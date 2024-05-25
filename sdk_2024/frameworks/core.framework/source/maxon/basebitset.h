#ifndef BASEBITSET_H__
#define BASEBITSET_H__

#include "maxon/basearray.h"
#include "maxon/error.h"
#include "maxon/dataserialize.h"

#ifdef MAXON_TARGET_LINUX
	#ifdef INT_WIDTH
		#undef INT_WIDTH
	#endif
#endif

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

//----------------------------------------------------------------------------------------
/// The BaseBitSetIterator allows you to iterate over only the set bits of a bit set.
/// Internally it stores a pointer to the bit set object and an index to the last set bit.
/// If we have reached the end or the iterator is invalid the index will be -1 to match the
/// specification of the bit set.
///
/// For simplicity the iterator provides only an increment operator.
/// @code
/// it++;									// go to the next set bit
/// it = bitSet.Begin();	// iterator to the first set bit of the array, index will be -1 if invalid
/// value = *it;					// get index of the bit referenced by the iterator
/// @endcode
///
/// You can also use the iterator implicitly in a range-based for loop to iterate over the set bits:
/// @code
/// for (const Int bitIndex : bitSet)
/// {
///		// do something with the index
/// }
/// @endcode
///
/// @tparam COLLECTION						Type of the bit set.
//----------------------------------------------------------------------------------------
template <typename COLLECTION> class BaseBitSetIterator
{
public:
	using CollectionType = COLLECTION;
	static const Bool isLinearIterator = true;

	explicit BaseBitSetIterator(CollectionType& a, Int start = 0) : _data(&a), _index(start)
	{
		if (start != -1)
		{
			_index = a.GetNextSet(start);
		}
	}

	operator Bool() const
	{
		return (_index != -1);
	}

	Int operator *() const
	{
		return _index;
	}

	Int GetIndex() const
	{
		return _index;
	}

	Bool operator ==(const BaseBitSetIterator& b) const
	{
		return _data == b._data && _index == b._index;
	}

	Bool operator <(const BaseBitSetIterator& b) const
	{
		return _data == b._data && _index < b._index;
	}

	MAXON_OPERATOR_COMPARISON(BaseBitSetIterator);

	// prefix operator ++ (increment and fetch)
	BaseBitSetIterator& operator ++()
	{
		_index = _data->GetNextSet(_index + 1);

		return *this;
	}

	// postfix operator ++ (fetch and increment)
	BaseBitSetIterator operator ++(int)
	{
		const Int oldIndex = _index;
		_index = _data->GetNextSet(_index + 1);

		return BaseBitSetIterator(_data, oldIndex);
	}

protected:
	CollectionType* _data = nullptr;
	Int _index = 0;
};

//----------------------------------------------------------------------------------------
///	BaseBitSet documentation
//----------------------------------------------------------------------------------------
template <typename ALLOCATOR = DefaultAllocator, typename INTTYPE = UInt> class BaseBitSet
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(BaseBitSet);

