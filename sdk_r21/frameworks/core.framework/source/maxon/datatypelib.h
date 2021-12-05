#ifndef DATATYPELIB_H__
#define DATATYPELIB_H__

#include "maxon/reflection_invocation.h"

namespace maxon
{

/// @addtogroup DATATYPE
/// @{


//----------------------------------------------------------------------------------------
/// InternedId represents an Id which has been interned into a pool of unique Id objects.
/// I.e., there are no two different Id objects with an equal id string, so for equality
/// comparison you can compare pointers instead of whole strings.
///
/// You can use MAXON_INTERNED_ID and MAXON_INTERNED_ID_LOCAL to define
/// interned ids which will be initialized automatically at module initialization.
///
/// InternedId uses reference counting, so where possible use @c{const InternedId&}
/// instead of InternedId to avoid unnecesssary reference counting.
//----------------------------------------------------------------------------------------
class InternedId
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs an empty InternedId. You have to initialize it afterwards using Init().
	//----------------------------------------------------------------------------------------
	InternedId() : _id(nullptr) { }

	InternedId(InternedId&& src) : _id(src._id)
	{
		src._id = nullptr;
	}

	InternedId& operator =(InternedId&& src)
	{
		if (this != &src)
		{
			Reset();
			_id = src._id;
			src._id = nullptr;
		}
		return *this;
	}

	InternedId(const InternedId& src) : _id(src._id)
	{
		if (_id)
			StrongReferenceCounter::Get(_id).Inc();
	}

	InternedId& operator =(const InternedId& src)
	{
		if (_id != src._id)
		{
			Reset();
			_id = src._id;
			if (_id)
				StrongReferenceCounter::Get(_id).Inc();
		}
		return *this;
	}

