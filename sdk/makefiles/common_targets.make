###############################################################################
#  Tbricks Build System
#
#  Copyright (c) 2006-2013 Tbricks AB.
#
#  Targets common to both recursive (subdir.make) and non-recursive
#  (strategy.make) builds.
#
###############################################################################

include $(SDK)/makefiles/version.make

.PHONY: check_system
check_system:
ifeq ($(MAKELEVEL),0)
	@echo Performing sanity check...
	@echo '$(MAKEFLAGS)' | awk '{ \
	  s=$$0; \
	  i=index(s, " -- "); \
	  if (i) s=substr(s, 1, i-1);  \
	  if (index(s, " --jobserver-fds=") == 0 && index(s, "=") == 0 && index(s, "j")) exit 1; \
	}' || { echo "Warning: please restart $(MAKE) with explicit number of job slots (e.g. '$(MAKE) -j 8')" >&2; exit 1; }
ifneq ($(and $(MAKECMDGOALS),$(filter-out all test clean gdb memory,$(MAKECMDGOALS))),)
	@{ \
	  if [ -z "$(SYSTEM)" ]; then \
	    echo "ERROR: System name is not specified.";\
	    echo ""; \
	    echo "Usage: gnumake SYSTEM='production_system'";\
	    exit 1;\
	  fi ; \
	  $(TBSYSTEM) get "$(SYSTEM)" >/dev/null || { \
	    echo "ERROR: unable to get system '$(SYSTEM)' information, wrong name?" >&2; \
	    exit 1; \
	  } \
	}
endif
ifneq ($(filter upgrade install,$(MAKECMDGOALS)),)
	@{ \
	  comps=`$(TBCOMPONENT) --parsable ls "$(SYSTEM)" | \
	    awk -F\| '$$2~/Running/{if($$5~/Metadata/) m=1; if($$5~/XRayPersistence/) p=1;};END{if(!m) {printf "Metadata"; if(!p) printf " and XRayPersistence";} else if(!p) printf "XRayPersistence";}'`; \
	  if [ -n "$$comps" ]; then \
	    echo "ERROR: System '$(SYSTEM)' has no running $$comps components." >&2; \
	    exit 1; \
	  fi; \
	}
endif
endif

.PHONY: upgrade_system_metadata
upgrade_system_metadata: check_system
ifeq ($(MAKELEVEL),0)
	@echo Upgrading system metadata...
	$(Q)$(TBPLUGIN) sdk_upgrade "$(PLUGINS_ROOT)/shared/etc" "$(SYSTEM)" || { \
	  echo "ERROR: unable to upgrade system metadata" >&2; \
	  exit 1; \
	}
endif

.PHONY: print_banner
print_banner:
ifeq ($(MAKELEVEL),0)
	@echo "*************************************************************"
	@echo " SDK API Version :" $(TBRICKS_PRODUCT_VERSION)
	@echo "*************************************************************"
endif