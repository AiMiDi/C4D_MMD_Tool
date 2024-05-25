
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
#ifndef _HAS_CPP20_COMPARISONS
#endif
constexpr const maxon::Char* DataTypeLib::PrivateGetCppName() { return nullptr; }

struct DataTypeLib::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetDataTypeType, GetDataTypeType, MAXON_EXPAND_VA_ARGS, (const DataType&));
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetVoidType, GetVoidType, MAXON_EXPAND_VA_ARGS, (const DataType&));
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetNullptrType, GetNullptrType, MAXON_EXPAND_VA_ARGS, (const DataType&));
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetGenericType, GetGenericType, MAXON_EXPAND_VA_ARGS, (const DataType&));
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetGenericArithmeticType, GetGenericArithmeticType, MAXON_EXPAND_VA_ARGS, (const DataType&));
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetParametricTypeType, GetParametricTypeType, MAXON_EXPAND_VA_ARGS, (const DataType&));
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetComponentDescriptorType, GetComponentDescriptorType, MAXON_EXPAND_VA_ARGS, (const DataType&));
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetEllipsisType, GetEllipsisType, MAXON_EXPAND_VA_ARGS, (const DataType&));
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetInvalidType, GetInvalidType, MAXON_EXPAND_VA_ARGS, (const DataType&));
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_Substitute, Substitute, MAXON_EXPAND_VA_ARGS, (Result<DataType>), const DataType& orig, const Delegate<Result<DataType>(const DataType&)>& replace);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetRuntimeDataType, GetRuntimeDataType, MAXON_EXPAND_VA_ARGS, (Result<DataType>), const DataType& orig);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetTupleMemberOffsets, GetTupleMemberOffsets, MAXON_EXPAND_VA_ARGS, (const Block<const Int>&), const TupleDataType& type);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetMemberOrder, GetMemberOrder, MAXON_EXPAND_VA_ARGS, (const Block<const Int>&), const DataType& bundleOrContainerType);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetDelegateType, GetDelegateType, MAXON_EXPAND_VA_ARGS, (Result<DelegateDataType>), const DataType& returnType, const Block<const DataType>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetDelegateType_1, GetDelegateType, MAXON_EXPAND_VA_ARGS, (Result<DelegateDataType>), const Result<DataType>& returnType, const Block<const Result<DataType>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_InvokeDelegate, InvokeDelegate, MAXON_EXPAND_VA_ARGS, (Result<void>), const DelegateDataType& delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_CreateDelegate, CreateDelegate, MAXON_EXPAND_VA_ARGS, (Result<DelegateBase>), const DelegateDataType& delegateType, reflection::DelegateHandler&& handler);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetDelegateReturnType, GetDelegateReturnType, MAXON_EXPAND_VA_ARGS, (const DataType&), const DelegateDataType& delegateType);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetDelegateParameterTypes, GetDelegateParameterTypes, MAXON_EXPAND_VA_ARGS, (const Block<const DataType>&), const DelegateDataType& delegateType);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetEnumType, GetEnumType, MAXON_EXPAND_VA_ARGS, (Result<EnumDataType>), const DataType& underlyingType, const Block<const Tuple<Id, Data>>& enumerators);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetEnumerators, GetEnumerators, MAXON_EXPAND_VA_ARGS, (const Block<const Tuple<Id, Data>>&), const DataType& enumType);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_RegisterEnumType, RegisterEnumType, MAXON_EXPAND_VA_ARGS, (Result<void>), DataTypeImpl& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetDataTypeOfInterfaces, GetDataTypeOfInterfaces, MAXON_EXPAND_VA_ARGS, (Result<DataType>), const Block<const InterfaceReference* const>& interfaces);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetReferenceType, GetReferenceType, MAXON_EXPAND_VA_ARGS, (Result<DataType>), const DataType& type, EntityBase::FLAGS refFlags);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_ParseDataType, ParseDataType, MAXON_EXPAND_VA_ARGS, (Result<Tuple<DataType, const Char*>>), const Char* str);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_ParseMember, ParseMember, MAXON_EXPAND_VA_ARGS, (Result<Tuple<Member, const Char*>>), const Char* str);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_ParseInt, ParseInt, MAXON_EXPAND_VA_ARGS, (Result<Tuple<Int64, const Char*>>), const Char* str);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetDataType, GetDataType, MAXON_EXPAND_VA_ARGS, (Result<DataType>), const Id& typeId);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetNumberedId, GetNumberedId, MAXON_EXPAND_VA_ARGS, (const Id&), Int number);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetMemberMap, GetMemberMap, MAXON_EXPAND_VA_ARGS, (Result<const MemberMap*>), Block<const Int> block);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetIdentityMemberMap, GetIdentityMemberMap, MAXON_EXPAND_VA_ARGS, (Result<const MemberMap*>), Int length);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_ConcatMemberMap, ConcatMemberMap, MAXON_EXPAND_VA_ARGS, (Result<const MemberMap*>), const MemberMap* first, const MemberMap* second);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetMemberMap_1, GetMemberMap, MAXON_EXPAND_VA_ARGS, (Result<const MemberMap*>), const DataTypeImpl* containerType, const DataTypeImpl* runtimeType);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_GetDataTypeForData, GetDataTypeForData, MAXON_EXPAND_VA_ARGS, (Result<DataType>), const DataType& valueType);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_ConvertToData, ConvertToData, MAXON_EXPAND_VA_ARGS, (Result<void>), Data& result, const DataType& dataType, const DataType& valueType, const Generic& value);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_MoveFromData, MoveFromData, MAXON_EXPAND_VA_ARGS, (Result<void>), const DataType& valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_PrivateIsBaseOfOrSame, PrivateIsBaseOfOrSame, MAXON_EXPAND_VA_ARGS, (Bool), const DataTypeImpl* type, const DataTypeImpl* other, DataType::BASE_OF_MODE mode);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_CreateTypeArguments, CreateTypeArguments, MAXON_EXPAND_VA_ARGS, (Result<StrongRef<TypeArguments>>), Int cnt);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_CreateTypeArguments_1, CreateTypeArguments, MAXON_EXPAND_VA_ARGS, (Result<StrongRef<TypeArguments>>), const Block<const Member>& args);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_FinalizeTypeArguments, FinalizeTypeArguments, MAXON_EXPAND_VA_ARGS, (ResultMem), TypeArguments& args);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_PrivateHandleUnreferencedType, PrivateHandleUnreferencedType, MAXON_EXPAND_VA_ARGS, (void), DataTypeImpl* type);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_PrivateGetPrimaryDataTypeType, PrivateGetPrimaryDataTypeType, MAXON_EXPAND_VA_ARGS, (const DataType&));
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_AddLeakingInstantiatedType, AddLeakingInstantiatedType, MAXON_EXPAND_VA_ARGS, (void), DataTypeImpl* type);
	PRIVATE_MAXON_SF_POINTER(DataTypeLib_PrivateGetNamedTupleMembers, PrivateGetNamedTupleMembers, MAXON_EXPAND_VA_ARGS, (void), Binary& binary, NamedTupleMembers* mem, std::add_pointer<Int(void*)>::type constructor);
	template <typename IMPL> void Init()
	{
		DataTypeLib_GetDataTypeType = DataTypeLib_GetDataTypeType_GetPtr<IMPL>(true);
		DataTypeLib_GetVoidType = DataTypeLib_GetVoidType_GetPtr<IMPL>(true);
		DataTypeLib_GetNullptrType = DataTypeLib_GetNullptrType_GetPtr<IMPL>(true);
		DataTypeLib_GetGenericType = DataTypeLib_GetGenericType_GetPtr<IMPL>(true);
		DataTypeLib_GetGenericArithmeticType = DataTypeLib_GetGenericArithmeticType_GetPtr<IMPL>(true);
		DataTypeLib_GetParametricTypeType = DataTypeLib_GetParametricTypeType_GetPtr<IMPL>(true);
		DataTypeLib_GetComponentDescriptorType = DataTypeLib_GetComponentDescriptorType_GetPtr<IMPL>(true);
		DataTypeLib_GetEllipsisType = DataTypeLib_GetEllipsisType_GetPtr<IMPL>(true);
		DataTypeLib_GetInvalidType = DataTypeLib_GetInvalidType_GetPtr<IMPL>(true);
		DataTypeLib_Substitute = DataTypeLib_Substitute_GetPtr<IMPL>(true);
		DataTypeLib_GetRuntimeDataType = DataTypeLib_GetRuntimeDataType_GetPtr<IMPL>(true);
		DataTypeLib_GetTupleMemberOffsets = DataTypeLib_GetTupleMemberOffsets_GetPtr<IMPL>(true);
		DataTypeLib_GetMemberOrder = DataTypeLib_GetMemberOrder_GetPtr<IMPL>(true);
		DataTypeLib_GetDelegateType = DataTypeLib_GetDelegateType_GetPtr<IMPL>(true);
		DataTypeLib_GetDelegateType_1 = DataTypeLib_GetDelegateType_1_GetPtr<IMPL>(true);
		DataTypeLib_InvokeDelegate = DataTypeLib_InvokeDelegate_GetPtr<IMPL>(true);
		DataTypeLib_CreateDelegate = DataTypeLib_CreateDelegate_GetPtr<IMPL>(true);
		DataTypeLib_GetDelegateReturnType = DataTypeLib_GetDelegateReturnType_GetPtr<IMPL>(true);
		DataTypeLib_GetDelegateParameterTypes = DataTypeLib_GetDelegateParameterTypes_GetPtr<IMPL>(true);
		DataTypeLib_GetEnumType = DataTypeLib_GetEnumType_GetPtr<IMPL>(true);
		DataTypeLib_GetEnumerators = DataTypeLib_GetEnumerators_GetPtr<IMPL>(true);
		DataTypeLib_RegisterEnumType = DataTypeLib_RegisterEnumType_GetPtr<IMPL>(true);
		DataTypeLib_GetDataTypeOfInterfaces = DataTypeLib_GetDataTypeOfInterfaces_GetPtr<IMPL>(true);
		DataTypeLib_GetReferenceType = DataTypeLib_GetReferenceType_GetPtr<IMPL>(true);
		DataTypeLib_ParseDataType = DataTypeLib_ParseDataType_GetPtr<IMPL>(true);
		DataTypeLib_ParseMember = DataTypeLib_ParseMember_GetPtr<IMPL>(true);
		DataTypeLib_ParseInt = DataTypeLib_ParseInt_GetPtr<IMPL>(true);
		DataTypeLib_GetDataType = DataTypeLib_GetDataType_GetPtr<IMPL>(true);
		DataTypeLib_GetNumberedId = DataTypeLib_GetNumberedId_GetPtr<IMPL>(true);
		DataTypeLib_GetMemberMap = DataTypeLib_GetMemberMap_GetPtr<IMPL>(true);
		DataTypeLib_GetIdentityMemberMap = DataTypeLib_GetIdentityMemberMap_GetPtr<IMPL>(true);
		DataTypeLib_ConcatMemberMap = DataTypeLib_ConcatMemberMap_GetPtr<IMPL>(true);
		DataTypeLib_GetMemberMap_1 = DataTypeLib_GetMemberMap_1_GetPtr<IMPL>(true);
		DataTypeLib_GetDataTypeForData = DataTypeLib_GetDataTypeForData_GetPtr<IMPL>(true);
		DataTypeLib_ConvertToData = DataTypeLib_ConvertToData_GetPtr<IMPL>(true);
		DataTypeLib_MoveFromData = DataTypeLib_MoveFromData_GetPtr<IMPL>(true);
		DataTypeLib_PrivateIsBaseOfOrSame = DataTypeLib_PrivateIsBaseOfOrSame_GetPtr<IMPL>(true);
		DataTypeLib_CreateTypeArguments = DataTypeLib_CreateTypeArguments_GetPtr<IMPL>(true);
		DataTypeLib_CreateTypeArguments_1 = DataTypeLib_CreateTypeArguments_1_GetPtr<IMPL>(true);
		DataTypeLib_FinalizeTypeArguments = DataTypeLib_FinalizeTypeArguments_GetPtr<IMPL>(true);
		DataTypeLib_PrivateHandleUnreferencedType = DataTypeLib_PrivateHandleUnreferencedType_GetPtr<IMPL>(true);
		DataTypeLib_PrivateGetPrimaryDataTypeType = DataTypeLib_PrivateGetPrimaryDataTypeType_GetPtr<IMPL>(true);
		DataTypeLib_AddLeakingInstantiatedType = DataTypeLib_AddLeakingInstantiatedType_GetPtr<IMPL>(true);
		DataTypeLib_PrivateGetNamedTupleMembers = DataTypeLib_PrivateGetNamedTupleMembers_GetPtr<IMPL>(true);
	}
};

