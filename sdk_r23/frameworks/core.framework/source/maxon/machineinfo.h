#ifndef MACHINEINFO_H__
#define MACHINEINFO_H__

#include "maxon/bytesvalue.h"
#include "maxon/fid.h"
#include "maxon/general_math.h"
#include "maxon/string.h"


//----------------------------------------------------------------------------------------
// BEGIN - auto generated code, do not edit
//----------------------------------------------------------------------------------------
namespace maxon
{
//----------------------------------------------------------------------------------------
/// IDs for the DataDictionary of Application::GetMachineInfo().
/// you can get the values by calling machineInfo.Get(MACHINEINFO::USERNAME) iferr_return;
//----------------------------------------------------------------------------------------
namespace MACHINEINFO
{
	MAXON_RESOURCE_DATABASE_SCOPE("net.maxon.machineinfo");

	/// Computer name returned by the OS.
	MAXON_ATTRIBUTE(String, COMPUTERNAME, "net.maxon.machineinfo.computername");

	/// User name of the currently logged in user.
	MAXON_ATTRIBUTE(String, USERNAME, "net.maxon.machineinfo.username");

	/// OS Version in text format.
	MAXON_ATTRIBUTE(String, OSVERSION, "net.maxon.machineinfo.osversion");

	/// OS build number as integer value.
	MAXON_ATTRIBUTE(Int, OSBUILDNUMBER, "net.maxon.machineinfo.osbuildnumber");

	/// Unique OS identifier. This id allows to identify a machine. Each machine (even VMs) should have it's unique identifier.
	MAXON_ATTRIBUTE(String, UNIQUEOSIDENTIFIER, "net.maxon.machineinfo.uniqueosidentifier");

	/// Unique OS identifier source. This id allows to identify a machine. Each machine (even VMs) should have it's unique identifier.
	/// NONE
	/// TPM: WIN TPM module
	/// UEFI: WIN Uefi
	/// REGISTRY: WIN registry
	/// CRYPTOGRAPHYID: WIN old cryptography id
	/// CRYPTOGRAPHYID_FALLBACK: WIN blocked collision id -> cryptography id
	/// SERIALKEY: OSX kIOPlatformSerialNumberKey
	/// UUIDKEY: OSX kIOPlatformUUIDKey
	MAXON_ATTRIBUTE(Id, UNIQUEOSIDENTIFIERSOURCE, "net.maxon.machineinfo.uniqueosidentifiersource",
		RESOURCE_DEFINE(ENUM_NONE, Id("none"))
		RESOURCE_DEFINE(ENUM_TPM, Id("tpm"))
		RESOURCE_DEFINE(ENUM_UEFI, Id("uefi"))
		RESOURCE_DEFINE(ENUM_REGISTRY, Id("registry"))
		RESOURCE_DEFINE(ENUM_CRYPTOGRAPHYID, Id("cryptographyid"))
		RESOURCE_DEFINE(ENUM_CRYPTOGRAPHYID_FALLBACK, Id("cryptographyid_fallback"))
		RESOURCE_DEFINE(ENUM_SERIALKEY, Id("serialkey"))
		RESOURCE_DEFINE(ENUM_UUIDKEY, Id("uuidkey")));

	/// Languages in order of preference. the first language is the most preferred language.
	MAXON_ATTRIBUTE(BaseArray<Id>, LANGUAGES, "net.maxon.machineinfo.languages");

	/// Linux and OSX only (getuid).
	MAXON_ATTRIBUTE(Int, USER_ID, "net.maxon.machineinfo.user_id");

	/// Linux and OSX only (geteuid).
	MAXON_ATTRIBUTE(Int, EFFECTIVE_USER_ID, "net.maxon.machineinfo.effective_user_id");

	/// Linux and OSX only (getgid).
	MAXON_ATTRIBUTE(Int, GROUP_ID, "net.maxon.machineinfo.group_id");

