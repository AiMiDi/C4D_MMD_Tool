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
			maxon::reflection::GetFunctionInfo<decltype(Member::MTable::_instance.Member_GetEnclosingContainer)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Member::MTable::_instance.Member_GetKind)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Member::MTable::_instance.Member_GetSimpleName)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Member::MTable::_instance.Member_GetId)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Member::MTable::_instance.Member_ToString)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "fs\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Member::MTable::_instance.Member_GetMembers)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "members\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Member::MTable::_instance.Member_Find)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "memberId\0", 1LL, nullptr),
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
			maxon::reflection::GetFunctionInfo<decltype(Container::MTable::_instance.Container_GetClasses)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Container::MTable::_instance.Container_FindClass)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "name\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Container::MTable::_instance.Container_GetFunctions)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Container::MTable::_instance.Container_FindFunction)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "name\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Container::MTable::_instance.Container_FindFunctions)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "name\0result\0", 9LL, nullptr),
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
			maxon::reflection::GetFunctionInfo<decltype(Package::MTable::_instance.Package_GetPackages)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Package::MTable::_instance.Package_FindPackage)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "name\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Package::MTable::_instance.Package_GetGlobalPackage)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
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
			maxon::reflection::GetFunctionInfo<decltype(Class::MTable::_instance.Class_GetInterface)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Class::MTable::_instance.Class_GetNonvirtualInterface)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Class::MTable::_instance.Class_GetBaseClasses)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Class::MTable::_instance.Class_GetStaticInterface)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
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
			maxon::reflection::GetFunctionInfo<decltype(Function::MTable::_instance.Function_Invoke)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "result\0arguments\0", 6LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Function::MTable::_instance.Function_GetReturnType)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Function::MTable::_instance.Function_GetParameterTypes)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Function::MTable::_instance.Function_GetParameters)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Function::MTable::_instance.Function_IsPure)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Function::MTable::_instance.Function_GetAddress)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Function::MTable::_instance.Function_PrivateFindMethod)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "vi\0offset\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Function::MTable::_instance.Function_FindAll)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "memberId\0result\0", 9LL, nullptr),
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
