/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Luc
Date:			2024/2/5
File:			mmd_rigid.cpp
Description:	C4D MMD rigid object

**************************************************************************/

#include <c4d.h>
#include <c4d_symbols.h>
#include "plugin_resource.h"
#include "module/core/cmt_marco.h"
#include "mmd_rigid.h"
#include "mmd_rigid_manager.h"
#include "mmd_bone_manager.h"
#include "mmd_model_manager.h"
#include "module/tools/tag/mmd_bone.h"
#include "customgui_priority.h"
#if CMT_SDK_HAS_CUSTOMGUI_ICONCHOOSER_HEADER
#include "c4d_customgui/customgui_iconchooser.h"
#endif
#include "libMMD/Model/MMD/MMDPhysics.h"
#include <Eigen/Core>
#include <Eigen/Geometry>

namespace
{
	Int32 NormalizeRigidMode(const Int32 mode)
	{
		constexpr Int32 kLegacyRigidModeVmd = 2;
		return mode == kLegacyRigidModeVmd ? RIGID_MODE_ANIM : mode;
	}

	void MarkSceneTransformDirty(BaseObject* object)
	{
		if (!object)
			return;

		object->Touch();
		object->SetDirty(DIRTYFLAGS::MATRIX | DIRTYFLAGS::DATA);
		object->Message(MSG_UPDATE);
	}

	Matrix NormalizeMatrixBasis(const Matrix& matrix)
	{
		Matrix normalized = matrix;
		normalized.sqmat = normalized.sqmat.GetNormalized();
		return normalized;
	}

	Eigen::Matrix4f MatrixToEigen(const Matrix& matrix)
	{
		Eigen::Matrix4f eigen = Eigen::Matrix4f::Identity();
		eigen(0, 0) = static_cast<float>(matrix.sqmat.v1.x);
		eigen(1, 0) = static_cast<float>(matrix.sqmat.v1.y);
		eigen(2, 0) = static_cast<float>(matrix.sqmat.v1.z);
		eigen(0, 1) = static_cast<float>(matrix.sqmat.v2.x);
		eigen(1, 1) = static_cast<float>(matrix.sqmat.v2.y);
		eigen(2, 1) = static_cast<float>(matrix.sqmat.v2.z);
		eigen(0, 2) = static_cast<float>(matrix.sqmat.v3.x);
		eigen(1, 2) = static_cast<float>(matrix.sqmat.v3.y);
		eigen(2, 2) = static_cast<float>(matrix.sqmat.v3.z);
		eigen(0, 3) = static_cast<float>(matrix.off.x);
		eigen(1, 3) = static_cast<float>(matrix.off.y);
		eigen(2, 3) = static_cast<float>(matrix.off.z);
		return eigen;
	}

	Matrix EigenToMatrix(const Eigen::Matrix4f& matrix)
	{
		return Matrix{
			Vector(matrix(0, 3), matrix(1, 3), matrix(2, 3)),
			Vector(matrix(0, 0), matrix(1, 0), matrix(2, 0)),
			Vector(matrix(0, 1), matrix(1, 1), matrix(2, 1)),
			Vector(matrix(0, 2), matrix(1, 2), matrix(2, 2))
		};
	}

	Eigen::Matrix4f BuildBoneRawGlobalMatrix(BaseObject* bone_object, const Bool frozen)
	{
		if (!bone_object)
			return Eigen::Matrix4f::Identity();

		Eigen::Matrix4f global = Eigen::Matrix4f::Identity();
		std::vector<BaseObject*> chain;
		for (BaseObject* current = bone_object; current != nullptr; current = current->GetUp())
		{
			if (!current->GetTag(g_mmd_bone_tag_id))
				break;
			chain.push_back(current);
		}

		for (auto it = chain.rbegin(); it != chain.rend(); ++it)
		{
			const Matrix local = NormalizeMatrixBasis(frozen ? (*it)->GetFrozenMln() : (*it)->GetMl());
			global = global * MatrixToEigen(local);
		}
		return global;
	}

