
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct NumberBaseInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GenericMul);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	NumberBaseRef<> (*_NumberBaseInterface_GenericMul) (const maxon::GenericComponent* this_, const NumberBaseRef<>& x);
	maxon::Int _NumberBaseInterface_GenericMul_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, NumberBaseInterface, GenericMul))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, NumberBaseInterface, GenericMul), W, MTable>::type::_NumberBaseInterface_GenericMul;
			_NumberBaseInterface_GenericMul = reinterpret_cast<const decltype(_NumberBaseInterface_GenericMul)&>(ptr);
			_NumberBaseInterface_GenericMul_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<NumberBaseInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(NumberBaseInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct NumberBaseInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GenericMul);
	static NumberBaseRef<> _NumberBaseInterface_GenericMul(const maxon::GenericComponent* this_, const NumberBaseRef<>& x) { return ((const typename S::Implementation*) this_)->GenericMul(x); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto NumberBaseInterface::GenericMul(const NumberBaseRef<>& x) const -> NumberBaseRef<>
{
	const NumberBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(NumberBaseInterface, this); return mt_._NumberBaseInterface_GenericMul((const maxon::GenericComponent*) this + mt_._NumberBaseInterface_GenericMul_Offset, x);
}

template <typename S, typename K_, Bool B_> MAXON_ATTRIBUTE_FORCE_INLINE auto NumberBaseInterface::Hxx1::ConstReferenceFunctionsImpl<S, K_, B_>::Mul(const K_& x) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<K_>, K_>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<K_>, K_>::type>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION NumberBaseInterface::Mul on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NumberBaseInterface* o_ = (const NumberBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NumberBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<K_>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->Mul<K_>(x));
}
template <typename S, typename K_, Bool B_> MAXON_ATTRIBUTE_FORCE_INLINE auto NumberBaseInterface::Hxx1::ConstReferenceFunctionsImpl<S, K_, B_>::GenericMul(const NumberBaseRef<>& x) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<NumberBaseRef<>>, NumberBaseRef<>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<NumberBaseRef<>>, NumberBaseRef<>>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Protected method NumberBaseInterface::GenericMul can only be invoked on self or super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NumberBaseInterface* o_ = (const NumberBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NumberBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<NumberBaseRef<>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(NumberBaseInterface, o_, NumberBaseInterface_GenericMul) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<NumberBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<NumberBaseInterface>() : PRIVATE_MAXON_VTABLE(NumberBaseInterface, o_); 
	return (mt_._NumberBaseInterface_GenericMul(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._NumberBaseInterface_GenericMul_Offset, x));
}
auto NumberBaseInterface::GetPtr() -> Ptr { return Ptr(this); }
auto NumberBaseInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_NumberBaseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_NumberBaseInterface() { new (s_ui_maxon_NumberBaseInterface) maxon::EntityUse(NumberBaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_NumberBaseInterface(NumberBaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

template <typename T, Int X> struct NumberInterface<T, X>::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Get1);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Set);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	T (*_NumberInterface_Get1) (const maxon::GenericComponent* this_);
	maxon::Int _NumberInterface_Get1_Offset;
	void (*_NumberInterface_Set) (maxon::GenericComponent* this_, typename IntType<X>::type number, const T& v);
	maxon::Int _NumberInterface_Set_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, NumberInterface, Get1))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, NumberInterface, Get1), W, MTable>::type::_NumberInterface_Get1;
			_NumberInterface_Get1 = reinterpret_cast<const decltype(_NumberInterface_Get1)&>(ptr);
			_NumberInterface_Get1_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, NumberInterface, Set))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, NumberInterface, Set), W, MTable>::type::_NumberInterface_Set;
			_NumberInterface_Set = reinterpret_cast<const decltype(_NumberInterface_Set)&>(ptr);
			_NumberInterface_Set_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!NumberBaseInterface::MTable::template InitWithBases<W>(info, offset) || !ErrorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<NumberInterface, typename ErrorInterface::MTable::template CombinedMTable<typename NumberBaseInterface::MTable::template CombinedMTable<S>>>;
	PRIVATE_MAXON_COMPBASE(NumberInterface);
	struct NVMTable;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::SFINAEHelper<NVMTable, I>::type::_instance.template GetMTable<I>(); }
};

template <typename T, Int X> struct NumberInterface<T, X>::MTable::NVMTable : public MTable::template CombinedMTable<maxon::CombinedMTableRoot> { static NVMTable _instance; };

