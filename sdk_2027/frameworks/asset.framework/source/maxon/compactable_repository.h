#ifndef COMPACTABLE_REPOSITORY_H__
#define COMPACTABLE_REPOSITORY_H__

#include "maxon/assets.h"

namespace maxon
{

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
	MAXON_INTERFACE(CompactableAssetRepositoryInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.compactableassetrepository", MAXON_IMPLEMENTATION_MODULE("net.maxon.asset"));

public:
	//----------------------------------------------------------------------------------------
	/// Generates an index for the current state of this repository. This will generate the folder `_index`
	/// at the root URL of the repository, and that folder contains the compacted structure
	/// of the repository and all meta data as binary, json and .dat format.
	///
	/// This method updates the repository itself. If you want to write the index without changing
	/// the repository, use WriteIndex.
	///
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Compact();

	//----------------------------------------------------------------------------------------
	/// DeleteIndexFiles removes all index files.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> DeleteIndexFiles();

	//----------------------------------------------------------------------------------------
	/// Compact generates an index for a repository in a async background job.
	/// @param[in] delay							Optional delay after which time the compact should run. TimeValue() to run immediatly.
	/// @param[in] backgroundJob			Optional backgroundJob to use given job. Nullptr to create a backgroundjob internally.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CompactInBackground(const TimeValue& delay, const BackgroundProgressRef& backgroundJob);

	//----------------------------------------------------------------------------------------
	/// GetIndexState returns the state of the database index.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD REPOSITORYINDEXSTATE GetIndexState();

	//----------------------------------------------------------------------------------------
	/// Generates an index for the current state of this repository. This will generate the folder `_index`
	/// at the given URL, and that folder contains
	/// - the compacted list of all assets and their versions.
	/// - the compacted meta data of all assets in binary and json format. This information is used to speed up loading of meta data.
	/// - the `index.dat` file with lists all files of the repository which are needed to load it in compacted form,
	/// 	including the newly created compacted meta data files.
	///   This file isn't used by asset repositories themselves, but by AssetDataBasesInterface::CreateRamDiskCache.
	///
	/// Unlike Compact(), this method doesn't update the repository itself.
	///
	/// You can pass an additional base repository. Then the generated `index.dat` will also list the files of that base.
	/// This is useful for the scenario where you have a local repository with new assets and want to prepare an upload of those
	/// new assets to the base repository's file storage. In that case the incremental flag is used:
	/// - When true, only the asset list and meta data of this repository is compacted to a folder of the name `from-to`, where from and to
	///   describe the range of version numbers of this repository. It is an error if there's an overlap with the range of version
	///   numbers of the base repository.
	/// - When false, the asset list and meta data of this repository and the base is written.
	/// In both cases, `index.dat` will contain the files of this repository and the base.
	///
	/// @param[in] dest					      A url where you want the `_index` to be generated.
	/// @param[in] baseToInclude      An optional base repository if you want to write a merged index of base and this repository.
	/// @param[in] incremental	      True if you want to write the meta data of just this repository (but `index.dat` is written for this and base).
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> WriteIndex(const Url& dest, const AssetRepositoryRef& baseToInclude, Bool incremental) const;
};


#include "compactable_repository1.hxx"

#include "compactable_repository2.hxx"

}

#endif // COMPACTABLE_REPOSITORY_H__
