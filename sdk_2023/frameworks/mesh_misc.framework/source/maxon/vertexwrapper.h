#ifndef VERTEXWRAPPER_H__
#define VERTEXWRAPPER_H__

#include "maxon/apibase.h"

// PRIVATE
namespace maxon
{

namespace details
{

inline Int CalculateMultipleValuesVertexListSize(Int elements, Int elementSize)
{
	return (elements + 1) * SIZEOF(UInt32) + elements * elementSize;
}

inline Result<void> AllocVertex(const DataType& dataType, void* data)
{
	void* newMem = maxon::DefaultAllocator::Alloc(dataType->GetSize(), MAXON_SOURCE_LOCATION);
	if (!newMem)
		return OutOfMemoryError(MAXON_SOURCE_LOCATION, "could not allocate memory for a mesh map value"_s);
	dataType->Construct(newMem);
	*((Int*)data) = (Int)newMem;

	return OK;
}

template <typename TYPE> class PrivateVertexWrapper
{
public:
	using ValueType = TYPE;

	PrivateVertexWrapper()
	{
	}

	~PrivateVertexWrapper()
	{
		// check if a pointer was set and free it
		void* ptr = GetPointer();
		DeleteMem(ptr);
		_value = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Copies the data from another object.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(const PrivateVertexWrapper<TYPE>& src)
	{
		iferr_scope;

		// check if a pointer was set and delete memory
		void* ptr = GetPointer();
		void* srcPtr = src.GetPointer();
		if (src.IsMultipleValue())
		{
			UInt32 count = *((UInt32*)srcPtr);
			// calculate the number of elements and memory
			Int memorySize = CalculateMultipleValuesVertexListSize(count, sizeof(TYPE));

			// delete old memory and recreate new one if we cannot reuse it
			if (!ptr || !IsMultipleValue() || count != *((UInt32*)ptr))
			{
				// delete old memory, as it is not usable anymore
				DeleteMem(ptr);

				// allocate new memory for multiple values
				ptr = NewMem(UChar, memorySize) iferr_return;

				// set the multiple value pointer bit
				_value = (void*)((Int)ptr | 1);
			}

			// copy over memory so that the data is identical
			MemCopy(ptr, srcPtr, memorySize);
		}
		else
		{
			if (!ptr || IsMultipleValue())
			{
				DeleteMem(ptr);
				AllocVertex(GetDataType<TYPE>(), &_value) iferr_return;
			}

			// copy over data; src does not need to be cleared as no pointer bit is set
			MemCopyType((TYPE*)_value, (TYPE*)srcPtr, 1);
		}

		return OK;
	}

	Bool IsSingleValue() const
	{
		return !IsMultipleValue();
	}

	Bool IsMultipleValue() const
	{
		return (Int)_value & 1;
	}

	Bool operator ==(const PrivateVertexWrapper<TYPE>& dst) const
	{
		const DataType& dataType = GetDataType<TYPE>();
		if (dataType)
			return dataType->IsEqual(GetPointer(), dst.GetPointer(), EQUALITY::DEEP);

		return false;
	}

	Bool operator <(const PrivateVertexWrapper<TYPE>& dst) const
	{
		const DataType& dataType = GetDataType<TYPE>();
		if (dataType)
		{
			COMPARERESULT res = dataType->Compare(GetPointer(), dst.GetPointer());
			return res == COMPARERESULT::LESS;
		}

		return false;
	}

	Bool operator >(const PrivateVertexWrapper<TYPE>& dst) const
	{
		const DataType& dataType = GetDataType<TYPE>();
		if (dataType)
		{
			COMPARERESULT res = dataType->Compare(GetPointer(), dst.GetPointer());
			return res == COMPARERESULT::GREATER;
		}

		return false;
	}

	HashInt GetHashCode() const
	{
		const DataType& dataType = GetDataType<TYPE>();
		if (MAXON_UNLIKELY(!dataType))
			return 0;

		void* dataPointer = GetPointer();

		if (IsMultipleValue())
		{
			UInt32 count = *((UInt32*)dataPointer);
			Block<UInt32> polyIndices = Block<UInt32>(((UInt32*)dataPointer) + 1, count);
			Block<TYPE> data = Block<TYPE>((TYPE*)(((UInt32*)dataPointer) + (count + 1)), count);
			return  polyIndices.GetHashCode() + 31 * data.GetHashCode();
		}

		return dataType->GetHashCode(dataPointer);
	}


protected:
	void MoveContent(PrivateVertexWrapper<TYPE>&& src)
	{
#if 0
		void* location = (void*)(*(Int*)src);
		*(Int*)src = (Int)ClearMultipleBit(_value);
		_value = location;
#endif
		void* ptr = GetPointer();
		DeleteMem(ptr);
		_value = src._value;
		src._value = nullptr;
	}

	/// Returns the stored pointer - or a nullptr if the pointer bit was not set.
	inline void* GetPointer() const
	{
		return ClearMultipleBit(_value);
	}

	template <typename FN>
	String ToStringHelper(FN&& toStringValue) const
	{
		void* ptr = GetPointer();
		if (IsMultipleValue())
		{
			UInt32* multiplePtr = (UInt32*)ptr;
			UInt32 count = *multiplePtr;

			multiplePtr++;

			TYPE* valueStart = (TYPE*)(multiplePtr + count);
			String output;
			UInt32 lastValueIndex = 0;
			for (UInt32 valueIndex = 0; valueIndex < count; valueIndex++)
			{
				static const UInt32 HIGHBIT = UInt32(1 << 31);
				Bool isJoined = valueIndex > 0 && (multiplePtr[valueIndex] & HIGHBIT) != 0;
				if (!isJoined)
					lastValueIndex = valueIndex;

				output += FormatString("\n  - [@{2'0'}]: p@{3'0'} (joined: @): @",
															 valueIndex,
															 multiplePtr[valueIndex],
															 isJoined ? "Y" : "N",
															 toStringValue(valueStart[lastValueIndex]));
			}
			return output;
		}
		else
		{
			return toStringValue(*((const TYPE*)ptr));
		}

		return ""_s;
	}
private:

	void* ClearMultipleBit(void* ptr) const
	{
		return (void*)((Int)ptr & ~1);
	}

	void* _value = nullptr;	// the reserved space for datatype TYPE
};

} // namespace details

} // namespace maxon

#endif // VERTEXWRAPPER_H__
