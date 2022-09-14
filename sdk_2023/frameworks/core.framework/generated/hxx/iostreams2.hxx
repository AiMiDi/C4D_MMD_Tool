
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct IoErrorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetUrl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetUrl);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(IoErrorInterface_SetUrl, SetUrl, true, maxon::GenericComponent,, (void), const Url& url);
	maxon::Int IoErrorInterface_SetUrl_Offset;
	PRIVATE_MAXON_MF_POINTER(IoErrorInterface_GetUrl, GetUrl, true, maxon::GenericComponent, const, (const Url&));
	maxon::Int IoErrorInterface_GetUrl_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoErrorInterface, SetUrl))
	{
		maxon::Tie(IoErrorInterface_SetUrl, IoErrorInterface_SetUrl_Offset) = IoErrorInterface_SetUrl_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoErrorInterface, GetUrl))
	{
		maxon::Tie(IoErrorInterface_GetUrl, IoErrorInterface_GetUrl_Offset) = IoErrorInterface_GetUrl_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<IoErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<IoErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct IoErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUrl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetUrl);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (IoErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, IoErrorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(IoErrorInterface_SetUrl, maxon::GenericComponent,, (void), const Url& url) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetUrl(url); }
		PRIVATE_MAXON_MF_WRAPPER(IoErrorInterface_GetUrl, maxon::GenericComponent, const, (const Url&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetUrl(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::SetUrl(const Url& url) -> void
{
	const IoErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.IoErrorInterface_SetUrl_Offset), mt_.IoErrorInterface_SetUrl, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::GetUrl() const -> const Url&
{
	const IoErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoErrorInterface_GetUrl_Offset), mt_.IoErrorInterface_GetUrl);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::Hxx1::Fn<S>::SetUrl(const Url& url) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoErrorInterface* o_ = (IoErrorInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoErrorInterface, o_, IoErrorInterface_SetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoErrorInterface>() : PRIVATE_MAXON_VTABLE(IoErrorInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoErrorInterface_SetUrl_Offset), mt_.IoErrorInterface_SetUrl, url);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::Hxx1::COWFn<S>::SetUrl(const Url& url) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); IoErrorInterface* o_ = (IoErrorInterface*) this->MakeWritable(false).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoErrorInterface, o_, IoErrorInterface_SetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoErrorInterface>() : PRIVATE_MAXON_VTABLE(IoErrorInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoErrorInterface_SetUrl_Offset), mt_.IoErrorInterface_SetUrl, url);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::Hxx1::ConstFn<S>::GetUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoErrorInterface* o_ = (const IoErrorInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoErrorInterface, o_, IoErrorInterface_GetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoErrorInterface>() : PRIVATE_MAXON_VTABLE(IoErrorInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoErrorInterface_GetUrl_Offset), mt_.IoErrorInterface_GetUrl));
}
auto IoErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto IoErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_iostreams)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_IoErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_IoErrorInterface() { new (s_ui_maxon_IoErrorInterface) maxon::EntityUse(IoErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_IoErrorInterface(IoErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct FileFormatErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FileFormatErrorInterface, typename IoErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<FileFormatErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct FileFormatErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public IoErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename IoErrorInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (FileFormatErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, FileFormatErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto FileFormatErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FileFormatErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_iostreams)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FileFormatErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FileFormatErrorInterface() { new (s_ui_maxon_FileFormatErrorInterface) maxon::EntityUse(FileFormatErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FileFormatErrorInterface(FileFormatErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct UnknownFileSizeErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnknownFileSizeErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<UnknownFileSizeErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct UnknownFileSizeErrorInterface::Hxx2
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
			auto* vt = (UnknownFileSizeErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, UnknownFileSizeErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto UnknownFileSizeErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnknownFileSizeErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_iostreams)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UnknownFileSizeErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UnknownFileSizeErrorInterface() { new (s_ui_maxon_UnknownFileSizeErrorInterface) maxon::EntityUse(UnknownFileSizeErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UnknownFileSizeErrorInterface(UnknownFileSizeErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct BaseStreamInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Close);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(DisableBuffering);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetPosition);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetStreamLength);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Seek);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SeekSupported);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(BaseStreamInterface_GetStreamLength, GetStreamLength, true, maxon::GenericComponent, const, (Result<Int64>));
	maxon::Int BaseStreamInterface_GetStreamLength_Offset;
	PRIVATE_MAXON_MF_POINTER(BaseStreamInterface_GetPosition, GetPosition, true, maxon::GenericComponent, const, (Result<Int64>));
	maxon::Int BaseStreamInterface_GetPosition_Offset;
	PRIVATE_MAXON_MF_POINTER(BaseStreamInterface_Close, Close, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int BaseStreamInterface_Close_Offset;
	PRIVATE_MAXON_MF_POINTER(BaseStreamInterface_SeekSupported, SeekSupported, true, maxon::GenericComponent, const, (Bool));
	maxon::Int BaseStreamInterface_SeekSupported_Offset;
	PRIVATE_MAXON_MF_POINTER(BaseStreamInterface_Seek, Seek, true, maxon::GenericComponent,, (Result<void>), Int64 position);
	maxon::Int BaseStreamInterface_Seek_Offset;
	PRIVATE_MAXON_MF_POINTER(BaseStreamInterface_DisableBuffering, DisableBuffering, true, maxon::GenericComponent,, (void));
	maxon::Int BaseStreamInterface_DisableBuffering_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, GetStreamLength))
	{
		maxon::Tie(BaseStreamInterface_GetStreamLength, BaseStreamInterface_GetStreamLength_Offset) = BaseStreamInterface_GetStreamLength_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, GetPosition))
	{
		maxon::Tie(BaseStreamInterface_GetPosition, BaseStreamInterface_GetPosition_Offset) = BaseStreamInterface_GetPosition_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, Close))
	{
		maxon::Tie(BaseStreamInterface_Close, BaseStreamInterface_Close_Offset) = BaseStreamInterface_Close_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, SeekSupported))
	{
		maxon::Tie(BaseStreamInterface_SeekSupported, BaseStreamInterface_SeekSupported_Offset) = BaseStreamInterface_SeekSupported_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, Seek))
	{
		maxon::Tie(BaseStreamInterface_Seek, BaseStreamInterface_Seek_Offset) = BaseStreamInterface_Seek_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, DisableBuffering))
	{
		maxon::Tie(BaseStreamInterface_DisableBuffering, BaseStreamInterface_DisableBuffering_Offset) = BaseStreamInterface_DisableBuffering_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<BaseStreamInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<BaseStreamInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct BaseStreamInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Close);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(DisableBuffering);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetPosition);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetStreamLength);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Seek);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SeekSupported);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (BaseStreamInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, BaseStreamInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(BaseStreamInterface_GetStreamLength, maxon::GenericComponent, const, (Result<Int64>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetStreamLength(); }
		PRIVATE_MAXON_MF_WRAPPER(BaseStreamInterface_GetPosition, maxon::GenericComponent, const, (Result<Int64>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetPosition(); }
		PRIVATE_MAXON_MF_WRAPPER(BaseStreamInterface_Close, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Close(); }
		PRIVATE_MAXON_MF_WRAPPER(BaseStreamInterface_SeekSupported, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->SeekSupported(); }
		PRIVATE_MAXON_MF_WRAPPER(BaseStreamInterface_Seek, maxon::GenericComponent,, (Result<void>), Int64 position) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Seek(position); }
		PRIVATE_MAXON_MF_WRAPPER(BaseStreamInterface_DisableBuffering, maxon::GenericComponent,, (void)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->DisableBuffering(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::GetStreamLength() const -> Result<Int64>
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BaseStreamInterface_GetStreamLength_Offset), mt_.BaseStreamInterface_GetStreamLength);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::GetPosition() const -> Result<Int64>
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BaseStreamInterface_GetPosition_Offset), mt_.BaseStreamInterface_GetPosition);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Close() -> Result<void>
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BaseStreamInterface_Close_Offset), mt_.BaseStreamInterface_Close);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::SeekSupported() const -> Bool
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.BaseStreamInterface_SeekSupported_Offset), mt_.BaseStreamInterface_SeekSupported);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Seek(Int64 position) -> Result<void>
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BaseStreamInterface_Seek_Offset), mt_.BaseStreamInterface_Seek, position);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::DisableBuffering() -> void
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.BaseStreamInterface_DisableBuffering_Offset), mt_.BaseStreamInterface_DisableBuffering);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::ConstFn<S>::GetStreamLength() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const BaseStreamInterface* o_ = (const BaseStreamInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = BaseStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_GetStreamLength) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_GetStreamLength_Offset), mt_.BaseStreamInterface_GetStreamLength));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::ConstFn<S>::GetPosition() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const BaseStreamInterface* o_ = (const BaseStreamInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = BaseStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_GetPosition) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_GetPosition_Offset), mt_.BaseStreamInterface_GetPosition));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::Fn<S>::Close() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_Close_Offset), mt_.BaseStreamInterface_Close));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::COWFn<S>::Close() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_Close_Offset), mt_.BaseStreamInterface_Close));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::ConstFn<S>::SeekSupported() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const BaseStreamInterface* o_ = (const BaseStreamInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = BaseStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_SeekSupported) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_SeekSupported_Offset), mt_.BaseStreamInterface_SeekSupported));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::Fn<S>::Seek(Int64 position) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_Seek) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_Seek_Offset), mt_.BaseStreamInterface_Seek, position));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::COWFn<S>::Seek(Int64 position) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_Seek) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_Seek_Offset), mt_.BaseStreamInterface_Seek, position));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::Fn<S>::DisableBuffering() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_DisableBuffering) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_DisableBuffering_Offset), mt_.BaseStreamInterface_DisableBuffering);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::COWFn<S>::DisableBuffering() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_DisableBuffering) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_DisableBuffering_Offset), mt_.BaseStreamInterface_DisableBuffering);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto BaseStreamInterface::GetPtr() -> Ptr { return Ptr(this); }
auto BaseStreamInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_iostreams)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_BaseStreamInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_BaseStreamInterface() { new (s_ui_maxon_BaseStreamInterface) maxon::EntityUse(BaseStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_BaseStreamInterface(BaseStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct InputStreamInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(BytesAvailable);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ReadEOS);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Skip);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(InputStreamInterface_BytesAvailable, BytesAvailable, true, maxon::GenericComponent, const, (Result<Int64>));
	maxon::Int InputStreamInterface_BytesAvailable_Offset;
	PRIVATE_MAXON_MF_POINTER(InputStreamInterface_ReadEOS, ReadEOS, true, maxon::GenericComponent,, (Result<Int>), const Block<Byte>& data);
	maxon::Int InputStreamInterface_ReadEOS_Offset;
	PRIVATE_MAXON_MF_POINTER(InputStreamInterface_Skip, Skip, true, maxon::GenericComponent,, (Result<void>), Int64 bytes);
	maxon::Int InputStreamInterface_Skip_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InputStreamInterface, BytesAvailable))
	{
		maxon::Tie(InputStreamInterface_BytesAvailable, InputStreamInterface_BytesAvailable_Offset) = InputStreamInterface_BytesAvailable_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InputStreamInterface, ReadEOS))
	{
		maxon::Tie(InputStreamInterface_ReadEOS, InputStreamInterface_ReadEOS_Offset) = InputStreamInterface_ReadEOS_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InputStreamInterface, Skip))
	{
		maxon::Tie(InputStreamInterface_Skip, InputStreamInterface_Skip_Offset) = InputStreamInterface_Skip_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<InputStreamInterface, typename BaseStreamInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<InputStreamInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct InputStreamInterface::Hxx2
{
	template <typename S> class CWrapper : public BaseStreamInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(BytesAvailable);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ReadEOS);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Skip);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename BaseStreamInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (InputStreamInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, InputStreamInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(InputStreamInterface_BytesAvailable, maxon::GenericComponent, const, (Result<Int64>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->BytesAvailable(); }
		PRIVATE_MAXON_MF_WRAPPER(InputStreamInterface_ReadEOS, maxon::GenericComponent,, (Result<Int>), const Block<Byte>& data) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ReadEOS(data); }
		PRIVATE_MAXON_MF_WRAPPER(InputStreamInterface_Skip, maxon::GenericComponent,, (Result<void>), Int64 bytes) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Skip(bytes); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::BytesAvailable() const -> Result<Int64>
{
	const InputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InputStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.InputStreamInterface_BytesAvailable_Offset), mt_.InputStreamInterface_BytesAvailable);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::ReadEOS(const Block<Byte>& data) -> Result<Int>
{
	const InputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InputStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.InputStreamInterface_ReadEOS_Offset), mt_.InputStreamInterface_ReadEOS, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Skip(Int64 bytes) -> Result<void>
{
	const InputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InputStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.InputStreamInterface_Skip_Offset), mt_.InputStreamInterface_Skip, bytes);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::ConstFn<S>::BytesAvailable() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const InputStreamInterface* o_ = (const InputStreamInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = InputStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_BytesAvailable) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.InputStreamInterface_BytesAvailable_Offset), mt_.InputStreamInterface_BytesAvailable));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::Fn<S>::Read(const Block<Byte>& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Read(data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::COWFn<S>::Read(const Block<Byte>& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION InputStreamInterface::Read on super."); if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Read(data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::Fn<S>::ReadEOS(const Block<Byte>& data) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_ReadEOS) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.InputStreamInterface_ReadEOS_Offset), mt_.InputStreamInterface_ReadEOS, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::COWFn<S>::ReadEOS(const Block<Byte>& data) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_ReadEOS) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.InputStreamInterface_ReadEOS_Offset), mt_.InputStreamInterface_ReadEOS, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::Fn<S>::Skip(Int64 bytes) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_Skip) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.InputStreamInterface_Skip_Offset), mt_.InputStreamInterface_Skip, bytes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::COWFn<S>::Skip(Int64 bytes) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_Skip) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.InputStreamInterface_Skip_Offset), mt_.InputStreamInterface_Skip, bytes));
}
auto InputStreamInterface::GetPtr() -> Ptr { return Ptr(this); }
auto InputStreamInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_iostreams)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_InputStreamInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_InputStreamInterface() { new (s_ui_maxon_InputStreamInterface) maxon::EntityUse(InputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_InputStreamInterface(InputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct OutputStreamInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Flush);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Write);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(OutputStreamInterface_Write, Write, true, maxon::GenericComponent,, (Result<void>), const Block<const Byte>& data);
	maxon::Int OutputStreamInterface_Write_Offset;
	PRIVATE_MAXON_MF_POINTER(OutputStreamInterface_Flush, Flush, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int OutputStreamInterface_Flush_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, OutputStreamInterface, Write))
	{
		maxon::Tie(OutputStreamInterface_Write, OutputStreamInterface_Write_Offset) = OutputStreamInterface_Write_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, OutputStreamInterface, Flush))
	{
		maxon::Tie(OutputStreamInterface_Flush, OutputStreamInterface_Flush_Offset) = OutputStreamInterface_Flush_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<OutputStreamInterface, typename BaseStreamInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<OutputStreamInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct OutputStreamInterface::Hxx2
{
	template <typename S> class CWrapper : public BaseStreamInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Flush);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Write);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename BaseStreamInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (OutputStreamInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, OutputStreamInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(OutputStreamInterface_Write, maxon::GenericComponent,, (Result<void>), const Block<const Byte>& data) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Write(data); }
		PRIVATE_MAXON_MF_WRAPPER(OutputStreamInterface_Flush, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Flush(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Write(const Block<const Byte>& data) -> Result<void>
{
	const OutputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(OutputStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.OutputStreamInterface_Write_Offset), mt_.OutputStreamInterface_Write, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Flush() -> Result<void>
{
	const OutputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(OutputStreamInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.OutputStreamInterface_Flush_Offset), mt_.OutputStreamInterface_Flush);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Hxx1::Fn<S>::Write(const Block<const Byte>& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); OutputStreamInterface* o_ = (OutputStreamInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(OutputStreamInterface, o_, OutputStreamInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<OutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<OutputStreamInterface>() : PRIVATE_MAXON_VTABLE(OutputStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.OutputStreamInterface_Write_Offset), mt_.OutputStreamInterface_Write, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Hxx1::COWFn<S>::Write(const Block<const Byte>& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); OutputStreamInterface* o_ = (OutputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(OutputStreamInterface, o_, OutputStreamInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<OutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<OutputStreamInterface>() : PRIVATE_MAXON_VTABLE(OutputStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.OutputStreamInterface_Write_Offset), mt_.OutputStreamInterface_Write, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Hxx1::Fn<S>::Flush() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); OutputStreamInterface* o_ = (OutputStreamInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(OutputStreamInterface, o_, OutputStreamInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<OutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<OutputStreamInterface>() : PRIVATE_MAXON_VTABLE(OutputStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.OutputStreamInterface_Flush_Offset), mt_.OutputStreamInterface_Flush));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Hxx1::COWFn<S>::Flush() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); OutputStreamInterface* o_ = (OutputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(OutputStreamInterface, o_, OutputStreamInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<OutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<OutputStreamInterface>() : PRIVATE_MAXON_VTABLE(OutputStreamInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.OutputStreamInterface_Flush_Offset), mt_.OutputStreamInterface_Flush));
}
auto OutputStreamInterface::GetPtr() -> Ptr { return Ptr(this); }
auto OutputStreamInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_iostreams)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_OutputStreamInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_OutputStreamInterface() { new (s_ui_maxon_OutputStreamInterface) maxon::EntityUse(OutputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_OutputStreamInterface(OutputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct InOutputStreamInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<InOutputStreamInterface, typename OutputStreamInterface::MTable::template CombinedMTable<typename InputStreamInterface::MTable::template CombinedMTable<S>>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<InOutputStreamInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct InOutputStreamInterface::Hxx2
{
	template <typename S> class CWrapper : public OutputStreamInterface::Hxx2::template CWrapper<typename InputStreamInterface::Hxx2::template CWrapper<S>>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename InputStreamInterface::Hxx2::template CWrapper<S>;
			using Super1 = typename OutputStreamInterface::Hxx2::template CWrapper<Super0>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset) && Super1::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (InOutputStreamInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, InOutputStreamInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto InOutputStreamInterface::GetPtr() -> Ptr { return Ptr(this); }
auto InOutputStreamInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_iostreams)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_InOutputStreamInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_InOutputStreamInterface() { new (s_ui_maxon_InOutputStreamInterface) maxon::EntityUse(InOutputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_InOutputStreamInterface(InOutputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

