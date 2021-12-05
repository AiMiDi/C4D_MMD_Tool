
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
namespace MEDIASESSION
{
	namespace EXPORT
	{
		struct QUALITY_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xae83c22493973ec5LL), maxon::UInt(37))> { };
		struct DATARATE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x21f4821696b99284LL), maxon::UInt(38))> { };
		struct KEYFRAMES_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x1c9bc644fee3c40bLL), maxon::UInt(39))> { };
		struct DISABLESRGBCONVERSION_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x7bb770bac5b88c3eLL), maxon::UInt(51))> { };
		struct CUSTOMDATA_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x76dc4e40f066bf15LL), maxon::UInt(40))> { };
		namespace BASE
		{
			struct MF_EXPORT_GROUP_PRESETS_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xba95430df8767f80LL), maxon::UInt(46))> { };
			struct MF_EXPORT_GROUP_OPTIONS_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xba95430dc0f58caaLL), maxon::UInt(46))> { };
		}
	}
}
namespace MEDIASTREAM
{
	struct DUMMY_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x4cee461f00b88a62LL), maxon::UInt(27))> { };
}
namespace MEDIAFORMAT
{
	namespace IMAGE
	{
		struct TYPE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x5d2baf6906807429LL), maxon::UInt(26))> { };
		struct SUBIMAGEINDEX_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xf5c6410cc84b4688LL), maxon::UInt(35))> { };
		struct PIXELFORMAT_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x3f15d7f5645fce2eLL), maxon::UInt(33))> { };
		struct COLORPROFILE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x9f2007611d625ad5LL), maxon::UInt(34))> { };
		struct WIDTH_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x484a3db7c9b0e6b7LL), maxon::UInt(27))> { };
		struct HEIGHT_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xc0fd7941529cf656LL), maxon::UInt(28))> { };
		struct ASPECTRATIO_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x3eeb147fcfa2b2e4LL), maxon::UInt(33))> { };
		struct DPI_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xb8aed41c297fc68eLL), maxon::UInt(25))> { };
		struct STREAMNAME_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xa732914b94153fbaLL), maxon::UInt(32))> { };
		struct ALPHANAME_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x7901936d04c4255aLL), maxon::UInt(31))> { };
		struct ALPHATYPE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x7901936d04c73a09LL), maxon::UInt(31))> { };
		struct LAYERALPHA_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xa731da67d87fbc5cLL), maxon::UInt(32))> { };
		struct DEEPIMAGE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x79019591b29bb860LL), maxon::UInt(31))> { };
		struct HOTSPOTX_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x77842e3943a910f8LL), maxon::UInt(30))> { };
		struct HOTSPOTY_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x77842e3943a910f9LL), maxon::UInt(30))> { };
	}
	namespace IMAGELAYER
	{
		struct BOUNDINGBOX_X_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xda1b1e389591d134LL), maxon::UInt(41))> { };
		struct BOUNDINGBOX_Y_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xda1b1e389591d135LL), maxon::UInt(41))> { };
		struct BOUNDINGBOX_W_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xda1b1e389591d133LL), maxon::UInt(41))> { };
		struct BOUNDINGBOX_H_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xda1b1e389591d124LL), maxon::UInt(41))> { };
		struct ENABLED_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xa277195b10cec795LL), maxon::UInt(35))> { };
		struct TRANSPARENCYPROTECTED_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xeedd75a4baf37caaLL), maxon::UInt(49))> { };
		struct OPACITY_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xa277195d2537345fLL), maxon::UInt(35))> { };
		struct FILLOPACITY_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xf4485ab4e4f54b7cLL), maxon::UInt(39))> { };
		struct BLENDMODE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xe1162c7a7351c0c8LL), maxon::UInt(37))> { };
		struct LAYERGROUP_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x41b04b417be43efaLL), maxon::UInt(38))> { };
		struct MASKDEFCOLOR_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x972439b7ae211996LL), maxon::UInt(40))> { };
		namespace FOLDER
		{
			struct ISOPEN_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xa224dfc928b377a0LL), maxon::UInt(34))> { };
		}
		namespace ADJUSTMENT
		{
			struct PSD_FILTERID_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x98660071a84b3a7dLL), maxon::UInt(40))> { };
			struct PSD_DATA_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xac6c124e8d26d494LL), maxon::UInt(36))> { };
		}
	}
	namespace VIDEO
	{
		struct FPS_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x7901a3a1777cad67LL), maxon::UInt(31))> { };
		struct STARTTIME_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xe97779f20118602dLL), maxon::UInt(37))> { };
		struct DURATION_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x39145e65f8bfcbd6LL), maxon::UInt(36))> { };
	}
	namespace AUDIO
	{
		struct CHANNELCOUNT_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x401b608e37fb8fb3LL), maxon::UInt(40))> { };
		struct BITSPERCHANNEL_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x65991c1ff97092d3LL), maxon::UInt(42))> { };
		struct SAMPLERATE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xb537969ff688b511LL), maxon::UInt(38))> { };
		struct MARKERARRAY_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xf1a9c86ede1d8bb8LL), maxon::UInt(39))> { };
		namespace MARKER
		{
			struct IDENTIFIER_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x15719b40e5ab2176LL), maxon::UInt(45))> { };
			struct POSITION_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xfd9ff3d35e75dd36LL), maxon::UInt(43))> { };
			struct LABEL_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x438f456c8e307e07LL), maxon::UInt(40))> { };
			struct NOTE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xf1a9c86edb4d027fLL), maxon::UInt(39))> { };
		}
	}
	struct EXPORTSETTINGS_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x60bef45053c6a206LL), maxon::UInt(36))> { };
}
namespace MEDIAPROPERTIES
{
	namespace VIDEO
	{
		struct SAMPLETIME_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xd039d7fa5d4b0688LL), maxon::UInt(34))> { };
		struct SAMPLEDURATION_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xef3e6d412112abcfLL), maxon::UInt(38))> { };
		struct SKIPPEDFRAMES_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x7ecfa63b95007f25LL), maxon::UInt(37))> { };
	}
}

