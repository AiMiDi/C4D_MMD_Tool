
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* UrlInterface::PrivateGetCppName() { return "maxon::Url"; }

struct UrlInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(UrlInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const UrlInterface* object);
	PRIVATE_MAXON_SF_POINTER(UrlInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (UrlInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(UrlInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (UrlInterface*), const maxon::SourceLocation& allocLocation, const UrlInterface& object);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetScheme, GetScheme, false, UrlInterface, const, (const UrlScheme&));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetScheme, SetScheme, false, UrlInterface,, (Result<void>), const UrlScheme& scheme);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_Append, Append, false, UrlInterface,, (Result<void>), const String& name);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_Append_1, Append, false, UrlInterface,, (Result<void>), const Url& relativeUrl);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_RemoveName, RemoveName, false, UrlInterface,, (Result<void>));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetEmbeddedUrl, GetEmbeddedUrl, false, UrlInterface, const, (Url));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetEmbeddedUrl, SetEmbeddedUrl, false, UrlInterface,, (Result<void>), const Url& url);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetName, GetName, false, UrlInterface, const, (String));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetName, SetName, false, UrlInterface,, (Result<void>), const String& name);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetDirectory, GetDirectory, false, UrlInterface, const, (Url));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetPath, SetPath, false, UrlInterface,, (Result<void>), const String& path);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetPath_1, SetPath, false, UrlInterface,, (Result<void>), const String& path, Bool convertWindowsBackslashes);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetPath, GetPath, false, UrlInterface, const, (const String&));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetSystemPath, SetSystemPath, false, UrlInterface,, (Result<void>), const String& path);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetSystemPath, GetSystemPath, false, UrlInterface, const, (Result<String>));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetUrl, SetUrl, false, UrlInterface,, (Result<void>), const String& urlString, Bool enableDefaultFallbackScheme);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetUrl, GetUrl, false, UrlInterface, const, (String));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetAuthority, SetAuthority, false, UrlInterface,, (Result<void>), const String& authority);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetAuthority_1, SetAuthority, false, UrlInterface,, (Result<void>), const Url& authority);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetAuthority, GetAuthority, false, UrlInterface, const, (const Url&));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetComponents, GetComponents, false, UrlInterface, const, (Result<void>), const NonConstArray<String>& parts);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetRelativeUrl, GetRelativeUrl, false, UrlInterface, const, (Result<Url>), const Url& basePath);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetSuffix, GetSuffix, false, UrlInterface, const, (String));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_CheckSuffix, CheckSuffix, false, UrlInterface, const, (Bool), const String& suffix);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetSuffix, SetSuffix, false, UrlInterface,, (Result<void>), const String& suffix);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_ClearSuffix, ClearSuffix, false, UrlInterface,, (void));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_IsEmpty, IsEmpty, false, UrlInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_Compare, Compare, false, UrlInterface, const, (COMPARERESULT), const UrlInterface* name, URLCOMPARE mode);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetData, GetData, false, UrlInterface, const, (Result<Data>), const ConstDataPtr& key);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetData, SetData, false, UrlInterface,, (Result<void>), ForwardingDataPtr&& key, const Data& data, Bool persistent);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetData_1, SetData, false, UrlInterface,, (Result<void>), ForwardingDataPtr&& key, Data&& data, Bool persistent);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_EraseData, EraseData, false, UrlInterface,, (Result<void>), ForwardingDataPtr&& key, Bool persistent);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_ToString, ToString, false, UrlInterface, const, (String), const FormatStatement* formatStatement);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_ToCString, ToCString, false, UrlInterface, const, (CString));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_ConvertToUiName, ConvertToUiName, false, UrlInterface, const, (Result<String>), CONVERTTOUINAMEFLAGS flags);
	PRIVATE_MAXON_SF_POINTER(UrlInterface_ConvertFromUiName, ConvertFromUiName, MAXON_EXPAND_VA_ARGS, (Result<Url>), const String& str);
	PRIVATE_MAXON_SF_POINTER(UrlInterface_DescribeIO, DescribeIO, MAXON_EXPAND_VA_ARGS, (Result<void>), const DataSerializeInterface& stream);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_ConvertToUiNameWithRepository, ConvertToUiNameWithRepository, false, UrlInterface, const, (Result<String>), CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository);
	PRIVATE_MAXON_SF_POINTER(UrlInterface_ConvertFromUiNameWithRepository, ConvertFromUiNameWithRepository, MAXON_EXPAND_VA_ARGS, (Result<Url>), const String& str, const AssetRepositoryRef& lookupRepository);
	template <typename IMPL> void Init()
	{
		UrlInterface_Free = UrlInterface_Free_GetPtr<IMPL>(true);
		UrlInterface_Alloc = UrlInterface_Alloc_GetPtr<IMPL>(true);
		UrlInterface_Alloc_1 = UrlInterface_Alloc_1_GetPtr<IMPL>(true);
		UrlInterface_GetScheme = UrlInterface_GetScheme_GetPtr<IMPL>(0, true).first;
		UrlInterface_SetScheme = UrlInterface_SetScheme_GetPtr<IMPL>(0, true).first;
		UrlInterface_Append = UrlInterface_Append_GetPtr<IMPL>(0, true).first;
		UrlInterface_Append_1 = UrlInterface_Append_1_GetPtr<IMPL>(0, true).first;
		UrlInterface_RemoveName = UrlInterface_RemoveName_GetPtr<IMPL>(0, true).first;
		UrlInterface_GetEmbeddedUrl = UrlInterface_GetEmbeddedUrl_GetPtr<IMPL>(0, true).first;
		UrlInterface_SetEmbeddedUrl = UrlInterface_SetEmbeddedUrl_GetPtr<IMPL>(0, true).first;
		UrlInterface_GetName = UrlInterface_GetName_GetPtr<IMPL>(0, true).first;
		UrlInterface_SetName = UrlInterface_SetName_GetPtr<IMPL>(0, true).first;
		UrlInterface_GetDirectory = UrlInterface_GetDirectory_GetPtr<IMPL>(0, true).first;
		UrlInterface_SetPath = UrlInterface_SetPath_GetPtr<IMPL>(0, true).first;
		UrlInterface_SetPath_1 = UrlInterface_SetPath_1_GetPtr<IMPL>(0, true).first;
		UrlInterface_GetPath = UrlInterface_GetPath_GetPtr<IMPL>(0, true).first;
		UrlInterface_SetSystemPath = UrlInterface_SetSystemPath_GetPtr<IMPL>(0, true).first;
		UrlInterface_GetSystemPath = UrlInterface_GetSystemPath_GetPtr<IMPL>(0, true).first;
		UrlInterface_SetUrl = UrlInterface_SetUrl_GetPtr<IMPL>(0, true).first;
		UrlInterface_GetUrl = UrlInterface_GetUrl_GetPtr<IMPL>(0, true).first;
		UrlInterface_SetAuthority = UrlInterface_SetAuthority_GetPtr<IMPL>(0, true).first;
		UrlInterface_SetAuthority_1 = UrlInterface_SetAuthority_1_GetPtr<IMPL>(0, true).first;
		UrlInterface_GetAuthority = UrlInterface_GetAuthority_GetPtr<IMPL>(0, true).first;
		UrlInterface_GetComponents = UrlInterface_GetComponents_GetPtr<IMPL>(0, true).first;
		UrlInterface_GetRelativeUrl = UrlInterface_GetRelativeUrl_GetPtr<IMPL>(0, true).first;
		UrlInterface_GetSuffix = UrlInterface_GetSuffix_GetPtr<IMPL>(0, true).first;
		UrlInterface_CheckSuffix = UrlInterface_CheckSuffix_GetPtr<IMPL>(0, true).first;
		UrlInterface_SetSuffix = UrlInterface_SetSuffix_GetPtr<IMPL>(0, true).first;
		UrlInterface_ClearSuffix = UrlInterface_ClearSuffix_GetPtr<IMPL>(0, true).first;
		UrlInterface_IsEmpty = UrlInterface_IsEmpty_GetPtr<IMPL>(0, true).first;
		UrlInterface_Compare = UrlInterface_Compare_GetPtr<IMPL>(0, true).first;
		UrlInterface_GetData = UrlInterface_GetData_GetPtr<IMPL>(0, true).first;
		UrlInterface_SetData = UrlInterface_SetData_GetPtr<IMPL>(0, true).first;
		UrlInterface_SetData_1 = UrlInterface_SetData_1_GetPtr<IMPL>(0, true).first;
		UrlInterface_EraseData = UrlInterface_EraseData_GetPtr<IMPL>(0, true).first;
		UrlInterface_ToString = UrlInterface_ToString_GetPtr<IMPL>(0, true).first;
		UrlInterface_ToCString = UrlInterface_ToCString_GetPtr<IMPL>(0, true).first;
		UrlInterface_ConvertToUiName = UrlInterface_ConvertToUiName_GetPtr<IMPL>(0, true).first;
		UrlInterface_ConvertFromUiName = UrlInterface_ConvertFromUiName_GetPtr<IMPL>(true);
		UrlInterface_DescribeIO = UrlInterface_DescribeIO_GetPtr<IMPL>(true);
		UrlInterface_ConvertToUiNameWithRepository = UrlInterface_ConvertToUiNameWithRepository_GetPtr<IMPL>(0, true).first;
		UrlInterface_ConvertFromUiNameWithRepository = UrlInterface_ConvertFromUiNameWithRepository_GetPtr<IMPL>(true);
	}
};

