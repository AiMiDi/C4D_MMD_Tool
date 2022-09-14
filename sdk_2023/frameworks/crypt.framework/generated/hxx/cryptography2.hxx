
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
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(CryptographyStreamConversionInterface_IsChainingChiffre, IsChainingChiffre, true, maxon::GenericComponent, const, (Bool));
	maxon::Int CryptographyStreamConversionInterface_IsChainingChiffre_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, CryptographyStreamConversionInterface, IsChainingChiffre))
	{
		maxon::Tie(CryptographyStreamConversionInterface_IsChainingChiffre, CryptographyStreamConversionInterface_IsChainingChiffre_Offset) = CryptographyStreamConversionInterface_IsChainingChiffre_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<CryptographyStreamConversionInterface, typename StreamConversionInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<CryptographyStreamConversionInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct CryptographyStreamConversionInterface::Hxx2
{
	template <typename S> class CWrapper : public StreamConversionInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IsChainingChiffre);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename StreamConversionInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (CryptographyStreamConversionInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, CryptographyStreamConversionInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(CryptographyStreamConversionInterface_IsChainingChiffre, maxon::GenericComponent, const, (Bool)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IsChainingChiffre(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CryptographyStreamConversionInterface::IsChainingChiffre() const -> Bool
{
	const CryptographyStreamConversionInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(CryptographyStreamConversionInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.CryptographyStreamConversionInterface_IsChainingChiffre_Offset), mt_.CryptographyStreamConversionInterface_IsChainingChiffre);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto CryptographyStreamConversionInterface::Hxx1::ConstFn<S>::IsChainingChiffre() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const CryptographyStreamConversionInterface* o_ = (const CryptographyStreamConversionInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = CryptographyStreamConversionInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(CryptographyStreamConversionInterface, o_, CryptographyStreamConversionInterface_IsChainingChiffre) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<CryptographyStreamConversionInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<CryptographyStreamConversionInterface>() : PRIVATE_MAXON_VTABLE(CryptographyStreamConversionInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.CryptographyStreamConversionInterface_IsChainingChiffre_Offset), mt_.CryptographyStreamConversionInterface_IsChainingChiffre));
}
auto CryptographyStreamConversionInterface::GetPtr() -> Ptr { return Ptr(this); }
auto CryptographyStreamConversionInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cryptography)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CryptographyStreamConversionInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CryptographyStreamConversionInterface() { new (s_ui_maxon_CryptographyStreamConversionInterface) maxon::EntityUse(CryptographyStreamConversionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cryptography.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CryptographyStreamConversionInterface(CryptographyStreamConversionInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cryptography.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

