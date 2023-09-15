#ifndef DATADESCRIPTION_DATA_H__
#define DATADESCRIPTION_DATA_H__

#include "maxon/datadescription.h"
#include "maxon/fid.h"

namespace maxon
{
using VariadicIdsElement = Tuple<Int, Id, String, HashMap<Id, Int /* portState */>>;

using VariadicIdsType = Array<VariadicIdsElement>;

MAXON_DATATYPE(VariadicIdsElement, "net.maxon.datatype.variadicidselement"); // TODO: (Ole) This can be removed when HashSet<T> is supported by the data type system. Not urgent.
}

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace DESCRIPTION
{
	namespace BASE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.base");

		/// Defines the type of a resource attribute. 
		/// Note that "command" type don't support propagation. only "attribute" commands can be propagated.
		MAXON_ATTRIBUTE(Id, COMMAND, "net.maxon.description.base.command",
			RESOURCE_DEFINE(ENUM_ATTRIBUTE, Id("attribute"))
			RESOURCE_DEFINE(ENUM_GROUP, Id("group"))
			RESOURCE_DEFINE(ENUM_PRESET, Id("preset"))
			RESOURCE_DEFINE(ENUM_SEPARATOR, Id("separator"))
			RESOURCE_DEFINE(ENUM_STRING, Id("string"))
			RESOURCE_DEFINE(ENUM_EXPORTEDSTRING, Id("exportedstring"))
			RESOURCE_DEFINE(ENUM_COMMAND, Id("command"))
			RESOURCE_DEFINE(ENUM_COMMANDSEPARATOR, Id("commandseparator"))
			RESOURCE_DEFINE(ENUM_INCLUDE, Id("include"))
			RESOURCE_DEFINE(ENUM_REMOVE, Id("remove"))
			RESOURCE_DEFINE(ENUM_VALUE, Id("value")));

		MAXON_ATTRIBUTE(InternedId, IDENTIFIER, "net.maxon.description.base.identifier");

		/// database version for db conversion
		MAXON_ATTRIBUTE(Int, DBVERSION, "net.maxon.description.base.dbversion");

		namespace INCLUDE
		{
			namespace GROUP
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.base.include.group");
				MAXON_ATTRIBUTE(Group, GROUP, "net.maxon.description.base.group");

				MAXON_ATTRIBUTE(Group, DATA_BASE_GROUP, "net.maxon.description.data.base.group");

				MAXON_ATTRIBUTE(Group, UI_BASE_GROUP, "net.maxon.description.ui.base.group");

				MAXON_ATTRIBUTE(Group, STRING_BASE_GROUP, "net.maxon.description.string.base.group");

				MAXON_ATTRIBUTE(Group, DATA_BASE_GROUPDEV, "net.maxon.description.data.base.groupdev");
			}
		}
	}

	namespace DATA
	{
		namespace BASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.data.base");

			// supports MAXON::DESCRIPTION::BASE::COMMAND
			// supports MAXON::DESCRIPTION::BASE::IDENTIFIER
			// supports MAXON::DESCRIPTION::BASE::DBVERSION

			/// Use DataTypeLib::GetRuntimeDataType to query the correct const DataType*. Some datatypes need to be converted into runtime types.
			/// E.g. "int" and "float" will be adjusted to the 32 or 64 types which the compiler defined for the current platform.
			/// But also types based on Int or Float (such as Vector) have to be converted.
			MAXON_ATTRIBUTE(Id, DATATYPE, "net.maxon.description.data.base.datatype",
				RESOURCE_DEFINE(ENUM_REGISTRYENTRY_NET_MAXON_REGISTRY_DATATYPECPPIDENTIFIERS, Id("registryentry#net.maxon.registry.datatypecppidentifiers"))
				RESOURCE_DEFINE(ENUM_REGISTRY_MAXON_DB_DATADESCRIPTIONS, Id("registry#maxon.db.datadescriptions")));

			/// Classification of the attribute. This can be any of the given enum types.
			MAXON_ATTRIBUTE(Id, CLASSIFICATION, "net.maxon.description.data.base.classification",
				RESOURCE_DEFINE(ENUM_NONE, Id("none"))
				RESOURCE_DEFINE(ENUM_INPUT, Id("input"))
				RESOURCE_DEFINE(ENUM_OUTPUT, Id("output"))
				RESOURCE_DEFINE(ENUM_DATA, Id("data")));

			MAXON_ATTRIBUTE(void, GUIANDLIMITPRESET, "net.maxon.description.data.base.guiandlimitpreset");

			MAXON_ATTRIBUTE(Id, UNIT, "net.maxon.description.data.base.unit",
				RESOURCE_DEFINE(ENUM_NONE, Id("none"))
				RESOURCE_DEFINE(ENUM_PERCENT, Id("percent"))
				RESOURCE_DEFINE(ENUM_DEGREE, Id("degree"))
				RESOURCE_DEFINE(ENUM_METER, Id("meter"))
				RESOURCE_DEFINE(ENUM_TIME, Id("time")));

			MAXON_ATTRIBUTE(Data, DEFAULTVALUE, "net.maxon.description.data.base.defaultvalue");

			MAXON_ATTRIBUTE(Id, LIMITVALUE, "net.maxon.description.data.base.limitvalue",
				RESOURCE_DEFINE(ENUM_NONE, Id("none"))
				RESOURCE_DEFINE(ENUM_MIN, Id("min"))
				RESOURCE_DEFINE(ENUM_MAX, Id("max"))
				RESOURCE_DEFINE(ENUM_BOTH, Id("both")));

			MAXON_ATTRIBUTE(Data, MINVALUE, "net.maxon.description.data.base.minvalue");

			MAXON_ATTRIBUTE(Data, MAXVALUE, "net.maxon.description.data.base.maxvalue");

			MAXON_ATTRIBUTE(Id, INCLUDE, "net.maxon.description.data.base.include");

			/// Fill with a list of identifier pairs such as "attribute_identifier->renamed_identifier" (one per line) to remap some of the included attributes.
			/// Attributes which are not remapped will be included using their  original identifier.
			MAXON_ATTRIBUTE(Array<Id>, INCLUDERENAME, "net.maxon.description.data.base.includerename");

			/// Fill with list of attribute identifiers (one per line) to whitelist them. All other included attributes will be skipped.
			MAXON_ATTRIBUTE(Array<Id>, INCLUDEFILTER, "net.maxon.description.data.base.includefilter");

			MAXON_ATTRIBUTE(MAXON_MACROARG_TYPE(Array<Tuple<Id, Data>>), ENUM, "net.maxon.description.data.base.enum");

			/// Command info: database ID which loaded this description.
			MAXON_ATTRIBUTE(Id, DATABASEID, "net.maxon.description.data.base.databaseid");

			/// True if the attribute should be overwritable for takes in the take system.
			MAXON_ATTRIBUTE(Bool, OVERWRITABLE, "net.maxon.description.data.base.overwritable");

			/// This attribute is set for a variadic port. A variadic port can be expanded a number of times.
			MAXON_ATTRIBUTE(Bool, ISVARIADIC, "net.maxon.description.data.base.isvariadic");

			/// This attribute sets the default number of ports of a variadic port.
			MAXON_ATTRIBUTE(Int, VARIADICCOUNT, "net.maxon.description.data.base.variadiccount");

			/// Fill this Id list to have command buttons associated with this attribute. Those commands will propagate with the port.
			MAXON_ATTRIBUTE(Array<Id>, COMMANDS, "net.maxon.description.data.base.commands");

			/// contains an array of IDs in case isvariadic is true.
			/// This value will be filled in programmatically.
			MAXON_ATTRIBUTE(VariadicIdsType, VARIADICIDS, "net.maxon.description.data.base.variadicids");

			/// Show why the element has warnings
			MAXON_ATTRIBUTE(String, WARNINGS, "net.maxon.description.data.base.warnings");

			/// Include export: comment to be added to the include export
			MAXON_ATTRIBUTE(CString, COMMENT, "net.maxon.description.data.base.comment");

			/// Command info: True to prevent this attribute from exporting to the header file.
			MAXON_ATTRIBUTE(Bool, GENERATEIGNOREHEADER, "net.maxon.description.data.base.generateignoreheader");

			/// True if the attribute should be inherited in child descriptions (descriptions that include the current one)..
			/// If true, the entry will show under root or a group in the layout tree so that parameters can be tweaked for the needs of the description making the include.
			/// In other words, this parameter allows to expose an attribute to non developer mode.
			/// Can be used on any attribute type (Attribute, Command, Group, ...).
			MAXON_ATTRIBUTE(Bool, INHERITSTRING, "net.maxon.description.data.base.inheritstring");

			/// True if the string is optional and should receive a translation only if reference language provides a string.
			/// Use this to avoid some translation warnings.
			/// Can be used on any attribute type which contains string data (Attribute, Command, Group, ...).
			MAXON_ATTRIBUTE(Bool, OPTIONALSTRING, "net.maxon.description.data.base.optionalstring");

			/// Command info: namespace that generated that symbol.
			MAXON_ATTRIBUTE(CString, NAMESPACE, "net.maxon.description.data.base.namespace");

			/// Is only set if the attribute was included by another attribute.
			/// Id - database ID of the included object
			/// Data - identifier of the include attribute
			MAXON_ATTRIBUTE(MAXON_MACROARG_TYPE(Tuple<Id, InternedId>), INCLUDEDFROM, "net.maxon.description.data.base.includedfrom");

			/// This value returns the original data type ID which defined the attribute
			MAXON_ATTRIBUTE(Id, ORIGIN, "net.maxon.description.data.base.origin");

			MAXON_ATTRIBUTE(Group, GROUPINFO, "net.maxon.description.data.base.groupinfo");
		}

		namespace INFO
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.data.info");

			/// Classification of this description. This can be any of the given enum types.
			/// node - allowsto define a node which appears in the node editor.
			MAXON_ATTRIBUTE(Id, CLASSIFICATION, "net.maxon.description.data.info.classification",
				RESOURCE_DEFINE(ENUM_UNCLASSIFIED, Id("unclassified"))
				RESOURCE_DEFINE(ENUM_NODE, Id("node"))
				RESOURCE_DEFINE(ENUM_ATTRIBUTE, Id("attribute"))
				RESOURCE_DEFINE(ENUM_PORTBUNDLE, Id("portbundle"))
				RESOURCE_DEFINE(ENUM_TYPE, Id("type"))
				RESOURCE_DEFINE(ENUM_ATTRIBUTE_TEMPLATES, Id("attribute_templates"))
				RESOURCE_DEFINE(ENUM_DESCRIPTION_TEMPLATE, Id("description_template")));

			/// A port of this node for an image Url. This is used when an Url is dropped on the node, and for some image-related node commands.
			MAXON_ATTRIBUTE(CString, IMAGEURLPORT, "net.maxon.description.data.info.imageurlport");

			/// If this is set, the described entity won't show up in the UI.
			MAXON_ATTRIBUTE(Bool, HIDDEN, "net.maxon.description.data.info.hidden");

			MAXON_ATTRIBUTE(String, ENABLING, "net.maxon.description.data.info.enabling");

			/// The processor processes a description, for example to create a node from the description and add it to the nodes registry.
			MAXON_ATTRIBUTE(Id, PROCESSOR, "net.maxon.description.data.info.processor",
				RESOURCE_DEFINE(ENUM_REGISTRY_NET_MAXON_REGISTRY_DESCRIPTIONPROCESSORS, Id("registry#net.maxon.registry.descriptionprocessors")));

			/// Node that will serve as base NodeSystem for the creation of a group (or template).
			MAXON_ATTRIBUTE(Id, PROCESSORBASENODE, "net.maxon.description.data.info.processorbasenode");

			/// Usually called as a finalizing step for customization of the NodeSystem from which will stem the final NodeTemplate.
			MAXON_ATTRIBUTE(Id, PROCESSORCALLBACK, "net.maxon.description.data.info.processorcallback",
				RESOURCE_DEFINE(ENUM_NODEFINALIZERFUNCTIONS_NET_MAXON_NEUTRON, Id("nodefinalizerfunctions#net.maxon.neutron.*"))
				RESOURCE_DEFINE(ENUM_NONE, Id("none")));

			MAXON_ATTRIBUTE(CString, PROCESSORPARAMS, "net.maxon.description.data.info.processorparams");

			/// Command info: include file to generate relative to the executable.
			MAXON_ATTRIBUTE(Url, INCLUDEFILE, "net.maxon.description.data.info.includefile");

			/// Include export: comment to be added to the include export
			MAXON_ATTRIBUTE(CString, COMMENT, "net.maxon.description.data.info.comment");

			/// True when the port bundle is dynamic, i.e., it may have missing or additional members.
			MAXON_ATTRIBUTE(Bool, DYNAMICBUNDLE, "net.maxon.description.data.info.dynamicbundle");

			/// A version string. This can be used to check for dirtyness of data which is derived from the description.
			MAXON_ATTRIBUTE(CString, VERSION, "version");

			MAXON_ATTRIBUTE(Group, INFOGROUP, "infogroup");

			MAXON_ATTRIBUTE(Group, PROCESSORGROUP, "processorgroup");

			MAXON_ATTRIBUTE(Group, EXPORTGROUP, "exportgroup");
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

