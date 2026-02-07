#ifndef TOOLCLOUD_H__
#define TOOLCLOUD_H__

enum
{
	MDATA_CLOUD_DISPLAY_QUALITY    = 10001, // real

	MDATA_RENDERPREVIEW_BTN        = 10004, // button

	MDATA_CLOUD_SIZE_X             = 10100, // long
	MDATA_CLOUD_SIZE_Y             = 10101, // long
	MDATA_CLOUD_SIZE_Z             = 10102, // long
	MDATA_CLOUD_SIZE_APPLY         = 10103, // button


	MDATA_CLOUD_SMOOTH_BORDERS     = 10200, // button
	MDATA_CLOUD_SMOOTH_B_DIST      = 10201, // real
	MDATA_CLOUD_SMOOTH_B_VAR       = 10202, // real
	MDATA_CLOUD_SMOOTH_B_SPLINE    = 10203, // spline
	MDATA_CLOUD_SMOOTH_ALL         = 10210, // button
	MDATA_CLOUD_SMOOTH_A_STR       = 10211, // real
	MDATA_CLOUD_SMOOTH_A_VARIANCE  = 10212, // real

	MDATA_CLOUD_CLEAR              = 10301, // clean
	MDATA_CLOUD_FILL_PLANE         = 10302, // fill plane with full density
	MDATA_CLOUD_FILL_SPHERE        = 10303, // fill with a sphere

	MDATA_CLOUD_REMAP_SPLINE       = 10401, // spline
	MDATA_CLOUD_REMAP              = 10402, // button

	MDATA_TOOLRAD                  = 20000, // real

	MDATA_CLOUD_CREATE_BRUSH_RAD   = 21000, // meter
	MDATA_CLOUD_CREATE_DENSITY     = 21001, // real
	MDATA_CLOUD_CREATE_MAX_SIZE    = 21002, // vector
	MDATA_CLOUD_DRAW_THRESHOLD     = 21003, // real

	MDATA_CLOUD_DISPLAY            = 29990,
	MDATA_CLOUD_SIZE               = 29991,
	MDATA_CLOUD_TOOLS              = 29992,
	MDATA_CLOUD_SMOOTHING          = 29993,

	MDATA_CLOUD_
};

#endif // TOOLCLOUD_H__
