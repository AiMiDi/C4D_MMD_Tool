#ifndef GETEXTRADATACALLBACK_H__
#define GETEXTRADATACALLBACK_H__

#include "maxon/interfacebase.h"
#include "maxon/delegate.h"


#ifdef __API_INTERN__
#undef MAXON_DEPENDENCY_ENABLE
#endif

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Implement this interface to receive the AMEmulator GetExtraDataCallbackType callbacks
/// from C4DCoreWrapperInterface implementation.
//----------------------------------------------------------------------------------------
class GetExtraDataCallbackInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(GetExtraDataCallbackInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.getextradatacallback");

public:

	//----------------------------------------------------------------------------------------
	/// Callback function called by a C4dCoreWrapperObject on references that implement GetExtraDataCallbackInterface.
	/// It allows processing extra data requests like ToUuidMessage or ToObjectMessage.
	/// @param[in] cmdId							The extra data request command.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DelegateBase> GetExtraDataMessage(const Id& cmdId);
};

#include "getextradatacallback1.hxx"
#include "getextradatacallback2.hxx"

}

#ifdef __API_INTERN__
#define MAXON_DEPENDENCY_ENABLE
#endif

#endif // GETEXTRADATACALLBACK_H__
