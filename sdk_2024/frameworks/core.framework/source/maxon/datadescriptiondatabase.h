#ifndef DATADESCRIPTIONDATABASE_H__
#define DATADESCRIPTIONDATABASE_H__

#include "maxon/datadescriptiondefinition.h"
#include "maxon/datadescriptionobject.h"
#include "maxon/datadictionaryobject.h"
#include "maxon/idandversion.h"

namespace maxon
{

class AssetRepositoryRef;
class LanguageRef;

static constexpr LiteralId DATADESCRIPTION_CATEGORY_DATA{"data"};
static constexpr LiteralId DATADESCRIPTION_CATEGORY_UI{"gui"};
static constexpr LiteralId DATADESCRIPTION_CATEGORY_STRING{"string"};

/// Used as separator for extension points below and some special identifier tags.
static constexpr Char EXTENSION_ID_SEPARATOR = '#';

#define ENUMCOMMAND											"command#"

/// Enumeration extension points that adds a separator in between entries.
#define ENUM_EXTENSION_SEPARATOR				Id("---")
#define ENUMSEPARATOR										ENUM_EXTENSION_SEPARATOR			///< @markDeprecated

/// Enumeration extension points that allows reuse/important enum resources instead of copy pasting them.
/// Supports the following format "enum#net.maxon.neutron.someenumresource"
#define ENUM_EXTENSION_ENUM							"enum#"_cs

/// Prepend this tag before an enumeration Id in a GUI Enum List to filter out certain ids. 
/// Useful when enums are populated dynamically with "enum#", "registry#", "node#", ...
#define ENUM_EXTENSION_REMOVE						"remove#"_cs
#define ENUMREMOVE											"remove#"											///< @markDeprecated

/// Prefix used in identifiers such as "net.maxon.{var#somevariabletoresolve}" to identify pieces to be resolved to get the final identifier.
#define PRESET_EXTENSION_VARIABLE				"var#"_cs
#define VARIABLEID_PREFIX								"var#"												///< @markDeprecated

/// Special identifier markers used in description identifiers for command, enum and presets.
/// Identifier in JSON data could look like this:
/// "databaseurlin#command#reload" or
/// "splinetype#enum#net.maxon.registry.geometryabstraction.curve.types.bezier" or
/// "alignaxis#enum#xpos" or
/// "alignaxis#enum#ypos"
/// It is preprended with the port identifier which needs the child entry and appended
/// with the identifier of the command/enum/preset itself.
#define DATADESCRIPTION_ID_COMMAND			"#command#"_cs
#define DATADESCRIPTION_ID_ENUM					"#enum#"_cs
#define DATADESCRIPTION_ID_PRESET				"#preset#"_cs

//----------------------------------------------------------------------------------------
/// Interface to access the storage of DataDescription objects.
//----------------------------------------------------------------------------------------
class DataDescriptionDatabaseInterface
{
	MAXON_INTERFACE_NONVIRTUAL(DataDescriptionDatabaseInterface, MAXON_REFERENCE_STATIC, "net.maxon.interface.datadescriptiondatabase");

public:
	//----------------------------------------------------------------------------------------
	/// LoadDescription description.
	/// @param[in] category						Database category (e.g. DATADESCRIPTION_CATEGORY_DATA / DATADESCRIPTION_CATEGORY_UI).
	/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
	/// @param[in] dataType						Data type id to load.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDescription> LoadDescription(const Id& category, const LanguageRef& language, const Id& dataType);

	static MAXON_METHOD Result<DataDescription> LoadDescription(const Id& category, const LanguageRef& language, const IdAndVersion& dataType);

	//----------------------------------------------------------------------------------------
	/// Resets the cached description.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DescriptionDefinitionChanged(const Id& category, const LanguageRef& language, const IdAndVersion& dataType);

