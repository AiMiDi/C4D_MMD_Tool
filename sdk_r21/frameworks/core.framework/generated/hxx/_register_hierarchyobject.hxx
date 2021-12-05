#if 1
namespace maxon
{
	const maxon::Char* const HierarchyObjectInterface::MTable::_ids = 
		"InsertBefore@62454b3823c81bf2\0" // Result<void> InsertBefore(const typename HIERARCHY::template Sibling<Interface>::type& nextSibling)
		"InsertAfter@62454b3823c81bf2\0" // Result<void> InsertAfter(const typename HIERARCHY::template Sibling<Interface>::type& prevSibling)
		"InsertAsFirstChildOf@102e044c15f5ab6e\0" // Result<void> InsertAsFirstChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId)
		"InsertAsLastChildOf@102e044c15f5ab6e\0" // Result<void> InsertAsLastChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId)
		"InsertAsChildAt@ea13e24df06f9311\0" // Result<void> InsertAsChildAt(const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId)
		"InsertChildAsFirst@102e044c15f5ab6e\0" // Result<void> InsertChildAsFirst(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId)
		"InsertChildAsLast@102e044c15f5ab6e\0" // Result<void> InsertChildAsLast(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId)
		"InsertChildAt@ea13e24df06f9311\0" // Result<void> InsertChildAt(const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId)
		"InsertChildrenAsFirst@86618450ea9ca0ec\0" // Result<void> InsertChildrenAsFirst(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId)
		"InsertChildrenAsLast@86618450ea9ca0ec\0" // Result<void> InsertChildrenAsLast(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId)
		"InsertChildrenAt@1acb74f98583998f\0" // Result<void> InsertChildrenAt(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId)
		"Replace@62454b3823c81bf2\0" // Result<void> Replace(const typename HIERARCHY::template Sibling<Interface>::type& newObject)
		"Remove@0a69c52cd1f871c4\0" // HierarchyObjectRef<> Remove()
		"RemoveChildren@073ee856ce7033e4\0" // typename HIERARCHY::template Child<Interface>::type RemoveChildren(const ConstDataPtr& branchId)
		"RemoveAllChildren@6b2e10f\0" // void RemoveAllChildren()
		"GetOwner@0499ab95441128ac\0" // Result<Data> GetOwner() const
		"GetFirstChild@e09e2282ff9648d6\0" // typename HIERARCHY::template Child<Interface>::type GetFirstChild(const ConstDataPtr& branchId) const
		"GetLastChild@e09e2282ff9648d6\0" // typename HIERARCHY::template Child<Interface>::type GetLastChild(const ConstDataPtr& branchId) const
		"GetChildAt@6e9146707db92093\0" // typename HIERARCHY::template Child<Interface>::type GetChildAt(Int position, const ConstDataPtr& branchId) const
		"GetChildren@a322b1e0ff7d4a03\0" // Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>> GetChildren(const ConstDataPtr& branchId) const
		"GetBranches@ecbe4fa81642600b\0" // Result<BaseArray<ConstDataPtr>> GetBranches() const
		"GetParent@42cee06d6d15c6f6\0" // typename HIERARCHY::template Parent<Interface>::type GetParent() const
		"GetNext@42cee06d6d15c6f6\0" // typename HIERARCHY::template Sibling<Interface>::type GetNext() const
		"GetPrev@42cee06d6d15c6f6\0" // typename HIERARCHY::template Sibling<Interface>::type GetPrev() const
		"ParentChanged@5e65c14d7099\0" // void ParentChanged(Bool removed)
		"ObservableHierarchyInsert@5951a8412a632934\0" // maxon::ObservableRef<ObservableHierarchyInsertDelegate> ObservableHierarchyInsert() const
		"ObservableHierarchyRemove@385aebd11063f689\0" // maxon::ObservableRef<ObservableHierarchyRemoveDelegate> ObservableHierarchyRemove() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(HierarchyObjectInterface, , "net.maxon.interface.hierarchyobject", "maxon.HierarchyObjectInterface", (&ObserverObjectInterface::_interface));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(HierarchyObjectClass, , "net.maxon.class.hierarchyobject");
}
#endif
