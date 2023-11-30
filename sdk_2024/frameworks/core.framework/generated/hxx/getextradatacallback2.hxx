
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
#ifdef __API_INTERN__
#endif

struct GetExtraDataCallbackInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetExtraDataMessage);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(GetExtraDataCallbackInterface_GetExtraDataMessage, GetExtraDataMessage, true, maxon::GenericComponent,, (Result<DelegateBase>), const Id& cmdId);
	maxon::Int GetExtraDataCallbackInterface_GetExtraDataMessage_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, GetExtraDataCallbackInterface, GetExtraDataMessage))
	{
		maxon::Tie(GetExtraDataCallbackInterface_GetExtraDataMessage, GetExtraDataCallbackInterface_GetExtraDataMessage_Offset) = GetExtraDataCallbackInterface_GetExtraDataMessage_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<GetExtraDataCallbackInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<GetExtraDataCallbackInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct GetExtraDataCallbackInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetExtraDataMessage);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (GetExtraDataCallbackInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, GetExtraDataCallbackInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(GetExtraDataCallbackInterface_GetExtraDataMessage, maxon::GenericComponent,, (Result<DelegateBase>), const Id& cmdId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetExtraDataMessage(cmdId); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto GetExtraDataCallbackInterface::GetExtraDataMessage(const Id& cmdId) -> Result<DelegateBase>
{
	const GetExtraDataCallbackInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(GetExtraDataCallbackInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.GetExtraDataCallbackInterface_GetExtraDataMessage_Offset), mt_.GetExtraDataCallbackInterface_GetExtraDataMessage, cmdId);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GetExtraDataCallbackInterface::Hxx1::Fn<S>::GetExtraDataMessage(const Id& cmdId) const -> Result<DelegateBase>
{
	HXXRETURN0(Result<DelegateBase>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(GetExtraDataCallbackInterface_GetExtraDataMessage); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.GetExtraDataCallbackInterface_GetExtraDataMessage_Offset), mt_.GetExtraDataCallbackInterface_GetExtraDataMessage, cmdId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto GetExtraDataCallbackInterface::Hxx1::COWFn<S>::GetExtraDataMessage(const Id& cmdId) -> Result<DelegateBase>
{
	HXXRETURN0(Result<DelegateBase>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(GetExtraDataCallbackInterface_GetExtraDataMessage); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.GetExtraDataCallbackInterface_GetExtraDataMessage_Offset), mt_.GetExtraDataCallbackInterface_GetExtraDataMessage, cmdId));
}
auto GetExtraDataCallbackInterface::GetPtr() -> Ptr { return Ptr(this); }
auto GetExtraDataCallbackInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_getextradatacallback)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_GetExtraDataCallbackInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_GetExtraDataCallbackInterface() { new (s_ui_maxon_GetExtraDataCallbackInterface) maxon::EntityUse(GetExtraDataCallbackInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/getextradatacallback.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_GetExtraDataCallbackInterface(GetExtraDataCallbackInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/getextradatacallback.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#ifdef __API_INTERN__
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

