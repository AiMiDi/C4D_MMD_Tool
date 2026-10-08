#include "module/core/cmt_old_sdk_stl_preload.h"
#include "mmd_model_manager.h"
#include "module/tools/material/mmd_material_morph_binding.h"
#include "module/tools/material/mmd_redshift_toon_material.h"
#include "plugin_resource.h"
#include "module/tools/material/mmd_toon_regression.hpp"

namespace
{
Bool IsModelMesh(BaseObject* mesh, BaseObject* model)
{
	if (!mesh || !mesh->IsInstanceOf(Opolygon)) return false;
	for (BaseObject* parent = mesh; parent; parent = parent->GetUp())
		if (parent->IsInstanceOf(model->GetType())) return parent == model;
	return false;
}
}

Bool MMDModelManagerObject::ConvertSelectedMaterialToon()
{
	BaseObject* const object = static_cast<BaseObject*>(Get());
	BaseDocument* const doc = object ? object->GetDocument() : nullptr;
	if (!doc || !GeIsMainThread()) return false;
	if (model_mode_ != MODEL_MODE_EDIT || material_preview_enabled_)
	{ material_binding_diagnostic_ = "Convert in EDIT mode with material preview disabled"_s; return false; }
	if (material_selection_index_ < 0 || material_selection_index_ >= material_list_.GetCount()) return false;
	if (!MMDRedShiftToonMaterialAdapter::IsAvailable(material_binding_diagnostic_)) return false;
	auto& base = material_list_[material_selection_index_];
	BaseMaterial* const previous = base.material_link && *base.material_link
		? static_cast<BaseMaterial*>((*base.material_link)->GetLink(doc)) : nullptr;
	BaseObject* const mesh = base.mesh_link && *base.mesh_link
		? static_cast<BaseObject*>((*base.mesh_link)->GetLink(doc)) : nullptr;
	if (!previous || previous->GetDocument() != doc || !mesh || mesh->GetDocument() != doc || !IsModelMesh(mesh, object))
	{ material_binding_diagnostic_ = "Conversion requires a live material and a mesh owned by this model"_s; return false; }
	for (Int index = 0; index < material_list_.GetCount(); ++index)
	{
		if (index == material_selection_index_) continue;
		const auto& other = material_list_[index];
		if (other.mesh_link && *other.mesh_link && (*other.mesh_link)->GetLink(doc) == mesh
			&& other.selection_name == base.selection_name && other.material_link && *other.material_link
			&& (*other.material_link)->GetLink(doc) == previous)
		{ material_binding_diagnostic_ = "Several entries identify the same mesh assignment; resolve the ambiguity before conversion"_s; return false; }
	}
	if (base.selection_name.IsPopulated())
	{
		Int matches = 0;
		Bool populated = false;
		for (BaseTag* tag = mesh->GetFirstTag(); tag; tag = tag->GetNext())
		{
			if (!tag->IsInstanceOf(Tpolygonselection) || tag->GetName() != base.selection_name) continue;
			++matches;
			populated = static_cast<SelectionTag*>(tag)->GetBaseSelect()->GetCount() > 0;
		}
		if (matches != 1 || !populated)
		{
			material_binding_diagnostic_ = "Conversion requires one nonempty polygon selection matching this entry"_s;
			return false;
		}
	}
	std::vector<BaseTag*> assignments;
	for (BaseTag* tag = mesh->GetFirstTag(); tag; tag = tag->GetNext())
	{
		if (!tag->IsInstanceOf(Ttexture)) continue;
		GeData link, restriction;
		if (!tag->GetParameter(ConstDescID(DescLevel(TEXTURETAG_MATERIAL)), link, DESCFLAGS_GET::NONE)
			|| !tag->GetParameter(ConstDescID(DescLevel(TEXTURETAG_RESTRICTION)), restriction, DESCFLAGS_GET::NONE)) return false;
		if (link.GetLink(doc) == previous && restriction.GetString() == base.selection_name)
			assignments.push_back(tag);
	}
	if (assignments.empty())
	{ material_binding_diagnostic_ = "No matching mesh/selection assignment was found; the source material was preserved"_s; return false; }

	MMDRedShiftToonMaterialAdapter adapter;
	AutoAlloc<BaseLink> model_link;
	if (!model_link) { material_binding_diagnostic_ = "Could not allocate conversion rollback identity"_s; return false; }
	model_link->SetLink(object);
	const auto reportAfterUndo = [&model_link, doc](const String& reason)
	{
		// Undo restores the node's plugin data. Publish on the restored instance,
		// rather than the instance that started the conversion transaction.
		if (auto* current = static_cast<BaseObject*>(model_link->GetLink(doc, g_mmd_model_manager_object_id)))
			if (auto* restored = current->GetNodeData<MMDModelManagerObject>())
				restored->material_binding_diagnostic_ = reason;
	};
	BaseMaterial* material = adapter.CreateFromData(base);
	if (!material) { material_binding_diagnostic_ = "RS Toon candidate construction failed"_s; return false; }
	doc->StartUndo();
	doc->AddUndo(UNDOTYPE::CHANGE, object);
	doc->AddUndo(UNDOTYPE::CHANGE, mesh);
	doc->InsertMaterial(material);
	if (!adapter.PrepareMorphBinding(base, material, object, mesh, material_binding_diagnostic_))
	{
		const String failure = material_binding_diagnostic_;
		material->Remove();
		BaseMaterial::Free(material);
		doc->EndUndo();
		// Restore the complete mesh snapshot too, including any dynamic-description
		// side effects of a failed attribute allocation. The candidate is detached.
		doc->DoUndo();
		reportAfterUndo(failure);
		return false;
	}
	doc->AddUndo(UNDOTYPE::NEWOBJ, material);
	const auto rollback = [&](const String& reason) -> Bool
	{
		doc->EndUndo();
		doc->DoUndo();
		reportAfterUndo(reason);
		return false;
	};
	if (mmd_toon_regression::Injected(object, mmd_toon_regression::Fault::AfterBinding))
		return rollback("Injected Toon conversion failure after binding"_s);
	for (BaseTag* tag : assignments)
	{
		doc->AddUndo(UNDOTYPE::CHANGE, tag);
		if (!tag->SetParameter(ConstDescID(DescLevel(TEXTURETAG_MATERIAL)), material, DESCFLAGS_SET::NONE))
		{
			doc->EndUndo();
			doc->DoUndo();
			reportAfterUndo("RS Toon assignment failed; conversion was rolled back"_s);
			return false;
		}
		if (mmd_toon_regression::Injected(object, mmd_toon_regression::Fault::AfterAssignment))
			return rollback("Injected Toon conversion failure after assignment"_s);
	}
	(*base.material_link)->SetLink(material);
	if (mmd_toon_regression::Injected(object, mmd_toon_regression::Fault::AfterLink))
		return rollback("Injected Toon conversion failure after link update"_s);
	if (!adapter.ValidateMorphBinding(material, material_binding_diagnostic_))
	{
		const String failure = material_binding_diagnostic_;
		doc->EndUndo();
		doc->DoUndo();
		reportAfterUndo(failure);
		return false;
	}
	doc->EndUndo();
	material_runtime_checksum_.Reset();
	RefreshMaterialMorphPreview();
	object->SetDirty(DIRTYFLAGS::DATA);
	EventAdd();
	return true;
}

