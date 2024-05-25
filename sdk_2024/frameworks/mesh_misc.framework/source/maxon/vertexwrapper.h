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

template <typename TYPE>
class PrivateVertexWrapper
{
public:
	using ValueType = TYPE;

	PrivateVertexWrapper()
	{
		ClearMemType(&_data[0], sizeof(ValueType), 0);
		_multiple = false;
	}

	~PrivateVertexWrapper()
	{
		void* ptr = GetPointer();
		if (MAXON_UNLIKELY(ptr))
		{
			DeleteMem(ptr);
		}
		_multiple = false;
	}

	//----------------------------------------------------------------------------------------
	/// Copies the data from another object.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(const PrivateVertexWrapper<ValueType>& src)
	{
		iferr_scope;

		// check if a pointer was set and delete memory
		void* ptr = GetPointer();
		void* srcPtr = src.GetPointer();
		if (src.IsMultipleValue())
		{
			UInt32 count = *static_cast<UInt32*>(srcPtr);
			// calculate the number of elements and memory
			Int memorySize = CalculateMultipleValuesVertexListSize(count, sizeof(ValueType));

			// delete old memory and recreate new one if we cannot reuse it
			if (!ptr || !IsMultipleValue() || count != *static_cast<UInt32*>(ptr))
			{
				// delete old memory, as it is not usable anymore
				DeleteMem(ptr);

				// allocate new memory for multiple values
				ptr = NewMem(UChar, memorySize) iferr_return;

				// set the multiple value pointer bit
				*((Int*)&_data[0]) = (Int)ptr;
			}

			// copy over memory so that the data is identical
			MemCopy(ptr, srcPtr, memorySize);
			_multiple = true;
		}
		else
		{
			MemCopyType((ValueType*)GetDataPointer(), (ValueType*)src.GetDataPointer(), 1);
			_multiple = false;
		}

		return OK;
	}

	Bool IsSingleValue() const
	{
		return !_multiple;
	}

	Bool IsMultipleValue() const
	{
		return _multiple;
	}

	Bool operator ==(const PrivateVertexWrapper<ValueType>& dst) const
	{
		const DataType& dataType = GetDataType<ValueType>();
		if (dataType)
		{
			return dataType->IsEqual(GetDataPointer(), dst.GetDataPointer(), EQUALITY::DEEP);
		}

		return false;
	}

	Bool operator <(const PrivateVertexWrapper<ValueType>& dst) const
	{
		const DataType& dataType = GetDataType<ValueType>();
		if (dataType)
		{
			COMPARERESULT res = dataType->Compare(GetDataPointer(), dst.GetDataPointer());
			return res == COMPARERESULT::LESS;
		}

		return false;
	}

	Bool operator >(const PrivateVertexWrapper<ValueType>& dst) const
	{
		const DataType& dataType = GetDataType<ValueType>();
		if (dataType)
		{
			COMPARERESULT res = dataType->Compare(GetDataPointer(), dst.GetDataPointer());
			return res == COMPARERESULT::GREATER;
		}

		return false;
	}

	HashInt GetHashCode() const
	{
		const DataType& dataType = GetDataType<ValueType>();
		if (MAXON_UNLIKELY(!dataType))
			return 0;

		void* dataPointer = GetDataPointer();
		if (IsMultipleValue())
		{
			UInt32 count = *static_cast<UInt32*>(dataPointer);
			Block<UInt32> polyIndices = Block<UInt32>(static_cast<UInt32*>(dataPointer) + 1, count);
			Block<ValueType> data = Block<ValueType>(reinterpret_cast<ValueType*>(static_cast<UInt32*>(dataPointer) + (count + 1)), count);
			return  polyIndices.GetHashCode() + 31 * data.GetHashCode();
		}

		return dataType->GetHashCode(dataPointer);
	}

protected:

	void MoveContent(PrivateVertexWrapper<ValueType>&& src)
	{
		void* ptr = GetPointer();
		DeleteMem(ptr);

		MemCopy(&_data[0], &src._data[0], sizeof(ValueType));
		_multiple = src._multiple;

		ClearMemType(&src._data[0], sizeof(ValueType), 0);
		src._multiple = false;
	}

	/// Returns the stored pointer - or a nullptr if the pointer bit was not set.
	inline void* GetPointer() const
	{
		if (MAXON_UNLIKELY(_multiple))
		{
			Int ptr = *((Int*)&_data[0]);
			return (void*)ptr;
		}
		return nullptr;
	}

	inline void* GetDataPointer() const
	{
		if (MAXON_UNLIKELY(_multiple))
		{
			Int ptr = *((Int*)&_data[0]);
			return (void*)ptr;
		}

		return (void*)&_data[0];
	}

	template <typename FN>
	String ToStringHelper(FN&& toStringValue) const
	{
    void* ptr = GetDataPointer();
		if (IsMultipleValue())
		{
			UInt32* multiplePtr = (UInt32*)ptr;
			UInt32 count = *multiplePtr;

			multiplePtr++;

			ValueType* valueStart = (ValueType*)(multiplePtr + count);
			String output;
			UInt32 lastValueIndex = 0;
			for (UInt32 valueIndex = 0; valueIndex < count; valueIndex++)
			{
				static const UInt32 HIGHBIT_TOSTRINGHELPER = UInt32(1 << 31);
				Bool isJoined = valueIndex > 0 && (multiplePtr[valueIndex] & HIGHBIT_TOSTRINGHELPER) != 0;
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
			return toStringValue(*static_cast<const ValueType*>(ptr));
		}

		return ""_s;
	}

private:


	UChar _data[sizeof(ValueType)];
	Bool _multiple = false;
};

} // namespace details

} // namespace maxon

#endif // VERTEXWRAPPER_H__