	Eigen::Matrix4f BuildRigidBindMatrix(const BaseContainer* bc)
	{
		if (!bc)
			return Eigen::Matrix4f::Identity();

		Eigen::Matrix4f rx = Eigen::Matrix4f::Identity();
		rx.block<3, 3>(0, 0) = Eigen::AngleAxisf(static_cast<float>(bc->GetFloat(RIGID_SHAPE_ROTATION_X)), Eigen::Vector3f::UnitX()).toRotationMatrix();
		Eigen::Matrix4f ry = Eigen::Matrix4f::Identity();
		ry.block<3, 3>(0, 0) = Eigen::AngleAxisf(static_cast<float>(bc->GetFloat(RIGID_SHAPE_ROTATION_Y)), Eigen::Vector3f::UnitY()).toRotationMatrix();
		Eigen::Matrix4f rz = Eigen::Matrix4f::Identity();
		rz.block<3, 3>(0, 0) = Eigen::AngleAxisf(static_cast<float>(bc->GetFloat(RIGID_SHAPE_ROTATION_Z)), Eigen::Vector3f::UnitZ()).toRotationMatrix();

		Eigen::Matrix4f translate = Eigen::Matrix4f::Identity();
		translate(0, 3) = static_cast<float>(bc->GetFloat(RIGID_SHAPE_POSITION_X));
		translate(1, 3) = static_cast<float>(bc->GetFloat(RIGID_SHAPE_POSITION_Y));
		translate(2, 3) = static_cast<float>(bc->GetFloat(RIGID_SHAPE_POSITION_Z));
		return translate * (ry * rx * rz);
	}

	Bool BuildTrackBoneRigidLocalMatrix(MMDRigidManagerObject* rigid_manager, const BaseContainer* bc, Matrix& out_matrix)
	{
		if (!rigid_manager || !bc)
			return false;

		const Int32 bone_index = bc->GetInt32(RIGID_RELATED_BONE_INDEX);
		if (bone_index < 0)
			return false;

		MMDBoneManagerObject* const bone_manager = rigid_manager->GetBoneManagerData();
		BaseTag* const bone_tag = bone_manager ? bone_manager->FindBone(bone_index) : nullptr;
		BaseObject* const bone_object = bone_tag ? bone_tag->GetObject() : nullptr;
		if (!bone_object)
			return false;

		const Eigen::Matrix4f current_global = BuildBoneRawGlobalMatrix(bone_object, false);
		const Eigen::Matrix4f initial_global = BuildBoneRawGlobalMatrix(bone_object, true);
		const Eigen::Matrix4f rigid_bind = BuildRigidBindMatrix(bc);
		out_matrix = EigenToMatrix(current_global * initial_global.inverse() * rigid_bind);
		return true;
	}

	void ConfigureRigidExecutionPriority(GeListNode* node)
	{
		if (!node)
			return;

		BaseContainer* const bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
		if (!bc)
			return;

		if (GeData priority; node->GetParameter(ConstDescID(DescLevel(EXPRESSION_PRIORITY)), priority, DESCFLAGS_GET::NONE))
		{
			if (auto* pd = GetCustomDataTypeWritable<PriorityData>(priority, CUSTOMGUI_PRIORITY_DATA))
			{
				pd->SetPriorityValue(PRIORITYVALUE_MODE, CYCLE_EXPRESSION);
				pd->SetPriorityValue(PRIORITYVALUE_PRIORITY, 5200);
				bc->SetData(EXPRESSION_PRIORITY, priority);
			}
		}
	}
}

MMDRigidManagerObject* MMDRigidObject::GetRigidManager() const
{
	if (!rigid_manager_data_)
	{
		if (auto* obj = io_util::ResolveObjectLink(rigid_manager_link_))
			rigid_manager_data_ = obj->GetNodeData<MMDRigidManagerObject>();
	}
	return rigid_manager_data_;
}

