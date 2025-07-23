/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_mesh_root.h
Description:	MMD mesh root object

**************************************************************************/

#include "pch.h"
#include "mmd_mesh_manager.h"

#include "CMTSceneManager.h"
#include "mmd_bone_manager.h"
#include "mmd_model.h"
#include "tcaposemorph.h"
#include "description/OMMDMeshManager.h"
#include "module/tools/mmd_material.h"

NodeData* MMDMeshManagerObject::Alloc()
{
	return NewObjClear(MMDMeshManagerObject);
}

Bool MMDMeshManagerObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
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

Bool MMDMeshManagerObject::Write(SDK2024_Const GeListNode* node, HyperFile* hf) SDK2024_Const
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

Bool MMDMeshManagerObject::CopyTo(NodeData* dest, SDK2024_Const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags,
	AliasTrans* trn) SDK2024_Const
{
	iferr_scope_handler{
		return false;
	};
	auto const dest_object = reinterpret_cast<MMDMeshManagerObject*>(dest);
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

Bool MMDMeshManagerObject::SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags)
{
	const auto op = reinterpret_cast<BaseObject*>(node);
	CreateDisplayTag(node);

	switch (id[0].id)
	{
	case MESH_DISPLAY_TYPE:
		if (m_display_tag != nullptr)
		{
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
		}
		break;
	case MESH_MODE:
		if (m_display_tag != nullptr)
		{
			const auto display_mode_DescID = ConstDescID(DescLevel(DISPLAYTAG_SDISPLAYMODE));
			switch (t_data.GetInt32())
			{
			case MESH_MODE_EDIT:
				{
					MMDMeshManagerObjectMsg msg(MMDMeshManagerObjectMsgType::MESH_MODE_CHANGE, MESH_DISPLAY_TYPE_OFF, MESH_MODE_EDIT);
					node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_MESH_MANAGER, &msg);
					break;
				}
			case MESH_MODE_ANIM:
				{
					MMDMeshManagerObjectMsg msg(MMDMeshManagerObjectMsgType::MESH_MODE_CHANGE, MESH_DISPLAY_TYPE_OFF, MESH_MODE_ANIM);
					node->MultiMessage(MULTIMSG_ROUTE::DOWN, ID_O_MMD_MESH_MANAGER, &msg);
					break;
				}
			default:
				break;
			}
		}
		break;
	default:
		break;
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

Bool MMDMeshManagerObject::Message(GeListNode* node, Int32 type, void* data)
{
	if (type == ID_O_MMD_MODEL)
	{
		if (const auto msg = static_cast<MMDModelRootObjectMsg*>(data); msg->msg_type == MMDModelRootObjectMsgType::MANAGER_OBJECT_UPDATE)
		{
			m_model_root = msg->object;
		}
	}
	return SUPER::Message(node, type, data);
}

EXECUTIONRESULT MMDMeshManagerObject::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority,
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

Bool MMDMeshManagerObject::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list && op)
	{
		list->Add(op, EXECUTIONPRIORITY_EXPRESSION - 2, EXECUTIONFLAGS::NONE);
	}
	return SUPER::AddToExecution(op, list);
}

const maxon::HashMap<String, maxon::BaseList<MorphUIData>>& MMDMeshManagerObject::GetMeshMorphData() const
{
	return m_mesh_morph_data;
}

Bool MMDMeshManagerObject::SetMorphStrength(const String& morph_name, const Float& strength)
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
	maxon::HashMap<maxon::String, CAMorph*> morphs;
	bool is_point_morph_tag_init = false;
	bool is_uv_morph_tag_init = false;

	morph_tag_info() = default;
	morph_tag_info(CAPoseMorphTag* morph_tag) : morph_tag(morph_tag) {}
};

struct vertex_info
{
	Int32		vertex_index = -1;
	BaseObject* mesh_object = nullptr;
	Int			morph_tag_index = -1;
	vertex_info() = default;
	vertex_info(Int32 vertex_index, BaseObject* mesh_object, Int morph_tag_index) :
		vertex_index(vertex_index), mesh_object(mesh_object), morph_tag_index(morph_tag_index) {}
	maxon::HashInt GetHashCode() const;
};

maxon::HashInt vertex_info::GetHashCode() const
{
	return MAXON_HASHCODE(mesh_object, vertex_index);
}

