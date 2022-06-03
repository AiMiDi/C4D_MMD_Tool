#if 1
class ParametricType;

struct ParametricTypeInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = ParametricType;
	/// Intermediate helper class for ParametricTypeInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(ParametricTypeInterface**);
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
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename ST::type>
	> { };
};
class ParametricTypeInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<ParametricType>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const ParametricTypeInterface, maxon::PointerHandler, ParametricType>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const ParametricTypeInterface, maxon::PointerHandler, ParametricType>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class ParametricTypeInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ParametricTypeInterface, maxon::PointerHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ParametricTypeInterface, maxon::PointerHandler, NonConstRef>>>>);
};

/// ParametricType is the reference class of ParametricTypeInterface.
class ParametricType : public ParametricTypeInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ParametricType, typename ParametricTypeInterface::Hxx1::Reference);
};

#endif
