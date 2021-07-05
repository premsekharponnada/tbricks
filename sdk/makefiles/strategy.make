###############################################################################
#  Tbricks Strategy SDK.
#
#  Copyright (c) 2006-2011 Tbricks AB.
#
#  Build wrapper for SDK based strategies. Configurable parameters are:
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

LINKAGE = dynamic
SUPPRESS_STRATEGY_VERSION ?= NO
NAME ?= my_strategy
ifneq ($(BUILD_TYPE),package)
POSTFIX = $(STRATEGY_POSTFIX)
else
POSTFIX = $(PACKAGE_POSTFIX)
endif
AUX_OVERRIDE = YES

ifeq ($(TB_SDK_RESULT_DIR),)
ifneq ($(filter install upgrade,$(MAKECMDGOALS)),)
BEFORE_DEPENDS += upgrade_system_metadata
endif
endif

include $(SDK)/makefiles/library.make

ifneq ($(filter print-build-version,$(MAKECMDGOALS)),)

# This should be called after TARGET is built to grep $(DEPENDENCY_FILES)
.PHONY: print-build-version
print-build-version:
	@echo '$(VERSION)'

ifeq ($(strip $(VERSION)),)

ifeq ($(USE_GIT),YES)
# Get last commit that affected any of the specified files
git-last-commit = $(shell $(GIT) rev-list --abbrev-commit -1 --topo-order HEAD -- $(patsubst %,'%',$(1)))

# Get deleted, modified, and other (untracked) files in the specified dir
git-dirty = $(shell $(GIT) ls-files -dmo --exclude-standard $(patsubst %,'%',$(1)))

# filter out missing .deps
app_dep_files := $(wildcard $(DEPENDENCY_FILES))
ifneq ($(app_dep_files),)
app_deps   := $(shell cat $(app_dep_files) | sed -e 's/^.*://' -e 's/\\$$/ /')
endif
app_files_all  := $(sort $(abspath $(app_deps) $(SOURCES)))
app_files_git  := $(filter $(abspath $(GIT_ROOT))%, $(app_files_all))
ifeq ($(BUILD_TYPE),maven)
app_files_git  += $(abspath $(GIT_ROOT))/pom.xml
endif
git_version    := $(call git-last-commit, . $(filter-out $(CURDIR)%,$(app_files_git)))
ifneq ($(git_version),)
git_status_all := $(abspath $(call git-dirty,$(abspath $(GIT_ROOT))))
git_status_app := $(strip $(filter $(app_files_git),$(git_status_all)) \
					$(filter $(CURDIR)%,$(git_status_all)))
git_version := $(git_version)$(if $(git_status_app),_with_local_changes)
else
git_version := no_commits_yet
endif

override VERSION := $(git_version)
else # USE_GIT
override VERSION := none
endif # USE_GIT

endif # VERSION

endif # print-build-version

# fast path for __print-depends and __print-name targets, used for DEPENDS collection.
ifeq ($(filter __print-depends __print-name print-build-version,$(MAKECMDGOALS)),)

ifneq ($(BUILDABLE),NO)

RESOURCE_FILES :=

define parse-resources
ifneq ($$(words $(1)),0)
__RFILE := $$(word 1,$(1))
__RNAME := $$(word 2,$(1))@$(SYSTEM)
__RTYPE := $$(word 3,$(1))
RESOURCE_FILES += $$(__RFILE)
$$(__RFILE).NAME := $$(__RNAME)
ifneq ($$(__RTYPE),-)
$$(__RFILE).TYPE := $$(__RTYPE)
endif
$$(eval $$(call parse-resources, $$(wordlist 4,$$(words $(1)),$(1))))
endif
endef

$(eval $(call parse-resources,$(RESOURCES)))

