
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct MediaSessionFileFormatHandlerInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!FileFormatHandlerInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaSessionFileFormatHandlerInterface, typename FileFormatHandlerInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(MediaSessionFileFormatHandlerInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaSessionFileFormatHandlerInterface::Hxx2
{
	template <typename S> class Wrapper : public FileFormatHandlerInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

auto MediaSessionFileFormatHandlerInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaSessionFileFormatHandlerInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaSessionFileFormatHandlerInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaSessionFileFormatHandlerInterface() { new (s_ui_maxon_MediaSessionFileFormatHandlerInterface) maxon::EntityUse(MediaSessionFileFormatHandlerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_fileformats.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaSessionFileFormatHandlerInterface(MediaSessionFileFormatHandlerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_fileformats.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
namespace URLFLAGS
{
	struct IMAGESEQUENCE_FPS_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xf84e22fbf6811b4bLL), maxon::UInt(31))> { };
	struct IMAGESEQUENCE_FIRSTFRAME_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xa0bbffb42e83e41bLL), maxon::UInt(38))> { };
	struct IMAGESEQUENCE_LASTFRAME_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xaa58a99b48a20179LL), maxon::UInt(37))> { };
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

