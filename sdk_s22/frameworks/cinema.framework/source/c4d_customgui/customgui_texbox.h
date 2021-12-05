/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_TEXBOX_H__
#define CUSTOMGUI_TEXBOX_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"

/// Shader link custom GUI ID.
#define CUSTOMGUI_TEXBOX	1001066

/// @addtogroup TEXBOX_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define TEXBOX_POPUP_ONLY								'tbpo'			///< ::Bool Popup only.
#define TEXBOX_ALPHAMODE								'talp'			///< ::Bool Alpha mode.
/// @}

//----------------------------------------------------------------------------------------
/// Shader link custom GUI (@ref CUSTOMGUI_TEXBOX).\n
/// Here are the settings: @enumerateEnum{TEXBOX_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class TexBoxGui : public BaseCustomGui<CUSTOMGUI_TEXBOX>
{
		TexBoxGui();
		~TexBoxGui();

	public:
		//----------------------------------------------------------------------------------------
		/// Evaluates the link in the specified document.
		/// @param[in] doc								The document to evaluate the link in. @callerOwnsPointed{document}
		/// @return												The linked object, or @formatConstant{nullptr} if the link is broken. @theOwnsPointed{document,object}
		//----------------------------------------------------------------------------------------
		BaseList2D* GetLink(const BaseDocument* doc);

		//----------------------------------------------------------------------------------------
		/// Evaluates the link in the specified document. If @formatParam{type} is specified, @formatConstant{nullptr} is returned if the object is not of this type.
		/// @param[in] doc								The document to evaluate the link in. @callerOwnsPointed{document}
		/// @param[in] type								Set this to a node type to only return the link if it is of this type.
		/// @return												The linked object, or @formatConstant{nullptr} if the link is broken or of the wrong type. @theOwnsPointed{document,object}
		//----------------------------------------------------------------------------------------
		BaseList2D* GetLink(const BaseDocument* doc, Int32 type);

		//----------------------------------------------------------------------------------------
		/// Sets the link to point to @formatParam{obj}.
		/// @param[in] obj								The new goal. @callerOwnsPointed{object}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetLink(const BaseList2D* obj);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_TEXBOX_DEF_
	class iTexBoxGui
	{
	};
#else
	class iTexBoxGui;
#endif

struct CustomGuiTexBoxLib : public BaseCustomGuiLib
{
	BaseList2D*	(iTexBoxGui::*GetLink)(const BaseDocument* doc);
	BaseList2D*	(iTexBoxGui::*GetLinkType)(const BaseDocument* doc, Int32 type);
	Bool				(iTexBoxGui::*SetLink)(const BaseList2D* obj);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_TEXBOX_H__
