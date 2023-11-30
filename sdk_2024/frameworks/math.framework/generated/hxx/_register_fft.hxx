#if 1
namespace maxon
{
	namespace enum21
	{
		enum class FFT_FLAGS
		{
			NONE		         = 0,
			CALC_INVERSE     = (1 << 0), ///< If set, the reverse transformation from frequency domain to time domain is computed.
			SUPPRESS_PADDING = (1 << 1)  ///< Suppress automatic padding. Note: Most implementations run faster if the input array count is even or a power of 2. But padding changes the output array count and fills the remaning array entries with zeros. This leads to a slightly different output since padding with zeros in the time domain effectively means interpolating in the frequency domain. For some critical applications it might be advisable to leave the original array size intact. Works only if the implementation supports this feature, otherwise the flag is ignored
		
		} ;
		static const maxon::UInt64 FFT_FLAGS_values[] = {maxon::UInt64(enum21::FFT_FLAGS::NONE), maxon::UInt64(enum21::FFT_FLAGS::CALC_INVERSE), maxon::UInt64(enum21::FFT_FLAGS::SUPPRESS_PADDING)};
		static const maxon::EnumInfo FFT_FLAGS_info{"FFT_FLAGS", SIZEOF(FFT_FLAGS), true, "NONE\0CALC_INVERSE\0SUPPRESS_PADDING\0", FFT_FLAGS_values, std::extent<decltype(FFT_FLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_FFT_FLAGS21(){ return enum21::FFT_FLAGS_info; }
	namespace enum30
	{
		enum class FFT_SUPPORT
		{
			NONE	         = 0,
			TRANSFORM_1D   = (1 << 0), ///< Component supports 1D transformation.
			TRANSFORM_2D   = (1 << 1), ///< Component supports 2D transformation.
			ALWAYS_PADDING = (1 << 2)  ///< If set component always does padding of the input array (e.g. power of 2).
		} ;
		static const maxon::UInt64 FFT_SUPPORT_values[] = {maxon::UInt64(enum30::FFT_SUPPORT::NONE), maxon::UInt64(enum30::FFT_SUPPORT::TRANSFORM_1D), maxon::UInt64(enum30::FFT_SUPPORT::TRANSFORM_2D), maxon::UInt64(enum30::FFT_SUPPORT::ALWAYS_PADDING)};
		static const maxon::EnumInfo FFT_SUPPORT_info{"FFT_SUPPORT", SIZEOF(FFT_SUPPORT), true, "NONE\0TRANSFORM_1D\0TRANSFORM_2D\0ALWAYS_PADDING\0", FFT_SUPPORT_values, std::extent<decltype(FFT_SUPPORT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_FFT_SUPPORT30(){ return enum30::FFT_SUPPORT_info; }
	const maxon::Char* const FFTInterface::MTable::_ids = 
		"Transform1D@6abbf16748acd0dc\0" // Result<void> Transform1D(const ArrayInterface<Generic>& in, WritableArrayInterface<Generic>& out, FFT_FLAGS fftFlags) const
		"Transform2D@a553ae00129f1334\0" // Result<void> Transform2D(const ConstMatrixNxMInterface& in, const MatrixNxMInterface& out, FFT_FLAGS fftFlags) const
		"GetSupportOptions@4e91c08f3d0d475e\0" // FFT_SUPPORT GetSupportOptions() const
	"";
	const maxon::METHOD_FLAGS FFTInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(FFTInterface, , "net.maxon.interface.fft", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int FFTInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<FFT_SUPPORT>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(FFTClasses);
	namespace FFTClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Generic, , "net.maxon.fftclass.generic");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Kiss, , "net.maxon.fftclass.kiss");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Cooley, , "net.maxon.fftclass.cooley");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_fft(0
	| maxon::FFTInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