SDK2024_ConstExpr Vector g_pmx_rigid_colors[16] =
{
		Vector(255, 212, 127) / 255,
		Vector(212, 255, 127) / 255,
		Vector(127, 255, 127) / 255,
		Vector(127, 212, 255) / 255,
		Vector(127, 212, 255) / 255,
		Vector(127, 127, 255) / 255,
		Vector(212, 127, 255) / 255,
		Vector(255, 84,  0) / 255,
		Vector(255, 255, 0) / 255,
		Vector(0,   255, 85) / 255,
		Vector(0,   255, 255) / 255,
		Vector(0,   85,  255) / 255,
		Vector(84,  0,   255) / 255,
		Vector(255, 0,   255) / 255,
		Vector(255, 0,   84) / 255,
		Vector(127, 127, 0) / 255
};

SDK2024_ConstExpr Vector g_pmx_rigid_wire_colors[3] =
{
	Vector(200, 255, 150) / 255,
	Vector(255, 200, 150) / 255,
	Vector(255, 255, 150) / 255,
};

MMDRigidObject::MMDRigidObject() : draw_color_(MakeObjectColorProperties(g_pmx_rigid_colors[0], ID_BASEOBJECT_USECOLOR_ALWAYS, true))
{}

SDK2024_Init(MMDRigidObject)
{
	if (!node)
	{
		return false;
	}

	BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
	{
		return false;
	}

	node->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);

	bc->SetInt32(RIGID_RELATED_BONE_INDEX, -1);
	bc->SetFloat(RIGID_SHAPE_SIZE_X, 2.);
	bc->SetFloat(RIGID_SHAPE_SIZE_Y, 2.);
	bc->SetFloat(RIGID_SHAPE_SIZE_Z, 2.);
	bc->SetFloat(RIGID_MASS, 1.);
	bc->SetFloat(RIGID_FRICTION_FORCE, 0.5);
	bc->SetFloat(RIGID_MOVE_ATTENUATION, 0.5);
	bc->SetFloat(RIGID_ROTATION_DAMPING, 0.5);

#if CMT_SDK_HAS_ICON_COLORIZE
	bc->SetInt32(ID_BASELIST_ICON_COLORIZE_MODE, ID_BASELIST_ICON_COLORIZE_MODE_CUSTOM);
#endif
	ConfigureRigidExecutionPriority(node);
	return true;
}

SDK2024_GetDDescription(MMDRigidObject)
{
	if (!(node && description))
	{
		return false;
	}

	if (!description->LoadDescription(node->GetType()))
	{
		return false;
	}

	BaseContainer* settings;
	if (const BaseContainer* data_container = reinterpret_cast<SDK2024_Const BaseList2D*>(node)->GetDataInstance(); data_container)
	{
		switch (m_rigid_shape_type)
		{
		case SPHERICAL:

			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_X)), nullptr);
			if (settings != nullptr)
			{
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_R));
			}

			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Y)), nullptr);
			if (settings != nullptr)
			{
				settings->SetBool(DESC_HIDE, true);
			}

			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Z)), nullptr);
			if (settings != nullptr)
			{
				settings->SetBool(DESC_HIDE, true);
			}
			break;

		case BOX:

			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_X)), nullptr);
			if (settings != nullptr)
			{
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_L));
			}

			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Y)), nullptr);
			if (settings != nullptr)
			{
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_H));
			}

			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Z)), nullptr);
			if (settings != nullptr)
			{
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_W));
			}
			break;

		case CAPLETS:
			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_X)), nullptr);
			if (settings != nullptr)
			{
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_R));
			}

			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Y)), nullptr);
			if (settings != nullptr)
			{
				settings->SetString(DESC_SHORT_NAME, GeLoadString(IDS_RIGID_SHAPE_SIZE_H));
			}

			settings = description->GetParameterI(ConstDescID(DescLevel(RIGID_SHAPE_SIZE_Z)), nullptr);
			if (settings != nullptr)
			{
				settings->SetBool(DESC_HIDE, true);
			}
			break;

		default:
			break;
		}
	}

	const DescID* const single_id = description->GetSingleDescID();
	if (const auto cid = ConstDescID(DescLevel(RIGID_RELATED_BONE_INDEX)); single_id == nullptr || cid.IsPartOf(*single_id, nullptr))
    {
		settings = description->GetParameterI(cid, nullptr);
		if (settings)
		if (auto* mgr = GetRigidManager())
		{
			settings->SetContainer(DESC_CYCLE, mgr->GetBoneItems());
		}
    }

	flags |= DESCFLAGS_DESC::LOADED;
	return SUPER::GetDDescription(node, description, flags);
}

