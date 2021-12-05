#include "customgui_texbox.h"

static CustomGuiTexBoxLib *lib_TexboxControl = nullptr;


static CustomGuiTexBoxLib *CheckCustomGuiTexBoxLib(Int32 offset)
{
	return (CustomGuiTexBoxLib*)CheckLib(CUSTOMGUI_TEXBOX, offset, (C4DLibrary**)&lib_TexboxControl);
}

#define TexboxCall(b) 			CustomGuiTexBoxLib *lib = CheckCustomGuiTexBoxLib(LIBOFFSET(CustomGuiTexBoxLib, b)); \
															if (!lib || !lib->b) return; \
															(((iTexBoxGui*)this)->*lib->b)

#define TexboxCallR(a, b) 		CustomGuiTexBoxLib *lib = CheckCustomGuiTexBoxLib(LIBOFFSET(CustomGuiTexBoxLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iTexBoxGui*)this)->*lib->b)


BaseList2D* TexBoxGui::GetLink(const BaseDocument* doc) { TexboxCallR(nullptr, GetLink)(doc); }
BaseList2D* TexBoxGui::GetLink(const BaseDocument* doc, Int32 type) { TexboxCallR(nullptr, GetLinkType)(doc, type); }
Bool TexBoxGui::SetLink(const BaseList2D* obj) { TexboxCallR(false, SetLink)(obj); }
