/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_BASELIST_H__
#define C4D_BASELIST_H__

namespace maxon
{
class GraphNode;
};

#ifdef __API_INTERN__

	#include "intbaselist.h"
	#include "objectarray.h"
	#define AtCall(fnc) (this->*C4DOS.At->fnc)

	class NodeData;
	class GeListNode;
	class GeListHead;
	class DescID;
	class BaseBitmap;
	class TakeData;

#else

	#include "ge_math.h"
	#include "operatingsystem.h"
	#include "c4d_string.h"
	#include "c4d_basecontainer.h"
	#include "c4d_gedata.h"

	// macros for instanceof
	#define INSTANCEOFROOT(X)
	#define INSTANCEOF(X, Y)								\
		public:																\
			typedef Y SUPER;										\
		private:
	// macros for instanceof

	#define AtCall(fnc) (this->*C4DOS.At->fnc)
	#define BoCall(fnc) (this->*C4DOS.Bo->fnc)
#endif

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

class InclusionTable;
class SplineData;
class GeModalDialog;
class BaseTake;

/// @addtogroup MSG_REDIRECT_FLAG_PROCESSED
/// @ingroup group_enumeration
/// @{
/// @markPrivate
#define MSG_REDIRECT_FLAG_PROCESSED (1 << 0)
/// @}


/// Message structure for the @ref MSG_REDIRECT message. @markPrivate
struct RedirectMsgData
{
	Int32 type;
	void* data;
	BaseList2D* bl;
	Int32 flags;
};


/// @addtogroup TOOLTRANSFORM_FLAG
/// @ingroup group_enumeration
/// @{
/// @markPrivate
enum class TOOLTRANSFORM_FLAG
{
	NO_TRANSFORM	= (1 << 0),
	NO_RECURSE		= (1 << 1),
	NO_PARAMS			= (1 << 2),

	NONE					= 0
} MAXON_ENUM_FLAGS(TOOLTRANSFORM_FLAG);
/// @}


/// Message structure for the @ref MSG_TOOL_TRANSFORM message. @markPrivate
struct ToolTransformMsgData
{
	Float scl;
	Matrix tm, mm, up;
	Bool children;
	BaseObject* undo;
	TOOLTRANSFORM_FLAG flags;
};

/// Message structure for the @ref MSG_TAG_MODIFY message. @markPrivate
struct TagModifyMsgData
{
	Bool calculateFirst; ///< When try the result of TagData::GetModifiedObjects() will be calculated first.

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	TagModifyMsgData() : calculateFirst(false) { }
};

/// Message structure for the @ref MSG_TRANSFORM_OBJECT message. @markPrivate
struct ObjectTransformMsgData
{
	BaseObject* undo;
	Matrix tm;
	Bool sdown, useselection;
	Int32 mode;
	BaseDraw* bd;
};

/// Message structure for the @ref MSG_TRANSFORM_OBJECT message. @markPrivate
struct InvokeScriptData
{
	/// @name Input Values
	/// @{
	String functionName;					///< @readOnly The name of the function to call in the target script
	GeData arg1, arg2, arg3;			///< @readOnly The arguments to be passed to the function.
	/// @}

	/// @name Result Values
	/// @{
	GeData result;			///< Set to the result of executing the function
	/// @}
};

//----------------------------------------------------------------------------------------
/// Message structure for the @ref MSG_FIELDGUI_GETSUBLISTINFO message.
/// Sent to FieldLayers by the FieldListGUI to query whether the sublist in the passed ListHead should have certain channels disabled in the GUI.
//----------------------------------------------------------------------------------------
struct FieldGuiGetSubListInfo
{
	GeListHead* subListHead;			///< @readOnly The listhead that the FieldListGui wants to retrieve channel sampling information for
	FIELDLAYER_FLAG channelFlags = FIELDLAYER_FLAG::NONE;	///< Set to the correct sampling channels, use NOCHILDVALUE, NOCHILDCOLOR etc to disable channels in the GUI for the sublist.
	Int32 icon = NOTOK;						///< Set to the ID of the Icon you wish to use for the sublist
};

//----------------------------------------------------------------------------------------
/// Message struct for the @ref MSG_TOOL_ASK message.\n
/// Sent to tools on mouse input to query them on whether they accept/use certain input such as modifier keys, right or middle mouse button. This allows them to override the normal @C4D functionality.
//----------------------------------------------------------------------------------------
struct ToolAskMsgData
{
	/// @name Input Values
	/// @{
	Int32 version;								///< @readOnly The version number of this structure.
	EditorWindow* bw;							///< @readOnly The editor window.
	BaseDocument* doc;						///< @readOnly The document.
	Int32 x,											///< @readOnly X position of the mouse.
				y,											///< @readOnly Y position of the mouse.
				button;									///< @readOnly The pressed mouse buttons: @enumerateEnum{KEY}
	const BaseContainer* msg;			///< @readOnly The message container.
	BaseDraw* bd;									///< @readOnly The base draw.
	/// @}

	/// @name Result Values
	/// @{
	Bool popup_exit;					///< Set to @formatConstant{true} if you already did everything and canceling mouse input in the core.
	Bool popup_allowed;				///< Set to @formatConstant{false} to prevent core from opening a popup.
	Int32 popup_menuid;				///< Set to any menu ID to use the standard popup. e.g. @em M_MODELING_POLYGON.
	Bool use_middlemouse;			///< Set to @formatConstant{true} to use the middle mouse button to do something in ToolData::MouseInput().
	Bool use_rightmouse;			///< Set to @formatConstant{true} to use the right mouse button to do something in ToolData::MouseInput().
	Bool resize_allowed;			///< Set to @formatConstant{true} to accept sizing messages for brushes.
	Bool use_singleclick;			///< Set to @formatConstant{true} to allow single clicks to select components/objects.
	/// @}

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	ToolAskMsgData() : version(1), bw(nullptr), doc(nullptr), x(0), y(0), button(0), msg(nullptr), bd(nullptr),
		popup_exit(false), popup_allowed(true), popup_menuid(0), use_middlemouse(false), use_rightmouse(false), resize_allowed(false), use_singleclick(false) { }
};

//----------------------------------------------------------------------------------------
/// Message struct for the @ref MSG_TOOL_SWITCHACTION message.\n
/// Sent to tools on mouse input to query them on whether they should change to a different tool temporarily while a certain situation (e.g. modifier key) is being held.\n
/// @note The tool must have the @ref PLUGINFLAG_TOOL_SWITCHACTION flag for @ref MSG_TOOL_SWITCHACTION message to be invoked.
/// @since R17.032
//----------------------------------------------------------------------------------------
struct ToolSwitchActionMsgData
{
	/// @name Input Values
	/// @{
	EditorWindow* bw;							///< @readOnly The editor window.
	BaseDocument* doc;						///< @readOnly The document.
	BaseDraw* bd;									///< @readOnly The base draw.
	QUALIFIER qualifier;					///< @readOnly The current qualifier.
	/// @}

	/// @name Result Values
	/// @{
	Int32 action;									///< Assign the ID of an action to switch to temporarily, or leave as @ref NOTOK to ignore.
	/// @}

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	ToolSwitchActionMsgData() : bw(nullptr), doc(nullptr), bd(nullptr), qualifier(QUALIFIER::NONE), action(NOTOK) { }
};


//----------------------------------------------------------------------------------------
/// Message struct for the @ref MSG_TOOL_RESIZE message.\n
/// Sent during MMB (Middle Mouse Button) dragging and the [ and ] shortcuts with brushes if ToolAskMsgData::resize_allowed is set to @formatConstant{true} by the developer.\n
/// Here is an example from the <i>Live Selection tool</i> to show how it works:
/// @code
/// Bool LiveSelectionTool::Message(BaseDocument *doc, BaseContainer &data, Int32 type, void *t_data)
/// {
/// 	switch (type)
/// 	{
/// 	case MSG_TOOL_ASK:
/// 	{
/// 		ToolAskMsgData *a = (ToolAskMsgData*)t_data;
/// 		a->resize_allowed = true;
/// 	}
/// 	break;
/// 	case MSG_TOOL_RESIZE:
/// 	{
/// 		ToolResizeData *d = (ToolResizeData*)t_data;
/// 		if (!d || !d->data)
/// 			return false;
/// 		switch (d->pass)
/// 		{
/// 		case ToolResizeData::RESIZE_PASS_INIT:
/// 		{
/// 			d->falloff.show = d->cross_type = d->data->GetInt32(MDATA_SELECTLIVE_MODE) != MDATA_SELECTLIVE_MODE_NORMAL;
/// 			d->falloff.size = d->data->GetFloat(MDATA_SELECTLIVE_RADIUS);
/// 			d->falloff.opacity = d->data->GetFloat(MDATA_SOFT_STRENGTH);
/// 			d->falloff.position.off = Vector(mousex, mousey, 0.0);
/// 		}
/// 		break;
/// 		case ToolResizeData::RESIZE_PASS_RESIZE:
/// 		{
/// 			if (d->horizontal)
/// 			{
/// 				d->falloff.size = d->data->GetFloat(MDATA_SELECTLIVE_RADIUS);
/// 				d->falloff.size += d->delta;
/// 				if (d->falloff.size < 0.0) d->falloff.size = 0.0;
/// 				if (d->falloff.size > 1000.0) d->falloff.size = 1000.0;
/// 				d->data->SetFloat(MDATA_SELECTLIVE_RADIUS, d->falloff.size);
/// 			}
/// 			else
/// 			{
/// 				if (d->data->GetInt32(MDATA_SELECTLIVE_MODE) == MDATA_SELECTLIVE_MODE_SOFTSELECTION)
/// 				{
/// 					d->falloff.opacity = d->data->GetFloat(MDATA_SOFT_STRENGTH);
/// 					d->falloff.opacity += Float(d->delta) * 0.01;
/// 					d->falloff.opacity = FCut(d->falloff.opacity, 0.0, 1.0);
/// 					d->data->SetFloat(MDATA_SOFT_STRENGTH, d->falloff.opacity);
/// 				}
/// 				else
/// 				{
/// 					d->falloff.opacity = d->data->GetFloat(MDATA_VERTEXPAINT_STRENGTH);
/// 					d->falloff.opacity += Float(d->delta) * 0.01;
/// 					d->falloff.opacity = FCut(d->falloff.opacity, 0.0, 1.0);
/// 					d->data->SetFloat(MDATA_VERTEXPAINT_STRENGTH, d->falloff.opacity);
/// 				}
/// 			}
/// 		}
/// 		break;
/// 		default: break;
/// 		}
/// 	}
/// 	break;
/// 	}
///
/// 	...
/// }
/// @endcode
//----------------------------------------------------------------------------------------
struct ToolResizeData
{
	/// @name Input Values
	/// @{
	enum RESIZE_PASS
	{
		RESIZE_PASS_INIT						= 0,			///< Called before resizing starts.
		RESIZE_PASS_GENERATEFALLOFF	= 1,			///< Called when a custom falloff needs to be generated.
		RESIZE_PASS_RESIZE					= 2,			///< Called during the resizing process
		RESIZE_PASS_END							= 3,			///< Called to end the resizing process.
		RESIZE_PASS_RESET						= 4				///< Called to reset resizing (user canceled action).
	} pass;										///< @readOnly The resize pass: @enumerateEnum{RESIZE_PASS}
	Int32 delta;							///< @readOnly The mouse movement delta.
	Int32 total_delta;				///< @readOnly The mouse movement delta.
	Int32 horizontal;					///< @readOnly @formatConstant{true} if a horizontal movement is occurring and @ref cross_type has been set to @formatConstant{true} in the @ref RESIZE_PASS_INIT pass by the user.
	BaseContainer* data;			///< @readOnly A pointer to the tool's BaseContainer.
	/// @}

	/// @name Result Values
	/// @{
	Bool cross_type;			///< Set to @formatConstant{false} to disable cross type resizing, where the primary direction the mouse is moved in dictates movement afterwards.

	struct ToolResizeFalloffData
	{
		ToolResizeFalloffData() : show(false), opacity(1.0), size(0.0), hardness(0.0), color(1.0), is_3D(false), dirty(false), falloff(nullptr), custom_shape(nullptr) { }

		Bool show;								///< Set to @formatConstant{true} to show the falloff for the brush increment to force dirtiness for @ref falloff or @ref custom_shape.
		Float opacity;						///< The opacity of the brush display preview.
		Float size;								///< The size of the brush display preview.
		Float hardness;						///< The hardness of the brush display preview.
		Vector color;							///< The color for the brush display preview.
		Matrix position;					///< The center of the falloff, just use Matrix::off for 2D brushes.
		Bool is_3D;								///< Set to @formatConstant{true} to optionally display the falloff in 3D.
		Bool dirty;								///< Set to @formatConstant{true} to redraw the custom shape.
		SplineData* falloff;			///< Custom falloff spline, allocate and set in @ref RESIZE_PASS_GENERATEFALLOFF. The caller owns it and must release in @ref RESIZE_PASS_END.
		BaseBitmap* custom_shape;	///< Allocate in @ref RESIZE_PASS_INIT to use as a custom shape instead of the normal one, fill in @ref RESIZE_PASS_GENERATEFALLOFF. The caller owns it and must release in @ref RESIZE_PASS_END.
	};
	ToolResizeFalloffData falloff; ///< The radial falloff display preview settings.
	String cursor_text;							///< The text to display next to the mouse cursor.
	/// @}

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	ToolResizeData() : pass(RESIZE_PASS_RESIZE), delta(0), total_delta(0), horizontal(NOTOK), data(nullptr), cross_type(true) { }
};


/// Message struct for the @ref MSG_DESCRIPTION_IMPEXPORT_INIT message.
struct DescriptionImExportInit
{
	BaseDocument* doc;			///< The active document. @cinemaOwnsPointed{document}
	GeModalDialog* dlg;			///< The import/export settings dialog. @cinemaOwnsPointed{dialog}
};

/// @addtogroup MSG
/// @ingroup group_enumeration
/// @{
#define MSG_POINTS_CHANGED												1				///< The points have changed. @correspondingData{VariableChanged}
#define MSG_POLYGONS_CHANGED											2				///< The polygons have changed. @correspondingData{VariableChanged}
#define MSG_UPDATE																5				///< Must be sent if the bounding box has to be recalculated. (Otherwise use @ref MSG_CHANGE.)
#define MSG_SMALLUPDATE														6				///< Part of the object has changed that needs no cache rebuilding.\n
																													///< @note This message should be used very carefully, it is there for (small) performance enhancements, for example if a polygon selection is changed then the caches do not need to be rebuilt, so @ref MSG_SMALLUPDATE can be sent.
#define MSG_CHANGE																7				///< Must be sent if any object data (except for the matrix) has been changed.\n
																													///< @note	For tag parameter changes call
																													///<				@code
																													///					C4DAtom::SetDirty(DIRTYFLAGS::DATA);
																													///					@endcode
																													///<				instead of
																													///<				@code
																													///					C4DAtom::Message(MSG_CHANGE);
																													///					@endcode
#define MSG_BASECONTAINER													9				///< Message with a container, for example from a Python plugin. @correspondingData{BaseContainer}
#define MSG_SEGMENTS_CHANGED											10			///< The segments have changed. @correspondingData{VariableChanged}
#define MSG_FILTER																14			///< A message filter that lets block C4DAtom::MultiMessage() calls. @correspondingData{MessageFilter}\n
																													///< Return @formatConstant{true} to let the message pass and @formatConstant{false} to block it.
#define MSG_TRANSFERGOALS													15			///< Internal message. @markPrivate

#define MSG_DESCRIPTION_INITUNDO									16 ///< Allows elements to create undo actions for the following parameter changes in the attributes manager. This is already automatically handled for keys, tags, objects etc. @correspondingData{DescriptionInitUndo}
#define MSG_DESCRIPTION_CHECKUPDATE								17 ///< Allows elements to determine the type of refresh after a parameter has been changed in the Active manager. This is already automatically handled for keys, tags, objects etc. @correspondingData{DescriptionCheckUpdate}\n
																										 ///< @note	Currently this message is completely handled by all base data classes.\n
																										 ///<				Most plugins will not need to modify the message @em data. It is more interesting to start some update action - e.g. deleting data that will be rebuilt with the next access.
/// @addtogroup MSG_DESCRIPTION_CHECKUPDATE_FLAGS
/// @ingroup group_enumeration
/// @{
#define MSG_DESCRIPTION_CHECKUPDATE_DOCUMENT			(1 << 1)			///< Currently unused. (Necessary to force a view/bitmap update.)
#define MSG_DESCRIPTION_CHECKUPDATE_AUTOKEY				(1 << 2)			///< Element supports automatic keyframing.
#define MSG_DESCRIPTION_CHECKUPDATE_SYNC					(1 << 4)			///< This flag lets @C4D refresh while changing the values interactively (e.g. via edit field spinners).
#define MSG_DESCRIPTION_CHECKUPDATE_ANIMATE				(1 << 5)			///< @markPrivate
#define MSG_DESCRIPTION_CHECKUPDATE_AUTOTAKE			(1 << 6)			///< Element supports automatic Take overrides. @since R17.032
#define MSG_DESCRIPTION_CHECKUPDATE_BASELISTEDIT	(1 << 7)			///< Edit node is updating the current Take override value. @since R17.032
#define MSG_DESCRIPTION_CHECKUPDATE_NOSCENEUPDATE	(1 << 23)			///< @markPrivate
#define MSG_DESCRIPTION_CHECKUPDATE_INDRAG				(1 << 24)			///< set if the ui is in drag and this message is not the final one.
/// @}

#define MSG_DESCRIPTION_COMMAND										18						///< Sent by for example @em BUTTON description element. @correspondingData{DescriptionCommand}
#define MSG_DESCRIPTION_POPUP											300001046			///< Allows popup menu handling in the Attribute Manager. @correspondingData{DescriptionPopup}
#define MSG_DESCRIPTION_POSTSETPARAMETER					19						///< Sent after a C4DAtom::SetParameter() call. @correspondingData{DescriptionPostSetValue}
#define MSG_DESCRIPTION_VALIDATE									20						///< Allows to update dependencies or to check for invalid values after a parameter has been changed. @correspondingData{DescriptionValidate}\n
																																///< For example the light's inner radius always must be smaller than the light's outer radius; this routine checks for it and corrects it.

