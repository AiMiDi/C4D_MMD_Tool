
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct MediaConverterInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddOutputStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Analyze);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Close);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Execute);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetInputConverter);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetOutputStreams);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrepareExecute);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RemoveOutputStream);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SupportExportStrategy);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SupportImportStrategy);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(MediaConverterInterface_SupportImportStrategy, SupportImportStrategy, true, maxon::GenericComponent, const, (Bool));
	maxon::Int MediaConverterInterface_SupportImportStrategy_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaConverterInterface_SupportExportStrategy, SupportExportStrategy, true, maxon::GenericComponent, const, (Bool));
	maxon::Int MediaConverterInterface_SupportExportStrategy_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaConverterInterface_GetInputConverter, GetInputConverter, true, maxon::GenericComponent, const, (Result<BaseArray<MediaConverterRef>>));
	maxon::Int MediaConverterInterface_GetInputConverter_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaConverterInterface_AddOutputStream, AddOutputStream, true, maxon::GenericComponent,, (Result<void>), const MediaStreamRef& stream);
	maxon::Int MediaConverterInterface_AddOutputStream_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaConverterInterface_RemoveOutputStream, RemoveOutputStream, true, maxon::GenericComponent,, (Result<void>), const MediaStreamRef& stream);
	maxon::Int MediaConverterInterface_RemoveOutputStream_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaConverterInterface_GetOutputStreams, GetOutputStreams, true, maxon::GenericComponent, const, (Result<BaseArray<MediaStreamRef>>), Bool flattenChildren);
	maxon::Int MediaConverterInterface_GetOutputStreams_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaConverterInterface_Analyze, Analyze, true, maxon::GenericComponent,, (Result<void>), const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags);
	maxon::Int MediaConverterInterface_Analyze_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaConverterInterface_PrepareExecute, PrepareExecute, true, maxon::GenericComponent,, (Result<void>), const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags);
	maxon::Int MediaConverterInterface_PrepareExecute_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaConverterInterface_Execute, Execute, true, maxon::GenericComponent,, (Result<void>), const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags);
	maxon::Int MediaConverterInterface_Execute_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaConverterInterface_Close, Close, true, maxon::GenericComponent,, (Result<void>), const Block<const MediaConverterRef>& inputs);
	maxon::Int MediaConverterInterface_Close_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, SupportImportStrategy))
	{
		maxon::Tie(MediaConverterInterface_SupportImportStrategy, MediaConverterInterface_SupportImportStrategy_Offset) = MediaConverterInterface_SupportImportStrategy_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, SupportExportStrategy))
	{
		maxon::Tie(MediaConverterInterface_SupportExportStrategy, MediaConverterInterface_SupportExportStrategy_Offset) = MediaConverterInterface_SupportExportStrategy_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, GetInputConverter))
	{
		maxon::Tie(MediaConverterInterface_GetInputConverter, MediaConverterInterface_GetInputConverter_Offset) = MediaConverterInterface_GetInputConverter_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, AddOutputStream))
	{
		maxon::Tie(MediaConverterInterface_AddOutputStream, MediaConverterInterface_AddOutputStream_Offset) = MediaConverterInterface_AddOutputStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, RemoveOutputStream))
	{
		maxon::Tie(MediaConverterInterface_RemoveOutputStream, MediaConverterInterface_RemoveOutputStream_Offset) = MediaConverterInterface_RemoveOutputStream_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, GetOutputStreams))
	{
		maxon::Tie(MediaConverterInterface_GetOutputStreams, MediaConverterInterface_GetOutputStreams_Offset) = MediaConverterInterface_GetOutputStreams_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, Analyze))
	{
		maxon::Tie(MediaConverterInterface_Analyze, MediaConverterInterface_Analyze_Offset) = MediaConverterInterface_Analyze_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, PrepareExecute))
	{
		maxon::Tie(MediaConverterInterface_PrepareExecute, MediaConverterInterface_PrepareExecute_Offset) = MediaConverterInterface_PrepareExecute_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, Execute))
	{
		maxon::Tie(MediaConverterInterface_Execute, MediaConverterInterface_Execute_Offset) = MediaConverterInterface_Execute_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaConverterInterface, Close))
	{
		maxon::Tie(MediaConverterInterface_Close, MediaConverterInterface_Close_Offset) = MediaConverterInterface_Close_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaConverterInterface, typename MediaBaseInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaConverterInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaConverterInterface::Hxx2
{
	template <typename S> class CWrapper : public MediaBaseInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddOutputStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Analyze);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Close);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Execute);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetInputConverter);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetOutputStreams);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrepareExecute);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RemoveOutputStream);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SupportExportStrategy);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SupportImportStrategy);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename MediaBaseInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaConverterInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaConverterInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MediaConverterInterface_SupportImportStrategy, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->SupportImportStrategy(); }
		PRIVATE_MAXON_MF_WRAPPER(MediaConverterInterface_SupportExportStrategy, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->SupportExportStrategy(); }
		PRIVATE_MAXON_MF_WRAPPER(MediaConverterInterface_GetInputConverter, maxon::GenericComponent, const, (Result<BaseArray<MediaConverterRef>>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetInputConverter(); }
		PRIVATE_MAXON_MF_WRAPPER(MediaConverterInterface_AddOutputStream, maxon::GenericComponent,, (Result<void>), const MediaStreamRef& stream) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->AddOutputStream(stream); }
		PRIVATE_MAXON_MF_WRAPPER(MediaConverterInterface_RemoveOutputStream, maxon::GenericComponent,, (Result<void>), const MediaStreamRef& stream) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->RemoveOutputStream(stream); }
		PRIVATE_MAXON_MF_WRAPPER(MediaConverterInterface_GetOutputStreams, maxon::GenericComponent, const, (Result<BaseArray<MediaStreamRef>>), Bool flattenChildren) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetOutputStreams(flattenChildren); }
		PRIVATE_MAXON_MF_WRAPPER(MediaConverterInterface_Analyze, maxon::GenericComponent,, (Result<void>), const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Analyze(inputs, targetTime, flags); }
		PRIVATE_MAXON_MF_WRAPPER(MediaConverterInterface_PrepareExecute, maxon::GenericComponent,, (Result<void>), const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->PrepareExecute(inputs, targetTime, flags); }
		PRIVATE_MAXON_MF_WRAPPER(MediaConverterInterface_Execute, maxon::GenericComponent,, (Result<void>), const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Execute(inputs, targetTime, flags); }
		PRIVATE_MAXON_MF_WRAPPER(MediaConverterInterface_Close, maxon::GenericComponent,, (Result<void>), const Block<const MediaConverterRef>& inputs) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Close(inputs); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::SupportImportStrategy() const -> Bool
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MediaConverterInterface_SupportImportStrategy_Offset), mt_.MediaConverterInterface_SupportImportStrategy);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::SupportExportStrategy() const -> Bool
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MediaConverterInterface_SupportExportStrategy_Offset), mt_.MediaConverterInterface_SupportExportStrategy);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::GetInputConverter() const -> Result<BaseArray<MediaConverterRef>>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MediaConverterInterface_GetInputConverter_Offset), mt_.MediaConverterInterface_GetInputConverter);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::AddOutputStream(const MediaStreamRef& stream) -> Result<void>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaConverterInterface_AddOutputStream_Offset), mt_.MediaConverterInterface_AddOutputStream, stream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::RemoveOutputStream(const MediaStreamRef& stream) -> Result<void>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaConverterInterface_RemoveOutputStream_Offset), mt_.MediaConverterInterface_RemoveOutputStream, stream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::GetOutputStreams(Bool flattenChildren) const -> Result<BaseArray<MediaStreamRef>>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.MediaConverterInterface_GetOutputStreams_Offset), mt_.MediaConverterInterface_GetOutputStreams, flattenChildren);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Analyze(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaConverterInterface_Analyze_Offset), mt_.MediaConverterInterface_Analyze, inputs, targetTime, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::PrepareExecute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaConverterInterface_PrepareExecute_Offset), mt_.MediaConverterInterface_PrepareExecute, inputs, targetTime, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Execute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaConverterInterface_Execute_Offset), mt_.MediaConverterInterface_Execute, inputs, targetTime, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Close(const Block<const MediaConverterRef>& inputs) -> Result<void>
{
	const MediaConverterInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaConverterInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaConverterInterface_Close_Offset), mt_.MediaConverterInterface_Close, inputs);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::ConstFn<S>::SupportImportStrategy() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) HXXTABLE(MediaConverterInterface_SupportImportStrategy); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_SupportImportStrategy_Offset), mt_.MediaConverterInterface_SupportImportStrategy));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::ConstFn<S>::SupportExportStrategy() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) HXXTABLE(MediaConverterInterface_SupportExportStrategy); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_SupportExportStrategy_Offset), mt_.MediaConverterInterface_SupportExportStrategy));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::ConstFn<S>::GetInputConverter() const -> Result<BaseArray<MediaConverterRef>>
{
	HXXRETURN0(Result<BaseArray<MediaConverterRef>>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(MediaConverterInterface_GetInputConverter); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_GetInputConverter_Offset), mt_.MediaConverterInterface_GetInputConverter));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::Fn<S>::AddOutputStream(const MediaStreamRef& stream) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaConverterInterface_AddOutputStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_AddOutputStream_Offset), mt_.MediaConverterInterface_AddOutputStream, stream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::COWFn<S>::AddOutputStream(const MediaStreamRef& stream) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaConverterInterface_AddOutputStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_AddOutputStream_Offset), mt_.MediaConverterInterface_AddOutputStream, stream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::Fn<S>::RemoveOutputStream(const MediaStreamRef& stream) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaConverterInterface_RemoveOutputStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_RemoveOutputStream_Offset), mt_.MediaConverterInterface_RemoveOutputStream, stream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::COWFn<S>::RemoveOutputStream(const MediaStreamRef& stream) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaConverterInterface_RemoveOutputStream); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_RemoveOutputStream_Offset), mt_.MediaConverterInterface_RemoveOutputStream, stream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::ConstFn<S>::GetOutputStreams(Bool flattenChildren) const -> Result<BaseArray<MediaStreamRef>>
{
	HXXRETURN0(Result<BaseArray<MediaStreamRef>>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(MediaConverterInterface_GetOutputStreams); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_GetOutputStreams_Offset), mt_.MediaConverterInterface_GetOutputStreams, flattenChildren));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::Fn<S>::Analyze(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaConverterInterface_Analyze); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_Analyze_Offset), mt_.MediaConverterInterface_Analyze, inputs, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::COWFn<S>::Analyze(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaConverterInterface_Analyze); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_Analyze_Offset), mt_.MediaConverterInterface_Analyze, inputs, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::Fn<S>::PrepareExecute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaConverterInterface_PrepareExecute); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_PrepareExecute_Offset), mt_.MediaConverterInterface_PrepareExecute, inputs, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::COWFn<S>::PrepareExecute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaConverterInterface_PrepareExecute); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_PrepareExecute_Offset), mt_.MediaConverterInterface_PrepareExecute, inputs, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::Fn<S>::Execute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaConverterInterface_Execute); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_Execute_Offset), mt_.MediaConverterInterface_Execute, inputs, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::COWFn<S>::Execute(const Block<const MediaConverterRef>& inputs, const TimeValue& targetTime, MEDIASESSIONFLAGS flags) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaConverterInterface_Execute); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_Execute_Offset), mt_.MediaConverterInterface_Execute, inputs, targetTime, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::Fn<S>::Close(const Block<const MediaConverterRef>& inputs) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(MediaConverterInterface_Close); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_Close_Offset), mt_.MediaConverterInterface_Close, inputs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaConverterInterface::Hxx1::COWFn<S>::Close(const Block<const MediaConverterRef>& inputs) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(MediaConverterInterface_Close); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaConverterInterface_Close_Offset), mt_.MediaConverterInterface_Close, inputs));
}
auto MediaConverterInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaConverterInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_converter)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaConverterInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaConverterInterface() { new (s_ui_maxon_MediaConverterInterface) maxon::EntityUse(MediaConverterInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_converter.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaConverterInterface(MediaConverterInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_converter.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MediaConverterErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaConverterErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaConverterErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaConverterErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaConverterErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaConverterErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto MediaConverterErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaConverterErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_converter)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaConverterErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaConverterErrorInterface() { new (s_ui_maxon_MediaConverterErrorInterface) maxon::EntityUse(MediaConverterErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_converter.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaConverterErrorInterface(MediaConverterErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_converter.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

