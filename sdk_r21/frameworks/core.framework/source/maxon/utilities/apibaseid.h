#ifndef APIBASEID_H__
#define APIBASEID_H__

#ifndef APIBASE_H__
	#error "Do not include this file directly"
#endif

/// @file
/// String based id

namespace maxon
{

/// @addtogroup DATATYPE
/// @{

// Only used by Id.
class RefCountedCString
{
public:
	static RefCountedCString* Alloc(Int len);
	
	void AddReference() const;
	void RemoveReference() const;
	
	operator const Char*() const
	{
		return _string;
	}
	
	operator Char*()
	{
		return _string;
	}
	
private:
	RefCountedCString() = delete;
	~RefCountedCString() = delete;
	
	Char _string[MAXON_FLEXIBLE_ARRAY_LENGTH];
};

template <typename T> class ResultMemT;

using ResultMem = ResultMemT<Bool>;


//----------------------------------------------------------------------------------------
/// LiteralId is used as base class of Id. It may only be used for strings such as string
/// literals which have a longer lifetime than the LiteralId object itself. The benefit
/// is that LiteralId is a literal type and has a trivial destructor.
//----------------------------------------------------------------------------------------
class LiteralId
{
public:
	static const Int MAX_LENGTH_EXPONENT = 20;
	static const UInt LOW_HASH_MASK = (UInt)(Int)-1 >> (MAX_LENGTH_EXPONENT + 1); ///< Mask for the lower bits of the hash (the part which corresponds to the hash code of the string).
protected:
	static const Int RC_STRING_BIT = SIZEOF(Int) * 8 - MAX_LENGTH_EXPONENT - 1; ///< Bit position in _hash of the bit which is set when the Id uses a RefCountedCString.
	static const UInt RC_STRING_MASK = (UInt) 1 << RC_STRING_BIT; ///< Mask to get the #RC_STRING_BIT from _hash.
	static const UInt HASH_MASK = ~RC_STRING_MASK; ///< Mask to get the hash code from _hash.

public:
	constexpr LiteralId() : _value(nullptr), _hash(0)
	{
	}

	LiteralId(const LiteralId&) = default;
	MAXON_IMPLICIT LiteralId(const Id&) = delete;

	LiteralId& operator =(const LiteralId&) = default;
	LiteralId& operator =(const Id&) = delete;

	template <UInt N> explicit constexpr LiteralId(const Char (&str)[N]) : _value(str), _hash(GetHashCode<N>(str))
	{
		static_assert(N > 1, "str must have a length");
	}

	Bool operator ==(const LiteralId& other) const
	{
		if ((_hash ^ other._hash) & HASH_MASK)
			return false;
		if (_value == other._value)
			return true;
		if (!_value || !other._value)
			return false;
		// If the hash values are equal, the lengths are equal, too. Also note that we check starting at the end as ids tend to have a common prefix.
		for (Int i = GetCStringLength() - 1; i >= 0; i--)
		{
			if (_value[i] != other._value[i])
			{
				return false;
			}
		}
		return true;
	}

	Bool operator <(const LiteralId& other) const
	{
		if (_value == other._value)
			return false;
		if (!_value)
			return true;
		if (!other._value)
			return false;
		return strcmp(_value, other._value) < 0;
	}

	MAXON_OPERATOR_COMPARISON(LiteralId);

	//----------------------------------------------------------------------------------------
	/// Compares two Id objects using the lexicographic order.
	/// @param[in] other							Other Id object.
	/// @return												See COMPARERESULT.
	//----------------------------------------------------------------------------------------
	COMPARERESULT Compare(const LiteralId& other) const
	{
		if (_value == other._value)
			return COMPARERESULT::EQUAL;
		if (!_value)
			return COMPARERESULT::LESS;
		if (!other._value)
			return COMPARERESULT::GREATER;
		Int res = strcmp(_value, other._value);
		return (res < 0) ? COMPARERESULT::LESS : (res > 0) ? COMPARERESULT::GREATER : COMPARERESULT::EQUAL;
	}

