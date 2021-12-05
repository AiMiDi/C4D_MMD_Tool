// This file contains decorator implementations for the interfaces of hierarchyobject.h. They are intended for copy&paste usage only.

class HierarchyObjectDecoratorImpl : public maxon::Component<HierarchyObjectDecoratorImpl, HierarchyObjectInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InsertBefore(const typename HIERARCHY::template Sibling<Interface>::type& nextSibling)
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).InsertBefore(nextSibling);
	}

	MAXON_METHOD Result<void> InsertAfter(const typename HIERARCHY::template Sibling<Interface>::type& prevSibling)
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).InsertAfter(prevSibling);
	}

	MAXON_METHOD Result<void> InsertAsFirstChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId)
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).InsertAsFirstChildOf(parent, branchId);
	}

	MAXON_METHOD Result<void> InsertAsLastChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId)
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).InsertAsLastChildOf(parent, branchId);
	}

	MAXON_METHOD Result<void> InsertAsChildAt(const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId)
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).InsertAsChildAt(parent, position, branchId);
	}

	MAXON_METHOD Result<void> InsertChildAsFirst(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId)
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).InsertChildAsFirst(child, branchId);
	}

	MAXON_METHOD Result<void> InsertChildAsLast(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId)
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).InsertChildAsLast(child, branchId);
	}

	MAXON_METHOD Result<void> InsertChildAt(const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId)
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).InsertChildAt(child, position, branchId);
	}

	MAXON_METHOD Result<void> InsertChildrenAsFirst(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId)
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).InsertChildrenAsFirst(children, branchId);
	}

	MAXON_METHOD Result<void> InsertChildrenAsLast(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId)
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).InsertChildrenAsLast(children, branchId);
	}

	MAXON_METHOD Result<void> InsertChildrenAt(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId)
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).InsertChildrenAt(children, position, branchId);
	}

	MAXON_METHOD Result<void> Replace(const typename HIERARCHY::template Sibling<Interface>::type& newObject)
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).Replace(newObject);
	}

	MAXON_METHOD HierarchyObjectRef<> Remove()
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).Remove();
	}

	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type RemoveChildren(const ConstDataPtr& branchId)
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).RemoveChildren(branchId);
	}

	MAXON_METHOD void RemoveAllChildren()
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).RemoveAllChildren();
	}

	MAXON_METHOD Result<Data> GetOwner() const
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).GetOwner();
	}

	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type GetFirstChild(const ConstDataPtr& branchId) const
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).GetFirstChild(branchId);
	}

	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type GetLastChild(const ConstDataPtr& branchId) const
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).GetLastChild(branchId);
	}

	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type GetChildAt(Int position, const ConstDataPtr& branchId) const
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).GetChildAt(position, branchId);
	}

	MAXON_METHOD Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>> GetChildren(const ConstDataPtr& branchId) const
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).GetChildren(branchId);
	}

	MAXON_METHOD Result<BaseArray<ConstDataPtr>> GetBranches() const
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).GetBranches();
	}

	MAXON_METHOD typename HIERARCHY::template Parent<Interface>::type GetParent() const
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).GetParent();
	}

	MAXON_METHOD typename HIERARCHY::template Sibling<Interface>::type GetNext() const
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).GetNext();
	}

	MAXON_METHOD typename HIERARCHY::template Sibling<Interface>::type GetPrev() const
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).GetPrev();
	}

	MAXON_METHOD void ParentChanged(Bool removed)
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).ParentChanged(removed);
	}

	MAXON_METHOD maxon::ObservableRef<ObservableHierarchyInsertDelegate> ObservableHierarchyInsert() const
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).ObservableHierarchyInsert();
	}

	MAXON_METHOD maxon::ObservableRef<ObservableHierarchyRemoveDelegate> ObservableHierarchyRemove() const
	{
		return maxon::Cast<HierarchyObjectRef>(self.GetDecoratedObject()).ObservableHierarchyRemove();
	}

};
