/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/09/12
File:			mmd_joint_root.cpp
Description:	MMD joint root object

**************************************************************************/

#pragma once

#include "mmd_manager.hpp"
#include "description/OMMDJointManager.h"

class MMDModelManagerObject;
namespace libmmd
{
	class MMDPhysicsManager;
	class MMDJoint;
	struct PMXFile;
}

namespace CMTToolsSetting
{
	struct ModelImport;
}

class MMDRigidManagerObject;
class MMDBoneManagerObject;

enum class MMDJointRootObjectMsgType : uint8_t
{
	DEFAULT,
	JOINT_DISPLAY_CHANGE,
	JOINT_MODE_CHANGE
};

struct MMDJointRootObjectMsg
{
	MMDJointRootObjectMsgType type = MMDJointRootObjectMsgType::DEFAULT;
	Int32	display_type = JOINT_DISPLAY_TYPE_OFF;
	Int32	mode = JOINT_MODE_ANIM;

	explicit MMDJointRootObjectMsg(const MMDJointRootObjectMsgType type = MMDJointRootObjectMsgType::DEFAULT,
	                               const Int32 display_type = JOINT_DISPLAY_TYPE_OFF,
	                               const Int32 mode = JOINT_MODE_ANIM):
	type(type), display_type(display_type), mode(mode){}

	explicit MMDJointRootObjectMsg(const MMDJointRootObjectMsgType type_ = MMDJointRootObjectMsgType::DEFAULT) : type(type_) {}
};

class MMDJointManagerObject final : public MMDManagerObject
{
	Int32 joint_name_index_ = 1;
	AutoAlloc<BaseLink> bone_manager_link_;
	AutoAlloc<BaseLink> rigid_manager_link_;
	MMDBoneManagerObject* bone_manager_data_ = nullptr;
	MMDRigidManagerObject* rigid_manager_data_ = nullptr;
	libmmd::MMDPhysicsManager* mmd_physics_manager_ = nullptr;
	MMDJointManagerObject() {}
	~MMDJointManagerObject() override = default;
	friend MMDModelManagerObject;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDJointManagerObject)
	CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(MMDJointManagerObject)
	INSTANCEOF(MMDJointManagerObject, MMDManagerObject)
public:
	static NodeData* Alloc();
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	SDK2024_WriteOverride;
	SDK2024_CopyToOverride;
	Bool Message(GeListNode* node, Int32 type, void* data) override;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;

	MMDBoneManagerObject* GetBoneManager();
	MMDRigidManagerObject* GetRigidManager();
	BaseObject* AddJoint(const String& name, libmmd::MMDJoint* mmd_joint, GeListNode* node = nullptr);

	Bool LoadPMX(const libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelImport& setting);

	Bool BuildStandaloneJoints(libmmd::MMDPhysicsManager* physics_manager);
	void ReconnectJointPointers(libmmd::MMDPhysicsManager* physics_manager);
	void SetAllJointMode(Int32 mode, BaseObject* joint_manager_object = nullptr);
	void CommitEditorTransforms(BaseObject* joint_manager_object);
	void RestoreEditorTransforms(BaseObject* joint_manager_object);
};
