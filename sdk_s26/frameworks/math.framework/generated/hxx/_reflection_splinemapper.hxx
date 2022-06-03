#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_SplineMapperInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_Alloc_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetPoint)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "positionX\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetRange)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "min\0max\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_SetRange)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "min\0max\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_AdaptRange)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "min\0max\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetTension)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_SetTension)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "tension\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetKnotCount)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetKnot)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "knotIndex\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_SetKnot)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "knotIndex\0knot\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_IsEqual)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "other\0equality\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetHashCode)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_InsertKnot)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "knotIndex\0knot\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_InsertKnot_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "x\0y\0flags\0adaptTangents\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_DeleteKnot)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "knotIndex\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_DeleteAllKnots)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetKnots)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetKnotsRW)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_SortKnots)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_ClampPosition)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "position\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_DescribeIO)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "stream\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SplineMapperInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_SplineMapperInterface("net.maxon.interface.splinemapper", nullptr, &RegisterReflection_SplineMapperInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