struct MediaBaseInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ConnectToSession);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSession);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_MediaBaseInterface_ConnectToSession) (maxon::GenericComponent* this_, const MediaSessionRef& session);
	maxon::Int _MediaBaseInterface_ConnectToSession_Offset;
	MediaSessionRef (*_MediaBaseInterface_GetSession) (const maxon::GenericComponent* this_);
	maxon::Int _MediaBaseInterface_GetSession_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaBaseInterface, ConnectToSession))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaBaseInterface, ConnectToSession), W, MTable>::type::_MediaBaseInterface_ConnectToSession;
			_MediaBaseInterface_ConnectToSession = reinterpret_cast<const decltype(_MediaBaseInterface_ConnectToSession)&>(ptr);
			_MediaBaseInterface_ConnectToSession_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaBaseInterface, GetSession))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, MediaBaseInterface, GetSession), W, MTable>::type::_MediaBaseInterface_GetSession;
			_MediaBaseInterface_GetSession = reinterpret_cast<const decltype(_MediaBaseInterface_GetSession)&>(ptr);
			_MediaBaseInterface_GetSession_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset) || !DataDescriptionObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<MediaBaseInterface, typename DataDescriptionObjectInterface::MTable::template CombinedMTable<typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>>;
	PRIVATE_MAXON_COMPBASE(MediaBaseInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct MediaBaseInterface::Hxx2
{
	template <typename S> class Wrapper : public DataDescriptionObjectInterface::Hxx2::template Wrapper<typename DataDictionaryObjectInterface::Hxx2::template Wrapper<S>>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConnectToSession);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSession);
	static Result<void> _MediaBaseInterface_ConnectToSession(maxon::GenericComponent* this_, const MediaSessionRef& session) { return ((typename S::Implementation*) this_)->ConnectToSession(session); }
	static MediaSessionRef _MediaBaseInterface_GetSession(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetSession(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaBaseInterface::ConnectToSession(const MediaSessionRef& session) -> Result<void>
{
	const MediaBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaBaseInterface, this); return mt_._MediaBaseInterface_ConnectToSession((maxon::GenericComponent*) this + mt_._MediaBaseInterface_ConnectToSession_Offset, session);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto MediaBaseInterface::GetSession() const -> MediaSessionRef
{
	const MediaBaseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(MediaBaseInterface, this); return mt_._MediaBaseInterface_GetSession((const maxon::GenericComponent*) this + mt_._MediaBaseInterface_GetSession_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaBaseInterface::Hxx1::ReferenceFunctionsImpl<S>::ConnectToSession(const MediaSessionRef& session) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaBaseInterface* o_ = (MediaBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaBaseInterface, o_, MediaBaseInterface_ConnectToSession) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaBaseInterface>() : PRIVATE_MAXON_VTABLE(MediaBaseInterface, o_); 
	return (mt_._MediaBaseInterface_ConnectToSession(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaBaseInterface_ConnectToSession_Offset, session));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaBaseInterface::Hxx1::COWReferenceFunctionsImpl<S>::ConnectToSession(const MediaSessionRef& session) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); MediaBaseInterface* o_ = (MediaBaseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaBaseInterface, o_, MediaBaseInterface_ConnectToSession) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaBaseInterface>() : PRIVATE_MAXON_VTABLE(MediaBaseInterface, o_); 
	return (mt_._MediaBaseInterface_ConnectToSession(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MediaBaseInterface_ConnectToSession_Offset, session));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto MediaBaseInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSession() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<MediaSessionRef>, MediaSessionRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<MediaSessionRef>, MediaSessionRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const MediaBaseInterface* o_ = (const MediaBaseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = MediaBaseInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<MediaSessionRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(MediaBaseInterface, o_, MediaBaseInterface_GetSession) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<MediaBaseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<MediaBaseInterface>() : PRIVATE_MAXON_VTABLE(MediaBaseInterface, o_); 
	return (mt_._MediaBaseInterface_GetSession(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._MediaBaseInterface_GetSession_Offset));
}
auto MediaBaseInterface::GetPtr() -> Ptr { return Ptr(this); }
auto MediaBaseInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_MediaBaseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_MediaBaseInterface() { new (s_ui_maxon_MediaBaseInterface) maxon::EntityUse(MediaBaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_base.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_MediaBaseInterface(MediaBaseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/mediasession_base.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

