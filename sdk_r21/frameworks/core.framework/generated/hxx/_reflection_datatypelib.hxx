#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_DataTypeLib(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetDataTypeType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetVoidType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetNullptrType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetGenericType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetGenericArithmeticType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetParametricTypeType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetComponentDescriptorType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetEllipsisType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_Substitute)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "orig\0replace\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetRuntimeDataType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "orig\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetTupleMemberOffsets)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetDelegateType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "returnType\0paramTypes\0function\0handlerStub\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetDelegateType_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "returnType\0paramTypes\0function\0handlerStub\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_InvokeDelegate)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "delegateType\0delegate\0result\0arguments\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_CreateDelegate)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "delegateType\0handler\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetDelegateReturnType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "delegateType\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetDelegateParameterTypes)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "delegateType\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetEnumType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "underlyingType\0enumerators\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetEnumerators)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "enumType\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_RegisterEnumType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0typeId\0size\0isSigned\0flags\0enumValues\0enumValueNames\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetDataTypeOfInterfaces)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "interfaces\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetReferenceType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0refFlags\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_ParseDataType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "name\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetDataType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "typeId\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetNumberedId)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "number\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetMemberMap)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "block\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetIdentityMemberMap)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "length\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_ConcatMemberMap)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "first\0second\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_PrivateGetMemberMap)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "containerType\0runtimeType\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetConstant)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0value\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_GetDataTypeForData)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "valueType\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_ConvertToData)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "result\0dataType\0valueType\0value\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_MoveFromData)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "valueType\0value\0createDefaultPointees\0data\0storage\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_PrivateIsBaseOfOrSame)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0other\0mode\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_CreateTypeArguments)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "cnt\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_CreateTypeArguments_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "args\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_FinalizeTypeArguments)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "args\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_PrivateHandleUnreferencedType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_PrivateGetPrimaryDataTypeType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_AddLeakingInstantiatedType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataTypeLib::MTable::_instance._DataTypeLib_PrivateGetNamedTupleMembers)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "binary\0mem\0constructor\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataTypeLib::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_DataTypeLib("net.maxon.interface.datatypelib", nullptr, &RegisterReflection_DataTypeLib, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
