/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef CUSTOMGUI_DESCRIPTION_H__
#define CUSTOMGUI_DESCRIPTION_H__

#include "customgui_base.h"
#include "c4d_basecontainer.h"
#include "maxon/delegate.h"

class AtomArray;
class DescID;
class Description;
struct DescriptionGuiLib;

/// Description custom GUI ID.
#define CUSTOMGUI_DESCRIPTION			1000469

/// @addtogroup DESCRIPTION_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
#define DESCRIPTION_ALLOWFOLDING				'fldg'			///< ::Bool Allow folding.
#define DESCRIPTION_SHOWTITLE						'titl'			///< ::Bool Show title.
#define DESCRIPTION_NOUNDO							'noun'			///< ::Bool No undo.
#define DESCRIPTION_OBJECTSNOTINDOC			'onid'			///< ::Bool Objects are not located in document.
#define DESCRIPTION_FORCEGETOBJECT			'fget'			///< ::Bool Force retrieve the objects regardless of document state.
#define DESCRIPTION_MODALMODE						'modl'			///< ::Int32 Mode for modal dialogs: @em 1==normal, @em 2==no scrollareas
#define DESCRIPTION_LEFTMATEDITREGION		'lmer'			///< ::Bool Mode for left %Material Manager region.
#define DESCRIPTION_STORAGE							'stor'			///< BaseContainer* Pointer to layout storage, stored as @c void.
#define DESCRIPTION_FOLDERSTORE					'fsto'			///< BaseContainer* Pointer to layout storage, stored as @c void.
#define DESCRIPTION_SCALE_ALL_ELEMENTS	'sael'			///< ::Bool Scale all elements.
#define DESCRIPTION_NO_SHOW_SUBCHANNELS	'nssc'			///< ::Bool Remove "Show Sub-channels" the context menu.
#define DESCRIPTION_OPEN_ALL_GROUPS			'opag'			///< ::Bool Unfold all parameter groups.
#define DESCRIPTION_NO_TAKE_OVERRIDES		'ntov'			///< ::Bool: If @formatConstant{true} ignore the overrides enabling/disabling. @since R17.032
#define DESCRIPTION_SINGLEDESC_MODE			'sing'			///< @markPrivate @since R17.032
#define DESCRIPTION_MANAGER_TYPE				'mgrt'			///< @markPrivate
#define DESCRIPTION_HIDE_EMPTY_GROUPS		'hegr'			///< ::Bool Hides empty User Data groups @since R20
#define DESCRIPTION_HIDE_LAYOUT_SWITCH	'hlsw'			///< ::Bool Hides fold arrow @since R20

/// @}

//----------------------------------------------------------------------------------------
/// Callback function.
/// @param[in] master							The registered dialog pointer.
/// @param[in] msg								The message container: @enumerateEnum{MCB}
/// @return												The result.
//----------------------------------------------------------------------------------------
typedef GeData MasterCallBackFunc(GeDialog *master, const BaseContainer &msg);
/// @addtogroup MCB
/// @ingroup group_enumeration
/// @{
#define MCB_NAVIGATIONCHANGED					'navc'			///< The navigation tabs have changed. The message container contains the full names of the navigation tabs.
#define MCB_SETATOMARRAY							'seta'			///< @markPrivate
/// @}

//----------------------------------------------------------------------------------------
/// Allows to query the number of active objects:
/// @code
/// Int32 cnt = sub->MasterMessage(BaseContainer(MM_HASOBJECTS)).GetInt32();
/// @endcode
//----------------------------------------------------------------------------------------
#define MM_HASOBJECTS									'haso'

struct DescriptionFilter
{
	//----------------------------------------------------------------------------------------
	/// @markPrivate Description filter callback. Registered with DescriptionCustomGui::SetFilter().\n
	/// Checks if the description element @formatParam{id} should be visible.
	/// Arguments in order are description, entry_id, entry_container, sub_filter, hide.
	//----------------------------------------------------------------------------------------
	maxon::Delegate<Bool(const Description*, const DescID &, const BaseContainer &, Bool &, Bool &)> FilterID;
};

/// Attribute Manager filter flags.
enum class AMFILTERFLAGS
{
	NONE = 0,											 ///< None.
	SHOWHIDDEN = 1 << 0,					 ///< Show hidden parameters.
	SHOWANIMONLY = 1 << 1,				 ///< Show animated parameters.
	SHOWLOCKED = 1 << 2,					 ///< Show locked parameters.
	HIDEINLINEATTRIBUTES = 1 << 3, ///< Hide attributes if marked with DESC_HIDE_WHEN_INLINE
} MAXON_ENUM_FLAGS(AMFILTERFLAGS);


#ifndef _INTERNAL_DEF_CUSTOMGUI_DESCRIPTION

//----------------------------------------------------------------------------------------
/// Attribute Manager custom GUI (@ref CUSTOMGUI_DESCRIPTION).\n
/// Here are the settings: @enumerateEnum{DESCRIPTION_CUSTOMGUISETTINGS}
//----------------------------------------------------------------------------------------
class DescriptionCustomGui : public BaseCustomGui<CUSTOMGUI_DESCRIPTION>
{
		DescriptionCustomGui();
		~DescriptionCustomGui();

	public:
		//----------------------------------------------------------------------------------------
		/// Registers the master callback function.
		/// @param[in] dlg								The parent dialog. @callerOwnsPointed{dialog}
		/// @param[in] func								The callback function.
		//----------------------------------------------------------------------------------------
		void SetMaster(GeDialog *dlg, MasterCallBackFunc *func);

		//----------------------------------------------------------------------------------------
		/// Sends a master message to the custom GUI.
		/// @param[in] msg								The message: ::MM_HASOBJECTS.
		/// @return												The result.
		//----------------------------------------------------------------------------------------
		GeData MasterMessage(const BaseContainer &msg);

