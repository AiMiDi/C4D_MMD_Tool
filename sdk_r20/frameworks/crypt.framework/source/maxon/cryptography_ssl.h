#ifndef CRYPTOGRAPHY_SSL_H__
#define CRYPTOGRAPHY_SSL_H__

#include "maxon/object.h"

namespace maxon
{

// stylecheck.naming=false
struct SSL;
struct SSL_CTX;
struct SSL_CIPHER;
struct SSL_METHOD;
struct X509;
struct ERR_STATE;
struct X509_STORE_CTX;
struct BIO;
struct X509_NAME_;
struct CRYPTO_THREADID;
// stylecheck.naming=true

typedef int (* sslctxsetverifycallback)(int, X509_STORE_CTX*);

//----------------------------------------------------------------------------------------
/// This interface maps all OpenSSL functions into a interface.
//----------------------------------------------------------------------------------------
class SSLInterface
{
	MAXON_INTERFACE_NONVIRTUAL(SSLInterface, MAXON_REFERENCE_NONE, "net.maxon.interface.ssl");

public:
	static MAXON_METHOD ERR_STATE* ERR_get_state();
	static MAXON_METHOD void ERR_clear_error();
	static MAXON_METHOD void ADD_thread_state();
	static MAXON_METHOD void SSL_load_error_strings();
	static MAXON_METHOD int SSL_library_init();
	static MAXON_METHOD SSL_CTX* SSL_CTX_new(const SSL_METHOD* meth);
//	static MAXON_METHOD const SSL_METHOD* SSLv23_client_method();
	static MAXON_METHOD const SSL_METHOD* TLSv1_method();		/* TLSv1.0 */
	static MAXON_METHOD const SSL_METHOD* TLSv1_1_method();		/* TLSv1.1 */
	static MAXON_METHOD const SSL_METHOD* TLSv1_2_method();		/* TLSv1.2 */
	static MAXON_METHOD const SSL_METHOD* SSLv3_method();		/* SSLv3 */
	static MAXON_METHOD const SSL_METHOD* SSLv2_method();		/* SSLv2 */
	static MAXON_METHOD const SSL_METHOD* SSLv23_method();	/* SSLv3 but can rollback to v2 */
	static MAXON_METHOD SSL* SSL_new(SSL_CTX* ctx);
	static MAXON_METHOD String ERR_get_error_string();
	static MAXON_METHOD unsigned long ERR_get_error();
	static MAXON_METHOD unsigned long ERR_peek_last_error();
	static MAXON_METHOD int SSL_set_fd(SSL* s, int fd);
	static MAXON_METHOD int SSL_set_tlsext_hostname(SSL* s, const char* serverName);
	static MAXON_METHOD int SSL_connect(SSL* ssl);
	static MAXON_METHOD int SSL_shutdown(SSL* s);
	static MAXON_METHOD void SSL_free(SSL* ssl);
	static MAXON_METHOD void SSL_CTX_free(SSL_CTX* ctx);
	static MAXON_METHOD int SSL_read(SSL* ssl, void* buf, int num);
	static MAXON_METHOD int SSL_write(SSL* ssl, const void* buf, int num);
	static MAXON_METHOD long SSL_get_verify_result(const SSL* ssl);
	static MAXON_METHOD int SSL_CTX_set_cipher_list(SSL_CTX* ctx, const char* str);
	static MAXON_METHOD int SSL_CTX_load_verify_locations(SSL_CTX* ctx, const char* CAfile, const char* CApath);
	static MAXON_METHOD int	SSL_CTX_use_PrivateKey_file(SSL_CTX* ctx, const char* file, int type);
	static MAXON_METHOD int	SSL_CTX_use_certificate_chain_file(SSL_CTX* ctx, const char* file);
	static MAXON_METHOD long SSL_CTX_ctrl(SSL_CTX* ctx, int cmd, long larg, void* parg);
	static MAXON_METHOD void SSL_CTX_set_verify(SSL_CTX* ctx, int mode, sslctxsetverifycallback callback);
	static MAXON_METHOD void SSL_set_connect_state(SSL* s);
	static MAXON_METHOD void SSL_set_accept_state(SSL* s);
	static MAXON_METHOD long BIO_ctrl(BIO* bp, int cmd, long larg, void* parg);
	static MAXON_METHOD BIO* SSL_get_rbio(const SSL* s);
	static MAXON_METHOD BIO* SSL_get_wbio(const SSL* s);
	static MAXON_METHOD int SSL_do_handshake(SSL* s);
	static MAXON_METHOD int	SSL_get_error(const SSL* s, int ret_code);
	static MAXON_METHOD const char* SSL_CIPHER_get_version(const SSL_CIPHER* current);
	static MAXON_METHOD const SSL_CIPHER* SSL_get_current_cipher(const SSL* s);
	static MAXON_METHOD void X509_free_(X509* a);
	static MAXON_METHOD X509* SSL_get_peer_certificate(const SSL* s);
	static MAXON_METHOD char* X509_NAME_oneline(X509_NAME_* a, char* buf, int size);
	static MAXON_METHOD int X509_NAME_get_text_by_NID(X509_NAME_* name, int nid, char* buf, int len);
	static MAXON_METHOD X509_NAME_* X509_get_subject_name(X509* a);
	static MAXON_METHOD X509_NAME_* X509_get_issuer_name(X509* a);
	static MAXON_METHOD Result<void> SSL_get_alt_names(X509* a, BaseArray<String>& alternativeNames);
	static MAXON_METHOD void SSL_set_read_ahead(SSL* s, int yes);
	static MAXON_METHOD int	SSL_pending(const SSL* s);
	static MAXON_METHOD int SSL_get_shutdown(const SSL* ssl);
	static MAXON_METHOD int SSL_CTX_use_PrivateKey_ASN1_RSA(SSL_CTX* ctx, unsigned char* d, long len);
};

#include "cryptography_ssl1.hxx"

#include "cryptography_ssl2.hxx"

}



#endif // CRYPTOGRAPHY_SSL_H__
