
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct FactoryInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(PrivateGetDelegate);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(FactoryInterface_PrivateGetDelegate, PrivateGetDelegate, true, maxon::GenericComponent, const, (const DelegateBase*));
	maxon::Int FactoryInterface_PrivateGetDelegate_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, FactoryInterface, PrivateGetDelegate))
	{
		maxon::Tie(FactoryInterface_PrivateGetDelegate, FactoryInterface_PrivateGetDelegate_Offset) = FactoryInterface_PrivateGetDelegate_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<FactoryInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<FactoryInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct FactoryInterface::Hxx2
{
	template <typename S> class CWrapper : public DataDictionaryObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(PrivateGetDelegate);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataDictionaryObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (FactoryInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, FactoryInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(FactoryInterface_PrivateGetDelegate, maxon::GenericComponent, const, (const DelegateBase*)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->PrivateGetDelegate(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FactoryInterface::PrivateGetDelegate() const -> const DelegateBase*
{
	const FactoryInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(FactoryInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.FactoryInterface_PrivateGetDelegate_Offset), mt_.FactoryInterface_PrivateGetDelegate);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto FactoryInterface::Hxx1::ConstFn<S>::PrivateGetDelegate() const -> HXXADDRET2(const DelegateBase*)
{
	HXXRETURN0(HXXADDRET2(const DelegateBase*)); HXXINVOKE("FactoryInterface::PrivateGetDelegate"); HXXRES; HXXCONST(nullptr) HXXTABLE(FactoryInterface_PrivateGetDelegate); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.FactoryInterface_PrivateGetDelegate_Offset), mt_.FactoryInterface_PrivateGetDelegate));
}
auto FactoryInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FactoryInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_factory)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FactoryInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FactoryInterface() { new (s_ui_maxon_FactoryInterface) maxon::EntityUse(FactoryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/factory.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FactoryInterface(FactoryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/factory.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* FactoryFactory::PrivateGetCppName() { return nullptr; }

struct FactoryFactory::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(FactoryFactory_PrivateCreate, PrivateCreate, MAXON_EXPAND_VA_ARGS, (Result<GenericFactory::NonConst>), DelegateBase&& func, const DataDictionary& params);
	PRIVATE_MAXON_SF_POINTER(FactoryFactory_PrivateCreateCached, PrivateCreateCached, MAXON_EXPAND_VA_ARGS, (Result<GenericFactory::NonConst>), DelegateBase&& func, DelegateBase&& creator, Int size, const DataDictionary& params);
	PRIVATE_MAXON_SF_POINTER(FactoryFactory_CreateDataCached, CreateDataCached, MAXON_EXPAND_VA_ARGS, (Result<const Data&>), const FactoryInterface* factory, const DataDictionary& params, DataCreator* dc);
	template <typename IMPL> void Init()
	{
		FactoryFactory_PrivateCreate = FactoryFactory_PrivateCreate_GetPtr<IMPL>(true);
		FactoryFactory_PrivateCreateCached = FactoryFactory_PrivateCreateCached_GetPtr<IMPL>(true);
		FactoryFactory_CreateDataCached = FactoryFactory_CreateDataCached_GetPtr<IMPL>(true);
	}
};

struct FactoryFactory::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static Result<GenericFactory::NonConst> FactoryFactory_PrivateCreate(DelegateBase&& func, const DataDictionary& params) { return S::PrivateCreate(std::forward<DelegateBase>(func), params); }
		static Result<GenericFactory::NonConst> FactoryFactory_PrivateCreateCached(DelegateBase&& func, DelegateBase&& creator, Int size, const DataDictionary& params) { return S::PrivateCreateCached(std::forward<DelegateBase>(func), std::forward<DelegateBase>(creator), size, params); }
		static Result<const Data&> FactoryFactory_CreateDataCached(const FactoryInterface* factory, const DataDictionary& params, DataCreator* dc) { return S::CreateDataCached(factory, params, dc); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto FactoryFactory::PrivateCreate(DelegateBase&& func, const DataDictionary& params) -> Result<GenericFactory::NonConst>
{
	return MTable::_instance.FactoryFactory_PrivateCreate(std::forward<DelegateBase>(func), params);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FactoryFactory::PrivateCreateCached(DelegateBase&& func, DelegateBase&& creator, Int size, const DataDictionary& params) -> Result<GenericFactory::NonConst>
{
	return MTable::_instance.FactoryFactory_PrivateCreateCached(std::forward<DelegateBase>(func), std::forward<DelegateBase>(creator), size, params);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto FactoryFactory::CreateDataCached(const FactoryInterface* factory, const DataDictionary& params, DataCreator* dc) -> Result<const Data&>
{
	return MTable::_instance.FactoryFactory_CreateDataCached(factory, params, dc);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_factory)
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

