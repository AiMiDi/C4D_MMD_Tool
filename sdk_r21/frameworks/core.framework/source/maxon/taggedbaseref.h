#ifndef TAGGEDBASEREF_H__
#define TAGGEDBASEREF_H__

#include "maxon/baseref.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

template <typename T, typename HANDLER, typename TAG, Int TAG_BITS, TAG DEFAULT_VALUE = TAG(0), Bool ENABLE_POINTER_CONVERSION = true> class TaggedBaseRef
{
public:
	static const UInt TAG_MASK = (1 << TAG_BITS) - 1;
	static_assert(UInt(DEFAULT_VALUE) <= TAG_MASK, "");

	using ReferencedType = T;

	TaggedBaseRef() : _ptr(UInt(DEFAULT_VALUE))
	{
	}

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

	TaggedBaseRef& operator =(std::nullptr_t)
	{
		if (_ptr & ~TAG_MASK)
		{
			HANDLER::RemoveReference((T*) (_ptr & ~TAG_MASK));
			_ptr &= TAG_MASK;
		}
		return *this;
	}

	operator T*() const
	{
		static_assert(ENABLE_POINTER_CONVERSION, "The pointer conversion operator is disabled for this TaggedBaseRef.");
		return (T*) (_ptr & ~TAG_MASK);
	}

	explicit operator Bool() const
	{
		return (_ptr & ~TAG_MASK) != 0;
	}

	T* operator ->() const
	{
		return (T*) (_ptr & ~TAG_MASK);
	}

	typename std::conditional<std::is_same<const T, const void>::value, DummyReturnType, T>::type& operator *() const
	{
		return *(T*) (_ptr & ~TAG_MASK);
	}

	T* GetPointer() const
	{
		return (T*) (_ptr & ~TAG_MASK);
	}

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

	TAG GetTag() const
	{
		return TAG(_ptr & TAG_MASK);
	}

	void SetTag(TAG t)
	{
		DebugAssert(UInt(t) <= TAG_MASK);
		_ptr = (_ptr & ~TAG_MASK) + (UInt(t) & TAG_MASK);
	}

	void Reset()
	{
		_ptr = 0;
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(TaggedBaseRef, _ptr);

#if 0
	ResultRef<typename std::remove_const<T>::type> MakeWritable(Bool resetOnError = true)
	{
		return HANDLER::MakeWritable(*this, resetOnError);
	}
#endif

	typename SFINAEHelper<String, T>::type ToString(const FormatStatement* format) const
	{
		return GlobalToString(GetPointer(), format) + "/"_s + GlobalToString(GetTag(), format);
	}

private:
	UInt _ptr;
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
