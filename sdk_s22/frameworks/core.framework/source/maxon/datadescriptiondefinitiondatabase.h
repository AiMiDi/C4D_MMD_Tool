#ifndef DATADESCRIPTIONDEFINITIONDATABASE_H__
#define DATADESCRIPTIONDEFINITIONDATABASE_H__

#include "maxon/datadescription.h"
#include "maxon/datadescriptiondefinition.h"
#include "maxon/idandversion.h"
#include "maxon/observable.h"
#include "maxon/stringresource.h"
#include "maxon/url.h"


namespace maxon
{

class DataDescriptionDefinitionDatabaseImplRef;

//----------------------------------------------------------------------------------------
/// used in DescriptionMessageCheck.
//----------------------------------------------------------------------------------------
enum class DESCRIPTIONMESSAGECHECKFLAGS
{
	NONE = 0,							///< no flags
	ENABLED = 1 << 0,			///< menu entry should be enable.
	VISIBLE = 1 << 1,			///< visible menu entry is visible
	CHECKED = 1 << 2,			///< menu entry is checked with a check mark symbol.
	SORTSUBMENU = 1 << 3, ///< true to sort sub menu entries
} MAXON_ENUM_FLAGS(DESCRIPTIONMESSAGECHECKFLAGS);


class SubMenuEntry;

//----------------------------------------------------------------------------------------
/// Value receiver for menu entries. 
/// Id - id of the category to add the entry. Empty Id() for no category.
/// SubMenuEntry - entry with the data to present.
//----------------------------------------------------------------------------------------
using BuildSubMenuValueReceiver = ValueReceiver<SubMenuEntry&&>;

//----------------------------------------------------------------------------------------
/// Optional delegate to return a pre message check for a description command.
/// DESCRIPTIONMESSAGECHECKFLAGS will be evaluated to disable, hide or check the menu entry.
//----------------------------------------------------------------------------------------
using DescriptionMessageCheck = Delegate<Result<DESCRIPTIONMESSAGECHECKFLAGS>(const DataDictionary& userData)>;

//----------------------------------------------------------------------------------------
/// Optional delegate to return a sub menu structure of a registered description command.
//----------------------------------------------------------------------------------------
using DescriptionMessageBuildSubMenu = Delegate<Result<void>(const DataDictionary& userData, const BuildSubMenuValueReceiver& menuEntries)>;

//----------------------------------------------------------------------------------------
/// Delegate which will be called on execution of a registered command.
//----------------------------------------------------------------------------------------
using DescriptionMessageCall = Delegate<Result<void>(const DataDictionary& userData, DataDictionary& multiSelectionStorage)>;

MAXON_DATATYPE(DescriptionMessageCall, "net.maxon.datatype.descriptionmessagecall");


//----------------------------------------------------------------------------------------
/// Combines all delegates for a command registration.
///
/// Id:
/// DESCRIPTION::UI::BASE::COMMANDCONTEXT context to which the command belongs to
///
/// DescriptionMessageCheck: 
/// Callback for the check before presenting the command. This allows to control visibility, enabling, checking,
///
/// DescriptionMessageBuildSubMenu:
/// Optional callback to create a submenu structure for this menu entry.
///
/// DescriptionMessageCall: 
/// Callback for the execution of the command. This must be nullptr if a submenu is provided.
//----------------------------------------------------------------------------------------
using DescriptionMessageFunction = Tuple<Id, DescriptionMessageCheck, DescriptionMessageBuildSubMenu, DescriptionMessageCall>;


enum class LOADDESCRIPTIONMODE
{
	COMPLETE,			///< returns the complete description
	OVERWRITTEN,	///< returns the data description editor description with overwritten parameters.
} MAXON_ENUM_LIST(LOADDESCRIPTIONMODE);

//----------------------------------------------------------------------------------------
/// DataDescriptionDefinitionDatabaseInterface provides functions for loading, storing DescriptionDefinitions.
//----------------------------------------------------------------------------------------
class DataDescriptionDefinitionDatabaseInterface
{
	MAXON_INTERFACE_NONVIRTUAL(DataDescriptionDefinitionDatabaseInterface, MAXON_REFERENCE_NONE, "net.maxon.interface.datadescriptiondefinitiondatabase");

public:
	//----------------------------------------------------------------------------------------
	/// Loads a description from the registered databases.
	/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
	/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] dataType						Data type id to load.
	/// @param[out] foundInDatabase		Optional: Pointer to an Id of the database where the entry was found.
	/// @return												DataDescriptionDefinition on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDescriptionDefinition> LoadDescription(
		LOADDESCRIPTIONMODE mode, const Id& category, const LanguageRef& language, const IdAndVersion& dataType, Id* foundInDatabase = nullptr);

	//----------------------------------------------------------------------------------------
	/// Stores the given description under the given values.
	/// @param[in] databaseId					Data base id (see RegisterDatabase()/GetRegisteredDatabases()).
	/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
	/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] dataType						Data type id to store.
	/// @param[in] description				Description data to store.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> StoreDescription(const Id& databaseId, const Id& category, const LanguageRef& language,
		const IdAndVersion& dataType, const DataDescriptionDefinition& description, const DataDescriptionDefinition& overwrittenDescription,
		Bool usePendingSystem);

	//----------------------------------------------------------------------------------------
	/// DeleteDescription deletes a description from the database.
	/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
	/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] dataType						Data type id to delete.
	/// @return												True/False on success. True means the description was found and deleted. False if the description was not found.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> DeleteDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType);

	//----------------------------------------------------------------------------------------
	/// Return all registered descriptions.
	/// @param[in] databaseId					Unique id for the database. If Id() is given the result of all databases will be returned.
	/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
	/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @return												Array on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<IdAndVersion>> GetRegisteredDescriptions(const Id& databaseId, const Id& category, const LanguageRef& language);

	//----------------------------------------------------------------------------------------
	/// Save all databases.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> WriteDataBases();

	//----------------------------------------------------------------------------------------
	/// QueryNeedsWriteDataBases returns true if changes to the databases are pending and not saved.
	/// @return												True if databases were modified and are still unsaved.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool QueryNeedsWriteDataBases();

	//----------------------------------------------------------------------------------------
	/// Renames a id in all databases to the new id.
	/// @param[in] oldId							Old id to rename
	/// @param[in] newId							Id to replace.
	/// @return												Number of values that were renamed.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Int> RenameId(const Id& oldId, const Id& newId);

	//----------------------------------------------------------------------------------------
	/// Renames an attribute in all databases.
	/// @param[in] oldId							Old attribute key.
	/// @param[in] newId							New attribute key.
	/// @return												Number of values that were renamed.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Int> RenameAttribute(const InternedId& oldId, const InternedId& newId);

	//----------------------------------------------------------------------------------------
	/// Checks if the given id is unique in all data bases.
	/// @param[in] searchId						Id to search for.
	/// @return												True if the id is unique. False if the id already exists.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> CheckUniqueAttributeName(const InternedId& searchId);

	//----------------------------------------------------------------------------------------
	/// UpdateDescription description.
	/// @param[in] databaseId					Unique id for the database.
	/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
	/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] dataType						Data type id to store.
	/// @param[in] descRef						Description ref to connect the update observable with.
	/// @param[in] notifyParents			True if parents should be notified.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDescription> UpdateDescription(const Id& databaseId, const Id& category, const LanguageRef& language,
		const IdAndVersion& dataType, DataDescriptionDefinition& descRef, Bool notifyParents);

	//----------------------------------------------------------------------------------------
	/// UpdateDescription description.
	/// @param[in] databaseId					Unique id for the database.
	/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
	/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] descRef						Description ref to connect the update observable with.
	/// @param[in] dataType						TODO: (Tilo) describe
	/// @return												DataDescription on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDescription> UpdateDescriptionI(const Id& databaseId, const Id& category,
		const LanguageRef& language, DataDescriptionDefinition& descRef, const IdAndVersion& dataType);

	//----------------------------------------------------------------------------------------
	/// Registers a data base for a specific module under the given url.
	/// @param[in] databaseId					Unique id for the database.
	/// @param[in] url								Absolute url to look for the data base.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RegisterDatabaseWithUrl(const Id& databaseId, const Url& url);

	//----------------------------------------------------------------------------------------
	/// Registers a special data base DataDescriptionDefinitionDatabaseImplRef under the given id.
	/// @param[in] databaseId					Unique id for the database.
	/// @param[in] ddb								Data base implementation to register.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RegisterDatabase(const Id& databaseId, const DataDescriptionDefinitionDatabaseImplRef& ddb);

	//----------------------------------------------------------------------------------------
	/// Unregisters the database from the system.
	/// @param[in] databaseId					Unique id of the database.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> UnregisterDatabase(const Id& databaseId);

	//----------------------------------------------------------------------------------------
	/// Returns true if the database is writable.
	/// @param[in] databaseId					Unique id of the database.
	/// @param[in] languageId					Language id to check.
	/// @return												True if writable.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool IsWritableDatabase(const Id& databaseId, const Id& languageId);

	//----------------------------------------------------------------------------------------
	/// Returns the ids and urls of all registered databases.
	/// @return												Array on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Id>> GetRegisteredDatabases();

	//----------------------------------------------------------------------------------------
	/// Updates the description from the definition for the given type.
	/// @param[in] dataTypeId					DataType id to check
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDescription> BuildDescription(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language);

	//----------------------------------------------------------------------------------------
	/// Registers a message callback for a datatype, attribute and variadic command.
	/// @param[in] dataTypeId					Data type id to register.
	/// @param[in] attributeId				Attribute id to register.
	/// @param[in] cmdId							Command Id to register.
	/// @param[in] func								Callback function to register.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RegisterMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId, const DescriptionMessageFunction& func);

	//----------------------------------------------------------------------------------------
	/// Finds a registered command callback with a given datatype, attribute and variadic command.
	/// @param[in] dataTypeId					Data type id to register.
	/// @param[in] attributeId				Attribute id to register.
	/// @param[in] cmdId							Command Id to register.
	/// @return												Pointer to the callback. Nullptr if nothing was found.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD DescriptionMessageFunction* FindNodeMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId);

	//----------------------------------------------------------------------------------------
	/// ObservableSaveDatabase will be triggered before and after a database is/was written.
	/// This can be used to add source control callbacks etc.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE_STATIC(Result<void>, ObservableSaveDatabase, (const Id& databaseId, const Url& dataBaseUrl, Bool beforeSave), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// ObservableDatabaseRegistrationChange after a database was added or removed to the system.
	/// This can be used to update editors.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE_STATIC(Result<void>, ObservableDatabaseRegistrationChange, (const Id& databaseId, Bool added), ObservableCombinerRunAllComponent);
};

#include "datadescriptiondefinitiondatabase1.hxx"
#include "datadescriptiondefinitiondatabase2.hxx"

}
#endif // DATADESCRIPTIONDEFINITIONDATABASE_H__
