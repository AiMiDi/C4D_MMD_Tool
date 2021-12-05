/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_OBJECTDATA_H__
#define C4D_OBJECTDATA_H__

#include "c4d_nodedata.h"
#include "operatingsystem.h"

class SplineObject;
class BaseBitmap;
class BaseDraw;
class BaseDrawHelp;
class Particle;
class BaseThread;
class HierarchyHelp;
class BaseObject;
class PriorityList;
class BaseDraw;
struct BaseParticle;

/// @addtogroup HANDLECONSTRAINTTYPE
/// @ingroup group_enumeration
/// @{
/// Handle constraint type.
enum class HANDLECONSTRAINTTYPE
{
	INVALID		= -1,			///< Invalid handle constraint type, used to temporarily ignore handles (e.g. in the Camera Object with the Front/Back DOF handles).
	LINEAR		= 0,			///< Linear handle constraint.
	PLANAR		= 1,			///< Planar handle constraint.
	FREE			= 2,			///< No constraint.
	RADIAL		= 3,			///< Radial handle constraint.
	SPHERICAL	= 4				///< Spherical handle constraint.
} MAXON_ENUM_LIST(HANDLECONSTRAINTTYPE);
/// @}

//----------------------------------------------------------------------------------------
/// Class holding the information for object handles.
///
/// The handle system has been changed in such a way that handles must travel with the mouse.\n
/// The system tries to help automate the placement of the handles. It calculates the correct handle positions and constrains the handle.\n
/// The values of HandleInfo are typically set in ObjectData::GetHandle by the user.\n
/// Here is the internal code of the ObjectData::DetectHandle and ObjectData::MoveHandle methods:
/// @code
/// Int32 ObjectData::DetectHandle(BaseObject *op, BaseDraw *bd, Int32 x, Int32 y, QUALIFIER qualifier)
/// {
/// 	if (qualifier & QUALIFIER::CTRL)
/// 		return NOTOK;
///
/// 	Matrix mg = op->GetMg();
/// 	Int32 i, ret = NOTOK;
///
/// 	for (i=0; i<GetHandleCount(op); i++)
/// 	{
/// 		HandleInfo info;
/// 		GetHandle(op,i, info);
/// 		if (info.type == HANDLECONSTRAINTTYPE::INVALID)
/// 			continue;
///
/// 		if (bd->PointInRange(info.position*mg, x, y))
/// 		{
/// 			ret = i;
/// 			if (!(qualifier&QUALIFIER::SHIFT))
/// 				break;
/// 		}
/// 	}
/// 	return ret;
/// }
///
/// Bool ObjectData::MoveHandle( BaseObject *op, BaseObject *undo, const Vector &mouse_pos, Int32 hit_id, QUALIFIER qualifier, BaseDraw *bd )
/// {
/// 	Matrix mg = op->GetUpMg() * undo->GetMl();
/// 	HandleInfo info;
///
/// 	undo->GetNodeData<ObjectData>()->GetHandle(undo,hit_id,info);
/// 	SetHandle(op,hit_id,info.CalculateNewPosition(bd, mg, mouse_pos),info);
///
/// 	return true;
/// }
/// @endcode
/// Here is code from the @em DoubleCircle SDK example that shows the implementation of the automated handle interface functions:
/// @code
/// Int32 DoubleCircleData::GetHandleCount(BaseObject *op)
/// {
/// 	return 1;
/// }
///
/// void DoubleCircleData::GetHandle(BaseObject *op, Int32 i, HandleInfo &info)
/// {
/// 	BaseContainer *data = op->GetDataInstance();
/// 	if (!data)
/// 		return;
///
/// 	Float rad = data->GetFloat(CIRCLEOBJECT_RAD);
/// 	Int32 plane = data->GetInt32(PRIM_PLANE);
///
/// 	info.position = SwapPoint(Vector(rad, 0.0, 0.0),plane);
/// 	info.direction = !SwapPoint(Vector(1.0, 0.0, 0.0),plane);
/// 	info.type = HANDLECONSTRAINTTYPE::LINEAR;
/// }
///
/// void DoubleCircleData::SetHandle(BaseObject *op, Int32 i, Vector p, const HandleInfo &info)
/// {
/// 	BaseContainer *data = op->GetDataInstance();
/// 	if (!data)
/// 		return;
///
/// 	Float val = Dot(p, info.direction);
/// 	data->SetFloat(CIRCLEOBJECT_RAD, ClampValue(val, 0.0_f, (Float)MAXRANGE));
/// }
/// @endcode
//----------------------------------------------------------------------------------------
class HandleInfo
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	HandleInfo()
	{
		position = Vector(0.0);
		direction = Vector(0.0);
		center = Vector(0.0);
		radius = 100.0;
		type = HANDLECONSTRAINTTYPE::LINEAR;
	}

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~HandleInfo(void)
	{

	}

	Vector position;								///< The handle position.
	Vector direction;								///< The normal used for the handle travel. For linear handle constraints it is the line on which a handle can travel. For planar and radial constraints it is the normal of the plane/disc. Otherwise it is not needed.
	Vector center;									///< The handle constraint center, for radial and spherical handle constraints.
	Float radius;										///< The handle constraint radius, for radial and spherical handle constraints.
	HANDLECONSTRAINTTYPE type;			///< The handle constraint type: @enumerateEnum{HANDLECONSTRAINTTYPE}

	//----------------------------------------------------------------------------------------
	/// Calculates a handle position for the given mouse position.
	/// @param[in] bd									The editor's view. @callerOwnsPointed{view}
	/// @param[in] mg									The global matrix of the handle's parent object.
	/// @param[in] mouse_pos					The mouse coordinates for which to calculate the handle position.
	/// @return												The new handle position.
	//----------------------------------------------------------------------------------------
	Vector CalculateNewPosition(BaseDraw* bd, const Matrix& mg, const Vector& mouse_pos) const;
};

