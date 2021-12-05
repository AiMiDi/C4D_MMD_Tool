#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_CryptoKeyInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CryptoKeyInterface::MTable::_instance._CryptoKeyInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CryptoKeyInterface::MTable::_instance._CryptoKeyInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 87381LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CryptoKeyInterface::MTable::_instance._CryptoKeyInterface_GetCryptoAlgorithm)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CryptoKeyInterface::MTable::_instance._CryptoKeyInterface_GetBlockBitSize)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CryptoKeyInterface::MTable::_instance._CryptoKeyInterface_GetKey1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CryptoKeyInterface::MTable::_instance._CryptoKeyInterface_GetKey1BitSize)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CryptoKeyInterface::MTable::_instance._CryptoKeyInterface_GetKey2)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CryptoKeyInterface::MTable::_instance._CryptoKeyInterface_GetKey2BitSize)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CryptoKeyInterface::MTable::_instance._CryptoKeyInterface_GetFlags)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CryptoKeyInterface::MTable::_instance._CryptoKeyInterface_GetCallbackFunction)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CryptoKeyInterface::MTable::_instance._CryptoKeyInterface_ToString)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CryptoKeyInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_CryptoKeyInterface("net.maxon.interface.cryptokey", nullptr, &RegisterReflection_CryptoKeyInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
