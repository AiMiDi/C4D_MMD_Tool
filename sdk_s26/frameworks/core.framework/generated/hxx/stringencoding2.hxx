
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<StringEncodingInterface, typename StreamConversionInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<StringEncodingInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct StringEncodingInterface::Hxx2
{
	template <typename S> class CWrapper : public StreamConversionInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename StreamConversionInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (StringEncodingInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, StringEncodingInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto StringEncodingInterface::GetPtr() -> Ptr { return Ptr(this); }
auto StringEncodingInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_stringencoding)
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<StringDecodingInterface, typename StreamConversionInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<StringDecodingInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct StringDecodingInterface::Hxx2
{
	template <typename S> class CWrapper : public StreamConversionInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename StreamConversionInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (StringDecodingInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, StringDecodingInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto StringDecodingInterface::GetPtr() -> Ptr { return Ptr(this); }
auto StringDecodingInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_stringencoding)
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

