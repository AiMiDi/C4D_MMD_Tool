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

set(MAXON_COMPILE_OPTIONS_MSVC_RELEASE
	/O2 # Creates fast code.
)

# https://www.maxon.net/en/requirements/cinema-4d-2025-requirements
set(MAXON_COMPILE_OPTIONS_WINDOWS_MSVC_X64_ISA /arch:AVX2)
set(MAXON_COMPILE_OPTIONS_WINDOWS_CLANGCL_X64_ISA -mavx2)
set(MAXON_COMPILE_OPTIONS_WINDOWS_CLANGCL_ARM64_ISA -march=armv8.1a)
set(MAXON_COMPILE_OPTIONS_MACOS_X64_ISA -msse4.2) # SSE4.2 on macOS, because Graphisoft relies on Rosetta for testing. Note with macOS 15, Rosetta supports AVX2.
set(MAXON_COMPILE_OPTIONS_LINUX_X64_ISA -mavx2)

set(MAXON_COMPILE_OPTIONS_CLANGCL
	/MP # multi-threaded compilation
	/showFilenames # Prints out the file currently being compiled, to mimic MSVCs behavior.
	-fms-compatibility-version=19
	-fms-extensions
	-clang:-fstandalone-debug # fixes debugging with "a namespace is not allowed" and "identifier <class> is undefined"
	-clang:-fno-stack-protector
	-clang:-mno-stack-arg-probe # disables the __chkstk() calls after alloca()
	-clang:-fno-math-errno # disables sqrt null checks infront of sqrt intrinsics.
	-clang:-ffile-reproducible
)

set(MAXON_MSVC_DEBUG_FORMAT "ProgramDatabase") # other option is "Embedded"

set(MAXON_COMPILE_OPTIONS_CLANG
	-fms-compatibility-version=19
	-faligned-allocation
)

set(MAXON_COMPILE_OPTIONS_OBJECTIVE_C
	-Wno-missing-prototypes
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
