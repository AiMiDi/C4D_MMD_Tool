#ifndef XSLABANZI_H__
#define XSLABANZI_H__

enum
{
	ID_BANZI_WOOD                         = 4001, // group
	ID_BANZI_DIFFUSE                      = 4002, // group
	ID_BANZI_SPECULAR1                    = 4003, // group
	ID_BANZI_SPECULAR2                    = 4004, // group
	ID_BANZI_SPECULAR3                    = 4005, // group
	ID_BANZI_REFLECTION                   = 4006, // group
	ID_BANZI_ENVIRONMENT                  = 4007, // group
	ID_BANZI_AMBIENT                      = 4008, // group
	ID_BANZI_ROUGHNESS                    = 4009, // group
	ID_BANZI_ANISOTROPY                  = 4010, // group

	SLA_BANZI_WOOD                        = 3001, // bool
	SLA_BANZI_DIFFUSE                     = 3002, // bool
	SLA_BANZI_SPECULAR1                   = 3003, // bool
	SLA_BANZI_SPECULAR2                   = 3004, // bool
	SLA_BANZI_SPECULAR3                   = 3005, // bool
	SLA_BANZI_REFLECTION                  = 3006, // bool
	SLA_BANZI_ENVIRONMENT                 = 3007, // bool
	SLA_BANZI_AMBIENT                     = 3008, // bool
	SLA_BANZI_ROUGHNESS                   = 3009, // bool
	SLA_BANZI_ANISOTROPY                 = 3010, // bool

	SLA_BANZI_WOOD_GRADIENT               = 3170, // gradient
	SLA_BANZI_WOOD_RING_INTENSITY         = 3171, // real
	SLA_BANZI_WOOD_RING_SCALE             = 3172, // real
	SLA_BANZI_WOOD_RING_TURBULENCE        = 3173, // real
	SLA_BANZI_WOOD_TURBULENCE_SCALE       = 3174, // real
	SLA_BANZI_WOOD_RING_VARIANCE          = 3175, // real
	SLA_BANZI_WOOD_CORE_VARIANCE          = 3176, // real
	SLA_BANZI_WOOD_VARIANCE_SCALE         = 3177, // real
	SLA_BANZI_WOOD_RADIAL_VARIANCE        = 3178, // real
	SLA_BANZI_WOOD_RADIAL_VARIANCE_SCALE  = 3179, // real
	SLA_BANZI_WOOD_GRAIN_INTENSITY        = 3180, // real
	SLA_BANZI_WOOD_GRAIN_SCALE            = 3181, // real
	SLA_BANZI_WOOD_ATTENUATION            = 3182, // real

	SLA_BANZI_DIFFUSE_SURF_COLOR          = 3031, // vector
	SLA_BANZI_DIFFUSE_ALGORITHM           = 3032, // long
		SLA_BANZI_DIFFUSE_ALGORITHM_INTERNAL    = 2001,
		SLA_BANZI_DIFFUSE_ALGORITHM_OREN_NAYAR  = 2002,
	SLA_BANZI_DIFFUSE_ROUGHNESS           = 3033, // real
	SLA_BANZI_DIFFUSE_SURF_ILLUMINATION   = 3034, // real
	SLA_BANZI_DIFFUSE_CONTRAST            = 3035, // real

	SLA_BANZI_SPEC1_COLOR                 = 3041, // vector
	SLA_BANZI_SPEC1_INTENSITY             = 3042, // real
	SLA_BANZI_SPEC1_SIZE                  = 3043, // real
	SLA_BANZI_SPEC1_CONTRAST              = 3044, // real
	SLA_BANZI_SPEC1_GLARE                 = 3045, // real
	SLA_BANZI_SPEC1_FALLOFF               = 3046, // real

	SLA_BANZI_SPEC2_COLOR                 = 3051, // vector
	SLA_BANZI_SPEC2_INTENSITY             = 3052, // real
	SLA_BANZI_SPEC2_SIZE                  = 3053, // real
	SLA_BANZI_SPEC2_CONTRAST              = 3054, // real
	SLA_BANZI_SPEC2_GLARE                 = 3055, // real
	SLA_BANZI_SPEC2_FALLOFF               = 3056, // real

	SLA_BANZI_SPEC3_COLOR                 = 3061, // vector
	SLA_BANZI_SPEC3_INTENSITY             = 3062, // real
	SLA_BANZI_SPEC3_SIZE                  = 3063, // real
	SLA_BANZI_SPEC3_CONTRAST              = 3064, // real
	SLA_BANZI_SPEC3_GLARE                 = 3065, // real
	SLA_BANZI_SPEC3_FALLOFF               = 3066, // real

