
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
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	const DataType& (*DataTypeLib_GetDataTypeType) ();
	const DataType& (*DataTypeLib_GetVoidType) ();
	const DataType& (*DataTypeLib_GetNullptrType) ();
	const DataType& (*DataTypeLib_GetGenericType) ();
	const DataType& (*DataTypeLib_GetGenericArithmeticType) ();
	const DataType& (*DataTypeLib_GetParametricTypeType) ();
	const DataType& (*DataTypeLib_GetComponentDescriptorType) ();
	const DataType& (*DataTypeLib_GetEllipsisType) ();
	const DataType& (*DataTypeLib_GetInvalidType) ();
	Result<DataType> (*DataTypeLib_Substitute) (const DataType& orig, const Delegate<Result<DataType>(const DataType&)>& replace);
	Result<DataType> (*DataTypeLib_GetRuntimeDataType) (const DataType& orig);
	const Block<const Int>& (*DataTypeLib_GetTupleMemberOffsets) (const TupleDataType& type);
	const Block<const Int>& (*DataTypeLib_GetMemberOrder) (const DataType& bundleOrContainerType);
	Result<DelegateDataType> (*DataTypeLib_GetDelegateType) (const DataType& returnType, const Block<const DataType>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub);
	Result<DelegateDataType> (*DataTypeLib_GetDelegateType_1) (const Result<DataType>& returnType, const Block<const Result<DataType>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub);
	Result<void> (*DataTypeLib_InvokeDelegate) (const DelegateDataType& delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments);
	Result<DelegateBase> (*DataTypeLib_CreateDelegate) (const DelegateDataType& delegateType, reflection::DelegateHandler&& handler);
	const DataType& (*DataTypeLib_GetDelegateReturnType) (const DelegateDataType& delegateType);
	const Block<const DataType>& (*DataTypeLib_GetDelegateParameterTypes) (const DelegateDataType& delegateType);
	Result<EnumDataType> (*DataTypeLib_GetEnumType) (const DataType& underlyingType, const Block<const Tuple<Id, Data>>& enumerators);
	const Block<const Tuple<Id, Data>>& (*DataTypeLib_GetEnumerators) (const DataType& enumType);
	Result<void> (*DataTypeLib_RegisterEnumType) (DataTypeImpl& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames);
	Result<DataType> (*DataTypeLib_GetDataTypeOfInterfaces) (const Block<const InterfaceReference* const>& interfaces);
	Result<DataType> (*DataTypeLib_GetReferenceType) (const DataType& type, EntityBase::FLAGS refFlags);
	Result<Tuple<DataType, const Char*>> (*DataTypeLib_ParseDataType) (const Char* str);
	Result<Tuple<Member, const Char*>> (*DataTypeLib_ParseMember) (const Char* str);
	Result<Tuple<Int64, const Char*>> (*DataTypeLib_ParseInt) (const Char* str);
	Result<DataType> (*DataTypeLib_GetDataType) (const Id& typeId);
	const Id& (*DataTypeLib_GetNumberedId) (Int number);
	Result<const MemberMap*> (*DataTypeLib_GetMemberMap) (Block<const Int> block);
	Result<const MemberMap*> (*DataTypeLib_GetIdentityMemberMap) (Int length);
	Result<const MemberMap*> (*DataTypeLib_ConcatMemberMap) (const MemberMap* first, const MemberMap* second);
	Result<const MemberMap*> (*DataTypeLib_GetMemberMap_1) (const DataTypeImpl* containerType, const DataTypeImpl* runtimeType);
	ConstDataPtr (*DataTypeLib_GetConstant) (const DataType& type, Int value);
	Result<DataType> (*DataTypeLib_GetDataTypeForData) (const DataType& valueType);
	Result<void> (*DataTypeLib_ConvertToData) (Data& result, const DataType& dataType, const DataType& valueType, const Generic& value);
	Result<void> (*DataTypeLib_MoveFromData) (const DataType& valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage);
	Bool (*DataTypeLib_PrivateIsBaseOfOrSame) (const DataTypeImpl* type, const DataTypeImpl* other, DataType::BASE_OF_MODE mode);
	Result<StrongRef<TypeArguments>> (*DataTypeLib_CreateTypeArguments) (Int cnt);
	Result<StrongRef<TypeArguments>> (*DataTypeLib_CreateTypeArguments_1) (const Block<const Member>& args);
	ResultMem (*DataTypeLib_FinalizeTypeArguments) (TypeArguments& args);
	void (*DataTypeLib_PrivateHandleUnreferencedType) (DataTypeImpl* type);
	const DataType& (*DataTypeLib_PrivateGetPrimaryDataTypeType) ();
	void (*DataTypeLib_AddLeakingInstantiatedType) (DataTypeImpl* type);
	const Block<const Member>& (*DataTypeLib_PrivateGetNamedTupleMembers) (Binary& binary, NamedTupleMembers* mem, std::add_pointer<Int(void*)>::type constructor);
	const Generic* (*DataTypeLib_PrivateGetDefault) (const DataTypeImpl* type);
	template <typename IMPL> void Init()
	{
		DataTypeLib_GetDataTypeType = &IMPL::DataTypeLib_GetDataTypeType;
		DataTypeLib_GetVoidType = &IMPL::DataTypeLib_GetVoidType;
		DataTypeLib_GetNullptrType = &IMPL::DataTypeLib_GetNullptrType;
		DataTypeLib_GetGenericType = &IMPL::DataTypeLib_GetGenericType;
		DataTypeLib_GetGenericArithmeticType = &IMPL::DataTypeLib_GetGenericArithmeticType;
		DataTypeLib_GetParametricTypeType = &IMPL::DataTypeLib_GetParametricTypeType;
		DataTypeLib_GetComponentDescriptorType = &IMPL::DataTypeLib_GetComponentDescriptorType;
		DataTypeLib_GetEllipsisType = &IMPL::DataTypeLib_GetEllipsisType;
		DataTypeLib_GetInvalidType = &IMPL::DataTypeLib_GetInvalidType;
		DataTypeLib_Substitute = &IMPL::DataTypeLib_Substitute;
		DataTypeLib_GetRuntimeDataType = &IMPL::DataTypeLib_GetRuntimeDataType;
		DataTypeLib_GetTupleMemberOffsets = &IMPL::DataTypeLib_GetTupleMemberOffsets;
		DataTypeLib_GetMemberOrder = &IMPL::DataTypeLib_GetMemberOrder;
		DataTypeLib_GetDelegateType = &IMPL::DataTypeLib_GetDelegateType;
		DataTypeLib_GetDelegateType_1 = &IMPL::DataTypeLib_GetDelegateType_1;
		DataTypeLib_InvokeDelegate = &IMPL::DataTypeLib_InvokeDelegate;
		DataTypeLib_CreateDelegate = &IMPL::DataTypeLib_CreateDelegate;
		DataTypeLib_GetDelegateReturnType = &IMPL::DataTypeLib_GetDelegateReturnType;
		DataTypeLib_GetDelegateParameterTypes = &IMPL::DataTypeLib_GetDelegateParameterTypes;
		DataTypeLib_GetEnumType = &IMPL::DataTypeLib_GetEnumType;
		DataTypeLib_GetEnumerators = &IMPL::DataTypeLib_GetEnumerators;
		DataTypeLib_RegisterEnumType = &IMPL::DataTypeLib_RegisterEnumType;
		DataTypeLib_GetDataTypeOfInterfaces = &IMPL::DataTypeLib_GetDataTypeOfInterfaces;
		DataTypeLib_GetReferenceType = &IMPL::DataTypeLib_GetReferenceType;
		DataTypeLib_ParseDataType = &IMPL::DataTypeLib_ParseDataType;
		DataTypeLib_ParseMember = &IMPL::DataTypeLib_ParseMember;
		DataTypeLib_ParseInt = &IMPL::DataTypeLib_ParseInt;
		DataTypeLib_GetDataType = &IMPL::DataTypeLib_GetDataType;
		DataTypeLib_GetNumberedId = &IMPL::DataTypeLib_GetNumberedId;
		DataTypeLib_GetMemberMap = &IMPL::DataTypeLib_GetMemberMap;
		DataTypeLib_GetIdentityMemberMap = &IMPL::DataTypeLib_GetIdentityMemberMap;
		DataTypeLib_ConcatMemberMap = &IMPL::DataTypeLib_ConcatMemberMap;
		DataTypeLib_GetMemberMap_1 = &IMPL::DataTypeLib_GetMemberMap_1;
		DataTypeLib_GetConstant = &IMPL::DataTypeLib_GetConstant;
		DataTypeLib_GetDataTypeForData = &IMPL::DataTypeLib_GetDataTypeForData;
		DataTypeLib_ConvertToData = &IMPL::DataTypeLib_ConvertToData;
		DataTypeLib_MoveFromData = &IMPL::DataTypeLib_MoveFromData;
		DataTypeLib_PrivateIsBaseOfOrSame = &IMPL::DataTypeLib_PrivateIsBaseOfOrSame;
		DataTypeLib_CreateTypeArguments = &IMPL::DataTypeLib_CreateTypeArguments;
		DataTypeLib_CreateTypeArguments_1 = &IMPL::DataTypeLib_CreateTypeArguments_1;
		DataTypeLib_FinalizeTypeArguments = &IMPL::DataTypeLib_FinalizeTypeArguments;
		DataTypeLib_PrivateHandleUnreferencedType = &IMPL::DataTypeLib_PrivateHandleUnreferencedType;
		DataTypeLib_PrivateGetPrimaryDataTypeType = &IMPL::DataTypeLib_PrivateGetPrimaryDataTypeType;
		DataTypeLib_AddLeakingInstantiatedType = &IMPL::DataTypeLib_AddLeakingInstantiatedType;
		DataTypeLib_PrivateGetNamedTupleMembers = &IMPL::DataTypeLib_PrivateGetNamedTupleMembers;
		DataTypeLib_PrivateGetDefault = &IMPL::DataTypeLib_PrivateGetDefault;
	}
};

