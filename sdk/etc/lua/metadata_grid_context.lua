metadata_grid_context = {definitions = nil, grid_functions = {}, binder = nil, ffi_binder = nil, type_definitions = nil, pending_calculation_marker = {},  indirection_stack_size = 10, debug_mode = false, profiler = nil, global_vector_path = nil}
function metadata_grid_context:init_binder(b)
    self.binder = b
    b.context = self
    self.type_definitions = {}
    self.definitions = {}
    self:get_type_definitions()
    if type(jit) == "table" and use_jit_ffi then
        self:init_ffi(b)
    end
end

local ffi
local ffi_C

function metadata_grid_context:init_ffi(b)
    ffi = require("ffi")
    ffi_C = ffi.C
    ffi.cdef[[

    typedef struct { void* pT; } UserdataType;

    typedef struct _FFIValue
    {
        int value_type;
        bool bool_value;
        int int_value;
        double double_value;
        char string_value[8192];
    } FFIValue;

    bool binder_is_error(UserdataType* binder_ptr, int pid, FFIValue* v);
    bool binder_do_execute_function(UserdataType* binder_ptr, int pid);
    bool binder_get_value(UserdataType* binder_ptr, int pid, int vector_idx, FFIValue* v);
    bool binder_set_value(UserdataType* binder_ptr, int pid, FFIValue* v);
    bool binder_get_string_value(UserdataType* binder_ptr, int pid, int vector_idx, FFIValue* v);
    bool binder_compare_values(UserdataType* binder_ptr, int pid1, int pid2, FFIValue* v);
    bool binder_calculate_table_index(UserdataType* binder_ptr, int pid, FFIValue * ffi_v);
    bool binder_set_property_parameter(UserdataType* binder_ptr, int root_pid, int pid, int p_idx, int param_pid, FFIValue * ffi_v);
    void binder_handle_message(UserdataType* binder_ptr, const char * msg);
    ]]
    local tostruct = ffi.typeof("UserdataType *")
    self.ffi_binder = tostruct(b)
    self.ffi_value = ffi.new("FFIValue", {})
    self:debug("FFI binder ptr:", self.ffi_binder.pT, "Lua type:", type(b), "FFI type:", type(self.ffi_binder))
end

local FFIValueTypeEmpty = 0
local FFIValueTypeNotConverted = 1
local FFIValueTypeBool = 2
local FFIValueTypeDouble = 3
local FFIValueTypeString = 4
local FFIValueTypePropertyIndex = 5
local FFIValueTypeError = 6
local FFIValueTypePending = 7
local FFIValueTypeInt = 8


local SmartDoubleTypeEmpty    = 0
local SmartDoubleTypeAbsolute = 1
local SmartDoubleTypeDelta    = 2
local SmartDoubleTypeFactor   = 3
local SmartDoubleTypeTick     = 4

function metadata_grid_context:get_type_definitions()
    for type_code, type_name in pairs(self.binder:get_type_definitions()) do
        self.type_definitions[type_code] = {type_code = type_code, type_name = type_name, properties = {}}
    end
end

function metadata_grid_context:reset_properties()
    self.definitions  = {}
    self.grid_functions = {}
end

local function check_pending(ctx, value_type)
    if(value_type == FFIValueTypePending) then
        error(ctx.pending_calculation_marker)
    end
end

local function convert_to_ffi_value(ffi_value, v)
    if type(v) == "string" then
        ffi_value.value_type = FFIValueTypeString
        ffi.copy(ffi_value.string_value, v)
    elseif type(v) == "boolean" then
        ffi_value.value_type = FFIValueTypeBool
        ffi_value.bool_value = v            
    elseif type(v) == "number" then
        ffi_value.value_type = FFIValueTypeDouble
        ffi_value.double_value = v            
    elseif type(v) == "table" then
        local idx = rawget(v, "m_source_property_pid")
        ffi_value.value_type = FFIValueTypePropertyIndex
        ffi_value.int_value = idx or -1
    elseif type(v) == "nil" then
        ffi_value.value_type = FFIValueTypeEmpty
    end
end

local function convert_from_ffi_value(ctx)

    local vt = ctx.ffi_value.value_type
    check_pending(ctx, vt)
    if vt == FFIValueTypeNotConverted or vt == FFIValueTypeError then 
        return nil, false
    elseif vt == FFIValueTypeBool then
        return ctx.ffi_value.bool_value, true
    elseif vt == FFIValueTypeDouble then
        return ctx.ffi_value.double_value, true
    elseif vt == FFIValueTypeString then
        return (ffi.string(ctx.ffi_value.string_value)), true
    elseif vt == FFIValueTypeEmpty then
        return nil, true
    end
