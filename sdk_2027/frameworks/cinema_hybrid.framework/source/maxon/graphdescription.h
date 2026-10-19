/// @brief Contains the graph description related functions and constants.
//---------------------------------------------------------------------------------------------------------------------

#ifndef GRAPHDESCRIPTION_H__
#define GRAPHDESCRIPTION_H__

#include "enumflags.h"
#include "maxon/interfacebase.h"
#include "maxon/datadictionary.h"
#include "maxon/nodesgraph.h"

/// @brief Continues on returned errors in a loop.
#define iferr_continue PRIVATE_MAXON_iferr_continue()
#define PRIVATE_MAXON_iferr_continue() % tmperr_ies; if (MAXON_UNLIKELY(tmperr_ies.GetReferencedError() != nullptr)) continue;

/// @brief Breaks on returned errors in a loop.
#define iferr_break PRIVATE_MAXON_iferr_break()
#define PRIVATE_MAXON_iferr_break() % tmperr_ies; if (MAXON_UNLIKELY(tmperr_ies.GetReferencedError() != nullptr)) break;

namespace cinema
{
	class BaseList2D;
	class BaseDocument;
} // namespace cinema

namespace maxon
{

//---------------------------------------------------------------------------------------------------------------------
/// @brief Indicates that parsing of data failed.
//---------------------------------------------------------------------------------------------------------------------
class ParsingErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(ParsingErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.parsingerror");
};

//---------------------------------------------------------------------------------------------------------------------
/// @brief Indicates that a given key in a given key-value pair collection does not exist.
/// @note Use `IndexErrorInterface` to express indexing errors in non key-value pair collections.
//---------------------------------------------------------------------------------------------------------------------
class KeyErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(KeyErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.keyerror");
};

//---------------------------------------------------------------------------------------------------------------------
/// @brief Indicates that a given value in a given key-value pair collection is malformed.
/// @note Use `TypeErrorInterface` to express values being of wrong type, and `IndexErrorInterface` to express indexing errors.
//---------------------------------------------------------------------------------------------------------------------
class ValueErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(ValueErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.valueerror");
};

//---------------------------------------------------------------------------------------------------------------------
/// @brief Indicates that a given value is of wrong type.
//---------------------------------------------------------------------------------------------------------------------
class TypeErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(TypeErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.typeerror");
};

//---------------------------------------------------------------------------------------------------------------------
/// @brief Indicates that a given index is out of bounds for the given data.
//---------------------------------------------------------------------------------------------------------------------
class IndexErrorInterface : MAXON_INTERFACE_BASES(ErrorInterface)
{
	MAXON_INTERFACE(IndexErrorInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.indexerror");
};

namespace nodes
{

//---------------------------------------------------------------------------------------------------------------------
/// @brief Provides functions and constants to read and write node graphs from and into the graph description format.
/// @details A graph description is JSON-like format to describe complete or partial node graphs for arbitrary node
/// spaces. Graph descriptions can describe node types and their attributes over their labels in a natural language, 
/// absolute and lazy node paths, and queries to select entities in a graph by their values. Graph descriptions are 
/// primarily intended to be written and read from the Python API which binds to this class.
//---------------------------------------------------------------------------------------------------------------------
class GraphDescription
{
	MAXON_INTERFACE_NONVIRTUAL(GraphDescription, MAXON_REFERENCE_STATIC, "net.maxon.node.interface.graphdescription");

public:
	// ------------------------------------------------------------------------------------------------------------------
	/// @brief Expresses options when parsing graph descriptions.
	/// @note Currently unused.
	// ------------------------------------------------------------------------------------------------------------------
	enum class PARSE_FLAGS
	{
		NONE = (1 << 0),									///< Marks a description as having no special flags.
		VERBOSE_ATTRIBUTES = (1 << 1),		///< Marks a description as also encoding attributes which hold default values instead of omitting them.
		VERBOSE_REFERENCES = (1 << 2),		///< Marks a description as exclusively using identifiers instead of labels to reference nodes and attributes.
		ALWAYS_VALIDATE_PATHS = (1 << 3),	///< Marks a description as always validating absolute node paths with the underlying graph description cache.
		RAW_COLORS = (1 << 4)							///< Marks a description as using raw color values instead of their sRGB representation. This is only relevant for OCIO color managed documents.
	} MAXON_ENUM_FLAGS_CLASS(PARSE_FLAGS);

