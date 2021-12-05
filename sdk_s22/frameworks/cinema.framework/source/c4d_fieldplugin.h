/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_FIELDPLUGIN_H__
#define C4D_FIELDPLUGIN_H__

#include "ge_math.h"
#include "c4d_fielddata.h"
#include "c4d_objectplugin.h"
#include "c4d_tagdata.h"
#include "c4d_tagplugin.h"

class FieldData : public ObjectData
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(FieldData);
public:
	// // inherited from NodeData ////
	// virtual Bool Init(GeListNode *node);
	// virtual void Free(GeListNode *node);
	// virtual Bool Read(GeListNode *node, HyperFile *hf, Int32 level);
	// virtual Bool Write(GeListNode *node, HyperFile *hf);
	// virtual Bool Message(GeListNode *node, Int32 type, void *data);
	// virtual Bool CopyTo(NodeData *dest, GeListNode *snode, GeListNode *dnode, COPYFLAGS flags, AliasTrans *trn);
	// virtual void GetBubbleHelp(GeListNode *node, String &str);
	// virtual BaseDocument* GetDocument(GeListNode *node);
	// virtual Int32 GetBranchInfo(GeListNode *node, BranchInfo *info, Int32 max, GETBRANCHINFO flags);
	// virtual Bool GetDDescription(GeListNode *node, Description *description, DESCFLAGS_DESC &flags);
	// virtual Bool GetDParameter(GeListNode *node, const DescID &id,GeData &t_data,DESCFLAGS_GET &flags);
	// virtual Bool GetDEnabling(GeListNode *node, const DescID &id,const GeData &t_data,DESCFLAGS_ENABLE flags,const BaseContainer *itemdesc);
	// virtual Bool SetDParameter(GeListNode *node, const DescID &id,const GeData &t_data,DESCFLAGS_SET &flags);
	// static NodeData *Alloc(void) { return NewObjClear(MyNodeData); }
	// // inherited from NodeData ////

	// // inherited from ObjectData ////
	// virtual void GetDimension(BaseObject* op, Vector* mp, Vector* rad);
	// virtual DRAWRESULT Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh);
	// virtual DRAWRESULT DrawShadow(BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh);
	// virtual Int32 DetectHandle(BaseObject* op, BaseDraw* bd, Int32 x, Int32 y, QUALIFIER qualifier);
	// virtual Bool MoveHandle(BaseObject* op, BaseObject* undo, const Vector& mouse_pos, Int32 hit_id, QUALIFIER qualifier, BaseDraw* bd);
	// virtual Bool AddToExecution(BaseObject* op, PriorityList* list);
	// virtual EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
	// virtual void GetModelingAxis(BaseObject* op, BaseDocument* doc, Matrix& axis);
	// virtual BaseObject* GetVirtualObjects(BaseObject* op, HierarchyHelp* hh);
	// virtual Bool ModifyObject(BaseObject* mod, BaseDocument* doc, BaseObject* op, const Matrix& op_mg, const Matrix& mod_mg, Float lod, Int32 flags, BaseThread* thread);
	// virtual void CheckDirty(BaseObject* op, BaseDocument* doc);
	// virtual SplineObject* GetContour(BaseObject* op, BaseDocument* doc, Float lod, BaseThread* bt);
	// virtual void ModifyParticles(BaseObject* op, Particle* pp, BaseParticle* ss, Int32 pcnt, Float diff);
	// virtual Int32 GetHandleCount(BaseObject* op);
	// virtual void GetHandle(BaseObject* op, Int32 i, HandleInfo& info);
	// virtual void SetHandle(BaseObject* op, Int32 i, Vector p, const HandleInfo& info);
	// // inherited from ObjectData ////

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	FieldData() : ObjectData() { }

	//----------------------------------------------------------------------------------------
	/// @markprivate - Initialization block, invoked prior to any sampling.
	/// @param[in] op									The object, convenience function equivalent to Get().
	/// @param[in] info								The information detailing thread count, points information etc.  Caller is
	/// 															responsible for validity of content.
	/// @param[in,out] shared					Shared data between layers/fields.
	/// @return												OK on success, error will cancel sampling.
	//----------------------------------------------------------------------------------------
	virtual maxon::Result<void> InitSampling(FieldObject& op, const FieldInfo& info, FieldShared& shared) { return maxon::OK; }

	//----------------------------------------------------------------------------------------
	/// @markprivate - Free any temporarily stored data after sampling has finished.
	/// @param[in] op									The object, convenience function equivalent to Get().
	/// @param[in] info								The information.
	/// @param[in,out] shared					Shared data between layers/fields.
	//----------------------------------------------------------------------------------------
	virtual void FreeSampling(FieldObject& op, const FieldInfo& info, FieldShared& shared) { }

	//----------------------------------------------------------------------------------------
	/// @markprivate - Sampling invocation.  The points are no longer just vectors, but also contain other
	/// information that may be relevant such as normal direction, the points must be iterated over and the
	/// result filled with the output values.  The flags determine which values are being requested by the
	/// caller.  InitializeSampling must be called first and the points data must be valid. NOTE: Sample does not
	/// receive the SharedData. If a layer needs access to it, it can keep a reference on it or copy parts of it
	/// in InitSampling.
	/// @param[in] op									The object, convenience function equivalent to Get().
	/// @param[in] inputs							The points to sample at owned by the caller.
	/// @param[out] outputs						The result array, owned by the caller.
	/// @param[in] info								The information.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	virtual maxon::Result<void> Sample(const FieldObject& op, const FieldInput& inputs, FieldOutputBlock& outputs, const FieldInfo& info) const = 0;

	//----------------------------------------------------------------------------------------
	/// Gets Field objects flags.
	/// @param[in] op									The field object, convenience function equivalent to Get().
	/// @param[in] doc								The current document.
	/// @return												The field flags see @FIELDOBJECT_FLAG.
	//----------------------------------------------------------------------------------------
	virtual FIELDOBJECT_FLAG GetFieldFlags(const FieldObject& op, BaseDocument* doc) const { return FIELDOBJECT_FLAG::NONE; }
};

