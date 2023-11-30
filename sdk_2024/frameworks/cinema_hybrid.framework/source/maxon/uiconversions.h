#ifndef UICONVERSIONS_H__
#define UICONVERSIONS_H__

#include "maxon/bytesvalue.h"
#include "maxon/datadescription.h"
#include "maxon/datadescriptiondefinition.h"
#include "maxon/datadescriptiondatabase.h"
#include "maxon/hashmap.h"

class GeData;
class DescID;
class BaseContainer;
class BaseDocument;
class Description;

namespace maxon
{

class DescTranslation;
class UiConversion;
class LanguageRef;

using GetExtraDataCallbackType = Delegate<DelegateBase(const Id&)>;
using PatchC4DDescriptionEntryDelegate = Delegate<Result<void>(BaseContainer& param)>;


class UiConversionInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(UiConversionInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.uiconversion");

public:
	//----------------------------------------------------------------------------------------
	/// Returns the supported data types of the implemented ui.
	/// @param[out] dataTypes					List of compatible types.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> QuerySupportedDataTypes(BaseArray<DataType>& dataTypes /* const ValueReceiver<const DataType&>& dataTypes */) const;

	//----------------------------------------------------------------------------------------
	/// CreateC4DDescription generates the description for the given description entry.
	/// @param[in] dataType						Data type of the entry.
	/// @param[in,out] c4dDescription	C4D description to fill.
	/// @param[in] language						Language to use.
	/// @param[in] dataEntry					Data description for the given entry.
	/// @param[in] guiEntry						UI description for the given entry.
	/// @param[in] mainDataDescription	Main data description.
	/// @param[in] stringDescription	String description for the given entry and current language.
	/// @param[in] mainId							DescID to use for this id.
	/// @param[in] groupId						Group id to use for this entry.
	/// @param[in] patchEntryFunc			call back which is called for each generated c4d description entry. This allows to patch several parameters from outside before adding to c4dDescription.
	/// @param[in] translateIds				Translation table for all ids.
	/// @param[in] parentIds					Parent ids to concatenate.
	/// @param[in] parentFoldId				Parent fold id.
	/// @param[in] getDataCallback		GetDataCallback in case the data is needed to create the ui.
	/// @param[in] getExtraDataDelegate	Callback to query extra data (e.g. GetRepositoryMessage).
	/// @param[in] doc								Document context for the description.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CreateC4DDescription(const DataType& dataType, Description& c4dDescription, const LanguageRef& language,
		const DataDictionary& dataEntry, const DataDictionary& guiEntry, const DataDescription& mainDataDescription, const DataDescription& stringDescription, const DescID& mainId,
		const DescID& groupId, const PatchC4DDescriptionEntryDelegate& patchEntryFunc, DescTranslation& translateIds,
		const BaseArray<InternedId>& parentIds, const DescID& parentFoldId, const GetDataCallbackType& getDataCallback, const GetExtraDataCallbackType& getExtraDataDelegate,
		const BaseDocument* doc) const;

