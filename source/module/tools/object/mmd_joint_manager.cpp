/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/09/12
File:			mmd_joint_root.h
Description:	MMD joint root object

**************************************************************************/

#include <c4d.h>
#include "plugin_resource.h"
#include "module/core/cmt_marco.h"
#include "mmd_joint.h"
#include "mmd_joint_manager.h"
#include "mmd_bone_manager.h"
#include "mmd_rigid_manager.h"
#include "mmd_model_manager.h"
#include "description/OMMDJoint.h"
#include "libMMD/Model/MMD/MMDPhysics.h"
#include "utils/string_util.hpp"

namespace
{
	Int32 NormalizeJointMode(const Int32 mode)
	{
		constexpr Int32 kLegacyJointModeVmd = 2;
		return mode == kLegacyJointModeVmd ? JOINT_MODE_ANIM : mode;
	}

	Matrix NormalizeMatrixBasis(const Matrix& matrix)
	{
		Matrix normalized = matrix;
		normalized.sqmat = normalized.sqmat.GetNormalized();
		return normalized;
	}

	ROTATIONORDER GetObjectRotationOrder(BaseObject* object)
	{
		GeData rotation_order;
		if (object && object->GetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_ROTATION_ORDER)), rotation_order, DESCFLAGS_GET::NONE))
			return static_cast<ROTATIONORDER>(rotation_order.GetInt32());
		return ROTATIONORDER::DEFAULT;
	}

	void MarkSceneNodeDirty(BaseList2D* node)
	{
		if (!node)
			return;

		node->SetDirty(DIRTYFLAGS::MATRIX | DIRTYFLAGS::DATA | DIRTYFLAGS::CACHE);
		node->Message(MSG_UPDATE);
	}

	void SetFloatParameter(BaseObject* object, const Int32 id, const Float value)
	{
		if (object)
			object->SetParameter(CreateDescID(DescLevel(id)), value, DESCFLAGS_SET::NONE);
	}

	void SetVectorXYZParameters(BaseObject* object, const Int32 x_id, const Int32 y_id, const Int32 z_id, const Vector& value)
	{
		SetFloatParameter(object, x_id, value.x);
		SetFloatParameter(object, y_id, value.y);
		SetFloatParameter(object, z_id, value.z);
	}

	String ReadObjectStoredString(const BaseObject* object, const Int32 id, const String& fallback)
	{
		const BaseContainer* const bc = object ? object->GetDataInstance() : nullptr;
		if (!bc)
			return fallback;

		const GeData* const data = bc->GetDataPointer(id);
		if (!data || data->GetType() != DA_STRING)
			return fallback;

		const String value = data->GetString();
		return value.IsEmpty() ? fallback : value;
	}

	Int32 ReadObjectStoredIndex(const BaseObject* object, const Int32 id, const Int32 fallback = 0)
	{
		const BaseContainer* const bc = object ? object->GetDataInstance() : nullptr;
		if (!bc)
			return fallback;

		const GeData* const data = bc->GetDataPointer(id);
		if (!data)
			return fallback;
		if (data->GetType() == DA_LONG)
			return data->GetInt32();
		if (data->GetType() != DA_STRING)
			return fallback;

		const String value = data->GetString();
		return value.IsEmpty() ? fallback : value.ToInt32(nullptr);
	}

	Matrix BuildPRSMatrix(const Vector& position, const Vector& rotation, const ROTATIONORDER order)
	{
		Matrix matrix = HPBToMatrix(rotation, order);
		matrix.off = position;
		return matrix;
	}
}

NodeData* MMDJointManagerObject::Alloc()
{
	return NewObjClear(MMDJointManagerObject);
}

Bool MMDJointManagerObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	IOReadField(joint_name_index_);
	if (!SUPER::Read(node, hf, level))
		return false;
	if (BaseContainer* const bc = node ? reinterpret_cast<BaseList2D*>(node)->GetDataInstance() : nullptr)
		bc->SetInt32(JOINT_MODE, NormalizeJointMode(bc->GetInt32(JOINT_MODE)));
	return true;
}

