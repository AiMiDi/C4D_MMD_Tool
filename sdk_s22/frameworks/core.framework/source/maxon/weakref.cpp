#include "maxon/weakref.h"
#include "maxon/weakrefservices.h"

namespace maxon
{

WeakRefBase::~WeakRefBase()
{
	WeakRefServices::RemoveWeakReference(*this);
}

WeakRefBase::WeakRefBase(WeakRefBase&& src)
{
	WeakRefServices::MoveWeakReference(*this, src);
}

WeakRefBase::WeakRefBase(const WeakRefBase& src)
{
	if (WeakRefServices::CopyWeakReference(*this, src) == false)
		DebugStop();
}

MemoryMetadataProxy::~MemoryMetadataProxy()
{
	// Unlock access upon proxy object destruction.
	if (MAXON_LIKELY(_weakRefTarget != nullptr))
		_weakRefTarget->UnlockCurrent();
}

namespace details
{
void PrivateAddWeakReference(WeakRefBase& weakRef, const void* target)
{
	if (WeakRefServices::AddWeakReference(weakRef, target) == false)
		DebugStop();
}

Bool PrivateClearAllWeakReferences(const void* obj)
{
	return WeakRefServices::ClearAllWeakReferences(obj);
}
}

} // namespace maxon
