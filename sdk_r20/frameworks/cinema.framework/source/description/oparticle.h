#ifndef OPARTICLE_H__
#define OPARTICLE_H__

enum
{
	ID_PARTICLE = 807,
	ID_EMITTER  = 808,
	ID_INCLUDE  = 809,

	PARTICLEOBJECT_BIRTHEDITOR			= 1000, // LONG     - Birthrate Editor
	PARTICLEOBJECT_BIRTHRAYTRACER		= 1001, // LONG     - Birthrate Raytracer
	PARTICLEOBJECT_SPEED						= 1002, // REAL     - Speed
	PARTICLEOBJECT_SPEEDVAR					= 1003, // REAL     - Speed variation
	PARTICLEOBJECT_LIFETIME					= 1004, // BASETIME - Average Lifetime
	PARTICLEOBJECT_LIFETIMEVAR			= 1005, // REAL		 - Lifetime variation
	PARTICLEOBJECT_SIZE							= 1006, // REAL		 - Particle size
	PARTICLEOBJECT_SIZEVAR					= 1007, // REAL		 - Size variation
	PARTICLEOBJECT_ROTATION					= 1008, // REAL		 - Particle rotation
	PARTICLEOBJECT_ROTATIONVAR			= 1009, // REAL		 - Rotational variation
	PARTICLEOBJECT_TANGENTIAL				= 1010, // BOOL		 - Tangential
	PARTICLEOBJECT_TYPE							= 1011, // LONG		 - Emitter type; 0=pyramid, 1=cone
		PARTICLEOBJECT_TYPE_PYRAMID 		= 0,
		PARTICLEOBJECT_TYPE_CONE    		= 1,
	PARTICLEOBJECT_SIZEX						= 1012, // REAL		 - X-Size
	PARTICLEOBJECT_SIZEY						= 1013, // REAL		 - Y-Size
	PARTICLEOBJECT_ANGLEH						= 1014, // REAL		 - Angle horizontal
	PARTICLEOBJECT_ANGLEV						= 1015, // REAL		 - Angle vertical
	PARTICLEOBJECT_START            = 1018, // BASETIME - Average Lifetime
	PARTICLEOBJECT_STOP             = 1019, // BASETIME - Average Lifetime
	PARTICLEOBJECT_SEED             = 1020, // LONG     - random start value
	PARTICLEOBJECT_VISIBILITY       = 1021, // REAL     - percentage of visible particles
	PARTICLEOBJECT_SHOWOBJECTS			= 1022,  // BOOL
	PARTICLEOBJECT_MODE							= 1024,	// LONG
	PARTICLEOBJECT_INCLUDE					= 1025,	// IN_EXCLUDE
		PARTICLEOBJECT_MODE_INCLUDE = 0,
		PARTICLEOBJECT_MODE_EXCLUDE = 1,
	PARTICLEOBJECT_RENDERINSTANCES	= 1026,

	//////////////////////////////////////////////////////////////////////////

	PARTICLEOBJECT_DUMMY
};

#endif // OPARTICLE_H__
