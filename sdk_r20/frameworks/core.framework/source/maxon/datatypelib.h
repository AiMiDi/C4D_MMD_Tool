#ifndef DATATYPELIB_H__
#define DATATYPELIB_H__

#include "maxon/reflection_invocation.h"

namespace maxon
{

/// @addtogroup DATATYPE
/// @{

struct Member;
class EnumDataType;

//----------------------------------------------------------------------------------------
/// DataTypeLib declares some static functions needed for the DataType system.
//----------------------------------------------------------------------------------------
class DataTypeLib
{
	MAXON_INTERFACE_NONVIRTUAL(DataTypeLib, MAXON_REFERENCE_NONE, "net.maxon.interface.datatypelib");
public:
	//----------------------------------------------------------------------------------------
	/// Returns the DataType for DataType itself (to be precise, for const DataType*).
	/// @return												DataType of DataType.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType* GetDataTypeType();

	//----------------------------------------------------------------------------------------
	/// Returns the DataType for void.
	/// @return												DataType of void.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType* GetVoidType();

	//----------------------------------------------------------------------------------------
	/// Returns the DataType for std::nullptr_t.
	/// @return												DataType of void.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType* GetNullptrType();

	//----------------------------------------------------------------------------------------
	/// Returns the DataType for the Generic type. All operations on a Generic value will fail.
	/// @return												DataType of Generic.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType* GetGenericType();

	//----------------------------------------------------------------------------------------
	/// Returns the DataType for the generic arithmetic type. All operations on a Generic value will fail.
	/// @return												Abstract base type of all arithmetic types.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType* GetGenericArithmeticType();

	//----------------------------------------------------------------------------------------
	/// Returns the DataType for ParametricType.
	/// @return												DataType of ParametricType.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType* GetParametricTypeType();

	//----------------------------------------------------------------------------------------
	/// Returns the DataType for ComponentDescriptor.
	/// @return												DataType of ComponentDescriptor.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const DataType* GetComponentDescriptorType();

	//----------------------------------------------------------------------------------------
	/// Applies the substitutions given be replace to orig and its nested types. For example,
	/// if replace maps Float to Float64, then Float gets transformed into
	/// Float64, but also Tuple<Bool, Float, Vector, BaseArray<Float>> gets transformed into
	/// Tuple<Bool, Float64, Vector64, BaseArray<Float64>>.
	/// @param[in] orig								Original DataType.
	/// @param[in] replace						This delegate is called for each DataType found in orig.
	///																It has to return the replacement for the registered DataType,
	///																or nullptr if no immediate replacement shall be done. In the
	///																latter case, if the type is an instance of a parametric type,
	///																the substitution recurses into the type parameters.
	/// @return												DataType where the substitutions given by #replace have been applied.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<const DataType*> Substitute(const DataType* orig, const Delegate<Result<const DataType*>(const DataType*)>& replace);

	//----------------------------------------------------------------------------------------
	/// Replaces types which depend on the architecture or the version by the concrete types for the
	/// current runtime:
	/// - The architecture-dependent types Int, UInt and Float are replaced by the corresponding runtime data types
	///   (Int32 or Int64, likewise for UInt and Float).
	/// - Unversioned interface types are replaced by the corresponding main version types.
	/// The replacement is also done within instances of parametric types so that
	/// e.g. Vector gets replaced by Vector64. Internally GetRuntimeDataType() just uses Substitute().
	/// @param[in] orig								Original DataType.
	/// @return												DataType where all occurrences of Int, UInt and Float have been replaced
	///																by the corresponding runtime type.
	/// @see Substitute
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<const DataType*> GetRuntimeDataType(const DataType* orig);

	//----------------------------------------------------------------------------------------
	/// Returns a TupleDataType with members of the given @p types. On the first invocation
	/// for a specific @p types array, the data type will be constructed, later invocations
	/// will return the same data type object. The identifier of a tuple data type
	/// is a parenthesized list of the identifiers of the member types.
	/// @param[in] types							Array of member types for the tuple data type.
	/// @return												TupleDataType consisting of the given member types.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<const TupleDataType*> GetTupleType(const Block<const DataType* const>& types);

	static MAXON_METHOD Result<const TupleDataType*> GetTupleType(const Block<const Result<const DataType*>>& types);

	static MAXON_METHOD Result<const TupleDataType*> GetTupleType(const Block<const Member>& members);

	static MAXON_METHOD Result<const TupleDataType*> GetTupleTypeWithIndividualMembers(const TupleDataType* type);

	//----------------------------------------------------------------------------------------
	/// Returns the byte offsets of the tuple members.
	/// @param[in] type								Tuple data type.
	/// @return												Byte offsets of the member values.
	/// @note The memory layout of a TupleDataType is compatible with the C++ layout of standard-layout classes.
	/// Members with higher index have a higher offset.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const Block<const Int>& GetTupleMemberOffsets(const TupleDataType* type);

	static MAXON_METHOD Result<const FunctionDataType*> GetFunctionType(const DataType* outputTypes, const DataType* inputTypes);

	static MAXON_METHOD Result<const DelegateDataType*> GetDelegateType(const DataType* returnType, const Block<const DataType* const>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub);

	static MAXON_METHOD Result<const DelegateDataType*> GetDelegateType(const Result<const DataType*>& returnType, const Block<const Result<const DataType*>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub);

	static MAXON_METHOD Result<void> InvokeDelegate(const DelegateDataType* delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments);

