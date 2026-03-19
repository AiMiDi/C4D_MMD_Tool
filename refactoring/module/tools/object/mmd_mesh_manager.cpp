/**************************************************************************

Copyright:Copyright(c) 2022-present, Aimidi & CMT contributors.
Author:			Aimidi
Date:			2023/9/12
File:			mmd_mesh_root.h
Description:	MMD mesh root object

**************************************************************************/

#include <c4d.h>
#include <c4d_symbols.h>
#include "plugin_resource.h"
#include "module/core/cmt_marco.h"
#include "mmd_mesh_manager.h"
#include "CMTSceneManager.h"
#include "lib_ca.h"
#include "mmd_bone_manager.h"
#include "mmd_model_manager.h"
#include "tcaposemorph.h"
#include "description/OMMDMeshManager.h"
#include "maxon/parallelfor.h"
#include "maxon/queue.h"
#include "module/tools/material/mmd_material.h"
#include "utils/string_util.hpp"

namespace cinema
{
	class CAWeightTag;
	class CAMorph;
	class CAPoseMorphTag;
}

NodeData* MMDMeshManagerObject::Alloc()
{
	return NewObjClear(MMDMeshManagerObject);
}

template<>
bool inline io_util::ReadData<maxon::PointerArray<MorphUIData>>(HyperFile* hf, maxon::PointerArray<MorphUIData>& data)
{
	if (!ReadLinearContainer(hf, data))
		return false;
	return true;
}

template<>
bool inline io_util::WriteData<maxon::PointerArray<MorphUIData>>(HyperFile* hf, const maxon::PointerArray<MorphUIData>& data)
{
	if (!WriteLinearContainer(hf, data))
		return false;
	return true;
}

Bool MMDMeshManagerObject::Read(GeListNode* node, HyperFile* hf, Int32 level)
{
	iferr_scope_handler{
		return false;
	};
	IOReadField(mesh_mode_);
	IOReadField(model_manager_);

	if (!io_util::ReadHashMap(hf, mesh_morph_mode_))
		return false;

	if (!io_util::ReadHashMap(hf, mesh_morph_name_))
		return false;

	if (!io_util::ReadLinearContainer(hf, morph_manager_index_))
		return false;

	if (!io_util::ReadLinearContainer(hf, mesh_morph_data_))
		return false;

	Int64 uv_count = 0;
	if (!hf->ReadInt64(&uv_count))
		return SUPER::Read(node, hf, level);
	uv_morph_names_.Reset();
	for (Int64 i = 0; i < uv_count; ++i)
	{
		String s;
		if (!io_util::ReadData(hf, s))
			return false;
		uv_morph_names_.Insert(s)iferr_return;
	}

	*needs_morph_data_refresh_.Write() = true;
	return SUPER::Read(node, hf, level);
}

SDK2024_Write(MMDMeshManagerObject)
{
	IOWriteField(mesh_mode_);
	IOWriteField(model_manager_);

	if (!io_util::WriteHashMap(hf, mesh_morph_mode_))
		return false;

	if (!io_util::WriteHashMap(hf, mesh_morph_name_))
		return false;

	if (!io_util::WriteLinearContainer(hf, morph_manager_index_))
		return false;

	if (!io_util::WriteLinearContainer(hf, mesh_morph_data_))
		return false;

	if (!hf->WriteInt64(uv_morph_names_.GetCount()))
		return false;
	for (const auto& name : uv_morph_names_)
	{
		if (!io_util::WriteData(hf, name))
			return false;
	}

	return SUPER::Write(node, hf);
}

SDK2024_CopyTo(MMDMeshManagerObject)
{
	iferr_scope_handler{
		return false;
	};
	auto const dest_object = reinterpret_cast<MMDMeshManagerObject*>(dest);
	for (const auto& entry : mesh_morph_mode_)
	{
		dest_object->mesh_morph_mode_.Insert(entry.GetKey(), entry.GetValue())iferr_return;
	}
	for (const auto& name : uv_morph_names_)
	{
		dest_object->uv_morph_names_.Insert(name)iferr_return;
	}
	*dest_object->needs_morph_data_refresh_.Write() = true;
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
		mesh_mode_ = t_data.GetInt32();
		break;
	default:
		break;
	}
	return SUPER::SetDParameter(node, id, t_data, flags);
}