	SLA_BANZI_REFLECTION_INTENSITY        = 3071, // real
	SLA_BANZI_REFLECTION_EDGE_INTENSITY   = 3072, // real
	SLA_BANZI_REFLECTION_FALLOFF          = 3073, // real
	SLA_BANZI_REFLECTION_REFLECTION_COLOR = 3081, // vector
	SLA_BANZI_REFLECTION_EDGE_COLOR       = 3082, // vector

	SLA_BANZI_ENVIRONMENT_IMAGE           = 3091, // texture
	SLA_BANZI_ENVIRONMENT_INTENSITY       = 3092, // real
	SLA_BANZI_ENVIRONMENT_GLARE           = 3093, // real
	SLA_BANZI_ENVIRONMENT_FALLOFF         = 3094, // real
	SLA_BANZI_ENVIRONMENT_UTILIZE_ANISO_SCRATCHES = 3095, // bool
	SLA_BANZI_ENVIRONMENT_BLUR            = 3096, // real
	SLA_BANZI_ENVIRONMENT_SAMPLES         = 3097, // long
	SLA_BANZI_ENVIRONMENT_JITTER          = 3098, // real
	SLA_BANZI_ENVIRONMENT_ENVIRONMENT_COLOR = 3099, // vector
	SLA_BANZI_ENVIRONMENT_EDGE_COLOR      = 3100, // vector

	SLA_BANZI_AMBIENT_COLOR               = 3111, // vector
	SLA_BANZI_AMBIENT_INTENSITY           = 3112, // real
	SLA_BANZI_AMBIENT_EDGE_INTENSITY      = 3113, // real
	SLA_BANZI_AMBIENT_FALLOFF             = 3114, // real

	SLA_BANZI_ROUGHNESS_AMPLITUDE         = 3116, // real
	SLA_BANZI_ROUGHNESS_DELTA             = 3121, // real
	SLA_BANZI_ROUGHNESS_LOW_CLIP          = 3124, // real
	SLA_BANZI_ROUGHNESS_HIGH_CLIP         = 3125, // real
	SLA_BANZI_ROUGHNESS_GRIT_COLOR        = 3126, // vector
	SLA_BANZI_ROUGHNESS_GRIT_INTENSITY    = 3127, // real
	SLA_BANZI_ROUGHNESS_GRIT_LOW_CLIP     = 3128, // real
	SLA_BANZI_ROUGHNESS_GRIT_HIGH_CLIP    = 3129, // real

	SLA_BANZI_ANISOTROPY_PROJECTION      = 3131, // long
		SLA_BANZI_ANISOTROPY_PROJECTION_PLANAR               = 2140,
		SLA_BANZI_ANISOTROPY_PROJECTION_AUTO_PLANAR          = 2141,
		SLA_BANZI_ANISOTROPY_PROJECTION_SHRINK_WRAP          = 2142,
		SLA_BANZI_ANISOTROPY_PROJECTION_RADIAL_AUTO_PLANAR   = 2143,
		SLA_BANZI_ANISOTROPY_PROJECTION_RAD_PATTERN_AUTO_PLANAR  = 2144,
		SLA_BANZI_ANISOTROPY_PROJECTION_RADIAL_PLANAR        = 2145,
		SLA_BANZI_ANISOTROPY_PROJECTION_RAD_PATTERN_PLANAR   = 2146,

	SLA_BANZI_ANISOTROPY_PROJ_SCALE      = 3132, // real
	SLA_BANZI_ANISOTROPY_X_ROUGH         = 3133, // real
	SLA_BANZI_ANISOTROPY_Y_ROUGH         = 3134, // real
	SLA_BANZI_ANISOTROPY_AMPL            = 3135, // real
	SLA_BANZI_ANISOTROPY_SCALE           = 3136, // real
	SLA_BANZI_ANISOTROPY_LENGTH          = 3137, // real
	SLA_BANZI_ANISOTROPY_ATT             = 3138, // real
	SLA_BANZI_ANISOTROPY_CHANNEL1        = 3140, // bool
	SLA_BANZI_ANISOTROPY_CHANNEL2        = 3141, // bool
	SLA_BANZI_ANISOTROPY_CHANNEL3        = 3142, // bool

	SLA_BANZI_DUMMY_
};

#endif // XSLABANZI_H__
