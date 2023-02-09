/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & Walter White & CMT contributors.
Author:			Aimidi
Date:			2022/10/2
File:			o_mmd_camera.h
Description:	C4D MMD camera object

**************************************************************************/

#ifndef _MMD_CAMERA_H_
#define _MMD_CAMERA_H_

#include "cmt_tools_setting.h"
#include "description/OMMDCamera.h"
#include "module/MMD/vmd_camera.h"
#include "module/MMD/vmd_interpolator.h"
#include "module/tools/mmd_interpolator.hpp"

using MMDCameraBase = MMDInterpolator<ObjectData, VMDCameraInterpolator, 9>;

class MMDCamera final : public MMDCameraBase
{
	INSTANCEOF(OMMDCamera, MMDCameraBase)

	// Default camera distance
	inline static Float default_distance = 0;

	// Maintained camera object
	BaseObject* m_camera = nullptr;
	
	BaseTag* m_protection_tag = nullptr;

	//Track DESC ID table
	inline static const DescID m_track_desc_IDs[]
	{
		DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_X),
		DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Y),
		DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z),
		DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_X),
		DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Y),
		DescID(ID_BASEOBJECT_REL_ROTATION, VECTOR_Z),
		DescID(ID_BASEOBJECT_REL_POSITION, VECTOR_Z),
		DescID(CAMERAOBJECT_APERTURE),
		DescID(VMD_CAM_OBJ_FRAME_ON)
	};
public:
	// Constructor function
	MMDCamera() : MMDCameraBase(VMD_CAM_OBJ_SPLINE, VMD_CAM_OBJ_CURVE_TYPE, VMD_CAM_OBJ_FRAME_ON, VMD_CAM_OBJ_ACURVE) {}

	// Destructor function
	~MMDCamera() override = default;

public:
	// Get maintained camera object
	[[nodiscard]] BaseObject* GetCamera() const
	{
		return m_camera;
	}

	// Initialize camera object
	Bool CameraInit(GeListNode* node = nullptr);

	Bool SetFrom(const std::unique_ptr<VMDCameraData>& data);

	// Convert a normal camera to a MMD camera
	static BaseObject* ConversionCamera(const cmt_tools_setting::CameraConversion& setting);

	// Generating function
	static NodeData* Alloc()
	{
		return NewObjClear(MMDCamera);
	}

private:
	static bool ConversionCameraCurve(MMDCamera* camera_data, CCurve* src_curve_position, Int32 curve_type, Int32 frame_count);


public:
	// Object initialization
	Bool Init(GeListNode* node = nullptr) override;

	// Called to override the writing of parameters. The callback function used to call SplineData.
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;

	// Called to decide which description parameters should be enabled or disabled.
	Bool GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) override;

	// Called when a node receives messages.
	Bool Message(GeListNode* node, Int32 type, void* data) override;

	// Called at the point in the priority pipeline specified by AddToExecution, or the lack thereof.
	EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;

protected:
	TrackDescIDSpan GetTrackDescIDs() override;

	TrackObjectSpan GetTrackObjects(GeListNode* node) override;

	KeyDefaultValueSpan GetKeyDefaultValue(GeListNode* node) override;

	TrackInterpolatorSpan GetTrackInterpolatorMap() override;
};


#endif // !MMD_CAMERA_H
