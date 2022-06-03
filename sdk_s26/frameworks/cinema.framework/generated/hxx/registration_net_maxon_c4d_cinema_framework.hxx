// Include this file in a cpp file of a single module to add the framework registration of net.maxon.c4d.cinema.framework to the module.

#define PRIVATE_MAXON_REGISTRATION_FRAMEWORK
#if !(defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION) && defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL))
#include "maxon/reflection_registration.h"
#else
#include "maxon/apibase.h"
#endif
#undef MAXON_DEPENDENCY_ENABLE
#include "register.hxx"
