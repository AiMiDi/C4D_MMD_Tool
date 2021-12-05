#ifndef CRYPTOGRAPHY_SSH_H__
#define CRYPTOGRAPHY_SSH_H__

#include "maxon/object.h"

struct _LIBSSH2_SESSION;

typedef struct _LIBSSH2_SESSION                     LIBSSH2_SESSION;
typedef struct _LIBSSH2_CHANNEL                     LIBSSH2_CHANNEL;
typedef struct _LIBSSH2_LISTENER                    LIBSSH2_LISTENER;
typedef struct _LIBSSH2_KNOWNHOSTS                  LIBSSH2_KNOWNHOSTS;
typedef struct _LIBSSH2_AGENT                       LIBSSH2_AGENT;

struct _LIBSSH2_SFTP;
typedef struct _LIBSSH2_SFTP                LIBSSH2_SFTP;
typedef struct _LIBSSH2_SFTP_HANDLE         LIBSSH2_SFTP_HANDLE;
typedef struct _LIBSSH2_SFTP_ATTRIBUTES     LIBSSH2_SFTP_ATTRIBUTES;
typedef struct _LIBSSH2_SFTP_STATVFS        LIBSSH2_SFTP_STATVFS;

namespace maxon
{

using LIBSSH2_PASSWD_CHANGEREQ_FUNC = void(*)(LIBSSH2_SESSION *session, char **newpw, int *newpw_len, void **abstract);

// stylecheck.naming=false

//----------------------------------------------------------------------------------------
/// This interface maps all libssh2 functions into a interface.
//----------------------------------------------------------------------------------------
class SSHInterface
{
	MAXON_INTERFACE_NONVIRTUAL(SSHInterface, MAXON_REFERENCE_NONE, "net.maxon.interface.ssh");
public:
	static MAXON_METHOD LIBSSH2_SESSION* libssh2_session_init();
	static MAXON_METHOD int libssh2_session_disconnect_ex(LIBSSH2_SESSION* session, int reason, const char* description, const char* lang);
	static MAXON_METHOD int libssh2_session_free(LIBSSH2_SESSION* session);
	static MAXON_METHOD void libssh2_session_set_blocking(LIBSSH2_SESSION* session, int blocking);
	static MAXON_METHOD int libssh2_session_handshake(LIBSSH2_SESSION* session, Int socket);
	static MAXON_METHOD const char* libssh2_hostkey_hash(LIBSSH2_SESSION* session, int hash_type);
	static MAXON_METHOD const char* libssh2_userauth_list(LIBSSH2_SESSION* session, const char* username, unsigned int username_len);
	static MAXON_METHOD int libssh2_userauth_password_ex(LIBSSH2_SESSION* session, const char* username, unsigned int username_len, const char* password, unsigned int password_len, LIBSSH2_PASSWD_CHANGEREQ_FUNC passwd_change_cb);
	static MAXON_METHOD int libssh2_session_last_error(LIBSSH2_SESSION* session, char** errmsg, int* errmsg_len, int want_buf);

	static MAXON_METHOD LIBSSH2_SFTP* libssh2_sftp_init(LIBSSH2_SESSION* session);
	static MAXON_METHOD int libssh2_sftp_shutdown(LIBSSH2_SFTP* sftp);
	static MAXON_METHOD LIBSSH2_SFTP_HANDLE* libssh2_sftp_open_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len, unsigned long flags, long mode, int open_type); // use -1 for mode if the file attributes should not be changed
	static int libssh2_sftp_close(LIBSSH2_SFTP_HANDLE* handle) { return libssh2_sftp_close_handle(handle); }
	static int libssh2_sftp_closedir(LIBSSH2_SFTP_HANDLE* handle) { return libssh2_sftp_close_handle(handle); }
	static MAXON_METHOD int libssh2_sftp_close_handle(LIBSSH2_SFTP_HANDLE* handle);
	static MAXON_METHOD int libssh2_sftp_unlink_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len);
	static MAXON_METHOD int libssh2_sftp_mkdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, long mode);
	static MAXON_METHOD int libssh2_sftp_rmdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len);
	static MAXON_METHOD int libssh2_sftp_fstat_ex(LIBSSH2_SFTP_HANDLE* handle, LIBSSH2_SFTP_ATTRIBUTES* attrs, bool setstat);
	static MAXON_METHOD int libssh2_sftp_stat_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, int stat_type, LIBSSH2_SFTP_ATTRIBUTES* attrs);
	static MAXON_METHOD Int libssh2_sftp_read(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen);
	static MAXON_METHOD Int libssh2_sftp_write(LIBSSH2_SFTP_HANDLE* handle, const char* buffer, size_t count);
	static MAXON_METHOD int libssh2_sftp_readdir_ex(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen, char* longentry, size_t longentry_maxlen, LIBSSH2_SFTP_ATTRIBUTES* attrs);
	static MAXON_METHOD void libssh2_sftp_seek64(LIBSSH2_SFTP_HANDLE* handle, UInt64 offset);
};

#include "cryptography_ssh1.hxx"

#include "cryptography_ssh2.hxx"

}

#endif // CRYPTOGRAPHY_SSH_H__
