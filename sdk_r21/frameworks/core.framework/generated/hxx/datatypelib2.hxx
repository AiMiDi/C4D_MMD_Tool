
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
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
	const DataType& (*_DataTypeLib_GetDataTypeType) ();
	const DataType& (*_DataTypeLib_GetVoidType) ();
	const DataType& (*_DataTypeLib_GetNullptrType) ();
	const DataType& (*_DataTypeLib_GetGenericType) ();
	const DataType& (*_DataTypeLib_GetGenericArithmeticType) ();
	const DataType& (*_DataTypeLib_GetParametricTypeType) ();
	const DataType& (*_DataTypeLib_GetComponentDescriptorType) ();
	const DataType& (*_DataTypeLib_GetEllipsisType) ();
	Result<DataType> (*_DataTypeLib_Substitute) (const DataType& orig, const Delegate<Result<DataType>(const DataType&)>& replace);
	Result<DataType> (*_DataTypeLib_GetRuntimeDataType) (const DataType& orig);
	const Block<const Int>& (*_DataTypeLib_GetTupleMemberOffsets) (const TupleDataType& type);
	Result<DelegateDataType> (*_DataTypeLib_GetDelegateType) (const DataType& returnType, const Block<const DataType>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub);
	Result<DelegateDataType> (*_DataTypeLib_GetDelegateType_1) (const Result<DataType>& returnType, const Block<const Result<DataType>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub);
	Result<void> (*_DataTypeLib_InvokeDelegate) (const DelegateDataType& delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments);
	Result<DelegateBase> (*_DataTypeLib_CreateDelegate) (const DelegateDataType& delegateType, reflection::DelegateHandler&& handler);
	const DataType& (*_DataTypeLib_GetDelegateReturnType) (const DelegateDataType& delegateType);
	const Block<const DataType>& (*_DataTypeLib_GetDelegateParameterTypes) (const DelegateDataType& delegateType);
	Result<EnumDataType> (*_DataTypeLib_GetEnumType) (const DataType& underlyingType, const Block<const Tuple<Id, Data>>& enumerators);
	const Block<const Tuple<Id, Data>>& (*_DataTypeLib_GetEnumerators) (const DataType& enumType);
	Result<void> (*_DataTypeLib_RegisterEnumType) (DataTypeImpl& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames);
	Result<DataType> (*_DataTypeLib_GetDataTypeOfInterfaces) (const Block<const InterfaceReference* const>& interfaces);
	Result<DataType> (*_DataTypeLib_GetReferenceType) (const DataType& type, EntityBase::FLAGS refFlags);
	Result<Tuple<DataType, const Char*>> (*_DataTypeLib_ParseDataType) (const Char* name);
	Result<DataType> (*_DataTypeLib_GetDataType) (const Id& typeId);
	const Id& (*_DataTypeLib_GetNumberedId) (Int number);
	Result<const MemberMap*> (*_DataTypeLib_GetMemberMap) (Block<const Int> block);
	Result<const MemberMap*> (*_DataTypeLib_GetIdentityMemberMap) (Int length);
	Result<const MemberMap*> (*_DataTypeLib_ConcatMemberMap) (const MemberMap* first, const MemberMap* second);
	Result<const MemberMap*> (*_DataTypeLib_PrivateGetMemberMap) (const DataTypeImpl* containerType, const DataTypeImpl* runtimeType);
	ConstDataPtr (*_DataTypeLib_GetConstant) (const DataType& type, Int value);
	Result<DataType> (*_DataTypeLib_GetDataTypeForData) (const DataType& valueType);
	Result<void> (*_DataTypeLib_ConvertToData) (Data& result, const DataType& dataType, const DataType& valueType, const Generic& value);
	Result<void> (*_DataTypeLib_MoveFromData) (const DataType& valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage);
	Bool (*_DataTypeLib_PrivateIsBaseOfOrSame) (const DataTypeImpl* type, const DataTypeImpl* other, DataType::MEMBER_MATCH_MODE mode);
	Result<StrongRef<TypeArguments>> (*_DataTypeLib_CreateTypeArguments) (Int cnt);
	Result<StrongRef<TypeArguments>> (*_DataTypeLib_CreateTypeArguments_1) (const Block<const Member>& args);
	ResultMem (*_DataTypeLib_FinalizeTypeArguments) (TypeArguments& args);
	void (*_DataTypeLib_PrivateHandleUnreferencedType) (DataTypeImpl* type);
	const DataType& (*_DataTypeLib_PrivateGetPrimaryDataTypeType) ();
	void (*_DataTypeLib_AddLeakingInstantiatedType) (DataTypeImpl* type);
	const Block<const Member>& (*_DataTypeLib_PrivateGetNamedTupleMembers) (Binary& binary, NamedTupleMembers* mem, std::add_pointer<Int(void*)>::type constructor);
	template <typename IMPL> void Init()
	{
		_DataTypeLib_GetDataTypeType = &IMPL::_DataTypeLib_GetDataTypeType;
		_DataTypeLib_GetVoidType = &IMPL::_DataTypeLib_GetVoidType;
		_DataTypeLib_GetNullptrType = &IMPL::_DataTypeLib_GetNullptrType;
		_DataTypeLib_GetGenericType = &IMPL::_DataTypeLib_GetGenericType;
		_DataTypeLib_GetGenericArithmeticType = &IMPL::_DataTypeLib_GetGenericArithmeticType;
		_DataTypeLib_GetParametricTypeType = &IMPL::_DataTypeLib_GetParametricTypeType;
		_DataTypeLib_GetComponentDescriptorType = &IMPL::_DataTypeLib_GetComponentDescriptorType;
		_DataTypeLib_GetEllipsisType = &IMPL::_DataTypeLib_GetEllipsisType;
		_DataTypeLib_Substitute = &IMPL::_DataTypeLib_Substitute;
		_DataTypeLib_GetRuntimeDataType = &IMPL::_DataTypeLib_GetRuntimeDataType;
		_DataTypeLib_GetTupleMemberOffsets = &IMPL::_DataTypeLib_GetTupleMemberOffsets;
		_DataTypeLib_GetDelegateType = &IMPL::_DataTypeLib_GetDelegateType;
		_DataTypeLib_GetDelegateType_1 = &IMPL::_DataTypeLib_GetDelegateType_1;
		_DataTypeLib_InvokeDelegate = &IMPL::_DataTypeLib_InvokeDelegate;
		_DataTypeLib_CreateDelegate = &IMPL::_DataTypeLib_CreateDelegate;
		_DataTypeLib_GetDelegateReturnType = &IMPL::_DataTypeLib_GetDelegateReturnType;
		_DataTypeLib_GetDelegateParameterTypes = &IMPL::_DataTypeLib_GetDelegateParameterTypes;
		_DataTypeLib_GetEnumType = &IMPL::_DataTypeLib_GetEnumType;
		_DataTypeLib_GetEnumerators = &IMPL::_DataTypeLib_GetEnumerators;
		_DataTypeLib_RegisterEnumType = &IMPL::_DataTypeLib_RegisterEnumType;
		_DataTypeLib_GetDataTypeOfInterfaces = &IMPL::_DataTypeLib_GetDataTypeOfInterfaces;
		_DataTypeLib_GetReferenceType = &IMPL::_DataTypeLib_GetReferenceType;
		_DataTypeLib_ParseDataType = &IMPL::_DataTypeLib_ParseDataType;
		_DataTypeLib_GetDataType = &IMPL::_DataTypeLib_GetDataType;
		_DataTypeLib_GetNumberedId = &IMPL::_DataTypeLib_GetNumberedId;
		_DataTypeLib_GetMemberMap = &IMPL::_DataTypeLib_GetMemberMap;
		_DataTypeLib_GetIdentityMemberMap = &IMPL::_DataTypeLib_GetIdentityMemberMap;
		_DataTypeLib_ConcatMemberMap = &IMPL::_DataTypeLib_ConcatMemberMap;
		_DataTypeLib_PrivateGetMemberMap = &IMPL::_DataTypeLib_PrivateGetMemberMap;
		_DataTypeLib_GetConstant = &IMPL::_DataTypeLib_GetConstant;
		_DataTypeLib_GetDataTypeForData = &IMPL::_DataTypeLib_GetDataTypeForData;
		_DataTypeLib_ConvertToData = &IMPL::_DataTypeLib_ConvertToData;
		_DataTypeLib_MoveFromData = &IMPL::_DataTypeLib_MoveFromData;
		_DataTypeLib_PrivateIsBaseOfOrSame = &IMPL::_DataTypeLib_PrivateIsBaseOfOrSame;
		_DataTypeLib_CreateTypeArguments = &IMPL::_DataTypeLib_CreateTypeArguments;
		_DataTypeLib_CreateTypeArguments_1 = &IMPL::_DataTypeLib_CreateTypeArguments_1;
		_DataTypeLib_FinalizeTypeArguments = &IMPL::_DataTypeLib_FinalizeTypeArguments;
		_DataTypeLib_PrivateHandleUnreferencedType = &IMPL::_DataTypeLib_PrivateHandleUnreferencedType;
		_DataTypeLib_PrivateGetPrimaryDataTypeType = &IMPL::_DataTypeLib_PrivateGetPrimaryDataTypeType;
		_DataTypeLib_AddLeakingInstantiatedType = &IMPL::_DataTypeLib_AddLeakingInstantiatedType;
		_DataTypeLib_PrivateGetNamedTupleMembers = &IMPL::_DataTypeLib_PrivateGetNamedTupleMembers;
	}
};

