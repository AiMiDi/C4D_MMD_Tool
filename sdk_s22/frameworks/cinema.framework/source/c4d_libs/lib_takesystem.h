/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_TAKESYSTEM_H__
#define LIB_TAKESYSTEM_H__

#include "c4d_library.h"
#include "ge_math.h"
#include "lib_description.h"

#ifdef __API_INTERN__
	#include "pluginobject.h"
	#include "plugintag.h"

#else
	#include "c4d_baseobject.h"
	#include "c4d_basetag.h"
#endif

/// @addtogroup group_takesystemlibrary Take System Library
/// @ingroup group_library
/// @{
/// @since R17.032
/// @see The @ref page_overview_takesystem article.

/// Take System library ID.
#define ID_TAKESYSTEM_LIB	431000064

///
#define ENABLING_BIT_DESCID	NOTOK

class BaseTake;
class BaseOverrideGroup;

/// @addtogroup TAKE_MODE
/// @{
/// Take System main mode. Defines the workflow to override parameters.
enum class TAKE_MODE
{
	MANUAL	= 0,			///< Manual override: the user has to explicitly override every single parameter.
	AUTO							///< Auto override: the system overrides any edited parameter (similar to Auto Key).
} MAXON_ENUM_LIST(TAKE_MODE);
/// @}

/// @addtogroup OVERRIDEENABLING
/// @{
/// The types of nodes that can be overridden based on global GUI switch.
enum class OVERRIDEENABLING
{
	NONE											= 0,							///< None.
	OBJECT									= (1 << 0),				///< Object override enabled.
	TAG										= (1 << 1),				///< Tag override enabled.
	MATERIAL								= (1 << 2),				///< Material override enabled.
	SHADER									= (1 << 3),				///< Shader override enabled.
	LAYER									= (1 << 4),				///< Layer override enabled.
	OTHER									= (1 << 5),				///< Other types override enabled.
	GLOBAL									= (1 << 6),				///< Main switch types override enabled.

	ENABLING								= (1 << 7),				///< Object enabling and visibility override enabled.
	TRANSFOM								= (1 << 8),				///< Transformation override enabled.
	CAMERA									= (1 << 9),				///< Active camera override enabled.
	RS											= (1 << 10),			///< Active render settings override enabled.
	PARAM									= (1 << 11)				///< Generic parameter override enabled.
} MAXON_ENUM_FLAGS(OVERRIDEENABLING);
/// @}

