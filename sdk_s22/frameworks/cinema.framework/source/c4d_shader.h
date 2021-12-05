/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_SHADER_H__
#define C4D_SHADER_H__

#include "ge_math.h"
#include "c4d_file.h"
#include "c4d_basetime.h"
#include "ge_prepass.h" // Important


/// @addtogroup TEX
/// @ingroup group_enumeration
/// @{
#define TEX_TILE		0x01		///< Texture tile enabled.
#define TEX_MIRROR	0x02		///< Texture mirroring enabled.
#define TEX_ALPHA		0x04		///< Texture uses alpha channel (for use within channel shaders).
#define TEX_BUMP		0x08		///< Bump calculation.
/// @}

//----------------------------------------------------------------------------------------
/// Extracts the bump sample from @formatParam{texflag}.
/// @param[in] texflag						The texture flags.
/// @return												The bump sample:
///																- 0 Left.
///																- 1 Right.
///																- 2 Above.
///																- 3 Below.
//----------------------------------------------------------------------------------------
#define GET_TEX_BUMP_SAMPLE(texflag)	(((texflag) >> 4) & 3)

//----------------------------------------------------------------------------------------
/// Extracts the texture channel from @formatParam{texflag}.
/// @param[in] texflag						The texture flags.
/// @return												The texture channel: @enumerateEnum{CHANNEL}
//----------------------------------------------------------------------------------------
#define GET_TEX_CHANNEL(texflag)			(((texflag) >> 6) & 15)

//----------------------------------------------------------------------------------------
/// Inserts channel information into the texture flags.
/// @param[in] texflag						The texture flags.
/// @param[in] channel						The texture channel: @enumerateEnum{CHANNEL}
/// @return												The new texture flags.
//----------------------------------------------------------------------------------------
inline Int32 CALC_TEXINFO(Int32 texflag, Int32 channel) { return (texflag & ~0x3f0) | (channel << 6); }

//----------------------------------------------------------------------------------------
/// Inserts channel and bump sample information into the texture flags.
/// @param[in] texflag						The texture flags.
/// @param[in] channel						The texture channel: @enumerateEnum{CHANNEL}
/// @param[in] sample							The bump sample:
///																- 0 Left.
///																- 1 Right.
///																- 2 Above.
///																- 3 Below.
/// @return												The new texture flags.
//----------------------------------------------------------------------------------------
inline Int32 CALC_TEXINFO_BUMP(Int32 texflag, Int32 channel, Int32 sample) { return (texflag & ~0x3f0) | ((sample & 3) << 4) | (channel << 6); }

class CDialog;
class HyperFile;
class BaseChannel;
class BaseDocument;
class BaseObject;
class BaseTag;
class BaseDraw;
class BaseDrawHelp;
class BaseThread;
class Filename;
class String;
class BaseView;
class BaseContainer;
class Raytracer;
class RootTextureString;
struct TexEntry;
struct RayObj;
struct RayLight;
struct RayObject;
struct VolumeData;

/// The maximum number of channels in a @C4D material.
#define MAX_MATERIALCHANNELS 14

/// @addtogroup CHANNEL
/// @ingroup group_enumeration
/// @{
#define CHANNEL_COLOR					0				///< The color channel of a material.
#define CHANNEL_LUMINANCE			1				///< The luminance channel of a material.
#define CHANNEL_TRANSPARENCY	2				///< The transparency channel of a material.
#define CHANNEL_REFLECTION		3				///< The reflection channel of a material.
#define CHANNEL_ENVIRONMENT		4				///< The environment channel of a material.
#define CHANNEL_FOG						5				///< The fog channel of the material.
#define CHANNEL_BUMP					6				///< The bump channel of the material.
#define CHANNEL_ALPHA					7				///< The alpha channel of the material.
#define CHANNEL_SPECULAR			8				///< The specular channel of the material.
#define CHANNEL_SPECULARCOLOR	9				///< The specular color channel of the material.
#define CHANNEL_GLOW					10			///< The glow channel of the material.
#define CHANNEL_DISPLACEMENT	11			///< The displacement channel of the material.
#define CHANNEL_DIFFUSION			12			///< The diffusion channel of the material.
#define CHANNEL_NORMAL				13			///< The normal channel of the material.
#define CHANNEL_ANY						-1			///< An unlabeled plugin channel.
/// @}

/// @addtogroup BASECHANNEL
/// @ingroup group_containerid
/// @{
#define BASECHANNEL_COLOR_EX				1000			///< ::Vector. @markDeprecated
#define BASECHANNEL_BRIGHTNESS_EX		1001			///< ::Float. @markDeprecated
#define BASECHANNEL_MIXMODE_EX			1006			///< ::Int32. @markDeprecated
#define BASECHANNEL_MIXSTRENGTH_EX	1007			///< ::Float. @markDeprecated

#define BASECHANNEL_TEXTURE					1002			///< String. The texture for this channel.
#define BASECHANNEL_BLUR_OFFSET			1003			///< ::Float. The MIP blur offset for this channel.
#define BASECHANNEL_BLUR_STRENGTH		1004			///< ::Float. The MIP blur strength for this channel.
#define BASECHANNEL_INTERPOLATION		1005			///< ::Int32. The interpolation for this channel.
#define BASECHANNEL_TIME_FROM				1008			///< ::Int32. Movie from frame.
#define BASECHANNEL_TIME_TO					1009			///< ::Int32. Movie to frame.
#define BASECHANNEL_TIME_FPS				1010			///< ::Int32. Movie frame rate.
#define BASECHANNEL_TIME_MODE				1011			///< ::Int32. Sequence mode (see @C4D dialog).
#define BASECHANNEL_TIME_TIMING			1012			///< ::Int32. Sequence timing (see @C4D dialog).
#define BASECHANNEL_TIME_START			1013			///< BaseTime. Sequence start.
#define BASECHANNEL_TIME_END				1014			///< BaseTime. Sequence end.
#define BASECHANNEL_TIME_LOOPS			1015			///< ::Int32. Sequence loops.
#define BASECHANNEL_SHADERID				1016			///< ::Int32. The unique ID of the shader for this channel.
#define BASECHANNEL_SUGGESTEDFOLDER	1017			///< BaseTime. Suggested folder. See GenerateTexturePath().
/// @}

