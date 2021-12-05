#ifndef DATADESCRIPTION_UI_H__
#define DATADESCRIPTION_UI_H__

#include "maxon/basearray.h"
#include "maxon/datadescriptiondefinitiondatabase.h"
#include "maxon/string.h"

//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
namespace DESCRIPTION
{
	namespace UI
	{
		namespace BASE
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.ui.base");

			// supports MAXON::DESCRIPTION::BASE::COMMAND
			// supports MAXON::DESCRIPTION::BASE::IDENTIFIER

			/// Id of the ui to use to display this attribute.
			MAXON_ATTRIBUTE(maxon::Id, GUITYPEID, "net.maxon.description.ui.base.guitypeid");

			/// Accept list for link fields. It's possible to use symbolic names like Obase, Ocamera.
			MAXON_ATTRIBUTE(maxon::BaseArray<maxon::Id>, BASELINK_ACCEPT, "net.maxon.description.ui.base.baselink.accept");

			/// Id of the group into which the attribute should be assigned
			MAXON_ATTRIBUTE(maxon::InternedId, GROUPID, "net.maxon.description.ui.base.groupid");

			MAXON_ATTRIBUTE(maxon::Bool, SHOWGROUPINPORTLIST, "net.maxon.description.ui.base.showgroupinportlist");

			/// Condition which will be evaluated before displaying the value. If the term returns false the attribute will be hidden.
			MAXON_ATTRIBUTE(maxon::CString, SHOW, "net.maxon.description.ui.base.show");

			/// Condition which controls the enabling of the ui element. True to enable it.
			MAXON_ATTRIBUTE(maxon::CString, ENABLE, "net.maxon.description.ui.base.enable");

			/// Optional Id of the parent attribute. If given the ui will ident the attribute. 
			/// If the parent contains it's own id the parent is foldable.
			MAXON_ATTRIBUTE(maxon::InternedId, PARENTFOLDERID, "net.maxon.description.ui.base.parentfolderid");

			/// True to open the parent group by default
			MAXON_ATTRIBUTE(maxon::Bool, PARENTFOLDERIDDEFAULTOPEN, "net.maxon.description.ui.base.parentfolderiddefaultopen");

			/// Command "preset": Preset id to define the key under which the presetmembers will be stored. E.g. "net.maxon.presets.colors"
			MAXON_ATTRIBUTE(maxon::Id, PRESETDATABASEID, "net.maxon.description.ui.base.presetdatabaseid",
				RESOURCE_DEFINE(ENUM_ASSETTYPE_NET_MAXON_ASSETTYPE_PRESET, maxon::Id("assettype#net.maxon.assettype.preset")));

			/// Command "preset": A list of preset members to store under the preset id.
			MAXON_ATTRIBUTE(MAXON_MACROARG_TYPE(maxon::BaseArray<maxon::Tuple<maxon::InternedId, maxon::InternedId>>), PRESETMEMBERS, "net.maxon.description.ui.base.presetmembers");

			/// Allows to reorder the enum fields of the DATADESCRIPTIONPROPS.
			/// The following options are available:
			/// "---" - add a seperator
			/// <<any id>> - add a specific id
			/// registry#<<name>> - fill in all members of an extension point
			/// # - fill in all other member not listed explicitly
			MAXON_ATTRIBUTE(maxon::BaseArray<maxon::Id>, ENUM, "net.maxon.description.ui.base.enum");

			/// Gives the portstate
			MAXON_ATTRIBUTE(maxon::Int, PORTSTATE, "net.maxon.description.ui.base.portstate",
				RESOURCE_DEFINE(ENUM_ISCONNECTED, 1)
				RESOURCE_DEFINE(ENUM_ISMUTED, 2)
				RESOURCE_DEFINE(ENUM_HASERROR, 4)
				RESOURCE_DEFINE(ENUM_HASWARNING, 8)
				RESOURCE_DEFINE(ENUM_HASLIMITATION, 16));

			/// True if strings of children of this attribute are optional and not 
			/// requiried to translate.
			MAXON_ATTRIBUTE(maxon::Bool, OPTIONALCHILDRENSTRINGS, "net.maxon.description.ui.base.optionalchildrenstrings");

			/// If the attribute is a "command" it's possible to specify the appearance of 
			/// the command as a button or menu
			MAXON_ATTRIBUTE(maxon::Id, COMMANDTYPE, "net.maxon.description.ui.base.commandtype",
				RESOURCE_DEFINE(ENUM_BUTTON, maxon::Id("button"))
				RESOURCE_DEFINE(ENUM_MENU, maxon::Id("menu")));

