// Material/bone/mesh morph runtime dispatch and scene synchronization.
#include "module/core/cmt_old_sdk_stl_preload.h"
#include "mmd_model_manager.h"
#include "mmd_morph.h"
#include "mmd_bone_manager.h"
#include "mmd_mesh_manager.h"
#include "module/tools/tag/mmd_bone.h"
#include "utils/cmt_material_morph_accumulator.hpp"
#include "utils/cmt_runtime_profile.hpp"

#include <cstring>
#include "utils/cmt_morph_evaluation.hpp"
#include "module/tools/material/mmd_material_morph_binding.h"
#include "module/tools/material/mmd_redshift_toon_material.h"
#include "plugin_resource.h"

namespace
{
	void RecordMaterialBindingUndo(BaseDocument* doc, BaseMaterial* material)
	{
		// One document transaction owns metadata and the complete shader/node
		// hierarchy. Redshift graph transactions suppress automatic graph undo;
		// mixing that with material snapshots splits multi-material Undo/Redo.
		doc->AddUndo(UNDOTYPE::CHANGE, material);
	}

	UInt64 MixBoneMorphState(const UInt64 hash, const UInt64 value)
	{
		return (hash ^ value) * 1099511628211ULL;
	}

	UInt64 HashBoneMorphValue(const UInt64 hash, const Float64 value)
	{
		static_assert(sizeof(Float64) == sizeof(UInt64), "Bone morph checksum expects 64-bit Float64");
		const Float64 normalized = value == 0. ? 0. : value;
		UInt64 bits = 0;
		std::memcpy(&bits, &normalized, sizeof(bits));
		return MixBoneMorphState(hash, bits);
	}
}

UInt64 MMDModelManagerObject::GetBoneMorphStateChecksum() const
{
	UInt64 checksum = 14695981039346656037ULL;
	UInt64 morph_count = 0;
	if (!bone_manager_data_)
		return checksum;

	// Read effective tag parameters after group/flip expansion. Checking definitions
	// as well as strength also catches direct tag edits at an unchanged document time.
	// Sum per-bone hashes so HashMap iteration order does not require a per-frame sort.
	for (const auto& entry : bone_manager_data_->bone_list_)
	{
		BaseTag* const tag = bone_manager_data_->FindBone(static_cast<Int32>(entry.GetKey()));
		const auto* const bone = tag ? tag->GetNodeData<MMDBoneTag>() : nullptr;
		if (!bone || bone->bone_morph_data_arr_.IsEmpty())
			continue;

		UInt64 bone_hash = MixBoneMorphState(14695981039346656037ULL, static_cast<UInt64>(entry.GetKey()));
		bone_hash = MixBoneMorphState(bone_hash, static_cast<UInt64>(bone->bone_morph_data_arr_.GetCount()));
		for (const auto& morph : bone->bone_morph_data_arr_)
		{
			GeData value;
			const Bool has_strength = tag->GetParameter(morph.strength_id, value, DESCFLAGS_GET::NONE);
			bone_hash = MixBoneMorphState(bone_hash, has_strength);
			bone_hash = HashBoneMorphValue(bone_hash, has_strength ? value.GetFloat() : 0.);
			for (const DescID* const id : { &morph.translation_id, &morph.rotation_id })
			{
				const Bool has_offset = tag->GetParameter(*id, value, DESCFLAGS_GET::NONE);
				const Vector offset = has_offset ? value.GetVector() : Vector();
				bone_hash = MixBoneMorphState(bone_hash, has_offset);
				bone_hash = HashBoneMorphValue(bone_hash, offset.x);
				bone_hash = HashBoneMorphValue(bone_hash, offset.y);
				bone_hash = HashBoneMorphValue(bone_hash, offset.z);
			}
			++morph_count;
		}
		checksum += bone_hash;
	}
	return MixBoneMorphState(checksum, morph_count);
}

void MMDModelManagerObject::ApplyMorphRuntimeStrengths()
{
	cmt_runtime::ScopedRuntimeStage stage(cmt_runtime::RuntimeStage::Morph);
	GeListNode* const node = Get();
	const Int morph_count = morph_data_.GetCount();
	if (!node)
		return;
	if (morph_count <= 0)
	{
		EvaluateMaterialMorphRuntime({});
		return;
	}

	BaseDocument* doc = node->GetDocument();
	const std::vector<Float> strengths = EvaluateMorphWeights(doc ? doc->GetTime() : BaseTime(), false, false);

	for (Int i = 0; i < morph_count; ++i)
	{
		const MMDMorphType type = morph_data_[i].GetType();
		if (type == MMDMorphType::GROUP || type == MMDMorphType::FLIP)
			continue;
		ApplyMorphRuntimeStrength(morph_data_[i], strengths[static_cast<size_t>(i)]);
	}

	EvaluateMaterialMorphRuntime(strengths);
}

