#ifndef GRAPH_SELECTION_H__
#define GRAPH_SELECTION_H__

#include "maxon/selection.h"
#include "maxon/graph.h"

namespace maxon
{

MAXON_ATTRIBUTE(DataDictionary, GraphNodeSelection, "net.maxon.mvp.graphnodeselection");
MAXON_ATTRIBUTE(DataDictionary, GraphPortSelection, "net.maxon.mvp.graphportselection");
MAXON_ATTRIBUTE(DataDictionary, GraphWireSelection, "net.maxon.mvp.graphwireselection");


namespace details
{

template <typename> inline Opt<IoNodePath> GetPath(const IoNodePath& p)
{
	return p;
}


template <typename KEY> static Result<void> SetSelectionImpl(DataDictionary& dict, const KEY& key, SELECTION_MODE mode)
{
	iferr_scope;
	if (mode == SELECTION_MODE::TOGGLE)
	{
		mode = SELECTION_MODE::ADD;
		if (dict.IsPopulated())
		{
			const Data* c = dict.GetPointer()->PrivateGetData(ConstDataPtr(key));
			if (c && *c == Data(true))
				mode = SELECTION_MODE::SUBTRACT;
		}
	}
	if (mode == SELECTION_MODE::SUBTRACT)
	{
		dict.Erase(key) iferr_return;
	}
	else
	{
		dict.Set(key, Data(true)) iferr_return;
	}
	return OK;
}

template <typename ATTR, typename PRES, typename SEL> static Result<void> SetGraphSelectionImpl(const GraphNode& root, const SEL& selection, SELECTION_MODE mode)
{
	iferr_scope;

	Int rootPathLen = root.GetPath().GetCount();

	DataDictionary dict;

	if (mode != SELECTION_MODE::NEW)
	{
		dict = root.GetValue<ATTR>().GetValueOrDefault() iferr_return;
	}

	for (const auto& s : selection)
	{
		Opt<IoNodePath> key = maxon::details::GetPath<PRES>(s);
		if (key)
		{
			key->first = key->first.GetPart(rootPathLen, StringEnd()) iferr_return;
			maxon::details::SetSelectionImpl(dict, *key, mode) iferr_return;
		}
	}

	root.SetValue<ATTR>(std::move(dict)) iferr_return;

	return OK;
}

}

namespace TransactionProperties
{
	MAXON_ATTRIBUTE(NodePath, SelectionRoot, "net.maxon.graph.selectionroot");
	MAXON_ATTRIBUTE(Bool, SelectionTransaction, "net.maxon.graph.selectiontransaction");
	MAXON_ATTRIBUTE(NodePath, TransactionRoot, "net.maxon.graph.transactionroot");
	MAXON_ATTRIBUTE(Bool, DisableNotifications, "net.maxon.graph.transactiondisablenotifications");
	MAXON_ATTRIBUTE(Bool, DoNotChangeAMMode, "net.maxon.graph.donotchangeammode");
}


template <typename ATTR, typename PRES, typename SEL> static Result<void> SetGraphSelection(const GraphNode& root, const SEL& selection, SELECTION_MODE mode, const DataDictionary& userData)
{
	iferr_scope;

	auto gt = root.GetGraph().BeginTransaction(userData) iferr_return;
	maxon::details::SetGraphSelectionImpl<ATTR, PRES>(root, selection, mode) iferr_return;
	DataDictionary commitData;
	commitData.Set(TransactionProperties::SelectionRoot, root.GetPath()) iferr_return;
	if (gt.GetNesting() == 0)
	{
		commitData.Set(TransactionProperties::SelectionTransaction, true) iferr_return;
	}
	gt.Commit(commitData, false) iferr_return;
	
	return OK;
}

#include "graph_selection1.hxx"
#include "graph_selection2.hxx"

} // namespace maxon

#endif // GRAPH_SELECTION_H__
