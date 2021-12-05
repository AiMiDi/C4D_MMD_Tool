
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* SSHInterface::PrivateGetCppName() { return nullptr; }

struct SSHInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	LIBSSH2_SESSION* (*_SSHInterface_libssh2_session_init) ();
	int (*_SSHInterface_libssh2_session_disconnect_ex) (LIBSSH2_SESSION* session, int reason, const char* description, const char* lang);
	int (*_SSHInterface_libssh2_session_free) (LIBSSH2_SESSION* session);
	void (*_SSHInterface_libssh2_session_set_blocking) (LIBSSH2_SESSION* session, int blocking);
	int (*_SSHInterface_libssh2_session_handshake) (LIBSSH2_SESSION* session, Int socket);
	const char* (*_SSHInterface_libssh2_hostkey_hash) (LIBSSH2_SESSION* session, int hash_type);
	const char* (*_SSHInterface_libssh2_userauth_list) (LIBSSH2_SESSION* session, const char* username, unsigned int username_len);
	int (*_SSHInterface_libssh2_userauth_password_ex) (LIBSSH2_SESSION* session, const char* username, unsigned int username_len, const char* password, unsigned int password_len, LIBSSH2_PASSWD_CHANGEREQ_FUNC passwd_change_cb);
	int (*_SSHInterface_libssh2_session_last_error) (LIBSSH2_SESSION* session, char** errmsg, int* errmsg_len, int want_buf);
	LIBSSH2_SFTP* (*_SSHInterface_libssh2_sftp_init) (LIBSSH2_SESSION* session);
	int (*_SSHInterface_libssh2_sftp_shutdown) (LIBSSH2_SFTP* sftp);
	LIBSSH2_SFTP_HANDLE* (*_SSHInterface_libssh2_sftp_open_ex) (LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len, unsigned long flags, long mode, int open_type);
	int (*_SSHInterface_libssh2_sftp_close_handle) (LIBSSH2_SFTP_HANDLE* handle);
	int (*_SSHInterface_libssh2_sftp_unlink_ex) (LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len);
	int (*_SSHInterface_libssh2_sftp_mkdir_ex) (LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, long mode);
	int (*_SSHInterface_libssh2_sftp_rmdir_ex) (LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len);
	int (*_SSHInterface_libssh2_sftp_fstat_ex) (LIBSSH2_SFTP_HANDLE* handle, LIBSSH2_SFTP_ATTRIBUTES* attrs, bool setstat);
	int (*_SSHInterface_libssh2_sftp_stat_ex) (LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, int stat_type, LIBSSH2_SFTP_ATTRIBUTES* attrs);
	Int (*_SSHInterface_libssh2_sftp_read) (LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen);
	Int (*_SSHInterface_libssh2_sftp_write) (LIBSSH2_SFTP_HANDLE* handle, const char* buffer, size_t count);
	int (*_SSHInterface_libssh2_sftp_readdir_ex) (LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen, char* longentry, size_t longentry_maxlen, LIBSSH2_SFTP_ATTRIBUTES* attrs);
	void (*_SSHInterface_libssh2_sftp_seek64) (LIBSSH2_SFTP_HANDLE* handle, UInt64 offset);
	template <typename IMPL> void Init()
	{
		_SSHInterface_libssh2_session_init = &IMPL::_SSHInterface_libssh2_session_init;
		_SSHInterface_libssh2_session_disconnect_ex = &IMPL::_SSHInterface_libssh2_session_disconnect_ex;
		_SSHInterface_libssh2_session_free = &IMPL::_SSHInterface_libssh2_session_free;
		_SSHInterface_libssh2_session_set_blocking = &IMPL::_SSHInterface_libssh2_session_set_blocking;
		_SSHInterface_libssh2_session_handshake = &IMPL::_SSHInterface_libssh2_session_handshake;
		_SSHInterface_libssh2_hostkey_hash = &IMPL::_SSHInterface_libssh2_hostkey_hash;
		_SSHInterface_libssh2_userauth_list = &IMPL::_SSHInterface_libssh2_userauth_list;
		_SSHInterface_libssh2_userauth_password_ex = &IMPL::_SSHInterface_libssh2_userauth_password_ex;
		_SSHInterface_libssh2_session_last_error = &IMPL::_SSHInterface_libssh2_session_last_error;
		_SSHInterface_libssh2_sftp_init = &IMPL::_SSHInterface_libssh2_sftp_init;
		_SSHInterface_libssh2_sftp_shutdown = &IMPL::_SSHInterface_libssh2_sftp_shutdown;
		_SSHInterface_libssh2_sftp_open_ex = &IMPL::_SSHInterface_libssh2_sftp_open_ex;
		_SSHInterface_libssh2_sftp_close_handle = &IMPL::_SSHInterface_libssh2_sftp_close_handle;
		_SSHInterface_libssh2_sftp_unlink_ex = &IMPL::_SSHInterface_libssh2_sftp_unlink_ex;
		_SSHInterface_libssh2_sftp_mkdir_ex = &IMPL::_SSHInterface_libssh2_sftp_mkdir_ex;
		_SSHInterface_libssh2_sftp_rmdir_ex = &IMPL::_SSHInterface_libssh2_sftp_rmdir_ex;
		_SSHInterface_libssh2_sftp_fstat_ex = &IMPL::_SSHInterface_libssh2_sftp_fstat_ex;
		_SSHInterface_libssh2_sftp_stat_ex = &IMPL::_SSHInterface_libssh2_sftp_stat_ex;
		_SSHInterface_libssh2_sftp_read = &IMPL::_SSHInterface_libssh2_sftp_read;
		_SSHInterface_libssh2_sftp_write = &IMPL::_SSHInterface_libssh2_sftp_write;
		_SSHInterface_libssh2_sftp_readdir_ex = &IMPL::_SSHInterface_libssh2_sftp_readdir_ex;
		_SSHInterface_libssh2_sftp_seek64 = &IMPL::_SSHInterface_libssh2_sftp_seek64;
	}
};

