#if 1
template <typename... T_> class SingletonContainer;

struct GenericSingletonContainerInterface::Hxx1
{
	template <typename T_> class Reference;
	template <typename T_> class NonConstRef;
	using ReferenceClass = SingletonContainer<>;
	/// Intermediate helper class for GenericSingletonContainerInterface.
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
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const TupleDataType&>, const TupleDataType&>::type GetTupleType() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type GetMemberPointers(const Block<const Generic*>& pointers, const TupleDataType& members) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type GetMemberPointer(const InternedId& name) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type GetAllMemberPointers(const Block<const Generic*>& pointers, Bool skipPointersIfTupleLayout) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic&>, const Generic&>::type Get(Int index) const;
		template <typename ATTR> inline typename std::conditional<S::HAS_ERROR, maxon::Result<Opt<const typename ATTR::ValueType&>>, Opt<const typename ATTR::ValueType&>>::type Get() const;
	};
	/// Intermediate helper class for GenericSingletonContainerInterface.
	template <typename S, typename T_> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S, T_>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S, T_>;
		using PrivateBaseClass::PrivateBaseClass;
		using T = T_;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type GetMemberPointers(const Block<Generic*>& pointers, const TupleDataType& members) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type GetMemberPointer(const InternedId& name) const;
	};
	/// Intermediate helper class for GenericSingletonContainerInterface.
	template <typename S, typename T_> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S, T_>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S, T_>;
		using PrivateBaseClass::PrivateBaseClass;
		using T = T_;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, typename T_::template Apply<SingletonContainer>, false>::type&() const { return reinterpret_cast<const typename T_::template Apply<SingletonContainer>&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, typename T_::template Apply<SingletonContainer>, false>::type&() { return reinterpret_cast<const typename T_::template Apply<SingletonContainer>&>(this->GetBaseRef()); }
	};
	template <typename ST, typename T_ = ParameterPack<>> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename GenericContainerInterface::Hxx1::template ReferenceFunctionsHelper<ST, T_>::type, T_>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename GenericContainerInterface::Hxx1::template ReferenceFunctionsHelper<ST, T_>::type, T_>, ReferenceFunctionsImpl<typename GenericContainerInterface::Hxx1::template ReferenceFunctionsHelper<ST, T_>::type, T_>>::type> { };
};
template <typename... T_> class SingletonContainerInterface : public GenericSingletonContainerInterface::Hxx1::template ReferenceFunctionsHelper<maxon::details::DirectInstance<SingletonContainerInterface<T_...>, GenericSingletonContainerInterface>, maxon::ParameterPack<T_...>>::type
{
public:
	using ErasedType = GenericSingletonContainerInterface;
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = SingletonContainerInterface<typename MAP<T_>::type...>;
	};
};
template <typename T_> class GenericSingletonContainerInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<typename T_::template Apply<SingletonContainer>>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const typename T_::template Apply<SingletonContainerInterface>, maxon::StrongCOWRefHandler, typename T_::template Apply<SingletonContainer>>>, T_>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const typename T_::template Apply<SingletonContainerInterface>, maxon::StrongCOWRefHandler, typename T_::template Apply<SingletonContainer>>>, T_>>);
	using NonConst = Hxx1::NonConstRef<T_>;
};

template <typename T_> class GenericSingletonContainerInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef<T_>>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<typename T_::template Apply<SingletonContainerInterface>, maxon::StrongRefHandler, NonConstRef<T_>>>, T_>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<typename T_::template Apply<SingletonContainerInterface>, maxon::StrongRefHandler, NonConstRef<T_>>>, T_>>);
};

/// SingletonContainer is the reference class of GenericSingletonContainerInterface.
template <typename... T_> class SingletonContainer : public GenericSingletonContainerInterface::Hxx1::template Reference<maxon::ParameterPack<T_...>>
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(SingletonContainer, typename GenericSingletonContainerInterface::Hxx1::template Reference<maxon::ParameterPack<T_...>>);
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = SingletonContainer<typename MAP<T_>::type...>;
	};
};

#endif
