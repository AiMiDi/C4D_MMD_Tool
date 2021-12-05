#if 1
class StringEncodingRef;

struct StringEncodingInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, StringEncodingInterface>::value || StreamConversionInterface::HasBase::template Check<I>::value; static I* Cast(StringEncodingInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct StringEncodingInterface::Hxx1
{
	class Reference;
	using ReferenceClass = StringEncodingRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<StreamConversionInterface>;
	/// Intermediate helper class for StringEncodingInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for StringEncodingInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, StringEncodingRef, true>::type&() const { return reinterpret_cast<const StringEncodingRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, StringEncodingRef, false>::type&() { return reinterpret_cast<const StringEncodingRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for StringEncodingInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, StringEncodingRef, false>::type&() { return reinterpret_cast<const StringEncodingRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename StreamConversionInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename StreamConversionInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename StreamConversionInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class StringEncodingInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<StringEncodingRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<StringEncodingInterface, maxon::StrongRefHandler, StringEncodingRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<StringEncodingInterface, maxon::StrongRefHandler, StringEncodingRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// StringEncodingRef is the reference class of StringEncodingInterface.
///
/// Specialized Type of StreamConversionInterface for type safe usage in strings.
/// A StringEncodingRef is able to convert Utf32Char to UChar data.
class StringEncodingRef : public StringEncodingInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(StringEncodingRef, typename StringEncodingInterface::Hxx1::Reference);
};

class StringDecodingRef;

struct StringDecodingInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, StringDecodingInterface>::value || StreamConversionInterface::HasBase::template Check<I>::value; static I* Cast(StringDecodingInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct StringDecodingInterface::Hxx1
{
	class Reference;
	using ReferenceClass = StringDecodingRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<StreamConversionInterface>;
	/// Intermediate helper class for StringDecodingInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for StringDecodingInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, StringDecodingRef, true>::type&() const { return reinterpret_cast<const StringDecodingRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, StringDecodingRef, false>::type&() { return reinterpret_cast<const StringDecodingRef&>(this->GetBaseRef()); }
	};
	/// Intermediate helper class for StringDecodingInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, StringDecodingRef, false>::type&() { return reinterpret_cast<const StringDecodingRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename StreamConversionInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename StreamConversionInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename StreamConversionInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class StringDecodingInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<StringDecodingRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<StringDecodingInterface, maxon::StrongRefHandler, StringDecodingRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<StringDecodingInterface, maxon::StrongRefHandler, StringDecodingRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// StringDecodingRef is the reference class of StringDecodingInterface.
///
/// Specialized Type of StreamConversionInterface for type safe usage in strings.
/// A StringDecodingRef is able to convert UChar to Utf32Char data.
class StringDecodingRef : public StringDecodingInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(StringDecodingRef, typename StringDecodingInterface::Hxx1::Reference);
};

#endif