struct DataTypeLib::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static const DataType& DataTypeLib_GetDataTypeType() { return C::GetDataTypeType(); }
		static const DataType& DataTypeLib_GetVoidType() { return C::GetVoidType(); }
		static const DataType& DataTypeLib_GetNullptrType() { return C::GetNullptrType(); }
		static const DataType& DataTypeLib_GetGenericType() { return C::GetGenericType(); }
		static const DataType& DataTypeLib_GetGenericArithmeticType() { return C::GetGenericArithmeticType(); }
		static const DataType& DataTypeLib_GetParametricTypeType() { return C::GetParametricTypeType(); }
		static const DataType& DataTypeLib_GetComponentDescriptorType() { return C::GetComponentDescriptorType(); }
		static const DataType& DataTypeLib_GetEllipsisType() { return C::GetEllipsisType(); }
		static const DataType& DataTypeLib_GetInvalidType() { return C::GetInvalidType(); }
		static Result<DataType> DataTypeLib_Substitute(const DataType& orig, const Delegate<Result<DataType>(const DataType&)>& replace) { return C::Substitute(orig, replace); }
		static Result<DataType> DataTypeLib_GetRuntimeDataType(const DataType& orig) { return C::GetRuntimeDataType(orig); }
		static const Block<const Int>& DataTypeLib_GetTupleMemberOffsets(const TupleDataType& type) { return C::GetTupleMemberOffsets(type); }
		static const Block<const Int>& DataTypeLib_GetMemberOrder(const DataType& bundleOrContainerType) { return C::GetMemberOrder(bundleOrContainerType); }
		static Result<DelegateDataType> DataTypeLib_GetDelegateType(const DataType& returnType, const Block<const DataType>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) { return C::GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub); }
		static Result<DelegateDataType> DataTypeLib_GetDelegateType_1(const Result<DataType>& returnType, const Block<const Result<DataType>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) { return C::GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub); }
		static Result<void> DataTypeLib_InvokeDelegate(const DelegateDataType& delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments) { return C::InvokeDelegate(delegateType, delegate, result, arguments); }
		static Result<DelegateBase> DataTypeLib_CreateDelegate(const DelegateDataType& delegateType, reflection::DelegateHandler&& handler) { return C::CreateDelegate(delegateType, std::forward<reflection::DelegateHandler>(handler)); }
		static const DataType& DataTypeLib_GetDelegateReturnType(const DelegateDataType& delegateType) { return C::GetDelegateReturnType(delegateType); }
		static const Block<const DataType>& DataTypeLib_GetDelegateParameterTypes(const DelegateDataType& delegateType) { return C::GetDelegateParameterTypes(delegateType); }
		static Result<EnumDataType> DataTypeLib_GetEnumType(const DataType& underlyingType, const Block<const Tuple<Id, Data>>& enumerators) { return C::GetEnumType(underlyingType, enumerators); }
		static const Block<const Tuple<Id, Data>>& DataTypeLib_GetEnumerators(const DataType& enumType) { return C::GetEnumerators(enumType); }
		static Result<void> DataTypeLib_RegisterEnumType(DataTypeImpl& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames) { return C::RegisterEnumType(type, typeId, size, isSigned, flags, enumValues, enumValueNames); }
		static Result<DataType> DataTypeLib_GetDataTypeOfInterfaces(const Block<const InterfaceReference* const>& interfaces) { return C::GetDataTypeOfInterfaces(interfaces); }
		static Result<DataType> DataTypeLib_GetReferenceType(const DataType& type, EntityBase::FLAGS refFlags) { return C::GetReferenceType(type, refFlags); }
		static Result<Tuple<DataType, const Char*>> DataTypeLib_ParseDataType(const Char* str) { return C::ParseDataType(str); }
		static Result<Tuple<Member, const Char*>> DataTypeLib_ParseMember(const Char* str) { return C::ParseMember(str); }
		static Result<Tuple<Int64, const Char*>> DataTypeLib_ParseInt(const Char* str) { return C::ParseInt(str); }
		static Result<DataType> DataTypeLib_GetDataType(const Id& typeId) { return C::GetDataType(typeId); }
		static const Id& DataTypeLib_GetNumberedId(Int number) { return C::GetNumberedId(number); }
		static Result<const MemberMap*> DataTypeLib_GetMemberMap(Block<const Int> block) { return C::GetMemberMap(std::forward<Block<const Int>>(block)); }
		static Result<const MemberMap*> DataTypeLib_GetIdentityMemberMap(Int length) { return C::GetIdentityMemberMap(length); }
		static Result<const MemberMap*> DataTypeLib_ConcatMemberMap(const MemberMap* first, const MemberMap* second) { return C::ConcatMemberMap(first, second); }
		static Result<const MemberMap*> DataTypeLib_GetMemberMap_1(const DataTypeImpl* containerType, const DataTypeImpl* runtimeType) { return C::GetMemberMap(containerType, runtimeType); }
		static ConstDataPtr DataTypeLib_GetConstant(const DataType& type, Int value) { return C::GetConstant(type, value); }
		static Result<DataType> DataTypeLib_GetDataTypeForData(const DataType& valueType) { return C::GetDataTypeForData(valueType); }
		static Result<void> DataTypeLib_ConvertToData(Data& result, const DataType& dataType, const DataType& valueType, const Generic& value) { return C::ConvertToData(result, dataType, valueType, value); }
		static Result<void> DataTypeLib_MoveFromData(const DataType& valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage) { return C::MoveFromData(valueType, value, createDefaultPointees, data, storage); }
		static Bool DataTypeLib_PrivateIsBaseOfOrSame(const DataTypeImpl* type, const DataTypeImpl* other, DataType::BASE_OF_MODE mode) { return C::PrivateIsBaseOfOrSame(type, other, mode); }
		static Result<StrongRef<TypeArguments>> DataTypeLib_CreateTypeArguments(Int cnt) { return C::CreateTypeArguments(cnt); }
		static Result<StrongRef<TypeArguments>> DataTypeLib_CreateTypeArguments_1(const Block<const Member>& args) { return C::CreateTypeArguments(args); }
		static ResultMem DataTypeLib_FinalizeTypeArguments(TypeArguments& args) { return C::FinalizeTypeArguments(args); }
		static void DataTypeLib_PrivateHandleUnreferencedType(DataTypeImpl* type) { return C::PrivateHandleUnreferencedType(type); }
		static const DataType& DataTypeLib_PrivateGetPrimaryDataTypeType() { return C::PrivateGetPrimaryDataTypeType(); }
		static void DataTypeLib_AddLeakingInstantiatedType(DataTypeImpl* type) { return C::AddLeakingInstantiatedType(type); }
		static const Block<const Member>& DataTypeLib_PrivateGetNamedTupleMembers(Binary& binary, NamedTupleMembers* mem, std::add_pointer<Int(void*)>::type constructor) { return C::PrivateGetNamedTupleMembers(binary, mem, std::forward<std::add_pointer<Int(void*)>::type>(constructor)); }
		static const Generic* DataTypeLib_PrivateGetDefault(const DataTypeImpl* type) { return C::PrivateGetDefault(type); }
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
[[deprecated]] MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetConstant(const DataType& type, Int value) -> ConstDataPtr
{
	return MTable::_instance.DataTypeLib_GetConstant(type, value);
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
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::PrivateGetNamedTupleMembers(Binary& binary, NamedTupleMembers* mem, std::add_pointer<Int(void*)>::type constructor) -> const Block<const Member>&
{
	return MTable::_instance.DataTypeLib_PrivateGetNamedTupleMembers(binary, mem, std::forward<std::add_pointer<Int(void*)>::type>(constructor));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::PrivateGetDefault(const DataTypeImpl* type) -> const Generic*
{
	return MTable::_instance.DataTypeLib_PrivateGetDefault(type);
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

