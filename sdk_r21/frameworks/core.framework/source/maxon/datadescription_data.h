#ifndef DATADESCRIPTION_DATA_H__
#define DATADESCRIPTION_DATA_H__

#include "maxon/datadescription.h"
#include "maxon/fid.h"

namespace maxon
{
using VariadicIdsElement = Tuple<Int, Id, String, HashMap<Id, Int /* portState */>>;

using VariadicIdsType = BaseArray<VariadicIdsElement>;

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

		MAXON_ATTRIBUTE(maxon::Id, COMMAND, "net.maxon.description.base.command",
			RESOURCE_DEFINE(ENUM_ATTRIBUTE, maxon::Id("attribute"))
			RESOURCE_DEFINE(ENUM_GROUP, maxon::Id("group"))
			RESOURCE_DEFINE(ENUM_PRESET, maxon::Id("preset"))
			RESOURCE_DEFINE(ENUM_SEPARATOR, maxon::Id("separator"))
			RESOURCE_DEFINE(ENUM_STRING, maxon::Id("string"))
			RESOURCE_DEFINE(ENUM_EXPORTEDSTRING, maxon::Id("exportedstring"))
			RESOURCE_DEFINE(ENUM_COMMAND, maxon::Id("command"))
			RESOURCE_DEFINE(ENUM_COMMANDSEPARATOR, maxon::Id("commandseparator"))
			RESOURCE_DEFINE(ENUM_INCLUDE, maxon::Id("include"))
			RESOURCE_DEFINE(ENUM_REMOVE, maxon::Id("remove"))
			RESOURCE_DEFINE(ENUM_VALUE, maxon::Id("value")));

		MAXON_ATTRIBUTE(maxon::InternedId, IDENTIFIER, "net.maxon.description.base.identifier");

		MAXON_ATTRIBUTE(Group, GROUP, "net.maxon.description.base.group");

		MAXON_ATTRIBUTE(Group, DATA_BASE_GROUP, "net.maxon.description.data.base.group");

		MAXON_ATTRIBUTE(Group, UI_BASE_GROUP, "net.maxon.description.ui.base.group");

