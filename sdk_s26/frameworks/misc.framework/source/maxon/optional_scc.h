#ifndef OPTIONAL_SCC_H__
#define OPTIONAL_SCC_H__

#include "maxon/entity.h"
#include "maxon/sourcecontrol.h"

// Make source control optional for external SDK user that doesn't have perforce.module
MAXON_DEPENDENCY_WEAK("maxon/sourcecontrol.h");

#endif // OPTIONAL_SCC_H__
