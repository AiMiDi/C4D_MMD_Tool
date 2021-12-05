#ifndef UUID_H__
#define UUID_H__


#include "maxon/interface.h"
#include "maxon/string.h"


namespace maxon
{

class Uuid;

//----------------------------------------------------------------------------------------
/// Creates an uuid object. The object will be constructed with no valid uuid.
/// After calling CreateId() a new id is generated.
///
/// Examples how to create ids:
/// @code
/// Uuid a;                                                      // creates an empty id.
/// Uuid b(MAXON_SOURCE_LOCATION);                                              // creates a new unique id.
/// Uuid c("00000000-0000-0000-0000-000000000000"_s); // creates a new id with the given identifier.
/// a.CreateId();                                                // creates a new unique id.
/// a.Set("00000000-0000-0000-0000-000000000000"_s);  // sets the given identifier.
/// String uuid = Uuid::CreateUuidString();                      // creates a new id and returns it as a string.
/// @endcode
///
/// from: http://www.ietf.org/rfc/rfc4122.txt
///
/// One of the main reasons for using UUIDs is that no centralized
/// authority is required to administer them (although one format uses
/// IEEE 802 node identifiers, others do not).  As a result, generation
/// on demand can be completely automated, and used for a variety of
/// purposes.  The UUID generation algorithm described here supports very
/// high allocation rates of up to 10 million per second per machine if
/// necessary, so that they could even be used as transaction IDs.
///
/// UUIDs are of a fixed size (128 bits) which is reasonably small
/// compared to other alternatives.  This lends itself well to sorting,
/// ordering, and hashing of all sorts, storing in databases, simple
/// allocation, and ease of programming in general.
///
/// Since UUIDs are unique and persistent, they make excellent Uniform
/// Resource Names.  The unique ability to generate a new UUID without a
/// registration process allows for UUIDs to be one of the URNs with the
/// lowest minting cost.
///
/// @MAXON_ANNOTATION{refclass=false}
//----------------------------------------------------------------------------------------
class UuidInterface
{
	MAXON_INTERFACE_NONVIRTUAL(UuidInterface, MAXON_REFERENCE_COPY_ON_WRITE, "net.maxon.interface.uuid");

public:
	//----------------------------------------------------------------------------------------
	/// @param[in] allocLocation			Source location.
	/// @param[in] uuid								String with a valid uuid.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD UuidInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const String& uuid);

	//----------------------------------------------------------------------------------------
	/// @param[in] allocLocation			Source location.
	/// @param[in] uuid								Pointer to memory of a uuid in big endian format.
	/// @param[in] uuidSize						Size of the memory block that receives the uuid.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD UuidInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION, const UChar* uuid, Int uuidSize);

	//----------------------------------------------------------------------------------------
	/// Returns whether the object is empty or not. A Uuid is empty if it hasn't been constructed yet, or
	/// if a copy operation on the object failed, or if it just contains 0-values.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool IsEmpty() const;

	//----------------------------------------------------------------------------------------
	/// Returns whether the object is populated or not. Always the opposite of IsEmpty().
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool IsPopulated() const
	{
		return !IsEmpty();
	}

	//----------------------------------------------------------------------------------------
	/// Creates a new uuid.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CreateId();

	//----------------------------------------------------------------------------------------
	/// Sets a given uuid string. The id must be of the format "00000000-0000-0000-0000-000000000000".
	/// @param[in] uuid								String with a valid uuid.
	/// @return												OK on success. Returns IllegalArgumentError if the id could not be parsed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(const String& uuid);

	//----------------------------------------------------------------------------------------
	/// Sets a given memory block of a uuid. The id must be 16 bytes long. Please note that native window functions return little endian for the first 3 components which is different to this call.
	/// @param[in] uuid								Pointer to memory of a uuid in big endian format.
	/// @param[in] uuidSize						Size of the memory block that keeps the uuid.
	/// @return												OK on success. Returns IllegalArgumentError if the id could not be parsed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Set(const UChar* uuid, Int uuidSize);

	//----------------------------------------------------------------------------------------
	/// Gets a given memory block of a uuid. The id must be 16 bytes long. Please note that native window functions return little endian for the first 3 components which is different to this call.
	/// @param[in] uuid								Pointer to memory of a uuid in big endian format.
	/// @param[in] uuidSize						Size of the memory block that receives the uuid.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Get(UChar* uuid, Int uuidSize) const;

	//----------------------------------------------------------------------------------------
	/// Converts the uuid into a string. The format will be "00000000-0000-0000-0000-000000000000" and the letters will be uppercase.
	/// @param[in] formatStatement		Format statement for string formating.
	/// @return												String representation of the uuid.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Compares the uuid against another uuid.
	/// @param[in] uuid								The uuid to compare with.
	/// @return												See COMPARERESULT.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD COMPARERESULT Compare(const UuidInterface* uuid) const;

	//----------------------------------------------------------------------------------------
	/// Returns the hash code of the uuid. The return value is 0 if the object IsEmpty().
	//----------------------------------------------------------------------------------------
	MAXON_METHOD UInt GetHashCode() const;

	//----------------------------------------------------------------------------------------
	/// Describes all elements of this class for I/O operations.
	/// @param[in] stream							The stream that is used to register the class members.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<void> DescribeIO(const DataSerializeInterface& stream);

	//----------------------------------------------------------------------------------------
	/// Creates a new uuid and returns the string of it.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<String> CreateUuidString();
};

#include "uuid1.hxx"

class Uuid : public UuidInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Uuid, Reference);

	MAXON_IMPLICIT Uuid(const String& uuid)
	{
		*this = Reference::Create(uuid).UncheckedGetValue();
	}

	Uuid(const UChar* uuid, Int uuidSize)
	{
		*this = Reference::Create(uuid, uuidSize).UncheckedGetValue();
	}
};

#include "uuid2.hxx"

#if (defined MAXON_TARGET_WINDOWS) && (defined MAXON_TARGET_DEBUG)
	// definition for natvis file
	struct UuidX4lo
	{
		unsigned __int8 v : 4;
		unsigned __int8 _ : 4;
	};
	static UuidX4lo g_natvisHelperUuidX4lo;

	struct UuidX4hi
	{
		unsigned __int8 _ : 4;
		unsigned __int8 v : 4;
	};
	static UuidX4hi g_natvisHelperUuidX4hi;

	struct UuidX8
	{
		unsigned __int8 _;
	};
	static UuidX8 g_natvisHelperUuidX8;

	struct UuidX32
	{
		__int32 _;
	};
	static UuidX32 g_natvisHelperUuidX32;
#endif

} // namespace maxon

#endif // UUID_H__
