#ifndef CONTAINERBASE_H__
#define CONTAINERBASE_H__

#include "maxon/viewiterator.h"

namespace maxon
{

namespace details
{
template <typename PACK, Bool CONST_ITERATOR> class ContainerIterator;
}

template <typename TO, typename FROM, Int TO_COUNT = TO::COUNT> struct ContainerVariance
{
	static_assert(TO::COUNT > 0, "Error in instantiation of ContainerVariance.");
	static constexpr Bool value = maxon::details::MemberType<typename TO::FirstType>::NAMED ? FROM::template ContainsAll<TO>::value : (STD_IS_REPLACEMENT(same, typename TO::FirstType, typename FROM::FirstType) && ContainerVariance<typename TO::RestPack, typename FROM::RestPack>::value);
};

template <typename TO, typename FROM> struct ContainerVariance<TO, FROM, 0>
{
	static_assert(TO::COUNT == 0, "Error in instantiation of ContainerVariance.");
	static constexpr Bool value = true;
};

using PersistentIdBuffer = BufferedBaseArray<Int64, 10>;

class GenericContainerInterface
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(GenericContainerInterface, MAXON_REFERENCE_COPY_ON_WRITE);
	MAXON_GENERIC((ContainerVariance) typename T = NamedTuple<>);
public:
	using GenericContainerInterfaceMarker = void;

	enum class INTERFACES
	{
		NONE = 0,
		SINGLETON_CONTAINER = 1,
		ARRAY_CONTAINER = 2,
		XFORM_CONTAINER = 4,
		CONCAT_CONTAINER = 8,
		STATIC_ARRAY = 16,
		V_ARRAY = 32,
		ARRAY = 64,
		SINGLE_VALUE_ARRAY = 128
	} MAXON_ENUM_FLAGS_CLASS(INTERFACES);

	MAXON_METHOD const ContainerDataType<>& GetContainerType() const;

	MAXON_METHOD INTERFACES GetInterfaces() const;

	//----------------------------------------------------------------------------------------
	/// Returns a writable copy of this container. This may return a different implementation of the
	/// interface if the current implementation only supports read-only access (for example a
	/// container implementation where all elements have the same value). If there's just a single
	/// reference to the container, the container itself may be returned.
	/// @param[in] cloneElements			True if also the elements shall be cloned, false otherwise (then just a new object with a writable implementation is created).
	/// @return												Pointer to the writable container object, nullptr if allocation or copying failed.
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GenericContainerInterface*> MakeWritable(Bool cloneElements = true) const;

	MAXON_METHOD Result<GenericContainerInterface*> Clone(Bool cloneElements = true) const;

	MAXON_METHOD String ToString(const FormatStatement* formatStatement = nullptr) const;

	MAXON_METHOD HashInt GetHashCode() const;

	MAXON_METHOD HashValue GetHashValue() const;

	MAXON_METHOD Bool IsEqual(const GenericContainerInterface* other, EQUALITY equality) const;

	//----------------------------------------------------------------------------------------
	/// Finds the member index of the member with the given #name in this. If no such member
	/// can be found, -1 is returned.
	/// @param[in] name								Name of the member to find.
	/// @return												Index of the member, or -1 if it doesn't exist.
	/// @MAXON_ANNOTATION{default=-1}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int FindMemberIndex(const InternedId& name) const;

	MAXON_FUNCTION Int FindMemberIndex(const Member& member) const
	{
		return FindMemberIndex(member.name);
	}

	MAXON_METHOD Result<Int> GetCount() const;

	/// @MAXON_ANNOTATION{refclass=false}
	MAXON_METHOD Int GetIteratorStateSize(const MemberMap* map) const;

