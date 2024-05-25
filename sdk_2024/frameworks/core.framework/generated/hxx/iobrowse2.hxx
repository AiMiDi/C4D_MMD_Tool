
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
/// @cond INTERNAL

/// @endcond


struct IoBrowseInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBasePath);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetCurrentPath);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetExtraData);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetNext);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSize);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(HasEntry);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoGetAttributes);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoGetFlags);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoGetTime);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Reset);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
/// @cond INTERNAL

	PRIVATE_MAXON_MF_POINTER(IoBrowseInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags);
	maxon::Int IoBrowseInterface_Init_Offset;
/// @endcond

	PRIVATE_MAXON_MF_POINTER(IoBrowseInterface_GetBasePath, GetBasePath, true, maxon::GenericComponent, const, (const Url&));
	maxon::Int IoBrowseInterface_GetBasePath_Offset;
	PRIVATE_MAXON_MF_POINTER(IoBrowseInterface_Reset, Reset, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int IoBrowseInterface_Reset_Offset;
	PRIVATE_MAXON_MF_POINTER(IoBrowseInterface_GetNext, GetNext, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int IoBrowseInterface_GetNext_Offset;
	PRIVATE_MAXON_MF_POINTER(IoBrowseInterface_HasEntry, HasEntry, true, maxon::GenericComponent, const, (Bool));
	maxon::Int IoBrowseInterface_HasEntry_Offset;
	PRIVATE_MAXON_MF_POINTER(IoBrowseInterface_GetCurrentPath, GetCurrentPath, true, maxon::GenericComponent, const, (Url));
	maxon::Int IoBrowseInterface_GetCurrentPath_Offset;
	PRIVATE_MAXON_MF_POINTER(IoBrowseInterface_IoGetFlags, IoGetFlags, true, maxon::GenericComponent, const, (IOBROWSEFLAGS));
	maxon::Int IoBrowseInterface_IoGetFlags_Offset;
	PRIVATE_MAXON_MF_POINTER(IoBrowseInterface_IoGetAttributes, IoGetAttributes, true, maxon::GenericComponent, const, (Result<IOATTRIBUTES>));
	maxon::Int IoBrowseInterface_IoGetAttributes_Offset;
	PRIVATE_MAXON_MF_POINTER(IoBrowseInterface_IoGetTime, IoGetTime, true, maxon::GenericComponent, const, (Result<UniversalDateTime>), IOTIMEMODE mode);
	maxon::Int IoBrowseInterface_IoGetTime_Offset;
	PRIVATE_MAXON_MF_POINTER(IoBrowseInterface_GetSize, GetSize, true, maxon::GenericComponent, const, (Int64));
	maxon::Int IoBrowseInterface_GetSize_Offset;
	PRIVATE_MAXON_MF_POINTER(IoBrowseInterface_GetExtraData, GetExtraData, true, maxon::GenericComponent, const, (String));
	maxon::Int IoBrowseInterface_GetExtraData_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
/// @cond INTERNAL

	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, Init))
	{
		maxon::Tie(IoBrowseInterface_Init, IoBrowseInterface_Init_Offset) = IoBrowseInterface_Init_GetPtr<W>(offset, true);
	}