struct BoxType
{
	constexpr static Int32 type =  Ocube;

	static void InitParameter(const BaseContainer* bc, BaseObject* object)
	{
		object->SetParameter(ConstDescID(DescLevel(PRIM_CUBE_LEN)), Vector(bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Z) * 2, bc->GetFloat(RIGID_SHAPE_SIZE_Y) * 2), DESCFLAGS_SET::NONE);
	}
};

struct SphericalType
{
	constexpr static Int32 type = Osphere;

	static void InitParameter(const BaseContainer* bc, BaseObject* object)
	{
		object->SetParameter(ConstDescID(DescLevel(PRIM_SPHERE_RAD)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
	}
};

struct CaplsuleType
{
	constexpr static Int32 type =  Ocapsule;

	static void InitParameter(const BaseContainer* bc, BaseObject* object)
	{
		object->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_RADIUS)), bc->GetData(RIGID_SHAPE_SIZE_X), DESCFLAGS_SET::NONE);
		object->SetParameter(ConstDescID(DescLevel(PRIM_CAPSULE_HEIGHT)), bc->GetFloat(RIGID_SHAPE_SIZE_Y) + bc->GetFloat(RIGID_SHAPE_SIZE_X) * 2, DESCFLAGS_SET::NONE);
	}
};

template <typename Type>
void MMDRigidObject::ResetRigidType(const BaseContainer* bc)
{
	ModelingCommandData cd;
	cd.doc = GetActiveDocument();
	const AutoFree draw_parameter_object(BaseObject::Alloc(Type::type));
	Type::InitParameter(bc, draw_parameter_object);
	cd.op = draw_parameter_object;
	SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
	draw_mesh_object_.Free();
	draw_mesh_object_.Assign(reinterpret_cast<BaseObject*>(cd.result->GetIndex(0)));
	draw_mesh_object_->SetPhong(true, true, 0.7853982);
}

template <typename Type>
void MMDRigidObject::SetRigidSize(const BaseContainer* bc)
{
	ModelingCommandData cd;
	cd.doc = GetActiveDocument();
	const AutoFree draw_parameter_object(BaseObject::Alloc(Type::type));
	Type::InitParameter(bc, draw_parameter_object);
	cd.op = draw_parameter_object;
	SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, cd);
	draw_mesh_object_.Free();
	draw_mesh_object_.Assign(reinterpret_cast<BaseObject*>(cd.result->GetIndex(0)));
	draw_mesh_object_->SetPhong(true, true, 0.7853982);
}

Bool MMDRigidObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	if (!SUPER::SetDParameter(node, id, t_data, flags))
		return false;

	BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if(!bc)
		return true;
	switch (id[0].id)
	{
	case RIGID_SHAPE_TYPE:
		UpdateRigidShape(bc, t_data.GetInt32());
		break;
	case RIGID_SHAPE_SIZE_X:
	case RIGID_SHAPE_SIZE_Y:
	case RIGID_SHAPE_SIZE_Z:
		UpdateRigidSize(bc);
		break;
	case RIGID_PHYSICS_MODE:
		UpdateRigidPhysics(t_data.GetInt32());
		break;
	case RIGID_GROUP_ID:
		UpdateRigidGroup(t_data.GetInt32());
		break;
	default:
		break;
	}
	return true;
}

SDK2024_GetDEnabling(MMDRigidObject)
{
	if (m_rigid_mode != RIGID_MODE_EDIT || id[0].id == ID_BASEOBJECT_REL_SCALE || id[0].id == ID_BASEOBJECT_FROZEN_SCALE)
		return false;

	return SUPER::GetDEnabling(node, id, t_data, flags, itemdesc);
}