class FieldLayerData : public NodeData
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(FieldLayerData);
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	FieldLayerData() : NodeData() { }

	//----------------------------------------------------------------------------------------
	/// Called to allow you to initialize any memory or values prior to sampling for the sake of speed. This
	/// function is single threaded.
	/// @param[in] layer							The layer a convenience value, equivalent to Get().
	/// @param[in] info								The information used for sampling within this core.
	/// @param[in,out] shared					Shared data between layers/fields.
	/// @return												OK on success, error will cancel sampling.
	//----------------------------------------------------------------------------------------
	virtual maxon::Result<void> InitSampling(FieldLayer& layer, const FieldInfo& info, FieldShared& shared) { return maxon::OK; }

	//----------------------------------------------------------------------------------------
	/// Called to modify the passed output values.  This is the central purpose of the layer and as a
	/// requirement for the layer to function.  It is critical that this function is as fast as possible and
	/// avoids too many memory operations.  This function operates within a multithreaded environment and as such
	/// it is important to pay attention to the thread information passed within the supplied 'info' FieldInfo
	/// structure in order to avoid garbled output. NOTE: Sample does not receive the SharedData. If a layer
	/// needs access to it, it can keep a reference on it or copy parts of it in InitSampling.
	/// @param[in] layer							The layer a convenience value, equivalent to Get().
	/// @param[in] inputs							The spacial points being sampled.
	/// @param[in,out] outputs				The output arrays to modify, this will have content already from prior layers.
	/// @param[in] info								The information used for sampling within this core.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	virtual maxon::Result<void> Sample(const FieldLayer& layer, const FieldInput& inputs, FieldOutputBlock& outputs, const FieldInfo& info) const = 0;

	//----------------------------------------------------------------------------------------
	/// This function requires the FIELDLAYER_AGGREGATE registration flag to be set.  This function receives
	/// the final output of the FieldLayers and is called at the end of each thread/block to allow the layer to
	/// Aggregate this output for it's own storage purposes or do per block cleanup as required.
	/// @param[in] layer							The layer a convenience value, equivalent to Get().
	/// @param[in] inputs							The spacial points being sampled.
	/// @param[in] outputs						The output arrays to modify, this will have content already from prior layers.
	/// @param[in] info								The information used for sampling within this core.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	virtual maxon::Result<void> Aggregate(const FieldLayer& layer, const FieldInput& inputs, const FieldOutputBlock& outputs, const FieldInfo& info) { return maxon::OK; }

	//----------------------------------------------------------------------------------------
	/// Called after sampling in order to allow you to clean up any memory utilized by your sampling algorithm.
	/// This function is single threaded.
	/// @param[in] layer							The layer a convenience value, equivalent to Get().
	/// @param[in] info								The information used for sampling within this core.
	/// @param[in,out] shared					Shared data between layers/fields.
	//----------------------------------------------------------------------------------------
	virtual void FreeSampling(FieldLayer& layer, const FieldInfo& info, FieldShared& shared) { }

	//----------------------------------------------------------------------------------------
	/// Query if 'layer' is equal to the passed 'comp' layer.  This is mandatory to fill in, if a comparison is
	/// not correctly done then any changes made by the developer or user will not be stored within the GUI.
	/// @param[in] layer							The layer a convenience value, equivalent to Get().
	/// @param[in] comp								The layer data to compare with.
	/// @return												true if equal, false if not.
	//----------------------------------------------------------------------------------------
	virtual Bool IsEqual(const FieldLayer& layer, const FieldLayerData& comp) const { return true; }

	//----------------------------------------------------------------------------------------
	/// In a situation where the layer is a wrapper around another object, for example the built in FieldObject
	/// layers, this allows the layer to return it's linked object to the Layer GUI for dirty checks so that the
	/// owner of the GUI can update when for example an object that's linked moves.
	/// @param[in] layer							The layer, a convenience function the same as Get().
	/// @param[in] doc								The document.
	/// @return												A filled in FiledLayerLink structure containing passed BaseList and secondary data.
	//----------------------------------------------------------------------------------------
	virtual FieldLayerLink GetLinkedObject(const FieldLayer& layer, BaseDocument* doc) const { return FieldLayerLink(); }

	//----------------------------------------------------------------------------------------
	/// This function is invoked to set the linked object.  The passed structure corresponds to the data that
	/// might be found in a Drag &amp; Drop invocation.
	/// @param[in] layer							The layer.
	/// @param[in] link								The link data containing the object and/or any secondary information that may be
	/// 															required, e.g. DescID from a DescID drag&amp;drop into the Fields GUI.
	/// @return												True if it succeeds, false if it fails and the object cannot receive the passed information (or
	/// 				it is incorrect).
	//----------------------------------------------------------------------------------------
	virtual Bool SetLinkedObject(FieldLayer& layer, const FieldLayerLink& link) { return false; }

	//----------------------------------------------------------------------------------------
	/// Called to update the dirtiness of the Fieldlayer.  Use layer->SetDirty(FLAGS) to set the dirtiness as
	/// required
	/// @param[in] layer							The layer.
	/// @param[in] doc								The document.
	//----------------------------------------------------------------------------------------
	virtual void CheckDirty(FieldLayer& layer, BaseDocument* doc) { }
};

