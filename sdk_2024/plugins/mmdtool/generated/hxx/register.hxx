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

static const maxon::LiteralId g_usedFrameworks[] = {maxon::LiteralId("net.maxon.c4d.cinema.framework"), maxon::LiteralId("net.maxon.core.framework"), maxon::LiteralId("net.maxon.image.framework"), maxon::LiteralId("net.maxon.math.framework"), maxon::LiteralId("net.maxon.mesh_misc.framework"), maxon::LiteralId("net.maxon.modeling_geom.framework")};
static const maxon::SetUsedFrameworks g_setUsedFrameworks{PRIVATE_MAXON_MODULE, g_usedFrameworks};

static maxon::TranslationUnit g_reflectionRegistrationUnit{&PRIVATE_MAXON_MODULE, "[reflection registration]", maxon::EntityBase::FLAGS::SYNTHETIC | maxon::EntityBase::FLAGS::REFLECTION_REGISTRATION};
namespace maxon { template <> EntityDefinition g_privateReflectionRegistrationDependency<>{EntityBase::TYPE::DEPENDENCY, LiteralId(".reflection"), &g_reflectionRegistrationUnit, nullptr, EntityBase::FLAGS::HIDDEN}; }

#endif
