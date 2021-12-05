#if 1
namespace maxon
{
	namespace reflection
	{
		namespace enum48 { enum class KIND
			{
				PACKAGE = 1,									///< The member is a Package.
				CLASS = 2,										///< The member is a Class.
				FUNCTION = 4,									///< The member is a Function (either at package scope, or a static class member).
				INSTANCE_FUNCTION = 8,				///< The member is a non-const instance function (i.e., non-static class member).
				CONST_INSTANCE_FUNCTION = 16,	///< The member is a const instance function (i.e., non-static class member).
				CONTAINER_TEST = PACKAGE | CLASS,
				FUNCTION_TEST = FUNCTION | INSTANCE_FUNCTION | CONST_INSTANCE_FUNCTION
			} ; }
		maxon::String PrivateToString_KIND48(std::underlying_type<enum48::KIND>::type x, const maxon::FormatStatement* fmt, void*)
		{
			const maxon::UInt64 values[] = {(maxon::UInt64) enum48::KIND::PACKAGE, (maxon::UInt64) enum48::KIND::CLASS, (maxon::UInt64) enum48::KIND::FUNCTION, (maxon::UInt64) enum48::KIND::INSTANCE_FUNCTION, (maxon::UInt64) enum48::KIND::CONST_INSTANCE_FUNCTION, (maxon::UInt64) enum48::KIND::CONTAINER_TEST, (maxon::UInt64) enum48::KIND::FUNCTION_TEST};
			return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "Member::KIND", SIZEOF(x), true, values, "PACKAGE\0CLASS\0FUNCTION\0INSTANCE_FUNCTION\0CONST_INSTANCE_FUNCTION\0CONTAINER_TEST\0FUNCTION_TEST\0", fmt);
		}
		const maxon::Char* const Member::MTable::_ids = 
		"GetEnclosingContainer@cdae5c00faa1bfbd\0" // const Container* GetEnclosingContainer() const
		"GetKind@8424a30b\0" // KIND GetKind() const
		"GetSimpleName@12b0ccb12f8b105\0" // const Id& GetSimpleName() const
		"GetId@12b0ccb12f8b105\0" // const Id& GetId() const
		"ToString@7de9f6f51c89c899\0" // String ToString(const FormatStatement* fs) const
		"GetMembers@254200f7f1d769f3\0" // Result<Bool> GetMembers(const ValueReceiver<const Member&>& members)
		"Find@1dbabe350644d365\0" // const Member* Find(const Id& memberId)
		"";
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_DEPRECATED
		class Member::Hxx2::Unresolved : public Member
		{
		public:
			static const Unresolved* Get(const Member* o) { return (const Unresolved*) o; }
			static Unresolved* Get(Member* o) { return (Unresolved*) o; }
			const Container* GetEnclosingContainer() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Member*) this)->GetEnclosingContainer(); return nullptr;}
			KIND GetKind() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Member*) this)->GetKind(); return maxon::PrivateIncompleteNullReturnValue<KIND>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
			const Id& GetSimpleName() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Member*) this)->GetSimpleName(); return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
			const Id& GetId() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Member*) this)->GetId(); return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
			String ToString(const FormatStatement* fs) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Member*) this)->ToString(fs); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
			static Result<Bool> GetMembers(const ValueReceiver<const Member&>& members) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Member::GetMembers(members); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
			static const Member* Find(const Id& memberId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Member::Find(memberId); return nullptr;}
		};
		MAXON_WARNING_POP
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		const maxon::NULL_RETURN_TYPE Member::MTable::_returnTypes[] = 
		{
			maxon::details::NullReturnType<const Container*>::value,
			maxon::details::NullReturnType<KIND>::value,
			maxon::details::NullReturnType<const Id&>::value,
			maxon::details::NullReturnType<const Id&>::value,
			maxon::details::NullReturnType<String>::value,
			maxon::details::NullReturnType<Result<Bool>>::value,
			maxon::details::NullReturnType<const Member*>::value,
			maxon::NULL_RETURN_TYPE::OTHER
		};
	#endif
		maxon::Bool Member::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
		{
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->_Member_GetEnclosingContainer = &Hxx2::Wrapper<Hxx2::Unresolved>::_Member_GetEnclosingContainer;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<KIND>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Member_GetKind = &Hxx2::Wrapper<Hxx2::Unresolved>::_Member_GetKind;
			#else
			tbl->_Member_GetKind = &Hxx2::Wrapper<Hxx2::Unresolved>::_Member_GetKind;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<const Id&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Member_GetSimpleName = &Hxx2::Wrapper<Hxx2::Unresolved>::_Member_GetSimpleName;
			#else
			tbl->_Member_GetSimpleName = &Hxx2::Wrapper<Hxx2::Unresolved>::_Member_GetSimpleName;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<const Id&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Member_GetId = &Hxx2::Wrapper<Hxx2::Unresolved>::_Member_GetId;
			#else
			tbl->_Member_GetId = &Hxx2::Wrapper<Hxx2::Unresolved>::_Member_GetId;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Member_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_Member_ToString;
			#else
			tbl->_Member_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_Member_ToString;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Member_GetMembers = &Hxx2::Wrapper<Hxx2::Unresolved>::_Member_GetMembers;
			#else
			tbl->_Member_GetMembers = &Hxx2::Wrapper<Hxx2::Unresolved>::_Member_GetMembers;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->_Member_Find = &Hxx2::Wrapper<Hxx2::Unresolved>::_Member_Find;
			#endif
		#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
			return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
		#else
			return true;
		#endif
		}
		MAXON_INTERFACE_REGISTER(Member, "net.maxon.reflection.interface.member", nullptr);
		template <typename DUMMY> maxon::Int Member::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<KIND>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<const Id&>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const Container::MTable::_ids = 
		"GetClasses@73f05112fbf66c75\0" // Block<const Class* const> GetClasses() const
		"FindClass@e1b01f5fe220ad9f\0" // const Class* FindClass(const Id& name) const
		"GetFunctions@7a9bcb6927d6822d\0" // Block<const Function* const> GetFunctions() const
		"FindFunction@2d4fc0fb649daaa6\0" // Result<const Function*> FindFunction(const Id& name) const
		"FindFunctions@230a6b16aff6aa4b\0" // Result<void> FindFunctions(const Id& name, const ValueReceiver<const Function*>& result) const
		"";
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_DEPRECATED
		class Container::Hxx2::Unresolved : public Member::Hxx2::Unresolved
		{
		public:
			operator const Container&() const { return *static_cast<const Container*>(static_cast<const BaseInterface*>(this)); }
			operator Container&() { return *static_cast<Container*>(static_cast<BaseInterface*>(this)); }
			static const Unresolved* Get(const Container* o) { return (const Unresolved*) o; }
			static Unresolved* Get(Container* o) { return (Unresolved*) o; }
			Block<const Class* const> GetClasses() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Container*) this)->GetClasses(); return maxon::PrivateIncompleteNullReturnValue<Block<const Class* const>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
			const Class* FindClass(const Id& name) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Container*) this)->FindClass(name); return nullptr;}
			Block<const Function* const> GetFunctions() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Container*) this)->GetFunctions(); return maxon::PrivateIncompleteNullReturnValue<Block<const Function* const>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
			Result<const Function*> FindFunction(const Id& name) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const Container*) this)->FindFunction(name); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
			Result<void> FindFunctions(const Id& name, const ValueReceiver<const Function*>& result) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const Container*) this)->FindFunctions(name, result); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		};
		MAXON_WARNING_POP
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		const maxon::NULL_RETURN_TYPE Container::MTable::_returnTypes[] = 
		{
			maxon::details::NullReturnType<Block<const Class* const>>::value,
			maxon::details::NullReturnType<const Class*>::value,
			maxon::details::NullReturnType<Block<const Function* const>>::value,
			maxon::details::NullReturnType<Result<const Function*>>::value,
			maxon::details::NullReturnType<Result<void>>::value,
			maxon::NULL_RETURN_TYPE::OTHER
		};
	#endif
		maxon::Bool Container::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
		{
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Block<const Class* const>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Container_GetClasses = &Hxx2::Wrapper<Hxx2::Unresolved>::_Container_GetClasses;
			#else
			tbl->_Container_GetClasses = &Hxx2::Wrapper<Hxx2::Unresolved>::_Container_GetClasses;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->_Container_FindClass = &Hxx2::Wrapper<Hxx2::Unresolved>::_Container_FindClass;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Block<const Function* const>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Container_GetFunctions = &Hxx2::Wrapper<Hxx2::Unresolved>::_Container_GetFunctions;
			#else
			tbl->_Container_GetFunctions = &Hxx2::Wrapper<Hxx2::Unresolved>::_Container_GetFunctions;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<const Function*>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Container_FindFunction = &Hxx2::Wrapper<Hxx2::Unresolved>::_Container_FindFunction;
			#else
			tbl->_Container_FindFunction = &Hxx2::Wrapper<Hxx2::Unresolved>::_Container_FindFunction;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Container_FindFunctions = &Hxx2::Wrapper<Hxx2::Unresolved>::_Container_FindFunctions;
			#else
			tbl->_Container_FindFunctions = &Hxx2::Wrapper<Hxx2::Unresolved>::_Container_FindFunctions;
			#endif
		#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
			return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
		#else
			return true;
		#endif
		}
		MAXON_INTERFACE_REGISTER(Container, "net.maxon.reflection.interface.container", nullptr);
		template <typename DUMMY> maxon::Int Container::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<Block<const Class* const>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<Block<const Function* const>>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const Package::MTable::_ids = 
		"GetPackages@93983379e28b8088\0" // Block<const Package* const> GetPackages() const
		"FindPackage@be1830367658dc08\0" // const Package* FindPackage(const Id& name) const
		"GetGlobalPackage@49fa7d86f7619e87\0" // const Package* GetGlobalPackage()
		"";
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_DEPRECATED
		class Package::Hxx2::Unresolved : public Container::Hxx2::Unresolved
		{
		public:
			operator const Package&() const { return *static_cast<const Package*>(static_cast<const BaseInterface*>(this)); }
			operator Package&() { return *static_cast<Package*>(static_cast<BaseInterface*>(this)); }
			static const Unresolved* Get(const Package* o) { return (const Unresolved*) o; }
			static Unresolved* Get(Package* o) { return (Unresolved*) o; }
			Block<const Package* const> GetPackages() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Package*) this)->GetPackages(); return maxon::PrivateIncompleteNullReturnValue<Block<const Package* const>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
			const Package* FindPackage(const Id& name) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Package*) this)->FindPackage(name); return nullptr;}
			static const Package* GetGlobalPackage() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Package::GetGlobalPackage(); return nullptr;}
		};
		MAXON_WARNING_POP
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		const maxon::NULL_RETURN_TYPE Package::MTable::_returnTypes[] = 
		{
			maxon::details::NullReturnType<Block<const Package* const>>::value,
			maxon::details::NullReturnType<const Package*>::value,
			maxon::details::NullReturnType<const Package*>::value,
			maxon::NULL_RETURN_TYPE::OTHER
		};
	#endif
		maxon::Bool Package::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
		{
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Block<const Package* const>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Package_GetPackages = &Hxx2::Wrapper<Hxx2::Unresolved>::_Package_GetPackages;
			#else
			tbl->_Package_GetPackages = &Hxx2::Wrapper<Hxx2::Unresolved>::_Package_GetPackages;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->_Package_FindPackage = &Hxx2::Wrapper<Hxx2::Unresolved>::_Package_FindPackage;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->_Package_GetGlobalPackage = &Hxx2::Wrapper<Hxx2::Unresolved>::_Package_GetGlobalPackage;
			#endif
		#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
			return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
		#else
			return true;
		#endif
		}
		MAXON_INTERFACE_REGISTER(Package, "net.maxon.reflection.interface.package", nullptr);
		template <typename DUMMY> maxon::Int Package::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<Block<const Package* const>>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const Class::MTable::_ids = 
		"GetInterface@5aa3fc415f83f4aa\0" // const InterfaceReference* GetInterface() const
		"GetNonvirtualInterface@72e02afe449d366c\0" // const NonvirtualInterfaceReference* GetNonvirtualInterface() const
		"GetBaseClasses@de57415d311ace2c\0" // Block<const Class* const> GetBaseClasses() const
		"GetStaticInterface@f6256f7510cfe1de\0" // const Class* GetStaticInterface() const
		"";
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_DEPRECATED
		class Class::Hxx2::Unresolved : public Container::Hxx2::Unresolved
		{
		public:
			operator const Class&() const { return *static_cast<const Class*>(static_cast<const BaseInterface*>(this)); }
			operator Class&() { return *static_cast<Class*>(static_cast<BaseInterface*>(this)); }
			static const Unresolved* Get(const Class* o) { return (const Unresolved*) o; }
			static Unresolved* Get(Class* o) { return (Unresolved*) o; }
			const InterfaceReference* GetInterface() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Class*) this)->GetInterface(); return nullptr;}
			const NonvirtualInterfaceReference* GetNonvirtualInterface() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Class*) this)->GetNonvirtualInterface(); return nullptr;}
			Block<const Class* const> GetBaseClasses() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Class*) this)->GetBaseClasses(); return maxon::PrivateIncompleteNullReturnValue<Block<const Class* const>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
			const Class* GetStaticInterface() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Class*) this)->GetStaticInterface(); return nullptr;}
		};
		MAXON_WARNING_POP
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		const maxon::NULL_RETURN_TYPE Class::MTable::_returnTypes[] = 
		{
			maxon::details::NullReturnType<const InterfaceReference*>::value,
			maxon::details::NullReturnType<const NonvirtualInterfaceReference*>::value,
			maxon::details::NullReturnType<Block<const Class* const>>::value,
			maxon::details::NullReturnType<const Class*>::value,
			maxon::NULL_RETURN_TYPE::OTHER
		};
	#endif
		maxon::Bool Class::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
		{
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->_Class_GetInterface = &Hxx2::Wrapper<Hxx2::Unresolved>::_Class_GetInterface;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->_Class_GetNonvirtualInterface = &Hxx2::Wrapper<Hxx2::Unresolved>::_Class_GetNonvirtualInterface;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Block<const Class* const>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Class_GetBaseClasses = &Hxx2::Wrapper<Hxx2::Unresolved>::_Class_GetBaseClasses;
			#else
			tbl->_Class_GetBaseClasses = &Hxx2::Wrapper<Hxx2::Unresolved>::_Class_GetBaseClasses;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->_Class_GetStaticInterface = &Hxx2::Wrapper<Hxx2::Unresolved>::_Class_GetStaticInterface;
			#endif
		#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
			return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
		#else
			return true;
		#endif
		}
		MAXON_INTERFACE_REGISTER(Class, "net.maxon.reflection.interface.class", nullptr);
		template <typename DUMMY> maxon::Int Class::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<Block<const Class* const>>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const Function::MTable::_ids = 
		"Invoke@69916512dd1dec3d\0" // Result<void> Invoke(void* result, const Block<Argument>& arguments) const
		"GetReturnType@d0282cca56e4e04c\0" // ParameterType GetReturnType() const
		"GetParameterTypes@7b7d0a2eeb81bfa8\0" // Block<const ParameterType> GetParameterTypes() const
		"GetParameters@4a868f893655f527\0" // const Block<const Parameter>& GetParameters() const
		"IsPure@1020e3b4d3277d45\0" // Bool IsPure() const
		"GetAddress@82a274981154cbb9\0" // void* GetAddress() const
		"PrivateFindMethod@53f90404becffa49\0" // const Function* PrivateFindMethod(const InterfaceReference& vi, Int offset)
		"FindAll@908f1539b5711c33\0" // Result<void> FindAll(const Id& memberId, const ValueReceiver<const Function*>& result)
		"";
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_DEPRECATED
		class Function::Hxx2::Unresolved : public Member::Hxx2::Unresolved
		{
		public:
			operator const Function&() const { return *static_cast<const Function*>(static_cast<const BaseInterface*>(this)); }
			operator Function&() { return *static_cast<Function*>(static_cast<BaseInterface*>(this)); }
			static const Unresolved* Get(const Function* o) { return (const Unresolved*) o; }
			static Unresolved* Get(Function* o) { return (Unresolved*) o; }
			Result<void> Invoke(void* result, const Block<Argument>& arguments) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const Function*) this)->Invoke(result, arguments); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
			ParameterType GetReturnType() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Function*) this)->GetReturnType(); return maxon::PrivateIncompleteNullReturnValue<ParameterType>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
			Block<const ParameterType> GetParameterTypes() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Function*) this)->GetParameterTypes(); return maxon::PrivateIncompleteNullReturnValue<Block<const ParameterType>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
			const Block<const Parameter>& GetParameters() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Function*) this)->GetParameters(); return maxon::PrivateIncompleteNullReturnValue<const Block<const Parameter>&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
			Bool IsPure() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Function*) this)->IsPure(); return maxon::PrivateLogNullptrError(false);}
			void* GetAddress() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Function*) this)->GetAddress(); return nullptr;}
			static const Function* PrivateFindMethod(const InterfaceReference& vi, Int offset) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Function::PrivateFindMethod(vi, offset); return nullptr;}
			static Result<void> FindAll(const Id& memberId, const ValueReceiver<const Function*>& result) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Function::FindAll(memberId, result); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		};
		MAXON_WARNING_POP
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		const maxon::NULL_RETURN_TYPE Function::MTable::_returnTypes[] = 
		{
			maxon::details::NullReturnType<Result<void>>::value,
			maxon::details::NullReturnType<ParameterType>::value,
			maxon::details::NullReturnType<Block<const ParameterType>>::value,
			maxon::details::NullReturnType<const Block<const Parameter>&>::value,
			maxon::details::NullReturnType<Bool>::value,
			maxon::details::NullReturnType<void*>::value,
			maxon::details::NullReturnType<const Function*>::value,
			maxon::details::NullReturnType<Result<void>>::value,
			maxon::NULL_RETURN_TYPE::OTHER
		};
	#endif
		maxon::Bool Function::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
		{
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Function_Invoke = &Hxx2::Wrapper<Hxx2::Unresolved>::_Function_Invoke;
			#else
			tbl->_Function_Invoke = &Hxx2::Wrapper<Hxx2::Unresolved>::_Function_Invoke;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<ParameterType>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Function_GetReturnType = &Hxx2::Wrapper<Hxx2::Unresolved>::_Function_GetReturnType;
			#else
			tbl->_Function_GetReturnType = &Hxx2::Wrapper<Hxx2::Unresolved>::_Function_GetReturnType;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Block<const ParameterType>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Function_GetParameterTypes = &Hxx2::Wrapper<Hxx2::Unresolved>::_Function_GetParameterTypes;
			#else
			tbl->_Function_GetParameterTypes = &Hxx2::Wrapper<Hxx2::Unresolved>::_Function_GetParameterTypes;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<const Block<const Parameter>&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Function_GetParameters = &Hxx2::Wrapper<Hxx2::Unresolved>::_Function_GetParameters;
			#else
			tbl->_Function_GetParameters = &Hxx2::Wrapper<Hxx2::Unresolved>::_Function_GetParameters;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->_Function_IsPure = &Hxx2::Wrapper<Hxx2::Unresolved>::_Function_IsPure;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->_Function_GetAddress = &Hxx2::Wrapper<Hxx2::Unresolved>::_Function_GetAddress;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->_Function_PrivateFindMethod = &Hxx2::Wrapper<Hxx2::Unresolved>::_Function_PrivateFindMethod;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Function_FindAll = &Hxx2::Wrapper<Hxx2::Unresolved>::_Function_FindAll;
			#else
			tbl->_Function_FindAll = &Hxx2::Wrapper<Hxx2::Unresolved>::_Function_FindAll;
			#endif
		#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
			return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
		#else
			return true;
		#endif
		}
		MAXON_INTERFACE_REGISTER(Function, "net.maxon.reflection.interface.function", nullptr);
		template <typename DUMMY> maxon::Int Function::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<Block<const ParameterType>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<ParameterType>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<const Block<const Parameter>&>(OVERLOAD_MAX_RANK)
			;
		}
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_reflectionbase(0
	| maxon::reflection::Member::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::reflection::Container::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::reflection::Package::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::reflection::Class::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::reflection::Function::PrivateInstantiateNullValueHelper<maxon::Int>()
);
