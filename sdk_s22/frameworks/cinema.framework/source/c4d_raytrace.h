/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_RAYTRACE_H__
#define C4D_RAYTRACE_H__

#include "ge_math.h"
#include "c4d_shader.h"
#include "c4d_spc.h"

/// @addtogroup TextureProjectionTypes
/// @ingroup group_enumeration
/// @{
/// Texture projection types.
#define P_SPHERICAL			0				///< Spherical.
#define P_CYLINDRICAL		1				///< Cylindrical.
#define P_FLAT					2				///< Flat.
#define P_CUBIC					3				///< Cubic.
#define P_FRONTAL				4				///< Frontal.
#define P_SPATIAL				5				///< Spatial.
#define P_UVW						6				///< UVW.
#define P_SHRINKWRAP		7				///< Shrinkwrap.
#define P_CAMERAMAP			8				///< Camera
#define P_VOLUMESHADER	10			///< Volume
/// @}

/// @addtogroup RayObjectTypes
/// @ingroup group_enumeration
/// @{
/// RayObject types.
#define O_FLOOR		0			///< Infinite floor object. RayObject::mp and RayObject::v2 define the plane: <tt>(p-@link RayObject::mp@endlink)*@link RayObject::v2@endlink = 0</tt> where @c p is any point on the plane.
#define O_SKY			1			///< Infinite sphere object. The sky object always has (@em 0, @em 0, @em 0) origin and infinite size.
#define O_SPHERE	2			///< Perfect sphere. The center of the sphere is RayObject::mp. The radius is [@c RayObject::rad.x,@c RayObject::rad.y] and @c RayObject::rad.z can be ignored.
#define O_POLYGON	3			///< Polygon object. The points and polygons are stored in RayObject::padr and RayObject::vadr. RayObject::mp and RayObject::rad define the bounding box.
/// @}

/// @addtogroup FIELD
/// @ingroup group_enumeration
/// @{
/// Field rendering.
#define FIELD_NONE	0			///< No field rendering.
#define FIELD_EVEN	1			///< Even field is rendered first.
#define FIELD_ODD		2			///< Odd field is rendered first.
/// @}

/// @addtogroup DOF
/// @ingroup group_enumeration
/// @{
/// Depth of field.
#define DOF_NONE	0			///< No depth of field.
#define DOF_BOTH	1			///< Front and rear depth of field.
#define DOF_FRONT	2			///< Front depth of field.
#define DOF_BACK	3			///< Rear depth of field.
/// @}

/// @addtogroup ANTI
/// @ingroup group_enumeration
/// @{
/// Anti-aliasing.
#define ANTI_NONE			0			///< No antialiasing.
#define ANTI_GEOMETRY	1			///< Geometry antialiasing.
#define ANTI_BEST			2			///< Best antialiasing.
/// @}

/// @addtogroup RaytraceCameraTypes
/// @ingroup group_enumeration
/// @{
/// Camera types.
#define CAMERA_PERSPECTIVE	0								///< Perspective camera projection.
#define CAMERA_PARALLEL			1								///< Parallel camera projection.
#define CAMERA_AXONOMETRIC	2								///< Axonometric camera projection.
#define CAMERA_VRPANORAMA		3								///< VR panorama camera projection.
#define CAMERA_CUSTOMLENS		4								///< Custom lens projection (see @ref VIDEOPOSTINFO::CUSTOMLENS).
#define CAMERA_CUSTOMLENS_LENSDISTORT 5			///< Custom lens projection used to implement Lens Distortion. @since R17.032
#define CAMERA_SPHERICAL		14							///< Stereo Spherical Camera. @since R19
/// @}

/// @addtogroup RaytraceLightTypes
/// @ingroup group_enumeration
/// @{
/// Light types.
#define RT_LT_OMNI				0				///< Omni light.
#define RT_LT_SPOT				1				///< Spot light.
#define RT_LT_SPOTRECT		2				///< Square spot light.
#define RT_LT_DISTANT			3				///< Distant light.
#define RT_LT_PARALLEL		4				///< Parallel light.
#define RT_LT_PARSPOT			5				///< Parallel spot light.
#define RT_LT_PARSPOTRECT	6				///< Parallel square spot light.
#define RT_LT_AREA				8				///< Area light.
#define RT_LT_PHOTOMETRIC	9				///< Photometric light (IES).
#define RT_LT_AMBIENT			50			///< Only for OpenGL fragment programs.
#define RT_LT_DEFAULT			51			///< Only for OpenGL fragment programs.
/// @}

/// @addtogroup RaytraceShadowTypes
/// @ingroup group_enumeration
/// @{
/// Shadow types.
#define RT_SHADOW_NONE	0			///< No shadow.
#define RT_SHADOW_SOFT	1			///< Soft shadow.
#define RT_SHADOW_HARD	2			///< Hard shadow.
#define RT_SHADOW_AREA	3			///< Area shadow.
/// @}

/// @addtogroup RaytraceVisibleLight
/// @ingroup group_enumeration
/// @{
/// Light visibility.
#define RT_VL_NONE					0			///< No visible light.
#define RT_VL_VISIBLE				1			///< Visible light.
#define RT_VL_VOLUMETRIC		2			///< Volumetric visible light.
#define RT_VL_INVVOLUMETRIC	3			///< Inverse volumetric visible light.
/// @}

/// @addtogroup RaytraceLightFalloff
/// @ingroup group_enumeration
/// @{
/// Light falloff.
#define RT_FALLOFF_NONE							0				///< No light falloff.
#define RT_FALLOFF_INVERSE_CLAMPED	6				///< Clamped inverse light falloff.
#define RT_FALLOFF_SQUARE_CLAMPED		7				///< Clamped square light falloff.
#define RT_FALLOFF_LINEAR						8				///< Linear light falloff.
#define RT_FALLOFF_INVERSE					9				///< Inverse light falloff.
#define RT_FALLOFF_SQUARE						10			///< Square light falloff.
#define RT_FALLOFF_STEP							5				///< Step light falloff.
/// @}

/// @addtogroup RaytraceLightNoise
/// @ingroup group_enumeration
/// @{
/// Light noise.
#define RT_VN_NONE	0			///< No light noise.
#define RT_VN_ILLUM	1			///< Light noise illumination.
#define RT_VN_VISIB	2			///< Light noise visibility.
#define RT_VN_BOTH	3			///< Light noise both illumination and visibility.
/// @}

/// @addtogroup RaytraceLightNoiseTypes
/// @ingroup group_enumeration
/// @{
/// Light noise types.
#define RT_VN_NOISE						0			///< Noise light.
#define RT_VN_SOFTTURBULENCE	1			///< Soft turbulence light.
#define RT_VN_HARDTURBULENCE	2			///< Hard turbulence light.
#define RT_VN_WAVYTURBULENCE	3			///< Wavy turbulence light.
/// @}

/// @addtogroup RAY
/// @ingroup group_enumeration
/// @{
/// Raytrace structure types.
/// @see VolumeData::GetRayData
#define RAY_PARAMETER		0			///< The raytracer settings. @see VolumeData::GetRayParameter().
#define RAY_ENVIRONMENT	1			///< The raytracer environment parameters. @see VolumeData::GetRayEnvironment().
#define RAY_CAMERA			2			///< The raytracer camera. @see VolumeData::GetRayCamera().
#define RAY_SKY					3			///< The raytracer sky object. @see VolumeData::GetRaySky().
#define RAY_FOREGROUND	4			///< The raytracer foreground object. @see VolumeData::GetRayForeground().
#define RAY_BACKGROUND	5			///< The raytracer background object. @see VolumeData::GetRayBackground().
/// @}

/// Sub-pixel fragment masks have this resolution (@em 16*@em 16).
/// @see PixelFragment
#define OVERSAMPLING	16

/// @addtogroup RayTracePolystate
/// @ingroup group_enumeration
/// @{
/// Raytrace polygon state bits.
#define RAYPOLYSTATE_TRIANGLE		1			///< Triangle polygon.
#define RAYPOLYSTATE_QUADRANGLE	2			///< Quadrangle polygon.
#define RAYPOLYSTATE_SPLIT			4			///< Split polygon. (Not coplanar.)
/// @}

struct RayPolygon
{
	Int32 a,			///< Index for the first point of the polygon.
				b,			///< Index for the second point of the polygon.
				c,			///< Index for the third point of the polygon.
				d;			///< Index for the fourth point of the polygon.
};

class BaseObject;
struct TexList;
struct RayFragment;
struct PixelFragment;
class Gradient;

/// @addtogroup LIGHTRESTRICTION
/// @ingroup group_enumeration
/// @{
#define LIGHTRESTRICTION_NODIFFUSE	(1 << 0)			///< No diffuse.
#define LIGHTRESTRICTION_NOSPECULAR	(1 << 1)			///< No specular.
#define LIGHTRESTRICTION_NOSHADOW		(1 << 2)			///< No shadow.
/// @}

