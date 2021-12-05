#ifndef GENERIC_BASEARRAY_H__
#define GENERIC_BASEARRAY_H__

#include "maxon/datatypebase.h"
#include "maxon/basearray.h"

/// @file

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

//----------------------------------------------------------------------------------------
/// A GenericBaseArray allows to operate on a BaseArray without knowing the element type
/// of the array at compile time.
///
/// This array class contains no standard subscript operator because the DataType and the index
/// must be available to access the elements. Use GenericBaseArray::GetPointer or
/// GenericBaseArray::Get to access the elements.
//----------------------------------------------------------------------------------------
class GenericBaseArray : private BaseArray<Char>
{
public:
	using ValueType = Generic;
	using Super = BaseArray<Char>;
	using Super::GetCount;
	using Super::IsEmpty;
	using Super::IsPopulated;
	using Super::GetFirst;

	GenericBaseArray()
	{
	}

	~GenericBaseArray()
	{
		DebugAssert(_cnt == 0);
	}

	GenericBaseArray(GenericBaseArray&&) = default;
	GenericBaseArray& operator =(GenericBaseArray&&) = default;

	ResultMem EnsureCapacity(const DataType& elementType, Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags);

	ResultMem SetCapacityHint(const DataType& elementType, Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags)
	{
		return EnsureCapacity(elementType, requestedCapacity, resizeFlags);
	}

	ResultMem Resize(const DataType& elementType, Int count, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::DEFAULT);

	ResultRef<Generic> Insert(const DataType& elementType, Int index);

	ResultMem Insert(const DataType& elementType, Int index, const Block<const Generic>& values);

	ResultMem Insert(const DataType& elementType, Int index, const MoveBlock<Generic>& values);

	ResultMem Erase(const DataType& elementType, Int index, Int count = 1);

	ResultMem SwapErase(const DataType& elementType, Int index, Int count = 1);

	void Reset(const DataType& elementType);

	void Flush(const DataType& elementType);

	Result<void> CopyFrom(const DataType& elementType, const GenericBaseArray& other);

	String ToString(const DataType& elementType, const FormatStatement* formatStatement) const;

	Bool IsEqual(const DataType& elementType, const GenericBaseArray& other, EQUALITY equality) const;

	UInt GetHashCode(const DataType& elementType) const;

	Generic* GetPointer()
	{
		return (Generic*)_ptr;
	}

	Generic* GetPointer(const DataType& elementType, Int index)
	{
		return (Generic*) (_ptr + elementType->GetSize() * index);
	}

	const Generic* GetPointer(const DataType& elementType, Int index) const
	{
		return (const Generic*) (_ptr + elementType->GetSize() * index);
	}

	template <typename T>
	T& Get(Int index)
	{
		return *reinterpret_cast<T*>(_ptr + SIZEOF(T) * index);
	}

	template <typename T>
	const T& Get(Int index) const
	{
		return *reinterpret_cast<const T*>(_ptr + SIZEOF(T) * index);
	}

private:
	friend class GenericBaseArrayImpl;
	friend class BaseArrayDataTypeFunctions;
};

/// @}

} // namespace maxon

#endif // GENERIC_BASEARRAY_H__
