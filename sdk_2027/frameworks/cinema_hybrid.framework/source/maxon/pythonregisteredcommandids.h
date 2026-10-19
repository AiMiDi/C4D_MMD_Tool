#ifndef PYTHONREGISTEREDCOMMANDIDS_H__
#define PYTHONREGISTEREDCOMMANDIDS_H__

#include "maxon/interfacebase.h"

namespace maxon
{
class PythonRegisteredCommandIdsInterface
{
	MAXON_INTERFACE_NONVIRTUAL(PythonRegisteredCommandIdsInterface, MAXON_REFERENCE_STATIC, "net.maxon.pythonregisteredcommandids.interface");

public:
	static MAXON_METHOD void AddCommandId(Int32 commandId);
	static MAXON_METHOD Bool ContainsCommandId(Int32 commandId);
};

#include "pythonregisteredcommandids1.hxx"
#include "pythonregisteredcommandids2.hxx"

} // namespace maxon

#endif // PYTHONREGISTEREDCOMMANDIDS_H__
