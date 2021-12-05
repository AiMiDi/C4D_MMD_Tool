#if 1
struct HierarchyObjectInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, HierarchyObjectInterface>::value || ObserverObjectInterface::HasBase::template Check<I>::value; static I* Cast(HierarchyObjectInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct HierarchyObjectInterface::Hxx1
{
	template <typename HIERARCHY_> class Reference;
	using ReferenceClass = HierarchyObjectRef<>;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObserverObjectInterface>;
	/// Intermediate helper class for HierarchyObjectInterface.
	template <typename S, typename HIERARCHY_> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using HIERARCHY = HIERARCHY_;
		using S::GenericVarianceCheck;
		template <typename _S> static typename std::integral_constant<bool, true>::type GenericVarianceCheck(const ConstReferenceFunctionsImpl<_S, HIERARCHY_>*);
		template <typename _S> static typename std::true_type GenericVarianceCheck(ConstReferenceFunctionsImpl<_S, DefaultHierarchy<void>>*);
		template <typename DERIVED> struct IsGenericBaseOf { static const Bool value = S::template IsGenericBaseOf<DERIVED>::value && decltype(DERIVED::GenericVarianceCheck((ConstReferenceFunctionsImpl*) nullptr))::value; };
/// Returns the owner of this object (and the whole hierarchy).
/// @return												Owner of hierarchy.
		inline Result<Data> GetOwner() const;
/// Returns the first child of this object.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												Child object or nullptr if not available.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type GetFirstChild(const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Returns the last child of this object.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												Child object or nullptr if not available.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type GetLastChild(const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Returns the n'th child of this object.
/// @param[in] position						The child position.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												Child object or nullptr if not available.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type GetChildAt(Int position, const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Returns all children of the given hierarchy.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
		inline Result<BaseArray<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>> GetChildren(const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Returns all branches of the given hierarchy.
		inline Result<BaseArray<ConstDataPtr>> GetBranches() const;
/// Returns the parent of this object.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type>::type GetParent() const;
/// Returns the next sibling of this object.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>::type GetNext() const;
/// Returns the previous sibling of this object.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type>::type GetPrev() const;
/// ObservableHierarchyInsert is sent whenever an object was inserted in the hierarchy.
/// -param[in] sender							Sender object.
/// -param[in] object							HierarchyObject which was added.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableHierarchyInsertDelegate>>, maxon::ObservableRef<ObservableHierarchyInsertDelegate>>::type ObservableHierarchyInsert() const;
/// ObservableHierarchyRemove is sent whenever an object was removed from the hierarchy.
/// -param[in] sender							Sender object.
/// -param[in] object							HierarchyObject which was removed.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<maxon::ObservableRef<ObservableHierarchyRemoveDelegate>>, maxon::ObservableRef<ObservableHierarchyRemoveDelegate>>::type ObservableHierarchyRemove() const;
	};
	/// Intermediate helper class for HierarchyObjectInterface.
	template <typename S, typename HIERARCHY_> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S, HIERARCHY_>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S, HIERARCHY_>;
		using PrivateBaseClass::PrivateBaseClass;
		using HIERARCHY = HIERARCHY_;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, HierarchyObjectRef<HIERARCHY_>, true>::type&() const { return reinterpret_cast<const HierarchyObjectRef<HIERARCHY_>&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, HierarchyObjectRef<HIERARCHY_>, false>::type&() { return reinterpret_cast<const HierarchyObjectRef<HIERARCHY_>&>(this->GetBaseRef()); }
/// Inserts this object (including its children and next siblings, if any) into the hierarchy as the previous sibling of nextSibling.
/// Before invocation, nextSibling needs to have either a previous sibling or a parent object,
/// which will get the ownership of this object. This object will take over the ownership of nextSibling.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] nextSibling				An object which shall become the next sibling of this object.
/// @return												OK on success.
		inline Result<void> InsertBefore(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& nextSibling) const;
/// Inserts this object (including its children and next siblings, if any) into the hierarchy as the next sibling of prevSibling.
/// prevSibling gets the ownership of this object.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] prevSibling				Another object of which this object shall become the next sibling.
/// @return												OK on success.
		inline Result<void> InsertAfter(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& prevSibling) const;
/// Insert this object (including its children and next siblings, if any) as the first child of the given parent object.
/// The parent object gets the ownership of this object.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] parent							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
		inline Result<void> InsertAsFirstChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Insert this object (including its children and next siblings, if any) as the last child of the given parent object.
/// If there are already children existing in the given branch the last one will get ownership of this object.
/// Otherwise the parent object gets the ownership of this object.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] parent							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
		inline Result<void> InsertAsLastChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId = ConstDataPtr()) const;
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
		[[deprecated("Use InsertChildAt")]] inline Result<void> InsertAsChildAt(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, Int position, const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Insert a child object (including its children and next siblings, if any) as the first child of this object.
/// This object gets the ownership of the given child.
///
/// The child object mustn't have a parent or a previous sibling.
/// @param[in] child							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
		inline Result<void> InsertChildAsFirst(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Insert a child object (including its children and next siblings, if any) as the last child of this object.
/// If there are already children existing in the given branch the last one will get ownership of the given child object.
/// Otherwise this object gets the ownership of the given child.
///
/// The child object mustn't have a parent or a previous sibling.
/// @param[in] child							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
		inline Result<void> InsertChildAsLast(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId = ConstDataPtr()) const;
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
		inline Result<void> InsertChildAt(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, Int position, const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Insert a list of child objects (including its children and next siblings, if any) as the first child of this object.
/// This object gets the ownership of the given children.
///
/// Each child object mustn't have a parent or a previous sibling.
/// @param[in] children						Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
		inline Result<void> InsertChildrenAsFirst(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Insert a list of child objects (including its children and next siblings, if any) as the last child of this object.
/// If there are already children existing in the given branch the last one will get ownership of the given children objects.
/// Otherwise this object gets the ownership of the given children.
///
/// Each child object mustn't have a parent or a previous sibling.
/// @param[in] children						Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
		inline Result<void> InsertChildrenAsLast(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId = ConstDataPtr()) const;
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
		inline Result<void> InsertChildrenAt(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, Int position, const ConstDataPtr& branchId = ConstDataPtr()) const;
/// Replace this object with the new one and remove it from the hierarchy.
/// The new object will have the same prev/next siblings and descendants like this object.
/// @return												This object including the descendants hierarchy.
		inline Result<void> Replace(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& newObject) const;
/// Remove this object from the hierarchy, including all descendants.
/// @return												This object including the descendants hierarchy.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<HierarchyObjectRef<>>, HierarchyObjectRef<>>::type Remove() const;
/// Remove all descendants from the given branch hierarchy.
/// The descendants hierarchy is returned as a reference which has the ownership of the descendants.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												Descendants hierarchy.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>, typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>::type RemoveChildren(const ConstDataPtr& branchId = ConstDataPtr()) const;
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
	/// Intermediate helper class for HierarchyObjectInterface.
	template <typename S, typename HIERARCHY_> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S, HIERARCHY_>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S, HIERARCHY_>;
		using PrivateBaseClass::PrivateBaseClass;
		using HIERARCHY = HIERARCHY_;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, HierarchyObjectRef<HIERARCHY_>, false>::type&() { return reinterpret_cast<const HierarchyObjectRef<HIERARCHY_>&>(this->GetBaseRef()); }
/// Inserts this object (including its children and next siblings, if any) into the hierarchy as the previous sibling of nextSibling.
/// Before invocation, nextSibling needs to have either a previous sibling or a parent object,
/// which will get the ownership of this object. This object will take over the ownership of nextSibling.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] nextSibling				An object which shall become the next sibling of this object.
/// @return												OK on success.
		inline Result<void> InsertBefore(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& nextSibling);
/// Inserts this object (including its children and next siblings, if any) into the hierarchy as the next sibling of prevSibling.
/// prevSibling gets the ownership of this object.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] prevSibling				Another object of which this object shall become the next sibling.
/// @return												OK on success.
		inline Result<void> InsertAfter(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& prevSibling);
/// Insert this object (including its children and next siblings, if any) as the first child of the given parent object.
/// The parent object gets the ownership of this object.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] parent							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
		inline Result<void> InsertAsFirstChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId = ConstDataPtr());
/// Insert this object (including its children and next siblings, if any) as the last child of the given parent object.
/// If there are already children existing in the given branch the last one will get ownership of this object.
/// Otherwise the parent object gets the ownership of this object.
///
/// This object mustn't have a parent or a previous sibling.
/// @param[in] parent							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
		inline Result<void> InsertAsLastChildOf(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, const ConstDataPtr& branchId = ConstDataPtr());
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
		[[deprecated("Use InsertChildAt")]] inline Result<void> InsertAsChildAt(const typename HIERARCHY_::template Parent<maxon::details::GetPrivateReferencedType<S>>::type& parent, Int position, const ConstDataPtr& branchId = ConstDataPtr());
/// Insert a child object (including its children and next siblings, if any) as the first child of this object.
/// This object gets the ownership of the given child.
///
/// The child object mustn't have a parent or a previous sibling.
/// @param[in] child							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
		inline Result<void> InsertChildAsFirst(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId = ConstDataPtr());
/// Insert a child object (including its children and next siblings, if any) as the last child of this object.
/// If there are already children existing in the given branch the last one will get ownership of the given child object.
/// Otherwise this object gets the ownership of the given child.
///
/// The child object mustn't have a parent or a previous sibling.
/// @param[in] child							Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
		inline Result<void> InsertChildAsLast(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, const ConstDataPtr& branchId = ConstDataPtr());
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
		inline Result<void> InsertChildAt(const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type& child, Int position, const ConstDataPtr& branchId = ConstDataPtr());
/// Insert a list of child objects (including its children and next siblings, if any) as the first child of this object.
/// This object gets the ownership of the given children.
///
/// Each child object mustn't have a parent or a previous sibling.
/// @param[in] children						Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
		inline Result<void> InsertChildrenAsFirst(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId = ConstDataPtr());
/// Insert a list of child objects (including its children and next siblings, if any) as the last child of this object.
/// If there are already children existing in the given branch the last one will get ownership of the given children objects.
/// Otherwise this object gets the ownership of the given children.
///
/// Each child object mustn't have a parent or a previous sibling.
/// @param[in] children						Parent object under which the object should be inserted.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												OK on success.
		inline Result<void> InsertChildrenAsLast(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, const ConstDataPtr& branchId = ConstDataPtr());
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
		inline Result<void> InsertChildrenAt(const Block<const typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>& children, Int position, const ConstDataPtr& branchId = ConstDataPtr());
/// Replace this object with the new one and remove it from the hierarchy.
/// The new object will have the same prev/next siblings and descendants like this object.
/// @return												This object including the descendants hierarchy.
		inline Result<void> Replace(const typename HIERARCHY_::template Sibling<maxon::details::GetPrivateReferencedType<S>>::type& newObject);
/// Remove this object from the hierarchy, including all descendants.
/// @return												This object including the descendants hierarchy.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), HierarchyObjectRef<>, maxon::Result<HierarchyObjectRef<>>>::type Remove();
/// Remove all descendants from the given branch hierarchy.
/// The descendants hierarchy is returned as a reference which has the ownership of the descendants.
/// @param[in] branchId						Defines the optional branch to which the children belongs to.
/// @return												Descendants hierarchy.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type, maxon::Result<typename HIERARCHY_::template Child<maxon::details::GetPrivateReferencedType<S>>::type>>::type RemoveChildren(const ConstDataPtr& branchId = ConstDataPtr());
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
	template <typename ST, typename HIERARCHY_ = DefaultHierarchy<void>> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type, HIERARCHY_>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type, HIERARCHY_>, ReferenceFunctionsImpl<typename ObserverObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type, HIERARCHY_>>::type> { };
};
template <typename HIERARCHY_> class HierarchyObjectInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<HierarchyObjectRef<HIERARCHY_>>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<HierarchyObjectInterface, maxon::StrongRefHandler, HierarchyObjectRef<HIERARCHY_>>>, HIERARCHY_>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<HierarchyObjectInterface, maxon::StrongRefHandler, HierarchyObjectRef<HIERARCHY_>>>, HIERARCHY_>>);
	using NonConst = typename Super::ReferenceClass;
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
template <typename HIERARCHY_> class HierarchyObjectRef : public HierarchyObjectInterface::Hxx1::template Reference<HIERARCHY_>
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(HierarchyObjectRef, typename HierarchyObjectInterface::Hxx1::template Reference<HIERARCHY_>);
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = HierarchyObjectRef<typename MAP<HIERARCHY_>::type>;
	};
};

class HierarchyObjectInterface::ObservableHierarchyInsertDelegate : public maxon::Delegate<Result<void>(const HierarchyObjectRef<>&,const HierarchyObjectRef<>&)>
{
public:
	using Super = maxon::Delegate<Result<void>(const HierarchyObjectRef<>&,const HierarchyObjectRef<>&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleHierarchyInsert);
	ObservableHierarchyInsertDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleHierarchyInsert<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleHierarchyInsert); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleHierarchyInsert<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

class HierarchyObjectInterface::ObservableHierarchyRemoveDelegate : public maxon::Delegate<Result<void>(const HierarchyObjectRef<>&,const HierarchyObjectRef<>&)>
{
public:
	using Super = maxon::Delegate<Result<void>(const HierarchyObjectRef<>&,const HierarchyObjectRef<>&)>;
	MAXON_MEMBERFUNCTION_DETECTOR(HandleHierarchyRemove);
	ObservableHierarchyRemoveDelegate() = default;
	template <typename FN> static maxon::ResultOk<Super> Create(FN&& src, typename std::enable_if<HasHandleHierarchyRemove<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr) { return Super::CreateByReference(std::forward<FN>(src), &maxon::Dereference<typename std::decay<FN>::type, false>::type::HandleHierarchyRemove); }
	template <typename FN> static maxon::Result<Super> Create(FN&& src, typename std::enable_if<!HasHandleHierarchyRemove<typename maxon::Dereference<typename std::decay<FN>::type, false>::type>::value, void>::type* = nullptr){ return Super::Create(std::forward<FN>(src)); }
	using OBSERVABLECOMBINER = ObservableCombinerRunAllComponentPrivateHelper;
};

#endif