	~InternedId()
	{
		Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Initializes an InternedId with a given Id.
	/// @param[in] i									The id to intern.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Init(const Id& i);

	//----------------------------------------------------------------------------------------
	/// Initializes an InternedId with a given CString.
	/// @param[in] str								The string to intern.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Init(const CString& str);

	//----------------------------------------------------------------------------------------
	/// Initializes an InternedId with a given String.
	/// @param[in] str								The string to intern.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Init(const String& str);

	//----------------------------------------------------------------------------------------
	/// Initializes an InternedId with a given C-style string.
	/// @param[in] str								The string to intern.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Init(const Char* str);

	//----------------------------------------------------------------------------------------
	/// Initializes an InternedId with a given block of characters.
	/// @param[in] str								The string to intern, no null termination required.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> Init(const Block<const Char>& str);

	//----------------------------------------------------------------------------------------
	/// Returns the interned Id. The returned object is unique, i.e., there is no other
	/// interned Id with an equal string.
	/// @return												Interned Id.
	//----------------------------------------------------------------------------------------
	operator const Id&() const
	{
		return Get();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the interned Id. The returned object is unique, i.e., there is no other
	/// interned Id with an equal string.
	/// @return												Interned Id.
	//----------------------------------------------------------------------------------------
	const Id& Get() const
	{
		return _id ? *_id : Id::NullValue();
	}

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the interned Id. The pointer is unique, i.e., there is no other
	/// pointer to an interned Id with an equal string. The Id uses a special reference-counting,
	/// so you must only use the returned pointer as long as the owning InternedId is valid.
	/// @return												Unique pointer to the interned Id.
	//----------------------------------------------------------------------------------------
	const Id* GetPointer() const
	{
		return _id;
	}

	Bool operator ==(const InternedId& other) const
	{
		return _id == other._id;
	}

	Bool operator !=(const InternedId& other) const
	{
		return _id != other._id;
	}

	Bool operator <(const InternedId& other) const
	{
		if (other._id == nullptr)
			return false;
		if (_id == nullptr)
			return true;

		// Compare the Id, not the pointer. This is important for stable file output in text files.
		return *_id < *other._id;
	}

	MAXON_OPERATOR_INEQUALITY(InternedId);

	Bool operator ==(const Id& other) const
	{
		return _id && *_id == other;
	}

	Bool operator !=(const Id& other) const
	{
		return !this->operator ==(other);
	}

	//----------------------------------------------------------------------------------------
	/// Compares two InternedId objects using the lexicographic order.
	/// @param[in] other							Other InternedId object.
	/// @return												See COMPARERESULT.
	//----------------------------------------------------------------------------------------
	COMPARERESULT Compare(const InternedId& other) const
	{
		if (_id == other._id)
			return COMPARERESULT::EQUAL;
		if (!_id)
			return COMPARERESULT::LESS;
		if (!other._id)
			return COMPARERESULT::GREATER;
		Int res = strcmp(_id->GetCString(), other._id->GetCString());
		return (res < 0) ? COMPARERESULT::LESS : (res > 0) ? COMPARERESULT::GREATER : COMPARERESULT::EQUAL;
	}

	UInt GetHashCode() const
	{
		return _id ? _id->GetHashCode() : 0;
	}

	const Char* GetCString() const
	{
		return _id ? _id->GetCString() : nullptr;
	}

	Int GetCStringLength() const
	{
		return _id ? _id->GetCStringLength() : 0;
	}

	Block<const Char> ToBlock() const
	{
		return _id ? _id->ToBlock() : Block<const Char>();
	}

	static const InternedId& NullValue()
	{
		return NULL_VALUE;
	}

	String ToString(const FormatStatement* fmt) const;

	Bool IsPopulated() const
	{
		return _id != nullptr;
	}

	Bool IsEmpty() const
	{
		return _id == nullptr;
	}

	void Reset()
	{
		if (_id)
		{
			if (StrongReferenceCounter::Get(_id).Dec())
				Free(_id);
			_id = nullptr;
		}
	}

	static const InternedId NULL_VALUE;

private:
	static void Free(const Id* ptr);

	const Id* _id; ///< Pointer to the interned id.
};

template <> struct IsTriviallyEquatable<InternedId> : public std::true_type
{
};

template <> struct IsZeroInitialized<InternedId> : public std::true_type
{
};


//----------------------------------------------------------------------------------------
/// Member represents a member of struct-like types or function signatures. A member is just a pair of a type and a name.
//----------------------------------------------------------------------------------------
struct Member
{
	MAXON_IMPLICIT Member(const DataType& t = DataType::NullValue(), const InternedId& n = InternedId()) : type(t), name(n)
	{
	}

	template <typename T> static Member Create(const InternedId& n)
	{
		return {GetDataType<T, GET_DATATYPE_POLICY::NO_DECAY>(), n};
	}

	String ToString(const FormatStatement* fmt) const;

	MAXON_OPERATOR_EQUALITY_HASHCODE(Member, type, name);

	Bool operator <(const Member& other) const
	{
		return LexicographicalLessThan(name, other.name, type ? type->GetId() : NullValue<const Id&>(), other.type ? other.type->GetId() : NullValue<const Id&>());
	}

	MAXON_OPERATOR_INEQUALITY(Member);

	DataType type;		///< The type of the member.
	InternedId name;	///< The name of the member, this may be empty where anonymous members are allowed.
};


enum class INNERMOST_MEMBER : Int32
{
} MAXON_ENUM_ORDERED_LIST(INNERMOST_MEMBER);


//----------------------------------------------------------------------------------------
/// TypeArguments are usually set for a DataType if it is an instantiation of a ParametricType.
/// For example the type @c{Tuple<Int, Bool, String>} is an instantiation of the parametric type
/// Tuple with the type arguments @c{(Int, Bool, String)}, and the type Vector
/// is an instantiation of ParametricTypes::Vec with the type arguments @c{(Float, 3)}.
///
/// There are two kinds of type arguments:
/// - They can be types itself (like for Tuple), these are found in #args.
///   Optionally these arguments can even specify a name together with the type. This is used
///   e.g. for NamedTuple types like @c{NamedTuple<Int count, Bool valid>}.
/// - They can be of integral type (like the dimension for Vec), these are found in #iargs.
//----------------------------------------------------------------------------------------
struct TypeArguments
{
	BaseArray<INNERMOST_MEMBER> toInnermost;

	// This maps from an INNERMOST_MEMBER to a member index at the level of the array. For example, the innermost member with index 4 of an array of type [A, [B, C], [D, E], F]
	// has type E. It is contained in the member [D, E] at index 2 of the array, and within this member it has the innermost member index 1. So _fromInnermost[4] = (2, 1).
	// The innermost member with index 0 is A, _fromInnermost[0] is (0, -1) to indicate that A is non-nested at index 0 of the array.
	BaseArray<Tuple<Int32, INNERMOST_MEMBER>> fromInnermost;

	/// The integral type arguments.
	BaseArray<Int64> iargs;

	/// The number of type arguments which are types.
	Int count;

	/// The type arguments which are (optionally named) types.
	Member args[MAXON_FLEXIBLE_ARRAY_LENGTH];

	//----------------------------------------------------------------------------------------
	/// Returns the type arguments which are types as a block.
	//----------------------------------------------------------------------------------------
	Block<const Member> ToBlock() const
	{
		return {args, count};
	}

	//----------------------------------------------------------------------------------------
	/// Returns the type argument at the given #index.
	//----------------------------------------------------------------------------------------
	const Member& operator [](Int index) const
	{
		DebugAssert(UInt(index) <= UInt(count));
		return args[index];
	}

	using ValueType = Member;
	using ConstIterator = BaseIterator<const TypeArguments, false>;

	//----------------------------------------------------------------------------------------
	/// Gets an iterator pointing to the first type argument.
	/// @return												Iterator for the first type argument.
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		return ConstIterator(args);
	}

	//----------------------------------------------------------------------------------------
	/// Returns and iterator pointing to the end of the type arguments (one behind last).
	/// @return												Iterator for the end of the type arguments.
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		return ConstIterator(args + count);
	}

