#if 1
struct DimensionInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DimensionInterface>::value || Object::HasBase::Check<I>::value; static I* Cast(DimensionInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class Dimension;

struct DimensionInterface::ReferenceClassHelper { using type = Dimension; };

/// Intermediate helper class for DimensionInterface.
template <typename S> class DimensionInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, Dimension, false>::type&() const { return reinterpret_cast<const Dimension&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, Dimension, false>::type&() { return reinterpret_cast<const Dimension&>(this->GetBaseRef()); }
	static inline const Dimension& Get(BASE_DIMENSION q);
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type GetId() const;
	inline Result<Dimension> operator *(const Result<Dimension>& q) const;
	inline Result<Dimension> operator /(const Result<Dimension>& q) const;
	inline Result<Dimension> operator ^(Int exponent) const;
	inline Result<Dimension> Copy(const Id& qid) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetExponent(BASE_DIMENSION q) const;
	inline Result<Unit> AddUnit(const Id& unitId, Float siConversionFactor) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<UnitsArray>, UnitsArray>::type GetUnits() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEquivalent(const Dimension& other) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* fs) const;
};
#ifdef DOXYGEN
template <typename REF> class DimensionInterface::ConstReferenceFunctionsImplDoxy : public DimensionInterface::ConstReferenceFunctionsImpl<REF>, public Object::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DimensionInterface.
template <typename S> class DimensionInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class DimensionInterface::ReferenceFunctionsImplDoxy : public DimensionInterface::ReferenceFunctionsImpl<REF>, public Object::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for DimensionInterface.
template <typename S> class DimensionInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class DimensionInterface::COWReferenceFunctionsImplDoxy : public DimensionInterface::COWReferenceFunctionsImpl<REF>, public Object::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct DimensionInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>>::type>::type; };
class DimensionInterface::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<Dimension>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const DimensionInterface, maxon::StrongRefHandler, Dimension>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const DimensionInterface, maxon::StrongRefHandler, Dimension>>>>);
	using NonConst = NonConstRef;
};

class DimensionInterface::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DimensionInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<DimensionInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// Dimension is the reference class of DimensionInterface.
class Dimension : public DimensionInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Dimension, Reference);
};

class Unit;

struct UnitInterface::ReferenceClassHelper { using type = Unit; };

/// Intermediate helper class for UnitInterface.
template <typename S> class UnitInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, Unit, false>::type&() const { return reinterpret_cast<const Unit&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, Unit, false>::type&() { return reinterpret_cast<const Unit&>(this->GetBaseRef()); }
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type GetId() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Dimension&>, const Dimension&>::type GetDimension() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Float>, Float>::type GetSIConversionFactor() const;
	inline Result<Unit> operator *(const Result<Unit>& u) const;
	inline Result<Unit> operator /(const Result<Unit>& u) const;
	inline Result<Unit> operator ^(Int exponent) const;
	inline Result<Unit> Copy(const Id& uid) const;
	inline Result<Unit> Copy(const Dimension& quantity) const;
	inline Result<void> AddToDimension() const;
	inline Result<Unit> Reduce() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* fs) const;
};
#ifdef DOXYGEN
template <typename REF> class UnitInterface::ConstReferenceFunctionsImplDoxy : public UnitInterface::ConstReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for UnitInterface.
template <typename S> class UnitInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class UnitInterface::ReferenceFunctionsImplDoxy : public UnitInterface::ReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for UnitInterface.
template <typename S> class UnitInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class UnitInterface::COWReferenceFunctionsImplDoxy : public UnitInterface::COWReferenceFunctionsImpl<REF> { };
#endif

template <typename ST> struct UnitInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type>::type; };
class UnitInterface::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<Unit>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UnitInterface, maxon::StrongRefHandler, Unit>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const UnitInterface, maxon::StrongRefHandler, Unit>>>>);
	using NonConst = NonConstRef;
};

class UnitInterface::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UnitInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<UnitInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// Unit is the reference class of UnitInterface.
class Unit : public UnitInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Unit, Reference);
};

#endif