	// ------------------------------------------------------------------------------------------------------------------
	/// @brief Expresses options when querying a graph for nodes.
	// ------------------------------------------------------------------------------------------------------------------
	enum class QUERY_FLAGS
	{
		NONE = (1 << 0),																///< Marks a query as having no special flags.
		MATCH_FIRST = (1 << 1),													///< Marks a query to pick the first match when ambiguous. Dominant over `MATCH_ALL`. When no match flag is set, a query must be unambiguous.
		MATCH_ALL = (1 << 2),														///< Marks a query to pick all matches when ambiguous. Suppressed by `MATCH_FIRST`. When no match flag is set, a query must be unambiguous.
		MATCH_MAYBE = (1 << 4),													///< Marks a query to match lazily, instead of raising an error, a non-matching sub-graph will simply not be executed.
		MATCH_MAYBE_FIRST = (MATCH_FIRST | MATCH_MAYBE),///< Marks a query to lazily pick the first match when ambiguous. This is equal to `MATCH_FIRST | MATCH_MAYBE`.
		MATCH_MAYBE_ALL = (MATCH_ALL | MATCH_MAYBE),		///< Marks a query to lazily pick all matches when ambiguous. This is equal to `MATCH_ALL | MATCH_MAYBE`.
		SELECT_THIS = (1 << 3),													///< Marks the to be selected element in a query. When a query does not contain a selection marker, the out most element will be selected.
		RAW_URLS = (1 << 5),														///< Marks a query to compare stored raw URL values instead of their UI representation.
		RAW_COLORS = (1 << 6),													///< Marks a query to compare stored raw color values, instead of their sRGB representation. This is only relevant for OCIO color managed documents.
		DEBUG = (1 << 7),																///< Marks a query to print debug information about the query evaluation to the Python logger.
	} MAXON_ENUM_FLAGS_CLASS(QUERY_FLAGS);

	// ------------------------------------------------------------------------------------------------------------------

	static MAXON_METHOD String GetDescriptionKey();							///< Returns the key for a description field in a description. Alias for "$description".
	static MAXON_METHOD String GetFlagsKey();										///< Returns the key for a flags field in a description. Alias for "$flags".
	static MAXON_METHOD String GetIdKey();											///< Returns the key for a node ID field in a description. Alias for "$id".
	static MAXON_METHOD String GetLanguageKey();								///< Returns the key for a language ID field in a description. Alias for "$language".
	static MAXON_METHOD String GetQueryKey();										///< Returns the key for a query field in a description. Alias for "$query".
	static MAXON_METHOD String GetQueryModeKey();								///< Returns the key for a query mode field in a description. Alias for "$qmode".
	static MAXON_METHOD String GetSpaceKey();										///< Returns the key for a node space ID field in a description. Alias for "$space".
	static MAXON_METHOD String GetTypeKey();										///< Returns the key for a node type field in a description. Alias for "$type".
	static MAXON_METHOD String GetCommandsKey();								///< Returns the key for a node command field in a description. Alias for "$commands".
	static MAXON_METHOD String GetQueryCompositionKey();				///< Returns the key for a query composition field. Alias for "$qcomp".
	static MAXON_METHOD String GetQueryValueKey();							///< Returns the key for a comparison value field. Alias for "$qvalue".
	static MAXON_METHOD String GetQueryOpKey();									///< Returns the key for a comparison operator field. Alias for "$qop".
	static MAXON_METHOD String GetQueryMaxErrorKey();						///< Returns the key for a query tolerance field. Defaults to `1E-6` when not set. Alias for "$qmaxer".
	static MAXON_METHOD String GetQuerySelectPortsKey();				///< Returns the key for a query select ports field. Alias for "$qselports".
	static MAXON_METHOD String GetQueryFlagsKey();								///< Returns the key for query flags. Alias for "$queryflags".

