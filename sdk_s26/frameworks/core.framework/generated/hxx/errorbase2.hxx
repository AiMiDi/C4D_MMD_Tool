
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
	template <typename S> using CombinedMTable = maxon::CombinedMTable<OutOfMemoryErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
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
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FunctionNotImplementedErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
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
	template <typename S> using CombinedMTable = maxon::CombinedMTable<IllegalArgumentErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
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
	template <typename S> using CombinedMTable = maxon::CombinedMTable<NullptrErrorInterface, typename IllegalArgumentErrorInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
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
	template <typename S> using CombinedMTable = maxon::CombinedMTable<IllegalStateErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
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
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnexpectedErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
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

struct ThreadCancelledErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ThreadCancelledErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ThreadCancelledErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ThreadCancelledErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (ThreadCancelledErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ThreadCancelledErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto ThreadCancelledErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ThreadCancelledErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_errorbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ThreadCancelledErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ThreadCancelledErrorInterface() { new (s_ui_maxon_ThreadCancelledErrorInterface) maxon::EntityUse(ThreadCancelledErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ThreadCancelledErrorInterface(ThreadCancelledErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
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
	Bool (*AggregatedErrorInterface_AddError) (maxon::GenericComponent* this_, const Error& error);
	maxon::Int AggregatedErrorInterface_AddError_Offset;
	Bool (*AggregatedErrorInterface_AddError_1) (maxon::GenericComponent* this_, Error&& error);
	maxon::Int AggregatedErrorInterface_AddError_1_Offset;
	Int (*AggregatedErrorInterface_GetCount) (const maxon::GenericComponent* this_);
	maxon::Int AggregatedErrorInterface_GetCount_Offset;
	const Error& (*AggregatedErrorInterface_GetError) (const maxon::GenericComponent* this_, Int index);
	maxon::Int AggregatedErrorInterface_GetError_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AggregatedErrorInterface, AddError))
	{
		AggregatedErrorInterface_AddError = &W::AggregatedErrorInterface_AddError;
		AggregatedErrorInterface_AddError_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AggregatedErrorInterface, AddError))
	{
		AggregatedErrorInterface_AddError_1 = &W::AggregatedErrorInterface_AddError_1;
		AggregatedErrorInterface_AddError_1_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AggregatedErrorInterface, GetCount))
	{
		AggregatedErrorInterface_GetCount = &W::AggregatedErrorInterface_GetCount;
		AggregatedErrorInterface_GetCount_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, AggregatedErrorInterface, GetError))
	{
		AggregatedErrorInterface_GetError = &W::AggregatedErrorInterface_GetError;
		AggregatedErrorInterface_GetError_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<AggregatedErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (AggregatedErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, AggregatedErrorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Bool AggregatedErrorInterface_AddError(maxon::GenericComponent* this_, const Error& error) { return ((typename S::Implementation*) this_)->AddError(error); }
		static Bool AggregatedErrorInterface_AddError_1(maxon::GenericComponent* this_, Error&& error) { return ((typename S::Implementation*) this_)->AddError(std::forward<Error>(error)); }
		static Int AggregatedErrorInterface_GetCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetCount(); }
		static const Error& AggregatedErrorInterface_GetError(const maxon::GenericComponent* this_, Int index) { return ((const typename S::Implementation*) this_)->GetError(index); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::AddError(const Error& error) -> Bool
{
	const AggregatedErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, this); return mt_.AggregatedErrorInterface_AddError((maxon::GenericComponent*) this + mt_.AggregatedErrorInterface_AddError_Offset, error);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::AddError(Error&& error) -> Bool
{
	const AggregatedErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, this); return mt_.AggregatedErrorInterface_AddError_1((maxon::GenericComponent*) this + mt_.AggregatedErrorInterface_AddError_1_Offset, std::forward<Error>(error));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::GetCount() const -> Int
{
	const AggregatedErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, this); return mt_.AggregatedErrorInterface_GetCount((const maxon::GenericComponent*) this + mt_.AggregatedErrorInterface_GetCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::GetError(Int index) const -> const Error&
{
	const AggregatedErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, this); return mt_.AggregatedErrorInterface_GetError((const maxon::GenericComponent*) this + mt_.AggregatedErrorInterface_GetError_Offset, index);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::Hxx1::Fn<S>::AddError(const Error& error) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); AggregatedErrorInterface* o_ = (AggregatedErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AggregatedErrorInterface, o_, AggregatedErrorInterface_AddError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<AggregatedErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AggregatedErrorInterface>() : PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, o_); 
	return (mt_.AggregatedErrorInterface_AddError(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.AggregatedErrorInterface_AddError_Offset, error));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::Hxx1::COWFn<S>::AddError(const Error& error) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); AggregatedErrorInterface* o_ = (AggregatedErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AggregatedErrorInterface, o_, AggregatedErrorInterface_AddError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<AggregatedErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AggregatedErrorInterface>() : PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, o_); 
	return (mt_.AggregatedErrorInterface_AddError(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.AggregatedErrorInterface_AddError_Offset, error));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::Hxx1::Fn<S>::AddError(Error&& error) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); AggregatedErrorInterface* o_ = (AggregatedErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AggregatedErrorInterface, o_, AggregatedErrorInterface_AddError_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<AggregatedErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AggregatedErrorInterface>() : PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, o_); 
	return (mt_.AggregatedErrorInterface_AddError_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.AggregatedErrorInterface_AddError_1_Offset, std::forward<Error>(error)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::Hxx1::COWFn<S>::AddError(Error&& error) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); AggregatedErrorInterface* o_ = (AggregatedErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AggregatedErrorInterface, o_, AggregatedErrorInterface_AddError_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<AggregatedErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AggregatedErrorInterface>() : PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, o_); 
	return (mt_.AggregatedErrorInterface_AddError_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.AggregatedErrorInterface_AddError_1_Offset, std::forward<Error>(error)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::Hxx1::ConstFn<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const AggregatedErrorInterface* o_ = (const AggregatedErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = AggregatedErrorInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AggregatedErrorInterface, o_, AggregatedErrorInterface_GetCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<AggregatedErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AggregatedErrorInterface>() : PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, o_); 
	return (mt_.AggregatedErrorInterface_GetCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.AggregatedErrorInterface_GetCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::Hxx1::ConstFn<S>::GetError(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Error&>, const Error&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Error&>, const Error&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const AggregatedErrorInterface* o_ = (const AggregatedErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = AggregatedErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Error&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AggregatedErrorInterface, o_, AggregatedErrorInterface_GetError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<AggregatedErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AggregatedErrorInterface>() : PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, o_); 
	return (mt_.AggregatedErrorInterface_GetError(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.AggregatedErrorInterface_GetError_Offset, index));
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

