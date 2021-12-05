
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct SSLInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	ERR_STATE* (*_SSLInterface_ERR_get_state) ();
	void (*_SSLInterface_ERR_clear_error) ();
	void (*_SSLInterface_ADD_thread_state) ();
	void (*_SSLInterface_SSL_load_error_strings) ();
	int (*_SSLInterface_SSL_library_init) ();
	SSL_CTX* (*_SSLInterface_SSL_CTX_new) (const SSL_METHOD* meth);
	const SSL_METHOD* (*_SSLInterface_TLSv1_method) ();
	const SSL_METHOD* (*_SSLInterface_TLSv1_1_method) ();
	const SSL_METHOD* (*_SSLInterface_TLSv1_2_method) ();
	const SSL_METHOD* (*_SSLInterface_SSLv3_method) ();
	const SSL_METHOD* (*_SSLInterface_SSLv2_method) ();
	const SSL_METHOD* (*_SSLInterface_SSLv23_method) ();
	SSL* (*_SSLInterface_SSL_new) (SSL_CTX* ctx);
	String (*_SSLInterface_ERR_get_error_string) ();
	unsigned long (*_SSLInterface_ERR_get_error) ();
	unsigned long (*_SSLInterface_ERR_peek_last_error) ();
	int (*_SSLInterface_SSL_set_fd) (SSL* s, int fd);
	int (*_SSLInterface_SSL_set_tlsext_hostname) (SSL* s, const char* serverName);
	int (*_SSLInterface_SSL_connect) (SSL* ssl);
	int (*_SSLInterface_SSL_shutdown) (SSL* s);
	void (*_SSLInterface_SSL_free) (SSL* ssl);
	void (*_SSLInterface_SSL_CTX_free) (SSL_CTX* ctx);
	int (*_SSLInterface_SSL_read) (SSL* ssl, void* buf, int num);
	int (*_SSLInterface_SSL_write) (SSL* ssl, const void* buf, int num);
	long (*_SSLInterface_SSL_get_verify_result) (const SSL* ssl);
	int (*_SSLInterface_SSL_CTX_set_cipher_list) (SSL_CTX* ctx, const char* str);
	int (*_SSLInterface_SSL_CTX_load_verify_locations) (SSL_CTX* ctx, const char* CAfile, const char* CApath);
	int (*_SSLInterface_SSL_CTX_use_PrivateKey_file) (SSL_CTX* ctx, const char* file, int type);
	int (*_SSLInterface_SSL_CTX_use_certificate_chain_file) (SSL_CTX* ctx, const char* file);
	long (*_SSLInterface_SSL_CTX_ctrl) (SSL_CTX* ctx, int cmd, long larg, void* parg);
	void (*_SSLInterface_SSL_CTX_set_verify) (SSL_CTX* ctx, int mode, sslctxsetverifycallback callback);
	void (*_SSLInterface_SSL_set_connect_state) (SSL* s);
	void (*_SSLInterface_SSL_set_accept_state) (SSL* s);
	long (*_SSLInterface_BIO_ctrl) (BIO* bp, int cmd, long larg, void* parg);
	BIO* (*_SSLInterface_SSL_get_rbio) (const SSL* s);
	BIO* (*_SSLInterface_SSL_get_wbio) (const SSL* s);
	int (*_SSLInterface_SSL_do_handshake) (SSL* s);
	int (*_SSLInterface_SSL_get_error) (const SSL* s, int ret_code);
	const char* (*_SSLInterface_SSL_CIPHER_get_version) (const SSL_CIPHER* current);
	const SSL_CIPHER* (*_SSLInterface_SSL_get_current_cipher) (const SSL* s);
	void (*_SSLInterface_X509_free_) (X509* a);
	X509* (*_SSLInterface_SSL_get_peer_certificate) (const SSL* s);
	char* (*_SSLInterface_X509_NAME_oneline) (X509_NAME_* a, char* buf, int size);
	int (*_SSLInterface_X509_NAME_get_text_by_NID) (X509_NAME_* name, int nid, char* buf, int len);
	X509_NAME_* (*_SSLInterface_X509_get_subject_name) (X509* a);
	X509_NAME_* (*_SSLInterface_X509_get_issuer_name) (X509* a);
	Result<void> (*_SSLInterface_SSL_get_alt_names) (X509* a, BaseArray<String>& alternativeNames);
	void (*_SSLInterface_SSL_set_read_ahead) (SSL* s, int yes);
	int (*_SSLInterface_SSL_pending) (const SSL* s);
	int (*_SSLInterface_SSL_get_shutdown) (const SSL* ssl);
	int (*_SSLInterface_SSL_CTX_use_PrivateKey_ASN1_RSA) (SSL_CTX* ctx, unsigned char* d, long len);
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_SSLInterface_ERR_get_state = &IMPL::_SSLInterface_ERR_get_state;
		tbl->_SSLInterface_ERR_clear_error = &IMPL::_SSLInterface_ERR_clear_error;
		tbl->_SSLInterface_ADD_thread_state = &IMPL::_SSLInterface_ADD_thread_state;
		tbl->_SSLInterface_SSL_load_error_strings = &IMPL::_SSLInterface_SSL_load_error_strings;
		tbl->_SSLInterface_SSL_library_init = &IMPL::_SSLInterface_SSL_library_init;
		tbl->_SSLInterface_SSL_CTX_new = &IMPL::_SSLInterface_SSL_CTX_new;
		tbl->_SSLInterface_TLSv1_method = &IMPL::_SSLInterface_TLSv1_method;
		tbl->_SSLInterface_TLSv1_1_method = &IMPL::_SSLInterface_TLSv1_1_method;
		tbl->_SSLInterface_TLSv1_2_method = &IMPL::_SSLInterface_TLSv1_2_method;
		tbl->_SSLInterface_SSLv3_method = &IMPL::_SSLInterface_SSLv3_method;
		tbl->_SSLInterface_SSLv2_method = &IMPL::_SSLInterface_SSLv2_method;
		tbl->_SSLInterface_SSLv23_method = &IMPL::_SSLInterface_SSLv23_method;
		tbl->_SSLInterface_SSL_new = &IMPL::_SSLInterface_SSL_new;
		tbl->_SSLInterface_ERR_get_error_string = &IMPL::_SSLInterface_ERR_get_error_string;
		tbl->_SSLInterface_ERR_get_error = &IMPL::_SSLInterface_ERR_get_error;
		tbl->_SSLInterface_ERR_peek_last_error = &IMPL::_SSLInterface_ERR_peek_last_error;
		tbl->_SSLInterface_SSL_set_fd = &IMPL::_SSLInterface_SSL_set_fd;
		tbl->_SSLInterface_SSL_set_tlsext_hostname = &IMPL::_SSLInterface_SSL_set_tlsext_hostname;
		tbl->_SSLInterface_SSL_connect = &IMPL::_SSLInterface_SSL_connect;
		tbl->_SSLInterface_SSL_shutdown = &IMPL::_SSLInterface_SSL_shutdown;
		tbl->_SSLInterface_SSL_free = &IMPL::_SSLInterface_SSL_free;
		tbl->_SSLInterface_SSL_CTX_free = &IMPL::_SSLInterface_SSL_CTX_free;
		tbl->_SSLInterface_SSL_read = &IMPL::_SSLInterface_SSL_read;
		tbl->_SSLInterface_SSL_write = &IMPL::_SSLInterface_SSL_write;
		tbl->_SSLInterface_SSL_get_verify_result = &IMPL::_SSLInterface_SSL_get_verify_result;
		tbl->_SSLInterface_SSL_CTX_set_cipher_list = &IMPL::_SSLInterface_SSL_CTX_set_cipher_list;
		tbl->_SSLInterface_SSL_CTX_load_verify_locations = &IMPL::_SSLInterface_SSL_CTX_load_verify_locations;
		tbl->_SSLInterface_SSL_CTX_use_PrivateKey_file = &IMPL::_SSLInterface_SSL_CTX_use_PrivateKey_file;
		tbl->_SSLInterface_SSL_CTX_use_certificate_chain_file = &IMPL::_SSLInterface_SSL_CTX_use_certificate_chain_file;
		tbl->_SSLInterface_SSL_CTX_ctrl = &IMPL::_SSLInterface_SSL_CTX_ctrl;
		tbl->_SSLInterface_SSL_CTX_set_verify = &IMPL::_SSLInterface_SSL_CTX_set_verify;
		tbl->_SSLInterface_SSL_set_connect_state = &IMPL::_SSLInterface_SSL_set_connect_state;
		tbl->_SSLInterface_SSL_set_accept_state = &IMPL::_SSLInterface_SSL_set_accept_state;
		tbl->_SSLInterface_BIO_ctrl = &IMPL::_SSLInterface_BIO_ctrl;
		tbl->_SSLInterface_SSL_get_rbio = &IMPL::_SSLInterface_SSL_get_rbio;
		tbl->_SSLInterface_SSL_get_wbio = &IMPL::_SSLInterface_SSL_get_wbio;
		tbl->_SSLInterface_SSL_do_handshake = &IMPL::_SSLInterface_SSL_do_handshake;
		tbl->_SSLInterface_SSL_get_error = &IMPL::_SSLInterface_SSL_get_error;
		tbl->_SSLInterface_SSL_CIPHER_get_version = &IMPL::_SSLInterface_SSL_CIPHER_get_version;
		tbl->_SSLInterface_SSL_get_current_cipher = &IMPL::_SSLInterface_SSL_get_current_cipher;
		tbl->_SSLInterface_X509_free_ = &IMPL::_SSLInterface_X509_free_;
		tbl->_SSLInterface_SSL_get_peer_certificate = &IMPL::_SSLInterface_SSL_get_peer_certificate;
		tbl->_SSLInterface_X509_NAME_oneline = &IMPL::_SSLInterface_X509_NAME_oneline;
		tbl->_SSLInterface_X509_NAME_get_text_by_NID = &IMPL::_SSLInterface_X509_NAME_get_text_by_NID;
		tbl->_SSLInterface_X509_get_subject_name = &IMPL::_SSLInterface_X509_get_subject_name;
		tbl->_SSLInterface_X509_get_issuer_name = &IMPL::_SSLInterface_X509_get_issuer_name;
		tbl->_SSLInterface_SSL_get_alt_names = &IMPL::_SSLInterface_SSL_get_alt_names;
		tbl->_SSLInterface_SSL_set_read_ahead = &IMPL::_SSLInterface_SSL_set_read_ahead;
		tbl->_SSLInterface_SSL_pending = &IMPL::_SSLInterface_SSL_pending;
		tbl->_SSLInterface_SSL_get_shutdown = &IMPL::_SSLInterface_SSL_get_shutdown;
		tbl->_SSLInterface_SSL_CTX_use_PrivateKey_ASN1_RSA = &IMPL::_SSLInterface_SSL_CTX_use_PrivateKey_ASN1_RSA;
	}
};

