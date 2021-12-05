#if 1
class VectorImageRef;

struct VectorImageInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, VectorImageInterface>::value || ImageBaseInterface::HasBaseDetector::template Check<I>::value; static I* Cast(VectorImageInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct VectorImageInterface::Hxx1
{
	class Reference;
	using ReferenceClass = VectorImageRef;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ImageBaseInterface>;
	/// Intermediate helper class for VectorImageInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		inline Result<ForwardRef<SVGDocument>> GetVectorIcon() const;
	};
	/// Intermediate helper class for VectorImageInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, VectorImageRef, true>::type&() const { return reinterpret_cast<const VectorImageRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, VectorImageRef, false>::type&() { return reinterpret_cast<const VectorImageRef&>(this->GetBaseRef()); }
		inline Result<void> Init(const Url& vectorIconUrl) const;
		inline Result<void> Init(const SVGDocument& vectorIcon) const;
	};
	/// Intermediate helper class for VectorImageInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, VectorImageRef, false>::type&() { return reinterpret_cast<const VectorImageRef&>(this->GetBaseRef()); }
		inline Result<void> Init(const Url& vectorIconUrl);
		inline Result<void> Init(const SVGDocument& vectorIcon);
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWReferenceFunctionsImpl<typename ImageBaseInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ImageBaseInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ImageBaseInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type
	> { };
};
class VectorImageInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<VectorImageRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<VectorImageInterface, maxon::StrongRefHandler, VectorImageRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<VectorImageInterface, maxon::StrongRefHandler, VectorImageRef>>>>);
	using NonConst = typename Super::ReferenceClass;
};

/// VectorImageRef is the reference class of VectorImageInterface.
///
/// The ImageInterface represents a single image with a ImageTextureRef.
/// one or more Images can be part of a ImageTextureRef.
class VectorImageRef : public VectorImageInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(VectorImageRef, typename VectorImageInterface::Hxx1::Reference);
	using ConstPtr = typename VectorImageInterface::ConstPtr;
};

#endif
