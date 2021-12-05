#if 1
namespace maxon
{
	FactoryInterface::Parameters_PrivateAttribute FactoryInterface::Parameters;
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FactoryInterface, "net.maxon.interface.factory", "maxon.FactoryInterface", , &DataDictionaryObjectInterface::_interface);
	const maxon::Char* const FactoryInterface::MTable::_ids = 
		"PrivateGetDelegate@06662c384f80cd8e\0" // PrivateGetDelegate() const
	"";
	template <typename DUMMY> maxon::Int FactoryInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
	const maxon::Char* const FactoryFactory::MTable::_ids = 
		"PrivateCreate@08519ee73dd39143\0" // PrivateCreate(DelegateBase&& func, const DataDictionary& params)
		"PrivateCreateCached@34e751babf175464\0" // PrivateCreateCached(DelegateBase&& func, DelegateBase&& creator, Int size, const DataDictionary& params)
		"CreateDataCached@7332637d4b2d9ec5\0" // CreateDataCached(const FactoryInterface* factory, const DataDictionary& params, DataCreator* dc)
	"";
	class FactoryFactory::Unresolved : public FactoryFactory
	{
	public:
		static const Unresolved* Get(const FactoryFactory* o) { return (const Unresolved*) o; }
		static Unresolved* Get(FactoryFactory* o) { return (Unresolved*) o; }
		static Result<GenericFactory::NonConst> PrivateCreate(DelegateBase&& func, const DataDictionary& params) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FactoryFactory::PrivateCreate(std::forward<DelegateBase>(func), params); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<GenericFactory::NonConst> PrivateCreateCached(DelegateBase&& func, DelegateBase&& creator, Int size, const DataDictionary& params) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FactoryFactory::PrivateCreateCached(std::forward<DelegateBase>(func), std::forward<DelegateBase>(creator), size, params); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<const Data&> CreateDataCached(const FactoryInterface* factory, const DataDictionary& params, DataCreator* dc) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return FactoryFactory::CreateDataCached(factory, params, dc); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE FactoryFactory::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<GenericFactory::NonConst>>::value,
		maxon::details::NullReturnType<Result<GenericFactory::NonConst>>::value,
		maxon::details::NullReturnType<Result<const Data&>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool FactoryFactory::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<GenericFactory::NonConst>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FactoryFactory_PrivateCreate = &Wrapper<Unresolved>::_FactoryFactory_PrivateCreate;
	#else
		tbl->_FactoryFactory_PrivateCreate = &Wrapper<Unresolved>::_FactoryFactory_PrivateCreate;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<GenericFactory::NonConst>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FactoryFactory_PrivateCreateCached = &Wrapper<Unresolved>::_FactoryFactory_PrivateCreateCached;
	#else
		tbl->_FactoryFactory_PrivateCreateCached = &Wrapper<Unresolved>::_FactoryFactory_PrivateCreateCached;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<const Data&>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_FactoryFactory_CreateDataCached = &Wrapper<Unresolved>::_FactoryFactory_CreateDataCached;
	#else
		tbl->_FactoryFactory_CreateDataCached = &Wrapper<Unresolved>::_FactoryFactory_CreateDataCached;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(FactoryFactory, "net.maxon.interface.factoryfactory", nullptr);
	template <typename DUMMY> maxon::Int FactoryFactory::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_factory(0
	| maxon::FactoryInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::FactoryFactory::PrivateInstantiateNullValueHelper<maxon::Int>()
);