	//----------------------------------------------------------------------------------------
	/// Searches for a named type argument which uses the given #name and returns its index.
	/// If no such argument is found, -1 is returned. The function doesn't check for duplicates.
	/// @param[in] name								Name to search. If this is empty, -1 is returned.
	/// @return												Index of the matching type argument, or -1.
	//----------------------------------------------------------------------------------------
	Int FindIndex(const Id& name) const
	{
		if (name.IsPopulated())
		{
			for (Int i = 0; i < count; ++i)
			{
				if (args[i].name == name)
					return i;
			}
		}
		return -1;
	}

	//----------------------------------------------------------------------------------------
	/// @copydoc FindIndex
	//----------------------------------------------------------------------------------------
	Int FindIndex(const InternedId& name) const
	{
		if (name.IsPopulated())
		{
			for (Int i = 0; i < count; ++i)
			{
				if (args[i].name == name)
					return i;
			}
		}
		return -1;
	}

	Bool operator ==(const TypeArguments& other) const
	{
		return ToBlock() == other.ToBlock();
	}

	Bool operator !=(const TypeArguments& other) const
	{
		return !this->operator ==(other);
	}

	UInt GetHashCode() const
	{
		return ToBlock().GetHashCode();
	}

	using IsAllocType = std::true_type;

	void RemoveReference() const
	{
		if (StrongReferenceCounter::Get(this).Dec())
		{
			for (Int i = 0; i < count; ++i)
			{
				args[i].~Member();
			}
			TypeArguments* t = const_cast<TypeArguments*>(this);
			t->iargs.Reset();
			t->fromInnermost.Reset();
			t->toInnermost.Reset();
			DeleteMem(t);
		}
	}

	~TypeArguments() = delete;
};


struct MemberMap;

class EnumDataType;

//----------------------------------------------------------------------------------------
/// DataTypeLib declares some static functions needed for the DataType system.
//----------------------------------------------------------------------------------------
class DataTypeLib
{
	MAXON_INTERFACE_NONVIRTUAL(DataTypeLib, MAXON_REFERENCE_NONE, "net.maxon.interface.datatypelib");
public:
	//----------------------------------------------------------------------------------------
	/// Returns the DataType for DataType itself (to be precise, for const DataTypeImpl*).
	/// @return												DataType of DataType.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType& GetDataTypeType();

