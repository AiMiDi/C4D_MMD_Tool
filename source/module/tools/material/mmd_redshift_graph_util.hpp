#pragma once

#include "module/core/cmt_marco.h"
#include <string>

#if CMT_SDK_HAS_REDSHIFT_NODE_API
#include "maxon/graph.h"
#include "maxon/graph_helper.h"
#include "maxon/nodesgraph.h"
#include "maxon/node_undo.h"

namespace mmd_rs
{
inline constexpr maxon::LiteralId Space("com.redshift3d.redshift4c4d.class.nodespace");
inline constexpr const char* Core = "com.redshift3d.redshift4c4d.nodes.core.";
inline constexpr const char* OutputAsset = "com.redshift3d.redshift4c4d.node.output";

inline maxon::Id CoreId(const char* suffix)
{
	iferr_scope_handler { return maxon::Id(); };
	const std::string value = std::string(Core) + suffix;
	maxon::Id result;
	// Id(const char*) borrows its input. Own the assembled string after return;
	// an allocation failure returns a null ID which required-node checks reject.
	result.Init(value.c_str(), true) iferr_return;
	return result;
}

inline maxon::Result<maxon::GraphTransaction> Transaction(const maxon::nodes::NodesGraphModelRef& graph)
{
	iferr_scope;
	maxon::DataDictionary settings;
	settings.Set(maxon::nodes::UndoMode, maxon::nodes::UNDO_MODE::NONE) iferr_return;
	return graph.BeginTransaction(settings);
}

inline maxon::Result<maxon::GraphNode> Input(const maxon::GraphNode& node, const maxon::Id& id)
{
	iferr_scope;
	const auto inputs = node.GetInputs() iferr_return;
	const auto port = inputs.FindChild(id) iferr_return;
	if (!port.IsValid()) return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	return port;
}

inline maxon::Result<maxon::GraphNode> Output(const maxon::GraphNode& node, const maxon::Id& id)
{
	iferr_scope;
	const auto outputs = node.GetOutputs() iferr_return;
	const auto port = outputs.FindChild(id) iferr_return;
	if (!port.IsValid()) return maxon::IllegalStateError(MAXON_SOURCE_LOCATION);
	return port;
}

template <class T>
maxon::Result<void> Set(const maxon::GraphNode& node, const char* port, const T& value)
{
	iferr_scope;
	const auto input = Input(node, CoreId(port)) iferr_return;
	input.SetPortValue(value) iferr_return;
	return maxon::OK;
}

inline maxon::Result<void> Connect(const maxon::GraphNode& source, const maxon::Id& output_id,
	const maxon::GraphNode& target, const maxon::Id& input_id, const maxon::WIRE_MODE mode = maxon::WIRE_MODE::NORMAL)
{
	iferr_scope;
	const auto output = Output(source, output_id) iferr_return;
	const auto input = Input(target, input_id) iferr_return;
	output.Connect(input, mode) iferr_return;
	return maxon::OK;
}

inline maxon::Result<Bool> HasOnlySource(const maxon::GraphNode& source, const maxon::GraphNode& input)
{
	iferr_scope;
	Bool found = false;
	Bool conflict = false;
	maxon::GraphModelHelper::GetDirectPredecessors(input, maxon::NODE_KIND::NODE,
		[&](const maxon::GraphNode& predecessor) -> maxon::Result<Bool>
		{
			if (source == predecessor) found = true;
			else conflict = true;
			return true;
		}) iferr_return;
	return found && !conflict;
}

inline maxon::Color64 Color(const Vector& value)
{
	return maxon::Color64(value.x, value.y, value.z);
}
}
#endif
