/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_bone.cpp
Description:	DESC

**************************************************************************/

#ifndef MMD_BONE_H__
#define MMD_BONE_H__

#include "description/TMMDBone.h"
#include "module/tools/mmd_interpolator.hpp"
#include "utils/morph_ui_data_util.hpp"

namespace CMTToolsSetting
{
	struct MotionImport;
}

struct MMDBoneRootObjectMsg;

struct BoneMorphData
{
	String name;
	DescID grp_id;

	DescID strength_id;
	DescID translation_id;
	DescID rotation_id;

	DescID button_grp_id;
	DescID button_delete_id;
	DescID button_rename_id;
	
	BoneMorphData(
		String name = String(),
		DescID grp_id = DescID(),
		DescID strength_id = DescID(),
		DescID translation_id = DescID(),
		DescID rotation_id = DescID(),
		DescID button_grp_id = DescID(),
		DescID button_delete_id = DescID(),
		DescID button_rename_id = DescID()
	);
	~BoneMorphData() = default;

	Bool Write(HyperFile* hf) SDK2024_Const;
	Bool Read(HyperFile* hf);
	BoneMorphData(BoneMorphData&& src) noexcept :
	MAXON_MOVE_MEMBERS(name, grp_id, strength_id, translation_id, rotation_id, button_grp_id, button_delete_id, button_rename_id){}
	BoneMorphData& operator=(BoneMorphData&&) noexcept = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(BoneMorphData)
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
	explicit MMDBoneTagMsg(const MMDBoneTagMsgType type = MMDBoneTagMsgType::DEFAULT);
	virtual ~MMDBoneTagMsg() = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDBoneTagMsg)
	CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(MMDBoneTagMsg)
};

class MMDBoneTagBoneIndexChangeMsg final : public MMDBoneTagMsg
{
public:
	explicit MMDBoneTagBoneIndexChangeMsg();
	~MMDBoneTagBoneIndexChangeMsg() override = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDBoneTagBoneIndexChangeMsg)
	CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(MMDBoneTagBoneIndexChangeMsg)
};

class MMDBoneTagBoneMorphAddMsg final : public MMDBoneTagMsg
{
public:
	String	name;
	MorphUIData bone_morph_UI_data;

	explicit MMDBoneTagBoneMorphAddMsg(String name, SDK2024_Const BaseTag* bone_tag, const DescID& strength_id);
	~MMDBoneTagBoneMorphAddMsg() override = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDBoneTagBoneMorphAddMsg)
	CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(MMDBoneTagBoneMorphAddMsg)
};

class MMDBoneTagBoneMorphDeleteMsg final : public MMDBoneTagMsg
{
public:
	String	name;
	MorphUIData bone_morph_UI_data;

	explicit MMDBoneTagBoneMorphDeleteMsg(String name, SDK2024_Const BaseTag* bone_tag, const DescID& strength_id);
	~MMDBoneTagBoneMorphDeleteMsg() override = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDBoneTagBoneMorphDeleteMsg)
	CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(MMDBoneTagBoneMorphDeleteMsg)
};

class MMDBoneTagBoneMorphRenameMsg final : public MMDBoneTagMsg
{
public:
	String	old_name;
	String	new_name;
	MorphUIData bone_morph_UI_data;

	explicit MMDBoneTagBoneMorphRenameMsg(String old_name, String new_name, SDK2024_Const BaseTag* bone_tag, const DescID& strength_id);
	~MMDBoneTagBoneMorphRenameMsg() override = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDBoneTagBoneMorphRenameMsg)
	CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(MMDBoneTagBoneMorphRenameMsg)
};

using MMDBoneTagBase = MMDInterpolatorNode<TagData, 6, PMX_BONE_TAG_INTERPOLATOR_NUM, PMX_BONE_TAG_SPLINE, PMX_BONE_TAG_CURVE_TYPE, PMX_BONE_TAG_FRAME_AT, PMX_BONE_TAG_FRAME_AT_STR>;


/**
 * @class MMDBoneTag
 * @brief This class represents a bone tag used in the MMDTool module.
 * 
 * The MMDBoneTag class is responsible for managing bone data and operations related to bone manipulation.
 * It provides functions for setting bone root and bone object, initializing the tag, handling messages, executing the tag, and reading/writing data.
 * Additionally, it supports bone morphs, bone protection, and physical bones.
 */
