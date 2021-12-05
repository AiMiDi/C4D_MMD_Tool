/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_VIDEOPOSTDATA_H__
#define C4D_VIDEOPOSTDATA_H__

#include "c4d_nodedata.h"
#include "c4d_string.h"
#include "ge_math.h"
#include "operatingsystem.h"

class BaseVideoPost;
class BaseContainer;
class BaseDocument;
class BaseObject;
class BaseDraw;
class BaseDrawHelp;
class BaseDocument;
class BaseBitmap;
class String;
class CDialog;
class Render;
class RenderJob;
class GlFrameBuffer;
class NetRenderData;
struct Multipass;
struct PixelPost;
struct VideoPostStruct;
struct VolumeData;
struct RayFragment;
struct Ray;
struct NetRenderBuffer;
struct NetRenderDocumentContext;

/// @addtogroup VIDEOPOSTCALL
/// @ingroup group_enumeration
/// @{
enum class VIDEOPOSTCALL
{
	FRAMESEQUENCE	= 1,	///< Called when the renderer prepares to render a sequence of images.
	FRAME					= 2,	///< Called when the renderer prepares to render a frame.
	SUBFRAME			= 3,	///< Called when the renderer prepares to render a subframe.
	RENDER				= 4,	///< Called before the rendering process starts and before shaders are initialized.
	INNER					= 5,	///< Called immediately before rendering starts.
	TILE					= 6		///< Called immediately before rendering a bucket. @since R16
} MAXON_ENUM_LIST(VIDEOPOSTCALL);
/// @}

struct BaseVideoPostStruct
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	BaseVideoPostStruct()
	{
		version					= 0;
		vp							= (VIDEOPOSTCALL)0;
		open						= false;
		fps							= 30;
		error						= nullptr;
		vd							= nullptr;
		doc							= nullptr;
		thread					= nullptr;
		subframe				= 0;
		subframe_cnt		= 1;
		field						= 0;
		field_cnt				= 1;
		render					= nullptr;
		renderflags			= RENDERFLAGS::NONE;
		linear_workflow = false;
		colorspacetransformation = COLORSPACETRANSFORMATION::NONE;
		net							= nullptr;
		net_server			= false;
	}

	Int32 version;										///< The version of @C4D.
	VIDEOPOSTCALL vp;									///< the VideoPost call: @enumerateEnum{VIDEOPOSTCALL}
	Bool open;												///< @formatConstant{true} if it is an opening call. See also VideoPostData::Execute.
	BaseTime time;										///< The current time.
	Int32 fps;												///< The number of frames per second.
	RENDERRESULT* error;							///< The render result error: @enumerateEnum{RENDERRESULT} May be @formatConstant{nullptr}.
	VolumeData* vd;										///< The current VolumeData. Only valid for @ref VIDEOPOSTCALL::INNER and @ref VIDEOPOSTCALL::RENDER calls.
	BaseDocument* doc;								///< The active document.

	BaseThread* thread;								///< The executing thread. Use <tt>thread</tt>->@link BaseThread::TestBreak TestBreak()@endlink to check for a user break.

	Int32 subframe,										///< The current subframe. Multiple subframes are rendered if scene motion blur or field rendering are used.
				subframe_cnt;								///< The number of subframes.

	Int32 field,											///< The current field. Multiple subframes are rendered if scene motion blur or field rendering are used.
				field_cnt;									///< The number of fields.

	Render* render;										///< The current render.

	RENDERFLAGS renderflags;					///< The render flags passed to RenderDocument(): @enumerateEnum{RENDERFLAGS}

	Bool linear_workflow;							///< Linear workflow enabled/disabled.
	COLORSPACETRANSFORMATION colorspacetransformation;			///< Color space transformation: @enumerateEnum{COLORSPACETRANSFORMATION}

	NetRenderDocumentContext* net;		///< If not @formatConstant{nullptr} then it is a Team %Render rendering and this holds NET context information.
	Bool net_server;									///< If @formatConstant{true} the rendering is executed on a server side, otherwise it is on a client side.
};

/// @addtogroup VPBUFFER
/// @ingroup group_enumeration
/// @{
#define VPBUFFER_RGBA						1								///< RGB and alpha multipass channel.
#define VPBUFFER_AMBIENT				2								///< Ambient multipass channel.
#define VPBUFFER_DIFFUSE				3								///< Diffuse multipass channel.
#define VPBUFFER_SPECULAR				4								///< Specular multipass channel.
#define VPBUFFER_SHADOW					5								///< Shadow multipass channel.
#define VPBUFFER_REFLECTION			6								///< Reflection multipass channel.
#define VPBUFFER_TRANSPARENCY		7								///< Transparency multipass channel.
#define VPBUFFER_RADIOSITY			8								///< Radiosity multipass channel.
#define VPBUFFER_CAUSTICS				9								///< Caustics multipass channel.
#define VPBUFFER_ATMOSPHERE			10							///< Atmosphere multipass channel.
#define VPBUFFER_ATMOSPHERE_MUL	11							///< Atmosphere (multiply) multipass channel.
#define VPBUFFER_ALLPOSTEFFECTS	12							///< All post effects channel.

#define VPBUFFER_IMAGEBUILDING_PASS	32					///< The maximum number of the image building layers.