/// @addtogroup INITRENDERFLAG
/// @ingroup group_enumeration
/// @{
enum class INITRENDERFLAG
{
	NONE							= 0,						///< No flags.
	TEXTURES					= (1 << 0),			///< Use textures.
	PAINTERNOMIP			= (1 << 1),			///< Disable MIP for painting.
	NOMIP							= (1 << 2),			///< Disable MIP.
	PREVIEWRENDER			= (1 << 3),			///< Preview render.\n
																		///< @note	The container of the preview rendered document contains the path to the original document in ID ::DOCUMENT_SECONDARYPATH:
																		/// @code
																		/// if (irs.flags & INITRENDERFLAG::PREVIEWRENDER)
																		/// {
																		/// 	if (irs.doc && irs.doc->GetDataInstance())
																		/// 	{
																		/// 		const Filename originalPath = irs.doc->GetDataInstance()->GetFilename(DOCUMENT_SECONDARYPATH);
																		/// 	}
																		/// }
																		/// @endcode
	IRR								= (1 << 4)			///< Interactive region render.
} MAXON_ENUM_FLAGS(INITRENDERFLAG);
/// @}

//----------------------------------------------------------------------------------------
/// Transforms a color from one color profile to another.
/// @param[in] input							The color to transform.
/// @param[in] colortransformation	The color space transformation: @enumerateEnum{COLORSPACETRANSFORMATION}
/// @return												The transformed color.
//----------------------------------------------------------------------------------------
extern Vector TransformColor(const Vector& input, COLORSPACETRANSFORMATION colortransformation);

//----------------------------------------------------------------------------------------
/// Transforms a color from one color profile to another.
/// @param[in] input							The color to transform.
/// @param[in] colortransformation	The color space transformation: @enumerateEnum{COLORSPACETRANSFORMATION}
/// @return												The transformed color.
//----------------------------------------------------------------------------------------
extern maxon::Color TransformColor(const maxon::Color& input, COLORSPACETRANSFORMATION colortransformation);

//----------------------------------------------------------------------------------------
/// The InitRenderStruct is usually filled by @C4D and then passed to the shader or channel @c InitRender().\n
/// However to evaluate a BaseChannel for own purposes then create an InitRenderStruct on the stack.
//----------------------------------------------------------------------------------------
struct InitRenderStruct
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	InitRenderStruct()
	{
		version = 0;
		fps = 30;
		docpath = Filename();
		errorlist = nullptr;
		matname = nullptr;
		vd = nullptr;
		doc = nullptr;
		thread = nullptr;
		flags = INITRENDERFLAG::TEXTURES;
		linear_workflow = false;
		document_colorprofile = DOCUMENT_COLORPROFILE_SRGB;
	}

	//----------------------------------------------------------------------------------------
	/// Creates the structure accordingly to the passed document.
	/// @param[in] t_doc							The document to initialize the structure. @callerOwnsPointed{document}
	//----------------------------------------------------------------------------------------
	explicit InitRenderStruct(BaseDocument* t_doc) { Init(t_doc); }

	//----------------------------------------------------------------------------------------
	/// Initializes the structure accordingly to the passed document.
	/// @param[in] t_doc							The document to initialize the structure. @callerOwnsPointed{document}
	//----------------------------------------------------------------------------------------
	void Init(BaseDocument* t_doc);

	Int32								version;										///< The version of @C4D.
	BaseTime						time;												///< The current time.
	Int32								fps;												///< The framerate.
	Filename						docpath;										///< The path for the document.
	String*							matname;										///< The material name.
	RootTextureString*	errorlist;									///< A private error list. Can be @formatConstant{nullptr}, always check.
	VolumeData*					vd;													///< The volume data. Can be @formatConstant{nullptr}, always check.\n
																									///< @note	When initializing an InitRenderStruct, if the following line is missing, @C4D assumes that there will be only one render thread.\n
																									///<				(Without VolumeData no multi-threaded calculation can be done.). Access to VolumeData::Sample() will then crash or overwrite memory.\n
																									///<				Here is a safe initialization of @link vd@endlink:
																									///<				@code
																									///					irs.vd = render->GetInitialVolumeData(0);
																									///					@endcode
																									///< @warning	To accurately rebuild a host environment for shader, material or channel sampling all members that VolumeData offers need to be filled.\n
																									///<					Any pointer that is not initialized can cause a crash. Members like BaseVolumeData::recursion_data, BaseVolumeData::multipass and BaseVolumeData::intersection can be set to @formatConstant{nullptr}.
	BaseDocument*				doc;												///< The document to render. Can be @formatConstant{nullptr}, always check.
	BaseThread*					thread;											///< The current thread or @formatConstant{nullptr} for the main @C4D thread.
	INITRENDERFLAG			flags;											///< The flags; @enumerateEnum{INITRENDERFLAG}

	Bool								linear_workflow;						///< Linear workflow enabled/disabled.
	Int32								document_colorprofile;			///< The document color profile: @enumerateEnum{DOCUMENT_COLORPROFILE}

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of render threads.
	/// @return												The number of render threads.
	//----------------------------------------------------------------------------------------
	Int32 GetThreadCount() const;

	//----------------------------------------------------------------------------------------
	/// If linear workflow is enabled the passed color is transformed into the color profile specified by document_colorprofile.
	/// @param[in] input							The color to transform.
	/// @return												The transformed color.
	//----------------------------------------------------------------------------------------
	Vector TransformColor(const Vector& input) const
	{
		if (document_colorprofile == DOCUMENT_COLORPROFILE_SRGB && linear_workflow)
			return ::TransformColor(input, COLORSPACETRANSFORMATION::SRGB_TO_LINEAR);
		else if (document_colorprofile == DOCUMENT_COLORPROFILE_LINEAR && !linear_workflow)
			return ::TransformColor(input, COLORSPACETRANSFORMATION::LINEAR_TO_SRGB);

		return input;
	}
};

