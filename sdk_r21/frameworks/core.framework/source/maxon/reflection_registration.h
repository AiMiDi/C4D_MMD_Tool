#ifndef REFLECTION_REGISTRATION_H__
#define REFLECTION_REGISTRATION_H__

#include "maxon/reflectionbase.h"

namespace maxon
{

namespace reflection
{

struct FunctionInfo
{
	FunctionInfo() { }

	FunctionInfo(const Char* n, Member::KIND k, const ParameterType& ret, const Block<const ParameterType>& paramTypes, const Char* paramNames, Int64 inOut, void* nat, InvocationWrapper wrap);

	const Char* name;
	Member::KIND kind;
	ParameterType returnType;
	BaseArray<Parameter> parameters;
	void* native;
	InvocationWrapper wrapper;
};

using FunctionRegistrationCallback = Result<void> (*)(Class* cls, const EntityReference* interfaceRef, const Block<FunctionInfo>& functions);
using ReflectionRegistration = Result<void> (*)(Class* cls, FunctionRegistrationCallback callback);

struct ContainerInfo
{
	ContainerInfo(const Char* i, const ComponentDescriptor* pr, ReflectionRegistration reg, ModuleInfo* module);

	const Char* cid; // identifier of container, or nullptr if functions of a namespace shall be registered
	const ComponentDescriptor* const proxy;
	ReflectionRegistration registration;

	const ContainerInfo* const next;

	static const ContainerInfo* Get(const ModuleInfo* module)
	{
		return module->_containerInfos;
	}
};


template <typename X = void> inline void GetParameterTypes(const ParameterType* array)
{
	static_assert(std::is_same<X, void>::value, "MSVC hack not working.");
}

template <typename X, typename... ARGS> inline void GetParameterTypes(ParameterType* array)
{
	*array = ParameterType::Get<X>();
	GetParameterTypes<ARGS...>(array + 1);
}


template <typename SIG> class ReflectionWrapper;

template <typename T, typename... ARGS> class ReflectionWrapper<T(ARGS...)>
{
public:
	using Ptr = T(*)(ARGS...);

	static FunctionInfo GetInfo(const Char* name, Member::KIND kind, const Char* paramNames, Int64 inOut, Ptr fn, const Function** reflectionMethod)
	{
		ParameterType paramTypes[Max<Int>(sizeof...(ARGS), 1)]; // Max is needed for functions without parameters to avoid an empty array.
		GetParameterTypes<ARGS...>(paramTypes);
		return FunctionInfo(name, kind, ParameterType::Get<T>(), ToBlock(paramTypes, sizeof...(ARGS)), paramNames, inOut, fn ? (void*) fn : reflectionMethod, &Invocation<T, ARGS...>::Invoke);
	}
};


template <typename T> inline FunctionInfo GetFunctionInfo(const Char* name, Member::KIND kind, const Char* paramNames, Int64 inOut, T* fn)
{
	return ReflectionWrapper<T>::GetInfo(name, kind, paramNames, inOut, fn, nullptr);
}

template <typename T> inline FunctionInfo GetVirtualFunctionInfo(Member::KIND kind, const Char* paramNames, Int64 inOut, const Function** reflectionMethod)
{
	return ReflectionWrapper<typename std::remove_pointer<T>::type>::GetInfo(nullptr, kind, paramNames, inOut, nullptr, reflectionMethod);
}

#define MAXON_GET_VIRTUAL_METHOD_INFO(kind, paramNames, inOut, interface, ptrname) \
	maxon::reflection::GetVirtualFunctionInfo<decltype(interface::MTable::ptrname)>(reflection::Member::KIND::kind, paramNames, inOut, &interface::ProxyComponent::_fn##ptrname)

}

}

#endif // REFLECTION_REGISTRATION_H__