/// @addtogroup OBJECTRESTRICTION
/// @ingroup group_enumeration
/// @{
#define OBJECTRESTRICTION_TRANSPARENCY	(1 << 0)			///< Transparency.
#define OBJECTRESTRICTION_REFRACTION		(1 << 1)			///< Refraction.
#define OBJECTRESTRICTION_REFLECTION		(1 << 2)			///< Reflection.
#define OBJECTRESTRICTION_AO						(1 << 4)			///< Ambient occlusion.
/// @}

struct ObjectRestriction
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	ObjectRestriction() : object(nullptr), object_cnt(0) { }

	UChar*	object;					///< An array of @ref object_cnt flags, one for each object.\n
													///< For light restriction these are the flags: @enumerateEnum{LIGHTRESTRICTION}\n
													///< For object restriction these are the flags: @enumerateEnum{OBJECTRESTRICTION}
	Int32		object_cnt;			///< The number of objects.
};

struct RayObjectInstanceData
{
	Int32				instance_of_index;			///< Index to the instanced ray object.
	Matrix64		transform,							///< Transformation matrix of the instance.\n
																			///< Transformation from original object's point to instanced object: <tt>new_point = old_point * instanced_rayobject->instance->transform</tt>
							transform_inverse;			///< Inverse transformation matrix of the instance.\n
																			///< Transformation from instanced object's point to original object: <tt>new_point = old_point * instanced_rayobject->instance->transform_inverse</tt>
	Matrix64		transform_tensor;				///< Transformation matrix tensor of the instance.\n
																			///< Transformation of normal from original object to instanced object: <tt>new_normal = !(old_normal^instanced_rayobject->instance->transform_tensor)</tt>
	BaseObject* link;										///< Link to the virtual instance parent (the "Instance" object).
	Matrix64			_matrix;							///< Matrix of the instance. @since R19
	Int32					_instanceID = NOTOK;	///< ID of the given instance. Used for Multi-Instance for now. @since R20
	maxon::Bool		_useColor = false;		///< request use of color. @since R20
	maxon::Color64 _color;							///< desired color for the instance. @since R20
};

struct RayObject
{
protected:
	RayObject();

public:
	Char										type;									///< Object type: @enumerateEnum{RayObjectTypes}\n
																								///< Special types such as @ref O_SPHERE have no polygonal geometry, thus all values like @ref padr and @ref vadr are @formatConstant{nullptr}.

	Char										flag_phong;						///< Phong flag.
	Char										flag_castshadow;			///< Cast shadow flag.
	Char										flag_receiveshadow;		///< Receive shadow flag.
	Char										flag_seenbycamera;		///< Seen by camera flag.
	Char										flag_compositing;			///< Compositing flag. Catches shadows.
	Char										flag_selfshadow;			///< Self shadowing flag.
	Char										flag_seenbygi;				///< Seen by GI flag.
	Char										flag_matteobject;			///< Object is matte object flag.
	Char										flag_seenbydetails;		///< Seen by details flag: @enumerateEnum{OBJECTRESTRICTION}
	Char										flag_instanced;				///< Object instanced flag.

	Vector									v2;										///< Normal in Y direction.
	Vector									mp;										///< Center of bounding box.
	Vector									rad;									///< Radius of bounding box.

	Float										visibility;						///< Object visibility. This is the information about the object dissolve (see the Timeline and the Visibility track) in the range from @em 0.0 to @em 1.0.
	Float										phong_angle;					///< Phong angle.

	Vector*									padr;									///< Address of the point array for the object. Can be @formatConstant{nullptr} for non @ref O_POLYGON elements.
	Int32										pcnt;									///< Number of points for this object.

	const RayPolygon*				vadr;									///< Address of the polygons array. Can be @formatConstant{nullptr} for non @ref O_POLYGON elements.
	Int32										vcnt;									///< Number of polygons for this object.

	TexList*								texadr;								///< Address of the texture array. Can be @formatConstant{nullptr}, always check.
																								///< @note It is not possible to access textures directly. Use VolumeData::GetTexData() instead.
	Int32										texcnt;								///< Number of textures.

	const void**						uvwadr;								///< Address of the UVW coordinate sets. Can be @formatConstant{nullptr}, always check.
																								///< @note It is not possible to access UVWs directly. Use VolumeData::GetUVW() instead.\n
																								///< The UVW sets range from @em 1 to <tt>uvwcnt-1</tt>.
	Int32										uvwcnt;								///< Number of UVW coordinate sets.

	UInt32**								rsadr;								///< Address of the object's restriction. Can be @formatConstant{nullptr}, always check.
																								///< @note It is possible to access the restriction directly.
																								///< The restriction sets range from @em 1 to <tt>rscnt-1</tt>.
	Int32										rscnt;								///< Number of object's restriction.

	BaseObject*							link;									///< Link to real @C4D object. Can be @formatConstant{nullptr}, always check.

	Matrix64								mg;										///< World matrix for the object.
	Matrix64								mg_inverse;						///< Inverse object matrix.

	Matrix									motion_delta;					///< Motion transformation matrix. This is <tt>oldmg * !newmg</tt>. The delta time is always 1/fps.
																								///< @note The @ref VIDEOPOSTINFO::REQUEST_MOTIONMATRIX flag must be set for this value to be calculated.
	Float										oblurlen;							///< Object blur strength.

	Char										aa_minlevel;					///< Minimum antialiasing level.
	Char										aa_maxlevel;					///< Maximum antialiasing level.
	Float										aa_threshold;					///< Antialiasing threshold.

	Int16										channelid[12];				///< Object buffer IDs.

	BaseObject*							texture_link;					///< Link to the real object that inherited the texture tag. Can be @formatConstant{nullptr}, always check.
	Vector									default_color;				///< Object default color.

	Int32										restriction_index;		///< Index to light/object restriction table.

	UChar*									edges;								///< Address of the edges array, one per polygon. Can be @formatConstant{nullptr}, always check.\n
																								///< Bits @em 0 to @em 3 indicate hiding of edge A to D, bits @em 4 to @em 7 indicate the broken phong property.
	Int16*									psum;									///< @markPrivate Phong normals. Access depends on mode.

	Int32										spd_displacement;			///< Sub-pixel displacement subdivision.
	Float										spd_height;						///< Maximum displacement height, taking the strength into account.
	Char										spd_keepedges;				///< Sub-pixel displacement keep edge setting.
	Char										spd_distribution;			///< Sub-pixel displacement best distribution setting.
	Char										spd_round;						///< Sub-pixel displacement round setting.
	Char										spd_roundcontour;			///< Sub-pixel displacement round contour setting.
	Char										spd_hqremapping;			///< Sub-pixel displacement high quality remapping setting.
	Char										spd_mapresult;				///< Sub-pixel displacement map geometry setting.

	void*										userdata;							///< Only to be used by plugin renderers.

	ObjectRestriction				rr;										///< Compositing tag restriction.

	RayObjectInstanceData*	instance;							///< The render instance data. If not @formatConstant{nullptr} the object is a render instance.

	Int16**									tex_tsum;							///< Address of the precomputed tangents for each UV channel used in VolumeData::GetDUDV().\n
																								///< Just like the smooth normals, the way the data is stored depends on the mode (in same way as it does for phong). Can be @formatConstant{nullptr}, always check.\n
																								///< Only one tangent vector is stored. The second can be easily computed by cross product with the normal vector.
	Char										flag_compositing_gi;	///< New compositing flag for Sky mode as seen in the Compositing Tag.
	Bool										forceDefaultColor = false;  ///< force the use of default color. added for R20.
};

//----------------------------------------------------------------------------------------
/// The UVWs for a polygon. In the raytracer they are uncompressed.
//----------------------------------------------------------------------------------------
struct PolyVector
{
	Vector	a,			///< The UVW for the first point of the polygon.
					b,			///< The UVW for the second point of the polygon.
					c,			///< The UVW for the third point of the polygon.
					d;			///< The UVW for the fourth point of the polygon.
};

//----------------------------------------------------------------------------------------
/// Stores polygon weight information. Filled by VolumeData::GetWeights().
//----------------------------------------------------------------------------------------
struct RayPolyWeight
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	RayPolyWeight() : wa(0.0), wb(0.0), wc(0.0), wd(0.0) {}

	Float	wa;			///< A weight.
	Float	wb;			///< B weight.
	Float	wc;			///< C weight.
	Float	wd;			///< D weight.
};

struct RayLightNoise
{
protected:
	RayLightNoise();

public:
	Int32		type;						///< The noise algorithm type.
	Float		octaves;				///< The noise octaves.
	Float		velocity;				///< The noise speed.
	Float		brightness;			///< The noise brightness.
	Float		contrast;				///< The noise contrast.
	Bool		local;					///< @formatConstant{true} for local noise.
	Vector	scale;					///< The noise scale.
	Float		iscale;					///< The illumination scale.
	Vector	wind;						///< The wind effect.
	Float		windvelocity;		///< The wind velocity.
};

struct RayLightCaustics
{
protected:
	RayLightCaustics();

public:
	Bool	cs_enable;			///< enable surface caustics
	Float	cs_energy;			///< The caustic energy.
	Int32	cs_photons;			///< The number of photons.

