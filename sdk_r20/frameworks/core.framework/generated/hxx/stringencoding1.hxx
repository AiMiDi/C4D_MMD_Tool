#if 1
struct StringEncodingInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, StringEncodingInterface>::value || StreamConversionInterface::HasBase::Check<I>::value; static I* Cast(StringEncodingInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class StringEncodingRef;

struct StringEncodingInterface::ReferenceClassHelper { using type = StringEncodingRef; };

/// Intermediate helper class for StringEncodingInterface.
template <typename S> class StringEncodingInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class StringEncodingInterface::ConstReferenceFunctionsImplDoxy : public StringEncodingInterface::ConstReferenceFunctionsImpl<REF>, public StreamConversionInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for StringEncodingInterface.
template <typename S> class StringEncodingInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, StringEncodingRef, true>::type&() const { return reinterpret_cast<const StringEncodingRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, StringEncodingRef, false>::type&() { return reinterpret_cast<const StringEncodingRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class StringEncodingInterface::ReferenceFunctionsImplDoxy : public StringEncodingInterface::ReferenceFunctionsImpl<REF>, public StreamConversionInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for StringEncodingInterface.
template <typename S> class StringEncodingInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, StringEncodingRef, false>::type&() { return reinterpret_cast<const StringEncodingRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class StringEncodingInterface::COWReferenceFunctionsImplDoxy : public StringEncodingInterface::COWReferenceFunctionsImpl<REF>, public StreamConversionInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct StringEncodingInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename StreamConversionInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename StreamConversionInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename StreamConversionInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class StringEncodingInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<StringEncodingRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<StringEncodingInterface, maxon::StrongRefHandler, StringEncodingRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<StringEncodingInterface, maxon::StrongRefHandler, StringEncodingRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// StringEncodingRef is the reference class of StringEncodingInterface.
///
/// Specialized Type of StreamConversionInterface for type safe usage in strings.
/// A StringEncodingRef is able to convert Utf32Char to UChar data.
class StringEncodingRef : public StringEncodingInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(StringEncodingRef, Reference);
};

struct StringDecodingInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, StringDecodingInterface>::value || StreamConversionInterface::HasBase::Check<I>::value; static I* Cast(StringDecodingInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class StringDecodingRef;

struct StringDecodingInterface::ReferenceClassHelper { using type = StringDecodingRef; };

/// Intermediate helper class for StringDecodingInterface.
template <typename S> class StringDecodingInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class StringDecodingInterface::ConstReferenceFunctionsImplDoxy : public StringDecodingInterface::ConstReferenceFunctionsImpl<REF>, public StreamConversionInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for StringDecodingInterface.
template <typename S> class StringDecodingInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, StringDecodingRef, true>::type&() const { return reinterpret_cast<const StringDecodingRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, StringDecodingRef, false>::type&() { return reinterpret_cast<const StringDecodingRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class StringDecodingInterface::ReferenceFunctionsImplDoxy : public StringDecodingInterface::ReferenceFunctionsImpl<REF>, public StreamConversionInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for StringDecodingInterface.
template <typename S> class StringDecodingInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, StringDecodingRef, false>::type&() { return reinterpret_cast<const StringDecodingRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class StringDecodingInterface::COWReferenceFunctionsImplDoxy : public StringDecodingInterface::COWReferenceFunctionsImpl<REF>, public StreamConversionInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct StringDecodingInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename StreamConversionInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename StreamConversionInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename StreamConversionInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class StringDecodingInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<StringDecodingRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<StringDecodingInterface, maxon::StrongRefHandler, StringDecodingRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<StringDecodingInterface, maxon::StrongRefHandler, StringDecodingRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// StringDecodingRef is the reference class of StringDecodingInterface.
///
/// Specialized Type of StreamConversionInterface for type safe usage in strings.
/// A StringDecodingRef is able to convert UChar to Utf32Char data.
class StringDecodingRef : public StringDecodingInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(StringDecodingRef, Reference);
};

#endif
