
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
	Result<void> (*HierarchyObjectInterface_InsertBefore) (maxon::GenericComponent* this_, const typename HIERARCHY::template Sibling<Interface>::type& nextSibling);
	maxon::Int HierarchyObjectInterface_InsertBefore_Offset;
	Result<void> (*HierarchyObjectInterface_InsertAfter) (maxon::GenericComponent* this_, const typename HIERARCHY::template Sibling<Interface>::type& prevSibling);
	maxon::Int HierarchyObjectInterface_InsertAfter_Offset;
	Result<void> (*HierarchyObjectInterface_InsertAsFirstChildOf) (maxon::GenericComponent* this_, const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertAsFirstChildOf_Offset;
	Result<void> (*HierarchyObjectInterface_InsertAsLastChildOf) (maxon::GenericComponent* this_, const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertAsLastChildOf_Offset;
	Result<void> (*HierarchyObjectInterface_InsertAsChildAt) (maxon::GenericComponent* this_, const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertAsChildAt_Offset;
	Result<void> (*HierarchyObjectInterface_InsertChildAsFirst) (maxon::GenericComponent* this_, const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertChildAsFirst_Offset;
	Result<void> (*HierarchyObjectInterface_InsertChildAsLast) (maxon::GenericComponent* this_, const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertChildAsLast_Offset;
	Result<void> (*HierarchyObjectInterface_InsertChildAt) (maxon::GenericComponent* this_, const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertChildAt_Offset;
	Result<void> (*HierarchyObjectInterface_InsertChildrenAsFirst) (maxon::GenericComponent* this_, const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertChildrenAsFirst_Offset;
	Result<void> (*HierarchyObjectInterface_InsertChildrenAsLast) (maxon::GenericComponent* this_, const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertChildrenAsLast_Offset;
	Result<void> (*HierarchyObjectInterface_InsertChildrenAt) (maxon::GenericComponent* this_, const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_InsertChildrenAt_Offset;
	Result<void> (*HierarchyObjectInterface_Replace) (maxon::GenericComponent* this_, const typename HIERARCHY::template Sibling<Interface>::type& newObject);
	maxon::Int HierarchyObjectInterface_Replace_Offset;
	HierarchyObjectRef<> (*HierarchyObjectInterface_Remove) (maxon::GenericComponent* this_);
	maxon::Int HierarchyObjectInterface_Remove_Offset;
	typename HIERARCHY::template Child<Interface>::type (*HierarchyObjectInterface_RemoveChildren) (maxon::GenericComponent* this_, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_RemoveChildren_Offset;
	void (*HierarchyObjectInterface_RemoveAllChildren) (maxon::GenericComponent* this_);
	maxon::Int HierarchyObjectInterface_RemoveAllChildren_Offset;
	typename HIERARCHY::template Child<Interface>::type (*HierarchyObjectInterface_GetFirstChild) (const maxon::GenericComponent* this_, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_GetFirstChild_Offset;
	typename HIERARCHY::template Child<Interface>::type (*HierarchyObjectInterface_GetLastChild) (const maxon::GenericComponent* this_, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_GetLastChild_Offset;
	typename HIERARCHY::template Child<Interface>::type (*HierarchyObjectInterface_GetChildAt) (const maxon::GenericComponent* this_, Int position, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_GetChildAt_Offset;
	Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>> (*HierarchyObjectInterface_GetChildren) (const maxon::GenericComponent* this_, const ConstDataPtr& branchId);
	maxon::Int HierarchyObjectInterface_GetChildren_Offset;
	Result<BaseArray<ConstDataPtr>> (*HierarchyObjectInterface_GetBranches) (const maxon::GenericComponent* this_);
	maxon::Int HierarchyObjectInterface_GetBranches_Offset;
	ConstDataPtr (*HierarchyObjectInterface_GetBranchId) (const maxon::GenericComponent* this_);
	maxon::Int HierarchyObjectInterface_GetBranchId_Offset;
	void (*HierarchyObjectInterface_SetLocking) (maxon::GenericComponent* this_, const Bool locking);
	maxon::Int HierarchyObjectInterface_SetLocking_Offset;
	Bool (*HierarchyObjectInterface_IsLocked) (const maxon::GenericComponent* this_);
	maxon::Int HierarchyObjectInterface_IsLocked_Offset;
	typename HIERARCHY::template Parent<Interface>::type (*HierarchyObjectInterface_GetParent) (const maxon::GenericComponent* this_);
	maxon::Int HierarchyObjectInterface_GetParent_Offset;
	std::add_pointer<HierarchyObjectInterface>::type (*HierarchyObjectInterface_GetParentPtr) (const maxon::GenericComponent* this_);
	maxon::Int HierarchyObjectInterface_GetParentPtr_Offset;
	typename HIERARCHY::template Sibling<Interface>::type (*HierarchyObjectInterface_GetNext) (const maxon::GenericComponent* this_);
	maxon::Int HierarchyObjectInterface_GetNext_Offset;
	typename HIERARCHY::template Sibling<Interface>::type (*HierarchyObjectInterface_GetPrev) (const maxon::GenericComponent* this_);
	maxon::Int HierarchyObjectInterface_GetPrev_Offset;
	typename HIERARCHY::template Sibling<Interface>::type (*HierarchyObjectInterface_GetFirst) (const maxon::GenericComponent* this_);
	maxon::Int HierarchyObjectInterface_GetFirst_Offset;
	typename HIERARCHY::template Sibling<Interface>::type (*HierarchyObjectInterface_GetLast) (const maxon::GenericComponent* this_);
	maxon::Int HierarchyObjectInterface_GetLast_Offset;
	void (*HierarchyObjectInterface_ParentChanged) (maxon::GenericComponent* this_, Bool removed);
	maxon::Int HierarchyObjectInterface_ParentChanged_Offset;
	std::add_pointer<HierarchyObjectInterface>::type (*HierarchyObjectInterface_FindNextLeaf) (const maxon::GenericComponent* this_, const HierarchyObjectInterface* stopAtParent);
	maxon::Int HierarchyObjectInterface_FindNextLeaf_Offset;
	maxon::ObservableRef<ObservableHierarchyInsertDelegate> (*HierarchyObjectInterface_ObservableHierarchyInsert) (const maxon::GenericComponent* this_);
	maxon::Int HierarchyObjectInterface_ObservableHierarchyInsert_Offset;
	maxon::ObservableRef<ObservableHierarchyRemoveDelegate> (*HierarchyObjectInterface_ObservableHierarchyRemove) (const maxon::GenericComponent* this_);
	maxon::Int HierarchyObjectInterface_ObservableHierarchyRemove_Offset;
	void (*HierarchyObjectInterface_FlushBranches) (maxon::GenericComponent* this_);
	maxon::Int HierarchyObjectInterface_FlushBranches_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertBefore))
	{
		HierarchyObjectInterface_InsertBefore = &W::HierarchyObjectInterface_InsertBefore;
		HierarchyObjectInterface_InsertBefore_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAfter))
	{
		HierarchyObjectInterface_InsertAfter = &W::HierarchyObjectInterface_InsertAfter;
		HierarchyObjectInterface_InsertAfter_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAsFirstChildOf))
	{
		HierarchyObjectInterface_InsertAsFirstChildOf = &W::HierarchyObjectInterface_InsertAsFirstChildOf;
		HierarchyObjectInterface_InsertAsFirstChildOf_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAsLastChildOf))
	{
		HierarchyObjectInterface_InsertAsLastChildOf = &W::HierarchyObjectInterface_InsertAsLastChildOf;
		HierarchyObjectInterface_InsertAsLastChildOf_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAsChildAt))
	{
		HierarchyObjectInterface_InsertAsChildAt = &W::HierarchyObjectInterface_InsertAsChildAt;
		HierarchyObjectInterface_InsertAsChildAt_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildAsFirst))
	{
		HierarchyObjectInterface_InsertChildAsFirst = &W::HierarchyObjectInterface_InsertChildAsFirst;
		HierarchyObjectInterface_InsertChildAsFirst_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildAsLast))
	{
		HierarchyObjectInterface_InsertChildAsLast = &W::HierarchyObjectInterface_InsertChildAsLast;
		HierarchyObjectInterface_InsertChildAsLast_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildAt))
	{
		HierarchyObjectInterface_InsertChildAt = &W::HierarchyObjectInterface_InsertChildAt;
		HierarchyObjectInterface_InsertChildAt_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildrenAsFirst))
	{
		HierarchyObjectInterface_InsertChildrenAsFirst = &W::HierarchyObjectInterface_InsertChildrenAsFirst;
		HierarchyObjectInterface_InsertChildrenAsFirst_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildrenAsLast))
	{
		HierarchyObjectInterface_InsertChildrenAsLast = &W::HierarchyObjectInterface_InsertChildrenAsLast;
		HierarchyObjectInterface_InsertChildrenAsLast_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildrenAt))
	{
		HierarchyObjectInterface_InsertChildrenAt = &W::HierarchyObjectInterface_InsertChildrenAt;
		HierarchyObjectInterface_InsertChildrenAt_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, Replace))
	{
		HierarchyObjectInterface_Replace = &W::HierarchyObjectInterface_Replace;
		HierarchyObjectInterface_Replace_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, Remove))
	{
		HierarchyObjectInterface_Remove = &W::HierarchyObjectInterface_Remove;
		HierarchyObjectInterface_Remove_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, RemoveChildren))
	{
		HierarchyObjectInterface_RemoveChildren = &W::HierarchyObjectInterface_RemoveChildren;
		HierarchyObjectInterface_RemoveChildren_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, RemoveAllChildren))
	{
		HierarchyObjectInterface_RemoveAllChildren = &W::HierarchyObjectInterface_RemoveAllChildren;
		HierarchyObjectInterface_RemoveAllChildren_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetFirstChild))
	{
		HierarchyObjectInterface_GetFirstChild = &W::HierarchyObjectInterface_GetFirstChild;
		HierarchyObjectInterface_GetFirstChild_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetLastChild))
	{
		HierarchyObjectInterface_GetLastChild = &W::HierarchyObjectInterface_GetLastChild;
		HierarchyObjectInterface_GetLastChild_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetChildAt))
	{
		HierarchyObjectInterface_GetChildAt = &W::HierarchyObjectInterface_GetChildAt;
		HierarchyObjectInterface_GetChildAt_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetChildren))
	{
		HierarchyObjectInterface_GetChildren = &W::HierarchyObjectInterface_GetChildren;
		HierarchyObjectInterface_GetChildren_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetBranches))
	{
		HierarchyObjectInterface_GetBranches = &W::HierarchyObjectInterface_GetBranches;
		HierarchyObjectInterface_GetBranches_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetBranchId))
	{
		HierarchyObjectInterface_GetBranchId = &W::HierarchyObjectInterface_GetBranchId;
		HierarchyObjectInterface_GetBranchId_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, SetLocking))
	{
		HierarchyObjectInterface_SetLocking = &W::HierarchyObjectInterface_SetLocking;
		HierarchyObjectInterface_SetLocking_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, IsLocked))
	{
		HierarchyObjectInterface_IsLocked = &W::HierarchyObjectInterface_IsLocked;
		HierarchyObjectInterface_IsLocked_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetParent))
	{
		HierarchyObjectInterface_GetParent = &W::HierarchyObjectInterface_GetParent;
		HierarchyObjectInterface_GetParent_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetParentPtr))
	{
		HierarchyObjectInterface_GetParentPtr = &W::HierarchyObjectInterface_GetParentPtr;
		HierarchyObjectInterface_GetParentPtr_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetNext))
	{
		HierarchyObjectInterface_GetNext = &W::HierarchyObjectInterface_GetNext;
		HierarchyObjectInterface_GetNext_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetPrev))
	{
		HierarchyObjectInterface_GetPrev = &W::HierarchyObjectInterface_GetPrev;
		HierarchyObjectInterface_GetPrev_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetFirst))
	{
		HierarchyObjectInterface_GetFirst = &W::HierarchyObjectInterface_GetFirst;
		HierarchyObjectInterface_GetFirst_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetLast))
	{
		HierarchyObjectInterface_GetLast = &W::HierarchyObjectInterface_GetLast;
		HierarchyObjectInterface_GetLast_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, ParentChanged))
	{
		HierarchyObjectInterface_ParentChanged = &W::HierarchyObjectInterface_ParentChanged;
		HierarchyObjectInterface_ParentChanged_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, FindNextLeaf))
	{
		HierarchyObjectInterface_FindNextLeaf = &W::HierarchyObjectInterface_FindNextLeaf;
		HierarchyObjectInterface_FindNextLeaf_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, ObservableHierarchyInsert))
	{
		HierarchyObjectInterface_ObservableHierarchyInsert = &W::HierarchyObjectInterface_ObservableHierarchyInsert;
		HierarchyObjectInterface_ObservableHierarchyInsert_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, ObservableHierarchyRemove))
	{
		HierarchyObjectInterface_ObservableHierarchyRemove = &W::HierarchyObjectInterface_ObservableHierarchyRemove;
		HierarchyObjectInterface_ObservableHierarchyRemove_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, FlushBranches))
	{
		HierarchyObjectInterface_FlushBranches = &W::HierarchyObjectInterface_FlushBranches;
		HierarchyObjectInterface_FlushBranches_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<HierarchyObjectInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (HierarchyObjectInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, HierarchyObjectInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> HierarchyObjectInterface_InsertBefore(maxon::GenericComponent* this_, const typename HIERARCHY::template Sibling<Interface>::type& nextSibling) { return ((typename S::Implementation*) this_)->InsertBefore(nextSibling); }
		static Result<void> HierarchyObjectInterface_InsertAfter(maxon::GenericComponent* this_, const typename HIERARCHY::template Sibling<Interface>::type& prevSibling) { return ((typename S::Implementation*) this_)->InsertAfter(prevSibling); }
		static Result<void> HierarchyObjectInterface_InsertAsFirstChildOf(maxon::GenericComponent* this_, const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertAsFirstChildOf(parent, branchId); }
		static Result<void> HierarchyObjectInterface_InsertAsLastChildOf(maxon::GenericComponent* this_, const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertAsLastChildOf(parent, branchId); }
		static Result<void> HierarchyObjectInterface_InsertAsChildAt(maxon::GenericComponent* this_, const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertAsChildAt(parent, position, branchId); }
		static Result<void> HierarchyObjectInterface_InsertChildAsFirst(maxon::GenericComponent* this_, const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertChildAsFirst(child, branchId); }
		static Result<void> HierarchyObjectInterface_InsertChildAsLast(maxon::GenericComponent* this_, const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertChildAsLast(child, branchId); }
		static Result<void> HierarchyObjectInterface_InsertChildAt(maxon::GenericComponent* this_, const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertChildAt(child, position, branchId); }
		static Result<void> HierarchyObjectInterface_InsertChildrenAsFirst(maxon::GenericComponent* this_, const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertChildrenAsFirst(children, branchId); }
		static Result<void> HierarchyObjectInterface_InsertChildrenAsLast(maxon::GenericComponent* this_, const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertChildrenAsLast(children, branchId); }
		static Result<void> HierarchyObjectInterface_InsertChildrenAt(maxon::GenericComponent* this_, const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertChildrenAt(children, position, branchId); }
		static Result<void> HierarchyObjectInterface_Replace(maxon::GenericComponent* this_, const typename HIERARCHY::template Sibling<Interface>::type& newObject) { return ((typename S::Implementation*) this_)->Replace(newObject); }
		static HierarchyObjectRef<> HierarchyObjectInterface_Remove(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Remove(); }
		static typename HIERARCHY::template Child<Interface>::type HierarchyObjectInterface_RemoveChildren(maxon::GenericComponent* this_, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->RemoveChildren(branchId); }
		static void HierarchyObjectInterface_RemoveAllChildren(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->RemoveAllChildren(); }
		static typename HIERARCHY::template Child<Interface>::type HierarchyObjectInterface_GetFirstChild(const maxon::GenericComponent* this_, const ConstDataPtr& branchId) { return ((const typename S::Implementation*) this_)->GetFirstChild(branchId); }
		static typename HIERARCHY::template Child<Interface>::type HierarchyObjectInterface_GetLastChild(const maxon::GenericComponent* this_, const ConstDataPtr& branchId) { return ((const typename S::Implementation*) this_)->GetLastChild(branchId); }
		static typename HIERARCHY::template Child<Interface>::type HierarchyObjectInterface_GetChildAt(const maxon::GenericComponent* this_, Int position, const ConstDataPtr& branchId) { return ((const typename S::Implementation*) this_)->GetChildAt(position, branchId); }
		static Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>> HierarchyObjectInterface_GetChildren(const maxon::GenericComponent* this_, const ConstDataPtr& branchId) { return ((const typename S::Implementation*) this_)->GetChildren(branchId); }
		static Result<BaseArray<ConstDataPtr>> HierarchyObjectInterface_GetBranches(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetBranches(); }
		static ConstDataPtr HierarchyObjectInterface_GetBranchId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetBranchId(); }
		static void HierarchyObjectInterface_SetLocking(maxon::GenericComponent* this_, const Bool locking) { return ((typename S::Implementation*) this_)->SetLocking(locking); }
		static Bool HierarchyObjectInterface_IsLocked(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->IsLocked(); }
		static typename HIERARCHY::template Parent<Interface>::type HierarchyObjectInterface_GetParent(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetParent(); }
		static std::add_pointer<HierarchyObjectInterface>::type HierarchyObjectInterface_GetParentPtr(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetParentPtr(); }
		static typename HIERARCHY::template Sibling<Interface>::type HierarchyObjectInterface_GetNext(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetNext(); }
		static typename HIERARCHY::template Sibling<Interface>::type HierarchyObjectInterface_GetPrev(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetPrev(); }
		static typename HIERARCHY::template Sibling<Interface>::type HierarchyObjectInterface_GetFirst(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetFirst(); }
		static typename HIERARCHY::template Sibling<Interface>::type HierarchyObjectInterface_GetLast(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetLast(); }
		static void HierarchyObjectInterface_ParentChanged(maxon::GenericComponent* this_, Bool removed) { return ((typename S::Implementation*) this_)->ParentChanged(removed); }
		static std::add_pointer<HierarchyObjectInterface>::type HierarchyObjectInterface_FindNextLeaf(const maxon::GenericComponent* this_, const HierarchyObjectInterface* stopAtParent) { return ((const typename S::Implementation*) this_)->FindNextLeaf(stopAtParent); }
		static maxon::ObservableRef<ObservableHierarchyInsertDelegate> HierarchyObjectInterface_ObservableHierarchyInsert(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableHierarchyInsert(); }
		static maxon::ObservableRef<ObservableHierarchyRemoveDelegate> HierarchyObjectInterface_ObservableHierarchyRemove(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableHierarchyRemove(); }
		static void HierarchyObjectInterface_FlushBranches(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->FlushBranches(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertBefore(const typename HIERARCHY::template Sibling<Interface>::type& nextSibling) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_InsertBefore((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertBefore_Offset, nextSibling);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertAfter(const typename HIERARCHY::template Sibling<Interface>::type& prevSibling) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_InsertAfter((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertAfter_Offset, prevSibling);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertAsFirstChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_InsertAsFirstChildOf((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertAsFirstChildOf_Offset, parent, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertAsLastChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_InsertAsLastChildOf((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertAsLastChildOf_Offset, parent, branchId);
}
[[deprecated("Use InsertChildAt")]] MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertAsChildAt(const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_InsertAsChildAt((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertAsChildAt_Offset, parent, position, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildAsFirst(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_InsertChildAsFirst((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertChildAsFirst_Offset, child, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildAsLast(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_InsertChildAsLast((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertChildAsLast_Offset, child, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildAt(const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_InsertChildAt((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertChildAt_Offset, child, position, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildrenAsFirst(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_InsertChildrenAsFirst((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertChildrenAsFirst_Offset, children, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildrenAsLast(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_InsertChildrenAsLast((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertChildrenAsLast_Offset, children, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildrenAt(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_InsertChildrenAt((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_InsertChildrenAt_Offset, children, position, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Replace(const typename HIERARCHY::template Sibling<Interface>::type& newObject) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_Replace((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_Replace_Offset, newObject);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Remove() -> HierarchyObjectRef<>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_Remove((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_Remove_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::RemoveChildren(const ConstDataPtr& branchId) -> typename HIERARCHY::template Child<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_RemoveChildren((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_RemoveChildren_Offset, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::RemoveAllChildren() -> void
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_RemoveAllChildren((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_RemoveAllChildren_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetFirstChild(const ConstDataPtr& branchId) const -> typename HIERARCHY::template Child<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_GetFirstChild((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetFirstChild_Offset, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetLastChild(const ConstDataPtr& branchId) const -> typename HIERARCHY::template Child<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_GetLastChild((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetLastChild_Offset, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetChildAt(Int position, const ConstDataPtr& branchId) const -> typename HIERARCHY::template Child<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_GetChildAt((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetChildAt_Offset, position, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetChildren(const ConstDataPtr& branchId) const -> Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_GetChildren((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetChildren_Offset, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetBranches() const -> Result<BaseArray<ConstDataPtr>>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_GetBranches((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetBranches_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetBranchId() const -> ConstDataPtr
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_GetBranchId((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetBranchId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::SetLocking(const Bool locking) -> void
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_SetLocking((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_SetLocking_Offset, locking);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::IsLocked() const -> Bool
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_IsLocked((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_IsLocked_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetParent() const -> typename HIERARCHY::template Parent<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_GetParent((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetParent_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetParentPtr() const -> std::add_pointer<HierarchyObjectInterface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_GetParentPtr((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetParentPtr_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetNext() const -> typename HIERARCHY::template Sibling<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_GetNext((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetNext_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetPrev() const -> typename HIERARCHY::template Sibling<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_GetPrev((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetPrev_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetFirst() const -> typename HIERARCHY::template Sibling<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_GetFirst((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetFirst_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetLast() const -> typename HIERARCHY::template Sibling<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_GetLast((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_GetLast_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::ParentChanged(Bool removed) -> void
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_ParentChanged((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_ParentChanged_Offset, removed);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::FindNextLeaf(const HierarchyObjectInterface* stopAtParent) const -> std::add_pointer<HierarchyObjectInterface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_FindNextLeaf((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_FindNextLeaf_Offset, stopAtParent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::ObservableHierarchyInsert() const -> maxon::ObservableRef<ObservableHierarchyInsertDelegate>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_ObservableHierarchyInsert((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_ObservableHierarchyInsert_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::ObservableHierarchyRemove() const -> maxon::ObservableRef<ObservableHierarchyRemoveDelegate>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_ObservableHierarchyRemove((const maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_ObservableHierarchyRemove_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::FlushBranches() -> void
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_.HierarchyObjectInterface_FlushBranches((maxon::GenericComponent*) this + mt_.HierarchyObjectInterface_FlushBranches_Offset);
}

template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertBefore(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& nextSibling) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertBefore) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertBefore(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertBefore_Offset, nextSibling));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertBefore(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& nextSibling) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertBefore) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertBefore(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertBefore_Offset, nextSibling));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertAfter(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& prevSibling) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAfter) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertAfter(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAfter_Offset, prevSibling));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertAfter(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& prevSibling) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAfter) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertAfter(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAfter_Offset, prevSibling));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertAsFirstChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAsFirstChildOf) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertAsFirstChildOf(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAsFirstChildOf_Offset, parent, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertAsFirstChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAsFirstChildOf) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertAsFirstChildOf(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAsFirstChildOf_Offset, parent, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertAsLastChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAsLastChildOf) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertAsLastChildOf(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAsLastChildOf_Offset, parent, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertAsLastChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAsLastChildOf) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertAsLastChildOf(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAsLastChildOf_Offset, parent, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertAsChildAt(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, Int position, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAsChildAt) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertAsChildAt(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAsChildAt_Offset, parent, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertAsChildAt(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAsChildAt) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertAsChildAt(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertAsChildAt_Offset, parent, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertChildAsFirst(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildAsFirst) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertChildAsFirst(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildAsFirst_Offset, child, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertChildAsFirst(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildAsFirst) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertChildAsFirst(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildAsFirst_Offset, child, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertChildAsLast(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildAsLast) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertChildAsLast(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildAsLast_Offset, child, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertChildAsLast(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildAsLast) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertChildAsLast(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildAsLast_Offset, child, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertChildAt(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, Int position, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildAt) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertChildAt(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildAt_Offset, child, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertChildAt(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildAt) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertChildAt(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildAt_Offset, child, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertChildrenAsFirst(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildrenAsFirst) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertChildrenAsFirst(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildrenAsFirst_Offset, children, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertChildrenAsFirst(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildrenAsFirst) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertChildrenAsFirst(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildrenAsFirst_Offset, children, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertChildrenAsLast(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildrenAsLast) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertChildrenAsLast(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildrenAsLast_Offset, children, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertChildrenAsLast(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildrenAsLast) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertChildrenAsLast(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildrenAsLast_Offset, children, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::InsertChildrenAt(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, Int position, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildrenAt) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertChildrenAt(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildrenAt_Offset, children, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::InsertChildrenAt(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildrenAt) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_InsertChildrenAt(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_InsertChildrenAt_Offset, children, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::Replace(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& newObject) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_Replace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_Replace(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_Replace_Offset, newObject));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::Replace(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& newObject) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_Replace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_Replace(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_Replace_Offset, newObject));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::Remove() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<HierarchyObjectRef<>>, HierarchyObjectRef<>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<HierarchyObjectRef<>>, HierarchyObjectRef<>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<HierarchyObjectRef<>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_Remove) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_Remove(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_Remove_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::Remove() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), HierarchyObjectRef<>, maxon::Result<HierarchyObjectRef<>>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), HierarchyObjectRef<>, maxon::Result<HierarchyObjectRef<>>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_Remove) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_Remove(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_Remove_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::RemoveChildren(const ConstDataPtr& branchId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_RemoveChildren) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_.HierarchyObjectInterface_RemoveChildren(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_RemoveChildren_Offset, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::RemoveChildren(const ConstDataPtr& branchId) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_RemoveChildren) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_.HierarchyObjectInterface_RemoveChildren(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_RemoveChildren_Offset, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::RemoveAllChildren() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_RemoveAllChildren) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	mt_.HierarchyObjectInterface_RemoveAllChildren(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_RemoveAllChildren_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::RemoveAllChildren() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_RemoveAllChildren) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	mt_.HierarchyObjectInterface_RemoveAllChildren(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_RemoveAllChildren_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetFirstChild(const ConstDataPtr& branchId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetFirstChild) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_.HierarchyObjectInterface_GetFirstChild(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetFirstChild_Offset, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetLastChild(const ConstDataPtr& branchId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetLastChild) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_.HierarchyObjectInterface_GetLastChild(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetLastChild_Offset, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetChildAt(Int position, const ConstDataPtr& branchId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetChildAt) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_.HierarchyObjectInterface_GetChildAt(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetChildAt_Offset, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetChildren(const ConstDataPtr& branchId) const -> Result<BaseArray<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetChildren) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_.HierarchyObjectInterface_GetChildren(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetChildren_Offset, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetBranches() const -> Result<BaseArray<ConstDataPtr>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<ConstDataPtr>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetBranches) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_GetBranches(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetBranches_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetBranchId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstDataPtr>, ConstDataPtr>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstDataPtr>, ConstDataPtr>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<ConstDataPtr>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetBranchId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_GetBranchId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetBranchId_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::SetLocking(const Bool locking) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_SetLocking) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	mt_.HierarchyObjectInterface_SetLocking(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_SetLocking_Offset, locking);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::SetLocking(const Bool locking) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_SetLocking) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	mt_.HierarchyObjectInterface_SetLocking(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_SetLocking_Offset, locking);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::IsLocked() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_IsLocked) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_IsLocked(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_IsLocked_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetParent() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetParent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_.HierarchyObjectInterface_GetParent(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetParent_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetParentPtr() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<std::add_pointer<HierarchyObjectInterface>::type>, std::add_pointer<HierarchyObjectInterface>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<std::add_pointer<HierarchyObjectInterface>::type>, std::add_pointer<HierarchyObjectInterface>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<std::add_pointer<HierarchyObjectInterface>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetParentPtr) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_GetParentPtr(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetParentPtr_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetNext() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetNext) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_.HierarchyObjectInterface_GetNext(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetNext_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetPrev() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetPrev) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_.HierarchyObjectInterface_GetPrev(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetPrev_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetFirst() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<Interface>::type>, typename HIERARCHY_::template Sibling<Interface>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<Interface>::type>, typename HIERARCHY_::template Sibling<Interface>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Sibling<Interface>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetFirst) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_.HierarchyObjectInterface_GetFirst(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetFirst_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::GetLast() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<Interface>::type>, typename HIERARCHY_::template Sibling<Interface>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<Interface>::type>, typename HIERARCHY_::template Sibling<Interface>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Sibling<Interface>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetLast) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_.HierarchyObjectInterface_GetLast(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_GetLast_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::ParentChanged(Bool removed) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_ParentChanged) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	mt_.HierarchyObjectInterface_ParentChanged(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_ParentChanged_Offset, removed);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::ParentChanged(Bool removed) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_ParentChanged) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	mt_.HierarchyObjectInterface_ParentChanged(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_ParentChanged_Offset, removed);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::FindNextLeaf(const HierarchyObjectInterface* stopAtParent) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<std::add_pointer<HierarchyObjectInterface>::type>, std::add_pointer<HierarchyObjectInterface>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<std::add_pointer<HierarchyObjectInterface>::type>, std::add_pointer<HierarchyObjectInterface>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<std::add_pointer<HierarchyObjectInterface>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_FindNextLeaf) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_FindNextLeaf(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_FindNextLeaf_Offset, stopAtParent));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::ObservableHierarchyInsert() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableHierarchyInsertDelegate>>, maxon::ObservableRef<ObservableHierarchyInsertDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableHierarchyInsertDelegate>>, maxon::ObservableRef<ObservableHierarchyInsertDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableHierarchyInsertDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_ObservableHierarchyInsert) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_ObservableHierarchyInsert(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_ObservableHierarchyInsert_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstFn<S, HIERARCHY_>::ObservableHierarchyRemove() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableHierarchyRemoveDelegate>>, maxon::ObservableRef<ObservableHierarchyRemoveDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableHierarchyRemoveDelegate>>, maxon::ObservableRef<ObservableHierarchyRemoveDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableHierarchyRemoveDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_ObservableHierarchyRemove) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_.HierarchyObjectInterface_ObservableHierarchyRemove(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_ObservableHierarchyRemove_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::Fn<S, HIERARCHY_>::FlushBranches() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_FlushBranches) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	mt_.HierarchyObjectInterface_FlushBranches(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_FlushBranches_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWFn<S, HIERARCHY_>::FlushBranches() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_FlushBranches) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	mt_.HierarchyObjectInterface_FlushBranches(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.HierarchyObjectInterface_FlushBranches_Offset);
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