			/// Context for the command. 
			/// nodecore - command belongs to the NodesGraphInterface
			/// nimbuscore - command belongs to the NimbusInterface (includes nodecore)
			/// nodepresenter - command belongs to the NodePresenterInterface
			/// nodegraphwidget - command belongs to the NodeGraphWidgetInterface
			MAXON_ATTRIBUTE(maxon::Id, COMMANDCONTEXT, "net.maxon.description.ui.base.commandcontext",
				RESOURCE_DEFINE(ENUM_NODECORE, maxon::Id("nodecore"))
				RESOURCE_DEFINE(ENUM_NIMBUSCORE, maxon::Id("nimbuscore"))
				RESOURCE_DEFINE(ENUM_APPWIDGET, maxon::Id("appwidget")));

			/// Icon Id of the icon that should be used the id can be a qualified name of a registered icon or a c4d icon id as number.
			MAXON_ATTRIBUTE(maxon::Id, COMMANDICONID, "net.maxon.description.ui.base.commandiconid");

			/// True if the group should be open by default.
			MAXON_ATTRIBUTE(maxon::Bool, GROUPDEFAULTOPEN, "net.maxon.description.ui.base.groupdefaultopen");

			/// True if the ui (e.g. color/colora) should be open by default.
			MAXON_ATTRIBUTE(maxon::Bool, UIDEFAULTOPEN, "net.maxon.description.ui.base.uidefaultopen");

			/// True if the group should display the title bar.
			MAXON_ATTRIBUTE(maxon::Bool, GROUPTITLEBAR, "net.maxon.description.ui.base.grouptitlebar");

			/// Number of columns the group should support.
			MAXON_ATTRIBUTE(maxon::Int, GROUPCOLUMNS, "net.maxon.description.ui.base.groupcolumns");

			/// New id for legacy DESC_ANIMATE (and values DESC_ANIMATE_ON, DESC_ANIMATE_OFF)
			MAXON_ATTRIBUTE(maxon::Bool, ANIMATABLE, "net.maxon.description.ui.base.animatable");

			/// True if the attribute should be hidden when the object is displayed as inline object
			MAXON_ATTRIBUTE(maxon::Bool, HIDEWHENINLINE, "net.maxon.description.ui.base.hidewheninline");

			/// True if the string should be a multiline text.
			MAXON_ATTRIBUTE(maxon::Bool, MULTILINETITLE, "net.maxon.description.ui.base.multilinetitle");

			namespace ADDMINMAX
			{
				MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.ui.base.addminmax");

				/// True if the minvalue and maxvalue are valid.
				MAXON_ATTRIBUTE(maxon::Bool, LIMITVALUE, "net.maxon.description.ui.base.addminmax.limitvalue");

				/// min value for the ui.
				MAXON_ATTRIBUTE(maxon::Data, MINVALUE, "net.maxon.description.ui.base.addminmax.minvalue");

				/// max value for the ui.
				MAXON_ATTRIBUTE(maxon::Data, MAXVALUE, "net.maxon.description.ui.base.addminmax.maxvalue");

				/// step value for the ui.
				MAXON_ATTRIBUTE(maxon::Data, STEPVALUE, "net.maxon.description.ui.base.addminmax.stepvalue");
			}
		}

		namespace INFO
		{
			MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.ui.info");

			MAXON_ATTRIBUTE(maxon::Id, MENUCATEGORY, "net.maxon.description.ui.info.menucategory",
				RESOURCE_DEFINE(ENUM_ASSETTYPE_NET_MAXON_ASSETTYPE_CATEGORY, maxon::Id("assettype#net.maxon.assettype.category")));

			/// Defines the pattern for the default name
			/// Special ids: 
			/// assetid - the asset id of the node
			/// uniquenumber - the unique number of the node.
			/// {{any attribute}} - value of the attribute
			/// examples:
			/// {{assetid}}.{{uniquenumber}} -> Bitmap.1
			/// {{url}} || {{assetid}}.{{uniquenumber}} -> app.png if url is given, otherwise Bitmap.1
			MAXON_ATTRIBUTE(maxon::CString, DEFAULTNAME, "net.maxon.description.ui.info.defaultname");
		}

		namespace NET
		{
			namespace MAXON
			{
				namespace UI
				{
					namespace DATA
					{
						MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.ui.net.maxon.ui.data");

