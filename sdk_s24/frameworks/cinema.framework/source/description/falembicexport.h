#ifndef FALEMBICEXPORT_H__
#define FALEMBICEXPORT_H__

enum
{
	ABCEXPORT_GROUP				= 999,
	ABCEXPORT_STR_ANIMATION = 1000,
	ABCEXPORT_FRAME_START,
	ABCEXPORT_FRAME_END,
	ABCEXPORT_FRAME_STEP,
	ABCEXPORT_SUBFRAMES,

	ABCEXPORT_STR_GENERAL,
	ABCEXPORT_SELECTION_ONLY,
	ABCEXPORT_VISIBILITY,

	ABCEXPORT_STR_OPTIONS,
	ABCEXPORT_NORMALS,
	ABCEXPORT_UVS,
	ABCEXPORT_POLYGONSELECTIONS,
	ABCEXPORT_CAMERAS,
	ABCEXPORT_HYPERNURBS,
	ABCEXPORT_SPLINES,
	ABCEXPORT_POINTS_ONLY,
	ABCEXPORT_PARTICLES,
	ABCEXPORT_HAIR,
	ABCEXPORT_SCALE,
	ABCEXPORT_MERGE_CACHE,
	ABCEXPORT_GLOBAL_MATRIX,
	ABCEXPORT_XREFS,
	ABCEXPORT_PARTICLE_GEOMETRY,
	ABCEXPORT_VERTEX_MAPS,

	ABCEXPORT_VERTEX_COLORS = 1025,
	ABCEXPORT_DISPLAY_COLORS,
	ABCEXPORT_SDS_WEIGHTS,

	ABCEXPORT_PARENTS_ONLY_MODE	// virtual
};

#endif // FALEMBICEXPORT_H__

