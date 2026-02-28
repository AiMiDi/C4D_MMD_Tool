# Custom CMakeLists.txt for mmdtool plugin.
# When this file exists, the build system uses it directly and does NOT parse projectdefinition.txt.
# See: sdk_library_template.cmake and sdk_update_projects.cmake (MaxonUpdateProjects_Execute)

include(${MAXON_TOOLING_DIR}/sdk_targets.cmake)
include(${MAXON_TOOLING_DIR}/sdk_compiler_helper.cmake)

# Project root (F:/code/C4DSDK/C4D_MMDTool/)
set(PROJECT_ROOT_DIR ${MAXON_SDK_ROOT_DIR}/..)
# Module root (sdk_2026/plugins/mmdtool/)
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH MODULE_ROOT_DIR)

# Dependency install root (built by init.bat)
set(DEPENDENCY_INSTALL_DIR ${PROJECT_ROOT_DIR}/dependency/install)

# Create directory junctions so source files appear under the module root.
# This is required because source_group(TREE) in sdk_targets.cmake needs all files
# to be under the module root directory. Junctions are idempotent (re-created only if target changes).
MaxonTargets_CreateDirectoryLink(PATH ${MODULE_ROOT_DIR}/source TARGET ${PROJECT_ROOT_DIR}/refactoring)
MaxonTargets_CreateDirectoryLink(PATH ${MODULE_ROOT_DIR}/res    TARGET ${PROJECT_ROOT_DIR}/res/S24_up)

# Auto-collect dependency libraries from install directory.
# Convention: Debug libs have "_Debug" suffix (set by CMAKE_DEBUG_POSTFIX in init.bat).
file(GLOB _ALL_LIBS "${DEPENDENCY_INSTALL_DIR}/lib/*.lib")
set(_DEBUG_LIBS "")
set(_RELEASE_LIBS "")
foreach(_lib IN LISTS _ALL_LIBS)
  get_filename_component(_name ${_lib} NAME)
  if(_name MATCHES "_Debug\\.lib$")
    list(APPEND _DEBUG_LIBS ${_name})
  else()
    list(APPEND _RELEASE_LIBS ${_name})
  endif()
endforeach()
list(SORT _DEBUG_LIBS)
list(SORT _RELEASE_LIBS)

# Variables
#########################
# --- general ---
set(maxon_targetName mmdtool)
set(maxon_targetType DLL)
set(maxon_targetFrameworkDependencies
  cinema.framework
  core.framework
  image.framework
  math.framework
  nodespace.framework
)
set(maxon_targetPublicCompileDefinitions USE_API_MAXON)
set(maxon_targetPrivateCompileDefinitions MAXON_CMAKE_BUILD MAXON_MODULE_ID="net.aimidi.mmdtool")
set(maxon_targetPlatforms Win64 OSX)

# Standard source directories (resolved via junctions created above).
set(maxon_targetSourceDirectories source res)

set(maxon_targetRegisterGeneratedFileNames register.cpp interface_registration.cpp)
set(maxon_targetTypeViewerFiles )
# Third-party library configuration:
#   BT_THREADSAFE=1         - Bullet Physics thread safety
#   BT_USE_DOUBLE_PRECISION - Bullet Physics double precision (matches MMD coordinate system)
#   LIBMMD_STATIC=1         - libMMD is statically linked
set(maxon_additionalDefinitions BT_THREADSAFE=1 BT_USE_DOUBLE_PRECISION LIBMMD_STATIC=1)
set(maxon_enableRTTI OFF)
set(maxon_enableExceptionHandling ON)

# --- WINDOWS specific ---
set(maxon_excludeFromBuild.WINDOWS )
set(maxon_exclude.WINDOWS )
set(maxon_additionalDefinitions.WINDOWS )

set(maxon_linkLibraries.WINDOWS.DEBUG ${_DEBUG_LIBS})
set(maxon_linkLibraries.WINDOWS.RELEASE ${_RELEASE_LIBS})
set(maxon_linkLibraries.WINDOWS.ARM )

set(maxon_additionalIncludeDirectories.WINDOWS ${DEPENDENCY_INSTALL_DIR}/include)
set(maxon_additionalIncludeDirectories.WINDOWS.ARM ${DEPENDENCY_INSTALL_DIR}/include)

