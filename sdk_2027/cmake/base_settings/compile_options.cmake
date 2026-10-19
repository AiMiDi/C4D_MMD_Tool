if(MAXON_COMPILE_OPTIONS_INCLUDED)
	return()
endif()

set(MAXON_COMPILE_OPTIONS_CLANGCL_MSVC
	/Z7 # Generates C 7.0-compatible debugging information.
	/vmg # Uses full generality for pointers to members.
	/vms # Declares single inheritance.
	/bigobj # Increases the number of addressable sections in an .obj file.
	/GF # Enables string pooling.
	/Gd # Uses the __cdecl calling convention. (x86 only)
	/Gw # Enables whole-program global data optimization. (enabled)
	/Gy # Enables function-level linking. (enabled)
)

set(MAXON_COMPILE_OPTIONS_CLANGCL_MSVC_DEBUG
	/GS # Checks buffer security. (enabled)
	/Ob1 # Controls inline expansion. (set to level 1)
	/Od # Disables optimization.
	/Oi # Generates intrinsic functions. (enabled), release doesn'T need this - it's part of /O2

	# The following flags are not part of bazel build
	# /FC # Displays the full path of source code files passed to cl.exe in diagnostic text.

	/JMC # Supports native C++ Just My Code debugging. enable only in debug
)

set(MAXON_COMPILE_OPTIONS_CLANGCL_MSVC_RELEASE
	/GS- # Checks buffer security. (disabled)
	/Ob2 # Controls inline expansion. (set to level 2)
)

set(MAXON_COMPILE_OPTIONS_MSVC
	/Zc:__cplusplus
	/MP # multi-threaded compilation
)

set(MAXON_COMPILE_OPTIONS_MSVC_ARM64
	  /Zc:preprocessor # Needed for core.framework/source/maxon/utilities/sseconversion_msvc.h
)

set(MAXON_COMPILE_OPTIONS_MSVC_RELEASE
	/O2 # Creates fast code.
)

# See https://support.maxon.net/hc/en-us/articles/16797414314012-System-Requirements-for-Maxon-Productss
# CMake issue: while v145 properly supports ARM ISAs this is currently lacking in v143: https://gitlab.kitware.com/cmake/cmake/-/issues/27428
set(MAXON_COMPILE_OPTIONS_WINDOWS_ARM64_MSVC_ISA /arch:armv8.1)  # in v143 does not work properly, is put into AdditionalOptions not EnableEnhancedInstructionSet
set(MAXON_COMPILE_OPTIONS_WINDOWS_X64_MSVC_ISA /arch:AVX2)
set(MAXON_COMPILE_OPTIONS_WINDOWS_ARM64_CLANGCL_ISA -march=armv8.1a)
set(MAXON_COMPILE_OPTIONS_WINDOWS_X64_CLANGCL_ISA -mavx2)
set(MAXON_COMPILE_OPTIONS_MACOS_X64_ISA -msse4.2) # SSE4.2 on macOS, because Graphisoft relies on Rosetta for testing. Note with macOS 15, Rosetta supports AVX2.
set(MAXON_COMPILE_OPTIONS_LINUX_X64_ISA
	-mavx2
	-maes
)
set(MAXON_COMPILE_OPTIONS_LINUX_ARM64_ISA -march=armv8.1-a) # gcc/clang spelling of the windows-arm64 baseline

