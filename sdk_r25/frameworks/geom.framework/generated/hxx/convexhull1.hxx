#if 1
class ConvexHullRef;

struct ConvexHullInterface::Hxx1
{
	class Reference;
	using ReferenceClass = ConvexHullRef;
	/// Intermediate helper class for ConvexHullInterface.
	template <typename S> class ReferenceFunctionsImpl : public S
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ConvexHullRef, true>::type&() const { return reinterpret_cast<const ConvexHullRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ConvexHullRef, false>::type&() { return reinterpret_cast<const ConvexHullRef&>(this->GetBaseRef()); }
/// Creates a Convex hull out of the input points.
/// @param[in] vertices						Block of point data for which the convex hull is to be calculated.
/// @param[in] shrink							Value the resulting convex hull is shrunk by.
/// @param[in] shrinkClamp				Clamping the minimum size of the resulting convex hull.
/// @param[out] resultVertices		The array is filled with the vertices of the calculated convex hull.
/// @param[out] resultEdges				The array is filled with the edges of the calculated convex hull.
/// @param[out] resultFaces				The array is filled with the face of the calculated convex hull.
/// @return												The amount the convex hull was shrunk by. if value is negative the convex hull is empty because it shrunk to much.
		inline Result<Float> ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, BaseArray<Vector>& resultVertices, BaseArray<ConvEdge>& resultEdges, BaseArray<Int>& resultFaces) const;
/// Creates a Convex hull out of the input points.
/// @param[in] vertices						Block of point data for which the convex hull is to be calculated.
/// @param[in] shrink							Value the resulting convex hull is shrunk by.
/// @param[in] shrinkClamp				Clamping the minimum size of the resulting convex hull.
/// @param[out] hull							The struct is filled with all data that makes up the convex hull (vertices, edges, faces).
/// @return												The amount the convex hull was shrunk by. if value is negative the convex hull is empty because it shrunk to much.
		inline Result<Float> ComputeConvexHull(const Block<const Vector>& vertices, const Float shrink, const Float shrinkClamp, ConvexHullData& hull) const;
	};
	/// Intermediate helper class for ConvexHullInterface.
	template <typename S> class COWReferenceFunctionsImpl : public S
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, ConvexHullRef, false>::type&() { return reinterpret_cast<const ConvexHullRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ST::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, typename ST::type, ReferenceFunctionsImpl<typename ST::type>>::type
	> { };
};
class ConvexHullInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<ConvexHullRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ConvexHullInterface, maxon::StrongRefHandler, ConvexHullRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ConvexHullInterface, maxon::StrongRefHandler, ConvexHullRef>>>>);
	using NonConst = typename Super::ReferenceClass;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<ConvexHullRef> Create();
};

/// ConvexHullRef is the reference class of ConvexHullInterface.
///
/// ConvexHullInterface provides functions for creating a convex hull of a set of points
class ConvexHullRef : public ConvexHullInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ConvexHullRef, typename ConvexHullInterface::Hxx1::Reference);
	using ConstPtr = typename ConvexHullInterface::ConstPtr;
};

#endif
