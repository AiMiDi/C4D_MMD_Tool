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

	static GenericContainerInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION)
	{
		DebugStop("Can't allocate abstract container.");
		return nullptr;
	}

	MAXON_METHOD const ContainerDataType<>& GetContainerType() const;

	//----------------------------------------------------------------------------------------
	/// This enum informs about the interfaces which are implemented by a container and also
	/// about some implementation details (see GetInterfaces()).
	//----------------------------------------------------------------------------------------
	enum class INTERFACES
	{
		NONE = 0,												///< No interface.
		VIRTUAL_TUPLE_CONTAINER = 1,		///< The container is a virtual tuple container.
		ARRAY_CONTAINER = 2,						///< The container implements GenericArrayContainerInterface.
		XFORM_CONTAINER = 4,						///< The container is an xform container (see XformContainerActionsInterface).
		CONCAT_CONTAINER = 8,						///< The container is a concat container (see ContainerFactory::Concat).
		STATIC_ARRAY = 16,							///< The container implements StaticArrayInterface.
		ARRAY = 32,											///< The container implements ArrayInterface.
		SINGLE_VALUE_ARRAY = 64,				///< The container is a single-value array (see ArrayFactory::NewSingleValueArray). This is set in addition to ARRAY.
		BASE_ARRAY = 128,								///< The container uses an underlying BaseArray (see ArrayFactory::NewBaseArray). This is set in addition to ARRAY.
		PAGED_ARRAY = 256,							///< The container is a paged array (see ArrayFactory::NewPagedArray). This is set in addition to ARRAY.
		INDEXABLE = 512,								///< The container implements GenericIndexableContainerInterface.
		MULTI_DOMAIN_CONTAINER = 1024,	///< The container implements MultiDomainContainerInterface.
		SLICED_ARRAY = 2048,						///< The container is a subset of an array (see ArrayFactory::Slice). This is set in addition to ARRAY.
		MEMBER_ARRAY = 4096							///< The container is an array pointing to member data of a source array (see ArrayFactory::ExtractMember). This is set in addition to ARRAY.
	} MAXON_ENUM_FLAGS_CLASS(INTERFACES);

	//----------------------------------------------------------------------------------------
	/// Returns INTERFACES flags corresponding to the interfaces implemented by this container.
	/// You can safely cast the container to these interfaces.
	/// @return												INTERFACES flags for this container.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD INTERFACES GetInterfaces() const;

	//----------------------------------------------------------------------------------------
	/// Returns a writable copy of this container. This may return a different implementation of the
	/// interface if the current implementation only supports read-only access (for example a
	/// container implementation where all elements have the same value). If there's just a single
	/// reference to the container, the container itself may be returned.
	///
	/// By default the value of copyContent is true. Then the content of the copy will be equal to
	/// the content of the original container. However if you don't need that because you're going to
	/// overwrite the complete content anyway, you can use false for copyContent. Then the content of the
	/// copy is unspecified, so the implementation is free to skip copying the content and the returned copy may even be empty.
	/// In particular any indexed read or write access to elements without a prior call to a method like Resize may fail.
	///
	/// @note Don't confuse this method with the MakeWritable function of reference classes. The latter
	/// makes sure that the object held by a COW reference is writable by calling this MakeWritable function
	/// (with default true value for copyContent) and then replacing the object of the COW reference by
	/// the returned object. This MakeWritable method is a const method which doesn't change anything.
	/// For containers the COW reference class has an additional MakeWritableDontCopyContent function which uses
	/// false for copyContent, you can use that function to make the object of a COW reference writable
	/// when you are going to overwrite its complete content.
	///
	/// @param[in] copyContent				True (the default) if the content shall be copied, false otherwise
	///																(then just a new object with a writable implementation is created, its content is unspecified and may be empty).
	/// @return												Pointer to the writable container object.
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GenericContainerInterface*> MakeWritable(Bool copyContent = true) const;

	MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS(
	//----------------------------------------------------------------------------------------
	/// Makes the container object of this copy-on-write reference writable, where the content of the
	/// resulting container object is unspecified (see GenericContainerInterface::MakeWritable).
	/// You can use this function instead of MakeWritable()
	/// or prior to non-const method calls when you are going to overwrite the complete content of the
	/// container (so that a copy of the original content is needless and wasteful).
	/// @code
	/// Array<Int> someArray;
	/// ...
	/// // We will overwrite the content afterwards, so we don't care about the current content.
	/// someArray.MakeWritableDontCopyContent() iferr_return;
	/// someArray.Resize(100) iferr_return;
	/// for (Int i = 0; i < 100; ++i)
	/// {
	/// 	someArray.Set(i, i) iferr_return;
	/// }
	/// @endcode
	/// @return												Reference to the writable container object.
	//----------------------------------------------------------------------------------------
	ResultRef<typename std::remove_const<typename S::PrivateReferencedType>::type> MakeWritableDontCopyContent()
	{
		return StrongCOWRefHandler::MakeWritableHelper<typename std::remove_const<typename S::PrivateReferencedType>::type>::MakeWritable(this->GetBaseRef(), false, false);
	}
	);

	MAXON_METHOD String ToString(const FormatStatement* formatStatement = nullptr) const;

	MAXON_METHOD HashInt GetHashCode() const;

	MAXON_METHOD UniqueHash GetUniqueHashCode() const;

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
	MAXON_METHOD Result<Int> InitIterator(ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer, Bool constAccess) const;

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
	// The copyContent parameter is only used by MakeWritableDontCopyContent
	template <typename R> static MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> MakeWritable(R& ref, Bool resetOnError, Bool copyContent = true)
	{
		const T* orig = ref.GetPointer();
		T* o = const_cast<T*>(orig);
		if (MAXON_UNLIKELY(o == nullptr))
		{
			o = NewObj(T).GetPointer();
		}
		else
		{
			o = static_cast<T*>(o->GenericContainerInterface::MakeWritable(copyContent) iferr_ignore("nullptr indicates error"));
			if (MAXON_LIKELY(o == orig))
				return o;
		}
		if (MAXON_LIKELY(resetOnError || o))
			ref.PrivateSetTarget(ResultPtr<typename R::ReferencedType>(o));
		DebugAssert(!o || (GetReferenceCounter(o) == 1));
		return o;
	}
};


//----------------------------------------------------------------------------------------
/// This is the base interface of all indexable containers such as arrays or array containers.
//----------------------------------------------------------------------------------------
class GenericIndexableContainerInterface : public GenericContainerInterface MAXON_GENERIC_BASE(T)
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL_DERIVED(GenericIndexableContainerInterface, MAXON_REFERENCE_COPY_ON_WRITE);
	MAXON_GENERIC((ContainerVariance) typename T = NamedTuple<>);
public:
	//----------------------------------------------------------------------------------------
	/// Gets the number of elements of the container.
	/// @return												Number of container elements.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetCount() const;

	/// @MAXON_ANNOTATION{default=true}
	MAXON_FUNCTION Bool IsEmpty() const
	{
		return GetCount() == 0;
	}

	MAXON_FUNCTION Bool IsPopulated() const
	{
		return GetCount() != 0;
	}

	MAXON_METHOD_RESERVE;
	MAXON_METHOD_RESERVE;
	MAXON_METHOD_RESERVE;
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
		maxon::Member GetMember() const { return maxon::Member::Create<T>(*this); } \
		operator maxon::Member() const { return GetMember(); } \
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
