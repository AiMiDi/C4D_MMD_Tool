#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ExactPredicates2DInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ExactPredicates2DInterface::MTable::_instance._ExactPredicates2DInterface_Orient)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pointA\0pointB\0pointC\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ExactPredicates2DInterface::MTable::_instance._ExactPredicates2DInterface_InCircle)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pointA\0pointB\0pointC\0testPoint\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ExactPredicates2DInterface::MTable::_instance._ExactPredicates2DInterface_InTriangle)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pointA\0pointB\0pointC\0testPoint\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ExactPredicates2DInterface::MTable::_instance._ExactPredicates2DInterface_InSector)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "center\0rayA\0rayB\0testPoint\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ExactPredicates2DInterface::MTable::_instance._ExactPredicates2DInterface_OutlineSelfIntersectionTest)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outline\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ExactPredicates2DInterface::MTable::_instance._ExactPredicates2DInterface_OutlinesIntersectionTest)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outline1\0outline2\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ExactPredicates2DInterface::MTable::_instance._ExactPredicates2DInterface_OutlinesIntersectionTest_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "outlines\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ExactPredicates2DInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ExactPredicates2DInterface("net.maxon.interface.exactpredicates2d", nullptr, &RegisterReflection_ExactPredicates2DInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
