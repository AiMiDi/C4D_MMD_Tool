// MAXON_MODULE_ID must be defined globally for the module.
// This file assumes the module just uses core.framework.

#ifdef PRIVATE_MAXON_REGISTRATION_UNIT
	#error "Wrong include hierarchy"
#endif

#define PRIVATE_MAXON_DEFINE_MODULE_INFO_FLAGS

#include "maxon/register.h"

#undef PRIVATE_MAXON_DEFINE_MODULE_INFO_FLAGS
#undef PRIVATE_MAXON_REGISTRATION_UNIT