SDK2024_Write(MMDJointManagerObject)
{
	IOWriteField(joint_name_index_);
	return SUPER::Write(node, hf);
}

SDK2024_CopyTo(MMDJointManagerObject)
{
	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

BaseObject* MMDJointManagerObject::AddJoint(const String& name, libmmd::MMDJoint* mmd_joint, GeListNode* node)
{
	if (!node)
		node = Get();
	if (const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance())
	{
		if (BaseObject* new_joint = BaseObject::Alloc(g_mmd_joint_object_id))
		{
			if (name.IsEmpty())
				new_joint->SetName(new_joint->GetName() + "." + String::IntToString(joint_name_index_++));
			else
				new_joint->SetName(name);
			const auto new_joint_data = new_joint->GetNodeData<MMDJointObject>();
			new_joint_data->joint_manager_data_ = this;
			new_joint_data->joint_manager_link_->SetLink(reinterpret_cast<BaseObject*>(Get()));
			new_joint_data->mmd_joint_ = mmd_joint;

			new_joint->InsertUnderLast(node);
			{
				MMDJointRootObjectMsg msg(MMDJointRootObjectMsgType::JOINT_DISPLAY_CHANGE, bc->GetInt32(JOINT_DISPLAY_TYPE), 0);
				new_joint->Message(g_mmd_joint_manager_object_id, &msg);
			}
			{
				MMDJointRootObjectMsg msg(MMDJointRootObjectMsgType::JOINT_MODE_CHANGE, 0, NormalizeJointMode(bc->GetInt32(JOINT_MODE)));
				new_joint->Message(g_mmd_joint_manager_object_id, &msg);
			}
			return new_joint;
		}
	}
	return nullptr;
}

Bool MMDJointManagerObject::Message(GeListNode* node, Int32 type, void* data)
{
	switch (type)
	{
	case MSG_DESCRIPTION_COMMAND:
	{
		const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
		if (!bc)
		{
			return(true);
		}
		if (const auto description_command = static_cast<DescriptionCommand*>(data); description_command->_descId[0].id == ADD_JOINT_BUTTON)
		{
			AddJoint({}, nullptr, node);
			if (BaseObject* const parent = reinterpret_cast<BaseObject*>(node)->GetUp(); parent && parent->IsInstanceOf(g_mmd_model_manager_object_id))
			{
				if (auto* const model = parent->GetNodeData<MMDModelManagerObject>())
					model->InvalidateStandaloneRuntime();
			}
		}
		break;
	}
	case g_mmd_model_manager_object_id:
	{
		if (const auto msg = static_cast<MMDModelManagerObjectMsg*>(data); msg && msg->msg_type == MMDModelManagerObjectMsgType::MODEL_MODE_CHANGE)
		{
			SetAllJointMode(msg->model_mode, reinterpret_cast<BaseObject*>(node));
		}
		break;
	}
	default:
		break;
	}
	return SUPER::Message(node, type, data);
}

Bool MMDJointManagerObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	switch (id[0].id)
	{
	case JOINT_DISPLAY_TYPE:
	{
		MMDJointRootObjectMsg msg(MMDJointRootObjectMsgType::JOINT_DISPLAY_CHANGE, t_data.GetInt32(), 0);
		node->MultiMessage(MULTIMSG_ROUTE::DOWN, g_mmd_joint_manager_object_id, &msg);
		break;
	}
	case JOINT_MODE:
	{
		const GeData normalized_mode(NormalizeJointMode(t_data.GetInt32()));
		MMDJointRootObjectMsg msg(MMDJointRootObjectMsgType::JOINT_MODE_CHANGE, 0, normalized_mode.GetInt32());
		node->MultiMessage(MULTIMSG_ROUTE::DOWN, g_mmd_joint_manager_object_id, &msg);
		return SUPER::SetDParameter(node, id, normalized_mode, flags);
	}
	default:
		break;
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

void MMDJointManagerObject::SetAllJointMode(const Int32 mode, BaseObject* joint_manager_object)
{
	const Int32 normalized_mode = NormalizeJointMode(mode);
	if (!joint_manager_object)
		joint_manager_object = reinterpret_cast<BaseObject*>(Get());
	if (!joint_manager_object)
		return;

	joint_manager_object->SetParameter(ConstDescID(DescLevel(JOINT_MODE)), normalized_mode, DESCFLAGS_SET::NONE);
	MMDJointRootObjectMsg msg(MMDJointRootObjectMsgType::JOINT_MODE_CHANGE, 0, normalized_mode);
	joint_manager_object->MultiMessage(MULTIMSG_ROUTE::DOWN, g_mmd_joint_manager_object_id, &msg);

	for (BaseObject* child = joint_manager_object->GetDown(); child; child = child->GetNext())
	{
		if (!child->IsInstanceOf(g_mmd_joint_object_id))
			continue;
		if (auto* const joint = child->GetNodeData<MMDJointObject>())
			joint->HandleJointModeChange(normalized_mode);
		child->SetDirty(DIRTYFLAGS::DESCRIPTION | DIRTYFLAGS::DATA);
	}

	joint_manager_object->SetDirty(DIRTYFLAGS::DESCRIPTION | DIRTYFLAGS::DATA);
	SendCoreMessage(COREMSG_CINEMA, BaseContainer(COREMSG_CINEMA_FORCE_AM_UPDATE));
	if (GeIsMainThread())
		EventAdd();
}

void MMDJointManagerObject::CommitEditorTransforms(BaseObject* joint_manager_object)
{
	if (!joint_manager_object)
		return;

	for (BaseObject* child = joint_manager_object->GetDown(); child; child = child->GetNext())
	{
		if (!child->IsInstanceOf(g_mmd_joint_object_id))
			continue;

		const Matrix rel = NormalizeMatrixBasis(child->GetRelMl());
		const Vector rotation = MatrixToHPB(rel, GetObjectRotationOrder(child));
		SetVectorXYZParameters(child, JOINT_ATTITUDE_POSITION_X, JOINT_ATTITUDE_POSITION_Y, JOINT_ATTITUDE_POSITION_Z, rel.off);
		SetVectorXYZParameters(child, JOINT_ATTITUDE_ROTATION_X, JOINT_ATTITUDE_ROTATION_Y, JOINT_ATTITUDE_ROTATION_Z, rotation);
		MarkSceneNodeDirty(child);
	}
}

void MMDJointManagerObject::RestoreEditorTransforms(BaseObject* joint_manager_object)
{
	if (!joint_manager_object)
		return;

	for (BaseObject* child = joint_manager_object->GetDown(); child; child = child->GetNext())
	{
		if (!child->IsInstanceOf(g_mmd_joint_object_id))
			continue;

		const BaseContainer* const bc = child->GetDataInstance();
		if (!bc)
			continue;

		const Vector position(
			bc->GetFloat(JOINT_ATTITUDE_POSITION_X),
			bc->GetFloat(JOINT_ATTITUDE_POSITION_Y),
			bc->GetFloat(JOINT_ATTITUDE_POSITION_Z));
		const Vector rotation(
			bc->GetFloat(JOINT_ATTITUDE_ROTATION_X),
			bc->GetFloat(JOINT_ATTITUDE_ROTATION_Y),
			bc->GetFloat(JOINT_ATTITUDE_ROTATION_Z));
		child->SetRelMl(BuildPRSMatrix(position, rotation, GetObjectRotationOrder(child)));
		MarkSceneNodeDirty(child);
	}
}

MMDRigidManagerObject* MMDJointManagerObject::GetRigidManager()
{
	if (!rigid_manager_data_)
		if (auto* obj = io_util::ResolveObjectLink(rigid_manager_link_))
			rigid_manager_data_ = obj->GetNodeData<MMDRigidManagerObject>();
	if (!rigid_manager_data_)
	{
		if (auto* parent = reinterpret_cast<BaseObject*>(Get())->GetUp())
			if (parent->IsInstanceOf(g_mmd_model_manager_object_id))
				if (auto* model = parent->GetNodeData<MMDModelManagerObject>())
					if (auto* mgr = model->GetRigidManagerData())
					{
						rigid_manager_data_ = mgr;
						rigid_manager_link_->SetLink(reinterpret_cast<BaseObject*>(mgr->Get()));
					}
	}
	return rigid_manager_data_;
}

namespace
{
	template <Int32 ID>
	void SetJointParameter(BaseObject* object ,GeData data)
	{
		object->SetParameter(ConstDescID(DescLevel(ID)), data, DESCFLAGS_SET::NONE);
	}
}

Bool MMDJointManagerObject::LoadPMX(const libmmd::PMXFile& pmx_file,
                                    const CMTToolsSetting::ModelImport& setting)
{
	const auto joint_count = pmx_file.m_joints.size();
	for (size_t joint_index = 0; joint_index < joint_count; ++joint_index)
	{
		const auto& pmx_joint = pmx_file.m_joints[joint_index];
		const maxon::String name_local{ pmx_joint.m_name.c_str() };
		const auto joint_object = AddJoint(name_local, nullptr);
		if (!joint_object)
			return false;

		joint_object->SetParameter(ConstDescID(DescLevel(JOINT_INDEX)),
			String::IntToString(static_cast<Int32>(joint_index)), DESCFLAGS_SET::NONE);

		const maxon::String name_universal{ pmx_joint.m_englishName.c_str() };
		SetJointParameter<JOINT_NAME_LOCAL>(joint_object, name_local);
		SetJointParameter<JOINT_NAME_UNIVERSAL>(joint_object, name_universal);
		SetJointParameter<JOINT_NAME_IS>(joint_object, setting.import_english);

		SetJointParameter<JOINT_TYPE>(joint_object, static_cast<Int32>(pmx_joint.m_type));

		SetJointParameter<JOINT_LINK_RIGID_A_INDEX>(joint_object, pmx_joint.m_rigidbodyAIndex);
		SetJointParameter<JOINT_LINK_RIGID_B_INDEX>(joint_object, pmx_joint.m_rigidbodyBIndex);

		SetJointParameter<JOINT_ATTITUDE_POSITION_X>(joint_object, pmx_joint.m_translate.x());
		SetJointParameter<JOINT_ATTITUDE_POSITION_Y>(joint_object, pmx_joint.m_translate.y());
		SetJointParameter<JOINT_ATTITUDE_POSITION_Z>(joint_object, pmx_joint.m_translate.z());
		joint_object->SetRelPos(Vector(pmx_joint.m_translate.x(), pmx_joint.m_translate.y(), pmx_joint.m_translate.z()));

		SetJointParameter<JOINT_ATTITUDE_ROTATION_X>(joint_object, pmx_joint.m_rotate.x());
		SetJointParameter<JOINT_ATTITUDE_ROTATION_Y>(joint_object, pmx_joint.m_rotate.y());
		SetJointParameter<JOINT_ATTITUDE_ROTATION_Z>(joint_object, pmx_joint.m_rotate.z());
		joint_object->SetRelRot(Vector(pmx_joint.m_rotate.x(), pmx_joint.m_rotate.y(), pmx_joint.m_rotate.z()));

		SetJointParameter<JOINT_PARAMETER_POSITION_X_MIN>(joint_object, pmx_joint.m_translateLowerLimit.x());
		SetJointParameter<JOINT_PARAMETER_POSITION_Y_MIN>(joint_object, pmx_joint.m_translateLowerLimit.y());
		SetJointParameter<JOINT_PARAMETER_POSITION_Z_MIN>(joint_object, pmx_joint.m_translateLowerLimit.z());
		SetJointParameter<JOINT_PARAMETER_POSITION_X_MAX>(joint_object, pmx_joint.m_translateUpperLimit.x());
		SetJointParameter<JOINT_PARAMETER_POSITION_Y_MAX>(joint_object, pmx_joint.m_translateUpperLimit.y());
		SetJointParameter<JOINT_PARAMETER_POSITION_Z_MAX>(joint_object, pmx_joint.m_translateUpperLimit.z());

		SetJointParameter<JOINT_PARAMETER_ROTATION_X_MIN>(joint_object, pmx_joint.m_rotateLowerLimit.x());
		SetJointParameter<JOINT_PARAMETER_ROTATION_Y_MIN>(joint_object, pmx_joint.m_rotateLowerLimit.y());
		SetJointParameter<JOINT_PARAMETER_ROTATION_Z_MIN>(joint_object, pmx_joint.m_rotateLowerLimit.z());
		SetJointParameter<JOINT_PARAMETER_ROTATION_X_MAX>(joint_object, pmx_joint.m_rotateUpperLimit.x());
		SetJointParameter<JOINT_PARAMETER_ROTATION_Y_MAX>(joint_object, pmx_joint.m_rotateUpperLimit.y());
		SetJointParameter<JOINT_PARAMETER_ROTATION_Z_MAX>(joint_object, pmx_joint.m_rotateUpperLimit.z());

		SetJointParameter<JOINT_SPRING_POSITION_X>(joint_object, pmx_joint.m_springTranslateFactor.x());
		SetJointParameter<JOINT_SPRING_POSITION_Y>(joint_object, pmx_joint.m_springTranslateFactor.y());
		SetJointParameter<JOINT_SPRING_POSITION_Z>(joint_object, pmx_joint.m_springTranslateFactor.z());

		SetJointParameter<JOINT_SPRING_ROTATION_X>(joint_object, pmx_joint.m_springRotateFactor.x());
		SetJointParameter<JOINT_SPRING_ROTATION_Y>(joint_object, pmx_joint.m_springRotateFactor.y());
		SetJointParameter<JOINT_SPRING_ROTATION_Z>(joint_object, pmx_joint.m_springRotateFactor.z());
	}

	return true;
}

namespace
{
	template <Int32 ID>
	Float32 GetJointFloat(const BaseContainer* bc)
	{
		return static_cast<Float32>(bc->GetFloat(ID));
	}
}

namespace
{
	Int32 RemapRigidIndex(const Int32 rigid_index, const std::unordered_map<Int32, Int32>* rigid_index_remap)
	{
		if (rigid_index < 0)
			return -1;
		if (!rigid_index_remap)
			return rigid_index;
		const auto it = rigid_index_remap->find(rigid_index);
		return it != rigid_index_remap->end() ? it->second : -1;
	}
}

Bool MMDJointManagerObject::SavePMX(libmmd::PMXFile& pmx_file, const std::unordered_map<Int32, Int32>* rigid_index_remap) const
{
	const auto op = reinterpret_cast<const BaseObject*>(Get());
	BaseObject* const op_mutable = const_cast<BaseObject*>(op);
	std::vector<std::pair<Int32, const BaseObject*>> sorted_children;
	for (BaseObject* child = op_mutable ? op_mutable->GetDown() : nullptr; child; child = child->GetNext())
	{
		if (child->GetType() != g_mmd_joint_object_id)
			continue;
		const Int32 joint_index = ReadObjectStoredIndex(child, JOINT_INDEX);
		sorted_children.emplace_back(joint_index, child);
	}
	std::stable_sort(sorted_children.begin(), sorted_children.end(),
		[](const auto& a, const auto& b) { return a.first < b.first; });

	pmx_file.m_joints.clear();
	pmx_file.m_joints.reserve(sorted_children.size());

	for (const auto& [joint_index, child] : sorted_children)
	{
		(void)joint_index;
		const BaseContainer* bc = child->GetDataInstance();
		if (!bc)
			return false;

		libmmd::PMXJoint pmx_joint;
		const String name_local = ReadObjectStoredString(child, JOINT_NAME_LOCAL, child->GetName());
		const String name_universal = ReadObjectStoredString(child, JOINT_NAME_UNIVERSAL, name_local);
		pmx_joint.m_name = string_util::GetStdString(name_local);
		pmx_joint.m_englishName = string_util::GetStdString(name_universal);
		if (pmx_joint.m_englishName.empty())
			pmx_joint.m_englishName = pmx_joint.m_name;

		pmx_joint.m_type = static_cast<libmmd::PMXJoint::JointType>(bc->GetInt32(JOINT_TYPE));
		pmx_joint.m_rigidbodyAIndex = RemapRigidIndex(bc->GetInt32(JOINT_LINK_RIGID_A_INDEX), rigid_index_remap);
		pmx_joint.m_rigidbodyBIndex = RemapRigidIndex(bc->GetInt32(JOINT_LINK_RIGID_B_INDEX), rigid_index_remap);
		pmx_joint.m_translate = Eigen::Vector3f(
			GetJointFloat<JOINT_ATTITUDE_POSITION_X>(bc),
			GetJointFloat<JOINT_ATTITUDE_POSITION_Y>(bc),
			GetJointFloat<JOINT_ATTITUDE_POSITION_Z>(bc));
		pmx_joint.m_rotate = Eigen::Vector3f(
			GetJointFloat<JOINT_ATTITUDE_ROTATION_X>(bc),
			GetJointFloat<JOINT_ATTITUDE_ROTATION_Y>(bc),
			GetJointFloat<JOINT_ATTITUDE_ROTATION_Z>(bc));
		pmx_joint.m_translateLowerLimit = Eigen::Vector3f(
			GetJointFloat<JOINT_PARAMETER_POSITION_X_MIN>(bc),
			GetJointFloat<JOINT_PARAMETER_POSITION_Y_MIN>(bc),
			GetJointFloat<JOINT_PARAMETER_POSITION_Z_MIN>(bc));
		pmx_joint.m_translateUpperLimit = Eigen::Vector3f(
			GetJointFloat<JOINT_PARAMETER_POSITION_X_MAX>(bc),
			GetJointFloat<JOINT_PARAMETER_POSITION_Y_MAX>(bc),
			GetJointFloat<JOINT_PARAMETER_POSITION_Z_MAX>(bc));
		pmx_joint.m_rotateLowerLimit = Eigen::Vector3f(
			GetJointFloat<JOINT_PARAMETER_ROTATION_X_MIN>(bc),
			GetJointFloat<JOINT_PARAMETER_ROTATION_Y_MIN>(bc),
			GetJointFloat<JOINT_PARAMETER_ROTATION_Z_MIN>(bc));
		pmx_joint.m_rotateUpperLimit = Eigen::Vector3f(
			GetJointFloat<JOINT_PARAMETER_ROTATION_X_MAX>(bc),
			GetJointFloat<JOINT_PARAMETER_ROTATION_Y_MAX>(bc),
			GetJointFloat<JOINT_PARAMETER_ROTATION_Z_MAX>(bc));
		pmx_joint.m_springTranslateFactor = Eigen::Vector3f(
			GetJointFloat<JOINT_SPRING_POSITION_X>(bc),
			GetJointFloat<JOINT_SPRING_POSITION_Y>(bc),
			GetJointFloat<JOINT_SPRING_POSITION_Z>(bc));
		pmx_joint.m_springRotateFactor = Eigen::Vector3f(
			GetJointFloat<JOINT_SPRING_ROTATION_X>(bc),
			GetJointFloat<JOINT_SPRING_ROTATION_Y>(bc),
			GetJointFloat<JOINT_SPRING_ROTATION_Z>(bc));
		pmx_file.m_joints.push_back(std::move(pmx_joint));
	}
	return true;
}

MMDBoneManagerObject* MMDJointManagerObject::GetBoneManager()
{
	if (!bone_manager_data_)
		if (auto* obj = io_util::ResolveObjectLink(bone_manager_link_))
			bone_manager_data_ = obj->GetNodeData<MMDBoneManagerObject>();
	if (!bone_manager_data_)
	{
		if (auto* parent = reinterpret_cast<BaseObject*>(Get())->GetUp())
			if (parent->IsInstanceOf(g_mmd_model_manager_object_id))
				if (auto* model = parent->GetNodeData<MMDModelManagerObject>())
					if (auto* mgr = model->GetBoneManagerData())
					{
						bone_manager_data_ = mgr;
						bone_manager_link_->SetLink(reinterpret_cast<BaseObject*>(mgr->Get()));
					}
	}
	return bone_manager_data_;
}

Bool MMDJointManagerObject::BuildStandaloneJoints(libmmd::MMDPhysicsManager* physics_manager)
{
	if (!physics_manager)
		return false;

	auto* rigid_bodies = physics_manager->GetRigidBodys();
	if (!rigid_bodies)
		return false;

	const auto op = reinterpret_cast<BaseObject*>(Get());

	std::vector<std::pair<Int32, BaseObject*>> sorted_children;
	for (BaseObject* child = op->GetDown(); child; child = child->GetNext())
	{
		if (child->GetType() == g_mmd_joint_object_id)
		{
			const Int32 joint_index = ReadObjectStoredIndex(child, JOINT_INDEX);
			sorted_children.emplace_back(joint_index, child);
		}
	}
	std::stable_sort(sorted_children.begin(), sorted_children.end(),
		[](const auto& a, const auto& b) { return a.first < b.first; });

	Int32 created = 0, skipped_invalid = 0, skipped_self = 0, failed = 0;

	for (const auto& [joint_index, child] : sorted_children)
	{
		const BaseContainer* bc = child->GetDataInstance();
		if (!bc)
			return false;

		const auto rigidAIndex = bc->GetInt32(JOINT_LINK_RIGID_A_INDEX);
		const auto rigidBIndex = bc->GetInt32(JOINT_LINK_RIGID_B_INDEX);

		auto* joint_data = child->GetNodeData<MMDJointObject>();
		if (joint_data)
		{
			if (auto* rigid_mgr = GetRigidManager())
			{
				joint_data->link_rigid_a_->SetLink(rigid_mgr->FindRigid(rigidAIndex));
				joint_data->link_rigid_b_->SetLink(rigid_mgr->FindRigid(rigidBIndex));
			}
		}

		const libmmd::MMDRigidBody* rbA = nullptr;
		const libmmd::MMDRigidBody* rbB = nullptr;
		if (rigidAIndex >= 0 && static_cast<size_t>(rigidAIndex) < rigid_bodies->size())
			rbA = (*rigid_bodies)[rigidAIndex].get();
		if (rigidBIndex >= 0 && static_cast<size_t>(rigidBIndex) < rigid_bodies->size())
			rbB = (*rigid_bodies)[rigidBIndex].get();

		if (!rbA || !rbB || rbA->GetRigidBody() == nullptr || rbB->GetRigidBody() == nullptr)
		{
			physics_manager->AddJoint();
			++skipped_invalid;
			continue;
		}

		if (rigidAIndex == rigidBIndex)
		{
			physics_manager->AddJoint();
			++skipped_self;
			continue;
		}

		auto* jt = physics_manager->AddJoint();

		const Eigen::Vector3f translate(
			static_cast<float>(bc->GetFloat(JOINT_ATTITUDE_POSITION_X)),
			static_cast<float>(bc->GetFloat(JOINT_ATTITUDE_POSITION_Y)),
			static_cast<float>(bc->GetFloat(JOINT_ATTITUDE_POSITION_Z))
		);
		const Eigen::Vector3f rotate(
			static_cast<float>(bc->GetFloat(JOINT_ATTITUDE_ROTATION_X)),
			static_cast<float>(bc->GetFloat(JOINT_ATTITUDE_ROTATION_Y)),
			static_cast<float>(bc->GetFloat(JOINT_ATTITUDE_ROTATION_Z))
		);
		const Eigen::Vector3f translateLowerLimit(
			static_cast<float>(bc->GetFloat(JOINT_PARAMETER_POSITION_X_MIN)),
			static_cast<float>(bc->GetFloat(JOINT_PARAMETER_POSITION_Y_MIN)),
			static_cast<float>(bc->GetFloat(JOINT_PARAMETER_POSITION_Z_MIN))
		);
		const Eigen::Vector3f translateUpperLimit(
			static_cast<float>(bc->GetFloat(JOINT_PARAMETER_POSITION_X_MAX)),
			static_cast<float>(bc->GetFloat(JOINT_PARAMETER_POSITION_Y_MAX)),
			static_cast<float>(bc->GetFloat(JOINT_PARAMETER_POSITION_Z_MAX))
		);
		const Eigen::Vector3f rotateLowerLimit(
			static_cast<float>(bc->GetFloat(JOINT_PARAMETER_ROTATION_X_MIN)),
			static_cast<float>(bc->GetFloat(JOINT_PARAMETER_ROTATION_Y_MIN)),
			static_cast<float>(bc->GetFloat(JOINT_PARAMETER_ROTATION_Z_MIN))
		);
		const Eigen::Vector3f rotateUpperLimit(
			static_cast<float>(bc->GetFloat(JOINT_PARAMETER_ROTATION_X_MAX)),
			static_cast<float>(bc->GetFloat(JOINT_PARAMETER_ROTATION_Y_MAX)),
			static_cast<float>(bc->GetFloat(JOINT_PARAMETER_ROTATION_Z_MAX))
		);
		const Eigen::Vector3f springTranslate(
			static_cast<float>(bc->GetFloat(JOINT_SPRING_POSITION_X)),
			static_cast<float>(bc->GetFloat(JOINT_SPRING_POSITION_Y)),
			static_cast<float>(bc->GetFloat(JOINT_SPRING_POSITION_Z))
		);
		const Eigen::Vector3f springRotate(
			static_cast<float>(bc->GetFloat(JOINT_SPRING_ROTATION_X)),
			static_cast<float>(bc->GetFloat(JOINT_SPRING_ROTATION_Y)),
			static_cast<float>(bc->GetFloat(JOINT_SPRING_ROTATION_Z))
		);

		if (!jt->CreateJoint(translate, rotate,
			translateLowerLimit, translateUpperLimit,
			rotateLowerLimit, rotateUpperLimit,
			springTranslate, springRotate,
			rbA, rbB))
		{
			++failed;
			DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] BuildStandaloneJoints[@]: CreateJoint FAILED, name='@' rbA=@ rbB=@",
				joint_index, child->GetName(), rigidAIndex, rigidBIndex);
		}
		else
		{
			++created;
		}
	}

	if (failed != 0)
		DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT] BuildStandaloneJoints: total=@ created=@ skipped_invalid=@ skipped_self=@ failed=@",
			sorted_children.size(), created, skipped_invalid, skipped_self, failed);
	return failed == 0;
}

