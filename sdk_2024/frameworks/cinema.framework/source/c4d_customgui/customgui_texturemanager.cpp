#include "customgui_texturemanager.h"
#include "c4d_string.h"
#include "c4d_gui.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

static TextureManagerLib *lib_texturemanager = nullptr;


static TextureManagerLib *CheckTextureManagerLib(Int32 offset)
{
	return CheckLib<TextureManagerLib>(CUSTOMGUI_TEXTUREMANAGER, offset, lib_texturemanager);
}


void TextureManagerCustomGui::SetTexture(PaintTexture *tex)
{
	TextureManagerLib *lib = CheckTextureManagerLib(LIBOFFSET(TextureManagerLib, SetTexture1));
	if (!lib || !lib->SetTexture1) return;

	(reinterpret_cast<iTextureManagerCustomGui*>(this)->*lib->SetTexture1)(tex);
}

void TextureManagerCustomGui::SetTexture(MultipassBitmap *bmp)
{
	TextureManagerLib *lib = CheckTextureManagerLib(LIBOFFSET(TextureManagerLib, SetTexture2));
	if (!lib || !lib->SetTexture2) return;

	(reinterpret_cast<iTextureManagerCustomGui*>(this)->*lib->SetTexture2)(bmp);
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