# Determines the MS compatibility version clang reports as _MSC_VER (via
# -fms-compatibility-version). The value must reflect the MSVC toolset the build actually
# uses: the MSVC STL, third-party and product code gate on _MSC_VER to detect toolset
# capabilities (e.g. the fstream wchar_t* path constructors require _MSC_VER >= 1930), and
# a stale value silently selects wrong code paths.
# Resolution order:
# 1. An explicit -DMAXON_MS_COMPATIBILITY_VERSION=<major.minor> always wins.
# 2. With VS compiler pinning active (MAXON_ENABLE_VS_COMPILER_PINNING) the pinned toolset
#    directory (MAXON_BUILDCACHE_VS_TOOLSETS_DIRECTORY) determines the version: pinnable
#    toolset packages always carry a toolsets.json manifest; a real Visual Studio
#    installation is probed via its canonical default-version files instead. A bare LLVM
#    install dir pins no MSVC and therefore yields the default.
# 3. Without pinning, whatever CMake detected wins: CMAKE_CXX_SIMULATE_VERSION is the
#    MSVC version the clang frontend reports by default (detection runs before these
#    option lists apply). Turning pinning off means "use my latest installed compiler",
#    so the macro surface follows the compiler instead of a fixed pin.
# 4. Only when nothing can be detected (e.g. non-clang frontends, script mode) the
#    historical default 19 (VS2015 level, _MSC_VER=1900) remains.
# VC toolset 14.xx <=> cl 19.xx; the minor version has tracked identically for the whole
# 14.x (VS2015+) family, which Microsoft keeps ABI-stable on purpose.
function(MaxonCompileOptions_GetMSCompatibilityVersion resultVariable)
	if(DEFINED MAXON_MS_COMPATIBILITY_VERSION)
		set(${resultVariable} "${MAXON_MS_COMPATIBILITY_VERSION}" PARENT_SCOPE)
		return()
	endif()
	set(vcToolsetVersion "")
	if(MAXON_ENABLE_VS_COMPILER_PINNING AND MAXON_BUILDCACHE_VS_TOOLSETS_DIRECTORY)
		set(toolsetsManifest "${MAXON_BUILDCACHE_VS_TOOLSETS_DIRECTORY}/toolsets.json")
		if(EXISTS "${toolsetsManifest}")
			file(READ "${toolsetsManifest}" toolsetsContent)
			foreach(vcGeneration "v145" "v143" "v142" "v141")
				string(JSON vcToolsetVersion ERROR_VARIABLE toolsetsJsonError
					GET "${toolsetsContent}" "${vcGeneration}")
				if(NOT toolsetsJsonError)
					break()
				endif()
				set(vcToolsetVersion "")
			endforeach()
		else()
			# Same per-generation default-version files the buildcache helper's
			# VCToolsVersion override consumes, newest generation first.
			foreach(vcGeneration "v145" "v143" "v142" "v141" "")
				if(vcGeneration)
					set(defaultVersionName "Microsoft.VCToolsVersion.${vcGeneration}.default.txt")
				else()
					set(defaultVersionName "Microsoft.VCToolsVersion.default.txt")
				endif()
				set(defaultVersionFile "${MAXON_BUILDCACHE_VS_TOOLSETS_DIRECTORY}/VC/Auxiliary/Build/${defaultVersionName}")
				if(EXISTS "${defaultVersionFile}")
					file(STRINGS "${defaultVersionFile}" vcToolsetVersion LIMIT_COUNT 1)
					string(STRIP "${vcToolsetVersion}" vcToolsetVersion)
					break()
				endif()
			endforeach()
		endif()
	endif()
	if(vcToolsetVersion MATCHES "^14\\.([0-9]+)")
		set(${resultVariable} "19.${CMAKE_MATCH_1}" PARENT_SCOPE)
		message(STATUS "MS compatibility version (from pinned VC toolset ${vcToolsetVersion}): 19.${CMAKE_MATCH_1}")
	else()
		if(vcToolsetVersion)
			message(WARNING "Unrecognized VC toolset version '${vcToolsetVersion}' (expected 14.xx); "
				"falling back to the detected compiler default. Override with -DMAXON_MS_COMPATIBILITY_VERSION=<major.minor>.")
		endif()
		if(CMAKE_CXX_SIMULATE_ID STREQUAL "MSVC" AND CMAKE_CXX_SIMULATE_VERSION)
			# Unpinned: follow the MSVC version the detected clang frontend reports by default.
			set(${resultVariable} "${CMAKE_CXX_SIMULATE_VERSION}" PARENT_SCOPE)
			message(STATUS "MS compatibility version (detected compiler default): ${CMAKE_CXX_SIMULATE_VERSION}")
		else()
			set(${resultVariable} "19" PARENT_SCOPE) # historical default (VS2015, _MSC_VER=1900)
		endif()
	endif()
endfunction()

MaxonCompileOptions_GetMSCompatibilityVersion(MAXON_MS_COMPATIBILITY_VERSION)

set(MAXON_COMPILE_OPTIONS_CLANGCL
	/MP # multi-threaded compilation
	/showFilenames # Prints out the file currently being compiled, to mimic MSVCs behavior.
	-fms-compatibility-version=${MAXON_MS_COMPATIBILITY_VERSION}
	-fms-extensions
	-clang:-fstandalone-debug # fixes debugging with "a namespace is not allowed" and "identifier <class> is undefined"
	-clang:-fno-stack-protector
	-clang:-mno-stack-arg-probe # disables the __chkstk() calls after alloca()
	-clang:-fno-math-errno # disables sqrt null checks infront of sqrt intrinsics.
	-clang:-ffile-reproducible
)

set(MAXON_MSVC_DEBUG_FORMAT "ProgramDatabase") # other option is "Embedded"

set(MAXON_COMPILE_OPTIONS_CLANG
	-fms-compatibility-version=${MAXON_MS_COMPATIBILITY_VERSION}
	-faligned-allocation
)

set(MAXON_COMPILE_OPTIONS_OBJECTIVE_C
	-fobjc-arc # CLANG_ENABLE_OBJC_ARC, use Automatic Reference Counting
	-fobjc-weak # CLANG_ENABLE_OBJC_WEAK, enable weak references for code compiled with manual retain release (MRR) semantics
)

set(MAXON_COMPILE_OPTIONS_CLANG_APPLECLANG_GCC_DEBUG
	-ggdb
)

set(MAXON_COMPILE_OPTIONS_ANYCLANG_GCC
	-g
	-fno-strict-aliasing
	-fno-math-errno
	-ffp-contract=off # disable FMA for all clang compilers, this break mesh unit tests and floating point math
)

set(MAXON_COMPILE_OPTIONS_ANYCLANG_GCC_RELEASE
	-O3 # this also works correctly for ClangCL when prefixed as '/clang:-O3'
)

set(MAXON_COMPILE_OPTIONS_GCC
	-fno-delete-null-pointer-checks
	-fmessage-length=0
	-fvisibility=hidden
	-fvisibility-inlines-hidden
)

set(MAXON_COMPILE_OPTIONS_INCLUDED ON)
