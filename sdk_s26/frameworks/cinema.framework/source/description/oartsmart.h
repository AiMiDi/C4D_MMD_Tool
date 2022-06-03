#ifndef _Oartsmart_H_
#define _Oartsmart_H_
enum
{
	//Reserve 1000-1010 for Spline Interpolation
	//Reserve 2000+ for NURBS Caps
	ART_FILE		=30000,
	ART_LAYEROFFSET		=30001,
	ART_DEPTH		=30002,
	ART_CONTENTS		=30003,
	ART_RECENTER		=30004,
	ART_PATHOFFSET		=30005,
	ART_USEMOGRAPH		=30006,
	ART_SHOW_HIERARCHY	=30007,
	ART_FILTERGROUP		=30010,
	ART_LAYERFILTER		=30011,
	ART_PATHFILTER_ON	=30012,
	ART_PATHFILTER		=30013,
	ART_RECENTER_Z		=30014,
	ART_FORCEPDF		=30015,
	ART_STROKESETTINGS	=30016,
	ART_STROKESCALE		=30017,
	ART_STROKEASPECT	=30018,
	ART_STROKEROUNDING	=30019,
	ART_STROKEGROWTH	=30020,
	ART_STROKEALIGN		=30021,
	ART_STROKEALIGN_START = 30022,
	ART_STROKEALIGN_END = 30023,
	ART_STROKEALIGN_CENTER = 30024,
	ART_STROKEALIGN_STARTEND = 30025,
	ART_STROKEOFFSET = 30026,
	ART_GREEDYFILL = 30050,
	ART_AUTOCLOSE = 30051,
	ART_LEGACYCENTER = 30052,
	ART_PATHEFFECTOR	=30100,
	ART_PATHEFFECTOR_LIST = 30101,
	ART_LAYEREFFECTOR   =30200,
	ART_LAYEREFFECTOR_LIST = 30201,
	ART_RELOAD		=5000,
	ART_OPEN		=5001,
	ART_CREATEMATERIALS		=5002,
	ART_INFO		=5005,
	ART_DEBUGMSG	=5006,
	ART_SPLINESETTINGS = 5007,
	ART_CREATEOBJECT = 6000,
	
	SPLINEOBJECT_INTERPOLATION				= 1001,
		SPLINEOBJECT_INTERPOLATION_NONE     = 0,
		SPLINEOBJECT_INTERPOLATION_NATURAL  = 1,
		SPLINEOBJECT_INTERPOLATION_UNIFORM  = 2,
		SPLINEOBJECT_INTERPOLATION_ADAPTIVE = 3,
		SPLINEOBJECT_INTERPOLATION_SUBDIV   = 4,
	SPLINEOBJECT_CLOSED					    = 1002,
	SPLINEOBJECT_SUB						= 1003,
	SPLINEOBJECT_ANGLE						= 1004,
	SPLINEOBJECT_MAXIMUMLENGTH				= 1005,
	
	ART_DIRTY_PATHSTATE_FLAG = 7000,
	ART_SCALE = 7001,
	ART_HIERARCHY_LINK = 7002,
	
	ART_TYPE = 7003,
	ART_Z_LENGTH = 7004,
	ART_IMPORT_FAILED = 7005,
	ART_ROOT_OBJECT = 7006,
	
	ART_NUM_GRADIENT_MATERIALS = 7007,
	ART_GRADIENT_MATERIAL_LINKS = 8000,
	
	ART_NUM_BUILT_MATERIALS = 7008,
	ART_BUILT_MATERIAL_LINKS = 10000,
};
#endif