//----------------------------------------------------------------------------------------
/// Illumination information for materials.
//----------------------------------------------------------------------------------------
struct RayIllumination
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	RayIllumination()
	{
		gi_receive_strength			= 0.0;
		gi_generate_strength		= 0.0;
		gi_saturation						= 0.0;
		gi_generate_saturation	= 0.0;
		cs_receive_strength			= 0.0;
		cs_generate_strength		= 0.0;
		cs_sampleradius					= 0.0;
		cs_accuracy							= NOTOK;
		trans_dispersion				=	0.0;
		trans_accuracy					= 0.0;
		trans_minsamples				= 1;
		trans_maxsamples				= 1;
		refl_dispersion					= 0.0;
		refl_accuracy						= 0.0;
		refl_minsamples					= 1;
		refl_maxsamples					= 1;
	}

	Float	gi_receive_strength,				///< GI receive strength.
				gi_generate_strength,				///< GI generate strength.
				gi_saturation,							///< GI saturation.
				gi_generate_saturation;			///< GI generate saturation.

	Float cs_receive_strength,				///< Caustics strength.
				cs_generate_strength;				///< Caustics generate strength.
	Float cs_sampleradius;						///< Caustics sample radius.
	Int32 cs_accuracy;								///< Caustics accuracy.

	Float trans_dispersion,						///< Transparency dispersion.
				trans_accuracy;							///< Transparency accuracy.
	Int32 trans_minsamples,						///< Transparency minimum number of samples.
				trans_maxsamples;						///< Transparency maximum number of samples.

	Float refl_dispersion,						///< Reflection dispersion.
				refl_accuracy;							///< Reflection accuracy.
	Int32 refl_minsamples,						///< Reflection minimum number of samples.
				refl_maxsamples;						///< Reflection maximum number of samples.
};


/// @addtogroup SIDE
/// @ingroup group_enumeration
/// @{
/// See @C4D manual for more information
#define SIDE_FRONT_AND_BACK	0			///< Decal setting front and back.
#define SIDE_FRONT					1			///< Decal setting front
#define SIDE_BACK						2			///< Decal setting back.
/// @}

