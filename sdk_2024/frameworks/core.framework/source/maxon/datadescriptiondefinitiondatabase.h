#ifndef DATADESCRIPTIONDEFINITIONDATABASE_H__
#define DATADESCRIPTIONDEFINITIONDATABASE_H__

#include "maxon/datadescription.h"
#include "maxon/datadescriptiondefinition.h"
#include "maxon/idandversion.h"
#include "maxon/observable.h"
#include "maxon/valuereceiver.h"
#include "maxon/url.h"


namespace maxon
{

class DataDescriptionDefinitionDatabaseImplRef;
class LanguageRef;

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

enum class DBVERSION;

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
	MAXON_INTERFACE_NONVIRTUAL(DataDescriptionDefinitionDatabaseInterface, MAXON_REFERENCE_STATIC, "net.maxon.interface.datadescriptiondefinitiondatabase");

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
	/// @param[in] databaseId					Database id (see RegisterDatabase()/GetRegisteredDatabases()).
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
	/// Save all databases (including user changes and version update changes).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> WriteDataBases();

	//----------------------------------------------------------------------------------------
	/// Save all databases edited by a user.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> WriteUserChangedDataBases();

	//----------------------------------------------------------------------------------------
	/// QueryNeedsWriteDataBases returns true if changes to the databases are pending and not saved.
	/// Those changes can include user changes and automatic database version update changes.
	/// @return												True if databases were modified and are still unsaved.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool QueryNeedsWriteDataBases();

	//----------------------------------------------------------------------------------------
	/// QueryNeedsWriteDataBases returns true if changes from user to the databases are pending and not saved.
	/// @return												True if databases were modified and are still unsaved.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Bool QueryNeedsWriteDataBasesForUserChanges();

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
	/// Checks if the given id is unique in all databases.
	/// @param[in] searchId						Id to search for.
	/// @return												True if the id is unique. False if the id already exists.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> CheckUniqueAttributeName(const InternedId& searchId);

	//----------------------------------------------------------------------------------------
	/// UpdateDescription description.
	/// @param[in] databaseId					Unique id for the database.
	/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI / DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] dataType						Data type id to store.
	/// @param[in] descRef						Description ref to connect the update observable with.
	/// @param[in] notifyParents			True if parents should be notified.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDescription> UpdateDescription(const Id& databaseId, const Id& category, const LanguageRef& language,
		const IdAndVersion& dataType, DataDescriptionDefinition& descRef, Bool notifyParents);

	//----------------------------------------------------------------------------------------
	/// Registers a database for a specific module under the given url.
	/// @param[in] databaseId					Unique id for the database.
	/// @param[in] url								Absolute url to look for the database.
	/// @param[in] version						An optional version string to use for the database.
	/// 															This is used by some description processors to invalidate
	/// 															cached meta data which is derived from descriptions.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RegisterDatabaseWithUrl(const Id& databaseId, const Url& url, const CString& version = CString::DefaultValue());

	//----------------------------------------------------------------------------------------
	/// Registers a special database DataDescriptionDefinitionDatabaseImplRef under the given id.
	/// @param[in] databaseId					Unique id for the database.
	/// @param[in] ddb								Database implementation to register.
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
	/// Returns the ids of all registered databases.
	/// @return												Array on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Id>> GetRegisteredDatabases();

	//----------------------------------------------------------------------------------------
	/// Updates the description from the unique definition identified by #dataTypeId.
	/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI / DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] dataTypeId					Identifier of the definition to process.
	/// @param[in] language						Language for which to build the description (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @return												The result of the processed definition.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDescription> BuildDescription(const Id& category, const IdAndVersion& dataTypeId, const LanguageRef& language);

	//----------------------------------------------------------------------------------------
	/// Processes a definition to create a usable DataDescription.
	/// For instance, include commands will be expanded, remove commands will be "erased", overrides will be aggregated, etc.
	/// The resulting description should not contain any entry with duplicated DESCRIPTION::BASE::IDENTIFIER.
	/// Can be used to process dynamically created definitions, not only definitions read from a database.
	/// The resulting descriptions are not cached.
	/// @param[in] category						Description category to build (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI / DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] language						Language for which to build the description (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] descriptionId			The identifier of the original definition of #srcDefinition if available.
	/// @param[in] srcDefinition			The source definition to process.
	/// @return												The result of the processed definition.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDescription> BuildDescription(const Id& category, const LanguageRef& language, const IdAndVersion& descriptionId,
		const DataDescriptionDefinition& srcDefinition);

	//----------------------------------------------------------------------------------------
	/// Registers a message callback for a datatype, attribute and variadic command.
	/// @param[in] dataTypeId					Data type id to register.
	/// @param[in] attributeId				Attribute id to register.
	/// @param[in] cmdId							Command Id to register.
	/// @param[in] func								Callback function to register.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RegisterMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId, const DescriptionMessageFunction& func);

	static MAXON_FUNCTION Result<void> RegisterMessage(const Id& dataTypeId, const InternedId& attributeId, const Id& cmdId, const DescriptionMessageFunction& func)
	{
		return RegisterMessage(dataTypeId, attributeId.Get(), cmdId, func);
	}

	//----------------------------------------------------------------------------------------
	/// Registers a value changed callback for a datatype and attribute id.
	/// Callback will be fired after the new value was changed.
	/// @param[in] dataTypeId					Data type id to register.
	/// @param[in] attributeId				Attribute id to register. Optional.
	/// @param[in] func								Callback function to register.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> RegisterValueChangedMessage(const Id& dataTypeId, const Id& attributeId, const DescriptionMessageFunction& func);

	static MAXON_FUNCTION Result<void> RegisterValueChangedMessage(const Id& dataTypeId, const InternedId& attributeId, const DescriptionMessageFunction& func)
	{
		return RegisterValueChangedMessage(dataTypeId, attributeId.Get(), func);
	}

	//----------------------------------------------------------------------------------------
	/// Finds a registered command callback with a given datatype, attribute and variadic command.
	/// @param[in] dataTypeId					Data type id to search for.
	/// @param[in] attributeId				Attribute id to search for.
	/// @param[in] cmdId							Command id to search for.
	/// @return												Pointer to the callback. Nullptr if nothing was found.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD DescriptionMessageFunction* FindNodeMessage(const Id& dataTypeId, const Id& attributeId, const Id& cmdId);

	//----------------------------------------------------------------------------------------
	/// Finds a registered value changed callback with a given datatype and attribute id.
	/// It is possible to supply only both id inputs or just a #dataTypeId. But then
	/// the same callback will be found for multiple multiples attributes of this #datatypeId (i.e. global to #dataTypeId).
	/// @param[in] dataTypeId					Data type id to search for.
	/// @param[in] attributeId				Attribute id to search for. Optional.
	/// @param[in] receiver						Receiver for the various functions found (could be multiple hits).
	/// @return												Result of the receiver.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> FindNodeValueChangedMessage(const Id& dataTypeId, const Id& attributeId, const ValueReceiver<DescriptionMessageFunction&>& receiver);

	//----------------------------------------------------------------------------------------
	/// Fixes an entry of the resource database.
	/// @param[in] version						last converted version.
	/// @param[in] entry							DataDictionary to convert.
	/// @return                       OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> FixDatabaseProps(DBVERSION version, DataDictionary& entry);

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