/// @endcond

	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetBasePath))
	{
		maxon::Tie(IoBrowseInterface_GetBasePath, IoBrowseInterface_GetBasePath_Offset) = IoBrowseInterface_GetBasePath_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, Reset))
	{
		maxon::Tie(IoBrowseInterface_Reset, IoBrowseInterface_Reset_Offset) = IoBrowseInterface_Reset_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetNext))
	{
		maxon::Tie(IoBrowseInterface_GetNext, IoBrowseInterface_GetNext_Offset) = IoBrowseInterface_GetNext_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, HasEntry))
	{
		maxon::Tie(IoBrowseInterface_HasEntry, IoBrowseInterface_HasEntry_Offset) = IoBrowseInterface_HasEntry_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetCurrentPath))
	{
		maxon::Tie(IoBrowseInterface_GetCurrentPath, IoBrowseInterface_GetCurrentPath_Offset) = IoBrowseInterface_GetCurrentPath_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, IoGetFlags))
	{
		maxon::Tie(IoBrowseInterface_IoGetFlags, IoBrowseInterface_IoGetFlags_Offset) = IoBrowseInterface_IoGetFlags_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, IoGetAttributes))
	{
		maxon::Tie(IoBrowseInterface_IoGetAttributes, IoBrowseInterface_IoGetAttributes_Offset) = IoBrowseInterface_IoGetAttributes_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, IoGetTime))
	{
		maxon::Tie(IoBrowseInterface_IoGetTime, IoBrowseInterface_IoGetTime_Offset) = IoBrowseInterface_IoGetTime_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetSize))
	{
		maxon::Tie(IoBrowseInterface_GetSize, IoBrowseInterface_GetSize_Offset) = IoBrowseInterface_GetSize_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoBrowseInterface, GetExtraData))
	{
		maxon::Tie(IoBrowseInterface_GetExtraData, IoBrowseInterface_GetExtraData_Offset) = IoBrowseInterface_GetExtraData_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<IoBrowseInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<IoBrowseInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct IoBrowseInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBasePath);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCurrentPath);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetExtraData);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetNext);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSize);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(HasEntry);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoGetAttributes);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoGetFlags);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoGetTime);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Reset);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (IoBrowseInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, IoBrowseInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
/// @cond INTERNAL

		PRIVATE_MAXON_MF_WRAPPER(IoBrowseInterface_Init, maxon::GenericComponent,, (Result<void>), IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(connection, flags); }
/// @endcond

		PRIVATE_MAXON_MF_WRAPPER(IoBrowseInterface_GetBasePath, maxon::GenericComponent, const, (const Url&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetBasePath(); }
		PRIVATE_MAXON_MF_WRAPPER(IoBrowseInterface_Reset, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Reset(); }
		PRIVATE_MAXON_MF_WRAPPER(IoBrowseInterface_GetNext, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->GetNext(); }
		PRIVATE_MAXON_MF_WRAPPER(IoBrowseInterface_HasEntry, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->HasEntry(); }
		PRIVATE_MAXON_MF_WRAPPER(IoBrowseInterface_GetCurrentPath, maxon::GenericComponent, const, (Url)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetCurrentPath(); }
		PRIVATE_MAXON_MF_WRAPPER(IoBrowseInterface_IoGetFlags, maxon::GenericComponent, const, (IOBROWSEFLAGS)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IoGetFlags(); }
		PRIVATE_MAXON_MF_WRAPPER(IoBrowseInterface_IoGetAttributes, maxon::GenericComponent, const, (Result<IOATTRIBUTES>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IoGetAttributes(); }
		PRIVATE_MAXON_MF_WRAPPER(IoBrowseInterface_IoGetTime, maxon::GenericComponent, const, (Result<UniversalDateTime>), IOTIMEMODE mode) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IoGetTime(mode); }
		PRIVATE_MAXON_MF_WRAPPER(IoBrowseInterface_GetSize, maxon::GenericComponent, const, (Int64)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetSize(); }
		PRIVATE_MAXON_MF_WRAPPER(IoBrowseInterface_GetExtraData, maxon::GenericComponent, const, (String)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetExtraData(); }
	};

};
/// @cond INTERNAL

MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags) -> Result<void>
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoBrowseInterface_Init_Offset), mt_.IoBrowseInterface_Init, connection, flags);
}
/// @endcond

MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::GetBasePath() const -> const Url&
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoBrowseInterface_GetBasePath_Offset), mt_.IoBrowseInterface_GetBasePath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Reset() -> Result<void>
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoBrowseInterface_Reset_Offset), mt_.IoBrowseInterface_Reset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::GetNext() -> Result<void>
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoBrowseInterface_GetNext_Offset), mt_.IoBrowseInterface_GetNext);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::HasEntry() const -> Bool
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoBrowseInterface_HasEntry_Offset), mt_.IoBrowseInterface_HasEntry);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::GetCurrentPath() const -> Url
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoBrowseInterface_GetCurrentPath_Offset), mt_.IoBrowseInterface_GetCurrentPath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::IoGetFlags() const -> IOBROWSEFLAGS
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoBrowseInterface_IoGetFlags_Offset), mt_.IoBrowseInterface_IoGetFlags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::IoGetAttributes() const -> Result<IOATTRIBUTES>
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoBrowseInterface_IoGetAttributes_Offset), mt_.IoBrowseInterface_IoGetAttributes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::IoGetTime(IOTIMEMODE mode) const -> Result<UniversalDateTime>
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoBrowseInterface_IoGetTime_Offset), mt_.IoBrowseInterface_IoGetTime, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::GetSize() const -> Int64
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoBrowseInterface_GetSize_Offset), mt_.IoBrowseInterface_GetSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::GetExtraData() const -> String
{
	const IoBrowseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoBrowseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoBrowseInterface_GetExtraData_Offset), mt_.IoBrowseInterface_GetExtraData);
}

