
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<MediaSessionFileFormatHandlerInterface, typename FileFormatHandlerInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<MediaSessionFileFormatHandlerInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaSessionFileFormatHandlerInterface::Hxx2
{
	template <typename S> class CWrapper : public FileFormatHandlerInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename FileFormatHandlerInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (MediaSessionFileFormatHandlerInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, MediaSessionFileFormatHandlerInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto MediaSessionFileFormatHandlerInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaSessionFileFormatHandlerInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_mediasession_fileformats)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaSessionFileFormatHandlerInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaSessionFileFormatHandlerInterface() { new (s_ui_maxon_MediaSessionFileFormatHandlerInterface) maxon::EntityUse(MediaSessionFileFormatHandlerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_fileformats.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
#if defined(MAXON_API) || defined(PRIVATE_MODULE_net_maxon_image)
static maxon::EntityUse s_ui_maxon_MediaSessionFileFormatHandlerInterface(MediaSessionFileFormatHandlerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_fileformats.h", false);
#elif !defined(PRIVATE_MODULE_net_maxon_image_DEPENDENCY)
#define PRIVATE_MODULE_net_maxon_image_DEPENDENCY
MAXON_DEPENDENCY_ON_MODULE("net.maxon.image");
#endif
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