//----------------------------------------------------------------------------------------
/// An Override holds the settings for a specific object in a @link BaseTake Take@endlink.
/// @see The @ref page_manual_baseoverride overview article.
//----------------------------------------------------------------------------------------
class BaseOverride : public BaseList2D
{
	INSTANCEOF(BaseOverride, BaseList2D)

#ifndef __API_INTERN__
private:
	BaseOverride();
	~BaseOverride();
#endif

public:

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next Override in the list. Convenience version of GeListNode::GetNext() returning a @ref BaseOverride*.
	/// @return												The next Override, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{BaseOverride}
	//----------------------------------------------------------------------------------------
	BaseOverride* GetNext() const { return (BaseOverride*)AtCall(GetNext)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous Override in the list. Convenience version of GeListNode::GetPred() returning a @ref BaseOverride*.
	/// @return												The previous Override, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{BaseOverride}
	//----------------------------------------------------------------------------------------
	BaseOverride* GetPred() const { return (BaseOverride*)AtCall(GetPred)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the parent Override of the list node. Convenience version of GeListNode::GetUp() returning a @ref BaseOverride*.
	/// @return												The parent Override, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{BaseOverride}
	//----------------------------------------------------------------------------------------
	BaseOverride* GetUp() const { return (BaseOverride*)AtCall(GetUp)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the first child Override of the list node. Convenience version of GeListNode::GetDown() returning a @ref BaseOverride*.
	/// @return												The first child Override, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{BaseOverride}
	//----------------------------------------------------------------------------------------
	BaseOverride* GetDown() const { return (BaseOverride*)AtCall(GetDown)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the last child Override of the list node. Convenience version of GeListNode::GetDownLast() returning a @ref BaseOverride*.
	/// @return												The last child Override, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{BaseOverride}
	//----------------------------------------------------------------------------------------
	BaseOverride* GetDownLast() const { return (BaseOverride*)AtCall(GetDownLast)(); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if the parameter at @formatParam{descID} is overridden.
	/// @param[in] descID							The parameter to be checked.
	/// @return												@trueIfOtherwiseFalse{parameter is overridden}
	//----------------------------------------------------------------------------------------
	Bool IsOverriddenParam(const DescID& descID);

	//----------------------------------------------------------------------------------------
	/// Returns a pointer to the original scene node connected to the Override node.
	/// @return												A pointer to the original scene node, or @formatConstant{nullptr} if any error.
	//----------------------------------------------------------------------------------------
	BaseList2D* GetSceneNode();

	//----------------------------------------------------------------------------------------
	/// Gets a pointer to the Take that owns the Override.
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @return												A pointer to the Take for this Override, or @formatConstant{nullptr} if any error. @cinemaOwnsPointed{BaseTake}
	//----------------------------------------------------------------------------------------
	BaseTake* GetOwnerTake(TakeData* takeData);

	//----------------------------------------------------------------------------------------
	/// Checks if the Override is also part of an Override Group, and if yes fills @formatParam{resGroup}.
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[out] resGroup					The assigned BaseOverrideGroup. @formatConstant{nullptr} if the function returns @formatConstant{false}. @cinemaOwnsPointed{BaseOverrideGroup}
	/// @return												@trueIfOtherwiseFalse{the Override is part of an Override Group}
	//----------------------------------------------------------------------------------------
	Bool IsInGroup(TakeData* takeData, BaseOverrideGroup*& resGroup);

	//----------------------------------------------------------------------------------------
	/// Retrieves the DescID of all parameters in the Override.
	/// @note Sub-descriptions are included if overridden.
	/// @param[out] result						The array to be filled.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetAllOverrideDescID(maxon::BaseArray<DescID>& result);

	//----------------------------------------------------------------------------------------
	/// Updates the scene node whenever data is directly changed on the base Override (for example with @ref SetParameter).\n
	/// This ensures the scene node is properly updated if the Override affects the current document state.
	/// @note An undo step is added automatically if the call is added from the main (GUI) thread and global undo is allowed (see @ref TakeData::GetUndoState/@ref TakeData::SetUndoState).
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] descID							The DescID of the edited parameter.
	//----------------------------------------------------------------------------------------
	void UpdateSceneNode(TakeData* takeData, const DescID& descID);

	/// @}
};

//----------------------------------------------------------------------------------------
/// An Override Group manages the values of multiple objects in a @link BaseTake Take@endlink.
/// @see The @ref page_manual_baseoverridegroup overview article.
//----------------------------------------------------------------------------------------
class BaseOverrideGroup : public BaseList2D
{
	INSTANCEOF(BaseOverrideGroup, BaseList2D)

#ifndef __API_INTERN__
private:
	BaseOverrideGroup();
	~BaseOverrideGroup();
#endif

public:

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next Override Group in the list. Convenience version of GeListNode::GetNext() returning a @ref BaseOverrideGroup*.
	/// @return												The next Override group, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{BaseOverrideGroup}
	//----------------------------------------------------------------------------------------
	BaseOverrideGroup* GetNext() const { return (BaseOverrideGroup*)AtCall(GetNext)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous Override Group in the list. Convenience version of GeListNode::GetPred() returning a @ref BaseOverrideGroup*.
	/// @return												The previous Override group, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{BaseOverrideGroup}
	//----------------------------------------------------------------------------------------
	BaseOverrideGroup* GetPred() const { return (BaseOverrideGroup*)AtCall(GetPred)(); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves all the objects in the group.
	/// @param[out] selection					The AtomArray to be filled.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetObjectsInGroup(AtomArray& selection);

	//----------------------------------------------------------------------------------------
	/// Adds @formatParam{node} to the Override Group. If @formatParam{node} is already part of another group it will be automatically removed first.
	/// @warning The node to add must be a real scene node. Adding BaseOverride nodes is forbidden.
	/// @note An undo step is added automatically if the call is added from the main (GUI) thread and global undo is allowed (see @ref TakeData::GetUndoState/@ref TakeData::SetUndoState).
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] node								The node to add. @callerOwnsPointed{BaseList2D}
	//----------------------------------------------------------------------------------------
	void AddToGroup(TakeData* takeData, BaseList2D* node);

	//----------------------------------------------------------------------------------------
	/// Removes @formatParam{node} from the Override Group.
	/// @note An undo step is added automatically if the call is added from the main (GUI) thread and global undo is allowed (see @ref TakeData::GetUndoState/@ref TakeData::SetUndoState).
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] node								The node to remove. If @formatParam{node} is not part of the group the function returns. @callerOwnsPointed{node}
	//----------------------------------------------------------------------------------------
	void RemoveFromGroup(TakeData* takeData, BaseList2D* node);

	//----------------------------------------------------------------------------------------
	/// Adds a new tag of the given @formatParam{type} to the Override Group if it is not already there.
	/// @warning Only tags registered with flag @ref TAG_ADDTOTAKEGROUP are accepted by the group.
	/// @note An undo step is added automatically if the call is added from the main (GUI) thread and global undo is allowed (see @ref TakeData::GetUndoState/@ref TakeData::SetUndoState).
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] type								The tag type to be added. If the tag is already in the group the function returns.\n
	/// 															If @ref Ttexture the material can be assigned to @formatParam{mat}.
	/// @param[in] mat								The optional material if passed @formatParam{type} is @ref Ttexture.
	/// @return												The tag. The added one if created by the function or the one already in the group.
	//----------------------------------------------------------------------------------------
	BaseTag* AddTag(TakeData* takeData, Int32 type, BaseMaterial* mat);

	//----------------------------------------------------------------------------------------
	/// Removes the tag of the given @formatParam{type} from the Override Group.
	/// @note An undo step is added automatically if the call is added from the main (GUI) thread and global undo is allowed (see @ref TakeData::GetUndoState/@ref TakeData::SetUndoState).
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] type								The tag type to be removed. If the tag type is not in the Group the function returns.
	//----------------------------------------------------------------------------------------
	void RemoveTag(TakeData* takeData, Int32 type);

	/// @}

	/// @name Visibility Modes
	/// @{

	//----------------------------------------------------------------------------------------
	/// Returns the editor visibility mode for the Override Group.
	/// @return												The editor mode: @enumerateEnum{MODE}
	//----------------------------------------------------------------------------------------
	Int32 GetEditorMode();

	//----------------------------------------------------------------------------------------
	/// Returns the render visibility mode for the Override Group.
	/// @return												The render mode: @enumerateEnum{MODE}
	//----------------------------------------------------------------------------------------
	Int32 GetRenderMode();

	//----------------------------------------------------------------------------------------
	/// Sets the editor visibility mode for the Override Group.
	/// @param[in] mode								The editor mode to set: @enumerateEnum{MODE}
	//----------------------------------------------------------------------------------------
	void SetEditorMode(Int32 mode);

	//----------------------------------------------------------------------------------------
	/// Sets the render visibility mode for the Override Group.
	/// @param[in] mode								The render mode to set: @enumerateEnum{MODE}
	//----------------------------------------------------------------------------------------
	void SetRenderMode(Int32 mode);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Searches for a tag of the given @formatParam{type} attached to the Override Group.
	/// @param[in] type								The tag type to search for.
	/// @return												The tag if found, otherwise @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	BaseTag* GetTag(Int32 type);

	//----------------------------------------------------------------------------------------
	/// Returns the Take that owns the Override Group.
	/// @return												The owner Take, or @formatConstant{nullptr} if any error.
	//----------------------------------------------------------------------------------------
	BaseTake* GetTake();

	//----------------------------------------------------------------------------------------
	/// Checks if an object is included in the Override Group.
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] op									The object to check. @callerOwnsPointed{BaseObject}
	/// @return												@trueIfOtherwiseFalse{the object is included in the Override Group}
	//----------------------------------------------------------------------------------------
	Bool Find(TakeData* takeData, BaseObject* op);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Represents a Take of the @link TakeData Take System@endlink. It stores BaseOverride objects that define how a specific entity is changed in a Take.
/// @note To retrieve the Take System for a document simply call BaseDocument::GetTakeData().
/// @see The @ref page_manual_basetake overview article.
//----------------------------------------------------------------------------------------
class BaseTake : public BaseList2D
{
	INSTANCEOF(BaseTake, BaseList2D)

#ifndef __API_INTERN__
private:
	BaseTake();
	~BaseTake();
#endif

public:

	/// @name Navigation
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the next Take in the list. Convenience version of GeListNode::GetNext() returning a @ref BaseTake*.
	/// @return												The next Take, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{BaseTake}
	//----------------------------------------------------------------------------------------
	BaseTake* GetNext() const { return (BaseTake*)AtCall(GetNext)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the previous Take in the list. Convenience version of GeListNode::GetPred() returning a @ref BaseTake*.
	/// @return												The previous Take, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{BaseTake}
	//----------------------------------------------------------------------------------------
	BaseTake* GetPred() const { return (BaseTake*)AtCall(GetPred)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the parent Take of the list node. Convenience version of GeListNode::GetUp() returning a @ref BaseTake*.
	/// @return												The parent Take, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{BaseTake}
	//----------------------------------------------------------------------------------------
	BaseTake* GetUp() const { return (BaseTake*)AtCall(GetUp)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the first child Take of the list node. Convenience version of GeListNode::GetDown() returning a @ref BaseTake*.
	/// @return												The first child Take, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{BaseTake}
	//----------------------------------------------------------------------------------------
	BaseTake* GetDown() const { return (BaseTake*)AtCall(GetDown)(); }

	//----------------------------------------------------------------------------------------
	/// Gets the last child Take of the list node. Convenience version of GeListNode::GetDownLast() returning a @ref BaseTake*.
	/// @return												The last child Take, or @formatConstant{nullptr} if there is none. @cinemaOwnsPointed{BaseTake}
	//----------------------------------------------------------------------------------------
	BaseTake* GetDownLast() const { return (BaseTake*)AtCall(GetDownLast)(); }

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if the Take is the Main Take.
	/// @return												@trueIfOtherwiseFalse{the Take is the Main Take}
	//----------------------------------------------------------------------------------------
	Bool IsMain();

	//----------------------------------------------------------------------------------------
	/// Checks if the Take is a child of @formatParam{op}.
	/// @param[in] op									The Take to search within his hierarchy. @callerOwnsPointed{BaseTake}
	/// @return												@trueIfOtherwiseFalse{the Take is child of @formatParam{op}}
	//----------------------------------------------------------------------------------------
	Bool SearchHierarchy(BaseTake* op);

	/// @}

	/// @name Override
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves all Override nodes owned by the Take.
	/// @param[out] selection					The AtomArray to be filled.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetOverrides(AtomArray& selection);

	//----------------------------------------------------------------------------------------
	/// Retrieves all Override Groups nodes owned by the Take.
	/// @param[out] selection					The AtomArray to be filled.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetOverrideGroups(AtomArray& selection);

	//----------------------------------------------------------------------------------------
	/// Searches if parameter with @formatParam{descID} is Overridden. If not adds a new Override with passed value for the Take.\n
	/// If the BaseOverride node does not exist the function automatically allocates and inserts it, plus takes care to backup data properly in parent or Main Take.
	/// @note An undo step is added automatically if the call is added from the main (GUI) thread and global undo is allowed (see @ref TakeData::GetUndoState/@ref TakeData::SetUndoState).
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] node								The scene node to override. @callerOwnsPointed{BaseList2D}
	/// @param[in] descID							The parameter DescID to override.
	/// @param[in] overrideValue			The initial value to set in the overrides for the Take.
	/// @param[in] backupValue				Optionally provide the backup value for the Main/parent Take. Mandatory to set this for parameters not from the GUI.
	/// @param[in] deleteAnim					If @formatParam{true} and original parameter in the scene is animated the animation will be removed in the resulting Override.
	/// @return												The found or newly created BaseOverride node, or @formatParam{nullptr} if any error.
	//----------------------------------------------------------------------------------------
	BaseOverride* FindOrAddOverrideParam(TakeData* takeData, BaseList2D* node, const DescID& descID, const GeData& overrideValue, const GeData& backupValue = GeData(), Bool deleteAnim = false);

	//----------------------------------------------------------------------------------------
	/// Overrides all parameters of passed node in the Take.
	/// @note An undo step is added automatically if the call is added from the main (GUI) thread and global undo is allowed (see @ref TakeData::GetUndoState/@ref TakeData::SetUndoState).
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] node								The scene node to override. @callerOwnsPointed{BaseList2D}
	/// @param[in] deleteAnim					If @formatParam{true} and original parameter in the scene is animated the animation will be removed in the resulting Override.
	/// @return												The newly created BaseOverride node, or @formatParam{nullptr} if any error.
	//----------------------------------------------------------------------------------------
	BaseOverride* OverrideNode(TakeData* takeData, BaseList2D* node, Bool deleteAnim);

	//----------------------------------------------------------------------------------------
	/// Compares nodes and automatically generates overrides for different parameters in the Take.
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] node								The scene node to override. @callerOwnsPointed{BaseList2D}
	/// @param[in] undo								The node to compare with. @callerOwnsPointed{BaseList2D}
	//----------------------------------------------------------------------------------------
	void AutoTake(TakeData* takeData, BaseList2D* node, BaseList2D* undo);

	//----------------------------------------------------------------------------------------
	/// Deletes a single parameter override for @formatParam{node} with @formatParam{descID}. If the Override results empty (no more overridden parameters) then it will be deleted too.
	/// @note An undo step is added automatically if the call is added from the main (GUI) thread and global undo is allowed (see @ref TakeData::GetUndoState/@ref TakeData::SetUndoState).
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] node								The scene node to delete the parameter for. @callerOwnsPointed{BaseList2D}
	/// @param[in] descID							The parameter DescID to be deleted.
	//----------------------------------------------------------------------------------------
	void DeleteOverride(TakeData* takeData, BaseList2D* node, const DescID& descID);

	//----------------------------------------------------------------------------------------
	/// Searches if @formatParam{node} is overridden in the Take.
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] node								The node to search the BaseOverride for. @callerOwnsPointed{BaseList2D}
	/// @return												The BaseOverride if found, otherwise @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	BaseOverride* FindOverride(TakeData* takeData, BaseList2D* node);

