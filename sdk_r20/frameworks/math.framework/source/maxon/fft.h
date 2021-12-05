#ifndef FFT_H__
#define FFT_H__

#include "maxon/objectbase.h"
#include "maxon/matrix_nxm.h"
#include "maxon/array.h"

namespace maxon
{




/// Flags for the FFT transform.
enum class FFT_FLAGS
{
	NONE		         = 0,
	CALC_INVERSE     = (1 << 0), ///< If set, the reverse transformation from frequency domain to time domain is computed.
	SUPPRESS_PADDING = (1 << 1)  ///< Suppress automatic padding. Note: Most implementations run faster if the input array count is even or a power of 2. But padding changes the output array count and fills the remaning array entries with zeros. This leads to a slightly different output since padding with zeros in the time domain effectively means interpolating in the frequency domain. For some critical applications it might be advisable to leave the original array size intact. Works only if the implementation supports this feature, otherwise the flag is ignored

} MAXON_ENUM_FLAGS(FFT_FLAGS);

/// Flags for GetSupportOptions()
enum class FFT_SUPPORT
{
	NONE	         = 0,
	TRANSFORM_1D   = (1 << 0), ///< Component supports 1D transformation.
	TRANSFORM_2D   = (1 << 1), ///< Component supports 2D transformation.
	ALWAYS_PADDING = (1 << 2)  ///< If set component always does padding of the input array (e.g. power of 2).
} MAXON_ENUM_FLAGS(FFT_SUPPORT);


class FFTInterface : MAXON_INTERFACE_BASES(Object)
{
	MAXON_INTERFACE(FFTInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.fft");

public:

	//----------------------------------------------------------------------------------------
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
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Transform1D(const ArrayInterface<Generic>& in, WritableArrayInterface<Generic>& out,  FFT_FLAGS fftFlags = FFT_FLAGS::NONE) const;


	//----------------------------------------------------------------------------------------
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
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Transform2D(const ConstMatrixNxMInterface& in, const MatrixNxMInterface& out, FFT_FLAGS fftFlags = FFT_FLAGS::NONE) const;

	//----------------------------------------------------------------------------------------
	/// Returns the supported flags
	//----------------------------------------------------------------------------------------
	MAXON_METHOD FFT_SUPPORT GetSupportOptions() const;
};

// include autogenerated headerfile here
#include "fft1.hxx"

//----------------------------------------------------------------------------------------
/// Registry to register/iterate all available FFT implementations.
//----------------------------------------------------------------------------------------
MAXON_REGISTRY(Class<FFTRef>, FFTClasses, "net.maxon.registry.fftclasses");

//----------------------------------------------------------------------------------------
/// Publish generic FFT routine
//----------------------------------------------------------------------------------------
namespace FFTClasses
{
	/// Generic but slow fft algorithm (c4d legacy). Works with any number of input data
	MAXON_DECLARATION(FFTClasses::EntryType, Generic, "net.maxon.fftclass.generic");

	/// Fast fft algorithm using the KISS library. Works with any number of input data but can when not using FFT_FLAGS::SUPPRESS_PADDING the algorithm can be up to 1000x faster
	MAXON_DECLARATION(FFTClasses::EntryType, Kiss, "net.maxon.fftclass.kiss");

	/// Cooley Tukey algorithm.
	MAXON_DECLARATION(FFTClasses::EntryType, Cooley, "net.maxon.fftclass.cooley");
}

// include autogenerated headerfile here
#include "fft2.hxx"

}

#endif // FFT_H__