void MMDRigidObject::UpdateRigidShape(const BaseContainer* bc, const Int32 rigid_shape_type)
{
	m_rigid_shape_type = rigid_shape_type;
	switch (m_rigid_shape_type)
	{
	case SPHERICAL:
		ResetRigidType<SphericalType>(bc);
		break;
	case BOX:
		ResetRigidType<BoxType>(bc);
		break;
	case CAPLETS:
		ResetRigidType<CaplsuleType>(bc);
		break;
	default:
		break;
	}
}

void MMDRigidObject::UpdateRigidSize(const BaseContainer* bc)
{
	switch (m_rigid_shape_type)
	{
	case SPHERICAL:
		SetRigidSize<SphericalType>(bc);
		break;
	case BOX:
		SetRigidSize<BoxType>(bc);
		break;
	case CAPLETS:
		SetRigidSize<CaplsuleType>(bc);
		break;
	default:
		break;
	}
}

void MMDRigidObject::UpdateRigidPhysics(Int32 physics_mode)
{
	m_physics_mode = physics_mode;
	if (m_display_type == RIGID_DISPLAY_TYPE_WIRE)
	{
		draw_color_.color = g_pmx_rigid_wire_colors[m_physics_mode];
	}
}

void MMDRigidObject::UpdateRigidGroup(const Int32 rigid_group)
{
	m_rigid_group_id = rigid_group;
	if (m_display_type != RIGID_DISPLAY_TYPE_WIRE)
	{
		draw_color_.color = g_pmx_rigid_colors[m_rigid_group_id];
	}
}

Bool MMDRigidObject::Message(GeListNode* node, Int32 type, void* data)
{
	switch (type)
	{
#if CMT_SDK_HAS_CUSTOMGUI_ICONCHOOSER_HEADER
	case MSG_GETCUSTOMICON:
	{
		const auto cid = static_cast<GetCustomIconData*>(data);
		if (!cid)
		{
			break;
		}

		CustomIconSettings settings;
		FillCustomIconSettingsFromBaseList2D(settings, reinterpret_cast<BaseObject*>(node)->GetDataInstanceRef(), node->GetType(), true);
		settings._colorMode = 1;
		settings._customColor = maxon::Color(g_pmx_rigid_colors[m_rigid_group_id]);

		CustomIconGetIdDelegate get_id_callback = [this]()->Int32
			{
				static Int32 rigid_shape_type_to_object_type[3] = {Osphere, Ocube, Ocapsule};
				return rigid_shape_type_to_object_type[m_rigid_shape_type];
			};
		GetCustomIcon(*cid, settings, false, &get_id_callback);
		break;
	}
#endif
	case MSG_DESCRIPTION_CHECKUPDATE:
	{
		const Int32	id = static_cast<DescriptionCheckUpdate*>(data)->descid->operator[](0).id;
		const BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
		if(!bc)
			return false;
		switch (id)
		{
			case RIGID_SHAPE_TYPE:
				UpdateRigidShape(bc, bc->GetInt32(RIGID_SHAPE_TYPE));
				break;
			case RIGID_SHAPE_SIZE_X: [[fallthrough]];
			case RIGID_SHAPE_SIZE_Y: [[fallthrough]];
			case RIGID_SHAPE_SIZE_Z:
				UpdateRigidSize(bc);
				break;
			case RIGID_PHYSICS_MODE:
				UpdateRigidPhysics(bc->GetInt32(RIGID_PHYSICS_MODE));
				break;
			case RIGID_GROUP_ID:
				UpdateRigidGroup(bc->GetInt32(RIGID_GROUP_ID));
				break;
			default:
				break;
		}
		break;
	}
	case  g_mmd_rigid_manager_object_id:
	{
		if (const auto* msg = static_cast<MMDRigidRootObjectMsg*>(data); msg)
		{
			switch (msg->type)
			{
			case MMDRigidRootObjectMsgType::RIGID_DISPLAY_CHANGE:
				m_display_type = msg->display_type;
				break;
			case MMDRigidRootObjectMsgType::RIGID_MODE_CHANGE:
				HandleRigidModeChange(msg->rigid_mode);
				break;
			case MMDRigidRootObjectMsgType::DEFAULT:
				break;
			}
		}
		break;
	}
	default:
		break;
	}
	return SUPER::Message(node, type, data);
}

