/*
	DON'T INCLUDE THIS FILE!
	It needs to be included only by the automatically created file register.cpp.
*/

#define PRIVATE_MAXON_REGISTRATION_UNIT

#if defined(MAXON_MODULE_ID)
	// Do not add ModuleInfo for kernel.framework or additional registrations (when multiple register*.cpp are used).
	#if !defined(PRIVATE_MODULE_net_maxon_kernel) && !defined(PRIVATE_MAXON_EXTRA_REGISTRATION_UNIT)
		#define PRIVATE_MAXON_DEFINE_MODULE_INFO
	#endif
#else
	#error "Module ID is missing"
#endif

#include "maxon/object.h"

#ifdef MAXON_COMPILER_MSVC
#pragma warning( disable : 4996)
#endif // MAXON_COMPILER_MSVC

namespace maxon
{

namespace details
{

#ifdef PRIVATE_MAXON_DEFINE_MODULE_INFO
	#ifdef MAXON_API
		// This is the ModuleInfo used by a framework.
		template <UInt64 MODULE_ID_HASH> ModuleInfo ModuleInfoWrapper<MODULE_ID_HASH>::info(MAXON_MODULE_ID, &g_translationUnit, EntityBase::FLAGS::FRAMEWORK PRIVATE_MAXON_DEFINE_MODULE_INFO_FLAGS);
	#else
		// This is the ModuleInfo used by a module.
		template <UInt64 MODULE_ID_HASH> ModuleInfo ModuleInfoWrapper<MODULE_ID_HASH>::info(MAXON_MODULE_ID, &g_translationUnit, EntityBase::FLAGS::NONE PRIVATE_MAXON_DEFINE_MODULE_INFO_FLAGS);
	#endif
#endif

}

class SetUsedFrameworks
{
public:
	explicit SetUsedFrameworks(ModuleInfo& module, const Block<const LiteralId>& ids)
	{
		if (module._usedFrameworks)
			__debugbreak();
		module._usedFrameworks = static_cast<const Id*>(ids.GetFirst());
		module._usedFrameworksCount = ids.GetCount();
	}
};

class SetExpectedModuleDependencies
{
public:
	explicit SetExpectedModuleDependencies(ModuleInfo& module, const Block<const Tuple<const Char*, ModuleInfo::DEPENDENCY>>& deps)
	{
		if (module._expectedModuleDependencies)
			__debugbreak();
		module._expectedModuleDependencies = deps.GetFirst();
		module._expectedModuleDependenciesCount = deps.GetCount();
	}
};

namespace details
{

class ForceEvaluation
{
public:
	explicit ForceEvaluation(Int expr)
	{
		sum += expr;
	}

	static Int sum;
};

#define MAXON_REGISTRY_REGISTER(R) namespace R { const maxon::DataType& Registry::GetDataType() { return maxon::GetDataType<EntryType>(); } maxon::RegistryReference Registry::_reference(Registry::GetId(), &maxon::g_translationUnit); }

#define MAXON_INTERFACE_REGISTER_NULLIMPL(I) (maxon::NonvirtualInterfaceReference::MTableInitializer) &maxon::details::InitMTable<typename I::MTable, typename I::Hxx2::template Wrapper<typename I::Hxx2::Null>>

#define MAXON_INTERFACE_REGISTER(I, IID, NULL_IMPL, FLAGS) \
	I::MTable I::MTable::_instance; \
	I::MTable I::MTable::_unresolvedInstance; \
	maxon::NonvirtualInterfaceReference I::_interface(IID, (maxon::MTableBase*) &I::MTable::_instance, (maxon::MTableBase*) &I::MTable::_unresolvedInstance, I::MTable::_ids, SIZEOF(I::MTable) / SIZEOF(void*), (maxon::NonvirtualInterfaceReference::UnresolvedInitializer) &I::MTable::InitUnresolved, NULL_IMPL, &maxon::g_translationUnit, I::REFERENCE_KIND | FLAGS)

#define MAXON_DEFAULT_VALUE_INCOMPLETE_GET_DEFINITION \
	namespace maxon \
	{ \
		template <typename T> T DefaultValueTypeHelper<T>::IncompleteGet() { return maxon::PrivateDefaultValueHelper<T>(OVERLOAD_MAX_RANK); } \
		template <typename T> const T& DefaultValueTypeHelper<const T&>::IncompleteGet() { return maxon::PrivateConstRefDefaultValueHelper<T>(OVERLOAD_MAX_RANK); } \
	}

template <typename T> inline Int InstantiateDefaultReturnValue(OverloadRank0)
{
	return 0;
}

template <typename T> inline typename SFINAEHelper<Int, typename std::enable_if<!STD_IS_REPLACEMENT(scalar, typename std::remove_reference<T>::type)>::type, typename DefaultValueFunctions<typename std::decay<T>::type>::Default>::type InstantiateDefaultReturnValue(OverloadRank1)
{
	return (Int) (void*) &DefaultValueTypeHelper<T>::IncompleteGet;
}

}

} // namespace maxon
