#ifndef REFLECTION_H__
#define REFLECTION_H__

#include "maxon/reflectionbase.h"

namespace maxon
{

namespace reflection
{

class Proxy
{
	MAXON_INTERFACE_NONVIRTUAL(Proxy, MAXON_REFERENCE_NONE, "net.maxon.reflection.interface.proxy");
public:
	static MAXON_METHOD Result<Int> AddComponents(ClassInterface* cls, Bool classProxy, const Block<const InterfaceReference* const>& interfaces, Bool includeBaseInterfaces);

	template <typename... I> static Result<Int> AddComponents(ClassInterface* cls, Bool classProxy, Bool includeBaseInterfaces)
	{
		const InterfaceReference* interfaces[] = {&I::_interface...};
		return AddComponents(cls, classProxy, interfaces, includeBaseInterfaces);
	}

	static MAXON_METHOD Result<void> SetHandler(ObjectInterface* object, Int component, ProxyHandler&& handler);

	static MAXON_METHOD Result<void> SetHandler(ClassInterface* cls, Int component, ProxyHandler&& handler);

	/// @MAXON_ANNOTATION{methodId="GetClass@e953c8ace7754084"->"GetClass@490a71ce9415958e"}
	static MAXON_METHOD Result<maxon::Class<>> GetClass(const Block<const InterfaceReference* const>& interfaces);

	/// @MAXON_ANNOTATION{methodId="Create@f499fd225b57e493"->"Create@9c43ea65fc6c92c9"}
	static MAXON_METHOD Result<ObjectRef> Create(const maxon::Class<>& cls, ProxyHandler&& handler);
};


#include "reflection1.hxx"
#include "reflection2.hxx"

}

}

#endif // REFLECTION_H__
