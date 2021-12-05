#if 1
namespace maxon
{
	const maxon::Char* const CustomAllocatorInterface::MTable::_ids = 
		"Free@42e9676dcf312a44\0" // void Free(const CustomAllocatorInterface* object)
		"Alloc@c9a195d00dc7a37b\0" // CustomAllocatorInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@701133d89c8735da\0" // void* Alloc(Int s, const maxon::SourceLocation& allocLocation)
		"AllocClear@701133d89c8735da\0" // void* AllocClear(Int s, const maxon::SourceLocation& allocLocation)
		"Realloc@b38dc399069351f0\0" // void* Realloc(void* data, Int size, const maxon::SourceLocation& allocLocation)
		"PrivateAlloc@e2806e896540b268\0" // void* PrivateAlloc(Int size, Bool clear, const maxon::SourceLocation& allocLocation)
		"PrivateFree@b6e526b3d5167\0" // void PrivateFree(void* data)
		"PrivateGetDataSize@3b7925044762\0" // Int PrivateGetDataSize(void* data)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class CustomAllocatorInterface::Hxx2::Unresolved : public CustomAllocatorInterface
	{
	public:
		static const Unresolved* Get(const CustomAllocatorInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(CustomAllocatorInterface* o) { return (Unresolved*) o; }
		static void Free(const CustomAllocatorInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CustomAllocatorInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static CustomAllocatorInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CustomAllocatorInterface::Alloc(allocLocation); return nullptr;}
		void* Alloc(Int s, const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((CustomAllocatorInterface*) this)->Alloc(s, allocLocation); return nullptr;}
		void* AllocClear(Int s, const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((CustomAllocatorInterface*) this)->AllocClear(s, allocLocation); return nullptr;}
		void* Realloc(void* data, Int size, const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((CustomAllocatorInterface*) this)->Realloc(data, size, allocLocation); return nullptr;}
		void* PrivateAlloc(Int size, Bool clear, const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((CustomAllocatorInterface*) this)->PrivateAlloc(size, clear, allocLocation); return nullptr;}
		void PrivateFree(void* data) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((CustomAllocatorInterface*) this)->PrivateFree(data); return maxon::PrivateLogNullptrError();}
		Int PrivateGetDataSize(void* data) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((CustomAllocatorInterface*) this)->PrivateGetDataSize(data); return 0;}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE CustomAllocatorInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<CustomAllocatorInterface*>::value,
		maxon::details::NullReturnType<void*>::value,
		maxon::details::NullReturnType<void*>::value,
		maxon::details::NullReturnType<void*>::value,
		maxon::details::NullReturnType<void*>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool CustomAllocatorInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CustomAllocatorInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_CustomAllocatorInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CustomAllocatorInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_CustomAllocatorInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CustomAllocatorInterface_Alloc_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_CustomAllocatorInterface_Alloc_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CustomAllocatorInterface_AllocClear = &Hxx2::Wrapper<Hxx2::Unresolved>::_CustomAllocatorInterface_AllocClear;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CustomAllocatorInterface_Realloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_CustomAllocatorInterface_Realloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CustomAllocatorInterface_PrivateAlloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_CustomAllocatorInterface_PrivateAlloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CustomAllocatorInterface_PrivateFree = &Hxx2::Wrapper<Hxx2::Unresolved>::_CustomAllocatorInterface_PrivateFree;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CustomAllocatorInterface_PrivateGetDataSize = &Hxx2::Wrapper<Hxx2::Unresolved>::_CustomAllocatorInterface_PrivateGetDataSize;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(CustomAllocatorInterface, "net.maxon.interface.customallocator", nullptr);
}
#endif
