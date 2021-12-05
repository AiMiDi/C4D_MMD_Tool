#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_Voronoi3DInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_Init)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "workSpace\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_CopyFrom)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "src\0resizeFlags\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_IsReadyButPendingChanges)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_IsReady)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_SetPoints)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "points\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_AddPoint)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "pointIn\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_AddPoints)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "points\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_CalcCells)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_CalcTetrahedralization)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_SetForClipping)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "clipping\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_GetCellCount)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_GetVoronoiPointPositions)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_GetInputPoints)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_GetBorderCellFlags)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_GetCellDataStructure)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_GetCellHasVolume)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_ScaleCell)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "cellIndex\0scaleValue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_ScaleAllCells)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "scaleValue\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_GetDelaunayTetrizer)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_Flush)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_SetCellFuseGroup)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "fuseIndices\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_FuseCells)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "joinList\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Voronoi3DInterface::MTable::_instance._Voronoi3DInterface_CreateInvertedVoronoiCell)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Voronoi3DInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_Voronoi3DInterface("net.maxon.interface.voronoi3d", nullptr, &RegisterReflection_Voronoi3DInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