//----------------------------------------------------------------------------------------
/// Texture information.
/// @addAllocFreeAutoAllocNote
///
/// The @ref ox, @ref oy and @ref m values may differ from the values specified in the dialog, these are a precalculated raytracer representation. To better understand the meaning of those values please print this routine (it is the projection routine in source code):
/// @code
/// Bool ShdProjectPoint(VolumeData *sd, TexData *tdp, Int32 lhit, const Vector &p, const Vector &n, Vector *uv)
/// {
/// 	Float lenxinv=0.0,lenyinv=0.0;
/// 	if (tdp->lenx!=0.0) lenxinv = 1.0/tdp->lenx;
/// 	if (tdp->leny!=0.0) lenyinv = 1.0/tdp->leny;
///
/// 	switch (tdp->proj)
/// 	{
/// 		case P_VOLUMESHADER:
/// 		{
/// 			*uv = p * tdp->im;
/// 			return true;
/// 		}
///
/// 		case P_SPHERICAL: default:
/// 		{
/// 			Vector d = p * tdp->im;
/// 			Float sq = Sqrt(d.x*d.x + d.z*d.z);
/// 			if (sq==0.0)
/// 			{
/// 				uv->x = 0.0;
/// 				if (d.y>0.0)
/// 					uv->y = +0.5;
/// 				else
/// 					uv->y = -0.5;
/// 			}
/// 			else
/// 			{
/// 				uv->x = ACos(d.x/sq)/PI2;
/// 				if (d.z<0.0) uv->x = 1.0-uv->x;
///
/// 				uv->x -= tdp->ox;
/// 				if (tdp->lenx>0.0 && uv->x<0.0)
/// 					uv->x += 1.0;
/// 				else if (tdp->lenx<0.0 && uv->x>0.0)
/// 					uv->x -= 1.0;
/// 				uv->x *= lenxinv;
/// 				uv->y = ATan(d.y/sq)/PI;
/// 			}
/// 			uv->y = -(uv->y+tdp->oy)*lenyinv;
/// 			break;
/// 		}
///
/// 		case P_SHRINKWRAP:
/// 		{
/// 			Vector d = p * tdp->im;
/// 			Float   sn,cs,sq = Sqrt(d.x*d.x + d.z*d.z);
///
/// 			if (sq==0.0)
/// 			{
/// 				uv->x = 0.0;
/// 				if (d.y>0.0)
/// 					uv->y = 0.0;
/// 				else
/// 					uv->y = 1.0;
/// 			}
/// 			else
/// 			{
/// 				uv->x = ACos(d.x/sq)/PI2;
/// 				if (d.z<0.0) uv->x = 1.0-uv->x;
/// 				uv->y = 0.5-ATan(d.y/sq)/PI;
/// 			}
///
/// 			SinCos(uv->x*PI2,sn,cs);
///
/// 			uv->x = (0.5 + 0.5*cs*uv->y - tdp->ox)*lenxinv;
/// 			uv->y = (0.5 + 0.5*sn*uv->y - tdp->oy)*lenyinv;
/// 			break;
/// 		}
///
/// 		case P_CYLINDRICAL:
/// 		{
/// 			Vector d = p * tdp->im;
/// 			Float sq = Sqrt(d.x*d.x + d.z*d.z);
/// 			if (sq==0.0)
/// 				uv->x = 0.0;
/// 			else
/// 			{
/// 				uv->x = ACos(d.x/sq)/PI2;
/// 				if (d.z<0.0) uv->x = 1.0-uv->x;
///
/// 				uv->x -= tdp->ox;
/// 				if (tdp->lenx>0.0 && uv->x<0.0)
/// 					uv->x += 1.0;
/// 				else if (tdp->lenx<0.0 && uv->x>0.0)
/// 					uv->x -= 1.0;
/// 				uv->x *= lenxinv;
/// 			}
/// 			uv->y = -(d.y*0.5+tdp->oy)*lenyinv;
/// 			break;
/// 		}
///
/// 		case P_FLAT: case P_SPATIAL:
/// 		{
/// 			Vector d = p * tdp->im;
/// 			uv->x =  (d.x*0.5-tdp->ox)*lenxinv;
/// 			uv->y = -(d.y*0.5+tdp->oy)*lenyinv;
/// 			break;
/// 		}
///
/// 		case P_CUBIC:
/// 		{
/// 			Vector d = p * tdp->im;
/// 			Vector v = n ^ tdp->im;
/// 			Int32   dir;
///
/// 			if (Abs(v.x)>Abs(v.y))
/// 			{
/// 				if (Abs(v.x)>Abs(v.z))
/// 					dir = 0;
/// 				else
/// 					dir = 2;
/// 			}
/// 			else
/// 			{
/// 				if (Abs(v.y)>Abs(v.z))
/// 					dir = 1;
/// 				else
/// 					dir = 2;
/// 			}
///
/// 			switch (dir)
/// 			{
/// 				case 0: // x axis
/// 				{
/// 					if (v.x<0.0)
/// 						uv->x = (-d.z*0.5-tdp->ox)*lenxinv;
/// 					else
/// 						uv->x = ( d.z*0.5-tdp->ox)*lenxinv;
///
/// 					uv->y = -(d.y*0.5+tdp->oy)*lenyinv;
/// 					break;
/// 				}
///
/// 				case 1:  // y axis
/// 				{
/// 					if (v.y<0.0)
/// 						uv->y = ( d.z*0.5-tdp->oy)*lenyinv;
/// 					else
/// 						uv->y = (-d.z*0.5-tdp->oy)*lenyinv;
///
/// 					uv->x = (d.x*0.5-tdp->ox)*lenxinv;
/// 					break;
/// 				}
///
/// 				case 2: // z axis
/// 				{
/// 					if (v.z<0.0)
/// 						uv->x = ( d.x*0.5-tdp->ox)*lenxinv;
/// 					else
/// 						uv->x = (-d.x*0.5-tdp->ox)*lenxinv;
///
/// 					uv->y = -(d.y*0.5+tdp->oy)*lenyinv;
/// 					break;
/// 				}
/// 			}
///
/// 			break;
/// 		}
///
/// 		case P_FRONTAL:
/// 		{
/// 			RayParameter *param=sd->GetRayParameter();
///
/// 			Float ox=0.0,oy=0.0,ax=param->xres,ay=param->yres;
/// 			Int32 curr_x,curr_y,scl;
/// 			sd->GetXY(&curr_x,&curr_y,&scl);
/// 			uv->x = ((Float(curr_x)/Float(scl)-ox)/ax - tdp->ox)*lenxinv;
/// 			uv->y = ((Float(curr_y)/Float(scl)-ox)/ay - tdp->oy)*lenyinv;
/// 			break;
/// 		}
///
/// 		case P_UVW:
/// 		{
/// 			RayObject *op=sd->ID_to_Obj(lhit,nullptr);
/// 			if (op && tdp->uvwind<op->uvwcnt && op->uvwadr[tdp->uvwind])
/// 				*uv=sd->GetPointUVW(tdp,lhit,p);
/// 			else
/// 				uv->x = uv->y = 0.0;
///
/// 			break;
/// 		}
/// 	}
///
/// 	if (tdp->texflag&TEX_TILE)
/// 		return true;
/// 	else
/// 		return uv->x>=0.0 && uv->x<=1.0 && uv->y>=0.0 && uv->y<=1.0;
/// }
/// @endcode
//----------------------------------------------------------------------------------------
struct TexData
{
private:
	TexData();
	~TexData();

public:
	Matrix			m,								///< The texture projection matrix.
																///< @note This actual value may differ from those specified in the dialog, these are a precalculated raytracer representation.
							im;								///< The inverse of the texture projection matrix.
	Char				texflag;					///< The texture flags: @enumerateEnum{TEX}
	Char				additive,					///< @formatConstant{true} to mix with other textures.
							proj,							///< The texture projection: @enumerateEnum{TextureProjectionTypes}
							side;							///< The side: @enumerateEnum{SIDE}
	Int32				restrict;					///< This is either @em 0 for no restriction or the index to a restriction in a RayObject\n
																///< To check if global polygon @c id applies to TexData @c tex using VolumeData @c sd use the following:
																/// @code
																/// if (tex->restrict)
																/// {
																/// 	if (!sd->op || sd->op->type!=O_POLYGON || tex->restrict>=sd->op->rscnt || !sd->op->rsadr[tex->restrict])
																/// 		return false;
																///
																/// 	Int32 num;
																/// 	sd->ID_to_Obj(id,&num);
																///
																/// 	if (!(sd->op->rsadr[tex->restrict][num>>5]&(1<<(num&31))))
																/// 		return false;
																/// }
																/// return true;
																/// @endcode
	Float				ox,								///< The X offset of the texture.
																///< @note This actual value may differ from the one specified in the dialog, these are a precalculated raytracer representation.
							oy,								///< The Y offset of the texture.
																///< @note This actual value may differ from the one specified in the dialog, these are a precalculated raytracer representation.
							lenx,							///< The X length of the texture.
							leny,							///< The Y length of the texture.
							repetitionx,			///< The repetition of U tiling.
							repetitiony;			///< The repetition of V tiling.
	GeListNode*	mp;								///< The material.
																///< @note Make sure to cast this to the right material type before using it.
	Int32				uvwind;						///< The uvw index, access is through VolumeData::GetUVW().
	BaseView*		camera;						///< The current view.
	Char				uvbump;						///< The direct boolean representation of @ref TEXTURETAG_UVBUMP.
	BaseTag*		link;							///< The originating texture tag.
	Float				invLenx,					///< The inverted X length of the texture. @since R19.SP2
							invLeny;					///< The inverted Y length of the texture. @since R19.SP2
	Bool				parallaxUVW;			///< @trueIfOtherwiseFalse{the UVW coordinates are changed by Parallax Mapping} @since R19.SP2

	//----------------------------------------------------------------------------------------
	/// @allocatesA{texture data}
	/// @return												@allocReturn{texture data}
	//----------------------------------------------------------------------------------------
	static TexData* Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{texture data}
	/// @param[in] td									@theToDestruct{texture data}
	//----------------------------------------------------------------------------------------
	static void Free(TexData*& td);

	//----------------------------------------------------------------------------------------
	/// Initializes the structure.
	//----------------------------------------------------------------------------------------
	void Init(void);
};

//----------------------------------------------------------------------------------------
///
//----------------------------------------------------------------------------------------
struct Ray
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	Ray() : p(DC), v(DC) { ior = 1.0; }

	Vector64	p,							///< [READ WRITE] The rays position.
						v;							///< [READ WRITE] The rays direction vector.
	Float			ior;						///< [READ WRITE] The current index of refraction.
	Vector		pp[3];					///< [READ WRITE] 3 additional ray points for MIP-Mapping.
														///< @note @image html ray_mip.png
														///< @c P is the pixel origin or where the ray was generated.\n
														///< 0/1/2 are indices into the @ref pp and @ref vv arrays.\n
														///< The square is one screen pixel wide in X and Y direction.
	Vector		vv[3];					///< [READ WRITE] 3 additional ray vectors for MIP-Mapping.
														///< @note @image html ray_mip.png
														///< @c P is the pixel origin or where the ray was generated.\n
														///< 0/1/2 are indices into the @ref pp and @ref vv arrays.\n
														///< The square is one screen pixel wide in X and Y direction.

	Vector		transport;			///< [READ ONLY] The current ray intensity (for special shadow calculation). A ray starts with intensity @em 1.0.
};

