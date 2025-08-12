#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_SplineMapperInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetPoint)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "positionX\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetRange)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "min\0max\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_SetRange)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "min\0max\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_AdaptRange)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "min\0max\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetTension)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_SetTension)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "tension\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetKnotCount)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetKnot)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "knotIndex\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_SetKnot)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "knotIndex\0knot\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_IsEqual)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "other\0equality\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_InsertKnot)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "knotIndex\0knot\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_InsertKnot_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "x\0y\0flags\0adaptTangents\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_DeleteKnot)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "knotIndex\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_DeleteAllKnots)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetKnots)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_GetKnotsRW)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_SortKnots)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_ClampPosition)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "position\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SplineMapperInterface::MTable::_instance.SplineMapperInterface_DescribeIO)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "stream\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SplineMapperInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_SplineMapperInterface("net.maxon.interface.splinemapper", nullptr, &RegisterReflection_SplineMapperInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
