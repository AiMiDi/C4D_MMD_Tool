/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_ACTIVEOBJECTMANAGER_H__
#define LIB_ACTIVEOBJECTMANAGER_H__

#include "c4d_library.h"
#include "c4d_string.h"
#include "lib_description.h"

class AtomArray;

//----------------------------------------------------------------------------------------
/// Parent message to allow the ActiveObject Manager to set a new active object.
//----------------------------------------------------------------------------------------
#define ID_AOM_SETOBJECT_PARENTMESSAGE 200001012

/// @addtogroup group_activeobjectmanagerlibrary Active Object Manager
/// @ingroup group_library
/// @{

/// @addtogroup ACTIVEOBJECTMODE
/// @ingroup group_enumeration
/// @{
enum class ACTIVEOBJECTMODE
{
	NONE,						///< None.

	OBJECT,					///< Object mode.
	TAG,						///< Tag mode.
	MATERIAL,				///< %Material mode.
	SHADER,					///< Shader mode.
	NODE,						///< Node mode.
	TIMELINE,				///< Timeline mode.
	FCURVE,					///< F-curve mode.
	BITMAPINFO,			///< @BP3D bitmap info mode
	TOOL,						///< Tool mode.
	VIEW,						///< View mode.
	INFOTAB,				///< Info tab.
	CAMERA,					///< Editor camera mode.
	RENDERDATA,			///< %Render data mode.
	DOCUMENT,				///< Document settings mode.
	MODELING,				///< %Modeling mode.
	LAYER,					///< Layer mode. @since R17.032

	DUMMY
} MAXON_ENUM_LIST(ACTIVEOBJECTMODE);
/// @}

//----------------------------------------------------------------------------------------
/// Describes a hook for active object manager modes.\n
/// Here is an example:
/// @code
/// GeData TagMessageHook(const BaseContainer &msg,void *data)
/// {
/// 	switch (msg.GetId())
/// 	{
/// 		case AOM_MSG_ISENABLED:
/// 			return true;
///
/// 		case AOM_MSG_GETATOMLIST:
/// 		{
/// 			BaseDocument* doc = GetActiveDocument();
/// 			if (!doc)
/// 				break;
/// 			doc->GetActiveTags(*((AtomArray*)data));
/// 			return true;
/// 		}
/// 		break;
/// 	}
/// 	return false;
/// }
/// @endcode
/// @param[in] msg								The message container. These are the available messages: @enumerateEnum{AOM_MSG}
/// @param[in] data								The data pointer. Depends on the message.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
typedef GeData MESSAGEHOOK(const BaseContainer &msg, void *data);

//----------------------------------------------------------------------------------------
/// Active object manager mode information.
/// @see ActiveObjectManager_GetModeInfo()
//----------------------------------------------------------------------------------------
struct ActiveModeInfo
{
	ACTIVEOBJECTMODE	id;					///< The mode ID. Either a member of @ref ACTIVEOBJECTMODE or a unique ID: @enumerateEnum{ACTIVEOBJECTMODE}
	String						name;				///< The mode name.
	MESSAGEHOOK				*hook;			///< The mode message hook.
};

/// @addtogroup AOM_MSG
/// @ingroup group_enumeration
/// @{
#define AOM_MSG_ISENABLED				'aoen'			///< Sent when the mode is enabled.
#define AOM_MSG_GETATOMLIST			'geta'			///< Sent when the active Object Manager needs a list of atoms to show. Store these in the @link AtomArray@endlink* pointed by @formatParam{data}.
#define AOM_MSG_GETSUBDIALOG		'osub'			///< @markInternal
#define AOM_MSG_FREESUBDIALOG		'fsub'			///< @markInternal
/// @}

/// @addtogroup ACTIVEOBJECTMANAGER_SETOBJECTS
/// @ingroup group_enumeration
/// @{
#define ACTIVEOBJECTMANAGER_SETOBJECTS_OPEN						1			///< A new manager is opened if there is no manager that accepts the given id, for example if the other managers are locked or have that mode disabled.
#define ACTIVEOBJECTMANAGER_SETOBJECTS_NOMODESWITCH		2			///< If the Attribute Manager already shows the mode of the objects being set, it will switch to the new objects. If the Attribute Manager has another mode the old mode and objects stay.
/// @}