#define VPBUFFER_DEPTH							100					///< Depth multipass channel.
#define VPBUFFER_MAT_COLOR					101					///< Material color multipass channel.
#define VPBUFFER_MAT_DIFFUSION			102					///< Material diffusion multipass channel.
#define VPBUFFER_MAT_LUMINANCE			103					///< Material luminance multipass channel.
#define VPBUFFER_MAT_TRANSPARENCY		104					///< Material transparency multipass channel.
#define VPBUFFER_MAT_REFLECTION			105					///< Material reflection multipass channel.
#define VPBUFFER_MAT_ENVIRONMENT		106					///< Material environment multipass channel.
#define VPBUFFER_MAT_SPECULAR				107					///< Material specular multipass channel.
#define VPBUFFER_MAT_SPECULARCOLOR	108					///< Material specular color multipass channel.
#define VPBUFFER_ILLUMINATION				109					///< Illumination multipass channel.
#define VPBUFFER_OBJECTBUFFER				110					///< Object buffer multipass channel.

#define VPBUFFER_POSTEFFECT					111					///< Post effect channel.
#define VPBUFFER_POSTEFFECT_MUL			112					///< Post effect (multiply) channel.
#define VPBUFFER_AMBIENTOCCLUSION		113					///< Ambient occlusion channel.
#define VPBUFFER_MAT_NORMAL					114					///< Material normal channel.
#define VPBUFFER_MAT_UV							115					///< Material UV channel.
#define VPBUFFER_MOTIONVECTOR				116					///< Motion vector channel.
#define VPBUFFER_SAMPLER						117					///< Sampler channel.

#define VPBUFFER_BLEND							1000				///< Blend multipass channel.
#define VPBUFFER_LIGHTBLEND					1001				///< @markPrivate
#define VPBUFFER_ALPHA							1002				///< Alpha multipass channel (for SDK request only).
#define VPBUFFER_BLENDCH						1003				///< @markPrivate
#define VPBUFFER_REFLECTION_FOLDER	1004				///< @markPrivate @since R16
#define VPBUFFER_REFLECTION_LAYER		1005				///< @markPrivate @since R16
#define VPBUFFER_SPECULAR_FOLDER		1006				///< @markPrivate @since R16
#define VPBUFFER_SPECULAR_LAYER			1007				///< @markPrivate @since R16

#define VPBUFFER_DIRECT_DIFFUSE					200				///< @markPrivate @since R20
#define VPBUFFER_INDIRECT_DIFFUSE				201				///< @markPrivate @since R20
#define VPBUFFER_DIRECT_SPECULAR				202				///< @markPrivate @since R20
#define VPBUFFER_INDIRECT_SPECULAR			203				///< @markPrivate @since R20

#define VPBUFFER_AOV										204				///< AOV buffer multipass channels.
#define VPBUFFER_REFLECTANCE_ALBEDO			205				///< Reflectance Channel Diffuse Albedo.
/// @}

struct PixelPost
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	PixelPost()
	{
		frag				= nullptr;
		frag_nx			= nullptr;
		vd					= nullptr;
		col					= nullptr;
		mp					= nullptr;
		aa					= false;
		valid_line	= false;
		comp				= 0;
		cpu_num			= 0;
		xmin				= 0;
		xmax				= 0;
		line				= 0;
	}

#ifdef __API_INTERN__
	RayFragment**		frag;
	RayFragment**		frag_nx;
#else
	PixelFragment** frag;							///< The current pixel fragment.
	PixelFragment** frag_nx;					///< The pixel fragments for the next line. @markPrivate
#endif
	VolumeData*			vd;								///< The current VolumeData.
	Float32*				col;							///< The buffer to the full line for VideoPostData::ExecuteLine or the sub-pixels for VideoPostData::ExecutePixel.
	Multipass*			mp;								///< The current Multipass.
	Bool						aa;								///< @formatConstant{true} means that antialiasing is used during rendering.\n
																		///< In the case of antialiasing this has an important impact on VideoPostData::ExecuteLine, using antialiasing means that each pixel is split into @em 4 independent sub-pixels.\n
																		///< In the case of VideoPostData::ExecuteLine col is the buffer to the line.\n
																		///< If @formatConstant{false} the line contains for each pixel @ref comp ::Float values (e.g. @ref comp==@em 3 gives RGB components).\n
																		///< If @formatConstant{true} the line contains for each pixel @em 4 @ref comp ::Float values (@em 4 sub-pixels: first one is upper left, then upper right, then lower left, then lower right).
	Bool						valid_line;				///< @formatConstant{true} means that the line has not yet been processed.\n
																		///< During antialiasing and multiprocessor rendering it is possible that a few lines are rendered twice.\n
																		///< Imagine that you have created abuffer. In VideoPostData::ExecuteLine you save the local data to the buffer which is then processed at the end of the frame.\n
																		///< To avoid that the same line is calculated twice @ref valid_line is set to @formatConstant{false} after it already has been processed.
	Int32						comp;							///< The number of components per pixel. At least @em 3 (RGB), but larger values are possible. (Depending on existing special buffers, alphas etc.)\n
																		///< The structure of those components is stored in the Multipass structure.
	Int32						cpu_num;					///< The current CPU.
	Int32						xmin;							///< The left value of the rendered line (main pixel units, no sub-pixels).
	Int32						xmax;							///< The right value of the rendered line (main pixel units, no sub-pixels).
	Int32						line;							///< The current vertical line (main pixel units).
};

