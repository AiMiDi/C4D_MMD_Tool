
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* Member::PrivateGetCppName() { return nullptr; }

struct Member::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_MF_POINTER(Member_GetEnclosingContainer, GetEnclosingContainer, false, Member, const, (const Container*));
	PRIVATE_MAXON_MF_POINTER(Member_GetKind, GetKind, false, Member, const, (KIND));
	PRIVATE_MAXON_MF_POINTER(Member_GetSimpleName, GetSimpleName, false, Member, const, (const Id&));
	PRIVATE_MAXON_MF_POINTER(Member_GetId, GetId, false, Member, const, (const Id&));
	PRIVATE_MAXON_MF_POINTER(Member_ToString, ToString, false, Member, const, (String), const FormatStatement* fs);
	PRIVATE_MAXON_SF_POINTER(Member_GetMembers, GetMembers, MAXON_EXPAND_VA_ARGS, (Result<Bool>), const ValueReceiver<const Member&>& members);
	PRIVATE_MAXON_SF_POINTER(Member_Find, Find, MAXON_EXPAND_VA_ARGS, (const Member*), const Id& memberId);
	template <typename IMPL> void Init()
	{
		Member_GetEnclosingContainer = Member_GetEnclosingContainer_GetPtr<IMPL>(0, true).first;
		Member_GetKind = Member_GetKind_GetPtr<IMPL>(0, true).first;
		Member_GetSimpleName = Member_GetSimpleName_GetPtr<IMPL>(0, true).first;
		Member_GetId = Member_GetId_GetPtr<IMPL>(0, true).first;
		Member_ToString = Member_ToString_GetPtr<IMPL>(0, true).first;
		Member_GetMembers = Member_GetMembers_GetPtr<IMPL>(true);
		Member_Find = Member_Find_GetPtr<IMPL>(true);
	}
};

