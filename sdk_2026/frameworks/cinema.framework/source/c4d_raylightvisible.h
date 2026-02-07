/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef __C4D_RAYLIGHTVISIBLE__
#define __C4D_RAYLIGHTVISIBLE__

#include "maxon/gradient.h"
#include "c4d_ray_objectrestriction.h"

namespace cinema
{

class CINEWARE_SINGLEINHERITANCE BaseObject;
struct RayPolygon;
struct TexList;

struct RayLightNoise
{
protected:
	RayLightNoise();

public:
	Int32 type;					///< The noise algorithm type.
	Float octaves;			///< The noise octaves.
	Float velocity;			///< The noise speed.
	Float brightness;		///< The noise brightness.
	Float contrast;			///< The noise contrast.
	Bool local;					///< @formatConstant{true} for local noise.
	Vector scale;				///< The noise scale.
	Float iscale;				///< The illumination scale.
	Vector wind;				///< The wind effect.
	Float windvelocity; ///< The wind velocity.
};

struct RayLightCaustics
{
protected:
	RayLightCaustics();

public:
	Bool cs_enable;		///< enable surface caustics
	Float cs_energy;	///< The caustic energy.
	Int32 cs_photons; ///< The number of photons.

	Bool vcs_enable;	 ///< @formatConstant{true} to enable volume caustics.
	Float vcs_energy;	 ///< The volume caustic energy.
	Int32 vcs_photons; ///< The number of volume photons.

	Int32 falloff;		 ///< The caustic light falloff.
	Float innerradius; ///< The inner radius.
	Float outerradius; ///< The outer radius.
};

struct RayLightShadow
{
protected:
	RayLightShadow();

public:
	Float density;					///< The shadow density.
	Vector color;						///< The shadow color.
	Bool transparency;			///< @formatConstant{true} if the shadow supports transparency.
	Bool clippinginfluence; ///< @formatConstant{true} to evaluate clipping areas.

	Int32 mapsizex,			 ///< The soft shadow map horizontal resolution.
		mapsizey;					 ///< The soft shadow map vertical resolution.
	Float bias;					 ///< The soft shadow bias.
	Bool absolute;			 ///< The absolute bias.
	Int32 sampleradius;	 ///< The soft shadow sample radius.
	Float parallelwidth; ///< The soft shadow parallel width.
	Bool outline;				 ///< The outline soft shadow.

	Bool shadowcone; ///< The soft shadow cone.
	Float coneangle; ///< The soft shadow cone angle.
	Bool softcone;	 ///< @formatConstant{true} for soft falloff at the edges.

	Float accuracy;		///< The area shadow accuracy.
	Int32 minsamples; ///< The area shadow min samples.
	Int32 maxsamples; ///< The area shadow max samples.

	Bool highquality;		 ///< The soft shadow omni light is calculated with the best quality.
	Int32 samplingBoost; ///< The soft shadow sampling boost.
};

struct RayLightVisible
{
protected:
	RayLightVisible();

public:
	Bool falloff;								 ///< Falloff.
	Float strength;							 ///< Falloff strength.
	Bool edgefalloff;						 ///< Edge falloff.
	Float edgestrength;					 ///< Edge falloff strength.
	Bool colfalloff;						 ///< Colored edge falloff.
	Float innerdistance;				 ///< Inner distance.
	Vector outerdistance;				 ///< Outer distance.
	Float sampledistance;				 ///< Sample distance.
	Float brightness_multiplier; ///< Brightness multiplier.
	Float dust;									 ///< Dust effect.
	Float dithering;						 ///< Dithering.
	Bool adaptbrightness;				 ///< Adapt brightness (angle based brightness scale).
	Bool additive;							 ///< Additive visible light.
	Vector color;								 ///< Color.

	maxon::GradientRenderData cgradient; ///< Color gradient.
};

struct RayLight
{
protected:
	RayLight();

public:
	RayLightNoise* ln;	 ///< The light noise structure. Always valid, not @formatConstant{nullptr}.
	RayLightShadow* ls;	 ///< The shadow structure. Always valid, not @formatConstant{nullptr}.
	RayLightVisible* lv; ///< The visible light structure. Always valid, not @formatConstant{nullptr}.
	BaseObject* link;		 ///< The link to the 'real' light object.

	Bool calc_illum;		///< @formatConstant{true} if the light source illuminates.
	Matrix64 m;					///< The light matrix.
	Matrix64 m_inverse; ///< The inverse light matrix.

