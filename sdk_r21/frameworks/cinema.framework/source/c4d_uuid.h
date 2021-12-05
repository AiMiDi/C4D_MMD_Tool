/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_UUID_H__
#define C4D_UUID_H__

#include "maxon/uuid.h"
#include "maxon/crc32c.h"

/// @markDeprecated Use maxon::Uuid. 
class C4DUuid : public maxon::Uuid
{
public:
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @markDeprecated Use maxon::Uuid::CreateId().
	//----------------------------------------------------------------------------------------
	C4DUuid()
	{
		iferr (maxon::Uuid::CreateId())
			CriticalStop();
	}

	//----------------------------------------------------------------------------------------
	/// Creates an uninitialized uuid.
	/// @param[in] n									Dummy argument. Pass @ref DC.
	//----------------------------------------------------------------------------------------
	explicit C4DUuid(_DONTCONSTRUCT n)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Creates an empty uuid.
	/// @param[in] n									Dummy argument. Pass @ref EC.
	//----------------------------------------------------------------------------------------
	explicit C4DUuid(_EMPTYCONSTRUCT n) : maxon::Uuid((const UChar*)maxon::g_zeroMemory, 16)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] uid								Another C4DUuid to copy.
	//----------------------------------------------------------------------------------------
	C4DUuid(const C4DUuid& uid) : maxon::Uuid(uid)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Gets the hash code for the uuid.
	/// @markDeprecated Use maxon::Uuid::GetHashCode().
	/// @note This method returns a UInt32 and calculates a different value than maxon::Uuid::GetHashCode().
	/// @return												The uuid's hash code.
	//----------------------------------------------------------------------------------------
	UInt32 GetHashCodeDeprecated() const
	{
		UChar buf[16];
		
		iferr (maxon::Uuid::Get(buf, 16))
		{
			CriticalStop();
			return 0;
		}

		maxon::Crc32C crc;
		crc.Update(buf);
		return (UInt32)crc.GetCrc();
	}

	//----------------------------------------------------------------------------------------
	/// Resets the uuid.
	/// @markDeprecated Use maxon::Uuid::CreateId() or Set().
	/// @param[in] clear							@trueIfOtherwiseFalse{true} to clear the uuid or @trueIfOtherwiseFalse{false} to reinitialize it.
	//----------------------------------------------------------------------------------------
	void Reset(Bool clear)
	{
		if (clear)
		{
			iferr (maxon::Uuid::Set((const UChar*)maxon::g_zeroMemory, 16))
				CriticalStop();
		}
		else
		{
			iferr (maxon::Uuid::CreateId())
				CriticalStop();
		}
	}

	//----------------------------------------------------------------------------------------
	/// Gets the string for the uuid.
	/// @markDeprecated Use maxon::Uuid::ToString().
	/// @return												The uuid's string.
	//----------------------------------------------------------------------------------------
	String GetString() const
	{
		return maxon::Uuid::ToString(nullptr);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the uuid has content.
	/// @return												@trueIfOtherwiseFalse{the uuid has content}
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return maxon::Uuid::IsPopulated();
	}

	//----------------------------------------------------------------------------------------
	/// Copies the uuid to a ::UChar buffer.
	/// @markDeprecated Use maxon::Uuid::Get().
	/// @param[in] buf								The destination buffer.
	//----------------------------------------------------------------------------------------
	void CopyTo(UChar* buf) const
	{
		iferr (maxon::Uuid::Get(buf, 16))
			ClearMem(buf, 16);
	}

	//----------------------------------------------------------------------------------------
	/// Copies the uuid from a ::UChar buffer.
	/// @markDeprecated Use maxon::Uuid::Set().
	/// @param[in] buf								The source buffer.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> CopyFrom(UChar* buf)
	{
		return maxon::Uuid::Set(buf, 16);
	}

	//----------------------------------------------------------------------------------------
	/// Copies the uuid from a string.
	/// @markDeprecated Use maxon::Uuid::Set().
	/// @param[in] uuid								The source string.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	maxon::Result<void> CopyFrom(const maxon::String& uuid)
	{
		return maxon::Uuid::Set(uuid);
	}

	//----------------------------------------------------------------------------------------
	/// Copies the uuid to another uuid.
	/// @markDeprecated Use maxon::Uuid::Set().
	/// @param[in] dst								The destination uuid.
	//----------------------------------------------------------------------------------------
	void CopyTo(const C4DUuid& dst) const
	{
		UChar buf[16];
		
		iferr (maxon::Uuid::Get(buf, 16))
		{
			CriticalStop();
			return;
		}
		dst.CopyTo(buf);
	}

	//----------------------------------------------------------------------------------------
	/// Equality operator. Checks if the uuids are equal.
	/// @markDeprecated Use maxon::Uuid::Compare().
	/// @param[in] k									A uuid to compare with.
	/// @return												@trueIfOtherwiseFalse{the uuids are equal}
	//----------------------------------------------------------------------------------------
	Bool operator == (const C4DUuid& k) const
	{
		return maxon::Uuid::Compare(k) == maxon::COMPARERESULT::EQUAL;
	}

	//----------------------------------------------------------------------------------------
	/// Inequality operator. Checks if the uuids are different.
	/// @markDeprecated Use maxon::Uuid::Compare().
	/// @param[in] k									A uuid to compare with.
	/// @return												@trueIfOtherwiseFalse{the uuids are different}
	//----------------------------------------------------------------------------------------
	Bool operator != (const C4DUuid& k) const
	{
		return maxon::Uuid::Compare(k) != maxon::COMPARERESULT::EQUAL;
	}
};

#endif // C4D_UUID_H__
