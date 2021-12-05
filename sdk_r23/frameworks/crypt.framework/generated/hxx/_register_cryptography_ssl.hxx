#if 1
namespace maxon
{
	const maxon::Char* const SSLInterface::MTable::_ids = 
		"ERR_get_state@7c2e4116115ca0ae\0" // ERR_STATE* ERR_get_state()
		"ERR_clear_error@c52e0d8d7af2df35\0" // void ERR_clear_error()
		"ADD_thread_state@c52e0d8d7af2df35\0" // void ADD_thread_state()
		"SSL_load_error_strings@c52e0d8d7af2df35\0" // void SSL_load_error_strings()
		"SSL_library_init@4153dd736b06a0ec\0" // int SSL_library_init()
		"SSL_CTX_new@176631932a81e65c\0" // SSL_CTX* SSL_CTX_new(const SSL_METHOD* meth)
		"TLSv1_method@7ef662892d95cd4a\0" // const SSL_METHOD* TLSv1_method()
		"TLSv1_1_method@7ef662892d95cd4a\0" // const SSL_METHOD* TLSv1_1_method()
		"TLSv1_2_method@7ef662892d95cd4a\0" // const SSL_METHOD* TLSv1_2_method()
		"SSLv3_method@7ef662892d95cd4a\0" // const SSL_METHOD* SSLv3_method()
		"SSLv2_method@7ef662892d95cd4a\0" // const SSL_METHOD* SSLv2_method()
		"SSLv23_method@7ef662892d95cd4a\0" // const SSL_METHOD* SSLv23_method()
		"SSL_new@d625d5441fe91349\0" // SSL* SSL_new(SSL_CTX* ctx)
		"ERR_get_error_string@b8f12df9fd0527a6\0" // String ERR_get_error_string()
		"ERR_get_error@76b27a2fe92c86ea\0" // unsigned long ERR_get_error()
		"ERR_peek_last_error@76b27a2fe92c86ea\0" // unsigned long ERR_peek_last_error()
		"SSL_set_fd@20713121897ab87\0" // int SSL_set_fd(SSL* s, int fd)
		"SSL_set_tlsext_hostname@7b1a4060970de2ef\0" // int SSL_set_tlsext_hostname(SSL* s, const char* serverName)
		"SSL_connect@591a3f1448477e98\0" // int SSL_connect(SSL* ssl)
		"SSL_shutdown@591a3f1448477e98\0" // int SSL_shutdown(SSL* s)
		"SSL_free@aacd3c53aecb2af9\0" // void SSL_free(SSL* ssl)
		"SSL_CTX_free@4187a74fc38f74cf\0" // void SSL_CTX_free(SSL_CTX* ctx)
		"SSL_read@698bf9db0478c8b\0" // int SSL_read(SSL* ssl, void* buf, int num)
		"SSL_write@34990f6355a254d6\0" // int SSL_write(SSL* ssl, const void* buf, int num)
		"SSL_get_verify_result@e52ea5a89cdd39f6\0" // long SSL_get_verify_result(const SSL* ssl)
		"SSL_CTX_set_cipher_list@f33b38df93196a79\0" // int SSL_CTX_set_cipher_list(SSL_CTX* ctx, const char* str)
		"SSL_CTX_load_verify_locations@a2bab68663cf61f2\0" // int SSL_CTX_load_verify_locations(SSL_CTX* ctx, const char* CAfile, const char* CApath)
		"SSL_CTX_set_default_verify_paths@13d09fd0b9a637e6\0" // int SSL_CTX_set_default_verify_paths(SSL_CTX* ctx)
		"SSL_CTX_use_PrivateKey_file@8636792a2a1b423a\0" // int SSL_CTX_use_PrivateKey_file(SSL_CTX* ctx, const char* file, int type)
		"SSL_CTX_use_certificate_chain_file@f33b38df93196a79\0" // int SSL_CTX_use_certificate_chain_file(SSL_CTX* ctx, const char* file)
		"SSL_CTX_ctrl@4d198a574f771cac\0" // long SSL_CTX_ctrl(SSL_CTX* ctx, int cmd, long larg, void* parg)
		"SSL_CTX_set_verify@2bc5274c850976fd\0" // void SSL_CTX_set_verify(SSL_CTX* ctx, int mode, sslctxsetverifycallback callback)
		"SSL_set_connect_state@aacd3c53aecb2af9\0" // void SSL_set_connect_state(SSL* s)
		"SSL_set_accept_state@aacd3c53aecb2af9\0" // void SSL_set_accept_state(SSL* s)
		"BIO_ctrl@93715eaa0f824a26\0" // long BIO_ctrl(BIO* bp, int cmd, long larg, void* parg)
		"SSL_get_rbio@169f08037924f508\0" // BIO* SSL_get_rbio(const SSL* s)
		"SSL_get_wbio@169f08037924f508\0" // BIO* SSL_get_wbio(const SSL* s)
		"SSL_do_handshake@591a3f1448477e98\0" // int SSL_do_handshake(SSL* s)
		"SSL_get_error@99b80c126c048c94\0" // int SSL_get_error(const SSL* s, int ret_code)
		"SSL_CIPHER_get_version@5b23fa129c589531\0" // const char* SSL_CIPHER_get_version(const SSL_CIPHER* current)
		"SSL_get_current_cipher@cdd3c3e989fcbbbb\0" // const SSL_CIPHER* SSL_get_current_cipher(const SSL* s)
		"X509_free_@b14d65d2c3eb7ef7\0" // void X509_free_(X509* a)
		"SSL_get_peer_certificate@94f1bef9b3030348\0" // X509* SSL_get_peer_certificate(const SSL* s)
		"X509_NAME_oneline@ad75e9be1f09355f\0" // char* X509_NAME_oneline(X509_NAME_* a, char* buf, int size)
		"X509_NAME_get_text_by_NID@73aa225385280ff9\0" // int X509_NAME_get_text_by_NID(X509_NAME_* name, int nid, char* buf, int len)
		"X509_get_subject_name@cfd5cefd11f10052\0" // X509_NAME_* X509_get_subject_name(X509* a)
		"X509_get_issuer_name@cfd5cefd11f10052\0" // X509_NAME_* X509_get_issuer_name(X509* a)
		"SSL_get_alt_names@e83c8d149fd2e79d\0" // Result<void> SSL_get_alt_names(X509* a, BaseArray<String>& alternativeNames)
		"SSL_set_read_ahead@4a2d3ee5d5488aba\0" // void SSL_set_read_ahead(SSL* s, int yes)
		"SSL_pending@2061c4aadb388aef\0" // int SSL_pending(const SSL* s)
		"SSL_get_shutdown@2061c4aadb388aef\0" // int SSL_get_shutdown(const SSL* ssl)
		"SSL_CTX_use_PrivateKey_ASN1_RSA@5fb7307c10a49a85\0" // int SSL_CTX_use_PrivateKey_ASN1_RSA(SSL_CTX* ctx, unsigned char* d, long len)
		"VerifySignature@5b03380ff3582203\0" // Result<Bool> VerifySignature(const Block<const Char>& publicKey, const Block<const Char>& messageHash, const Block<const Char>& message)
		"CreateSignature@d71ff1fbb5951a48\0" // Result<void> CreateSignature(const Block<const Char>& privateKey, BaseArray<Char>& messageHash, const Block<const Char>& message)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class SSLInterface::Hxx2::Unresolved : public SSLInterface
	{
	public:
		static const Unresolved* Get(const SSLInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(SSLInterface* o) { return (Unresolved*) o; }
		static ERR_STATE* ERR_get_state() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::ERR_get_state(); return nullptr;}
		static void ERR_clear_error() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::ERR_clear_error(); return maxon::PrivateLogNullptrError();}
		static void ADD_thread_state() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::ADD_thread_state(); return maxon::PrivateLogNullptrError();}
		static void SSL_load_error_strings() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_load_error_strings(); return maxon::PrivateLogNullptrError();}
		static int SSL_library_init() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_library_init(); return 0;}
		static SSL_CTX* SSL_CTX_new(const SSL_METHOD* meth) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_CTX_new(meth); return nullptr;}
		static const SSL_METHOD* TLSv1_method() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::TLSv1_method(); return nullptr;}
		static const SSL_METHOD* TLSv1_1_method() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::TLSv1_1_method(); return nullptr;}
		static const SSL_METHOD* TLSv1_2_method() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::TLSv1_2_method(); return nullptr;}
		static const SSL_METHOD* SSLv3_method() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSLv3_method(); return nullptr;}
		static const SSL_METHOD* SSLv2_method() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSLv2_method(); return nullptr;}
		static const SSL_METHOD* SSLv23_method() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSLv23_method(); return nullptr;}
		static SSL* SSL_new(SSL_CTX* ctx) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_new(ctx); return nullptr;}
		static String ERR_get_error_string() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::ERR_get_error_string(); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static unsigned long ERR_get_error() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::ERR_get_error(); return maxon::PrivateIncompleteNullReturnValue<unsigned long>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static unsigned long ERR_peek_last_error() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::ERR_peek_last_error(); return maxon::PrivateIncompleteNullReturnValue<unsigned long>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static int SSL_set_fd(SSL* s, int fd) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_set_fd(s, fd); return 0;}
		static int SSL_set_tlsext_hostname(SSL* s, const char* serverName) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_set_tlsext_hostname(s, serverName); return 0;}
		static int SSL_connect(SSL* ssl) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_connect(ssl); return 0;}
		static int SSL_shutdown(SSL* s) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_shutdown(s); return 0;}
		static void SSL_free(SSL* ssl) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_free(ssl); return maxon::PrivateLogNullptrError();}
		static void SSL_CTX_free(SSL_CTX* ctx) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_CTX_free(ctx); return maxon::PrivateLogNullptrError();}
		static int SSL_read(SSL* ssl, void* buf, int num) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_read(ssl, buf, num); return 0;}
		static int SSL_write(SSL* ssl, const void* buf, int num) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_write(ssl, buf, num); return 0;}
		static long SSL_get_verify_result(const SSL* ssl) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_get_verify_result(ssl); return 0;}
		static int SSL_CTX_set_cipher_list(SSL_CTX* ctx, const char* str) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_CTX_set_cipher_list(ctx, str); return 0;}
		static int SSL_CTX_load_verify_locations(SSL_CTX* ctx, const char* CAfile, const char* CApath) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_CTX_load_verify_locations(ctx, CAfile, CApath); return 0;}
		static int SSL_CTX_set_default_verify_paths(SSL_CTX* ctx) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_CTX_set_default_verify_paths(ctx); return 0;}
		static int SSL_CTX_use_PrivateKey_file(SSL_CTX* ctx, const char* file, int type) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_CTX_use_PrivateKey_file(ctx, file, type); return 0;}
		static int SSL_CTX_use_certificate_chain_file(SSL_CTX* ctx, const char* file) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_CTX_use_certificate_chain_file(ctx, file); return 0;}
		static long SSL_CTX_ctrl(SSL_CTX* ctx, int cmd, long larg, void* parg) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_CTX_ctrl(ctx, cmd, larg, parg); return 0;}
		static void SSL_CTX_set_verify(SSL_CTX* ctx, int mode, sslctxsetverifycallback callback) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_CTX_set_verify(ctx, mode, std::forward<sslctxsetverifycallback>(callback)); return maxon::PrivateLogNullptrError();}
		static void SSL_set_connect_state(SSL* s) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_set_connect_state(s); return maxon::PrivateLogNullptrError();}
		static void SSL_set_accept_state(SSL* s) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_set_accept_state(s); return maxon::PrivateLogNullptrError();}
		static long BIO_ctrl(BIO* bp, int cmd, long larg, void* parg) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::BIO_ctrl(bp, cmd, larg, parg); return 0;}
		static BIO* SSL_get_rbio(const SSL* s) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_get_rbio(s); return nullptr;}
		static BIO* SSL_get_wbio(const SSL* s) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_get_wbio(s); return nullptr;}
		static int SSL_do_handshake(SSL* s) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_do_handshake(s); return 0;}
		static int SSL_get_error(const SSL* s, int ret_code) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_get_error(s, ret_code); return 0;}
		static const char* SSL_CIPHER_get_version(const SSL_CIPHER* current) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_CIPHER_get_version(current); return nullptr;}
		static const SSL_CIPHER* SSL_get_current_cipher(const SSL* s) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_get_current_cipher(s); return nullptr;}
		static void X509_free_(X509* a) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::X509_free_(a); return maxon::PrivateLogNullptrError();}
		static X509* SSL_get_peer_certificate(const SSL* s) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_get_peer_certificate(s); return nullptr;}
		static char* X509_NAME_oneline(X509_NAME_* a, char* buf, int size) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::X509_NAME_oneline(a, buf, size); return nullptr;}
		static int X509_NAME_get_text_by_NID(X509_NAME_* name, int nid, char* buf, int len) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::X509_NAME_get_text_by_NID(name, nid, buf, len); return 0;}
		static X509_NAME_* X509_get_subject_name(X509* a) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::X509_get_subject_name(a); return nullptr;}
		static X509_NAME_* X509_get_issuer_name(X509* a) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::X509_get_issuer_name(a); return nullptr;}
		static Result<void> SSL_get_alt_names(X509* a, BaseArray<String>& alternativeNames) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return SSLInterface::SSL_get_alt_names(a, alternativeNames); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static void SSL_set_read_ahead(SSL* s, int yes) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_set_read_ahead(s, yes); return maxon::PrivateLogNullptrError();}
		static int SSL_pending(const SSL* s) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_pending(s); return 0;}
		static int SSL_get_shutdown(const SSL* ssl) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_get_shutdown(ssl); return 0;}
		static int SSL_CTX_use_PrivateKey_ASN1_RSA(SSL_CTX* ctx, unsigned char* d, long len) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSLInterface::SSL_CTX_use_PrivateKey_ASN1_RSA(ctx, d, len); return 0;}
		static Result<Bool> VerifySignature(const Block<const Char>& publicKey, const Block<const Char>& messageHash, const Block<const Char>& message) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return SSLInterface::VerifySignature(publicKey, messageHash, message); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> CreateSignature(const Block<const Char>& privateKey, BaseArray<Char>& messageHash, const Block<const Char>& message) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return SSLInterface::CreateSignature(privateKey, messageHash, message); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE SSLInterface::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<ERR_STATE*>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<SSL_CTX*>::value,
		maxon::details::NullReturnType<const SSL_METHOD*>::value,
		maxon::details::NullReturnType<const SSL_METHOD*>::value,
		maxon::details::NullReturnType<const SSL_METHOD*>::value,
		maxon::details::NullReturnType<const SSL_METHOD*>::value,
		maxon::details::NullReturnType<const SSL_METHOD*>::value,
		maxon::details::NullReturnType<const SSL_METHOD*>::value,
		maxon::details::NullReturnType<SSL*>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<unsigned long>::value,
		maxon::details::NullReturnType<unsigned long>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<long>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<long>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<long>::value,
		maxon::details::NullReturnType<BIO*>::value,
		maxon::details::NullReturnType<BIO*>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<const char*>::value,
		maxon::details::NullReturnType<const SSL_CIPHER*>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<X509*>::value,
		maxon::details::NullReturnType<char*>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<X509_NAME_*>::value,
		maxon::details::NullReturnType<X509_NAME_*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<Result<Bool>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool SSLInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_ERR_get_state = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_ERR_get_state;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_ERR_clear_error = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_ERR_clear_error;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_ADD_thread_state = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_ADD_thread_state;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_load_error_strings = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_load_error_strings;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_library_init = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_library_init;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_CTX_new = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_CTX_new;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_TLSv1_method = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_TLSv1_method;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_TLSv1_1_method = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_TLSv1_1_method;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_TLSv1_2_method = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_TLSv1_2_method;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSLv3_method = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSLv3_method;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSLv2_method = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSLv2_method;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSLv23_method = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSLv23_method;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_new = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_new;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SSLInterface_ERR_get_error_string = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_ERR_get_error_string;
		#else
		tbl->_SSLInterface_ERR_get_error_string = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_ERR_get_error_string;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<unsigned long>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SSLInterface_ERR_get_error = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_ERR_get_error;
		#else
		tbl->_SSLInterface_ERR_get_error = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_ERR_get_error;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<unsigned long>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SSLInterface_ERR_peek_last_error = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_ERR_peek_last_error;
		#else
		tbl->_SSLInterface_ERR_peek_last_error = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_ERR_peek_last_error;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_set_fd = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_set_fd;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_set_tlsext_hostname = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_set_tlsext_hostname;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_connect = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_connect;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_shutdown = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_shutdown;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_free = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_CTX_free = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_CTX_free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_read = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_read;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_write = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_write;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_get_verify_result = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_get_verify_result;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_CTX_set_cipher_list = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_CTX_set_cipher_list;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_CTX_load_verify_locations = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_CTX_load_verify_locations;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_CTX_set_default_verify_paths = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_CTX_set_default_verify_paths;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_CTX_use_PrivateKey_file = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_CTX_use_PrivateKey_file;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_CTX_use_certificate_chain_file = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_CTX_use_certificate_chain_file;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_CTX_ctrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_CTX_ctrl;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_CTX_set_verify = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_CTX_set_verify;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_set_connect_state = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_set_connect_state;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_set_accept_state = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_set_accept_state;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_BIO_ctrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_BIO_ctrl;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_get_rbio = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_get_rbio;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_get_wbio = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_get_wbio;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_do_handshake = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_do_handshake;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_get_error = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_get_error;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_CIPHER_get_version = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_CIPHER_get_version;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_get_current_cipher = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_get_current_cipher;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_X509_free_ = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_X509_free_;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_get_peer_certificate = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_get_peer_certificate;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_X509_NAME_oneline = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_X509_NAME_oneline;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_X509_NAME_get_text_by_NID = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_X509_NAME_get_text_by_NID;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_X509_get_subject_name = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_X509_get_subject_name;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_X509_get_issuer_name = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_X509_get_issuer_name;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SSLInterface_SSL_get_alt_names = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_get_alt_names;
		#else
		tbl->_SSLInterface_SSL_get_alt_names = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_get_alt_names;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_set_read_ahead = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_set_read_ahead;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_pending = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_pending;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_get_shutdown = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_get_shutdown;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_SSLInterface_SSL_CTX_use_PrivateKey_ASN1_RSA = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_SSL_CTX_use_PrivateKey_ASN1_RSA;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Bool>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SSLInterface_VerifySignature = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_VerifySignature;
		#else
		tbl->_SSLInterface_VerifySignature = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_VerifySignature;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_SSLInterface_CreateSignature = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_CreateSignature;
		#else
		tbl->_SSLInterface_CreateSignature = &Hxx2::Wrapper<Hxx2::Unresolved>::_SSLInterface_CreateSignature;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(SSLInterface, "net.maxon.interface.ssl", nullptr);
	template <typename DUMMY> maxon::Int SSLInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<unsigned long>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_cryptography_ssl(0
	| maxon::SSLInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
