// This file contains default implementations for the interfaces of fft.h. They are intended for copy&paste usage only.

class MyFFTImpl : public maxon::Component<MyFFTImpl, FFTInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Transform1D(const ArrayInterface<Generic>& in, WritableArrayInterface<Generic>& out, FFT_FLAGS fftFlags) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Transform2D(const ConstMatrixNxMInterface& in, const MatrixNxMInterface& out, FFT_FLAGS fftFlags) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD FFT_SUPPORT GetSupportOptions() const
	{
		return maxon::PrivateIncompleteNullReturnValue<FFT_SUPPORT>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
