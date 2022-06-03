
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnsupportedArgumentErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<UnsupportedArgumentErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct UnsupportedArgumentErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (UnsupportedArgumentErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, UnsupportedArgumentErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto UnsupportedArgumentErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnsupportedArgumentErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errortypes)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnresolvedErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<UnresolvedErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct UnresolvedErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (UnresolvedErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, UnresolvedErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto UnresolvedErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnresolvedErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errortypes)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnknownErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<UnknownErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct UnknownErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (UnknownErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, UnknownErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto UnknownErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnknownErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errortypes)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnsupportedOperationErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<UnsupportedOperationErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct UnsupportedOperationErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (UnsupportedOperationErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, UnsupportedOperationErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto UnsupportedOperationErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnsupportedOperationErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errortypes)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ShutdownErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ShutdownErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ShutdownErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ShutdownErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ShutdownErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto ShutdownErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ShutdownErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errortypes)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DisabledErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DisabledErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DisabledErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (DisabledErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DisabledErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto DisabledErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DisabledErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errortypes)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ErrnoErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ErrnoErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ErrnoErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ErrnoErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ErrnoErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrnoErrorInterface::Hxx1::ConstFn<S>::GetErrorCode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ErrnoErrorInterface::GetErrorCode on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrnoErrorInterface* o_ = (const ErrnoErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = ErrnoErrorInterface::NullValuePtr(); if (!o_) return 0; } 
	return (o_->GetErrorCode());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrnoErrorInterface::Hxx1::Fn<S>::SetErrorCode(Int errorCode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ErrnoErrorInterface* o_ = (ErrnoErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	o_->SetErrorCode(errorCode);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrnoErrorInterface::Hxx1::COWFn<S>::SetErrorCode(Int errorCode) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ErrnoErrorInterface::SetErrorCode on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ErrnoErrorInterface* o_ = (ErrnoErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	o_->SetErrorCode(errorCode);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto ErrnoErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ErrnoErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errortypes)
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

