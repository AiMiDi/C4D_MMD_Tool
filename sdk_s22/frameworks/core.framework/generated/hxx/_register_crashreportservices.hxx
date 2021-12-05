#if 1
namespace maxon
{
	const maxon::Char* const CrashReportServices::MTable::_ids = 
		"CreateCrashReportProperty@cc2246a2adacbe16\0" // Int32 CreateCrashReportProperty(const Char* name, const Char* value)
		"FreeCrashReportProperty@1625bfaaf98f944\0" // void FreeCrashReportProperty(Int32 propertyIdx)
		"GetCrashReportProperties@2ae923804dfb35da\0" // void* GetCrashReportProperties(void* osThread)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class CrashReportServices::Hxx2::Unresolved : public CrashReportServices
	{
	public:
		static const Unresolved* Get(const CrashReportServices* o) { return (const Unresolved*) o; }
		static Unresolved* Get(CrashReportServices* o) { return (Unresolved*) o; }
		static Int32 CreateCrashReportProperty(const Char* name, const Char* value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CrashReportServices::CreateCrashReportProperty(name, value); return 0;}
		static void FreeCrashReportProperty(Int32 propertyIdx) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CrashReportServices::FreeCrashReportProperty(propertyIdx); return maxon::PrivateLogNullptrError();}
		static void* GetCrashReportProperties(void* osThread) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CrashReportServices::GetCrashReportProperties(osThread); return nullptr;}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE CrashReportServices::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Int32>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void*>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool CrashReportServices::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CrashReportServices_CreateCrashReportProperty = &Hxx2::Wrapper<Hxx2::Unresolved>::_CrashReportServices_CreateCrashReportProperty;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CrashReportServices_FreeCrashReportProperty = &Hxx2::Wrapper<Hxx2::Unresolved>::_CrashReportServices_FreeCrashReportProperty;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_CrashReportServices_GetCrashReportProperties = &Hxx2::Wrapper<Hxx2::Unresolved>::_CrashReportServices_GetCrashReportProperties;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(CrashReportServices, "net.maxon.interface.crashreportservices", nullptr);
}
#endif
