
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
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
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
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetPath, SetPath, false, UrlInterface,, (Result<void>), const String& path, Bool convertWindowsBackslashes);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetPath, GetPath, false, UrlInterface, const, (const String&));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetSystemPath, SetSystemPath, false, UrlInterface,, (Result<void>), const String& path);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetSystemPath, GetSystemPath, false, UrlInterface, const, (Result<String>));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_SetUrl, SetUrl, false, UrlInterface,, (Result<void>), const String& urlString, Bool enableDefaultFallbackScheme);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetUrl, GetUrl, false, UrlInterface, const, (String));
	PRIVATE_MAXON_MF_POINTER(UrlInterface_GetUrlEncoded, GetUrlEncoded, false, UrlInterface, const, (String));
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
	PRIVATE_MAXON_SF_POINTER(UrlInterface_DescribeIO, DescribeIO, MAXON_EXPAND_VA_ARGS, (Result<void>), const DataSerializeInterface& stream);
	PRIVATE_MAXON_MF_POINTER(UrlInterface_ConvertToUiName, ConvertToUiName, false, UrlInterface, const, (Result<String>), CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository);
	PRIVATE_MAXON_SF_POINTER(UrlInterface_ConvertFromUiName, ConvertFromUiName, MAXON_EXPAND_VA_ARGS, (Result<Url>), const String& str, const AssetRepositoryRef& lookupRepository);
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
		UrlInterface_GetPath = UrlInterface_GetPath_GetPtr<IMPL>(0, true).first;
		UrlInterface_SetSystemPath = UrlInterface_SetSystemPath_GetPtr<IMPL>(0, true).first;
		UrlInterface_GetSystemPath = UrlInterface_GetSystemPath_GetPtr<IMPL>(0, true).first;
		UrlInterface_SetUrl = UrlInterface_SetUrl_GetPtr<IMPL>(0, true).first;
		UrlInterface_GetUrl = UrlInterface_GetUrl_GetPtr<IMPL>(0, true).first;
		UrlInterface_GetUrlEncoded = UrlInterface_GetUrlEncoded_GetPtr<IMPL>(0, true).first;
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
		UrlInterface_DescribeIO = UrlInterface_DescribeIO_GetPtr<IMPL>(true);
		UrlInterface_ConvertToUiName = UrlInterface_ConvertToUiName_GetPtr<IMPL>(0, true).first;
		UrlInterface_ConvertFromUiName = UrlInterface_ConvertFromUiName_GetPtr<IMPL>(true);
	}
};

