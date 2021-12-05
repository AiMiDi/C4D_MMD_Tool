#ifndef BASEARRAY_H__
#define BASEARRAY_H__

#include "maxon/defaultallocator.h"
#include "maxon/fixedbufferallocator.h"
#include "maxon/block.h"

/// @file

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

/// Flags for the behaviour of BaseArray when moving objects, can be used to force memcpy/memmove/realloc.
enum class BASEARRAYFLAGS
{
	NONE								= 0,						///< Use constructor/destructor or move operator unless the type is trivially copyable using memcpy, memmove or realloc.
	MOVEANDCOPYOBJECTS	= (1 << 0)			///< Elements are PODs and can be copied using memcpy and moved using memmove/realloc (for Resize, Insert, Erase, Append etc.). Overrides the setting of std::is_trivially_copyable<T>
} MAXON_ENUM_FLAGS(BASEARRAYFLAGS);

static const Int BASEARRAY_DEFAULT_CHUNK_SIZE = 16;

/// @cond INTERNAL

//----------------------------------------------------------------------------------------
/// Utility class that implements MoveFrom(), CopyFrom() and TryRealloc() depending on whether
/// T can be moved or copied byte-wise (using memmove(), memcpy() or realloc()) or the
/// move and copy constructors have to be used to do so.
/// @tparam T											Type of the array elements.
/// @tparam MOVE_AND_COPY_MEMORY	False in this case, T must be moved or copied using move and copy constructors.
//----------------------------------------------------------------------------------------
template <typename T, Bool MOVE_AND_COPY_MEMORY> class BaseArrayUtilities
{
public:
	//----------------------------------------------------------------------------------------
	/// Initializes #initCnt elements with the default value, cannot fail.
	/// @param[in] dst								Pointer to the destination buffer.
	/// @param[in] initCnt						Number of elements to initialize.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_NO_INLINE void Initialize(T* dst, Int initCnt)
	{
		for (; initCnt > 0; initCnt--)
			new (dst++) T();
	}

	//----------------------------------------------------------------------------------------
	/// Destructs #destructCnt elements, cannot fail.
	/// @param[in] dst								Pointer to the destination buffer.
	/// @param[in] destructCnt				Number of elements to destruct.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_NO_INLINE void Destruct(T* dst, Int destructCnt)
	{
		for (Int i = destructCnt - 1; i >= 0; i--)
			dst[i].~T();
	}

	//----------------------------------------------------------------------------------------
	/// Moves objects within the array or from one array to another, cannot fail.
	/// It is assumed that the elements dst points to are not constructed, if dst and src
	/// overlap the elements are moved in the right order.
	/// @param[in] src								Pointer to the source buffer.
	/// @param[in] dst								Pointer to the destination buffer.
	/// @param[in] moveCnt						Number of elements to move.
	//----------------------------------------------------------------------------------------
	static void MoveFrom(T* src, T* dst, Int moveCnt)
	{
		// Do nothing if src equals dst.
		if (src > dst)
		{
			for (Int i = 0; i < moveCnt; i++)
			{
				// Call move constructor if available, otherwise the old element will be copied.
				new (dst) T(std::move(*src));

				// If the move constructor is available the compiler might be able to omit the destructor call.
				src->~T();

				src++;
				dst++;
			}
		}
		else if (src < dst)
		{
			src += moveCnt;
			dst += moveCnt;

			for (Int i = 0; i < moveCnt; i++)
			{
				src--;
				dst--;

				// Call move constructor if available, otherwise the old element will be copied.
				new (dst) T(std::move(*src));

				// If the move constructor is available the compiler might be able to omit the destructor call.
				src->~T();
			}
		}
	}

	//----------------------------------------------------------------------------------------
	/// Copies multiple elements (used by BaseArray::Insert()).
	/// It is assumed that the elements dst points to are not constructed.
	/// @param[in] src								Pointer to the source buffer.
	/// @param[in] dst								Pointer to the destination buffer.
	/// @param[in] copyCnt						Number of elements to copy.
	/// @return												Pointer to the destination (or nullptr if CopyFrom() failed).
	//----------------------------------------------------------------------------------------
	MAXON_WARN_UNUSED static T* CopyFrom(const T* src, T* dst, Int copyCnt)
	{
		for (Int i = 0; i < copyCnt; i++)
		{
			if (NewCopy<T>(dst[i], src[i]) == FAILED)
			{
				// Copy failed: Destruct already copied objects.
				Destruct(dst, i);

				dst = nullptr;
				break;
			}
		}

		return dst;
	}

	//----------------------------------------------------------------------------------------
	/// Tries to reallocate an array buffer of the requested size for PODs or movable data types.
	/// @param[in] a									Allocator.
	/// @param[in] ptr								Pointer to the previous array buffer (or nullptr).
	/// @param[in] s									Requested size of the array buffer.
	/// @param[out] memoryHasBeenMoved	False indicates that ptr is still valid and elements have to be moved to the new array buffer using MoveFrom().
	/// @tparam ALLOCATOR							Class for memory allocation.
	/// @return												Pointer to the new array buffer.
	//----------------------------------------------------------------------------------------
	template <typename ALLOCATOR> MAXON_WARN_UNUSED static T* TryRealloc(ALLOCATOR& a, T* ptr, Int s, Bool& memoryHasBeenMoved)
	{
		memoryHasBeenMoved = false;
		return (T*) a.Alloc(s, MAXON_SOURCE_LOCATION_NAME(T));
	}
};

//----------------------------------------------------------------------------------------
/// T can be moved or copied using memmove() and memcpy().
/// @tparam T											Type of the array elements.
//----------------------------------------------------------------------------------------
template <typename T> class BaseArrayUtilities<T, true>
{
public:
	//----------------------------------------------------------------------------------------
	/// Initializes #initCnt elements with the default value, cannot fail.
	/// @param[in] dst								Pointer to the destination buffer.
	/// @param[in] initCnt						Number of elements to initialize.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE void Initialize(T* dst, Int initCnt)
	{
		// Use memset() for POD types (optimized for larger number of elements).
		if (std::is_pod<T>::value)
		{
			memset(dst, 0, size_t(initCnt * SIZEOF(T)));
		}
		else
		{
			for (; initCnt > 0; initCnt--)
				new (dst++) T();
		}
	}

	//----------------------------------------------------------------------------------------
	/// Destructs #destructCnt elements, cannot fail.
	/// @param[in] dst								Pointer to the destination buffer.
	/// @param[in] destructCnt				Number of elements to destruct.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE void Destruct(T* dst, Int destructCnt)
	{
		// Call the destructor for non-POD types.
		if (std::is_pod<T>::value == false)
		{
			for (Int i = destructCnt - 1; i >= 0; i--)
				dst[i].~T();
		}
	}

	//----------------------------------------------------------------------------------------
	/// Moves objects within the array or from one array to another, cannot fail.
	/// It is assumed that the elements dst points to are not constructed, if dst and src
	/// overlap the elements are moved in the right order.
	/// @param[in] src								Pointer to the source buffer.
	/// @param[in] dst								Pointer to the destination buffer.
	/// @param[in] moveCnt						Number of elements to move.
	//----------------------------------------------------------------------------------------
	static MAXON_ATTRIBUTE_FORCE_INLINE void MoveFrom(T* src, T* dst, Int moveCnt)
	{
		memmove((void*)dst, (void*)src, size_t(moveCnt * SIZEOF(T)));
	}

	//----------------------------------------------------------------------------------------
	/// Copies multiple elements (used by BaseArray::Insert()).
	/// It is assumed that the elements dst points to are not constructed.
	/// @param[in] src								Pointer to the source buffer.
	/// @param[in] dst								Pointer to the destination buffer.
	/// @param[in] copyCnt						Number of elements to copy.
	/// @return												Pointer to the destination (or nullptr if CopyFrom() failed).
	//----------------------------------------------------------------------------------------
	MAXON_WARN_UNUSED static MAXON_ATTRIBUTE_FORCE_INLINE T* CopyFrom(const T* src, T* dst, Int copyCnt)
	{
		return (T*) memcpy((void*)dst, (const void*)src, size_t(copyCnt * SIZEOF(T)));
	}

	//----------------------------------------------------------------------------------------
	/// Tries to reallocate an array buffer of the requested size for PODs or movable data types.
	/// @param[in] a									Allocator.
	/// @param[in] ptr								Pointer to the previous array buffer (or nullptr).
	/// @param[in] s									Requested size of the array buffer.
	/// @param[out] memoryHasBeenMoved	True indicates that data has been moved to the new memory location and ptr is not valid anymore.
	/// @tparam ALLOCATOR							Class for memory allocation.
	/// @return												Pointer to the new array buffer.
	//----------------------------------------------------------------------------------------
	template <typename ALLOCATOR> static MAXON_ATTRIBUTE_FORCE_INLINE T* TryRealloc(ALLOCATOR& a, T* ptr, Int s, Bool& memoryHasBeenMoved)
	{
		memoryHasBeenMoved = true;
		return (T*) a.Realloc(ptr, s, MAXON_SOURCE_LOCATION_NAME(T));
	}
};