	static MAXON_METHOD Result<DelegateBase> CreateDelegate(const DelegateDataType* delegateType, reflection::DelegateHandler&& handler);

	static MAXON_METHOD const DataType* GetDelegateReturnType(const DelegateDataType* delegateType);

	static MAXON_METHOD const Block<const DataType* const>& GetDelegateParameterTypes(const DelegateDataType* delegateType);

	static MAXON_METHOD Result<const DataType*> GetSimdElementType(const DataType* componentType, Int dimension, Int multiplicity);

	static MAXON_METHOD Result<const EnumDataType*> GetEnumType(const DataType* underlyingType, const Block<const Tuple<Id, Data>>& enumerators);

	static MAXON_METHOD const Block<const Tuple<Id, Data>>& GetEnumerators(const DataType* enumType);

	static MAXON_METHOD Result<const DataType*> RegisterEnumType(DataType& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames);

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
	static MAXON_METHOD Result<const DataType*> GetDataTypeOfInterfaces(const Block<const InterfaceReference* const>& interfaces);

	static MAXON_METHOD Result<Tuple<const DataType*, const Char*>> ParseDataType(const Char* name);

	//----------------------------------------------------------------------------------------
	/// Returns the DataType identified by @p typeId. This supports primary data types as well as
	/// compound data types which are built by primary data types and array- and struct-compositions.
	/// E.g., the id "(int64,net.maxon.parametrictype.vec<3,float64>,{net.maxon.interface.function})[]" identifies an array of structs
	/// with Int64, Vector64 and object members where the object has to implement FunctionSignatureInterface
	/// and GenericFunctionInterface.
	/// @param[in] typeId							Type identifier.
	/// @return												DataType for the given id.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<const DataType*> GetDataType(const Id& typeId);

	//----------------------------------------------------------------------------------------
	/// The limit for GetNumberedId.
	//----------------------------------------------------------------------------------------
	static const Int NUMBERED_ID_COUNT = 10000;

	//----------------------------------------------------------------------------------------
	/// Returns an Id of the form _123, i.e., consisting of the characer _ followed by the given #number in decimals.
	/// @param[in] number							The number for the Id, has to be non-negative and below NUMBERED_ID_COUNT.
	/// @return												Id of the form _123.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const Id& GetNumberedId(Int number);

	static MAXON_METHOD ConstDataPtr GetConstant(const DataType* type, Int value);

	static MAXON_METHOD Result<const DataType*> GetDataTypeForData(const DataType* valueType);

	static MAXON_METHOD Result<void> ConvertToData(Data& result, const DataType* dataType, const DataType* valueType, const Generic& value);

	static MAXON_METHOD Result<void> MoveFromData(const DataType* valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage);

	static MAXON_METHOD Bool IsBaseOfOrSame(const DataType* type, const DataType* other, DataType::MEMBER_MATCH_MODE mode);

	static MAXON_METHOD ResultPtr<TypeArguments> CreateTypeArguments(Int cnt);

	static MAXON_METHOD ResultMem FinalizeTypeArguments(TypeArguments& args);

	static MAXON_METHOD ResultPtr<TypeArguments> CreateTypeArguments(const Block<const Member>& args);
};

//----------------------------------------------------------------------------------------
/// TupleDataType represents a custom tuple type created at runtime with DataTypeLib::GetTupleType().
/// If a DataType is of the kind VALUEKIND::TUPLE or VALUEKIND::NAMED_TUPLE, you can safely cast it to TupleDataType.
/// The memory layout of a TupleDataType is compatible with the corresponding C++ layout of standard-layout classes.
//----------------------------------------------------------------------------------------
class TupleDataType : public DataType
{
public:
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
		return DataTypeLib::GetTupleMemberOffsets(this)[index];
	}

	Result<const TupleDataType*> GetWithIndividualMembers() const
	{
		return DataTypeLib::GetTupleTypeWithIndividualMembers(this);
	}
};


//----------------------------------------------------------------------------------------
/// DelegateDataType represents the data type of a Delegate. You can get the Delegate's
/// return type and its parameter types from a DelegateDataType.
//----------------------------------------------------------------------------------------
class DelegateDataType : public DataType
{
public:
	//----------------------------------------------------------------------------------------
	/// Returns the return type of the delegate, i.e., for Delegate<RESULT(ARGS...)> this is
	/// the data type of RESULT.
	/// @return												Return type of delegate.
	//----------------------------------------------------------------------------------------
	const DataType* GetReturnType() const
	{
		return DataTypeLib::GetDelegateReturnType(this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the parameter types of the delegate, i.e., for Delegate<RESULT(ARGS...)> this is
	/// a block consisting of the data types of ARGS... .
	/// @return												Parameter types of delegate.
	//----------------------------------------------------------------------------------------
	const Block<const DataType* const>& GetParameterTypes() const
	{
		return DataTypeLib::GetDelegateParameterTypes(this);
	}

	Result<void> Invoke(const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments) const
	{
		return DataTypeLib::InvokeDelegate(this, delegate, result, arguments);
	}

	Result<DelegateBase> Create(reflection::DelegateHandler&& handler) const
	{
		return DataTypeLib::CreateDelegate(this, std::move(handler));
	}
};


class EnumDataType : public DataType
{
public:
	const Block<const Tuple<Id, Data>>& GetEnumerators() const
	{
		return DataTypeLib::GetEnumerators(this);
	}
};

#include "datatypelib1.hxx"
#include "datatypelib2.hxx"

/// @}

} // namespace maxon

#endif // DATATYPELIB_H__
