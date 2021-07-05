###############################################################################
#  Tbricks Build System
#
#  Copyright (c) 2010-2013 Tbricks AB.
#
#  Microsoft Visual C++ 10.0 project generator.
#
###############################################################################

###############################################################################
##### Project generator input/output.
###############################################################################

VCX_PROJECT ?= $(NAME).vcxproj

VCX_BUILD_BIN ?= .
VCX_INTERMEDIATE_OUTPUT	?= .

# Windows default
VCX_SOLIBDIR ?= $(SDK)/bin

VCX_SOURCES ?= $(filter %.cpp %.cxx %.cc %.C %.c, $(SOURCES))

###############################################################################
##### Project generator internal translations.
###############################################################################

VCX_PLATFORM ?= Win32

ifneq ($(findstring perf,$(PROFILE)),)
VCX_CONFIGURATION = Release
else
VCX_CONFIGURATION = Debug
endif

ifeq ($(PROFILE),release)
VCX_ISDEBUG         ?= false
VCX_ISNDEBUG        ?= true
VCX_OPTIMIZATION    ?= MaxSpeed
DEFINES             += NDEBUG;_WINDOWS;_USRDLL;DLL_EXPORTS
VCX_RUNTIME_LIBRARY ?= MultiThreadedDLL
else
VCX_ISDEBUG         ?= true
VCX_ISNDEBUG        ?= false
VCX_OPTIMIZATION    ?= Disabled
DEFINES             += _DEBUG;_WINDOWS;_USRDLL;DLL_EXPORTS
VCX_RUNTIME_LIBRARY ?= MultiThreadedDebugDLL
endif

# System specific defines
DEFINES += WIN32
DEFINES += _USE_32BIT_TIME_T
DEFINES += _CRT_SECURE_NO_WARNINGS _SCL_SECURE_NO_WARNINGS
DEFINES += NOMINMAX		# don't define min and max macros in windef.h (clash with std::min and std::max)
DEFINES += NOGDI
DEFINES += WIN32_LEAN_AND_MEAN
DEFINES += _WIN32_WINNT=0x0501
DEFINES += _DLL

VCX_DEFINES := $(sort $(DEFINES))

# Path to lib strategy headers are hardcoded in CXXFLAGS, extract them
VCX_HEADERS := $(sort $(HEADERS) $(patsubst -I%,%,$(filter -I%,$(CXXFLAGS))))

VCX_LIBPATH := $(sort $(VCX_SOLIBDIR) $(LIBPATH))

###############################################################################
##### Project generation rules.
###############################################################################

##### Interface rule.
generate-vcproj: $(VCX_PROJECT)

ECHO ?= echo

