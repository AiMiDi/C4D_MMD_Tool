/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/09/12
File:			mmd_joint_root.cpp
Description:	MMD joint root object

**************************************************************************/

#ifndef MMD_JOINT_ROOT_H__
#define MMD_JOINT_ROOT_H__
#include "mmd_root.hpp"
#include "description/OMMDJointRoot.h"

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

class MMDJointRootObject final : public MMDRootObject
{
	Int64 m_joint_name_index = 1;
	BaseObject* m_bone_root = nullptr;
	BaseObject* m_rigid_root = nullptr;
	MMDJointRootObject() {}
	~MMDJointRootObject() override = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDJointRootObject)
	CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(MMDJointRootObject)
	INSTANCEOF(MMDJointRootObject, MMDRootObject)
public:
	static NodeData* Alloc();
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;
	Bool CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;
	Bool Message(GeListNode* node, Int32 type, void* data) override;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;

	BaseObject* GetRigidRoot() const;
	BaseObject* GetBoneRoot() const;

};

#endif // !MMD_JOINT_ROOT_H__
