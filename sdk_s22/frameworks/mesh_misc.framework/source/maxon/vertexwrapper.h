#ifndef VERTEXWRAPPER_H__
#define VERTEXWRAPPER_H__

#include "maxon/apibase.h"

// PRIVATE
namespace maxon
{

namespace details
{

template <typename TYPE> class PrivateVertexWrapper
{
public:
	using ValueType = TYPE;

	PrivateVertexWrapper()
	{
		ClearMemType(this, 1, 0);
		*((Int*)this) = 0;
	}

	~PrivateVertexWrapper()
	{
		void* ptr = GetPointer();
		DeleteMem(ptr);

		*((Int*)this) = 0;
	}

	Result<void> CopyFrom(const PrivateVertexWrapper<TYPE>& src)
	{
		iferr_scope;

		void* ptr = GetPointer();
		DeleteMem(ptr);

		void* srcPtr = src.GetPointer();
		if (srcPtr)
		{
			UInt32 count = *((UInt32*)srcPtr);
			Int memorySize = (count + 1) * SIZEOF(UInt32) + count * sizeof(TYPE);

			ptr = NewMem(UChar, memorySize) iferr_return;

			*((Int*)this) = (Int)ptr | 1;

			MemCopy(ptr, srcPtr, memorySize);
		}
		else
		{
			MemCopyType(this, &src, 1);
			*((Int*)this) &= ~1;
		}

		return OK;
	}

	Bool operator ==(const PrivateVertexWrapper<TYPE>& dst) const
	{
		const DataType& dataType = GetDataType<TYPE>();
		if (dataType)
			return dataType->IsEqual(this, &dst, EQUALITY::DEEP);

		return false;
	}

	UInt GetHashCode() const
	{
		CriticalStop();
		return 0;
	}

protected:
	void MoveContent(void* src)
	{
		MemCopy(this, src, sizeof(TYPE));

		ClearMem(src, sizeof(TYPE));
	}

private:

	inline void* GetPointer() const
	{
		Int ptr = *((Int*)this);
		return (ptr & 1) ? (void*)(ptr & ~1) : nullptr;
	}

	UChar _value[sizeof(TYPE)];
};

} // namespace details

} // namespace maxon

#endif // VERTEXWRAPPER_H__
