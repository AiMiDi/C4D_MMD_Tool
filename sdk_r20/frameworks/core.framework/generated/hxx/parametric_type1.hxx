#if 1
class ParametricType;

struct ParametricTypeInterface::ReferenceClassHelper { using type = ParametricType; };

/// Intermediate helper class for ParametricTypeInterface.
template <typename S> class ParametricTypeInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ParametricType, false>::type&() const { return reinterpret_cast<const ParametricType&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, ParametricType, false>::type&() { return reinterpret_cast<const ParametricType&>(this->GetBaseRef()); }
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type GetId() const;
	inline Result<const DataType*> Instantiate(const Block<const Member>& args, const Block<const Int64>& iargs) const;
	inline Result<const DataType*> Instantiate(const DataType* type, const Block<const Int64>& iargs = GetZeroRef<Block<const Int64>>()) const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsBaseOfOrSame(const DataType* type, const DataType* other) const;
	inline Result<void> Convert(const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) const;
	inline Result<Tuple<const DataType*, const Char*>> Parse(const Char* params) const;
	inline Result<const DataType*> Substitute(const DataType* orig, const Delegate<Result<const DataType*>(const DataType*)>& replace) const;
};
#ifdef DOXYGEN
template <typename REF> class ParametricTypeInterface::ConstReferenceFunctionsImplDoxy : public ParametricTypeInterface::ConstReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for ParametricTypeInterface.
template <typename S> class ParametricTypeInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class ParametricTypeInterface::ReferenceFunctionsImplDoxy : public ParametricTypeInterface::ReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for ParametricTypeInterface.
template <typename S> class ParametricTypeInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class ParametricTypeInterface::COWReferenceFunctionsImplDoxy : public ParametricTypeInterface::COWReferenceFunctionsImpl<REF> { };
#endif

template <typename ST> struct ParametricTypeInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type>::type; };
class ParametricTypeInterface::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<ParametricType>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const ParametricTypeInterface, maxon::StrongRefHandler, ParametricType>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const ParametricTypeInterface, maxon::StrongRefHandler, ParametricType>>>>);
	using NonConst = NonConstRef;
};

class ParametricTypeInterface::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<ParametricTypeInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<ParametricTypeInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// ParametricType is the reference class of ParametricTypeInterface.
class ParametricType : public ParametricTypeInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ParametricType, Reference);
};

#endif
