
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct DataTypeLib::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	const DataType* (*_DataTypeLib_GetDataTypeType) ();
	const DataType* (*_DataTypeLib_GetVoidType) ();
	const DataType* (*_DataTypeLib_GetNullptrType) ();
	const DataType* (*_DataTypeLib_GetGenericType) ();
	const DataType* (*_DataTypeLib_GetGenericArithmeticType) ();
	const DataType* (*_DataTypeLib_GetParametricTypeType) ();
	const DataType* (*_DataTypeLib_GetComponentDescriptorType) ();
	Result<const DataType*> (*_DataTypeLib_Substitute) (const DataType* orig, const Delegate<Result<const DataType*>(const DataType*)>& replace);
	Result<const DataType*> (*_DataTypeLib_GetRuntimeDataType) (const DataType* orig);
	Result<const TupleDataType*> (*_DataTypeLib_GetTupleType) (const Block<const DataType* const>& types);
	Result<const TupleDataType*> (*_DataTypeLib_GetTupleType_1) (const Block<const Result<const DataType*>>& types);
	Result<const TupleDataType*> (*_DataTypeLib_GetTupleType_2) (const Block<const Member>& members);
	Result<const TupleDataType*> (*_DataTypeLib_GetTupleTypeWithIndividualMembers) (const TupleDataType* type);
	const Block<const Int>& (*_DataTypeLib_GetTupleMemberOffsets) (const TupleDataType* type);
	Result<const FunctionDataType*> (*_DataTypeLib_GetFunctionType) (const DataType* outputTypes, const DataType* inputTypes);
	Result<const DelegateDataType*> (*_DataTypeLib_GetDelegateType) (const DataType* returnType, const Block<const DataType* const>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub);
	Result<const DelegateDataType*> (*_DataTypeLib_GetDelegateType_1) (const Result<const DataType*>& returnType, const Block<const Result<const DataType*>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub);
	Result<void> (*_DataTypeLib_InvokeDelegate) (const DelegateDataType* delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments);
	Result<DelegateBase> (*_DataTypeLib_CreateDelegate) (const DelegateDataType* delegateType, reflection::DelegateHandler&& handler);
	const DataType* (*_DataTypeLib_GetDelegateReturnType) (const DelegateDataType* delegateType);
	const Block<const DataType* const>& (*_DataTypeLib_GetDelegateParameterTypes) (const DelegateDataType* delegateType);
	Result<const DataType*> (*_DataTypeLib_GetSimdElementType) (const DataType* componentType, Int dimension, Int multiplicity);
	Result<const EnumDataType*> (*_DataTypeLib_GetEnumType) (const DataType* underlyingType, const Block<const Tuple<Id, Data>>& enumerators);
	const Block<const Tuple<Id, Data>>& (*_DataTypeLib_GetEnumerators) (const DataType* enumType);
	Result<const DataType*> (*_DataTypeLib_RegisterEnumType) (DataType& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames);
	Result<const DataType*> (*_DataTypeLib_GetDataTypeOfInterfaces) (const Block<const InterfaceReference* const>& interfaces);
	Result<Tuple<const DataType*, const Char*>> (*_DataTypeLib_ParseDataType) (const Char* name);
	Result<const DataType*> (*_DataTypeLib_GetDataType) (const Id& typeId);
	const Id& (*_DataTypeLib_GetNumberedId) (Int number);
	ConstDataPtr (*_DataTypeLib_GetConstant) (const DataType* type, Int value);
	Result<const DataType*> (*_DataTypeLib_GetDataTypeForData) (const DataType* valueType);
	Result<void> (*_DataTypeLib_ConvertToData) (Data& result, const DataType* dataType, const DataType* valueType, const Generic& value);
	Result<void> (*_DataTypeLib_MoveFromData) (const DataType* valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage);
	Bool (*_DataTypeLib_IsBaseOfOrSame) (const DataType* type, const DataType* other, DataType::MEMBER_MATCH_MODE mode);
	ResultPtr<TypeArguments> (*_DataTypeLib_CreateTypeArguments) (Int cnt);
	ResultMem (*_DataTypeLib_FinalizeTypeArguments) (TypeArguments& args);
	ResultPtr<TypeArguments> (*_DataTypeLib_CreateTypeArguments_1) (const Block<const Member>& args);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_DataTypeLib_GetDataTypeType = &IMPL::_DataTypeLib_GetDataTypeType;
		tbl->_DataTypeLib_GetVoidType = &IMPL::_DataTypeLib_GetVoidType;
		tbl->_DataTypeLib_GetNullptrType = &IMPL::_DataTypeLib_GetNullptrType;
		tbl->_DataTypeLib_GetGenericType = &IMPL::_DataTypeLib_GetGenericType;
		tbl->_DataTypeLib_GetGenericArithmeticType = &IMPL::_DataTypeLib_GetGenericArithmeticType;
		tbl->_DataTypeLib_GetParametricTypeType = &IMPL::_DataTypeLib_GetParametricTypeType;
		tbl->_DataTypeLib_GetComponentDescriptorType = &IMPL::_DataTypeLib_GetComponentDescriptorType;
		tbl->_DataTypeLib_Substitute = &IMPL::_DataTypeLib_Substitute;
		tbl->_DataTypeLib_GetRuntimeDataType = &IMPL::_DataTypeLib_GetRuntimeDataType;
		tbl->_DataTypeLib_GetTupleType = &IMPL::_DataTypeLib_GetTupleType;
		tbl->_DataTypeLib_GetTupleType_1 = &IMPL::_DataTypeLib_GetTupleType_1;
		tbl->_DataTypeLib_GetTupleType_2 = &IMPL::_DataTypeLib_GetTupleType_2;
		tbl->_DataTypeLib_GetTupleTypeWithIndividualMembers = &IMPL::_DataTypeLib_GetTupleTypeWithIndividualMembers;
		tbl->_DataTypeLib_GetTupleMemberOffsets = &IMPL::_DataTypeLib_GetTupleMemberOffsets;
		tbl->_DataTypeLib_GetFunctionType = &IMPL::_DataTypeLib_GetFunctionType;
		tbl->_DataTypeLib_GetDelegateType = &IMPL::_DataTypeLib_GetDelegateType;
		tbl->_DataTypeLib_GetDelegateType_1 = &IMPL::_DataTypeLib_GetDelegateType_1;
		tbl->_DataTypeLib_InvokeDelegate = &IMPL::_DataTypeLib_InvokeDelegate;
		tbl->_DataTypeLib_CreateDelegate = &IMPL::_DataTypeLib_CreateDelegate;
		tbl->_DataTypeLib_GetDelegateReturnType = &IMPL::_DataTypeLib_GetDelegateReturnType;
		tbl->_DataTypeLib_GetDelegateParameterTypes = &IMPL::_DataTypeLib_GetDelegateParameterTypes;
		tbl->_DataTypeLib_GetSimdElementType = &IMPL::_DataTypeLib_GetSimdElementType;
		tbl->_DataTypeLib_GetEnumType = &IMPL::_DataTypeLib_GetEnumType;
		tbl->_DataTypeLib_GetEnumerators = &IMPL::_DataTypeLib_GetEnumerators;
		tbl->_DataTypeLib_RegisterEnumType = &IMPL::_DataTypeLib_RegisterEnumType;
		tbl->_DataTypeLib_GetDataTypeOfInterfaces = &IMPL::_DataTypeLib_GetDataTypeOfInterfaces;
		tbl->_DataTypeLib_ParseDataType = &IMPL::_DataTypeLib_ParseDataType;
		tbl->_DataTypeLib_GetDataType = &IMPL::_DataTypeLib_GetDataType;
		tbl->_DataTypeLib_GetNumberedId = &IMPL::_DataTypeLib_GetNumberedId;
		tbl->_DataTypeLib_GetConstant = &IMPL::_DataTypeLib_GetConstant;
		tbl->_DataTypeLib_GetDataTypeForData = &IMPL::_DataTypeLib_GetDataTypeForData;
		tbl->_DataTypeLib_ConvertToData = &IMPL::_DataTypeLib_ConvertToData;
		tbl->_DataTypeLib_MoveFromData = &IMPL::_DataTypeLib_MoveFromData;
		tbl->_DataTypeLib_IsBaseOfOrSame = &IMPL::_DataTypeLib_IsBaseOfOrSame;
		tbl->_DataTypeLib_CreateTypeArguments = &IMPL::_DataTypeLib_CreateTypeArguments;
		tbl->_DataTypeLib_FinalizeTypeArguments = &IMPL::_DataTypeLib_FinalizeTypeArguments;
		tbl->_DataTypeLib_CreateTypeArguments_1 = &IMPL::_DataTypeLib_CreateTypeArguments_1;
	}
};

