#if 1
struct FFTInterface::HasBase { template <typename I> struct Check { static const maxon::Bool value = std::is_same<I, FFTInterface>::value || Object::HasBase::Check<I>::value; static I* Cast(FFTInterface* ptr) { return static_cast<I*>(static_cast<maxon::Object*>(ptr)); } }; };
class FFTRef;

struct FFTInterface::ReferenceClassHelper { using type = FFTRef; };

/// Intermediate helper class for FFTInterface.
template <typename S> class FFTInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Computes a one dimensional FFT transformation
/// Note:
/// The count of the input array can be an arbitrary number.
/// The size of the output array is automatically adjusted if necessary and might be greater than the input array due to padding (some implementations get a speedup factor of 1000x and more from this)
/// Note 1: padding changes the output array count and fills the remaning array entries with zeros.
/// This leads to a slightly different output since padding with zeros in the time domain effectively means interpolating in the frequency domain.
/// For some critical applications it might be advisable to leave the original array size intact and hence set the SUPPRESS_PADDING option (works only if the implementation supports no padding)
/// Note 2: Usually FFT conversion means using an input array of complex data and get a transformed output array of complex data too.
/// On the other hand for many applications the input data (time domain) is pure real data without any imaginary (phase) data. The interface automatically acounts for this and allows the user to either input complex or pure float arrays alternatively. Same goes for the output array.
/// But please note even if it is possible to use float arrays both as input and output array this is not advisable since you loose vital phase information for inverse transformation. Only if you dont rely on any phase information and you dont plan on inverting the data this combination might be useful.
/// At the moment the implementation supports the types Float32, Float64, Complex32 and Complex64.
/// Check for FFT_SUPPORT::TRANSFORM_1D if component supports this function
	inline Result<void> Transform1D(const ArrayInterface<Generic>& in, WritableArrayInterface<Generic>& out, FFT_FLAGS fftFlags = FFT_FLAGS::NONE) const;
/// Computes a one dimensional FFT transformation
/// Note:
/// The count of the input array can be an arbitrary number.
/// The size of the output array is automatically adjusted if necessary and might be greater than the input array due to padding (some implementations get a speedup factor of 1000x and more from this)
/// Note 1: padding changes the output array count and fills the remaning array entries with zeros.
/// This leads to a slightly different output since padding with zeros in the time domain effectively means interpolating in the frequency domain.
/// For some critical applications it might be advisable to leave the original array size intact and hence set the SUPPRESS_PADDING option (works only if the implementation supports no padding)
/// Note 2: Usually FFT conversion means using an input array of complex data and get a transformed output array of complex data too.
/// On the other hand for many applications the input data (time domain) is pure real data without any imaginary (phase) data. The interface automatically acounts for this and allows the user to either input complex or pure float arrays alternatively. Same goes for the output array.
/// But please note even if it is possible to use float arrays both as input and output array this is not advisable since you loose vital phase information for inverse transformation. Only if you dont rely on any phase information and you dont plan on inverting the data this combination might be useful.
/// At the moment the implementation supports the types Float32, Float64, Complex32 and Complex64
/// Check for FFT_SUPPORT::TRANSFORM_2D if component supports this function
	inline Result<void> Transform2D(const ConstMatrixNxMInterface& in, const MatrixNxMInterface& out, FFT_FLAGS fftFlags = FFT_FLAGS::NONE) const;
/// Returns the supported flags
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<FFT_SUPPORT>, FFT_SUPPORT>::type GetSupportOptions() const;
};
#ifdef DOXYGEN
template <typename REF> class FFTInterface::ConstReferenceFunctionsImplDoxy : public FFTInterface::ConstReferenceFunctionsImpl<REF>, public Object::ConstReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for FFTInterface.
template <typename S> class FFTInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FFTRef, true>::type&() const { return reinterpret_cast<const FFTRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, FFTRef, false>::type&() { return reinterpret_cast<const FFTRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class FFTInterface::ReferenceFunctionsImplDoxy : public FFTInterface::ReferenceFunctionsImpl<REF>, public Object::ReferenceFunctionsImplDoxy<REF> { };
#endif

/// Intermediate helper class for FFTInterface.
template <typename S> class FFTInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, FFTRef, false>::type&() { return reinterpret_cast<const FFTRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class FFTInterface::COWReferenceFunctionsImplDoxy : public FFTInterface::COWReferenceFunctionsImpl<REF>, public Object::COWReferenceFunctionsImplDoxy<REF> { };
#endif

template <typename ST> struct FFTInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>, ReferenceFunctionsImpl<typename Object::ReferenceFunctions<ST>::type>>::type>::type; };
class FFTInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<FFTRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<FFTInterface, maxon::StrongRefHandler, FFTRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<FFTInterface, maxon::StrongRefHandler, FFTRef>>>>);
	using NonConst = Super::ReferenceClass;
};

/// FFTRef is the reference class of FFTInterface.
class FFTRef : public FFTInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(FFTRef, Reference);
};

#endif
