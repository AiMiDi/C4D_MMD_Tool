# DO NOT EDIT.
# This file is auto-generated. Manual edits may be overwritten and lost on CMake configure.
# If manual editing is required, copy the filled out template from the binary sub-directory of your target into the source directory next to 'projectdefinition.txt'.
# In such a case, the CMake file is used and projectdefinition.txt is not parsed.

# Since the CMakeLists.txt file is not in the 'actual' source dir, we bend it. Note that this variable change has no effect on add_library(), Therefore, paths to source files must absolute not relative if you rely on auto-generated CMakeLists.txt files within the build directory.
# If you put the CMakeLists.txt file next to the projectdefinition.txt this issue does not apply. Feel free to delete the next line and check-in this file into your code versioning system without having to rely on absolute paths.
set(CMAKE_CURRENT_SOURCE_DIR <<CMAKE_CURRENT_SOURCE_DIR>>)

# Please take note of the suboptimal modeling of maxon_prebuildEvents.<platform>.
# The nature of prebuild_event.py files prohibits a clean model of inputs and outputs within CMake. To satisfy the requirements for certain generators, .e.g. Xcode,
# timestamp input and output files are generated and depended upon. This creates false negatives in dirtiness, but allows convenient developer interaction within the IDE
# without continuously rerunning the prebuild event scripts.

include(${MAXON_TOOLING_DIR}/sdk_targets.cmake)
include(${MAXON_TOOLING_DIR}/sdk_compiler_helper.cmake)

# Variables to auto-fill.
#########################
# --- general ---
set(maxon_targetName <<maxon_targetName>>)
set(maxon_targetType <<maxon_targetType>>)
set(maxon_targetFrameworkDependencies <<maxon_targetFrameworkDependencies>>)
set(maxon_targetPublicCompileDefinitions <<maxon_targetPublicCompileDefinitions>>)
set(maxon_targetPrivateCompileDefinitions <<maxon_targetPrivateCompileDefinitions>>)
set(maxon_targetPlatforms <<maxon_targetPlatforms>>)
set(maxon_targetSourceDirectories <<maxon_targetSourceDirectories>>)
set(maxon_targetRegisterGeneratedFileNames <<maxon_targetRegisterGeneratedFileNames>>)
set(maxon_targetTypeViewerFiles <<maxon_targetTypeViewerFiles>>)
set(maxon_additionalDefinitions <<maxon_additionalDefinitions>>)
set(maxon_enableRTTI <<maxon_enableRTTI>>)
set(maxon_enableExceptionHandling <<maxon_enableExceptionHandling>>)

# --- WINDOWS specific ---
set(maxon_excludeFromBuild.WINDOWS <<maxon_excludeFromBuild.WINDOWS>>)
set(maxon_exclude.WINDOWS <<maxon_exclude.WINDOWS>>)
set(maxon_additionalDefinitions.WINDOWS <<maxon_additionalDefinitions.WINDOWS>>)
set(maxon_linkLibraries.WINDOWS.DEBUG <<maxon_linkLibraries.WINDOWS.DEBUG>>)
set(maxon_linkLibraries.WINDOWS.RELEASE <<maxon_linkLibraries.WINDOWS.RELEASE>>)
set(maxon_linkLibraries.WINDOWS.ARM <<maxon_linkLibraries.WINDOWS.ARM>>)
set(maxon_additionalIncludeDirectories.WINDOWS <<maxon_additionalIncludeDirectories.WINDOWS>>)
set(maxon_additionalIncludeDirectories.WINDOWS.ARM <<maxon_additionalIncludeDirectories.WINDOWS.ARM>>)
set(maxon_additionalLinkDirectories.WINDOWS <<maxon_additionalLinkDirectories.WINDOWS>>)
set(maxon_additionalLinkDirectories.WINDOWS.DEBUG <<maxon_additionalLinkDirectories.WINDOWS.DEBUG>>)
set(maxon_additionalLinkDirectories.WINDOWS.RELEASE <<maxon_additionalLinkDirectories.WINDOWS.RELEASE>>)
set(maxon_additionalLinkDirectories.WINDOWS.ARM <<maxon_additionalLinkDirectories.WINDOWS.ARM>>)
set(maxon_additionalSourceFiles.WINDOWS <<maxon_additionalSourceFiles.WINDOWS>>)
set(maxon_prebuildEvents.WINDOWS.DEBUG [=[<<maxon_prebuildEvents.WINDOWS.DEBUG>>]=])
set(maxon_prebuildEvents.WINDOWS.RELEASE [=[<<maxon_prebuildEvents.WINDOWS.RELEASE>>]=])
set(maxon_subsystem.WINDOWS <<maxon_subsystem.WINDOWS>>)

