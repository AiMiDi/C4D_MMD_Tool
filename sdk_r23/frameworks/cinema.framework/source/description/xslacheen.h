#ifndef XSLACHEEN_H__
#define XSLACHEEN_H__

enum
{
	XSLACheen                             = 1000,

	ID_CHEEN_GRADIENTS                    = 4013, // group
	ID_CHEEN_DIFFUSE                      = 4001, // group
	ID_CHEEN_SPECULAR1                    = 4002, // group
	ID_CHEEN_SPECULAR2                    = 4003, // group
	ID_CHEEN_SPECULAR3                    = 4004, // group
	ID_CHEEN_TRANSPARENCY                 = 4011, // group
	ID_CHEEN_REFLECTION                   = 4005, // group
	ID_CHEEN_ENVIRONMENT                  = 4006, // group
	ID_CHEEN_AMBIENT                      = 4007, // group
	ID_CHEEN_ROUGHNESS                    = 4008, // group
	ID_CHEEN_ANISOTROPY                  = 4009, // group
	ID_CHEEN_ESOTERICA                    = 4012, // group

	SLA_CHEEN_GRADIENTS                   = 3011, // bool
	SLA_CHEEN_DIFFUSE                     = 3001, // bool
	SLA_CHEEN_SPECULAR1                   = 3002, // bool
	SLA_CHEEN_SPECULAR2                   = 3003, // bool
	SLA_CHEEN_SPECULAR3                   = 3004, // bool
	SLA_CHEEN_TRANSPARENCY                = 3010, // bool
	SLA_CHEEN_REFLECTION                  = 3005, // bool
	SLA_CHEEN_ENVIRONMENT                 = 3006, // bool
	SLA_CHEEN_AMBIENT                     = 3007, // bool
	SLA_CHEEN_ROUGHNESS                   = 3008, // bool
	SLA_CHEEN_ANISOTROPY                 = 3009, // bool
	SLA_CHEEN_ESOTERICA                   = 3012, // bool

	SLA_CHEEN_GRADIENTS_COLOR             = 3170, // gradient
	SLA_CHEEN_GRADIENTS_OPACITY           = 3171, // gradient

	SLA_CHEEN_DIFFUSE_SURF_COLOR          = 3031, // vector
	SLA_CHEEN_DIFFUSE_ALGORITHM           = 3032, // long
		SLA_CHEEN_DIFFUSE_ALGORITHM_INTERNAL    = 2001,
		SLA_CHEEN_DIFFUSE_ALGORITHM_OREN_NAYAR  = 2002,
	SLA_CHEEN_DIFFUSE_ROUGHNESS           = 3033, // real
	SLA_CHEEN_DIFFUSE_SURF_ILLUMINATION   = 3034, // real
	SLA_CHEEN_DIFFUSE_CONTRAST            = 3035, // real

	SLA_CHEEN_SPEC1_COLOR                 = 3041, // vector
	SLA_CHEEN_SPEC1_INTENSITY             = 3042, // real
	SLA_CHEEN_SPEC1_SIZE                  = 3043, // real
	SLA_CHEEN_SPEC1_CONTRAST              = 3044, // real
	SLA_CHEEN_SPEC1_GLARE                 = 3045, // real
	SLA_CHEEN_SPEC1_FALLOFF               = 3046, // real

	SLA_CHEEN_SPEC2_COLOR                 = 3051, // vector
	SLA_CHEEN_SPEC2_INTENSITY             = 3052, // real
	SLA_CHEEN_SPEC2_SIZE                  = 3053, // real
	SLA_CHEEN_SPEC2_CONTRAST              = 3054, // real
	SLA_CHEEN_SPEC2_GLARE                 = 3055, // real
	SLA_CHEEN_SPEC2_FALLOFF               = 3056, // real

	SLA_CHEEN_SPEC3_COLOR                 = 3061, // vector
	SLA_CHEEN_SPEC3_INTENSITY             = 3062, // real
	SLA_CHEEN_SPEC3_SIZE                  = 3063, // real
	SLA_CHEEN_SPEC3_CONTRAST              = 3064, // real
	SLA_CHEEN_SPEC3_GLARE                 = 3065, // real
	SLA_CHEEN_SPEC3_FALLOFF               = 3066, // real

