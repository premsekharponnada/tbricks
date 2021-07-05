###############################################################################
#  Tbricks Strategy SDK.
#
#  Copyright (c) 2006-2018 Tbricks AB.
#
#  Build wrapper for SDK based tests.
#
###############################################################################

NAME                      ?= my_test
TARGET                    = $(strip $(NAME)).test
LINKAGE                   = dynamic
SUPPRESS_STRATEGY_VERSION = YES
POSTFIX                   = $(TEST_POSTFIX)
AUX_OVERRIDE              = NO
LDFLAGS                   += -Wl,-rpath-link,$(SDK)/platform/lib64 -Wl,-rpath,/opt/gcc-8.2.0/lib64 -Wl,--enable-new-dtags -fuse-ld=gold-2.25 -L$(SDK)/platform/lib64 -ltbricks_strategy_2.14.6.v255
ADDITIONAL_LIBS           += -lgtest -ldl

include $(SDK)/makefiles/library.make

LDFLAGS.library-dynamic =

ifeq ($(TARGET_OS),linux)
ADDITIONAL_LIBS += -llttng-ust
endif

export TB_RELEASE_ROOT=$(SDK)
LD_PRELOAD_CONTENT = $(SDK)/platform/lib64/libjemalloc.so.2
export LD_PRELOAD=$(LD_PRELOAD_CONTENT)

CXXFLAGS += -DUNITTESTING
DEBUGGER = gdb

ifneq ($(LOGS_FILE),)
RUN_OUT_FILE = $(LOGS_FILE).log
ERR_OUT_FILE = $(LOGS_FILE).err
RUNOPTIONS = 1>$(RUN_OUT_FILE) 2>$(ERR_OUT_FILE)
__PRINT_RC := YES

print-error-text :=
ifeq ($(PRINT_RUN_ERRORS),YES)
print-error-text := cat "$(ERR_OUT_FILE)";
endif

clean::
	$(RM) $(RUN_OUT_FILE) $(ERR_OUT_FILE)
endif

ifneq ($(TB_SDK_RESULT_DIR),)
touch-pass := echo "test passed" > "$(TB_SDK_RESULT_DIR)/pass$(TEST_POSTFIX)";
touch-fail := echo "test failed" > "$(TB_SDK_RESULT_DIR)/fail$(TEST_POSTFIX)";
touch-unpass := echo "test passed unexpected" > "$(TB_SDK_RESULT_DIR)/unexpected$(TEST_POSTFIX)";
touch-exfail := echo "test failed as expected" > "$(TB_SDK_RESULT_DIR)/expected$(TEST_POSTFIX)";
check-build := if [ ! -f "$(TB_SDK_RESULT_DIR)/success$(POSTFIX)" ]; then exit 0; fi;
else
touch-pass :=
touch-fail :=
touch-unpass :=
touch-exfail :=
check-build :=
endif

color_red    := \033[31m
color_green  := \033[32m
color_yellow := \033[33m
color_reset  := \033[0m
colorize-str = if [ -t 1 ]; then $(1)="$(3)$(2)$(color_reset)"; else $(1)="$(2)"; fi;

print-status = printf "$$status $(NAME)\n";

EXPECT_FILE ?= $(PLUGINS_ROOT)/tests/tests.expect
ifeq ($(wildcard $(EXPECT_FILE)),)
print-test-expect = false
else
print-test-expect = cat $(EXPECT_FILE) \
                    | sed 's/\#.*//' \
                    | awk '$$2 == "$(subst $(MK_SRCROOT)/,,$(CURDIR))" {print $$1}'
endif

define run-test-commands
$(check-build) \
LD_LIBRARY_PATH=$(SDK)/platform/lib64 $(CURDIR)/$(TARGET) $(RUNOPTIONS); \
let rc=$$? ; \
expect=`$(print-test-expect)`; \
if [ $$rc -ne 0 ]; then \
  if [ "$$expect" = "may_fail" ] || [ "$$expect" = "must_fail" ]; then \
    $(call colorize-str,status,[ FAILED AS EXPECTED ],$(color_yellow)) \
    $(touch-exfail) \
    rc=0; \
  else \
    $(call colorize-str,status,[ FAILED ],$(color_red)) \
    $(touch-fail) \
  fi ; \
else \
  if [ "$$expect" = "must_fail" ]; then \
    $(call colorize-str,status,[ PASSED UNEXPECTED ],$(color_red)) \
    $(touch-unpass) \
    rc=1; \
  else \
    $(call colorize-str,status,[ PASSED ],$(color_green)) \
    $(touch-pass) \
  fi ; \
fi ; \
$(print-error-text) \
$(if $(__PRINT_RC),$(print-status),) \
exit $$rc
endef

ifneq ($(BUILDABLE),NO)

.PHONY: test
test: all
	@+$(run-test-commands)

.PHONY: gdb
gdb: all
	@LD_LIBRARY_PATH=$(SDK)/platform/lib64 DISABLE_TIMEOUT=YES $(DEBUGGER) $(CURDIR)/$(TARGET)

.PHONY: memory
memory: all
	@LD_LIBRARY_PATH=$(SDK)/platform/lib64 LD_PRELOAD="$(LD_PRELOAD) $(SDK)/platform/lib64/libtbricks_stlport4-alloc.so" MEMORY_TRACING=YES DISABLE_TIMEOUT=YES $(CURDIR)/$(TARGET) $(RUNOPTIONS)	

endif

###############################################################################