	/// @MAXON_ANNOTATION{refclass=false}
	MAXON_METHOD Result<Int> InitIterator(ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const;

	/// @MAXON_ANNOTATION{refclass=false}
	MAXON_METHOD Result<Int> ValidateIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const;

	/// @MAXON_ANNOTATION{refclass=false}
	MAXON_METHOD void FreeIterator(ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const;

	/// @MAXON_ANNOTATION{refclass=false}
	MAXON_METHOD Result<Int> MoveIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const;

	/// @MAXON_ANNOTATION{refclass=false}
	MAXON_METHOD Result<void> AdvancePersistentId(Int index, const Char* state, PersistentIdBuffer& idBuffer) const;

	MAXON_METHOD_RESERVE;
	MAXON_METHOD_RESERVE;

	// MAXON_METHOD Tuple<Int, DataTypePtr, INNERMOST_MEMBER> GetContainingMember(INNERMOST_MEMBER member) const;

	MAXON_ADD_TO_CONST_REFERENCE_CLASS
	(
	using Iterator = maxon::details::ContainerIterator<T, false>;
	using ConstIterator = maxon::details::ContainerIterator<T, true>;
	);
};


// There's a specialization of the MakeWritable mechanism for containers to allow for
// read-only implementations of the container interface (such as arrays where all elements are the same).
// These implementations need to create a new writable implementation even if there is just a single reference.
template <typename T> struct StrongCOWRefHandler::MakeWritableHelper<T, typename T::GenericContainerInterfaceMarker>
{
	template <typename R> static MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> MakeWritable(R& ref, Bool resetOnError)
	{
		const T* orig = ref.GetPointer();
		T* o = const_cast<T*>(orig);
		if (MAXON_UNLIKELY(o == nullptr))
		{
			o = NewObj(T).GetPointer();
		}
		else
		{
			o = static_cast<T*>(o->GenericContainerInterface::MakeWritable(true) iferr_ignore("nullptr indicates error"));
			if (MAXON_LIKELY(o == orig))
				return o;
		}
		if (MAXON_LIKELY(resetOnError || o))
			ref.PrivateSetTarget(ResultPtr<typename R::ReferencedType>(o));
		DebugAssert(!o || (GetReferenceCounter(o) == 1));
		return o;
	}
};


#define PRIVATE_MAXON_MEMBER_NAME(N, M) M(#N, PrivateMemberNameId_##N); \
	struct PrivateMemberName_##N : public maxon::InternedId \
	{ \
		PrivateMemberName_##N() : maxon::InternedId(PrivateMemberNameId_##N) { } \
		template <typename T, typename SUPER> struct AddMember : public SUPER \
		{ \
			typename T::template Member<AddMember> N; \
			static maxon::Int PrivateGetOffset() { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(AddMember, N); } \
		}; \
		static const maxon::InternedId& GetInstance() { return PrivateMemberNameId_##N; } \
		const maxon::InternedId& Get() const { return *this; } \
	}; \
	template <typename T = void> struct N; /* see UnannotatedType why we have to use the helper */ \
	template <typename T = void> using PrivateHelper_##N = maxon::TemplateInstantiation<N, T>; \
	template <typename T> struct N : public PrivateMemberName_##N \
	{ \
		using ValueType = T; \
		using Instantiation = PrivateHelper_##N<T>; \
	}

#define MAXON_MEMBER_NAME(N, ...) PRIVATE_MAXON_MEMBER_NAME(N, MAXON_INTERNED_ID)
#define MAXON_MEMBER_NAME_LOCAL(N, ...) PRIVATE_MAXON_MEMBER_NAME(N, MAXON_INTERNED_ID_LOCAL)


#include "containerbase1.hxx"
#include "containerbase2.hxx"


template <GET_DATATYPE_POLICY POLICY, typename... T> inline ResultOk<const ContainerDataType<T...>&> PrivateGetDataType(ContainerInterface<T...>**, OverloadRank1)
{
	return NamedTuple<T...>::GetContainerType();
}

template <Int DEPTH> class RecursiveContainer : public Container<>
{
public:
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = RecursiveContainer;
	};
};

template <GET_DATATYPE_POLICY POLICY, Int DEPTH> inline Result<DataType> PrivateGetDataType(RecursiveContainer<DEPTH>**, OverloadRank0)
{
	return ParametricTypes::COWReference().Instantiate(ParametricTypes::RecursiveContainerInterface().Instantiate(GetZeroRef<Block<const Member>>(), ToSingletonBlock(Int64(DEPTH))));
}

} // namespace maxon

#endif // CONTAINERBASE_H__
