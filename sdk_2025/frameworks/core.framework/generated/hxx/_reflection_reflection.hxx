#if 1
namespace maxon
{
	namespace reflection
	{
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
		static maxon::Result<void> RegisterReflection_Proxy(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
			maxon::reflection::GetFunctionInfo<decltype(Proxy::MTable::_instance.Proxy_AddComponents)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "cls\0classProxy\0interfaces\0includeBaseInterfaces\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Proxy::MTable::_instance.Proxy_SetHandler)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0component\0handler\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Proxy::MTable::_instance.Proxy_SetHandler_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "cls\0component\0handler\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Proxy::MTable::_instance.Proxy_GetClass)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "interfaces\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Proxy::MTable::_instance.Proxy_Create)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "cls\0handler\0", 0LL, nullptr),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Proxy::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
		static maxon::reflection::ContainerInfo g_reflection_Proxy("net.maxon.reflection.interface.proxy", nullptr, &RegisterReflection_Proxy, &PRIVATE_MAXON_MODULE);
	#endif
	}
}
#endif
