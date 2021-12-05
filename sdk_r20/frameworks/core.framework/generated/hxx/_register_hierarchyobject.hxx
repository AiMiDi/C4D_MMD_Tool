#if 1
namespace maxon
{
	MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(HierarchyObjectInterface, "net.maxon.interface.hierarchyobject", "maxon.HierarchyObjectInterface", , &ObserverObjectInterface::_interface);
	const maxon::Char* const HierarchyObjectInterface::MTable::_ids = 
		"InsertBefore@62454b3823c81bf2\0" // InsertBefore(const HierarchyObjectRef& nextSibling)
		"InsertAfter@62454b3823c81bf2\0" // InsertAfter(const HierarchyObjectRef& prevSibling)
		"InsertAsFirstChildOf@102e044c15f5ab6e\0" // InsertAsFirstChildOf(const HierarchyObjectRef& parent, const ConstDataPtr& branchId)
		"InsertAsLastChildOf@102e044c15f5ab6e\0" // InsertAsLastChildOf(const HierarchyObjectRef& parent, const ConstDataPtr& branchId)
		"InsertAsChildAt@ea13e24df06f9311\0" // InsertAsChildAt(const HierarchyObjectRef& parent, Int position, const ConstDataPtr& branchId)
		"InsertChildAsFirst@102e044c15f5ab6e\0" // InsertChildAsFirst(const HierarchyObjectRef& child, const ConstDataPtr& branchId)
		"InsertChildAsLast@102e044c15f5ab6e\0" // InsertChildAsLast(const HierarchyObjectRef& child, const ConstDataPtr& branchId)
		"InsertChildAt@ea13e24df06f9311\0" // InsertChildAt(const HierarchyObjectRef& child, Int position, const ConstDataPtr& branchId)
		"InsertChildrenAsFirst@86618450ea9ca0ec\0" // InsertChildrenAsFirst(const BaseArray<HierarchyObjectRef>& children, const ConstDataPtr& branchId)
		"InsertChildrenAsLast@86618450ea9ca0ec\0" // InsertChildrenAsLast(const BaseArray<HierarchyObjectRef>& children, const ConstDataPtr& branchId)
		"InsertChildrenAt@1acb74f98583998f\0" // InsertChildrenAt(const BaseArray<HierarchyObjectRef>& children, Int position, const ConstDataPtr& branchId)
		"Replace@62454b3823c81bf2\0" // Replace(const HierarchyObjectRef& newObject)
		"Remove@0a69c52cd1f871c4\0" // Remove()
		"RemoveChildren@073ee856ce7033e4\0" // RemoveChildren(const ConstDataPtr& branchId)
		"RemoveAllChildren@6b2e10f\0" // RemoveAllChildren()
		"GetOwner@0499ab95441128ac\0" // GetOwner() const
		"GetFirstChild@e09e2282ff9648d6\0" // GetFirstChild(const ConstDataPtr& branchId) const
		"GetLastChild@e09e2282ff9648d6\0" // GetLastChild(const ConstDataPtr& branchId) const
		"GetChildAt@6e9146707db92093\0" // GetChildAt(Int position, const ConstDataPtr& branchId) const
		"GetChildren@a322b1e0ff7d4a03\0" // GetChildren(const ConstDataPtr& branchId) const
		"GetBranches@ecbe4fa81642600b\0" // GetBranches() const
		"GetParent@42cee06d6d15c6f6\0" // GetParent() const
		"GetNext@42cee06d6d15c6f6\0" // GetNext() const
		"GetPrev@42cee06d6d15c6f6\0" // GetPrev() const
		"ParentChanged@5e65c14d7099\0" // ParentChanged(Bool removed)
		"ObservableHierarchyInsert@5951a8412a632934\0" // ObservableHierarchyInsert() const
		"ObservableHierarchyRemove@385aebd11063f689\0" // ObservableHierarchyRemove() const
	"";
	template <typename DUMMY> maxon::Int HierarchyObjectInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<HierarchyObjectRef>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(HierarchyObjectClass, , "net.maxon.class.hierarchyobject");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_hierarchyobject(0
	| maxon::HierarchyObjectInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
