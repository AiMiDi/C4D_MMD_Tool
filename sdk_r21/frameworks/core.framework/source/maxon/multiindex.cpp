#include "maxon/multiindex.h"
#include "maxon/string.h"

namespace maxon
{

#if 1
#ifdef MAXON_TARGET_WINDOWS
Bool g_dummyGlobal; // avoids that the MSVC linker shows a warning
#endif
#else
template <typename INT_TYPE> MultiIndex<INT_TYPE> MultiIndex<INT_TYPE>::Concat(Int index) const
{
	INT_TYPE i = _value;
	UInt pos = SIZEOF(INT_TYPE) * 8 - 3 - Clz(i);
	AndNotAssignWithShift(i, 7, pos);
	MultiIndexBuilder<INT_TYPE>::Append(i, pos, index);
	OrAssignWithShift(i, UInt(7), pos);
	return MultiIndex<INT_TYPE>(i);
}

template <typename INT_TYPE> MultiIndex<INT_TYPE> MultiIndex<INT_TYPE>::Concat(const MultiIndex& index) const
{
	INT_TYPE i = _value;
	UInt pos = SIZEOF(INT_TYPE) * 8 - 3 - Clz(i);
	DebugAssert(pos + SIZEOF(INT_TYPE) * 8 - Clz(index._value) <= SIZEOF(INT_TYPE) * 8);
	AndNotAssignWithShift(i, 7, pos);
	OrAssignWithShift(i, index._value, pos);
	return MultiIndex<INT_TYPE>(i);
}
#endif

template <typename INT_TYPE> Int MultiIndex<INT_TYPE>::GetCount() const
{
	INT_TYPE i = _value;
	UInt pos = 0;
	Int cnt = 0;
	while (true)
	{
		UInt len = GetUInt(i, pos) & 7;
		if (len == 0)
		{
			return cnt;
		}
		len = GetMultiIndexElementLength(len);
		pos += 3 + len;
		++cnt;
	}
}

template <typename INT_TYPE> MultiIndex<INT_TYPE> MultiIndex<INT_TYPE>::GetParent() const
{
	INT_TYPE i = _value;
	UInt prevPos = 0;
	UInt pos = 0;
	while (true)
	{
		UInt len = GetUInt(i, pos) & 7;
		if (len == 0)
		{
			AndNotAssignWithShift(i, LIMIT<UInt>::MAX, prevPos);
			return MultiIndex<INT_TYPE>(i);
		}
		len = GetMultiIndexElementLength(len);
		prevPos = pos;
		pos += 3 + len;
	}
}

template <typename INT_TYPE> MultiIndex<INT_TYPE> MultiIndex<INT_TYPE>::FromEnd(Int count) const
{
	Int cnt = GetCount();
	DebugAssert(UInt(count) <= UInt(cnt));
	INT_TYPE i = _value;
	UInt pos = 0;
	while (cnt > count)
	{
		UInt len = GetUInt(i, pos) & 7;
		len = GetMultiIndexElementLength(len);
		pos += 3 + len;
		--cnt;
	}
	return MultiIndex<INT_TYPE>(i >> pos);
}

template <typename INT_TYPE> String MultiIndex<INT_TYPE>::ToString(const FormatStatement* fmt) const
{
	return JoinElements(*this, "."_s);
}

template class MultiIndex<UInt64>;

} // namespace maxon
