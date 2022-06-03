
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*MediaSessionInterface_ConnectMediaConverter) (maxon::GenericComponent* this_, const MediaConverterRef& input, const MediaConverterRef& output);
	maxon::Int MediaSessionInterface_ConnectMediaConverter_Offset;
	Result<void> (*MediaSessionInterface_Convert) (maxon::GenericComponent* this_, const TimeValue& targetTime, MEDIASESSIONFLAGS flags);
	maxon::Int MediaSessionInterface_Convert_Offset;
	Result<void> (*MediaSessionInterface_Close) (maxon::GenericComponent* this_);
	maxon::Int MediaSessionInterface_Close_Offset;
	ProgressRef (*MediaSessionInterface_GetProgress) (const maxon::GenericComponent* this_);
	maxon::Int MediaSessionInterface_GetProgress_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, ConnectMediaConverter))
	{
		MediaSessionInterface_ConnectMediaConverter = &W::MediaSessionInterface_ConnectMediaConverter;
		MediaSessionInterface_ConnectMediaConverter_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, Convert))
	{
		MediaSessionInterface_Convert = &W::MediaSessionInterface_Convert;
		MediaSessionInterface_Convert_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, Close))
	{
		MediaSessionInterface_Close = &W::MediaSessionInterface_Close;
		MediaSessionInterface_Close_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, GetProgress))
	{
		MediaSessionInterface_GetProgress = &W::MediaSessionInterface_GetProgress;
		MediaSessionInterface_GetProgress_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaSessionInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaSessionInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaSessionInterface::Hxx2
{
	template <typename S> class CWrapper : public ObserverObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Close);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConnectMediaConverter);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Convert);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetProgress);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObserverObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MediaSessionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaSessionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> MediaSessionInterface_ConnectMediaConverter(maxon::GenericComponent* this_, const MediaConverterRef& input, const MediaConverterRef& output) { return ((typename S::Implementation*) this_)->ConnectMediaConverter(input, output); }
		static Result<void> MediaSessionInterface_Convert(maxon::GenericComponent* this_, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) { return ((typename S::Implementation*) this_)->Convert(targetTime, flags); }
		static Result<void> MediaSessionInterface_Close(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Close(); }
		static ProgressRef MediaSessionInterface_GetProgress(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetProgress(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output) -> Result<void>
{
	const MediaSessionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionInterface, this); return mt_.MediaSessionInterface_ConnectMediaConverter((maxon::GenericComponent*) this + mt_.MediaSessionInterface_ConnectMediaConverter_Offset, input, output);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	const MediaSessionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionInterface, this); return mt_.MediaSessionInterface_Convert((maxon::GenericComponent*) this + mt_.MediaSessionInterface_Convert_Offset, targetTime, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Close() -> Result<void>
{
	const MediaSessionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionInterface, this); return mt_.MediaSessionInterface_Close((maxon::GenericComponent*) this + mt_.MediaSessionInterface_Close_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::GetProgress() const -> ProgressRef
{
	const MediaSessionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionInterface, this); return mt_.MediaSessionInterface_GetProgress((const maxon::GenericComponent*) this + mt_.MediaSessionInterface_GetProgress_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::Fn<S>::ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionInterface* o_ = (MediaSessionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionInterface, o_, MediaSessionInterface_ConnectMediaConverter) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaSessionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionInterface, o_); 
	return (mt_.MediaSessionInterface_ConnectMediaConverter(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_ConnectMediaConverter_Offset, input, output));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::COWFn<S>::ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionInterface* o_ = (MediaSessionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionInterface, o_, MediaSessionInterface_ConnectMediaConverter) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaSessionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionInterface, o_); 
	return (mt_.MediaSessionInterface_ConnectMediaConverter(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_ConnectMediaConverter_Offset, input, output));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::Fn<S>::Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionInterface* o_ = (MediaSessionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionInterface, o_, MediaSessionInterface_Convert) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaSessionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionInterface, o_); 
	return (mt_.MediaSessionInterface_Convert(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_Convert_Offset, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::COWFn<S>::Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionInterface* o_ = (MediaSessionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionInterface, o_, MediaSessionInterface_Convert) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaSessionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionInterface, o_); 
	return (mt_.MediaSessionInterface_Convert(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_Convert_Offset, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::Fn<S>::Close() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionInterface* o_ = (MediaSessionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionInterface, o_, MediaSessionInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaSessionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionInterface, o_); 
	return (mt_.MediaSessionInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::COWFn<S>::Close() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaSessionInterface* o_ = (MediaSessionInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionInterface, o_, MediaSessionInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaSessionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionInterface, o_); 
	return (mt_.MediaSessionInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::ConstFn<S>::GetProgress() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ProgressRef>, ProgressRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ProgressRef>, ProgressRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaSessionInterface* o_ = (const MediaSessionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaSessionInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ProgressRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaSessionInterface, o_, MediaSessionInterface_GetProgress) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaSessionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaSessionInterface>() : PRIVATE_MAXON_VTABLE(MediaSessionInterface, o_); 
	return (mt_.MediaSessionInterface_GetProgress(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_GetProgress_Offset));
}
auto MediaSessionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaSessionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_session)
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