	static MAXON_METHOD String GetInputGroupKey();								///< Returns the key for an input-group scope. Alias for "$inputgroup".
	static MAXON_METHOD String GetPortsKey();										///< Returns the key for input-group ports. Alias for "$ports".
	static MAXON_METHOD String GetEnumKey();											///< Returns the key for input-group enumerations. Alias for "$enum".
	static MAXON_METHOD String GetDefaultKey();										///< Returns the key for an input-group default value. Alias for "$default".
	static MAXON_METHOD String GetMinKey();												///< Returns the key for an input-group minimum value. Alias for "$min".
	static MAXON_METHOD String GetMaxKey();												///< Returns the key for an input-group maximum value. Alias for "$max".
	static MAXON_METHOD String GetStepKey();											///< Returns the key for an input-group step value. Alias for "$step".
	static MAXON_METHOD String GetChildrenKey();									///< Returns the key for group children. Alias for "$children".

	static MAXON_METHOD String GetFloatType();										///< Returns the input-group type string for float values. Returns "float".
	static MAXON_METHOD String GetIntType();											///< Returns the input-group type string for integer values. Returns "int".
	static MAXON_METHOD String GetBoolType();										///< Returns the input-group type string for boolean values. Returns "bool".
	static MAXON_METHOD String GetStringType();									///< Returns the input-group type string for string values. Returns "string".
	static MAXON_METHOD String GetUrlType();										///< Returns the input-group type string for URL values. Returns "url".
	static MAXON_METHOD String GetIdType();										///< Returns the input-group type string for ID values. Returns "id".
	static MAXON_METHOD String GetInternedIdType();								///< Returns the input-group type string for interned ID values. Returns "internedid".
	static MAXON_METHOD String GetVectorType();										///< Returns the input-group type string for vector values. Returns "vector".
	static MAXON_METHOD String GetColorType();										///< Returns the input-group type string for color values. Returns "color".
	static MAXON_METHOD String GetColorAType();										///< Returns the input-group type string for alpha color values. Returns "colora".

	static MAXON_METHOD String GetQueryOpEqualKey();						///< Returns the equality operator. Alias for "==".
	static MAXON_METHOD String GetQueryOpNotEqualKey();					///< Returns the inequality operator. Alias for "!=".
	static MAXON_METHOD String GetQueryOpLessKey();							///< Returns the less-than operator. Alias for "<".
	static MAXON_METHOD String GetQueryOpLessEqualKey();				///< Returns the less-than-or-equal operator. Alias for "<=".
	static MAXON_METHOD String GetQueryOpGreaterKey();					///< Returns the greater-than operator. Alias for ">".
	static MAXON_METHOD String GetQueryOpGreaterEqualKey();			///< Returns the greater-than-or-equal operator. Alias for ">=".
	static MAXON_METHOD String GetQueryOpAndKey();							///< Returns the logical-and operator. Alias for "and".
	static MAXON_METHOD String GetQueryOpOrKey();								///< Returns the logical-or operator. Alias for "or".
	static MAXON_METHOD String GetQueryOpRegexSearchKey();			///< Returns the regular expression search operator. Alias for "regex".
	static MAXON_METHOD String GetQueryOpRegexMatchKey();				///< Returns the regular expression match operator. Alias for "regex_match".

	static MAXON_METHOD String GetUnGroupCommandKey();					///< Returns the command key for ungrouping a node. Alias for "$cmd_ungroup".
	static MAXON_METHOD String GetRecursiveUnGroupCommandKey();	///< Returns the command key for recursively ungrouping a node. Alias for "$cmd_rec_ungroup".
	static MAXON_METHOD String GetRemoveNodeCommandKey();				///< Returns the command key for a removing a node. Alias for "$cmd_remove".
	static MAXON_METHOD String GetDefaultNodeCommandKey();			///< Returns the command key for setting a node to its defaults. Alias for "$cmd_default".
	static MAXON_METHOD String GetDisconnectCommandKey();				///< Returns the command key for removing all wires from a node. Alias for "$cmd_disconnect".
	static MAXON_METHOD String GetSetPortCountCommandKey();			///< Returns the command key for changing the number of variadic children of the variadic ports of a node. Alias for "$cmd_count_ports".
	static MAXON_METHOD String GetShowPortsCommandKey();				///< Returns the command key for showing the ports of a node. Alias for "$cmd_show_ports".
	static MAXON_METHOD String GetHidePortsCommandKey();				///< Returns the command key for hiding the ports of a node. Alias for "$cmd_hide_ports".
	static MAXON_METHOD String GetStartNodeCommandKey();				///< Returns the command key for making a node the start node. Alias for "$cmd_set_start".
	static MAXON_METHOD String GetSoloNodeCommandKey();					///< Returns the command key for making a node the solo node. Alias for "$cmd_set_solo".
	static MAXON_METHOD String GetClearStartNodeCommandKey();		///< Returns the command key for clearing the start node. Alias for "$cmd_clear_start".
	static MAXON_METHOD String GetClearSoloNodeCommandKey();		///< Returns the command key for clearing the solo node. Alias for "$cmd_clear_solo".