//----------------------------------------------------------------------------------------
/// Base class for BaseArray containing all member variables. The allocator contains
/// member variables and this is not a POD.
/// @tparam T											Type of the array elements.
/// @tparam ALLOCATOR							Class for memory allocation.
/// @tparam EMPTY_ALLOCATOR				False in this case.
//----------------------------------------------------------------------------------------
template <typename T, typename ALLOCATOR, Bool EMPTY_ALLOCATOR> class BaseArrayData
{
protected:
	MAXON_ATTRIBUTE_FORCE_INLINE BaseArrayData() : _allocator(), _ptr((T*) this), _cnt(0), _capacity(0) { }
	MAXON_ATTRIBUTE_FORCE_INLINE explicit BaseArrayData(const ALLOCATOR& a) : _allocator(a), _ptr((T*) this), _cnt(0), _capacity(0) { }
	MAXON_ATTRIBUTE_FORCE_INLINE explicit BaseArrayData(ALLOCATOR&& a) : _allocator(std::move(a)), _ptr((T*) this), _cnt(0), _capacity(0) { }
	MAXON_ATTRIBUTE_FORCE_INLINE BaseArrayData(BaseArrayData&& src) : MAXON_MOVE_MEMBERS(_allocator, _ptr, _cnt, _capacity)
	{
		// Use dummy pointer if the array has no capacity.
		if (_capacity == 0)
			_ptr = (T*) this;

		src._ptr = (T*) &src;
		src._cnt = 0;
		src._capacity = 0;
	}

	ALLOCATOR _allocator;
	T*	_ptr;																									// Pointer to a memory block (or a dummy pointer if _capacity equals 0).
	Int _cnt;																									// Number of used array elements.
	Int _capacity;																						// Number of allocated array elements.
};

//----------------------------------------------------------------------------------------
/// Base class for BaseArray with special support for moving FixedBufferAllocators.
/// This is not a POD.
/// @tparam T											Type of the array elements.
/// @tparam COUNT									Number of elements to be reserved by the FixedBufferAllocator
/// @tparam PARENT_ALLOCATOR			Fallback allocator if the number of elements exceeds the reserved count.
//----------------------------------------------------------------------------------------
template <typename T, Int COUNT, typename PARENT_ALLOCATOR, Bool SINGLE_ALLOCATION>  class BaseArrayData<T, FixedBufferAllocator<T, COUNT, PARENT_ALLOCATOR, SINGLE_ALLOCATION>, false>
{
protected:
	using ALLOCATOR = FixedBufferAllocator<T, COUNT, PARENT_ALLOCATOR, SINGLE_ALLOCATION>;
	MAXON_ATTRIBUTE_FORCE_INLINE BaseArrayData() : _allocator(), _ptr((T*) this), _cnt(0), _capacity(0) { }
	MAXON_ATTRIBUTE_FORCE_INLINE explicit BaseArrayData(const ALLOCATOR& a) : _allocator(a), _ptr((T*) this), _cnt(0), _capacity(0) { }
	MAXON_ATTRIBUTE_FORCE_INLINE explicit BaseArrayData(ALLOCATOR&& a) : _allocator(std::move(a)), _ptr((T*) this), _cnt(0), _capacity(0) {  }
	MAXON_ATTRIBUTE_FORCE_INLINE BaseArrayData(BaseArrayData&& src) : MAXON_MOVE_MEMBERS(_ptr, _cnt, _capacity)
	{
		// Use dummy pointer if the array has no capacity.
		if (_capacity == 0)
			_ptr = (T*) this;

		// If the static buffer of the allocator was used the content must be moved.
		if (src._allocator.IsCompatibleWithDefaultAllocator(src._ptr) == false)
		{
			using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value /*|| MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS*/>;

			_ptr = (T*) _allocator.Alloc(SIZEOF(T) * _cnt, MAXON_SOURCE_LOCATION);
			DebugAssert(_ptr != nullptr, "FixedBufferAllocator is broken.");
			Utilities::MoveFrom(src._ptr, _ptr, _cnt);
		}

		src._ptr = (T*) &src;
		src._cnt = 0;
		src._capacity = 0;
	}

	ALLOCATOR _allocator;
	T*	_ptr;																									// Pointer to a memory block (or a dummy pointer if _capacity equals 0).
	Int _cnt;																									// Number of used array elements.
	Int _capacity;																						// Number of allocated array elements.
};

//----------------------------------------------------------------------------------------
/// POD base class for BaseArray containing all member variables. The allocator is empty.
/// Uses a union of (empty) allocator and element pointer for minimal memory usage.
/// @tparam T											Type of the array elements.
/// @tparam ALLOCATOR							Class for memory allocation.
//----------------------------------------------------------------------------------------
template <typename T, typename ALLOCATOR> class BaseArrayData<T, ALLOCATOR, true>
{
protected:
	MAXON_ATTRIBUTE_FORCE_INLINE BaseArrayData() : _ptr((T*) this), _cnt(0), _capacity(0) { }
	MAXON_ATTRIBUTE_FORCE_INLINE BaseArrayData(BaseArrayData&& src) : _ptr(src._ptr), _cnt(src._cnt), _capacity(src._capacity)
	{
		// Use dummy pointer if the array has no capacity.
		if (_capacity == 0)
			_ptr = (T*) this;

		src._ptr = (T*) &src;
		src._cnt = 0;
		src._capacity = 0;
	}

	union
	{
		T*	_ptr;																								// Pointer to a memory block (or a dummy pointer if _capacity equals 0).
		ALLOCATOR _allocator;
	};
	Int _cnt;																									// Number of used array elements.
	Int _capacity;																						// Number of allocated array elements.
};

