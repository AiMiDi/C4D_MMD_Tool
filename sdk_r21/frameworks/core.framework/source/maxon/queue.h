#ifndef QUEUE_H__
#define QUEUE_H__

#include "maxon/apibase.h"
#include "maxon/optional.h"
#include "maxon/algorithms.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// A Queue that holds elements of type T, stored in a circular buffer.
/// Supports access from both ends.
//----------------------------------------------------------------------------------------
template <typename T> class Queue
{
public:
	using ValueType = T;

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// Creates an empty queue.
	//----------------------------------------------------------------------------------------
	Queue() = default;

	//----------------------------------------------------------------------------------------
	/// Deleted copy constructor.
	//----------------------------------------------------------------------------------------
	Queue(const Queue&) = delete;

	//----------------------------------------------------------------------------------------
	/// Deleted copy assignment.
	//----------------------------------------------------------------------------------------
	Queue& operator =(const Queue&) = delete;

	//----------------------------------------------------------------------------------------
	/// Move constructor.
	//----------------------------------------------------------------------------------------
	Queue(Queue&& src) : MAXON_MOVE_MEMBERS(_data, _headIndex, _tailIndex, _count, _capacity)
	{
		src.Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Move assignment.
	//----------------------------------------------------------------------------------------
	Queue& operator =(Queue&& src)
	{
		_data = std::move(_data);

		_headIndex = src._headIndex;
		_tailIndex = src._tailIndex;
		_count = src._count;
		_capacity = src._capacity;

		src._data = nullptr;
		src.Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the number of elements in the queue.
	//----------------------------------------------------------------------------------------
	Int GetCount() const { return _count; }

	//----------------------------------------------------------------------------------------
	/// Checks if the queue contains no elements.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const { return _count == 0; }

	//----------------------------------------------------------------------------------------
	/// Checks if the queue contains any elements.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const { return _count != 0; }

	//----------------------------------------------------------------------------------------
	/// Returns a reference to the element at the front of the queue
	/// without removing it, or NO_VALUE if the queue was empty.
	//----------------------------------------------------------------------------------------
	Optional<T&> Peek()
	{
		if (IsEmpty())
			return NO_VALUE;
		else
			return _data[_tailIndex];
	}

	Optional<const T&> Peek() const
	{
		if (IsEmpty())
			return NO_VALUE;
		else
			return _data[_tailIndex];
	}

	//----------------------------------------------------------------------------------------
	/// Returns a reference to the element at the back of the queue
	/// without removing it, or NO_VALUE if the queue was empty.
	//----------------------------------------------------------------------------------------
	Optional<T&> PeekBack()
	{
		if (IsEmpty())
		{
			return NO_VALUE;
		}
		else
		{
			Int peekIndex = _headIndex;
			DecrementIndex(peekIndex, _capacity);
			return _data[peekIndex];
		}
	}

	Optional<const T&> PeekBack() const
	{
		if (IsEmpty())
		{
			return NO_VALUE;
		}
		else
		{
			Int peekIndex = _headIndex;
			DecrementIndex(peekIndex, _capacity);
			return _data[peekIndex];
		}
	}

	//----------------------------------------------------------------------------------------
	/// Pushes an element to the back of the queue.
	//----------------------------------------------------------------------------------------
	ResultMem Push(T value)
	{
		if (MAXON_UNLIKELY(IsAtFullCapacity()))
		{
			if (! Grow())
				return ResultMem(false);
		}

		PushToHead(std::move(value));
		return ResultMem(true);
	}

	//----------------------------------------------------------------------------------------
	/// Pushes an element to the front of the queue.
	//----------------------------------------------------------------------------------------
	ResultMem PushFront(T value)
	{
		if (MAXON_UNLIKELY(IsAtFullCapacity()))
		{
			if (! Grow())
				return ResultMem(false);
		}

		PushToTail(std::move(value));
		return ResultMem(true);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs an element in-place at the back of the queue with the given arguments as constructor arguments.
	//----------------------------------------------------------------------------------------
	template <typename ... ARGS> ResultMem Emplace(ARGS&& ... args)
	{
		if (MAXON_UNLIKELY(IsAtFullCapacity()))
		{
			if (! Grow())
				return ResultMem(false);
		}

		EmplaceAtHead(std::forward<ARGS>(args) ...);
		return ResultMem(true);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs an element in-place at the front of the queue with the given arguments.
	//----------------------------------------------------------------------------------------
	template <typename ... ARGS> ResultMem EmplaceFront(ARGS&& ... args)
	{
		if (MAXON_UNLIKELY(IsAtFullCapacity()))
		{
			if (! Grow())
				return ResultMem(false);
		}

		EmplaceAtTail(std::forward<ARGS>(args) ...);

		return ResultMem(true);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the element at the front of the queue and removes it, or NO_VALUE if the queue was empty.
	//----------------------------------------------------------------------------------------
	Optional<T> Pop()
	{
		if (IsEmpty())
			return NO_VALUE;
		else
			return PopFromTail();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the element at the back of the queue and removes it, or NO_VALUE if the queue was empty.
	//----------------------------------------------------------------------------------------
	Optional<T> PopBack()
	{
		if (IsEmpty())
			return NO_VALUE;
		else
			return PopFromHead();
	}

	//----------------------------------------------------------------------------------------
	/// Removes the element at the front of the queue without returning it. Returns true if the operation
	/// succeeded, or false if the queue was empty.
	//----------------------------------------------------------------------------------------
	Bool Truncate()
	{
		if (IsEmpty())
			return false;

		TruncateTail();
		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Removes the element at the back of the queue without returning it. Returns true if the operation
	/// succeeded, or false if the queue was empty.
	//----------------------------------------------------------------------------------------
	Bool TruncateBack()
	{
		if (IsEmpty())
			return false;

		TruncateHead();
		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Removes all elements from the queue by calling their destructors, but does not de-allocate the memory yet.
	//----------------------------------------------------------------------------------------
	void Flush()
	{
		T* dataBegin = &_data[0];
		T* dataEnd = &_data[_capacity];

		T* tailPtr = &_data[_tailIndex];
		T* headPtr = &_data[_headIndex];

		// Linear? [__TxxxxH__]
		if (tailPtr < headPtr)
		{
			Destruct(tailPtr, headPtr);
		}
		// Wraps around? [xxH____Txx]
		else if (tailPtr > headPtr)
		{
			Destruct(dataBegin, headPtr);
			Destruct(tailPtr, dataEnd);
		}
		// Full? [xxxxxx]
		else if (_count > 0)
		{
			DebugAssert(_count == _capacity);
			Destruct(dataBegin, dataEnd);
		}

		_tailIndex = 0;
		_headIndex = 0;
		_count = 0;
	}

	//----------------------------------------------------------------------------------------
	/// Removes all elements from the queue by calling their destructors and frees the allocated memory.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		Flush();

		_data = nullptr;
		_capacity = 0;
	}

	//----------------------------------------------------------------------------------------
	/// Linearizes the internal data storage and returns the elements as a block, from front to back.
	//----------------------------------------------------------------------------------------
	Block<T> AlignAsBlock()
	{
		Linearize();
		return Block<T>(_data, _count);
	}

	//----------------------------------------------------------------------------------------
	/// The destructor resets the queue.
	//----------------------------------------------------------------------------------------
	~Queue() { Reset(); }

	//----------------------------------------------------------------------------------------
	/// Copies the queue.
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(const Queue& src)
	{
		iferr_scope;

		if (src.IsPopulated())
		{
			AutoMem<T> newData = NewMem(T, src._capacity) iferr_return;
			src.CopyDataToNewBuffer(newData) iferr_return;
			_data = std::move(newData);
		}

		_headIndex = src._headIndex;
		_tailIndex = src._tailIndex;
		_count = src._count;
		_capacity = src._capacity;

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Ensures that the queue can hold @c requestedSize items without allocating additional memory.
	/// Can be used for optimization to pre-allocate a sufficiently large internal buffer instead of growing on-demand.
	//----------------------------------------------------------------------------------------
	ResultMem EnsureCapacity(Int requestedSize)
	{
		if (requestedSize <= _capacity)
			return ResultMem(true);

		if (!Grow(requestedSize))
			return ResultMem(false);

		return ResultMem(true);
	}

private:
	static const Int GROW_INIT = 4;
	static const Int GROW_FACTOR = 2;

	static MAXON_ATTRIBUTE_FORCE_INLINE void IncrementIndex(Int& index, Int capacity)
	{
		if (MAXON_UNLIKELY(index == capacity - 1))
			index = 0;
		else
			++index;
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE void DecrementIndex(Int& index, Int capacity)
	{
		if (MAXON_UNLIKELY(index == 0))
			index = capacity - 1;
		else
			--index;
	}

	void Linearize()
	{
		// Case 1: Already linear
		if (_tailIndex < _headIndex || _headIndex == 0)
		{
			return;
		}

		T* dataBegin = &_data[0];
		T* dataEnd = &_data[_capacity];

		// Case 2: Wraps around, but no gaps, so we can rotate
		if (IsAtFullCapacity())
		{
			Rotate(dataBegin, dataEnd, &_data[_tailIndex]);

			// Adjust indices
			_headIndex = 0;
			_tailIndex = 0;
			return;
		}

		// Case 3: Wraps around and there's a gap of uninitialized storage between
		// head and tail.
		T* gapBegin = &_data[_headIndex];
		T* gapEnd = &_data[_tailIndex];

		// Reverse elements before gap
		Reverse(dataBegin, gapBegin);

		// Move elements after gap into gap in reverse order
		T* newDataEnd = dataEnd;
		while (true)
		{
			if (gapBegin == gapEnd)
				break;

			if (newDataEnd == gapEnd)
				break;

			--newDataEnd;

			new (gapBegin) T(std::move(*newDataEnd));
			newDataEnd->T::~T();

			++gapBegin;
		}

		// Reverse any remaining elements after gap
		Reverse(gapEnd, newDataEnd);

		// Final reverse (Note: rotate(f, p, l) <=> reverse(f, p); reverse(p, l); reverse(f, l);)
		Reverse(dataBegin, newDataEnd);

		// Adjust indices
		_headIndex = _count;
		_tailIndex = 0;
	}

	Bool IsAtFullCapacity() const { return _count == _capacity; }

	Int CalcNewCapacity(Int targetSize) const
	{
		if (_capacity == 0)
			return GROW_INIT;

		Int newCapacity = _capacity;

		// Always do at least one grow step.
		do
		{
			newCapacity *= GROW_FACTOR;
		}
		while (newCapacity < targetSize);

		return newCapacity;
	}

	Bool Grow(Int targetSize = 0)
	{
		Int newCapacity = CalcNewCapacity(targetSize);

		DebugAssert(newCapacity > 0);
		DebugAssert(newCapacity > _capacity);
		DebugAssert(newCapacity > _count);

		AutoMem<T> newData = NewMem(T, newCapacity).GetValue();
		if (newData == nullptr)
			return false;

		// Move over current data?
		if (IsPopulated())
			MoveDataToNewBuffer(newData);

		_data = std::move(newData);
		_capacity = newCapacity;
		_headIndex = _count;
		_tailIndex = 0;

		return true;
	}

	Result<void> CopyDataToNewBuffer(T* destPtr) const
	{
		iferr_scope;

		DebugAssert(_count > 0);

		const T* tailPtr = &_data[_tailIndex];
		const T* headPtr = &_data[_headIndex];

		// Linear? [__TxxxxH__]
		if (tailPtr < headPtr)
		{
			CopyToUninitialized(tailPtr, headPtr, destPtr) iferr_return;
			Destruct(tailPtr, headPtr);
		}
		// Wraps around? [xxH____Txx]
		else
		{
			const T* dataBegin = &_data[0];
			const T* dataEnd = &_data[_capacity];

			destPtr = CopyToUninitialized(tailPtr, dataEnd, destPtr) iferr_return;
			CopyToUninitialized(dataBegin, headPtr, destPtr) iferr_return;
			Destruct(tailPtr, dataEnd);
			Destruct(dataBegin, headPtr);
		}

		return OK;
	}

	void MoveDataToNewBuffer(T* destPtr)
	{
		DebugAssert(_count > 0);

		T* tailPtr = &_data[_tailIndex];
		T* headPtr = &_data[_headIndex];

		// Linear? [__TxxxxH__]
		if (tailPtr < headPtr)
		{
			MoveToUninitialized<MOVE_MODE::DESTRUCT_SOURCE>(tailPtr, headPtr, destPtr);
		}
		// Wraps around? [xxH____Txx]
		else
		{
			T* dataBegin = &_data[0];
			T* dataEnd = &_data[_capacity];

			destPtr = MoveToUninitialized<MOVE_MODE::DESTRUCT_SOURCE>(tailPtr, dataEnd, destPtr);
			MoveToUninitialized<MOVE_MODE::DESTRUCT_SOURCE>(dataBegin, headPtr, destPtr);
		}
	}

	void PushToHead(T&& value)
	{
		new (&_data[_headIndex]) T(std::move(value));
		IncrementIndex(_headIndex, _capacity);
		++_count;
	}

	void PushToTail(T&& value)
	{
		DecrementIndex(_tailIndex, _capacity);
		new (&_data[_tailIndex]) T(std::move(value));
		++_count;
	}

	template <typename ... ARGS> void EmplaceAtHead(ARGS&& ... args)
	{
		new (&_data[_headIndex]) T(std::forward<ARGS>(args) ...);
		IncrementIndex(_headIndex, _capacity);
		++_count;
	}

	template <typename ... ARGS> void EmplaceAtTail(ARGS&& ... args)
	{
		DecrementIndex(_tailIndex, _capacity);
		new (&_data[_tailIndex]) T(std::forward<ARGS>(args) ...);
		++_count;
	}

	T PopFromTail()
	{
		T result(std::move(_data[_tailIndex]));
		_data[_tailIndex].~T();

		IncrementIndex(_tailIndex, _capacity);

		--_count;
		return result;
	}

	T PopFromHead()
	{
		DecrementIndex(_headIndex, _capacity);

		T result(std::move(_data[_headIndex]));
		_data[_headIndex].~T();

		--_count;
		return result;
	}

	void TruncateTail()
	{
		_data[_tailIndex].~T();
		IncrementIndex(_tailIndex, _capacity);
		--_count;
	}

	void TruncateHead()
	{
		DecrementIndex(_headIndex, _capacity);
		_data[_headIndex].~T();
		--_count;
	}

	AutoMem<T> _data;

	Int		_headIndex = 0;
	Int		_tailIndex = 0;
	Int		_count = 0;
	Int		_capacity = 0;
};

}

#endif // QUEUE_H__