	Bool	vcs_enable;			///< @formatConstant{true} to enable volume caustics.
	Float	vcs_energy;			///< The volume caustic energy.
	Int32	vcs_photons;		///< The number of volume photons.

	Int32	falloff;				///< The caustic light falloff.
	Float	innerradius;		///< The inner radius.
	Float	outerradius;		///< The outer radius.
};

struct RayLightShadow
{
protected:
	RayLightShadow();

public:
	Float		density;							///< The shadow density.
	Vector	color;								///< The shadow color.
	Bool		transparency;					///< @formatConstant{true} if the shadow supports transparency.
	Bool		clippinginfluence;		///< @formatConstant{true} to evaluate clipping areas.

	Int32		mapsizex,							///< The soft shadow map horizontal resolution.
					mapsizey;							///< The soft shadow map vertical resolution.
	Float		bias;									///< The soft shadow bias.
	Bool		absolute;							///< The absolute bias.
	Int32		sampleradius;					///< The soft shadow sample radius.
	Float		parallelwidth;				///< The soft shadow parallel width.
	Bool		outline;							///< The outline soft shadow.

	Bool		shadowcone;						///< The soft shadow cone.
	Float		coneangle;						///< The soft shadow cone angle.
	Bool		softcone;							///< @formatConstant{true} for soft falloff at the edges.

	Float		accuracy;							///< The area shadow accuracy.
	Int32		minsamples;						///< The area shadow min samples.
	Int32		maxsamples;						///< The area shadow max samples.

	Bool		highquality;					///< The soft shadow omni light is calculated with the best quality.
	Int32		samplingBoost;				///< The soft shadow sampling boost.
};

struct RayLightVisible
{
protected:
	RayLightVisible();

public:
	Bool			falloff;									///< Falloff.
	Float			strength;									///< Falloff strength.
	Bool			edgefalloff;							///< Edge falloff.
	Float			edgestrength;							///< Edge falloff strength.
	Bool			colfalloff;								///< Colored edge falloff.
	Float			innerdistance;						///< Inner distance.
	Vector		outerdistance;						///< Outer distance.
	Float			sampledistance;						///< Sample distance.
	Float			brightness_multiplier;		///< Brightness multiplier.
	Float			dust;											///< Dust effect.
	Float			dithering;								///< Dithering.
	Bool			adaptbrightness;					///< Adapt brightness (angle based brightness scale).
	Bool			additive;									///< Additive visible light.
	Vector		color;										///< Color.

	Gradient* gradient;									///< Color gradient.
};

struct RayLight
{
protected:
	RayLight();

public:
	RayLightNoise*		ln;												///< The light noise structure. Always valid, not @formatConstant{nullptr}.
	RayLightShadow*		ls;												///< The shadow structure. Always valid, not @formatConstant{nullptr}.
	RayLightVisible*	lv;												///< The visible light structure. Always valid, not @formatConstant{nullptr}.
	BaseObject*				link;											///< The link to the 'real' light object.

	Bool							calc_illum;								///< @formatConstant{true} if the light source illuminates.
	Matrix64					m;												///< The light matrix.
	Matrix64					m_inverse;								///< The inverse light matrix.

	Int32							type;											///< The type of light source: @enumerateEnum{RaytraceLightTypes}
	Int32							stype;										///< The shadow type: @enumerateEnum{RaytraceShadowTypes}
	Int32							vtype;										///< The type of visible light: @enumerateEnum{RaytraceVisibleLight}
	Int32							ntype;										///< The type of noise for illumination/visible light: @enumerateEnum{RaytraceLightNoise}
	Int32							falloff;									///< The type of light falloff: @enumerateEnum{RaytraceLightFalloff}
	Float							innerangle;								///< The inner angle of light cone, only relevant if the light source is a spot.
	Float							outerangle;								///< The outer angle of light cone, only relevant if the light source is a spot.
	Float							innerradius;							///< The inner radius of light cylinder, only relevant if the light source is a parallel spot.
	Float							outerradius;							///< The outer radius of light cylinder, only relevant if the light source is a parallel spot.
	Float							aspectratio;							///< The Y distortion, to get the resulting matrix system multiply by @c m.sqmat.v2.
	Bool							arealight;								///< @formatConstant{true} if the light source acts as arealight.
	Bool							ambient;									///< The light source illuminates ambient light.
	Bool							nodiffuse;								///< The light source does not affect the diffuse component.
	Bool							nospecular;								///< The light source does not affect the specular component.
	Bool							nogi;											///< The light source does not affect GI.
	Bool							innercolor;								///< @formatConstant{true} if the inner color is used.
	Bool							colfalloff;								///< Edge color falloff.
	Bool							negative;									///< @formatConstant{true} if the light source subtracts intensity.
	Float							contrast;									///< The light contrast.
	Float							innerdist;								///< The inner distance, only important if falloff is set.
	Float							outerdist;								///< The outer distance, only important if falloff is set.
	Vector						color;										///< The light color, only important if @ref innercolor is set.
	Bool							nearclip;									///< Near clipping.
	Bool							farclip;									///< Far clipping.
	Float							nearfrom;									///< Near clipping start.
	Float							nearto;										///< Near clipping end.
	Float							farfrom;									///< Far clipping start.
	Float							farto;										///< Far clipping end.
	Vector						lens_color;								///< Color for the lens flares.

	RayLightCaustics*	lc;												///< The caustics structure. Always valid, not @formatConstant{nullptr}.
	Bool							separatepass;							///< @formatConstant{true} if render as separate multipass.
	Float							trn;											///< Exp (-contrast).
	Int32							multipass_index;					///< Index into multipass light field (or @ref NOTOK).

	ObjectRestriction	lr;												///< Light restriction.

	void*							userdata;									///< Only to be used by plugin renderers.

	Bool							onlyz;										///< Only Z.

	Vector						arearadius;								///< Area radius.
	Int32							areashape;								///< Area shape. (See olight.h, @ref LIGHT_AREADETAILS_SHAPE.)
	Int32							areasamples;							///< Number of area samples.
	Bool							areaaddgrain;							///< @formatConstant{true} to add area grain.

	const Vector*			area_padr;								///< Area points.
	Int32							area_pcnt;								///< Number of area points.
	const RayPolygon*	area_vadr;								///< Area polygons.
	Int32							area_vcnt;								///< Number of area polygons.
	BaseObject*				area_link;								///< Area link.
	Matrix*						area_matrix;							///< Area matrix.
	Bool							shadowcaster;							///< Shadow caster.
	Float							area_falloffangle;				///< Area falloff angle.
	Float							area_infiniteangle;				///< Infinite area angle.
	Bool							area_showinrender;				///< Show area light in render.
	Bool							area_showinreflection;		///< Show area light in render.
	Vector						area_backcolor;						///< Area light back color. @since R19

	Gradient*					gradient;									///< Color gradient.
	Float							gradient_multiplier;			///< Gradient multiplier.
	Float							lens_imul;								///< Lens multiplier.

	TexList*					texadr;										///< Texture address. Can be @formatConstant{nullptr}, always check.
																							///< @note It is not possible to access textures directly. Use VolumeData::GetTexData() instead.
	Int32							texcnt;										///< Texture count.
};

struct RayParameter
{
protected:
	RayParameter();

public:
	Int32											xres,						///< Image horizontal resolution.
														yres;						///< Image vertical resolution.
	Int32											left,						///< Left offset for the marquee render.
														top,						///< Top offset for the marquee render.
														right,					///< Right offset for the marquee render.
														bottom;					///< Bottom offset for the marquee render.
	Float											pixelaspect;		///< Aspect ratio of pixels.

	Int32											antialiasing;		///< Antialiasing level: @enumerateEnum{ANTI}
	Int32											oversample;			///< Antialiasing oversampling (@em 1 or @em 16).

	Int32											reflection;				///< Reflection level (@em 0: none, @em 1: floor and sky, @em 2: full).
	Int32											transparency;			///< Transparency level (@em 0: none, @em 1: no refraction, @em 2: full).
	Bool											shadow;						///< Enable shadows.
	Bool											onlysoftshadow;		///< Limit shadows to soft shadows only.

	Int32											raydepth;						///< Maximum ray depth.
	Int32											reflectiondepth;		///< Maximum reflection depth.
	Int32											shadowdepth;				///< Maximum ray depth for shadow calculations.
	Float											threshold;					///< Minimum intensity of a ray.

	Bool											gi_reflectivecaustics;		///< Enable reflective caustics for GI.
	Bool											gi_refractivecaustics;		///< Enable refractive caustics for GI.
	Int32											field;										///< Field rendering: @enumerateEnum{FIELD}
	Bool											volumetriclighting;				///< Enable volumetric effects.
	Bool											straightalpha;						///< Straight alpha.
	Bool											textures;									///< Textures.
	Bool											textureerror;							///< Stop if texture error.
	Bool											enable_blurry;						///< Enable blurry.
	Bool											dithering;								///< True color dithering.

