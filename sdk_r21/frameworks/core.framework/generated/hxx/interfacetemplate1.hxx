#if 1
struct NumberBaseInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, NumberBaseInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(NumberBaseInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct NumberBaseInterface::Hxx1
{
	template <typename K_, Bool B_> class Reference;
	using ReferenceClass = NumberBaseRef<>;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for NumberBaseInterface.
	template <typename S, typename K_, Bool B_> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using K = K_;
		using S::GenericVarianceCheck;
		template <typename _S, typename _K> static typename std::integral_constant<bool, true && SpecialOut<_K, K_>::value>::type GenericVarianceCheck(const ConstReferenceFunctionsImpl<_S, _K, B_>*);
		template <typename _S> static typename std::true_type GenericVarianceCheck(ConstReferenceFunctionsImpl<_S, GenericRef<NumberBaseInterface>, false>*);
		template <typename DERIVED> struct IsGenericBaseOf { static const Bool value = S::template IsGenericBaseOf<DERIVED>::value && decltype(DERIVED::GenericVarianceCheck((ConstReferenceFunctionsImpl*) nullptr))::value; };
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<K_>, K_>::type Mul(const K_& x) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<NumberBaseRef<>>, NumberBaseRef<>>::type GenericMul(const NumberBaseRef<>& x) const;
	};
	/// Intermediate helper class for NumberBaseInterface.
	template <typename S, typename K_, Bool B_> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S, K_, B_>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S, K_, B_>;
		using PrivateBaseClass::PrivateBaseClass;
		using K = K_;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, NumberBaseRef<K_, B_>, true>::type&() const { return reinterpret_cast<const NumberBaseRef<K_, B_>&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, NumberBaseRef<K_, B_>, false>::type&() { return reinterpret_cast<const NumberBaseRef<K_, B_>&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for NumberBaseInterface.
	template <typename S, typename K_, Bool B_> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S, K_, B_>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S, K_, B_>;
		using PrivateBaseClass::PrivateBaseClass;
		using K = K_;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, NumberBaseRef<K_, B_>, false>::type&() { return reinterpret_cast<const NumberBaseRef<K_, B_>&>(this->GetBaseRef()); }
	};
	template <typename ST, typename K_ = GenericRef<NumberBaseInterface>, Bool B_ = false> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type, K_, B_>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type, K_, B_>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type, K_, B_>>::type> { };
};
template <typename K_, Bool B_> class NumberBaseInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NumberBaseRef<K_, B_>>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<NumberBaseInterface, maxon::StrongRefHandler, NumberBaseRef<K_, B_>>>, K_, B_>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<NumberBaseInterface, maxon::StrongRefHandler, NumberBaseRef<K_, B_>>>, K_, B_>>);
	using NonConst = typename Super::ReferenceClass;
};

/// NumberBaseRef is the reference class of NumberBaseInterface.
template <typename K_, Bool B_> class NumberBaseRef : public NumberBaseInterface::Hxx1::template Reference<K_, B_>
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NumberBaseRef, typename NumberBaseInterface::Hxx1::template Reference<K_, B_>);
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = NumberBaseRef<typename MAP<K_>::type, B_>;
	};
};

