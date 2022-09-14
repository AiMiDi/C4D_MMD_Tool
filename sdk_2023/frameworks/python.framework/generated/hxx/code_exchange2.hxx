
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct CodeExchangeInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLanguage);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetName);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SendConsoleOutput);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SendScriptToIDE);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Start);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Stop);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(CodeExchangeInterface_Start, Start, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int CodeExchangeInterface_Start_Offset;
	PRIVATE_MAXON_MF_POINTER(CodeExchangeInterface_Stop, Stop, true, maxon::GenericComponent,, (Result<void>));
	maxon::Int CodeExchangeInterface_Stop_Offset;
	PRIVATE_MAXON_MF_POINTER(CodeExchangeInterface_SendScriptToIDE, SendScriptToIDE, true, maxon::GenericComponent,, (Result<void>), const PythonElementScriptRef& script);
	maxon::Int CodeExchangeInterface_SendScriptToIDE_Offset;
	PRIVATE_MAXON_MF_POINTER(CodeExchangeInterface_SendConsoleOutput, SendConsoleOutput, true, maxon::GenericComponent,, (Result<void>), const String& content);
	maxon::Int CodeExchangeInterface_SendConsoleOutput_Offset;
	PRIVATE_MAXON_MF_POINTER(CodeExchangeInterface_GetLanguage, GetLanguage, true, maxon::GenericComponent, const, (InternedId));
	maxon::Int CodeExchangeInterface_GetLanguage_Offset;
	PRIVATE_MAXON_MF_POINTER(CodeExchangeInterface_GetName, GetName, true, maxon::GenericComponent, const, (String));
	maxon::Int CodeExchangeInterface_GetName_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CodeExchangeInterface, Start))
	{
		maxon::Tie(CodeExchangeInterface_Start, CodeExchangeInterface_Start_Offset) = CodeExchangeInterface_Start_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CodeExchangeInterface, Stop))
	{
		maxon::Tie(CodeExchangeInterface_Stop, CodeExchangeInterface_Stop_Offset) = CodeExchangeInterface_Stop_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CodeExchangeInterface, SendScriptToIDE))
	{
		maxon::Tie(CodeExchangeInterface_SendScriptToIDE, CodeExchangeInterface_SendScriptToIDE_Offset) = CodeExchangeInterface_SendScriptToIDE_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CodeExchangeInterface, SendConsoleOutput))
	{
		maxon::Tie(CodeExchangeInterface_SendConsoleOutput, CodeExchangeInterface_SendConsoleOutput_Offset) = CodeExchangeInterface_SendConsoleOutput_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CodeExchangeInterface, GetLanguage))
	{
		maxon::Tie(CodeExchangeInterface_GetLanguage, CodeExchangeInterface_GetLanguage_Offset) = CodeExchangeInterface_GetLanguage_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CodeExchangeInterface, GetName))
	{
		maxon::Tie(CodeExchangeInterface_GetName, CodeExchangeInterface_GetName_Offset) = CodeExchangeInterface_GetName_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CodeExchangeInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CodeExchangeInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CodeExchangeInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLanguage);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetName);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SendConsoleOutput);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SendScriptToIDE);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Start);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Stop);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CodeExchangeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CodeExchangeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(CodeExchangeInterface_Start, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Start(); }
		PRIVATE_MAXON_MF_WRAPPER(CodeExchangeInterface_Stop, maxon::GenericComponent,, (Result<void>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Stop(); }
		PRIVATE_MAXON_MF_WRAPPER(CodeExchangeInterface_SendScriptToIDE, maxon::GenericComponent,, (Result<void>), const PythonElementScriptRef& script) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SendScriptToIDE(script); }
		PRIVATE_MAXON_MF_WRAPPER(CodeExchangeInterface_SendConsoleOutput, maxon::GenericComponent,, (Result<void>), const String& content) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SendConsoleOutput(content); }
		PRIVATE_MAXON_MF_WRAPPER(CodeExchangeInterface_GetLanguage, maxon::GenericComponent, const, (InternedId)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetLanguage(); }
		PRIVATE_MAXON_MF_WRAPPER(CodeExchangeInterface_GetName, maxon::GenericComponent, const, (String)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetName(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Start() -> Result<void>
{
	const CodeExchangeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CodeExchangeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CodeExchangeInterface_Start_Offset), mt_.CodeExchangeInterface_Start);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Stop() -> Result<void>
{
	const CodeExchangeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CodeExchangeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CodeExchangeInterface_Stop_Offset), mt_.CodeExchangeInterface_Stop);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::SendScriptToIDE(const PythonElementScriptRef& script) -> Result<void>
{
	const CodeExchangeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CodeExchangeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CodeExchangeInterface_SendScriptToIDE_Offset), mt_.CodeExchangeInterface_SendScriptToIDE, script);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::SendConsoleOutput(const String& content) -> Result<void>
{
	const CodeExchangeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CodeExchangeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.CodeExchangeInterface_SendConsoleOutput_Offset), mt_.CodeExchangeInterface_SendConsoleOutput, content);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::GetLanguage() const -> InternedId
{
	const CodeExchangeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CodeExchangeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CodeExchangeInterface_GetLanguage_Offset), mt_.CodeExchangeInterface_GetLanguage);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::GetName() const -> String
{
	const CodeExchangeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CodeExchangeInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CodeExchangeInterface_GetName_Offset), mt_.CodeExchangeInterface_GetName);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::Fn<S>::Start() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CodeExchangeInterface* o_ = (CodeExchangeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_Start) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_Start_Offset), mt_.CodeExchangeInterface_Start));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::COWFn<S>::Start() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CodeExchangeInterface* o_ = (CodeExchangeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_Start) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_Start_Offset), mt_.CodeExchangeInterface_Start));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::Fn<S>::Stop() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CodeExchangeInterface* o_ = (CodeExchangeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_Stop) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_Stop_Offset), mt_.CodeExchangeInterface_Stop));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::COWFn<S>::Stop() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CodeExchangeInterface* o_ = (CodeExchangeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_Stop) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_Stop_Offset), mt_.CodeExchangeInterface_Stop));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::Fn<S>::SendScriptToIDE(const PythonElementScriptRef& script) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CodeExchangeInterface* o_ = (CodeExchangeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_SendScriptToIDE) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_SendScriptToIDE_Offset), mt_.CodeExchangeInterface_SendScriptToIDE, script));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::COWFn<S>::SendScriptToIDE(const PythonElementScriptRef& script) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CodeExchangeInterface* o_ = (CodeExchangeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_SendScriptToIDE) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_SendScriptToIDE_Offset), mt_.CodeExchangeInterface_SendScriptToIDE, script));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::Fn<S>::SendConsoleOutput(const String& content) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CodeExchangeInterface* o_ = (CodeExchangeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_SendConsoleOutput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_SendConsoleOutput_Offset), mt_.CodeExchangeInterface_SendConsoleOutput, content));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::COWFn<S>::SendConsoleOutput(const String& content) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); CodeExchangeInterface* o_ = (CodeExchangeInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_SendConsoleOutput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_SendConsoleOutput_Offset), mt_.CodeExchangeInterface_SendConsoleOutput, content));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::ConstFn<S>::GetLanguage() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<InternedId>, InternedId>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<InternedId>, InternedId>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CodeExchangeInterface* o_ = (const CodeExchangeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CodeExchangeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<InternedId>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_GetLanguage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_GetLanguage_Offset), mt_.CodeExchangeInterface_GetLanguage));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CodeExchangeInterface* o_ = (const CodeExchangeInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CodeExchangeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_GetName_Offset), mt_.CodeExchangeInterface_GetName));
}
auto CodeExchangeInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CodeExchangeInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_code_exchange)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CodeExchangeInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CodeExchangeInterface() { new (s_ui_maxon_CodeExchangeInterface) maxon::EntityUse(CodeExchangeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/code_exchange.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CodeExchangeInterface(CodeExchangeInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/code_exchange.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

