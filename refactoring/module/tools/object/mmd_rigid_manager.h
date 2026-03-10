/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/09/12
File:			mmd_rigid_root.cpp
Description:	MMD rigid root object

**************************************************************************/

#pragma once

#include <c4d.h>
#include "mmd_manager.hpp"
#include "cmt_tools_setting.h"
#include "description/OMMDRigidManager.h"
#include "module/core/cmt_marco.h"
#include "libMMD/Model/MMD/PMXModel.h"

class MMDRigidObject;
class MMDModelManagerObject;
class MMDBoneManagerObject;

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

class MMDRigidManagerObject final : public MMDManagerObject
{
	Int32 m_rigid_name_index_ = 1;
	Float32 position_multiple_ = 1.0;
	AutoAlloc<BaseLink> bone_manager_link_;
	MMDBoneManagerObject* bone_manager_data_ = nullptr;
	libmmd::MMDPhysicsManager* mmd_physics_manager_ = nullptr;
	BaseContainer rigid_items_;
	maxon::HashMap<Int32, maxon::StrongRef<AutoAlloc<BaseLink>>> rigid_list_;
	MMDRigidManagerObject() = default;
	~MMDRigidManagerObject() override = default;
	friend MMDModelManagerObject;
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MMDRigidManagerObject)
	CMT_DEFAULT_MOVE_BODY(MMDRigidManagerObject)
	INSTANCEOF(MMDRigidManagerObject, MMDManagerObject)
public:
	static NodeData* Alloc();
	Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
	SDK2024_WriteOverride;
	SDK2024_CopyToOverride;
	Bool Message(GeListNode* node, Int32 type, void* data) override;
	Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;

	BaseObject* AddRigid(const String& name, libmmd::MMDRigidBody* mmd_rigidbody, GeListNode* node = nullptr);
	BaseObject* FindRigid(Int32 index) const;
	Bool UpdateRigidList();

	const BaseContainer& GetRigidItems() const;
	const BaseContainer& GetBoneItems();
	MMDBoneManagerObject* GetBoneManagerData();
	const Float32& GetPositionMultiple() const { return position_multiple_; }

	Bool LoadPMX(const libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelImport& setting);

	Bool RebuildRigidBodies(libmmd::MMDModel* model);
	void ReconnectRigidBodyPointers(libmmd::MMDPhysicsManager* physics_manager);
};

