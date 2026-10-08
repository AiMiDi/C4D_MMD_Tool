#pragma once

#include "mmd_material.h"

/** A distinct, versioned MMD-style profile using native RS Toon and Contour. */
class MMDRedShiftToonMaterialAdapter final : public MMDMaterialAdapter
{
public:
	static Bool IsAvailable(String& diagnostic);
	/** Read cached capability only; attribute callbacks must never build a graph. */
	static Bool AvailabilityForUi(String& diagnostic);
	static Bool IsToonMaterial(const BaseMaterial* material);
	static String SupportDiagnostic(const MMDMaterialData& data);

	BaseMaterial* CreateFromPMX(const libmmd::PMXMaterial& material,
		const maxon::BaseArray<Filename>& paths, const maxon::String& name) override;
	BaseMaterial* CreateFromData(const MMDMaterialData& data) override;
	void SyncTo(const MMDMaterialData& data, BaseMaterial* material) override;
	void ReadFrom(const BaseMaterial* material, MMDMaterialData& data) override;
	Bool PrepareMorphBinding(const MMDMaterialData& data, BaseMaterial* material,
		BaseObject* model, BaseObject* mesh, String& diagnostic) override;
	Bool ValidateMorphBinding(BaseMaterial* material, String& diagnostic) const override;
	Bool RepairMorphBinding(const MMDMaterialData& data, BaseMaterial* material,
		BaseObject* model, BaseObject* mesh, String& diagnostic) override;
	Bool UpdateMorphTexture(const MMDMaterialData& previous, const String& path,
		BaseMaterial* material, String& diagnostic) override;
	Bool UpdateToonTexture(const MMDMaterialData& previous, const String& path,
		BaseMaterial* material, String& diagnostic);
	Bool UpdateSphereTexture(const MMDMaterialData& previous, const String& path, Int32 mode,
		BaseMaterial* material, String& diagnostic) override;
private:
	Bool Bind(const MMDMaterialData& data, BaseMaterial* material, BaseObject* model,
		BaseObject* mesh, Bool repair, String& diagnostic);
};
