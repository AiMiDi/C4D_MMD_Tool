#if 1
class JsonParserRef;

struct JsonParserInterface::Hxx1
{
	class Reference;
	using ReferenceClass = JsonParserRef;
	/// Intermediate helper class for JsonParserInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for JsonParserInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, JsonParserRef, true>::type&() const { return reinterpret_cast<const JsonParserRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, JsonParserRef, false>::type&() { return reinterpret_cast<const JsonParserRef&>(this->GetBaseRef()); }
/// ConvertToJSON converts a data dictionary into a JSON string.
/// @param[in] jsonObject					DataDictionary to convert.
/// @param[out] jsonString				Result string.
/// @param[in] niceFormatting			True to have nict formatting with idents and new lines. False to get compact format (smaller filesize).
/// @return												OK on success.
		inline Result<void> Write(const DataDictionary& jsonObject, String& jsonString, Bool niceFormatting) const;
/// ConvertFromJSON parses a json string into DataDictionary representation.
/// @param[in] jsonString					JSON formated string to precess.
/// @param[in] flags							See JSONPARSERFLAGS.
/// @param[in] jsonObjects				ValueReceiver which receives all processed DataDictionaries.
/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
		inline Result<void> Read(const String& jsonString, JSONPARSERFLAGS flags, const ValueReceiver<const DataDictionary&>& jsonObjects) const;
/// ConvertFromJSON parses a json stream or url into DataDictionary representation.
/// @param[in] nameOrStream				JSON formated input stream or file url.
/// @param[in] flags							See JSONPARSERFLAGS.
/// @param[in] jsonObjects				ValueReceiver which receives all processed DataDictionaries.
/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
		inline Result<void> Read(UrlOrInputStream&& nameOrStream, JSONPARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& jsonObjects) const;
	};
	/// Intermediate helper class for JsonParserInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, JsonParserRef, false>::type&() { return reinterpret_cast<const JsonParserRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class JsonParserInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<JsonParserRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<JsonParserInterface, maxon::StrongRefHandler, JsonParserRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<JsonParserInterface, maxon::StrongRefHandler, JsonParserRef>>>>);
	using NonConst = typename Super::ReferenceClass;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<JsonParserRef> Create();
};

/// JsonParserRef is the reference class of JsonParserInterface.
class JsonParserRef : public JsonParserInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(JsonParserRef, typename JsonParserInterface::Hxx1::Reference);
};

#endif
