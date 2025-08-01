/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/09/12
File:			mmd_joint_root.cpp
Description:	MMD joint root object

**************************************************************************/

#ifndef MMD_JOINT_ROOT_H__
#define MMD_JOINT_ROOT_H__
#include "mmd_manager.hpp"
#include "description/OMMDJointManager.h"

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
	Float32 position_multiple_ = 1.f;
	BaseObject* bone_manager_ = nullptr;
	BaseObject* rigid_manager_ = nullptr;
	MMDBoneManagerObject* bone_manager_data_ = nullptr;
	MMDRigidManagerObject* rigid_manager_data_ = nullptr;
	MMDJointManagerObject() {}
	~MMDJointManagerObject() override = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDJointManagerObject)
	CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(MMDJointManagerObject)
	INSTANCEOF(MMDJointManagerObject, MMDManagerObject)
public:
	static NodeData* Alloc();
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;
	Bool CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;
	BaseObject* AddJoint(const String& name, GeListNode* node = nullptr);
	Bool Message(GeListNode* node, Int32 type, void* data) override;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
	const Float32& GetPositionMultiple() const { return position_multiple_; }

	MMDBoneManagerObject* GetBoneManager() const;
	MMDRigidManagerObject* GetRigidManager() const;

	Bool LoadPMX(const libmmd::PMXFile& pmx_file, const MMDModelPtr& pmx_model, const CMTToolsSetting::ModelImport& setting);
};

#endif // !MMD_JOINT_ROOT_H__