std::vector<Float> MMDModelManagerObject::EvaluateMorphWeights(const BaseTime& time,
	const Bool preview, const Bool sample_tracks, Bool* cyclic)
{
	BaseObject* const object = static_cast<BaseObject*>(Get());
	std::vector<cmt_runtime::MorphNode> graph(static_cast<size_t>(morph_data_.GetCount()));
	std::vector<double> input(graph.size(), 0.0);
	for (Int i = 0; i < morph_data_.GetCount(); ++i)
	{
		IMorph& morph = morph_data_[i];
		if (preview)
		{
			const auto value = material_preview_weights_.find(morph.GetRuntimeIdentity());
			if (material_preview_enabled_ && value != material_preview_weights_.end()) input[i] = value->second;
		}
		else if (object)
		{
			input[i] = morph.GetStrength(object);
			if (sample_tracks)
				if (CTrack* track = object->FindCTrack(morph.GetStrengthDescID()))
					input[i] = track->GetValue(object->GetDocument(), time);
		}
		auto& node = graph[i];
		if (morph.GetType() == MMDMorphType::GROUP) node.kind = cmt_runtime::MorphKind::Group;
		if (morph.GetType() == MMDMorphType::FLIP) node.kind = cmt_runtime::MorphKind::Flip;
		if (auto* children = morph.GetSubMorphDataWritable())
		{
			for (const auto& child : *children)
				node.children.emplace_back(static_cast<size_t>(child.GetKey()), child.GetValue());
			std::sort(node.children.begin(), node.children.end());
		}
	}
	const auto expanded = cmt_runtime::ExpandMorphWeights(graph, input);
	if (cyclic) *cyclic = expanded.cyclic || expanded.invalid;
	return std::vector<Float>(expanded.values.begin(), expanded.values.end());
}

std::vector<MMDMaterialRuntimeState> MMDModelManagerObject::EvaluateMaterialMorphs(const std::vector<Float>& strengths) const
{
	using Accumulator = cmt_runtime::MaterialMorphAccumulator<Vector, Float>;
	std::vector<Accumulator> accumulators(static_cast<size_t>(material_list_.GetCount()));
	for (Int i = 0; i < morph_data_.GetCount() && i < static_cast<Int>(strengths.size()); ++i)
	{
		if (morph_data_[i].GetType() != MMDMorphType::MATERIAL || strengths[i] == 0.0) continue;
		for (const auto& offset : static_cast<const MaterialMorph&>(morph_data_[i]).GetOffsets())
		{
			if (offset.material_index == -1)
				for (auto& accumulator : accumulators) accumulator.Apply(offset, strengths[i]);
			else if (offset.material_index >= 0 && offset.material_index < material_list_.GetCount())
				accumulators[offset.material_index].Apply(offset, strengths[i]);
		}
	}
	std::vector<MMDMaterialRuntimeState> states;
	states.reserve(accumulators.size());
	for (Int i = 0; i < material_list_.GetCount(); ++i)
		states.push_back(accumulators[i].Compose(MMDMaterialRuntimeState::FromBase(material_list_[i])));
	return states;
}

Bool MMDModelManagerObject::GetMaterialRenderState(BaseMaterial* material, const BaseTime& time, MMDMaterialRuntimeState& state)
{
	BaseObject* const object = static_cast<BaseObject*>(Get());
	if (!object || !mmd_material_binding::IsOwner(material, object, object->GetDocument())) return false;
	if (!HasUniqueMaterialBinding(material)) return false;
	auto adapter = MMDMaterialAdapter::CreateFor(material);
	String diagnostic;
	if (!adapter || !adapter->ValidateMorphBinding(material, diagnostic)) return false;
	Int selected = NOTOK;
	for (Int i = 0; i < material_list_.GetCount(); ++i)
	{
		const auto& base = material_list_[i];
		if (base.material_link && *base.material_link && (*base.material_link)->GetLink(object->GetDocument()) == material)
		{
			if (selected != NOTOK) return false; // Two PMX entries must not race on a single binding.
			selected = i;
		}
	}
	if (selected == NOTOK) return false;
	const Bool edit = model_mode_ == MODEL_MODE_EDIT;
	const auto weights = EvaluateMorphWeights(time, edit, !edit);
	const auto states = EvaluateMaterialMorphs(weights);
	state = states[selected];
	return true;
}

