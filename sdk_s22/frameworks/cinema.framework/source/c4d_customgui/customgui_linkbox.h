/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_LINKBOX_H__
#define CUSTOMGUI_LINKBOX_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"

/// Link box custom GUI ID.
#define CUSTOMGUI_LINKBOX	1009415

/// Only the inline content is shown if this is set for a @em LINK description element.
#define CUSTOMGUI_INLINE	300001044

/// @addtogroup LINKBOX_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
enum
{
	LINKBOX_HIDE_ICON	= 10000,			///< ::Bool Hide the icon.
	LINKBOX_LAYERMODE	= 10001,			///< ::Bool Layer mode.
	LINKBOX_NODE_MODE	= 10002				///< ::Bool Private - Node mode.
};
/// @}

/// @addtogroup LINKBOX_ACCEPT_MESSAGE
/// @ingroup group_containerid
/// @{
#define LINKBOX_ACCEPT_MESSAGE_TYPE				1			///< ::Int32 The type of the item dragged in the link box.
#define LINKBOX_ACCEPT_MESSAGE_ELEMENT		2			///< @c void* A pointer (@ref BaseList2D*) to the object
#define LINKBOX_ACCEPT_MESSAGE_ACCEPT			3			///< @c void* A pointer to a ::Bool. Set this value to @formatConstant{true} to accept the object.
#define LINKBOX_ACCEPT_MESSAGE_CONTROL_ID	4			///< ::Int32 The ID of the control that sent the message.
/// @}

//----------------------------------------------------------------------------------------
/// Link box custom GUI (@ref CUSTOMGUI_LINKBOX) for the BaseLink data.\n
/// Here are the settings: @enumerateEnum{LINKBOX_CUSTOMGUISETTINGS}\n
/// The following is sent with the @ref MSG_DESCRIPTION_CHECKDRAGANDDROP parent message: (Normally packed into a DescriptionCheckDragAndDrop structure.)\n
/// @enumerateEnum{LINKBOX_ACCEPT_MESSAGE}
//----------------------------------------------------------------------------------------
class LinkBoxGui : public BaseCustomGui<CUSTOMGUI_LINKBOX>
{
		LinkBoxGui();
		~LinkBoxGui();

	public:
		//----------------------------------------------------------------------------------------
		/// Evaluates the link in the specified document.
		/// @param[in] doc								The document to evaluate the link in. @callerOwnsPointed{document}
		/// @return												The linked object, or @formatConstant{nullptr} if the link is broken. @theOwnsPointed{document,object}
		//----------------------------------------------------------------------------------------
		BaseList2D* GetLink(const BaseDocument* doc);

		//----------------------------------------------------------------------------------------
		/// Sets the link to point to @formatParam{obj}.
		/// @param[in] obj								The object to link to. @callerOwnsPointed{object}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool SetLink(const BaseList2D* obj);

		//----------------------------------------------------------------------------------------
		/// Evaluates the link in @formatParam{doc}, returning @formatConstant{nullptr} if the linked object is not an instance of @formatParam{instance}.
		/// @param[in] doc								The document to evaluate the link in. @callerOwnsPointed{document}
		/// @param[in] instance						The type to check.
		/// @return												The linked object, or @formatConstant{nullptr} if the link is broken or of the wrong type. @theOwnsPointed{document,object}
		//----------------------------------------------------------------------------------------
		BaseList2D* GetLink(const BaseDocument* doc, Int32 instance);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_LINKBOX_DEF_
	class iLinkBoxGui
	{
	};
#else
	class iLinkBoxGui;
#endif

struct CustomGuiLinkBoxLib : public BaseCustomGuiLib
{
	BaseList2D*	(iLinkBoxGui::*GetLink)(const BaseDocument* doc);
	Bool				(iLinkBoxGui::*SetLink)(const BaseList2D* obj);
	BaseList2D*	(iLinkBoxGui::*GetLinkI)(const BaseDocument* doc, Int32 instance);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_LINKBOX_H__
