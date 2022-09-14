#if 1
namespace maxon
{
#ifndef _HAS_CPP20_COMPARISONS
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_DataTypeLib(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetDataTypeType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetVoidType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetNullptrType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetGenericType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetGenericArithmeticType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetParametricTypeType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetComponentDescriptorType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetEllipsisType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetInvalidType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_Substitute)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "orig\0replace\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetRuntimeDataType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "orig\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetTupleMemberOffsets)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetMemberOrder)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "bundleOrContainerType\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetDelegateType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "returnType\0paramTypes\0function\0handlerStub\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetDelegateType_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "returnType\0paramTypes\0function\0handlerStub\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_InvokeDelegate)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "delegateType\0delegate\0result\0arguments\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_CreateDelegate)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "delegateType\0handler\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetDelegateReturnType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "delegateType\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetDelegateParameterTypes)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "delegateType\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetEnumType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "underlyingType\0enumerators\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetEnumerators)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "enumType\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_RegisterEnumType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0typeId\0size\0isSigned\0flags\0enumValues\0enumValueNames\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetDataTypeOfInterfaces)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "interfaces\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetReferenceType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0refFlags\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_ParseDataType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_ParseMember)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_ParseInt)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetDataType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "typeId\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetNumberedId)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "number\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetMemberMap)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "block\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetIdentityMemberMap)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "length\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_ConcatMemberMap)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "first\0second\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetMemberMap_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "containerType\0runtimeType\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_GetDataTypeForData)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "valueType\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_ConvertToData)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "result\0dataType\0valueType\0value\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_MoveFromData)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "valueType\0value\0createDefaultPointees\0data\0storage\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_PrivateIsBaseOfOrSame)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0other\0mode\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_CreateTypeArguments)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "cnt\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_CreateTypeArguments_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "args\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_FinalizeTypeArguments)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "args\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_PrivateHandleUnreferencedType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_PrivateGetPrimaryDataTypeType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_AddLeakingInstantiatedType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "type\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataTypeLib::MTable::_instance.DataTypeLib_PrivateGetNamedTupleMembers)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "binary\0mem\0constructor\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataTypeLib::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_DataTypeLib("net.maxon.interface.datatypelib", nullptr, &RegisterReflection_DataTypeLib, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
