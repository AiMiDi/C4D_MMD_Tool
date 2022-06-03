
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct MediaStreamInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddFormat);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetFormat);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetFormats);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSelectedFormat);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsSubscribed);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetSelectedFormat);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SubscribeStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(UnsubscribeStream);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<BaseArray<Data>> (*MediaStreamInterface_GetFormats) (const maxon::GenericComponent* this_);
	maxon::Int MediaStreamInterface_GetFormats_Offset;
	MediaStreamFormat (*MediaStreamInterface_GetFormat) (const maxon::GenericComponent* this_, const Data& formatId);
	maxon::Int MediaStreamInterface_GetFormat_Offset;
	const Data& (*MediaStreamInterface_GetSelectedFormat) (const maxon::GenericComponent* this_);
	maxon::Int MediaStreamInterface_GetSelectedFormat_Offset;
	Result<void> (*MediaStreamInterface_SetSelectedFormat) (maxon::GenericComponent* this_, const Data& formatId);
	maxon::Int MediaStreamInterface_SetSelectedFormat_Offset;
	Result<void> (*MediaStreamInterface_AddFormat) (maxon::GenericComponent* this_, const Data& formatId, const MediaStreamFormat& ref);
	maxon::Int MediaStreamInterface_AddFormat_Offset;
	Result<void> (*MediaStreamInterface_SubscribeStream) (maxon::GenericComponent* this_, const Data& formatId);
	maxon::Int MediaStreamInterface_SubscribeStream_Offset;
	Result<void> (*MediaStreamInterface_UnsubscribeStream) (maxon::GenericComponent* this_);
	maxon::Int MediaStreamInterface_UnsubscribeStream_Offset;
	Bool (*MediaStreamInterface_IsSubscribed) (const maxon::GenericComponent* this_);
	maxon::Int MediaStreamInterface_IsSubscribed_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, GetFormats))
	{
		MediaStreamInterface_GetFormats = &W::MediaStreamInterface_GetFormats;
		MediaStreamInterface_GetFormats_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, GetFormat))
	{
		MediaStreamInterface_GetFormat = &W::MediaStreamInterface_GetFormat;
		MediaStreamInterface_GetFormat_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, GetSelectedFormat))
	{
		MediaStreamInterface_GetSelectedFormat = &W::MediaStreamInterface_GetSelectedFormat;
		MediaStreamInterface_GetSelectedFormat_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, SetSelectedFormat))
	{
		MediaStreamInterface_SetSelectedFormat = &W::MediaStreamInterface_SetSelectedFormat;
		MediaStreamInterface_SetSelectedFormat_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, AddFormat))
	{
		MediaStreamInterface_AddFormat = &W::MediaStreamInterface_AddFormat;
		MediaStreamInterface_AddFormat_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, SubscribeStream))
	{
		MediaStreamInterface_SubscribeStream = &W::MediaStreamInterface_SubscribeStream;
		MediaStreamInterface_SubscribeStream_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, UnsubscribeStream))
	{
		MediaStreamInterface_UnsubscribeStream = &W::MediaStreamInterface_UnsubscribeStream;
		MediaStreamInterface_UnsubscribeStream_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, IsSubscribed))
	{
		MediaStreamInterface_IsSubscribed = &W::MediaStreamInterface_IsSubscribed;
		MediaStreamInterface_IsSubscribed_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaStreamInterface, typename HierarchyObjectInterface::MTable::template CombinedMTable<typename MediaBaseInterface::MTable::template CombinedMTable<S>>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaStreamInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaStreamInterface::Hxx2
{
	template <typename S> class CWrapper : public HierarchyObjectInterface::Hxx2::template CWrapper<typename MediaBaseInterface::Hxx2::template CWrapper<S>>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddFormat);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFormat);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFormats);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSelectedFormat);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsSubscribed);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetSelectedFormat);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SubscribeStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(UnsubscribeStream);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename MediaBaseInterface::Hxx2::template CWrapper<S>;
			using Super1 = typename HierarchyObjectInterface::Hxx2::template CWrapper<Super0>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset) && Super1::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MediaStreamInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<BaseArray<Data>> MediaStreamInterface_GetFormats(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetFormats(); }
		static MediaStreamFormat MediaStreamInterface_GetFormat(const maxon::GenericComponent* this_, const Data& formatId) { return ((const typename S::Implementation*) this_)->GetFormat(formatId); }
		static const Data& MediaStreamInterface_GetSelectedFormat(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetSelectedFormat(); }
		static Result<void> MediaStreamInterface_SetSelectedFormat(maxon::GenericComponent* this_, const Data& formatId) { return ((typename S::Implementation*) this_)->SetSelectedFormat(formatId); }
		static Result<void> MediaStreamInterface_AddFormat(maxon::GenericComponent* this_, const Data& formatId, const MediaStreamFormat& ref) { return ((typename S::Implementation*) this_)->AddFormat(formatId, ref); }
		static Result<void> MediaStreamInterface_SubscribeStream(maxon::GenericComponent* this_, const Data& formatId) { return ((typename S::Implementation*) this_)->SubscribeStream(formatId); }
		static Result<void> MediaStreamInterface_UnsubscribeStream(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->UnsubscribeStream(); }
		static Bool MediaStreamInterface_IsSubscribed(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->IsSubscribed(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::GetFormats() const -> Result<BaseArray<Data>>
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return mt_.MediaStreamInterface_GetFormats((const maxon::GenericComponent*) this + mt_.MediaStreamInterface_GetFormats_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::GetFormat(const Data& formatId) const -> MediaStreamFormat
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return mt_.MediaStreamInterface_GetFormat((const maxon::GenericComponent*) this + mt_.MediaStreamInterface_GetFormat_Offset, formatId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::GetSelectedFormat() const -> const Data&
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return mt_.MediaStreamInterface_GetSelectedFormat((const maxon::GenericComponent*) this + mt_.MediaStreamInterface_GetSelectedFormat_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::SetSelectedFormat(const Data& formatId) -> Result<void>
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return mt_.MediaStreamInterface_SetSelectedFormat((maxon::GenericComponent*) this + mt_.MediaStreamInterface_SetSelectedFormat_Offset, formatId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::AddFormat(const Data& formatId, const MediaStreamFormat& ref) -> Result<void>
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return mt_.MediaStreamInterface_AddFormat((maxon::GenericComponent*) this + mt_.MediaStreamInterface_AddFormat_Offset, formatId, ref);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::SubscribeStream(const Data& formatId) -> Result<void>
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return mt_.MediaStreamInterface_SubscribeStream((maxon::GenericComponent*) this + mt_.MediaStreamInterface_SubscribeStream_Offset, formatId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::UnsubscribeStream() -> Result<void>
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return mt_.MediaStreamInterface_UnsubscribeStream((maxon::GenericComponent*) this + mt_.MediaStreamInterface_UnsubscribeStream_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::IsSubscribed() const -> Bool
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return mt_.MediaStreamInterface_IsSubscribed((const maxon::GenericComponent*) this + mt_.MediaStreamInterface_IsSubscribed_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::ConstFn<S>::GetFormats() const -> Result<BaseArray<Data>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<Data>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaStreamInterface* o_ = (const MediaStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamInterface, o_, MediaStreamInterface_GetFormats) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamInterface, o_); 
	return (mt_.MediaStreamInterface_GetFormats(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_GetFormats_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::ConstFn<S>::GetFormat(const Data& formatId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<MediaStreamFormat>, MediaStreamFormat>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<MediaStreamFormat>, MediaStreamFormat>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaStreamInterface* o_ = (const MediaStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<MediaStreamFormat>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamInterface, o_, MediaStreamInterface_GetFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamInterface, o_); 
	return (mt_.MediaStreamInterface_GetFormat(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_GetFormat_Offset, formatId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::ConstFn<S>::GetSelectedFormat() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Data&>, const Data&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Data&>, const Data&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaStreamInterface* o_ = (const MediaStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Data&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamInterface, o_, MediaStreamInterface_GetSelectedFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamInterface, o_); 
	return (mt_.MediaStreamInterface_GetSelectedFormat(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_GetSelectedFormat_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::Fn<S>::SetSelectedFormat(const Data& formatId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamInterface* o_ = (MediaStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamInterface, o_, MediaStreamInterface_SetSelectedFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamInterface, o_); 
	return (mt_.MediaStreamInterface_SetSelectedFormat(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_SetSelectedFormat_Offset, formatId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::COWFn<S>::SetSelectedFormat(const Data& formatId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamInterface* o_ = (MediaStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamInterface, o_, MediaStreamInterface_SetSelectedFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamInterface, o_); 
	return (mt_.MediaStreamInterface_SetSelectedFormat(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_SetSelectedFormat_Offset, formatId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::Fn<S>::AddFormat(const Data& formatId, const MediaStreamFormat& ref) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamInterface* o_ = (MediaStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamInterface, o_, MediaStreamInterface_AddFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamInterface, o_); 
	return (mt_.MediaStreamInterface_AddFormat(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_AddFormat_Offset, formatId, ref));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::COWFn<S>::AddFormat(const Data& formatId, const MediaStreamFormat& ref) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamInterface* o_ = (MediaStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamInterface, o_, MediaStreamInterface_AddFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamInterface, o_); 
	return (mt_.MediaStreamInterface_AddFormat(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_AddFormat_Offset, formatId, ref));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::Fn<S>::SubscribeStream(const Data& formatId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamInterface* o_ = (MediaStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamInterface, o_, MediaStreamInterface_SubscribeStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamInterface, o_); 
	return (mt_.MediaStreamInterface_SubscribeStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_SubscribeStream_Offset, formatId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::COWFn<S>::SubscribeStream(const Data& formatId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamInterface* o_ = (MediaStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamInterface, o_, MediaStreamInterface_SubscribeStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamInterface, o_); 
	return (mt_.MediaStreamInterface_SubscribeStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_SubscribeStream_Offset, formatId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::Fn<S>::UnsubscribeStream() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamInterface* o_ = (MediaStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamInterface, o_, MediaStreamInterface_UnsubscribeStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamInterface, o_); 
	return (mt_.MediaStreamInterface_UnsubscribeStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_UnsubscribeStream_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::COWFn<S>::UnsubscribeStream() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamInterface* o_ = (MediaStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamInterface, o_, MediaStreamInterface_UnsubscribeStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamInterface, o_); 
	return (mt_.MediaStreamInterface_UnsubscribeStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_UnsubscribeStream_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::ConstFn<S>::IsSubscribed() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaStreamInterface* o_ = (const MediaStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamInterface, o_, MediaStreamInterface_IsSubscribed) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamInterface, o_); 
	return (mt_.MediaStreamInterface_IsSubscribed(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_IsSubscribed_Offset));
}
auto MediaStreamInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaStreamInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_stream)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaStreamInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaStreamInterface() { new (s_ui_maxon_MediaStreamInterface) maxon::EntityUse(MediaStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_stream.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaStreamInterface(MediaStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_stream.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MediaStreamExifDataInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FinishStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(HandleExifData);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetCallbackHandler);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*MediaStreamExifDataInterface_SetCallbackHandler) (maxon::GenericComponent* this_, const ExifDataHandler& handleExifData);
	maxon::Int MediaStreamExifDataInterface_SetCallbackHandler_Offset;
	Result<void> (*MediaStreamExifDataInterface_HandleExifData) (maxon::GenericComponent* this_, const ExifRef& exifData);
	maxon::Int MediaStreamExifDataInterface_HandleExifData_Offset;
	Result<void> (*MediaStreamExifDataInterface_FinishStream) (maxon::GenericComponent* this_, const MediaStreamProperties& props);
	maxon::Int MediaStreamExifDataInterface_FinishStream_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamExifDataInterface, SetCallbackHandler))
	{
		MediaStreamExifDataInterface_SetCallbackHandler = &W::MediaStreamExifDataInterface_SetCallbackHandler;
		MediaStreamExifDataInterface_SetCallbackHandler_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamExifDataInterface, HandleExifData))
	{
		MediaStreamExifDataInterface_HandleExifData = &W::MediaStreamExifDataInterface_HandleExifData;
		MediaStreamExifDataInterface_HandleExifData_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamExifDataInterface, FinishStream))
	{
		MediaStreamExifDataInterface_FinishStream = &W::MediaStreamExifDataInterface_FinishStream;
		MediaStreamExifDataInterface_FinishStream_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaStreamExifDataInterface, typename MediaStreamInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaStreamExifDataInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaStreamExifDataInterface::Hxx2
{
	template <typename S> class CWrapper : public MediaStreamInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FinishStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(HandleExifData);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetCallbackHandler);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename MediaStreamInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MediaStreamExifDataInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamExifDataInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> MediaStreamExifDataInterface_SetCallbackHandler(maxon::GenericComponent* this_, const ExifDataHandler& handleExifData) { return ((typename S::Implementation*) this_)->SetCallbackHandler(handleExifData); }
		static Result<void> MediaStreamExifDataInterface_HandleExifData(maxon::GenericComponent* this_, const ExifRef& exifData) { return ((typename S::Implementation*) this_)->HandleExifData(exifData); }
		static Result<void> MediaStreamExifDataInterface_FinishStream(maxon::GenericComponent* this_, const MediaStreamProperties& props) { return ((typename S::Implementation*) this_)->FinishStream(props); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::SetCallbackHandler(const ExifDataHandler& handleExifData) -> Result<void>
{
	const MediaStreamExifDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamExifDataInterface, this); return mt_.MediaStreamExifDataInterface_SetCallbackHandler((maxon::GenericComponent*) this + mt_.MediaStreamExifDataInterface_SetCallbackHandler_Offset, handleExifData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::HandleExifData(const ExifRef& exifData) -> Result<void>
{
	const MediaStreamExifDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamExifDataInterface, this); return mt_.MediaStreamExifDataInterface_HandleExifData((maxon::GenericComponent*) this + mt_.MediaStreamExifDataInterface_HandleExifData_Offset, exifData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamExifDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamExifDataInterface, this); return mt_.MediaStreamExifDataInterface_FinishStream((maxon::GenericComponent*) this + mt_.MediaStreamExifDataInterface_FinishStream_Offset, props);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::Hxx1::Fn<S>::SetCallbackHandler(const ExifDataHandler& handleExifData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamExifDataInterface* o_ = (MediaStreamExifDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamExifDataInterface, o_, MediaStreamExifDataInterface_SetCallbackHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamExifDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamExifDataInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamExifDataInterface, o_); 
	return (mt_.MediaStreamExifDataInterface_SetCallbackHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamExifDataInterface_SetCallbackHandler_Offset, handleExifData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::Hxx1::COWFn<S>::SetCallbackHandler(const ExifDataHandler& handleExifData) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamExifDataInterface* o_ = (MediaStreamExifDataInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamExifDataInterface, o_, MediaStreamExifDataInterface_SetCallbackHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamExifDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamExifDataInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamExifDataInterface, o_); 
	return (mt_.MediaStreamExifDataInterface_SetCallbackHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamExifDataInterface_SetCallbackHandler_Offset, handleExifData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::Hxx1::Fn<S>::HandleExifData(const ExifRef& exifData) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamExifDataInterface* o_ = (MediaStreamExifDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamExifDataInterface, o_, MediaStreamExifDataInterface_HandleExifData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamExifDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamExifDataInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamExifDataInterface, o_); 
	return (mt_.MediaStreamExifDataInterface_HandleExifData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamExifDataInterface_HandleExifData_Offset, exifData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::Hxx1::COWFn<S>::HandleExifData(const ExifRef& exifData) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamExifDataInterface* o_ = (MediaStreamExifDataInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamExifDataInterface, o_, MediaStreamExifDataInterface_HandleExifData) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamExifDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamExifDataInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamExifDataInterface, o_); 
	return (mt_.MediaStreamExifDataInterface_HandleExifData(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamExifDataInterface_HandleExifData_Offset, exifData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::Hxx1::Fn<S>::FinishStream(const MediaStreamProperties& props) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamExifDataInterface* o_ = (MediaStreamExifDataInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamExifDataInterface, o_, MediaStreamExifDataInterface_FinishStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamExifDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamExifDataInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamExifDataInterface, o_); 
	return (mt_.MediaStreamExifDataInterface_FinishStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamExifDataInterface_FinishStream_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::Hxx1::COWFn<S>::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamExifDataInterface* o_ = (MediaStreamExifDataInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamExifDataInterface, o_, MediaStreamExifDataInterface_FinishStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamExifDataInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamExifDataInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamExifDataInterface, o_); 
	return (mt_.MediaStreamExifDataInterface_FinishStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamExifDataInterface_FinishStream_Offset, props));
}
auto MediaStreamExifDataInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaStreamExifDataInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_stream)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaStreamExifDataInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaStreamExifDataInterface() { new (s_ui_maxon_MediaStreamExifDataInterface) maxon::EntityUse(MediaStreamExifDataInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_stream.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaStreamExifDataInterface(MediaStreamExifDataInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_stream.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MediaStreamImageBaseInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaStreamImageBaseInterface, typename MediaStreamInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaStreamImageBaseInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaStreamImageBaseInterface::Hxx2
{
	template <typename S> class CWrapper : public MediaStreamInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename MediaStreamInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MediaStreamImageBaseInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamImageBaseInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto MediaStreamImageBaseInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaStreamImageBaseInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_stream)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaStreamImageBaseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaStreamImageBaseInterface() { new (s_ui_maxon_MediaStreamImageBaseInterface) maxon::EntityUse(MediaStreamImageBaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_stream.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaStreamImageBaseInterface(MediaStreamImageBaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_stream.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MediaStreamImageDataImportInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FinishStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetCallbackHandler);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetPixelStream);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*MediaStreamImageDataImportInterface_SetCallbackHandler) (maxon::GenericComponent* this_, const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler);
	maxon::Int MediaStreamImageDataImportInterface_SetCallbackHandler_Offset;
	Result<void> (*MediaStreamImageDataImportInterface_InitStream) (maxon::GenericComponent* this_, const MediaStreamProperties& props);
	maxon::Int MediaStreamImageDataImportInterface_InitStream_Offset;
	Result<SetPixelHandlerStruct> (*MediaStreamImageDataImportInterface_SetPixelStream) (maxon::GenericComponent* this_, const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags);
	maxon::Int MediaStreamImageDataImportInterface_SetPixelStream_Offset;
	Result<void> (*MediaStreamImageDataImportInterface_FinishStream) (maxon::GenericComponent* this_, const MediaStreamProperties& props);
	maxon::Int MediaStreamImageDataImportInterface_FinishStream_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataImportInterface, SetCallbackHandler))
	{
		MediaStreamImageDataImportInterface_SetCallbackHandler = &W::MediaStreamImageDataImportInterface_SetCallbackHandler;
		MediaStreamImageDataImportInterface_SetCallbackHandler_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataImportInterface, InitStream))
	{
		MediaStreamImageDataImportInterface_InitStream = &W::MediaStreamImageDataImportInterface_InitStream;
		MediaStreamImageDataImportInterface_InitStream_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataImportInterface, SetPixelStream))
	{
		MediaStreamImageDataImportInterface_SetPixelStream = &W::MediaStreamImageDataImportInterface_SetPixelStream;
		MediaStreamImageDataImportInterface_SetPixelStream_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataImportInterface, FinishStream))
	{
		MediaStreamImageDataImportInterface_FinishStream = &W::MediaStreamImageDataImportInterface_FinishStream;
		MediaStreamImageDataImportInterface_FinishStream_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaStreamImageDataImportInterface, typename MediaStreamImageBaseInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaStreamImageDataImportInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaStreamImageDataImportInterface::Hxx2
{
	template <typename S> class CWrapper : public MediaStreamImageBaseInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FinishStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetCallbackHandler);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetPixelStream);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename MediaStreamImageBaseInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MediaStreamImageDataImportInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamImageDataImportInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> MediaStreamImageDataImportInterface_SetCallbackHandler(maxon::GenericComponent* this_, const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler) { return ((typename S::Implementation*) this_)->SetCallbackHandler(initHandler, setPixelHandler, finishHandler); }
		static Result<void> MediaStreamImageDataImportInterface_InitStream(maxon::GenericComponent* this_, const MediaStreamProperties& props) { return ((typename S::Implementation*) this_)->InitStream(props); }
		static Result<SetPixelHandlerStruct> MediaStreamImageDataImportInterface_SetPixelStream(maxon::GenericComponent* this_, const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags) { return ((typename S::Implementation*) this_)->SetPixelStream(props, srcChannelOffsets, setPixelFlags); }
		static Result<void> MediaStreamImageDataImportInterface_FinishStream(maxon::GenericComponent* this_, const MediaStreamProperties& props) { return ((typename S::Implementation*) this_)->FinishStream(props); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::SetCallbackHandler(const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler) -> Result<void>
{
	const MediaStreamImageDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, this); return mt_.MediaStreamImageDataImportInterface_SetCallbackHandler((maxon::GenericComponent*) this + mt_.MediaStreamImageDataImportInterface_SetCallbackHandler_Offset, initHandler, setPixelHandler, finishHandler);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::InitStream(const MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamImageDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, this); return mt_.MediaStreamImageDataImportInterface_InitStream((maxon::GenericComponent*) this + mt_.MediaStreamImageDataImportInterface_InitStream_Offset, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::SetPixelStream(const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags) -> Result<SetPixelHandlerStruct>
{
	const MediaStreamImageDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, this); return mt_.MediaStreamImageDataImportInterface_SetPixelStream((maxon::GenericComponent*) this + mt_.MediaStreamImageDataImportInterface_SetPixelStream_Offset, props, srcChannelOffsets, setPixelFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamImageDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, this); return mt_.MediaStreamImageDataImportInterface_FinishStream((maxon::GenericComponent*) this + mt_.MediaStreamImageDataImportInterface_FinishStream_Offset, props);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::Fn<S>::SetCallbackHandler(const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataImportInterface* o_ = (MediaStreamImageDataImportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataImportInterface, o_, MediaStreamImageDataImportInterface_SetCallbackHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, o_); 
	return (mt_.MediaStreamImageDataImportInterface_SetCallbackHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_SetCallbackHandler_Offset, initHandler, setPixelHandler, finishHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::COWFn<S>::SetCallbackHandler(const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataImportInterface* o_ = (MediaStreamImageDataImportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataImportInterface, o_, MediaStreamImageDataImportInterface_SetCallbackHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, o_); 
	return (mt_.MediaStreamImageDataImportInterface_SetCallbackHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_SetCallbackHandler_Offset, initHandler, setPixelHandler, finishHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::Fn<S>::InitStream(const MediaStreamProperties& props) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataImportInterface* o_ = (MediaStreamImageDataImportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataImportInterface, o_, MediaStreamImageDataImportInterface_InitStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, o_); 
	return (mt_.MediaStreamImageDataImportInterface_InitStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_InitStream_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::COWFn<S>::InitStream(const MediaStreamProperties& props) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataImportInterface* o_ = (MediaStreamImageDataImportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataImportInterface, o_, MediaStreamImageDataImportInterface_InitStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, o_); 
	return (mt_.MediaStreamImageDataImportInterface_InitStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_InitStream_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::Fn<S>::SetPixelStream(const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags) const -> Result<SetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SetPixelHandlerStruct>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataImportInterface* o_ = (MediaStreamImageDataImportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataImportInterface, o_, MediaStreamImageDataImportInterface_SetPixelStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, o_); 
	return (mt_.MediaStreamImageDataImportInterface_SetPixelStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_SetPixelStream_Offset, props, srcChannelOffsets, setPixelFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::COWFn<S>::SetPixelStream(const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags) -> Result<SetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SetPixelHandlerStruct>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataImportInterface* o_ = (MediaStreamImageDataImportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataImportInterface, o_, MediaStreamImageDataImportInterface_SetPixelStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, o_); 
	return (mt_.MediaStreamImageDataImportInterface_SetPixelStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_SetPixelStream_Offset, props, srcChannelOffsets, setPixelFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::Fn<S>::FinishStream(const MediaStreamProperties& props) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataImportInterface* o_ = (MediaStreamImageDataImportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataImportInterface, o_, MediaStreamImageDataImportInterface_FinishStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, o_); 
	return (mt_.MediaStreamImageDataImportInterface_FinishStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_FinishStream_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::COWFn<S>::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataImportInterface* o_ = (MediaStreamImageDataImportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataImportInterface, o_, MediaStreamImageDataImportInterface_FinishStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, o_); 
	return (mt_.MediaStreamImageDataImportInterface_FinishStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_FinishStream_Offset, props));
}
auto MediaStreamImageDataImportInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaStreamImageDataImportInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_stream)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaStreamImageDataImportInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaStreamImageDataImportInterface() { new (s_ui_maxon_MediaStreamImageDataImportInterface) maxon::EntityUse(MediaStreamImageDataImportInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_stream.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaStreamImageDataImportInterface(MediaStreamImageDataImportInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_stream.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MediaStreamImageDataExportInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FinishStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetPixelStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetCallbackHandler);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*MediaStreamImageDataExportInterface_SetCallbackHandler) (maxon::GenericComponent* this_, const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler);
	maxon::Int MediaStreamImageDataExportInterface_SetCallbackHandler_Offset;
	Result<void> (*MediaStreamImageDataExportInterface_InitStream) (maxon::GenericComponent* this_, MediaStreamProperties& props);
	maxon::Int MediaStreamImageDataExportInterface_InitStream_Offset;
	Result<GetPixelHandlerStruct> (*MediaStreamImageDataExportInterface_GetPixelStream) (maxon::GenericComponent* this_, const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags);
	maxon::Int MediaStreamImageDataExportInterface_GetPixelStream_Offset;
	Result<void> (*MediaStreamImageDataExportInterface_FinishStream) (maxon::GenericComponent* this_, const MediaStreamProperties& props);
	maxon::Int MediaStreamImageDataExportInterface_FinishStream_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataExportInterface, SetCallbackHandler))
	{
		MediaStreamImageDataExportInterface_SetCallbackHandler = &W::MediaStreamImageDataExportInterface_SetCallbackHandler;
		MediaStreamImageDataExportInterface_SetCallbackHandler_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataExportInterface, InitStream))
	{
		MediaStreamImageDataExportInterface_InitStream = &W::MediaStreamImageDataExportInterface_InitStream;
		MediaStreamImageDataExportInterface_InitStream_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataExportInterface, GetPixelStream))
	{
		MediaStreamImageDataExportInterface_GetPixelStream = &W::MediaStreamImageDataExportInterface_GetPixelStream;
		MediaStreamImageDataExportInterface_GetPixelStream_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataExportInterface, FinishStream))
	{
		MediaStreamImageDataExportInterface_FinishStream = &W::MediaStreamImageDataExportInterface_FinishStream;
		MediaStreamImageDataExportInterface_FinishStream_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaStreamImageDataExportInterface, typename MediaStreamImageBaseInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaStreamImageDataExportInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaStreamImageDataExportInterface::Hxx2
{
	template <typename S> class CWrapper : public MediaStreamImageBaseInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FinishStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetPixelStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetCallbackHandler);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename MediaStreamImageBaseInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MediaStreamImageDataExportInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamImageDataExportInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> MediaStreamImageDataExportInterface_SetCallbackHandler(maxon::GenericComponent* this_, const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler) { return ((typename S::Implementation*) this_)->SetCallbackHandler(initHandler, getPixelHandler, finishHandler); }
		static Result<void> MediaStreamImageDataExportInterface_InitStream(maxon::GenericComponent* this_, MediaStreamProperties& props) { return ((typename S::Implementation*) this_)->InitStream(props); }
		static Result<GetPixelHandlerStruct> MediaStreamImageDataExportInterface_GetPixelStream(maxon::GenericComponent* this_, const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) { return ((typename S::Implementation*) this_)->GetPixelStream(props, dstFormat, channelOffsets, dstColorProfile, flags); }
		static Result<void> MediaStreamImageDataExportInterface_FinishStream(maxon::GenericComponent* this_, const MediaStreamProperties& props) { return ((typename S::Implementation*) this_)->FinishStream(props); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::SetCallbackHandler(const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler) -> Result<void>
{
	const MediaStreamImageDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, this); return mt_.MediaStreamImageDataExportInterface_SetCallbackHandler((maxon::GenericComponent*) this + mt_.MediaStreamImageDataExportInterface_SetCallbackHandler_Offset, initHandler, getPixelHandler, finishHandler);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::InitStream(MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamImageDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, this); return mt_.MediaStreamImageDataExportInterface_InitStream((maxon::GenericComponent*) this + mt_.MediaStreamImageDataExportInterface_InitStream_Offset, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::GetPixelStream(const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) -> Result<GetPixelHandlerStruct>
{
	const MediaStreamImageDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, this); return mt_.MediaStreamImageDataExportInterface_GetPixelStream((maxon::GenericComponent*) this + mt_.MediaStreamImageDataExportInterface_GetPixelStream_Offset, props, dstFormat, channelOffsets, dstColorProfile, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamImageDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, this); return mt_.MediaStreamImageDataExportInterface_FinishStream((maxon::GenericComponent*) this + mt_.MediaStreamImageDataExportInterface_FinishStream_Offset, props);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::Fn<S>::SetCallbackHandler(const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataExportInterface* o_ = (MediaStreamImageDataExportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataExportInterface, o_, MediaStreamImageDataExportInterface_SetCallbackHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, o_); 
	return (mt_.MediaStreamImageDataExportInterface_SetCallbackHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_SetCallbackHandler_Offset, initHandler, getPixelHandler, finishHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::COWFn<S>::SetCallbackHandler(const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataExportInterface* o_ = (MediaStreamImageDataExportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataExportInterface, o_, MediaStreamImageDataExportInterface_SetCallbackHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, o_); 
	return (mt_.MediaStreamImageDataExportInterface_SetCallbackHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_SetCallbackHandler_Offset, initHandler, getPixelHandler, finishHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::Fn<S>::InitStream(MediaStreamProperties& props) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataExportInterface* o_ = (MediaStreamImageDataExportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataExportInterface, o_, MediaStreamImageDataExportInterface_InitStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, o_); 
	return (mt_.MediaStreamImageDataExportInterface_InitStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_InitStream_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::COWFn<S>::InitStream(MediaStreamProperties& props) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataExportInterface* o_ = (MediaStreamImageDataExportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataExportInterface, o_, MediaStreamImageDataExportInterface_InitStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, o_); 
	return (mt_.MediaStreamImageDataExportInterface_InitStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_InitStream_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::Fn<S>::GetPixelStream(const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const -> Result<GetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GetPixelHandlerStruct>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataExportInterface* o_ = (MediaStreamImageDataExportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataExportInterface, o_, MediaStreamImageDataExportInterface_GetPixelStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, o_); 
	return (mt_.MediaStreamImageDataExportInterface_GetPixelStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_GetPixelStream_Offset, props, dstFormat, channelOffsets, dstColorProfile, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::COWFn<S>::GetPixelStream(const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) -> Result<GetPixelHandlerStruct>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<GetPixelHandlerStruct>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataExportInterface* o_ = (MediaStreamImageDataExportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataExportInterface, o_, MediaStreamImageDataExportInterface_GetPixelStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, o_); 
	return (mt_.MediaStreamImageDataExportInterface_GetPixelStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_GetPixelStream_Offset, props, dstFormat, channelOffsets, dstColorProfile, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::Fn<S>::FinishStream(const MediaStreamProperties& props) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataExportInterface* o_ = (MediaStreamImageDataExportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataExportInterface, o_, MediaStreamImageDataExportInterface_FinishStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, o_); 
	return (mt_.MediaStreamImageDataExportInterface_FinishStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_FinishStream_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::COWFn<S>::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataExportInterface* o_ = (MediaStreamImageDataExportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataExportInterface, o_, MediaStreamImageDataExportInterface_FinishStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataExportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataExportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, o_); 
	return (mt_.MediaStreamImageDataExportInterface_FinishStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_FinishStream_Offset, props));
}
auto MediaStreamImageDataExportInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaStreamImageDataExportInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_stream)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaStreamImageDataExportInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaStreamImageDataExportInterface() { new (s_ui_maxon_MediaStreamImageDataExportInterface) maxon::EntityUse(MediaStreamImageDataExportInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_stream.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaStreamImageDataExportInterface(MediaStreamImageDataExportInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_stream.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MediaStreamImageDataForwardImportInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetSourceStream);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*MediaStreamImageDataForwardImportInterface_SetSourceStream) (maxon::GenericComponent* this_, const MediaStreamImageDataImportRef& sourceStream);
	maxon::Int MediaStreamImageDataForwardImportInterface_SetSourceStream_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataForwardImportInterface, SetSourceStream))
	{
		MediaStreamImageDataForwardImportInterface_SetSourceStream = &W::MediaStreamImageDataForwardImportInterface_SetSourceStream;
		MediaStreamImageDataForwardImportInterface_SetSourceStream_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaStreamImageDataForwardImportInterface, typename MediaStreamImageDataImportInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaStreamImageDataForwardImportInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaStreamImageDataForwardImportInterface::Hxx2
{
	template <typename S> class CWrapper : public MediaStreamImageDataImportInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetSourceStream);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename MediaStreamImageDataImportInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MediaStreamImageDataForwardImportInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamImageDataForwardImportInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> MediaStreamImageDataForwardImportInterface_SetSourceStream(maxon::GenericComponent* this_, const MediaStreamImageDataImportRef& sourceStream) { return ((typename S::Implementation*) this_)->SetSourceStream(sourceStream); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataForwardImportInterface::SetSourceStream(const MediaStreamImageDataImportRef& sourceStream) -> Result<void>
{
	const MediaStreamImageDataForwardImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataForwardImportInterface, this); return mt_.MediaStreamImageDataForwardImportInterface_SetSourceStream((maxon::GenericComponent*) this + mt_.MediaStreamImageDataForwardImportInterface_SetSourceStream_Offset, sourceStream);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataForwardImportInterface::Hxx1::Fn<S>::SetSourceStream(const MediaStreamImageDataImportRef& sourceStream) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataForwardImportInterface* o_ = (MediaStreamImageDataForwardImportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataForwardImportInterface, o_, MediaStreamImageDataForwardImportInterface_SetSourceStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataForwardImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataForwardImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataForwardImportInterface, o_); 
	return (mt_.MediaStreamImageDataForwardImportInterface_SetSourceStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataForwardImportInterface_SetSourceStream_Offset, sourceStream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataForwardImportInterface::Hxx1::COWFn<S>::SetSourceStream(const MediaStreamImageDataImportRef& sourceStream) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamImageDataForwardImportInterface* o_ = (MediaStreamImageDataForwardImportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamImageDataForwardImportInterface, o_, MediaStreamImageDataForwardImportInterface_SetSourceStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamImageDataForwardImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamImageDataForwardImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamImageDataForwardImportInterface, o_); 
	return (mt_.MediaStreamImageDataForwardImportInterface_SetSourceStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataForwardImportInterface_SetSourceStream_Offset, sourceStream));
}
auto MediaStreamImageDataForwardImportInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaStreamImageDataForwardImportInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_stream)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaStreamImageDataForwardImportInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaStreamImageDataForwardImportInterface() { new (s_ui_maxon_MediaStreamImageDataForwardImportInterface) maxon::EntityUse(MediaStreamImageDataForwardImportInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_stream.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaStreamImageDataForwardImportInterface(MediaStreamImageDataForwardImportInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_stream.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MediaStreamAudioDataImportInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FinishStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InitStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetAudioDataCallback);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetCallbackHandler);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*MediaStreamAudioDataImportInterface_SetCallbackHandler) (maxon::GenericComponent* this_, const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler);
	maxon::Int MediaStreamAudioDataImportInterface_SetCallbackHandler_Offset;
	Result<void> (*MediaStreamAudioDataImportInterface_InitStream) (maxon::GenericComponent* this_, MediaStreamProperties& props);
	maxon::Int MediaStreamAudioDataImportInterface_InitStream_Offset;
	Result<SetAudioDataCallbackType> (*MediaStreamAudioDataImportInterface_SetAudioDataCallback) (maxon::GenericComponent* this_, MediaStreamProperties& props);
	maxon::Int MediaStreamAudioDataImportInterface_SetAudioDataCallback_Offset;
	Result<void> (*MediaStreamAudioDataImportInterface_FinishStream) (maxon::GenericComponent* this_, const MediaStreamProperties& props);
	maxon::Int MediaStreamAudioDataImportInterface_FinishStream_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataImportInterface, SetCallbackHandler))
	{
		MediaStreamAudioDataImportInterface_SetCallbackHandler = &W::MediaStreamAudioDataImportInterface_SetCallbackHandler;
		MediaStreamAudioDataImportInterface_SetCallbackHandler_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataImportInterface, InitStream))
	{
		MediaStreamAudioDataImportInterface_InitStream = &W::MediaStreamAudioDataImportInterface_InitStream;
		MediaStreamAudioDataImportInterface_InitStream_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataImportInterface, SetAudioDataCallback))
	{
		MediaStreamAudioDataImportInterface_SetAudioDataCallback = &W::MediaStreamAudioDataImportInterface_SetAudioDataCallback;
		MediaStreamAudioDataImportInterface_SetAudioDataCallback_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataImportInterface, FinishStream))
	{
		MediaStreamAudioDataImportInterface_FinishStream = &W::MediaStreamAudioDataImportInterface_FinishStream;
		MediaStreamAudioDataImportInterface_FinishStream_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaStreamAudioDataImportInterface, typename MediaStreamInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaStreamAudioDataImportInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaStreamAudioDataImportInterface::Hxx2
{
	template <typename S> class CWrapper : public MediaStreamInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FinishStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetAudioDataCallback);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetCallbackHandler);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename MediaStreamInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MediaStreamAudioDataImportInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamAudioDataImportInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> MediaStreamAudioDataImportInterface_SetCallbackHandler(maxon::GenericComponent* this_, const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler) { return ((typename S::Implementation*) this_)->SetCallbackHandler(initHandler, getAudioDataHandler, finishHandler); }
		static Result<void> MediaStreamAudioDataImportInterface_InitStream(maxon::GenericComponent* this_, MediaStreamProperties& props) { return ((typename S::Implementation*) this_)->InitStream(props); }
		static Result<SetAudioDataCallbackType> MediaStreamAudioDataImportInterface_SetAudioDataCallback(maxon::GenericComponent* this_, MediaStreamProperties& props) { return ((typename S::Implementation*) this_)->SetAudioDataCallback(props); }
		static Result<void> MediaStreamAudioDataImportInterface_FinishStream(maxon::GenericComponent* this_, const MediaStreamProperties& props) { return ((typename S::Implementation*) this_)->FinishStream(props); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::SetCallbackHandler(const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler) -> Result<void>
{
	const MediaStreamAudioDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, this); return mt_.MediaStreamAudioDataImportInterface_SetCallbackHandler((maxon::GenericComponent*) this + mt_.MediaStreamAudioDataImportInterface_SetCallbackHandler_Offset, initHandler, getAudioDataHandler, finishHandler);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::InitStream(MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamAudioDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, this); return mt_.MediaStreamAudioDataImportInterface_InitStream((maxon::GenericComponent*) this + mt_.MediaStreamAudioDataImportInterface_InitStream_Offset, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::SetAudioDataCallback(MediaStreamProperties& props) -> Result<SetAudioDataCallbackType>
{
	const MediaStreamAudioDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, this); return mt_.MediaStreamAudioDataImportInterface_SetAudioDataCallback((maxon::GenericComponent*) this + mt_.MediaStreamAudioDataImportInterface_SetAudioDataCallback_Offset, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamAudioDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, this); return mt_.MediaStreamAudioDataImportInterface_FinishStream((maxon::GenericComponent*) this + mt_.MediaStreamAudioDataImportInterface_FinishStream_Offset, props);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::Fn<S>::SetCallbackHandler(const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataImportInterface* o_ = (MediaStreamAudioDataImportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataImportInterface, o_, MediaStreamAudioDataImportInterface_SetCallbackHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamAudioDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, o_); 
	return (mt_.MediaStreamAudioDataImportInterface_SetCallbackHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_SetCallbackHandler_Offset, initHandler, getAudioDataHandler, finishHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::COWFn<S>::SetCallbackHandler(const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataImportInterface* o_ = (MediaStreamAudioDataImportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataImportInterface, o_, MediaStreamAudioDataImportInterface_SetCallbackHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamAudioDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, o_); 
	return (mt_.MediaStreamAudioDataImportInterface_SetCallbackHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_SetCallbackHandler_Offset, initHandler, getAudioDataHandler, finishHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::Fn<S>::InitStream(MediaStreamProperties& props) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataImportInterface* o_ = (MediaStreamAudioDataImportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataImportInterface, o_, MediaStreamAudioDataImportInterface_InitStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamAudioDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, o_); 
	return (mt_.MediaStreamAudioDataImportInterface_InitStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_InitStream_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::COWFn<S>::InitStream(MediaStreamProperties& props) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataImportInterface* o_ = (MediaStreamAudioDataImportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataImportInterface, o_, MediaStreamAudioDataImportInterface_InitStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamAudioDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, o_); 
	return (mt_.MediaStreamAudioDataImportInterface_InitStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_InitStream_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::Fn<S>::SetAudioDataCallback(MediaStreamProperties& props) const -> Result<SetAudioDataCallbackType>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SetAudioDataCallbackType>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataImportInterface* o_ = (MediaStreamAudioDataImportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataImportInterface, o_, MediaStreamAudioDataImportInterface_SetAudioDataCallback) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamAudioDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, o_); 
	return (mt_.MediaStreamAudioDataImportInterface_SetAudioDataCallback(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_SetAudioDataCallback_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::COWFn<S>::SetAudioDataCallback(MediaStreamProperties& props) -> Result<SetAudioDataCallbackType>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SetAudioDataCallbackType>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataImportInterface* o_ = (MediaStreamAudioDataImportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataImportInterface, o_, MediaStreamAudioDataImportInterface_SetAudioDataCallback) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamAudioDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, o_); 
	return (mt_.MediaStreamAudioDataImportInterface_SetAudioDataCallback(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_SetAudioDataCallback_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::Fn<S>::FinishStream(const MediaStreamProperties& props) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataImportInterface* o_ = (MediaStreamAudioDataImportInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataImportInterface, o_, MediaStreamAudioDataImportInterface_FinishStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamAudioDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, o_); 
	return (mt_.MediaStreamAudioDataImportInterface_FinishStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_FinishStream_Offset, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::COWFn<S>::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaStreamAudioDataImportInterface* o_ = (MediaStreamAudioDataImportInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaStreamAudioDataImportInterface, o_, MediaStreamAudioDataImportInterface_FinishStream) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaStreamAudioDataImportInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaStreamAudioDataImportInterface>() : PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, o_); 
	return (mt_.MediaStreamAudioDataImportInterface_FinishStream(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_FinishStream_Offset, props));
}
auto MediaStreamAudioDataImportInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaStreamAudioDataImportInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_stream)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaStreamAudioDataImportInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaStreamAudioDataImportInterface() { new (s_ui_maxon_MediaStreamAudioDataImportInterface) maxon::EntityUse(MediaStreamAudioDataImportInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_stream.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaStreamAudioDataImportInterface(MediaStreamAudioDataImportInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_stream.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