template <typename T, Int X> struct NumberInterface<T, X>::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	Result<NumberRef<T, X>> (*_NumberInterface_Create) (T a, typename IntType<X>::type number);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->_NumberInterface_Create = &IMPL::_NumberInterface_Create;
		}
	};
	template <typename S> class Wrapper : public ErrorInterface::Hxx2::template Wrapper<typename NumberBaseInterface::Hxx2::template Wrapper<S>>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Get1);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Set);
	static T _NumberInterface_Get1(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->Get1(); }
	static Result<NumberRef<T, X>> _NumberInterface_Create(T a, typename IntType<X>::type number) { return S::Implementation::Create(a, std::forward<typename IntType<X>::type>(number)); }
	static void _NumberInterface_Set(maxon::GenericComponent* this_, typename IntType<X>::type number, const T& v) { return ((typename S::Implementation*) this_)->Set(std::forward<typename IntType<X>::type>(number), v); }
	};

};
template <typename T, Int X> MAXON_ATTRIBUTE_FORCE_INLINE auto NumberInterface<T, X>::Get1() const -> T
{
	const NumberInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_._NumberInterface_Get1((const maxon::GenericComponent*) this + mt_._NumberInterface_Get1_Offset);
}
template <typename T, Int X> MAXON_ATTRIBUTE_FORCE_INLINE auto NumberInterface<T, X>::Create(T a, typename IntType<X>::type number) -> Result<NumberRef<T, X>>
{
	return Hxx2::StaticMTable::_instance._NumberInterface_Create(a, std::forward<typename IntType<X>::type>(number));
}
template <typename T, Int X> MAXON_ATTRIBUTE_FORCE_INLINE auto NumberInterface<T, X>::Set(typename IntType<X>::type number, const T& v) -> void
{
	const NumberInterface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_._NumberInterface_Set((maxon::GenericComponent*) this + mt_._NumberInterface_Set_Offset, std::forward<typename IntType<X>::type>(number), v);
}