Bool MMDModelManagerObject::UpdateSelectedMaterialToon(const Int32 mode, const Int32 index, const String& path)
{
	BaseObject* const object = static_cast<BaseObject*>(Get());
	BaseDocument* const doc = object ? object->GetDocument() : nullptr;
	if (!doc || !GeIsMainThread() || material_selection_index_ < 0 || material_selection_index_ >= material_list_.GetCount()) return false;
	if (mode < 0 || mode > 1 || index < -1 || (mode == 1 && index > 9))
	{ material_binding_diagnostic_ = "Invalid Toon mode or shared texture index"_s; return false; }
	auto& base = material_list_[material_selection_index_];
	String resolved = path;
	if (mode == 1)
	{
		resolved = String();
		if (index >= 0)
		{
			const String number = index < 9 ? String("0") + String::IntToString(index + 1) : String("10");
			resolved = (GeGetPluginResourcePath() + Filename("mikumikudance_data")
				+ Filename(String("toon") + number + String(".bmp"))).GetString();
		}
	}
	BaseMaterial* material = base.material_link && *base.material_link
		? static_cast<BaseMaterial*>((*base.material_link)->GetLink(doc)) : nullptr;
	if (MMDRedShiftToonMaterialAdapter::IsToonMaterial(material) && base.toon_texture_path != resolved)
	{
		if (!HasUniqueMaterialBinding(material) || !mmd_material_binding::IsOwner(material, object, doc))
		{ material_binding_diagnostic_ = "Material binding is shared or unbound; convert to an independent material"_s; return false; }
		MMDRedShiftToonMaterialAdapter adapter;
		doc->AddUndo(UNDOTYPE::CHANGE, material);
		if (!adapter.UpdateToonTexture(base, resolved, material, material_binding_diagnostic_)) return false;
	}
	base.toon_mode = mode;
	base.toon_texture_index = index;
	base.toon_texture_path = resolved;
	return true;
}

Bool MMDModelManagerObject::UpdateSelectedMaterialSphere(const Int32 mode, const String& path)
{
	BaseObject* const object = static_cast<BaseObject*>(Get());
	BaseDocument* const doc = object ? object->GetDocument() : nullptr;
	if (!doc || !GeIsMainThread() || material_selection_index_ < 0 || material_selection_index_ >= material_list_.GetCount()) return false;
	if (mode < 0 || mode > 3)
	{ material_binding_diagnostic_ = "Invalid sphere texture mode"_s; return false; }
	auto& base = material_list_[material_selection_index_];
	BaseMaterial* material = base.material_link && *base.material_link
		? static_cast<BaseMaterial*>((*base.material_link)->GetLink(doc)) : nullptr;
	const auto renderer = MMDMaterialAdapter::DetectType(material);
	if ((renderer == MMDRendererMaterialType::Standard || renderer == MMDRendererMaterialType::RedShift
		|| renderer == MMDRendererMaterialType::RedShiftToon)
		&& (base.sphere_texture_path != path || base.sphere_mode != mode))
	{
		if (!HasUniqueMaterialBinding(material) || !mmd_material_binding::IsOwner(material, object, doc))
		{ material_binding_diagnostic_ = "Material binding is shared or unbound; convert to an independent material"_s; return false; }
		auto adapter = MMDMaterialAdapter::CreateFor(material);
		if (!adapter) return false;
		doc->AddUndo(UNDOTYPE::CHANGE, material);
		if (!adapter->UpdateSphereTexture(base, path, mode, material, material_binding_diagnostic_)) return false;
	}
	base.sphere_mode = mode;
	base.sphere_texture_path = path;
	return true;
}