class MMDBoneTag final : public MMDBoneTagBase
{
	// Bone index
	Int32 m_bone_index = -1;
	// Bone morph name index
	Int32 m_bone_morph_name_index = 0;
	// Store the previous frame to determine the update state
	Int32 prev_frame = -1;
	// Store the previous interpolator type to determine the update state
	Int32 prev_interpolator_type = -1;
	// Store the previous frame position for handling bone morphs
	Vector prev_position{};
	// Store the previous frame rotation for handling bone morphs
	Vector prev_rotation{};

	// Inherited bone parent object
	AutoAlloc<BaseLink> inherit_bone_parent;
	// Bone root object
	BaseObject* m_bone_root = nullptr;
	// Corresponding bone object
	BaseObject* m_bone_object = nullptr;
	// Bone tag
	BaseTag* m_bone_tag = nullptr;
	// Protection tag for limiting bone movement
	BaseTag* protection_tag = nullptr;
	// Flag indicating if it is a physical bone
	Bool m_is_physical_bone = false;

	// Store bone morph data
	maxon::BaseArray<BoneMorphData> bone_morph_data_arr;
	maxon::HashMap<DescID, Int> button_id_map;

	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDBoneTag)
	CMT_DEFAULT_MOVE_BODY(MMDBoneTag)
	INSTANCEOF(MMDBoneTag, MMDBoneTagBase)

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
	 * @brief Sets the bone root object.
	 * @param[in] bone_root The bone root object.
	 */
	void SetBoneRoot(BaseObject* bone_root);

	/**
	 * @brief Sets the bone object.
	 * @param[in] bone_object The bone object.
	 */
	void SetBoneObject(BaseObject* bone_object);

	Bool LoadVMD(const libmmd::vmd_bone_key_frame& data, const CMTToolsSetting::MotionImport& setting);

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
	 * @brief Checks if the MMDBoneTag represents a physical bone.
	 * @return true if the MMDBoneTag is a physical bone, false otherwise.
	 */
	[[nodiscard]] Bool IsPhysicalBone() const;

	/**
	 * @brief Sets the physical bone flag for the MMDBoneTag.
	 * @param[in] is_physical_bone The physical bone flag.
	 */
	void SetPhysical(Bool is_physical_bone);

	/**
	 * @brief Refreshes the color of the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] op The BaseObject associated with the MMDBoneTag.
	 * @return true if the color is refreshed successfully, false otherwise.
	 */
	Bool RefreshColor(GeListNode* node = nullptr, BaseObject* op = nullptr);

	/**
	 * @brief Adds a bone morph to the MMDBoneTag.
	 * @param[in] morph_name The name of the bone morph.
	 * @return The index of the added bone morph.
	 */
	Int AddBoneMorph(String morph_name);

	/**
	 * @brief Gets a bone morph from the MMDBoneTag.
	 * @param[in] index The index of the bone morph.
	 * @return A pointer to the bone morph data.
	 */
	BoneMorphData* GetBoneMorph(Int index);

	/**
	 * @brief Gets a bone morph from the MMDBoneTag without checking the index.
	 * @param[in] index The index of the bone morph.
	 * @return A pointer to the bone morph data.
	 */
	BoneMorphData* GetBoneMorphNoCheck(Int index);

	/**
	 * @brief Sets the translation of a bone morph in the MMDBoneTag.
	 * @param[in] index The index of the bone morph.
	 * @param[in] translation The translation vector.
	 * @return true if the translation is set successfully, false otherwise.
	 */
	Bool SetBoneMorphTranslation(Int index, const Vector& translation);

	/**
	 * @brief Sets the rotation of a bone morph in the MMDBoneTag.
	 * @param[in] index The index of the bone morph.
	 * @param[in] rotation The rotation vector.
	 * @return true if the rotation is set successfully, false otherwise.
	 */
	Bool SetBoneMorphRotation(Int index, const Vector& rotation);

	/**
	 * @brief Sets the translation of a bone morph in the MMDBoneTag without checking the index.
	 * @param[in] index The index of the bone morph.
	 * @param[in] translation The translation vector.
	 * @return true if the translation is set successfully, false otherwise.
	 */
	Bool SetBoneMorphTranslationNoCheck(Int index, const Vector& translation);

	/**
	 * @brief Sets the rotation of a bone morph in the MMDBoneTag without checking the index.
	 * @param[in] index The index of the bone morph.
	 * @param[in] rotation The rotation vector.
	 * @return true if the rotation is set successfully, false otherwise.
	 */
	Bool SetBoneMorphRotationNoCheck(Int index, const Vector& rotation);

	/**
	 * @brief Gets the number of bone morphs in the MMDBoneTag.
	 * @return The number of bone morphs.
	 */
	[[nodiscard]] Int GetBoneMorphCount() const;

	/**
	 * @brief Checks if the given bone morph index is valid.
	 * @param[in] index The index of the bone morph.
	 * @return true if the bone morph index is valid, false otherwise.
	 */
	[[nodiscard]] bool CheckBoneMorphIndex(Int index) const;

	/**
	 * @brief Gets the bone index of the MMDBoneTag.
	 * @return The bone index.
	 */
	Int32 GetBoneIndex() const;

