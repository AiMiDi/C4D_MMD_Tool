#if 1
namespace maxon
{
	const maxon::Char* const CrashReportServices::MTable::_ids = 
		"CreateCrashReportProperty@6407ff0f4d361d75\0" // Int32 CreateCrashReportProperty(const Char* name, const Char* value)
		"FreeCrashReportProperty@47d03faaba2d7da1\0" // void FreeCrashReportProperty(Int32 propertyIdx)
		"GetCrashReportProperties@84e97963adabc8d5\0" // void* GetCrashReportProperties(void* osThread)
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
		tbl->CrashReportServices_CreateCrashReportProperty = PRIVATE_MAXON_MF_CAST(decltype(CrashReportServices_CreateCrashReportProperty), &Hxx2::Wrapper<Hxx2::Unresolved>::CrashReportServices_CreateCrashReportProperty);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CrashReportServices_FreeCrashReportProperty = PRIVATE_MAXON_MF_CAST(decltype(CrashReportServices_FreeCrashReportProperty), &Hxx2::Wrapper<Hxx2::Unresolved>::CrashReportServices_FreeCrashReportProperty);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CrashReportServices_GetCrashReportProperties = PRIVATE_MAXON_MF_CAST(decltype(CrashReportServices_GetCrashReportProperties), &Hxx2::Wrapper<Hxx2::Unresolved>::CrashReportServices_GetCrashReportProperties);
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
