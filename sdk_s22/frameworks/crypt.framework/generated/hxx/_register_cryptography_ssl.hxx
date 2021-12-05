#if 1
namespace maxon
{
	const maxon::Char* const SSLInterface::MTable::_ids = 
		"ERR_get_state@194b56c08645f5b3\0" // ERR_STATE* ERR_get_state()
		"ERR_clear_error@cfa940f4\0" // void ERR_clear_error()
		"ADD_thread_state@cfa940f4\0" // void ADD_thread_state()
		"SSL_load_error_strings@cfa940f4\0" // void SSL_load_error_strings()
		"SSL_library_init@5fb5c8f\0" // int SSL_library_init()
		"SSL_CTX_new@7d5051d8c94ee897\0" // SSL_CTX* SSL_CTX_new(const SSL_METHOD* meth)
		"TLSv1_method@8cbe0309d62facf9\0" // const SSL_METHOD* TLSv1_method()
		"TLSv1_1_method@8cbe0309d62facf9\0" // const SSL_METHOD* TLSv1_1_method()
		"TLSv1_2_method@8cbe0309d62facf9\0" // const SSL_METHOD* TLSv1_2_method()
		"SSLv3_method@8cbe0309d62facf9\0" // const SSL_METHOD* SSLv3_method()
		"SSLv2_method@8cbe0309d62facf9\0" // const SSL_METHOD* SSLv2_method()
		"SSLv23_method@8cbe0309d62facf9\0" // const SSL_METHOD* SSLv23_method()
		"SSL_new@84124121c62f86e8\0" // SSL* SSL_new(SSL_CTX* ctx)
		"ERR_get_error_string@22c6ed80851\0" // String ERR_get_error_string()
		"ERR_get_error@a4d40e48b9374f67\0" // unsigned long ERR_get_error()
		"ERR_peek_last_error@a4d40e48b9374f67\0" // unsigned long ERR_peek_last_error()
		"SSL_set_fd@a3e0a8d8be924bae\0" // int SSL_set_fd(SSL* s, int fd)
		"SSL_set_tlsext_hostname@97e15b923fa67206\0" // int SSL_set_tlsext_hostname(SSL* s, const char* serverName)
		"SSL_connect@544bab97c291\0" // int SSL_connect(SSL* ssl)
		"SSL_shutdown@544bab97c291\0" // int SSL_shutdown(SSL* s)
		"SSL_free@b6e526942ec76\0" // void SSL_free(SSL* ssl)
		"SSL_CTX_free@152dc0a558c7093e\0" // void SSL_CTX_free(SSL_CTX* ctx)
		"SSL_read@1c66faecaefa9704\0" // int SSL_read(SSL* ssl, void* buf, int num)
		"SSL_write@c9ca9205cde6d061\0" // int SSL_write(SSL* ssl, const void* buf, int num)
		"SSL_get_verify_result@b4c6b9704478f9a1\0" // long SSL_get_verify_result(const SSL* ssl)
		"SSL_CTX_set_cipher_list@bf3139d03c7b5d4e\0" // int SSL_CTX_set_cipher_list(SSL_CTX* ctx, const char* str)
		"SSL_CTX_load_verify_locations@7a2f6fb87caed943\0" // int SSL_CTX_load_verify_locations(SSL_CTX* ctx, const char* CAfile, const char* CApath)
		"SSL_CTX_set_default_verify_paths@a3e0a8d91a3d59d9\0" // int SSL_CTX_set_default_verify_paths(SSL_CTX* ctx)
		"SSL_CTX_use_PrivateKey_file@ed63261caa803feb\0" // int SSL_CTX_use_PrivateKey_file(SSL_CTX* ctx, const char* file, int type)
		"SSL_CTX_use_certificate_chain_file@bf3139d03c7b5d4e\0" // int SSL_CTX_use_certificate_chain_file(SSL_CTX* ctx, const char* file)
		"SSL_CTX_ctrl@a9e04f07ca5efcb1\0" // long SSL_CTX_ctrl(SSL_CTX* ctx, int cmd, long larg, void* parg)
		"SSL_CTX_set_verify@57c0303d7fac3b42\0" // void SSL_CTX_set_verify(SSL_CTX* ctx, int mode, sslctxsetverifycallback callback)
		"SSL_set_connect_state@b6e526942ec76\0" // void SSL_set_connect_state(SSL* s)
		"SSL_set_accept_state@b6e526942ec76\0" // void SSL_set_accept_state(SSL* s)
		"BIO_ctrl@306fb7243d1ba6fd\0" // long BIO_ctrl(BIO* bp, int cmd, long larg, void* parg)
		"SSL_get_rbio@7d7969ddbce4d667\0" // BIO* SSL_get_rbio(const SSL* s)
		"SSL_get_wbio@7d7969ddbce4d667\0" // BIO* SSL_get_wbio(const SSL* s)
		"SSL_do_handshake@544bab97c291\0" // int SSL_do_handshake(SSL* s)
		"SSL_get_error@460644b8953d0631\0" // int SSL_get_error(const SSL* s, int ret_code)
		"SSL_CIPHER_get_version@969ef550a1dd5680\0" // const char* SSL_CIPHER_get_version(const SSL_CIPHER* current)
		"SSL_get_current_cipher@909dea5cf8bba994\0" // const SSL_CIPHER* SSL_get_current_cipher(const SSL* s)
		"X509_free_@1625bfac5ef9b2e\0" // void X509_free_(X509* a)
		"SSL_get_peer_certificate@3809fa53d3642e69\0" // X509* SSL_get_peer_certificate(const SSL* s)
		"X509_NAME_oneline@a94ecc5284b07098\0" // char* X509_NAME_oneline(X509_NAME_* a, char* buf, int size)
		"X509_NAME_get_text_by_NID@86551ff1abf6df3a\0" // int X509_NAME_get_text_by_NID(X509_NAME_* name, int nid, char* buf, int len)
		"X509_get_subject_name@ba8310c9896ba833\0" // X509_NAME_* X509_get_subject_name(X509* a)
		"X509_get_issuer_name@ba8310c9896ba833\0" // X509_NAME_* X509_get_issuer_name(X509* a)
		"SSL_get_alt_names@0e06d84fa01b8ad6\0" // Result<void> SSL_get_alt_names(X509* a, BaseArray<String>& alternativeNames)
		"SSL_set_read_ahead@152dc0a4fd1bfb13\0" // void SSL_set_read_ahead(SSL* s, int yes)
		"SSL_pending@2e8b2a5d1c723694\0" // int SSL_pending(const SSL* s)
		"SSL_get_shutdown@2e8b2a5d1c723694\0" // int SSL_get_shutdown(const SSL* ssl)
		"SSL_CTX_use_PrivateKey_ASN1_RSA@1682f02762d8fd46\0" // int SSL_CTX_use_PrivateKey_ASN1_RSA(SSL_CTX* ctx, unsigned char* d, long len)
		"VerifySignature@c8a561339a6d2c4e\0" // Result<Bool> VerifySignature(const Block<const Char>& publicKey, const Block<const Char>& messageHash, const Block<const Char>& message)
		"CreateSignature@055b78c4bf58516f\0" // Result<void> CreateSignature(const Block<const Char>& privateKey, BaseArray<Char>& messageHash, const Block<const Char>& message)
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
