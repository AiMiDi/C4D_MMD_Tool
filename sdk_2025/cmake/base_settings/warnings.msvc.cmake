include_guard()

set(MUTED_WARNINGS_MSVC
/wd4003
/wd4061
/wd4062
/wd4063
/wd4100 # warning C4100: 'x': unreferenced formal parameter
/wd4101 # warning C4101: 'f2': unreferenced local variable 
/wd4127 # warning C4127: conditional expression is constant
/wd4131 # warning C4131: 'function' : uses old-style declarator
/wd4191 # warning C4191: 'type cast': unsafe conversion from 'void (__cdecl *)(MATRIX_PRIVATE *,PIX_C **,PIX_C *,Int32)' to 'TYPE_apply_matrix_effect (__cdecl *)' Calling this function through the result pointer may cause your program to fail
/wd4200
/wd4201 # warning C4201: nonstandard extension used: nameless struct/union
/wd4244 # warning C4244: '*': conversion from 'A' to 'maB64', possible loss of data
/wd4245
/wd4265
/wd4266
/wd4296
/wd4305 # warning C4305: '*': truncation from 'A' to 'B'
/wd4307
/wd4324
/wd4350
/wd4351
/wd4355
/wd4365
/wd4371
/wd4458
/wd4463
/wd4464
/wd4503
/wd4514
/wd4519
/wd4530
/wd4548
/wd4571
/wd4574
/wd4577
/wd4592
/wd4611
/wd4623
/wd4625 # warning C4625: 'maxon::PrivateInitialization_141_8': copy constructor was implicitly defined as deleted
/wd4626 # warning C4626: 'maxon::PrivateSuperCallBase': assignment operator was implicitly defined as deleted
/wd4628
/wd4640
/wd4647
/wd4668
/wd4706
/wd4710
/wd4711
/wd4714
/wd4738
/wd4768
/wd4774
/wd4800 # warning C4800: Implicit conversion from 'T' to bool. Possible information loss
/wd4820
/wd4826
/wd4868
/wd4883
/wd4917
/wd4928
/wd4946
/wd4987
/wd4996
/wd5026
/wd5027
/wd5039
/wd5045
/wd5204
/wd5219 # warning C5219: implicit conversion from 'maxon::Int' to 'maxon::Float32', possible loss of data
/wd5220
/wd5246 # warning C5246: '*': the initialization of a subobject should be wrapped in braces
/wd5256 # warning C5256 '*': a non-defining declaration of an enumeration with a fixed underlying type is only permitted as a standalone declaration
/wd5262 # warning C5262: implicit fall-through occurs here; are you missing a break statement? Use [[fallthrough]] when a break statement is intentionally omitted between cases
/wd5263 # warning C5263: calling 'std::move' on a temporary object prevents copy elision
/wd5266 # warning C5266 'const' qualifier on return type has no effect
/wd5267 # warning C5267: C++20 definition of implicit assignment operator for 'X' is deprecated because it has a user-provided destructor

# /we4101 # warning C4101: 'a': unreferenced local variable                                                     ->  # causes error in 2025.0
# /we4189 # warning C4189: 'a': local variable is initialized but not referenced                                ->  # causes error in 2025.0
/we4834 # warning C4834: discarding return value of function with 'nodiscard' attribute
/we4505 # warning C4505: 'a': unreferenced local function has been removed
)
