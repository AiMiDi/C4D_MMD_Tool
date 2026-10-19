include_guard()

# warnings that can be used with C and C++
set(MUTED_WARNINGS_GCC_C_CXX
-w
-Wno-multichar
-Wno-switch
-Wno-strict-aliasing
-Wno-misleading-indentation
-Werror=char-subscripts
-Werror=sequence-point
)

# warnings that can be used only with C
set(MUTED_WARNINGS_GCC_C)

# warnings that can be used only with C++
set(MUTED_WARNINGS_GCC_CXX
-w
-Wno-invalid-offsetof
-Werror=conversion-null
-Werror=reorder
)