		MAXON_ATTRIBUTE(Group, STRING_BASE_GROUP, "net.maxon.description.string.base.group");
	}

	namespace DATA
	{
		namespace BASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.data.base");

			// supports MAXON::DESCRIPTION::BASE::COMMAND
			// supports MAXON::DESCRIPTION::BASE::IDENTIFIER

			/// Use DataTypeLib::GetRuntimeDataType to query the correct const DataType*. Some datatypes need to be converted into runtime types.
			/// E.g. "int" and "float" will be adjusted to the 32 or 64 types which the compiler defined for the current platform.
			/// But also types based on Int or Float (such as Vector) have to be converted.
			MAXON_ATTRIBUTE(maxon::Id, DATATYPE, "net.maxon.description.data.base.datatype",
				RESOURCE_DEFINE(ENUM_REGISTRYENTRY_NET_MAXON_REGISTRY_DATATYPECPPIDENTIFIERS, maxon::Id("registryentry#net.maxon.registry.datatypecppidentifiers"))
				RESOURCE_DEFINE(ENUM_REGISTRY_MAXON_DB_DATADESCRIPTIONS, maxon::Id("registry#maxon.db.datadescriptions")));

			/// Classification of the attribute. This can be any of the given enum types.
			MAXON_ATTRIBUTE(maxon::Id, CLASSIFICATION, "net.maxon.description.data.base.classification",
				RESOURCE_DEFINE(ENUM_NONE, maxon::Id("none"))
				RESOURCE_DEFINE(ENUM_INPUT, maxon::Id("input"))
				RESOURCE_DEFINE(ENUM_OUTPUT, maxon::Id("output"))
				RESOURCE_DEFINE(ENUM_DATA, maxon::Id("data")));

			MAXON_ATTRIBUTE(maxon::Id, UNIT, "net.maxon.description.data.base.unit",
				RESOURCE_DEFINE(ENUM_NONE, maxon::Id("none"))
				RESOURCE_DEFINE(ENUM_PERCENT, maxon::Id("percent"))
				RESOURCE_DEFINE(ENUM_DEGREE, maxon::Id("degree"))
				RESOURCE_DEFINE(ENUM_METER, maxon::Id("meter"))
				RESOURCE_DEFINE(ENUM_TIME, maxon::Id("time")));

			MAXON_ATTRIBUTE(maxon::Data, DEFAULTVALUE, "net.maxon.description.data.base.defaultvalue");

			MAXON_ATTRIBUTE(maxon::Bool, LIMITVALUE, "net.maxon.description.data.base.limitvalue");

			MAXON_ATTRIBUTE(maxon::Data, MINVALUE, "net.maxon.description.data.base.minvalue");

			MAXON_ATTRIBUTE(maxon::Data, MAXVALUE, "net.maxon.description.data.base.maxvalue");

			MAXON_ATTRIBUTE(maxon::Id, INCLUDE, "net.maxon.description.data.base.include");

			MAXON_ATTRIBUTE(maxon::BaseArray<maxon::Id>, INCLUDERENAME, "net.maxon.description.data.base.includerename");

			MAXON_ATTRIBUTE(maxon::BaseArray<maxon::Id>, INCLUDEFILTER, "net.maxon.description.data.base.includefilter");

			MAXON_ATTRIBUTE(MAXON_MACROARG_TYPE(maxon::BaseArray<maxon::Tuple<maxon::Id, maxon::Data>>), ENUM, "net.maxon.description.data.base.enum");

			/// Command info: database id which loaded this description.
			MAXON_ATTRIBUTE(maxon::Id, DATABASEID, "net.maxon.description.data.base.databaseid");

			/// True if the attribute should be overwritable for takes in the take system.
			MAXON_ATTRIBUTE(maxon::Bool, OVERWRITABLE, "net.maxon.description.data.base.overwritable");

			/// This attribute is set for a variadic port. A variadic port can be expanded a number of times.
			MAXON_ATTRIBUTE(maxon::Bool, ISVARIADIC, "net.maxon.description.data.base.isvariadic");

			/// This attribute sets the default number of ports of a variadic port.
			MAXON_ATTRIBUTE(maxon::Int, VARIADICCOUNT, "net.maxon.description.data.base.variadiccount");

			MAXON_ATTRIBUTE(maxon::BaseArray<maxon::Id>, VARIADICCOMMANDS, "net.maxon.description.data.base.variadiccommands");

			/// contains an array of ids in case isvariadic is true.
			/// This value will be filled in programmatically.
			MAXON_ATTRIBUTE(maxon::VariadicIdsType, VARIADICIDS, "net.maxon.description.data.base.variadicids");

			/// Include export: comment to be added to the include export
			MAXON_ATTRIBUTE(maxon::CString, COMMENT, "net.maxon.description.data.base.comment");

			/// Command info: True to prevent this attribute from exporting to the header file.
			MAXON_ATTRIBUTE(maxon::Bool, GENERATEIGNOREHEADER, "net.maxon.description.data.base.generateignoreheader");

			/// True if the string should be inherited to descriptions which include this description.
			MAXON_ATTRIBUTE(maxon::Bool, INHERITSTRING, "net.maxon.description.data.base.inheritstring");

			/// True if the string is optional and doesn't need to be translated.
			MAXON_ATTRIBUTE(maxon::Bool, OPTIONALSTRING, "net.maxon.description.data.base.optionalstring");

			/// Command info: namespace that generated that symbol.
			MAXON_ATTRIBUTE(maxon::CString, NAMESPACE, "net.maxon.description.data.base.namespace");

			/// Is only set if the attribute was included by another attribute.
			/// Id - database id of the included object
			/// Data - identifier of the include attribute
			MAXON_ATTRIBUTE(MAXON_MACROARG_TYPE(maxon::Tuple<maxon::Id, maxon::InternedId>), INCLUDEDFROM, "net.maxon.description.data.base.includedfrom");

			/// This value returns the original data type id which defined the attribute
			MAXON_ATTRIBUTE(maxon::Id, ORIGIN, "net.maxon.description.data.base.origin");

			MAXON_ATTRIBUTE(Group, GROUPDEV, "net.maxon.description.data.base.groupdev");
		}

		namespace INFO
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.data.info");

			/// Classification of this description. This can be any of the given enum types.
			/// node - allowsto define a node which appears in the node editor.
			MAXON_ATTRIBUTE(maxon::Id, CLASSIFICATION, "net.maxon.description.data.info.classification",
				RESOURCE_DEFINE(ENUM_UNCLASSIFIED, maxon::Id("unclassified"))
				RESOURCE_DEFINE(ENUM_TYPE, maxon::Id("type"))
				RESOURCE_DEFINE(ENUM_STRUCT, maxon::Id("struct"))
				RESOURCE_DEFINE(ENUM_PORTBUNDLE, maxon::Id("portbundle"))
				RESOURCE_DEFINE(ENUM_NODE, maxon::Id("node"))
				RESOURCE_DEFINE(ENUM_TEMPLATE, maxon::Id("template"))
				RESOURCE_DEFINE(ENUM_GLOBAL, maxon::Id("global")));

			/// The processor processes a description, for example to create a node from the description and add it to the nodes registry.
			MAXON_ATTRIBUTE(maxon::Id, PROCESSOR, "net.maxon.description.data.info.processor",
				RESOURCE_DEFINE(ENUM_REGISTRY_NET_MAXON_REGISTRY_DESCRIPTIONPROCESSORS, maxon::Id("registry#net.maxon.registry.descriptionprocessors")));

			MAXON_ATTRIBUTE(maxon::CString, PROCESSORPARAMS, "net.maxon.description.data.info.processorparams");

			/// A port of this node for an image Url. This is used when an Url is dropped on the node, and for some image-related node commands.
			MAXON_ATTRIBUTE(maxon::CString, IMAGEURLPORT, "net.maxon.description.data.info.imageurlport");

			/// Command info: include file to generate relative to the executable.
			MAXON_ATTRIBUTE(maxon::Url, INCLUDEFILE, "net.maxon.description.data.info.includefile");

			/// Include export: comment to be added to the include export
			MAXON_ATTRIBUTE(maxon::CString, COMMENT, "net.maxon.description.data.info.comment");

			/// If this is set, the described entity won't show up in the UI.
			MAXON_ATTRIBUTE(maxon::Bool, HIDDEN, "net.maxon.description.data.info.hidden");
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
		id.Init(str) iferr_return;
		codecEnum.Append({ id, Data(val) }) iferr_return;
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