template <typename T, Int X> template <typename S, typename K_> MAXON_ATTRIBUTE_FORCE_INLINE auto NumberInterface<T, X>::Hxx1::ConstReferenceFunctionsImpl<S, K_>::Get1() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<T>, T>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<T>, T>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NumberInterface* o_ = (const NumberInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NumberInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<T>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(NumberInterface, o_, NumberInterface_Get1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<NumberInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<NumberInterface>() : PRIVATE_MAXON_VTABLE(NumberInterface, o_); 
	return (mt_._NumberInterface_Get1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._NumberInterface_Get1_Offset));
}
template <typename T, Int X> template <typename S, typename K_> MAXON_ATTRIBUTE_FORCE_INLINE auto NumberInterface<T, X>::Hxx1::ConstReferenceFunctionsImpl<S, K_>::Create(T a, typename IntType<X>::type number) -> Result<NumberRef<T, X>> { return (Hxx2::StaticMTable::_instance._NumberInterface_Create(a, std::forward<typename IntType<X>::type>(number))); }
template <typename T, Int X> template <typename S, typename K_> MAXON_ATTRIBUTE_FORCE_INLINE auto NumberInterface<T, X>::Hxx1::ReferenceFunctionsImpl<S, K_>::Set(typename IntType<X>::type number, const T& v) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NumberInterface* o_ = (NumberInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(NumberInterface, o_, NumberInterface_Set) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<NumberInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<NumberInterface>() : PRIVATE_MAXON_VTABLE(NumberInterface, o_); 
	mt_._NumberInterface_Set(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._NumberInterface_Set_Offset, std::forward<typename IntType<X>::type>(number), v);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename T, Int X> template <typename S, typename K_> MAXON_ATTRIBUTE_FORCE_INLINE auto NumberInterface<T, X>::Hxx1::COWReferenceFunctionsImpl<S, K_>::Set(typename IntType<X>::type number, const T& v) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NumberInterface* o_ = (NumberInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(NumberInterface, o_, NumberInterface_Set) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<NumberInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<NumberInterface>() : PRIVATE_MAXON_VTABLE(NumberInterface, o_); 
	mt_._NumberInterface_Set(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._NumberInterface_Set_Offset, std::forward<typename IntType<X>::type>(number), v);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename T, Int X> auto NumberInterface<T, X>::GetPtr() -> Ptr { return Ptr(this); }
template <typename T, Int X> auto NumberInterface<T, X>::GetPtr() const -> ConstPtr { return ConstPtr(this); }
MAXON_WARNING_PUSH
MAXON_WARNING_DISABLE_DEPRECATED
template <typename T, Int X> class NumberInterface<T, X>::Hxx2::Unresolved : public NumberInterface
{
public:
		static Result<NumberRef<T, X>> Create(T a, typename IntType<X>::type number) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return NumberInterface::Create(a, std::forward<typename IntType<X>::type>(number)); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
};
MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
template <typename T, Int X> const maxon::NULL_RETURN_TYPE NumberInterface<T, X>::Hxx2::StaticMTable::_returnTypes[] = 
{
		maxon::details::NullReturnType<Result<NumberRef<T, X>>>::value,
	maxon::NULL_RETURN_TYPE::OTHER
};
#endif
template <typename T, Int X> maxon::Bool NumberInterface<T, X>::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<NumberRef<T, X>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_NumberInterface_Create = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_NumberInterface_Create;
		#else
		tbl->_NumberInterface_Create = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_NumberInterface_Create;
		#endif
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
#else
	return true;
#endif
}
template <typename T, Int X> typename NumberInterface<T, X>::MTable::NVMTable NumberInterface<T, X>::MTable::NVMTable::_instance;
template <typename T, Int X> const maxon::Char* const NumberInterface<T, X>::MTable::_ids = 
		"Get1@13fcb\0" // T Get1() const
		"Set@0a96b5766da02bdc\0" // void Set(typename IntType<X>::type number, const T& v)
"";
PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_IMPL(NumberInterface<T MAXON_COMMA X>, NumberInterface, <T MAXON_COMMA X>, template <typename T MAXON_COMMA Int X> , PrivateGetInstantiationId((NumberInterface*) nullptr), PrivateGetInstantiationSourceName((NumberInterface*) nullptr), (&NumberBaseInterface::_interface), (&ErrorInterface::_interface), nullptr);
template <typename T, Int X> const maxon::Char* const NumberInterface<T, X>::Hxx2::StaticMTable::_ids = 
		"Create@706c56ca3646f06f\0" // Result<NumberRef<T, X>> Create(T a, typename IntType<X>::type number)
"";
PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(NumberInterface<T MAXON_COMMA X>, template <typename T MAXON_COMMA Int X> , PrivateGetInstantiationId((NumberInterface*) nullptr));
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
template <typename T, Int X> class NumberInterface<T, X>::ProxyComponent : public maxon::Component<ProxyComponent, NumberInterface>
{
	MAXON_COMPONENT();
public:
	using typename maxon::Component<ProxyComponent, NumberInterface>::_Wrapper;
	static const maxon::Bool PROXY = true;
	maxon::reflection::ProxyHandler _handler;
		T Get1() const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<NumberInterface>();
			T proxy_result = maxon::PrivateNullReturnValue<T>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._NumberInterface_Get1_Offset)};
			(*handler_)(_fn_NumberInterface_Get1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<T, const maxon::GenericComponent*>::Invoke, (const void*) mt_._NumberInterface_Get1));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_NumberInterface_Get1;
		void Set(typename IntType<X>::type number, const T& v) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<NumberInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._NumberInterface_Set_Offset), maxon::reflection::Argument::ByValue(number), maxon::reflection::Argument::ByReference(v)};
			(*handler_)(_fn_NumberInterface_Set, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, typename IntType<X>::type, const T&>::Invoke, (const void*) mt_._NumberInterface_Set));
		}
		static const maxon::reflection::Function* _fn_NumberInterface_Set;
};
	template <typename T, Int X> const maxon::reflection::Function* NumberInterface<T, X>::ProxyComponent::_fn_NumberInterface_Get1;
	template <typename T, Int X> const maxon::reflection::Function* NumberInterface<T, X>::ProxyComponent::_fn_NumberInterface_Set;
PRIVATE_MAXON_COMPONENT_REGISTER(NumberInterface<T MAXON_COMMA X>::ProxyComponent, template <typename T MAXON_COMMA Int X> , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
template <typename T, Int X> static maxon::Result<void> RegisterReflection_NumberInterface_Static(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
{
	maxon::reflection::FunctionInfo functions[] =
	{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NumberInterface<T, X>::Hxx2::StaticMTable::_instance._NumberInterface_Create)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0number\0", 0LL, nullptr),
	};
	return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&NumberInterface<T, X>::_staticInterface), maxon::ToBlock(functions));
}
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
template <typename T, Int X> static maxon::Result<void> RegisterReflection_NumberInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
{
	maxon::reflection::FunctionInfo functions[] =
	{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, NumberInterface<T MAXON_COMMA X>, _NumberInterface_Get1),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "number\0v\0", 0LL, NumberInterface<T MAXON_COMMA X>, _NumberInterface_Set),
	};
	return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&NumberInterface<T, X>::_interface), maxon::ToBlock(functions));
}
#endif

