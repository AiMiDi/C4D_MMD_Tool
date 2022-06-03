/*
	DON'T EDIT THIS FILE!
	It has been created and is updated automatically by the interface processor.
	It has to be included by the register.cpp file of the project in order for the automatic registration to work.
*/
#define PRIVATE_MAXON_REGISTRATION_UNIT


#ifndef PRIVATE_MAXON_REGISTRATION_FRAMEWORK
#define PRIVATE_MAXON_DEFINE_MODULE_INFO_FLAGS | EntityBase::FLAGS::PUBLIC
#include "maxon/register.h"
#endif

#include "_include_cryptography.hxx"
#include "_include_cryptography_hash.hxx"
#include "_include_cryptography_key.hxx"
#include "_include_cryptography_ssh.hxx"
#include "_include_cryptography_ssl.hxx"
#include "_include_datacompression.hxx"
#include "_include_fileformat_zip.hxx"

#ifdef PRIVATE_MAXON_REGISTRATION_FRAMEWORK

#include "_reflection_cryptography.hxx"
#include "_reflection_cryptography_hash.hxx"
#include "_reflection_cryptography_key.hxx"
#include "_reflection_cryptography_ssh.hxx"
#include "_reflection_cryptography_ssl.hxx"
#include "_reflection_datacompression.hxx"
#include "_reflection_fileformat_zip.hxx"

#else

MAXON_NULL_VALUE_INCOMPLETE_GET_DEFINITION;

#include "_register_cryptography.hxx"
#include "_register_cryptography_hash.hxx"
#include "_register_cryptography_key.hxx"
#include "_register_cryptography_ssh.hxx"
#include "_register_cryptography_ssl.hxx"
#include "_register_datacompression.hxx"
#include "_register_fileformat_zip.hxx"

static maxon::Id g_usedFrameworks[] = {maxon::Id("net.maxon.core.framework")};
static maxon::SetUsedFrameworks g_setUsedFrameworks(PRIVATE_MAXON_MODULE, g_usedFrameworks);

#endif
