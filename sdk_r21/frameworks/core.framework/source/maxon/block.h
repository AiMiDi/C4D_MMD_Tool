#ifndef BLOCK_H__
#define BLOCK_H__

#include <iterator>
#include <initializer_list>

#include "maxon/collection.h"

/// @file

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

//----------------------------------------------------------------------------------------
/// Base class for Block.
//----------------------------------------------------------------------------------------
template <typename T, Bool STRIDED> class BlockBase
{
public:
	BlockBase(T* ptr, Int size, Int stride) : _ptr(ptr), _size(size), _stride(stride) { }

	//----------------------------------------------------------------------------------------
	/// Returns the number of elements of this block.
	/// @return												Number of elements of this block.
	//----------------------------------------------------------------------------------------
	Int GetCount() const { return _size; }

	//----------------------------------------------------------------------------------------
	/// Sets the number of elements of this block.
	/// @param[in] cnt								Number of elements of this block.
	//----------------------------------------------------------------------------------------
	void SetCount(Int cnt) { _size = cnt; }

protected:
	Int PrivateGetStride() const { return _stride; }

	T* _ptr;
	Int _size;
	Int _stride;
};

// specialization for the non-strided case
template <typename T> class BlockBase<T, false>
{
public:
	BlockBase(T* ptr, Int size, Int stride = 0) : _ptr(ptr), _size(size) { }

	Int GetCount() const { return _size; }

	void SetCount(Int cnt) { _size = cnt; }

protected:
	Int PrivateGetStride() const { return -1; }

	T* _ptr;
	Int _size;
};

//----------------------------------------------------------------------------------------
/// The BaseIterator internally is a pointer. So using it to iterate over an array
/// or parts of it is as efficient as using a real pointer (for more ease of use you may
/// want to invoke this via the C++11 range based for loop).
///
/// As already said you can use an Iterator almost like a pointer, e.g.
/// @code
/// it++;								// go to the next element
/// it--;								// go to the previous element
/// it += 5;						// advance by 5 elements
/// it -= 3;						// go back 3 elements
/// cnt = itB - itA;		// number of elements from itA to itB
/// it = array.Begin();	// iterator to the first element of the array
/// *it = value;				// assign value to the elements referenced by the iterator
/// value = *it;				// get value of the element referenced by the iterator
/// @endcode
///
/// Please note that using a postfix operator access (*it++ or *it--) can be slower than
/// using the prefix form or a separate assignment. E.g.
/// @code	value = *it++; @endcode is most likely slower than
/// @code	value = it; ++it; @endcode or @code	value = it; it++; @endcode
/// because *it++ requires a temporary copy of the iterator that the compiler may not
/// be able to remove during optimization. As long as you only use the iterator's postfix
/// operator without assignment it should be fine because the compiler will remove the
/// temporary copy.
///
/// You can either type alias the BaseIterator (like the BaseArray does) or inherit from it.
///
/// @tparam COLLECTION						Type of the array.
/// @tparam STRIDED								False for pointer-only iterator. True if the iterator has to support a variable stride offset (slower and requires another member variable).
//----------------------------------------------------------------------------------------
template <typename COLLECTION, Bool STRIDED> class BaseIterator
{
public:
	using CollectionType = COLLECTION;
	using ValueType = typename InheritConst<typename COLLECTION::ValueType, COLLECTION>::type;
	static const Bool isLinearIterator = true;

	using iterator_category = std::random_access_iterator_tag;
	using difference_type = Int;
	using value_type = ValueType;
	using pointer = ValueType*;
	using reference = ValueType&;

	explicit BaseIterator(CollectionType& a, Int start = 0) : _data(a.GetFirst() + start) { }

	explicit BaseIterator(ValueType* pos = nullptr, Int index = 0, Int stride = 0) : _data(pos) { }

	BaseIterator(const BaseIterator& src) = default;
	BaseIterator& operator =(const BaseIterator& src) = default;

#ifdef MAXON_COMPILER_INTEL
#pragma warning disable 597
#endif
	operator BaseIterator<typename std::add_const<COLLECTION>::type, STRIDED>&()
	{
		return *(BaseIterator<typename std::add_const<COLLECTION>::type, STRIDED>*) this;
	}
#ifdef MAXON_COMPILER_INTEL
#pragma warning enable 597
#endif

	//----------------------------------------------------------------------------------------
	/// @return												true if the iterator points to an element.
	//----------------------------------------------------------------------------------------
	explicit operator Bool() const
	{
		return Bool(_data != nullptr);
	}

	ValueType* GetPtr() const
	{
		return _data;
	}

	ValueType& operator *() const
	{
		return *_data;
	}

	ValueType* operator ->() const
	{
		return _data;
	}

	Bool operator ==(const BaseIterator& b) const
	{
		return _data == b._data;
	}

	Bool operator <(const BaseIterator& b) const
	{
		return _data < b._data;
	}

	MAXON_OPERATOR_COMPARISON(BaseIterator);

	// prefix operator ++ (increment and fetch)
	BaseIterator& operator ++()
	{
		_data++;
		return *this;
	}

	// postfix operator ++ (fetch and increment)
	BaseIterator operator ++(int)
	{
		ValueType* tmp = _data;
		_data++;

		// use RVO
		return BaseIterator(tmp);
	}

	// operator +=
	BaseIterator& operator +=(Int i)
	{
		_data += i;
		return *this;
	}

	// prefix operator -- (decrement and fetch)
	BaseIterator& operator --()
	{
		_data--;
		return *this;
	}

	// postfix operator -- (fetch and decrement)
	BaseIterator operator --(int)
	{
		ValueType* tmp = _data;
		_data--;

		// use RVO
		return BaseIterator(tmp);
	}

	// operator -=
	BaseIterator& operator -=(Int i)
	{
		_data -= i;
		return *this;
	}

	// operator +
	BaseIterator operator +(Int i) const
	{
		// use RVO
		return BaseIterator(_data + i);
	}

	BaseIterator operator -(Int i) const
	{
		// use RVO
		return BaseIterator(_data - i);
	}

	Int operator -(const BaseIterator& b) const
	{
		return _data - b._data;
	}

protected:
	ValueType* _data;
};

