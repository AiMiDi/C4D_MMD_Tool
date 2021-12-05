#ifndef REFLECTIONBASE_H__
#define REFLECTIONBASE_H__

#include "maxon/parametertype.h"
#include "maxon/hashmap.h"

namespace maxon
{

namespace reflection
{


class Container;
class Class;
class Function;


//----------------------------------------------------------------------------------------
/// Member is the root interface of the reflection hierarchy. A Member may be
/// - a Container, which is either
///   - a Package
///   - or a Class
/// - or a Function
///
/// All members except the global package have an enclosing container as their parent.
/// For example, the method StringInterface::GetLength() has the class StringInterface as enclosing
/// container, which has the maxon package as enclosing container, which has the global package
/// as enclosing container.
//----------------------------------------------------------------------------------------
class Member
{
	MAXON_INTERFACE_NONVIRTUAL(Member, MAXON_REFERENCE_NONE, "net.maxon.reflection.interface.member");
public:
	//----------------------------------------------------------------------------------------
	/// This enum defines the possible kinds of a Member. Exactly one of the flags is set
	/// in the value returned by GetKind().
	//----------------------------------------------------------------------------------------
	enum class KIND
	{
		PACKAGE = 1,									///< The member is a Package.
		CLASS = 2,										///< The member is a Class.
		FUNCTION = 4,									///< The member is a Function (either at package scope, or a static class member).
		INSTANCE_FUNCTION = 8,				///< The member is a non-const instance function (i.e., non-static class member).
		CONST_INSTANCE_FUNCTION = 16,	///< The member is a const instance function (i.e., non-static class member).
		CONTAINER_TEST = PACKAGE | CLASS,
		FUNCTION_TEST = FUNCTION | INSTANCE_FUNCTION | CONST_INSTANCE_FUNCTION
	} MAXON_ENUM_FLAGS_CLASS(KIND);

	//----------------------------------------------------------------------------------------
	/// Returns the enclosing container of this member. All members except the global package
	/// have such an enclosing container: Functions and classes are nested in classes or packages,
	/// packages are nested in other packages.
	/// @return												The enclosing container of this member, or nullptr if this is the global package.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Container* GetEnclosingContainer() const;

	//----------------------------------------------------------------------------------------
	/// Returns the kind of this member. This allows to tell whether this Member can be safely cast
	/// to a Package, Class or Function. The returned value has exactly one of the KIND flags set.
	/// @return												Kind of this member.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD KIND GetKind() const;

	//----------------------------------------------------------------------------------------
	/// Returns the (unqualified) name of this member. E.g., for maxon::StringInterface::GetLength this is
	/// "GetLength".
	/// @return												Name of this member.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Id& GetSimpleName() const;

	//----------------------------------------------------------------------------------------
	/// Returns a unique id for this member. This is the qualified name of the member (with dot
	/// as separator), plus optionally an additional code for disambiguation, separated by "@".
	///	For functions, a hashcode which depends on the parameter and return types is used
	///	to disambiguate between overloads (such as "net.maxon.asin@919429e0").
	///
	/// The function Find() allows to find a Member for the id.
	/// @return												Unique id for this member.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Id& GetId() const;

	//----------------------------------------------------------------------------------------
	/// Returns a readable string of the content.
	/// @param[in] fs									Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	/// @return												The converted result.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String ToString(const FormatStatement* fs) const;

	//----------------------------------------------------------------------------------------
	/// Yields all registered members
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Bool> GetMembers(const ValueReceiver<const Member&>& members);

	//----------------------------------------------------------------------------------------
	/// Finds the member whose id is @p memberId. The id has to be in a format as specified
	/// by GetId(). If there is no member with the given @p memberId, nullptr is returned.
	/// @param[in] memberId						A member id.
	/// @return												The member with the given @p memberId, or nullptr.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const Member* Find(const Id& memberId);
};


//----------------------------------------------------------------------------------------
/// Container is the base interface of members which may contain other members, i.e., of
/// packages and classes. Correspondingly, there are two derived interfaces Package and Class.
//----------------------------------------------------------------------------------------
class Container : public Member
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(Container, MAXON_REFERENCE_NONE, "net.maxon.reflection.interface.container");
public:
	//----------------------------------------------------------------------------------------
	/// Returns a list of all classes which are members of this container. For a Package,
	/// these are its top-level classes. For a Class, these are the direct member classes,
	/// excluding inherited member classes.
	/// @return												All classes which are direct members of this container.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Block<const Class* const> GetClasses() const;

