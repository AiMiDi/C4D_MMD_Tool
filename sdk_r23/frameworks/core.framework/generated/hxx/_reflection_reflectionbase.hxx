#if 1
namespace maxon
{
	namespace reflection
	{
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
		static maxon::Result<void> RegisterReflection_Member(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Member::MTable::_instance._Member_GetEnclosingContainer)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Member::MTable::_instance._Member_GetKind)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Member::MTable::_instance._Member_GetSimpleName)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Member::MTable::_instance._Member_GetId)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Member::MTable::_instance._Member_ToString)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "fs\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Member::MTable::_instance._Member_GetMembers)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "members\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Member::MTable::_instance._Member_Find)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "memberId\0", 1LL, nullptr),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Member::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
		static maxon::reflection::ContainerInfo g_reflection_Member("net.maxon.reflection.interface.member", nullptr, &RegisterReflection_Member, &PRIVATE_MAXON_MODULE);
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
		static maxon::Result<void> RegisterReflection_Container(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Container::MTable::_instance._Container_GetClasses)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Container::MTable::_instance._Container_FindClass)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "name\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Container::MTable::_instance._Container_GetFunctions)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Container::MTable::_instance._Container_FindFunction)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "name\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Container::MTable::_instance._Container_FindFunctions)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "name\0result\0", 9LL, nullptr),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Container::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
		static maxon::reflection::ContainerInfo g_reflection_Container("net.maxon.reflection.interface.container", nullptr, &RegisterReflection_Container, &PRIVATE_MAXON_MODULE);
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
		static maxon::Result<void> RegisterReflection_Package(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Package::MTable::_instance._Package_GetPackages)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Package::MTable::_instance._Package_FindPackage)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "name\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Package::MTable::_instance._Package_GetGlobalPackage)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Package::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
		static maxon::reflection::ContainerInfo g_reflection_Package("net.maxon.reflection.interface.package", nullptr, &RegisterReflection_Package, &PRIVATE_MAXON_MODULE);
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
		static maxon::Result<void> RegisterReflection_Class(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Class::MTable::_instance._Class_GetInterface)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Class::MTable::_instance._Class_GetNonvirtualInterface)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Class::MTable::_instance._Class_GetBaseClasses)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Class::MTable::_instance._Class_GetStaticInterface)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Class::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
		static maxon::reflection::ContainerInfo g_reflection_Class("net.maxon.reflection.interface.class", nullptr, &RegisterReflection_Class, &PRIVATE_MAXON_MODULE);
	#endif
	#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
		static maxon::Result<void> RegisterReflection_Function(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
		{
			maxon::reflection::FunctionInfo functions[] =
			{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Function::MTable::_instance._Function_Invoke)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "result\0arguments\0", 6LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Function::MTable::_instance._Function_GetReturnType)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Function::MTable::_instance._Function_GetParameterTypes)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Function::MTable::_instance._Function_GetParameters)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Function::MTable::_instance._Function_IsPure)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Function::MTable::_instance._Function_GetAddress)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Function::MTable::_instance._Function_PrivateFindMethod)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "vi\0offset\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Function::MTable::_instance._Function_FindAll)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "memberId\0result\0", 9LL, nullptr),
			};
			return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Function::_interface), maxon::ToBlock(functions));
		}
	#endif
	#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
		static maxon::reflection::ContainerInfo g_reflection_Function("net.maxon.reflection.interface.function", nullptr, &RegisterReflection_Function, &PRIVATE_MAXON_MODULE);
	#endif
	}
}
#endif
