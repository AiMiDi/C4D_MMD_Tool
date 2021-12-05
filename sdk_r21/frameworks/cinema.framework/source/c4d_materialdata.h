/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_MATERIALDATA_H__
#define C4D_MATERIALDATA_H__

#include "c4d_nodedata.h"
#include "operatingsystem.h"

class BaseMaterial;
class BaseObject;
class BaseDraw;
class BaseDrawHelp;
class BaseDocument;
class BaseBitmap;
class String;
class BaseTag;
class BaseThread;
struct InitRenderStruct;
struct VolumeData;

/// @addtogroup PLUGINFLAG_MATERIAL
/// @ingroup group_enumeration
/// @{
/// %Material plugin flags.
#define PLUGINFLAG_MATERIAL_GLIMAGE									(1 << 0)									///< %Material implements its own editor image preview in MaterialData::InitGLImage.
#define PLUGINFLAG_MATERIAL_NO_MATERIALEDITOR				(1 << 1)									///< Do not open Attribute Manager on double click or edit.
#define PLUGINFLAG_MATERIAL_HIDE_IN_MATERIALMANAGER	(1 << 2)									///< Do not show in the %Material Manager.
#define PLUGINFLAG_MATERIAL_GLIMAGE_TIMECHANGE			(1 << 3)									///< Same as @ref PLUGINFLAG_MATERIAL_GLIMAGE but called for each change in time.
#define PLUGINFLAG_MATERIAL_GLIMAGE_WITH_ALPHA			((1 << 0) | (1 << 4))			///< Editor image preview for the material has an alpha channel. (Implies @ref PLUGINFLAG_MATERIAL_GLIMAGE.)
#define PLUGINFLAG_MATERIAL_SHOW_IN_DEFAULT_MENU 		(1 << 5)									///< If set, material will appear in Preferences / Material / Material Manager / Default Material dropdown.
/// @}