namespace maxon
{

#include "datadescription_data1.hxx"
#include "datadescription_data2.hxx"



template <typename T> inline Result<void> AddResourceDefault(DataDictionary& props, const T& t, OverloadRank0)
{
	return OK;
}
template <typename T> inline typename SFINAEHelper<Result<void>, typename T::HasDefault>::type AddResourceDefault(DataDictionary& props, const T& t, OverloadRank1)
{
	return props.Set(DESCRIPTION::DATA::BASE::DEFAULTVALUE, Data(t.DEFAULTVALUE));
}

//----------------------------------------------------------------------------------------
/// Converts a given Block<TYPE> to a enum list array to use with DESCRIPTION::DATA::BASE::ENUM.
/// @param[in] enumBlock					Block to convert into a array.
/// @return												BaseArray on success.
//----------------------------------------------------------------------------------------
template <typename TYPE> inline Result<BaseArray<Tuple<Id, Data>>> BlockToEnumArray(const Block<TYPE>& enumBlock)
{
	iferr_scope;
	BaseArray<Tuple<Id, Data>> codecEnum;
	for (const TYPE& val : enumBlock)
	{
		CString str = FormatCString("@", val);
		Id id;
		id.Init(std::move(str)) iferr_return;
		codecEnum.Append(id, Data(val)) iferr_return;
	}
	return std::move(codecEnum);
}

template <typename T> inline Result<void> AddResourceProperty(DataDescription& description, const T& t, const Delegate<Result<void>(DataDictionary& props)>& addProps = nullptr)
{
	iferr_scope;

	const DataType& dataType = GetDataType<typename T::ValueType>();

	if (!dataType)
		return IllegalArgumentError(MAXON_SOURCE_LOCATION).DbgStop();

	Id dataTypeId;
	dataTypeId = dataType->GetId();

	DataDictionary props;
	Data data;
	data.CopyFrom(GetDataType<decltype(t.Get())>(), (const Generic&)t.Get()) iferr_return;
	props.SetData(ConstDataPtr(DESCRIPTION::BASE::IDENTIFIER), std::move(data)) iferr_return;
	props.Set(DESCRIPTION::DATA::BASE::DATATYPE, dataTypeId) iferr_return;
	AddResourceDefault(props, t, OVERLOAD_MAX_RANK) iferr_return;

	if (addProps)
	{
		addProps(props) iferr_return;
	}

	description.SetEntry(props) iferr_return;

	return OK;
}

template <typename T> inline Result<void> EraseResourceProperty(DataDescription& description, const T& t)
{
	iferr_scope;

	description.EraseEntry(t.Get()) iferr_return;

	return OK;
}

}

#endif // DATADESCRIPTION_DATA_H__
