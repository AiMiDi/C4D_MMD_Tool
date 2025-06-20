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

class MMDCamera final : public ObjectData
{
	INSTANCEOF(MMDCamera, ObjectData)

	static constexpr size_t track_count = 8;
	static constexpr auto frame_at_desc = ConstDescID(DescLevel(VMD_CAM_OBJ_FRAME_AT));

	// Maintained camera object
	BaseObject* camera_ = nullptr;
	BaseTag*      protection_tag_ = nullptr;

	std::once_flag added_to_manager_flag_{};

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

	// Get maintained camera object
	[[nodiscard]] BaseObject* GetCamera() const;

	// Initialize camera object
	Bool InitCamera(GeListNode* node = nullptr);

	Bool LoadVMDCamera(const std::unique_ptr<saba::VMDCameraAnimation>& animation, const CMTToolsSetting::CameraImport& setting);

	Bool SaveVMDCamera(saba::VMDFile& vmd_data, const CMTToolsSetting::CameraExport& setting);

	// Convert a normal camera to a MMD camera
	Bool ConversionCamera(const CMTToolsSetting::CameraConversion& setting);

	// Generating function
	static NodeData* Alloc();

	// Object initialization
	Bool Init(GeListNode* node SDK2024_InitParaName) override;

	Bool CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;

	// Called when a node receives messages.
	Bool Message(GeListNode* node, Int32 type, void* data) override;

	// Called at the point in the priority pipeline specified by AddToExecution, or the lack thereof.
	EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;

	Bool AddToExecution(BaseObject* op, PriorityList* list) override;

private:
	using TrackDescIDArray = std::array<const DescID, track_count>;
	using TrackObjectArray = std::array<BaseObject*, track_count>;

	static void AddToSceneManager(BaseObject* object);

	static TrackDescIDArray GetTrackDescIDs();

	TrackObjectArray GetTrackObjects(GeListNode* node) const;
};

#endif // !MMD_CAMERA_H__