	//----------------------------------------------------------------------------------------
	/// Searches if @formatParam{node} parameter with @formatParam{descID} is overridden in the Take or in a parent.
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] node								The node to search the BaseOverride for. @callerOwnsPointed{BaseList2D}
	/// @param[in] descID							The parameter DescID to search for.
	/// @param[out] resultTake				Filled with The Take that owns the Override. Can be equal to @c *this or @formatConstant{nullptr} if the Override is not found. @callerOwnsPointed{BaseTake}
	/// @return												The BaseOverride if found, otherwise @formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	BaseOverride* FindOverrideInHierarchy(TakeData* takeData, BaseList2D* node, const DescID& descID, BaseTake*& resultTake);

	//----------------------------------------------------------------------------------------
	/// Adds a new Override Group to the Take.
	/// @note An undo step is added automatically if the call is added from the main (GUI) thread and global undo is allowed (see @ref TakeData::GetUndoState/@ref TakeData::SetUndoState).
	/// @return												The added Override Group, or @formatConstant{nullptr} if any error.
	//----------------------------------------------------------------------------------------
	BaseOverrideGroup* AddOverrideGroup();

	//----------------------------------------------------------------------------------------
	/// Gets the first Override Group in the Take.
	/// @return												The first Override Group, or @formatConstant{nullptr} if there is none.
	//----------------------------------------------------------------------------------------
	BaseOverrideGroup* GetFirstOverrideGroup();

	//----------------------------------------------------------------------------------------
	/// Deletes an Override Group from the Take.
	/// @note An undo step is added automatically if the call is added from the main (GUI) thread and global undo is allowed (see @ref TakeData::GetUndoState/@ref TakeData::SetUndoState).
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] og									The Override Group to be deleted. @callerOwnsPointed{BaseOverrideGroup}
	//----------------------------------------------------------------------------------------
	void DeleteOverrideGroup(TakeData* takeData, BaseOverrideGroup* og);

	/// @}

	/// @name Camera
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the camera for the Take.
	/// @note Can return the default camera.
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @return												The camera assigned to the Take, or @formatConstant{nullptr} if the Take uses the camera from a parent Take.
	//----------------------------------------------------------------------------------------
	BaseObject* GetCamera(TakeData* takeData);

	//----------------------------------------------------------------------------------------
	/// Gets the camera used by the Take even if it comes from a parent Take.
	/// @note Can return the default camera.
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[out] resultTake				The Take the camera comes from. @cinemaOwnsPointed{BaseTake}
	/// @return												The camera used by the Take.
	//----------------------------------------------------------------------------------------
	BaseObject* GetEffectiveCamera(TakeData* takeData, BaseTake*& resultTake);

	//----------------------------------------------------------------------------------------
	/// Sets the camera for the Take.
	/// @note Can be the default camera.
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] camera							The camera to set, or @formatConstant{nullptr} to reset and use one from a parent Take.
	//----------------------------------------------------------------------------------------
	void SetCamera(TakeData* takeData, BaseObject* camera);

	/// @}

	/// @name RenderData
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the RenderData for the Take.
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @return												The RenderData assigned to the Take, or @formatConstant{nullptr} if the Take uses the RenderData from a parent Take.
	//----------------------------------------------------------------------------------------
	RenderData* GetRenderData(TakeData* takeData);

	//----------------------------------------------------------------------------------------
	/// Gets the RenderData used by the Take even if it comes from a parent Take.
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[out] resultTake				The Take the RenderData come from. @cinemaOwnsPointed{BaseTake}
	/// @return												The RenderData used by the Take.
	//----------------------------------------------------------------------------------------
	RenderData* GetEffectiveRenderData(TakeData* takeData, BaseTake*& resultTake);

	//----------------------------------------------------------------------------------------
	/// Sets the RenderData for the Take.
	/// @param[in] takeData						The Take System context. @callerOwnsPointed{TakeData}
	/// @param[in] rData							The RenderData to set, or @formatConstant{nullptr} to reset and use one from a parent Take. @callerOwnsPointed{RenderData}
	//----------------------------------------------------------------------------------------
	void SetRenderData(TakeData* takeData, RenderData* rData);

	/// @}

	/// @name Checked
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the mark status of the Take used for rendering and export operations.
	/// @return												@trueIfOtherwiseFalse{the Take is marked}
	//----------------------------------------------------------------------------------------
	Bool IsChecked();

	//----------------------------------------------------------------------------------------
	/// Sets the mark status of the Take used for rendering and export operations.
	/// @param[in] status							If @formatConstant{true} the Take will be marked otherwise the mark will be removed.
	//----------------------------------------------------------------------------------------
	void SetChecked(Bool status);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Resets all sub-structures and Overrides for the Take.
	/// @warning All data not in the current state of the document are deleted.
	//----------------------------------------------------------------------------------------
	void Reset();

	/// @}
};

