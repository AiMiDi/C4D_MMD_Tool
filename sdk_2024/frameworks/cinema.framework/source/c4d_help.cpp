#include "c4d_help.h"
#include "operatingsystem.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

Bool RegisterPluginHelpDelegate(Int32 pluginId, PluginHelpDelegate delegate)
{
	// Register delegate in the help system.
	return C4DOS_Ge->RegisterPluginHelpDelegate(pluginId, delegate);
}

void OpenHelpBrowser(const maxon::String& opType, const maxon::String& baseType, const maxon::String& group, const maxon::String& property)
{
	// Open the help browser for the indicated topic.
	C4DOS_Ge->OpenHelpBrowser(opType, baseType, group, property);
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
