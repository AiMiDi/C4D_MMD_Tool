#ifndef DATADESCRIPTIONPRESETSTORAGE_H__
#define DATADESCRIPTIONPRESETSTORAGE_H__

#include "maxon/hashmap.h"
#include "maxon/basearray.h"
#include "maxon/datadictionary.h"
#include "maxon/assets.h"


namespace maxon
{


using PresetStorage = DataDictionary;
using DataDescriptionEntry = DataDictionary;

//----------------------------------------------------------------------------------------
/// Helper class to handle loading and saving of presets.
//----------------------------------------------------------------------------------------
class DataDescriptionPresetStorageInterface
{
	MAXON_INTERFACE_NONVIRTUAL(DataDescriptionPresetStorageInterface, MAXON_REFERENCE_NONE, "net.maxon.interface.datadescriptionpresetstorage");

public:
	//----------------------------------------------------------------------------------------
	/// LoadPreset reads a preset from the database.
	/// @param[in] repository					Repository to search for presets (including it's bases).
	/// @param[in] presetIdentifier		Identifier to check.
	/// @param[in] presetName					Name of the preset.
	/// @return												PresetStorage on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<PresetStorage> LoadPreset(const AssetRepositoryRef& repository, const Id& presetIdentifier, const Id& presetName);

	//----------------------------------------------------------------------------------------
	/// StorePreset stores a preset under the given scope and id in the database.
	/// @param[in] repository					Repository to search for presets (including it's bases).
	/// @param[in] presetIdentifier		Identifier to check.
	/// @param[in] presetName					Name of the preset.
	/// @param[in] presetData					Data to store.
	/// @return												AssetDescription on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<AssetDescription> StorePreset(const AssetRepositoryRef& repository, const Id& presetIdentifier, const Id& presetName, const PresetStorage& presetData);

	//----------------------------------------------------------------------------------------
	/// DeletePreset deletes a preset from the database.
	/// @param[in] repository					Repository to search for presets (including it's bases).
	/// @param[in] presetIdentifier		Identifier to check.
	/// @param[in] presetName					Name of the preset.
	/// @return												true if the preset could be deleted. false if the repository which stores the asset is write protected.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> DeletePreset(const AssetRepositoryRef& repository, const Id& presetIdentifier, const Id& presetName);

	//----------------------------------------------------------------------------------------
	/// Returns all preset identifiers registered under the given scope
	/// @param[in] repository					Repository to search for presets (including it's bases).
	/// @return												Array of Ids on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Id>> GetPresetIdentifiers(const AssetRepositoryRef& repository);

	//----------------------------------------------------------------------------------------
	/// Returns all stored preset ids.
	/// @param[in] repository					Repository to search for presets (including it's bases).
	/// @param[in] presetIdentifier		Identifier to check.
	/// @return												Array of preset identifiers on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Id>> GetPresets(const AssetRepositoryRef& repository, const Id& presetIdentifier);

	//----------------------------------------------------------------------------------------
	/// Returns all stored attribute ids of a given preset identifier database.
	/// @param[in] repository					Repository to search for presets (including it's bases).
	/// @param[in] presetIdentifier		Identifier to check.
	/// @return												Array of attribute ids on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<HashSet<InternedId>> GetPresetAttributes(const AssetRepositoryRef& repository, const Id& presetIdentifier);

	//----------------------------------------------------------------------------------------
	/// Returns the localized string of the preset name.
	/// @param[in] repository					Repository to search for presets (including it's bases).
	/// @param[in] presetIdentifier		Identifier to check.
	/// @param[in] presetName					Name of the preset.
	/// @param[in] language						Language to find.
	/// @return												Localized String on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> GetPresetName(const AssetRepositoryRef& repository, const Id& presetIdentifier, const Id& presetName, const LanguageRef& language);

	//----------------------------------------------------------------------------------------
	/// Sets the localized string of the preset name.
	/// @param[in] assetDescription		Asset to modify.
	/// @param[in] presetName					Name of the preset.
	/// @param[in] name								Localized String for the given language.
	/// @param[in] language						Language to find.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> SetPresetName(const AssetDescription& assetDescription, const Id& presetName, const String& name, const LanguageRef& language);
};

#include "datadescriptionpresetstorage1.hxx"
#include "datadescriptionpresetstorage2.hxx"

}

#endif // DATADESCRIPTIONPRESETSTORAGE_H__
