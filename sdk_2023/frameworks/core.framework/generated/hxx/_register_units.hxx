#if 1
namespace maxon
{
	namespace enum21
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
		} ;
		static const maxon::UInt64 BASE_DIMENSION_values[] = {maxon::UInt64(enum21::BASE_DIMENSION::LENGTH), maxon::UInt64(enum21::BASE_DIMENSION::TIME), maxon::UInt64(enum21::BASE_DIMENSION::MASS), maxon::UInt64(enum21::BASE_DIMENSION::TEMPERATURE), maxon::UInt64(enum21::BASE_DIMENSION::AMOUNT_OF_SUBSTANCE), maxon::UInt64(enum21::BASE_DIMENSION::ELECTRIC_CURRENT), maxon::UInt64(enum21::BASE_DIMENSION::LUMINOUS_INTENSITY), maxon::UInt64(enum21::BASE_DIMENSION::ANGLE), maxon::UInt64(enum21::BASE_DIMENSION::SOLID_ANGLE), maxon::UInt64(enum21::BASE_DIMENSION::PRIVATE_COUNT)};
		static const maxon::EnumInfo BASE_DIMENSION_info{"BASE_DIMENSION", SIZEOF(BASE_DIMENSION), false, "LENGTH\0TIME\0MASS\0TEMPERATURE\0AMOUNT_OF_SUBSTANCE\0ELECTRIC_CURRENT\0LUMINOUS_INTENSITY\0ANGLE\0SOLID_ANGLE\0PRIVATE_COUNT\0", BASE_DIMENSION_values, std::extent<decltype(BASE_DIMENSION_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_BASE_DIMENSION21(){ return enum21::BASE_DIMENSION_info; }
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
		if (maxon::details::NullReturnType<const Dimension&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->DimensionInterface_Get = PRIVATE_MAXON_MF_CAST(decltype(DimensionInterface_Get), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DimensionInterface_Get);
		#else
		tbl->DimensionInterface_Get = PRIVATE_MAXON_MF_CAST(decltype(DimensionInterface_Get), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::DimensionInterface_Get);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	typename DimensionInterface::MTable::NVMTable DimensionInterface::MTable::NVMTable::_instance;
	const maxon::Char* const DimensionInterface::MTable::_ids = 
		"GetId@daec66e7da84a648\0" // const Id& GetId() const
		"operatorMul@9c5855bcd803545f\0" // Result<Dimension> operatorMul(const Result<Dimension>& q) const
		"operatorDiv@9c5855bcd803545f\0" // Result<Dimension> operatorDiv(const Result<Dimension>& q) const
		"operatorXor@67b5a4321b6a9bd6\0" // Result<Dimension> operatorXor(Int exponent) const
		"Copy@d1a7bf5f4dc3db77\0" // Result<Dimension> Copy(const Id& qid) const
		"GetExponent@4d2ac5e77b29c049\0" // Int GetExponent(BASE_DIMENSION q) const
		"AddUnit@ffe9d55ac23993db\0" // Result<Unit> AddUnit(const Id& unitId, Float siConversionFactor) const
		"GetUnits@fde529a5f41c3764\0" // UnitsArray GetUnits() const
		"IsEquivalent@baea6577a3c9b4e9\0" // Bool IsEquivalent(const Dimension& other) const
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* fs) const
	"";
	const maxon::METHOD_FLAGS DimensionInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE_SINGLE_IMPL(DimensionInterface, , "net.maxon.interface.dimension", "maxon.DimensionInterface", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const DimensionInterface::Hxx2::StaticMTable::_ids = 
		"Get@c1af1581792845a2\0" // const Dimension& Get(BASE_DIMENSION q)
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
		"Free@d9ed9e9646e49bd5\0" // void Free(const UnitInterface* object)
		"GetId@daec66e7da84a648\0" // const Id& GetId() const
		"GetDimension@46410ee1dc76f73b\0" // const Dimension& GetDimension() const
		"GetSIConversionFactor@e6d3186387d3ce58\0" // Float GetSIConversionFactor() const
		"operatorMul@4ee3c6a454e86fc5\0" // Result<Unit> operatorMul(const Result<Unit>& u) const
		"operatorDiv@4ee3c6a454e86fc5\0" // Result<Unit> operatorDiv(const Result<Unit>& u) const
		"operatorXor@f6c6aedce965cc48\0" // Result<Unit> operatorXor(Int exponent) const
		"Copy@4582b76207d500f1\0" // Result<Unit> Copy(const Id& uid) const
		"Copy@efa7ed7f65fca58c\0" // Result<Unit> Copy(const Dimension& quantity) const
		"AddToDimension@a0cff72f111cef5d\0" // Result<void> AddToDimension() const
		"Reduce@8ca9e0110db26f01\0" // Result<Unit> Reduce() const
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* fs) const
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
		tbl->UnitInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Id&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnitInterface_GetId = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_GetId), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_GetId);
		#else
		tbl->UnitInterface_GetId = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_GetId), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_GetId);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Dimension&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnitInterface_GetDimension = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_GetDimension), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_GetDimension);
		#else
		tbl->UnitInterface_GetDimension = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_GetDimension), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_GetDimension);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->UnitInterface_GetSIConversionFactor = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_GetSIConversionFactor), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_GetSIConversionFactor);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Unit>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnitInterface_operatorMul = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_operatorMul), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_operatorMul);
		#else
		tbl->UnitInterface_operatorMul = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_operatorMul), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_operatorMul);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Unit>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnitInterface_operatorDiv = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_operatorDiv), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_operatorDiv);
		#else
		tbl->UnitInterface_operatorDiv = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_operatorDiv), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_operatorDiv);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Unit>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnitInterface_operatorXor = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_operatorXor), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_operatorXor);
		#else
		tbl->UnitInterface_operatorXor = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_operatorXor), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_operatorXor);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Unit>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnitInterface_Copy = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_Copy), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_Copy);
		#else
		tbl->UnitInterface_Copy = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_Copy), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_Copy);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Unit>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnitInterface_Copy_1 = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_Copy_1), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_Copy_1);
		#else
		tbl->UnitInterface_Copy_1 = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_Copy_1), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_Copy_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnitInterface_AddToDimension = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_AddToDimension), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_AddToDimension);
		#else
		tbl->UnitInterface_AddToDimension = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_AddToDimension), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_AddToDimension);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Unit>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnitInterface_Reduce = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_Reduce), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_Reduce);
		#else
		tbl->UnitInterface_Reduce = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_Reduce), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_Reduce);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->UnitInterface_ToString = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_ToString);
		#else
		tbl->UnitInterface_ToString = PRIVATE_MAXON_MF_CAST(decltype(UnitInterface_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::UnitInterface_ToString);
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
