#if 1
namespace maxon
{
	namespace reflection
	{
		namespace enum48
		{
			enum class KIND
				{
					PACKAGE = 1,									///< The member is a Package.
					CLASS = 2,										///< The member is a Class.
					FUNCTION = 4,									///< The member is a Function (either at package scope, or a static class member).
					INSTANCE_FUNCTION = 8,				///< The member is a non-const instance function (i.e., non-static class member).
					CONST_INSTANCE_FUNCTION = 16,	///< The member is a const instance function (i.e., non-static class member).
					CONTAINER_TEST = PACKAGE | CLASS,
					FUNCTION_TEST = FUNCTION | INSTANCE_FUNCTION | CONST_INSTANCE_FUNCTION
				} ;
			static const maxon::UInt64 KIND_values[] = {maxon::UInt64(enum48::KIND::PACKAGE), maxon::UInt64(enum48::KIND::CLASS), maxon::UInt64(enum48::KIND::FUNCTION), maxon::UInt64(enum48::KIND::INSTANCE_FUNCTION), maxon::UInt64(enum48::KIND::CONST_INSTANCE_FUNCTION), maxon::UInt64(enum48::KIND::CONTAINER_TEST), maxon::UInt64(enum48::KIND::FUNCTION_TEST)};
			static const maxon::EnumInfo KIND_info{"Member::KIND", SIZEOF(KIND), true, "PACKAGE\0CLASS\0FUNCTION\0INSTANCE_FUNCTION\0CONST_INSTANCE_FUNCTION\0CONTAINER_TEST\0FUNCTION_TEST\0", KIND_values, std::extent<decltype(KIND_values)>::value};
		}
		const maxon::EnumInfo& PrivateGetEnumInfo_KIND48(void*){ return enum48::KIND_info; }
		const maxon::Char* const Member::MTable::_ids = 
		"GetEnclosingContainer@94a412ac1d875bb6\0" // const Container* GetEnclosingContainer() const
		"GetKind@978744d15f2fd32e\0" // KIND GetKind() const
		"GetSimpleName@daec66e7da84a648\0" // const Id& GetSimpleName() const
		"GetId@daec66e7da84a648\0" // const Id& GetId() const
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* fs) const
		"GetMembers@e709bbf708469c6\0" // Result<Bool> GetMembers(const ValueReceiver<const Member&>& members)
		"Find@ed20a4fca0c01fca\0" // const Member* Find(const Id& memberId)
		"";
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_DEPRECATED
		class Member::Hxx2::Unresolved : public Member
		{
		public:
			static const Unresolved* Get(const Member* o) { return (const Unresolved*) o; }
			static Unresolved* Get(Member* o) { return (Unresolved*) o; }
			const Container* GetEnclosingContainer() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Member*) this)->GetEnclosingContainer(); return nullptr;}
			KIND GetKind() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Member*) this)->GetKind(); return HXXRET3(UNRESOLVED, KIND);}
			const Id& GetSimpleName() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Member*) this)->GetSimpleName(); return HXXRET3(UNRESOLVED, const Id&);}
			const Id& GetId() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Member*) this)->GetId(); return HXXRET3(UNRESOLVED, const Id&);}
			String ToString(const FormatStatement* fs) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Member*) this)->ToString(fs); return HXXRET3(UNRESOLVED, String);}
			static Result<Bool> GetMembers(const ValueReceiver<const Member&>& members) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Member::GetMembers(members); return HXXRET1(UNRESOLVED);}
			static const Member* Find(const Id& memberId) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Member::Find(memberId); return nullptr;}
		};
		MAXON_WARNING_POP
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		const maxon::UNRESOLVED_RETURN_TYPE Member::MTable::_returnTypes[] = 
		{
			maxon::details::UnresolvedReturnType<const Container*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<KIND>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<const Id&>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<const Id&>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<String>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<Result<Bool>>::value,
			maxon::details::UnresolvedReturnType<const Member*>::value,
			maxon::UNRESOLVED_RETURN_TYPE::OTHER
		};
	#endif
		maxon::Bool Member::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
		{
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->Member_GetEnclosingContainer = PRIVATE_MAXON_MF_CAST(decltype(Member_GetEnclosingContainer), &Hxx2::Wrapper<Hxx2::Unresolved>::Member_GetEnclosingContainer);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<KIND>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Member_GetKind = PRIVATE_MAXON_MF_CAST(decltype(Member_GetKind), &Hxx2::Wrapper<Hxx2::Unresolved>::Member_GetKind);
			#else
			tbl->Member_GetKind = PRIVATE_MAXON_MF_CAST(decltype(Member_GetKind), &Hxx2::Wrapper<Hxx2::Unresolved>::Member_GetKind);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<const Id&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Member_GetSimpleName = PRIVATE_MAXON_MF_CAST(decltype(Member_GetSimpleName), &Hxx2::Wrapper<Hxx2::Unresolved>::Member_GetSimpleName);
			#else
			tbl->Member_GetSimpleName = PRIVATE_MAXON_MF_CAST(decltype(Member_GetSimpleName), &Hxx2::Wrapper<Hxx2::Unresolved>::Member_GetSimpleName);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<const Id&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Member_GetId = PRIVATE_MAXON_MF_CAST(decltype(Member_GetId), &Hxx2::Wrapper<Hxx2::Unresolved>::Member_GetId);
			#else
			tbl->Member_GetId = PRIVATE_MAXON_MF_CAST(decltype(Member_GetId), &Hxx2::Wrapper<Hxx2::Unresolved>::Member_GetId);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Member_ToString = PRIVATE_MAXON_MF_CAST(decltype(Member_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::Member_ToString);
			#else
			tbl->Member_ToString = PRIVATE_MAXON_MF_CAST(decltype(Member_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::Member_ToString);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<Bool>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Member_GetMembers = PRIVATE_MAXON_MF_CAST(decltype(Member_GetMembers), &Hxx2::Wrapper<Hxx2::Unresolved>::Member_GetMembers);
			#else
			tbl->Member_GetMembers = PRIVATE_MAXON_MF_CAST(decltype(Member_GetMembers), &Hxx2::Wrapper<Hxx2::Unresolved>::Member_GetMembers);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->Member_Find = PRIVATE_MAXON_MF_CAST(decltype(Member_Find), &Hxx2::Wrapper<Hxx2::Unresolved>::Member_Find);
			#endif
		#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
			return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
		#else
			return true;
		#endif
		}
		MAXON_INTERFACE_REGISTER(Member, "net.maxon.reflection.interface.member", nullptr, maxon::EntityBase::FLAGS::NONE);
		template <typename DUMMY> maxon::Int Member::PrivateInstantiateDefaultValueHelper()
		{
			return 0
			| maxon::details::InstantiateDefaultReturnValue<KIND>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateDefaultReturnValue<const Id&>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const Container::MTable::_ids = 
		"GetClasses@ee35fb5f10af1f7e\0" // Block<const Class* const> GetClasses() const
		"FindClass@e4836772479d1316\0" // const Class* FindClass(const Id& name) const
		"GetFunctions@92bbb8c881d53a60\0" // Block<const Function* const> GetFunctions() const
		"FindFunction@c107f8282867162f\0" // Result<const Function*> FindFunction(const Id& name) const
		"FindFunctions@268def0636cf1062\0" // Result<void> FindFunctions(const Id& name, const ValueReceiver<const Function*>& result) const
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
			Block<const Class* const> GetClasses() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Container*) this)->GetClasses(); return HXXRET3(UNRESOLVED, Block<const Class* const>);}
			const Class* FindClass(const Id& name) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Container*) this)->FindClass(name); return nullptr;}
			Block<const Function* const> GetFunctions() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Container*) this)->GetFunctions(); return HXXRET3(UNRESOLVED, Block<const Function* const>);}
			Result<const Function*> FindFunction(const Id& name) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const Container*) this)->FindFunction(name); return HXXRET1(UNRESOLVED);}
			Result<void> FindFunctions(const Id& name, const ValueReceiver<const Function*>& result) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const Container*) this)->FindFunctions(name, result); return HXXRET1(UNRESOLVED);}
		};
		MAXON_WARNING_POP
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		const maxon::UNRESOLVED_RETURN_TYPE Container::MTable::_returnTypes[] = 
		{
			maxon::details::UnresolvedReturnType<Block<const Class* const>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<const Class*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<Block<const Function* const>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<Result<const Function*>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::UNRESOLVED_RETURN_TYPE::OTHER
		};
	#endif
		maxon::Bool Container::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
		{
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Block<const Class* const>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Container_GetClasses = PRIVATE_MAXON_MF_CAST(decltype(Container_GetClasses), &Hxx2::Wrapper<Hxx2::Unresolved>::Container_GetClasses);
			#else
			tbl->Container_GetClasses = PRIVATE_MAXON_MF_CAST(decltype(Container_GetClasses), &Hxx2::Wrapper<Hxx2::Unresolved>::Container_GetClasses);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->Container_FindClass = PRIVATE_MAXON_MF_CAST(decltype(Container_FindClass), &Hxx2::Wrapper<Hxx2::Unresolved>::Container_FindClass);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Block<const Function* const>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Container_GetFunctions = PRIVATE_MAXON_MF_CAST(decltype(Container_GetFunctions), &Hxx2::Wrapper<Hxx2::Unresolved>::Container_GetFunctions);
			#else
			tbl->Container_GetFunctions = PRIVATE_MAXON_MF_CAST(decltype(Container_GetFunctions), &Hxx2::Wrapper<Hxx2::Unresolved>::Container_GetFunctions);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<const Function*>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Container_FindFunction = PRIVATE_MAXON_MF_CAST(decltype(Container_FindFunction), &Hxx2::Wrapper<Hxx2::Unresolved>::Container_FindFunction);
			#else
			tbl->Container_FindFunction = PRIVATE_MAXON_MF_CAST(decltype(Container_FindFunction), &Hxx2::Wrapper<Hxx2::Unresolved>::Container_FindFunction);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Container_FindFunctions = PRIVATE_MAXON_MF_CAST(decltype(Container_FindFunctions), &Hxx2::Wrapper<Hxx2::Unresolved>::Container_FindFunctions);
			#else
			tbl->Container_FindFunctions = PRIVATE_MAXON_MF_CAST(decltype(Container_FindFunctions), &Hxx2::Wrapper<Hxx2::Unresolved>::Container_FindFunctions);
			#endif
		#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
			return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
		#else
			return true;
		#endif
		}
		MAXON_INTERFACE_REGISTER(Container, "net.maxon.reflection.interface.container", nullptr, maxon::EntityBase::FLAGS::NONE);
		template <typename DUMMY> maxon::Int Container::PrivateInstantiateDefaultValueHelper()
		{
			return 0
			| maxon::details::InstantiateDefaultReturnValue<Block<const Class* const>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateDefaultReturnValue<Block<const Function* const>>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const Package::MTable::_ids = 
		"GetPackages@3cfe86ac33c35ef9\0" // Block<const Package* const> GetPackages() const
		"FindPackage@9b7f78d05195b507\0" // const Package* FindPackage(const Id& name) const
		"GetGlobalPackage@5e6db0227bd6525c\0" // const Package* GetGlobalPackage()
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
			Block<const Package* const> GetPackages() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Package*) this)->GetPackages(); return HXXRET3(UNRESOLVED, Block<const Package* const>);}
			const Package* FindPackage(const Id& name) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Package*) this)->FindPackage(name); return nullptr;}
			static const Package* GetGlobalPackage() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Package::GetGlobalPackage(); return nullptr;}
		};
		MAXON_WARNING_POP
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		const maxon::UNRESOLVED_RETURN_TYPE Package::MTable::_returnTypes[] = 
		{
			maxon::details::UnresolvedReturnType<Block<const Package* const>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<const Package*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<const Package*>::value,
			maxon::UNRESOLVED_RETURN_TYPE::OTHER
		};
	#endif
		maxon::Bool Package::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
		{
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Block<const Package* const>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Package_GetPackages = PRIVATE_MAXON_MF_CAST(decltype(Package_GetPackages), &Hxx2::Wrapper<Hxx2::Unresolved>::Package_GetPackages);
			#else
			tbl->Package_GetPackages = PRIVATE_MAXON_MF_CAST(decltype(Package_GetPackages), &Hxx2::Wrapper<Hxx2::Unresolved>::Package_GetPackages);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->Package_FindPackage = PRIVATE_MAXON_MF_CAST(decltype(Package_FindPackage), &Hxx2::Wrapper<Hxx2::Unresolved>::Package_FindPackage);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->Package_GetGlobalPackage = PRIVATE_MAXON_MF_CAST(decltype(Package_GetGlobalPackage), &Hxx2::Wrapper<Hxx2::Unresolved>::Package_GetGlobalPackage);
			#endif
		#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
			return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
		#else
			return true;
		#endif
		}
		MAXON_INTERFACE_REGISTER(Package, "net.maxon.reflection.interface.package", nullptr, maxon::EntityBase::FLAGS::NONE);
		template <typename DUMMY> maxon::Int Package::PrivateInstantiateDefaultValueHelper()
		{
			return 0
			| maxon::details::InstantiateDefaultReturnValue<Block<const Package* const>>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const Class::MTable::_ids = 
		"GetInterface@758610fce433caef\0" // const InterfaceReference* GetInterface() const
		"GetNonvirtualInterface@e99ed77681752875\0" // const NonvirtualInterfaceReference* GetNonvirtualInterface() const
		"GetBaseClasses@f966e9a746774f0d\0" // Block<const Class* const> GetBaseClasses() const
		"GetStaticInterface@b8cdd53eff98d847\0" // const Class* GetStaticInterface() const
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
			Block<const Class* const> GetBaseClasses() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Class*) this)->GetBaseClasses(); return HXXRET3(UNRESOLVED, Block<const Class* const>);}
			const Class* GetStaticInterface() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Class*) this)->GetStaticInterface(); return nullptr;}
		};
		MAXON_WARNING_POP
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		const maxon::UNRESOLVED_RETURN_TYPE Class::MTable::_returnTypes[] = 
		{
			maxon::details::UnresolvedReturnType<const InterfaceReference*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<const NonvirtualInterfaceReference*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<Block<const Class* const>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<const Class*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::UNRESOLVED_RETURN_TYPE::OTHER
		};
	#endif
		maxon::Bool Class::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
		{
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->Class_GetInterface = PRIVATE_MAXON_MF_CAST(decltype(Class_GetInterface), &Hxx2::Wrapper<Hxx2::Unresolved>::Class_GetInterface);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->Class_GetNonvirtualInterface = PRIVATE_MAXON_MF_CAST(decltype(Class_GetNonvirtualInterface), &Hxx2::Wrapper<Hxx2::Unresolved>::Class_GetNonvirtualInterface);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Block<const Class* const>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Class_GetBaseClasses = PRIVATE_MAXON_MF_CAST(decltype(Class_GetBaseClasses), &Hxx2::Wrapper<Hxx2::Unresolved>::Class_GetBaseClasses);
			#else
			tbl->Class_GetBaseClasses = PRIVATE_MAXON_MF_CAST(decltype(Class_GetBaseClasses), &Hxx2::Wrapper<Hxx2::Unresolved>::Class_GetBaseClasses);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->Class_GetStaticInterface = PRIVATE_MAXON_MF_CAST(decltype(Class_GetStaticInterface), &Hxx2::Wrapper<Hxx2::Unresolved>::Class_GetStaticInterface);
			#endif
		#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
			return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
		#else
			return true;
		#endif
		}
		MAXON_INTERFACE_REGISTER(Class, "net.maxon.reflection.interface.class", nullptr, maxon::EntityBase::FLAGS::NONE);
		template <typename DUMMY> maxon::Int Class::PrivateInstantiateDefaultValueHelper()
		{
			return 0
			| maxon::details::InstantiateDefaultReturnValue<Block<const Class* const>>(OVERLOAD_MAX_RANK)
			;
		}
		const maxon::Char* const Function::MTable::_ids = 
		"Invoke@299683ed150e3a8e\0" // Result<void> Invoke(void* result, const Block<Argument>& arguments) const
		"GetReturnType@ba4e4cb8edfd84e9\0" // ParameterType GetReturnType() const
		"GetParameterTypes@cb9d2648b66741f5\0" // Block<const ParameterType> GetParameterTypes() const
		"GetParameters@d9bc1b49fa73936a\0" // const Block<const Parameter>& GetParameters() const
		"IsPure@561ffe16ba15d902\0" // Bool IsPure() const
		"GetAddress@c9298143b407dfd4\0" // void* GetAddress() const
		"PrivateFindMethod@dc2df995d1c671b2\0" // const Function* PrivateFindMethod(const InterfaceReference& vi, Int offset)
		"FindAll@cc8f83c3fd6392ac\0" // Result<void> FindAll(const Id& memberId, const ValueReceiver<const Function*>& result)
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
			Result<void> Invoke(void* result, const Block<Argument>& arguments) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const Function*) this)->Invoke(result, arguments); return HXXRET1(UNRESOLVED);}
			ParameterType GetReturnType() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Function*) this)->GetReturnType(); return HXXRET3(UNRESOLVED, ParameterType);}
			Block<const ParameterType> GetParameterTypes() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Function*) this)->GetParameterTypes(); return HXXRET3(UNRESOLVED, Block<const ParameterType>);}
			const Block<const Parameter>& GetParameters() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Function*) this)->GetParameters(); return HXXRET3(UNRESOLVED, const Block<const Parameter>&);}
			Bool IsPure() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Function*) this)->IsPure(); return maxon::PrivateLogNullptrError(false);}
			void* GetAddress() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const Function*) this)->GetAddress(); return nullptr;}
			static const Function* PrivateFindMethod(const InterfaceReference& vi, Int offset) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Function::PrivateFindMethod(vi, offset); return nullptr;}
			static Result<void> FindAll(const Id& memberId, const ValueReceiver<const Function*>& result) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Function::FindAll(memberId, result); return HXXRET1(UNRESOLVED);}
		};
		MAXON_WARNING_POP
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		const maxon::UNRESOLVED_RETURN_TYPE Function::MTable::_returnTypes[] = 
		{
			maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<ParameterType>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<Block<const ParameterType>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<const Block<const Parameter>&>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<void*>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
			maxon::details::UnresolvedReturnType<const Function*>::value,
			maxon::details::UnresolvedReturnType<Result<void>>::value,
			maxon::UNRESOLVED_RETURN_TYPE::OTHER
		};
	#endif
		maxon::Bool Function::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
		{
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Function_Invoke = PRIVATE_MAXON_MF_CAST(decltype(Function_Invoke), &Hxx2::Wrapper<Hxx2::Unresolved>::Function_Invoke);
			#else
			tbl->Function_Invoke = PRIVATE_MAXON_MF_CAST(decltype(Function_Invoke), &Hxx2::Wrapper<Hxx2::Unresolved>::Function_Invoke);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<ParameterType>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Function_GetReturnType = PRIVATE_MAXON_MF_CAST(decltype(Function_GetReturnType), &Hxx2::Wrapper<Hxx2::Unresolved>::Function_GetReturnType);
			#else
			tbl->Function_GetReturnType = PRIVATE_MAXON_MF_CAST(decltype(Function_GetReturnType), &Hxx2::Wrapper<Hxx2::Unresolved>::Function_GetReturnType);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Block<const ParameterType>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Function_GetParameterTypes = PRIVATE_MAXON_MF_CAST(decltype(Function_GetParameterTypes), &Hxx2::Wrapper<Hxx2::Unresolved>::Function_GetParameterTypes);
			#else
			tbl->Function_GetParameterTypes = PRIVATE_MAXON_MF_CAST(decltype(Function_GetParameterTypes), &Hxx2::Wrapper<Hxx2::Unresolved>::Function_GetParameterTypes);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<const Block<const Parameter>&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Function_GetParameters = PRIVATE_MAXON_MF_CAST(decltype(Function_GetParameters), &Hxx2::Wrapper<Hxx2::Unresolved>::Function_GetParameters);
			#else
			tbl->Function_GetParameters = PRIVATE_MAXON_MF_CAST(decltype(Function_GetParameters), &Hxx2::Wrapper<Hxx2::Unresolved>::Function_GetParameters);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->Function_IsPure = PRIVATE_MAXON_MF_CAST(decltype(Function_IsPure), &Hxx2::Wrapper<Hxx2::Unresolved>::Function_IsPure);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->Function_GetAddress = PRIVATE_MAXON_MF_CAST(decltype(Function_GetAddress), &Hxx2::Wrapper<Hxx2::Unresolved>::Function_GetAddress);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			#else
			tbl->Function_PrivateFindMethod = PRIVATE_MAXON_MF_CAST(decltype(Function_PrivateFindMethod), &Hxx2::Wrapper<Hxx2::Unresolved>::Function_PrivateFindMethod);
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Function_FindAll = PRIVATE_MAXON_MF_CAST(decltype(Function_FindAll), &Hxx2::Wrapper<Hxx2::Unresolved>::Function_FindAll);
			#else
			tbl->Function_FindAll = PRIVATE_MAXON_MF_CAST(decltype(Function_FindAll), &Hxx2::Wrapper<Hxx2::Unresolved>::Function_FindAll);
			#endif
		#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
			return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
		#else
			return true;
		#endif
		}
		MAXON_INTERFACE_REGISTER(Function, "net.maxon.reflection.interface.function", nullptr, maxon::EntityBase::FLAGS::NONE);
		template <typename DUMMY> maxon::Int Function::PrivateInstantiateDefaultValueHelper()
		{
			return 0
			| maxon::details::InstantiateDefaultReturnValue<Block<const ParameterType>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateDefaultReturnValue<ParameterType>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateDefaultReturnValue<const Block<const Parameter>&>(OVERLOAD_MAX_RANK)
			;
		}
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_reflectionbase(0
	| maxon::reflection::Member::PrivateInstantiateDefaultValueHelper<maxon::Int>()
	| maxon::reflection::Container::PrivateInstantiateDefaultValueHelper<maxon::Int>()
	| maxon::reflection::Package::PrivateInstantiateDefaultValueHelper<maxon::Int>()
	| maxon::reflection::Class::PrivateInstantiateDefaultValueHelper<maxon::Int>()
	| maxon::reflection::Function::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
