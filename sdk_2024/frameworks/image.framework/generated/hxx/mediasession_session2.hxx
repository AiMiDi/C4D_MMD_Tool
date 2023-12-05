
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
	PRIVATE_MAXON_MF_POINTER(MediaSessionInterface_ConnectMediaConverter, ConnectMediaConverter, true, maxon::GenericComponent,, (Result<void>), const MediaConverterRef& input, const MediaConverterRef& output);
	maxon::Int MediaSessionInterface_ConnectMediaConverter_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaSessionInterface_Convert, Convert, true, maxon::GenericComponent,, (Result<void>), const TimeValue& targetTime, MEDIASESSIONFLAGS flags);
	maxon::Int MediaSessionInterface_Convert_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaSessionInterface_Close, Close, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int MediaSessionInterface_Close_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaSessionInterface_GetProgress, GetProgress, true, maxon::GenericComponent, const, (ProgressRef));
	maxon::Int MediaSessionInterface_GetProgress_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, ConnectMediaConverter))
	{
		maxon::Tie(MediaSessionInterface_ConnectMediaConverter, MediaSessionInterface_ConnectMediaConverter_Offset) = MediaSessionInterface_ConnectMediaConverter_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, Convert))
	{
		maxon::Tie(MediaSessionInterface_Convert, MediaSessionInterface_Convert_Offset) = MediaSessionInterface_Convert_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, Close))
	{
		maxon::Tie(MediaSessionInterface_Close, MediaSessionInterface_Close_Offset) = MediaSessionInterface_Close_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaSessionInterface, GetProgress))
	{
		maxon::Tie(MediaSessionInterface_GetProgress, MediaSessionInterface_GetProgress_Offset) = MediaSessionInterface_GetProgress_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaSessionInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaSessionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaSessionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MediaSessionInterface_ConnectMediaConverter, maxon::GenericComponent,, (Result<void>), const MediaConverterRef& input, const MediaConverterRef& output) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ConnectMediaConverter(input, output); }
		PRIVATE_MAXON_MF_WRAPPER(MediaSessionInterface_Convert, maxon::GenericComponent,, (Result<void>), const TimeValue& targetTime, MEDIASESSIONFLAGS flags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Convert(targetTime, flags); }
		PRIVATE_MAXON_MF_WRAPPER(MediaSessionInterface_Close, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Close(); }
		PRIVATE_MAXON_MF_WRAPPER(MediaSessionInterface_GetProgress, maxon::GenericComponent, const, (ProgressRef)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetProgress(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output) -> Result<void>
{
	const MediaSessionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaSessionInterface_ConnectMediaConverter_Offset), mt_.MediaSessionInterface_ConnectMediaConverter, input, output);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	const MediaSessionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaSessionInterface_Convert_Offset), mt_.MediaSessionInterface_Convert, targetTime, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Close() -> Result<void>
{
	const MediaSessionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaSessionInterface_Close_Offset), mt_.MediaSessionInterface_Close);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::GetProgress() const -> ProgressRef
{
	const MediaSessionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaSessionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MediaSessionInterface_GetProgress_Offset), mt_.MediaSessionInterface_GetProgress);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::Fn<S>::ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaSessionInterface_ConnectMediaConverter); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_ConnectMediaConverter_Offset), mt_.MediaSessionInterface_ConnectMediaConverter, input, output));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::COWFn<S>::ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaSessionInterface_ConnectMediaConverter); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_ConnectMediaConverter_Offset), mt_.MediaSessionInterface_ConnectMediaConverter, input, output));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::Fn<S>::Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaSessionInterface_Convert); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_Convert_Offset), mt_.MediaSessionInterface_Convert, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::COWFn<S>::Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaSessionInterface_Convert); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_Convert_Offset), mt_.MediaSessionInterface_Convert, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::Fn<S>::Close() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaSessionInterface_Close); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_Close_Offset), mt_.MediaSessionInterface_Close));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::COWFn<S>::Close() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaSessionInterface_Close); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_Close_Offset), mt_.MediaSessionInterface_Close));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaSessionInterface::Hxx1::ConstFn<S>::GetProgress() const -> HXXADDRET2(ProgressRef)
{
	HXXRETURN0(HXXADDRET2(ProgressRef)); HXXRES; HXXCONST(HXXRET3(NULLPTR, ProgressRef)) HXXTABLE(MediaSessionInterface_GetProgress); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_GetProgress_Offset), mt_.MediaSessionInterface_GetProgress));
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
