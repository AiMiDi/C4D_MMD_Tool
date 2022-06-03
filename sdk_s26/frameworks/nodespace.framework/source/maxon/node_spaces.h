#ifndef NODE_SPACES_H__
#define NODE_SPACES_H__

#include "maxon/nodematerialexchange.h"
#include "maxon/datatype.h"

namespace maxon
{

class NimbusRef;

namespace nodes
{

//----------------------------------------------------------------------------------------
/// The following attributes should be passed to the NodeSpaceInterface::Init() function 
/// and be available for query via NodeSpaceInterface::GetData() .
//----------------------------------------------------------------------------------------
namespace NODESPACE
{
	//----------------------------------------------------------------------------------------
	/// Defines the identifier for all space-related data, such as node graph storage within C4D files.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Id, SPACEID, "net.maxon.nodes.nodespace.spaceid");

	//----------------------------------------------------------------------------------------
	/// Defines the GUI-visible string for the space-related components, such as
	/// node space switch and the Basic tab of node materials.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(String, SPACENAME, "net.maxon.nodes.nodespace.spacename");

	//----------------------------------------------------------------------------------------
	/// Defines the list of renderers that support the node space.
	/// Multiple renderers may be supported. This is the case for the MaterialNodeSpaces::Standard space
	/// which is supported by Standard renderer, Physical Renderer and Hardware Renderer.
	///
	/// However it is invalid to have multiple spaces that indicate support for one particular renderer.
	/// In such a case, the "Current (Renderer)" binding is ambiguous and made with no well-defined
	/// priority.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Array<Int>, RENDERERS, "net.maxon.nodes.nodespace.renderers");


	//----------------------------------------------------------------------------------------
	/// An enum to represent the different node space kinds (such as materials or scene nodes).
	//----------------------------------------------------------------------------------------
	enum class KIND
	{
		MATERIAL = 0,		///< The node space is used for materials.
		SCENE = 1				///< The node space is used for scene nodes.
	} MAXON_ENUM_LIST(KIND);

	//----------------------------------------------------------------------------------------
	/// Defines the node space kind of this node space.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(KIND, SPACEKIND, "net.maxon.nodes.nodespace.kind");

	//----------------------------------------------------------------------------------------
	/// This callback is executed for the active space if a node material is created, and
	/// for the user-selected add space command.
	///
	/// The provided function has exclusive write access and can instantiate nodes the following:
	/// @code
	/// iferr_scope;
	/// 
	/// maxon::nodes::NodeTemplate endNodeSystem = maxon::nodes::NodesLib::LoadTemplate(maxon::AssetInterface::GetBuiltinRepository(), maxonexample::NODE::ENDNODE::GetId()) iferr_return;
	/// maxon::GraphNode endGraphNode = graph.AddChild(maxon::Id("end node instance"), endNodeSystem) iferr_return;
	/// 
	/// return maxon::OK;
	/// @endcode
	///
	/// @param[in,out] graph				The empty node graph for filling with a default setup.
	/// @return											OK on success.
	///
	/// Future consideration: we may extend the signature of this function by providing read-only access to other
	/// node graphs that are already present in the particular material. This may fulfill the use case
	/// for migrating a node material from one space to another. The implementer would then be able to
	/// implement a (complex and lossy) conversion from another source node graph (from another space)
	/// to the target node space.
	//----------------------------------------------------------------------------------------
	using CreateMaterialGraphFunc = Delegate<Result<void>(const NodesGraphModelRef& graph)>;
	MAXON_ATTRIBUTE(CreateMaterialGraphFunc, CREATEMATERIALGRAPHFUNC, "net.maxon.nodes.nodespace.creatematerialgraphfunc");

	//----------------------------------------------------------------------------------------
	/// This callback is executed for the active space if a preview for the current node material is requested.
	/// The origin of the preview may lie in GUI components such as the Attribute Manager, Node Editor, or Material Manager.
	///
	/// It is mandatory to provide a valid maxon::nodes::PREVIEWIMAGEREQUEST::PROVIDER class.
	/// @param[in,out] request			The container to be filled that is passed into PreviewImageProviderInterface::Initialize() function later.
	/// @return											OK on success.
	//----------------------------------------------------------------------------------------
	using ConfigurePreviewImageRequestFunc = Delegate<Result<void>(DataDictionaryObjectRef request)>;
	MAXON_ATTRIBUTE(ConfigurePreviewImageRequestFunc, CONFIGUREPREVIEWIMAGEREQUESTFUNC, "net.maxon.nodes.nodespace.configurepreviewimagerequestfunc");

