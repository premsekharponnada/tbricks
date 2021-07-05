###############################################################################
#  Tbricks Build System
#
#  Copyright (c) 2006-2013 Tbricks AB.
#
#  Definitions common to both recursive (subdir.make) and non-recursive
#  (strategy.make) builds.
#
###############################################################################

ifeq ($(or a,b),)
$(error ERROR: unsupported version of $(basename $(MAKE)) is used, please use '$(SDK)/bin/gnumake' instead)
endif

ifneq ($(filter-out 0 1,$(words $(MAKECMDGOALS))),)
$(error ERROR: specifying more than one target isn't supported)
endif

ifeq ($(origin CC),default)
CC	= clang
endif

ifeq ($(origin CXX),default)
CXX	= clang++
endif

ifeq ($(origin AR),default)
AR	= llvm-ar
endif

# NM is not one of the built-in Make variables
NM	= llvm-nm

COMPILER_DIRS	= /opt/llvm-6.0/bin

__find_compiler = $(firstword $(wildcard $(addsuffix /$(1),$(COMPILER_DIRS))) $(1))

$(foreach v,CC CXX AR NM,\
	$(if $(findstring /,$($(v))),,\
		$(eval $(v) := $(call __find_compiler,$($(v))))))

# ccache binary or NO to disable ccache, or YES to use "ccache"
# Disabled by default:
CCACHE ?= NO

ifeq ($(CCACHE),YES)
override CCACHE := ccache
endif

ifeq ($(CCACHE),)
override __CCACHE := NO
else ifeq ($(CCACHE),NO)
override __CCACHE := NO
else
# in case we do not have ccache:
override __CCACHE := $(shell bash -c 'type -P "$(CCACHE)" || printf NO')
# in case we do not have bash:
ifeq ($(__CCACHE),)
override __CCACHE := NO
endif
ifeq ($(VERBOSE),YES)
ifeq ($(MAKELEVEL),0)
ifeq ($(filter __print-depends __print-name print-build-version,$(MAKECMDGOALS)),)
$(info [ccache] using ccache: $(__CCACHE))
endif
endif
endif
endif

ifneq ($(__CCACHE),NO)
# ccache environment, see man ccache
export CCACHE_COMPILERCHECK ?= mtime
export CCACHE_COMPRESS      ?= 1
export CCACHE_DIR           ?= /var/cache/ccache
export CCACHE_UMASK         ?= 002

ifeq ($(filter $(__CCACHE), $(CC)),)
override CC  := $(__CCACHE) $(CC)
endif
ifeq ($(filter $(__CCACHE), $(CXX)),)
override CXX := $(__CCACHE) $(CXX)
endif

endif
# ^^^ __CCACHE != NO

ifeq ($(MAKECMDGOALS),)
MAKECMDGOALS = all
endif

all:

# "User" targets
TARGETS = all test clean
AUX_TARGETS = install upgrade reload upload

LIBRARY_POSTFIX = _library
STRATEGY_POSTFIX = _strategy
PACKAGE_POSTFIX = _package
TEST_POSTFIX = _test

.PHONY: $(TARGETS) $(AUX_TARGETS)

$(foreach t,$(TARGETS) $(AUX_TARGETS),\
  $(eval VERB_$(t) := $(t)))

VERB_all := build

CONFLICT ?= force

ifneq ($(and $(TB_SDK_RESULT_ROOT),$(TB_SDK_PLUGIN_SUBDIR)),)
TB_SDK_RESULT_DIR := $(TB_SDK_RESULT_ROOT)/$(TB_SDK_PLUGIN_SUBDIR)
endif

ifneq ($(and $(filter upgrade install,$(MAKECMDGOALS)),$(strip $(CONFLICT))),)

CONFLICT_OPT.skip = -s
CONFLICT_OPT.force = -fv
CONFLICT_OPT = $(CONFLICT_OPT.$(CONFLICT))

ifeq ($(CONFLICT_OPT),)
$(error ERROR: invalid conflict resolution method specified in CONFLICT ($(CONFLICT)), use 'skip' or 'force')
endif
endif

GIT ?= git

USE_GIT := $(shell $(GIT) rev-parse --is-inside-work-tree 2>/dev/null)
ifeq ($(USE_GIT),true)
USE_GIT := YES
GIT_ROOT := $(shell $(GIT) rev-parse --show-toplevel)
else
USE_GIT := NO
endif

ifeq ($(MAKELEVEL),0)
ifneq ($(filter install upgrade reload upload install_strategy,$(MAKECMDGOALS)),)
ifeq ($(VERSION),)
ifeq ($(USE_GIT),NO)
$(info WARNING: app is not versioned under git. You can run 'gmake VERSION=<version>' to set version manually)
endif
endif
endif
endif

ADMIN_TOOLS	?= /opt/tbricks/admin/current

include $(SDK)/makefiles/functions.make

mk_prj_dir := $(dir $(abspath $(firstword $(MAKEFILE_LIST))))

# Root directory for apps dependencies
ifeq ($(MK_SRCROOT),)
MK_SRCROOT := $(call mk-find-abs-srcroot, $(mk_prj_dir))
endif

# Resolve symlinks
override MK_SRCROOT := $(realpath $(MK_SRCROOT))
# Remove trailing slash
override MK_SRCROOT := $(patsubst %/,%,$(MK_SRCROOT))
ifeq ($(MK_SRCROOT),)
$(error ERROR: Can not calculate 'MK_SRCROOT'. \
    Are you building not from working copy of apps repository? \
    Please, specify path to the root of apps dependencies in MK_SRCROOT.)
endif

PLUGINS_ROOT := $(or $(shell \
	while :; do \
		p=`pwd`; \
		if [ -d $$p/shared/etc ]; then echo $$p; break; fi; \
		if [ "$$p" = "/" ]; then break; fi; \
		cd ..; \
	done),$(realpath $(TB_APPS)),$(SDK)/source/plugin)

##### Verbosity.
ifeq ($(VERBOSE),YES)
DEV_NULL_ALL =
else
DEV_NULL_ALL = >/dev/null 2>/dev/null
Q = @
endif

TARGET_OS := $(shell uname -s | tr '[A-Z]' '[a-z]')

BUILDABLE ?= YES
# Default message if user set BUILDABLE=NO in GNUmakefile
WHY_NOT_BUILDABLE := "disabled manually"

##### Tools.
MV		?= mv
SED		?= sed
XSLTPROC	?= $(firstword $(wildcard $(SDK)/bin/xsltproc) xsltproc)
TBPLUGIN	?= $(firstword $(wildcard $(SDK)/bin/tbplugin) tbplugin)
TBCOMPONENT	?= $(firstword $(wildcard $(ADMIN_TOOLS)/bin/tbcomponent $(SDK)/bin/tbcomponent) tbcomponent)
TBSYSTEM	?= $(firstword $(wildcard $(ADMIN_TOOLS)/bin/tbsystem $(SDK)/bin/tbsystem) tbsystem)
TBRESOURCE  ?= $(firstword $(wildcard $(ADMIN_TOOLS)/bin/tbresource $(SDK)/bin/tbresource) tbresource)

ifeq ($(PROFILE),asan)
ifeq ($(filter asan, $(TBPLUGIN)),)
override TBPLUGIN := $(TBPLUGIN) asan
endif
endif
