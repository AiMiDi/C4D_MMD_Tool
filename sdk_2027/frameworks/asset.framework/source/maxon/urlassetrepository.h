#ifndef URLASSETREPOSITORY_H__
#define URLASSETREPOSITORY_H__

#include "maxon/updatable_asset.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Extends UpdatableAssetRepositoryInterface with a url on disk.
//----------------------------------------------------------------------------------------
class UrlAssetRepositoryInterface : MAXON_INTERFACE_BASES(UpdatableAssetRepositoryInterface)
{
	MAXON_INTERFACE(UrlAssetRepositoryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.urlassetrepository", MAXON_IMPLEMENTATION_MODULE("net.maxon.asset"));

public:
	//----------------------------------------------------------------------------------------
	/// GetUrl returns the storage url of the asset repository.
	/// @param[in] getOrigin					True to get the original mount path of the repository. False to get the effective url (e.g. this could be a ramdisk:// in case of http connections).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Url GetUrl(Bool getOrigin) const;

	//----------------------------------------------------------------------------------------
	/// Checks if this repository can be mounted in writable mode, see UrlAssetRepositoryFactory::CreateRepository.
	/// @return												True if repository can be re-mounted as writable, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool SupportsWritableMount() const;
};

namespace ASSETREPOSITORYPROPERTIES
{
	/// This flag has to be set on an asset repository if the user shall be able to switch between read-write and read-only mode in the asset browser.
	MAXON_ATTRIBUTE(Bool, WRITABILITY_CHANGE_ALLOWED, "net.maxon.assetrepository.writabilitychangeallowed");
}

class UrlAssetRepositoryRef;

class UrlAssetRepositoryFactoryInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(UrlAssetRepositoryFactoryInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.urlassetrepositoryfactory", MAXON_IMPLEMENTATION_MODULE("net.maxon.asset"));

public:
	MAXON_METHOD Result<Bool> CanLoad(const Url& url) const;

	//----------------------------------------------------------------------------------------
	/// Creates an asset repository for the given Url. If there already is a directory structure
	/// in the expected format it is read as far as needed to initialize the repository with the found assets.
	/// Otherwise, the factory may create such a directory structure, but that's factory-dependent.
	/// @param[in] rid								The repository identifier. There mustn't be a base with the same identifier.
	/// @param[in] url								The root directory to use for the repository.
	/// @param[in] writable						True if the repository shall be writable.
	/// @param[in] registerDescriptionDatabase			True if the repository shall be registered as a description database as well.
	/// @param[in] bases							The base repositories for the new repository.
	/// @param[in] args								Optional factory-specific arguments.
	/// @param[in] backgroundJob			Optional background job to report errors, warnings, progress, cancellation.
	/// @return												An asset repository stored at #url.
	/// @MAXON_ANNOTATION{methodId="CreateRepository@6846999666030c37"->"CreateRepository@556d7ed4895b1d11"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<UrlAssetRepositoryRef> CreateRepository(const Id& rid, const Url& url, Bool writable, Bool registerDescriptionDatabase, const Block<const AssetRepositoryRef>& bases,
																															const DataDictionary& args = GetZeroRef<DataDictionary>(), const BackgroundEntryTuple& backgroundJob = GetZeroRef<BackgroundEntryTuple>()) const;

	//----------------------------------------------------------------------------------------
	/// Creates a standard asset repository for the given Url. If there already is a directory structure
	/// in the expected format it is read as far as needed to initialize the repository with the found
	/// assets, otherwise such a directory structure is created.
	/// @param[in] rid								The repository identifier. There mustn't be a base with the same identifier.
	/// @param[in] url								The root directory to use for the repository.
	/// @param[in] writable						True if the repository shall be writable.
	/// @param[in] registerDescriptionDatabase			True if the repository shall be registered as a description database as well.
	/// @param[in] bases							The base repositories for the new repository.
	/// @param[in] derivedInRepository	True if derived meta data shall be stored in the repository itself, false if the user preferences folder shall be used. The latter is mandatory if #url is a read-only Url.
	/// @param[in] backgroundJob			Optional background job to report errors, warnings, progress, cancellation.
	/// @param[in] baseVersionRepo		Optional repository if the new repository's version counter shall start one after the version counter of that base. This ensures non-overlapping version ranges for CompactableAssetRepositoryInterface::WriteIndex.
	/// @return												An asset repository stored at #url.
	//----------------------------------------------------------------------------------------
	static MAXON_FUNCTION Result<UrlAssetRepositoryRef> CreateStandardRepository(const Id& rid, const Url& url, Bool writable, Bool registerDescriptionDatabase, const Block<const AssetRepositoryRef>& bases,
																																							 Bool derivedInRepository, const BackgroundEntryTuple& backgroundJob = GetZeroRef<BackgroundEntryTuple>(),
																																							 const AssetRepositoryRef& baseVersionRepo = GetZeroRef<AssetRepositoryRef>());
};

#include "urlassetrepository1.hxx"

MAXON_REGISTRY(UrlAssetRepositoryFactory, UrlAssetRepositoryFactories, "net.maxon.asset.registry.repositoryfactories");

namespace UrlAssetRepositoryFactories
{
	MAXON_DECLARATION(UrlAssetRepositoryFactory, Standard, "net.maxon.asset.registry.repositoryfactories.standard",
		MAXON_ATTRIBUTE_CLASS(Bool, DerivedInRepository, "derivedinrepo");
		MAXON_ATTRIBUTE_CLASS(AssetRepositoryRef, BaseVersionRepository, "baseversionrepo");
	);
}

#include "urlassetrepository2.hxx"

}


#endif // URLASSETREPOSITORY_H__
