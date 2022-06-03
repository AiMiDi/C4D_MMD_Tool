
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
	void (*IoErrorInterface_SetUrl) (maxon::GenericComponent* this_, const Url& url);
	maxon::Int IoErrorInterface_SetUrl_Offset;
	const Url& (*IoErrorInterface_GetUrl) (const maxon::GenericComponent* this_);
	maxon::Int IoErrorInterface_GetUrl_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoErrorInterface, SetUrl))
	{
		IoErrorInterface_SetUrl = &W::IoErrorInterface_SetUrl;
		IoErrorInterface_SetUrl_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoErrorInterface, GetUrl))
	{
		IoErrorInterface_GetUrl = &W::IoErrorInterface_GetUrl;
		IoErrorInterface_GetUrl_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (IoErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, IoErrorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static void IoErrorInterface_SetUrl(maxon::GenericComponent* this_, const Url& url) { return ((typename S::Implementation*) this_)->SetUrl(url); }
		static const Url& IoErrorInterface_GetUrl(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetUrl(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::SetUrl(const Url& url) -> void
{
	const IoErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoErrorInterface, this); return mt_.IoErrorInterface_SetUrl((maxon::GenericComponent*) this + mt_.IoErrorInterface_SetUrl_Offset, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::GetUrl() const -> const Url&
{
	const IoErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoErrorInterface, this); return mt_.IoErrorInterface_GetUrl((const maxon::GenericComponent*) this + mt_.IoErrorInterface_GetUrl_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::Hxx1::Fn<S>::SetUrl(const Url& url) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoErrorInterface* o_ = (IoErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoErrorInterface, o_, IoErrorInterface_SetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoErrorInterface>() : PRIVATE_MAXON_VTABLE(IoErrorInterface, o_); 
	mt_.IoErrorInterface_SetUrl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoErrorInterface_SetUrl_Offset, url);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::Hxx1::COWFn<S>::SetUrl(const Url& url) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoErrorInterface* o_ = (IoErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoErrorInterface, o_, IoErrorInterface_SetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoErrorInterface>() : PRIVATE_MAXON_VTABLE(IoErrorInterface, o_); 
	mt_.IoErrorInterface_SetUrl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.IoErrorInterface_SetUrl_Offset, url);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::Hxx1::ConstFn<S>::GetUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoErrorInterface* o_ = (const IoErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoErrorInterface, o_, IoErrorInterface_GetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoErrorInterface>() : PRIVATE_MAXON_VTABLE(IoErrorInterface, o_); 
	return (mt_.IoErrorInterface_GetUrl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoErrorInterface_GetUrl_Offset));
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
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
	Result<Int64> (*BaseStreamInterface_GetStreamLength) (const maxon::GenericComponent* this_);
	maxon::Int BaseStreamInterface_GetStreamLength_Offset;
	Result<Int64> (*BaseStreamInterface_GetPosition) (const maxon::GenericComponent* this_);
	maxon::Int BaseStreamInterface_GetPosition_Offset;
	Result<void> (*BaseStreamInterface_Close) (maxon::GenericComponent* this_);
	maxon::Int BaseStreamInterface_Close_Offset;
	Bool (*BaseStreamInterface_SeekSupported) (const maxon::GenericComponent* this_);
	maxon::Int BaseStreamInterface_SeekSupported_Offset;
	Result<void> (*BaseStreamInterface_Seek) (maxon::GenericComponent* this_, Int64 position);
	maxon::Int BaseStreamInterface_Seek_Offset;
	void (*BaseStreamInterface_DisableBuffering) (maxon::GenericComponent* this_);
	maxon::Int BaseStreamInterface_DisableBuffering_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, GetStreamLength))
	{
		BaseStreamInterface_GetStreamLength = &W::BaseStreamInterface_GetStreamLength;
		BaseStreamInterface_GetStreamLength_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, GetPosition))
	{
		BaseStreamInterface_GetPosition = &W::BaseStreamInterface_GetPosition;
		BaseStreamInterface_GetPosition_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, Close))
	{
		BaseStreamInterface_Close = &W::BaseStreamInterface_Close;
		BaseStreamInterface_Close_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, SeekSupported))
	{
		BaseStreamInterface_SeekSupported = &W::BaseStreamInterface_SeekSupported;
		BaseStreamInterface_SeekSupported_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, Seek))
	{
		BaseStreamInterface_Seek = &W::BaseStreamInterface_Seek;
		BaseStreamInterface_Seek_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, DisableBuffering))
	{
		BaseStreamInterface_DisableBuffering = &W::BaseStreamInterface_DisableBuffering;
		BaseStreamInterface_DisableBuffering_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (BaseStreamInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, BaseStreamInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<Int64> BaseStreamInterface_GetStreamLength(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetStreamLength(); }
		static Result<Int64> BaseStreamInterface_GetPosition(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetPosition(); }
		static Result<void> BaseStreamInterface_Close(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Close(); }
		static Bool BaseStreamInterface_SeekSupported(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->SeekSupported(); }
		static Result<void> BaseStreamInterface_Seek(maxon::GenericComponent* this_, Int64 position) { return ((typename S::Implementation*) this_)->Seek(position); }
		static void BaseStreamInterface_DisableBuffering(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->DisableBuffering(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::GetStreamLength() const -> Result<Int64>
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return mt_.BaseStreamInterface_GetStreamLength((const maxon::GenericComponent*) this + mt_.BaseStreamInterface_GetStreamLength_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::GetPosition() const -> Result<Int64>
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return mt_.BaseStreamInterface_GetPosition((const maxon::GenericComponent*) this + mt_.BaseStreamInterface_GetPosition_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Close() -> Result<void>
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return mt_.BaseStreamInterface_Close((maxon::GenericComponent*) this + mt_.BaseStreamInterface_Close_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::SeekSupported() const -> Bool
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return mt_.BaseStreamInterface_SeekSupported((const maxon::GenericComponent*) this + mt_.BaseStreamInterface_SeekSupported_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Seek(Int64 position) -> Result<void>
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return mt_.BaseStreamInterface_Seek((maxon::GenericComponent*) this + mt_.BaseStreamInterface_Seek_Offset, position);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::DisableBuffering() -> void
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return mt_.BaseStreamInterface_DisableBuffering((maxon::GenericComponent*) this + mt_.BaseStreamInterface_DisableBuffering_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::ConstFn<S>::GetStreamLength() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BaseStreamInterface* o_ = (const BaseStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BaseStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_GetStreamLength) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (mt_.BaseStreamInterface_GetStreamLength(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_GetStreamLength_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::ConstFn<S>::GetPosition() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BaseStreamInterface* o_ = (const BaseStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BaseStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_GetPosition) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (mt_.BaseStreamInterface_GetPosition(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_GetPosition_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::Fn<S>::Close() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (mt_.BaseStreamInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::COWFn<S>::Close() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (mt_.BaseStreamInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::ConstFn<S>::SeekSupported() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BaseStreamInterface* o_ = (const BaseStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BaseStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_SeekSupported) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (mt_.BaseStreamInterface_SeekSupported(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_SeekSupported_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::Fn<S>::Seek(Int64 position) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_Seek) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (mt_.BaseStreamInterface_Seek(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_Seek_Offset, position));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::COWFn<S>::Seek(Int64 position) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_Seek) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (mt_.BaseStreamInterface_Seek(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_Seek_Offset, position));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::Fn<S>::DisableBuffering() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_DisableBuffering) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	mt_.BaseStreamInterface_DisableBuffering(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_DisableBuffering_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::COWFn<S>::DisableBuffering() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_DisableBuffering) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	mt_.BaseStreamInterface_DisableBuffering(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.BaseStreamInterface_DisableBuffering_Offset);
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
	Result<Int64> (*InputStreamInterface_BytesAvailable) (const maxon::GenericComponent* this_);
	maxon::Int InputStreamInterface_BytesAvailable_Offset;
	Result<Int> (*InputStreamInterface_ReadEOS) (maxon::GenericComponent* this_, const Block<Byte>& data);
	maxon::Int InputStreamInterface_ReadEOS_Offset;
	Result<void> (*InputStreamInterface_Skip) (maxon::GenericComponent* this_, Int64 bytes);
	maxon::Int InputStreamInterface_Skip_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InputStreamInterface, BytesAvailable))
	{
		InputStreamInterface_BytesAvailable = &W::InputStreamInterface_BytesAvailable;
		InputStreamInterface_BytesAvailable_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InputStreamInterface, ReadEOS))
	{
		InputStreamInterface_ReadEOS = &W::InputStreamInterface_ReadEOS;
		InputStreamInterface_ReadEOS_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InputStreamInterface, Skip))
	{
		InputStreamInterface_Skip = &W::InputStreamInterface_Skip;
		InputStreamInterface_Skip_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (InputStreamInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, InputStreamInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<Int64> InputStreamInterface_BytesAvailable(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->BytesAvailable(); }
		static Result<Int> InputStreamInterface_ReadEOS(maxon::GenericComponent* this_, const Block<Byte>& data) { return ((typename S::Implementation*) this_)->ReadEOS(data); }
		static Result<void> InputStreamInterface_Skip(maxon::GenericComponent* this_, Int64 bytes) { return ((typename S::Implementation*) this_)->Skip(bytes); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::BytesAvailable() const -> Result<Int64>
{
	const InputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InputStreamInterface, this); return mt_.InputStreamInterface_BytesAvailable((const maxon::GenericComponent*) this + mt_.InputStreamInterface_BytesAvailable_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::ReadEOS(const Block<Byte>& data) -> Result<Int>
{
	const InputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InputStreamInterface, this); return mt_.InputStreamInterface_ReadEOS((maxon::GenericComponent*) this + mt_.InputStreamInterface_ReadEOS_Offset, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Skip(Int64 bytes) -> Result<void>
{
	const InputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InputStreamInterface, this); return mt_.InputStreamInterface_Skip((maxon::GenericComponent*) this + mt_.InputStreamInterface_Skip_Offset, bytes);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::ConstFn<S>::BytesAvailable() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const InputStreamInterface* o_ = (const InputStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = InputStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_BytesAvailable) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (mt_.InputStreamInterface_BytesAvailable(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.InputStreamInterface_BytesAvailable_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::Fn<S>::Read(const Block<Byte>& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Read(data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::COWFn<S>::Read(const Block<Byte>& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION InputStreamInterface::Read on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (o_->Read(data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::Fn<S>::ReadEOS(const Block<Byte>& data) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_ReadEOS) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (mt_.InputStreamInterface_ReadEOS(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.InputStreamInterface_ReadEOS_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::COWFn<S>::ReadEOS(const Block<Byte>& data) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_ReadEOS) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (mt_.InputStreamInterface_ReadEOS(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.InputStreamInterface_ReadEOS_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::Fn<S>::Skip(Int64 bytes) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_Skip) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (mt_.InputStreamInterface_Skip(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.InputStreamInterface_Skip_Offset, bytes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::COWFn<S>::Skip(Int64 bytes) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_Skip) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (mt_.InputStreamInterface_Skip(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.InputStreamInterface_Skip_Offset, bytes));
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
	Result<void> (*OutputStreamInterface_Write) (maxon::GenericComponent* this_, const Block<const Byte>& data);
	maxon::Int OutputStreamInterface_Write_Offset;
	Result<void> (*OutputStreamInterface_Flush) (maxon::GenericComponent* this_);
	maxon::Int OutputStreamInterface_Flush_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, OutputStreamInterface, Write))
	{
		OutputStreamInterface_Write = &W::OutputStreamInterface_Write;
		OutputStreamInterface_Write_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, OutputStreamInterface, Flush))
	{
		OutputStreamInterface_Flush = &W::OutputStreamInterface_Flush;
		OutputStreamInterface_Flush_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (OutputStreamInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, OutputStreamInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> OutputStreamInterface_Write(maxon::GenericComponent* this_, const Block<const Byte>& data) { return ((typename S::Implementation*) this_)->Write(data); }
		static Result<void> OutputStreamInterface_Flush(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Flush(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Write(const Block<const Byte>& data) -> Result<void>
{
	const OutputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(OutputStreamInterface, this); return mt_.OutputStreamInterface_Write((maxon::GenericComponent*) this + mt_.OutputStreamInterface_Write_Offset, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Flush() -> Result<void>
{
	const OutputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(OutputStreamInterface, this); return mt_.OutputStreamInterface_Flush((maxon::GenericComponent*) this + mt_.OutputStreamInterface_Flush_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Hxx1::Fn<S>::Write(const Block<const Byte>& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); OutputStreamInterface* o_ = (OutputStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(OutputStreamInterface, o_, OutputStreamInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<OutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<OutputStreamInterface>() : PRIVATE_MAXON_VTABLE(OutputStreamInterface, o_); 
	return (mt_.OutputStreamInterface_Write(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.OutputStreamInterface_Write_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Hxx1::COWFn<S>::Write(const Block<const Byte>& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); OutputStreamInterface* o_ = (OutputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(OutputStreamInterface, o_, OutputStreamInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<OutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<OutputStreamInterface>() : PRIVATE_MAXON_VTABLE(OutputStreamInterface, o_); 
	return (mt_.OutputStreamInterface_Write(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.OutputStreamInterface_Write_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Hxx1::Fn<S>::Flush() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); OutputStreamInterface* o_ = (OutputStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(OutputStreamInterface, o_, OutputStreamInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<OutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<OutputStreamInterface>() : PRIVATE_MAXON_VTABLE(OutputStreamInterface, o_); 
	return (mt_.OutputStreamInterface_Flush(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.OutputStreamInterface_Flush_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Hxx1::COWFn<S>::Flush() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); OutputStreamInterface* o_ = (OutputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(OutputStreamInterface, o_, OutputStreamInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<OutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<OutputStreamInterface>() : PRIVATE_MAXON_VTABLE(OutputStreamInterface, o_); 
	return (mt_.OutputStreamInterface_Flush(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.OutputStreamInterface_Flush_Offset));
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset) && Super1::InitMTablesWithBases(info, offset))) return false;
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

