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

#include "_include_code_exchange.hxx"
#include "_include_cpython.hxx"
#include "_include_cpython_c4d.hxx"
#include "_include_cpython_raw.hxx"
#include "_include_cpython_ref.hxx"
#include "_include_vm.hxx"

#ifdef PRIVATE_MAXON_REGISTRATION_FRAMEWORK

#include "_reflection_code_exchange.hxx"
#include "_reflection_cpython.hxx"
#include "_reflection_cpython_c4d.hxx"
#include "_reflection_cpython_raw.hxx"
#include "_reflection_cpython_ref.hxx"
#include "_reflection_vm.hxx"

#else

MAXON_NULL_VALUE_INCOMPLETE_GET_DEFINITION;

#include "_register_code_exchange.hxx"
#include "_register_cpython.hxx"
#include "_register_cpython_c4d.hxx"
#include "_register_cpython_raw.hxx"
#include "_register_cpython_ref.hxx"
#include "_register_vm.hxx"

static maxon::Id g_usedFrameworks[] = {maxon::Id("net.maxon.core.framework")};
static maxon::SetUsedFrameworks g_setUsedFrameworks(PRIVATE_MAXON_MODULE, g_usedFrameworks);

#endif