//----------------------------------------------------------------------------------------
/// Stores the Take System related data of a BaseDocument.
/// @see The @ref page_manual_takedata overview article.
//----------------------------------------------------------------------------------------
class TakeData
{
private:
	C4D_RESERVE_PRIVATE_TYPE(void*, dummy1);

#ifndef __API_INTERN__
	TakeData();
	~TakeData();
#endif

public:

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets the internal document link for the TakeData.
	/// @markPrivate
	/// @param[in] doc								The document to attach to the TakeData. @callerOwnsPointed{BaseDocument}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Set(BaseDocument* doc);

	//----------------------------------------------------------------------------------------
	/// Retrieves the document for the TakeData.
	/// @return												The document, or @formatConstant{nullptr} if TakeData is not initialized. @cinemaOwnsPointed{BaseDocument}
	//----------------------------------------------------------------------------------------
	BaseDocument* GetDocument();

	//----------------------------------------------------------------------------------------
	/// Retrieves the Main Take.
	/// @note Main Take is always the first under the header.
	/// @return												The Main Take. Must be !@formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	BaseTake* GetMainTake();

	//----------------------------------------------------------------------------------------
	/// Retrieves the Take System global mode, can be @ref TAKE_MODE::MANUAL or @ref TAKE_MODE::AUTO.
	/// @note This mode affects how the user has to interact with GUI to override parameters.
	/// @return												The Take System mode: @enumerateEnum{TAKE_MODE}
	//----------------------------------------------------------------------------------------
	TAKE_MODE GetTakeMode();

