#if 1
namespace maxon
{
	const maxon::Char* const DataTypeLib::MTable::_ids = 
		"GetDataTypeType@f6200306f4b33429\0" // GetDataTypeType()
		"GetVoidType@f6200306f4b33429\0" // GetVoidType()
		"GetNullptrType@f6200306f4b33429\0" // GetNullptrType()
		"GetGenericType@f6200306f4b33429\0" // GetGenericType()
		"GetGenericArithmeticType@f6200306f4b33429\0" // GetGenericArithmeticType()
		"GetParametricTypeType@f6200306f4b33429\0" // GetParametricTypeType()
		"GetComponentDescriptorType@f6200306f4b33429\0" // GetComponentDescriptorType()
		"Substitute@faf9bbcbc67fb17f\0" // Substitute(const DataType* orig, const Delegate<Result<const DataType*>(const DataType*)>& replace)
		"GetRuntimeDataType@f4f9b1f979332ae9\0" // GetRuntimeDataType(const DataType* orig)
		"GetTupleType@57afc860ecc80e3a\0" // GetTupleType(const Block<const DataType* const>& types)
		"GetTupleType@b680ec92e911faaf\0" // GetTupleType(const Block<const Result<const DataType*>>& types)
		"GetTupleType@8c6f18c6c030f4d9\0" // GetTupleType(const Block<const Member>& members)
		"GetTupleTypeWithIndividualMembers@30d00749eddca929\0" // GetTupleTypeWithIndividualMembers(const TupleDataType* type)
		"GetTupleMemberOffsets@24b12f4145a616f3\0" // GetTupleMemberOffsets(const TupleDataType* type)
		"GetFunctionType@36f5981a620ed334\0" // GetFunctionType(const DataType* outputTypes, const DataType* inputTypes)
		"GetDelegateType@0cfc435a0374b035\0" // GetDelegateType(const DataType* returnType, const Block<const DataType* const>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub)
		"GetDelegateType@a6f1905ad1c277d0\0" // GetDelegateType(const Result<const DataType*>& returnType, const Block<const Result<const DataType*>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub)
		"InvokeDelegate@b41e8399ebc39238\0" // InvokeDelegate(const DelegateDataType* delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments)
		"CreateDelegate@478c04f891f8b10b\0" // CreateDelegate(const DelegateDataType* delegateType, reflection::DelegateHandler&& handler)
		"GetDelegateReturnType@a40dad475248e2d9\0" // GetDelegateReturnType(const DelegateDataType* delegateType)
		"GetDelegateParameterTypes@bc924a5b3d3e20da\0" // GetDelegateParameterTypes(const DelegateDataType* delegateType)
		"GetSimdElementType@770ddd091bbe66e3\0" // GetSimdElementType(const DataType* componentType, Int dimension, Int multiplicity)
		"GetEnumType@a294692cab0a0f24\0" // GetEnumType(const DataType* underlyingType, const Block<const Tuple<Id, Data>>& enumerators)
		"GetEnumerators@22e88abdca71adad\0" // GetEnumerators(const DataType* enumType)
		"RegisterEnumType@79e3ced958382877\0" // RegisterEnumType(DataType& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames)
		"GetDataTypeOfInterfaces@0b09cc4ba67792f8\0" // GetDataTypeOfInterfaces(const Block<const InterfaceReference* const>& interfaces)
		"ParseDataType@81d7596b58480842\0" // ParseDataType(const Char* name)
		"GetDataType@2bb6cfdd661bb0c4\0" // GetDataType(const Id& typeId)
		"GetNumberedId@f0c5c3f4ba887189\0" // GetNumberedId(Int number)
		"GetConstant@82835af19c523119\0" // GetConstant(const DataType* type, Int value)
		"GetDataTypeForData@f4f9b1f979332ae9\0" // GetDataTypeForData(const DataType* valueType)
		"ConvertToData@7d5ec4fbf57e3d49\0" // ConvertToData(Data& result, const DataType* dataType, const DataType* valueType, const Generic& value)
		"MoveFromData@fe70c45122e0cf2d\0" // MoveFromData(const DataType* valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage)
		"IsBaseOfOrSame@55d5e3a370ab4764\0" // IsBaseOfOrSame(const DataType* type, const DataType* other, DataType::MEMBER_MATCH_MODE mode)
		"CreateTypeArguments@d650953820345aaa\0" // CreateTypeArguments(Int cnt)
		"FinalizeTypeArguments@6a8ed66b0384c2ae\0" // FinalizeTypeArguments(TypeArguments& args)
		"CreateTypeArguments@5181d277dbc04482\0" // CreateTypeArguments(const Block<const Member>& args)
	"";
	class DataTypeLib::Unresolved : public DataTypeLib
	{
	public:
		static const Unresolved* Get(const DataTypeLib* o) { return (const Unresolved*) o; }
		static Unresolved* Get(DataTypeLib* o) { return (Unresolved*) o; }
		static const DataType* GetDataTypeType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetDataTypeType(); return nullptr;}
		static const DataType* GetVoidType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetVoidType(); return nullptr;}
		static const DataType* GetNullptrType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetNullptrType(); return nullptr;}
		static const DataType* GetGenericType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetGenericType(); return nullptr;}
		static const DataType* GetGenericArithmeticType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetGenericArithmeticType(); return nullptr;}
		static const DataType* GetParametricTypeType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetParametricTypeType(); return nullptr;}
		static const DataType* GetComponentDescriptorType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetComponentDescriptorType(); return nullptr;}
		static Result<const DataType*> Substitute(const DataType* orig, const Delegate<Result<const DataType*>(const DataType*)>& replace) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::Substitute(orig, replace); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<const DataType*> GetRuntimeDataType(const DataType* orig) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetRuntimeDataType(orig); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<const TupleDataType*> GetTupleType(const Block<const DataType* const>& types) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetTupleType(types); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<const TupleDataType*> GetTupleType(const Block<const Result<const DataType*>>& types) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetTupleType(types); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<const TupleDataType*> GetTupleType(const Block<const Member>& members) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetTupleType(members); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<const TupleDataType*> GetTupleTypeWithIndividualMembers(const TupleDataType* type) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetTupleTypeWithIndividualMembers(type); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static const Block<const Int>& GetTupleMemberOffsets(const TupleDataType* type) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetTupleMemberOffsets(type); return maxon::PrivateIncompleteNullReturnValue<const Block<const Int>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<const FunctionDataType*> GetFunctionType(const DataType* outputTypes, const DataType* inputTypes) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetFunctionType(outputTypes, inputTypes); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<const DelegateDataType*> GetDelegateType(const DataType* returnType, const Block<const DataType* const>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<const DelegateDataType*> GetDelegateType(const Result<const DataType*>& returnType, const Block<const Result<const DataType*>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> InvokeDelegate(const DelegateDataType* delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::InvokeDelegate(delegateType, delegate, result, arguments); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<DelegateBase> CreateDelegate(const DelegateDataType* delegateType, reflection::DelegateHandler&& handler) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::CreateDelegate(delegateType, std::forward<reflection::DelegateHandler>(handler)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static const DataType* GetDelegateReturnType(const DelegateDataType* delegateType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetDelegateReturnType(delegateType); return nullptr;}
		static const Block<const DataType* const>& GetDelegateParameterTypes(const DelegateDataType* delegateType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetDelegateParameterTypes(delegateType); return maxon::PrivateIncompleteNullReturnValue<const Block<const DataType* const>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<const DataType*> GetSimdElementType(const DataType* componentType, Int dimension, Int multiplicity) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetSimdElementType(componentType, dimension, multiplicity); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<const EnumDataType*> GetEnumType(const DataType* underlyingType, const Block<const Tuple<Id, Data>>& enumerators) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetEnumType(underlyingType, enumerators); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static const Block<const Tuple<Id, Data>>& GetEnumerators(const DataType* enumType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetEnumerators(enumType); return maxon::PrivateIncompleteNullReturnValue<const Block<const Tuple<Id, Data>>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<const DataType*> RegisterEnumType(DataType& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::RegisterEnumType(type, typeId, size, isSigned, flags, enumValues, enumValueNames); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<const DataType*> GetDataTypeOfInterfaces(const Block<const InterfaceReference* const>& interfaces) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDataTypeOfInterfaces(interfaces); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Tuple<const DataType*, const Char*>> ParseDataType(const Char* name) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::ParseDataType(name); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<const DataType*> GetDataType(const Id& typeId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDataType(typeId); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static const Id& GetNumberedId(Int number) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetNumberedId(number); return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static ConstDataPtr GetConstant(const DataType* type, Int value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::GetConstant(type, value); return maxon::PrivateIncompleteNullReturnValue<ConstDataPtr>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<const DataType*> GetDataTypeForData(const DataType* valueType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::GetDataTypeForData(valueType); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> ConvertToData(Data& result, const DataType* dataType, const DataType* valueType, const Generic& value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::ConvertToData(result, dataType, valueType, value); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> MoveFromData(const DataType* valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return DataTypeLib::MoveFromData(valueType, value, createDefaultPointees, data, storage); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Bool IsBaseOfOrSame(const DataType* type, const DataType* other, DataType::MEMBER_MATCH_MODE mode) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::IsBaseOfOrSame(type, other, mode); return maxon::PrivateLogNullptrError(false);}
		static ResultPtr<TypeArguments> CreateTypeArguments(Int cnt) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::CreateTypeArguments(cnt); return maxon::PrivateIncompleteNullReturnValue<ResultPtr<TypeArguments>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static ResultMem FinalizeTypeArguments(TypeArguments& args) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::FinalizeTypeArguments(args); return maxon::PrivateIncompleteNullReturnValue<ResultMem>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static ResultPtr<TypeArguments> CreateTypeArguments(const Block<const Member>& args) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return DataTypeLib::CreateTypeArguments(args); return maxon::PrivateIncompleteNullReturnValue<ResultPtr<TypeArguments>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE DataTypeLib::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<const DataType*>::value,
		maxon::details::NullReturnType<const DataType*>::value,
		maxon::details::NullReturnType<const DataType*>::value,
		maxon::details::NullReturnType<const DataType*>::value,
		maxon::details::NullReturnType<const DataType*>::value,
		maxon::details::NullReturnType<const DataType*>::value,
		maxon::details::NullReturnType<const DataType*>::value,
		maxon::details::NullReturnType<Result<const DataType*>>::value,
		maxon::details::NullReturnType<Result<const DataType*>>::value,
		maxon::details::NullReturnType<Result<const TupleDataType*>>::value,
		maxon::details::NullReturnType<Result<const TupleDataType*>>::value,
		maxon::details::NullReturnType<Result<const TupleDataType*>>::value,
		maxon::details::NullReturnType<Result<const TupleDataType*>>::value,
		maxon::details::NullReturnType<const Block<const Int>&>::value,
		maxon::details::NullReturnType<Result<const FunctionDataType*>>::value,
		maxon::details::NullReturnType<Result<const DelegateDataType*>>::value,
		maxon::details::NullReturnType<Result<const DelegateDataType*>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<DelegateBase>>::value,
		maxon::details::NullReturnType<const DataType*>::value,
		maxon::details::NullReturnType<const Block<const DataType* const>&>::value,
		maxon::details::NullReturnType<Result<const DataType*>>::value,
		maxon::details::NullReturnType<Result<const EnumDataType*>>::value,
		maxon::details::NullReturnType<const Block<const Tuple<Id, Data>>&>::value,
		maxon::details::NullReturnType<Result<const DataType*>>::value,
		maxon::details::NullReturnType<Result<const DataType*>>::value,
		maxon::details::NullReturnType<Result<Tuple<const DataType*, const Char*>>>::value,
		maxon::details::NullReturnType<Result<const DataType*>>::value,
		maxon::details::NullReturnType<const Id&>::value,
		maxon::details::NullReturnType<ConstDataPtr>::value,
		maxon::details::NullReturnType<Result<const DataType*>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<ResultPtr<TypeArguments>>::value,
		maxon::details::NullReturnType<ResultMem>::value,
		maxon::details::NullReturnType<ResultPtr<TypeArguments>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataTypeLib::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataTypeLib_GetDataTypeType = &Wrapper<Unresolved>::_DataTypeLib_GetDataTypeType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataTypeLib_GetVoidType = &Wrapper<Unresolved>::_DataTypeLib_GetVoidType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataTypeLib_GetNullptrType = &Wrapper<Unresolved>::_DataTypeLib_GetNullptrType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataTypeLib_GetGenericType = &Wrapper<Unresolved>::_DataTypeLib_GetGenericType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataTypeLib_GetGenericArithmeticType = &Wrapper<Unresolved>::_DataTypeLib_GetGenericArithmeticType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataTypeLib_GetParametricTypeType = &Wrapper<Unresolved>::_DataTypeLib_GetParametricTypeType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataTypeLib_GetComponentDescriptorType = &Wrapper<Unresolved>::_DataTypeLib_GetComponentDescriptorType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const DataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_Substitute = &Wrapper<Unresolved>::_DataTypeLib_Substitute;
	#else
		tbl->_DataTypeLib_Substitute = &Wrapper<Unresolved>::_DataTypeLib_Substitute;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const DataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetRuntimeDataType = &Wrapper<Unresolved>::_DataTypeLib_GetRuntimeDataType;
	#else
		tbl->_DataTypeLib_GetRuntimeDataType = &Wrapper<Unresolved>::_DataTypeLib_GetRuntimeDataType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const TupleDataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetTupleType = &Wrapper<Unresolved>::_DataTypeLib_GetTupleType;
	#else
		tbl->_DataTypeLib_GetTupleType = &Wrapper<Unresolved>::_DataTypeLib_GetTupleType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const TupleDataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetTupleType_1 = &Wrapper<Unresolved>::_DataTypeLib_GetTupleType_1;
	#else
		tbl->_DataTypeLib_GetTupleType_1 = &Wrapper<Unresolved>::_DataTypeLib_GetTupleType_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const TupleDataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetTupleType_2 = &Wrapper<Unresolved>::_DataTypeLib_GetTupleType_2;
	#else
		tbl->_DataTypeLib_GetTupleType_2 = &Wrapper<Unresolved>::_DataTypeLib_GetTupleType_2;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const TupleDataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetTupleTypeWithIndividualMembers = &Wrapper<Unresolved>::_DataTypeLib_GetTupleTypeWithIndividualMembers;
	#else
		tbl->_DataTypeLib_GetTupleTypeWithIndividualMembers = &Wrapper<Unresolved>::_DataTypeLib_GetTupleTypeWithIndividualMembers;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Block<const Int>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetTupleMemberOffsets = &Wrapper<Unresolved>::_DataTypeLib_GetTupleMemberOffsets;
	#else
		tbl->_DataTypeLib_GetTupleMemberOffsets = &Wrapper<Unresolved>::_DataTypeLib_GetTupleMemberOffsets;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const FunctionDataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetFunctionType = &Wrapper<Unresolved>::_DataTypeLib_GetFunctionType;
	#else
		tbl->_DataTypeLib_GetFunctionType = &Wrapper<Unresolved>::_DataTypeLib_GetFunctionType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const DelegateDataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetDelegateType = &Wrapper<Unresolved>::_DataTypeLib_GetDelegateType;
	#else
		tbl->_DataTypeLib_GetDelegateType = &Wrapper<Unresolved>::_DataTypeLib_GetDelegateType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const DelegateDataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetDelegateType_1 = &Wrapper<Unresolved>::_DataTypeLib_GetDelegateType_1;
	#else
		tbl->_DataTypeLib_GetDelegateType_1 = &Wrapper<Unresolved>::_DataTypeLib_GetDelegateType_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_InvokeDelegate = &Wrapper<Unresolved>::_DataTypeLib_InvokeDelegate;
	#else
		tbl->_DataTypeLib_InvokeDelegate = &Wrapper<Unresolved>::_DataTypeLib_InvokeDelegate;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<DelegateBase>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_CreateDelegate = &Wrapper<Unresolved>::_DataTypeLib_CreateDelegate;
	#else
		tbl->_DataTypeLib_CreateDelegate = &Wrapper<Unresolved>::_DataTypeLib_CreateDelegate;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataTypeLib_GetDelegateReturnType = &Wrapper<Unresolved>::_DataTypeLib_GetDelegateReturnType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Block<const DataType* const>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetDelegateParameterTypes = &Wrapper<Unresolved>::_DataTypeLib_GetDelegateParameterTypes;
	#else
		tbl->_DataTypeLib_GetDelegateParameterTypes = &Wrapper<Unresolved>::_DataTypeLib_GetDelegateParameterTypes;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const DataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetSimdElementType = &Wrapper<Unresolved>::_DataTypeLib_GetSimdElementType;
	#else
		tbl->_DataTypeLib_GetSimdElementType = &Wrapper<Unresolved>::_DataTypeLib_GetSimdElementType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const EnumDataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetEnumType = &Wrapper<Unresolved>::_DataTypeLib_GetEnumType;
	#else
		tbl->_DataTypeLib_GetEnumType = &Wrapper<Unresolved>::_DataTypeLib_GetEnumType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Block<const Tuple<Id, Data>>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetEnumerators = &Wrapper<Unresolved>::_DataTypeLib_GetEnumerators;
	#else
		tbl->_DataTypeLib_GetEnumerators = &Wrapper<Unresolved>::_DataTypeLib_GetEnumerators;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const DataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_RegisterEnumType = &Wrapper<Unresolved>::_DataTypeLib_RegisterEnumType;
	#else
		tbl->_DataTypeLib_RegisterEnumType = &Wrapper<Unresolved>::_DataTypeLib_RegisterEnumType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const DataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetDataTypeOfInterfaces = &Wrapper<Unresolved>::_DataTypeLib_GetDataTypeOfInterfaces;
	#else
		tbl->_DataTypeLib_GetDataTypeOfInterfaces = &Wrapper<Unresolved>::_DataTypeLib_GetDataTypeOfInterfaces;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Tuple<const DataType*, const Char*>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_ParseDataType = &Wrapper<Unresolved>::_DataTypeLib_ParseDataType;
	#else
		tbl->_DataTypeLib_ParseDataType = &Wrapper<Unresolved>::_DataTypeLib_ParseDataType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const DataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetDataType = &Wrapper<Unresolved>::_DataTypeLib_GetDataType;
	#else
		tbl->_DataTypeLib_GetDataType = &Wrapper<Unresolved>::_DataTypeLib_GetDataType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Id&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetNumberedId = &Wrapper<Unresolved>::_DataTypeLib_GetNumberedId;
	#else
		tbl->_DataTypeLib_GetNumberedId = &Wrapper<Unresolved>::_DataTypeLib_GetNumberedId;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ConstDataPtr>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetConstant = &Wrapper<Unresolved>::_DataTypeLib_GetConstant;
	#else
		tbl->_DataTypeLib_GetConstant = &Wrapper<Unresolved>::_DataTypeLib_GetConstant;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const DataType*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_GetDataTypeForData = &Wrapper<Unresolved>::_DataTypeLib_GetDataTypeForData;
	#else
		tbl->_DataTypeLib_GetDataTypeForData = &Wrapper<Unresolved>::_DataTypeLib_GetDataTypeForData;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_ConvertToData = &Wrapper<Unresolved>::_DataTypeLib_ConvertToData;
	#else
		tbl->_DataTypeLib_ConvertToData = &Wrapper<Unresolved>::_DataTypeLib_ConvertToData;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_MoveFromData = &Wrapper<Unresolved>::_DataTypeLib_MoveFromData;
	#else
		tbl->_DataTypeLib_MoveFromData = &Wrapper<Unresolved>::_DataTypeLib_MoveFromData;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_DataTypeLib_IsBaseOfOrSame = &Wrapper<Unresolved>::_DataTypeLib_IsBaseOfOrSame;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ResultPtr<TypeArguments>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_CreateTypeArguments = &Wrapper<Unresolved>::_DataTypeLib_CreateTypeArguments;
	#else
		tbl->_DataTypeLib_CreateTypeArguments = &Wrapper<Unresolved>::_DataTypeLib_CreateTypeArguments;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ResultMem>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_FinalizeTypeArguments = &Wrapper<Unresolved>::_DataTypeLib_FinalizeTypeArguments;
	#else
		tbl->_DataTypeLib_FinalizeTypeArguments = &Wrapper<Unresolved>::_DataTypeLib_FinalizeTypeArguments;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ResultPtr<TypeArguments>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DataTypeLib_CreateTypeArguments_1 = &Wrapper<Unresolved>::_DataTypeLib_CreateTypeArguments_1;
	#else
		tbl->_DataTypeLib_CreateTypeArguments_1 = &Wrapper<Unresolved>::_DataTypeLib_CreateTypeArguments_1;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(DataTypeLib, "net.maxon.interface.datatypelib", nullptr);
	template <typename DUMMY> maxon::Int DataTypeLib::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ConstDataPtr>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<ResultMem>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<ResultPtr<TypeArguments>>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Block<const DataType* const>&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Block<const Int>&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Block<const Tuple<Id, Data>>&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Id&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_datatypelib(0
	| maxon::DataTypeLib::PrivateInstantiateNullValueHelper<maxon::Int>()
);
