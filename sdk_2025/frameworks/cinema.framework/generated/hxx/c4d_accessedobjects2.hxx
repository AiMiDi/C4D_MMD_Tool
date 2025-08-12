
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
namespace cinema
{

	struct AccessedObjectsCallback::MTable
	{
		MTable() { }
		template <typename C> explicit MTable(C*) { Init<typename maxon::SFINAEHelper<Hxx2, C>::type::template Wrapper<C>>(); }
		template <typename C> MTable(C*, maxon::Bool) { Init<C>(); }
		PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_AddFlags, AddFlags, false, AccessedObjectsCallback,, (GET_ACCESSED_OBJECTS_FLAGS), GET_ACCESSED_OBJECTS_FLAGS newFlags);
		PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_RestoreFlags, RestoreFlags, false, AccessedObjectsCallback,, (void), GET_ACCESSED_OBJECTS_FLAGS prevFlags);
		PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_TestFlags, TestFlags, false, AccessedObjectsCallback, const, (Bool), GET_ACCESSED_OBJECTS_FLAGS mask);
		PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_MarkVisited, MarkVisited, false, AccessedObjectsCallback,, (maxon::Result<Bool>), const BaseList2D* object);
		PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_IsReadable, IsReadable, false, AccessedObjectsCallback,, (Bool), const BaseList2D* object, ACCESSED_OBJECTS_MASK readMask);
		PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_EnsureReadable, EnsureReadable, false, AccessedObjectsCallback,, (maxon::Result<void>), const BaseList2D* object, ACCESSED_OBJECTS_MASK readMask);
		PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_MayAccess, MayAccess, false, AccessedObjectsCallback,, (maxon::Result<Bool>), const BaseList2D* object, ACCESSED_OBJECTS_MASK readMask, ACCESSED_OBJECTS_MASK writeMask);
		PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_MayAccessAnything, MayAccessAnything, false, AccessedObjectsCallback,, (maxon::Result<Bool>));
		PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_GetDocument, GetDocument, false, AccessedObjectsCallback,, (const BaseDocument*));
		PRIVATE_MAXON_MF_POINTER(AccessedObjectsCallback_GetBuildFlags, GetBuildFlags, false, AccessedObjectsCallback,, (BUILDFLAGS));
		maxon::ClassInfoBase _info;
		template <typename IMPL> void Init()
		{
			void (*free) (const AccessedObjectsCallback*) = &IMPL::Implementation::Free;
			_info._free = reinterpret_cast<void(*)(const void*)>(free);
			_info.PrivateInitName(maxon::details::GetTypeNameHelper<typename IMPL::Implementation>());
			AccessedObjectsCallback_AddFlags = AccessedObjectsCallback_AddFlags_GetPtr<IMPL>(0, true).first;
			AccessedObjectsCallback_RestoreFlags = AccessedObjectsCallback_RestoreFlags_GetPtr<IMPL>(0, true).first;
			AccessedObjectsCallback_TestFlags = AccessedObjectsCallback_TestFlags_GetPtr<IMPL>(0, true).first;
			AccessedObjectsCallback_MarkVisited = AccessedObjectsCallback_MarkVisited_GetPtr<IMPL>(0, true).first;
			AccessedObjectsCallback_IsReadable = AccessedObjectsCallback_IsReadable_GetPtr<IMPL>(0, true).first;
			AccessedObjectsCallback_EnsureReadable = AccessedObjectsCallback_EnsureReadable_GetPtr<IMPL>(0, true).first;
			AccessedObjectsCallback_MayAccess = AccessedObjectsCallback_MayAccess_GetPtr<IMPL>(0, true).first;
			AccessedObjectsCallback_MayAccessAnything = AccessedObjectsCallback_MayAccessAnything_GetPtr<IMPL>(0, true).first;
			AccessedObjectsCallback_GetDocument = AccessedObjectsCallback_GetDocument_GetPtr<IMPL>(0, true).first;
			AccessedObjectsCallback_GetBuildFlags = AccessedObjectsCallback_GetBuildFlags_GetPtr<IMPL>(0, true).first;
		}
		template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset) { return true; }
		template <typename S> using CombinedMTable = S;
	};

	struct AccessedObjectsCallback::Hxx2
	{
		template <typename C> using CWrapper = C;
		template <typename S> class Wrapper
		{
		public:
			using Implementation = S;
			PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_AddFlags, AccessedObjectsCallback,, (GET_ACCESSED_OBJECTS_FLAGS), GET_ACCESSED_OBJECTS_FLAGS newFlags) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->AddFlags(newFlags); }
			PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_RestoreFlags, AccessedObjectsCallback,, (void), GET_ACCESSED_OBJECTS_FLAGS prevFlags) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->RestoreFlags(prevFlags); }
			PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_TestFlags, AccessedObjectsCallback, const, (Bool), GET_ACCESSED_OBJECTS_FLAGS mask) { return S::Get(PRIVATE_MAXON_MF_THIS(const AccessedObjectsCallback))->TestFlags(mask); }
			PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_MarkVisited, AccessedObjectsCallback,, (maxon::Result<Bool>), const BaseList2D* object) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->MarkVisited(object); }
			PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_IsReadable, AccessedObjectsCallback,, (Bool), const BaseList2D* object, ACCESSED_OBJECTS_MASK readMask) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->IsReadable(object, readMask); }
			PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_EnsureReadable, AccessedObjectsCallback,, (maxon::Result<void>), const BaseList2D* object, ACCESSED_OBJECTS_MASK readMask) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->EnsureReadable(object, readMask); }
			PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_MayAccess, AccessedObjectsCallback,, (maxon::Result<Bool>), const BaseList2D* object, ACCESSED_OBJECTS_MASK readMask, ACCESSED_OBJECTS_MASK writeMask) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->MayAccess(object, readMask, writeMask); }
			PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_MayAccessAnything, AccessedObjectsCallback,, (maxon::Result<Bool>)) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->MayAccessAnything(); }
			PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_GetDocument, AccessedObjectsCallback,, (const BaseDocument*)) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->GetDocument(); }
			PRIVATE_MAXON_MF_WRAPPER(AccessedObjectsCallback_GetBuildFlags, AccessedObjectsCallback,, (BUILDFLAGS)) { return S::Get(PRIVATE_MAXON_MF_THIS(AccessedObjectsCallback))->GetBuildFlags(); }
		};

	};
	MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::AddFlags(GET_ACCESSED_OBJECTS_FLAGS newFlags) -> GET_ACCESSED_OBJECTS_FLAGS
	{
		return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_AddFlags, newFlags);
	}
	MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::RestoreFlags(GET_ACCESSED_OBJECTS_FLAGS prevFlags) -> void
	{
		return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_RestoreFlags, prevFlags);
	}
	MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::TestFlags(GET_ACCESSED_OBJECTS_FLAGS mask) const -> Bool
	{
		return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_TestFlags, mask);
	}
	MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::MarkVisited(const BaseList2D* object) -> maxon::Result<Bool>
	{
		return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_MarkVisited, object);
	}
	MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::IsReadable(const BaseList2D* object, ACCESSED_OBJECTS_MASK readMask) -> Bool
	{
		return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_IsReadable, object, readMask);
	}
	MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::EnsureReadable(const BaseList2D* object, ACCESSED_OBJECTS_MASK readMask) -> maxon::Result<void>
	{
		return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_EnsureReadable, object, readMask);
	}
	MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::MayAccess(const BaseList2D* object, ACCESSED_OBJECTS_MASK readMask, ACCESSED_OBJECTS_MASK writeMask) -> maxon::Result<Bool>
	{
		return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_MayAccess, object, readMask, writeMask);
	}
	MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::MayAccessAnything() -> maxon::Result<Bool>
	{
		return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_MayAccessAnything);
	}
	MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::GetDocument() -> const BaseDocument*
	{
		return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_GetDocument);
	}
	MAXON_ATTRIBUTE_FORCE_INLINE auto AccessedObjectsCallback::GetBuildFlags() -> BUILDFLAGS
	{
		return PRIVATE_MAXON_MF_INVOKE((this), ((AccessedObjectsCallback::MTable*) (this->_vtableCls + 1))[-1].AccessedObjectsCallback_GetBuildFlags);
	}

	AccessedObjectsCallback::AccessedObjectsCallback(const MTable& vtable) : _vtableCls(&vtable._info) { }
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