template <typename T> struct Number2Interface<T>::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Get2);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	T (*_Number2Interface_Get2) (const maxon::GenericComponent* this_);
	maxon::Int _Number2Interface_Get2_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, Number2Interface, Get2))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, Number2Interface, Get2), W, MTable>::type::_Number2Interface_Get2;
			_Number2Interface_Get2 = reinterpret_cast<const decltype(_Number2Interface_Get2)&>(ptr);
			_Number2Interface_Get2_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!NumberInterface<T, 4>::MTable::template InitWithBases<W>(info, offset) || !NumberBaseInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<Number2Interface, typename NumberBaseInterface::MTable::template CombinedMTable<typename NumberInterface<T, 4>::MTable::template CombinedMTable<S>>>;
	PRIVATE_MAXON_COMPBASE(Number2Interface);
	struct NVMTable;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::SFINAEHelper<NVMTable, I>::type::_instance.template GetMTable<I>(); }
};

template <typename T> struct Number2Interface<T>::MTable::NVMTable : public MTable::template CombinedMTable<maxon::CombinedMTableRoot> { static NVMTable _instance; };

template <typename T> struct Number2Interface<T>::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	Result<Int> (*_Number2Interface_Func) (T a);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->_Number2Interface_Func = &IMPL::_Number2Interface_Func;
		}
	};
	template <typename S> class Wrapper : public NumberBaseInterface::Hxx2::template Wrapper<typename NumberInterface<T, 4>::Hxx2::template Wrapper<S>>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Get2);
	static Result<Int> _Number2Interface_Func(T a) { return S::Implementation::Func(a); }
	static T _Number2Interface_Get2(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->Get2(); }
	};

};
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto Number2Interface<T>::Func(T a) -> Result<Int>
{
	return Hxx2::StaticMTable::_instance._Number2Interface_Func(a);
}
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE auto Number2Interface<T>::Get2() const -> T
{
	const Number2Interface::MTable& mt_ = MTable::NVMTable::_instance.mtable; return mt_._Number2Interface_Get2((const maxon::GenericComponent*) this + mt_._Number2Interface_Get2_Offset);
}

template <typename T> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Number2Interface<T>::Hxx1::ConstReferenceFunctionsImpl<S>::Func(T a) -> Result<Int> { return (Hxx2::StaticMTable::_instance._Number2Interface_Func(a)); }
template <typename T> template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto Number2Interface<T>::Hxx1::ConstReferenceFunctionsImpl<S>::Get2() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<T>, T>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<T>, T>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const Number2Interface* o_ = (const Number2Interface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = Number2Interface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<T>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(Number2Interface, o_, Number2Interface_Get2) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<Number2Interface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<Number2Interface>() : PRIVATE_MAXON_VTABLE(Number2Interface, o_); 
	return (mt_._Number2Interface_Get2(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._Number2Interface_Get2_Offset));
}
template <typename T> auto Number2Interface<T>::GetPtr() -> Ptr { return Ptr(this); }
template <typename T> auto Number2Interface<T>::GetPtr() const -> ConstPtr { return ConstPtr(this); }
MAXON_WARNING_PUSH
MAXON_WARNING_DISABLE_DEPRECATED
template <typename T> class Number2Interface<T>::Hxx2::Unresolved : public Number2Interface
{
public:
		static Result<Int> Func(T a) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return Number2Interface::Func(a); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
};
MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
template <typename T> const maxon::NULL_RETURN_TYPE Number2Interface<T>::Hxx2::StaticMTable::_returnTypes[] = 
{
		maxon::details::NullReturnType<Result<Int>>::value,
	maxon::NULL_RETURN_TYPE::OTHER
};
#endif
template <typename T> maxon::Bool Number2Interface<T>::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Number2Interface_Func = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_Number2Interface_Func;
		#else
		tbl->_Number2Interface_Func = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_Number2Interface_Func;
		#endif
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
#else
	return true;
#endif
}
template <typename T> typename Number2Interface<T>::MTable::NVMTable Number2Interface<T>::MTable::NVMTable::_instance;
template <typename T> const maxon::Char* const Number2Interface<T>::MTable::_ids = 
		"Get2@13fcb\0" // T Get2() const
"";
PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_IMPL(Number2Interface<T>, Number2Interface, <T>, template <typename T> , PrivateGetInstantiationId((Number2Interface*) nullptr), PrivateGetInstantiationSourceName((Number2Interface*) nullptr), (&NumberInterface<T, 4>::_interface), (&NumberBaseInterface::_interface), nullptr);
template <typename T> const maxon::Char* const Number2Interface<T>::Hxx2::StaticMTable::_ids = 
		"Func@0499ab9662af0884\0" // Result<Int> Func(T a)
