#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_SSLInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_ERR_get_state)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_ERR_clear_error)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_ADD_thread_state)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_load_error_strings)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_library_init)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_CTX_new)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "meth\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_TLSv1_method)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_TLSv1_1_method)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_TLSv1_2_method)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSLv3_method)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSLv2_method)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSLv23_method)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_new)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_ERR_get_error_string)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_ERR_get_error)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_ERR_peek_last_error)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_set_fd)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0fd\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_set_tlsext_hostname)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0serverName\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_connect)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ssl\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_shutdown)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ssl\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_CTX_free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_read)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ssl\0buf\0num\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_write)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ssl\0buf\0num\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_get_verify_result)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ssl\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_CTX_set_cipher_list)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0str\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_CTX_load_verify_locations)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0CAfile\0CApath\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_CTX_set_default_verify_paths)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_CTX_use_PrivateKey_file)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0file\0type\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_CTX_use_certificate_chain_file)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0file\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_CTX_ctrl)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0cmd\0larg\0parg\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_CTX_set_verify)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0mode\0callback\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_set_connect_state)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_set_accept_state)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_BIO_ctrl)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "bp\0cmd\0larg\0parg\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_get_rbio)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_get_wbio)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_do_handshake)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_get_error)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0ret_code\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_CIPHER_get_version)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "current\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_get_current_cipher)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_X509_free_)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_get_peer_certificate)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_X509_NAME_oneline)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0buf\0size\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_X509_NAME_get_text_by_NID)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "name\0nid\0buf\0len\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_X509_get_subject_name)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_X509_get_issuer_name)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_get_alt_names)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0alternativeNames\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_set_read_ahead)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0yes\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_pending)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_get_shutdown)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ssl\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_SSL_CTX_use_PrivateKey_ASN1_RSA)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0d\0len\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_VerifySignature)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "publicKey\0messageHash\0message\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SSLInterface::MTable::_instance._SSLInterface_CreateSignature)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "privateKey\0messageHash\0message\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SSLInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_SSLInterface("net.maxon.interface.ssl", nullptr, &RegisterReflection_SSLInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
