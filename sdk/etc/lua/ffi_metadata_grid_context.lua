metadata_grid_context = { pending_calculation_marker = {} }

function metadata_grid_context:init(b)
    self.type_definitions = {}
    self.objects = {}
    self.lua_functions = {}
    if type(jit) == "table" then
        self:init_ffi(b)
    end
    self:get_type_definitions()
end

local ffi
local ffi_C

function evaluate_function(obj_idx)
    local ctx = metadata_grid_context
    ctx:debug("evaluate function", obj_idx)
    ffi_C.tb_ffi_reset_references(ctx.ffi_context, obj_idx)
    if not ffi_C.tb_ffi_do_execute_function(ctx.ffi_context, obj_idx) then
        ctx:debug("function already calculated")
        return
    end

    local d = ctx:get_function(obj_idx)
    if d.func then
        local status, res = pcall(d.func)

        if status then
            ctx:set_value(obj_idx, res, nil)
        elseif res ~= ctx.pending_calculation_marker then
            ctx:set_value(obj_idx, nil, res)
        else
            ctx:debug("Suspended function ", obj_idx)
        end
    else
        ctx:set_value(obj_idx, nil, d.func_err or "Property " .. pid .. " not a lua function")
    end
end

function reset_state()
    local ctx = metadata_grid_context
    ctx.lua_functions = {}
    ctx.objects = {}
end

function metadata_grid_context:init_ffi(b)
    ffi = require("ffi")
    ffi_C = ffi.C
    ffi.cdef[[
    typedef struct { void* pT; } UserdataType;


    typedef struct _FFIValue
    {
        int32_t value_type;
        bool bool_value;
        int32_t object_id;
        int32_t lua_function_id;
        int32_t type_code;
        double double_value;
        const char* string_value;
    } FFIValue;
    
    typedef struct _FFITypeDefinition
    {
        int32_t type_code;
        const char* type_name;
    } FFITypeDefinition;

    typedef struct _FFITypeDefinitions
    {
        FFITypeDefinition* definitions;
        int32_t size;
    } FFITypeDefinitions;

    typedef struct _FFIParameter
    {
        int32_t pid;
        FFIValue value;
        int32_t double_type;
    } FFIParameter;

    bool tb_ffi_do_execute_function(UserdataType* ffi_context_ptr, int32_t obj_id);
    void tb_ffi_set_value(UserdataType* ffi_context_ptr, int32_t obj_id, const FFIValue* v);
    void tb_ffi_set_internal_value(UserdataType* ffi_context_ptr, int32_t obj_idx, const FFIValue* v);
    void tb_ffi_debug(UserdataType* ffi_context_ptr, const char* str);
    const char* tb_ffi_get_lua_chain(UserdataType* ffi_context_ptr, int32_t obj_id);

    const FFIValue* tb_ffi_get_property_value(UserdataType* ffi_context_ptr, int32_t type_idx, int32_t obj_idx, const char* property_name, FFIParameter* parameters);
    const FFIValue* tb_ffi_get_index_value(UserdataType* ffi_context_ptr, int32_t obj_idx, int32_t tbl_idx);

    const FFIValue* tb_ffi_get_object_value(UserdataType* ffi_context_ptr, int32_t obj_idx);

    const FFIValue* tb_ffi_get_object_value(UserdataType* ffi_context_ptr, int32_t obj_idx);

    const FFIValue* tb_ffi_get_local_parameter_value(UserdataType* ffi_context_ptr, const char* parameter_name, int32_t type_code, int32_t obj_id);

    const FFIValue* tb_ffi_get_reference(UserdataType* ffi_context_ptr, int32_t type_idx, int32_t obj_idx, const char* property_name, FFIParameter* parameters);

    int32_t tb_ffi_compare(UserdataType* ffi_context_ptr, int32_t obj_idx1, int32_t obj_idx2);
    const char* tb_ffi_to_string(UserdataType* ffi_context_ptr, int32_t obj_idx);

    void tb_ffi_get_type_definitions(UserdataType* ffi_context_ptr, FFITypeDefinitions* type_definitions);
    void tb_ffi_reset_references(UserdataType* ffi_context_ptr, int32_t obj_idx);

    typedef void( *tb_lua_evaluate_function_callback)(int32_t pid);
    typedef void( *tb_lua_reset_state_callback)();
    void tb_ffi_set_callbacks(UserdataType* ffi_context_ptr, tb_lua_evaluate_function_callback eval_cb, tb_lua_reset_state_callback reset_cb);

    int32_t tb_ffi_get_local_parameter_pid(UserdataType* ffi_context_ptr, const char* parameter_name, int32_t type_code, int32_t obj_id);
    int32_t tb_ffi_get_parameter_pid(UserdataType* ffi_context_ptr, const char* parameter_name, int32_t type_code);
    double tb_ffi_time_now(UserdataType* ffi_context_ptr, int32_t rate);
    double tb_ffi_today(UserdataType* ffi_context_ptr);
    bool tb_ffi_is_error(UserdataType* ffi_context_ptr, int32_t obj_id);
    ]]

    self.ffi = ffi
    self.ffi_context = ffi.new("UserdataType", {})
    self.ffi_context.pT = b
    self.ffi_value = ffi.new("FFIValue", {})
    self.ffi_parameter_pack = ffi.new("FFIParameter[15]", {})
    self:debug("FFI binder ptr:", self.ffi_context.pT, "Lua type:", type(b), "FFI type:", type(self.ffi_binder))
    ffi_C.tb_ffi_set_callbacks(self.ffi_context, evaluate_function, reset_state)
