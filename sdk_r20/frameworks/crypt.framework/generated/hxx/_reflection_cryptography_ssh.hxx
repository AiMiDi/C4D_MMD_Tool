#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_SSHInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_session_init)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_session_disconnect_ex)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_session_free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_session_set_blocking)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_session_handshake)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_hostkey_hash)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_userauth_list)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_userauth_password_ex)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_session_last_error)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_sftp_init)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_sftp_shutdown)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_sftp_open_ex)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_sftp_close_handle)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_sftp_unlink_ex)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_sftp_mkdir_ex)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_sftp_rmdir_ex)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_sftp_fstat_ex)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_sftp_stat_ex)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_sftp_read)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_sftp_write)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_sftp_readdir_ex)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSHInterface::MTable::_instance._SSHInterface_libssh2_sftp_seek64)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SSHInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_SSHInterface("net.maxon.interface.ssh", nullptr, &RegisterReflection_SSHInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