struct UrlInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static void UrlInterface_Free(const UrlInterface* object) { return S::Free(object); }
		static UrlInterface* UrlInterface_Alloc(const maxon::SourceLocation& allocLocation) { return S::Alloc(allocLocation); }
		static UrlInterface* UrlInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const UrlInterface& object) { return S::Alloc(allocLocation, ((const S&) object)); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetScheme, UrlInterface, const, (const UrlScheme&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetScheme(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetScheme, UrlInterface,, (Result<void>), const UrlScheme& scheme) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetScheme(scheme); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_Append, UrlInterface,, (Result<void>), const String& name) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->Append(name); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_Append_1, UrlInterface,, (Result<void>), const Url& relativeUrl) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->Append(relativeUrl); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_RemoveName, UrlInterface,, (Result<void>)) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->RemoveName(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetEmbeddedUrl, UrlInterface, const, (Url)) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetEmbeddedUrl(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetEmbeddedUrl, UrlInterface,, (Result<void>), const Url& url) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetEmbeddedUrl(url); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetName, UrlInterface, const, (String)) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetName(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetName, UrlInterface,, (Result<void>), const String& name) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetName(name); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetDirectory, UrlInterface, const, (Url)) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetDirectory(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetPath, UrlInterface,, (Result<void>), const String& path, Bool convertWindowsBackslashes) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetPath(path, convertWindowsBackslashes); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetPath, UrlInterface, const, (const String&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetPath(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetSystemPath, UrlInterface,, (Result<void>), const String& path) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetSystemPath(path); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetSystemPath, UrlInterface, const, (Result<String>)) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetSystemPath(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetUrl, UrlInterface,, (Result<void>), const String& urlString, Bool enableDefaultFallbackScheme) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetUrl(urlString, enableDefaultFallbackScheme); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetUrl, UrlInterface, const, (String)) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetUrl(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetUrlEncoded, UrlInterface, const, (String)) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetUrlEncoded(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetAuthority, UrlInterface,, (Result<void>), const String& authority) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetAuthority(authority); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetAuthority_1, UrlInterface,, (Result<void>), const Url& authority) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetAuthority(authority); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetAuthority, UrlInterface, const, (const Url&)) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetAuthority(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetComponents, UrlInterface, const, (Result<void>), const NonConstArray<String>& parts) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetComponents(parts); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetRelativeUrl, UrlInterface, const, (Result<Url>), const Url& basePath) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetRelativeUrl(basePath); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetSuffix, UrlInterface, const, (String)) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetSuffix(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_CheckSuffix, UrlInterface, const, (Bool), const String& suffix) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->CheckSuffix(suffix); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetSuffix, UrlInterface,, (Result<void>), const String& suffix) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetSuffix(suffix); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_ClearSuffix, UrlInterface,, (void)) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->ClearSuffix(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_IsEmpty, UrlInterface, const, (Bool)) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->IsEmpty(); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_Compare, UrlInterface, const, (COMPARERESULT), const UrlInterface* name, URLCOMPARE mode) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->Compare(name, mode); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_GetData, UrlInterface, const, (Result<Data>), const ConstDataPtr& key) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->GetData(key); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetData, UrlInterface,, (Result<void>), ForwardingDataPtr&& key, const Data& data, Bool persistent) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetData(std::forward<ForwardingDataPtr>(key), data, persistent); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_SetData_1, UrlInterface,, (Result<void>), ForwardingDataPtr&& key, Data&& data, Bool persistent) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->SetData(std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_EraseData, UrlInterface,, (Result<void>), ForwardingDataPtr&& key, Bool persistent) { return S::Get(PRIVATE_MAXON_MF_THIS(UrlInterface))->EraseData(std::forward<ForwardingDataPtr>(key), persistent); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_ToString, UrlInterface, const, (String), const FormatStatement* formatStatement) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->ToString(formatStatement); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_ToCString, UrlInterface, const, (CString)) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->ToCString(); }
		static Result<void> UrlInterface_DescribeIO(const DataSerializeInterface& stream) { return S::DescribeIO(stream); }
		PRIVATE_MAXON_MF_WRAPPER(UrlInterface_ConvertToUiName, UrlInterface, const, (Result<String>), CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) { return S::Get(PRIVATE_MAXON_MF_THIS(const UrlInterface))->ConvertToUiName(flags, lookupRepository); }
		static Result<Url> UrlInterface_ConvertFromUiName(const String& str, const AssetRepositoryRef& lookupRepository) { return S::ConvertFromUiName(str, lookupRepository); }
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
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetPath(const String& path, Bool convertWindowsBackslashes) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_SetPath, path, convertWindowsBackslashes);
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
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetUrlEncoded() const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_GetUrlEncoded);
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
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance.UrlInterface_DescribeIO(stream);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::ConvertToUiName(CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) const -> Result<String>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.UrlInterface_ConvertToUiName, flags, lookupRepository);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::ConvertFromUiName(const String& str, const AssetRepositoryRef& lookupRepository) -> Result<Url>
{
	return MTable::_instance.UrlInterface_ConvertFromUiName(str, lookupRepository);
}