struct UrlInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void UrlInterface_Free(const UrlInterface* object) { return C::Free(object); }
		static UrlInterface* UrlInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static UrlInterface* UrlInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const UrlInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetScheme, UrlInterface, const, (const UrlScheme&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetScheme(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetScheme, UrlInterface,, (Result<void>), const UrlScheme& scheme) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetScheme(scheme); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_Append, UrlInterface,, (Result<void>), const String& name) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->Append(name); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_Append_1, UrlInterface,, (Result<void>), const Url& relativeUrl) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->Append(relativeUrl); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_RemoveName, UrlInterface,, (Result<void>)) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->RemoveName(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetEmbeddedUrl, UrlInterface, const, (Url)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetEmbeddedUrl(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetEmbeddedUrl, UrlInterface,, (Result<void>), const Url& url) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetEmbeddedUrl(url); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetName, UrlInterface, const, (String)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetName(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetName, UrlInterface,, (Result<void>), const String& name) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetName(name); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetDirectory, UrlInterface, const, (Url)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetDirectory(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetPath, UrlInterface,, (Result<void>), const String& path) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetPath(path); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetPath_1, UrlInterface,, (Result<void>), const String& path, Bool convertWindowsBackslashes) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetPath(path, convertWindowsBackslashes); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetPath, UrlInterface, const, (const String&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetPath(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetSystemPath, UrlInterface,, (Result<void>), const String& path) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetSystemPath(path); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetSystemPath, UrlInterface, const, (Result<String>)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetSystemPath(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetUrl, UrlInterface,, (Result<void>), const String& urlString, Bool enableDefaultFallbackScheme) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetUrl(urlString, enableDefaultFallbackScheme); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetUrl, UrlInterface, const, (String)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetUrl(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetAuthority, UrlInterface,, (Result<void>), const String& authority) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetAuthority(authority); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetAuthority_1, UrlInterface,, (Result<void>), const Url& authority) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetAuthority(authority); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetAuthority, UrlInterface, const, (const Url&)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetAuthority(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetComponents, UrlInterface, const, (Result<void>), const NonConstArray<String>& parts) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetComponents(parts); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetRelativeUrl, UrlInterface, const, (Result<Url>), const Url& basePath) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetRelativeUrl(basePath); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetSuffix, UrlInterface, const, (String)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetSuffix(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_CheckSuffix, UrlInterface, const, (Bool), const String& suffix) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->CheckSuffix(suffix); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetSuffix, UrlInterface,, (Result<void>), const String& suffix) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetSuffix(suffix); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_ClearSuffix, UrlInterface,, (void)) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->ClearSuffix(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_IsEmpty, UrlInterface, const, (Bool)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->IsEmpty(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_Compare, UrlInterface, const, (COMPARERESULT), const UrlInterface* name, URLCOMPARE mode) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->Compare(name, mode); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetData, UrlInterface, const, (Result<Data>), const ConstDataPtr& key) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetData(key); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetData, UrlInterface,, (Result<void>), ForwardingDataPtr&& key, const Data& data, Bool persistent) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetData(std::forward<ForwardingDataPtr>(key), data, persistent); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetData_1, UrlInterface,, (Result<void>), ForwardingDataPtr&& key, Data&& data, Bool persistent) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetData(std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_EraseData, UrlInterface,, (Result<void>), ForwardingDataPtr&& key, Bool persistent) { return C::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->EraseData(std::forward<ForwardingDataPtr>(key), persistent); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_ToString, UrlInterface, const, (String), const FormatStatement* formatStatement) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->ToString(formatStatement); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_ToCString, UrlInterface, const, (CString)) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->ToCString(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_ConvertToUiName, UrlInterface, const, (Result<String>), CONVERTTOUINAMEFLAGS flags) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->ConvertToUiName(flags); }
		static Result<Url> UrlInterface_ConvertFromUiName(const String& str) { return C::ConvertFromUiName(str); }
		static Result<void> UrlInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_ConvertToUiNameWithRepository, UrlInterface, const, (Result<String>), CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) { return C::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->ConvertToUiNameWithRepository(flags, lookupRepository); }
		static Result<Url> UrlInterface_ConvertFromUiNameWithRepository(const String& str, const AssetRepositoryRef& lookupRepository) { return C::ConvertFromUiNameWithRepository(str, lookupRepository); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Free(const UrlInterface* object) -> void
{
	return MTable::_instance.UrlInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Alloc(const maxon::SourceLocation& allocLocation) -> UrlInterface*
{
	return MTable::_instance.UrlInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Alloc(const maxon::SourceLocation& allocLocation, const UrlInterface& object) -> UrlInterface*
{
	return MTable::_instance.UrlInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetScheme() const -> const UrlScheme&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_GetScheme);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetScheme(const UrlScheme& scheme) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_SetScheme, scheme);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Append(const String& name) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_Append, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Append(const Url& relativeUrl) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_Append_1, relativeUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::RemoveName() -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_RemoveName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetEmbeddedUrl() const -> Url
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_GetEmbeddedUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetEmbeddedUrl(const Url& url) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_SetEmbeddedUrl, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetName() const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_GetName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetName(const String& name) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_SetName, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetDirectory() const -> Url
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_GetDirectory);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetPath(const String& path) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_SetPath, path);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetPath(const String& path, Bool convertWindowsBackslashes) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_SetPath_1, path, convertWindowsBackslashes);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetPath() const -> const String&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_GetPath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetSystemPath(const String& path) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_SetSystemPath, path);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetSystemPath() const -> Result<String>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_GetSystemPath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetUrl(const String& urlString, Bool enableDefaultFallbackScheme) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_SetUrl, urlString, enableDefaultFallbackScheme);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetUrl() const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_GetUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetAuthority(const String& authority) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_SetAuthority, authority);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetAuthority(const Url& authority) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_SetAuthority_1, authority);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetAuthority() const -> const Url&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_GetAuthority);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetComponents(const NonConstArray<String>& parts) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_GetComponents, parts);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetRelativeUrl(const Url& basePath) const -> Result<Url>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_GetRelativeUrl, basePath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetSuffix() const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_GetSuffix);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::CheckSuffix(const String& suffix) const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_CheckSuffix, suffix);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetSuffix(const String& suffix) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_SetSuffix, suffix);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::ClearSuffix() -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_ClearSuffix);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::IsEmpty() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_IsEmpty);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Compare(const UrlInterface* name, URLCOMPARE mode) const -> COMPARERESULT
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_Compare, name, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_GetData, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_SetData, std::forward<ForwardingDataPtr>(key), data, persistent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_SetData_1, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::EraseData(ForwardingDataPtr&& key, Bool persistent) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_EraseData, std::forward<ForwardingDataPtr>(key), persistent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_ToString, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::ToCString() const -> CString
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_ToCString);
}
[[deprecated("use ConvertToUiNameWithRepository instead")]] MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::ConvertToUiName(CONVERTTOUINAMEFLAGS flags) const -> Result<String>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_ConvertToUiName, flags);
}
[[deprecated("use ConvertFromUiNameWithRepository instead")]] MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::ConvertFromUiName(const String& str) -> Result<Url>
{
	return MTable::_instance.UrlInterface_ConvertFromUiName(str);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance.UrlInterface_DescribeIO(stream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::ConvertToUiNameWithRepository(CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) const -> Result<String>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_ConvertToUiNameWithRepository, flags, lookupRepository);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::ConvertFromUiNameWithRepository(const String& str, const AssetRepositoryRef& lookupRepository) -> Result<Url>
{
	return MTable::_instance.UrlInterface_ConvertFromUiNameWithRepository(str, lookupRepository);
}

auto UrlInterface::Reference::Create() -> maxon::ResultMemT<Url>
{
	UrlInterface* res_ = UrlInterface::Alloc(MAXON_SOURCE_LOCATION);
	return Url(maxon::ForwardResultPtr<UrlInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetScheme() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const UrlScheme&>, const UrlScheme&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const UrlScheme&>, const UrlScheme&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const UrlScheme&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetScheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetScheme(const UrlScheme& scheme) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetScheme, scheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetScheme(const UrlScheme& scheme) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetScheme, scheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::Append(const String& name) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); } 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_Append, name);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::Append(const String& name) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_Append, name);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::Append(const Url& relativeUrl) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); } 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_Append_1, relativeUrl);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::Append(const Url& relativeUrl) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_Append_1, relativeUrl);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::RemoveName() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_RemoveName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::RemoveName() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_RemoveName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetEmbeddedUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetEmbeddedUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetEmbeddedUrl(const Url& url) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetEmbeddedUrl, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetEmbeddedUrl(const Url& url) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetEmbeddedUrl, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetName(const String& name) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetName, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetName(const String& name) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetName, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetDirectory() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetDirectory));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetPath(const String& path) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetPath, path));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetPath(const String& path) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetPath, path));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetPath(const String& path, Bool convertWindowsBackslashes) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetPath_1, path, convertWindowsBackslashes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetPath(const String& path, Bool convertWindowsBackslashes) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetPath_1, path, convertWindowsBackslashes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetPath() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetPath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetSystemPath(const String& path) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetSystemPath, path));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetSystemPath(const String& path) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetSystemPath, path));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetSystemPath() const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetSystemPath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetUrl(const String& urlString, Bool enableDefaultFallbackScheme) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetUrl, urlString, enableDefaultFallbackScheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetUrl(const String& urlString, Bool enableDefaultFallbackScheme) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetUrl, urlString, enableDefaultFallbackScheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetAuthority(const String& authority) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetAuthority, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetAuthority(const String& authority) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetAuthority, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetAuthority(const Url& authority) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetAuthority_1, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetAuthority(const Url& authority) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetAuthority_1, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetAuthority() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetAuthority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetComponents(const NonConstArray<String>& parts) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetComponents, parts));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetRelativeUrl(const Url& basePath) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetRelativeUrl, basePath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetSuffix() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetSuffix));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::CheckSuffix(const String& suffix) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_CheckSuffix, suffix));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetSuffix(const String& suffix) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetSuffix, suffix));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetSuffix(const String& suffix) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetSuffix, suffix));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::ClearSuffix() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_ClearSuffix);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::ClearSuffix() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_ClearSuffix);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return true; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_IsEmpty));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::Compare(const UrlInterface* name, URLCOMPARE mode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_Compare, name, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetData, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetData, std::forward<ForwardingDataPtr>(key), data, persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetData, std::forward<ForwardingDataPtr>(key), data, persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetData_1, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetData_1, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::EraseData(ForwardingDataPtr&& key, Bool persistent) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_EraseData, std::forward<ForwardingDataPtr>(key), persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::EraseData(ForwardingDataPtr&& key, Bool persistent) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_EraseData, std::forward<ForwardingDataPtr>(key), persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoDetect() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<IODETECT>, IODETECT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<IODETECT>, IODETECT>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<IODETECT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->IoDetect());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::OpenConnection() const -> typename maxon::SFINAEHelper<Result<IoConnectionRef>, S>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename maxon::SFINAEHelper<Result<IoConnectionRef>, S>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenConnection());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::OpenInputStream(OPENSTREAMFLAGS flags) const -> typename maxon::SFINAEHelper<Result<InputStreamRef>, S>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename maxon::SFINAEHelper<Result<InputStreamRef>, S>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenInputStream(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::OpenOutputStream(OPENSTREAMFLAGS flags) const -> typename maxon::SFINAEHelper<Result<OutputStreamRef>, S>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename maxon::SFINAEHelper<Result<OutputStreamRef>, S>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenOutputStream(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::OpenInOutputStream(OPENSTREAMFLAGS flags) const -> typename maxon::SFINAEHelper<Result<InOutputStreamRef>, S>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename maxon::SFINAEHelper<Result<InOutputStreamRef>, S>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenInOutputStream(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetBrowseIterator(GETBROWSEITERATORFLAGS flags) const -> typename maxon::SFINAEHelper<Result<IoBrowseRef>, S>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename maxon::SFINAEHelper<Result<IoBrowseRef>, S>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->GetBrowseIterator(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoGetAttributes() const -> Result<IOATTRIBUTES>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<IOATTRIBUTES>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoGetAttributes());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoSetAttributes(flags, mask));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoGetTime(IOTIMEMODE mode) const -> typename maxon::SFINAEHelper<Result<UniversalDateTime>, S>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename maxon::SFINAEHelper<Result<UniversalDateTime>, S>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->IoGetTime(mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoSetTime(mode, dateTime));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoDelete(Bool force, Bool recursive) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoDelete(force, recursive));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoCreateDirectory(createParents, createdDirs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoCopyFile(destName, overwrite, removeReadOnly, progress));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoMove(const Url& destName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoMove(destName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoRename(const Url& newName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoRename(newName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoGetFreeVolumeSpace(availableBytes, totalBytes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoShowInOS(IOSHOWINOSFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoShowInOS(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::Normalize(NORMALIZEFLAGS flags) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Normalize(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoNormalize(NORMALIZEFLAGS flags) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoNormalize(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::operator +(const String& s) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->operator +(s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::operator +(const Url& s) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->operator +(s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_ToString, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::ToCString() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<CString>, CString>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<CString>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_ToCString));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::ConvertToUiName(CONVERTTOUINAMEFLAGS flags) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_ConvertToUiName, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::ConvertFromUiName(const String& str) -> Result<Url>
{
	return (MTable::_instance.UrlInterface_ConvertFromUiName(str));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return (MTable::_instance.UrlInterface_DescribeIO(stream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::ConvertToUiNameWithRepository(CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_ConvertToUiNameWithRepository, flags, lookupRepository));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::ConvertFromUiNameWithRepository(const String& str, const AssetRepositoryRef& lookupRepository) -> Result<Url>
{
	return (MTable::_instance.UrlInterface_ConvertFromUiNameWithRepository(str, lookupRepository));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_url)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UrlInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UrlInterface() { new (s_ui_maxon_UrlInterface) maxon::EntityUse(UrlInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/url.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UrlInterface(UrlInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/url.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#ifdef URLSCHEME_UNC_ENABLED
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

