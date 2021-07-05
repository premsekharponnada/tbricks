###############################################################################
#  Tbricks Build System
#
#  Copyright (c) 2006-2011 Tbricks AB.
#
#  Subdir build wrapper for GNU Make.
#
#  Usage:
#
#  $ gmake [CXX=<compiler>] [SDK=<path to SDK>]
#
###############################################################################

include $(SDK)/makefiles/common_defs.make

SUBDIRS	?= $(patsubst %/,%,$(dir $(wildcard */GNUmakefile)))

# sanity check
ifeq ($(filter __print-depends, $(MAKECMDGOALS)),)
ifeq ($(MAKELEVEL),0)

ifeq ($(RECURSIVE),)
RECURSIVE := NO
endif

ifeq ($(abspath $(PLUGINS_ROOT)),$(CURDIR))
SUBDIRS := $(filter-out tests, $(SUBDIRS))
endif

ifneq ($(RECURSIVE),YES)
ifneq ($(RECURSIVE),NO)
$(error ERROR: 'RECURSIVE' can be either 'YES' or 'NO')
endif
ifneq ($(filter $(MAKECMDGOALS), all test install reload upload),)
$(error WARNING: You are going to recursively $(VERB_$(MAKECMDGOALS)) all plugins from this directory tree.\
		Use RECURSIVE=YES to confirm this behavior)
endif
endif

RECURSIVE :=

endif
endif

$(foreach t,$(TARGETS) $(AUX_TARGETS),\
  $(eval VERB_$(t) := $(t)ed))

VERB_all     := built
VERB_test    := $(VERB_all)
VERB_upgrade := upgraded

ifeq ($(filter __print-depends, $(MAKECMDGOALS)),)
ifeq ($(TB_SDK_RESULT_ROOT),)

export TB_SDK_RESULT_ROOT := $(shell mktemp -d /var/tmp/tb_sdk_resultXXXXXX)
TB_SDK_RESULT_DIR := $(TB_SDK_RESULT_ROOT)/$(subst $(MK_SRCROOT)/,,$(CURDIR))
$(shell mkdir -p $(TB_SDK_RESULT_DIR))
TARGET_DEPS_install := upgrade_system_metadata
TARGET_DEPS_upgrade := upgrade_system_metadata
PRE_SUBDIRS_TASKS   := print_banner check_system
check_system: print_banner

endif
endif

PRE_SUBDIRS_TASKS += $(TARGET_DEPS_$(MAKECMDGOALS))
PRE_SUBDIRS_TASKS += check_deprecated

.PHONY: check_deprecated
check_deprecated:
	+@{ \
	  d=`ls -d *.plugin *.metadata 2>/dev/null`; \
	  if [ -n "$$d" ]; then \
	    echo "ERROR: Shared metadata ('$$d') must be part of BUILD_TYPE=package project." 1>&2; \
	    echo "subdir.make project cannot have shared metadata" > "$(TB_SDK_RESULT_DIR)/fail$(PACKAGE_POSTFIX)"; \
	    exit 0; \
	  fi; \
	}

PLUGIN_SUBDIR = $@
PLUGIN_RESULT_DIR = $(TB_SDK_RESULT_ROOT)/$@

include $(SDK)/makefiles/common_targets.make

mk-normalize-subdirs = \
	$(subst $(MK_SRCROOT)/,,\
			$(realpath $(if $(2),$(addprefix $(2)/,$(1)),$(1))))

ifneq ($(and $(TB_SDK_RESULT_ROOT),$(TB_SDK_PLUGIN_SUBDIR)),)
$(shell touch "$(TB_SDK_RESULT_ROOT)/$(TB_SDK_PLUGIN_SUBDIR)/subdir")
endif

#####  Build all subdirectories.

# true for top-level invocation and __print-depends target
ifeq ($(MAKELEVEL),0)

ifeq ($(filter __print-depends __print-name, $(MAKECMDGOALS)),)

ifneq ($(SUBDIRS),)

do-subdir = $(eval $(call do-subdir-template,$(1),$(2)))
do-subdirs = $(foreach dir,$(1),$(call do-subdir,$(dir),$(2)))

##### The main dependency collection function (recursive)
# Arguments:
#	$(1) - project to process (relative to SRCROOT)
#	$(2) - subdir flag (if set -- we are called from Makefile with subdir driver)
#		   Need this to include proper file (Makefile or Makefile.inc)
define do-subdir-template
$$(call mk-log-debug,Processing $(1) from subdir = $(2))