	//----------------------------------------------------------------------------------------
	/// The set of asset identifiers for end nodes.
	/// An end node acts as an entry point to the node graph within the Attribute Manager, if no specific
	/// start node has been specified by the user.
	/// Multiple identifiers should be defined in ascending priority order. A node instance of the first Id type is 
	/// preferred for ambiguous cases.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Array<Id>, MATERIALENDNODEIDS, "net.maxon.nodes.nodespace.materialendnodeids");

	//----------------------------------------------------------------------------------------
	/// The set of Ids that require a 3d preview along with the user choice over the 3d scene.
	/// It can be expected that a valid value for maxon::nodes::PREVIEW::SCENETYPE
	/// is then provided to PreviewImageProviderInterface::Initialize().
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Array<Id>, MATERIALPREVIEWIDS, "net.maxon.nodes.nodespace.materialpreviewids");

	//----------------------------------------------------------------------------------------
	/// The type of node system this space supports. The node system defines which types of
	/// nodes are available for the user in the GUI for the particular node space. Node instances 
	/// are bound to one node system class.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(NodeSystemClass, NODESYSTEMCLASS, "net.maxon.nodes.nodespace.nodesystemclass");

	//----------------------------------------------------------------------------------------
	/// The class to use for the NimbusRef of this node space.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Class<NimbusRef>, NIMBUSCLASS, "net.maxon.nodes.nodespace.nimbusclass");

	//----------------------------------------------------------------------------------------
	/// Defines the collection of compatible material types.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Array<Id>, MATERIALEXCHANGEBUNDLEIDS, "net.maxon.nodes.nodespace.materialexchangebundleids");

	//----------------------------------------------------------------------------------------
	/// Defines which component implementing the maxon::nodes::MaterialExchangeInterface is queried
	/// for the representation of the node material in the viewport and for exchange purposes like material export.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Class<MaterialExchangeRef>, MATERIALEXCHANGECLASS, "net.maxon.nodes.nodespace.materialexchangeclass");

	//----------------------------------------------------------------------------------------
	/// This callback is executed on import of material data, potentially from a file format such as FBX or by migrating
	/// data from one space to another.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Class<NodeMaterialImportRef>, NODEMATERIALIMPORTCLASS, "net.maxon.nodes.nodespace.nodematerialimportclass");

	//----------------------------------------------------------------------------------------
	/// This callback is executed on export of material data, potentially from a file format such as FBX or by migrating
	/// data from one space to another. If not provided, the export will fallback to the extraction of the material definition
	/// provided for viewport display.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Class<NodeMaterialExportRef>, NODEMATERIALEXPORTCLASS, "net.maxon.nodes.nodespace.nodematerialexportclass");

	//----------------------------------------------------------------------------------------
	/// Defines the type of node that acts as an image / texture node. An instance of this type is created if 
	/// users drag & drop an image onto the ports connectors or the Node Editor canvas.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Id, IMAGENODEASSETID, "net.maxon.nodes.nodespace.imagenodeassetid");

	using ImageNodePortTuple = HomogenousTupleType<4, NodePath>;

