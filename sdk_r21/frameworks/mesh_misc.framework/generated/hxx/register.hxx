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

#include "_include_distancequery.hxx"
#include "_include_mesh_attribute_base.hxx"
#include "_include_voxelization.hxx"

#ifdef PRIVATE_MAXON_REGISTRATION_FRAMEWORK

#include "_reflection_distancequery.hxx"
#include "_reflection_mesh_attribute_base.hxx"
#include "_reflection_voxelization.hxx"

#else

MAXON_NULL_VALUE_INCOMPLETE_GET_DEFINITION;

#include "_register_distancequery.hxx"
#include "_register_mesh_attribute_base.hxx"
#include "_register_voxelization.hxx"

static maxon::Id g_usedFrameworks[] = {maxon::Id("net.maxon.core.framework")};
static maxon::SetUsedFrameworks g_setUsedFrameworks(PRIVATE_MAXON_MODULE, g_usedFrameworks);

#endif