struct Member::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		PRIVATE_MAXON_MF_WRAPPER(Member_GetEnclosingContainer, Member, const, (const Container*)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Member))->GetEnclosingContainer(); }
		PRIVATE_MAXON_MF_WRAPPER(Member_GetKind, Member, const, (KIND)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Member))->GetKind(); }
		PRIVATE_MAXON_MF_WRAPPER(Member_GetSimpleName, Member, const, (const Id&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Member))->GetSimpleName(); }
		PRIVATE_MAXON_MF_WRAPPER(Member_GetId, Member, const, (const Id&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Member))->GetId(); }
		PRIVATE_MAXON_MF_WRAPPER(Member_ToString, Member, const, (String), const FormatStatement* fs) { return C::Get(PRIVATE_MAXON_MF_THIS(const Member))->ToString(fs); }
		static Result<Bool> Member_GetMembers(const ValueReceiver<const Member&>& members) { return C::GetMembers(members); }
		static const Member* Member_Find(const Id& memberId) { return C::Find(memberId); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Member::GetEnclosingContainer() const -> const Container*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Member_GetEnclosingContainer);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Member::GetKind() const -> KIND
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Member_GetKind);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Member::GetSimpleName() const -> const Id&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Member_GetSimpleName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Member::GetId() const -> const Id&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Member_GetId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Member::ToString(const FormatStatement* fs) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Member_ToString, fs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Member::GetMembers(const ValueReceiver<const Member&>& members) -> Result<Bool>
{
	return MTable::_instance.Member_GetMembers(members);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Member::Find(const Id& memberId) -> const Member*
{
	return MTable::_instance.Member_Find(memberId);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_reflectionbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_reflection_Member); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_reflection_Member() { new (s_ui_maxon_reflection_Member) maxon::EntityUse(Member::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_reflection_Member(Member::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* Container::PrivateGetCppName() { return nullptr; }

struct Container::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_MF_POINTER(Container_GetClasses, GetClasses, false, Container, const, (Block<const Class* const>));
	PRIVATE_MAXON_MF_POINTER(Container_FindClass, FindClass, false, Container, const, (const Class*), const Id& name);
	PRIVATE_MAXON_MF_POINTER(Container_GetFunctions, GetFunctions, false, Container, const, (Block<const Function* const>));
	PRIVATE_MAXON_MF_POINTER(Container_FindFunction, FindFunction, false, Container, const, (Result<const Function*>), const Id& name);
	PRIVATE_MAXON_MF_POINTER(Container_FindFunctions, FindFunctions, false, Container, const, (Result<void>), const Id& name, const ValueReceiver<const Function*>& result);
	template <typename IMPL> void Init()
	{
		Container_GetClasses = Container_GetClasses_GetPtr<IMPL>(0, true).first;
		Container_FindClass = Container_FindClass_GetPtr<IMPL>(0, true).first;
		Container_GetFunctions = Container_GetFunctions_GetPtr<IMPL>(0, true).first;
		Container_FindFunction = Container_FindFunction_GetPtr<IMPL>(0, true).first;
		Container_FindFunctions = Container_FindFunctions_GetPtr<IMPL>(0, true).first;
	}
};

struct Container::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper : public Member::Hxx2::Wrapper<C>
	{
	public:
		PRIVATE_MAXON_MF_WRAPPER(Container_GetClasses, Container, const, (Block<const Class* const>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Container))->GetClasses(); }
		PRIVATE_MAXON_MF_WRAPPER(Container_FindClass, Container, const, (const Class*), const Id& name) { return C::Get(PRIVATE_MAXON_MF_THIS(const Container))->FindClass(name); }
		PRIVATE_MAXON_MF_WRAPPER(Container_GetFunctions, Container, const, (Block<const Function* const>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Container))->GetFunctions(); }
		PRIVATE_MAXON_MF_WRAPPER(Container_FindFunction, Container, const, (Result<const Function*>), const Id& name) { return C::Get(PRIVATE_MAXON_MF_THIS(const Container))->FindFunction(name); }
		PRIVATE_MAXON_MF_WRAPPER(Container_FindFunctions, Container, const, (Result<void>), const Id& name, const ValueReceiver<const Function*>& result) { return C::Get(PRIVATE_MAXON_MF_THIS(const Container))->FindFunctions(name, result); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Container::GetClasses() const -> Block<const Class* const>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Container_GetClasses);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Container::FindClass(const Id& name) const -> const Class*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Container_FindClass, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Container::GetFunctions() const -> Block<const Function* const>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Container_GetFunctions);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Container::FindFunction(const Id& name) const -> Result<const Function*>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Container_FindFunction, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Container::FindFunctions(const Id& name, const ValueReceiver<const Function*>& result) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Container_FindFunctions, name, result);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_reflectionbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_reflection_Container); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_reflection_Container() { new (s_ui_maxon_reflection_Container) maxon::EntityUse(Container::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_reflection_Container(Container::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* Package::PrivateGetCppName() { return nullptr; }

struct Package::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_MF_POINTER(Package_GetPackages, GetPackages, false, Package, const, (Block<const Package* const>));
	PRIVATE_MAXON_MF_POINTER(Package_FindPackage, FindPackage, false, Package, const, (const Package*), const Id& name);
	PRIVATE_MAXON_SF_POINTER(Package_GetGlobalPackage, GetGlobalPackage, MAXON_EXPAND_VA_ARGS, (const Package*));
	template <typename IMPL> void Init()
	{
		Package_GetPackages = Package_GetPackages_GetPtr<IMPL>(0, true).first;
		Package_FindPackage = Package_FindPackage_GetPtr<IMPL>(0, true).first;
		Package_GetGlobalPackage = Package_GetGlobalPackage_GetPtr<IMPL>(true);
	}
};

struct Package::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper : public Container::Hxx2::Wrapper<C>
	{
	public:
		PRIVATE_MAXON_MF_WRAPPER(Package_GetPackages, Package, const, (Block<const Package* const>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Package))->GetPackages(); }
		PRIVATE_MAXON_MF_WRAPPER(Package_FindPackage, Package, const, (const Package*), const Id& name) { return C::Get(PRIVATE_MAXON_MF_THIS(const Package))->FindPackage(name); }
		static const Package* Package_GetGlobalPackage() { return C::GetGlobalPackage(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Package::GetPackages() const -> Block<const Package* const>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Package_GetPackages);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Package::FindPackage(const Id& name) const -> const Package*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Package_FindPackage, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Package::GetGlobalPackage() -> const Package*
{
	return MTable::_instance.Package_GetGlobalPackage();
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_reflectionbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_reflection_Package); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_reflection_Package() { new (s_ui_maxon_reflection_Package) maxon::EntityUse(Package::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_reflection_Package(Package::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* Class::PrivateGetCppName() { return nullptr; }

struct Class::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_MF_POINTER(Class_GetInterface, GetInterface, false, Class, const, (const InterfaceReference*));
	PRIVATE_MAXON_MF_POINTER(Class_GetNonvirtualInterface, GetNonvirtualInterface, false, Class, const, (const NonvirtualInterfaceReference*));
	PRIVATE_MAXON_MF_POINTER(Class_GetBaseClasses, GetBaseClasses, false, Class, const, (Block<const Class* const>));
	PRIVATE_MAXON_MF_POINTER(Class_GetStaticInterface, GetStaticInterface, false, Class, const, (const Class*));
	template <typename IMPL> void Init()
	{
		Class_GetInterface = Class_GetInterface_GetPtr<IMPL>(0, true).first;
		Class_GetNonvirtualInterface = Class_GetNonvirtualInterface_GetPtr<IMPL>(0, true).first;
		Class_GetBaseClasses = Class_GetBaseClasses_GetPtr<IMPL>(0, true).first;
		Class_GetStaticInterface = Class_GetStaticInterface_GetPtr<IMPL>(0, true).first;
	}
};

struct Class::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper : public Container::Hxx2::Wrapper<C>
	{
	public:
		PRIVATE_MAXON_MF_WRAPPER(Class_GetInterface, Class, const, (const InterfaceReference*)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Class))->GetInterface(); }
		PRIVATE_MAXON_MF_WRAPPER(Class_GetNonvirtualInterface, Class, const, (const NonvirtualInterfaceReference*)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Class))->GetNonvirtualInterface(); }
		PRIVATE_MAXON_MF_WRAPPER(Class_GetBaseClasses, Class, const, (Block<const Class* const>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Class))->GetBaseClasses(); }
		PRIVATE_MAXON_MF_WRAPPER(Class_GetStaticInterface, Class, const, (const Class*)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Class))->GetStaticInterface(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Class::GetInterface() const -> const InterfaceReference*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Class_GetInterface);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Class::GetNonvirtualInterface() const -> const NonvirtualInterfaceReference*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Class_GetNonvirtualInterface);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Class::GetBaseClasses() const -> Block<const Class* const>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Class_GetBaseClasses);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Class::GetStaticInterface() const -> const Class*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Class_GetStaticInterface);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_reflectionbase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_reflection_Class); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_reflection_Class() { new (s_ui_maxon_reflection_Class) maxon::EntityUse(Class::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_reflection_Class(Class::_interface.GetReference(), &maxon::g_translationUnit, "maxon/reflectionbase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* Function::PrivateGetCppName() { return nullptr; }

struct Function::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_MF_POINTER(Function_Invoke, Invoke, false, Function, const, (Result<void>), void* result, const Block<Argument>& arguments);
	PRIVATE_MAXON_MF_POINTER(Function_GetReturnType, GetReturnType, false, Function, const, (ParameterType));
	PRIVATE_MAXON_MF_POINTER(Function_GetParameterTypes, GetParameterTypes, false, Function, const, (Block<const ParameterType>));
	PRIVATE_MAXON_MF_POINTER(Function_GetParameters, GetParameters, false, Function, const, (const Block<const Parameter>&));
	PRIVATE_MAXON_MF_POINTER(Function_IsPure, IsPure, false, Function, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(Function_GetAddress, GetAddress, false, Function, const, (void*));
	PRIVATE_MAXON_SF_POINTER(Function_PrivateFindMethod, PrivateFindMethod, MAXON_EXPAND_VA_ARGS, (const Function*), const InterfaceReference& vi, Int offset);
	PRIVATE_MAXON_SF_POINTER(Function_FindAll, FindAll, MAXON_EXPAND_VA_ARGS, (Result<void>), const Id& memberId, const ValueReceiver<const Function*>& result);
	template <typename IMPL> void Init()
	{
		Function_Invoke = Function_Invoke_GetPtr<IMPL>(0, true).first;
		Function_GetReturnType = Function_GetReturnType_GetPtr<IMPL>(0, true).first;
		Function_GetParameterTypes = Function_GetParameterTypes_GetPtr<IMPL>(0, true).first;
		Function_GetParameters = Function_GetParameters_GetPtr<IMPL>(0, true).first;
		Function_IsPure = Function_IsPure_GetPtr<IMPL>(0, true).first;
		Function_GetAddress = Function_GetAddress_GetPtr<IMPL>(0, true).first;
		Function_PrivateFindMethod = Function_PrivateFindMethod_GetPtr<IMPL>(true);
		Function_FindAll = Function_FindAll_GetPtr<IMPL>(true);
	}
};

struct Function::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper : public Member::Hxx2::Wrapper<C>
	{
	public:
		PRIVATE_MAXON_MF_WRAPPER(Function_Invoke, Function, const, (Result<void>), void* result, const Block<Argument>& arguments) { return C::Get(PRIVATE_MAXON_MF_THIS(const Function))->Invoke(result, arguments); }
		PRIVATE_MAXON_MF_WRAPPER(Function_GetReturnType, Function, const, (ParameterType)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Function))->GetReturnType(); }
		PRIVATE_MAXON_MF_WRAPPER(Function_GetParameterTypes, Function, const, (Block<const ParameterType>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Function))->GetParameterTypes(); }
		PRIVATE_MAXON_MF_WRAPPER(Function_GetParameters, Function, const, (const Block<const Parameter>&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Function))->GetParameters(); }
		PRIVATE_MAXON_MF_WRAPPER(Function_IsPure, Function, const, (Bool)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Function))->IsPure(); }
		PRIVATE_MAXON_MF_WRAPPER(Function_GetAddress, Function, const, (void*)) { return C::Get(PRIVATE_MAXON_MF_THIS(const Function))->GetAddress(); }
		static const Function* Function_PrivateFindMethod(const InterfaceReference& vi, Int offset) { return C::PrivateFindMethod(vi, offset); }
		static Result<void> Function_FindAll(const Id& memberId, const ValueReceiver<const Function*>& result) { return C::FindAll(memberId, result); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::Invoke(void* result, const Block<Argument>& arguments) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Function_Invoke, result, arguments);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::GetReturnType() const -> ParameterType
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Function_GetReturnType);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::GetParameterTypes() const -> Block<const ParameterType>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Function_GetParameterTypes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::GetParameters() const -> const Block<const Parameter>&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Function_GetParameters);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::IsPure() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Function_IsPure);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::GetAddress() const -> void*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.Function_GetAddress);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::PrivateFindMethod(const InterfaceReference& vi, Int offset) -> const Function*
{
	return MTable::_instance.Function_PrivateFindMethod(vi, offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Function::FindAll(const Id& memberId, const ValueReceiver<const Function*>& result) -> Result<void>
{
	return MTable::_instance.Function_FindAll(memberId, result);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_reflectionbase)
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

