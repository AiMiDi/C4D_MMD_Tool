
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct MediaStreamAudioDataExportInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FinishStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetAudioObject);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitWithAudioData);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetCallbackHandler);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_MediaStreamAudioDataExportInterface_InitWithAudioData) (maxon::GenericComponent* this_, const AudioObjectRef& audioData);
	maxon::Int _MediaStreamAudioDataExportInterface_InitWithAudioData_Offset;
	AudioObjectRef (*_MediaStreamAudioDataExportInterface_GetAudioObject) (const maxon::GenericComponent* this_);
	maxon::Int _MediaStreamAudioDataExportInterface_GetAudioObject_Offset;
	Result<void> (*_MediaStreamAudioDataExportInterface_SetCallbackHandler) (maxon::GenericComponent* this_);
	maxon::Int _MediaStreamAudioDataExportInterface_SetCallbackHandler_Offset;
	Result<void> (*_MediaStreamAudioDataExportInterface_InitStream) (maxon::GenericComponent* this_, MediaStreamProperties& props);
	maxon::Int _MediaStreamAudioDataExportInterface_InitStream_Offset;
	Result<void> (*_MediaStreamAudioDataExportInterface_FinishStream) (maxon::GenericComponent* this_, const MediaStreamProperties& props);
	maxon::Int _MediaStreamAudioDataExportInterface_FinishStream_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, InitWithAudioData))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, InitWithAudioData), W, MTable>::type::_MediaStreamAudioDataExportInterface_InitWithAudioData;
			_MediaStreamAudioDataExportInterface_InitWithAudioData = reinterpret_cast<const decltype(_MediaStreamAudioDataExportInterface_InitWithAudioData)&>(ptr);
			_MediaStreamAudioDataExportInterface_InitWithAudioData_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, GetAudioObject))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, GetAudioObject), W, MTable>::type::_MediaStreamAudioDataExportInterface_GetAudioObject;
			_MediaStreamAudioDataExportInterface_GetAudioObject = reinterpret_cast<const decltype(_MediaStreamAudioDataExportInterface_GetAudioObject)&>(ptr);
			_MediaStreamAudioDataExportInterface_GetAudioObject_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, SetCallbackHandler))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, SetCallbackHandler), W, MTable>::type::_MediaStreamAudioDataExportInterface_SetCallbackHandler;
			_MediaStreamAudioDataExportInterface_SetCallbackHandler = reinterpret_cast<const decltype(_MediaStreamAudioDataExportInterface_SetCallbackHandler)&>(ptr);
			_MediaStreamAudioDataExportInterface_SetCallbackHandler_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, InitStream))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, InitStream), W, MTable>::type::_MediaStreamAudioDataExportInterface_InitStream;
			_MediaStreamAudioDataExportInterface_InitStream = reinterpret_cast<const decltype(_MediaStreamAudioDataExportInterface_InitStream)&>(ptr);
			_MediaStreamAudioDataExportInterface_InitStream_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, FinishStream))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, FinishStream), W, MTable>::type::_MediaStreamAudioDataExportInterface_FinishStream;
			_MediaStreamAudioDataExportInterface_FinishStream = reinterpret_cast<const decltype(_MediaStreamAudioDataExportInterface_FinishStream)&>(ptr);
			_MediaStreamAudioDataExportInterface_FinishStream_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!MediaStreamInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaStreamAudioDataExportInterface, typename MediaStreamInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(MediaStreamAudioDataExportInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaStreamAudioDataExportInterface::Hxx2
{
	template <typename S> class Wrapper : public MediaStreamInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FinishStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetAudioObject);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitWithAudioData);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetCallbackHandler);
	static Result<void> _MediaStreamAudioDataExportInterface_InitWithAudioData(maxon::GenericComponent* this_, const AudioObjectRef& audioData) { return ((typename S::Implementation*) this_)->InitWithAudioData(audioData); }
	static AudioObjectRef _MediaStreamAudioDataExportInterface_GetAudioObject(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetAudioObject(); }
	static Result<void> _MediaStreamAudioDataExportInterface_SetCallbackHandler(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->SetCallbackHandler(); }
	static Result<void> _MediaStreamAudioDataExportInterface_InitStream(maxon::GenericComponent* this_, MediaStreamProperties& props) { return ((typename S::Implementation*) this_)->InitStream(props); }
	static Result<void> _MediaStreamAudioDataExportInterface_FinishStream(maxon::GenericComponent* this_, const MediaStreamProperties& props) { return ((typename S::Implementation*) this_)->FinishStream(props); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::InitWithAudioData(const AudioObjectRef& audioData) -> Result<void>
{
	const MediaStreamAudioDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, this); return mt_._MediaStreamAudioDataExportInterface_InitWithAudioData((maxon::GenericComponent*) this + mt_._MediaStreamAudioDataExportInterface_InitWithAudioData_Offset, audioData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::GetAudioObject() const -> AudioObjectRef
{
	const MediaStreamAudioDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, this); return mt_._MediaStreamAudioDataExportInterface_GetAudioObject((const maxon::GenericComponent*) this + mt_._MediaStreamAudioDataExportInterface_GetAudioObject_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::SetCallbackHandler() -> Result<void>
{
	const MediaStreamAudioDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, this); return mt_._MediaStreamAudioDataExportInterface_SetCallbackHandler((maxon::GenericComponent*) this + mt_._MediaStreamAudioDataExportInterface_SetCallbackHandler_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::InitStream(MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamAudioDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, this); return mt_._MediaStreamAudioDataExportInterface_InitStream((maxon::GenericComponent*) this + mt_._MediaStreamAudioDataExportInterface_InitStream_Offset, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamAudioDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, this); return mt_._MediaStreamAudioDataExportInterface_FinishStream((maxon::GenericComponent*) this + mt_._MediaStreamAudioDataExportInterface_FinishStream_Offset, props);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::ReferenceFunctionsImpl<S>::InitWithAudioData(const AudioObjectRef& audioData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataExportInterface* o_ = (MediaStreamAudioDataExportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataExportInterface, o_, MediaStreamAudioDataExportInterface_InitWithAudioData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaStreamAudioDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, o_); 
	return (mt_._MediaStreamAudioDataExportInterface_InitWithAudioData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataExportInterface_InitWithAudioData_Offset, audioData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::COWReferenceFunctionsImpl<S>::InitWithAudioData(const AudioObjectRef& audioData) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataExportInterface* o_ = (MediaStreamAudioDataExportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataExportInterface, o_, MediaStreamAudioDataExportInterface_InitWithAudioData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaStreamAudioDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, o_); 
	return (mt_._MediaStreamAudioDataExportInterface_InitWithAudioData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataExportInterface_InitWithAudioData_Offset, audioData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetAudioObject() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<AudioObjectRef>, AudioObjectRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<AudioObjectRef>, AudioObjectRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaStreamAudioDataExportInterface* o_ = (const MediaStreamAudioDataExportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaStreamAudioDataExportInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<AudioObjectRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataExportInterface, o_, MediaStreamAudioDataExportInterface_GetAudioObject) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaStreamAudioDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, o_); 
	return (mt_._MediaStreamAudioDataExportInterface_GetAudioObject(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataExportInterface_GetAudioObject_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::ReferenceFunctionsImpl<S>::SetCallbackHandler() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataExportInterface* o_ = (MediaStreamAudioDataExportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataExportInterface, o_, MediaStreamAudioDataExportInterface_SetCallbackHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaStreamAudioDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, o_); 
	return (mt_._MediaStreamAudioDataExportInterface_SetCallbackHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataExportInterface_SetCallbackHandler_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetCallbackHandler() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataExportInterface* o_ = (MediaStreamAudioDataExportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataExportInterface, o_, MediaStreamAudioDataExportInterface_SetCallbackHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaStreamAudioDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, o_); 
	return (mt_._MediaStreamAudioDataExportInterface_SetCallbackHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataExportInterface_SetCallbackHandler_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::ReferenceFunctionsImpl<S>::InitStream(MediaStreamProperties& props) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataExportInterface* o_ = (MediaStreamAudioDataExportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataExportInterface, o_, MediaStreamAudioDataExportInterface_InitStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaStreamAudioDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, o_); 
	return (mt_._MediaStreamAudioDataExportInterface_InitStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataExportInterface_InitStream_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::COWReferenceFunctionsImpl<S>::InitStream(MediaStreamProperties& props) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataExportInterface* o_ = (MediaStreamAudioDataExportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataExportInterface, o_, MediaStreamAudioDataExportInterface_InitStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaStreamAudioDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, o_); 
	return (mt_._MediaStreamAudioDataExportInterface_InitStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataExportInterface_InitStream_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::ReferenceFunctionsImpl<S>::FinishStream(const MediaStreamProperties& props) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataExportInterface* o_ = (MediaStreamAudioDataExportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataExportInterface, o_, MediaStreamAudioDataExportInterface_FinishStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaStreamAudioDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, o_); 
	return (mt_._MediaStreamAudioDataExportInterface_FinishStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataExportInterface_FinishStream_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::COWReferenceFunctionsImpl<S>::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataExportInterface* o_ = (MediaStreamAudioDataExportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataExportInterface, o_, MediaStreamAudioDataExportInterface_FinishStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaStreamAudioDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, o_); 
	return (mt_._MediaStreamAudioDataExportInterface_FinishStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaStreamAudioDataExportInterface_FinishStream_Offset, props));
}
auto MediaStreamAudioDataExportInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaStreamAudioDataExportInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaStreamAudioDataExportInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaStreamAudioDataExportInterface() { new (s_ui_maxon_MediaStreamAudioDataExportInterface) maxon::EntityUse(MediaStreamAudioDataExportInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_audiodata.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaStreamAudioDataExportInterface(MediaStreamAudioDataExportInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_audiodata.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