/// @markPrivate
#define L_SPLIT_BIT	(1 << 31)

//----------------------------------------------------------------------------------------
/// The class RayHitID replaces the old ::Int32 value that stored information of an object/polygon.\n
/// It conveniently allows to set objects with a polygon index, or read this information.\n
/// @link SetSecond()@endlink/@link GetSecond()@endlink determine for a non-coplanar quadrangle which part of the quadrangle was stored (A-B-C or A-C-D). In case of a coplanar quadrangle "second" is not set.\n
/// @note	- Instead of <tt>if (lhit==0)</tt> write <tt>if (lhit.IsPopulated())</tt>
///				- Instead of <tt>lhit=0</tt> write <tt>lhit.Clear()</tt>
//----------------------------------------------------------------------------------------
struct RayHitID
{
private:
	Int32 rayobject;
	Int32 polygon;

public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	RayHitID() { rayobject = polygon = 0; }

	//----------------------------------------------------------------------------------------
	/// Creates an uninitialized ray hit structure.
	/// @param[in] DC									Dummy argument. Pass @ref DC.
	//----------------------------------------------------------------------------------------
	explicit RayHitID(_DONTCONSTRUCT DC) { }

	//----------------------------------------------------------------------------------------
	/// Copy constructor. Creates a new RayHitID structure with all of the values from the other one.
	/// @param[in] other							The source ray hit structure.
	//----------------------------------------------------------------------------------------
	RayHitID(const RayHitID& other) { rayobject = other.rayobject; polygon = other.polygon; }

	//----------------------------------------------------------------------------------------
	/// Creates a ray hit structure based on the passed parameters.
	/// @param[in] t_rayobject				The ray object.
	/// @param[in] t_polygon					The polygon index.
	/// @param[in] second							@formatConstant{true} for second part (A-C-D) of a quadrangle, @formatConstant{false} for the first part (A-B-C).
	//----------------------------------------------------------------------------------------
	RayHitID(const RayObject* t_rayobject, Int32 t_polygon, Bool second) { Set(t_rayobject, t_polygon, second); }

	//----------------------------------------------------------------------------------------
	/// Checks if 2 ray hit structures are equal.
	/// @param[in] snd								The ray hit structure to compare with.
	/// @return												@trueIfOtherwiseFalse{the ray hit structures are equal}
	//----------------------------------------------------------------------------------------
	inline Bool IsEqual(const RayHitID& snd) const { return rayobject == snd.rayobject && polygon == snd.polygon; }

	//----------------------------------------------------------------------------------------
	/// Checks if the ray hit identity is zero.
	/// @return												@trueIfOtherwiseFalse{he ray hit identity is zero}
	//----------------------------------------------------------------------------------------
	inline Bool IsPopulated() const { return rayobject != 0; }

	//----------------------------------------------------------------------------------------
	/// Clears the ray hit identity.
	//----------------------------------------------------------------------------------------
	inline void Clear() { rayobject = polygon = 0; }

#ifdef __API_INTERN__
	void Set(const RayObject* t_rayobject, Int32 t_polygon, Bool second);
	RayObj* GetObject(const Raytracer* rt) const;
	inline Int32 GetPolygonPlus() const { return (rayobject & L_SPLIT_BIT) | polygon; }
#else
	//----------------------------------------------------------------------------------------
	/// Setups the ray hit structure.
	/// @param[in] t_rayobject				The ray object.
	/// @param[in] t_polygon					The polygon index.
	/// @param[in] second							@formatConstant{true} for second part (A-C-D) of a quadrangle, @formatConstant{false} for the first part (A-B-C).
	//----------------------------------------------------------------------------------------
	inline void Set(const RayObject* t_rayobject, Int32 t_polygon, Bool second)
	{
		rayobject = C4DOS.Sh->Obj_to_Num(nullptr, t_rayobject) + 1;
		polygon = t_polygon;
		if (second)
			rayobject |= L_SPLIT_BIT;
	}

	//----------------------------------------------------------------------------------------
	/// Retrieves the ray object of the ray hit identity for a volume data.
	/// @param[in] vd									The volume data.
	/// @return												The ray object, or @formatConstant{nullptr} if not available.
	//----------------------------------------------------------------------------------------
	inline const RayObject* GetObject(const VolumeData* vd) const
	{
		return C4DOS.Sh->ID_to_Obj(vd, *this);
	}
#endif

	//----------------------------------------------------------------------------------------
	/// Gets the polygon index.
	/// @return												The polygon index.
	//----------------------------------------------------------------------------------------
	inline Int32 GetPolygon() const { return polygon; }

	//----------------------------------------------------------------------------------------
	/// Checks if the polygon is the second part of a quadrangle.
	/// @return												@formatConstant{true} if the polygon is a second part of a quadrangle (A-C-D), @formatConstant{false} for the first part (A-B-C).
	//----------------------------------------------------------------------------------------
	inline Bool GetSecond() const { return (rayobject & L_SPLIT_BIT) != 0; }

	//----------------------------------------------------------------------------------------
	/// Sets the polygon to be a first part of a quadrangle (A-B-C).
	//----------------------------------------------------------------------------------------
	inline void ClearSecond() { rayobject &= ~L_SPLIT_BIT; }

	//----------------------------------------------------------------------------------------
	/// Set the polygon to be a second part of a quadrangle (A-C-D).
	//----------------------------------------------------------------------------------------
	inline void SetSecond() { rayobject |= L_SPLIT_BIT; }

	//----------------------------------------------------------------------------------------
	/// Sets the private data.
	/// @param[in] t_rayobject				The ray object index.
	/// @param[in] t_polygon					The polygon index.
	//----------------------------------------------------------------------------------------
	inline void SetPrivateData(Int32 t_rayobject, Int32 t_polygon) { rayobject = t_rayobject; polygon = t_polygon; }

