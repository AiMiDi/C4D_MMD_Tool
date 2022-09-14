#ifndef XSLASPLINE_H__
#define XSLASPLINE_H__

enum
{
	XSLASpline                            = 1000,

	SLA_SPLINE_OBJECT                     = 1001, // link
	SLA_SPLINE_BACKGROUND_COLOR           = 1002, // texture
	SLA_SPLINE_LINE_COLOR                 = 1003, // texture
	SLA_SPLINE_FILLET_COLOR               = 1004, // texture

	SLA_SPLINE_X_OFFSET                   = 1011, // real
	SLA_SPLINE_Y_OFFSET                   = 1012, // real
	SLA_SPLINE_X_SCALE                    = 1013, // real
	SLA_SPLINE_Y_SCALE                    = 1014, // real
	SLA_SPLINE_USE_PLANE                  = 1037, // long
		SLA_SPLINE_USE_PLANE_XZ         = 0,
		SLA_SPLINE_USE_PLANE_XY         = 1,
		SLA_SPLINE_USE_PLANE_YZ         = 2,
	SLA_SPLINE_SINGLE_PIXEL_WIDTH         = 1015, // bool
	SLA_SPLINE_LINE_WIDTH                 = 1016, // real
	SLA_SPLINE_SMOOTH_WIDTH               = 1017, // real
	SLA_SPLINE_HAS_CAPS                   = 1018, // bool
	SLA_SPLINE_FILL                       = 1019, // bool
	SLA_SPLINE_FILL_COLOR                 = 1020, // bool
	SLA_SPLINE_BUMP_WIDTH                 = 1038, // real

	SLA_SPLINE_TEXT                       = 1030, // bool
	SLA_SPLINE_TEXT_TEXT                  = 1031, // String
	SLA_SPLINE_TEXT_FONT                  = 1032, // font
	SLA_SPLINE_TEXT_ALIGN                 = 1033, // long
		SLA_SPLINE_TEXT_ALIGN_LEFT      = 0,
		SLA_SPLINE_TEXT_ALIGN_MIDDLE    = 1,
		SLA_SPLINE_TEXT_ALIGN_RIGHT     = 2,
	SLA_SPLINE_TEXT_HEIGHT                = 1034, // real
	SLA_SPLINE_TEXT_HSPACING              = 1035, // real
	SLA_SPLINE_TEXT_VSPACING              = 1036, // real

	SLA_SPLINE_DUMMY_
};

#endif // XSLASPLINE_H__
