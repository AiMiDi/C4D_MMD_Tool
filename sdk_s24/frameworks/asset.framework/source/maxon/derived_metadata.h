#ifndef DERIVED_METADATA_H__
#define DERIVED_METADATA_H__

#include "maxon/assets.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Caches and returns meta data which is derived from the asset via the given callback.
/// This helper function checks if there already exists derived meta data for the identifier
/// #metaId with matching externalHash. If so, this data is loaded if necessary and returned,
/// otherwise @c{callback(asset)} is called, its result is stored as derived meta data of the
/// asset under @metaId and finally returned.
///
/// The externalHash is stored together with the actual data, this allows for a simple mechanism
/// to see whether the cached data is still valid. For example if the derivation requires
/// data from some external source, you could provide the hash code of that data as externalHash.
///
/// Derived meta data of an asset is automatically invalidated whenever persistent meta data
/// is stored for the same asset. Also all derived meta data is invalidated when the application version changes.
/// Therefore you don't have to take this into account for the externalHash.
///
/// @param[in] asset							The asset for which derived meta data shall be obtained.
/// @param[in] metaId							The identifier to use for the meta data.
/// @param[in] externalHash				Some hash string. Only when this matches the one used for the cached data, the cached data is used.
/// @param[in] callback						A callback to derived the meta data from the asset, its meta data and external data.
/// @return												The derived meta data.
//----------------------------------------------------------------------------------------
template <typename T, typename CALLBACK> inline Result<T> GetDerivedMetaData(const AssetDescription& asset, const InternedId& metaId, const CString& externalHash, CALLBACK&& callback)
{
	iferr_scope;

	Data data;
	MAXON_SCOPE
	{
		AssetMetaData meta = asset.GetMetaData();
		data = meta.Get(metaId) iferr_return;
	}
	const T* const value = data.GetPtr<T>();
	T result;
	if (value)
	{
		AssignCopy(result, *value) iferr_return;
	}
	else
	{
		using MetaType = Tuple<T, CString>;
		const MetaType* const cached = data.GetPtr<MetaType>();
		if (cached && cached->second == externalHash)
		{
			AssignCopy(result, cached->first) iferr_return;
		}
		else
		{
			result = callback(asset) iferr_return;
			MetaType derived;
			derived.second = externalHash;
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

}

#endif // DERIVED_METADATA_H__
