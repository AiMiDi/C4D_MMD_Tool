#ifndef OSKETCH_H__
#define OSKETCH_H__

enum
{
	ID_ST_OBJECT_LINE_GROUP = 29000,
	ID_ST_OBJECT_GROUP_SELECTIONS,

	ID_ST_OBJECT_MODE = 25000,
	ID_ST_OBJECT_OBJECTS,
	ID_ST_OBJECT_LINE_HIDDEN,
	ID_ST_OBJECT_LINE_VISIBLE,
	ID_ST_OBJECT_FROM_ST,
	ID_ST_OBJECT_SPLINE_TYPE,
	ID_ST_OBJECT_SPLINE_INTERPOLATION,
	ID_ST_OBJECT_SPLINE_SUBD,
	ID_ST_OBJECT_SPLINE_ANGLE,
	ID_ST_OBJECT_SPLINE_LENGTH,

	ID_ST_OBJECT_LINE_OUTLINE = 20000,
	ID_ST_OBJECT_LINE_FOLD,
	ID_ST_OBJECT_LINE_OVERLAPS,
	ID_ST_OBJECT_LINE_MATERIAL,
	ID_ST_OBJECT_LINE_CREASE,
	ID_ST_OBJECT_LINE_INTERSECTION,
	ID_ST_OBJECT_LINE_BORDER,
	ID_ST_OBJECT_LINE_EDGES,
	ID_ST_OBJECT_LINE_ANGLE,
	ID_ST_OBJECT_LINE_CONTOUR,
	ID_ST_OBJECT_LINE_ISOPARMS,
	ID_ST_OBJECT_LINE_TRI,

	ID_ST_OBJECT_LINES_MODE = 401019,
	ID_ST_OBJECT_LINES = 401002,
	ID_ST_OBJECT_BORDER = 401003,
	ID_ST_OBJECT_EDGES = 401004,
	ID_ST_OBJECT_UVW = 401006,

	//////////////////////////////////////////////////////////////////////////

	ID_ST_OBJECT_MODE_INCLUDE = 0,
	ID_ST_OBJECT_MODE_EXCLUDE,

	ID_ST_OBJECT_SPLINE_TYPE_LINEAR = 0,
	ID_ST_OBJECT_SPLINE_TYPE_CUBIC,
	ID_ST_OBJECT_SPLINE_TYPE_AKIMA,
	ID_ST_OBJECT_SPLINE_TYPE_BSPLINE,
	ID_ST_OBJECT_SPLINE_TYPE_BEZIER,

	ID_ST_OBJECT_SPLINE_INTERPOLATION_NONE = 0,
	ID_ST_OBJECT_SPLINE_INTERPOLATION_NATURAL,
	ID_ST_OBJECT_SPLINE_INTERPOLATION_UNIFORM,
	ID_ST_OBJECT_SPLINE_INTERPOLATION_ADAPTIVE,
	ID_ST_OBJECT_SPLINE_INTERPOLATION_SUBDIVIDED,

	ID_ST_OBJECT_LINES_MODE_INCLUDE = 0,
	ID_ST_OBJECT_LINES_MODE_EXCLUDE,

	//////////////////////////////////////////////////////////////////////////

	ID_ST_OBJECT_DUMMY
};

#endif // OSKETCH_H__