/// @endcond

//----------------------------------------------------------------------------------------
/// Basic array template.
/// The array consists of one contiguous block of memory. The block will have a minimum
/// size of MINCHUNKSIZE elements of type T as soon as the first element is added.
///
/// The elements may be copied and change their memory address when the array grows. If
/// your objects cannot be copied or need a constant address use the BlockArray template.
///
/// If you need a specific alignment you may have to use a non-default allocator. See
/// defaultallocator.h for alignment and grow rate behaviour details.
///
/// Please note that in a C++11 range based for loop you may not call a non-const method
/// that modifies the range (e.g. Erase) - it does not work because the loop does not
/// expect the range to change. Use the Iterable::EraseIterator in that case.
///
/// @note The 'Base' in BaseArray doesn't indicate that you should inherit from this class -
/// it's just the most basic array template which is used as foundation by many other array
/// templates and collections as well. The intended usage is simply
/// @code
/// BaseArray<MyDataType> myArray;
/// @endcode
///
/// Performance characteristics:
/// Random access to array elements is constant: O(1).
/// Append or Pop (erase the last) an element is amortized constant: O(1)
/// Insert or Erase an element is linear with the number of elements which have to be moved (with n elements until the array end): O(n)
/// @note: Do not rely on the characteristics to pick the right type of collection. Always profile!
///
/// @tparam T											Type of the array elements.
/// @tparam MINCHUNKSIZE					The minimum number of elements upon array creation.
/// @tparam MEMFLAGS							Use BASEARRAYFLAGS::NONE unless you know the object can be moved and/or copied.
/// @tparam ALLOCATOR							Class for memory allocation.
///
/// @note Note that the array element class has special requirements regarding @link movecopy copy and move constructors @endlink.
/// @see @$ref arrays
//----------------------------------------------------------------------------------------
template <typename T, Int MINCHUNKSIZE = BASEARRAY_DEFAULT_CHUNK_SIZE, BASEARRAYFLAGS MEMFLAGS = BASEARRAYFLAGS::NONE, typename ALLOCATOR = DefaultAllocator> class BaseArray
	: public ArrayBase<BaseArray<T, MINCHUNKSIZE, MEMFLAGS, ALLOCATOR>, T, BaseArrayData<T, ALLOCATOR, std::is_empty<ALLOCATOR>::value>, DefaultCompare>
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(BaseArray);