Bool MMDModelManagerObject::HasUniqueMaterialBinding(BaseMaterial* material) const
{
	// R20 exposes the read-only traversal methods without const qualifiers.
	BaseDocument* doc = Get() ? const_cast<BaseDocument*>(Get()->GetDocument()) : nullptr;
	if (!doc || !material) return false;
	Int count = 0;
	std::vector<BaseObject*> pending;
	if (BaseObject* first = doc->GetFirstObject()) pending.push_back(first);
	while (!pending.empty())
	{
		BaseObject* object = pending.back();
		pending.pop_back();
		if (object->GetNext()) pending.push_back(object->GetNext());
		if (object->GetDown()) pending.push_back(object->GetDown());
		if (!object->IsInstanceOf(g_mmd_model_manager_object_id)) continue;
		const auto* model = object->GetNodeData<MMDModelManagerObject>();
		if (!model) continue;
		for (const auto& base : model->material_list_)
			if (base.material_link && *base.material_link && (*base.material_link)->GetLink(doc) == material)
				if (++count > 1) return false;
	}
	return count == 1;
}

Bool MMDModelManagerObject::PrepareMaterialMorphBindings(const Bool record_undo)
{
	using namespace mmd_material_binding;
	BaseObject* const object = static_cast<BaseObject*>(Get());
	BaseDocument* const doc = object ? object->GetDocument() : nullptr;
	if (!doc || !GeIsMainThread()) return false;
	Bool success = true;
	String first_error;
	if (record_undo) doc->StartUndo();
	for (auto& base : material_list_)
	{
		BaseMaterial* material = base.material_link && *base.material_link
			? static_cast<BaseMaterial*>((*base.material_link)->GetLink(doc)) : nullptr;
		BaseObject* mesh = base.mesh_link && *base.mesh_link
			? static_cast<BaseObject*>((*base.mesh_link)->GetLink(doc)) : nullptr;
		if (!material) continue;
		if (!HasUniqueMaterialBinding(material))
		{
			material_binding_diagnostic_ = "Several model entries share this material; create an independent material"_s;
			if (first_error.IsEmpty()) first_error = material_binding_diagnostic_;
			success = false;
			continue;
		}
		auto adapter = MMDMaterialAdapter::CreateFor(material);
		const auto type = MMDMaterialAdapter::DetectType(material);
		if (!adapter || (type != MMDRendererMaterialType::Standard && type != MMDRendererMaterialType::RedShift
			&& type != MMDRendererMaterialType::RedShiftToon)) continue;
		if (IsBound(material))
		{
			if (!IsOwner(material, object, doc))
			{
				material_binding_diagnostic_ = "Material belongs to another model; create an independent material"_s;
				success = false;
			}
			else if (Metadata(material).GetInt32(Version) < CurrentVersion)
			{
				if (record_undo)
				{
					RecordMaterialBindingUndo(doc, material);
					if (mesh) doc->AddUndo(UNDOTYPE::CHANGE_SMALL, mesh);
				}
				if (!adapter->RepairMorphBinding(base, material, object, mesh, material_binding_diagnostic_)) success = false;
			}
			else if (!adapter->ValidateMorphBinding(material, material_binding_diagnostic_)) success = false;
			if (!success && first_error.IsEmpty()) first_error = material_binding_diagnostic_;
			continue;
		}
		if (record_undo)
		{
			RecordMaterialBindingUndo(doc, material);
			if (mesh) doc->AddUndo(UNDOTYPE::CHANGE_SMALL, mesh);
		}
		if (!adapter->PrepareMorphBinding(base, material, object, mesh, material_binding_diagnostic_))
		{
			success = false;
			if (first_error.IsEmpty()) first_error = material_binding_diagnostic_;
		}
	}
	if (record_undo) doc->EndUndo();
	if (!first_error.IsEmpty()) material_binding_diagnostic_ = first_error;
	material_runtime_checksum_.Reset();
	return success;
}

