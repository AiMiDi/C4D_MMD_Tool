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
		using PrivateInterface = ParametricTypeInterface;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(ParametricTypeInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::PointerHandler, ParametricType, false>::type&() const { return reinterpret_cast<const ParametricType&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::PointerHandler, ParametricType, false>::type&() { return reinterpret_cast<const ParametricType&>(this->GetBaseRef()); }
/// Returns the identifier of the parametric type. Usually this is also used as prefix
/// for the identifiers of instantiates types, but there are exceptions for basic parametric
/// types such as for const, tuples or arrays.
/// @return												Identifier of parametric type.
		inline HXXADDRET2(const Id&) GetId() const;
/// Instantiates this parametric type for the given arguments. This is the general method
/// which supports members and integers as arguments, you can use one of the simpler overloads
/// for common cases like type-only arguments.
/// @param[in] args								The arguments for Member parameters of this parametric type.
/// 															The identifier part of a Member has to be left empty if the
/// 															parametric type needs a DataType only.
/// @param[in] iargs							The arguments for Int64 parameters of this parametric type
/// 															(for example the dimension of a vector).
/// @return												The instantiated DataType for the given arguments.
		inline Result<DataType> Instantiate(const Block<const Member>& args, const Block<const Int64>& iargs = GetZeroRef<Block<const Int64>>()) const;
/// Instantiates this parametric type for the given arguments. This overload can be used for
/// parametric types with a single DataType parameter (plus optionally some integer parameters).
/// @param[in] type								The argument for the single DataType parameter of this parametric type.
/// @param[in] iargs							The optional arguments for Int64 parameters of this parametric type.
/// @return												The instantiated DataType for the given arguments.
		inline Result<DataType> Instantiate(const DataType& type, const Block<const Int64>& iargs = GetZeroRef<Block<const Int64>>()) const;
/// Instantiates this parametric type for the given arguments. This overload can be used for
/// parametric types with a single DataType parameter (plus optionally some integer parameters).
/// For convenience the type parameter of this overload supports Result<DataType>, so you can
/// directly pass the result of some other function with Result<DataType> return type to this parameter.
/// @param[in] type								The argument for the single DataType parameter of this parametric type.
/// @param[in] iargs							The optional arguments for Int64 parameters of this parametric type.
/// @return												The instantiated DataType for the given arguments.
		inline Result<DataType> Instantiate(Result<DataType>&& type, const Block<const Int64>& iargs = GetZeroRef<Block<const Int64>>()) const;
/// Instantiates this parametric type for the given arguments. This overload can be used for
/// parametric types with a number of DataType parameters (plus optionally some integer parameters).
/// @param[in] types							The arguments for the DataType parameters of this parametric type.
/// @param[in] iargs							The optional arguments for Int64 parameters of this parametric type.
/// @return												The instantiated DataType for the given arguments.
		inline Result<DataType> Instantiate(const Block<const DataType>& types, const Block<const Int64>& iargs = GetZeroRef<Block<const Int64>>()) const;
/// Checks if the given type is a base type of the @p other type (or the same).
/// At least one of the types is an instantiation of this parametric type.
/// This method is invoked from DataType::IsBaseOfOrSame, and when type and other have different parametric types,
/// it will be invoked twice, once for each parametric type. If at least one of these invocations returns true,
/// the result of DataType::IsBaseOfOrSame is true.
/// @param[in] type								A data type.
/// @param[in] other							Another data type.
/// @return												True if type is a base type of other.
		inline HXXADDRET2(Bool) IsBaseOfOrSame(const DataType& type, const DataType& other) const;
/// Converts the value #src to the value #dest (the type of which has to be an instantiation of this parametric type).
/// @param[in] dest								The destination value, it has to use an instantiation of this parametric type.
/// @param[in] src								The source value.
/// @param[in] ignore							Only those conversions are taken into account whose conversion flags aren't set in #ignore.
/// @return												OK on success. If there is no conversion from the source type at all,
/// 															an UnsupportedArgumentError is returned. For narrowing conversions other errors may occur,
/// 															such as when the representable range is exceeded.
		inline Result<void> Convert(const DataPtr& dest, const ConstDataPtr& src, CONVERSION_FLAGS ignore) const;
/// Parses an instantiation of this parametric type from a part of a data type identifier.
/// params points to the first character after the opening angular bracket. The returned character
/// pointer has to point to the closing angular bracket. For example, when the full data type identifier
/// is "net.maxon.parametrictype.vec<3,float32>" the Parse method of ParametricTypes::Vec will be called
/// with params pointing to "3", and it returns the data type of Vector32 plus a character pointer to ">".
/// @param[in] params							Pointer to a part of a data type identifier.
/// @return												Tuple of the parsed data type instantiation and a pointer to the closing angular bracket.
		inline Result<Tuple<DataType, const Char*>> Parse(const Char* params) const;
		inline HXXADDRET2(void) ResetInstantiated(DataTypeImpl* type) const;
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
///
/// A ParametricType instantiates a new DataType from a number of more elementary data types.
/// For example, ParametricTypes::Vec instantiates a vector type from its element type and the number
/// of dimensions, ParametricTypes::Tuple instantiates a tuple type from member types,
/// and ParametricTypes::Const instantiates the const-qualified version of a given type.
/// Possible parameters of a ParametricType are not only types, but also Members
/// (type/id pairs) and integers.
class ParametricType : public ParametricTypeInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(ParametricType, typename ParametricTypeInterface::Hxx1::Reference);
};

#endif