set(maxon_additionalLinkDirectories.WINDOWS ${DEPENDENCY_INSTALL_DIR}/lib)
set(maxon_additionalLinkDirectories.WINDOWS.DEBUG ${maxon_additionalLinkDirectories.WINDOWS})
set(maxon_additionalLinkDirectories.WINDOWS.RELEASE ${maxon_additionalLinkDirectories.WINDOWS})
set(maxon_additionalLinkDirectories.WINDOWS.ARM )

set(maxon_additionalSourceFiles.WINDOWS )
set(maxon_prebuildEvents.WINDOWS.DEBUG [=[]=])
set(maxon_prebuildEvents.WINDOWS.RELEASE [=[]=])
set(maxon_subsystem.WINDOWS WINDOWS)

# --- MACOS specific ---
set(maxon_excludeFromBuild.MACOS )
set(maxon_exclude.MACOS )
set(maxon_additionalDefinitions.MACOS )
# Auto-collect macOS static libraries (.a)
file(GLOB _ALL_MACOS_LIBS "${DEPENDENCY_INSTALL_DIR}/lib/*.a")
set(_MACOS_DEBUG_LIBS -L${DEPENDENCY_INSTALL_DIR}/lib)
set(_MACOS_RELEASE_LIBS -L${DEPENDENCY_INSTALL_DIR}/lib)
foreach(_lib IN LISTS _ALL_MACOS_LIBS)
  get_filename_component(_name ${_lib} NAME_WE)        # e.g. "liblibMMD_Debug"
  string(REGEX REPLACE "^lib" "" _link_name ${_name})   # e.g. "libMMD_Debug"
  if(_name MATCHES "_Debug$")
    list(APPEND _MACOS_DEBUG_LIBS -l${_link_name})
  else()
    list(APPEND _MACOS_RELEASE_LIBS -l${_link_name})
  endif()
endforeach()
set(maxon_linkLibraries.MACOS.DEBUG ${_MACOS_DEBUG_LIBS})
set(maxon_linkLibraries.MACOS.RELEASE ${_MACOS_RELEASE_LIBS})
set(maxon_additionalIncludeDirectories.MACOS ${DEPENDENCY_INSTALL_DIR}/include)
set(maxon_linkFrameworks.MACOS )
set(maxon_additionalSourceFiles.MACOS )
set(maxon_prebuildEvents.MACOS.DEBUG [=[]=])
set(maxon_prebuildEvents.MACOS.RELEASE [=[]=])

# --- LINUX specific ---
set(maxon_excludeFromBuild.LINUX )
set(maxon_exclude.LINUX )
set(maxon_additionalDefinitions.LINUX )
set(maxon_linkLibraries.LINUX.DEBUG )
set(maxon_linkLibraries.LINUX.RELEASE )
set(maxon_additionalSourceFiles.LINUX )
set(maxon_systemIncludePaths )
set(maxon_additionalLinkDirectories.LINUX.DEBUG )
set(maxon_additionalLinkDirectories.LINUX.RELEASE )
set(maxon_additionalIncludeDirectories.LINUX )
set(maxon_prebuildEvents.LINUX.DEBUG [=[]=])
set(maxon_prebuildEvents.LINUX.RELEASE [=[]=])

# --- Compiler specific ---

# MSVC
# Override SDK's /Wall with /W4 (high but practical warning level).
# SDK adds /Wall with BEFORE, so /W4 here takes precedence as it appears later on the command line.
# /wd4471: suppress "forward declaration of unscoped enum must have underlying type" - our shared
#          description headers use anonymous enums (enum { ... }) for backward compat with SDK 2025.
# /utf-8:  treat source files as UTF-8 (description headers contain Chinese comments).
set(maxon_additionalCompileOptions.MSVC.CPP /W4 /wd4471 /utf-8)
set(maxon_additionalCompileOptions.MSVC.C )

# GCC
set(maxon_additionalCompileOptions.GNU.C )
set(maxon_additionalCompileOptions.GNU.CPP )

# Clang
set(maxon_additionalCompileOptions.CLANG.C )
set(maxon_additionalCompileOptions.CLANG.CPP )

# --- Linker specific ---
set(maxon_additionalLinkerOptions.MSVC.DEBUG )
set(maxon_additionalLinkerOptions.MSVC.RELEASE )
set(maxon_additionalLinkerOptions.CLANG.DEBUG )
set(maxon_additionalLinkerOptions.CLANG.RELEASE )

set(maxon_targetFrameworkDependencies ${maxon_targetFrameworkDependencies} PARENT_SCOPE)

MaxonTargets_ProcessCinemaTargetVars()