	/// @}

	/// @name Override Enabling
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the ability for the Take System to override a specific kind of node based on global switch.
	/// @return												The Take System override enabling: @enumerateEnum{OVERRIDEENABLING}
	//----------------------------------------------------------------------------------------
	OVERRIDEENABLING GetOverrideEnabling();

	//----------------------------------------------------------------------------------------
	/// Checks for a specific @ref OVERRIDEENABLING.
	/// @param[in] mask								The Take System override enabling mask: @enumerateEnum{OVERRIDEENABLING}
	/// @return												@formatConstant{true} if the @ref OVERRIDEENABLING is set otherwise @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	Bool CheckOverrideEnabling(OVERRIDEENABLING mask);

	/// @}

	/// @name Take
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves all the selected Takes.
	/// @param[in] selection					An AtomArray to be filled with the selected Takes.
	/// @param[in] children						If @formatConstant{true} also selected Take children are collected.
	//----------------------------------------------------------------------------------------
	void GetTakeSelection(AtomArray& selection, Bool children);

	//----------------------------------------------------------------------------------------
	/// Retrieves a pointer to the current Take.
	/// @return												The current Take, or @formatConstant{nullptr} if any error. @cinemaOwnsPointed{BaseTake}
	//----------------------------------------------------------------------------------------
	BaseTake* GetCurrentTake();

