#ifndef DATADESCRIPTIONDEFINITION_H__
#define DATADESCRIPTIONDEFINITION_H__


#include "maxon/datadescription.h"
#include "maxon/datadictionary.h"
#include "maxon/interface.h"
#include "maxon/observerobject.h"
#include "maxon/stringresource.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Flags used in combination with GetDataCallbackType
//----------------------------------------------------------------------------------------
enum class GETDATAFLAGS
{
	NONE = 0,																///< no flags
	INTENT_ENABLING = (1 << 0),							///< Set this flag to get the effective value for the enabling with out port links (but the effective coming
																					///< from the linked port)
	INTENT_ENABLING_ISCONNECTED = (1 << 1),	///< Check only if the property is connected.
} MAXON_ENUM_FLAGS(GETDATAFLAGS);

using GetDataCallbackType = Delegate<Result<Data>(const InternedId& id, const DataDictionary& dataEntry, GETDATAFLAGS flags)>;

using DataDescriptionEntry = DataDictionary;

class DataDescriptionDefinition;

//----------------------------------------------------------------------------------------
/// Interface to store descriptions definitions of objects. The DataDescription definition defines a sequence of "commands" to define
/// attributes, include, commands, strings, etc.
//----------------------------------------------------------------------------------------
class DataDescriptionDefinitionInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(DataDescriptionDefinitionInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.datadescriptiondefinition");

public:

	//----------------------------------------------------------------------------------------
	/// Returns the info dictionary.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD DataDictionary GetInfo() const;

	//----------------------------------------------------------------------------------------
	/// SetInfo the info dictionary of the description.
	/// @param[in] info								Dictionary with infos.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> SetInfo(const DataDictionary& info);

	//----------------------------------------------------------------------------------------
	/// Returns the number of entries in the description.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetEntryCount() const;

	//----------------------------------------------------------------------------------------
	/// Returns a array with all entries.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<DataDescriptionEntry>> GetEntries() const;

	//----------------------------------------------------------------------------------------
	/// Returns a specific entry with the given index.
	/// @param[in] idx								Index to return.
	/// @return												Entry on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDescriptionEntry> GetEntry(Int idx) const;

	//----------------------------------------------------------------------------------------
	/// FindEntry searches the first occurrence of the entry.
	/// @param[in] id									Id to search.
	/// @return												Entry on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDescriptionEntry> FindEntry(const InternedId& id) const;

	//----------------------------------------------------------------------------------------
	/// AddEntry to the description.
	/// @param[in] props							Attribute to add to the end of the list.
	/// @return												Index of the new attribute on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> AddEntry(const DataDescriptionEntry& props);

	//----------------------------------------------------------------------------------------
	/// Replaces an entry.
	/// @param[in] props							Properties to replace.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ReplaceEntry(const DataDescriptionEntry& props);

	//----------------------------------------------------------------------------------------
	/// Replaces an entry.
	/// @param[in] idx								Index to replace.
	/// @param[in] props							Properties to replace.
	/// @return												True if changes were detected. False if the data was identical.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> ReplaceEntry(Int idx, const DataDescriptionEntry& props);

	//----------------------------------------------------------------------------------------
	/// EraseEntry an attribute from the description.
	/// @param[in] idx								Index of the attribute to delete.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> EraseEntry(Int idx);

	//----------------------------------------------------------------------------------------
	/// Resets the description and clear all attributes.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Reset();

	//----------------------------------------------------------------------------------------
	/// Merges the given descriptions.
	/// @param[in] target							Target description to overwrite.
	/// @param[in] source							New entries to merge into target.
	/// @param[in] overwriteIncludes	True to overwrite the includes of target id source has includes.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> MergeDescriptionDefinition(DataDescriptionDefinition& target, const DataDescriptionDefinition& source, Bool overwriteIncludes, Bool skipIncludes);

	static MAXON_METHOD Result<Data> GetDataDefaults(const DataDictionary& dataEntry);

	static MAXON_METHOD Result<Data> GetDataValueOrDefaults(
		const InternedId& dataId, const DataDictionary& dataEntry, GETDATAFLAGS flags, const GetDataCallbackType& getDataCallback);

	static MAXON_METHOD DataDescriptionDefinitionInterface* Create();

	static MAXON_METHOD const DataDescriptionDefinitionInterface* NullValuePtr();
};



#include "datadescriptiondefinition1.hxx"

//----------------------------------------------------------------------------------------
/// Implementation of the DataDictionaryObjectInterface without any data stored.
/// This class can be used as a base component for you own inherited classes which overrides SetData/GetData.
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<DataDescriptionDefinition>, DataDescriptionDefinitionClass, "net.maxon.class.datadescriptiondefinition");

#include "datadescriptiondefinition2.hxx"

using LanguageStringDataDescriptionDefinition = HashMap<Id /* LanguageRef */, DataDescriptionDefinition>;
using DataDescriptionDefinitionWithUIAndLanguageStrings = Tuple<DataDescriptionDefinition /* data description */, DataDescriptionDefinition /* ui description*/, LanguageStringDataDescriptionDefinition /* string description*/>;

MAXON_DATATYPE(LanguageStringDataDescriptionDefinition, "net.maxon.datatype.languagestringdatadescriptiondefinition");




}

#endif // DATADESCRIPTIONDEFINITION_H__