void MMDModelManagerObject::EvaluateMaterialMorphRuntime(const std::vector<Float>& strengths)
{
	cmt_runtime::ScopedRuntimeStage stage(cmt_runtime::RuntimeStage::MaterialSync);
	BaseObject* const object = static_cast<BaseObject*>(Get());
	BaseDocument* const doc = object ? object->GetDocument() : nullptr;
	if (!doc) return;
	Bool has_morph = false;
	for (const auto& morph : morph_data_)
		if (morph.GetType() == MMDMorphType::MATERIAL && static_cast<const MaterialMorph&>(morph).GetOffsetCount() > 0)
			has_morph = true;
	const auto effective = model_mode_ == MODEL_MODE_EDIT
		? EvaluateMorphWeights(doc->GetTime(), true, false) : strengths;
	const auto states = EvaluateMaterialMorphs(effective);
	Bool legacy_sync_complete = true;
	String first_binding_error;
	String selected_toon_support;
	const auto record_error = [&](BaseMaterial* material, const String& reason)
	{
		if (first_binding_error.IsEmpty())
			first_binding_error = material->GetName() + String(": ") + reason;
	};
	if (material_runtime_checksum_.GetCount() != material_list_.GetCount())
	{
		iferr(material_runtime_checksum_.Resize(material_list_.GetCount())) return;
		for (auto& checksum : material_runtime_checksum_) checksum = 0;
	}
	for (Int i = 0; i < material_list_.GetCount(); ++i)
	{
		const auto& base = material_list_[i];
		BaseMaterial* material = base.material_link && *base.material_link
			? static_cast<BaseMaterial*>((*base.material_link)->GetLink(doc)) : nullptr;
		if (!material) { legacy_sync_complete = false; continue; }
		if (mmd_material_binding::IsBound(material))
		{
			if (!mmd_material_binding::IsOwner(material, object, doc) || !HasUniqueMaterialBinding(material))
			{ record_error(material, "Material is owned by a different model; create an independent material"_s); continue; }
			auto adapter = MMDMaterialAdapter::CreateFor(material);
			String diagnostic;
			if (!adapter || !adapter->ValidateMorphBinding(material, diagnostic))
			{
				record_error(material, diagnostic.IsPopulated() ? diagnostic : String("Material binding could not be validated"));
				continue;
			}
			const auto type = MMDMaterialAdapter::DetectType(material);
			if (type == MMDRendererMaterialType::RedShiftToon && i == material_selection_index_)
				selected_toon_support = diagnostic;
			if (type == MMDRendererMaterialType::RedShift || type == MMDRendererMaterialType::RedShiftToon)
			{
				BaseObject* mesh = base.mesh_link && *base.mesh_link ? static_cast<BaseObject*>((*base.mesh_link)->GetLink(doc)) : nullptr;
				if (!mmd_material_binding::PublishUserData(mesh, material, states[i]))
				{ record_error(material, "Material User Data binding is missing; repair the binding"_s); continue; }
			}
			// Standard reads its own render-document snapshot in InitRender. No
			// shader parameters or graph structures are changed by this pass.
			continue;
		}
		// Legacy materials retain their explicit-upgrade boundary. Restrict their
		// old parameter-writing path to main-thread evaluation.
		if (!GeIsMainThread()) { legacy_sync_complete = false; continue; }
		if (!has_morph && !material_morph_runtime_active_) continue;
		const auto checksum = states[i].Checksum();
		if (material_runtime_checksum_[i] == checksum) continue;
		MMDMaterialData synced;
		if (!base.CopyTo(synced)) { legacy_sync_complete = false; continue; }
		states[i].WriteSupportedFieldsTo(synced);
		SyncToMaterial(synced, material);
		SyncRuntimeStateToMaterial(states[i], material);
		material_runtime_checksum_[i] = checksum;
	}
	// A valid later material must not hide a broken graph or owner conflict.
	if (first_binding_error.IsPopulated()) material_binding_diagnostic_ = first_binding_error;
	else if (selected_toon_support.IsPopulated()) material_binding_diagnostic_ = selected_toon_support;
	// A worker-thread pass cannot restore a legacy scene. Retain the pending
	// restoration until a main-thread pass has actually written its base state.
	if (has_morph) material_morph_runtime_active_ = true;
	else if (legacy_sync_complete) material_morph_runtime_active_ = false;
}