/// @addtogroup VideoPostTypes
/// @ingroup group_enumeration
/// @{
/// Video post types.
#define VPlenseffects							1001049				///< Lens effects.
#define VPobjectglow							1001007				///< Object glow.
#define VPcolorcorrection					1001008				///< Color correction.
#define VPcomic										1001009				///< Comic.
#define VPscenemotionblur					1001010				///< Scene motion blur.
#define VPsoftfilter							1001012				///< Soft filter.
#define VPsharpenfilter						1001013				///< Sharpen filter.
#define VPmedianfilter						1001014				///< Median filter.
#define VPremote									1001015				///< Remote.
#define VPopticsuite_depthoffield 1001400				///< Optic suite dof.
#define VPopticsuite_glow					1001401				///< Optic suite glow.
#define VPopticsuite_highlights		1001402				///< Optic suite highlights.
#define VPambientocclusion				300001045			///< Ambient occlusion.
#define VPxmbsampler							1023342				///< Subsurface scattering sampler.
#define VPGPURenderer							1037639				///< GPU Renderer. @since R19
#define VPToneMapping							1037876				///< Tone-Mapper. @since R19
#define VPDenoiser								1050980				///< Denoiser.
#define VPdemowatermark						1037739 			///< Demo Watermark. @since R19
/// @}

/// @addtogroup VPPRIORITY
/// @ingroup group_enumeration
/// @{
/// Video post priority.
#define VPPRIORITY_OBJECTGLOW				500				///< Priority for object glow.
#define VPPRIORITY_OBJECTMOTIONBLUR 400				///< Priority for object motion blur.
#define VPPRIORITY_DEPTHOFFIELD			300				///< Priority for depth of field.
#define VPPRIORITY_LENSEFFECTS			200				///< Priority for the lens effect.
#define VPPRIORITY_FILTERSOFT				100				///< Priority for filter soft.
#define VPPRIORITY_FILTERSHARPEN		100				///< Priority for sharpen filter.
#define VPPRIORITY_FILTERMEDIAN			100				///< Priority for median filter.

#define VPPRIORITY_COMIC					 600				///< Priority for comic.
#define VPPRIORITY_COLORCORRECTION 500				///< Priority for color correction.
#define VPPRIORITY_SCENEMOTIONBLUR 100				///< Priority for scene motion blur.
#define VPPRIORITY_EXTERNAL				 100				///< Priority for remote (external).
/// @}

/// @addtogroup PLUGINFLAG_VIDEOPOST
/// @ingroup group_enumeration
/// @{
/// Video post plugin flags.
#define PLUGINFLAG_VIDEOPOST_MULTIPLE					(1 << 0)																																					///< Allow multiple effects of this type.
#define PLUGINFLAG_VIDEOPOST_INHERENT					(1 << 1)																																					///< Always active. (Use with caution!)
#define PLUGINFLAG_VIDEOPOST_GL								(1 << 2)																																					///< Supports OpenGL drawing.
#define PLUGINFLAG_VIDEOPOST_ISRENDERER				(1 << 3)																																					///< Renderer.
#define PLUGINFLAG_VIDEOPOST_STEREO_EDITOR		(1 << 4)																																					///< Stereoscopic viewport display. Requires @ref PLUGINFLAG_VIDEOPOST_GL to be set.
#define PLUGINFLAG_VIDEOPOST_STEREO_RENDERING	(1 << 5)																																					///< Stereoscopic rendering.
#define PLUGINFLAG_VIDEOPOST_STEREO						((PLUGINFLAG_VIDEOPOST_STEREO_EDITOR) | (PLUGINFLAG_VIDEOPOST_STEREO_RENDERING))	///< Both stereoscopic view display and rendering, (@ref PLUGINFLAG_VIDEOPOST_STEREO_EDITOR|@ref PLUGINFLAG_VIDEOPOST_STEREO_RENDERING).
#define PLUGINFLAG_VIDEOPOST_ISRENDERER_NET		(1 << 6)																																					///< Supports Team %Render/NET. Requires @ref PLUGINFLAG_VIDEOPOST_ISRENDERER to be set.
#define PLUGINFLAG_VIDEOPOST_MULTIPASS				(1 << 7)																																					///< Supports multipasses (needed for Cineware support). @since R16
/// @}

/// @addtogroup VIDEOPOST_GLINFO
/// @ingroup group_enumeration
/// @{
/// @extOpenGlMode
enum class VIDEOPOST_GLINFO : UInt32
{
	NONE															= 0x00000000,
	CUSTOM_MOUSE											= 0x00000001,
	ALLOC_UVW_BUFFER									= 0x00000002,
	ALLOC_UVW_BUFFER_FLOAT32					= 0x00100002,
	ALLOC_DU_BUFFER										= 0x00000004,
	ALLOC_DV_BUFFER										= 0x00000008,
	ALLOC_NORMAL_BUFFER								= 0x00000010,
	ALLOC_MATERIAL_ID									= 0x00000020,
	ALLOC_NORMAL_BUFFER_FLOAT16				= 0x00100010,
	ALLOC_NORMAL_BUFFER_FLOAT32				= 0x00200010,
	ALLOC_WORLCOORD_BUFFER						= 0x00000040,
	ALLOC_OBJECTID_BUFFER							= 0x00000080,
	PREPASS														= 0x01000000,
	DRAW															= 0x02000000,
	STEREO3D													= 0x04000000,
	ALLOC_UVW_MATID_BUFFER_FLOAT32		= 0x00000100,
	ALLOC_TEXEL_SELECTION_BUFFER_R8I	= 0x00000200,				///< @since R19
	DISABLED													= 0x80000000
} MAXON_ENUM_FLAGS(VIDEOPOST_GLINFO);
/// @}

/// @addtogroup VIDEOPOST_GLDRAW
/// @ingroup group_enumeration
/// @{
/// @extOpenGlMode
enum class VIDEOPOST_GLDRAW
{
	NONE								= 0,
	CUSTOM_MOUSE_INIT		= (1 << 0),
	CUSTOM_MOUSE_DRAW		= (1 << 1),
	PREPASS							= (1 << 2),
	DRAW								= (1 << 3)
} MAXON_ENUM_FLAGS(VIDEOPOST_GLDRAW);
/// @}

