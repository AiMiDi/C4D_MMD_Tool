#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ConvexHullInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ConvexHullInterface::MTable::_instance._ConvexHullInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ConvexHullInterface::MTable::_instance._ConvexHullInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ConvexHullInterface::MTable::_instance._ConvexHullInterface_ComputeConvexHull)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "vertices\0shrink\0shrinkClamp\0resultVertices\0resultEdges\0resultFaces\0", 2709LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ConvexHullInterface::MTable::_instance._ConvexHullInterface_ComputeConvexHull_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "vertices\0shrink\0shrinkClamp\0hull\0", 149LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ConvexHullInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ConvexHullInterface("net.maxon.interface.convexhull", nullptr, &RegisterReflection_ConvexHullInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