end

local FFIValueTypeEmpty       = 0
local FFIValueTypeBool        = 1
local FFIValueTypeDouble      = 2
local FFIValueTypeString      = 3
local FFIValueTypeObjectId    = 4
local FFIValueTypeError       = 5
local FFIValueTypeLuaFunction = 6

local CustomTypeEmpty         = 100

local SmartDoubleTypeEmpty    = 0
local SmartDoubleTypeAbsolute = 1
local SmartDoubleTypeDelta    = 2
local SmartDoubleTypeFactor   = 3
local SmartDoubleTypeTick     = 4

function metadata_grid_context:convert_to_ffi_value(ffi_value, v)
    self:debug("convert to ffi value ", v, type(v))
    if type(v) == "string" then
        ffi_value.value_type = FFIValueTypeString
        ffi_value.string_value = v
    elseif type(v) == "boolean" then
        ffi_value.value_type = FFIValueTypeBool
        ffi_value.bool_value = v            
    elseif type(v) == "number" then
        ffi_value.value_type = FFIValueTypeDouble
        ffi_value.double_value = v            
    elseif type(v) == "table" then
        local idx = rawget(v, "obj_idx")
        ffi_value.value_type = FFIValueTypeObjectId
        ffi_value.object_id = idx or -1
    elseif type(v) == "nil" then
        ffi_value.value_type = FFIValueTypeEmpty
    end
end

function metadata_grid_context:convert_to_ffi_parameters(ffi_parameter_pack, parameter, idx)
    if not parameter then
        ffi_parameter_pack[idx].pid = -1
        return
    end
    ffi_parameter_pack[idx].pid = parameter.pid 
    ffi_parameter_pack[idx].double_type = parameter.double_type or SmartDoubleTypeEmpty
    self:convert_to_ffi_value(ffi_parameter_pack[idx].value, parameter.value)
end

function metadata_grid_context:convert_from_ffi_value(ffi_value)

    self:debug("convert from ffi value", ffi_value == nil)
    if ffi_value == nil then 
        error(self.pending_calculation_marker) 
    end

    local vt = ffi_value.value_type
    if vt == FFIValueTypeError then
        error( ffi.string(ffi_value.string_value) )
    elseif vt == FFIValueTypeBool then
        return ffi_value.bool_value
    elseif vt == FFIValueTypeDouble then
        return ffi_value.double_value
    elseif vt == FFIValueTypeString then
        local res = ffi.string(ffi_value.string_value)
        return res
    elseif vt == FFIValueTypeEmpty then
        return nil
    elseif vt == FFIValueTypeObjectId then
        self:debug("convert from ffi object", ffi_value.object_id)
        local obj = self:get_object(ffi_value.object_id)
        obj.type_code = ffi_value.type_code
        return obj
    elseif vt == FFIValueTypeLuaFunction then
        self:debug("convert from ffi function", ffi_value.lua_function_id)
        evaluate_function(ffi_value.lua_function_id)
        local val = ffi_C.tb_ffi_get_object_value(self.ffi_context, ffi_value.lua_function_id)
        if val ~= nil then ffi_C.tb_ffi_set_internal_value(self.ffi_context, ffi_value.object_id, val) end
        return self:convert_from_ffi_value(val)
    end