//----------------------------------------------------------------------------------------
/// A data class for creating object plugins.\n
/// An object plugin can either be a generator, a modifier, a spline generator or a particle modifier. This is set when the object is registered and affects which functions are called.
///
/// Use RegisterObjectPlugin() to register an object plugin.
///
/// @note Be sure to read the new information about BaseObject::GetUniqueIP if a generator is created.
//----------------------------------------------------------------------------------------
class ObjectData : public NodeData
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

	/// @name Dimension
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to get the boundaries of the object.
	/// @note GetDimension() should be implemented for objects of types @ref Opolygon, @ref Opoint, @ref Oline and @ref Ospline. Furthermore it may be implemented to override @C4D's default handling of bounding boxes.
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[out] mp								Assign the center point of the bounding box.
	/// @param[out] rad								Assign the XYZ bounding box radius.
	//----------------------------------------------------------------------------------------
	virtual void GetDimension(BaseObject* op, Vector* mp, Vector* rad);

	/// @}

	/// @name Draw
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to draw additional information for the object in the editor view.\n
	/// Be sure to call the parent version as last return:
	/// @code
	/// return SUPER::Draw(op, drawpass, bd, bh);
	/// @endcode
	/// @note Generator objects are automatically drawn as GetVirtualObjects() returns the polygonal data already.
	/// @warning Only draw in @ref DRAWPASS::HIGHLIGHTS if you really know what you are doing. Otherwise always check the @formatParam{drawpass} and then do not draw if it is @ref DRAWPASS::HIGHLIGHTS.\n
	///					 Only draw the object in @ref DRAWPASS::OBJECT. The object's appearance may change if the same object is drawn in multiple passes.
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[in] drawpass						The draw pass: @enumerateEnum{DRAWPASS}
	/// @param[in] bd									The editor's view. @callerOwnsPointed{view}
	/// @param[in] bh									The helper for the editor's view. @callerOwnsPointed{view helper}
	/// @return												The result of drawing into the editor view: @enumerateEnum{DRAWRESULT}
	//----------------------------------------------------------------------------------------
	virtual DRAWRESULT Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh);

	//----------------------------------------------------------------------------------------
	/// Called during the shadow pass instead of the Draw() method.
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[in] bd									The editor's view. @callerOwnsPointed{view}
	/// @param[in] bh									The helper for the editor's view. @callerOwnsPointed{view helper}
	/// @return												The result of drawing into the editor view: @enumerateEnum{DRAWRESULT}
	//----------------------------------------------------------------------------------------
	virtual DRAWRESULT DrawShadow(BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh);

	/// @}

	/// @name Handle
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to manually detect a click on a handle.
	/// @note It is only needed to override @ref DetectHandle if @ref GetHandleCount/@ref GetHandle/@ref SetHandle automated handle interface functions are not overridden.
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[in] bd									The editor's view. @callerOwnsPointed{view}
	/// @param[in] x									The mouse X coordinate.
	/// @param[in] y									The mouse Y coordinate.
	/// @param[in] qualifier					The qualifier keys that were pressed: @enumerateEnum{QUALIFIER}
	/// @return												The handle ID that is to be passed to @ref MoveHandle.
	//----------------------------------------------------------------------------------------
	virtual Int32 DetectHandle(BaseObject* op, BaseDraw* bd, Int32 x, Int32 y, QUALIFIER qualifier);

	//----------------------------------------------------------------------------------------
	/// Called to move a handle manually.
	/// @note It is only needed to override @ref MoveHandle if @ref GetHandleCount/@ref GetHandle/@ref SetHandle automated handle interface functions are not overridden.
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[in] undo								This is a copy of the object that should not be modified during the move handle. @cinemaOwnsPointed{object}
	/// @param[in] mouse_pos					The mouse position.
	/// @param[in] hit_id							The handle ID returned from DetectHandle().
	/// @param[in] qualifier					The qualifier keys that were pressed: @enumerateEnum{QUALIFIER}
	/// @param[in] bd									The editor's view. @callerOwnsPointed{view}
	/// @return												@trueIfOtherwiseFalse{the handle was moved}
	//----------------------------------------------------------------------------------------
	virtual Bool MoveHandle(BaseObject* op, BaseObject* undo, const Vector& mouse_pos, Int32 hit_id, QUALIFIER qualifier, BaseDraw* bd);

	/// @}

	/// @name Execution
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to add execution priorities.\n
	/// By default returns @formatConstant{false}. In that case @C4D will call Execute() at the priority specified by the user in the @ref EXPRESSION_PRIORITY parameter of the container.\n
	/// If overridden then insert points of execution in the list and return @formatConstant{true}. Heres is an example:
	/// @code
	/// list->Add(op, EXECUTIONPRIORITY_ANIMATION, EXECUTIONFLAGS::NONE);
	/// list->Add(op, EXECUTIONPRIORITY_GENERATOR, EXECUTIONFLAGS::NONE);
	/// @endcode
	/// @C4D will then call Execute() 2 times.
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[in] list								The priority list to add execution points to. @cinemaOwnsPointed{priority list}
	/// @return												@trueIfOtherwiseFalse{priority was added to the execution list}
	//----------------------------------------------------------------------------------------
	virtual Bool AddToExecution(BaseObject* op, PriorityList* list);

	//----------------------------------------------------------------------------------------
	/// Called at the point in the priority pipeline specified by @ref AddToExecution, or the lack thereof.
	/// @calledThreadContext
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[in] doc								The host document of the object. @cinemaOwnsPointed{document}
	/// @param[in] bt									The calling thread. Can be @formatConstant{nullptr}. @cinemaOwnsPointed{thread}
	/// @param[in] priority						The priority of the call to Execute() in the pipeline: @enumerateEnum{EXECUTIONPRIORITY}
	/// @param[in] flags							The execution flags: @enumerateEnum{EXECUTIONFLAGS}
	/// @return												The execution result: @enumerateEnum{EXECUTIONRESULT}
	//----------------------------------------------------------------------------------------
	virtual EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);

	/// @}

	/// @name Modeling Axis
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to return the modeling axis for the object.\n
	/// The value given here will be returned by BaseObject::GetModelingAxis. No built-in tools currently use this, as plugin objects are not editable. Only the camera will use it when in an editing mode.
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[in] doc								The host document of the object. @cinemaOwnsPointed{document}
	/// @param[out] axis							Assign the modeling axis.
	//----------------------------------------------------------------------------------------
	virtual void GetModelingAxis(BaseObject* op, BaseDocument* doc, Matrix& axis);

	/// @}

	/// @name Generator
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to get an object chain for a generator object.
	/// @calledThreadContext
	/// @warning Must not be overridden for non-generator objects.
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[in] hh									A hierarchy helper for the operation. @callerOwnsPointed{hierarchy helper}
	/// @return												The newly allocated object chain, or @formatConstant{nullptr} if a memory error occurred.\n
	///																If the generator does not produce any output (e.g. when the user chose wrong settings) it must at least return an (empty) @ref Onull object, otherwise @C4D will try to rebuild the cache again and again.\n
	///																Only return @formatConstant{nullptr} in the case of a memory error.\n
	///																An exception to this rule are generators with @enumerateEnum{OBJECT} flag OBJECT_INPUT set. If there is no input object, then such generators need to return @formatConstant{nullptr} as well.
	//----------------------------------------------------------------------------------------
	virtual BaseObject* GetVirtualObjects(BaseObject* op, HierarchyHelp* hh);

	/// @}

	/// @name Modifier
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to modify the passed object.
	/// @calledThreadContext
	/// @warning Must not be overridden for non-modifier objects.
	/// @param[in] mod								The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[in] doc								The document containing the object to modify. @cinemaOwnsPointed{document}
	/// @param[in,out] op							The object to modify. @cinemaOwnsPointed{object}
	/// @param[in] op_mg							The object's world matrix.
	/// @param[in] mod_mg							The modifier object's world matrix.
	/// @param[in] lod								The level of detail.
	/// @param[in] flags							Currently unused.
	/// @param[in] thread							The calling thread. Can be @formatConstant{nullptr}. @cinemaOwnsPointed{thread}
	/// @return												@trueIfOtherwiseFalse{the object was modified}
	//----------------------------------------------------------------------------------------
	virtual Bool ModifyObject(BaseObject* mod, BaseDocument* doc, BaseObject* op, const Matrix& op_mg, const Matrix& mod_mg, Float lod, Int32 flags, BaseThread* thread);

	//----------------------------------------------------------------------------------------
	/// Called to check for a change in a deformer object manually.\n
	/// For example this will make a deformer update every frame:
	/// @code
	/// void CheckDirty(BaseObject *op, BaseDocument *doc)
	/// {
	/// 	if (doc->GetTime()!=cached_time)
	/// 	{
	/// 		cached_time = doc->GetTime();
	/// 		op->SetDirty(DIRTYFLAGS::DATA);
	/// 	}
	/// }
	/// @endcode
	/// @calledThreadContext
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[in] doc								The document containing the object to modify. @cinemaOwnsPointed{document}
	//----------------------------------------------------------------------------------------
	virtual void CheckDirty(BaseObject* op, BaseDocument* doc);

	/// @}

	/// @name Spline
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to return a spline contour.
	/// @calledThreadContext
	/// @warning Must not be overridden for non-spline objects.
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[in] doc								The document containing the object to modify. @cinemaOwnsPointed{document}
	/// @param[in] lod								The level of detail.
	/// @param[in] bt									The calling thread. Can be @formatConstant{nullptr}. @cinemaOwnsPointed{thread}
	/// @return												The spline contour.\n
	///																If the generator does not produce any output (e.g. when the user chose wrong settings) it must at least return an (empty) @ref Onull object, otherwise @C4D will try to rebuild the cache again and again.\n
	///																Only return @formatConstant{nullptr} in the case of a memory error.
	//----------------------------------------------------------------------------------------
	virtual SplineObject* GetContour(BaseObject* op, BaseDocument* doc, Float lod, BaseThread* bt);

	/// @}

	/// @name Particle
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to modify particles.
	/// @calledThreadContext
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[in] pp									The initial element of the Particle array. @callerOwnsPointed{array}\n
	///																This array is used to read the particles information and should not be modified.
	/// @param[out] ss								The initial element of the BaseParticle array.\n
	///																Modify the elements in this array to change the velocity of the particles. @callerOwnsPointed{array}
	/// @param[in] pcnt								The number of particles in the @formatParam{pp} and @formatParam{ss} arrays.
	/// @param[in] diff								The time delta for the particles movement in seconds. Usually the difference in time between two frames, but this can be different for such functions as motion blur.
	//----------------------------------------------------------------------------------------
	virtual void ModifyParticles(BaseObject* op, Particle* pp, BaseParticle* ss, Int32 pcnt, Float diff);

	/// @}

	/// @name Automated Handle Interface
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to get the number of handles the object has.\n
	/// Part of the automated handle interface.
	/// @see HandleInfo.
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @return												The number of handles for the object.
	//----------------------------------------------------------------------------------------
	virtual Int32 GetHandleCount(BaseObject* op);

	//----------------------------------------------------------------------------------------
	/// Called to get the information for handle @formatParam{i}.\n
	/// Part of the automated handle interface.
	/// @see HandleInfo.
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[in] i									The handle index.
	/// @param[in,out] info						Fill with the handle information.
	//----------------------------------------------------------------------------------------
	virtual void GetHandle(BaseObject* op, Int32 i, HandleInfo& info);

	//----------------------------------------------------------------------------------------
	/// Called to set the information for handle @formatParam{i}.\n
	/// Called when the user has moved handle @formatParam{i} to position @formatParam{p}. Update the object's internal data accordingly (e.g. parameter values etc.).\n
	/// Part of the automated handle interface.
	/// @see HandleInfo.
	/// @param[in] op									The BaseObject connected with the ObjectData instance. Equal to <tt>static_cast</tt><@ref BaseObject*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{object}
	/// @param[in] i									The handle index.
	/// @param[in] p									The handle's position.
	/// @param[in] info								The handle information.
	//----------------------------------------------------------------------------------------
	virtual void SetHandle(BaseObject* op, Int32 i, Vector p, const HandleInfo& info);

	/// @}
};

