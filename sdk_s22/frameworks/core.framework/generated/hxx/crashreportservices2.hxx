
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct CrashReportServices::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Int32 (*_CrashReportServices_CreateCrashReportProperty) (const Char* name, const Char* value);
	void (*_CrashReportServices_FreeCrashReportProperty) (Int32 propertyIdx);
	void* (*_CrashReportServices_GetCrashReportProperties) (void* osThread);
	template <typename IMPL> void Init()
	{
		_CrashReportServices_CreateCrashReportProperty = &IMPL::_CrashReportServices_CreateCrashReportProperty;
		_CrashReportServices_FreeCrashReportProperty = &IMPL::_CrashReportServices_FreeCrashReportProperty;
		_CrashReportServices_GetCrashReportProperties = &IMPL::_CrashReportServices_GetCrashReportProperties;
	}
};

struct CrashReportServices::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static Int32 _CrashReportServices_CreateCrashReportProperty(const Char* name, const Char* value) { return C::CreateCrashReportProperty(name, value); }
	static void _CrashReportServices_FreeCrashReportProperty(Int32 propertyIdx) { return C::FreeCrashReportProperty(propertyIdx); }
	static void* _CrashReportServices_GetCrashReportProperties(void* osThread) { return C::GetCrashReportProperties(osThread); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashReportServices::CreateCrashReportProperty(const Char* name, const Char* value) -> Int32
{
	return MTable::_instance._CrashReportServices_CreateCrashReportProperty(name, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashReportServices::FreeCrashReportProperty(Int32 propertyIdx) -> void
{
	return MTable::_instance._CrashReportServices_FreeCrashReportProperty(propertyIdx);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashReportServices::GetCrashReportProperties(void* osThread) -> void*
{
	return MTable::_instance._CrashReportServices_GetCrashReportProperties(osThread);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CrashReportServices); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CrashReportServices() { new (s_ui_maxon_CrashReportServices) maxon::EntityUse(CrashReportServices::_interface.GetReference(), &maxon::g_translationUnit, "maxon/crashreportservices.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CrashReportServices(CrashReportServices::_interface.GetReference(), &maxon::g_translationUnit, "maxon/crashreportservices.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

