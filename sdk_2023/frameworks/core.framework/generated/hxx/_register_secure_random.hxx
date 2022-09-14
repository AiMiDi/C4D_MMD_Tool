#if 1
namespace maxon
{
	const maxon::Char* const SecureRandom::MTable::_ids = 
		"GetDefaultProvider@80ad0c84b7353314\0" // SecureRandomProvider GetDefaultProvider()
		"GetRandomNumber@2b2bc4ffe80fb478\0" // Bool GetRandomNumber(SecureRandomProvider provider, const Block<Byte>& buffer)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class SecureRandom::Hxx2::Unresolved : public SecureRandom
	{
	public:
		static const Unresolved* Get(const SecureRandom* o) { return (const Unresolved*) o; }
		static Unresolved* Get(SecureRandom* o) { return (Unresolved*) o; }
		static SecureRandomProvider GetDefaultProvider() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SecureRandom::GetDefaultProvider(); return maxon::PrivateIncompleteNullReturnValue<SecureRandomProvider>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Bool GetRandomNumber(SecureRandomProvider provider, const Block<Byte>& buffer) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SecureRandom::GetRandomNumber(std::forward<SecureRandomProvider>(provider), buffer); return maxon::PrivateLogNullptrError(false);}
	};
	MAXON_WARNING_POP
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
		if (maxon::details::NullReturnType<SecureRandomProvider>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->SecureRandom_GetDefaultProvider = PRIVATE_MAXON_MF_CAST(decltype(SecureRandom_GetDefaultProvider), &Hxx2::Wrapper<Hxx2::Unresolved>::SecureRandom_GetDefaultProvider);
		#else
		tbl->SecureRandom_GetDefaultProvider = PRIVATE_MAXON_MF_CAST(decltype(SecureRandom_GetDefaultProvider), &Hxx2::Wrapper<Hxx2::Unresolved>::SecureRandom_GetDefaultProvider);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SecureRandom_GetRandomNumber = PRIVATE_MAXON_MF_CAST(decltype(SecureRandom_GetRandomNumber), &Hxx2::Wrapper<Hxx2::Unresolved>::SecureRandom_GetRandomNumber);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
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
