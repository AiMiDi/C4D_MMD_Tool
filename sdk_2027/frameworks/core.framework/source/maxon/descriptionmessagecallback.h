#ifndef DESCRIPTIONMESSAGECALLBACK_H__
#define DESCRIPTIONMESSAGECALLBACK_H__

#include "maxon/interfacebase.h"
#include "maxon/delegate.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Implement this interface to receive the AMEmulator DescriptionMessageCallbackType callbacks
/// from C4DCoreWrapperInterface implementation.
//----------------------------------------------------------------------------------------
class DescriptionMessageCallbackInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(DescriptionMessageCallbackInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.descriptionmessagecallback", MAXON_IMPLEMENTATION_MODULE("net.maxon.kernel"));

public:

	//----------------------------------------------------------------------------------------
	/// Callback function called by a C4dCoreWrapperObject on references that implement DescriptionMessageCallbackInterface.
	/// It allows receiving commands callbacks from the attribute manager emulation code.
	/// @param[in] id									The object's id.
	/// @param[in] cmdId							The command's id.
	/// @param[in] type								Message type.
	/// @param[in] data								The legacy message data.
	/// @return												Tuple<Bool HANDLED, Bool RES_VALUE_IF_HANDLED>.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Tuple<Bool, Bool>> DescriptionMessage(const InternedId& id, const Id& cmdId, Int32 type, void* data);
};

#include "descriptionmessagecallback1.hxx"
#include "descriptionmessagecallback2.hxx"

}

#endif // DESCRIPTIONMESSAGECALLBACK_H__