#define MSG_DESCRIPTION_SWAP											465001611			///< A private message sent by the X-Ref system to exchange proxies. @since R16.038

#define MSG_EDIT																	21			///< Allows elements to do some action if the user edits the element (double-click e.g. in object manager).
#define MSG_MENUPREPARE														22			///< Allows tags, objects, shaders etc. to do some setup work when called from the menu. @correspondingData{the current BaseDocument}
#define MSG_RETRIEVEPRIVATEDATA										23			///< A generic private message to retrieve data from an object. Specific for every type of object so no public documentation available. @correspondingData{RetrievePrivateData}

/// @addtogroup MSG_DESCRIPTION
/// @ingroup group_enumeration
/// @{
#define MSG_DESCRIPTION_INEX_DELETED											1036464				///< Sent by an in/exclude list to the parent. Tells the parent, that an entry got deleted from the list @correspondingData{DescriptionInExDeleted} @since R18
#define MSG_DESCRIPTION_INEX_ADDED												1036465				///< Sent by an in/exclude list to the parent. Tells the parent, that an entry got added to the list @correspondingData{DescriptionInExAdded} @since R18
#define MSG_DESCRIPTION_INEX_SELCHANGED										1037151				///< Sent by an in/exclude list to the parent. Tells the parent, that the selection in the InExclude List changed @correspondingData{DescriptionInExSelChanged} @since R18
#define MSG_DESCRIPTION_REMOVE_ENTRY											24						///< Tells the atom to remove a description entry. @correspondingData{DescriptionCommand}
#define MSG_DESCRIPTION_EDIT_ENTRY												25						///< Tells the atom to edit a description entry. @correspondingData{DescriptionCommand}
#define MSG_DESCRIPTION_CHECKDRAGANDDROP									26						///< Asks the atom if a drag and drop onto for example a @em LINK description element or @em IN_EXCLUDE description element field should be accepted. @correspondingData{DescriptionCheckDragAndDrop}
#define MSG_DESCRIPTION_GETBITMAP													27						///< Queries the object for updated bitmaps for BitmapButtonCustomGui elements in the description (e.g. the lens flare preview). @correspondingData{DescriptionGetBitmap}
#define MSG_DESCRIPTION_GETOBJECTS												30						///< @markPrivate
#define MSG_DESCRIPTION_USERINTERACTION_START							440000249			///< Start of user interaction.
#define MSG_DESCRIPTION_USERINTERACTION_END								31						///< End of user interaction.
#define MSG_DESCRIPTION_GETINLINEOBJECT										200000169			///< Sent by the Attribute Manager to the atom. The atom can check for a description ID and return the linked objects in the atom array. @correspondingData{DescriptionInlineObjectMsg}
#define MSG_DESCRIPTION_IMPEXPORT_INIT										200000288			///< Sent before the import/export setting dialog of filter plugins is shown. @correspondingData{DescriptionImExportInit}
#define MSG_DESCRIPTION_IMPEXPORT_CANCEL									1040093				///< Sent if the import/export setting dialog of filter plugins was canceled.
#define MSG_DESCRIPTION_CUSTOMGUI_NOTIFICATION						431000175			///< Sent by a custom GUI to the parent. @correspondingData{DescriptionCustomGuiNotification} @since R19
#define MSG_DESCRIPTION_CUSTOMGUI_NOTIFICATION_ID 				0							///< The custom GUI ID in the message container for @ref MSG_DESCRIPTION_CUSTOMGUI_NOTIFICATION. @since R19
#define MSG_DESCRIPTION_CUSTOMGUI_NOTIFICATION_CONTENT		1							///< The used data in the message container for @ref MSG_DESCRIPTION_CUSTOMGUI_NOTIFICATION. @since R19
#define MSG_DESCRIPTION_RESET_CHANGE											440000288			///< Tells the atom to reset a changed description entry. @correspondingData{DescriptionCommand}
/// @}

/// @addtogroup MSG_DESCRIPTION_TEXT
/// @ingroup group_containerid
/// @{
#define MSG_DESCRIPTION_TEXT_STOREUNDO						440000181			///< Used by the Multiline Edit Text gadget to store its undo data as a BaseContainer. See MultilineEditTextStoreUndo.
#define MSG_DESCRIPTION_TEXT_RESTOREUNDO					440000182			///< Used by the Multiline Edit Text gadget to restore its undo data from a passed BaseContainer. See MultilineEditTextStoreUndo.
#define MSG_DESCRIPTION_TEXT_COMPILE							440000194			///< Used by the Multiline Edit Text gadget when used for code to set the line flags.
#define MSG_DESCRIPTION_TEXT_SAVE									440000195			///< Used by the Multiline Edit Text gadget when used for code to set the line flags.
/// @}

#define MSG_DESCRIPTION_ALLOWOVERRIDE							431000094			///< Sent before the Take override is added to allow it or not. @correspondingData{DescriptionAllowOverride} @since R17.032 @see Take System @ref page_manual_baseoverride_takesystem_additional_messages.
#define MSG_DESCRIPTION_TAKECHANGED								431000140			///< Sent to each overridden node when the user changes the current Take. Sent to both the node storing the data in the Take and the node releasing the data to the document. @correspondingData{DescriptionTakeChanged} @since R17.032 @see Take System @ref page_manual_baseoverride_takesystem_additional_messages.
#define MSG_GETOVERRIDEASSETS											1050943				///< @markPrivate

/// @addtogroup MULTLINEEDITTEXT_UNDO_CONTAINER
/// @ingroup group_containerid
/// @{
#define MULTLINEEDITTEXT_UNDO_CONTAINER						440000196			///< Default storage ID location for the Multiline Edit Text gadget's undo container.
#define MULTLINEEDITTEXT_UNDO_CONTAINER_TEXT			0							///< @markPrivate
#define MULTLINEEDITTEXT_UNDO_CONTAINER_LEVEL			1							///< @markPrivate
#define MULTLINEEDITTEXT_UNDO_CONTAINER_SIZE			2							///< @markPrivate
#define MULTLINEEDITTEXT_UNDO_CONTAINER_FLAGS			3							///< @markPrivate
#define MULTLINEEDITTEXT_UNDO_CONTAINER_SAVED			4							///< @markPrivate
#define MULTLINEEDITTEXT_UNDO_CONTAINER_STACK			100						///< @markPrivate
/// @}

#define MSG_MOVE_FINISHED													32					///< Sent after a handle or the object has been moved.
#define MSG_MOVE_START														1021543			///< Sent before a handle or the object has been moved.
#define MSG_EDITABLE_END													33					///< @markPrivate
#define MSG_GETCUSTOMICON													1001090			///< Every atom can return a custom icon with this message. @correspondingData{GetCustomIconData}
#define MSG_MATERIALDRAGANDDROP										1001069			///< Received by a material upon dropping an instance of a material onto an object. @correspondingData{MaterialDragAndDrop}\n
																															///< @note	The material can choose to create a tag of its own, or trigger other actions, instead of letting @C4D create a normal material assignment.\n
																															///<				For example Sketch and Toon creates its own type of tag and returns it in MaterialDragAndDrop::result. @C4D creates the undo for it and activates it. Inserting the tag is done by the material.
#define MSG_DRAGANDDROP														1018756			///< Received by an element in the Object manager when something is dropped on it. @correspondingData{DragAndDrop}
#define MSG_INITIALCHANNEL												1001073			///< See HandleInitialChannel().
#define MSG_PYTHON_RESET													1024114			///< If this message is sent to Python related instances (Python tag, generator, node etc.) the Python scope is freed and reallocated.

#define MSG_DOCUMENTINFO													1001078			///< Sent as broadcast message by the document when it is loaded, saved , merged etc. @correspondingData{DocumentInfoData}

#define MSG_MATERIAL_OVERRIDE											431000124		///< Sent to each material before the rendering to react to a global material override. @correspondingData{OverrideMaterial} @since R17.032

#define MSG_RETRIEVE_NIMBUS_NODESYSTEM						13246576		///< 
#define MSG_REQUEST_VIEWPORT_MAPPING							13246579		///< @markprivate @since R21 - sent to a BaseMaterial requesting a viewport representation.
#define MSG_UPDATE_VIEWPORT_MAPPING								13246580		///< @markprivate @since R21 - sent to a BaseMaterial updating the current viewport representation.

/// @addtogroup MSG_DOCUMENTINFO_TYPE
/// @ingroup group_enumeration
/// @{
#define MSG_DOCUMENTINFO_TYPE_SETACTIVE						1000			///< Document was set as active.
#define MSG_DOCUMENTINFO_TYPE_LOAD								1001			///< Document was loaded.
#define MSG_DOCUMENTINFO_TYPE_MERGE								1002			///< Document was merged.
#define MSG_DOCUMENTINFO_TYPE_BEFOREMERGE					1003			///< Document before merge. @em data points to a @ref MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT value.
#define MSG_DOCUMENTINFO_TYPE_SAVE_BEFORE					1004			///< Document is about to be written.
#define MSG_DOCUMENTINFO_TYPE_SAVE_AFTER					1005			///< Document was saved.
#define MSG_DOCUMENTINFO_TYPE_SAVEPROJECT_BEFORE	1006			///< Save Project with Assets is about to be executed. dfi->data contains SaveProjectStruct
#define MSG_DOCUMENTINFO_TYPE_SAVEPROJECT_AFTER		1007			///< Save Project with Assets was executed. dfi->data contains SaveProjectStruct

/// structure contains extra data for MSG_DOCUMENTINFO_TYPE_SAVEPROJECT_BEFORE and MSG_DOCUMENTINFO_TYPE_SAVEPROJECT_AFTER
struct SaveProjectStruct
{
	SAVEPROJECT saveProjectFlags = SAVEPROJECT::NONE;
};

#define MSG_DOCUMENTINFO_TYPE_REMOVE							1008			///< The document is removed from the document list. All structures are still accessible.
#define MSG_DOCUMENTINFO_TYPE_TOOL_CHANGED				1009			///< Tool changed.
#define MSG_DOCUMENTINFO_TYPE_OBJECT_INSERT				1010			///< Objects got inserted into the document.
#define MSG_DOCUMENTINFO_TYPE_TAG_INSERT					1011			///< Tags got inserted into the document.
#define MSG_DOCUMENTINFO_TYPE_MATERIAL_INSERT			1012			///< Materials got inserted into the document.
#define MSG_DOCUMENTINFO_TYPE_UNDO								1013			///< Undo was called.
#define MSG_DOCUMENTINFO_TYPE_REDO								1014			///< Redo was called.
#define MSG_DOCUMENTINFO_TYPE_PASTE								1015			///< Paste was called.
#define MSG_DOCUMENTINFO_TYPE_COPY								1016			///< Copy was called. @markPrivate
#define MSG_DOCUMENTINFO_TYPE_LOAD_XREFS					1017			///< @markPrivate
#define MSG_DOCUMENTINFO_TYPE_MERGE_XREFS					1018			///< @markPrivate
#define MSG_DOCUMENTINFO_TYPE_XREFS_IMPORTED			1019			///< @markPrivate
#define MSG_DOCUMENTINFO_TYPE_MAKEPROJECT					1020			///< Sent around during "Save as Project" for each texture / asset it copies. @em data points to a DocumentInfoMakeProj. This message is only sent to scene hooks.
#define MSG_DOCUMENTINFO_TYPE_SWAP_XREF						1021			///< @markPrivate @since R16.038
#define MSG_DOCUMENTINFO_TYPE_NODE_ASSETS_CHANGED	1022			///< @markprivate @since R20.000 - send around after assets in a basedocument have been changed
#define MSG_DOCUMENTINFO_TYPE_MODE_CHANGED				1023			///< Mode changed
#define MSG_DOCUMENTINFO_TYPE_FLUSHCACHES					1024			///< Document caches are flushed. This message is only sent to scene hooks. @since R19.062
/// @}

#define MSG_GETSELECTION													1022176				///< @markPrivate
#define MSG_REDIRECT															1023019				///< @markPrivate
#define MSG_TOOL_TRANSFORM												1025528				///< @markPrivate
#define MSG_GETACTIVEREDIRECT											1025664				///< @markPrivate
#define MSG_TOOL_ASK															200000285			///< Sent to tools on mouse input to query them on whether they accept/use certain input such as modifier keys, right or middle mouse button. @correspondingData{ToolAskMsgData}
#define MSG_TAG_MODIFY														1027944				///< @markPrivate
#define MSG_TOOL_RESIZE														440000137			///< Sent during MMB (MMB (Middle Mouse Button) dragging and the [ and ] shortcuts with brushes if ToolAskMsgData::resize_allowed is set to @formatConstant{true} by the developer in @ref MSG_TOOL_ASK. @correspondingData{ToolResizeData}
#define MSG_CURRENTSTATE_END											1028521				///< @markPrivate
#define MSG_ALLOWXPRESSODROP											1030412				///< Allow or deny drag&drop of an XPresso node. Return @formatConstant{true} to allow, @formatConstant{false} to deny.
#define MSG_TOOL_SWITCHACTION											440000218			///< Sent to tools on mouse input and cursor info if they have the flag @ref PLUGINFLAG_TOOL_SWITCHACTION set to allow to change action on modifier key. @since R17.032
#define MSG_COPYDIRTYPRIVATE											440000326			///< @markPrivate

/// @addtogroup MSG_MULTI
/// @ingroup group_enumeration
/// @{
#define MSG_MULTI_RENDERNOTIFICATION		1001071							///< A document and all of its elements receive this message before a render starts. @correspondingData{RenderNotificationData}
#define MSG_MULTI_MARKMATERIALS					(4 | (1 << 30))			///< When @em data is @formatConstant{nullptr} this is sent to atoms to let them mark the materials they use.\n
																														///< Otherwise the message is sent to let translate material links, for example when a material is replaced, and then the corresponding data is MarkMaterials.
																														///< @note An example for both cases is included on the MarkMaterials page.
#define MSG_MULTI_DOCUMENTCLONED				11									///< The document has been cloned.
#define MSG_MULTI_DOCUMENTIMPORTED			13									///< After a @C4D document has been loaded this message is sent to the document (and all children structures). @correspondingData{DocumentImported}
#define MSG_MULTI_SETNEWMARKERS					200000161						///< @markPrivate
#define MSG_MULTI_CLEARSUGGESTEDFOLDER	200000040						///< Objects have to remove absolute paths (only if they support @ref MSG_GETALLASSETS).\n
																														///< Both @ref MSG_GETALLASSETS and @ref MSG_MULTI_CLEARSUGGESTEDFOLDER are important for "Save Project" to work and to collect all items.
																														///< @note	When "Save Project with Assets" is invoked, everything is moved to the new target directory.\n
																														///<				In this case all absolute paths must be converted to just filenames because the files are next to the document and the absolute paths are not needed anymore.
																														///< @see MSG_GETALLASSETS MSG_RENAMETEXTURES
																														///< r24: struct ModifyFilenameDataStruct will be send with the message. Call HandleModifyFilenameMessage() to process the data correctly by the c4d api.

struct ModifyFilenameDataStruct
{
	maxon::HashMap<maxon::Url, maxon::Url> _oldToNew;
};

maxon::Result<Filename> HandleModifyFilenameMessage(Int32 msgType, const void* msgData, const Filename& filename, BaseList2D* undoBl, const ModifyFilenameDelegate& modifyFilenameDelegate = {});

	/// @}

#define MSG_TRANSLATE_POINTS					1015632				///< Sent by the modeling core to let tags etc. update after point changes. @correspondingData{TranslationMaps}
#define MSG_TRANSLATE_POLYGONS				1015633				///< Sent by the modeling core to let tags etc. update after polygon changes. @correspondingData{TranslationMaps}
#define MSG_TRANSLATE_NGONS						1015634				///< Sent by the modeling core to let tags etc. update after N-gon changes. @correspondingData{TranslationMaps}
#define MSG_TRANSLATE_SEGMENTS				1015831				///< Sent by the modeling core to let tags etc. update after segment changes. @correspondingData{TranslationMaps}
#define MSG_PRETRANSLATE_POINTS				1015822				///< Sent before @ref MSG_TRANSLATE_POINTS, before the changes are actually carried out. @correspondingData{TranslationMaps}
#define MSG_PRETRANSLATE_POLYGONS			1015823				///< Sent before @ref MSG_TRANSLATE_POLYGONS, before the changes are actually carried out. @correspondingData{TranslationMaps}
#define MSG_PRETRANSLATE_NGONS				1015824				///< Sent before @ref MSG_TRANSLATE_NGONS, before the changes are actually carried out. @correspondingData{TranslationMaps}
#define MSG_PRETRANSLATE_SEGMENTS			1015832				///< Sent before @ref MSG_TRANSLATE_SEGMENTS, before the changes are actually carried out. @correspondingData{TranslationMaps}
#define MSG_UPDATE_NGONS							475000000			///< Should be sent if points are changed and any N-gons need updating. @C4D will then update the N-gons, if the user has this option enabled.
#define MSG_DOCUMENT_MODE_CHANGED			200000091			///< Sent to the active tool plugin during BaseDocument::SetMode().
#define MSG_TOOL_RESTART							200000096			///< @markPrivate (Handles the tool description apply behavior after mouse clicks.)
#define MSG_DEFORMMODECHANGED					200000125			///< @markPrivate
#define MSG_ANIMATE										300001037			///< Sent to objects after they have been animated.
#define MSG_CALCMEMUSAGE							200000160			///< @markPrivate
#define MSG_SCALEDOCUMENT							300001069			///< Tells the document that another document with different scale has been merged. @correspondingData{MessageScaleDocument}
#define MSG_GET_INHERITANCECONTAINER	300001052			///< @markPrivate
#define MSG_SOFTTAG_UPDATE						1016685				///< @markPrivate
#define MSG_TRANSFORM_OBJECT					440000109			///< @markPrivate
#define MSG_STRINGUNDO								300001071			///< @markPrivate
#define MSG_GETREALCAMERADATA					1028476				///< Sent to get a real camera object from a generator. @correspondingData{GetRealCameraData}
#define MSG_ADAPTVIEW_START						1028478				///< Sent to the camera object when the viewport transition starts.
#define MSG_ADAPTVIEW_END							1028479				///< Sent to the camera object when the viewport transition ends.
#define MSG_GETREALTAGDATA						1036447				///< Sent to get a real tag object from a virtual "generator" tag. @correspondingData{GetRealTagData} @since R18

