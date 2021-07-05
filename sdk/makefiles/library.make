###############################################################################
#  Tbricks Strategy SDK.
#
#  Copyright (c) 2006-2011 Tbricks AB.
#
#  Build wrapper for SDK based libraries. Configurable parameters are:
#
#  SDK			Path to SDK folder, either absolute or relative
#                       [../build.x86_64-sun-solaris/sdk]
#  NAME                 Strategy library name [e.g. peg_order]
#  CC                   C compiler [default: cc]
#  CXX                  C++ compiler [default: CC]
#  SOURCES              Source files
#                       [default: all c and cpp files in current directory and 3 levels under]
#
###############################################################################

##### Vendor settings.
include $(SDK)/makefiles/version.make

##### Default configuration.
include $(SDK)/makefiles/common_defs.make

include $(SDK)/makefiles/common_targets.make

SDK ?= /opt/tbricks/sdk
LINKAGE ?= static
SUPPRESS_STRATEGY_VERSION ?= YES
NAME ?= my_library
POSTFIX ?= $(LIBRARY_POSTFIX)
BUILD_TYPE ?= cxx
PRECOMPILED ?= NO

define precompiled-msg-action
@echo "Using precompiled binary '$(TARGET)'"
endef

define precompiled-err-action
@echo "ERROR: Cannot find precompiled binary '$(TARGET)'."
@echo "       You specified PRECOMPILED=YES option which can only be used with prebuilt apps."
@echo "       Please build the app."
endef

# NOTE: if app depends on SKIP_BUILD_TYPES prj we only want to skip the dependency
# So to fool subdir.make and depends.make always report "stock" BUILDABLE status
ifeq ($(filter __print-depends, $(MAKECMDGOALS)),)
ifneq ($(filter $(BUILD_TYPE),$(SKIP_BUILD_TYPES)),)
BUILDABLE := NO
WHY_NOT_BUILDABLE := "Build type '$(BUILD_TYPE)' skipped by user request"
endif
endif

ifneq ($(BUILDABLE),NO)
ifneq ($(BUILD_ONLY_FOR),)
ifeq ($(filter $(TARGET_OS),$(BUILD_ONLY_FOR)),)
BUILDABLE := NO
WHY_NOT_BUILDABLE := "OS '$(TARGET_OS)' is not supported"
endif
endif
endif

DEPENDS := $(call mk-resolve-subdirs, $(DEPENDS))
DEPENDS := $(patsubst %/,%,$(DEPENDS))

.PHONY: test
test: all

.PHONY: gdb
gdb: all

.PHONY: memory
memory: all

# fast path for __print-depends and __print-name targets, used for DEPENDS collection.
ifneq ($(filter __print-depends __print-name,$(MAKECMDGOALS)),)

.PHONY: __print-depends __print-name

__print-depends:
ifeq ($(BUILDABLE),NO)
	@echo __UNBUILDABLE__
else
	@echo $(DEPENDS)
endif

__print-name:
	@echo $(NAME) $(LINKAGE)

else  # __print-depends __print-name

# print error description when invoked directly
# ignore when building as a dependency
ifneq ($(AUX_OVERRIDE),YES)
ifeq ($(MAKELEVEL),0)
$(AUX_TARGETS): print_static_error
else
$(AUX_TARGETS): all
endif
endif

ifneq ($(BUILDABLE),NO)

ifeq ($(TB_SDK_RESULT_DIR),)
BEFORE_DEPENDS += check_system
endif

include $(SDK)/makefiles/depends.make

ifeq ($(BUILDABLE),NO)
WHY_NOT_BUILDABLE := "One of the dependencies is not buildable."
endif

endif

ifeq ($(BUILDABLE),NO)

# When run in plugin directory
ifeq ($(TB_SDK_RESULT_DIR),)

VERB_print-depends := print

define unbuildable-action
@echo "*************************************************************"
@echo " Nothing to $(VERB_$(MAKECMDGOALS)): $(WHY_NOT_BUILDABLE)"
@echo "*************************************************************"
endef

$(filter-out clean, $(TARGETS)) $(AUX_TARGETS) print-depends:
	$(unbuildable-action)

clean::
	$(unbuildable-action)

else

unbuildable-action = @echo "$(WHY_NOT_BUILDABLE)" > "$(TB_SDK_RESULT_DIR)/skipped$(POSTFIX)"

$(filter-out clean, $(TARGETS)) $(AUX_TARGETS):
	$(unbuildable-action)

clean::
	$(unbuildable-action)

endif

else # ifeq ($(BUILDABLE),NO)

print-depends:
	@echo "$(subst $(MK_SRCROOT),,$(realpath $(mk_prj_dir))): $(sort $(__DEPENDS.all))"

include $(SDK)/makefiles/build.$(BUILD_TYPE).make

ifeq ($(TB_SDK_RESULT_DIR),)
all: check_system print_banner do-depends
	@ $(MAKE) $(TARGET) --no-print-directory

do-depends: check_system print_banner
check_system: print_banner

else # invoked from subdir
all:	do-depends
	@ok=""; \
	for d in $(DEPENDS); do \
	  if echo $(TB_SDK_RESULT_ROOT)/$$d/* | grep -q fail; then \
			ok="no"; break; \
	  fi; \
	done; \
	if [ -n "$$ok" ]; then \
		echo "dependency failed ($$d)" > "$(TB_SDK_RESULT_DIR)/fail$(POSTFIX)"; \
	elif $(MAKE) $(TARGET) $(DEV_NULL_ALL); then \
		touch "$(TB_SDK_RESULT_DIR)/success$(POSTFIX)"; \
	else \
		echo "build failed" > "$(TB_SDK_RESULT_DIR)/fail$(POSTFIX)"; \
	fi
endif

print_static_error:
	$(error ERROR: Cannot "$(MAKECMDGOALS)" library. Try including it in your app)

endif # ifeq ($(BUILDABLE),NO)

endif # __print-depends __print-name

###############################################################################
