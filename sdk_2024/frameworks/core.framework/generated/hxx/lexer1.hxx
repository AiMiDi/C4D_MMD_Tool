#if 1
class LexerRef;

struct LexerInterface::Hxx1
{
	class Reference;
	using ReferenceClass = LexerRef;
	/// Intermediate helper class for LexerInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = LexerInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(LexerInterface**);
/// Returns the current symbol
		inline HXXADDRET2(LEXERSYMBOL) GetSymbol() const;
/// Returns the number of leading spaces of the symbol. Tabs count as up to 8 spaces.
		inline HXXADDRET2(Int) GetLeadingSpace() const;
/// Returns the current String ident.
		inline HXXADDRET2(String) GetIdent() const;
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
/// Returns the position of the current symbol.
/// @return												The position of the current symbol.
		inline Result<Int64> GetSymbolPosition() const;
/// Checks against the current identifier.
/// @param[in] cmp								C-style string to compare with.
/// @return												Returns true if identical.
		inline HXXADDRET2(Bool) CheckIdent(const Char* cmp) const;
/// Checks against the current identifier.
/// @param[in] cmp								String to compare with.
/// @return												Returns true if identical.
		inline HXXADDRET2(Bool) CheckIdent(const String& cmp) const;
/// Returns the current line number within the file.
		inline HXXADDRET2(Int) GetLine() const;
	};
	/// Intermediate helper class for LexerInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = LexerInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(LexerInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LexerRef, true>::type&() const { return reinterpret_cast<const LexerRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, LexerRef, false>::type&() { return reinterpret_cast<const LexerRef&>(this->GetBaseRef()); }
/// Initializes the lexer class. This functions opens the stream.
/// @param[in] fileName						Url or Input Stream.
/// @param[in] flags							Control flags for the lexer. See LEXERINITFLAGS for description.
/// @param[in] stringEscapeCharacters	Defines characters that allow to escape \" ' and the escape character itself within strings. By Default this is '\'.
/// @param[in] stringDecoding			String encoding for this file. If a nullptr is passed (recommended) then StreamConversions::UtfTextDecoder will be used to auto-detect the file encoding.
/// @param[in] firstParseFlag			The lexer will parse the first symbol from the file with ReadNextSymbol. This flag will be passed to the call.
/// @return												OK on success.
		inline Result<void> Init(UrlOrInputStream&& fileName, LEXERINITFLAGS flags, const String& stringEscapeCharacters, const StringDecodingRef& stringDecoding, LEXERSYMBOLFLAGS firstParseFlag = LEXERSYMBOLFLAGS::NONE) const;
/// Adds an operator symbol to the lexer. This is a symbol which consists of several non-letter characters
/// such as && or +=. The lexer will then return such a character sequence as a single symbol of type LEXERSYMBOL::OPERATOR.
/// @param[in] chars							The symbol to add.
		inline Result<void> AddOperator(const String& chars) const;
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
		inline HXXADDRET2(void) RewindSymbol() const;
/// Sets the quote characters that are used to detect Strings when LEXERSYMBOLFLAGS::ALLOWSTRINGS is used.
/// @param[in] quoteChar	Defines characters that is used to detect quoted strings. By Default this is "\"'".
		inline HXXADDRET2(void) SetStringQuoteCharacters(const String& quoteChar) const;
	};
	/// Intermediate helper class for LexerInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = LexerInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(LexerInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, LexerRef, false>::type&() { return reinterpret_cast<const LexerRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ST::type>, Fn<typename ST::type>>::type
	> { };
};
class LexerInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<LexerRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<LexerInterface, maxon::StrongRefHandler, LexerRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<LexerInterface, maxon::StrongRefHandler, LexerRef>>>>);
	using NonConst = typename Super::ReferenceClass;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<LexerRef> Create();
};

/// LexerRef is the reference class of LexerInterface.
///
/// Lexer class. This class provides functionality to scan text files.
/// the stream is tokenized for easy reading.
class LexerRef : public LexerInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(LexerRef, typename LexerInterface::Hxx1::Reference);
	using ConstPtr = typename LexerInterface::ConstPtr;
};

#endif
