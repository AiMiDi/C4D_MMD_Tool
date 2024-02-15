/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_mesh_root.h
Description:	MMD mesh root object

**************************************************************************/

#include "pch.h"
#include "mmd_mesh_root.h"

#include "mmd_bone_root.h"
#include "mmd_model.h"
#include "tcaposemorph.h"
#include "description/OMMDMeshRoot.h"
#include "module/tools/mmd_material.h"

NodeData* MMDMeshRootObject::Alloc()
{
	return NewObjClear(MMDMeshRootObject);
}

Bool MMDMeshRootObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		return false;
	};
	{
		AutoAlloc<BaseLink> temp_link;
		if (!temp_link)
			return false;
		if (!temp_link->Read(hf))
			return false;
		m_model_root = reinterpret_cast<BaseObject*>(temp_link->ForceGetLink());
	}

	// m_tag_mode_map
	{
		Int64 tag_mode_num = 0;
		if (!hf->ReadInt64(&tag_mode_num))
			return false;
		AutoAlloc<BaseLink> temp_link;
		for (Int64 index = 0; index < tag_mode_num; index++)
		{
			if (!temp_link->Read(hf))
				return false;
			auto tag = reinterpret_cast<BaseTag*>(temp_link->ForceGetLink());
			Int32 mode = 0;
			if (!hf->ReadInt32(&mode))
				return false;
			m_tag_mode_map.Insert(tag, mode)iferr_return;
		}
	}

	// m_mesh_morph_data
	{
		Int64 mesh_morph_data_num = 0;
		if (!hf->ReadInt64(&mesh_morph_data_num))
			return false;
		for (Int64 index = 0; index < mesh_morph_data_num; index++)
		{
			String morph_name;
			if (!hf->ReadString(&morph_name))
				return false;
			Int64 morph_count = 0;
			if (!hf->ReadInt64(&morph_count))
				return false;
			maxon::BaseList<MorphUIData>* morph_ui_data_list;
			if (const auto morph_ui_data_list_ptr = m_mesh_morph_data.Find(morph_name); morph_ui_data_list_ptr)
			{
				morph_ui_data_list = &morph_ui_data_list_ptr->GetValue();
			}
			else
			{
				morph_ui_data_list = &m_mesh_morph_data.InsertEntry(std::move(morph_name)).GetValue().GetValue();
			}
			for (Int64 morph_index = 0; morph_index < morph_count; morph_index++)
			{
				MorphUIData morph_ui_data;
				if (!morph_ui_data.Read(hf))
					return false;
				morph_ui_data_list->Append(std::move(morph_ui_data))iferr_return;
			}
		}
	}
	return SUPER::Read(node, hf, level);
}

Bool MMDMeshRootObject::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const
{
	{
		AutoAlloc<BaseLink> temp_link;
		if (!temp_link)
			return false;
		temp_link->SetLink(m_model_root);
		if (!temp_link->Write(hf))
			return false;
	}
	// m_tag_mode_map
	{
		if (!hf->WriteInt64(m_tag_mode_map.GetCount()))
			return false;
		AutoAlloc<BaseLink> temp_link;
		for (const auto& entry : m_tag_mode_map)
		{
			temp_link->SetLink(entry.GetKey());
			if (!temp_link->Write(hf))
				return false;
			if (!hf->WriteInt32(entry.GetValue()))
				return false;
		}
	}
	// m_mesh_morph_data
	{
		if (!hf->WriteInt64(m_mesh_morph_data.GetCount()))
			return false;
		for (SDK2024_Const auto& entry : m_mesh_morph_data)
		{
			if (!hf->WriteString(entry.GetKey()))
				return false;
			SDK2024_Const auto& morph_ui_data_list = entry.GetValue();
			if (!hf->WriteInt64(morph_ui_data_list.GetCount()))
				return false;
			for (SDK2024_Const auto& morph_ui_data : morph_ui_data_list)
			{
				if (!morph_ui_data.Write(hf))
					return false;
			}
		}
	}
	return SUPER::Write(node, hf);
}

Bool MMDMeshRootObject::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags,
	AliasTrans* trn) SDK2024_Const
{
	iferr_scope_handler{
		return false;
	};
	auto const dest_object = reinterpret_cast<MMDMeshRootObject*>(dest);
	dest_object->m_model_root = m_model_root;
	for (const auto& entry : m_tag_mode_map)
	{
		dest_object->m_tag_mode_map.Insert(entry.GetKey(), entry.GetValue())iferr_return;
	}
	for (const auto& entry : m_mesh_morph_data)
	{
		dest_object->m_mesh_morph_data.Insert(entry.GetKey(), entry.GetValue())iferr_return;
	}
	return SUPER::CopyTo(dest, snode, dnode, flags, trn);
}