template <typename C> class DataTypeLib::Wrapper
{
public:
	static const DataType* _DataTypeLib_GetDataTypeType() { return C::GetDataTypeType(); }
	static const DataType* _DataTypeLib_GetVoidType() { return C::GetVoidType(); }
	static const DataType* _DataTypeLib_GetNullptrType() { return C::GetNullptrType(); }
	static const DataType* _DataTypeLib_GetGenericType() { return C::GetGenericType(); }
	static const DataType* _DataTypeLib_GetGenericArithmeticType() { return C::GetGenericArithmeticType(); }
	static const DataType* _DataTypeLib_GetParametricTypeType() { return C::GetParametricTypeType(); }
	static const DataType* _DataTypeLib_GetComponentDescriptorType() { return C::GetComponentDescriptorType(); }
	static Result<const DataType*> _DataTypeLib_Substitute(const DataType* orig, const Delegate<Result<const DataType*>(const DataType*)>& replace) { return C::Substitute(orig, replace); }
	static Result<const DataType*> _DataTypeLib_GetRuntimeDataType(const DataType* orig) { return C::GetRuntimeDataType(orig); }
	static Result<const TupleDataType*> _DataTypeLib_GetTupleType(const Block<const DataType* const>& types) { return C::GetTupleType(types); }
	static Result<const TupleDataType*> _DataTypeLib_GetTupleType_1(const Block<const Result<const DataType*>>& types) { return C::GetTupleType(types); }
	static Result<const TupleDataType*> _DataTypeLib_GetTupleType_2(const Block<const Member>& members) { return C::GetTupleType(members); }
	static Result<const TupleDataType*> _DataTypeLib_GetTupleTypeWithIndividualMembers(const TupleDataType* type) { return C::GetTupleTypeWithIndividualMembers(type); }
	static const Block<const Int>& _DataTypeLib_GetTupleMemberOffsets(const TupleDataType* type) { return C::GetTupleMemberOffsets(type); }
	static Result<const FunctionDataType*> _DataTypeLib_GetFunctionType(const DataType* outputTypes, const DataType* inputTypes) { return C::GetFunctionType(outputTypes, inputTypes); }
	static Result<const DelegateDataType*> _DataTypeLib_GetDelegateType(const DataType* returnType, const Block<const DataType* const>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) { return C::GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub); }
	static Result<const DelegateDataType*> _DataTypeLib_GetDelegateType_1(const Result<const DataType*>& returnType, const Block<const Result<const DataType*>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) { return C::GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub); }
	static Result<void> _DataTypeLib_InvokeDelegate(const DelegateDataType* delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments) { return C::InvokeDelegate(delegateType, delegate, result, arguments); }
	static Result<DelegateBase> _DataTypeLib_CreateDelegate(const DelegateDataType* delegateType, reflection::DelegateHandler&& handler) { return C::CreateDelegate(delegateType, std::forward<reflection::DelegateHandler>(handler)); }
	static const DataType* _DataTypeLib_GetDelegateReturnType(const DelegateDataType* delegateType) { return C::GetDelegateReturnType(delegateType); }
	static const Block<const DataType* const>& _DataTypeLib_GetDelegateParameterTypes(const DelegateDataType* delegateType) { return C::GetDelegateParameterTypes(delegateType); }
	static Result<const DataType*> _DataTypeLib_GetSimdElementType(const DataType* componentType, Int dimension, Int multiplicity) { return C::GetSimdElementType(componentType, dimension, multiplicity); }
	static Result<const EnumDataType*> _DataTypeLib_GetEnumType(const DataType* underlyingType, const Block<const Tuple<Id, Data>>& enumerators) { return C::GetEnumType(underlyingType, enumerators); }
	static const Block<const Tuple<Id, Data>>& _DataTypeLib_GetEnumerators(const DataType* enumType) { return C::GetEnumerators(enumType); }
	static Result<const DataType*> _DataTypeLib_RegisterEnumType(DataType& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames) { return C::RegisterEnumType(type, typeId, size, isSigned, flags, enumValues, enumValueNames); }
	static Result<const DataType*> _DataTypeLib_GetDataTypeOfInterfaces(const Block<const InterfaceReference* const>& interfaces) { return C::GetDataTypeOfInterfaces(interfaces); }
	static Result<Tuple<const DataType*, const Char*>> _DataTypeLib_ParseDataType(const Char* name) { return C::ParseDataType(name); }
	static Result<const DataType*> _DataTypeLib_GetDataType(const Id& typeId) { return C::GetDataType(typeId); }
	static const Id& _DataTypeLib_GetNumberedId(Int number) { return C::GetNumberedId(number); }
	static ConstDataPtr _DataTypeLib_GetConstant(const DataType* type, Int value) { return C::GetConstant(type, value); }
	static Result<const DataType*> _DataTypeLib_GetDataTypeForData(const DataType* valueType) { return C::GetDataTypeForData(valueType); }
	static Result<void> _DataTypeLib_ConvertToData(Data& result, const DataType* dataType, const DataType* valueType, const Generic& value) { return C::ConvertToData(result, dataType, valueType, value); }
	static Result<void> _DataTypeLib_MoveFromData(const DataType* valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage) { return C::MoveFromData(valueType, value, createDefaultPointees, data, storage); }
	static Bool _DataTypeLib_IsBaseOfOrSame(const DataType* type, const DataType* other, DataType::MEMBER_MATCH_MODE mode) { return C::IsBaseOfOrSame(type, other, mode); }
	static ResultPtr<TypeArguments> _DataTypeLib_CreateTypeArguments(Int cnt) { return C::CreateTypeArguments(cnt); }
	static ResultMem _DataTypeLib_FinalizeTypeArguments(TypeArguments& args) { return C::FinalizeTypeArguments(args); }
	static ResultPtr<TypeArguments> _DataTypeLib_CreateTypeArguments_1(const Block<const Member>& args) { return C::CreateTypeArguments(args); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDataTypeType() -> const DataType*
{
	return MTable::_instance._DataTypeLib_GetDataTypeType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetVoidType() -> const DataType*
{
	return MTable::_instance._DataTypeLib_GetVoidType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetNullptrType() -> const DataType*
{
	return MTable::_instance._DataTypeLib_GetNullptrType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetGenericType() -> const DataType*
{
	return MTable::_instance._DataTypeLib_GetGenericType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetGenericArithmeticType() -> const DataType*
{
	return MTable::_instance._DataTypeLib_GetGenericArithmeticType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetParametricTypeType() -> const DataType*
{
	return MTable::_instance._DataTypeLib_GetParametricTypeType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetComponentDescriptorType() -> const DataType*
{
	return MTable::_instance._DataTypeLib_GetComponentDescriptorType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::Substitute(const DataType* orig, const Delegate<Result<const DataType*>(const DataType*)>& replace) -> Result<const DataType*>
{
	return MTable::_instance._DataTypeLib_Substitute(orig, replace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetRuntimeDataType(const DataType* orig) -> Result<const DataType*>
{
	return MTable::_instance._DataTypeLib_GetRuntimeDataType(orig);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetTupleType(const Block<const DataType* const>& types) -> Result<const TupleDataType*>
{
	return MTable::_instance._DataTypeLib_GetTupleType(types);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetTupleType(const Block<const Result<const DataType*>>& types) -> Result<const TupleDataType*>
{
	return MTable::_instance._DataTypeLib_GetTupleType_1(types);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetTupleType(const Block<const Member>& members) -> Result<const TupleDataType*>
{
	return MTable::_instance._DataTypeLib_GetTupleType_2(members);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetTupleTypeWithIndividualMembers(const TupleDataType* type) -> Result<const TupleDataType*>
{
	return MTable::_instance._DataTypeLib_GetTupleTypeWithIndividualMembers(type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetTupleMemberOffsets(const TupleDataType* type) -> const Block<const Int>&
{
	return MTable::_instance._DataTypeLib_GetTupleMemberOffsets(type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetFunctionType(const DataType* outputTypes, const DataType* inputTypes) -> Result<const FunctionDataType*>
{
	return MTable::_instance._DataTypeLib_GetFunctionType(outputTypes, inputTypes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDelegateType(const DataType* returnType, const Block<const DataType* const>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) -> Result<const DelegateDataType*>
{
	return MTable::_instance._DataTypeLib_GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDelegateType(const Result<const DataType*>& returnType, const Block<const Result<const DataType*>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) -> Result<const DelegateDataType*>
{
	return MTable::_instance._DataTypeLib_GetDelegateType_1(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::InvokeDelegate(const DelegateDataType* delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments) -> Result<void>
{
	return MTable::_instance._DataTypeLib_InvokeDelegate(delegateType, delegate, result, arguments);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::CreateDelegate(const DelegateDataType* delegateType, reflection::DelegateHandler&& handler) -> Result<DelegateBase>
{
	return MTable::_instance._DataTypeLib_CreateDelegate(delegateType, std::forward<reflection::DelegateHandler>(handler));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDelegateReturnType(const DelegateDataType* delegateType) -> const DataType*
{
	return MTable::_instance._DataTypeLib_GetDelegateReturnType(delegateType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDelegateParameterTypes(const DelegateDataType* delegateType) -> const Block<const DataType* const>&
{
	return MTable::_instance._DataTypeLib_GetDelegateParameterTypes(delegateType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetSimdElementType(const DataType* componentType, Int dimension, Int multiplicity) -> Result<const DataType*>
{
	return MTable::_instance._DataTypeLib_GetSimdElementType(componentType, dimension, multiplicity);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetEnumType(const DataType* underlyingType, const Block<const Tuple<Id, Data>>& enumerators) -> Result<const EnumDataType*>
{
	return MTable::_instance._DataTypeLib_GetEnumType(underlyingType, enumerators);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetEnumerators(const DataType* enumType) -> const Block<const Tuple<Id, Data>>&
{
	return MTable::_instance._DataTypeLib_GetEnumerators(enumType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::RegisterEnumType(DataType& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames) -> Result<const DataType*>
{
	return MTable::_instance._DataTypeLib_RegisterEnumType(type, typeId, size, isSigned, flags, enumValues, enumValueNames);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDataTypeOfInterfaces(const Block<const InterfaceReference* const>& interfaces) -> Result<const DataType*>
{
	return MTable::_instance._DataTypeLib_GetDataTypeOfInterfaces(interfaces);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::ParseDataType(const Char* name) -> Result<Tuple<const DataType*, const Char*>>
{
	return MTable::_instance._DataTypeLib_ParseDataType(name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDataType(const Id& typeId) -> Result<const DataType*>
{
	return MTable::_instance._DataTypeLib_GetDataType(typeId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetNumberedId(Int number) -> const Id&
{
	return MTable::_instance._DataTypeLib_GetNumberedId(number);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetConstant(const DataType* type, Int value) -> ConstDataPtr
{
	return MTable::_instance._DataTypeLib_GetConstant(type, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDataTypeForData(const DataType* valueType) -> Result<const DataType*>
{
	return MTable::_instance._DataTypeLib_GetDataTypeForData(valueType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::ConvertToData(Data& result, const DataType* dataType, const DataType* valueType, const Generic& value) -> Result<void>
{
	return MTable::_instance._DataTypeLib_ConvertToData(result, dataType, valueType, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::MoveFromData(const DataType* valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage) -> Result<void>
{
	return MTable::_instance._DataTypeLib_MoveFromData(valueType, value, createDefaultPointees, data, storage);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::IsBaseOfOrSame(const DataType* type, const DataType* other, DataType::MEMBER_MATCH_MODE mode) -> Bool
{
	return MTable::_instance._DataTypeLib_IsBaseOfOrSame(type, other, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::CreateTypeArguments(Int cnt) -> ResultPtr<TypeArguments>
{
	return MTable::_instance._DataTypeLib_CreateTypeArguments(cnt);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::FinalizeTypeArguments(TypeArguments& args) -> ResultMem
{
	return MTable::_instance._DataTypeLib_FinalizeTypeArguments(args);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::CreateTypeArguments(const Block<const Member>& args) -> ResultPtr<TypeArguments>
{
	return MTable::_instance._DataTypeLib_CreateTypeArguments_1(args);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_DataTypeLib(DataTypeLib::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datatypelib.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

