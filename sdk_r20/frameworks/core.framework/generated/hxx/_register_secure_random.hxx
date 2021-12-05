#if 1
namespace maxon
{
	const maxon::Char* const SecureRandom::MTable::_ids = 
		"GetDefaultProvider@18f6dd3947eeb8eb\0" // GetDefaultProvider()
		"GetRandomNumber@1115e5c90c5bd2a4\0" // GetRandomNumber(SecureRandomProvider provider, const Block<UChar>& buffer)
	"";
	class SecureRandom::Unresolved : public SecureRandom
	{
	public:
		static const Unresolved* Get(const SecureRandom* o) { return (const Unresolved*) o; }
		static Unresolved* Get(SecureRandom* o) { return (Unresolved*) o; }
		static SecureRandomProvider GetDefaultProvider() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SecureRandom::GetDefaultProvider(); return maxon::PrivateIncompleteNullReturnValue<SecureRandomProvider>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Bool GetRandomNumber(SecureRandomProvider provider, const Block<UChar>& buffer) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SecureRandom::GetRandomNumber(std::forward<SecureRandomProvider>(provider), buffer); return maxon::PrivateLogNullptrError(false);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE SecureRandom::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<SecureRandomProvider>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool SecureRandom::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<SecureRandomProvider>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SecureRandom_GetDefaultProvider = &Wrapper<Unresolved>::_SecureRandom_GetDefaultProvider;
	#else
		tbl->_SecureRandom_GetDefaultProvider = &Wrapper<Unresolved>::_SecureRandom_GetDefaultProvider;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SecureRandom_GetRandomNumber = &Wrapper<Unresolved>::_SecureRandom_GetRandomNumber;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(SecureRandom, "net.maxon.interface.securerandom", nullptr);
	template <typename DUMMY> maxon::Int SecureRandom::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<SecureRandomProvider>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_secure_random(0
	| maxon::SecureRandom::PrivateInstantiateNullValueHelper<maxon::Int>()
);
