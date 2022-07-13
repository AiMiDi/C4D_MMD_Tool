/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/7/2
File:			vmd_data.h
Description:	vmd file data

**************************************************************************/

#ifndef _VMD_DATA_H_
#define _VMD_DATA_H_

#include "pch.h"
#include "vmd_interpolator.h"

/* MMD style bone animation. */
struct VMDBoneAnimation
{
	String			bone_name{};                  /* The action corresponds to the bone name. */
	UInt32			frame_no = 0;                 /* Frame of action. */
	Vector32		position{};                   /* The action corresponds to the bone position. */
	Vector4d32		rotation{};                   /* The action corresponds to the rotation of the bone (quad). */
	VMDInterpolator interpolator_position_x{};    /* X-axis displacement action interpolation. */
	VMDInterpolator interpolator_position_y{};    /* Y-axis displacement action interpolation. */
	VMDInterpolator interpolator_position_z{};    /* Z-axis displacement action interpolation. */
	VMDInterpolator interpolator_rotation  {};    /* Rotation action interpolation. */
};
/* MMD style expression animation. */
struct VMDMorphAnimation
{
	String	morph_name{};                          /* The action corresponds to the expression name. */
	UInt32	frame_no = 0;                          /* Frame of action. */
	Float32 weight = 0.f;                          /* Expression deformation strength. */
};
/* MMD风格的摄像机动画 */
struct VMDCameraAnimation
{
	UInt32		frame_no = 0;                     /* Frame of action. */
	Float32		distance = 0.f;                   /* Camera view distance. */
	Vector32	position{};						  /* View position of the camera. */
	Vector32	rotation{};						  /* Camera view rotation (Euler Angle of x and Y reversal) */
	VMDInterpolator interpolator_position_x{};    /* X-axis displacement action interpolation. */
	VMDInterpolator interpolator_position_y{};    /* Y-axis displacement action interpolation. */
	VMDInterpolator interpolator_position_z{};    /* Z-axis displacement action interpolation. */
	VMDInterpolator interpolator_rotation  {};    /* Rotation action interpolation. */
	VMDInterpolator interpolator_position_d{};    /* Distance action interpolation. */
	VMDInterpolator interpolator_position_v{};    /* View Angle motion interpolation */
	UInt32		viewing_angle = 0;                /* View Angle. */
	UChar		perspective = 0;                  /* 0:on, 1:off */
};
/* MMD style lighting animation */
struct VMDLightAnimation
{
	UInt32		frame_no = 0;                                       /* Frame of action. */
	Vector32	rgb{};                                   /* Light color. */
	Vector32	position{};                              /* location. */
};
/* MMD style shadow animation */
struct VMDShadowAnimation
{
	UInt32	frame_no = 0;                                           /* Frame of action. */
	UChar	shadowType = 0;                                         /* 0:Off 1:mode1 2:mode2 */
	Float32 distance = 0.f;                                         /* Distance. */
};



#endif // !_VMD_DATA_H_