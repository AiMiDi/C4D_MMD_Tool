#include "customgui_texturemanager.h"
#include "c4d_string.h"
#include "c4d_gui.h"


static TextureManagerLib *lib_texturemanager = nullptr;


static TextureManagerLib *CheckTextureManagerLib(Int32 offset)
{
	return (TextureManagerLib*)CheckLib(CUSTOMGUI_TEXTUREMANAGER, offset, (C4DLibrary**)&lib_texturemanager);
}


void TextureManagerCustomGui::SetTexture(PaintTexture *tex)
{
	TextureManagerLib *lib = CheckTextureManagerLib(LIBOFFSET(TextureManagerLib, SetTexture1));
	if (!lib || !lib->SetTexture1) return;

	(((iTextureManagerCustomGui*)this)->*lib->SetTexture1)(tex);
}

void TextureManagerCustomGui::SetTexture(MultipassBitmap *bmp)
{
	TextureManagerLib *lib = CheckTextureManagerLib(LIBOFFSET(TextureManagerLib, SetTexture2));
	if (!lib || !lib->SetTexture2) return;

	(((iTextureManagerCustomGui*)this)->*lib->SetTexture2)(bmp);
}
