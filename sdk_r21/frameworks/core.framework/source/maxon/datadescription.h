#ifndef DATADESCRIPTION_H__
#define DATADESCRIPTION_H__

#include "maxon/datadictionary.h"
#include "maxon/interface.h"
#include "maxon/stringresource.h"
#include "maxon/tuple.h"
#include "maxon/url.h"
#include "maxon/vector.h"
#include "maxon/vector2d.h"
#include "maxon/vector4d.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Interface to store descriptions of objects. The DataDescription object is a cow object. It stores a compiled version of the
/// DataDescriptionDefinitionRef for each datatype.
//----------------------------------------------------------------------------------------
class DataDescriptionInterface
{
	MAXON_INTERFACE_NONVIRTUAL(DataDescriptionInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.datadescription");

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
	MAXON_METHOD Result<BaseArray<DataDictionary>> GetEntries() const;

	//----------------------------------------------------------------------------------------
	/// Returns a specific entry with the given id.
	/// @param[in] id									Id to find
	/// @return												DataDictionary on success. Error if the requested attribute was not in the description-
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<DataDictionary> GetEntry(const InternedId& id) const;

	//----------------------------------------------------------------------------------------
	/// SetEntry description.
	/// @param[in] props							Properties to set. The DESCRIPTION::BASE::IDENTIFIER will be used as key for the hashmap.
	/// @param[in] merge							True if the container should be merged with the existing props im the description. The given props will
	///																have priority over the existing.
	/// @return												true if properties has been changed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Bool> SetEntry(const DataDictionary& props, Bool merge = false);

	//----------------------------------------------------------------------------------------
	/// Deletes a attribute from the description.
	/// @param[in] id									Id of the attribute to delete.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> EraseEntry(const InternedId& id);

	//----------------------------------------------------------------------------------------
	/// Resets the description and clear all attributes.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Reset();

	//----------------------------------------------------------------------------------------
	/// Compares two descriptions.
	/// @param[in] other							Other description to compare.
	/// @param[in] equality						See @EQUALITY.
	/// @return												True in equality.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsEqual(const DataDescriptionInterface* other, EQUALITY equality) const;

	//----------------------------------------------------------------------------------------
	/// Compares the 2 values.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD COMPARERESULT Compare(const DataDescriptionInterface* other) const;

	//----------------------------------------------------------------------------------------
	/// Returns the hashcode of the description.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt GetHashCode() const;

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Use "{N}" for nive formatting of the name only. Otherwise the unique id is printed together with the name.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Describe all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DescribeIO(const DataSerializeInterface& stream);
};

#include "datadescription1.hxx"
#include "datadescription2.hxx"

//----------------------------------------------------------------------------------------
/// This extension point allows to declare the cpp identifiers for types used in the description editor.
/// It's used to translate the datatype back to a cpp identifier.
/// Register any new type for the editor with this line:
/// MAXON_DECLARATION_REGISTER(maxon::DataTypeCppIdentifiers, "net.maxon.image.maxrenderinfo") { return "maxon::rla::MAXRenderInfo"_cs; }
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(CString, DataTypeCppIdentifiers, "net.maxon.registry.datatypecppidentifiers");

//----------------------------------------------------------------------------------------
/// This extension point allows to declare new DataType to be used with deprecated identifiers.
/// Register any deprecated type that needs to be converted with this line:
/// MAXON_DECLARATION_REGISTER(maxon::LegacyIdentifiers, "net.maxon.mograph.legacyshadingdata") { return DataTypePtr(GetDataType<NewShadingData>()); }
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(DataType, LegacyIdentifiers, "net.maxon.registry.datatype.legacyidentifiers");

using DataDescriptionWithUIAndString = Tuple<DataDescription /* data description */, DataDescription /* ui description*/, DataDescription /* string description*/>;

using LanguageStringDataDescription = HashMap<Id /* languageId */, DataDescription>;
using DataDescriptionWithUIAndLanguageStrings = Tuple<DataDescription /* data description */, DataDescription /* ui description*/, LanguageStringDataDescription /* string description*/>;

MAXON_DATATYPE(LanguageStringDataDescription, "net.maxon.datatype.languagestringdatadescription");

}

#endif // DATADESCRIPTION_H__
