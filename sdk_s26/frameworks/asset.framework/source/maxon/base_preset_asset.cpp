#include "maxon/datadescriptiondefinition.h"
#include "maxon/datadescription_string.h"
#include "base_preset_asset.h"

namespace maxon
{

PresetLoadArgs::PresetLoadArgs()
{
}

PresetLoadArgs::PresetLoadArgs(const PresetLoadArgs& src) : DataDictionary(src)
{
}

Result<void> PresetLoadArgs::SetPointer(void* pointer)
{
	iferr_scope;
	Set(0, pointer) iferr_return;
	return OK;
}

void* PresetLoadArgs::GetPointer() const
{
	ifnoerr (void* ptr = Get<void*>(0))
		return ptr;
	DebugStop();
	return nullptr;
}

Result<void> PresetLoadArgs::SetType(Int type)
{
	iferr_scope;
	Set(1, type) iferr_return;
	return OK;
}

Int PresetLoadArgs::GetType() const
{
	ifnoerr (Int ptr = Get<Int>(1))
		return ptr;
	DebugStop();
	return 0;
}

PresetSaveArgs::PresetSaveArgs(const PresetSaveArgs& src) : DataDictionary(src)
{
}

PresetSaveArgs::PresetSaveArgs(void* rawptr, Int type)
{
	Set(0, rawptr) iferr_ignore();
	Set(1, type) iferr_ignore();
}


void* PresetSaveArgs::GetPointer() const
{
	ifnoerr (void* ptr = Get<void*>(0))
		return ptr;
	DebugStop();
	return nullptr;
}

Int PresetSaveArgs::GetType() const
{
	ifnoerr (Int type = Get<Int>(1))
		return type;
	DebugStop();
	return 0;
}

Result<void> AddAssetDepencendyStruct::AddDependency(AssetDependencyStruct&& assetDependency)
{
	iferr_scope;
	_dependencies.Insert(std::move(assetDependency)) iferr_return;
	return OK;
}

Result<void> AddAssetDepencendyStruct::AddDependency(const AssetDescription& depAsset)
{
	iferr_scope;

	String name = depAsset.GetMetaString(OBJECT::BASE::NAME) iferr_return;

	UniversalDateTime creationTimeStamp = depAsset.GetMetaData().Get(ASSETMETADATA::ASSET_TIMESTAMP).GetValueOrNull() iferr_return;
	AddDependency(AssetDependencyStruct{depAsset.GetIdAndVersion(), depAsset.GetTypeId(), creationTimeStamp, std::move(name), ASSET_UPDATE_POLICY::IMPLICIT}) iferr_return;

	return OK;
}

Result<AssetDescription> AddAssetDepencendyStruct::AddDependency(const Id& depAssetId)
{
	iferr_scope;

	AssetDescription latestAsset = _lookupRepository.FindLatestAsset(Id(), depAssetId, Id(), ASSET_FIND_MODE::LATEST) iferr_return;
	if (latestAsset)
	{
		AddDependency(latestAsset) iferr_return;
	}
	return latestAsset;
}

const HashSet<AssetDependencyStruct>& AddAssetDepencendyStruct::GetDependencies() const
{
	return _dependencies;
}

CreatePresetAssetStruct::CreatePresetAssetStruct(const String& name, const PresetSaveArgs& sourceData, ResolveAssetDependenciesStruct::ResolveDelegate&& resolveDependenciesDelegate, const Id& parentCategory, const AssetRepositoryRef& saveRepository, const AssetRepositoryRef& lookupRepository)
	: AddAssetDepencendyStruct(parentCategory, saveRepository, lookupRepository),
	_name(name),
	_sourceData(sourceData)
{
	_resolveAssets._resolveAssetDelegate = std::move(resolveDependenciesDelegate);
}

Result<void> CreatePresetAssetStruct::StoreMetaData(const InternedId& attr, ForwardingDataPtr&& data, AssetMetaDataInterface::KIND kind)
{
	iferr_scope;
	AddAssetMetaData::ValueType d;
	d.first = data.GetData() iferr_return;
	d.second = kind;
	_resMetaData.Insert(attr, std::move(d)) iferr_return;
	return OK;
}

}
