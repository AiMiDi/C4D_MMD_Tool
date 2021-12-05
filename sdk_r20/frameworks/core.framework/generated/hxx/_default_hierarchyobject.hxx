// This file contains default implementations for the interfaces of hierarchyobject.h. They are intended for copy&paste usage only.

class MyHierarchyObjectImpl : public Component<MyHierarchyObjectImpl, HierarchyObjectInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InsertBefore(const HierarchyObjectRef& nextSibling)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertAfter(const HierarchyObjectRef& prevSibling)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertAsFirstChildOf(const HierarchyObjectRef& parent, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertAsLastChildOf(const HierarchyObjectRef& parent, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertAsChildAt(const HierarchyObjectRef& parent, Int position, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertChildAsFirst(const HierarchyObjectRef& child, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertChildAsLast(const HierarchyObjectRef& child, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertChildAt(const HierarchyObjectRef& child, Int position, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertChildrenAsFirst(const BaseArray<HierarchyObjectRef>& children, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertChildrenAsLast(const BaseArray<HierarchyObjectRef>& children, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertChildrenAt(const BaseArray<HierarchyObjectRef>& children, Int position, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Replace(const HierarchyObjectRef& newObject)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD HierarchyObjectRef Remove()
	{
		return maxon::PrivateIncompleteNullReturnValue<HierarchyObjectRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD HierarchyObjectRef RemoveChildren(const ConstDataPtr& branchId)
	{
		return maxon::PrivateIncompleteNullReturnValue<HierarchyObjectRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void RemoveAllChildren()
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Result<Data> GetOwner() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD HierarchyObjectRef GetFirstChild(const ConstDataPtr& branchId) const
	{
		return maxon::PrivateIncompleteNullReturnValue<HierarchyObjectRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD HierarchyObjectRef GetLastChild(const ConstDataPtr& branchId) const
	{
		return maxon::PrivateIncompleteNullReturnValue<HierarchyObjectRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD HierarchyObjectRef GetChildAt(Int position, const ConstDataPtr& branchId) const
	{
		return maxon::PrivateIncompleteNullReturnValue<HierarchyObjectRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<BaseArray<HierarchyObjectRef>> GetChildren(const ConstDataPtr& branchId) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<BaseArray<ConstDataPtr>> GetBranches() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD HierarchyObjectRef GetParent() const
	{
		return maxon::PrivateIncompleteNullReturnValue<HierarchyObjectRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD HierarchyObjectRef GetNext() const
	{
		return maxon::PrivateIncompleteNullReturnValue<HierarchyObjectRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD HierarchyObjectRef GetPrev() const
	{
		return maxon::PrivateIncompleteNullReturnValue<HierarchyObjectRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void ParentChanged(Bool removed)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD maxon::ObservableRef<ObservableHierarchyInsertDelegate> ObservableHierarchyInsert() const
	{
		return maxon::ObservableRef<ObservableHierarchyInsertDelegate>::NullValue();
	}

	MAXON_METHOD maxon::ObservableRef<ObservableHierarchyRemoveDelegate> ObservableHierarchyRemove() const
	{
		return maxon::ObservableRef<ObservableHierarchyRemoveDelegate>::NullValue();
	}

};
