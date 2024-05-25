#if 1
namespace maxon
{
	namespace enum65
	{
		enum class GETBROWSEITERATORFLAGS
		{
			NONE = 0,					///< No flags specified.
			NOERRORONOPEN = 1 << 0,		///< Will return no error when opening a non existing directory but will return an empty browse handler with no entries.
			RESOLVEPATHS = 1 << 1,		///< Attempts to resolve paths by invoking @ref maxon::UrlInterface::IoNormalize "IoNormalize" on them. Non-resolvable paths will not halt iteration and instead be passed through.
		} ;
		static const maxon::UInt64 GETBROWSEITERATORFLAGS_values[] = {maxon::UInt64(enum65::GETBROWSEITERATORFLAGS::NONE), maxon::UInt64(enum65::GETBROWSEITERATORFLAGS::NOERRORONOPEN), maxon::UInt64(enum65::GETBROWSEITERATORFLAGS::RESOLVEPATHS)};
		static const maxon::EnumInfo GETBROWSEITERATORFLAGS_info{"GETBROWSEITERATORFLAGS", SIZEOF(GETBROWSEITERATORFLAGS), true, "NONE\0NOERRORONOPEN\0RESOLVEPATHS\0", GETBROWSEITERATORFLAGS_values, std::extent<decltype(GETBROWSEITERATORFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_GETBROWSEITERATORFLAGS65(){ return enum65::GETBROWSEITERATORFLAGS_info; }
	namespace enum78
	{
		enum class CONVERTTOUINAMEFLAGS
		{
			NONE = 0,									///< Default: returns directory + name.
			NAMEONLY = 1 << 0,				///< Returns only the name without directory + optional version.
			DIRECTORYONLY = 1 << 1,		///< Returns only the directory without name.
			ADDVERSION = 1 << 2,			///< Adds the version in front of the suffix.
			CLEARSUFFIX = 1 << 3,			///< Remove the suffix from the name.
			DONTADDDATABASE = 1 << 4,	///< Don't add the Database name in brackets behind the name.
		} ;
		static const maxon::UInt64 CONVERTTOUINAMEFLAGS_values[] = {maxon::UInt64(enum78::CONVERTTOUINAMEFLAGS::NONE), maxon::UInt64(enum78::CONVERTTOUINAMEFLAGS::NAMEONLY), maxon::UInt64(enum78::CONVERTTOUINAMEFLAGS::DIRECTORYONLY), maxon::UInt64(enum78::CONVERTTOUINAMEFLAGS::ADDVERSION), maxon::UInt64(enum78::CONVERTTOUINAMEFLAGS::CLEARSUFFIX), maxon::UInt64(enum78::CONVERTTOUINAMEFLAGS::DONTADDDATABASE)};
		static const maxon::EnumInfo CONVERTTOUINAMEFLAGS_info{"CONVERTTOUINAMEFLAGS", SIZEOF(CONVERTTOUINAMEFLAGS), true, "NONE\0NAMEONLY\0DIRECTORYONLY\0ADDVERSION\0CLEARSUFFIX\0DONTADDDATABASE\0", CONVERTTOUINAMEFLAGS_values, std::extent<decltype(CONVERTTOUINAMEFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_CONVERTTOUINAMEFLAGS78(){ return enum78::CONVERTTOUINAMEFLAGS_info; }
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
		"SetPath@b4bc6d7668aa1693\0" // Result<void> SetPath(const String& path, Bool convertWindowsBackslashes)
		"GetPath@8fd391aee7382314\0" // const String& GetPath() const
		"SetSystemPath@d85d74e087a2f051\0" // Result<void> SetSystemPath(const String& path)
		"GetSystemPath@74a82a5700c59c60\0" // Result<String> GetSystemPath() const
		"SetUrl@b4bc6d7668aa1693\0" // Result<void> SetUrl(const String& urlString, Bool enableDefaultFallbackScheme)
		"GetUrl@b8f12dfa16054f01\0" // String GetUrl() const
		"GetUrlEncoded@b8f12dfa16054f01\0" // String GetUrlEncoded() const
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
		"EraseData@cfb9ef0763cd71f0\0" // Result<void> EraseData(ForwardingDataPtr&& key, Bool persistent)
		"ToString@a73a45c584c879d4\0" // String ToString(const FormatStatement* formatStatement) const
		"ToCString@bcd5f72447348886\0" // CString ToCString() const
		"DescribeIO@fe3f1bd5a495cc32\0" // Result<void> DescribeIO(const DataSerializeInterface& stream)
		"ConvertToUiName@714e4aba89b8b630\0" // Result<String> ConvertToUiName(CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) const
		"ConvertFromUiName@dfeae62395c9e70b\0" // Result<Url> ConvertFromUiName(const String& str, const AssetRepositoryRef& lookupRepository)
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
		const UrlScheme& GetScheme() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetScheme(); return HXXRET3(UNRESOLVED, const UrlScheme&);}
		Result<void> SetScheme(const UrlScheme& scheme) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetScheme(scheme); return HXXRET1(UNRESOLVED);}
		Result<void> Append(const String& name) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->Append(name); return HXXRET1(UNRESOLVED);}
		Result<void> Append(const Url& relativeUrl) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->Append(relativeUrl); return HXXRET1(UNRESOLVED);}
		Result<void> RemoveName() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->RemoveName(); return HXXRET1(UNRESOLVED);}
		Url GetEmbeddedUrl() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetEmbeddedUrl(); return HXXRET3(UNRESOLVED, Url);}
		Result<void> SetEmbeddedUrl(const Url& url) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetEmbeddedUrl(url); return HXXRET1(UNRESOLVED);}
		String GetName() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetName(); return HXXRET3(UNRESOLVED, String);}
		Result<void> SetName(const String& name) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetName(name); return HXXRET1(UNRESOLVED);}
		Url GetDirectory() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetDirectory(); return HXXRET3(UNRESOLVED, Url);}
		Result<void> SetPath(const String& path, Bool convertWindowsBackslashes) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetPath(path, convertWindowsBackslashes); return HXXRET1(UNRESOLVED);}
		const String& GetPath() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetPath(); return HXXRET3(UNRESOLVED, const String&);}
		Result<void> SetSystemPath(const String& path) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetSystemPath(path); return HXXRET1(UNRESOLVED);}
		Result<String> GetSystemPath() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UrlInterface*) this)->GetSystemPath(); return HXXRET1(UNRESOLVED);}
		Result<void> SetUrl(const String& urlString, Bool enableDefaultFallbackScheme) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetUrl(urlString, enableDefaultFallbackScheme); return HXXRET1(UNRESOLVED);}
		String GetUrl() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetUrl(); return HXXRET3(UNRESOLVED, String);}
		String GetUrlEncoded() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetUrlEncoded(); return HXXRET3(UNRESOLVED, String);}
		Result<void> SetAuthority(const String& authority) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetAuthority(authority); return HXXRET1(UNRESOLVED);}
		Result<void> SetAuthority(const Url& authority) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetAuthority(authority); return HXXRET1(UNRESOLVED);}
		const Url& GetAuthority() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetAuthority(); return HXXRET3(UNRESOLVED, const Url&);}
		Result<void> GetComponents(const NonConstArray<String>& parts) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UrlInterface*) this)->GetComponents(parts); return HXXRET1(UNRESOLVED);}
		Result<Url> GetRelativeUrl(const Url& basePath) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UrlInterface*) this)->GetRelativeUrl(basePath); return HXXRET1(UNRESOLVED);}
		String GetSuffix() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->GetSuffix(); return HXXRET3(UNRESOLVED, String);}
		Bool CheckSuffix(const String& suffix) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->CheckSuffix(suffix); return maxon::PrivateLogNullptrError(false);}
		Result<void> SetSuffix(const String& suffix) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetSuffix(suffix); return HXXRET1(UNRESOLVED);}
		void ClearSuffix() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((UrlInterface*) this)->ClearSuffix(); return maxon::PrivateLogNullptrError();}
		Bool IsEmpty() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->IsEmpty(); return true;}
		COMPARERESULT Compare(const UrlInterface* name, URLCOMPARE mode) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->Compare(name, mode); return HXXRET3(UNRESOLVED, COMPARERESULT);}
		Result<Data> GetData(const ConstDataPtr& key) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UrlInterface*) this)->GetData(key); return HXXRET1(UNRESOLVED);}
		Result<void> SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetData(std::forward<ForwardingDataPtr>(key), data, persistent); return HXXRET1(UNRESOLVED);}
		Result<void> SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->SetData(std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent); return HXXRET1(UNRESOLVED);}
		Result<void> EraseData(ForwardingDataPtr&& key, Bool persistent) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((UrlInterface*) this)->EraseData(std::forward<ForwardingDataPtr>(key), persistent); return HXXRET1(UNRESOLVED);}
		String ToString(const FormatStatement* formatStatement) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->ToString(formatStatement); return HXXRET3(UNRESOLVED, String);}
		CString ToCString() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const UrlInterface*) this)->ToCString(); return HXXRET3(UNRESOLVED, CString);}
		static Result<void> DescribeIO(const DataSerializeInterface& stream) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return UrlInterface::DescribeIO(stream); return HXXRET1(UNRESOLVED);}
		Result<String> ConvertToUiName(CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const UrlInterface*) this)->ConvertToUiName(flags, lookupRepository); return HXXRET1(UNRESOLVED);}
		static Result<Url> ConvertFromUiName(const String& str, const AssetRepositoryRef& lookupRepository) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return UrlInterface::ConvertFromUiName(str, lookupRepository); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE UrlInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<UrlInterface*>::value,
		maxon::details::UnresolvedReturnType<UrlInterface*>::value,
		maxon::details::UnresolvedReturnType<const UrlScheme&>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Url>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<String>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Url>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<const String&>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<String>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<String>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<String>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<const Url&>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Url>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<String>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<COMPARERESULT>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Data>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<String>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<CString>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<String>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<Url>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool UrlInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->UrlInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->UrlInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->UrlInterface_Alloc_1 = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_Alloc_1), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_Alloc_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const UrlScheme&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_GetScheme = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetScheme), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetScheme);
		#else
		tbl->UrlInterface_GetScheme = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetScheme), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetScheme);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_SetScheme = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetScheme), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetScheme);
		#else
		tbl->UrlInterface_SetScheme = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetScheme), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetScheme);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_Append = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_Append), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_Append);
		#else
		tbl->UrlInterface_Append = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_Append), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_Append);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_Append_1 = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_Append_1), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_Append_1);
		#else
		tbl->UrlInterface_Append_1 = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_Append_1), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_Append_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_RemoveName = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_RemoveName), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_RemoveName);
		#else
		tbl->UrlInterface_RemoveName = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_RemoveName), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_RemoveName);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Url>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_GetEmbeddedUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetEmbeddedUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetEmbeddedUrl);
		#else
		tbl->UrlInterface_GetEmbeddedUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetEmbeddedUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetEmbeddedUrl);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_SetEmbeddedUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetEmbeddedUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetEmbeddedUrl);
		#else
		tbl->UrlInterface_SetEmbeddedUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetEmbeddedUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetEmbeddedUrl);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_GetName = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetName), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetName);
		#else
		tbl->UrlInterface_GetName = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetName), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetName);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_SetName = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetName), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetName);
		#else
		tbl->UrlInterface_SetName = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetName), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetName);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Url>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_GetDirectory = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetDirectory), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetDirectory);
		#else
		tbl->UrlInterface_GetDirectory = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetDirectory), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetDirectory);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_SetPath = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetPath), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetPath);
		#else
		tbl->UrlInterface_SetPath = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetPath), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetPath);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const String&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_GetPath = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetPath), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetPath);
		#else
		tbl->UrlInterface_GetPath = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetPath), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetPath);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_SetSystemPath = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetSystemPath), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetSystemPath);
		#else
		tbl->UrlInterface_SetSystemPath = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetSystemPath), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetSystemPath);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<String>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_GetSystemPath = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetSystemPath), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetSystemPath);
		#else
		tbl->UrlInterface_GetSystemPath = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetSystemPath), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetSystemPath);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_SetUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetUrl);
		#else
		tbl->UrlInterface_SetUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetUrl);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_GetUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetUrl);
		#else
		tbl->UrlInterface_GetUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetUrl);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_GetUrlEncoded = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetUrlEncoded), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetUrlEncoded);
		#else
		tbl->UrlInterface_GetUrlEncoded = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetUrlEncoded), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetUrlEncoded);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_SetAuthority = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetAuthority), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetAuthority);
		#else
		tbl->UrlInterface_SetAuthority = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetAuthority), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetAuthority);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_SetAuthority_1 = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetAuthority_1), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetAuthority_1);
		#else
		tbl->UrlInterface_SetAuthority_1 = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetAuthority_1), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetAuthority_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const Url&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_GetAuthority = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetAuthority), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetAuthority);
		#else
		tbl->UrlInterface_GetAuthority = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetAuthority), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetAuthority);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_GetComponents = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetComponents), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetComponents);
		#else
		tbl->UrlInterface_GetComponents = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetComponents), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetComponents);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Url>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_GetRelativeUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetRelativeUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetRelativeUrl);
		#else
		tbl->UrlInterface_GetRelativeUrl = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetRelativeUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetRelativeUrl);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_GetSuffix = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetSuffix), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetSuffix);
		#else
		tbl->UrlInterface_GetSuffix = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetSuffix), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetSuffix);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->UrlInterface_CheckSuffix = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_CheckSuffix), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_CheckSuffix);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_SetSuffix = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetSuffix), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetSuffix);
		#else
		tbl->UrlInterface_SetSuffix = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetSuffix), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetSuffix);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->UrlInterface_ClearSuffix = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_ClearSuffix), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_ClearSuffix);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->UrlInterface_IsEmpty = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_IsEmpty), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_IsEmpty);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<COMPARERESULT>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_Compare = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_Compare), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_Compare);
		#else
		tbl->UrlInterface_Compare = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_Compare), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_Compare);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Data>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_GetData = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetData), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetData);
		#else
		tbl->UrlInterface_GetData = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_GetData), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_GetData);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_SetData = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetData), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetData);
		#else
		tbl->UrlInterface_SetData = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetData), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetData);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_SetData_1 = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetData_1), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetData_1);
		#else
		tbl->UrlInterface_SetData_1 = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_SetData_1), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_SetData_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_EraseData = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_EraseData), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_EraseData);
		#else
		tbl->UrlInterface_EraseData = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_EraseData), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_EraseData);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_ToString = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_ToString);
		#else
		tbl->UrlInterface_ToString = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_ToString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<CString>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_ToCString = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_ToCString), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_ToCString);
		#else
		tbl->UrlInterface_ToCString = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_ToCString), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_ToCString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_DescribeIO = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_DescribeIO), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_DescribeIO);
		#else
		tbl->UrlInterface_DescribeIO = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_DescribeIO), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_DescribeIO);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<String>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_ConvertToUiName = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_ConvertToUiName), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_ConvertToUiName);
		#else
		tbl->UrlInterface_ConvertToUiName = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_ConvertToUiName), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_ConvertToUiName);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Url>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->UrlInterface_ConvertFromUiName = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_ConvertFromUiName), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_ConvertFromUiName);
		#else
		tbl->UrlInterface_ConvertFromUiName = PRIVATE_MAXON_MF_CAST(decltype(UrlInterface_ConvertFromUiName), &Hxx2::Wrapper<Hxx2::Unresolved>::UrlInterface_ConvertFromUiName);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(UrlInterface, "net.maxon.interface.url", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int UrlInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<COMPARERESULT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<CString>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<IODETECT>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<UniqueHash>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<Url>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const String&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const Url&>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const UrlScheme&>(OVERLOAD_MAX_RANK)
		;
	}
#ifdef URLSCHEME_UNC_ENABLED
#endif
	MAXON_REGISTRY_REGISTER(UrlIoShowInOSRegistry);
}
#endif
static maxon::details::ForceEvaluation s_forceEval_url(0
	| maxon::UrlInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
