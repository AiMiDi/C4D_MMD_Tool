/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_DESCPROPERTY_H__
#define CUSTOMGUI_DESCPROPERTY_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "c4d_gui.h"
#include "lib_description.h"

class AtomArray;

/// Description property custom GUI ID.
#define CUSTOMGUI_DESCRIPTIONPROPERTY			1000485

/// @addtogroup DESCRIPTIONPROPERTY_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define DESCRIPTIONPROPERTY_SHOWBUTTON					10005			///< ::Bool Show special button.
#define DESCRIPTIONPROPERTY_INDENT							10006			///< ::Bool Indent text.
#define DESCRIPTIONPROPERTY_BPDOT								10007			///< ::Bool Use @BP3D dot.
#define DESCRIPTIONPROPERTY_PORTSTATE						10008			///< ::Int32 0: not connected, 1: connected, 2: connected but muted, 4: error, 8: warning, 16: limitation.

#define DESCRIPTIONPROPERTY_PARENTMSG						20000			///< @markPrivate ::DescID
/// @}

#define SETTING_AUTOIDENT			(1)			///< ::Bool Indent text if animation symbol is visible.
#define SETTING_HEIGHT				(2)			///< ::Bool Height.

/// @addtogroup BFM_ACTION_DP
/// @ingroup group_enumeration
/// @{
#define BFM_ACTION_DP_MENUCLICK		'menu'			///< ::Bool Right mouse button.
#define BFM_ACTION_DP_ADDSELECT		'adds'			///< ::Bool Shift.
#define BFM_ACTION_DP_SUBSELECT		'subs'			///< ::Bool Control.
#define BFM_ACTION_DP_FOCUS				'dpfc'			///< ::DescID Focus.
#define BFM_ACTION_DP_ANIMCLICK		'anim'			///< ::Bool Animation click.
#define BFM_ACTION_DP_BUTTONCLICK	'butt'			///< ::Bool Double left mouse button click.
#define BFM_ACTION_QUAL						'qual'			///< ::Int32 Qualifier.
static const Int32 BFM_ACTION_KEYFRAMESTATE		= 440000179;	// Int32 <-> DESCPROP
static const Int32 BFM_ACTION_SECTION					= 300001081;
static const Int32 BFM_ACTION_SECTION_NODE		= 1;
static const Int32 BFM_ACTION_SECTION_ANIM		= 2;
static const Int32 BFM_ACTION_SECTION_OPENER	= 3;
static const Int32 BFM_ACTION_SECTION_TEXT		= 4;
static const Int32 ICON_PORTCONNECTOR_CONNECTED = 200001006;
static const Int32 ICON_PORTCONNECTOR_UNCONNECTED = 200001013;
static const Int32 ICON_PORTCONNECTOR_CONNECTED_HIGHLIGHTED = 1040139;
static const Int32 ICON_PORTCONNECTOR_UNCONNECTED_HIGHLIGHTED = 1040140;
static const Int32 ICON_PORTCONNECTOR_CONNECTEDMUTED = 200001038;
static const Int32 ICON_PORTCONNECTOR_CONNECTEDMUTED_HIGHLIGHTED = 200001039;

/// @}

/// @addtogroup DESCPROP
/// @ingroup group_enumeration
/// @{
enum class DESCPROP
{
	NONE							= 0,
	SEQUENCE					= (1 << 0),			///< Has a sequence on the current frame.
	KEY								= (1 << 1),			///< Has a key on the current frame.
	AUTOKEY_ACTIVE		= (1 << 2),			///< Autokey active icon.
	AUTOKEY_INACTIVE	= (1 << 3),			///< Autokey inactive icon.
	NOANIM						= (1 << 4),			///< No animation.
	ENABLED						= (1 << 5),			///< Enabled.
	ANIM_NOT_ALLOWED	= (1 << 6),			///< Animation not allowed.
	GLOBAL_PARAMETER	= (1 << 7),			///< Global parameter.
	KEY_CHANGED				= (1 << 9),			///< Has a key on the current frame but the value changed.
	HIDDEN						= (1 << 10),		///< Hidden description property.
	LOCKED						= (1 << 11),		///< Locked description property.
	KEY_MUTED					= (1 << 12),		///< Current key frame is muted.
	PORTIN						= (1 << 13),		///< Port used by XPresso as inport.
	PORTIN_CONNECTED	= (1 << 14),		///< Port used by XPresso as connected inport.
	PORTOUT						= (1 << 15),		///< Port used by XPresso as outport.
	PORTOUT_CONNECTED	= (1 << 16),		///< Port used by XPresso as connected outport.
	CHANGED						= (1 << 17),		///< The value changed.
	NOTOVERRIDE				= (1 << 18),		///< Parameter is not overridden. @since R17.032
	AUTOTAKE					= (1 << 19),		///< Description is enabled for Auto Take. @since R17.032
	INVERTENABLING		= (1 << 20),		///< Description enabling defined by override from Take has to be inverted. @since R17.032
	NODE							= (1 << 21)			///< Private - node parameter.
} MAXON_ENUM_FLAGS(DESCPROP);
/// @}

