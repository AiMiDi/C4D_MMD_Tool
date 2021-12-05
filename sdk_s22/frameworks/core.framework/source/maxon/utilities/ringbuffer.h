#ifndef RINGBUFFER_H__
#define RINGBUFFER_H__

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Ring buffer array template.
/// This class implements a ring buffer using your preferred ARRAY type.
///
/// @tparam ARRAYTYPE							Type of the array.
/// @tparam RINGSIZE							Maximum number of elements in the ring buffer.
//----------------------------------------------------------------------------------------
template <typename ARRAYTYPE, Int RINGSIZE> class RingBuffer : private ARRAYTYPE
{
	Int _ringPos = 0;

public:
	using T = typename ARRAYTYPE::ValueType;

	using typename ARRAYTYPE::ValueType;

	using ARRAYTYPE::IsEmpty;
	using ARRAYTYPE::IsPopulated;
	using ARRAYTYPE::GetCount;

	template <Bool CONSTITERATOR> class IteratorTemplate;
	using Iterator = IteratorTemplate<false>;
	using ConstIterator = IteratorTemplate<true>;

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the buffer and initializes it with a copy of x.
	/// @param[in] t									Value to be copied.
	/// @return												Element reference or OutOfMemoryError if the initial allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<T> Append(const T& t)
	{
		// fill initial buffer
		if (ARRAYTYPE::GetCount() < RINGSIZE)
			return ARRAYTYPE::Append(t);

		T& storeAt = ARRAYTYPE::operator [](_ringPos);
		storeAt = t;
		_ringPos = (_ringPos + 1) % RINGSIZE;

		return storeAt;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the buffer and moves the content of x to it.
	/// @param[in] t									Value to be moved.
	/// @return												Element reference or OutOfMemoryError if the initial allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<T> Append(T&& t)
	{
		// fill initial buffer
		if (ARRAYTYPE::GetCount() < RINGSIZE)
			return ARRAYTYPE::Append(std::move(t));

		T& storeAt = ARRAYTYPE::operator [](_ringPos);
		storeAt = std::move(t);
		_ringPos = (_ringPos + 1) % RINGSIZE;

		return storeAt;
	}

	//----------------------------------------------------------------------------------------
	/// Appends new elements at the end of the array.
	/// @param[in] values							Initializer list with values to be copied.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultPtr<T> Append(const std::initializer_list<T>& values)
	{
		static_assert(values.size() == 1, "Only one element supported");
		const T* first = values.begin();
		return Append(*first);
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for non-const objects. Index 0 is the oldest entry.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Array element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const T& operator [](Int idx) const
	{
		return ARRAYTYPE::operator []((idx + _ringPos) % RINGSIZE);
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for non-const objects. Index 0 is the oldest entry.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Array element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE T& operator [](Int idx)
	{
		return ARRAYTYPE::operator []((idx + _ringPos) % RINGSIZE);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the first element in the ring buffer (which is different from the first element in the array).
	/// @return												Pointer to the first element (nullptr if the buffer is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const T* GetFirst() const
	{
		if (IsEmpty())
			return nullptr;
		return &(*this)[0];
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the first element in the ring buffer (which is different from the first element in the array).
	/// @return												Pointer to the first element (nullptr if the buffer is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE T* GetFirst()
	{
		if (IsEmpty())
			return nullptr;
		return &(*this)[0];
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the last element in the ring buffer (which is different from the last element in the array).
	/// @return												Pointer to the last element (nullptr if the buffer is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const T* GetLast() const
	{
		if (IsEmpty())
			return nullptr;
		return &(*this)[GetCount() - 1];
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the last element in the ring buffer (which is different from the last element in the array).
	/// @return												Pointer to the last element (nullptr if the buffer is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE T* GetLast()
	{
		if (IsEmpty())
			return nullptr;
		return &(*this)[GetCount() - 1];
	}

	//----------------------------------------------------------------------------------------
	/// Deletes all elements (calls destructors and frees memory).
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		ARRAYTYPE::Reset();
		_ringPos = 0;
	}

	//----------------------------------------------------------------------------------------
	/// Deletes all elements, but doesn't free memory (calls destructors though).
	//----------------------------------------------------------------------------------------
	void Flush()
	{
		ARRAYTYPE::Flush();
		_ringPos = 0;
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the first element.
	/// When you modify the array Begin() will change, it is not a constant value.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		return ConstIterator(*this, 0);
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the first element.
	/// When you modify the array Begin() will change, it is not a constant value.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	Iterator Begin()
	{
		return Iterator(*this, 0);
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the end (End() - 1 is the last element if the array is not empty).
	/// When you modify the array End() will change, it is not a constant value.
	/// @return												Iterator for the array end (this is behind the last element).
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		return ConstIterator(*this, GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the end (End() - 1 is the last element if the array is not empty).
	/// When you modify the array End() will change, it is not a constant value.
	/// @return												Iterator for the array end (this is behind the last element).
	//----------------------------------------------------------------------------------------
	Iterator End()
	{
		return Iterator(*this, GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// The RingBuffer iterator iterates the underlying BaseArray in correct order starting
	/// from _ringPos (for Begin) and might wrap if necessary.
	//----------------------------------------------------------------------------------------
	template <Bool CONSTITERATOR> class IteratorTemplate
	{
	public:
		using CollectionType = typename ConstIf<RingBuffer, CONSTITERATOR>::type;
		using Type = typename ConstIf<T, CONSTITERATOR>::type;
		static const Bool isLinearIterator = false;

		explicit IteratorTemplate(CollectionType& a, Int start = 0) : _array(&a), _index(start)
		{
		}

		IteratorTemplate& operator =(const IteratorTemplate& src)
		{
			_array = src._array;																	// self assignment is no problem here, therefore no check if (this != &src)
			_index = src._index;

			return *this;
		}

#ifdef MAXON_COMPILER_INTEL
	#pragma warning disable 597
#endif
		operator ConstIterator&()
		{
			return *(ConstIterator*) this;
		}
#ifdef MAXON_COMPILER_INTEL
	#pragma warning enable 597
#endif

		//----------------------------------------------------------------------------------------
		/// @return												true if the iterator points to an element.
		//----------------------------------------------------------------------------------------
		explicit operator Bool() const
		{
			return Bool(_array != nullptr);
		}

		Type* GetPtr() const
		{
			return &_array->operator [](_index);
		}

		Type& operator *() const
		{
			return _array->operator [](_index);
		}

		Type* operator ->() const
		{
			return &_array->operator [](_index);
		}

		Bool operator ==(const IteratorTemplate& b) const
		{
			return _index == b._index;
		}

		Bool operator <(const IteratorTemplate& b) const
		{
			return _index < b._index;
		}

		MAXON_OPERATOR_COMPARISON(IteratorTemplate);

		// prefix operator ++ (increment and fetch)
		IteratorTemplate& operator ++()
		{
			++_index;
			return *this;
		}

		// postfix operator ++ (fetch and increment)
		const IteratorTemplate operator ++(int)
		{
			Int index = _index;

			++(*this);

			// use RVO
			return IteratorTemplate(_array, index);
		}

		// operator +=
		IteratorTemplate& operator +=(Int i)
		{
			_index += i;
			return *this;
		}

		// operator +
		IteratorTemplate operator +(Int i) const
		{
			IteratorTemplate tmp = *this;
			tmp += i;
			return tmp;
		}

		// prefix operator -- (decrement and fetch)
		IteratorTemplate& operator --()
		{
			--_index;
			return *this;
		}

		// postfix operator -- (fetch and decrement)
		const IteratorTemplate operator --(int)
		{
			Int index = _index;

			--(*this);

			// use RVO
			return IteratorTemplate(_array, index);
		}

		// operator -=
		IteratorTemplate& operator -=(Int i)
		{
			_index -= i;
			return *this;
		}

		// operator -
		IteratorTemplate operator -(Int i) const
		{
			IteratorTemplate	tmp = *this;
			tmp -= i;
			return tmp;
		}

		Int operator -(const IteratorTemplate& b) const
		{
			return _index - b._index;
		}

	private:
		CollectionType*								_array;
		Int _index;
	};
};


} // namespace maxon

#endif // RINGBUFFER_H__
