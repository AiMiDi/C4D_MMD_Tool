#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_SymbolificationInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SymbolificationInterface::MTable::_instance._SymbolificationInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SymbolificationInterface::MTable::_instance._SymbolificationInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SymbolificationInterface::MTable::_instance._SymbolificationInterface_Init)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SymbolificationInterface::MTable::_instance._SymbolificationInterface_FindSymbol)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 676LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SymbolificationInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_SymbolificationInterface("net.maxon.interface.symbolification", nullptr, &RegisterReflection_SymbolificationInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
