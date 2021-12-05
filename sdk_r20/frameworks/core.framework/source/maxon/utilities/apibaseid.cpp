#include "maxon/apibase.h"
#include "maxon/system.h"

namespace maxon
{

RefCountedCString* RefCountedCString::Alloc(Int len)
{
	RefCountedCString* s = (RefCountedCString*) System::Alloc(1 + len, MAXON_SOURCE_LOCATION_NAME(RefCountedCString));
	return s;
}

void RefCountedCString::AddReference() const
{
	System::GetReferenceCounter(this).Inc();
}

void RefCountedCString::RemoveReference() const
{
	if (MAXON_UNLIKELY(System::GetReferenceCounter(this).Dec() == true))
		System::Free(this);
}

} // namespace maxon

