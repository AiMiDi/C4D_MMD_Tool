#if 1
namespace maxon
{
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#else
#endif
#ifdef MAXON_COMPILER_BUG_CONST_TYPE_ALIAS
#else
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ArrayFactory(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ArrayFactory::MTable::_instance.ArrayFactory_NewBaseArray)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "elementType\0src\0move\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ArrayFactory::MTable::_instance.ArrayFactory_NewBaseArrayFromContainerType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "containerType\0src\0move\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ArrayFactory::MTable::_instance.ArrayFactory_NewBlockArray)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "elementType\0src\0move\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ArrayFactory::MTable::_instance.ArrayFactory_NewPagedArray)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "elementType\0defaultValue\0useRefCountForDefault\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ArrayFactory::MTable::_instance.ArrayFactory_NewPagedArrayFromContainerType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "containerType\0defaultValue\0useRefCountForDefault\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ArrayFactory::MTable::_instance.ArrayFactory_Slice)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "base\0start\0end\0cycle\0defaultValue\0useRefCountForDefault\0", 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ArrayFactory::MTable::_instance.ArrayFactory_NewSingleValueArray)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "value\0count\0containerType\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ArrayFactory::MTable::_instance.ArrayFactory_ExtractMember)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "base\0offset\0containerType\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ArrayFactory::MTable::_instance.ArrayFactory_Reinterpret)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "base\0containerType\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ArrayFactory::MTable::_instance.ArrayFactory_PrivateNewPagedArrayFromBase)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "base\0defaultValue\0useRefCountForDefault\0", 21LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ArrayFactory::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ArrayFactory("net.maxon.interface.arrayfactory", nullptr, &RegisterReflection_ArrayFactory, &PRIVATE_MAXON_MODULE);
#endif
#ifndef CPP_853_HACK
#else
#endif
#ifdef CPP_853_HACK
#else
#endif
#ifdef CPP_853_HACK
#else
#endif
}
#endif
