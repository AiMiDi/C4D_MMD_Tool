#ifndef NODEPATH_H__
#define NODEPATH_H__

#include "maxon/bitmanipulation.h"
#include "maxon/graph_basics.h"

namespace maxon
{

# ifndef NODE_PATH_IMPL_GUARD1

//----------------------------------------------------------------------------------------
/// NODE_KIND allows to determine whether a general node (g-node for short) is a true node, a port or a port list.
/// Because nodes, ports and port lists can be represented in a single hierarchy, classes
/// such as GraphNode and GNode make use of this and need NODE_KIND to determine the actual kind
/// of a g-node.
/// - NODE stands for true nodes. They may contain nested nodes and two port lists, one for the
///   input ports and one for the output ports.
/// - INPUTS and OUTPUTS stand for port lists. They occur in the hierarchy as direct children
///   of true nodes. Each true node may have at most one input list and one output list.
/// - INPORT and OUTPORT stand for ports. When a port is actually a port bundle,
///   it may contain nested ports. A port is a child of either a port bundle or a port list.
//----------------------------------------------------------------------------------------
enum class NODE_KIND
{
	NONE = 0,															///< Special value used e.g. for null references.
	NODE = 1,															///< Indicates that the g-node is a true node.
	INPUTS = 2,														///< Indicates that the g-node is an input port list. An input port list has a true node as parent and input ports as children.
	OUTPUTS = 4,													///< Indicates that the g-node is an output port list. An output port list has a true node as parent and output ports as children.
	INPORT = 8,														///< Indicates that the g-node is an input port. An input port has an input port list or an input port as parent and input ports as children.
	OUTPORT = 16,													///< Indicates that the g-node is an output port. An output port has a output port list or a output port as parent and output ports as children.
	IN_MASK = INPUTS | INPORT,						///< Mask to check a NODE_KIND if it stands for an input port or an input port list.
	OUT_MASK = OUTPUTS | OUTPORT,					///< Mask to check a NODE_KIND if it stands for an output port or an output port list.
	PORTLIST_MASK = INPUTS | OUTPUTS,			///< Mask to check a NODE_KIND if it stands for a port list.
	PORT_MASK = INPORT | OUTPORT,					///< Mask to check a NODE_KIND if it stands for a port.
	ALL_MASK = 31													///< Mask which matches all node kinds.
} MAXON_ENUM_FLAGS(NODE_KIND);


//----------------------------------------------------------------------------------------
/// Returns the direction of a NODE_KIND. The given #kind has to stand for ports or port lists,
/// and the returned value is PORT_DIR::INPUT for input ports and input ports lists, or
/// PORT_DIR::OUTPUT for output ports and output port lists.
/// @param[in] kind								The kind of a port or port list.
/// @return												The corresponding direction.
//----------------------------------------------------------------------------------------
inline PORT_DIR GetPortDirection(NODE_KIND kind)
{
	return (kind & NODE_KIND::OUT_MASK) ? PORT_DIR::OUTPUT : PORT_DIR::INPUT;
}


class NodePath;

//----------------------------------------------------------------------------------------
/// A PathBlock is a Block of identifiers to be used as path into a graph, see NodePath.
//----------------------------------------------------------------------------------------
using PathBlock = Block<const InternedId>;

//----------------------------------------------------------------------------------------
/// A NodePath identifies a graph node (a true node, port or port list) within a node graph.
/// It consists of a list of identifiers (one for each hierarchy level) just like the path
/// of a file in a file system. In the textual notation of a path we use `/` as separator character
/// (except around `<` or `>`, see below).
///
/// The root node has an empty path, and port lists use the special identifiers `<` (input port list)
/// and `>` (output port list). For example in the graph
/// @graph
/// +------------------------------------------------------------+
/// |                                                            |
/// o object      +-x-------------------------------+            |
///  o geometry   |            +-n----------+       |            |
///  o bounds --> o bounds --> o in     out o --> c o --> center o
/// |             |            +------------+       |            |
/// |             +---------------------------------+            |
/// +------------------------------------------------------------+
/// @endgraph
/// there are the following paths:
/// - The empty path identifies the root node.
/// - `<` is the path of the input port list of the root node (containing the object port), `>` of the output port list (containing the center port).
/// - `<object`, `<object/geometry`, `<object/bounds` are the paths of the input ports of the root node.
/// - `>center` is the path of the output port of the root node.
/// - `x` is the path of the child node x.
/// - x has the input port `x<bounds` and the output port `x>c`.
/// - x has the inner node `x/n` with ports `x/n<in` and `x/n>out`.
///
/// A path cannot contain more than one of the port list identifiers `<` or `>`. All methods which initialize
/// or modify a path return an error if the result was such an invalid path.
///
/// To make the string representation shorter and more readable, the separator character `/`
/// is only used between regular identifiers, but not around the port list identifiers `<` or `>`.
/// Therefore we write e.g. `x/n>out` instead of `x/n/>/out`.
///
/// @see @$ref usernodes_nodes
/// @MAXON_ANNOTATION{implementationClassMacro=NODE_PATH_IMPL}
//----------------------------------------------------------------------------------------
class NodePathInterface
{
	MAXON_INTERFACE_NONVIRTUAL(NodePathInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.graph.interface.nodepath");
public:
	//----------------------------------------------------------------------------------------
	/// Constructs a new node path from the given #path.
	/// @param[in] path								The path to use.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodePathInterface*> Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const PathBlock& path);

	//----------------------------------------------------------------------------------------
	/// Constructs a new node path from the given #path.
	/// @param[in] path								The path to use.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodePathInterface*> Alloc(MAXON_SOURCE_LOCATION_DECLARATION, BaseArray<InternedId>&& path);

	//----------------------------------------------------------------------------------------
	/// Parses a node path given as a character block into a NodePath object. The given #path has to match the
	/// format returned by ToCString, otherwise an error is returned.
	/// @param[in] path								The path to parse.
	/// @return												The parsed NodePath.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodePath> FromCString(const Block<const Char>& path);

	//----------------------------------------------------------------------------------------
	/// Converts a node path into its textual notation. The identifiers of the path are concatenated
	/// with the separator character `/` between identifiers as in `node/child` (with a special handling
	/// of the port list identifiers `<` or `>`, see NodePath). Within an identifier the special characters
	/// `/` and `\\` are escaped by a `\\`, so for example if the path is {"a/b", "\u"}, its textual notation
	/// is `a\\/b/\\\\u`.
	/// @param[in] path								The path to parse.
	/// @return												The textual notation of the path as a CString.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<CString> ToCString(const PathBlock& path);

	//----------------------------------------------------------------------------------------
	/// Converts this node path into its textual notation. The identifiers of the path are concatenated
	/// with the separator character `/` between identifiers as in `node/child` (with a special handling
	/// of the port list identifiers `<` or `>`, see NodePath). Within an identifier the special characters
	/// `/`, `\\`, `<`, `>` are escaped by a `\\`, so for example if the path is {"a/b", "\u"}, its textual notation
	/// is `a\\/b/\\\\u`.
	/// @return												The textual notation of this path as a CString.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<CString> ToCString() const
	{
		return ToCString(ToBlock());
	}

	//----------------------------------------------------------------------------------------
	/// Converts this node path into its textual notation and appends this to the given CString.
	/// @see ToCString
	/// @param[in,out] str						The CString to append to.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> AppendToCString(CString& str) const;

	//----------------------------------------------------------------------------------------
	/// Converts a node path given as an initializer list into a NodePath object.
	/// @param[in] path								The path to use.
	/// @return												The new NodePath.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodePath> FromPathBlock(const PathBlock& path);

	//----------------------------------------------------------------------------------------
	/// Converts a node path given as an initializer list into a NodePath object.
	/// NodePathInterface::INPUTS will automatically be prepended, making this a root node input path.
	/// @param[in] path								The path to use.
	/// @return												The new NodePath.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodePath> FromInPathBlock(const PathBlock& path);

	//----------------------------------------------------------------------------------------
	/// Converts a node path given as an initializer list into a NodePath object.
	/// NodePathInterface::OUTPUTS will automatically be prepended, making this a root node output path.
	/// @param[in] path								The path to use.
	/// @return												The new NodePath.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<NodePath> FromOutPathBlock(const PathBlock& path);

	//----------------------------------------------------------------------------------------
	/// Parses a node path given as a character block into a BaseArray. The given #path has to match the
	/// format returned by ToCString, otherwise an error is returned.
	/// @param[in] path								The path to parse.
	/// @param[in] out								Parsed path elements are appended to this array.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> ParsePath(const Block<const Char>& path, BaseArray<InternedId>& out);

	//----------------------------------------------------------------------------------------
	/// Returns the internally stored path as a Block.
	/// @return												This path as a Block.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD PathBlock ToBlock() const;

	MAXON_METHOD PathBlock Slice(Int start) const;

	MAXON_METHOD PathBlock Slice(Int start, Int end) const;

	/// @copydoc ToBlock
	MAXON_FUNCTION operator PathBlock() const
	{
		return ToBlock();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the last element of this path.
	/// @return												Last element of this path, or an empty identifier if the path is empty.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const InternedId& GetLastId() const;

	//----------------------------------------------------------------------------------------
	/// Returns the length of this path. The path elements have indices from 0 up to length-1.
	/// @return												Number of elements of this path.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetCount() const;

	//----------------------------------------------------------------------------------------
	/// Checks if this path is an empty path. The root node of a node system is identified by an empty path.
	/// @return												True if this is an empty path (of length 0), false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool IsEmpty() const { return GetCount() == 0; }

	//----------------------------------------------------------------------------------------
	/// Checks if this path contains anything.
	/// @return												True if this is not an empty path (of length 0).
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool IsPopulated() const { return GetCount() != 0; }

	//----------------------------------------------------------------------------------------
	/// Returns the path element at the given #index. The index is zero-based, i.e., from 0
	/// up to length-1.
	/// @param[in] index							The index of the element to return.
	/// 															It has to be within the bounds, otherwise the behaviour is undefined.
	/// @return												The path element at #index.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const InternedId& operator [](Int index) const;

	//----------------------------------------------------------------------------------------
	/// Appends a single identifier at the end of this path.
	/// @param[in] node								The identifier to append.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodePath> operator +(const InternedId& node) const;

	//----------------------------------------------------------------------------------------
	/// Appends a node subpath at the end of this path.
	/// @param[in] suffix							The subpath to append.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodePath> operator +(const PathBlock& suffix) const;

	//----------------------------------------------------------------------------------------
	/// Appends a node subpath at the end of this path.
	/// @param[in] suffix							The subpath to append.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodePath> operator +(const NodePath& suffix) const;

	//----------------------------------------------------------------------------------------
	/// Prepends a node prefix at the beginning of this path.
	/// @param[in] prefix							The prefix to insert.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodePath> Prepend(const PathBlock& prefix) const;

	//----------------------------------------------------------------------------------------
	/// Returns a part of this node path as a new NodePath.
	/// @param[in] start							Position where the new partial path will start. This has to be within the bounds, otherwise an error is returned.
	/// @param[in] count							Number of identifiers for the partial path. If it is larger than the number of available identifiers an error is returned.
	/// @return												The partial path.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodePath> GetPart(StringPosition start, StringCount count) const;

	//----------------------------------------------------------------------------------------
	/// Returns the port part of this path as a new NodePath. The port parts starts at the input/output list identifier.
	/// @return												The port part of this path.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodePath> GetPortPart() const;

	//----------------------------------------------------------------------------------------
	/// Returns the path of the parent of this path.
	/// @return												The parent of this path, or an empty path if this path is already the root path.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Result<NodePath> GetParent() const;

	//----------------------------------------------------------------------------------------
	/// Replaces the identifier at the given index.
	/// @param[in] index							The index within this path.
	/// @param[in] id									The new identifier to use.
	/// @return												A new path with the replaced identifier.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodePath> Replace(Int index, const InternedId& id) const;

	//----------------------------------------------------------------------------------------
	/// Replaces the identifier at the given index using the translation.
	/// This method is useful in conjunction with the translations which are returned by GraphModelInterface::Merge.
	/// @param[in] index							The index within this path.
	/// @param[in] translation				A mapping from old identifiers to new identifiers.
	/// @return												A path with the replaced identifier (or this path if no
	///																replacement was found in translation),
	///																and a Bool which is true if and only if a replacement has occurred.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Tuple<NodePath, Bool>> Translate(Int index, const HashMap<InternedId, InternedId>& translation) const;

	//----------------------------------------------------------------------------------------
	/// Checks whether this path starts with #other.
	/// @param[in] other							Another path.
	/// @return												True if this path starts with the given path.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool StartsWith(const PathBlock& other) const;

	//----------------------------------------------------------------------------------------
	/// Checks whether this path ends with #other.
	/// @param[in] other							Another path.
	/// @return												True if this path ends with the given path.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool EndsWith(const PathBlock& other) const;

	//----------------------------------------------------------------------------------------
	/// Returns the node kind of the graph node which is identified by this path:
	/// - A path without path list identifiers `<` or `>` is a true node (NODE_KIND::NODE), for example `node/child`.
	/// - A path which ends with `<` or `>` is a port list (NODE_KIND::INPUTS or NODE_KIND::OUTPUTS), for example `node/child/<`.
	/// - A path which contains `<` or `>`, but does not end with such an identifier is a port
	///   (NODE_KIND::INPORT or NODE_KIND::OUTPORT), for example `node/child/</in`.
	/// @return												The node kind of the graph node identified by this path.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD NODE_KIND GetKind() const;

	/// @MAXON_ANNOTATION{refclass=false}
	MAXON_METHOD NODE_KIND PrivateGetKind(Bool existing) const;

	//----------------------------------------------------------------------------------------
	/// Returns the hierarchy depth of the true node which is identified by this path. If this path
	/// identifies a true node directly, the depth is the number of path elements. Otherwise, if this
	/// path identifies a port or port list, the depth is the depth of the innermost enclosing true node,
	/// i.e., the number of path elements up to but excluding the port list identifier.
	/// For example all of the paths `node/child`, `node/child/<` and `node/child/</in` have a node depth of 2
	/// because for all those paths `node/child` is the innermost true node.
	/// @return												The depth of the true node given by this path.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetNodeDepth() const;

	//----------------------------------------------------------------------------------------
	/// Returns the path to the @ref Port "top-level port" of this path. The top-level port of a port
	/// is the outermost enclosing port, i.e., an enclosing port which is a direct child of a port list,
	/// or the port itself if this is already a direct child of a port list. For example in the node
	/// @graph
	/// +---------+
	/// o x       |
	///  o a      |
	///   o b     |
	///  o c      |
	/// +---------+
	/// @endgraph
	/// all of the ports x, a, b, c have x as their top-level port.
	/// @return												The path to the top-level port of the port given by this path.
	/// 															If this path doesn't represent a port, an error is returned.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodePath> GetTopLevelPort() const;

	//----------------------------------------------------------------------------------------
	/// GetNode returns only the path of the node without ports.
	/// @return												NodePath with the node path on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<NodePath> GetNode() const;

	//----------------------------------------------------------------------------------------
	/// GetPortPath returns only the relative port path without the node path.
	/// @return												PathBlock with the ports on success.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION PathBlock GetPortPath() const
	{
		return Slice(GetNodeDepth() + 1);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if this path identifies a @ref Port "top-level port". A top-level port is a port
	/// which is not nested within another port, but a direct child of the input or output port list of a node.
	/// @see GetTopLevelPort
	/// @return												True if this path stands for a top-level port, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsTopLevelPort() const;

	//----------------------------------------------------------------------------------------
	/// Checks if this path identifies a port of the root node of a node system.
	/// This includes not only top-level ports, but also nested ports.
	/// @return												True if this path stands for a port of the root node, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsPortOfRoot() const;

	/// @copydoc DefaultDoc::ToString
	MAXON_METHOD String ToString(const FormatStatement* fs = nullptr) const;

	/// @copydoc DefaultDoc::operator==
	MAXON_METHOD Bool IsEqual(const NodePathInterface* other) const;

	//----------------------------------------------------------------------------------------
	/// Compares this node path with the other one. This uses the same comparison as e.g. Block<InternedId>,
	/// namely the lexicographic order. It compares path elements of both paths until it finds the first difference (or the end of a path
	/// is reached), and then it returns the result of the comparison of the first difference. If the end of
	/// one path has been reached, the shorter path is less than the longer path.
	/// @param[in] other							Another path.
	/// @return												Result of the comparison.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD COMPARERESULT Compare(const NodePathInterface* other) const;

	/// @copydoc DefaultDoc::GetHashCode
	MAXON_METHOD HashInt GetHashCode() const;

	/// @copydoc DefaultDoc::GetHashValue
	MAXON_METHOD HashValue GetHashValue() const;

	//----------------------------------------------------------------------------------------
	/// Returns a hash value for the node path which has been pre-computed on construction of the path.
	/// The hash value is not stable across different runs of the application as it is based on pointers.
	/// @return												A hash value for the node path.
	/// @see FastNodePathHash
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const HashValue& GetFastHashValue() const;

	//----------------------------------------------------------------------------------------
	/// Returns a hash code for the node path which has been pre-computed on construction of the path.
	/// The hash code is not stable across different runs of the application as it is based on pointers.
	/// @return												A hash code for the node path.
	/// @see FastNodePathHash
	//----------------------------------------------------------------------------------------
	MAXON_METHOD HashInt GetFastHashCode() const;

	//----------------------------------------------------------------------------------------
	/// Returns a hash code for the path block which is compatible with GetFastHashCode.
	/// @param[in] block							A node path.
	/// @return												The GetFastHashCode-compatible hash code of block.
	/// @see FastNodePathHash
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD HashInt GetFastHashCodeOfPathBlock(const PathBlock& block);

	//----------------------------------------------------------------------------------------
	/// Returns a hash value for the path block which is compatible with GetFastHashCode.
	/// @param[in] block							A node path.
	/// @return												The GetFastHashCode-compatible hash value of block.
	/// @see FastNodePathHash
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD HashValue GetFastHashValueOfPathBlock(const PathBlock& block);

	//----------------------------------------------------------------------------------------
	/// Checks if this node path is equal to the concatenation @c{prefix + suffix}.
	/// @param[in] prefix							The first path block for the concatenation.
	/// @param[in] suffix							The second path block for the concatenation.
	/// @param[in] ignorePrefixWhenEmpty	If true, a special mode is used when this node path is empty:
	/// 															prefix is ignored in that case, so it's tested if suffix is empty as well.
	/// @return												True if this node path equals @c{prefix + suffix}, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsEqual(const PathBlock& prefix, const PathBlock& suffix, Bool ignorePrefixWhenEmpty) const;

	//----------------------------------------------------------------------------------------
	/// Compares this node path with the other one. This uses lexicographic order, see Compare.
	/// @param[in] other							Another path given as a PathBlock.
	/// @return												True if this node path is less than other, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool LessThan(const PathBlock& other) const;

	//----------------------------------------------------------------------------------------
	/// Compares this node path with the other one. This uses lexicographic order, see Compare.
	/// @param[in] other							Another path given as a PathBlock.
	/// @return												True if this node path is less than or equal to other, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool LessThanOrEqual(const PathBlock& other) const;

	/// Iterator to iterate over path elements.
	using ConstIterator = BaseIterator<const PathBlock, false>;

	/// @copydoc ConstIterator
	using Iterator = ConstIterator;

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first identifier of this path.
	/// @return												Iterator pointing to first identifier.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION ConstIterator Begin() const
	{
		return ToBlock().Begin();
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing behind the last identifier of this path.
	/// @return												Iterator pointing behind last identifier.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION ConstIterator End() const
	{
		return ToBlock().End();
	}

	/// @private
	static MAXON_METHOD Result<void> DescribeIO(const DataSerializeInterface& stream);

	//----------------------------------------------------------------------------------------
	/// Checks if the identifier i stands for the input or output port list of a node,
	/// so if it is either '<' or '>'.
	/// @param[in] i									An identifier for a general node.
	/// @return												True if the identifier stands for the input or output port list.
	//----------------------------------------------------------------------------------------
	static Bool IsInputsOrOutputs(const InternedId& i)
	{
		return (i == INPUTS) || (i == OUTPUTS);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the port part of this path in a single identifier. I.e. the resulting identifier could contain
	/// numerous ids with separators if the port is nested. For example if the full path is
	/// node>port/nested, then the returned identifier is "port/nested". Special characters are
	/// escaped, see NodePathInterface::ToCString.
	/// @return												The relative path condensed in an identifier.
	//----------------------------------------------------------------------------------------
	// #LEGACYCOMPATIBILITY: (Ole) reorder methods
	MAXON_METHOD Result<InternedId> GetPortPartAsId() const;

	//----------------------------------------------------------------------------------------
	/// Returns the port part of #path in a single identifier. I.e. the resulting identifier could contain
	/// numerous ids with separators if the port is nested. For example if the full path is
	/// node>port/nested, then the returned identifier is "port/nested". Special characters are
	/// escaped, see NodePathInterface::ToCString.
	/// @return												The relative path condensed in an identifier.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<InternedId> GetPortPartAsId(const PathBlock& path);

	static InternedId INPUTS;			///< The identifier '<', this is used for the input port list of a node.
	static InternedId OUTPUTS;		///< The identifier '>', this is used for the output port list of a node.
	static InternedId TEMPLATE;		///< The identifier '#', this is used for the template port of a variadic port.
	static constexpr Char SEPARATOR = '/';	///< '/' This is used as a separator for each node depth in a NodePath.
};

#include "nodepath1.hxx"

# endif

# ifndef NODE_PATH_IMPL_GUARD2

#include "nodepath2.hxx"


inline Bool operator ==(const PathBlock& a, const NodePathInterface* b)
{
	return b ? a == b->ToBlock() : a.IsEmpty();
}

inline Bool operator !=(const PathBlock& a, const NodePathInterface* b)
{
	return !operator ==(a, b);
}


inline Bool operator ==(const NodePathInterface* b, const PathBlock& a)
{
	return operator ==(a, b);
}

inline Bool operator !=(const NodePathInterface* b, const PathBlock& a)
{
	return !operator ==(a, b);
}


inline Bool operator >=(const PathBlock& a, const NodePathInterface* b)
{
	return !b || b->LessThanOrEqual(a);
}

inline Bool operator <(const PathBlock& a, const NodePathInterface* b)
{
	return !operator >=(a, b);
}


inline Bool operator >(const PathBlock& a, const NodePathInterface* b)
{
	return b ? b->LessThan(a) : a.IsPopulated();
}

inline Bool operator <=(const PathBlock& a, const NodePathInterface* b)
{
	return !operator >(a, b);
}


inline Result<NodePath> operator +(const PathBlock& a, const NodePath& b)
{
	return b.Prepend(a);
}


//----------------------------------------------------------------------------------------
/// This class can be used instead of DefaultCompare for hash maps of NodePath keys when you want to
/// make use of the precomputed GetFastHashValue of the NodePath.
//----------------------------------------------------------------------------------------
class FastNodePathHash : public DefaultCompare
{
public:
	static MAXON_ATTRIBUTE_FORCE_INLINE HashInt GetHashCode(const NodePath& path)
	{
		return path.GetFastHashCode();
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE HashInt GetHashCode(const PathBlock& block)
	{
		return NodePathInterface::GetFastHashCodeOfPathBlock(block);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE HashInt GetHashCode(const BaseArray<InternedId>& block)
	{
		return NodePathInterface::GetFastHashCodeOfPathBlock(block);
	}

	template <typename K> static MAXON_ATTRIBUTE_FORCE_INLINE HashInt GetHashCode(const K& key)
	{
		return DefaultCompare::GetHashCode(key);
	}
};

# endif

} // namespace maxon

#endif // NODEPATH_H__
