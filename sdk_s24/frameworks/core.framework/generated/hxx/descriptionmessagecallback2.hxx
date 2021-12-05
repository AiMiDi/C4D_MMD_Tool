
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
	Result<Tuple<Bool, Bool>> (*_DescriptionMessageCallbackInterface_DescriptionMessage) (maxon::GenericComponent* this_, const InternedId& id, const Id& cmdId, Int32 type, void* data);
	maxon::Int _DescriptionMessageCallbackInterface_DescriptionMessage_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DescriptionMessageCallbackInterface, DescriptionMessage))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, DescriptionMessageCallbackInterface, DescriptionMessage), W, MTable>::type::_DescriptionMessageCallbackInterface_DescriptionMessage;
		_DescriptionMessageCallbackInterface_DescriptionMessage = reinterpret_cast<const decltype(_DescriptionMessageCallbackInterface_DescriptionMessage)&>(ptr);
		_DescriptionMessageCallbackInterface_DescriptionMessage_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DescriptionMessageCallbackInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DescriptionMessageCallbackInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DescriptionMessageCallbackInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(DescriptionMessage);
		static Result<Tuple<Bool, Bool>> _DescriptionMessageCallbackInterface_DescriptionMessage(maxon::GenericComponent* this_, const InternedId& id, const Id& cmdId, Int32 type, void* data) { return ((typename S::Implementation*) this_)->DescriptionMessage(id, cmdId, type, data); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto DescriptionMessageCallbackInterface::DescriptionMessage(const InternedId& id, const Id& cmdId, Int32 type, void* data) -> Result<Tuple<Bool, Bool>>
{
	const DescriptionMessageCallbackInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(DescriptionMessageCallbackInterface, this); return mt_._DescriptionMessageCallbackInterface_DescriptionMessage((maxon::GenericComponent*) this + mt_._DescriptionMessageCallbackInterface_DescriptionMessage_Offset, id, cmdId, type, data);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DescriptionMessageCallbackInterface::Hxx1::ReferenceFunctionsImpl<S>::DescriptionMessage(const InternedId& id, const Id& cmdId, Int32 type, void* data) const -> Result<Tuple<Bool, Bool>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Tuple<Bool, Bool>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DescriptionMessageCallbackInterface* o_ = (DescriptionMessageCallbackInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DescriptionMessageCallbackInterface, o_, DescriptionMessageCallbackInterface_DescriptionMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DescriptionMessageCallbackInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DescriptionMessageCallbackInterface>() : PRIVATE_MAXON_VTABLE(DescriptionMessageCallbackInterface, o_); 
	return (mt_._DescriptionMessageCallbackInterface_DescriptionMessage(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DescriptionMessageCallbackInterface_DescriptionMessage_Offset, id, cmdId, type, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto DescriptionMessageCallbackInterface::Hxx1::COWReferenceFunctionsImpl<S>::DescriptionMessage(const InternedId& id, const Id& cmdId, Int32 type, void* data) -> Result<Tuple<Bool, Bool>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Tuple<Bool, Bool>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); DescriptionMessageCallbackInterface* o_ = (DescriptionMessageCallbackInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(DescriptionMessageCallbackInterface, o_, DescriptionMessageCallbackInterface_DescriptionMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<DescriptionMessageCallbackInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<DescriptionMessageCallbackInterface>() : PRIVATE_MAXON_VTABLE(DescriptionMessageCallbackInterface, o_); 
	return (mt_._DescriptionMessageCallbackInterface_DescriptionMessage(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DescriptionMessageCallbackInterface_DescriptionMessage_Offset, id, cmdId, type, data));
}
auto DescriptionMessageCallbackInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DescriptionMessageCallbackInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

