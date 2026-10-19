#include "customgui_linkbox.h"
#include "c4d_string.h"
#include "c4d_gui.h"

namespace cinema
{

static CustomGuiLinkBoxLib *lib_LinkBox = nullptr;

static CustomGuiLinkBoxLib *CheckGuiLinkboxLib(Int32 offset)
{
	return CheckLib<CustomGuiLinkBoxLib>(CUSTOMGUI_LINKBOX, offset, lib_LinkBox);
}

#define LinkBoxGuiCall(b) 		cinema::CustomGuiLinkBoxLib *lib = cinema::CheckGuiLinkboxLib(LIBOFFSET(cinema::CustomGuiLinkBoxLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<cinema::iLinkBoxGui*>(this)->*lib->b)

#define LinkBoxGuiCallR(a, b)	cinema::CustomGuiLinkBoxLib *lib = cinema::CheckGuiLinkboxLib(LIBOFFSET(cinema::CustomGuiLinkBoxLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<cinema::iLinkBoxGui*>(this)->*lib->b)

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

} // namespace cinema
