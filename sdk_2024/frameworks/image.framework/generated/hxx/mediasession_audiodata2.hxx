
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(MediaStreamAudioDataExportInterface_InitWithAudioData, InitWithAudioData, true, maxon::GenericComponent,, (Result<void>), const AudioObjectRef& audioData);
	maxon::Int MediaStreamAudioDataExportInterface_InitWithAudioData_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamAudioDataExportInterface_GetAudioObject, GetAudioObject, true, maxon::GenericComponent, const, (AudioObjectRef));
	maxon::Int MediaStreamAudioDataExportInterface_GetAudioObject_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamAudioDataExportInterface_SetCallbackHandler, SetCallbackHandler, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int MediaStreamAudioDataExportInterface_SetCallbackHandler_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamAudioDataExportInterface_InitStream, InitStream, true, maxon::GenericComponent,, (Result<void>), MediaStreamProperties& props);
	maxon::Int MediaStreamAudioDataExportInterface_InitStream_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamAudioDataExportInterface_FinishStream, FinishStream, true, maxon::GenericComponent,, (Result<void>), const MediaStreamProperties& props);
	maxon::Int MediaStreamAudioDataExportInterface_FinishStream_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, InitWithAudioData))
	{
		maxon::Tie(MediaStreamAudioDataExportInterface_InitWithAudioData, MediaStreamAudioDataExportInterface_InitWithAudioData_Offset) = MediaStreamAudioDataExportInterface_InitWithAudioData_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, GetAudioObject))
	{
		maxon::Tie(MediaStreamAudioDataExportInterface_GetAudioObject, MediaStreamAudioDataExportInterface_GetAudioObject_Offset) = MediaStreamAudioDataExportInterface_GetAudioObject_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, SetCallbackHandler))
	{
		maxon::Tie(MediaStreamAudioDataExportInterface_SetCallbackHandler, MediaStreamAudioDataExportInterface_SetCallbackHandler_Offset) = MediaStreamAudioDataExportInterface_SetCallbackHandler_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, InitStream))
	{
		maxon::Tie(MediaStreamAudioDataExportInterface_InitStream, MediaStreamAudioDataExportInterface_InitStream_Offset) = MediaStreamAudioDataExportInterface_InitStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamAudioDataExportInterface, FinishStream))
	{
		maxon::Tie(MediaStreamAudioDataExportInterface_FinishStream, MediaStreamAudioDataExportInterface_FinishStream_Offset) = MediaStreamAudioDataExportInterface_FinishStream_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaStreamAudioDataExportInterface, typename MediaStreamInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaStreamAudioDataExportInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaStreamAudioDataExportInterface::Hxx2
{
	template <typename S> class CWrapper : public MediaStreamInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FinishStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetAudioObject);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InitWithAudioData);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetCallbackHandler);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename MediaStreamInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaStreamAudioDataExportInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamAudioDataExportInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamAudioDataExportInterface_InitWithAudioData, maxon::GenericComponent,, (Result<void>), const AudioObjectRef& audioData) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InitWithAudioData(audioData); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamAudioDataExportInterface_GetAudioObject, maxon::GenericComponent, const, (AudioObjectRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetAudioObject(); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamAudioDataExportInterface_SetCallbackHandler, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetCallbackHandler(); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamAudioDataExportInterface_InitStream, maxon::GenericComponent,, (Result<void>), MediaStreamProperties& props) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InitStream(props); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamAudioDataExportInterface_FinishStream, maxon::GenericComponent,, (Result<void>), const MediaStreamProperties& props) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->FinishStream(props); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::InitWithAudioData(const AudioObjectRef& audioData) -> Result<void>
{
	const MediaStreamAudioDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamAudioDataExportInterface_InitWithAudioData_Offset), mt_.MediaStreamAudioDataExportInterface_InitWithAudioData, audioData);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::GetAudioObject() const -> AudioObjectRef
{
	const MediaStreamAudioDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MediaStreamAudioDataExportInterface_GetAudioObject_Offset), mt_.MediaStreamAudioDataExportInterface_GetAudioObject);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::SetCallbackHandler() -> Result<void>
{
	const MediaStreamAudioDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamAudioDataExportInterface_SetCallbackHandler_Offset), mt_.MediaStreamAudioDataExportInterface_SetCallbackHandler);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::InitStream(MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamAudioDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamAudioDataExportInterface_InitStream_Offset), mt_.MediaStreamAudioDataExportInterface_InitStream, props);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	const MediaStreamAudioDataExportInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamAudioDataExportInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamAudioDataExportInterface_FinishStream_Offset), mt_.MediaStreamAudioDataExportInterface_FinishStream, props);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::Fn<S>::InitWithAudioData(const AudioObjectRef& audioData) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamAudioDataExportInterface_InitWithAudioData); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataExportInterface_InitWithAudioData_Offset), mt_.MediaStreamAudioDataExportInterface_InitWithAudioData, audioData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::COWFn<S>::InitWithAudioData(const AudioObjectRef& audioData) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamAudioDataExportInterface_InitWithAudioData); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataExportInterface_InitWithAudioData_Offset), mt_.MediaStreamAudioDataExportInterface_InitWithAudioData, audioData));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::ConstFn<S>::GetAudioObject() const -> HXXADDRET2(AudioObjectRef)
{
	HXXRETURN0(HXXADDRET2(AudioObjectRef)); HXXRES; HXXCONST(HXXRET3(NULLPTR, AudioObjectRef)) HXXTABLE(MediaStreamAudioDataExportInterface_GetAudioObject); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataExportInterface_GetAudioObject_Offset), mt_.MediaStreamAudioDataExportInterface_GetAudioObject));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::Fn<S>::SetCallbackHandler() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamAudioDataExportInterface_SetCallbackHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataExportInterface_SetCallbackHandler_Offset), mt_.MediaStreamAudioDataExportInterface_SetCallbackHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::COWFn<S>::SetCallbackHandler() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamAudioDataExportInterface_SetCallbackHandler); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataExportInterface_SetCallbackHandler_Offset), mt_.MediaStreamAudioDataExportInterface_SetCallbackHandler));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::Fn<S>::InitStream(MediaStreamProperties& props) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamAudioDataExportInterface_InitStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataExportInterface_InitStream_Offset), mt_.MediaStreamAudioDataExportInterface_InitStream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::COWFn<S>::InitStream(MediaStreamProperties& props) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamAudioDataExportInterface_InitStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataExportInterface_InitStream_Offset), mt_.MediaStreamAudioDataExportInterface_InitStream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::Fn<S>::FinishStream(const MediaStreamProperties& props) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaStreamAudioDataExportInterface_FinishStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataExportInterface_FinishStream_Offset), mt_.MediaStreamAudioDataExportInterface_FinishStream, props));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamAudioDataExportInterface::Hxx1::COWFn<S>::FinishStream(const MediaStreamProperties& props) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaStreamAudioDataExportInterface_FinishStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamAudioDataExportInterface_FinishStream_Offset), mt_.MediaStreamAudioDataExportInterface_FinishStream, props));
}
auto MediaStreamAudioDataExportInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaStreamAudioDataExportInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_audiodata)
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

