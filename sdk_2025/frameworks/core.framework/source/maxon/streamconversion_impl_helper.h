#ifndef STREAMCONVERSION_IMPL_HELPER_H__
#define STREAMCONVERSION_IMPL_HELPER_H__

#include "maxon/streamconversion.h"



namespace maxon
{

static const Int DEFAULT_APPENDSIZE = 1024;

//----------------------------------------------------------------------------------------
/// Helper to Append efficiently to WritableArrayInterface<> by caching several append calls and writing them back in blocks
/// Without this caching mechanism calling Append directly can slow down by a factor of 4 or even more!
/// Usage:
/** @code
	FastArrayAppend<UChar> dst(xdst); // xdst is the WritableArrayInterface of type UChar
	for (auto ch : src)
	{
		iferr (dst.Append(ch))
			return err;
	}
	iferr (dst.Finalize()) // tell the FastArrayAppend that we are finished and remaning elements in the cache should be copied as well
		return err;
@endcode */
//----------------------------------------------------------------------------------------
template <typename T> class ArrayAppendCache
{
public:
	MAXON_IMPLICIT ArrayAppendCache(WritableArrayInterface<Generic>& destination)
	{
		_tempPos     = 0;
		WritableArrayInterface<T>& dstX = reinterpret_cast<WritableArrayInterface<T>&>(destination);
		_destination = &dstX;
	}

	ArrayAppendCache()
	{
		DebugAssert(_tempPos == 0);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Result<void> Append(const T& ch)
	{
		DebugAssert(_destination);

		_tempArray[_tempPos++] = ch;

		if (MAXON_UNLIKELY(_tempPos >= DEFAULT_APPENDSIZE))
		{
			iferr (_destination->Insert(_destination->GetCount(), ToBlock(& _tempArray[0], _tempPos)))
				return err;
			_tempPos = 0;
		}
		return OK;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Result<void> Finalize()
	{
		DebugAssert(_destination);

		if (_tempPos > 0)
		{
			iferr (_destination->Insert(_destination->GetCount(), ToBlock(&_tempArray[0], _tempPos)))
				return err;
			_tempPos = 0;
		}
		return OK;
	}

	Int GetCount() const
	{
		DebugAssert(_destination);

		return _destination->GetCount() + _tempPos;
	}

private:
	Int		 _tempPos;
	T      _tempArray[DEFAULT_APPENDSIZE];
	WritableArrayInterface<T>* _destination;
};


}


#endif // STREAMCONVERSION_IMPL_HELPER_H__
