#ifndef DATADESCRIPTIONDEFINITIONDATABASEIMPL_H__
#define DATADESCRIPTIONDEFINITIONDATABASEIMPL_H__

#include "maxon/datadescriptiondefinition.h"
#include "maxon/datadescriptiondefinitiondatabase.h"



namespace maxon
{

//----------------------------------------------------------------------------------------
/// Allows to create different implementations of data description database stores.
//----------------------------------------------------------------------------------------
class DataDescriptionDefinitionDatabaseImplInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(DataDescriptionDefinitionDatabaseImplInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.datadescriptiondefinitiondatabaseimpl");

public:
	//----------------------------------------------------------------------------------------
	/// checks if the data base contains the datatype.
	/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
	/// @param[in] dataType						Data type id to load.
	/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @return												True if the data base contains the data type.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool Contains(const Id& category, const IdAndVersion& dataType, const LanguageRef& language) const;

	//----------------------------------------------------------------------------------------
	/// Loads a description from the registered databases.
	/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
	/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] dataType						Data type id to load.
	/// @param[out] foundInDatabase		Optional: Pointer to an Id of the database where the entry was found.
	/// @return												DataDescriptionDefinition on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDescriptionDefinition> LoadDescription(LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language,
		const IdAndVersion& dataType, Id* foundInDatabase = nullptr) const;

	//----------------------------------------------------------------------------------------
	/// Stores the given description under the given values.
	/// @param[in] databaseId					Data base id (see RegisterDatabase()/GetRegisteredDatabases()).
	/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
	/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] dataType						Data type id to store.
	/// @param[in] description				Description data to store.
	/// @return												Tuple with a Bool (changed or not) and the pointer of the stored description if changed. Error otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Tuple<Bool, DataDescriptionDefinition*>> StoreDescription(const Id& databaseId, const Id& category,
		const LanguageRef& language, const IdAndVersion& dataType, const DataDescriptionDefinition& description,
		const DataDescriptionDefinition& overwrittenDescription, Bool usePendingSystem);

	//----------------------------------------------------------------------------------------
	/// DeleteDescription deletes a description from the database.
	/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
	/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] dataType						Data type id to delete.
	/// @return												True/False on success. True means the description was found and deleted. False if the description was not found.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType);

	//----------------------------------------------------------------------------------------
	/// Return all registered descriptions.
	/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
	/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @return												Array on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<IdAndVersion>> GetRegisteredDescriptions(const Id& category, const LanguageRef& language) const;

	//----------------------------------------------------------------------------------------
	/// Returns all registered languages of this database.
	/// @return												Array with languages on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<LanguageRef>> GetRegisteredLanguages() const;

	//----------------------------------------------------------------------------------------
	/// Save all databases.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> WriteDataBases() const;

	//----------------------------------------------------------------------------------------
	/// Renames a id in all databases to the new id.
	/// @param[in] oldId							Old id to rename
	/// @param[in] newId							Id to replace.
	/// @return												Number of values that were renamed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> RenameId(const Id& oldId, const Id& newId);

	//----------------------------------------------------------------------------------------
	/// Renames an attribute in all databases.
	/// @param[in] oldId							Old attribute key.
	/// @param[in] newId							New attribute key.
	/// @return												Number of values that were renamed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> RenameAttribute(const InternedId& oldId, const InternedId& newId);

	//----------------------------------------------------------------------------------------
	/// Checks if the given id is unique in all data bases.
	/// @param[in] searchId						Id to search for.
	/// @return												True if the id is unique. False if the id already exists.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> CheckUniqueAttributeName(const InternedId& searchId) const;

	//----------------------------------------------------------------------------------------
	/// Updates the description from the given DataDescriptionDefinition.
	/// @param[in] category						Category to search.
	/// @param[in] dataTypeId					Data type id to process.
	/// @param[in] language						Language to process.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDescription> UpdateDescriptions(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language) const;

	//----------------------------------------------------------------------------------------
	/// Returns true if the database is writable.
	/// @param[in] languageId					Language id to check.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsWritableDatabase(const Id& languageId) const;
	
	//----------------------------------------------------------------------------------------
	/// Returns the number of changes made since the last Write().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetChangeCount() const;

	//----------------------------------------------------------------------------------------
	/// Writes all changes permanently to hd.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Write() const;
};

#include "datadescriptiondefinitiondatabaseimpl1.hxx"
#include "datadescriptiondefinitiondatabaseimpl2.hxx"

}

#endif // DATADESCRIPTIONDEFINITIONDATABASEIMPL_H__
