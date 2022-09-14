#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_BigIntegerInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Zero)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_One)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_MinusOne)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Set)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "c\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Set_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "c\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Set_2)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "i\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Set_3)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "u\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Set_4)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "i\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Set_5)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "u\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Set_6)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "i\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Set_7)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "u\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_SetRandom)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "bitCount\0provider\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_SetRandomPrime)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "bitCount\0certainty\0provider\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Set_8)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "mem\0littleEndian\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Set_9)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "str\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_SetHex)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "str\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_IsEven)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_IsOdd)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_IsOne)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_IsZero)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_IsNegative)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_IsPowerOfTwo)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_IsProbablyPrime)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "certainty\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Sign)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GetHighestNonSignBit)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GetLowestSetBit)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GetLowestClearedBit)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_IsBitSet)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "bit\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GetLowestBits8U)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GetLowestBits8S)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GetLowestBits16U)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GetLowestBits16S)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GetLowestBits32U)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GetLowestBits32S)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GetLowestBits64U)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GetLowestBits64S)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GetDataCopy)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "littleEndian\0data\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Add)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Sub)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Inc)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Dec)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Mul)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Div)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Mod)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_DivMod)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0r\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Pow)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_PowMod)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0mod\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GreatestCommonDivisor)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "b\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_MultiplicativeInverse)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "m\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_LeftShift)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "s\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_RightShift)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "s\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Negate)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_SetBit)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "bit\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_ClearBit)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "bit\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_ToggleBit)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "bit\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_Compare)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "arg2\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GetHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_GetUniqueHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_ToString)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "formatStatement\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(BigIntegerInterface::MTable::_instance.BigIntegerInterface_DescribeIO)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "stream\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&BigIntegerInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_BigIntegerInterface("net.maxon.interface.biginteger", nullptr, &RegisterReflection_BigIntegerInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