protected:
	/**
	 * @brief Gets the track description IDs for the MMDBoneTag.
	 * @return An array of track description IDs.
	 */
	TrackDescIDArray GetTrackDescIDs() override;

	/**
	 * @brief Gets the track objects for the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @return An array of track objects.
	 */
	TrackObjectArray GetTrackObjects(GeListNode* node) override;

	/**
	 * @brief Gets the track interpolator map for the MMDBoneTag.
	 * @return An array of interpolator track tables.
	 */
	InterpolatorTrackTableArray GetTrackInterpolatorMap() override;

	/**
	 * @brief Gets the current values for the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @return An array of current values.
	 */
	CurrentValuesArray GetCurrentValues(GeListNode* node) override;

private:
	enum track_enum : uint8_t
	{
		POSITION_X,
		POSITION_Y,
		POSITION_Z,
		ROTATION_X,
		ROTATION_Y,
		ROTATION_Z
	};

	/**
	 * @brief Creates a bone lock tag for the MMDBoneTag.
	 * @return true if the bone lock tag is created successfully, false otherwise.
	 */
	bool CreateBoneLockTag();

	/**
	 * @brief Handles bone morph updates for the MMDBoneTag.
	 * @param[in] tag The BaseTag representing the MMDBoneTag.
	 * @param[in] op The BaseObject associated with the MMDBoneTag.
	 */
	void HandleBoneMorphUpdate(SDK2024_Const BaseTag* tag, BaseObject* op);

	/**
	 * @brief Handles bone index updates for the MMDBoneTag.
	 * @param[in] tag The BaseTag representing the MMDBoneTag.
	 * @param[in] op The BaseObject associated with the MMDBoneTag.
	 * @param[in] bc The BaseContainer containing the bone index.
	 */
	void HandleBoneIndexUpdate(BaseTag* tag, BaseObject* op, BaseContainer* bc);

	/**
	 * @brief Handles bone lock updates for the MMDBoneTag.
	 * @param[in] bc The BaseContainer containing the bone lock data.
	 */
	void HandleBoneLockUpdate(const BaseContainer* bc);

	/**
	 * @brief Handles description updates for the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] bc The BaseContainer containing the description data.
	 * @param[in] id The ID of the description.
	 */
	void HandleDescriptionUpdate(GeListNode* node, BaseContainer* bc, Int32 id);

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
	 * @brief Checks the user data button for the MMDBoneTag.
	 * @param[in] node The GeListNode representing the MMDBoneTag.
	 * @param[in] description_command The DescriptionCommand for the user data button.
	 */
	void CheckUserDataButton(GeListNode* node, const DescriptionCommand* description_command);

	void SetBoneDisplay(const BaseContainer* data_instance_bc, const MMDBoneRootObjectMsg* msg) const;

	void BoneRootUpdate(BaseContainer* data_instance_bc, const MMDBoneRootObjectMsg* msg);

	/**
	 * @brief Checks the inherit bone parent for the MMDBoneTag.
	 * @param[in] doc The BaseDocument containing the MMDBoneTag.
	 * @param[in] op The BaseObject associated with the MMDBoneTag.
	 * @param[in] bc The BaseContainer containing the inherit bone parent data.
	 */
	void HandleInheritParentBone(const BaseDocument* doc, BaseObject* op, const BaseContainer* bc);

	/**
	 * @brief Gets the track description IDs for the MMDBoneTag (implementation).
	 * @return An array of track description IDs.
	 */
	static TrackDescIDArray GetTrackDescIDsImpl();
};

#endif // MMD_BONE_H__
