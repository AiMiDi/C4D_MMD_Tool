#ifndef XSLAPROJECTOR_H__
#define XSLAPROJECTOR_H__

enum
{
	XSLAProjector                         = 1000,

	SLA_PROJECTOR_TEXTURE                 = 1001, // texture group

	SLA_PROJECTOR_PROJECTION              = 1002, // long
		SLA_PROJECTOR_PROJECTION_SPHERICAL  = 2001,
		SLA_PROJECTOR_PROJECTION_CYLINDRICAL = 2002,
		SLA_PROJECTOR_PROJECTION_FLAT       = 2003,
		SLA_PROJECTOR_PROJECTION_CUBIC      = 2004,
		SLA_PROJECTOR_PROJECTION_FRONTAL    = 2005,
		SLA_PROJECTOR_PROJECTION_SPATIAL    = 2006,
		SLA_PROJECTOR_PROJECTION_UVW        = 2007,
		SLA_PROJECTOR_PROJECTION_SHRINKWRAP = 2008,

	//SLA_PROJECTOR_TILE_UV                 = 1015, // bool
	SLA_PROJECTOR_OFFSET_X                = 1003, // real
	SLA_PROJECTOR_OFFSET_Y                = 1004, // real
	SLA_PROJECTOR_LENGTH_X                = 1005, // real
	SLA_PROJECTOR_LENGTH_Y                = 1006, // real
	SLA_PROJECTOR_TILES_X                 = 1007, // real
	SLA_PROJECTOR_TILES_Y                 = 1008, // real
	SLA_PROJECTOR_TILE                    = 1009, // bool
	SLA_PROJECTOR_SEAMLESS                = 1010, // bool
	SLA_PROJECTOR_POSITION                = 1011, // vector
	SLA_PROJECTOR_SIZE                    = 1012, // vector
	SLA_PROJECTOR_ROTATION                = 1013, // vector
	SLA_PROJECTOR_PASTE_TAG               = 1014, // button

	SLA_PROJECTOR_DUMMY_
};

#endif // XSLAPROJECTOR_H__