Bool MMDMeshManagerObject::Message(GeListNode* node, Int32 type, void* data)
{
	if (type == g_mmd_model_manager_object_id)
	{
		switch (const auto msg = static_cast<MMDModelManagerObjectMsg*>(data); msg->msg_type)
		{
		case MMDModelManagerObjectMsgType::MANAGER_OBJECT_UPDATE:
			model_manager_->SetLink(msg->object);
			break;
		case MMDModelManagerObjectMsgType::MODEL_MODE_CHANGE:
			node->SetParameter(ConstDescID(DescLevel(MESH_MODE)),msg->model_mode, DESCFLAGS_SET::NONE);
			break;
		case MMDModelManagerObjectMsgType::DEFAULT:
			break;
		}
	}
	return SUPER::Message(node, type, data);
}

EXECUTIONRESULT MMDMeshManagerObject::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority,
	EXECUTIONFLAGS flags)
{
	if (!io_util::ResolveObjectLink(model_manager_))
	{
		if (BaseObject* up_object = op->GetUp(); up_object->IsInstanceOf(g_mmd_model_manager_object_id))
		{
			model_manager_->SetLink(up_object);
		}
	}

	if (*needs_morph_data_refresh_.Read())
	{
		mesh_morph_mode_.Reset();
		mesh_morph_name_.Reset();
		mesh_morph_data_.Reset();
		morph_manager_index_.Reset();
		RefreshMeshMorphData(op, true);
		*needs_morph_data_refresh_.Write() = false;
	}

	if (mesh_mode_ == MESH_MODE_VMD && mmd_morph_manager_)
	{
		const auto morph_manager_count = morph_manager_index_.GetCount();
		const auto mmd_morph_manager_count = mmd_morph_manager_->GetMorphCount();
		for (int i = 0; i < morph_manager_count; ++i)
		{
			if(i >= mmd_morph_manager_count)
				continue;
			const auto strength = mmd_morph_manager_->GetMorph(i)->GetWeight();
			if (const auto mesh_morph_data_index = morph_manager_index_[i];
				mesh_morph_data_index != -1 && mesh_morph_data_index < mesh_morph_data_.GetCount())
			{
				const auto& sub_morphs = mesh_morph_data_[mesh_morph_data_index];
				for (const auto& sub_morph : sub_morphs)
				{
					sub_morph.SetStrength(strength);
				}
			}
		}
	}

	return SUPER::Execute(op, doc, bt, priority, flags);
}

Bool MMDMeshManagerObject::AddToExecution(BaseObject* op, PriorityList* list)
{
	if (list && op)
	{
		list->Add(op, EXECUTIONPRIORITY_EXPRESSION, EXECUTIONFLAGS::NONE);
	}
	return SUPER::AddToExecution(op, list);
}

const maxon::HashMap<String, Int32>& MMDMeshManagerObject::GetMeshMorphData() const
{
	return mesh_morph_name_;
}

const maxon::HashSet<String>& MMDMeshManagerObject::GetUVMorphNames() const
{
	return uv_morph_names_;
}

Bool MMDMeshManagerObject::SetMorphStrength(const String& morph_name, const Float& strength)
{
	const auto morph_ptr = mesh_morph_name_.Find(morph_name);
	if (!morph_ptr)
		return false;
	const auto index = morph_ptr->GetSecond();
	if (index < 0 || index >= mesh_morph_data_.GetCount())
		return false;
	const auto& sub_morphs = mesh_morph_data_[index];
	for (const auto& sub_morph : sub_morphs)
	{
		sub_morph.SetStrength(strength);
	}
	return true;
}

Bool MMDMeshManagerObject::GetMorphStrength(const String& morph_name, Float& out_strength) const
{
	const auto morph_ptr = mesh_morph_name_.Find(morph_name);
	if (!morph_ptr)
		return false;
	const auto index = morph_ptr->GetSecond();
	if (index < 0 || index >= mesh_morph_data_.GetCount())
		return false;
	const auto& sub_morphs = mesh_morph_data_[index];
	if (sub_morphs.GetCount() == 0)
		return false;
	out_strength = sub_morphs[0].GetStrength();
	return true;
}