end

function metadata_grid_context:int_dump(force, args)
    local str = ""
    for i, v in pairs(args) do
        if v ~= nil then
            if i > 1 then str = str .. " " end
            str = str .. tostring(v)
        end
    end
    ffi_C.tb_ffi_debug(self.ffi_context, str)
end

function metadata_grid_context:debug(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12)
    if self.debug_mode then self:int_dump(false, {p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12}) end
end


function metadata_grid_context:get_type_definitions()
    local type_definitions = ffi.new("FFITypeDefinitions", {})
    ffi_C.tb_ffi_get_type_definitions(self.ffi_context, type_definitions)
    for i = 0, type_definitions.size - 1 do
        local type_code = type_definitions.definitions[i].type_code
        self.type_definitions[ type_code ] = {type_code = type_code, type_name = ffi.string( type_definitions.definitions[i].type_name) }
    end
end


function metadata_grid_context:get_parametrized_property_value(type_idx, obj_idx, prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
    if type(prop_name) ~= "string" then return nil end
    local convert_f = self.convert_to_ffi_parameters
    convert_f(self, self.ffi_parameter_pack,  p1,  0)
    convert_f(self, self.ffi_parameter_pack,  p2,  1)
    convert_f(self, self.ffi_parameter_pack,  p3,  2)
    convert_f(self, self.ffi_parameter_pack,  p4,  3)
    convert_f(self, self.ffi_parameter_pack,  p5,  4)
    convert_f(self, self.ffi_parameter_pack,  p6,  5)
    convert_f(self, self.ffi_parameter_pack,  p7,  6)
    convert_f(self, self.ffi_parameter_pack,  p8,  7)
    convert_f(self, self.ffi_parameter_pack,  p9,  8)
    convert_f(self, self.ffi_parameter_pack, p10,  9)
    convert_f(self, self.ffi_parameter_pack, p11, 10)
    convert_f(self, self.ffi_parameter_pack, p12, 11)
    convert_f(self, self.ffi_parameter_pack, p13, 12)
    convert_f(self, self.ffi_parameter_pack, p14, 13)
    convert_f(self, self.ffi_parameter_pack, p15, 14)
    self:debug("get parametrided property value ", code, obj_idx, prop_name)
    return self:convert_from_ffi_value(ffi_C.tb_ffi_get_property_value(self.ffi_context, type_idx, obj_idx, prop_name, self.ffi_parameter_pack))
end

function metadata_grid_context:get_object(obj_idx)
    local tbl = rawget(self.objects, obj_idx)
    if tbl then return tbl end

    tbl = {obj_idx = obj_idx}
    local mt = {}

    local ffi_context_f = self.ffi_context

    tbl.get_parametrized = function(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
        self:debug("get parametrized for obj", obj_idx, prop_name)
        return self:get_parametrized_property_value(CustomTypeEmpty, obj_idx, prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
    end
        
    local get_parametrized_f = tbl.get_parametrized
    tbl.calculate = function(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
        return get_parametrized_f(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
    end
    tbl.lower_bound = function(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
        return get_parametrized_f(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
    end
    tbl.get_local_table = function(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14)
        --TODO
    end

    tbl.get_reference = function(prop_name)
        if type(prop_name) ~= "string" then return nil end
        self:debug("get obj reference", obj_idx, k)
        local ffi_value = ffi_C.tb_ffi_get_reference(self.ffi_context, CustomTypeEmpty, obj_idx, prop_name, nil)
        return self:convert_from_ffi_value(ffi_value)
    end

    tbl.get_by_ref = tbl.get_reference
    tbl.get_property_object = tbl.get_reference

    tbl.size = function() return tbl[0] end

    mt.__index = function(t, k)
        self:debug("get obj value", obj_idx, k)
        if type(k) == "string" then
            return self:convert_from_ffi_value(ffi_C.tb_ffi_get_property_value(self.ffi_context, CustomTypeEmpty, obj_idx, k, nil))
        elseif type(k) == "number" then
            return self:convert_from_ffi_value(ffi_C.tb_ffi_get_index_value(self.ffi_context, obj_idx, k))
        end
    end    

    mt.__eq = function(obj1, obj2)
        return ffi_C.tb_ffi_compare(ffi_context_f, obj1.obj_idx, obj2.obj_idx) == 0
    end
    mt.__le = function(obj1, obj2)
        return ffi_C.tb_ffi_compare(ffi_context_f, obj1.obj_idx, obj2.obj_idx) <= 0
    end
    mt.__lt = function(obj1, obj2)
        return ffi_C.tb_ffi_compare(ffi_context_f, obj1.obj_idx, obj2.obj_idx) < 0
    end

    mt.__tostring = function(obj1)
        return ffi.string( ffi_C.tb_ffi_to_string(ffi_context_f, obj1.obj_idx) )
    end
    mt.__len = mt.size

    setmetatable(tbl, mt)
    self.objects[obj_idx] = tbl

    return tbl
end

function metadata_grid_context:create_type_index(code, obj_idx)
    local tbl = {type_code = code}

    local mt = {}

    mt.__index = function(t, k)
        if type(k) ~= "string" then return nil end
        self:debug("get type value", code, obj_idx, k)
        local ffi_value = ffi_C.tb_ffi_get_property_value(self.ffi_context, code, obj_idx, k, nil)
        return self:convert_from_ffi_value(ffi_value)
    end   

    tbl.parameter = function(prop_name, value)
        local param = { value = value }
        param.pid = ffi_C.tb_ffi_get_parameter_pid(self.ffi_context, prop_name, code)
        if param.pid < 0 then 
            local def = rawget(self.type_definitions, code)
            error("Property '" .. prop_name .. "' of type '" .. def.type_name  .. "' is not found")
        end
        self:debug("parameter ", code, obj_idx, prop_name, param.pid, value)
        return param
    end
    tbl.calculate = function(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
        self:debug("get parametrized for type", code, obj_idx, prop_name)
        return self:get_parametrized_property_value(code, obj_idx, prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
    end

    tbl.lower_bound = function(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
        return self:get_parametrized_property_value(code, obj_idx, prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
    end
  
    tbl.get_parameter = function(prop, vector_path)
        --TODO
    end

    tbl.get_reference = function(prop_name)
        if type(prop_name) ~= "string" then return nil end
        self:debug("get reference", code, obj_idx, k)
        local ffi_value = ffi_C.tb_ffi_get_reference(self.ffi_context, code, obj_idx, prop_name, nil)
        return self:convert_from_ffi_value(ffi_value)
    end

    tbl.get_property_object = tbl.get_reference

    tbl.percent_offset_parameter = function(prop, param_value)
        --TODO
    end

    tbl.get_local_table = function(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14)
        --TODO
    end

    tbl.sum = function(prop_name)
        local obj = self:convert_from_ffi_value(ffi_C.tb_ffi_get_property_value(self.ffi_context, code, obj_idx, k, nil))
        if(type(obj) == "table") then return obj["Sum accessor"] end
    end

    setmetatable(tbl, mt)
    return tbl
end

function metadata_grid_context:create_fenv(obj_idx) 
    local tb = {}
    local e = 
            {
                math = math,
                string = string,
                table = table,
                error = error,
                tostring = tostring,
                rawequal = rawequal,
                rawset = rawset,
                rawget = rawget,
                unpack = unpack,
                pairs = pairs,
                ipairs = ipairs,
                tonumber = tonumber,
                type = type,
                assert = assert,
                select = select,
                next = next,
                tb = tb,
                print_reference_only = true,
                __layer = "env"
            }

    self:debug("create fenv", obj_idx)
    for type_code, type_def in pairs(self.type_definitions) do
        e[type_def.type_name] = self:create_type_index(type_code, obj_idx)
    end

    e.local_parameter = function(type_table, name)
        if string.char(name:byte(1)) ~= '@' then error("local parameter name should start with '@'") end
        local type_code = type_table and type(type_table) == "table" and rawget(type_table, "type_code")
        if not type_code then type_code = 1 end
        self:debug("get local parameter", type_code, name)
        return self:convert_from_ffi_value(ffi_C.tb_ffi_get_local_parameter_value(self.ffi_context, name, type_code, obj_idx))
    end

    tb.is_error = function(value)
        if(type(value) ~= "table") then return false end
        local idx = rawget(value, "obj_idx")
        if not idx then return false end
        return ffi_C.tb_ffi_is_error(self.ffi_context, idx)
    end

    local int_table = e.internal
    tb.time_now = function(rate)
        return ffi_C.tb_ffi_time_now(self.ffi_context, rate or 5)
    end
    
    tb.today = function()
        return ffi_C.tb_ffi_today(self.ffi_context)
    end

    tb.time = function(t)
        return (os.time(t))
    end

    tb.date = function(num, format)
        if not num then return nil end
        return (os.date(format or "*t", num))
    end

    tb.usec = function(num)
        if not num then return nil end
        if num < 0 then num = -num end
        return (num - math.floor(num)) * 1e6
    end

    tb.days_between = function(t1, t2)
        return (math.ceil(math.abs(os.difftime(t1, t2))/86400))
    end

    e.parameter = e.plugin.parameter
    --TODO e.percent_offset_parameter = e.plugin.percent_offset_parameter
    e.set_parameter = e.plugin.parameter

    local enum_table = e.enumeration
    e.enumeration_parameter = function(enum_name, enum_item_name)
        return enum_table.parameter(enum_name, enum_table[enum_name][enum_item_name])
    end

    e.set_local_parameter = function(type_table, name, param_value)
        if string.char(name:byte(1)) ~= '@' then error("local parameter name should start with '@'") end
        self:debug("set local parameter", name, param_value)
        local type_code = type_table and type(type_table) == "table" and rawget(type_table, "type_code")
        if not type_code then type_code = 1 end
        local param = { value = param_value }
        param.pid = ffi_C.tb_ffi_get_local_parameter_pid(self.ffi_context, name, type_code, obj_idx)
        return param
    end
    
    e.set_local_enumeration_parameter = function(enum_name, name, enum_item_name)
        return e.set_local_parameter(enum_table[enum_name], name, enum_table[enum_name][enum_item_name])
    end

    e.current_user = {}
    setmetatable(e.current_user, {__index = function(t, k) return int_table["Current user"][k] end })

    tb.set_indirection_stack_size = function(v)
        --TODO
        self.indirection_stack_size = v
    end

    return e
end

function metadata_grid_context:get_function(obj_idx)
    local lua_func = self.lua_functions[obj_idx]
    if not lua_func then
        self:debug("get_function", self.ffi_context, obj_idx)
        local c_str = ffi_C.tb_ffi_get_lua_chain(self.ffi_context, obj_idx)
        local f, err = loadstring(ffi.string(c_str), name or id) 
        lua_func = {func_err = err}
        self.lua_functions[obj_idx] = lua_func
        local env = self:create_fenv(obj_idx)
        if f then
            lua_func.func = function() setfenv(f, env) return f() end
        end
    end
    return lua_func
end

function metadata_grid_context:set_value(obj_idx, val, err)
    self:debug("set value", obj_idx, val, err)
    if err then
        self.ffi_value.value_type = FFIValueTypeError
        str_err = tostring(err)
        self.ffi_value.string_value = str_err
        ffi_C.tb_ffi_set_value(self.ffi_context, obj_idx, self.ffi_value)
        return
    end
    self:convert_to_ffi_value(self.ffi_value, val)
    ffi_C.tb_ffi_set_value(self.ffi_context, obj_idx, self.ffi_value)
end



metadata_grid_context:init(ffi_context_pointer)
return metadata_grid_context
