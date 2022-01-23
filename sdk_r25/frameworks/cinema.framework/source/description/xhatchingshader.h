#ifndef XHATCHINGSHADER_H__
#define XHATCHINGSHADER_H__

enum
{
	HATCHINGSHADER_GROUP_LIGHTING = 2000,
	HATCHINGSHADER_GROUP_COLOR,

	HATCHINGSHADER_BUMP = 10000,
	HATCHINGSHADER_SCALE,
	HATCHINGSHADER_SCALE_U,
	HATCHINGSHADER_SCALE_V,
	HATCHINGSHADER_TEXTURE,
	HATCHINGSHADER_ROTATE,
	HATCHINGSHADER_DENSITY,
	HATCHINGSHADER_DENSITY_U,
	HATCHINGSHADER_DENSITY_V,
	HATCHINGSHADER_SCATTER_U,
	HATCHINGSHADER_SCATTER_V,
	HATCHINGSHADER_SPACE_U,
	HATCHINGSHADER_SPACE_U_VAR,
	HATCHINGSHADER_SPACE_V,
	HATCHINGSHADER_SPACE_V_VAR,
	HATCHINGSHADER_SCALE_U_VAR,
	HATCHINGSHADER_SCALE_V_VAR,
	HATCHINGSHADER_ROTATE_VAR,
	HATCHINGSHADER_CROSSED,
	HATCHINGSHADER_CROSS_ROTATE,
	HATCHINGSHADER_STOKE_ROTATE,
	HATCHINGSHADER_OFFSET_U,
	HATCHINGSHADER_OFFSET_V,
	HATCHINGSHADER_LEVELS,
	HATCHINGSHADER_THRESHOLD,

	HATCHINGSHADER_STROKE_COLOR,
	HATCHINGSHADER_BACK_COLOR,
	HATCHINGSHADER_SHADOW,
	HATCHINGSHADER_DIFFUSE,
	HATCHINGSHADER_SPEC,
	HATCHINGSHADER_ILLUM,
	HATCHINGSHADER_CAMERA,
	HATCHINGSHADER_LIGHTS,
	HATCHINGSHADER_SPECULAR,
	HATCHINGSHADER_ILLUMINATION,
	HATCHINGSHADER_SHADOWS,
	HATCHINGSHADER_STROKELIGHT_COLOR,
	HATCHINGSHADER_DARK_STROKES,
	HATCHINGSHADER_LIGHT_STROKES,
	HATCHINGSHADER_BRIGHTNESS,
	HATCHINGSHADER_CONTRAST,

	HATCHINGSHADER_TILE,
	HATCHINGSHADER_ROTATIONAL,

	HATCHINGSHADER_INCEXC,
	HATCHINGSHADER_INCEXC_LIGHTS,

	//

	HATCHINGSHADER_INCEXC_INCLUDE = 0,
	HATCHINGSHADER_INCEXC_EXCLUDE
};

#endif // XHATCHINGSHADER_H__