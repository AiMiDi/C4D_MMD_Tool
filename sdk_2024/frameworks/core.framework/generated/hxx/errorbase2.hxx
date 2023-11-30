
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct OutOfMemoryErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<OutOfMemoryErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<OutOfMemoryErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct OutOfMemoryErrorInterface::Hxx2
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
			auto* vt = (OutOfMemoryErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, OutOfMemoryErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto OutOfMemoryErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto OutOfMemoryErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errorbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_OutOfMemoryErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_OutOfMemoryErrorInterface() { new (s_ui_maxon_OutOfMemoryErrorInterface) maxon::EntityUse(OutOfMemoryErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_OutOfMemoryErrorInterface(OutOfMemoryErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct FunctionNotImplementedErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<FunctionNotImplementedErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<FunctionNotImplementedErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct FunctionNotImplementedErrorInterface::Hxx2
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
			auto* vt = (FunctionNotImplementedErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, FunctionNotImplementedErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto FunctionNotImplementedErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FunctionNotImplementedErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errorbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FunctionNotImplementedErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FunctionNotImplementedErrorInterface() { new (s_ui_maxon_FunctionNotImplementedErrorInterface) maxon::EntityUse(FunctionNotImplementedErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FunctionNotImplementedErrorInterface(FunctionNotImplementedErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct IllegalArgumentErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<IllegalArgumentErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<IllegalArgumentErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct IllegalArgumentErrorInterface::Hxx2
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
			auto* vt = (IllegalArgumentErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, IllegalArgumentErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto IllegalArgumentErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto IllegalArgumentErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errorbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_IllegalArgumentErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_IllegalArgumentErrorInterface() { new (s_ui_maxon_IllegalArgumentErrorInterface) maxon::EntityUse(IllegalArgumentErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_IllegalArgumentErrorInterface(IllegalArgumentErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct NullptrErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<NullptrErrorInterface, typename IllegalArgumentErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<NullptrErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct NullptrErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public IllegalArgumentErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename IllegalArgumentErrorInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (NullptrErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, NullptrErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto NullptrErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto NullptrErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errorbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_NullptrErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_NullptrErrorInterface() { new (s_ui_maxon_NullptrErrorInterface) maxon::EntityUse(NullptrErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_NullptrErrorInterface(NullptrErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct IllegalStateErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<IllegalStateErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<IllegalStateErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct IllegalStateErrorInterface::Hxx2
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
			auto* vt = (IllegalStateErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, IllegalStateErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto IllegalStateErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto IllegalStateErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errorbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_IllegalStateErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_IllegalStateErrorInterface() { new (s_ui_maxon_IllegalStateErrorInterface) maxon::EntityUse(IllegalStateErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_IllegalStateErrorInterface(IllegalStateErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct UnexpectedErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<UnexpectedErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<UnexpectedErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct UnexpectedErrorInterface::Hxx2
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
			auto* vt = (UnexpectedErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, UnexpectedErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto UnexpectedErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnexpectedErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errorbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UnexpectedErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UnexpectedErrorInterface() { new (s_ui_maxon_UnexpectedErrorInterface) maxon::EntityUse(UnexpectedErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UnexpectedErrorInterface(UnexpectedErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct OperationCancelledErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<OperationCancelledErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<OperationCancelledErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct OperationCancelledErrorInterface::Hxx2
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
			auto* vt = (OperationCancelledErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, OperationCancelledErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto OperationCancelledErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto OperationCancelledErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errorbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_OperationCancelledErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_OperationCancelledErrorInterface() { new (s_ui_maxon_OperationCancelledErrorInterface) maxon::EntityUse(OperationCancelledErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_OperationCancelledErrorInterface(OperationCancelledErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct AggregatedErrorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddError);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetError);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(AggregatedErrorInterface_AddError, AddError, true, maxon::GenericComponent,, (Bool), const Error& error);
	maxon::Int AggregatedErrorInterface_AddError_Offset;
	PRIVATE_MAXON_MF_POINTER(AggregatedErrorInterface_AddError_1, AddError, true, maxon::GenericComponent,, (Bool), Error&& error);
	maxon::Int AggregatedErrorInterface_AddError_1_Offset;
	PRIVATE_MAXON_MF_POINTER(AggregatedErrorInterface_GetCount, GetCount, true, maxon::GenericComponent, const, (Int));
	maxon::Int AggregatedErrorInterface_GetCount_Offset;
	PRIVATE_MAXON_MF_POINTER(AggregatedErrorInterface_GetError, GetError, true, maxon::GenericComponent, const, (const Error&), Int index);
	maxon::Int AggregatedErrorInterface_GetError_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AggregatedErrorInterface, AddError))
	{
		maxon::Tie(AggregatedErrorInterface_AddError, AggregatedErrorInterface_AddError_Offset) = AggregatedErrorInterface_AddError_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AggregatedErrorInterface, AddError))
	{
		maxon::Tie(AggregatedErrorInterface_AddError_1, AggregatedErrorInterface_AddError_1_Offset) = AggregatedErrorInterface_AddError_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AggregatedErrorInterface, GetCount))
	{
		maxon::Tie(AggregatedErrorInterface_GetCount, AggregatedErrorInterface_GetCount_Offset) = AggregatedErrorInterface_GetCount_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AggregatedErrorInterface, GetError))
	{
		maxon::Tie(AggregatedErrorInterface_GetError, AggregatedErrorInterface_GetError_Offset) = AggregatedErrorInterface_GetError_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<AggregatedErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<AggregatedErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct AggregatedErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddError);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCount);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetError);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (AggregatedErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, AggregatedErrorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(AggregatedErrorInterface_AddError, maxon::GenericComponent,, (Bool), const Error& error) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->AddError(error); }
		PRIVATE_MAXON_MF_WRAPPER(AggregatedErrorInterface_AddError_1, maxon::GenericComponent,, (Bool), Error&& error) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->AddError(std::forward<Error>(error)); }
		PRIVATE_MAXON_MF_WRAPPER(AggregatedErrorInterface_GetCount, maxon::GenericComponent, const, (Int)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetCount(); }
		PRIVATE_MAXON_MF_WRAPPER(AggregatedErrorInterface_GetError, maxon::GenericComponent, const, (const Error&), Int index) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetError(index); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::AddError(const Error& error) -> Bool
{
	const AggregatedErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.AggregatedErrorInterface_AddError_Offset), mt_.AggregatedErrorInterface_AddError, error);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::AddError(Error&& error) -> Bool
{
	const AggregatedErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.AggregatedErrorInterface_AddError_1_Offset), mt_.AggregatedErrorInterface_AddError_1, std::forward<Error>(error));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::GetCount() const -> Int
{
	const AggregatedErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.AggregatedErrorInterface_GetCount_Offset), mt_.AggregatedErrorInterface_GetCount);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::GetError(Int index) const -> const Error&
{
	const AggregatedErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.AggregatedErrorInterface_GetError_Offset), mt_.AggregatedErrorInterface_GetError, index);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::Hxx1::Fn<S>::AddError(const Error& error) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXNONCONST(, , false, maxon::PrivateLogNullptrError(false)) HXXTABLE(AggregatedErrorInterface_AddError); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.AggregatedErrorInterface_AddError_Offset), mt_.AggregatedErrorInterface_AddError, error));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::Hxx1::COWFn<S>::AddError(const Error& error) -> HXXADDRET1(Bool)
{
	HXXRETURN0(HXXADDRET1(Bool)); HXXRES; HXXNONCONST(, MakeWritable(false)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(AggregatedErrorInterface_AddError); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.AggregatedErrorInterface_AddError_Offset), mt_.AggregatedErrorInterface_AddError, error));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::Hxx1::Fn<S>::AddError(Error&& error) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXNONCONST(, , false, maxon::PrivateLogNullptrError(false)) HXXTABLE(AggregatedErrorInterface_AddError_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.AggregatedErrorInterface_AddError_1_Offset), mt_.AggregatedErrorInterface_AddError_1, std::forward<Error>(error)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::Hxx1::COWFn<S>::AddError(Error&& error) -> HXXADDRET1(Bool)
{
	HXXRETURN0(HXXADDRET1(Bool)); HXXRES; HXXNONCONST(, MakeWritable(false)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(AggregatedErrorInterface_AddError_1); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.AggregatedErrorInterface_AddError_1_Offset), mt_.AggregatedErrorInterface_AddError_1, std::forward<Error>(error)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::Hxx1::ConstFn<S>::GetCount() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) HXXTABLE(AggregatedErrorInterface_GetCount); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.AggregatedErrorInterface_GetCount_Offset), mt_.AggregatedErrorInterface_GetCount));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::Hxx1::ConstFn<S>::GetError(Int index) const -> HXXADDRET2(const Error&)
{
	HXXRETURN0(HXXADDRET2(const Error&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const Error&)) HXXTABLE(AggregatedErrorInterface_GetError); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.AggregatedErrorInterface_GetError_Offset), mt_.AggregatedErrorInterface_GetError, index));
}
auto AggregatedErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto AggregatedErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errorbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_AggregatedErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_AggregatedErrorInterface() { new (s_ui_maxon_AggregatedErrorInterface) maxon::EntityUse(AggregatedErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_AggregatedErrorInterface(AggregatedErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

