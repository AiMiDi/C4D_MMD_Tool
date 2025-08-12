#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_SymbolificationInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(SymbolificationInterface::MTable::_instance.SymbolificationInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SymbolificationInterface::MTable::_instance.SymbolificationInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SymbolificationInterface::MTable::_instance.SymbolificationInterface_Init)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "symbolFile\0architecture\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SymbolificationInterface::MTable::_instance.SymbolificationInterface_FindSymbol)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "addr\0file\0line\0function\0", 169LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SymbolificationInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_SymbolificationInterface("net.maxon.interface.symbolification", nullptr, &RegisterReflection_SymbolificationInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