template <typename T, Int X> struct NumberInterface<T, X>::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, NumberInterface>::value || NumberBaseInterface::HasBase::template Check<I>::value || ErrorInterface::HasBase::template Check<I>::value; static I* Cast(NumberInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
template <typename T, Int X> struct NumberInterface<T, X>::Hxx1
{
	template <typename K_> class Reference;
	using ReferenceClass = NumberRef<T, X>;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<NumberBaseInterface, ErrorInterface>;
	/// Intermediate helper class for NumberInterface.
	template <typename S, typename K_> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using K = K_;
		using S::GenericVarianceCheck;
		template <typename _S, typename _K> static typename std::integral_constant<bool, true && SpecialOut<_K, K_>::value>::type GenericVarianceCheck(const ConstReferenceFunctionsImpl<_S, _K>*);
		template <typename _S> static typename std::true_type GenericVarianceCheck(ConstReferenceFunctionsImpl<_S, GenericRef<NumberInterface>>*);
		template <typename DERIVED> struct IsGenericBaseOf { static const Bool value = S::template IsGenericBaseOf<DERIVED>::value && decltype(DERIVED::GenericVarianceCheck((ConstReferenceFunctionsImpl*) nullptr))::value; };
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<T>, T>::type Get1() const;
		static inline Result<NumberRef<T, X>> Create(T a, typename IntType<X>::type number);
	};
	/// Intermediate helper class for NumberInterface.
	template <typename S, typename K_> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S, K_>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S, K_>;
		using PrivateBaseClass::PrivateBaseClass;
		using K = K_;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, NumberRef<T, X, K_>, true>::type&() const { return reinterpret_cast<const NumberRef<T, X, K_>&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, NumberRef<T, X, K_>, false>::type&() { return reinterpret_cast<const NumberRef<T, X, K_>&>(this->GetBaseRef()); }
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Set(typename IntType<X>::type number, const T& v) const;
	};
	/// Intermediate helper class for NumberInterface.
	template <typename S, typename K_> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S, K_>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S, K_>;
		using PrivateBaseClass::PrivateBaseClass;
		using K = K_;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, NumberRef<T, X, K_>, false>::type&() { return reinterpret_cast<const NumberRef<T, X, K_>&>(this->GetBaseRef()); }
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Set(typename IntType<X>::type number, const T& v);
	};
	template <typename ST, typename K_ = GenericRef<NumberInterface>> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<typename NumberBaseInterface::Hxx1::template ReferenceFunctionsHelper<ST, K_, false>>::type, K_>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<typename NumberBaseInterface::Hxx1::template ReferenceFunctionsHelper<ST, K_, false>>::type, K_>, ReferenceFunctionsImpl<typename ErrorInterface::Hxx1::template ReferenceFunctionsHelper<typename NumberBaseInterface::Hxx1::template ReferenceFunctionsHelper<ST, K_, false>>::type, K_>>::type> { };
};
template <typename T, Int X> template <typename K_> class NumberInterface<T, X>::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NumberRef<T, X, K_>>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<NumberInterface<T, X>, maxon::StrongRefHandler, NumberRef<T, X, K_>>>, K_>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<NumberInterface<T, X>, maxon::StrongRefHandler, NumberRef<T, X, K_>>>, K_>>);
	using NonConst = typename Super::ReferenceClass;
};

/// NumberRef is the reference class of NumberInterface.
template <typename T, Int X, typename K_> class NumberRef : public NumberInterface<T, X>::Hxx1::template Reference<K_>
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NumberRef, typename NumberInterface<T, X>::Hxx1::template Reference<K_>);
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = NumberRef<typename MAP<T>::type, X, typename MAP<K_>::type>;
	};
};

template <typename T> class Number2Ref;

template <typename T> struct Number2Interface<T>::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, Number2Interface>::value || NumberInterface<T, 4>::HasBase::template Check<I>::value || NumberBaseInterface::HasBase::template Check<I>::value; static I* Cast(Number2Interface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
template <typename T> struct Number2Interface<T>::Hxx1
{
	class Reference;
	using ReferenceClass = Number2Ref<T>;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<NumberInterface<T, 4>, NumberBaseInterface>;
	/// Intermediate helper class for Number2Interface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		static inline Result<Int> Func(T a);
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<T>, T>::type Get2() const;
	};
	/// Intermediate helper class for Number2Interface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, Number2Ref<T>, true>::type&() const { return reinterpret_cast<const Number2Ref<T>&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, Number2Ref<T>, false>::type&() { return reinterpret_cast<const Number2Ref<T>&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for Number2Interface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, Number2Ref<T>, false>::type&() { return reinterpret_cast<const Number2Ref<T>&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename NumberBaseInterface::Hxx1::template ReferenceFunctionsHelper<typename NumberInterface<T, 4>::Hxx1::template ReferenceFunctionsHelper<ST, T>, T>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename NumberBaseInterface::Hxx1::template ReferenceFunctionsHelper<typename NumberInterface<T, 4>::Hxx1::template ReferenceFunctionsHelper<ST, T>, T>::type>, ReferenceFunctionsImpl<typename NumberBaseInterface::Hxx1::template ReferenceFunctionsHelper<typename NumberInterface<T, 4>::Hxx1::template ReferenceFunctionsHelper<ST, T>, T>::type>>::type> { };
};
template <typename T> class Number2Interface<T>::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<Number2Ref<T>>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<Number2Interface<T>, maxon::StrongRefHandler, Number2Ref<T>>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<Number2Interface<T>, maxon::StrongRefHandler, Number2Ref<T>>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// Number2Ref is the reference class of Number2Interface.
template <typename T> class Number2Ref : public Number2Interface<T>::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Number2Ref, typename Number2Interface<T>::Hxx1::Reference);
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = Number2Ref<typename MAP<T>::type>;
	};
};

extern template maxon::InterfaceReference NumberInterface<Int,4>::_interface;
extern template maxon::NonvirtualMTableReference NumberInterface<Int,4>::_nonvirtualMTable;
extern template maxon::NonvirtualInterfaceReference NumberInterface<Int,4>::_staticInterface;
extern template maxon::InterfaceReference Number2Interface<Int>::_interface;
extern template maxon::NonvirtualMTableReference Number2Interface<Int>::_nonvirtualMTable;
extern template maxon::NonvirtualInterfaceReference Number2Interface<Int>::_staticInterface;
#endif