//----------------------------------------------------------------------------------------
/// BaseIterator specialization for elements having a different offset from each other
/// than the element size.
///
/// @tparam COLLECTION						Type of the array.
//----------------------------------------------------------------------------------------
template <typename COLLECTION> class BaseIterator<COLLECTION, true> : public BaseIterator<COLLECTION, false>
{
public:
	using Super = BaseIterator<COLLECTION, false>;
	using ValueType = typename Super::ValueType;

	BaseIterator(COLLECTION& a, Int index) : Super((ValueType*) ((Char*) a.GetFirst() + a.GetStride() * index)), _stride(a.GetStride()), _index(index)
	{
	}

	BaseIterator(ValueType* pos, Int index, Int stride) : Super(pos), _stride(stride), _index(index) { }

	BaseIterator(const BaseIterator& src) = default;
	BaseIterator& operator =(const BaseIterator& src) = default;

#ifdef MAXON_COMPILER_INTEL
#pragma warning disable 597
#endif
	operator BaseIterator<typename std::add_const<COLLECTION>::type, true>&()
	{
		return *(BaseIterator<typename std::add_const<COLLECTION>::type, true>*) this;
	}
#ifdef MAXON_COMPILER_INTEL
#pragma warning enable 597
#endif

	Bool operator ==(const BaseIterator& b) const
	{
		return _index == b._index;
	}

	Bool operator <(const BaseIterator& b) const
	{
		return _index < b._index;
	}

	MAXON_OPERATOR_COMPARISON(BaseIterator);

	// prefix operator ++ (increment and fetch)
	BaseIterator& operator ++()
	{
		(Char*&) this->_data += _stride;
		++_index;
		return *this;
	}

	// postfix operator ++ (fetch and increment)
	BaseIterator operator ++(int)
	{
		ValueType* tmp = this->_data;
		(Char*&) this->_data += _stride;
		// use RVO
		return BaseIterator(tmp, _index++, _stride);
	}

	// operator +=
	BaseIterator& operator +=(Int i)
	{
		(Char*&) this->_data += _stride * i;
		_index += i;
		return *this;
	}

	// prefix operator -- (decrement and fetch)
	BaseIterator& operator --()
	{
		(Char*&) this->_data -= _stride;
		--_index;
		return *this;
	}

	// postfix operator -- (fetch and decrement)
	BaseIterator operator --(int)
	{
		ValueType* tmp = this->_data;
		(Char*&) this->_data -= _stride;
		// use RVO
		return BaseIterator(tmp, _index--, _stride);
	}

	// operator -=
	BaseIterator& operator -=(Int i)
	{
		(Char*&) this->_data -= _stride * i;
		_index -= i;
		return *this;
	}

	// operator +
	BaseIterator operator +(Int i) const
	{
		// use RVO
		return BaseIterator((ValueType*) ((Char*) this->_data + _stride * i), _index + i, _stride);
	}

	BaseIterator operator -(Int i) const
	{
		// use RVO
		return BaseIterator((ValueType*) ((Char*) this->_data - _stride * i), _index - i, _stride);
	}

	Int operator -(const BaseIterator& b) const
	{
		DebugAssert((Char*) this->_data - (Char*) b._data == (_index - b._index) * _stride);
		return _index - b._index;
	}

protected:
	const Int _stride;
	Int _index; // we have to maintain a pointer and an index for the case of zero stride
};


