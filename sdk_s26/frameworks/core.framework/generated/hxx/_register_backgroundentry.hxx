#if 1
namespace maxon
{
	namespace enum34
	{
		enum class STATE
			{
				NONE = 0,
				SUCCEEDED = 1 << 0, ///< Background Task succeeded
				CANCELED = 1 << 1,	///< Background Task was canceled
				WARNING = 1 << 2,		///< Background Task has warnings
				ERROR = 1 << 3,			///< Background Task has errors
			} ;
		static const maxon::UInt64 STATE_values[] = {maxon::UInt64(enum34::STATE::NONE), maxon::UInt64(enum34::STATE::SUCCEEDED), maxon::UInt64(enum34::STATE::CANCELED), maxon::UInt64(enum34::STATE::WARNING), maxon::UInt64(enum34::STATE::ERROR)};
		static const maxon::EnumInfo STATE_info{"BackgroundEntryInterface::STATE", SIZEOF(STATE), true, "NONE\0SUCCEEDED\0CANCELED\0WARNING\0ERROR\0", STATE_values, std::extent<decltype(STATE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_STATE34(void*){ return enum34::STATE_info; }
	const maxon::Char* const BackgroundEntryInterface::MTable::_ids = 
		"GetName@b8f12dfa16054f01\0" // String GetName() const
		"GetStartTime@4bef8e8cd77e9942\0" // UniversalDateTime GetStartTime() const
		"GetDuration@9a3c0bd9da107c0\0" // TimeValue GetDuration() const
		"GetState@15d52c1481dd9ef\0" // STATE GetState()
		"GetStates@3b6a308b4c7bdb9b\0" // Result<Bool> GetStates(const ValueReceiver<STATE, const String&>& state) const
		"GetStateCount@7d0e6f3d29c239e7\0" // Int GetStateCount() const
		"AddState@ca340d87b1a0f6b4\0" // Result<void> AddState(STATE state, const String& message)
	"";
	const maxon::METHOD_FLAGS BackgroundEntryInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(BackgroundEntryInterface, , "net.maxon.interface.backgroundentry", "maxon.BackgroundEntryInterface", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int BackgroundEntryInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<STATE>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<TimeValue>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<UniversalDateTime>(OVERLOAD_MAX_RANK)
		;
	}
	namespace enum93
	{
		enum class STATECHANGE
			{
				ACTIVE_ADDED,						 ///< an active entry was added
				ACTIVE_REMOVED,					 ///< an active entry was removed
				HISTORY_ADDED,					 ///< a history entry was added
				HISTORY_REMOVED,				 ///< a history entry was removed
				CANCELDELEGATE_CHANGED,  ///< cancel delegate changed
			} ;
		static const maxon::UInt64 STATECHANGE_values[] = {maxon::UInt64(enum93::STATECHANGE::ACTIVE_ADDED), maxon::UInt64(enum93::STATECHANGE::ACTIVE_REMOVED), maxon::UInt64(enum93::STATECHANGE::HISTORY_ADDED), maxon::UInt64(enum93::STATECHANGE::HISTORY_REMOVED), maxon::UInt64(enum93::STATECHANGE::CANCELDELEGATE_CHANGED)};
		static const maxon::EnumInfo STATECHANGE_info{"BackgroundProgressInterface::STATECHANGE", SIZEOF(STATECHANGE), false, "ACTIVE_ADDED\0ACTIVE_REMOVED\0HISTORY_ADDED\0HISTORY_REMOVED\0CANCELDELEGATE_CHANGED\0", STATECHANGE_values, std::extent<decltype(STATECHANGE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_STATECHANGE93(void*){ return enum93::STATECHANGE_info; }
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class BackgroundProgressInterface::Hxx2::Unresolved : public BackgroundProgressInterface
	{
	public:
		static BackgroundProgressRef GetMaster() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, true)) return BackgroundProgressInterface::GetMaster(); return maxon::PrivateIncompleteNullReturnValue<BackgroundProgressRef>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE BackgroundProgressInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<BackgroundProgressRef>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool BackgroundProgressInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<BackgroundProgressRef>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->BackgroundProgressInterface_GetMaster = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::BackgroundProgressInterface_GetMaster;
		#else
		tbl->BackgroundProgressInterface_GetMaster = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::BackgroundProgressInterface_GetMaster;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const BackgroundProgressInterface::MTable::_ids = 
		"AddActiveEntry@21730e8071584eb9\0" // Result<BackgroundProgressRef> AddActiveEntry(const String& title, Bool sendToHistory)
		"RemoveActiveEntry@b9d914976e8c1ab6\0" // Result<void> RemoveActiveEntry(const BackgroundProgressRef& entry)
		"GetActiveEntries@7cf76a6ebecc20ed\0" // Result<Bool> GetActiveEntries(const ValueReceiver<const BackgroundProgressRef&>& entry) const
		"GetActiveCount@7d0e6f3d29c239e7\0" // Int GetActiveCount() const
		"GetHistoryEntries@b4dfea9195e3bde6\0" // Result<Bool> GetHistoryEntries(const ValueReceiver<const BackgroundEntryRef&>& entry) const
		"GetHistoryCount@7d0e6f3d29c239e7\0" // Int GetHistoryCount() const
		"RemoveHistoryEntry@54ddfa57233fdd05\0" // Result<void> RemoveHistoryEntry(const BackgroundEntryRef& entry)
		"ClearHistory@3008090429c5a175\0" // Result<void> ClearHistory()
		"ObservableStateChanged@aa7fbcb7b68d3522\0" // maxon::ObservableRef<ObservableStateChangedDelegate> ObservableStateChanged() const
		"ObservableTotalProgressNotification@7ab48ff722633ce3\0" // maxon::ObservableRef<ObservableTotalProgressNotificationDelegate> ObservableTotalProgressNotification() const
	"";
	const maxon::METHOD_FLAGS BackgroundProgressInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL(BackgroundProgressInterface, BackgroundProgressInterface, , , "net.maxon.interface.backgroundprogress", "maxon.BackgroundProgressInterface", (ProgressInterface::PrivateGetInterface()), (BackgroundEntryInterface::PrivateGetInterface()), nullptr);
	const maxon::Char* const BackgroundProgressInterface::Hxx2::StaticMTable::_ids = 
		"GetMaster@8b9a6670123148d5\0" // BackgroundProgressRef GetMaster()
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(BackgroundProgressInterface, , "net.maxon.interface.backgroundprogress");
	template <typename DUMMY> maxon::Int BackgroundProgressInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<BackgroundProgressRef>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_BackgroundEntryTuple,, "net.maxon.datatyoe.backgroundentrytuple");
	namespace URLFLAGS
	{
		BACKGROUNDJOB_PrivateAttribute BACKGROUNDJOB;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_backgroundentry(0
	| maxon::BackgroundEntryInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::BackgroundProgressInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
