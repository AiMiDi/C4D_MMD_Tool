#if 1
namespace maxon
{
	namespace NormalsHelper
	{
#if 0
#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
		static maxon::Result<void> RegisterReflection_NormalsHelperInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
#if 0
			maxon::reflection::GetFunctionInfo<decltype(NormalsHelperInterface::MTable::_instance.NormalsHelperInterface_CalculatePolygonNormalsSSE)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "points\0polygons\0normalized\0polygonNormals\0", 149LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NormalsHelperInterface::MTable::_instance.NormalsHelperInterface_CalculatePointNormalsAveragedSSE)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "style\0points\0polygons\0pointCount\0polygonNormals\0pointNormals\0", 2389LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NormalsHelperInterface::MTable::_instance.NormalsHelperInterface_CalculateShadingNormalsAveragedSSE)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "style\0points\0polygons\0pointCount\0polygonNormals\0shadingNormals\0", 2389LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NormalsHelperInterface::MTable::_instance.NormalsHelperInterface_CalculateShadingNormalsSSE)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "style\0points\0polygons\0pointCount\0polygonNormals\0angle\0shadingBreaks\0shadingNormals\0", 38229LL, nullptr),
#endif
			maxon::reflection::GetFunctionInfo<decltype(NormalsHelperInterface::MTable::_instance.NormalsHelperInterface_CalculatePolygonNormals)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "points\0polygons\0normalized\0polygonNormals\0", 149LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NormalsHelperInterface::MTable::_instance.NormalsHelperInterface_CalculatePolygonNormals_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "points\0polygons\0normalized\0polygonNormals\0", 149LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NormalsHelperInterface::MTable::_instance.NormalsHelperInterface_CalculatePolygonNormals_2)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "points\0polygons\0normalized\0polygonNormals\0", 149LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NormalsHelperInterface::MTable::_instance.NormalsHelperInterface_CalculatePointNormalsAveraged)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "style\0points\0polygons\0polygonNormals\0pointNormals\0", 597LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NormalsHelperInterface::MTable::_instance.NormalsHelperInterface_CalculateShadingNormalsAveraged)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "style\0points\0polygons\0polygonNormals\0shadingNormals\0", 597LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(NormalsHelperInterface::MTable::_instance.NormalsHelperInterface_CalculateShadingNormals)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "style\0points\0polygons\0polygonNormals\0angle\0shadingBreaks\0shadingNormals\0", 9557LL, nullptr),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&NormalsHelperInterface::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
		static maxon::reflection::ContainerInfo g_reflection_NormalsHelperInterface("net.maxon.geom.normalshelper", nullptr, &RegisterReflection_NormalsHelperInterface, &PRIVATE_MAXON_MODULE);
	#endif
	}
}
#endif
