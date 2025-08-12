#ifndef CUSTOMSTLALLOCATOR_H__
#define CUSTOMSTLALLOCATOR_H__

/// @file

namespace maxon
{

#ifdef MAXON_TARGET_WINDOWS
	#pragma warning(push)
	#pragma warning(disable:4180) // applying const to a function type generates this warning as this has no meaning
#endif

// stylecheck.naming=false

//----------------------------------------------------------------------------------------
/// Custom STL C++11 allocator that wraps maxon::DefaultAllocator
//----------------------------------------------------------------------------------------
template <typename T> class CustomSTLAllocator
{
public:
	// Dummy constructors and destructor as required for a custom allocator
	CustomSTLAllocator() noexcept {}
	CustomSTLAllocator(const CustomSTLAllocator&) noexcept {}
	template <typename U> CustomSTLAllocator (const CustomSTLAllocator<U>&) noexcept {}

	/// Allocates storage for n values of T.
	T* allocate(std::size_t n) noexcept
	{
		return NewMem(T, n);
	}

	/// Deallocates storage obtained by a call to allocate().
	void deallocate(T* p, std::size_t) noexcept
	{
		DeleteMem(p);
	}

	/// Constructs an object of type T at the location of p, using the value of value in the call to the constructor for T.
	void construct(T* p, const T& value)
	{
		// initialize memory with placement new
		new (p) T(value);
	}

	/// Calls the destructor on the value pointed to by p.
	void destroy(T* p)
	{
		p->~T();
	}

	// rebind allocator to type U
	template <typename U> struct rebind
	{
		using other = CustomSTLAllocator<U>;
	};

	/// type definitions required for custom allocator
	using value_type = T;
	using pointer = T*;
	using const_pointer = const T*;
	using reference = T&;
	using const_reference = const T&;
	using size_type = std::size_t;
	using difference_type = std::ptrdiff_t;
};

#ifdef MAXON_TARGET_WINDOWS
	#pragma warning(pop)
#endif

// return that all specializations of this allocator are interchangeable
template <typename T1, typename T2> MAXON_ATTRIBUTE_FORCE_INLINE bool operator == (const CustomSTLAllocator<T1>&, const CustomSTLAllocator<T2>&) noexcept
{
	return true;
}
template <typename T1, typename T2> MAXON_ATTRIBUTE_FORCE_INLINE bool operator != (const CustomSTLAllocator<T1>&, const CustomSTLAllocator<T2>&) noexcept
{
	return false;
}


} // namespace maxon

#endif // CUSTOMSTLALLOCATOR_H__
