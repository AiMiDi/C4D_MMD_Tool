#ifndef GRAPHBASE_H__
#define GRAPHBASE_H__

#include "maxon/apibase.h"
#include "maxon/basearray.h"
#include "maxon/pointerarray.h"
#include "maxon/vector.h"

namespace maxon
{

/// Define graph type
enum class GRAPH_TYPE
{
	CONTINUOS		= 0,	///< The Graph is continuos so all points in array list order.
	SPARSE			= 1		///< The Graph is sparse so points have to be sorted before modeling.
} MAXON_ENUM_LIST(GRAPH_TYPE);

//----------------------------------------------------------------------------------------
/// Basic node template for a graph, reppresent a node with attached strokes pointers list
/// basically an node with an adjacency list.
/// @tparam NODEDATA							Custom Data attched to the node.
/// @tparam EDGE									Edge type have to be GraphEdgeBase<this->Type>.
//----------------------------------------------------------------------------------------
template <typename NODEDATA, typename EDGE> class GraphNodeBase
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(GraphNodeBase)
public:

	typedef GraphNodeBase<NODEDATA, EDGE> NodeType;

	explicit GraphNodeBase() : _data(), _pos(Vector())
	{
		Reset();
	}

	explicit GraphNodeBase(const NODEDATA& data, Vector pos = Vector()) : _data(data), _pos(pos)
	{
		Reset();
	}

	~GraphNodeBase()
	{
		Reset();
	}

	//----------------------------------------------------------------------------------------
	// Move semantics
	//----------------------------------------------------------------------------------------
	GraphNodeBase(GraphNodeBase&& src)
	{
		_pos = src._pos;
		_visited = false;
		_data = std::move(src._data);
		_edges = std::move(src._edges);
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(GraphNodeBase)

	Result<void> CopyFrom(const GraphNodeBase& src)
	{
		_pos = src._pos;
		_visited = false;
		iferr (_edges.CopyFrom(src._edges))
			return err;
		iferr (_data.CopyFrom(src._data))
			return err;
		return  OK;
	}

	//----------------------------------------------------------------------------------------
	/// Get the Node position.
	/// @return												The Node position.
	//----------------------------------------------------------------------------------------
	Vector GetPosition() const
	{
		return _pos;
	}

	//----------------------------------------------------------------------------------------
	/// Set the Node position.
	/// @param[in] pos								The new Node position.
	//----------------------------------------------------------------------------------------
	void SetPosition(const Vector& pos)
	{
		_pos = pos;
	}

	//----------------------------------------------------------------------------------------
	/// Get the edges count for this point.
	/// @return												The PenPoint::EdgeType count.
	//----------------------------------------------------------------------------------------
	Int GetEdgesCount() const
	{
		return _edges.GetCount();
	}

	//----------------------------------------------------------------------------------------
	/// Get the edges at pos in the list.
	/// @param[in] pos								The edge index position.
	/// @return												The PenPoint::EdgeType pointer pos or error if pos is out of bounds.
	//----------------------------------------------------------------------------------------
	Result<EDGE*> GetEdge(Int pos) const
	{
		if (pos >= GetEdgesCount())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		return _edges[pos];
	}

	//----------------------------------------------------------------------------------------
	/// Get The other hand of the edge at index pos.
	/// @param[in] pos								the edge index.
	/// @return												The node pointer otherwise an error.
	//----------------------------------------------------------------------------------------
	Result<NodeType*> GetNeighbor(Int pos)const
	{
		if (pos >= GetEdgesCount())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		EDGE* edge = _edges[pos];
		if (edge)
		{
			return edge->GetOtherHand(this);
		}
		return NullptrError(MAXON_SOURCE_LOCATION);
	}

	//----------------------------------------------------------------------------------------
	/// Find an edge in between this node and otherHand node.
	/// @param[in] otherHand					The other node which create the edge.
	/// @return												The edge pointer of an error if used nodes does not share any edge.
	//----------------------------------------------------------------------------------------
	Result<EDGE*> FindEdge(NodeType* otherHand)
	{
		if (!otherHand)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		for (const auto& it : _edges)
		{
			if (it->IsEqual(this, otherHand))
				return it;
		}

		return IllegalStateError(MAXON_SOURCE_LOCATION);
	}

	//----------------------------------------------------------------------------------------
	/// Add a new edges to the point.
	/// @param[in] edge								The edge to add.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> AddEdge(EDGE* edge)
	{
		if (!edge)
			IllegalArgumentError(MAXON_SOURCE_LOCATION);
		return _edges.Append(edge);
	}

	//----------------------------------------------------------------------------------------
	/// Remove the edge at pos.
	/// @param[in] pos								The edge list index.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> DeleteEdge(Int32 pos)
	{
		if (pos >= GetEdgesCount())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		return _edges.Erase(pos);
	}

	//----------------------------------------------------------------------------------------
	/// Remove edge form the list.
	/// @param[in] edge								The edge to be removed.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> DeleteEdge(EDGE* edge)
	{
		if (!edge)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		if (!_edges.EraseFirst(edge))
			return IllegalStateError(MAXON_SOURCE_LOCATION);
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Get a pointer to user data.
	/// @return												The user data pointer.
	//----------------------------------------------------------------------------------------
	const NODEDATA* GetData() const
	{
		return &_data;
	}

	//----------------------------------------------------------------------------------------
	/// Replace current user data with the passed one, data is duplicated.
	/// @param[in] data								The new data to be used.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> SetData(const NODEDATA& data)
	{
		return _data.CopyFrom(data);
	}

	//----------------------------------------------------------------------------------------
	/// Process this node.
	//----------------------------------------------------------------------------------------
	void Visit()
	{
		_visited = true;
	}

	//----------------------------------------------------------------------------------------
	/// Reset the processing status.
	//----------------------------------------------------------------------------------------
	void Unvisit()
	{
		_visited = false;
	}

	//----------------------------------------------------------------------------------------
	/// Get the processing status.
	/// @return												The processing status.
	//----------------------------------------------------------------------------------------
	Bool IsVisited() const
	{
		return _visited;
	}

	//----------------------------------------------------------------------------------------
	/// Free memory and reset all values, could be extended for each implementation
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_edges.Reset();
	}

protected:
	NODEDATA	_data;								// user custom data
	Vector		_pos;									// node position
	Bool			_visited;							// visited by an algo
	BaseArray<EDGE*> _edges;				// list of stroke pointers attached to this point
};

//----------------------------------------------------------------------------------------
/// Basic edge template for a graph, in case of custom implementation have to be frowarded to the node type.
/// @tparam NODE									The node type in the graph.
//----------------------------------------------------------------------------------------
template <typename NODE> class GraphEdgeBase
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(GraphEdgeBase)

public:
	typedef GraphEdgeBase<NODE> EdgeType;