	//----------------------------------------------------------------------------------------
	/// Makes a set of ports on the image / texture node type known to Cinema4D's business logic.
	/// For each port you have to specify the relative node path within its port list,
	/// so for the simple case of a non-nested path you have to specify a path of just one identifier.
	///
	/// The four ports must have the following signature:
	///
	/// Index in Tuple |    Port Type |    Data Type | Description
	/// -----------------------------------------------------------
	///              0 |  Output Port | maxon::Color | The result port.
	///              1 |   Input Port |   maxon::Url | The URL of the input image.
	///              2 |   Input Port |   maxon::Int | The index of the starting frame.
	///              3 |   Input Port |   maxon::Int | The index of the ending frame.
	///
	/// The setup could be the following:
	/// @code
	/// nodes::NODESPACE::ImageNodePortTuple imageTuple;
	/// imageTuple.first = NodePath::Create(ToSingletonBlock<InternedId>(MYSPACE::NODE::IMAGE::RESULT)) iferr_return;
	/// imageTuple.second = NodePath::Create(ToSingletonBlock<InternedId>(MYSPACE::NODE::IMAGE::URL)) iferr_return;
	/// imageTuple.third = NodePath::Create(ToSingletonBlock<InternedId>(MYSPACE::NODE::IMAGE::SEQUENCE_FRAMESTART)) iferr_return;
	/// imageTuple.fourth = NodePath::Create(ToSingletonBlock<InternedId>(MYSPACE::NODE::IMAGE::SEQUENCE_FRAMEEND)) iferr_return;
	/// spaceData.Set(nodes::NODESPACE::IMAGENODEPORTS, std::move(imageTuple)) iferr_return;
	/// @endcode
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(ImageNodePortTuple, IMAGENODEPORTS, "net.maxon.nodes.nodespace.IMAGENODEPORTS");

	using LayerSetUrlDelegate = Delegate<Result<Url>(const GraphNode&)>;

	//----------------------------------------------------------------------------------------
	/// A node space can set this property if it wants to use the built-in layerset UI for more
	/// than the image node. The layerset UI calls the delegate to obtain the Url to use for
	/// the given layerset port. For example, if the layerset port is in a port bundle which also
	/// contains a Url port with id "url", you can use code like this:
	/// @code
	/// nodes::NODESPACE::LayerSetUrlDelegate d = [] (const GraphNode& port) -> Result<Url>
	/// {
	/// 	iferr_scope;
	/// 	GraphNode urlPort = port.GetParent().FindChild(Id("url")) iferr_return;
	/// 	if (urlPort.IsValid())
	/// 	{
	/// 		return urlPort.GetDefaultValue(Url());
	/// 	}
	/// 	return {};
	/// };
	/// spaceData.Set(nodes::NODESPACE::LAYERSETURL, std::move(d)) iferr_return;
	/// @endcode
	/// If the node space doesn't set this property or if the delegate returns an empty Url,
	/// the port determined by IMAGENODEPORTS is used as fallback.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(LayerSetUrlDelegate, LAYERSETURL, "net.maxon.nodes.nodespace.layerseturl");

	using ImageNodeSetupDelegate = Delegate<Result<void>(const GraphNode&, const Url&)>;

	//----------------------------------------------------------------------------------------
	/// A node space can set this property if it wants to handle the setup of an image node
	/// for a given Url. The delegate receives the GraphNode of a newly create image node
	/// and the Url to use. Before the delegate is called, the ports determined by IMAGENODEPORTS
	/// have been set up (Url, start and end frame).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(ImageNodeSetupDelegate, IMAGENODESETUP, "net.maxon.nodes.nodespace.imagenodesetup");

	/// Is executed on every message that sent to the owning BaseMaterial. This message may be used to react and mutate the graph.
	///
	/// The node material comes with a default message handling behavior that can be disabled when returning true (indicating complete consume of the message).
	/// Note that the default behavior handles the undo system and other state changes outside of the node graph.
	///
	/// @param[in] graph						The node graph associated with the particular space.
	/// @param[in] messageId				The id of the message.
	/// @param[in] messageData			The (opaque) content of the message.
	/// @param[in] nodeMaterial			The (opaque) pointer to the BaseMaterial (of type NodeMaterial).
	/// @return											true if message is declared consumed, false if default consume behavior should follow.
	//----------------------------------------------------------------------------------------
	using MaterialMessageHandlerFunc = Delegate<Result<Bool>(const NodesGraphModelRef& graph, Int32 messageId, void* messageData, void* nodeMaterial)>;
	MAXON_ATTRIBUTE(MaterialMessageHandlerFunc, MATERIALMESSAGEHANDLERFUNC, "net.maxon.nodes.nodespace.materialmessagehandlerfunc");

