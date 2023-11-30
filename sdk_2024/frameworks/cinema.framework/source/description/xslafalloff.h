#ifndef XSLAFALLOFF_H__
#define XSLAFALLOFF_H__

enum
{
	XSLAFalloff                           = 1000,

	SLA_FALLOFF_VECTOR                    = 1001,   // Vector
	SLA_FALLOFF_SPACE                     = 1002,   // LONG
		SLA_FALLOFF_SPACE_OBJECT            = 2000,
		SLA_FALLOFF_SPACE_WORLD,
		SLA_FALLOFF_SPACE_CAMERA,

	SLA_FALLOFF_USE_BUMP                  = 1003,   // Bool
	SLA_FALLOFF_GRADIENT                  = 1004,   // Gradient

	SLA_FALLOFF_DUMMY_
};

#endif // XSLAFALLOFF_H__