	SLA_CHEEN_TRANS_REFRACTION_INDEX      = 3153, // real
	SLA_CHEEN_TRANS_INTERNAL_REFLECTION   = 3154, // bool
	SLA_CHEEN_TRANS_SOLID_OBJECT          = 3155, // bool

	SLA_CHEEN_REFLECTION_INTENSITY        = 3071, // real
	SLA_CHEEN_REFLECTION_EDGE_INTENSITY   = 3072, // real
	SLA_CHEEN_REFLECTION_FALLOFF          = 3073, // real
	SLA_CHEEN_REFLECTION_REFLECTION_COLOR = 3081, // vector
	SLA_CHEEN_REFLECTION_EDGE_COLOR       = 3082, // vector

	SLA_CHEEN_ENVIRONMENT_IMAGE           = 3091, // texture
	SLA_CHEEN_ENVIRONMENT_INTENSITY       = 3092, // real
	SLA_CHEEN_ENVIRONMENT_GLARE           = 3093, // real
	SLA_CHEEN_ENVIRONMENT_FALLOFF         = 3094, // real
	SLA_CHEEN_ENVIRONMENT_UTILIZE_ANISO_SCRATCHES = 3095, // bool
	SLA_CHEEN_ENVIRONMENT_BLUR            = 3096, // real
	SLA_CHEEN_ENVIRONMENT_SAMPLES         = 3097, // long
	SLA_CHEEN_ENVIRONMENT_JITTER          = 3098, // real
	SLA_CHEEN_ENVIRONMENT_ENVIRONMENT_COLOR = 3099, // vector
	SLA_CHEEN_ENVIRONMENT_EDGE_COLOR      = 3100, // vector

	SLA_CHEEN_AMBIENT_COLOR               = 3111, // vector
	SLA_CHEEN_AMBIENT_INTENSITY           = 3112, // real
	SLA_CHEEN_AMBIENT_EDGE_INTENSITY      = 3113, // real
	SLA_CHEEN_AMBIENT_FALLOFF             = 3114, // real

	SLA_CHEEN_ROUGHNESS_SEED							= 3130, // long
	SLA_CHEEN_ROUGHNESS_NOISE             = 3115, // long
		//SLA_CHEEN_ROUGHNESS_NOISE_NONE                     = 2100,
		//SLA_CHEEN_ROUGHNESS_NOISE_BOX_NOISE                = 2101,
		//SLA_CHEEN_ROUGHNESS_NOISE_BUYA                     = 2102,
		//SLA_CHEEN_ROUGHNESS_NOISE_CRANAL                   = 2103,
		//SLA_CHEEN_ROUGHNESS_NOISE_DENTS                    = 2104,
		//SLA_CHEEN_ROUGHNESS_NOISE_FBM                      = 2105,
		//SLA_CHEEN_ROUGHNESS_NOISE_HAMA                     = 2106,
		//SLA_CHEEN_ROUGHNESS_NOISE_LUKA                     = 2107,
		//SLA_CHEEN_ROUGHNESS_NOISE_NAKI                     = 2108,
		//SLA_CHEEN_ROUGHNESS_NOISE_NOISE                    = 2109,
		//SLA_CHEEN_ROUGHNESS_NOISE_NUTOUS                   = 2110,
		//SLA_CHEEN_ROUGHNESS_NOISE_OBER                     = 2111,
		//SLA_CHEEN_ROUGHNESS_NOISE_PEZO                     = 2112,
		//SLA_CHEEN_ROUGHNESS_NOISE_POXO                     = 2113,
		//SLA_CHEEN_ROUGHNESS_NOISE_SEMA                     = 2114,
		//SLA_CHEEN_ROUGHNESS_NOISE_STUPL                    = 2115,
		//SLA_CHEEN_ROUGHNESS_NOISE_TURBULENCE               = 2116,
		//SLA_CHEEN_ROUGHNESS_NOISE_BLIST_TURB               = 2117,
		//SLA_CHEEN_ROUGHNESS_NOISE_DISPL_TURB               = 2118,
		//SLA_CHEEN_ROUGHNESS_NOISE_VL_NOISE                 = 2119,
		//SLA_CHEEN_ROUGHNESS_NOISE_WAVY_TURB                = 2120,
		//SLA_CHEEN_ROUGHNESS_NOISE_ZADA                     = 2121,
		//SLA_CHEEN_ROUGHNESS_NOISE_CELL_NOISE               = 2122,
		//SLA_CHEEN_ROUGHNESS_NOISE_MOD_NOISE                = 2123,
		//SLA_CHEEN_ROUGHNESS_NOISE_RANDOM                   = 2124,
		//SLA_CHEEN_ROUGHNESS_NOISE_SEPARATOR                = 5000,
		//SLA_CHEEN_ROUGHNESS_NOISE_CELL_VORONOI             = 2125,
		//SLA_CHEEN_ROUGHNESS_NOISE_DISPL_VORONOI            = 2126,
		//SLA_CHEEN_ROUGHNESS_NOISE_SPARSE_CONV              = 2127,
		//SLA_CHEEN_ROUGHNESS_NOISE_VORONOI_1                = 2128,
		//SLA_CHEEN_ROUGHNESS_NOISE_VORONOI_2                = 2129,
		//SLA_CHEEN_ROUGHNESS_NOISE_VORONOI_3                = 2130,

