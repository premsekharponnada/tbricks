###############################################################################
# Configurable parameters
###############################################################################

# APP_MODULE: Maven module name which resulting JAR to collect. By default it
# is the same with the app name, but in multi-module Maven project it can be
# different.
APP_MODULE	?= $(strip $(NAME))

# MVN_EXECUTABLE: Maven executable to call for the build.
MVN_EXECUTABLE	?= $(firstword $(wildcard $(M2_HOME)/bin/mvn /opt/maven/bin/mvn) mvn)

# MVN_OPTS: Command line options to pass to Maven invokation.
MVN_OPTS	?= -V -B

# SOURCES: App source files to check up-to-date build status. By default all
# files are accounted except those in target-sdk directory.
SOURCES		?= $(call get-maven-sources)

###############################################################################
# Internal machinery, do not touch!
###############################################################################

APPS_MAVEN_REPO ?= $(SDK)/maven
APPS_API_JAR    ?= $(SDK)/java/sdk/apps_api.jar

ifeq ($(wildcard $(APPS_API_JAR)),)
  $(error Something wrong with SDK: Can not find API JAR!)
endif

APP_SOURCE_ABS_DIR	:= $(mk_prj_dir)
APP_SOURCE_REL_DIR	:= .
APP_BUILD_ABS_DIR	:= $(APP_SOURCE_ABS_DIR)target-sdk
APP_BUILD_REL_DIR	:= target-sdk

APP_JAR_DIR	:= $(APP_BUILD_ABS_DIR)/$(APP_MODULE)/jar
APP_JAR_FILE	:= $(APP_JAR_DIR)/$(APP_MODULE).jar
APP_MANIFEST_FILE := $(APP_SOURCE_ABS_DIR)/manifest.xml

TARGET_JAR	:= $(APP_BUILD_REL_DIR)/$(strip $(NAME)).jar
TARGET_MANIFEST	:= $(APP_BUILD_REL_DIR)/manifest.xml
TARGET		:= $(TARGET_JAR)

MVN_OPTS_SDK	:= -Ptbricks-sdk \
  -Dapps_api.systemPath='$(APPS_API_JAR)' \
  -Dtbricks-sdk.buildDirectory='$(APP_BUILD_ABS_DIR)' \
  -Dmaven.repo.local='$(APPS_MAVEN_REPO)'

get-maven-sources = $(shell find $(APP_SOURCE_ABS_DIR) \
  -type f \! -path '$(APP_BUILD_ABS_DIR)/*' )


MVN		:= $(MVN_EXECUTABLE) $(MVN_OPTS_SDK) $(MVN_OPTS)

ifeq ($(PRECOMPILED),YES)

.PHONY: $(TARGET_JAR)
$(TARGET_JAR):
ifneq ($(wildcard $(TARGET_JAR)),)
	$(precompiled-msg-action)
else
	$(precompiled-err-action)
	@exit 1
endif

else

$(TARGET_JAR): $(APP_JAR_FILE) $(TARGET_MANIFEST)
	mkdir -p $(dir $@)
	cp $(APP_JAR_FILE) $@

endif

$(TARGET_MANIFEST): $(APP_MANIFEST_FILE)
	mkdir -p $(dir $@)
	cp $(APP_MANIFEST_FILE) $@

$(APP_JAR_FILE): $(SOURCES)
	$(MVN) package

clean::
	$(RM) -r $(APP_BUILD_REL_DIR)
ifneq ($(TB_SDK_RESULT_DIR),)
	@touch "$(TB_SDK_RESULT_DIR)/success"
endif