# --- MACOS specific ---
set(maxon_excludeFromBuild.MACOS <<maxon_excludeFromBuild.MACOS>>)
set(maxon_exclude.MACOS <<maxon_exclude.MACOS>>)
set(maxon_additionalDefinitions.MACOS <<maxon_additionalDefinitions.MACOS>>)
set(maxon_linkLibraries.MACOS.DEBUG <<maxon_linkLibraries.MACOS.DEBUG>>)
set(maxon_linkLibraries.MACOS.RELEASE <<maxon_linkLibraries.MACOS.RELEASE>>)
set(maxon_additionalIncludeDirectories.MACOS <<maxon_additionalIncludeDirectories.MACOS>>)
set(maxon_linkFrameworks.MACOS <<maxon_linkFrameworks.MACOS>>)
set(maxon_additionalSourceFiles.MACOS <<maxon_additionalSourceFiles.MACOS>>)
set(maxon_prebuildEvents.MACOS.DEBUG [=[<<maxon_prebuildEvents.MACOS.DEBUG>>]=])
set(maxon_prebuildEvents.MACOS.RELEASE [=[<<maxon_prebuildEvents.MACOS.RELEASE>>]=])

# --- LINUX specific ---
set(maxon_excludeFromBuild.LINUX <<maxon_excludeFromBuild.LINUX>>)
set(maxon_exclude.LINUX <<maxon_exclude.LINUX>>)
set(maxon_additionalDefinitions.LINUX <<maxon_additionalDefinitions.LINUX>>)
set(maxon_linkLibraries.LINUX.DEBUG <<maxon_linkLibraries.LINUX.DEBUG>>)
set(maxon_linkLibraries.LINUX.RELEASE <<maxon_linkLibraries.LINUX.RELEASE>>)
set(maxon_additionalSourceFiles.LINUX <<maxon_additionalSourceFiles.LINUX>>)
set(maxon_systemIncludePaths <<maxon_systemIncludePaths>>)
set(maxon_additionalLinkDirectories.LINUX.DEBUG <<maxon_additionalLinkDirectories.LINUX.DEBUG>>)
set(maxon_additionalLinkDirectories.LINUX.RELEASE <<maxon_additionalLinkDirectories.LINUX.RELEASE>>)
set(maxon_additionalIncludeDirectories.LINUX <<maxon_additionalIncludeDirectories.LINUX>>)
set(maxon_prebuildEvents.LINUX.DEBUG [=[<<maxon_prebuildEvents.LINUX.DEBUG>>]=])
set(maxon_prebuildEvents.LINUX.RELEASE [=[<<maxon_prebuildEvents.LINUX.RELEASE>>]=])

# --- Compiler specific ---

# MSVC
set(maxon_additionalCompileOptions.MSVC.CPP <<maxon_additionalCompileOptions.MSVC.CPP>>)
set(maxon_additionalCompileOptions.MSVC.C <<maxon_additionalCompileOptions.MSVC.C>>)

# GCC
set(maxon_additionalCompileOptions.GNU.C <<maxon_additionalCompileOptions.GNU.C>>)
set(maxon_additionalCompileOptions.GNU.CPP <<maxon_additionalCompileOptions.GNU.CPP>>)

# Clang
set(maxon_additionalCompileOptions.CLANG.C <<maxon_additionalCompileOptions.CLANG.C>>)
set(maxon_additionalCompileOptions.CLANG.CPP <<maxon_additionalCompileOptions.CLANG.CPP>>)

# --- Linker specific ---
set(maxon_additionalLinkerOptions.MSVC.DEBUG <<maxon_additionalLinkerOptions.MSVC.DEBUG>>)
set(maxon_additionalLinkerOptions.MSVC.RELEASE <<maxon_additionalLinkerOptions.MSVC.RELEASE>>)
set(maxon_additionalLinkerOptions.CLANG.DEBUG <<maxon_additionalLinkerOptions.CLANG.DEBUG>>)
set(maxon_additionalLinkerOptions.CLANG.RELEASE <<maxon_additionalLinkerOptions.CLANG.RELEASE>>)

set(maxon_targetFrameworkDependencies ${maxon_targetFrameworkDependencies} PARENT_SCOPE) # Needed for option MAXON_FILTER_UNUSED_FRAMEWORKS to reflect on the target dependencies.

MaxonTargets_ProcessCinemaTargetVars()