	//----------------------------------------------------------------------------------------
	/// A node space can set this property to true to completely disable previews in the node editor.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Bool, DISABLE_PREVIEWS, "net.maxon.nodes.nodespace.disablepreviews");
} // namespace NODESPACE

//----------------------------------------------------------------------------------------
/// The following attributes are constructed by Cinema4d and available for query.
//----------------------------------------------------------------------------------------
namespace NODESPACE
{

	//----------------------------------------------------------------------------------------
	/// Defines the path to the currently defined start node, as used in the Attribute Manager.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(NodePath, STARTNODEPATH, "net.maxon.nodes.nodespace.startnodepath");

	//----------------------------------------------------------------------------------------
	/// Defines the path to the currently defined solo node, as used in the Node Editor and Viewport.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(NodePath, SOLONODEPATH, "net.maxon.nodes.nodespace.solonodepath");

	//----------------------------------------------------------------------------------------
	/// Defines the directory of the owning BaseDocument. This path may help resolving absolute paths 
	/// to assets defined in a relative fashion, such as images.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(Url, DOCUMENTPATH, "net.maxon.nodes.nodespace.documentpath");

	//----------------------------------------------------------------------------------------
	/// Defines a generic data container that exists on root GraphNode of every material node graph.
	/// It defines the connection between the node space-agnostic node graph and the space-specific
	/// embedding of the node graph into Cinema4d business logic.
	///
	/// Its content is currently restricted to
	/// supports maxon::nodes::NODESPACE::SPACEID
	/// supports maxon::nodes::NODESPACE::SOLONODEPATH
	/// supports maxon::nodes::NODESPACE::DOCUMENTPATH
	///
	/// The data can be extracted as such from a graph: 
	/// @code
	/// const maxon::DataDictionary graphContext = graph.GetRoot().GetValue(maxon::nodes::NODESPACE::NodeSpaceContext).GetValueOrNull() iferr_return;
	/// const maxon::Url documentPath = graphContext.Get(maxon::nodes::NODESPACE::DOCUMENTPATH, maxon::Url());
	/// @endcode
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE(DataDictionary, NodeSpaceContext, "net.maxon.nodes.nodespace.nodespacecontext");

}// namespace NODESPACE

class NodeSpaceRef;

//----------------------------------------------------------------------------------------
/// NodeSpaceInterface defines a hook into the node-based material system.
/// Each node material provides a container which can be populated under a specific maxon::nodes::NODESPACE::SPACEID.
/// Entries in this container store node graphs and provide connections to visible functionality of Cinema4d.
/// 
/// Components implementing this interface are expected to make such connections known by providing
/// appropriate attributes in the GetData() DataDictionary, such as
/// - a translated name
/// - a set of renderers that support the node graph stored under the space id
/// - a provider for preview thumbnails
/// - a provider for viewport representation
/// - a node system along with instaniable nodes
/// ...
/// 
/// Node graphs are stored in c4d files under the space id. If this space is unknown when loading the scene, e.g.
/// because the plugin is missing, scenes can be resaved without data loss.
/// 
/// It is recommended to initialize the space once and keep the data unchanged over the long lifetime.
//----------------------------------------------------------------------------------------
class NodeSpaceInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NodeSpaceInterface, MAXON_REFERENCE_NORMAL, "net.maxon.nodes.interface.nodespace");
public:

	//----------------------------------------------------------------------------------------
	/// Initializes the components and assigns meaningful data that can be queried via GetData().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(DataDictionary data);

	//----------------------------------------------------------------------------------------
	/// Fetches the data container and expects appropriate values for maxon::nodes::NODESPACE attributes.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD DataDictionary GetData() const;

	//----------------------------------------------------------------------------------------
	/// This callback is executed if the space's data has changed, e.g. the name.
	/// A copy-on-write state of the current data is provided.
	///
	/// @param[in] data				The current data container.
	//----------------------------------------------------------------------------------------
	using DataChangedObserver = Delegate<void(const DataDictionary& data)>;

	//----------------------------------------------------------------------------------------
	/// This is currently unused: No functionality monitors changes to an already registered space.
	/// 
	/// Adds an observer to changes for the space's data container.
	/// @param[in] observer												The delegate to be called on data change.
	/// @param[in] notifyDuringRegistration				If true, the current data state is *immediately* dispatched to the delegate, before returning from AddDataChangedObserver.
	/// @return																		The ticket to the observing delegate. Releasing it will auto-unsubscribe.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<GenericData> AddDataChangedObserver(DataChangedObserver&& observer, Bool notifyDuringRegistration);

