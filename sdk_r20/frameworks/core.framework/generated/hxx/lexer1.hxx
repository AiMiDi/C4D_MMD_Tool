#if 1
class LexerRef;

struct LexerInterface::ReferenceClassHelper { using type = LexerRef; };

/// Intermediate helper class for LexerInterface.
template <typename S> class LexerInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Returns the current symbol
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<LEXERSYMBOL>, LEXERSYMBOL>::type GetSymbol() const;
/// Returns a non-zero value if the symbol had a leading space
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetLeadingSpace() const;
/// Returns the current String ident.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type GetIdent() const;
/// In case of LEXERSYMBOL::NUMBER this function returns the floating point value of this number.
/// @param[out] val								Reference to the value.
	inline Result<void> GetFloat(Float32& val) const;
/// In case of LEXERSYMBOL::NUMBER this function returns the floating point value of this number.
/// @param[in] val								Reference to the value.
	inline Result<void> GetFloat(Float64& val) const;
/// In case of LEXERSYMBOL::NUMBER this function returns the integer value of this number.
/// @param[in] val								Reference to the value.
	inline Result<void> GetInt(Int32& val) const;
/// In case of LEXERSYMBOL::NUMBER this function returns the integer value of this number.
/// @param[in] val								Reference to the value.
	inline Result<void> GetInt(Int64& val) const;
/// In case of LEXERSYMBOL::NUMBER this function returns the integer value of this number.
/// @param[in] val								Reference to the value.
	inline Result<void> GetUInt(UInt32& val) const;
/// In case of LEXERSYMBOL::NUMBER this function returns the integer value of this number.
/// @param[in] val								Reference to the value.
	inline Result<void> GetUInt(UInt64& val) const;
/// Returns the current reading position
	inline Result<Int64> GetCurrentReadPosition() const;
/// Checks against the current identifier.
/// @param[in] cmp								C-style string to compare with.
/// @return												Returns true if identical.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CheckIdent(const Char* cmp) const;
/// Checks against the current identifier.
/// @param[in] cmp								String to compare with.
/// @return												Returns true if identical.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type CheckIdent(const String& cmp) const;
/// Returns the current line number within the file.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetLine() const;
};
#ifdef DOXYGEN
template <typename REF> class LexerInterface::ConstReferenceFunctionsImplDoxy : public LexerInterface::ConstReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for LexerInterface.
template <typename S> class LexerInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LexerRef, true>::type&() const { return reinterpret_cast<const LexerRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LexerRef, false>::type&() { return reinterpret_cast<const LexerRef&>(this->GetBaseRef()); }
/// Initializes the lexer class. This functions opens the stream.
/// @param[in] fileName						Url or Input Stream.
/// @param[in] flags							Control flags for the lexer. See LEXERINITFLAGS for description.
/// @param[in] stringEscapeCharacters	Defines characters that allow to escape \" ' and the escape character itself within strings. By Default this is '\'.
/// @param[in] stringDecoding			String encoding for this file. If a nullptr is passed (recommended) then StreamConversions::UtfTextDecoder will be used to auto-detect the file encoding.
/// @return												OK on success.
	inline Result<void> Init(UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding) const;
/// Closes the stream
	inline Result<void> Close() const;
/// Reads the next character out of the stream.
/// @return												Returns the character that has been read. This function returns 0 if the end of the file has been reached.
	inline Result<Utf32Char> ReadNextChar() const;
/// Skips the spaces from the current position.
/// @return												True if the function was successful. False if the end of the file has been reached.
	inline Result<Bool> SkipSpaces() const;
/// Skips line to the end.
/// If the lexer is in NEED_EOL mode the method stops at line end. Otherwise it will advance
/// to the next line and stops when non-whitespace is found.
/// @param[in] collectSkipped			If true then the skipped bytes are returned with the next GetIdent() call.
/// @return												True if the function was successful. False if the end of the file has been reached. Otherwise an error.
	inline Result<Bool> SkipLineToEnd(Bool collectSkipped = false) const;
/// Reads the next symbol in the stream. GetIdent() returns the name of the symbol/ident/number/operator.
/// @param[in] flags							See LEXERSYMBOLFLAGS for details.
/// @return												Next detected symbol. LEXERSYMBOL::ENDOFFILE if the end of file has been reached.
	inline Result<LEXERSYMBOL> ReadNextSymbol(LEXERSYMBOLFLAGS flags = LEXERSYMBOLFLAGS::NONE) const;
/// Reads the next symbol in the stream and checks if it's identical to requiredSymbols. GetIdent() returns the name of the symbol/ident/number/operator.
/// @param[in] expectedSymbols		Symbol that is required.
/// @param[in] flags							See LEXERSYMBOLFLAGS for details.
/// @return												Next detected symbol. LEXERSYMBOL::ENDOFFILE if the end of file has been reached.
	inline Result<void> ReadNextSymbolExpected(LEXERSYMBOL expectedSymbols, LEXERSYMBOLFLAGS flags = LEXERSYMBOLFLAGS::NONE) const;
/// Rewinds the current symbol so that the next ReadNextSymbol returns exactly the same as before.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type RewindSymbol() const;
};
#ifdef DOXYGEN
template <typename REF> class LexerInterface::ReferenceFunctionsImplDoxy : public LexerInterface::ReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for LexerInterface.
template <typename S> class LexerInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, LexerRef, false>::type&() { return reinterpret_cast<const LexerRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class LexerInterface::COWReferenceFunctionsImplDoxy : public LexerInterface::COWReferenceFunctionsImpl<REF> { };
#endif

template <typename ST> struct LexerInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type>::type; };
class LexerInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<LexerRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<LexerInterface, maxon::StrongRefHandler, LexerRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<LexerInterface, maxon::StrongRefHandler, LexerRef>>>>);
	using NonConst = Super::ReferenceClass;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<LexerRef> Create();
};

/// LexerRef is the reference class of LexerInterface.
///
/// Lexer class. This class provides functionality to scan text files.
/// the stream is tokenized for easy reading.
class LexerRef : public LexerInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(LexerRef, Reference);
};

#endif
