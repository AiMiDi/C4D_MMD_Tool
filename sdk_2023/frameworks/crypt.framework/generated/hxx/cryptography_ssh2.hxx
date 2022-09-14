
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
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_session_init, libssh2_session_init, MAXON_EXPAND_VA_ARGS, (LIBSSH2_SESSION*));
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_session_disconnect_ex, libssh2_session_disconnect_ex, MAXON_EXPAND_VA_ARGS, (int), LIBSSH2_SESSION* session, int reason, const char* description, const char* lang);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_session_free, libssh2_session_free, MAXON_EXPAND_VA_ARGS, (int), LIBSSH2_SESSION* session);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_session_set_blocking, libssh2_session_set_blocking, MAXON_EXPAND_VA_ARGS, (void), LIBSSH2_SESSION* session, int blocking);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_session_handshake, libssh2_session_handshake, MAXON_EXPAND_VA_ARGS, (int), LIBSSH2_SESSION* session, Int socket);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_hostkey_hash, libssh2_hostkey_hash, MAXON_EXPAND_VA_ARGS, (const char*), LIBSSH2_SESSION* session, int hash_type);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_userauth_list, libssh2_userauth_list, MAXON_EXPAND_VA_ARGS, (const char*), LIBSSH2_SESSION* session, const char* username, unsigned int username_len);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_userauth_password_ex, libssh2_userauth_password_ex, MAXON_EXPAND_VA_ARGS, (int), LIBSSH2_SESSION* session, const char* username, unsigned int username_len, const char* password, unsigned int password_len, LIBSSH2_PASSWD_CHANGEREQ_FUNC passwd_change_cb);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_session_last_error, libssh2_session_last_error, MAXON_EXPAND_VA_ARGS, (int), LIBSSH2_SESSION* session, char** errmsg, int* errmsg_len, int want_buf);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_sftp_init, libssh2_sftp_init, MAXON_EXPAND_VA_ARGS, (LIBSSH2_SFTP*), LIBSSH2_SESSION* session);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_sftp_shutdown, libssh2_sftp_shutdown, MAXON_EXPAND_VA_ARGS, (int), LIBSSH2_SFTP* sftp);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_sftp_open_ex, libssh2_sftp_open_ex, MAXON_EXPAND_VA_ARGS, (LIBSSH2_SFTP_HANDLE*), LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len, unsigned long flags, long mode, int open_type);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_sftp_close_handle, libssh2_sftp_close_handle, MAXON_EXPAND_VA_ARGS, (int), LIBSSH2_SFTP_HANDLE* handle);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_sftp_unlink_ex, libssh2_sftp_unlink_ex, MAXON_EXPAND_VA_ARGS, (int), LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_sftp_mkdir_ex, libssh2_sftp_mkdir_ex, MAXON_EXPAND_VA_ARGS, (int), LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, long mode);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_sftp_rmdir_ex, libssh2_sftp_rmdir_ex, MAXON_EXPAND_VA_ARGS, (int), LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_sftp_fstat_ex, libssh2_sftp_fstat_ex, MAXON_EXPAND_VA_ARGS, (int), LIBSSH2_SFTP_HANDLE* handle, LIBSSH2_SFTP_ATTRIBUTES* attrs, bool setstat);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_sftp_stat_ex, libssh2_sftp_stat_ex, MAXON_EXPAND_VA_ARGS, (int), LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, int stat_type, LIBSSH2_SFTP_ATTRIBUTES* attrs);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_sftp_read, libssh2_sftp_read, MAXON_EXPAND_VA_ARGS, (Int), LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_sftp_write, libssh2_sftp_write, MAXON_EXPAND_VA_ARGS, (Int), LIBSSH2_SFTP_HANDLE* handle, const char* buffer, size_t count);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_sftp_readdir_ex, libssh2_sftp_readdir_ex, MAXON_EXPAND_VA_ARGS, (int), LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen, char* longentry, size_t longentry_maxlen, LIBSSH2_SFTP_ATTRIBUTES* attrs);
	PRIVATE_MAXON_SF_POINTER(SSHInterface_libssh2_sftp_seek64, libssh2_sftp_seek64, MAXON_EXPAND_VA_ARGS, (void), LIBSSH2_SFTP_HANDLE* handle, UInt64 offset);
	template <typename IMPL> void Init()
	{
		SSHInterface_libssh2_session_init = SSHInterface_libssh2_session_init_GetPtr<IMPL>(true);
		SSHInterface_libssh2_session_disconnect_ex = SSHInterface_libssh2_session_disconnect_ex_GetPtr<IMPL>(true);
		SSHInterface_libssh2_session_free = SSHInterface_libssh2_session_free_GetPtr<IMPL>(true);
		SSHInterface_libssh2_session_set_blocking = SSHInterface_libssh2_session_set_blocking_GetPtr<IMPL>(true);
		SSHInterface_libssh2_session_handshake = SSHInterface_libssh2_session_handshake_GetPtr<IMPL>(true);
		SSHInterface_libssh2_hostkey_hash = SSHInterface_libssh2_hostkey_hash_GetPtr<IMPL>(true);
		SSHInterface_libssh2_userauth_list = SSHInterface_libssh2_userauth_list_GetPtr<IMPL>(true);
		SSHInterface_libssh2_userauth_password_ex = SSHInterface_libssh2_userauth_password_ex_GetPtr<IMPL>(true);
		SSHInterface_libssh2_session_last_error = SSHInterface_libssh2_session_last_error_GetPtr<IMPL>(true);
		SSHInterface_libssh2_sftp_init = SSHInterface_libssh2_sftp_init_GetPtr<IMPL>(true);
		SSHInterface_libssh2_sftp_shutdown = SSHInterface_libssh2_sftp_shutdown_GetPtr<IMPL>(true);
		SSHInterface_libssh2_sftp_open_ex = SSHInterface_libssh2_sftp_open_ex_GetPtr<IMPL>(true);
		SSHInterface_libssh2_sftp_close_handle = SSHInterface_libssh2_sftp_close_handle_GetPtr<IMPL>(true);
		SSHInterface_libssh2_sftp_unlink_ex = SSHInterface_libssh2_sftp_unlink_ex_GetPtr<IMPL>(true);
		SSHInterface_libssh2_sftp_mkdir_ex = SSHInterface_libssh2_sftp_mkdir_ex_GetPtr<IMPL>(true);
		SSHInterface_libssh2_sftp_rmdir_ex = SSHInterface_libssh2_sftp_rmdir_ex_GetPtr<IMPL>(true);
		SSHInterface_libssh2_sftp_fstat_ex = SSHInterface_libssh2_sftp_fstat_ex_GetPtr<IMPL>(true);
		SSHInterface_libssh2_sftp_stat_ex = SSHInterface_libssh2_sftp_stat_ex_GetPtr<IMPL>(true);
		SSHInterface_libssh2_sftp_read = SSHInterface_libssh2_sftp_read_GetPtr<IMPL>(true);
		SSHInterface_libssh2_sftp_write = SSHInterface_libssh2_sftp_write_GetPtr<IMPL>(true);
		SSHInterface_libssh2_sftp_readdir_ex = SSHInterface_libssh2_sftp_readdir_ex_GetPtr<IMPL>(true);
		SSHInterface_libssh2_sftp_seek64 = SSHInterface_libssh2_sftp_seek64_GetPtr<IMPL>(true);
	}
};