#define MSG_VIDEOPOST_TIMESHIFT						300000106			///< @markInternal
#define MSG_GLOBALILLUMINATIONINFORMATION	300001050			///< Called when global illumination and caustic video post effects. The corresponding data is GlobalIlluminationInformation.

//----------------------------------------------------------------------------------------
/// Message struct for the @ref MSG_GLOBALILLUMINATIONINFORMATION message.
//----------------------------------------------------------------------------------------
struct GlobalIlluminationInformation
{
	Bool reflective_caustics;					///< Set this @formatConstant{true} for reflective caustics.
	Bool refractive_caustics;					///< Set this @formatConstant{true} for refractive caustics.
	Float refractive_cutoff;					///< Set the refractive cufoff threshold.
	Bool ambient_occlusion;						///< Set this @formatConstant{true} to enable ambient occlusion.
	Bool radiance_enabled;						///< Set this @formatConstant{true} to enable radiance.
	Int32 radiance_mode;							///< Set the radiance mode.
	Int32 radiance_samples;						///< Set the radiance samples.
	Float radiance_density;						///< Set the radiance density.
	Float radiance_intensity;					///< Set the radiance intensity.
	Float radiance_saturation;				///< Set radiance saturation.
	Bool lightmapping_enabled;				///< Set this @formatConstant{true} to enable lightmapping.
	Bool lightmapping_direct;					///< Set this @formatConstant{true} for lightmapping direct.
	Int32 lightmapping_mode;					///< Set lightmapping mode.
};

//----------------------------------------------------------------------------------------
/// Stereoscopic camera information.
//----------------------------------------------------------------------------------------
struct StereoCameraInfo
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	StereoCameraInfo() : off_x(0.0), off_y(0.0) { }

	Matrix m;						///< Matrix of the stereoscopic camera.
	Float off_x,				///< Stereoscopic camera film X offset.
				off_y;				///< Stereoscopic camera film Y offset.
	String strName;			///< Name of the stereoscopic camera.
};

//----------------------------------------------------------------------------------------
/// Motion information.
/// @since R17.032
//----------------------------------------------------------------------------------------
struct MotionInfo
{
	Int32	debugOutput;						///< Debug ouput level.
	Bool	enableDOF;							///< Enable DOF.
	Bool	enableMotion;						///< Enable motion blur.
	Int32	motionPrimary;					///< Sample motion blur.
	Int32	motionDeformation;			///< Sample deformation.
	Int32	motionHair;							///< Sample hair.
};

/// @addtogroup RENDERPROPERTY
/// @ingroup group_enumeration
/// @{
#define RENDERPROPERTY_CLUSTERFRAGMENTS	1				///< Cluster fragments. This tells @C4D to cluster sub-fragments of the same object (but with different polygon IDs).\n
																								///< Clustering makes @C4D faster, but for a few purposes (like the Cell AA filter that needs the separate polygon IDs to stay separate fragments) it is unwanted.
#define RENDERPROPERTY_BUCKETOVERLAP		2				///< If @formatConstant{true} each scanline is prepared one pixel bigger in X and Y direction. @markPrivate
/// @}

