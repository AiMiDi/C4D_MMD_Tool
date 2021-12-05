
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct Member::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	const Container* (*_Member_GetEnclosingContainer) (const Member* this_);
	KIND (*_Member_GetKind) (const Member* this_);
	const Id& (*_Member_GetSimpleName) (const Member* this_);
	const Id& (*_Member_GetId) (const Member* this_);
	String (*_Member_ToString) (const Member* this_, const FormatStatement* fs);
	Result<Bool> (*_Member_GetMembers) (const ValueReceiver<const Member&>& members);
	const Member* (*_Member_Find) (const Id& memberId);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_Member_GetEnclosingContainer = &IMPL::_Member_GetEnclosingContainer;
		tbl->_Member_GetKind = &IMPL::_Member_GetKind;
		tbl->_Member_GetSimpleName = &IMPL::_Member_GetSimpleName;
		tbl->_Member_GetId = &IMPL::_Member_GetId;
		tbl->_Member_ToString = &IMPL::_Member_ToString;
		tbl->_Member_GetMembers = &IMPL::_Member_GetMembers;
		tbl->_Member_Find = &IMPL::_Member_Find;
	}
};

template <typename C> class Member::Wrapper
{
public:
	static const Container* _Member_GetEnclosingContainer(const Member* this_) { return ((const C*) this_)->GetEnclosingContainer(); }
	static KIND _Member_GetKind(const Member* this_) { return ((const C*) this_)->GetKind(); }
	static const Id& _Member_GetSimpleName(const Member* this_) { return ((const C*) this_)->GetSimpleName(); }
	static const Id& _Member_GetId(const Member* this_) { return ((const C*) this_)->GetId(); }
	static String _Member_ToString(const Member* this_, const FormatStatement* fs) { return ((const C*) this_)->ToString(fs); }
	static Result<Bool> _Member_GetMembers(const ValueReceiver<const Member&>& members) { return C::GetMembers(members); }
	static const Member* _Member_Find(const Id& memberId) { return C::Find(memberId); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto Member::GetEnclosingContainer() const -> const Container*
{
	return MTable::_instance._Member_GetEnclosingContainer(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Member::GetKind() const -> KIND
{
	return MTable::_instance._Member_GetKind(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Member::GetSimpleName() const -> const Id&
{
	return MTable::_instance._Member_GetSimpleName(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Member::GetId() const -> const Id&
{
	return MTable::_instance._Member_GetId(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Member::ToString(const FormatStatement* fs) const -> String
{
	return MTable::_instance._Member_ToString(this, fs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Member::GetMembers(const ValueReceiver<const Member&>& members) -> Result<Bool>
{
	return MTable::_instance._Member_GetMembers(members);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Member::Find(const Id& memberId) -> const Member*
{
	return MTable::_instance._Member_Find(memberId);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_reflection_Member(Member::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false);
#endif

struct Container::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	Block<const Class* const> (*_Container_GetClasses) (const Container* this_);
	const Class* (*_Container_FindClass) (const Container* this_, const Id& name);
	Block<const Function* const> (*_Container_GetFunctions) (const Container* this_);
	Result<const Function*> (*_Container_FindFunction) (const Container* this_, const Id& name);
	Result<void> (*_Container_FindFunctions) (const Container* this_, const Id& name, const ValueReceiver<const Function*>& result);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_Container_GetClasses = &IMPL::_Container_GetClasses;
		tbl->_Container_FindClass = &IMPL::_Container_FindClass;
		tbl->_Container_GetFunctions = &IMPL::_Container_GetFunctions;
		tbl->_Container_FindFunction = &IMPL::_Container_FindFunction;
		tbl->_Container_FindFunctions = &IMPL::_Container_FindFunctions;
	}
};

template <typename C> class Container::Wrapper : public Member::Wrapper<C>
{
public:
	static Block<const Class* const> _Container_GetClasses(const Container* this_) { return ((const C*) this_)->GetClasses(); }
	static const Class* _Container_FindClass(const Container* this_, const Id& name) { return ((const C*) this_)->FindClass(name); }
	static Block<const Function* const> _Container_GetFunctions(const Container* this_) { return ((const C*) this_)->GetFunctions(); }
	static Result<const Function*> _Container_FindFunction(const Container* this_, const Id& name) { return ((const C*) this_)->FindFunction(name); }
	static Result<void> _Container_FindFunctions(const Container* this_, const Id& name, const ValueReceiver<const Function*>& result) { return ((const C*) this_)->FindFunctions(name, result); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto Container::GetClasses() const -> Block<const Class* const>
{
	return MTable::_instance._Container_GetClasses(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Container::FindClass(const Id& name) const -> const Class*
{
	return MTable::_instance._Container_FindClass(this, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Container::GetFunctions() const -> Block<const Function* const>
{
	return MTable::_instance._Container_GetFunctions(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Container::FindFunction(const Id& name) const -> Result<const Function*>
{
	return MTable::_instance._Container_FindFunction(this, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Container::FindFunctions(const Id& name, const ValueReceiver<const Function*>& result) const -> Result<void>
{
	return MTable::_instance._Container_FindFunctions(this, name, result);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_reflection_Container(Container::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false);
#endif

struct Package::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	Block<const Package* const> (*_Package_GetPackages) (const Package* this_);
	const Package* (*_Package_FindPackage) (const Package* this_, const Id& name);
	const Package* (*_Package_GetGlobalPackage) ();
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_Package_GetPackages = &IMPL::_Package_GetPackages;
		tbl->_Package_FindPackage = &IMPL::_Package_FindPackage;
		tbl->_Package_GetGlobalPackage = &IMPL::_Package_GetGlobalPackage;
	}
};

template <typename C> class Package::Wrapper : public Container::Wrapper<C>
{
public:
	static Block<const Package* const> _Package_GetPackages(const Package* this_) { return ((const C*) this_)->GetPackages(); }
	static const Package* _Package_FindPackage(const Package* this_, const Id& name) { return ((const C*) this_)->FindPackage(name); }
	static const Package* _Package_GetGlobalPackage() { return C::GetGlobalPackage(); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto Package::GetPackages() const -> Block<const Package* const>
{
	return MTable::_instance._Package_GetPackages(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Package::FindPackage(const Id& name) const -> const Package*
{
	return MTable::_instance._Package_FindPackage(this, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Package::GetGlobalPackage() -> const Package*
{
	return MTable::_instance._Package_GetGlobalPackage();
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_reflection_Package(Package::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false);
#endif

struct Class::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	const NonvirtualInterfaceReference* (*_Class_GetInterface) (const Class* this_);
	const InterfaceReference* (*_Class_GetVirtualInterface) (const Class* this_);
	Block<const Class* const> (*_Class_GetBaseClasses) (const Class* this_);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_Class_GetInterface = &IMPL::_Class_GetInterface;
		tbl->_Class_GetVirtualInterface = &IMPL::_Class_GetVirtualInterface;
		tbl->_Class_GetBaseClasses = &IMPL::_Class_GetBaseClasses;
	}
};

template <typename C> class Class::Wrapper : public Container::Wrapper<C>
{
public:
	static const NonvirtualInterfaceReference* _Class_GetInterface(const Class* this_) { return ((const C*) this_)->GetInterface(); }
	static const InterfaceReference* _Class_GetVirtualInterface(const Class* this_) { return ((const C*) this_)->GetVirtualInterface(); }
	static Block<const Class* const> _Class_GetBaseClasses(const Class* this_) { return ((const C*) this_)->GetBaseClasses(); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto Class::GetInterface() const -> const NonvirtualInterfaceReference*
{
	return MTable::_instance._Class_GetInterface(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Class::GetVirtualInterface() const -> const InterfaceReference*
{
	return MTable::_instance._Class_GetVirtualInterface(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Class::GetBaseClasses() const -> Block<const Class* const>
{
	return MTable::_instance._Class_GetBaseClasses(this);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_reflection_Class(Class::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false);
#endif

struct Function::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	Result<void> (*_Function_Invoke) (const Function* this_, void* result, const Block<Argument>& arguments);
	ParameterType (*_Function_GetReturnType) (const Function* this_);
	Block<const ParameterType> (*_Function_GetParameterTypes) (const Function* this_);
	const Function* (*_Function_PrivateFindMethod) (const InterfaceReference& vi, Int offset);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_Function_Invoke = &IMPL::_Function_Invoke;
		tbl->_Function_GetReturnType = &IMPL::_Function_GetReturnType;
		tbl->_Function_GetParameterTypes = &IMPL::_Function_GetParameterTypes;
		tbl->_Function_PrivateFindMethod = &IMPL::_Function_PrivateFindMethod;
	}
};

template <typename C> class Function::Wrapper : public Member::Wrapper<C>
{
public:
	static Result<void> _Function_Invoke(const Function* this_, void* result, const Block<Argument>& arguments) { return ((const C*) this_)->Invoke(result, arguments); }
	static ParameterType _Function_GetReturnType(const Function* this_) { return ((const C*) this_)->GetReturnType(); }
	static Block<const ParameterType> _Function_GetParameterTypes(const Function* this_) { return ((const C*) this_)->GetParameterTypes(); }
	static const Function* _Function_PrivateFindMethod(const InterfaceReference& vi, Int offset) { return C::PrivateFindMethod(vi, offset); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto Function::Invoke(void* result, const Block<Argument>& arguments) const -> Result<void>
{
	return MTable::_instance._Function_Invoke(this, result, arguments);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::GetReturnType() const -> ParameterType
{
	return MTable::_instance._Function_GetReturnType(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::GetParameterTypes() const -> Block<const ParameterType>
{
	return MTable::_instance._Function_GetParameterTypes(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::PrivateFindMethod(const InterfaceReference& vi, Int offset) -> const Function*
{
	return MTable::_instance._Function_PrivateFindMethod(vi, offset);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_reflection_Function(Function::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

