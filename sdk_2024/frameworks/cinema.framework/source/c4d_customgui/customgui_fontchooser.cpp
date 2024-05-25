#include "c4d_gui.h"
#include "customgui_fontchooser.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

static FontchooserLib *lib_FontControl = nullptr;


static FontchooserLib *CheckFontChooser(Int32 offset)
{
	return CheckLib<FontchooserLib>(CUSTOMGUI_FONTCHOOSER, offset, lib_FontControl);
}

#define FontCall(b) 			FontchooserLib *lib = CheckFontChooser(LIBOFFSET(FontchooserLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<iFontData*>(this)->*lib->b)

#define FontCallR(a, b) 		FontchooserLib *lib = CheckFontChooser(LIBOFFSET(FontchooserLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<iFontData*>(this)->*lib->b)

#define FontCallRC(a, b) 		FontchooserLib *lib = CheckFontChooser(LIBOFFSET(FontchooserLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<const iFontData*>(this)->*lib->b)

#define FontGuiCall(b) 		FontchooserLib *lib = CheckFontChooser(LIBOFFSET(FontchooserLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<iFontChooserGUI*>(this)->*lib->b)

#define FontGuiCallR(a, b) FontchooserLib *lib = CheckFontChooser(LIBOFFSET(FontchooserLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<iFontChooserGUI*>(this)->*lib->b)


BaseContainer FontchooserCustomGui::GetFont() { FontGuiCallR(BaseContainer(), GetFont)(); }
void FontchooserCustomGui::SetFont(BaseContainer* bc) { FontGuiCall(SetFont)(bc); }

BaseContainer FontData::GetFont() const { FontCallRC(BaseContainer(), GetFontData)(); }
void FontData::SetFont(const BaseContainer *bc) { FontCall(SetFontData)(bc); }

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