Bool MMDMeshRootObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	const auto op = reinterpret_cast<BaseObject*>(node);
	CreateDisplayTag(node);
	if (id[0].id == MESH_DISPLAY_TYPE && m_display_tag != nullptr)
	{
		const auto display_mode_DescID = ConstDescID(DescLevel(DISPLAYTAG_SDISPLAYMODE));
		switch (t_data.GetInt32())
		{
		case MESH_DISPLAY_TYPE_OFF:
		{
			op->SetEditorMode(MODE_OFF);
			op->SetRenderMode(MODE_OFF);
			break;
		}
		case MESH_DISPLAY_TYPE_ON:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			m_display_tag->SetParameter(display_mode_DescID, DISPLAYTAG_SDISPLAY_GOURAUD, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_ON_WIRE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			m_display_tag->SetParameter(display_mode_DescID, DISPLAYTAG_SDISPLAY_GOURAUD_WIRE, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_QUICK:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			m_display_tag->SetParameter(display_mode_DescID, DISPLAYTAG_SDISPLAY_QUICK, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_QUICK_WIRE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			m_display_tag->SetParameter(display_mode_DescID, DISPLAYTAG_SDISPLAY_QUICK_WIRE, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_HIDDENLINE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			m_display_tag->SetParameter(display_mode_DescID, DISPLAYTAG_SDISPLAY_HIDDENLINE, DESCFLAGS_SET::NONE);
			break;
		}
		case MESH_DISPLAY_TYPE_WIRE:
		{
			op->SetEditorMode(MODE_UNDEF);
			op->SetRenderMode(MODE_UNDEF);
			m_display_tag->SetParameter(display_mode_DescID, DISPLAYTAG_SDISPLAY_NOSHADING, DESCFLAGS_SET::NONE);
			break;
		}
		default:
			break;
		}
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

Bool MMDMeshRootObject::Message(GeListNode* node, Int32 type, void* data)
{
	if(type == ID_O_MMD_MODEL)
	{
		if (const auto msg = static_cast<MMDModelRootObjectMsg*>(data); msg->msg_type == MMDModelRootObjectMsgType::TOOL_OBJECT_UPDATE)
		{
			m_model_root = msg->object;
		}
	}
	return SUPER::Message(node, type, data);
}

EXECUTIONRESULT MMDMeshRootObject::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority,
	EXECUTIONFLAGS flags)
{
	if (!m_model_root)
	{
		if (BaseObject* up_object = op->GetUp(); up_object->IsInstanceOf(ID_O_MMD_MODEL))
		{
			m_model_root = up_object;
		}
	}
	RefreshMeshMorphData(op);
	return SUPER::Execute(op, doc, bt, priority, flags);
}

Bool MMDMeshRootObject::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list && op)
	{
		list->Add(op, EXECUTIONPRIORITY_EXPRESSION - 2, EXECUTIONFLAGS::NONE);
	}
	return SUPER::AddToExecution(op, list);
}

const maxon::HashMap<String, maxon::BaseList<MorphUIData>>& MMDMeshRootObject::GetMeshMorphData() const
{
	return m_mesh_morph_data;
}

Bool MMDMeshRootObject::SetMeshMorphStrength(const String& morph_name, Float strength)
{
	const auto morph_ptr = m_mesh_morph_data.Find(morph_name);
	if (!morph_ptr)
	{
		return false;
	}
	for (const auto& mesh_morph_ui_data : morph_ptr->GetSecond())
	{
		if (const auto mesh_morph_tag = mesh_morph_ui_data.GetMorphTag(); mesh_morph_tag)
		{
			if (!mesh_morph_tag->SetParameter(mesh_morph_ui_data.GetStrengthID(), strength, DESCFLAGS_SET::NONE))
				return false;
		}
	}
	return true;
}

struct morph_tag_info
{
	CAPoseMorphTag* morph_tag = nullptr;
	CAMorph* morph = nullptr;
	bool is_point_morph_tag_init = false;
	bool is_uv_morph_tag_init = false;

	morph_tag_info() = default;
	morph_tag_info(CAPoseMorphTag* morph_tag) : morph_tag(morph_tag){}
};

struct vertex_info
{
	Int32		vertex_index = -1;
	BaseObject* mesh_object = nullptr;
	Int			morph_tag_index = -1;
	vertex_info() = default;
	vertex_info(Int32 morph_tag_index) : morph_tag_index(morph_tag_index){}
	maxon::HashInt GetHashCode() const;
};

maxon::HashInt vertex_info::GetHashCode() const
{
	return MAXON_HASHCODE(mesh_object, vertex_index);
}

Bool MMDMeshRootObject::LoadPMX(
	const libmmd::pmx_model& pmx_model,
	const maxon::HashMap<uint64_t, BaseObject*>& bone_map,
	const CMTToolsSetting::ModelImport& setting)
{
	iferr_scope_handler{
		return false;
	};

	const auto& pmx_surface_array = pmx_model.get_pmx_surface_array();
	const auto& pmx_vertex_array = pmx_model.get_pmx_vertex_array();
	const auto& pmx_material_array = pmx_model.get_pmx_material_array();

	// create mesh
	const auto surface_count = pmx_surface_array.size();
	const auto vertex_count = pmx_vertex_array.size();
	const auto material_count = pmx_material_array.size();

	if (surface_count == 0 || vertex_count == 0 || material_count == 0)
		return true;
	
	if (!setting.import_multipart)
	{
		PolygonObject* mesh_object = PolygonObject::Alloc(static_cast<Int32>(vertex_count), static_cast<Int32>(surface_count));
		if (!mesh_object)
			return false;
		mesh_object->SetName("Mesh"_s);
		mesh_object->InsertUnder(this->Get());

		const auto mesh_object_points = ToPoint(mesh_object)->GetPointW();
		const auto mesh_object_polygons = ToPoly(mesh_object)->GetPolygonW();

		// if import_weights is true, create weight tag
		CAWeightTag* weight_tag = nullptr;

		// mmd bone index -> weight tag joint index
		maxon::HashMap<Int32, Int32> weight_tag_joint_map;
		if (setting.import_weights)
		{
			weight_tag = CAWeightTag::Alloc();
			if (!weight_tag)
			{
				return false;
			}
			mesh_object->InsertTag(weight_tag);

			// add joint to weight tag
			for (const auto& mmd_bone_index : bone_map.GetKeys())
			{
				const auto& bone_object = bone_map.Find(mmd_bone_index)->GetValue();
				const auto joint_index = weight_tag->AddJoint(bone_object);
				weight_tag_joint_map.Insert(mmd_bone_index, joint_index)iferr_return;
			}

			// add morph deformer
			BaseObject* morph_deformer_object = BaseObject::Alloc(Oskin);
			if (!morph_deformer_object)
			{ 
				return false;
			}
			morph_deformer_object->InsertUnder(mesh_object);
		}

		maxon::ParallelFor::Dynamic(decltype(vertex_count){}, vertex_count, [&pmx_vertex_array, &setting, &mesh_object_points, &weight_tag, &weight_tag_joint_map](const uint64_t vertex_index)
		{
			const auto& pmx_vertex = pmx_vertex_array[vertex_index];

			// add vertex position
			auto& mesh_object_point = mesh_object_points[vertex_index];
			const auto& pmx_vertex_position = pmx_vertex.get_position();
			mesh_object_point.x = pmx_vertex_position[0] * setting.position_multiple;
			mesh_object_point.y = pmx_vertex_position[1] * setting.position_multiple;
			mesh_object_point.z = pmx_vertex_position[2] * setting.position_multiple;

			if (setting.import_weights)
			{
				// add weight data to weight tag
				LoadPMXVertexWeight(pmx_vertex, weight_tag_joint_map, vertex_index, weight_tag);
			}
		});

		// if import_normal is true, create normal tag
		NormalHandle normal_handle{};
		if (setting.import_normal)
		{
			NormalTag* normal_tag = NormalTag::Alloc(static_cast<Int32>(surface_count));
			if (!normal_tag)
			{
				return false;
			}
			normal_handle = normal_tag->GetDataAddressW();
			mesh_object->InsertTag(normal_tag);
		}

		// if import_uv is true, create uv tag
		UVWHandle uvw_handle{};
		if (setting.import_uv)
		{
			UVWTag* uvw_tag = UVWTag::Alloc(static_cast<Int32>(surface_count));
			if (uvw_tag == nullptr)
			{
				return false;
			}
			uvw_handle = uvw_tag->GetDataAddressW();
			mesh_object->InsertTag(uvw_tag);
		}
		// vertex index -> surface index
		maxon::ParallelFor::Dynamic(decltype(surface_count){}, surface_count, [&pmx_surface_array, &pmx_vertex_array, &setting, &mesh_object_polygons, &normal_handle, &uvw_handle](const uint64_t surface_index)
		{
			iferr_scope_handler{
				return;
			};

			// add surface
			const auto& pmx_surface = pmx_surface_array[surface_index];
			const auto& pmx_surface_vertex_a = pmx_surface.get_a();
			const auto& pmx_surface_vertex_b = pmx_surface.get_b();
			const auto& pmx_surface_vertex_c = pmx_surface.get_c();

			auto& mesh_object_polygon = mesh_object_polygons[surface_index];
			mesh_object_polygon.a = static_cast<Int32>(pmx_surface_vertex_a);
			mesh_object_polygon.b = static_cast<Int32>(pmx_surface_vertex_b);
			mesh_object_polygon.c = mesh_object_polygon.d = static_cast<Int32>(pmx_surface_vertex_c);

			const auto& pmx_vertex_a = pmx_vertex_array[pmx_surface_vertex_a];
			const auto& pmx_vertex_b = pmx_vertex_array[pmx_surface_vertex_b];
			const auto& pmx_vertex_c = pmx_vertex_array[pmx_surface_vertex_c];

			// add normal
			if (setting.import_normal)
			{
				const auto& pmx_vertex_normal_a = pmx_vertex_a.get_normal();
				const auto& pmx_vertex_normal_b = pmx_vertex_b.get_normal();
				const auto& pmx_vertex_normal_c = pmx_vertex_c.get_normal();

				NormalTag::Set(normal_handle, static_cast<Int32>(surface_index), NormalStruct(
					Vector(pmx_vertex_normal_a[0], pmx_vertex_normal_a[1], pmx_vertex_normal_a[2]).GetNormalized(),
					Vector(pmx_vertex_normal_b[0], pmx_vertex_normal_b[1], pmx_vertex_normal_b[2]).GetNormalized(),
					Vector(pmx_vertex_normal_c[0], pmx_vertex_normal_c[1], pmx_vertex_normal_c[2]).GetNormalized(),
					Vector{}));
			}
			// add uv
			if (setting.import_uv)
			{
				const auto& pmx_vertex_uv_a = pmx_vertex_a.get_uv();
				const auto& pmx_vertex_uv_b = pmx_vertex_b.get_uv();
				const auto& pmx_vertex_uv_c = pmx_vertex_c.get_uv();

				UVWTag::Set(uvw_handle, static_cast<Int32>(surface_index), UVWStruct(
					Vector(pmx_vertex_uv_a[0], pmx_vertex_uv_a[1], 0.),
					Vector(pmx_vertex_uv_b[0], pmx_vertex_uv_b[1], 0.),
					Vector(pmx_vertex_uv_c[0], pmx_vertex_uv_c[1], 0.),
					Vector{}));
			}
		});

		if (setting.import_weights)
		{
			CAWeightMgr::NormalizeWeights(setting.doc);
			weight_tag->WeightDirty();
#if API_VERSION >= 21000
			weight_tag->SetBindPose(setting.doc, false);
#else		
			DescriptionCommand dc;
			dc._descId = DescID(ID_CA_WEIGHT_TAG_SET);
			weight_tag->Message(MSG_DESCRIPTION_COMMAND, &dc);
#endif

		}

		// if import_expression is true, create morph ta
		if (setting.import_expression)
		{
			// create morph tag
			CAPoseMorphTag* morph_tag = CAPoseMorphTag::Alloc();
			if (!morph_tag)
				return false;

			mesh_object->InsertTag(morph_tag);
			morph_tag->InitMorphs();
			morph_tag->ExitEdit(setting.doc, true);

			CAMorph* base_morph = morph_tag->AddMorph();
			if (!base_morph)
				return false;

			base_morph->Store(setting.doc, morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
			morph_tag->UpdateMorphs();
			morph_tag->Message(MSG_UPDATE);

			bool is_point_morph_tag_init = false;
			bool is_uv_morph_tag_init = false;
			const auto& pmx_morph_array = pmx_model.get_pmx_morph_array();
			const auto pmx_morph_num = pmx_morph_array.size();
			for (auto morph_index = decltype(pmx_morph_num){}; morph_index < pmx_morph_num; ++morph_index)
			{
				const auto& pmx_morph = pmx_morph_array[morph_index];
				switch (pmx_morph.get_morph_offset_type())
				{
				case libmmd::pmx_morph::morph_type::VERTEX:
				{
					const auto& morph_offset_array = pmx_morph.get_morph_offset_array();
					const auto morph_offset_num = morph_offset_array.size();

					if (morph_offset_num == 0)
						continue;

					if (!is_point_morph_tag_init)
					{
						morph_tag->SetParameter(ConstDescID(DescLevel(ID_CA_POSE_POINTS)), true, DESCFLAGS_SET::NONE);

						is_point_morph_tag_init = true;
					}
					CAMorph* morph = morph_tag->AddMorph();
					if (!morph)
						return false;

					// set morph name
					morph->SetName(maxon::String{ pmx_morph.get_morph_name_local().c_str() });

					morph->Store(setting.doc, morph_tag, CAMORPH_DATA_FLAGS::ASTAG);

					// set morph node to end
					CAMorphNode* morph_node = morph->GetFirst();
					while (!(morph_node->GetInfo() & CAMORPH_DATA_FLAGS::POINTS) && morph_node)
					{
						morph_node = morph_node->GetNext();
					}

					// set morph mode
					morph->SetMode(setting.doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::EXPAND, CAMORPH_MODE::REL);

					// add morph point
					for (auto offset_index = decltype(morph_offset_num){}; offset_index < morph_offset_num; ++offset_index)
					{
						const auto& pmx_bone_morph_offset = reinterpret_cast<const libmmd::pmx_vertex_morph_offset&>(morph_offset_array[offset_index]);
						const auto& pmx_bone_morph_offset_vertex_index = pmx_bone_morph_offset.get_vertex_index();
						const auto& pmx_bone_morph_offset_position = pmx_bone_morph_offset.get_offset_position();
						morph_node->SetPoint(static_cast<Int32>(pmx_bone_morph_offset_vertex_index),
							Vector(pmx_bone_morph_offset_position[0], pmx_bone_morph_offset_position[1], pmx_bone_morph_offset_position[2]) * setting.position_multiple);
					}

					morph->SetMode(setting.doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::COLLAPSE, CAMORPH_MODE::AUTO);
					morph_tag->UpdateMorphs();
					morph_tag->Message(MSG_UPDATE);
					morph->SetStrength(0);
					break;
				}
				case libmmd::pmx_morph::morph_type::UV0: [[fallthrough]];
				case libmmd::pmx_morph::morph_type::UV1: [[fallthrough]];
				case libmmd::pmx_morph::morph_type::UV2: [[fallthrough]];
				case libmmd::pmx_morph::morph_type::UV3: [[fallthrough]];
				case libmmd::pmx_morph::morph_type::UV4:
				{
					const auto& morph_offset_array = pmx_morph.get_morph_offset_array();
					const auto morph_offset_num = morph_offset_array.size();

					if (morph_offset_num == 0)
						continue;

					if (!is_uv_morph_tag_init)
					{
						morph_tag->SetParameter(ConstDescID(DescLevel(ID_CA_POSE_UV)), true, DESCFLAGS_SET::NONE);
						is_uv_morph_tag_init = true;
					}

					CAMorph* morph = morph_tag->AddMorph();
					if (!morph)
						return false;

					// set morph name
					morph->SetName(maxon::String{ pmx_morph.get_morph_name_local().c_str() });

					morph->Store(setting.doc, morph_tag, CAMORPH_DATA_FLAGS::ASTAG);

					// set morph node to end
					CAMorphNode* morph_node = morph->GetFirst();
					while (!(morph_node->GetInfo() & CAMORPH_DATA_FLAGS::POINTS) && morph_node)
					{
						morph_node = morph_node->GetNext();
					}

					morph->SetMode(setting.doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::EXPAND, CAMORPH_MODE::REL);

					// vertex_index -> uv offset
					maxon::HashMap<Int32, Vector> morph_uv_map;
					// mapping uv morph from vertex_index to surface_index
					for (auto offset_index = decltype(morph_offset_num){}; offset_index < morph_offset_num; ++offset_index)
					{
						const auto& pmx_bone_morph_offset = reinterpret_cast<const libmmd::pmx_uv_morph_offset&>(morph_offset_array[offset_index]);
						const auto& pmx_bone_morph_offset_vertex_index = pmx_bone_morph_offset.get_vertex_index();
						const auto& pmx_bone_morph_offset_uv = pmx_bone_morph_offset.get_uv_offset();

						morph_uv_map.Insert(static_cast<Int32>(pmx_bone_morph_offset_vertex_index), Vector(pmx_bone_morph_offset_uv[0], pmx_bone_morph_offset_uv[1], 0.))iferr_return;
					}

					// add morph uv
					maxon::ParallelFor::Dynamic(decltype(surface_count){}, surface_count, [&pmx_surface_array, &morph_node, &morph_uv_map](const uint64_t surface_index)
					{
						iferr_scope_handler{
							return;
						};
						const auto& pmx_surface = pmx_surface_array[surface_index];
						const auto& pmx_surface_vertex_a = pmx_surface.get_a();
						const auto& pmx_surface_vertex_b = pmx_surface.get_b();
						const auto& pmx_surface_vertex_c = pmx_surface.get_c();
						UVWStruct uvw;
						bool is_has_uv_morph = false;
						if (const auto vertex_a_ptr = morph_uv_map.Find(pmx_surface_vertex_a); vertex_a_ptr)
						{
							uvw[0] = vertex_a_ptr->GetValue();
							is_has_uv_morph = true;
						}
						else if (const auto vertex_b_ptr = morph_uv_map.Find(pmx_surface_vertex_b); vertex_b_ptr)
						{
							uvw[1] = vertex_b_ptr->GetValue();
							is_has_uv_morph = true;
						}else if (const auto vertex_c_ptr = morph_uv_map.Find(pmx_surface_vertex_c); vertex_c_ptr)
						{
							uvw[2] = vertex_c_ptr->GetValue();
							is_has_uv_morph = true;
						}
						if (is_has_uv_morph)
						{
							morph_node->SetUV(0, static_cast<Int32>(surface_index), uvw);
						}
					});

					morph->SetMode(setting.doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::COLLAPSE, CAMORPH_MODE::AUTO);
					morph_tag->UpdateMorphs();
					morph_tag->Message(MSG_UPDATE);
					morph->SetStrength(0);
					break;
				}
				case libmmd::pmx_morph::morph_type::GROUP: [[fallthrough]];
				case libmmd::pmx_morph::morph_type::BONE: [[fallthrough]];
				case libmmd::pmx_morph::morph_type::MATERIAL: [[fallthrough]];
				case libmmd::pmx_morph::morph_type::FLIP: [[fallthrough]];
				case libmmd::pmx_morph::morph_type::IMPULSE: 
					break;
				}
			}
			morph_tag->SetParameter(ConstDescID(DescLevel(ID_CA_POSE_MODE)), ID_CA_POSE_MODE_ANIMATE, DESCFLAGS_SET::NONE);
		}

		std::shared_ptr<MMDMaterialManager> material_manager;
		if (setting.import_material)
		{
			material_manager = std::make_shared<MMDMaterialManager>();
			if (!material_manager)
				return false;
			material_manager->SetTextureRelativePath(setting.fn.GetDirectory());
			if (!material_manager->LoadPMXTexture(pmx_model.get_pmx_texture_array()))
				return false;
		}

		auto surface_begin_index = decltype(surface_count){};
		for (auto material_index = decltype(material_count){}; material_index < material_count; ++material_index)
		{
			const auto& pmx_material = pmx_material_array[material_index];
			const uint64_t surface_num = pmx_material.get_surface_count();

			if (surface_num == 0)
				continue;

			maxon::String material_name(pmx_material.get_material_name_local().c_str());

			const auto polygon_selection_tag = SelectionTag::Alloc(Tpolygonselection);
			if(!polygon_selection_tag)
				return false;
			polygon_selection_tag->GetWritableBaseSelect()->SelectAll(static_cast<Int32>(surface_begin_index), static_cast<Int32>(surface_begin_index + surface_num - 1));
			polygon_selection_tag->SetName(material_name);
			mesh_object->InsertTag(polygon_selection_tag);

			if(setting.import_material)
			{
				const auto material = material_manager->LoadPMXMaterial(pmx_material, material_index, setting);
				if (!material)
					return false;
				setting.doc->InsertMaterial(material);

				const auto texture_tag = TextureTag::Alloc();
				if (!texture_tag)
					return false;
				texture_tag->SetName(material_name);
				texture_tag->SetMaterial(material);
				texture_tag->SetParameter(ConstDescID(DescLevel(TEXTURETAG_PROJECTION)), TEXTURETAG_PROJECTION_UVW, DESCFLAGS_SET::NONE);
				texture_tag->SetParameter(ConstDescID(DescLevel(TEXTURETAG_RESTRICTION)), material_name, DESCFLAGS_SET::NONE);
				mesh_object->InsertTag(texture_tag, polygon_selection_tag);
			}

			surface_begin_index += surface_num;
		}
	}
	else
	{
		auto surface_begin_index = decltype(surface_count){};
		for (auto material_index = decltype(material_count){}; material_index < material_count; ++material_index)
		{
			const auto& pmx_material = pmx_material_array[material_index];
			const uint64_t surface_num = pmx_material.get_surface_count();
			maxon::String material_name(pmx_material.get_material_name_local().c_str());

			if (surface_num == 0)
				continue;

			PolygonObject* mesh_object = PolygonObject::Alloc(static_cast<Int32>(surface_num * 3), static_cast<Int32>(surface_num));
			if (setting.import_english)
			{
				mesh_object->SetName(maxon::String(pmx_material.get_material_name_local().c_str()));
			}
			else
			{
				if (maxon::String material_name_universal(pmx_material.get_material_name_universal().c_str()); material_name_universal.IsEmpty())
				{
					mesh_object->SetName("Mesh_" + String::UIntToString(material_index));
				}
				else
				{
					mesh_object->SetName(material_name_universal);
				}
			}
			mesh_object->InsertUnder(Get());

			const auto mesh_object_points = ToPoint(mesh_object)->GetPointW();
			const auto mesh_object_polygons = ToPoly(mesh_object)->GetPolygonW();

			// if import_weights is true, create weight tag
			CAWeightTag* weight_tag = nullptr;

			// mmd bone index -> weight tag joint index
			maxon::HashMap<Int32, Int32> weight_tag_joint_map;
			if (setting.import_weights)
			{
				weight_tag = CAWeightTag::Alloc();
				if (!weight_tag)
				{
					return false;
				}
				mesh_object->InsertTag(weight_tag);

				// add joint to weight tag
				for (const auto& mmd_bone_index : bone_map.GetKeys())
				{
					const auto& bone_object = bone_map.Find(mmd_bone_index)->GetValue();
					const auto joint_index = weight_tag->AddJoint(bone_object);
					weight_tag_joint_map.Insert(mmd_bone_index, joint_index)iferr_return;
				}

				// add morph deformer
				BaseObject* morph_deformer_object = BaseObject::Alloc(Oskin);
				if (!morph_deformer_object)
				{
					return false;
				}
				morph_deformer_object->InsertUnder(mesh_object);
			}

			const auto surface_begin_index3 = surface_begin_index * 3;
			maxon::ParallelFor::Dynamic(surface_begin_index3, (surface_begin_index + surface_num) * 3, [&pmx_vertex_array, &setting, &mesh_object_points, &weight_tag, &weight_tag_joint_map, &surface_begin_index3](const uint64_t vertex_index)
			{
				const auto& pmx_vertex = pmx_vertex_array[vertex_index];
				const auto object_vertex_index = vertex_index - surface_begin_index3;
				// add vertex position
				auto& mesh_object_point = mesh_object_points[object_vertex_index];
				const auto& pmx_vertex_position = pmx_vertex.get_position();
				mesh_object_point.x = pmx_vertex_position[0] * setting.position_multiple;
				mesh_object_point.y = pmx_vertex_position[1] * setting.position_multiple;
				mesh_object_point.z = pmx_vertex_position[2] * setting.position_multiple;

				if (setting.import_weights)
				{
					// add weight data to weight tag
					LoadPMXVertexWeight(pmx_vertex, weight_tag_joint_map, object_vertex_index, weight_tag);
				}
			});

			// if import_normal is true, create normal tag
			NormalHandle normal_handle{};
			if (setting.import_normal)
			{
				NormalTag* normal_tag = NormalTag::Alloc(static_cast<Int32>(surface_num));
				if (!normal_tag)
				{
					return false;
				}
				normal_handle = normal_tag->GetDataAddressW();
				mesh_object->InsertTag(normal_tag);
			}

			// if import_uv is true, create uv tag
			UVWHandle uvw_handle{};
			if (setting.import_uv)
			{
				UVWTag* uvw_tag = UVWTag::Alloc(static_cast<Int32>(surface_num));
				if (uvw_tag == nullptr)
				{
					return false;
				}
				uvw_handle = uvw_tag->GetDataAddressW();
				mesh_object->InsertTag(uvw_tag);
			}
			maxon::Synchronized<maxon::HashMap<uint64_t, vertex_info>> vertex_info_map;
			maxon::BaseArray<morph_tag_info> morph_tag_infos;
			if(setting.import_expression)
			{
				/* Initialization morph tag. */
				CAPoseMorphTag* morph_tag = CAPoseMorphTag::Alloc();
				morph_tag->SetName("morph_"_s + material_name);
				if(!morph_tag)
					return false;
				mesh_object->InsertTag(morph_tag);
				BaseObject* morph_deformer_object = BaseObject::Alloc(Oskin);
				morph_deformer_object->InsertUnder(mesh_object);
				morph_tag_infos.Append(morph_tag_info{ morph_tag })iferr_return;
				*vertex_info_map.Write() = maxon::HashMap<uint64_t, vertex_info>();

			}
			// vertex index -> surface index
			maxon::ParallelFor::Dynamic(surface_begin_index, surface_begin_index + surface_num, [&pmx_surface_array, &pmx_vertex_array, &setting, &mesh_object_polygons, &mesh_object, &normal_handle, &uvw_handle, &surface_begin_index, &surface_begin_index3, &vertex_info_map, &morph_tag_infos](const uint64_t surface_index)
			{
					iferr_scope;

					// add surface
					const auto& pmx_surface = pmx_surface_array[surface_index];
					const auto& pmx_surface_vertex_a = pmx_surface.get_a();
					const auto& pmx_surface_vertex_b = pmx_surface.get_b();
					const auto& pmx_surface_vertex_c = pmx_surface.get_c();

					const auto object_surface_index = surface_index - surface_begin_index;
					auto& mesh_object_polygon = mesh_object_polygons[object_surface_index];
					mesh_object_polygon.a = static_cast<Int32>(pmx_surface_vertex_a - surface_begin_index3);
					mesh_object_polygon.b = static_cast<Int32>(pmx_surface_vertex_b - surface_begin_index3);
					mesh_object_polygon.c = mesh_object_polygon.d = static_cast<Int32>(pmx_surface_vertex_c - surface_begin_index3);

					if (setting.import_expression)
					{
						const auto morph_tag_index = morph_tag_infos.GetCount() - 1;
						vertex_info_map.Write([&pmx_surface_vertex_a, &mesh_object_polygon, &pmx_surface_vertex_b, &pmx_surface_vertex_c, &mesh_object, &morph_tag_index](auto& map)
						{
							iferr_scope;
							auto& vertex_info_a = map.InsertMultiEntry(pmx_surface_vertex_a).GetValue().GetValue();
							vertex_info_a.vertex_index = mesh_object_polygon.a;
							vertex_info_a.mesh_object = mesh_object;
							vertex_info_a.morph_tag_index = morph_tag_index;

							auto& vertex_info_b = map.InsertMultiEntry(pmx_surface_vertex_b).GetValue().GetValue();
							vertex_info_b.vertex_index = mesh_object_polygon.b;
							vertex_info_b.mesh_object = mesh_object;
							vertex_info_b.morph_tag_index = morph_tag_index;

							auto& vertex_info_c = map.InsertMultiEntry(pmx_surface_vertex_c).GetValue().GetValue();
							vertex_info_c.vertex_index = mesh_object_polygon.c;
							vertex_info_c.mesh_object = mesh_object;
							vertex_info_c.morph_tag_index = morph_tag_index;
							return maxon::OK;
						})iferr_return;
					}

					const auto& pmx_vertex_a = pmx_vertex_array[pmx_surface_vertex_a];
					const auto& pmx_vertex_b = pmx_vertex_array[pmx_surface_vertex_b];
					const auto& pmx_vertex_c = pmx_vertex_array[pmx_surface_vertex_c];

					// add normal
					if (setting.import_normal)
					{
						const auto& pmx_vertex_normal_a = pmx_vertex_a.get_normal();
						const auto& pmx_vertex_normal_b = pmx_vertex_b.get_normal();
						const auto& pmx_vertex_normal_c = pmx_vertex_c.get_normal();

						NormalTag::Set(normal_handle, static_cast<Int32>(object_surface_index), NormalStruct(
							Vector(pmx_vertex_normal_a[0], pmx_vertex_normal_a[1], pmx_vertex_normal_a[2]).GetNormalized(),
							Vector(pmx_vertex_normal_b[0], pmx_vertex_normal_b[1], pmx_vertex_normal_b[2]).GetNormalized(),
							Vector(pmx_vertex_normal_c[0], pmx_vertex_normal_c[1], pmx_vertex_normal_c[2]).GetNormalized(),
							Vector{}));
					}
					// add uv
					if (setting.import_uv)
					{
						const auto& pmx_vertex_uv_a = pmx_vertex_a.get_uv();
						const auto& pmx_vertex_uv_b = pmx_vertex_b.get_uv();
						const auto& pmx_vertex_uv_c = pmx_vertex_c.get_uv();

						UVWTag::Set(uvw_handle, static_cast<Int32>(object_surface_index), UVWStruct(
							Vector(pmx_vertex_uv_a[0], pmx_vertex_uv_a[1], 0.),
							Vector(pmx_vertex_uv_b[0], pmx_vertex_uv_b[1], 0.),
							Vector(pmx_vertex_uv_c[0], pmx_vertex_uv_c[1], 0.),
							Vector{}));
					}
			});

			if (setting.import_weights)
			{
				CAWeightMgr::NormalizeWeights(setting.doc);
				weight_tag->WeightDirty();
#if API_VERSION >= 21000
				weight_tag->SetBindPose(setting.doc, false);
#else		
				DescriptionCommand dc;
				dc._descId = DescID(ID_CA_WEIGHT_TAG_SET);
				weight_tag->Message(MSG_DESCRIPTION_COMMAND, &dc);
#endif

			}

			if (setting.import_expression)
			{
				// initialize morph tag
				for (const auto& [morph_tag, morph, is_point_morph_tag_init, is_uv_morph_tag_init] : morph_tag_infos)
				{
						morph_tag->InitMorphs();
						morph_tag->ExitEdit(setting.doc, true);

						CAMorph* base_morph = morph_tag->AddMorph();
						if (!base_morph)
							return false;

						base_morph->Store(setting.doc, morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
						morph_tag->UpdateMorphs();
						morph_tag->Message(MSG_UPDATE);
				}

				// add morph deformer
				const auto& pmx_morph_array = pmx_model.get_pmx_morph_array();
				const auto pmx_morph_num = pmx_morph_array.size();
				for (auto morph_index = decltype(pmx_morph_num){}; morph_index < pmx_morph_num; ++morph_index)
				{
					const auto& pmx_morph = pmx_morph_array[morph_index];
					switch (pmx_morph.get_morph_offset_type())
					{
					case libmmd::pmx_morph::morph_type::VERTEX:
					{
						const auto& morph_offset_array = pmx_morph.get_morph_offset_array();
						const auto morph_offset_num = morph_offset_array.size();

						if (morph_offset_num == 0)
							continue;

						// morph name
						maxon::String pmx_morph_name{ pmx_morph.get_morph_name_local().c_str() };

						// add morph point
						for (auto offset_index = decltype(morph_offset_num){}; offset_index < morph_offset_num; ++offset_index)
						{
							const auto& pmx_bone_morph_offset = reinterpret_cast<const libmmd::pmx_vertex_morph_offset&>(morph_offset_array[offset_index]);
							const auto& pmx_bone_morph_offset_vertex_index = pmx_bone_morph_offset.get_vertex_index();
							const auto& pmx_bone_morph_offset_position = pmx_bone_morph_offset.get_offset_position();
							const auto& [vertex_index, offset_mesh_object, morph_tag_index] = vertex_info_map.Read()->Find(pmx_bone_morph_offset_vertex_index)->GetValue();
							auto& [morph_tag, morph, is_point_morph_tag_init, is_uv_morph_tag_init] = morph_tag_infos[morph_tag_index];

							if (!is_point_morph_tag_init)
							{
								morph_tag->SetParameter(ConstDescID(DescLevel(ID_CA_POSE_POINTS)), true, DESCFLAGS_SET::NONE);
								is_point_morph_tag_init = true;
							}

							if (!morph)
							{
								morph = morph_tag->AddMorph();
								if (!morph)
									return false;

								// set morph name
								morph->SetName(maxon::String{ pmx_morph.get_morph_name_local().c_str() });

								morph->Store(setting.doc, morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
							}

							// set morph node to end
							CAMorphNode* morph_node = morph->GetFirst();
							while (!(morph_node->GetInfo() & CAMORPH_DATA_FLAGS::POINTS) && morph_node)
							{
								morph_node = morph_node->GetNext();
							}

							// set morph mode
							morph->SetMode(setting.doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::EXPAND, CAMORPH_MODE::REL);

							morph_node->SetPoint(static_cast<Int32>(vertex_index),
								Vector(pmx_bone_morph_offset_position[0], pmx_bone_morph_offset_position[1], pmx_bone_morph_offset_position[2]) * setting.position_multiple);
						}

						break;
					}
					case libmmd::pmx_morph::morph_type::UV0: [[fallthrough]];
					case libmmd::pmx_morph::morph_type::UV1: [[fallthrough]];
					case libmmd::pmx_morph::morph_type::UV2: [[fallthrough]];
					case libmmd::pmx_morph::morph_type::UV3: [[fallthrough]];
					case libmmd::pmx_morph::morph_type::UV4:
					{
						const auto& morph_offset_array = pmx_morph.get_morph_offset_array();
						const auto morph_offset_num = morph_offset_array.size();

						if (morph_offset_num == 0)
							continue;

						// vertex_index -> uv offset
						maxon::HashMap<Int32, Vector> morph_uv_map;
						// mapping uv morph from vertex_index to surface_index
						for (auto offset_index = decltype(morph_offset_num){}; offset_index < morph_offset_num; ++offset_index)
						{
							const auto& pmx_bone_morph_offset = reinterpret_cast<const libmmd::pmx_uv_morph_offset&>(morph_offset_array[offset_index]);
							const auto& pmx_bone_morph_offset_vertex_index = pmx_bone_morph_offset.get_vertex_index();
							const auto& pmx_bone_morph_offset_uv = pmx_bone_morph_offset.get_uv_offset();
							const auto& [vertex_index, offset_mesh_object, morph_tag_index] = vertex_info_map.Read()->Find(pmx_bone_morph_offset_vertex_index)->GetValue();
							auto& [morph_tag, morph, is_point_morph_tag_init, is_uv_morph_tag_init] = morph_tag_infos[morph_tag_index];
							if (!is_uv_morph_tag_init)
							{
								morph_tag->SetParameter(ConstDescID(DescLevel(ID_CA_POSE_UV)), true, DESCFLAGS_SET::NONE);
								is_uv_morph_tag_init = true;
							}
							if (!morph)
							{
								morph = morph_tag->AddMorph();
								if (!morph)
									return false;

								// set morph name
								morph->SetName(maxon::String{ pmx_morph.get_morph_name_local().c_str() });

								morph->Store(setting.doc, morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
							}

							morph_uv_map.Insert(static_cast<Int32>(pmx_bone_morph_offset_vertex_index), Vector(pmx_bone_morph_offset_uv[0], pmx_bone_morph_offset_uv[1], 0.))iferr_return;
						}

						// add morph uv
						maxon::ParallelFor::Dynamic(decltype(surface_count){}, surface_count, [&pmx_surface_array, &morph_uv_map](const uint64_t surface_index)
						{
								iferr_scope_handler{
									return;
								};
								const auto& pmx_surface = pmx_surface_array[surface_index];
								const auto& pmx_surface_vertex_a = pmx_surface.get_a();
								const auto& pmx_surface_vertex_b = pmx_surface.get_b();
								const auto& pmx_surface_vertex_c = pmx_surface.get_c();
								UVWStruct uvw;
								bool is_has_uv_morph = false;
								if (const auto vertex_a_ptr = morph_uv_map.Find(pmx_surface_vertex_a); vertex_a_ptr)
								{
									uvw[0] = vertex_a_ptr->GetValue();
									is_has_uv_morph = true;
								}
								else if (const auto vertex_b_ptr = morph_uv_map.Find(pmx_surface_vertex_b); vertex_b_ptr)
								{
									uvw[1] = vertex_b_ptr->GetValue();
									is_has_uv_morph = true;
								}
								else if (const auto vertex_c_ptr = morph_uv_map.Find(pmx_surface_vertex_c); vertex_c_ptr)
								{
									uvw[2] = vertex_c_ptr->GetValue();
									is_has_uv_morph = true;
								}
								if (is_has_uv_morph)
								{
									morph_node->SetUV(0, static_cast<Int32>(surface_index), uvw);
								}
						});
						break;
					}
					case libmmd::pmx_morph::morph_type::GROUP: [[fallthrough]];
					case libmmd::pmx_morph::morph_type::BONE: [[fallthrough]];
					case libmmd::pmx_morph::morph_type::MATERIAL: [[fallthrough]];
					case libmmd::pmx_morph::morph_type::FLIP: [[fallthrough]];
					case libmmd::pmx_morph::morph_type::IMPULSE:
						break;
					}
				}
				
				for (const auto& [morph_tag, morph, is_point_morph_tag_init, is_uv_morph_tag_init] : morph_tag_infos)
				{
					morph->SetMode(setting.doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::COLLAPSE, CAMORPH_MODE::AUTO);
					morph_tag->UpdateMorphs();
					morph_tag->Message(MSG_UPDATE);
					morph->SetStrength(0);
				}
			}

			surface_begin_index += surface_num;
		}
	}
	return true;
}

void MMDMeshRootObject::RefreshMeshMorphData(BaseObject* op)
{
	iferr_scope_handler{};

	Bool need_update_morph = false;
	maxon::Queue<BaseObject*> nodes;
	maxon::HashSet<String> morph_name_list;
	nodes.Push(op)iferr_return;
	while (!nodes.IsEmpty())
	{
		BaseObject* node = *nodes.Pop();
		while (node)
		{
			if (node->IsInstanceOf(Opolygon))
			{
				if (const auto morph_tag = node->GetTag(Tposemorph); morph_tag)
				{
					SDK2024_Const auto pose_morph_tag = reinterpret_cast<CAPoseMorphTag*>(morph_tag);
					const auto morph_mode = pose_morph_tag->GetMode();
					const auto morph_count = pose_morph_tag->GetMorphCount();
					for (Int32 morph_index = 1; morph_index < morph_count; morph_index++)
					{
						morph_name_list.Insert(pose_morph_tag->GetMorph(morph_index)->GetName())iferr_return;
					}
					bool is_no_update_mode = false;
					if (const auto morph_previous_model_ptr = m_tag_mode_map.Find(pose_morph_tag); morph_previous_model_ptr != nullptr)
					{
						if (morph_mode == morph_previous_model_ptr->GetValue() || morph_mode == ID_CA_POSE_MODE_EDIT)
						{
							morph_previous_model_ptr->SetValue(morph_mode);
							is_no_update_mode = true;
						}
						morph_previous_model_ptr->SetValue(morph_mode);
					}
					else
					{
						m_tag_mode_map.Insert(morph_tag, morph_mode)iferr_return;
					}
					if(!is_no_update_mode)
					{
						for (Int32 index = 1; index < morph_count; index++)
						{
							auto* morph = pose_morph_tag->GetMorph(index);
							String morph_name = morph->GetName();
							DescID morph_id = pose_morph_tag->GetMorphID(index);
							maxon::BaseList<MorphUIData>* mesh_morph_list;
							if (const auto mesh_morph_map_ptr = m_mesh_morph_data.Find(morph_name); mesh_morph_map_ptr)
							{
								mesh_morph_list = &mesh_morph_map_ptr->GetValue();
								bool is_find = false;
								for (auto& morph_data : *mesh_morph_list)
								{
									if (morph_data.GetMorphTag() == pose_morph_tag && morph_data.GetStrengthID() == morph_id)
										is_find = true;
								}
								if (is_find)
									continue;
							}
							else {
								mesh_morph_list = &m_mesh_morph_data.InsertEntry(morph_name).GetValue().GetValue();
							}
							mesh_morph_list->SDK2024_Append(pose_morph_tag, morph_id)iferr_return;
							need_update_morph = true;
						}
					}
				}
			}
			nodes.Push(node->GetDown()) iferr_return;
			if (node != op)
			{
				node = node->GetNext();
			}
			else {
				break;
			}
		}
	}
	// Remove deleted mesh morph
	if (m_mesh_morph_data.GetCount() > morph_name_list.GetCount())
	{
		for (auto it = maxon::Iterable::EraseIterator(m_mesh_morph_data); it; ++it)
		{
			if (!morph_name_list.Find(it->GetKey()))
			{
				it.Erase();
				need_update_morph = true;
			}
		}
	}
	if (need_update_morph == true) {
		if (m_model_root != nullptr) {
			MMDMeshRootObjectMsg msg{ MMDMeshRootObjectMsgType::MESH_MORPH_CHANGE };
			m_model_root->Message(ID_O_MMD_MESH_ROOT, &msg);
		}
	}
}

void MMDMeshRootObject::LoadPMXVertexWeight(const libmmd::pmx_vertex& pmx_vertex,
                                            maxon::HashMap<Int32, Int32>& weight_tag_joint_map, uint64_t vertex_index, CAWeightTag* weight_tag)
{
	switch (pmx_vertex.get_skinning_type())
	{
	case libmmd::pmx_vertex_skinning::skinning_type::BDEF1:
		{
			const auto skinning_data = reinterpret_cast<const libmmd::pmx_vertex_skinning_BDEF1*>(pmx_vertex.get_skinning());
			const auto& joint_index = weight_tag_joint_map.Find(skinning_data->get_bone_index())->GetValue();
			weight_tag->SetWeight(joint_index, static_cast<Int32>(vertex_index), 1.);
			break;
		}
	case libmmd::pmx_vertex_skinning::skinning_type::BDEF2:
		{
			const auto skinning_data = reinterpret_cast<const libmmd::pmx_vertex_skinning_BDEF2*>(pmx_vertex.get_skinning());
			const auto bone_weight = skinning_data->get_bone_weight();
			const auto& joint_index1 = weight_tag_joint_map.Find(skinning_data->get_bone_index1())->GetValue();
			const auto& joint_index2 = weight_tag_joint_map.Find(skinning_data->get_bone_index2())->GetValue();
			weight_tag->SetWeight(joint_index1, static_cast<Int32>(vertex_index), bone_weight);
			weight_tag->SetWeight(joint_index2, static_cast<Int32>(vertex_index), 1. - bone_weight);
			break;
		}
	case libmmd::pmx_vertex_skinning::skinning_type::BDEF4:
		{
			const auto skinning_data = reinterpret_cast<const libmmd::pmx_vertex_skinning_BDEF4*>(pmx_vertex.get_skinning());
			const auto bone_weight1 = skinning_data->get_bone_weight1();
			const auto bone_weight2 = skinning_data->get_bone_weight2();
			const auto bone_weight3 = skinning_data->get_bone_weight3();
			const auto bone_weight4 = skinning_data->get_bone_weight4();
			const auto& joint_index1 = weight_tag_joint_map.Find(skinning_data->get_bone_index1())->GetValue();
			const auto& joint_index2 = weight_tag_joint_map.Find(skinning_data->get_bone_index2())->GetValue();
			const auto& joint_index3 = weight_tag_joint_map.Find(skinning_data->get_bone_index3())->GetValue();
			const auto& joint_index4 = weight_tag_joint_map.Find(skinning_data->get_bone_index4())->GetValue();
			weight_tag->SetWeight(joint_index1, static_cast<Int32>(vertex_index), bone_weight1);
			weight_tag->SetWeight(joint_index2, static_cast<Int32>(vertex_index), bone_weight2);
			weight_tag->SetWeight(joint_index3, static_cast<Int32>(vertex_index), bone_weight3);
			weight_tag->SetWeight(joint_index4, static_cast<Int32>(vertex_index), bone_weight4);
			break;
		}
	case libmmd::pmx_vertex_skinning::skinning_type::SDEF:
		{
			const auto skinning_data = reinterpret_cast<const libmmd::pmx_vertex_skinning_SDEF*>(pmx_vertex.get_skinning());
			const auto bone_weight1 = skinning_data->get_bone_weight();
			const auto& joint_index1 = weight_tag_joint_map.Find(skinning_data->get_bone_index1())->GetValue();
			const auto& joint_index2 = weight_tag_joint_map.Find(skinning_data->get_bone_index2())->GetValue();
			weight_tag->SetWeight(joint_index1, static_cast<Int32>(vertex_index), bone_weight1);
			weight_tag->SetWeight(joint_index2, static_cast<Int32>(vertex_index), 1. - bone_weight1);
			break;
		}
	case libmmd::pmx_vertex_skinning::skinning_type::QDEF:
		{
			const auto skinning_data = reinterpret_cast<const libmmd::pmx_vertex_skinning_QDEF*>(pmx_vertex.get_skinning());
			const auto bone_weight1 = skinning_data->get_bone_weight1();
			const auto bone_weight2 = skinning_data->get_bone_weight2();
			const auto bone_weight3 = skinning_data->get_bone_weight3();
			const auto bone_weight4 = skinning_data->get_bone_weight4();
			const auto& joint_index1 = weight_tag_joint_map.Find(skinning_data->get_bone_index1())->GetValue();
			const auto& joint_index2 = weight_tag_joint_map.Find(skinning_data->get_bone_index2())->GetValue();
			const auto& joint_index3 = weight_tag_joint_map.Find(skinning_data->get_bone_index3())->GetValue();
			const auto& joint_index4 = weight_tag_joint_map.Find(skinning_data->get_bone_index4())->GetValue();
			weight_tag->SetWeight(joint_index1, static_cast<Int32>(vertex_index), bone_weight1);
			weight_tag->SetWeight(joint_index2, static_cast<Int32>(vertex_index), bone_weight2);
			weight_tag->SetWeight(joint_index3, static_cast<Int32>(vertex_index), bone_weight3);
			weight_tag->SetWeight(joint_index4, static_cast<Int32>(vertex_index), bone_weight4);
			break;
		}
	case libmmd::pmx_vertex_skinning::skinning_type::NONE:
		break;
	}
}