DRAWRESULT MMDRigidObject::Draw(BaseObject* op, const DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh)
{
	if (drawpass == DRAWPASS::OBJECT)
	{
		if (op == nullptr || bd == nullptr || bh == nullptr)
		{
			return DRAWRESULT::FAILURE;
		}
		const BaseContainer* bc = op->GetDataInstance();
		bd->SetMatrix_Matrix(nullptr, op->GetMg());
		if (!bc)
		{
			return DRAWRESULT::FAILURE;
		}
		switch (m_display_type)
		{
		case RIGID_DISPLAY_TYPE_ON:
		{
			if (draw_mesh_object_)
			{
					if (op == GetActiveDocument()->GetActiveObject())
					{
						draw_color_.xray = false;
						draw_mesh_object_->SetColorProperties(&draw_color_);
						bd->DrawObject(bh, draw_mesh_object_, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
					}
					else
					{
						draw_color_.xray = true;
						draw_mesh_object_->SetColorProperties(&draw_color_);
						bd->DrawObject(bh, draw_mesh_object_, DRAWOBJECT::USE_OBJECT_COLOR | DRAWOBJECT::XRAY_ON, drawpass);
					}
			}
			else
			{
				UpdateRigidShape(bc, bc->GetInt32(RIGID_SHAPE_TYPE));
			}
			break;
		}
		case RIGID_DISPLAY_TYPE_WIRE:
		{
			if (draw_mesh_object_)
			{
				if (op == GetActiveDocument()->GetActiveObject())
				{
					ObjectColorProperties objColor = MakeObjectColorProperties(Vector(1, 0.21, 0.21), ID_BASEOBJECT_USECOLOR_ALWAYS, false);
					draw_mesh_object_->SetColorProperties(&objColor);
					bd->DrawObject(bh, draw_mesh_object_, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
				}
				else
				{
					draw_color_.xray = false;
					draw_mesh_object_->SetColorProperties(&draw_color_);
					bd->DrawObject(bh, draw_mesh_object_, DRAWOBJECT::USE_OBJECT_COLOR, drawpass);
				}
			}
			else
			{
				UpdateRigidShape(bc, bc->GetInt32(RIGID_SHAPE_TYPE));
			}
			break;
		}
		default:
			break;
		}
	}
	return SUPER::Draw(op, drawpass, bd, bh);
}

void MMDRigidObject::HandleRigidIndexUpdate(BaseObject* op) const
{
	if (const BaseObject* up_object = op->GetUp(); !up_object || !up_object->IsInstanceOf(g_mmd_rigid_manager_object_id))
		return;

	if (BaseObject* prev_object = op->GetPred(); !prev_object)
	{
		op->SetParameter(ConstDescID(DescLevel(RIGID_INDEX)), "0"_s, DESCFLAGS_SET::NONE);
	}
	else
	{
		while (prev_object != nullptr && !prev_object->IsInstanceOf(g_mmd_rigid_object_id))
			prev_object = prev_object->GetPred();

		GeData data;
		if (!prev_object->GetParameter(ConstDescID(DescLevel(RIGID_INDEX)), data, DESCFLAGS_GET::NONE))
			return;

		const auto rigid_index = data.GetString().ToInt32(nullptr) + 1;
		if (!op->GetParameter(ConstDescID(DescLevel(RIGID_INDEX)), data, DESCFLAGS_GET::NONE))
			return;

		if (rigid_index == data.GetString().ToInt32(nullptr))
			return;

		if (!op->SetParameter(ConstDescID(DescLevel(RIGID_INDEX)), String::IntToString(rigid_index), DESCFLAGS_SET::NONE))
			return;

		if (auto* mgr = GetRigidManager())
			mgr->UpdateRigidList();
	}
}

EXECUTIONRESULT MMDRigidObject::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority,
                                        EXECUTIONFLAGS flags)
{
	if (op == nullptr)
	{
		return EXECUTIONRESULT::OK;
	}

	if (m_rigid_mode == RIGID_MODE_EDIT)
	{
		HandleRigidIndexUpdate(op);
	}
	else if (mmd_rigidbody_)
	{
		if (m_display_type != RIGID_DISPLAY_TYPE_OFF)
		{
			const BaseContainer* const bc = op->GetDataInstance();
			Matrix local_matrix;
			const Bool is_track_bones = bc && bc->GetInt32(RIGID_PHYSICS_MODE) == TRACK_BONES;
			if (!(is_track_bones && BuildTrackBoneRigidLocalMatrix(GetRigidManager(), bc, local_matrix)))
			{
				const auto transform = mmd_rigidbody_->GetTransform();
				local_matrix = Matrix{
					Vector(transform(0,3),transform(1,3),transform(2,3)),
					Vector(transform(0,0),transform(1,0),transform(2,0)),
					Vector(transform(0,1),transform(1,1),transform(2,1)),
					Vector(transform(0,2),transform(1,2),transform(2,2)) };
			}
			op->SetRelMl(local_matrix);
			MarkSceneTransformDirty(op);
		}
	}

	return EXECUTIONRESULT::OK;
}

Bool MMDRigidObject::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list == nullptr || op == nullptr)
	{
		return true;
	}
	list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::EXPRESSION);
	return true;
}