	SLA_CHEEN_ROUGHNESS_AMPLITUDE         = 3116, // real
	SLA_CHEEN_ROUGHNESS_OCTAVES           = 3117, // real
	SLA_CHEEN_ROUGHNESS_SCALE             = 3118, // real
	SLA_CHEEN_ROUGHNESS_SPEED             = 3119, // real
	SLA_CHEEN_ROUGHNESS_ATTENUATION       = 3120, // real
	SLA_CHEEN_ROUGHNESS_DELTA             = 3121, // real
	SLA_CHEEN_ROUGHNESS_HARD_BUMP         = 3122, // bool
	SLA_CHEEN_ROUGHNESS_ABSOLUTE          = 3123, // bool
	SLA_CHEEN_ROUGHNESS_LOW_CLIP          = 3124, // real
	SLA_CHEEN_ROUGHNESS_HIGH_CLIP         = 3125, // real
	SLA_CHEEN_ROUGHNESS_GRIT_COLOR        = 3126, // vector
	SLA_CHEEN_ROUGHNESS_GRIT_INTENSITY    = 3127, // real
	SLA_CHEEN_ROUGHNESS_GRIT_LOW_CLIP     = 3128, // real
	SLA_CHEEN_ROUGHNESS_GRIT_HIGH_CLIP    = 3129, // real

	SLA_CHEEN_ANISOTROPY_PROJECTION      = 3131, // long
		SLA_CHEEN_ANISOTROPY_PROJECTION_PLANAR               = 2140,
		SLA_CHEEN_ANISOTROPY_PROJECTION_AUTO_PLANAR          = 2141,
		SLA_CHEEN_ANISOTROPY_PROJECTION_SHRINK_WRAP          = 2142,
		SLA_CHEEN_ANISOTROPY_PROJECTION_RADIAL_AUTO_PLANAR   = 2143,
		SLA_CHEEN_ANISOTROPY_PROJECTION_RAD_PATTERN_AUTO_PLANAR  = 2144,
		SLA_CHEEN_ANISOTROPY_PROJECTION_RADIAL_PLANAR        = 2145,
		SLA_CHEEN_ANISOTROPY_PROJECTION_RAD_PATTERN_PLANAR   = 2146,

	SLA_CHEEN_ANISOTROPY_PROJ_SCALE      = 3132, // real
	SLA_CHEEN_ANISOTROPY_X_ROUGH         = 3133, // real
	SLA_CHEEN_ANISOTROPY_Y_ROUGH         = 3134, // real
	SLA_CHEEN_ANISOTROPY_AMPL            = 3135, // real
	SLA_CHEEN_ANISOTROPY_SCALE           = 3136, // real
	SLA_CHEEN_ANISOTROPY_LENGTH          = 3137, // real
	SLA_CHEEN_ANISOTROPY_ATT             = 3138, // real
	SLA_CHEEN_ANISOTROPY_CHANNEL1        = 3140, // bool
	SLA_CHEEN_ANISOTROPY_CHANNEL2        = 3141, // bool
	SLA_CHEEN_ANISOTROPY_CHANNEL3        = 3142, // bool

	SLA_CHEEN_ESOTERICA_OPACITY           = 3160, // real

	SLA_CHEEN_DUMMY_
};

#endif // XSLACHEEN_H__
