/*
	DON'T EDIT THIS FILE!
	It has been created and is updated automatically by the interface processor.
	It has to be included by the register.cpp file of the project in order for the automatic registration to work.
*/
#define PRIVATE_MAXON_REGISTRATION_UNIT


#ifndef PRIVATE_MAXON_REGISTRATION_FRAMEWORK
#define PRIVATE_MAXON_DEFINE_MODULE_INFO_FLAGS | EntityBase::FLAGS::PUBLIC
#include "maxon/register.h"
#endif

#include "_include_NURBSCurve.hxx"
#include "_include_NURBSMath.hxx"
#include "_include_big_integer.hxx"
#include "_include_blend_animation.hxx"
#include "_include_blend_function.hxx"
#include "_include_complex.hxx"
#include "_include_fft.hxx"
#include "_include_gradient.hxx"
#include "_include_matrix_nxm.hxx"
#include "_include_matrix_prs.hxx"
#include "_include_noise.hxx"
#include "_include_quaternion.hxx"
#include "_include_splinemapper.hxx"

#ifdef PRIVATE_MAXON_REGISTRATION_FRAMEWORK

#include "_reflection_NURBSCurve.hxx"
#include "_reflection_NURBSMath.hxx"
#include "_reflection_big_integer.hxx"
#include "_reflection_blend_animation.hxx"
#include "_reflection_blend_function.hxx"
#include "_reflection_complex.hxx"
#include "_reflection_fft.hxx"
#include "_reflection_gradient.hxx"
#include "_reflection_matrix_nxm.hxx"
#include "_reflection_matrix_prs.hxx"
#include "_reflection_noise.hxx"
#include "_reflection_quaternion.hxx"
#include "_reflection_splinemapper.hxx"

#else

MAXON_NULL_VALUE_INCOMPLETE_GET_DEFINITION;

#include "_register_NURBSCurve.hxx"
#include "_register_NURBSMath.hxx"
#include "_register_big_integer.hxx"
#include "_register_blend_animation.hxx"
#include "_register_blend_function.hxx"
#include "_register_complex.hxx"
#include "_register_fft.hxx"
#include "_register_gradient.hxx"
#include "_register_matrix_nxm.hxx"
#include "_register_matrix_prs.hxx"
#include "_register_noise.hxx"
#include "_register_quaternion.hxx"
#include "_register_splinemapper.hxx"

static maxon::Id g_usedFrameworks[] = {maxon::Id("net.maxon.core.framework")};
static maxon::SetUsedFrameworks g_setUsedFrameworks(PRIVATE_MAXON_MODULE, g_usedFrameworks);

#endif