struct DataTypeLib::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static const DataType& _DataTypeLib_GetDataTypeType() { return C::GetDataTypeType(); }
	static const DataType& _DataTypeLib_GetVoidType() { return C::GetVoidType(); }
	static const DataType& _DataTypeLib_GetNullptrType() { return C::GetNullptrType(); }
	static const DataType& _DataTypeLib_GetGenericType() { return C::GetGenericType(); }
	static const DataType& _DataTypeLib_GetGenericArithmeticType() { return C::GetGenericArithmeticType(); }
	static const DataType& _DataTypeLib_GetParametricTypeType() { return C::GetParametricTypeType(); }
	static const DataType& _DataTypeLib_GetComponentDescriptorType() { return C::GetComponentDescriptorType(); }
	static const DataType& _DataTypeLib_GetEllipsisType() { return C::GetEllipsisType(); }
	static Result<DataType> _DataTypeLib_Substitute(const DataType& orig, const Delegate<Result<DataType>(const DataType&)>& replace) { return C::Substitute(orig, replace); }
	static Result<DataType> _DataTypeLib_GetRuntimeDataType(const DataType& orig) { return C::GetRuntimeDataType(orig); }
	static const Block<const Int>& _DataTypeLib_GetTupleMemberOffsets(const TupleDataType& type) { return C::GetTupleMemberOffsets(type); }
	static Result<DelegateDataType> _DataTypeLib_GetDelegateType(const DataType& returnType, const Block<const DataType>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) { return C::GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub); }
	static Result<DelegateDataType> _DataTypeLib_GetDelegateType_1(const Result<DataType>& returnType, const Block<const Result<DataType>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) { return C::GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub); }
	static Result<void> _DataTypeLib_InvokeDelegate(const DelegateDataType& delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments) { return C::InvokeDelegate(delegateType, delegate, result, arguments); }
	static Result<DelegateBase> _DataTypeLib_CreateDelegate(const DelegateDataType& delegateType, reflection::DelegateHandler&& handler) { return C::CreateDelegate(delegateType, std::forward<reflection::DelegateHandler>(handler)); }
	static const DataType& _DataTypeLib_GetDelegateReturnType(const DelegateDataType& delegateType) { return C::GetDelegateReturnType(delegateType); }
	static const Block<const DataType>& _DataTypeLib_GetDelegateParameterTypes(const DelegateDataType& delegateType) { return C::GetDelegateParameterTypes(delegateType); }
	static Result<EnumDataType> _DataTypeLib_GetEnumType(const DataType& underlyingType, const Block<const Tuple<Id, Data>>& enumerators) { return C::GetEnumType(underlyingType, enumerators); }
	static const Block<const Tuple<Id, Data>>& _DataTypeLib_GetEnumerators(const DataType& enumType) { return C::GetEnumerators(enumType); }
	static Result<void> _DataTypeLib_RegisterEnumType(DataTypeImpl& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames) { return C::RegisterEnumType(type, typeId, size, isSigned, flags, enumValues, enumValueNames); }
	static Result<DataType> _DataTypeLib_GetDataTypeOfInterfaces(const Block<const InterfaceReference* const>& interfaces) { return C::GetDataTypeOfInterfaces(interfaces); }
	static Result<DataType> _DataTypeLib_GetReferenceType(const DataType& type, EntityBase::FLAGS refFlags) { return C::GetReferenceType(type, refFlags); }
	static Result<Tuple<DataType, const Char*>> _DataTypeLib_ParseDataType(const Char* name) { return C::ParseDataType(name); }
	static Result<DataType> _DataTypeLib_GetDataType(const Id& typeId) { return C::GetDataType(typeId); }
	static const Id& _DataTypeLib_GetNumberedId(Int number) { return C::GetNumberedId(number); }
	static Result<const MemberMap*> _DataTypeLib_GetMemberMap(Block<const Int> block) { return C::GetMemberMap(std::forward<Block<const Int>>(block)); }
	static Result<const MemberMap*> _DataTypeLib_GetIdentityMemberMap(Int length) { return C::GetIdentityMemberMap(length); }
	static Result<const MemberMap*> _DataTypeLib_ConcatMemberMap(const MemberMap* first, const MemberMap* second) { return C::ConcatMemberMap(first, second); }
	static Result<const MemberMap*> _DataTypeLib_PrivateGetMemberMap(const DataTypeImpl* containerType, const DataTypeImpl* runtimeType) { return C::PrivateGetMemberMap(containerType, runtimeType); }
	static ConstDataPtr _DataTypeLib_GetConstant(const DataType& type, Int value) { return C::GetConstant(type, value); }
	static Result<DataType> _DataTypeLib_GetDataTypeForData(const DataType& valueType) { return C::GetDataTypeForData(valueType); }
	static Result<void> _DataTypeLib_ConvertToData(Data& result, const DataType& dataType, const DataType& valueType, const Generic& value) { return C::ConvertToData(result, dataType, valueType, value); }
	static Result<void> _DataTypeLib_MoveFromData(const DataType& valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage) { return C::MoveFromData(valueType, value, createDefaultPointees, data, storage); }
	static Bool _DataTypeLib_PrivateIsBaseOfOrSame(const DataTypeImpl* type, const DataTypeImpl* other, DataType::MEMBER_MATCH_MODE mode) { return C::PrivateIsBaseOfOrSame(type, other, mode); }
	static Result<StrongRef<TypeArguments>> _DataTypeLib_CreateTypeArguments(Int cnt) { return C::CreateTypeArguments(cnt); }
	static Result<StrongRef<TypeArguments>> _DataTypeLib_CreateTypeArguments_1(const Block<const Member>& args) { return C::CreateTypeArguments(args); }
	static ResultMem _DataTypeLib_FinalizeTypeArguments(TypeArguments& args) { return C::FinalizeTypeArguments(args); }
	static void _DataTypeLib_PrivateHandleUnreferencedType(DataTypeImpl* type) { return C::PrivateHandleUnreferencedType(type); }
	static const DataType& _DataTypeLib_PrivateGetPrimaryDataTypeType() { return C::PrivateGetPrimaryDataTypeType(); }
	static void _DataTypeLib_AddLeakingInstantiatedType(DataTypeImpl* type) { return C::AddLeakingInstantiatedType(type); }
	static const Block<const Member>& _DataTypeLib_PrivateGetNamedTupleMembers(Binary& binary, NamedTupleMembers* mem, std::add_pointer<Int(void*)>::type constructor) { return C::PrivateGetNamedTupleMembers(binary, mem, std::forward<std::add_pointer<Int(void*)>::type>(constructor)); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDataTypeType() -> const DataType&
{
	return MTable::_instance._DataTypeLib_GetDataTypeType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetVoidType() -> const DataType&
{
	return MTable::_instance._DataTypeLib_GetVoidType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetNullptrType() -> const DataType&
{
	return MTable::_instance._DataTypeLib_GetNullptrType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetGenericType() -> const DataType&
{
	return MTable::_instance._DataTypeLib_GetGenericType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetGenericArithmeticType() -> const DataType&
{
	return MTable::_instance._DataTypeLib_GetGenericArithmeticType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetParametricTypeType() -> const DataType&
{
	return MTable::_instance._DataTypeLib_GetParametricTypeType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetComponentDescriptorType() -> const DataType&
{
	return MTable::_instance._DataTypeLib_GetComponentDescriptorType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetEllipsisType() -> const DataType&
{
	return MTable::_instance._DataTypeLib_GetEllipsisType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::Substitute(const DataType& orig, const Delegate<Result<DataType>(const DataType&)>& replace) -> Result<DataType>
{
	return MTable::_instance._DataTypeLib_Substitute(orig, replace);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetRuntimeDataType(const DataType& orig) -> Result<DataType>
{
	return MTable::_instance._DataTypeLib_GetRuntimeDataType(orig);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetTupleMemberOffsets(const TupleDataType& type) -> const Block<const Int>&
{
	return MTable::_instance._DataTypeLib_GetTupleMemberOffsets(type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDelegateType(const DataType& returnType, const Block<const DataType>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) -> Result<DelegateDataType>
{
	return MTable::_instance._DataTypeLib_GetDelegateType(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDelegateType(const Result<DataType>& returnType, const Block<const Result<DataType>>& paramTypes, reflection::DelegateFunctionPointer function, void* handlerStub) -> Result<DelegateDataType>
{
	return MTable::_instance._DataTypeLib_GetDelegateType_1(returnType, paramTypes, std::forward<reflection::DelegateFunctionPointer>(function), handlerStub);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::InvokeDelegate(const DelegateDataType& delegateType, const DelegateBase& delegate, void* result, const Block<reflection::Argument>& arguments) -> Result<void>
{
	return MTable::_instance._DataTypeLib_InvokeDelegate(delegateType, delegate, result, arguments);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::CreateDelegate(const DelegateDataType& delegateType, reflection::DelegateHandler&& handler) -> Result<DelegateBase>
{
	return MTable::_instance._DataTypeLib_CreateDelegate(delegateType, std::forward<reflection::DelegateHandler>(handler));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDelegateReturnType(const DelegateDataType& delegateType) -> const DataType&
{
	return MTable::_instance._DataTypeLib_GetDelegateReturnType(delegateType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDelegateParameterTypes(const DelegateDataType& delegateType) -> const Block<const DataType>&
{
	return MTable::_instance._DataTypeLib_GetDelegateParameterTypes(delegateType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetEnumType(const DataType& underlyingType, const Block<const Tuple<Id, Data>>& enumerators) -> Result<EnumDataType>
{
	return MTable::_instance._DataTypeLib_GetEnumType(underlyingType, enumerators);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetEnumerators(const DataType& enumType) -> const Block<const Tuple<Id, Data>>&
{
	return MTable::_instance._DataTypeLib_GetEnumerators(enumType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::RegisterEnumType(DataTypeImpl& type, const Id& typeId, Int size, Bool isSigned, Bool flags, const UInt64* enumValues, const Char* enumValueNames) -> Result<void>
{
	return MTable::_instance._DataTypeLib_RegisterEnumType(type, typeId, size, isSigned, flags, enumValues, enumValueNames);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDataTypeOfInterfaces(const Block<const InterfaceReference* const>& interfaces) -> Result<DataType>
{
	return MTable::_instance._DataTypeLib_GetDataTypeOfInterfaces(interfaces);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetReferenceType(const DataType& type, EntityBase::FLAGS refFlags) -> Result<DataType>
{
	return MTable::_instance._DataTypeLib_GetReferenceType(type, refFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::ParseDataType(const Char* name) -> Result<Tuple<DataType, const Char*>>
{
	return MTable::_instance._DataTypeLib_ParseDataType(name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDataType(const Id& typeId) -> Result<DataType>
{
	return MTable::_instance._DataTypeLib_GetDataType(typeId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetNumberedId(Int number) -> const Id&
{
	return MTable::_instance._DataTypeLib_GetNumberedId(number);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetMemberMap(Block<const Int> block) -> Result<const MemberMap*>
{
	return MTable::_instance._DataTypeLib_GetMemberMap(std::forward<Block<const Int>>(block));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetIdentityMemberMap(Int length) -> Result<const MemberMap*>
{
	return MTable::_instance._DataTypeLib_GetIdentityMemberMap(length);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::ConcatMemberMap(const MemberMap* first, const MemberMap* second) -> Result<const MemberMap*>
{
	return MTable::_instance._DataTypeLib_ConcatMemberMap(first, second);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::PrivateGetMemberMap(const DataTypeImpl* containerType, const DataTypeImpl* runtimeType) -> Result<const MemberMap*>
{
	return MTable::_instance._DataTypeLib_PrivateGetMemberMap(containerType, runtimeType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetConstant(const DataType& type, Int value) -> ConstDataPtr
{
	return MTable::_instance._DataTypeLib_GetConstant(type, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::GetDataTypeForData(const DataType& valueType) -> Result<DataType>
{
	return MTable::_instance._DataTypeLib_GetDataTypeForData(valueType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::ConvertToData(Data& result, const DataType& dataType, const DataType& valueType, const Generic& value) -> Result<void>
{
	return MTable::_instance._DataTypeLib_ConvertToData(result, dataType, valueType, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::MoveFromData(const DataType& valueType, Generic& value, Bool createDefaultPointees, Data& data, BaseArray<Data>& storage) -> Result<void>
{
	return MTable::_instance._DataTypeLib_MoveFromData(valueType, value, createDefaultPointees, data, storage);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::PrivateIsBaseOfOrSame(const DataTypeImpl* type, const DataTypeImpl* other, DataType::MEMBER_MATCH_MODE mode) -> Bool
{
	return MTable::_instance._DataTypeLib_PrivateIsBaseOfOrSame(type, other, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::CreateTypeArguments(Int cnt) -> Result<StrongRef<TypeArguments>>
{
	return MTable::_instance._DataTypeLib_CreateTypeArguments(cnt);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::CreateTypeArguments(const Block<const Member>& args) -> Result<StrongRef<TypeArguments>>
{
	return MTable::_instance._DataTypeLib_CreateTypeArguments_1(args);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::FinalizeTypeArguments(TypeArguments& args) -> ResultMem
{
	return MTable::_instance._DataTypeLib_FinalizeTypeArguments(args);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::PrivateHandleUnreferencedType(DataTypeImpl* type) -> void
{
	return MTable::_instance._DataTypeLib_PrivateHandleUnreferencedType(type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::PrivateGetPrimaryDataTypeType() -> const DataType&
{
	return MTable::_instance._DataTypeLib_PrivateGetPrimaryDataTypeType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::AddLeakingInstantiatedType(DataTypeImpl* type) -> void
{
	return MTable::_instance._DataTypeLib_AddLeakingInstantiatedType(type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto DataTypeLib::PrivateGetNamedTupleMembers(Binary& binary, NamedTupleMembers* mem, std::add_pointer<Int(void*)>::type constructor) -> const Block<const Member>&
{
	return MTable::_instance._DataTypeLib_PrivateGetNamedTupleMembers(binary, mem, std::forward<std::add_pointer<Int(void*)>::type>(constructor));
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

