#ifndef DATADESCRIPTION_NODES_H__
#define DATADESCRIPTION_NODES_H__

#include "maxon/assets.h"
#include "maxon/fid.h"
#include "maxon/idandversion.h"
#include "maxon/nodesgraph.h"
#include "maxon/url.h"
#include "maxon/vector.h"
#include "maxon/vector2d.h"
#include "maxon/vector4d.h"

namespace maxon
{

class ImageBaseRef;

}

#ifdef DOMAIN
	#undef DOMAIN // normally defined by math.h to indicate a domain error which can be reported by matherr()
#endif

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace NODE
{
	namespace ATTRIBUTE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.attribute");

		/// This attribute defines the port order on variadic ports.
		MAXON_ATTRIBUTE(Int, ORDERINDEX, "net.maxon.node.attribute.orderindex");

		/// This attribute defines the node insert order. This can be
		/// used to sort for insert order.
		MAXON_ATTRIBUTE(Int, INSERTINDEX, "net.maxon.node.attribute.insertindex");

		/// This attribute can be set for nodes or ports to hide them.
		MAXON_ATTRIBUTE(Bool, INTERNALHIDDEN, "net.maxon.node.attribute.internalhidden");

		/// True if the port needs a constant value.
		MAXON_ATTRIBUTE(Bool, CONSTANTPARAMETER, "net.maxon.node.attribute.constantparameter");

		/// True if the port is an optional parameter for the node.
		MAXON_ATTRIBUTE(Bool, OPTIONAL, "net.maxon.node.attribute.optional");

		/// True if the port is a converter port which should 
		/// show up in the insertconverternode command.
		/// Please make sure you marked one input and one 
		/// output as converter port for a node.
		MAXON_ATTRIBUTE(Bool, ISCONVERTERPORT, "net.maxon.node.attribute.isconverterport");

		/// True if this port is the default preview calculation output.
		MAXON_ATTRIBUTE(Bool, ISPREVIEWPORT, "net.maxon.node.attribute.ispreviewport");

		/// Optional Identifier which defines the outport from which enum/unit/min/max/step values should 
		/// be copied from
		MAXON_ATTRIBUTE(InternedId, COPYUNITSFROMOUTPORT, "net.maxon.node.attribute.copyunitsfromoutport");

		/// True if the port should be hidden in the node editor.
		MAXON_ATTRIBUTE(Bool, HIDEPORTINNODEGRAPH, "net.maxon.node.attribute.hideportinnodegraph");

		/// True if the attribute should appear only on the left side in the Material Editor.
		MAXON_ATTRIBUTE(Bool, MATERIALEDITORSHOWONLEFTSIDE, "net.maxon.node.attribute.materialeditorshowonleftside");

		/// If net.maxon.node.attribute.materialpreviewshowonleftside is true this attribute defines
		/// which group should be activated when clicking on the element.
		MAXON_ATTRIBUTE(InternedId, MATERIALEDITORGROUPACTIVATION, "net.maxon.node.attribute.materialeditorgroupactivation");

		/// With a mode other than "none" the scene manager uses the port for its scene representation.
		MAXON_ATTRIBUTE(InternedId, SCENEPORTMODE, "net.maxon.node.attribute.sceneportmode");
		MAXON_ATTRIBUTE(void, SCENEPORTMODE_ENUM_NONE, "none");
		MAXON_ATTRIBUTE(void, SCENEPORTMODE_ENUM_OBJECT, "object");
		MAXON_ATTRIBUTE(void, SCENEPORTMODE_ENUM_LINK, "link");
		MAXON_ATTRIBUTE(void, SCENEPORTMODE_ENUM_MODIFIER, "modifier");

		/// Choose the context which this port shall receive it's value from.  If the port is connected, the connected value will override any selected context.
		MAXON_ATTRIBUTE(Id, NODECONTEXT, "net.maxon.node.attribute.nodecontext",
			RESOURCE_DEFINE(ENUM_NONE, Id("none"))
			RESOURCE_DEFINE(ENUM_NODECONTEXT_NET_MAXON, Id("nodecontext#net.maxon")));

		/// ID of the asset
		MAXON_ATTRIBUTE(IdAndVersion, ASSETID, "net.maxon.node.attribute.assetid");

		/// ID of the Database where the object is stored
		MAXON_ATTRIBUTE(Id, REPOSITORYID, "net.maxon.node.attribute.repositoryid");
	}

	namespace BASE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.base");

		/// Trigger for the preview Image of the node. Please note that this is not directly available. 
		/// Please use the NodesPreviewRenderDataInterface for preview rendering.
		MAXON_ATTRIBUTE(ImageBaseRef, NODEPREVIEWIMAGE, "net.maxon.node.base.nodepreviewimage");

		/// Trigger for the preview Image of the material. Please note that this is not directly available. 
		/// Please use the NodesPreviewRenderDataInterface for preview rendering.
		MAXON_ATTRIBUTE(ImageBaseRef, MATERIALPREVIEWIMAGE, "net.maxon.node.base.materialpreviewimage");

		/// This attribute represents the name of a node. The name should be used for the
		/// user interface instead of the identifier. 
		/// Use NodesHelperInterface::GetNodeName() instead of using this directly.
		MAXON_ATTRIBUTE(String, NAME, "net.maxon.node.base.name");

		MAXON_ATTRIBUTE(Id, ASSETVERSION, "net.maxon.node.base.assetversion");

		/// Node Color to be used in the node editor
		MAXON_ATTRIBUTE(Color, COLOR, "net.maxon.node.base.color");

		MAXON_ATTRIBUTE(Id, PORTDISPLAY, "net.maxon.node.base.portdisplay",
			RESOURCE_DEFINE(ENUM_NONE, Id("none"))
			RESOURCE_DEFINE(ENUM_CONNECTED, Id("connected"))
			RESOURCE_DEFINE(ENUM_ALL, Id("all")));

		MAXON_ATTRIBUTE(Bool, DISPLAYPREVIEW, "net.maxon.node.base.displaypreview");

		/// Displays the comment under the node.
		MAXON_ATTRIBUTE(Bool, DISPLAYCOMMENT, "net.maxon.node.base.displaycomment");

		MAXON_ATTRIBUTE(String, COMMENT, "net.maxon.node.base.comment");

		/// Filter tags for the object.
		MAXON_ATTRIBUTE(CString, FILTERTAGS, "net.maxon.node.base.filtertags");

		MAXON_ATTRIBUTE(InternedId, CATEGORY, "net.maxon.node.base.category");
		MAXON_ATTRIBUTE(void, CATEGORY_ENUM_DISTRIBUTIONS, "distributions");
		MAXON_ATTRIBUTE(void, CATEGORY_ENUM_GEOMETRIES, "geometries");
		MAXON_ATTRIBUTE(void, CATEGORY_ENUM_PATTERNS, "patterns");
		MAXON_ATTRIBUTE(void, CATEGORY_ENUM_OPERATORS, "operators");
		MAXON_ATTRIBUTE(void, CATEGORY_ENUM_PRIMITIVES, "primitives");
		MAXON_ATTRIBUTE(void, CATEGORY_ENUM_EFFECTORS, "effectors");
		MAXON_ATTRIBUTE(void, CATEGORY_ENUM_FIELDS, "fields");
		MAXON_ATTRIBUTE(void, CATEGORY_ENUM_FUNCTIONS, "functions");
		MAXON_ATTRIBUTE(void, CATEGORY_ENUM_STRUCTURES, "structures");

		/// Icon identifier to use in the UI.
		MAXON_ATTRIBUTE(CString, ICON, "net.maxon.node.base.icon");

		MAXON_ATTRIBUTE(ASSET_UPDATE_POLICY, UPDATEPOLICY, "net.maxon.node.base.updatepolicy");

		// supports MAXON::ASSET::BASE::PROTECTED

		MAXON_ATTRIBUTE(void, CONNECTNODE, "net.maxon.node.base.connectnode");

		MAXON_ATTRIBUTE(void, REPLACENODE, "net.maxon.node.base.replacenode");

		MAXON_ATTRIBUTE(void, TOGGLENODETYPE, "net.maxon.node.base.togglenodetype");

		MAXON_ATTRIBUTE(void, CONNECTLAYEREDNODE, "net.maxon.node.base.connectlayerednode");

		MAXON_ATTRIBUTE(void, INSERTCONVERTERNODE, "net.maxon.node.base.insertconverternode");

		MAXON_ATTRIBUTE(void, ADDINPORT, "net.maxon.node.base.addinport");

		MAXON_ATTRIBUTE(void, ADDOUTPORT, "net.maxon.node.base.addoutport");

		MAXON_ATTRIBUTE(void, AVAILABLETEXTURES, "net.maxon.node.base.availabletextures");

		MAXON_ATTRIBUTE(void, LOADTEXTURE, "net.maxon.node.base.loadtexture");

		MAXON_ATTRIBUTE(void, COPYCONNECTION, "net.maxon.node.base.copyconnection");

		MAXON_ATTRIBUTE(void, PASTECONNECTION, "net.maxon.node.base.pasteconnection");

		MAXON_ATTRIBUTE(void, PASTECONNECTIONASCOPY, "net.maxon.node.base.pasteconnectionascopy");

		MAXON_ATTRIBUTE(void, REMOVE, "net.maxon.node.base.remove");

		MAXON_ATTRIBUTE(void, REMOVEPORTINSTANCE, "net.maxon.node.base.removeportinstance");

		MAXON_ATTRIBUTE(void, HIDEPORT, "net.maxon.node.base.hideport");

		MAXON_ATTRIBUTE(void, PORTINSPECTOR, "net.maxon.node.base.portinspector");

		MAXON_ATTRIBUTE(void, DATAINSPECTOR, "net.maxon.node.base.datainspector");

		MAXON_ATTRIBUTE(void, ADDNESTEDPORT, "net.maxon.node.base.addnestedport");

		MAXON_ATTRIBUTE(void, HIDEUNUSEDPORTS, "net.maxon.node.base.hideunusedports");

		MAXON_ATTRIBUTE(void, MUTEPORT, "net.maxon.node.base.muteport");

		MAXON_ATTRIBUTE(void, SOLOPORT, "net.maxon.node.base.soloport");

		MAXON_ATTRIBUTE(void, SHOWSUBCHANNELS, "net.maxon.node.base.showsubchannels");

		MAXON_ATTRIBUTE(void, PROPAGATEPORT, "net.maxon.node.base.propagateport");

		MAXON_ATTRIBUTE(void, INHERITINTERFACE, "net.maxon.node.base.inheritinterface");

		MAXON_ATTRIBUTE(void, SETASPREVIEWPORT, "net.maxon.node.base.setaspreviewport");

		MAXON_ATTRIBUTE(void, RESETTODEFAULTVALUE, "net.maxon.node.base.resettodefaultvalue");

		MAXON_ATTRIBUTE(void, SHOWNODEEDITOR, "net.maxon.node.base.shownodeeditor");

		MAXON_ATTRIBUTE(void, SHOWPREVIEW, "net.maxon.node.base.showpreview");

		MAXON_ATTRIBUTE(void, HIDEPREVIEW, "net.maxon.node.base.hidepreview");

		MAXON_ATTRIBUTE(void, PORTSTATEHORIZONTAL, "net.maxon.node.base.portstatehorizontal");

		MAXON_ATTRIBUTE(void, PORTSTATEVERTICAL, "net.maxon.node.base.portstatevertical");

		MAXON_ATTRIBUTE(void, NODESTATESHOWALL, "net.maxon.node.base.nodestateshowall");

		MAXON_ATTRIBUTE(void, NODESTATESHOWCONNECTED, "net.maxon.node.base.nodestateshowconnected");

		MAXON_ATTRIBUTE(void, NODESTATECOLLAPSED, "net.maxon.node.base.nodestatecollapsed");

		MAXON_ATTRIBUTE(void, SELECTCONNECTED, "net.maxon.node.base.selectconnected");

		MAXON_ATTRIBUTE(void, LAYOUTSELECTED, "net.maxon.node.base.layoutselected");

		MAXON_ATTRIBUTE(void, CUT, "net.maxon.node.base.cut");

		MAXON_ATTRIBUTE(void, COPY, "net.maxon.node.base.copy");

		MAXON_ATTRIBUTE(void, PASTE, "net.maxon.node.base.paste");

		MAXON_ATTRIBUTE(void, DUPLICATE, "net.maxon.node.base.duplicate");

		MAXON_ATTRIBUTE(void, COPYVALUE, "net.maxon.node.base.copyvalue");

		MAXON_ATTRIBUTE(void, COPYTYPE, "net.maxon.node.base.copytype");

		MAXON_ATTRIBUTE(void, PASTEVALUE, "net.maxon.node.base.pastevalue");

		MAXON_ATTRIBUTE(void, SETDEDUCEDTYPE, "net.maxon.node.base.setdeducedtype");

		MAXON_ATTRIBUTE(void, CREATEGROUP, "net.maxon.node.base.creategroup");

		MAXON_ATTRIBUTE(void, DISOLVEGROUP, "net.maxon.node.base.disolvegroup");

		MAXON_ATTRIBUTE(void, ADDALLPORTS, "net.maxon.node.base.addallports");

		MAXON_ATTRIBUTE(void, CONVERTGROUPTOASSET, "net.maxon.node.base.convertgrouptoasset");

		MAXON_ATTRIBUTE(void, CONVERTASSETTOGROUP, "net.maxon.node.base.convertassettogroup");

		MAXON_ATTRIBUTE(void, EDITPORT, "net.maxon.node.base.editport");

		MAXON_ATTRIBUTE(void, EDITDESCRIPTION, "net.maxon.node.base.editdescription");

		MAXON_ATTRIBUTE(void, EDITASSET, "net.maxon.node.base.editasset");

		MAXON_ATTRIBUTE(void, SELECTCHILDREN, "net.maxon.node.base.selectchildren");

		MAXON_ATTRIBUTE(void, GROUPOBJECTS, "net.maxon.node.base.groupobjects");

		MAXON_ATTRIBUTE(void, UNGROUPOBJECTS, "net.maxon.node.base.ungroupobjects");

		MAXON_ATTRIBUTE(void, DELETEWITHOUTCHILDREN, "net.maxon.node.base.deletewithoutchildren");

		MAXON_ATTRIBUTE(void, UNPARENT, "net.maxon.node.base.unparent");

		MAXON_ATTRIBUTE(void, FOLDALL, "net.maxon.node.base.foldall");

		MAXON_ATTRIBUTE(void, UNFOLDALL, "net.maxon.node.base.unfoldall");

		MAXON_ATTRIBUTE(void, FOLDSELECTED, "net.maxon.node.base.foldselected");

		MAXON_ATTRIBUTE(void, UNFOLDSELECTED, "net.maxon.node.base.unfoldselected");

		MAXON_ATTRIBUTE(void, FOLDSELECTEDSTACKS, "net.maxon.node.base.foldselectedstacks");

		MAXON_ATTRIBUTE(void, UNFOLDSELECTEDSTACKS, "net.maxon.node.base.unfoldselectedstacks");

		MAXON_ATTRIBUTE(void, TOGGLESHOWTAGSELECTION, "net.maxon.node.base.toggleshowtagselection");

		MAXON_ATTRIBUTE(void, REVEALINNODEEDITOR, "net.maxon.node.base.revealinnodeeditor");

		MAXON_ATTRIBUTE(Group, PREVIEW, "net.maxon.node.base.preview");

		MAXON_ATTRIBUTE(Group, GROUP_BASIC, "net.maxon.node.base.group.basic");

		MAXON_ATTRIBUTE(Group, GROUP_COORD, "net.maxon.node.base.group.coord");

		MAXON_ATTRIBUTE(Group, GROUP_INPUTS, "net.maxon.node.base.group.inputs");

		MAXON_ATTRIBUTE(Group, GROUP_OUTPUTS, "net.maxon.node.base.group.outputs");

		MAXON_ATTRIBUTE(Group, GROUP_OBJECT, "net.maxon.node.base.group.object");

		MAXON_ATTRIBUTE(String, STRINGS_PROPAGATED, "net.maxon.node.base.strings.propagated");

		MAXON_ATTRIBUTE(String, STRINGS_NOCOMPATIBLENODESFOUND, "net.maxon.node.base.strings.nocompatiblenodesfound");

		MAXON_ATTRIBUTE(String, STRINGS_NOPORTSTOADD, "net.maxon.node.base.strings.noportstoadd");

		MAXON_ATTRIBUTE(String, STRINGS_ADDINPUT, "net.maxon.node.base.strings.addinput");

		MAXON_ATTRIBUTE(String, STRINGS_ADDOUTPUT, "net.maxon.node.base.strings.addoutput");

		MAXON_ATTRIBUTE(String, NOTEXTURESFOUND, "net.maxon.node.base.notexturesfound");

		MAXON_ATTRIBUTE(String, STRINGS_ALL, "net.maxon.node.base.strings.all");

		MAXON_ATTRIBUTE(String, STRINGS_PORT, "net.maxon.node.base.strings.port");

		MAXON_ATTRIBUTE(String, PORTCONSTERROR, "net.maxon.node.base.portconsterror");

		namespace COMMANDS
		{
			namespace DEV
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.base.commands.dev");
				MAXON_ATTRIBUTE(void, WRITEGML, "net.maxon.node.base.commands.dev.writegml");

				MAXON_ATTRIBUTE(void, WRITEGMLFILTERED, "net.maxon.node.base.commands.dev.writegmlfiltered");

				MAXON_ATTRIBUTE(void, WRITEGMLCORE, "net.maxon.node.base.commands.dev.writegmlcore");

				MAXON_ATTRIBUTE(void, WRITEGMLBLOCK, "net.maxon.node.base.commands.dev.writegmlblock");

				MAXON_ATTRIBUTE(void, DUMPATTRIBUTES, "net.maxon.node.base.commands.dev.dumpattributes");
			}
		}
	}

	namespace COLORCATEGORIES
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.colorcategories");

		MAXON_ATTRIBUTE(Color, DISTRIBUTIONS, "distributions");

		MAXON_ATTRIBUTE(Color, GEOMETRIES, "geometries");

		MAXON_ATTRIBUTE(Color, PATTERNS, "patterns");

		MAXON_ATTRIBUTE(Color, OPERATORS, "operators");

		MAXON_ATTRIBUTE(Color, GENERATORS, "generators");

		MAXON_ATTRIBUTE(Color, PRIMITIVES, "primitives");

		MAXON_ATTRIBUTE(Color, SPLINEPRIMITIVES, "splineprimitives");

		MAXON_ATTRIBUTE(Color, EFFECTORS, "effectors");

		MAXON_ATTRIBUTE(Color, FIELDS, "fields");

		MAXON_ATTRIBUTE(Color, FUNCTIONS, "functions");

		MAXON_ATTRIBUTE(Color, STRUCTURES, "structures");
	}

	namespace GROUPPORTS
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.groupports");

		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
		// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
		// supports MAXON::NODE::BASE::NAME
		// supports MAXON::NODE::BASE::ASSETVERSION
		// supports MAXON::NODE::BASE::COLOR
		// supports MAXON::NODE::BASE::PORTDISPLAY
		// supports MAXON::NODE::BASE::DISPLAYPREVIEW
		// supports MAXON::NODE::BASE::DISPLAYCOMMENT
		// supports MAXON::NODE::BASE::COMMENT
		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::CATEGORY
		// supports MAXON::NODE::BASE::ICON
		// supports MAXON::NODE::BASE::UPDATEPOLICY
		// supports MAXON::ASSET::BASE::PROTECTED

		/// This is the default template port for user inports.
		MAXON_ATTRIBUTE(void, DEFAULTINPORT, "net.maxon.node.groupports.defaultinport");

		/// This is the default template port for user outports.
		MAXON_ATTRIBUTE(void, DEFAULTOUTPORT, "net.maxon.node.groupports.defaultoutport");
	}

	namespace INPORTGROUP
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.inportgroup");

		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
		// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
		// supports MAXON::NODE::BASE::NAME
		// supports MAXON::NODE::BASE::ASSETVERSION
		// supports MAXON::NODE::BASE::COLOR
		// supports MAXON::NODE::BASE::PORTDISPLAY
		// supports MAXON::NODE::BASE::DISPLAYPREVIEW
		// supports MAXON::NODE::BASE::DISPLAYCOMMENT
		// supports MAXON::NODE::BASE::COMMENT
		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::CATEGORY
		// supports MAXON::NODE::BASE::ICON
		// supports MAXON::NODE::BASE::UPDATEPOLICY
		// supports MAXON::ASSET::BASE::PROTECTED
	}

	namespace IO
	{
		namespace IN
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.io.in");

			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
			// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
			// supports MAXON::NODE::BASE::NAME
			// supports MAXON::NODE::BASE::ASSETVERSION
			// supports MAXON::NODE::BASE::COLOR
			// supports MAXON::NODE::BASE::PORTDISPLAY
			// supports MAXON::NODE::BASE::DISPLAYPREVIEW
			// supports MAXON::NODE::BASE::DISPLAYCOMMENT
			// supports MAXON::NODE::BASE::COMMENT
			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::CATEGORY
			// supports MAXON::NODE::BASE::ICON
			// supports MAXON::NODE::BASE::UPDATEPOLICY
			// supports MAXON::ASSET::BASE::PROTECTED
		}

		namespace OUT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.io.out");

			// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
			// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
			// supports MAXON::NODE::BASE::NAME
			// supports MAXON::NODE::BASE::ASSETVERSION
			// supports MAXON::NODE::BASE::COLOR
			// supports MAXON::NODE::BASE::PORTDISPLAY
			// supports MAXON::NODE::BASE::DISPLAYPREVIEW
			// supports MAXON::NODE::BASE::DISPLAYCOMMENT
			// supports MAXON::NODE::BASE::COMMENT
			// supports MAXON::NODE::BASE::FILTERTAGS
			// supports MAXON::NODE::BASE::CATEGORY
			// supports MAXON::NODE::BASE::ICON
			// supports MAXON::NODE::BASE::UPDATEPOLICY
			// supports MAXON::ASSET::BASE::PROTECTED
		}
	}

	namespace OUTPORTGROUP
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.outportgroup");

		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
		// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
		// supports MAXON::NODE::BASE::NAME
		// supports MAXON::NODE::BASE::ASSETVERSION
		// supports MAXON::NODE::BASE::COLOR
		// supports MAXON::NODE::BASE::PORTDISPLAY
		// supports MAXON::NODE::BASE::DISPLAYPREVIEW
		// supports MAXON::NODE::BASE::DISPLAYCOMMENT
		// supports MAXON::NODE::BASE::COMMENT
		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::CATEGORY
		// supports MAXON::NODE::BASE::ICON
		// supports MAXON::NODE::BASE::UPDATEPOLICY
		// supports MAXON::ASSET::BASE::PROTECTED
	}

	namespace PORTBUNDLE
	{
		namespace SPLINEKNOT
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.portbundle.splineknot");

			/// Position of the spline knot
			MAXON_ATTRIBUTE(Vector2d, POS, "net.maxon.node.portbundle.splineknot.pos");

			/// Lock knot's X movement.
			MAXON_ATTRIBUTE(Bool, LOCKX, "net.maxon.node.portbundle.splineknot.lockx");

			/// Lock knot's Y movement.
			MAXON_ATTRIBUTE(Bool, LOCKY, "net.maxon.node.portbundle.splineknot.locky");

			/// Knot interpolation mode
			MAXON_ATTRIBUTE(Id, INTERPOLATION, "net.maxon.node.portbundle.splineknot.interpolation",
				RESOURCE_DEFINE(ENUM_BEZIER, Id("bezier"))
				RESOURCE_DEFINE(ENUM_LINEAR, Id("linear"))
				RESOURCE_DEFINE(ENUM_CUBIC, Id("cubic")));

			/// Left Tangent value.
			MAXON_ATTRIBUTE(Vector2d, TANGENTLEFT, "net.maxon.node.portbundle.splineknot.tangentleft");

			/// Right tangent value
			MAXON_ATTRIBUTE(Vector2d, TANGENTRIGHT, "net.maxon.node.portbundle.splineknot.tangentright");

			/// Break knot tangents.
			MAXON_ATTRIBUTE(Bool, BREAK, "net.maxon.node.portbundle.splineknot.break");

			/// Lock knot's tangent angle.
			MAXON_ATTRIBUTE(Bool, LOCKANGLE, "net.maxon.node.portbundle.splineknot.lockangle");

			/// Lock knot's tangent length.
			MAXON_ATTRIBUTE(Bool, LOCKLENGTH, "net.maxon.node.portbundle.splineknot.locklength");

			/// Keep visual angle between knot's tangents.
			MAXON_ATTRIBUTE(Bool, KEEPVISUALANGLE, "net.maxon.node.portbundle.splineknot.keepvisualangle");
		}
	}

	namespace WIRE
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.wire");

		MAXON_ATTRIBUTE(void, INSERTCONVERTERNODE, "net.maxon.node.wire.insertconverternode");

		MAXON_ATTRIBUTE(void, REMOVECONNECTION, "net.maxon.node.wire.removeconnection");

		MAXON_ATTRIBUTE(void, MUTE, "net.maxon.node.wire.mute");

		MAXON_ATTRIBUTE(void, CHAIN, "net.maxon.node.wire.chain");
	}

	namespace WITHOUTPUTS
	{
		MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.node.withoutputs");

		// supports MAXON::NODE::BASE::NODEPREVIEWIMAGE
		// supports MAXON::NODE::BASE::MATERIALPREVIEWIMAGE
		// supports MAXON::NODE::BASE::NAME
		// supports MAXON::NODE::BASE::ASSETVERSION
		// supports MAXON::NODE::BASE::COLOR
		// supports MAXON::NODE::BASE::PORTDISPLAY
		// supports MAXON::NODE::BASE::DISPLAYPREVIEW
		// supports MAXON::NODE::BASE::DISPLAYCOMMENT
		// supports MAXON::NODE::BASE::COMMENT
		// supports MAXON::NODE::BASE::FILTERTAGS
		// supports MAXON::NODE::BASE::CATEGORY
		// supports MAXON::NODE::BASE::ICON
		// supports MAXON::NODE::BASE::UPDATEPOLICY
		// supports MAXON::ASSET::BASE::PROTECTED

		MAXON_ATTRIBUTE(void, OUTPUTS, "outputs");
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

namespace maxon
{

namespace NODE
{
	namespace ATTRIBUTE
	{
		/// Asset
		MAXON_ATTRIBUTE(Asset, ASSET, "net.maxon.node.attribute.asset");

		/// Depth of the path of the asset in the node system
		MAXON_ATTRIBUTE(Int, ASSETPATHDEPTH, "net.maxon.node.attribute.assetpathdepth");
	}
}

class LazyLanguageStringDataDescriptionDefinition;
class LazyLanguageDictionary;

namespace nodes
{

MAXON_ATTRIBUTE(void, NodeCategoryExistingNodes, "net.maxon.nodecategory.existingnodes");

using LanguageDictionary = DataDictionary; // key == [Id] of the LanguageRef, Value = [DataDictionary]

//----------------------------------------------------------------------------------------
/// Data/Ui/String description of a node port
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(DataDictionary, PortDescriptionData, "portDescriptionData");
MAXON_ATTRIBUTE(DataDictionary, PortDescriptionUi, "portDescriptionUi");

// Lazy loading of LanguageDictionary reads the meta data from the string-<<language>>.meta on first access.
MAXON_ATTRIBUTE(LazyLanguageDictionary, PortDescriptionStringLazy, "portDescriptionStringLazy");

//----------------------------------------------------------------------------------------
/// Data/Ui/String description of a node
//----------------------------------------------------------------------------------------
MAXON_ATTRIBUTE(DataDescriptionDefinition, NodeDescriptionData, "nodeDescriptionData");
MAXON_ATTRIBUTE(DataDescriptionDefinition, NodeDescriptionUi, "nodeDescriptionUi");

// Lazy loading of LanguageStringDataDescriptionDefinition reads the meta data from the string-<<language>>.meta on first access.
MAXON_ATTRIBUTE(LazyLanguageStringDataDescriptionDefinition, NodeDescriptionStringLazy, "nodeDescriptionStringLazy");

//----------------------------------------------------------------------------------------
/// Callback type for port description update/modify events. Overwrite or modify the content of
/// the loaded description based on node graph state, attributes, connections, ...
/// @param[in,out] description		The description to update.
/// @param[in] port								The path to parse. Content depends on #category.
/// @param[in] category						The #description category, DATADESCRIPTION_CATEGORY_DATA/UI/STRING.
/// @return												OK on success.
//----------------------------------------------------------------------------------------
using PortDescriptionProvider = Delegate<Result<void>(DataDictionary& description, const GraphNode& port, const Id& category)>;
/// PortDescriptionProvider registry, keys are the node resource ids. Values are the delegates.
/// Delegate will get called every time the node's description has to be updated.	Hence the provider 
/// will affect the description of all node instance of the "key" node.
MAXON_REGISTRY(PortDescriptionProvider, PortDescriptionProviders, "net.maxon.nodes.portdescriptionproviders");

//----------------------------------------------------------------------------------------
/// Callback type for port description update/modify events. These are called after PortDescriptionProviders
/// if any applies to #port's node. Overwrite or modify the content of
/// the loaded description based on node graph state, attributes, connections, ...
/// @param[in] port								The path to parse. Content depends on #category.
/// @param[in] additionalArgs			Additional arguments given to the description provider 
///																(in the form "memberindex#net.maxon.someid,int" where we have 1 string with 2 additional arguments "net.maxon.someid" and "int").
/// @param[in] enumEntryIdx				The index of the registered enumeration entry in DESCRIPTION::DATA::BASE::ENUM (useful for insertion).
/// @param[in,out] description		The description to update.
/// @param[in] category						The #description category, DATADESCRIPTION_CATEGORY_DATA/UI/STRING.
/// @return												OK on success.
//----------------------------------------------------------------------------------------
using PortEnumDescriptionProvider = Delegate<Result<void>(const GraphNode& port, const CString& additionalArgs, Int enumEntryIdx, DataDictionary& description, const Id& category)>;
/// PortEnumDescriptionProvider registry, keys are the enum token ids. Values are the delegates.
/// Delegate will get called every time a node's description gets updated if the node uses the key as a special enum entry.
/// For instance a Resource Editor enum entry to list all align options would look like this 
/// "enum#net.maxon.neutron.datatype.enum.alignaxis" where the token identifier is "enum".
/// This is similar to ProcessEnumListDelegates registry but here you have access to the node graph.
MAXON_REGISTRY(PortEnumDescriptionProvider, PortEnumDescriptionProviders, "net.maxon.nodes.portenumdescriptionproviders");


} // namespace nodes

MAXON_INTERNED_ID("in", DefaultInIoNode);
MAXON_INTERNED_ID("out", DefaultOutIoNode);

namespace ARGUMENTS
{
	namespace NODECORE
	{
		//----------------------------------------------------------------------------------------
		/// Reference to the graph in which all the paths (see below) can be found.
		//----------------------------------------------------------------------------------------
		MAXON_ATTRIBUTE(GraphModelRef, GRAPHMODEL, "net.maxon.arguments.nodecore.graphmodel");
		
		/// Used for various commands, this should contain a node path. But for numerous cases if might contain a port path.
		MAXON_ATTRIBUTE(IoNodePath, NODEPATH, "net.maxon.arguments.nodecore.nodepath");
		
		/// Used for various commands, port contextual menus and also wire (as target).
		MAXON_ATTRIBUTE(IoNodePath, PORTPATH, "net.maxon.arguments.nodecore.portpath");
		
		/// Used for wire contextual menus only.
		MAXON_ATTRIBUTE(IoNodePath, SRCPORTPATH, "net.maxon.arguments.nodecore.srcportpath");
	
		//----------------------------------------------------------------------------------------
		/// Used for port contextual menus and callbacks (buttons, value changed, etc).
		/// Points to the internal port from which the message stems (full path).
		/// Mandatory for all button messages and callbacks.
		//----------------------------------------------------------------------------------------
		MAXON_ATTRIBUTE(NodePath, INNERPORTPATH, "net.maxon.arguments.nodecore.innerportpath");

		MAXON_ATTRIBUTE(String, FILTERTAGS, "net.maxon.arguments.nodecore.filtertags");
		
		//----------------------------------------------------------------------------------------
		/// Used for commands which show a popup menu: shall new nodes (insertable in the current context) be included in the menu?
		/// Optional.
		//----------------------------------------------------------------------------------------
		MAXON_ATTRIBUTE(Bool, INCLUDE_NEW_INSERTABLE_NODES, "net.maxon.arguments.nodecore.includenewinsertablenodes");
		
		//----------------------------------------------------------------------------------------
		/// Description of the node given by #NODEPATH.
		/// Optional.
		//----------------------------------------------------------------------------------------
		MAXON_ATTRIBUTE(DataDescriptionWithUIAndString, NODEDESCRIPTION, "net.maxon.arguments.nodecore.nodedescription");

	} // namespace NODECORE
} // namespace ARGUMENTS

#include "datadescription_nodes1.hxx"
#include "datadescription_nodes2.hxx"

} // namespace maxon

#endif // DATADESCRIPTION_NODES_H__
