#if 1
namespace maxon
{
	const maxon::Char* const CustomAllocatorInterface::MTable::_ids = 
		"Free@4036783d90f990b5\0" // void Free(const CustomAllocatorInterface* object)
		"Alloc@51385844f3ffbe36\0" // CustomAllocatorInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@1c15e39418db92db\0" // void* Alloc(Int s, const maxon::SourceLocation& allocLocation)
		"AllocClear@1c15e39418db92db\0" // void* AllocClear(Int s, const maxon::SourceLocation& allocLocation)
		"Realloc@7bb27a5d92734def\0" // void* Realloc(void* data, Int size, const maxon::SourceLocation& allocLocation)
		"PrivateAlloc@11d4de6c1727b585\0" // void* PrivateAlloc(Int size, Bool clear, const maxon::SourceLocation& allocLocation)
		"PrivateFree@3b2dcd824df323e4\0" // void PrivateFree(void* data)
		"PrivateGetDataSize@f0b1de6ca3238f59\0" // Int PrivateGetDataSize(void* data)
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
		tbl->CustomAllocatorInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(CustomAllocatorInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::CustomAllocatorInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CustomAllocatorInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(CustomAllocatorInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::CustomAllocatorInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CustomAllocatorInterface_Alloc_1 = PRIVATE_MAXON_MF_CAST(decltype(CustomAllocatorInterface_Alloc_1), &Hxx2::Wrapper<Hxx2::Unresolved>::CustomAllocatorInterface_Alloc_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CustomAllocatorInterface_AllocClear = PRIVATE_MAXON_MF_CAST(decltype(CustomAllocatorInterface_AllocClear), &Hxx2::Wrapper<Hxx2::Unresolved>::CustomAllocatorInterface_AllocClear);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CustomAllocatorInterface_Realloc = PRIVATE_MAXON_MF_CAST(decltype(CustomAllocatorInterface_Realloc), &Hxx2::Wrapper<Hxx2::Unresolved>::CustomAllocatorInterface_Realloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CustomAllocatorInterface_PrivateAlloc = PRIVATE_MAXON_MF_CAST(decltype(CustomAllocatorInterface_PrivateAlloc), &Hxx2::Wrapper<Hxx2::Unresolved>::CustomAllocatorInterface_PrivateAlloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CustomAllocatorInterface_PrivateFree = PRIVATE_MAXON_MF_CAST(decltype(CustomAllocatorInterface_PrivateFree), &Hxx2::Wrapper<Hxx2::Unresolved>::CustomAllocatorInterface_PrivateFree);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CustomAllocatorInterface_PrivateGetDataSize = PRIVATE_MAXON_MF_CAST(decltype(CustomAllocatorInterface_PrivateGetDataSize), &Hxx2::Wrapper<Hxx2::Unresolved>::CustomAllocatorInterface_PrivateGetDataSize);
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
