#if 1
class JwtParserRef;

struct JwtParserInterface::Hxx1
{
	class Reference;
	using ReferenceClass = JwtParserRef;
	/// Intermediate helper class for JwtParserInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for JwtParserInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, JwtParserRef, true>::type&() const { return reinterpret_cast<const JwtParserRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, JwtParserRef, false>::type&() { return reinterpret_cast<const JwtParserRef&>(this->GetBaseRef()); }
/// ConvertFromJWT converts a JWT token into a json DataDictionary. For more details of JWT see https://jwt.io/
/// @param[in] nameOrStream				JSON formated input stream or file url.
/// @param[in] flags							See JWTPARSERFLAGS.
/// @param[in] publicKey					RSA256 public key to verify the JWT token.
/// @param[in] jsonObjects				ValueReceiver which receives all processed DataDictionaries.
/// @param[out] originalToken			[Optional] Returns the original token memory read from the stream.	
/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
		inline Result<void> Read(UrlOrInputStream&& nameOrStream, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects, BaseArray<Char>* originalToken) const;
		inline Result<void> Read(const Block<const Char>& jwtString, JWTPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const Block<const Char>& publicKey, const ValueReceiver<const DataDictionary&>& jsonObjects) const;
		inline Result<CString> Write(const DataDictionary& jsonObject, const StringEncodingRef& stringEncoding, const Block<const Char>& privateKey) const;
	};
	/// Intermediate helper class for JwtParserInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, JwtParserRef, false>::type&() { return reinterpret_cast<const JwtParserRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class JwtParserInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<JwtParserRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<JwtParserInterface, maxon::StrongRefHandler, JwtParserRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<JwtParserInterface, maxon::StrongRefHandler, JwtParserRef>>>>);
	using NonConst = typename Super::ReferenceClass;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<JwtParserRef> Create();
};

/// JwtParserRef is the reference class of JwtParserInterface.
class JwtParserRef : public JwtParserInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(JwtParserRef, typename JwtParserInterface::Hxx1::Reference);
};

#endif
