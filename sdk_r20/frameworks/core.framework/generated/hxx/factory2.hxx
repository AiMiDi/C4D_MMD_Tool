
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
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
		if (PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FactoryInterface, PrivateGetDelegate))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(W::Implementation, FactoryInterface, PrivateGetDelegate), W, MTable>::type::_FactoryInterface_PrivateGetDelegate;
			_FactoryInterface_PrivateGetDelegate = reinterpret_cast<const decltype(_FactoryInterface_PrivateGetDelegate)&>(ptr);
			_FactoryInterface_PrivateGetDelegate_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FactoryInterface, DataDictionaryObjectInterface::MTable::CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(FactoryInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class FactoryInterface::Wrapper : public DataDictionaryObjectInterface::Wrapper<S>
{
public:
	PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateGetDelegate);
	static const DelegateBase* _FactoryInterface_PrivateGetDelegate(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->PrivateGetDelegate(); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto FactoryInterface::PrivateGetDelegate() const -> const DelegateBase*
{
	const FactoryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FactoryInterface, this); return mt_._FactoryInterface_PrivateGetDelegate((const maxon::GenericComponent*) this + mt_._FactoryInterface_PrivateGetDelegate_Offset);
}

auto FactoryInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FactoryInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_FactoryInterface(FactoryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/factory.h", false);
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
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_FactoryFactory_PrivateCreate = &IMPL::_FactoryFactory_PrivateCreate;
		tbl->_FactoryFactory_PrivateCreateCached = &IMPL::_FactoryFactory_PrivateCreateCached;
		tbl->_FactoryFactory_CreateDataCached = &IMPL::_FactoryFactory_CreateDataCached;
	}
};

template <typename C> class FactoryFactory::Wrapper
{
public:
	static Result<GenericFactory::NonConst> _FactoryFactory_PrivateCreate(DelegateBase&& func, const DataDictionary& params) { return C::PrivateCreate(std::forward<DelegateBase>(func), params); }
	static Result<GenericFactory::NonConst> _FactoryFactory_PrivateCreateCached(DelegateBase&& func, DelegateBase&& creator, Int size, const DataDictionary& params) { return C::PrivateCreateCached(std::forward<DelegateBase>(func), std::forward<DelegateBase>(creator), size, params); }
	static Result<const Data&> _FactoryFactory_CreateDataCached(const FactoryInterface* factory, const DataDictionary& params, DataCreator* dc) { return C::CreateDataCached(factory, params, dc); }
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
static maxon::EntityUse s_ui_maxon_FactoryFactory(FactoryFactory::_interface.GetReference(), &maxon::g_translationUnit, "maxon/factory.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

