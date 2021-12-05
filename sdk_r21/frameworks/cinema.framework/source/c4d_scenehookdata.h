/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_SCENEHOOKDATA_H__
#define C4D_SCENEHOOKDATA_H__

#include "c4d_nodedata.h"
#include "operatingsystem.h"

class String;
class BaseContainer;
class BaseBitmap;
class BaseDocument;
class BaseObject;
class BaseDraw;
class BaseDrawHelp;
class BaseThread;
class CDialog;
class PriorityList;
class EditorWindow;
class BaseSceneHook;
struct ControlDisplayStruct;

/// @addtogroup PLUGINFLAG_SCENEHOOK
/// @ingroup group_enumeration
/// @{
/// Scene hook plugin flags.
#define PLUGINFLAG_SCENEHOOK_NOTDRAGGABLE									(1 << 0)			///< Do not call during scrubbing (e.g. dynamics).
#define PLUGINFLAG_SCENEHOOK_SUPPORT_DOCUMENT_DESCRIPTION	(1 << 1)			///< Show in the document's description.
#define PLUGINFLAG_SCENEHOOK_SUPPORT_ANIMATION						(1 << 2)			///< Show in the timeline.
/// @}

//----------------------------------------------------------------------------------------
/// A data class for creating scene hook plugins.\n
/// A scene hook is called on every scene prepare, for example before redraw and before rendering.
///
/// Use RegisterSceneHookPlugin() to register a scene hook plugin.
///
/// @warning Make sure that a scene hook plugin is @em 100% stable and not too slow before releasing it. A crashing scene hook is a potential disaster!
//----------------------------------------------------------------------------------------
class SceneHookData : public NodeData
{
public:
	// Inherited from NodeData
	// virtual Bool Init(GeListNode *node);
	// virtual void Free(GeListNode *node);
	// virtual Bool Read(GeListNode *node, HyperFile *hf, Int32 level);
	// virtual Bool Write(GeListNode *node, HyperFile *hf);
	// virtual Bool Message(GeListNode *node, Int32 type, void *data);
	// virtual Bool CopyTo(NodeData *dest, GeListNode *snode, GeListNode *dnode, COPYFLAGS flags, AliasTrans *trn);
	// virtual void GetBubbleHelp(GeListNode *node, maxon::String &str);
	// virtual BaseDocument* GetDocument(GeListNode *node);
	// virtual Int32 GetBranchInfo(GeListNode *node, BranchInfo *info, Int32 max, GETBRANCHINFO flags);
	// virtual Bool GetDDescription(GeListNode *node, Description *description, DESCFLAGS_DESC &flags);
	// virtual Bool GetDParameter(GeListNode *node, const DescID &id,GeData &t_data,DESCFLAGS_GET &flags);
	// virtual Bool GetDEnabling(GeListNode *node, const DescID &id,const GeData &t_data,DESCFLAGS_ENABLE flags,const BaseContainer *itemdesc);
	// virtual Bool SetDParameter(GeListNode *node, const DescID &id,const GeData &t_data,DESCFLAGS_SET &flags);
	// static NodeData *Alloc(void) { return NewObjClear(MyNodeData); }
	// Inherited from NodeData