#define MSG_DISABLE_SYMMETRY_OBJECTS	440000286			///< @markPrivate
#define MSG_ENABLE_SYMMETRY_OBJECTS		440000287			///< @markPrivate
#define MSG_SYMMETRY_FLIP 						431000173			///< @markPrivate @since R18

#define MSG_XREFINIT									431000149			///< Sent to each node if any special operation has to be done on ref. @correspondingData{XrefInitData}
#define MSG_XREF_GET_FIRST_MATERIAL		450000271			///< Sent to an X-Ref object to get its first material. @correspondingData{BaseMaterial*}.

#define MSG_INVOKE_SCRIPT_FUNCTION		440000184			///< Sent to invoke a function within a script on the target object. @correspondingData{InvokeScriptData}
/// @}
#define MSG_CONVERT_TO_IES_STRING			500000214			///< @markPrivate Sent to convert the internal IES representation to a maxon::String. @since R19
#define MSG_COMPUTE_LIGHT_COLOR				500000318			///< @markPrivate Sent to compute the color of a light. @since R19
#define MSG_COMPUTE_LIGHT_AREA				500000319			///< @markPrivate Sent to compute the area of a light. @since R19
#define MSG_GETCUSTOMICON_SETTINGS		1041699 			///< @markPrivate Sent to get icon settings. @see CustomIconSettings. @since R21
#define MSG_FIELDGUI_GETSUBLISTINFO	440000346			///< Sent to retrieve the correct channel flags for the GeListHead in the passed @correspondingData{FieldGuiGetSubListInfo}@ object, this lets the Field List GUI know which channels will be sampled in the sublist that the GeListHead owns in order that it can hide channels not in use.
#define MSG_FIELDGUI_ENABLEMASK				440000343			///< @markPrivate
#define MSG_FIELDGUI_DISABLEMASK			440000344			///< Sent to the owning FieldLayer with a passed GeListHead* that the user has pressed the delete key on in the GUI to remove.  The FieldLayer must handle the deletion itself.

#define MSG_BASEOBJECT_PRIVATEDATA_SET		465900000	///< This message is used to send private data to the baseObject.
																										///< The contents of the message are described by @ref BaseObjectPrivateMessage, which provides both a generic
																										///< ObjectRef which can store any type of StrongRef'd data and a key, which uniquely identifies the message.
																										///< Using the unique key the data is stored as an entry in a private thread-safe hashmap on the baseObject.
																										///< The private entry can be then queried with @ref MSG_BASEOBJECT_PRIVATEDATA_GET.
																										///< @since R21
#define MSG_BASEOBJECT_PRIVATEDATA_GET		465900001	///< This message is used to query private data from the baseObject.
																										///< The contents of the message are described by @ref BaseObjectPrivateMessage, which provides both a generic
																										///< ObjectRef which can store any type of StrongRef'd data and a key, which uniquely identifies the message.
																										///< Using the unique key the data is queried from a private thread-safe hashmap on the baseObject.
																										///< To query with this message only the key member has to be set.
																										///< If the key was previously set through a @ref MSG_BASEOBJECT_PRIVATEDATA_SET message, the data is returned
																										///< in the dataRefPtr member.
																										///< @since R21

#define MSG_DISALLOW_UV_3D_DISPLAY 431000204				///< @markPrivate
#define MSG_TOOL_CLONE  431000205										///< @markPrivate

#define MSG_GET_VIEWPORT_RENDER_ID  1054802					///< This message is used to get the viewport render ID. The message data is of type ViewportRenderIDMessageData.
																										///< @markPrivate
																										///< @since R22

//----------------------------------------------------------------------------------------
/// Message structure for the @ref MSG_BASEOBJECT_PRIVATEDATA_SET and @ref MSG_BASEOBJECT_PRIVATEDATA_GET messages.
/// If used with @ref MSG_BASEOBJECT_PRIVATEDATA_SET the the key represents the insertion key and the dataRefPtr represents the value for the key
/// If used with @ref MSG_BASEOBJECT_PRIVATEDATA_GET the the key represents the query key and the dataRefPtr represents the value that was
/// previously stored on the baseObject for the query key. 
/// @markPrivate
/// @since R21
//----------------------------------------------------------------------------------------
class BaseObjectPrivateMessage
{
public:
	UInt key = 0;									///< Key used to uniquely query/store feature-related data (e.g. hair) on a BaseObject.
																///< It is recommended to use the HashCode of the class that has data passed through BaseObject.
	maxon::ObjectRef* dataRefPtr;	///< @markPrivate ObjectRef can be used to store/receive any StrongRefType.
};

/// Message struct for the @ref MSG_STRINGUNDO message. @markPrivate
struct StringUndo
{
	String str;
	Bool redo;
};


//-------------------------------------------------------------------------------------------------
/// The VariableChanged structure is essential for changing point/polygon counts in objects to allocate or remove multiple elements with a single C4DAtom::Message() call.\n
/// It can be used for example when sending @ref MSG_POINTS_CHANGED and @ref MSG_POLYGONS_CHANGED messages to objects, tags and keys.
///
/// The structure contains the number of elements (points or polygons) before and after the change, and optionally a translation map array.\n
/// Each element in the map represents an element before the change, and its value decides what element this corresponds to after the change. This is used to keep for example point selections and vertex maps valid.
///
/// @b Example: Adding a point to a point object.
/// @code
/// VariableChanged vc;
///
/// Int32 count = op->GetPointCount(); // Get actual point count
/// vc.old_cnt = count;
/// vc.new_cnt = count+1; // Resize point count from count to count+1
///
/// // Just for adding a point at the end of the point list a map is not needed
///
/// // Send the message to all tags and keys and let them return a boolean, telling us if everything is alright
/// if (op->Message(MSG_POINTS_CHANGED, &vc))
/// {
/// 	// Now all tags and structures have reacted and resized their memory part, so the new point can be accessed
/// 	Vector* points = op->GetPointW();
/// 	if (points)
/// 		points[count] = Vector(0, 0, 0); // Set data for the new point
///
/// 	op->Message(MSG_UPDATE); // Notify change to the object
/// 	EventAdd();
/// }
/// @endcode
///
/// @b Example: Inserting a point in a point object.
/// @code
/// VariableChanged vc;
///
/// Int32 count = op->GetPointCount(); // Get actual point count
/// vc.old_cnt = count;
/// vc.new_cnt = count+1; // Resize point count from count to count+1
///
/// // Allocate a map
/// vc.map = NewMemClear(Int32, count);
/// if (vc.map != nullptr)
/// {
/// 	Int32 i, pos = 5; // pos is the index to insert the point at
///
/// 	// The points below pos stay at the same point number
/// 	for (i = 0; i <= pos; i++)
/// 		vc.map[i] = i;
///
/// 	// The points above pos are shifted 1 step
/// 	for (i = pos+1; i < count; i++)
/// 		vc.map[i] = i+1;
///
/// 	// Send the message to all tags and keys and let them return a boolean, telling us if everything is alright
/// 	if (op->Message(MSG_POINTS_CHANGED, &vc))
/// 	{
/// 		// Now all tags and structures have reacted and resized their memory part, so the new point can be accessed
/// 		Vector* points= op->GetPointW();
/// 		if (points)
/// 			points[pos] = Vector(0, 0, 0); // Set data for the new point
///
/// 		op->Message(MSG_UPDATE); // Notify change to the object
/// 		EventAdd();
/// 	}
///
/// 	DeleteMem(vc.map);
/// }
/// @endcode
struct VariableChanged
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	VariableChanged();

	Int32 old_cnt,			///< The number of elements before the change.
				new_cnt,			///< The new number of elements.
			 *map;					///< The optional translation map.
											///< @note A map element can be @ref NOTOK.
	Int32 vc_flags;			///< Flags: @enumerateEnum{VC_FLAGS}
/// @addtogroup VC_FLAGS
/// @ingroup group_enumeration
/// @{
#define VC_SAFETY					(1 << 0)			///< Set this flag to use the Safety class during changes to ensure the object does not become corrupt during low memory conditions.
#define VC_DONTCOPYDATA		(1 << 1)			///< Speed-up flag. PointObject::ResizeObject() usually copies all old data into a new bigger memory block. This flag suppresses the copying to save memory bandwidth.
																				///< @warning If this flag is set a function must handle all tags on their own. Only set it if you know what you are doing.
#define VC_DONTCLEARDATA	(1 << 2)			///< This flag prevents PointObject::ResizeObject() to clear the memory during its data initialization.
/// @}
};


/// Message struct for the @ref MSG_MULTI_DOCUMENTIMPORTED message.
struct DocumentImported
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	DocumentImported() { doc = nullptr; c4dversion = 0; fileformat = 0; gui_allowed = false; }

	BaseDocument* doc;			///< The imported document. @cinemaOwnsPointed{document}
	Int32 c4dversion;				///< The version of the imported document.
	Int32 fileformat;				///< The file format: (Set for load, merge and before/after save only. Otherwise @ref NOTOK.) @enumerateEnum{FORMAT_FILES}
	Bool gui_allowed;				///< @formatConstant{true} if a GUI (dialog) is allowed.\n
													///< NET for instance sets it to @formatConstant{false}, in which case no dialogs should be shown. For example if a Morph/XRef is not found it will inform the user; under NET this dialog should not display.
};

//----------------------------------------------------------------------------------------
/// Message struct for the @ref MSG_MULTI_MARKMATERIALS message.\n
/// This is an example of how to handle the message:
/// @code
/// Bool MyObject::Message(Int32 msg_type, void* msg_data)
/// {
/// 	switch (msg_type)
/// 	{
/// 		case MSG_MULTI_MARKMATERIALS:
/// 		{
/// 			// 'mat' is the material of my object in the link parameter MATERIAL_ID
/// 			BaseDocument* doc = GetDocument();
/// 			BaseMaterial* mat = data.GetMaterialLink(MATERIAL_ID, doc);
///
/// 			if (data) // Material translation, update my link if necessary
/// 			{
/// 				MarkMaterials* mm = static_cast<MarkMaterials*>(msg_data);
/// 				if (doc && mm->omat == mat)
/// 				{
/// 					doc->undo.InitUndo(UNDO_CHANGE_SMALL, this);
/// 					data.SetLink(MATERIAL_ID, mm->nmat);
/// 				}
/// 			}
/// 			else // Material marking, mark all my materials
/// 			{
/// 				if (mat)
/// 					mat->SetBit(BIT_MATMARK);
/// 			}
/// 		}
/// 		break;
/// 	}
///
/// 	return SUPER::Message(msg_type, msg_data);
/// }
/// @endcode
//----------------------------------------------------------------------------------------
struct MarkMaterials
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	MarkMaterials() { omat = nmat = nullptr; }

	BaseMaterial* omat;			///< Original material. @cinemaOwnsPointed{material}
	BaseMaterial* nmat;			///< New material. @cinemaOwnsPointed{material}
};

/// Message struct for the @ref MSG_DESCRIPTION_INITUNDO message.
struct DescriptionInitUndo
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	DescriptionInitUndo() { doc = nullptr; descid = nullptr; }

	BaseDocument* doc;				///< The current document. @cinemaOwnsPointed{document}
	const DescID* descid;			///< The description ID.
};

/// Message struct for the @ref MSG_DESCRIPTION_CHECKUPDATE message.
struct DescriptionCheckUpdate
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	DescriptionCheckUpdate() { doc = nullptr; drawflags = 0; descid = nullptr; }

	BaseDocument* doc;				///< The current document. @cinemaOwnsPointed{document}
	Int32 drawflags;					///< Set this to one of the draw flags: @enumerateEnum{MSG_DESCRIPTION_CHECKUPDATE_FLAGS}
	const DescID* descid;			///< The description ID.
};

/// Message struct for the @ref MSG_DESCRIPTION_VALIDATE message.
struct DescriptionValidate
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	DescriptionValidate() { flags = 0; }

	Int32 flags; ///< Unused.
};

/// Message struct for the @ref MSG_DESCRIPTION_POSTSETPARAMETER message.
struct DescriptionPostSetValue
{
	DescriptionPostSetValue() : descid(nullptr) { }

	const DescID* descid; ///< The description ID of the value set.
};

//----------------------------------------------------------------------------------------
/// Message struct for the @ref MSG_RETRIEVEPRIVATEDATA message.\n
/// For example, this message can be used to get/set exporters/importers settings:
/// @code
/// BaseList2D* exporter;
/// // Find Alembic scene saver (exporter) plugin with its ID 1028082
/// BasePlugin* abc = FindPlugin(1028082, PLUGINTYPE::SCENESAVER);
/// // If found, send MSG_RETRIEVEPRIVATEDATA to get the Alembic exporter private data
/// if (abc && abc->Message(MSG_RETRIEVEPRIVATEDATA, &exporter))
/// {
/// 	if (!exporter)
/// 		return false;
///
/// 	// Get the container data instance
/// 	BaseContainer *data = abc->GetDataInstance();
/// 	if (!data)
/// 		return false;
///
/// 	// Set Alembic export settings
/// 	data->SetBool(ABCEXPORT_HAIR, true);
/// 	data->SetBool(ABCEXPORT_PARTICLE_GEOMETRY, true);
/// 	data->SetBool(ABCEXPORT_XREFS, true);
///
/// 	SaveDocument(doc, "dir/to/save/to/filename.abc", SAVEDOCUMENTFLAGS::DONTADDTORECENTLIST, 1028082);
/// }
/// @endcode
//----------------------------------------------------------------------------------------
struct RetrievePrivateData
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	RetrievePrivateData () { flags = 0; data = nullptr; }

	Int32 flags;			///< The flags for the retrieval.
	void* data;				///< The address returned.
};

/// Message struct for the @ref MSG_MATERIALDRAGANDDROP message.
struct MaterialDragAndDrop
{
	MaterialDragAndDrop() { doc = nullptr; op = nullptr; result = nullptr; }

	BaseDocument* doc;			///< The current document. @cinemaOwnsPointed{document}
	BaseObject* op;					///< The current object. @cinemaOwnsPointed{object}
	BaseTag* result;				///< If you choose to create a tag of your own, point this pointer to it. @C4D will create the undo and activate the tag but you still have to insert the tag manually onto the object.
};

/// Message struct for the @ref MSG_GETREALCAMERADATA message.
struct GetRealCameraData
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	GetRealCameraData() : res(nullptr) { }

	BaseObject* res;			///< Set a camera object to provide a real camera for a generator.
};

/// Message struct for the @ref MSG_GETREALTAGDATA message. @since R18
struct GetRealTagData
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	GetRealTagData() : res(nullptr) { }

	BaseTag* res;			///< Set a tag object to provide a real tag for a virtual "generator" tag.
};

/// @addtogroup MULTILINEEDITTEXTMESSAGEFLAGS
/// @ingroup group_enumeration
/// @{
enum class MULTILINEEDITTEXTMESSAGEFLAGS
{
	NONE	= 0,						///< No flags.
	SET		= (1 << 0)			///< Set.
} MAXON_ENUM_FLAGS(MULTILINEEDITTEXTMESSAGEFLAGS);
/// @}

/// Message struct for the @ref MSG_DESCRIPTION_TEXT_STOREUNDO and @ref MSG_DESCRIPTION_TEXT_RESTOREUNDO messages.
struct MultilineEditTextStoreUndo
{
	BaseContainer										undoData;			///< The undo data container. @see MULTLINEEDITTEXT_UNDO_CONTAINER
	const DescID*										id;						///< The description ID for the Multiline Edit Text.
	MULTILINEEDITTEXTMESSAGEFLAGS		flags;				///< The flags: @enumerateEnum{MULTILINEEDITTEXTMESSAGEFLAGS}
};


/// @addtogroup DRAGANDDROP_FLAG
/// @ingroup group_enumeration
/// @{
#define DRAGANDDROP_FLAG_RECEIVE		1			///< Receive.
#define DRAGANDDROP_FLAG_DROP				2			///< Drop.
#define DRAGANDDROP_FLAG_ACCEPT			4			///< Accept.
#define DRAGANDDROP_FLAG_MSGVALID		8			///< If this flag is set the DragAndDrop::msg container becomes valid.

#define DRAGANDDROP_FLAG_FORBID		(1 << 4)			///< Set by the user to forbid drag and drop.
#define DRAGANDDROP_FLAG_SOURCE		(1 << 5)			///< Drag and drop message is send to the source objects (objects that were dragged).
#define DRAGANDDROP_FLAG_BEFORE		(1 << 6)			///< Drag and drop position in a tree view.
#define DRAGANDDROP_FLAG_AFTER		(1 << 7)			///< Drag and drop position in a tree view.
#define DRAGANDDROP_FLAG_LEFT			(1 << 8)			///< Drag and drop position in a tree view.
#define DRAGANDDROP_FLAG_RIGHT		(1 << 9)			///< Drag and drop position in a tree view.
/// @}

/// @addtogroup OBJSELDATA_FLAG
/// @ingroup group_containerid
/// @{
/// @markPrivate
#define OBJSELDATA_FLAG_QUERYSELECTION	1
#define OBJSELDATA_FLAG_HASSELECTION		2
/// @}

/// Message struct for the @ref MSG_DRAGANDDROP message.
struct DragAndDrop
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	DragAndDrop() { doc = nullptr; sender = nullptr; flags = 0; type = 0; data = nullptr; x = y = 0; msg = nullptr; result = 0; }

	BaseDocument* doc;						///< The current document. @cinemaOwnsPointed{document}
	C4DAtom* sender;							///< This is where the drag comes from. A scene hook for instance would get the pointer to the BaseDraw that had the item dragged into it.
	UInt32 flags;									///< Flags: @enumerateEnum{DRAGANDDROP_FLAG}
																///< @note Should be set if the message has been accepted.
	Int32 type;										///< The drag type: @link DRAGTYPE_FILES DRAGTYPE@endlink
	void* data;										///< The pointer to the dragged elements. Depends on the drag @ref type.
	Int32 x,											///< The X position where the dragged object was released.
				y;											///< The Y position where the dragged object was released.
	const BaseContainer* msg;			///< This container becomes valid if @ref DRAGANDDROP_FLAG_MSGVALID is set so items like @ref BFM_INPUT_QUALIFIER are available.
	Int32 result;									///< Currently unused.
};

/// Message struct for the @ref MSG_GETSELECTION message. @markPrivate
struct ObjectSelectionData
{
	ObjectSelectionData() { doc = nullptr; table = nullptr; flags = 0; }