protected:

	//----------------------------------------------------------------------------------------
	/// Updates the space's data and notifiers all registered DataChangedObserver's.
	///
	/// @param[in] data				The new data container.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void SetData(const DataDictionary& data);
};

//----------------------------------------------------------------------------------------
/// NodeSpaceHelpersInterface provides a collection of static helpers.
//----------------------------------------------------------------------------------------
class NodeSpaceHelpersInterface
{
	MAXON_INTERFACE_NONVIRTUAL(NodeSpaceHelpersInterface, MAXON_REFERENCE_NONE, "net.maxon.nodes.interface.nodespacehelpers");
public:

	//----------------------------------------------------------------------------------------
	/// Looks up the NodeSpaceRef within the MaterialNodeSpaces registry and returns the result of NodeSpaceInterface::GetData().
	/// @param[in] spaceId		The id of the space.
	/// @return								The data container of the space.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD DataDictionary GetNodeSpaceData(const Id& spaceId);

	//----------------------------------------------------------------------------------------
	/// Loads resource name under the current language for the provided Id and assigns it to the attribute maxon::nodes::NODESPACE::SPACENAME
	/// of the returned data container.
	/// @param[in] spaceDescriptionId				The id of the named description.
	/// @return															The data container with the assigned maxon::nodes::NODESPACE::SPACENAME attribute.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<DataDictionary> LoadDescription(const Id& spaceDescriptionId);
};

#include "node_spaces1.hxx"

//----------------------------------------------------------------------------------------
/// The registry of all material node spaces. This registry is monitored for changes by Cinema4d.
/// Add and remove operations are picked up by GUI components, offering the user to select among the registered spaces.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(NodeSpaceRef, MaterialNodeSpaces, "net.maxon.nodes.registry.materialnodespaces");

namespace MaterialNodeSpaces
{

	//----------------------------------------------------------------------------------------
	/// The Id of the "Standard" space that is being read when rendering with Standard Renderer, Physical Renderer, and
	/// Hardware renderer.
	//----------------------------------------------------------------------------------------
	MAXON_DECLARATION(NodeSpaceRef, Standard, "net.maxon.nodespace.standard");
}

//----------------------------------------------------------------------------------------
/// The base components implements the thread-safe paradigm for data change notification, including
/// - GetData()
/// - SetData()
/// - AddDataChangedObserver()
/// In addition, it implements a fallback initialization for incomplete data containers passed into Init():
/// - maxon::nodes::NODESPACE::SPACEID is assigned to GetClass().GetId()
/// - If maxon::nodes::NODESPACE::SPACENAME is missing, it's assigned with the stringified SPACEID
/// - If maxon::nodes::NODESPACE::VIEWPORTMATERIALCLASS is missing, it's assigned with a constant gray dielectric viewport material.
/// 
/// It is encouraged to make use of the NodeSpaceBaseClass:
/// @code
/// class MySpace : public maxon::Component<MySpace, maxon::nodes::NodeSpaceInterface>
/// {
///		MAXON_COMPONENT(NORMAL, maxon::nodes::NodeSpaceBaseClass);
///	public:
///		MAXON_METHOD maxon::Result<void> Init(maxon::DataDictionary spaceData)
///			{
///				iferr_scope;
///
///				// Initialize spaceData attributes
///
///				return super.Init(spaceData); // Make use of the fallback init.
///			}
/// };
/// @endcode
//----------------------------------------------------------------------------------------
MAXON_DECLARATION(Class<NodeSpaceRef>, NodeSpaceBaseClass, "net.maxon.class.nodespace.base");

#include "node_spaces2.hxx"

} // namespace nodes
} // namespace maxon

#endif // NODE_SPACES_H__
