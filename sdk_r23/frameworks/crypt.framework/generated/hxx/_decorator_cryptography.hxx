// This file contains decorator implementations for the interfaces of cryptography.h. They are intended for copy&paste usage only.

class CryptographyStreamConversionDecoratorImpl : public maxon::Component<CryptographyStreamConversionDecoratorImpl, CryptographyStreamConversionInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Bool IsChainingChiffre() const
	{
		return maxon::Cast<CryptographyStreamConversionRef>(self.GetDecoratedObject()).IsChainingChiffre();
	}

};
