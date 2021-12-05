// This file contains default implementations for the interfaces of cryptography.h. They are intended for copy&paste usage only.

class MyCryptographyStreamConversionImpl : public Component<MyCryptographyStreamConversionImpl, CryptographyStreamConversionInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Bool IsChainingChiffre() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

};