end

local function binder_set_value(ctx, pid, val, err)
    ctx.binder:set_value(pid, val, err)
end

local function binder_set_property_parameter(ctx, root_pid, pid, p_idx, param_pid, v, v_type)
    ctx.binder:set_property_parameter(root_pid, pid, p_idx, param_pid, v, v_type)
end

local function binder_calculate_table_index(ctx, pid, k)
    return ctx.binder:calculate_table_index(pid, k)
end

local function binder_compare_values(ctx, pid1, v_path1, pid2, v_path2)
    return (ctx.binder:compare_values(pid1, v_path1, pid2, v_path2))
end

local function binder_get_string_value(ctx, pid, vector_path)
    return (ctx.binder:get_string_value(pid, vector_path))
end

local function binder_do_execute_function(ctx, pid)
    local ok = ctx.binder:do_execute_function(pid)
    return ok --for jit compilation
end

local function binder_send_message(ctx, str, force)
    ctx.binder:handle_message(str, force)
end

local function get_vector_element(obj, vector_path, create_elements)
    if not obj or not vector_path then return nil end
    if type(vector_path) == "number" then  
        local result = rawget(obj, vector_path) 
        if create_elements and not result then 
            result = {}
            obj[vector_path] = result
        end
        return result
    end

    local result = obj
    for _, v in ipairs(vector_path) do 
        if not result then return nil end
        local vector_element = rawget(result, v)

        if not vector_element and create_elements then
            vector_element = {}
            result[v] = vector_element
        end

        result = vector_element
    end
    return result
end

local function get_propterty_vector_values(d, vector_path)
    if not vector_path then return nil end
    local vector_values = d.vector_values
    if not vector_values then
        vector_values = {}
        d.vector_values = vector_values
    end
    return get_vector_element(vector_values, vector_path, true)
end


function metadata_grid_context:evaluate_function(pid, vector_path)
    local f_ref = self.grid_functions[pid]
    if not f_ref then
        local v = self.binder:get_grid_function(pid)
        f_ref = 
        {
            func_id = v.m_id, func_pid = v.m_pid, func_src_pid = v.m_src_pid, func_root_pid = v.m_root_pid, 
            properties = {print_reference_only = true},
            __layer = "func"
        }
        self.grid_functions[pid] = f_ref
        if self.debug_mode then
            self:debug("New function: ", pid, " ,id: ", v.m_id, " ,src pid: ", v.m_src_pid, " ,ref: ", f_ref)
        end
    end

    for _, v in ipairs(f_ref.properties) do
        if not v.const then
            v.value = nil
            v.value_calculated = nil
            v.vector_values = nil
        end
    end

    if vector_path or binder_do_execute_function(self, pid) then

        f_ref.parametrized_index = 1

        local obj = self:get_object(f_ref, f_ref.func_src_pid, nil)
        local d = self:register_property(f_ref, obj, f_ref.func_id, nil, nil, f_ref.func_pid)


        local vector_values = get_propterty_vector_values(d, vector_path)
        if d.func then

            if self.debug_mode then
                self:debug("Calling function:", d.property_name, ", pid:", d.pid, ", vector_path:", vector_path, ", obj.vector_path:", obj.vector_path)
            end

            local old_vector_path = self.global_vector_path
            self.global_vector_path = vector_path
            local status, res = pcall(d.func)
            self.global_vector_path = old_vector_path

            if status then
                if not vector_values then binder_set_value(self, pid, res, nil) end
                d.value_calculated = true
                d.value = res
                if vector_values then
                    vector_values.value_calculated = true
                    vector_values.value = d.value
                end

            elseif res ~= self.pending_calculation_marker then 
            
                if not vector_values then binder_set_value(self, pid, nil, res) end
                d.value_calculated = true
                d.value = self:get_indirect_object(f_ref, d, vector_path)
                if vector_values then
                    vector_values.value_calculated = true
                    vector_values.value = d.value
                end
            else
                if self.debug_mode then
                    self:debug("Suspended function:", d.property_name, ", pid:", d.pid, ", src:", d.src_pid, ", ref:", f_ref)
                end
            end
        
        else
            if not vector_values then binder_set_value(self, pid, nil, d.func_err or "Property " .. pid .. " not a lua function") end
            d.value_calculated = true
            d.value = self:get_indirect_object(f_ref, d, vector_path)
            if vector_values then
                vector_values.value_calculated = true
                vector_values.value = d.value
            end

        end
    end
end

