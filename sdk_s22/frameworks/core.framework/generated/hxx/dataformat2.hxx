
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
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataFormatBaseReaderInterface::MTable::template InitWithBases<W>(info, offset) || !DataSerializeReaderInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataFormatReaderInterface, typename DataSerializeReaderInterface::MTable::template CombinedMTable<typename DataFormatBaseReaderInterface::MTable::template CombinedMTable<S>>>;
	PRIVATE_MAXON_COMPBASE(DataFormatReaderInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataFormatReaderInterface::Hxx2
{
	template <typename S> class Wrapper : public DataSerializeReaderInterface::Hxx2::template Wrapper<typename DataFormatBaseReaderInterface::Hxx2::template Wrapper<S>>
	{
	public:
	};

};

auto DataFormatReaderInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataFormatReaderInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataFormatBaseWriterInterface::MTable::template InitWithBases<W>(info, offset) || !DataSerializeWriterInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataFormatWriterInterface, typename DataSerializeWriterInterface::MTable::template CombinedMTable<typename DataFormatBaseWriterInterface::MTable::template CombinedMTable<S>>>;
	PRIVATE_MAXON_COMPBASE(DataFormatWriterInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct DataFormatWriterInterface::Hxx2
{
	template <typename S> class Wrapper : public DataSerializeWriterInterface::Hxx2::template Wrapper<typename DataFormatBaseWriterInterface::Hxx2::template Wrapper<S>>
	{
	public:
	};

};

auto DataFormatWriterInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataFormatWriterInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