	//----------------------------------------------------------------------------------------
	/// Gets the private data.
	/// @param[out] t_rayobject				Assigned the ray object index.
	/// @param[out] t_polygon					Assigned the polygon index.
	//----------------------------------------------------------------------------------------
	inline void GetPrivateData(Int32* t_rayobject, Int32* t_polygon) const { *t_rayobject = rayobject; *t_polygon = polygon; }
};

//----------------------------------------------------------------------------------------
/// A structure for surface intersections.
//----------------------------------------------------------------------------------------
struct SurfaceIntersection
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	SurfaceIntersection() { sid = 0; par_u = par_v = 0.0; }

	//----------------------------------------------------------------------------------------
	/// Creates an uninitialized surface intersection structure.
	/// @param[in] dc									Dummy argument. Pass @ref DC.
	//----------------------------------------------------------------------------------------
	explicit SurfaceIntersection(_DONTCONSTRUCT dc) : id(DC), p(DC), n(DC) { }

#ifdef __API_INTERN__
	const RayObj*			op;		///< Intersected object.
#else
	const RayObject*	op;		///< Intersected object.
#endif

	RayHitID	id;				///< Ray hit identity.
	Vector64	p,				///< Point.
						n;				///< Normal.
	Int32			sid;			///< Sub-ID (only used for SPD).
	Float			par_u,		///< Barycentric U coordinate (only used for SPD).
						par_v;		///< Barycentric V coordinate (only used for SPD).
};

class VPBitmap;

//----------------------------------------------------------------------------------------
/// These values have to be filled by custom illumination models:
/// - Standard: @ref diffuse, @ref specular, @ref shadow
/// - VP: @ref vp_diffuse, @ref vp_specular, @ref vp_shadow, @ref vp_illumination (later @ref vp_radiosity and @ref vp_caustics)
/// These values have to be filled/processed by shaders:
/// - Filled: @ref vp_mat_color, @ref vp_mat_luminance, @ref vp_mat_transparency, @ref vp_mat_reflection
///							@ref vp_mat_environment, @ref vp_mat_specularcolor
///							@ref vp_mat_specular, @ref vp_mat_diffusion
/// - Processed: @ref diffuse, @ref specular, @ref vp_ambient
//----------------------------------------------------------------------------------------
struct Multipass
{
	VPBitmap**	bmp;												///< @markInternal An array of @@ref cnt VPBitmaps.
	Int32*			ind;												///< The index into the components for all layers.\n
																					///< @b Examples:
																					///< - Standard rendering:
																					/// @code
																					/// cnt == 1
																					/// cmp == 4 (R,G,B, Alpha)
																					/// ind[0] = 0
																					/// result[0..3] : R,G,B, Alpha component
																					/// @endcode
																					///< - Multilayer rendering:
																					/// @code
																					/// cnt == 3
																					/// cmp == 8 (R,G,B, Alpha, Diffuse R, Diffuse G, Diffuse B, Depth Channel)
																					/// ind[0] = 0
																					/// ind[1] = 4
																					/// ind[2] = 7
																					/// result[0..7] : R,G,B, Alpha, Diffuse R, Diffuse G, Diffuse B, Depth component
																					/// @endcode
	Float*			result;											///< The result of all components.
	Int32				cnt,												///< The number of layers, for instance @em 1 for the main RGB layer.
							cmp;												///< The number of components.

	Vector**		diffuse;										///< The diffuse components.
	Int32				diffuse_cnt;								///< The number of diffuse components.

	Vector**		specular;										///< The specular components.
	Int32				specular_cnt;								///< The number of specular components.

	Vector**		shadow;											///< The shadow components.
	Int32				shadow_cnt;									///< The number of shadow components.

	RayLight**	light;											///< The array of the lights that create special light buffers. For example, if you render out a diffuse/specular pass for each light source all those lights will be listed here.
	Int32				light_cnt;									///< The number of lights.

	Float**			ochannel;										///< The object buffers, filled by @C4D. An array of @ref ochannel_cnt Float pointers.\n
																					///< Each Float* directly points to the value of the object buffer.
	Int32*			ochannelid;									///< The channel ID of the object buffer.
	Int32				ochannel_cnt;								///< The number of object buffers.

	Vector*			vp_ambient,									///< The attenuated ambient from all lights plus self illuminating part for the current pixel.
							*vp_diffuse,								///< The diffuse illumination for the current pixel.
							*vp_specular,								///< The specular illumination for the current pixel.
							*vp_shadow,									///< The shadow component for the current pixel.
							*vp_reflection,							///< The reflection component for the current pixel.
							*vp_transparency;						///< The resulting transparency for the current pixel.
	Vector*			vp_radiosity,								///< Currently a custom model cannot access radiosity/caustics so it do not need to be filled.
							*vp_caustics,								///< Currently a custom model cannot access radiosity/caustics so it do not need to be filled.
							*vp_illumination;						///< The diffuse and ambient components of the light.
	Vector*			vp_mat_color,								///< The diffuse illumination attenuation.
							*vp_mat_luminance,					///< Self illuminating part (luminance channel in the @C4D material).
							*vp_mat_transparency,				///< The material transparency attenuation.
							*vp_mat_reflection;					///< The reflection attenuation (reflection channel in the @C4D material).
	Vector*			vp_mat_environment,					///< The material environment attenuation.
							*vp_mat_specularcolor,			///< The material specular color attenuation.
							*vp_atmosphere;							///< The atmosphere component (fog and volumetric effects).
	Float*			vp_depth,										///< The depth value for the current pixel.
							*vp_mat_specular,						///< The material specular attenuation.
							*vp_mat_diffusion,					///< The material diffusion attenuation.
							*vp_atmosphere_mul;					///< The atmosphere multiplier.
	Vector*			vp_ambientocclusion,				///< The ambient occlusion.
							*vp_mat_uv,									///< The UV layer.
							*vp_mat_normal,							///< The normal layer.
							*vp_motionvector;						///< The motion vector.

	Vector**		rchannel,										///< The reflection buffer. @since R16
							**schannel;									///< The specular buffer. @since R16
	Int32				rchannel_cnt,								///< The number of reflections in @ref rchannel. @since R16
							schannel_cnt;								///< The number of specular values in @ref schannel. @since R16