	//----------------------------------------------------------------------------------------
	/// Returns the DataType for void.
	/// @return												DataType of void.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType& GetVoidType();

	//----------------------------------------------------------------------------------------
	/// Returns the DataType for std::nullptr_t.
	/// @return												DataType of void.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType& GetNullptrType();

	//----------------------------------------------------------------------------------------
	/// Returns the DataType for the Generic type. All operations on a Generic value will fail.
	/// @return												DataType of Generic.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType& GetGenericType();

	//----------------------------------------------------------------------------------------
	/// Returns the DataType for the generic arithmetic type. All operations on a Generic value will fail.
	/// @return												Abstract base type of all arithmetic types.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType& GetGenericArithmeticType();

	//----------------------------------------------------------------------------------------
	/// Returns the DataType for ParametricType.
	/// @return												DataType of ParametricType.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType& GetParametricTypeType();

	//----------------------------------------------------------------------------------------
	/// Returns the DataType for ComponentDescriptor.
	/// @return												DataType of ComponentDescriptor.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType& GetComponentDescriptorType();

	//----------------------------------------------------------------------------------------
	/// Returns the DataType which represents an arbitrary number of members for container types.
	/// @return												DataType for the ellipsis of container types.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType& GetEllipsisType();

	//----------------------------------------------------------------------------------------
	/// Applies the substitutions given be replace to orig and its nested types. For example,
	/// if replace maps Float to Float64, then Float gets transformed into
	/// Float64, but also Tuple<Bool, Float, Vector, BaseArray<Float>> gets transformed into
	/// Tuple<Bool, Float64, Vector64, BaseArray<Float64>>.
	/// @param[in] orig								Original DataType.
	/// @param[in] replace						This delegate is called for each DataType found in orig.
	///																It has to return the replacement for the passed DataType,
	///																or the passed DataType itself if no immediate replacement shall be done.
	///																In both cases, if the returned type is an instance of a parametric type,
	///																the substitution recurses into the type parameters and
	///																re-instantiates the parametric type for the substituted type arguments.
	/// @return												DataType where the substitutions given by #replace have been applied.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataType> Substitute(const DataType& orig, const Delegate<Result<DataType>(const DataType&)>& replace);

	//----------------------------------------------------------------------------------------
	/// Replaces types which depend on the architecture or the version by the concrete types for the
	/// current runtime:
	/// - The architecture-dependent types Int, UInt and Float are replaced by the corresponding runtime data types
	///   (Int32 or Int64, likewise for UInt and Float).
	/// - Unversioned interface types are replaced by the corresponding main version types.
	///
	/// The replacement is also done within instances of parametric types so that
	/// e.g. Vector gets replaced by Vector64. Internally GetRuntimeDataType() just uses Substitute().
	/// @param[in] orig								Original DataType.
	/// @return												DataType where all occurrences of Int, UInt and Float have been replaced
	///																by the corresponding runtime type.
	/// @see Substitute
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataType> GetRuntimeDataType(const DataType& orig);

	//----------------------------------------------------------------------------------------
	/// Returns the byte offsets of the tuple members.
	/// @param[in] type								Tuple data type.
	/// @return												Byte offsets of the member values.
	/// @note The memory layout of a TupleDataType is compatible with the C++ layout of standard-layout classes.
	/// Members with higher index have a higher offset.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const Block<const Int>& GetTupleMemberOffsets(const TupleDataType& type);

	static MAXON_METHOD Result<DelegateDataType> GetDelegateType(const DataType& returnType, const Block<const DataType>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub);

	static MAXON_METHOD Result<DelegateDataType> GetDelegateType(const Result<DataType>& returnType, const Block<const Result<DataType>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub);

	static MAXON_METHOD Result<void> InvokeDelegate(const DelegateDataType& delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments);

