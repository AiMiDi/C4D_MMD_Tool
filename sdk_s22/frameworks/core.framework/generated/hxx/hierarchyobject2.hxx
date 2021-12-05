
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
	PRIVATE_MAXON_IMPLEMENTS_CHECK(DeprecatedObservableHierarchyInsert);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(DeprecatedObservableHierarchyRemove);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(FindNextLeaf);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBranchId);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetBranches);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChildAt);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetChildren);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetFirst);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetFirstChild);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLast);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetLastChild);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetNext);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetOwner);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetParent);
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
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_HierarchyObjectInterface_InsertBefore) (maxon::GenericComponent* this_, const typename HIERARCHY::template Sibling<Interface>::type& nextSibling);
	maxon::Int _HierarchyObjectInterface_InsertBefore_Offset;
	Result<void> (*_HierarchyObjectInterface_InsertAfter) (maxon::GenericComponent* this_, const typename HIERARCHY::template Sibling<Interface>::type& prevSibling);
	maxon::Int _HierarchyObjectInterface_InsertAfter_Offset;
	Result<void> (*_HierarchyObjectInterface_InsertAsFirstChildOf) (maxon::GenericComponent* this_, const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId);
	maxon::Int _HierarchyObjectInterface_InsertAsFirstChildOf_Offset;
	Result<void> (*_HierarchyObjectInterface_InsertAsLastChildOf) (maxon::GenericComponent* this_, const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId);
	maxon::Int _HierarchyObjectInterface_InsertAsLastChildOf_Offset;
	Result<void> (*_HierarchyObjectInterface_InsertAsChildAt) (maxon::GenericComponent* this_, const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId);
	maxon::Int _HierarchyObjectInterface_InsertAsChildAt_Offset;
	Result<void> (*_HierarchyObjectInterface_InsertChildAsFirst) (maxon::GenericComponent* this_, const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId);
	maxon::Int _HierarchyObjectInterface_InsertChildAsFirst_Offset;
	Result<void> (*_HierarchyObjectInterface_InsertChildAsLast) (maxon::GenericComponent* this_, const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId);
	maxon::Int _HierarchyObjectInterface_InsertChildAsLast_Offset;
	Result<void> (*_HierarchyObjectInterface_InsertChildAt) (maxon::GenericComponent* this_, const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId);
	maxon::Int _HierarchyObjectInterface_InsertChildAt_Offset;
	Result<void> (*_HierarchyObjectInterface_InsertChildrenAsFirst) (maxon::GenericComponent* this_, const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId);
	maxon::Int _HierarchyObjectInterface_InsertChildrenAsFirst_Offset;
	Result<void> (*_HierarchyObjectInterface_InsertChildrenAsLast) (maxon::GenericComponent* this_, const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId);
	maxon::Int _HierarchyObjectInterface_InsertChildrenAsLast_Offset;
	Result<void> (*_HierarchyObjectInterface_InsertChildrenAt) (maxon::GenericComponent* this_, const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId);
	maxon::Int _HierarchyObjectInterface_InsertChildrenAt_Offset;
	Result<void> (*_HierarchyObjectInterface_Replace) (maxon::GenericComponent* this_, const typename HIERARCHY::template Sibling<Interface>::type& newObject);
	maxon::Int _HierarchyObjectInterface_Replace_Offset;
	HierarchyObjectRef<> (*_HierarchyObjectInterface_Remove) (maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_Remove_Offset;
	typename HIERARCHY::template Child<Interface>::type (*_HierarchyObjectInterface_RemoveChildren) (maxon::GenericComponent* this_, const ConstDataPtr& branchId);
	maxon::Int _HierarchyObjectInterface_RemoveChildren_Offset;
	void (*_HierarchyObjectInterface_RemoveAllChildren) (maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_RemoveAllChildren_Offset;
	Result<Data> (*_HierarchyObjectInterface_GetOwner) (const maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_GetOwner_Offset;
	typename HIERARCHY::template Child<Interface>::type (*_HierarchyObjectInterface_GetFirstChild) (const maxon::GenericComponent* this_, const ConstDataPtr& branchId);
	maxon::Int _HierarchyObjectInterface_GetFirstChild_Offset;
	typename HIERARCHY::template Child<Interface>::type (*_HierarchyObjectInterface_GetLastChild) (const maxon::GenericComponent* this_, const ConstDataPtr& branchId);
	maxon::Int _HierarchyObjectInterface_GetLastChild_Offset;
	typename HIERARCHY::template Child<Interface>::type (*_HierarchyObjectInterface_GetChildAt) (const maxon::GenericComponent* this_, Int position, const ConstDataPtr& branchId);
	maxon::Int _HierarchyObjectInterface_GetChildAt_Offset;
	Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>> (*_HierarchyObjectInterface_GetChildren) (const maxon::GenericComponent* this_, const ConstDataPtr& branchId);
	maxon::Int _HierarchyObjectInterface_GetChildren_Offset;
	Result<BaseArray<ConstDataPtr>> (*_HierarchyObjectInterface_GetBranches) (const maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_GetBranches_Offset;
	ConstDataPtr (*_HierarchyObjectInterface_GetBranchId) (const maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_GetBranchId_Offset;
	void (*_HierarchyObjectInterface_SetLocking) (maxon::GenericComponent* this_, const Bool locking);
	maxon::Int _HierarchyObjectInterface_SetLocking_Offset;
	Bool (*_HierarchyObjectInterface_IsLocked) (const maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_IsLocked_Offset;
	typename HIERARCHY::template Parent<Interface>::type (*_HierarchyObjectInterface_GetParent) (const maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_GetParent_Offset;
	typename HIERARCHY::template Sibling<Interface>::type (*_HierarchyObjectInterface_GetNext) (const maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_GetNext_Offset;
	typename HIERARCHY::template Sibling<Interface>::type (*_HierarchyObjectInterface_GetPrev) (const maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_GetPrev_Offset;
	typename HIERARCHY::template Sibling<Interface>::type (*_HierarchyObjectInterface_GetFirst) (const maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_GetFirst_Offset;
	typename HIERARCHY::template Sibling<Interface>::type (*_HierarchyObjectInterface_GetLast) (const maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_GetLast_Offset;
	void (*_HierarchyObjectInterface_ParentChanged) (maxon::GenericComponent* this_, Bool removed);
	maxon::Int _HierarchyObjectInterface_ParentChanged_Offset;
	std::add_pointer<HierarchyObjectInterface>::type (*_HierarchyObjectInterface_FindNextLeaf) (const maxon::GenericComponent* this_, const HierarchyObjectInterface* stopAtParent);
	maxon::Int _HierarchyObjectInterface_FindNextLeaf_Offset;
	maxon::ObservableRef<ObservableHierarchyInsertDelegate> (*_HierarchyObjectInterface_ObservableHierarchyInsert) (const maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_ObservableHierarchyInsert_Offset;
	maxon::ObservableRef<DeprecatedObservableHierarchyInsertDelegate> (*_HierarchyObjectInterface_DeprecatedObservableHierarchyInsert) (const maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_DeprecatedObservableHierarchyInsert_Offset;
	maxon::ObservableRef<ObservableHierarchyRemoveDelegate> (*_HierarchyObjectInterface_ObservableHierarchyRemove) (const maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_ObservableHierarchyRemove_Offset;
	maxon::ObservableRef<DeprecatedObservableHierarchyRemoveDelegate> (*_HierarchyObjectInterface_DeprecatedObservableHierarchyRemove) (const maxon::GenericComponent* this_);
	maxon::Int _HierarchyObjectInterface_DeprecatedObservableHierarchyRemove_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertBefore))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertBefore), W, MTable>::type::_HierarchyObjectInterface_InsertBefore;
			_HierarchyObjectInterface_InsertBefore = reinterpret_cast<const decltype(_HierarchyObjectInterface_InsertBefore)&>(ptr);
			_HierarchyObjectInterface_InsertBefore_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAfter))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAfter), W, MTable>::type::_HierarchyObjectInterface_InsertAfter;
			_HierarchyObjectInterface_InsertAfter = reinterpret_cast<const decltype(_HierarchyObjectInterface_InsertAfter)&>(ptr);
			_HierarchyObjectInterface_InsertAfter_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAsFirstChildOf))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAsFirstChildOf), W, MTable>::type::_HierarchyObjectInterface_InsertAsFirstChildOf;
			_HierarchyObjectInterface_InsertAsFirstChildOf = reinterpret_cast<const decltype(_HierarchyObjectInterface_InsertAsFirstChildOf)&>(ptr);
			_HierarchyObjectInterface_InsertAsFirstChildOf_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAsLastChildOf))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAsLastChildOf), W, MTable>::type::_HierarchyObjectInterface_InsertAsLastChildOf;
			_HierarchyObjectInterface_InsertAsLastChildOf = reinterpret_cast<const decltype(_HierarchyObjectInterface_InsertAsLastChildOf)&>(ptr);
			_HierarchyObjectInterface_InsertAsLastChildOf_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAsChildAt))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertAsChildAt), W, MTable>::type::_HierarchyObjectInterface_InsertAsChildAt;
			_HierarchyObjectInterface_InsertAsChildAt = reinterpret_cast<const decltype(_HierarchyObjectInterface_InsertAsChildAt)&>(ptr);
			_HierarchyObjectInterface_InsertAsChildAt_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildAsFirst))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildAsFirst), W, MTable>::type::_HierarchyObjectInterface_InsertChildAsFirst;
			_HierarchyObjectInterface_InsertChildAsFirst = reinterpret_cast<const decltype(_HierarchyObjectInterface_InsertChildAsFirst)&>(ptr);
			_HierarchyObjectInterface_InsertChildAsFirst_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildAsLast))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildAsLast), W, MTable>::type::_HierarchyObjectInterface_InsertChildAsLast;
			_HierarchyObjectInterface_InsertChildAsLast = reinterpret_cast<const decltype(_HierarchyObjectInterface_InsertChildAsLast)&>(ptr);
			_HierarchyObjectInterface_InsertChildAsLast_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildAt))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildAt), W, MTable>::type::_HierarchyObjectInterface_InsertChildAt;
			_HierarchyObjectInterface_InsertChildAt = reinterpret_cast<const decltype(_HierarchyObjectInterface_InsertChildAt)&>(ptr);
			_HierarchyObjectInterface_InsertChildAt_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildrenAsFirst))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildrenAsFirst), W, MTable>::type::_HierarchyObjectInterface_InsertChildrenAsFirst;
			_HierarchyObjectInterface_InsertChildrenAsFirst = reinterpret_cast<const decltype(_HierarchyObjectInterface_InsertChildrenAsFirst)&>(ptr);
			_HierarchyObjectInterface_InsertChildrenAsFirst_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildrenAsLast))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildrenAsLast), W, MTable>::type::_HierarchyObjectInterface_InsertChildrenAsLast;
			_HierarchyObjectInterface_InsertChildrenAsLast = reinterpret_cast<const decltype(_HierarchyObjectInterface_InsertChildrenAsLast)&>(ptr);
			_HierarchyObjectInterface_InsertChildrenAsLast_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildrenAt))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, InsertChildrenAt), W, MTable>::type::_HierarchyObjectInterface_InsertChildrenAt;
			_HierarchyObjectInterface_InsertChildrenAt = reinterpret_cast<const decltype(_HierarchyObjectInterface_InsertChildrenAt)&>(ptr);
			_HierarchyObjectInterface_InsertChildrenAt_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, Replace))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, Replace), W, MTable>::type::_HierarchyObjectInterface_Replace;
			_HierarchyObjectInterface_Replace = reinterpret_cast<const decltype(_HierarchyObjectInterface_Replace)&>(ptr);
			_HierarchyObjectInterface_Replace_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, Remove))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, Remove), W, MTable>::type::_HierarchyObjectInterface_Remove;
			_HierarchyObjectInterface_Remove = reinterpret_cast<const decltype(_HierarchyObjectInterface_Remove)&>(ptr);
			_HierarchyObjectInterface_Remove_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, RemoveChildren))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, RemoveChildren), W, MTable>::type::_HierarchyObjectInterface_RemoveChildren;
			_HierarchyObjectInterface_RemoveChildren = reinterpret_cast<const decltype(_HierarchyObjectInterface_RemoveChildren)&>(ptr);
			_HierarchyObjectInterface_RemoveChildren_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, RemoveAllChildren))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, RemoveAllChildren), W, MTable>::type::_HierarchyObjectInterface_RemoveAllChildren;
			_HierarchyObjectInterface_RemoveAllChildren = reinterpret_cast<const decltype(_HierarchyObjectInterface_RemoveAllChildren)&>(ptr);
			_HierarchyObjectInterface_RemoveAllChildren_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetOwner))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetOwner), W, MTable>::type::_HierarchyObjectInterface_GetOwner;
			_HierarchyObjectInterface_GetOwner = reinterpret_cast<const decltype(_HierarchyObjectInterface_GetOwner)&>(ptr);
			_HierarchyObjectInterface_GetOwner_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetFirstChild))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetFirstChild), W, MTable>::type::_HierarchyObjectInterface_GetFirstChild;
			_HierarchyObjectInterface_GetFirstChild = reinterpret_cast<const decltype(_HierarchyObjectInterface_GetFirstChild)&>(ptr);
			_HierarchyObjectInterface_GetFirstChild_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetLastChild))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetLastChild), W, MTable>::type::_HierarchyObjectInterface_GetLastChild;
			_HierarchyObjectInterface_GetLastChild = reinterpret_cast<const decltype(_HierarchyObjectInterface_GetLastChild)&>(ptr);
			_HierarchyObjectInterface_GetLastChild_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetChildAt))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetChildAt), W, MTable>::type::_HierarchyObjectInterface_GetChildAt;
			_HierarchyObjectInterface_GetChildAt = reinterpret_cast<const decltype(_HierarchyObjectInterface_GetChildAt)&>(ptr);
			_HierarchyObjectInterface_GetChildAt_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetChildren))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetChildren), W, MTable>::type::_HierarchyObjectInterface_GetChildren;
			_HierarchyObjectInterface_GetChildren = reinterpret_cast<const decltype(_HierarchyObjectInterface_GetChildren)&>(ptr);
			_HierarchyObjectInterface_GetChildren_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetBranches))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetBranches), W, MTable>::type::_HierarchyObjectInterface_GetBranches;
			_HierarchyObjectInterface_GetBranches = reinterpret_cast<const decltype(_HierarchyObjectInterface_GetBranches)&>(ptr);
			_HierarchyObjectInterface_GetBranches_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetBranchId))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetBranchId), W, MTable>::type::_HierarchyObjectInterface_GetBranchId;
			_HierarchyObjectInterface_GetBranchId = reinterpret_cast<const decltype(_HierarchyObjectInterface_GetBranchId)&>(ptr);
			_HierarchyObjectInterface_GetBranchId_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, SetLocking))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, SetLocking), W, MTable>::type::_HierarchyObjectInterface_SetLocking;
			_HierarchyObjectInterface_SetLocking = reinterpret_cast<const decltype(_HierarchyObjectInterface_SetLocking)&>(ptr);
			_HierarchyObjectInterface_SetLocking_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, IsLocked))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, IsLocked), W, MTable>::type::_HierarchyObjectInterface_IsLocked;
			_HierarchyObjectInterface_IsLocked = reinterpret_cast<const decltype(_HierarchyObjectInterface_IsLocked)&>(ptr);
			_HierarchyObjectInterface_IsLocked_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetParent))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetParent), W, MTable>::type::_HierarchyObjectInterface_GetParent;
			_HierarchyObjectInterface_GetParent = reinterpret_cast<const decltype(_HierarchyObjectInterface_GetParent)&>(ptr);
			_HierarchyObjectInterface_GetParent_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetNext))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetNext), W, MTable>::type::_HierarchyObjectInterface_GetNext;
			_HierarchyObjectInterface_GetNext = reinterpret_cast<const decltype(_HierarchyObjectInterface_GetNext)&>(ptr);
			_HierarchyObjectInterface_GetNext_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetPrev))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetPrev), W, MTable>::type::_HierarchyObjectInterface_GetPrev;
			_HierarchyObjectInterface_GetPrev = reinterpret_cast<const decltype(_HierarchyObjectInterface_GetPrev)&>(ptr);
			_HierarchyObjectInterface_GetPrev_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetFirst))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetFirst), W, MTable>::type::_HierarchyObjectInterface_GetFirst;
			_HierarchyObjectInterface_GetFirst = reinterpret_cast<const decltype(_HierarchyObjectInterface_GetFirst)&>(ptr);
			_HierarchyObjectInterface_GetFirst_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetLast))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, GetLast), W, MTable>::type::_HierarchyObjectInterface_GetLast;
			_HierarchyObjectInterface_GetLast = reinterpret_cast<const decltype(_HierarchyObjectInterface_GetLast)&>(ptr);
			_HierarchyObjectInterface_GetLast_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, ParentChanged))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, ParentChanged), W, MTable>::type::_HierarchyObjectInterface_ParentChanged;
			_HierarchyObjectInterface_ParentChanged = reinterpret_cast<const decltype(_HierarchyObjectInterface_ParentChanged)&>(ptr);
			_HierarchyObjectInterface_ParentChanged_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, FindNextLeaf))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, FindNextLeaf), W, MTable>::type::_HierarchyObjectInterface_FindNextLeaf;
			_HierarchyObjectInterface_FindNextLeaf = reinterpret_cast<const decltype(_HierarchyObjectInterface_FindNextLeaf)&>(ptr);
			_HierarchyObjectInterface_FindNextLeaf_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, ObservableHierarchyInsert))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, ObservableHierarchyInsert), W, MTable>::type::_HierarchyObjectInterface_ObservableHierarchyInsert;
			_HierarchyObjectInterface_ObservableHierarchyInsert = reinterpret_cast<const decltype(_HierarchyObjectInterface_ObservableHierarchyInsert)&>(ptr);
			_HierarchyObjectInterface_ObservableHierarchyInsert_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, DeprecatedObservableHierarchyInsert))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, DeprecatedObservableHierarchyInsert), W, MTable>::type::_HierarchyObjectInterface_DeprecatedObservableHierarchyInsert;
			_HierarchyObjectInterface_DeprecatedObservableHierarchyInsert = reinterpret_cast<const decltype(_HierarchyObjectInterface_DeprecatedObservableHierarchyInsert)&>(ptr);
			_HierarchyObjectInterface_DeprecatedObservableHierarchyInsert_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, ObservableHierarchyRemove))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, ObservableHierarchyRemove), W, MTable>::type::_HierarchyObjectInterface_ObservableHierarchyRemove;
			_HierarchyObjectInterface_ObservableHierarchyRemove = reinterpret_cast<const decltype(_HierarchyObjectInterface_ObservableHierarchyRemove)&>(ptr);
			_HierarchyObjectInterface_ObservableHierarchyRemove_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, DeprecatedObservableHierarchyRemove))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, HierarchyObjectInterface, DeprecatedObservableHierarchyRemove), W, MTable>::type::_HierarchyObjectInterface_DeprecatedObservableHierarchyRemove;
			_HierarchyObjectInterface_DeprecatedObservableHierarchyRemove = reinterpret_cast<const decltype(_HierarchyObjectInterface_DeprecatedObservableHierarchyRemove)&>(ptr);
			_HierarchyObjectInterface_DeprecatedObservableHierarchyRemove_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObserverObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<HierarchyObjectInterface, typename ObserverObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(HierarchyObjectInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct HierarchyObjectInterface::Hxx2
{
	template <typename S> class Wrapper : public ObserverObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(DeprecatedObservableHierarchyInsert);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(DeprecatedObservableHierarchyRemove);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(FindNextLeaf);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBranchId);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetBranches);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChildAt);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetChildren);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFirst);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetFirstChild);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLast);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetLastChild);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetNext);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetOwner);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetParent);
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
	static Result<void> _HierarchyObjectInterface_InsertBefore(maxon::GenericComponent* this_, const typename HIERARCHY::template Sibling<Interface>::type& nextSibling) { return ((typename S::Implementation*) this_)->InsertBefore(nextSibling); }
	static Result<void> _HierarchyObjectInterface_InsertAfter(maxon::GenericComponent* this_, const typename HIERARCHY::template Sibling<Interface>::type& prevSibling) { return ((typename S::Implementation*) this_)->InsertAfter(prevSibling); }
	static Result<void> _HierarchyObjectInterface_InsertAsFirstChildOf(maxon::GenericComponent* this_, const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertAsFirstChildOf(parent, branchId); }
	static Result<void> _HierarchyObjectInterface_InsertAsLastChildOf(maxon::GenericComponent* this_, const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertAsLastChildOf(parent, branchId); }
	static Result<void> _HierarchyObjectInterface_InsertAsChildAt(maxon::GenericComponent* this_, const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertAsChildAt(parent, position, branchId); }
	static Result<void> _HierarchyObjectInterface_InsertChildAsFirst(maxon::GenericComponent* this_, const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertChildAsFirst(child, branchId); }
	static Result<void> _HierarchyObjectInterface_InsertChildAsLast(maxon::GenericComponent* this_, const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertChildAsLast(child, branchId); }
	static Result<void> _HierarchyObjectInterface_InsertChildAt(maxon::GenericComponent* this_, const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertChildAt(child, position, branchId); }
	static Result<void> _HierarchyObjectInterface_InsertChildrenAsFirst(maxon::GenericComponent* this_, const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertChildrenAsFirst(children, branchId); }
	static Result<void> _HierarchyObjectInterface_InsertChildrenAsLast(maxon::GenericComponent* this_, const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertChildrenAsLast(children, branchId); }
	static Result<void> _HierarchyObjectInterface_InsertChildrenAt(maxon::GenericComponent* this_, const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->InsertChildrenAt(children, position, branchId); }
	static Result<void> _HierarchyObjectInterface_Replace(maxon::GenericComponent* this_, const typename HIERARCHY::template Sibling<Interface>::type& newObject) { return ((typename S::Implementation*) this_)->Replace(newObject); }
	static HierarchyObjectRef<> _HierarchyObjectInterface_Remove(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Remove(); }
	static typename HIERARCHY::template Child<Interface>::type _HierarchyObjectInterface_RemoveChildren(maxon::GenericComponent* this_, const ConstDataPtr& branchId) { return ((typename S::Implementation*) this_)->RemoveChildren(branchId); }
	static void _HierarchyObjectInterface_RemoveAllChildren(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->RemoveAllChildren(); }
	static Result<Data> _HierarchyObjectInterface_GetOwner(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetOwner(); }
	static typename HIERARCHY::template Child<Interface>::type _HierarchyObjectInterface_GetFirstChild(const maxon::GenericComponent* this_, const ConstDataPtr& branchId) { return ((const typename S::Implementation*) this_)->GetFirstChild(branchId); }
	static typename HIERARCHY::template Child<Interface>::type _HierarchyObjectInterface_GetLastChild(const maxon::GenericComponent* this_, const ConstDataPtr& branchId) { return ((const typename S::Implementation*) this_)->GetLastChild(branchId); }
	static typename HIERARCHY::template Child<Interface>::type _HierarchyObjectInterface_GetChildAt(const maxon::GenericComponent* this_, Int position, const ConstDataPtr& branchId) { return ((const typename S::Implementation*) this_)->GetChildAt(position, branchId); }
	static Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>> _HierarchyObjectInterface_GetChildren(const maxon::GenericComponent* this_, const ConstDataPtr& branchId) { return ((const typename S::Implementation*) this_)->GetChildren(branchId); }
	static Result<BaseArray<ConstDataPtr>> _HierarchyObjectInterface_GetBranches(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetBranches(); }
	static ConstDataPtr _HierarchyObjectInterface_GetBranchId(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetBranchId(); }
	static void _HierarchyObjectInterface_SetLocking(maxon::GenericComponent* this_, const Bool locking) { return ((typename S::Implementation*) this_)->SetLocking(locking); }
	static Bool _HierarchyObjectInterface_IsLocked(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->IsLocked(); }
	static typename HIERARCHY::template Parent<Interface>::type _HierarchyObjectInterface_GetParent(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetParent(); }
	static typename HIERARCHY::template Sibling<Interface>::type _HierarchyObjectInterface_GetNext(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetNext(); }
	static typename HIERARCHY::template Sibling<Interface>::type _HierarchyObjectInterface_GetPrev(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetPrev(); }
	static typename HIERARCHY::template Sibling<Interface>::type _HierarchyObjectInterface_GetFirst(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetFirst(); }
	static typename HIERARCHY::template Sibling<Interface>::type _HierarchyObjectInterface_GetLast(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetLast(); }
	static void _HierarchyObjectInterface_ParentChanged(maxon::GenericComponent* this_, Bool removed) { return ((typename S::Implementation*) this_)->ParentChanged(removed); }
	static std::add_pointer<HierarchyObjectInterface>::type _HierarchyObjectInterface_FindNextLeaf(const maxon::GenericComponent* this_, const HierarchyObjectInterface* stopAtParent) { return ((const typename S::Implementation*) this_)->FindNextLeaf(stopAtParent); }
	static maxon::ObservableRef<ObservableHierarchyInsertDelegate> _HierarchyObjectInterface_ObservableHierarchyInsert(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableHierarchyInsert(); }
	static maxon::ObservableRef<DeprecatedObservableHierarchyInsertDelegate> _HierarchyObjectInterface_DeprecatedObservableHierarchyInsert(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->DeprecatedObservableHierarchyInsert(); }
	static maxon::ObservableRef<ObservableHierarchyRemoveDelegate> _HierarchyObjectInterface_ObservableHierarchyRemove(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->ObservableHierarchyRemove(); }
	static maxon::ObservableRef<DeprecatedObservableHierarchyRemoveDelegate> _HierarchyObjectInterface_DeprecatedObservableHierarchyRemove(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->DeprecatedObservableHierarchyRemove(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertBefore(const typename HIERARCHY::template Sibling<Interface>::type& nextSibling) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_InsertBefore((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_InsertBefore_Offset, nextSibling);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertAfter(const typename HIERARCHY::template Sibling<Interface>::type& prevSibling) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_InsertAfter((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_InsertAfter_Offset, prevSibling);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertAsFirstChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_InsertAsFirstChildOf((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_InsertAsFirstChildOf_Offset, parent, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertAsLastChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_InsertAsLastChildOf((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_InsertAsLastChildOf_Offset, parent, branchId);
}
[[deprecated("Use InsertChildAt")]] MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertAsChildAt(const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_InsertAsChildAt((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_InsertAsChildAt_Offset, parent, position, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildAsFirst(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_InsertChildAsFirst((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_InsertChildAsFirst_Offset, child, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildAsLast(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_InsertChildAsLast((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_InsertChildAsLast_Offset, child, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildAt(const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_InsertChildAt((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_InsertChildAt_Offset, child, position, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildrenAsFirst(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_InsertChildrenAsFirst((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_InsertChildrenAsFirst_Offset, children, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildrenAsLast(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_InsertChildrenAsLast((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_InsertChildrenAsLast_Offset, children, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::InsertChildrenAt(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_InsertChildrenAt((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_InsertChildrenAt_Offset, children, position, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Replace(const typename HIERARCHY::template Sibling<Interface>::type& newObject) -> Result<void>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_Replace((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_Replace_Offset, newObject);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Remove() -> HierarchyObjectRef<>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_Remove((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_Remove_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::RemoveChildren(const ConstDataPtr& branchId) -> typename HIERARCHY::template Child<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_RemoveChildren((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_RemoveChildren_Offset, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::RemoveAllChildren() -> void
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_RemoveAllChildren((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_RemoveAllChildren_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetOwner() const -> Result<Data>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_GetOwner((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_GetOwner_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetFirstChild(const ConstDataPtr& branchId) const -> typename HIERARCHY::template Child<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_GetFirstChild((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_GetFirstChild_Offset, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetLastChild(const ConstDataPtr& branchId) const -> typename HIERARCHY::template Child<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_GetLastChild((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_GetLastChild_Offset, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetChildAt(Int position, const ConstDataPtr& branchId) const -> typename HIERARCHY::template Child<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_GetChildAt((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_GetChildAt_Offset, position, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetChildren(const ConstDataPtr& branchId) const -> Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_GetChildren((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_GetChildren_Offset, branchId);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetBranches() const -> Result<BaseArray<ConstDataPtr>>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_GetBranches((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_GetBranches_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetBranchId() const -> ConstDataPtr
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_GetBranchId((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_GetBranchId_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::SetLocking(const Bool locking) -> void
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_SetLocking((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_SetLocking_Offset, locking);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::IsLocked() const -> Bool
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_IsLocked((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_IsLocked_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetParent() const -> typename HIERARCHY::template Parent<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_GetParent((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_GetParent_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetNext() const -> typename HIERARCHY::template Sibling<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_GetNext((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_GetNext_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetPrev() const -> typename HIERARCHY::template Sibling<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_GetPrev((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_GetPrev_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetFirst() const -> typename HIERARCHY::template Sibling<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_GetFirst((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_GetFirst_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::GetLast() const -> typename HIERARCHY::template Sibling<Interface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_GetLast((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_GetLast_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::ParentChanged(Bool removed) -> void
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_ParentChanged((maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_ParentChanged_Offset, removed);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::FindNextLeaf(const HierarchyObjectInterface* stopAtParent) const -> std::add_pointer<HierarchyObjectInterface>::type
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_FindNextLeaf((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_FindNextLeaf_Offset, stopAtParent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::ObservableHierarchyInsert() const -> maxon::ObservableRef<ObservableHierarchyInsertDelegate>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_ObservableHierarchyInsert((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_ObservableHierarchyInsert_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::DeprecatedObservableHierarchyInsert() const -> maxon::ObservableRef<DeprecatedObservableHierarchyInsertDelegate>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_DeprecatedObservableHierarchyInsert((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_DeprecatedObservableHierarchyInsert_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::ObservableHierarchyRemove() const -> maxon::ObservableRef<ObservableHierarchyRemoveDelegate>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_ObservableHierarchyRemove((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_ObservableHierarchyRemove_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::DeprecatedObservableHierarchyRemove() const -> maxon::ObservableRef<DeprecatedObservableHierarchyRemoveDelegate>
{
	const HierarchyObjectInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, this); return mt_._HierarchyObjectInterface_DeprecatedObservableHierarchyRemove((const maxon::GenericComponent*) this + mt_._HierarchyObjectInterface_DeprecatedObservableHierarchyRemove_Offset);
}

template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::InsertBefore(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& nextSibling) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertBefore) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertBefore(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertBefore_Offset, nextSibling));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::InsertBefore(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& nextSibling) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertBefore) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertBefore(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertBefore_Offset, nextSibling));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::InsertAfter(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& prevSibling) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAfter) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertAfter(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertAfter_Offset, prevSibling));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::InsertAfter(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& prevSibling) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAfter) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertAfter(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertAfter_Offset, prevSibling));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::InsertAsFirstChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAsFirstChildOf) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertAsFirstChildOf(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertAsFirstChildOf_Offset, parent, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::InsertAsFirstChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAsFirstChildOf) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertAsFirstChildOf(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertAsFirstChildOf_Offset, parent, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::InsertAsLastChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAsLastChildOf) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertAsLastChildOf(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertAsLastChildOf_Offset, parent, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::InsertAsLastChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAsLastChildOf) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertAsLastChildOf(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertAsLastChildOf_Offset, parent, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::InsertAsChildAt(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, Int position, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAsChildAt) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertAsChildAt(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertAsChildAt_Offset, parent, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::InsertAsChildAt(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertAsChildAt) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertAsChildAt(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertAsChildAt_Offset, parent, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::InsertChildAsFirst(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildAsFirst) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertChildAsFirst(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildAsFirst_Offset, child, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::InsertChildAsFirst(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildAsFirst) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertChildAsFirst(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildAsFirst_Offset, child, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::InsertChildAsLast(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildAsLast) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertChildAsLast(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildAsLast_Offset, child, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::InsertChildAsLast(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildAsLast) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertChildAsLast(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildAsLast_Offset, child, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::InsertChildAt(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, Int position, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildAt) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertChildAt(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildAt_Offset, child, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::InsertChildAt(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildAt) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertChildAt(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildAt_Offset, child, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::InsertChildrenAsFirst(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildrenAsFirst) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertChildrenAsFirst(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildrenAsFirst_Offset, children, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::InsertChildrenAsFirst(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildrenAsFirst) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertChildrenAsFirst(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildrenAsFirst_Offset, children, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::InsertChildrenAsLast(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildrenAsLast) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertChildrenAsLast(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildrenAsLast_Offset, children, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::InsertChildrenAsLast(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildrenAsLast) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertChildrenAsLast(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildrenAsLast_Offset, children, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::InsertChildrenAt(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, Int position, const ConstDataPtr& branchId) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildrenAt) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertChildrenAt(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildrenAt_Offset, children, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::InsertChildrenAt(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, Int position, const ConstDataPtr& branchId) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_InsertChildrenAt) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_InsertChildrenAt(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_InsertChildrenAt_Offset, children, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::Replace(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& newObject) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_Replace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_Replace(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_Replace_Offset, newObject));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::Replace(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& newObject) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_Replace) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_Replace(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_Replace_Offset, newObject));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::Remove() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<HierarchyObjectRef<>>, HierarchyObjectRef<>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<HierarchyObjectRef<>>, HierarchyObjectRef<>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<HierarchyObjectRef<>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_Remove) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_Remove(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_Remove_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::Remove() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), HierarchyObjectRef<>, maxon::Result<HierarchyObjectRef<>>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), HierarchyObjectRef<>, maxon::Result<HierarchyObjectRef<>>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_Remove) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_Remove(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_Remove_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::RemoveChildren(const ConstDataPtr& branchId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_RemoveChildren) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_._HierarchyObjectInterface_RemoveChildren(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_RemoveChildren_Offset, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::RemoveChildren(const ConstDataPtr& branchId) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_RemoveChildren) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_._HierarchyObjectInterface_RemoveChildren(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_RemoveChildren_Offset, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::RemoveAllChildren() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_RemoveAllChildren) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	mt_._HierarchyObjectInterface_RemoveAllChildren(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_RemoveAllChildren_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::RemoveAllChildren() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_RemoveAllChildren) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	mt_._HierarchyObjectInterface_RemoveAllChildren(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_RemoveAllChildren_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::GetOwner() const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetOwner) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_GetOwner(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetOwner_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::GetFirstChild(const ConstDataPtr& branchId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetFirstChild) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_._HierarchyObjectInterface_GetFirstChild(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetFirstChild_Offset, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::GetLastChild(const ConstDataPtr& branchId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetLastChild) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_._HierarchyObjectInterface_GetLastChild(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetLastChild_Offset, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::GetChildAt(Int position, const ConstDataPtr& branchId) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetChildAt) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_._HierarchyObjectInterface_GetChildAt(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetChildAt_Offset, position, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::GetChildren(const ConstDataPtr& branchId) const -> Result<BaseArray<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetChildren) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_._HierarchyObjectInterface_GetChildren(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetChildren_Offset, branchId));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::GetBranches() const -> Result<BaseArray<ConstDataPtr>>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<BaseArray<ConstDataPtr>>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetBranches) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_GetBranches(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetBranches_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::GetBranchId() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ConstDataPtr>, ConstDataPtr>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ConstDataPtr>, ConstDataPtr>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<ConstDataPtr>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetBranchId) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_GetBranchId(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetBranchId_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::SetLocking(const Bool locking) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_SetLocking) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	mt_._HierarchyObjectInterface_SetLocking(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_SetLocking_Offset, locking);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::SetLocking(const Bool locking) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_SetLocking) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	mt_._HierarchyObjectInterface_SetLocking(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_SetLocking_Offset, locking);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::IsLocked() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_IsLocked) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_IsLocked(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_IsLocked_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::GetParent() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetParent) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_._HierarchyObjectInterface_GetParent(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetParent_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::GetNext() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetNext) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_._HierarchyObjectInterface_GetNext(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetNext_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::GetPrev() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetPrev) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_._HierarchyObjectInterface_GetPrev(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetPrev_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::GetFirst() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<Interface>::type>, typename HIERARCHY_::template Sibling<Interface>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<Interface>::type>, typename HIERARCHY_::template Sibling<Interface>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Sibling<Interface>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetFirst) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_._HierarchyObjectInterface_GetFirst(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetFirst_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::GetLast() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<Interface>::type>, typename HIERARCHY_::template Sibling<Interface>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<Interface>::type>, typename HIERARCHY_::template Sibling<Interface>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<typename HIERARCHY_::template Sibling<Interface>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_GetLast) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return maxon::GenericReinterpretCast<typename ReturnHelper::ReturnType>(mt_._HierarchyObjectInterface_GetLast(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_GetLast_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ReferenceFunctionsImpl<S, HIERARCHY_>::ParentChanged(Bool removed) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_ParentChanged) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	mt_._HierarchyObjectInterface_ParentChanged(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_ParentChanged_Offset, removed);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::COWReferenceFunctionsImpl<S, HIERARCHY_>::ParentChanged(Bool removed) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); HierarchyObjectInterface* o_ = (HierarchyObjectInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_ParentChanged) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	mt_._HierarchyObjectInterface_ParentChanged(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_ParentChanged_Offset, removed);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::FindNextLeaf(const HierarchyObjectInterface* stopAtParent) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<std::add_pointer<HierarchyObjectInterface>::type>, std::add_pointer<HierarchyObjectInterface>::type>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<std::add_pointer<HierarchyObjectInterface>::type>, std::add_pointer<HierarchyObjectInterface>::type>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::PrivateNullReturnValue<std::add_pointer<HierarchyObjectInterface>::type>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_FindNextLeaf) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_FindNextLeaf(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_FindNextLeaf_Offset, stopAtParent));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::ObservableHierarchyInsert() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableHierarchyInsertDelegate>>, maxon::ObservableRef<ObservableHierarchyInsertDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableHierarchyInsertDelegate>>, maxon::ObservableRef<ObservableHierarchyInsertDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableHierarchyInsertDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_ObservableHierarchyInsert) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_ObservableHierarchyInsert(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_ObservableHierarchyInsert_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::DeprecatedObservableHierarchyInsert() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<DeprecatedObservableHierarchyInsertDelegate>>, maxon::ObservableRef<DeprecatedObservableHierarchyInsertDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<DeprecatedObservableHierarchyInsertDelegate>>, maxon::ObservableRef<DeprecatedObservableHierarchyInsertDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<DeprecatedObservableHierarchyInsertDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_DeprecatedObservableHierarchyInsert) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_DeprecatedObservableHierarchyInsert(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_DeprecatedObservableHierarchyInsert_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::ObservableHierarchyRemove() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableHierarchyRemoveDelegate>>, maxon::ObservableRef<ObservableHierarchyRemoveDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableHierarchyRemoveDelegate>>, maxon::ObservableRef<ObservableHierarchyRemoveDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<ObservableHierarchyRemoveDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_ObservableHierarchyRemove) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_ObservableHierarchyRemove(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_ObservableHierarchyRemove_Offset));
}
template <typename S, typename HIERARCHY_> MAXON_ATTRIBUTE_FORCE_INLINE auto HierarchyObjectInterface::Hxx1::ConstReferenceFunctionsImpl<S, HIERARCHY_>::DeprecatedObservableHierarchyRemove() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<DeprecatedObservableHierarchyRemoveDelegate>>, maxon::ObservableRef<DeprecatedObservableHierarchyRemoveDelegate>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<DeprecatedObservableHierarchyRemoveDelegate>>, maxon::ObservableRef<DeprecatedObservableHierarchyRemoveDelegate>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const HierarchyObjectInterface* o_ = (const HierarchyObjectInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = HierarchyObjectInterface::NullValuePtr(); if (!o_) return maxon::ObservableRef<DeprecatedObservableHierarchyRemoveDelegate>::NullValue(); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(HierarchyObjectInterface, o_, HierarchyObjectInterface_DeprecatedObservableHierarchyRemove) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<HierarchyObjectInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<HierarchyObjectInterface>() : PRIVATE_MAXON_VTABLE(HierarchyObjectInterface, o_); 
	return (mt_._HierarchyObjectInterface_DeprecatedObservableHierarchyRemove(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._HierarchyObjectInterface_DeprecatedObservableHierarchyRemove_Offset));
}
auto HierarchyObjectInterface::GetPtr() -> Ptr { return Ptr(this); }
auto HierarchyObjectInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