	Bool											gi_enablediffuse,						///< Enable radiosity diffuse option.
														gi_prepass;									///< Radiosity prepass.
	Bool											cs_enablecaustics,					///< Enable caustics.
														cs_enablevolumecaustics;		///< Enable volume caustics.

	Int32											aa_filter;			///< Antialiasing filter.
	Float											aa_threshold;		///< Antialiasing threshold.
	Int32											aa_minlevel;		///< Antialiasing minimum level.
	Int32											aa_maxlevel;		///< Antialiasing maximum level.
	Bool											aa_useobject;		///< Enable local antialiasing.
	Float											aa_globalmip;		///< Global MIP scale.

	RENDERFLAGS								renderflags;		///< %Render flags passed to ::RenderDocument(): @enumerateEnum{RENDERFLAGS}

	Bool											showhud;									///< Show head up display.
	Bool											cacheshadowmaps;					///< Enable shadow map caching.
	Bool											enablespd;								///< Enable sub-polygon displacement.
	Float											global_brightness;				///< Global brightness.
	Bool											apply_ambientocclusion;		///< Apply ambient occlusion.
	Bool											aa_considermultipasses;		///< Antialiasing consider multi-passes.

	Bool											linear_workflow;						///< Enable Linear Workflow.
	COLORSPACETRANSFORMATION	colorspacetransformation;		///< Color space transformation: @enumerateEnum{COLORSPACETRANSFORMATION}

	Float											unitscale;		///< Unit scale. @em 1.0 unit equals 'unitscale' meters in real life.

	Float											aa_filtersizex,					///< Antialiasing filter width.
														aa_filtersizey;					///< Antialiasing filter height.
	Bool											aa_customfiltersize,		///< Enable custom antialiasing filter size.
														aa_clipnegative;				///< Enable negative antialiasing clipping.

	Bool											gi_ambientocclusion;		///< GI computes AO.

	Bool											gi_radiance_enabled;		///< GI computes radiance maps.
	Int32											gi_radiance_mode;				///< GI radiance mode.
	Int32											gi_radiance_samples;		///< GI radiance samples.
	Float											gi_radiance_density;		///< GI radiance density.

	Bool											lock_noise;		///< Enable identical noise distribution.
	Bool											enable_sss;		///< Enable subsurface scattering.

	Float											gi_radiance_intensity;		///< GI radiance intensity
	Float											gi_radiance_saturation;		///< GI radiance saturation.

	Bool											gi_lightmapping_enabled;		///< GI computes light mapping.
	Bool											gi_lightmapping_direct;			///< GI computes light mapping direct.
	Bool											gi_lightmapping_prepass;		///< GI computes light mapping prepass.
	Int32											gi_lightmapping_mode;				///< GI light mapping mode.
	
	Bool											net_caches_sss;		///< NET caches SSS.
	Bool											net_caches_ao;		///< NET caches AO.
	Bool											net_caches_gi;		///< NET caches GI.
	Bool											net_caches_rm;		///< NET caches radiance mapping.
	Bool											net_caches_lm;		///< NET caches light mapping.
};

//----------------------------------------------------------------------------------------
/// The data for the scene environment (if an EnvironmentObject was in the scene).
//----------------------------------------------------------------------------------------
struct RayEnvironment
{
protected:
	RayEnvironment();

public:
	Vector	ambient;				///< Ambient environment color.
	Bool		fogenable;			///< Environment fog flag.
	Vector	fog;						///< Environment fog color.
	Float		fogdistance;		///< Environment fog distance.
	Bool		fogaffectbg;		///< Fog affects background.
};

struct RayCamera
{
protected:
	RayCamera();

public:
	Matrix64		m;												///< The camera's matrix.
	Matrix64		m_inverse;								///< The camera's inverse matrix.

	Float64			zoom;											///< The zoom factor (focal length divided by aperture width for perspective projections).

	Int32				type;											///< The camera type: @enumerateEnum{RaytraceCameraTypes}

	Int32				depthoffield;							///< The type of depth of field: @enumerateEnum{DOF}
	Float				front_end,								///< The depth of field front blur end.
							middle,										///< The depth of field target distance.
							rear_end;									///< The depth of field rear blur end.

	Float				qtvr_hstart;							///< The horizontal start angle for QuickTime VR panorama.
	Float				qtvr_hend;								///< The horizontal end angle for QuickTime VR panorama.
	Float				qtvr_vfov;								///< The vertical field of view for QuickTime VR panorama.

	BaseObject*	link;											///< The pointer to the real camera object. Can be @formatConstant{nullptr}, always check.

	Vector64		off,											///< The camera offset, this is the center in screen coordinates.
							scale;										///< The camera scale, this is the screen scale, including focal length, aperture etc.

	Float				front_start,							///< The depth of field front blur start.
							rear_start,								///< The depth of field rear blur start.
							front_dlt,								///< <tt>1.0/(RayCamera::front_start - RayCamera::front_end)</tt>.
							rear_dlt;									///< <tt>1.0/(RayCamera::rear_end - RayCamera::rear_start)</tt>.
	Int32				xdlt,											///< The X offset for internal render.
																				///< @note This value (and @ref ydlt) is only relevant if there is an editor rendering.\n
																				///< In the editor @C4D has to fit in the view into the view window that might have a different x/y aspect ratio.\n
																				///< This means that either to the left/right or the upper/lower there will be an additional region that the final (external) render will not see.\n
																				///< The offset for this line is stored in either @ref xdlt or @ref ydlt, and the other one is @em 0.
							ydlt;											///< The Y offset for internal render. See @ref xdlt.

	Matrix			motion_delta;							///< The motion transformation matrix. This is <tt>oldmg * !newmg</tt>. The delta time is always @em 1/fps.
																				///< @note The @ref VIDEOPOSTINFO::REQUEST_MOTIONMATRIX flag must be set for this value to be calculated.
	Float64			near_clipping;						///< The Z clipping depth if @ref near_clipping_enabled is @formatConstant{true}.

	Vector64		kscale;										///< The camera's image scale.
	Vector64		kscale_z;									///< The camera's image Z scale (for axonometric projections).

	Float64			far_clipping;							///< The far clipping plane distance.
	Bool				near_clipping_enabled,		///< Enables near clipping.
							far_clipping_enabled;			///< Enables far clipping.

	Float				fDOFAperture;							///< The real depth of field (DOF) aperture.

	SpcInfo			_spcInfo;									///< Spherical camera parameters. @since R19
}; // struct RayCamera

//----------------------------------------------------------------------------------------
/// Filled by VolumeData::GetSurfaceData().
//----------------------------------------------------------------------------------------
struct SurfaceData
{
	Vector		col,										///< The surface color at a point.
						refl,										///< The reflection color. Note the result of the reflection ray is not part of this color.
						trans;									///< The transparency color. Note the result of the transparent ray is not part of this color.
	Float			alpha;									///< Obsolete.
	Ray				rray,										///< The reflected ray.
						tray;										///< The transmitted ray.
	Vector64	bumpn;									///< The bump normal.
	Float			cs_generate_strength,		///< This is the "caustic generation strength value" for the surface point.\n
																		///< The user can adjust this value in the material, it determines when caustic photons hit the surface point how strong caustics will be generated.
						cs_receive_strength;		///< This is the "caustics receive value" for the surface point.
	Vector		comp_color;							///< The diffuse component of the color.
	Vector		comp_specular;					///< The specular component of the color.
	Vector		comp_luminance;					///< The luminance component of the color.
};

//----------------------------------------------------------------------------------------
/// Use by custom illumination models; the illumination model fills out @ref rdiffuse and @ref rspecular for a given light source.
//----------------------------------------------------------------------------------------
struct RayLightComponent
{
	RayLight*	light;					///< [READ ONLY] The light source.
	Vector64	lv;							///< [READ ONLY] The light vector (points towards the light source).
	Vector		col;						///< [READ ONLY] The color of the light source.
	Vector		rdiffuse,				///< [WRITE] The diffuse component.
						rspecular,			///< [WRITE] The specular component.
						rreflection;		///< [WRITE] The reflection component. @since R16
};

struct RayLightCache
{
	RayLightComponent**	comp;										///< [READ ONLY] An array of RayLightComponent*.
	Int32								cnt;										///< [READ ONLY] The number of light sources.
	Vector							radiosity,							///< [READ ONLY] The global radiosity illumination at this point.
											caustics;								///< [READ ONLY] The global caustic illumination at this point.
	Vector							diffuse,								///< [READ WRITE] The diffuse component, filled out by the illumination model.
											specular;								///< [READ WRITE] The specular component, filled out by the illumination model.
	Vector							ao;											///< [READ ONLY] The ambient occlusion.
	Vector							reflection;							///< [READ WRITE] The reflection. @since R16
};

//----------------------------------------------------------------------------------------
/// @markPrivate
//----------------------------------------------------------------------------------------
struct RaySampler
{
	void*		guid;			///< [READ ONLY]
	UInt32	depth;		///< [READ ONLY]
	UInt32	index;		///< [READ WRITE]
};