	//-------------------------------------------------------------------------------------------------------------------
	/// @brief Not yet implemented.
	//-------------------------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDictionary> GenerateDescription(NodesGraphModelRef& graph, DataDictionary description);

	//-------------------------------------------------------------------------------------------------------------------
	/// @brief Not yet implemented.
	//-------------------------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDictionary> TranslateDescription(DataDictionary description);

	//-------------------------------------------------------------------------------------------------------------------
	/// @brief Evaluates the given query for the given graph and returns the matching nodes.
	//-------------------------------------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<GraphNode>> EvaluateQuery(nodes::NodesGraphModelRef& graph, DataDictionary query);

	//----------------------------------------------------------------------------------------
	/// @brief Applies the given graph #description to the given nodes #graph.
	/// @param[in] graph							The nodes graph to apply the #description to.
	/// @param[in] description				The graph description to apply to #graph.
	/// @return												All nodes in the graph after the description has been read as <String, GraphNode> pairs where the string.
	/// is the ID of the node. Primarily intended for the Python fronted.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDictionary> ApplyDescription(NodesGraphModelRef& graph, DataDictionary description);

	//-------------------------------------------------------------------------------------------------------------------
	/// @note Deprecated in favour of `GetGraph`.
	//-------------------------------------------------------------------------------------------------------------------
	[[deprecated("Use GetGraph instead")]] static MAXON_METHOD Result<nodes::NodesGraphModelRef> CreateGraph(cinema::BaseList2D* element, Id& nodeSpaceId, 
		const Bool createEmpty, const String& name);

	//----------------------------------------------------------------------------------------
	/// @brief Returns the nodes graph for the given scene #element and #nodeSpaceId.
	/// @details #element can be a `BaseDocument` (for the document wide scene nodes graph), a `BaseObject` (for capsules),
	/// or a material (for material graphs), or nullptr (to create a material in the active document). When the passed 
	/// element does not yet have a graph in the requested node space, it will be created.
	/// @param[in] element						The scene element to get the graph for. Can be `nullptr` to create a material in the active document.
	/// @param[in] nodeSpaceId				The node space to retrieve the graph for. When the empty ID is passed, it will default to the 
	/// active node space for materials and the neutron node space for everything else.
	/// @param[in] createEmpty				When #true, new graphs will be created as an empty graph, when #false the default graph will 
	/// be created.
	/// @param[in] name								The name to give the material which is created when #element is the `nullptr`.
	/// @return												The retrieved graph.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<nodes::NodesGraphModelRef> GetGraph(cinema::BaseList2D* element, Id& nodeSpaceId, 
		const Bool createEmpty, const String& name);

	//----------------------------------------------------------------------------------------
	/// @brief Returns all material graphs in the given scene #doc which are in the given #nodeSpaceId.
	/// @param[in] doc								The document to get the material graphs from.
	/// @param[in] nodeSpaceId				The node space to retrieve the graphs for. Cannot be the empty ID.
	/// @return												All material graphs in the given scene #doc which are of the given #nodeSpaceId.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<BaseArray<nodes::NodesGraphModelRef>> GetMaterialGraphs(const cinema::BaseDocument* const doc, const Id& nodeSpaceId);
};

} // namespace nodes

#include "graphdescription1.hxx"
#include "graphdescription2.hxx"
} // namespace maxon

#endif // GRAPHDESCRIPTION_H__