//----------------------------------------------------------------------------------------
/// Registers a new mode. If no hook is passed the active objects will need to be manually set with ActiveObjectManager_SetObjects().
/// @param[in] id									The mode ID. If it is not a member of @ref ACTIVEOBJECTMODE, use a unique ID: @enumerateEnum{ACTIVEOBJECTMODE}
/// @param[in] text								The mode name.
/// @param[in] hook								The mode hook, or @formatConstant{nullptr} to register a mode without a hook.
/// @return												@trueIfOtherwiseFalse{the new mode was registered}
//----------------------------------------------------------------------------------------
Bool ActiveObjectManager_RegisterMode(ACTIVEOBJECTMODE id, const String &text, MESSAGEHOOK *hook);

//----------------------------------------------------------------------------------------
/// Sets the current mode.\n
/// For example, when the timeline becomes active it calls @link ActiveObjectManager_SetMode@endlink(@ref ACTIVEOBJECTMODE::TIMELINE) so that there is a manager ready to show its selections.
/// @param[in] id									The mode ID.
/// @param[in] openmanager				If @formatConstant{true} a new manager is opened if there is no manager that accepts the given id, for example if the other managers are locked or have that mode disabled.
//----------------------------------------------------------------------------------------
void ActiveObjectManager_SetMode(ACTIVEOBJECTMODE id, Bool openmanager);

//----------------------------------------------------------------------------------------
/// Sets the currently shown @formatParam{objects} in the specified mode @formatParam{id}.
/// @note Use this only if a mode has been registered without a hook. Otherwise the managers will ask for new objects themselves, and listen for events when new objects are selected.
/// @param[in] id									The mode ID.
/// @param[in] objects						The objects to show.
/// @param[in] flags							The flags: @enumerateEnum{ACTIVEOBJECTMANAGER_SETOBJECTS}
/// @param[in] activepage					The tab of the object's description to be shown. Pass the description ID of the tab.
//----------------------------------------------------------------------------------------
void ActiveObjectManager_SetObjects(ACTIVEOBJECTMODE id, const AtomArray &objects, Int32 flags, const DescID &activepage = DescID());

//----------------------------------------------------------------------------------------
/// Sets the currently shown object @formatParam{op} in the specified mode @formatParam{id}.
/// @note Use this only if a mode has been registered without a hook. Otherwise the managers will ask for new objects themselves, and listen for events when new objects are selected.
/// @param[in] id									The mode ID.
/// @param[in] op									The object to show.
/// @param[in] flags							The flags: @enumerateEnum{ACTIVEOBJECTMANAGER_SETOBJECTS}
/// @param[in] activepage					The tab of the object's description to be shown. Pass the description ID of the tab.
//----------------------------------------------------------------------------------------
void ActiveObjectManager_SetObject(ACTIVEOBJECTMODE id, C4DAtom *op, Int32 flags, const DescID &activepage = DescID());

//----------------------------------------------------------------------------------------
/// Opens a new active object manager.
//----------------------------------------------------------------------------------------
void ActiveObjectManager_Open();

//----------------------------------------------------------------------------------------
/// Shows a modal active object manager dialog with the specified @formatParam{objects} and @formatParam{dlgtitle}.
/// @param[in] objects						The objects to show.
/// @param[in] dlgtitle						The dialog title.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool EditObjectModal(const AtomArray &objects, const String &dlgtitle);

//----------------------------------------------------------------------------------------
/// Shows a modal active object manager dialog with the specified object @formatParam{op} and title @formatParam{dlgtitle}.
/// @param[in] op									The object to show.
/// @param[in] dlgtitle						The dialog title.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool EditObjectModal(C4DAtom *op, const String &dlgtitle);

