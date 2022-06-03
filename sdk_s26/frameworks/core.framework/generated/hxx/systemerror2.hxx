
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<SystemErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<SystemErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct SystemErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (SystemErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, SystemErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemErrorInterface::Hxx1::ConstFn<S>::GetErrorCode() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION SystemErrorInterface::GetErrorCode on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const SystemErrorInterface* o_ = (const SystemErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = SystemErrorInterface::NullValuePtr(); if (!o_) return 0; } 
	return (o_->GetErrorCode());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemErrorInterface::Hxx1::Fn<S>::SetErrorCode(Int errorCode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SystemErrorInterface* o_ = (SystemErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	o_->SetErrorCode(errorCode);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto SystemErrorInterface::Hxx1::COWFn<S>::SetErrorCode(Int errorCode) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION SystemErrorInterface::SetErrorCode on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); SystemErrorInterface* o_ = (SystemErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	o_->SetErrorCode(errorCode);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto SystemErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto SystemErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_systemerror)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_SystemErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_SystemErrorInterface() { new (s_ui_maxon_SystemErrorInterface) maxon::EntityUse(SystemErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/systemerror.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_SystemErrorInterface(SystemErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/systemerror.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct NSSystemErrorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetNSError);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetCFError);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetNSError);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	void (*NSSystemErrorInterface_SetNSError) (maxon::GenericComponent* this_, NSError* osError);
	maxon::Int NSSystemErrorInterface_SetNSError_Offset;
	void (*NSSystemErrorInterface_SetCFError) (maxon::GenericComponent* this_, CFErrorRef osError);
	maxon::Int NSSystemErrorInterface_SetCFError_Offset;
	NSError* (*NSSystemErrorInterface_GetNSError) (const maxon::GenericComponent* this_);
	maxon::Int NSSystemErrorInterface_GetNSError_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, NSSystemErrorInterface, SetNSError))
	{
		NSSystemErrorInterface_SetNSError = &W::NSSystemErrorInterface_SetNSError;
		NSSystemErrorInterface_SetNSError_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, NSSystemErrorInterface, SetCFError))
	{
		NSSystemErrorInterface_SetCFError = &W::NSSystemErrorInterface_SetCFError;
		NSSystemErrorInterface_SetCFError_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, NSSystemErrorInterface, GetNSError))
	{
		NSSystemErrorInterface_GetNSError = &W::NSSystemErrorInterface_GetNSError;
		NSSystemErrorInterface_GetNSError_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<NSSystemErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<NSSystemErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct NSSystemErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetNSError);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetCFError);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetNSError);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (NSSystemErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, NSSystemErrorInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static void NSSystemErrorInterface_SetNSError(maxon::GenericComponent* this_, NSError* osError) { return ((typename S::Implementation*) this_)->SetNSError(osError); }
		static void NSSystemErrorInterface_SetCFError(maxon::GenericComponent* this_, CFErrorRef osError) { return ((typename S::Implementation*) this_)->SetCFError(std::forward<CFErrorRef>(osError)); }
		static NSError* NSSystemErrorInterface_GetNSError(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetNSError(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto NSSystemErrorInterface::SetNSError(NSError* osError) -> void
{
	const NSSystemErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(NSSystemErrorInterface, this); return mt_.NSSystemErrorInterface_SetNSError((maxon::GenericComponent*) this + mt_.NSSystemErrorInterface_SetNSError_Offset, osError);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NSSystemErrorInterface::SetCFError(CFErrorRef osError) -> void
{
	const NSSystemErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(NSSystemErrorInterface, this); return mt_.NSSystemErrorInterface_SetCFError((maxon::GenericComponent*) this + mt_.NSSystemErrorInterface_SetCFError_Offset, std::forward<CFErrorRef>(osError));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NSSystemErrorInterface::GetNSError() const -> NSError*
{
	const NSSystemErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(NSSystemErrorInterface, this); return mt_.NSSystemErrorInterface_GetNSError((const maxon::GenericComponent*) this + mt_.NSSystemErrorInterface_GetNSError_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NSSystemErrorInterface::Hxx1::Fn<S>::SetNSError(NSError* osError) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NSSystemErrorInterface* o_ = (NSSystemErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(NSSystemErrorInterface, o_, NSSystemErrorInterface_SetNSError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<NSSystemErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<NSSystemErrorInterface>() : PRIVATE_MAXON_VTABLE(NSSystemErrorInterface, o_); 
	mt_.NSSystemErrorInterface_SetNSError(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.NSSystemErrorInterface_SetNSError_Offset, osError);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NSSystemErrorInterface::Hxx1::COWFn<S>::SetNSError(NSError* osError) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NSSystemErrorInterface* o_ = (NSSystemErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(NSSystemErrorInterface, o_, NSSystemErrorInterface_SetNSError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<NSSystemErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<NSSystemErrorInterface>() : PRIVATE_MAXON_VTABLE(NSSystemErrorInterface, o_); 
	mt_.NSSystemErrorInterface_SetNSError(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.NSSystemErrorInterface_SetNSError_Offset, osError);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NSSystemErrorInterface::Hxx1::Fn<S>::SetCFError(CFErrorRef osError) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NSSystemErrorInterface* o_ = (NSSystemErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(NSSystemErrorInterface, o_, NSSystemErrorInterface_SetCFError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<NSSystemErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<NSSystemErrorInterface>() : PRIVATE_MAXON_VTABLE(NSSystemErrorInterface, o_); 
	mt_.NSSystemErrorInterface_SetCFError(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.NSSystemErrorInterface_SetCFError_Offset, std::forward<CFErrorRef>(osError));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NSSystemErrorInterface::Hxx1::COWFn<S>::SetCFError(CFErrorRef osError) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NSSystemErrorInterface* o_ = (NSSystemErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(NSSystemErrorInterface, o_, NSSystemErrorInterface_SetCFError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<NSSystemErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<NSSystemErrorInterface>() : PRIVATE_MAXON_VTABLE(NSSystemErrorInterface, o_); 
	mt_.NSSystemErrorInterface_SetCFError(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.NSSystemErrorInterface_SetCFError_Offset, std::forward<CFErrorRef>(osError));
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NSSystemErrorInterface::Hxx1::ConstFn<S>::GetNSError() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<NSError*>, NSError*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<NSError*>, NSError*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NSSystemErrorInterface* o_ = (const NSSystemErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NSSystemErrorInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(NSSystemErrorInterface, o_, NSSystemErrorInterface_GetNSError) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<NSSystemErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<NSSystemErrorInterface>() : PRIVATE_MAXON_VTABLE(NSSystemErrorInterface, o_); 
	return (mt_.NSSystemErrorInterface_GetNSError(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.NSSystemErrorInterface_GetNSError_Offset));
}
auto NSSystemErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto NSSystemErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_systemerror)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_NSSystemErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_NSSystemErrorInterface() { new (s_ui_maxon_NSSystemErrorInterface) maxon::EntityUse(NSSystemErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/systemerror.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_NSSystemErrorInterface(NSSystemErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/systemerror.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