struct SSHInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static LIBSSH2_SESSION* _SSHInterface_libssh2_session_init() { return C::libssh2_session_init(); }
		static int _SSHInterface_libssh2_session_disconnect_ex(LIBSSH2_SESSION* session, int reason, const char* description, const char* lang) { return C::libssh2_session_disconnect_ex(session, reason, description, lang); }
		static int _SSHInterface_libssh2_session_free(LIBSSH2_SESSION* session) { return C::libssh2_session_free(session); }
		static void _SSHInterface_libssh2_session_set_blocking(LIBSSH2_SESSION* session, int blocking) { return C::libssh2_session_set_blocking(session, blocking); }
		static int _SSHInterface_libssh2_session_handshake(LIBSSH2_SESSION* session, Int socket) { return C::libssh2_session_handshake(session, socket); }
		static const char* _SSHInterface_libssh2_hostkey_hash(LIBSSH2_SESSION* session, int hash_type) { return C::libssh2_hostkey_hash(session, hash_type); }
		static const char* _SSHInterface_libssh2_userauth_list(LIBSSH2_SESSION* session, const char* username, unsigned int username_len) { return C::libssh2_userauth_list(session, username, std::forward<unsigned int>(username_len)); }
		static int _SSHInterface_libssh2_userauth_password_ex(LIBSSH2_SESSION* session, const char* username, unsigned int username_len, const char* password, unsigned int password_len, LIBSSH2_PASSWD_CHANGEREQ_FUNC passwd_change_cb) { return C::libssh2_userauth_password_ex(session, username, std::forward<unsigned int>(username_len), password, std::forward<unsigned int>(password_len), passwd_change_cb); }
		static int _SSHInterface_libssh2_session_last_error(LIBSSH2_SESSION* session, char** errmsg, int* errmsg_len, int want_buf) { return C::libssh2_session_last_error(session, errmsg, errmsg_len, want_buf); }
		static LIBSSH2_SFTP* _SSHInterface_libssh2_sftp_init(LIBSSH2_SESSION* session) { return C::libssh2_sftp_init(session); }
		static int _SSHInterface_libssh2_sftp_shutdown(LIBSSH2_SFTP* sftp) { return C::libssh2_sftp_shutdown(sftp); }
		static LIBSSH2_SFTP_HANDLE* _SSHInterface_libssh2_sftp_open_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len, unsigned long flags, long mode, int open_type) { return C::libssh2_sftp_open_ex(sftp, filename, std::forward<unsigned int>(filename_len), std::forward<unsigned long>(flags), mode, open_type); }
		static int _SSHInterface_libssh2_sftp_close_handle(LIBSSH2_SFTP_HANDLE* handle) { return C::libssh2_sftp_close_handle(handle); }
		static int _SSHInterface_libssh2_sftp_unlink_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len) { return C::libssh2_sftp_unlink_ex(sftp, filename, std::forward<unsigned int>(filename_len)); }
		static int _SSHInterface_libssh2_sftp_mkdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, long mode) { return C::libssh2_sftp_mkdir_ex(sftp, path, std::forward<unsigned int>(path_len), mode); }
		static int _SSHInterface_libssh2_sftp_rmdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len) { return C::libssh2_sftp_rmdir_ex(sftp, path, std::forward<unsigned int>(path_len)); }
		static int _SSHInterface_libssh2_sftp_fstat_ex(LIBSSH2_SFTP_HANDLE* handle, LIBSSH2_SFTP_ATTRIBUTES* attrs, bool setstat) { return C::libssh2_sftp_fstat_ex(handle, attrs, setstat); }
		static int _SSHInterface_libssh2_sftp_stat_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, int stat_type, LIBSSH2_SFTP_ATTRIBUTES* attrs) { return C::libssh2_sftp_stat_ex(sftp, path, std::forward<unsigned int>(path_len), stat_type, attrs); }
		static Int _SSHInterface_libssh2_sftp_read(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen) { return C::libssh2_sftp_read(handle, buffer, std::forward<size_t>(buffer_maxlen)); }
		static Int _SSHInterface_libssh2_sftp_write(LIBSSH2_SFTP_HANDLE* handle, const char* buffer, size_t count) { return C::libssh2_sftp_write(handle, buffer, std::forward<size_t>(count)); }
		static int _SSHInterface_libssh2_sftp_readdir_ex(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen, char* longentry, size_t longentry_maxlen, LIBSSH2_SFTP_ATTRIBUTES* attrs) { return C::libssh2_sftp_readdir_ex(handle, buffer, std::forward<size_t>(buffer_maxlen), longentry, std::forward<size_t>(longentry_maxlen), attrs); }
		static void _SSHInterface_libssh2_sftp_seek64(LIBSSH2_SFTP_HANDLE* handle, UInt64 offset) { return C::libssh2_sftp_seek64(handle, offset); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_session_init() -> LIBSSH2_SESSION*
{
	return MTable::_instance._SSHInterface_libssh2_session_init();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_session_disconnect_ex(LIBSSH2_SESSION* session, int reason, const char* description, const char* lang) -> int
{
	return MTable::_instance._SSHInterface_libssh2_session_disconnect_ex(session, reason, description, lang);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_session_free(LIBSSH2_SESSION* session) -> int
{
	return MTable::_instance._SSHInterface_libssh2_session_free(session);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_session_set_blocking(LIBSSH2_SESSION* session, int blocking) -> void
{
	return MTable::_instance._SSHInterface_libssh2_session_set_blocking(session, blocking);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_session_handshake(LIBSSH2_SESSION* session, Int socket) -> int
{
	return MTable::_instance._SSHInterface_libssh2_session_handshake(session, socket);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_hostkey_hash(LIBSSH2_SESSION* session, int hash_type) -> const char*
{
	return MTable::_instance._SSHInterface_libssh2_hostkey_hash(session, hash_type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_userauth_list(LIBSSH2_SESSION* session, const char* username, unsigned int username_len) -> const char*
{
	return MTable::_instance._SSHInterface_libssh2_userauth_list(session, username, std::forward<unsigned int>(username_len));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_userauth_password_ex(LIBSSH2_SESSION* session, const char* username, unsigned int username_len, const char* password, unsigned int password_len, LIBSSH2_PASSWD_CHANGEREQ_FUNC passwd_change_cb) -> int
{
	return MTable::_instance._SSHInterface_libssh2_userauth_password_ex(session, username, std::forward<unsigned int>(username_len), password, std::forward<unsigned int>(password_len), passwd_change_cb);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_session_last_error(LIBSSH2_SESSION* session, char** errmsg, int* errmsg_len, int want_buf) -> int
{
	return MTable::_instance._SSHInterface_libssh2_session_last_error(session, errmsg, errmsg_len, want_buf);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_init(LIBSSH2_SESSION* session) -> LIBSSH2_SFTP*
{
	return MTable::_instance._SSHInterface_libssh2_sftp_init(session);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_shutdown(LIBSSH2_SFTP* sftp) -> int
{
	return MTable::_instance._SSHInterface_libssh2_sftp_shutdown(sftp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_open_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len, unsigned long flags, long mode, int open_type) -> LIBSSH2_SFTP_HANDLE*
{
	return MTable::_instance._SSHInterface_libssh2_sftp_open_ex(sftp, filename, std::forward<unsigned int>(filename_len), std::forward<unsigned long>(flags), mode, open_type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_close_handle(LIBSSH2_SFTP_HANDLE* handle) -> int
{
	return MTable::_instance._SSHInterface_libssh2_sftp_close_handle(handle);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_unlink_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len) -> int
{
	return MTable::_instance._SSHInterface_libssh2_sftp_unlink_ex(sftp, filename, std::forward<unsigned int>(filename_len));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_mkdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, long mode) -> int
{
	return MTable::_instance._SSHInterface_libssh2_sftp_mkdir_ex(sftp, path, std::forward<unsigned int>(path_len), mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_rmdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len) -> int
{
	return MTable::_instance._SSHInterface_libssh2_sftp_rmdir_ex(sftp, path, std::forward<unsigned int>(path_len));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_fstat_ex(LIBSSH2_SFTP_HANDLE* handle, LIBSSH2_SFTP_ATTRIBUTES* attrs, bool setstat) -> int
{
	return MTable::_instance._SSHInterface_libssh2_sftp_fstat_ex(handle, attrs, setstat);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_stat_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, int stat_type, LIBSSH2_SFTP_ATTRIBUTES* attrs) -> int
{
	return MTable::_instance._SSHInterface_libssh2_sftp_stat_ex(sftp, path, std::forward<unsigned int>(path_len), stat_type, attrs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_read(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen) -> Int
{
	return MTable::_instance._SSHInterface_libssh2_sftp_read(handle, buffer, std::forward<size_t>(buffer_maxlen));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_write(LIBSSH2_SFTP_HANDLE* handle, const char* buffer, size_t count) -> Int
{
	return MTable::_instance._SSHInterface_libssh2_sftp_write(handle, buffer, std::forward<size_t>(count));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_readdir_ex(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen, char* longentry, size_t longentry_maxlen, LIBSSH2_SFTP_ATTRIBUTES* attrs) -> int
{
	return MTable::_instance._SSHInterface_libssh2_sftp_readdir_ex(handle, buffer, std::forward<size_t>(buffer_maxlen), longentry, std::forward<size_t>(longentry_maxlen), attrs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_seek64(LIBSSH2_SFTP_HANDLE* handle, UInt64 offset) -> void
{
	return MTable::_instance._SSHInterface_libssh2_sftp_seek64(handle, offset);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_SSHInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_SSHInterface() { new (s_ui_maxon_SSHInterface) maxon::EntityUse(SSHInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cryptography_ssh.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_SSHInterface(SSHInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/cryptography_ssh.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

