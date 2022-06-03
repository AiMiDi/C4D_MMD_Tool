#ifndef TAGGEDBASEREF_H__
#define TAGGEDBASEREF_H__

#include "maxon/baseref.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

//----------------------------------------------------------------------------------------
/// A TaggedBaseRef is similar to a BaseRef, but it allows to save some extra information
/// (the tag) in the lowest bits of the internal pointer while still having the size of a pointer.
///
/// Pointers obtained through the DefaultAllocator have a guaranteed minimal alignment
/// of DefaultAllocator::MIN_ALIGNMENT_MASK. The mask is 15 which means that the lowest 4 bits
/// are guaranteed to be zero. With a TaggedBaseRef you can use those 4 bits for extra information. For other
/// allocators the number of usable bits will be different.
///
/// @tparam T											Type of the referenced object.
/// @tparam HANDLER								The reference handler implements the specific behaviour whenever a reference is changed to point to another object.
/// @tparam TAG										Type of the tag. This has to be Bool, an integral or an enumeration type.
/// @tparam TAG_BITS							The number of bits to use for the tag. In debug configuration it is checked that pointers have sufficient alignment,
/// 															and that tag values don't make use of exceeding bits.
/// @tparam DEFAULT_VALUE					The default value of the tag.
/// @tparam ENABLE_POINTER_CONVERSION	Use true (the default) to allow the conversion operator to T*.
//----------------------------------------------------------------------------------------
template <typename T, typename HANDLER, typename TAG, Int TAG_BITS, TAG DEFAULT_VALUE = TAG(0), Bool ENABLE_POINTER_CONVERSION = true> class TaggedBaseRef
{
public:
	/// The bit mask for tag values.
	static const UInt TAG_MASK = (1 << TAG_BITS) - 1;
	static_assert(UInt(DEFAULT_VALUE) <= TAG_MASK, "Default value doesn't fit into mask.");

	//----------------------------------------------------------------------------------------
	/// A type alias for the type the TaggedBaseRef points to.
	//----------------------------------------------------------------------------------------
	using ReferencedType = T;

	TaggedBaseRef() = default;

	//----------------------------------------------------------------------------------------
	/// Constructs a TaggedBaseRef, initializing pointer and tag with the given arguments.
	/// @param[in] ptr								Pointer with which the TaggedBaseRef is initialized, may be nullptr.
	/// @param[in] tag								Tag value with which the TaggedBaseRef is initialized, may be nullptr.
	//----------------------------------------------------------------------------------------
	TaggedBaseRef(T* ptr, TAG tag) : _ptr(UInt(ptr) + UInt(tag))
	{
		DebugAssert((UInt(ptr) & TAG_MASK) == 0);
		DebugAssert(UInt(tag) <= TAG_MASK);
		if (ptr)
		{
			HANDLER::AddReference(ptr);
		}
	}

	TaggedBaseRef(const TaggedBaseRef& src) : _ptr(src._ptr)
	{
		static_assert(!(HANDLER::KIND & VALUEKIND::UNIQUE_REFERENCE), "Can't copy a TaggedBaseRef with unique ownership.");
		if (_ptr & ~TAG_MASK)
		{
			HANDLER::AddReference((T*) (_ptr & ~TAG_MASK));
		}
	}

	MAXON_OPERATOR_COPY_ASSIGNMENT(TaggedBaseRef);

	TaggedBaseRef(TaggedBaseRef&& src) : _ptr(src._ptr)
	{
		src._ptr = 0;
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(TaggedBaseRef);

	~TaggedBaseRef()
	{
		*this = nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Resets the internal pointer to nullptr, which includes the proper release of the reference.
	/// The tag value won't be changed.
	//----------------------------------------------------------------------------------------
	// #LEGACYCOMPATIBILITY: remove
	TaggedBaseRef& operator =(std::nullptr_t)
	{
		if (_ptr & ~TAG_MASK)
		{
			HANDLER::RemoveReference((T*) (_ptr & ~TAG_MASK));
			_ptr &= TAG_MASK;
		}
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Resets pointer to nullptr and tag value to DEFAULT_VALUE.
	/// This includes the proper release of the reference.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		if (_ptr & ~TAG_MASK)
		{
			HANDLER::RemoveReference((T*) (_ptr & ~TAG_MASK));
		}
		_ptr = UInt(DEFAULT_VALUE);
	}

	//----------------------------------------------------------------------------------------
	/// User-defined conversion to T*, unpacking the internal pointer.
	/// @return												Internal pointer.
	//----------------------------------------------------------------------------------------
	operator T*() const
	{
		static_assert(ENABLE_POINTER_CONVERSION, "The pointer conversion operator is disabled for this TaggedBaseRef.");
		return (T*) (_ptr & ~TAG_MASK);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the pointer is valid (i.e., not a nullptr).
	/// @return												True if the internal pointer is not a nullptr.
	//----------------------------------------------------------------------------------------
	explicit operator Bool() const
	{
		return (_ptr & ~TAG_MASK) != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Allows direct access to the members of the pointee. You have to check for a nullptr before.
	/// @return												Internal pointer.
	//----------------------------------------------------------------------------------------
	T* operator ->() const
	{
		return (T*) (_ptr & ~TAG_MASK);
	}

	//----------------------------------------------------------------------------------------
	/// Dereferences the TaggedBaseRef. This yields the pointee as a reference. You have to check for a nullptr before.
	/// @note Not available for T = void.
	/// @return												Pointee as a reference.
	//----------------------------------------------------------------------------------------
	typename std::conditional<STD_IS_REPLACEMENT(same, const T, const void), DeleteReturnType01, T>::type& operator *() const
	{
		return *(T*) (_ptr & ~TAG_MASK);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the internal pointer of the TaggedBaseRef. You can also use operator-> to access members of the pointee directly through the TaggedBaseRef.
	/// @return												Internal pointer.
	//----------------------------------------------------------------------------------------
	T* GetPointer() const
	{
		return (T*) (_ptr & ~TAG_MASK);
	}

	//----------------------------------------------------------------------------------------
	/// Sets the pointer of this TaggedBaseRef to ptr. This includes proper reference handling according to HANDLER.
	/// The tag value won't be changed.
	/// @param[in] ptr								New pointer for the TaggedBaseRef.
	//----------------------------------------------------------------------------------------
	void SetPointer(T* ptr)
	{
		if (ptr != (T*) (_ptr & ~TAG_MASK))
		{
			*this = nullptr;
			if (ptr)
			{
				DebugAssert((UInt(ptr) & TAG_MASK) == 0);
				HANDLER::AddReference(ptr);
				_ptr += UInt(ptr);
			}
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns tag value of the TaggedBaseRef.
	/// @return												Current tag value.
	//----------------------------------------------------------------------------------------
	TAG GetTag() const
	{
		return TAG(_ptr & TAG_MASK);
	}

	//----------------------------------------------------------------------------------------
	/// Sets tag value of this TaggedBaseRef to t. The pointer won't be changed.
	/// @param[in] t									New tag value for the TaggedBaseRef.
	//----------------------------------------------------------------------------------------
	void SetTag(TAG t)
	{
		DebugAssert(UInt(t) <= TAG_MASK);
		_ptr = (_ptr & ~TAG_MASK) + (UInt(t) & TAG_MASK);
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(TaggedBaseRef, _ptr);

	ResultRef<typename std::remove_const<T>::type> MakeWritable(Bool resetOnError = true)
	{
		return HANDLER::MakeWritable(*this, resetOnError);
	}

	/// @copydoc DefaultDoc::ToString
	typename SFINAEHelper<String, T>::type ToString(const FormatStatement* format = nullptr) const
	{
		return GlobalToString(GetPointer(), format) + "/"_s + GlobalToString(GetTag(), format);
	}

	void PrivateSetTarget(ResultPtr<T> src)
	{
		SetPointer(src.GetPointer());
	}

private:
	UInt _ptr = UInt(DEFAULT_VALUE);
};

// Overload global ToString function for TaggedBaseRef because the default one only uses the pointer and ignores the tag.
template <typename T, typename HANDLER, typename TAG, Int TAG_BITS, TAG DEFAULT_VALUE, Bool ENABLE_POINTER_CONVERSION>
inline typename SFINAEHelper<String, T>::type ToString(const TaggedBaseRef<T, HANDLER, TAG, TAG_BITS, DEFAULT_VALUE, ENABLE_POINTER_CONVERSION>& object, const FormatStatement* formatStatement, Bool checkDataType = true)
{
	return ToStringHelper(&object, formatStatement, (Int*) checkDataType);
}

/// @}

} // namespace maxon


#endif // TAGGEDBASEREF_H__
