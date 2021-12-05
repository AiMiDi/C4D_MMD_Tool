#if 1
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
		using GenericContainerInterfaceMarker = GenericContainerInterface::GenericContainerInterfaceMarker;
		using INTERFACES = GenericContainerInterface::INTERFACES;
		using S::GenericVarianceCheck;
		template <typename _S, typename _T> static typename std::integral_constant<bool, true && ContainerVariance<_T, T_>::value>::type GenericVarianceCheck(const ConstReferenceFunctionsImpl<_S, _T>*);
		template <typename _S> static typename std::true_type GenericVarianceCheck(ConstReferenceFunctionsImpl<_S, NamedTuple<>>*);
		template <typename DERIVED> struct IsGenericBaseOf { static const Bool value = S::template IsGenericBaseOf<DERIVED>::value && decltype(DERIVED::GenericVarianceCheck((ConstReferenceFunctionsImpl*) nullptr))::value; };
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const ContainerDataType<>&>, const ContainerDataType<>&>::type GetContainerType() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<INTERFACES>, INTERFACES>::type GetInterfaces() const;
		inline Result<GenericContainerInterface*> Clone(Bool cloneElements = true) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement = nullptr) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<HashValue>, HashValue>::type GetHashValue() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEqual(const GenericContainerInterface* other, EQUALITY equality) const;
/// Finds the member index of the member with the given #name in this. If no such member
/// can be found, -1 is returned.
/// @param[in] name								Name of the member to find.
/// @return												Index of the member, or -1 if it doesn't exist.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindMemberIndex(const InternedId& name) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindMemberIndex(const Member& member) const;
		inline Result<Int> GetCount() const;

	using Iterator = maxon::details::ContainerIterator<T, false>;
	using ConstIterator = maxon::details::ContainerIterator<T, true>;
	
		public:
	};
	/// Intermediate helper class for GenericContainerInterface.
	template <typename S, typename T_> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S, T_>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S, T_>;
		using PrivateBaseClass::PrivateBaseClass;
		using T = T_;
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
	template <typename ST, typename T_ = NamedTuple<>> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type, T_>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type, T_>, ReferenceFunctionsImpl<typename ST::type, T_>>::type> { };
};
template <typename... T_> class ContainerInterface : public GenericContainerInterface::Hxx1::template ReferenceFunctionsHelper<maxon::details::DirectInstance<ContainerInterface<T_...>, GenericContainerInterface>, NamedTuple<T_...>>::type
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
template <typename... T_> class Container : public GenericContainerInterface::Hxx1::template Reference<NamedTuple<T_...>>
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Container, typename GenericContainerInterface::Hxx1::template Reference<NamedTuple<T_...>>);
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = Container<typename MAP<T_>::type...>;
	};
};

#endif
