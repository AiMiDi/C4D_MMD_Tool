#if 1
class NURBSCurveRef;

struct NURBSCurveInterface::Hxx1
{
	class Reference;
	using ReferenceClass = NURBSCurveRef;
	/// Intermediate helper class for NURBSCurveInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		inline Result<Vector> EvaluateAt(Float s) const;
		inline Result<Vector> DeriveAt(Float s) const;
		inline Result<Int> GetDegree() const;
		inline Result<Int> GetMaxDegree() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetPointCount() const;
		inline Result<Int> GetWeightCount() const;
		inline Result<Vector> GetPoint(Int i) const;
		inline Result<Vector4d> GetPointWithWeight(Int i) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Block<const Vector4d>>, const Block<const Vector4d>>::type GetPointsWithWeights() const;
		inline Result<Float> GetWeight(Int i) const;
	};
	/// Intermediate helper class for NURBSCurveInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, NURBSCurveRef, true>::type&() const { return reinterpret_cast<const NURBSCurveRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, NURBSCurveRef, false>::type&() { return reinterpret_cast<const NURBSCurveRef&>(this->GetBaseRef()); }
		inline Result<void> SetPoint(Int i, const Vector& point) const;
		inline Result<void> SetPointWithWeight(Int i, const Vector4d& point) const;
		inline Result<void> ChangePoints(const Block<Vector>& points) const;
		inline Result<void> SetPointsWithWeights(const Block<const Vector4d>& points) const;
		inline Result<void> SetWeight(Int i, Float weight) const;
		inline Result<void> ChangeWeights(const Block<const Float>& weights) const;
		inline Result<void> ChangeWeights(const Block<const Float32>& weights) const;
	};
	/// Intermediate helper class for NURBSCurveInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, NURBSCurveRef, false>::type&() { return reinterpret_cast<const NURBSCurveRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type
	> { };
};
class NURBSCurveInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NURBSCurveRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<NURBSCurveInterface, maxon::StrongRefHandler, NURBSCurveRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<NURBSCurveInterface, maxon::StrongRefHandler, NURBSCurveRef>>>>);
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
