#ifndef TMETABALL_H__
#define TMETABALL_H__

enum
{
	METABALLTAG_NEGATIVE						= 1000, // BOOL
	METABALLTAG_STRENGTH						= 1001, // REAL
	METABALLTAG_RADIUS							= 1002, // REAL
	METABALLTAG_TYPE								= 1003, // LONG
		METABALLTAG_TYPE_SPHERE					= 0,
		METABALLTAG_TYPE_LINE						= 1,
		METABALLTAG_TYPE_TRIANGLE				= 2,
	METABALLTAG_SOLID							= 1004
};

#endif // TMETABALL_H__
