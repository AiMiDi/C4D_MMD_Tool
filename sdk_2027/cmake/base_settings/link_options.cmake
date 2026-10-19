if(MAXON_LINK_OPTIONS_INCLUDED)
	return()
endif()

set(MAXON_LINK_OPTIONS_CLANGCL_MSVC
	-INCREMENTAL:NO
	-NXCOMPAT
	-ERRORREPORT:PROMPT
	-DYNAMICBASE
	-TLBID:1
	-IGNORE:4099
	-DEBUG:FULL
	-OPT:REF
	-OPT:ICF
	/pdbpagesize:32768
)

set(MAXON_LINK_OPTIONS_CLANGCL_MSVC_DEBUG
)

set(MAXON_LINK_OPTIONS_CLANGCL_MSVC_RELEASE
)

set(MAXON_DEBUG_INFO_IN_RELEASE ON)

set(MAXON_LINK_OPTIONS_LINUX_CLANG_GCC
	-fuse-ld=lld
	# Fail shared-library links on unresolved symbols instead of deferring them to dlopen() at
	# runtime (ELF linkers permit undefined symbols in shared objects by default; Windows and
	# macOS links have always been strict). Every module is symbol-self-contained: cross-module
	# MAXON API calls go through runtime-resolved method tables, never through dynamic symbol
	# imports, and system libraries are on the link line - verified across all corelibs, plugins
	# and cineware of a release artifact (zero maxon/cinema undefineds; the remaining undefineds
	# are system-provided or weak toolchain symbols, which -z defs permits). This turns staleness
	# or dependency bugs into deterministic link errors instead of flaky unit-test failures.
	-Wl,-z,defs
)

set(MAXON_LINK_OPTIONS_INCLUDED ON)