//----------------------------------------------------------------------------------------
/// Registers an object plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
///																To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
///																Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The object plugin info flags: @enumerateEnum{OBJECT} @enumerateEnum{PLUGINFLAG}
/// @param[in] g									The allocator for the object plugin. This is a pointer to a function that creates a new instance of ObjectData with NewObj().
/// @param[in] description				The name of the description resource file to use for the object plugin without @em .res extension, for example @em "Oobjectname".\n
///																The name has to be unique, i.e. @em "Tdisplay" cannot be used for 2 different descriptions. See Description Resource for more information.
/// @param[in] icon								The icon for the object. The bitmap is copied. \n
///																The icon should be of size @em 32x@em 32, but will be scaled if needed.\n
///																It must also be @em 24 bits and should if possible include an alpha to support pattern backgrounds.
/// @param[in] disklevel					The plugin level is similar to a version number. The default level is @em 0.\n
///																Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
///																As an example you may have updated a plugin. If you now need to write additional information for new settings or changed types for old settings increase the level.\n
///																During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
///																For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.\n\n
///																@formatParam{disklevel} is only useful if variables are written/read in @ref NodeData::Write/@ref NodeData::Read.
/// @return												@trueIfOtherwiseFalse{the object plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterObjectPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* g, const maxon::String& description, BaseBitmap* icon, Int32 disklevel);

#endif // C4D_OBJECTDATA_H__