	//----------------------------------------------------------------------------------------
	/// ConvertToC4D implements the data type conversion from Data to GeData for all supported types returned by QuerySupportedDataTypes().
	/// @param[out] output						The converted value.
	/// @param[in] dataType						Data type to convert.
	/// @param[in] data								Data to convert.
	/// @param[in] descIdSuffix				DescId suffix which indicates the sub entry for UIs which generated multiple DescID attributes in the c4d description.
	/// @param[in] dataEntry					Data description entry of the given value.
	/// @param[in] guiEntry						UI description entry of the given value.
	/// @param[in] extraDataDelegate	Extra delegate to retrieve additional data from parent objects.
	/// @param[in] doc								Document context for the conversion.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> ConvertToC4D(GeData& output, const DataType& dataType, const Data& data, const DescID& descIdSuffix, const DataDictionary& dataEntry,
		const DataDictionary& guiEntry, const GetExtraDataCallbackType& extraDataDelegate, const BaseDocument* doc) const;

	//----------------------------------------------------------------------------------------
	/// ConvertToCore implements the data type conversion from GeData to Data for all supported types returned by QuerySupportedDataTypes().
	/// @param[in] dataType						Data type to convert.
	/// @param[in] data								GeData to convert.
	/// @param[in] descIdSuffix				DescId suffix which indicates the sub entry for UIs which generated multiple DescID attributes in the c4d description.
	/// @param[in] dataEntry					Data description entry of the given value.
	/// @param[in] guiEntry						UI description entry of the given value.
	/// @param[in] oldData						Previous old data.
	/// @param[in] extraDataDelegate	Extra delegate to retrieve additional data from parent objects.
	/// @param[in] doc								Document context for the conversion.
	/// @return												Converted Data on success. Bool: false is the default, true overrites the return value in the port with the ui type (e.g. psrmatrix)
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Tuple<Data, Bool>> ConvertToCore(const DataType& dataType, const GeData& data, const DescID& descIdSuffix, const DataDictionary& dataEntry,
		const DataDictionary& guiEntry, const Data& oldData, const GetExtraDataCallbackType& extraDataDelegate, const BaseDocument* doc) const;

	//----------------------------------------------------------------------------------------
	/// AddDefaultConversion allows to add a new default conversion for a given data type.
	/// @code
	/// UiConversionInterface::AddDefaultConversion(GetDataType<Bool>(), UiConversions::UiBool.GetId()) iferr_return;
	/// @endcode
	/// @param[in] dataType						Data type to add.
	/// @param[in] guiId							UI id to add to the table.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> AddDefaultConversion(const DataType& dataType, const Id& guiId);

	//----------------------------------------------------------------------------------------
	/// GetGuiConversionEntry returns the UiConversion object for the given datatype and ui id.
	/// @param[in] dataTypeId					Data type to use as fallback.
	/// @param[in] guiTypeId					UI to find in the UiConversions registry. If not found the fallback will check the datatype id with the registered default UIs.
	/// @param[out] resGuiTypeId			Optional: if not nullptr it will return the detected UI id.
	/// @return												UiConversion on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<UiConversion> GetGuiConversionEntry(const Id& dataTypeId, const Id& guiTypeId, Id* resGuiTypeId);

	//----------------------------------------------------------------------------------------
	/// Returns a array with all compatible ui types for the given datatype.
	/// @param[in] dataType						Data type for which all ids should be returned.
	/// @return												Array with ids on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<Id>> GetCompatibleUIs(const DataType& dataType);

	//----------------------------------------------------------------------------------------
	/// ConvertData converts the given data to any compatible type. If no valid conversion is found an error is returns.
	/// @param[in] data								Data to convert.
	/// @param[in] dstDataType				Destination data type.
	/// @return												Converted data on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Data> ConvertData(const Data& data, const DataType& dstDataType);

	//----------------------------------------------------------------------------------------
	/// ConvertData converts the given data to any compatible type. If no valid conversion is found an error is returns.
	/// @param[in] data								Data to convert.
	/// @param[in] dstDataType				Destination data type.
	/// @return												Converted data on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Data> ConvertData(Data&& data, const DataType& dstDataType);
};



#include "uiconversions1.hxx"

MAXON_REGISTRY(UiConversion, UiConversions, "net.maxon.image.registry.uiconversions");

