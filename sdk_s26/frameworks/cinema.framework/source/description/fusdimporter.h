#ifndef FUSDIMPORTER_H__
#define FUSDIMPORTER_H__

enum
{
	USDIMPORTER_GROUP						= 999,

	USDIMPORTER_GRP_GENERAL,
	USDIMPORTER_KEEPBRIDGEOPEN,
	USDIMPORTER_CAMERAS,
	USDIMPORTER_LIGHTUNITS,
		USDIMPORTER_LIGHTUNITS_NONE,
		USDIMPORTER_LIGHTUNITS_NIT,
		USDIMPORTER_LIGHTUNITS_CANDELA,
		USDIMPORTER_LIGHTUNITS_PERCENT,
	USDIMPORTER_MATERIALS,
	
	USDIMPORTER_GRP_GEOMETRY,
	USDIMPORTER_GEOMETRY,
	USDIMPORTER_NORMALS,
		USDIMPORTER_NORMALS_NONE,
		USDIMPORTER_NORMALS_VERTEX,
		USDIMPORTER_NORMALS_PHONG,
	USDIMPORTER_PHONG_ANGLE,
	USDIMPORTER_UV,
	USDIMPORTER_DISPLAYCOLOR,
	USDIMPORTER_NODESPACE,
	USDIMPORTER_NODESPACE_STRINGIFIED_ID,

	USDIMPORTER_END
};

#endif // FUSDIMPORTER_H__
