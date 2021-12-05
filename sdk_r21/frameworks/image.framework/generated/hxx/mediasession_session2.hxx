
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct MediaSessionInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Close);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ConnectMediaConverter);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Convert);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetProgress);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_MediaSessionInterface_ConnectMediaConverter) (maxon::GenericComponent* this_, const MediaConverterRef& input, const MediaConverterRef& output);
	maxon::Int _MediaSessionInterface_ConnectMediaConverter_Offset;
	Result<void> (*_MediaSessionInterface_Convert) (maxon::GenericComponent* this_, const TimeValue& targetTime, MEDIASESSIONFLAGS flags);
	maxon::Int _MediaSessionInterface_Convert_Offset;
	Result<void> (*_MediaSessionInterface_Close) (maxon::GenericComponent* this_);
	maxon::Int _MediaSessionInterface_Close_Offset;
	MediaSessionProgressRef (*_MediaSessionInterface_GetProgress) (const maxon::GenericComponent* this_);
	maxon::Int _MediaSessionInterface_GetProgress_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, ConnectMediaConverter))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, ConnectMediaConverter), W, MTable>::type::_MediaSessionInterface_ConnectMediaConverter;
			_MediaSessionInterface_ConnectMediaConverter = reinterpret_cast<const decltype(_MediaSessionInterface_ConnectMediaConverter)&>(ptr);
			_MediaSessionInterface_ConnectMediaConverter_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, Convert))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, Convert), W, MTable>::type::_MediaSessionInterface_Convert;
			_MediaSessionInterface_Convert = reinterpret_cast<const decltype(_MediaSessionInterface_Convert)&>(ptr);
			_MediaSessionInterface_Convert_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, Close))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, Close), W, MTable>::type::_MediaSessionInterface_Close;
			_MediaSessionInterface_Close = reinterpret_cast<const decltype(_MediaSessionInterface_Close)&>(ptr);
			_MediaSessionInterface_Close_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, GetProgress))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, GetProgress), W, MTable>::type::_MediaSessionInterface_GetProgress;
			_MediaSessionInterface_GetProgress = reinterpret_cast<const decltype(_MediaSessionInterface_GetProgress)&>(ptr);
			_MediaSessionInterface_GetProgress_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObserverObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaSessionInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(MediaSessionInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaSessionInterface::Hxx2
{
	template <typename S> class Wrapper : public ObserverObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Close);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConnectMediaConverter);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Convert);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetProgress);
	static Result<void> _MediaSessionInterface_ConnectMediaConverter(maxon::GenericComponent* this_, const MediaConverterRef& input, const MediaConverterRef& output) { return ((typename S::Implementation*) this_)->ConnectMediaConverter(input, output); }
	static Result<void> _MediaSessionInterface_Convert(maxon::GenericComponent* this_, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) { return ((typename S::Implementation*) this_)->Convert(targetTime, flags); }
	static Result<void> _MediaSessionInterface_Close(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Close(); }
	static MediaSessionProgressRef _MediaSessionInterface_GetProgress(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetProgress(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output) -> Result<void>
{
	const MediaSessionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionInterface, this); return mt_._MediaSessionInterface_ConnectMediaConverter((maxon::GenericComponent*) this + mt_._MediaSessionInterface_ConnectMediaConverter_Offset, input, output);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	const MediaSessionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionInterface, this); return mt_._MediaSessionInterface_Convert((maxon::GenericComponent*) this + mt_._MediaSessionInterface_Convert_Offset, targetTime, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Close() -> Result<void>
{
	const MediaSessionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionInterface, this); return mt_._MediaSessionInterface_Close((maxon::GenericComponent*) this + mt_._MediaSessionInterface_Close_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::GetProgress() const -> MediaSessionProgressRef
{
	const MediaSessionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionInterface, this); return mt_._MediaSessionInterface_GetProgress((const maxon::GenericComponent*) this + mt_._MediaSessionInterface_GetProgress_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::ReferenceFunctionsImpl<S>::ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionInterface* o_ = (MediaSessionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionInterface, o_, MediaSessionInterface_ConnectMediaConverter) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaSessionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionInterface, o_); 
	return (mt_._MediaSessionInterface_ConnectMediaConverter(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionInterface_ConnectMediaConverter_Offset, input, output));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionInterface* o_ = (MediaSessionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionInterface, o_, MediaSessionInterface_ConnectMediaConverter) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaSessionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionInterface, o_); 
	return (mt_._MediaSessionInterface_ConnectMediaConverter(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionInterface_ConnectMediaConverter_Offset, input, output));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::ReferenceFunctionsImpl<S>::Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionInterface* o_ = (MediaSessionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionInterface, o_, MediaSessionInterface_Convert) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaSessionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionInterface, o_); 
	return (mt_._MediaSessionInterface_Convert(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionInterface_Convert_Offset, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::COWReferenceFunctionsImpl<S>::Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionInterface* o_ = (MediaSessionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionInterface, o_, MediaSessionInterface_Convert) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaSessionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionInterface, o_); 
	return (mt_._MediaSessionInterface_Convert(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionInterface_Convert_Offset, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::ReferenceFunctionsImpl<S>::Close() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionInterface* o_ = (MediaSessionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionInterface, o_, MediaSessionInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaSessionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionInterface, o_); 
	return (mt_._MediaSessionInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::COWReferenceFunctionsImpl<S>::Close() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionInterface* o_ = (MediaSessionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionInterface, o_, MediaSessionInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaSessionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionInterface, o_); 
	return (mt_._MediaSessionInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaSessionInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetProgress() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<MediaSessionProgressRef>, MediaSessionProgressRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<MediaSessionProgressRef>, MediaSessionProgressRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaSessionInterface* o_ = (const MediaSessionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaSessionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<MediaSessionProgressRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionInterface, o_, MediaSessionInterface_GetProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaSessionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionInterface, o_); 
	return (mt_._MediaSessionInterface_GetProgress(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MediaSessionInterface_GetProgress_Offset));
}
auto MediaSessionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaSessionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaSessionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaSessionInterface() { new (s_ui_maxon_MediaSessionInterface) maxon::EntityUse(MediaSessionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_session.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaSessionInterface(MediaSessionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_session.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