//----------------------------------------------------------------------------------------
/// @cond INTERNAL

struct FIELDPLUGIN : public OBJECTPLUGIN
{
	const String*				_help;

	maxon::Result<void>	(FieldData::*InitSampling				 )(FieldObject& op, const FieldInfo& info, FieldShared& shared);
	void								(FieldData::*FreeSampling				 )(FieldObject& op, const FieldInfo& info, FieldShared& shared);
	maxon::Result<void>	(FieldData::*Sample							 )(const FieldObject& op, const FieldInput& inputs, FieldOutputBlock& outputs, const FieldInfo& info) const;
	FIELDOBJECT_FLAG		(FieldData::*GetFieldFlags			 )(const FieldObject& op, BaseDocument* doc) const;

	void*								reserved[(32 - 4) * C4DPL_MEMBERMULTIPLIER - 1];
};

struct FIELDLAYERPLUGIN : public NODEPLUGIN
{
	const String*				_help;
	const String*				_pickInstruction;

	Bool								(*AcceptDrag												)(const FieldLayerLink& link);

	maxon::Result<void>	(FieldLayerData::*InitSampling			)(FieldLayer& layer, const FieldInfo& info, FieldShared& shared);
	maxon::Result<void>	(FieldLayerData::*Sample						)(const FieldLayer& layer, const FieldInput& inputs, FieldOutputBlock& outputs, const FieldInfo& info) const;
	maxon::Result<void>	(FieldLayerData::*Aggregate					)(const FieldLayer& layer, const FieldInput& inputs, const FieldOutputBlock& outputs, const FieldInfo& info);
	void								(FieldLayerData::*FreeSampling			)(FieldLayer& layer, const FieldInfo& info, FieldShared& shared);
	Bool								(FieldLayerData::*IsEqual						)(const FieldLayer& layer, const FieldLayerData& comp) const;
	FieldLayerLink			(FieldLayerData::*GetLinkedObject		)(const FieldLayer& layer, BaseDocument* doc) const;
	Bool								(FieldLayerData::*SetLinkedObject		)(FieldLayer& layer, const FieldLayerLink& link);
	void								(FieldLayerData::*CheckDirty				)(FieldLayer& layer, BaseDocument* doc);

