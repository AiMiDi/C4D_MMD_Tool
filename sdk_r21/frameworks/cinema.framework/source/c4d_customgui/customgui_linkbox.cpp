#include "customgui_linkbox.h"
#include "c4d_string.h"
#include "c4d_gui.h"

static CustomGuiLinkBoxLib *lib_LinkBox = nullptr;

static CustomGuiLinkBoxLib *CheckGuiLinkboxLib(Int32 offset)
{
	return (CustomGuiLinkBoxLib*)CheckLib(CUSTOMGUI_LINKBOX, offset, (C4DLibrary**)lib_LinkBox);
}

#define LinkBoxGuiCall(b) 		CustomGuiLinkBoxLib *lib = CheckGuiLinkboxLib(LIBOFFSET(CustomGuiLinkBoxLib, b)); \
															if (!lib || !lib->b) return; \
															(((iLinkBoxGui*)this)->*lib->b)

#define LinkBoxGuiCallR(a, b)	CustomGuiLinkBoxLib *lib = CheckGuiLinkboxLib(LIBOFFSET(CustomGuiLinkBoxLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iLinkBoxGui*)this)->*lib->b)

BaseList2D* LinkBoxGui::GetLink(const BaseDocument* doc)
{
	LinkBoxGuiCallR(nullptr, GetLink)(doc);
}

BaseList2D* LinkBoxGui::GetLink(const BaseDocument* doc, Int32 instance)
{
	LinkBoxGuiCallR(nullptr, GetLinkI)(doc, instance);
}

Bool LinkBoxGui::SetLink(const BaseList2D* obj)
{
	LinkBoxGuiCallR(false, SetLink)(obj);
}
