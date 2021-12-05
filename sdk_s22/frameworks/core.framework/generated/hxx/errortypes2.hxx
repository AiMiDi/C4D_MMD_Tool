
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct UnsupportedArgumentErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnsupportedArgumentErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(UnsupportedArgumentErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct UnsupportedArgumentErrorInterface::Hxx2
{
	template <typename S> class Wrapper : public ErrorInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

auto UnsupportedArgumentErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnsupportedArgumentErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UnsupportedArgumentErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UnsupportedArgumentErrorInterface() { new (s_ui_maxon_UnsupportedArgumentErrorInterface) maxon::EntityUse(UnsupportedArgumentErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errortypes.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UnsupportedArgumentErrorInterface(UnsupportedArgumentErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errortypes.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct UnresolvedErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnresolvedErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(UnresolvedErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct UnresolvedErrorInterface::Hxx2
{
	template <typename S> class Wrapper : public ErrorInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

auto UnresolvedErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnresolvedErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UnresolvedErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UnresolvedErrorInterface() { new (s_ui_maxon_UnresolvedErrorInterface) maxon::EntityUse(UnresolvedErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errortypes.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UnresolvedErrorInterface(UnresolvedErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errortypes.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct UnknownErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnknownErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(UnknownErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct UnknownErrorInterface::Hxx2
{
	template <typename S> class Wrapper : public ErrorInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

auto UnknownErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnknownErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UnknownErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UnknownErrorInterface() { new (s_ui_maxon_UnknownErrorInterface) maxon::EntityUse(UnknownErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errortypes.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UnknownErrorInterface(UnknownErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errortypes.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct UnsupportedOperationErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnsupportedOperationErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(UnsupportedOperationErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct UnsupportedOperationErrorInterface::Hxx2
{
	template <typename S> class Wrapper : public ErrorInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

auto UnsupportedOperationErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnsupportedOperationErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UnsupportedOperationErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UnsupportedOperationErrorInterface() { new (s_ui_maxon_UnsupportedOperationErrorInterface) maxon::EntityUse(UnsupportedOperationErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errortypes.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UnsupportedOperationErrorInterface(UnsupportedOperationErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errortypes.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct ShutdownErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ShutdownErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(ShutdownErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ShutdownErrorInterface::Hxx2
{
	template <typename S> class Wrapper : public ErrorInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

auto ShutdownErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ShutdownErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ShutdownErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ShutdownErrorInterface() { new (s_ui_maxon_ShutdownErrorInterface) maxon::EntityUse(ShutdownErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errortypes.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ShutdownErrorInterface(ShutdownErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errortypes.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct DisabledErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DisabledErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(DisabledErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DisabledErrorInterface::Hxx2
{
	template <typename S> class Wrapper : public ErrorInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

auto DisabledErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DisabledErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DisabledErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DisabledErrorInterface() { new (s_ui_maxon_DisabledErrorInterface) maxon::EntityUse(DisabledErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errortypes.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DisabledErrorInterface(DisabledErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errortypes.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct ErrnoErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ErrnoErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(ErrnoErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ErrnoErrorInterface::Hxx2
{
	template <typename S> class Wrapper : public ErrorInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrnoErrorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetErrorCode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ErrnoErrorInterface::GetErrorCode on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrnoErrorInterface* o_ = (const ErrnoErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrnoErrorInterface::NullValuePtr(); if (!o_) return 0; } 
	return (o_->GetErrorCode());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrnoErrorInterface::Hxx1::ReferenceFunctionsImpl<S>::SetErrorCode(Int errorCode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ErrnoErrorInterface* o_ = (ErrnoErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	o_->SetErrorCode(errorCode);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrnoErrorInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetErrorCode(Int errorCode) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ErrnoErrorInterface::SetErrorCode on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ErrnoErrorInterface* o_ = (ErrnoErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	o_->SetErrorCode(errorCode);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto ErrnoErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ErrnoErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ErrnoErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ErrnoErrorInterface() { new (s_ui_maxon_ErrnoErrorInterface) maxon::EntityUse(ErrnoErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errortypes.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ErrnoErrorInterface(ErrnoErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errortypes.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

