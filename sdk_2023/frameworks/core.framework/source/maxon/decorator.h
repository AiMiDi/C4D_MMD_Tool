#ifndef DECORATOR_H__
#define DECORATOR_H__

#include "maxon/object.h"

namespace maxon
{

namespace details
{
template <EntityBase::FLAGS FLAGS> struct ObjectBaseRefImpl;
template <> struct ObjectBaseRefImpl<EntityBase::FLAGS::REFERENCE_NORMAL> { using type = ObjectRef; };
template <> struct ObjectBaseRefImpl<EntityBase::FLAGS::REFERENCE_CONST> { using type = StrongRef<const ObjectInterface>; };
template <> struct ObjectBaseRefImpl<EntityBase::FLAGS::REFERENCE_COPY_ON_WRITE> { using type = StrongCOWRef<ObjectInterface>; };
}

template <typename I> using ObjectBaseRef = typename maxon::details::ObjectBaseRefImpl<I::REFERENCE_KIND>::type;

//----------------------------------------------------------------------------------------
/// This interface is implemented by decorator classes which forward calls to the base object.
//----------------------------------------------------------------------------------------
class DecoratorInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(DecoratorInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.decorator");

public:
	//----------------------------------------------------------------------------------------
	/// @return												The decorated object.
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ObjectRef PrivateGetDecoratedObject() const;

	//----------------------------------------------------------------------------------------
	/// @return												The decorated object.
	/// @MAXON_ANNOTATION{interfaceParameter=INTERFACE}
	//----------------------------------------------------------------------------------------
	template <typename INTERFACE> MAXON_FUNCTION ObjectBaseRef<INTERFACE> GetDecoratedObject() const
	{
		return ObjectBaseRef<INTERFACE>(std::move(PrivateGetDecoratedObject()));
	}
};

//----------------------------------------------------------------------------------------
/// An eager decorator is a decorator which knows its decorated object already on construction (eagerly).
//----------------------------------------------------------------------------------------
class EagerDecoratorInterface : MAXON_INTERFACE_BASES(DecoratorInterface)
{
	MAXON_INTERFACE(EagerDecoratorInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.eagerdecorator");

public:
	//----------------------------------------------------------------------------------------
	/// Sets the object where all calls should be forwarded to.
	/// @param[in] object							The object to decorate.
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void PrivateSetDecoratedObject(const ObjectRef& object);

	//----------------------------------------------------------------------------------------
	/// Sets the object where all calls should be forwarded to.
	/// @param[in] object							The object to decorate.
	/// @MAXON_ANNOTATION{interfaceParameter=INTERFACE}
	//----------------------------------------------------------------------------------------
	template <typename INTERFACE> MAXON_FUNCTION void SetDecoratedObject(const ObjectBaseRef<INTERFACE>& object)
	{
		PrivateSetDecoratedObject(reinterpret_cast<const ObjectRef&>(object));
	}

	//----------------------------------------------------------------------------------------
	/// Sets the object where all calls should be forwarded to.
	/// @param[in] object							The object to decorate.
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void PrivateSetDecoratedObject(ObjectRef&& object);

	//----------------------------------------------------------------------------------------
	/// Sets the object where all calls should be forwarded to.
	/// @param[in] object							The object to decorate.
	/// @MAXON_ANNOTATION{interfaceParameter=INTERFACE}
	//----------------------------------------------------------------------------------------
	template <typename INTERFACE> MAXON_FUNCTION void SetDecoratedObject(ObjectBaseRef<INTERFACE>&& object)
	{
		PrivateSetDecoratedObject(std::move(reinterpret_cast<ObjectRef&>(object)));
	}
};

MAXON_DECLARATION(ComponentDescriptor, EagerDecoratorComponent, "net.maxon.component.eagerdecorator");


//----------------------------------------------------------------------------------------
/// A weak decorator is a decorator which stores its decorated object as a weak reference.
//----------------------------------------------------------------------------------------
class WeakDecoratorInterface : MAXON_INTERFACE_BASES(DecoratorInterface)
{
	MAXON_INTERFACE(WeakDecoratorInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.weakdecorator");

public:
	//----------------------------------------------------------------------------------------
	/// Sets the object where all calls should be forwarded to.
	/// @param[in] object							The object to decorate.
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void PrivateSetDecoratedObject(const ObjectRef& object);

	//----------------------------------------------------------------------------------------
	/// Sets the object where all calls should be forwarded to.
	/// @param[in] object							The object to decorate.
	/// @MAXON_ANNOTATION{interfaceParameter=INTERFACE}
	//----------------------------------------------------------------------------------------
	template <typename INTERFACE> MAXON_FUNCTION void SetDecoratedObject(const ObjectBaseRef<INTERFACE>& object)
	{
		PrivateSetDecoratedObject(reinterpret_cast<const ObjectRef&>(object));
	}
};

MAXON_DECLARATION(ComponentDescriptor, WeakDecoratorComponent, "net.maxon.component.weakdecorator");


#include "decorator1.hxx"
#include "decorator2.hxx"


}

#endif // DECORATOR_H__
