#include "maxon/mac_cfhelpers.h"
#include "maxon/defaultallocator.h"
#include "maxon/lazyinit.h"

namespace maxon
{

static void* CustomCFAlloc(CFIndex allocSize, CFOptionFlags hint, void *info)
{
	return DefaultAllocator::Alloc(Int(allocSize), MAXON_SOURCE_LOCATION);
}

static void* CustomCFRealloc(void *ptr, CFIndex newsize, CFOptionFlags hint, void *info)
{
	return DefaultAllocator::Realloc(ptr, Int(newsize), MAXON_SOURCE_LOCATION);
}

static void CustomCFDealloc(void* ptr, void* info)
{
	DefaultAllocator::Free(ptr);
}

static LazyInit g_customAllocInitOnce;

CFAllocatorRef GetCustomCFAllocator()
{
	static CFAllocatorRef deallocRef = nullptr;

	Bool res = g_customAllocInitOnce.Init(
		[]() -> Bool
		{
			CFAllocatorContext allocContext =
			{
				0,
				nullptr,
				nullptr,
				nullptr,
				nullptr,
				&CustomCFAlloc,
				&CustomCFRealloc,
				&CustomCFDealloc,
				nullptr
			};

			deallocRef = CFAllocatorCreate(kCFAllocatorDefault, &allocContext);
			return deallocRef != nullptr;
		});

	if (!res)
		return nullptr;

	return deallocRef;
}

}
