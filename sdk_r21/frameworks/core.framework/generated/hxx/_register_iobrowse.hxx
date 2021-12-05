#if 1
namespace maxon
{
	namespace enum31 { enum class IOBROWSEFLAGS
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
	} ; }
	maxon::String PrivateToString_IOBROWSEFLAGS31(std::underlying_type<enum31::IOBROWSEFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum31::IOBROWSEFLAGS::NONE, (maxon::UInt64) enum31::IOBROWSEFLAGS::IS_DIRECTORY, (maxon::UInt64) enum31::IOBROWSEFLAGS::IS_BUNDLE, (maxon::UInt64) enum31::IOBROWSEFLAGS::IS_READONLY, (maxon::UInt64) enum31::IOBROWSEFLAGS::IS_HIDDEN, (maxon::UInt64) enum31::IOBROWSEFLAGS::SUPPORT_REVISIONS, (maxon::UInt64) enum31::IOBROWSEFLAGS::IS_LINK, (maxon::UInt64) enum31::IOBROWSEFLAGS::IS_ENCRYPTED, (maxon::UInt64) enum31::IOBROWSEFLAGS::IS_DELETED, (maxon::UInt64) enum31::IOBROWSEFLAGS::IS_INVISIBLE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "IOBROWSEFLAGS", SIZEOF(x), true, values, "NONE\0IS_DIRECTORY\0IS_BUNDLE\0IS_READONLY\0IS_HIDDEN\0SUPPORT_REVISIONS\0IS_LINK\0IS_ENCRYPTED\0IS_DELETED\0IS_INVISIBLE\0", fmt);
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_IOBROWSEFLAGS, , "net.maxon.datatype.enum.iobrowseflags");
/// @cond INTERNAL

/// @endcond

	const maxon::Char* const IoBrowseInterface::MTable::_ids = 
/// @cond INTERNAL

		"Init@247cfc1149c71d78\0" // Result<void> Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags)
/// @endcond

		"GetBasePath@24368c97617cbacb\0" // const Url& GetBasePath() const
		"Reset@a54f4799cbe1a498\0" // Result<void> Reset()
		"GetNext@a54f4799cbe1a498\0" // Result<void> GetNext()
		"HasEntry@76f01901\0" // Bool HasEntry() const
		"GetCurrentPath@4e33a06\0" // Url GetCurrentPath() const
		"IoGetFlags@fcfcd0514d74d7ee\0" // IOBROWSEFLAGS IoGetFlags() const
		"IoGetAttributes@507ff8fe2ae3e399\0" // Result<IOATTRIBUTES> IoGetAttributes() const
		"IoGetTime@14de2ec95d150358\0" // Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const
		"GetSize@fd7d7f404\0" // Int64 GetSize() const
		"GetExtraData@22c6ed80868\0" // String GetExtraData() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IoBrowseInterface, , "net.maxon.interface.iobrowse", "maxon.IoBrowseInterface", (&ObjectInterface::_interface));
	template <typename DUMMY> maxon::Int IoBrowseInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<IOBROWSEFLAGS>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<Url>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Url&>(OVERLOAD_MAX_RANK)
		;
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(IoBrowseBaseClass, , "net.maxon.class.iobrowsebase");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_iobrowse(0
	| maxon::IoBrowseInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
