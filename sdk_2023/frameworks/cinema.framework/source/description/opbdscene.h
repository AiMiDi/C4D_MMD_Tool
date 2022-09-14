#ifndef OPBDSCENE_H__
#define OPBDSCENE_H__

enum
{
	PBDSCENE_DEVICE = 1000,
		PBDSCENE_DEVICE_CPU = 0,
		PBDSCENE_DEVICE_GPU = 1,
	PBDSCENE_SUBSTEPS = 1001,
	PBDSCENE_ITERATIONS = 1002,
	PBDSCENE_COLLISIONPASSES = 1003,
	PBDSCENE_USEDOCUMENT_RANGE = 1004,
	PBDSCENE_SIMULATION_FROM = 1005,
	PBDSCENE_SIMULATION_TO = 1006,
	PBDSCENE_TAGS	= 1007,
	PBDSCENE_FORCES = 1008,
	PBDSCENE_USECCD = 1009,
	PBDSCENE_DAMPING = 1010,
	PBDSCENE_POSTCOLLISIONPASSES = 1011,
	PBDSCENE_POLISHITERATIONS = 1012,
	PBDSCENE_SMOOTHINGITERATIONS = 1013,
	PBDSCENE_CONSTRAINTSOLVER = 1014,
		PBDSCENE_CONSTRAINTSOLVER_JACOBI = 0,
		PBDSCENE_CONSTRAINTSOLVER_GAUSSSEIDEL = 1,
		PBDSCENE_CONSTRAINTSOLVER_GAUSSSEIDELVIVACE = 2,
	PBDSCENE_DEFAULTGRAVITY = 1015,
	PBDSCENE_SCENESCALE = 1016,
	PBDSCENE_EVALUATEBEFOREGENERATORS = 1017,
	PBDSCENE_GROUP_SCENEPROPERTIES = 1018,
	PBDSCENE_GROUP_XPBDPROPERTIES = 1019,
	PBDSCENE_GROUP_PYROPROPERTIES = 1020,
	PBDSCENE_PYRO_DENSITYBUOYANCY = 1021,
	PBDSCENE_PYRO_TEMPERATUREBUOYANCY = 1022,
	PBDSCENE_PYRO_VORTICITYSTRENGTH = 1023,
	PBDSCENE_PYRO_TEMPERATUREAMBIENT = 1024,
	PBDSCENE_PYRO_TEMPERATUREIGNITION = 1025,
	PBDSCENE_PYRO_FUELBURNINGRATE = 1026,
	PBDSCENE_PYRO_TEMPERTUREADDPERFUEL = 1027,
	PBDSCENE_PYRO_DENSITYADDPERFUEL = 1028,
	PBDSCENE_PYRO_PRESSUREADDPERFUEL = 1029,
	PBDSCENE_PYRO_TEMPERATUREDISSIPATION = 1030,
	PBDSCENE_PYRO_LINEARFUELDISSIPATION = 1031,
	PBDSCENE_PYRO_DENSITYDISSIPATION = 1032,
	PBDSCENE_PYRO_SUBSTEPS = 1033,
	PBDSCENE_PYRO_FORCES = 1034,
	PBDSCENE_PYRO_BURNPROCESS = 1035,
	PBDSCENE_PYRO_DISSIPATION = 1036,
	PBDSCENE_PYRO_PRESSURESOLVER = 1037,
	PBDSCENE_PYRO_MACVELOCITIY_ENABLED = 1038,
	PBDSCENE_PYRO_ADVECTIONMODE = 1039,
	PBDSCENE_PYRO_ADVECTIONMODE_SEMILAGRANGIAN = 1040,
	PBDSCENE_PYRO_ADVECTIONMODE_MACCORMACK = 1041,
	PBDSCENE_PYRO_MACCORMACKCORRECT = 1042,	
	PBDSCENE_PYRO_PRESSURESOLVER_TYPE = 1043,	
		PBDSCENE_PYRO_PRESSURESOLVER_GAUSSSEIDEL = 0,
		PBDSCENE_PYRO_PRESSURESOLVER_MULTIGRIDV = 1,
		PBDSCENE_PYRO_PRESSURESOLVER_MULTIGRIDFULL = 2,
	PBDSCENE_PYRO_PRESSURESOLVER_ITERATIONS = 1044,	
	PBDSCENE_PYRO_PRESSURESOLVER_SMOOTHINGITERATIONS = 1045,	
	PBDSCENE_PYRO_PRESSURESOLVER_SMOOTHINGITERATIONSFINAL = 1046,	
	PBDSCENE_PYRO_PRESSURESOLVER_MAXIMUMMULTIGRIDDEPTH = 1047,
	PBDSCENE_PYRO_TREESETTINGS = 1048,
	PBDSCENE_PYRO_VOXELSIZE = 1049,
	PBDSCENE_PYRO_TREESETTINGS_VOXELCOUNT = 1050,
		PBDSCENE_PYRO_TREESETTINGS_VOXELCOUNT_16 = 16,
		PBDSCENE_PYRO_TREESETTINGS_VOXELCOUNT_32 = 32,
	PBDSCENE_PYRO_TREESETTINGS_CHILDCOUNT = 1051,
		PBDSCENE_PYRO_TREESETTINGS_CHILDCOUNT_2 = 2,
		PBDSCENE_PYRO_TREESETTINGS_CHILDCOUNT_4 = 4,
	PBDSCENE_DRAW_GROUP = 1052,
	PBDSCENE_DRAW = 1053,
	PBDSCENE_DRAW_PARTICLES = 1054,
	PBDSCENE_DRAW_STRUTS = 1055,
	PBDSCENE_DRAW_EDGES = 1056,
	PBDSCENE_PYRO_DRAW_PYRO = 1057,
	PBDSCENE_PYRO_DRAW_TREE = 1058,
	PBDSCENE_PYRO_DRAW_GROUP = 1059, 
	PBDSCENE_PYRO_DRAW_TEXTURE = 1060,
		PBDSCENE_PYRO_DRAW_TEXTURE_DENSITY = 0,
		PBDSCENE_PYRO_DRAW_TEXTURE_COLOR = 1,
		PBDSCENE_PYRO_DRAW_TEXTURE_TEMPERATURE = 2,
		PBDSCENE_PYRO_DRAW_TEXTURE_FUEL = 3,
		PBDSCENE_PYRO_DRAW_TEXTURE_VELOCITY = 4,
		PBDSCENE_PYRO_DRAW_TEXTURE_PRESSURE = 5,
		PBDSCENE_PYRO_DRAW_TEXTURE_SHADED = 6,
	PBDSCENE_PYRO_DRAW_DENSITY_SCALE = 1061,
	PBDSCENE_PYRO_DRAW_ABSORPTION = 1062,
	PBDSCENE_PYRO_BLUR_FACTOR_TEMPERATURE = 1063,
	PBDSCENE_GROUP_DEBUGPROPERTIES = 1064,
	PBDSCENE_DEBUG_COLLISIONDETECTION = 1065,
	PBDSCENE_PARTICLEPARTICLEON = 1066,
	PBDSCENE_PARTICLETRIANGLEON = 1067,
	PBDSCENE_EDGEEDGEON = 1068,
	PBDSCENE_COLLIDERPARTICLETRIANGLEON = 1069,
	PBDSCENE_PARTICLECOLLIDERTRIANGLEON = 1070,
	PBDSCENE_EDGECOLLIDEREDGEON = 1071,
	PBDSCENE_DEBUG_SOLVECONTACTS = 1072,
	PBDSCENE_SORTCONTACTSON = 1073,
	PBDSCENE_SOLVEPARTICLEPARTICLEON = 1074,
	PBDSCENE_SOLVEPARTICLETRIANGLEON = 1075,
	PBDSCENE_SOLVEEDGEEDGEON = 1076,
	PBDSCENE_SOLVECOLLIDERPARTICLETRIANGLEON = 1077,
	PBDSCENE_SOLVEPARTICLECOLLIDERTRIANGLEON = 1078,
	PBDSCENE_SOLVEEDGECOLLIDEREDGEON = 1079,
	PBDSCENE_DEBUG_DYNAMICFRICTION = 1080,
	PBDSCENE_SOLVEPARTICLEPARTICLEVELOCITYON = 1081,
	PBDSCENE_SOLVEPARTICLETRIANGLEVELOCITYON = 1082,
	PBDSCENE_SOLVECOLLIDERPARTICLETRIANGLEVELOCITYON = 1083,
	PBDSCENE_SOLVEPARTICLECOLLIDERTRIANGLEVELOCITYON = 1084,
	PBDSCENE_EXCLUSIONLISTON = 1085,
	PBDSCENE_VELOCITYCLAMP = 1086,
		PBDSCENE_VELOCITYCLAMP_OFF = 0,
		PBDSCENE_VELOCITYCLAMP_SCENESCALE = 1,
		PBDSCENE_VELOCITYCLAMP_ABSOLUTE = 2,
		PBDSCENE_VELOCITYCLAMP_RADIUS = 3,
	PBDSCENE_ACCELERATIONCLAMP = 1087,
		PBDSCENE_ACCELERATIONCLAMP_OFF = 0,
		PBDSCENE_ACCELERATIONCLAMP_SCENESCALE = 1,
	PBDSCENE_VELOCITYCLAMP_SCENESCALE_VALUE = 1088,
	PBDSCENE_VELOCITYCLAMP_ABSOLUTE_VALUE = 1089,
	PBDSCENE_VELOCITYCLAMP_RADIUS_VALUE = 1090,
	PBDSCENE_ACCELERATIONCLAMP_SCENESCALE_VALUE = 1091,
	PBDSCENE_PYRO_ADVECTIONMODE_BFECC = 1092,
	PBDSCENE_PYRO_ADVECTIONMODE_VELOCITIES = 1093,
	PBDSCENE_COLLISIONGROUP = 1094,
	PBDSCENE_PYRO_PADDINGRADIUS = 1095,
	PBDSCENE_DEBUG_COLORING = 1096,
	PBDSCENE_RANDOMIZECOLORSOLVE = 1097,
	PBDSCENE_PYRO_ADVECTION_GROUP = 1098,
	PBDSCENE_PYRO_ADVANCED_GROUP = 1099,
	PBDSCENE_PYRO_LINEARDENSITYDISSIPATION = 1100,
	PBDSCENE_PYRO_LINEARTEMPERATUREDISSIPATION = 1101,
	PBDSCENE_PYRO_MASS = 1102,
	PBDSCENE_RECREATECOLORS = 1103,
	PBDSCENE_PYRO_ADVECT_FUEL = 1104,
	PBDSCENE_DRAW_TRIANGLEBEND = 1105,
	PBDSCENE_DRAW_CONNECTORS = 1106,
	PBDSCENE_DEBUG_FIXEDCONSTRAINTS = 1107,
	PBDSCENE_SOLVEELASTICON = 1108,
	PBDSCENE_SOLVEELASTICADDEDON = 1109,
	PBDSCENE_SOLVETRIANGLEBENDON = 1110,
	PBDSCENE_SOLVESPLINEBENDON = 1111,
	PBDSCENE_SOLVESTRETCHSHEARON = 1112,
	PBDSCENE_SOLVEBENDTWISTON = 1113,
	PBDSCENE_SOLVEWEAKPINSON = 1114,
	PBDSCENE_SOLVEVOLUMEON = 1115,
	PBDSCENE_PYRO_FLOATPRECISION = 1116,
		PBDSCENE_PYRO_FLOATPRECISION_16 = 16,
		PBDSCENE_PYRO_FLOATPRECISION_32 = 32,
	PBDSCENE_PYRO_BLUR_FACTOR_FUEL = 1117,
	PBDSCENE_PYRO_BLUR_FACTOR_VELOCITY = 1118,
	PBDSCENE_PYRO_BLUR_FACTOR_DENSITY = 1119,
	PBDSCENE_PYRO_BLUR_FACTOR_GROUP = 1120, 
	PBDSCENE_PYRO_RAYMARCH_STEPSIZE = 1121, 
	PBDSCENE_END
};
#endif // OPBDSCENE_H__