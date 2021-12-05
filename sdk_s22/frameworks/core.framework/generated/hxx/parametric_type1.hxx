#if 1
class ParametricType;

struct ParametricTypeInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = ParametricType;
	/// Intermediate helper class for ParametricTypeInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::PointerHandler, ParametricType, false>::type&() const { return reinterpret_cast<const ParametricType&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::PointerHandler, ParametricType, false>::type&() { return reinterpret_cast<const ParametricType&>(this->GetBaseRef()); }
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type GetId() const;
		inline Result<DataType> Instantiate(const Block<const Member>& args, const Block<const Int64>& iargs = GetZeroRef<Block<const Int64>>()) const;
		inline Result<DataType> Instantiate(const DataType& type, const Block<const Int64>& iargs = GetZeroRef<Block<const Int64>>()) const;
		inline Result<DataType> Instantiate(const Block<const DataType>& types, const Block<const Int64>& iargs = GetZeroRef<Block<const Int64>>()) const;
		inline Result<DataType> Instantiate(Result<DataType>&& type, const Block<const Int64>& iargs = GetZeroRef<Block<const Int64>>()) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsBaseOfOrSame(const DataType& type, const DataType& other) const;
		inline Result<void> Convert(const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) const;
		inline Result<Tuple<DataType, const Char*>> Parse(const Char* params) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type ResetInstantiated(DataTypeImpl* type) const;
	};
	/// Intermediate helper class for ParametricTypeInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	/// Intermediate helper class for ParametricTypeInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class ParametricTypeInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstReferenceFunctionsImplDoxy<ParametricType>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ParametricTypeInterface, maxon::PointerHandler, ParametricType>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<const ParametricTypeInterface, maxon::PointerHandler, ParametricType>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ParametricTypeInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<NonConstRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ParametricTypeInterface, maxon::PointerHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<ParametricTypeInterface, maxon::PointerHandler, NonConstRef>>>>);
};

/// ParametricType is the reference class of ParametricTypeInterface.
class ParametricType : public ParametricTypeInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ParametricType, typename ParametricTypeInterface::Hxx1::Reference);
};

#endif
