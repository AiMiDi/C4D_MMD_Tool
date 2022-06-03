#ifndef DERIVED_METADATA_H__
#define DERIVED_METADATA_H__

#include "maxon/assets.h"

namespace maxon
{

namespace ASSETMETADATA
{
	//----------------------------------------------------------------------------------------
	/// The value of this meta data attribute is used by GetDerivedMetaData for invalidation
	/// of cached derived meta data. If an asset has a value for this meta data attribute,
	/// then GetDerivedMetaData uses the value as a stamp for its persistent cache. Whenever
	/// the value changes, the cached data is considered invalid and gets re-derived.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(CString, DerivedMetaDataStamp, "net.maxon.asset.derivedmetadatastamp");
}

//----------------------------------------------------------------------------------------
/// Caches and returns meta data which is derived from the asset via the given callback.
/// This helper function checks if there already exists derived meta data for the identifier
/// #metaId with matching stamp. If so, this data is loaded if necessary and returned,
/// otherwise @c{callback(asset)} is called, its result is stored (to a persistent storage)
/// as derived meta data of the asset under @metaId and finally returned.
///
/// Both the externalStamp and the value of the meta data attribute ASSETMETADATA::DerivedMetaDataStamp
/// are taken into account for the stamp. These two stamps are stored together with the actual data,
/// this allows for a simple mechanism to see whether the cached data is still valid.
/// For example if the derivation requires data from some external source, you could provide
/// the hash code of that data as externalStamp. Then, whenever that external source changes,
/// the cached data is considered invalid. Or, to invalidate all cached derived data of an asset,
/// you could change the value of ASSETMETADATA::DerivedMetaDataStamp.
///
/// Derived meta data of an asset is automatically invalidated whenever persistent meta data
/// is stored for the same asset. Also all derived meta data is invalidated when the application version changes.
/// Therefore you don't have to take this into account for the externalStamp.
///
/// @param[in] asset							The asset for which derived meta data shall be obtained.
/// @param[in] metaId							The identifier to use for the meta data.
/// @param[in] externalStamp			A string to tag the cached data. Only when this matches the one used for previously cached data, that data is used,
/// 															otherwise the data is newly computed by the callback.
/// @param[in] callback						A callback to derived the meta data from the asset, its meta data and external data.
/// @return												The derived meta data.
//----------------------------------------------------------------------------------------
template <typename T, typename CALLBACK> inline Result<T> GetDerivedMetaData(const AssetDescription& asset, const InternedId& metaId, const CString& externalStamp, CALLBACK&& callback)
{
	iferr_scope;

	Data data;
	CString stamp;
	MAXON_SCOPE
	{
		AssetMetaData meta = asset.GetMetaData();
		data = meta.Get(metaId) iferr_return;
		stamp = meta.Get(ASSETMETADATA::DerivedMetaDataStamp).GetValueOrNull() iferr_return;
	}
	const T* const value = data.GetPtr<T>();
	T result;
	if (value)
	{
		AssignCopy(result, *value) iferr_return;
	}
	else
	{
		using MetaType = Tuple<T, CString, CString>;
		const MetaType* const cached = data.GetPtr<MetaType>();
		if (cached && cached->second == stamp && cached->third == externalStamp)
		{
			AssignCopy(result, cached->first) iferr_return;
		}
		else
		{
			result = callback(asset) iferr_return;
			MetaType derived;
			derived.second = stamp;
			derived.third = externalStamp;
			AssignCopy(derived.first, result) iferr_return;
			iferr (asset.StoreMetaData(metaId, MoveDataPtr(std::move(derived)), AssetMetaData::KIND::PERSISTENT | AssetMetaData::KIND::DERIVED))
			{
				// Storing of derived meta data may fail because the repository is read-only and has no Url to store meta data.
				// Just ignore the error (so there is no caching and we have to call the callback every time).
				DiagnosticOutput(err.ToString());
			}
		}
	}
	return std::move(result);
}

#include "derived_metadata1.hxx"
#include "derived_metadata2.hxx"

}

#endif // DERIVED_METADATA_H__
