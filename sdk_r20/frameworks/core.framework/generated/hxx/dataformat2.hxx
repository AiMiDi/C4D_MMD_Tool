
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
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
		if (!W::Implementation::PROXY && (!DataFormatBaseReaderInterface::MTable::InitWithBases<W>(info, offset) || !DataSerializeReaderInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataFormatReaderInterface, DataSerializeReaderInterface::MTable::CombinedMTable<DataFormatBaseReaderInterface::MTable::CombinedMTable<S>>>;
	PRIVATE_MAXON_COMPBASE(DataFormatReaderInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class DataFormatReaderInterface::Wrapper : public DataSerializeReaderInterface::Wrapper<DataFormatBaseReaderInterface::Wrapper<S>>
{
public:
};


auto DataFormatReaderInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataFormatReaderInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_DataFormatReaderInterface(DataFormatReaderInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataformat.h", false);
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
		if (!W::Implementation::PROXY && (!DataFormatBaseWriterInterface::MTable::InitWithBases<W>(info, offset) || !DataSerializeWriterInterface::MTable::InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::Object::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<DataFormatWriterInterface, DataSerializeWriterInterface::MTable::CombinedMTable<DataFormatBaseWriterInterface::MTable::CombinedMTable<S>>>;
	PRIVATE_MAXON_COMPBASE(DataFormatWriterInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

template <typename S> class DataFormatWriterInterface::Wrapper : public DataSerializeWriterInterface::Wrapper<DataFormatBaseWriterInterface::Wrapper<S>>
{
public:
};


auto DataFormatWriterInterface::GetPtr() -> Ptr { return Ptr(this); }
auto DataFormatWriterInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_DataFormatWriterInterface(DataFormatWriterInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/dataformat.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