//----------------------------------------------------------------------------------------
/// Each sample as computed when sampling the indirect illumination.\n
/// The RayHemiSample is the point on the RayHemisphere used for computing the indirect illumination when caches are used.\n
/// Contains all the information needed to compute the gradients for GI. When gradients are used these values should be used to compute the indirect illumination.
//----------------------------------------------------------------------------------------
struct RayHemiSample
{
	Vector	dir;						///< [READ ONLY] The point direction (in normal vector frame space).
	Vector	col;						///< [WRITE] The accumulated irradiance.
	Float		dist_sum;				///< [WRITE] Store the average distance (sum) to the intersecting geometry that is used later on during gradient computation.
	Float		dist_weight;		///< [WRITE] Store the average distance (weight) to the intersecting geometry that is used later on during gradient computation.
	Float		cos_theta;			///< [READ ONLY] Cosinus of angle precomputed for speed.
	Float		sin_theta;			///< [READ ONLY] Sinus of angle precomputed for speed.
};

//----------------------------------------------------------------------------------------
/// @see RayHemiSample
//----------------------------------------------------------------------------------------
struct RayHemisphere
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	RayHemisphere()
	{
		size_m					= 0;
		size_n					= 0;
		depth						= 0;
		count_hs				= 0;
		count_area			= 0;
		count_sky				= 0;
		sample_hs				= false;
		sample_area			= false;
		sample_sky			= false;
		no_hs						= false;
		no_area					= false;
		no_sky					= false;
		gradients				= false;
		per_pixel				= false;
		radiance_area		= false;
		radiance_sky		= false;
		ao_only					= false;
		ao_dist_min			= 0.0;
		ao_dist_max			= 0.0;
		ao_trans				= false;
		ao_self					= false;
		ao_reverse			= false;
		cache_mode			= false;
		cache_dist			= 0.0;
		cache_r					= 0.0;
		cache_r_real		= 0.0;
		details					= false;
		details_found		= false;
		details_radius	= 0.0;
		details_ratios	= 0.0;
		details_sum			= 0.0;
	}

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(RayHemisphere)

public:
	UInt32													size_m;					///< [READ ONLY] Width of the samples array (2D array of samples mapped into hemisphere).
	UInt32													size_n;					///< [READ ONLY] Height of the samples array (2D array of samples mapped into hemisphere).

	UInt32													depth;					///< [READ ONLY] The indirect depth.
	UInt32													count_hs;				///< [READ ONLY] Hemispherical sampling counts.
	UInt32													count_area;			///< [READ ONLY] Area sampling counts.
	UInt32													count_sky;			///< [READ ONLY] Sky sampling counts.
	Bool														sample_hs;			///< [READ ONLY] Enable hemispherical sampling.
	Bool														sample_area;		///< [READ ONLY] Enable area sampling.
	Bool														sample_sky;			///< [READ ONLY] Enable sky sampling.
	Bool														no_hs;					///< [READ ONLY] Do not compute hemispherical sampling.
	Bool														no_area;				///< [READ ONLY] Do not compute area sampling.
	Bool														no_sky;					///< [READ ONLY] Do not compute sky sampling.
	Bool														gradients;			///< [READ ONLY] Compute gradients. @ref samples is not valid unless this is @formatConstant{true}.
	Bool														per_pixel;			///< [READ ONLY] The call is used in per-pixel mode.
	Bool														radiance_area;	///< [READ ONLY] The call is used when computing area radiance for radiance maps.
	Bool														radiance_sky;		///< [READ ONLY] The call is used when computing sky radiance for radiance maps.

	Bool														ao_only;				///< [READ ONLY] Compute only the AO.
	Float														ao_dist_min;		///< [READ ONLY] AO minimum distance.
	Float														ao_dist_max;		///< [READ ONLY] AO maximum distance.
	Bool														ao_trans;				///< [READ ONLY] AO transparency.
	Bool														ao_self;				///< [READ ONLY] Self shadowing only AO.

	Vector													color;					///< [WRITE] The computed indirect illumination when gradients are not used.
	Bool														cache_mode;			///< [READ ONLY] GI caching mode.
	Float														cache_dist;			///< [WRITE] GI cache distance.
	Float														cache_r;				///< [WRITE] GI cache.
	Float														cache_r_real;		///< [WRITE] GI cache.

	Bool														details;				///< [READ ONLY] Compute the details enhancement for GI.
	Bool														details_found;	///< [WRITE] Found details enhancement.
	Float														details_radius;	///< [READ ONLY] Details enhancement radius.
	Float														details_ratios;	///< [WRITE] Details enhancement quality ratios.
	Float														details_sum;		///< [WRITE] Details enhancement sum.

	maxon::BaseArray<RayHemiSample>	samples;				///< [READ ONLY] Indirect illumination samples. @since R17.032

	Bool														ao_reverse;			///< [READ ONLY] Compute reverse ambient occlusion. @since R18
};

//----------------------------------------------------------------------------------------
/// Holds the radiance values for front and back of a polygon.
/// @since R17.032
//----------------------------------------------------------------------------------------
struct RadiancePolyFrontBack
{
	Vector32 radiance_front;			///< Radiance value for the front of the polygon.
	Vector32 radiance_back;				///< Radiance value for the back of the polygon.
};

//----------------------------------------------------------------------------------------
/// Contains the computed radiance values for front and back of each polygon.\n
/// The color is computed on demand, so if a certain texel is never seen it contains the value of @c Vector32(0.0, 0.0, -1.0).
//----------------------------------------------------------------------------------------
struct RayRadiancePoly
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(RayRadiancePoly)

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	RayRadiancePoly() : size_u(0), size_v(0) { }

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @since R17.032
	/// @param[in] src								The source RayRadiancePoly.
	//----------------------------------------------------------------------------------------
	RayRadiancePoly(RayRadiancePoly&& src) : map_front_back(std::move(src.map_front_back)), size_u(src.size_u), size_v(src.size_v) { }

	maxon::BaseArray<RadiancePolyFrontBack>	map_front_back;			///< Radiance values for the front and back of the polygon. @since R17.032
	Int32																		size_u;							///< Size U.
	Int32																		size_v;							///< Size V.
};

//----------------------------------------------------------------------------------------
/// Contains the computed radiance values for an object.
//----------------------------------------------------------------------------------------
struct RayRadianceObject
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(RayRadianceObject)

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	RayRadianceObject() { }

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @since R17.032
	/// @param[in] src								The source RayRadianceObject.
	//----------------------------------------------------------------------------------------
	RayRadianceObject(RayRadianceObject&& src) : polys(std::move(src.polys)) { }

	maxon::BaseArray<RayRadiancePoly> polys;	///< Radiance values buffer for the object's polygons. @since R17.032
};

struct PixelFragment
{
#ifdef __API_INTERN__
	RayFragment*	 next, *cluster;
#else
	PixelFragment* next,				///< The next fragment in the list.
							 *cluster;			///< If not @formatConstant{nullptr} then this pixel fragment is just a dummy for its children, stored as a linear list in 'cluster'.\n
															///< The coverage masks are then automatically in the union of all children masks.
#endif

	RayHitID id;			///< The global RayHitID structure.

	union
	{
		UInt16 mask[OVERSAMPLING];					///< The coverage mask. Each pixel fragment can cover @em 16*@em 16 sub-pixels at maximum.\n
																				///< For each Y sub-pixel line the mask is stored in <tt>PixelFragment::mask[y]</tt>. Bit @em 15 it the leftmost sub-pixel, @em 0 is at the right.\n
																				///< To check for the upper left sub-pixel use <tt>exists=PixelFragment::mask[0]&(1<<15)</tt>.\n
																				///< @note Use either @ref mask or @ref lmask. Both belong to the same union in the structure.
		UInt32 lmask[OVERSAMPLING / 2];			///< Provides wide access to the @em 16 elements of @ref mask.
																				///< @note Use either @ref mask or @ref lmask. Both belong to the same union in the structure.
	};

	Float32	z,			///< The pixel fragment's average z value as the fragment can cover a large Z area this is just a rough Z.
					u,			///< The UV coordinates for the pixel fragment for it is first evaluated texture (several textures can be stacked, so only the first one can be stored here).
					v;			///< The UV coordinates for the pixel fragment for it is first evaluated texture (several textures can be stacked, so only the first one can be stored here).

	Vector32	col;			///< The color of the pixel fragment.
	Vector		n;				///< The average normal. As the fragment can cover a 'large' area this is just a rough normal.

	Int32	subid;				///< For polygon objects this is the sub-pixel displacement ID.\n
											///< For perfect sphere objects this is @formatConstant{true} for the back side and @formatConstant{false} for the front side.
};

struct IlluminanceSurfacePointData;

//----------------------------------------------------------------------------------------
/// Callback definition for surface point illumination models.
/// @param[in] sd									The volume data for the point being calculated. @cinemaOwnsPointed{volume data}
/// @param[in] rlc								The light data cache for the point being calculated. @cinemaOwnsPointed{data}
/// @param[in] dat								The illuminance surface point data.
//----------------------------------------------------------------------------------------
typedef void IlluminanceSurfacePointModel (VolumeData * sd, RayLightCache * rlc, IlluminanceSurfacePointData * dat);

