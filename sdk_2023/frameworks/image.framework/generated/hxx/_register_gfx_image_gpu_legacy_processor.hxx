#if 1
namespace maxon
{
	const maxon::Char* const ColorProfileLegacyProcessorInterface::MTable::_ids = 
		"Free@6cab60a3ccf2e1f6\0" // void Free(const ColorProfileLegacyProcessorInterface* object)
		"Alloc@dee53544ad6174df\0" // ColorProfileLegacyProcessorInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@1657335e8883c184\0" // ColorProfileLegacyProcessorInterface* Alloc(const maxon::SourceLocation& allocLocation, const ColorProfileLegacyProcessorInterface& object)
		"CreateHandler@ba7533b0abfa1034\0" // Result<ForwardRef<ColorProfileGpuHandlerRef>> CreateHandler(const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class ColorProfileLegacyProcessorInterface::Hxx2::Unresolved : public ColorProfileLegacyProcessorInterface
	{
	public:
		static const Unresolved* Get(const ColorProfileLegacyProcessorInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(ColorProfileLegacyProcessorInterface* o) { return (Unresolved*) o; }
		static void Free(const ColorProfileLegacyProcessorInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ColorProfileLegacyProcessorInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static ColorProfileLegacyProcessorInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ColorProfileLegacyProcessorInterface::Alloc(allocLocation); return nullptr;}
		static ColorProfileLegacyProcessorInterface* Alloc(const maxon::SourceLocation& allocLocation, const ColorProfileLegacyProcessorInterface& object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ColorProfileLegacyProcessorInterface::Alloc(allocLocation, object); return nullptr;}
		static Result<ForwardRef<ColorProfileGpuHandlerRef>> CreateHandler(const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ColorProfileLegacyProcessorInterface::CreateHandler(srcProfile, dstProfile, flags, optimization); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE ColorProfileLegacyProcessorInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<ColorProfileLegacyProcessorInterface*>::value,
		maxon::details::NullReturnType<ColorProfileLegacyProcessorInterface*>::value,
		maxon::details::NullReturnType<Result<ForwardRef<ColorProfileGpuHandlerRef>>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool ColorProfileLegacyProcessorInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileLegacyProcessorInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileLegacyProcessorInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileLegacyProcessorInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileLegacyProcessorInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileLegacyProcessorInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileLegacyProcessorInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->ColorProfileLegacyProcessorInterface_Alloc_1 = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileLegacyProcessorInterface_Alloc_1), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileLegacyProcessorInterface_Alloc_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<ForwardRef<ColorProfileGpuHandlerRef>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->ColorProfileLegacyProcessorInterface_CreateHandler = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileLegacyProcessorInterface_CreateHandler), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileLegacyProcessorInterface_CreateHandler);
		#else
		tbl->ColorProfileLegacyProcessorInterface_CreateHandler = PRIVATE_MAXON_MF_CAST(decltype(ColorProfileLegacyProcessorInterface_CreateHandler), &Hxx2::Wrapper<Hxx2::Unresolved>::ColorProfileLegacyProcessorInterface_CreateHandler);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(ColorProfileLegacyProcessorInterface, "net.maxon.image.interface.legacygpuprocessor", nullptr);
}
#endif