struct SSHInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static LIBSSH2_SESSION* SSHInterface_libssh2_session_init() { return C::libssh2_session_init(); }
		static int SSHInterface_libssh2_session_disconnect_ex(LIBSSH2_SESSION* session, int reason, const char* description, const char* lang) { return C::libssh2_session_disconnect_ex(session, reason, description, lang); }
		static int SSHInterface_libssh2_session_free(LIBSSH2_SESSION* session) { return C::libssh2_session_free(session); }
		static void SSHInterface_libssh2_session_set_blocking(LIBSSH2_SESSION* session, int blocking) { return C::libssh2_session_set_blocking(session, blocking); }
		static int SSHInterface_libssh2_session_handshake(LIBSSH2_SESSION* session, Int socket) { return C::libssh2_session_handshake(session, socket); }
		static const char* SSHInterface_libssh2_hostkey_hash(LIBSSH2_SESSION* session, int hash_type) { return C::libssh2_hostkey_hash(session, hash_type); }
		static const char* SSHInterface_libssh2_userauth_list(LIBSSH2_SESSION* session, const char* username, unsigned int username_len) { return C::libssh2_userauth_list(session, username, std::forward<unsigned int>(username_len)); }
		static int SSHInterface_libssh2_userauth_password_ex(LIBSSH2_SESSION* session, const char* username, unsigned int username_len, const char* password, unsigned int password_len, LIBSSH2_PASSWD_CHANGEREQ_FUNC passwd_change_cb) { return C::libssh2_userauth_password_ex(session, username, std::forward<unsigned int>(username_len), password, std::forward<unsigned int>(password_len), passwd_change_cb); }
		static int SSHInterface_libssh2_session_last_error(LIBSSH2_SESSION* session, char** errmsg, int* errmsg_len, int want_buf) { return C::libssh2_session_last_error(session, errmsg, errmsg_len, want_buf); }
		static LIBSSH2_SFTP* SSHInterface_libssh2_sftp_init(LIBSSH2_SESSION* session) { return C::libssh2_sftp_init(session); }
		static int SSHInterface_libssh2_sftp_shutdown(LIBSSH2_SFTP* sftp) { return C::libssh2_sftp_shutdown(sftp); }
		static LIBSSH2_SFTP_HANDLE* SSHInterface_libssh2_sftp_open_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len, unsigned long flags, long mode, int open_type) { return C::libssh2_sftp_open_ex(sftp, filename, std::forward<unsigned int>(filename_len), std::forward<unsigned long>(flags), mode, open_type); }
		static int SSHInterface_libssh2_sftp_close_handle(LIBSSH2_SFTP_HANDLE* handle) { return C::libssh2_sftp_close_handle(handle); }
		static int SSHInterface_libssh2_sftp_unlink_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len) { return C::libssh2_sftp_unlink_ex(sftp, filename, std::forward<unsigned int>(filename_len)); }
		static int SSHInterface_libssh2_sftp_mkdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, long mode) { return C::libssh2_sftp_mkdir_ex(sftp, path, std::forward<unsigned int>(path_len), mode); }
		static int SSHInterface_libssh2_sftp_rmdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len) { return C::libssh2_sftp_rmdir_ex(sftp, path, std::forward<unsigned int>(path_len)); }
		static int SSHInterface_libssh2_sftp_fstat_ex(LIBSSH2_SFTP_HANDLE* handle, LIBSSH2_SFTP_ATTRIBUTES* attrs, bool setstat) { return C::libssh2_sftp_fstat_ex(handle, attrs, setstat); }
		static int SSHInterface_libssh2_sftp_stat_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, int stat_type, LIBSSH2_SFTP_ATTRIBUTES* attrs) { return C::libssh2_sftp_stat_ex(sftp, path, std::forward<unsigned int>(path_len), stat_type, attrs); }
		static Int SSHInterface_libssh2_sftp_read(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen) { return C::libssh2_sftp_read(handle, buffer, std::forward<size_t>(buffer_maxlen)); }
		static Int SSHInterface_libssh2_sftp_write(LIBSSH2_SFTP_HANDLE* handle, const char* buffer, size_t count) { return C::libssh2_sftp_write(handle, buffer, std::forward<size_t>(count)); }
		static int SSHInterface_libssh2_sftp_readdir_ex(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen, char* longentry, size_t longentry_maxlen, LIBSSH2_SFTP_ATTRIBUTES* attrs) { return C::libssh2_sftp_readdir_ex(handle, buffer, std::forward<size_t>(buffer_maxlen), longentry, std::forward<size_t>(longentry_maxlen), attrs); }
		static void SSHInterface_libssh2_sftp_seek64(LIBSSH2_SFTP_HANDLE* handle, UInt64 offset) { return C::libssh2_sftp_seek64(handle, offset); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_session_init() -> LIBSSH2_SESSION*
{
	return MTable::_instance.SSHInterface_libssh2_session_init();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_session_disconnect_ex(LIBSSH2_SESSION* session, int reason, const char* description, const char* lang) -> int
{
	return MTable::_instance.SSHInterface_libssh2_session_disconnect_ex(session, reason, description, lang);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_session_free(LIBSSH2_SESSION* session) -> int
{
	return MTable::_instance.SSHInterface_libssh2_session_free(session);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_session_set_blocking(LIBSSH2_SESSION* session, int blocking) -> void
{
	return MTable::_instance.SSHInterface_libssh2_session_set_blocking(session, blocking);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_session_handshake(LIBSSH2_SESSION* session, Int socket) -> int
{
	return MTable::_instance.SSHInterface_libssh2_session_handshake(session, socket);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_hostkey_hash(LIBSSH2_SESSION* session, int hash_type) -> const char*
{
	return MTable::_instance.SSHInterface_libssh2_hostkey_hash(session, hash_type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_userauth_list(LIBSSH2_SESSION* session, const char* username, unsigned int username_len) -> const char*
{
	return MTable::_instance.SSHInterface_libssh2_userauth_list(session, username, std::forward<unsigned int>(username_len));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_userauth_password_ex(LIBSSH2_SESSION* session, const char* username, unsigned int username_len, const char* password, unsigned int password_len, LIBSSH2_PASSWD_CHANGEREQ_FUNC passwd_change_cb) -> int
{
	return MTable::_instance.SSHInterface_libssh2_userauth_password_ex(session, username, std::forward<unsigned int>(username_len), password, std::forward<unsigned int>(password_len), passwd_change_cb);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_session_last_error(LIBSSH2_SESSION* session, char** errmsg, int* errmsg_len, int want_buf) -> int
{
	return MTable::_instance.SSHInterface_libssh2_session_last_error(session, errmsg, errmsg_len, want_buf);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_init(LIBSSH2_SESSION* session) -> LIBSSH2_SFTP*
{
	return MTable::_instance.SSHInterface_libssh2_sftp_init(session);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_shutdown(LIBSSH2_SFTP* sftp) -> int
{
	return MTable::_instance.SSHInterface_libssh2_sftp_shutdown(sftp);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_open_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len, unsigned long flags, long mode, int open_type) -> LIBSSH2_SFTP_HANDLE*
{
	return MTable::_instance.SSHInterface_libssh2_sftp_open_ex(sftp, filename, std::forward<unsigned int>(filename_len), std::forward<unsigned long>(flags), mode, open_type);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_close_handle(LIBSSH2_SFTP_HANDLE* handle) -> int
{
	return MTable::_instance.SSHInterface_libssh2_sftp_close_handle(handle);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_unlink_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len) -> int
{
	return MTable::_instance.SSHInterface_libssh2_sftp_unlink_ex(sftp, filename, std::forward<unsigned int>(filename_len));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_mkdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, long mode) -> int
{
	return MTable::_instance.SSHInterface_libssh2_sftp_mkdir_ex(sftp, path, std::forward<unsigned int>(path_len), mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_rmdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len) -> int
{
	return MTable::_instance.SSHInterface_libssh2_sftp_rmdir_ex(sftp, path, std::forward<unsigned int>(path_len));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_fstat_ex(LIBSSH2_SFTP_HANDLE* handle, LIBSSH2_SFTP_ATTRIBUTES* attrs, bool setstat) -> int
{
	return MTable::_instance.SSHInterface_libssh2_sftp_fstat_ex(handle, attrs, setstat);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_stat_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, int stat_type, LIBSSH2_SFTP_ATTRIBUTES* attrs) -> int
{
	return MTable::_instance.SSHInterface_libssh2_sftp_stat_ex(sftp, path, std::forward<unsigned int>(path_len), stat_type, attrs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_read(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen) -> Int
{
	return MTable::_instance.SSHInterface_libssh2_sftp_read(handle, buffer, std::forward<size_t>(buffer_maxlen));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_write(LIBSSH2_SFTP_HANDLE* handle, const char* buffer, size_t count) -> Int
{
	return MTable::_instance.SSHInterface_libssh2_sftp_write(handle, buffer, std::forward<size_t>(count));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_readdir_ex(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen, char* longentry, size_t longentry_maxlen, LIBSSH2_SFTP_ATTRIBUTES* attrs) -> int
{
	return MTable::_instance.SSHInterface_libssh2_sftp_readdir_ex(handle, buffer, std::forward<size_t>(buffer_maxlen), longentry, std::forward<size_t>(longentry_maxlen), attrs);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto SSHInterface::libssh2_sftp_seek64(LIBSSH2_SFTP_HANDLE* handle, UInt64 offset) -> void
{
	return MTable::_instance.SSHInterface_libssh2_sftp_seek64(handle, offset);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_cryptography_ssh)
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

