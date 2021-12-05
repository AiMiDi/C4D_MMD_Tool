#if 1
class Dimension;

struct DimensionInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DimensionInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(DimensionInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct DimensionInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = Dimension;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DimensionInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
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
	/// Intermediate helper class for DimensionInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for DimensionInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class DimensionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<Dimension>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DimensionInterface, maxon::StrongRefHandler, Dimension>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const DimensionInterface, maxon::StrongRefHandler, Dimension>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class DimensionInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DimensionInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<DimensionInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// Dimension is the reference class of DimensionInterface.
class Dimension : public DimensionInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Dimension, typename DimensionInterface::Hxx1::Reference);
};

class Unit;

struct UnitInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = Unit;
	/// Intermediate helper class for UnitInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
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
	/// Intermediate helper class for UnitInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for UnitInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class UnitInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<Unit>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnitInterface, maxon::StrongRefHandler, Unit>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const UnitInterface, maxon::StrongRefHandler, Unit>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnitInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnitInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<UnitInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// Unit is the reference class of UnitInterface.
class Unit : public UnitInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Unit, typename UnitInterface::Hxx1::Reference);
};

#endif
