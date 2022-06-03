#ifndef XCELSHADER_H__
#define XCELSHADER_H__

enum
{
	CELSHADER_SHADOW = 10000,
	CELSHADER_DIFFUSE,
	CELSHADER_SPEC,
	CELSHADER_CAMERA,
	CELSHADER_LIGHTS,
	CELSHADER_ILLUMINATION,
	CELSHADER_SHADOWS,
	CELSHADER_DUMMY,
	CELSHADER_BUMP,
	CELSHADER_ILLUM,
	CELSHADER_SPECULAR,
	CELSHADER_LIGHTSCOL,
	CELSHADER_INCEXC,
	CELSHADER_INCEXC_LIGHTS,

	CELSHADER_SHADOWSTYPE,
	CELSHADER_SHADOWSMODE,

	CELSHADER_SHADOWSMODE_INV,
	CELSHADER_BACKFACE,

	//

	CELSHADER_INCEXC_INCLUDE = 0,
	CELSHADER_INCEXC_EXCLUDE,

	CELSHADER_SHADOWSTYPE_MULTIPLY = 0,
	CELSHADER_SHADOWSTYPE_COLOR,
	CELSHADER_SHADOWSTYPE_LIGHTS,

	CELSHADER_SHADOWSMODE_NORMAL = 0,
	CELSHADER_SHADOWSMODE_H,
	CELSHADER_SHADOWSMODE_S,
	CELSHADER_SHADOWSMODE_V
};

#endif // XCELSHADER_H__