ifeq ($$(wildcard $(MK_SRCROOT)/$(1)),)
$$(error Project $(1) doesn't exist)
endif

override BUILDABLE := YES
__IS_SUBDIR :=

__DEPENDS := $$(shell MAKEFLAGS= $$(MAKE) --no-print-directory -C $(MK_SRCROOT)/$(1) \
				SDK=$(SDK) $$(if $(TB_APPS),TB_APPS=$(TB_APPS)) CXX="$(CXX)" MK_SRCROOT=$(MK_SRCROOT) __print-depends || echo __ERROR__ )

$$(call mk-log-debug,DEPENDS1: $$(__DEPENDS))

ifeq ($$(strip $$(__DEPENDS)),__ERROR__)
$$(error Unable to get depends for $(1))
endif

ifeq ($$(strip $$(__DEPENDS)),__UNBUILDABLE__)

override BUILDABLE := NO

else

ifeq ($$(firstword $$(__DEPENDS)),__SUBDIR__)
__IS_SUBDIR := YES
# Cut-off driver marker
__DEPENDS := $$(wordlist 2,$$(words $$(__DEPENDS)),$$(__DEPENDS))
endif

endif # BUILDABLE

$$(call mk-log-debug,DEPENDS: $$(__DEPENDS))
$$(call mk-log-debug,BUILDABLE: $$(BUILDABLE))
$$(call mk-log-debug,IS_SUBDIR: $$(__IS_SUBDIR))

# FIXME: if project is non-buildable and someone depends on it we shouldn't
# remove both from buildable list
# For now we simply check at the end and remove project with empty $($@_PATH)
# See below.
ifneq ($$(BUILDABLE),NO)

$(1)_DEPENDS := $$(__DEPENDS)
$(1)_IS_SUBDIR := $$(__IS_SUBDIR)
$(1)_PATH := $(MK_SRCROOT)/$(1)

ifneq ($$(__IS_SUBDIR),)
$$(foreach prj,$$(__DEPENDS),\
	$$(eval $$(prj)_FROM_SUBDIR := $$($$(prj)_FROM_SUBDIR) $(1)))
endif

$$(call mk-log-debug,KNOWN: $$(__ALL_PROJECTS))
__NEW_PROJECTS := $$(filter-out $$(__ALL_PROJECTS),$$(__DEPENDS))
$$(call mk-log-debug,NEW: $$(__NEW_PROJECTS))
__ALL_PROJECTS += $$(__NEW_PROJECTS)
$$(call mk-log-debug,ALL: $$(__ALL_PROJECTS))

# Recursive call
$$(eval $$(call do-subdirs,$$(__NEW_PROJECTS),$$(__IS_SUBDIR)))

endif # BUILDABLE

endef

__ALL_PROJECTS := $(call mk-normalize-subdirs,$(SUBDIRS))

# Set FROM_SUBDIR property for immediate sub-projects
$(foreach prj,$(__ALL_PROJECTS),\
	$(eval $(prj)_FROM_SUBDIR := $($(prj)_FROM_SUBDIR) $(MK_BUILD_PRJSUBDIR)))

$(call do-subdirs,$(__ALL_PROJECTS),YES)

# Add dependency rules
mk-add-rule = $(eval $(1): $(2))

# For regular projects, build their deps first
# For subdirs, build the subdir before its subprojects (to import metadata)
$(foreach prj,$(__ALL_PROJECTS),\
	$(if $($(prj)_IS_SUBDIR),\
		$(call mk-add-rule,$($(prj)_DEPENDS),$(prj)),\
		$(call mk-add-rule,$(prj),$($(prj)_DEPENDS))))

# Diagnostics
ifeq ($(MK_LOG_LEVEL),DEBUG)
$(foreach prj,$(__ALL_PROJECTS),\
	$(call mk-log-debug,$(prj) -> $($(prj)_DEPENDS) path: $($(prj)_PATH) from subdir: $($(prj)_FROM_SUBDIR)))
endif

# Building rules
.PHONY:	$(__ALL_PROJECTS)

__PROJECTS_TO_BUILD := $(__ALL_PROJECTS)

$(call mk-log-debug,PROJECTS_TO_BUILD: $(__PROJECTS_TO_BUILD))

# Remove unbuildable projects
# See FIXME note in do-subdir-template function above

__PROJECTS_TO_BUILD := \
	$(foreach prj,$(__PROJECTS_TO_BUILD),\
		$(if $($(prj)_PATH),$(prj),))

$(call mk-log-debug,PROJECTS_TO_BUILD: $(__PROJECTS_TO_BUILD))

$(__PROJECTS_TO_BUILD):
	@{ \
	  mkdir -p $(PLUGIN_RESULT_DIR) || exit 1; \
	  ok="no"; \
	  $(MAKE) -s --no-print-directory -C $($@_PATH) $(MAKECMDGOALS) RECURSIVE=NO TB_SDK_PLUGIN_SUBDIR="$(PLUGIN_SUBDIR)" && ok="yes"; \
	  if [ -z "`ls $(PLUGIN_RESULT_DIR)`" ]; then \
	  [ $$ok = "yes" ] && touch $(PLUGIN_RESULT_DIR)/success$(STRATEGY_POSTFIX) \
	                   || touch $(PLUGIN_RESULT_DIR)/fail$(STRATEGY_POSTFIX); \
	  else \
	    if [ -f "$(PLUGIN_RESULT_DIR)/success$(STRATEGY_POSTFIX)" ]; then \
	      echo "$(PLUGIN_SUBDIR) - $(VERB_$(MAKECMDGOALS))"; \
	    elif [ -f "$(PLUGIN_RESULT_DIR)/success$(LIBRARY_POSTFIX)" ]; then \
	      echo "$(PLUGIN_SUBDIR) - $(VERB_$(if $(filter clean, $(MAKECMDGOALS)),clean,all)) (library)"; \
	    elif [ -f "$(PLUGIN_RESULT_DIR)/fail$(STRATEGY_POSTFIX)" ]; then \
	      echo "$(PLUGIN_SUBDIR) - `cat "$(PLUGIN_RESULT_DIR)/fail$(STRATEGY_POSTFIX)"`"; \
	    elif [ -f "$(PLUGIN_RESULT_DIR)/fail$(LIBRARY_POSTFIX)" ]; then \
	      echo "$(PLUGIN_SUBDIR) - `cat "$(PLUGIN_RESULT_DIR)/fail$(LIBRARY_POSTFIX)"` (library)"; \
	    elif [ -f "$(PLUGIN_RESULT_DIR)/fail$(TEST_POSTFIX)" ]; then \
	      echo "$(PLUGIN_SUBDIR) - `cat "$(PLUGIN_RESULT_DIR)/fail$(TEST_POSTFIX)"`"; \
	    elif [ -f "$(PLUGIN_RESULT_DIR)/pass$(TEST_POSTFIX)" ]; then \
	      echo "$(PLUGIN_SUBDIR) - `cat "$(PLUGIN_RESULT_DIR)/pass$(TEST_POSTFIX)"`"; \
	    elif [ -f "$(PLUGIN_RESULT_DIR)/unexpected$(TEST_POSTFIX)" ]; then \
	      echo "$(PLUGIN_SUBDIR) - `cat "$(PLUGIN_RESULT_DIR)/unexpected$(TEST_POSTFIX)"`"; \
	    elif [ -f "$(PLUGIN_RESULT_DIR)/expected$(TEST_POSTFIX)" ]; then \
          echo "$(PLUGIN_SUBDIR) - `cat "$(PLUGIN_RESULT_DIR)/expected$(TEST_POSTFIX)"`"; \
	    elif [ -f "$(PLUGIN_RESULT_DIR)/uptodate$(STRATEGY_POSTFIX)" ]; then \
	      echo "$(PLUGIN_SUBDIR) - `cat "$(PLUGIN_RESULT_DIR)/uptodate$(STRATEGY_POSTFIX)"`"; \
	    elif [ -f "$(PLUGIN_RESULT_DIR)/skipped$(STRATEGY_POSTFIX)" ]; then \
	      echo "$(PLUGIN_SUBDIR) - `cat "$(PLUGIN_RESULT_DIR)/skipped$(STRATEGY_POSTFIX)"`"; \
	    elif [ -f "$(PLUGIN_RESULT_DIR)/skipped$(LIBRARY_POSTFIX)" ]; then \
	      echo "$(PLUGIN_SUBDIR) - `cat "$(PLUGIN_RESULT_DIR)/skipped$(LIBRARY_POSTFIX)"`"; \
	    elif [ -f "$(PLUGIN_RESULT_DIR)/success$(PACKAGE_POSTFIX)" ]; then \
	      echo "$(PLUGIN_SUBDIR) - package $(VERB_$(MAKECMDGOALS))"; \
	    elif [ -f "$(PLUGIN_RESULT_DIR)/fail$(PACKAGE_POSTFIX)" ]; then \
	      echo "$(PLUGIN_SUBDIR) - `cat "$(PLUGIN_RESULT_DIR)/fail$(PACKAGE_POSTFIX)"`"; \
	    elif [ -f "$(PLUGIN_RESULT_DIR)/skipped$(PACKAGE_POSTFIX)" ]; then \
	      echo "$(PLUGIN_SUBDIR) - `cat "$(PLUGIN_RESULT_DIR)/skipped$(PACKAGE_POSTFIX)"`"; \
	    fi; \
	  fi; \
	}

endif # SUBDIRS

$(__PROJECTS_TO_BUILD): $(PRE_SUBDIRS_TASKS)

$(TARGETS) $(AUX_TARGETS): $(__PROJECTS_TO_BUILD)
	@{ \
	  echo; \
	  echo "Summary:"; \
	  echo "========"; \
	  echo; \
	  echo "Finished at `date`"; \
	  msg=""; \
	  uptodate=`find $(TB_SDK_RESULT_ROOT) -type f -name uptodate$(STRATEGY_POSTFIX) | wc -l | sed 's/ *//g'`; \
	  if [ x"$$uptodate" != "x0" ]; then \
	    echo; \
	    echo "Up to date plugins:"; \
	    find $(TB_SDK_RESULT_ROOT) -type f -name uptodate$(STRATEGY_POSTFIX) | \
	      sed 's!^$(TB_SDK_RESULT_ROOT)/!  * !;s!/uptodate$(STRATEGY_POSTFIX)$$!!'; \
	    us="s are"; [ x"$$uptodate" = "x1" ] && us=" is"; \
	    msg="$$uptodate plugin$$us up to date"; \
	  fi; \
	  success=`find $(TB_SDK_RESULT_ROOT) -type f -name success$(STRATEGY_POSTFIX) | wc -l | sed 's/ *//g'`; \
	  if [ x"$$success" != "x0" ]; then \
	    echo; \
	    echo "Successfully $(VERB_$@) plugins:"; \
	    find $(TB_SDK_RESULT_ROOT) -type f -name success$(STRATEGY_POSTFIX) | \
	      sed 's!^$(TB_SDK_RESULT_ROOT)/!  * !;s!/success$(STRATEGY_POSTFIX)$$!!'; \
	  fi; \
	  fail=`find $(TB_SDK_RESULT_ROOT) -type f -name fail$(STRATEGY_POSTFIX) | wc -l | sed 's/ *//g'`; \
	  if [ x"$$fail" != "x0" ]; then \
	    echo; \
	    echo "Failed plugins:"; \
	    find $(TB_SDK_RESULT_ROOT) -type f -name fail$(STRATEGY_POSTFIX) | \
	      sed 's!^$(TB_SDK_RESULT_ROOT)/!  * !;s!/fail$(STRATEGY_POSTFIX)$$!!'; \
	  fi; \
	  success_package=`find $(TB_SDK_RESULT_ROOT) -type f -name success$(PACKAGE_POSTFIX) | wc -l | sed 's/ *//g'`; \
	  if [ x"$$success_package" != "x0" ]; then \
	    echo; \
	    echo "Successfully $(VERB_$@) packages:"; \
	    find $(TB_SDK_RESULT_ROOT) -type f -name success$(PACKAGE_POSTFIX) | \
	      sed 's!^$(TB_SDK_RESULT_ROOT)/!  * !;s!/success$(PACKAGE_POSTFIX)$$!!'; \
	  fi; \
	  fail_package=`find $(TB_SDK_RESULT_ROOT) -type f -name fail$(PACKAGE_POSTFIX) | wc -l | sed 's/ *//g'`; \
	  if [ x"$$fail_package" != "x0" ]; then \
	    echo; \
	    echo "Failed packages:"; \
	    find $(TB_SDK_RESULT_ROOT) -type f -name fail$(PACKAGE_POSTFIX) | \
	      sed 's!^$(TB_SDK_RESULT_ROOT)/!  * !;s!/fail$(PACKAGE_POSTFIX)$$!!'; \
	  fi; \
	  pass_test=`find $(TB_SDK_RESULT_ROOT) -type f -name pass$(TEST_POSTFIX) | wc -l | sed 's/ *//g'`; \
	  if [ x"$$pass_test" != "x0" ]; then \
	    echo; \
	    echo "Passed tests:"; \
	    find $(TB_SDK_RESULT_ROOT) -type f -name pass$(TEST_POSTFIX) | \
	      sed 's!^$(TB_SDK_RESULT_ROOT)/!  * !;s!/pass$(TEST_POSTFIX)$$!!'; \
	  fi; \
	  unexpected_test=`find $(TB_SDK_RESULT_ROOT) -type f -name unexpected$(TEST_POSTFIX) | wc -l | sed 's/ *//g'`; \
	  if [ x"$$unexpected_test" != "x0" ]; then \
	    echo; \
	    echo "Unexpected passed tests:"; \
	    find $(TB_SDK_RESULT_ROOT) -type f -name unexpected$(TEST_POSTFIX) | \
	      sed 's!^$(TB_SDK_RESULT_ROOT)/!  * !;s!/unexpected$(TEST_POSTFIX)$$!!'; \
	  fi; \
	  fail_test=`find $(TB_SDK_RESULT_ROOT) -type f -name fail$(TEST_POSTFIX) | wc -l | sed 's/ *//g'`; \
	  if [ x"$$fail_test" != "x0" ]; then \
	    echo; \
	    echo "Failed tests:"; \
	    find $(TB_SDK_RESULT_ROOT) -type f -name fail$(TEST_POSTFIX) | \
	      sed 's!^$(TB_SDK_RESULT_ROOT)/!  * !;s!/fail$(TEST_POSTFIX)$$!!'; \
	  fi; \
	  expected_test=`find $(TB_SDK_RESULT_ROOT) -type f -name expected$(TEST_POSTFIX) | wc -l | sed 's/ *//g'`; \
	  if [ x"$$expected_test" != "x0" ]; then \
	    echo; \
	    echo "Failed as expected tests:"; \
	    find $(TB_SDK_RESULT_ROOT) -type f -name expected$(TEST_POSTFIX) | \
	      sed 's!^$(TB_SDK_RESULT_ROOT)/!  * !;s!/expected$(TEST_POSTFIX)$$!!'; \
	  fi; \
	  echo; \
	  ss="s"; [ x"$$success" = "x1" ] && ss=""; \
	  fs="s"; [ x"$$fail" = "x1" ] && fs=""; \
	  tss="s"; [ x"$$pass_test" = "x1" ] && tss=""; \
	  tus="s"; [ x"$$unexpected_test" = "x1" ] && tus=""; \
	  tfs="s"; [ x"$$fail_test" = "x1" ] && tfs=""; \
	  tes="s"; [ x"$$expected_test" = "x1" ] && tes=""; \
	  fss="s"; [ x"$$fail_package" = "x1" ] && fss=""; \
	  [ -n "$$msg" ] && msg="$$msg, "; \
	  echo "$$msg$$success plugin$$ss $(VERB_$@)"; \
	  echo "$$fail plugin$$fs failed"; \
	  echo "$$fail_package package$$fss failed"; \
	  echo "$$pass_test test$$tss passed"; \
	  echo "$$unexpected_test test$$tus passed unexpected"; \
	  echo "$$fail_test test$$tfs failed"; \
	  echo "$$expected_test test$$tes failed as expected"; \
	  rm -rf $(TB_SDK_RESULT_ROOT); \
	  [ x"$$fail" = "x0" ] || exit 1; \
	  [ x"$$fail_package" = "x0" ] || exit 1; \
	  [ x"$$fail_test" = "x0" ] || exit 1; \
	  [ x"$$unexpected_test" = "x0" ] || exit 1; \
	}

endif # __print-*

DEPENDS := __SUBDIR__ $(call mk-normalize-subdirs,$(SUBDIRS))

__print-depends:
	@echo $(DEPENDS)

else # MAKELEVEL

$(TARGETS) $(AUX_TARGETS): $(PRE_SUBDIRS_TASKS)

endif # MAKELEVEL

###############################################################################
