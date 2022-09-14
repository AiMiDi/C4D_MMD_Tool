
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* ColorProfileLegacyProcessorInterface::PrivateGetCppName() { return "maxon::ColorProfileLegacyProcessor"; }

struct ColorProfileLegacyProcessorInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(ColorProfileLegacyProcessorInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const ColorProfileLegacyProcessorInterface* object);
	PRIVATE_MAXON_SF_POINTER(ColorProfileLegacyProcessorInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (ColorProfileLegacyProcessorInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(ColorProfileLegacyProcessorInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (ColorProfileLegacyProcessorInterface*), const maxon::SourceLocation& allocLocation, const ColorProfileLegacyProcessorInterface& object);
	PRIVATE_MAXON_SF_POINTER(ColorProfileLegacyProcessorInterface_CreateHandler, CreateHandler, MAXON_EXPAND_VA_ARGS, (Result<ForwardRef<ColorProfileGpuHandlerRef>>), const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization);
	template <typename IMPL> void Init()
	{
		ColorProfileLegacyProcessorInterface_Free = ColorProfileLegacyProcessorInterface_Free_GetPtr<IMPL>(true);
		ColorProfileLegacyProcessorInterface_Alloc = ColorProfileLegacyProcessorInterface_Alloc_GetPtr<IMPL>(true);
		ColorProfileLegacyProcessorInterface_Alloc_1 = ColorProfileLegacyProcessorInterface_Alloc_1_GetPtr<IMPL>(true);
		ColorProfileLegacyProcessorInterface_CreateHandler = ColorProfileLegacyProcessorInterface_CreateHandler_GetPtr<IMPL>(true);
	}
};

struct ColorProfileLegacyProcessorInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void ColorProfileLegacyProcessorInterface_Free(const ColorProfileLegacyProcessorInterface* object) { return C::Free(object); }
		static ColorProfileLegacyProcessorInterface* ColorProfileLegacyProcessorInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static ColorProfileLegacyProcessorInterface* ColorProfileLegacyProcessorInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const ColorProfileLegacyProcessorInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		static Result<ForwardRef<ColorProfileGpuHandlerRef>> ColorProfileLegacyProcessorInterface_CreateHandler(const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization) { return C::CreateHandler(srcProfile, dstProfile, flags, optimization); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileLegacyProcessorInterface::Free(const ColorProfileLegacyProcessorInterface* object) -> void
{
	return MTable::_instance.ColorProfileLegacyProcessorInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileLegacyProcessorInterface::Alloc(const maxon::SourceLocation& allocLocation) -> ColorProfileLegacyProcessorInterface*
{
	return MTable::_instance.ColorProfileLegacyProcessorInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileLegacyProcessorInterface::Alloc(const maxon::SourceLocation& allocLocation, const ColorProfileLegacyProcessorInterface& object) -> ColorProfileLegacyProcessorInterface*
{
	return MTable::_instance.ColorProfileLegacyProcessorInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileLegacyProcessorInterface::CreateHandler(const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization) -> Result<ForwardRef<ColorProfileGpuHandlerRef>>
{
	return MTable::_instance.ColorProfileLegacyProcessorInterface_CreateHandler(srcProfile, dstProfile, flags, optimization);
}

auto ColorProfileLegacyProcessorInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<ColorProfileLegacyProcessor>
{
	ColorProfileLegacyProcessorInterface* res_ = ColorProfileLegacyProcessorInterface::Alloc(MAXON_SOURCE_LOCATION);
	return ColorProfileLegacyProcessor(maxon::ForwardResultPtr<ColorProfileLegacyProcessorInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto ColorProfileLegacyProcessorInterface::Hxx1::ConstFn<S>::CreateHandler(const ColorProfile& srcProfile, const ColorProfile& dstProfile, COLORCONVERSIONFLAGS_GPU flags, COLORCONVERSION_OPTIMIZATION_GPU_FLAGS optimization) -> Result<ForwardRef<ColorProfileGpuHandlerRef>>
{
	return (MTable::_instance.ColorProfileLegacyProcessorInterface_CreateHandler(srcProfile, dstProfile, flags, optimization));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_gpu_legacy_processor)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ColorProfileLegacyProcessorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ColorProfileLegacyProcessorInterface() { new (s_ui_maxon_ColorProfileLegacyProcessorInterface) maxon::EntityUse(ColorProfileLegacyProcessorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_gpu_legacy_processor.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ColorProfileLegacyProcessorInterface(ColorProfileLegacyProcessorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_gpu_legacy_processor.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

