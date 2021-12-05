// This file contains decorator implementations for the interfaces of units.h. They are intended for copy&paste usage only.

class DimensionDecoratorImpl : public maxon::Component<DimensionDecoratorImpl, DimensionInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const Id& GetId() const
	{
		return maxon::Cast<Dimension>(self.GetDecoratedObject()).GetId();
	}

	MAXON_METHOD Result<Dimension> operatorMul(const Result<Dimension>& q) const
	{
		return maxon::Cast<Dimension>(self.GetDecoratedObject()).operator *(q);
	}

	MAXON_METHOD Result<Dimension> operatorDiv(const Result<Dimension>& q) const
	{
		return maxon::Cast<Dimension>(self.GetDecoratedObject()).operator /(q);
	}

	MAXON_METHOD Result<Dimension> operatorXor(Int exponent) const
	{
		return maxon::Cast<Dimension>(self.GetDecoratedObject()).operator ^(exponent);
	}

	MAXON_METHOD Result<Dimension> Copy(const Id& qid) const
	{
		return maxon::Cast<Dimension>(self.GetDecoratedObject()).Copy(qid);
	}

	MAXON_METHOD Int GetExponent(BASE_DIMENSION q) const
	{
		return maxon::Cast<Dimension>(self.GetDecoratedObject()).GetExponent(q);
	}

	MAXON_METHOD Result<Unit> AddUnit(const Id& unitId, Float siConversionFactor) const
	{
		return maxon::Cast<Dimension>(self.GetDecoratedObject()).AddUnit(unitId, siConversionFactor);
	}

	MAXON_METHOD UnitsArray GetUnits() const
	{
		return maxon::Cast<Dimension>(self.GetDecoratedObject()).GetUnits();
	}

	MAXON_METHOD Bool IsEquivalent(const Dimension& other) const
	{
		return maxon::Cast<Dimension>(self.GetDecoratedObject()).IsEquivalent(other);
	}

	MAXON_METHOD String ToString(const FormatStatement* fs) const
	{
		return maxon::Cast<Dimension>(self.GetDecoratedObject()).ToString(fs);
	}

};