	//----------------------------------------------------------------------------------------
	/// GetEffectiveEnumList returns the enum list prepared for display in the ui with the user order etc.
	/// It takes DESCRIPTION::DATA::BASE::ENUM and DESCRIPTION::UI::BASE::ENUM into account.
	/// @param[in] dataEntry					Description of the data.
	/// @param[in] guiEntry						Description of the ui.
	/// @param[in] stringDescription	Description of the strings.
	/// @param[in] resolveExtensionPointsAndGui	True if extension points and ui order should be evaluated. False will return the unprocessed DESCRIPTION::DATA::BASE::ENUM array.
	/// @param[in] withStrings				True if strings shall be set up.
	/// @param[in] language						Language to use.
	/// @param[in] repository					Asset Repository to use.
	/// @param[in] filterData					Filter only for this one type. Nullptr to disable filtering.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Tuple<Id, Data, String>>> GetEffectiveEnumList(const DataDictionary& dataEntry,
		const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui,
		Bool withStrings, const LanguageRef& language, const AssetRepositoryRef& repository, const Data* filterData);

	//----------------------------------------------------------------------------------------
	/// @see GetEffectiveEnumList. Same functionality, but supports resolving variable identifiers with #getDataCallback.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Tuple<Id, Data, String>>> GetEffectiveEnumList(const DataDictionary& dataEntry,
		const DataDictionary& guiEntry, const DataDescription& stringDescription, Bool resolveExtensionPointsAndGui,
		Bool withStrings, const LanguageRef& language, const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback,
		const Data* filterData);

	//----------------------------------------------------------------------------------------
	/// PostProcessStringDescription description.
	/// @param[in] description				Description to modify
	/// @param[in] entries						String description entries to process.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> PostProcessStringDescription(DataDescription& description, const BaseArray<DataDictionary>& entries);

	//----------------------------------------------------------------------------------------
	/// Returns a usable identifier with all variables resolved. #identifier usually comes from
	/// DESCRIPTION::UI::BASE::PRESETDATABASEID or DESCRIPTION::UI::BASE::PRESETDATABASEDYNAMICID.
	/// It can also come from GetEffectiveEnumList, as long as the context to resolve the variables is at hand.
	/// For instance "preset_net.maxon.preset.neutron.distribution.parametric.spiral.{var#net.maxon.description.data.base.datatype}".
	/// This has to be resolved to load the correct preset database. The variable parts of the given identifier 
	/// must be found in the supplied DataDictionary entries or through GetDataBCallbackType.
	/// @see VARIABLEID_PREFIX.
	/// @param[in] identifier					The identifier to resolve.
	/// @param[in] repository					Repository from where the entries stem.
	/// @param[in] getDataCallback		Callback used to read read description entry values.
	/// @param[in] dataEntry					Optional. The description definition DATADESCRIPTION_CATEGORY_DATA entry used to resolve the identifier.
	/// @param[in] guiEntry						Optional. The description definition DATADESCRIPTION_CATEGORY_GUI entry used to resolve the identifier.
	/// @return												Resolved identifier. An error if variables ("{var#@}") were not resolved successfully.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Id> ResolveVariableIdentifier(const Id& identifier, const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, Opt<const DataDictionary&> dataEntry, Opt<const DataDictionary&> guiEntry = Opt<const DataDictionary&>{});

	//----------------------------------------------------------------------------------------
	/// Returns a usable preset identifier with all variables resolved. #presetIdentifier will be read in
	/// DESCRIPTION::UI::BASE::PRESETDATABASEID or DESCRIPTION::UI::BASE::PRESETDATABASEDYNAMICID. The latter has priority
	/// and might contains links to other definition entries which need to be resolved..
	/// For instance "preset_net.maxon.preset.neutron.distribution.parametric.spiral.{net.maxon.description.data.base.datatype}".
	/// This has to be resolved to load the correct preset database. The variable parts of the given identifier 
	/// must be found in the supplied data or gui entries. If no entry dictionaries are supplied, resolving will not occur and 
	/// the preset identifier will be handled as constant.
	/// @param[in] repository					Repository from where the entries stem.
	/// @param[in] getDataCallback		Callback used to read read description entry values.
	/// @param[in] guiEntry						The description definition DATADESCRIPTION_CATEGORY_GUI entry used to resolve the preset identifier.
	/// @param[in] dataEntry					Optional. The description definition DATADESCRIPTION_CATEGORY_DATA entry used to resolve the preset identifier.
	/// @param[out] outResolveSuccess	Optional. Will be set to true if a dynamic identifier is set and was resolved properly.
	/// @return												Preset resolved PRESETDATABASEDYNAMICID database identifier or PRESETDATABASEID if resolve failed.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Id> GetAndResolvePresetIdentifier(const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, const DataDictionary& guiEntry, Opt<const DataDictionary&> dataEntry = Opt<const DataDictionary&>{}, Bool& outResolveSuccess = DefaultLValue<Bool>{});
};

