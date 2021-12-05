#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_BigIntegerInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Alloc_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Zero)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_One)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_MinusOne)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Set)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "c\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Set_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "c\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Set_2)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "i\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Set_3)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "u\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Set_4)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "i\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Set_5)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "u\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Set_6)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "i\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Set_7)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "u\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_SetRandom)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "bitCount\0provider\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_SetRandomPrime)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "bitCount\0certainty\0provider\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Set_8)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "mem\0littleEndian\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Set_9)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "str\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_SetHex)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "str\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_IsEven)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_IsOdd)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_IsOne)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_IsZero)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_IsNegative)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_IsPowerOfTwo)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_IsProbablyPrime)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "certainty\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Sign)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_GetHighestNonSignBit)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_GetLowestSetBit)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_GetLowestClearedBit)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_IsBitSet)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "bit\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_GetLowestBits8U)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_GetLowestBits8S)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_GetLowestBits16U)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_GetLowestBits16S)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_GetLowestBits32U)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_GetLowestBits32S)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_GetLowestBits64U)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_GetLowestBits64S)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_GetDataCopy)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "littleEndian\0data\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Add)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Sub)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Inc)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Dec)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Mul)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Div)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Mod)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_DivMod)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0r\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Pow)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_PowMod)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0mod\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_GreatestCommonDivisor)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_MultiplicativeInverse)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "m\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_LeftShift)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "s\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_RightShift)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "s\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Negate)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_SetBit)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "bit\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_ClearBit)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "bit\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_ToggleBit)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "bit\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_Compare)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "arg2\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_GetHashCode)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_ToString)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "formatStatement\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(BigIntegerInterface::MTable::_instance._BigIntegerInterface_DescribeIO)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "stream\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&BigIntegerInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_BigIntegerInterface("net.maxon.interface.biginteger", nullptr, &RegisterReflection_BigIntegerInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
