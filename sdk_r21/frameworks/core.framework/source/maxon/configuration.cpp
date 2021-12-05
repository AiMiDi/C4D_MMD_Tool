#define MAXON_DEPENDENCY_ENABLE // so that MAXON_INITIALIZATION can be used, and that this file takes part in the dependency analysis

#include "maxon/configuration.h"
#include "maxon/string.h"

namespace maxon
{

const Int	 g_maxConfigInitCnt = 256;
ConfigInit g_configInit[g_maxConfigInitCnt];
Int				 g_configInitCnt = 0;

Bool ConfigurationRegisterBool(const Char* key, Bool& value, Bool defaultValue, CONFIGURATION_CATEGORY category, const Char* helpText)
{
	if (g_configInitCnt < g_maxConfigInitCnt)
	{
		g_configInit[g_configInitCnt].key = key;
		g_configInit[g_configInitCnt].category = category;
		g_configInit[g_configInitCnt].helpText = helpText;
		g_configInit[g_configInitCnt].bValue = &value;
		g_configInit[g_configInitCnt].type = ConfigInit::CONFIGURATION_DATATYPE_BOOL;
		g_configInitCnt++;
	}
	else
	{
		value = defaultValue;
	}
	return defaultValue;
}

Int ConfigurationRegisterInt(const Char* key, Int& value, Int defaultValue, Int minValue, Int maxValue, CONFIGURATION_CATEGORY category, const Char* helpText)
{
	if (g_configInitCnt < g_maxConfigInitCnt)
	{
		g_configInit[g_configInitCnt].key = key;
		g_configInit[g_configInitCnt].category = category;
		g_configInit[g_configInitCnt].helpText = helpText;
		g_configInit[g_configInitCnt].iValue = &value;
		g_configInit[g_configInitCnt].type = ConfigInit::CONFIGURATION_DATATYPE_INT;
		g_configInit[g_configInitCnt].minValue = minValue;
		g_configInit[g_configInitCnt].maxValue = maxValue;
		g_configInitCnt++;
	}
	else
	{
		value = defaultValue;
	}
	return defaultValue;
}

Float ConfigurationRegisterFloat(const Char* key, Float& value, Float defaultValue, Float minValue, Float maxValue, CONFIGURATION_CATEGORY category, const Char* helpText)
{
	if (g_configInitCnt < g_maxConfigInitCnt)
	{
		g_configInit[g_configInitCnt].key = key;
		g_configInit[g_configInitCnt].category = category;
		g_configInit[g_configInitCnt].helpText = helpText;
		g_configInit[g_configInitCnt].fValue = &value;
		g_configInit[g_configInitCnt].type = ConfigInit::CONFIGURATION_DATATYPE_FLOAT;
		g_configInit[g_configInitCnt].fMinValue = minValue;
		g_configInit[g_configInitCnt].fMaxValue = maxValue;
		g_configInitCnt++;
	}
	else
	{
		value = defaultValue;
	}
	return defaultValue;
}

Bool ConfigurationRegisterString(const Char* key, String& value, const Char* defaultValue, CONFIGURATION_CATEGORY category, const Char* helpText)
{
	if (g_configInitCnt < g_maxConfigInitCnt)
	{
		g_configInit[g_configInitCnt].key = key;
		g_configInit[g_configInitCnt].category = category;
		g_configInit[g_configInitCnt].helpText = helpText;
		g_configInit[g_configInitCnt].sValue = &value;
		g_configInit[g_configInitCnt].type = ConfigInit::CONFIGURATION_DATATYPE_STRING_C;
		g_configInit[g_configInitCnt].defaultValueC = defaultValue;
		g_configInitCnt++;
	}
	return true;	// string can only be initialized later when components are registered
}

Bool ConfigurationRegisterString(const Char* key, String& value, const wchar_t* defaultValue, CONFIGURATION_CATEGORY category, const Char* helpText)
{
	if (g_configInitCnt < g_maxConfigInitCnt)
	{
		g_configInit[g_configInitCnt].key = key;
		g_configInit[g_configInitCnt].category = category;
		g_configInit[g_configInitCnt].helpText = helpText;
		g_configInit[g_configInitCnt].sValue = &value;
		g_configInit[g_configInitCnt].type = ConfigInit::CONFIGURATION_DATATYPE_STRING;
		g_configInit[g_configInitCnt].defaultValue = defaultValue;
		g_configInitCnt++;
	}
	return true;	// string can only be initialized later when components are registered
}

static Result<void> InitializeConfiguration()
{
	for (const ModuleInfo* info = g_maxon.GetModules(); info; info = info->GetNext())
	{
		if (info->IsCore())
			return OK;
	}

	for (Int i = 0; i < g_configInitCnt; i++)
		System::ConfigurationRegister(g_configInit[i]);

	return OK;
}

static void FreeConfiguration()
{
	for (Int i = 0; i < g_configInitCnt; i++)
	{
		switch (g_configInit[i].type)
		{
			case ConfigInit::CONFIGURATION_DATATYPE_STRING:
			case ConfigInit::CONFIGURATION_DATATYPE_STRING_C:
			{
				g_configInit[i].sValue->~String();
				break;
			}
			default:
				break;
		}
	}
}

MAXON_INITIALIZATION(InitializeConfiguration, FreeConfiguration);
MAXON_DEPENDENCY_REGISTER(configuration)

} // namespace maxon
