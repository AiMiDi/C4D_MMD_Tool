#include "c4d_customguidata.h"
#include "c4d_customguiplugin.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

CustomProperty* CustomGuiData::GetProperties()
{
	return nullptr;
}

Int32 CustomGuiData::GetResourceDataType(Int32*& table)
{
	table = nullptr;
	return 0;
}

CUSTOMGUIPLUGIN* CustomGuiData::GetPlugin()
{
	return FindCustomGuiPlugin(GetId());
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
