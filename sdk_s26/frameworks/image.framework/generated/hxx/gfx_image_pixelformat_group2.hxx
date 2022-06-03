
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct PixelFormatGroupInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetEntries);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PixelFormatIterator (*PixelFormatGroupInterface_GetEntries) (const maxon::GenericComponent* this_);
	maxon::Int PixelFormatGroupInterface_GetEntries_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatGroupInterface, GetEntries))
	{
		PixelFormatGroupInterface_GetEntries = &W::PixelFormatGroupInterface_GetEntries;
		PixelFormatGroupInterface_GetEntries_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<PixelFormatGroupInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<PixelFormatGroupInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct PixelFormatGroupInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetEntries);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (PixelFormatGroupInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, PixelFormatGroupInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static PixelFormatIterator PixelFormatGroupInterface_GetEntries(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetEntries(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatGroupInterface::GetEntries() const -> PixelFormatIterator
{
	const PixelFormatGroupInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatGroupInterface, this); return mt_.PixelFormatGroupInterface_GetEntries((const maxon::GenericComponent*) this + mt_.PixelFormatGroupInterface_GetEntries_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatGroupInterface::Hxx1::ConstFn<S>::GetEntries() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormatIterator>, PixelFormatIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormatIterator>, PixelFormatIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatGroupInterface* o_ = (const PixelFormatGroupInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatGroupInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<PixelFormatIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatGroupInterface, o_, PixelFormatGroupInterface_GetEntries) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<PixelFormatGroupInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatGroupInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatGroupInterface, o_); 
	return (mt_.PixelFormatGroupInterface_GetEntries(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.PixelFormatGroupInterface_GetEntries_Offset));
}
auto PixelFormatGroupInterface::GetPtr() -> Ptr { return Ptr(this); }
auto PixelFormatGroupInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_gfx_image_pixelformat_group)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_PixelFormatGroupInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_PixelFormatGroupInterface() { new (s_ui_maxon_PixelFormatGroupInterface) maxon::EntityUse(PixelFormatGroupInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat_group.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_PixelFormatGroupInterface(PixelFormatGroupInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat_group.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

