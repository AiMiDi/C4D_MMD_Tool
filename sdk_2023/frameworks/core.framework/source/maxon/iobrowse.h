#ifndef IOBROWSE_H__
#define IOBROWSE_H__

#include "maxon/objectbase.h"
#include "maxon/datetime.h"
#include "maxon/ioenums.h"
#include "maxon/url.h"


namespace maxon
{

/// @addtogroup IO
/// @{

//----------------------------------------------------------------------------------------
/// Possible flags of IoGetFlags()
//----------------------------------------------------------------------------------------
enum class IOBROWSEFLAGS
{
	NONE						 	= 0,			///< No bit set.
	IS_DIRECTORY		 	= 1 << 0,	///< Browsed file is a directory.
	IS_BUNDLE				 	= 1 << 1,	///< Browsed file is a bundle (osx/ios).
	IS_READONLY			 	= 1 << 2,	///< Browsed file is read only.
	IS_HIDDEN				 	= 1 << 3,	///< Browsed file is hidden.
	SUPPORT_REVISIONS	= 1 << 4,	///< Browsed file supports file revisions. This means requesting a browseiterator allows to browse through all revisions of the file.
	IS_LINK					 	= 1 << 5,	///< Browsed file is a link.
	IS_ENCRYPTED		 	= 1 << 6,	///< Browsed file is encrypted within an archive.
	IS_DELETED			 	= 1 << 7,	///< Browsed file is deleted. E.g. when browsing a perforce depot with deleted files.
	IS_INVISIBLE		 	= 1 << 8,	///< Browsed file should be treated as invisible for the app; this is set for any file that starts with '.' under OSX/Linux or '._' under Windows. Under Windows files can be invisible, but not hidden.
} MAXON_ENUM_FLAGS(IOBROWSEFLAGS, "net.maxon.datatype.enum.iobrowseflags");


class IoConnectionInterface;
class IoBrowseRef;

//----------------------------------------------------------------------------------------
/// The IoBrowserIterator interface for a given Url.
/// This IoBrowserIterator needs to be implemented for each protocol that support kind of directories. (e.g. "file", "zip")
//----------------------------------------------------------------------------------------
class IoBrowseInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(IoBrowseInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.iobrowse");

public:
	/// @cond INTERNAL

	//----------------------------------------------------------------------------------------
	/// Private.
	/// TODO: (Tilo) Please describe.
	/// @param[in] connection					IoConnectionRef connected to this IoBrowseRef.
	/// @param[in] flags							See GETBROWSEITERATORFLAGS.
	/// @MAXON_ANNOTATION{returnsThis}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags);

	/// @endcond

	//----------------------------------------------------------------------------------------
	/// Returns corresponding Url.
	/// @return												Name of the connection.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const Url& GetBasePath() const;

	//----------------------------------------------------------------------------------------
	/// Restart browsing of the directory.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> Reset();

	//----------------------------------------------------------------------------------------
	/// Browses to the next object in the list.
	/// You need to call GetNext() before you get the first object.
	/// A typical use is: while (browse->GetNext()) { n = browse->GetCurrentPath(); }
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> GetNext();

	//----------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Bool HasEntry() const;

	//----------------------------------------------------------------------------------------
	/// Returns the current Url.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Url GetCurrentPath() const;

	//----------------------------------------------------------------------------------------
	/// Returns the flags (IOBROWSEFLAGS) of the children.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD IOBROWSEFLAGS IoGetFlags() const;

	//----------------------------------------------------------------------------------------
	/// Returns the flags (IOATTRIBUTES) of the children.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<IOATTRIBUTES> IoGetAttributes() const;

	//----------------------------------------------------------------------------------------
	/// Returns the DateTime of the current file. The time is in local time.
	/// @param[in] mode								IOTIMEMODE of the requested time.
	/// @return												Returns the DateTime or an error.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const;

	//----------------------------------------------------------------------------------------
	/// Returns the size of the current file.
	/// @return												Size in bytes. -1 means unknown size.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int64 GetSize() const;

	//----------------------------------------------------------------------------------------
	/// Returns some extra data.
	/// @return												The return value depends on the handler what it returns.
	/// 															URLSCHEME_VOLUME: returns the human readable drive name.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String GetExtraData() const;

	MAXON_ADD_TO_REFERENCE_CLASS(
		const IoBrowseRef& operator *()
		{
			return *(IoBrowseRef*)((char*) this + (S::HAS_ERROR ? SIZEOF(void*) : 0));
		}
		Result<void> operator ++()	// prefix operator++ (increment and fetch)
		{
			return GetNext();
		}

		template <typename SUPER> using ResultFunctions = ResultIteratorFunctions<ObjectRef::ResultFunctions<SUPER>>;
		);
};


// include autogenerated headerfile here
#include "iobrowse1.hxx"

MAXON_DECLARATION(Class<IoBrowseRef>, IoBrowseBaseClass, "net.maxon.class.iobrowsebase");

// include autogenerated headerfile here
#include "iobrowse2.hxx"

/// @}

} // namespace maxon



#endif // IOBROWSE_H__