void MMDMeshManagerObject::RequestMorphDataRefresh()
{
	*needs_morph_data_refresh_.Write() = true;
}

void MMDMeshManagerObject::ForceRefreshMorphData(BaseObject* op)
{
	mesh_morph_mode_.Reset();
	mesh_morph_name_.Reset();
	mesh_morph_data_.Reset();
	morph_manager_index_.Reset();
	RefreshMeshMorphData(op, true);
	*needs_morph_data_refresh_.Write() = false;
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
		mesh_object->InsertUnderLast(this->Get());

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
			morph_skin_object->InsertUnderLast(mesh_object);
		}

		maxon::ParallelFor::Dynamic(decltype(vertex_count){}, vertex_count, [&pmx_vertices, &setting, &mesh_object_points, &weight_tag, &vertex_weight_data](const decltype(vertex_count) vertex_index)
		{
			const auto& pmx_vertex = pmx_vertices[vertex_index];

			// add vertex position
			auto& mesh_object_point = mesh_object_points[vertex_index];
			const auto& pmx_vertex_position = pmx_vertex.m_position;
			mesh_object_point.x = pmx_vertex_position[0];
			mesh_object_point.y = pmx_vertex_position[1];
			mesh_object_point.z = pmx_vertex_position[2];

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

		// create edge magnitude VertexMapTag
		{
			VertexMapTag* edge_map_tag = VertexMapTag::Alloc(static_cast<Int32>(vertex_count));
			if (edge_map_tag)
			{
				edge_map_tag->SetName("\u8F6E\u5ED3\u500D\u7387"_s);
				Float32* edge_data = edge_map_tag->GetDataAddressW();
				for (auto vi = decltype(vertex_count){}; vi < vertex_count; ++vi)
				{
					edge_data[vi] = pmx_vertices[vi].m_edgeMag;
				}
				mesh_object->InsertTag(edge_map_tag);
			}
		}

		// create SDEF VertexColorTags if any SDEF vertices exist
		{
			bool has_sdef = false;
			for (auto vi = decltype(vertex_count){}; vi < vertex_count; ++vi)
			{
				if (pmx_vertices[vi].m_weightType == libmmd::PMXVertexWeight::SDEF)
				{
					has_sdef = true;
					break;
				}
			}
			if (has_sdef)
			{
				VertexColorTag* tag_c = VertexColorTag::Alloc(static_cast<Int32>(vertex_count));
				VertexColorTag* tag_r0 = VertexColorTag::Alloc(static_cast<Int32>(vertex_count));
				VertexColorTag* tag_r1 = VertexColorTag::Alloc(static_cast<Int32>(vertex_count));
				if (tag_c && tag_r0 && tag_r1)
				{
					tag_c->SetName("SDEF_C"_s);
					tag_r0->SetName("SDEF_R0"_s);
					tag_r1->SetName("SDEF_R1"_s);

					tag_c->SetPerPointMode(true);
					tag_r0->SetPerPointMode(true);
					tag_r1->SetPerPointMode(true);

					VertexColorHandle handle_c = tag_c->GetDataAddressW();
					VertexColorHandle handle_r0 = tag_r0->GetDataAddressW();
					VertexColorHandle handle_r1 = tag_r1->GetDataAddressW();

					for (auto vi = decltype(vertex_count){}; vi < vertex_count; ++vi)
					{
						const auto& v = pmx_vertices[vi];
						maxon::ColorA32 col_c, col_r0, col_r1;
						if (v.m_weightType == libmmd::PMXVertexWeight::SDEF)
						{
							col_c = maxon::ColorA32(v.m_sdefC.x(), v.m_sdefC.y(), v.m_sdefC.z(), 1.0f);
							col_r0 = maxon::ColorA32(v.m_sdefR0.x(), v.m_sdefR0.y(), v.m_sdefR0.z(), 1.0f);
							col_r1 = maxon::ColorA32(v.m_sdefR1.x(), v.m_sdefR1.y(), v.m_sdefR1.z(), 1.0f);
						}
						else
						{
							col_c = col_r0 = col_r1 = maxon::ColorA32(0, 0, 0, 1.0f);
						}
						VertexColorTag::Set(handle_c, nullptr, nullptr, static_cast<Int32>(vi), col_c);
						VertexColorTag::Set(handle_r0, nullptr, nullptr, static_cast<Int32>(vi), col_r0);
						VertexColorTag::Set(handle_r1, nullptr, nullptr, static_cast<Int32>(vi), col_r1);
					}
					mesh_object->InsertTag(tag_c);
					mesh_object->InsertTag(tag_r0);
					mesh_object->InsertTag(tag_r1);
				}
			}
		}

		// if import_expression is true, create morph tag
		if (setting.import_expression)
		{
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
							Vector(position[0], position[1], position[2]));
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

					uv_morph_names_.Insert(maxon::String{ pmx_morph.m_name.c_str() })iferr_return;

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

			BaseMaterial* material = nullptr;
			if (setting.import_material)
			{
				material = material_manager->LoadPMXMaterial(pmx_material, material_index, material_name, setting);
				if (!material)
				{
					maxon::String renderer_name;
					switch (setting.import_material_type)
					{
					case CMTToolsSetting::ModelImport::material_type::RedShift: renderer_name = "RedShift"_s; break;
					case CMTToolsSetting::ModelImport::material_type::Octane:   renderer_name = "Octane"_s;   break;
					case CMTToolsSetting::ModelImport::material_type::Corona:   renderer_name = "Corona"_s;   break;
					default: renderer_name = "Standard"_s; break;
					}
					MessageDialog(GeLoadString(IDS_MES_RENDERER_NOT_INSTALLED, renderer_name));
					return false;
				}
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
			if (BaseObject* model_op = static_cast<BaseObject*>(Get()->GetUp()))
				if (MMDModelManagerObject* model_data = model_op->GetNodeData<MMDModelManagerObject>())
					model_data->AddMaterial(pmx_material, material, mesh_object, material_name, material_manager->GetTexturePaths());

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
			mesh_object->InsertUnderLast(Get());

			BaseMaterial* material = nullptr;
			if (setting.import_material)
			{
				material = material_manager->LoadPMXMaterial(pmx_material, material_index, material_name, setting);
				if (!material)
				{
					maxon::String renderer_name;
					switch (setting.import_material_type)
					{
					case CMTToolsSetting::ModelImport::material_type::RedShift: renderer_name = "RedShift"_s; break;
					case CMTToolsSetting::ModelImport::material_type::Octane:   renderer_name = "Octane"_s;   break;
					case CMTToolsSetting::ModelImport::material_type::Corona:   renderer_name = "Corona"_s;   break;
					default: renderer_name = "Standard"_s; break;
					}
					MessageDialog(GeLoadString(IDS_MES_RENDERER_NOT_INSTALLED, renderer_name));
					return false;
				}
				setting.doc->InsertMaterial(material);

				const auto texture_tag = TextureTag::Alloc();
				if (!texture_tag)
					return false;
				texture_tag->SetName(material_name);
				texture_tag->SetMaterial(material);
				texture_tag->SetParameter(ConstDescID(DescLevel(TEXTURETAG_PROJECTION)), TEXTURETAG_PROJECTION_UVW, DESCFLAGS_SET::NONE);
				mesh_object->InsertTag(texture_tag);
			}
			if (BaseObject* model_op = static_cast<BaseObject*>(Get()->GetUp()))
				if (MMDModelManagerObject* model_data = model_op->GetNodeData<MMDModelManagerObject>())
					model_data->AddMaterial(pmx_material, material, mesh_object, ""_s, material_manager->GetTexturePaths());

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
				morph_skin_object->InsertUnderLast(mesh_object);
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
					{
						vertex_index_map.Insert(pmx_surface_vertex_a, part_vertex_count++)iferr_return;
					}

					if (!vertex_index_map.Contains(pmx_surface_vertex_b))
					{
						vertex_index_map.Insert(pmx_surface_vertex_b, part_vertex_count++)iferr_return;
					}

					if (!vertex_index_map.Contains(pmx_surface_vertex_c))
					{
						vertex_index_map.Insert(pmx_surface_vertex_c, part_vertex_count++)iferr_return;
					}
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
				mesh_object_point.x = pmx_vertex_position[0];
				mesh_object_point.y = pmx_vertex_position[1];
				mesh_object_point.z = pmx_vertex_position[2];

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
								Vector(position[0], position[1], position[2]));
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

					uv_morph_names_.Insert(pmx_morph_name)iferr_return;

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

	RefreshMeshMorphData(static_cast<BaseObject*>(Get()));
	return true;
}

Bool MMDMeshManagerObject::SavePMX(libmmd::PMXFile& pmx_file, const CMTToolsSetting::ModelExport& setting)
{
	return false;
}

void MMDMeshManagerObject::RefreshMeshMorphData(BaseObject* op, bool suppress_change_message)
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
			if (const auto morph_tag = node->GetTag(Tposemorph); node->IsInstanceOf(Opolygon) && morph_tag)
			{
				SDK2024_Const auto pose_morph_tag = reinterpret_cast<CAPoseMorphTag*>(morph_tag);
				const auto morph_mode = pose_morph_tag->GetMode();
				const auto morph_count = pose_morph_tag->GetMorphCount();
				for (Int32 morph_index = 1; morph_index < morph_count; morph_index++)
				{
					morph_name_list.Insert(pose_morph_tag->GetMorph(morph_index)->GetName())iferr_return;
				}
				bool mode_change = false;
				if (const auto morph_previous_model_ptr = mesh_morph_mode_.Find(pose_morph_tag); morph_previous_model_ptr != nullptr)
				{
					if (morph_mode == morph_previous_model_ptr->GetValue() || morph_mode == ID_CA_POSE_MODE_EDIT)
					{
						morph_previous_model_ptr->SetValue(morph_mode);
						mode_change = true;
					}
					morph_previous_model_ptr->SetValue(morph_mode);
				}
				else
				{
					mesh_morph_mode_.Insert(morph_tag, morph_mode)iferr_return;
				}
				if (!mode_change)
				{
					for (Int32 index = 1; index < morph_count; index++)
					{
						auto* morph = pose_morph_tag->GetMorph(index);
						String morph_name = morph->GetName();
						DescID morph_id = pose_morph_tag->GetMorphID(index);
						maxon::PointerArray<MorphUIData>* mesh_morph_list;
						if (const auto morph_data_ptr = mesh_morph_name_.Find(morph_name); morph_data_ptr)
						{
							mesh_morph_list = &mesh_morph_data_[morph_data_ptr->GetValue()];
							bool is_find = false;
							for (auto& morph_data : *mesh_morph_list)
							{
								if (morph_data.Compare(pose_morph_tag, morph_id))
									is_find = true;
							}
							if (is_find)
								continue;
						}
						else {
							mesh_morph_list = &mesh_morph_data_.Append().GetValue();
							const auto mesh_morph_data_index = static_cast<Int32>(mesh_morph_data_.GetCount() - 1);
							mesh_morph_name_.Insert(morph_name, mesh_morph_data_index)iferr_return;
						}
						mesh_morph_list->SDK2024_Append(pose_morph_tag, morph_id)iferr_return;
						need_update_morph = true;
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
	if (mesh_morph_name_.GetCount() > morph_name_list.GetCount())
	{
		for (auto it = maxon::Iterable::EraseIterator(mesh_morph_name_); it; ++it)
		{
			if (!morph_name_list.Find(it->GetKey()))
			{
				it.Erase();
				need_update_morph = true;
			}
		}
	}
	if (need_update_morph) {
		if (mmd_morph_manager_)
		{
			const auto morph_count = static_cast<Int>(mmd_morph_manager_->GetMorphCount());
			morph_manager_index_.SetCapacityHint(morph_count)iferr_return;
			for (Int32 index = 0; index < morph_count; index++)
			{
				morph_manager_index_.Append(-1)iferr_return;
			}
			for (const auto &entry : mesh_morph_name_.Begin())
			{
				morph_manager_index_[static_cast<Int32>(mmd_morph_manager_->FindMorphIndex(string_util::GetStdString(entry.GetKey())))] = entry.GetValue();
			}
		}
		if (!suppress_change_message)
		{
			if (auto* model_mgr = io_util::ResolveObjectLink(model_manager_))
			{
				MMDMeshManagerObjectMsg msg{ MMDMeshManagerObjectMsgType::MESH_MORPH_CHANGE };
				model_mgr->Message(g_mmd_mesh_manager_object_id, &msg);
			}
		}
	}
}
