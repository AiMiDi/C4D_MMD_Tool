#if 1
struct HierarchyObjectInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, HierarchyObjectInterface>::value || ObserverObjectInterface::HasBase::Check<I>::value; static I* Cast(HierarchyObjectInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class HierarchyObjectRef;

struct HierarchyObjectInterface::ReferenceClassHelper { using type = HierarchyObjectRef; };

/// Intermediate helper class for HierarchyObjectInterface.
template <typename S> class HierarchyObjectInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Returns the owner of this object (and the whole hierarchy).
/// @return												Owner of hierarchy.
	inline Result<Data> GetOwner() const;
/// Returns the first child of this object.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												Child object or nullptr if not available.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<HierarchyObjectRef>, HierarchyObjectRef>::type GetFirstChild(const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Returns the last child of this object.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												Child object or nullptr if not available.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<HierarchyObjectRef>, HierarchyObjectRef>::type GetLastChild(const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Returns the n'th child of this object.
/// @param[in] position						The child position.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												Child object or nullptr if not available.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<HierarchyObjectRef>, HierarchyObjectRef>::type GetChildAt(Int position, const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Returns all children of the given hierarchy.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
	inline Result<BaseArray<HierarchyObjectRef>> GetChildren(const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Returns all branches of the given hierarchy.
	inline Result<BaseArray<ConstDataPtr>> GetBranches() const;
/// Returns the parent of this object.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<HierarchyObjectRef>, HierarchyObjectRef>::type GetParent() const;
/// Returns the next sibling of this object.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<HierarchyObjectRef>, HierarchyObjectRef>::type GetNext() const;
/// Returns the previous sibling of this object.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<HierarchyObjectRef>, HierarchyObjectRef>::type GetPrev() const;
/// ObservableHierarchyInsert is sent whenever an object was inserted in the hierarchy.
/// -param[in] sender							Sender object.
/// -param[in] object   					HierarchyObject which was added.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableHierarchyInsertDelegate>>, maxon::ObservableRef<ObservableHierarchyInsertDelegate>>::type ObservableHierarchyInsert() const;
/// ObservableHierarchyRemove is sent whenever an object was removed from the hierarchy.
/// -param[in] sender							Sender object.
/// -param[in] object							HierarchyObject which was removed.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableHierarchyRemoveDelegate>>, maxon::ObservableRef<ObservableHierarchyRemoveDelegate>>::type ObservableHierarchyRemove() const;
};
#ifdef DOXYGEN
template <typename REF> class HierarchyObjectInterface::ConstReferenceFunctionsImplDoxy : public HierarchyObjectInterface::ConstReferenceFunctionsImpl<REF>, public ObserverObjectInterface::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for HierarchyObjectInterface.
template <typename S> class HierarchyObjectInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, HierarchyObjectRef, true>::type&() const { return reinterpret_cast<const HierarchyObjectRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, HierarchyObjectRef, false>::type&() { return reinterpret_cast<const HierarchyObjectRef&>(this->GetBaseRef()); }
/// Inserts this object (including its children and next siblings, if any) into the hierarchy as the previous sibling of nextSibling.
/// Before invocation, nextSibling needs to have either a previous sibling or a parent object,
/// which will get the ownership of this object. This object will take over the ownership of nextSibling.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] nextSibling				An object which shall become the next sibling of this object.
/// @return												OK on success.
	inline Result<void> InsertBefore(const HierarchyObjectRef& nextSibling) const;
/// Inserts this object (including its children and next siblings, if any) into the hierarchy as the next sibling of prevSibling.
/// prevSibling gets the ownership of this object.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] prevSibling				Another object of which this object shall become the next sibling.
/// @return												OK on success.
	inline Result<void> InsertAfter(const HierarchyObjectRef& prevSibling) const;
/// Insert this object (including its children and next siblings, if any) as the first child of the given parent object.
/// The parent object gets the ownership of this object.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] parent							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
	inline Result<void> InsertAsFirstChildOf(const HierarchyObjectRef& parent, const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Insert this object (including its children and next siblings, if any) as the last child of the given parent object.
/// If there are already children existing in the given branch the last one will get ownership of this object.
/// Otherwise the parent object gets the ownership of this object.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] parent							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
	inline Result<void> InsertAsLastChildOf(const HierarchyObjectRef& parent, const ConstDataPtr& branchId = ConstDataPtr()) const;
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
	inline Result<void> InsertAsChildAt(const HierarchyObjectRef& parent, Int position, const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Insert a child object (including its children and next siblings, if any) as the first child of this object.
/// This object gets the ownership of the given child.
///
/// The child object mustn't have a parent or a previous sibling.
/// @param[in] child							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
	inline Result<void> InsertChildAsFirst(const HierarchyObjectRef& child, const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Insert a child object (including its children and next siblings, if any) as the last child of this object.
/// If there are already children existing in the given branch the last one will get ownership of the given child object.
/// Otherwise this object gets the ownership of the given child.
///
/// The child object mustn't have a parent or a previous sibling.
/// @param[in] child							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
	inline Result<void> InsertChildAsLast(const HierarchyObjectRef& child, const ConstDataPtr& branchId = ConstDataPtr()) const;
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
	inline Result<void> InsertChildAt(const HierarchyObjectRef& child, Int position, const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Insert a list of child objects (including its children and next siblings, if any) as the first child of this object.
/// This object gets the ownership of the given children.
///
/// Each child object mustn't have a parent or a previous sibling.
/// @param[in] children						Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
	inline Result<void> InsertChildrenAsFirst(const BaseArray<HierarchyObjectRef>& children, const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Insert a list of child objects (including its children and next siblings, if any) as the last child of this object.
/// If there are already children existing in the given branch the last one will get ownership of the given children objects.
/// Otherwise this object gets the ownership of the given children.
///
/// Each child object mustn't have a parent or a previous sibling.
/// @param[in] children						Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
	inline Result<void> InsertChildrenAsLast(const BaseArray<HierarchyObjectRef>& children, const ConstDataPtr& branchId = ConstDataPtr()) const;
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
	inline Result<void> InsertChildrenAt(const BaseArray<HierarchyObjectRef>& children, Int position, const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Replace this object with the new one and remove it from the hierarchy.
/// The new object will have the same prev/next siblings and descendants like this object.
/// @return												This object including the descendants hierarchy.
	inline Result<void> Replace(const HierarchyObjectRef& newObject) const;
/// Remove this object from the hierarchy, including all descendants.
/// @return												This object including the descendants hierarchy.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<HierarchyObjectRef>, HierarchyObjectRef>::type Remove() const;
/// Remove all descendants from the given branch hierarchy.
/// The descendants hierarchy is returned as a reference which has the ownership of the descendants.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												Descendants hierarchy.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<HierarchyObjectRef>, HierarchyObjectRef>::type RemoveChildren(const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Remove all descendants from the hierarchy.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type RemoveAllChildren() const;
/// Is invoked whenever the parent of this object changes. This method can be overridden
/// when special actions have to be taken on such a change, for example the update of an
/// underlying hierarchy which has to be kept in sync with this hierarchy.
///
/// This method must not be invoked by user code.
/// @param[in] removed						Flag if the object has been removed (true) or inserted (false).
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type ParentChanged(Bool removed) const;
};
#ifdef DOXYGEN
template <typename REF> class HierarchyObjectInterface::ReferenceFunctionsImplDoxy : public HierarchyObjectInterface::ReferenceFunctionsImpl<REF>, public ObserverObjectInterface::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for HierarchyObjectInterface.
template <typename S> class HierarchyObjectInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, HierarchyObjectRef, false>::type&() { return reinterpret_cast<const HierarchyObjectRef&>(this->GetBaseRef()); }
/// Inserts this object (including its children and next siblings, if any) into the hierarchy as the previous sibling of nextSibling.
/// Before invocation, nextSibling needs to have either a previous sibling or a parent object,
/// which will get the ownership of this object. This object will take over the ownership of nextSibling.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] nextSibling				An object which shall become the next sibling of this object.
/// @return												OK on success.
	inline Result<void> InsertBefore(const HierarchyObjectRef& nextSibling);
/// Inserts this object (including its children and next siblings, if any) into the hierarchy as the next sibling of prevSibling.
/// prevSibling gets the ownership of this object.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] prevSibling				Another object of which this object shall become the next sibling.
/// @return												OK on success.
	inline Result<void> InsertAfter(const HierarchyObjectRef& prevSibling);
/// Insert this object (including its children and next siblings, if any) as the first child of the given parent object.
/// The parent object gets the ownership of this object.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] parent							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
	inline Result<void> InsertAsFirstChildOf(const HierarchyObjectRef& parent, const ConstDataPtr& branchId = ConstDataPtr());
/// Insert this object (including its children and next siblings, if any) as the last child of the given parent object.
/// If there are already children existing in the given branch the last one will get ownership of this object.
/// Otherwise the parent object gets the ownership of this object.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] parent							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
	inline Result<void> InsertAsLastChildOf(const HierarchyObjectRef& parent, const ConstDataPtr& branchId = ConstDataPtr());
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
	inline Result<void> InsertAsChildAt(const HierarchyObjectRef& parent, Int position, const ConstDataPtr& branchId = ConstDataPtr());
/// Insert a child object (including its children and next siblings, if any) as the first child of this object.
/// This object gets the ownership of the given child.
///
/// The child object mustn't have a parent or a previous sibling.
/// @param[in] child							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
	inline Result<void> InsertChildAsFirst(const HierarchyObjectRef& child, const ConstDataPtr& branchId = ConstDataPtr());
/// Insert a child object (including its children and next siblings, if any) as the last child of this object.
/// If there are already children existing in the given branch the last one will get ownership of the given child object.
/// Otherwise this object gets the ownership of the given child.
///
/// The child object mustn't have a parent or a previous sibling.
/// @param[in] child							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
	inline Result<void> InsertChildAsLast(const HierarchyObjectRef& child, const ConstDataPtr& branchId = ConstDataPtr());
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
	inline Result<void> InsertChildAt(const HierarchyObjectRef& child, Int position, const ConstDataPtr& branchId = ConstDataPtr());
/// Insert a list of child objects (including its children and next siblings, if any) as the first child of this object.
/// This object gets the ownership of the given children.
///
/// Each child object mustn't have a parent or a previous sibling.
/// @param[in] children						Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
	inline Result<void> InsertChildrenAsFirst(const BaseArray<HierarchyObjectRef>& children, const ConstDataPtr& branchId = ConstDataPtr());
/// Insert a list of child objects (including its children and next siblings, if any) as the last child of this object.
/// If there are already children existing in the given branch the last one will get ownership of the given children objects.
/// Otherwise this object gets the ownership of the given children.
///
/// Each child object mustn't have a parent or a previous sibling.
/// @param[in] children						Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
	inline Result<void> InsertChildrenAsLast(const BaseArray<HierarchyObjectRef>& children, const ConstDataPtr& branchId = ConstDataPtr());
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
	inline Result<void> InsertChildrenAt(const BaseArray<HierarchyObjectRef>& children, Int position, const ConstDataPtr& branchId = ConstDataPtr());
/// Replace this object with the new one and remove it from the hierarchy.
/// The new object will have the same prev/next siblings and descendants like this object.
/// @return												This object including the descendants hierarchy.
	inline Result<void> Replace(const HierarchyObjectRef& newObject);
/// Remove this object from the hierarchy, including all descendants.
/// @return												This object including the descendants hierarchy.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), HierarchyObjectRef, maxon::Result<HierarchyObjectRef>>::type Remove();
/// Remove all descendants from the given branch hierarchy.
/// The descendants hierarchy is returned as a reference which has the ownership of the descendants.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												Descendants hierarchy.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), HierarchyObjectRef, maxon::Result<HierarchyObjectRef>>::type RemoveChildren(const ConstDataPtr& branchId = ConstDataPtr());
/// Remove all descendants from the hierarchy.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type RemoveAllChildren();
/// Is invoked whenever the parent of this object changes. This method can be overridden
/// when special actions have to be taken on such a change, for example the update of an
/// underlying hierarchy which has to be kept in sync with this hierarchy.
///
/// This method must not be invoked by user code.
/// @param[in] removed						Flag if the object has been removed (true) or inserted (false).
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type ParentChanged(Bool removed);
};
#ifdef DOXYGEN
template <typename REF> class HierarchyObjectInterface::COWReferenceFunctionsImplDoxy : public HierarchyObjectInterface::COWReferenceFunctionsImpl<REF>, public ObserverObjectInterface::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct HierarchyObjectInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObserverObjectInterface::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObserverObjectInterface::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename ObserverObjectInterface::ReferenceFunctions<ST>::type>>::type>::type; };
class HierarchyObjectInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<HierarchyObjectRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<HierarchyObjectInterface, maxon::StrongRefHandler, HierarchyObjectRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<HierarchyObjectInterface, maxon::StrongRefHandler, HierarchyObjectRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// HierarchyObjectRef is the reference class of HierarchyObjectInterface.
///
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
class HierarchyObjectRef : public HierarchyObjectInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(HierarchyObjectRef, Reference);
};

class HierarchyObjectInterface::ObservableHierarchyInsertDelegate : public maxon::Delegate<Result<void>(const HierarchyObjectRef&,const HierarchyObjectRef&)>
{
public:
	using Super = maxon::Delegate<Result<void>(const HierarchyObjectRef&,const HierarchyObjectRef&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleHierarchyInsert);
	ObservableHierarchyInsertDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleHierarchyInsert<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleHierarchyInsert); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleHierarchyInsert<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

class HierarchyObjectInterface::ObservableHierarchyRemoveDelegate : public maxon::Delegate<Result<void>(const HierarchyObjectRef&,const HierarchyObjectRef&)>
{
public:
	using Super = maxon::Delegate<Result<void>(const HierarchyObjectRef&,const HierarchyObjectRef&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleHierarchyRemove);
	ObservableHierarchyRemoveDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleHierarchyRemove<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleHierarchyRemove); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleHierarchyRemove<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

#endif