						// supports MAXON::DESCRIPTION::BASE::COMMAND
						// supports MAXON::DESCRIPTION::BASE::IDENTIFIER
						// supports MAXON::DESCRIPTION::UI::BASE::GUITYPEID
						// supports MAXON::DESCRIPTION::UI::BASE::ACCEPT
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPID
						// supports MAXON::DESCRIPTION::UI::BASE::SHOWGROUPINPORTLIST
						// supports MAXON::DESCRIPTION::UI::BASE::SHOW
						// supports MAXON::DESCRIPTION::UI::BASE::ENABLE
						// supports MAXON::DESCRIPTION::UI::BASE::PARENTFOLDERID
						// supports MAXON::DESCRIPTION::UI::BASE::PARENTFOLDERIDDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::PRESETDATABASEID
						// supports MAXON::DESCRIPTION::UI::BASE::PRESETMEMBERS
						// supports MAXON::DESCRIPTION::UI::BASE::ENUM
						// supports MAXON::DESCRIPTION::UI::BASE::PORTSTATE
						// supports MAXON::DESCRIPTION::UI::BASE::OPTIONALCHILDRENSTRINGS
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDTYPE
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDCONTEXT
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDICONID
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::UIDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPTITLEBAR
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPCOLUMNS
						// supports MAXON::DESCRIPTION::UI::BASE::HIDEWHENINLINE
						// supports MAXON::DESCRIPTION::UI::BASE::MULTILINETITLE
						// supports MAXON::DESCRIPTION::UI::BASE::ADDMINMAX::LIMITVALUE
						// supports MAXON::DESCRIPTION::UI::BASE::ADDMINMAX::MINVALUE
						// supports MAXON::DESCRIPTION::UI::BASE::ADDMINMAX::MAXVALUE
						// supports MAXON::DESCRIPTION::UI::BASE::ADDMINMAX::STEPVALUE
					}

					namespace NUMBER
					{
						MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.ui.net.maxon.ui.number");

						// supports MAXON::DESCRIPTION::BASE::COMMAND
						// supports MAXON::DESCRIPTION::BASE::IDENTIFIER
						// supports MAXON::DESCRIPTION::UI::BASE::GUITYPEID
						// supports MAXON::DESCRIPTION::UI::BASE::ACCEPT
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPID
						// supports MAXON::DESCRIPTION::UI::BASE::SHOWGROUPINPORTLIST
						// supports MAXON::DESCRIPTION::UI::BASE::SHOW
						// supports MAXON::DESCRIPTION::UI::BASE::ENABLE
						// supports MAXON::DESCRIPTION::UI::BASE::PARENTFOLDERID
						// supports MAXON::DESCRIPTION::UI::BASE::PARENTFOLDERIDDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::PRESETDATABASEID
						// supports MAXON::DESCRIPTION::UI::BASE::PRESETMEMBERS
						// supports MAXON::DESCRIPTION::UI::BASE::ENUM
						// supports MAXON::DESCRIPTION::UI::BASE::PORTSTATE
						// supports MAXON::DESCRIPTION::UI::BASE::OPTIONALCHILDRENSTRINGS
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDTYPE
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDCONTEXT
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDICONID
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::UIDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPTITLEBAR
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPCOLUMNS
						// supports MAXON::DESCRIPTION::UI::BASE::HIDEWHENINLINE
						// supports MAXON::DESCRIPTION::UI::BASE::MULTILINETITLE

						MAXON_ATTRIBUTE(maxon::Bool, SLIDER, "net.maxon.description.ui.net.maxon.ui.number.slider");

						// supports MAXON::DESCRIPTION::UI::BASE::ADDMINMAX::LIMITVALUE
						// supports MAXON::DESCRIPTION::UI::BASE::ADDMINMAX::MINVALUE
						// supports MAXON::DESCRIPTION::UI::BASE::ADDMINMAX::MAXVALUE
						// supports MAXON::DESCRIPTION::UI::BASE::ADDMINMAX::STEPVALUE
					}

					namespace STRING
					{
						MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.ui.net.maxon.ui.string");

						// supports MAXON::DESCRIPTION::BASE::COMMAND
						// supports MAXON::DESCRIPTION::BASE::IDENTIFIER
						// supports MAXON::DESCRIPTION::UI::BASE::GUITYPEID
						// supports MAXON::DESCRIPTION::UI::BASE::ACCEPT
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPID
						// supports MAXON::DESCRIPTION::UI::BASE::SHOWGROUPINPORTLIST
						// supports MAXON::DESCRIPTION::UI::BASE::SHOW
						// supports MAXON::DESCRIPTION::UI::BASE::ENABLE
						// supports MAXON::DESCRIPTION::UI::BASE::PARENTFOLDERID
						// supports MAXON::DESCRIPTION::UI::BASE::PARENTFOLDERIDDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::PRESETDATABASEID
						// supports MAXON::DESCRIPTION::UI::BASE::PRESETMEMBERS
						// supports MAXON::DESCRIPTION::UI::BASE::ENUM
						// supports MAXON::DESCRIPTION::UI::BASE::PORTSTATE
						// supports MAXON::DESCRIPTION::UI::BASE::OPTIONALCHILDRENSTRINGS
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDTYPE
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDCONTEXT
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDICONID
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::UIDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPTITLEBAR
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPCOLUMNS
						// supports MAXON::DESCRIPTION::UI::BASE::HIDEWHENINLINE
						// supports MAXON::DESCRIPTION::UI::BASE::MULTILINETITLE

