
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct MediaOutputInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CallSelectionHandler);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSelectionHandler);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ResetConverter);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetSelectionHandler);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*MediaOutputInterface_ResetConverter) (maxon::GenericComponent* this_);
	maxon::Int MediaOutputInterface_ResetConverter_Offset;
	Result<void> (*MediaOutputInterface_SetSelectionHandler) (maxon::GenericComponent* this_, const MediaOutputSelectionHandler& selectionHandler);
	maxon::Int MediaOutputInterface_SetSelectionHandler_Offset;
	const MediaOutputSelectionHandler& (*MediaOutputInterface_GetSelectionHandler) (const maxon::GenericComponent* this_);
	maxon::Int MediaOutputInterface_GetSelectionHandler_Offset;
	Result<SELECTIONHANDLERRESULT> (*MediaOutputInterface_CallSelectionHandler) (maxon::GenericComponent* this_, const MediaStreamRef& stream, const MediaStreamFormat& props);
	maxon::Int MediaOutputInterface_CallSelectionHandler_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputInterface, ResetConverter))
	{
		MediaOutputInterface_ResetConverter = &W::MediaOutputInterface_ResetConverter;
		MediaOutputInterface_ResetConverter_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputInterface, SetSelectionHandler))
	{
		MediaOutputInterface_SetSelectionHandler = &W::MediaOutputInterface_SetSelectionHandler;
		MediaOutputInterface_SetSelectionHandler_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputInterface, GetSelectionHandler))
	{
		MediaOutputInterface_GetSelectionHandler = &W::MediaOutputInterface_GetSelectionHandler;
		MediaOutputInterface_GetSelectionHandler_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputInterface, CallSelectionHandler))
	{
		MediaOutputInterface_CallSelectionHandler = &W::MediaOutputInterface_CallSelectionHandler;
		MediaOutputInterface_CallSelectionHandler_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaOutputInterface, typename MediaConverterInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaOutputInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaOutputInterface::Hxx2
{
	template <typename S> class CWrapper : public MediaConverterInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CallSelectionHandler);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSelectionHandler);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ResetConverter);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetSelectionHandler);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename MediaConverterInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MediaOutputInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaOutputInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> MediaOutputInterface_ResetConverter(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->ResetConverter(); }
		static Result<void> MediaOutputInterface_SetSelectionHandler(maxon::GenericComponent* this_, const MediaOutputSelectionHandler& selectionHandler) { return ((typename S::Implementation*) this_)->SetSelectionHandler(selectionHandler); }
		static const MediaOutputSelectionHandler& MediaOutputInterface_GetSelectionHandler(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetSelectionHandler(); }
		static Result<SELECTIONHANDLERRESULT> MediaOutputInterface_CallSelectionHandler(maxon::GenericComponent* this_, const MediaStreamRef& stream, const MediaStreamFormat& props) { return ((typename S::Implementation*) this_)->CallSelectionHandler(stream, props); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::ResetConverter() -> Result<void>
{
	const MediaOutputInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputInterface, this); return mt_.MediaOutputInterface_ResetConverter((maxon::GenericComponent*) this + mt_.MediaOutputInterface_ResetConverter_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler) -> Result<void>
{
	const MediaOutputInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputInterface, this); return mt_.MediaOutputInterface_SetSelectionHandler((maxon::GenericComponent*) this + mt_.MediaOutputInterface_SetSelectionHandler_Offset, selectionHandler);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::GetSelectionHandler() const -> const MediaOutputSelectionHandler&
{
	const MediaOutputInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputInterface, this); return mt_.MediaOutputInterface_GetSelectionHandler((const maxon::GenericComponent*) this + mt_.MediaOutputInterface_GetSelectionHandler_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props) -> Result<SELECTIONHANDLERRESULT>
{
	const MediaOutputInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputInterface, this); return mt_.MediaOutputInterface_CallSelectionHandler((maxon::GenericComponent*) this + mt_.MediaOutputInterface_CallSelectionHandler_Offset, stream, props);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::Hxx1::Fn<S>::ResetConverter() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaOutputInterface* o_ = (MediaOutputInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputInterface, o_, MediaOutputInterface_ResetConverter) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputInterface, o_); 
	return (mt_.MediaOutputInterface_ResetConverter(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_ResetConverter_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::Hxx1::COWFn<S>::ResetConverter() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaOutputInterface* o_ = (MediaOutputInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputInterface, o_, MediaOutputInterface_ResetConverter) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputInterface, o_); 
	return (mt_.MediaOutputInterface_ResetConverter(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_ResetConverter_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::Hxx1::Fn<S>::SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaOutputInterface* o_ = (MediaOutputInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputInterface, o_, MediaOutputInterface_SetSelectionHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputInterface, o_); 
	return (mt_.MediaOutputInterface_SetSelectionHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_SetSelectionHandler_Offset, selectionHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::Hxx1::COWFn<S>::SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaOutputInterface* o_ = (MediaOutputInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputInterface, o_, MediaOutputInterface_SetSelectionHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputInterface, o_); 
	return (mt_.MediaOutputInterface_SetSelectionHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_SetSelectionHandler_Offset, selectionHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::Hxx1::ConstFn<S>::GetSelectionHandler() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const MediaOutputSelectionHandler&>, const MediaOutputSelectionHandler&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const MediaOutputSelectionHandler&>, const MediaOutputSelectionHandler&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaOutputInterface* o_ = (const MediaOutputInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaOutputInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const MediaOutputSelectionHandler&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputInterface, o_, MediaOutputInterface_GetSelectionHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputInterface, o_); 
	return (mt_.MediaOutputInterface_GetSelectionHandler(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_GetSelectionHandler_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::Hxx1::Fn<S>::CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props) const -> Result<SELECTIONHANDLERRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SELECTIONHANDLERRESULT>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaOutputInterface* o_ = (MediaOutputInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputInterface, o_, MediaOutputInterface_CallSelectionHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputInterface, o_); 
	return (mt_.MediaOutputInterface_CallSelectionHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_CallSelectionHandler_Offset, stream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::Hxx1::COWFn<S>::CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props) -> Result<SELECTIONHANDLERRESULT>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<SELECTIONHANDLERRESULT>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaOutputInterface* o_ = (MediaOutputInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputInterface, o_, MediaOutputInterface_CallSelectionHandler) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputInterface, o_); 
	return (mt_.MediaOutputInterface_CallSelectionHandler(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_CallSelectionHandler_Offset, stream, props));
}
auto MediaOutputInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaOutputInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_output)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaOutputInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaOutputInterface() { new (s_ui_maxon_MediaOutputInterface) maxon::EntityUse(MediaOutputInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_output.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaOutputInterface(MediaOutputInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_output.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MediaOutputTextureInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetOutputTexture);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*MediaOutputTextureInterface_SetOutputTexture) (maxon::GenericComponent* this_, const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass);
	maxon::Int MediaOutputTextureInterface_SetOutputTexture_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputTextureInterface, SetOutputTexture))
	{
		MediaOutputTextureInterface_SetOutputTexture = &W::MediaOutputTextureInterface_SetOutputTexture;
		MediaOutputTextureInterface_SetOutputTexture_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaOutputTextureInterface, typename MediaOutputInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaOutputTextureInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaOutputTextureInterface::Hxx2
{
	template <typename S> class CWrapper : public MediaOutputInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetOutputTexture);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename MediaOutputInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MediaOutputTextureInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaOutputTextureInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> MediaOutputTextureInterface_SetOutputTexture(maxon::GenericComponent* this_, const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass) { return ((typename S::Implementation*) this_)->SetOutputTexture(textureRef, pixelStorageClass); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputTextureInterface::SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass) -> Result<void>
{
	const MediaOutputTextureInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputTextureInterface, this); return mt_.MediaOutputTextureInterface_SetOutputTexture((maxon::GenericComponent*) this + mt_.MediaOutputTextureInterface_SetOutputTexture_Offset, textureRef, pixelStorageClass);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputTextureInterface::Hxx1::Fn<S>::SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaOutputTextureInterface* o_ = (MediaOutputTextureInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputTextureInterface, o_, MediaOutputTextureInterface_SetOutputTexture) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputTextureInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputTextureInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputTextureInterface, o_); 
	return (mt_.MediaOutputTextureInterface_SetOutputTexture(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputTextureInterface_SetOutputTexture_Offset, textureRef, pixelStorageClass));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputTextureInterface::Hxx1::COWFn<S>::SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaOutputTextureInterface* o_ = (MediaOutputTextureInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputTextureInterface, o_, MediaOutputTextureInterface_SetOutputTexture) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputTextureInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputTextureInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputTextureInterface, o_); 
	return (mt_.MediaOutputTextureInterface_SetOutputTexture(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputTextureInterface_SetOutputTexture_Offset, textureRef, pixelStorageClass));
}
auto MediaOutputTextureInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaOutputTextureInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_output)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaOutputTextureInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaOutputTextureInterface() { new (s_ui_maxon_MediaOutputTextureInterface) maxon::EntityUse(MediaOutputTextureInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_output.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaOutputTextureInterface(MediaOutputTextureInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_output.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MediaOutputUrlInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(CheckBitmapSize);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(EditSystemOptions);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetFileFormat);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetOutputUrl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetOutputUrl);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Url (*MediaOutputUrlInterface_GetOutputUrl) (const maxon::GenericComponent* this_);
	maxon::Int MediaOutputUrlInterface_GetOutputUrl_Offset;
	Result<void> (*MediaOutputUrlInterface_SetOutputUrl) (maxon::GenericComponent* this_, const Url& url);
	maxon::Int MediaOutputUrlInterface_SetOutputUrl_Offset;
	const FileFormat& (*MediaOutputUrlInterface_GetFileFormat) (const maxon::GenericComponent* this_);
	maxon::Int MediaOutputUrlInterface_GetFileFormat_Offset;
	Result<Bool> (*MediaOutputUrlInterface_EditSystemOptions) (maxon::GenericComponent* this_, DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle);
	maxon::Int MediaOutputUrlInterface_EditSystemOptions_Offset;
	Result<DrawDimensionInt> (*MediaOutputUrlInterface_CheckBitmapSize) (const maxon::GenericComponent* this_, const DataDictionary& settings, const DrawDimensionInt& bitmapSize);
	maxon::Int MediaOutputUrlInterface_CheckBitmapSize_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputUrlInterface, GetOutputUrl))
	{
		MediaOutputUrlInterface_GetOutputUrl = &W::MediaOutputUrlInterface_GetOutputUrl;
		MediaOutputUrlInterface_GetOutputUrl_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputUrlInterface, SetOutputUrl))
	{
		MediaOutputUrlInterface_SetOutputUrl = &W::MediaOutputUrlInterface_SetOutputUrl;
		MediaOutputUrlInterface_SetOutputUrl_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputUrlInterface, GetFileFormat))
	{
		MediaOutputUrlInterface_GetFileFormat = &W::MediaOutputUrlInterface_GetFileFormat;
		MediaOutputUrlInterface_GetFileFormat_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputUrlInterface, EditSystemOptions))
	{
		MediaOutputUrlInterface_EditSystemOptions = &W::MediaOutputUrlInterface_EditSystemOptions;
		MediaOutputUrlInterface_EditSystemOptions_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputUrlInterface, CheckBitmapSize))
	{
		MediaOutputUrlInterface_CheckBitmapSize = &W::MediaOutputUrlInterface_CheckBitmapSize;
		MediaOutputUrlInterface_CheckBitmapSize_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaOutputUrlInterface, typename MediaOutputInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaOutputUrlInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaOutputUrlInterface::Hxx2
{
	template <typename S> class CWrapper : public MediaOutputInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(CheckBitmapSize);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(EditSystemOptions);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFileFormat);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetOutputUrl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetOutputUrl);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename MediaOutputInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MediaOutputUrlInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaOutputUrlInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Url MediaOutputUrlInterface_GetOutputUrl(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetOutputUrl(); }
		static Result<void> MediaOutputUrlInterface_SetOutputUrl(maxon::GenericComponent* this_, const Url& url) { return ((typename S::Implementation*) this_)->SetOutputUrl(url); }
		static const FileFormat& MediaOutputUrlInterface_GetFileFormat(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetFileFormat(); }
		static Result<Bool> MediaOutputUrlInterface_EditSystemOptions(maxon::GenericComponent* this_, DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle) { return ((typename S::Implementation*) this_)->EditSystemOptions(settings, getParentwindowHandle); }
		static Result<DrawDimensionInt> MediaOutputUrlInterface_CheckBitmapSize(const maxon::GenericComponent* this_, const DataDictionary& settings, const DrawDimensionInt& bitmapSize) { return ((const typename S::Implementation*) this_)->CheckBitmapSize(settings, bitmapSize); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::GetOutputUrl() const -> Url
{
	const MediaOutputUrlInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, this); return mt_.MediaOutputUrlInterface_GetOutputUrl((const maxon::GenericComponent*) this + mt_.MediaOutputUrlInterface_GetOutputUrl_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::SetOutputUrl(const Url& url) -> Result<void>
{
	const MediaOutputUrlInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, this); return mt_.MediaOutputUrlInterface_SetOutputUrl((maxon::GenericComponent*) this + mt_.MediaOutputUrlInterface_SetOutputUrl_Offset, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::GetFileFormat() const -> const FileFormat&
{
	const MediaOutputUrlInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, this); return mt_.MediaOutputUrlInterface_GetFileFormat((const maxon::GenericComponent*) this + mt_.MediaOutputUrlInterface_GetFileFormat_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle) -> Result<Bool>
{
	const MediaOutputUrlInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, this); return mt_.MediaOutputUrlInterface_EditSystemOptions((maxon::GenericComponent*) this + mt_.MediaOutputUrlInterface_EditSystemOptions_Offset, settings, getParentwindowHandle);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::CheckBitmapSize(const DataDictionary& settings, const DrawDimensionInt& bitmapSize) const -> Result<DrawDimensionInt>
{
	const MediaOutputUrlInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, this); return mt_.MediaOutputUrlInterface_CheckBitmapSize((const maxon::GenericComponent*) this + mt_.MediaOutputUrlInterface_CheckBitmapSize_Offset, settings, bitmapSize);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::Hxx1::ConstFn<S>::GetOutputUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaOutputUrlInterface* o_ = (const MediaOutputUrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaOutputUrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputUrlInterface, o_, MediaOutputUrlInterface_GetOutputUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputUrlInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputUrlInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, o_); 
	return (mt_.MediaOutputUrlInterface_GetOutputUrl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_GetOutputUrl_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::Hxx1::Fn<S>::SetOutputUrl(const Url& url) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaOutputUrlInterface* o_ = (MediaOutputUrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputUrlInterface, o_, MediaOutputUrlInterface_SetOutputUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputUrlInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputUrlInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, o_); 
	return (mt_.MediaOutputUrlInterface_SetOutputUrl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_SetOutputUrl_Offset, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::Hxx1::COWFn<S>::SetOutputUrl(const Url& url) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaOutputUrlInterface* o_ = (MediaOutputUrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputUrlInterface, o_, MediaOutputUrlInterface_SetOutputUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputUrlInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputUrlInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, o_); 
	return (mt_.MediaOutputUrlInterface_SetOutputUrl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_SetOutputUrl_Offset, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::Hxx1::ConstFn<S>::GetFileFormat() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const FileFormat&>, const FileFormat&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const FileFormat&>, const FileFormat&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaOutputUrlInterface* o_ = (const MediaOutputUrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaOutputUrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const FileFormat&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputUrlInterface, o_, MediaOutputUrlInterface_GetFileFormat) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputUrlInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputUrlInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, o_); 
	return (mt_.MediaOutputUrlInterface_GetFileFormat(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_GetFileFormat_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::Hxx1::Fn<S>::EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle) const -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaOutputUrlInterface* o_ = (MediaOutputUrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputUrlInterface, o_, MediaOutputUrlInterface_EditSystemOptions) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputUrlInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputUrlInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, o_); 
	return (mt_.MediaOutputUrlInterface_EditSystemOptions(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_EditSystemOptions_Offset, settings, getParentwindowHandle));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::Hxx1::COWFn<S>::EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle) -> Result<Bool>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Bool>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaOutputUrlInterface* o_ = (MediaOutputUrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputUrlInterface, o_, MediaOutputUrlInterface_EditSystemOptions) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputUrlInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputUrlInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, o_); 
	return (mt_.MediaOutputUrlInterface_EditSystemOptions(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_EditSystemOptions_Offset, settings, getParentwindowHandle));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::Hxx1::ConstFn<S>::CheckBitmapSize(const DataDictionary& settings, const DrawDimensionInt& bitmapSize) const -> Result<DrawDimensionInt>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<DrawDimensionInt>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaOutputUrlInterface* o_ = (const MediaOutputUrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaOutputUrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaOutputUrlInterface, o_, MediaOutputUrlInterface_CheckBitmapSize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<MediaOutputUrlInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaOutputUrlInterface>() : PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, o_); 
	return (mt_.MediaOutputUrlInterface_CheckBitmapSize(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_CheckBitmapSize_Offset, settings, bitmapSize));
}
auto MediaOutputUrlInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaOutputUrlInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_output)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaOutputUrlInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaOutputUrlInterface() { new (s_ui_maxon_MediaOutputUrlInterface) maxon::EntityUse(MediaOutputUrlInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_output.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaOutputUrlInterface(MediaOutputUrlInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_output.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

