#if 1
namespace maxon
{
	const maxon::Char* const SSHInterface::MTable::_ids = 
		"libssh2_session_init@cd9541ba36c862e4\0" // libssh2_session_init()
		"libssh2_session_disconnect_ex@4e24413f8f040412\0" // libssh2_session_disconnect_ex(LIBSSH2_SESSION* session, int reason, const char* description, const char* lang)
		"libssh2_session_free@ccd72efd729cc58b\0" // libssh2_session_free(LIBSSH2_SESSION* session)
		"libssh2_session_set_blocking@b34ac01d0936018d\0" // libssh2_session_set_blocking(LIBSSH2_SESSION* session, int blocking)
		"libssh2_session_handshake@1f83b795a4fab5c8\0" // libssh2_session_handshake(LIBSSH2_SESSION* session, Int socket)
		"libssh2_hostkey_hash@8324b0aabf1f0850\0" // libssh2_hostkey_hash(LIBSSH2_SESSION* session, int hash_type)
		"libssh2_userauth_list@5967ddbc7d4d7b4e\0" // libssh2_userauth_list(LIBSSH2_SESSION* session, const char* username, unsigned int username_len)
		"libssh2_userauth_password_ex@a3a258146306f991\0" // libssh2_userauth_password_ex(LIBSSH2_SESSION* session, const char* username, unsigned int username_len, const char* password, unsigned int password_len, LIBSSH2_PASSWD_CHANGEREQ_FUNC passwd_change_cb)
		"libssh2_session_last_error@2a05e4d5ff4de983\0" // libssh2_session_last_error(LIBSSH2_SESSION* session, char** errmsg, int* errmsg_len, int want_buf)
		"libssh2_sftp_init@c420691f39a08787\0" // libssh2_sftp_init(LIBSSH2_SESSION* session)
		"libssh2_sftp_shutdown@33c14fad7f302fac\0" // libssh2_sftp_shutdown(LIBSSH2_SFTP* sftp)
		"libssh2_sftp_open_ex@5433c9aff86b108e\0" // libssh2_sftp_open_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len, unsigned long flags, long mode, int open_type)
		"libssh2_sftp_close_handle@1fe0aea5da7e6ced\0" // libssh2_sftp_close_handle(LIBSSH2_SFTP_HANDLE* handle)
		"libssh2_sftp_unlink_ex@4873dd76ba6495f5\0" // libssh2_sftp_unlink_ex(LIBSSH2_SFTP* sftp, const char* filename, unsigned int filename_len)
		"libssh2_sftp_mkdir_ex@f1082d521dc581e9\0" // libssh2_sftp_mkdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, long mode)
		"libssh2_sftp_rmdir_ex@4873dd76ba6495f5\0" // libssh2_sftp_rmdir_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len)
		"libssh2_sftp_fstat_ex@6c4ce71039ee3e96\0" // libssh2_sftp_fstat_ex(LIBSSH2_SFTP_HANDLE* handle, LIBSSH2_SFTP_ATTRIBUTES* attrs, bool setstat)
		"libssh2_sftp_stat_ex@cd8cfe0658dba935\0" // libssh2_sftp_stat_ex(LIBSSH2_SFTP* sftp, const char* path, unsigned int path_len, int stat_type, LIBSSH2_SFTP_ATTRIBUTES* attrs)
		"libssh2_sftp_read@9c5622b74fbdffff\0" // libssh2_sftp_read(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen)
		"libssh2_sftp_write@db167a2cd797ea82\0" // libssh2_sftp_write(LIBSSH2_SFTP_HANDLE* handle, const char* buffer, size_t count)
		"libssh2_sftp_readdir_ex@751d0b4c2b8b947a\0" // libssh2_sftp_readdir_ex(LIBSSH2_SFTP_HANDLE* handle, char* buffer, size_t buffer_maxlen, char* longentry, size_t longentry_maxlen, LIBSSH2_SFTP_ATTRIBUTES* attrs)
		"libssh2_sftp_seek64@fd9257e19f93ce50\0" // libssh2_sftp_seek64(LIBSSH2_SFTP_HANDLE* handle, UInt64 offset)
	"";
	class SSHInterface::Unresolved : public SSHInterface
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
		tbl->_SSHInterface_libssh2_session_init = &Wrapper<Unresolved>::_SSHInterface_libssh2_session_init;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_session_disconnect_ex = &Wrapper<Unresolved>::_SSHInterface_libssh2_session_disconnect_ex;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_session_free = &Wrapper<Unresolved>::_SSHInterface_libssh2_session_free;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_session_set_blocking = &Wrapper<Unresolved>::_SSHInterface_libssh2_session_set_blocking;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_session_handshake = &Wrapper<Unresolved>::_SSHInterface_libssh2_session_handshake;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_hostkey_hash = &Wrapper<Unresolved>::_SSHInterface_libssh2_hostkey_hash;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_userauth_list = &Wrapper<Unresolved>::_SSHInterface_libssh2_userauth_list;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_userauth_password_ex = &Wrapper<Unresolved>::_SSHInterface_libssh2_userauth_password_ex;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_session_last_error = &Wrapper<Unresolved>::_SSHInterface_libssh2_session_last_error;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_sftp_init = &Wrapper<Unresolved>::_SSHInterface_libssh2_sftp_init;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_sftp_shutdown = &Wrapper<Unresolved>::_SSHInterface_libssh2_sftp_shutdown;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_sftp_open_ex = &Wrapper<Unresolved>::_SSHInterface_libssh2_sftp_open_ex;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_sftp_close_handle = &Wrapper<Unresolved>::_SSHInterface_libssh2_sftp_close_handle;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_sftp_unlink_ex = &Wrapper<Unresolved>::_SSHInterface_libssh2_sftp_unlink_ex;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_sftp_mkdir_ex = &Wrapper<Unresolved>::_SSHInterface_libssh2_sftp_mkdir_ex;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_sftp_rmdir_ex = &Wrapper<Unresolved>::_SSHInterface_libssh2_sftp_rmdir_ex;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_sftp_fstat_ex = &Wrapper<Unresolved>::_SSHInterface_libssh2_sftp_fstat_ex;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_sftp_stat_ex = &Wrapper<Unresolved>::_SSHInterface_libssh2_sftp_stat_ex;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_sftp_read = &Wrapper<Unresolved>::_SSHInterface_libssh2_sftp_read;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_sftp_write = &Wrapper<Unresolved>::_SSHInterface_libssh2_sftp_write;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_sftp_readdir_ex = &Wrapper<Unresolved>::_SSHInterface_libssh2_sftp_readdir_ex;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_SSHInterface_libssh2_sftp_seek64 = &Wrapper<Unresolved>::_SSHInterface_libssh2_sftp_seek64;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(SSHInterface, "net.maxon.interface.ssh", nullptr);
	template <typename DUMMY> maxon::Int SSHInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_cryptography_ssh(0
	| maxon::SSHInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