	/// @name Init/Free SceneHook
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to initialize the scene hook, before all scene hooks and expressions in a scene are calculated.\n
	/// Allocate here temporary data in the node.
	/// @param[in] node								The BaseSceneHook connected with the SceneHookData instance. Equal to <tt>static_cast</tt><@ref BaseSceneHook*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{scene hook}
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] bt									The calling thread. Can be @formatConstant{nullptr}. @cinemaOwnsPointed{thread}
	/// @return												The execution result: @enumerateEnum{EXECUTIONRESULT}
	//----------------------------------------------------------------------------------------
	virtual EXECUTIONRESULT InitSceneHook(BaseSceneHook* node, BaseDocument* doc, BaseThread* bt);

	//----------------------------------------------------------------------------------------
	/// Called to free the scene hook, after all scene hooks and expressions in a scene are calculated, before the drawing starts.\n
	/// Free here temporary data allocated in @ref InitSceneHook.
	/// @param[in] node								The BaseSceneHook connected with the SceneHookData instance. Equal to <tt>static_cast</tt><@ref BaseSceneHook*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{scene hook}
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	//----------------------------------------------------------------------------------------
	virtual void FreeSceneHook(BaseSceneHook* node, BaseDocument* doc);

	/// @}

	/// @name Execute
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called at the point in the priority pipeline specified by @ref AddToExecution, or by @ref RegisterSceneHookPlugin.
	/// @calledThreadContext
	/// @param[in] node								The BaseSceneHook connected with the SceneHookData instance. Equal to <tt>static_cast</tt><@ref BaseSceneHook*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{scene hook}
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] bt									The calling thread. Can be @formatConstant{nullptr}. @cinemaOwnsPointed{thread}
	/// @param[in] priority						The priority of the call to Execute() in the pipeline: @enumerateEnum{EXECUTIONPRIORITY}
	/// @param[in] flags							The execution flags: @enumerateEnum{EXECUTIONFLAGS}
	/// @return												The execution result: @enumerateEnum{EXECUTIONRESULT}
	//----------------------------------------------------------------------------------------
	virtual EXECUTIONRESULT Execute(BaseSceneHook* node, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Called to add execution priorities.\n
	/// By default returns @formatConstant{false}. In that case @C4D will call Execute() at the priority specified by the RegisterSceneHookPlugin() call for the scene hook.\n
	/// If overridden then insert points of execution in the list and return @formatConstant{true}. Heres is an example:
	/// @code
	/// list->Add(node, EXECUTIONPRIORITY_ANIMATION, EXECUTIONFLAGS::NONE);
	/// list->Add(node, EXECUTIONPRIORITY_GENERATOR, EXECUTIONFLAGS::NONE);
	/// @endcode
	/// @C4D will then call Execute() 2 times.
	/// @param[in] node								The BaseSceneHook connected with the SceneHookData instance. Equal to <tt>static_cast</tt><@ref BaseSceneHook*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{scene hook}
	/// @param[in] list								The priority list to add execution points to. @cinemaOwnsPointed{priority list}
	/// @return												@trueIfOtherwiseFalse{priority was added to the execution @formatParam{list}}
	//----------------------------------------------------------------------------------------
	virtual Bool AddToExecution(BaseSceneHook* node, PriorityList* list);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Called when the user clicks with the mouse in any of the editors views.
	/// @note Make sure this function is used only when the user is somehow working with the scene hook plugin, so that other plugins can also use this hook when it is their turn.
	/// @warning	At least call @c SceneHookData::MouseInput(node, doc, bd, win, msg) as last return, so that other plugins can also use this hook when it is their turn.\n
	///						If @formatConstant{true} is returned the right-click will not be evaluated anymore in the editor views.
	/// @param[in] node								The BaseSceneHook connected with the SceneHookData instance. Equal to <tt>static_cast</tt><@ref BaseSceneHook*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{scene hook}
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
	/// @param[in] win								The window for the active editor view. @cinemaOwnsPointed{editor window}
	/// @param[in] msg								The mouse message container. See @link page_input_events Input Events@endlink.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool MouseInput(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Called when the user types something in any of the editors views.
	/// @note Make sure this function is used only when the user is somehow working with the scene hook plugin, so that other plugins can also use this hook when it is their turn.
	/// @warning	At least call @c SceneHookData::KeyboardInput(node, doc, bd, win, msg) as last return, so that other plugins can also use this hook when it is their turn.\n
	///						If @formatConstant{true} is returned the keyboard will be blocked in the editor views.
	/// @param[in] node								The BaseSceneHook connected with the SceneHookData instance. Equal to <tt>static_cast</tt><@ref BaseSceneHook*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{scene hook}
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
	/// @param[in] win								The window for the active editor view. @cinemaOwnsPointed{editor window}
	/// @param[in] msg								The keyboard message container. See @link page_input_events Input Events@endlink.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool KeyboardInput(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd, EditorWindow* win, const BaseContainer& msg);

	//----------------------------------------------------------------------------------------
	/// Called when the cursor is over the editor views to get the state of the mouse pointer.\n
	/// Set the bubble help and cursor, for example:
	/// @code
	/// bc.SetString(RESULT_BUBBLEHELP, "My Tools Help");
	/// bc.SetInt32(RESULT_CURSOR, MOUSE_POINT_HAND);
	/// @endcode
	/// @note Make sure this function is used only when the user is somehow working with the scene hook plugin, so that other plugins can also use this hook when it is their turn.
	/// @param[in] node								The BaseSceneHook connected with the SceneHookData instance. Equal to <tt>static_cast</tt><@ref BaseSceneHook*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{scene hook}
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
	/// @param[in] x									The X coordinate of the mouse cursor relative to the top-left of the active editor view.
	/// @param[in] y									The Y coordinate of the mouse cursor relative to the top-left of the active editor view.
	/// @param[in] bc									The container to store the cursor information in: @link RESULT_CURSOR BFM_GETCURSORINFO_RESULT@endlink
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool GetCursorInfo(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd, Float x, Float y, BaseContainer& bc);

	//----------------------------------------------------------------------------------------
	/// Called when the display is updated to display arbitrary visual elements in the editor views.
	/// @calledThreadContext
	/// @note Make sure this function is used only when the user is somehow working with the scene hook plugin, so that other plugins can also use this hook when it is their turn.
	/// @param[in] node								The BaseSceneHook connected with the SceneHookData instance. Equal to <tt>static_cast</tt><@ref BaseSceneHook*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{scene hook}
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
	/// @param[in] bh									The helper for active the editor view. @callerOwnsPointed{view helper}
	/// @param[in] bt									The calling thread. Can be @formatConstant{nullptr}. @cinemaOwnsPointed{thread}
	/// @param[in] flags							The draw flags: @enumerateEnum{ SCENEHOOKDRAW}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool Draw(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd, BaseDrawHelp* bh, BaseThread* bt, SCENEHOOKDRAW flags);

	/// @name DisplayControl
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to set information about how the active object should be displayed.
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] op									The active object. @cinemaOwnsPointed{object}
	/// @param[in] chainstart					The start of the object chain. @cinemaOwnsPointed{object}
	/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
	/// @param[in] bh									The helper for active the editor view. @callerOwnsPointed{view helper}
	/// @param[in] cds								The display control settings.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool DisplayControl(BaseDocument* doc, BaseObject* op, BaseObject* chainstart, BaseDraw* bd, BaseDrawHelp* bh, ControlDisplayStruct& cds);

	//----------------------------------------------------------------------------------------
	/// Initialize resources for the display control used in @ref DisplayControl.
	/// @param[in] node								The BaseSceneHook connected with the SceneHookData instance. Equal to <tt>static_cast</tt><@ref BaseSceneHook*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{scene hook}
	/// @param[in] doc								The active document. @cinemaOwnsPointed{document}
	/// @param[in] bd									The active editor view. @cinemaOwnsPointed{base draw}
	/// @param[in] active							The active objects array. @cinemaOwnsPointed{array}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool InitDisplayControl(BaseSceneHook* node, BaseDocument* doc, BaseDraw* bd, const AtomArray* active);

	//----------------------------------------------------------------------------------------
	/// Free resources allocated in @ref InitDisplayControl.
	//----------------------------------------------------------------------------------------
	virtual void FreeDisplayControl(void);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Registers a scene hook plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
/// 															To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
/// 															Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The scene hook plugin info flags: @enumerateEnum{PLUGINFLAG_SCENEHOOK} @enumerateEnum{PLUGINFLAG}
/// @param[in] g									The allocator for the scene hook plugin. This is a pointer to a function that creates a new instance of SceneHookData with NewObj().
/// @param[in] priority						The default priority to call SceneHookData::Execute in the pipeline. Override SceneHookData::AddToExecution to change this or add more priorities. @enumerateEnum{EXECUTIONPRIORITY}
/// @param[in] disklevel					The plugin level is similar to a version number. The default level is @em 0.\n
/// 															Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
/// 															As an example you may have updated a plugin. If you now need to write additional information for new settings or changed types for old settings increase the level.\n
/// 															During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
/// 															For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.\n\n
/// 															@formatParam{disklevel} is only useful if variables are written/read in @ref NodeData::Write/@ref NodeData::Read.
/// @return												@trueIfOtherwiseFalse{the scene hook plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterSceneHookPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* g, Int32 priority, Int32 disklevel);

#endif // C4D_SCENEHOOKDATA_H__