	//----------------------------------------------------------------------------------------
	/// Sets the current Take.
	/// @note An undo step is added automatically if the call is added from the main (GUI) thread and global undo is allowed (see @ref TakeData::GetUndoState/@ref TakeData::SetUndoState).
	/// @param[in] take								The Take to set. If @formatConstant{nullptr} is passed the Main Take will be set. @callerOwnsPointed{BaseTake}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetCurrentTake(BaseTake* take);

	//----------------------------------------------------------------------------------------
	/// Isolates a Take in a new document.The new document will be allocated and filled by the function.
	/// @note The caller has to insert the document if necessary.
	/// @param[in] take								The Take to isolate. @callerOwnsPointed{BaseTake}
	/// @return												The allocated BaseDocument.
	//----------------------------------------------------------------------------------------
	BaseDocument* TakeToDocument(BaseTake* take);

	//----------------------------------------------------------------------------------------
	/// Executes a "Save Project With Assets" for Takes in document with each saved file representing a Take.
	/// @param[in] selected						If @formatConstant{true} only selected Takes are exported otherwise all.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SaveTakesWithAssets(Bool selected);

	//----------------------------------------------------------------------------------------
	/// Creates and inserts a new Take.
	/// @note An undo step is added automatically if the call is added from the main (GUI) thread and global undo is allowed (see @ref TakeData::GetUndoState/@ref TakeData::SetUndoState).
	/// @warning Selections have to be handled manually.
	/// @param[in] name								The name of the Take to add. If an empty string is passed default Take name will be used.
	/// @param[in] parent							Optionally pass a parent Take otherwise new Take will be added at the end of the list under the Main Take. @callerOwnsPointed{BaseTake}
	/// @param[in] cloneFrom					Optionally pass a Take the new Take will be cloned from. @callerOwnsPointed{BaseTake}
	/// @return												The new Take. Must be !@formatConstant{nullptr}.
	//----------------------------------------------------------------------------------------
	BaseTake* AddTake(const String& name, BaseTake* parent, BaseTake* cloneFrom);

	//----------------------------------------------------------------------------------------
	/// Deletes a Take and all connected overrides. If Take is the current the Main Take will be set as current.
	/// @note An undo step is added automatically if the call is added from the main (GUI) thread and global undo is allowed (see @ref TakeData::GetUndoState/@ref TakeData::SetUndoState).
	/// @param[in] take								The Take to delete. @callerOwnsPointed{BaseTake}
	//----------------------------------------------------------------------------------------
	void DeleteTake(BaseTake* take);