//----------------------------------------------------------------------------------------
/// Shows the edit dialog for a dynamic description (i.e. user data).\n
/// @b Example:
/// @code
/// DynamicDescription* dd = op->GetDynamicDescription();
///
/// BaseContainer bc = GetCustomDataTypeDefault(DTYPE_LONG);
/// bc.SetString(DESC_NAME,"test1");
/// bc.SetString(DESC_SHORT_NAME,"test1");
/// bc.SetInt32(DESC_CUSTOMGUI,CUSTOMGUI_LONG);
/// bc.SetInt32(DESC_MIN,0);
/// bc.SetInt32(DESC_MAX,100);
/// bc.SetInt32(DESC_STEP,1);
/// bc.SetInt32(DESC_ANIMATE, DESC_ANIMATE_ON);
/// bc.SetBool(DESC_REMOVEABLE, true);
///
/// EditDescription(op, dd->Alloc(bc));
/// @endcode
/// @param[in] bl									The owner of the user data e.g. objects, tags etc.
/// @param[in] id									The ID of the user data element to be inserted.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool EditDescription(C4DAtom *bl, const DescID &id);

//----------------------------------------------------------------------------------------
/// Shows the add dialog for a dynamic description (i.e. user data).
/// @since R17.032
/// @param[in] bl									The owner of the user data e.g. objects, tags etc. @callerOwnsPointed{C4DAtom}
//----------------------------------------------------------------------------------------
void AddDescription(C4DAtom* bl);

//----------------------------------------------------------------------------------------
/// Shows the paste dialog for a dynamic description (i.e. user data).
/// @since R17.032
/// @param[in] bl									The owner of the user data e.g. objects, tags etc. @callerOwnsPointed{C4DAtom}
//----------------------------------------------------------------------------------------
void PasteDescription(C4DAtom* bl);

//----------------------------------------------------------------------------------------
/// Retrieves the currently shown @formatParam{objects} in the specified mode @formatParam{id}.
/// @param[in] id									The mode ID.
/// @param[out] objects						The shown objects.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool ActiveObjectManager_GetObjects(ACTIVEOBJECTMODE id, AtomArray &objects);

//----------------------------------------------------------------------------------------
/// Retrieves the information for the specified mode @formatParam{id}.
/// @param[in] id									The mode ID.
/// @param[out] info							Filled with the mode information.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool ActiveObjectManager_GetModeInfo(ACTIVEOBJECTMODE id, ActiveModeInfo &info);

//----------------------------------------------------------------------------------------
/// Gets the number of modes.
/// @return												The number of modes.
//----------------------------------------------------------------------------------------
Int32 ActiveObjectManager_GetModeCount();

//----------------------------------------------------------------------------------------
/// Retrieves the information for a mode by index.
/// @param[in] idx								The index of the mode: @em 0 <= @formatParam{idx} < ActiveObjectManager_GetModeCount()
/// @param[out] info							Filled with the mode information.
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
Bool ActiveObjectManager_GetModeInfoIdx(Int32 idx, ActiveModeInfo &info);

//----------------------------------------------------------------------------------------
/// Gets the last used mode.
/// @return												The last mode.
//----------------------------------------------------------------------------------------
ACTIVEOBJECTMODE ActiveObjectManager_GetLastMode();

/// Active object manager library ID.
#define LIBRARY_ACTIVEOBJECTMANAGER	1000473

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct ActiveObjectManagerLib : public C4DLibrary
{
	Bool							(*RegisterMode			)(ACTIVEOBJECTMODE id, const String &text, MESSAGEHOOK *hook);
	void							(*SetMode						)(ACTIVEOBJECTMODE id, Bool openmanager);
	void							(*Open							)();
	Bool							(*EditObjectModal		)(const AtomArray &objects, const String &dlgtitle);
	Bool							(*EditDescriptionOld)(DynamicDescription *dd, BaseContainer &bc);

	Bool							(*GetObjects				)(ACTIVEOBJECTMODE id, AtomArray &objects);
	Bool							(*GetModeInfo				)(ACTIVEOBJECTMODE id, ActiveModeInfo &info);
	Int32							(*GetModeCount			)();
	Bool							(*GetModeInfoIdx		)(Int32 idx, ActiveModeInfo &info);
	ACTIVEOBJECTMODE	(*GetLastMode				)();
	Bool							(*EditDescription		)(C4DAtom *bl, const DescID &id);
	void							(*SetObjects				)(ACTIVEOBJECTMODE id, const AtomArray &objects, Int32 flags, const DescID &activepage);
	void							(*AddDescription		)(C4DAtom* bl);
	void							(*PasteDescription  )(C4DAtom* bl);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_ACTIVEOBJECTMANAGER_H__
