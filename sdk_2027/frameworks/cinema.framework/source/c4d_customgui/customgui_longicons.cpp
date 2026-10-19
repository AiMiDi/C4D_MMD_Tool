#include "customgui_longicons.h"
#include "c4d_gui.h"

namespace cinema
{

static LongIconsLib* g_longiconslib = nullptr;

static LongIconsLib* CheckLongIconsLib(Int32 offset)
{
	return CheckLib<LongIconsLib>(CUSTOMGUI_LONGICONS, offset, g_longiconslib);
}

void LongIconsCustomGui::AddMenuItem(BaseContainer& settings, Int32 id, const String& name, Int32 iconId, const String& help, Bool hasSubmenu)
{
	LongIconsLib* lib = CheckLongIconsLib(LIBOFFSET(LongIconsLib, AddMenuItem));
	if (!lib || !lib->AddMenuItem)
		return;

	lib->AddMenuItem(settings, id, name, iconId, help, hasSubmenu);
}

void LongIconsCustomGui::AddPopupMenuItem(BaseContainer& popup, Int32 id, const String& name, Int32 iconId)
{
	LongIconsLib* lib = CheckLongIconsLib(LIBOFFSET(LongIconsLib, AddPopupMenuItem));
	if (!lib || !lib->AddPopupMenuItem)
		return;

	lib->AddPopupMenuItem(popup, id, name, iconId);
}

Bool LongIconsCustomGui::HandlePopup(const BaseContainer& menu, DescriptionPopup* popup,
	GeDialog* dialog, Int32 actionID)
{
	LongIconsLib* lib = CheckLongIconsLib(LIBOFFSET(LongIconsLib, HandlePopup));
	if (!lib || !lib->HandlePopup)
		return false;

	return lib->HandlePopup(menu, popup, dialog, actionID);
}

} // namespace cinema