void MMDJointManagerObject::ReconnectJointPointers(libmmd::MMDPhysicsManager* physics_manager)
{
	if (!physics_manager)
		return;

	auto* joints = physics_manager->GetJoints();
	if (!joints)
		return;

	const auto op = reinterpret_cast<BaseObject*>(Get());

	std::vector<std::pair<Int32, BaseObject*>> sorted_children;
	for (BaseObject* child = op->GetDown(); child; child = child->GetNext())
	{
		if (child->GetType() == g_mmd_joint_object_id)
		{
			const Int32 joint_index = ReadObjectStoredIndex(child, JOINT_INDEX);
			sorted_children.emplace_back(joint_index, child);
		}
	}
	std::stable_sort(sorted_children.begin(), sorted_children.end(),
		[](const auto& a, const auto& b) { return a.first < b.first; });

	MMDRigidManagerObject* const rigid_mgr = GetRigidManager();
	for (size_t i = 0; i < sorted_children.size() && i < joints->size(); ++i)
	{
		BaseObject* const joint_object = sorted_children[i].second;
		auto* joint_data = joint_object ? joint_object->GetNodeData<MMDJointObject>() : nullptr;
		if (!joint_data)
			continue;
		joint_data->mmd_joint_ = (*joints)[i].get();
		joint_data->joint_manager_data_ = this;
		joint_data->joint_manager_link_->SetLink(reinterpret_cast<BaseObject*>(Get()));
		const BaseContainer* const bc = joint_object->GetDataInstance();
		const Int32 rigid_a_index = bc ? bc->GetInt32(JOINT_LINK_RIGID_A_INDEX) : -1;
		const Int32 rigid_b_index = bc ? bc->GetInt32(JOINT_LINK_RIGID_B_INDEX) : -1;
		BaseObject* const rigid_a = rigid_mgr ? rigid_mgr->FindRigid(rigid_a_index) : nullptr;
		BaseObject* const rigid_b = rigid_mgr ? rigid_mgr->FindRigid(rigid_b_index) : nullptr;
		joint_data->link_rigid_a_->SetLink(rigid_a);
		joint_data->link_rigid_b_->SetLink(rigid_b);
	}
}