	Vector*			vp_direct_diffuse;					///< Direct diffuse from Reflectance Channel. @since R20
	Vector*			vp_indirect_diffuse;				///< Indirect diffuse from Reflectance Channel. @since R20
	Vector*			vp_direct_specular;					///< Direct specular from Reflectance Channel. @since R20
	Vector*			vp_indirect_specular;				///< Indirect specular from Reflectance Channel. @since R20
	Vector*			vp_reflectance_albedo;			///< Reflectance Channel Diffuse Albedo. @since R21

	Vector**		aov_channel;								///< The object buffers, filled by @C4D. An array of @ref aov_channel_cnt Vector pointers. @since R21
																					///< Each Vector* directly points to the value of the object buffer. @since R21
	Int32*			aov_channel_id;							///< The channel ID of the AOV. @since R21
	Int32				aov_channel_cnt;						///< The number of AOVs. @since R21
};


struct BaseVolumeData
{
protected:
	BaseVolumeData();

public:
	Int32				version;								///< [READ ONLY] The version number of the structure.
	Int32				fps;										///< [READ ONLY] The frames per second.
	Vector			ambient;								///< [READ ONLY] The global ambient component.
	Float				time;										///< [READ ONLY] The current time in seconds.

	Vector			col;										///< [READ WRITE] Set the calculated color within MaterialData::CalcSurface() and MaterialData::CalcVolumetric().
	Vector			trans;									///< [READ WRITE] Set the calculated transparency within MaterialData::CalcSurface(), MaterialData::CalcTransparency() and MaterialData::CalcVolumetric().
	Vector			refl;										///< [READ WRITE] Set the calculated reflection within MaterialData::CalcSurface().
	Float				alpha;									///< [READ WRITE] Set the calculated alpha within MaterialData::CalcAlpha().
	Ray*				tray;										///< [READ WRITE] The transmitted vector (can be modified in MaterialData::ChangeNormal()), only valid if shader sets @ref VOLUMEINFO::TRANSPARENCY and only during MaterialData::CalcSurface().
	Ray*				rray;										///< [READ WRITE] The reflected vector (can be modified in MaterialData::ChangeNormal()), only valid if shader sets @ref VOLUMEINFO::REFLECTION and only during MaterialData::CalcSurface().
	Vector64		p;											///< [READ WRITE] The surface point, this can only be modified by MaterialData::Displace().
	Vector64		bumpn;									///< [READ WRITE] The surface phong and bump normal.

	Ray*				ray;										///< [READ ONLY] The current eye ray. Always valid, not @formatConstant{nullptr}.
	Vector64		orign;									///< [READ ONLY] The original surface normal.
	Vector64		n;											///< [READ ONLY] The surface phong normal.
	Vector64		dispn;									///< [READ ONLY] The suggested displacement direction.
	Float64			dist;										///< [READ ONLY] The distance between @ref p and @c ray->p, i.e. the ray length.
	Float64			cosc;										///< [READ ONLY] The angle between ray vector and unbumped normal.

	Vector			uvw;										///< [READ ONLY] The surface UVW coordinates, this is invalid for volumetric shaders.
	Vector			delta;									///< [READ ONLY] The MIP sample radius. Defines the radius for the area around UVW that needs to be sampled.\n
																			///< If this value is ignored by a shader, it will work, but produce aliasing artefacts.
	RayHitID		lhit;										///< [READ ONLY] The surface identity.
	const TexData* tex;									///< [READ ONLY] The surface texture, @b never change this pointer.
	Vector			ddu,										///< [READ ONLY] U direction vector perpendicular to @ref n; can be used for bump mapping if @ref VOLUMEINFO::DUDVREQUIRED is set.
							ddv;										///< [READ ONLY] V direction vector perpendicular to @ref n; can be used for bump mapping if @ref VOLUMEINFO::DUDVREQUIRED is set.
	Int32				raydepth;								///< [READ ONLY] The depth of the actual ray.
																			///< @note @em 0 during shadow calculation.

	Int32				calc_trans;							///< [READ ONLY] Specifies if transparency will be rendered:
																			///< - 0 No transparency.
																			///< - 1 No refractions.
																			///< - 2 Full calculation.
	Int32				calc_refl;							///< [READ ONLY] Specifies if reflections will be rendered:
																			///< - 0 No reflection.
																			///< - 1 Only sky/floor.
																			///< - 2 Full calculation.
	Bool				calc_shadow;						///< [READ ONLY] Specifies, if shadows will be rendered.
	Int32				calc_illum;							///< [READ ONLY] Specifies, if illumination will be rendered.\n
																			///< If this value is @em 0 then VolumeData::CalcSurface() should directly return the surface color without illumination (also, no bump mapping is needed in VolumeData::ChangeNormal() etc.).
																			///< This technique is used for some types of objects like the sky. @c Illuminance1 automatically takes care of @ref calc_illum.
	Int32				calc_mip;								///< [READ ONLY] Specifies if MIP calculations will be done.\n
																			///< If this value is @em 0 then no MIP mapping needs to be calculated. @ref calc_mip can in some cases be false, even if the shader sets @ref VOLUMEINFO::MIPSAT.\n
																			///< If @ref calc_mip is @formatConstant{false} you should not access MIP/SAT variables such as @ref delta etc.

	Vector			pp[3];									///< [READ ONLY] MIP corner points in global space.
																			///< @note Only valid if @ref VOLUMEINFO::MIPSAT is set.
	Vector			nn[3];									///< [READ ONLY] MIP normals of the three other corner points.
																			///< @note Only valid if @ref VOLUMEINFO::MIPSAT is set.

	RAYBIT			raybits;								///< [READ ONLY] The ray information: @enumerateEnum{RAYBIT}
	const RayLight*		xlight;						///< The light source during shadow evaluation. Can be @formatConstant{nullptr}, always check.
	const RayObject*	op;								///< The object. Can be @formatConstant{nullptr}, always check.

	Int32				recursion_id;						///< [READ WRITE] The plugin ID of data passed through recursion.
	void*				recursion_data;					///< [READ WRITE] The address of data passed through recursion.
	Multipass*	multipass;							///< [READ WRITE] To be filled for multipasses.

