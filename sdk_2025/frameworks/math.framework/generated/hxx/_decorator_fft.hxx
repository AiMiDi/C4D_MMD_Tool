// This file contains decorator implementations for the interfaces of fft.h. They are intended for copy&paste usage only.

class FFTDecoratorImpl : public maxon::Component<FFTDecoratorImpl, FFTInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Transform1D(const ArrayInterface<Generic>& in, WritableArrayInterface<Generic>& out, FFT_FLAGS fftFlags) const
	{
		return maxon::Cast<FFTRef>(self.GetDecoratedObject()).Transform1D(in, out, fftFlags);
	}

	MAXON_METHOD Result<void> Transform2D(const ConstMatrixNxMInterface& in, const MatrixNxMInterface& out, FFT_FLAGS fftFlags) const
	{
		return maxon::Cast<FFTRef>(self.GetDecoratedObject()).Transform2D(in, out, fftFlags);
	}

	MAXON_METHOD FFT_SUPPORT GetSupportOptions() const
	{
		return maxon::Cast<FFTRef>(self.GetDecoratedObject()).GetSupportOptions();
	}

};
