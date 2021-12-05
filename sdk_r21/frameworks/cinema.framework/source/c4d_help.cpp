#include "c4d_help.h"
#include "operatingsystem.h"

Bool RegisterPluginHelpDelegate(Int32 pluginId, PluginHelpDelegate delegate)
{
	// Register delegate in the help system.
	return C4DOS.Ge->RegisterPluginHelpDelegate(pluginId, delegate);
}

void OpenHelpBrowser(const maxon::String& opType, const maxon::String& baseType, const maxon::String& group, const maxon::String& property)
{
	// Open the help browser for the indicated topic.
	C4DOS.Ge->OpenHelpBrowser(opType, baseType, group, property);
}
