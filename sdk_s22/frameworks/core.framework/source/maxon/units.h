#ifndef UNITS_H__
#define UNITS_H__

#include "maxon/object.h"

namespace maxon
{

enum class BASE_DIMENSION
{
	LENGTH,
	TIME,
	MASS,
	TEMPERATURE,
	AMOUNT_OF_SUBSTANCE,
	ELECTRIC_CURRENT,
	LUMINOUS_INTENSITY,
	ANGLE,
	SOLID_ANGLE,
	PRIVATE_COUNT
} MAXON_ENUM_LIST(BASE_DIMENSION);

class Unit;
class Dimension;

using UnitsArray = StrongCOWRef<BaseArray<Unit>>;

class DimensionInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(DimensionInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.dimension");
	MAXON_INTERFACE_SINGLE_IMPLEMENTATION;

public:
	static MAXON_METHOD const Dimension& Get(BASE_DIMENSION q);

	MAXON_METHOD const Id& GetId() const;

	MAXON_METHOD Result<Dimension> operator *(const Result<Dimension>& q) const;

	MAXON_METHOD Result<Dimension> operator /(const Result<Dimension>& q) const;

	MAXON_METHOD Result<Dimension> operator ^(Int exponent) const;

	MAXON_METHOD Result<Dimension> Copy(const Id& qid) const;

	MAXON_METHOD Int GetExponent(BASE_DIMENSION q) const;

	MAXON_METHOD Result<Unit> AddUnit(const Id& unitId, Float siConversionFactor) const;

	MAXON_METHOD UnitsArray GetUnits() const;

	MAXON_METHOD Bool IsEquivalent(const Dimension& other) const;

	MAXON_METHOD String ToString(const FormatStatement* fs) const;
};

class UnitInterface // : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE_NONVIRTUAL(UnitInterface, MAXON_REFERENCE_CONST, "net.maxon.interface.unit");
	// MAXON_INTERFACE_SINGLE_IMPLEMENTATION;

public:
	MAXON_METHOD const Id& GetId() const;

	MAXON_METHOD const Dimension& GetDimension() const;

	MAXON_METHOD Float GetSIConversionFactor() const;

	MAXON_METHOD Result<Unit> operator *(const Result<Unit>& u) const;

	MAXON_METHOD Result<Unit> operator /(const Result<Unit>& u) const;

	MAXON_METHOD Result<Unit> operator ^(Int exponent) const;

	MAXON_METHOD Result<Unit> Copy(const Id& uid) const;

	MAXON_METHOD Result<Unit> Copy(const Dimension& quantity) const;

	MAXON_METHOD Result<void> AddToDimension() const;

	MAXON_METHOD Result<Unit> Reduce() const;

	MAXON_METHOD String ToString(const FormatStatement* fs) const;
};

#include "units1.hxx"

MAXON_REGISTRY(Dimension, Dimensions, "net.maxon.registry.dimensions");

namespace Dimensions
{
	MAXON_DECLARATION(Dimension, Length, "net.maxon.dimension.length");
	MAXON_DECLARATION(Dimension, Time, "net.maxon.dimension.time");
	MAXON_DECLARATION(Dimension, Mass, "net.maxon.dimension.mass");
	MAXON_DECLARATION(Dimension, Temperature, "net.maxon.dimension.temperature");
	MAXON_DECLARATION(Dimension, AmountOfSubstance, "net.maxon.dimension.amountofsubstance");
	MAXON_DECLARATION(Dimension, ElectricCurrent, "net.maxon.dimension.electriccurrent");
	MAXON_DECLARATION(Dimension, LuminousIntensity, "net.maxon.dimension.luminousintensity");
	MAXON_DECLARATION(Dimension, Angle, "net.maxon.dimension.angle");
	MAXON_DECLARATION(Dimension, SolidAngle, "net.maxon.dimension.solidangle");

	MAXON_DECLARATION(Dimension, Velocity, "net.maxon.dimension.velocity");
	MAXON_DECLARATION(Dimension, Density, "net.maxon.dimension.density");
}

MAXON_REGISTRY(Unit, Units, "net.maxon.registry.units");

namespace Units
{
	MAXON_DECLARATION(Unit, m, "net.maxon.unit.m");
	MAXON_DECLARATION(Unit, cm, "net.maxon.unit.cm");
	MAXON_DECLARATION(Unit, ft, "net.maxon.unit.ft");
	MAXON_DECLARATION(Unit, kg, "net.maxon.unit.kg");
	MAXON_DECLARATION(Unit, s, "net.maxon.unit.s");
	MAXON_DECLARATION(Unit, K, "net.maxon.unit.k");
	MAXON_DECLARATION(Unit, mol, "net.maxon.unit.mol");
	MAXON_DECLARATION(Unit, A, "net.maxon.unit.a");
	MAXON_DECLARATION(Unit, cd, "net.maxon.unit.cd");
	MAXON_DECLARATION(Unit, rad, "net.maxon.unit.rad");
	MAXON_DECLARATION(Unit, sr, "net.maxon.unit.sr");
}

#include "units2.hxx"

} // namespace maxon

#endif // UNITS_H__
