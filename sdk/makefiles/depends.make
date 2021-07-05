###############################################################################
#  Tbricks Build System
#
#  Copyright (c) 2007-2011 Tbricks AB.
#
#  Interproject dependency handling.
#
###############################################################################


##### Ananlyze all dependencies.
ifneq ($(DEPENDS),)

define get_name
$$(call mk-log-debug,Processing $(1))

__DEPNAME := $$(strip $$(shell MAKEFLAGS= $(MAKE) --no-print-directory \
			SDK=$$(SDK) $$(if $$(TB_APPS),TB_APPS=$$(TB_APPS)) MK_SRCROOT=$$(MK_SRCROOT) CXX="$$(CXX)" \
			-C $$(call mk-get-depdir,$(1)) __print-name 2>/dev/null || echo __ERROR__))

$$(call mk-log-debug,__DEPNAME: $$(__DEPNAME))

ifeq ($$(__DEPNAME),__ERROR__)
$$(error ERROR: $(notdir $(CURDIR)) - Unable to get name for dependency '$(1)')
endif

ifeq ($$(word 2, $$(__DEPNAME)),static)
DEPENDS.NAMES += $$(word 1, $$(__DEPNAME))
endif

endef

DEPENDS.NAMES :=

$(foreach dep,$(DEPENDS),$(eval $(call get_name,$(dep))))

$(call mk-log-debug,DEPENDS.NAMES: $(DEPENDS.NAMES))

##### Build project dependency graph.

do-prj = $(eval $(call do-prj-template,$(1)))
do-projects = $(foreach dir,$(1),$(call do-prj,$(dir)))

##### The main dependency collection function (recursive)
# Arguments:
#	$(1) - project to process (relative to SRCROOT)
define do-prj-template

# Don't process anything if we're not buildable
ifneq ($$(BUILDABLE),NO)

$$(call mk-log-debug,Processing $(1))

__DEPENDS := $$(strip $$(shell MAKEFLAGS= $(MAKE) --no-print-directory \
			SDK=$$(SDK) $$(if $$(TB_APPS),TB_APPS=$$(TB_APPS)) MK_SRCROOT=$$(MK_SRCROOT) CXX="$$(CXX)" \
			-C $$(call mk-get-depdir,$(1)) __print-depends 2>/dev/null || echo __ERROR__))

$$(call mk-log-debug,DEPENDS: $$(__DEPENDS))

ifeq ($$(__DEPENDS),__ERROR__)
$$(error ERROR: $(notdir $(CURDIR)) - Unable to get depends for '$(1)')
endif

ifeq ($$(__DEPENDS),__UNBUILDABLE__)
BUILDABLE := NO
endif

ifneq ($$(BUILDABLE),NO)

$(1)_DEPENDS := $$(__DEPENDS)

$$(call mk-log-debug,KNOWN: $$(__DEPENDS.all))

__DEPENDS.new := $$(filter-out $$(__DEPENDS.all),$$(__DEPENDS))

$$(call mk-log-debug,NEW: $$(__DEPENDS.new))

__DEPENDS.all += $$(__DEPENDS.new)

$$(call mk-log-debug,ALL: $$(__DEPENDS.all))

# Recursive call
$$(eval $$(call do-projects,$$(__DEPENDS.new)))

endif # BUILDABLE
endif # BUILDABLE

endef   # do-prj-template

# Initial value
__DEPENDS.all := $(sort $(strip $(DEPENDS)))
__DO_DEPENDS := $(__DEPENDS.all)

$(call mk-log-debug,__DO_DEPENDS: $(__DO_DEPENDS))

# Start
$(call do-projects,$(__DEPENDS.all))

ifneq ($(BUILDABLE),NO)
ifneq ($(RECURSIVE),NO)

# Create project building rules

.PHONY: $(__DEPENDS.all)
$(__DEPENDS.all): | $(BEFORE_DEPENDS)
	@$(MAKE) -C $(MK_SRCROOT)/$@ $(MAKECMDGOALS)	\
		RECURSIVE=NO

# Project interdependencies
mk-add-rule = \
	$(call mk-log-debug,Emitting dep rule: $(1): $(2)) \
	$(eval $(1): $(2))

$(foreach prj,$(__DEPENDS.all),\
	$(call mk-add-rule,$(prj),$($(prj)_DEPENDS)))

else

# Don't build anything for when non RECURSIVE
__DO_DEPENDS :=

endif # RECURSIVE
endif # BUILDABLE

endif # DEPENDS

#$(warning EMITTING RULE: do-depends:	$(__DO_DEPENDS))

##### Do not propagate 'clean'
ifeq ($(if $(MAKECMDGOALS),$(filter-out clean,$(MAKECMDGOALS)),"all"),)
__DO_DEPENDS	:=
endif

##### Do not scan dependencies for suppressed builds.
ifeq ($(BUILDABLE),NO)
__DO_DEPENDS	:=
endif

do-depends:	$(__DO_DEPENDS)

###############################################################################
