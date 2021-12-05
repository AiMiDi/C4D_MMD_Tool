#if 1
class PixelFormatGroup;

struct PixelFormatGroupInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, PixelFormatGroupInterface>::value || ObjectInterface::HasBase::template Check<I>::value; static I* Cast(PixelFormatGroupInterface* ptr) { return static_cast<I*>(static_cast<maxon::ObjectInterface*>(ptr)); } }; };
struct PixelFormatGroupInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = PixelFormatGroup;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for PixelFormatGroupInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, PixelFormatGroup, false>::type&() const { return reinterpret_cast<const PixelFormatGroup&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, PixelFormatGroup, false>::type&() { return reinterpret_cast<const PixelFormatGroup&>(this->GetBaseRef()); }
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormatIterator>, PixelFormatIterator>::type GetEntries() const;
	};
	/// Intermediate helper class for PixelFormatGroupInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for PixelFormatGroupInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>, ReferenceFunctionsImpl<typename ObjectInterface::Hxx1::template ReferenceFunctionsHelper<ST>::type>>::type> { };
};
class PixelFormatGroupInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<PixelFormatGroup>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const PixelFormatGroupInterface, maxon::StrongRefHandler, PixelFormatGroup>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const PixelFormatGroupInterface, maxon::StrongRefHandler, PixelFormatGroup>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class PixelFormatGroupInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<PixelFormatGroupInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<PixelFormatGroupInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// PixelFormatGroup is the reference class of PixelFormatGroupInterface.
///
/// Every pixel format belongs to a specific group. This interface define this group.
/// The group should define a general pixel format, e.g. RGB or BGRA etc. All the different implementations for different bit depths should
/// be grouped under that group.
class PixelFormatGroup : public PixelFormatGroupInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(PixelFormatGroup, typename PixelFormatGroupInterface::Hxx1::Reference);
};

#endif
