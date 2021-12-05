#if 1
#ifndef MAXON_TARGET_64BIT
#endif
template <typename... T_> class Container;

struct GenericContainerInterface::Hxx1
{
	template <typename T_> class Reference;
	template <typename T_> class NonConstRef;
	using ReferenceClass = Container<>;
	/// Intermediate helper class for GenericContainerInterface.
	template <typename S, typename T_> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using T = T_;
		using S::GenericVarianceCheck;
		template <typename _S, typename _T> static typename std::integral_constant<bool, true && Out<_T, T_>::value>::type GenericVarianceCheck(const ConstReferenceFunctionsImpl<_S, _T>*);
		template <typename _S> static typename std::true_type GenericVarianceCheck(ConstReferenceFunctionsImpl<_S, ParameterPack<>>*);
		template <typename DERIVED> struct IsGenericBaseOf { static const Bool value = S::template IsGenericBaseOf<DERIVED>::value && decltype(DERIVED::GenericVarianceCheck((ConstReferenceFunctionsImpl*) nullptr))::value; };
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const ContainerDataType&>, const ContainerDataType&>::type GetType() const;
		inline Result<GenericContainerInterface*> Clone() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement) const;
/// Finds the member index of the member with the given #name in this. If no such member
/// can be found, -1 is returned.
/// @param[in] name								Name of the member to find.
/// @return												Index of the member, or -1 if it doesn't exist.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindMemberIndex(const InternedId& name) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindMemberIndex(const Member& member) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetIteratorStateSize(const MemberMap* map) const;
		inline Result<Int> InitIterator(ViewIteratorMember* members, const MemberMap* map, Char* state) const;
		inline Result<Int> ValidateIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type FreeIterator(ViewIteratorMember* members, const MemberMap* map, Char* state) const;
		inline Result<Int> MoveIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::details::ContainerIterator<T_, true>>, maxon::details::ContainerIterator<T_, true>>::type Begin() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T_,true>)>, PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T_,true>)>::type End() const;
	};
	/// Intermediate helper class for GenericContainerInterface.
	template <typename S, typename T_> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S, T_>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S, T_>;
		using PrivateBaseClass::PrivateBaseClass;
		using T = T_;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::details::ContainerIterator<T_, false>>, maxon::details::ContainerIterator<T_, false>>::type Begin() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T_,false>)>, PRIVATE_MAXON_RBF_SENTINEL(maxon::details::ContainerIterator<T_,false>)>::type End() const;
	};
	/// Intermediate helper class for GenericContainerInterface.
	template <typename S, typename T_> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S, T_>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S, T_>;
		using PrivateBaseClass::PrivateBaseClass;
		using T = T_;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, typename T_::template Apply<Container>, false>::type&() const { return reinterpret_cast<const typename T_::template Apply<Container>&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, typename T_::template Apply<Container>, false>::type&() { return reinterpret_cast<const typename T_::template Apply<Container>&>(this->GetBaseRef()); }
	};
	template <typename ST, typename T_ = ParameterPack<>> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type, T_>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type, T_>, ReferenceFunctionsImpl<typename ST::type, T_>>::type> { };
};
template <typename... T_> class ContainerInterface : public GenericContainerInterface::Hxx1::template ReferenceFunctionsHelper<maxon::details::DirectInstance<ContainerInterface<T_...>, GenericContainerInterface>, maxon::ParameterPack<T_...>>::type
{
public:
	using ErasedType = GenericContainerInterface;
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = ContainerInterface<typename MAP<T_>::type...>;
	};
};
template <typename T_> class GenericContainerInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<typename T_::template Apply<Container>>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const typename T_::template Apply<ContainerInterface>, maxon::StrongCOWRefHandler, typename T_::template Apply<Container>>>, T_>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const typename T_::template Apply<ContainerInterface>, maxon::StrongCOWRefHandler, typename T_::template Apply<Container>>>, T_>>);
	using NonConst = Hxx1::NonConstRef<T_>;
};

template <typename T_> class GenericContainerInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef<T_>>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<typename T_::template Apply<ContainerInterface>, maxon::StrongRefHandler, NonConstRef<T_>>>, T_>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<typename T_::template Apply<ContainerInterface>, maxon::StrongRefHandler, NonConstRef<T_>>>, T_>>);
};

/// Container is the reference class of GenericContainerInterface.
template <typename... T_> class Container : public GenericContainerInterface::Hxx1::template Reference<maxon::ParameterPack<T_...>>
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Container, typename GenericContainerInterface::Hxx1::template Reference<maxon::ParameterPack<T_...>>);
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = Container<typename MAP<T_>::type...>;
	};
};

#endif