"";
PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(Number2Interface<T>, template <typename T> , PrivateGetInstantiationId((Number2Interface*) nullptr));
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
template <typename T> class Number2Interface<T>::ProxyComponent : public maxon::Component<ProxyComponent, Number2Interface>
{
	MAXON_COMPONENT();
public:
	using typename maxon::Component<ProxyComponent, Number2Interface>::_Wrapper;
	static const maxon::Bool PROXY = true;
	maxon::reflection::ProxyHandler _handler;
		T Get2() const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<Number2Interface>();
			T proxy_result = maxon::PrivateNullReturnValue<T>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._Number2Interface_Get2_Offset)};
			(*handler_)(_fn_Number2Interface_Get2, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<T, const maxon::GenericComponent*>::Invoke, (const void*) mt_._Number2Interface_Get2));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_Number2Interface_Get2;
};
	template <typename T> const maxon::reflection::Function* Number2Interface<T>::ProxyComponent::_fn_Number2Interface_Get2;
PRIVATE_MAXON_COMPONENT_REGISTER(Number2Interface<T>::ProxyComponent, template <typename T> , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
template <typename T> static maxon::Result<void> RegisterReflection_Number2Interface_Static(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
{
	maxon::reflection::FunctionInfo functions[] =
	{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Number2Interface<T>::Hxx2::StaticMTable::_instance._Number2Interface_Func)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0", 0LL, nullptr),
	};
	return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Number2Interface<T>::_staticInterface), maxon::ToBlock(functions));
}
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
template <typename T> static maxon::Result<void> RegisterReflection_Number2Interface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
{
	maxon::reflection::FunctionInfo functions[] =
	{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, Number2Interface<T>, _Number2Interface_Get2),
	};
	return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Number2Interface<T>::_interface), maxon::ToBlock(functions));
}
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_NumberInterfaceNumberInterface_Int_4_); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_NumberInterfaceNumberInterface_Int_4_() { new (s_ui_maxon_NumberInterfaceNumberInterface_Int_4_) maxon::EntityUse(NumberInterface<Int,4>::_interface.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_NumberInterfaceNumberInterface_Int_4_(NumberInterface<Int,4>::_interface.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui1_maxon_NumberInterfaceNumberInterface_Int_4_); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui1_maxon_NumberInterfaceNumberInterface_Int_4_() { new (s_ui1_maxon_NumberInterfaceNumberInterface_Int_4_) maxon::EntityUse(NumberInterface<Int,4>::_nonvirtualMTable.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui1_maxon_NumberInterfaceNumberInterface_Int_4_(NumberInterface<Int,4>::_nonvirtualMTable.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_NumberInterfaceNumberInterface_Int_4_); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_NumberInterfaceNumberInterface_Int_4_() { new (s_usi_maxon_NumberInterfaceNumberInterface_Int_4_) maxon::EntityUse(NumberInterface<Int,4>::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_NumberInterfaceNumberInterface_Int_4_(NumberInterface<Int,4>::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
extern template NumberInterface<Int,4>::MTable::NVMTable NumberInterface<Int,4>::MTable::NVMTable::_instance;
extern template NumberInterface<Int,4>::Hxx2::StaticMTable NumberInterface<Int,4>::Hxx2::StaticMTable::_instance;
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_Number2InterfaceNumber2Interface_Int_); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_Number2InterfaceNumber2Interface_Int_() { new (s_ui_maxon_Number2InterfaceNumber2Interface_Int_) maxon::EntityUse(Number2Interface<Int>::_interface.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_Number2InterfaceNumber2Interface_Int_(Number2Interface<Int>::_interface.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui1_maxon_Number2InterfaceNumber2Interface_Int_); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui1_maxon_Number2InterfaceNumber2Interface_Int_() { new (s_ui1_maxon_Number2InterfaceNumber2Interface_Int_) maxon::EntityUse(Number2Interface<Int>::_nonvirtualMTable.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui1_maxon_Number2InterfaceNumber2Interface_Int_(Number2Interface<Int>::_nonvirtualMTable.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_Number2InterfaceNumber2Interface_Int_); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_Number2InterfaceNumber2Interface_Int_() { new (s_usi_maxon_Number2InterfaceNumber2Interface_Int_) maxon::EntityUse(Number2Interface<Int>::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_Number2InterfaceNumber2Interface_Int_(Number2Interface<Int>::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/interfacetemplate.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
extern template Number2Interface<Int>::MTable::NVMTable Number2Interface<Int>::MTable::NVMTable::_instance;
extern template Number2Interface<Int>::Hxx2::StaticMTable Number2Interface<Int>::Hxx2::StaticMTable::_instance;
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