//----------------------------------------------------------------------------------------
/// Callback definition for hooks passed to VolumeData::IlluminanceSimple(). Called during illuminance calculations.
/// @param[in] sd									The volume data for the point being calculated. @cinemaOwnsPointed{volume data}
/// @param[in] rlc								The light data cache for the point being calculated. @cinemaOwnsPointed{data}
/// @param[in] dat								The data sent to VolumeData::IlluminanceSimple(). @callerOwnsPointed{data}
//----------------------------------------------------------------------------------------
typedef void IlluminationModel (VolumeData * sd, RayLightCache * rlc, void* dat);

struct IlluminanceSurfacePointData
{
	Vector64											p,											///< Global point.
																bumpn,									///< Bump normal.
																phongn,									///< Phong normal.
																orign,									///< Original normal.
																ray_vector;							///< Ray vector.
	Float													specular_exponent;			///< Specular exponent.
	Int32													receive_gi;							///< Receive GI.
	Bool													receive_caustics,				///< Receive caustics.
																cosine_cutoff,					///< Defines whether the calculation shall check for light/camera being on the same side or not.\n
																												///< If @formatConstant{false} illumination model samples the light from all directions. If @formatConstant{true} illumination model samples like it was a surface point.\n
																												///< If @formatConstant{true}, add special code for the area light handling (as the light/camera situation is different for every subsample of an area light). That is where the call VolumeData::CalcArea() is necessary.
																calc_shadow;						///< Enables shadow calculation.
	RAYBIT												raybits;								///< Ray bits: @enumerateEnum{RAYBIT}
	RayHitID											lhit;										///< Global RayHitID structure for the surface intersection (to avoid self shadowing).\n
																												///< Can be set to RayHitID() if you do not have the current RayHitID.

	void*													local_mat;							///< The material where all the GI and caustic properties are taken from.

	IlluminanceSurfacePointModel*	model;									///< The custom illumination model.
	void*													customdata;							///< Custom data for the illumination model.
};



/// @addtogroup RaytraceMotionInformation
/// @ingroup group_enumeration
/// @{
/// Motion Blur information [READ ONLY].
/// @since R17.032
#define RAY_MOTION_MATRIX					0x01			///< Matrix.
#define RAY_MOTION_POINTS					0x02			///< Points.
#define RAY_MOTION_COPIES					0x04			///< Copies.
#define RAY_MOTION_DUPLICATE			0x10			///< Duplicates.
#define RAY_MOTION								(RAY_MOTION_MATRIX | RAY_MOTION_POINTS)			///< @ref RAY_MOTION_MATRIX | @ref RAY_MOTION_POINTS.
/// @}

/// @addtogroup RaytraceMotionBlurLightMatrices
/// @ingroup group_enumeration
/// @{
/// Motion Blur light matrices.
/// @since R17.032
#define RAY_MOTION_LIGHT_MATRIX													0x00			///< Light matrix.
#define RAY_MOTION_LIGHT_MATRIX_INV											0x01			///< Inverted light matrix.
#define RAY_MOTION_LIGHT_MATRIX_DISTORTED								0x02			///< Distorted matrix.
#define RAY_MOTION_LIGHT_MATRIX_NOISE										0x03			///< Noise matrix.
#define RAY_MOTION_LIGHT_MATRIX_AREA_OBJECT							0x04			///< Object matrix for area lights.
#define RAY_MOTION_LIGHT_MATRIX_LAST										0x05			///< Last matrix index.
/// @}

/// @addtogroup RaytraceMotionBlurLightVectors
/// @ingroup group_enumeration
/// @{
/// Motion Blur light vectors.
/// @since R17.032
#define RAY_MOTION_LIGHT_VECTOR_COLOR										0x00			///< Light color.
#define RAY_MOTION_LIGHT_VECTOR_AREA_RADIUS							0x01			///< Area radius.
#define RAY_MOTION_LIGHT_VECTOR_NOISE_SCALE							0x02			///< Noise scale.
#define RAY_MOTION_LIGHT_VECTOR_NOISE_WIND							0x03			///< Noise wind effect.
#define RAY_MOTION_LIGHT_VECTOR_SHADOW_COLOR						0x04			///< Shadow color.
#define RAY_MOTION_LIGHT_VECTOR_VISIBLE_COLOR						0x05			///< Visible light color.
#define RAY_MOTION_LIGHT_VECTOR_LAST										0x06			///< Last vector index
/// @}

/// @addtogroup RaytraceMotionBlurLightFloats
/// @ingroup group_enumeration
/// @{
/// Motion Blur light floats.
/// @since R17.032
#define RAY_MOTION_LIGHT_FLOAT_SPOT_ANGLE_INNER					0x00			///< The inner angle of light cone.
#define RAY_MOTION_LIGHT_FLOAT_SPOT_ANGLE_OUTER					0x01			///< The outer angle of light cone.
#define RAY_MOTION_LIGHT_FLOAT_SPOT_ASPECT_RATIO				0x02			///< The Y distortion.

#define RAY_MOTION_LIGHT_FLOAT_FALLOFF_RADIUS_INNER			0x03			///< Falloff inner radius.
#define RAY_MOTION_LIGHT_FLOAT_FALLOFF_RADIUS_OUTER			0x04			///< Falloff outer radius.
#define RAY_MOTION_LIGHT_FLOAT_FALLOFF_DISTANCE_INNER		0x05			///< Falloff inner distance.
#define RAY_MOTION_LIGHT_FLOAT_FALLOFF_DISTANCE_OUTER		0x06			///< Falloff outer distance.
#define RAY_MOTION_LIGHT_FLOAT_FALLOFF_ENERGY_LEVEL			0x07			///< Falloff energy level.

#define RAY_MOTION_LIGHT_FLOAT_CLIPPING_NEAR_FROM				0x08			///< Near clipping start.
#define RAY_MOTION_LIGHT_FLOAT_CLIPPING_NEAR_TO					0x09			///< Near clipping end.
#define RAY_MOTION_LIGHT_FLOAT_CLIPPING_FAR_FROM				0x0A			///< Far clipping start.
#define RAY_MOTION_LIGHT_FLOAT_CLIPPING_FAR_TO					0x0B			///< Far clipping end.

#define RAY_MOTION_LIGHT_FLOAT_AREA_FALLOFF_ANGLE				0x0C			///< Area falloff angle.
#define RAY_MOTION_LIGHT_FLOAT_AREA_INFINITE_ANGLE			0x0D			///< Infinite area angle.

#define RAY_MOTION_LIGHT_FLOAT_GRADIENT_MULTIPLIER			0x10			///< Gradient multiplier.
#define RAY_MOTION_LIGHT_FLOAT_CONTRAST_TRN							0x11			///< Contrast.

// Noise
#define RAY_MOTION_LIGHT_FLOAT_NOISE_OCTAVES						0x12			///< Noise octaves.
#define RAY_MOTION_LIGHT_FLOAT_NOISE_VELOCITY						0x13			///< Noise speed.
#define RAY_MOTION_LIGHT_FLOAT_NOISE_BRIGHTNESS					0x14			///< Noise brightness.
#define RAY_MOTION_LIGHT_FLOAT_NOISE_CONTRAST						0x15			///< Noise contrast.
#define RAY_MOTION_LIGHT_FLOAT_NOISE_ISCALE							0x16			///< Noise illumination scale.
#define RAY_MOTION_LIGHT_FLOAT_NOISE_WIND_VELOCITY			0x17			///< Noise wind velocity.

// Shadow
#define RAY_MOTION_LIGHT_FLOAT_SHADOW_DENSITY						0x18			///< Shadow density.

// Area Shadow
#define RAY_MOTION_LIGHT_FLOAT_AREA_SHADOW_NEAR_OFFSET	0x19			///< Area shadow near offset.
#define RAY_MOTION_LIGHT_FLOAT_AREA_SHADOW_ACCURACY			0x1A			///< Area shadow accuracy.

// Visible
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_LEFT							0x20			///< Visible light screen region left value.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_TOP							0x21			///< Visible light screen region top value.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_RIGHT						0x22			///< Visible light screen region right value.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_BOTTOM						0x23			///< Visible light screen region bottom value.

#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_NEAR_FROM				0x24			///< Visible light near clipping start.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_NEAR_TO					0x25			///< Visible light near clipping end.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_FAR_FROM					0x26			///< Visible light far clipping start.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_FAR_TO						0x27			///< Visible light far clipping end.

#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_FO_SUB						0x28			///< Visible light falloff "sub" value.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_FO_MUL						0x29			///< Visible light falloff "mul" value.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_FO_STRENGTH			0x2A			///< Visible light adjusted falloff strength.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_FE_SUB						0x2B			///< Visible light adjusted edge falloff "sub" value.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_FE_MUL						0x2C			///< Visible light adjusted edge falloff "mul" value.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_FE_STRENGTH			0x2D			///< Visible light adjusted edge falloff strength.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_INNER_SUB				0x2E			///< Visible light ratio of inner to outer distance.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_INNER_MUL				0x2F			///< Visible light inverted ratio of inner to outer distance.

