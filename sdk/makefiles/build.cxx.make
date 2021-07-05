# Add path to HEADERS to allow include "shared/sdk_definitions.h"
HEADERS += $(PLUGINS_ROOT)

##### Profile options
PROFILE	?= release
PROFILE_MAKEFILE := $(wildcard $(SDK)/makefiles/strategy.$(PROFILE).make)
ifeq ($(PROFILE_MAKEFILE),)
$(error Profile "$(PROFILE)" is not supported, "debug" or "release" expected)
endif
include $(SDK)/makefiles/strategy.$(PROFILE).make

ifeq ($(TARGET),)
ifeq ($(LINKAGE),static)
TARGET=$(LIBPFX)$(strip $(NAME))$(LIBEXT)
else
TARGET=$(strip $(NAME))$(SOLIBEXT)
endif
endif

#target is linked against these static libraries
TARGET_DEPENDS := $(wildcard $(foreach dir,$(DEPENDS),\
									$(patsubst %, $(MK_SRCROOT)/$(dir)/$(LIBPFX)%$(LIBEXT),$(DEPENDS.NAMES))))

ADDITIONAL_LIBS += $(addprefix -l, $(DEPENDS.NAMES))
LDFLAGS += $(LDFLAGS.library-dynamic)
LDFLAGS += $(addprefix -L$(MK_SRCROOT)/, $(DEPENDS))

##### Build targets.
SRC_EXTENSIONS	?= .cpp .cc .C .cxx .c
get-sources = $(foreach ext,$(SRC_EXTENSIONS),$(wildcard $(1)*$(ext) \
  $(1)*/*$(ext) \
  $(1)*/*/*$(ext) \
  $(1)*/*/*/*$(ext) \
  $(1)*/*/*/*/*$(ext) \
  $(1)*/*/*/*/*/*$(ext) \
  $(1)*/*/*/*/*/*/*$(ext) \
  $(1)*/*/*/*/*/*/*/*$(ext) \
  $(1)*/*/*/*/*/*/*/*/*$(ext) \
  $(1)*/*/*/*/*/*/*/*/*/*$(ext) \
  $(1)*/*/*/*/*/*/*/*/*/*/*$(ext) \
  $(1)*/*/*/*/*/*/*/*/*/*/*/*$(ext) \
  ))
SOURCES		?= $(call get-sources)

ifneq ($(SUPPRESS_STRATEGY_VERSION),YES)
VERSION_CPP	:= StrategyVersion.cpp
# add to sources only if exists already
SOURCES += $(wildcard $(VERSION_CPP))
VERSION_O	:= $(VERSION_CPP:.cpp=.o)
endif

CXXFLAGS    += -DSTRATEGY_BUILD_PROFILE=\"$(PROFILE)\"

ifneq ($(ICA),)
ifeq ($(PROFILE),debug)
CXX = /opt/llvm-9/bin/clang++
ICA_PLUGIN ?= $(SDK)/platform/lib64/$(LIBPFX)ica-plugin$(SOLIBEXT)
CXXFLAGS+= -Xclang -load -Xclang $(ICA_PLUGIN)
CXXFLAGS+= -Xclang -add-plugin -Xclang ica-plugin
CXXFLAGS+= -Xclang -plugin-arg-ica-plugin -Xclang checks=$(ICA)
endif
endif

_sources := $(sort $(SOURCES))

$(foreach ext,$(SRC_EXTENSIONS),\
    $(foreach s,$(filter %$(ext),$(_sources)),\
        $(eval o := $(notdir $(s:$(ext)=.o))) \
        $(if $(_obj_$(o)),$(error Error: $(_obj_$(o)) and $(s) have the same name, please rename one)) \
        $(eval _obj_$(o) := $(s)) \
        $(eval _objects += $(o))))

OBJECTS	:=	$(_objects)

##### Build Rules.

define __cxx-generate-make-deps
	if [ ! -d $(dir .deps/$(1)) ]; then mkdir -p $(dir .deps/$(1)); fi
	$(CXX) $(CXXFLAGS.mkdep) $(2) > .deps/$(1).d
endef

define __cxx-compile-file
	$(CXX) $(CXXFLAGS) -c $(2) -o $(1)
endef

define cxx-compile-recipe
	$(call __cxx-generate-make-deps,$(strip $(1)),$(strip $(2)))
	$(call __cxx-compile-file,$(strip $(1)),$(strip $(2)))
endef

define __c-generate-make-deps
	if [ ! -d $(dir .deps/$(1)) ]; then mkdir -p $(dir .deps/$(1)); fi
	$(CC) $(CFLAGS.mkdep) $(2) > .deps/$(1).d
endef

define __c-compile-file
	$(CC) $(CFLAGS) -c $(2) -o $(1)
endef

define c-compile-recipe
	$(call __c-generate-make-deps,$(strip $(1)),$(strip $(2)))
	$(call __c-compile-file,$(strip $(1)),$(strip $(2)))
endef

ifeq ($(PRECOMPILED),YES)

.PHONY: $(TARGET)
$(TARGET):
ifneq ($(wildcard $(TARGET)),)
	$(precompiled-msg-action)
else
	$(precompiled-err-action)
	@exit 1
endif

else

$(TARGET): $(OBJECTS) $(TARGET_DEPENDS)
ifneq ($(SUPPRESS_STRATEGY_VERSION),YES)
	@echo '#include "version/StrategyVersion.inl"' > $(VERSION_CPP)
	$(call cxx-compile-recipe,$(VERSION_O),$(VERSION_CPP))
endif
	$(foreach recipe,$(TB_BEFORE_LINK),$($(recipe)))
ifeq ($(LINKAGE),static)
	$(AR) $(ARFLAGS) $@ $(sort $(OBJECTS) $(TB_ADDITIONAL_OBJECTS))
else
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $(sort $(OBJECTS) $(TB_ADDITIONAL_OBJECTS) $(VERSION_O)) $(ADDITIONAL_LIBS)
endif
	$(foreach recipe,$(TB_AFTER_LINK),$($(recipe)))

endif

clean::
	$(RM) $(TARGET) $(VERSION_CPP) *.o
	$(RM) -r .deps
ifneq ($(TB_SDK_RESULT_DIR),)
	@touch "$(TB_SDK_RESULT_DIR)/success$(POSTFIX)"
endif

vpath %.cpp $(sort $(dir $(filter %.cpp,$(_sources))))
vpath %.cc  $(sort $(dir $(filter %.cc, $(_sources))))
vpath %.C   $(sort $(dir $(filter %.C,  $(_sources))))
vpath %.cxx $(sort $(dir $(filter %.cxx,$(_sources))))
vpath %.c   $(sort $(dir $(filter %.c,  $(_sources))))

%.o:	%.cpp
	$(call cxx-compile-recipe,$@,$<)

%.o:	%.cc
	$(call cxx-compile-recipe,$@,$<)

%.o:	%.C
	$(call cxx-compile-recipe,$@,$<)

%.o:	%.cxx
	$(call cxx-compile-recipe,$@,$<)

%.o:	%.c
	$(call c-compile-recipe,$@,$<)

###############################################################################
##### Track source dependencies.
###############################################################################

DEPENDENCY_FILES := $(OBJECTS:%=.deps/%.d)
ifneq ($(DEPENDENCY_FILES),)
-include $(DEPENDENCY_FILES)
endif

include $(SDK)/makefiles/vcproj.make
