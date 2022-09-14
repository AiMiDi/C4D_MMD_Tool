#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_Delaunay3DInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_CopyFrom)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "src\0resizeFlags\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_Init)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "workSpace\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_CalculateDelaunayTetrahedralization)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_IsInitialized)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_AddPointsIntoTetrahedralization)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "newPointsIn\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_AddPointIntoTetrahedralization)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "newPointIn\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_GetTetrahedrons)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "arrayCount\0pointCount\0", 10LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_GetTetrahedrons_1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_GetPointsToTetConnections)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_GetPoints)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_GetPointsWrite)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_GetTetrahedronCount)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_GetPointCount)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_Reset)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_OrientDet)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "planePointA\0planePointB\0planePointC\0testPoint\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_Flush)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_FindTetIndexContainingPoint)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "point\0foundTetIndex\0onFace1\0onFace2\0", 169LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Delaunay3DInterface::MTable::_instance.Delaunay3DInterface_FindTetContainingPoint)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "point\0foundTetIndex\0", 9LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Delaunay3DInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_Delaunay3DInterface("net.maxon.interface.delaunay3d", nullptr, &RegisterReflection_Delaunay3DInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
