#if 1
class Dimension;

struct DimensionInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, DimensionInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(DimensionInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct DimensionInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = Dimension;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for DimensionInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = DimensionInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(DimensionInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, Dimension, false>::type&() const { return reinterpret_cast<const Dimension&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, Dimension, false>::type&() { return reinterpret_cast<const Dimension&>(this->GetBaseRef()); }
		static inline const Dimension& Get(BASE_DIMENSION q);
		inline HXXADDRET2(const Id&) GetId() const;
		inline Result<Dimension> operator *(const Result<Dimension>& q) const;
		inline Result<Dimension> operator /(const Result<Dimension>& q) const;
		inline Result<Dimension> operator ^(Int exponent) const;
		inline Result<Dimension> Copy(const Id& qid) const;
		inline HXXADDRET2(Int) GetExponent(BASE_DIMENSION q) const;
		inline Result<Unit> AddUnit(const Id& unitId, Float siConversionFactor) const;
		inline HXXADDRET2(UnitsArray) GetUnits() const;
		inline HXXADDRET2(Bool) IsEquivalent(const Dimension& other) const;
		inline HXXADDRET2(String) ToString(const FormatStatement* fs = nullptr) const;
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>
	> { };
};
class DimensionInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<Dimension>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const DimensionInterface, maxon::StrongRefHandler, Dimension>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const DimensionInterface, maxon::StrongRefHandler, Dimension>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class DimensionInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DimensionInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<DimensionInterface, maxon::StrongRefHandler, NonConstRef>>>>);
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
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = UnitInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(UnitInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, Unit, false>::type&() const { return reinterpret_cast<const Unit&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, Unit, false>::type&() { return reinterpret_cast<const Unit&>(this->GetBaseRef()); }
		inline HXXADDRET2(const Id&) GetId() const;
		inline HXXADDRET2(const Dimension&) GetDimension() const;
		inline HXXADDRET2(Float) GetSIConversionFactor() const;
		inline Result<Unit> operator *(const Result<Unit>& u) const;
		inline Result<Unit> operator /(const Result<Unit>& u) const;
		inline Result<Unit> operator ^(Int exponent) const;
		inline Result<Unit> Copy(const Id& uid) const;
		inline Result<Unit> Copy(const Dimension& quantity) const;
		inline Result<void> AddToDimension() const;
		inline Result<Unit> Reduce() const;
		inline HXXADDRET2(String) ToString(const FormatStatement* fs = nullptr) const;
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename ST::type>
	> { };
};
class UnitInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<Unit>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const UnitInterface, maxon::StrongRefHandler, Unit>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const UnitInterface, maxon::StrongRefHandler, Unit>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class UnitInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<UnitInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<UnitInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// Unit is the reference class of UnitInterface.
class Unit : public UnitInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Unit, typename UnitInterface::Hxx1::Reference);
};

#endif