	//----------------------------------------------------------------------------------------
	/// Finds the class which is a direct member of this container and has the given (unqualified) @p name.
	/// This does not search for inherited member classes of a class.
	/// @param[in] name								Name of the class to find.
	/// @return												The found class, or nullptr if there is no class with the given @p name.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Class* FindClass(const Id& name) const;

	//----------------------------------------------------------------------------------------
	/// Returns a list of all functions which are members of this container. For a Package,
	/// these are its top-level functions. For a Class, these are its member functions,
	/// excluding inherited member functions.
	/// @return												All functions which are direct members of this container.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Block<const Function* const> GetFunctions() const;

	//----------------------------------------------------------------------------------------
	/// Finds the function which is a direct member of this container and has the given (unqualified) @p name.
	/// If no such function exists, or if the function is overloaded, an error is returned.
	/// This does not search for inherited member functions of classes.
	/// @param[in] name								Name of the function to find.
	/// @return												The found function, or an error if no function is found or the function is overloaded.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<const Function*> FindFunction(const Id& name) const;

	//----------------------------------------------------------------------------------------
	/// Finds all functions which are direct members of this container and have the given (unqualified) @p name.
	/// This does not search for inherited member functions of classes.
	/// @param[in] name								Name of the function to find.
	/// @param[out] result						Receiver for the found functions.
	/// @return												OK unless a memory allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> FindFunctions(const Id& name, const ValueReceiver<const Function*>& result) const;

	static const Container* Find(const Id& memberId)
	{
		const Member* m = Member::Find(memberId);
		return (m && (m->GetKind() & KIND::CONTAINER_TEST)) ? static_cast<const Container*>(m) : nullptr;
	}
};


//----------------------------------------------------------------------------------------
/// Package represents a package, that is a container of other packages, functions or classes
/// which share the same prefix in their identifiers.
//----------------------------------------------------------------------------------------
class Package : public Container
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(Package, MAXON_REFERENCE_NONE, "net.maxon.reflection.interface.package");
public:
	//----------------------------------------------------------------------------------------
	/// Returns a list of all packages which are directly contained within this package.
	/// @return												All packages which are directly contained within this package.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Block<const Package* const> GetPackages() const;

	//----------------------------------------------------------------------------------------
	/// Finds the package which is directly contained within this package and has the given (unqualified) @p name.
	/// @param[in] name								Name of the package to find.
	/// @return												The found package, or nullptr if there is no package with the given @p name.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Package* FindPackage(const Id& name) const;

	//----------------------------------------------------------------------------------------
	/// Returns the global package. All other members are directly or indirectly contained within the global package.
	/// @return												Representation of the global package.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD const Package* GetGlobalPackage();
};


