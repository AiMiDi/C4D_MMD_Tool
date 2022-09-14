#include "maxon/graph.h"
#include "maxon/dataserialize.h"

namespace maxon
{

InternedId NodePathInterface::INPUTS;
static InternedIdInitializer g_initNodePathInputs{&NodePathInterface::INPUTS, "<", &PRIVATE_MAXON_MODULE};

InternedId NodePathInterface::OUTPUTS;
static InternedIdInitializer g_initNodePathOutputs{&NodePathInterface::OUTPUTS, ">", &PRIVATE_MAXON_MODULE};

InternedId NodePathInterface::TEMPLATE;
static InternedIdInitializer g_initNodePathTemplate{&NodePathInterface::TEMPLATE, "#", &PRIVATE_MAXON_MODULE};

Result<NodePath> NodePathInterface::GetParent() const
{
	return GetPart(0, StringEnd(-1));
}

Result<GraphTransaction> GraphModelInterface::BeginTransaction(const DataDictionary& userData)
{
	iferr_scope;
	Int nesting = BeginTransactionImpl(userData) iferr_return;
	return GraphTransaction(this, nesting);
}

Result<void> GraphTransaction::Commit(const DataDictionary& userData, Bool validate)
{
	Result<void> res;
	if (_graph)
	{
		res = _graph.GetPointer()->CommitImpl(userData, _nesting, validate);
		_graph = nullptr;
	}
	return res;
}

Bool GraphNode::IsInner() const
{
	return GetPath().GetNodeDepth() > GetGraph().GetRootPath().GetCount();
}

}