	//----------------------------------------------------------------------------------------
	/// Moves a Take in the hierarchy in a safe way.\n
	/// The Take system has several hierarchy dependencies.\n
	/// If a Take is moved while it is current or while it is a child of the Current Take then this would need to manually take care of all data sorting and handling.\n
	/// This function do all this work for you.\n
	/// @note An undo step is added automatically if the call is added from the main (GUI) thread and global undo is allowed (see @ref TakeData::GetUndoState/@ref TakeData::SetUndoState).
	/// @param[in] takeToMove					The Take to move. @callerOwnsPointed{BaseTake}
	/// @param[in] destTake						The parent destination Take. If @formatConstant{nullptr} the Main Take will be used. In this case NOTOK can be used as the insert mode to add the take as the last child of the main take. @callerOwnsPointed{BaseTake}
	/// @param[in] insertMode					The insertion mode. Can be @ref INSERT_BEFORE or @ref INSERT_AFTER or @ref INSERT_UNDER.
	//----------------------------------------------------------------------------------------
	void InsertTake(BaseTake* takeToMove, BaseTake* destTake, Int32 insertMode);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Finds the backup node that fits with an Override (for example the backup node in the Main Take).
	/// @param[in] overrideNode				The original Override node. @callerOwnsPointed{BaseOverride}
	/// @param[in] descID							The description ID to check.
	/// @param[out] resultTake				The Take that owns the returned node, or @formatConstant{nullptr} if no counterpart found. @cinemaOwnsPointed{BaseOverride}
	/// @return												The counterpart node, or @formatConstant{nullptr} if any error.
	//----------------------------------------------------------------------------------------
	BaseOverride* FindOverrideCounterPart(BaseOverride* overrideNode, const DescID& descID, BaseTake*& resultTake);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	void SendNodeToRepository(BaseList2D* parent, BaseList2D* node);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	BaseList2D* GetNodeFromRepository(BaseList2D* parent, BaseList2D* node);

	/// @}

	/// @name Undo
	/// @{

	//----------------------------------------------------------------------------------------
	/// Gets the state of automatic Take undo.
	/// @note It is useful to deactivate undo when working on document clones in several situation like import/export operations where undo is not important.
	/// @return												@trueIfOtherwiseFalse{the automatic undo is active}
	//----------------------------------------------------------------------------------------
	Bool GetUndoState();

	//----------------------------------------------------------------------------------------
	/// Activates or deactivates the state of automatic Take undo.
	/// @note It is useful to deactivate undo when working on document clones in several situation like import/export operations where undo is not important.
	/// @param[in] state							@trueIfOtherwiseFalse{the automatic undo has to be used}
	//----------------------------------------------------------------------------------------
	void SetUndoState(Bool state);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Resets completely the Take System. Usually not needed.
	/// @warning All data not in the current state of the document are deleted.
	//----------------------------------------------------------------------------------------
	void ResetSystem();

	/// @}
};

//----------------------------------------------------------------------------------------
/// Checks if a Take render is running.
/// @return												@trueIfOtherwiseFalse{a Take render is running}
//----------------------------------------------------------------------------------------
Bool IsTakeRenderRunning();

//----------------------------------------------------------------------------------------
/// Stops the Take render if it is running.
//----------------------------------------------------------------------------------------
void StopTakeRender();

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

class		iBaseTake;
class		iBaseOverride;
class		iBaseOverrideGroup;
class		iTakeData;

struct TakeSystemLibrary : public C4DLibrary
{
	Bool									(iBaseTake::*IsMain)												();

	Bool									(iBaseTake::*SearchHierarchy)								(iBaseTake* op);

	Bool									(iBaseTake::*GetOverrides)									(AtomArray& selection);
	Bool									(iBaseTake::*GetOverrideGroups)							(AtomArray& selection);

	iBaseOverride*				(iBaseTake::*FindOrAddOverrideParam)				(iTakeData* takeData, BaseList2D* node, const DescID& descID, const GeData& overrideValue, const GeData& backupValue, Bool deleteAnim);
	iBaseOverride*				(iBaseTake::*OverrideNode)									(iTakeData* takeData, BaseList2D* node, Bool deleteAnim);
	void 									(iBaseTake::*AutoTake)											(iTakeData* takeData, BaseList2D* node, BaseList2D* undo);
	void									(iBaseTake::*DeleteOverride)								(iTakeData* takeData, BaseList2D* node, const DescID& descID);
	iBaseOverride*				(iBaseTake::*FindOverride)									(iTakeData* takeData, BaseList2D* node);
	iBaseOverride*				(iBaseTake::*FindOverrideInHierarchy)				(iTakeData* takeData, BaseList2D* node, const DescID& descID, iBaseTake*& resultTake);

