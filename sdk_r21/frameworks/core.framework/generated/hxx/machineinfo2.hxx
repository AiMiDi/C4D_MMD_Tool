
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
namespace MACHINEINFO
{
	struct COMPUTERNAME_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x14f9a9d23f8283bbLL), maxon::UInt(34))> { };
	struct USERNAME_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xe41d1c39c9032aebLL), maxon::UInt(30))> { };
	struct OSVERSION_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x9f86665b4b2306ffLL), maxon::UInt(31))> { };
	struct OSBUILDNUMBER_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x0eb1204defc415deLL), maxon::UInt(35))> { };
	struct UNIQUEOSIDENTIFIER_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xaf906cc5282bd3b3LL), maxon::UInt(40))> { };
	struct LANGUAGES_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x9f8663929cda78a6LL), maxon::UInt(31))> { };
	struct USER_ID_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xee95958e404a355aLL), maxon::UInt(29))> { };
	struct EFFECTIVE_USER_ID_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x3968db93938f0d02LL), maxon::UInt(39))> { };
	struct GROUP_ID_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xe41d1bdff70818f0LL), maxon::UInt(30))> { };
	struct EFFECTIVE_GROUP_ID_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xf3b296850c5e3648LL), maxon::UInt(40))> { };
	struct PROCESSORTYPE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x1969599eda2aa5d7LL), maxon::UInt(35))> { };
	struct PROCESSORNAME_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x1969599eda279128LL), maxon::UInt(35))> { };
	struct PROCESSORFEATURES_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x2bd35c9ced4a645aLL), maxon::UInt(39))> { };
	struct PROCESSORARCHITECTURE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x21cb6764a78292f0LL), maxon::UInt(43))> { };
	struct PROCESSORFREQMHZ_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x2ab43ccb57dbe50aLL), maxon::UInt(38))> { };
	struct NUMBEROFPROCESSORS_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x9d835876280f34d6LL), maxon::UInt(40))> { };
	struct NUMBEROFPHYSICALCORES_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xf46b4f289f07eb68LL), maxon::UInt(43))> { };
	struct SUPPORTSSE2_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xd7920e35a7eaace7LL), maxon::UInt(33))> { };
	struct SUPPORTSSE3_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xd7920e35a7eaace8LL), maxon::UInt(33))> { };
	struct SUPPORTSSSE3_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x1aafb87f556b2ae7LL), maxon::UInt(34))> { };
	struct SUPPORTSSE41_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x1aafb87f556af068LL), maxon::UInt(34))> { };
	struct SUPPORTSSE42_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x1aafb87f556af069LL), maxon::UInt(34))> { };
	struct SUPPORTAVX_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x5146c6a6e4622589LL), maxon::UInt(32))> { };
	struct SUPPORTAVX2_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xd7920e35a7e28bc9LL), maxon::UInt(33))> { };
	struct SUPPORTFMA_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x5146c6a6e4623720LL), maxon::UInt(32))> { };
	struct SUPPORTAES_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x5146c6a6e4622375LL), maxon::UInt(32))> { };
	struct SUPPORTPCLMULQDQ_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x531611f768cd46b9LL), maxon::UInt(38))> { };
	struct PHYSICALMEMORY_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xaa280e2f4c3d5eedLL), maxon::UInt(36))> { };
	struct DISPLAYDEVICE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x931dbb950c0880a3LL), maxon::UInt(35))> { };
	struct GROUP_OS_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xe41d1bdff70761c8LL), maxon::UInt(30))> { };
	struct GROUP_HARDWARE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x2a36221b1f01beccLL), maxon::UInt(36))> { };
}
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