void MMDModelManagerObject::ApplyMorphRuntimeStrength(IMorph& morph, const Float strength)
{
	switch (morph.GetType())
	{
	case MMDMorphType::MESH:
	case MMDMorphType::UV:
		if (mesh_manager_data_ || GetMeshManagerData())
			mesh_manager_data_->SetMorphStrength(morph.GetName(), strength);
		break;
	case MMDMorphType::BONE:
	{
		if (!(bone_manager_data_ || GetBoneManagerData()))
			break;
		auto& bone_morph_map = bone_manager_data_->GetBoneMorphMap();
		if (auto* entry = bone_morph_map.Find(morph.GetName()))
		{
			for (const auto& hub : entry->GetValue())
			{
				const Float previous_strength = hub.GetStrength();
				if (previous_strength != strength)
				{
					hub.SetStrength(strength);
					if (hub.GetStrength() != previous_strength)
						bone_morph_pose_dirty_ = true;
				}
			}
		}
		break;
	}
	default:
		break;
	}
}

Bool MMDModelManagerObject::IsMaterialPreviewMorph(const Int32 index) const
{
	if (index < 0 || index >= morph_data_.GetCount()) return false;
	const auto type = morph_data_[index].GetType();
	return type == MMDMorphType::MATERIAL || type == MMDMorphType::GROUP || type == MMDMorphType::FLIP;
}

Float MMDModelManagerObject::GetMaterialPreviewWeight() const
{
	if (!IsMaterialPreviewMorph(material_preview_selection_)) return 0.0;
	const auto entry = material_preview_weights_.find(morph_data_[material_preview_selection_].GetRuntimeIdentity());
	return entry == material_preview_weights_.end() ? 0.0 : entry->second;
}

void MMDModelManagerObject::RefreshMaterialMorphPreview()
{
	BaseDocument* doc = Get() ? Get()->GetDocument() : nullptr;
	if (!doc || !GeIsMainThread()) return;
	Bool invalid_graph = false;
	const auto weights = EvaluateMorphWeights(doc->GetTime(), model_mode_ == MODEL_MODE_EDIT, false, &invalid_graph);
	const String graph_error("Morph contains a cycle or invalid reference; invalid paths are skipped");
	if (invalid_graph) material_binding_diagnostic_ = graph_error;
	else if (material_binding_diagnostic_ == graph_error) material_binding_diagnostic_ = String();
	EvaluateMaterialMorphRuntime(weights);
	// Same-frame edits must invalidate native shader previews. Scene structure
	// remains fixed; this helper is invoked only by main-thread authoring actions.
	for (const auto& base : material_list_)
	{
		BaseMaterial* material = base.material_link && *base.material_link
			? static_cast<BaseMaterial*>((*base.material_link)->GetLink(doc)) : nullptr;
		if (!material || !mmd_material_binding::IsOwner(material, static_cast<BaseObject*>(Get()), doc)) continue;
		material->SetDirty(DIRTYFLAGS::DATA);
		for (BaseShader* shader = material->GetFirstShader(); shader; shader = shader->GetNext())
			if (shader->IsInstanceOf(g_mmd_material_texture_morph_shader_id)) shader->SetDirty(DIRTYFLAGS::DATA);
		material->Message(MSG_UPDATE);
	}
	Get()->SetDirty(DIRTYFLAGS::DATA);
	EventAdd();
}

Bool MMDModelManagerObject::UpdateSelectedMaterialTexture(const String& path)
{
	BaseObject* object = static_cast<BaseObject*>(Get());
	BaseDocument* doc = object ? object->GetDocument() : nullptr;
	if (!doc || !GeIsMainThread() || material_selection_index_ < 0 || material_selection_index_ >= material_list_.GetCount()) return false;
	auto& base = material_list_[material_selection_index_];
	if (base.texture_path == path) return true;
	BaseMaterial* material = base.material_link && *base.material_link
		? static_cast<BaseMaterial*>((*base.material_link)->GetLink(doc)) : nullptr;
	if (material && mmd_material_binding::IsBound(material))
	{
		if (!HasUniqueMaterialBinding(material) || !mmd_material_binding::IsOwner(material, object, doc))
		{ material_binding_diagnostic_ = "Binding is shared or belongs to another model; create an independent material"_s; return false; }
		auto adapter = MMDMaterialAdapter::CreateFor(material);
		if (!adapter || !adapter->ValidateMorphBinding(material, material_binding_diagnostic_)) return false;
		// Join the parameter editor's undo transaction. Script callers, as with
		// other SetParameter operations, must open an undo block and record model.
		RecordMaterialBindingUndo(doc, material);
		if (!adapter->UpdateMorphTexture(base, path, material, material_binding_diagnostic_)) return false;
	}
	base.texture_path = path;
	return true;
}