function metadata_grid_context:get_parametrized_property(references, obj, code, name, parameter_type_code)
    local def = rawget(self.type_definitions, code)
    local by_name = def.properties
    local id = rawget(by_name, name)
    if id == nil then
        id = self.binder:get_property_by_name(code, name)
        by_name[name] = id or false
    end
    if not id then error("Property '" .. name .. "' of type '" .. def.type_name .. "' not found") end
    return (self:register_parametrized_property(references, obj, id, parameter_type_code))
end


function metadata_grid_context:get_property(references, obj, code, name)
    code = code or 1 --protocol::DataSourceServiceProvider by default
    local def = rawget(self.type_definitions, code)
    local by_name = def.properties
    local id = rawget(by_name, name)
    if id == nil then
        id = self.binder:get_property_by_name(code, name)
        by_name[name] = id or false
    end
    if not id then error("Property '" .. name .. "' of type '" .. def.type_name .. "' not found") end
    return (self:register_property(references, obj, id))
end


function metadata_grid_context:get_local_parameter_property(references, obj, type_table, name)
    assert(type(tonumber(name) or name) == "string", "Parameter name should be of type 'string'")
    local def = rawget(self.definitions, name)
    if not def then
        def = {property_name = name}
        local type_code = type_table and type(type_table) == "table" and rawget(type_table, "type_code")
        if type_code then
            def.parameter_type_code = type_code
            def.type_code = type_code
        else
            def.parameter_type_code = 1 --protocol::DataSourceServiceProvider by default
        end
        self.definitions[name] = def
        if self.debug_mode then
            self:debug("local_parameter:", def.parameter_type_code, ", parameter:", name)
        end
    end
    return (self:register_parametrized_property(references, obj, name))
end


local function update_parameters_table(ctx, references, obj, code, name, parameter_type_code, param_value, double_type)
    local d_param = ctx:get_parametrized_property(references, obj, code, name, parameter_type_code)
    local param_tbl = d_param.parameter_table
    if not param_tbl then
        param_tbl = {d_param.pid}
        d_param.parameter_table = param_tbl
    end
    param_tbl[2] = param_value
    param_tbl[3] = double_type
    return param_tbl
end

local local_table_property_name = "Use temporary table"
local plugin_type_code = 3

local function local_table_parameter(ctx, references, obj)
    return update_parameters_table(ctx, references, obj, plugin_type_code, local_table_property_name, plugin_type_code, true)
end