	explicit GraphEdgeBase(NODE* p1 = nullptr, NODE* p2 = nullptr) : _p1(p1), _p2(p2) { }

	~GraphEdgeBase()
	{
		Reset();
	}

	//----------------------------------------------------------------------------------------
	// Move semantics
	//----------------------------------------------------------------------------------------
	GraphEdgeBase(GraphEdgeBase&& src)
	{
		_p1 = src._p1;
		_p2 = src._p2;
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(GraphEdgeBase)

	Result<void> CopyFrom(const GraphEdgeBase& src)
	{
		_p1 = src._p1;
		_p2 = src._p2;
		return OK;
	}
	//----------------------------------------------------------------------------------------
	/// Update node pointers used after consistency check.
	/// @param[in] p1									First edge node.
	/// @param[in] p2									Second edge node.
	/// @return												OK if both nodes are not nullptr otherwise error.
	//----------------------------------------------------------------------------------------
	Result<void> UpdateNodes(NODE* p1, NODE* p2)
	{
		_p1 = p1;
		_p2 = p2;
		if (_p1 && _p2)
			return OK;
		return IllegalStateError(MAXON_SOURCE_LOCATION);
	}

	//----------------------------------------------------------------------------------------
	/// Check if the edge is in between 2 valid points.
	/// @return												True if edge is valid otherwise false.
	//----------------------------------------------------------------------------------------
	Bool IsValid() const
	{
		return _p1 != nullptr && _p2 != nullptr && _p1 != _p2;
	}

	//----------------------------------------------------------------------------------------
	/// Get the tow main nodes for this edge (copy all data).
	/// @param[out] p1								First node to be filled.
	/// @param[out] p2								Second node to be filled.
	/// @return												OK if both nodes are not nullptr otherwise error.
	//----------------------------------------------------------------------------------------
	Result<void> GetNodes(NODE& p1, NODE& p2) const
	{
		iferr_scope;
		if (!_p1 || !_p2)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		p1.CopyFrom(*_p1) iferr_return;
		p2.CopyFrom(*_p2) iferr_return;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Get the tow main ndoes for this edge.
	/// @param[out] p1								First node to be filled.
	/// @param[out] p2								Second node to be filled.
	/// @return												OK if both nodes are not nullptr otherwise error.
	//----------------------------------------------------------------------------------------
	Result<void> GetNodesPointer(NODE*& p1, NODE*& p2) const
	{
		if (!_p1 || !_p2)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		p1 = _p1;
		p2 = _p2;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Get the tow main node position for this edge.
	/// @param[out] p1								First node to be filled.
	/// @param[out] p2								Second node to be filled.
	/// @return												OK if both nodes are not nullptr otherwise error.
	//----------------------------------------------------------------------------------------
	Result<void> GetNodesPos(Vector& p1, Vector& p2) const
	{
		if (!_p1 || !_p2)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		p1 = _p1->GetPosition();
		p2 = _p2->GetPosition();
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Calculate the distance in between _p1 and _p2.
	/// @return												The stroke length.
	//----------------------------------------------------------------------------------------
	Float GetLength() const
	{
		return (_p1->GetPosition() - _p2->GetPosition()).GetLength();
	}

	//----------------------------------------------------------------------------------------
	/// Return a node pointer on opposite side of the edge.
	/// @param[in] point							The original point.
	/// @param[out] secondPoint				If passed the function set it true if the other hand is _p2 otherwise false.
	/// @return												The opposite side of edge otherwise error.
	//----------------------------------------------------------------------------------------
	Result<NODE*> GetOtherHand(NODE* point, Bool* secondPoint = nullptr) const
	{
		if (!_p1 || !_p2 || !point)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		if (secondPoint)
		{
			*secondPoint = false;
			if (point == _p2)
				*secondPoint = true;
		}

		if (point == _p1)
			return _p2;
		else if (point == _p2)
			return _p1;

		return IllegalStateError(MAXON_SOURCE_LOCATION); // error point is not part of this stroke
	}

	//----------------------------------------------------------------------------------------
	/// Return true if the edge is in between p1 and p2.
	/// @param[in] p1									First edge point to check.
	/// @param[in] p2									Second edge point to check.
	/// @return												True if this edge is in between p1 and p2. otherwise false.
	//----------------------------------------------------------------------------------------
	Bool IsEqual(NODE* p1, NODE* p2) const
	{
		if (!p1 || !p2)
			return false;

		return ((_p1 == p1 && _p2 == p2) || (_p2 == p1 && _p1 == p2));
	}

	//----------------------------------------------------------------------------------------
	/// Free memory and reset all values.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_p1 = nullptr;
		_p2 = nullptr;
	}

protected:
	NODE* _p1;		// first edge node
	NODE* _p2;		// second edge node
};

//----------------------------------------------------------------------------------------
/// Basic undirected graph template.
/// @tparam NODE									The node type in the graph.
/// @tparam EDGE									The edge type in the graph.
//----------------------------------------------------------------------------------------
template <typename NODE, typename EDGE> class GraphBase
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(GraphBase)

public:

	typedef GraphBase<NODE, EDGE> Super;
	typedef NODE NodeType;
	typedef EDGE EdgeType;

	explicit GraphBase() : _type(GRAPH_TYPE::CONTINUOS) { }
	~GraphBase() { }

	//----------------------------------------------------------------------------------------
	// Move semantics
	//----------------------------------------------------------------------------------------
	GraphBase(GraphBase&& src)
	{
		_type = src._type;
		_nodes = std::move(src._nodes);
		_edges = std::move(src._edges);
	}

	MAXON_OPERATOR_MOVE_ASSIGNMENT(GraphBase)

	Result<void> CopyFrom(const GraphBase& src)
	{
		iferr_scope;

		_type = src._type;
		Reset();
		NODE p;
		EDGE s;
		for (const auto& it : src._edges)
		{
			s.CopyFrom(it) iferr_return;
			_edges.Append(s) iferr_return;
		}

		for (const auto& it : src._nodes)
		{
			p.CopyFrom(it) iferr_return;
			_nodes.Append(p) iferr_return;
			// is important to flush edge pointers will change so we have to remap it
			_nodes.GetLast()->Reset();
		}

		// remap edges nodes pointers and rebuild edge list for each node
		// this is necessary to clone the object in a correct way
		// the object could be cloned by undo system at each action
		const EDGE* oldEdge = nullptr;
		EDGE* newEdge = nullptr;
		NODE* oldP1 = nullptr;
		NODE* oldP2 = nullptr;
		NODE* newP1 = nullptr;
		NODE* newP2 = nullptr;
		Int		pointIndex1  = NOTOK;
		Int		pointIndex2  = NOTOK;
		for (Int32 i = 0; i < GetEdgesCount(); ++i)
		{
			oldEdge = &src._edges[i];
			newEdge = GetEdge(i) iferr_return;
			if (oldEdge && newEdge)
			{
				oldEdge->GetNodesPointer(oldP1, oldP2) iferr_return;
				newEdge->GetNodesPointer(newP1, newP2) iferr_return;
				pointIndex1 = src._nodes.GetIndex(*oldP1);
				pointIndex2 = src._nodes.GetIndex(*oldP2);
				if (pointIndex1 == NOTOK || pointIndex2 == NOTOK)
				{
					DebugStop();
					return NullptrError(MAXON_SOURCE_LOCATION);
				}
				newP1 = &_nodes[pointIndex1];
				newP2 = &_nodes[pointIndex2];
				newEdge->UpdateNodes(newP1, newP2) iferr_return;
				newP1->AddEdge(newEdge) iferr_return;
				newP2->AddEdge(newEdge) iferr_return;
			}
		}
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Append src graph t this graph, the existing graph is mantained.
	/// @param[in] src								The graph to append.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> AppendGraph(const GraphBase& src)
	{
		iferr_scope;

		if (_type != src._type)
			return maxon::IllegalArgumentError(MAXON_SOURCE_LOCATION);

		Int initialNodesCount = GetNodesCount();
		Int initialEdgesCount = GetEdgesCount();

		NODE p;
		EDGE s;
		for (const auto& it : src._edges)
		{
			s.CopyFrom(it) iferr_return;
			_edges.Append(s) iferr_return;
		}

		for (const auto& it : src._nodes)
		{
			p.CopyFrom(it) iferr_return;
			_nodes.Append(p) iferr_return;
			// is important to flush edge pointers will change so we have to remap it
			_nodes.GetLast()->Reset();
		}

		// remap edges nodes pointers and rebuild edge list for each node
		// this is necessary to clone the object in a correct way
		// the object could be cloned by undo system at each action
		const EDGE* oldEdge = nullptr;
		EDGE* newEdge = nullptr;
		NODE* oldP1 = nullptr;
		NODE* oldP2 = nullptr;
		NODE* newP1 = nullptr;
		NODE* newP2 = nullptr;
		Int		pointIndex1  = NOTOK;
		Int		pointIndex2  = NOTOK;
		for (Int i = initialEdgesCount; i < GetEdgesCount(); ++i)
		{
			oldEdge = &src._edges[i - initialEdgesCount];
			newEdge = GetEdge(i) iferr_return;
			if (oldEdge && newEdge)
			{
				oldEdge->GetNodesPointer(oldP1, oldP2) iferr_return;
				newEdge->GetNodesPointer(newP1, newP2) iferr_return;
				pointIndex1 = src._nodes.GetIndex(*oldP1);
				pointIndex2 = src._nodes.GetIndex(*oldP2);
				if (pointIndex1 == NOTOK || pointIndex2 == NOTOK)
				{
					DebugStop();
					return NullptrError(MAXON_SOURCE_LOCATION);
				}
				newP1 = &_nodes[pointIndex1 + initialNodesCount];
				newP2 = &_nodes[pointIndex2 + initialNodesCount];
				newEdge->UpdateNodes(newP1, newP2) iferr_return;
				newP1->AddEdge(newEdge) iferr_return;
				newP2->AddEdge(newEdge) iferr_return;
			}
		}
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Get The graph type.
	/// @return												The graph type.
	//----------------------------------------------------------------------------------------
	GRAPH_TYPE GetType() const
	{
		return _type;
	}

	//----------------------------------------------------------------------------------------
	/// Set The graph type.
	/// @param[in] type								The new graph type.
	//----------------------------------------------------------------------------------------
	void SetType(GRAPH_TYPE type)
	{
		_type = type;
	}

	//----------------------------------------------------------------------------------------
	/// Get All nodes count in the graph.
	/// @return												The main point count in the graph.
	//----------------------------------------------------------------------------------------
	Int GetNodesCount(Bool subPoint = false) const
	{
		return _nodes.GetCount();
	}

	//----------------------------------------------------------------------------------------
	/// Get All edge count in the graph.
	/// @return												The stroke count in the graph.
	//----------------------------------------------------------------------------------------
	Int GetEdgesCount() const
	{
		return _edges.GetCount();
	}

	//----------------------------------------------------------------------------------------
	/// Get a pointer to the first node.
	/// @return												A pointer to the first node.
	//----------------------------------------------------------------------------------------
	NODE* GetFirstNode()
	{
		return _nodes.IsEmpty() ? nullptr : _nodes.GetFirst();
	}

	//----------------------------------------------------------------------------------------
	/// Get a pointer to the last node.
	/// @return												A pointer to the last node.
	//----------------------------------------------------------------------------------------
	NODE* GetLastNode()
	{
		return _nodes.IsEmpty() ? nullptr : _nodes.GetLast();
	}

	//----------------------------------------------------------------------------------------
	/// Serch a node with at passed position.
	/// @param[in] position						The 3d position where search the node.
	/// @param[in] tolerance					Search can be tolerat if passed value is != 0.
	/// @return												A pointer to the node if found at position otherwise false.
	//----------------------------------------------------------------------------------------
	NODE* FindNodeByPosition(const Vector& position, Float tolerance = 0.0)
	{
		for (auto& it : _nodes)
		{
			if (position.IsEqual(it.GetPosition(), tolerance))
				return &it;
		}
		return nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Serch a node with at passed position.
	/// @param[in] position						The 3d position where search the node.
	/// @param[in] tolerance					Search can be tolerat if passed value is != 0.
	/// @return												A pointer to the node if found at position otherwise false.
	//----------------------------------------------------------------------------------------
	const NODE* FindNodeByPosition(const Vector& position, Float tolerance = 0.0) const
	{
		for (const auto& it : _nodes)
		{
			if (position.IsEqual(it.GetPosition(), tolerance))
				return &it;
		}
		return nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Get a node in the list.
	/// @param[in] idx								The node index in the list.
	/// @return												A pointer to the entry in the list otherwise error.
	//----------------------------------------------------------------------------------------
	Result<NODE*> GetNode(Int idx)
	{
		if (idx >= _nodes.GetCount())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		return &_nodes[idx];
	}

	//----------------------------------------------------------------------------------------
	/// Get a node in the list.
	/// @param[in] idx								The node index in the list.
	/// @return												A pointer to the entry in the list otherwise error.
	//----------------------------------------------------------------------------------------
	Result<const NODE*> GetNode(Int idx) const
	{
		if (idx >= _nodes.GetCount())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		return &_nodes[idx];
	}

	//----------------------------------------------------------------------------------------
	/// Get the successor node, valid only in continuos graph case.
	/// @param[in] node								The node.
	/// @return												A pointer to the successor node otherwise an error.
	//----------------------------------------------------------------------------------------
	Result<NODE*> GetSuccessor(NODE* node)
	{
		if (GetType() != GRAPH_TYPE::CONTINUOS)
			return IllegalStateError(MAXON_SOURCE_LOCATION).DbgStop();

		Int nodeIndex = _nodes.GetIndex(*node);
		if (nodeIndex == InvalidArrayIndex)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		Int sucIndex = MAXON_UNLIKELY(nodeIndex + 1 >= _nodes.GetCount()) ? 0 : (nodeIndex + 1);
		return &_nodes[sucIndex];
	}

	//----------------------------------------------------------------------------------------
	/// Get the predecessor node, valid only in continuos graph case.
	/// @param[in] node								The node.
	/// @return												A pointer to the Predecessor node otherwise an error.
	//----------------------------------------------------------------------------------------
	Result<NODE*> GetPredecessor(NODE* node)
	{
		if (GetType() != GRAPH_TYPE::CONTINUOS)
			return IllegalStateError(MAXON_SOURCE_LOCATION).DbgStop();

		Int nodeIndex = _nodes.GetIndex(*node);
		if (nodeIndex == InvalidArrayIndex)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		Int predIndex = MAXON_UNLIKELY(nodeIndex == 0) ? (_nodes.GetCount() - 1) : (nodeIndex - 1);
		return &_nodes[predIndex];
	}

	//----------------------------------------------------------------------------------------
	/// Get the successor edge, valid only in continuos graph case.
	/// @param[in] node								The node.
	/// @return												A pointer to the successor edge otherwise an error.
	//----------------------------------------------------------------------------------------
	Result<EDGE*> GetSuccessorEdge(NODE* node)
	{
		iferr_scope;
		NODE* otherHand = GetSuccessor(node) iferr_return;
		return node->FindEdge(otherHand);
	}

	//----------------------------------------------------------------------------------------
	/// Get the predecessor edge, valid only in continuos graph case.
	/// @param[in] node								The node.
	/// @return												A pointer to the Predecessor edge otherwise an error.
	//----------------------------------------------------------------------------------------
	Result<EDGE*> GetPredecessorEdge(NODE* node)
	{
		iferr_scope;
		NODE* otherHand = GetPredecessor(node) iferr_return;
		return node->FindEdge(otherHand);
	}

	//----------------------------------------------------------------------------------------
	/// Check if node exist in the node list and return the index.
	/// @param[in] node								The node to check for.
	/// @return												The node index if found or NOTOK if the node is not in to the list.
	//----------------------------------------------------------------------------------------
	Int FindNode(NODE* node)
	{
		return _nodes.GetIndex(*node);
	}

	//----------------------------------------------------------------------------------------
	/// Get a edge at idx in the list.
	/// @param[in] idx								The edge index in the list.
	/// @return												A pointer to the entry in the list otherwise error.
	//----------------------------------------------------------------------------------------
	Result<EDGE*> GetEdge(Int idx)
	{
		if (idx >= _edges.GetCount())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		return &_edges[idx];
	}

	//----------------------------------------------------------------------------------------
	/// Get a edge at idx in the list.
	/// @param[in] idx								The edge index in the list.
	/// @return												A pointer to the entry in the list otherwise error.
	//----------------------------------------------------------------------------------------
	Result<const EDGE*> GetEdge(Int idx) const
	{
		if (idx >= _edges.GetCount())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);
		return &_edges[idx];
	}

	//----------------------------------------------------------------------------------------
	/// Check if edge exist in the edge list and return the index.
	/// @param[in] edge								The edge to check for.
	/// @return												The edge index if found or NOTOK if the edge is not in to the list.
	//----------------------------------------------------------------------------------------
	Int FindEdge(EDGE* edge)
	{
		return _edges.GetIndex(*edge);
	}

	//----------------------------------------------------------------------------------------
	/// Check if exist a edge in between p1 and p2, if yes return the pointer.
	/// @param[in] p1									First edge point.
	/// @param[in] p2									Second edge point.
	/// @return												A pointer to the edge otherwise error.
	//----------------------------------------------------------------------------------------
	Result<EDGE*> GetEdgeByPoints(NodeType* p1, NodeType* p2) const
	{
		iferr_scope;

		if (!p1 || ! p2)
			IllegalArgumentError(MAXON_SOURCE_LOCATION);

		Int p1Count = p1->GetEdgesCount();
		Int p2Count = p2->GetEdgesCount();
		EDGE* e1 = nullptr;
		EDGE* e2 = nullptr;
		for (Int32 i = 0; i < p1Count; ++i)
		{
			for (Int32 a = 0; a < p2Count; ++a)
			{
				e1 = p1->GetEdge(i) iferr_return;
				e2 = p2->GetEdge(a) iferr_return;
				if (e1 == e2)
					return e1;
			}
		}
		return nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Add a new node to the list.
	/// @param[in] node								The new pen node to add.
	/// @param[in] pos								Optional position in to the array if NOTOK or not passed the point is added at the end of the list.
	/// @return												A pointer to the added entry otherwise error.
	//----------------------------------------------------------------------------------------
	Result<NODE*> AddNode(const NodeType& node, Int pos = NOTOK)
	{
		iferr_scope;

		NODE* res = nullptr;
		Int nodeCount = _nodes.GetCount();
		if (pos != NOTOK && pos != nodeCount)
		{
			if (pos >= nodeCount)
				return IllegalStateError(MAXON_SOURCE_LOCATION);

			res = &_nodes.Insert(pos, node) iferr_return;
		}
		else
		{
			res = &_nodes.Append(node) iferr_return;
		}

		return res;
	}

	//----------------------------------------------------------------------------------------
	/// Add a new edge in between p1 and p2 with type and initialize it.
	/// Automatically map the stoke to the points list.
	/// @param[in] p1									First edge node.
	/// @param[in] p2									Second edge node.
	/// @param[in] pos								If not NOTOK new stroke will be inserted at pos in the list.
	/// @return												A pointer to the new stroke added to the list otherwise error.
	//----------------------------------------------------------------------------------------
	Result<EDGE*> AddEdge(NodeType* p1, NodeType* p2, Int pos = NOTOK)
	{
		iferr_scope;

		EDGE edge;
		edge.UpdateNodes(p1, p2) iferr_return;
		EDGE*	res = nullptr;

		if (pos == NOTOK)
		{
			res = &_edges.Append(edge) iferr_return;
		}
		else
		{
			res = &_edges.Insert(pos, edge) iferr_return;
		}

		p1->AddEdge(res) iferr_return;
		p2->AddEdge(res) iferr_return;

		return res;
	}

	//----------------------------------------------------------------------------------------
	/// Split edge in 2 parts by adding the new node.
	/// @param[in] node								The new node to insert in to the list.
	/// @param[in] edge								The edge to split.
	/// @return												A pointer to the new created node otherwise error.
	//----------------------------------------------------------------------------------------
	Result<NODE*> SplitEdge(const NODE& node, EdgeType* edge)
	{
		iferr_scope;

		if (!edge)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		NodeType* originalP1 = nullptr;
		NodeType* originalP2 = nullptr;

		edge->GetNodesPointer(originalP1, originalP2) iferr_return;

		Int pos = _nodes.GetIndex(*originalP1) + 1;
		NodeType* res = AddNode(node, pos) iferr_return;
		SplitEdge(res, edge) iferr_return;
		return res;
	}

	//----------------------------------------------------------------------------------------
	/// Split edge in 2 parts by attaching it to an existing node.
	/// @param[in] node								The node to attach the strokes.
	/// @param[in] edge								The edge to split.
	/// @return												The new added edge pointer otherwise error.
	//----------------------------------------------------------------------------------------
	Result<EDGE*> SplitEdge(NodeType* node, EdgeType* edge)
	{
		iferr_scope;

		if (!edge || !node)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		NodeType* originalP1 = nullptr;
		NodeType* originalP2 = nullptr;

		edge->GetNodesPointer(originalP1, originalP2) iferr_return;

		originalP2->DeleteEdge(edge) iferr_return;
		edge->Reset();
		edge->UpdateNodes(originalP1, node) iferr_return;
		node->AddEdge(edge) iferr_return;

		return AddEdge(node, originalP2, _edges.GetIndex(*edge) + 1);
	}

	//----------------------------------------------------------------------------------------
	/// Remove node and the connected edges.
	/// @param[in] node								The node to be removed.
	/// @param[in] replaceEdge				If true a new edge will be added to fill the gap, just if the graph is not sparse (max 2 edges per node).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> DeleteNode(NodeType* node, Bool replaceEdge = true)
	{
		if (!node)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		Int pos = _nodes.GetIndex(*node);

		if (pos == NOTOK)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		return DeleteNode(pos, replaceEdge);
	}

	//----------------------------------------------------------------------------------------
	/// Remove node at pos and the connected edges.
	/// @param[in] pos								The index position of node to be removed.
	/// @param[in] replaceEdge				If true a new edge will be added to fill the gap, just if the graph is not sparse (max 2 edges per node).
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> DeleteNode(Int pos, Bool replaceEdge = true)
	{
		iferr_scope;

		if (pos >= GetNodesCount())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		NodeType* 	pp = GetNode(pos) iferr_return;
		NodeType*		source = nullptr;
		NodeType*		dest = nullptr;
		EdgeType*		currentEdge = nullptr;
		Int					edgeCount = pp->GetEdgesCount();
		for (Int i = edgeCount - 1; i >= 0; --i)
		{
			currentEdge = pp->GetEdge(i) iferr_return;
			if (edgeCount == 2 && replaceEdge)
			{
				if (dest)
				{
					source = currentEdge->GetOtherHand(pp) iferr_return;
				}
				else
				{
					dest = currentEdge->GetOtherHand(pp) iferr_return;
				}
			}

			DeleteEdge(currentEdge) iferr_return;
		}
		_nodes.Erase(pos) iferr_return;

		if (source && dest && edgeCount == 2 && replaceEdge)
		{
			Int sourceNodeIndex = _nodes.GetIndex(*source);
			Int destNodeIndex = _nodes.GetIndex(*dest);
			Int nodeIndex = sourceNodeIndex;
			if (sourceNodeIndex > destNodeIndex)
			{
				nodeIndex = destNodeIndex;
				maxon::Swap(source, dest);
			}
			if (nodeIndex >= _edges.GetCount())
				nodeIndex = NOTOK;
			AddEdge(source, dest, nodeIndex) iferr_return;
		}
		else // remove isolated points
		{
			for (auto it = Iterable::EraseIterator(_nodes); it; ++it)
			{
				if (it->GetEdgesCount() <= 0)
				{
					it.Erase();
				}
			}
		}

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Remove the edge and adjust the nodes<->edges mapping.
	/// @param[in] edge								The edge to be removed.
	/// @param[in] nodes							If True also node will be deleted if any other edge use it.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> DeleteEdge(EdgeType* edge, Bool nodes = false)
	{
		if (!edge)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		Int pos = _edges.GetIndex(*edge);

		if (pos == NOTOK)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		return DeleteEdge(pos, nodes);
	}

	//----------------------------------------------------------------------------------------
	/// Remove the edge and adjust the nodes<->edges mapping.
	/// @param[in] pos								The position in to edge list.
	/// @param[in] nodes							If True also nodes will be deleted if any other edge use it.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> DeleteEdge(Int pos, Bool nodes = false)
	{
		iferr_scope;

		if (pos >= GetEdgesCount())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		NodeType*		p1 = nullptr;
		NodeType*		p2 = nullptr;
		EdgeType*		currentEdge = &_edges[pos];
		if (!currentEdge)
		{
			DebugStop();
			return IllegalStateError(MAXON_SOURCE_LOCATION);
		}
		currentEdge->GetNodesPointer(p1, p2) iferr_return;

		p1->DeleteEdge(currentEdge) iferr_return;
		p2->DeleteEdge(currentEdge) iferr_return;

		_edges.Erase(pos) iferr_return;

		if (nodes)
		{
			Int nodePos = _nodes.GetIndex(*p1);
			if (p1->GetEdgesCount() == 0)
			{
				_nodes.Erase(nodePos) iferr_return;
			}
			nodePos = _nodes.GetIndex(*p2);
			if (p2->GetEdgesCount() == 0)
			{
				_nodes.Erase(nodePos) iferr_return;
			}
		}
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Weld disconnected nodes.
	/// @param[in] p1									First node, this node will be stay alive.
	/// @param[in] p2									Second node.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> WeldNodes(NodeType* p1, NodeType* p2)
	{
		iferr_scope;

		if (!p1 || !p2)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		EdgeType*		currentEdge = nullptr;
		EdgeType*		compareEdge = nullptr;
		NodeType*		updateNode = nullptr;
		NodeType*		currentNode = nullptr;

		// move all stoke attached to p2 to p1;
		Int		edgeCount = p2->GetEdgesCount();
		Bool	jump = false;
		Bool	isSecond = false;
		BaseArray<EdgeType*> toBeDeleted;
		for (Int32 i = 0; i < edgeCount; ++i)
		{
			jump = false;
			currentEdge = p2->GetEdge(i) iferr_return;
			updateNode = currentEdge->GetOtherHand(p2, &isSecond) iferr_return;
			for (Int32 a = 0; a < p1->GetEdgesCount(); ++a) // check for duplicated stroke
			{
				compareEdge = p1->GetEdge(a) iferr_return;
				currentNode = compareEdge->GetOtherHand(p1) iferr_return;
				if (updateNode == currentNode)
				{
					toBeDeleted.Append(currentEdge) iferr_return;
					jump = true;
					break;
				}
			}
			if (jump)
				continue;
			if (!isSecond)
			{
				currentEdge->UpdateNodes(p1, updateNode) iferr_return;
			}
			else
			{
				currentEdge->UpdateNodes(updateNode, p1) iferr_return;
			}
			p1->AddEdge(currentEdge) iferr_return;
		}

		for (EdgeType* e : toBeDeleted)
		{
			DeleteEdge(e) iferr_return;
		}

		// then we can delete the p2
		Int p2Pos = _nodes.GetIndex(*p2);
		_nodes.Erase(p2Pos) iferr_return;
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Shrink edge to a single node and refresh the graph.
	/// @param[in] edge								The edge to be removed.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> MeltEdge(EdgeType* edge)
	{
		if (!edge)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		Int pos = _edges.GetIndex(*edge);

		if (pos == NOTOK)
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		return MeltEdge(pos);
	}

	//----------------------------------------------------------------------------------------
	/// Shrink edge at pos to a single node and refresh the graph.
	/// @param[in] pos								The position in to edge list.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> MeltEdge(Int pos)
	{
		iferr_scope;

		if (pos >= GetEdgesCount())
			return IllegalArgumentError(MAXON_SOURCE_LOCATION);

		NodeType*		p1 = nullptr;
		NodeType*		p2 = nullptr;
		EdgeType*		currentEdge = &_edges[pos];
		if (!currentEdge)
			return IllegalStateError(MAXON_SOURCE_LOCATION);
		currentEdge->GetNodesPointer(p1, p2) iferr_return;
		p1->DeleteEdge(currentEdge) iferr_return;
		p2->DeleteEdge(currentEdge) iferr_return;
		_edges.Erase(pos) iferr_return;

		return WeldNodes(p1, p2);
	}

	//----------------------------------------------------------------------------------------
	/// Free memory and reset all values.
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_nodes.Reset();
		_edges.Reset();
	}


protected:
	GRAPH_TYPE						_type;			// the graph type
	PointerArray<NODE>		_nodes;			// list of main nodes in the graph
	PointerArray<EDGE>		_edges;			// list of main edges in the graph
};

} // namespace maxon

#endif // GRAPHBASE_H__
