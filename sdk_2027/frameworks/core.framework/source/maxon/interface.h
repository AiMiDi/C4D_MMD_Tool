#ifndef INTERFACE_H__
#define INTERFACE_H__

#include "maxon/interfacebase.h"

// If an interface uses references, a DataType is automatically created. This requires a dependency on
// the extension system, which is added by the following #include. interfacebase.h can be included instead of
// interface.h if you don't need references, this is also done by system.h and registrybase.h.
#include "maxon/registry.h"

#endif // INTERFACE_H__
