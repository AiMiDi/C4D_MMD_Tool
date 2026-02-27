/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone.cpp
Description:	DESC

**************************************************************************/

#pragma once

#include <c4d.h>
#include "module/core/cmt_marco.h"
#include "description/OMMDBoneManager.h"
#include "maxon/pointerarray.h"

namespace libmmd { class MMDIkSolver; }

class MMDBoneManagerObject;
struct MMDBoneManagerObjectMsg;

namespace CMTToolsSetting
{
	struct MotionImport;
}


struct BoneMorphTagData
{
	DescID	grp_id;
	DescID	strength_id;
	DescID	translation_id;
	DescID	rotation_id;
	DescID	button_grp_id;
	DescID	button_delete_id;
	DescID	button_rename_id;
	String	name;

	BoneMorphTagData() = default;
	BoneMorphTagData(const BoneMorphTagData&) = delete;
	BoneMorphTagData& operator=(const BoneMorphTagData&) = delete;
	BoneMorphTagData(BoneMorphTagData&& other) noexcept = default;
	BoneMorphTagData& operator=(BoneMorphTagData&& other) noexcept = default;

	Bool Write(HyperFile* hf) SDK2024_Const;
	Bool Read(HyperFile* hf);
};

enum class MMDBoneTagMsgType : int8_t
{
	DEFAULT = -1,
	BONE_INDEX_CHANGE,
	BONE_MORPH_ADD,
	BONE_MORPH_DELETE,
	BONE_MORPH_RENAME
};

class MMDBoneTagMsg
{
public:
	MMDBoneTagMsgType type;
	String name;
	String name_old;
	BaseTag* bone_tag = nullptr;
	DescID strength_id;

	explicit MMDBoneTagMsg(const MMDBoneTagMsgType in_type = MMDBoneTagMsgType::DEFAULT) : type(in_type) {}
	MMDBoneTagMsg(MMDBoneTagMsgType in_type, const String& name_, const DescID& strength_id_, BaseTag* tag_)
		: type(in_type), name(name_), bone_tag(tag_), strength_id(strength_id_) {}
	MMDBoneTagMsg(MMDBoneTagMsgType in_type, const String& name_, const DescID& strength_id_, BaseTag* tag_, const String& old_name_)
		: type(in_type), name(name_), name_old(old_name_), bone_tag(tag_), strength_id(strength_id_) {}
	virtual ~MMDBoneTagMsg() = default;
	MMDBoneTagMsg(const MMDBoneTagMsg&) = delete; void operator =(const MMDBoneTagMsg&) = delete;
	MMDBoneTagMsg(MMDBoneTagMsg&&) = delete; void operator =(MMDBoneTagMsg&&) = delete;
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
	// Bone MMD node
	libmmd::MMDNode* mmd_node_ = nullptr;
	// IK solver (non-null only for IK bones)
	libmmd::MMDIkSolver* ik_solver_ = nullptr;
	// Bone manager ObjectData
	MMDBoneManagerObject* bone_manager_data_ = nullptr;
	// Corresponding bone object
	BaseObject* bone_object_ = nullptr;
	// Protection tag for limiting bone movement
	BaseTag* protection_tag_ = nullptr;
	// Bone mode
	Int32 bone_mode_ = BONE_MODE_ANIM;
	// Is IK
	Bool is_IK = false;

	// Bone morph data
	Int32 bone_morph_name_index_ = 0;
	maxon::PointerArray<BoneMorphTagData> bone_morph_data_arr_;
	maxon::HashMap<DescID, Int32> bone_morph_button_id_map_;
	Vector prev_position_;
	Vector prev_rotation_;

	friend class MMDBoneManagerObject;

public:
	MMDBoneTag(const MMDBoneTag&) = delete; void operator =(const MMDBoneTag&) = delete;
	MMDBoneTag(MMDBoneTag&&) noexcept = default; MMDBoneTag& operator =(MMDBoneTag&&) noexcept = default;
	typedef TagData SUPER;

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
	SDK2024_InitOverride;

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
	SDK2024_GetDEnablingOverride;

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
	SDK2024_WriteOverride;

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

	Int32 AddBoneMorph(String morph_name = {});
	Bool SetBoneMorphTranslationNoCheck(Int32 id, Vector translation);
	Bool SetBoneMorphRotationNoCheck(Int32 id, Vector rotation);

private:
	void HandleBoneMorphButtonCommand(const DescID& desc_id);
	/**
	 * @brief Creates a bone lock tag for the MMDBoneTag.
	 * @return true if the bone lock tag is created successfully, false otherwise.
	 */
	bool CreateBoneLockTag();

	/**
	 * @brief Handles description updates for the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] bc The BaseContainer containing the description data.
	 * @param[in] id The ID of the description.
	 */
	void HandleDescriptionUpdate(GeListNode* node, BaseContainer* bc, Int32 id);

	void HandleBoneModeChange(Int32 bone_mode);

	void RebuildIKChains();

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
	 * @param[in] bc The BaseContainer containing the data instance.
	 * @param[in] bone_manager_object The MMDBoneRootObjectMsg containing the root object message.
	 */
	void HandleBoneIndexUpdate(BaseContainer* bc, BaseObject* bone_manager_object) const;
};
