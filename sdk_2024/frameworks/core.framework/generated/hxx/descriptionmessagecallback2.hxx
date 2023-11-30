
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

struct DescriptionMessageCallbackInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(DescriptionMessage);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(DescriptionMessageCallbackInterface_DescriptionMessage, DescriptionMessage, true, maxon::GenericComponent,, (Result<Tuple<Bool, Bool>>), const InternedId& id, const Id& cmdId, Int32 type, void* data);
	maxon::Int DescriptionMessageCallbackInterface_DescriptionMessage_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DescriptionMessageCallbackInterface, DescriptionMessage))
	{
		maxon::Tie(DescriptionMessageCallbackInterface_DescriptionMessage, DescriptionMessageCallbackInterface_DescriptionMessage_Offset) = DescriptionMessageCallbackInterface_DescriptionMessage_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<DescriptionMessageCallbackInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DescriptionMessageCallbackInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DescriptionMessageCallbackInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(DescriptionMessage);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DescriptionMessageCallbackInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DescriptionMessageCallbackInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(DescriptionMessageCallbackInterface_DescriptionMessage, maxon::GenericComponent,, (Result<Tuple<Bool, Bool>>), const InternedId& id, const Id& cmdId, Int32 type, void* data) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->DescriptionMessage(id, cmdId, type, data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DescriptionMessageCallbackInterface::DescriptionMessage(const InternedId& id, const Id& cmdId, Int32 type, void* data) -> Result<Tuple<Bool, Bool>>
{
	const DescriptionMessageCallbackInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DescriptionMessageCallbackInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.DescriptionMessageCallbackInterface_DescriptionMessage_Offset), mt_.DescriptionMessageCallbackInterface_DescriptionMessage, id, cmdId, type, data);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DescriptionMessageCallbackInterface::Hxx1::Fn<S>::DescriptionMessage(const InternedId& id, const Id& cmdId, Int32 type, void* data) const -> Result<Tuple<Bool, Bool>>
{
	HXXRETURN0(Result<Tuple<Bool, Bool>>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(DescriptionMessageCallbackInterface_DescriptionMessage); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DescriptionMessageCallbackInterface_DescriptionMessage_Offset), mt_.DescriptionMessageCallbackInterface_DescriptionMessage, id, cmdId, type, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DescriptionMessageCallbackInterface::Hxx1::COWFn<S>::DescriptionMessage(const InternedId& id, const Id& cmdId, Int32 type, void* data) -> Result<Tuple<Bool, Bool>>
{
	HXXRETURN0(Result<Tuple<Bool, Bool>>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(DescriptionMessageCallbackInterface_DescriptionMessage); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DescriptionMessageCallbackInterface_DescriptionMessage_Offset), mt_.DescriptionMessageCallbackInterface_DescriptionMessage, id, cmdId, type, data));
}
auto DescriptionMessageCallbackInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DescriptionMessageCallbackInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_descriptionmessagecallback)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DescriptionMessageCallbackInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DescriptionMessageCallbackInterface() { new (s_ui_maxon_DescriptionMessageCallbackInterface) maxon::EntityUse(DescriptionMessageCallbackInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/descriptionmessagecallback.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DescriptionMessageCallbackInterface(DescriptionMessageCallbackInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/descriptionmessagecallback.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#ifdef __API_INTERN__
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