/// @see GeUserArea::HandleMouseDrag and ::DRAGTYPE_DESCID
struct DescPropertyDragData
{
	AtomArray *arr;			///< Current selection.
	DescID did;					///< Current description ID.
};

//----------------------------------------------------------------------------------------
/// Description property custom GUI (@ref CUSTOMGUI_DESCRIPTIONPROPERTY).\n
/// Here are the settings: @enumerateEnum{DESCRIPTIONPROPERTY_CUSTOMGUISETTINGS}\n
/// The following custom parent message IDs are sent: @enumerateEnum{BFM_ACTION_DP}
//----------------------------------------------------------------------------------------
class DescriptionPropertyCustomGui : public BaseCustomGui<CUSTOMGUI_DESCRIPTIONPROPERTY>
{
		DescriptionPropertyCustomGui();
		~DescriptionPropertyCustomGui();

	public:

		//----------------------------------------------------------------------------------------
		/// Sets the description ID to display.\n
		/// @note The name of the element must have as many parts, separated by ~!~, as @formatParam{id}.@link DescID::GetDepth GetDepth()@endlink. These are displayed separated by dots.
		/// @param[in] id									The description ID.
		//----------------------------------------------------------------------------------------
		void SetDescID(const DescID &id);

		//----------------------------------------------------------------------------------------
		/// Sets the display flags.
		/// @param[in] flags							A combination of these flags: @enumerateEnum{DESCPROP}
		//----------------------------------------------------------------------------------------
		void SetState(DESCPROP flags);

		//----------------------------------------------------------------------------------------
		/// Gets the display flags.
		/// @return												A combination of these flags: @enumerateEnum{DESCPROP}
		//----------------------------------------------------------------------------------------
		DESCPROP GetState();

		//----------------------------------------------------------------------------------------
		/// Gets the number of parts. (For instance "Foo . Bar" has 2 parts.)
		/// @return												The number of parts.
		//----------------------------------------------------------------------------------------
		Int32 GetPartCount();

		//----------------------------------------------------------------------------------------
		/// Gets information for each part.
		/// @param[in] part								The part index: @em 0 <= @formatParam{part} < GetPartCount()
		/// @param[in] str								The part title.
		/// @param[in] id									The part ID.
		/// @param[in] onoff							The selection state.
		//----------------------------------------------------------------------------------------
		void GetPartInfo(Int32 part, maxon::String &str, DescID &id, Bool &onoff);

		//----------------------------------------------------------------------------------------
		/// Sets the selection state.
		/// @param[in] id									The description ID to set the state for.
		/// @param[in] onoff							The new selection state.
		//----------------------------------------------------------------------------------------
		void SetSelection(const DescID &id, Bool onoff);

		//----------------------------------------------------------------------------------------
		/// Sets the description property settings.
		/// @param[in] settings						The new settings: @enumerateEnum{DESCRIPTIONPROPERTY_CUSTOMGUISETTINGS}
		//----------------------------------------------------------------------------------------
		void ChangeSettings(const BaseContainer &settings);
};

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#ifndef _INTERNAL_DEF_
	class iDescriptionPropertyCustomGui : public iBaseCustomGui
	{
		iDescriptionPropertyCustomGui(const BaseContainer &settings, CUSTOMGUIPLUGIN *plugin) : iBaseCustomGui(settings, plugin) { }
	};
#else
	class iDescriptionPropertyCustomGui;
#endif

struct CustomGuiDescriptionPropertyLib : public BaseCustomGuiLib
{
	void	   (iDescriptionPropertyCustomGui::*SetState				)(DESCPROP flags);
	DESCPROP (iDescriptionPropertyCustomGui::*GetState				)();
	void	   (iDescriptionPropertyCustomGui::*SetDescID				)(const DescID &id);
	Int32	   (iDescriptionPropertyCustomGui::*GetPartCount		)();
	void	   (iDescriptionPropertyCustomGui::*GetPartInfo			)(Int32 part, maxon::String &str, DescID &id, Bool &onoff);
	void	   (iDescriptionPropertyCustomGui::*SetSelection		)(const DescID &id, Bool onoff);
	void	   (iDescriptionPropertyCustomGui::*ChangeSettings	)(const BaseContainer &settings);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_DESCPROPERTY_H__