$(VCX_PROJECT): GNUmakefile
	( \
		$(ECHO) "<?xml version=\"1.0\" encoding=\"utf-8\"?>";\
		$(ECHO) "<Project DefaultTargets=\"Build\" ToolsVersion=\"4.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">";\
		$(ECHO) "  <ItemGroup Label=\"ProjectConfigurations\">";\
		$(ECHO) "    <ProjectConfiguration Include=\"$(VCX_CONFIGURATION)|$(VCX_PLATFORM)\">";\
		$(ECHO) "      <Configuration>$(VCX_CONFIGURATION)</Configuration>";\
		$(ECHO) "      <Platform>$(VCX_PLATFORM)</Platform>";\
		$(ECHO) "    </ProjectConfiguration>";\
		$(ECHO) "  </ItemGroup>";\
\
		$(ECHO) "  <PropertyGroup Label=\"Globals\">";\
		$(ECHO) "    <Configuration>$(VCX_CONFIGURATION)</Configuration>";\
		$(ECHO) "    <Platform>$(VCX_PLATFORM)</Platform>";\
		$(ECHO) "    <Keyword>Win32Proj</Keyword>";\
		$(ECHO) "    <TargetName>$(NAME)</TargetName>";\
		$(ECHO) "  </PropertyGroup>";\
		$(ECHO) "  <Import Project=\"$$""(VCTargetsPath)\Microsoft.Cpp.Default.props\" />";\
\
		$(ECHO) "  <PropertyGroup Label=\"Configuration\">";\
		$(ECHO) "    <ConfigurationType>DynamicLibrary</ConfigurationType>";\
		$(ECHO) "    <UseDebugLibraries>$(VCX_ISDEBUG)</UseDebugLibraries>";\
		$(ECHO) "    <WholeProgramOptimization>$(VCX_ISNDEBUG)</WholeProgramOptimization>";\
		$(ECHO) "  </PropertyGroup>";\
		$(ECHO) "  <Import Project=\"$$""(VCTargetsPath)\Microsoft.Cpp.props\" />";\
		$(ECHO) "  <ImportGroup Label=\"PropertySheets\">";\
		$(ECHO) "    <Import Project=\"$$""(UserRootDir)\Microsoft.Cpp.$$""(Platform).user.props\" Condition=\"exists('$$""(UserRootDir)\Microsoft.Cpp.$$""(Platform).user.props')\" Label=\"LocalAppDataPlatform\" />";\
		$(ECHO) "  </ImportGroup>";\
\
		$(ECHO) "  <PropertyGroup>";\
		$(ECHO) "    <LinkIncremental>$(VCX_ISDEBUG)</LinkIncremental>";\
		$(ECHO) "    <Profile>$(PROFILE)</Profile>";\
		$(ECHO) "    <OutputPath>$(VCX_BUILD_BIN)\</OutputPath>";\
		$(ECHO) "    <BaseIntermediateOutputPath>$(VCX_INTERMEDIATE_OUTPUT)\</BaseIntermediateOutputPath>";\
		$(ECHO) "    <OutDir>$$""(OutputPath)\</OutDir>";\
		$(ECHO) "    <IntDir>$$""(BaseIntermediateOutputPath)\$$""(Configuration)\</IntDir>";\
		$(ECHO) "  </PropertyGroup>";\
\
		$(ECHO) "  <ItemDefinitionGroup>";\
		$(ECHO) "    <ClCompile>";\
		$(ECHO) "      <RuntimeLibrary>$(VCX_RUNTIME_LIBRARY)</RuntimeLibrary>";\
		$(ECHO) "      <MinimalRebuild>false</MinimalRebuild>";\
		$(ECHO) "      <AdditionalOptions>/MP /wd4251 /wd4996 %(AdditionalOptions)</AdditionalOptions>";\
		$(ECHO) "      <WarningLevel>Level3</WarningLevel>";\
		$(ECHO) "      <Optimization>$(VCX_OPTIMIZATION)</Optimization>";\
		$(ECHO) "      <PreprocessorDefinitions>";\
		$(ECHO) "        $(addsuffix ;,$(VCX_DEFINES))%(PreprocessorDefinitions)";\
		$(ECHO) "      </PreprocessorDefinitions>";\
		$(ECHO) "      <FunctionLevelLinking>$(VCX_ISNDEBUG)</FunctionLevelLinking>";\
		$(ECHO) "      <IntrinsicFunctions>$(VCX_ISNDEBUG)</IntrinsicFunctions>";\
		$(ECHO) "      <AdditionalIncludeDirectories>$(addsuffix ;,$(VCX_HEADERS))%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>";\
		$(ECHO) "    </ClCompile>";\
\
		$(ECHO) "    <Link>";\
		$(ECHO) "      <AdditionalLibraryDirectories>$(addsuffix ;,$(VCX_LIBPATH));%(AdditionalLibraryDirectories);</AdditionalLibraryDirectories>";\
		$(ECHO) "      <AdditionalDependencies>";\
		$(ECHO) "        tbricks_strategy.lib;";\
	) >> $@.tmp
ifneq ($(ADDITIONAL_LIBS),)
	$(ECHO) "        $(addsuffix .lib;,$(ADDITIONAL_LIBS))" >> $@.tmp
endif
	( \
		$(ECHO) "        %(AdditionalDependencies)</AdditionalDependencies>";\
		$(ECHO) "      <SubSystem>Windows</SubSystem>";\
		$(ECHO) "      <GenerateDebugInformation>true</GenerateDebugInformation>";\
		$(ECHO) "      <EnableCOMDATFolding>$(VCX_ISNDEBUG)</EnableCOMDATFolding>";\
		$(ECHO) "      <OptimizeReferences>$(VCX_ISNDEBUG)</OptimizeReferences>";\
		$(ECHO) "    </Link>";\
		$(ECHO) "  </ItemDefinitionGroup>";\
		$(ECHO) "  <ItemGroup>";\
		$(ECHO) "$(foreach s,$(VCX_SOURCES),    <ClCompile Include=\"$(s)\"/>)";\
		$(ECHO) "  </ItemGroup>";\
		$(ECHO) "  <Import Project=\"$$""(VCTargetsPath)\Microsoft.Cpp.targets\" />";\
		$(ECHO) "</Project>";\
	) >> $@.tmp
	$(MV) $@.tmp $@

###############################################################################