	/// Linux and OSX only (getegid).
	MAXON_ATTRIBUTE(Int, EFFECTIVE_GROUP_ID, "net.maxon.machineinfo.effective_group_id");

	/// CPU id string.
	MAXON_ATTRIBUTE(String, PROCESSORTYPE, "net.maxon.machineinfo.processortype");

	/// Name of the processor.
	MAXON_ATTRIBUTE(String, PROCESSORNAME, "net.maxon.machineinfo.processorname");

	/// Supported cpu features.
	MAXON_ATTRIBUTE(String, PROCESSORFEATURES, "net.maxon.machineinfo.processorfeatures");

	/// Processor architecture.
	MAXON_ATTRIBUTE(String, PROCESSORARCHITECTURE, "net.maxon.machineinfo.processorarchitecture");

	/// Nominal processor frequency.
	MAXON_ATTRIBUTE(Float64, PROCESSORFREQMHZ, "net.maxon.machineinfo.processorfreqmhz");

	/// Number of threads including hyper threading cores.
	MAXON_ATTRIBUTE(Int32, NUMBEROFPROCESSORS, "net.maxon.machineinfo.numberofprocessors");

	/// Number of physical cpu cores.
	MAXON_ATTRIBUTE(Int32, NUMBEROFPHYSICALCORES, "net.maxon.machineinfo.numberofphysicalcores");

	/// True if SSE2 is supported.
	MAXON_ATTRIBUTE(Bool, SUPPORTSSE2, "net.maxon.machineinfo.supportsse2");

	/// True if SSE3 is supported.
	MAXON_ATTRIBUTE(Bool, SUPPORTSSE3, "net.maxon.machineinfo.supportsse3");

	/// True if SSSE3 is supported (some older 64 bit AMD cpus do not support this feature).
	MAXON_ATTRIBUTE(Bool, SUPPORTSSSE3, "net.maxon.machineinfo.supportssse3");

	/// True if SSE41 is supported.
	MAXON_ATTRIBUTE(Bool, SUPPORTSSE41, "net.maxon.machineinfo.supportsse41");

	/// True if SSE42 is supported.
	MAXON_ATTRIBUTE(Bool, SUPPORTSSE42, "net.maxon.machineinfo.supportsse42");

	/// True if AVX is supported.
	MAXON_ATTRIBUTE(Bool, SUPPORTAVX, "net.maxon.machineinfo.supportavx");

	/// True if AVX2 is supported.
	MAXON_ATTRIBUTE(Bool, SUPPORTAVX2, "net.maxon.machineinfo.supportavx2");

	/// True if FMA is supported.
	MAXON_ATTRIBUTE(Bool, SUPPORTFMA, "net.maxon.machineinfo.supportfma");

	/// True if AES is supported.
	MAXON_ATTRIBUTE(Bool, SUPPORTAES, "net.maxon.machineinfo.supportaes");

	/// True if PCLMULQDQ is supported.
	MAXON_ATTRIBUTE(Bool, SUPPORTPCLMULQDQ, "net.maxon.machineinfo.supportpclmulqdq");

	/// Physical memory of the machine.
	MAXON_ATTRIBUTE(BytesValue, PHYSICALMEMORY, "net.maxon.machineinfo.physicalmemory");

	/// Main Display Device of the machine.
	MAXON_ATTRIBUTE(String, DISPLAYDEVICE, "net.maxon.machineinfo.displaydevice");

	MAXON_ATTRIBUTE(Group, GROUP_OS, "net.maxon.machineinfo.group.os");

	MAXON_ATTRIBUTE(Group, GROUP_HARDWARE, "net.maxon.machineinfo.group.hardware");
}
}
//----------------------------------------------------------------------------------------
// END - auto generated code, do not edit
//----------------------------------------------------------------------------------------

#include "machineinfo1.hxx"
#include "machineinfo2.hxx"

#endif // MACHINEINFO_H__