Bool MMDRigidObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	BaseContainer* bc = reinterpret_cast<BaseList2D*>(node)->GetDataInstance();
	if (!bc)
	{
		return false;
	}

	IOReadField(m_display_type);
	IOReadField(m_rigid_mode);
	IOReadField(m_physics_mode);
	IOReadField(m_rigid_shape_type);
	IOReadField(m_rigid_group_id);
	IOReadField(rigid_manager_link_);
	m_rigid_mode = NormalizeRigidMode(m_rigid_mode);
	bc->SetInt32(RIGID_MODE, NormalizeRigidMode(bc->GetInt32(RIGID_MODE)));

	UpdateRigidPhysics(m_physics_mode);
	UpdateRigidShape(bc, m_rigid_shape_type);
	UpdateRigidGroup(m_rigid_group_id);
	ConfigureRigidExecutionPriority(node);
	return true;
}

SDK2024_Write(MMDRigidObject)
{
	IOWriteField(m_display_type);
	IOWriteField(m_rigid_mode);
	IOWriteField(m_physics_mode);
	IOWriteField(m_rigid_shape_type);
	IOWriteField(m_rigid_group_id);
	IOWriteField(rigid_manager_link_);

	return true;
}

SDK2024_CopyTo(MMDRigidObject)
{
	auto* const destObject = reinterpret_cast<MMDRigidObject*>(dest);
	if (destObject == nullptr)
	{
		return false;
	}

	destObject->m_rigid_mode = m_rigid_mode;
	destObject->m_display_type = m_display_type;
	destObject->m_physics_mode = m_physics_mode;
	destObject->m_rigid_shape_type = m_rigid_shape_type;
	destObject->m_rigid_group_id = m_rigid_group_id;
	if (rigid_manager_link_)
		rigid_manager_link_->CopyTo(destObject->rigid_manager_link_, flags, trn);

	return true;
}

NodeData* MMDRigidObject::Alloc()
{
	return NewObjClear(MMDRigidObject);
}

void MMDRigidObject::HandleRigidModeChange(Int32 mode)
{
	mode = NormalizeRigidMode(mode);
	if (m_rigid_mode == mode)
		return;

	if (mode == RIGID_MODE_EDIT)
	{
		Get()->ChangeNBit(NBIT::NO_DD, NBITCONTROL::CLEAR);

	}
	else
	{
		// TODO: Save to mmd_rigid_body
		Get()->ChangeNBit(NBIT::NO_DD, NBITCONTROL::SET);

	}

	m_rigid_mode = mode;
}
