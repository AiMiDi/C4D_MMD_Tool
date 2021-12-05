#ifndef DATATYPE_BUILDER_H__
#define DATATYPE_BUILDER_H__

#include "maxon/basearray.h"
#include "maxon/global.h"
#include "maxon/object.h"

namespace maxon
{

#define FOLDER_BASIC			Id("#$01Basic")
#define FOLDER_ADVANCED		Id("#$02Advanced")
#define FOLDER_STRUCTURE	Id("#$03Structure")
#define FOLDER_MODULES		Id("#$04Modules")

enum class DATATYPEBUILDERNAME
{
	HUMAN_READABLE,
	CODE_CPP,
} MAXON_ENUM_LIST(DATATYPEBUILDERNAME);


class ParametricTypeInterface;

struct DataTypeComponent
{
	Int														 _identifier = -1;
	String												 _compName, _name;
	DataType											 _type;
	Id														 _typeId;
	Id 															_parametricTypeId;
	const ParametricTypeInterface* _additionalRefType = nullptr;
	BaseArray<DataTypeComponent>	 _children;

	String ToString(const FormatStatement* formatStatement = nullptr) const
	{
		if (_name.IsPopulated())
			return FormatString("@: @ @", _name, _compName, _children);
		else
			return FormatString("@ @", _compName, _children);
	}
};



class DataTypeBuilderInterface : MAXON_INTERFACE_BASES(Object)
{
	MAXON_INTERFACE(DataTypeBuilderInterface, MAXON_REFERENCE_NORMAL, "net.maxon.datatype.builder");

public:
	static MAXON_METHOD Result<String> GetDataTypeName(const DataType& dt, DATATYPEBUILDERNAME category);
	static MAXON_METHOD Result<Tuple<String, Bool>> RecurseDataType(DATATYPEBUILDERNAME category, const Member& dt, const ParametricTypeInterface* parentTypeId, Int& globalIdentifier, BaseArray<DataTypeComponent>& components);
};

#include "datatype_builder1.hxx"
#include "datatype_builder2.hxx"

using GetChildrenTypesCallback = Delegate<Result<Tuple<String, Bool>>(const Member& elementType, const ParametricTypeInterface* parametricType)>;
using GetDataTypeNameDelegate = Delegate<Result<Tuple<String, String>>(DATATYPEBUILDERNAME category, const DataType& dt, const GetChildrenTypesCallback& getChildrenTypes, const ParametricTypeInterface* parentTypeId, const ParametricTypeInterface** skipParentType)>;
using GetChildrenCountDelegate = Delegate<Tuple<Int, Int, Bool>()>;
using InstantiateDataTypeDelegate = Delegate<Result<DataType>(const BaseArray<Member>& members)>;
using GetParentTypeSupportDelegate = Delegate<Block<ParametricType>()>;
using GetFolderDelegate = Delegate<Block<const Id>()>;

//----------------------------------------------------------------------------------------
/// This extension point allows to declare the cpp identifiers for types used in the description editor.
/// It's used to translate the datatype back to a cpp identifier.
//----------------------------------------------------------------------------------------
class DataTypeBuilderEntry
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(DataTypeBuilderEntry);

public:
	DataTypeBuilderEntry() = default;
	DataTypeBuilderEntry(DataTypeBuilderEntry&&) = default;

	MAXON_OPERATOR_MOVE_ASSIGNMENT(DataTypeBuilderEntry);

	Result<void> CopyFrom(const DataTypeBuilderEntry& src)
	{
		iferr_scope;
		getFolder.CopyFrom(src.getFolder) iferr_return;
		getName.CopyFrom(src.getName) iferr_return;
		getChildrenCount.CopyFrom(src.getChildrenCount) iferr_return;
		instantiateDataType.CopyFrom(src.instantiateDataType) iferr_return;
		getParentTypeSupport.CopyFrom(src.getParentTypeSupport) iferr_return;
		return OK;
	}

	GetFolderDelegate						 getFolder;
	GetDataTypeNameDelegate			 getName;
	GetChildrenCountDelegate		 getChildrenCount;
	InstantiateDataTypeDelegate	 instantiateDataType;
	GetParentTypeSupportDelegate getParentTypeSupport;
};

MAXON_DATATYPE(DataTypeBuilderEntry, "net.maxon.datatype.datatypebuilderentry");

MAXON_REGISTRY(DataTypeBuilderEntry, DataTypeBuilderRegistry, "net.maxon.registry.datatypebuilderregistry");

//----------------------------------------------------------------------------------------
/// This macro allows to define a specialized data type for the resource editor and datatype ui.
/// this function must not be used for general types like Tuple<Id, Id> etc.
/// Please use only for your own classes wrapped into something from maxon api. 
/// e.g.: MAXON_REGISTER_DATATYPEBUILDER_TYPE(DataRef, "maxon::DataRef", "DataRef");
//----------------------------------------------------------------------------------------
#define MAXON_REGISTER_DATATYPEBUILDER_TYPE(TYPE, STRING, HUMAN, FOLDER) \
	static Global<GenericData> g_datatypeBuilder##TYPE##Registration{ []() -> Result<GenericData> \
	{ \
		return DataTypeBuilderRegistry::Register(GetDataType<TYPE, GET_DATATYPE_POLICY::ALLOW_BASEARRAY>().GetId(), DataTypeBuilderEntry \
		{ \
			[]() -> Block<const Id> { static Id folder[] = {FOLDER}; return folder; }, \
			[](DATATYPEBUILDERNAME category, const DataType& dt, const GetChildrenTypesCallback& getChildrenTypes, const ParametricTypeInterface* parentTypeId, const ParametricTypeInterface** skipParentType) -> Result<Tuple<String, String>> \
			{ return category == DATATYPEBUILDERNAME::CODE_CPP ? Tuple<String, String>{ STRING##_s, STRING##_s } : Tuple<String, String>{ HUMAN##_s, HUMAN##_s }; }, \
			[]() ->Tuple<Int, Int, Bool> { return { 0, 0, false }; }, \
			{}, {} \
		}); \
	} }

}

#endif // DATATYPE_BUILDER_H__