auto UrlInterface::Reference::Create() -> maxon::ResultMemT<Url>
{
	UrlInterface* res_ = UrlInterface::Alloc(MAXON_SOURCE_LOCATION);
	return Url(maxon::ForwardResultPtr<UrlInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetScheme() const -> HXXADDRET2(const UrlScheme&)
{
	HXXRETURN0(HXXADDRET2(const UrlScheme&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const UrlScheme&)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetScheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetScheme(const UrlScheme& scheme) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetScheme, scheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetScheme(const UrlScheme& scheme) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetScheme, scheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::Append(const String& name) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>); HXXRES; HXXNONCONST(, , false, HXXRET2a(HXXRET1(NULLPTR))) 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_Append, name);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::Append(const String& name) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_Append, name);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::Append(const Url& relativeUrl) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>); HXXRES; HXXNONCONST(, , false, HXXRET2a(HXXRET1(NULLPTR))) 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_Append_1, relativeUrl);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::Append(const Url& relativeUrl) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	HXXRETURN1(maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	auto res_ = PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_Append_1, relativeUrl);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::RemoveName() const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_RemoveName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::RemoveName() -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_RemoveName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetEmbeddedUrl() const -> HXXADDRET2(Url)
{
	HXXRETURN0(HXXADDRET2(Url)); HXXRES; HXXCONST(HXXRET3(NULLPTR, Url)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetEmbeddedUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetEmbeddedUrl(const Url& url) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetEmbeddedUrl, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetEmbeddedUrl(const Url& url) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetEmbeddedUrl, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetName() const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(HXXRET3(NULLPTR, String)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetName(const String& name) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetName, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetName(const String& name) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetName, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetDirectory() const -> HXXADDRET2(Url)
{
	HXXRETURN0(HXXADDRET2(Url)); HXXRES; HXXCONST(HXXRET3(NULLPTR, Url)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetDirectory));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetPath(const String& path, Bool convertWindowsBackslashes) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetPath, path, convertWindowsBackslashes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetPath(const String& path, Bool convertWindowsBackslashes) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetPath, path, convertWindowsBackslashes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetPath() const -> HXXADDRET2(const String&)
{
	HXXRETURN0(HXXADDRET2(const String&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const String&)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetPath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetSystemPath(const String& path) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetSystemPath, path));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetSystemPath(const String& path) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetSystemPath, path));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetSystemPath() const -> Result<String>
{
	HXXRETURN0(Result<String>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetSystemPath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetUrl(const String& urlString, Bool enableDefaultFallbackScheme) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetUrl, urlString, enableDefaultFallbackScheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetUrl(const String& urlString, Bool enableDefaultFallbackScheme) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetUrl, urlString, enableDefaultFallbackScheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetUrl() const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(HXXRET3(NULLPTR, String)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetUrlEncoded() const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(HXXRET3(NULLPTR, String)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetUrlEncoded));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetAuthority(const String& authority) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetAuthority, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetAuthority(const String& authority) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetAuthority, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetAuthority(const Url& authority) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetAuthority_1, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetAuthority(const Url& authority) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetAuthority_1, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetAuthority() const -> HXXADDRET2(const Url&)
{
	HXXRETURN0(HXXADDRET2(const Url&)); HXXRES; HXXCONST(HXXRET3(NULLPTR, const Url&)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetAuthority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetComponents(const NonConstArray<String>& parts) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetComponents, parts));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetRelativeUrl(const Url& basePath) const -> Result<Url>
{
	HXXRETURN0(Result<Url>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetRelativeUrl, basePath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetSuffix() const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(HXXRET3(NULLPTR, String)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetSuffix));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::CheckSuffix(const String& suffix) const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_CheckSuffix, suffix));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetSuffix(const String& suffix) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetSuffix, suffix));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetSuffix(const String& suffix) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetSuffix, suffix));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::ClearSuffix() const -> HXXADDRET2(void)
{
	HXXRETURN0(HXXADDRET2(void)); HXXRES; HXXNONCONST(DebugStop(), , false, maxon::PrivateLogNullptrError()) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_ClearSuffix);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::ClearSuffix() -> HXXADDRET1(void)
{
	HXXRETURN0(HXXADDRET1(void)); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_ClearSuffix);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IsEmpty() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(true) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_IsEmpty));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IsPopulated() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (o_->IsPopulated());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::Compare(const UrlInterface* name, URLCOMPARE mode) const -> HXXADDRET2(COMPARERESULT)
{
	HXXRETURN0(HXXADDRET2(COMPARERESULT)); HXXRES; HXXCONST(HXXRET3(NULLPTR, COMPARERESULT)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_Compare, name, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	HXXRETURN0(Result<Data>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_GetData, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetData, std::forward<ForwardingDataPtr>(key), data, persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetData, std::forward<ForwardingDataPtr>(key), data, persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetData_1, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_SetData_1, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::EraseData(ForwardingDataPtr&& key, Bool persistent) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_EraseData, std::forward<ForwardingDataPtr>(key), persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::EraseData(ForwardingDataPtr&& key, Bool persistent) -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, MakeWritable(true)., true, HXXRET2a(HXXRET1(MAKE_WRITABLE_FAILED))) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_EraseData, std::forward<ForwardingDataPtr>(key), persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoDetect() const -> HXXADDRET2(IODETECT)
{
	HXXRETURN0(HXXADDRET2(IODETECT)); HXXRES; HXXCONST(HXXRET3(NULLPTR, IODETECT)) 
	return (o_->IoDetect());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::OpenConnection() const -> typename maxon::SFINAEHelper<Result<IoConnectionRef>, S>::type
{
	HXXRETURN0(typename maxon::SFINAEHelper<Result<IoConnectionRef>, S>::type); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenConnection());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::OpenInputStream(OPENSTREAMFLAGS flags) const -> typename maxon::SFINAEHelper<Result<InputStreamRef>, S>::type
{
	HXXRETURN0(typename maxon::SFINAEHelper<Result<InputStreamRef>, S>::type); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenInputStream(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::OpenOutputStream(OPENSTREAMFLAGS flags) const -> typename maxon::SFINAEHelper<Result<OutputStreamRef>, S>::type
{
	HXXRETURN0(typename maxon::SFINAEHelper<Result<OutputStreamRef>, S>::type); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenOutputStream(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::OpenInOutputStream(OPENSTREAMFLAGS flags) const -> typename maxon::SFINAEHelper<Result<InOutputStreamRef>, S>::type
{
	HXXRETURN0(typename maxon::SFINAEHelper<Result<InOutputStreamRef>, S>::type); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenInOutputStream(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetBrowseIterator(GETBROWSEITERATORFLAGS flags) const -> typename maxon::SFINAEHelper<Result<IoBrowseRef>, S>::type
{
	HXXRETURN0(typename maxon::SFINAEHelper<Result<IoBrowseRef>, S>::type); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->GetBrowseIterator(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoGetAttributes() const -> Result<IOATTRIBUTES>
{
	HXXRETURN0(Result<IOATTRIBUTES>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->IoGetAttributes());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->IoSetAttributes(flags, mask));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoGetTime(IOTIMEMODE mode) const -> typename maxon::SFINAEHelper<Result<UniversalDateTime>, S>::type
{
	HXXRETURN0(typename maxon::SFINAEHelper<Result<UniversalDateTime>, S>::type); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->IoGetTime(mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->IoSetTime(mode, dateTime));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoDelete(Bool force, Bool recursive) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->IoDelete(force, recursive));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->IoCreateDirectory(createParents, createdDirs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->IoCopyFile(destName, overwrite, removeReadOnly, progress));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoMove(const Url& destName) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->IoMove(destName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoRename(const Url& newName) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->IoRename(newName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->IoGetFreeVolumeSpace(availableBytes, totalBytes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoShowInOS(IOSHOWINOSFLAGS flags) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->IoShowInOS(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::Normalize(NORMALIZEFLAGS flags) const -> Result<Url>
{
	HXXRETURN0(Result<Url>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->Normalize(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoNormalize(NORMALIZEFLAGS flags) const -> Result<Url>
{
	HXXRETURN0(Result<Url>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->IoNormalize(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::operator +(const String& s) const -> Result<Url>
{
	HXXRETURN0(Result<Url>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->operator +(s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::operator +(const Url& s) const -> Result<Url>
{
	HXXRETURN0(Result<Url>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (o_->operator +(s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> HXXADDRET2(String)
{
	HXXRETURN0(HXXADDRET2(String)); HXXRES; HXXCONST(HXXRET3(NULLPTR, String)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_ToString, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::ToCString() const -> HXXADDRET2(CString)
{
	HXXRETURN0(HXXADDRET2(CString)); HXXRES; HXXCONST(HXXRET3(NULLPTR, CString)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_ToCString));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return (MTable::_instance.UrlInterface_DescribeIO(stream));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::ConvertToUiName(CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) const -> Result<String>
{
	HXXRETURN0(Result<String>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.UrlInterface_ConvertToUiName, flags, lookupRepository));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::ConvertFromUiName(const String& str, const AssetRepositoryRef& lookupRepository) -> Result<Url>
{
	return (MTable::_instance.UrlInterface_ConvertFromUiName(str, lookupRepository));
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

