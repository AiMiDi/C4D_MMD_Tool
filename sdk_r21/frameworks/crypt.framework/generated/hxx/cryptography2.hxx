
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct CryptographyStreamConversionInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IsChainingChiffre);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Bool (*_CryptographyStreamConversionInterface_IsChainingChiffre) (const maxon::GenericComponent* this_);
	maxon::Int _CryptographyStreamConversionInterface_IsChainingChiffre_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CryptographyStreamConversionInterface, IsChainingChiffre))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CryptographyStreamConversionInterface, IsChainingChiffre), W, MTable>::type::_CryptographyStreamConversionInterface_IsChainingChiffre;
			_CryptographyStreamConversionInterface_IsChainingChiffre = reinterpret_cast<const decltype(_CryptographyStreamConversionInterface_IsChainingChiffre)&>(ptr);
			_CryptographyStreamConversionInterface_IsChainingChiffre_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!StreamConversionInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CryptographyStreamConversionInterface, typename StreamConversionInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(CryptographyStreamConversionInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CryptographyStreamConversionInterface::Hxx2
{
	template <typename S> class Wrapper : public StreamConversionInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsChainingChiffre);
	static Bool _CryptographyStreamConversionInterface_IsChainingChiffre(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->IsChainingChiffre(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptographyStreamConversionInterface::IsChainingChiffre() const -> Bool
{
	const CryptographyStreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CryptographyStreamConversionInterface, this); return mt_._CryptographyStreamConversionInterface_IsChainingChiffre((const maxon::GenericComponent*) this + mt_._CryptographyStreamConversionInterface_IsChainingChiffre_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptographyStreamConversionInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsChainingChiffre() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const CryptographyStreamConversionInterface* o_ = (const CryptographyStreamConversionInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = CryptographyStreamConversionInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CryptographyStreamConversionInterface, o_, CryptographyStreamConversionInterface_IsChainingChiffre) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<CryptographyStreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CryptographyStreamConversionInterface>() : PRIVATE_MAXON_VTABLE(CryptographyStreamConversionInterface, o_); 
	return (mt_._CryptographyStreamConversionInterface_IsChainingChiffre(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._CryptographyStreamConversionInterface_IsChainingChiffre_Offset));
}
auto CryptographyStreamConversionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CryptographyStreamConversionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CryptographyStreamConversionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CryptographyStreamConversionInterface() { new (s_ui_maxon_CryptographyStreamConversionInterface) maxon::EntityUse(CryptographyStreamConversionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cryptography.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CryptographyStreamConversionInterface(CryptographyStreamConversionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cryptography.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
namespace BLOWFISHLEGACYENDECODER_OPTIONS
{
	struct ENCRYPT_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xddbbbe9f6ce191e6LL), maxon::UInt(49))> { };
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

