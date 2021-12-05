
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct SecureRandom::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	SecureRandomProvider (*_SecureRandom_GetDefaultProvider) ();
	Bool (*_SecureRandom_GetRandomNumber) (SecureRandomProvider provider, const Block<UChar>& buffer);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_SecureRandom_GetDefaultProvider = &IMPL::_SecureRandom_GetDefaultProvider;
		tbl->_SecureRandom_GetRandomNumber = &IMPL::_SecureRandom_GetRandomNumber;
	}
};

template <typename C> class SecureRandom::Wrapper
{
public:
	static SecureRandomProvider _SecureRandom_GetDefaultProvider() { return C::GetDefaultProvider(); }
	static Bool _SecureRandom_GetRandomNumber(SecureRandomProvider provider, const Block<UChar>& buffer) { return C::GetRandomNumber(std::forward<SecureRandomProvider>(provider), buffer); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto SecureRandom::GetDefaultProvider() -> SecureRandomProvider
{
	return MTable::_instance._SecureRandom_GetDefaultProvider();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SecureRandom::GetRandomNumber(SecureRandomProvider provider, const Block<UChar>& buffer) -> Bool
{
	return MTable::_instance._SecureRandom_GetRandomNumber(std::forward<SecureRandomProvider>(provider), buffer);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_SecureRandom(SecureRandom::_interface.GetReference(), &maxon::g_translationUnit, "maxon/secure_random.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

