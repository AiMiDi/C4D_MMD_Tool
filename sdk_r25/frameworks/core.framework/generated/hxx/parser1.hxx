#if 1
namespace PARSERPARAMETERS
{
#ifndef PRIVATE_MAXON_GUARD_maxon_PARSERPARAMETERS
#define PRIVATE_MAXON_GUARD_maxon_PARSERPARAMETERS
	class RESTRICT : public maxon::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
#endif
	namespace JWT
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_PARSERPARAMETERS_JWT
	#define PRIVATE_MAXON_GUARD_maxon_PARSERPARAMETERS_JWT
		class RESTRICT : public PARSERPARAMETERS::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
	}
	namespace CSV
	{
	#ifndef PRIVATE_MAXON_GUARD_maxon_PARSERPARAMETERS_CSV
	#define PRIVATE_MAXON_GUARD_maxon_PARSERPARAMETERS_CSV
		class RESTRICT : public PARSERPARAMETERS::RESTRICT { }; template <typename T> RESTRICT TestRestriction(T y, maxon::OverloadRank1);
	#endif
	}
}
class ParserRef;

struct ParserInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, ParserInterface>::value || DataDictionaryObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(ParserInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct ParserInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ParserRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<DataDictionaryObjectInterface>;
	/// Intermediate helper class for ParserInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using RESTRICT_DICTIONARY_PROPS = ParserInterface::RESTRICT_DICTIONARY_PROPS;
/// GetFileExtension gives the file extension of the parser.
/// @return the file extension as a string.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetFileExtension() const;
	};
	/// Intermediate helper class for ParserInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ParserRef, true>::type&() const { return reinterpret_cast<const ParserRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ParserRef, false>::type&() { return reinterpret_cast<const ParserRef&>(this->GetBaseRef()); }
/// ConvertFromJWT converts a JWT token into a json DataDictionary. For more details of JWT see https://jwt.io/
/// @param[in] nameOrStream				JSON formated input stream or file url.
/// @param[in] flags							See JWTPARSERFLAGS.
/// @param[in] objects				ValueReceiver which receives all processed DataDictionaries.
/// @param[out] originalToken			[Optional] Returns the original token memory read from the stream.
/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
		inline Result<void> Read(UrlOrInputStream&& nameOrStream, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects, BaseArray<Char>* originalToken = nullptr) const;
/// ConvertFromJSON parses a json string into DataDictionary representation.
/// @param[in] parserData					JSON formated string to precess.
/// @param[in] flags							See JSONPARSERFLAGS.
/// @param[in] stringDecoding				ValueReceiver which receives all processed DataDictionaries.
/// @param[in] objects						ValueReceiver which receives all processed DataDictionaries.
/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
		inline Result<void> ReadString(const Block<const Char>& parserData, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects) const;
		inline Result<void> ReadString(const String& text, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects) const;
/// ConvertToJSON converts a data dictionary into a JSON string.
/// @param[in] object							DataDictionary to convert.
/// @param[out] string						Result string.
/// @param[in] niceFormatting			True to have nice formatting with indents and new lines. False to get compact format (smaller filesize).
/// @return												OK on success.
		inline Result<void> Write(const DataDictionary& object, String& string, Bool niceFormatting) const;
/// WriteFile writes a object into a file or url.
/// @param[in] out								Url or stream to write.
/// @param[in] stringEncoding			String encoding to use.
/// @param[in] dict								Data to write.
/// @param[in] niceFormatting			True to have nice formatting with indents and new lines. False to get compact format (smaller filesize).
/// @return                       OK on success.
		inline Result<void> WriteFile(UrlOrOutputStream&& out, const StringEncodingRef& stringEncoding, const DataDictionary& dict, Bool niceFormatting) const;
	};
	/// Intermediate helper class for ParserInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ParserRef, false>::type&() { return reinterpret_cast<const ParserRef&>(this->GetBaseRef()); }
/// ConvertFromJWT converts a JWT token into a json DataDictionary. For more details of JWT see https://jwt.io/
/// @param[in] nameOrStream				JSON formated input stream or file url.
/// @param[in] flags							See JWTPARSERFLAGS.
/// @param[in] objects				ValueReceiver which receives all processed DataDictionaries.
/// @param[out] originalToken			[Optional] Returns the original token memory read from the stream.
/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
		inline Result<void> Read(UrlOrInputStream&& nameOrStream, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects, BaseArray<Char>* originalToken = nullptr);
/// ConvertFromJSON parses a json string into DataDictionary representation.
/// @param[in] parserData					JSON formated string to precess.
/// @param[in] flags							See JSONPARSERFLAGS.
/// @param[in] stringDecoding				ValueReceiver which receives all processed DataDictionaries.
/// @param[in] objects						ValueReceiver which receives all processed DataDictionaries.
/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
		inline Result<void> ReadString(const Block<const Char>& parserData, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects);
		inline Result<void> ReadString(const String& text, PARSERFLAGS flags, const StringDecodingRef& stringDecoding, const ValueReceiver<const DataDictionary&>& objects);
/// ConvertToJSON converts a data dictionary into a JSON string.
/// @param[in] object							DataDictionary to convert.
/// @param[out] string						Result string.
/// @param[in] niceFormatting			True to have nice formatting with indents and new lines. False to get compact format (smaller filesize).
/// @return												OK on success.
		inline Result<void> Write(const DataDictionary& object, String& string, Bool niceFormatting);
/// WriteFile writes a object into a file or url.
/// @param[in] out								Url or stream to write.
/// @param[in] stringEncoding			String encoding to use.
/// @param[in] dict								Data to write.
/// @param[in] niceFormatting			True to have nice formatting with indents and new lines. False to get compact format (smaller filesize).
/// @return                       OK on success.
		inline Result<void> WriteFile(UrlOrOutputStream&& out, const StringEncodingRef& stringEncoding, const DataDictionary& dict, Bool niceFormatting);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename DataDictionaryObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type
	> { };
};
class ParserInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<ParserRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ParserInterface, maxon::StrongRefHandler, ParserRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ParserInterface, maxon::StrongRefHandler, ParserRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// ParserRef is the reference class of ParserInterface.
class ParserRef : public ParserInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ParserRef, typename ParserInterface::Hxx1::Reference);
	using ConstPtr = typename ParserInterface::ConstPtr;
};

#endif