//----------------------------------------------------------------------------------------
/// A data class for creating video post plugins.\n
/// In a video post hook it is possible to do just everything, not just the image processing that the name implies.\n
/// It is possible to prepare information for shaders, modify image buffers, initialize hardware, output an image to an image recorder etc.
///
/// Use RegisterVideoPostPlugin() to register a video post plugin.
//----------------------------------------------------------------------------------------
class VideoPostData : public NodeData
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
	/// Not used!
	//----------------------------------------------------------------------------------------
	virtual Bool Draw(BaseVideoPost* node, BaseDraw* bd, BaseDrawHelp* bh);

	//----------------------------------------------------------------------------------------
	/// Called to request additional buffers to process.\n
	/// One buffer is always there: @ref VPBUFFER_RGBA, it is the RGB image.\n
	/// Either the user (on the Multipass tab) or a video post plugin now can request more buffers (like @ref VPBUFFER_DIFFUSE, which is the Diffuse Multipass layer) with any color resolution (@em 8 bit, @em 16 bit or @em 32 bit for each channel).\n
	/// For example:
	/// @code
	/// render->AllocateBuffer(VPBUFFER_ALPHA, 0, 32, false);
	/// @endcode
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in,out] render					The Render class to use to allocate additional buffers. @callerOwnsPointed{render}
	/// @param[in] doc								The active document. @callerOwnsPointed{document}
	//----------------------------------------------------------------------------------------
	virtual void AllocateBuffers(BaseVideoPost* node, Render* render, BaseDocument* doc);

	//----------------------------------------------------------------------------------------
	/// Called to get information about the video post.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @return												The video post information: @enumerateEnum{VIDEOPOSTINFO}
	//----------------------------------------------------------------------------------------
	virtual VIDEOPOSTINFO GetRenderInfo(BaseVideoPost* node);

	/// @name Execute
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called for all video post entry and exit points: @enumerateEnum{VIDEOPOSTCALL}
	///
	/// The calling sequence is:\n
	///	@ref VIDEOPOSTCALL::FRAMESEQUENCE - @link VideoPostStruct::open open@endlink==@formatConstant{true} - Series of images starts. - <i>\<Sequence\></i>\n
	///		&nbsp;@ref VIDEOPOSTCALL::FRAME - @link VideoPostStruct::open open@endlink==@formatConstant{true} - Image render starts. - <i>\<Frame\></i>\n
	///			&nbsp;&nbsp;@ref VIDEOPOSTCALL::SUBFRAME - @link VideoPostStruct::open open@endlink==@formatConstant{true} - Sub-frame starts. - <i>\<Sub-frame\></i>\n
	///			&nbsp;&nbsp;@ref VIDEOPOSTCALL::RENDER - @link VideoPostStruct::open open@endlink==@formatConstant{true} - %Render precalculation. VolumeData not yet completely accessible.\n
	///			&nbsp;&nbsp;@ref VIDEOPOSTCALL::INNER - @link VideoPostStruct::open open@endlink==@formatConstant{true} - %Render precalculation.\n
	///			&nbsp;&nbsp;@ref ExecuteLine()/@ref ExecutePixel() During rendering.\n
	///			&nbsp;&nbsp;@ref VIDEOPOSTCALL::INNER - @link VideoPostStruct::open open@endlink==@formatConstant{false} - Immediately after rendering.\n
	///			&nbsp;&nbsp;@ref VIDEOPOSTCALL::RENDER - @link VideoPostStruct::open open@endlink==@formatConstant{false} - Immediately after shader cleanup. VolumeData no longer accessible!\n
	///			&nbsp;&nbsp;@ref VIDEOPOSTCALL::SUBFRAME - @link VideoPostStruct::open open@endlink==@formatConstant{false} - Sub-frame rendering done. - <i>\</Sub-frame\></i>\n
	///		&nbsp;@ref VIDEOPOSTCALL::FRAME - @link VideoPostStruct::open open@endlink==@formatConstant{false} - Frame rendering done. - <i>\</Frame\></i>\n
	///	@ref VIDEOPOSTCALL::FRAMESEQUENCE - @link VideoPostStruct::open open@endlink==@formatConstant{false} - Complete rendering process finished. - <i>\</Sequence\></i>
	///
	/// The order of calls is guaranteed, and every opening call is matched by a corresponding closing call.\n
	/// @ref VIDEOPOSTCALL::RENDER is opened immediately before shader initialization, and @ref VIDEOPOSTCALL::INNER immediately before rendering.
	///
	/// Multiple sub-frames are rendered if scene motion blur or field rendering is used. In this case the number of subframes/fields is available in VideoPostStruct::subframe_cnt and VideoPostStruct::field_cnt.
	///
	/// Most of the times only the @ref VIDEOPOSTCALL::RENDER and @ref VIDEOPOSTCALL::INNER calls are of interest. In this case @ref Execute would look like this:
	/// @code
	/// RENDERRESULT MyVideoPost::Execute(BaseVideoPost *node, VideoPostStruct *vps)
	/// {
	/// 	if (vps->vp!=VIDEOPOSTCALL::RENDER)
	/// 		return RENDERRESULT::OK;
	///
	/// 	// Do something...
	///
	/// 	return result;
	/// }
	/// @endcode
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in] vps								The video post information. @callerOwnsPointed{video post struct}
	/// @return												The render result: @enumerateEnum{RENDERRESULT}
	//----------------------------------------------------------------------------------------
	virtual RENDERRESULT Execute(BaseVideoPost* node, VideoPostStruct* vps);

	//----------------------------------------------------------------------------------------
	/// Called after each rendered line.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in] pp									The pixel buffer. @callerOwnsPointed{buffer}
	//----------------------------------------------------------------------------------------
	virtual void ExecuteLine(BaseVideoPost* node, PixelPost* pp);

	//----------------------------------------------------------------------------------------
	/// Called for every sub-fragment (sub-pixel) that is rendered.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in] pp									The pixel buffer. @callerOwnsPointed{buffer}
	/// @param[in] x									The main pixel X position.
	/// @param[in] subx								The sub-pixel X position. (@em 0 <= @formatParam{subx} <= @em 15)
	/// @param[in] suby								The sub-pixel Y position. (@em 0 <= @formatParam{suby} <= @em 15)
	//----------------------------------------------------------------------------------------
	virtual void ExecutePixel(BaseVideoPost* node, PixelPost* pp, Int32 x, Int32 subx, Int32 suby);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Called to calculate volumetric information.\n
	/// Set @formatParam{vd}->@link VolumeData::col col@endlink and @formatParam{vd}->@link VolumeData::trans trans@endlink.\n
	/// If @ref VIDEOPOSTINFO::CALCVOLUMETRIC is not set then @ref CalcVolumetric is not needed. If this flag is set then @ref CalcVolumetric is required.\n
	///
	/// Called for spans; @formatParam{vd}->@link VolumeData::ray ray@endlink->@link Ray::p p@endlink to @formatParam{vd}->@link VolumeData::p p@endlink where @formatParam{vd}->@link VolumeData::ray ray@endlink->@link Ray::p p@endlink is the entry point and @formatParam{vd}->@link VolumeData::p p@endlink is the exit point.
	///
	/// @warning No OS calls are allowed during this function. Doing so could cause a crash, since it can be called in a multi-processor context.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in,out] vd							The volume data to use and modify. @callerOwnsPointed{volume data}
	//----------------------------------------------------------------------------------------
	virtual void CalcVolumetric(BaseVideoPost* node, VolumeData* vd);

	//----------------------------------------------------------------------------------------
	/// Called to calculate shadow information.\n
	/// If @ref VIDEOPOSTINFO::CALCSHADOW is not set then @ref CalcShadow is not needed. If this flag is set then @ref CalcShadow is required.
	/// @warning No OS calls are allowed during this function. Doing so could cause a crash, since it can be called in a multi-processor context.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in,out] vd							The volume data to use and modify. @callerOwnsPointed{volume data}
	//----------------------------------------------------------------------------------------
	virtual void CalcShadow(BaseVideoPost* node, VolumeData* vd);

	//----------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//----------------------------------------------------------------------------------------
	virtual Bool GlDraw(BaseVideoPost* node, BaseDraw* bd, GlFrameBuffer* fbuf, Int32 colortex, Int32 depthtex, VIDEOPOST_GLDRAW flags);

	//----------------------------------------------------------------------------------------
	/// @extOpenGlMode
	//----------------------------------------------------------------------------------------
	virtual VIDEOPOST_GLINFO GetGlInfo(BaseVideoPost* node, BaseDocument* doc, BaseDraw* bd);

	/// @name Physical
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to calculate global illumination information.\n
	/// If @ref VIDEOPOSTINFO::GLOBALILLUMINATION is not set then @ref ComputeDiffuseGI is not needed. If this flag is set then @ref ComputeDiffuseGI is required.
	/// @warning No OS calls are allowed during this function. Doing so could cause a crash, since it can be called in a multi-processor context.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in,out] vd							The volume data to use and modify. @callerOwnsPointed{volume data}
	/// @param[in] receive_strength		The receive GI strength of the rendered materials.
	/// @return												The global illumination component.
	//----------------------------------------------------------------------------------------
	virtual Vector ComputeDiffuseGI(BaseVideoPost* node, VolumeData* vd, Float receive_strength);

	//----------------------------------------------------------------------------------------
	/// Called to calculate surface caustics information.\n
	/// If @ref VIDEOPOSTINFO::CAUSTICS is not set then @ref ComputeDiffuseCaustic is not needed. If this flag is set then @ref ComputeDiffuseCaustic is required.
	/// @warning No OS calls are allowed during this function. Doing so could cause a crash, since it can be called in a multi-processor context.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in,out] vd							The volume data to use and modify. @callerOwnsPointed{volume data}
	/// @param[in] sampleradius				The caustics sample radius of the rendered materials.
	/// @param[in] accuracy						The caustics sample count of the rendered material.
	/// @return												The surface caustics component.
	//----------------------------------------------------------------------------------------
	virtual Vector ComputeDiffuseCaustic(BaseVideoPost* node, VolumeData* vd, Float sampleradius, Int32 accuracy);

	//----------------------------------------------------------------------------------------
	/// Called to calculate volume caustics information.\n
	/// If @ref VIDEOPOSTINFO::CAUSTICS is not set then @ref ComputeDiffuseCaustic is not needed. If this flag is set then @ref ComputeDiffuseCaustic is required.
	/// @warning No OS calls are allowed during this function. Doing so could cause a crash, since it can be called in a multi-processor context.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in] p									The rendered point for volume caustics.
	/// @param[in] cpu_index					The index of the current running thread (@em 0 to cpu_cnt-@em 1), so that the volume caustics calculation get this information passed.
	/// @return												The volume caustics component.
	//----------------------------------------------------------------------------------------
	virtual Vector ComputeVolumeCaustic(BaseVideoPost* node, const Vector64& p, Int32 cpu_index);

	//----------------------------------------------------------------------------------------
	/// Called to let the video post create its own rays for the pixel at (@formatParam{x}, @formatParam{y}).\n
	/// @note ::VIDEOPOSTINFO::CUSTOMLENS needs to be returned by @ref GetRenderInfo to use this feature.
	/// @param[in,out] dst						The custom ray. Change the ray's parameters.
	/// @param[in] x									The X coordinate of the pixel.
	/// @param[in] y									The Y coordinate of the pixel.
	//----------------------------------------------------------------------------------------
	virtual void CreateRay(Ray* dst, Float x, Float y);

	//----------------------------------------------------------------------------------------
	/// Called to let the video post create its own extended ray for the pixel at (@formatParam{x}, @formatParam{y}).\n
	/// Improved version of @ref CreateRay giving additional information for motion blur and DOF that some custom lens plugins might want to use to correctly compute these effects.
	/// @note ::VIDEOPOSTINFO::CUSTOMLENS needs to be returned by GetRenderInfo() to use this feature.
	/// @param[in,out] dst						The custom ray. Change the ray's parameters.
	/// @param[in] x									The X coordinate of the pixel.
	/// @param[in] y									The Y coordinate of the pixel.
	/// @param[in] lensx							The lens X. (Value is in the range @em 0.0 to @em 1.0.)
	/// @param[in] lensy							The lens Y. (Value is in the range @em 0.0 to @em 1.0.)
	/// @param[in] time								The time. (Value is in the range @em 0.0 to @em 1.0.)
	//----------------------------------------------------------------------------------------
	virtual void CreateExtendedRay(Ray* dst, Float x, Float y, Float lensx, Float lensy, Float time);

	/// @}

	/// @name Stereo
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to return the number of stereoscopic editor cameras.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in] doc								The active document. @callerOwnsPointed{document}
	/// @param[in] bd									The active editor view. @callerOwnsPointed{view}
	/// @return												The number of stereoscopic cameras.
	//----------------------------------------------------------------------------------------
	virtual Int32 StereoGetCameraCountEditor(BaseVideoPost* node, BaseDocument* doc, BaseDraw* bd);

	//----------------------------------------------------------------------------------------
	/// Called to return the number of stereoscopic cameras used for rendering.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in] doc								The active document. @callerOwnsPointed{document}
	/// @param[in] rd									The current render settings. @callerOwnsPointed{render data}
	/// @return												The number of stereoscopic cameras.
	//----------------------------------------------------------------------------------------
	virtual Int32 StereoGetCameraCountRenderer(BaseVideoPost* node, BaseDocument* doc, RenderData* rd);

	//----------------------------------------------------------------------------------------
	/// Called to fill the information structure for each stereoscopic camera.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in] doc								The active document. @callerOwnsPointed{document}
	/// @param[in] bd									The active editor view. @callerOwnsPointed{view}
	/// @param[in] rd									The current render settings. @callerOwnsPointed{render data}
	/// @param[in] index							The index of the stereoscopic camera: @em 0 <= @formatParam{index} < StereoGetCameraCountRenderer()
	/// @param[out] info							Fill with the stereoscopic camera information.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool StereoGetCameraInfo(BaseVideoPost* node, BaseDocument* doc, BaseDraw* bd, RenderData* rd, Int32 index, StereoCameraInfo& info);

	//----------------------------------------------------------------------------------------
	/// Called to return a scene hook ID to store mouse coordinates used for drawing.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @return												The plugin ID of the scene hook.
	//----------------------------------------------------------------------------------------
	virtual Int32 StereoGetSceneHookID(BaseVideoPost* node);

	//----------------------------------------------------------------------------------------
	/// Called to merge the stereo images for rendering.\n
	/// @formatParam{settings} contains the stereoscopic render settings.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[out] dest							The destination bitmap to fill with the merged stereoscopic image.
	/// @param[in] source							The array of stereoscopic images.
	/// @param[in] cnt								The number of stereoscopic images in @formatParam{source}.
	/// @param[in] settings						The stereoscopic render settings container.
	/// @param[in] transform					The color space transformation: @enumerateEnum{COLORSPACETRANSFORMATION}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool StereoMergeImages(BaseVideoPost* node, BaseBitmap* dest, const BaseBitmap* const* source, Int32 cnt, const BaseContainer& settings, COLORSPACETRANSFORMATION transform);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Called to enable video post effects only for certain render engines or to allow only certain render settings tabs, e.g. if the video post is a render engine itself.\n
	/// For example to disable the video post effect for the Cineman renderer:
	/// @code
	/// Bool MyEffect::RenderEngineCheck(BaseVideoPost *node, Int32 id)
	/// {
	/// 	// The following render engines are not supported by this effect
	/// 	if (id==RDATA_RENDERENGINE_CINEMAN)
	/// 		return false;
	///
	/// 	return true;
	/// }
	///
	/// @endcode
	/// Here is how to disable some render settings tabs for a render engine plugin:
	/// @code
	/// Bool MyRenderer::RenderEngineCheck(BaseVideoPost *node, Int32 id)
	/// {
	/// 	switch (id)
	/// 	{
	/// 		case RENDERSETTING_STATICTAB_MULTIPASS:
	/// 		case RENDERSETTING_STATICTAB_ANTIALIASING:
	/// 		case RENDERSETTING_STATICTAB_OPTIONS:
	/// 		case RENDERSETTING_STATICTAB_STEREO:
	/// 			return false;
	/// 	}
	///
	/// 	return true;
	/// }
	/// @endcode
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in] id									The ID of the render engine or the render settings tab: @enumerateEnum{RENDERSETTING_STATICTAB}
	/// @return												@formatConstant{true} to enable the render engine or render settings tab passed to @formatParam{id}, @formatConstant{false} to disable it.
	//----------------------------------------------------------------------------------------
	virtual Bool RenderEngineCheck(BaseVideoPost* node, Int32 id);

	// set diffuse weight to control gi quality
	//----------------------------------------------------------------------------------------
	/// Called to send the current ray weight. The call is made right before each ComputeDiffuseGI().\n
	/// Each ray has now a weight associated with it, basically how important the ray is. All primary rays start with a weight of @em 1.0 and as they get "split" their weight is reduced.\n
	/// For example computing GI within blurry reflections would use much lower weight, assuming each blurry reflection uses @em 8 samples then the weight would be @em 1/8 so the GI would only use now @em 1/8 of the original rays.
	/// @note If the video post computes its own GI it should store and use that weight to improve/reduce the quality/time of the GI calculation.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in] cpu_index					The index of the current running thread (@em 0 to cpu_cnt-@em 1). The thread index is important as each thread might use different @formatParam{weight}.
	/// @param[in] weight							The current ray weight.
	//----------------------------------------------------------------------------------------
	virtual void SetDiffuseWeight(BaseVideoPost* node, Int32 cpu_index, Float weight);

	/// @name Team Render/NET
	/// @{

	//----------------------------------------------------------------------------------------
	/// Called to setup all the data for a NET frame.
	/// @note These methods are run on the server. The client does not receive any special calls and does not have any hookups but the NET context parameter is simply not @formatConstant{nullptr}.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in] doc								The active document. @callerOwnsPointed{document}
	/// @param[in] job								The render job. @callerOwnsPointed{render job}
	/// @param[in] assignedClients		The initial client count at the moment the frame is about to be rendered.
	/// @param[in] renderData					The NET render data. @callerOwnsPointed{render data}
	/// @param[in] frameBmp						The multipass bitmap where the resulting images are expected to be stored (important if the image is to be shown in the <i>Picture Viewer</i>).
	/// @param[in] bt									The render thread. @callerOwnsPointed{thread}
	/// @param[out] realdepth					Assign the real image depth.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool NetFrameInit(BaseVideoPost* node, BaseDocument* doc, RenderJob* job, Int32 assignedClients, const NetRenderData* renderData, MultipassBitmap* frameBmp, BaseThread* bt, Int32& realdepth);

	//----------------------------------------------------------------------------------------
	/// Called to clean up after rendering the NET frame has been done.
	/// @note These methods are run on the server. The client does not receive any special calls and does not have any hookups but the NET context parameter is simply not @formatConstant{nullptr}.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	//----------------------------------------------------------------------------------------
	virtual void NetFrameFree(BaseVideoPost* node);

	//----------------------------------------------------------------------------------------
	/// Called to send NET frame messages.
	/// @note These methods are run on the server. The client does not receive any special calls and does not have any hookups but the NET context parameter is simply not @formatConstant{nullptr}.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in] remoteUuid					The client uuid.
	/// @param[in] data								The data the client sends to the server.
	/// @param[in] result							An optional return value if the client is expecting a result.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool NetFrameMessage(BaseVideoPost* node, const C4DUuid& remoteUuid, const NetRenderBuffer& data, NetRenderBuffer* result);

	//----------------------------------------------------------------------------------------
	/// Called to to create specialized buffers e.g. for Normal and Position passes.\n
	/// @note These methods are run on the server. The client does not receive any special calls and does not have any hookups but the NET context parameter is simply not @formatConstant{nullptr}.
	/// If the video post has the flag @ref VIDEOPOSTINFO::NETCREATEBUFFER set @ref NetCreateBuffer will be called by the server.\n
	/// The plugin should then update the multipass buffer, and return the buffer @formatParam{id} and @formatParam{subid}.
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in] vps								The video post information. @callerOwnsPointed{video post struct}
	/// @param[in] x									The X position in the buffer that needs to be filled.
	/// @param[in] y									The Y position in the buffer that needs to be filled.
	/// @param[in] sizex							The width in the buffer that needs to be filled.
	/// @param[in] sizey							The height in the buffer that needs to be filled.
	/// @param[in] id									Assign the buffer ID.
	/// @param[in] subid							Assign the buffer sub-ID.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool NetCreateBuffer(BaseVideoPost* node, VideoPostStruct* vps, Int32 x, Int32 y, Int32 sizex, Int32 sizey, Int32& id, Int32& subid);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Called to return the motion blur information.
	/// @since R17.032
	/// @param[in] node								The BaseVideoPost connected with the VideoPostData instance. Equal to <tt>static_cast</tt><@ref BaseVideoPost*>Get(). Provided for speed and convenience. @cinemaOwnsPointed{video post}
	/// @param[in] info								The motion blur information.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	virtual Bool GetMotionInfo(BaseVideoPost* node, MotionInfo& info);
};

