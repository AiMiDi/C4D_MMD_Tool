/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_TEXTUREMANAGER_H__
#define CUSTOMGUI_TEXTUREMANAGER_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"

/// Texure manager custom GUI ID.
#define CUSTOMGUI_TEXTUREMANAGER	200000247

//----------------------------------------------------------------------------------------
/// Custom GUI (@ref CUSTOMGUI_TEXTUREMANAGER) for managing paint textures.
//----------------------------------------------------------------------------------------
class TextureManagerCustomGui : public BaseCustomGui<CUSTOMGUI_TEXTUREMANAGER>
{
		TextureManagerCustomGui();
		~TextureManagerCustomGui();

	public:

		//----------------------------------------------------------------------------------------
		/// Sets the paint texture.
		/// @param[in] tex								The paint texure to set. @callerOwnsPointed{texture}
		//----------------------------------------------------------------------------------------
		void SetTexture(PaintTexture *tex);

		//----------------------------------------------------------------------------------------
		/// Sets the paint texture as multipass bitmap.
		/// @param[in] bmp								The paint texure to set passed as multipass bitmap. @callerOwnsPointed{multipass bitmap}
		//----------------------------------------------------------------------------------------
		void SetTexture(MultipassBitmap *bmp);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class iTextureManagerCustomGui
	{
	};
#else
	class iTextureManagerCustomGui;
#endif

struct TextureManagerLib : public BaseCustomGuiLib
{
	void	(iTextureManagerCustomGui::*SetTexture1)(PaintTexture *tex);
	void	(iTextureManagerCustomGui::*SetTexture2)(MultipassBitmap *bmp);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_TEXTUREMANAGER_H__
