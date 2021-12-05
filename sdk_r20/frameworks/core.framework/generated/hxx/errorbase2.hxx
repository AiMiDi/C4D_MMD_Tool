
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct OutOfMemoryErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<OutOfMemoryErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(OutOfMemoryErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class OutOfMemoryErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


auto OutOfMemoryErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto OutOfMemoryErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_OutOfMemoryErrorInterface(OutOfMemoryErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif

struct FunctionNotImplementedErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FunctionNotImplementedErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(FunctionNotImplementedErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class FunctionNotImplementedErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


auto FunctionNotImplementedErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FunctionNotImplementedErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_FunctionNotImplementedErrorInterface(FunctionNotImplementedErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
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
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnresolvedErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(UnresolvedErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class UnresolvedErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


auto UnresolvedErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnresolvedErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_UnresolvedErrorInterface(UnresolvedErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
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
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnsupportedOperationErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(UnsupportedOperationErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class UnsupportedOperationErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


auto UnsupportedOperationErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnsupportedOperationErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_UnsupportedOperationErrorInterface(UnsupportedOperationErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif

struct ThreadCancelledErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ThreadCancelledErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(ThreadCancelledErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class ThreadCancelledErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


auto ThreadCancelledErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ThreadCancelledErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_ThreadCancelledErrorInterface(ThreadCancelledErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif

struct IllegalArgumentErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<IllegalArgumentErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(IllegalArgumentErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class IllegalArgumentErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


auto IllegalArgumentErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto IllegalArgumentErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_IllegalArgumentErrorInterface(IllegalArgumentErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif

struct UnsupportedArgumentErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnsupportedArgumentErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(UnsupportedArgumentErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class UnsupportedArgumentErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


auto UnsupportedArgumentErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnsupportedArgumentErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_UnsupportedArgumentErrorInterface(UnsupportedArgumentErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif

struct NullptrErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!IllegalArgumentErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<NullptrErrorInterface, IllegalArgumentErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(NullptrErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class NullptrErrorInterface::Wrapper : public IllegalArgumentErrorInterface::Wrapper<S>
{
public:
};


auto NullptrErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto NullptrErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_NullptrErrorInterface(NullptrErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif

struct IllegalStateErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<IllegalStateErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(IllegalStateErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class IllegalStateErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


auto IllegalStateErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto IllegalStateErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_IllegalStateErrorInterface(IllegalStateErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
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
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnknownErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(UnknownErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class UnknownErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


auto UnknownErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnknownErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_UnknownErrorInterface(UnknownErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
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
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ShutdownErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(ShutdownErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class ShutdownErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


auto ShutdownErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ShutdownErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_ShutdownErrorInterface(ShutdownErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif

struct UnexpectedErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnexpectedErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(UnexpectedErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class UnexpectedErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


auto UnexpectedErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnexpectedErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_UnexpectedErrorInterface(UnexpectedErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
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
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<ErrnoErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(ErrnoErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class ErrnoErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrnoErrorInterface::ConstReferenceFunctionsImpl<S>::GetErrorCode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ErrnoErrorInterface::GetErrorCode on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const ErrnoErrorInterface* o_ = (const ErrnoErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = ErrnoErrorInterface::NullValuePtr(); if (!o_) return 0; } 
	return (o_->GetErrorCode());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrnoErrorInterface::ReferenceFunctionsImpl<S>::SetErrorCode(Int errorCode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ErrnoErrorInterface* o_ = (ErrnoErrorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	o_->SetErrorCode(errorCode);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ErrnoErrorInterface::COWReferenceFunctionsImpl<S>::SetErrorCode(Int errorCode) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION ErrnoErrorInterface::SetErrorCode on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); ErrnoErrorInterface* o_ = (ErrnoErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	o_->SetErrorCode(errorCode);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto ErrnoErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ErrnoErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_ErrnoErrorInterface(ErrnoErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif

struct UnregisteredDataTypeErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnregisteredDataTypeErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(UnregisteredDataTypeErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class UnregisteredDataTypeErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


auto UnregisteredDataTypeErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnregisteredDataTypeErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_UnregisteredDataTypeErrorInterface(UnregisteredDataTypeErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif

struct AggregatedErrorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddError);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetCount);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetError);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Bool (*_AggregatedErrorInterface_AddError) (maxon::GenericComponent* this_, const Error& error);
	maxon::Int _AggregatedErrorInterface_AddError_Offset;
	Bool (*_AggregatedErrorInterface_AddError_1) (maxon::GenericComponent* this_, Error&& error);
	maxon::Int _AggregatedErrorInterface_AddError_1_Offset;
	Int (*_AggregatedErrorInterface_GetCount) (const maxon::GenericComponent* this_);
	maxon::Int _AggregatedErrorInterface_GetCount_Offset;
	const Error& (*_AggregatedErrorInterface_GetError) (const maxon::GenericComponent* this_, Int index);
	maxon::Int _AggregatedErrorInterface_GetError_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, AggregatedErrorInterface, AddError))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, AggregatedErrorInterface, AddError), W, MTable>::type::_AggregatedErrorInterface_AddError;
			_AggregatedErrorInterface_AddError = reinterpret_cast<const decltype(_AggregatedErrorInterface_AddError)&>(ptr);
			_AggregatedErrorInterface_AddError_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, AggregatedErrorInterface, AddError))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, AggregatedErrorInterface, AddError), W, MTable>::type::_AggregatedErrorInterface_AddError_1;
			_AggregatedErrorInterface_AddError_1 = reinterpret_cast<const decltype(_AggregatedErrorInterface_AddError_1)&>(ptr);
			_AggregatedErrorInterface_AddError_1_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, AggregatedErrorInterface, GetCount))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, AggregatedErrorInterface, GetCount), W, MTable>::type::_AggregatedErrorInterface_GetCount;
			_AggregatedErrorInterface_GetCount = reinterpret_cast<const decltype(_AggregatedErrorInterface_GetCount)&>(ptr);
			_AggregatedErrorInterface_GetCount_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, AggregatedErrorInterface, GetError))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, AggregatedErrorInterface, GetError), W, MTable>::type::_AggregatedErrorInterface_GetError;
			_AggregatedErrorInterface_GetError = reinterpret_cast<const decltype(_AggregatedErrorInterface_GetError)&>(ptr);
			_AggregatedErrorInterface_GetError_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<AggregatedErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(AggregatedErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class AggregatedErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddError);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetCount);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetError);
	static Bool _AggregatedErrorInterface_AddError(maxon::GenericComponent* this_, const Error& error) { return ((typename S::Implementation*) this_)->AddError(error); }
	static Bool _AggregatedErrorInterface_AddError_1(maxon::GenericComponent* this_, Error&& error) { return ((typename S::Implementation*) this_)->AddError(std::forward<Error>(error)); }
	static Int _AggregatedErrorInterface_GetCount(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetCount(); }
	static const Error& _AggregatedErrorInterface_GetError(const maxon::GenericComponent* this_, Int index) { return ((const typename S::Implementation*) this_)->GetError(index); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::AddError(const Error& error) -> Bool
{
	const AggregatedErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, this); return mt_._AggregatedErrorInterface_AddError((maxon::GenericComponent*) this + mt_._AggregatedErrorInterface_AddError_Offset, error);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::AddError(Error&& error) -> Bool
{
	const AggregatedErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, this); return mt_._AggregatedErrorInterface_AddError_1((maxon::GenericComponent*) this + mt_._AggregatedErrorInterface_AddError_1_Offset, std::forward<Error>(error));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::GetCount() const -> Int
{
	const AggregatedErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, this); return mt_._AggregatedErrorInterface_GetCount((const maxon::GenericComponent*) this + mt_._AggregatedErrorInterface_GetCount_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::GetError(Int index) const -> const Error&
{
	const AggregatedErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, this); return mt_._AggregatedErrorInterface_GetError((const maxon::GenericComponent*) this + mt_._AggregatedErrorInterface_GetError_Offset, index);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::ReferenceFunctionsImpl<S>::AddError(const Error& error) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); AggregatedErrorInterface* o_ = (AggregatedErrorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(false); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AggregatedErrorInterface, o_, AggregatedErrorInterface_AddError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<AggregatedErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AggregatedErrorInterface>() : PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, o_); 
	return (mt_._AggregatedErrorInterface_AddError(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._AggregatedErrorInterface_AddError_Offset, error));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::COWReferenceFunctionsImpl<S>::AddError(const Error& error) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); AggregatedErrorInterface* o_ = (AggregatedErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AggregatedErrorInterface, o_, AggregatedErrorInterface_AddError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<AggregatedErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AggregatedErrorInterface>() : PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, o_); 
	return (mt_._AggregatedErrorInterface_AddError(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._AggregatedErrorInterface_AddError_Offset, error));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::ReferenceFunctionsImpl<S>::AddError(Error&& error) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); AggregatedErrorInterface* o_ = (AggregatedErrorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(false); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AggregatedErrorInterface, o_, AggregatedErrorInterface_AddError_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<AggregatedErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AggregatedErrorInterface>() : PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, o_); 
	return (mt_._AggregatedErrorInterface_AddError_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._AggregatedErrorInterface_AddError_1_Offset, std::forward<Error>(error)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::COWReferenceFunctionsImpl<S>::AddError(Error&& error) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); AggregatedErrorInterface* o_ = (AggregatedErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AggregatedErrorInterface, o_, AggregatedErrorInterface_AddError_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<AggregatedErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AggregatedErrorInterface>() : PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, o_); 
	return (mt_._AggregatedErrorInterface_AddError_1(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._AggregatedErrorInterface_AddError_1_Offset, std::forward<Error>(error)));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::ConstReferenceFunctionsImpl<S>::GetCount() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const AggregatedErrorInterface* o_ = (const AggregatedErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = AggregatedErrorInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AggregatedErrorInterface, o_, AggregatedErrorInterface_GetCount) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<AggregatedErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AggregatedErrorInterface>() : PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, o_); 
	return (mt_._AggregatedErrorInterface_GetCount(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._AggregatedErrorInterface_GetCount_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AggregatedErrorInterface::ConstReferenceFunctionsImpl<S>::GetError(Int index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Error&>, const Error&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Error&>, const Error&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const AggregatedErrorInterface* o_ = (const AggregatedErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = AggregatedErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Error&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AggregatedErrorInterface, o_, AggregatedErrorInterface_GetError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<AggregatedErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AggregatedErrorInterface>() : PRIVATE_MAXON_VTABLE(AggregatedErrorInterface, o_); 
	return (mt_._AggregatedErrorInterface_GetError(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._AggregatedErrorInterface_GetError_Offset, index));
}
auto AggregatedErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto AggregatedErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_AggregatedErrorInterface(AggregatedErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/errorbase.h", false);
#endif
#ifdef MAXON_COMPILER_MSVC
#else
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

