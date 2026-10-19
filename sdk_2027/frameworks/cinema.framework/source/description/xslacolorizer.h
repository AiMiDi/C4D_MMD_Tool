#ifndef XSLACOLORIZER_H__
#define XSLACOLORIZER_H__

enum
{
	XSLAColorizer                         = 1000,

	SLA_COLORIZER_INPUT                   = 1001, // long
		SLA_COLORIZER_INPUT_LUMINANCE       = 2001,
		SLA_COLORIZER_INPUT_HUE             = 2002,
		SLA_COLORIZER_INPUT_SATURATION      = 2003,
		SLA_COLORIZER_INPUT_LIGHTNESS       = 2004,
		SLA_COLORIZER_INPUT_RED             = 2005,
		SLA_COLORIZER_INPUT_GREEN           = 2006,
		SLA_COLORIZER_INPUT_BLUE            = 2007,
	SLA_COLORIZER_CYCLE                   = 1004, // bool
	SLA_COLORIZER_TEXTURE                 = 1002, // texture group
	SLA_COLORIZER_GRADIENT                = 1003, // gradient

	SLA_COLORIZER_DUMMY_
};

#endif // XSLACOLORIZER_H__
