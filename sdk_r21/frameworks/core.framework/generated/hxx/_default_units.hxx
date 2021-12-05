// This file contains default implementations for the interfaces of units.h. They are intended for copy&paste usage only.

class MyDimensionImpl : public maxon::Component<MyDimensionImpl, DimensionInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const Id& GetId() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<Dimension> operatorMul(const Result<Dimension>& q) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Dimension> operatorDiv(const Result<Dimension>& q) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Dimension> operatorXor(Int exponent) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Dimension> Copy(const Id& qid) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Int GetExponent(BASE_DIMENSION q) const
	{
		return 0;
	}

	MAXON_METHOD Result<Unit> AddUnit(const Id& unitId, Float siConversionFactor) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD UnitsArray GetUnits() const
	{
		return maxon::PrivateIncompleteNullReturnValue<UnitsArray>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool IsEquivalent(const Dimension& other) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD String ToString(const FormatStatement* fs) const
	{
		return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