	void*								reserved[(32 - 9) * C4DPL_MEMBERMULTIPLIER - 3];
};

typedef Bool FieldLayerAcceptDragFunction (const FieldLayerLink& link);

void FillFieldPlugin(FIELDPLUGIN& np, DataAllocator* npalloc, Int32 info, Int32 disklevel, BaseBitmap* icon);
void FillFieldLayerPlugin(FIELDLAYERPLUGIN& np, DataAllocator* npalloc, Int32 info, BaseBitmap* icon, Int32 disklevel, FieldLayerAcceptDragFunction* dragFunc);

/// @endcond
//----------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------
/// Registers a FieldObject plugin
/// @param[in] id									@uniquePluginID.
/// @param[in] name								The name of the plugin.\n To affect the order that plugins are displayed in menus
/// 															add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n Lower numbers
/// 															are displayed before higher numbers. If name is <i>"--"</i> it will show up as a
/// 															menu separator.
/// @param[in] help								The help displayed on mouse hover over this FieldLayers icon.
/// @param[in] info								The field plugin info flags: @enumerateEnum{PLUGINFLAG}
/// 															@enumerateEnum{OBJECT} @enumerateEnum{PLUGINFLAG}
/// @param[in] g									The allocator for the object plugin. This is a pointer to a function that creates
/// 															a new instance of FieldData with NewObj().
/// @param[in] description				The name of the description resource file to use for the object plugin without
/// 															@em .res extension, for example @em "Fobjectname".\n The name has to be unique,
/// 															i.e. @em "Tdisplay" cannot be used for 2 different descriptions. See Description
/// 															Resource for more information.
/// @param[in] icon								The icon for the object. The bitmap is copied. \n The icon should be of size @em
/// 															32x@em 32, but will be scaled if needed.\n It must also be @em 24 bits and should
/// 															if possible include an alpha to support pattern backgrounds.
/// @param[in] disklevel					The plugin level is similar to a version number. The default level is
/// 															@em 0.\n Increase this for new revisions of a plugin to allow for
/// 															forward and backward compatibility.\n\n As an example you may have updated a
/// 															plugin. If you now need to write additional information for new settings or changed
/// 															types for old settings increase the level.\n During loading either a @em 0 is
/// 															passed (if the file was written by the old plugin) or @em 1 (if the file was
/// 															written by the new plugin). This allows to easily write/read new values.\n For
/// 															forward and backward compatibility to work any existing read order from a given
/// 															level must not be changed. @C4D skips any new settings automatically if they have
/// 															not been read.\n\n
/// 															@formatParam{disklevel} is only useful if variables are written/read in
/// 															@ref NodeData::Write/@ref NodeData::Read.
/// @return												@trueIfOtherwiseFalse{the object plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterFieldPlugin(Int32 id, const maxon::String& name, const maxon::String& help, Int32 info, DataAllocator* g, const maxon::String& description, BaseBitmap* icon, Int32 disklevel);

