/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_TAGDATA_H__
#define C4D_TAGDATA_H__

#include "c4d_nodedata.h"
#include "operatingsystem.h"

class BaseTag;
class BaseObject;
class BaseDraw;
class BaseDrawHelp;
class BaseDocument;
class BaseBitmap;
class String;
class BaseThread;
class PriorityList;
class GeClipMap;

//----------------------------------------------------------------------------------------
/// A data class for creating tag plugins.\n
/// Tag plugins appear in the Tag menu of the Object Manager and can be attached to objects.
///
/// Use RegisterTagPlugin() to register a tag plugin.
//----------------------------------------------------------------------------------------
class TagData : public NodeData
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

	//----------------------------------------------------------------------------------------
	/// Called when the display is updated to draw visual elements of the tag in the 3D view.
	/// @calledThreadContext
	/// @note To get the current drawpass call @formatParam{bd}->@link BaseDraw::GetDrawPass GetDrawPass()@endlink.
	/// @warning Only draw in @ref DRAWPASS::HIGHLIGHTS if you really know what you are doing. Otherwise always check the drawpass and then do not draw if it is @ref DRAWPASS::HIGHLIGHTS.
	/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{shader}
	/// @param[in] op									The host object of the tag. @cinemaOwnsPointed{object}
	/// @param[in] bd									The editor's view. @callerOwnsPointed{view}
	/// @param[in] bh									The helper for the editor's view. @callerOwnsPointed{base draw helper}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool Draw(BaseTag* tag, BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh);

	//----------------------------------------------------------------------------------------
	/// Called at the point in the priority pipeline specified by @ref AddToExecution, or the lack thereof.
	/// @calledThreadContext
	/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{shader}
	/// @param[in] doc								The host document of the tag. @cinemaOwnsPointed{document}
	/// @param[in] op									The host object of the tag. @cinemaOwnsPointed{object}
	/// @param[in] bt									The calling thread. Can be @formatConstant{nullptr}. @cinemaOwnsPointed{thread}
	/// @param[in] priority						The priority of the call to Execute() in the pipeline: @enumerateEnum{EXECUTIONPRIORITY}
	/// @param[in] flags							The execution flags: @enumerateEnum{EXECUTIONFLAGS}
	/// @return												The execution result: @enumerateEnum{EXECUTIONRESULT}
	//----------------------------------------------------------------------------------------
	virtual EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);

	//----------------------------------------------------------------------------------------
	/// Called to add execution priorities.\n
	/// By default returns @formatConstant{false}. In that case @C4D will call Execute() at the priority specified by the user in the @ref EXPRESSION_PRIORITY parameter of the container.\n
	/// If overridden then insert points of execution in the list and return @formatConstant{true}. Heres is an example:
	/// @code
	/// list->Add(op, EXECUTIONPRIORITY_ANIMATION, EXECUTIONFLAGS::NONE);
	/// list->Add(op, EXECUTIONPRIORITY_GENERATOR, EXECUTIONFLAGS::NONE);
	/// @endcode
	/// @C4D will then call Execute() 2 times.
	/// @param[in] tag								The BaseTag connected with the TagData instance. Equal to <tt>static_cast</tt><@ref TagData*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{shader}
	/// @param[in] list								The priority list to add execution points to. @cinemaOwnsPointed{priority list}
	/// @return												@trueIfOtherwiseFalse{priority was added to the execution list}
	//----------------------------------------------------------------------------------------
	virtual Bool AddToExecution(BaseTag* tag, PriorityList* list);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	virtual Bool GetModifiedObjects(BaseTag* tag, BaseDocument* doc, BaseObject*& op, Bool& pluginownedop, const Matrix& op_mg, Float lod, Int32 flags, BaseThread* thread);
};

//----------------------------------------------------------------------------------------
/// Registers a tag plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
/// 															To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
/// 															Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The node plugin info flags: @enumerateEnum{TAG} @enumerateEnum{PLUGINFLAG}
/// @param[in] g									The allocator for the tag plugin. This is a pointer to a function that creates a new instance of TagData with NewObj().
/// @param[in] description				The name of the description resource file to use for the material plugin without @em .res extension, for example @em "Ttagname".\n
/// 															The name has to be unique, i.e. @em "Tdisplay" cannot be used for 2 different descriptions. See Description Resource for more information.
/// @param[in] icon								The icon for the tag. The bitmap is copied. \n
/// 															The icon should be of size @em 32x@em 32, but will be scaled if needed.\n
/// 															It must also be @em 24 bits and should if possible include an alpha to support pattern backgrounds.
/// @param[in] disklevel					The plugin level is similar to a version number. The default level is @em 0.\n
/// 															Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
/// 															As an example you may have updated a plugin. If you now need to write additional information for new settings or changed types for old settings increase the level.\n
/// 															During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
/// 															For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.\n\n
/// 															@formatParam{disklevel} is only useful if variables are written/read in @ref NodeData::Write/@ref NodeData::Read.
/// @return												@trueIfOtherwiseFalse{the tag plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterTagPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* g, const maxon::String& description, BaseBitmap* icon, Int32 disklevel);

#endif // C4D_TAGDATA_H__
