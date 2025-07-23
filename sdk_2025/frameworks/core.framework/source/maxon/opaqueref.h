#ifndef OPAQUEREF_H__
#define OPAQUEREF_H__

#include "maxon/baseref.h"
#include "maxon/defaultallocator.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

//----------------------------------------------------------------------------------------
/// Use this class to derive private classes of which the content will be hidden in the API.
/// @code
/// class MyClass : public OpaqueBase
/// {
///   ...data that only the implementation knows...
/// }
/// @endcode
/// In the API write:
/// @code
/// using OpaqueRef = MyClassRef;
/// @endcode
//----------------------------------------------------------------------------------------
class OpaqueBase
{
public:
	virtual ~OpaqueBase() {}
};

/// A strong reference to a hidden class.
using OpaqueRef = StrongRef<OpaqueBase>;

/// @}

} // namespace maxon


#endif // OPAQUEREF_H__
