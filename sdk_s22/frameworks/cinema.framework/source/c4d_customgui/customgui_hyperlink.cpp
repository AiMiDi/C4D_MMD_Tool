#include "customgui_hyperlink.h"
#include "c4d_string.h"
#include "c4d_gui.h"


HyperLinkStaticLib *lib_hyperlinkstatic = nullptr;


static HyperLinkStaticLib *CheckHyperLinkLib(Int32 offset)
{
	return (HyperLinkStaticLib*)CheckLib(CUSTOMGUI_HYPER_LINK_STATIC, offset, (C4DLibrary**)&lib_hyperlinkstatic);
}

Bool HyperLinkCustomGui::SetLinkString(const maxon::String* pStrLink, const maxon::String *pStrText)
{
	HyperLinkStaticLib *lib = CheckHyperLinkLib(LIBOFFSET(HyperLinkStaticLib, SetLinkString));
	if (!lib || !lib->SetLinkString) return false;

	return (((iHyperLinkCustomGui*)this)->*lib->SetLinkString)(pStrLink, pStrText);
}

Bool HyperLinkCustomGui::GetLinkString(maxon::String* pStrLink, maxon::String *pStrText)
{
	HyperLinkStaticLib *lib = CheckHyperLinkLib(LIBOFFSET(HyperLinkStaticLib, GetLinkString));
	if (!lib || !lib->GetLinkString) return false;

	return (((iHyperLinkCustomGui*)this)->*lib->GetLinkString)(pStrLink, pStrText);
}

Bool HyperLinkCustomGui::SetLinkStringThreaded(const maxon::String* pStrLink, const maxon::String *pStrText)
{
	HyperLinkStaticLib *lib = CheckHyperLinkLib(LIBOFFSET(HyperLinkStaticLib, SetLinkStringThreaded));
	if (!lib || !lib->SetLinkStringThreaded) return false;

	return (((iHyperLinkCustomGui*)this)->*lib->SetLinkStringThreaded)(pStrLink, pStrText);
}


void HyperLinkData::SetStrings(const maxon::String* pStrLink, const maxon::String* pStrText)
{
	HyperLinkStaticLib *lib = CheckHyperLinkLib(LIBOFFSET(HyperLinkStaticLib, SetStrings));
	if (!lib || !lib->SetStrings) return;

	(((iHyperLinkData*)this)->*lib->SetStrings)(pStrLink, pStrText);
}

void HyperLinkData::GetStrings(maxon::String* pStrLink, maxon::String* pStrText)
{
	HyperLinkStaticLib *lib = CheckHyperLinkLib(LIBOFFSET(HyperLinkStaticLib, GetStrings));
	if (!lib || !lib->GetStrings) return;

	(((iHyperLinkData*)this)->*lib->GetStrings)(pStrLink, pStrText);
}

