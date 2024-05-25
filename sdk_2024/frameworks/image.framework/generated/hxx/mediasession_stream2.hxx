
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
	PRIVATE_MAXON_MF_POINTER(MediaStreamInterface_GetFormats, GetFormats, true, maxon::GenericComponent, const, (Result<BaseArray<Data>>));
	maxon::Int MediaStreamInterface_GetFormats_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamInterface_GetFormat, GetFormat, true, maxon::GenericComponent, const, (MediaStreamFormat), const Data& formatId);
	maxon::Int MediaStreamInterface_GetFormat_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamInterface_GetSelectedFormat, GetSelectedFormat, true, maxon::GenericComponent, const, (const Data&));
	maxon::Int MediaStreamInterface_GetSelectedFormat_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamInterface_SetSelectedFormat, SetSelectedFormat, true, maxon::GenericComponent,, (Result<void>), const Data& formatId);
	maxon::Int MediaStreamInterface_SetSelectedFormat_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamInterface_AddFormat, AddFormat, true, maxon::GenericComponent,, (Result<void>), const Data& formatId, const MediaStreamFormat& ref);
	maxon::Int MediaStreamInterface_AddFormat_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamInterface_SubscribeStream, SubscribeStream, true, maxon::GenericComponent,, (Result<void>), const Data& formatId);
	maxon::Int MediaStreamInterface_SubscribeStream_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamInterface_UnsubscribeStream, UnsubscribeStream, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int MediaStreamInterface_UnsubscribeStream_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamInterface_IsSubscribed, IsSubscribed, true, maxon::GenericComponent, const, (Bool));
	maxon::Int MediaStreamInterface_IsSubscribed_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, GetFormats))
	{
		maxon::Tie(MediaStreamInterface_GetFormats, MediaStreamInterface_GetFormats_Offset) = MediaStreamInterface_GetFormats_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, GetFormat))
	{
		maxon::Tie(MediaStreamInterface_GetFormat, MediaStreamInterface_GetFormat_Offset) = MediaStreamInterface_GetFormat_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, GetSelectedFormat))
	{
		maxon::Tie(MediaStreamInterface_GetSelectedFormat, MediaStreamInterface_GetSelectedFormat_Offset) = MediaStreamInterface_GetSelectedFormat_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, SetSelectedFormat))
	{
		maxon::Tie(MediaStreamInterface_SetSelectedFormat, MediaStreamInterface_SetSelectedFormat_Offset) = MediaStreamInterface_SetSelectedFormat_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, AddFormat))
	{
		maxon::Tie(MediaStreamInterface_AddFormat, MediaStreamInterface_AddFormat_Offset) = MediaStreamInterface_AddFormat_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, SubscribeStream))
	{
		maxon::Tie(MediaStreamInterface_SubscribeStream, MediaStreamInterface_SubscribeStream_Offset) = MediaStreamInterface_SubscribeStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, UnsubscribeStream))
	{
		maxon::Tie(MediaStreamInterface_UnsubscribeStream, MediaStreamInterface_UnsubscribeStream_Offset) = MediaStreamInterface_UnsubscribeStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamInterface, IsSubscribed))
	{
		maxon::Tie(MediaStreamInterface_IsSubscribed, MediaStreamInterface_IsSubscribed_Offset) = MediaStreamInterface_IsSubscribed_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaStreamInterface, typename HierarchyObjectInterface::MTable::template CombinedMTable<typename MediaBaseInterface::MTable::template CombinedMTable<S>>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset) && Super1::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaStreamInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamInterface_GetFormats, maxon::GenericComponent, const, (Result<BaseArray<Data>>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetFormats(); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamInterface_GetFormat, maxon::GenericComponent, const, (MediaStreamFormat), const Data& formatId) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetFormat(formatId); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamInterface_GetSelectedFormat, maxon::GenericComponent, const, (const Data&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetSelectedFormat(); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamInterface_SetSelectedFormat, maxon::GenericComponent,, (Result<void>), const Data& formatId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetSelectedFormat(formatId); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamInterface_AddFormat, maxon::GenericComponent,, (Result<void>), const Data& formatId, const MediaStreamFormat& ref) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->AddFormat(formatId, ref); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamInterface_SubscribeStream, maxon::GenericComponent,, (Result<void>), const Data& formatId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SubscribeStream(formatId); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamInterface_UnsubscribeStream, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->UnsubscribeStream(); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamInterface_IsSubscribed, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IsSubscribed(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::GetFormats() const -> Result<BaseArray<Data>>
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MediaStreamInterface_GetFormats_Offset), mt_.MediaStreamInterface_GetFormats);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::GetFormat(const Data& formatId) const -> MediaStreamFormat
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MediaStreamInterface_GetFormat_Offset), mt_.MediaStreamInterface_GetFormat, formatId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::GetSelectedFormat() const -> const Data&
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MediaStreamInterface_GetSelectedFormat_Offset), mt_.MediaStreamInterface_GetSelectedFormat);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::SetSelectedFormat(const Data& formatId) -> Result<void>
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamInterface_SetSelectedFormat_Offset), mt_.MediaStreamInterface_SetSelectedFormat, formatId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::AddFormat(const Data& formatId, const MediaStreamFormat& ref) -> Result<void>
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamInterface_AddFormat_Offset), mt_.MediaStreamInterface_AddFormat, formatId, ref);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::SubscribeStream(const Data& formatId) -> Result<void>
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamInterface_SubscribeStream_Offset), mt_.MediaStreamInterface_SubscribeStream, formatId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::UnsubscribeStream() -> Result<void>
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamInterface_UnsubscribeStream_Offset), mt_.MediaStreamInterface_UnsubscribeStream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::IsSubscribed() const -> Bool
{
	const MediaStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MediaStreamInterface_IsSubscribed_Offset), mt_.MediaStreamInterface_IsSubscribed);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::ConstFn<S>::GetFormats() const -> Result<BaseArray<Data>>
{
	HXXRETURN0(Result<BaseArray<Data>>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(MediaStreamInterface_GetFormats); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_GetFormats_Offset), mt_.MediaStreamInterface_GetFormats));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::ConstFn<S>::GetFormat(const Data& formatId) const -> HXXADDRET2(MediaStreamFormat)
{
	HXXRETURN0(HXXADDRET2(MediaStreamFormat)); HXXRES; HXXCONST(HXXRET3(NULLPTR, MediaStreamFormat)) HXXTABLE(MediaStreamInterface_GetFormat); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_GetFormat_Offset), mt_.MediaStreamInterface_GetFormat, formatId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::ConstFn<S>::GetSelectedFormat() const -> HXXADDRET2(const Data&)
{
	HXXRETURN0(HXXADDRET2(const Data&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const Data&)) HXXTABLE(MediaStreamInterface_GetSelectedFormat); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_GetSelectedFormat_Offset), mt_.MediaStreamInterface_GetSelectedFormat));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::Fn<S>::SetSelectedFormat(const Data& formatId) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamInterface_SetSelectedFormat); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_SetSelectedFormat_Offset), mt_.MediaStreamInterface_SetSelectedFormat, formatId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::COWFn<S>::SetSelectedFormat(const Data& formatId) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamInterface_SetSelectedFormat); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_SetSelectedFormat_Offset), mt_.MediaStreamInterface_SetSelectedFormat, formatId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::Fn<S>::AddFormat(const Data& formatId, const MediaStreamFormat& ref) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamInterface_AddFormat); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_AddFormat_Offset), mt_.MediaStreamInterface_AddFormat, formatId, ref));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::COWFn<S>::AddFormat(const Data& formatId, const MediaStreamFormat& ref) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamInterface_AddFormat); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_AddFormat_Offset), mt_.MediaStreamInterface_AddFormat, formatId, ref));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::Fn<S>::SubscribeStream(const Data& formatId) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamInterface_SubscribeStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_SubscribeStream_Offset), mt_.MediaStreamInterface_SubscribeStream, formatId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::COWFn<S>::SubscribeStream(const Data& formatId) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamInterface_SubscribeStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_SubscribeStream_Offset), mt_.MediaStreamInterface_SubscribeStream, formatId));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::Fn<S>::UnsubscribeStream() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamInterface_UnsubscribeStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_UnsubscribeStream_Offset), mt_.MediaStreamInterface_UnsubscribeStream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::COWFn<S>::UnsubscribeStream() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamInterface_UnsubscribeStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_UnsubscribeStream_Offset), mt_.MediaStreamInterface_UnsubscribeStream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamInterface::Hxx1::ConstFn<S>::IsSubscribed() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) HXXTABLE(MediaStreamInterface_IsSubscribed); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaStreamInterface_IsSubscribed_Offset), mt_.MediaStreamInterface_IsSubscribed));
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
	PRIVATE_MAXON_MF_POINTER(MediaStreamExifDataInterface_SetCallbackHandler, SetCallbackHandler, true, maxon::GenericComponent,, (Result<void>), const ExifDataHandler& handleExifData);
	maxon::Int MediaStreamExifDataInterface_SetCallbackHandler_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamExifDataInterface_HandleExifData, HandleExifData, true, maxon::GenericComponent,, (Result<void>), const ExifRef& exifData);
	maxon::Int MediaStreamExifDataInterface_HandleExifData_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamExifDataInterface_FinishStream, FinishStream, true, maxon::GenericComponent,, (Result<void>), const MediaStreamProperties& props);
	maxon::Int MediaStreamExifDataInterface_FinishStream_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamExifDataInterface, SetCallbackHandler))
	{
		maxon::Tie(MediaStreamExifDataInterface_SetCallbackHandler, MediaStreamExifDataInterface_SetCallbackHandler_Offset) = MediaStreamExifDataInterface_SetCallbackHandler_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamExifDataInterface, HandleExifData))
	{
		maxon::Tie(MediaStreamExifDataInterface_HandleExifData, MediaStreamExifDataInterface_HandleExifData_Offset) = MediaStreamExifDataInterface_HandleExifData_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamExifDataInterface, FinishStream))
	{
		maxon::Tie(MediaStreamExifDataInterface_FinishStream, MediaStreamExifDataInterface_FinishStream_Offset) = MediaStreamExifDataInterface_FinishStream_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaStreamExifDataInterface, typename MediaStreamInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaStreamExifDataInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamExifDataInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamExifDataInterface_SetCallbackHandler, maxon::GenericComponent,, (Result<void>), const ExifDataHandler& handleExifData) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetCallbackHandler(handleExifData); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamExifDataInterface_HandleExifData, maxon::GenericComponent,, (Result<void>), const ExifRef& exifData) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->HandleExifData(exifData); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamExifDataInterface_FinishStream, maxon::GenericComponent,, (Result<void>), const MediaStreamProperties& props) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->FinishStream(props); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::SetCallbackHandler(const ExifDataHandler& handleExifData) -> Result<void>
{
	const MediaStreamExifDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamExifDataInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamExifDataInterface_SetCallbackHandler_Offset), mt_.MediaStreamExifDataInterface_SetCallbackHandler, handleExifData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::HandleExifData(const ExifRef& exifData) -> Result<void>
{
	const MediaStreamExifDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamExifDataInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamExifDataInterface_HandleExifData_Offset), mt_.MediaStreamExifDataInterface_HandleExifData, exifData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamExifDataInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamExifDataInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamExifDataInterface_FinishStream_Offset), mt_.MediaStreamExifDataInterface_FinishStream, props);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::Hxx1::Fn<S>::SetCallbackHandler(const ExifDataHandler& handleExifData) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamExifDataInterface_SetCallbackHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamExifDataInterface_SetCallbackHandler_Offset), mt_.MediaStreamExifDataInterface_SetCallbackHandler, handleExifData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::Hxx1::COWFn<S>::SetCallbackHandler(const ExifDataHandler& handleExifData) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamExifDataInterface_SetCallbackHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamExifDataInterface_SetCallbackHandler_Offset), mt_.MediaStreamExifDataInterface_SetCallbackHandler, handleExifData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::Hxx1::Fn<S>::HandleExifData(const ExifRef& exifData) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamExifDataInterface_HandleExifData); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamExifDataInterface_HandleExifData_Offset), mt_.MediaStreamExifDataInterface_HandleExifData, exifData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::Hxx1::COWFn<S>::HandleExifData(const ExifRef& exifData) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamExifDataInterface_HandleExifData); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamExifDataInterface_HandleExifData_Offset), mt_.MediaStreamExifDataInterface_HandleExifData, exifData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::Hxx1::Fn<S>::FinishStream(const MediaStreamProperties& props) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamExifDataInterface_FinishStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamExifDataInterface_FinishStream_Offset), mt_.MediaStreamExifDataInterface_FinishStream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamExifDataInterface::Hxx1::COWFn<S>::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamExifDataInterface_FinishStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamExifDataInterface_FinishStream_Offset), mt_.MediaStreamExifDataInterface_FinishStream, props));
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
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaStreamImageBaseInterface, typename MediaStreamInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
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
	PRIVATE_MAXON_MF_POINTER(MediaStreamImageDataImportInterface_SetCallbackHandler, SetCallbackHandler, true, maxon::GenericComponent,, (Result<void>), const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler);
	maxon::Int MediaStreamImageDataImportInterface_SetCallbackHandler_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamImageDataImportInterface_InitStream, InitStream, true, maxon::GenericComponent,, (Result<void>), const MediaStreamProperties& props);
	maxon::Int MediaStreamImageDataImportInterface_InitStream_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamImageDataImportInterface_SetPixelStream, SetPixelStream, true, maxon::GenericComponent,, (Result<SetPixelHandlerStruct>), const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags);
	maxon::Int MediaStreamImageDataImportInterface_SetPixelStream_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamImageDataImportInterface_FinishStream, FinishStream, true, maxon::GenericComponent,, (Result<void>), const MediaStreamProperties& props);
	maxon::Int MediaStreamImageDataImportInterface_FinishStream_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataImportInterface, SetCallbackHandler))
	{
		maxon::Tie(MediaStreamImageDataImportInterface_SetCallbackHandler, MediaStreamImageDataImportInterface_SetCallbackHandler_Offset) = MediaStreamImageDataImportInterface_SetCallbackHandler_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataImportInterface, InitStream))
	{
		maxon::Tie(MediaStreamImageDataImportInterface_InitStream, MediaStreamImageDataImportInterface_InitStream_Offset) = MediaStreamImageDataImportInterface_InitStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataImportInterface, SetPixelStream))
	{
		maxon::Tie(MediaStreamImageDataImportInterface_SetPixelStream, MediaStreamImageDataImportInterface_SetPixelStream_Offset) = MediaStreamImageDataImportInterface_SetPixelStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataImportInterface, FinishStream))
	{
		maxon::Tie(MediaStreamImageDataImportInterface_FinishStream, MediaStreamImageDataImportInterface_FinishStream_Offset) = MediaStreamImageDataImportInterface_FinishStream_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaStreamImageDataImportInterface, typename MediaStreamImageBaseInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaStreamImageDataImportInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamImageDataImportInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamImageDataImportInterface_SetCallbackHandler, maxon::GenericComponent,, (Result<void>), const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetCallbackHandler(initHandler, setPixelHandler, finishHandler); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamImageDataImportInterface_InitStream, maxon::GenericComponent,, (Result<void>), const MediaStreamProperties& props) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InitStream(props); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamImageDataImportInterface_SetPixelStream, maxon::GenericComponent,, (Result<SetPixelHandlerStruct>), const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetPixelStream(props, srcChannelOffsets, setPixelFlags); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamImageDataImportInterface_FinishStream, maxon::GenericComponent,, (Result<void>), const MediaStreamProperties& props) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->FinishStream(props); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::SetCallbackHandler(const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler) -> Result<void>
{
	const MediaStreamImageDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamImageDataImportInterface_SetCallbackHandler_Offset), mt_.MediaStreamImageDataImportInterface_SetCallbackHandler, initHandler, setPixelHandler, finishHandler);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::InitStream(const MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamImageDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamImageDataImportInterface_InitStream_Offset), mt_.MediaStreamImageDataImportInterface_InitStream, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::SetPixelStream(const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags) -> Result<SetPixelHandlerStruct>
{
	const MediaStreamImageDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamImageDataImportInterface_SetPixelStream_Offset), mt_.MediaStreamImageDataImportInterface_SetPixelStream, props, srcChannelOffsets, setPixelFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamImageDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataImportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamImageDataImportInterface_FinishStream_Offset), mt_.MediaStreamImageDataImportInterface_FinishStream, props);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::Fn<S>::SetCallbackHandler(const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamImageDataImportInterface_SetCallbackHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_SetCallbackHandler_Offset), mt_.MediaStreamImageDataImportInterface_SetCallbackHandler, initHandler, setPixelHandler, finishHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::COWFn<S>::SetCallbackHandler(const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamImageDataImportInterface_SetCallbackHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_SetCallbackHandler_Offset), mt_.MediaStreamImageDataImportInterface_SetCallbackHandler, initHandler, setPixelHandler, finishHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::Fn<S>::InitStream(const MediaStreamProperties& props) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamImageDataImportInterface_InitStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_InitStream_Offset), mt_.MediaStreamImageDataImportInterface_InitStream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::COWFn<S>::InitStream(const MediaStreamProperties& props) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamImageDataImportInterface_InitStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_InitStream_Offset), mt_.MediaStreamImageDataImportInterface_InitStream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::Fn<S>::SetPixelStream(const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags) const -> Result<SetPixelHandlerStruct>
{
	HXXRETURN0(Result<SetPixelHandlerStruct>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamImageDataImportInterface_SetPixelStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_SetPixelStream_Offset), mt_.MediaStreamImageDataImportInterface_SetPixelStream, props, srcChannelOffsets, setPixelFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::COWFn<S>::SetPixelStream(const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags) -> Result<SetPixelHandlerStruct>
{
	HXXRETURN0(Result<SetPixelHandlerStruct>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamImageDataImportInterface_SetPixelStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_SetPixelStream_Offset), mt_.MediaStreamImageDataImportInterface_SetPixelStream, props, srcChannelOffsets, setPixelFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::Fn<S>::FinishStream(const MediaStreamProperties& props) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamImageDataImportInterface_FinishStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_FinishStream_Offset), mt_.MediaStreamImageDataImportInterface_FinishStream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataImportInterface::Hxx1::COWFn<S>::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamImageDataImportInterface_FinishStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataImportInterface_FinishStream_Offset), mt_.MediaStreamImageDataImportInterface_FinishStream, props));
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
	PRIVATE_MAXON_MF_POINTER(MediaStreamImageDataExportInterface_SetCallbackHandler, SetCallbackHandler, true, maxon::GenericComponent,, (Result<void>), const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler);
	maxon::Int MediaStreamImageDataExportInterface_SetCallbackHandler_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamImageDataExportInterface_InitStream, InitStream, true, maxon::GenericComponent,, (Result<void>), MediaStreamProperties& props);
	maxon::Int MediaStreamImageDataExportInterface_InitStream_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamImageDataExportInterface_GetPixelStream, GetPixelStream, true, maxon::GenericComponent,, (Result<GetPixelHandlerStruct>), const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags);
	maxon::Int MediaStreamImageDataExportInterface_GetPixelStream_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamImageDataExportInterface_FinishStream, FinishStream, true, maxon::GenericComponent,, (Result<void>), const MediaStreamProperties& props);
	maxon::Int MediaStreamImageDataExportInterface_FinishStream_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataExportInterface, SetCallbackHandler))
	{
		maxon::Tie(MediaStreamImageDataExportInterface_SetCallbackHandler, MediaStreamImageDataExportInterface_SetCallbackHandler_Offset) = MediaStreamImageDataExportInterface_SetCallbackHandler_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataExportInterface, InitStream))
	{
		maxon::Tie(MediaStreamImageDataExportInterface_InitStream, MediaStreamImageDataExportInterface_InitStream_Offset) = MediaStreamImageDataExportInterface_InitStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataExportInterface, GetPixelStream))
	{
		maxon::Tie(MediaStreamImageDataExportInterface_GetPixelStream, MediaStreamImageDataExportInterface_GetPixelStream_Offset) = MediaStreamImageDataExportInterface_GetPixelStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataExportInterface, FinishStream))
	{
		maxon::Tie(MediaStreamImageDataExportInterface_FinishStream, MediaStreamImageDataExportInterface_FinishStream_Offset) = MediaStreamImageDataExportInterface_FinishStream_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaStreamImageDataExportInterface, typename MediaStreamImageBaseInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaStreamImageDataExportInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamImageDataExportInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamImageDataExportInterface_SetCallbackHandler, maxon::GenericComponent,, (Result<void>), const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetCallbackHandler(initHandler, getPixelHandler, finishHandler); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamImageDataExportInterface_InitStream, maxon::GenericComponent,, (Result<void>), MediaStreamProperties& props) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InitStream(props); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamImageDataExportInterface_GetPixelStream, maxon::GenericComponent,, (Result<GetPixelHandlerStruct>), const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetPixelStream(props, dstFormat, channelOffsets, dstColorProfile, flags); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamImageDataExportInterface_FinishStream, maxon::GenericComponent,, (Result<void>), const MediaStreamProperties& props) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->FinishStream(props); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::SetCallbackHandler(const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler) -> Result<void>
{
	const MediaStreamImageDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamImageDataExportInterface_SetCallbackHandler_Offset), mt_.MediaStreamImageDataExportInterface_SetCallbackHandler, initHandler, getPixelHandler, finishHandler);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::InitStream(MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamImageDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamImageDataExportInterface_InitStream_Offset), mt_.MediaStreamImageDataExportInterface_InitStream, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::GetPixelStream(const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) -> Result<GetPixelHandlerStruct>
{
	const MediaStreamImageDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamImageDataExportInterface_GetPixelStream_Offset), mt_.MediaStreamImageDataExportInterface_GetPixelStream, props, dstFormat, channelOffsets, dstColorProfile, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamImageDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataExportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamImageDataExportInterface_FinishStream_Offset), mt_.MediaStreamImageDataExportInterface_FinishStream, props);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::Fn<S>::SetCallbackHandler(const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamImageDataExportInterface_SetCallbackHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_SetCallbackHandler_Offset), mt_.MediaStreamImageDataExportInterface_SetCallbackHandler, initHandler, getPixelHandler, finishHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::COWFn<S>::SetCallbackHandler(const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamImageDataExportInterface_SetCallbackHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_SetCallbackHandler_Offset), mt_.MediaStreamImageDataExportInterface_SetCallbackHandler, initHandler, getPixelHandler, finishHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::Fn<S>::InitStream(MediaStreamProperties& props) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamImageDataExportInterface_InitStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_InitStream_Offset), mt_.MediaStreamImageDataExportInterface_InitStream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::COWFn<S>::InitStream(MediaStreamProperties& props) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamImageDataExportInterface_InitStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_InitStream_Offset), mt_.MediaStreamImageDataExportInterface_InitStream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::Fn<S>::GetPixelStream(const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const -> Result<GetPixelHandlerStruct>
{
	HXXRETURN0(Result<GetPixelHandlerStruct>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamImageDataExportInterface_GetPixelStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_GetPixelStream_Offset), mt_.MediaStreamImageDataExportInterface_GetPixelStream, props, dstFormat, channelOffsets, dstColorProfile, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::COWFn<S>::GetPixelStream(const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) -> Result<GetPixelHandlerStruct>
{
	HXXRETURN0(Result<GetPixelHandlerStruct>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamImageDataExportInterface_GetPixelStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_GetPixelStream_Offset), mt_.MediaStreamImageDataExportInterface_GetPixelStream, props, dstFormat, channelOffsets, dstColorProfile, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::Fn<S>::FinishStream(const MediaStreamProperties& props) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamImageDataExportInterface_FinishStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_FinishStream_Offset), mt_.MediaStreamImageDataExportInterface_FinishStream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataExportInterface::Hxx1::COWFn<S>::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamImageDataExportInterface_FinishStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataExportInterface_FinishStream_Offset), mt_.MediaStreamImageDataExportInterface_FinishStream, props));
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
	PRIVATE_MAXON_MF_POINTER(MediaStreamImageDataForwardImportInterface_SetSourceStream, SetSourceStream, true, maxon::GenericComponent,, (Result<void>), const MediaStreamImageDataImportRef& sourceStream);
	maxon::Int MediaStreamImageDataForwardImportInterface_SetSourceStream_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamImageDataForwardImportInterface, SetSourceStream))
	{
		maxon::Tie(MediaStreamImageDataForwardImportInterface_SetSourceStream, MediaStreamImageDataForwardImportInterface_SetSourceStream_Offset) = MediaStreamImageDataForwardImportInterface_SetSourceStream_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaStreamImageDataForwardImportInterface, typename MediaStreamImageDataImportInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaStreamImageDataForwardImportInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamImageDataForwardImportInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamImageDataForwardImportInterface_SetSourceStream, maxon::GenericComponent,, (Result<void>), const MediaStreamImageDataImportRef& sourceStream) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetSourceStream(sourceStream); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataForwardImportInterface::SetSourceStream(const MediaStreamImageDataImportRef& sourceStream) -> Result<void>
{
	const MediaStreamImageDataForwardImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamImageDataForwardImportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamImageDataForwardImportInterface_SetSourceStream_Offset), mt_.MediaStreamImageDataForwardImportInterface_SetSourceStream, sourceStream);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataForwardImportInterface::Hxx1::Fn<S>::SetSourceStream(const MediaStreamImageDataImportRef& sourceStream) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamImageDataForwardImportInterface_SetSourceStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataForwardImportInterface_SetSourceStream_Offset), mt_.MediaStreamImageDataForwardImportInterface_SetSourceStream, sourceStream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamImageDataForwardImportInterface::Hxx1::COWFn<S>::SetSourceStream(const MediaStreamImageDataImportRef& sourceStream) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamImageDataForwardImportInterface_SetSourceStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamImageDataForwardImportInterface_SetSourceStream_Offset), mt_.MediaStreamImageDataForwardImportInterface_SetSourceStream, sourceStream));
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
	PRIVATE_MAXON_MF_POINTER(MediaStreamAudioDataImportInterface_SetCallbackHandler, SetCallbackHandler, true, maxon::GenericComponent,, (Result<void>), const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler);
	maxon::Int MediaStreamAudioDataImportInterface_SetCallbackHandler_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamAudioDataImportInterface_InitStream, InitStream, true, maxon::GenericComponent,, (Result<void>), MediaStreamProperties& props);
	maxon::Int MediaStreamAudioDataImportInterface_InitStream_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamAudioDataImportInterface_SetAudioDataCallback, SetAudioDataCallback, true, maxon::GenericComponent,, (Result<SetAudioDataCallbackType>), MediaStreamProperties& props);
	maxon::Int MediaStreamAudioDataImportInterface_SetAudioDataCallback_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamAudioDataImportInterface_FinishStream, FinishStream, true, maxon::GenericComponent,, (Result<void>), const MediaStreamProperties& props);
	maxon::Int MediaStreamAudioDataImportInterface_FinishStream_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataImportInterface, SetCallbackHandler))
	{
		maxon::Tie(MediaStreamAudioDataImportInterface_SetCallbackHandler, MediaStreamAudioDataImportInterface_SetCallbackHandler_Offset) = MediaStreamAudioDataImportInterface_SetCallbackHandler_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataImportInterface, InitStream))
	{
		maxon::Tie(MediaStreamAudioDataImportInterface_InitStream, MediaStreamAudioDataImportInterface_InitStream_Offset) = MediaStreamAudioDataImportInterface_InitStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataImportInterface, SetAudioDataCallback))
	{
		maxon::Tie(MediaStreamAudioDataImportInterface_SetAudioDataCallback, MediaStreamAudioDataImportInterface_SetAudioDataCallback_Offset) = MediaStreamAudioDataImportInterface_SetAudioDataCallback_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataImportInterface, FinishStream))
	{
		maxon::Tie(MediaStreamAudioDataImportInterface_FinishStream, MediaStreamAudioDataImportInterface_FinishStream_Offset) = MediaStreamAudioDataImportInterface_FinishStream_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaStreamAudioDataImportInterface, typename MediaStreamInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaStreamAudioDataImportInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamAudioDataImportInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamAudioDataImportInterface_SetCallbackHandler, maxon::GenericComponent,, (Result<void>), const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetCallbackHandler(initHandler, getAudioDataHandler, finishHandler); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamAudioDataImportInterface_InitStream, maxon::GenericComponent,, (Result<void>), MediaStreamProperties& props) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InitStream(props); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamAudioDataImportInterface_SetAudioDataCallback, maxon::GenericComponent,, (Result<SetAudioDataCallbackType>), MediaStreamProperties& props) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetAudioDataCallback(props); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamAudioDataImportInterface_FinishStream, maxon::GenericComponent,, (Result<void>), const MediaStreamProperties& props) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->FinishStream(props); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::SetCallbackHandler(const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler) -> Result<void>
{
	const MediaStreamAudioDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamAudioDataImportInterface_SetCallbackHandler_Offset), mt_.MediaStreamAudioDataImportInterface_SetCallbackHandler, initHandler, getAudioDataHandler, finishHandler);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::InitStream(MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamAudioDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamAudioDataImportInterface_InitStream_Offset), mt_.MediaStreamAudioDataImportInterface_InitStream, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::SetAudioDataCallback(MediaStreamProperties& props) -> Result<SetAudioDataCallbackType>
{
	const MediaStreamAudioDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamAudioDataImportInterface_SetAudioDataCallback_Offset), mt_.MediaStreamAudioDataImportInterface_SetAudioDataCallback, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamAudioDataImportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataImportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamAudioDataImportInterface_FinishStream_Offset), mt_.MediaStreamAudioDataImportInterface_FinishStream, props);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::Fn<S>::SetCallbackHandler(const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamAudioDataImportInterface_SetCallbackHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_SetCallbackHandler_Offset), mt_.MediaStreamAudioDataImportInterface_SetCallbackHandler, initHandler, getAudioDataHandler, finishHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::COWFn<S>::SetCallbackHandler(const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamAudioDataImportInterface_SetCallbackHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_SetCallbackHandler_Offset), mt_.MediaStreamAudioDataImportInterface_SetCallbackHandler, initHandler, getAudioDataHandler, finishHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::Fn<S>::InitStream(MediaStreamProperties& props) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamAudioDataImportInterface_InitStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_InitStream_Offset), mt_.MediaStreamAudioDataImportInterface_InitStream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::COWFn<S>::InitStream(MediaStreamProperties& props) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamAudioDataImportInterface_InitStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_InitStream_Offset), mt_.MediaStreamAudioDataImportInterface_InitStream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::Fn<S>::SetAudioDataCallback(MediaStreamProperties& props) const -> Result<SetAudioDataCallbackType>
{
	HXXRETURN0(Result<SetAudioDataCallbackType>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamAudioDataImportInterface_SetAudioDataCallback); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_SetAudioDataCallback_Offset), mt_.MediaStreamAudioDataImportInterface_SetAudioDataCallback, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::COWFn<S>::SetAudioDataCallback(MediaStreamProperties& props) -> Result<SetAudioDataCallbackType>
{
	HXXRETURN0(Result<SetAudioDataCallbackType>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamAudioDataImportInterface_SetAudioDataCallback); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_SetAudioDataCallback_Offset), mt_.MediaStreamAudioDataImportInterface_SetAudioDataCallback, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::Fn<S>::FinishStream(const MediaStreamProperties& props) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamAudioDataImportInterface_FinishStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_FinishStream_Offset), mt_.MediaStreamAudioDataImportInterface_FinishStream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataImportInterface::Hxx1::COWFn<S>::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamAudioDataImportInterface_FinishStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataImportInterface_FinishStream_Offset), mt_.MediaStreamAudioDataImportInterface_FinishStream, props));
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

