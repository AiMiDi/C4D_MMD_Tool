
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
	PRIVATE_MAXON_MF_POINTER(MediaOutputInterface_ResetConverter, ResetConverter, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int MediaOutputInterface_ResetConverter_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaOutputInterface_SetSelectionHandler, SetSelectionHandler, true, maxon::GenericComponent,, (Result<void>), const MediaOutputSelectionHandler& selectionHandler);
	maxon::Int MediaOutputInterface_SetSelectionHandler_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaOutputInterface_GetSelectionHandler, GetSelectionHandler, true, maxon::GenericComponent, const, (const MediaOutputSelectionHandler&));
	maxon::Int MediaOutputInterface_GetSelectionHandler_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaOutputInterface_CallSelectionHandler, CallSelectionHandler, true, maxon::GenericComponent,, (Result<SELECTIONHANDLERRESULT>), const MediaStreamRef& stream, const MediaStreamFormat& props);
	maxon::Int MediaOutputInterface_CallSelectionHandler_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputInterface, ResetConverter))
	{
		maxon::Tie(MediaOutputInterface_ResetConverter, MediaOutputInterface_ResetConverter_Offset) = MediaOutputInterface_ResetConverter_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputInterface, SetSelectionHandler))
	{
		maxon::Tie(MediaOutputInterface_SetSelectionHandler, MediaOutputInterface_SetSelectionHandler_Offset) = MediaOutputInterface_SetSelectionHandler_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputInterface, GetSelectionHandler))
	{
		maxon::Tie(MediaOutputInterface_GetSelectionHandler, MediaOutputInterface_GetSelectionHandler_Offset) = MediaOutputInterface_GetSelectionHandler_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputInterface, CallSelectionHandler))
	{
		maxon::Tie(MediaOutputInterface_CallSelectionHandler, MediaOutputInterface_CallSelectionHandler_Offset) = MediaOutputInterface_CallSelectionHandler_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaOutputInterface, typename MediaConverterInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaOutputInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaOutputInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MediaOutputInterface_ResetConverter, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ResetConverter(); }
		PRIVATE_MAXON_MF_WRAPPER(MediaOutputInterface_SetSelectionHandler, maxon::GenericComponent,, (Result<void>), const MediaOutputSelectionHandler& selectionHandler) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetSelectionHandler(selectionHandler); }
		PRIVATE_MAXON_MF_WRAPPER(MediaOutputInterface_GetSelectionHandler, maxon::GenericComponent, const, (const MediaOutputSelectionHandler&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetSelectionHandler(); }
		PRIVATE_MAXON_MF_WRAPPER(MediaOutputInterface_CallSelectionHandler, maxon::GenericComponent,, (Result<SELECTIONHANDLERRESULT>), const MediaStreamRef& stream, const MediaStreamFormat& props) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->CallSelectionHandler(stream, props); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::ResetConverter() -> Result<void>
{
	const MediaOutputInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaOutputInterface_ResetConverter_Offset), mt_.MediaOutputInterface_ResetConverter);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler) -> Result<void>
{
	const MediaOutputInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaOutputInterface_SetSelectionHandler_Offset), mt_.MediaOutputInterface_SetSelectionHandler, selectionHandler);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::GetSelectionHandler() const -> const MediaOutputSelectionHandler&
{
	const MediaOutputInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MediaOutputInterface_GetSelectionHandler_Offset), mt_.MediaOutputInterface_GetSelectionHandler);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props) -> Result<SELECTIONHANDLERRESULT>
{
	const MediaOutputInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaOutputInterface_CallSelectionHandler_Offset), mt_.MediaOutputInterface_CallSelectionHandler, stream, props);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::Hxx1::Fn<S>::ResetConverter() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaOutputInterface_ResetConverter); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_ResetConverter_Offset), mt_.MediaOutputInterface_ResetConverter));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::Hxx1::COWFn<S>::ResetConverter() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaOutputInterface_ResetConverter); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_ResetConverter_Offset), mt_.MediaOutputInterface_ResetConverter));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::Hxx1::Fn<S>::SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaOutputInterface_SetSelectionHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_SetSelectionHandler_Offset), mt_.MediaOutputInterface_SetSelectionHandler, selectionHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::Hxx1::COWFn<S>::SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaOutputInterface_SetSelectionHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_SetSelectionHandler_Offset), mt_.MediaOutputInterface_SetSelectionHandler, selectionHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::Hxx1::ConstFn<S>::GetSelectionHandler() const -> HXXADDRET2(const MediaOutputSelectionHandler&)
{
	HXXRETURN0(HXXADDRET2(const MediaOutputSelectionHandler&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const MediaOutputSelectionHandler&)) HXXTABLE(MediaOutputInterface_GetSelectionHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_GetSelectionHandler_Offset), mt_.MediaOutputInterface_GetSelectionHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::Hxx1::Fn<S>::CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props) const -> Result<SELECTIONHANDLERRESULT>
{
	HXXRETURN0(Result<SELECTIONHANDLERRESULT>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaOutputInterface_CallSelectionHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_CallSelectionHandler_Offset), mt_.MediaOutputInterface_CallSelectionHandler, stream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputInterface::Hxx1::COWFn<S>::CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props) -> Result<SELECTIONHANDLERRESULT>
{
	HXXRETURN0(Result<SELECTIONHANDLERRESULT>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaOutputInterface_CallSelectionHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputInterface_CallSelectionHandler_Offset), mt_.MediaOutputInterface_CallSelectionHandler, stream, props));
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
	PRIVATE_MAXON_MF_POINTER(MediaOutputTextureInterface_SetOutputTexture, SetOutputTexture, true, maxon::GenericComponent,, (Result<void>), const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass);
	maxon::Int MediaOutputTextureInterface_SetOutputTexture_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputTextureInterface, SetOutputTexture))
	{
		maxon::Tie(MediaOutputTextureInterface_SetOutputTexture, MediaOutputTextureInterface_SetOutputTexture_Offset) = MediaOutputTextureInterface_SetOutputTexture_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaOutputTextureInterface, typename MediaOutputInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaOutputTextureInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaOutputTextureInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MediaOutputTextureInterface_SetOutputTexture, maxon::GenericComponent,, (Result<void>), const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetOutputTexture(textureRef, pixelStorageClass); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputTextureInterface::SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass) -> Result<void>
{
	const MediaOutputTextureInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputTextureInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaOutputTextureInterface_SetOutputTexture_Offset), mt_.MediaOutputTextureInterface_SetOutputTexture, textureRef, pixelStorageClass);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputTextureInterface::Hxx1::Fn<S>::SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaOutputTextureInterface_SetOutputTexture); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputTextureInterface_SetOutputTexture_Offset), mt_.MediaOutputTextureInterface_SetOutputTexture, textureRef, pixelStorageClass));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputTextureInterface::Hxx1::COWFn<S>::SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaOutputTextureInterface_SetOutputTexture); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputTextureInterface_SetOutputTexture_Offset), mt_.MediaOutputTextureInterface_SetOutputTexture, textureRef, pixelStorageClass));
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
	PRIVATE_MAXON_MF_POINTER(MediaOutputUrlInterface_GetOutputUrl, GetOutputUrl, true, maxon::GenericComponent, const, (Url));
	maxon::Int MediaOutputUrlInterface_GetOutputUrl_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaOutputUrlInterface_SetOutputUrl, SetOutputUrl, true, maxon::GenericComponent,, (Result<void>), const Url& url);
	maxon::Int MediaOutputUrlInterface_SetOutputUrl_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaOutputUrlInterface_GetFileFormat, GetFileFormat, true, maxon::GenericComponent, const, (const FileFormat&));
	maxon::Int MediaOutputUrlInterface_GetFileFormat_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaOutputUrlInterface_EditSystemOptions, EditSystemOptions, true, maxon::GenericComponent,, (Result<Bool>), DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle);
	maxon::Int MediaOutputUrlInterface_EditSystemOptions_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaOutputUrlInterface_CheckBitmapSize, CheckBitmapSize, true, maxon::GenericComponent, const, (Result<DrawDimensionInt>), const DataDictionary& settings, const DrawDimensionInt& bitmapSize);
	maxon::Int MediaOutputUrlInterface_CheckBitmapSize_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputUrlInterface, GetOutputUrl))
	{
		maxon::Tie(MediaOutputUrlInterface_GetOutputUrl, MediaOutputUrlInterface_GetOutputUrl_Offset) = MediaOutputUrlInterface_GetOutputUrl_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputUrlInterface, SetOutputUrl))
	{
		maxon::Tie(MediaOutputUrlInterface_SetOutputUrl, MediaOutputUrlInterface_SetOutputUrl_Offset) = MediaOutputUrlInterface_SetOutputUrl_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputUrlInterface, GetFileFormat))
	{
		maxon::Tie(MediaOutputUrlInterface_GetFileFormat, MediaOutputUrlInterface_GetFileFormat_Offset) = MediaOutputUrlInterface_GetFileFormat_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputUrlInterface, EditSystemOptions))
	{
		maxon::Tie(MediaOutputUrlInterface_EditSystemOptions, MediaOutputUrlInterface_EditSystemOptions_Offset) = MediaOutputUrlInterface_EditSystemOptions_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaOutputUrlInterface, CheckBitmapSize))
	{
		maxon::Tie(MediaOutputUrlInterface_CheckBitmapSize, MediaOutputUrlInterface_CheckBitmapSize_Offset) = MediaOutputUrlInterface_CheckBitmapSize_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaOutputUrlInterface, typename MediaOutputInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaOutputUrlInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaOutputUrlInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MediaOutputUrlInterface_GetOutputUrl, maxon::GenericComponent, const, (Url)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetOutputUrl(); }
		PRIVATE_MAXON_MF_WRAPPER(MediaOutputUrlInterface_SetOutputUrl, maxon::GenericComponent,, (Result<void>), const Url& url) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetOutputUrl(url); }
		PRIVATE_MAXON_MF_WRAPPER(MediaOutputUrlInterface_GetFileFormat, maxon::GenericComponent, const, (const FileFormat&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetFileFormat(); }
		PRIVATE_MAXON_MF_WRAPPER(MediaOutputUrlInterface_EditSystemOptions, maxon::GenericComponent,, (Result<Bool>), DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->EditSystemOptions(settings, getParentwindowHandle); }
		PRIVATE_MAXON_MF_WRAPPER(MediaOutputUrlInterface_CheckBitmapSize, maxon::GenericComponent, const, (Result<DrawDimensionInt>), const DataDictionary& settings, const DrawDimensionInt& bitmapSize) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->CheckBitmapSize(settings, bitmapSize); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::GetOutputUrl() const -> Url
{
	const MediaOutputUrlInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MediaOutputUrlInterface_GetOutputUrl_Offset), mt_.MediaOutputUrlInterface_GetOutputUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::SetOutputUrl(const Url& url) -> Result<void>
{
	const MediaOutputUrlInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaOutputUrlInterface_SetOutputUrl_Offset), mt_.MediaOutputUrlInterface_SetOutputUrl, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::GetFileFormat() const -> const FileFormat&
{
	const MediaOutputUrlInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MediaOutputUrlInterface_GetFileFormat_Offset), mt_.MediaOutputUrlInterface_GetFileFormat);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle) -> Result<Bool>
{
	const MediaOutputUrlInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaOutputUrlInterface_EditSystemOptions_Offset), mt_.MediaOutputUrlInterface_EditSystemOptions, settings, getParentwindowHandle);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::CheckBitmapSize(const DataDictionary& settings, const DrawDimensionInt& bitmapSize) const -> Result<DrawDimensionInt>
{
	const MediaOutputUrlInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaOutputUrlInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MediaOutputUrlInterface_CheckBitmapSize_Offset), mt_.MediaOutputUrlInterface_CheckBitmapSize, settings, bitmapSize);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::Hxx1::ConstFn<S>::GetOutputUrl() const -> HXXADDRET2(Url)
{
	HXXRETURN0(HXXADDRET2(Url)); HXXRES; HXXCONST(HXXRET3(NULLPTR, Url)) HXXTABLE(MediaOutputUrlInterface_GetOutputUrl); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_GetOutputUrl_Offset), mt_.MediaOutputUrlInterface_GetOutputUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::Hxx1::Fn<S>::SetOutputUrl(const Url& url) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaOutputUrlInterface_SetOutputUrl); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_SetOutputUrl_Offset), mt_.MediaOutputUrlInterface_SetOutputUrl, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::Hxx1::COWFn<S>::SetOutputUrl(const Url& url) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaOutputUrlInterface_SetOutputUrl); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_SetOutputUrl_Offset), mt_.MediaOutputUrlInterface_SetOutputUrl, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::Hxx1::ConstFn<S>::GetFileFormat() const -> HXXADDRET2(const FileFormat&)
{
	HXXRETURN0(HXXADDRET2(const FileFormat&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const FileFormat&)) HXXTABLE(MediaOutputUrlInterface_GetFileFormat); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_GetFileFormat_Offset), mt_.MediaOutputUrlInterface_GetFileFormat));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::Hxx1::Fn<S>::EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle) const -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaOutputUrlInterface_EditSystemOptions); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_EditSystemOptions_Offset), mt_.MediaOutputUrlInterface_EditSystemOptions, settings, getParentwindowHandle));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::Hxx1::COWFn<S>::EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle) -> Result<Bool>
{
	HXXRETURN0(Result<Bool>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaOutputUrlInterface_EditSystemOptions); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_EditSystemOptions_Offset), mt_.MediaOutputUrlInterface_EditSystemOptions, settings, getParentwindowHandle));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaOutputUrlInterface::Hxx1::ConstFn<S>::CheckBitmapSize(const DataDictionary& settings, const DrawDimensionInt& bitmapSize) const -> Result<DrawDimensionInt>
{
	HXXRETURN0(Result<DrawDimensionInt>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(MediaOutputUrlInterface_CheckBitmapSize); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaOutputUrlInterface_CheckBitmapSize_Offset), mt_.MediaOutputUrlInterface_CheckBitmapSize, settings, bitmapSize));
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

