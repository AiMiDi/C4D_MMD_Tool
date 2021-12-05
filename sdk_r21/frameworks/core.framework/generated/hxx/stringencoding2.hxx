
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct StringEncodingInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!StreamConversionInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<StringEncodingInterface, typename StreamConversionInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(StringEncodingInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct StringEncodingInterface::Hxx2
{
	template <typename S> class Wrapper : public StreamConversionInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

auto StringEncodingInterface::GetPtr() -> Ptr { return Ptr(this); }
auto StringEncodingInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_StringEncodingInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_StringEncodingInterface() { new (s_ui_maxon_StringEncodingInterface) maxon::EntityUse(StringEncodingInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/stringencoding.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_StringEncodingInterface(StringEncodingInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/stringencoding.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct StringDecodingInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!StreamConversionInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<StringDecodingInterface, typename StreamConversionInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(StringDecodingInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct StringDecodingInterface::Hxx2
{
	template <typename S> class Wrapper : public StreamConversionInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

auto StringDecodingInterface::GetPtr() -> Ptr { return Ptr(this); }
auto StringDecodingInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_StringDecodingInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_StringDecodingInterface() { new (s_ui_maxon_StringDecodingInterface) maxon::EntityUse(StringDecodingInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/stringencoding.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_StringDecodingInterface(StringDecodingInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/stringencoding.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

