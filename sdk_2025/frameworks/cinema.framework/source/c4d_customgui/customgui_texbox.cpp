#include "customgui_texbox.h"

namespace cinema
{

static CustomGuiTexBoxLib *lib_TexboxControl = nullptr;


static CustomGuiTexBoxLib *CheckCustomGuiTexBoxLib(Int32 offset)
{
	return CheckLib<CustomGuiTexBoxLib>(CUSTOMGUI_TEXBOX, offset, lib_TexboxControl);
}

#define TexboxCall(b) 			cinema::CustomGuiTexBoxLib *lib = cinema::CheckCustomGuiTexBoxLib(LIBOFFSET(cinema::CustomGuiTexBoxLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<cinema::iTexBoxGui*>(this)->*lib->b)

#define TexboxCallR(a, b) 		cinema::CustomGuiTexBoxLib *lib = cinema::CheckCustomGuiTexBoxLib(LIBOFFSET(cinema::CustomGuiTexBoxLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<cinema::iTexBoxGui*>(this)->*lib->b)


BaseList2D* TexBoxGui::GetLink(const BaseDocument* doc) { TexboxCallR(nullptr, GetLink)(doc); }
BaseList2D* TexBoxGui::GetLink(const BaseDocument* doc, Int32 type) { TexboxCallR(nullptr, GetLinkType)(doc, type); }
Bool TexBoxGui::SetLink(const BaseList2D* obj) { TexboxCallR(false, SetLink)(obj); }

} // namespace cinema
