#ifndef ASSETS_H__
#define ASSETS_H__

#include "maxon/backgroundentry.h"
#include "maxon/datadictionaryobject.h"
#include "maxon/datetime.h"
#include "maxon/factory.h"
#include "maxon/idandversion.h"
#include "maxon/observable.h"
#include "maxon/observerobject.h"
#include "maxon/url.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace ASSETMETADATA
{
	MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.assetmetadata");

	/// This read-only asset meta data attribute has the time stamp of the asset creation as value.
	/// It is automatically set by an asset repository when StoreAsset is called.
	MAXON_ATTRIBUTE(UniversalDateTime, ASSET_TIMESTAMP, "net.maxon.asset.timestamp");

	/// This read-only asset meta data attribute has the size of the asset.
	/// It is a optional property.
	MAXON_ATTRIBUTE(UInt64, ASSET_SIZE, "net.maxon.asset.size");

	/// This asset meta data attribute can be set by the user to give a version tag for an asset.
	/// There is no special convention for the version tag, so it could be for example "1.0" or "Fixed bug 42".
	MAXON_ATTRIBUTE(String, ASSET_VERSIONTAG, "net.maxon.asset.versiontag");

	/// This asset meta data attribute can be set by the user to give a preview image.
	MAXON_ATTRIBUTE(Url, ASSET_PREVIEWIMAGEURL, "net.maxon.asset.previewimageurl");

	/// Optional asset meta data attribute can be set by the user to give a preview animation.
	MAXON_ATTRIBUTE(Url, ASSET_PREVIEWANIMURL, "net.maxon.asset.previewanimurl");

	/// url to a 3D file format with the proxy geometry
	MAXON_ATTRIBUTE(Url, PROXYGEOMETRY, "net.maxon.assetmetadata.proxygeometry");

	/// manual sorting of asset browser entries
	MAXON_ATTRIBUTE(String, ASSET_SORT, "net.maxon.asset.sort");
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------


namespace maxon
{

class DataDescription MAXON_FORWARD("maxon/datadescription.h");
class DataDescriptionDefinition MAXON_FORWARD("maxon/datadescriptiondefinition.h");
enum class LOADDESCRIPTIONMODE;

class AssetMetaData;
class AssetType;
class Asset;
class AssetBase;
class AssetInterface;
class AssetDescription;
class AssetReference;
class AssetLink;
class AssetRepositoryRef;
class BackgroundProgressRef;
class UpdatableAssetRepositoryRef;
class LanguageRef;
class ImageBaseRef;
class DerivedAssetRepositoryDataRef;

/// @brief Scheme identifier for asset references as used by Asset API data structures.
/// @details The same asset could be referenced by the URLs `"asset:///file_37cd8c8dadea1a6a~.c4d"`
/// and `"asset:///file_37cd8c8dadea1a6a~.c4d?name=SDK Cube&db=sdkdatabase.db"`, where the optional
/// parameters are only used in error messages when the asset URL does not resolve. Both URLs can 
/// be used to reference the asset.
/// @see UrlScheme
constexpr LiteralId URLSCHEME_ASSET = LiteralId("asset");

/// @brief Scheme identifier for human readable asset references as shown to the user in GUIs.
/// @details This scheme is never used to store references. The location of an asset is unpacked
/// into its asset category relations, e.g., `asset:///file_37cd8c8dadea1a6a~.c4d` -> `assetdb:///tex/Surfaces/Dirt Scratches & Smudges/RustPaint0291_M.jpg`.
/// @see UrlScheme
constexpr LiteralId URLSCHEME_ASSETDB = LiteralId("assetdb");

/// @brief Scheme identifier for relative file links to the metadata of an asset in a asset repository.
/// @see UrlScheme
constexpr LiteralId URLSCHEME_META = LiteralId("meta");

/// @brief Scheme identifier for relative file links to the metadata of an asset in an SQL database.
/// @see UrlScheme
constexpr LiteralId URLSCHEME_METASQ = LiteralId("metasq");


enum class ASSETLICENSETYPE : UInt64
{
	NONE = 0,

	ENABLE_IN_SUBSCRIPTION = (1 << 0),
	SHOW_IN_SUBSCRIPTION = (1 << 1),

	ENABLE_IN_PERPETUAL = (1 << 2),
	SHOW_IN_PERPETUAL = (1 << 3),

	ENABLE_IN_TRIAL = (1 << 4),
	SHOW_IN_TRIAL = (1 << 5),

	ENABLE_IN_LITE = (1 << 6),
	SHOW_IN_LITE = (1 << 7),

	ENABLE_IN_STUDENT = (1 << 8),
	SHOW_IN_STUDENT = (1 << 9),

	ENABLE_IN_EDUCATION = (1 << 10),
	SHOW_IN_EDUCATION = (1 << 11),

	ENABLE_IN_CINEWARE = (1 << 12),
	SHOW_IN_CINEWARE = (1 << 13),

	ONLY_IN_MAXONONE = (1 << 30),

	ENABLE_IN_ALL = ENABLE_IN_SUBSCRIPTION | ENABLE_IN_PERPETUAL | ENABLE_IN_TRIAL | ENABLE_IN_LITE | ENABLE_IN_STUDENT | ENABLE_IN_EDUCATION | ENABLE_IN_CINEWARE,
	SHOW_IN_ALL = SHOW_IN_SUBSCRIPTION | SHOW_IN_PERPETUAL | SHOW_IN_TRIAL | SHOW_IN_LITE | SHOW_IN_STUDENT | SHOW_IN_EDUCATION | SHOW_IN_CINEWARE,

	ALLBITS = ONLY_IN_MAXONONE | ENABLE_IN_ALL | SHOW_IN_ALL,

} MAXON_ENUM_FLAGS(ASSETLICENSETYPE);

/// AssetRepositoryRef properties can get queried with Get() or Set()
/// e.g. Bool skipSearch = repository.Get(ASSETREPOSITORYPROPERTIES::SKIP_ON_SEARCH, false);
namespace ASSETREPOSITORYPROPERTIES
{
	/// internal: skips the repository when searching in all asset browsers. this flag is used to hide mounted libraries if another own with the same id overloads it
	MAXON_ATTRIBUTE(Bool, SKIP_ON_SEARCH, "net.maxon.assetrepository.skipinsearch");
	/// flag which indicates if the repository is configured to copy assets to disk on "save project with assets"
	MAXON_ATTRIBUTE(Bool, EXPORT_ON_SAVE_PROJECT, "net.maxon.assetrepository.exportonsaveproject");

	MAXON_ATTRIBUTE(Int, CATEGORYCOUNT, "net.maxon.assetrepository.categorycount");
	MAXON_ATTRIBUTE(Int, ASSETCOUNT, "net.maxon.assetrepository.assetcount");
	MAXON_ATTRIBUTE(Int64, ASSETSIZE, "net.maxon.assetrepository.assetsize");
	/// key: Id Value: Tuple<Int count, Int64 size>
	MAXON_ATTRIBUTE(DataDictionary, DETAILCOUNT, "net.maxon.assetrepository.detailcount");
}

//----------------------------------------------------------------------------------------
/// Special asset id to declare missing assets in the dependency list.
/// if this id appears in the dependencies, then the dependency asset was missing when creating the asset.
//----------------------------------------------------------------------------------------
static constexpr LiteralId ID_MISSINGASSETS{"net.maxon.asset.file.missingassets"};

//----------------------------------------------------------------------------------------
/// Helper class to pass several arguments into asset creation functions
//----------------------------------------------------------------------------------------
struct AssetDependencyStruct
{
	IdAndVersion				assetIdAndVersion;	///< IdAndVersion of the asset.
	Id									assetTypeId;				///< Asset Type.
	UniversalDateTime		assetCreationDate;	///< Asset Creation time
	String							originalName;				///< Original asset name
	ASSET_UPDATE_POLICY updatePolicy = ASSET_UPDATE_POLICY::IMPLICIT;	///< update policy.

	// make sure to extend "static Result<void> DescribeIO(const AssetDependencyStruct& s, const DataSerializeInterface& stream)" when adding policy

	MAXON_OPERATOR_STRUCT(AssetDependencyStruct, assetIdAndVersion, assetTypeId, assetCreationDate, originalName, updatePolicy);
};

MAXON_DATATYPE(AssetDependencyStruct, "net.maxon.datatype.asset.dependencystruct");

namespace ASSETMETADATA
{
	//----------------------------------------------------------------------------------------
	/// Array with asset ids which other assets are required to use this asset.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Array<AssetDependencyStruct>, Dependencies, "net.maxon.asset.dependencies.2");

	//----------------------------------------------------------------------------------------
	/// Defines the version (from, to) which the asset is valid.
	//----------------------------------------------------------------------------------------
	using VersionRange = Tuple<Float, Float>;
	MAXON_ATTRIBUTE(VersionRange, ValidVersionRange, "net.maxon.asset.validversion");

	//----------------------------------------------------------------------------------------
	/// Defines the version (from, to) which the asset is valid.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(ASSETLICENSETYPE, ValidLicenseType, "net.maxon.asset.validlicensetype");

	//----------------------------------------------------------------------------------------
	/// This asset meta data attribute can be set by the user to give more details about the asset.
	/// The data is depending on the asset type and subtype.
	/// The DataDictionary can contain the Resolution of images/movies, bounding boxes of geometry.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(DataDictionary, MetaProperties, "net.maxon.asset.metaproperties");

	using AssetUsageType = Tuple<UniversalDateTime, Int>;
	//----------------------------------------------------------------------------------------
	/// this meta data counts the usage of the assets.
	/// 1. UniversalDateTime - last usage
	/// 2. Int - usage count
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(AssetUsageType, Usage, "net.maxon.asset.usage");
}

//----------------------------------------------------------------------------------------
/// AssetMetaData allows to query the meta data of an asset. It is returned by AssetDescriptionInterface::GetMetaData.
/// The methods of this interface are thread-safe, but the meta data of an asset may be
/// changed concurrently, so the returned values may differ from call to call even when the
/// calling thread made no modification inbetween.
///
/// You can't modify the meta data of an asset through this interface, you have to use
/// AssetDescriptionInterface::StoreMetaData instead.
//----------------------------------------------------------------------------------------
class AssetMetaDataInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(AssetMetaDataInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.assetmetadata");
public:
	//----------------------------------------------------------------------------------------
	/// This enum defines flags for the kind of a meta data entry.
	//----------------------------------------------------------------------------------------
	enum class KIND
	{
		NONE = 0,											///< No flag set.
		READ_ONLY = (1 << 0),					///< The meta data is read-only, for example the AssetTimeStamp.
		PERSISTENT = (1 << 1),				///< The meta data is persistent.
		VERSION = (1 << 2),						///< The meta data is tied to the version so that it isn't copied to a new version, for example the AssetVersionTag.
		DERIVED = (1 << 3),						///< The meta data is derived from the asset and other meta data.
		USER = (1 << 4),							///< The meta data should be stored in user folder.
		MASK = 0xffff,								///< A mask for all regular flags.
		IGNORE_READ_ONLY = (1 << 16)	///< This flag is only used as argument for AssetRepositoryInterface::StoreMetaData to ignore the READ_ONLY flag.
	} MAXON_ENUM_FLAGS_CLASS(KIND);

	//----------------------------------------------------------------------------------------
	/// Returns an array with the current set of meta data entries.
	/// @return												The current set of meta data entries given by the meta data attribute id and kind.
	/// @note The returned value may differ from call to call because another thread could have modified the meta data in between.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<Tuple<InternedId, KIND>>> GetExistingEntries() const;

	//----------------------------------------------------------------------------------------
	/// Returns the current value of the meta data entry for the meta data attribute #metaId.
	/// @param[in] metaId							The identifier of the meta data attribute.
	/// @return												The current value for the attribute, or an empty Data if there is no entry.
	///																An error is returned if there is an entry, but loading the entry value fails.
	/// @note The returned value may differ from call to call because another thread could have modified the meta data in between.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data> Get(const InternedId& metaId) const;

	//----------------------------------------------------------------------------------------
	/// Returns the current value of the meta data entry for the meta data attribute #metaId.
	/// @param[in] metaId							The identifier of the meta data attribute.
	/// @tparam T											The type of the meta data attribute.
	/// @return												The current value for the attribute, or an empty Opt if there is no entry.
	///																An error is returned if there is an entry, but loading the entry value fails.
	/// @note The returned value may differ from call to call because another thread could have modified the meta data in between.
	//----------------------------------------------------------------------------------------
	template <typename T> MAXON_FUNCTION Result<Opt<T>> Get(const InternedId& metaId) const
	{
		iferr_scope;
		Opt<T> result;
		PrivateGet(metaId, GetDataType<T>(), reinterpret_cast<Generic*>(&result)) iferr_return;
		return result;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the current value of the meta data entry for the meta data attribute ATTR.
	/// @tparam ATTR									The attribute for which the value shall be returned (has to be declared with MAXON_ATTRIBUTE).
	/// @return												The current value for the id, or an empty Opt if there is no entry.
	///																An error is returned if there is an entry, but loading the entry value fails.
	/// @note The returned value may differ from call to call because another thread could have modified the meta data in between.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> MAXON_FUNCTION Result<Opt<typename ATTR::ValueType>> Get() const
	{
		return Get<typename ATTR::ValueType>(ATTR::Get());
	}

	//----------------------------------------------------------------------------------------
	/// Returns the current value of the meta data entry for the meta data attribute #attr.
	/// @param[in] attr								The attribute for which the value shall be returned (has to be declared with MAXON_ATTRIBUTE).
	/// @return												The current value for the id, or an empty Opt if there is no entry.
	///																An error is returned if there is an entry, but loading the entry value fails.
	/// @note The returned value may differ from call to call because another thread could have modified the meta data in between.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> MAXON_FUNCTION Result<Opt<typename ATTR::ValueType>> Get(const ATTR& attr) const
	{
		return Get<typename ATTR::ValueType>(attr.Get());
	}

	//----------------------------------------------------------------------------------------
	/// Returns the current value of the meta data entry for the meta data attribute #attr.
	/// @param[in] attr								The attribute for which the value shall be returned (has to be declared with MAXON_ATTRIBUTE).
	/// @param[in] defaultValue				The default value to use when there is no entry.
	/// @return												The current value for the id, or the defaultValue if there is no entry.
	///																An error is returned if there is an entry, but loading the entry value fails.
	/// @note The returned value may differ from call to call because another thread could have modified the meta data in between.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> MAXON_FUNCTION Result<typename ATTR::ValueType> Get(const ATTR& attr, const typename ATTR::ValueType& defaultValue) const
	{
		iferr_scope;
		Opt<typename ATTR::ValueType> result;
		PrivateGet(attr.Get(), GetDataType<typename ATTR::ValueType>(), reinterpret_cast<Generic*>(&result)) iferr_return;
		return result.GetValueOr(defaultValue);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the time stamp for the meta data attribute #metaId. The time stamp is increased
	/// each time the value changes.
	/// @param[in] metaId							The identifier of the meta data attribute.
	/// @return												The time stamp for the attribute, or 0 if there is no entry for the attribute.
	/// @note The returned value may differ from call to call because another thread could have modified the meta data in between.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetTimeStamp(const InternedId& metaId) const;

	/// @private
	static MAXON_METHOD const AssetMetaDataInterface* DefaultValuePtr();

	MAXON_METHOD Result<void> PrivateGet(const InternedId& metaId, const DataType& type, Generic* mem) const;
};


class OutputStreamRef MAXON_FORWARD("maxon/iostreams.h");

//----------------------------------------------------------------------------------------
/// A delegate which receives an output stream as parameter and returns either that %stream itself or a
/// wrapper %stream which decorates the original stream.
/// @param[in] stream							The %stream to decorated.
/// @return												The decorated %stream, may be stream itself.
//----------------------------------------------------------------------------------------
using OutputStreamDecoratorFactory = Delegate<Result<OutputStreamRef>(const OutputStreamRef& stream)>;


namespace ASSETTYPEPROPERTIES
{
	class RESTRICT;

	namespace SUPPORTS
	{
		/// AssetTypeInterface::Get(ASSETTYPEPROPERTIES::SUPPORTS::VERSIONS) returns true if this type of asset supports versioning.
		MAXON_ATTRIBUTE(Bool, VERSIONS, "net.maxon.assettypeproperties.support.versions");
	}
}

//----------------------------------------------------------------------------------------
/// An AssetType provides the methods needed by an asset repository to handle a specific type of assets.
/// For example there is one asset type for node systems which knows how to load and store
/// node systems and their description resources, one for pure files and so on. Asset types
/// are registered at the AssetTypes registry.
//----------------------------------------------------------------------------------------
class AssetTypeInterface : MAXON_INTERFACE_BASES(DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(AssetTypeInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.assettype");
public:
	using RESTRICT_DICTIONARY_PROPS = ASSETTYPEPROPERTIES::RESTRICT;

	//----------------------------------------------------------------------------------------
	/// Returns the identifier of this asset type. This has to be the same as used for the AssetTypes registry.
	/// @return												Asset type identifier.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Id& GetId() const;

	//----------------------------------------------------------------------------------------
	/// Returns the DataType of assets handled by this AssetType. The data type has to be a reference type
	/// derived from Asset.
	/// @return												The data type of assets of this AssetType.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataType& GetAssetDataType() const;

	//----------------------------------------------------------------------------------------
	/// Returns the Url suffix (file name ending without the dot) to use for the given asset.
	/// @param[in] asset							An asset, has to match the expected data type of this AssetType.
	/// @return												The Url suffix to use, may be empty.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> GetUrlSuffix(const Asset& asset) const;

	//----------------------------------------------------------------------------------------
	/// GetDefaultIcon returns the default icon of this asset type.
	/// @param[in] repository					Repository to search for.
	/// @param[in] asset							Asset id and version.
	/// @param[in] meta								meta data of the asset to store.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Url> GetDefaultIcon(const AssetRepositoryRef& repository, const IdAndVersion& asset, const AssetMetaData& meta) const;

	//----------------------------------------------------------------------------------------
	/// Loads an asset from a Url.
	/// @param[in] repo								The repository to which the asset belongs.
	/// @param[in] assetDescription		The asset description.
	/// @param[in] url								The Url from which the asset shall be loaded.
	/// @param[in,out] updateLinks		nullptr if the asset shall be loaded as is, or a pointer to a Bool if asset links which
	///																use ASSET_UPDATE_POLICY::IMPLICIT shall be resolved to the latest version. The Bool is set to true
	///																by this method whenever there is a link where the resolved version differs from the original version.
	/// @return												The loaded asset.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Asset> Load(const AssetRepositoryRef& repo, const AssetDescription& assetDescription, const Url& url, Bool* updateLinks) const;

	//----------------------------------------------------------------------------------------
	/// Stores an asset at the given Url.
	/// @param[in] asset							The asset to store, has to match the expected data type of this AssetType.
	/// @param[in] url								The Url where to store the asset.
	/// @param[in] hashStream					The stream decorator to use for each created output stream.
	///																This can be used by the caller to compute a hash value of the asset content
	///																which is then used as version identifier.
	/// @return												A map for additional persistent meta data entries which the calling repository has to store for the asset.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<HashMap<InternedId, Data>> Store(const Asset& asset, const Url& url, const OutputStreamDecoratorFactory& hashStream) const;

	//----------------------------------------------------------------------------------------
	/// CopyWithEncryption copies the asset with encryption to the new url.
	/// @param[in] source							Asset to copy.
	/// @param[in] from								source url.
	/// @param[in] to									destination url.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CopyWithEncryption(const AssetDescription& source, const Url& from, const Url& to) const;

	//----------------------------------------------------------------------------------------
	/// LoadDescriptionDefinition loads the data description of the given asset.
	/// @param[in] asset							Asset to load.
	/// @param[in] mode								see LOADDESCRIPTIONMODE.
	/// @param[in] category						DATADESCRIPTION_CATEGORY_xxx
	/// @param[in] language						Language id in case of DATADESCRIPTION_CATEGORY_STRING.
	/// @return                       DataDescriptionDefinition on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDescriptionDefinition> LoadDescriptionDefinition(const AssetDescription& asset,
		LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language) const;

	//----------------------------------------------------------------------------------------
	/// StoreDescriptionDefinition description.
	/// @param[in] asset							Asset to store.
	/// @param[in] category						DATADESCRIPTION_CATEGORY_xxx
	/// @param[in] language						Language id in case of DATADESCRIPTION_CATEGORY_STRING.
	/// @param[in] overwrittenDescription	Additional description with overwritten parameters.
	/// @param[in] storeRepository		Repository to store the asset.
	/// @return                       AssetDescription with the new asset on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<AssetDescription> StoreDescriptionDefinition(const AssetDescription& asset, const Id& category,
		const LanguageRef& language, const DataDescriptionDefinition& overwrittenDescription, const AssetRepositoryRef& storeRepository) const;

	//----------------------------------------------------------------------------------------
	/// GetRepositoryId returns the default id of the asset.
	/// @param[in] id									Id of the asset.
	/// @param[in] fromTo							True to add the full id. False to cut the hash code and append it.
	/// @return                       New id on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Id> GetRepositoryId(const Id& id, Bool fromTo) const;

	//----------------------------------------------------------------------------------------
	/// GetMetaString returns the translated string from a asset.
	/// @param[in] asset							Asset to load.
	/// @param[in] key								Attribute id to load. e.g. OBJECT::BASE:NAME.
	/// @param[in] languageRef				Optional language. By default the function uses the current language.
	/// @param[in] fallback						Fallback string if the asset has no name.
	/// @return                       String on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> GetMetaString(const AssetDescription& asset, const InternedId& key, const LanguageRef& languageRef, const String& fallback) const;

	//----------------------------------------------------------------------------------------
	/// StoreMetaString stores the name of an asset for a language.
	/// @param[in] asset							Asset to modify.
	/// @param[in] key								Attribute id to save. e.g. OBJECT::BASE:NAME.
	/// @param[in] value							New string.
	/// @param[in] languageRef				Optional language. By default the function uses the current language.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> StoreMetaString(const AssetDescription& asset, const InternedId& key, const String& value, const LanguageRef& languageRef) const;

	//----------------------------------------------------------------------------------------
	/// Overload ComputeMetaData to specialize the loading of meta data.
	/// @param[in] repository					Resository where the asset is stored.
	/// @param[in] asset							Asset id and version.
	/// @param[in] meta								Meta data of the asset.
	/// @param[in] metaId							MetaId to load.
	/// @return                       Tuple<Data, Bool> on success. Data contains the data. Bool if the value should be cached.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Tuple<Data, Bool>> ComputeMetaData(const AssetRepositoryRef& repository, const IdAndVersion& asset, const AssetMetaData& meta, const InternedId& metaId) const;
};


//----------------------------------------------------------------------------------------
/// This base component can be used by implementations of AssetType.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<AssetType>, AssetTypeBaseComponent, "net.maxon.component.assettypebase");


//----------------------------------------------------------------------------------------
/// The registry for asset types.
/// @see AssetType
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(AssetType, AssetTypes, "net.maxon.registry.assettypes");


//----------------------------------------------------------------------------------------
/// The base interface of AssetBaseInterface and AssetLinkInterface.
/// It contains their common methods to obtain type, identifier and version.
//----------------------------------------------------------------------------------------
class AssetIdentifierInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(AssetIdentifierInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.assetidentifier");
public:
	//----------------------------------------------------------------------------------------
	/// VIRTUAL is used as version identifier for assets which can't be re-obtained
	/// from a repository by their identifier. The typical use case is for dynamically created
	/// assets which get an identifier just for clarity, but not to actually identify them.
	/// References to virtual assets can't be serialized.
	//----------------------------------------------------------------------------------------
	static constexpr LiteralId VIRTUAL{"virtual"};

	//----------------------------------------------------------------------------------------
	/// Returns the identifier of the AssetType of this asset.
	/// @return												Identifier of the AssetType of this asset.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Id& GetTypeId() const;

	//----------------------------------------------------------------------------------------
	/// Returns the identifier and version of this asset as a tuple.
	/// @return												(identifier, version) of this asset.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const IdAndVersion& GetIdAndVersion() const;

	//----------------------------------------------------------------------------------------
	/// Returns the identifier of this asset. Asset identifiers have to be globally unique.
	/// @return												Asset identifier (empty for an Asset which doesn't belong to a repository).
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION const Id& GetId() const
	{
		return GetIdAndVersion().first;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the version of this asset. Version identifiers are assigned by repositories when
	/// assets are stored, typically this is a hash value derived from the asset content or a UUID.
	/// In general two assets should have equal version identifiers only if they have equal content.
	/// @return												Asset version identifier (empty for an Asset which doesn't belong to a repository).
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION const Id& GetVersion() const
	{
		return GetIdAndVersion().second;
	}
};


//----------------------------------------------------------------------------------------
/// An AssetLink is a symbolic link to an asset identified by its id and version.
/// Also an ASSET_UPDATE_POLICY is stored to control the behavior of the link when
/// newer versions of the linked asset exists.
///
/// Alternatively an AssetLink can also just wrap a Url from which an asset can be loaded directly.
//----------------------------------------------------------------------------------------
class AssetLinkInterface : MAXON_INTERFACE_BASES(AssetIdentifierInterface)
{
	MAXON_INTERFACE(AssetLinkInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.assetlink");
	MAXON_INTERFACE_SINGLE_IMPLEMENTATION;
public:
	//----------------------------------------------------------------------------------------
	/// Creates a new AssetLink for the given asset and update policy.
	/// @param[in] type								The expected type of the asset.
	/// @param[in] aid								Identifier and version of the asset.
	/// @param[in] up									The update policy which the created link shall use.
	/// @return												A new AssetLink.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetLink> Create(const Id& type, const IdAndVersion& aid, ASSET_UPDATE_POLICY up);

	//----------------------------------------------------------------------------------------
	/// Creates a new AssetLink for the given Url. This is for assets which aren't stored in a repository, but shall be read directly from a Url
	/// such as a local image file.
	/// @param[in] type								The expected type of the asset.
	/// @param[in] url								The Url where the asset can be read from.
	/// @return												A new AssetLink.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetLink> Create(const Id& type, const Url& url);

	//----------------------------------------------------------------------------------------
	/// Returns the Url for a Url-based AssetLink.
	/// @return												The Url to which this AssetLink points, or a default value when this AssetLink uses an asset identifier instead of a Url.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Url& GetUrl() const;

	//----------------------------------------------------------------------------------------
	/// Resolves this AssetLink to an AssetDescription in the given context. The asset identifier
	/// of this link is used to find the asset in context, and if this link uses the policy
	/// ASSET_UPDATE_POLICY::IMPLICIT the latest version of the asset is used,
	/// otherwise the version recorded in this link.
	/// @param[in] context						The repository to use for the asset lookup.
	/// @return												The found AssetDescription or a default value when no asset could be found.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<AssetDescription> Resolve(const AssetRepositoryRef& context) const;

	//----------------------------------------------------------------------------------------
	/// Returns the update policy which this link uses.
	/// @return												The update policy of this link.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ASSET_UPDATE_POLICY GetUpdatePolicy() const;

	//----------------------------------------------------------------------------------------
	/// Sets the update policy for this link.
	/// @param[in] up									The new update policy for this link.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetUpdatePolicy(ASSET_UPDATE_POLICY up);
};


//----------------------------------------------------------------------------------------
/// The flags of ASSET_FIND_MODE control the behavior of AssetRepositoryInterface::FindAssets.
//----------------------------------------------------------------------------------------
enum class ASSET_FIND_MODE
{
	NONE																= 0,			///< No flag set.
	LATEST															= 1 << 0,	///< Set this flag to obtain only the latest version of the asset.
	ALL																	= 1 << 1,	///< Set this flag to obtain all versions of the asset.
	WITHOUT_BASES												= 1 << 2,	///< Set this flag if the asset shouldn't be looked up in base repositories.
	WITH_DELETED												= 1 << 3,	///< Set this flag to also find deleted assets.
	PREFIX															= 1 << 4,	///< Set this flag to include assets for which the given identifier is a prefix of their identifier.
	RANDOMIZED_ORDER										= 1 << 5,	///< Set this flag when you want to get assets in randomized order, this is useful for parallelized code.
	CHECK_CANCELLATION									= 1 << 6,	///< Set this flag when you want to check if the job is cancelled. if cancelled a OperationCancelledError is returned.
	PRIVATE_QUERY_REPOSITORY_VISIBILITY = 1 << 7, ///< Private: if this flag is given then the delegate is called at the beginning of each findasset if the repository, the const AssetDescription& points to a const AssetRespsitoryRef&
} MAXON_ENUM_FLAGS(ASSET_FIND_MODE);

//----------------------------------------------------------------------------------------
/// An AssetRepositoryInterface manages a set of assets:
/// - Assets can be looked up using their identifier and version.
/// - New assets or new asset versions can be stored.
/// - Each asset can have associated meta data which can be read and written.
/// - Observers for changes to the repository can be added.
///
/// An asset repository can have several base repositories which are used for the lookup
/// after lookup in the repository itself has finished. Cycles aren't allowed, so asset repositories
/// form a directed acyclic graph.
///
/// A repository which has another repository as (direct or indirect) base is said to be
/// /derived/ from that repository. Whenever an observable of a repository is triggered,
/// this is done for all derived repositories too.
///
/// The methods of AssetRepositoryInterface are thread-safe. This allows for concurrent modifications
/// and queries.
//----------------------------------------------------------------------------------------
class AssetRepositoryInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface, DataDictionaryObjectInterface)
{
	MAXON_INTERFACE(AssetRepositoryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.assetrepository");
public:
	//----------------------------------------------------------------------------------------
	/// Returns the identifier of this repository. Repository identifiers needn't be unique,
	/// but a repository must not have the same identifier as one of its (direct or indirect) bases.
	/// @return												The identifier of this repository.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Id& GetId() const;

	//----------------------------------------------------------------------------------------
	/// Returns an array holding all current base repositories of this repository.
	/// but a repository must not have the same identifier as one of its (direct or indirect) bases.
	/// @return												The identifier of this repository.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Array<AssetRepositoryRef> GetBases() const;

	//----------------------------------------------------------------------------------------
	/// Yields all derived repositories of this repository to #receiver
	/// (those which have this repository as direct base).
	/// @param[in] receiver						The receiver for derived repositories.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetDerived(const ValueReceiver<const AssetRepositoryRef&>& receiver) const;

	//----------------------------------------------------------------------------------------
	/// Initializes the base repositories of this repository. This function may only be called once
	/// right after the AssetRepositoryInterface instance has been created. It doesn't inform any
	/// observers.
	/// @param[in] bases							The bases of this repository.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InitBases(const Block<const AssetRepositoryRef>& bases);

	//----------------------------------------------------------------------------------------
	/// Adds #base to the list of base repositories of this repository. The observers
	/// for ObservableBaseChanged of this repository and its derived repositories are informed.
	/// @param[in] base								The base repository to add.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AddBase(const AssetRepositoryRef& base);

	//----------------------------------------------------------------------------------------
	/// Removes #base from the list of base repositories of this repository. The observers
	/// for ObservableBaseChanged of this repository and its derived repositories are informed.
	/// Nothing happens if this repository doesn't have #base as one of its bases.
	/// @param[in] base								The base repository to remove.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> RemoveBase(const AssetRepositoryRef& base);

	//----------------------------------------------------------------------------------------
	/// Finds the repository with the given identifier among this repository and its direct and
	/// indirect bases. If no such repository exists, a null reference is returned.
	/// @param[in] repoId							The identifier of the repository to find.
	/// @return												The found repository, or a null reference.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD AssetRepositoryRef FindRepository(const Id& repoId) const;

	//----------------------------------------------------------------------------------------
	/// Returns true if this repository is based on #other or #other itself, false otherwise.
	/// @param[in] other							A repository.
	/// @return												True if other is a direct or indirect base of this repository or this repository itself.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool IsBasedOnOrSame(const AssetRepositoryRef& other) const;

	//----------------------------------------------------------------------------------------
	/// Returns true if this repository is based a repository with identifier #other or has that identifier itself, false otherwise.
	/// @param[in] other							A repository identifier.
	/// @return												True if other denotes a direct or indirect base of this repository or this repository itself.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool IsBasedOnOrSame(const Id& other) const;

	//----------------------------------------------------------------------------------------
	/// Tells if this repository is writable or not.
	/// @return												True if this repository is writable, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsWritable() const;

	using LatestAssetMap = HashMap<Id, AssetDescription>;

	MAXON_METHOD Result<Bool> PrivateFindAssets(const Block<const Id>& types, const Id& aid, const Id& version, ASSET_FIND_MODE findMode,
		const ValueReceiver<const AssetDescription&>& assets, HashSet<const AssetRepositoryInterface*>& visited, LatestAssetMap& latestMap) const;

	//----------------------------------------------------------------------------------------
	/// PrivatePrefetchMetaData prefetches all meta data of the given type.
	/// @param[in] metaId							MetaData id to prefetch.
	/// @param[in] findMode						see ASSET_FIND_MODE.
	/// @param[in] visited						temp Hashmap.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> PrivatePrefetchMetaData(const InternedId& metaId, AssetMetaDataInterface::KIND kind, ASSET_FIND_MODE findMode, HashSet<const AssetRepositoryInterface*>& visited);

	//----------------------------------------------------------------------------------------
	/// Finds all assets matching the parameters:
	/// - If aid is set, only assets with that identifier are found (or which have the aid as prefix
	///		when ASSET_FIND_MODE::PREFIX is set), otherwise all assets.
	/// - If version is set, only assets with that version are found, otherwise
	///   - if ASSET_FIND_MODE::LATEST is set in findMode, only the latest asset version is found
	///   - if ASSET_FIND_MODE::ALL is set in findMode, all asset versions are found.
	/// - If ASSET_FIND_MODE::WITHOUT_BASES is set in findMode, then base repositories aren't taken into account.
	///   Otherwise they are considered after this repository.
	/// - If ASSET_FIND_MODE::WITH_DELETED is set in findMode, then also deleted assets are reported.
	///
	/// When version is given or ASSET_FIND_MODE::LATEST is used and a matching asset is found in a repository,
	/// assets in base repositories thereof aren't reported even if they are newer. So then an asset in a repository
	/// hides assets with the same identifier in base repositories. Assets with another identifier are still reported.
	///
	/// @param[in] type								The allowed asset type.
	/// @param[in] aid								The asset identifier to lookup, use an empty identifier to find all assets.
	/// @param[in] version						The version identifier to find, use an empty identifier to find all versions.
	/// @param[in] findMode						Flags for the lookup.
	/// @param[in] receiver						All found assets are reported to this receiver.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<Bool> FindAssets(const Id& type, const Id& aid, const Id& version, ASSET_FIND_MODE findMode, const ValueReceiver<const AssetDescription&>& receiver) const
	{
		return FindAssets(ToSingletonBlock(type), aid, version, findMode, receiver);
	}

	/// @copydoc FindAssets
	MAXON_FUNCTION Result<Bool> FindAssets(const AssetType& type, const Id& aid, const Id& version, ASSET_FIND_MODE findMode, const ValueReceiver<const AssetDescription&>& receiver) const;

	//----------------------------------------------------------------------------------------
	/// Finds all assets matching the parameters:
	/// - If aid is set, only assets with that identifier are found (or which have the aid as prefix
	///		when ASSET_FIND_MODE::PREFIX is set), otherwise all assets.
	/// - If version is set, only assets with that version are found, otherwise
	///   - if ASSET_FIND_MODE::LATEST is set in findMode, only the latest asset version is found
	///   - if ASSET_FIND_MODE::ALL is set in findMode, all asset versions are found.
	/// - If ASSET_FIND_MODE::WITHOUT_BASES is set in findMode, then base repositories aren't taken into account.
	///   Otherwise they are considered after this repository.
	/// - If ASSET_FIND_MODE::WITH_DELETED is set in findMode, then also deleted assets are reported.
	///
	/// When version is given or ASSET_FIND_MODE::LATEST is used and a matching asset is found in a repository,
	/// assets in base repositories thereof aren't reported even if they are newer. So then an asset in a repository
	/// hides assets with the same identifier in base repositories. Assets with another identifier are still reported.
	///
	/// @param[in] types							The allowed asset types.
	/// @param[in] aid								The asset identifier to lookup, use an empty identifier to find all assets.
	/// @param[in] version						The version identifier to find, use an empty identifier to find all versions.
	/// @param[in] findMode						Flags for the lookup.
	/// @param[in] receiver						All found assets are reported to this receiver.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> FindAssets(const Block<const Id>& types, const Id& aid, const Id& version, ASSET_FIND_MODE findMode, const ValueReceiver<const AssetDescription&>& receiver) const;

	//----------------------------------------------------------------------------------------
	/// Finds the asset with the given identifier in this repository and its base repositories.
	/// If version is set, this finds the asset with that version, otherwise it finds the latest asset.
	/// When a matching asset is found in a repository, assets in base repositories thereof aren't considered even if they are newer.
	///
	/// @param[in] type								The allowed asset type.
	/// @param[in] aid								The asset identifier to lookup.
	/// @param[in] version						The version identifier to find, use an empty identifier to find the latest version.
	/// @param[in] findMode						Flags for the lookup, only ASSET_FIND_MODE::WITHOUT_BASES and ASSET_FIND_MODE::WITH_DELETED make sense for this method.
	/// @return												The found asset, or a null reference.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<AssetDescription> FindLatestAsset(const Id& type, const Id& aid, const Id& version, ASSET_FIND_MODE findMode = ASSET_FIND_MODE::NONE) const;

	/// @copydoc FindLatestAsset
	MAXON_FUNCTION Result<AssetDescription> FindLatestAsset(const AssetType& type, const Id& aid, const Id& version, ASSET_FIND_MODE findMode = ASSET_FIND_MODE::NONE) const;

	//----------------------------------------------------------------------------------------
	/// GetDescription returns the AssetDescription of the given asset.
	/// @param[in] asset							Asset to query.
	/// @return                       AssetDescription on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<AssetDescription> GetDescription(const Asset& asset) const;

	//----------------------------------------------------------------------------------------
	/// Compares the versions of assets of this repository:
	/// - If #first is newer, returns COMPARERESULT::GREATER.
	/// - If #second is newer, returns COMPARERESULT::LESS.
	/// - If both denote the same asset version, returns COMPARERESULT::EQUAL.
	///
	/// Being newer isn't based on the time stamp, but on the order in which assets are stored.
	/// It also takes into account the update counter (AssetInterface::GetUpdate) when both
	/// assets have the same version identifier.
	///
	/// If both assets have different asset identifiers the method returns COMPARERESULT::INCOMPARABLE.
	/// If the assets don't belong to this repository, the result is unspecified.
	///
	/// @param[in] first							The first asset.
	/// @param[in] second							The second asset.
	/// @return												The result of the comparison of the versions.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD COMPARERESULT CompareVersions(const AssetBase& first, const AssetBase& second) const;

	//----------------------------------------------------------------------------------------
	/// Stores asset as a new version using the identifier #aid. Identifier, version and repository
	/// are set correspondingly at #asset, so #asset may point to a copy of the original object afterwards
	/// (Asset is a copy-on-write reference).
	///
	/// Observers of ObservableAssetStored of this repository and its derived repositories are informed.
	///
	/// @param[in] aid								The asset identifier to use.
	/// @param[in,out] asset					The asset object to store. This method sets identifier, version and repository of #asset.
	/// @param[in] metaData						Initial meta data to use for the asset.
	/// @return												The AssetDescription for the added asset.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<AssetDescription> StoreAsset(const Id& aid, Asset& asset, const AssetMetaData& metaData = GetZeroRef<AssetMetaData>());

	/// @copydoc StoreAsset
	template <typename ASSET, typename = typename std::enable_if<maxon::HasBaseDetector<typename ASSET::ReferencedType, AssetInterface>::value>::type>
	MAXON_FUNCTION Result<AssetDescription> StoreAsset(
		const Id& aid, ASSET& asset, const AssetMetaData& metaData = GetZeroRef<AssetMetaData>());

	/// @copydoc StoreAsset
	MAXON_METHOD Result<AssetDescription> OverwriteAsset(const Id& aid, Asset& asset, const AssetMetaData& metaData = GetZeroRef<AssetMetaData>());

	/// @copydoc StoreAsset
	template <typename ASSET, typename = typename std::enable_if<maxon::HasBaseDetector<typename ASSET::ReferencedType, AssetInterface>::value>::type>
	MAXON_FUNCTION Result<AssetDescription> OverwriteAsset(
		const Id& aid, ASSET& asset, const AssetMetaData& metaData = GetZeroRef<AssetMetaData>());

	//----------------------------------------------------------------------------------------
	/// Deletes the asset given by the identifier #aid. The previous versions still exist in the repository,
	/// this method just stores a delete marker so that FindAssets doesn't take those versions into account
	/// unless the ASSET_FIND_MODE::WITH_DELETED flag is given.
	/// For a complete removal of a specific version use EraseAsset.
	///
	/// Observers of ObservableAssetStored of this repository and its derived repositories are informed.
	///
	/// @param[in] aid								The asset to delete.
	/// @return												The AssetDescription which represents the delete marker.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<AssetDescription> DeleteAsset(const Id& aid);

	//----------------------------------------------------------------------------------------
	/// Permanently erases an asset version. Unlike DeleteAsset which marks an asset as deleted
	/// but keeps all previous versions this method completely removes any data of the given asset version.
	///
	/// Observers of ObservableAssetErased of this repository and its derived repositories are informed.
	///
	/// @param[in] asset							The asset version to erase from this repository.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> EraseAsset(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// Copies an asset including meta data to this repository using the identifier #aid for the copy.
	/// #source has to be an asset already stored in some repository. The version identifier of #source will be used for the
	/// copy even if this repository would normally derive a different identifier from the asset content.
	///
	/// Observers of ObservableAssetStored of this repository and its derived repositories are informed.
	///
	/// @param[in] aid								The asset identifier to use.
	/// @param[in] source							The source asset to copy.
	/// @param[in] addEncryption			True if the copy shall be stored in an encrypted way. The encryption has to be handled by the AssetType.
	/// @param[in] overwrite					True to overwrite the existing asset.
	/// @return												The AssetDescription of the copy.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<AssetDescription> CopyAsset(const Id& aid, const AssetDescription& source, Bool addEncryption = false, Bool overwrite = false);

	//----------------------------------------------------------------------------------------
	/// Stores #data for the meta data attribute #metaId of the given #asset.
	/// Observers of ObservableMetaDataStored of this repository and its derived repositories are informed.
	/// @param[in] asset							The asset for which a meta data value shall be set.
	/// @param[in] metaId							The identifier of the meta data attribute.
	/// @param[in] data								The value to set.
	/// @param[in] kind								The kind of the meta data.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> StoreMetaData(const AssetDescription& asset, const InternedId& metaId, ForwardingDataPtr&& data, AssetMetaDataInterface::KIND kind);

	//----------------------------------------------------------------------------------------
	/// Copies the file or directory #source as meta data for the meta data attribute #metaId of the given #asset.
	/// The value of the meta data attribute will be a Url which points to the local copy within the asset
	/// (i.e., not to #source) of the form @c{meta:///assetid/metaid.kind.extension}, so the file name extension
	/// of #source gets preserved.
	/// Observers of ObservableMetaDataStored of this repository and its derived repositories are informed.
	/// @param[in] asset							The asset for which a meta data value shall be set.
	/// @param[in] metaId							The identifier of the meta data attribute.
	/// @param[in] source							The source which shall be copied as meta data to #asset. Pass empty Url to remove the meta data.
	/// @param[in] kind								The kind of the meta data.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> StoreUrlMetaData(const AssetDescription& asset, const InternedId& metaId, const Url& source, AssetMetaDataInterface::KIND kind);

	//----------------------------------------------------------------------------------------
	/// Informs about the addition or removal of a base repository via AddBase and RemoveBase.
	/// The observers are called not only when this happens for this repository itself,
	/// but also when it happens for one of its base repositories.
	/// @param[in] base								The base repository.
	/// @param[in] added							True if base has been added, false if it has been removed.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableBaseChanged, (const AssetRepositoryRef& base, Bool added), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Informs about the storage of a new asset version. This includes StoreAsset and CopyAsset,
	/// but also the storage of a delete marker via DeleteAsset.
	/// The observers are called not only when this happens for this repository itself,
	/// but also when it happens for one of its base repositories.
	/// @param[in] asset							The description of the new asset version.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableAssetStored, (const AssetDescription& asset), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Informs about the erasure of an asset version, see EraseAsset.
	/// The observers are called not only when this happens for this repository itself,
	/// but also when it happens for one of its base repositories.
	/// @param[in] asset							The description of the erased asset version.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableAssetErased, (const AssetDescription& asset), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Informs about the update of an asset. An update happens when the asset uses references
	/// to other assets and those references are updated to newer versions of the referenced assets.
	/// No new asset version is created.
	/// The observers are called not only when this happens for this repository itself,
	/// but also when it happens for one of its base repositories.
	/// @param[in] asset							The updated asset.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableAssetUpdated, (const Asset& asset), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Informs about the storage of a meta data attribute value, see StoreMetaData.
	/// The observers are called not only when this happens for this repository itself,
	/// but also when it happens for one of its base repositories.
	/// @param[in] asset							The asset.
	/// @param[in] metaId							The identifier of the stored meta data attribute.
	/// @param[in] kind								The meta data kind.
	/// @param[in] prevData						The previous value of the attribute (may be empty).
	/// @param[in] newData						The new value of the attribute.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableMetaDataStored,
		(const AssetDescription& asset, const InternedId& metaId, AssetMetaDataInterface::KIND kind, const Data& prevData, const Data& newData),
		ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// Informs about the download state change in the repository.
	/// @param[in] repository					The repository with the changes assets.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(void, ObservableDownloadStateChanged, (const AssetRepositoryRef& repository, Bool finished), ObservableCombinerRunAllComponent);

	MAXON_METHOD Result<const GenericData&> GetCachedData(MoveDataPtr&& key, const Delegate<Result<GenericData>()>& callback);

	MAXON_METHOD Result<Id> GetDescriptionDatabaseId() const;

	MAXON_METHOD Result<DataDescription> LoadDescription(const Id& category, const LanguageRef& language, const AssetDescription& asset);

	MAXON_METHOD Result<DataDescription> LoadDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType);

	MAXON_FUNCTION Result<DataDescription> LoadDescription(const Id& category, const LanguageRef& language, const Id& dataType);

	MAXON_METHOD Result<DataDescriptionDefinition> LoadDescriptionDefinition(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// GetRepositoryName returns the name of the repository in the requested language.
	/// @param[in] language						Language to query.
	/// @return                       Name on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> GetRepositoryName(const LanguageRef& language, Bool addDetails) const;

	//----------------------------------------------------------------------------------------
	/// SetRepositoryName sets the name of the repository in the given language.
	/// @param[in] name								Name to set.
	/// @param[in] language						Language.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetRepositoryName(const String& name, const LanguageRef& language);

	MAXON_METHOD Result<const DerivedAssetRepositoryDataRef&> GetCachedData(MoveDataPtr&& key, const Delegate<Result<DerivedAssetRepositoryDataRef>()>& callback);

protected:
	//----------------------------------------------------------------------------------------
	/// Informs all observers of ObservableBaseChanged and calls HandleBaseChanged on all derived repositories.
	/// @param[in] base								The base repository.
	/// @param[in] added							True if base has been added, false if it has been removed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void HandleBaseChanged(const AssetRepositoryRef& base, Bool added);

	//----------------------------------------------------------------------------------------
	/// Informs all observers of ObservableAssetStored and calls HandleAssetStored on all derived repositories.
	/// @param[in] asset							The description of the new asset version.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void HandleAssetStored(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// Informs all observers of ObservableAssetErased and calls HandleAssetErased on all derived repositories.
	/// @param[in] asset							The description of the erased asset version.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void HandleAssetErased(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// Informs all observers of ObservableAssetUpdated and calls HandleAssetUpdated on all derived repositories.
	/// @param[in] asset							The updated asset.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void HandleAssetUpdated(const Asset& asset);

	//----------------------------------------------------------------------------------------
	/// Informs all observers of ObservableMetaDataStored and calls HandleMetaDataStored on all derived repositories.
	/// @param[in] asset							The asset.
	/// @param[in] metaId							The identifier of the stored meta data attribute.
	/// @param[in] kind								The meta data kind.
	/// @param[in] prevData						The previous value of the attribute (may be empty).
	/// @param[in] newData						The new value of the attribute.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void HandleMetaDataStored(const AssetDescription& asset, const InternedId& metaId, AssetMetaDataInterface::KIND kind, const Data& prevData, const Data& newData);

public:
	//----------------------------------------------------------------------------------------
	/// Informs all observers of ObservableDownloadStateChanged and calls HandleDownloadStateChanged on all derived repositories.
	/// @param[in] repository					The repository.
	/// @param[in] finished						True if finished
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void HandleDownloadStateChanged(const AssetRepositoryRef& repository, Bool finished);

	//----------------------------------------------------------------------------------------
	/// RequestUnloadRepository is called if the user requested to reload or remove the repository.
	/// This function should stop all running background threads/jobs to free references to this repo.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void RequestUnloadRepository();
};


class DerivedAssetRepositoryDataInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(DerivedAssetRepositoryDataInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.derivedassetrepositorydata");
public:
	//----------------------------------------------------------------------------------------
	/// Gets called when the base of the asset repository has been changed.
	/// @param[in] repo								The asset repository which owns the derived data.
	/// @param[in] base								The base repository.
	/// @param[in] added							True if base has been added, false if it has been removed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void HandleBaseChanged(const AssetRepositoryRef& repo, const AssetRepositoryRef& base, Bool added);

	//----------------------------------------------------------------------------------------
	/// Gets called when an asset has been stored.
	/// @param[in] asset							The description of the new asset version.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void HandleAssetStored(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// Gets called when an asset has been erased.
	/// @param[in] asset							The description of the erased asset version.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void HandleAssetErased(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// Gets called when an asset has been updated.
	/// @param[in] asset							The updated asset.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void HandleAssetUpdated(const Asset& asset);

	//----------------------------------------------------------------------------------------
	/// Gets called when meta data has been stored.
	/// @param[in] asset							The asset.
	/// @param[in] metaId							The identifier of the stored meta data attribute.
	/// @param[in] kind								The meta data kind.
	/// @param[in] prevData						The previous value of the attribute (may be empty).
	/// @param[in] newData						The new value of the attribute.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void HandleMetaDataStored(const AssetDescription& asset, const InternedId& metaId, AssetMetaDataInterface::KIND kind, const Data& prevData, const Data& newData);

	//----------------------------------------------------------------------------------------
	/// Informs all observers of ObservableDownloadStateChanged and calls HandleDownloadStateChanged on all derived repositories.
	/// @param[in] repository					The repository.
	/// @param[in] finished						True if finished
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void HandleDownloadStateChanged(const AssetRepositoryRef& repository, Bool finished);
};

//----------------------------------------------------------------------------------------
/// The base interface of AssetBaseWithUpdateInterface and AssetDescriptionInterface.
/// It inherits from AssetIdentifierInterface and adds methods to obtain the repository.
//----------------------------------------------------------------------------------------
class AssetBaseInterface : MAXON_INTERFACE_BASES(AssetIdentifierInterface)
{
	MAXON_INTERFACE(AssetBaseInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.assetbase");
public:
	//----------------------------------------------------------------------------------------
	/// Returns the identifier of the repository where this asset is stored.
	/// @return												Asset repository identifier (empty when the asset doesn't belong to a repository).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Id& GetRepositoryId() const;

	//----------------------------------------------------------------------------------------
	/// Returns the repository where this asset is stored.
	/// The implementation should use a weak reference to avoid circular references.
	/// @return												Asset repository (empty when the asset doesn't belong to a repository).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD AssetRepositoryRef GetRepository() const;
};


//----------------------------------------------------------------------------------------
/// An AssetDescription represents all meta information about an asset, namely its identifer and version,
/// the AssetMetaData and some further information. AssetRepositoryInterface::FindAssets yields
/// the found assets not as Asset, but as AssetDescription to avoid unnecessary loading of the assets.
/// When you really need the asset itself you have to call Load on the description.
//----------------------------------------------------------------------------------------
class AssetDescriptionInterface : MAXON_INTERFACE_BASES(AssetBaseInterface)
{
	MAXON_INTERFACE(AssetDescriptionInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.assetdescription");
public:
	//----------------------------------------------------------------------------------------
	/// Returns the Url where the asset is stored.
	/// @return												The Url of this asset, may be empty if the asset isn't accessible through a Url.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<const Url&> GetUrl() const;

	//----------------------------------------------------------------------------------------
	/// Loads the asset. The implementation may use caching to avoid repeated loading of the same asset.
	/// @param[in,out] updateLinks		nullptr if the asset shall be loaded as is, or a pointer to a Bool if asset links which
	///																use ASSET_UPDATE_POLICY::IMPLICIT shall be resolved to the latest version. The Bool is set to true
	///																by this method whenever there is a link where the resolved version differs from the original version.
	/// @return												The loaded asset.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Asset> Load(Bool* updateLinks) const;

	//----------------------------------------------------------------------------------------
	/// Loads the asset, thereby updating asset links which use ASSET_UPDATE_POLICY::IMPLICIT to the latest version.
	/// The implementation may use caching to avoid repeated loading of the same asset.
	/// @return												The loaded asset.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<Asset> Load() const;

	//----------------------------------------------------------------------------------------
	/// Returns the meta data of this asset.
	/// @return												The meta data of this asset.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const AssetMetaData& GetMetaData() const;

	//----------------------------------------------------------------------------------------
	/// Returns true if this asset description is a delete marker. Delete markers are stored in
	/// repositories upon call of AssetRepositoryInterface::DeleteAsset to indicate a deleted asset,
	/// but previous asset versions still exist in the repository.
	/// @return												True if this description represents a delete marker, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsDeleted() const;

	//----------------------------------------------------------------------------------------
	/// Stores #data for the meta data attribute #attr of this asset.
	/// Observers of AssetRepositoryInterface::ObservableMetaDataStored of the repository of the asset
	/// and its derived repositories are informed.
	/// @param[in] attr								The meta data attribute.
	/// @param[in] data								The value to set.
	/// @param[in] kind								The kind of the meta data.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> StoreMetaData(const InternedId& attr, ForwardingDataPtr&& data, AssetMetaDataInterface::KIND kind) const;

	/// @copydoc StoreMetaData
	template <typename ATTR> MAXON_FUNCTION Result<void> StoreMetaData(const ATTR& attr, typename ATTR::ValueType&& data, AssetMetaDataInterface::KIND kind) const
	{
		return StoreMetaData(attr.Get(), MoveDataPtr(std::move(data)), kind);
	}

	/// @copydoc StoreMetaData
	template <typename ATTR> MAXON_FUNCTION Result<void> StoreMetaData(const ATTR& attr, const typename ATTR::ValueType& data, AssetMetaDataInterface::KIND kind) const
	{
		return StoreMetaData(attr.Get(), ConstDataPtr(data), kind);
	}

	//----------------------------------------------------------------------------------------
	/// EraseMetaData removes meta data from the asset.
	/// @param[in] attr								The meta data attribute.
	/// @param[in] kind								The kind of the meta data.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	template <typename ATTR> MAXON_FUNCTION Result<void> EraseMetaData(const ATTR& attr, AssetMetaDataInterface::KIND kind) const
	{
		return StoreMetaData(attr.Get(), MoveDataPtr(), kind);
	}

	//----------------------------------------------------------------------------------------
	/// Copies the file or directory #source as meta data for the meta data attribute #metaId of this #asset.
	/// The value of the meta data attribute will be a Url which points to the local copy within the asset
	/// (i.e., not to #source) of the form @c{meta:///assetid/metaid.kind.extension}, so the file name extension
	/// of #source gets preserved.
	/// Observers of ObservableMetaDataStored of this repository and its derived repositories are informed.
	/// @param[in] metaId							The identifier of the meta data attribute.
	/// @param[in] source							The source which shall be copied as meta data to #asset. Pass empty Url to erase meta data.
	/// @param[in] kind								The kind of the meta data.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<void> StoreUrlMetaData(const InternedId& metaId, const Url& source, AssetMetaDataInterface::KIND kind) const;

	//----------------------------------------------------------------------------------------
	/// GetMetaString returns the translated string from a asset.
	/// @param[in] key								Attribute id to load. e.g. OBJECT::BASE:NAME.
	/// @param[in] languageRef				Optional language. By default the function uses the current language.
	/// @param[in] fallback						Fallback string if the asset has no name.
	/// @return                       String on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<String> GetMetaString(const InternedId& key, const LanguageRef& languageRef = GetPtrSizedZeroRef<LanguageRef>(), const String& fallback = GetPtrSizedZeroRef<String>()) const;

	//----------------------------------------------------------------------------------------
	/// StoreMetaString stores the name of an asset for a language.
	/// @param[in] key								Attribute id to save. e.g. OBJECT::BASE:NAME.
	/// @param[in] value							New string.
	/// @param[in] languageRef				Optional language. By default the function uses the current language.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> StoreMetaString(const InternedId& key, const String& value, const LanguageRef& languageRef) const;
};


//----------------------------------------------------------------------------------------
/// The base interface of AssetInterface and AssetReferenceInterface.
/// It inherits from AssetBaseInterface and adds a methods to obtain the update counter.
//----------------------------------------------------------------------------------------
class AssetBaseWithUpdateInterface : MAXON_INTERFACE_BASES(AssetBaseInterface)
{
	MAXON_INTERFACE(AssetBaseWithUpdateInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.assetbasewithupdate");
public:
	//----------------------------------------------------------------------------------------
	/// Returns the update counter of the asset. The update counter is incremented
	/// whenever an asset is updated because one of its references to other assets
	/// is updated to a newer version of the referenced asset. This does not lead to
	/// a newer repository version of the asset itself because the asset definition isn't changed.
	/// Therefore the version identifier stays the same, just the update counter changes.
	///
	/// The update counter is 0 for the asset which exacly matches the original version
	/// (returned by AssetDescriptionInterface::Load when it is called with a nullptr argument).
	///
	/// @return												Update counter of the asset.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetUpdate() const;
};


//----------------------------------------------------------------------------------------
/// AssetReference is needed for the asset update mechanism and represents a specific
/// updatable AssetLink within an asset, see AssetInterface::GetReferencedAssets.
//----------------------------------------------------------------------------------------
class AssetReferenceInterface : MAXON_INTERFACE_BASES(AssetBaseWithUpdateInterface)
{
	MAXON_INTERFACE(AssetReferenceInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.assetreference");
public:
	//----------------------------------------------------------------------------------------
	/// Returns the link which this AssetReference uses.
	/// @return												The AssetLink of this reference.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const AssetLink& GetLink() const;
};

/// @addtogroup ASSET_VERSION_VALIDITY
/// @ingroup group_enumeration
/// @{
enum class ASSET_VERSION_VALIDITY
{
	VALID,														///< Valid asset version.
	INVALID_HIGHER_VERSION_REQUIRED,	///< Invalid asset version: app version is too low: higher version required.
	INVALID_LOWER_VERSION_REQUIRED		///< Invalid asset version: app version is too high: lower version required.
} MAXON_ENUM_LIST(ASSET_VERSION_VALIDITY);
/// @}

//----------------------------------------------------------------------------------------
/// Version validity data returned by @ref AssetInterface::IsAssetVersionValid
//----------------------------------------------------------------------------------------
struct AssetVersionValidityData
{
	ASSET_VERSION_VALIDITY validity	= ASSET_VERSION_VALIDITY::VALID; ///< Validity result.
	Float assetVersionFrom		= 0.0; 																 ///< If version is invalid, this is the minimal version allowed.
	Float assetVersionTo			= 0.0; 																 ///< If version is invalid and if is greater than @formatConstant{0.0}, this is the maximal version allowed. If is equal to @formatConstant{0.0}, no upper limit.
	Float appCurrentVersion		= 0.0; 																 ///< Cinema 4D current version.
};

/// @addtogroup ASSET_LICENSE_VALIDITY
/// @ingroup group_enumeration
/// @{
enum class ASSET_LICENSE_VALIDITY
{
	VALID,									///< Valid asset license.
	INVALID_LICENSE_HIDDEN,	///< Invalid asset license and it's hidden.
	INVALID_LICENSE_VISIBLE ///< Invalid asset license but it's visible.
} MAXON_ENUM_LIST(ASSET_LICENSE_VALIDITY);
/// @}

//----------------------------------------------------------------------------------------
/// License validity data returned by @ref AssetInterface::IsAssetLicenseValid
//----------------------------------------------------------------------------------------
struct AssetLicenseValidityData
{
	ASSET_LICENSE_VALIDITY validity	= ASSET_LICENSE_VALIDITY::VALID; ///< Validity result.
	ASSETLICENSETYPE assetLicenseType	= ASSETLICENSETYPE::NONE;			 ///< If license is invalid, this is the asset license type.
	InternedId appLicenseType;																			 ///< If license is invalid, this is the Cinema 4D current license type. @see LICENSETYPES
};

//----------------------------------------------------------------------------------------
/// An Asset represents digital content which can be managed by an @ref AssetRepositoryInterface
/// "asset repository". The management includes versioning, meta data and automatic updates.
//----------------------------------------------------------------------------------------
class AssetInterface : MAXON_INTERFACE_BASES(AssetBaseWithUpdateInterface)
{
	MAXON_INTERFACE(AssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.asset");
public:
	//----------------------------------------------------------------------------------------
	/// Returns the built-in repository. This contains the built-in assets which are defined
	/// by program code (i.e., not by a data format to read them from a data stream).
	/// @return												Reference to the built-in repository.
	/// @see BuiltinAssetLoaders
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const AssetRepositoryRef& GetBuiltinRepository();

	//----------------------------------------------------------------------------------------
	/// Returns the application repository. The application repository uses the
	/// @ref GetBuiltinRepository "built-in repository" as base and adds the assets found in
	/// the resources of the asset.module.
	/// @return												Reference to the application repository.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const AssetRepositoryRef& GetApplicationRepository();

	//----------------------------------------------------------------------------------------
	/// Returns the asset repository in the user preferences folder. This repository is
	/// writable for the user.
	/// @return												Reference to the repository in the user preferences folder.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const UpdatableAssetRepositoryRef& GetUserPrefsRepository();

	//----------------------------------------------------------------------------------------
	/// Creates an asset repository for the given Url. If there already is a directory structure
	/// in the expected format it is read as far as needed to initialize the repository with the found
	/// assets, otherwise such a directory structure is created.
	/// @param[in] rid								The repository identifier. There mustn't be a base with the same identifier.
	/// @param[in] repoType						See AssetRepositoryTypes registry.
	/// @param[in] bases							The base repositories for the new repository.
	/// @param[in] url								The root directory to use for the repository.
	/// @param[in] writable						True if the repository shall be writable.
	/// @param[in] derivedInPrefs			True if derived meta data shall be stored in the user preferences folder. This is mandatory if #url is a read-only Url.
	/// @param[in] tempRepository			True if the repository should not be registered as a description database.
	/// @param[in] backgroundJob			Optional background job to report errors, warnings, progress, cancellation.
	/// @return												An asset repository stored at #url.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<UpdatableAssetRepositoryRef> CreateRepositoryFromUrl(const Id& rid, const Class<AssetRepositoryRef>& repoType, const Block<const AssetRepositoryRef>& bases, const Url& url, Bool writable, Bool derivedInPrefs, Bool tempRepository, const BackgroundEntryTuple& backgroundJob = {});

	//----------------------------------------------------------------------------------------
	/// Creates a UUID (universally unique identifier). If prefix is given, the returned identifier
	/// starts with prefix, followed by an \@ sign, followed by the UUID such as
	/// @c{base@5e75b5e319f64055ac5387490d7355c0}, otherwise it is a UUID only. If prefix
	/// already contains an \@ sign, only the part before that sign is used.
	///
	/// If compact is true, a Base64-encoding with $ and _ as last characters is used for the UUID instead of the default Hex encoding,
	/// and it's ensured that the resulting characters of the encoding don't start with a digit.
	/// This results in shorter UUIDs like @c{FR4pAc$UFR_jXb16rXadEB}.
	/// In compact mode and when there are dot characters in prefix, only the part of prefix after the last dot is used.
	/// @param[in] prefix							The prefix for the identifier, may be nullptr. Only the characters up to the first \@ sign are used.
	/// @param[in] compact						True if the shorter Base64-encoding shall be used, false for Hex encoding.
	/// @return												A new UUID. It is safe to assume that this UUID differs from any other UUID returned by this method.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Id> MakeUuid(const Char* prefix, Bool compact);

	//----------------------------------------------------------------------------------------
	/// AddRepositoryScope resolves the asset url and caching the assetdescription in the url.
	/// @param[in] url								Url to investigate.
	/// @param[in] repository					Repository to search.
	/// @return                       Modified url which contains the AssetDescription on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Url> AddRepositoryScope(const Url& url, const AssetRepositoryRef& repository);

	//----------------------------------------------------------------------------------------
	/// GetLanguageMetaDataId returns the standardized InternedId for the given languageid.
	/// @param[in] languageId					Language id.
	/// @return                       InternedId on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<InternedId> GetLanguageMetaDataId(const Id& languageId);

	//----------------------------------------------------------------------------------------
	/// GetVersionString returns the version string for the given asset.
	/// @param[in] asset							Asset to look at.
	/// @return                       Version string on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> GetVersionString(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// GetVersionString returns the version string for the given asset.
	/// @param[in] asset							Asset to look at.
	/// @return                       Version string on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> GetVersionString(const Asset& asset);

	//----------------------------------------------------------------------------------------
	/// Sets identifier, version and repository of this asset. This method should only be called
	/// by the owning asset repository when it stores an asset to establish the link between asset
	/// and repository.
	/// @param[in] aid								Identifier and version identifier of the asset.
	/// @param[in] update							Update counter, see AssetBaseWithUpdateInterface::GetUpdate.
	/// @param[in] repository					The repository which stored the asset.
	/// @param[in] url								An optional Url where the repository stored the asset.
	/// @MAXON_ANNOTATION{returnsThis}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetId(const IdAndVersion& aid, Int update, const AssetRepositoryRef& repository, const Url& url = GetPtrSizedZeroRef<Url>());

	//----------------------------------------------------------------------------------------
	/// Returns the AssetType of this asset.
	/// @return												The asset's type.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const AssetType& GetType() const;

	//----------------------------------------------------------------------------------------
	/// GetDescription returns the AssetDescription of the given Asset.
	/// @return                       AssetDescription on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<AssetDescription> GetDescription() const;

	//----------------------------------------------------------------------------------------
	/// Yields all direct references which this asset makes to other assets. The AssetReference objects
	/// are used later for the update mechanism: The method UpdatableAssetInterface::Update gets
	/// a block of tuples (AssetReference, AssetBase) as input, and each tuple indicates to which
	/// asset an AssetReference shall be updated. So for example if an asset
	/// has two links to the same asset this has to be reported as two AssetReference objects,
	/// and when only the first one is passed to UpdatableAssetInterface::Update only the
	/// first link has to be updated, while the second has to remain unchanged.
	///
	/// @param[in] onlyUpdatable			If true only references which use updatable links shall be reported (update policy different from ASSET_UPDATE_POLICY::NEVER), otherwise all references.
	/// @param[in] receiver						Receiver to which references are reported.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetReferencedAssets(Bool onlyUpdatable, const ValueReceiver<const AssetReference&>& receiver) const;

	//----------------------------------------------------------------------------------------
	/// Yields all possible AssetReference updates for this asset due to #updatedAssets to #receiver.
	/// This method finds all direct references which this asset makes to other assets, and
	/// checks if they are affected by the list of #updatedAssets. This check takes into account
	/// the update policy of the AssetLink used for the reference. Whenever there is an updatable
	/// AssetLink and #updatedAssets contains a newer version for that link, this is reported by a
	/// call to #receiver with the reference as first argument and the newer asset from #updatedAssets
	/// as second argument.
	///
	/// @param[in] updatedAssets			A block of assets with (potentially) newer versions.
	/// @param[in] receiver						Receiver to which all pending updates due to #updatedAssets are reported.
	/// @return												false if the receiver cancelled further evaluation, true otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> GetPendingUpdates(const Block<const AssetBase>& updatedAssets, const ValueReceiver<const AssetReference&, const AssetBase&>& receiver) const;

	//----------------------------------------------------------------------------------------
	/// Sets the meta data object to use for this asset. This method should only be called by
	/// the owning asset repository.
	/// @param[in] data								The meta data of the asset.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetMetaData(const AssetMetaData& data);

	//----------------------------------------------------------------------------------------
	/// Returns the meta data of this asset.
	/// @return												The meta data of this asset.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD AssetMetaData GetMetaData() const;

	//----------------------------------------------------------------------------------------
	/// Returns the asset description from a given url with the URLSCHEME_ASSET.
	/// @param[in] url								Url to search.
	/// @param[in] repository					Lookup repository.
	/// @return                       AssetDescription on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetDescription> ResolveAsset(const Url& url, const AssetRepositoryRef& repository);

	//----------------------------------------------------------------------------------------
	/// Returns the url to access the asset data.
	/// e.g. asset:///file_634545662344
	/// @param[in] asset						asset to convert.
	/// @param[in] isLatest					True if the asset is the latest asset. In that case the version will not be added to the url.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Url> GetAssetUrl(const AssetDescription& asset, Bool isLatest);

	//----------------------------------------------------------------------------------------
	/// Checks if the asset is valid for the current license and program version.
	/// @param[in] asset							Asset to check
	/// @return                       @trueOtherwiseFalse{if asset is valid}
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> IsAssetValid(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// Checks if the asset is visible for the current license and program version.
	/// @param[in] asset							Asset to check
	/// @return                       @trueOtherwiseFalse{if asset is visible}
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> IsAssetVisible(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// Checks if the asset is valid for the current program version.
	/// @param[in] asset							Asset to check
	/// @return                       Version validity result.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetVersionValidityData> IsAssetVersionValid(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// Checks if the asset is valid for the current license.
	/// @param[in] asset							Asset to check
	/// @return                       License validity result.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetLicenseValidityData> IsAssetLicenseValid(const AssetDescription& asset);

	//----------------------------------------------------------------------------------------
	/// Checks if the asset idVersion can be found in the given searchRepository to resolve missing assets
	/// @param[in] searchRepository		Repository to search for the asset
	/// @param[in] typeId							Type of the asset
	/// @param[in] idVersion					Id and version of the asset
	/// @param[in] assetCreationDate	[optional] Argument with the creation date of the asset. Pass UniversalDateTime() when unknown.
	/// @param[in] checked						HashSet to prevent stackoverflow.
	/// @param[in] callbackFound			[optional] Callback that is called if the asset could be found. It might happen that the passed asset is the 
	///																renamed/updated version of the searched one.
	/// @param[in] callbackMissing		[optional] Callback that is called if the asset could not be found.
	/// @return												OK on success.
	static MAXON_METHOD Result<void> ResolveAssetsWithMissingAssets(const AssetRepositoryRef& searchRepository, const Id& typeId, const IdAndVersion& idVersion, const UniversalDateTime& assetCreationDate, HashSet<IdAndVersion>& checked, const Delegate<Result<void>(const AssetDescription&, HashSet<IdAndVersion>& checked)>& callbackFound, const Delegate<Result<void>(Bool outdated)>& callbackMissing);
};


//----------------------------------------------------------------------------------------
/// This base component can be used by implementations of Asset.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(ComponentDescriptor, AssetBaseComponent, "net.maxon.component.assetbase");


//----------------------------------------------------------------------------------------
/// An UpdatableAsset is an Asset which supports the update of its updatable references
/// to other assets to newer versions. Such an update doesn't create a new repository version
/// of the asset because the asset definition itself isn't changed, only the references
/// (represented by AssetLink) point to newer assets.
//----------------------------------------------------------------------------------------
class UpdatableAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(UpdatableAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.updatableasset");
public:
	//----------------------------------------------------------------------------------------
	/// Updates the given references of this asset to point to the corresponding assets.
	/// The references have to use updatable AssetLink objects (their update policy must not
	/// be ASSET_UPDATE_POLICY::NEVER). Afterwards the @ref GetUpdate "update counter"
	/// is incremented.
	/// @param[in] updates						The updates to apply as a block of the references and their new targets.
	/// @param[in] repository					The repository to which this asset belongs. @c{asset.GetRepository()}
	///																will be nullptr during the update because the asset is in mutable state.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Update(const Block<const Tuple<AssetReference, AssetBase>>& updates, const AssetRepositoryRef& repository);
};


//----------------------------------------------------------------------------------------
/// A tuple where the asset description represents an asset in a repository and the array
/// lists other assets to which the asset's references can be updated. For example if
/// asset A has links to assets B1, C1 but there are newer versions B2, C2,
/// then this is represented by the tuple (A, [B2, C2]).
//----------------------------------------------------------------------------------------
using AssetRepositoryUpdate = Tuple<AssetDescription, BaseArray<AssetBase>>;

//----------------------------------------------------------------------------------------
/// Asset repository which allows to update assets.
//----------------------------------------------------------------------------------------
class UpdatableAssetRepositoryInterface : MAXON_INTERFACE_BASES(AssetRepositoryInterface)
{
	MAXON_INTERFACE(UpdatableAssetRepositoryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.updatableassetrepository");
public:
	//----------------------------------------------------------------------------------------
	/// GetPendingUpdates returns an array with a list of unsaved changes.
	/// @param[in] reset							True to reset the changes.
	/// @return                       Array on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<AssetRepositoryUpdate>> GetPendingUpdates(Bool reset) const;

	//----------------------------------------------------------------------------------------
	/// Update applies the updates to the repository.
	/// @param[in] updates						Updates to process
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Update(const Block<const AssetRepositoryUpdate>& updates);
};

enum class REPOSITORYINDEXSTATE
{
	NONE,
	PENDING,
	RUNNING,
	EXISTS,
} MAXON_ENUM_LIST(REPOSITORYINDEXSTATE);

//----------------------------------------------------------------------------------------
/// Repository which allows to write an index.
//----------------------------------------------------------------------------------------
class CompactableAssetRepositoryInterface : MAXON_INTERFACE_BASES(AssetRepositoryInterface)
{
	MAXON_INTERFACE(CompactableAssetRepositoryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.compactableassetrepository");
public:
	//----------------------------------------------------------------------------------------
	/// Compact generates an index for a repository.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Compact();

	//----------------------------------------------------------------------------------------
	/// DeleteIndexFiles removes all index files.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> DeleteIndexFiles();

	//----------------------------------------------------------------------------------------
	/// Compact generates an index for a repository in a async background job.
	/// param[in] delay								Optional delay after which time the compact should run. TimeValue() to run immediatly.
	/// param[in] backgroundJob				Optional backgroundJob to use given job. Nullptr to create a backgroundjob internally.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CompactInBackground(const TimeValue& delay, const BackgroundProgressRef& backgroundJob);

	//----------------------------------------------------------------------------------------
	/// GetIndexState returns the state of the database index.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD REPOSITORYINDEXSTATE GetIndexState();
};


class FileAsset;

//----------------------------------------------------------------------------------------
/// This interface represents a file asset, so a plain file (or directory) stored in an asset repository.
//----------------------------------------------------------------------------------------
class FileAssetInterface : MAXON_INTERFACE_BASES(AssetInterface)
{
	MAXON_INTERFACE(FileAssetInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.fileasset");

public:
	//----------------------------------------------------------------------------------------
	/// The Url to access the file which is wrapped by this asset.
	/// @return												The Url of the file (or directory).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Url& GetUrl() const;

	//----------------------------------------------------------------------------------------
	/// Creates a new FileAsset for the given Url. The returned file asset doesn't belong to a
	/// repository, you have to store it afterwards at a repository. This will change the Url to
	/// a Url within the repository.
	/// @param[in] url								The Url of the file (or directory) which shall be made an asset.
	/// @return												The FileAsset wrapping #url.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<FileAsset> Create(const Url& url);
};

namespace AssetTypes
{
	//----------------------------------------------------------------------------------------
	/// The File asset type allows to store files and directories as an asset in an asset repository.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(AssetType, File, "net.maxon.assettype.file");
};


//----------------------------------------------------------------------------------------
/// A BuiltinAssetReceiver receives built-in assets from a BuiltinAssetLoaderNew.
/// metaUrl can be left empty, in that case only USER and DERIVED meta data can be written.
/// Non-user, non-derived meta data will be written to metaUrl, but the option
/// @c g_builtinRepositoryWritable has to be enabled to allow this.
/// @param[in] asset							The asset to receive.
/// @param[in] meta								Built-in meta data for the asset.
/// @param[in] metaUrl						An optional Url where additional meta data can be written to.
/// @return												false if the receiver cancelled further evaluation, true otherwise.
//----------------------------------------------------------------------------------------
using BuiltinAssetReceiver = Delegate<Result<Bool>(const Asset& asset, const DataDictionary& meta, const Url& metaUrl)>;

//----------------------------------------------------------------------------------------
/// A BuiltinAssetLoaderNew is used by the @ref AssetInterface::GetBuiltinRepository "built-in asset repository"
/// to find built-in assets. You can register such a loader at the BuiltinAssetLoadersNew registry
/// to add new built-in assets.
/// @param[in] types							The allowed asset types.
/// @param[in] aid								The asset identifier to lookup, use an empty identifier to find all assets.
/// @param[in] findMode						Flags for the lookup.
/// @param[in] receiver						All found assets (plus their meta data and an optional Url to store persistent meta data) are reported to this receiver.
/// @return												false if the receiver cancelled further evaluation, true otherwise.
//----------------------------------------------------------------------------------------
using BuiltinAssetLoaderNew = Delegate<Result<Bool>(const Block<const Id>& types, const Id& aid, ASSET_FIND_MODE findMode,
																								 const BuiltinAssetReceiver& receiver)>;

using BuiltinAssetLoader = Delegate<Result<Bool>(const Block<const Id>& types, const Id& aid, ASSET_FIND_MODE findMode, const ValueReceiver<const Asset&, const DataDictionary&>& receiver)>;

//----------------------------------------------------------------------------------------
/// The @ref AssetInterface::GetBuiltinRepository "built-in asset repository" uses this registry to find built-in assets.
/// When its FindAssets method is invoked it forwards the call to each of the registered loaders.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(BuiltinAssetLoaderNew, BuiltinAssetLoadersNew, "net.maxon.registry.builtinassetloaders2");

MAXON_REGISTRY(BuiltinAssetLoader, BuiltinAssetLoaders, "net.maxon.registry.builtinassetloaders");

MAXON_REGISTRY(Class<AssetRepositoryRef>, AssetRepositoryTypes, "net.maxon.registry.assetrepositorytypes");

#include "assets1.hxx"

namespace AssetRepositoryTypes
{
	MAXON_DECLARATION(Class<AssetRepositoryRef>, AssetDatabase, "net.maxon.assets.repositorytype.database");
}

//----------------------------------------------------------------------------------------
/// A base implementation class for a decorator of AssetRepositoryRef.
/// You can use this class as base class whenever you implement such a decorator.
/// The class forwards calls of all methods of AssetRepositoryInterface to the decorated object.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<AssetRepositoryRef>, AssetRepositoryDecoratorBaseClass, "net.maxon.class.assetrepositorydecoratorbase");

//----------------------------------------------------------------------------------------
/// An implementation class for a decorator of AssetRepositoryRef where the decorated repository is held by a weak reference.
/// The class forwards calls of all methods of AssetRepositoryInterface to the decorated object.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<AssetRepositoryRef>, WeakAssetRepositoryDecoratorClass, "net.maxon.class.weakassetrepositorydecorator");

#include "assets2.hxx"

template <typename ASSET, typename> inline Result<AssetDescription> AssetRepositoryInterface::StoreAsset(const Id& aid, ASSET& asset, const AssetMetaData& metaData)
{
	return StoreAsset(aid, reinterpret_cast<Asset&>(asset), metaData);
}

template <typename ASSET, typename> inline Result<AssetDescription> AssetRepositoryInterface::OverwriteAsset(const Id& aid, ASSET& asset, const AssetMetaData& metaData)
{
	return OverwriteAsset(aid, reinterpret_cast<Asset&>(asset), metaData);
}

inline Result<Bool> AssetRepositoryInterface::FindAssets(const AssetType& type, const Id& aid, const Id& version, ASSET_FIND_MODE findMode, const ValueReceiver<const AssetDescription&>& assets) const
{
	return FindAssets(ToSingletonBlock(type.GetId()), aid, version, findMode, assets);
}

inline Result<AssetDescription> AssetRepositoryInterface::FindLatestAsset(const AssetType& type, const Id& aid, const Id& version, ASSET_FIND_MODE findMode) const
{
	return FindLatestAsset(type.GetId(), aid, version, findMode);
}

//----------------------------------------------------------------------------------------
/// Tuple with d&d asset data
/// AssetDescription: asset
/// Url: of the asset
/// String: searchString at the time when the d&d was initiated.
//----------------------------------------------------------------------------------------
using DndAsset = Tuple<AssetDescription, Url, String /* searchString */>;

//----------------------------------------------------------------------------------------
/// GetAssetUrl returns the url of a DndAsset.
/// @param[in] asset							Drag&Drop asset to check.
/// @return                       Url on success.
//----------------------------------------------------------------------------------------
Url GetAssetUrl(const DndAsset& asset);

//----------------------------------------------------------------------------------------
/// Mark the asset as used and increment the usage counter.
/// This function will update the ASSETMETADATA::Uage meta data by increasing the count and date
/// @param[in] asset							Asset to mark.
/// @param[in] incCount						True to update the count.
/// @param[in] updateDate					True to update the usage count.
/// @return                       OK on success.
//----------------------------------------------------------------------------------------
Result<void> UpdateAssetUsage(const AssetDescription& asset, Bool incCount = true, Bool updateDate = true);

//----------------------------------------------------------------------------------------
/// IdToIdAndVersion helper function to convert a compacted id back to an id and version.
/// @param[in] id									Compacted id.
/// @return                       Extracted Id and version on success.
//----------------------------------------------------------------------------------------
Result<IdAndVersion> IdToIdAndVersion(const Id& id);

//----------------------------------------------------------------------------------------
/// IdAndVersionToId compacts an IdAndVersion into a id.
/// @param[in] assetId						Id to compact.
/// @return                       Id on success.
//----------------------------------------------------------------------------------------
Result<Id> IdAndVersionToId(const IdAndVersion& assetId);

//----------------------------------------------------------------------------------------
/// IdToIdAndVersionWithRepository calls IdToIdAndVersion and adds the repository ontop.
/// @param[in] id									Id to extract.
/// @param[in] lookupRepository		Repository to look at.
/// @return                       Tuple<AssetRepositoryRef, IdAndVersion, Bool> on success. Bool: limitRepository
//----------------------------------------------------------------------------------------
Result<Tuple<AssetRepositoryRef, IdAndVersion, Bool>> IdToIdAndVersionWithRepository(const Id& id, const AssetRepositoryRef& lookupRepository);

//----------------------------------------------------------------------------------------
/// IdAndVersionToIdWithRepository inverse of IdToIdAndVersionWithRepository.
/// @param[in] assetId						AssetId to compact.
/// @param[in] repository					Repository to use.
/// @return                       OK on success.
//----------------------------------------------------------------------------------------
Result<Id> IdAndVersionToIdWithRepository(const IdAndVersion& assetId, const AssetRepositoryRef& repository);

}

#endif // ASSETS_H__
