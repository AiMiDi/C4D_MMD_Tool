include_guard(GLOBAL)



function(cmt_collect_dependency_libs DEPENDENCY_INSTALL_DIR OUT_DEBUG_LIBS OUT_RELEASE_LIBS OUT_MACOS_DEBUG_LIBS OUT_MACOS_RELEASE_LIBS)

  file(GLOB _ALL_LIBS "${DEPENDENCY_INSTALL_DIR}/lib/*.lib")

  set(_DEBUG_LIBS "")

  set(_RELEASE_LIBS "")

  foreach(_lib IN LISTS _ALL_LIBS)

    get_filename_component(_name "${_lib}" NAME)

    if(_name MATCHES "_Debug\\.lib$")

      list(APPEND _DEBUG_LIBS "${_name}")

    else()

      list(APPEND _RELEASE_LIBS "${_name}")

    endif()

  endforeach()

  list(SORT _DEBUG_LIBS)

  list(SORT _RELEASE_LIBS)



  file(GLOB _ALL_MACOS_LIBS "${DEPENDENCY_INSTALL_DIR}/lib/*.a")

  set(_MACOS_DEBUG_LIBS "-L${DEPENDENCY_INSTALL_DIR}/lib")

  set(_MACOS_RELEASE_LIBS "-L${DEPENDENCY_INSTALL_DIR}/lib")

  foreach(_lib IN LISTS _ALL_MACOS_LIBS)

    get_filename_component(_name "${_lib}" NAME_WE)

    string(REGEX REPLACE "^lib" "" _link_name "${_name}")

    if(_name MATCHES "_Debug$")

      list(APPEND _MACOS_DEBUG_LIBS "-l${_link_name}")

    else()

      list(APPEND _MACOS_RELEASE_LIBS "-l${_link_name}")

    endif()

  endforeach()



  set(${OUT_DEBUG_LIBS} "${_DEBUG_LIBS}" PARENT_SCOPE)

  set(${OUT_RELEASE_LIBS} "${_RELEASE_LIBS}" PARENT_SCOPE)

  set(${OUT_MACOS_DEBUG_LIBS} "${_MACOS_DEBUG_LIBS}" PARENT_SCOPE)

  set(${OUT_MACOS_RELEASE_LIBS} "${_MACOS_RELEASE_LIBS}" PARENT_SCOPE)

endfunction()



# SUBDIR mode: link library order matches BULLET_LIBRARIES in libMMD/CMakeLists.txt (BulletConfig.cmake)

macro(_cmt_link_subdir_third_party_to_plugin)

  set(_cmt_subdir_libs

    libMMD

    LinearMath

    Bullet3Common

    BulletInverseDynamics

    BulletCollision

    BulletDynamics

    BulletSoftBody

  )

  if(g_maxonTargetOS STREQUAL "WINDOWS" OR g_maxonTargetOS STREQUAL "MACOS")

    target_link_libraries(${maxon_targetName} PRIVATE ${_cmt_subdir_libs})

  endif()

endmacro()



