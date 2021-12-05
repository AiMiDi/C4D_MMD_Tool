#include "maxon/assets.h"
#include "maxon/datadescriptiondefinition.h"
#include "maxon/datetime.h"
#include "maxon/iostreams.h"

namespace maxon
{

const Id URLSCHEME_ASSET = Id("asset");
const Id URLSCHEME_ASSETDB = Id("assetdb");
const Id URLSCHEME_META = Id("meta");

Url GetAssetUrl(const DndAsset& asset)
{
	return asset.second;
}


const LiteralId AssetIdentifierInterface::VIRTUAL{"virtual"};

Bool AssetRepositoryInterface::IsBasedOnOrSame(const AssetRepositoryRef& other) const
{
	return other && FindRepository(other.GetId());
}

Bool AssetRepositoryInterface::IsBasedOnOrSame(const Id& otherRepo) const
{
	return FindRepository(otherRepo) != nullptr;
}

Result<DataDescription> AssetRepositoryInterface::LoadDescription(const Id& category, const LanguageRef& language, const Id& dataType)
{
	return LoadDescription(category, language, IdAndVersion(dataType, Id()));
}

Result<Asset> AssetDescriptionInterface::Load() const
{
	Bool update = false;
	return Load(&update);
}

Result<void> AssetDescriptionInterface::StoreMetaData(const InternedId& metaId, ForwardingDataPtr&& data, AssetMetaDataInterface::KIND kind) const
{
	const AssetDescriptionInterface* d = this;
	return static_cast<const AssetBaseInterface*>(static_cast<const ObjectInterface*>(this))->GetRepository().StoreMetaData(reinterpret_cast<const AssetDescription&>(d), metaId, std::move(data), kind);
}

Result<void> AssetDescriptionInterface::StoreUrlMetaData(const InternedId& metaId, const Url& source, AssetMetaDataInterface::KIND kind) const
{
	const AssetDescriptionInterface* d = this;
	return static_cast<const AssetBaseInterface*>(static_cast<const ObjectInterface*>(this))->GetRepository().StoreUrlMetaData(reinterpret_cast<const AssetDescription&>(d), metaId, source, kind);
}

Result<void> UpdateAssetUsage(const AssetDescription& asset, Bool incCount, Bool updateDate)
{
	iferr_scope;

	if (!asset)
		return OK;

	if (incCount || updateDate)
	{
		ASSETMETADATA::AssetUsageType usage = asset.GetMetaData().Get(ASSETMETADATA::Usage, ASSETMETADATA::AssetUsageType()) iferr_return;
		if (updateDate)
		{
			usage.Get<UniversalDateTime>() = UniversalDateTime::GetNow();
		}
		if (incCount)
		{
			usage.Get<Int>()++;
		}

		asset.StoreMetaData(ASSETMETADATA::Usage, usage, AssetMetaData::KIND::PERSISTENT | AssetMetaData::KIND::USER) iferr_return;
	}

	return OK;
}

Result<IdAndVersion> IdToIdAndVersion(const Id& id)
{
	iferr_scope;

	IdAndVersion assetId;

	CString idStr = id.ToCString();

	Int idx = idStr.FindIndex("#="_cs);
	if (idx != InvalidArrayIndex)
	{
		idStr = idStr.GetLeftPart(idx);
	}

	idx = idStr.FindIndex("?="_cs);
	if (idx != InvalidArrayIndex)
	{
		CString versionStr = idStr.GetRightPart(idx + 2);
		assetId.second.Init(versionStr) iferr_return;
		idStr = idStr.GetLeftPart(idx);
	}

	assetId.first.Init(idStr) iferr_return;

	return std::move(assetId);
}

Result<Id> IdAndVersionToId(const IdAndVersion& assetId)
{
	iferr_scope;
	Id id = assetId.Get<0>();
	if (assetId.Get<1>().IsPopulated())
	{
		CString idStr = assetId.Get<0>().ToCString();
		CString versionStr = assetId.Get<1>().ToCString();
		id.Init(idStr + "?="_cs + versionStr) iferr_return;
	}
	return std::move(id);
}

Result<Tuple<AssetRepositoryRef, IdAndVersion, Bool>> IdToIdAndVersionWithRepository(const Id& id, const AssetRepositoryRef& lookupRepository)
{
	iferr_scope;

	if (id.IsEmpty())
		return Tuple<AssetRepositoryRef, IdAndVersion, Bool>();

	AssetRepositoryRef repositoryRef;
	IdAndVersion			 assetId;
	Bool							 limitRepository = false;

	CString idStr = id.ToCString();

	Int idx = idStr.FindIndex("#="_cs);
	if (idx != InvalidArrayIndex)
	{
		Id repositoryId;
		repositoryId.Init(idStr.GetRightPart(idx + 2)) iferr_return;
		repositoryRef = lookupRepository.FindRepository(repositoryId);
		idStr = idStr.GetLeftPart(idx);
		if (repositoryRef)
			limitRepository = true;
	}

	idx = idStr.FindIndex("?="_cs);
	if (idx != InvalidArrayIndex)
	{
		CString versionStr = idStr.GetRightPart(idx + 2);
		assetId.second.Init(versionStr) iferr_return;
		idStr = idStr.GetLeftPart(idx);
	}

	assetId.first.Init(idStr) iferr_return;

	if (!repositoryRef)
	{
		repositoryRef = lookupRepository;
	}

	return Tuple<AssetRepositoryRef, IdAndVersion, Bool>(repositoryRef, std::move(assetId), limitRepository);
}

Result<Id> IdAndVersionToIdWithRepository(const IdAndVersion& assetId, const AssetRepositoryRef& repository)
{
	iferr_scope;
	Id id = IdAndVersionToId(assetId) iferr_return;
	if (repository)
	{
		Id repositoryId = repository.GetId();
		if (repositoryId.IsPopulated())
		{
			id.Init(id.ToCString() + "#="_cs + repositoryId.ToCString()) iferr_return;
		}
	}
	return std::move(id);
}

}