public:
	using IntType = INTTYPE;

	/// Iterator for read-only access to the bit elements
	using ConstIterator = BaseBitSetIterator<const BaseBitSet>;

	template <typename SUPER> class ResultFunctions : public SUPER
	{
	public:
		using SUPER::SUPER;

		Result<ConstIterator> begin()
		{
			return { this->UncheckedGetValue().Begin(), reinterpret_cast<const Result<void>&>(this->_error) };
		}

		Result<ConstIterator> end()
		{
			return { this->UncheckedGetValue().End(), reinterpret_cast<const Result<void>&>(this->_error) };
		}
	};

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	BaseBitSet() = default;

	//----------------------------------------------------------------------------------------
	/// Move constructor
	/// @param[in] rhs								The bitset which is moved.
	//----------------------------------------------------------------------------------------
	BaseBitSet(BaseBitSet&& rhs)
		: _bits(std::move(rhs._bits))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Move assignment operator
	/// @param[in] rhs								The bitset which is moved.
	/// @return												A reference to this bitset.
	//----------------------------------------------------------------------------------------
	BaseBitSet& operator =(BaseBitSet&& rhs)
	{
		_bits = std::move(rhs._bits);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if a bit is set in the bitset.
	/// @param[in] index							Input index of the bit which should be set.
	/// @return												True if the bit at @p index is set, otherwise false.
	//----------------------------------------------------------------------------------------
	Bool IsSet(UInt index) const
	{
		const Int intIndex = (Int) (index >> INT_WIDTH_EXPONENT);
		return (intIndex < _bits.GetCount()) &&
			((_bits[intIndex] & (IntType(1) << (index & INT_MASK))) != 0);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if a bit is set in the bitset. It does not check if the underlying array is big enough to contain a bit at this index.
	/// @param[in] index							Input index of the bit which should be set.
	/// @return												True if the bit at @index index is set, otherwise false.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool IsSetUnchecked(UInt index) const
	{
		const Int intIndex = (Int)(index >> INT_WIDTH_EXPONENT);
		return (_bits[intIndex] & (IntType(1) << (index & INT_MASK))) != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Clears a bit in the bitset. It does not check if the underlying array is big enough to contain a bit at this index.
	/// @param[in] index							Input index of the bit which should be set.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void ClearUnchecked(UInt index)
	{
		const Int intIndex = (Int)(index >> INT_WIDTH_EXPONENT);
		_bits[intIndex] &= ~(IntType(1) << (index & INT_MASK));
	}

	//----------------------------------------------------------------------------------------
	/// Sets the bit at a given index and returns if it was actually set.
	/// @param[in] index							Input index of the bit which should be set.
	/// @param[out] isSet							This will be set to true if the bit is actually set, otherwise to false.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Set(UInt index, Bool& isSet)
	{
		iferr_scope;
		// Resize the bit array if necessary
		const Int intIndex = (Int)(index >> INT_WIDTH_EXPONENT);
		if ((intIndex >= _bits.GetCount()))
		{
			isSet = false;
			_bits.Resize(intIndex + 1) iferr_return;
		}

		// Get the local int value for the index and the local bit
		const IntType localValue = IntType(1) << (index & INT_MASK);
		IntType& localBit = _bits[intIndex];

		// Check if the bit is already set
		isSet = !(localBit & localValue);
		localBit |= localValue;

		return OK;
	}


	//----------------------------------------------------------------------------------------
	/// Check if the bitset is empty.
	/// @return												True if no bit is set, otherwise false.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const
	{
		return _bits.GetCount() == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Check if the bitset contains at least one element.
	/// @return												False if no bit is set, otherwise true.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return _bits.GetCount() != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Sets the bit at a given index to the specific value.
	/// @param[in] index							Input index of the bit which should be set.
	///	@param[in] value							The value to set the bit to (true or false).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> SetValue(UInt index, Bool value)
	{
		iferr_scope;

		// Resize the bit array if necessary
		const Int intIndex = (Int)(index >> INT_WIDTH_EXPONENT);
		if ((intIndex >= _bits.GetCount()))
		{
			_bits.Resize(intIndex + 1) iferr_return;
		}

		// Get the local int value for the index and the local bit
		const IntType localValue = IntType(1) << (index & INT_MASK);
		const IntType otherLocalValue = IntType(value) << (index & INT_MASK);
		IntType& localBit = _bits[intIndex];
		localBit = ((localBit & ~localValue) | otherLocalValue);

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Sets the bit at a given index. It does not check if the underlying array is big enough to contain a bit at this index.
	/// @param[in] index							Input index of the bit which should be set.
	/// @param[in] value							The value to set the bit to (true or false).
	//----------------------------------------------------------------------------------------
	void SetValueUnchecked(UInt index, Bool value)
	{
		const Int intIndex = (Int)(index >> INT_WIDTH_EXPONENT);

		// Get the local int value for the index and the local bit
		const IntType localValue = IntType(1) << (index & INT_MASK);
		const IntType otherLocalValue = IntType(value) << (index & INT_MASK);
		IntType& localBit = _bits[intIndex];
		localBit = ((localBit & ~localValue) | otherLocalValue);
	}

	//----------------------------------------------------------------------------------------
	/// Sets the bit at a given index.
	/// @param[in] index							Input index of the bit which should be set.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Set(UInt index)
	{
		iferr_scope;
		// Resize the bit array if necessary
		const Int intIndex = (Int)(index >> INT_WIDTH_EXPONENT);
		if ((intIndex >= _bits.GetCount()))
		{
			_bits.Resize(intIndex + 1) iferr_return;
		}

		// Get the local int value for the index and the local bit
		const IntType localValue = IntType(1) << (index & INT_MASK);
		IntType& localBit = _bits[intIndex];

		localBit |= localValue;

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Sets the bit at a given index. It does not check if the underlying array is big enough to contain a bit at this index.
	/// @param[in] index							Input index of the bit which should be set.
	//----------------------------------------------------------------------------------------
	void SetUnchecked(UInt index)
	{
		const Int intIndex = (Int)(index >> INT_WIDTH_EXPONENT);

		// Get the local int value for the index and the local bit
		const IntType localValue = IntType(1) << (index & INT_MASK);
		IntType& localBit = _bits[intIndex];

		localBit |= localValue;
	}

	//----------------------------------------------------------------------------------------
	/// Sets the bit at a given index. It does not check if the underlying array is big enough to contain a bit at this index.
	/// @param[in] index							Input index of the bit which should be set.
	/// @return												true, if the bit was already set.
	//----------------------------------------------------------------------------------------
	Bool SetAndCheckUnchecked(UInt index)
	{
		const Int intIndex = (Int)(index >> INT_WIDTH_EXPONENT);

		// Get the local int value for the index and the local bit
		const IntType localValue = IntType(1) << (index & INT_MASK);
		IntType& localBit = _bits[intIndex];
		const Bool isBitSet = Bool(localBit & localValue);

		localBit |= localValue;

		return isBitSet;
	}

	//----------------------------------------------------------------------------------------
	/// Sets all bits in the given range. first must be smaller or equal to last.
	/// @param[in] first							First element to set.
	/// @param[in] last								Last element to set.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> SetRange(UInt first, UInt last)
	{
		iferr_scope;
		// Resize the bit array if necessary
		const Int intIndex = (Int)(last >> INT_WIDTH_EXPONENT);
		if ((intIndex >= _bits.GetCount()))
		{
			_bits.Resize(intIndex + 1) iferr_return;
		}

		SetRangeUnchecked(first, last);

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Sets all bits in the given range. first must be smaller or equal to last.
	/// @param[in] first							First element to set.
	/// @param[in] last								Last element to set.
	//----------------------------------------------------------------------------------------
	void SetRangeUnchecked(UInt first, UInt last)
	{
		UInt j, k;
		UInt a, b;

		a = first & INT_MASK;
		b = last & INT_MASK;

		j = first >> INT_WIDTH_EXPONENT;
		k = last >> INT_WIDTH_EXPONENT;

		if (j == k)
		{
			// first and last are at the same index in the underlying array.
			UInt c = LIMIT<IntType>::MAX >> (INT_WIDTH - (b - a + 1)); // the lowest (b - a + 1) bits will be set.
			c <<= a; // shift to the correct position
			_bits[j] |= c;

			return;
		}

		// Find out which bits have to be set in the first integer.
		_bits[j++] |= LIMIT<IntType>::MAX << (a);

		// Find out which bits have to be set in the last integer.
		_bits[k--] |= LIMIT<IntType>::MAX >> (INT_MASK - b);

		for (; j <= k; ++j)
			_bits[j] = LIMIT<IntType>::MAX;
	}

	//----------------------------------------------------------------------------------------
	/// Clears the bit at a given index and returns if it was actually cleared.
	/// @param[in] index							Input index of the bit which should be cleared.
	/// @param[out] cleared						This will be set to true if the bit is actually cleared, otherwise to false.
	//----------------------------------------------------------------------------------------
	void Clear(UInt index, Bool& cleared)
	{
		const Int intIndex = (Int)(index >> INT_WIDTH_EXPONENT);
		if ((intIndex >= _bits.GetCount()))
		{
			// Bit for the requested index does not exist
			cleared = false;
			return;
		}

		// Get the local int value for the index and the local bit
		const IntType localValue = IntType(1) << (index & INT_MASK);
		IntType& localBit = _bits[intIndex];

		// Check if the bit is already set
		cleared = (localBit & localValue);

		localBit &= ~localValue;

		RemoveTrailingZeroes();
	}

	//----------------------------------------------------------------------------------------
	/// Clears the bit at a given index.
	/// @param[in] index							Input index of the bit which should be cleared.
	//----------------------------------------------------------------------------------------
	void Clear(UInt index)
	{
		const Int intIndex = (Int)(index >> INT_WIDTH_EXPONENT);
		if ((intIndex >= _bits.GetCount()))
		{
			// Bit for the requested index does not exist
			return;
		}

		// Get the local int value for the index and the local bit
		const IntType localValue = IntType(1) << (index & INT_MASK);
		IntType& localBit = _bits[intIndex];

		localBit &= ~localValue;

		RemoveTrailingZeroes();
	}

	//----------------------------------------------------------------------------------------
	/// Resets the bitset.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_bits.Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Gets the hash code for the bitset, using GetHashCode() of the underlying <tt>BaseArray</tt>.
	/// @return												The bitset's hash code.
	//----------------------------------------------------------------------------------------
	HashInt GetHashCode() const
	{
		return _bits.GetHashCode();
	}

	//----------------------------------------------------------------------------------------
	/// Compares two bitsets, using the compare operator of the underlying <tt>BaseArray</tt>.
	/// @param[in] rhs								Input bitset rhs.
	/// @return												The component-by-component result of <tt>this == rhs</tt>.
	//----------------------------------------------------------------------------------------
	Bool operator ==(const BaseBitSet<ALLOCATOR, INTTYPE>& rhs) const
	{
		return _bits == rhs._bits;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise OR of this bitset and another bitset.
	/// @param[in] rhs								Input bitset rhs.
	/// @return												A reference to this bitset.
	//----------------------------------------------------------------------------------------
	BaseBitSet<ALLOCATOR, INTTYPE>& operator |=(const BaseBitSet<ALLOCATOR, INTTYPE>& rhs)
	{
		// Increase the length of the output bit array if its to short
		Int32 maxLength = (Int32)maxon::Max(_bits.GetCount(), rhs._bits.GetCount());

		iferr (_bits.Resize(maxLength))
		{
			// On resize error : _bits was to short, so limit the | operation on the length of _bits
			maxLength = (Int32)_bits.GetCount();
			DebugAssert(false);
		}

		Int32 minLength = (Int32)maxon::Min(_bits.GetCount(), rhs._bits.GetCount());

		// Logical OR of all Ints of the arrays
		for (Int32 i = 0; i < minLength; i++)
		{
			_bits[i] |= rhs._bits[i];
		}

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the bitwise AND of this bitset and another bitset.
	/// @param[in] rhs								Input bitset rhs.
	/// @return												A reference to this bitset.
	//----------------------------------------------------------------------------------------
	BaseBitSet<ALLOCATOR, INTTYPE>& operator &=(const BaseBitSet<ALLOCATOR, INTTYPE>& rhs)
	{
		// Increase the length of the output bit array if its to short
		Int32 maxLength = (Int32)maxon::Max(_bits.GetCount(), rhs._bits.GetCount());

		iferr (_bits.Resize(maxLength))
		{
			// On resize error : _bits was to short, so limit the | operation on the length of _bits
			maxLength = (Int32)_bits.GetCount();
			DebugAssert(false);
		}

		Int32 minLength = (Int32)maxon::Min(_bits.GetCount(), rhs._bits.GetCount());

		// Logical AND of all Ints of the arrays
		for (Int32 i = 0; i < minLength; i++)
		{
			_bits[i] &= rhs._bits[i];
		}

		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Copies the data from another bitset, using <tt>CopyFrom()</tt> of the underlying <tt>BaseArray</tt>
	/// @param[in] src								Source from which the data is taken
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(const BaseBitSet<ALLOCATOR, INTTYPE>& src)
	{
		return _bits.CopyFrom(src._bits);
	}


	//----------------------------------------------------------------------------------------
	/// Merges the data from another bitset with logical OR. If the other bitset is larger it will resize this one.
	/// @param[in] src								Source from which the data is merged.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> MergeOr(const BaseBitSet<ALLOCATOR, INTTYPE>& src)
	{
		iferr_scope;

		if (src._bits.GetCount() > _bits.GetCount())
		{
			_bits.Resize(src._bits.GetCount(), COLLECTION_RESIZE_FLAGS::ON_GROW_FIT_TO_SIZE) iferr_return;
		}


		for (Int bitIndex = 0; bitIndex < src._bits.GetCount(); bitIndex++)
		{
			_bits[bitIndex] |= src._bits[bitIndex];
		}

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Merges the data from another bitset with logical OR NOT. If the other bitset is larger it will resize this one.
	/// @param[in] src								Source from which the data is merged.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> MergeOrNot(const BaseBitSet<ALLOCATOR, INTTYPE>& src)
	{
		iferr_scope;

		if (src._bits.GetCount() > _bits.GetCount())
		{
			_bits.Resize(src._bits.GetCount(), COLLECTION_RESIZE_FLAGS::ON_GROW_FIT_TO_SIZE) iferr_return;
		}


		for (Int bitIndex = 0; bitIndex < src._bits.GetCount(); bitIndex++)
		{
			_bits[bitIndex] |= ~src._bits[bitIndex];
		}

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Merges the data from another bitset with logical AND. If the other bitset is larger it will resize this one.
	/// @param[in] src								Source from which the data is merged.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> MergeAnd(const BaseBitSet<ALLOCATOR, INTTYPE>& src)
	{
		iferr_scope;

		if (src._bits.GetCount() > _bits.GetCount())
		{
			_bits.Resize(src._bits.GetCount(), COLLECTION_RESIZE_FLAGS::ON_GROW_FIT_TO_SIZE) iferr_return;
		}

		for (Int bitIndex = 0; bitIndex < src._bits.GetCount(); bitIndex++)
		{
			_bits[bitIndex] &= src._bits[bitIndex];
		}

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Merges the data from another bitset with logical AND NOT. If the other bitset is larger it will resize this one.
	/// @param[in] src								Source from which the data is merged.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> MergeAndNot(const BaseBitSet<ALLOCATOR, INTTYPE>& src)
	{
		iferr_scope;

		if (src._bits.GetCount() > _bits.GetCount())
		{
			_bits.Resize(src._bits.GetCount(), COLLECTION_RESIZE_FLAGS::ON_GROW_FIT_TO_SIZE) iferr_return;
		}

		for (Int bitIndex = 0; bitIndex < src._bits.GetCount(); bitIndex++)
		{
			_bits[bitIndex] &= ~src._bits[bitIndex];
		}

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Merges the data from another bitset with logical XOR. If the other bitset is larger it will resize this one.
	/// @param[in] src								Source from which the data is merged.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> MergeXOr(const BaseBitSet<ALLOCATOR, INTTYPE>& src)
	{
		iferr_scope;

		if (src._bits.GetCount() > _bits.GetCount())
		{
			_bits.Resize(src._bits.GetCount(), COLLECTION_RESIZE_FLAGS::ON_GROW_FIT_TO_SIZE) iferr_return;
		}

		for (Int bitIndex = 0; bitIndex < src._bits.GetCount(); bitIndex++)
		{
			_bits[bitIndex] ^= src._bits[bitIndex];
		}

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Inverts all bits of the BaseBitSet.
	//----------------------------------------------------------------------------------------
	void Invert()
	{
		for (IntType& bitBlock : _bits)
		{
			bitBlock = ~bitBlock;
		}
	}

	//----------------------------------------------------------------------------------------
	/// Initializes the array to have at least as much space to contain a certain amount of bits.
	/// @param[in] count							Number of bits.
	//----------------------------------------------------------------------------------------
	Result<void> Init(UInt count, Bool clearValue)
	{
		Int minSize = (Int)(count >> INT_WIDTH_EXPONENT) + 1;
		iferr (_bits.Resize(minSize, COLLECTION_RESIZE_FLAGS::POD_UNINITIALIZED))
			return err;

		if (clearValue)
			ClearMemType(_bits.GetFirst(), _bits.GetCount(), 0xff);
		else
			ClearMemType(_bits.GetFirst(), _bits.GetCount(), 0x00);

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Counts the bits in the selection
	/// @param[in] first							Index from which counting starts.
	/// @param[in] last								Index where counting ends.
	/// @return												Number of set bits.
	//----------------------------------------------------------------------------------------
	Int CountBits(UInt first = 0, UInt last = (UInt)-1) const
	{
		Int count = 0;

		if (last == (UInt)-1)
		{
			last = (_bits.GetCount() * INT_WIDTH) - 1;

			if (last == (UInt)-1)
				return 0;
		}

		UInt j, k;
		UInt a, b;

		a = first & INT_MASK;
		b = last & INT_MASK;

		j = first >> INT_WIDTH_EXPONENT;
		k = last >> INT_WIDTH_EXPONENT;

		if (j == k)
		{
			// first and last are at the same index in the underlying array.
			UInt c = LIMIT<IntType>::MAX >> (INT_WIDTH - (b - a + 1)); // the lowest (b - a + 1) bits will be set.
			c <<= a; // shift to the correct position
			count += CountBitsInWord(_bits[j] & c);

			return count;
		}

		// Find out which bits have to be checked in the first integer.
		if (a > 0)
			count += CountBitsInWord(_bits[j++] & LIMIT<IntType>::MAX << (a));

		// Find out which bits have to be checked in the last integer.
		if (b > 0)
			count += CountBitsInWord(_bits[k--] & LIMIT<IntType>::MAX >> (INT_MASK - b));

		for (; j <= k; ++j)
			count += CountBitsInWord(_bits[j]);

		return count;
	}

	Int GetNextSet(Int index) const
	{
		const Int end = _bits.GetCount() << INT_WIDTH_EXPONENT;
		while (index < end)
		{
			const IntType bits = _bits[index >> INT_WIDTH_EXPONENT];
			if (bits == 0)
			{
				index = (index & ~INT_MASK) + INT_WIDTH;
			}
			else if (bits & (IntType(1) << (index & INT_MASK)))
			{
				return index;
			}
			else
			{
				++index;
			}
		}
		return -1;
	}

	Int GetNextCleared(Int index) const
	{
		const Int end = _bits.GetCount() << INT_WIDTH_EXPONENT;
		while (index < end)
		{
			const IntType bits = _bits[index >> INT_WIDTH_EXPONENT];
			if (bits == LIMIT<IntType>::MAX)
			{
				index = (index & ~INT_MASK) + INT_WIDTH;
			}
			else if (!(bits & (IntType(1) << (index & INT_MASK))))
			{
				return index;
			}
			else
			{
				++index;
			}
		}
		return index;
	}

	//----------------------------------------------------------------------------------------
	/// Get The maximum capacity of the BitSet.
	/// @return												Number maximum bits.
	//----------------------------------------------------------------------------------------
	Int GetCapacity() const
	{
		return _bits.GetCount() << INT_WIDTH_EXPONENT;
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator to a const bit set to the first set bit.
	/// @return												Iterator for the first set bit (equal to End() if the set has no set bits).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ConstIterator Begin() const
	{
		return ConstIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator to a const bit set pointing to an invalid bit (-1).
	/// @return												Iterator pointing to an invalid bit (-1).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ConstIterator End() const
	{
		return ConstIterator(*this, -1);
	}

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static Result<void> DescribeIO(const DataSerializeInterface& stream)
	{
		iferr_scope;
		using BaseBitSetDefault = BaseBitSet<ALLOCATOR, INTTYPE>;
		PrepareDescribe(stream, BaseBitSetDefault);
		Describe("_bits", _bits, IntType, DESCRIBEFLAGS::TYPE_ARRAY) iferr_return;
		return OK;
	}

	const Block<const IntType>& GetRawData() const
	{
		return _bits.ToBlock();
	}

	static Bool IsSet(const Block<const IntType>& raw, Int index)
	{
		const Int intIndex = (Int) (index >> INT_WIDTH_EXPONENT);
		return (intIndex < raw.GetCount()) &&
			((raw[intIndex] & (IntType(1) << (index & INT_MASK))) != 0);
	}

private:
	static const UInt INT_WIDTH_EXPONENT = (SIZEOF(IntType) == 8) ? 6 : 5;
	static const IntType INT_MASK = ((1 << INT_WIDTH_EXPONENT) - 1);
	static const IntType INT_WIDTH = (1 << INT_WIDTH_EXPONENT);
	BaseArray<IntType, BASEARRAY_DEFAULT_CHUNK_SIZE, BASEARRAYFLAGS::MOVEANDCOPYOBJECTS, ALLOCATOR> _bits;

	//----------------------------------------------------------------------------------------
	/// Removes trailing zero bits in the underlying <tt>BaseArray</tt>
	//----------------------------------------------------------------------------------------
	void RemoveTrailingZeroes()
	{
		// Remove elements from the back that equal zero, until an non zero element is found
		while ((_bits.GetCount() > 0) && (*_bits.GetLast()) == 0)
		{
			_bits.Pop();
		}
	}

	//----------------------------------------------------------------------------------------
	/// Counts the bits of a word.
	/// @param[in] word								Word in which the bits have to be counted.
	/// @return												Number of set bits in the word.
	//----------------------------------------------------------------------------------------
	Int CountBitsInWord(IntType word) const
	{
		// From Hacker's Delight, p. 66, Figure 5-2, https://books.google.de/books?id=iBNKMspIlqEC&pg=PA66&redir_esc=y&hl=de#v=onepage&q&f=false
		if (SIZEOF(IntType) == 8)
		{
			UInt64 x = word;
			x = x - ((x >> 1) & 0x5555555555555555);
			x = (x & 0x3333333333333333) + ((x >> 2) & 0x3333333333333333);
			x = (x + (x >> 4)) & 0x0F0F0F0F0F0F0F0F;
			x = x + (x >> 8);
			x = x + (x >> 16);
			x = x + (x >> 32);
			return (Int)(x & 0x0000007F);
		}
		else
		{
			UInt32 x = (UInt32)word;
			DebugAssert(SIZEOF(IntType) == 4);
			x = x - ((x >> 1) & 0x55555555);
			x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
			x = (x + (x >> 4)) & 0x0F0F0F0F;
			x = x + (x >> 8);
			x = x + (x >> 16);
			return (Int)(x & 0x0000003F);
		}
	}
};

/// @}

using BitSet = BaseBitSet<DefaultAllocator, UInt>;
MAXON_DATATYPE(BitSet, "net.maxon.datatype.bitset");

#include "basebitset1.hxx"
#include "basebitset2.hxx"

} // namespace maxon

#endif // BASEBITSET_H__
