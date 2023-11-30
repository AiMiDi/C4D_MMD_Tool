
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct MediaStreamFormatInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaStreamFormatInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaStreamFormatInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaStreamFormatInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaStreamFormatInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamFormatInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto MediaStreamFormatInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaStreamFormatInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_streamformat)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaStreamFormatInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaStreamFormatInterface() { new (s_ui_maxon_MediaStreamFormatInterface) maxon::EntityUse(MediaStreamFormatInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_streamformat.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaStreamFormatInterface(MediaStreamFormatInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_streamformat.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MediaStreamPropertiesInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(MediaStreamPropertiesInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), const MediaStreamFormat& withFormat);
	maxon::Int MediaStreamPropertiesInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(MediaStreamPropertiesInterface_Init_1, Init, true, maxon::GenericComponent,, (Result<void>), const MediaStreamRef& withStream);
	maxon::Int MediaStreamPropertiesInterface_Init_1_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamPropertiesInterface, Init))
	{
		maxon::Tie(MediaStreamPropertiesInterface_Init, MediaStreamPropertiesInterface_Init_Offset) = MediaStreamPropertiesInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaStreamPropertiesInterface, Init))
	{
		maxon::Tie(MediaStreamPropertiesInterface_Init_1, MediaStreamPropertiesInterface_Init_1_Offset) = MediaStreamPropertiesInterface_Init_1_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaStreamPropertiesInterface, typename MediaStreamFormatInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaStreamPropertiesInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaStreamPropertiesInterface::Hxx2
{
	template <typename S> class CWrapper : public MediaStreamFormatInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename MediaStreamFormatInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaStreamPropertiesInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamPropertiesInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamPropertiesInterface_Init, maxon::GenericComponent,, (Result<void>), const MediaStreamFormat& withFormat) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(withFormat); }
		PRIVATE_MAXON_MF_WRAPPER(MediaStreamPropertiesInterface_Init_1, maxon::GenericComponent,, (Result<void>), const MediaStreamRef& withStream) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(withStream); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamPropertiesInterface::Init(const MediaStreamFormat& withFormat) -> Result<void>
{
	const MediaStreamPropertiesInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamPropertiesInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamPropertiesInterface_Init_Offset), mt_.MediaStreamPropertiesInterface_Init, withFormat);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamPropertiesInterface::Init(const MediaStreamRef& withStream) -> Result<void>
{
	const MediaStreamPropertiesInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaStreamPropertiesInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.MediaStreamPropertiesInterface_Init_1_Offset), mt_.MediaStreamPropertiesInterface_Init_1, withStream);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamPropertiesInterface::Hxx1::Fn<S>::Init(const MediaStreamFormat& withFormat) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>); HXXRES; HXXNONCONST(, , false, HXXRET2b(NULLPTR)) HXXTABLE(MediaStreamPropertiesInterface_Init); 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamPropertiesInterface_Init_Offset), mt_.MediaStreamPropertiesInterface_Init, withFormat);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamPropertiesInterface::Hxx1::COWFn<S>::Init(const MediaStreamFormat& withFormat) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2b(MAKE_WRITABLE_FAILED)) HXXTABLE(MediaStreamPropertiesInterface_Init); 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamPropertiesInterface_Init_Offset), mt_.MediaStreamPropertiesInterface_Init, withFormat);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamPropertiesInterface::Hxx1::Fn<S>::Init(const MediaStreamRef& withStream) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>); HXXRES; HXXNONCONST(, , false, HXXRET2b(NULLPTR)) HXXTABLE(MediaStreamPropertiesInterface_Init_1); 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamPropertiesInterface_Init_1_Offset), mt_.MediaStreamPropertiesInterface_Init_1, withStream);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaStreamPropertiesInterface::Hxx1::COWFn<S>::Init(const MediaStreamRef& withStream) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2b(MAKE_WRITABLE_FAILED)) HXXTABLE(MediaStreamPropertiesInterface_Init_1); 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaStreamPropertiesInterface_Init_1_Offset), mt_.MediaStreamPropertiesInterface_Init_1, withStream);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
auto MediaStreamPropertiesInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaStreamPropertiesInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_streamformat)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaStreamPropertiesInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaStreamPropertiesInterface() { new (s_ui_maxon_MediaStreamPropertiesInterface) maxon::EntityUse(MediaStreamPropertiesInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_streamformat.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaStreamPropertiesInterface(MediaStreamPropertiesInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_streamformat.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

