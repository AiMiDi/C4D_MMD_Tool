
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
	static const maxon::Bool HAS_NONSTATIC = false;
	PixelFormatIterator (*_PixelFormatGroupInterface_GetEntries) (const maxon::GenericComponent* this_);
	maxon::Int _PixelFormatGroupInterface_GetEntries_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatGroupInterface, GetEntries))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatGroupInterface, GetEntries), W, MTable>::type::_PixelFormatGroupInterface_GetEntries;
			_PixelFormatGroupInterface_GetEntries = reinterpret_cast<const decltype(_PixelFormatGroupInterface_GetEntries)&>(ptr);
			_PixelFormatGroupInterface_GetEntries_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<PixelFormatGroupInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(PixelFormatGroupInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct PixelFormatGroupInterface::Hxx2
{
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetEntries);
	static PixelFormatIterator _PixelFormatGroupInterface_GetEntries(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetEntries(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatGroupInterface::GetEntries() const -> PixelFormatIterator
{
	const PixelFormatGroupInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatGroupInterface, this); return mt_._PixelFormatGroupInterface_GetEntries((const maxon::GenericComponent*) this + mt_._PixelFormatGroupInterface_GetEntries_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatGroupInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetEntries() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormatIterator>, PixelFormatIterator>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<PixelFormatIterator>, PixelFormatIterator>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const PixelFormatGroupInterface* o_ = (const PixelFormatGroupInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = PixelFormatGroupInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<PixelFormatIterator>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatGroupInterface, o_, PixelFormatGroupInterface_GetEntries) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatGroupInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatGroupInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatGroupInterface, o_); 
	return (mt_._PixelFormatGroupInterface_GetEntries(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._PixelFormatGroupInterface_GetEntries_Offset));
}
auto PixelFormatGroupInterface::GetPtr() -> Ptr { return Ptr(this); }
auto PixelFormatGroupInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

