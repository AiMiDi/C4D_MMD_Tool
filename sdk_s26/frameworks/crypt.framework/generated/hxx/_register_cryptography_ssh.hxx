#if 1
namespace maxon
{
	const maxon::Char* const SSHInterface::MTable::_ids = 
		"libssh2_session_init@8e3013a72449db69\0" // LIBSSH2_SESSION* libssh2_session_init()
		"libssh2_session_disconnect_ex@dc7eb14a19f64a45\0" // int libssh2_session_disconnect_ex(LIBSSH2_SESSION* session, int reason, const char* description, const char* lang)
		"libssh2_session_free@314e9108f57f1cee\0" // int libssh2_session_free(LIBSSH2_SESSION* session)
		"libssh2_session_set_blocking@77847bdf69ad2e4c\0" // void libssh2_session_set_blocking(LIBSSH2_SESSION* session, int blocking)
		"libssh2_session_handshake@87a9bd93430d02f9\0" // int libssh2_session_handshake(LIBSSH2_SESSION* session, Int socket)
		"libssh2_hostkey_hash@48ce33f4f2607ec1\0" // const char* libssh2_hostkey_hash(LIBSSH2_SESSION* session, int hash_type)
		"libssh2_userauth_list@354944e355276f4b\0" // const char* libssh2_userauth_list(LIBSSH2_SESSION* session, const char* username, unsigned int username_len)
		"libssh2_userauth_password_ex@f7f5fdf6cd965e6c\0" // int libssh2_userauth_password_ex(LIBSSH2_SESSION* session, const char* username, unsigned int username_len, const char* password, unsigned int password_len, LIBSSH2_PASSWD_CHANGEREQ_FUNC passwd_change_cb)
		"libssh2_session_last_error@65b2c8033babe6f2\0" // int libssh2_session_last_error(LIBSSH2_SESSION* session, char** errmsg, int* errmsg_len, int want_buf)
		"libssh2_sftp_init@d49783dadb752c7a\0" // LIBSSH2_SFTP* libssh2_sftp_init(LIBSSH2_SESSION* session)
		"libssh2_sftp_shutdown@6732f7a4403c0ab1\0" // int libssh2_sftp_shutdown(LIBSSH2_SFTP* sftp)
		"libssh2_sftp_open_ex@c42e2f350704f239\0" // LIBSSH2_SFTP_HANDLE* libssh2_sftp_open_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len, unsigned long flags, long mode, int open_type)
		"libssh2_sftp_close_handle@c539ffd06ff16bfe\0" // int libssh2_sftp_close_handle(LIBSSH2_SFTP_HANDLE* handle)
		"libssh2_sftp_unlink_ex@829713e8c064ebba\0" // int libssh2_sftp_unlink_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len)
		"libssh2_sftp_mkdir_ex@10c046f9e1006cda\0" // int libssh2_sftp_mkdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, long mode)
		"libssh2_sftp_rmdir_ex@829713e8c064ebba\0" // int libssh2_sftp_rmdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len)
		"libssh2_sftp_fstat_ex@ac2aa5ee34efd8e5\0" // int libssh2_sftp_fstat_ex(LIBSSH2_SFTP_HANDLE* handle, LIBSSH2_SFTP_ATTRIBUTES* attrs, bool setstat)
		"libssh2_sftp_stat_ex@cd1e12beb85b90d4\0" // int libssh2_sftp_stat_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, int stat_type, LIBSSH2_SFTP_ATTRIBUTES* attrs)
		"libssh2_sftp_read@4587a16ca1a3e658\0" // Int libssh2_sftp_read(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen)
		"libssh2_sftp_write@cf1e7013cca2c7e7\0" // Int libssh2_sftp_write(LIBSSH2_SFTP_HANDLE* handle, const char* buffer, size_t count)
		"libssh2_sftp_readdir_ex@6108f4f76f0bf449\0" // int libssh2_sftp_readdir_ex(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen, char* longentry, size_t longentry_maxlen, LIBSSH2_SFTP_ATTRIBUTES* attrs)
		"libssh2_sftp_seek64@d30ca825efa074c1\0" // void libssh2_sftp_seek64(LIBSSH2_SFTP_HANDLE* handle, UInt64 offset)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class SSHInterface::Hxx2::Unresolved : public SSHInterface
	{
	public:
		static const Unresolved* Get(const SSHInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(SSHInterface* o) { return (Unresolved*) o; }
		static LIBSSH2_SESSION* libssh2_session_init() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_session_init(); return nullptr;}
		static int libssh2_session_disconnect_ex(LIBSSH2_SESSION* session, int reason, const char* description, const char* lang) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_session_disconnect_ex(session, reason, description, lang); return 0;}
		static int libssh2_session_free(LIBSSH2_SESSION* session) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_session_free(session); return 0;}
		static void libssh2_session_set_blocking(LIBSSH2_SESSION* session, int blocking) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_session_set_blocking(session, blocking); return maxon::PrivateLogNullptrError();}
		static int libssh2_session_handshake(LIBSSH2_SESSION* session, Int socket) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_session_handshake(session, socket); return 0;}
		static const char* libssh2_hostkey_hash(LIBSSH2_SESSION* session, int hash_type) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_hostkey_hash(session, hash_type); return nullptr;}
		static const char* libssh2_userauth_list(LIBSSH2_SESSION* session, const char* username, unsigned int username_len) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_userauth_list(session, username, std::forward<unsigned int>(username_len)); return nullptr;}
		static int libssh2_userauth_password_ex(LIBSSH2_SESSION* session, const char* username, unsigned int username_len, const char* password, unsigned int password_len, LIBSSH2_PASSWD_CHANGEREQ_FUNC passwd_change_cb) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_userauth_password_ex(session, username, std::forward<unsigned int>(username_len), password, std::forward<unsigned int>(password_len), passwd_change_cb); return 0;}
		static int libssh2_session_last_error(LIBSSH2_SESSION* session, char** errmsg, int* errmsg_len, int want_buf) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_session_last_error(session, errmsg, errmsg_len, want_buf); return 0;}
		static LIBSSH2_SFTP* libssh2_sftp_init(LIBSSH2_SESSION* session) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_sftp_init(session); return nullptr;}
		static int libssh2_sftp_shutdown(LIBSSH2_SFTP* sftp) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_sftp_shutdown(sftp); return 0;}
		static LIBSSH2_SFTP_HANDLE* libssh2_sftp_open_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len, unsigned long flags, long mode, int open_type) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_sftp_open_ex(sftp, filename, std::forward<unsigned int>(filename_len), std::forward<unsigned long>(flags), mode, open_type); return nullptr;}
		static int libssh2_sftp_close_handle(LIBSSH2_SFTP_HANDLE* handle) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_sftp_close_handle(handle); return 0;}
		static int libssh2_sftp_unlink_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_sftp_unlink_ex(sftp, filename, std::forward<unsigned int>(filename_len)); return 0;}
		static int libssh2_sftp_mkdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, long mode) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_sftp_mkdir_ex(sftp, path, std::forward<unsigned int>(path_len), mode); return 0;}
		static int libssh2_sftp_rmdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_sftp_rmdir_ex(sftp, path, std::forward<unsigned int>(path_len)); return 0;}
		static int libssh2_sftp_fstat_ex(LIBSSH2_SFTP_HANDLE* handle, LIBSSH2_SFTP_ATTRIBUTES* attrs, bool setstat) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_sftp_fstat_ex(handle, attrs, setstat); return 0;}
		static int libssh2_sftp_stat_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, int stat_type, LIBSSH2_SFTP_ATTRIBUTES* attrs) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_sftp_stat_ex(sftp, path, std::forward<unsigned int>(path_len), stat_type, attrs); return 0;}
		static Int libssh2_sftp_read(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_sftp_read(handle, buffer, std::forward<size_t>(buffer_maxlen)); return 0;}
		static Int libssh2_sftp_write(LIBSSH2_SFTP_HANDLE* handle, const char* buffer, size_t count) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_sftp_write(handle, buffer, std::forward<size_t>(count)); return 0;}
		static int libssh2_sftp_readdir_ex(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen, char* longentry, size_t longentry_maxlen, LIBSSH2_SFTP_ATTRIBUTES* attrs) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_sftp_readdir_ex(handle, buffer, std::forward<size_t>(buffer_maxlen), longentry, std::forward<size_t>(longentry_maxlen), attrs); return 0;}
		static void libssh2_sftp_seek64(LIBSSH2_SFTP_HANDLE* handle, UInt64 offset) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SSHInterface::libssh2_sftp_seek64(handle, offset); return maxon::PrivateLogNullptrError();}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE SSHInterface::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<LIBSSH2_SESSION*>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<const char*>::value,
		maxon::details::NullReturnType<const char*>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<LIBSSH2_SFTP*>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<LIBSSH2_SFTP_HANDLE*>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<int>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool SSHInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_session_init = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_session_init;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_session_disconnect_ex = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_session_disconnect_ex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_session_free = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_session_free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_session_set_blocking = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_session_set_blocking;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_session_handshake = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_session_handshake;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_hostkey_hash = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_hostkey_hash;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_userauth_list = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_userauth_list;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_userauth_password_ex = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_userauth_password_ex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_session_last_error = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_session_last_error;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_sftp_init = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_sftp_init;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_sftp_shutdown = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_sftp_shutdown;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_sftp_open_ex = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_sftp_open_ex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_sftp_close_handle = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_sftp_close_handle;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_sftp_unlink_ex = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_sftp_unlink_ex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_sftp_mkdir_ex = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_sftp_mkdir_ex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_sftp_rmdir_ex = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_sftp_rmdir_ex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_sftp_fstat_ex = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_sftp_fstat_ex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_sftp_stat_ex = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_sftp_stat_ex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_sftp_read = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_sftp_read;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_sftp_write = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_sftp_write;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_sftp_readdir_ex = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_sftp_readdir_ex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SSHInterface_libssh2_sftp_seek64 = &Hxx2::Wrapper<Hxx2::Unresolved>::SSHInterface_libssh2_sftp_seek64;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(SSHInterface, "net.maxon.interface.ssh", nullptr);
}
#endif
