#if 1
struct BlendFunctionInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, BlendFunctionInterface>::value || Object::HasBase::Check<I>::value; static I* Cast(BlendFunctionInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class BlendFunctionRef;

struct BlendFunctionInterface::ReferenceClassHelper { using type = BlendFunctionRef; };

/// Intermediate helper class for BlendFunctionInterface.
template <typename S> class BlendFunctionInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class BlendFunctionInterface::ConstReferenceFunctionsImplDoxy : public BlendFunctionInterface::ConstReferenceFunctionsImpl<REF>, public Object::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for BlendFunctionInterface.
template <typename S> class BlendFunctionInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BlendFunctionRef, true>::type&() const { return reinterpret_cast<const BlendFunctionRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, BlendFunctionRef, false>::type&() { return reinterpret_cast<const BlendFunctionRef&>(this->GetBaseRef()); }
/// Maps a value for a given x value based on the given startValue and endValue.
	inline Result<Data> MapValue(Float x, const Data& startValue, const Data& endValue) const;
};
#ifdef DOXYGEN
template <typename REF> class BlendFunctionInterface::ReferenceFunctionsImplDoxy : public BlendFunctionInterface::ReferenceFunctionsImpl<REF>, public Object::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for BlendFunctionInterface.
template <typename S> class BlendFunctionInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, BlendFunctionRef, false>::type&() { return reinterpret_cast<const BlendFunctionRef&>(this->GetBaseRef()); }
/// Maps a value for a given x value based on the given startValue and endValue.
	inline Result<Data> MapValue(Float x, const Data& startValue, const Data& endValue);
};
#ifdef DOXYGEN
template <typename REF> class BlendFunctionInterface::COWReferenceFunctionsImplDoxy : public BlendFunctionInterface::COWReferenceFunctionsImpl<REF>, public Object::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct BlendFunctionInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>>::type>::type; };
class BlendFunctionInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<BlendFunctionRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<BlendFunctionInterface, maxon::StrongRefHandler, BlendFunctionRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<BlendFunctionInterface, maxon::StrongRefHandler, BlendFunctionRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// BlendFunctionRef is the reference class of BlendFunctionInterface.
///
/// Blend function class.
/// The registry BlendFunctions allow to iterate over all available blend functions.
class BlendFunctionRef : public BlendFunctionInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(BlendFunctionRef, Reference);
};

#endif