						MAXON_ATTRIBUTE(maxon::Bool, MULTILINE, "net.maxon.description.ui.net.maxon.ui.string.multiline");

						MAXON_ATTRIBUTE(maxon::Bool, READONLY, "net.maxon.description.ui.net.maxon.ui.string.readonly");
					}

					namespace URL
					{
						MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.ui.net.maxon.ui.url");

						// supports MAXON::DESCRIPTION::BASE::COMMAND
						// supports MAXON::DESCRIPTION::BASE::IDENTIFIER
						// supports MAXON::DESCRIPTION::UI::BASE::GUITYPEID
						// supports MAXON::DESCRIPTION::UI::BASE::ACCEPT
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPID
						// supports MAXON::DESCRIPTION::UI::BASE::SHOWGROUPINPORTLIST
						// supports MAXON::DESCRIPTION::UI::BASE::SHOW
						// supports MAXON::DESCRIPTION::UI::BASE::ENABLE
						// supports MAXON::DESCRIPTION::UI::BASE::PARENTFOLDERID
						// supports MAXON::DESCRIPTION::UI::BASE::PARENTFOLDERIDDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::PRESETDATABASEID
						// supports MAXON::DESCRIPTION::UI::BASE::PRESETMEMBERS
						// supports MAXON::DESCRIPTION::UI::BASE::ENUM
						// supports MAXON::DESCRIPTION::UI::BASE::PORTSTATE
						// supports MAXON::DESCRIPTION::UI::BASE::OPTIONALCHILDRENSTRINGS
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDTYPE
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDCONTEXT
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDICONID
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::UIDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPTITLEBAR
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPCOLUMNS
						// supports MAXON::DESCRIPTION::UI::BASE::HIDEWHENINLINE
						// supports MAXON::DESCRIPTION::UI::BASE::MULTILINETITLE

						MAXON_ATTRIBUTE(maxon::Bool, SAVEMODE, "net.maxon.description.ui.net.maxon.ui.url.savemode");

						MAXON_ATTRIBUTE(maxon::Bool, TEXTUREHANDLING, "net.maxon.description.ui.net.maxon.ui.url.texturehandling");
					}

					namespace VARIADICPORT
					{
						MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.description.ui.net.maxon.ui.variadicport");

						// supports MAXON::DESCRIPTION::BASE::COMMAND
						// supports MAXON::DESCRIPTION::BASE::IDENTIFIER
						// supports MAXON::DESCRIPTION::UI::BASE::GUITYPEID
						// supports MAXON::DESCRIPTION::UI::BASE::ACCEPT
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPID
						// supports MAXON::DESCRIPTION::UI::BASE::SHOWGROUPINPORTLIST
						// supports MAXON::DESCRIPTION::UI::BASE::SHOW
						// supports MAXON::DESCRIPTION::UI::BASE::ENABLE
						// supports MAXON::DESCRIPTION::UI::BASE::PARENTFOLDERID
						// supports MAXON::DESCRIPTION::UI::BASE::PARENTFOLDERIDDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::PRESETDATABASEID
						// supports MAXON::DESCRIPTION::UI::BASE::PRESETMEMBERS
						// supports MAXON::DESCRIPTION::UI::BASE::ENUM
						// supports MAXON::DESCRIPTION::UI::BASE::PORTSTATE
						// supports MAXON::DESCRIPTION::UI::BASE::OPTIONALCHILDRENSTRINGS
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDTYPE
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDCONTEXT
						// supports MAXON::DESCRIPTION::UI::BASE::COMMANDICONID
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::UIDEFAULTOPEN
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPTITLEBAR
						// supports MAXON::DESCRIPTION::UI::BASE::GROUPCOLUMNS
						// supports MAXON::DESCRIPTION::UI::BASE::HIDEWHENINLINE
						// supports MAXON::DESCRIPTION::UI::BASE::MULTILINETITLE

