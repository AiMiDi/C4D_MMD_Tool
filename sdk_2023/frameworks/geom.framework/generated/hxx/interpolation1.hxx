#if 1
class InterpolateType;

struct InterpolateTypeInterface::HasBaseDetector { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, InterpolateTypeInterface>::value || ObjectInterface::HasBaseDetector::template Check<I>::value; static I* Cast(InterpolateTypeInterface* ptr) { return reinterpret_cast<I*>(ptr); } }; };
struct InterpolateTypeInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = InterpolateType;
	template <template <typename...> class TEMPL> using SubstituteBases = TEMPL<ObjectInterface>;
	/// Intermediate helper class for InterpolateTypeInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(InterpolateTypeInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, InterpolateType, false>::type&() const { return reinterpret_cast<const InterpolateType&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, InterpolateType, false>::type&() { return reinterpret_cast<const InterpolateType&>(this->GetBaseRef()); }
/// Returns the datatype this class manages, e.g. Vector2d32
/// @return												The datatype.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type GetInterpolateDataType() const;
/// Interpolates linearly between two data values. Both addresses must be cast to the appropriate datatype.
/// @param[in,out] data1					The address of the first value. The value will be overwritten with the result.
/// @param[in] data2							The address of the second value.
/// @param[in] blend							The blend percentage [0.0..blend..1.0]
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type InterpolateLinear(void* data1, const void* data2, Float blend) const;
/// Interpolates a value in the polygon outline using given weights. The addresses in data and outline need to be cast to the appropriate datatype.
/// @param[in,out] data						The address of the value. The value will be overwritten with the result.
/// @param[in] outline						The outline data used to perform the interpolation.
/// @param[in] weights						Weights to use for the interpolation; represent the interpolation distance from each outline edge.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const;
/// Averages values in dataSet and stores the result under the specified data pointer.
/// @param[in,out] data						The resulting data pointer to be filled. The caller owns the memory.
/// @param[in] dataSet						The data set to average.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Average(void* data, const Block<const void*>& dataSet) const;
/// Interpolates bilinearly between four data values. All addresses must be cast to the appropriate datatype.
/// @param[in,out] data1					The address of the first value. The value will be overwritten with the result.
/// @param[in] data2							The address of the second value.
/// @param[in] data3							The address of the third value.
/// @param[in] data4							The address of the fourth value.
/// @param[in] blendS							The first blend percentage [0.0..blend..1.0]. Interpolation Scheme [data1 .. blendS .. data2] and [data4 .. blendS .. data3].
/// @param[in] blendT							The second blend percentage [0.0..blend..1.0]. Interpolation Scheme [blendS1 .. blendT .. blendS2]
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type InterpolateBilinear(const DataTypePtr dataType, void* data1, const void* data2, const void* data3, const void* data4, Float blendS, Float blendT) const;
/// Return the interpolation class for the passed data type if exist.
/// @param[in] datatype						The DataType.
/// @return												The interpolation class or an empty class if do not exist.
		static inline InterpolateType GetInterpolationClass(const DataType& datatype);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	false, void,
	ConstFn<typename ObjectInterface::Hxx1::template FnHelper<ST>::type>
	> { };
};
class InterpolateTypeInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ConstFnDoxy<InterpolateType>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const InterpolateTypeInterface, maxon::StrongRefHandler, InterpolateType>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const InterpolateTypeInterface, maxon::StrongRefHandler, InterpolateType>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class InterpolateTypeInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<InterpolateTypeInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<InterpolateTypeInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// InterpolateType is the reference class of InterpolateTypeInterface.
class InterpolateType : public InterpolateTypeInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(InterpolateType, typename InterpolateTypeInterface::Hxx1::Reference);
};

#endif