template <typename T> using StridedBlock = Block<T, true>;

//----------------------------------------------------------------------------------------
/// A Block stands for a number of elements with a regular memory layout. It consists of
/// a pointer for the first element, the element count and optionally a stride.
/// All elements are placed consecutively in memory, but with a possible padding inbetween:
/// The stride is the pointer difference between
/// consecutive elements in bytes. By default, the stride is just <tt>SIZEOF(T)</tt>.
///
/// You can use an alternative stride length to access only specific elements of your array.
/// For example if you have an array with XYZ vectors and want to access only the X-values as a block,
/// you could use the pointer to the first X-value and a stride length of SIZEOF(Vector).
/// Or for a Block whose elements are all the same, you can use a stride of 0 and a pointer to
/// a single value.
///
/// There is an important difference between a Block and arrays such as BaseArray with respect
/// to the meaning of a const Block: A const block can't be modified itself, so its pointer and length
/// cannot be changed, but the memory to which the block points is still non-const (if #T is a non-const type).
/// So you can modify the memory through a const block. In other words, <tt>a[13] = 42;</tt> is OK for
/// a <tt>const Block<Int> a</tt>, but not for a <tt>const BaseArray<Int> a</tt>. Therefore you have to use
/// <tt>Block<const Int></tt> whenever the memory of the block shall be read-only. A typical case is an
/// input parameter to a function such as
/// @code
/// static Result<Int32> StringConversion::ToInt32(const Block<const Utf32Char>& str, STRINGCONVERSION flags);
/// @endcode
///
/// A Block supports the usual array functions which do not modify the length.
/// Also it can be converted to the Array interface. If unsupported functions are invoked then,
/// they will cause a @c DebugStop and indicate a failure on return.
/// @tparam T											Type of elements of the block. If the memory must not be modified through this block, use a const type.
/// @tparam STRIDED								True if a stride other than <tt>SIZEOF(T)</tt> shall be supported.
/// @tparam MOVE									True if the values of this block shall be moved (only useful when used as a parameter type, see MoveBlock).
/// @see @$ref blocks
//----------------------------------------------------------------------------------------
template <typename T, Bool STRIDED /* = false */, Bool MOVE /* = false */> class Block : public ArrayBase<Block<T, STRIDED, MOVE>, T, BlockBase<T, STRIDED>, DefaultCompare>
{
public:
	using Super = ArrayBase<Block<T, STRIDED, MOVE>, T, BlockBase<T, STRIDED>, DefaultCompare>;
	static const Bool GENERIC = std::is_same<const T, const Generic>::value;
	using StrideType = typename std::conditional<GENERIC, Char, T>::type; // use this to determine the default stride (Generic is incomplete and can't be used)
	using IsBlock = std::true_type; // allow to check templates if we have the Block class

	using Iterator = BaseIterator<Block, STRIDED>;
	using ConstIterator = BaseIterator<const Block, STRIDED>;

	//----------------------------------------------------------------------------------------
	/// Constructs an empty block with a @c nullptr pointer and zero count.
	//----------------------------------------------------------------------------------------
	Block() : Super(nullptr, 0, 0) { }

	//----------------------------------------------------------------------------------------
	/// Constructs a block using the given values.
	/// @param[in] ptr								Pointer to the first element.
	/// @param[in] size								Number of elements.
	/// @param[in] stride							Element stride. If the @p STRIDED parameter of the Block class is @c false, this has to be <tt>SIZEOF(T)</tt>.
	//----------------------------------------------------------------------------------------
	Block(T* ptr, Int size, Int stride = (STRIDED && GENERIC) ? -1 : SIZEOF(StrideType)) : Super(ptr, size, stride)
	{
		DebugAssert(STRIDED ? (stride >= 0) : (stride == SIZEOF(StrideType))); // in the strided Generic case, this ensures that an argument for stride has been specified
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a block from iterator and size. Equivalent to Block(static_cast<T*>(&*start), size, stride).
	//----------------------------------------------------------------------------------------
	Block(Iterator start, Int size, Int stride = (STRIDED && GENERIC) ? -1 : SIZEOF(StrideType)) : Super(&*start, size, stride)
	{
		DebugAssert(STRIDED ? (stride >= 0) : (stride == SIZEOF(StrideType))); // in the strided Generic case, this ensures that an argument for stride has been specified
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a block from const iterator and size. Equivalent to Block(static_cast<T*>(&*start), size, stride).
	//----------------------------------------------------------------------------------------
	Block(ConstIterator start, Int size, Int stride = (STRIDED && GENERIC) ? -1 : SIZEOF(StrideType)) : Super(&*start, size, stride)
	{
		DebugAssert(STRIDED ? (stride >= 0) : (stride == SIZEOF(StrideType))); // in the strided Generic case, this ensures that an argument for stride has been specified
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a block for a C++ fixed-size array. The length is automatically set to the full length
	/// of the array.
	//----------------------------------------------------------------------------------------
	template <Int N> MAXON_IMPLICIT Block(T (&array)[N]) : Super(static_cast<T*>(array), N, SIZEOF(StrideType)) { }

	MAXON_IMPLICIT Block(const std::initializer_list<typename std::remove_const<T>::type>& list) : Super(list.begin(), list.size(), SIZEOF(StrideType))
	{
		static_assert(std::is_const<T>::value, "Only a Block with const type can be initialized from an initializer list.");
	}

	Block(const Block& src) = default;
	Block& operator =(const Block& src) = default;

	Result<void> CopyFrom(const Block& src) = delete;

	// prevent auto conversion of a block to an array. use ToArray() to do this explicitly.
	operator ArrayImpl<Block&>() = delete;
	operator ArrayImpl<const Block&>() const = delete;

	//----------------------------------------------------------------------------------------
	/// Returns the stride of this block. If the @p STRIDED parameter of the Block class is
	/// @c false, this will always be <tt>SIZEOF(T)</tt>.
	/// @return												Element stride of this block, i.e., the difference in bytes between two consecutive elements.
	//----------------------------------------------------------------------------------------
	Int GetStride() const
	{
		static_assert(STRIDED || !GENERIC, "This function can't be used when T is Generic and no stride is given.");
		return STRIDED ? this->PrivateGetStride() : SIZEOF(StrideType);
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if this block uses a stride other than <tt>SIZEOF(T)</tt>.
	/// @return												True if the stride differs from the element size.
	//----------------------------------------------------------------------------------------
	Bool IsStrided() const
	{
		return STRIDED && (GENERIC || (this->PrivateGetStride() != SIZEOF(StrideType)));
	}

	//----------------------------------------------------------------------------------------
	/// Sets this block to new values.
	/// @param[in] ptr								Pointer to the first element.
	/// @param[in] size								Number of elements.
	/// @param[in] stride							Element stride. If the @p STRIDED parameter of the Block class is @c false, this has to be <tt>SIZEOF(T)</tt>.
	//----------------------------------------------------------------------------------------
	void Set(T* ptr, Int size, Int stride = (STRIDED && GENERIC) ? -1 : SIZEOF(StrideType))
	{
		DebugAssert(STRIDED ? (stride >= 0) : (stride == SIZEOF(StrideType))); // in the strided Generic case, this ensures that an argument for stride has been specified
		new (this) Super(ptr, size, stride);
	}

	//----------------------------------------------------------------------------------------
	/// Resets this block so that is points to @c nullptr and has zero length.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		new (this) Super(nullptr, 0, this->PrivateGetStride());
	}

	//----------------------------------------------------------------------------------------
	/// Converts this block to a strided block.
	//----------------------------------------------------------------------------------------
	operator typename std::conditional<STRIDED, DummyReturnType, Block<T, true, MOVE>>::type() const
	{
		return Block<T, true, MOVE>(GetFirst(), this->GetCount(), GetStride());
	}

	//----------------------------------------------------------------------------------------
	/// Converts this block to a strided block with constant elements.
	//----------------------------------------------------------------------------------------
	operator typename std::conditional<STRIDED || std::is_const<T>::value, const DummyReturnType, Block<const T, true, MOVE>>::type() const
	{
		return Block<const T, true, MOVE>(GetFirst(), this->GetCount(), GetStride());
	}

	//----------------------------------------------------------------------------------------
	/// Converts this block to a block with constant elements.
	//----------------------------------------------------------------------------------------
	operator typename std::conditional<std::is_const<T>::value, volatile DummyReturnType, const Block<const T, STRIDED, MOVE>&>::type() const
	{
		return *reinterpret_cast<const Block<const T, STRIDED, MOVE>*>(this);
	}


	//----------------------------------------------------------------------------------------
	/// Converts this block to a strided non-movable block.
	//----------------------------------------------------------------------------------------
	operator typename std::conditional<STRIDED || !MOVE, DummyReturnType&, Block<T, true, false>>::type() const
	{
		return Block<T, true, false>(GetFirst(), this->GetCount(), GetStride());
	}

	//----------------------------------------------------------------------------------------
	/// Converts this block to a strided non-movable block with constant elements.
	//----------------------------------------------------------------------------------------
	operator typename std::conditional<STRIDED || !MOVE || std::is_const<T>::value, const DummyReturnType&, Block<const T, true, false>>::type() const
	{
		return Block<const T, true, false>(GetFirst(), this->GetCount(), GetStride());
	}

	//----------------------------------------------------------------------------------------
	/// Converts this block to a non-movable block with constant elements.
	//----------------------------------------------------------------------------------------
	operator typename std::conditional<!MOVE || std::is_const<T>::value, volatile DummyReturnType&, const Block<const T, STRIDED, false>&>::type() const
	{
		return *reinterpret_cast<const Block<const T, STRIDED, false>*>(this);
	}

	//----------------------------------------------------------------------------------------
	/// Converts this block to a non-movable block.
	//----------------------------------------------------------------------------------------
	operator typename std::conditional<!MOVE, const volatile DummyReturnType&, const Block<T, STRIDED, false>&>::type() const
	{
		return *reinterpret_cast<const Block<T, STRIDED, false>*>(this);
	}


	//----------------------------------------------------------------------------------------
	/// Converts this block to a generic block.
	//----------------------------------------------------------------------------------------
	operator typename std::conditional<GENERIC, const volatile DummyReturnType, const Block<typename InheritConst<Generic, T>::type, STRIDED>&>::type() const
	{
		return *reinterpret_cast<const Block<typename InheritConst<Generic, T>::type, STRIDED>*>(this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the first element of this block. For an empty block, this is undefined and might be @c nullptr or any other value.
	/// @return												Pointer to the first element of this block (undefined if the block is empty).
	//----------------------------------------------------------------------------------------
	T* GetFirst() const { return this->_ptr; }

	//----------------------------------------------------------------------------------------
	/// Sets the first element of this block, may be @c nullptr.
	/// @param[in] value							Pointer to first element of this block.
	//----------------------------------------------------------------------------------------
	void SetFirst(T* value) { this->_ptr = value; }

	//----------------------------------------------------------------------------------------
	/// Returns the last element of this block. For an empty block, this is undefined and might be @c nullptr or any other value.
	/// @return												Pointer to the last element of this block (undefined if the block is empty).
	//----------------------------------------------------------------------------------------
	T* GetLast() const { return GetPtr(this->_size-1); }

	//----------------------------------------------------------------------------------------
	/// Returns the element at the given @p index of this block.
	/// @param[in] index							Index into the block.
	/// @return												Reference to the value at @p index.
	//----------------------------------------------------------------------------------------
	T& operator [](Int index) const
	{
		DebugAssert((UInt) index < (UInt) this->_size);
		return *GetPtr(index);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a sub block of this block with contains the elements from the given @p start index up to the end of the block.
	/// @param[in] start							Start index of the sub block.
	/// @return												Sub block starting at @p start.
	//----------------------------------------------------------------------------------------
	Block Slice(Int start) const
	{
		DebugAssert((UInt) start <= (UInt) this->_size);
		return Block(GetPtr(start), this->_size - start);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a sub block of this block with contains the elements from the given @p start index up to but not including the given @p end index.
	/// @param[in] start							Start index of the sub block.
	/// @param[in] end								End index of the sub block. The end index is exclusive.
	/// @return												Sub block with elements from @p start up to @p end.
	//----------------------------------------------------------------------------------------
	Block Slice(Int start, Int end) const
	{
		DebugAssert(((UInt) start <= (UInt) this->_size) && (start <= end) && ((UInt) end <= (UInt) this->_size));
		return Block(GetPtr(start), end - start);
	}

	Bool StartsWith(const Block& prefix) const
	{
		return this->GetCount() >= prefix.GetCount() && this->Slice(0, prefix.GetCount()) == prefix;
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the first element.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	Iterator Begin() const
	{
		static_assert(STRIDED || !GENERIC, "This function can't be used when T is Generic and no stride is given.");
		return Iterator(GetFirst(), 0, this->GetStride());
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the end (End() - 1 is the last element if the array is not empty).
	/// @return												Iterator for the array end (this is behind the last element).
	//----------------------------------------------------------------------------------------
	Iterator End() const
	{
		static_assert(STRIDED || !GENERIC, "This function can't be used when T is Generic and no stride is given.");
		return Iterator(*const_cast<Block*>(this), this->_size);
	}

	static const Block& NullValueRef()
	{
		return GetZeroRef<Block>();
	}

	Int GetCapacityCount() const
	{
		return this->GetCount();
	}

	// we must not use the name "CopyFrom" here because then it would be ambiguous whether to use copy assignment or CopyFrom in AssignCopy for a block
	template <typename T2, Bool S2> Result<void> CopyValuesFrom(const Block<T2, S2>& other)
	{
		Int n = this->GetCount();
		if (n != other.GetCount())
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_ARGUMENT);
		T* dest = GetFirst();
		T2* src = other.GetFirst();
		while (--n >= 0)
		{
			Result<void> res = AssignCopy<T>(*dest, *src);
			if (res == FAILED)
				return res;
			*((Char**) &dest) += this->GetStride();
			*((Char**) &src) += other.GetStride();
		}
		return OK;
	}

	template <typename COLLECTION> Result<void> CopyValuesFrom(const COLLECTION& other)
	{
		Int n = this->GetCount();
		if (n != other.GetCount())
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_ARGUMENT);
		T* dest = GetFirst();
		for (const auto& i : other)
		{
			if (--n < 0)
				return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::UNKNOWN);
			Result<void> res = AssignCopy<T>(*dest, i);
			if (res == FAILED)
				return res;
			*((Char**) &dest) += this->GetStride();
		}
		if (n != 0)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::UNKNOWN);
		return OK;
	}

	Int GetMemorySize() const
	{
		return SIZEOF(Block); // Block doesn't own the array's memory
	}

	Int GetBlock(Int index, Block<const T, false>& block) const
	{
		if (STRIDED && (GetStride() != SIZEOF(StrideType)))
		{
			block.Set(GetPtr(index), 1);
			return index;
		}
		else
		{
			block.Set(GetFirst(), this->GetCount());
			return 0;
		}
	}

	Int GetBlock(Int index, Block<T, false>& block) { return static_cast<const Block*>(this)->GetBlock(index, reinterpret_cast<Block<const T, false>&>(block)); }

	Int GetBlock(Int index, StridedBlock<T>& block) { block.Set(GetFirst(), this->GetCount(), GetStride()); return 0; }
	Int GetBlock(Int index, StridedBlock<const T>& block) const { block.Set(GetFirst(), this->GetCount(), GetStride()); return 0; }

private:
	T* GetPtr(Int index) const
	{
		MAXON_ASSERT_STANDARD_LAYOUT(Block);
		static_assert(STRIDED || !GENERIC, "This function can't be used when T is Generic and no stride is given.");
		return (!STRIDED || (this->PrivateGetStride() == SIZEOF(StrideType))) ? (T*) ((StrideType*) this->_ptr + index) : (T*) ((Char*) this->_ptr + index * this->PrivateGetStride());
	}

	template <typename ARRAY> friend class ArrayImpl;

	ResultRef<T> Insert(Int index) { DebugStop(); return nullptr; }
	ResultMem Insert(Int index, const Block<const T>& values) { DebugStop(); return FAILED; }
	ResultRef<T> Append() { DebugStop(); return nullptr; }
	ResultMem Erase(Int index, Int count)
	{
		if (count == 0)
			return OK;
		DebugStop();
		return FAILED;
	}
	ResultMem SwapErase(Int index, Int count)
	{
		if (count == 0)
			return OK;
		DebugStop();
		return FAILED;
	}

	ResultMem SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		return OK;
	}

	ResultMem Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::DEFAULT)
	{
		if (count == this->GetCount())
			return OK;
		DebugStop();
		return FAILED;
	}
	void Flush() { DebugAssert(this->IsEmpty()); }
};

template <> class Block<Byte, false, false> : public Block<Char, false, false>
{
	using Super = Block<Char, false, false>;
public:
	Block() : Super() { }

	Block(const Block& src) = default;
	Block& operator =(const Block& src) = default;

	Block(void* ptr, Int size, Int stride = 1) : Super((Char*)ptr, size, stride)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a block of raw bytes using the given values.
	/// @param[in] ptr								Pointer to the first byte.
	/// @param[in] size								Number of elements.
	/// @param[in] stride							Element stride. If the @p STRIDED parameter of the Block class is @c false, this has to be <tt>SIZEOF(T)</tt>.
	//----------------------------------------------------------------------------------------
	template <typename ANY> Block(ANY* ptr, Int size, Int stride = 1) : Super((Char*)ptr, size * SIZEOF(ANY), stride)
	{
	}

	template <typename ANY> Block(const Block<ANY>& src) : Super((Char*)src.GetFirst(), src.GetCount() * SIZEOF(ANY), 1)
	{
	}

	template <typename ANY, Int N> MAXON_IMPLICIT Block(ANY (&array)[N]) : Super((Char*)array, N * SIZEOF(ANY), 1) { }
};

template <> class Block<const Byte, false, false> : public Block<const Char, false, false>
{
	using Super = Block<const Char, false, false>;
public:
	Block() : Super() { }

	Block(const Block& src) = default;
	Block& operator =(const Block& src) = default;

	Block(const void* ptr, Int size, Int stride = 1) : Super(reinterpret_cast<const Char*>(ptr), size, stride)
	{
	}

	Block(const Block<Byte>& src) : Super(reinterpret_cast<const Char*>(src.GetFirst()), src.GetCount(), 1)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a block of const raw bytes using the given values.
	/// @param[in] ptr								Pointer to the first byte.
	/// @param[in] size								Number of elements.
	/// @param[in] stride							Element stride. If the @p STRIDED parameter of the Block class is @c false, this has to be <tt>SIZEOF(T)</tt>.
	//----------------------------------------------------------------------------------------
	template <typename ANY> Block(const ANY* ptr, Int size, Int stride = 1) : Super(reinterpret_cast<const Char*>(ptr), size * SIZEOF(ANY), stride)
	{
	}

	template <typename ANY> Block(const Block<ANY>& src) : Super(reinterpret_cast<const Char*>(src.GetFirst()), src.GetCount() * SIZEOF(ANY), 1)
	{
	}

	template <typename ANY, Int N> MAXON_IMPLICIT Block(ANY (&array)[N]) : Super(reinterpret_cast<const Char*>(array), N * SIZEOF(ANY), 1)
	{
	}
};


//----------------------------------------------------------------------------------------
/// Converts a C++ fixed-size array to a block.
/// @param[in] array							The array to wrap in a block.
/// @return												A non-strided block which wraps the complete C++ array.
//----------------------------------------------------------------------------------------
template <typename T, Int N> inline Block<T> ToBlock(T (&array)[N])
{
	return Block<T>(array);
}

namespace details
{
template <typename T> struct BlockType
{
	using type = T;
};
template <> struct BlockType<void>
{
	using type = Byte;
};
template <> struct BlockType<const void>
{
	using type = const Byte;
};
}

//----------------------------------------------------------------------------------------
/// Makes a non-strided block from a pointer and a size. This is the same as
/// using the constructor <tt>Block<T>(ptr, size)</tt>, but you save to specify the
/// template argument for the type.
/// @param[in] ptr								Pointer to the first element.
/// @param[in] size								Number of elements.
/// @return												A non-strided block representing @p size elements starting at @p ptr.
//----------------------------------------------------------------------------------------
template <typename T> inline Block<typename maxon::details::BlockType<T>::type> ToBlock(T* ptr, Int size)
{
	return {ptr, size};
}

template <typename T> inline Block<T> ToSingletonBlock(T& value)
{
	return {&value, 1};
}

template <typename T> inline Block<const T> ToSingletonBlock(const T& value)
{
	return {&value, 1};
}


//----------------------------------------------------------------------------------------
/// Makes a strided block from a pointer, a size and a stride. This is the same as
/// using the constructor <tt>StridedBlock<T>(ptr, size, stride)</tt>, but you save to specify the
/// template arguments.
/// @param[in] ptr								Pointer to the first element.
/// @param[in] size								Number of elements.
/// @param[in] stride							Element stride.
/// @return												A strided block representing @p size elements starting at @p ptr with the given @p stride.
//----------------------------------------------------------------------------------------
template <typename T> inline StridedBlock<typename maxon::details::BlockType<T>::type> ToBlock(T* ptr, Int size, Int stride)
{
	return {ptr, size, stride};
}


//----------------------------------------------------------------------------------------
/// Converts a null-terminated C-string to a block. The block contains all characters from the
/// string except the null terminator.
/// @param[in] str								Pointer to the null-terminated C-string, may be nullptr.
/// @return												A non-strided block representing all characters from @p str.
//----------------------------------------------------------------------------------------
inline Block<const Char> CharToBlock(const Char* str)
{
	return {str, str ? (Int)strlen(str) : 0};
}

inline Block<const UChar> CharToBlock(const UChar* str)
{
	return {str, str ? (Int)strlen((Char*)str) : 0};
}

template <Int N> inline Block<const Char> CharToBlock(const Char (&str)[N])
{
	return {str, N - 1};
}

template <Int N> inline Block<const UChar> CharToBlock(const UChar (&str)[N])
{
	return {str, N - 1};
}

template <Int N> inline Block<const Utf32Char> CharToBlock(const Utf32Char (&str)[N])
{
	return {str, N - 1};
}

inline Block<const Char> LiteralId::ToBlock() const
{
	return {_value, GetCStringLength()};
}

//----------------------------------------------------------------------------------------
/// MoveBlock is a type alias for a Block with the MOVE template parameter set to true.
/// MoveBlock can be used for function parameters where the values of the block may be moved
/// to another place by the function.
/// This prevents accidental moves of temporary Blocks (e.g. those returend by ToBlock())
/// which would happen with Block&&.
///
/// @tparam T											Type of elements of the block.
/// @tparam STRIDED								True if a stride other than <tt>SIZEOF(T)</tt> shall be supported.
//----------------------------------------------------------------------------------------
template <typename T, Bool STRIDED = false> using MoveBlock = Block<T, STRIDED, true>;

#ifndef MAXON_COMPILER_GCC
static_assert(std::is_trivially_copyable<Block<Char>>::value, "Block not trivially copyable.");
#endif

//----------------------------------------------------------------------------------------
/// CArray<T, N> wraps a C-style array T[N] in its single member #values, and it has
/// conversion operators to Block. It can be used to specify an argument for a function
/// parameter of Block type directly in the function call as in
/// @code
/// void Func(const Block<const Int>& values);
/// Func(CArray<Int, 3>{{1, 4, 42}});
/// @endcode
/// To automatically determine N from the number of elements you can use the macro MAXON_C_ARRAY.
/// @tparam T											Type of the array elements.
/// @tparam N											Size of the array.
//----------------------------------------------------------------------------------------
template <typename T, Int N> struct CArray
{
	operator Block<T>() const { return Block<T>(values, N); };
	operator Block<typename std::conditional<std::is_const<T>::value, DummyReturnType, const T>::type>() const { return Block<const T>(values, N); };
	operator StridedBlock<T>() const { return StridedBlock<T>(values, N, SIZEOF(T)); };
	operator Block<typename std::conditional<std::is_const<T>::value, DummyReturnType, const T>::type, true>() const { return StridedBlock<const T>(values, N, SIZEOF(T)); };

	T values[N];
};

#define PRIVATE_MAXON_C_ARRAY_B(count, T, ...) maxon::CArray<T, MAXON_EXPAND(count)>{{__VA_ARGS__}}
#define PRIVATE_MAXON_C_ARRAY_A(count, T, ...) PRIVATE_MAXON_C_ARRAY_B(count, T, __VA_ARGS__)

//----------------------------------------------------------------------------------------
/// Returns a CArray of type T. The number of elements is automatically determined.
/// The macro can be used to specify an argument for a function
/// parameter of Block type directly in the function call as in
/// @code
/// void Func(const Block<const Int>& values);
/// Func(MAXON_C_ARRAY(Int, 1, 4, 42));
/// @endcode
/// @param[in] T									Type of the array elements.
/// @param[in] ...								Values for the array elements.
//----------------------------------------------------------------------------------------
#define MAXON_C_ARRAY(T, ...) PRIVATE_MAXON_C_ARRAY_A(MAXON_VA_NARGS(__VA_ARGS__), T, __VA_ARGS__)

/// @}

} // namespace maxon

#endif // BLOCK_H__