function metadata_grid_context:create_type_index(references, obj, code, type_name)
    local tbl = {type_code = code, properties_cache = {}, __layer = "type_idx"}

    local properties_cache = tbl.properties_cache
    local i = obj.interface
    local binder = self.binder
    local debug_mode = self.debug_mode
    local get_property_f = self.get_property
    local get_parametrized_property_f = self.get_parametrized_property
    local get_parametrized_f = i.get_parametrized
    local get_indirect_object_f = self.get_indirect_object

    tbl.get_property = function(prop_name)
        return self:get_property(code, prop_name).id
    end
    
    tbl.calculate = function(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
        return (get_parametrized_f(code, prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15))
    end

    tbl.lower_bound = function(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
        return (get_parametrized_f(code, prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15))
    end

    tbl.get_property_object = function(prop_name)
        return (i.get_by_ref(code, prop_name, true))
    end    

    tbl.get_reference = function(prop_name)
        return (i.get_by_ref(code, prop_name))
    end

    tbl.get_parameter = function(prop, vector_path)
        local d_param = get_parametrized_property_f(self, references, obj, code, prop, code)
        return d_param.get_value(vector_path)
    end

    tbl.parameter = function(prop, param_value)
        return update_parameters_table(self, references, obj, code, prop, code, param_value)
    end

    tbl.percent_offset_parameter = function(prop, param_value)
        if(type(tonumber(param_value)) ~= 'number') then error("attempt to get offset of " .. type(param_value) .. " value") end
        return update_parameters_table(self, references, obj, code, prop, code, 1 + 0.01 * param_value, SmartDoubleTypeFactor)
    end

    tbl.get_local_table = function(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14)
        return get_parametrized_f(code, prop_name, local_table_parameter(self, references, obj), p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14)
    end

    tbl.sum = function(prop_name)
        local d = get_property_f(self, references, obj, code, prop_name)
        local i = get_indirect_object_f(self, references, d)
        if self.debug_mode then
            self:debug("get_sum:", d.property_name, ", pid:", d.pid, ", i:", i, ", ref:", references)
        end
        return i["Sum accessor"]
    end

    local mt = {}
    local default_index = function(t, k)
        local d = rawget(properties_cache, k)
        if not d then 
            d = get_property_f(self, references, obj, code, k)
            properties_cache[k] = d
            --CustomTypeEnumeration = 101,
            --CustomTypeRanking = 107,
            --CustomTypeParameterContext = 108
            if code == 101 or code == 107 or code == 108 then
                d.const = {}
            end
        elseif debug_mode then
            self:debug("get cached type property:", d.property_name, ", type:", code, ", pid:", d.pid, ", src:", d.src_pid, ", ref:", references, "global_vector_path", self.global_vector_path)
        end
        return d.get_value()
    end    
    mt.__index = default_index
            
    setmetatable(tbl, mt)
    return tbl
end

local function indirect_object_is_equal(interface1, interface2)
    return interface1.compare(interface2.m_source_property_pid, interface2.get_vector_path()) == 0
end

local function indirect_object_is_less_or_equal(interface1, interface2)
    return interface1.compare(interface2.m_source_property_pid, interface2.get_vector_path()) <= 0
end

local function indirect_object_is_less(interface1, interface2)
    return interface1.compare(interface2.m_source_property_pid, interface2.get_vector_path()) < 0
end

local function indirect_object_to_string(interface)
    return interface.value_to_string()
end

function metadata_grid_context:get_indirect_object(references, d, vector_path)
    if self.debug_mode then
        self:debug("get_indirect_object:", d.property_name, ", pid:", d.pid, ", src:", d.src_pid, ", ref:", references, ", idx:", vector_path)
    end

    if not d.value_ref or vector_path then 
        d.value_ref = self:get_object(references, d.pid, d, vector_path).interface 
    end
    return d.value_ref
end

local function binder_get_value(ctx, d, binder, debug_mode, vector_path)
    if d.is_func then
        if debug_mode then
            ctx:debug("evaluate internal:", d.property_name, ", pid:", d.pid, ", src:", d.src_pid, ", idx:", vector_path)
        end    
        ctx:evaluate_function(d.pid, vector_path)
        if vector_path then
            local f_ref = rawget(ctx.grid_functions, d.pid)
            local obj = ctx:get_object(f_ref, f_ref.func_src_pid, nil)
            local d_ref = ctx:register_property(f_ref, obj, f_ref.func_id, nil, nil, f_ref.func_pid)
            d.value = d_ref.value
            d.value_calculated = d_ref.value_calculated
            d.vector_values = d_ref.vector_values
            return true
        end
    end
    local status
    d.value, status = binder:get_value(d.pid, vector_path)
    return status
end

function metadata_grid_context.get_value(ctx, references, d, binder, debug_mode, vector_path)
    vector_path = vector_path or ctx.global_vector_path
    if debug_mode then
        ctx:debug("get_value:", d.property_name, ", pid:", d.pid, ", src:", d.src_pid, ", ref:", references, ", idx:", vector_path)
    end
    if d.value_calculated and not vector_path then return d.value end

    local vector_values = get_propterty_vector_values(d, vector_path)
    if vector_values and vector_values.value_calculated then return vector_values.value end

    local status = binder_get_value(ctx, d, binder, debug_mode, vector_path)

    if status ~= nil then
        if status == false then d.value = ctx:get_indirect_object(references, d, vector_path) end

        if vector_path then 
            vector_values.value = d.value 
            vector_values.value_calculated = true
        else d.value_calculated = true end
    else
        if debug_mode then
            ctx:debug("Suspended property:", d.property_name, ", pid:", d.pid, ", src:", d.src_pid, ", ref:", references, ", idx:", vector_path)
        end
        error(ctx.pending_calculation_marker)

    end
    return d.value
end

local function copy_vector(vec)
    local result = {}
    if(vec == nil) then return result end

    if(type(vec) == "number") then 
        result[1] = vec
        return result
    end

    for i, v in ipairs(vec) do
        result[i] = v
    end
    return result
end

local function create_object(ctx, references, src_pid, indirect_d, vector_path)
    local binder = ctx.binder
    local debug_mode = ctx.debug_mode
    local get_property_f = ctx.get_property
    local get_parametrized_property_f = ctx.get_parametrized_property
    local get_indirect_object_f = ctx.get_indirect_object

    local i = {m_source_property_pid = src_pid, print_reference_only = true, m_vector_path = vector_path}
    local obj = {src_pid = src_pid, vector_path = vector_path, interface = i, src_property = indirect_d, __layer = "obj"}

    local root_obj = obj
    if(vector_path) then
        root_obj = ctx:get_object(references, src_pid, indirect_d)
        obj.properties_cache = root_obj.properties_cache
    else
        obj.properties_cache = {}
    end

    local properties_cache = obj.properties_cache

    i.compare = function(pid, v_path) return binder_compare_values(ctx, src_pid, vector_path, pid, v_path) end

    i.get_vector_path = function() return vector_path end

    i.value_to_string = function()
    
        return binder_get_string_value(ctx, src_pid, vector_path) 
    end

    i.value = function() if obj.src_property then return obj.src_property.get_value(vector_path) end end 

    i.get_by_ref = function(code, name, ignore_value)
        local d = get_property_f(ctx, references, root_obj, code, name)
        if not ignore_value then
            if d.get_value(vector_path) == nil then return nil end
        end
        return (get_indirect_object_f(ctx, references, d))
    end

    i.get_parametrized = function(code, name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
        local d = get_parametrized_property_f(ctx, references, root_obj, code, name)
        if  p1 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid,  0,  p1[1],  p1[2],  p1[3]) end
        if  p2 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid,  1,  p2[1],  p2[2],  p2[3]) end
        if  p3 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid,  2,  p3[1],  p3[2],  p3[3]) end
        if  p4 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid,  3,  p4[1],  p4[2],  p4[3]) end
        if  p5 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid,  4,  p5[1],  p5[2],  p5[3]) end
        if  p6 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid,  5,  p6[1],  p6[2],  p6[3]) end
        if  p7 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid,  6,  p7[1],  p7[2],  p7[3]) end
        if  p8 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid,  7,  p8[1],  p8[2],  p8[3]) end
        if  p9 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid,  8,  p9[1],  p9[2],  p9[3]) end
        if p10 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid,  9, p10[1], p10[2], p10[3]) end
        if p11 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid, 10, p11[1], p11[2], p11[3]) end
        if p12 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid, 11, p12[1], p12[2], p12[3]) end
        if p13 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid, 12, p13[1], p13[2], p13[3]) end
        if p14 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid, 13, p14[1], p14[2], p14[3]) end
        if p15 then binder_set_property_parameter(ctx, references.func_root_pid, d.pid, 14, p15[1], p15[2], p15[3]) end
        return d.get_value(vector_path)
    end

    if indirect_d then

        if indirect_d.level > ctx.indirection_stack_size then error("Indirection stack overflow") end
        obj.level = indirect_d.level            
        if indirect_d.type_code then
            local get_parametrized_f = i.get_parametrized

            i.type_code = indirect_d.type_code
        
            i.get_property_object = function(prop_name)
                return i.get_by_ref(indirect_d.type_code, prop_name, true)
            end

            i.calculate = function(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
                return get_parametrized_f(indirect_d.type_code, prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
            end

            i.lower_bound = function(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
                return get_parametrized_f(indirect_d.type_code, prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15)
            end

            i.get_local_table = function(prop_name, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14)
                return get_parametrized_f(indirect_d.type_code, prop_name, local_table_parameter(ctx, references, obj), p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14)
            end

        end

        i.size = function() return i[0] end

        local indirect_obj_interface_mt = {}
        setmetatable(obj.interface, indirect_obj_interface_mt)

        indirect_obj_interface_mt.__eq = indirect_object_is_equal
        indirect_obj_interface_mt.__le = indirect_object_is_less_or_equal
        indirect_obj_interface_mt.__lt = indirect_object_is_less
        indirect_obj_interface_mt.__tostring = indirect_object_to_string
        indirect_obj_interface_mt.__len = i.size

        local default_index = function(t, k)
            if ctx.debug_mode then
                ctx:debug("Indexing obj:", obj.src_pid, ", idx:", obj.vector_path, ", indexer:", k)
            end

            local table_idx
            local obj_elements = obj.own_elements
            if not vector_path or type(k) ~= "number" then table_idx = k else
                if obj_elements then
                    local v_element = rawget(obj_elements, k)
                    if v_element then table_idx = v_element.vector_path end
                end
                if not table_idx then 
                    table_idx = copy_vector(vector_path)
                    table_idx[#table_idx + 1] = k
                end
            end

            local idx_value, idx_converted = binder_calculate_table_index(ctx, src_pid, table_idx)
            if idx_converted ~= nil then
                if ctx.debug_mode then
                    ctx:debug("Table index item:", k, ", value:", idx_value, ", const:", indirect_d.const)
                end

                if type(k) == "number" then

                    local own_elements = obj.own_elements
                    if not own_elements then
                        if not vector_path then
                            own_elements = obj.elements
                            if not own_elements then
                                own_elements = {}
                                obj.elements = own_elements
                            end
                            obj.own_elements = own_elements
                        else
                            own_elements = {}
                            obj.own_elements = own_elements
                        end
                    end

                    local v_element = rawget(own_elements, k)
                    if not idx_converted then
                        if v_element then return v_element.interface end
                        v_element = create_object(ctx, references, src_pid, indirect_d, table_idx)
                        own_elements[k] = v_element
                        return v_element.interface
                    end
                    if not v_element then
                        v_element = {}
                        own_elements[k] = v_element
                    end
                    if not v_element.vector_path then v_element.vector_path = table_idx end

                end
                return idx_value
            else
                local d = rawget(properties_cache, k)
                if not d then
                    d = get_property_f(ctx, references, root_obj, indirect_d.type_code, k)
                    properties_cache[k] = d
                elseif debug_mode then
                    ctx:debug("get cached object property:", d.property_name, ", type:", indirect_d.type_code, ", pid:", d.pid, ", src:", d.src_pid, ", v path", vector_path, ", ref:", references)
                end
                return d.get_value(vector_path)
            end
        end

        if indirect_d.const then
            local const = indirect_d.const
            indirect_obj_interface_mt.__index = function(t, k)
                local cv = rawget(const, k)
                if not cv then
                    cv = default_index(t, k)
                    const[k] = cv
                elseif debug_mode then
                    ctx:debug("cached const item:", k, ", value:", cv)
                end
                return cv
            end
        else
            indirect_obj_interface_mt.__index = default_index
        end

    else
        obj.level = 0
    end

    if not vector_path then references[src_pid] = obj else

        local tbl = root_obj.elements
        if not tbl then
            tbl = {}
            root_obj.elements = tbl 
        end

        if type(vector_path) == "number" then
            tbl[vector_path] = obj
        else
            for i, v in ipairs(vector_path) do
                if i < #vector_path then
                    if not tbl[v] then tbl[v] = {} end
                    tbl = tbl[v]
                end
            end
            tbl[#vector_path] = obj

        end
    if ctx.debug_mode then
        ctx:debug("registered vector element for:", src_pid, ", id:", vector_path, ", refs", references)
    end
    end
    return obj
end

create_object_f = create_object

function metadata_grid_context:get_object(references, src_pid, indirect_d, vector_path)
    if self.debug_mode then
        self:debug("get_object:", src_pid, ", ref:", references, ", vector_path", vector_path)
    end
    local obj = rawget(references, src_pid)
    if vector_path and obj then
        if self.debug_mode then
            self:debug("get vector element from:", obj, " ", obj, ", src pid:", src_pid, ", idx:", vector_path)
        end
        obj = get_vector_element(obj.elements, vector_path) 
    end
    if not obj then return create_object(self, references, src_pid, indirect_d, vector_path) end
    return obj
end

local function binder_is_error(ctx, v, binder)
    if type(v) == "table" then
        return (binder:is_error_value(v))     
    end    
end

function metadata_grid_context:create_fenv(references, obj)
    local tb = {internal_context = self, cache = {}}
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

    for type_code, type_def in pairs(self.type_definitions) do
        e[type_def.type_name] = self:create_type_index(references, obj, type_code, type_def.type_name)
    end

    local int_table = e.internal
    local enum_table = e.enumeration
    local binder = self.binder

    tb.time_now = function(rate)
        return int_table["Current user"].calculate("Current time", int_table.parameter("Rate", rate or 5))
    end
    
    tb.today = function()
        return int_table["Current user"]["Current date"]
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

    tb.is_error = function(value)
        return binder_is_error(self, value, binder)
    end

    e.parameter = e.plugin.parameter
    e.percent_offset_parameter = e.plugin.percent_offset_parameter
    e.set_parameter = e.plugin.parameter
    e.get_parameter = e.plugin.get_parameter

    e.enumeration_parameter = function(enum_name, enum_item_name)
        return enum_table.parameter(enum_name, enum_table[enum_name][enum_item_name])
    end

    e.local_parameter = function(type_table, name, vector_path)
        local d_param = self:get_local_parameter_property(references, obj, type_table, name)
        return d_param.get_value(vector_path)
    end

    e.set_local_parameter = function(type_table, name, param_value)
        local d_param = self:get_local_parameter_property(references, obj, type_table, name)
        local param_tbl = d_param.parameter_table
        if not param_tbl then
            param_tbl = {d_param.pid}
            d_param.parameter_table = param_tbl
        end
        param_tbl[2] = param_value
        return param_tbl
    end
    
    e.set_local_enumeration_parameter = function(enum_name, name, enum_item_name)
        return e.set_local_parameter(enum_table[enum_name], name, enum_table[enum_name][enum_item_name])
    end

    e.current_user = {}
    setmetatable(e.current_user, {__index = function(t, k) return int_table["Current user"][k] end })

    tb.set_indirection_stack_size = function(v)
        self.indirection_stack_size = v
    end
    return e
end

function metadata_grid_context:register_parametrized_property(references, obj, id, parameter_type_code)
    local d = nil
    while not d do
        d = (self:register_property(references, obj, id, references.parametrized_index, parameter_type_code))
        if self.debug_mode then
            self:debug("register_parametrized_property: ", references.parametrized_index, ", name:", d.property_name, ", pid:", d.pid, ", src:", d.src_pid, ", ref:", references)
        end
        references.parametrized_index = references.parametrized_index + 1
        if d.id ~= id then
            d = nil
        end
    end
    return d
end

function metadata_grid_context:get_definition(id)
    local def = self.definitions[id]
    if not def then
        local f_str, type_code, name = self.binder:get_property_definition(id)
        local f, err
        if f_str then
            --parse chain
            f, err = loadstring(f_str, name or id)
            if not f and not err then
                err = "Cannot parse Lua function '" .. tostring(name or id) .. "'"
            end
        end
        def = {func = f, func_err = err, f_str = f_str, type_code = type_code, property_name = name}
        self.definitions[id] = def
    end
    return def
end

function metadata_grid_context:init_property(references, obj, d, def, func_pid)
    d.type_code = def.type_code
    d.property_name = def.property_name
    d.value_ref = nil
    d.is_func = def.func ~= nil or d.func_err ~= nil

    local binder = self.binder
    local get_value_f = self.get_value
    local debug_mode = self.debug_mode
    
    d.get_value = function(vector_path)
        return (get_value_f(self, references, d, binder, debug_mode, vector_path or obj.vector_path))
    end

    if func_pid ~= nil then
        d.func_err = def.func_err
        if def.func then             
            local env = self:create_fenv(references, obj)
            d.env = env
            local func = def.func
            d.func = function() setfenv(func, env) return func() end
        end
    end
end

function metadata_grid_context:register_property(references, obj, id, parametrized_index, parameter_type_code, func_pid)
    local cache
    local cache_key
    if parametrized_index then 
        cache = obj.parametrized
        if not cache then 
            cache = {}
            obj.parametrized = cache
        end
        cache_key = parametrized_index
    else
        cache = obj.plain
        if not cache then 
            cache = {}
            obj.plain = cache
        end
        cache_key = id
    end
    local d = rawget(cache, cache_key)
    if not d then
        local def = self:get_definition(id)
        local pid = func_pid or self.binder:register_property(id, obj.src_pid, references.func_root_pid, parameter_type_code or def.parameter_type_code, parametrized_index)
        if pid ~= -1 then
            local last = #references.properties
            d = {pid = pid, id = id, src_pid = obj.src_pid, level = obj.level + 1, parametrized_index = parametrized_index, __layer = "prop"}
            references.properties[last + 1] = d
            self:init_property(references, obj, d, def, func_pid)
            cache[cache_key] = d
        else
            error("Failed to register property. Maximum count properties in view reached. ")
        end
    end

    if self.debug_mode then
        self:debug("get property:", d.property_name, ", pid:", d.pid, ", src:", d.src_pid, ", d:", d, ", ref:", references)
    end
    return d
end

local function add_to_stack(stack, line)
    stack[#stack + 1] = line
    for i=table.getn(stack)-1, 1, -1 do
        if string.len(stack[i]) > string.len(stack[i+1]) then
        break
        end
        stack[i] = stack[i] .. table.remove(stack)
    end
end


local calculate_entry_size
local function calculate_table_size(t, path, key_names)
    local result = 0
    path = path or {}
    path[t] = true
    if t == metadata_grid_context or t == math or t == table or t == string then return 0 end
    if(not(type(t) == "table")) then return 0 end
    for k,v in pairs(t) do
        result = result + 1   
        result = result + calculate_entry_size(k, path, key_names)
                        + calculate_entry_size(v, path, key_names)
    end
    return result
end

calculate_entry_size = 
function(obj, path, key_names)
    local size_v = 0
    if type(obj) == "table" and not path[obj] then
        size_v = calculate_table_size(obj, path, key_names)
        if key_names and rawget(obj, "__layer") then
            local key_value = key_names[tostring(rawget(obj, "__layer"))] or 0
            key_names[tostring(rawget(obj, "__layer"))] = key_value + 1
        end
    end
    return size_v      
end

function metadata_grid_context:dump_memory_consumption()
    local msg = ""
    if self.profiler then
        msg = table.concat(self.profiler:flush()) 
        self:stop_profiler()
    end
    local keys = {}
    local jit_version = "jit off"
    local jit_mode = false
    if type(jit) == 'table' then
       jit_version = jit.version
       jit_mode = jit.status()
    end
    local old_gc = collectgarbage("count")
    collectgarbage("collect")
    local new_gc = collectgarbage("count")
    msg = msg .. "definitions: "            .. tostring(calculate_table_size(self.definitions, nil))          .. " entries; " ..
                 "grid functions: "         .. tostring(calculate_table_size(self.grid_functions, nil, keys)) .. " entries; " ..
                 "type definitions: "       .. tostring(calculate_table_size(self.type_definitions, nil))     .. " entries; " ..
                 "garbage: "                .. old_gc - new_gc                                                .. " KiB; "     ..
                 "memory consumption: "     .. new_gc                                                         .. " KiB; "     ..
                 "jit_version: "            ..  jit_version                                                   .. " "          ..
                 "jit compiler mode on: "   ..  tostring(jit_mode)                                            .. " "          ..
                 "string keys: "            .. table.concat(self:dump_tables(keys, nil, nil, nil, ", "))
    return msg
end


function metadata_grid_context:dump_tables(t, ind, path, stack, delim)
    ind = ind or ""
    path = path or {}
    stack = stack or {}
    delim = delim or "\n"
    add_to_stack(stack, tostring(t) .. delim)
    if self == t or t == math or t == table or t == string then return end
    for k,v in pairs(t) do
        if type(k) == "table" and not path[k] then
            path[k] = true
            self:dump_tables(k, ind .. "  ", path, stack, delim)
            path[k] = nil
        else add_to_stack(stack, ind .. tostring(k))
        end
        add_to_stack(stack, "=")
        if type(v) == "table" and not path[v] and not rawget(v, "print_reference_only") then
            path[v]= true
            self:dump_tables(v, ind .. "  ", path, stack, delim)
            path[v] = nil
        else add_to_stack(stack, tostring(v) .. delim)
        end
    end
    return stack
end

function metadata_grid_context:int_dump(force, args)
    local str = ""
    for i, v in pairs(args) do
        if v ~= nil then
            if i > 1 then str = str .. " " end
            str = str .. tostring(v)
        end
    end
    binder_send_message(self, str, force)
end

function metadata_grid_context:dump(p1, v2, p3, v4, p5, v6, p7, v8, p9, p10, p11, p12)
    if self.debug_mode then self:int_dump(false, {p1, v2, p3, v4, p5, v6, p7, v8, p9, p10, p11, p12}) end
end

function metadata_grid_context:debug(p1, v2, p3, v4, p5, v6, p7, v8, p9, p10, p11, p12)
    self:int_dump(false, {p1, v2, p3, v4, p5, v6, p7, v8, p9, p10, p11, p12})
end

function metadata_grid_context:status(p1, v1, p2, v2)
    self:int_dump(true, {p1, v1, p2, v2})
end

function metadata_grid_context:print_table(t)
    if type(t) ~= "table" then 
        self:debug(t)
        return 
    end 
    return table.concat(self:dump_tables(t))
end

function metadata_grid_context:dump_functions()    
    self:debug(table.concat(self:dump_tables(self.grid_functions)))
    self:debug(self:dump_memory_consumption())
end

--Profiler

function metadata_grid_context:start_profiler()
    if type(jit) ~= "table" then return end
    if not self.profiler then 
        self.profiler = newProfiler() 
        self.profiler:start()
     end
end

function metadata_grid_context:stop_profiler()
    if type(jit) ~= "table" then return end
    if self.profiler then 
        self.profiler:stop()        
        self.profiler = nil
    end
end

_profiler = {}
local stdout = io.stdout

function newProfiler()
  if _profiler.running then return end

  local newprof = {}
  for k,v in pairs(_profiler) do
    newprof[k] = v
  end
  return newprof

end

function _profiler:start()
    if self.running then return end

    -- Start the profiler. This begins by setting up internal profiler state
    _profiler.running = self
    _profiler.stable = _profiler.stable or {} 
    if not _profiler.sfile then
        local sfile = {}
        sfile.flush = function() end
        sfile.close = function() end
        sfile.write = function(self, str) add_to_stack(_profiler.stable, str) end
        _profiler.sfile = sfile
    end
    if not _profiler.start_trace then
        getfenv(1).io.stdout = _profiler.sfile
        local verbose = require("jit.v")
        _profiler.start_trace = verbose.on
        _profiler.stop_trace = verbose.off

    end
    _profiler.start_trace("-")
end

function _profiler.stop(self)
  if _profiler.running ~= self or not _profiler.stop_trace then return end
  _profiler.running = nil
  _profiler.stop_trace()
  getfenv(1).io.stdout = stdout
end

function _profiler:flush()
    local res = _profiler.stable or {} 
    _profiler.stable = {} 
    return res
end

--Profiler end
metadata_grid_context:init_binder(metadata_grid_binder)

return metadata_grid_context