ifeq ($(origin RESOURCES),undefined)
RESOURCE_FILES := $(wildcard resources/*)
$(foreach r,$(RESOURCE_FILES),$(eval $(r).NAME := $(notdir $(r))@$(SYSTEM)))
endif

ifneq ($(filter install,$(MAKECMDGOALS)),)
$(RESOURCE_FILES): do-install
endif

ifneq ($(filter upgrade,$(MAKECMDGOALS)),)

# checks that given app is installed
# $(1) path to app
# if installed, app is appended to PLUGINS_INSTALLED
# last error is written to __UPGRADE_ERROR
define is-installed
__PLUGIN_INSTALLED :=
__UPGRADE_ERROR :=
ifneq ($$(wildcard $(1)/manifest.xml),)
__PLUGIN_NAME := $$(shell $(XSLTPROC) $(SDK)/makefiles/get_name.xsl $(1)/manifest.xml)
__PLUGIN_ID   := $$(shell $(XSLTPROC) $(SDK)/makefiles/get_id.xsl   $(1)/manifest.xml)
ifneq ($$(strip $$(__PLUGIN_ID)),)
__PLUGIN_INFO := $$(shell $(TBPLUGIN) get "$$(__PLUGIN_ID)")
ifneq ($$(findstring system : $(SYSTEM),$$(__PLUGIN_INFO)),)
__PLUGIN_INSTALLED := YES
PLUGINS_INSTALLED := $$(strip $$(PLUGINS_INSTALLED) $(1))
endif
else # __PLUGIN_ID
__UPGRADE_ERROR := ERROR: empty plugin id ($(1)/manifest.xml)
endif # __PLUGIN_ID
else # manifest.xml
__UPGRADE_ERROR := ERROR: no manifest.xml found ($(1)/manifest.xml)
endif # manifest.xml
$(1)_UPGRADE_ERROR := $$(__UPGRADE_ERROR)
endef

ifeq ($(BUILD_TYPE),package)
MANIFESTS := $(dir $(shell find .. -type f -name manifest.xml))
SKIPPED_MSG_USER = None of package plugins are installed, nothing to upgrade.
SKIPPED_MSG_FILE = none of package plugins are installed
else
MANIFESTS := .
SKIPPED_MSG_USER = Plugin '$(__PLUGIN_NAME)' ($(__PLUGIN_ID)) not installed, nothing to upgrade.
SKIPPED_MSG_FILE = plugin is not installed
endif

$(foreach m,$(MANIFESTS),$(eval $(call is-installed,$(m))))
ifeq ($(PLUGINS_INSTALLED),)
RESOURCE_FILES :=
endif

$(RESOURCE_FILES): do-upgrade
endif

# Plug in additional user targets
.PHONY: do-install do-upgrade
install: do-install $(RESOURCE_FILES) $(AFTER_INSTALL)
upgrade: do-upgrade $(RESOURCE_FILES) $(AFTER_UPGRADE)
$(AFTER_INSTALL): do-install $(RESOURCE_FILES)
$(AFTER_UPGRADE): do-upgrade $(RESOURCE_FILES)

.PHONY: $(RESOURCE_FILES)
$(RESOURCE_FILES):
	@{ \
	  out=`$(TBRESOURCE) get $($@.NAME) 2>&1`; \
	  if [ $$? -ne 0 ]; then \
	    echo "$$out" | grep -q 'No resource is found'; \
	    if [ $$? -eq 0 ]; then \
	      $(TBRESOURCE) create $($@.NAME) $(if $(TB_SDK_RESULT_DIR),$(DEV_NULL_ALL)); \
	      $(TBRESOURCE) set systems=$(SYSTEM) $($@.NAME) $(if $(TB_SDK_RESULT_DIR),$(DEV_NULL_ALL)); \
	    else \
	      echo "ERROR: $$out"; \
	    fi; \
	  fi; \
	}
	@$(TBRESOURCE) import $@ $($@.NAME) $($@.TYPE) $(if $(TB_SDK_RESULT_DIR),$(DEV_NULL_ALL))

# Cannot directly depend on 'all' target because we don't want to build the app on upgrade if it isn't installed
do-install: do-depends
	@+{ $(install-strategy-commands) }

do-upgrade: do-depends
	@+{ \
	  [ -z "$(__UPGRADE_ERROR)" ] || { echo "$(__UPGRADE_ERROR)"; exit 1; }; \
	  if [ -z "$(PLUGINS_INSTALLED)" ]; then \
	      if [ -z "$(TB_SDK_RESULT_DIR)" ]; then \
	        echo "$(SKIPPED_MSG_USER)"; \
	      else \
	        echo "$(SKIPPED_MSG_FILE)" > "$(TB_SDK_RESULT_DIR)/skipped$(POSTFIX)"; \
	      fi; \
	      exit 0; \
	  fi; \
	  $(install-strategy-commands) \
	}

# When run in plugin directory
ifeq ($(TB_SDK_RESULT_DIR),)

reload upload: all
ifneq ($(BUILD_TYPE),package)
	$(Q)v=$(VERSION); \
	if [ -z "$$v" ]; then \
	  v=`MAKEFLAGS= $(MAKE) --no-print-directory print-build-version CXX="$(CXX)" $(if $(TB_APPS),TB_APPS=$(TB_APPS)) MK_SRCROOT=$(MK_SRCROOT) VERSION=$(VERSION)`; \
	fi;\
	$(TBPLUGIN) reload $(TARGET) $(SYSTEM) "$$v"
endif

do-install: print_banner check_system upgrade_system_metadata
do-upgrade: print_banner check_system upgrade_system_metadata
upgrade_system_metadata: print_banner check_system

define install-strategy-commands
p=""; \
for f in `ls -d *.plugin *.metadata 2>/dev/null`; do \
  if [ -n "$$p" ]; then \
    echo "ERROR: found more than one plugin metadata file: '$$p' and '$$f'" >&2; \
    exit 1; \
  else \
    p="$$f"; \
  fi; \
done; \
$(MAKE) --no-print-directory install_strategy RECURSIVE=NO PLUGIN_FILE="$$p" CONFLICT_OPT=$(CONFLICT_OPT);
endef

.PHONY: install_strategy
install_strategy: $(TARGET)
ifneq ($(PLUGIN_FILE),)
	$(TBPLUGIN) import $(CONFLICT_OPT) "$(PLUGIN_FILE)" "$(SYSTEM)" "$(USER)"
endif
ifneq ($(BUILD_TYPE),package)
	$(Q)v=$(VERSION); \
	if [ -z "$$v" ]; then \
	  v=`MAKEFLAGS= $(MAKE) --no-print-directory print-build-version CXX="$(CXX)" $(if $(TB_APPS),TB_APPS=$(TB_APPS)) MK_SRCROOT=$(MK_SRCROOT) VERSION=$(VERSION)`; \
	fi;\
	$(TBPLUGIN) reload $(TARGET) $(SYSTEM) "$$v"
endif

else  # invoked from subdir

reload upload:
	@{ \
	  $(MAKE) all $(DEV_NULL_ALL); \
	  [ -f "$(TB_SDK_RESULT_DIR)/fail$(POSTFIX)" ] && exit 0; \
	  [ -f "$(TB_SDK_RESULT_DIR)/success$(POSTFIX)" ] && rm "$(TB_SDK_RESULT_DIR)/success$(POSTFIX)"; \
	  if [ "$(BUILD_TYPE)" != "package" ]; then \
	    v=$(VERSION); \
	    if [ -z "$$v" ]; then \
	      v=`MAKEFLAGS= $(MAKE) --no-print-directory print-build-version CXX="$(CXX)" $(if $(TB_APPS),TB_APPS=$(TB_APPS)) MK_SRCROOT=$(MK_SRCROOT) VERSION=$(VERSION)`; \
	    fi;\
	    $(TBPLUGIN) reload --fail-if-up-to-date "$(TARGET)" "$(SYSTEM)" "$$v" $(DEV_NULL_ALL) || { \
	      if [ $$? -eq 77 ]; then \
	        echo "plugin is up-to-date" > "$(TB_SDK_RESULT_DIR)/uptodate$(POSTFIX)"; \
	      else \
	        echo "$@ failed" > "$(TB_SDK_RESULT_DIR)/fail$(POSTFIX)"; \
	      fi; \
	      exit 0; \
	    }; \
	  fi; \
	  touch "$(TB_SDK_RESULT_DIR)/success$(POSTFIX)"; \
	}

define install-strategy-commands
p=""; \
for f in `ls -d *.plugin *.metadata 2>/dev/null`; do \
  if [ -n "$$p" ]; then \
    echo "metadata import failed" > "$(TB_SDK_RESULT_DIR)/fail$(POSTFIX)"; \
    exit 0; \
  else \
    p="$$f"; \
  fi; \
done; \
$(MAKE) all $(DEV_NULL_ALL); \
[ -f "$(TB_SDK_RESULT_DIR)/fail$(POSTFIX)" ] && exit 0; \
[ -f "$(TB_SDK_RESULT_DIR)/success$(POSTFIX)" ] && rm "$(TB_SDK_RESULT_DIR)/success$(POSTFIX)"; \
if [ -n "$$p" ]; then \
  $(TBPLUGIN) import $(CONFLICT_OPT) "$$p" "$(SYSTEM)" "$(USER)" $(DEV_NULL_ALL) || { \
    echo "metadata import failed" > "$(TB_SDK_RESULT_DIR)/fail$(POSTFIX)"; \
    exit 0; \
  }; \
fi; \
if [ "$(BUILD_TYPE)" != "package" ]; then \
  v=$(VERSION); \
  if [ -z "$$v" ]; then \
    v=`MAKEFLAGS= $(MAKE) --no-print-directory print-build-version CXX="$(CXX)" $(if $(TB_APPS),TB_APPS=$(TB_APPS)) MK_SRCROOT=$(MK_SRCROOT) VERSION=$(VERSION)`; \
  fi;\
  $(TBPLUGIN) reload --fail-if-up-to-date $(TARGET) "$(SYSTEM)" "$$v" $(DEV_NULL_ALL) || { \
    if [ $$? -eq 77 ]; then \
      echo "plugin is up-to-date" > "$(TB_SDK_RESULT_DIR)/uptodate$(POSTFIX)"; \
    else \
      echo "plugin reload failed" > "$(TB_SDK_RESULT_DIR)/fail$(POSTFIX)"; \
    fi; \
    exit 0; \
  }; \
fi;\
touch "$(TB_SDK_RESULT_DIR)/success$(POSTFIX)";
endef

endif  # invoked from subdir

endif # ifeq ($(BUILDABLE),NO)

endif # __print-depends __print-name

###############################################################################
