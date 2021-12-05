
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
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
	template <typename IMPL> void Init()
	{
		_Member_GetEnclosingContainer = &IMPL::_Member_GetEnclosingContainer;
		_Member_GetKind = &IMPL::_Member_GetKind;
		_Member_GetSimpleName = &IMPL::_Member_GetSimpleName;
		_Member_GetId = &IMPL::_Member_GetId;
		_Member_ToString = &IMPL::_Member_ToString;
		_Member_GetMembers = &IMPL::_Member_GetMembers;
		_Member_Find = &IMPL::_Member_Find;
	}
};

struct Member::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
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
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_reflection_Member); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_reflection_Member() { new (s_ui_maxon_reflection_Member) maxon::EntityUse(Member::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_reflection_Member(Member::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
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
	template <typename IMPL> void Init()
	{
		_Container_GetClasses = &IMPL::_Container_GetClasses;
		_Container_FindClass = &IMPL::_Container_FindClass;
		_Container_GetFunctions = &IMPL::_Container_GetFunctions;
		_Container_FindFunction = &IMPL::_Container_FindFunction;
		_Container_FindFunctions = &IMPL::_Container_FindFunctions;
	}
};

struct Container::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper : public Member::Hxx2::Wrapper<C>
	{
	public:
	static Block<const Class* const> _Container_GetClasses(const Container* this_) { return ((const C*) this_)->GetClasses(); }
	static const Class* _Container_FindClass(const Container* this_, const Id& name) { return ((const C*) this_)->FindClass(name); }
	static Block<const Function* const> _Container_GetFunctions(const Container* this_) { return ((const C*) this_)->GetFunctions(); }
	static Result<const Function*> _Container_FindFunction(const Container* this_, const Id& name) { return ((const C*) this_)->FindFunction(name); }
	static Result<void> _Container_FindFunctions(const Container* this_, const Id& name, const ValueReceiver<const Function*>& result) { return ((const C*) this_)->FindFunctions(name, result); }
	};

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
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_reflection_Container); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_reflection_Container() { new (s_ui_maxon_reflection_Container) maxon::EntityUse(Container::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_reflection_Container(Container::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
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
	template <typename IMPL> void Init()
	{
		_Package_GetPackages = &IMPL::_Package_GetPackages;
		_Package_FindPackage = &IMPL::_Package_FindPackage;
		_Package_GetGlobalPackage = &IMPL::_Package_GetGlobalPackage;
	}
};

struct Package::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper : public Container::Hxx2::Wrapper<C>
	{
	public:
	static Block<const Package* const> _Package_GetPackages(const Package* this_) { return ((const C*) this_)->GetPackages(); }
	static const Package* _Package_FindPackage(const Package* this_, const Id& name) { return ((const C*) this_)->FindPackage(name); }
	static const Package* _Package_GetGlobalPackage() { return C::GetGlobalPackage(); }
	};

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
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_reflection_Package); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_reflection_Package() { new (s_ui_maxon_reflection_Package) maxon::EntityUse(Package::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_reflection_Package(Package::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct Class::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	const InterfaceReference* (*_Class_GetInterface) (const Class* this_);
	const NonvirtualInterfaceReference* (*_Class_GetNonvirtualInterface) (const Class* this_);
	Block<const Class* const> (*_Class_GetBaseClasses) (const Class* this_);
	const Class* (*_Class_GetStaticInterface) (const Class* this_);
	template <typename IMPL> void Init()
	{
		_Class_GetInterface = &IMPL::_Class_GetInterface;
		_Class_GetNonvirtualInterface = &IMPL::_Class_GetNonvirtualInterface;
		_Class_GetBaseClasses = &IMPL::_Class_GetBaseClasses;
		_Class_GetStaticInterface = &IMPL::_Class_GetStaticInterface;
	}
};

struct Class::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper : public Container::Hxx2::Wrapper<C>
	{
	public:
	static const InterfaceReference* _Class_GetInterface(const Class* this_) { return ((const C*) this_)->GetInterface(); }
	static const NonvirtualInterfaceReference* _Class_GetNonvirtualInterface(const Class* this_) { return ((const C*) this_)->GetNonvirtualInterface(); }
	static Block<const Class* const> _Class_GetBaseClasses(const Class* this_) { return ((const C*) this_)->GetBaseClasses(); }
	static const Class* _Class_GetStaticInterface(const Class* this_) { return ((const C*) this_)->GetStaticInterface(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Class::GetInterface() const -> const InterfaceReference*
{
	return MTable::_instance._Class_GetInterface(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Class::GetNonvirtualInterface() const -> const NonvirtualInterfaceReference*
{
	return MTable::_instance._Class_GetNonvirtualInterface(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Class::GetBaseClasses() const -> Block<const Class* const>
{
	return MTable::_instance._Class_GetBaseClasses(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Class::GetStaticInterface() const -> const Class*
{
	return MTable::_instance._Class_GetStaticInterface(this);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_reflection_Class); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_reflection_Class() { new (s_ui_maxon_reflection_Class) maxon::EntityUse(Class::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_reflection_Class(Class::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
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
	const Block<const Parameter>& (*_Function_GetParameters) (const Function* this_);
	Bool (*_Function_IsPure) (const Function* this_);
	void* (*_Function_GetAddress) (const Function* this_);
	const Function* (*_Function_PrivateFindMethod) (const InterfaceReference& vi, Int offset);
	Result<void> (*_Function_FindAll) (const Id& memberId, const ValueReceiver<const Function*>& result);
	template <typename IMPL> void Init()
	{
		_Function_Invoke = &IMPL::_Function_Invoke;
		_Function_GetReturnType = &IMPL::_Function_GetReturnType;
		_Function_GetParameterTypes = &IMPL::_Function_GetParameterTypes;
		_Function_GetParameters = &IMPL::_Function_GetParameters;
		_Function_IsPure = &IMPL::_Function_IsPure;
		_Function_GetAddress = &IMPL::_Function_GetAddress;
		_Function_PrivateFindMethod = &IMPL::_Function_PrivateFindMethod;
		_Function_FindAll = &IMPL::_Function_FindAll;
	}
};

struct Function::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper : public Member::Hxx2::Wrapper<C>
	{
	public:
	static Result<void> _Function_Invoke(const Function* this_, void* result, const Block<Argument>& arguments) { return ((const C*) this_)->Invoke(result, arguments); }
	static ParameterType _Function_GetReturnType(const Function* this_) { return ((const C*) this_)->GetReturnType(); }
	static Block<const ParameterType> _Function_GetParameterTypes(const Function* this_) { return ((const C*) this_)->GetParameterTypes(); }
	static const Block<const Parameter>& _Function_GetParameters(const Function* this_) { return ((const C*) this_)->GetParameters(); }
	static Bool _Function_IsPure(const Function* this_) { return ((const C*) this_)->IsPure(); }
	static void* _Function_GetAddress(const Function* this_) { return ((const C*) this_)->GetAddress(); }
	static const Function* _Function_PrivateFindMethod(const InterfaceReference& vi, Int offset) { return C::PrivateFindMethod(vi, offset); }
	static Result<void> _Function_FindAll(const Id& memberId, const ValueReceiver<const Function*>& result) { return C::FindAll(memberId, result); }
	};

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
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::GetParameters() const -> const Block<const Parameter>&
{
	return MTable::_instance._Function_GetParameters(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::IsPure() const -> Bool
{
	return MTable::_instance._Function_IsPure(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::GetAddress() const -> void*
{
	return MTable::_instance._Function_GetAddress(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::PrivateFindMethod(const InterfaceReference& vi, Int offset) -> const Function*
{
	return MTable::_instance._Function_PrivateFindMethod(vi, offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::FindAll(const Id& memberId, const ValueReceiver<const Function*>& result) -> Result<void>
{
	return MTable::_instance._Function_FindAll(memberId, result);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_reflection_Function); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_reflection_Function() { new (s_ui_maxon_reflection_Function) maxon::EntityUse(Function::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_reflection_Function(Function::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

