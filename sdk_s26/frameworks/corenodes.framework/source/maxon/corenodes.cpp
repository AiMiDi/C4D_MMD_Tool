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
	AppendParam(type->GetId().GetCString());
	return std::move(*this);
}

void IdBuilder::AppendParam(const Char* str)
{
	if (_name.IsEmpty() || (_name[_name.GetLength()-1] != '>'))
	{
		AppendChar('<');
	}
	else
	{
		_name[_name.GetLength()-1] = ',';
	}
	AppendString(str);
	AppendChar('>');
}

void IdBuilder::AppendString(const Char* str)
{
	iferr (_name.Append(str, strlen(str)))
		DebugStop("TODO: (Ole) please check if error handling is necessary -> Yes we do");
}

void IdBuilder::AppendString(Block<const Char> str)
{
	iferr (_name.Append(str))
		DebugStop("TODO: (Ole) please check if error handling is necessary -> Yes we do");
}

void IdBuilder::AppendChar(Char ch)
{
	iferr (_name.AppendChar(ch))
		DebugStop("TODO: (Ole) please check if error handling is necessary -> Yes we do");
}

String ConversionSequence::ToString(const FormatStatement* fs) const
{
	return ToBlock().ToString(fs);
}

void MicroNodeGroupInterface::PrivateAutoCreatePortInfo::CreatePort(Int pid, const Id& name, MicroNode::TYPE type, MicroNode::FLAGS flags, const DataType& vtype, Int count)
{
	if (result == FAILED)
		return;
	DataType typeOverride;
	if (getPortType)
	{
		auto x = getPortType(name, arg);
		if (x == FAILED)
		{
			result = x;
			return;
		}
		typeOverride = std::move(x.GetValue());
	}
	result = group->PrivateCreatePort(pid, name, type, flags, typeOverride ? typeOverride : vtype, count);
}

}

} // namespace maxon
