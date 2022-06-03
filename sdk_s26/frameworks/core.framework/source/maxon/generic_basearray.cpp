#include "maxon/generic_basearray.h"
#include "maxon/datatype.h"

namespace maxon
{

static Int GetByteSizeForGenericBaseArray(Int capacity, const DataType& elementType)
{
	if (MAXON_LIKELY(!(elementType->GetValueKind() & VALUEKIND::SIMD)))
		return capacity * elementType->GetSize();
	Int mask = elementType->GetSimdInfo().multiplicityMask;
	return ((capacity + mask) & ~mask) * elementType->GetSize();
}

ResultMem GenericBaseArray::EnsureCapacity(const DataType& elementType, Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags)
{
	if ((requestedCapacity == _capacity) || (requestedCapacity <= _cnt))
	{
		return OK;
	}
	else if (requestedCapacity < _capacity)
	{
		if (!(resizeFlags & COLLECTION_RESIZE_FLAGS::ON_SHRINK_FIT_TO_SIZE))
			return OK;
	}
	else
	{
		if (!(resizeFlags & COLLECTION_RESIZE_FLAGS::ON_GROW_FIT_TO_SIZE))
		{
			requestedCapacity = DefaultAllocator::ComputeArraySize(_capacity, requestedCapacity - _capacity, BASEARRAY_DEFAULT_CHUNK_SIZE);
		}
	}
	Char* mem = (Char*) DefaultAllocator::Alloc(GetByteSizeForGenericBaseArray(requestedCapacity, elementType), MAXON_SOURCE_LOCATION);
	if (!mem)
		return FAILED;
	Int sz = elementType->GetSize();
	elementType->MoveConstruct(mem, sz, _ptr, sz, _cnt);
	elementType->Destruct(_ptr, sz, _cnt);
	if (_capacity > 0)
		DeleteMem(_ptr);
	_ptr = mem;
	_capacity = requestedCapacity;
	return OK;
}

ResultRef<Generic> GenericBaseArray::Append(const DataType& elementType)
{
	Int newPosition = GetCount();
	if (Insert(elementType, newPosition, MoveBlock<ValueType>(nullptr, 1)) == FAILED)
		return nullptr;

	Generic* ptr = GetPointer(elementType, newPosition);
	elementType->Construct(ptr);

	return ptr;
}

ResultMem GenericBaseArray::Resize(const DataType& elementType, Int count, COLLECTION_RESIZE_FLAGS resizeFlags)
{
#ifdef MAXON_COMPILER_GCC // disable a warning as it seems to be a false positive
	MAXON_WARNING_PUSH // introduced by -O3; when building with -O2, the warning is not
	_Pragma("GCC diagnostic ignored \"-Wstrict-overflow\"") // emitted
#endif
	Bool fit = false;
	Int sz = elementType->GetSize();
	if (count == _cnt)
	{
		return OK;
	}
	else if (count < _cnt)
	{
		count = Max<Int>(count, 0);
		elementType->Destruct(GetPointer(elementType, count), sz, _cnt - count);
		if (resizeFlags & COLLECTION_RESIZE_FLAGS::ON_SHRINK_FIT_TO_SIZE)
		{
			fit = true;
		}
	}
	else if (count <= _capacity)
	{
		if (!(resizeFlags & COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED
					|| (resizeFlags & (COLLECTION_RESIZE_FLAGS::ON_GROW_UNSPECIFIED | COLLECTION_RESIZE_FLAGS::ON_RESIZE_UNSPECIFIED) && elementType->GetValueKind() & VALUEKIND::TRIVIALLY_CONSTRUCTIBLE)))
			elementType->Construct(GetPointer(elementType, _cnt), sz, count - _cnt);
		if ((resizeFlags & COLLECTION_RESIZE_FLAGS::ON_SHRINK_FIT_TO_SIZE) && (_capacity > count))
		{
			fit = true;
		}
	}
	else
	{
		Int totalCapacity = (resizeFlags & COLLECTION_RESIZE_FLAGS::ON_GROW_FIT_TO_SIZE) ? count : DefaultAllocator::ComputeArraySize(_capacity, count - _capacity, BASEARRAY_DEFAULT_CHUNK_SIZE);
		Char* mem = (Char*) DefaultAllocator::Alloc(GetByteSizeForGenericBaseArray(totalCapacity, elementType), MAXON_SOURCE_LOCATION);
		if (!mem)
			return FAILED;
		if (!(resizeFlags & COLLECTION_RESIZE_FLAGS::ON_RESIZE_UNSPECIFIED))
			elementType->MoveConstruct(mem, sz, _ptr, sz, _cnt);
		else if (!(elementType->GetValueKind() & VALUEKIND::TRIVIALLY_CONSTRUCTIBLE))
			elementType->Construct(mem, sz, _cnt);
		elementType->Destruct(_ptr, sz, _cnt);
		if (_capacity > 0)
			DeleteMem(_ptr);
		_ptr = mem;
		_capacity = totalCapacity;
		if (!(resizeFlags & COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED
					|| (resizeFlags & (COLLECTION_RESIZE_FLAGS::ON_GROW_UNSPECIFIED | COLLECTION_RESIZE_FLAGS::ON_RESIZE_UNSPECIFIED) && elementType->GetValueKind() & VALUEKIND::TRIVIALLY_CONSTRUCTIBLE)))
			elementType->Construct(GetPointer(elementType, _cnt), sz, count - _cnt);
	}
#ifdef MAXON_COMPILER_GCC
	MAXON_WARNING_POP
#endif

	_cnt = count;
	if (fit)
	{
		Char* mem = count ? (Char*) DefaultAllocator::Alloc(GetByteSizeForGenericBaseArray(count, elementType), MAXON_SOURCE_LOCATION) : (Char*) this;
		if (!mem)
			return OK;
		if (!(resizeFlags & COLLECTION_RESIZE_FLAGS::ON_RESIZE_UNSPECIFIED))
			elementType->MoveConstruct(mem, sz, _ptr, sz, count);
		else if (!(elementType->GetValueKind() & VALUEKIND::TRIVIALLY_CONSTRUCTIBLE))
			elementType->Construct(mem, sz, count);
		elementType->Destruct(_ptr, sz, count);
		if (_capacity > 0)
			DeleteMem(_ptr);
		_ptr = mem;
		_capacity = count;
	}
	return OK;
}

ResultRef<Generic> GenericBaseArray::Insert(const DataType& elementType, Int index)
{
	if (Insert(elementType, index, MoveBlock<ValueType>(nullptr, 1)) == FAILED)
		return nullptr;
	Generic* ptr = GetPointer(elementType, index);
	elementType->Construct(ptr);
	return ptr;
}

ResultMem GenericBaseArray::Insert(const DataType& elementType, Int index, const Block<const ValueType>& values)
{
	if (Insert(elementType, index, MoveBlock<ValueType>(nullptr, values.GetCount())) == FAILED)
		return FAILED;
	if (!values.GetFirst())
		return OK;
	Generic* ptr = GetPointer(elementType, index);
	Int sz = elementType->GetSize();
	elementType->Construct(ptr, sz, values.GetCount());
	return ResultMem(elementType->CopyFrom(ptr, sz, values.GetFirst(), sz, values.GetCount()) == OK);
}

ResultMem GenericBaseArray::Insert(const DataType& elementType, Int index, const MoveBlock<ValueType>& values)
{
	Int sz = elementType->GetSize();
	if (index == _cnt)
	{
		if (Resize(elementType, _cnt + values.GetCount(), COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY | COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) == FAILED)
			return FAILED;
	}
	else
	{
		if (Resize(elementType, _cnt + values.GetCount(), COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY) == FAILED)
			return FAILED;
		elementType->MoveFrom(GetPointer(elementType, index + values.GetCount()), sz, GetPointer(elementType, index), sz, _cnt - values.GetCount() - index);
		elementType->Destruct(GetPointer(elementType, index), sz, values.GetCount());
	}
	if (values.GetFirst())
		elementType->MoveConstruct(GetPointer(elementType, index), sz, values.GetFirst(), sz, values.GetCount());
	return OK;
}

ResultMem GenericBaseArray::Erase(const DataType& elementType, Int index, Int count)
{
	_cnt -= count;
	Int sz = elementType->GetSize();
	elementType->MoveFrom(GetPointer(elementType, index), sz, GetPointer(elementType, index + count), sz, _cnt - index);
	elementType->Destruct(GetPointer(elementType, _cnt), sz, count);
	return OK;
}

ResultMem GenericBaseArray::SwapErase(const DataType& elementType, Int index, Int count)
{
	// Move up to count elements from the end into the gap.
	Int moveStartIdx = Max<Int>(_cnt - count, index + count);
	Int sz = elementType->GetSize();
	elementType->MoveFrom(GetPointer(elementType, index), sz, GetPointer(elementType, moveStartIdx), sz, _cnt - moveStartIdx);
	_cnt -= count;
	elementType->Destruct(GetPointer(elementType, _cnt), sz, count);
	return OK;
}

void GenericBaseArray::Reset(const DataType& elementType)
{
	if (_cnt > 0)
	{
		Int sz = elementType->GetSize();
		elementType->Destruct(_ptr, sz, _cnt);
	}

	// only delete memory if _capacity > 0, as the address is set to this below
	if (_capacity > 0)
		DeleteMem(_ptr);

	_ptr = (Char*) this;
	_cnt = 0;
	_capacity = 0;
}

void GenericBaseArray::Flush(const DataType& elementType)
{
	// check for > 0 in case type was Generic and no valid destructor is present
	if (_cnt > 0)
	{
		Int sz = elementType->GetSize();
		elementType->Destruct(_ptr, sz, _cnt);
	}
	_cnt = 0;
}

Result<void> GenericBaseArray::CopyFrom(const DataType& elementType, const GenericBaseArray& other)
{
	iferr_scope;

	Resize(elementType, other._cnt, COLLECTION_RESIZE_FLAGS::ON_GROW_FIT_TO_SIZE) iferr_return;
	Int sz = elementType->GetSize();
	elementType->CopyFrom(_ptr, sz, other._ptr, sz, _cnt) iferr_return;

	return OK;
}

String GenericBaseArray::ToString(const DataType& elementType, const FormatStatement* formatStatement) const
{
	String s = "{"_s;
	const Char* ptr = _ptr;
	for (Int i = 0; i < _cnt; ++i)
	{
		if (i)
			s += ","_s;
		s += elementType->ToString(ptr, formatStatement);
		ptr += elementType->GetSize();
	}
	s += "}"_s;
	return s;
}

Bool GenericBaseArray::IsEqual(const DataType& elementType, const GenericBaseArray& other, EQUALITY equality) const
{
	if (this == &other)
		return true;
	if (_cnt != other._cnt)
		return false;
	const Char* a = _ptr;
	const Char* b = other._ptr;
	Int sz = elementType->GetSize();
	for (Int n = _cnt; n > 0; --n)
	{
		if (!elementType->IsEqual(a, b, equality))
			return false;
		a += sz;
		b += sz;
	}
	return true;
}

HashInt GenericBaseArray::GetHashCode(const DataType& elementType) const
{
	DefaultHash hash;
	const Char* ptr = _ptr;
	for (Int i = 0; i < _cnt; ++i)
	{
		hash.Combine(elementType->GetHashCode(ptr));
		ptr += elementType->GetSize();
	}
	return hash;
}

} // namespace maxon
