#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_SSLInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_ERR_get_state)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_ERR_clear_error)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_ADD_thread_state)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_load_error_strings)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_library_init)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_OPENSSL_init_ssl)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_CTX_new)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "meth\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_TLSv1_method)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_TLSv1_1_method)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_TLSv1_2_method)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSLv3_method)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSLv2_method)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSLv23_method)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_TLS_method)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_new)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_ERR_get_error_string)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_ERR_get_error)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_ERR_peek_last_error)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_set_fd)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0fd\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_set_tlsext_hostname)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0serverName\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_connect)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ssl\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_shutdown)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ssl\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_CTX_free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_read)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ssl\0buf\0num\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_write)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ssl\0buf\0num\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_get_verify_result)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ssl\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_CTX_set_cipher_list)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0str\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_CTX_load_verify_locations)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0CAfile\0CApath\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_CTX_set_default_verify_paths)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_CTX_use_PrivateKey_file)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0file\0type\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_CTX_use_certificate_chain_file)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0file\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_CTX_ctrl)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0cmd\0larg\0parg\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_CTX_set_verify)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0mode\0callback\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_set_connect_state)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_set_accept_state)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_BIO_ctrl)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "bp\0cmd\0larg\0parg\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_get_rbio)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_get_wbio)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_do_handshake)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_get_error)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0ret_code\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_CIPHER_get_version)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "current\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_get_current_cipher)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_X509_free_)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_get_peer_certificate)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_X509_NAME_oneline)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0buf\0size\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_X509_NAME_get_text_by_NID)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "name\0nid\0buf\0len\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_X509_get_subject_name)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_X509_get_issuer_name)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_get_alt_names)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0alternativeNames\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_set_read_ahead)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0yes\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_pending)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "s\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_get_shutdown)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ssl\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_SSL_CTX_use_PrivateKey_ASN1_RSA)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "ctx\0d\0len\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_VerifySignature)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "publicKey\0messageHash\0message\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SSLInterface::MTable::_instance.SSLInterface_CreateSignature)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "privateKey\0messageHash\0message\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SSLInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_SSLInterface("net.maxon.interface.ssl", nullptr, &RegisterReflection_SSLInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
