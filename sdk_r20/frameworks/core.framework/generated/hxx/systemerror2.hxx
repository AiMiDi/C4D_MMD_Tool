
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1
#if defined(MAXON_TARGET_MACOS) || defined(MAXON_TARGET_IOS)
#ifdef __OBJC__
#else
#endif
#else
#endif

struct SystemErrorInterface::MTable
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
	template <typename S> using CombinedMTable = maxon::CombinedMTable<SystemErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(SystemErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class SystemErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
};


template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemErrorInterface::ConstReferenceFunctionsImpl<S>::GetErrorCode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION SystemErrorInterface::GetErrorCode on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SystemErrorInterface* o_ = (const SystemErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = SystemErrorInterface::NullValuePtr(); if (!o_) return 0; } 
	return (o_->GetErrorCode());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemErrorInterface::ReferenceFunctionsImpl<S>::SetErrorCode(Int errorCode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SystemErrorInterface* o_ = (SystemErrorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	o_->SetErrorCode(errorCode);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemErrorInterface::COWReferenceFunctionsImpl<S>::SetErrorCode(Int errorCode) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION SystemErrorInterface::SetErrorCode on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SystemErrorInterface* o_ = (SystemErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	o_->SetErrorCode(errorCode);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto SystemErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto SystemErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_SystemErrorInterface(SystemErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/systemerror.h", false);
#endif

struct NSSystemErrorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetNSError);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetNSError);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	void (*_NSSystemErrorInterface_SetNSError) (maxon::GenericComponent* this_, NSError* osError);
	maxon::Int _NSSystemErrorInterface_SetNSError_Offset;
	NSError* (*_NSSystemErrorInterface_GetNSError) (const maxon::GenericComponent* this_);
	maxon::Int _NSSystemErrorInterface_GetNSError_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, NSSystemErrorInterface, SetNSError))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, NSSystemErrorInterface, SetNSError), W, MTable>::type::_NSSystemErrorInterface_SetNSError;
			_NSSystemErrorInterface_SetNSError = reinterpret_cast<const decltype(_NSSystemErrorInterface_SetNSError)&>(ptr);
			_NSSystemErrorInterface_SetNSError_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, NSSystemErrorInterface, GetNSError))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, NSSystemErrorInterface, GetNSError), W, MTable>::type::_NSSystemErrorInterface_GetNSError;
			_NSSystemErrorInterface_GetNSError = reinterpret_cast<const decltype(_NSSystemErrorInterface_GetNSError)&>(ptr);
			_NSSystemErrorInterface_GetNSError_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<NSSystemErrorInterface, ErrorInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(NSSystemErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class NSSystemErrorInterface::Wrapper : public ErrorInterface::Wrapper<S>
{
public:
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetNSError);
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetNSError);
	static void _NSSystemErrorInterface_SetNSError(maxon::GenericComponent* this_, NSError* osError) { return ((typename S::Implementation*) this_)->SetNSError(osError); }
	static NSError* _NSSystemErrorInterface_GetNSError(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetNSError(); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto NSSystemErrorInterface::SetNSError(NSError* osError) -> void
{
	const NSSystemErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(NSSystemErrorInterface, this); return mt_._NSSystemErrorInterface_SetNSError((maxon::GenericComponent*) this + mt_._NSSystemErrorInterface_SetNSError_Offset, osError);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NSSystemErrorInterface::GetNSError() const -> NSError*
{
	const NSSystemErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(NSSystemErrorInterface, this); return mt_._NSSystemErrorInterface_GetNSError((const maxon::GenericComponent*) this + mt_._NSSystemErrorInterface_GetNSError_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NSSystemErrorInterface::ReferenceFunctionsImpl<S>::SetNSError(NSError* osError) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NSSystemErrorInterface* o_ = (NSSystemErrorInterface*) this->GetPointer(); if (MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(NSSystemErrorInterface, o_, NSSystemErrorInterface_SetNSError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<NSSystemErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<NSSystemErrorInterface>() : PRIVATE_MAXON_VTABLE(NSSystemErrorInterface, o_); 
	mt_._NSSystemErrorInterface_SetNSError(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._NSSystemErrorInterface_SetNSError_Offset, osError);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NSSystemErrorInterface::COWReferenceFunctionsImpl<S>::SetNSError(NSError* osError) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NSSystemErrorInterface* o_ = (NSSystemErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(NSSystemErrorInterface, o_, NSSystemErrorInterface_SetNSError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<NSSystemErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<NSSystemErrorInterface>() : PRIVATE_MAXON_VTABLE(NSSystemErrorInterface, o_); 
	mt_._NSSystemErrorInterface_SetNSError(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._NSSystemErrorInterface_SetNSError_Offset, osError);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NSSystemErrorInterface::ConstReferenceFunctionsImpl<S>::GetNSError() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<NSError*>, NSError*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, typename std::conditional<S::HAS_ERROR, maxon::Result<NSError*>, NSError*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NSSystemErrorInterface* o_ = (const NSSystemErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = NSSystemErrorInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(NSSystemErrorInterface, o_, NSSystemErrorInterface_GetNSError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<NSSystemErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<NSSystemErrorInterface>() : PRIVATE_MAXON_VTABLE(NSSystemErrorInterface, o_); 
	return (mt_._NSSystemErrorInterface_GetNSError(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._NSSystemErrorInterface_GetNSError_Offset));
}
auto NSSystemErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto NSSystemErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_NSSystemErrorInterface(NSSystemErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/systemerror.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

