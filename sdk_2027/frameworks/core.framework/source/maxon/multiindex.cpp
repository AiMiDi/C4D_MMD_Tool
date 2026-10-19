#include "maxon/multiindex.h"
#include "maxon/string.h"
#include "maxon/bitmanipulation.h"

namespace maxon
{

template <typename INT_TYPE> MultiIndex<INT_TYPE> MultiIndex<INT_TYPE>::Prepend(Int index) const
{
	INT_TYPE i = 0;
	UInt pos = 0;
	MultiIndexBuilder<INT_TYPE>::Append(i, pos, index);
	return MultiIndex<INT_TYPE>((_value << pos) | i);
}

template <typename INT_TYPE> MultiIndex<INT_TYPE> MultiIndex<INT_TYPE>::Concat(Int index) const
{
	INT_TYPE i = _value;
	UInt pos = SIZEOF(INT_TYPE) * 8 - 3 - Clz(i);
	maxon::details::AndNotAssignWithShift(i, 7, pos);
	MultiIndexBuilder<INT_TYPE>::Append(i, pos, index);
	return MultiIndex<INT_TYPE>(i);
}

template <typename INT_TYPE> MultiIndex<INT_TYPE> MultiIndex<INT_TYPE>::Concat(const MultiIndex& index) const
{
	INT_TYPE i = _value;
	UInt pos = SIZEOF(INT_TYPE) * 8 - 3 - Clz(i);
	DebugAssert(pos + SIZEOF(INT_TYPE) * 8 - Clz(index._value) <= SIZEOF(INT_TYPE) * 8);
	maxon::details::AndNotAssignWithShift(i, 7, pos);
	return MultiIndex<INT_TYPE>(i | (index._value << pos));
}

template <typename INT_TYPE> Int MultiIndex<INT_TYPE>::GetCount() const
{
	INT_TYPE i = _value;
	UInt pos = 0;
	Int cnt = 0;
	while (true)
	{
		UInt len = maxon::details::GetUInt(i, pos) & 7;
		if (len == 0)
		{
			return cnt;
		}
		len = maxon::details::GetMultiIndexElementLength(len);
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
		UInt len = maxon::details::GetUInt(i, pos) & 7;
		if (len == 0)
		{
			maxon::details::AndNotAssignWithShift(i, LIMIT<UInt>::MAX, prevPos);
			return MultiIndex<INT_TYPE>(i);
		}
		len = maxon::details::GetMultiIndexElementLength(len);
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
		UInt len = maxon::details::GetUInt(i, pos) & 7;
		len = maxon::details::GetMultiIndexElementLength(len);
		pos += 3 + len;
		--cnt;
	}
	return MultiIndex<INT_TYPE>(i >> pos);
}

template <typename INT_TYPE> String MultiIndex<INT_TYPE>::ToString(const FormatStatement* fmt) const
{
	return "{"_s + JoinElements(*this, "."_s) + "}"_s;
}

template class MultiIndex<UInt64>;

} // namespace maxon
