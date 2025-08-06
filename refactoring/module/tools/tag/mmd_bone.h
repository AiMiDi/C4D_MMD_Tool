/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone.cpp
Description:	DESC

**************************************************************************/

#ifndef MMD_BONE_H__
#define MMD_BONE_H__
#include "description/OMMDBoneManager.h"

class MMDBoneManagerObject;

namespace CMTToolsSetting
{
	struct MotionImport;
}

struct MMDBoneManagerObjectMsg;

enum class MMDBoneTagMsgType : int8_t
{
	DEFAULT = -1,
	BONE_INDEX_CHANGE,
};

class MMDBoneTagMsg
{
public:
	MMDBoneTagMsgType type;
	explicit MMDBoneTagMsg(const MMDBoneTagMsgType type = MMDBoneTagMsgType::DEFAULT);
	virtual ~MMDBoneTagMsg() = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDBoneTagMsg)
	CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(MMDBoneTagMsg)
};

/**
 * @class MMDBoneTag
 * @brief This class represents a bone tag used in the MMDTool module.
 *
 * The MMDBoneTag class is responsible for managing bone data and operations related to bone manipulation.
 * It provides functions for setting bone root and bone object, initializing the tag, handling messages, executing the tag, and reading/writing data.
 * Additionally, it supports bone morphs, bone protection, and physical bones.
 */
class MMDBoneTag final : public TagData
{
	libmmd::MMDNode* mmd_node_ = nullptr;

	// Bone root object
	BaseObject* bone_manager_ = nullptr;
	MMDBoneManagerObject* bone_manager_node_ = nullptr;
	// Corresponding bone object
	BaseObject* bone_object_ = nullptr;
	// Bone tag
	BaseTag* bone_tag_ = nullptr;
	// Protection tag for limiting bone movement
	BaseTag* protection_tag_ = nullptr;

	Int32 bone_mode_ = BONE_MODE_ANIM;

	friend class MMDBoneManagerObject;

	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDBoneTag)
	CMT_DEFAULT_MOVE_BODY(MMDBoneTag)
	INSTANCEOF(MMDBoneTag, TagData)

public:
	/**
	 * @brief Default constructor for MMDBoneTag.
	 */
	MMDBoneTag() = default;

	/**
	 * @brief Default destructor for MMDBoneTag.
	 */
	~MMDBoneTag() override = default;

	/**
	 * @brief Allocates a new instance of MMDBoneTag.
	 * @return A pointer to the newly allocated MMDBoneTag instance.
	 */
	static NodeData* Alloc();

	/**
	 * @brief Initializes the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] isCloneInit The initialization parameters.
	 * @return true if initialization is successful, false otherwise.
	 */
	Bool Init(GeListNode* node SDK2024_InitParaName) override;

	/**
	 * @brief Handles messages sent to the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] type The type of the message.
	 * @param[in] data The message data.
	 * @return true if the message is handled, false otherwise.
	 */
	Bool Message(GeListNode* node, Int32 type, void* data) override;

	/**
	 * @brief Sets a dynamic parameter of the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] id The ID of the parameter.
	 * @param[in] t_data The data to set.
	 * @param[in,out] flags The flags indicating the status of the parameter.
	 * @return true if the parameter is set successfully, false otherwise.
	 */
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;

	/**
	 * @brief Gets the enabling status of a dynamic parameter of the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] id The ID of the parameter.
	 * @param[in] t_data The data of the parameter.
	 * @param[in] flags The flags indicating the status of the parameter.
	 * @param[in] itemdesc The description of the item.
	 * @return The enabling status of the parameter.
	 */
	Bool GetDEnabling(SDK2024_Const GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) SDK2024_Const override;

	/**
	 * @brief Executes the MMDBoneTag.
	 * @param[in] tag The BaseTag representing the MMDBoneTag.
	 * @param[in] doc The BaseDocument containing the MMDBoneTag.
	 * @param[in] op The BaseObject associated with the MMDBoneTag.
	 * @param[in] bt The BaseThread for execution.
	 * @param[in] priority The execution priority.
	 * @param[in] flags The execution flags.
	 * @return The execution result.
	 */
	EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;

	/**
	 * @brief Reads the MMDBoneTag from a HyperFile.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] hf The HyperFile to read from.
	 * @param[in] level The read level.
	 * @return true if the MMDBoneTag is read successfully, false otherwise.
	 */
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;

	/**
	 * @brief Writes the MMDBoneTag to a HyperFile.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] hf The HyperFile to write to.
	 * @return true if the MMDBoneTag is written successfully, false otherwise.
	 */
	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;

	/**
	 * @brief Refreshes the color of the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] op The BaseObject associated with the MMDBoneTag.
	 * @return true if the color is refreshed successfully, false otherwise.
	 */
	Bool RefreshColor(GeListNode* node = nullptr, BaseObject* op = nullptr);

	/**
	 * @brief Gets the bone index of the MMDBoneTag.
	 * @return The bone index.
	 */
	Int32 GetBoneIndex() const;

private:
	/**
	 * @brief Creates a bone lock tag for the MMDBoneTag.
	 * @return true if the bone lock tag is created successfully, false otherwise.
	 */
	bool CreateBoneLockTag();

	/**
	 * @brief Handles bone lock updates for the MMDBoneTag.
	 * @param allow_rotate
	 * @param allow_translate
	 */
	void HandleBoneLockUpdate(Bool allow_rotate, Bool allow_translate);

	/**
	 * @brief Handles description updates for the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] bc The BaseContainer containing the description data.
	 * @param[in] id The ID of the description.
	 */
	void HandleDescriptionUpdate(GeListNode* node, BaseContainer* bc, Int32 id);

	void HandleBoneModeChange(Int32 bone_mode);

	/**
	 * @brief Sets the rotation lock for the MMDBoneTag.
	 * @param[in] flag The rotation lock flag.
	 */
	void SetRotationLock(bool flag) const;

	/**
	 * @brief Sets the position lock for the MMDBoneTag.
	 * @param[in] flag The position lock flag.
	 */
	void SetPositionLock(bool flag) const;

	/**
	 * @brief Sets the bone display for the MMDBoneTag.
	 *
	 * This function is responsible for setting the display properties of the bone
	 * based on the provided data instance and root object message.
	 *
	 * @param[in] data_instance_bc The BaseContainer containing the data instance.
	 * @param[in] msg The MMDBoneRootObjectMsg containing the root object message.
	 */
	void SetBoneDisplay(const BaseContainer* data_instance_bc, const MMDBoneManagerObjectMsg* msg) const;

	/**
	 * @brief Updates the bone root for the MMDBoneTag.
	 *
	 * This function is responsible for updating the bone root properties based on
	 * the provided data instance and root object message.
	 *
	 * @param[in] data_instance_bc The BaseContainer containing the data instance.
	 * @param[in] msg The MMDBoneRootObjectMsg containing the root object message.
	 */
	void HandleBoneHierarchyUpdate(BaseContainer* data_instance_bc, const MMDBoneManagerObjectMsg* msg);
};

#endif // MMD_BONE_H__
