#ifndef OBOOLE_H__
#define OBOOLE_H__

enum
{
	BOOLEOBJECT_TYPE	= 1000, // LONG
		BOOLEOBJECT_TYPE_UNION     = 0,
		BOOLEOBJECT_TYPE_SUBTRACT  = 1,
		BOOLEOBJECT_TYPE_INTERSECT = 2,
		BOOLEOBJECT_TYPE_WITHOUT   = 3,

	BOOLEOBJECT_SINGLE_OBJECT   = 1001, // Bool
	BOOLEOBJECT_HIDE_NEW_EDGES  = 1002, // Bool
	BOOLEOBJECT_BREAK_CUT_EDGES = 1003, // Bool
	BOOLEOBJECT_SEL_CUT_EDGES   = 1004, // Bool
	BOOLEOBJECT_OPTIMIZE_LEVEL  = 1005, // REAL
	BOOLEOBJECT_HIGHQUALITY			= 1006, // BOOL
	BOOLEOBJECT_BEVEL           = 1007, // Bool
	//BOOLEOBJECT_BEVEL_INNER     = 1008, // Bool
	BOOLEOBJECT_BEVEL_WIDTH     = 1009, // Real
	BOOLEOBJECT_BEVEL_SUBDIVISION = 1010, // LONG
	BOOLEOBJECT_BEVEL_MODE      = 1011,
		BOOLEOBJECT_BEVEL_LINEAR  = 0,
		BOOLEOBJECT_BEVEL_OUTER_CIRCLE = 1,
		BOOLEOBJECT_BEVEL_INNER_CIRCLE = 2,
		BOOLEOBJECT_BEVEL_BEZIER       = 3,

	BOOLEOBJECT_
};

#endif // OBOOLE_H__
