#ifndef NODE_UNDO_H__
#define NODE_UNDO_H__

#include "maxon/graph.h"

namespace maxon
{
namespace nodes
{

//----------------------------------------------------------------------------------------
/// Type of the UndoMode attribute.
//----------------------------------------------------------------------------------------
enum class UNDO_MODE
{
	NONE	= 0,	///< Don't add an undo entry.
	START = 1,	///< Start a new undo and create an entry.
	ADD		= 2,	///< Add an undo entry, but don't start a new undo.
} MAXON_ENUM_LIST(UNDO_MODE);

//----------------------------------------------------------------------------------------
/// UndoMode controls the automatic creation of an undo entry in the undo buffer.
/// Usually an entry in the undo buffer of Cinema 4D is added whenever a transaction is started
/// for the currently edited node graph. If you set this attribute to UNDO_MODE::NONE in the dictionary
/// which is passed to GraphModelRef::BeginTransaction no undo entry is added.
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(UNDO_MODE, UndoMode, "net.maxon.nodes.undomode");



MAXON_ATTRIBUTE(Bool, NimbusUndoAttribute, "net.maxon.nodes.nimbusundoattribute");

//----------------------------------------------------------------------------------------
/// GraphSetUndoMode is an RAII-based convenience wrapper to ensure modifications done to a node graph
/// do not interfere with other components with write access to the same node graph.
///
/// The life-time of the instance should enclose the node graph modification:
/// @code
/// MAXON_SCOPE // My graph modification.
/// {
///		maxon::nodes::GraphSetUndoMode undo(node.GetGraph());
///		auto transaction = node.GetGraph().BeginTransaction() iferr_return;
///		.. // The change applied to the node graph.
///		transaction.Commit() iferr_return;
/// }
/// @endcode
//----------------------------------------------------------------------------------------
class GraphSetUndoMode
{
public:

	//----------------------------------------------------------------------------------------
	/// Constructs the RAII-based wrapper.
	/// @param[in] graph			The node graph that is to be modified.
	//----------------------------------------------------------------------------------------
	explicit GraphSetUndoMode(const GraphModelRef& graph) : _graph(graph)
	{
		_previous = graph.GetRoot().GetValue(NimbusUndoAttribute).GetValueOrDefault() iferr_ignore("no error handling possible here");
		graph.GetRoot().SetValue(NimbusUndoAttribute, ConstDataPtr(true), false) iferr_ignore("no error handling possible here");
	}

	//----------------------------------------------------------------------------------------
	/// Resets the undo state of the specified node graph.
	//----------------------------------------------------------------------------------------
	~GraphSetUndoMode()
	{
		if (_graph)
			_graph.GetRoot().SetValue(NimbusUndoAttribute, ConstDataPtr(_previous), false) iferr_ignore("no error handling possible here");
	}

private:
	const GraphModelRef& _graph;
	Bool _previous = false;
};

} // namespace nodes
} // namespace maxon

#endif // NODE_UNDO_H__
