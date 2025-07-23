#include "c4d_gui.h"
#include "customgui_fontchooser.h"

namespace cinema
{

static FontchooserLib *lib_FontControl = nullptr;


static FontchooserLib *CheckFontChooser(Int32 offset)
{
	return CheckLib<FontchooserLib>(CUSTOMGUI_FONTCHOOSER, offset, lib_FontControl);
}

#define FontCall(b) 			cinema::FontchooserLib *lib = cinema::CheckFontChooser(LIBOFFSET(cinema::FontchooserLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<cinema::iFontData*>(this)->*lib->b)

#define FontCallR(a, b) 		cinema::FontchooserLib *lib = cinema::CheckFontChooser(LIBOFFSET(cinema::FontchooserLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<cinema::iFontData*>(this)->*lib->b)

#define FontCallRC(a, b) 		cinema::FontchooserLib *lib = cinema::CheckFontChooser(LIBOFFSET(cinema::FontchooserLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<const cinema::iFontData*>(this)->*lib->b)

#define FontGuiCall(b) 		cinema::FontchooserLib *lib = cinema::CheckFontChooser(LIBOFFSET(cinema::FontchooserLib, b)); \
															if (!lib || !lib->b) return; \
															(reinterpret_cast<cinema::iFontChooserGUI*>(this)->*lib->b)

#define FontGuiCallR(a, b) cinema::FontchooserLib *lib = cinema::CheckFontChooser(LIBOFFSET(cinema::FontchooserLib, b)); \
															if (!lib || !lib->b) return a; \
															return (reinterpret_cast<cinema::iFontChooserGUI*>(this)->*lib->b)


BaseContainer FontchooserCustomGui::GetFont() { FontGuiCallR(BaseContainer(), GetFont)(); }
void FontchooserCustomGui::SetFont(BaseContainer* bc) { FontGuiCall(SetFont)(bc); }

BaseContainer FontData::GetFont() const { FontCallRC(BaseContainer(), GetFontData)(); }
void FontData::SetFont(const BaseContainer *bc) { FontCall(SetFontData)(bc); }


Bool OpenFontChooserPopup(const BaseContainer& font, maxon::Delegate<void(FONTCHOOSER_POPUP_RESULT, const BaseContainer&)> callback, Bool useReducedFontList, Int32 screenPositionX, Int32 screenPositionY)
{
	FontchooserLib *lib = CheckFontChooser(LIBOFFSET(FontchooserLib, OpenFontChooserPopup));
	if (!lib || !lib->OpenFontChooserPopup)
		return false;

	return lib->OpenFontChooserPopup(font, std::move(callback), useReducedFontList, screenPositionX, screenPositionY);
}

} // namespace cinema