//----------------------------------------------------------------------------------------
/// Registers a FieldLayer plugin
/// @param[in] id									@uniquePluginID.
/// @param[in] name								The name of the plugin.\n To affect the order that plugins are displayed in
/// 															menus add <i>"#$n"</i> as a prefix to this name, where
/// 															@em n is a number.\n Lower numbers are displayed before higher
/// 															numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] help								The help displayed on mouse hover over this FieldLayers icon.
/// @param[in] pickInstruction		The pick instruction.
/// @param[in] info								The FieldLayer plugin info flags: @enumerateEnum{FIELDLAYER}
/// 															@enumerateEnum{PLUGINFLAG}
/// @param[in] g									The allocator for the FieldLayer plugin. This is a pointer to a function that
/// 															creates a new instance of FieldLayerData with NewObj().
/// @param[in] description				The name of the description resource file to use for the FieldLayer plugin
/// 															without @em .res extension, for example
/// 															@em "FLlayername".\n The name has to be unique, i.e. @em "Tdisplay" cannot be
/// 															used for 2 different descriptions. See
/// 															Description Resource for more information.
/// @param[in] icon								The icon for the FieldLayer. The bitmap is copied. \n The icon should be of
/// 															size @em 32x@em 32, but will be scaled if needed.\n It must also be @em 24 bits
/// 															and should if possible include an alpha to support pattern backgrounds.
/// @param[in] disklevel					The plugin level is similar to a version number. The default level is @em
/// 															0.\n Increase this for new revisions of a plugin to allow for forward and
/// 															backward compatibility.\n\n As an example you may have updated a plugin. If you
/// 															now need to write additional information for new settings or changed types for
/// 															old settings increase the level.\n During loading either a @em 0 is passed (if
/// 															the file was written by the old plugin) or @em 1 (if the file was written by
/// 															the new plugin). This allows to easily write/read new values.\n For forward and
/// 															backward compatibility to work any existing read order from a given level must
/// 															not be changed. @C4D skips any new settings automatically if they have not been
/// 															read.\n\n
/// 															@formatParam{disklevel} is only useful if variables are
/// 															written/read in @ref NodeData::Write/@ref NodeData::Read.
/// @param[in] dragFunc						(Optional) If non-null, the drag function, this is used to determine whether
/// 															this layer can accept an object type (which will be passed via the
/// 															SetLinkedObject function)
/// 															within the FieldList.
/// @return												@trueIfOtherwiseFalse{the object plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterFieldLayerPlugin(Int32 id, const maxon::String& name, const maxon::String& help, const maxon::String& pickInstruction, Int32 info, DataAllocator* g, const maxon::String& description, BaseBitmap* icon, Int32 disklevel, FieldLayerAcceptDragFunction* dragFunc = nullptr);

#endif // C4D_FIELDPLUGIN_H__