	Int32 type;				 ///< The type of light source: @enumerateEnum{RaytraceLightTypes}
	Int32 stype;			 ///< The shadow type: @enumerateEnum{RaytraceShadowTypes}
	Int32 vtype;			 ///< The type of visible light: @enumerateEnum{RaytraceVisibleLight}
	Int32 ntype;			 ///< The type of noise for illumination/visible light: @enumerateEnum{RaytraceLightNoise}
	Int32 falloff;		 ///< The type of light falloff: @enumerateEnum{RaytraceLightFalloff}
	Float innerangle;	 ///< The inner angle of light cone, only relevant if the light source is a spot.
	Float outerangle;	 ///< The outer angle of light cone, only relevant if the light source is a spot.
	Float innerradius; ///< The inner radius of light cylinder, only relevant if the light source is a parallel spot.
	Float outerradius; ///< The outer radius of light cylinder, only relevant if the light source is a parallel spot.
	Float aspectratio; ///< The Y distortion, to get the resulting matrix system multiply by @c m.sqmat.v2.
	Bool arealight;		 ///< @formatConstant{true} if the light source acts as arealight.
	Bool ambient;			 ///< The light source illuminates ambient light.
	Bool nodiffuse;		 ///< The light source does not affect the diffuse component.
	Bool nospecular;	 ///< The light source does not affect the specular component.
	Bool nogi;				 ///< The light source does not affect GI.
	Bool innercolor;	 ///< @formatConstant{true} if the inner color is used.
	Bool colfalloff;	 ///< Edge color falloff.
	Bool negative;		 ///< @formatConstant{true} if the light source subtracts intensity.
	Float contrast;		 ///< The light contrast.
	Float innerdist;	 ///< The inner distance, only important if falloff is set.
	Float outerdist;	 ///< The outer distance, only important if falloff is set.
	Vector color;			 ///< The light color, only important if @ref innercolor is set.
	Bool nearclip;		 ///< Near clipping.
	Bool farclip;			 ///< Far clipping.
	Float nearfrom;		 ///< Near clipping start.
	Float nearto;			 ///< Near clipping end.
	Float farfrom;		 ///< Far clipping start.
	Float farto;			 ///< Far clipping end.
	Vector lens_color; ///< Color for the lens flares.

	RayLightCaustics* lc;	 ///< The caustics structure. Always valid, not @formatConstant{nullptr}.
	Bool separatepass;		 ///< @formatConstant{true} if render as separate multipass.
	Float trn;						 ///< Exp (-contrast).
	Int32 multipass_index; ///< Index into multipass light field (or @ref NOTOK).

	ObjectRestriction lr; ///< Light restriction.

	void* userdata; ///< Only to be used by plugin renderers.

	Bool onlyz; ///< Only Z.

	Vector arearadius; ///< Area radius.
	Int32 areashape;	 ///< Area shape. (See olight.h, @ref LIGHT_AREADETAILS_SHAPE.)
	Int32 areasamples; ///< Number of area samples.
	Bool areaaddgrain; ///< @formatConstant{true} to add area grain.

	const Vector* area_padr;		 ///< Area points.
	Int32 area_pcnt;						 ///< Number of area points.
	const RayPolygon* area_vadr; ///< Area polygons.
	Int32 area_vcnt;						 ///< Number of area polygons.
	BaseObject* area_link;			 ///< Area link.
	Matrix* area_matrix;				 ///< Area matrix.
	Bool shadowcaster;					 ///< Shadow caster.
	Float area_falloffangle;		 ///< Area falloff angle.
	Float area_infiniteangle;		 ///< Infinite area angle.
	Bool area_showinrender;			 ///< Show area light in render.
	Bool area_showinreflection;	 ///< Show area light in render.
	Vector area_backcolor;			 ///< Area light back color. @since R19

	maxon::GradientRenderData cgradient; ///<	Color gradient.

	Float gradient_multiplier; ///< Gradient multiplier.
	Float lens_imul;					 ///< Lens multiplier.

	TexList* texadr; ///< Texture address. Can be @formatConstant{nullptr}, always check.
									 ///< @note It is not possible to access textures directly. Use VolumeData::GetTexData() instead.
	Int32 texcnt;		 ///< Texture count.
};

struct RayNoiseStruct : public RayLightNoise
{
};

struct RayShadowStruct : public RayLightShadow
{
};

struct RayCaustics : public RayLightCaustics
{
};

struct RayVLStruct : public RayLightVisible
{
};

} // namespace cinema



#endif // __C4D_RAYLIGHTVISIBLE__
