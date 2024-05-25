
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct DataFormatReaderInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<DataFormatReaderInterface, typename DataSerializeReaderInterface::MTable::template CombinedMTable<typename DataFormatBaseReaderInterface::MTable::template CombinedMTable<S>>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DataFormatReaderInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataFormatReaderInterface::Hxx2
{
	template <typename S> class CWrapper : public DataSerializeReaderInterface::Hxx2::template CWrapper<typename DataFormatBaseReaderInterface::Hxx2::template CWrapper<S>>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataFormatBaseReaderInterface::Hxx2::template CWrapper<S>;
			using Super1 = typename DataSerializeReaderInterface::Hxx2::template CWrapper<Super0>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset) && Super1::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DataFormatReaderInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataFormatReaderInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto DataFormatReaderInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataFormatReaderInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_dataformat)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataFormatReaderInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataFormatReaderInterface() { new (s_ui_maxon_DataFormatReaderInterface) maxon::EntityUse(DataFormatReaderInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataformat.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataFormatReaderInterface(DataFormatReaderInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataformat.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct DataFormatWriterInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<DataFormatWriterInterface, typename DataSerializeWriterInterface::MTable::template CombinedMTable<typename DataFormatBaseWriterInterface::MTable::template CombinedMTable<S>>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<DataFormatWriterInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataFormatWriterInterface::Hxx2
{
	template <typename S> class CWrapper : public DataSerializeWriterInterface::Hxx2::template CWrapper<typename DataFormatBaseWriterInterface::Hxx2::template CWrapper<S>>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename DataFormatBaseWriterInterface::Hxx2::template CWrapper<S>;
			using Super1 = typename DataSerializeWriterInterface::Hxx2::template CWrapper<Super0>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset) && Super1::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (DataFormatWriterInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, DataFormatWriterInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto DataFormatWriterInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataFormatWriterInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_dataformat)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_DataFormatWriterInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_DataFormatWriterInterface() { new (s_ui_maxon_DataFormatWriterInterface) maxon::EntityUse(DataFormatWriterInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataformat.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_DataFormatWriterInterface(DataFormatWriterInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataformat.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

