#include "prefssubstance.h"
#include "lib_substance.h"

static SubstanceLibrary* substance_lib_cache = nullptr;

static SubstanceLibrary* CheckSubstanceLib(Int32 offset)
{
	return (SubstanceLibrary*)CheckLib(ID_SUBSTANCE_LIBRARY, offset, (C4DLibrary**)&substance_lib_cache);
}

SUBSTANCE_IMPORT_RESULT ImportSubstance(BaseDocument* doc, const Filename& fn, SUBSTANCE_IMPORT_COPY& copyFile, Bool errPopup, Bool addUndo, Bool createMaterial, BaseList2D** assetPtr)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, ImportSubstance));
	if (!lib || !lib->ImportSubstance)
		return SUBSTANCE_IMPORT_RESULT::UNKNOWNERROR;
	return lib->ImportSubstance(doc, fn, copyFile, errPopup, addUndo, !createMaterial, assetPtr);
}

Bool AssignChannelToMaterial(BaseList2D* const asset, Material* const c4dMaterial, Int32 channelId, Int32 outputUid, Bool addUndo)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, AssignAssetChannelToMaterial));
	if (!lib || !lib->AssignAssetChannelToMaterial)
		return false;
	return lib->AssignAssetChannelToMaterial(asset, c4dMaterial, channelId, outputUid, addUndo);
}

BaseList2D* GetFirstSubstance(BaseDocument* const doc)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, GetFirstSubstance));
	if (!lib || !lib->GetFirstSubstance)
		return nullptr;
	return lib->GetFirstSubstance(doc);
}

void GetSubstances(BaseDocument* const doc, AtomArray* arr, Bool onlySelected)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, GetSubstances));
	if (!lib || !lib->GetSubstances)
		return;
	lib->GetSubstances(doc, arr, onlySelected);
	return;
}

Bool InsertLastSubstance(BaseDocument* const doc, BaseList2D* asset)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, SubstanceInsertLast));
	if (!lib || !lib->SubstanceInsertLast)
		return false;
	return lib->SubstanceInsertLast(doc, asset);
}

void CloneReferencedSubstances(BaseDocument* const doc, BaseShader* const shd, BaseDocument* const ddoc, BaseShader* const dshd)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, CloneReferencedSubstances));
	if (!lib || !lib->CloneReferencedSubstances)
		return;
	lib->CloneReferencedSubstances(doc, shd, ddoc, dshd);
	return;
}

void CloneReferencedSubstancesObject(BaseDocument* const docSrc, BaseObject* const opSrc, BaseDocument* const docDst, BaseObject* const opDst)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, CloneReferencedSubstancesObject));
	if (!lib || !lib->CloneReferencedSubstancesObject)
		return;
	lib->CloneReferencedSubstancesObject(docSrc, opSrc, docDst, opDst);
}

void InsertSubstancePreviewScene(BaseDocument* const doc, BaseList2D* const asset)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, InsertSubstancePreviewScene));
	if (!lib || !lib->InsertSubstancePreviewScene)
		return;
	lib->InsertSubstancePreviewScene(doc, asset);
	return;
}

void UpdateImageInputPaths(BaseList2D* const asset, String& path)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, UpdateImageInputPaths));
	if (!lib || !lib->UpdateImageInputPaths)
		return;
	lib->UpdateImageInputPaths(asset, path);
	return;
}

BaseBitmap* GetSubstanceMosaicPreview(BaseList2D* const asset, Int32 w, Int32 h)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, GetSubstanceMosaicPreview));
	if (!lib || !lib->GetSubstanceMosaicPreview)
		return nullptr;
	return lib->GetSubstanceMosaicPreview(asset, w, h);
}

SUBSTANCE_MATERIAL_MODE PrefsGetMaterialModeSetting()
{
	SubstanceLibrary* lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, PrefsGetCreateMaterialSetting));
	if (!lib || !lib->PrefsGetCreateMaterialSetting)
		return SUBSTANCE_MATERIAL_MODE::AUTO;
	return lib->PrefsGetCreateMaterialSetting();
}

Int32 PrefsGetPreviewSetting()
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, PrefsGetPreviewSetting));
	if (!lib || !lib->PrefsGetPreviewSetting)
		return PREFS_SUBSTANCE_ENGINE_PREVIEW_MOSAIC;
	return lib->PrefsGetPreviewSetting();
}

BaseMaterial* CreateMaterial(BaseList2D* const asset, Int32 graphIndex, SUBSTANCE_MATERIAL_MODE mode)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, CreateMaterial));
	if (!lib || !lib->CreateMaterial)
		return nullptr;
	if (asset->GetType() != ID_SUBSTANCE_ASSET)
		return nullptr;
	return lib->CreateMaterial(asset, graphIndex, mode);
}

BaseShader* CreateSubstanceShader(BaseList2D* const asset)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, CreateSubstanceShader));
	if (!lib || !lib->CreateSubstanceShader)
		return nullptr;
	if (asset && asset->GetType() != ID_SUBSTANCE_ASSET) // asset may be nullptr, but if it ain't, it has to be a Substance asset
		return nullptr;
	return lib->CreateSubstanceShader(asset);
}

void* GetSubstanceGraph(BaseList2D* const asset, void* const prevGraph, String& name)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, SubstanceGetGraph));
	if (!lib || !lib->SubstanceGetGraph)
		return nullptr;
	if (asset->GetType() != ID_SUBSTANCE_ASSET)
		return nullptr;
	return lib->SubstanceGetGraph(asset, prevGraph, name);
}

void* GetSubstanceInput(BaseList2D* const asset, void* const graph, void* const prevInput, UInt32& inputUid, Int32& firstId, Int32& numElements, SUBSTANCE_INPUT_TYPE& type, String& name)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, SubstanceGetInput));
	if (!lib || !lib->SubstanceGetInput)
		return nullptr;
	if (asset->GetType() != ID_SUBSTANCE_ASSET)
		return nullptr;
	return lib->SubstanceGetInput(asset, graph, prevInput, inputUid, firstId, numElements, type, name);
}

void* GetSubstanceOutput(BaseList2D* const asset, void* const graph, void* const prevOutput, UInt32& outputUid, SUBSTANCE_OUTPUT_TYPE& type, String& name, BaseBitmap** bmpPtr)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, SubstanceGetOutput));
	if (!lib || !lib->SubstanceGetOutput)
		return nullptr;
	if (asset->GetType() != ID_SUBSTANCE_ASSET)
		return nullptr;
	return lib->SubstanceGetOutput(asset, graph, prevOutput, outputUid, (UInt32&)type, name, bmpPtr);
}

Bool MaterialUsesSubstance(BaseMaterial* const mat)
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, MaterialUsesSubstance));
	if (!lib || !lib->MaterialUsesSubstance)
		return false;
	return lib->MaterialUsesSubstance(mat);
}

const BaseBitmap* GetContentBrowserOverlay()
{
	SubstanceLibrary* const lib = CheckSubstanceLib(LIBOFFSET(SubstanceLibrary, GetContentBrowserOverlay));
	if (!lib || !lib->GetContentBrowserOverlay)
		return nullptr;
	return lib->GetContentBrowserOverlay();
}
