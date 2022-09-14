#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_CryptoKeyInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(CryptoKeyInterface::MTable::_instance.CryptoKeyInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CryptoKeyInterface::MTable::_instance.CryptoKeyInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0cryptoAlgorithm\0blockSizeBits\0key1\0key1BitSize\0key2\0key2BitSize\0flags\0callback\0", 87381LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CryptoKeyInterface::MTable::_instance.CryptoKeyInterface_GetCryptoAlgorithm)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CryptoKeyInterface::MTable::_instance.CryptoKeyInterface_GetBlockBitSize)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CryptoKeyInterface::MTable::_instance.CryptoKeyInterface_GetKey1)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CryptoKeyInterface::MTable::_instance.CryptoKeyInterface_GetKey1BitSize)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CryptoKeyInterface::MTable::_instance.CryptoKeyInterface_GetKey2)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CryptoKeyInterface::MTable::_instance.CryptoKeyInterface_GetKey2BitSize)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CryptoKeyInterface::MTable::_instance.CryptoKeyInterface_GetFlags)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CryptoKeyInterface::MTable::_instance.CryptoKeyInterface_GetCallbackFunction)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CryptoKeyInterface::MTable::_instance.CryptoKeyInterface_ToString)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "formatStatement\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CryptoKeyInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_CryptoKeyInterface("net.maxon.interface.cryptokey", nullptr, &RegisterReflection_CryptoKeyInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
