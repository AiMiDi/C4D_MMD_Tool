#if 1
class NURBSCurveRef;

struct NURBSCurveInterface::Hxx1
{
	class Reference;
	using ReferenceClass = NURBSCurveRef;
	/// Intermediate helper class for NURBSCurveInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = NURBSCurveInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(NURBSCurveInterface**);
		inline Result<Vector> EvaluateAt(Float s) const;
		inline Result<Vector> DeriveAt(Float s) const;
		inline Result<Int> GetDegree() const;
		inline Result<Int> GetMaxDegree() const;
		inline HXXADDRET2(Int) GetPointCount() const;
		inline Result<Int> GetWeightCount() const;
		inline Result<Vector> GetPoint(Int i) const;
		inline Result<Vector4d> GetPointWithWeight(Int i) const;
		inline HXXADDRET2(const Block<const Vector4d>) GetPointsWithWeights() const;
		inline Result<Float> GetWeight(Int i) const;
	};
	/// Intermediate helper class for NURBSCurveInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = NURBSCurveInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(NURBSCurveInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, NURBSCurveRef, true>::type&() const { return reinterpret_cast<const NURBSCurveRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, NURBSCurveRef, false>::type&() { return reinterpret_cast<const NURBSCurveRef&>(this->GetBaseRef()); }
		inline Result<void> SetPoint(Int i, const Vector& point) const;
		inline Result<void> SetPointWithWeight(Int i, const Vector4d& point) const;
		inline Result<void> ChangePoints(const Block<Vector>& points) const;
		inline Result<void> SetPointsWithWeights(const Block<const Vector4d>& points) const;
		inline Result<void> SetWeight(Int i, Float weight) const;
		inline Result<void> ChangeWeights(const Block<const Float>& weights) const;
		inline Result<void> ChangeWeights(const Block<const Float32>& weights) const;
		inline Result<Pair<Block<Vector4d>, Int>> AddControlPoint(const Float t) const;
	};
	/// Intermediate helper class for NURBSCurveInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateInterface = NURBSCurveInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(NURBSCurveInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, NURBSCurveRef, false>::type&() { return reinterpret_cast<const NURBSCurveRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ST::type>, Fn<typename ST::type>>::type
	> { };
};
class NURBSCurveInterface::Hxx1::Reference :
#ifdef DOXYGEN
public FnDoxy<NURBSCurveRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<NURBSCurveInterface, maxon::StrongRefHandler, NURBSCurveRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<NURBSCurveInterface, maxon::StrongRefHandler, NURBSCurveRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// NURBSCurveRef is the reference class of NURBSCurveInterface.
class NURBSCurveRef : public NURBSCurveInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NURBSCurveRef, typename NURBSCurveInterface::Hxx1::Reference);
	using ConstPtr = typename NURBSCurveInterface::ConstPtr;
};

#if 0
#endif
#endif