//----------------------------------------------------------------------------------------
/// Class represents a C++ class. It may contain member functions and member classes.
/// Also if the class is an interface (in the sense of the MAXON API), the corresponding
/// interface information can be obtained from Class.
//----------------------------------------------------------------------------------------
class Class : public Container
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(Class, MAXON_REFERENCE_NONE, "net.maxon.reflection.interface.class");
public:
	//----------------------------------------------------------------------------------------
	/// Returns a corresponding InterfaceReference if this Class is virtual interface,
	/// otherwise nullptr. If the interface has static methods, also GetNonvirtualInterface()
	/// returns a valid pointer which points to the NonvirtualInterfaceReference for the static methods.
	/// @return												A InterfaceReference for this Class, or nullptr if this is no virtual interface.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const InterfaceReference* GetInterface() const;

	//----------------------------------------------------------------------------------------
	/// Returns a corresponding NonvirtualInterfaceReference if this Class is a non-virtual interface,
	/// or if this Class is a virtual interface with static methods.
	/// otherwise nullptr.
	/// @return												An NonvirtualInterfaceReference for this Class, or nullptr if there is no corresponding non-virtual interface.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const NonvirtualInterfaceReference* GetNonvirtualInterface() const;

	//----------------------------------------------------------------------------------------
	/// TODO: (Ole) Not yet supported.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Block<const Class* const> GetBaseClasses() const;

	//----------------------------------------------------------------------------------------
	/// Return a Class containing the static methods of this virtual interface, or nullptr
	/// is this Class isn't a virtual interface or has no static methods.
	/// @return												The Class for the static methods of this virtual interface, or nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Class* GetStaticInterface() const;

	//----------------------------------------------------------------------------------------
	/// Finds the class whose id is @p memberId. The id is the qualified name of the class with
	/// dot as separator, see Member::GetId().
	/// If there is no class with the given @p memberId, nullptr is returned.
	/// @param[in] memberId						A member id for a class.
	/// @return												The class with the given @p memberId, or nullptr.
	//----------------------------------------------------------------------------------------
	static const Class* Find(const Id& memberId)
	{
		const Member* m = Member::Find(memberId);
		return (m && (m->GetKind() == KIND::CLASS)) ? static_cast<const Class*>(m) : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Finds the Class object for a given non-virtual or virtual interface.
	/// @tparam INTERFACE							The interface class (such as StringInterface).
	/// @return												The Class object for the given interface, or nullptr if no reflection was registered for that interface.
	//----------------------------------------------------------------------------------------
	template <typename INTERFACE> static const Class* FindInterface()
	{
		return Find(INTERFACE::_interface.GetId());
	}

	//----------------------------------------------------------------------------------------
	/// Finds the Class object for a given non-virtual interface reference.
	/// @param[in] i									The interface.
	/// @return												The Class object for the given interface, or nullptr if no reflection was registered for that interface or #i was nullptr.
	//----------------------------------------------------------------------------------------
	static const Class* FindInterface(const NonvirtualInterfaceReference* i)
	{
		return i ? Find(i->GetId()) : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Finds the Class object for a given virtual interface reference.
	/// @param[in] i									The interface.
	/// @return												The Class object for the given interface, or nullptr if no reflection was registered for that interface or #i was nullptr.
	//----------------------------------------------------------------------------------------
	static const Class* FindInterface(const InterfaceReference* i)
	{
		return i ? Find(i->GetId()) : nullptr;
	}
};



template <typename T> struct InvokeHelper;


//----------------------------------------------------------------------------------------
/// Function represents a C++ function. It describes the name, return type and parameter types
/// of the function, but also has the Invoke method to invoke the function.
///
/// There are three kinds of functions:
/// - KIND::FUNCTION is used for functions at package scope, or for static member functions
/// - KIND::INSTANCE_FUNCTION is used for non-static non-const member functions (which need a <tt>c</tt> this instance)
/// - KIND::CONST_INSTANCE_FUNCTION is used for non-static const member functions (which need a <tt>const this</tt> instance)
///
/// The implicit @c this argument is not part of the parameter types, but for the Invoke method
/// it has to be specified as first argument if the function is an instance function.
//----------------------------------------------------------------------------------------
class Function : public Member
{
	MAXON_INTERFACE_NONVIRTUAL_DERIVED(Function, MAXON_REFERENCE_NONE, "net.maxon.reflection.interface.function");

public:
	//----------------------------------------------------------------------------------------
	/// Invokes this function with the given arguments. If this is an instance function,
	/// the @c this pointer has to be given as first argument. @p result has to point to an object
	/// of the return type of the function, the result will then be written to that object.
	/// For a function with @c void return type, @p result may be @c nullptr.
	///
	/// @param[out] result						Pointer to a value to which the function result is written. May be @c nullptr if the functions returns @c void.
	/// 															The type of the value must be the return type of the function, otherwise the behaviour is undefined.
	/// @param[in] arguments					Arguments for the function. For an instance function, the first argument is the @c this pointer.
	/// 															The arguments have to match in type, otherwise the behaviour is undefined.
	/// @return												An error if the argument count doesn't match or (for a non-@c void function) @p result is @c nullptr, otherwise OK.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Invoke(void* result, const Block<Argument>& arguments) const;

	//----------------------------------------------------------------------------------------
	/// Invokes this function with the given arguments. If this is an instance function,
	/// the @c this pointer has to be given as first argument. @p T has to be of the form
	/// <tt>R(A1, ..., An)</tt>, where @c R is the return type of the function and
	/// @c A1, ..., @c An are the parameter types. For instance functions, @c A1 has to be the
	/// type of the additional @c this argument. If the types don't match the actual types of the
	/// function, the behaviour is undefined.
	///
	/// @tparam T											Type of the function of the form <tt>R(A1, ..., An)</tt>.
	/// 															If this doesn't match the actual type, the behaviour is undefined.
	/// @param[in] args								Arguments for the function. For an instance function, the first argument is the @c this pointer.
	/// @return												An error if the argument count doesn't match, otherwise OK.
	//----------------------------------------------------------------------------------------
	template <typename T, typename... ARGS> Result<typename InvokeHelper<T>::type> Invoke(ARGS&&... args) const
	{
		return InvokeHelper<T>::Invoke(this, std::forward<ARGS>(args)...);
	}

	MAXON_METHOD ParameterType GetReturnType() const;

	MAXON_METHOD Block<const ParameterType> GetParameterTypes() const;

	MAXON_METHOD const Block<const Parameter>& GetParameters() const;

	MAXON_METHOD Bool IsPure() const;

	MAXON_METHOD void* GetAddress() const;

	static MAXON_METHOD const Function* PrivateFindMethod(const InterfaceReference& vi, Int offset);

	static const Function* Find(const Id& memberId)
	{
		const Member* m = Member::Find(memberId);
		return (m && (m->GetKind() & KIND::FUNCTION_TEST)) ? static_cast<const Function*>(m) : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Finds all functions overloads which have the given (unqualified) @p id.
	/// @param[in] memberId						A member id.
	/// @param[out] result						Receiver for the found functions.
	/// @return												OK unless a memory allocation failed.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> FindAll(const Id& memberId, const ValueReceiver<const Function*>& result);
};


template <typename T, typename... ARGS> struct InvokeHelper<T(ARGS...)>
{
	using type = T;

	static Result<T> Invoke(const Function* fn, ARGS... args)
	{
		iferr_scope;
		T value;
		Argument a[] = {Argument::For<ARGS>(args)...};
		fn->Invoke(&value, a) iferr_return;
		return std::move(value);
	}
};

template <typename... ARGS> struct InvokeHelper<void(ARGS...)>
{
	using type = void;

	static Result<void> Invoke(const Function* fn, ARGS... args)
	{
		Argument a[] = {Argument::For<ARGS>(args)...};
		return fn->Invoke(nullptr, a);
	}
};

template <typename T> struct InvokeHelper<T()>
{
	using type = T;

	static Result<T> Invoke(const Function* fn)
	{
		iferr_scope;
		T value;
		fn->Invoke(&value, Block<Argument>()) iferr_return;
		return std::move(value);
	}
};

template <> struct InvokeHelper<void()>
{
	using type = void;

	static Result<void> Invoke(const Function* fn)
	{
		return fn->Invoke(nullptr, Block<Argument>());
	}
};


using InvocationWrapper = void(*)(const void* native, void* result, const Block<Argument>& arguments);


struct ProxyInvocation
{
public:
	ProxyInvocation(void* result, const Block<Argument>& args, InvocationWrapper wrapper, const void* super) : _result(result), _args(args), _wrapper(wrapper), _super(super)
	{
	}

	template <typename T> T& GetResult() const
	{
		return *reinterpret_cast<T*>(_result);
	}

	template <typename T> auto GetArgument(Int index) const -> decltype(Argument().Get<T>())
	{
		return _args[index+1].Get<T>();
	}

	Int GetArgumentCount() const
	{
		return _args.GetCount() - 1;
	}

	Block<Argument> GetArguments() const
	{
		return _args.Slice(1);
	}

	const Block<Argument>& GetArgumentsIncludingSelf() const
	{
		return _args;
	}

	Bool HasSuper() const
	{
		return _super != nullptr;
	}

	void Super() const
	{
		_wrapper(_super, _result, _args);
	}

private:
	void* _result;
	Block<Argument> _args;
	InvocationWrapper _wrapper;
	const void* _super;
};


using ProxyHandler = maxon::Delegate<void(const Function*, ObjectInterface*, const ProxyInvocation&)>;


#include "reflectionbase1.hxx"
#include "reflectionbase2.hxx"

}

}

#endif // REFLECTIONBASE_H__
