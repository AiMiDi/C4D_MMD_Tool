
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct AskPasswordInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AskPasswordFromUser);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<String> (*_AskPasswordInterface_AskPasswordFromUser) (const maxon::GenericComponent* this_, const String& text);
	maxon::Int _AskPasswordInterface_AskPasswordFromUser_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, AskPasswordInterface, AskPasswordFromUser))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, AskPasswordInterface, AskPasswordFromUser), W, MTable>::type::_AskPasswordInterface_AskPasswordFromUser;
			_AskPasswordInterface_AskPasswordFromUser = reinterpret_cast<const decltype(_AskPasswordInterface_AskPasswordFromUser)&>(ptr);
			_AskPasswordInterface_AskPasswordFromUser_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!Object::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<AskPasswordInterface, Object::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(AskPasswordInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class AskPasswordInterface::Wrapper : public Object::Wrapper<S>
{
public:
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AskPasswordFromUser);
	static Result<String> _AskPasswordInterface_AskPasswordFromUser(const maxon::GenericComponent* this_, const String& text) { return ((const typename S::Implementation*) this_)->AskPasswordFromUser(text); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto AskPasswordInterface::AskPasswordFromUser(const String& text) const -> Result<String>
{
	const AskPasswordInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(AskPasswordInterface, this); return mt_._AskPasswordInterface_AskPasswordFromUser((const maxon::GenericComponent*) this + mt_._AskPasswordInterface_AskPasswordFromUser_Offset, text);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto AskPasswordInterface::ConstReferenceFunctionsImpl<S>::AskPasswordFromUser(const String& text) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, false, Result<String>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const AskPasswordInterface* o_ = (const AskPasswordInterface*) this->GetPointer(); if (!(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS) && MAXON_UNLIKELY(!o_)) { o_ = AskPasswordInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(AskPasswordInterface, o_, AskPasswordInterface_AskPasswordFromUser) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<AskPasswordInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<AskPasswordInterface>() : PRIVATE_MAXON_VTABLE(AskPasswordInterface, o_); 
	return (mt_._AskPasswordInterface_AskPasswordFromUser(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._AskPasswordInterface_AskPasswordFromUser_Offset, text));
}
auto AskPasswordInterface::GetPtr() -> Ptr { return Ptr(this); }
auto AskPasswordInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_AskPasswordInterface(AskPasswordInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/ask_password.h", false);
#endif

struct AskPasswordMethod::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	void (*_AskPasswordMethod_Set) (const AskPasswordRef& method);
	const AskPasswordRef& (*_AskPasswordMethod_Get) ();
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_AskPasswordMethod_Set = &IMPL::_AskPasswordMethod_Set;
		tbl->_AskPasswordMethod_Get = &IMPL::_AskPasswordMethod_Get;
	}
};

class AskPasswordMethod::Null : public AskPasswordMethod
{
public:
	static const Null* Get(const AskPasswordMethod* o) { return (const Null*) o; }
	static Null* Get(AskPasswordMethod* o) { return (Null*) o; }
	static void Set(const AskPasswordRef& method) { return maxon::PrivateLogNullptrError(); }
	static const AskPasswordRef& Get() { return maxon::PrivateIncompleteNullReturnValue<const AskPasswordRef&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK); }
};

template <typename C> class AskPasswordMethod::Wrapper
{
public:
	static void _AskPasswordMethod_Set(const AskPasswordRef& method) { return C::Set(method); }
	static const AskPasswordRef& _AskPasswordMethod_Get() { return C::Get(); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto AskPasswordMethod::Set(const AskPasswordRef& method) -> void
{
	return MTable::_instance._AskPasswordMethod_Set(method);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto AskPasswordMethod::Get() -> const AskPasswordRef&
{
	return MTable::_instance._AskPasswordMethod_Get();
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_AskPasswordMethod(AskPasswordMethod::_interface.GetReference(), &maxon::g_translationUnit, "maxon/ask_password.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

