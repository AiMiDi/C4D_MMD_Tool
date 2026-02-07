#ifndef ASYNCRESOURCECACHE_H__
#define ASYNCRESOURCECACHE_H__

#include "maxon/datetime.h"
#include "maxon/factory.h"
#include "maxon/observerobject.h"
#include "maxon/optional.h"
#include "maxon/registrybase.h"

namespace maxon
{

using KeyData = StrongCOWRef<Data>;
using DataRef = StrongRef<Data>;
template <typename KEYTYPE = KeyData, typename TYPE = DataRef> class AsyncResourceCacheEntryRef;

//----------------------------------------------------------------------------------------
/// Cache class to allow delayed load of data with notification when it's ready to display.
/// Multiple requests are combined (the first request loads the data and notifies all others)
//----------------------------------------------------------------------------------------
class AsyncResourceCacheEntryInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(AsyncResourceCacheEntryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.asyncresourcecacheentry");
	MAXON_GENERIC(typename KEYTYPE = KeyData);
	MAXON_GENERIC((Out) typename TYPE = DataRef);

public:
	//----------------------------------------------------------------------------------------
	/// Delegate which is called if the cache was updated.
	/// @param[in] key								Key of the data.
	/// @param[in] loaded							Data with the loaded data.
	//----------------------------------------------------------------------------------------
	using UpdateCacheDelegate = Delegate<Result<void>(const Generic& key, const Generic& loaded)>;

	//----------------------------------------------------------------------------------------
	/// GetData returns the data from the cache, if there is one. If nullptr then the data is
	/// still loading. In that case the delegate is triggered once the data is loaded.
	/// @param[in] updateDelegate			Delegate which is called once the data is loaded.
	/// @param[in] async							Use false to force synchronous loading, by default loading is asynchronous.
	/// @return												Data or nullptr on success.
	//----------------------------------------------------------------------------------------
	template <typename KEYTYPE, typename TYPE> MAXON_FUNCTION Result<Opt<TYPE>> GetData(Delegate<Result<void>(const KEYTYPE& key, const TYPE& loaded)>&& updateDelegate, Bool async = true) const
	{
		iferr_scope;
		Opt<DataRef> data = GetDataImpl(std::move(reinterpret_cast<UpdateCacheDelegate&&>(updateDelegate)), async) iferr_return;
		if (!data.HasValue())
			return Opt<TYPE>{};
		if (data->GetPointer() == nullptr)
			return Opt<TYPE>(TYPE());
		return (*data)->Get<TYPE>();
	}

	MAXON_METHOD Result<Opt<DataRef>> GetDataImpl(UpdateCacheDelegate&& updateDelegate, Bool async = true) const;

	MAXON_METHOD Opt<UniversalDateTime> GetCacheCreationTime() const;

	MAXON_OBSERVABLE(void, ObservableFreeCache, (const KeyData& key), ObservableCombinerRunAllComponent);
};


enum class ASYNCRESOURCECACHEFLAGS
{
	NONE = 0,
	LIMIT_DATA_CACHE, ///< If set the data cache is limited to the given value in the init function. If this flag not set the cache lives as long as the cache entry.
} MAXON_ENUM_FLAGS(ASYNCRESOURCECACHEFLAGS);

template <typename KEYTYPE = KeyData, typename TYPE = DataRef> class AsyncResourceCacheRef;
//----------------------------------------------------------------------------------------
/// Cache class to allow delayed load of data with notification when it's ready to display.
/// Multiple requests are combined (the first request loads the data and notifies all others)
//----------------------------------------------------------------------------------------
class AsyncResourceCacheInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(AsyncResourceCacheInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.asyncresourcecache");

	MAXON_GENERIC(typename KEYTYPE = KeyData);
	MAXON_GENERIC((Out) typename TYPE = DataRef);

public:
	using LoadCacheDelegate = Delegate<Result<DataRef>(const KeyData& key)>;
	MAXON_ADD_TO_REFERENCE_CLASS(using Entry = AsyncResourceCacheEntryRef<KEYTYPE, TYPE>;);

	template <typename KEYTYPE, typename TYPE> static MAXON_FUNCTION Result<AsyncResourceCacheRef<KEYTYPE, TYPE>> Create(ASYNCRESOURCECACHEFLAGS flags, Int queueSize, Int cacheLimit, Delegate<Result<TYPE>(const KEYTYPE& key)>&& loadDelegate)
	{
		iferr_scope;
		using LambdaRef = StrongRef<Delegate<Result<TYPE>(const KEYTYPE& key)>>;
		LambdaRef lambda = NewObj(Delegate<Result<TYPE>(const KEYTYPE& key)>, std::move(loadDelegate)) iferr_return;

		typename SFINAEHelper<AsyncResourceCacheRef<>, TYPE>::type res = CreateImpl(flags, Data(GetDataType<TYPE>()), queueSize, cacheLimit,
			[lambda = std::move(lambda)](const KeyData& key) -> Result<DataRef>
			{
				iferr_scope;
				TYPE res = (*lambda)(key.GetOrDefault().GetOrDefault<KEYTYPE>()) iferr_return;
				DataRef dataRef = NewObj(Data, std::move(res)) iferr_return;
				return dataRef;
			}) iferr_return;

		return std::move(reinterpret_cast<AsyncResourceCacheRef<KEYTYPE, TYPE>&>(res));
	}

	static MAXON_METHOD Result<AsyncResourceCacheRef<>> CreateImpl(ASYNCRESOURCECACHEFLAGS flags, Data&& defaultValue, Int queueSize, Int cacheLimit, LoadCacheDelegate&& loadDelegate);

	//----------------------------------------------------------------------------------------
	/// InvalidateCache invalidates and removed the data from the cache. The next request will reload the data.
	/// @param[in] key								Data to discard from the cache.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename KEYTYPE> MAXON_FUNCTION Result<void> InvalidateCache(const KEYTYPE& key)
	{
		iferr_scope;
		KeyData keyData = KeyData::Create(Data(key)) iferr_return;
		return InvalidateCacheImpl(keyData);
	}

	MAXON_METHOD Result<void> InvalidateCacheImpl(const KeyData& key);

	//----------------------------------------------------------------------------------------
	/// FindOrCreate returns the cache for the requested data resource.
	/// @param[in] key								Key of the data to load.
	/// @return												Cache on success.
	//----------------------------------------------------------------------------------------
	template <typename KEYTYPE, typename TYPE> MAXON_FUNCTION Result<AsyncResourceCacheEntryRef<KEYTYPE, TYPE>> FindOrCreate(const KEYTYPE& key)
	{
		iferr_scope;
		typename SFINAEHelper<KeyData, TYPE>::type keyData = KeyData::Create(Data(key)) iferr_return;
		typename SFINAEHelper<AsyncResourceCacheEntryRef<>, TYPE>::type res = FindOrCreateImpl(keyData) iferr_return;
		return std::move(reinterpret_cast<AsyncResourceCacheEntryRef<KEYTYPE, TYPE>&>(res));
	}

	MAXON_METHOD Result<AsyncResourceCacheEntryRef<KEYTYPE, TYPE>> FindOrCreateImpl(const KeyData& key);

	//----------------------------------------------------------------------------------------
	/// Resets all caches
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Reset();

	//----------------------------------------------------------------------------------------
	/// Returns the current cache usage by type, count etc.
	/// @param[out] cnt								the number of entries of the cache,
	/// @param[out] mem								memory usage by this entry.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetStatistics(Int& cnt, Int& mem);
};

#include "asyncresourcecache1.hxx"

MAXON_REGISTRY(AsyncResourceCacheRef<>, AsyncResourceCacheTypes, "net.maxon.registry.asyncresourcecache");

#include "asyncresourcecache2.hxx"

} // namespace maxon

#endif // ASYNCRESOURCECACHE_H__
