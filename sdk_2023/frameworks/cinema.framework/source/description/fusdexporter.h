#ifndef FUSDEXPORTER_H__
#define FUSDEXPORTER_H__

enum
{
	USDEXPORTER_GROUP						= 999,

	USDEXPORTER_GRP_GENERAL,
	USDEXPORTER_EXPORT2LAYER,
	USDEXPORTER_FILEFORMAT,
		USDEXPORTER_FILEFORMAT_USDA,
		USDEXPORTER_FILEFORMAT_USDC,
	USDEXPORTER_ZIP,
	USDEXPORTER_CAMERAS,
	USDEXPORTER_LIGHTUNITS,
		USDEXPORTER_LIGHTUNITS_NONE,
		USDEXPORTER_LIGHTUNITS_NIT,
		USDEXPORTER_LIGHTUNITS_CANDELA,
	USDEXPORTER_MATERIALS,
	USDEXPORTER_MATERIALS_BRIDGE,
	USD_EXPORTER_MATERIALS_BRIDGE_INFO,
	USDEXPORTER_MATERIALS_BAKETEXTURES,
	USDEXPORTER_MATERIALS_WIDTH,
	USDEXPORTER_MATERIALS_HEIGHT,
	USDEXPORTER_MATERIALS_DEPTH,
		USDEXPORTER_MATERIALS_DEPTH_8,
		USDEXPORTER_MATERIALS_DEPTH_16,
		USDEXPORTER_MATERIALS_DEPTH_32,
	USDEXPORTER_MATERIALS_FORMAT,
	USDEXPORTER_MATERIALS_FORMAT_STRINGIFIED_ID,
	USDEXPORTER_MATERIALS_FORMAT_USDZ,
	USDEXPORTER_MATERIALS_FORMAT_USDZ_STRINGIFIED_ID,

	USDEXPORTER_GRP_GEOMETRY,
	USDEXPORTER_GEOMETRY,
	USDEXPORTER_NORMALS,
	USDEXPORTER_UV,
	USDEXPORTER_DISPLAYCOLOR,
	USDEXPORTER_VERTEXCOLORS,

	USDEXPORTER_MATERIALS_NONE,
	USDEXPORTER_MATERIALS_EXPORT,
	USDEXPORTER_MATERIALS_EXPORTANDBRIDGE,

	USDEXPORTER_END
};

#endif // FUSDEXPORTER_H__