template <typename C> class SSLInterface::Wrapper
{
public:
	static ERR_STATE* _SSLInterface_ERR_get_state() { return C::ERR_get_state(); }
	static void _SSLInterface_ERR_clear_error() { return C::ERR_clear_error(); }
	static void _SSLInterface_ADD_thread_state() { return C::ADD_thread_state(); }
	static void _SSLInterface_SSL_load_error_strings() { return C::SSL_load_error_strings(); }
	static int _SSLInterface_SSL_library_init() { return C::SSL_library_init(); }
	static SSL_CTX* _SSLInterface_SSL_CTX_new(const SSL_METHOD* meth) { return C::SSL_CTX_new(meth); }
	static const SSL_METHOD* _SSLInterface_TLSv1_method() { return C::TLSv1_method(); }
	static const SSL_METHOD* _SSLInterface_TLSv1_1_method() { return C::TLSv1_1_method(); }
	static const SSL_METHOD* _SSLInterface_TLSv1_2_method() { return C::TLSv1_2_method(); }
	static const SSL_METHOD* _SSLInterface_SSLv3_method() { return C::SSLv3_method(); }
	static const SSL_METHOD* _SSLInterface_SSLv2_method() { return C::SSLv2_method(); }
	static const SSL_METHOD* _SSLInterface_SSLv23_method() { return C::SSLv23_method(); }
	static SSL* _SSLInterface_SSL_new(SSL_CTX* ctx) { return C::SSL_new(ctx); }
	static String _SSLInterface_ERR_get_error_string() { return C::ERR_get_error_string(); }
	static unsigned long _SSLInterface_ERR_get_error() { return C::ERR_get_error(); }
	static unsigned long _SSLInterface_ERR_peek_last_error() { return C::ERR_peek_last_error(); }
	static int _SSLInterface_SSL_set_fd(SSL* s, int fd) { return C::SSL_set_fd(s, fd); }
	static int _SSLInterface_SSL_set_tlsext_hostname(SSL* s, const char* serverName) { return C::SSL_set_tlsext_hostname(s, serverName); }
	static int _SSLInterface_SSL_connect(SSL* ssl) { return C::SSL_connect(ssl); }
	static int _SSLInterface_SSL_shutdown(SSL* s) { return C::SSL_shutdown(s); }
	static void _SSLInterface_SSL_free(SSL* ssl) { return C::SSL_free(ssl); }
	static void _SSLInterface_SSL_CTX_free(SSL_CTX* ctx) { return C::SSL_CTX_free(ctx); }
	static int _SSLInterface_SSL_read(SSL* ssl, void* buf, int num) { return C::SSL_read(ssl, buf, num); }
	static int _SSLInterface_SSL_write(SSL* ssl, const void* buf, int num) { return C::SSL_write(ssl, buf, num); }
	static long _SSLInterface_SSL_get_verify_result(const SSL* ssl) { return C::SSL_get_verify_result(ssl); }
	static int _SSLInterface_SSL_CTX_set_cipher_list(SSL_CTX* ctx, const char* str) { return C::SSL_CTX_set_cipher_list(ctx, str); }
	static int _SSLInterface_SSL_CTX_load_verify_locations(SSL_CTX* ctx, const char* CAfile, const char* CApath) { return C::SSL_CTX_load_verify_locations(ctx, CAfile, CApath); }
	static int _SSLInterface_SSL_CTX_use_PrivateKey_file(SSL_CTX* ctx, const char* file, int type) { return C::SSL_CTX_use_PrivateKey_file(ctx, file, type); }
	static int _SSLInterface_SSL_CTX_use_certificate_chain_file(SSL_CTX* ctx, const char* file) { return C::SSL_CTX_use_certificate_chain_file(ctx, file); }
	static long _SSLInterface_SSL_CTX_ctrl(SSL_CTX* ctx, int cmd, long larg, void* parg) { return C::SSL_CTX_ctrl(ctx, cmd, larg, parg); }
	static void _SSLInterface_SSL_CTX_set_verify(SSL_CTX* ctx, int mode, sslctxsetverifycallback callback) { return C::SSL_CTX_set_verify(ctx, mode, std::forward<sslctxsetverifycallback>(callback)); }
	static void _SSLInterface_SSL_set_connect_state(SSL* s) { return C::SSL_set_connect_state(s); }
	static void _SSLInterface_SSL_set_accept_state(SSL* s) { return C::SSL_set_accept_state(s); }
	static long _SSLInterface_BIO_ctrl(BIO* bp, int cmd, long larg, void* parg) { return C::BIO_ctrl(bp, cmd, larg, parg); }
	static BIO* _SSLInterface_SSL_get_rbio(const SSL* s) { return C::SSL_get_rbio(s); }
	static BIO* _SSLInterface_SSL_get_wbio(const SSL* s) { return C::SSL_get_wbio(s); }
	static int _SSLInterface_SSL_do_handshake(SSL* s) { return C::SSL_do_handshake(s); }
	static int _SSLInterface_SSL_get_error(const SSL* s, int ret_code) { return C::SSL_get_error(s, ret_code); }
	static const char* _SSLInterface_SSL_CIPHER_get_version(const SSL_CIPHER* current) { return C::SSL_CIPHER_get_version(current); }
	static const SSL_CIPHER* _SSLInterface_SSL_get_current_cipher(const SSL* s) { return C::SSL_get_current_cipher(s); }
	static void _SSLInterface_X509_free_(X509* a) { return C::X509_free_(a); }
	static X509* _SSLInterface_SSL_get_peer_certificate(const SSL* s) { return C::SSL_get_peer_certificate(s); }
	static char* _SSLInterface_X509_NAME_oneline(X509_NAME_* a, char* buf, int size) { return C::X509_NAME_oneline(a, buf, size); }
	static int _SSLInterface_X509_NAME_get_text_by_NID(X509_NAME_* name, int nid, char* buf, int len) { return C::X509_NAME_get_text_by_NID(name, nid, buf, len); }
	static X509_NAME_* _SSLInterface_X509_get_subject_name(X509* a) { return C::X509_get_subject_name(a); }
	static X509_NAME_* _SSLInterface_X509_get_issuer_name(X509* a) { return C::X509_get_issuer_name(a); }
	static Result<void> _SSLInterface_SSL_get_alt_names(X509* a, BaseArray<String>& alternativeNames) { return C::SSL_get_alt_names(a, alternativeNames); }
	static void _SSLInterface_SSL_set_read_ahead(SSL* s, int yes) { return C::SSL_set_read_ahead(s, yes); }
	static int _SSLInterface_SSL_pending(const SSL* s) { return C::SSL_pending(s); }
	static int _SSLInterface_SSL_get_shutdown(const SSL* ssl) { return C::SSL_get_shutdown(ssl); }
	static int _SSLInterface_SSL_CTX_use_PrivateKey_ASN1_RSA(SSL_CTX* ctx, unsigned char* d, long len) { return C::SSL_CTX_use_PrivateKey_ASN1_RSA(ctx, d, len); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::ERR_get_state() -> ERR_STATE*
{
	return MTable::_instance._SSLInterface_ERR_get_state();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::ERR_clear_error() -> void
{
	return MTable::_instance._SSLInterface_ERR_clear_error();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::ADD_thread_state() -> void
{
	return MTable::_instance._SSLInterface_ADD_thread_state();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_load_error_strings() -> void
{
	return MTable::_instance._SSLInterface_SSL_load_error_strings();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_library_init() -> int
{
	return MTable::_instance._SSLInterface_SSL_library_init();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_CTX_new(const SSL_METHOD* meth) -> SSL_CTX*
{
	return MTable::_instance._SSLInterface_SSL_CTX_new(meth);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::TLSv1_method() -> const SSL_METHOD*
{
	return MTable::_instance._SSLInterface_TLSv1_method();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::TLSv1_1_method() -> const SSL_METHOD*
{
	return MTable::_instance._SSLInterface_TLSv1_1_method();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::TLSv1_2_method() -> const SSL_METHOD*
{
	return MTable::_instance._SSLInterface_TLSv1_2_method();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSLv3_method() -> const SSL_METHOD*
{
	return MTable::_instance._SSLInterface_SSLv3_method();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSLv2_method() -> const SSL_METHOD*
{
	return MTable::_instance._SSLInterface_SSLv2_method();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSLv23_method() -> const SSL_METHOD*
{
	return MTable::_instance._SSLInterface_SSLv23_method();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_new(SSL_CTX* ctx) -> SSL*
{
	return MTable::_instance._SSLInterface_SSL_new(ctx);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::ERR_get_error_string() -> String
{
	return MTable::_instance._SSLInterface_ERR_get_error_string();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::ERR_get_error() -> unsigned long
{
	return MTable::_instance._SSLInterface_ERR_get_error();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::ERR_peek_last_error() -> unsigned long
{
	return MTable::_instance._SSLInterface_ERR_peek_last_error();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_set_fd(SSL* s, int fd) -> int
{
	return MTable::_instance._SSLInterface_SSL_set_fd(s, fd);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_set_tlsext_hostname(SSL* s, const char* serverName) -> int
{
	return MTable::_instance._SSLInterface_SSL_set_tlsext_hostname(s, serverName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_connect(SSL* ssl) -> int
{
	return MTable::_instance._SSLInterface_SSL_connect(ssl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_shutdown(SSL* s) -> int
{
	return MTable::_instance._SSLInterface_SSL_shutdown(s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_free(SSL* ssl) -> void
{
	return MTable::_instance._SSLInterface_SSL_free(ssl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_CTX_free(SSL_CTX* ctx) -> void
{
	return MTable::_instance._SSLInterface_SSL_CTX_free(ctx);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_read(SSL* ssl, void* buf, int num) -> int
{
	return MTable::_instance._SSLInterface_SSL_read(ssl, buf, num);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_write(SSL* ssl, const void* buf, int num) -> int
{
	return MTable::_instance._SSLInterface_SSL_write(ssl, buf, num);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_get_verify_result(const SSL* ssl) -> long
{
	return MTable::_instance._SSLInterface_SSL_get_verify_result(ssl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_CTX_set_cipher_list(SSL_CTX* ctx, const char* str) -> int
{
	return MTable::_instance._SSLInterface_SSL_CTX_set_cipher_list(ctx, str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_CTX_load_verify_locations(SSL_CTX* ctx, const char* CAfile, const char* CApath) -> int
{
	return MTable::_instance._SSLInterface_SSL_CTX_load_verify_locations(ctx, CAfile, CApath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_CTX_use_PrivateKey_file(SSL_CTX* ctx, const char* file, int type) -> int
{
	return MTable::_instance._SSLInterface_SSL_CTX_use_PrivateKey_file(ctx, file, type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_CTX_use_certificate_chain_file(SSL_CTX* ctx, const char* file) -> int
{
	return MTable::_instance._SSLInterface_SSL_CTX_use_certificate_chain_file(ctx, file);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_CTX_ctrl(SSL_CTX* ctx, int cmd, long larg, void* parg) -> long
{
	return MTable::_instance._SSLInterface_SSL_CTX_ctrl(ctx, cmd, larg, parg);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_CTX_set_verify(SSL_CTX* ctx, int mode, sslctxsetverifycallback callback) -> void
{
	return MTable::_instance._SSLInterface_SSL_CTX_set_verify(ctx, mode, std::forward<sslctxsetverifycallback>(callback));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_set_connect_state(SSL* s) -> void
{
	return MTable::_instance._SSLInterface_SSL_set_connect_state(s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_set_accept_state(SSL* s) -> void
{
	return MTable::_instance._SSLInterface_SSL_set_accept_state(s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::BIO_ctrl(BIO* bp, int cmd, long larg, void* parg) -> long
{
	return MTable::_instance._SSLInterface_BIO_ctrl(bp, cmd, larg, parg);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_get_rbio(const SSL* s) -> BIO*
{
	return MTable::_instance._SSLInterface_SSL_get_rbio(s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_get_wbio(const SSL* s) -> BIO*
{
	return MTable::_instance._SSLInterface_SSL_get_wbio(s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_do_handshake(SSL* s) -> int
{
	return MTable::_instance._SSLInterface_SSL_do_handshake(s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_get_error(const SSL* s, int ret_code) -> int
{
	return MTable::_instance._SSLInterface_SSL_get_error(s, ret_code);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_CIPHER_get_version(const SSL_CIPHER* current) -> const char*
{
	return MTable::_instance._SSLInterface_SSL_CIPHER_get_version(current);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_get_current_cipher(const SSL* s) -> const SSL_CIPHER*
{
	return MTable::_instance._SSLInterface_SSL_get_current_cipher(s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::X509_free_(X509* a) -> void
{
	return MTable::_instance._SSLInterface_X509_free_(a);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_get_peer_certificate(const SSL* s) -> X509*
{
	return MTable::_instance._SSLInterface_SSL_get_peer_certificate(s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::X509_NAME_oneline(X509_NAME_* a, char* buf, int size) -> char*
{
	return MTable::_instance._SSLInterface_X509_NAME_oneline(a, buf, size);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::X509_NAME_get_text_by_NID(X509_NAME_* name, int nid, char* buf, int len) -> int
{
	return MTable::_instance._SSLInterface_X509_NAME_get_text_by_NID(name, nid, buf, len);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::X509_get_subject_name(X509* a) -> X509_NAME_*
{
	return MTable::_instance._SSLInterface_X509_get_subject_name(a);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::X509_get_issuer_name(X509* a) -> X509_NAME_*
{
	return MTable::_instance._SSLInterface_X509_get_issuer_name(a);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_get_alt_names(X509* a, BaseArray<String>& alternativeNames) -> Result<void>
{
	return MTable::_instance._SSLInterface_SSL_get_alt_names(a, alternativeNames);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_set_read_ahead(SSL* s, int yes) -> void
{
	return MTable::_instance._SSLInterface_SSL_set_read_ahead(s, yes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_pending(const SSL* s) -> int
{
	return MTable::_instance._SSLInterface_SSL_pending(s);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_get_shutdown(const SSL* ssl) -> int
{
	return MTable::_instance._SSLInterface_SSL_get_shutdown(ssl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSLInterface::SSL_CTX_use_PrivateKey_ASN1_RSA(SSL_CTX* ctx, unsigned char* d, long len) -> int
{
	return MTable::_instance._SSLInterface_SSL_CTX_use_PrivateKey_ASN1_RSA(ctx, d, len);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_SSLInterface(SSLInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cryptography_ssl.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