public:
	using AllocatorType = ALLOCATOR;

	/// Iterator allows read and write access to array elements
	using Iterator = BaseIterator<BaseArray, false>;

	/// Iterator for read-only access to array elements
	using ConstIterator = BaseIterator<const BaseArray, false>;

	using Super = ArrayBase<BaseArray<T, MINCHUNKSIZE, MEMFLAGS, ALLOCATOR>, T, BaseArrayData<T, ALLOCATOR, std::is_empty<ALLOCATOR>::value>, DefaultCompare>;

	//----------------------------------------------------------------------------------------
	/// Default constructor. Creates an empty arry.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE BaseArray() : Super() { }

	//----------------------------------------------------------------------------------------
	/// This constructor has to be used if an array should use a custom allocator with member variables.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit BaseArray(const ALLOCATOR& a) : Super(a) { }

	//----------------------------------------------------------------------------------------
	/// This constructor has to be used if an array should move a custom allocator with member variables.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit BaseArray(ALLOCATOR&& a) : Super(std::move(a)) { }

	//----------------------------------------------------------------------------------------
	/// Destructs the array with all its elements.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ~BaseArray()
	{
		Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Move constructor.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE BaseArray(BaseArray&& src) : Super(std::move(src)) { }

	//----------------------------------------------------------------------------------------
	/// Move assignment operator.
	//----------------------------------------------------------------------------------------
	MAXON_OPERATOR_MOVE_ASSIGNMENT(BaseArray);

	//----------------------------------------------------------------------------------------
	/// Returns a Block<const T> which represents the elements of the array.
	/// @return												The content of this array as a block.
	//----------------------------------------------------------------------------------------
	const Block<const T>& ToBlock() const
	{
		static_assert(offsetof(BaseArray, _ptr) + SIZEOF(void*) == offsetof(BaseArray, _cnt), "Invalid BaseArray layout, it has to be compatible with Block.");
		return reinterpret_cast<const Block<const T>&>(_ptr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a Block<T> which represents the elements of the array.
	/// @return												The content of this array as a block.
	//----------------------------------------------------------------------------------------
	const Block<T>& ToBlock()
	{
		return reinterpret_cast<const Block<T>&>(static_cast<const BaseArray*>(this)->ToBlock());
	}

	//----------------------------------------------------------------------------------------
	/// Converts this BaseArray to a Block<const T> which represents the elements of the array.
	/// @return												The content of this array as a block.
	//----------------------------------------------------------------------------------------
	operator const Block<const T>&() const
	{
		return ToBlock();
	}

	//----------------------------------------------------------------------------------------
	/// Converts this BaseArray to a Block<T> which represents the elements of the array.
	/// @return												The content of this array as a block.
	//----------------------------------------------------------------------------------------
	operator const Block<T>&()
	{
		return ToBlock();
	}

	//----------------------------------------------------------------------------------------
	/// Converts this BaseArray to a StridedBlock<const T> which represents the elements of the array.
	/// The block will have the natural stride of T.
	/// @return												The content of this array as a strided block.
	//----------------------------------------------------------------------------------------
	operator StridedBlock<const T>() const
	{
		return StridedBlock<const T>(_ptr, _cnt, SIZEOF(T));
	}

	//----------------------------------------------------------------------------------------
	/// Converts this BaseArray to a StridedBlock<T> which represents the elements of the array.
	/// The block will have the natural stride of T.
	/// @return												The content of this array as a strided block.
	//----------------------------------------------------------------------------------------
	operator StridedBlock<T>()
	{
		return StridedBlock<T>(_ptr, _cnt, SIZEOF(T));
	}

	//----------------------------------------------------------------------------------------
	/// Operator for passing a BaseArray to a Block<const Byte> which represents the raw bytes of the array.
	/// This operator is only supported when T is a scalar type.
	/// @return												The content of this array as a raw Byte block.
	//----------------------------------------------------------------------------------------
	template <typename DUMMY = T, typename = typename std::enable_if<std::is_scalar<DUMMY>::value>::type> operator Block<const Byte>() const
	{
		return ToBlock();
	}

	//----------------------------------------------------------------------------------------
	/// Operator for passing a BaseArray to a Block<Byte> which represents the raw bytes of the array.
	/// This operator is only supported when T is a scalar type.
	/// @return												The content of this array as a raw Byte block.
	//----------------------------------------------------------------------------------------
	template <typename DUMMY = T, typename = typename std::enable_if<std::is_scalar<DUMMY>::value>::type> operator Block<Byte>()
	{
		return ToBlock();
	}

	//----------------------------------------------------------------------------------------
	/// Deletes all elements (calls destructors and frees memory).
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		if (_capacity > 0)
		{
			using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;
			Utilities::Destruct(_ptr, _cnt);

			_allocator.Free(_ptr);
			_ptr = (T*) this;
		}
		_capacity = 0;
		_cnt = 0;
	}

	//----------------------------------------------------------------------------------------
	/// Deletes all elements, but doesn't free memory (calls destructors though).
	//----------------------------------------------------------------------------------------
	void Flush()
	{
		if (_cnt > 0)
		{
			using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;
			Utilities::Destruct(_ptr, _cnt);
		}

		_cnt = 0;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the number of array elements.
	/// @return												Number of array elements.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Int GetCount() const
	{
		return _cnt;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the number of elements for which memory has been allocated (this is usually bigger
	/// than GetCount()).
	/// @return												Number of array elements for which memory has been allocated.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Int GetCapacityCount() const
	{
		return _capacity;
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for const objects.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Array element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const T& operator [](Int idx) const
	{
		DebugAssert(UInt(idx) < UInt(_cnt));
		return _ptr[idx];
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for non-const objects.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Array element.
	//----------------------------------------------------------------------------------------
	// this is duplicate code but casting constness away for this case is plain ugly
	MAXON_ATTRIBUTE_FORCE_INLINE T& operator [](Int idx)
	{
		DebugAssert(UInt(idx) < UInt(_cnt));
		return _ptr[idx];
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> Append()
	{
		// Increase memory block size if capacity is too small.
		if (MAXON_UNLIKELY(_cnt >= _capacity))
		{
			if (MAXON_UNLIKELY(IncreaseCapacity() == nullptr))
				return nullptr;
		}

		return new (_ptr + _cnt++) T();
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array and initializes it with a copy of x.
	/// @param[in] x									Value to be copied.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> Append(const T& x)
	{
		// Increase memory block size if capacity is too small.
		if (MAXON_UNLIKELY(_cnt >= _capacity))
		{
			if (MAXON_UNLIKELY(IncreaseCapacity() == nullptr))
				return nullptr;
		}

		T* element = _ptr + _cnt++;
		if ((NewCopy(*element, x) == FAILED) && TestForCopyFromMember<T>::isSupported)
		{
			// CopyFrom() failed: Correct counter (compiler will only generate code for types supporting CopyFrom).
			_cnt--;
			return nullptr;
		}

		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array and moves the content of x to it.
	/// @param[in] x									Value to be moved.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> Append(T&& x)
	{
		// Increase memory block size if capacity is too small.
		if (MAXON_UNLIKELY(_cnt >= _capacity))
		{
			if (MAXON_UNLIKELY(IncreaseCapacity() == nullptr))
				return nullptr;
		}

		return new (_ptr + _cnt++) T(std::move(x));
	}

	//----------------------------------------------------------------------------------------
	/// Appends new elements at the end of the array.
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultPtr<T> Append(const Block<const T>& values)
	{
		T* element = IncreaseCapacity(values.GetCount());
		if (MAXON_LIKELY(element != nullptr))
		{
			// Increase counter.
			_cnt += values.GetCount();

			// Check if the block contains data (otherwise the array size is increased and element points to memory which has to be initialized by the caller).
			if (values.GetFirst())
			{
				using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;
				element = Utilities::CopyFrom(values.GetFirst(), element, values.GetCount());

				// Correct counter if CopyFrom failed.
				if (TestForCopyFromMember<T>::isSupported && element == nullptr)
					_cnt -= values.GetCount();
			}
		}
		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Appends new elements at the end of the array.
	/// @param[in] values							Block with values to be moved (a MoveBlock must be used to prevent accidental moves of temporary Blocks).
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Append(const MoveBlock<T>& values)
	{
		T* element = IncreaseCapacity(values.GetCount());
		if (MAXON_LIKELY(element != nullptr))
		{
			// Increase counter.
			_cnt += values.GetCount();

			// Check if the block contains data (otherwise the array size is increased and element points to memory which has to be initialized by the caller).
			if (values.GetFirst())
			{
				using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;
				Utilities::MoveFrom(values.GetFirst(), element, values.GetCount());
			}
		}

		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Appends new elements at the end of the array.
	/// @param[in] values							Initializer list with values to be copied.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultPtr<T> Append(const std::initializer_list<T>& values)
	{
		const T* first = values.begin();
		const T* last = values.end();
		Int cnt = last - first;
		return Append(Block<const T>(first, cnt));
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new default element at index position.
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> Insert(Int position)
	{
		T* element = InsertWithoutConstructor(position);
		if (MAXON_LIKELY(element != nullptr))
			new (element) T();
		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new default element at iterator position.
	/// @param[in] position						Insert position.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultMemT<Iterator> Insert(Iterator position)
	{
		return Iterator(Insert(position - Begin()).GetPointer());
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at index position and initializes it with a copy of x.
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] x									Value to be copied.
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> Insert(Int position, const T& x)
	{
		T* element = InsertWithoutConstructor(position);
		if (element)
		{
			if ((NewCopy(*element, x) == FAILED) && TestForCopyFromMember<T>::isSupported)
			{
				using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;
				// CopyFrom() failed: Correct counter and move elements back (compiler will only generate code for types supporting CopyFrom).
				_cnt--;
				Utilities::MoveFrom(element + 1, element, _cnt - position);
				return nullptr;
			}
		}
		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at iterator position and initializes it with a copy of x.
	/// @param[in] position						Insert position.
	/// @param[in] x									Value to be copied.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultMemT<Iterator> Insert(Iterator position, const T& x)
	{
		return Iterator(Insert(position - Begin(), x).GetPointer());
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at index position and moves the content of x to it.
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] x									Value to be moved.
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> Insert(Int position, T&& x)
	{
		T* element = InsertWithoutConstructor(position);
		if (MAXON_LIKELY(element != nullptr))
			new (element) T(std::move(x));
		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at iterator position and moves the content of x to it.
	/// @param[in] position						Insert position.
	/// @param[in] x									Value to be moved.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultMemT<Iterator> Insert(Iterator position, T&& x)
	{
		return Iterator(Insert(position - Begin(), std::move(x)).GetPointer());
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at index position (all elements from @p position on are moved by the the count of @p values).
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Insert(Int position, const Block<const T>& values)
	{
		T* element = InsertWithoutConstructor(position, values.GetCount());
		if (MAXON_LIKELY(element != nullptr))
		{
			// Check if the block contains data (otherwise the array size is increased and element points to memory which has to be initialized by the caller).
			if (values.GetFirst())
			{
				using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;
				element = Utilities::CopyFrom(values.GetFirst(), element, values.GetCount());

				// If CopyFrom() failed (element is nullptr) correct counter and move elements back.
				if (TestForCopyFromMember<T>::isSupported && element == nullptr)
				{
					_cnt -= values.GetCount();
					Utilities::MoveFrom(_ptr + position + values.GetCount(), _ptr + position, _cnt - position);
				}
			}
		}
		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at index position (all elements from @p position on are moved by the the count of @p values).
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] values							Initializer list with values to be copied.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Insert(Int position, const std::initializer_list<T>& values)
	{
		const T* first = values.begin();
		const T* last = values.end();
		Int cnt = last - first;
		return Insert(position, Block<const T>(first, cnt));
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at index position (all elements from @p position on are moved by the the count of @p values).
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] values							Block with values to be moved (a MoveBlock must be used to prevent accidental moves of temporary Blocks).
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Insert(Int position, const MoveBlock<T>& values)
	{
		T* element = InsertWithoutConstructor(position, values.GetCount());
		if (MAXON_LIKELY(element != nullptr))
		{
			// Check if the block contains data (otherwise the array size is increased and element points to memory which has to be initialized by the caller).
			if (values.GetFirst())
			{
				using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;
				Utilities::MoveFrom(values.GetFirst(), element, values.GetCount());
			}
		}
		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at iterator position (all elements from @p position on are moved by the the count of @p values).
	/// @param[in] position						Insert position.
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(Iterator position, const Block<const T>& values)
	{
		return Iterator(Insert(position - Begin(), values).GetPointer());
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at iterator position (all elements from @p position on are moved by the the count of @p values).
	/// @param[in] position						Insert position.
	/// @param[in] values							Initializer list with values to be copied.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(Iterator position, const std::initializer_list<T>& values)
	{
		return Iterator(Insert(position - Begin(), values).GetPointer());
	}

	//----------------------------------------------------------------------------------------
	/// Erases (removes and deletes) elements.
	/// @param[in] position						Erase index (Erase() will fail if out of bounds and return nullptr).
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) a nullptr will be returned.
	/// @return												Pointer to the element that is now at position. If position equals the number of elements after Erase() a valid pointer is returned but you are not allowed to access it. OutOfMemoryError is only returned on failure (position was out of bounds).
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Erase(Int position, Int eraseCnt = 1)
	{
		using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;
		T*	element = _ptr + position;
		Int availableCnt = _cnt - position;

		if (MAXON_UNLIKELY(UInt(position) > UInt(_cnt)))
		{
			DebugStop("The position is invalid.");
			return nullptr;
		}

		if (MAXON_UNLIKELY(UInt(availableCnt) < UInt(eraseCnt)))
		{
			DebugStop("You are trying to erase more elements than available.");
			return nullptr;
		}

		// Destruct elements because MoveFrom() assumes its destination does not contain constructed elements.
		Utilities::Destruct(element, eraseCnt);

		// Move the remaining elements.
		Utilities::MoveFrom(element + eraseCnt, element, availableCnt - eraseCnt);
		_cnt -= eraseCnt;

		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Erases (removes and deletes) elements.
	/// @param[in] position						Erase position.
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) an invalid iterator will be returned.
	/// @return												Iterator for the element that is now at position (its operator Bool() will return false if something failed).
	//----------------------------------------------------------------------------------------
	Iterator Erase(Iterator position, Int eraseCnt = 1)
	{
		using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;
		T*	element = position.GetPtr();
		Int idx = position - Begin();
		Int availableCnt = _cnt - idx;

		if (MAXON_UNLIKELY(UInt(availableCnt) < UInt(eraseCnt)))
		{
			DebugStop("You are trying to erase more elements than available.");
			return Iterator();
		}

		// Destruct elements because MoveFrom() assumes its destination does not contain constructed elements.
		Utilities::Destruct(element, eraseCnt);

		// Move the remaining elements.
		Utilities::MoveFrom(element + eraseCnt, element, availableCnt - eraseCnt);
		_cnt -= eraseCnt;

		return position;
	}

	//----------------------------------------------------------------------------------------
	/// Erases elements within the array and moves elements from the end to the erased gap.
	/// This is generally faster than Erase() because at most eraseCnt elements have to be moved,
	/// but it changes the order of elements.
	/// @param[in] position						Erase index (SwapErase() will fail if out of bounds and return nullptr).
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) false will be returned.
	/// @return												OK on success, FAILED if position was out of bounds.
	//----------------------------------------------------------------------------------------
	ResultMem SwapErase(Int position, Int eraseCnt = 1)
	{
		using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;
		T* start = _ptr + position;
		Int availableCnt = _cnt - position;

		if (MAXON_UNLIKELY(UInt(position) > UInt(_cnt)))
		{
			DebugStop("The position is invalid.");
			return FAILED;
		}

		if (MAXON_UNLIKELY(UInt(availableCnt) < UInt(eraseCnt)))
		{
			DebugStop("You are trying to erase more elements than available.");
			return FAILED;
		}

		// Destruct elements because MoveFrom() assumes its destination does not contain constructed elements.
		Utilities::Destruct(start, eraseCnt);

		// Move up to eraseCnt elements from the end into the gap.
		Int moveStartIdx = Max<Int>(_cnt - eraseCnt, position + eraseCnt);
		Utilities::MoveFrom(_ptr + moveStartIdx, start, _cnt - moveStartIdx);
		_cnt -= eraseCnt;

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Erases elements within the array and moves elements from the end to the erased gap.
	/// This is generally faster than Erase() because at most eraseCnt elements have to be moved,
	/// but it changes the order of elements.
	/// @param[in] position						Erase position.
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) an invalid iterator will be returned.
	/// @return												Iterator for the element that is now at position (its operator Bool() will return false if something failed).
	//----------------------------------------------------------------------------------------
	Iterator SwapErase(Iterator position, Int eraseCnt = 1)
	{
		if (SwapErase(position - Begin(), eraseCnt) == FAILED)
			return Iterator();

		return position;
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element index.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start index of the block. The requested element can be found within the block at @p position - start index.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE Int GetBlock(Int position, Block<const T, STRIDED>& block) const
	{
		block.Set(_ptr, _cnt, SIZEOF(T));
		return 0;
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element index.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start index of the block. The requested element can be found within the block at @p position - start index.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE Int GetBlock(Int position, Block<T, STRIDED>& block)
	{
		block.Set(_ptr, _cnt, SIZEOF(T));
		return 0;
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element position.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start iterator of the block. The requested element can be found within the block at index @p position - start iterator.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE ConstIterator GetBlock(ConstIterator position, Block<const T, STRIDED>& block) const
	{
		block.Set(_ptr, _cnt, SIZEOF(T));
		return Begin();
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element position.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start iterator of the block. The requested element can be found within the block at index @p position - start iterator.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE Iterator GetBlock(Iterator position, Block<T, STRIDED>& block)
	{
		block.Set(_ptr, _cnt, SIZEOF(T));
		return Begin();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the first element of the array.
	/// For the BaseArray this is a pointer to a continuous block of memory which contains all
	/// elements of the array. You can use it for operations like writing to a stream or copying
	/// or moving memory up to the number of allocated elements.
	/// @return												Pointer to the first element (nullptr if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const T* GetFirst() const
	{
		return (_cnt > 0) ? _ptr : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the first element of the array.
	/// For the BaseArray this is a pointer to a continuous block of memory which contains all
	/// elements of the array. You can use it for operations like reading from a stream or copying
	/// or moving memory up to the number of allocated elements.
	/// @return												Pointer to the first element (nullptr if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE T* GetFirst()
	{
		return (_cnt > 0) ? _ptr : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the last element of the array.
	/// @return												Pointer to the last element (nullptr if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const T* GetLast() const
	{
		return (_cnt > 0) ? _ptr + _cnt - 1 : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the last element of the array.
	/// @return												Pointer to the last element (nullptr if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE T* GetLast()
	{
		return (_cnt > 0) ? _ptr + _cnt - 1 : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Resizes the array to contain newCnt elements.
	/// If newCnt is smaller than GetCount() all extra elements are being deleted. If it is
	/// greater the array is expanded and the default constructor is called for new elements.
	/// @param[in] newCnt							New array size.
	/// @param[in] resizeFlags				See COLLECTION_RESIZE_FLAGS.
	/// @return												FAILED if allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Resize(Int newCnt, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::DEFAULT)
	{
		using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;
		Int	increment = newCnt - _cnt;
		T* element = _ptr + _cnt;

		// Decrease array size (or fit to size if equal) when newCnt is equal or smaller.
		if (increment <= 0)
		{
			if (newCnt >= 0)
			{
				Utilities::Destruct(element + increment, -increment);

				_cnt = newCnt;

				// Try to shrink the memory block, if it fails it doesn't matter.
				if ((resizeFlags & COLLECTION_RESIZE_FLAGS::ON_SHRINK_FIT_TO_SIZE) != COLLECTION_RESIZE_FLAGS::NONE)
				{
					if (FitToSize(newCnt) == FAILED)
					{
						// FitToSize is allowed to fail here. No need to return an error.
					}
				}
			}
			else
			{
				DebugStop("Invalid array size specified.");
			}
		}
		else
		{
			// Increase memory block size if necessary.
			if (newCnt > _capacity)
			{
				Int	 totalCapacity = newCnt;
				Bool memoryHasBeenMoved;

				if ((resizeFlags & COLLECTION_RESIZE_FLAGS::ON_GROW_FIT_TO_SIZE) == COLLECTION_RESIZE_FLAGS::NONE)
					totalCapacity = _allocator.ComputeArraySize(_capacity, increment, MINCHUNKSIZE);

				element = Utilities::TryRealloc(GetAllocator(), _capacity > 0 ? _ptr : nullptr, totalCapacity * SIZEOF(T), memoryHasBeenMoved);
				if (element)
				{
					// Move elements to new memory block if a new memory block was allocated (no realloc).
					if (memoryHasBeenMoved == false && _capacity > 0)
					{
						// If the FixedBufferAllocator is used it might return the already used pointer because the buffer is big enough and the elements don't have to be moved.
						if ((std::is_base_of<FixedBufferAllocatorBase, ALLOCATOR>::value == false) || (element != _ptr))
						{
							Utilities::MoveFrom(_ptr, element, _cnt);
							_allocator.Free(_ptr);
						}
					}
					_ptr = element;
					_capacity = totalCapacity;
					element += _cnt;
				}
			}

			if (element)
			{
				// By default initialize the elements unless the caller has opted out.
				if ((resizeFlags & COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) == COLLECTION_RESIZE_FLAGS::NONE)
					Utilities::Initialize(element, increment);

				_cnt = newCnt;
			}
		}

		return ResultMem(_cnt == newCnt);
	}

	//----------------------------------------------------------------------------------------
	/// Deletes the last element.
	/// @param[out] dst								Nullptr or pointer to return value.
	/// @return												True if there was at least one element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool Pop(T* dst = nullptr)
	{
		if (_cnt > 0)
		{
			_cnt--;
			if (dst)
				*dst = std::move(_ptr[_cnt]);

			_ptr[_cnt].~T();
			return true;
		}
		return false;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the index of the element. The element must be part of the array, otherwise (e.g.
	/// if x is a copy of an array element) InvalidArrayIndex will be returned.
	/// @return												Index of element or InvalidArrayIndex (not element of this).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Int GetIndex(const T& x) const
	{
		if ((&x >= _ptr) && (&x < _ptr + GetCount()))
			return Int(&x - _ptr);

		return InvalidArrayIndex;
	}

	//----------------------------------------------------------------------------------------
	/// Increases the internal capacity of this array (if necessary) so that it can hold at least
	/// the given number of elements without further memory allocations.
	/// @param[in] requestedCapacity	The desired internal capacity.
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												FAILED if allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem EnsureCapacity(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		Int	increment = requestedCapacity - _cnt;

		// Increase array size if requested capacity is bigger.
		if (increment > 0)
		{
			if (IncreaseCapacity(increment, resizeFlags) == nullptr)
				return FAILED;
		}
		else if (resizeFlags & COLLECTION_RESIZE_FLAGS::ON_SHRINK_FIT_TO_SIZE)
		{
			return FitToSize(requestedCapacity);
		}
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Prepares the internal buffer(s) to hold at least the given number of elements with
	/// as few further memory allocations as possible.
	/// @note This is just a hint. It does not guarantee that the collection will be able
	/// to store the number of indicated elements. Only for a BaseArray, this does the same
	/// as EnsureCapacity().
	/// @param[in] requestedCapacity	The desired internal capacity.
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												FAILED if allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		return EnsureCapacity(requestedCapacity, resizeFlags);
	}

	//----------------------------------------------------------------------------------------
	/// Specialization of AppendAllImpl, used by BaseCollection::AppendAll.
	/// @private
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> Result<void> AppendAllImpl(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags, Bool overwrite, OverloadRank0)
	{
		if (maxon::IsCollection<COLLECTION2>::value)
		{
			Int cnt = maxon::GetCount(other);
			DebugAssert(cnt >= 0);
			if (EnsureCapacity(GetCount() + cnt, resizeFlags) == FAILED)
				return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);

			T* element = _ptr + GetCount();
			for (auto&& i : std::forward<COLLECTION2>(other))
			{
				Result<void> res = NewCopy<T>(*element, ValueForward<COLLECTION2>(i));
				if (res == FAILED)
					return res;
				++element;
				++_cnt;
				DebugAssert(--cnt >= 0);
			}
		}
		else
		{
			for (auto&& i : std::forward<COLLECTION2>(other))
			{
				if (Append(ValueForward<COLLECTION2>(i)) == FAILED)
					return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
			}
		}
		return OK;
	}

	using Super::CopyFromImpl;

	//----------------------------------------------------------------------------------------
	/// Specialization of CopyFromImpl for a BaseArray source, used by BaseCollection::CopyFrom.
	/// @private
	//----------------------------------------------------------------------------------------
	template<typename BASEARRAY, typename = typename std::enable_if<std::is_same<typename std::decay<BASEARRAY>::type, BaseArray>::value>::type>
	Result<void> CopyFromImpl(BASEARRAY&& src, COLLECTION_RESIZE_FLAGS resizeFlags, OverloadRank4)
	{
		// Avoid copying yourself.
		if (&src != this)
		{
			using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;

			Flush();
			if ((EnsureCapacity(src._cnt, resizeFlags) == OK) && (Utilities::CopyFrom(src._ptr, _ptr, src._cnt) != nullptr))
			{
				_cnt = src._cnt;
			}
		}
		if (_cnt != src._cnt)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Specialization of CopyFromImpl for a Block source, used by BaseCollection::CopyFrom.
	/// @private
	//----------------------------------------------------------------------------------------
	template<typename BLOCK, typename = typename std::enable_if<std::is_same<typename std::decay<BLOCK>::type, Block<T>>::value>::type>
	Result<void> CopyFromImpl(BLOCK&& src, COLLECTION_RESIZE_FLAGS resizeFlags, OverloadRank3)
	{
		// Avoid copying yourself.
		if (src.GetFirst() != GetFirst())
		{
			using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;

			Flush();
			if ((EnsureCapacity(src.GetCount(), resizeFlags) == OK) && (Utilities::CopyFrom(src.GetFirst(), _ptr, src.GetCount()) != nullptr))
			{
				_cnt = src.GetCount();
			}
		}
		if (_cnt != src.GetCount())
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Swaps elements a and b (equivalent to global Swap(array[a], array[b]).
	/// @param[in] a									Position of element to be swapped.
	/// @param[in] b									Position of element to be swapped.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void Swap(Iterator a, Iterator b)
	{
		maxon::Swap(*a, *b);
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the memory usage for this array.
	/// The array element class must have a public member GetMemorySize that returns an element's size.
	/// @return												Memory size in bytes.
	//----------------------------------------------------------------------------------------
	Int GetMemorySize() const
	{
		Int memUsage = 0;
		for (Int i = 0; i < _cnt; i++)
			memUsage += maxon::GetMemorySizeHelper(_ptr[i]);

		return memUsage + SIZEOF(*this) + (GetCapacityCount() - _cnt) * SIZEOF(T);
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the first element.
	/// When you modify the array Begin() will change, it is not a constant value.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ConstIterator Begin() const
	{
		return ConstIterator(_ptr);
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the first element.
	/// When you modify the array Begin() will change, it is not a constant value.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Iterator Begin()
	{
		return Iterator(_ptr);
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the end (End() - 1 is the last element if the array is not empty).
	/// When you modify the array End() will change, it is not a constant value.
	/// @return												Iterator for the array end (points behind the last element).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ConstIterator End() const
	{
		return ConstIterator(_ptr + GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the end (End() - 1 is the last element if the array is not empty).
	/// When you modify the array End() will change, it is not a constant value.
	/// @return												Iterator for the array end (points behind the last element).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Iterator End()
	{
		return Iterator(_ptr + GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Moves elements to another (empty) array.
	/// @param[out] dst								The destination array.
	/// @param[in] position						Index of the first element to be moved.
	/// @param[in] moveCnt						Number of elements to be moved.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	ResultMem MoveAndShrink(BaseArray<T, MINCHUNKSIZE, MEMFLAGS, ALLOCATOR>& dst, Int position, Int moveCnt)
	{
		if (dst.GetCount() == 0 && dst.EnsureCapacity(moveCnt) == OK)
		{
			if (position + moveCnt <= GetCount())
			{
				using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;

				// Move elements to destination array.
				Utilities::MoveFrom(_ptr + position, dst._ptr, moveCnt);
				dst._cnt = moveCnt;

				// Close gap.
				Utilities::MoveFrom(_ptr + position + moveCnt, _ptr + position, _cnt - (position + moveCnt));
				_cnt -= moveCnt;
				return OK;
			}
		}
		return FAILED;
	}

	//----------------------------------------------------------------------------------------
	/// Disconnects the array's memory buffer and returns its content as a block.
	/// Afterwards the array is in the same state as directly after its construction.
	/// @return												Block of the memory buffer.
	/// @note The memory needs to be freed with the allocator that the array is using.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Block<T> Disconnect()
	{
		Block<T> result(_capacity > 0 ? _ptr : nullptr, _cnt, SIZEOF(T));
		_ptr = (T*) this;
		_cnt = 0;
		_capacity = 0;
		return result;
	}

	//----------------------------------------------------------------------------------------
	/// Sets the array's memory buffer to the given block. The current content of this
	/// array is freed before.
	/// @param[in] block							Memory block to use for the array. The array takes ownership of the memory.
	/// @param[in] capacity						Capacity of the buffer. If a non-positive value is given, the capacity is assumed to be the same as the size.
	/// @note The memory pointed to by @p block must have been allocated by the allocator that the array is using.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void Connect(const Block<T>& block, Int capacity = 0)
	{
		this->~BaseArray();
		new (this) BaseArray(block, capacity);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the allocator as reference. Typically this is used by the arrays and other
	/// base classes when multiple of them are "stitched" together as one big object all
	/// shall use one main allocator.
	/// @return												Allocator reference.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ALLOCATOR& GetAllocator()
	{
		return _allocator;
	}

	/// @copydoc GetAllocator
	MAXON_ATTRIBUTE_FORCE_INLINE const ALLOCATOR& GetAllocator() const
	{
		return _allocator;
	}

protected:
	using Super::_allocator;
	using Super::_ptr;
	using Super::_cnt;
	using Super::_capacity;

	//----------------------------------------------------------------------------------------
	/// Constructs a BaseArray such that it uses the given block as memory buffer.
	/// @param[in] block							Memory block to use for the array. The array takes ownership of the memory.
	/// @param[in] capacity						Capacity of the buffer. If a non-positive value is given, the capacity is assumed to be the same as the size.
	/// @note The memory pointed to by @p block must have been allocated by the allocator that the array is using.
	/// @private
	//----------------------------------------------------------------------------------------
	BaseArray(const Block<T>& block, Int capacity)
	{
		_ptr = block.GetFirst();
		_cnt = block.GetCount();
		_capacity = (capacity > 0) ? capacity : _cnt;
		DebugAssert(_capacity >= _cnt);

		// Use dummy pointer if the array has no capacity.
		if (_capacity == 0)
			_ptr = (T*) this;
	}

private:
	//----------------------------------------------------------------------------------------
	/// BaseArray specific: Appends uninitialized element(s) at the end of the array.
	/// @param[in] increment					Number of elements to be appended.
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												Pointer to the element (the constructor hasn't been called yet) or nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_WARN_UNUSED T* IncreaseCapacity(Int increment = 1, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		Int	requestedCapacity = _cnt + increment;
		T*	element = _ptr + _cnt;

		// Increase memory block size if capacity is too small.
		if (MAXON_UNLIKELY(requestedCapacity > _capacity))
		{
			using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;
			Bool memoryHasBeenMoved;
			Int	totalCapacity = (resizeFlags & COLLECTION_RESIZE_FLAGS::ON_GROW_FIT_TO_SIZE) ? requestedCapacity : _allocator.ComputeArraySize(_capacity, increment, MINCHUNKSIZE);

			// Use at least the buffer capacity if the FixedBufferAllocator is used.
			if (std::is_base_of<FixedBufferAllocatorBase, ALLOCATOR>::value)
			{
				Int minCapacity = _allocator.ComputeArraySize(0, 1, MINCHUNKSIZE);
				if (totalCapacity < minCapacity)
					totalCapacity = minCapacity;
			}

			element = Utilities::TryRealloc(GetAllocator(), _capacity > 0 ? _ptr : nullptr, totalCapacity * SIZEOF(T), memoryHasBeenMoved);
			if (element)
			{
				// Move elements to new memory block if a new memory block was allocated (no realloc).
				if (memoryHasBeenMoved == false && _capacity > 0)
				{
					// If the FixedBufferAllocator is used it might return the already used pointer because the buffer is big enough and the elements don't have to be moved.
					if ((std::is_base_of<FixedBufferAllocatorBase, ALLOCATOR>::value == false) || (element != _ptr))
					{
						Utilities::MoveFrom(_ptr, element, _cnt);
						_allocator.Free(_ptr);
					}
				}
				_ptr = element;
				_capacity = totalCapacity;
				element += _cnt;
			}
			else
			{
				requestedCapacity = _cnt;
			}
		}

		return element;
	}

	//----------------------------------------------------------------------------------------
	/// BaseArray specific: Inserts uninitialized element(s) at the specified index. <B> This does
	/// not call the constructor! Use Insert() unless you deal with PODs that shall not be
	/// initialized for a very good reason! </B>
	/// @param[in] idx								Index at which elements shall be inserted (0 <= idx <= cnt).
	/// @param[in] increment					Number of elements to be inserted.
	/// @return												Pointer to the element (the constructor hasn't been called yet) or nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_WARN_UNUSED T* InsertWithoutConstructor(Int idx, Int increment = 1)
	{
		using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;
		// If idx == cnt the elements will be appended.
		Bool isInsert = UInt(idx) < UInt(_cnt);

		if (UInt(idx) > UInt(_cnt))
		{
			DebugStop("The position is invalid.");
			return nullptr;
		}

		// Resize the array if _capacity is too small.
		if (_cnt + increment > _capacity)
		{
			Bool memoryHasBeenMoved;
			Int	 newCapacity = _allocator.ComputeArraySize(_cnt, increment, MINCHUNKSIZE);
			T*	 newArray = Utilities::TryRealloc(GetAllocator(), _capacity > 0 ? _ptr : nullptr, newCapacity * SIZEOF(T), memoryHasBeenMoved);

			if (newArray == nullptr)
				return nullptr;

			// Move elements if new memory block was allocated.
			if (memoryHasBeenMoved == false && _capacity > 0)
			{
				// If the FixedBufferAllocator is used it might return the already used pointer because the buffer is big enough and the elements don't have to be moved.
				if ((std::is_base_of<FixedBufferAllocatorBase, ALLOCATOR>::value == false) || (newArray != _ptr))
				{
					Utilities::MoveFrom(_ptr, newArray, idx);

					// Is insert in the array?
					if (isInsert)
						Utilities::MoveFrom(_ptr + idx, newArray + idx + increment, _cnt - idx);

					_allocator.Free(_ptr);
				}

				// Already done the work.
				isInsert = false;
			}
			_ptr = newArray;
			_capacity = newCapacity;
		}

		// Pointer to the inserted/appended element.
		T* element = _ptr + idx;

		// Will elements be inserted within the array?
		if (isInsert)
			Utilities::MoveFrom(element, element + increment, _cnt - idx);
		_cnt += increment;

		return element;
	}

	ResultMem FitToSize(Int newCapacity)
	{
		if (newCapacity >= _cnt)
		{
			if (newCapacity == _capacity)
				return OK;

			// Using Realloc() wouldn't work because it won't shrink an existing block (furthermore if it would we'd have problems with the constructors).
			T* newArray = newCapacity > 0 ? (T*) _allocator.Alloc(newCapacity * SIZEOF(T), MAXON_SOURCE_LOCATION_NAME(T)) : (T*) this;
			if (newArray)
			{
				// If the FixedBufferAllocator is used it might return the already used pointer because the buffer is big enough and the elements don't have to be moved.
				if ((std::is_base_of<FixedBufferAllocatorBase, ALLOCATOR>::value == false) || (newArray != _ptr))
				{
					using Utilities = BaseArrayUtilities<T, std::is_trivially_copyable<T>::value || MEMFLAGS == BASEARRAYFLAGS::MOVEANDCOPYOBJECTS>;

					// At this point we could check the real size of newArray and possibly skip the rest if it isn't smaller.
					Utilities::MoveFrom(_ptr, newArray, _cnt);
					_allocator.Free(_ptr);
					_capacity = newCapacity;
					_ptr = newArray;
				}
				return OK;
			}
		}
		return FAILED;
	}

	friend class GenericBaseArray;
};

template <typename TO, typename FROM, Bool SAFE> struct GenericCastMemberTrait<BaseArray<TO>, BaseArray<FROM>, SAFE> : public GenericCastMemberTrait<TO, FROM, SAFE>
{
};

//----------------------------------------------------------------------------------------
/// This selector class is used for template parameters which select the array implementation
/// to use. It will then instruct the template to use the BaseArray implementation.
/// For example, ArrayMap by default uses an underlying BaseArray with default settings. If you want to change
/// those default settings, you'd write
/// @code
/// ArrayMap<Int, String, true, DefaultCompare, BaseArraySelector<60>> map;
/// @endcode
///
/// @tparam MINCHUNKSIZE					The minimum number of elements upon array creation.
/// @tparam MEMFLAGS							Use BASEARRAYFLAGS::NONE unless you know the object can be moved and/or copied.
/// @tparam ALLOCATOR							Class for memory allocation.
//----------------------------------------------------------------------------------------
template <Int MINCHUNKSIZE = BASEARRAY_DEFAULT_CHUNK_SIZE, BASEARRAYFLAGS MEMFLAGS = BASEARRAYFLAGS::NONE, typename ALLOCATOR = DefaultAllocator> class BaseArraySelector
{
public:
	template <typename T> using Type = BaseArray<T, MINCHUNKSIZE, MEMFLAGS, ALLOCATOR>;
};


template <Int COUNT, Int MINCHUNKSIZE = COUNT, BASEARRAYFLAGS MEMFLAGS = BASEARRAYFLAGS::NONE, typename ALLOCATOR = DefaultAllocator> class BufferedBaseArraySelector
{
public:
	template <typename T> using Type = BaseArray<T, MINCHUNKSIZE, MEMFLAGS, FixedBufferAllocator<T, COUNT, ALLOCATOR, true>>;
};


//----------------------------------------------------------------------------------------
/// BufferedBaseArray is a maxon::BaseArray which uses a maxon::FixedBufferAllocator. The allocator's buffer
/// lies within the BufferedBaseArray, so no dynamic memory allocation is needed
/// as long as the reserved space suffices.
/// This can greatly improve performance if the number of elements in an array is usually small.
///
/// You shouldn't reserve a large amount of elements, and you shouldn't use @c BufferedBaseArray
/// if it is likely that the reserved space won't be enough. E.g., the ports of a node are
/// typically small in number, so a BufferedBaseArray can be used.
/// But the points of polygon object are typically large in number, so don't use a BufferedBaseArray.
///
/// Example:
/// @code
/// BufferedBaseArray<Utf32Char, 256> buffer;
/// @endcode
///
/// @tparam T											Type of the array elements.
/// @tparam COUNT									Number of elements of the internal buffer.
/// @tparam MINCHUNKSIZE					The minimum number of elements upon array creation.
/// @tparam MEMFLAGS							Use BASEARRAYFLAGS::NONE unless you know the object can be moved and/or copied.
/// @tparam ALLOCATOR							Class for memory allocation if the internal buffer doesn't suffice.
//----------------------------------------------------------------------------------------
template <typename T, Int COUNT, Int MINCHUNKSIZE = COUNT, BASEARRAYFLAGS MEMFLAGS = BASEARRAYFLAGS::NONE, typename ALLOCATOR = DefaultAllocator> using BufferedBaseArray = typename BufferedBaseArraySelector<COUNT, MINCHUNKSIZE, MEMFLAGS, ALLOCATOR>::template Type<T>;

template <typename T, Int MINCHUNKSIZE, BASEARRAYFLAGS MEMFLAGS, typename ALLOCATOR> struct IsZeroInitialized<BaseArray<T, MINCHUNKSIZE, MEMFLAGS, ALLOCATOR>> : public IsZeroInitialized<ALLOCATOR> { };

/// @}

} // namespace maxon

#endif // BASEARRAY_H__
