#if 1
class GenericDynamicTupleRef;

struct DynamicTupleInterface::ReferenceClassHelper { using type = GenericDynamicTupleRef; };

/// Intermediate helper class for DynamicTupleInterface.
template <typename S> class DynamicTupleInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type GetMemberPointers(const Generic** pointers, const TupleDataType* members) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type GetMemberPointer(InternedId name, const DataType* type) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type GetMemberPointer(const Member& member) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const TupleDataType*>, const TupleDataType*>::type GetType() const;
/// Finds the index of the function input having the given name. If no such input
/// can be found, -1 is returned.
/// @param[in] name								Name of the function input to find.
/// @return												Index of the function input, or -1 if it doesn't exist.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindMemberIndex(InternedId name, const DataType* type) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type FindMemberIndex(const Member& member) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type GetAllMemberPointers(const Generic** pointers, Bool skipPointersIfTupleLayout) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type GetMemberPointer(Int index) const;
	template <typename MEMBER> inline typename std::conditional<S::HAS_ERROR, maxon::Result<Opt<const typename MEMBER::Type&>>, Opt<const typename MEMBER::Type&>>::type Get() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Generic*>, const Generic*>::type Get(const Member& member) const;
};
#ifdef DOXYGEN
template <typename REF> class DynamicTupleInterface::ConstReferenceFunctionsImplDoxy : public DynamicTupleInterface::ConstReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for DynamicTupleInterface.
template <typename S> class DynamicTupleInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, GenericDynamicTupleRef, true>::type&() const { return reinterpret_cast<const GenericDynamicTupleRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, GenericDynamicTupleRef, false>::type&() { return reinterpret_cast<const GenericDynamicTupleRef&>(this->GetBaseRef()); }
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type GetMemberPointers(Generic** pointers, const TupleDataType* members) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type GetMemberPointer(InternedId name, const DataType* type) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type GetMemberPointer(const Member& member) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Generic*>, Generic*>::type GetMemberPointer(Int index) const;
};
#ifdef DOXYGEN
template <typename REF> class DynamicTupleInterface::ReferenceFunctionsImplDoxy : public DynamicTupleInterface::ReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for DynamicTupleInterface.
template <typename S> class DynamicTupleInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, GenericDynamicTupleRef, false>::type&() { return reinterpret_cast<const GenericDynamicTupleRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class DynamicTupleInterface::COWReferenceFunctionsImplDoxy : public DynamicTupleInterface::COWReferenceFunctionsImpl<REF> { };
#endif

template <typename ST> struct DynamicTupleInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type>::type; };
class DynamicTupleInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<GenericDynamicTupleRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DynamicTupleInterface, maxon::StrongRefHandler, GenericDynamicTupleRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DynamicTupleInterface, maxon::StrongRefHandler, GenericDynamicTupleRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// GenericDynamicTupleRef is the reference class of DynamicTupleInterface.
class GenericDynamicTupleRef : public DynamicTupleInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(GenericDynamicTupleRef, Reference);
};

#endif
