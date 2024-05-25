#if 1
namespace maxon
{
	const maxon::Char* const HierarchyObjectInterface::MTable::_ids = 
		"InsertBefore@15292b297590777f\0" // Result<void> InsertBefore(const typename HIERARCHY::template Sibling<Interface>::type& nextSibling)
		"InsertAfter@15292b297590777f\0" // Result<void> InsertAfter(const typename HIERARCHY::template Sibling<Interface>::type& prevSibling)
		"InsertAsFirstChildOf@4d4d507f68f77c65\0" // Result<void> InsertAsFirstChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId)
		"InsertAsLastChildOf@4d4d507f68f77c65\0" // Result<void> InsertAsLastChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId)
		"InsertAsChildAt@9c1ca531e7f03d78\0" // Result<void> InsertAsChildAt(const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId)
		"InsertChildAsFirst@90c13b36425a4893\0" // Result<void> InsertChildAsFirst(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId)
		"InsertChildAsLast@90c13b36425a4893\0" // Result<void> InsertChildAsLast(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId)
		"InsertChildAt@5bb02914c787723a\0" // Result<void> InsertChildAt(const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId)
		"InsertChildrenAsFirst@171cd1a63fd46849\0" // Result<void> InsertChildrenAsFirst(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId)
		"InsertChildrenAsLast@171cd1a63fd46849\0" // Result<void> InsertChildrenAsLast(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId)
		"InsertChildrenAt@de7195beb5df8704\0" // Result<void> InsertChildrenAt(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId)
		"Replace@15292b297590777f\0" // Result<void> Replace(const typename HIERARCHY::template Sibling<Interface>::type& newObject)
		"Remove@6e6803452669f0b7\0" // HierarchyObjectRef<> Remove()
		"RemoveChildren@a370486e34b8cd7f\0" // typename HIERARCHY::template Child<Interface>::type RemoveChildren(const ConstDataPtr& branchId)
		"RemoveAllChildren@780cdac8f1a33934\0" // void RemoveAllChildren()
		"GetFirstChild@b7f6be4a43eb239f\0" // typename HIERARCHY::template Child<Interface>::type GetFirstChild(const ConstDataPtr& branchId) const
		"GetLastChild@b7f6be4a43eb239f\0" // typename HIERARCHY::template Child<Interface>::type GetLastChild(const ConstDataPtr& branchId) const
		"GetChildAt@f790c33855f1192c\0" // typename HIERARCHY::template Child<Interface>::type GetChildAt(Int position, const ConstDataPtr& branchId) const
		"GetChildren@4860e3a46ec7f834\0" // Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>> GetChildren(const ConstDataPtr& branchId) const
		"GetBranches@d8ced65c68cc4f7c\0" // Result<BaseArray<ConstDataPtr>> GetBranches() const
		"GetBranchId@68a84da1826b8e5f\0" // ConstDataPtr GetBranchId() const
		"SetLocking@cc6b983dd2fdd2fd\0" // void SetLocking(const Bool locking)
		"IsLocked@12e73654e6d65520\0" // Bool IsLocked() const
		"GetParent@557f0f15b5bda8bd\0" // typename HIERARCHY::template Parent<Interface>::type GetParent() const
		"GetParentPtr@38288b97d6e36e21\0" // std::add_pointer<HierarchyObjectInterface>::type GetParentPtr() const
		"GetNext@ea4a7d79eae8dfd1\0" // typename HIERARCHY::template Sibling<Interface>::type GetNext() const
		"GetPrev@ea4a7d79eae8dfd1\0" // typename HIERARCHY::template Sibling<Interface>::type GetPrev() const
		"GetFirst@ea4a7d79eae8dfd1\0" // typename HIERARCHY::template Sibling<Interface>::type GetFirst() const
		"GetLast@ea4a7d79eae8dfd1\0" // typename HIERARCHY::template Sibling<Interface>::type GetLast() const
		"ParentChanged@add9409250097f0c\0" // void ParentChanged(Bool removed)
		"FindNextLeaf@1377ff1aa9342d1b\0" // std::add_pointer<HierarchyObjectInterface>::type FindNextLeaf(const HierarchyObjectInterface* stopAtParent) const
		"ObservableHierarchyInsert@f99738ffd79627b3\0" // maxon::ObservableRef<ObservableHierarchyInsertDelegate> ObservableHierarchyInsert(Bool create) const
		"ObservableHierarchyRemove@b46141dbbadf9b74\0" // maxon::ObservableRef<ObservableHierarchyRemoveDelegate> ObservableHierarchyRemove(Bool create) const
		"FlushBranches@780cdac8f1a33934\0" // void FlushBranches()
	"";
	const maxon::METHOD_FLAGS HierarchyObjectInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(HierarchyObjectInterface, , "net.maxon.interface.hierarchyobject", (ObserverObjectInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(HierarchyObjectClass, , "net.maxon.class.hierarchyobject");
}
#endif
