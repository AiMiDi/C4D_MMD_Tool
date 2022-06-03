
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
	Result<void> (*CodeExchangeInterface_Start) (maxon::GenericComponent* this_);
	maxon::Int CodeExchangeInterface_Start_Offset;
	Result<void> (*CodeExchangeInterface_Stop) (maxon::GenericComponent* this_);
	maxon::Int CodeExchangeInterface_Stop_Offset;
	Result<void> (*CodeExchangeInterface_SendScriptToIDE) (const maxon::GenericComponent* this_, const PythonElementScriptRef& script);
	maxon::Int CodeExchangeInterface_SendScriptToIDE_Offset;
	Result<void> (*CodeExchangeInterface_SendConsoleOutput) (const maxon::GenericComponent* this_, const String& content);
	maxon::Int CodeExchangeInterface_SendConsoleOutput_Offset;
	InternedId (*CodeExchangeInterface_GetLanguage) (const maxon::GenericComponent* this_);
	maxon::Int CodeExchangeInterface_GetLanguage_Offset;
	String (*CodeExchangeInterface_GetName) (const maxon::GenericComponent* this_);
	maxon::Int CodeExchangeInterface_GetName_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CodeExchangeInterface, Start))
	{
		CodeExchangeInterface_Start = &W::CodeExchangeInterface_Start;
		CodeExchangeInterface_Start_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CodeExchangeInterface, Stop))
	{
		CodeExchangeInterface_Stop = &W::CodeExchangeInterface_Stop;
		CodeExchangeInterface_Stop_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CodeExchangeInterface, SendScriptToIDE))
	{
		CodeExchangeInterface_SendScriptToIDE = &W::CodeExchangeInterface_SendScriptToIDE;
		CodeExchangeInterface_SendScriptToIDE_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CodeExchangeInterface, SendConsoleOutput))
	{
		CodeExchangeInterface_SendConsoleOutput = &W::CodeExchangeInterface_SendConsoleOutput;
		CodeExchangeInterface_SendConsoleOutput_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CodeExchangeInterface, GetLanguage))
	{
		CodeExchangeInterface_GetLanguage = &W::CodeExchangeInterface_GetLanguage;
		CodeExchangeInterface_GetLanguage_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CodeExchangeInterface, GetName))
	{
		CodeExchangeInterface_GetName = &W::CodeExchangeInterface_GetName;
		CodeExchangeInterface_GetName_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (CodeExchangeInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CodeExchangeInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> CodeExchangeInterface_Start(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Start(); }
		static Result<void> CodeExchangeInterface_Stop(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Stop(); }
		static Result<void> CodeExchangeInterface_SendScriptToIDE(const maxon::GenericComponent* this_, const PythonElementScriptRef& script) { return ((const typename S::Implementation*) this_)->SendScriptToIDE(script); }
		static Result<void> CodeExchangeInterface_SendConsoleOutput(const maxon::GenericComponent* this_, const String& content) { return ((const typename S::Implementation*) this_)->SendConsoleOutput(content); }
		static InternedId CodeExchangeInterface_GetLanguage(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetLanguage(); }
		static String CodeExchangeInterface_GetName(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetName(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Start() -> Result<void>
{
	const CodeExchangeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CodeExchangeInterface, this); return mt_.CodeExchangeInterface_Start((maxon::GenericComponent*) this + mt_.CodeExchangeInterface_Start_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Stop() -> Result<void>
{
	const CodeExchangeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CodeExchangeInterface, this); return mt_.CodeExchangeInterface_Stop((maxon::GenericComponent*) this + mt_.CodeExchangeInterface_Stop_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::SendScriptToIDE(const PythonElementScriptRef& script) const -> Result<void>
{
	const CodeExchangeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CodeExchangeInterface, this); return mt_.CodeExchangeInterface_SendScriptToIDE((const maxon::GenericComponent*) this + mt_.CodeExchangeInterface_SendScriptToIDE_Offset, script);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::SendConsoleOutput(const String& content) const -> Result<void>
{
	const CodeExchangeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CodeExchangeInterface, this); return mt_.CodeExchangeInterface_SendConsoleOutput((const maxon::GenericComponent*) this + mt_.CodeExchangeInterface_SendConsoleOutput_Offset, content);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::GetLanguage() const -> InternedId
{
	const CodeExchangeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CodeExchangeInterface, this); return mt_.CodeExchangeInterface_GetLanguage((const maxon::GenericComponent*) this + mt_.CodeExchangeInterface_GetLanguage_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::GetName() const -> String
{
	const CodeExchangeInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CodeExchangeInterface, this); return mt_.CodeExchangeInterface_GetName((const maxon::GenericComponent*) this + mt_.CodeExchangeInterface_GetName_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::Fn<S>::Start() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CodeExchangeInterface* o_ = (CodeExchangeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_Start) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (mt_.CodeExchangeInterface_Start(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_Start_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::COWFn<S>::Start() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CodeExchangeInterface* o_ = (CodeExchangeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_Start) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (mt_.CodeExchangeInterface_Start(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_Start_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::Fn<S>::Stop() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CodeExchangeInterface* o_ = (CodeExchangeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_Stop) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (mt_.CodeExchangeInterface_Stop(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_Stop_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::COWFn<S>::Stop() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); CodeExchangeInterface* o_ = (CodeExchangeInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_Stop) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (mt_.CodeExchangeInterface_Stop(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_Stop_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::ConstFn<S>::SendScriptToIDE(const PythonElementScriptRef& script) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CodeExchangeInterface* o_ = (const CodeExchangeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CodeExchangeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_SendScriptToIDE) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (mt_.CodeExchangeInterface_SendScriptToIDE(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_SendScriptToIDE_Offset, script));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::ConstFn<S>::SendConsoleOutput(const String& content) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CodeExchangeInterface* o_ = (const CodeExchangeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CodeExchangeInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_SendConsoleOutput) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (mt_.CodeExchangeInterface_SendConsoleOutput(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_SendConsoleOutput_Offset, content));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::ConstFn<S>::GetLanguage() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<InternedId>, InternedId>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<InternedId>, InternedId>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CodeExchangeInterface* o_ = (const CodeExchangeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CodeExchangeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<InternedId>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_GetLanguage) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (mt_.CodeExchangeInterface_GetLanguage(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_GetLanguage_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CodeExchangeInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CodeExchangeInterface* o_ = (const CodeExchangeInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CodeExchangeInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CodeExchangeInterface, o_, CodeExchangeInterface_GetName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CodeExchangeInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CodeExchangeInterface>() : PRIVATE_MAXON_VTABLE(CodeExchangeInterface, o_); 
	return (mt_.CodeExchangeInterface_GetName(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CodeExchangeInterface_GetName_Offset));
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