//----------------------------------------------------------------------------------------
/// Registers a video post plugin.
/// @param[in] id									@uniquePluginID
/// @param[in] str								The name of the plugin.\n
///																To affect the order that plugins are displayed in menus add <i>"#$n"</i> as a prefix to this name, where @em n is a number.\n
///																Lower numbers are displayed before higher numbers. If name is <i>"--"</i> it will show up as a menu separator.
/// @param[in] info								The video post plugin info flags: @enumerateEnum{PLUGINFLAG_VIDEOPOST} @enumerateEnum{PLUGINFLAG}
/// @param[in] g									The allocator for the video post plugin. This is a pointer to a function that creates a new instance of VideoPostData with NewObj().
/// @param[in] description				The name of the description resource file to use for the material plugin without @em .res extension, for example @em "VPeffectname".\n
///																The name has to be unique, i.e. @em "Tdisplay" cannot be used for 2 different descriptions. See Description Resource for more information.
/// @param[in] disklevel					The plugin level is similar to a version number. The default level is @em 0.\n
///																Increase this for new revisions of a plugin to allow for forward and backward compatibility.\n\n
///																As an example you may have updated a plugin. If you now need to write additional information for new settings or changed types for old settings increase the level.\n
///																During loading either a @em 0 is passed (if the file was written by the old plugin) or @em 1 (if the file was written by the new plugin). This allows to easily write/read new values.\n
///																For forward and backward compatibility to work any existing read order from a given level must not be changed. @C4D skips any new settings automatically if they have not been read.\n\n
///																@formatParam{disklevel} is only useful if variables are written/read in @ref NodeData::Write/@ref NodeData::Read.
/// @param[in] priority						The priority of the video post plugin. Higher priority values are called before lower values. The priorities of the internal video post processing are: @enumerateEnum{VPPRIORITY}\n
///																For example, to filter between glow and depth of field then priority has to be set between @ref VPPRIORITY_OBJECTGLOW and @ref VPPRIORITY_DEPTHOFFIELD.\n\n
///																Though all video post effects will be sorted by priority, an effect overriding for example VideoPostData::ExecutePixel will always be called before one using VideoPostData::ExecuteLine.\n
///																Also VideoPostData::ExecuteLine will always be called before @ref VIDEOPOSTCALL::INNER+@link BaseVideoPostStruct::open open@endlink==@formatConstant{false}.\n
///																This should be logical as VideoPostData::ExecutePixel will be instantly called after a sub-pixel has been calculated and VideoPostData::ExecuteLine instantly after a line has been calculated.
/// @return												@trueIfOtherwiseFalse{the video post plugin was registered}
//----------------------------------------------------------------------------------------
Bool RegisterVideoPostPlugin(Int32 id, const maxon::String& str, Int32 info, DataAllocator* g, const maxon::String& description, Int32 disklevel, Int32 priority);

#endif // C4D_VIDEOPOSTDATA_H__
