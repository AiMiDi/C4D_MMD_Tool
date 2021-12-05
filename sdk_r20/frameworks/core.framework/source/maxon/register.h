/*
	DON'T INCLUDE THIS FILE!
	It needs to be included only by the automatically created file register.cpp.
*/

#define PRIVATE_MAXON_REGISTRATION_UNIT


#if defined(MAXON_MODULE_ID) && !defined(PRIVATE_MODULE_net_maxon_kernel) && !defined(PRIVATE_MAXON_EXTRA_REGISTRATION_UNIT)
	#define PRIVATE_MAXON_DEFINE_MODULE_INFO
#endif

#include "maxon/object.h"

namespace maxon
{

namespace details
{

#ifdef PRIVATE_MAXON_DEFINE_MODULE_INFO
	#ifdef MAXON_API
		template <UInt64 MODULE_ID_HASH> ModuleInfo ModuleInfoWrapper<MODULE_ID_HASH>::info(MAXON_MODULE_ID, &g_translationUnit, EntityBase::FLAGS::FRAMEWORK PRIVATE_MAXON_DEFINE_MODULE_INFO_FLAGS);
	#else
		template <UInt64 MODULE_ID_HASH> ModuleInfo ModuleInfoWrapper<MODULE_ID_HASH>::info(MAXON_MODULE_ID, &g_translationUnit, EntityBase::FLAGS::NONE PRIVATE_MAXON_DEFINE_MODULE_INFO_FLAGS);
	#endif
#endif

}

class SetUsedFrameworks
{
public:
	explicit SetUsedFrameworks(ModuleInfo& module, const Block<const Id>& ids)
	{
		if (module._usedFrameworks)
			__debugbreak();
		module._usedFrameworks = ids.GetFirst();
		module._usedFrameworksCount = ids.GetCount();
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

#ifdef MAXON_TARGET_MACOS
static_assert(std::is_trivially_copyable<Result<void>>::value && (SIZEOF(Result<void>) == SIZEOF(Int)), "Result<void> can't be passed in a register!");
#endif

template <typename T> class NullReturnType
{
public:
	static const NULL_RETURN_TYPE value = std::is_void<T>::value ? NULL_RETURN_TYPE::VOID_ZERO
		: (std::is_integral<T>::value || std::is_pointer<T>::value) ? NULL_RETURN_TYPE::INTEGRAL_ZERO
		: std::is_floating_point<T>::value ? (std::is_same<const float, const T>::value ? NULL_RETURN_TYPE::FLOAT_ZERO : NULL_RETURN_TYPE::DOUBLE_ZERO)
#ifdef MAXON_TARGET_MACOS
		// Result<void> is passed in a register
		: std::is_same<T, Result<void>>::value ? NULL_RETURN_TYPE::INTEGRAL_ZERO
#endif
		: (std::is_lvalue_reference<T>::value && std::is_const<typename std::remove_reference<T>::type>::value
			 && GetDirectlyReferencedType<typename std::remove_reference<T>::type>::value) ? NULL_RETURN_TYPE::POINTER_TO_ZERO
		: NULL_RETURN_TYPE::OTHER;
};

#define MAXON_REGISTRY_REGISTER(R) namespace R { const maxon::DataType* Registry::GetDataType() { return maxon::GetDataType<EntryType>(); } maxon::RegistryReference Registry::_reference(Registry::GetId(), &maxon::g_translationUnit, Registry::ENTRY_FLAGS); }

#define MAXON_INTERFACE_REGISTER_NULLIMPL(I) (maxon::NonvirtualInterfaceReference::MTableInitializer) &I::MTable::Init<I::Wrapper<I::Null>>

#define MAXON_INTERFACE_REGISTER(I, IID, NULL_IMPL) \
	I::MTable I::MTable::_instance; \
	I::MTable I::MTable::_unresolvedInstance; \
	maxon::NonvirtualInterfaceReference I::_interface(IID, (maxon::MTableBase*) &I::MTable::_instance, (maxon::MTableBase*) &I::MTable::_unresolvedInstance, I::MTable::_ids, SIZEOF(I::MTable) / SIZEOF(void*), (maxon::NonvirtualInterfaceReference::UnresolvedInitializer) &I::MTable::InitUnresolved, NULL_IMPL, &maxon::g_translationUnit, I::REFERENCE_KIND)

#define MAXON_INTERFACE_REGISTER_VIRTUAL(I, IID, NAME, MTABLE_INSTANCE, ...) \
	MTABLE_INSTANCE \
	static const maxon::InterfaceReference* g_baseInterfaces_##I[] = {__VA_ARGS__}; \
	maxon::InterfaceReference I::_interface(IID, NAME, g_baseInterfaces_##I, I::MTable::_ids, &maxon::g_translationUnit, I::REFERENCE_KIND | I::INTERFACE_FLAGS)

#define MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_IMPL(I, IID, NAME, MTABLE_INSTANCE, ...) \
	MTABLE_INSTANCE \
	static const maxon::InterfaceReference* g_baseInterfaces_##I[] = {__VA_ARGS__}; \
	maxon::InterfaceReference I::_interface(IID, NAME, g_baseInterfaces_##I, I::MTable::_ids, &maxon::g_translationUnit, I::REFERENCE_KIND | I::INTERFACE_FLAGS); \
	maxon::NonvirtualMTableReference I::_nonvirtualMTable(IID, &I::MTable::_nonvirtual, &I::MTable::CombinedMTable<maxon::CombinedMTableRoot>::Init, &maxon::g_translationUnit)

#define MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(I, IID, NAME, MTABLE_INSTANCE, BASE) \
	MTABLE_INSTANCE \
	maxon::InterfaceReference I::_interface(IID, NAME, BASE, I::MTable::_ids, &maxon::g_translationUnit, I::REFERENCE_KIND | I::INTERFACE_FLAGS)

#define MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE_SINGLE_IMPL(I, IID, NAME, MTABLE_INSTANCE, BASE) \
	MTABLE_INSTANCE \
	maxon::InterfaceReference I::_interface(IID, NAME, BASE, I::MTable::_ids, &maxon::g_translationUnit, I::REFERENCE_KIND | I::INTERFACE_FLAGS); \
	maxon::NonvirtualMTableReference I::_nonvirtualMTable(IID, &I::MTable::_nonvirtual, (maxon::NonvirtualMTableReference::Initializer*) &I::MTable::CombinedMTable<maxon::CombinedMTableRoot>::Init, &maxon::g_translationUnit)

#define MAXON_INTERFACE_REGISTER_STATIC(I, IID) \
	I::StaticMTable I::StaticMTable::_instance; \
	I::StaticMTable I::StaticMTable::_unresolvedInstance; \
	maxon::NonvirtualInterfaceReference I::_staticInterface(IID, (maxon::MTableBase*) &I::StaticMTable::_instance, (maxon::MTableBase*) &I::StaticMTable::_unresolvedInstance, I::StaticMTable::_ids, SIZEOF(I::StaticMTable) / SIZEOF(void*), (maxon::NonvirtualInterfaceReference::UnresolvedInitializer) &I::StaticMTable::InitUnresolved, &maxon::g_translationUnit, I::REFERENCE_KIND)

#define MAXON_NULL_VALUE_INCOMPLETE_GET_DEFINITION \
	namespace maxon \
	{ \
		template <typename T> T NullValueTypeHelper<T>::IncompleteGet() { return maxon::PrivateNullValueHelper<T>(OVERLOAD_MAX_RANK); } \
		template <typename T> const T& NullValueTypeHelper<const T&>::IncompleteGet() { return maxon::PrivateConstRefNullValueHelper<T>(OVERLOAD_MAX_RANK); } \
	}

template <typename T> inline Int InstantiateNullReturnValue(OverloadRank0)
{
	return 0;
}

template <typename T> inline typename SFINAEHelper<Int, typename std::enable_if<!std::is_scalar<typename std::remove_reference<T>::type>::value>::type, typename NullValueFunctions<typename std::decay<T>::type>::Default>::type InstantiateNullReturnValue(OverloadRank1)
{
	return (Int) (void*) &NullValueTypeHelper<T>::IncompleteGet;
}

}

} // namespace maxon
