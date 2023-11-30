
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct HierarchyObjectInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FindNextLeaf);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FlushBranches);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBranchId);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBranches);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChildAt);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChildren);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetFirst);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetFirstChild);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLast);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLastChild);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetNext);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetParent);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetParentPtr);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetPrev);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InsertAfter);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InsertAsChildAt);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InsertAsFirstChildOf);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InsertAsLastChildOf);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InsertBefore);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InsertChildAsFirst);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InsertChildAsLast);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InsertChildAt);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InsertChildrenAsFirst);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InsertChildrenAsLast);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(InsertChildrenAt);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsLocked);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableHierarchyInsert);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ObservableHierarchyRemove);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ParentChanged);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Remove);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RemoveAllChildren);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RemoveChildren);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Replace);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetLocking);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_InsertBefore, InsertBefore, true, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Sibling<Interface>::type& nextSibling);
	maxon::Int HierarchyObjectInterface_InsertBefore_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_InsertAfter, InsertAfter, true, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Sibling<Interface>::type& prevSibling);
	maxon::Int HierarchyObjectInterface_InsertAfter_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_InsertAsFirstChildOf, InsertAsFirstChildOf, true, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertAsFirstChildOf_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_InsertAsLastChildOf, InsertAsLastChildOf, true, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertAsLastChildOf_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_InsertAsChildAt, InsertAsChildAt, true, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertAsChildAt_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_InsertChildAsFirst, InsertChildAsFirst, true, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertChildAsFirst_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_InsertChildAsLast, InsertChildAsLast, true, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertChildAsLast_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_InsertChildAt, InsertChildAt, true, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertChildAt_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_InsertChildrenAsFirst, InsertChildrenAsFirst, true, maxon::GenericComponent,, (Result<void>), const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertChildrenAsFirst_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_InsertChildrenAsLast, InsertChildrenAsLast, true, maxon::GenericComponent,, (Result<void>), const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertChildrenAsLast_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_InsertChildrenAt, InsertChildrenAt, true, maxon::GenericComponent,, (Result<void>), const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertChildrenAt_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_Replace, Replace, true, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Sibling<Interface>::type& newObject);
	maxon::Int HierarchyObjectInterface_Replace_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_Remove, Remove, true, maxon::GenericComponent,, (HierarchyObjectRef<>));
	maxon::Int HierarchyObjectInterface_Remove_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_RemoveChildren, RemoveChildren, true, maxon::GenericComponent,, (typename HIERARCHY::template Child<Interface>::type), const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_RemoveChildren_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_RemoveAllChildren, RemoveAllChildren, true, maxon::GenericComponent,, (void));
	maxon::Int HierarchyObjectInterface_RemoveAllChildren_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_GetFirstChild, GetFirstChild, true, maxon::GenericComponent, const, (typename HIERARCHY::template Child<Interface>::type), const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_GetFirstChild_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_GetLastChild, GetLastChild, true, maxon::GenericComponent, const, (typename HIERARCHY::template Child<Interface>::type), const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_GetLastChild_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_GetChildAt, GetChildAt, true, maxon::GenericComponent, const, (typename HIERARCHY::template Child<Interface>::type), Int position, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_GetChildAt_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_GetChildren, GetChildren, true, maxon::GenericComponent, const, (Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>>), const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_GetChildren_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_GetBranches, GetBranches, true, maxon::GenericComponent, const, (Result<BaseArray<ConstDataPtr>>));
	maxon::Int HierarchyObjectInterface_GetBranches_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_GetBranchId, GetBranchId, true, maxon::GenericComponent, const, (ConstDataPtr));
	maxon::Int HierarchyObjectInterface_GetBranchId_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_SetLocking, SetLocking, true, maxon::GenericComponent,, (void), const Bool locking);
	maxon::Int HierarchyObjectInterface_SetLocking_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_IsLocked, IsLocked, true, maxon::GenericComponent, const, (Bool));
	maxon::Int HierarchyObjectInterface_IsLocked_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_GetParent, GetParent, true, maxon::GenericComponent, const, (typename HIERARCHY::template Parent<Interface>::type));
	maxon::Int HierarchyObjectInterface_GetParent_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_GetParentPtr, GetParentPtr, true, maxon::GenericComponent, const, (std::add_pointer<HierarchyObjectInterface>::type));
	maxon::Int HierarchyObjectInterface_GetParentPtr_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_GetNext, GetNext, true, maxon::GenericComponent, const, (typename HIERARCHY::template Sibling<Interface>::type));
	maxon::Int HierarchyObjectInterface_GetNext_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_GetPrev, GetPrev, true, maxon::GenericComponent, const, (typename HIERARCHY::template Sibling<Interface>::type));
	maxon::Int HierarchyObjectInterface_GetPrev_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_GetFirst, GetFirst, true, maxon::GenericComponent, const, (typename HIERARCHY::template Sibling<Interface>::type));
	maxon::Int HierarchyObjectInterface_GetFirst_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_GetLast, GetLast, true, maxon::GenericComponent, const, (typename HIERARCHY::template Sibling<Interface>::type));
	maxon::Int HierarchyObjectInterface_GetLast_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_ParentChanged, ParentChanged, true, maxon::GenericComponent,, (void), Bool removed);
	maxon::Int HierarchyObjectInterface_ParentChanged_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_FindNextLeaf, FindNextLeaf, true, maxon::GenericComponent, const, (std::add_pointer<HierarchyObjectInterface>::type), const HierarchyObjectInterface* stopAtParent);
	maxon::Int HierarchyObjectInterface_FindNextLeaf_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_ObservableHierarchyInsert, ObservableHierarchyInsert, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableHierarchyInsertDelegate>), Bool create);
	maxon::Int HierarchyObjectInterface_ObservableHierarchyInsert_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_ObservableHierarchyRemove, ObservableHierarchyRemove, true, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableHierarchyRemoveDelegate>), Bool create);
	maxon::Int HierarchyObjectInterface_ObservableHierarchyRemove_Offset;
	PRIVATE_MAXON_MF_POINTER(HierarchyObjectInterface_FlushBranches, FlushBranches, true, maxon::GenericComponent,, (void));
	maxon::Int HierarchyObjectInterface_FlushBranches_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertBefore))
	{
		maxon::Tie(HierarchyObjectInterface_InsertBefore, HierarchyObjectInterface_InsertBefore_Offset) = HierarchyObjectInterface_InsertBefore_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAfter))
	{
		maxon::Tie(HierarchyObjectInterface_InsertAfter, HierarchyObjectInterface_InsertAfter_Offset) = HierarchyObjectInterface_InsertAfter_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAsFirstChildOf))
	{
		maxon::Tie(HierarchyObjectInterface_InsertAsFirstChildOf, HierarchyObjectInterface_InsertAsFirstChildOf_Offset) = HierarchyObjectInterface_InsertAsFirstChildOf_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAsLastChildOf))
	{
		maxon::Tie(HierarchyObjectInterface_InsertAsLastChildOf, HierarchyObjectInterface_InsertAsLastChildOf_Offset) = HierarchyObjectInterface_InsertAsLastChildOf_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAsChildAt))
	{
		maxon::Tie(HierarchyObjectInterface_InsertAsChildAt, HierarchyObjectInterface_InsertAsChildAt_Offset) = HierarchyObjectInterface_InsertAsChildAt_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildAsFirst))
	{
		maxon::Tie(HierarchyObjectInterface_InsertChildAsFirst, HierarchyObjectInterface_InsertChildAsFirst_Offset) = HierarchyObjectInterface_InsertChildAsFirst_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildAsLast))
	{
		maxon::Tie(HierarchyObjectInterface_InsertChildAsLast, HierarchyObjectInterface_InsertChildAsLast_Offset) = HierarchyObjectInterface_InsertChildAsLast_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildAt))
	{
		maxon::Tie(HierarchyObjectInterface_InsertChildAt, HierarchyObjectInterface_InsertChildAt_Offset) = HierarchyObjectInterface_InsertChildAt_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildrenAsFirst))
	{
		maxon::Tie(HierarchyObjectInterface_InsertChildrenAsFirst, HierarchyObjectInterface_InsertChildrenAsFirst_Offset) = HierarchyObjectInterface_InsertChildrenAsFirst_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildrenAsLast))
	{
		maxon::Tie(HierarchyObjectInterface_InsertChildrenAsLast, HierarchyObjectInterface_InsertChildrenAsLast_Offset) = HierarchyObjectInterface_InsertChildrenAsLast_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildrenAt))
	{
		maxon::Tie(HierarchyObjectInterface_InsertChildrenAt, HierarchyObjectInterface_InsertChildrenAt_Offset) = HierarchyObjectInterface_InsertChildrenAt_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, Replace))
	{
		maxon::Tie(HierarchyObjectInterface_Replace, HierarchyObjectInterface_Replace_Offset) = HierarchyObjectInterface_Replace_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, Remove))
	{
		maxon::Tie(HierarchyObjectInterface_Remove, HierarchyObjectInterface_Remove_Offset) = HierarchyObjectInterface_Remove_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, RemoveChildren))
	{
		maxon::Tie(HierarchyObjectInterface_RemoveChildren, HierarchyObjectInterface_RemoveChildren_Offset) = HierarchyObjectInterface_RemoveChildren_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, RemoveAllChildren))
	{
		maxon::Tie(HierarchyObjectInterface_RemoveAllChildren, HierarchyObjectInterface_RemoveAllChildren_Offset) = HierarchyObjectInterface_RemoveAllChildren_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetFirstChild))
	{
		maxon::Tie(HierarchyObjectInterface_GetFirstChild, HierarchyObjectInterface_GetFirstChild_Offset) = HierarchyObjectInterface_GetFirstChild_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetLastChild))
	{
		maxon::Tie(HierarchyObjectInterface_GetLastChild, HierarchyObjectInterface_GetLastChild_Offset) = HierarchyObjectInterface_GetLastChild_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetChildAt))
	{
		maxon::Tie(HierarchyObjectInterface_GetChildAt, HierarchyObjectInterface_GetChildAt_Offset) = HierarchyObjectInterface_GetChildAt_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetChildren))
	{
		maxon::Tie(HierarchyObjectInterface_GetChildren, HierarchyObjectInterface_GetChildren_Offset) = HierarchyObjectInterface_GetChildren_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetBranches))
	{
		maxon::Tie(HierarchyObjectInterface_GetBranches, HierarchyObjectInterface_GetBranches_Offset) = HierarchyObjectInterface_GetBranches_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetBranchId))
	{
		maxon::Tie(HierarchyObjectInterface_GetBranchId, HierarchyObjectInterface_GetBranchId_Offset) = HierarchyObjectInterface_GetBranchId_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, SetLocking))
	{
		maxon::Tie(HierarchyObjectInterface_SetLocking, HierarchyObjectInterface_SetLocking_Offset) = HierarchyObjectInterface_SetLocking_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, IsLocked))
	{
		maxon::Tie(HierarchyObjectInterface_IsLocked, HierarchyObjectInterface_IsLocked_Offset) = HierarchyObjectInterface_IsLocked_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetParent))
	{
		maxon::Tie(HierarchyObjectInterface_GetParent, HierarchyObjectInterface_GetParent_Offset) = HierarchyObjectInterface_GetParent_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetParentPtr))
	{
		maxon::Tie(HierarchyObjectInterface_GetParentPtr, HierarchyObjectInterface_GetParentPtr_Offset) = HierarchyObjectInterface_GetParentPtr_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetNext))
	{
		maxon::Tie(HierarchyObjectInterface_GetNext, HierarchyObjectInterface_GetNext_Offset) = HierarchyObjectInterface_GetNext_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetPrev))
	{
		maxon::Tie(HierarchyObjectInterface_GetPrev, HierarchyObjectInterface_GetPrev_Offset) = HierarchyObjectInterface_GetPrev_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetFirst))
	{
		maxon::Tie(HierarchyObjectInterface_GetFirst, HierarchyObjectInterface_GetFirst_Offset) = HierarchyObjectInterface_GetFirst_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetLast))
	{
		maxon::Tie(HierarchyObjectInterface_GetLast, HierarchyObjectInterface_GetLast_Offset) = HierarchyObjectInterface_GetLast_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, ParentChanged))
	{
		maxon::Tie(HierarchyObjectInterface_ParentChanged, HierarchyObjectInterface_ParentChanged_Offset) = HierarchyObjectInterface_ParentChanged_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, FindNextLeaf))
	{
		maxon::Tie(HierarchyObjectInterface_FindNextLeaf, HierarchyObjectInterface_FindNextLeaf_Offset) = HierarchyObjectInterface_FindNextLeaf_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, ObservableHierarchyInsert))
	{
		maxon::Tie(HierarchyObjectInterface_ObservableHierarchyInsert, HierarchyObjectInterface_ObservableHierarchyInsert_Offset) = HierarchyObjectInterface_ObservableHierarchyInsert_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, ObservableHierarchyRemove))
	{
		maxon::Tie(HierarchyObjectInterface_ObservableHierarchyRemove, HierarchyObjectInterface_ObservableHierarchyRemove_Offset) = HierarchyObjectInterface_ObservableHierarchyRemove_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, FlushBranches))
	{
		maxon::Tie(HierarchyObjectInterface_FlushBranches, HierarchyObjectInterface_FlushBranches_Offset) = HierarchyObjectInterface_FlushBranches_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<HierarchyObjectInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<HierarchyObjectInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct HierarchyObjectInterface::Hxx2
{
	template <typename S> class CWrapper : public ObserverObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FindNextLeaf);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FlushBranches);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBranchId);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBranches);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChildAt);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChildren);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFirst);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFirstChild);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLast);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLastChild);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetNext);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetParent);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetParentPtr);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetPrev);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InsertAfter);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InsertAsChildAt);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InsertAsFirstChildOf);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InsertAsLastChildOf);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InsertBefore);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InsertChildAsFirst);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InsertChildAsLast);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InsertChildAt);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InsertChildrenAsFirst);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InsertChildrenAsLast);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(InsertChildrenAt);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsLocked);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableHierarchyInsert);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ObservableHierarchyRemove);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ParentChanged);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Remove);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RemoveAllChildren);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RemoveChildren);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Replace);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetLocking);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObserverObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (HierarchyObjectInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, HierarchyObjectInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_InsertBefore, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Sibling<Interface>::type& nextSibling) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InsertBefore(nextSibling); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_InsertAfter, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Sibling<Interface>::type& prevSibling) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InsertAfter(prevSibling); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_InsertAsFirstChildOf, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InsertAsFirstChildOf(parent, branchId); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_InsertAsLastChildOf, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InsertAsLastChildOf(parent, branchId); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_InsertAsChildAt, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InsertAsChildAt(parent, position, branchId); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_InsertChildAsFirst, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InsertChildAsFirst(child, branchId); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_InsertChildAsLast, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InsertChildAsLast(child, branchId); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_InsertChildAt, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InsertChildAt(child, position, branchId); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_InsertChildrenAsFirst, maxon::GenericComponent,, (Result<void>), const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InsertChildrenAsFirst(children, branchId); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_InsertChildrenAsLast, maxon::GenericComponent,, (Result<void>), const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InsertChildrenAsLast(children, branchId); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_InsertChildrenAt, maxon::GenericComponent,, (Result<void>), const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->InsertChildrenAt(children, position, branchId); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_Replace, maxon::GenericComponent,, (Result<void>), const typename HIERARCHY::template Sibling<Interface>::type& newObject) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Replace(newObject); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_Remove, maxon::GenericComponent,, (HierarchyObjectRef<>)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Remove(); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_RemoveChildren, maxon::GenericComponent,, (typename HIERARCHY::template Child<Interface>::type), const ConstDataPtr& branchId) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->RemoveChildren(branchId); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_RemoveAllChildren, maxon::GenericComponent,, (void)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->RemoveAllChildren(); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_GetFirstChild, maxon::GenericComponent, const, (typename HIERARCHY::template Child<Interface>::type), const ConstDataPtr& branchId) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetFirstChild(branchId); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_GetLastChild, maxon::GenericComponent, const, (typename HIERARCHY::template Child<Interface>::type), const ConstDataPtr& branchId) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetLastChild(branchId); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_GetChildAt, maxon::GenericComponent, const, (typename HIERARCHY::template Child<Interface>::type), Int position, const ConstDataPtr& branchId) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetChildAt(position, branchId); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_GetChildren, maxon::GenericComponent, const, (Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>>), const ConstDataPtr& branchId) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetChildren(branchId); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_GetBranches, maxon::GenericComponent, const, (Result<BaseArray<ConstDataPtr>>)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetBranches(); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_GetBranchId, maxon::GenericComponent, const, (ConstDataPtr)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetBranchId(); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_SetLocking, maxon::GenericComponent,, (void), const Bool locking) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->SetLocking(locking); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_IsLocked, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IsLocked(); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_GetParent, maxon::GenericComponent, const, (typename HIERARCHY::template Parent<Interface>::type)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetParent(); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_GetParentPtr, maxon::GenericComponent, const, (std::add_pointer<HierarchyObjectInterface>::type)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetParentPtr(); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_GetNext, maxon::GenericComponent, const, (typename HIERARCHY::template Sibling<Interface>::type)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetNext(); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_GetPrev, maxon::GenericComponent, const, (typename HIERARCHY::template Sibling<Interface>::type)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetPrev(); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_GetFirst, maxon::GenericComponent, const, (typename HIERARCHY::template Sibling<Interface>::type)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetFirst(); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_GetLast, maxon::GenericComponent, const, (typename HIERARCHY::template Sibling<Interface>::type)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetLast(); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_ParentChanged, maxon::GenericComponent,, (void), Bool removed) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->ParentChanged(removed); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_FindNextLeaf, maxon::GenericComponent, const, (std::add_pointer<HierarchyObjectInterface>::type), const HierarchyObjectInterface* stopAtParent) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->FindNextLeaf(stopAtParent); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_ObservableHierarchyInsert, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableHierarchyInsertDelegate>), Bool create) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableHierarchyInsert(create); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_ObservableHierarchyRemove, maxon::GenericComponent, const, (maxon::ObservableRef<ObservableHierarchyRemoveDelegate>), Bool create) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ObservableHierarchyRemove(create); }
		PRIVATE_MAXON_MF_WRAPPER(HierarchyObjectInterface_FlushBranches, maxon::GenericComponent,, (void)) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->FlushBranches(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertBefore(const typename HIERARCHY::template Sibling<Interface>::type& nextSibling) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertBefore_Offset), mt_.HierarchyObjectInterface_InsertBefore, nextSibling);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertAfter(const typename HIERARCHY::template Sibling<Interface>::type& prevSibling) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertAfter_Offset), mt_.HierarchyObjectInterface_InsertAfter, prevSibling);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertAsFirstChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertAsFirstChildOf_Offset), mt_.HierarchyObjectInterface_InsertAsFirstChildOf, parent, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertAsLastChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertAsLastChildOf_Offset), mt_.HierarchyObjectInterface_InsertAsLastChildOf, parent, branchId);
}
[[deprecated("Use InsertChildAt")]] MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertAsChildAt(const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertAsChildAt_Offset), mt_.HierarchyObjectInterface_InsertAsChildAt, parent, position, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildAsFirst(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertChildAsFirst_Offset), mt_.HierarchyObjectInterface_InsertChildAsFirst, child, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildAsLast(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertChildAsLast_Offset), mt_.HierarchyObjectInterface_InsertChildAsLast, child, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildAt(const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertChildAt_Offset), mt_.HierarchyObjectInterface_InsertChildAt, child, position, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildrenAsFirst(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertChildrenAsFirst_Offset), mt_.HierarchyObjectInterface_InsertChildrenAsFirst, children, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildrenAsLast(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertChildrenAsLast_Offset), mt_.HierarchyObjectInterface_InsertChildrenAsLast, children, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildrenAt(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertChildrenAt_Offset), mt_.HierarchyObjectInterface_InsertChildrenAt, children, position, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Replace(const typename HIERARCHY::template Sibling<Interface>::type& newObject) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_Replace_Offset), mt_.HierarchyObjectInterface_Replace, newObject);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Remove() -> HierarchyObjectRef<>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_Remove_Offset), mt_.HierarchyObjectInterface_Remove);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::RemoveChildren(const ConstDataPtr& branchId) -> typename HIERARCHY::template Child<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_RemoveChildren_Offset), mt_.HierarchyObjectInterface_RemoveChildren, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::RemoveAllChildren() -> void
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_RemoveAllChildren_Offset), mt_.HierarchyObjectInterface_RemoveAllChildren);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetFirstChild(const ConstDataPtr& branchId) const -> typename HIERARCHY::template Child<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetFirstChild_Offset), mt_.HierarchyObjectInterface_GetFirstChild, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetLastChild(const ConstDataPtr& branchId) const -> typename HIERARCHY::template Child<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetLastChild_Offset), mt_.HierarchyObjectInterface_GetLastChild, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetChildAt(Int position, const ConstDataPtr& branchId) const -> typename HIERARCHY::template Child<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetChildAt_Offset), mt_.HierarchyObjectInterface_GetChildAt, position, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetChildren(const ConstDataPtr& branchId) const -> Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetChildren_Offset), mt_.HierarchyObjectInterface_GetChildren, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetBranches() const -> Result<BaseArray<ConstDataPtr>>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetBranches_Offset), mt_.HierarchyObjectInterface_GetBranches);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetBranchId() const -> ConstDataPtr
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetBranchId_Offset), mt_.HierarchyObjectInterface_GetBranchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::SetLocking(const Bool locking) -> void
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_SetLocking_Offset), mt_.HierarchyObjectInterface_SetLocking, locking);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::IsLocked() const -> Bool
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_IsLocked_Offset), mt_.HierarchyObjectInterface_IsLocked);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetParent() const -> typename HIERARCHY::template Parent<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetParent_Offset), mt_.HierarchyObjectInterface_GetParent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetParentPtr() const -> std::add_pointer<HierarchyObjectInterface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetParentPtr_Offset), mt_.HierarchyObjectInterface_GetParentPtr);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetNext() const -> typename HIERARCHY::template Sibling<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetNext_Offset), mt_.HierarchyObjectInterface_GetNext);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetPrev() const -> typename HIERARCHY::template Sibling<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetPrev_Offset), mt_.HierarchyObjectInterface_GetPrev);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetFirst() const -> typename HIERARCHY::template Sibling<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetFirst_Offset), mt_.HierarchyObjectInterface_GetFirst);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetLast() const -> typename HIERARCHY::template Sibling<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetLast_Offset), mt_.HierarchyObjectInterface_GetLast);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::ParentChanged(Bool removed) -> void
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_ParentChanged_Offset), mt_.HierarchyObjectInterface_ParentChanged, removed);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::FindNextLeaf(const HierarchyObjectInterface* stopAtParent) const -> std::add_pointer<HierarchyObjectInterface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_FindNextLeaf_Offset), mt_.HierarchyObjectInterface_FindNextLeaf, stopAtParent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::ObservableHierarchyInsert(Bool create) const -> maxon::ObservableRef<ObservableHierarchyInsertDelegate>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_ObservableHierarchyInsert_Offset), mt_.HierarchyObjectInterface_ObservableHierarchyInsert, create);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::ObservableHierarchyRemove(Bool create) const -> maxon::ObservableRef<ObservableHierarchyRemoveDelegate>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_ObservableHierarchyRemove_Offset), mt_.HierarchyObjectInterface_ObservableHierarchyRemove, create);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::FlushBranches() -> void
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_FlushBranches_Offset), mt_.HierarchyObjectInterface_FlushBranches);
}

