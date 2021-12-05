
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
namespace MEDIASESSION
{
	namespace EXPORT
	{
		namespace BASE
		{
		}
	}
}

struct MediaBaseInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ConnectToSession);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSession);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_MediaBaseInterface_ConnectToSession) (maxon::GenericComponent* this_, const MediaSessionRef& session);
	maxon::Int _MediaBaseInterface_ConnectToSession_Offset;
	MediaSessionRef (*_MediaBaseInterface_GetSession) (const maxon::GenericComponent* this_);
	maxon::Int _MediaBaseInterface_GetSession_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaBaseInterface, ConnectToSession))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaBaseInterface, ConnectToSession), W, MTable>::type::_MediaBaseInterface_ConnectToSession;
		_MediaBaseInterface_ConnectToSession = reinterpret_cast<const decltype(_MediaBaseInterface_ConnectToSession)&>(ptr);
		_MediaBaseInterface_ConnectToSession_Offset = offset;
	}
	if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaBaseInterface, GetSession))
	{
		auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaBaseInterface, GetSession), W, MTable>::type::_MediaBaseInterface_GetSession;
		_MediaBaseInterface_GetSession = reinterpret_cast<const decltype(_MediaBaseInterface_GetSession)&>(ptr);
		_MediaBaseInterface_GetSession_Offset = offset;
	}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset) || !DataDescriptionObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset);
		return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaBaseInterface, typename DataDescriptionObjectInterface::MTable::template CombinedMTable<typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaBaseInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaBaseInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDescriptionObjectInterface::Hxx2::template CWrapper<typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConnectToSession);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSession);
		static Result<void> _MediaBaseInterface_ConnectToSession(maxon::GenericComponent* this_, const MediaSessionRef& session) { return ((typename S::Implementation*) this_)->ConnectToSession(session); }
		static MediaSessionRef _MediaBaseInterface_GetSession(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetSession(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaBaseInterface::ConnectToSession(const MediaSessionRef& session) -> Result<void>
{
	const MediaBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaBaseInterface, this); return mt_._MediaBaseInterface_ConnectToSession((maxon::GenericComponent*) this + mt_._MediaBaseInterface_ConnectToSession_Offset, session);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaBaseInterface::GetSession() const -> MediaSessionRef
{
	const MediaBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaBaseInterface, this); return mt_._MediaBaseInterface_GetSession((const maxon::GenericComponent*) this + mt_._MediaBaseInterface_GetSession_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaBaseInterface::Hxx1::ReferenceFunctionsImpl<S>::ConnectToSession(const MediaSessionRef& session) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaBaseInterface* o_ = (MediaBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaBaseInterface, o_, MediaBaseInterface_ConnectToSession) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaBaseInterface>() : PRIVATE_MAXON_VTABLE(MediaBaseInterface, o_); 
	return (mt_._MediaBaseInterface_ConnectToSession(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaBaseInterface_ConnectToSession_Offset, session));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaBaseInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConnectToSession(const MediaSessionRef& session) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaBaseInterface* o_ = (MediaBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaBaseInterface, o_, MediaBaseInterface_ConnectToSession) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaBaseInterface>() : PRIVATE_MAXON_VTABLE(MediaBaseInterface, o_); 
	return (mt_._MediaBaseInterface_ConnectToSession(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaBaseInterface_ConnectToSession_Offset, session));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaBaseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSession() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<MediaSessionRef>, MediaSessionRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<MediaSessionRef>, MediaSessionRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaBaseInterface* o_ = (const MediaBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<MediaSessionRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaBaseInterface, o_, MediaBaseInterface_GetSession) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaBaseInterface>() : PRIVATE_MAXON_VTABLE(MediaBaseInterface, o_); 
	return (mt_._MediaBaseInterface_GetSession(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MediaBaseInterface_GetSession_Offset));
}
auto MediaBaseInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaBaseInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaBaseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaBaseInterface() { new (s_ui_maxon_MediaBaseInterface) maxon::EntityUse(MediaBaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_base.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaBaseInterface(MediaBaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_base.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

