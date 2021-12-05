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
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="InsertBefore@c3fe8c32c67820f6"->"InsertBefore@62454b3823c81bf2"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertBefore(const typename HIERARCHY::template Sibling<Interface>::type& nextSibling);

	//----------------------------------------------------------------------------------------
	/// Inserts this object (including its children and next siblings, if any) into the hierarchy as the next sibling of prevSibling.
	/// prevSibling gets the ownership of this object.
	///
	/// This object mustn't have a parent or a previous sibling.
	/// @param[in] prevSibling				Another object of which this object shall become the next sibling.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="InsertAfter@c3fe8c32c67820f6"->"InsertAfter@62454b3823c81bf2"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertAfter(const typename HIERARCHY::template Sibling<Interface>::type& prevSibling);

	//----------------------------------------------------------------------------------------
	/// Insert this object (including its children and next siblings, if any) as the first child of the given parent object.
	/// The parent object gets the ownership of this object.
	///
	/// This object mustn't have a parent or a previous sibling.
	/// @param[in] parent							Parent object under which the object should be inserted.
	/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="InsertAsFirstChildOf@f9dc7b22971a5d68"->"InsertAsFirstChildOf@102e044c15f5ab6e"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertAsFirstChildOf(const typename HIERARCHY::template Parent<Interface>::type& parent, const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Insert this object (including its children and next siblings, if any) as the last child of the given parent object.
	/// If there are already children existing in the given branch the last one will get ownership of this object.
	/// Otherwise the parent object gets the ownership of this object.
	///
	/// This object mustn't have a parent or a previous sibling.
	/// @param[in] parent							Parent object under which the object should be inserted.
	/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="InsertAsLastChildOf@f9dc7b22971a5d68"->"InsertAsLastChildOf@102e044c15f5ab6e"}
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
	/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="InsertAsChildAt@d7661a010b96b80b"->"InsertAsChildAt@ea13e24df06f9311"}
	//----------------------------------------------------------------------------------------
	[[deprecated("Use InsertChildAt")]] MAXON_METHOD Result<void> InsertAsChildAt(const typename HIERARCHY::template Parent<Interface>::type& parent, Int position, const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Insert a child object (including its children and next siblings, if any) as the first child of this object.
	/// This object gets the ownership of the given child.
	///
	/// The child object mustn't have a parent or a previous sibling.
	/// @param[in] child							Parent object under which the object should be inserted.
	/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="InsertChildAsFirst@78cfce42ca9ca78c"->"InsertChildAsFirst@102e044c15f5ab6e"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertChildAsFirst(const typename HIERARCHY::template Child<Interface>::type& child, const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Insert a child object (including its children and next siblings, if any) as the last child of this object.
	/// If there are already children existing in the given branch the last one will get ownership of the given child object.
	/// Otherwise this object gets the ownership of the given child.
	///
	/// The child object mustn't have a parent or a previous sibling.
	/// @param[in] child							Parent object under which the object should be inserted.
	/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="InsertChildAsLast@78cfce42ca9ca78c"->"InsertChildAsLast@102e044c15f5ab6e"}
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
	/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="InsertChildAt@383db2fbc2df502f"->"InsertChildAt@ea13e24df06f9311"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertChildAt(const typename HIERARCHY::template Child<Interface>::type& child, Int position, const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Insert a list of child objects (including its children and next siblings, if any) as the first child of this object.
	/// This object gets the ownership of the given children.
	///
	/// Each child object mustn't have a parent or a previous sibling.
	/// @param[in] children						Parent object under which the object should be inserted.
	/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="InsertChildrenAsFirst@07fadb8f8931912e"->"InsertChildrenAsFirst@86618450ea9ca0ec"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertChildrenAsFirst(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Insert a list of child objects (including its children and next siblings, if any) as the last child of this object.
	/// If there are already children existing in the given branch the last one will get ownership of the given children objects.
	/// Otherwise this object gets the ownership of the given children.
	///
	/// Each child object mustn't have a parent or a previous sibling.
	/// @param[in] children						Parent object under which the object should be inserted.
	/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="InsertChildrenAsLast@07fadb8f8931912e"->"InsertChildrenAsLast@86618450ea9ca0ec"}
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
	/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	/// @return												OK on success.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="InsertChildrenAt@f553b7ebf3c298d1"->"InsertChildrenAt@1acb74f98583998f"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> InsertChildrenAt(const Block<const typename HIERARCHY::template Child<Interface>::type>& children, Int position, const ConstDataPtr& branchId = ConstDataPtr());


	//----------------------------------------------------------------------------------------
	/// Replace this object with the new one and remove it from the hierarchy.
	/// The new object will have the same prev/next siblings and descendants like this object.
	/// @return												This object including the descendants hierarchy.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="Replace@c3fe8c32c67820f6"->"Replace@62454b3823c81bf2"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Replace(const typename HIERARCHY::template Sibling<Interface>::type& newObject);

	//----------------------------------------------------------------------------------------
	/// Remove this object from the hierarchy, including all descendants.
	/// @return												This object including the descendants hierarchy.
	/// @MAXON_ANNOTATION{methodId="Remove@170d2d4035a37642"->"Remove@0a69c52cd1f871c4"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD HierarchyObjectRef<> Remove();

	//----------------------------------------------------------------------------------------
	/// Remove all descendants from the given branch hierarchy.
	/// The descendants hierarchy is returned as a reference which has the ownership of the descendants.
	/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	/// @return												Descendants hierarchy.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="RemoveChildren@f2c30f6fa85ad950"->"RemoveChildren@073ee856ce7033e4"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type RemoveChildren(const ConstDataPtr& branchId = ConstDataPtr());

	//----------------------------------------------------------------------------------------
	/// Remove all descendants from the hierarchy.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void RemoveAllChildren();

	//----------------------------------------------------------------------------------------
	/// Returns the owner of this object (and the whole hierarchy).
	/// @return												Owner of hierarchy.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Data> GetOwner() const;

	//----------------------------------------------------------------------------------------
	/// Returns the first child of this object.
	/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	/// @return												Child object or nullptr if not available.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="GetFirstChild@659ede85630050ea"->"GetFirstChild@e09e2282ff9648d6"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type GetFirstChild(const ConstDataPtr& branchId = ConstDataPtr()) const;

	//----------------------------------------------------------------------------------------
	/// Returns the last child of this object.
	/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	/// @return												Child object or nullptr if not available.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="GetLastChild@659ede85630050ea"->"GetLastChild@e09e2282ff9648d6"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type GetLastChild(const ConstDataPtr& branchId = ConstDataPtr()) const;

	//----------------------------------------------------------------------------------------
	/// Returns the n'th child of this object.
	/// @param[in] position						The child position.
	/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	/// @return												Child object or nullptr if not available.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="GetChildAt@ccf5aa5f8df8fea7"->"GetChildAt@6e9146707db92093"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD typename HIERARCHY::template Child<Interface>::type GetChildAt(Int position, const ConstDataPtr& branchId = ConstDataPtr()) const;

	//----------------------------------------------------------------------------------------
	/// Returns all children of the given hierarchy.
	/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="GetChildren@82b1e42d9879cc5d"->"GetChildren@a322b1e0ff7d4a03"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<typename HIERARCHY::template Child<Interface>::type>> GetChildren(const ConstDataPtr& branchId = ConstDataPtr()) const;

	//----------------------------------------------------------------------------------------
	/// Returns all branches of the given hierarchy.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<BaseArray<ConstDataPtr>> GetBranches() const;

	//----------------------------------------------------------------------------------------
	/// Returns the parent of this object.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="GetParent@039201505769407c"->"GetParent@42cee06d6d15c6f6"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD typename HIERARCHY::template Parent<Interface>::type GetParent() const;

	//----------------------------------------------------------------------------------------
	/// Returns the next sibling of this object.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="GetNext@13c3e32f7298ccfc"->"GetNext@42cee06d6d15c6f6"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD typename HIERARCHY::template Sibling<Interface>::type GetNext() const;

	//----------------------------------------------------------------------------------------
	/// Returns the previous sibling of this object.
	/// @MAXON_ANNOTATION{interfaceParameter=Interface, methodId="GetPrev@13c3e32f7298ccfc"->"GetPrev@42cee06d6d15c6f6"}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD typename HIERARCHY::template Sibling<Interface>::type GetPrev() const;

	//----------------------------------------------------------------------------------------
	/// Is invoked whenever the parent of this object changes. This method can be overridden
	/// when special actions have to be taken on such a change, for example the update of an
	/// underlying hierarchy which has to be kept in sync with this hierarchy.
	///
	/// This method must not be invoked by user code.
	/// @param[in] removed						Flag if the object has been removed (true) or inserted (false).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void ParentChanged(Bool removed);

	//----------------------------------------------------------------------------------------
	/// ObservableHierarchyInsert is sent whenever an object was inserted in the hierarchy.
	/// @param[in] sender							Sender object.
	/// @param[in] object							HierarchyObject which was added.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(Result<void>, ObservableHierarchyInsert, (const HierarchyObjectRef<>& sender, const HierarchyObjectRef<>& object), ObservableCombinerRunAllComponent);

	//----------------------------------------------------------------------------------------
	/// ObservableHierarchyRemove is sent whenever an object was removed from the hierarchy.
	/// @param[in] sender							Sender object.
	/// @param[in] object							HierarchyObject which was removed.
	//----------------------------------------------------------------------------------------
	MAXON_OBSERVABLE(Result<void>, ObservableHierarchyRemove, (const HierarchyObjectRef<>& sender, const HierarchyObjectRef<>& object), ObservableCombinerRunAllComponent);
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

	HierarchyObjectRef<> FindNextLeaf(const HierarchyObjectRef<>& last)
	{
		HierarchyObjectRef<> ref = last;

		if (ref.GetFirstChild()) // first check down branch
		{
			return ref.GetFirstChild();
		}
		else if (ref.GetNext()) // then check next branch
		{
			return ref.GetNext();
		}
		else // try the neighbor branch
		{
			do
			{
				ref = ref.GetParent();
				if (!ref)
					break;

				if (ref.GetPointer() == _parent.GetPointer())
					break; // topmost possible level reached

				if (ref.GetNext())
					return ref.GetNext();
			}
			while (ref);
		}

		return HierarchyObjectRef<>(); // no leaf left
	}

	explicit HierarchyObjectIterator(const HierarchyObjectRef<>& first)
	{
		_parent = first.GetParent(); // store first parent to later limit the highest possible tree level when searching for a neighbour tree

		for (HierarchyObjectRef<> ref = first; ref; ref = FindNextLeaf(ref))
		{
			if (ref.IsInstanceOf<REFTYPE>()) // filter
			{
				_last = Cast<REFTYPE>(ref);
				return;
			}
		}

		_last = nullptr;
		_parent = nullptr;
	}

	void operator ++()
	{
		for (HierarchyObjectRef<> ref = FindNextLeaf(_last); ref; ref = FindNextLeaf(ref))
		{
			if (ref.IsInstanceOf<REFTYPE>()) // filter
			{
				_last = Cast<REFTYPE>(ref);
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
static Result<Bool> TraverseChildren(const REFTYPE& t, const ConstDataPtr& branch,
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
static Result<Bool> TraverseMeAndChildren(const REFTYPE& t, const REFTYPE& parent, const ConstDataPtr& branch,
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
