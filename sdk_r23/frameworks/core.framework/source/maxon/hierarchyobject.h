#ifndef HIERARCHYOBJECT_H__
#define HIERARCHYOBJECT_H__

#include "maxon/observerobject.h"
#include "maxon/foreach.h"

namespace maxon
{

template <typename REF> struct DefaultHierarchy
{
	using type = REF;
	template <typename I> using Sibling = DefaultHierarchy;
	template <typename I> using Parent = DefaultHierarchy;
	template <typename I> using Child = DefaultHierarchy;
};

template <typename HIERARCHY = DefaultHierarchy<void>> class HierarchyObjectRef;

template <> struct DefaultHierarchy<void>
{
	using type = HierarchyObjectRef<>;
	template <typename I> using Sibling = DefaultHierarchy;
	template <typename I> using Parent = DefaultHierarchy;
	template <typename I> using Child = DefaultHierarchy;
};

template <typename REFTYPE> class HierarchyObjectIterator;

//----------------------------------------------------------------------------------------
/// Object that allows to create hierarchical tree like structures.
///
/// An object can have siblings and branches with children. By default the children are all stored in the default branch branchId == ConstDataPtr().
/// But you can add as many branches to categorize and separate different flavors of children.
/// You can do this by defining different branches like in this example:
/// @code
/// enum class IMAGEHIERARCHY
/// {
/// 	TEXTURE, ///< Root of everything. Must not be used with AddChildren.
/// 	IMAGE,	   ///< Adds a subImage to a texture. Images are only allowed under Textures.
/// 	ALPHA,	   ///< Adds an alpha to a image. Alphas are allowed to insert under images.
/// 	LAYER,	   ///< Adds an image layer to a image. Layers are only allowed under Images or other layers.
/// 	MASK,		 ///< Adds a layer mask to a layer. Layer masks are allowed to insert under layers (layer mask).
/// 	MAX_ELEMENTS,
/// } MAXON_ENUM_LIST(IMAGEHIERARCHY);
/// @endcode
///
/// You can then pass the branch to one of the functions below by replacing the default ConstDataPtr() by a different id.
/// This example will return the first child of IMAGEHIERARCHY::IMAGE branch.
/// @code
/// HierarchyObjectRef child = object.GetFirstChild(ConstDataPtr(IMAGEHIERARCHY::IMAGE))
/// @endcode
//---------------------------------------------------------------------------------------
class HierarchyObjectInterface : MAXON_INTERFACE_BASES(ObserverObjectInterface)
{
	MAXON_INTERFACE(HierarchyObjectInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.hierarchyobject");
	MAXON_GENERIC(typename HIERARCHY = DefaultHierarchy<void>);

public:

	//----------------------------------------------------------------------------------------
	/// Inserts this object (including its children and next siblings, if any) into the hierarchy as the previous sibling of nextSibling.
	/// Before invocation, nextSibling needs to have either a previous sibling or a parent object,
	/// which will get the ownership of this object. This object will take over the ownership of nextSibling.
	///
	/// This object mustn't have a parent or a previous sibling.
	/// @param[in] nextSibling				An object which shall become the next sibling of this object.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertBefore(const typename HIERARCHY::template Sibling<Interface>::type& nextSibling);

	//----------------------------------------------------------------------------------------
	/// Inserts this object (including its children and next siblings, if any) into the hierarchy as the next sibling of prevSibling.
	/// prevSibling gets the ownership of this object.
	///
	/// This object mustn't have a parent or a previous sibling.
	/// @param[in] prevSibling				Another object of which this object shall become the next sibling.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertAfter(const typename HIERARCHY::template Sibling<Interface>::type& prevSibling);

	//----------------------------------------------------------------------------------------
	/// Insert this object (including its children and next siblings, if any) as the first child of the given parent object.
	/// The parent object gets the ownership of this object.
	///
	/// This object mustn't have a parent or a previous sibling.
	/// @param[in] parent							Parent object under which the object should be inserted.
  /// @param[in] branchId           Defines the branch the child belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertAsFirstChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Insert this object (including its children and next siblings, if any) as the last child of the given parent object.
	/// If there are already children existing in the given branch the last one will get ownership of this object.
	/// Otherwise the parent object gets the ownership of this object.
	///
	/// This object mustn't have a parent or a previous sibling.
	/// @param[in] parent							Parent object under which the object should be inserted.
  /// @param[in] branchId           Defines the branch the child belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertAsLastChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Insert this object (including its children and next siblings, if any) as a child of the given parent position.
	/// For example if you specify a position of 3 and there are already 5 children existing the object will be inserted between the previously second and third child.
	/// If you specify a position of 1 the object will be inserted as the first child.
	///
	/// If a next sibling exists, this object gets ownership of the next sibling.
	/// If a previous sibling exists, the previous sibling gets the ownership of this object.
	/// Otherwise the parent object gets the ownership of this object.
	///
	/// This object mustn't have a parent or a previous sibling.
	/// @param[in] parent							Parent object under which the object should be inserted.
	/// @param[in] position						A child of parent which shall become the next sibling of this object, or nullptr if this object shall become the last child.
  /// @param[in] branchId           Defines the branch the child belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	[[deprecated("Use InsertChildAt")]] MAXON_METHOD Result<void> InsertAsChildAt(const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Insert a child object (including its children and next siblings, if any) as the first child of this object.
	/// This object gets the ownership of the given child.
	///
	/// The child object mustn't have a parent or a previous sibling.
	/// @param[in] child							Parent object under which the object should be inserted.
  /// @param[in] branchId            Defines the branch the children belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertChildAsFirst(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Insert a child object (including its children and next siblings, if any) as the last child of this object.
	/// If there are already children existing in the given branch the last one will get ownership of the given child object.
	/// Otherwise this object gets the ownership of the given child.
	///
	/// The child object mustn't have a parent or a previous sibling.
	/// @param[in] child							Parent object under which the object should be inserted.
  /// @param[in] branchId           Defines the branch the child belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertChildAsLast(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Insert a child object (including its children and next siblings, if any) as the given child position of this object.
	/// For example if you specify a position of 3 and there are already 5 children existing the child object will be inserted between the previously second and third child.
	/// If you specify a position of 1 the given child object will be inserted as the first child.
	///
	/// If a next sibling exists, the given child object gets ownership of the next sibling.
	/// If a previous sibling exists, the previous sibling gets the ownership of the given child object.
	/// Otherwise this object gets the ownership of the given child object.
	///
	/// The child object mustn't have a parent or a previous sibling.
	/// @param[in] child							Parent object under which the object should be inserted.
	/// @param[in] position						A child of parent which shall become the next sibling of this object, or nullptr if this object shall become the last child.
  /// @param[in] branchId           Defines the branch the child belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertChildAt(const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Insert a list of child objects (including its children and next siblings, if any) as the first child of this object.
	/// This object gets the ownership of the given children.
	///
	/// Each child object mustn't have a parent or a previous sibling.
	/// @param[in] children						Parent object under which the object should be inserted.
  /// @param[in] branchId           Defines the branch the children belong to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertChildrenAsFirst(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Insert a list of child objects (including its children and next siblings, if any) as the last child of this object.
	/// If there are already children existing in the given branch the last one will get ownership of the given children objects.
	/// Otherwise this object gets the ownership of the given children.
	///
	/// Each child object mustn't have a parent or a previous sibling.
	/// @param[in] children						Parent object under which the object should be inserted.
  /// @param[in] branchId           Defines the branch the children belong to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertChildrenAsLast(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Insert a list of children objects (including its children and next siblings, if any) as the given child position of this object.
	/// For example if you specify a position of 3 and there are already 5 children existing the children will be inserted between the previously second and third child.
	/// If you specify a position of 1 the given children will bbe inserted as the first child.
	///
	/// If a next sibling exists, the last children object gets ownership of the next sibling.
	/// If a previous sibling exists, the previous sibling gets the ownership of the given children objects.
	/// Otherwise this object gets the ownership of the given children.
	///
	/// Each child object mustn't have a parent or a previous sibling.
	/// @param[in] children						Parent object under which the object should be inserted.
	/// @param[in] position						A child of parent which shall become the next sibling of this object, or nullptr if this object shall become the last child.
  /// @param[in] branchId           Defines the branch the children belong to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertChildrenAt(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId = ConstDataPtr());


	//----------------------------------------------------------------------------------------
	/// Replace this object with the new one and remove it from the hierarchy.
	/// The new object will have the same prev/next siblings and descendants like this object.
	/// @return												This object including the descendants hierarchy.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Replace(const typename HIERARCHY::template Sibling<Interface>::type& newObject);

	//----------------------------------------------------------------------------------------
	/// Removes this object from the hierarchy, including all descendants.
	/// @return												This object including the descendants hierarchy.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD HierarchyObjectRef<> Remove();

	//----------------------------------------------------------------------------------------
	/// Removes all descendants from the given branch hierarchy.
	/// The descendants hierarchy is returned as a reference which has the ownership of the descendants.
	/// @param[in] branchId						Defines from which branch the children are removed.
	/// @return												Descendants hierarchy.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type RemoveChildren(const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Removes all descendants from the hierarchy including all branches.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void RemoveAllChildren();

	//----------------------------------------------------------------------------------------
	/// Returns the owner of this object (and the whole hierarchy).
	/// @return												Owner of hierarchy.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data> GetOwner() const;

	//----------------------------------------------------------------------------------------
	/// Returns the first child of this object.
  /// @param[in] branchId           The branch.
	/// @return												Child object or nullptr if not available.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type GetFirstChild(const ConstDataPtr& branchId = ConstDataPtr()) const;

	//----------------------------------------------------------------------------------------
	/// Returns the last child of this object.
  /// @param[in] branchId           The branch.
	/// @return												Child object or nullptr if not available.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type GetLastChild(const ConstDataPtr& branchId = ConstDataPtr()) const;

	//----------------------------------------------------------------------------------------
	/// Returns the n'th child of this object.
	/// @param[in] position						The child position.
  /// @param[in] branchId           The branch.
	/// @return												Child object or nullptr if not available.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type GetChildAt(Int position, const ConstDataPtr& branchId = ConstDataPtr()) const;

	//----------------------------------------------------------------------------------------
	/// Returns all children of the given hierarchy.
  /// @param[in] branchId           The branch.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>> GetChildren(const ConstDataPtr& branchId = ConstDataPtr()) const;

	//----------------------------------------------------------------------------------------
	/// Returns all branches of the given hierarchy.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<ConstDataPtr>> GetBranches() const;

  //----------------------------------------------------------------------------------------
  /// Returns the branch the object belongs to.
  //----------------------------------------------------------------------------------------
  MAXON_METHOD ConstDataPtr GetBranchId() const;

  //----------------------------------------------------------------------------------------
  /// Set the locking of an object.
  /// If the object is locked it cannot be removed or changed in the hierarchy.
  //----------------------------------------------------------------------------------------
  MAXON_METHOD void SetLocking(const Bool locking);

  //----------------------------------------------------------------------------------------
  /// Get the locking of an object.
  /// If the object is locked it cannot be removed or changed in the hierarchy.
  /// @return                        True if locked.
  //----------------------------------------------------------------------------------------
  MAXON_METHOD Bool IsLocked() const;

	//----------------------------------------------------------------------------------------
	/// Returns the parent of this object.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD typename HIERARCHY::template Parent<Interface>::type GetParent() const;

	//----------------------------------------------------------------------------------------
	/// Returns the next sibling of this object.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD typename HIERARCHY::template Sibling<Interface>::type GetNext() const;

	//----------------------------------------------------------------------------------------
	/// Returns the previous sibling of this object.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD typename HIERARCHY::template Sibling<Interface>::type GetPrev() const;

  //----------------------------------------------------------------------------------------
  /// Returns the first sibling of this chain.
  /// If the object is already the first element the object is returned;
  //----------------------------------------------------------------------------------------
  MAXON_METHOD typename HIERARCHY::template Sibling<Interface>::type GetFirst() const;

  //----------------------------------------------------------------------------------------
  /// Returns the last sibling of this chain.
  /// If the object is already the first element the object is returned;
  //----------------------------------------------------------------------------------------
  MAXON_METHOD typename HIERARCHY::template Sibling<Interface>::type GetLast() const;

	//----------------------------------------------------------------------------------------
	/// Is invoked whenever the parent of this object changes. This method can be overridden
	/// when special actions have to be taken on such a change, for example the update of an
	/// underlying hierarchy which has to be kept in sync with this hierarchy.
	///
	/// This method must not be invoked by user code.
	/// @param[in] removed						Flag if the object has been removed (true) or inserted (false).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void ParentChanged(Bool removed);

	MAXON_METHOD std::add_pointer<HierarchyObjectInterface>::type FindNextLeaf(const HierarchyObjectInterface* stopAtParent) const;

	//----------------------------------------------------------------------------------------
	/// ObservableHierarchyInsert is sent whenever an object was inserted in the hierarchy.
  /// <strong>Note</strong>: The children and siblings of the object are not sent as an observable!
	/// @param[in] sender							Sender object.
	/// @param[in] object							HierarchyObject which was added.
  /// @param[in] branchId           The branch the object belongs to.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(Result<void>, ObservableHierarchyInsert, (const HierarchyObjectRef<>& sender, const HierarchyObjectRef<>& object, const ConstDataPtr& branchId), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// ObservableHierarchyRemove is sent whenever an object was removed from the hierarchy.
  /// <strong>Note</strong>: The children of the object are not sent as an observable!
	/// @param[in] sender							Sender object.
	/// @param[in] object							HierarchyObject which was removed.
  /// @param[in] branchId           The branch the object belongs to.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(Result<void>, ObservableHierarchyRemove, (const HierarchyObjectRef<>& sender, const HierarchyObjectRef<>& object, const ConstDataPtr& branchId), ObservableCombinerRunAllComponent);
};

#include "hierarchyobject1.hxx"

MAXON_DECLARATION(Class<HierarchyObjectRef<>>, HierarchyObjectClass, "net.maxon.class.hierarchyobject");

#include "hierarchyobject2.hxx"


//----------------------------------------------------------------------------------------
/// Iterator Class to run through all the elements of a HierarchyObjectRef in a linear manner.
///
/// Example usage:
/// @code
/// for (const HierarchyObjectRef& it : HierarchyObjectIterator<HierarchyObjectRef>(rootObject))
/// {
///   // do something with it here
/// }
/// @endcode
///
/// Since the iterator is templated you can easily filter the hierarchy for certain types.
/// In this example OSWindowRef is (amongst others) derived from HierarchyObjectRef.
/// By passing the type <OSWindowRef> to the iterator you will get only these objects - no matter where they are located in the hierarchy.
///
/// @code
/// for (const OSWindowRef& it : HierarchyObjectIterator<OSWindowRef>(rootObject))
/// {
///   // do something with it here
/// }
/// @endcode
///
/// Please note that the HierarchyObjectIterator automatically gives you the correct typed object.
/// This saves you from manually checking for the correct type and the do a (potential risky) cast to the target type like in this (not recommended) example.
/// @code
/// for (const HierarchyObjectRef& it : HierarchyObjectIterator<HierarchyObjectRef>(rootObject))
/// {
///   if (it.IsInstanceOf<OSWindowRef>)
///   {
///			OSWindowRef window = Cast<OSWindowRef>(it);
///     // do something with window here
///   }
/// }
/// @endcode
///
//----------------------------------------------------------------------------------------
template <typename REFTYPE> class HierarchyObjectIterator : public ForEachIterator<HierarchyObjectIterator<REFTYPE>>
{
public:
	HierarchyObjectIterator()
	{
	}

	HierarchyObjectIterator(const HierarchyObjectIterator& src) : _last(src._last)
	{
	}

	HierarchyObjectIterator(HierarchyObjectIterator&& src) : _last(std::move(src._last))
	{
	}

	MAXON_OPERATOR_COPY_ASSIGNMENT(HierarchyObjectIterator);
	MAXON_OPERATOR_MOVE_ASSIGNMENT(HierarchyObjectIterator);

	explicit HierarchyObjectIterator(const HierarchyObjectRef<>& first)
	{
		_parent = first.GetParent(); // store first parent to later limit the highest possible tree level when searching for a neighbour tree

		for (HierarchyObjectInterface* ptr = first; ptr; ptr = ptr->FindNextLeaf(_parent))
		{
			if (ptr->IsInstanceOf<REFTYPE>()) // filter
			{
				HierarchyObjectRef<> ref = ptr;
				_last = std::move(reinterpret_cast<REFTYPE&&>(ref));
				return;
			}
		}

		_last = nullptr;
		_parent = nullptr;
	}

	void operator ++()
	{
		for (HierarchyObjectInterface* ptr = _last.FindNextLeaf(_parent); ptr; ptr = ptr->FindNextLeaf(_parent))
		{
			if (ptr->IsInstanceOf<REFTYPE>()) // filter
			{
				HierarchyObjectRef<> ref = ptr;
				_last = std::move(reinterpret_cast<REFTYPE&&>(ref));
				return;
			}
		}

		_last = nullptr;
		_parent = nullptr;
	}

	explicit operator Bool() const
	{
		return _last != nullptr;
	}

	REFTYPE& operator *()
	{
		return _last;
	}

	REFTYPE* operator ->()
	{
		return &_last;
	}

private:
	REFTYPE           	 _last;
	HierarchyObjectRef<> _parent;
};


//----------------------------------------------------------------------------------------
/// Helper function to traverse all children of the root object.
/// @code
///	MediaStreamRef stream; // object with hierarchy to run through
///	BaseArray<MediaStreamRef>	res;
/// TraverseChildren<MediaStreamRef>(stream,
///   [&res](const MediaStreamRef& child, const MediaStreamRef& parent, const ConstDataPtr& branch, Int depth) -> Result<Bool>
/// 	{
/// 		iferr_scope;
/// 		res.Append(child) iferr_return;
/// 		return true;
/// 	}) iferr_return;
/// @endcode
/// @param[in] object 						Object to iterate.
/// @param[in] function  					Function which is called for each object.
/// @param[in] branchId           The branch.
/// @param[in] depth              Start value for the depth level.
/// @return												returns false if iteration should stop. otherwise true to continue.
//----------------------------------------------------------------------------------------
template <typename REFTYPE>
static Result<Bool> TraverseChildren(const REFTYPE& object, const Delegate<Result<Bool>(const REFTYPE& object, const REFTYPE& parent, const ConstDataPtr& branchId, Int depth)>& function, const ConstDataPtr& branchId = ConstDataPtr(), Int depth = Int(0))
{
	iferr_scope;

	auto children = object.GetChildren(branchId) iferr_return;

	for (const auto& child : children)
	{
    Bool continueTraverse = function(Cast<REFTYPE>(child), object, branchId, depth) iferr_return;
    if (!continueTraverse)
      return false;

    continueTraverse = TraverseChildren(Cast<REFTYPE>(child), function, branchId, depth + Int(1)) iferr_return;
    if (!continueTraverse)
      return false;
	}
	return true;
}

//----------------------------------------------------------------------------------------
/// Helper function to traverse the given object with its children.
/// @code
///	MediaStreamRef stream; // object with hierarchy to run through
///	BaseArray<MediaStreamRef>	res;
/// TraverseMeAndChildren<MediaStreamRef>(stream,
///   [&res](const MediaStreamRef& child, const MediaStreamRef& parent, const ConstDataPtr& branch, Int depth) -> Result<Bool>
/// 	{
/// 		iferr_scope;
/// 		res.Append(child) iferr_return;
/// 		return true;
/// 	}) iferr_return;
/// @endcode
/// @param[in] object             Object to iterate.
/// @param[in] function           Function which is called for each object.
/// @param[in] branchId           The branch.
/// @param[in] depth              Start value for the depth level.
/// @return                       returns false if iteration should stop. otherwise true to continue.
//----------------------------------------------------------------------------------------
template <typename REFTYPE>
static Result<Bool> TraverseMeAndChildren(const REFTYPE& object, const Delegate<Result<Bool>(const REFTYPE& object, const REFTYPE& parent, const ConstDataPtr& branchId, Int depth)>& function, const ConstDataPtr& branchId = ConstDataPtr(), Int depth = Int(0))
{
	iferr_scope;

	Bool continueTraverse = function(object, Cast<REFTYPE>(object.GetParent()), branchId, depth) iferr_return;
	if (!continueTraverse)
		return false;

  return TraverseChildren(object, function, branchId, depth + Int(1));
}


//----------------------------------------------------------------------------------------
/// Helper function to traverse all children of the root object t.
/// @code
///	MediaStreamRef stream; // object with hierarchy to run through
///	BaseArray<MediaStreamRef>	res;
/// TraverseChildren<MediaStreamRef>(stream, ConstDataPtr(),
/// 	[&res](const MediaStreamRef& child, const MediaStreamRef& parent, const ConstDataPtr& branch, Int depth) -> Result<Bool>
/// 	{
/// 		iferr_scope;
/// 		res.Append(child) iferr_return;
/// 		return true;
/// 	}, 0) iferr_return;
/// @endcode
/// @param[in] t									object to iterate.
/// @param[in] func								function which is called for each object.
/// @return												returns false if iteration should stop. otherwise true to continue.
//----------------------------------------------------------------------------------------
template <typename REFTYPE>
[[deprecated("Use the other overload")]] static Result<Bool> TraverseChildren(const REFTYPE& t, const ConstDataPtr& branch,
	const Delegate<Result<Bool>(const REFTYPE& child, const REFTYPE& parent, const ConstDataPtr& branch, Int depth)>& func, Int depth)
{
	iferr_scope;

	auto children = t.GetChildren(branch) iferr_return;

	for (const auto& child : children)
	{
		Bool continueTraverse = TraverseMeAndChildren(Cast<REFTYPE>(child), t, branch, func, depth + 1) iferr_return;
		if (!continueTraverse)
			return false;
	}
	return true;
}

//----------------------------------------------------------------------------------------
/// Helper function to traverse all children of the root object t, but also the given object.
/// @code
///	MediaStreamRef stream; // object with hierarchy to run through
///	BaseArray<MediaStreamRef>	res;
/// TraverseMeAndChildren<MediaStreamRef>(stream, MediaStreamRef(), ConstDataPtr(),
/// 	[&res](const MediaStreamRef& child, const MediaStreamRef& parent, const ConstDataPtr& branch, Int depth) -> Result<Bool>
/// 	{
/// 		iferr_scope;
/// 		res.Append(child) iferr_return;
/// 		return true;
/// 	}) iferr_return;
/// @endcode
/// @param[in] t									object to iterate.
/// @param[in] func								function which is called for each object.
/// @return												returns false if iteration should stop. otherwise true to continue.
//----------------------------------------------------------------------------------------
template <typename REFTYPE>
[[deprecated("Use the other overload")]] static Result<Bool> TraverseMeAndChildren(const REFTYPE& t, const REFTYPE& parent, const ConstDataPtr& branch,
	const Delegate<Result<Bool>(const REFTYPE& child, const REFTYPE& parent, const ConstDataPtr& branch, Int depth)>& func, Int depth = 0)
{
	iferr_scope;

	Bool continueTraverse = func(t, parent, branch, depth) iferr_return;
	if (!continueTraverse)
		return false;

	BaseArray<ConstDataPtr> branches = t.GetBranches() iferr_return;
	for (const ConstDataPtr& b : branches)
	{
		continueTraverse = TraverseChildren(t, b, func, depth) iferr_return;
		if (!continueTraverse)
			return false;
	}

	return true;
}

}

#endif // HIERARCHYOBJECT_H__