//----------------------------------------------------------------------------------------
/// Callback for registry ProcessEnumListDelegates.
/// @param[in] epId								The extension point identifier (for instance "node", "enum", ...).
/// @param[in] guiEntry						The description definition DATADESCRIPTION_CATEGORY_GUI entry which defines the enum or preset.
/// @param[in] repository					Repository from where the entries stem.
/// @param[in] filterData					See UseFilterData.
/// @param[in] addValue						ValueReceiver that will be called to process all enum entries generated by the extension point.
/// @return												Ok on success.
//----------------------------------------------------------------------------------------
using ProcessEnumListDelegate = Delegate<Result<void>(const Id& epId, const DataDictionary& guiEntry, const AssetRepositoryRef& repository, const Data* filterData,
	const ValueReceiver<Tuple<Id, Data, String>&&>& addValue)>;
MAXON_DATATYPE(ProcessEnumListDelegate, "net.maxon.datatype.processenumlistdelegate");
/// GetEffectiveEnumList will utilize this registry to replace extension points.
MAXON_REGISTRY(ProcessEnumListDelegate, ProcessEnumListDelegates, "net.maxon.datadescription.registry.processenumlist");

//----------------------------------------------------------------------------------------
/// Callback for registry EnumVariableResolveDelegates.
/// @param[in] variable						The variable to replace.
/// @param[in] fullString					The full context in which variables are being resolved.
/// @param[in] repository					Repository from where the entries stem.
/// @param[in] getDataCallback		Callback used to read read description entry values.
/// @param[in] dataEntry					Optional. The description definition DATADESCRIPTION_CATEGORY_DATA entry which defines the enum or preset.
/// @param[in] guiEntry						Optional. The description definition DATADESCRIPTION_CATEGORY_GUI entry which defines the enum or preset.
/// @return												A resolved string, should contain no more "{}". Can be turned in an Id or replaced in original string by caller.
///																An error if the variable could not be resolved.
//----------------------------------------------------------------------------------------
using EnumVariableResolveDelegate = Delegate<Result<CString>(const CString& variable, const CString& fullString, const AssetRepositoryRef& repository, const GetDataCallbackType& getDataCallback, Opt<const DataDictionary&> dataEntry, Opt<const DataDictionary&> guiEntry)>;
MAXON_DATATYPE(EnumVariableResolveDelegate, "net.maxon.datatype.delegate.enumvariableresolve");
/// GetEffectiveEnumList will utilize this registry to resolve enums and presets which need their identifier to be resolved before use.
/// For instance, "net.maxon.description.base.preset.{re_selectedtype}" must be resolved to something like
/// "net.maxon.description.base.preset.float" to fetch the correct preset database.
/// @see VARIABLEID_PREFIX.
MAXON_REGISTRY(EnumVariableResolveDelegate, EnumVariableResolveDelegates, "net.maxon.datadescription.registry.enumvariableresolve");

#include "datadescriptiondatabase1.hxx"
#include "datadescriptiondatabase2.hxx"

//----------------------------------------------------------------------------------------
/// Helper function to use with ProcessEnumListDelegate to verify if a type needs to be added to the output array.
/// @param[in] filterData					Forward filterData from delegate.
/// @param[in] compare						Data that would be added. check before doing more complex operations.
/// @return                       True to process the data, false to ignore this entry.
//----------------------------------------------------------------------------------------
inline Bool UseFilterData(const Data* filterData, const Data& compare)
{
	if (!filterData)
		return true;

	if (compare.GetType() != filterData->GetType())
	{
		ifnoerr (Data filterDataConverted = filterData->ConvertData(compare.GetType()))
		{
			return compare == filterDataConverted;
		}
	}
	return compare == *filterData;
}


}
#endif // DATADESCRIPTIONDATABASE_H__