	UInt GetHashCode() const
	{
		return _hash & HASH_MASK;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the Id is empty.
	/// @return												True if the Id contains a nullptr as c-string.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const
	{
		return _value == nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this Id contains anything.
	/// @return												True if the ID contains a c-string.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return _value != nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the internal c-string. No copy is made.
	/// @return												Internal string.
	//----------------------------------------------------------------------------------------
	const Char* GetCString() const
	{
		return _value;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the length of the internal c-string. This function doesn't have to scan the string,
	/// because the length is directly available in the Id.
	/// @return												Length of internal string.
	//----------------------------------------------------------------------------------------
	Int GetCStringLength() const
	{
		return (Int)(_hash >> (sizeof(Int) * 8 - MAX_LENGTH_EXPONENT));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	String ToString(const FormatStatement* formatStatement) const;

	CString ToCString() const;

	Block<const Char> ToBlock() const;

	static const Int MAX_LENGTH = (1 << MAX_LENGTH_EXPONENT) - 1;

	const Id& Get() const
	{
		return *reinterpret_cast<const Id*>(this);
	}

	operator const Id&() const
	{
		return *reinterpret_cast<const Id*>(this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if this Id uses a RefCountedCString. Otherwise, the Id uses
	/// a global c-string which is assumed to persist at least as long as the Id.
	/// @return												True if the Id uses a RefCountedCString.
	//----------------------------------------------------------------------------------------
	Bool UsesRefCountedCString() const
	{
		return (_hash & RC_STRING_MASK) != 0;
	}

	template <UInt N> constexpr LiteralId(bool dummy, const Char (&str)[N]) : _value(str), _hash(GetHashCode<N>(str))
	{
		static_assert(N > 1, "str must have a length");
	}

	constexpr LiteralId(bool dummy, const LiteralId& src) : _value(src._value), _hash(src._hash)
	{
	}


	template <typename T, typename = typename T::DeclarationHelper> constexpr LiteralId(bool dummy, const T& decl) : LiteralId(T::DeclarationHelper::GetId())
	{
	}

protected:
	constexpr LiteralId(const Char* value, UInt hash) : _value(value), _hash(hash)
	{
	}

	explicit LiteralId(ENUM_DONT_INITIALIZE) { } // needed by EntityBase

	const Char* _value; ///< C-string identifier. If the #RC_STRING_BIT is set in _hash, this actually points to the _string part of a RefCountedCString.
	UInt _hash; ///< Combination of hash code (lower bits), then a bit at #RC_STRING_BIT and finally the string length (MAX_LENGTH_EXPONENT bits). Use #HASH_MASK to mask out the #RC_STRING_BIT.

	static UInt GetHashCode(const Char* str)
	{
		UInt h = 0;
		if (str)
		{
			UInt i = 0;
			
			for (; str[i]; ++i)
				h = 31 * h + (UChar) str[i];
				
			DebugAssert((Int) i <= MAX_LENGTH);
			// shift by MAX_LENGTH_EXPONENT+1 to clear the RC_STRING_BIT
#define PRIVATE_MAXON_ID_HASHCODE(hash, len) (((hash) & maxon::LiteralId::LOW_HASH_MASK) + ((len) << (SIZEOF(maxon::Int) * 8 - maxon::LiteralId::MAX_LENGTH_EXPONENT)))
			h = PRIVATE_MAXON_ID_HASHCODE(h, i);
		}
		return h;
	}
	
// Currently all compilers but Clang expect constexpr in one line without a loop.
//#ifndef MAXON_COMPILER_CLANG
	template <UInt N> static constexpr UInt GetHashCode(const Char (&str)[N], UInt h = 0, UInt i = 0)
	{
		return str[i] ? GetHashCode(str, h * 31 + UChar(str[i]), i + 1) : PRIVATE_MAXON_ID_HASHCODE(h, i);
	}
//#else
//	template <UInt N> static constexpr UInt GetHashCode(const Char (&str)[N])
//	{
//		UInt h = 0;
//		UInt i = 0;
//
//		// The loop can't use N because it might be bigger than the actual string length when a static buffer is used.
//		for (; str[i]; ++i)
//			h = 31 * h + (UChar) str[i];
//
//		return PRIVATE_MAXON_ID_HASHCODE(h, i);
//	}
//#endif

	friend class EntityBase;
};


//----------------------------------------------------------------------------------------
/// Id represents an identifier consisting of a c-string. Such identifiers are used mainly to identify entities
/// such as interfaces, components, classes, registries, entries, modules or published objects.
//----------------------------------------------------------------------------------------
class Id : public LiteralId
{
public:

	//----------------------------------------------------------------------------------------
	/// Constructs a null Id. The internal c-string will be nullptr.
	//----------------------------------------------------------------------------------------
	constexpr Id() : LiteralId(nullptr, 0)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs an Id for a given c-string. str is used directly for the internal c-string pointer.
	/// It is assumed that the c-string exists at least as long as the constructed Id.
	/// @param[in] str								Identifier as c-string, may be nullptr. This will always be used directly, i.e., no copy is made.
	//----------------------------------------------------------------------------------------
	explicit Id(const volatile Char* str) : LiteralId(const_cast<const Char*>(str), str ? GetHashCode(const_cast<const Char*>(str)) : 0)
	{
		// We've added volatile just to make the constructor template a better match than this function for a string literal argument.
		DebugAssert(!str || (str[0] > 0));
	}

	template <UInt N> explicit constexpr Id(const Char (&str)[N]) : LiteralId(str)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Constructs an Id by moving the values from another Id.
	/// @param[in] other							Another Id to move from.
	//----------------------------------------------------------------------------------------
	Id(Id&& other) : LiteralId(other._value, other._hash)
	{
		other._value = nullptr;
		other._hash = 0;
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructs an Id from another Id.
	/// @param[in] other							Another Id to copy from.
	//----------------------------------------------------------------------------------------
	Id(const Id& other) : LiteralId(other._value, other._hash)
	{
		if ((_hash & RC_STRING_MASK) != 0)
		{
			GetRCString()->AddReference();
		}
	}

	//----------------------------------------------------------------------------------------
	/// Destructs the Id. If the Id uses a RefCountedCString, the reference will be removed.
	//----------------------------------------------------------------------------------------
	~Id()
	{
		Reset();
	}

	static const Id& NullValue()
	{
		return GetZeroRef<Id>();
	}

	//----------------------------------------------------------------------------------------
	/// Resets the Id. Afterwards, its internal c-string will be nullptr.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		if ((_hash & RC_STRING_MASK) != 0)
		{
			GetRCString()->RemoveReference();
		}
		_hash = 0;
		_value = nullptr;
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(Id);

	Id& operator =(const Id& other)
	{
		if (this != &other)
		{
			Reset();
			_value = other._value;
			_hash = other._hash;
			if ((_hash & RC_STRING_MASK) != 0)
			{
				GetRCString()->AddReference();
			}
		}
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Sets this Id to a new value. If copyString is false, str is used directly for the internal c-string pointer,
	/// and it is assumed that the c-string exists at least as long as this Id.
	/// Otherwise, if copyString is true, a RefCountedCString is created for str and used for the internal c-string.
	/// @param[in] str								Identifier as c-string, may be nullptr.
	/// @param[in] copyString					If true, a copy of str is made at first (as a RefCountedCString).
	/// @return												False if a copy had to be made, but the allocation failed. True otherwise.
	//----------------------------------------------------------------------------------------
	ResultMem Init(const Char* str, Bool copyString);

	//----------------------------------------------------------------------------------------
	/// Sets this Id to str. A RefCountedCString is created for str and used for the internal c-string.
	/// @param[in] str								Identifier as a block of characters (no null termination required).
	/// @return												False if the allocation for the RefCountedCString failed. True otherwise.
	//----------------------------------------------------------------------------------------
	ResultMem Init(const Block<const Char>& str);

	//----------------------------------------------------------------------------------------
	/// Sets this Id to str. A RefCountedCString is created for str and used for the internal c-string.
	/// @param[in] str								Identifier as CString.
	/// @return												False if the allocation for the RefCountedCString failed. True otherwise.
	//----------------------------------------------------------------------------------------
	ResultMem Init(const CString& str);

	//----------------------------------------------------------------------------------------
	/// Sets this Id to str. 
	/// @param[in] str								Identifier as String.
	/// @return												False if the allocation failed. True otherwise.
	//----------------------------------------------------------------------------------------
	ResultMem Init(const String& str);

	//----------------------------------------------------------------------------------------
	/// Sets this Id to id. 
	/// @param[in] id									Interned Id.
	//----------------------------------------------------------------------------------------
	void Init(const InternedId& id);

/// @cond INTERNAL

	//----------------------------------------------------------------------------------------
	/// Returns an Id which is the concatenation of a, b and c. The c-string of the result will
	/// exist until program termination. This is used internally by some entity macros.
	/// @param[in] a									Prefix string.
	/// @param[in] b									Infix string.
	/// @param[in] c									Postfix string.
	/// @return												Concatenation a + b + c as Id.
	//----------------------------------------------------------------------------------------
	static const Id& GetConcatenated(const Char* a, const Char* b, const Char* c);

	//----------------------------------------------------------------------------------------
	/// Returns an Id which is the concatenation of a, b and c. The c-string of the result will
	/// exist until program termination. This is used internally by some entity macros.
	/// @param[in] a									Prefix string.
	/// @param[in] b									Infix string.
	/// @param[in] c									Postfix string.
	/// @return												Concatenation a + b + c as Id.
	//----------------------------------------------------------------------------------------
	static const Id& GetConcatenated(const Char* a, const Char* b, const Id& c)
	{
		return GetConcatenated(a, b, c.GetCString());
	}
/// @endcond

private:
	explicit Id(const CString&) = delete; // without this, Id(const Char*) would be used when an Id is constructed by a CString, but this would crash as the Char-pointer of the CString might get invalid too early

	const RefCountedCString* GetRCString() const
	{
		DebugAssert((_hash & RC_STRING_MASK) != 0);
		return (const RefCountedCString*)_value;
	}
};


/// @}

} // namespace maxon

#endif // APIBASEID_H__
