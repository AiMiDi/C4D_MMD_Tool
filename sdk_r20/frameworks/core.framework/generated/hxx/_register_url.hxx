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
		HTTP_ADDITIONAL_REQUEST_HEADER_PrivateAttribute HTTP_ADDITIONAL_REQUEST_HEADER;
		HTTP_RESPONSE_HEADER_PrivateAttribute HTTP_RESPONSE_HEADER;
		HTTP_FOLLOWMOVEDFILES_PrivateAttribute HTTP_FOLLOWMOVEDFILES;
		HTTP_POST_PrivateAttribute HTTP_POST;
		HTTP_POSTDATA_PrivateAttribute HTTP_POSTDATA;
		HTTP_NO_PROXY_CACHING_PrivateAttribute HTTP_NO_PROXY_CACHING;
		HTTP_DISALLOW_GZIP_PrivateAttribute HTTP_DISALLOW_GZIP;
		CACHE_IN_RAM_PrivateAttribute CACHE_IN_RAM;
		FTPS_FINGERPRINT_PrivateAttribute FTPS_FINGERPRINT;
	}
	namespace enum63 { enum class GETBROWSEITERATORFLAGS
	{
		NONE = 0,									///< No flags specified.
		NOERRORONOPEN = 1 << 0,		///< Will return no error when opening a non existing directory but will return an empty browse handler with no entries.
		RESOLVEPATHS = 1 << 1,		///< TODO: (Sebastian) please add documentation on this.
	} ; }
	maxon::String PrivateToString_GETBROWSEITERATORFLAGS63(std::underlying_type<enum63::GETBROWSEITERATORFLAGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum63::GETBROWSEITERATORFLAGS::NONE, (maxon::UInt64) enum63::GETBROWSEITERATORFLAGS::NOERRORONOPEN, (maxon::UInt64) enum63::GETBROWSEITERATORFLAGS::RESOLVEPATHS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "GETBROWSEITERATORFLAGS", SIZEOF(x), true, values, "NONE\0NOERRORONOPEN\0RESOLVEPATHS\0", fmt);
	}
	const maxon::Char* const UrlInterface::MTable::_ids = 
		"Free@90ef223219100d4f\0" // Free(const UrlInterface* object)
		"Alloc@1919cd4f0a0b4250\0" // Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@2611b99399a4e51d\0" // Alloc(const maxon::SourceLocation& allocLocation, const UrlInterface& object)
		"GetScheme@d40fa674ca538c66\0" // GetScheme() const
		"SetScheme@c5f32532e9182c47\0" // SetScheme(const UrlScheme& scheme)
		"Append@84c7b902e2c48cc0\0" // Append(const String& name)
		"Append@e1e93c17010d01ec\0" // Append(const Url& relativeUrl)
		"RemoveName@a54f4799cbe1a498\0" // RemoveName()
		"GetEmbeddedUrl@4e33a06\0" // GetEmbeddedUrl() const
		"SetEmbeddedUrl@e1e93c17010d01ec\0" // SetEmbeddedUrl(const Url& url)
		"GetName@22c6ed80868\0" // GetName() const
		"SetName@84c7b902e2c48cc0\0" // SetName(const String& name)
		"GetDirectory@4e33a06\0" // GetDirectory() const
		"SetPath@84c7b902e2c48cc0\0" // SetPath(const String& path)
		"GetPath@27f2c2db0d16c8cf\0" // GetPath() const
		"SetSystemPath@84c7b902e2c48cc0\0" // SetSystemPath(const String& path)
		"GetSystemPath@44dd277090c036a5\0" // GetSystemPath() const
		"SetUrl@15108ee068612476\0" // SetUrl(const String& urlString, Bool enableDefaultFallbackScheme)
		"GetUrl@22c6ed80868\0" // GetUrl() const
		"SetAuthority@84c7b902e2c48cc0\0" // SetAuthority(const String& authority)
		"SetAuthority@e1e93c17010d01ec\0" // SetAuthority(const Url& authority)
		"GetAuthority@24368c97617cbacb\0" // GetAuthority() const
		"GetComponents@3bf6f91fd2075b33\0" // GetComponents(const NonConstArray<String>& parts) const
		"GetRelativeUrl@80ddfa2d31821f51\0" // GetRelativeUrl(const Url& basePath) const
		"GetSuffix@22c6ed80868\0" // GetSuffix() const
		"CheckSuffix@c49f0cd54ab1f37b\0" // CheckSuffix(const String& suffix) const
		"SetSuffix@84c7b902e2c48cc0\0" // SetSuffix(const String& suffix)
		"ClearSuffix@6b2e10f\0" // ClearSuffix()
		"IsEmpty@76f01901\0" // IsEmpty() const
		"Compare@28c48b040ae3999a\0" // Compare(const UrlInterface* name, URLCOMPARE mode) const
		"GetData@2eae62019803af60\0" // GetData(const ConstDataPtr& key) const
		"SetData@93fdde9367885994\0" // SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent)
		"SetData@e6575338e0a263af\0" // SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent)
		"ToString@7de9f6f51c89c899\0" // ToString(const FormatStatement* formatStatement) const
		"DescribeIO@0c0a05550eef0455\0" // DescribeIO(const DataSerializeInterface& stream)
	"";
	class UrlInterface::Unresolved : public UrlInterface
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
		tbl->_UrlInterface_Free = &Wrapper<Unresolved>::_UrlInterface_Free;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UrlInterface_Alloc = &Wrapper<Unresolved>::_UrlInterface_Alloc;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UrlInterface_Alloc_1 = &Wrapper<Unresolved>::_UrlInterface_Alloc_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const UrlScheme&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetScheme = &Wrapper<Unresolved>::_UrlInterface_GetScheme;
	#else
		tbl->_UrlInterface_GetScheme = &Wrapper<Unresolved>::_UrlInterface_GetScheme;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetScheme = &Wrapper<Unresolved>::_UrlInterface_SetScheme;
	#else
		tbl->_UrlInterface_SetScheme = &Wrapper<Unresolved>::_UrlInterface_SetScheme;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_Append = &Wrapper<Unresolved>::_UrlInterface_Append;
	#else
		tbl->_UrlInterface_Append = &Wrapper<Unresolved>::_UrlInterface_Append;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_Append_1 = &Wrapper<Unresolved>::_UrlInterface_Append_1;
	#else
		tbl->_UrlInterface_Append_1 = &Wrapper<Unresolved>::_UrlInterface_Append_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_RemoveName = &Wrapper<Unresolved>::_UrlInterface_RemoveName;
	#else
		tbl->_UrlInterface_RemoveName = &Wrapper<Unresolved>::_UrlInterface_RemoveName;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Url>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetEmbeddedUrl = &Wrapper<Unresolved>::_UrlInterface_GetEmbeddedUrl;
	#else
		tbl->_UrlInterface_GetEmbeddedUrl = &Wrapper<Unresolved>::_UrlInterface_GetEmbeddedUrl;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetEmbeddedUrl = &Wrapper<Unresolved>::_UrlInterface_SetEmbeddedUrl;
	#else
		tbl->_UrlInterface_SetEmbeddedUrl = &Wrapper<Unresolved>::_UrlInterface_SetEmbeddedUrl;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetName = &Wrapper<Unresolved>::_UrlInterface_GetName;
	#else
		tbl->_UrlInterface_GetName = &Wrapper<Unresolved>::_UrlInterface_GetName;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetName = &Wrapper<Unresolved>::_UrlInterface_SetName;
	#else
		tbl->_UrlInterface_SetName = &Wrapper<Unresolved>::_UrlInterface_SetName;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Url>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetDirectory = &Wrapper<Unresolved>::_UrlInterface_GetDirectory;
	#else
		tbl->_UrlInterface_GetDirectory = &Wrapper<Unresolved>::_UrlInterface_GetDirectory;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetPath = &Wrapper<Unresolved>::_UrlInterface_SetPath;
	#else
		tbl->_UrlInterface_SetPath = &Wrapper<Unresolved>::_UrlInterface_SetPath;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const String&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetPath = &Wrapper<Unresolved>::_UrlInterface_GetPath;
	#else
		tbl->_UrlInterface_GetPath = &Wrapper<Unresolved>::_UrlInterface_GetPath;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetSystemPath = &Wrapper<Unresolved>::_UrlInterface_SetSystemPath;
	#else
		tbl->_UrlInterface_SetSystemPath = &Wrapper<Unresolved>::_UrlInterface_SetSystemPath;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<String>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetSystemPath = &Wrapper<Unresolved>::_UrlInterface_GetSystemPath;
	#else
		tbl->_UrlInterface_GetSystemPath = &Wrapper<Unresolved>::_UrlInterface_GetSystemPath;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetUrl = &Wrapper<Unresolved>::_UrlInterface_SetUrl;
	#else
		tbl->_UrlInterface_SetUrl = &Wrapper<Unresolved>::_UrlInterface_SetUrl;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetUrl = &Wrapper<Unresolved>::_UrlInterface_GetUrl;
	#else
		tbl->_UrlInterface_GetUrl = &Wrapper<Unresolved>::_UrlInterface_GetUrl;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetAuthority = &Wrapper<Unresolved>::_UrlInterface_SetAuthority;
	#else
		tbl->_UrlInterface_SetAuthority = &Wrapper<Unresolved>::_UrlInterface_SetAuthority;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetAuthority_1 = &Wrapper<Unresolved>::_UrlInterface_SetAuthority_1;
	#else
		tbl->_UrlInterface_SetAuthority_1 = &Wrapper<Unresolved>::_UrlInterface_SetAuthority_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Url&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetAuthority = &Wrapper<Unresolved>::_UrlInterface_GetAuthority;
	#else
		tbl->_UrlInterface_GetAuthority = &Wrapper<Unresolved>::_UrlInterface_GetAuthority;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetComponents = &Wrapper<Unresolved>::_UrlInterface_GetComponents;
	#else
		tbl->_UrlInterface_GetComponents = &Wrapper<Unresolved>::_UrlInterface_GetComponents;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetRelativeUrl = &Wrapper<Unresolved>::_UrlInterface_GetRelativeUrl;
	#else
		tbl->_UrlInterface_GetRelativeUrl = &Wrapper<Unresolved>::_UrlInterface_GetRelativeUrl;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetSuffix = &Wrapper<Unresolved>::_UrlInterface_GetSuffix;
	#else
		tbl->_UrlInterface_GetSuffix = &Wrapper<Unresolved>::_UrlInterface_GetSuffix;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UrlInterface_CheckSuffix = &Wrapper<Unresolved>::_UrlInterface_CheckSuffix;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetSuffix = &Wrapper<Unresolved>::_UrlInterface_SetSuffix;
	#else
		tbl->_UrlInterface_SetSuffix = &Wrapper<Unresolved>::_UrlInterface_SetSuffix;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UrlInterface_ClearSuffix = &Wrapper<Unresolved>::_UrlInterface_ClearSuffix;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_UrlInterface_IsEmpty = &Wrapper<Unresolved>::_UrlInterface_IsEmpty;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<COMPARERESULT>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_Compare = &Wrapper<Unresolved>::_UrlInterface_Compare;
	#else
		tbl->_UrlInterface_Compare = &Wrapper<Unresolved>::_UrlInterface_Compare;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Data>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_GetData = &Wrapper<Unresolved>::_UrlInterface_GetData;
	#else
		tbl->_UrlInterface_GetData = &Wrapper<Unresolved>::_UrlInterface_GetData;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetData = &Wrapper<Unresolved>::_UrlInterface_SetData;
	#else
		tbl->_UrlInterface_SetData = &Wrapper<Unresolved>::_UrlInterface_SetData;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_SetData_1 = &Wrapper<Unresolved>::_UrlInterface_SetData_1;
	#else
		tbl->_UrlInterface_SetData_1 = &Wrapper<Unresolved>::_UrlInterface_SetData_1;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_ToString = &Wrapper<Unresolved>::_UrlInterface_ToString;
	#else
		tbl->_UrlInterface_ToString = &Wrapper<Unresolved>::_UrlInterface_ToString;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_UrlInterface_DescribeIO = &Wrapper<Unresolved>::_UrlInterface_DescribeIO;
	#else
		tbl->_UrlInterface_DescribeIO = &Wrapper<Unresolved>::_UrlInterface_DescribeIO;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(UrlInterface, "net.maxon.interface.url", nullptr);
	template <typename DUMMY> maxon::Int UrlInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
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