		//----------------------------------------------------------------------------------------
		/// Sets the objects that are shown.
		/// @param[in] list								The objects to show.
		/// @param[in] limitExceeded			Set to true if if the object count exceeded some limit.
		//----------------------------------------------------------------------------------------
		void SetObjectList(const AtomArray &list, Bool limitExceeded = false);

		//----------------------------------------------------------------------------------------
		/// Sets a single objects to show.
		/// @param[in] op									The object to show. @callerOwnsPointed{object}
		//----------------------------------------------------------------------------------------
		void SetObject(C4DAtom *op);

		//----------------------------------------------------------------------------------------
		/// Retrieves the objects that are shown.
		/// @param[out] list							Filled with the objects shown.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool GetObjectList(AtomArray &list);

		//----------------------------------------------------------------------------------------
		/// @markPrivate Registers a filter callback for the description.
		/// @param[in] flt								The callback structure, or @formatConstant{nullptr} to unregister the filter. @callerOwnsPointed{structure}
		//----------------------------------------------------------------------------------------
		void SetFilter(DescriptionFilter *flt);

		//----------------------------------------------------------------------------------------
		/// @markPrivate
		//----------------------------------------------------------------------------------------
		DescID HighlightDescID(const DescID& id, Bool check);

		//----------------------------------------------------------------------------------------
		/// Sets the active description tab.
		/// @param[in] activetab					The tab's page description ID.
		//----------------------------------------------------------------------------------------
		void SetActiveTabPage(const DescID &activetab);

		//----------------------------------------------------------------------------------------
		/// Retrieves the description IDs of the selected description elements.
		/// @param[out] selection					Filled with the description IDs of the selected description elements. The container elements' type is ::CUSTOMDATATYPE_DESCID.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool GetDescIDSelection(BaseContainer &selection);

		//----------------------------------------------------------------------------------------
		/// Gets the current filter string and flags.
		/// @param[out] flags							Assigned the filter flags: @enumerateEnum{AMFILTERFLAGS}
		/// @return												The current filter string.
		//----------------------------------------------------------------------------------------
		String GetFilterString(AMFILTERFLAGS &flags);

		//----------------------------------------------------------------------------------------
		/// Sets the current filter string and flags.
		/// @param[in] filter							The filter string.
		/// @param[in] flags							The filter flags: @enumerateEnum{AMFILTERFLAGS}
		//----------------------------------------------------------------------------------------
		void SetFilterString(const maxon::String &filter, AMFILTERFLAGS flags);

		//----------------------------------------------------------------------------------------
		/// Sets a lambda function that you can use to translate any DescID within the Description via.
		/// @param[in] func								The translation lambda function, follows the same signature as
		/// 															C4DAtom::TranslateDescID.
		/// @param[in] objectControl			(Optional) True to not translate for GetDEnabling (leave control with the original object).
		//----------------------------------------------------------------------------------------
		void SetTranslation(const maxon::Delegate<Bool(GeListNode* node, const DescID& id, DescID& resultId, C4DAtom*& resultAtom)>& func, Bool objectControl = false);

		/// Clears the function set by SetParentTranslation.
		void ClearTranslation();

		//----------------------------------------------------------------------------------------
		/// @markprivate Sets a lambda function that you can use to modify the description shown in the
		/// attributes manager
		/// @param[in] func								The modification function.
		/// @return												OK on success.
		//----------------------------------------------------------------------------------------
		maxon::Result<void> ModifyDescription(maxon::Delegate<void(GeListNode* node, Description& description, DESCFLAGS_DESC flags)>&& func);

		/// Clears the function set by ModifyDescription
		void ClearModifyDescription();
};

#endif

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

#if !defined _INTERNAL_DEF_ && !defined __API_INTERN__
	class iDescriptionCustomGui
	{
	};
#else
	class iDescriptionCustomGui;
#endif

struct DescriptionGuiLib : public BaseCustomGuiLib
{
	void			(iDescriptionCustomGui::*SetObjectList)(const AtomArray &list, Bool limitExceeded);
	void			(iDescriptionCustomGui::*SetObject)(C4DAtom *op);
	Bool			(iDescriptionCustomGui::*GetObjectList)(AtomArray &list);
	void			(iDescriptionCustomGui::*SetMaster)(GeDialog *dlg, MasterCallBackFunc *func);
	GeData		(iDescriptionCustomGui::*MasterMessage)(const BaseContainer &msg);
	void			(iDescriptionCustomGui::*SetFilter)(DescriptionFilter *flt);
	DescID		(iDescriptionCustomGui::*HighlightDescID)(const DescID& id, Bool check);
	void			(iDescriptionCustomGui::*SetActiveTabPage)(const DescID &activetab);
	Bool			(iDescriptionCustomGui::*GetDescIDSelection)(BaseContainer &selection);
	void			(iDescriptionCustomGui::*SetFilterString)(const String &str, AMFILTERFLAGS flags);
	String		(iDescriptionCustomGui::*GetFilterString)(AMFILTERFLAGS &flags);
	void			(iDescriptionCustomGui::*SetTranslation)(const maxon::Delegate<Bool(GeListNode* node, const DescID& id, DescID& resultId, C4DAtom*& resultAtom)>& func, Bool objectControl);
	void			(iDescriptionCustomGui::*ClearTranslation)();
	maxon::Result<void> (iDescriptionCustomGui::*ModifyDescription)(maxon::Delegate<void(GeListNode* node, Description& description, DESCFLAGS_DESC flags)>&& func);
	void			(iDescriptionCustomGui::*ClearModifyDescription)();

};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // CUSTOMGUI_DESCRIPTION_H__