template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertBefore(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& nextSibling) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(HierarchyObjectInterface_InsertBefore); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertBefore_Offset), mt_.HierarchyObjectInterface_InsertBefore, nextSibling));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertBefore(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& nextSibling) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_InsertBefore); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertBefore_Offset), mt_.HierarchyObjectInterface_InsertBefore, nextSibling));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertAfter(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& prevSibling) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(HierarchyObjectInterface_InsertAfter); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAfter_Offset), mt_.HierarchyObjectInterface_InsertAfter, prevSibling));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertAfter(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& prevSibling) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_InsertAfter); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAfter_Offset), mt_.HierarchyObjectInterface_InsertAfter, prevSibling));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertAsFirstChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(HierarchyObjectInterface_InsertAsFirstChildOf); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAsFirstChildOf_Offset), mt_.HierarchyObjectInterface_InsertAsFirstChildOf, parent, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertAsFirstChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_InsertAsFirstChildOf); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAsFirstChildOf_Offset), mt_.HierarchyObjectInterface_InsertAsFirstChildOf, parent, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertAsLastChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(HierarchyObjectInterface_InsertAsLastChildOf); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAsLastChildOf_Offset), mt_.HierarchyObjectInterface_InsertAsLastChildOf, parent, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertAsLastChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_InsertAsLastChildOf); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAsLastChildOf_Offset), mt_.HierarchyObjectInterface_InsertAsLastChildOf, parent, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertAsChildAt(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, Int position, const ConstDataPtr& branchId) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(HierarchyObjectInterface_InsertAsChildAt); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAsChildAt_Offset), mt_.HierarchyObjectInterface_InsertAsChildAt, parent, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertAsChildAt(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_InsertAsChildAt); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAsChildAt_Offset), mt_.HierarchyObjectInterface_InsertAsChildAt, parent, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertChildAsFirst(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(HierarchyObjectInterface_InsertChildAsFirst); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildAsFirst_Offset), mt_.HierarchyObjectInterface_InsertChildAsFirst, child, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertChildAsFirst(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_InsertChildAsFirst); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildAsFirst_Offset), mt_.HierarchyObjectInterface_InsertChildAsFirst, child, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertChildAsLast(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(HierarchyObjectInterface_InsertChildAsLast); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildAsLast_Offset), mt_.HierarchyObjectInterface_InsertChildAsLast, child, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertChildAsLast(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_InsertChildAsLast); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildAsLast_Offset), mt_.HierarchyObjectInterface_InsertChildAsLast, child, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertChildAt(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, Int position, const ConstDataPtr& branchId) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(HierarchyObjectInterface_InsertChildAt); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildAt_Offset), mt_.HierarchyObjectInterface_InsertChildAt, child, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertChildAt(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_InsertChildAt); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildAt_Offset), mt_.HierarchyObjectInterface_InsertChildAt, child, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertChildrenAsFirst(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(HierarchyObjectInterface_InsertChildrenAsFirst); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildrenAsFirst_Offset), mt_.HierarchyObjectInterface_InsertChildrenAsFirst, children, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertChildrenAsFirst(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_InsertChildrenAsFirst); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildrenAsFirst_Offset), mt_.HierarchyObjectInterface_InsertChildrenAsFirst, children, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertChildrenAsLast(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(HierarchyObjectInterface_InsertChildrenAsLast); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildrenAsLast_Offset), mt_.HierarchyObjectInterface_InsertChildrenAsLast, children, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertChildrenAsLast(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_InsertChildrenAsLast); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildrenAsLast_Offset), mt_.HierarchyObjectInterface_InsertChildrenAsLast, children, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertChildrenAt(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, Int position, const ConstDataPtr& branchId) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(HierarchyObjectInterface_InsertChildrenAt); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildrenAt_Offset), mt_.HierarchyObjectInterface_InsertChildrenAt, children, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertChildrenAt(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_InsertChildrenAt); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildrenAt_Offset), mt_.HierarchyObjectInterface_InsertChildrenAt, children, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::Replace(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& newObject) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) HXXTABLE(HierarchyObjectInterface_Replace); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_Replace_Offset), mt_.HierarchyObjectInterface_Replace, newObject));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::Replace(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& newObject) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_Replace); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_Replace_Offset), mt_.HierarchyObjectInterface_Replace, newObject));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::Remove() const -> HXXADDRET2(HierarchyObjectRef<>)
{
	HXXRETURN0(HXXADDRET2(HierarchyObjectRef<>)); HXXRES; HXXNONCONST(, , false, maxon::PrivateDefaultReturnValue<HierarchyObjectRef<>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) HXXTABLE(HierarchyObjectInterface_Remove); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_Remove_Offset), mt_.HierarchyObjectInterface_Remove));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::Remove() -> HXXADDRET1(HierarchyObjectRef<>)
{
	HXXRETURN0(HXXADDRET1(HierarchyObjectRef<>)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_Remove); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_Remove_Offset), mt_.HierarchyObjectInterface_Remove));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::RemoveChildren(const ConstDataPtr& branchId) const -> HXXADDRET2(typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type)
{
	HXXRETURN0(HXXADDRET2(typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type)); HXXRES; HXXNONCONST(, , false, maxon::PrivateDefaultReturnValue<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) HXXTABLE(HierarchyObjectInterface_RemoveChildren); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_RemoveChildren_Offset), mt_.HierarchyObjectInterface_RemoveChildren, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::RemoveChildren(const ConstDataPtr& branchId) -> HXXADDRET1(typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type)
{
	HXXRETURN0(HXXADDRET1(typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_RemoveChildren); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_RemoveChildren_Offset), mt_.HierarchyObjectInterface_RemoveChildren, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::RemoveAllChildren() const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(HierarchyObjectInterface_RemoveAllChildren); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_RemoveAllChildren_Offset), mt_.HierarchyObjectInterface_RemoveAllChildren);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::RemoveAllChildren() -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_RemoveAllChildren); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_RemoveAllChildren_Offset), mt_.HierarchyObjectInterface_RemoveAllChildren);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetFirstChild(const ConstDataPtr& branchId) const -> HXXADDRET2(typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type)
{
	HXXRETURN0(HXXADDRET2(typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) HXXTABLE(HierarchyObjectInterface_GetFirstChild); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetFirstChild_Offset), mt_.HierarchyObjectInterface_GetFirstChild, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetLastChild(const ConstDataPtr& branchId) const -> HXXADDRET2(typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type)
{
	HXXRETURN0(HXXADDRET2(typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) HXXTABLE(HierarchyObjectInterface_GetLastChild); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetLastChild_Offset), mt_.HierarchyObjectInterface_GetLastChild, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetChildAt(Int position, const ConstDataPtr& branchId) const -> HXXADDRET2(typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type)
{
	HXXRETURN0(HXXADDRET2(typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) HXXTABLE(HierarchyObjectInterface_GetChildAt); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetChildAt_Offset), mt_.HierarchyObjectInterface_GetChildAt, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetChildren(const ConstDataPtr& branchId) const -> Result<BaseArray<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>>
{
	HXXRETURN0(Result<BaseArray<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(HierarchyObjectInterface_GetChildren); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetChildren_Offset), mt_.HierarchyObjectInterface_GetChildren, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetBranches() const -> Result<BaseArray<ConstDataPtr>>
{
	HXXRETURN0(Result<BaseArray<ConstDataPtr>>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) HXXTABLE(HierarchyObjectInterface_GetBranches); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetBranches_Offset), mt_.HierarchyObjectInterface_GetBranches));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetBranchId() const -> HXXADDRET2(ConstDataPtr)
{
	HXXRETURN0(HXXADDRET2(ConstDataPtr)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<ConstDataPtr>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) HXXTABLE(HierarchyObjectInterface_GetBranchId); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetBranchId_Offset), mt_.HierarchyObjectInterface_GetBranchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::SetLocking(const Bool locking) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(HierarchyObjectInterface_SetLocking); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_SetLocking_Offset), mt_.HierarchyObjectInterface_SetLocking, locking);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::SetLocking(const Bool locking) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_SetLocking); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_SetLocking_Offset), mt_.HierarchyObjectInterface_SetLocking, locking);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::IsLocked() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) HXXTABLE(HierarchyObjectInterface_IsLocked); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_IsLocked_Offset), mt_.HierarchyObjectInterface_IsLocked));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetParent() const -> HXXADDRET2(typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type)
{
	HXXRETURN0(HXXADDRET2(typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) HXXTABLE(HierarchyObjectInterface_GetParent); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetParent_Offset), mt_.HierarchyObjectInterface_GetParent));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetParentPtr() const -> HXXADDRET2(std::add_pointer<HierarchyObjectInterface>::type)
{
	HXXRETURN0(HXXADDRET2(std::add_pointer<HierarchyObjectInterface>::type)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<std::add_pointer<HierarchyObjectInterface>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) HXXTABLE(HierarchyObjectInterface_GetParentPtr); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetParentPtr_Offset), mt_.HierarchyObjectInterface_GetParentPtr));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetNext() const -> HXXADDRET2(typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type)
{
	HXXRETURN0(HXXADDRET2(typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) HXXTABLE(HierarchyObjectInterface_GetNext); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetNext_Offset), mt_.HierarchyObjectInterface_GetNext));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetPrev() const -> HXXADDRET2(typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type)
{
	HXXRETURN0(HXXADDRET2(typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) HXXTABLE(HierarchyObjectInterface_GetPrev); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetPrev_Offset), mt_.HierarchyObjectInterface_GetPrev));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetFirst() const -> HXXADDRET2(typename HIERARCHY_::template Sibling<Interface>::type)
{
	HXXRETURN0(HXXADDRET2(typename HIERARCHY_::template Sibling<Interface>::type)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<typename HIERARCHY_::template Sibling<Interface>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) HXXTABLE(HierarchyObjectInterface_GetFirst); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetFirst_Offset), mt_.HierarchyObjectInterface_GetFirst));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetLast() const -> HXXADDRET2(typename HIERARCHY_::template Sibling<Interface>::type)
{
	HXXRETURN0(HXXADDRET2(typename HIERARCHY_::template Sibling<Interface>::type)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<typename HIERARCHY_::template Sibling<Interface>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) HXXTABLE(HierarchyObjectInterface_GetLast); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetLast_Offset), mt_.HierarchyObjectInterface_GetLast));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::ParentChanged(Bool removed) const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(HierarchyObjectInterface_ParentChanged); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_ParentChanged_Offset), mt_.HierarchyObjectInterface_ParentChanged, removed);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::ParentChanged(Bool removed) -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_ParentChanged); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_ParentChanged_Offset), mt_.HierarchyObjectInterface_ParentChanged, removed);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::FindNextLeaf(const HierarchyObjectInterface* stopAtParent) const -> HXXADDRET2(std::add_pointer<HierarchyObjectInterface>::type)
{
	HXXRETURN0(HXXADDRET2(std::add_pointer<HierarchyObjectInterface>::type)); HXXRES; HXXCONST(maxon::PrivateDefaultReturnValue<std::add_pointer<HierarchyObjectInterface>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK)) HXXTABLE(HierarchyObjectInterface_FindNextLeaf); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_FindNextLeaf_Offset), mt_.HierarchyObjectInterface_FindNextLeaf, stopAtParent));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::ObservableHierarchyInsert(Bool create) const -> HXXADDRET2(maxon::ObservableRef<ObservableHierarchyInsertDelegate>)
{
	HXXRETURN0(HXXADDRET2(maxon::ObservableRef<ObservableHierarchyInsertDelegate>)); HXXRES; HXXCONST(maxon::ObservableRef<ObservableHierarchyInsertDelegate>::DefaultValue()) HXXTABLE(HierarchyObjectInterface_ObservableHierarchyInsert); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_ObservableHierarchyInsert_Offset), mt_.HierarchyObjectInterface_ObservableHierarchyInsert, create));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::ObservableHierarchyRemove(Bool create) const -> HXXADDRET2(maxon::ObservableRef<ObservableHierarchyRemoveDelegate>)
{
	HXXRETURN0(HXXADDRET2(maxon::ObservableRef<ObservableHierarchyRemoveDelegate>)); HXXRES; HXXCONST(maxon::ObservableRef<ObservableHierarchyRemoveDelegate>::DefaultValue()) HXXTABLE(HierarchyObjectInterface_ObservableHierarchyRemove); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_ObservableHierarchyRemove_Offset), mt_.HierarchyObjectInterface_ObservableHierarchyRemove, create));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::FlushBranches() const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) HXXTABLE(HierarchyObjectInterface_FlushBranches); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_FlushBranches_Offset), mt_.HierarchyObjectInterface_FlushBranches);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::FlushBranches() -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) HXXTABLE(HierarchyObjectInterface_FlushBranches); 
	PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_FlushBranches_Offset), mt_.HierarchyObjectInterface_FlushBranches);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto HierarchyObjectInterface::GetPtr() -> Ptr { return Ptr(this); }
auto HierarchyObjectInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_hierarchyobject)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_HierarchyObjectInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_HierarchyObjectInterface() { new (s_ui_maxon_HierarchyObjectInterface) maxon::EntityUse(HierarchyObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/hierarchyobject.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_HierarchyObjectInterface(HierarchyObjectInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/hierarchyobject.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