/// @cond INTERNAL

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::Fn<S>::Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>); HXXRES; HXXNONCONST(, , false, HXXRET2b(NULLPTR)) HXXTABLE(IoBrowseInterface_Init); 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoBrowseInterface_Init_Offset), mt_.IoBrowseInterface_Init, connection, flags);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::COWFn<S>::Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2b(MAKE_WRITABLE_FAILED)) HXXTABLE(IoBrowseInterface_Init); 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoBrowseInterface_Init_Offset), mt_.IoBrowseInterface_Init, connection, flags);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
/// @endcond

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstFn<S>::GetBasePath() const -> HXXADDRET2(const Url&)
{
	HXXRETURN0(HXXADDRET2(const Url&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const Url&)) HXXTABLE(IoBrowseInterface_GetBasePath); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoBrowseInterface_GetBasePath_Offset), mt_.IoBrowseInterface_GetBasePath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::Fn<S>::Reset() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(IoBrowseInterface_Reset); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoBrowseInterface_Reset_Offset), mt_.IoBrowseInterface_Reset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::COWFn<S>::Reset() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(IoBrowseInterface_Reset); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoBrowseInterface_Reset_Offset), mt_.IoBrowseInterface_Reset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::Fn<S>::GetNext() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(IoBrowseInterface_GetNext); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoBrowseInterface_GetNext_Offset), mt_.IoBrowseInterface_GetNext));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::COWFn<S>::GetNext() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(IoBrowseInterface_GetNext); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoBrowseInterface_GetNext_Offset), mt_.IoBrowseInterface_GetNext));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstFn<S>::HasEntry() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) HXXTABLE(IoBrowseInterface_HasEntry); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoBrowseInterface_HasEntry_Offset), mt_.IoBrowseInterface_HasEntry));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstFn<S>::GetCurrentPath() const -> HXXADDRET2(Url)
{
	HXXRETURN0(HXXADDRET2(Url)); HXXRES; HXXCONST(HXXRET3(NULLPTR, Url)) HXXTABLE(IoBrowseInterface_GetCurrentPath); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoBrowseInterface_GetCurrentPath_Offset), mt_.IoBrowseInterface_GetCurrentPath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstFn<S>::IoGetFlags() const -> HXXADDRET2(IOBROWSEFLAGS)
{
	HXXRETURN0(HXXADDRET2(IOBROWSEFLAGS)); HXXRES; HXXCONST(HXXRET3(NULLPTR, IOBROWSEFLAGS)) HXXTABLE(IoBrowseInterface_IoGetFlags); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoBrowseInterface_IoGetFlags_Offset), mt_.IoBrowseInterface_IoGetFlags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstFn<S>::IoGetAttributes() const -> Result<IOATTRIBUTES>
{
	HXXRETURN0(Result<IOATTRIBUTES>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(IoBrowseInterface_IoGetAttributes); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoBrowseInterface_IoGetAttributes_Offset), mt_.IoBrowseInterface_IoGetAttributes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstFn<S>::IoGetTime(IOTIMEMODE mode) const -> Result<UniversalDateTime>
{
	HXXRETURN0(Result<UniversalDateTime>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(IoBrowseInterface_IoGetTime); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoBrowseInterface_IoGetTime_Offset), mt_.IoBrowseInterface_IoGetTime, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstFn<S>::GetSize() const -> HXXADDRET2(Int64)
{
	HXXRETURN0(HXXADDRET2(Int64)); HXXRES; HXXCONST(0) HXXTABLE(IoBrowseInterface_GetSize); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoBrowseInterface_GetSize_Offset), mt_.IoBrowseInterface_GetSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoBrowseInterface::Hxx1::ConstFn<S>::GetExtraData() const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(HXXRET3(NULLPTR, String)) HXXTABLE(IoBrowseInterface_GetExtraData); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoBrowseInterface_GetExtraData_Offset), mt_.IoBrowseInterface_GetExtraData));
}
auto IoBrowseInterface::GetPtr() -> Ptr { return Ptr(this); }
auto IoBrowseInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_iobrowse)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_IoBrowseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_IoBrowseInterface() { new (s_ui_maxon_IoBrowseInterface) maxon::EntityUse(IoBrowseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iobrowse.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_IoBrowseInterface(IoBrowseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iobrowse.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