	iBaseOverrideGroup*		(iBaseTake::*AddOverrideGroup)							();
	iBaseOverrideGroup*		(iBaseTake::*GetFirstOverrideGroup)					();
	void									(iBaseTake::*DeleteOverrideGroup)						(iTakeData* takeData, iBaseOverrideGroup* og);

	BaseObject*						(iBaseTake::*GetCamera)											(iTakeData* takeData);
	BaseObject*						(iBaseTake::*GetEffectiveCamera)						(iTakeData* takeData, iBaseTake*& resultTake);
	void									(iBaseTake::*SetCamera)											(iTakeData* takeData, BaseObject* camera);

	RenderData*						(iBaseTake::*GetRenderData)									(iTakeData* takeData);
	RenderData*						(iBaseTake::*GetEffectiveRenderData)				(iTakeData* takeData, iBaseTake*& resultTake);
	void									(iBaseTake::*SetRenderData)									(iTakeData* takeData, RenderData* rData);

	void									(iBaseTake::*Reset)													();

	Bool									(iBaseOverrideGroup::*GetObjectsInGroup)		(AtomArray& selection);

	void									(iBaseOverrideGroup::*AddToGroup)						(iTakeData* takeData, BaseList2D* node);
	void									(iBaseOverrideGroup::*RemoveFromGroup)			(iTakeData* takeData, BaseList2D* node);

	BaseTag*							(iBaseOverrideGroup::*AddTag)								(iTakeData* takeData, Int32 type, BaseMaterial* mat);
	void									(iBaseOverrideGroup::*RemoveTag)						(iTakeData* takeData, Int32 type);

	Int32									(iBaseOverrideGroup::*GetEditorMode)				();
	Int32									(iBaseOverrideGroup::*GetRenderMode)				();
	void									(iBaseOverrideGroup::*SetEditorMode)				(Int32 mode);
	void									(iBaseOverrideGroup::*SetRenderMode)				(Int32 mode);

	BaseTag*							(iBaseOverrideGroup::*GetTag)								(Int32 type);
	iBaseTake*						(iBaseOverrideGroup::*GetTake)							();
	Bool									(iBaseOverrideGroup::*Find)									(iTakeData* takeData, BaseObject* op);

	Bool									(iBaseOverride::*IsOverriddenParam)					(const DescID& descID);
	BaseList2D*						(iBaseOverride::*GetSceneNode)							();
	iBaseTake*						(iBaseOverride::*GetOwnerTake)							(iTakeData* takeData);
	Bool									(iBaseOverride::*IsInGroup)									(iTakeData* takeData, iBaseOverrideGroup*& resGroup);
	Bool									(iBaseOverride::*GetAllOverrideDescID)			(maxon::BaseArray<DescID>& result);
	void									(iBaseOverride::*UpdateSceneNode)						(iTakeData* takeData, const DescID& descID);


	Bool									(iTakeData::*Set)														(BaseDocument* doc);
	BaseDocument*					(iTakeData::*GetDocument)										();
	iBaseTake*						(iTakeData::*GetMainTake)										();
	TAKE_MODE							(iTakeData::*GetTakeMode)										();
	OVERRIDEENABLING			(iTakeData::*GetOverrideEnabling)						();
	Bool									(iTakeData::*CheckOverrideEnabling)					(OVERRIDEENABLING mask);

	void									(iTakeData::*GetTakeSelection)							(AtomArray& selection, Bool children);

	iBaseTake*						(iTakeData::*GetCurrentTake)								();
	Bool									(iTakeData::*SetCurrentTake)								(iBaseTake* take);

	BaseDocument*					(iTakeData::*TakeToDocument)								(iBaseTake* take);
	Bool									(iTakeData::*SaveTakesWithAssets)						(Bool selected);

	iBaseTake*						(iTakeData::*AddTake)												(const String& name, iBaseTake* parent, iBaseTake* cloneFrom);
	void									(iTakeData::*DeleteTake)										(iBaseTake* take);
	void									(iTakeData::*InsertTake)										(iBaseTake* takeToMove, iBaseTake* destTake, Int32 insertMode);

	iBaseOverride*				(iTakeData::*FindOverrideCounterPart)				(iBaseOverride* overrideNode, const DescID& descID, iBaseTake*& resultTake);

	void									(iTakeData::*SendNodeToRepository)					(BaseList2D* parent, BaseList2D* node);
	BaseList2D*						(iTakeData::*GetNodeFromRepository)					(BaseList2D* parent, BaseList2D* node);

	void									(iTakeData::*ResetSystem)										();

	Bool									(*IsTakeRenderRunning)											();

	Bool									(iTakeData::*GetUndoState)									();
	void									(iTakeData::*SetUndoState)									(Bool state);

	Bool									(iBaseTake::*IsChecked)											();
	void 									(iBaseTake::*SetChecked)										(Bool status);

	void 									(*StopTakeRender)													();
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_TAKESYSTEM_H__
