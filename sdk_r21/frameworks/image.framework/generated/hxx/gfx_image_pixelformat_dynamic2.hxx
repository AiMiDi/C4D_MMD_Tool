
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct PixelFormatDynamicInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AddChannel);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<Int> (*_PixelFormatDynamicInterface_AddChannel) (maxon::GenericComponent* this_, const ImageChannel& channel);
	maxon::Int _PixelFormatDynamicInterface_AddChannel_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatDynamicInterface, AddChannel))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, PixelFormatDynamicInterface, AddChannel), W, MTable>::type::_PixelFormatDynamicInterface_AddChannel;
			_PixelFormatDynamicInterface_AddChannel = reinterpret_cast<const decltype(_PixelFormatDynamicInterface_AddChannel)&>(ptr);
			_PixelFormatDynamicInterface_AddChannel_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!PixelFormatInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<PixelFormatDynamicInterface, typename PixelFormatInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(PixelFormatDynamicInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct PixelFormatDynamicInterface::Hxx2
{
	template <typename S> class Wrapper : public PixelFormatInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AddChannel);
	static Result<Int> _PixelFormatDynamicInterface_AddChannel(maxon::GenericComponent* this_, const ImageChannel& channel) { return ((typename S::Implementation*) this_)->AddChannel(channel); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatDynamicInterface::AddChannel(const ImageChannel& channel) -> Result<Int>
{
	const PixelFormatDynamicInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(PixelFormatDynamicInterface, this); return mt_._PixelFormatDynamicInterface_AddChannel((maxon::GenericComponent*) this + mt_._PixelFormatDynamicInterface_AddChannel_Offset, channel);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatDynamicInterface::Hxx1::ReferenceFunctionsImpl<S>::AddChannel(const ImageChannel& channel) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatDynamicInterface* o_ = (PixelFormatDynamicInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatDynamicInterface, o_, PixelFormatDynamicInterface_AddChannel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatDynamicInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatDynamicInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatDynamicInterface, o_); 
	return (mt_._PixelFormatDynamicInterface_AddChannel(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatDynamicInterface_AddChannel_Offset, channel));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto PixelFormatDynamicInterface::Hxx1::COWReferenceFunctionsImpl<S>::AddChannel(const ImageChannel& channel) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); PixelFormatDynamicInterface* o_ = (PixelFormatDynamicInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(PixelFormatDynamicInterface, o_, PixelFormatDynamicInterface_AddChannel) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<PixelFormatDynamicInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<PixelFormatDynamicInterface>() : PRIVATE_MAXON_VTABLE(PixelFormatDynamicInterface, o_); 
	return (mt_._PixelFormatDynamicInterface_AddChannel(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatDynamicInterface_AddChannel_Offset, channel));
}
auto PixelFormatDynamicInterface::GetPtr() -> Ptr { return Ptr(this); }
auto PixelFormatDynamicInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_PixelFormatDynamicInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_PixelFormatDynamicInterface() { new (s_ui_maxon_PixelFormatDynamicInterface) maxon::EntityUse(PixelFormatDynamicInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat_dynamic.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_PixelFormatDynamicInterface(PixelFormatDynamicInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/gfx_image_pixelformat_dynamic.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