struct DataTypeLib::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static const DataType& DataTypeLib_GetDataTypeType() { return S::GetDataTypeType(); }
		static const DataType& DataTypeLib_GetVoidType() { return S::GetVoidType(); }
		static const DataType& DataTypeLib_GetNullptrType() { return S::GetNullptrType(); }
		static const DataType& DataTypeLib_GetGenericType() { return S::GetGenericType(); }
		static const DataType& DataTypeLib_GetGenericArithmeticType() { return S::GetGenericArithmeticType(); }
		static const DataType& DataTypeLib_GetParametricTypeType() { return S::GetParametricTypeType(); }
		static const DataType& DataTypeLib_GetComponentDescriptorType() { return S::GetComponentDescriptorType(); }
		static const DataType& DataTypeLib_GetEllipsisType() { return S::GetEllipsisType(); }
		static const DataType& DataTypeLib_GetInvalidType() { return S::GetInvalidType(); }
		static Result<DataType> DataTypeLib_Substitute(const DataType& orig, const Delegate<Result<DataType>(const DataType&)>& replace) { return S::Substitute(orig, replace); }
		static Result<DataType> DataTypeLib_GetRuntimeDataType(const DataType& orig) { return S::GetRuntimeDataType(orig); }
		static const Block<const Int>& DataTypeLib_GetTupleMemberOffsets(const TupleDataType& type) { return S::GetTupleMemberOffsets(type); }
		static const Block<const Int>& DataTypeLib_GetMemberOrder(const DataType& bundleOrContainerType) { return S::GetMemberOrder(bundleOrContainerType); }
		static Result<DelegateDataType> DataTypeLib_GetDelegateType(const DataType& returnType, const Block<const DataType>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) { return S::GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub); }
		static Result<DelegateDataType> DataTypeLib_GetDelegateType_1(const Result<DataType>& returnType, const Block<const Result<DataType>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) { return S::GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub); }
		static Result<void> DataTypeLib_InvokeDelegate(const DelegateDataType& delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments) { return S::InvokeDelegate(delegateType, delegate, result, arguments); }
		static Result<DelegateBase> DataTypeLib_CreateDelegate(const DelegateDataType& delegateType, reflection::DelegateHandler&& handler) { return S::CreateDelegate(delegateType, std::forward<reflection::DelegateHandler>(handler)); }
		static const DataType& DataTypeLib_GetDelegateReturnType(const DelegateDataType& delegateType) { return S::GetDelegateReturnType(delegateType); }
		static const Block<const DataType>& DataTypeLib_GetDelegateParameterTypes(const DelegateDataType& delegateType) { return S::GetDelegateParameterTypes(delegateType); }
		static Result<EnumDataType> DataTypeLib_GetEnumType(const DataType& underlyingType, const Block<const Tuple<Id, Data>>& enumerators) { return S::GetEnumType(underlyingType, enumerators); }
		static const Block<const Tuple<Id, Data>>& DataTypeLib_GetEnumerators(const DataType& enumType) { return S::GetEnumerators(enumType); }
		static Result<void> DataTypeLib_RegisterEnumType(DataTypeImpl& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames) { return S::RegisterEnumType(type, typeId, size, isSigned, flags, enumValues, enumValueNames); }
		static Result<DataType> DataTypeLib_GetDataTypeOfInterfaces(const Block<const InterfaceReference* const>& interfaces) { return S::GetDataTypeOfInterfaces(interfaces); }
		static Result<DataType> DataTypeLib_GetReferenceType(const DataType& type, EntityBase::FLAGS refFlags) { return S::GetReferenceType(type, refFlags); }
		static Result<Tuple<DataType, const Char*>> DataTypeLib_ParseDataType(const Char* str) { return S::ParseDataType(str); }
		static Result<Tuple<Member, const Char*>> DataTypeLib_ParseMember(const Char* str) { return S::ParseMember(str); }
		static Result<Tuple<Int64, const Char*>> DataTypeLib_ParseInt(const Char* str) { return S::ParseInt(str); }
		static Result<DataType> DataTypeLib_GetDataType(const Id& typeId) { return S::GetDataType(typeId); }
		static const Id& DataTypeLib_GetNumberedId(Int number) { return S::GetNumberedId(number); }
		static Result<const MemberMap*> DataTypeLib_GetMemberMap(Block<const Int> block) { return S::GetMemberMap(std::forward<Block<const Int>>(block)); }
		static Result<const MemberMap*> DataTypeLib_GetIdentityMemberMap(Int length) { return S::GetIdentityMemberMap(length); }
		static Result<const MemberMap*> DataTypeLib_ConcatMemberMap(const MemberMap* first, const MemberMap* second) { return S::ConcatMemberMap(first, second); }
		static Result<const MemberMap*> DataTypeLib_GetMemberMap_1(const DataTypeImpl* containerType, const DataTypeImpl* runtimeType) { return S::GetMemberMap(containerType, runtimeType); }
		static Result<DataType> DataTypeLib_GetDataTypeForData(const DataType& valueType) { return S::GetDataTypeForData(valueType); }
		static Result<void> DataTypeLib_ConvertToData(Data& result, const DataType& dataType, const DataType& valueType, const Generic& value) { return S::ConvertToData(result, dataType, valueType, value); }
		static Result<void> DataTypeLib_MoveFromData(const DataType& valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage) { return S::MoveFromData(valueType, value, createDefaultPointees, data, storage); }
		static Bool DataTypeLib_PrivateIsBaseOfOrSame(const DataTypeImpl* type, const DataTypeImpl* other, DataType::BASE_OF_MODE mode) { return S::PrivateIsBaseOfOrSame(type, other, mode); }
		static Result<StrongRef<TypeArguments>> DataTypeLib_CreateTypeArguments(Int cnt) { return S::CreateTypeArguments(cnt); }
		static Result<StrongRef<TypeArguments>> DataTypeLib_CreateTypeArguments_1(const Block<const Member>& args) { return S::CreateTypeArguments(args); }
		static ResultMem DataTypeLib_FinalizeTypeArguments(TypeArguments& args) { return S::FinalizeTypeArguments(args); }
		static void DataTypeLib_PrivateHandleUnreferencedType(DataTypeImpl* type) { return S::PrivateHandleUnreferencedType(type); }
		static const DataType& DataTypeLib_PrivateGetPrimaryDataTypeType() { return S::PrivateGetPrimaryDataTypeType(); }
		static void DataTypeLib_AddLeakingInstantiatedType(DataTypeImpl* type) { return S::AddLeakingInstantiatedType(type); }
		static void DataTypeLib_PrivateGetNamedTupleMembers(Binary& binary, NamedTupleMembers* mem, std::add_pointer<Int(void*)>::type constructor) { return S::PrivateGetNamedTupleMembers(binary, mem, std::forward<std::add_pointer<Int(void*)>::type>(constructor)); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDataTypeType() -> const DataType&
{
	return MTable::_instance.DataTypeLib_GetDataTypeType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetVoidType() -> const DataType&
{
	return MTable::_instance.DataTypeLib_GetVoidType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetNullptrType() -> const DataType&
{
	return MTable::_instance.DataTypeLib_GetNullptrType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetGenericType() -> const DataType&
{
	return MTable::_instance.DataTypeLib_GetGenericType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetGenericArithmeticType() -> const DataType&
{
	return MTable::_instance.DataTypeLib_GetGenericArithmeticType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetParametricTypeType() -> const DataType&
{
	return MTable::_instance.DataTypeLib_GetParametricTypeType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetComponentDescriptorType() -> const DataType&
{
	return MTable::_instance.DataTypeLib_GetComponentDescriptorType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetEllipsisType() -> const DataType&
{
	return MTable::_instance.DataTypeLib_GetEllipsisType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetInvalidType() -> const DataType&
{
	return MTable::_instance.DataTypeLib_GetInvalidType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::Substitute(const DataType& orig, const Delegate<Result<DataType>(const DataType&)>& replace) -> Result<DataType>
{
	return MTable::_instance.DataTypeLib_Substitute(orig, replace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetRuntimeDataType(const DataType& orig) -> Result<DataType>
{
	return MTable::_instance.DataTypeLib_GetRuntimeDataType(orig);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetTupleMemberOffsets(const TupleDataType& type) -> const Block<const Int>&
{
	return MTable::_instance.DataTypeLib_GetTupleMemberOffsets(type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetMemberOrder(const DataType& bundleOrContainerType) -> const Block<const Int>&
{
	return MTable::_instance.DataTypeLib_GetMemberOrder(bundleOrContainerType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDelegateType(const DataType& returnType, const Block<const DataType>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) -> Result<DelegateDataType>
{
	return MTable::_instance.DataTypeLib_GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDelegateType(const Result<DataType>& returnType, const Block<const Result<DataType>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) -> Result<DelegateDataType>
{
	return MTable::_instance.DataTypeLib_GetDelegateType_1(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::InvokeDelegate(const DelegateDataType& delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments) -> Result<void>
{
	return MTable::_instance.DataTypeLib_InvokeDelegate(delegateType, delegate, result, arguments);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::CreateDelegate(const DelegateDataType& delegateType, reflection::DelegateHandler&& handler) -> Result<DelegateBase>
{
	return MTable::_instance.DataTypeLib_CreateDelegate(delegateType, std::forward<reflection::DelegateHandler>(handler));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDelegateReturnType(const DelegateDataType& delegateType) -> const DataType&
{
	return MTable::_instance.DataTypeLib_GetDelegateReturnType(delegateType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDelegateParameterTypes(const DelegateDataType& delegateType) -> const Block<const DataType>&
{
	return MTable::_instance.DataTypeLib_GetDelegateParameterTypes(delegateType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetEnumType(const DataType& underlyingType, const Block<const Tuple<Id, Data>>& enumerators) -> Result<EnumDataType>
{
	return MTable::_instance.DataTypeLib_GetEnumType(underlyingType, enumerators);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetEnumerators(const DataType& enumType) -> const Block<const Tuple<Id, Data>>&
{
	return MTable::_instance.DataTypeLib_GetEnumerators(enumType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::RegisterEnumType(DataTypeImpl& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames) -> Result<void>
{
	return MTable::_instance.DataTypeLib_RegisterEnumType(type, typeId, size, isSigned, flags, enumValues, enumValueNames);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDataTypeOfInterfaces(const Block<const InterfaceReference* const>& interfaces) -> Result<DataType>
{
	return MTable::_instance.DataTypeLib_GetDataTypeOfInterfaces(interfaces);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetReferenceType(const DataType& type, EntityBase::FLAGS refFlags) -> Result<DataType>
{
	return MTable::_instance.DataTypeLib_GetReferenceType(type, refFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::ParseDataType(const Char* str) -> Result<Tuple<DataType, const Char*>>
{
	return MTable::_instance.DataTypeLib_ParseDataType(str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::ParseMember(const Char* str) -> Result<Tuple<Member, const Char*>>
{
	return MTable::_instance.DataTypeLib_ParseMember(str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::ParseInt(const Char* str) -> Result<Tuple<Int64, const Char*>>
{
	return MTable::_instance.DataTypeLib_ParseInt(str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDataType(const Id& typeId) -> Result<DataType>
{
	return MTable::_instance.DataTypeLib_GetDataType(typeId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetNumberedId(Int number) -> const Id&
{
	return MTable::_instance.DataTypeLib_GetNumberedId(number);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetMemberMap(Block<const Int> block) -> Result<const MemberMap*>
{
	return MTable::_instance.DataTypeLib_GetMemberMap(std::forward<Block<const Int>>(block));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetIdentityMemberMap(Int length) -> Result<const MemberMap*>
{
	return MTable::_instance.DataTypeLib_GetIdentityMemberMap(length);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::ConcatMemberMap(const MemberMap* first, const MemberMap* second) -> Result<const MemberMap*>
{
	return MTable::_instance.DataTypeLib_ConcatMemberMap(first, second);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetMemberMap(const DataTypeImpl* containerType, const DataTypeImpl* runtimeType) -> Result<const MemberMap*>
{
	return MTable::_instance.DataTypeLib_GetMemberMap_1(containerType, runtimeType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDataTypeForData(const DataType& valueType) -> Result<DataType>
{
	return MTable::_instance.DataTypeLib_GetDataTypeForData(valueType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::ConvertToData(Data& result, const DataType& dataType, const DataType& valueType, const Generic& value) -> Result<void>
{
	return MTable::_instance.DataTypeLib_ConvertToData(result, dataType, valueType, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::MoveFromData(const DataType& valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage) -> Result<void>
{
	return MTable::_instance.DataTypeLib_MoveFromData(valueType, value, createDefaultPointees, data, storage);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::PrivateIsBaseOfOrSame(const DataTypeImpl* type, const DataTypeImpl* other, DataType::BASE_OF_MODE mode) -> Bool
{
	return MTable::_instance.DataTypeLib_PrivateIsBaseOfOrSame(type, other, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::CreateTypeArguments(Int cnt) -> Result<StrongRef<TypeArguments>>
{
	return MTable::_instance.DataTypeLib_CreateTypeArguments(cnt);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::CreateTypeArguments(const Block<const Member>& args) -> Result<StrongRef<TypeArguments>>
{
	return MTable::_instance.DataTypeLib_CreateTypeArguments_1(args);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::FinalizeTypeArguments(TypeArguments& args) -> ResultMem
{
	return MTable::_instance.DataTypeLib_FinalizeTypeArguments(args);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::PrivateHandleUnreferencedType(DataTypeImpl* type) -> void
{
	return MTable::_instance.DataTypeLib_PrivateHandleUnreferencedType(type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::PrivateGetPrimaryDataTypeType() -> const DataType&
{
	return MTable::_instance.DataTypeLib_PrivateGetPrimaryDataTypeType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::AddLeakingInstantiatedType(DataTypeImpl* type) -> void
{
	return MTable::_instance.DataTypeLib_AddLeakingInstantiatedType(type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::PrivateGetNamedTupleMembers(Binary& binary, NamedTupleMembers* mem, std::add_pointer<Int(void*)>::type constructor) -> void
{
	return MTable::_instance.DataTypeLib_PrivateGetNamedTupleMembers(binary, mem, std::forward<std::add_pointer<Int(void*)>::type>(constructor));
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datatypelib)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataTypeLib); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataTypeLib() { new (s_ui_maxon_DataTypeLib) maxon::EntityUse(DataTypeLib::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datatypelib.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataTypeLib(DataTypeLib::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datatypelib.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

