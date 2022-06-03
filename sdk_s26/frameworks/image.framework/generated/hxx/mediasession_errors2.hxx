
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct MediaSessionWrongTypeErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaSessionWrongTypeErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaSessionWrongTypeErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaSessionWrongTypeErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MediaSessionWrongTypeErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaSessionWrongTypeErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto MediaSessionWrongTypeErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaSessionWrongTypeErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_errors)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaSessionWrongTypeErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaSessionWrongTypeErrorInterface() { new (s_ui_maxon_MediaSessionWrongTypeErrorInterface) maxon::EntityUse(MediaSessionWrongTypeErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_errors.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaSessionWrongTypeErrorInterface(MediaSessionWrongTypeErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_errors.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct MediaStreamEOFErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaStreamEOFErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaStreamEOFErrorInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaStreamEOFErrorInterface::Hxx2
{
	template <typename S> class CWrapper : public ErrorInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ErrorInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (MediaStreamEOFErrorInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaStreamEOFErrorInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto MediaStreamEOFErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaStreamEOFErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_errors)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaStreamEOFErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaStreamEOFErrorInterface() { new (s_ui_maxon_MediaStreamEOFErrorInterface) maxon::EntityUse(MediaStreamEOFErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_errors.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaStreamEOFErrorInterface(MediaStreamEOFErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_errors.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