namespace UiConversions
{
	MAXON_DECLARATION(UiConversions::EntryType, UiBool, "net.maxon.ui.bool");
	MAXON_DECLARATION(UiConversions::EntryType, UiString, "net.maxon.ui.string");
	MAXON_DECLARATION(UiConversions::EntryType, UiUrl, "net.maxon.ui.url");
	MAXON_DECLARATION(UiConversions::EntryType, UiNumber, "net.maxon.ui.number");
	MAXON_DECLARATION(UiConversions::EntryType, UiNumberBytes, "net.maxon.ui.number.bytes");
	MAXON_DECLARATION(UiConversions::EntryType, UiNumberTimeValue, "net.maxon.ui.number.timevalue");
	MAXON_DECLARATION(UiConversions::EntryType, UiColor, "net.maxon.ui.color");
	MAXON_DECLARATION(UiConversions::EntryType, UiColorAlpha, "net.maxon.ui.coloralpha");
	MAXON_DECLARATION(UiConversions::EntryType, UiBaseLink, "net.maxon.ui.baselink");
	MAXON_DECLARATION(UiConversions::EntryType, UiData, "net.maxon.ui.data");
	MAXON_DECLARATION(UiConversions::EntryType, UiButton, "net.maxon.ui.button");
	MAXON_DECLARATION(UiConversions::EntryType, UiNodeLink, "net.maxon.ui.nodelink");
	MAXON_DECLARATION(UiConversions::EntryType, UiLinkedPort, "net.maxon.ui.linkedport");
	MAXON_DECLARATION(UiConversions::EntryType, UiLayerSet, "net.maxon.ui.layerset");
	MAXON_DECLARATION(UiConversions::EntryType, UiEnum, "net.maxon.ui.enum");
	MAXON_DECLARATION(UiConversions::EntryType, UiEnumQuickTab, "net.maxon.ui.enumquicktab");
	MAXON_DECLARATION(UiConversions::EntryType, UiEnumList, "net.maxon.ui.enumlist");
	MAXON_DECLARATION(UiConversions::EntryType, UiIdList, "net.maxon.ui.idlist");
	MAXON_DECLARATION(UiConversions::EntryType, UiVariadicPort, "net.maxon.ui.variadicport");
	MAXON_DECLARATION(UiConversions::EntryType, UiVariadicPortPlain, "net.maxon.ui.variadicportplain");
	MAXON_DECLARATION(UiConversions::EntryType, UiGroup, "net.maxon.ui.group");
	MAXON_DECLARATION(UiConversions::EntryType, UiPreviewImage, "net.maxon.ui.previewimage");
	MAXON_DECLARATION(UiConversions::EntryType, UiSeparator, "net.maxon.ui.separator");	
	MAXON_DECLARATION(UiConversions::EntryType, UiDataType, "net.maxon.ui.datatype");
	MAXON_DECLARATION(UiConversions::EntryType, UiSplineMapper, "net.maxon.ui.splinemapper");
	MAXON_DECLARATION(UiConversions::EntryType, UiPRSMatrix, "net.maxon.ui.prsmatrix");
	MAXON_DECLARATION(UiConversions::EntryType, UiFontChooser, "net.maxon.ui.fontchooser");
	MAXON_DECLARATION(UiConversions::EntryType, UiOcioColorSpace, "net.maxon.ui.ociocolorspace");
	MAXON_DECLARATION(UiConversions::EntryType, UiScenePort, "net.maxon.ui.sceneport");
}

namespace CustomNodeGui
{
	//----------------------------------------------------------------------------------------
	/// Identifier for the node-based gradient GUI which is extracted by UiConversions::UiVariadicPort from the attribute
	/// 'DESCRIPTION::UI::NET::MAXON::UI::VARIADICPORT::COMPLEXCUSTOMUI'.
	///
	/// This GUI can be used to represent a custom-defined variadic port bundle. In order for the GUI to operate
	/// the IDs of inputs in the bundle have to fulfill certain requirements:
	/// - Port Id =         [*color*]; Port Data Type = [Color, ColorA]
	/// - Port Id =      [*position*]; Port Data Type = [Float]
	/// - Port Id =          [*bias*]; Port Data Type = [Float]
	/// - Port Id = [*interpolation*]; Port Data Type = [Enum of InternedId's] with values = {*smoothknot*, *cubicknot*, *linearknot*, *none*, *blend*}
	/// The name mapping is case-insensitive and searches for substrings.
	//----------------------------------------------------------------------------------------
	static const Int32 GradientId = 200001011;

} // namespace CustomNodeGui

#include "uiconversions2.hxx"

} // namespace maxon
#endif // UICONVERSIONS_H__
