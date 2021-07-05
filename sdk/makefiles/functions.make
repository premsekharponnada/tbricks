###############################################################################
#  Tbricks Build System
#
#  Copyright (c) 2006-2011 Tbricks AB.
#
#  Commonly used functions.
#
###############################################################################

ifeq ($(origin __functions_make),undefined)
__functions_make = 1

###############################################################################
##### Path manipulation routines.
###############################################################################

##### Find MK_SRCROOT absolute path
mk-find-abs-srcroot = $(shell cd $(1) &&\
	while :; do \
		if [ -f .appsroot ]; \
			then pwd; break; fi; \
		if [ "`pwd`" = "/" ]; then echo ""; break; fi; \
	cd ..; done)

###############################################################################
##### Dependency tracking.
###############################################################################

##### Make sure dependency's directory exists.
mk-get-depdir	 = \
$(if $(wildcard $(MK_SRCROOT)/$(1)),$(MK_SRCROOT)/$(1), \
    $(error [build fatal] Unknown dependency '$(1)'))

##### make all paths relative to MK_SRCROOT.
mk-resolve-subdirs = \
$(foreach dir,$(1), \
	$(if $(filter ./% ../%, $(dir)), \
		$(patsubst $(MK_SRCROOT)/%,%,$(realpath $(dir))),\
		$(dir)))

###############################################################################
##### Debug logging
###############################################################################

ifeq ($(MK_LOG_LEVEL),DEBUG)
mk-log-debug = $(info $(1))
endif

endif # __functions_make

###############################################################################
