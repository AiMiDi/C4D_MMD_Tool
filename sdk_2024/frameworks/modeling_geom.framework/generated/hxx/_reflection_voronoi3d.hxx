#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_Voronoi3DInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_Init)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "workSpace\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_CopyFrom)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "src\0resizeFlags\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_IsReadyButPendingChanges)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_IsReady)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_SetPoints)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "points\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_AddPoint)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "pointIn\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_AddPoints)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "points\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_CalcCells)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_CalcTetrahedralization)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_SetForClipping)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "clipping\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_GetCellCount)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_GetVoronoiPointPositions)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_GetInputPoints)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_GetBorderCellFlags)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_GetCellDataStructure)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_GetCellHasVolume)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_ScaleCell)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "cellIndex\0scaleValue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_ScaleAllCells)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "scaleValue\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_GetDelaunayTetrizer)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_Flush)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_SetCellFuseGroup)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "fuseIndices\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_FuseCells)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "joinList\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Voronoi3DInterface::MTable::_instance.Voronoi3DInterface_CreateInvertedVoronoiCell)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Voronoi3DInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_Voronoi3DInterface("net.maxon.interface.voronoi3d", nullptr, &RegisterReflection_Voronoi3DInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
