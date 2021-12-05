#ifndef MULTIINDEX_H__
#define MULTIINDEX_H__

#include "maxon/foreach.h"

namespace maxon
{

inline void OrAssignWithShift(UInt64& value, UInt bits, UInt shift)
{
	value |= bits << shift;
}

#ifndef MAXON_TARGET_64BIT
inline void OrAssignWithShift(UInt64& value, UInt64 bits, UInt shift)
{
	value |= bits << shift;
}
#endif

inline void AndNotAssignWithShift(UInt64& value, UInt bits, UInt shift)
{
	value &= ~(UInt64(bits) << shift);
}

inline UInt GetUInt(UInt64 value, UInt position)
{
	return UInt(value >> position);
}

inline UInt GetMultiIndexElementLength(UInt code)
{
	DebugAssert((code > 0) && (code < 8));
	// 1 = 2 bits
	// 2 = 4 bits
	// 3 = 8 bits
	// 4 = 16 bits
	// 5 = 24 bits
	// 6 = 32 bits
	// 7 = 40 bits
	static_assert(Int(-1) >> 3 == Int(-1), "The C++ implementation doesn't implement right shifts for negative values as arithmetic shifts.");
	UInt mask = Int(code - 3) >> 3;
	return ((code << 1) & mask) | (((code - 2) << 3) & ~mask); // this branchless expression is faster than the straightforward one from below with ?:
	// return MAXON_UNLIKELY(code < 3) ? code << 1 : (code - 2) << 3;
}

template <typename INT_TYPE> class MultiIndexBuilder;

template <typename INT_TYPE> class MultiIndex
{
public:
	MultiIndex() = default;

	MAXON_OPERATOR_EQUALITY_HASHCODE(MultiIndex, _value);

	class Iterator : public ForEachIterator<Iterator>
	{
	public:
		explicit Iterator(const MultiIndex& index) : _value(index._value), _position(0), _current(GetUInt(index._value, 0))
		{
		}

		Iterator() = default;

		explicit operator Bool() const
		{
			return Bool(_current != 0);
		}

		Bool operator !=(const Iterator& other) const
		{
			return _current != 0;
		}

		void operator ++()
		{
			UInt len = GetMultiIndexElementLength(_current & 7);
			_position += 3 + len;
			_current = GetUInt(_value, _position);
		}

		Int operator *() const
		{
			UInt len = GetMultiIndexElementLength(_current & 7);
			return (_current >> 3) & ((UInt(1) << len) - 1);
		}

	private:
		INT_TYPE _value;
		UInt _position;
		UInt _current;
	};

	Iterator Begin() const
	{
		return Iterator(*this);
	}

	Iterator End() const
	{
		return Iterator();
	}

	String ToString(const FormatStatement* fmt) const;

	MultiIndex GetParent() const;

//	MultiIndex Concat(Int index) const;

//	MultiIndex Concat(const MultiIndex& index) const;

	MultiIndex FromEnd(Int count) const;

	Int GetCount() const;

	Bool IsEmpty() const
	{
		return _value == 0;
	}

	Bool IsPopulated() const
	{
		return _value != 0;
	}

private:
	explicit MultiIndex(const INT_TYPE& value) : _value(value)
	{
	}

	// _value represents a sequence of values of variable bit length.
	// A value starts with 3 bits which encode the remaining bit length of the value:
	// 0 = end of the sequence
	// 1 = 2 bits
	// 2 = 4 bits
	// 3 = 8 bits
	// 4 = 16 bits
	// 5 = 24 bits
	// 6 = 32 bits
	// 7 = 40 bits
	INT_TYPE _value = 0;

	friend class MultiIndexBuilder<INT_TYPE>;
};

using MultiIndex64 = MultiIndex<UInt64>;

template <typename INT_TYPE> class MultiIndexBuilder
{
public:
	MultiIndexBuilder() : _index(INT_TYPE(0)), _position(0)
	{
	}

	void Append(Int index)
	{
		Append(_index._value, _position, index);
	}

	static void Append(INT_TYPE& v, UInt& pos, Int index)
	{
		DebugAssert(index >= 0);
		if (index < (1 << 16))
		{
			if (index < (1 << 4))
			{
				if (index < (1 << 2))
				{
					AppendImpl(v, pos, index, 1);
				}
				else
				{
					AppendImpl(v, pos, index, 2);
				}
			}
			else
			{
				if (index < (1 << 8))
				{
					AppendImpl(v, pos, index, 3);
				}
				else
				{
					AppendImpl(v, pos, index, 4);
				}
			}
		}
		else
		{
#ifdef MAXON_TARGET_64BIT
			if (index < (Int(1) << 32))
#endif
			{
				if (index < (1 << 24))
				{
					AppendImpl(v, pos, index, 5);
				}
				else
				{
					AppendImpl(v, pos, index, 6);
				}
			}
#ifdef MAXON_TARGET_64BIT
			else
			{
				DebugAssert(index < (Int(1) << 40));
				AppendImpl(v, pos, index, 7);
			}
#endif
		}
	}

	const MultiIndex<INT_TYPE>& Finish()
	{
		OrAssignWithShift(_index._value, UInt(0), _position);
		return _index;
	}

private:
	static void AppendImpl(INT_TYPE& v, UInt& pos, UInt index, UInt bits)
	{
		OrAssignWithShift(v, (index << 3) + bits, pos);
		pos += 3 + (Int(1) << bits);
		DebugAssert(pos < SIZEOF(INT_TYPE) * 8);
	}

	MultiIndex<INT_TYPE> _index;
	UInt _position;
};

} // namespace maxon

#endif // MULTIINDEX_H__
