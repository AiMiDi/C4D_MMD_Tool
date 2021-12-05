#ifndef LAZYLANGUAGESTRINGDATADESCRIPTION_H__
#define LAZYLANGUAGESTRINGDATADESCRIPTION_H__

#include "maxon/assets.h"
#include "maxon/datadescriptiondefinition.h"



namespace maxon
{

class Asset;

using LanguageDictionary = DataDictionary; // key == [Id] of the LanguageRef, Value = [DataDictionary]

//----------------------------------------------------------------------------------------
/// Interface to manage lazy loading of LanguageStringDataDescriptionDefinition for description strings.
//----------------------------------------------------------------------------------------
class LazyLanguageStringDataDescriptionDefinitionInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(LazyLanguageStringDataDescriptionDefinitionInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.lazylanguagestringdatadescriptiondefinition");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the description of the given language.
	/// @param[in] languageId					Id of the language to load.
	/// @return												DataDescriptionDefinition on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDescriptionDefinition> Get(const Id& languageId) const;

	//----------------------------------------------------------------------------------------
	/// Stores the description for the given language.
	/// @param[in] languageId					Id of the language to store.
	/// @param[in] description				Description to store.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(const Id& languageId, const DataDescriptionDefinition& description);

	//----------------------------------------------------------------------------------------
	/// Sets the asset from which the definition shall be loaded lazily.
	/// @param[in] meta								Asset meta data to use for loading the strings.
	/// @param[in] path								Relative path of the description within the asset.
	/// @return												DataDescriptionDefinition on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetMetaData(const AssetMetaData& meta, const CString& path);

	//----------------------------------------------------------------------------------------
	/// Loads all string resources from the meta data into memory (e.g. for copying data).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> LoadAll();

	//----------------------------------------------------------------------------------------
	/// Returns all descriptions to export.
	/// @return												LanguageStringDataDescriptionDefinition on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<LanguageStringDataDescriptionDefinition> GetMetaData() const;

	//----------------------------------------------------------------------------------------
	/// Helper function to return the default value for an empty cow object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const LazyLanguageStringDataDescriptionDefinitionInterface* NullValuePtr();
};

//----------------------------------------------------------------------------------------
/// Interface to manage lazy loading of LanguageDictionary for description strings.
//----------------------------------------------------------------------------------------
class LazyLanguageDictionaryInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(LazyLanguageDictionaryInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.lazylanguagedictionary");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the description of the given language.
	/// @param[in] languageId					Id of the language to load.
	/// @return												DataDescriptionDefinition on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDictionary> Get(const Id& languageId) const;

	//----------------------------------------------------------------------------------------
	/// Stores the description for the given language.
	/// @param[in] languageId					Id of the language to store.
	/// @param[in] description				Description to store.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(const Id& languageId, const DataDictionary& description);

	//----------------------------------------------------------------------------------------
	/// Sets the asset from which the description shall be loaded lazily.
	/// @param[in] meta								Asset meta data to use for loading the strings.
	/// @param[in] path								Relative path of the description within the asset.
	/// @return												DataDescriptionDefinition on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetMetaData(const AssetMetaData& meta, const CString& path);

	//----------------------------------------------------------------------------------------
	/// Loads all string resources from the meta data into memory (e.g. for copying data).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> LoadAll();

	//----------------------------------------------------------------------------------------
	/// Returns all descriptions to export.
	/// @return												LanguageDictionary on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<LanguageDictionary> GetMetaData() const;

	//----------------------------------------------------------------------------------------
	/// Helper function to return the default value for an empty cow object.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const LazyLanguageDictionaryInterface* NullValuePtr();
};

#include "lazylanguagestringdatadescription1.hxx"
#include "lazylanguagestringdatadescription2.hxx"

MAXON_DECLARATION(LazyLanguageStringDataDescriptionDefinition, LazyLanguageStringDataDescriptionDefinitionClass, "net.maxon.class.lazylanguagestringdatadescriptiondefinition");
MAXON_DECLARATION(LazyLanguageDictionary, LazyLanguageDictionaryClass, "net.maxon.class.lazylanguagedictionary");

}

#endif // LAZYLANGUAGESTRINGDATADESCRIPTION_H__
