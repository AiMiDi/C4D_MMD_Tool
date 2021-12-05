// This file contains default implementations for the interfaces of hierarchyobject.h. They are intended for copy&paste usage only.

class MyHierarchyObjectImpl : public maxon::Component<MyHierarchyObjectImpl, HierarchyObjectInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InsertBefore(const typename HIERARCHY::template Sibling<Interface>::type& nextSibling)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertAfter(const typename HIERARCHY::template Sibling<Interface>::type& prevSibling)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertAsFirstChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertAsLastChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertAsChildAt(const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertChildAsFirst(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertChildAsLast(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertChildAt(const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertChildrenAsFirst(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertChildrenAsLast(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InsertChildrenAt(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Replace(const typename HIERARCHY::template Sibling<Interface>::type& newObject)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD HierarchyObjectRef<> Remove()
	{
		return maxon::PrivateNullReturnValue<HierarchyObjectRef<>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type RemoveChildren(const ConstDataPtr& branchId)
	{
		return maxon::PrivateNullReturnValue<typename HIERARCHY::template Child<Interface>::type>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void RemoveAllChildren()
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Result<Data> GetOwner() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type GetFirstChild(const ConstDataPtr& branchId) const
	{
		return maxon::PrivateNullReturnValue<typename HIERARCHY::template Child<Interface>::type>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type GetLastChild(const ConstDataPtr& branchId) const
	{
		return maxon::PrivateNullReturnValue<typename HIERARCHY::template Child<Interface>::type>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type GetChildAt(Int position, const ConstDataPtr& branchId) const
	{
		return maxon::PrivateNullReturnValue<typename HIERARCHY::template Child<Interface>::type>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>> GetChildren(const ConstDataPtr& branchId) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<BaseArray<ConstDataPtr>> GetBranches() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD typename HIERARCHY::template Parent<Interface>::type GetParent() const
	{
		return maxon::PrivateNullReturnValue<typename HIERARCHY::template Parent<Interface>::type>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD typename HIERARCHY::template Sibling<Interface>::type GetNext() const
	{
		return maxon::PrivateNullReturnValue<typename HIERARCHY::template Sibling<Interface>::type>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD typename HIERARCHY::template Sibling<Interface>::type GetPrev() const
	{
		return maxon::PrivateNullReturnValue<typename HIERARCHY::template Sibling<Interface>::type>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
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