	BaseDocument* doc;
	InclusionTable* table;
	UInt32 flags;
};

/// Message struct for the @ref MSG_MULTI_RENDERNOTIFICATION message.
struct RenderNotificationData
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	RenderNotificationData() { doc = nullptr; start = animated = external = false; render = nullptr; flags = RENDERFLAGS::NONE; }

	BaseDocument* doc;			///< The current document. @cinemaOwnsPointed{document}
	Bool start,							///< Determines if this is a start (@formatConstant{true}) or stop (@formatConstant{false}) notification. Stop notifications are only sent if the document will not be deleted, which more or less only happens if there is an editor render.
			 animated,					///< Determines if this is an animation sequence being rendered.
			 external;					///< @trueIfOtherwiseFalse{the rendering is not in the editor view}
	Render* render;					///< A pointer to the render. @cinemaOwnsPointed{render}
	RENDERFLAGS	flags;			///< A combination of the render flags: @enumerateEnum{RENDERFLAGS}
};

/// Message struct for the @ref MSG_DOCUMENTINFO_TYPE_PASTE and @ref MSG_DOCUMENTINFO_TYPE_COPY messages. @markPrivate
struct DocumentInfoClipData
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	DocumentInfoClipData() { arr = nullptr; trans = nullptr; bcdata = nullptr; }

	const AtomArray* arr;
	AliasTrans* trans;
	BaseContainer* bcdata;
};

/// Message struct for the @ref MSG_DOCUMENTINFO_TYPE_MAKEPROJECT message.
struct DocumentInfoMakeProj
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	DocumentInfoMakeProj()
	{
		allowCopy = false;
		allowGUI = false;
	}

	Filename sfile,			///< The source file.
					 dfile;			///< The destination file.
	Bool allowCopy;			///< @trueOtherwiseFalse{to allow copy}
	Bool allowGUI;			///< @trueOtherwiseFalse{to allow GUI}
};

/// Message struct for the @ref MSG_DOCUMENTINFO message.
struct DocumentInfoData
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	DocumentInfoData() : type(0), fileformat(0), doc(nullptr), bl(nullptr), gui_allowed(false), data(nullptr) { }

	Int32 type;							///< The message type: @enumerateEnum{MSG_DOCUMENTINFO_TYPE}
	Int32 fileformat;				///< The file format: (Set for load, merge and before/after save only. Otherwise @ref NOTOK.) @enumerateEnum{FORMAT_FILES}
	BaseDocument* doc;			///< The current document. @cinemaOwnsPointed{document}
	Filename filename;			///< The document filename.
													///< @b Note This is not always the same as the filename returned by BaseDocument::GetDocumentPath().\n
													///< e.g. for @ref MSG_DOCUMENTINFO_TYPE_SAVE_BEFORE BaseDocument::GetDocumentPath() still contains the old path whereas @ref filename designates the real file.
	BaseList2D* bl;					///< The object/tag/material that got inserted. It is used if @ref type is of one of the following values:
													///< - @ref MSG_DOCUMENTINFO_TYPE_OBJECT_INSERT
													///< - @ref MSG_DOCUMENTINFO_TYPE_TAG_INSERT
													///< - @ref MSG_DOCUMENTINFO_TYPE_MATERIAL_INSERT
	Bool gui_allowed;				///< It is set to @formatConstant{true} if a GUI (dialog) is allowed.\n
													///< @note NET for instance sets it to @formatConstant{false}, in which case no dialogs should be shown. For example if a Morph/XRef is not found it will inform the user, under NET this dialog should not display.
	void* data;							///< A pointer to message data structure. Depends on @ref type.
};

class AssetEntry
{
public:
	Filename				_filename;						///< The asset filename.
	String					_assetname;						///< The asset name.
	Int32						_channelId;						///< The asset channel ID.
	Bool						_netRequestOnDemand;	///< NET request on demand. @see AssetData::Add()
	BaseList2D*			_owner;								///< The owner object.
	Bool						_exists;							///< If the asset could be found.
	Int32						_paramId;							///< The parameter ID.
	maxon::CString	_nodePath;						///< The node path of the port the asset is assigned to in case of a nimbus material.
	maxon::Id				_nodeSpace;						///< The node space id in case of a nimbus material.
	BaseOverride*		_override;						///< The override containing the owner of the asset if it's not in the current take.

	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] filename						The asset filename.
	/// @param[in] assetname					The asset name.
	/// @param[in] channelId					The asset channel ID.
	/// @param[in] netRequestOnDemand	NET request on demand. @see AssetData::Add()
	//----------------------------------------------------------------------------------------
	AssetEntry(const Filename& filename, const maxon::String& assetname, Int32 channelId, Bool netRequestOnDemand) : _filename(filename), _assetname(assetname), _channelId(channelId), _netRequestOnDemand(netRequestOnDemand), _owner(nullptr), _exists(false), _paramId(NOTOK), _nodePath(maxon::String()), _override(nullptr) { }
	AssetEntry(const Filename& filename, const maxon::String& assetname, Int32 channelId, Bool netRequestOnDemand, BaseList2D* owner, Bool exists, Int32 paramId, const maxon::CString& nodePath, const maxon::Id& nodeSpace, BaseOverride* parentOverride) : _filename(filename), _assetname(assetname), _channelId(channelId), _netRequestOnDemand(netRequestOnDemand), _owner(owner), _exists(exists), _paramId(paramId), _nodePath(nodePath), _nodeSpace(nodeSpace), _override(parentOverride) { }
};

struct AssetData
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] doc								The document.
	/// @param[in] rs									@markPrivate
	/// @param[in] flags							The asset data flags: @enumerateEnum{ASSETDATA_FLAG}
	//----------------------------------------------------------------------------------------
	AssetData(BaseDocument* doc, RootTextureString* rs, ASSETDATA_FLAG flags) : _doc(doc), _rs(rs), _flags(flags), _override(nullptr), _channelId(NOTOK) { }

	BaseDocument*				_doc = nullptr;									///< The document.
	RootTextureString*	_rs = nullptr;									///< @markPrivate
	ASSETDATA_FLAG			_flags = ASSETDATA_FLAG::NONE;	///< The asset data flags: @enumerateEnum{ASSETDATA_FLAG}
	BaseOverride*				_override = nullptr;						///< @markPrivate
	Int32								_channelId = NOTOK;							///< @markPrivate

	//----------------------------------------------------------------------------------------
	/// Call this function from @ref MSG_GETALLASSETS to add missing textures or file strings, if you have additional references in a shader.
	/// @param[in] fn									The filename to add.
	/// @param[in] bl									The shader reporting the missing name.
	/// @param[in] parameterId				The ID of the parameter in the BaseContainer the asset is assigned to.
	/// @param[in] netRequestOnDemand	NET request on demand.
	///																@note When @ref MSG_GETALLASSETS is send around all assets will be collected from a scene. So every node in the scene will be asked if there is an external file.\n
	///																This happens with <i>Save project</i> or when the <i>Team Render</i> asks for all assets to send it to all clients.\n
	///																In case the message is sent from <i>Team Render</i>, AssetEntry::_netRequestOnDemand means that the file can be requested from the client to the server when needed or if the client must download this asset before it starts rendering.\n
	///																For instance, the scene itself is set with @formatConstant{false} as it must always exist before it starts rendering and for the most standard textures it is set to @formatConstant{true}.
	/// @param[in] channelIndex				@markPrivate
	/// @param[in] nodePath						The node path of the port in case of a node material.
	/// @param[in] nodeSpace					The node space in case of a node material.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Add(const Filename& fn, BaseList2D* bl, Int32 parameterId = NOTOK, Bool netRequestOnDemand = false, Int32 channelIndex = NOTOK, const maxon::CString& nodePath = maxon::GetZeroRef<maxon::CString>(), const maxon::Id& nodeSpace = maxon::GetZeroRef<maxon::Id>());

	//----------------------------------------------------------------------------------------
	/// Returns whether a filename has already been added before.
	/// @param[in] fn									The filename to add.
	/// @param[in] bl									The shader containing the filename.
	/// @return												True if it has been added before.
	//----------------------------------------------------------------------------------------
	Bool Find(const Filename& fn, BaseList2D* bl);
};

/// Message struct for the @ref MSG_XREFINIT message.
struct XrefInitData
{
	XrefInitData(BaseDocument* refDoc, BaseList2D* refNode, const maxon::String& refName, const maxon::String& separator) : _refDoc(refDoc), _refNode(refNode), _refName(refName), _separator(separator) { }

	BaseDocument* _refDoc;				///< The document where the node is referenced.
	BaseList2D*		_refNode;				///< The referenced node.
	String				_refName;				///< The reference name (also called namespace).
	String				_separator;			///< The separator string.
};

/// @addtogroup MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT
/// @ingroup group_enumeration
/// @{
/// Enum for the @ref MSG_DOCUMENTINFO_TYPE_BEFOREMERGE message. @em data points to a @ref MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT value.
enum class MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT
{
	CANCEL,				///< Allows to cancel the merge.
	MERGE,				///< Default, as before, just merge.
	NEWSCENE			///< Overwrites the merge flag and loads the scene as opened with load.\n
								///< In that case the message @ref MSG_DOCUMENTINFO_TYPE_MERGE will not be send to the original document but a @ref MSG_DOCUMENTINFO_TYPE_LOAD message instead.
} MAXON_ENUM_LIST(MSG_DOCUMENTINFO_TYPE_BEFOREMERGE_RESULT);
/// @}


/// Message struct for the @ref MSG_GETCUSTOMICON message.
struct GetCustomIconData
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	GetCustomIconData() { dat = nullptr; filled = false; }

	IconData* dat;			///< The icon data.
											///< @note This might already have been setup. In that case  directly render into this bitmap. Alternately, change the bitmap pointer/offsets/dimensions.
	Bool filled;				///< Set this to @formatConstant{true} if the icon data @ref dat was changed or set.
};

/// Message struct for the @ref MSG_DESCRIPTION_GETINLINEOBJECT message.
struct DescriptionInlineObjectMsg
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	DescriptionInlineObjectMsg() : id(nullptr), objects(nullptr) { }

	const DescID* id;				///< The description ID of the object.
	AtomArray* objects;			///< Return the linked objects.
};

/// Message struct for the @ref MSG_SCALEDOCUMENT message.
struct MessageScaleDocument
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	MessageScaleDocument() { scale = 1.0; }

	Float scale;			///< The merged document's scale.
};

/// Message struct for the @ref MSG_FILTER message.
struct MessageFilter
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	MessageFilter() { type = 0; route = MULTIMSG_ROUTE::NONE; data = nullptr; }

	Int32 type;								///< The message type: @enumerateEnum{MSG}
	MULTIMSG_ROUTE route;			///< Flags: @enumerateEnum{MULTIMSG_ROUTE}
	void* data;								///< The message data. Depends on the message @ref type.
};


/// Hold information about which node types a node contains.
/// @see GeListNode::GetBranchInfo()
struct BranchInfo
{
	GeListHead*			head;	 ///< Either a GeListNode or a GeListHead for the branch, depending on @ref flags.
	String					name;	 ///< The human readable name of the branch. (Currently not used.)
	Int32						id;		 ///< The base ID of the branch. For example @em VPbase, @em Mbase or @em Obase.
	BRANCHINFOFLAGS flags; ///< Flags for this branch: @enumerateEnum{BRANCHINFOFLAGS}
};

//----------------------------------------------------------------------------------------
/// Message struct for the @ref MSG_MATERIAL_OVERRIDE message.
/// @since R17.032
//----------------------------------------------------------------------------------------
struct OverrideMaterial
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	OverrideMaterial(BaseDocument* doc = nullptr, BaseContainer* renderDataBc = nullptr)
	{
		_doc = doc;
		_renderDataBc = renderDataBc;
		_resultMaterial = nullptr;
	}

	BaseDocument*		_doc;									///< The document to render.
	BaseContainer*	_renderDataBc;				///< The render data container.
	BaseList2D*			_resultMaterial;			///< The result material created in the message. Assign @formatConstant{nullptr} if the material has to be replaced as by default by @C4D.
};

/// @markPrivate
#define MSG_NOTIFY_EVENT 1024639

/// @markPrivate
class NotifyEventMsg
{
public:
	NotifyEventMsg() { msg_id = 0; msg_data = nullptr; }

	Int32 msg_id;
	void* msg_data;
};

/// @markPrivate
class NotifyEventCopy
{
public:
	NotifyEventCopy() { cpy_dst = nullptr; cpy_flags = COPYFLAGS::NONE; cpy_trans = nullptr; }

	BaseList2D* cpy_dst;
	COPYFLAGS cpy_flags;
	AliasTrans* cpy_trans;
};

/// @markPrivate
class NotifyEventData
{
public:
	NotifyEventData() { bl = nullptr; eventid = NOTIFY_EVENT::NONE; user_data = nullptr; event_data = nullptr; doc = nullptr; }

	BaseDocument* doc;
	BaseList2D* bl;
	NOTIFY_EVENT eventid;
	const BaseContainer* user_data;
	void* event_data;
};

static const Int MSG_PROPERTYPROPAGATION_OVERRIDE = 310006003; ///< @markPrivate

//----------------------------------------------------------------------------------------
/// Message structure for the @ref MSG_PROPERTYPROPAGATION_OVERRIDE message.
/// @markPrivate
/// @since R19
//----------------------------------------------------------------------------------------
class PropertyPropagationOverrideData
{
public:
	const DescID*	did = nullptr;
	Bool					isOverridden = false;
};

//----------------------------------------------------------------------------------------
/// Message structure for the @ref MSG_GETCUSTOMICON_SETTINGS message.
/// @markPrivate
/// @since R21
//----------------------------------------------------------------------------------------
struct CustomIconSettings
{
	String _iconFileId;											///< Custom bitmap file path or icon ID
	Int32 _colorMode = 0;										///< Color mode: 0: none, 1: custom, >=2: special cases
	maxon::Color _customColor;									///< Custom color used if _colorMode == 1;
	maxon::BaseArray<maxon::Color> _specialColors;				///< Special colors (e.g. Light Color for light object)
	Int32 _defaultIconId = NOTOK;								///< Icon Id used if no custom bitmap path / icon ID
	IconData* _customIcon = nullptr;							///< Custom icon used as default (more priority than _defaultIconId)
	Bool _fillDefault = false;									///<  If true, CustomIconData will be filled always. Set to true only if you provide a _customIcon IconData or an icon id different than default, otherwise just leave it false.
	Bool _colorizeContrastMode = true;							///< If true, icon bitmap will be inverted with dark colors for better readability.
	Float _colorizeContrastModeMaxBrightnessThreshold = 1.0;	///< Brightness values greater than this value will be considered as full brightness (1.0)
};


#ifndef __API_INTERN__

//-------------------------------------------------------------------------------------------------
/// A unique marker that identifies an object.
//-------------------------------------------------------------------------------------------------
class GeMarker
{
private:
	GeMarker();
	~GeMarker();

public:
	//----------------------------------------------------------------------------------------
	/// @allocatesA{marker}
	/// @return												@allocReturn{marker}
	//----------------------------------------------------------------------------------------
	static GeMarker* Alloc() { return (*C4DOS.At->GeMarkerAlloc)(); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{markers}
	///
	/// @param[in,out] obj						@theToDestruct{marker}
	//----------------------------------------------------------------------------------------
	static void Free(GeMarker*& obj) { (*C4DOS.At->GeMarkerFree)(obj); }

	//----------------------------------------------------------------------------------------
	/// Checks if the marker is empty.
	/// @return												@trueIfOtherwiseFalse{the marker has been set}
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const { return AtCall(IsPopulated) (); }

	//----------------------------------------------------------------------------------------
	/// Checks if two markers are equal.
	/// @param[in] m									The marker to compare with.
	/// @return												@trueIfOtherwiseFalse{both markers are equal}
	//----------------------------------------------------------------------------------------
	Bool IsEqual(const GeMarker& m) const { return AtCall(IsEqual) (m); }

	//----------------------------------------------------------------------------------------
	/// Compares two markers.
	/// @param[in] m									The marker to compare with.
	/// @return												@em 0 if identical and @em !=0 if different.
	//----------------------------------------------------------------------------------------
	Int32 Compare(const GeMarker& m) const { return AtCall(Compare) (m); }

	//----------------------------------------------------------------------------------------
	/// Sets a marker the same as another marker.
	/// @param[in] m									The new marker.
	//----------------------------------------------------------------------------------------
	void Set(const GeMarker& m) { AtCall(GeMarkerSet) (m); }

	//----------------------------------------------------------------------------------------
	/// Reads the marker from a hyper file.
	/// @param[in] hf									The hyper file to read from. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{the marker was read}
	//----------------------------------------------------------------------------------------
	Bool Read(HyperFile* hf) { return AtCall(GeMarkerRead) (hf); }

	//----------------------------------------------------------------------------------------
	/// Writes the marker to a hyper file.
	/// @param[in] hf									The hyper file to write to. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{the marker was written}
	//----------------------------------------------------------------------------------------
	Bool Write(HyperFile* hf) const { return AtCall(GeMarkerWrite) (hf); }

	//----------------------------------------------------------------------------------------
	/// Gets a memory pointer and the size of the memory block.\n
	/// Used for instance to create a checksum.
	/// @note The memory must not be freed.
	/// @param[out] data							The memory pointer.
	/// @param[out] size							The size of the memory block.
	//----------------------------------------------------------------------------------------
	void GetMemory(void*& data, Int32& size) const { AtCall(GeMarkerGetMemory) (data, size); }
};

//-------------------------------------------------------------------------------------------------
/// The base class of many classes within the API.\n
/// Represents an object that can be read from and written to disk, copied and that has a description for the Attribute Manager.
/// @see AtomArray
//-------------------------------------------------------------------------------------------------
class C4DAtom
{
private:
	C4DAtom();
	~C4DAtom();

public:

	/// @name Type
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the type of the atom.
	/// @warning This must be used to make sure that the derived object is really of the right type before casting it and accessing its members.
	/// @note Plugin nodes return their unique plugin IDs.
	/// @return												The type, for example @em Ocube.
	//----------------------------------------------------------------------------------------
	Int32 GetType() const { return AtCall(GetType) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the real type of the atom. This is similar to GetType(), but for multinodes the ID of the last linked part is returned.\n
	/// E.g. @em XPresso nodes have the type @ref ID_GV_GROUPDATA or @ref ID_GV_NODEDATA but GetRealType() returns the ID of the operator.
	/// @return												The type, for example @em Ocube.
	//----------------------------------------------------------------------------------------
	Int32 GetRealType() const { return AtCall(GetRealType) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the atoms unique disk type ID.
	/// @note Normally this is the same as GetType() but there are exceptions.
	/// @return												The type, for example @em Ocube.
	//----------------------------------------------------------------------------------------
	Int32 GetDiskType() const { return C4DOS.Bl->GetDiskType(this); }

	//----------------------------------------------------------------------------------------
	/// Checks if the atom is an instance of a base type.
	/// @note	To check if an object is a spline, check BaseList2D::GetInfo() & @ref OBJECT_ISSPLINE instead.\n
	///				Be aware that generators like the Cloner or Alembic objects have the flag @ref OBJECT_ISSPLINE set at registration,
	///				but calling ToSpline() would not return a valid SplineObject.\n
	///				In the case of an Alembic generator representing a spline, get the cache and check the type of it.
	/// @param[in] id									The base type ID, for example @em Obase.
	/// @return												@trueIfOtherwiseFalse{the atom is an instance of the given type @formatParam{id}}
	//----------------------------------------------------------------------------------------
	Bool IsInstanceOf(Int32 id) const { return AtCall(IsInstanceOf) (id); }

	//----------------------------------------------------------------------------------------
	/// Returns the base type of the atom; e.g. @em Obase for objects , @em Tbase for tags etc.
	/// @return												The base type.
	//----------------------------------------------------------------------------------------
	Int32 GetClassification() const { return AtCall(GetClassification) (); }

	/// @}

	/// @name Message
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sends a message to the atom only.
	/// @note	Some notification messages are automatically passed along to branches: @ref MSG_POINTS_CHANGED, @ref MSG_POLYGONS_CHANGED and @ref MSG_SEGMENTS_CHANGED.\n
	///				This is for convenience and historical reasons.
	/// @param[in] type								The message type, one of the following: @enumerateEnum{MSG}
	/// @param[in,out] data						The message data. @senderOwnsPointed{data}
	/// @return												Depends on the message @formatParam{type}.
	//----------------------------------------------------------------------------------------
	Bool Message(Int32 type, void* data = nullptr) { return AtCall(Message) (type, data); }


	//----------------------------------------------------------------------------------------
	/// Sends a message to the atom and to its children, parents or branches, depending on @formatParam{flags}.
	/// @param[in] flags							A combination of the following flags: @enumerateEnum{MULTIMSG_ROUTE}
	/// @param[in] type								The message type, one of the following types: @enumerateEnum{MSG}
	/// @param[in,out] data						The message data. @senderOwnsPointed{data}
	/// @return												Depends on the message @formatParam{type}.
	//----------------------------------------------------------------------------------------
	Bool MultiMessage(MULTIMSG_ROUTE flags, Int32 type, void* data) { return AtCall(MultiMessage) (flags, type, data); }

	/// @}

	/// @name Copy
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves a copy of the atom.
	/// @param[in] flags							Flags for the clone: @enumerateEnum{COPYFLAGS}
	/// @param[in] trn								An alias translator for the operation. Can be @formatConstant{nullptr}. @callerOwnsPointed{object}
	/// @return												The cloned atom. @callerOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	C4DAtom* GetClone(COPYFLAGS flags, AliasTrans* trn) { return AtCall(GetClone) (flags, trn); }

	//----------------------------------------------------------------------------------------
	/// Copies all values from @c *this to @formatParam{*dst}.
	/// @warning The atoms must be of the same type.
	/// @param[out] dst								The destination. @callerOwnsPointed{object}
	/// @param[in] flags							Flags for the copy: @enumerateEnum{COPYFLAGS}
	/// @param[in] trn								An alias translator for the operation. Can be @formatConstant{nullptr}. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{the atom was copied}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(C4DAtom* dst, COPYFLAGS flags, AliasTrans* trn) { return AtCall(CopyTo) (dst, flags, trn); }

	/// @}

	/// @name Read/Write
	/// @{

	//----------------------------------------------------------------------------------------
	/// Reads the atom from a HyperFile, manually specifying @formatParam{id} and disk @formatParam{level}.
	/// @note	This is the function to use if the hyper has been opened manually and the object is read separately.
	///				If reading within a plugin function where @C4D has passed the hyper file use ReadObject().
	/// @note Read(), Write(), ReadObject() and WriteObject() are generally not recommended for plugins.
	/// @param[in] hf									The hyper file to read from. @callerOwnsPointed{object}
	/// @param[in] id									The ID of the atom to read.
	/// @param[in] level							The disk level of the atom to read.
	/// @return												@trueIfOtherwiseFalse{the atom was read}
	//----------------------------------------------------------------------------------------
	Bool Read(HyperFile* hf, Int32 id, Int32 level);

	//----------------------------------------------------------------------------------------
	/// Writes the atom to a HyperFile.
	/// @note	This is the function to use if the hyper has been opened manually and the object is written separately.
	///				If writing within a plugin function where @C4D has passed the hyper file use WriteObject().
	/// @warning Read(), Write(), ReadObject() and WriteObject() are generally not recommended for plugins.
	/// @param[in] hf									The hyper file to write to. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{the atom was written}
	//----------------------------------------------------------------------------------------
	Bool Write(HyperFile* hf);

	//----------------------------------------------------------------------------------------
	/// Reads the atom from a HyperFile within another read operation.
	/// @note This is the function to use where @C4D has passed the hyper file, for example in a plugin hook. Otherwise use Read().
	/// @warning Read(), Write(), ReadObject() and WriteObject() are generally not recommended for plugins.
	/// @param[in] hf									The hyper file to read from. @callerOwnsPointed{object}
	/// @param[in] readheader					Normally @formatConstant{true}. Should only be @formatConstant{false} if the file header is manually read.
	/// @return												@trueIfOtherwiseFalse{the atom was read}
	//----------------------------------------------------------------------------------------
	Bool ReadObject(HyperFile* hf, Bool readheader);

	//----------------------------------------------------------------------------------------
	/// Writes the atom to a HyperFile, within another write operation.
	/// @note This is the function to use where @C4D has passed the hyper file, for example in a plugin hook. Otherwise use Write().
	/// @warning Read(), Write(), ReadObject() and WriteObject() are generally not recommended for plugins.
	/// @param[in] hf									The hyper file to write to. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{the atom was written}
	//----------------------------------------------------------------------------------------
	Bool WriteObject(HyperFile* hf);

	/// @}

	/// @name Description
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the description for the atom.
	/// @param[out] description				Filled with the atom's description. @callerOwnsPointed{object}
	/// @param[in] flags							Flags: @enumerateEnum{DESCFLAGS_DESC}
	/// @return												@trueIfOtherwiseFalse{the description was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetDescription(Description* description, DESCFLAGS_DESC flags);

	//----------------------------------------------------------------------------------------
	/// Gets a parameter of the atom.
	/// @param[in] id									The ID of the parameter.
	/// @param[out] t_data						Assigned the parameter's data.
	/// @param[in] flags							Flags: @enumerateEnum{DESCFLAGS_GET}
	/// @return												@trueIfOtherwiseFalse{the parameter was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetParameter(const DescID& id, GeData& t_data, DESCFLAGS_GET flags);

	//----------------------------------------------------------------------------------------
	/// Sets a parameter of the atom.
	/// @param[in] id									The ID of the parameter.
	/// @param[in] t_data							The data to set.
	/// @param[in] flags							Flags: @enumerateEnum{DESCFLAGS_SET}
	/// @return												@trueIfOtherwiseFalse{the parameter was set}
	//----------------------------------------------------------------------------------------
	Bool SetParameter(const DescID& id, const GeData& t_data, DESCFLAGS_SET flags);


	//----------------------------------------------------------------------------------------
	/// Gets the dynamic description of the atom. (Also known as the user data part of the Attribute Manager.)
	/// @return												The dynamic description. The atom owns the pointed object.
	//----------------------------------------------------------------------------------------
	DynamicDescription* GetDynamicDescription();

	//----------------------------------------------------------------------------------------
	/// Checks if a description parameter should be disabled or enabled.
	/// @param[in] id									The ID of the parameter.
	/// @param[out] t_data						Assigned the current data.
	/// @param[in] flags							Flags: @enumerateEnum{DESCFLAGS_ENABLE}
	/// @param[out] itemdesc					The parameter's description, encoded to a container as described in Description.
	/// @return												@trueIfOtherwiseFalse{the parameter should be enabled}
	//----------------------------------------------------------------------------------------
	Bool GetEnabling(const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);

	//----------------------------------------------------------------------------------------
	/// Redirects description IDs between nodes.
	/// @param[in] id									The description ID to redirect.
	/// @param[in] res_id							The target description ID.
	/// @param[in] res_at							The target node.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool TranslateDescID(const DescID& id, DescID& res_id, C4DAtom*& res_at);

	/// @}

	/// @name Dirty Flags
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the dirty checksum for the object. This can be used to check if the object has been changed.
	/// @see GetHDirty()
	/// @param[in] flags							Flags: @enumerateEnum{DIRTYFLAGS}
	/// @return												The dirty checksum.
	//----------------------------------------------------------------------------------------
	UInt32 GetDirty(DIRTYFLAGS flags) const { return C4DOS.Bo->GetDirty(this, flags); }

	//----------------------------------------------------------------------------------------
	/// Sets the dirty checksum, the one returned by GetDirty().
	/// @see SetHDirty()
	/// @param[in] flags							Flags: @enumerateEnum{DIRTYFLAGS}
	//----------------------------------------------------------------------------------------
	void SetDirty(DIRTYFLAGS flags) { C4DOS.Bo->SetDirty(this, flags); }


	//----------------------------------------------------------------------------------------
	/// Gets the dirty bits for the specified mask.
	/// @see GetDirty().
	/// @param[in] mask								Mask: @enumerateEnum{HDIRTYFLAGS}
	/// @return												The dirty bits.
	//----------------------------------------------------------------------------------------
	UInt32 GetHDirty(HDIRTYFLAGS mask) const { return BoCall(GetHDirty) (mask); }

	//----------------------------------------------------------------------------------------
	/// Sets the dirty bits, the one returned by GetHDirty().
	/// @see SetDirty().
	/// @param[in] mask								Mask: @enumerateEnum{HDIRTYFLAGS}
	//----------------------------------------------------------------------------------------
	void SetHDirty(HDIRTYFLAGS mask) { BoCall(SetHDirty) (mask); }

	/// @}
};


//-------------------------------------------------------------------------------------------------
/// Dummy class for C4DAtom objects that can be pointed to by BaseLink objects.
//-------------------------------------------------------------------------------------------------
class C4DAtomGoal : public C4DAtom
{
private:
	C4DAtomGoal();
	~C4DAtomGoal();
};


//-------------------------------------------------------------------------------------------------
/// An array of C4DAtom objects.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class AtomArray
{
private:
	AtomArray();
	~AtomArray();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesAN{atom array}
	/// @return												@allocReturn{atom array}
	//----------------------------------------------------------------------------------------
	static AtomArray* Alloc() { return (*C4DOS.At->AtomArrayAlloc)(); }

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{atom arrays}
	/// @param[in,out] obj						@theToDestruct{atom array}
	//----------------------------------------------------------------------------------------
	static void Free(AtomArray*& obj) { (*C4DOS.At->AtomArrayFree)(obj); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the number of atoms in the array.
	/// @return												The atom count.
	//----------------------------------------------------------------------------------------
	Int32 GetCount() const { return AtCall(GetCount) (); }

	//----------------------------------------------------------------------------------------
	/// Checks how many elements in the array match @formatParam{type} and/or @formatParam{instance}.
	/// @param[in] type								Checked against C4DAtom::GetType(). Pass @ref NOTOK to ignore this test.
	/// @param[in] instance						Checked against C4DAtom::IsInstanceOf(). Pass @ref NOTOK to ignore this test.
	/// @return												The number of matches.
	//----------------------------------------------------------------------------------------
	Int32 GetCount(Int32 type, Int32 instance) const { return AtCall(AAGetCountTI) (type, instance); }

	//----------------------------------------------------------------------------------------
	/// Gets the atom at the position @formatParam{idx} in the array.
	/// @param[in] idx								The index. Must be between @em 0 and GetCount().
	/// @return												The @formatParam{idx}-th atom in the array. @theOwnsPointed{atom array,object}
	//----------------------------------------------------------------------------------------
	C4DAtom* GetIndex(Int32 idx) const { return AtCall(GetIndex) (idx); }

	//----------------------------------------------------------------------------------------
	/// Appends @formatParam{obj} to the array.
	/// @param[in] obj								The atom to append to the array. Only the pointer is stored; the actual ownership remains with the caller.
	/// @return												@trueIfOtherwiseFalse{the atom was appended}
	//----------------------------------------------------------------------------------------
	Bool Append(C4DAtom* obj) { return AtCall(Append) (obj); }

	//-------------------------------------------------------------------------------------------------
	/// Clears the atom array.
	//-------------------------------------------------------------------------------------------------
	void Flush() { AtCall(Flush) (); }

	//----------------------------------------------------------------------------------------
	/// Removes @formatParam{obj} from the array.
	/// @param[in] obj								The atom to remove from the array. Only the pointer is removed; the object is not freed.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Remove(C4DAtom* obj) { return AtCall(AARemove) (obj); }

	/// @}

	/// @name Copy
	/// @{

	//----------------------------------------------------------------------------------------
	/// Copies all atoms in @c *this to @formatParam{*dest}.
	/// @param[out] dest							The destination array. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{the atom array was copied}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(AtomArray* dest) const { return AtCall(AACopyTo) (dest); }

	//----------------------------------------------------------------------------------------
	/// Copies all atoms in @c *this to @formatParam{*dest} filtered by @formatParam{type} and/or @formatParam{instance}.
	/// @param[out] dest							The destination array. @callerOwnsPointed{object}
	/// @param[in] type								Checked against C4DAtom::GetType(). Pass @ref NOTOK to ignore this test.
	/// @param[in] instance						Checked against C4DAtom::IsInstanceOf(). Pass @ref NOTOK to ignore this test.
	/// @param[in] generators					Used to filter generators.
	/// @return												@trueIfOtherwiseFalse{the atom array was copied}
	//----------------------------------------------------------------------------------------
	Bool CopyToFilter(AtomArray* dest, Int32 type, Int32 instance, Int32 generators = 1) const { return AtCall(AACopyToFilter) (dest, type, instance, generators); }

	/// @}

	/// @name User ID and Data
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the user ID of the array.
	/// @return												This array's user ID.
	//----------------------------------------------------------------------------------------
	Int32 GetUserID() const { return AtCall(AAGetUserID) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the user ID of the array to @formatParam{t_userid}.
	/// @param[in] t_userid						The new user ID.
	//----------------------------------------------------------------------------------------
	void SetUserID(Int32 t_userid) { AtCall(AASetUserID) (t_userid); }

	//----------------------------------------------------------------------------------------
	/// Gets the user data pointer stored with the array.
	/// @return												The user data pointer. Not managed by the atom array.
	//----------------------------------------------------------------------------------------
	void* GetUserData() const { return AtCall(AAGetUserData) (); }

	//----------------------------------------------------------------------------------------
	/// Store a user data pointer with the array.
	/// @param[in] t_userdata					The new user data pointer. Not manager by the atom array.
	//----------------------------------------------------------------------------------------
	void SetUserData(void* t_userdata) { AtCall(AASetUserData) (t_userdata); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// The preferred object is the one to use for operations that require a single object.\n
	/// For example, if the user drags many objects to a link field this is used.
	/// @note	This is not always set. In that case for example use the first object.
	/// @return												The preferred object to use for single object actions. @theOwnsPointed{array, object}.
	//----------------------------------------------------------------------------------------
	C4DAtom* GetPreferred() const { return AtCall(AAGetPreferred) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the preferred object.
	/// @see GetPreferred()
	/// @param[in] t_preferred				The new preferred object. Must already be in the array.
	//----------------------------------------------------------------------------------------
	void SetPreferred(C4DAtom* t_preferred) { AtCall(AASetPreferred) (t_preferred); }

	//----------------------------------------------------------------------------------------
	/// Removes objects that do not match the filter given by @formatParam{type} and @formatParam{instance}.
	/// @param[in] type								Checked against C4DAtom::GetType(). Pass @ref NOTOK to ignore this test.
	/// @param[in] instance						Checked against C4DAtom::IsInstanceOf(). Pass @ref NOTOK to ignore this test.
	/// @param[in] generators					Used to filter generators.
	//----------------------------------------------------------------------------------------
	void FilterObject(Int32 type, Int32 instance, Bool generators = false) { AtCall(AAFilterObject) (type, instance, generators); }

	//-------------------------------------------------------------------------------------------------
	/// Removes all objects that has a parent (or ancestor) in the array.
	//-------------------------------------------------------------------------------------------------
	void FilterObjectChildren() { AtCall(AAFilterObjectChildren) (); }

	//----------------------------------------------------------------------------------------
	/// Appends all objects in @formatParam{src} to the array.
	/// @param[in] src								The source array to append. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Append(const AtomArray* src) { return AtCall(AAAppendArr) (src); }

	//----------------------------------------------------------------------------------------
	/// Finds the index of @formatParam{obj} in the array.
	/// @param[in] obj								The atom to search for.
	/// @return												The index, or @ref NOTOK if not found.
	//----------------------------------------------------------------------------------------
	Int32 Find(C4DAtom* obj) { return AtCall(AAFind) (obj); }

	//----------------------------------------------------------------------------------------
	/// Compares the array with @formatParam{cmp}.
	/// @param[in] cmp								The atom array to compare with. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{both arrays are identical}
	//----------------------------------------------------------------------------------------
	Bool Compare(const AtomArray* cmp) const { return AtCall(AACompareArr) (cmp); }

		/// @}
};


//-------------------------------------------------------------------------------------------------
/// Represents a C4DAtom that resides in a 4D list.
//-------------------------------------------------------------------------------------------------
class GeListNode : public C4DAtomGoal
{
private:
	GeListNode();
	~GeListNode();

public:

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next node in the list.
	/// @return												The next node, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	GeListNode* GetNext() { return AtCall(GetNext) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous node in the list.
	/// @return												The previous node, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	GeListNode* GetPred() { return AtCall(GetPred) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the first child node.
	/// @return												The first child node, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	GeListNode* GetDown() { return AtCall(GetDown) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the parent node.
	/// @return												The parent node, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	GeListNode* GetUp() { return AtCall(GetUp) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the last child node.
	/// @return												The last child node, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	GeListNode* GetDownLast() { return AtCall(GetDownLast) (); }

	/// @}

	/// @name Insertion
	/// @{

	//----------------------------------------------------------------------------------------
	/// Inserts the node before @formatParam{bl}.
	/// @warning	You must make sure that @formatParam{bl} has a parent and that the insertion is sane, for example it is forbidden to insert a key.\n
	///						It is also necessary to use Remove() first if the object is already inserted into another list.
	/// @param[in] bl									The node to insert before. @callerOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	void InsertBefore(GeListNode* bl) { AtCall(InsertBefore) (bl); }

	//----------------------------------------------------------------------------------------
	/// Inserts the node after @formatParam{bl}.
	/// @warning	You must make sure that @formatParam{bl} has a parent and that the insertion is sane, for example it is forbidden to insert a key.\n
	///						It is also necessary to use Remove() first if the object is already inserted into another list.
	/// @param[in] bl									The node to insert after. @callerOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	void InsertAfter(GeListNode* bl) { AtCall(InsertAfter) (bl); }

	//----------------------------------------------------------------------------------------
	/// Inserts the node under @formatParam{bl} as the first child.
	/// @warning	You must make sure that the insertion is sane, for example it is forbidden to insert a key.\n
	///						It is also necessary to use Remove() first if the object is already inserted into another list.
	/// @param[in] bl									The node to insert under. @callerOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	void InsertUnder(GeListNode* bl) { AtCall(InsertUnder) (bl); }

	//----------------------------------------------------------------------------------------
	/// Inserts the node as the last child of @formatParam{bl}.
	/// @warning	You must make sure that the insertion is sane, for example it is forbidden to insert a key.\n
	///						It is also necessary to use Remove() first if the object is already inserted into another list.
	/// @param[in] bl									The node to insert under as last child. @callerOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	void InsertUnderLast(GeListNode* bl) { AtCall(InsertUnderLast) (bl); }

	/// @}

	/// Removal
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// Removes the node from its list.
	/// @warning When a node is removed you become responsible for freeing it or passing its ownership to another list.
	//-------------------------------------------------------------------------------------------------
	void Remove() { AtCall(Remove) (); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the list head for the node.
	/// @return												The list head or @formatConstant{nullptr} if the node is not attached to one. The pointed list head owns the node.
	//----------------------------------------------------------------------------------------
	GeListHead* GetListHead() { return AtCall(GetListHead) (); }


	//----------------------------------------------------------------------------------------
	/// Gets the ID of the node optionally for the given level @formatParam{index}.
	/// @param[in] index							For multi-nodes (two or more nodes virtually linked together) retrieve the ID for every level @formatParam{index}.\n
	/// 															For example GvNode is a level @em 2 multi-nodes. They consist of one list element (GeListNode or BaseList2D) and two virtual NodeData derivate: one is private and one is used by the operator.
	/// @return												The node's ID.
	//----------------------------------------------------------------------------------------
	Int32 GetNodeID(Int32 index = 0) const { return C4DOS.Bl->GetNodeID((GeListNode*)this, index); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the data for the node.
	/// @note Changed in R17. Changed returned object type from @ref NodeData* to <tt>template \<typename CAST\> CAST*</tt>.
	/// @warning Only use the virtual functions of the object if GetNodeData() is called in the same module that registered the node.
	/// @param[in] index							For multi-nodes (two or more nodes virtually linked together) retrieve the ID for every level @formatParam{index}.\n
	/// 															For example GvNode objects are level @em 2 multi-nodes. They consist of one list element (GeListNode or BaseList2D) and two virtual NodeData derivate: one is private and one is used by the operator.
	/// @return												The node data, or @formatConstant{nullptr}. @theOwnsPointed{node, NodeData}
	//----------------------------------------------------------------------------------------
	template <typename CAST> const CAST* GetNodeData(Int32 index = 0) const { return static_cast<const CAST*>(C4DOS.Bl->GetNodeData(const_cast<GeListNode*>(this), index)); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the data for the node.
	/// @note Changed in R17. Changed returned object type from @ref NodeData* to <tt>template \<typename CAST\> CAST*</tt>.
	/// @warning Only use the virtual functions of the object if GetNodeData() is called in the same module that registered the node.
	/// @param[in] index							For multi-nodes (two or more nodes virtually linked together) retrieve the ID for every level @formatParam{index}.\n
	/// 															For example GvNode objects are level @em 2 multi-nodes. They consist of one list element (GeListNode or BaseList2D) and two virtual NodeData derivate: one is private and one is used by the operator.
	/// @return												The node data, or @formatConstant{nullptr}. @theOwnsPointed{node, NodeData}
	//----------------------------------------------------------------------------------------
	template <typename CAST> CAST* GetNodeData(Int32 index = 0) { return static_cast<CAST*>(C4DOS.Bl->GetNodeData(this, index)); }

	//----------------------------------------------------------------------------------------
	/// Sets the custom data for the node.
	/// @note	The custom data is private data that can be attached to an object.\n
	///				Only the owner of an object type (not an object instance) is allowed to attach custom data to that object.
	/// @param[in] node								The new custom data.
	//----------------------------------------------------------------------------------------
	void SetCustomData(GeListNode* node);

	//----------------------------------------------------------------------------------------
	/// Gets the custom data for the node.
	/// @see SetCustomData()
	/// @return												The custom data.
	//----------------------------------------------------------------------------------------
	GeListNode* GetCustomData();

	//----------------------------------------------------------------------------------------
	/// Retrieves the document for the node.
	/// @return												The document, or @formatConstant{nullptr} if the node is not in a document. The pointed document owns the list head that possesses the node.
	//----------------------------------------------------------------------------------------
	BaseDocument* GetDocument() { return AtCall(GetDocument) (); }

	//----------------------------------------------------------------------------------------
	/// Gets information about which other node types the node contains.\n
	/// For example objects contain tags.\n
	/// @b Example: Pass an array of BranchInfo objects and its size, the function returns the number of filled elements:
	/// @code
	/// BranchInfo branch[MAX];
	/// Int32 count = node->GetBranchInfo(branch, MAX, GETBRANCHINFO::NONE);
	/// @endcode
	/// @param[in,out] info						An array of @formatParam{max} BranchInfo structures. @callerOwnsPointed{array}
	/// @param[in] max								The number of elements in @formatParam{info}.
	/// @param[in] flags							Flags: @enumerateEnum{GETBRANCHINFO}
	/// @return												The number of BranchInfo elements filled in.
	//----------------------------------------------------------------------------------------
	Int32 GetBranchInfo(BranchInfo* info, Int32 max, GETBRANCHINFO flags) { return AtCall(GetBranchInfo) (info, max, flags); }

	//----------------------------------------------------------------------------------------
	/// Checks if the node is of a type that can be inserted into a @link BaseDocument document@endlink.
	/// @return												@trueIfOtherwiseFalse{the node is document related}
	//----------------------------------------------------------------------------------------
	Bool IsDocumentRelated() { return AtCall(IsDocumentRelated) (); }

	/// @}

	/// @name Nbit
	/// @{

	//----------------------------------------------------------------------------------------
	/// Raw access to the node state.
	/// @param[in] bit								The bit index: @enumerateEnum{NBIT}
	/// @return												The bit state.
	//----------------------------------------------------------------------------------------
	Bool GetNBit(NBIT bit) const;

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	UInt32 GetNBitMask(Int32 index) const;

	//----------------------------------------------------------------------------------------
	/// Sets bits in the node state.
	/// @param[in] bit								The bit index: @enumerateEnum{NBIT}
	/// @param[in] bitmode						The bit mode: @enumerateEnum{NBITCONTROL}
	/// @return												@trueIfOtherwiseFalse{the bit was successfully changed}
	//----------------------------------------------------------------------------------------
	Bool ChangeNBit(NBIT bit, NBITCONTROL bitmode);

	/// @}

	/// @name Miscellaneous
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	Int32 GetInfo();

	/// @}
};

//-------------------------------------------------------------------------------------------------
/// Stores a list of GeListNode objects.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class GeListHead : public GeListNode
{
private:
	GeListHead();
	~GeListHead();

	/// @name Navigation
	/// @{

	void InsertBefore(GeListNode* bl) { AtCall(InsertBefore) (bl); }
	void InsertAfter(GeListNode* bl) { AtCall(InsertAfter) (bl); }
	void InsertUnder(GeListNode* bl) { AtCall(InsertUnder) (bl); }
	void InsertUnderLast(GeListNode* bl) { AtCall(InsertUnderLast) (bl); }
	void Remove() { AtCall(Remove) (); }

	/// @}

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{list head}
	/// @return												@allocReturn{list head}
	//----------------------------------------------------------------------------------------
	static GeListHead* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{list heads}
	/// @param[in,out] v							@theToDestruct{list head}
	//----------------------------------------------------------------------------------------
	static void Free(GeListHead*& v);

	/// @}

	/// @name Miscellaneous
	// @{

	//----------------------------------------------------------------------------------------
	/// Sets the parent of the list head.\n
	/// Usually called directly after the list head is allocated.
	/// @param[in] parent							The new parent. @callerOwnsPointed{parent}
	//----------------------------------------------------------------------------------------
	void SetParent(GeListNode* parent) { AtCall(SetParent) (parent); }

	//----------------------------------------------------------------------------------------
	/// Gets the parent of the list head.\n
	/// For the tag list head this would be the object, for the object list head this would be the document etc.
	/// @return												The parent. @cinemaOwnsPointed{parent}
	//----------------------------------------------------------------------------------------
	GeListNode* GetParent() { return AtCall(GetParent) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the first node in the list.
	/// @return												The first node in the list. @theOwnsPointed{list, node}
	//----------------------------------------------------------------------------------------
	GeListNode* GetFirst() { return AtCall(GetFirst) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the last node in the list.
	/// @return												The last node in the list. @theOwnsPointed{list, node}
	//----------------------------------------------------------------------------------------
	GeListNode* GetLast() { return AtCall(GetLast) (); }

	//-------------------------------------------------------------------------------------------------
	/// Clears the list, removing all nodes.
	//-------------------------------------------------------------------------------------------------
	void FlushAll() { AtCall(FlushAll) (); }

		// @}

	/// @name Insertion
	/// @{

	//----------------------------------------------------------------------------------------
	/// Inserts @formatParam{bn} as the first element in the list.
	/// @param[in] bn									The node to insert first. @callerOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	void InsertFirst(GeListNode* bn) { AtCall(InsertFirst) (bn); }

	//----------------------------------------------------------------------------------------
	/// Inserts @formatParam{bn} as the last element in the list.
	/// @param[in] bn									The node to insert last. @callerOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	void InsertLast(GeListNode* bn) { AtCall(InsertLast) (bn); }

	//----------------------------------------------------------------------------------------
	/// Inserts @formatParam{bn} as a child of @formatParam{parent} or after @formatParam{prev}.
	/// @param[in] bn									The node to insert. @callerOwnsPointed{node}
	/// @param[in] parent							The node to insert @formatParam{bn} as child. @callerOwnsPointed{node}
	/// @param[in] prev								The node to insert @formatParam{bn} after. @callerOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	void Insert(GeListNode* bn, GeListNode* parent, GeListNode* prev);

	/// @}
};

//-------------------------------------------------------------------------------------------------
/// Stores a list of GeListNode objects and has an optional callback function which the owner object can set and any other object may invoke.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class GeListHeadCB : public GeListHead
{
private:
	GeListHeadCB();
	~GeListHeadCB();

	/// @name Navigation
	/// @{

	void InsertBefore(GeListNode* bl) { AtCall(InsertBefore) (bl); }
	void InsertAfter(GeListNode* bl) { AtCall(InsertAfter) (bl); }
	void InsertUnder(GeListNode* bl) { AtCall(InsertUnder) (bl); }
	void InsertUnderLast(GeListNode* bl) { AtCall(InsertUnderLast) (bl); }
	void Remove() { AtCall(Remove) (); }

	/// @}

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{list head}
	/// @return												@allocReturn{list head}
	//----------------------------------------------------------------------------------------
	static GeListHeadCB* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{list heads}
	/// @param[in,out] v							@theToDestruct{list head}
	//----------------------------------------------------------------------------------------
	static void Free(GeListHeadCB*& v);

	/// @}

	/// @name Parent Callback
	/// @{

	//----------------------------------------------------------------------------------------
	/// Allows the owner (parent) to set a callback function that will be invoked via the InvokeParentCallback function.  Only the owner of the GeListHead should invoke this.
	/// @param[in,out] callback	[in] The callback delegate to be invoked.
	/// @return	OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> SetParentCallback(maxon::Delegate<maxon::Result<void>(BaseList2D& caller, Int32 type, void* message)>&& callback) { return AtCall(SetParentCallback) (std::forward<maxon::Delegate<maxon::Result<void>(BaseList2D& caller, Int32 type, void* message)> >(callback)); }

	//----------------------------------------------------------------------------------------
	/// Executes the parent callback set with SetParentCallback
	/// @param[in] caller 	The caller.
	/// @param[in] type			The type of message.
	/// @param[in] message	If non-null, the message data.
	/// @return	OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> InvokeParentCallback(BaseList2D& caller, Int32 type, void* message) const { return AtCall(InvokeParentCallback) (caller, type, message); }

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents a C4DAtom that resides in a 2D list.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class BaseList2D : public GeListNode
{
private:
	BaseList2D();
	~BaseList2D();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{base list node}
	/// @param[in] type								A node type ID.
	//----------------------------------------------------------------------------------------
	static BaseList2D* Alloc(Int32 type);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{base list nodes}
	/// @param[in,out] bl							@theToDestruct{base list node}
	//----------------------------------------------------------------------------------------
	static void Free(BaseList2D*& bl);

	//----------------------------------------------------------------------------------------
	/// Gets the Id of the viewport render object. The return value can be nullptr.
	/// @param[in] typeId							Defines which Id to return.
	/// @return												The viewport render Id.
	//----------------------------------------------------------------------------------------
	const Char* GetViewportRenderId(VIEWPORT_RENDER_ID typeId) const;

	/// @}

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next BaseList2D in the list. Convenience version of GeListNode::GetNext().
	/// @return												The next BaseList2D, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{BaseList2D}
	//----------------------------------------------------------------------------------------
	BaseList2D* GetNext() { return (BaseList2D*)AtCall(GetNext) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous BaseList2D in the list. Convenience version of GeListNode::GetPred().
	/// @return												The previous BaseList2D, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{BaseList2D}
	//----------------------------------------------------------------------------------------
	BaseList2D* GetPred() { return (BaseList2D*)AtCall(GetPred) (); }

	/// @}

	/// @name Bit
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the bits denoted by @formatParam{mask} to @formatConstant{true}.
	/// @param[in] mask								The mask of the bits: @enumerateEnum{BIT}
	//----------------------------------------------------------------------------------------
	void SetBit(Int32 mask) { C4DOS.Bl->SetAllBits(this, C4DOS.Bl->GetAllBits(this) | mask); }

	//----------------------------------------------------------------------------------------
	/// Gets the state of the object bits denoted by @formatParam{mask}.
	/// @param[in] mask								The mask of the bits: @enumerateEnum{BIT}
	/// @return												The state of the object bits denoted by @formatParam{mask}.
	//----------------------------------------------------------------------------------------
	Bool GetBit(Int32 mask) const { return (C4DOS.Bl->GetAllBits(this) & mask) == mask; }

	//----------------------------------------------------------------------------------------
	/// Deletes the object bits denoted by @formatParam{mask}, i.e. sets the corresponding bit to @em 0.
	/// @param[in] mask								The bit mask of the bits: @enumerateEnum{BIT}
	//----------------------------------------------------------------------------------------
	void DelBit(Int32 mask) { C4DOS.Bl->SetAllBits(this, C4DOS.Bl->GetAllBits(this) & ~mask); }

	//----------------------------------------------------------------------------------------
	/// Toggles the state of the object bits denoted by the @formatParam{mask}.
	/// @param[in] mask								The bit mask of the bits: @enumerateEnum{BIT}
	//----------------------------------------------------------------------------------------
	void ToggleBit(Int32 mask);

	//----------------------------------------------------------------------------------------
	/// Returns all the object's bits.
	/// @return												All the object's bits: @enumerateEnum{BIT}
	//----------------------------------------------------------------------------------------
	Int32 GetAllBits() const { return C4DOS.Bl->GetAllBits(this); }

	//----------------------------------------------------------------------------------------
	/// Sets all the object's bits at once.
	/// @param[in] bits								The new object's bits.
	//----------------------------------------------------------------------------------------
	void SetAllBits(Int32 bits) { C4DOS.Bl->SetAllBits(this, bits); }

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	static const Int32 SETBIT_FLAG_NODIRTY	= (1 << 1);	// do not dirty the selection status cache
	static const Int32 SETBIT_FLAG_REMOVE		= (1 << 2);	// remove bits (as in DelBit)
	void SetBitEx(Int32 mask, Int32 flags) { C4DOS.Bl->SetBitEx(this, mask, flags); }


	/// @}

	/// @name Container
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves a copy of the object's container.
	/// @note	Some objects do not store all their data in the container. For these use GetParameter()/SetParameter() instead.\n
	///				Here are some built-in objects that do not store everything in the container:
	/// - CompositingTag
	/// - DisplayTag
	/// - ValueKey
	/// - TextureTag
	/// - KinematicTag
	/// - UVWTag
	/// - LightObject
	/// - MetaballTag
	///
	/// @note	There are also often some other pieces of information that are not stored in the container, for example:
	///				- a BaseList2D's name.
	///				- a CameraObject's FOV (which is used just for display).
	///
	/// @note	Most of this information is accessible through other API functions, like for example BaseList2D::GetName().
	/// @return												The object container.
	//----------------------------------------------------------------------------------------
	BaseContainer GetData() { BaseContainer bc; C4DOS.Bl->GetData(this, &bc); return bc; }

	//----------------------------------------------------------------------------------------
	/// Sets the object container.\n
	/// By default the contents of @formatParam{bc} is added to the existing container; control this behavior with @formatParam{add}.
	/// @note Do not forget to send a @link C4DAtom::Message() message@endlink if you change any settings.
	/// @param[in] bc									The container with the new values.
	/// @param[in] add								If @formatConstant{false} the values are merged, otherwise the old values are discarded.
	//----------------------------------------------------------------------------------------
	void SetData(const BaseContainer& bc, Bool add = true) { C4DOS.Bl->SetData(this, &bc, add); }

	//----------------------------------------------------------------------------------------
	/// Retrieves a pointer to the read-only object container.
	/// @see GetData()
	/// @return												A pointer to the read-only internal container. @theOwnsPointed{node, container}
	/// @note													The returned pointer is guaranteed to be valid and never @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	const BaseContainer* GetDataInstance() const { return C4DOS.Bl->GetDataInstance(const_cast<BaseList2D*>(this)); }

	//----------------------------------------------------------------------------------------
	/// Retrieves a pointer to the object container that can be changed directly.
	/// @see GetData()
	/// @return												A pointer to the internal container. @theOwnsPointed{node, container}
	/// @note													The returned pointer is guaranteed to be valid and never @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	BaseContainer* GetDataInstance() { return C4DOS.Bl->GetDataInstance(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves a reference to the read-only object container.
	/// @since R19
	/// @see GetData()
	/// @return												A reference to the read-only internal container. The node owns the referenced container.
	//----------------------------------------------------------------------------------------
	const BaseContainer& GetDataInstanceRef() const { return *C4DOS.Bl->GetDataInstance(const_cast<BaseList2D*>(this)); }
	
	//----------------------------------------------------------------------------------------
	/// Retrieves a reference to the object container that can be changed directly.
	/// @since R19
	/// @see GetData()
	/// @return												A reference to the internal container. The node owns the referenced container.
	//----------------------------------------------------------------------------------------
	BaseContainer& GetDataInstanceRef() { return *C4DOS.Bl->GetDataInstance(this); }

	/// @}

	/// @name Name
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the name of the object.
	/// @return												The object's name.
	//----------------------------------------------------------------------------------------
	String GetName() const { return AtCall(GetName) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the name of the object.
	/// @param[in] name								The new object's name.
	//----------------------------------------------------------------------------------------
	void SetName(const maxon::String& name) { AtCall(SetName) (name); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the bubble help text for the object.
	/// @return												The bubble help text.
	//----------------------------------------------------------------------------------------
	String GetBubbleHelp() { return C4DOS.Bl->GetBubbleHelp(this); }

	//----------------------------------------------------------------------------------------
	/// Transfer goals from the object to @formatParam{dst}.\n
	/// This changes all BaseLink links that point to this object to point to @formatParam{dst} instead.
	/// @param[in] dst								The destination. @callerOwnsPointed{object}
	/// @param[in] undolink						This has to be set to @formatConstant{false}. Private.
	/// @return												@trueIfOtherwiseFalse{the goals could be transfered}
	//----------------------------------------------------------------------------------------
	Bool TransferGoal(BaseList2D* dst, Bool undolink) { return AtCall(TransferGoal) (dst, undolink); }

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	Bool TransferMarker(BaseList2D* dst) const { return AtCall(TransferMarker) (dst); }

	/// @}

	/// @name Marker
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// @markDeprecated
	//-------------------------------------------------------------------------------------------------
	void GetMarkerStampEx(UInt32* l1, UInt32* l2) { return C4DOS.Bl->GetMarker(this, l1, l2); }

	//----------------------------------------------------------------------------------------
	/// Gets the object's marker.
	/// @return												The object's marker.
	//----------------------------------------------------------------------------------------
	const GeMarker& GetMarker() const { return AtCall(GetMarker) (); }

	//----------------------------------------------------------------------------------------
	/// Sets the object's marker.
	/// @param[in] m									The new object's marker.
	//----------------------------------------------------------------------------------------
	void SetMarker(const GeMarker& m) { AtCall(SetMarker) (m); }

	/// @}

	/// @name Unique ID
	/// @{

	//----------------------------------------------------------------------------------------
	/// Adds a unique application ID data to the object.
	/// @note This is used for instance to identify scenes written by external applications.
	/// @param[in] appid							A unique application ID. It has to be registered at MAXON, at least it should be obtained from http://www.plugincafe.com.
	/// @param[in] mem								A pointer to a block of memory, used for instance to store the name of a software vendor.
	/// @param[in] bytes							The length of the memory block @formatParam{mem}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool AddUniqueID(Int32 appid, const Char* const mem, Int bytes) { return AtCall(AddUniqueID) (appid, mem, bytes); }

	//----------------------------------------------------------------------------------------
	/// Checks for a specific unique application ID data.
	/// @note This is used for instance to identify scenes written by external applications.
	/// @param[in] appid							A unique application ID. It has to be registered at MAXON, at least it should be obtained from http://www.plugincafe.com.
	/// @param[out] mem								Assigned a pointer to a block of memory, used for instance to read the name of a software vendor.
	/// @param[out] bytes							Assigned the length of the memory block @formatParam{mem}.
	/// @return												@trueIfOtherwiseFalse{the ID could be found}
	//----------------------------------------------------------------------------------------
	Bool FindUniqueID(Int32 appid, const Char*& mem, Int& bytes) const { return AtCall(FindUniqueID) (appid, mem, bytes); }

	//----------------------------------------------------------------------------------------
	/// Gets the number of unique application IDs.
	/// @return												The number of unique application IDs.
	//----------------------------------------------------------------------------------------
	Int32 GetUniqueIDCount() const { return AtCall(GetUniqueIDCount) (); }

	//----------------------------------------------------------------------------------------
	/// Gets the @formatParam{idx}-th unique application ID data (@formatParam{idx} ranging from @em 0 to GetUniqueIDCount()-1).
	/// @note This is used for instance to identify scenes written by external applications.
	/// @param[in] idx								The unique ID index.
	/// @param[out] id								Assigned the unique application ID.
	/// @param[out] mem								Assigned a pointer to a block of memory, used for instance to read the name of a software vendor.
	/// @param[out] bytes							Assigned the length of the memory block @formatParam{mem}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetUniqueIDIndex(Int32 idx, Int32& id, const Char*& mem, Int& bytes) const { return AtCall(GetUniqueIDIndex) (idx, id, mem, bytes); }

	/// @}

	/// @name Animated Parameter
	/// @{

	//----------------------------------------------------------------------------------------
	/// Normally not used. Used by the animator to set the interpolated value along with the right and left value.
	/// @param[in] track							The animation track. @callerOwnsPointed{track}
	/// @param[in] id									The ID of the animated parameter.
	/// @param[in] t_data1						The first data.
	/// @param[in] t_data2						The second data.
	/// @param[in] mix								The mix value between @formatParam{t_data1} and @formatParam{t_data2}.
	/// @param[in] flags							Flags: @enumerateEnum{DESCFLAGS_SET}
	/// @return												@trueIfOtherwiseFalse{the animated parameter was set}
	//----------------------------------------------------------------------------------------
	Bool SetAnimatedParameter(CTrack* track, const DescID& id, const GeData& t_data1, const GeData& t_data2, Float mix, DESCFLAGS_SET flags);

	//----------------------------------------------------------------------------------------
	/// If a parameter is set to @em MIX animation use this function to retrieve information about it.\n
	/// For example, the target expression has a link to its current target and when it is animated it slides between the two targets:
	/// @code
	/// EXECUTIONRESULT TargetExpressionTag::Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
	/// {
	/// 	GeData s1, s2;
	/// 	Float mix;
	///
	/// 	tag->GetAnimatedParameter(DescLevel(TARGETEXPRESSIONTAG_LINK), s1, s2, mix, DESCFLAGS_GET::NONE);
	///
	/// 	BaseList2D *o1 = s1.GetLink(doc);
	/// 	BaseList2D *o2 = s2.GetLink(doc);
	///
	/// 	if (!o1 || !o1->IsInstanceOf(Obase))
	/// 		return EXECUTIONRESULT::OK;
	///
	/// 	Vector nrot, p = ((BaseObject*)o1)->GetMg().off;
	///
	/// 	if (mix>0.0 && o2 && o2->IsInstanceOf(Obase))
	/// 		p = p * (1.0-mix) + ((BaseObject*)o2)->GetMg().off * mix;
	///
	/// 	p = p * (!op->GetUpMg());
	///
	/// 	nrot = VectorToHPB(p - op->GetPos());
	/// 	nrot.z = op->GetRot().z;
	/// 	op->SetRot(nrot);
	///
	/// 	return EXECUTIONRESULT::OK;
	/// }
	/// @endcode
	/// @param[in] id									The ID of the parameter.
	/// @param[in] t_data1						Assigned the first data.
	/// @param[in] t_data2						Assigned the second data.
	/// @param[in] mix								Assigned the mix value between @formatParam{t_data1} and @formatParam{t_data2}.
	/// @param[in] flags							Flags: @enumerateEnum{DESCFLAGS_GET}
	/// @return												@trueIfOtherwiseFalse{the animated parameter was retrieved}
	//----------------------------------------------------------------------------------------
	Bool GetAnimatedParameter(const DescID& id, GeData& t_data1, GeData& t_data2, Float& mix, DESCFLAGS_GET flags);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the object's scale.\n
	/// This will scale all parameters with length units by the factor scale.
	/// @param[in] scale							The scale factor.
	/// @return												@trueIfOtherwiseFalse{the object was scaled successfully}
	//----------------------------------------------------------------------------------------
	Bool Scale(Float scale) { return AtCall(Scale) (scale); }

	/// @}

	/// @name Shader
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the first shader of the object.\n
	/// @note	Normally you do not have to deal with the shader list. But if you want to create or modify shader trees via the API read the following lines:\n
	///				If you are programming shader links to make sure that every shader is referenced only once; it is not allowed that a shader is referenced multiple times.\n
	///				If the referencing object is a shader the referenced shader must be child of it, otherwise it must be inserted via InsertShader().
	///
	/// Example 1: A tag references a shader. The shader must be inserted into the tag using InsertShader();.
	/// Example 2: A Shader (A) references another shader (B): the shader B must be child of the shader A.
	/// @return												The first shader of the object, or @formatConstant{nullptr} if there are none. @theOwnsPointed{object, shader}
	//----------------------------------------------------------------------------------------
	BaseShader* GetFirstShader() const { return AtCall(GetFirstShader) (); }

	//----------------------------------------------------------------------------------------
	/// Inserts a shader in the object's shader list.
	/// @code
	/// BaseMaterial *mat = nullptr;
	/// mat = doc->GetFirstMaterial();
	/// if (!mat)
	/// 	return true;
	///
	/// BaseContainer *data = mat->GetDataInstance();
	/// if (!data)
	/// 	return true;
	///
	/// BaseShader *shd = BaseShader::Alloc(Xbitmap);
	/// if (!shd)
	/// 	return false;
	///
	/// data->SetLink(MATERIAL_COLOR_SHADER, shd);
	/// mat->InsertShader(shd);
	/// mat->Message(MSG_UPDATE);
	/// mat->Update(true, true);
	///
	/// EventAdd();
	/// @endcode
	/// @param[in] shader							The shader to insert. The object takes over the ownership of the pointed shader.
	/// @param[in] pred								The shader to insert the new shader after, or @formatConstant{nullptr} (default)to insert the new shader first. The pointed shader must already be inserted into the list.
	//----------------------------------------------------------------------------------------
	void InsertShader(BaseShader* shader, BaseShader* pred = nullptr) { AtCall(InsertShader) (shader, pred); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Triggers the edit action for the object.
	/// @note For most types this brings up the node in the attributes manager. Some still show a separate dialog.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Edit();


	//----------------------------------------------------------------------------------------
	/// Gets the icon for the object, by filling @formatParam{dat}.
	/// @param[out] dat								Pointer to the icon data to fill. @callerOwnsPointed{icon data}
	//----------------------------------------------------------------------------------------
	void GetIcon(IconData* dat);

	/// @}

	/// @name Keyframe
	/// @{

	//-------------------------------------------------------------------------------------------------
	/// Clears the current keyframe selection.
	//-------------------------------------------------------------------------------------------------
	void ClearKeyframeSelection();

	//----------------------------------------------------------------------------------------
	/// Checks if @formatParam{id} is included in the keyframe selection.
	/// @param[in] id									The description ID to check.
	/// @return												@trueIfOtherwiseFalse{the given @formatParam{id} is selected}
	//----------------------------------------------------------------------------------------
	Bool FindKeyframeSelection(const DescID& id);

	//----------------------------------------------------------------------------------------
	/// Sets the keyframe selection status of @formatParam{id} to selection.
	/// @param[in] id									The description ID to set.
	/// @param[in] selection					@formatConstant{true} if the element should be included in the keyframe selection, otherwise @formatConstant{false}.
	/// @return												A value that should be ignored.
	//----------------------------------------------------------------------------------------
	Bool SetKeyframeSelection(const DescID& id, Bool selection);

	//----------------------------------------------------------------------------------------
	/// Checks if there is any active keyframe selections.
	/// @note	This is not the same as @ref BIT_ACTIVE; it is the possibility to restrict auto-keyframing to certain description parameters.\n
	///				See "Animation->Add Keyframe Selection" in the Attribute Manager.
	/// @return												@trueIfOtherwiseFalse{there is a keyframe selection}
	//----------------------------------------------------------------------------------------
	Bool KeyframeSelectionContent();

	/// @}

	/// @name Layer
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the layer of the object.
	/// @param[in] doc								The document for the operation.
	/// @return												The layer, or @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	LayerObject* GetLayerObject(BaseDocument* doc);

	//----------------------------------------------------------------------------------------
	/// Sets the layer of the object.
	/// @param[in] layer							The new layer.
	/// @return												@trueIfOtherwiseFalse{the layer was successfully set}
	//----------------------------------------------------------------------------------------
	Bool SetLayerObject(LayerObject* layer);

	//----------------------------------------------------------------------------------------
	/// Gets the layer data for the object.
	/// @param[in] doc								The document for the operation.
	/// @param[in] rawdata						Usually GetLayerData() takes special global modes like @em SOLO layer automatically into account.\n
	/// 															To get the original layer values without any additional global changes set @formatParam{rawdata} to @formatConstant{true}.
	/// @return												The layer data, or @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	const LayerData* GetLayerData(BaseDocument* doc, Bool rawdata = false);

	//----------------------------------------------------------------------------------------
	/// Sets the layer data for the object.
	/// @param[in] doc								The document for the operation.
	/// @param[in] data								The new layer data.
	/// @return												@trueIfOtherwiseFalse{the layer data was successfully set}
	//----------------------------------------------------------------------------------------
	Bool SetLayerData(BaseDocument* doc, const LayerData& data);

	/// @}

	/// @name Track
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the track root of the object.
	/// @return												The track root.
	//----------------------------------------------------------------------------------------
	GeListHead* GetCTrackRoot();

	//----------------------------------------------------------------------------------------
	/// Gets the first track of the object.
	/// @return												The first track, or @formatConstant{nullptr} if there are no tracks.
	//----------------------------------------------------------------------------------------
	CTrack* GetFirstCTrack();

	//----------------------------------------------------------------------------------------
	/// Finds the track for the specified description @formatParam{id}.
	/// @param[in] id									The description ID for the searched track.
	/// @return												The found track, or @formatConstant{nullptr} if there was no match.
	//----------------------------------------------------------------------------------------
	CTrack* FindCTrack(const DescID& id);

	/// @}

/// @name Miscellaneous
/// @{

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	GeListHead* GetNLARoot();

	//----------------------------------------------------------------------------------------
	/// Retrieves a remapped base list pointer if an active animation layer is existent.\n
	/// If there is no active layer or no layer at all @c this will be returned.\n
	/// Optionally access the layer by passing @formatParam{layer}.
	/// @param[out] layer							The current active layer. You can then access the layer properties. @cinemaOwnsPointed{layer object}
	/// @return												The remapped base list pointer. This is the object of the current active layer. @cinemaOwnsPointed{layer object}
	//----------------------------------------------------------------------------------------
	BaseList2D* AnimationLayerRemap(BaseObject** layer = nullptr);

	//----------------------------------------------------------------------------------------
	/// The name of the object type, for example @em "Phong", @em "Spline", @em "Bone", etc.
	/// @return												The type name.
	//----------------------------------------------------------------------------------------
	String GetTypeName();

	//----------------------------------------------------------------------------------------
	/// Goes up the next level, e.g. from tag to object or XPresso node to tag, or object to document, etc.
	/// @return												The main object of the object.
	//----------------------------------------------------------------------------------------
	BaseList2D* GetMain() const;

	//----------------------------------------------------------------------------------------
	/// Inserts a track and automatically places it at the right place (so that Y comes after X for example).
	/// @param[in] track							The track to insert.
	//----------------------------------------------------------------------------------------
	void InsertTrackSorted(CTrack* track);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool AddEventNotification(BaseList2D* bl, NOTIFY_EVENT eventid, NOTIFY_EVENT_FLAG flags, const BaseContainer* data);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool RemoveEventNotification(BaseDocument* doc, BaseList2D* bl, NOTIFY_EVENT eventid);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool FindEventNotification(BaseDocument* doc, BaseList2D* bl, NOTIFY_EVENT eventid);

	//----------------------------------------------------------------------------------------
	/// Sets the state for the description @formatParam{id}.
	/// @param[in] id									The description ID.
	/// @param[in] descidstate				The new description ID state: @enumerateEnum{DESCIDSTATE}
	/// @return												@trueIfOtherwiseFalse{the description ID state was successfully set}
	//----------------------------------------------------------------------------------------
	Bool SetDescIDState(const DescID& id, DESCIDSTATE descidstate);

	//----------------------------------------------------------------------------------------
	/// Gets the state of a description @formatParam{id}.
	/// @param[in] id									The description ID.
	/// @param[in] tolerant						If set to @formatConstant{true} a valid state is returned even though the description ID do not match-completly.\n
	/// 															This can be useful for descriptions with several levels. Take this description ID for example:
	/// 															@code
	/// 															DescID(DescLevel(1000, DTYPE_VECTOR, 0), DescLevel(1, DTYPE_REAL, 0))
	/// 															@endcode
	/// 															If @formatParam{tolerant} is @formatConstant{true} a valid state is returned even though only the following description ID is passed:
	/// 															@code
	/// 															DescID(DescLevel(1000, DTYPE_VECTOR, 0))
	/// 															@endcode
	/// @return												The description ID state: @enumerateEnum{DESCIDSTATE}
	//----------------------------------------------------------------------------------------
	DESCIDSTATE GetDescIDState(const DescID& id, Bool tolerant) const;

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	/// @since R17.032
	//-------------------------------------------------------------------------------------------------
	GeListHead* GetOverrideRoot();

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	/// @since R17.032
	//-------------------------------------------------------------------------------------------------
	BaseOverride* GetFirstOverride();

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	/// @since R17.032
	//-------------------------------------------------------------------------------------------------
	GeListHead* GetShaderRepositoryRoot();

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	GeListHead* GetHiddenShaderRoot();

	//-------------------------------------------------------------------------------------------------
	/// Return the owning NimbusRef or NimbusBaseRef corresponding to the provided NodeSpace Id.
	/// @code
	/// // Retrieve the standard render NodeSpace from the selected material
	/// BaseMaterial* mat = doc->GetActiveMaterial();  // nullptr check avoided
	/// maxon::NimbusBaseRef nimbusRef = mat->GetNimbusRef(maxon::nodes::MaterialNodeSpaces::Standard.GetId());
	/// if (nimbusRef == nullptr)
	///		return;
	/// @param[in] spaceId				The NodeSpace ID.
	/// @return										Returns the owner of the node graph.
	//-------------------------------------------------------------------------------------------------
	maxon::NimbusForwardRef GetNimbusRef(const maxon::Id& spaceId) const;

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	maxon::Result<maxon::NimbusForwardRef> PrivateGetOrCreateNimbusRef(const maxon::Id& spaceId);

	//-------------------------------------------------------------------------------------------------
	/// Remove the NimbusRef and therefor the owned graph, corresponding to the provided NodeSpace Id.
	/// @param[in] spaceId				The NodeSpace ID.
	//-------------------------------------------------------------------------------------------------
	void RemoveNimbusRef(const maxon::Id& spaceId);

	//-------------------------------------------------------------------------------------------------
	/// Retrieve a HashMap of all NodeSpace ID and NimbusRef of the current BaseList is holding.
	/// @note the NimbusForwardRef can't be directly casted to a maxon::NimbusBaseRef. maxon::NimbusForwardRef::GetBase should be used.
	/// @code
	/// // Print all the NodeSpace ID from the selected material
	/// BaseMaterial* mat = doc->GetActiveMaterial(); // nullptr check avoided
	/// const maxon::HashMap<maxon::Id, maxon::NimbusForwardRef> hashNimbusRefs = mat->GetAllNimbusRefs() iferr_return;
	/// for (const auto& e : hashNimbusRefs)
	/// {
	///	  const maxon::Id& key = e.GetKey();
	///	  const maxon::NimbusBaseRef nimbusRef = e.GetValue().GetBase();
	///   ApplicationOutput("NodeSpace ID: @"_s, key);
	/// }
	/// @endcode
	/// @return									Returns a hash map of NodeSpace ID with their corresponding NimbusRef.
	//-------------------------------------------------------------------------------------------------
	maxon::Result<maxon::HashMap<maxon::Id, maxon::NimbusForwardRef>> GetAllNimbusRefs() const;

	//-------------------------------------------------------------------------------------------------
	/// Checks whether the object contains nodes.
	/// @return										True if node-based.
	//-------------------------------------------------------------------------------------------------
	Bool IsNodeBased() const;
	/// @}
};


/// @addtogroup c4d_baselist_nodeobjectallocation Node/Object Allocation/Deletion
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Allocates a list head. Destroy the allocated list head with FreeListNode().
/// @return												@allocReturn{list head node}
//----------------------------------------------------------------------------------------
GeListHead* AllocListHead();

//----------------------------------------------------------------------------------------
/// Allocates a RegisterNodePlugin() registered node.
/// @param[in] id									The node plugin ID.
/// @return												@allocReturn{list node}
//----------------------------------------------------------------------------------------
GeListNode* AllocListNode(Int32 id);

//----------------------------------------------------------------------------------------
/// Allocates a RegisterNodePlugin() registered node with the @ref PLUGINFLAG_SMALLNODE flag set.
/// @param[in] id									The small node plugin ID.
/// @return												@allocReturn{small list node}
//----------------------------------------------------------------------------------------
GeListNode* AllocSmallListNode(Int32 id);

//-------------------------------------------------------------------------------------------------
/// @markPrivate
//-------------------------------------------------------------------------------------------------
GeListNode* AllocMultiNode(Int32* id_array, Int32 id_cnt);

/// Destructs an AllocListNode() allocated node. It is basically the same as BaseList2D::Free().
#define FreeListNode(v) { if (v) C4DOS.Bl->Free(v); v = nullptr; }

/// Destructs objects derived from BaseList2D. It is basically the same as BaseList2D::Free().
#define blDelete(v) { if (v) C4DOS.Bl->Free(v); v = nullptr; }

/// @}


//-------------------------------------------------------------------------------------------------
/// A dynamic link to a BaseList2D object.\n
/// These links can easily be stored in containers and saved to disk, and are even preserved when duplicating hierarchies.
/// @addAllocFreeAutoAllocNote
//-------------------------------------------------------------------------------------------------
class BaseLink
{
private:
	BaseLink();
	~BaseLink();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{base link}
	/// @return												@allocReturn{base link}
	//----------------------------------------------------------------------------------------
	static BaseLink* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{base links}
	/// @param[in,out] link						@theToDestruct{base link}
	//----------------------------------------------------------------------------------------
	static void Free(BaseLink*& link);

	/// @}

	/// @name Get Link
	/// @{

	//----------------------------------------------------------------------------------------
	/// Evaluates the link in the specified document.\n
	/// If @formatParam{instanceof} is specified, @formatConstant{nullptr} is returned if the object is not of this type.
	/// @param[in] doc								The document to evaluate the link in. @callerOwnsPointed{document}
	/// @param[in] instanceof					Set this to a node type ID to only return the link if it is of this type.
	/// @return												The linked object, or @formatConstant{nullptr} if the link is broken or of the wrong type. @theOwnsPointed{document, object}
	//----------------------------------------------------------------------------------------
	BaseList2D* GetLink(const BaseDocument* doc, Int32 instanceof = 0) const { return C4DOS.Ln->GetLink(this, doc, instanceof); }

	//----------------------------------------------------------------------------------------
	/// Evaluates the atom link in the specified document.\n
	/// If @formatParam{instanceof} is specified, @formatConstant{nullptr} is returned if the atom object is not of this type.
	/// @param[in] doc								The document to evaluate the link in. @callerOwnsPointed{document}
	/// @param[in] instanceof					Set this to a type ID to only return the link if it is of this type.
	/// @return												The linked atom object, or @formatConstant{nullptr} if the link is broken or of the wrong type. @theOwnsPointed{document, atom object}
	//----------------------------------------------------------------------------------------
	C4DAtomGoal* GetLinkAtom(const BaseDocument* doc, Int32 instanceof = 0) const { return C4DOS.Ln->GetLinkAtom(this, doc, instanceof); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the stored link independent of a document.\n
	/// Can return @formatConstant{nullptr} if there is no object linked. For example:\n
	/// - Object @em A is inserted into document @em B.\n
	/// - @link SetLink SetLink@endlink(@em A) is called.\n
	/// - @link GetLink GetLink@endlink(@em B) is called : returns @em A.\n
	/// - Object @em A is removed from document @em B.\n
	/// - @link GetLink GetLink@endlink(@em B) is called : returns @formatConstant{nullptr}.\n
	/// - ForceGetLink() is called : returns @em A.\n
	/// - Object @em A is deleted.\n
	/// - ForceGetLink() is called : returns @formatConstant{nullptr}.
	/// @return												The linked object, or @formatConstant{nullptr} if the link is broken. @theOwnsPointed{document, object}
	//----------------------------------------------------------------------------------------
	BaseList2D* ForceGetLink() const { return C4DOS.Ln->ForceGetLink(this); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the stored atom link independent of a document.\n
	/// Can return @formatConstant{nullptr} if there is no object linked. For example:\n
	/// - Object @em A is inserted into document @em B.\n
	/// - @link SetLink SetLink@endlink(@em A) is called.\n
	/// - @link GetLink GetLink@endlink(@em B) is called : returns @em A.\n
	/// - Object @em A is removed from document @em B.\n
	/// - @link GetLink GetLink@endlink(@em B) is called : returns @formatConstant{nullptr}.\n
	/// - ForceGetLink() is called : returns @em A.\n
	/// - Object @em A is deleted.\n
	/// - ForceGetLink() is called : returns @formatConstant{nullptr}.
	/// @return												The linked atom object, or @formatConstant{nullptr} if the link is broken. @theOwnsPointed{document, atom object}
	//----------------------------------------------------------------------------------------
	C4DAtomGoal* ForceGetLinkAtom() const { return C4DOS.Ln->ForceGetLinkAtom(this); }

	/// @}

	/// @name Set Link
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the link to point to @formatParam{list}.
	/// @param[in] list								The new atom goal. @callerOwnsPointed{atom goal}
	//----------------------------------------------------------------------------------------
	void SetLink(C4DAtomGoal* list) { C4DOS.Ln->SetLink(this, list); }

	/// @}

	/// @name Read/Write
	/// @{

	//----------------------------------------------------------------------------------------
	/// Reads the link from a hyper file.
	/// @param[in] hf									The hyper file to read from. @callerOwnsPointed{hyper file}
	/// @return												@trueIfOtherwiseFalse{the link was read}
	//----------------------------------------------------------------------------------------
	Bool Read(HyperFile* hf) { return C4DOS.Ln->Read(this, hf); }

	//----------------------------------------------------------------------------------------
	/// Writes the link to a hyper file.
	/// @param[in] hf									The hyper file to write to. @callerOwnsPointed{hyper file}
	/// @return												@trueIfOtherwiseFalse{the link was written}
	//----------------------------------------------------------------------------------------
	Bool Write(HyperFile* hf) const { return C4DOS.Ln->Write(this, hf); }

	/// @}

	/// @name Copy
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets a copy of the link.
	/// @param[in] flags							Flags for the clone: @enumerateEnum{COPYFLAGS}
	/// @param[in] trn								An alias translator for the operation. Can be @formatConstant{nullptr}. @callerOwnsPointed{alias translator}
	/// @return												The cloned link. @callerOwnsPointed{link}
	//----------------------------------------------------------------------------------------
	BaseLink* GetClone(COPYFLAGS flags, AliasTrans* trn) const { return C4DOS.Ln->GetClone(this, flags, trn); }

	//----------------------------------------------------------------------------------------
	/// Copies the link to @formatParam{dst}.
	/// @param[in] dst								The destination link. @callerOwnsPointed{link}
	/// @param[in] flags							Flags for the copy: @enumerateEnum{COPYFLAGS}
	/// @param[in] trn								An alias translator for the operation. Can be @formatConstant{nullptr}. @callerOwnsPointed{alias translator}
	/// @return												@trueIfOtherwiseFalse{the link was copied}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(BaseLink* dst, COPYFLAGS flags, AliasTrans* trn) const { return C4DOS.Ln->CopyTo(this, dst, flags, trn); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if the link points to an object within the cache of another object.
	/// @return												@trueIfOtherwiseFalse{this link points to an object's cache}
	//----------------------------------------------------------------------------------------
	Bool IsCacheLink() const { return C4DOS.Ln->IsCacheLink(this); }

	//-------------------------------------------------------------------------------------------------
	/// @markPrivate
	//-------------------------------------------------------------------------------------------------
	void SetUpPointer(C4DAtom* t_up_pointer) { return C4DOS.Ln->SetUpPointer(this, t_up_pointer); }

	/// @}
};


//-------------------------------------------------------------------------------------------------
/// An alias translator class.
/// @addAllocFreeAutoAllocNote
///
/// The alias translator takes care about reconnecting BaseLink links when cloning, copying, reading or writing objects.\n
/// Normally @C4D will provide an alias translator when needed, for example in NodeData::CopyTo(). However, to copy objects manually use:
/// @code
/// AutoAlloc<AliasTrans> aliastrans;
/// if (!aliastrans || !aliastrans->Init(document))
/// 	return false;
/// dup = op->GetClone(COPYFLAGS::NONE, aliastrans);
/// if (!dup)
/// 	return false;
/// aliastrans->Translate(true);
/// @endcode
//-------------------------------------------------------------------------------------------------
class AliasTrans
{
private:
	AliasTrans();
	~AliasTrans();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesAN{alias translator}
	/// @return												@allocReturn{alias translator}
	//----------------------------------------------------------------------------------------
	static AliasTrans* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{alias translators}
	/// @param[in,out] link						@theToDestruct{alias translator}
	//----------------------------------------------------------------------------------------
	static void Free(AliasTrans*& link);

	/// @}

	/// @name Init and Translate
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the alias translator in the specified document @formatParam{doc}.
	/// @param[in] doc								The document. The caller owns the pointed object.
	/// @return												@trueIfOtherwiseFalse{the alias translator was initialized}
	//----------------------------------------------------------------------------------------
	Bool Init(BaseDocument* doc) { return C4DOS.Ln->TrnInit(this, doc); }

	//----------------------------------------------------------------------------------------
	/// Translates the links in all objects that the translator has come across.
	/// @param[in] connect_oldgoals		Connect old goals.\n
	/// 															For example: Take a cube with an instance linked to this cube, select both and duplicate them in one action.\n
	/// 															The new cube is linked to the new instance if @formatParam{connect_oldgoals} is @formatConstant{true}. If it is @formatConstant{false} the new instance is linked to the old cube.
	//----------------------------------------------------------------------------------------
	void Translate(Bool connect_oldgoals) { C4DOS.Ln->TrnTranslate(this, connect_oldgoals); }

	/// @}
};


//-------------------------------------------------------------------------------------------------
/// This is the class used for plugin scene loaders.
/// @see See SceneLoaderData.
//-------------------------------------------------------------------------------------------------
class BaseSceneLoader : public BaseList2D
{
private:
	BaseSceneLoader();
	~BaseSceneLoader();
};


//-------------------------------------------------------------------------------------------------
/// This is the class used for plugin scene savers.
/// @see See SceneSaverData.
//-------------------------------------------------------------------------------------------------
class BaseSceneSaver : public BaseList2D
{
private:
	BaseSceneSaver();
	~BaseSceneSaver();
};


/// @addtogroup c4d_baselist_shaderchannelmessage Shader/Channel Message
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Needs to be called by all shaders in NodeData::Message() if they have subchannels.\n
/// Here is an example:
/// @code
/// Bool CSLAFusion::Message(GeListNode* pNode, Int32 messageType, void* pMessageData)
/// {
/// 	BaseContainer* pData = ((BaseShader*)node)->GetDataInstance();
/// 	HandleInitialChannel(node, SLA_FUSION_BASE_CHANNEL, messageType, pMessageData);
/// 	HandleShaderMessage(node, (BaseShader*)pData->GetLink(SLA_FUSION_BLEND_CHANNEL, node->GetDocument(), Xbase), messageType, pMessageData);
/// 	HandleShaderMessage(node, (BaseShader*)pData->GetLink(SLA_FUSION_MASK_CHANNEL, node->GetDocument(), Xbase), messageType, pMessageData);
/// 	HandleShaderMessage(node, (BaseShader*)pData->GetLink(SLA_FUSION_BASE_CHANNEL, node->GetDocument(), Xbase), messageType, pMessageData);
/// 	return true;
/// }
/// @endcode
/// @param[in] node								The shader node. @callerOwnsPointed{shader node}
/// @param[in] ps									The subchannel shader. @callerOwnsPointed{shader node}
/// @param[in] type								The message type.
/// @param[in] data								The message data.
//----------------------------------------------------------------------------------------
void HandleShaderMessage(GeListNode* node, BaseShader* ps, Int32 type, void* data);

//-------------------------------------------------------------------------------------------------
/// @markDeprecated
//-------------------------------------------------------------------------------------------------
void HandleInitialChannel(GeListNode* node, Int32 id, Int32 type, void* data);

/// @}

/// @addtogroup c4d_baselist_transitionscale Translation Scale
/// @ingroup group_function
/// @{

//----------------------------------------------------------------------------------------
/// Calculates the scale between @formatParam{src} and @formatParam{dst} unit scale data.
/// @param[in] src								The source unit scale data.
/// @param[in] dst								The destination unit scale data.
/// @return												The scale between @formatParam{src} and @formatParam{dst}.
//----------------------------------------------------------------------------------------
Float CalculateTranslationScale(const UnitScaleData* src, const UnitScaleData* dst);

//----------------------------------------------------------------------------------------
/// Calculates the scale between @formatParam{sdoc} and @formatParam{ddoc} documents.
/// @param[in] sdoc								The source document.
/// @param[in] ddoc								The destination document.
/// @return												The scale between @formatParam{sdoc} and @formatParam{ddoc}.
//----------------------------------------------------------------------------------------
Float CalculateTranslationScale(BaseDocument* sdoc, BaseDocument* ddoc);

//----------------------------------------------------------------------------------------
/// Returns the corresponding BaseList element for a GraphNode. This function creates a new one if not already present.
/// @param[in] nbm								The nimbus class reference.
/// @param[in] nodePath						Absolute Path to the Node.
/// @return												BaseList2D element. The return value can be nullptr in case no element can be created for the given path, e.g. if it is invalid
///																of refers to an inner node.
//----------------------------------------------------------------------------------------
maxon::Result<BaseList2D*> NbmFindOrCreateCorrespondingBaseList(maxon::NimbusInterface* nbm, const maxon::CString& nodePath);

//----------------------------------------------------------------------------------------
/// Calculates the DescID for a given port.
/// @param[in] nbm								The nimbus class reference.
/// @param[in] node								The node that owns the port.
/// @param[in] port								The port.
/// @param[out] result						The description ID of the port.
/// @return												OK on success. If no description representation exists an error will be returned.
//----------------------------------------------------------------------------------------
maxon::Result<void> NbmPortToDescID(maxon::NimbusInterface* nbm, const maxon::GraphNode& node, const maxon::GraphNode& port, DescID& result);

/// @}

#endif // __API_INTERN__

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // C4D_BASELIST_H__
