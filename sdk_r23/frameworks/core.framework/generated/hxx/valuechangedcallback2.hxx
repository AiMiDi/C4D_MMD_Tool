
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

struct ValueChangedCallbackInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ValueChangedMessage);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_ValueChangedCallbackInterface_ValueChangedMessage) (maxon::GenericComponent* this_, const InternedId& id);
	maxon::Int _ValueChangedCallbackInterface_ValueChangedMessage_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ValueChangedCallbackInterface, ValueChangedMessage))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, ValueChangedCallbackInterface, ValueChangedMessage), W, MTable>::type::_ValueChangedCallbackInterface_ValueChangedMessage;
			_ValueChangedCallbackInterface_ValueChangedMessage = reinterpret_cast<const decltype(_ValueChangedCallbackInterface_ValueChangedMessage)&>(ptr);
			_ValueChangedCallbackInterface_ValueChangedMessage_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ValueChangedCallbackInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ValueChangedCallbackInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ValueChangedCallbackInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ValueChangedMessage);
		static Result<void> _ValueChangedCallbackInterface_ValueChangedMessage(maxon::GenericComponent* this_, const InternedId& id) { return ((typename S::Implementation*) this_)->ValueChangedMessage(id); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ValueChangedCallbackInterface::ValueChangedMessage(const InternedId& id) -> Result<void>
{
	const ValueChangedCallbackInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(ValueChangedCallbackInterface, this); return mt_._ValueChangedCallbackInterface_ValueChangedMessage((maxon::GenericComponent*) this + mt_._ValueChangedCallbackInterface_ValueChangedMessage_Offset, id);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ValueChangedCallbackInterface::Hxx1::ReferenceFunctionsImpl<S>::ValueChangedMessage(const InternedId& id) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ValueChangedCallbackInterface* o_ = (ValueChangedCallbackInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ValueChangedCallbackInterface, o_, ValueChangedCallbackInterface_ValueChangedMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ValueChangedCallbackInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ValueChangedCallbackInterface>() : PRIVATE_MAXON_VTABLE(ValueChangedCallbackInterface, o_); 
	return (mt_._ValueChangedCallbackInterface_ValueChangedMessage(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ValueChangedCallbackInterface_ValueChangedMessage_Offset, id));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ValueChangedCallbackInterface::Hxx1::COWReferenceFunctionsImpl<S>::ValueChangedMessage(const InternedId& id) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ValueChangedCallbackInterface* o_ = (ValueChangedCallbackInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(ValueChangedCallbackInterface, o_, ValueChangedCallbackInterface_ValueChangedMessage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<ValueChangedCallbackInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<ValueChangedCallbackInterface>() : PRIVATE_MAXON_VTABLE(ValueChangedCallbackInterface, o_); 
	return (mt_._ValueChangedCallbackInterface_ValueChangedMessage(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ValueChangedCallbackInterface_ValueChangedMessage_Offset, id));
}
auto ValueChangedCallbackInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ValueChangedCallbackInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ValueChangedCallbackInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ValueChangedCallbackInterface() { new (s_ui_maxon_ValueChangedCallbackInterface) maxon::EntityUse(ValueChangedCallbackInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/valuechangedcallback.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ValueChangedCallbackInterface(ValueChangedCallbackInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/valuechangedcallback.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#ifdef __API_INTERN__
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

