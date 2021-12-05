
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
struct FactoryInterface::Parameters_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x1fbe4ec2aef56cd4LL), maxon::UInt(23))> { };

struct FactoryInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateGetDelegate);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	const DelegateBase* (*_FactoryInterface_PrivateGetDelegate) (const maxon::GenericComponent* this_);
	maxon::Int _FactoryInterface_PrivateGetDelegate_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FactoryInterface, PrivateGetDelegate))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FactoryInterface, PrivateGetDelegate), W, MTable>::type::_FactoryInterface_PrivateGetDelegate;
			_FactoryInterface_PrivateGetDelegate = reinterpret_cast<const decltype(_FactoryInterface_PrivateGetDelegate)&>(ptr);
			_FactoryInterface_PrivateGetDelegate_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FactoryInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(FactoryInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct FactoryInterface::Hxx2
{
	template <typename S> class Wrapper : public DataDictionaryObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateGetDelegate);
	static const DelegateBase* _FactoryInterface_PrivateGetDelegate(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->PrivateGetDelegate(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FactoryInterface::PrivateGetDelegate() const -> const DelegateBase*
{
	const FactoryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FactoryInterface, this); return mt_._FactoryInterface_PrivateGetDelegate((const maxon::GenericComponent*) this + mt_._FactoryInterface_PrivateGetDelegate_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FactoryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::PrivateGetDelegate() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const DelegateBase*>, const DelegateBase*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const DelegateBase*>, const DelegateBase*>::type>; static_assert(std::is_base_of<maxon::SelfPointerHandler, typename S::Handler>::value, "Method FactoryInterface::PrivateGetDelegate with refclass=false can only be invoked on self or super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const FactoryInterface* o_ = (const FactoryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = FactoryInterface::NullValuePtr(); if (!o_) return nullptr; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(FactoryInterface, o_, FactoryInterface_PrivateGetDelegate) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<FactoryInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<FactoryInterface>() : PRIVATE_MAXON_VTABLE(FactoryInterface, o_); 
	return (mt_._FactoryInterface_PrivateGetDelegate(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._FactoryInterface_PrivateGetDelegate_Offset));
}
auto FactoryInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FactoryInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FactoryInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FactoryInterface() { new (s_ui_maxon_FactoryInterface) maxon::EntityUse(FactoryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/factory.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FactoryInterface(FactoryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/factory.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct FactoryFactory::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<GenericFactory::NonConst> (*_FactoryFactory_PrivateCreate) (DelegateBase&& func, const DataDictionary& params);
	Result<GenericFactory::NonConst> (*_FactoryFactory_PrivateCreateCached) (DelegateBase&& func, DelegateBase&& creator, Int size, const DataDictionary& params);
	Result<const Data&> (*_FactoryFactory_CreateDataCached) (const FactoryInterface* factory, const DataDictionary& params, DataCreator* dc);
	template <typename IMPL> void Init()
	{
		_FactoryFactory_PrivateCreate = &IMPL::_FactoryFactory_PrivateCreate;
		_FactoryFactory_PrivateCreateCached = &IMPL::_FactoryFactory_PrivateCreateCached;
		_FactoryFactory_CreateDataCached = &IMPL::_FactoryFactory_CreateDataCached;
	}
};

struct FactoryFactory::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static Result<GenericFactory::NonConst> _FactoryFactory_PrivateCreate(DelegateBase&& func, const DataDictionary& params) { return C::PrivateCreate(std::forward<DelegateBase>(func), params); }
	static Result<GenericFactory::NonConst> _FactoryFactory_PrivateCreateCached(DelegateBase&& func, DelegateBase&& creator, Int size, const DataDictionary& params) { return C::PrivateCreateCached(std::forward<DelegateBase>(func), std::forward<DelegateBase>(creator), size, params); }
	static Result<const Data&> _FactoryFactory_CreateDataCached(const FactoryInterface* factory, const DataDictionary& params, DataCreator* dc) { return C::CreateDataCached(factory, params, dc); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FactoryFactory::PrivateCreate(DelegateBase&& func, const DataDictionary& params) -> Result<GenericFactory::NonConst>
{
	return MTable::_instance._FactoryFactory_PrivateCreate(std::forward<DelegateBase>(func), params);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FactoryFactory::PrivateCreateCached(DelegateBase&& func, DelegateBase&& creator, Int size, const DataDictionary& params) -> Result<GenericFactory::NonConst>
{
	return MTable::_instance._FactoryFactory_PrivateCreateCached(std::forward<DelegateBase>(func), std::forward<DelegateBase>(creator), size, params);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FactoryFactory::CreateDataCached(const FactoryInterface* factory, const DataDictionary& params, DataCreator* dc) -> Result<const Data&>
{
	return MTable::_instance._FactoryFactory_CreateDataCached(factory, params, dc);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FactoryFactory); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FactoryFactory() { new (s_ui_maxon_FactoryFactory) maxon::EntityUse(FactoryFactory::_interface.GetReference(), &maxon::g_translationUnit, "maxon/factory.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FactoryFactory(FactoryFactory::_interface.GetReference(), &maxon::g_translationUnit, "maxon/factory.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