#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_SAMPLE_DIST			0x30			///< Visible light sample distance.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_BRIGHT						0x31			///< Visible light brightness.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_BRIGHT_AOI				0x32			///< Visible light brightness normalization.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_BRIGHTNESS_MUL		0x33			///< Visible light brightness multiplier.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_DITHERING				0x34			///< Visible light dithering.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_DUST							0x35			///< Visible light dust effect.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_TAN							0x36			///< Visible light tangent of the outer angle.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_TAN_SQUARE				0x37			///< Visible light tangent of the outer angle (squared).
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_ORAD							0x38			///< Visible light outer radius.
#define RAY_MOTION_LIGHT_FLOAT_VISIBLE_ORAD_SQAURE			0x39			///< Visible light outer radius (squared).

// Last Index
#define RAY_MOTION_LIGHT_FLOAT_LAST											0x40			///< Last float index.
/// @}

//----------------------------------------------------------------------------------------
/// Motion Blur normal vectors (stored as ::Int16).
/// @since R17.032
//----------------------------------------------------------------------------------------
struct RayMotionNormal
{
	//----------------------------------------------------------------------------------------
	/// Default constructor;
	//----------------------------------------------------------------------------------------
	RayMotionNormal()
	{
		normal[0] = 0;
		normal[1] = 0;
		normal[2] = 0;
	}

	Int16										normal[3];			///< The normal vectors.
};

//----------------------------------------------------------------------------------------
/// Motion Blur polygon normals.
/// @since R17.032
//----------------------------------------------------------------------------------------
struct RayMotionPolyNormal
{
	RayMotionNormal					poly_normals[4];			///< The normals.
};

//----------------------------------------------------------------------------------------
/// Motion Blur matrix data.
/// @since R17.032
//----------------------------------------------------------------------------------------
struct RayMotionMatrixData
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	RayMotionMatrixData() { }

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] src								The source RayMotionMatrixData.
	//----------------------------------------------------------------------------------------
	RayMotionMatrixData(RayMotionMatrixData&& src) :
		position(std::move(src.position)), rotation(std::move(src.rotation)),
		scale(std::move(src.scale)), order(src.order) { }

	//----------------------------------------------------------------------------------------
	/// Assignment operator.
	/// @param[in] src								The source RayMotionMatrixData.
	//----------------------------------------------------------------------------------------
	MAXON_OPERATOR_MOVE_ASSIGNMENT(RayMotionMatrixData);

public:
	Vector									position;			///< The position.
	Vector									rotation;			///< The rotation.
	Vector									scale;				///< The scale.
	ROTATIONORDER						order;				///< The order.
};

//----------------------------------------------------------------------------------------
/// Motion Blur matrix.
/// @since R17.032
//----------------------------------------------------------------------------------------
struct RayMotionMatrix
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	RayMotionMatrix() { }

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] src								The source RayMotionMatrix.
	//----------------------------------------------------------------------------------------
	RayMotionMatrix(RayMotionMatrix&& src) :
		_motion_data(std::move(src._motion_data)), motion_matrix(std::move(src.motion_matrix)), motion_matrix_inv(std::move(src.motion_matrix_inv)),
		global(std::move(src.global)), global_rotation(std::move(src.global_rotation)), global_length(std::move(src.global_length)) { }

	//----------------------------------------------------------------------------------------
	/// Assignment operator.
	/// @param[in] src								The source RayMotionMatrix.
	//----------------------------------------------------------------------------------------
	MAXON_OPERATOR_MOVE_ASSIGNMENT(RayMotionMatrix);

	/// Motion data.
	maxon::BaseArray<RayMotionMatrixData> _motion_data;

	Matrix64								motion_matrix;					///< Motion matrix.
	Matrix64								motion_matrix_inv;			///< Motion inverted matrix.

	Matrix64								global;									///< Motion global matrix
	Vector64								global_rotation;				///< Motion global rotation.
	Vector64								global_length;					///< Motion global length.
};

//----------------------------------------------------------------------------------------
/// Motion Blur texture frame.
/// @since R17.032
//----------------------------------------------------------------------------------------
struct RayMotionTextureFrame
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	RayMotionTextureFrame()
	{
		offset_x			= 0.0;
		offset_y			= 0.0;
		scale_x				= 0.0;
		scale_y				= 0.0;
		scale_inv_x		= 0.0;
		scale_inv_y		= 0.0;
		repetition_x	= 0.0;
		repetition_y	= 0.0;
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] src								The source RayMotionTextureFrame.
	//----------------------------------------------------------------------------------------
	RayMotionTextureFrame(RayMotionTextureFrame&& src) :
		matrix(std::move(src.matrix)), matrix_inv(std::move(src.matrix_inv)), camera_matrix(std::move(src.camera_matrix)),
		camera_matrix_inv(std::move(src.camera_matrix_inv))
	{
			offset_x				  = src.offset_x;
			offset_y				  = src.offset_y;
			scale_x					  = src.scale_x;
			scale_y					  = src.scale_y;
			scale_inv_x			  = src.scale_inv_x;
			scale_inv_y			  = src.scale_inv_y;
			repetition_x		  = src.repetition_x;
			repetition_y		  = src.repetition_y;
	}

public:
	Matrix									matrix;									///< Matrix.
	Matrix									matrix_inv;							///< Inverted matrix.
	Matrix									camera_matrix;					///< Camera matrix.
	Matrix									camera_matrix_inv;			///< Inverted camera matrix.
	Float										offset_x;								///< Offset X.
	Float										offset_y;								///< Offset Y.
	Float										scale_x;								///< Scale X.
	Float										scale_y;								///< Scale Y.
	Float										scale_inv_x;						///< Inverted scale X.
	Float										scale_inv_y;						///< Inverted scale Y.
	Float										repetition_x;						///< Repetition X.
	Float										repetition_y;						///< Repetition Y.
};

//----------------------------------------------------------------------------------------
/// Motion Blur texture.
/// @since R17.032
//----------------------------------------------------------------------------------------
struct RayMotionTexture
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(RayMotionTexture);
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	RayMotionTexture() { }

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] src								The source RayMotionTexture.
	//----------------------------------------------------------------------------------------
	RayMotionTexture(RayMotionTexture&& src) : _texture_frames_data(std::move(src._texture_frames_data)) { }

public:
	maxon::BaseArray<RayMotionTextureFrame>	_texture_frames_data;			///< Texture frames data.
};

//----------------------------------------------------------------------------------------
/// Motion Blur object.
/// @since R17.032
//----------------------------------------------------------------------------------------
struct RayMotionObject
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	RayMotionObject()
	{
		_motionFlags								= 0;
		_motionFrames								= 0;
		_motionPointsCount					= 0;
		_motionSpdCount							= 0;
		_motionTexPointsCount				= 0;
		_motionNormalsCount					= 0;
		_motionNormalsPhongCount		= 0;
		_motionSubNormalsCount			= 0;
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] src								The source RayMotionObject.
	//----------------------------------------------------------------------------------------
	RayMotionObject(RayMotionObject&& src) :
		_motionFlags(src._motionFlags), _motionFrames(src._motionFrames), _motionMatrixRef(std::move(src._motionMatrixRef)),
		_motionMatrixRefInv(std::move(src._motionMatrixRefInv)), _texturesData(std::move(src._texturesData)),
		_motionData(std::move(src._motionData)), _motionPointsData(std::move(src._motionPointsData)), _motionPointsCount(src._motionPointsCount),
		_motionSpdPoints(std::move(src._motionSpdPoints)), _motionSpdCooefs(std::move(src._motionSpdCooefs)), _motionSpdCount(src._motionSpdCount),
		_motionTexPointsData(std::move(src._motionTexPointsData)), _motionTexPointsCount(src._motionTexPointsCount), _motionNormalsData(std::move(src._motionNormalsData)),
		_motionNormalsCount(src._motionNormalsCount), _motionNormalsPhongData(std::move(src._motionNormalsPhongData)), _motionNormalsPhongCount(src._motionNormalsPhongCount),
		_motionSubNormalsData(std::move(src._motionSubNormalsData)), _motionSubNormalsCount(src._motionSubNormalsCount) { }

	//----------------------------------------------------------------------------------------
	/// Assignment operator.
	/// @param[in] src								The source RayMotionObject.
	//----------------------------------------------------------------------------------------
	MAXON_OPERATOR_MOVE_ASSIGNMENT(RayMotionObject);

