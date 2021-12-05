#if 1
namespace maxon
{
	namespace enum21 { enum class BASE_DIMENSION
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
	} ; }
	maxon::String PrivateToString_BASE_DIMENSION21(std::underlying_type<enum21::BASE_DIMENSION>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum21::BASE_DIMENSION::LENGTH, (maxon::UInt64) enum21::BASE_DIMENSION::TIME, (maxon::UInt64) enum21::BASE_DIMENSION::MASS, (maxon::UInt64) enum21::BASE_DIMENSION::TEMPERATURE, (maxon::UInt64) enum21::BASE_DIMENSION::AMOUNT_OF_SUBSTANCE, (maxon::UInt64) enum21::BASE_DIMENSION::ELECTRIC_CURRENT, (maxon::UInt64) enum21::BASE_DIMENSION::LUMINOUS_INTENSITY, (maxon::UInt64) enum21::BASE_DIMENSION::ANGLE, (maxon::UInt64) enum21::BASE_DIMENSION::SOLID_ANGLE, (maxon::UInt64) enum21::BASE_DIMENSION::PRIVATE_COUNT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "BASE_DIMENSION", SIZEOF(x), false, values, "LENGTH\0TIME\0MASS\0TEMPERATURE\0AMOUNT_OF_SUBSTANCE\0ELECTRIC_CURRENT\0LUMINOUS_INTENSITY\0ANGLE\0SOLID_ANGLE\0PRIVATE_COUNT\0", fmt);
	}
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class DimensionInterface::Hxx2::Unresolved : public DimensionInterface
	{
	public:
		static const Dimension& Get(BASE_DIMENSION q) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, true)) return DimensionInterface::Get(q); return maxon::PrivateIncompleteNullReturnValue<const Dimension&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE DimensionInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<const Dimension&>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool DimensionInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Dimension&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_DimensionInterface_Get = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DimensionInterface_Get;
		#else
		tbl->_DimensionInterface_Get = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_DimensionInterface_Get;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	typename DimensionInterface::MTable::NVMTable DimensionInterface::MTable::NVMTable::_instance;
	const maxon::Char* const DimensionInterface::MTable::_ids = 
		"GetId@12b0ccb12f8b105\0" // const Id& GetId() const
		"operatorMul@60a2ef764f095682\0" // Result<Dimension> operatorMul(const Result<Dimension>& q) const
		"operatorDiv@60a2ef764f095682\0" // Result<Dimension> operatorDiv(const Result<Dimension>& q) const
		"operatorXor@76a1633f465522b7\0" // Result<Dimension> operatorXor(Int exponent) const
		"Copy@55feb5b45a95d158\0" // Result<Dimension> Copy(const Id& qid) const
		"GetExponent@77447f87e1e7bd2e\0" // Int GetExponent(BASE_DIMENSION q) const
		"AddUnit@d10845b928d3cd84\0" // Result<Unit> AddUnit(const Id& unitId, Float siConversionFactor) const
		"GetUnits@1f43676fcafb6e41\0" // UnitsArray GetUnits() const
		"IsEquivalent@08a9aecab537ea24\0" // Bool IsEquivalent(const Dimension& other) const
		"ToString@7de9f6f51c89c899\0" // String ToString(const FormatStatement* fs) const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE_SINGLE_IMPL(DimensionInterface, , "net.maxon.interface.dimension", "maxon.DimensionInterface", (&ObjectInterface::_interface));
	const maxon::Char* const DimensionInterface::Hxx2::StaticMTable::_ids = 
		"Get@452403d3724951c5\0" // const Dimension& Get(BASE_DIMENSION q)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(DimensionInterface, , "net.maxon.interface.dimension");
	template <typename DUMMY> maxon::Int DimensionInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<UnitsArray>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Dimension&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Id&>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const UnitInterface::MTable::_ids = 
		"Free@2f7539d6aecbaf82\0" // void Free(const UnitInterface* object)
		"GetId@12b0ccb12f8b105\0" // const Id& GetId() const
		"GetDimension@cdf704d8301ba9b4\0" // const Dimension& GetDimension() const
		"GetSIConversionFactor@f358997b3\0" // Float GetSIConversionFactor() const
		"operatorMul@f43d2c532d50aff4\0" // Result<Unit> operatorMul(const Result<Unit>& u) const
		"operatorDiv@f43d2c532d50aff4\0" // Result<Unit> operatorDiv(const Result<Unit>& u) const
		"operatorXor@56c7f1da3f9822f3\0" // Result<Unit> operatorXor(Int exponent) const
		"Copy@bc8430be7b8eb494\0" // Result<Unit> Copy(const Id& uid) const
		"Copy@4ff292f35e5847b5\0" // Result<Unit> Copy(const Dimension& quantity) const
		"AddToDimension@0499ab9fb052eea2\0" // Result<void> AddToDimension() const
		"Reduce@0499ab98dcf7b892\0" // Result<Unit> Reduce() const
		"ToString@7de9f6f51c89c899\0" // String ToString(const FormatStatement* fs) const
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class UnitInterface::Hxx2::Unresolved : public UnitInterface
	{
	public:
		static const Unresolved* Get(const UnitInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(UnitInterface* o) { return (Unresolved*) o; }
		static void Free(const UnitInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UnitInterface::Free(object); return maxon::PrivateLogNullptrError();}
		const Id& GetId() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UnitInterface*) this)->GetId(); return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		const Dimension& GetDimension() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UnitInterface*) this)->GetDimension(); return maxon::PrivateIncompleteNullReturnValue<const Dimension&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Float GetSIConversionFactor() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UnitInterface*) this)->GetSIConversionFactor(); return 0;}
		Result<Unit> operator *(const Result<Unit>& u) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UnitInterface*) this)->operator *(u); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Unit> operator /(const Result<Unit>& u) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UnitInterface*) this)->operator /(u); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Unit> operator ^(Int exponent) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UnitInterface*) this)->operator ^(exponent); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Unit> Copy(const Id& uid) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UnitInterface*) this)->Copy(uid); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Unit> Copy(const Dimension& quantity) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UnitInterface*) this)->Copy(quantity); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> AddToDimension() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UnitInterface*) this)->AddToDimension(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Unit> Reduce() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UnitInterface*) this)->Reduce(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		String ToString(const FormatStatement* fs) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UnitInterface*) this)->ToString(fs); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE UnitInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<const Id&>::value,
		maxon::details::NullReturnType<const Dimension&>::value,
		maxon::details::NullReturnType<Float>::value,
		maxon::details::NullReturnType<Result<Unit>>::value,
		maxon::details::NullReturnType<Result<Unit>>::value,
		maxon::details::NullReturnType<Result<Unit>>::value,
		maxon::details::NullReturnType<Result<Unit>>::value,
		maxon::details::NullReturnType<Result<Unit>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Unit>>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool UnitInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_UnitInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Id&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnitInterface_GetId = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_GetId;
		#else
		tbl->_UnitInterface_GetId = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_GetId;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Dimension&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnitInterface_GetDimension = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_GetDimension;
		#else
		tbl->_UnitInterface_GetDimension = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_GetDimension;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_UnitInterface_GetSIConversionFactor = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_GetSIConversionFactor;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Unit>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnitInterface_operatorMul = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_operatorMul;
		#else
		tbl->_UnitInterface_operatorMul = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_operatorMul;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Unit>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnitInterface_operatorDiv = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_operatorDiv;
		#else
		tbl->_UnitInterface_operatorDiv = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_operatorDiv;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Unit>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnitInterface_operatorXor = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_operatorXor;
		#else
		tbl->_UnitInterface_operatorXor = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_operatorXor;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Unit>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnitInterface_Copy = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_Copy;
		#else
		tbl->_UnitInterface_Copy = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_Copy;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Unit>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnitInterface_Copy_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_Copy_1;
		#else
		tbl->_UnitInterface_Copy_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_Copy_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnitInterface_AddToDimension = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_AddToDimension;
		#else
		tbl->_UnitInterface_AddToDimension = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_AddToDimension;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Unit>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnitInterface_Reduce = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_Reduce;
		#else
		tbl->_UnitInterface_Reduce = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_Reduce;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UnitInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_ToString;
		#else
		tbl->_UnitInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_UnitInterface_ToString;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(UnitInterface, "net.maxon.interface.unit", nullptr);
	template <typename DUMMY> maxon::Int UnitInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Dimension&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Id&>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(Dimensions);
	namespace Dimensions
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Length, , "net.maxon.dimension.length");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Time, , "net.maxon.dimension.time");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Mass, , "net.maxon.dimension.mass");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Temperature, , "net.maxon.dimension.temperature");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(AmountOfSubstance, , "net.maxon.dimension.amountofsubstance");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ElectricCurrent, , "net.maxon.dimension.electriccurrent");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(LuminousIntensity, , "net.maxon.dimension.luminousintensity");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Angle, , "net.maxon.dimension.angle");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(SolidAngle, , "net.maxon.dimension.solidangle");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Velocity, , "net.maxon.dimension.velocity");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Density, , "net.maxon.dimension.density");
	}
	MAXON_REGISTRY_REGISTER(Units);
	namespace Units
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(m, , "net.maxon.unit.m");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(cm, , "net.maxon.unit.cm");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ft, , "net.maxon.unit.ft");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(kg, , "net.maxon.unit.kg");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(s, , "net.maxon.unit.s");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(K, , "net.maxon.unit.k");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(mol, , "net.maxon.unit.mol");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(A, , "net.maxon.unit.a");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(cd, , "net.maxon.unit.cd");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(rad, , "net.maxon.unit.rad");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(sr, , "net.maxon.unit.sr");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_units(0
	| maxon::DimensionInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::UnitInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
