#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_Delaunay3DInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_CopyFrom)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "src\0resizeFlags\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_Init)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "workSpace\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_CalculateDelaunayTetrahedralization)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_IsInitialized)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_AddPointsIntoTetrahedralization)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "newPointsIn\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_AddPointIntoTetrahedralization)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "newPointIn\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_GetTetrahedrons)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "arrayCount\0pointCount\0", 10LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_GetTetrahedrons_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_GetPointsToTetConnections)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_GetPoints)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_GetPointsWrite)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_GetTetrahedronCount)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_GetPointCount)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_Reset)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_OrientDet)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "planePointA\0planePointB\0planePointC\0testPoint\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_Flush)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_FindTetIndexContainingPoint)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "point\0foundTetIndex\0onFace1\0onFace2\0", 169LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Delaunay3DInterface::MTable::_instance._Delaunay3DInterface_FindTetContainingPoint)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "point\0foundTetIndex\0", 9LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Delaunay3DInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_Delaunay3DInterface("net.maxon.interface.delaunay3d", nullptr, &RegisterReflection_Delaunay3DInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