public:
	Int32																	_motionFlags;								///< Flags.
	Int32																	_motionFrames;							///< Frames.

	Matrix64															_motionMatrixRef;						///< Reference matrix.
	Matrix64															_motionMatrixRefInv;				///< Reference inverse matrix.

	maxon::BaseArray<RayMotionTexture>		_texturesData;							///< Textures data.
	maxon::BaseArray<RayMotionMatrix>			_motionData;								///< Motion matrices.

	maxon::BaseArray<Vector32>						_motionPointsData;					///< Motion vectors for each subframe.
	Int32																	_motionPointsCount;					///< Motion vector count for each frame.

	maxon::BaseArray<Vector32>						_motionSpdPoints;						///< SPD Points for each subframe.
	maxon::BaseArray<Vector32>						_motionSpdCooefs;						///< SPD Points for each subframe.
	Int32																	_motionSpdCount;						///< SPD Points / Coefs count per frame.

	maxon::BaseArray<Vector32>						_motionTexPointsData;				///< Texture points (@ref StickTextureTag).
	Int32																	_motionTexPointsCount;			///< Texture Points count per frame.

	maxon::BaseArray<RayMotionPolyNormal>	_motionNormalsData;					///< Motion normals for each subframe.
	Int32																	_motionNormalsCount;				///< Motion normals count for each frame.

	maxon::BaseArray<RayMotionPolyNormal>	_motionNormalsPhongData;		///< Motion phong normals for each subframe.
	Int32																	_motionNormalsPhongCount;		///< Motion phong normals count for each frame.

	maxon::BaseArray<RayMotionNormal>			_motionSubNormalsData;			///< Motion SPD normals for each subframe.
	Int32																	_motionSubNormalsCount;			///< Motion SPD normals count for each frame.
};

//----------------------------------------------------------------------------------------
/// Motion Blur light frame.
/// @since R17.032
//----------------------------------------------------------------------------------------
struct RayMotionLightFrame
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	RayMotionLightFrame()
	{
		for (Float64& f : _float)
			f = 0.0;
	}

	Matrix64								_matrix[RAY_MOTION_LIGHT_MATRIX_LAST];			///< Matrices.
	Vector64								_vector[RAY_MOTION_LIGHT_VECTOR_LAST];			///< Vectors.
	Float64									_float[RAY_MOTION_LIGHT_FLOAT_LAST];				///< Floats.
};

//----------------------------------------------------------------------------------------
/// Motion Blur light.
/// @since R17.032
//----------------------------------------------------------------------------------------
struct RayMotionLight
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(RayMotionLight);
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	RayMotionLight() { }

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] src								The source RayMotionLight.
	//----------------------------------------------------------------------------------------
	RayMotionLight(RayMotionLight&& src) : _lightFrames(std::move(src._lightFrames)) { }

	//----------------------------------------------------------------------------------------
	/// Assignment operator.
	/// @param[in] src								The source RayMotionLight.
	//----------------------------------------------------------------------------------------
	MAXON_OPERATOR_MOVE_ASSIGNMENT(RayMotionLight);

public:
	maxon::BaseArray<RayMotionLightFrame> _lightFrames;			///< The light frames.
};

//----------------------------------------------------------------------------------------
/// Motion Blur camera frame.
/// @since R17.032
//----------------------------------------------------------------------------------------
struct RayMotionCameraFrame
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	RayMotionCameraFrame()
	{
		frame_time						= 0.0f;
		projection						= 0;
		delta_x								= 0;
		delta_y								= 0;
		flag_exposure					= false;
		flag_dof							= false;
		scale_x								= 0.0;
		scale_y								= 0.0;
		zoom									= 0.0;
		focal_length					= 0.0;
		aperture							= 0.0;
		aperture_size					= 0.0;
		target_distance				= 0.0;
		f_number							= 0.0;
		exposure_iso					= 0.0;
		exposure_gain					= 0.0;
		bokeh									= false;
		bokeh_blades					= 0;
		bokeh_rotation				= 0.0;
		bokeh_bias						= 0.0;
		bokeh_anisotropy			= 0.0;
		film_offset_x					= 0.0;
		film_offset_y					= 0.0;
		white_balance					= 0.0;
		white_balance_lights	= false;
		vignetting_intensity	= 0.0;
		vignetting_offset			= 0.0;
		lens_distortion_quad	= 0.0;
		lens_distortion_cubic	= 0.0;
		chromatic_strength		= 0.0;
		clipping_near_enabled	= false;
		clipping_far_enabled	= false;
		clipping_near_value		= 0.0;
		clipping_far_value		= 0.0;
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] src								The source RayMotionCameraFrame.
	//----------------------------------------------------------------------------------------
	RayMotionCameraFrame(const RayMotionCameraFrame& src)
	{
		frame_time						= src.frame_time;
		projection						= src.projection;
		delta_x								= src.delta_x;
		delta_y								= src.delta_y;
		flag_exposure					= src.flag_exposure;
		flag_dof							= src.flag_dof;
		matrix								= std::move(src.matrix);
		offset								= std::move(src.offset);
		scale_x								= src.scale_x;
		scale_y								= src.scale_y;
		zoom									= src.zoom;
		focal_length					= src.focal_length;
		aperture							= src.aperture;
		aperture_size					= src.aperture_size;
		target_distance				= src.target_distance;
		f_number							= src.f_number;
		exposure_iso					= src.exposure_iso;
		exposure_gain					= src.exposure_gain;
		bokeh									= src.bokeh;
		bokeh_blades					= src.bokeh_blades;
		bokeh_rotation				= src.bokeh_rotation;
		bokeh_bias						= src.bokeh_bias;
		bokeh_anisotropy			= src.bokeh_anisotropy;
		film_offset_x					= src.film_offset_x;
		film_offset_y					= src.film_offset_y;
		white_balance					= src.white_balance;
		white_balance_lights	= src.white_balance_lights;
		vignetting_intensity	= src.vignetting_intensity;
		vignetting_offset			= src.vignetting_offset;
		lens_distortion_quad	= src.lens_distortion_quad;
		lens_distortion_cubic	= src.lens_distortion_cubic;
		chromatic_strength		= src.chromatic_strength;
		clipping_near_enabled	= src.clipping_near_enabled;
		clipping_far_enabled	= src.clipping_far_enabled;
		clipping_near_value		= src.clipping_near_value;
		clipping_far_value		= src.clipping_far_value;
		_spcInfo							= src._spcInfo;
	}

public:
	Float32									frame_time;									///< Frame time.

	// Projection
	Int32										projection;									///< Projection.

	// Image Delta
	Int32										delta_x;										///< Delta X.
	Int32										delta_y;										///< Delta Y.

	// Flags
	Bool										flag_exposure;							///< Flag for exposure.
	Bool										flag_dof;										///< Flag for DOF.

	// Matrix and Scale
	Matrix64								matrix;											///< Matrix.
	Vector64								offset;											///< Offset.
	Float64									scale_x;										///< Scale X.
	Float64									scale_y;										///< Scale Y.
	Float64									zoom;												///< Zoom.

	// Focal Length and Film Gate
	Float64									focal_length;								///< Focal length.
	Float64									aperture;										///< Aperture.
	Float64									aperture_size;							///< Aperture size. Computed.

	// Target Distance
	Float64									target_distance;						///< Target distance.

	// F-Number
	Float64									f_number;										///< F-number.

	// Exposure
	Float64									exposure_iso;								///< Exposure iso.
	Float64									exposure_gain;							///< Exposure gain.

	// Aperture Shape (Bokeh)
	Bool										bokeh;											///< Bokeh (Aperture Shape).
	Int32										bokeh_blades;								///< Bokeh blades.
	Float										bokeh_rotation;							///< Bokeh rotation.
	Float										bokeh_bias;									///< Bokeh bias.
	Float										bokeh_anisotropy;						///< Bokeh anisotropy.

	// Film Offset
	Float64									film_offset_x;							///< Film offset X.
	Float64									film_offset_y;							///< Film offset Y.

	// White Balance
	Float64									white_balance;							///< White balance.
	Bool										white_balance_lights;				///< White balance lights.

	// Vignetting
	Float64									vignetting_intensity;				///< Vignetting intensity.
	Float64									vignetting_offset;					///< Vignetting offset.

	// Lens Distortion
	Float64									lens_distortion_quad;				///< Lens distortion quad.
	Float64									lens_distortion_cubic;			///< Lens distortion cubic.

	// Chromatic Aberration
	Float64									chromatic_strength;					///< Chromatic aberration strength.

	// Clipping
	Bool										clipping_near_enabled;			///< Clipping near enabled.
	Bool										clipping_far_enabled;				///< Clipping far enabled.
	Float64									clipping_near_value;				///< Clipping near value.
	Float64									clipping_far_value;					///< Clipping far value.

	// Spherical Camera (SPC) 
	SpcInfo									_spcInfo;										///< Spherical Camera (SPC) parameters. @since R19
}; // struct RayMotionCameraFrame

//----------------------------------------------------------------------------------------
/// Motion Blur camera.
//----------------------------------------------------------------------------------------
struct RayMotionCamera
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	RayMotionCamera() { }

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] src								The source RayMotionCameraFrame.
	//----------------------------------------------------------------------------------------
	RayMotionCamera(RayMotionCamera&& src) : _cameraFramesData(std::move(src._cameraFramesData)) { }

	maxon::BaseArray<RayMotionCameraFrame> _cameraFramesData;			///< The camera frames data.
};

#endif // C4D_RAYTRACE_H__
