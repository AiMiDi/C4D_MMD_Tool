
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
namespace DESCRIPTION
{
	namespace BASE
	{
		struct COMMAND_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xb6dbd2278b27e19cLL), maxon::UInt(34))> { };
		struct IDENTIFIER_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x76cd6f4726d43cb8LL), maxon::UInt(37))> { };
		struct GROUP_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xc32fe9935af15910LL), maxon::UInt(32))> { };
		struct DATA_BASE_GROUP_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x91bc2dd69a269eb8LL), maxon::UInt(37))> { };
		struct UI_BASE_GROUP_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xf65805295782f60eLL), maxon::UInt(35))> { };
		struct STRING_BASE_GROUP_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xaa34cd533319cb71LL), maxon::UInt(39))> { };
	}
	namespace DATA
	{
		namespace BASE
		{
			struct DATATYPE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x599a406600c4db0bLL), maxon::UInt(40))> { };
			struct CLASSIFICATION_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xffb0e39616bbbbcdLL), maxon::UInt(46))> { };
			struct UNIT_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x15379e61c2eec62bLL), maxon::UInt(36))> { };
			struct DEFAULTVALUE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x8821fd62c529d177LL), maxon::UInt(44))> { };
			struct LIMITVALUE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x5c0c8551f741f5fdLL), maxon::UInt(42))> { };
			struct MINVALUE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x599a40a145c34f86LL), maxon::UInt(40))> { };
			struct MAXVALUE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x599a409fafa1ebb4LL), maxon::UInt(40))> { };
			struct INCLUDE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x136812990d45d2a1LL), maxon::UInt(39))> { };
			struct INCLUDERENAME_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xb5ea1a702f36cd1fLL), maxon::UInt(45))> { };
			struct INCLUDEFILTER_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xb5ea1a701af46159LL), maxon::UInt(45))> { };
			struct ENUM_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x15379e61c2e781a8LL), maxon::UInt(36))> { };
			struct DATABASEID_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x5c0bbee8c2f23f3dLL), maxon::UInt(42))> { };
			struct OVERWRITABLE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x8c3468d0db83d21bLL), maxon::UInt(44))> { };
			struct ISVARIADIC_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x5c0c4527e0a9b030LL), maxon::UInt(42))> { };
			struct VARIADICCOUNT_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x3f9a5dcbe8ef0209LL), maxon::UInt(45))> { };
			struct VARIADICCOMMANDS_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x8cc93437afe1ff4eLL), maxon::UInt(48))> { };
			struct VARIADICIDS_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x25a086e3f9953e32LL), maxon::UInt(43))> { };
			struct COMMENT_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x13681297d2226c58LL), maxon::UInt(39))> { };
			struct GENERATEIGNOREHEADER_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x9da2ba5366ee077bLL), maxon::UInt(52))> { };
			struct INHERITSTRING_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xb5f7ff28d04c6805LL), maxon::UInt(45))> { };
			struct OPTIONALSTRING_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x14567dacf0432b58LL), maxon::UInt(46))> { };
			struct NAMESPACE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xd9add41a76f83914LL), maxon::UInt(41))> { };
			struct INCLUDEDFROM_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x89ff4b2ce7faf00dLL), maxon::UInt(44))> { };
			struct ORIGIN_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xa5c98cfcb8510e0dLL), maxon::UInt(38))> { };
			struct GROUPDEV_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x599a407cb441ca5dLL), maxon::UInt(40))> { };
		}
		namespace INFO
		{
			struct CLASSIFICATION_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xfa1e77bf68df4850LL), maxon::UInt(46))> { };
			struct PROCESSOR_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xa757bcc4a1b59de8LL), maxon::UInt(41))> { };
			struct PROCESSORPARAMS_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x3f4a6c71ad9c896eLL), maxon::UInt(47))> { };
			struct IMAGEURLPORT_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xd89067548c9b5f9fLL), maxon::UInt(44))> { };
			struct INCLUDEFILE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x3046d2bf0f1609faLL), maxon::UInt(43))> { };
			struct COMMENT_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x16049eaffa8c9d35LL), maxon::UInt(39))> { };
			struct HIDDEN_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xa5df1de4ad2bbc14LL), maxon::UInt(38))> { };
		}
	}
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

