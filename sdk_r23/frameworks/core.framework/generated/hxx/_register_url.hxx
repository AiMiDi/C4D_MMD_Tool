#if 1
namespace maxon
{
	namespace URLFLAGS
	{
		UNBUFFERED_FILE_PrivateAttribute UNBUFFERED_FILE;
		NETWORK_CONNECTTIMEOUT_PrivateAttribute NETWORK_CONNECTTIMEOUT;
		NETWORK_SESSIONTIMEOUT_PrivateAttribute NETWORK_SESSIONTIMEOUT;
		USERNAME_PrivateAttribute USERNAME;
		USERPASSWORD_PrivateAttribute USERPASSWORD;
		QUERY_PrivateAttribute QUERY;
		FRAGMENT_PrivateAttribute FRAGMENT;
		CACHE_IN_RAM_PrivateAttribute CACHE_IN_RAM;
		FTPS_FINGERPRINT_PrivateAttribute FTPS_FINGERPRINT;
	}
	namespace enum54 { enum class GETBROWSEITERATORFLAGS
	{
		NONE = 0,									///< No flags specified.
		NOERRORONOPEN = 1 << 0,		///< Will return no error when opening a non existing directory but will return an empty browse handler with no entries.
		RESOLVEPATHS = 1 << 1,		///< TODO: (Sebastian) please add documentation on this.
	} ; }
	maxon::String PrivateToString_GETBROWSEITERATORFLAGS54(std::underlying_type<enum54::GETBROWSEITERATORFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum54::GETBROWSEITERATORFLAGS::NONE, (maxon::UInt64) enum54::GETBROWSEITERATORFLAGS::NOERRORONOPEN, (maxon::UInt64) enum54::GETBROWSEITERATORFLAGS::RESOLVEPATHS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GETBROWSEITERATORFLAGS", SIZEOF(x), true, values, "NONE\0NOERRORONOPEN\0RESOLVEPATHS\0", fmt);
	}
	const maxon::Char* const UrlInterface::MTable::_ids = 
		"Free@515adf4a4bcd3dca\0" // void Free(const UrlInterface* object)
		"Alloc@10d45449dcb2d9b3\0" // UrlInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@82d7f22a223fdf40\0" // UrlInterface* Alloc(const maxon::SourceLocation& allocLocation, const UrlInterface& object)
		"GetScheme@c3dafd89bade4735\0" // const UrlScheme& GetScheme() const
		"SetScheme@c72b9815756151ec\0" // Result<void> SetScheme(const UrlScheme& scheme)
		"Append@d85d74e087a2f051\0" // Result<void> Append(const String& name)
		"Append@1db4eca46d9225b9\0" // Result<void> Append(const Url& relativeUrl)
		"RemoveName@3008090429c5a175\0" // Result<void> RemoveName()
		"GetEmbeddedUrl@f0cc56ca89511da7\0" // Url GetEmbeddedUrl() const
		"SetEmbeddedUrl@1db4eca46d9225b9\0" // Result<void> SetEmbeddedUrl(const Url& url)
		"GetName@b8f12dfa16054f01\0" // String GetName() const
		"SetName@d85d74e087a2f051\0" // Result<void> SetName(const String& name)
		"GetDirectory@f0cc56ca89511da7\0" // Url GetDirectory() const
		"SetPath@d85d74e087a2f051\0" // Result<void> SetPath(const String& path)
		"GetPath@8fd391aee7382314\0" // const String& GetPath() const
		"SetSystemPath@d85d74e087a2f051\0" // Result<void> SetSystemPath(const String& path)
		"GetSystemPath@74a82a5700c59c60\0" // Result<String> GetSystemPath() const
		"SetUrl@b4bc6d7668aa1693\0" // Result<void> SetUrl(const String& urlString, Bool enableDefaultFallbackScheme)
		"GetUrl@b8f12dfa16054f01\0" // String GetUrl() const
		"SetAuthority@d85d74e087a2f051\0" // Result<void> SetAuthority(const String& authority)
		"SetAuthority@1db4eca46d9225b9\0" // Result<void> SetAuthority(const Url& authority)
		"GetAuthority@dd23129f046419ec\0" // const Url& GetAuthority() const
		"GetComponents@b4598998dddd3732\0" // Result<void> GetComponents(const NonConstArray<String>& parts) const
		"GetRelativeUrl@f5d52a42a2050d2c\0" // Result<Url> GetRelativeUrl(const Url& basePath) const
		"GetSuffix@b8f12dfa16054f01\0" // String GetSuffix() const
		"CheckSuffix@1d577fae915a8f2e\0" // Bool CheckSuffix(const String& suffix) const
		"SetSuffix@d85d74e087a2f051\0" // Result<void> SetSuffix(const String& suffix)
		"ClearSuffix@780cdac8f1a33934\0" // void ClearSuffix()
		"IsEmpty@12e73654e6d65520\0" // Bool IsEmpty() const
		"Compare@9533ebe50f064c99\0" // COMPARERESULT Compare(const UrlInterface* name, URLCOMPARE mode) const
		"GetData@2650f729e23305a1\0" // Result<Data> GetData(const ConstDataPtr& key) const
		"SetData@347fe24919b69e97\0" // Result<void> SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent)
		"SetData@194242748340e0b8\0" // Result<void> SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent)
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* formatStatement) const
		"DescribeIO@fe3f1bd5a495cc32\0" // Result<void> DescribeIO(const DataSerializeInterface& stream)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class UrlInterface::Hxx2::Unresolved : public UrlInterface
	{
	public:
		static const Unresolved* Get(const UrlInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(UrlInterface* o) { return (Unresolved*) o; }
		static void Free(const UrlInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UrlInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static UrlInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UrlInterface::Alloc(allocLocation); return nullptr;}
		static UrlInterface* Alloc(const maxon::SourceLocation& allocLocation, const UrlInterface& object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return UrlInterface::Alloc(allocLocation, object); return nullptr;}
		const UrlScheme& GetScheme() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetScheme(); return maxon::PrivateIncompleteNullReturnValue<const UrlScheme&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<void> SetScheme(const UrlScheme& scheme) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetScheme(scheme); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Append(const String& name) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->Append(name); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Append(const Url& relativeUrl) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->Append(relativeUrl); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> RemoveName() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->RemoveName(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Url GetEmbeddedUrl() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetEmbeddedUrl(); return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<void> SetEmbeddedUrl(const Url& url) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetEmbeddedUrl(url); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		String GetName() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetName(); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<void> SetName(const String& name) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetName(name); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Url GetDirectory() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetDirectory(); return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<void> SetPath(const String& path) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetPath(path); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		const String& GetPath() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetPath(); return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<void> SetSystemPath(const String& path) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetSystemPath(path); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<String> GetSystemPath() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UrlInterface*) this)->GetSystemPath(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetUrl(const String& urlString, Bool enableDefaultFallbackScheme) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetUrl(urlString, enableDefaultFallbackScheme); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		String GetUrl() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetUrl(); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<void> SetAuthority(const String& authority) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetAuthority(authority); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetAuthority(const Url& authority) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetAuthority(authority); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		const Url& GetAuthority() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetAuthority(); return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<void> GetComponents(const NonConstArray<String>& parts) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UrlInterface*) this)->GetComponents(parts); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Url> GetRelativeUrl(const Url& basePath) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UrlInterface*) this)->GetRelativeUrl(basePath); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		String GetSuffix() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetSuffix(); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Bool CheckSuffix(const String& suffix) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->CheckSuffix(suffix); return maxon::PrivateLogNullptrError(false);}
		Result<void> SetSuffix(const String& suffix) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetSuffix(suffix); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		void ClearSuffix() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((UrlInterface*) this)->ClearSuffix(); return maxon::PrivateLogNullptrError();}
		Bool IsEmpty() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->IsEmpty(); return true;}
		COMPARERESULT Compare(const UrlInterface* name, URLCOMPARE mode) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->Compare(name, mode); return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Result<Data> GetData(const ConstDataPtr& key) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UrlInterface*) this)->GetData(key); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetData(std::forward<ForwardingDataPtr>(key), data, persistent); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetData(std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		String ToString(const FormatStatement* formatStatement) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->ToString(formatStatement); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<void> DescribeIO(const DataSerializeInterface& stream) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return UrlInterface::DescribeIO(stream); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE UrlInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<UrlInterface*>::value,
		maxon::details::NullReturnType<UrlInterface*>::value,
		maxon::details::NullReturnType<const UrlScheme&>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Url>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Url>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<const String&>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<String>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<const Url&>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Url>>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<COMPARERESULT>::value,
		maxon::details::NullReturnType<Result<Data>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool UrlInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_UrlInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_UrlInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_UrlInterface_Alloc_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_Alloc_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const UrlScheme&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetScheme = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetScheme;
		#else
		tbl->_UrlInterface_GetScheme = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetScheme;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetScheme = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetScheme;
		#else
		tbl->_UrlInterface_SetScheme = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetScheme;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_Append = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_Append;
		#else
		tbl->_UrlInterface_Append = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_Append;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_Append_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_Append_1;
		#else
		tbl->_UrlInterface_Append_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_Append_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_RemoveName = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_RemoveName;
		#else
		tbl->_UrlInterface_RemoveName = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_RemoveName;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Url>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetEmbeddedUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetEmbeddedUrl;
		#else
		tbl->_UrlInterface_GetEmbeddedUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetEmbeddedUrl;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetEmbeddedUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetEmbeddedUrl;
		#else
		tbl->_UrlInterface_SetEmbeddedUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetEmbeddedUrl;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetName = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetName;
		#else
		tbl->_UrlInterface_GetName = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetName;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetName = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetName;
		#else
		tbl->_UrlInterface_SetName = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetName;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Url>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetDirectory = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetDirectory;
		#else
		tbl->_UrlInterface_GetDirectory = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetDirectory;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetPath = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetPath;
		#else
		tbl->_UrlInterface_SetPath = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetPath;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const String&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetPath = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetPath;
		#else
		tbl->_UrlInterface_GetPath = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetPath;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetSystemPath = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetSystemPath;
		#else
		tbl->_UrlInterface_SetSystemPath = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetSystemPath;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<String>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetSystemPath = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetSystemPath;
		#else
		tbl->_UrlInterface_GetSystemPath = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetSystemPath;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetUrl;
		#else
		tbl->_UrlInterface_SetUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetUrl;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetUrl;
		#else
		tbl->_UrlInterface_GetUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetUrl;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetAuthority = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetAuthority;
		#else
		tbl->_UrlInterface_SetAuthority = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetAuthority;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetAuthority_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetAuthority_1;
		#else
		tbl->_UrlInterface_SetAuthority_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetAuthority_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Url&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetAuthority = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetAuthority;
		#else
		tbl->_UrlInterface_GetAuthority = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetAuthority;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetComponents = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetComponents;
		#else
		tbl->_UrlInterface_GetComponents = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetComponents;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetRelativeUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetRelativeUrl;
		#else
		tbl->_UrlInterface_GetRelativeUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetRelativeUrl;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetSuffix = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetSuffix;
		#else
		tbl->_UrlInterface_GetSuffix = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetSuffix;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_UrlInterface_CheckSuffix = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_CheckSuffix;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetSuffix = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetSuffix;
		#else
		tbl->_UrlInterface_SetSuffix = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetSuffix;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_UrlInterface_ClearSuffix = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_ClearSuffix;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_UrlInterface_IsEmpty = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_IsEmpty;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<COMPARERESULT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_Compare = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_Compare;
		#else
		tbl->_UrlInterface_Compare = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_Compare;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Data>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetData = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetData;
		#else
		tbl->_UrlInterface_GetData = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_GetData;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetData = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetData;
		#else
		tbl->_UrlInterface_SetData = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetData;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetData_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetData_1;
		#else
		tbl->_UrlInterface_SetData_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_SetData_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_ToString;
		#else
		tbl->_UrlInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_ToString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_DescribeIO = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_DescribeIO;
		#else
		tbl->_UrlInterface_DescribeIO = &Hxx2::Wrapper<Hxx2::Unresolved>::_UrlInterface_DescribeIO;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(UrlInterface, "net.maxon.interface.url", nullptr);
	template <typename DUMMY> maxon::Int UrlInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<IODETECT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<Url>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const String&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const Url&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const UrlScheme&>(OVERLOAD_MAX_RANK)
		;
	}
#ifdef URLSCHEME_UNC_ENABLED
#endif
}
#endif
static maxon::details::ForceEvaluation s_forceEval_url(0
	| maxon::UrlInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
