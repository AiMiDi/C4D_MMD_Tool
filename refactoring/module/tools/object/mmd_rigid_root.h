/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/09/12
File:			mmd_rigid_root.cpp
Description:	MMD rigid root object

**************************************************************************/

#ifndef MMD_RIGID_ROOT_H__
#define MMD_RIGID_ROOT_H__
#include "description/OMMDRigidRoot.h"
#include "mmd_root.hpp"

enum class MMDRigidRootObjectMsgType : uint8_t
{
	DEFAULT,
	RIGID_DISPLAY_CHANGE,
	RIGID_MODE_CHANGE
};

struct MMDRigidRootObjectMsg
{
	MMDRigidRootObjectMsgType type;
	Int32	display_type;
	Int32	rigid_mode;

	explicit MMDRigidRootObjectMsg(const MMDRigidRootObjectMsgType type,
	                               const Int32 display_type = RIGID_DISPLAY_TYPE_OFF,
	                               const Int32 mode = RIGID_MODE_ANIM) : type(type), display_type(display_type), rigid_mode(mode){}
};

class MMDRigidRootObject final : public MMDRootObject
{
	Int64 m_rigid_name_index = 1;
	BaseContainer rigid_items;
	BaseObject* m_bone_root = nullptr;
	BaseObject* m_joint_root = nullptr;
	maxon::HashMap<Int32, maxon::StrongRef<AutoAlloc<BaseLink>>> m_rigid_list;
	MMDRigidRootObject() = default;
	~MMDRigidRootObject() override = default;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDRigidRootObject)
	CMT_DEFAULT_MOVE_BODY(MMDRigidRootObject)
	INSTANCEOF(MMDRigidRootObject, MMDRootObject)
public:
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	Bool Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const override;
	Bool CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) SDK2024_Const override;
	Bool Message(GeListNode* node, Int32 type, void* data) override;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
	static NodeData* Alloc();
};

#endif // !MMD_RIGID_ROOT_H__