Bool MMDMeshManagerObject::LoadPMX(
	const libmmd::PMXFile& pmx_file,
	const maxon::BaseArray<BaseObject*>& bone_list,
	const CMTToolsSetting::ModelImport& setting)
{
	iferr_scope_handler{
		return false;
	};

	const auto& pmx_faces = pmx_file.m_faces;
	const auto& pmx_vertices = pmx_file.m_vertices;
	const auto& pmx_materials = pmx_file.m_materials;

	// create mesh
	const auto faces_count = pmx_faces.size();
	const auto vertex_count = pmx_vertices.size();
	const auto material_count = pmx_materials.size();

	if (faces_count == 0 || vertex_count == 0 || material_count == 0)
		return true;

	// create material manager
	std::shared_ptr<MMDMaterialManager> material_manager;
	if (setting.import_material)
	{
		material_manager = std::make_shared<MMDMaterialManager>();
		if (!material_manager)
			return false;
		material_manager->SetTextureRelativePath(setting.fn.GetDirectory());
		if (!material_manager->LoadPMXTextures(pmx_file.m_textures))
			return false;
	}

	std::vector<std::unordered_map<Int32, Float32>> vertex_weight_data;
	if (setting.import_weights)
	{
		// statistics vertex weight data
		vertex_weight_data.resize(vertex_count);
		maxon::ParallelFor::Dynamic(decltype(vertex_count){}, vertex_count, [&pmx_vertices, &vertex_weight_data](const Int vertex_index)
		{
			auto& weight_data = vertex_weight_data[vertex_index];
			switch (const auto& pmx_vertex = pmx_vertices[vertex_index]; pmx_vertex.m_weightType)
			{
			case libmmd::PMXVertexWeight::BDEF1:
			{
				weight_data[pmx_vertex.m_boneIndices[0]] = 1.f;
				break;
			}
			case libmmd::PMXVertexWeight::BDEF2:
			{
				const auto& bone_weight = pmx_vertex.m_boneWeights[0];
				if (auto [it, inserted] = weight_data.try_emplace(pmx_vertex.m_boneIndices[0], bone_weight); !inserted)
				{
					it->second += bone_weight;
				}
				if (auto [it, inserted] = weight_data.try_emplace(pmx_vertex.m_boneIndices[1], 1.f - bone_weight); !inserted)
				{
					it->second += 1.f - bone_weight;
				}
				break;
			}
			case libmmd::PMXVertexWeight::BDEF4:
			{
				const auto& bone_weight1 = pmx_vertex.m_boneWeights[0];
				const auto& bone_weight2 = pmx_vertex.m_boneWeights[1];
				const auto& bone_weight3 = pmx_vertex.m_boneWeights[2];
				const auto& bone_weight4 = pmx_vertex.m_boneWeights[3];
				if (auto [it, inserted] = weight_data.try_emplace(pmx_vertex.m_boneIndices[0], bone_weight1); !inserted)
				{
					it->second += bone_weight1;
				}
				if (auto [it, inserted] = weight_data.try_emplace(pmx_vertex.m_boneIndices[1], bone_weight2); !inserted)
				{
					it->second += bone_weight2;
				}
				if (auto [it, inserted] = weight_data.try_emplace(pmx_vertex.m_boneIndices[2], bone_weight3); !inserted)
				{
					it->second += bone_weight3;
				}
				if (auto [it, inserted] = weight_data.try_emplace(pmx_vertex.m_boneIndices[3], bone_weight4); !inserted)
				{
					it->second += bone_weight4;
				}
				break;
			}
			case libmmd::PMXVertexWeight::SDEF:
			{
				const auto& bone_weight = pmx_vertex.m_boneWeights[0];
				if (auto [it, inserted] = weight_data.try_emplace(pmx_vertex.m_boneIndices[0], bone_weight); !inserted)
				{
					it->second += bone_weight;
				}
				if (auto [it, inserted] = weight_data.try_emplace(pmx_vertex.m_boneIndices[1], 1.f - bone_weight); !inserted)
				{
					it->second += 1.f - bone_weight;
				}
				break;
			}
			case libmmd::PMXVertexWeight::QDEF:
			{
				const auto& bone_weight1 = pmx_vertex.m_boneWeights[0];
				const auto& bone_weight2 = pmx_vertex.m_boneWeights[1];
				const auto& bone_weight3 = pmx_vertex.m_boneWeights[2];
				const auto& bone_weight4 = pmx_vertex.m_boneWeights[3];
				if (auto [it, inserted] = weight_data.try_emplace(pmx_vertex.m_boneIndices[0], bone_weight1); !inserted)
				{
					it->second += bone_weight1;
				}
				if (auto [it, inserted] = weight_data.try_emplace(pmx_vertex.m_boneIndices[1], bone_weight2); !inserted)
				{
					it->second += bone_weight2;
				}
				if (auto [it, inserted] = weight_data.try_emplace(pmx_vertex.m_boneIndices[2], bone_weight3); !inserted)
				{
					it->second += bone_weight3;
				}
				if (auto [it, inserted] = weight_data.try_emplace(pmx_vertex.m_boneIndices[3], bone_weight4); !inserted)
				{
					it->second += bone_weight4;
				}
				break;
			}
			}
		});
	}

	// create mesh
	if (!setting.import_multipart)
	{
		PolygonObject* mesh_object = PolygonObject::Alloc(static_cast<Int32>(vertex_count), static_cast<Int32>(faces_count));
		if (!mesh_object)
			return false;
		mesh_object->SetName("Mesh"_s);
		mesh_object->InsertUnder(this->Get());

		const auto mesh_object_points = ToPoint(mesh_object)->GetPointW();
		const auto mesh_object_polygons = ToPoly(mesh_object)->GetPolygonW();

		// if import_weights is true, create weight tag
		CAWeightTag* weight_tag = nullptr;

		// mmd bone index -> weight tag joint index
		if (setting.import_weights)
		{
			weight_tag = CAWeightTag::Alloc();
			if (!weight_tag)
			{
				return false;
			}
			mesh_object->InsertTag(weight_tag);

			// add joint to weight tag
			const auto bone_count = bone_list.GetCount();
			for (auto mmd_bone_index = Int32{}; mmd_bone_index < bone_count; ++mmd_bone_index)
			{
				weight_tag->AddJoint(bone_list[mmd_bone_index]);
			}

			// add morph skin
			BaseObject* morph_skin_object = BaseObject::Alloc(Oskin);
			if (!morph_skin_object)
			{
				return false;
			}
			morph_skin_object->InsertUnder(mesh_object);
		}

		maxon::ParallelFor::Dynamic(decltype(vertex_count){}, vertex_count, [&pmx_vertices, &setting, &mesh_object_points, &weight_tag, &vertex_weight_data](const decltype(vertex_count) vertex_index)
		{
			const auto& pmx_vertex = pmx_vertices[vertex_index];

			// add vertex position
			auto& mesh_object_point = mesh_object_points[vertex_index];
			const auto& pmx_vertex_position = pmx_vertex.m_position;
			mesh_object_point.x = pmx_vertex_position[0] * setting.position_multiple;
			mesh_object_point.y = pmx_vertex_position[1] * setting.position_multiple;
			mesh_object_point.z = pmx_vertex_position[2] * setting.position_multiple;

			if (setting.import_weights)
			{
				// add weight data to weight tag
				for (const auto& [joint_index, weight] : vertex_weight_data[vertex_index])
				{
					// clamp weight at 0.0 to 1.0
					weight_tag->SetWeight(joint_index, static_cast<Int32>(vertex_index), Clamp01(weight));
				}
			}
		});

		// if import_normal is true, create normal tag
		NormalHandle normal_handle{};
		if (setting.import_normal)
		{
			NormalTag* normal_tag = NormalTag::Alloc(static_cast<Int32>(faces_count));
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
			UVWTag* uvw_tag = UVWTag::Alloc(static_cast<Int32>(faces_count));
			if (uvw_tag == nullptr)
			{
				return false;
			}
			uvw_handle = uvw_tag->GetDataAddressW();
			mesh_object->InsertTag(uvw_tag);
		}
		// vertex index -> surface index
		maxon::ParallelFor::Dynamic(decltype(faces_count){}, faces_count, [&pmx_faces, &pmx_vertices, &setting, &mesh_object_polygons, &normal_handle, &uvw_handle](const uint64_t surface_index)
		{
			iferr_scope_handler
			{
				return;
			};

			// add surface
			const auto& pmx_surface = pmx_faces[surface_index];
			const auto& pmx_surface_vertex_a = pmx_surface.m_vertices[0];
			const auto& pmx_surface_vertex_b = pmx_surface.m_vertices[1];
			const auto& pmx_surface_vertex_c = pmx_surface.m_vertices[2];

			auto& mesh_object_polygon = mesh_object_polygons[surface_index];
			mesh_object_polygon.a = static_cast<Int32>(pmx_surface_vertex_a);
			mesh_object_polygon.b = static_cast<Int32>(pmx_surface_vertex_b);
			mesh_object_polygon.c = mesh_object_polygon.d = static_cast<Int32>(pmx_surface_vertex_c);

			const auto& pmx_vertex_a = pmx_vertices[pmx_surface_vertex_a];
			const auto& pmx_vertex_b = pmx_vertices[pmx_surface_vertex_b];
			const auto& pmx_vertex_c = pmx_vertices[pmx_surface_vertex_c];

			// add normal
			if (setting.import_normal)
			{
				const auto& pmx_vertex_normal_a = pmx_vertex_a.m_normal;
				const auto& pmx_vertex_normal_b = pmx_vertex_b.m_normal;
				const auto& pmx_vertex_normal_c = pmx_vertex_c.m_normal;

				NormalTag::Set(normal_handle, static_cast<Int32>(surface_index), NormalStruct(
					Vector(pmx_vertex_normal_a[0], pmx_vertex_normal_a[1], pmx_vertex_normal_a[2]).GetNormalized(),
					Vector(pmx_vertex_normal_b[0], pmx_vertex_normal_b[1], pmx_vertex_normal_b[2]).GetNormalized(),
					Vector(pmx_vertex_normal_c[0], pmx_vertex_normal_c[1], pmx_vertex_normal_c[2]).GetNormalized(),
					Vector{}));
			}
			// add uv
			if (setting.import_uv)
			{
				const auto& pmx_vertex_uv_a = pmx_vertex_a.m_uv;
				const auto& pmx_vertex_uv_b = pmx_vertex_b.m_uv;
				const auto& pmx_vertex_uv_c = pmx_vertex_c.m_uv;

				UVWTag::Set(uvw_handle, static_cast<Int32>(surface_index), UVWStruct(
					Vector(pmx_vertex_uv_a[0], pmx_vertex_uv_a[1], 0.),
					Vector(pmx_vertex_uv_b[0], pmx_vertex_uv_b[1], 0.),
					Vector(pmx_vertex_uv_c[0], pmx_vertex_uv_c[1], 0.),
					Vector{}));
			}
		});

		// set weight tag
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
			for (const auto& pmx_morph : pmx_file.m_morphs)
			{
				switch (pmx_morph.m_morphType)
				{
				case libmmd::PMXMorphType::Position:
				{
					const auto& position_morphs = pmx_morph.m_positionMorph;

					if (position_morphs.empty())
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
					morph->SetName(maxon::String{ pmx_morph.m_name.c_str() });

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
					for (const auto& [vertex_index, position] : position_morphs)
					{
						morph_node->SetPoint(vertex_index,
							Vector(position[0], position[1], position[2]) * setting.position_multiple);
					}

					morph->SetMode(setting.doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::COLLAPSE, CAMORPH_MODE::AUTO);
					morph_tag->UpdateMorphs();
					morph_tag->Message(MSG_UPDATE);
					morph->SetStrength(0);
					break;
				}
				case libmmd::PMXMorphType::UV: [[fallthrough]];
				case libmmd::PMXMorphType::AddUV1: [[fallthrough]];
				case libmmd::PMXMorphType::AddUV2: [[fallthrough]];
				case libmmd::PMXMorphType::AddUV3: [[fallthrough]];
				case libmmd::PMXMorphType::AddUV4:
				{
					const auto& uv_morphs = pmx_morph.m_uvMorph;

					if (uv_morphs.empty())
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
					morph->SetName(maxon::String{ pmx_morph.m_name.c_str() });

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
					for (const auto& [vertex_index, uv] : uv_morphs)
					{
						morph_uv_map.Insert(vertex_index, Vector(uv[0], uv[1], 0.))iferr_return;
					}

					// add morph uv
					maxon::ParallelFor::Dynamic(decltype(faces_count){}, faces_count, [&pmx_faces, &morph_node, &morph_uv_map](const uint64_t surface_index)
					{
						iferr_scope_handler{
							return;
						};
						const auto& pmx_surface = pmx_faces[surface_index];
						const auto& pmx_surface_vertex_a = pmx_surface.m_vertices[0];
						const auto& pmx_surface_vertex_b = pmx_surface.m_vertices[1];
						const auto& pmx_surface_vertex_c = pmx_surface.m_vertices[2];
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

					morph->SetMode(setting.doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::COLLAPSE, CAMORPH_MODE::AUTO);
					morph_tag->UpdateMorphs();
					morph_tag->Message(MSG_UPDATE);
					morph->SetStrength(0);
					break;
				}
				case libmmd::PMXMorphType::Flip:
				case libmmd::PMXMorphType::Group: [[fallthrough]];
				case libmmd::PMXMorphType::Material: [[fallthrough]];
				case libmmd::PMXMorphType::Bone: [[fallthrough]];
				case libmmd::PMXMorphType::Impluse:
					break;
				}
			}
			morph_tag->SetParameter(ConstDescID(DescLevel(ID_CA_POSE_MODE)), ID_CA_POSE_MODE_ANIMATE, DESCFLAGS_SET::NONE);
		}

		auto surface_begin_index = decltype(faces_count){};
		for (auto material_index = decltype(material_count){}; material_index < material_count; ++material_index)
		{
			const auto& pmx_material = pmx_materials[material_index];
			const auto part_vertices_num = pmx_material.m_numFaceVertices;
			const auto part_face_num = part_vertices_num / 3;

			if (part_face_num == 0)
				continue;

			maxon::String material_name;
			if (setting.import_english)
			{
				if (maxon::String material_name_universal(pmx_material.m_englishName.c_str()); material_name_universal.IsEmpty())
				{
					material_name = "Mesh_" + String::UIntToString(material_index);
				}
				else
				{
					material_name = std::move(material_name_universal);
				}
			}
			else
			{
				material_name = maxon::String(pmx_material.m_name.c_str());
			}

			const auto polygon_selection_tag = SelectionTag::Alloc(Tpolygonselection);
			if (!polygon_selection_tag)
				return false;
			polygon_selection_tag->GetWritableBaseSelect()->SelectAll(static_cast<Int32>(surface_begin_index), static_cast<Int32>(surface_begin_index + part_face_num - 1));
			polygon_selection_tag->SetName(material_name);
			mesh_object->InsertTag(polygon_selection_tag);

			if (setting.import_material)
			{
				const auto material = material_manager->LoadPMXMaterial(pmx_material, material_index, material_name, setting);
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

			surface_begin_index += part_face_num;
		}
	}
	else
	{
		maxon::BaseArray<morph_tag_info> morph_tag_infos;
		maxon::Synchronized<maxon::HashMap<uint64_t, vertex_info>> vertex_info_map;

		auto surface_begin_index = decltype(faces_count){};
		for (auto material_index = decltype(material_count){}; material_index < material_count; ++material_index)
		{
			const auto& pmx_material = pmx_materials[material_index];
			const auto part_vertices_num = pmx_material.m_numFaceVertices;
			const auto part_face_num = part_vertices_num / 3;

			maxon::String material_name;

			if (part_face_num == 0)
				continue;

			if (setting.import_english)
			{
				if (maxon::String material_name_universal(pmx_material.m_englishName.c_str()); material_name_universal.IsEmpty())
				{
					material_name = "Mesh_" + String::UIntToString(material_index);
				}
				else
				{
					material_name = std::move(material_name_universal);
				}
			}
			else
			{
				material_name = maxon::String(pmx_material.m_name.c_str());
			}

			PolygonObject* mesh_object = PolygonObject::Alloc(part_vertices_num, part_face_num);
			mesh_object->SetName(material_name);
			mesh_object->InsertUnder(Get());

			if (setting.import_material)
			{
				const auto material = material_manager->LoadPMXMaterial(pmx_material, material_index, material_name, setting);
				if (!material)
					return false;
				setting.doc->InsertMaterial(material);

				const auto texture_tag = TextureTag::Alloc();
				if (!texture_tag)
					return false;
				texture_tag->SetName(material_name);
				texture_tag->SetMaterial(material);
				texture_tag->SetParameter(ConstDescID(DescLevel(TEXTURETAG_PROJECTION)), TEXTURETAG_PROJECTION_UVW, DESCFLAGS_SET::NONE);
				mesh_object->InsertTag(texture_tag);
			}

			// if import_weights is true, create weight tag
			CAWeightTag* weight_tag = nullptr;

			// mmd bone index -> weight tag joint index
			if (setting.import_weights)
			{
				weight_tag = CAWeightTag::Alloc();
				if (!weight_tag)
				{
					return false;
				}
				mesh_object->InsertTag(weight_tag);

				// add joint to weight tag
				const auto bone_count = bone_list.GetCount();
				for (auto mmd_bone_index = Int32{}; mmd_bone_index < bone_count; ++mmd_bone_index)
				{
					weight_tag->AddJoint(bone_list[mmd_bone_index]);
				}

				// add morph skin
				BaseObject* morph_skin_object = BaseObject::Alloc(Oskin);
				if (!morph_skin_object)
				{
					return false;
				}
				morph_skin_object->InsertUnder(mesh_object);
			}

			// create morph tag
			if (setting.import_expression)
			{
				/* Initialization morph tag. */
				CAPoseMorphTag* morph_tag = CAPoseMorphTag::Alloc();
				morph_tag->SetName("morph_"_s + material_name);
				if (!morph_tag)
					return false;
				mesh_object->InsertTag(morph_tag);
				morph_tag_infos.Append(morph_tag_info{ morph_tag })iferr_return;
			}

			maxon::HashMap<uint32_t, Int32> vertex_index_map;
			// add vertex position and weight data
			{
				Int32 part_vertex_count = 0;
				for (auto surface_index = surface_begin_index; surface_index < surface_begin_index + part_face_num; ++surface_index)
				{
					const auto& pmx_surface =  pmx_faces[surface_index];
					const auto& pmx_surface_vertex_a = pmx_surface.m_vertices[0];
					const auto& pmx_surface_vertex_b = pmx_surface.m_vertices[1];
					const auto& pmx_surface_vertex_c = pmx_surface.m_vertices[2];

					if (!vertex_index_map.Contains(pmx_surface_vertex_a))
						vertex_index_map.Insert(pmx_surface_vertex_a, part_vertex_count++)iferr_return;

					if (!vertex_index_map.Contains(pmx_surface_vertex_b))
						vertex_index_map.Insert(pmx_surface_vertex_b, part_vertex_count++)iferr_return;

					if (!vertex_index_map.Contains(pmx_surface_vertex_c))
						vertex_index_map.Insert(pmx_surface_vertex_c, part_vertex_count++)iferr_return;
				}
				maxon::BaseArray<uint32_t> pmx_vertex_index_array;
				for (const auto& vertex_index : vertex_index_map.GetKeys())
				{
					pmx_vertex_index_array.Append(vertex_index)iferr_return;
				}

				if (!mesh_object->ResizeObject(part_vertex_count, static_cast<Int32>(part_face_num)))
					return false;

				const auto mesh_object_points = ToPoint(mesh_object)->GetPointW();

				maxon::ParallelFor::Dynamic(0, part_vertex_count, [&setting, &pmx_vertices, &mesh_object_points, &weight_tag, &vertex_weight_data, &pmx_vertex_index_array, &vertex_index_map, &vertex_info_map, &mesh_object, &morph_tag_infos](const Int32 vertex_index)
				{
					iferr_scope_handler
					{
						return;
					};
					const auto & pmx_vertex_index = pmx_vertex_index_array[vertex_index];
					const auto & pmx_vertex = pmx_vertices[pmx_vertex_index];
					// add vertex position
					const auto & c4d_vertex_index = vertex_index_map.Find(pmx_vertex_index)->GetValue();
					auto & mesh_object_point = mesh_object_points[c4d_vertex_index];
					const auto & pmx_vertex_position = pmx_vertex.m_position;
					mesh_object_point.x = pmx_vertex_position[0] * setting.position_multiple;
					mesh_object_point.y = pmx_vertex_position[1] * setting.position_multiple;
					mesh_object_point.z = pmx_vertex_position[2] * setting.position_multiple;

					if (setting.import_expression)
					{
						vertex_info_map.Write([&pmx_vertex_index, &c4d_vertex_index, &mesh_object, &setting, &morph_tag_infos](maxon::HashMap<uint64_t, vertex_info>& map)->maxon::Result<void>
						{
							iferr_scope;
							auto& entry = map.InsertMultiEntry(pmx_vertex_index)iferr_return;
							auto& vertex_info = entry.GetValue();
							vertex_info.vertex_index = c4d_vertex_index;
							vertex_info.mesh_object = mesh_object;
							vertex_info.morph_tag_index = morph_tag_infos.GetCount() - 1;
							return maxon::OK;
						})iferr_return;
					}

					if (setting.import_weights)
					{
						// add weight data to weight tag
						for (const auto& [joint_index, weight] : vertex_weight_data[pmx_vertex_index])
						{
							// clamp weight at 0.0 to 1.0
							weight_tag->SetWeight(joint_index, c4d_vertex_index, Clamp01(weight));
						}
					}
				});
			}

			// if import_normal is true, create normal tag
			NormalHandle normal_handle{};
			if (setting.import_normal)
			{
				NormalTag* normal_tag = NormalTag::Alloc(static_cast<Int32>(part_face_num));
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
				UVWTag* uvw_tag = UVWTag::Alloc(static_cast<Int32>(part_face_num));
				if (uvw_tag == nullptr)
				{
					return false;
				}
				uvw_handle = uvw_tag->GetDataAddressW();
				mesh_object->InsertTag(uvw_tag);
			}


			// vertex index -> surface index
			const auto mesh_object_polygons = ToPoly(mesh_object)->GetPolygonW();
			maxon::ParallelFor::Dynamic(surface_begin_index, surface_begin_index + part_face_num, [&pmx_faces, &pmx_vertices, &setting, &mesh_object_polygons, &normal_handle, &uvw_handle, &surface_begin_index, &vertex_index_map](const uint64_t surface_index)
			{
				iferr_scope_handler
				{
					return;
				};

				const auto & pmx_surface = pmx_faces[surface_index];
				const auto & pmx_surface_vertex_a = pmx_surface.m_vertices[0];
				const auto & pmx_surface_vertex_b = pmx_surface.m_vertices[1];
				const auto & pmx_surface_vertex_c = pmx_surface.m_vertices[2];

				// add index
				const auto object_surface_index = surface_index - surface_begin_index;
				auto & mesh_object_polygon = mesh_object_polygons[object_surface_index];

				if (const auto vertex_index_a_ptr = vertex_index_map.Find(pmx_surface_vertex_a); vertex_index_a_ptr)
				{
					mesh_object_polygon.a = vertex_index_a_ptr->GetValue();
				}
				if (const auto vertex_index_b_ptr = vertex_index_map.Find(pmx_surface_vertex_b); vertex_index_b_ptr)
				{
					mesh_object_polygon.b = vertex_index_b_ptr->GetValue();
				}
				if (const auto vertex_index_c_ptr = vertex_index_map.Find(pmx_surface_vertex_c); vertex_index_c_ptr)
				{
					mesh_object_polygon.c = mesh_object_polygon.d = vertex_index_c_ptr->GetValue();
				}

				const auto& pmx_vertex_a = pmx_vertices[pmx_surface_vertex_a];
				const auto& pmx_vertex_b = pmx_vertices[pmx_surface_vertex_b];
				const auto& pmx_vertex_c = pmx_vertices[pmx_surface_vertex_c];

				// add normal
				if (setting.import_normal)
				{
					const auto& pmx_vertex_normal_a = pmx_vertex_a.m_normal;
					const auto& pmx_vertex_normal_b = pmx_vertex_b.m_normal;
					const auto& pmx_vertex_normal_c = pmx_vertex_c.m_normal;

					NormalTag::Set(normal_handle, static_cast<Int32>(object_surface_index), NormalStruct(
						Vector(pmx_vertex_normal_a[0], pmx_vertex_normal_a[1], pmx_vertex_normal_a[2]).GetNormalized(),
						Vector(pmx_vertex_normal_b[0], pmx_vertex_normal_b[1], pmx_vertex_normal_b[2]).GetNormalized(),
						Vector(pmx_vertex_normal_c[0], pmx_vertex_normal_c[1], pmx_vertex_normal_c[2]).GetNormalized(),
						Vector{}));
				}
				// add uv
				if (setting.import_uv)
				{
					const auto& pmx_vertex_uv_a = pmx_vertex_a.m_uv;
					const auto& pmx_vertex_uv_b = pmx_vertex_b.m_uv;
					const auto& pmx_vertex_uv_c = pmx_vertex_c.m_uv;

					UVWTag::Set(uvw_handle, static_cast<Int32>(object_surface_index), UVWStruct(
						Vector(pmx_vertex_uv_a[0], pmx_vertex_uv_a[1], 0.),
						Vector(pmx_vertex_uv_b[0], pmx_vertex_uv_b[1], 0.),
						Vector(pmx_vertex_uv_c[0], pmx_vertex_uv_c[1], 0.),
						Vector{}));
				}
			});

			// set weight tag
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

			surface_begin_index += part_face_num;
		}

		if (setting.import_expression)
		{
			// initialize morph tag
			for (const auto& morph_tag_info : morph_tag_infos)
			{
				const auto& morph_tag = morph_tag_info.morph_tag;
				morph_tag->InitMorphs();
				morph_tag->ExitEdit(setting.doc, true);

				CAMorph* base_morph = morph_tag->AddMorph();
				if (!base_morph)
					return false;

				base_morph->Store(setting.doc, morph_tag, CAMORPH_DATA_FLAGS::ASTAG);
				morph_tag->UpdateMorphs();
			}

			for (const auto& pmx_morph : pmx_file.m_morphs)
			{
				maxon::String pmx_morph_name{ pmx_morph.m_name.c_str() };
				switch (pmx_morph.m_morphType)
				{
				case libmmd::PMXMorphType::Position:
				{
					const auto& position_morphs = pmx_morph.m_positionMorph;

					if (position_morphs.empty())
						continue;

					// morph name

					// add morph point
					for (const auto& [src_vertex_index, position] : position_morphs)
					{
						// MultiMap
						for (auto it = vertex_info_map.Read()->FindAll(src_vertex_index); it; ++it)
						{
							const auto& [vertex_index, offset_mesh_object, morph_tag_index] = it->GetValue();
							auto& [morph_tag, morphs, is_point_morph_tag_init, is_uv_morph_tag_init] = morph_tag_infos[morph_tag_index];

							if (!is_point_morph_tag_init)
							{
								morph_tag->SetParameter(ConstDescID(DescLevel(ID_CA_POSE_POINTS)), true, DESCFLAGS_SET::NONE);
								is_point_morph_tag_init = true;
							}

							CAMorph* morph = nullptr;
							if (auto morph_ptr = morphs.Find(pmx_morph_name); !morph_ptr)
							{
								morph = morph_tag->AddMorph();
								if (!morph)
									return false;

								morphs.Insert(pmx_morph_name, morph)iferr_return;

								// set morph name
								morph->SetName(pmx_morph_name);

								morph->Store(setting.doc, morph_tag, CAMORPH_DATA_FLAGS::ASTAG);

								// set morph mode
								morph->SetMode(setting.doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::EXPAND, CAMORPH_MODE::REL);
							}
							else
							{
								morph = morph_ptr->GetValue();
							}

							// set morph node to end
							CAMorphNode* morph_node = morph->GetFirst();
							while (!(morph_node->GetInfo() & CAMORPH_DATA_FLAGS::POINTS) && morph_node)
							{
								morph_node = morph_node->GetNext();
							}

							morph_node->SetPoint(vertex_index,
								Vector(position[0], position[1], position[2]) * setting.position_multiple);
						}
					}

					break;
				}
				case libmmd::PMXMorphType::UV: [[fallthrough]];
				case libmmd::PMXMorphType::AddUV1: [[fallthrough]];
				case libmmd::PMXMorphType::AddUV2: [[fallthrough]];
				case libmmd::PMXMorphType::AddUV3: [[fallthrough]];
				case libmmd::PMXMorphType::AddUV4:
				{
					const auto& uv_morphs = pmx_morph.m_uvMorph;

					if (uv_morphs.empty())
						continue;

					// vertex_index -> uv offset
					maxon::HashMap<Int32, std::tuple<CAMorphNode*, Vector>> morph_uv_map;
					// mapping uv morph from vertex_index to surface_index
						for (const auto& [src_vertex_index, uv] : uv_morphs)
					{
						// MultiMap
						for (auto it = vertex_info_map.Read()->FindAll(src_vertex_index); it; ++it)
						{
							const auto& [vertex_index, offset_mesh_object, morph_tag_index] = it->GetValue();
							auto& [morph_tag, morphs, is_point_morph_tag_init, is_uv_morph_tag_init] = morph_tag_infos[morph_tag_index];

							if (!is_uv_morph_tag_init)
							{
								morph_tag->SetParameter(ConstDescID(DescLevel(ID_CA_POSE_UV)), true, DESCFLAGS_SET::NONE);
								is_uv_morph_tag_init = true;
							}

							CAMorph* morph = nullptr;
							if (auto morph_ptr = morphs.Find(pmx_morph_name); !morph_ptr)
							{
								morph = morph_tag->AddMorph();
								if (!morph)
									return false;

								morphs.Insert(pmx_morph_name, morph)iferr_return;

								// set morph name
								morph->SetName(pmx_morph_name);

								morph->Store(setting.doc, morph_tag, CAMORPH_DATA_FLAGS::ASTAG);

								// set morph mode
								morph->SetMode(setting.doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::EXPAND, CAMORPH_MODE::REL);
							}
							else
							{
								morph = morph_ptr->GetValue();
							}

							// set morph node to end
							CAMorphNode* morph_node = morph->GetFirst();
							while (!(morph_node->GetInfo() & CAMORPH_DATA_FLAGS::UV) && morph_node)
							{
								morph_node = morph_node->GetNext();
							}

							morph_uv_map.Insert(src_vertex_index, std::make_tuple(morph_node, Vector(uv[0], uv[1], 0.)))iferr_return;
						}
					}

					// add morph uv
					maxon::ParallelFor::Dynamic(decltype(faces_count){}, faces_count, [&pmx_faces, &morph_uv_map](const uint64_t surface_index)
					{
						const auto& pmx_surface = pmx_faces[surface_index];
						const auto& pmx_surface_vertex_a = pmx_surface.m_vertices[0];
						const auto& pmx_surface_vertex_b = pmx_surface.m_vertices[1];
						const auto& pmx_surface_vertex_c = pmx_surface.m_vertices[2];
						UVWStruct uvw{};
						CAMorphNode* morph_node = nullptr;
						if (const auto vertex_a_ptr = morph_uv_map.Find(pmx_surface_vertex_a); vertex_a_ptr)
						{
							const auto& [morph_node_, offset] = vertex_a_ptr->GetValue();
							uvw[0] = offset;
							morph_node = morph_node_;
						}
						else if (const auto vertex_b_ptr = morph_uv_map.Find(pmx_surface_vertex_b); vertex_b_ptr)
						{
							const auto& [morph_node_, offset] = vertex_b_ptr->GetValue();
							uvw[1] = offset;
							morph_node = morph_node_;
						}
						else if (const auto vertex_c_ptr = morph_uv_map.Find(pmx_surface_vertex_c); vertex_c_ptr)
						{
							const auto& [morph_node_, offset] = vertex_c_ptr->GetValue();
							uvw[2] = offset;
							morph_node = morph_node_;
						}
						if (morph_node)
						{
							morph_node->SetUV(0, static_cast<Int32>(surface_index), uvw);
						}
					});
					break;
				}
				case libmmd::PMXMorphType::Flip:
				case libmmd::PMXMorphType::Group: [[fallthrough]];
				case libmmd::PMXMorphType::Material: [[fallthrough]];
				case libmmd::PMXMorphType::Bone: [[fallthrough]];
				case libmmd::PMXMorphType::Impluse:
					break;
				}
			}

			// set morph tag mode
			for (const auto& morph_tag_info : morph_tag_infos)
			{
				const auto& morph_tag = morph_tag_info.morph_tag;
				const auto morph_tag_count = morph_tag->GetMorphCount();
				for (auto morph_index = decltype(morph_tag_count){}; morph_index < morph_tag_count; ++morph_index)
				{
					auto* morph = morph_tag->GetMorph(morph_index);
					morph->SetMode(setting.doc, morph_tag, CAMORPH_MODE_FLAGS::ALL | CAMORPH_MODE_FLAGS::COLLAPSE, CAMORPH_MODE::AUTO);
				}
				morph_tag->UpdateMorphs();
				morph_tag->SetParameter(ConstDescID(DescLevel(ID_CA_POSE_MODE)), ID_CA_POSE_MODE_ANIMATE, DESCFLAGS_SET::NONE);
			}
		}
	}
	return true;
}

Bool MMDMeshManagerObject::SavePMX(libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelExport& setting)
{
	return false;
}

void MMDMeshManagerObject::RefreshMeshMorphData(BaseObject* op)
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
					if (!is_no_update_mode)
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
			MMDMeshManagerObjectMsg msg{ MMDMeshManagerObjectMsgType::MESH_MORPH_CHANGE };
			m_model_root->Message(ID_O_MMD_MESH_MANAGER, &msg);
		}
	}
}
