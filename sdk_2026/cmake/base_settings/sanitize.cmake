if(MAXON_SANITIZE_OPTIONS_INCLUDED)
	return()
endif()

# MSBuild currently only supports sanitization builds in release mode. as per https://devblogs.microsoft.com/cppblog/addresssanitizer-asan-for-windows-with-msvc/cm
set(SANITIZE_RELEASE_COMPILE_OPTS
	-fsanitize=address
)

set(SANITIZE_RELEASE_COMPILE_OPTS_ANYCLANG
	-fno-omit-frame-pointer
	-fno-common
)

set(SANITIZE_RELEASE_COMPILE_DEFINES
	_DISABLE_VECTOR_ANNOTATION
	_DISABLE_STRING_ANNOTATION
	MAXON_TARGET_SANITIZE
	MAXON_TARGET_64BIT
)

set(SANITIZE_RELEASE_LINK_OPTS_CLANG_APPLECLANG
	-fsanitize=address
)

set(MAXON_SANITIZE_OPTIONS_INCLUDED ON)