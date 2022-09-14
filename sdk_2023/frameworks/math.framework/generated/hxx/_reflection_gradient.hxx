#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_GradientInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_AllocAlphaGradient)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_GetAlphaGradient)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_GetKnotCount)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_InsertKnot)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "knot\0keepId\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_RemoveKnot)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "index\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_GetKnot)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "index\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_SetKnot)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "index\0k\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_ConvertToAlphaGradient)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_SortKnots)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_InvertKnots)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_DoubleKnots)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_DistributeKnots)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_Flush)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_SetIsAlphaGradient)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "alphaGradient\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_IsAlphaGradient)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_Compare)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "arg2\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_GetHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientInterface::MTable::_instance.GradientInterface_InitRender)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "transformColorDelegate\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&GradientInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_GradientInterface("net.maxon.interface.gradient", nullptr, &RegisterReflection_GradientInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_GradientRenderDataInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(GradientRenderDataInterface::MTable::_instance.GradientRenderDataInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientRenderDataInterface::MTable::_instance.GradientRenderDataInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientRenderDataInterface::MTable::_instance.GradientRenderDataInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientRenderDataInterface::MTable::_instance.GradientRenderDataInterface_CalcGradientPixel)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "pos\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientRenderDataInterface::MTable::_instance.GradientRenderDataInterface_GetKnotCount)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientRenderDataInterface::MTable::_instance.GradientRenderDataInterface_GetKnot)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "index\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientRenderDataInterface::MTable::_instance.GradientRenderDataInterface_GetKnots)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientRenderDataInterface::MTable::_instance.GradientRenderDataInterface_Compare)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "arg2\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(GradientRenderDataInterface::MTable::_instance.GradientRenderDataInterface_GetHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&GradientRenderDataInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_GradientRenderDataInterface("net.maxon.interface.gradientrenderdata", nullptr, &RegisterReflection_GradientRenderDataInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