						MAXON_ATTRIBUTE(maxon::Int32, COMPLEXCUSTOMUI, "net.maxon.description.ui.net.maxon.ui.variadicport.complexcustomui");
					}
				}
			}
		}
	}
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

namespace maxon
{

//----------------------------------------------------------------------------------------
/// Structure to store a menu definition.
//----------------------------------------------------------------------------------------
class SubMenuEntry
{
public:
	/// unique identifier to allow selections (e.g. in treeviews)
	Id _identifier;

	/// unique identifier to allow feature highilghting
	Id _identifierOriginal;

	/// name of the menu entry
	String _name;

	/// id of the icon
	Id _iconId;

	/// state flags of the menu entry see DESCRIPTIONMESSAGECHECKFLAGS.
	DESCRIPTIONMESSAGECHECKFLAGS _flags = DESCRIPTIONMESSAGECHECKFLAGS::VISIBLE | DESCRIPTIONMESSAGECHECKFLAGS::ENABLED | DESCRIPTIONMESSAGECHECKFLAGS::SORTSUBMENU;

	/// context to which the command belongs.
	Id _commandContext;

	/// function callback to call the function
	DescriptionMessageCall _function;

	/// optional sub menu entry. in that case _function must be nullptr.
	StrongRef<BaseArray<SubMenuEntry>> _subEntryRef;

	//----------------------------------------------------------------------------------------
	/// Compare function for menu sorting.
	/// @param[in] a									Entry 1.
	/// @param[in] b									Entry 2.
	/// @return												True if less than on success.
	//----------------------------------------------------------------------------------------
	static Bool LessThan(const SubMenuEntry& a, const SubMenuEntry& b)
	{
		return a._name.Compare(b._name, STRINGCOMPARISON::CASEINSENSITIVE_NUMBERS) == COMPARERESULT::LESS;
	}

	Result<void> CopyFrom(const SubMenuEntry& src)
	{
		iferr_scope;

		_identifier = src._identifier;
		_identifierOriginal = src._identifierOriginal;
		_name = src._name;
		_iconId = src._iconId;
		_flags = src._flags;
		_commandContext = src._commandContext;
		_function.CopyFrom(src._function) iferr_return;
		_subEntryRef = src._subEntryRef;

		return OK;
	}
};


//----------------------------------------------------------------------------------------
/// Tuple which stores the parameters (DataDictionary) of a function call and provides the GetDataCallbackType to evaluate conditions.
//----------------------------------------------------------------------------------------
using ContextVarTuple = Tuple<DataDictionary, GetDataCallbackType>;

//----------------------------------------------------------------------------------------
/// Hash map which stores ContextVarTuple for commands.
//----------------------------------------------------------------------------------------
using ContextVarsMap = HashMap<Id, ContextVarTuple>;

//----------------------------------------------------------------------------------------
/// This interface provides helper functions for ui stuff in combination with descriptions.
//----------------------------------------------------------------------------------------
class DataDescriptionUIInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(DataDescriptionUIInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.datadescriptionui");

public:

	//----------------------------------------------------------------------------------------
	/// Evaluates a condition for a given uiEntry
	/// @param[in] condition					Condition string to evaluate.
	/// @param[in] description				Description to use.
	/// @param[in] uiEntries					UI entries.
	/// @param[in] getDataCallback		Callback to get data for the evaluation.
	/// @param[in] externalVariables	External variables for the FormulaParser.
	/// @return												True if the condition matches. False if not.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description,
		const BaseArray<DataDictionary>& uiEntries, const GetDataCallbackType& getDataCallback,
		const HashMap<CString, CString>& externalVariables);

	//----------------------------------------------------------------------------------------
	/// BuildPopupMenuForDescription description.
	/// @param[in] description				Description to use.
	/// @param[in] externalVariables	External variables for the FormulaParser.
	/// @param[in] contextVars				HashMap with variables to execute and evaluate the menu checks for each context that should be used.
	/// @param[out] mainMenuEntries		Value Receiver which receives the created menu entries.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> BuildPopupMenuForDescription(const DataDescriptionWithUIAndString& description,
		const HashMap<CString, CString>& externalVariables, const ContextVarsMap& contextVars,
		const ValueReceiver<SubMenuEntry&&>& mainMenuEntries);
};


#include "datadescription_ui1.hxx"
#include "datadescription_ui2.hxx"

//----------------------------------------------------------------------------------------
/// Appending this string to any enum entry will skip/filter that element when scrolling through the elements using the keyboard or
/// mouse wheel.
//----------------------------------------------------------------------------------------
#define STRING_FILTERENUMCOMMAND "#cmd#"_s

}

#endif // DATADESCRIPTION_UI_H__
