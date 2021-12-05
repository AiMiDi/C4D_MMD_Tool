/*
	DON'T EDIT THIS FILE!
	It has been created and is updated automatically by the interface processor.
	It has to be included by the register.cpp file of the project in order for the automatic registration to work.
*/
#define PRIVATE_MAXON_REGISTRATION_UNIT


#ifndef PRIVATE_MAXON_REGISTRATION_FRAMEWORK
#define PRIVATE_MAXON_DEFINE_MODULE_INFO_FLAGS 
#include "maxon/register.h"
#endif


#ifdef PRIVATE_MAXON_REGISTRATION_FRAMEWORK


#else

static maxon::Id g_usedFrameworks[] = {maxon::Id("net.maxon.c4d.cinema.framework"), maxon::Id("net.maxon.command.framework"), maxon::Id("net.maxon.core.framework"), maxon::Id("net.maxon.crypt.framework"), maxon::Id("net.maxon.geom.framework"), maxon::Id("net.maxon.image.framework"), maxon::Id("net.maxon.math.framework"), maxon::Id("net.maxon.mesh_misc.framework"), maxon::Id("net.maxon.python.framework")};
static maxon::SetUsedFrameworks g_setUsedFrameworks(PRIVATE_MAXON_MODULE, g_usedFrameworks);

#endif
