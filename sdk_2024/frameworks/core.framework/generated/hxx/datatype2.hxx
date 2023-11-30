
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct UnregisteredDataTypeErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<UnregisteredDataTypeErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<UnregisteredDataTypeErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct UnregisteredDataTypeErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (UnregisteredDataTypeErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, UnregisteredDataTypeErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto UnregisteredDataTypeErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnregisteredDataTypeErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_datatype)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UnregisteredDataTypeErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UnregisteredDataTypeErrorInterface() { new (s_ui_maxon_UnregisteredDataTypeErrorInterface) maxon::EntityUse(UnregisteredDataTypeErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datatype.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UnregisteredDataTypeErrorInterface(UnregisteredDataTypeErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/datatype.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#ifdef MAXON_COMPILER_INTEL
#else
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

