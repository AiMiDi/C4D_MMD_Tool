#include "maxon/micronodes_runtime.h"
#include "maxon/corenodes_lib.h"
#include "maxon/corenodes_conversion.h"

namespace maxon
{

namespace corenodes
{

const InPortId InPortId::_nullValue;
const OutPortId OutPortId::_nullValue;

String PortId::ToString(const FormatStatement* fs) const
{
	return IsEmpty() ? "null"_s : IsIndex() ? String::IntToString(GetIndex()) : _name.ToString(fs);
}


Result<CoreNodeInstancePtr> CoreNodeGroupInterface::AddChild(const Id& name, Result<CoreNode>&& node)
{
	if (node == FAILED)
		return node.GetErrorStorage();
	return AddChild(name, node.GetValue());
}

Result<CoreNodeInstancePtr> CoreNodeGroupInterface::AddChild(const Id& name, IdOrBuilder&& nodeId, const DataDictionary& args)
{
	iferr_scope;
	Id i = nodeId.GetId() iferr_return;
	return AddChild(name, CoreNodes::Get(i).Create(args));
}

Result<CoreNodeInstancePtr> CoreNodeGroupInterface::AddChild(const Id& name, IdOrBuilder&& nodeId, Result<DataDictionary>&& args)
{
	iferr_scope;
	DataDictionary dict = args iferr_return;
	return AddChild(name, std::move(nodeId), dict);
}

IdBuilder&& IdBuilder::Append(const DataType& type)
{
	if (_name.IsEmpty() || (_name[_name.GetLength()-1] != '>'))
	{
		AppendChar('<');
	}
	else
	{
		_name[_name.GetLength()-1] = ',';
	}
	AppendString(type->GetId().GetCString());
	AppendChar('>');
	return std::move(*this);
}

void IdBuilder::AppendString(const Char* str)
{
	iferr (_name.Append(str, strlen(str)))
		DebugStop("TODO: (Ole) please check if error handling is necessary");
}

void IdBuilder::AppendChar(Char ch)
{
	iferr (_name.AppendChar(ch))
		DebugStop("TODO: (Ole) please check if error handling is necessary");
}

String ConversionSequence::ToString(const FormatStatement* fs) const
{
	return ToBlock().ToString(fs);
}

}

} // namespace maxon
