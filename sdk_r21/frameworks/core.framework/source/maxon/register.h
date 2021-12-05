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

#define MAXON_REGISTRY_REGISTER(R) namespace R { const maxon::DataType& Registry::GetDataType() { return maxon::GetDataType<EntryType>(); } maxon::RegistryReference Registry::_reference(Registry::GetId(), &maxon::g_translationUnit, Registry::ENTRY_FLAGS); }

#define MAXON_INTERFACE_REGISTER_NULLIMPL(I) (maxon::NonvirtualInterfaceReference::MTableInitializer) &maxon::details::InitMTable<typename I::MTable, typename I::Hxx2::template Wrapper<typename I::Hxx2::Null>>

#define MAXON_INTERFACE_REGISTER(I, IID, NULL_IMPL) \
	I::MTable I::MTable::_instance; \
	I::MTable I::MTable::_unresolvedInstance; \
	maxon::NonvirtualInterfaceReference I::_interface(IID, (maxon::MTableBase*) &I::MTable::_instance, (maxon::MTableBase*) &I::MTable::_unresolvedInstance, I::MTable::_ids, SIZEOF(I::MTable) / SIZEOF(void*), (maxon::NonvirtualInterfaceReference::UnresolvedInitializer) &I::MTable::InitUnresolved, NULL_IMPL, &maxon::g_translationUnit, I::REFERENCE_KIND)

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
