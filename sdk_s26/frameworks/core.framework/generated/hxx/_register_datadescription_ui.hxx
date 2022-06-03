#if 1
namespace maxon
{
	namespace DESCRIPTION
	{
		namespace UI
		{
			namespace BASE
			{
				DEFAULTCLASSIFICATION_PrivateAttribute DEFAULTCLASSIFICATION;
				GUITYPEID_PrivateAttribute GUITYPEID;
				BASELINK_ACCEPT_PrivateAttribute BASELINK_ACCEPT;
				GROUPID_PrivateAttribute GROUPID;
				SHOWGROUPINPORTLIST_PrivateAttribute SHOWGROUPINPORTLIST;
				SHOW_PrivateAttribute SHOW;
				ENABLE_PrivateAttribute ENABLE;
				PARENTFOLDERID_PrivateAttribute PARENTFOLDERID;
				PARENTFOLDERIDDEFAULTOPEN_PrivateAttribute PARENTFOLDERIDDEFAULTOPEN;
				PRESETDATABASEID_PrivateAttribute PRESETDATABASEID;
				PRESETMEMBERS_PrivateAttribute PRESETMEMBERS;
				ENUM_PrivateAttribute ENUM;
				ENUMSORTMODE_PrivateAttribute ENUMSORTMODE;
				PORTSTATE_PrivateAttribute PORTSTATE;
				OPTIONALCHILDRENSTRINGS_PrivateAttribute OPTIONALCHILDRENSTRINGS;
				COMMANDTYPE_PrivateAttribute COMMANDTYPE;
				COMMANDCONTEXT_PrivateAttribute COMMANDCONTEXT;
				COMMANDICONID_PrivateAttribute COMMANDICONID;
				COMMANDSHORTCUTID_PrivateAttribute COMMANDSHORTCUTID;
				GROUPDEFAULTOPEN_PrivateAttribute GROUPDEFAULTOPEN;
				UIDEFAULTOPEN_PrivateAttribute UIDEFAULTOPEN;
				GROUPTITLEBAR_PrivateAttribute GROUPTITLEBAR;
				GROUPCOLUMNS_PrivateAttribute GROUPCOLUMNS;
				SCALEV_PrivateAttribute SCALEV;
				SCALEH_PrivateAttribute SCALEH;
				ANIMATABLE_PrivateAttribute ANIMATABLE;
				HIDEWHENINLINE_PrivateAttribute HIDEWHENINLINE;
				MULTILINETITLE_PrivateAttribute MULTILINETITLE;
				namespace ADDMINMAX
				{
					LIMITVALUE_PrivateAttribute LIMITVALUE;
					MINVALUE_PrivateAttribute MINVALUE;
					MAXVALUE_PrivateAttribute MAXVALUE;
					STEPVALUE_PrivateAttribute STEPVALUE;
				}
			}
			namespace INFO
			{
				MENUCATEGORY_PrivateAttribute MENUCATEGORY;
				DEFAULTNAME_PrivateAttribute DEFAULTNAME;
			}
			namespace NET
			{
				namespace MAXON
				{
					namespace UI
					{
						namespace NUMBER
						{
							SLIDER_PrivateAttribute SLIDER;
						}
						namespace STRING
						{
							READONLY_PrivateAttribute READONLY;
							MULTILINE_PrivateAttribute MULTILINE;
							PYTHON_PrivateAttribute PYTHON;
							SYNTAXCOLOR_PrivateAttribute SYNTAXCOLOR;
							STATUSBAR_PrivateAttribute STATUSBAR;
							WORDWRAP_PrivateAttribute WORDWRAP;
							MONOSPACED_PrivateAttribute MONOSPACED;
							BOLD_PrivateAttribute BOLD;
							BORDER_PrivateAttribute BORDER;
							HIGHLIGHTLINE_PrivateAttribute HIGHLIGHTLINE;
							SCROLLBARS_PrivateAttribute SCROLLBARS;
							DARKBACKGROUND_PrivateAttribute DARKBACKGROUND;
							DROPTEXTQUOTED_PrivateAttribute DROPTEXTQUOTED;
							LINECOUNT_PrivateAttribute LINECOUNT;
							MULTILINE_GROUP_PrivateAttribute MULTILINE_GROUP;
						}
						namespace URL
						{
							TEXTUREHANDLING_PrivateAttribute TEXTUREHANDLING;
						}
						namespace VARIADICPORT
						{
							COMPLEXCUSTOMUI_PrivateAttribute COMPLEXCUSTOMUI;
						}
					}
				}
			}
		}
	}
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DataDescriptionUIInterface::Hxx2::Unresolved : public DataDescriptionUIInterface
	{
	public:
		static Result<Bool> EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const BaseArray<DataDictionary>& uiEntries, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return DataDescriptionUIInterface::EvaluateCondition(condition, description, uiEntries, getDataCallback, externalVariables); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> BuildPopupMenuForDescription(const DataDescriptionWithUIAndString& description, const HashMap<CString, CString>& externalVariables, const ContextVarsMap& contextVars, const ValueReceiver<SubMenuEntry&&>& mainMenuEntries) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return DataDescriptionUIInterface::BuildPopupMenuForDescription(description, externalVariables, contextVars, mainMenuEntries); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Bool> EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return DataDescriptionUIInterface::EvaluateCondition(condition, description, getDescCallback, getDataCallback, externalVariables); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE DataDescriptionUIInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DataDescriptionUIInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionUIInterface_EvaluateCondition = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionUIInterface_EvaluateCondition;
		#else
		tbl->DataDescriptionUIInterface_EvaluateCondition = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionUIInterface_EvaluateCondition;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionUIInterface_BuildPopupMenuForDescription = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionUIInterface_BuildPopupMenuForDescription;
		#else
		tbl->DataDescriptionUIInterface_BuildPopupMenuForDescription = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionUIInterface_BuildPopupMenuForDescription;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DataDescriptionUIInterface_EvaluateCondition_1 = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionUIInterface_EvaluateCondition_1;
		#else
		tbl->DataDescriptionUIInterface_EvaluateCondition_1 = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DataDescriptionUIInterface_EvaluateCondition_1;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const DataDescriptionUIInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS DataDescriptionUIInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(DataDescriptionUIInterface, , "net.maxon.interface.datadescriptionui", "maxon.DataDescriptionUIInterface", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const DataDescriptionUIInterface::Hxx2::StaticMTable::_ids = 
		"EvaluateCondition@9f5d840e0975ea9e\0" // Result<Bool> EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const BaseArray<DataDictionary>& uiEntries, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables)
		"BuildPopupMenuForDescription@72503cbb3e02ee4c\0" // Result<void> BuildPopupMenuForDescription(const DataDescriptionWithUIAndString& description, const HashMap<CString, CString>& externalVariables, const ContextVarsMap& contextVars, const ValueReceiver<SubMenuEntry&&>& mainMenuEntries)
		"EvaluateCondition@b5d3423ab395bfb6\0" // Result<Bool> EvaluateCondition(const CString& condition, const DataDescriptionWithUIAndString& description, const GetDescEntriesCallbackType& getDescCallback, const GetDataCallbackType& getDataCallback, const HashMap<CString, CString>& externalVariables)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(DataDescriptionUIInterface, , "net.maxon.interface.datadescriptionui");
}
#endif
