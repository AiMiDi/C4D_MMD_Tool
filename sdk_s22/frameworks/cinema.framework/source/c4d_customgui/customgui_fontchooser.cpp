#include "c4d_gui.h"
#include "customgui_fontchooser.h"

static FontchooserLib *lib_FontControl = nullptr;


static FontchooserLib *CheckFontChooser(Int32 offset)
{
	return (FontchooserLib*)CheckLib(CUSTOMGUI_FONTCHOOSER, offset, (C4DLibrary**)&lib_FontControl);
}

#define FontCall(b) 			FontchooserLib *lib = CheckFontChooser(LIBOFFSET(FontchooserLib, b)); \
															if (!lib || !lib->b) return; \
															(((iFontData*)this)->*lib->b)

#define FontCallR(a, b) 		FontchooserLib *lib = CheckFontChooser(LIBOFFSET(FontchooserLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iFontData*)this)->*lib->b)

#define FontGuiCall(b) 		FontchooserLib *lib = CheckFontChooser(LIBOFFSET(FontchooserLib, b)); \
															if (!lib || !lib->b) return; \
															(((iFontChooserGUI*)this)->*lib->b)

#define FontGuiCallR(a, b) FontchooserLib *lib = CheckFontChooser(LIBOFFSET(FontchooserLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iFontChooserGUI*)this)->*lib->b)


BaseContainer FontchooserCustomGui::GetFont() { FontGuiCallR(BaseContainer(), GetFont)(); }
void FontchooserCustomGui::SetFont(BaseContainer* bc) { FontGuiCall(SetFont)(bc); }

BaseContainer FontData::GetFont() const { FontCallR(BaseContainer(), GetFontData)(); }
void FontData::SetFont(BaseContainer *bc) { FontCall(SetFontData)(bc); }
