#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_DataDescriptionDatabaseInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDatabaseInterface::MTable::_instance.DataDescriptionDatabaseInterface_LoadDescription)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "category\0language\0dataType\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDatabaseInterface::MTable::_instance.DataDescriptionDatabaseInterface_LoadDescription_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "category\0language\0dataType\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDatabaseInterface::MTable::_instance.DataDescriptionDatabaseInterface_DescriptionDefinitionChanged)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "category\0language\0dataType\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDatabaseInterface::MTable::_instance.DataDescriptionDatabaseInterface_GetEffectiveEnumList)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dataEntry\0guiEntry\0stringDescription\0resolveExtensionPointsAndGui\0withStrings\0language\0repository\0filterData\0", 21845LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDatabaseInterface::MTable::_instance.DataDescriptionDatabaseInterface_GetEffectiveEnumList_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dataEntry\0guiEntry\0stringDescription\0resolveExtensionPointsAndGui\0withStrings\0language\0repository\0getDataCallback\0filterData\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDatabaseInterface::MTable::_instance.DataDescriptionDatabaseInterface_PostProcessStringDescription)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "description\0entries\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDatabaseInterface::MTable::_instance.DataDescriptionDatabaseInterface_ResolveVariableIdentifier)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "identifier\0repository\0getDataCallback\0dataEntry\0guiEntry\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(DataDescriptionDatabaseInterface::MTable::_instance.DataDescriptionDatabaseInterface_GetAndResolvePresetIdentifier)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "repository\0getDataCallback\0guiEntry\0dataEntry\0outResolveSuccess\0", 597LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDescriptionDatabaseInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_DataDescriptionDatabaseInterface("net.maxon.interface.datadescriptiondatabase", nullptr, &RegisterReflection_DataDescriptionDatabaseInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(ProcessEnumListDelegates);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(EnumVariableResolveDelegates);
#endif
}
#endif
