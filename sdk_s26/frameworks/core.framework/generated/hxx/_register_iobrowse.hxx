#if 1
namespace maxon
{
	namespace enum31
	{
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
		} ;
		static const maxon::UInt64 IOBROWSEFLAGS_values[] = {maxon::UInt64(enum31::IOBROWSEFLAGS::NONE), maxon::UInt64(enum31::IOBROWSEFLAGS::IS_DIRECTORY), maxon::UInt64(enum31::IOBROWSEFLAGS::IS_BUNDLE), maxon::UInt64(enum31::IOBROWSEFLAGS::IS_READONLY), maxon::UInt64(enum31::IOBROWSEFLAGS::IS_HIDDEN), maxon::UInt64(enum31::IOBROWSEFLAGS::SUPPORT_REVISIONS), maxon::UInt64(enum31::IOBROWSEFLAGS::IS_LINK), maxon::UInt64(enum31::IOBROWSEFLAGS::IS_ENCRYPTED), maxon::UInt64(enum31::IOBROWSEFLAGS::IS_DELETED), maxon::UInt64(enum31::IOBROWSEFLAGS::IS_INVISIBLE)};
		static const maxon::EnumInfo IOBROWSEFLAGS_info{"IOBROWSEFLAGS", SIZEOF(IOBROWSEFLAGS), true, "NONE\0IS_DIRECTORY\0IS_BUNDLE\0IS_READONLY\0IS_HIDDEN\0SUPPORT_REVISIONS\0IS_LINK\0IS_ENCRYPTED\0IS_DELETED\0IS_INVISIBLE\0", IOBROWSEFLAGS_values, std::extent<decltype(IOBROWSEFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_IOBROWSEFLAGS31(){ return enum31::IOBROWSEFLAGS_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_IOBROWSEFLAGS, , "net.maxon.datatype.enum.iobrowseflags");
/// @cond INTERNAL

/// @endcond

	const maxon::Char* const IoBrowseInterface::MTable::_ids = 
/// @cond INTERNAL

		"Init@36d382510ff02dd\0" // Result<void> Init(IoConnectionInterface* connection, GETBROWSEITERATORFLAGS flags)
/// @endcond

		"GetBasePath@dd23129f046419ec\0" // const Url& GetBasePath() const
		"Reset@3008090429c5a175\0" // Result<void> Reset()
		"GetNext@3008090429c5a175\0" // Result<void> GetNext()
		"HasEntry@12e73654e6d65520\0" // Bool HasEntry() const
		"GetCurrentPath@f0cc56ca89511da7\0" // Url GetCurrentPath() const
		"IoGetFlags@f06bd7957acce49b\0" // IOBROWSEFLAGS IoGetFlags() const
		"IoGetAttributes@48f6114bedbf9314\0" // Result<IOATTRIBUTES> IoGetAttributes() const
		"IoGetTime@3554f01be48bac5\0" // Result<UniversalDateTime> IoGetTime(IOTIMEMODE mode) const
		"GetSize@22a5c7f065ce5f0d\0" // Int64 GetSize() const
		"GetExtraData@b8f12dfa16054f01\0" // String GetExtraData() const
	"";
	const maxon::METHOD_FLAGS IoBrowseInterface::MTable::_flags[] = 
	{
/// @cond INTERNAL

		maxon::METHOD_FLAGS::NONE,
/// @endcond

		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(IoBrowseInterface, , "net.maxon.interface.iobrowse", "maxon.IoBrowseInterface", (ObjectInterface::PrivateGetInterface()));
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