macro(cmt_setup_mmdtool_plugin)

  set(options)

  set(oneValueArgs PROJECT_ROOT_DIR MODULE_ROOT_DIR SOURCE_ROOT RESOURCE_ROOT DEPENDENCY_INSTALL_DIR DEPENDENCY_MODE)

  set(multiValueArgs EXTRA_INCLUDE_DIRS FRAMEWORK_DEPENDENCIES REGISTER_GENERATED_FILENAMES)

  cmake_parse_arguments(CMT "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})



  if(NOT CMT_DEPENDENCY_MODE)

    set(CMT_DEPENDENCY_MODE SUBDIR)

  endif()

  # CMT_DEPS_PREBUILT_DIR overrides DEPENDENCY_MODE to avoid recompiling deps per SDK.
  if(NOT CMT_DEPS_PREBUILT_DIR STREQUAL "")
    set(CMT_DEPENDENCY_MODE PREBUILT)
  endif()

  set(_CMT_INCLUDE_DIRS ${CMT_EXTRA_INCLUDE_DIRS})

  cmake_path(ABSOLUTE_PATH CMT_PROJECT_ROOT_DIR NORMALIZE OUTPUT_VARIABLE _cmt_root)

  if(CMT_DEPENDENCY_MODE STREQUAL "PREBUILT")

    cmake_path(ABSOLUTE_PATH CMT_DEPS_PREBUILT_DIR NORMALIZE OUTPUT_VARIABLE _prebuilt)

    cmt_collect_dependency_libs(

      "${_prebuilt}"

      _DEBUG_LIBS

      _RELEASE_LIBS

      _MACOS_DEBUG_LIBS

      _MACOS_RELEASE_LIBS

    )

    set(_CMT_WIN_INCLUDES

      "${_cmt_root}/dependency/bullet3/src"

      "${_cmt_root}/dependency/libMMD/src"

      "${_cmt_root}/dependency/libMMD/external/eigen"

    )

    set(_CMT_MAC_INCLUDES ${_CMT_WIN_INCLUDES})

    set(_CMT_WIN_LINK_DIR "${_prebuilt}/lib")

    set(_CMT_WIN_LINK_DIR_DBG "${_prebuilt}/lib")

    set(_CMT_WIN_LINK_DIR_REL "${_prebuilt}/lib")

  elseif(CMT_DEPENDENCY_MODE STREQUAL "INSTALL")

    if(NOT CMT_DEPENDENCY_INSTALL_DIR)

      message(FATAL_ERROR "cmt: DEPENDENCY_INSTALL_DIR required when DEPENDENCY_MODE is INSTALL")

    endif()

    cmt_collect_dependency_libs(

      "${CMT_DEPENDENCY_INSTALL_DIR}"

      _DEBUG_LIBS

      _RELEASE_LIBS

      _MACOS_DEBUG_LIBS

      _MACOS_RELEASE_LIBS

    )

    set(_CMT_WIN_INCLUDES "${CMT_DEPENDENCY_INSTALL_DIR}/include")

    set(_CMT_MAC_INCLUDES "${CMT_DEPENDENCY_INSTALL_DIR}/include")

    set(_CMT_WIN_LINK_DIR "${CMT_DEPENDENCY_INSTALL_DIR}/lib")

    set(_CMT_WIN_LINK_DIR_DBG "${CMT_DEPENDENCY_INSTALL_DIR}/lib")

    set(_CMT_WIN_LINK_DIR_REL "${CMT_DEPENDENCY_INSTALL_DIR}/lib")

  elseif(CMT_DEPENDENCY_MODE STREQUAL "SUBDIR")

    set(_DEBUG_LIBS "")

    set(_RELEASE_LIBS "")

    set(_MACOS_DEBUG_LIBS "")

    set(_MACOS_RELEASE_LIBS "")

    set(_CMT_WIN_INCLUDES

      "${_cmt_root}/dependency/bullet3/src"

      "${_cmt_root}/dependency/libMMD/src"

      "${_cmt_root}/dependency/libMMD/external/eigen"

    )

    set(_CMT_MAC_INCLUDES ${_CMT_WIN_INCLUDES})

    set(_CMT_WIN_LINK_DIR)

    set(_CMT_WIN_LINK_DIR_DBG)

    set(_CMT_WIN_LINK_DIR_REL)

  else()

    message(FATAL_ERROR "cmt: unknown DEPENDENCY_MODE '${CMT_DEPENDENCY_MODE}' (use SUBDIR, INSTALL, or PREBUILT)")

  endif()



  MaxonTargets_CreateDirectoryLink(PATH "${CMT_MODULE_ROOT_DIR}/source" TARGET "${CMT_SOURCE_ROOT}")

  MaxonTargets_CreateDirectoryLink(PATH "${CMT_MODULE_ROOT_DIR}/res" TARGET "${CMT_RESOURCE_ROOT}")



  set(_CMT_FRAMEWORK_DEPENDENCIES

    cinema.framework

    core.framework

    image.framework

    math.framework

    nodespace.framework

  )

  if(CMT_FRAMEWORK_DEPENDENCIES)

    set(_CMT_FRAMEWORK_DEPENDENCIES ${CMT_FRAMEWORK_DEPENDENCIES})

  endif()



  set(maxon_targetName mmdtool)

  set(maxon_targetType DLL)

  set(maxon_targetFrameworkDependencies ${_CMT_FRAMEWORK_DEPENDENCIES})

  set(maxon_targetPublicCompileDefinitions USE_API_MAXON)

  set(maxon_targetPrivateCompileDefinitions MAXON_CMAKE_BUILD MAXON_MODULE_ID="net.aimidi.mmdtool")

  set(maxon_targetPlatforms Win64 OSX)

  set(maxon_targetSourceDirectories source res)

  if(CMT_REGISTER_GENERATED_FILENAMES)

    set(maxon_targetRegisterGeneratedFileNames ${CMT_REGISTER_GENERATED_FILENAMES})

  else()

    set(maxon_targetRegisterGeneratedFileNames register.cpp interface_registration.cpp)

  endif()

  set(maxon_targetTypeViewerFiles)



  # Shared dependency feature flags for all SDK plugin builds.

  set(maxon_additionalDefinitions BT_THREADSAFE=1 BT_USE_DOUBLE_PRECISION LIBMMD_STATIC=1)

  set(maxon_enableRTTI OFF)

  set(maxon_enableExceptionHandling ON)



  set(maxon_excludeFromBuild.WINDOWS)

  set(maxon_exclude.WINDOWS)

  set(maxon_additionalDefinitions.WINDOWS)

  set(maxon_linkLibraries.WINDOWS.DEBUG ${_DEBUG_LIBS})

  set(maxon_linkLibraries.WINDOWS.RELEASE ${_RELEASE_LIBS})

  set(maxon_linkLibraries.WINDOWS.ARM)

  set(maxon_additionalIncludeDirectories.WINDOWS "${_CMT_WIN_INCLUDES}" ${_CMT_INCLUDE_DIRS})

  set(maxon_additionalIncludeDirectories.WINDOWS.ARM "${_CMT_WIN_INCLUDES}" ${_CMT_INCLUDE_DIRS})

  set(maxon_additionalLinkDirectories.WINDOWS "${_CMT_WIN_LINK_DIR}")

  set(maxon_additionalLinkDirectories.WINDOWS.DEBUG "${_CMT_WIN_LINK_DIR_DBG}")

  set(maxon_additionalLinkDirectories.WINDOWS.RELEASE "${_CMT_WIN_LINK_DIR_REL}")

  set(maxon_additionalLinkDirectories.WINDOWS.ARM)

  set(maxon_additionalSourceFiles.WINDOWS)

  set(maxon_prebuildEvents.WINDOWS.DEBUG [=[]=])

  set(maxon_prebuildEvents.WINDOWS.RELEASE [=[]=])

  set(maxon_subsystem.WINDOWS WINDOWS)



  set(maxon_excludeFromBuild.MACOS)

  set(maxon_exclude.MACOS)

  set(maxon_additionalDefinitions.MACOS)

  set(maxon_linkLibraries.MACOS.DEBUG ${_MACOS_DEBUG_LIBS})

  set(maxon_linkLibraries.MACOS.RELEASE ${_MACOS_RELEASE_LIBS})

  set(maxon_additionalIncludeDirectories.MACOS "${_CMT_MAC_INCLUDES}" ${_CMT_INCLUDE_DIRS})

  set(maxon_linkFrameworks.MACOS)

  set(maxon_additionalSourceFiles.MACOS)

  set(maxon_prebuildEvents.MACOS.DEBUG [=[]=])

  set(maxon_prebuildEvents.MACOS.RELEASE [=[]=])



  set(maxon_excludeFromBuild.LINUX)

  set(maxon_exclude.LINUX)

  set(maxon_additionalDefinitions.LINUX)

  set(maxon_linkLibraries.LINUX.DEBUG)

  set(maxon_linkLibraries.LINUX.RELEASE)

  set(maxon_additionalSourceFiles.LINUX)

  set(maxon_systemIncludePaths)

  set(maxon_additionalLinkDirectories.LINUX.DEBUG)

  set(maxon_additionalLinkDirectories.LINUX.RELEASE)

  set(maxon_additionalIncludeDirectories.LINUX)

  set(maxon_prebuildEvents.LINUX.DEBUG [=[]=])

  set(maxon_prebuildEvents.LINUX.RELEASE [=[]=])



  set(maxon_additionalCompileOptions.MSVC.CPP /W4 /wd4471 /utf-8)

  set(maxon_additionalCompileOptions.MSVC.C)

  set(maxon_additionalCompileOptions.GNU.C)

  set(maxon_additionalCompileOptions.GNU.CPP)

  set(maxon_additionalCompileOptions.CLANG.C)

  set(maxon_additionalCompileOptions.CLANG.CPP)

  set(maxon_additionalLinkerOptions.MSVC.DEBUG)

  set(maxon_additionalLinkerOptions.MSVC.RELEASE)

  set(maxon_additionalLinkerOptions.CLANG.DEBUG)

  set(maxon_additionalLinkerOptions.CLANG.RELEASE)



  set(maxon_targetFrameworkDependencies ${maxon_targetFrameworkDependencies} PARENT_SCOPE)

  MaxonTargets_ProcessCinemaTargetVars()

  if(CMAKE_GENERATOR MATCHES "Visual Studio")
    set_target_properties(${maxon_targetName} PROPERTIES
      VS_DEBUGGER_COMMAND_ARGUMENTS "$<$<CONFIG:Debug>:g_additionalModulePath=$(OutDir)..>"
    )
  endif()

  if(CMT_DEPENDENCY_MODE STREQUAL "SUBDIR")

    _cmt_link_subdir_third_party_to_plugin()

  endif()

endmacro()

