#ifndef STACKBUFFERALLOCATOR_H__
#define STACKBUFFERALLOCATOR_H__

#include "maxon/defaultallocator.h"

namespace maxon
{

// #define MAXON_DEBUG_STACKBUFFERALLOCATOR // We can't enable this just for debug builds, because then the layout of StackBufferAllocator differs from release builds which prohibits mixed builds

//----------------------------------------------------------------------------------------
/// A StackBufferAllocator can be used if a large number of allocations shall be done in the
/// sequel, and either all of those allocations will be freed together at a later point,
/// or they will be freed in reverse order (LIFO). If all allocations will be freed together,
/// set the LIFO template parameter to false, then there is practically no memory overhead
/// for each allocation. For a de-allocation in reverse order, set LIFO to true. Then
/// a structure of the size of two Ints has to be added for each allocation for bookkeeping purposes.
///
/// @tparam BLOCK_SIZE						Minimum size of each memory block which is obtained from ALLOCATOR.
/// @tparam LIFO									Use true if you want to use this allocator in a stack-like LIFO way. This adds some overhead.
/// 															If set to false, no actual de-allocation will happen until all allocations have been freed.
/// @tparam ALLOCATOR							The parent allocator from which this allocator shall obtain its memory.
//----------------------------------------------------------------------------------------
template <Int BLOCK_SIZE, Bool LIFO, typename ALLOCATOR = DefaultAllocator> class StackBufferAllocator
{
private:
	struct Header
	{
		Int index;
		Char* pointer;
#ifdef MAXON_DEBUG_STACKBUFFERALLOCATOR
		void* result;
#endif
	};

public:
	StackBufferAllocator() : _end(nullptr), _allocCount(0)
	{
		_header.index = -1;
		_header.pointer = nullptr;
	}

	void* Alloc(Int size, MAXON_SOURCE_LOCATION_DECLARATION)
	{
		Int align = (size >= 16) ? (size >= 64 ? 64 : ((size >= 32) ? 32 : 16)) : ((size >= 8) ? 8 : alignof(void*));
		Int index = _header.index;
		Char* base = _header.pointer;
		Char* end = _end;
		Char* p;
		while (true)
		{
			p = Align(base + (LIFO ? SIZEOF(Header) : 0), align);
			if (MAXON_LIKELY(p + size <= end))
				break;
			++index;
			if (MAXON_UNLIKELY(index == _memory.GetCount()))
			{
				Int sz = Max<Int>(BLOCK_SIZE, size + align + SIZEOF(Int));
				Char* mem = (Char*) _allocator.Alloc(sz, MAXON_SOURCE_LOCATION_FORWARD);
				if (MAXON_UNLIKELY(!mem) || MAXON_UNLIKELY(_memory.Append(mem) == FAILED))
				{
					if (mem)
						_allocator.Free(mem);
					return nullptr;
				}
				base = mem + SIZEOF(Int);
				*((Int*) mem) = sz;
				end = mem + sz;
			}
			else
			{
				base = _memory[index];
				end = base + *((Int*) base);
				base += SIZEOF(Int);
			}
		}
		if (LIFO)
		{
			((Header*) p)[-1] = _header;
		}
		_header.index = index;
		_header.pointer = p + size;
#ifdef MAXON_DEBUG_STACKBUFFERALLOCATOR
		_header.result = p;
#endif
		_end = end;
		++_allocCount;
		return p;
	}

	void Free(const void* ptr)
	{
		if (!ptr)
			return;
		--_allocCount;
		if (LIFO)
		{
#ifdef MAXON_DEBUG_STACKBUFFERALLOCATOR
			DebugAssert(_header.result == ptr);
#endif
			Int i = _header.index;
			_header = ((const Header*) ptr)[-1];
			if (MAXON_UNLIKELY(_header.index != i))
			{
				if (_allocCount == 0)
				{
					DebugAssert(_header.index == -1);
					_end = nullptr;
				}
				else
				{
					Char* m = _memory[_header.index];
					_end = m + *((Int*) m);
				}
			}
		}
		else if (MAXON_UNLIKELY(_allocCount == 0))
		{
			_header.index = -1;
			_header.pointer = nullptr;
			_end = nullptr;
		}
	}

	~StackBufferAllocator()
	{
		CriticalAssert(_allocCount == 0);
		if (_allocCount == 0)
		{
			for (Char* ptr : _memory)
			{
				_allocator.Free(ptr);
			}
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns if a memory block allocated via this allocator can be reallocated or freed by the DefaultAllocator.
	/// @return												Always false.
	//----------------------------------------------------------------------------------------
	static Bool IsCompatibleWithDefaultAllocator(void*)
	{
		return false;
	}

private:
	ALLOCATOR _allocator;
	BaseArray<Char*> _memory;
	Header _header;
	Char* _end;
	Int _allocCount;
};

}

#endif // STACKBUFFERALLOCATOR_H__
