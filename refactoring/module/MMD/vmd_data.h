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

class VMDInterpolator
{
	UChar m_ax, m_ay, m_bx, m_by;
	Bool m_isLinear;
public:
	/* Partial types of interpolator data */
	enum class PartType { ax, ay, bx, by };
	/* Constructor function */
	VMDInterpolator(const UChar ax = 20U, const UChar ay = 20U, const UChar bx = 107U, const UChar by = 107U);
	VMDInterpolator(const VMDInterpolator&) noexcept = default;

	[[nodiscard]] Bool IsLinear() const;
	/* Sets the value of the interpolator. If the parameter is empty, set the default value. */
	void SetValue(UChar ax = 20U, UChar ay = 20U, UChar bx = 107U, UChar by = 107U);
	/* Gets the interpolator value. */
	[[nodiscard]] UChar GetValue(const PartType& part) const;
	/* Hash function */
	[[nodiscard]] maxon::HashInt GetHashCode() const
	{
		return MAXON_HASHCODE(this->m_ax, this->m_ay, this->m_bx, this->m_by);
	}
	/* Read bone interpolator information from a file */
	Bool ReadBoneInterpolator(BaseFile* const file);
	/* Read the camera interpolator information from the file. */
	Bool ReadCameraInterpolator(BaseFile* const file);
	/* Write the bone interpolator information to the file. */
	Bool WriteBoneInterpolator(BaseFile* const file) const
	{
		if (!file->WriteUChar(this->m_ax))
			return false;
		if (!file->WriteUChar(this->m_ax))
			return false;
		if (!file->WriteUChar(this->m_ax))
			return false;
		if (!file->WriteUChar(this->m_ax))
			return false;
		if (!file->WriteUChar(this->m_ay))
			return false;
		if (!file->WriteUChar(this->m_ay))
			return false;
		if (!file->WriteUChar(this->m_ay))
			return false;
		if (!file->WriteUChar(this->m_ay))
			return false;
		if (!file->WriteUChar(this->m_bx))
			return false;
		if (!file->WriteUChar(this->m_bx))
			return false;
		if (!file->WriteUChar(this->m_bx))
			return false;
		if (!file->WriteUChar(this->m_bx))
			return false;
		if (!file->WriteUChar(this->m_by))
			return false;
		if (!file->WriteUChar(this->m_by))
			return false;
		if (!file->WriteUChar(this->m_by))
			return false;
		if (!file->WriteUChar(this->m_by))
			return false;
		return true;
	}
	/* Write the camera interpolator information to the file. */
	Bool WriteCameraInterpolator(BaseFile* const file) const
	{
		if (!file->WriteUChar(this->m_ax))
			return false;
		if (!file->WriteUChar(this->m_bx))
			return false;
		if (!file->WriteUChar(this->m_ay))
			return false;
		if (!file->WriteUChar(this->m_by))
			return false;
		return true;
	}
};
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
/* MMD style IK enable information */
struct VMDIkControllerAnimation
{
	String	name{};                                        /* IK name. */
	Bool	enable = true;                                          /* Is enable. */
	/* Constructor function */
	VMDIkControllerAnimation() = default;
	VMDIkControllerAnimation(String name_, const Bool enable_ = true) : name(std::move(name_)), enable(enable_) {}
};
/* MMD style model information animation */
class VMDModelControllerAnimation
{
	UInt32				m_frame_on = 0;                                   /* Frame of action. */
	Bool				m_show = true;                                    /* Is m_show. */
	maxon::PointerArray<VMDIkControllerAnimation> m_IK_Info_array;        /* IKs enable information. */
public:
	/* Constructor function */
	VMDModelControllerAnimation(const UInt32 frame_no, const Bool show) :m_frame_on(frame_no), m_show(show) {}
	/* Copy constructor */
	VMDModelControllerAnimation(const VMDModelControllerAnimation& src);
	/* Move constructor */
	VMDModelControllerAnimation(VMDModelControllerAnimation&& src) noexcept;
	/* operator= Copy*/
	VMDModelControllerAnimation& operator =(const VMDModelControllerAnimation& src);
	/* operator= Move*/
	VMDModelControllerAnimation& operator =(VMDModelControllerAnimation&& src) noexcept;

	Bool ReadFormFile(const BaseFile* file)
	{
		if(!file)
		{
			return false;
		}
		return true;
	}

	Bool WriteToFile(const BaseFile* file)
	{
		if (!file)
		{
			return false;
		}
		return true;
	}

	[[nodiscard]] UInt32 GetFrameOn() const
	{
		return m_frame_on;
	}

	[[nodiscard]] Bool IsShow() const
	{
		return m_show;
	}
};

#endif // !_VMD_DATA_H_