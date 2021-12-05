
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
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
	Bool (*_SecureRandom_GetRandomNumber) (SecureRandomProvider provider, const Block<Byte>& buffer);
	template <typename IMPL> void Init()
	{
		_SecureRandom_GetDefaultProvider = &IMPL::_SecureRandom_GetDefaultProvider;
		_SecureRandom_GetRandomNumber = &IMPL::_SecureRandom_GetRandomNumber;
	}
};

struct SecureRandom::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static SecureRandomProvider _SecureRandom_GetDefaultProvider() { return C::GetDefaultProvider(); }
	static Bool _SecureRandom_GetRandomNumber(SecureRandomProvider provider, const Block<Byte>& buffer) { return C::GetRandomNumber(std::forward<SecureRandomProvider>(provider), buffer); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto SecureRandom::GetDefaultProvider() -> SecureRandomProvider
{
	return MTable::_instance._SecureRandom_GetDefaultProvider();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SecureRandom::GetRandomNumber(SecureRandomProvider provider, const Block<Byte>& buffer) -> Bool
{
	return MTable::_instance._SecureRandom_GetRandomNumber(std::forward<SecureRandomProvider>(provider), buffer);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_SecureRandom); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_SecureRandom() { new (s_ui_maxon_SecureRandom) maxon::EntityUse(SecureRandom::_interface.GetReference(), &maxon::g_translationUnit, "maxon/secure_random.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_SecureRandom(SecureRandom::_interface.GetReference(), &maxon::g_translationUnit, "maxon/secure_random.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