	static MAXON_METHOD Result<DelegateBase> CreateDelegate(const DelegateDataType& delegateType, reflection::DelegateHandler&& handler);

	static MAXON_METHOD const DataType& GetDelegateReturnType(const DelegateDataType& delegateType);

	static MAXON_METHOD const Block<const DataType>& GetDelegateParameterTypes(const DelegateDataType& delegateType);

	static MAXON_METHOD Result<EnumDataType> GetEnumType(const DataType& underlyingType, const Block<const Tuple<Id, Data>>& enumerators);

	static MAXON_METHOD const Block<const Tuple<Id, Data>>& GetEnumerators(const DataType& enumType);

	static MAXON_METHOD Result<void> RegisterEnumType(DataTypeImpl& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames);

	//----------------------------------------------------------------------------------------
	/// Returns the DataType of an object which implements at least the given
	/// @p interfaces. On the first invocation for a specific set of interfaces, the data type will be constructed, later invocations
	/// will return the same data type object. The order of @p interfaces doesn't matter.
	///
	/// The identifier of the returned type is a comma-separated list of the identifiers of the interfaces, alphabetically sorted by their id
	/// and enclosed in {}-parentheses.
	///
	/// @param[in] interfaces					Array of virtual interfaces.
	/// @return												DataType for the given set of interfaces.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataType> GetDataTypeOfInterfaces(const Block<const InterfaceReference* const>& interfaces);

	static MAXON_METHOD Result<DataType> GetReferenceType(const DataType& type, EntityBase::FLAGS refFlags);

	static MAXON_METHOD Result<Tuple<DataType, const Char*>> ParseDataType(const Char* name);

	//----------------------------------------------------------------------------------------
	/// Returns the DataType identified by @p typeId. This supports primary data types as well as
	/// compound data types which are built by primary data types and array- and struct-compositions.
	/// E.g., the id "(int64,net.maxon.parametrictype.vec<3,float64>,{net.maxon.interface.function})[]" identifies an array of structs
	/// with Int64, Vector64 and object members where the object has to implement FunctionSignatureInterface
	/// and GenericFunctionInterface.
	/// @param[in] typeId							Type identifier.
	/// @return												DataType for the given id.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataType> GetDataType(const Id& typeId);

	//----------------------------------------------------------------------------------------
	/// The limit for GetNumberedId.
	//----------------------------------------------------------------------------------------
	static const Int NUMBERED_ID_COUNT = 10000;

	//----------------------------------------------------------------------------------------
	/// Returns an Id of the form _123, i.e., consisting of the character _ followed by the given #number in decimals.
	/// @param[in] number							The number for the Id, has to be non-negative and below NUMBERED_ID_COUNT.
	/// @return												Id of the form _123.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const Id& GetNumberedId(Int number);

	static MAXON_METHOD Result<const MemberMap*> GetMemberMap(Block<const Int> block);

	//----------------------------------------------------------------------------------------
	/// Returns a MemberMap of the given length which maps each index onto itself.
	/// @param[in] length							The length of the MemberMap.
	/// @return												A MemberMap with the values 0, 1, ..., length-1.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<const MemberMap*> GetIdentityMemberMap(Int length);

	static MAXON_METHOD Result<const MemberMap*> ConcatMemberMap(const MemberMap* first, const MemberMap* second);

	static MAXON_METHOD Result<const MemberMap*> PrivateGetMemberMap(const DataTypeImpl* containerType, const DataTypeImpl* runtimeType);

	static MAXON_METHOD ConstDataPtr GetConstant(const DataType& type, Int value);

	static MAXON_METHOD Result<DataType> GetDataTypeForData(const DataType& valueType);

	static MAXON_METHOD Result<void> ConvertToData(Data& result, const DataType& dataType, const DataType& valueType, const Generic& value);

	static MAXON_METHOD Result<void> MoveFromData(const DataType& valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage);

	static MAXON_METHOD Bool PrivateIsBaseOfOrSame(const DataTypeImpl* type, const DataTypeImpl* other, DataType::MEMBER_MATCH_MODE mode);