//----------------------------------------------------------------------------------------
/// A data class for creating material plugins.
/// @see ShaderData
///
/// Use RegisterMaterialPlugin() to register a material plugin.
///
/// <b>General notes</b>\n
/// Here are some general comments on the material API:
/// - Coordinate Systems: if there is no further note, all elements like points, normals etc. are always given in global coordinates.
/// - Angle Systems: all angle values are always given in radians. Use @ref maxon::RadToDeg macro for conversion if needed.
/// - Vectors: all normals and ray vectors must be normalized. Also, all normals and ray vectors received from @C4D are normalized.
/// - Functions: no OS calls are allowed for @ref CalcSurface, @ref CalcVolumetric, @ref Displace, @ref ChangeNormal, @ref CalcTransparency, and @ref CalcAlpha. (These can be called within MP thread contexts.)
/// - Radiosity: @C4D automatically handles radiosity for shaders, but a description interface for the radiosity IDs must be provided manually. Please refer to the @em SimpleShader SDK example. Note that this means that IDs in the @em 1000 range are reserved, so start the material IDs above @em 2000.
///
/// <b>Optimization</b>\n
/// @ref CalcSurface, @ref CalcVolumetric, @ref ChangeNormal, @ref CalcTransparency and @ref CalcAlpha are the speed critical routines; concentrate efforts optimizing them.\n
/// Do not allocate new classes in those routines; only if absolutely necessary! Most of classes can be pre-allocated in @ref InitRender.\n
/// Avoid ANY function calls there. For instance to access the global render settings store the pointer in @ref InitRender for later use. This can save a tremendous amount of time.
//----------------------------------------------------------------------------------------
class MaterialData : public NodeData
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
	/// Called to draw additional information for the material in the editor.
	/// Called for every @formatParam{op}/@formatParam{tag} pair that references the material.
	/// @param[in] mat								The BaseMaterial connected with the MaterialData instance. Equal to <tt>static_cast</tt><@ref BaseMaterial*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{material}
	/// @param[in] op									The object associated with the material. @cinemaOwnsPointed{object}
	/// @param[in] tag								The material tag. @callerOwnsPointed{tag}
	/// @param[in] bd									The editor's view. @callerOwnsPointed{view}
	/// @param[in] bh									The helper for the editor's view. @callerOwnsPointed{base draw helper}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool Draw(BaseMaterial* mat, BaseObject* op, BaseTag* tag, BaseDraw* bd, BaseDrawHelp* bh);

	//----------------------------------------------------------------------------------------
	/// Called to get information about what the material plugin requires from the raytracer and what it returns.
	/// @param[in] mat								The BaseMaterial connected with the MaterialData instance. Equal to <tt>static_cast</tt><@ref BaseMaterial*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{material}
	/// @return												The volume info: @enumerateEnum{VOLUMEINFO}
	//----------------------------------------------------------------------------------------
	virtual VOLUMEINFO GetRenderInfo(BaseMaterial* mat);

	//----------------------------------------------------------------------------------------
	/// Called to initialize resources for rendering.
	/// @param[in] mat								The BaseMaterial connected with the MaterialData instance. Equal to <tt>static_cast</tt><@ref BaseMaterial*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{material}
	/// @param[in] irs								A struct with information about the upcoming rendering.
	/// @return												The result of the initialization: @enumerateEnum{INITRENDERRESULT}
	//----------------------------------------------------------------------------------------
	virtual INITRENDERRESULT InitRender(BaseMaterial* mat, const InitRenderStruct& irs);

	//----------------------------------------------------------------------------------------
	/// Called to free any resources allocated in @ref InitRender.
	/// @param[in] mat								The BaseMaterial connected with the MaterialData instance. Equal to <tt>static_cast</tt><@ref BaseMaterial*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{material}
	//----------------------------------------------------------------------------------------
	virtual void FreeRender(BaseMaterial* mat);

	//----------------------------------------------------------------------------------------
	/// Called every time a new series of shader calls is made.\n
	/// In @ref InitCalculation precalculate values for the following calls. Store the resulting data for each processor (@formatParam{vd}->@link VolumeData::GetCurrentCPU GetCurrentCPU()@endlink) separately because @ref InitCalculation may be entered multiple times on a MP thread contexts.\n
	/// If all the routines are overridden and the flags are set properly @C4D calls them in this order:
	///
	/// Before rendering:
	/// - InitRender() and GetRenderInfo()
	/// - <tt>InitCalculation</tt>(@ref INITCALCULATION::DISPLACEMENT)
	/// - Displace()
	///
	/// During rendering:
	/// - <tt>InitCalculation</tt>(@ref INITCALCULATION::SURFACE)
	/// - CalcAlpha()
	/// - ChangeNormal()
	/// - CalcSurface()
	/// - CalcVolumetric()
	///
	/// During rendering for e.g. shadow rays:
	/// - <tt>InitCalculation</tt>(@ref INITCALCULATION::TRANSPARENCY)
	/// - CalcAlpha()
	/// - CalcTransparency()
	/// @param[in] mat								The BaseMaterial connected with the MaterialData instance. Equal to <tt>static_cast</tt><@ref BaseMaterial*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{material}
	/// @param[in] vd									The volume data to use. @callerOwnsPointed{volume data}
	/// @param[in] type								The upcoming call sequence: @enumerateEnum{INITCALCULATION}
	//----------------------------------------------------------------------------------------
	virtual void InitCalculation(BaseMaterial* mat, VolumeData* vd, INITCALCULATION type);

	//----------------------------------------------------------------------------------------
	/// Called to displace a point on the surface.\n
	/// Modify @formatParam{vd}->@link VolumeData::p p@endlink. Usually it elevates the point along its normal a certain extent such as @formatParam{vd}->@link VolumeData::p p@endlink += @formatParam{vd}->@link VolumeData::dispn dispn@endlink * @c factor.\n
	/// Called after the render initialization (@ref InitRender) but during the beginning phase.
	/// @warning No OS calls are allowed during this function. Doing so could cause a crash, since it can be called in a multi-processor context.
	/// @param[in] mat								The BaseMaterial connected with the MaterialData instance. Equal to <tt>static_cast</tt><@ref BaseMaterial*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{material}
	/// @param[in,out] vd							The volume data to use and modify. @callerOwnsPointed{volume data}
	//----------------------------------------------------------------------------------------
	virtual void Displace(BaseMaterial* mat, VolumeData* vd);

	//----------------------------------------------------------------------------------------
	/// Called to create a bump effect.\n
	/// Modify @formatParam{vd}->@link VolumeData::bumpn bumpn@endlink. If @ref VOLUMEINFO::DUDVREQUIRED was set for the material registration then use @formatParam{vd}->@link VolumeData::ddu ddu@endlink and @formatParam{vd}->@link VolumeData::ddv ddv@endlink as modification directions perpendicular to the face normal.\n
	/// Called during rendering. See @ref InitCalculation for the order of calls.
	/// @warning No OS calls are allowed during this function. Doing so could cause a crash, since it can be called in a multi-processor context.
	/// @param[in] mat								The BaseMaterial connected with the MaterialData instance. Equal to <tt>static_cast</tt><@ref BaseMaterial*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{material}
	/// @param[in,out] vd							The volume data to use and modify. @callerOwnsPointed{volume data}
	//----------------------------------------------------------------------------------------
	virtual void ChangeNormal(BaseMaterial* mat, VolumeData* vd);

	//----------------------------------------------------------------------------------------
	/// Called to calculate the surface color.\n
	/// Set @formatParam{vd}->@link VolumeData::col col@endlink, @formatParam{vd}->@link VolumeData::trans trans@endlink and @formatParam{vd}->@link VolumeData::refl refl@endlink. Also @formatParam{vd}->@link VolumeData::rray rray@endlink and @formatParam{vd}->@link VolumeData::tray tray@endlink (the reflecting and transparent rays) can be modified.\n
	/// Called during rendering. See @ref InitCalculation for the order of calls.
	/// @note @formatParam{vd}->@link VolumeData::tray tray@endlink is only valid if @ref VOLUMEINFO::TRANSPARENCY was set for the material registration, and @formatParam{vd}->@link VolumeData::rray rray@endlink is only valid if @ref VOLUMEINFO::REFLECTION or @ref VOLUMEINFO::ENVREQUIRED was set.
	/// @warning No OS calls are allowed during this function. Doing so could cause a crash, since it can be called in a multi-processor context.
	/// @param[in] mat								The BaseMaterial connected with the MaterialData instance. Equal to <tt>static_cast</tt><@ref BaseMaterial*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{material}
	/// @param[in,out] vd							The volume data to use and modify. @callerOwnsPointed{volume data}
	//----------------------------------------------------------------------------------------
	virtual void CalcSurface(BaseMaterial* mat, VolumeData* vd);

	//----------------------------------------------------------------------------------------
	/// Called to speed up the transparency calculation.\n
	/// Several times @C4D needs the transparency information, for example for fast shadow calculation.\n
	/// Set @formatParam{vd}->@link VolumeData::trans trans@endlink. Use @formatParam{vd}->@link VolumeData::xlight xlight@endlink to find out which light is being evaluated.\n
	/// If this routine is not supplied then the result will be slower shadow calculations.\n
	/// Called during rendering. See @ref InitCalculation for the order of calls.
	/// @note @formatParam{vd}->@link VolumeData::tray tray@endlink is not valid and must not be modified.
	/// @warning No OS calls are allowed during this function. Doing so could cause a crash, since it can be called in a multi-processor context.
	/// @param[in] mat								The BaseMaterial connected with the MaterialData instance. Equal to <tt>static_cast</tt><@ref BaseMaterial*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{material}
	/// @param[in,out] vd							The volume data to use and modify. @callerOwnsPointed{volume data}
	//----------------------------------------------------------------------------------------
	virtual void CalcTransparency(BaseMaterial* mat, VolumeData* vd);

	//----------------------------------------------------------------------------------------
	/// Called to calculate the alpha.\n
	/// Set @formatParam{vd}->@link VolumeData::alpha alpha@endlink.
	/// @warning No OS calls are allowed during this function. Doing so could cause a crash, since it can be called in a multi-processor context.
	/// @param[in] mat								The BaseMaterial connected with the MaterialData instance. Equal to <tt>static_cast</tt><@ref BaseMaterial*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{material}
	/// @param[in,out] vd							The volume data to use and modify. @callerOwnsPointed{volume data}
	//----------------------------------------------------------------------------------------
	virtual void CalcAlpha(BaseMaterial* mat, VolumeData* vd);

	//----------------------------------------------------------------------------------------
	/// Called to calculate volumetric information.\n
	/// @note If @ref VOLUMEINFO::VOLUMETRIC is not set for the material registration this function is not needed. If @ref VOLUMEINFO::VOLUMETRIC is set this function is required.\n
	/// Set @formatParam{vd}->@link VolumeData::col col@endlink and @formatParam{vd}->@link VolumeData::trans trans@endlink.\n
	/// Called for spans; @formatParam{vd}->@link VolumeData::ray ray@endlink->@link Ray::p p@endlink to @formatParam{vd}->@link VolumeData::p p@endlink where @formatParam{vd}->@link VolumeData::ray ray@endlink->@link Ray::p p@endlink is the entry point and @formatParam{vd}->@link VolumeData::p p@endlink is the exit point.\n
	/// Volumetric shaders that do not have a surface calculation can set @formatParam{vd}->@link VolumeData::trans trans@endlink = vector(1.0) in @ref CalcSurface and @ref CalcTransparency.\n
	/// Called during rendering. See @ref InitCalculation for the order of calls.
	/// @warning No OS calls are allowed during this function. Doing so could cause a crash, since it can be called in a multi-processor context.
	/// @param[in] mat								The BaseMaterial connected with the MaterialData instance. Equal to <tt>static_cast</tt><@ref BaseMaterial*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{material}
	/// @param[in,out] vd							The volume data to use and modify. @callerOwnsPointed{volume data}
	//----------------------------------------------------------------------------------------
	virtual void CalcVolumetric(BaseMaterial* mat, VolumeData* vd);

	//----------------------------------------------------------------------------------------
	/// Called to return a 2D representation of the material for use in the editor.\n
	/// The image is shown both in OpenGL and Software mode.\n
	/// @note After you set the content of the image you have to call BaseBitmap::SetDirty().
	/// @param[in] mat								The BaseMaterial connected with the MaterialData instance. Equal to <tt>static_cast</tt><@ref BaseMaterial*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{material}
	/// @param[in] doc								The document. @callerOwnsPointed{document}
	/// @param[in] th									The thread. @callerOwnsPointed{thread}
	/// @param[in,out] bmp						The bitmap to fill, initialized to the right size. @callerOwnsPointed{bitmap}
	/// @param[in] doccolorspace			The document's color space: @enumerateEnum{DOCUMENT_COLORPROFILE}
	/// @param[in] linearworkflow			@trueIfOtherwiseFalse{Linear Workflow is enabled}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool InitGLImage(BaseMaterial* mat, BaseDocument* doc, BaseThread* th, BaseBitmap* bmp, Int32 doccolorspace, Bool linearworkflow);

	//----------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//----------------------------------------------------------------------------------------
	virtual GL_MESSAGE GlMessage(BaseMaterial* mat, Int32 type, void* data);

	//----------------------------------------------------------------------------------------
	/// Called to check if the material has editor transparency.
	/// @since R17.032
	/// @return												@trueIfOtherwiseFalse{if the material supports editor transparency}
	//----------------------------------------------------------------------------------------
	virtual Bool HasEditorTransparency(BaseMaterial* mat);
};

//----------------------------------------------------------------------------------------
/// Registers a material plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
/// 															To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
/// 															Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The node plugin info flags: @enumerateEnum{PLUGINFLAG_MATERIAL} @enumerateEnum{PLUGINFLAG}
/// @param[in] g									The allocator for the material plugin. This is a pointer to a function that creates a new instance of MaterialData with NewObj().
/// @param[in] description				The name of the description resource file to use for the material plugin without @em .res extension, for example @em "Mmaterialname".\n
/// 															The name has to be unique, i.e. @em "Tdisplay" cannot be used for 2 different descriptions. See Description Resource for more information.
/// @param[in] disklevel					The plugin level is similar to a version number. The default level is @em 0.\n
/// 															Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
/// 															As an example you may have updated a plugin. If you now need to write additional information for new settings or changed types for old settings increase the level.\n
/// 															During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
/// 															For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.\n\n
/// 															@formatParam{disklevel} is only useful if variables are written/read in @ref NodeData::Write/@ref NodeData::Read.
/// @return												@trueIfOtherwiseFalse{the material plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterMaterialPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* g, const maxon::String& description, Int32 disklevel);

#endif // C4D_MATERIALDATA_H__
