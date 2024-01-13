/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2022/10/2
File:			mmd_camera.h
Description:	C4D MMD camera object

**************************************************************************/

#ifndef MMD_CAMERA_H__
#define MMD_CAMERA_H__

#include "cmt_tools_setting.h"
#include "description/OMMDCamera.h"
#include "module/tools/mmd_interpolator.hpp"

using MMDCameraBase = MMDInterpolatorNode<ObjectData, 8, VMD_CAM_OBJ_INTERPOLATOR_NUM, VMD_CAM_OBJ_SPLINE, VMD_CAM_OBJ_CURVE_TYPE, VMD_CAM_OBJ_FRAME_AT, VMD_CAM_OBJ_FRAME_AT_STR>;

class MMDCamera final : public MMDCameraBase
{
	INSTANCEOF(MMDCamera, MMDCameraBase)

	// Default camera distance
	inline static Float default_distance = 0;

	// Maintained camera object
	BaseObject* m_camera = nullptr;
	BaseTag*    m_protection_tag = nullptr;

	std::once_flag m_init_flag{};
	bool m_is_setup_spline_callback = false;

	enum track_enum : uint8_t
	{
		POSITION_X,
		POSITION_Y,
		POSITION_Z,
		ROTATION_X,
		ROTATION_Y,
		ROTATION_Z,
		DISTANCE,
		AOV
	};

public:
	// Constructor function
	MMDCamera() = default;

	// Destructor function
	~MMDCamera() override = default;

	/**
	 * \brief Default copy constructor.
	 * \param other The object to be copied from.
	 */
	MMDCamera(const MMDCamera& other) = delete;

	/**
	 * \brief Default copy assignment operator.
	 * \param other The object to be copied from.
	 * \return A reference to this object.
	 */
	MMDCamera& operator=(const MMDCamera& other) = delete;

	/**
	 * \brief Default move constructor.
	 * \param other The object to be moved from.
	 */
	MMDCamera(MMDCamera&& other) noexcept;

	/**
	 * \brief Default move assignment operator.
	 * \param other The object to be moved from.
	 * \return A reference to this object.
	 */
	MMDCamera& operator=(MMDCamera&& other) noexcept;

public:
	// Get maintained camera object
	[[nodiscard]] BaseObject* GetCamera() const;

	// Initialize camera object
	Bool CameraInit(GeListNode* node = nullptr);

	Bool LoadVMDCamera(const libmmd::vmd_animation& vmd_data, const CMTToolsSetting::CameraImport& setting);

	Bool SaveVMDCamera(libmmd::vmd_animation* vmd_data, const CMTToolsSetting::CameraExport& setting);

	// Convert a normal camera to a MMD camera
	Bool ConversionCamera(const CMTToolsSetting::CameraConversion& setting);

	// Generating function
	static NodeData* Alloc();

private:
	bool ConversionCameraCurve(CCurve* src_curve_position, const size_t& curve_type, const Int32& frame_count, const Float& fps);

	static TrackDescIDArray GetTrackDescIDsImpl();

	static void AddToSceneManager(BaseObject* object);
public:
	// Object initialization
	Bool Init(GeListNode* node SDK2024_InitParaName) override;

	Bool CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;

	// Called to override the writing of parameters. The callback function used to call SplineData.
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;

	// Called when a node receives messages.
	Bool Message(GeListNode* node, Int32 type, void* data) override;

	// Called at the point in the priority pipeline specified by AddToExecution, or the lack thereof.
	EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;

	Bool AddToExecution(BaseObject* op, PriorityList* list) override;

protected:
	TrackDescIDArray GetTrackDescIDs() override;

	TrackObjectArray GetTrackObjects(GeListNode* node) override;

	CurrentValuesArray GetCurrentValues(GeListNode* node) override;

	InterpolatorTrackTableArray GetTrackInterpolatorMap() override;
};


#endif // !MMD_CAMERA_H__
