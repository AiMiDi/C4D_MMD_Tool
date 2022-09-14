#ifndef VALUECHANGEDCALLBACK_H__
#define VALUECHANGEDCALLBACK_H__

#include "maxon/interfacebase.h"
#include "maxon/delegate.h"


#ifdef __API_INTERN__
#undef MAXON_DEPENDENCY_ENABLE
#endif

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Implement this interface to receive the AMEmulator ValueChangedCallbackType callbacks
/// from C4DCoreWrapperInterface implementation.
//----------------------------------------------------------------------------------------
class ValueChangedCallbackInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(ValueChangedCallbackInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.valuechangedcallback");

public:

	//----------------------------------------------------------------------------------------
	/// Callback function called by a C4dCoreWrapperObject on references that implement ValueChangedCallbackInterface.
	/// It allows receiving value changed callbacks from the attribute manager emulation code on DataDictionary content changes.
	/// @param[in] id									The changed data's id.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ValueChangedMessage(const InternedId& id);
};

#include "valuechangedcallback1.hxx"
#include "valuechangedcallback2.hxx"

}

#ifdef __API_INTERN__
#define MAXON_DEPENDENCY_ENABLE
#endif

#endif // VALUECHANGEDCALLBACK_H__