Bool MMDModelManagerObject::RepairSelectedMaterialBinding()
{
	BaseObject* object = static_cast<BaseObject*>(Get());
	BaseDocument* doc = object ? object->GetDocument() : nullptr;
	if (!doc || !GeIsMainThread() || material_selection_index_ < 0 || material_selection_index_ >= material_list_.GetCount()) return false;
	const auto& base = material_list_[material_selection_index_];
	BaseMaterial* material = base.material_link && *base.material_link ? static_cast<BaseMaterial*>((*base.material_link)->GetLink(doc)) : nullptr;
	BaseObject* mesh = base.mesh_link && *base.mesh_link ? static_cast<BaseObject*>((*base.mesh_link)->GetLink(doc)) : nullptr;
	if (!material || !HasUniqueMaterialBinding(material) || !mmd_material_binding::IsOwner(material, object, doc))
	{ material_binding_diagnostic_ = "Binding is shared or belongs to another model; create an independent material"_s; return false; }
	auto adapter = MMDMaterialAdapter::CreateFor(material);
	if (!adapter) return false;
	doc->StartUndo();
	RecordMaterialBindingUndo(doc, material);
	if (mesh) doc->AddUndo(UNDOTYPE::CHANGE_SMALL, mesh);
	const Bool result = adapter->RepairMorphBinding(base, material, object, mesh, material_binding_diagnostic_);
	doc->EndUndo();
	return result;
}

Bool MMDModelManagerObject::CreateIndependentMaterialBinding()
{
	BaseObject* object = static_cast<BaseObject*>(Get());
	BaseDocument* doc = object ? object->GetDocument() : nullptr;
	if (!doc || !GeIsMainThread() || material_selection_index_ < 0 || material_selection_index_ >= material_list_.GetCount()) return false;
	auto& base = material_list_[material_selection_index_];
	BaseMaterial* previous = base.material_link && *base.material_link ? static_cast<BaseMaterial*>((*base.material_link)->GetLink(doc)) : nullptr;
	BaseObject* mesh = base.mesh_link && *base.mesh_link ? static_cast<BaseObject*>((*base.mesh_link)->GetLink(doc)) : nullptr;
	if (!previous || !mesh) return false;
	auto adapter = MMDMaterialAdapter::CreateFor(previous);
	if (!adapter) return false;
	BaseMaterial* material = adapter->CreateFromData(base);
	if (!material) return false;
	doc->StartUndo();
	doc->AddUndo(UNDOTYPE::CHANGE, object);
	doc->AddUndo(UNDOTYPE::CHANGE_SMALL, mesh);
	doc->InsertMaterial(material);
	(*base.material_link)->SetLink(material);
	if (!adapter->PrepareMorphBinding(base, material, object, mesh, material_binding_diagnostic_))
	{
		(*base.material_link)->SetLink(previous);
		material->Remove();
		BaseMaterial::Free(material);
		doc->EndUndo();
		return false;
	}
	doc->AddUndo(UNDOTYPE::NEWOBJ, material);
	for (BaseTag* tag = mesh->GetFirstTag(); tag; tag = tag->GetNext())
	{
		if (!tag->IsInstanceOf(Ttexture)) continue;
		GeData link, restriction;
		tag->GetParameter(ConstDescID(DescLevel(TEXTURETAG_MATERIAL)), link, DESCFLAGS_GET::NONE);
		tag->GetParameter(ConstDescID(DescLevel(TEXTURETAG_RESTRICTION)), restriction, DESCFLAGS_GET::NONE);
		if (link.GetLink(doc) != previous || restriction.GetString() != base.selection_name) continue;
		doc->AddUndo(UNDOTYPE::CHANGE, tag);
		tag->SetParameter(ConstDescID(DescLevel(TEXTURETAG_MATERIAL)), material, DESCFLAGS_SET::NONE);
	}
	doc->EndUndo();
	material_runtime_checksum_.Reset();
	return true;
}