	Vector			back_p;									///< [READ ONLY] The back-projected point (StickTextureTag) will be generated if the shader sets the flag @ref VOLUMEINFO::TRANSFORM or @ref SHADERINFO::TRANSFORM for a channel shader.
	Vector			back_delta;							///< [READ ONLY] This the 'spot size' (MIP mapping value) for the back-projected point.\n
																			///< The back-projected point (StickTextureTag) will be generated if the shader sets the flag @ref VOLUMEINFO::TRANSFORM (or @ref SHADERINFO::TRANSFORM if it is a channel shader).

	Float				global_mip;							///< [READ ONLY] The global MIP scale.

	Int32				sid;										///< [READ ONLY] Sub-polygon ID (only used for SPD).
	Float				par_u,									///< [READ ONLY] Barycentric U coordinate (only used for SPD).
							par_v;									///< [READ ONLY] Barycentric U coordinate (only used for SPD).

	SurfaceIntersection* intersection;	///< [READ ONLY] The intersection data. Can be @formatConstant{nullptr}, always check.

	Float				mb_offset;							///< [READ ONLY] The motion blur time offset. (Between @em 0.0 and @em 1.0, only valid in Physical %Render.)

	Vector			comp_color;							///< [READ WRITE] The diffuse component of the calculated color.
	Vector			comp_specular;					///< [READ WRITE] The specular component of the calculated color.
	Vector			comp_luminance;					///< [READ WRITE] The luminance component of the calculated color.

	TexEntry*		rtex[4];								///< [READ ONLY] @markInternal The reflection textures. @since R16
	Int32				rtex_count;							///< [READ ONLY] @markInternal The number of reflection textures in @ref rtex. @since R16

	Int32				elementIndex;						///< [READ ONLY] @markInternal Stores the index of the currently rendering hair. May be extended to other object types eventually. @since R19

	const RayPolyWeight* displacementWeight;	///< [READ ONLY] Private.
};

struct ChannelData
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	ChannelData() { vd = nullptr; }

	//----------------------------------------------------------------------------------------
	/// Constructs a ChannelData that matches the current state of a BaseVolumeData.
	/// @param[in] t_vd								The volume data to take @ref p, @ref n and @ref d from. @callerOwnsPointed{volume data}
	//----------------------------------------------------------------------------------------
	explicit ChannelData(BaseVolumeData* t_vd) : p(t_vd->uvw), n((Vector)t_vd->n), d(t_vd->delta) { t = t_vd->time; texflag = 0; vd = (VolumeData*)t_vd; off = 0.0; scale = t_vd->global_mip; }

	Vector			p;					///< [READ ONLY] The texture position in UVW coordinates.
	Vector			n;					///< [READ ONLY] The surface normal.
	Vector			d;					///< [READ ONLY] The MIP sample radius in UVW coordinates.
	Float				t;					///< [READ ONLY] The current time in seconds.
	Int32				texflag;		///< [READ ONLY] The texture flags: @enumerateEnum{TEX}
	VolumeData*	vd;					///< [READ ONLY] The volume information, can be @formatConstant{nullptr}.
	Float				off, scale;	///< [READ ONLY] The MIP blur offset.

	//----------------------------------------------------------------------------------------
	/// Retrieves the current thread index on which the shader is executed.
	/// @since R16.038
	/// @note	<tt>%GetCurrentCPU()</tt> exists as a member of ChannelData and VolumeData, both yielding the same results.\n
	///				However if no VolumeData is present (and only then!) a channel shader calculation can also be called with ChannelData::vd set to @formatConstant{nullptr}.\n
	///				In that case (or generally) use ChannelData::GetCurrentCPU().
	/// @return												The running thread index, which is guaranteed to be <tt>>= 0</tt> and smaller than the thread count that was passed during @c InitRender().
	//----------------------------------------------------------------------------------------
	Int32 GetCurrentCPU() { return C4DOS.Sh->GetCurrentCPU(vd); }
};

/// @addtogroup MSG_SHADER
/// @ingroup group_enumeration
/// @{
#define MSG_GETALLASSETS		112004			///< Retrieve all assets used by an object.
																				///< @see MSG_MULTI_CLEARSUGGESTEDFOLDER MSG_RENAMETEXTURES
#define MSG_RENAMETEXTURES	112010			///< This message is broadcast to all scene elements when a bitmap image was renamed (e.g. by Make Project or by @BP3D) and all shaders etc. need to adjust the name.
/// @}

//----------------------------------------------------------------------------------------
/// Message struct for the @ref MSG_RENAMETEXTURES message.
/// This message is broadcast to all scene elements when a bitmap image was renamed (e.g. by Make Project or by @BP3D) and all shaders etc. need to adjust the name.\n
/// If something is adjusted then @ref changecnt must be increased.
//----------------------------------------------------------------------------------------
struct RenameTextureMessage
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	RenameTextureMessage() : doc(nullptr), changecnt(0), noundo(false) { }

	Filename			oldname;				///< Old filename.
	Filename			newname;				///< New filename.
	BaseDocument*	doc;						///< Document.
	Int32					changecnt;			///< Change count. Increase this if to adjust a value.
	Bool					noundo;					///< Set this to @formatConstant{true} when sending @ref MSG_RENAMETEXTURES to stop an undo getting added when filenames (textures etc.) are renamed.\n
																///< Also check this when receiving @ref MSG_RENAMETEXTURES (e.g. morphs/Xrefs check for this message to rename their external filenames).
};

//----------------------------------------------------------------------------------------
/// @see VolumeData::GetFragments
//----------------------------------------------------------------------------------------
struct VPFragment
{
	RayHitID		id;					///< Fragment ID.
	UChar				subx,				///< A valid sub-X position that is covered by the fragment; where a ray can safely be created that will intersect the fragment: @em 0 <= @ref subx <= @em 15
							suby;				///< A valid sub-Y position that is covered by the fragment; where a ray can safely be created that will intersect the fragment: @em 0 <= @ref suby <= @em 15
	Int16				weight;			///< The weight of the fragment. @em 256 = @em 16x16 = full pixel; @em 0 = empty pixel.
	RayObject*	op;					///< Fragment object.

	Vector32		color;			///< Fragment color.

	Float				z;					///< Z depth at the @link subx@endlink/@link suby@endlink position.
	Vector			p;					///< Global intersection point at the @link subx@endlink/@link suby@endlink position.
	Vector			n;					///< Normal at the @link subx@endlink/@link suby@endlink position.

	VPFragment*	next;				///< The next fragment, or @formatConstant{nullptr} if this is the last.
};

#endif // C4D_SHADER_H__
