
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct ImagePixelDeepImageStorageInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename S> using CombinedMTable = maxon::PrivateCombinedMTable<ImagePixelDeepImageStorageInterface, typename ImagePixelStorageInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<ImagePixelDeepImageStorageInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct ImagePixelDeepImageStorageInterface::Hxx2
{
	template <typename S> class CWrapper : public ImagePixelStorageInterface::Hxx2::template CWrapper<S>
	{
	public:
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ImagePixelStorageInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (ImagePixelDeepImageStorageInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, ImagePixelDeepImageStorageInterface::_interface); if (!vt) return false;
			return true;
		}
	};

};

auto ImagePixelDeepImageStorageInterface::GetPtr() -> Ptr { return Ptr(this); }
auto ImagePixelDeepImageStorageInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_storage_deepimage)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_ImagePixelDeepImageStorageInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_ImagePixelDeepImageStorageInterface() { new (s_ui_maxon_ImagePixelDeepImageStorageInterface) maxon::EntityUse(ImagePixelDeepImageStorageInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_storage_deepimage.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_ImagePixelDeepImageStorageInterface(ImagePixelDeepImageStorageInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_storage_deepimage.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