	static MAXON_METHOD Result<StrongRef<TypeArguments>> CreateTypeArguments(Int cnt);

	static MAXON_METHOD Result<StrongRef<TypeArguments>> CreateTypeArguments(const Block<const Member>& args);

	static MAXON_METHOD ResultMem FinalizeTypeArguments(TypeArguments& args);

	static MAXON_METHOD void PrivateHandleUnreferencedType(DataTypeImpl* type);

	static MAXON_METHOD const DataType& PrivateGetPrimaryDataTypeType();

	static MAXON_METHOD void AddLeakingInstantiatedType(DataTypeImpl* type);

	static MAXON_METHOD const Block<const Member>& PrivateGetNamedTupleMembers(Binary& binary, NamedTupleMembers* mem, std::add_pointer<Int(void*)>::type constructor);
};

//----------------------------------------------------------------------------------------
/// TupleDataType represents a custom tuple type created at runtime with ParametricTypes::Tuple.
/// If a DataType is of the kind VALUEKIND::TUPLE or VALUEKIND::NAMED_TUPLE, you can safely cast it to TupleDataType.
/// The memory layout of a TupleDataType is compatible with the corresponding C++ layout of standard-layout classes.
//----------------------------------------------------------------------------------------
class TupleDataType : public DataType
{
public:
	using DataType::DataType;

	//----------------------------------------------------------------------------------------
	/// Returns the byte offset of the tuple member at the given index. I.e., if @c s
	/// is a <tt>TupleValue*</tt>, the member at @p index will be found at the returned offset
	/// from @c s. Members with higher index have a higher offset.
	/// The memory layout of a TupleDataType is compatible with the C++ layout of standard-layout classes.
	/// @param[in] index							Index of the member.
	/// @return												Byte offset of the member value.
	//----------------------------------------------------------------------------------------
	Int GetMemberOffset(Int index) const
	{
		return DataTypeLib::GetTupleMemberOffsets(*this)[index];
	}
};


//----------------------------------------------------------------------------------------
/// DelegateDataType represents the data type of a Delegate. You can get the Delegate's
/// return type and its parameter types from a DelegateDataType.
//----------------------------------------------------------------------------------------
class DelegateDataType : public DataType
{
public:
	using DataType::DataType;

	//----------------------------------------------------------------------------------------
	/// Returns the return type of the delegate, i.e., for Delegate<RESULT(ARGS...)> this is
	/// the data type of RESULT.
	/// @return												Return type of delegate.
	//----------------------------------------------------------------------------------------
	const DataType& GetReturnType() const
	{
		return DataTypeLib::GetDelegateReturnType(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the parameter types of the delegate, i.e., for Delegate<RESULT(ARGS...)> this is
	/// a block consisting of the data types of ARGS... .
	/// @return												Parameter types of delegate.
	//----------------------------------------------------------------------------------------
	const Block<const DataType>& GetParameterTypes() const
	{
		return DataTypeLib::GetDelegateParameterTypes(*this);
	}

	Result<void> Invoke(const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments) const
	{
		return DataTypeLib::InvokeDelegate(*this, delegate, result, arguments);
	}

	Result<DelegateBase> Create(reflection::DelegateHandler&& handler) const
	{
		return DataTypeLib::CreateDelegate(*this, std::move(handler));
	}
};


class EnumDataType : public DataType
{
public:
	using DataType::DataType;

	const Block<const Tuple<Id, Data>>& GetEnumerators() const
	{
		return DataTypeLib::GetEnumerators(*this);
	}
};


class ContainerDataType : public DataType
{
public:
	using DataType::DataType;

	Result<const MemberMap*> GetMemberMap(const ContainerDataType& runtimeType) const
	{
		return DataTypeLib::PrivateGetMemberMap(PrivateGetPointer(), runtimeType.PrivateGetPointer());
	}
};


#include "datatypelib1.hxx"
#include "datatypelib2.hxx"

/// @}

} // namespace maxon

#endif // DATATYPELIB_H__
