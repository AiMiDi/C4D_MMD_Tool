
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
	void (*UrlInterface_Free) (const UrlInterface* object);
	UrlInterface* (*UrlInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	UrlInterface* (*UrlInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const UrlInterface& object);
	const UrlScheme& (*UrlInterface_GetScheme) (const UrlInterface* this_);
	Result<void> (*UrlInterface_SetScheme) (UrlInterface* this_, const UrlScheme& scheme);
	Result<void> (*UrlInterface_Append) (UrlInterface* this_, const String& name);
	Result<void> (*UrlInterface_Append_1) (UrlInterface* this_, const Url& relativeUrl);
	Result<void> (*UrlInterface_RemoveName) (UrlInterface* this_);
	Url (*UrlInterface_GetEmbeddedUrl) (const UrlInterface* this_);
	Result<void> (*UrlInterface_SetEmbeddedUrl) (UrlInterface* this_, const Url& url);
	String (*UrlInterface_GetName) (const UrlInterface* this_);
	Result<void> (*UrlInterface_SetName) (UrlInterface* this_, const String& name);
	Url (*UrlInterface_GetDirectory) (const UrlInterface* this_);
	Result<void> (*UrlInterface_SetPath) (UrlInterface* this_, const String& path);
	const String& (*UrlInterface_GetPath) (const UrlInterface* this_);
	Result<void> (*UrlInterface_SetSystemPath) (UrlInterface* this_, const String& path);
	Result<String> (*UrlInterface_GetSystemPath) (const UrlInterface* this_);
	Result<void> (*UrlInterface_SetUrl) (UrlInterface* this_, const String& urlString, Bool enableDefaultFallbackScheme);
	String (*UrlInterface_GetUrl) (const UrlInterface* this_);
	Result<void> (*UrlInterface_SetAuthority) (UrlInterface* this_, const String& authority);
	Result<void> (*UrlInterface_SetAuthority_1) (UrlInterface* this_, const Url& authority);
	const Url& (*UrlInterface_GetAuthority) (const UrlInterface* this_);
	Result<void> (*UrlInterface_GetComponents) (const UrlInterface* this_, const NonConstArray<String>& parts);
	Result<Url> (*UrlInterface_GetRelativeUrl) (const UrlInterface* this_, const Url& basePath);
	String (*UrlInterface_GetSuffix) (const UrlInterface* this_);
	Bool (*UrlInterface_CheckSuffix) (const UrlInterface* this_, const String& suffix);
	Result<void> (*UrlInterface_SetSuffix) (UrlInterface* this_, const String& suffix);
	void (*UrlInterface_ClearSuffix) (UrlInterface* this_);
	Bool (*UrlInterface_IsEmpty) (const UrlInterface* this_);
	COMPARERESULT (*UrlInterface_Compare) (const UrlInterface* this_, const UrlInterface* name, URLCOMPARE mode);
	Result<Data> (*UrlInterface_GetData) (const UrlInterface* this_, const ConstDataPtr& key);
	Result<void> (*UrlInterface_SetData) (UrlInterface* this_, ForwardingDataPtr&& key, const Data& data, Bool persistent);
	Result<void> (*UrlInterface_SetData_1) (UrlInterface* this_, ForwardingDataPtr&& key, Data&& data, Bool persistent);
	Result<void> (*UrlInterface_EraseData) (UrlInterface* this_, ForwardingDataPtr&& key, Bool persistent);
	String (*UrlInterface_ToString) (const UrlInterface* this_, const FormatStatement* formatStatement);
	Result<String> (*UrlInterface_ConvertToUiName) (const UrlInterface* this_, CONVERTTOUINAMEFLAGS flags);
	Result<Url> (*UrlInterface_ConvertFromUiName) (const String& str);
	Result<void> (*UrlInterface_DescribeIO) (const DataSerializeInterface& stream);
	Result<String> (*UrlInterface_ConvertToUiNameWithRepository) (const UrlInterface* this_, CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository);
	Result<Url> (*UrlInterface_ConvertFromUiNameWithRepository) (const String& str, const AssetRepositoryRef& lookupRepository);
	template <typename IMPL> void Init()
	{
		UrlInterface_Free = &IMPL::UrlInterface_Free;
		UrlInterface_Alloc = &IMPL::UrlInterface_Alloc;
		UrlInterface_Alloc_1 = &IMPL::UrlInterface_Alloc_1;
		UrlInterface_GetScheme = &IMPL::UrlInterface_GetScheme;
		UrlInterface_SetScheme = &IMPL::UrlInterface_SetScheme;
		UrlInterface_Append = &IMPL::UrlInterface_Append;
		UrlInterface_Append_1 = &IMPL::UrlInterface_Append_1;
		UrlInterface_RemoveName = &IMPL::UrlInterface_RemoveName;
		UrlInterface_GetEmbeddedUrl = &IMPL::UrlInterface_GetEmbeddedUrl;
		UrlInterface_SetEmbeddedUrl = &IMPL::UrlInterface_SetEmbeddedUrl;
		UrlInterface_GetName = &IMPL::UrlInterface_GetName;
		UrlInterface_SetName = &IMPL::UrlInterface_SetName;
		UrlInterface_GetDirectory = &IMPL::UrlInterface_GetDirectory;
		UrlInterface_SetPath = &IMPL::UrlInterface_SetPath;
		UrlInterface_GetPath = &IMPL::UrlInterface_GetPath;
		UrlInterface_SetSystemPath = &IMPL::UrlInterface_SetSystemPath;
		UrlInterface_GetSystemPath = &IMPL::UrlInterface_GetSystemPath;
		UrlInterface_SetUrl = &IMPL::UrlInterface_SetUrl;
		UrlInterface_GetUrl = &IMPL::UrlInterface_GetUrl;
		UrlInterface_SetAuthority = &IMPL::UrlInterface_SetAuthority;
		UrlInterface_SetAuthority_1 = &IMPL::UrlInterface_SetAuthority_1;
		UrlInterface_GetAuthority = &IMPL::UrlInterface_GetAuthority;
		UrlInterface_GetComponents = &IMPL::UrlInterface_GetComponents;
		UrlInterface_GetRelativeUrl = &IMPL::UrlInterface_GetRelativeUrl;
		UrlInterface_GetSuffix = &IMPL::UrlInterface_GetSuffix;
		UrlInterface_CheckSuffix = &IMPL::UrlInterface_CheckSuffix;
		UrlInterface_SetSuffix = &IMPL::UrlInterface_SetSuffix;
		UrlInterface_ClearSuffix = &IMPL::UrlInterface_ClearSuffix;
		UrlInterface_IsEmpty = &IMPL::UrlInterface_IsEmpty;
		UrlInterface_Compare = &IMPL::UrlInterface_Compare;
		UrlInterface_GetData = &IMPL::UrlInterface_GetData;
		UrlInterface_SetData = &IMPL::UrlInterface_SetData;
		UrlInterface_SetData_1 = &IMPL::UrlInterface_SetData_1;
		UrlInterface_EraseData = &IMPL::UrlInterface_EraseData;
		UrlInterface_ToString = &IMPL::UrlInterface_ToString;
		UrlInterface_ConvertToUiName = &IMPL::UrlInterface_ConvertToUiName;
		UrlInterface_ConvertFromUiName = &IMPL::UrlInterface_ConvertFromUiName;
		UrlInterface_DescribeIO = &IMPL::UrlInterface_DescribeIO;
		UrlInterface_ConvertToUiNameWithRepository = &IMPL::UrlInterface_ConvertToUiNameWithRepository;
		UrlInterface_ConvertFromUiNameWithRepository = &IMPL::UrlInterface_ConvertFromUiNameWithRepository;
	}
};

struct UrlInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void UrlInterface_Free(const UrlInterface* object) { return C::Free(object); }
		static UrlInterface* UrlInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static UrlInterface* UrlInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const UrlInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
		static const UrlScheme& UrlInterface_GetScheme(const UrlInterface* this_) { return C::Get(this_)->GetScheme(); }
		static Result<void> UrlInterface_SetScheme(UrlInterface* this_, const UrlScheme& scheme) { return C::Get(this_)->SetScheme(scheme); }
		static Result<void> UrlInterface_Append(UrlInterface* this_, const String& name) { return C::Get(this_)->Append(name); }
		static Result<void> UrlInterface_Append_1(UrlInterface* this_, const Url& relativeUrl) { return C::Get(this_)->Append(relativeUrl); }
		static Result<void> UrlInterface_RemoveName(UrlInterface* this_) { return C::Get(this_)->RemoveName(); }
		static Url UrlInterface_GetEmbeddedUrl(const UrlInterface* this_) { return C::Get(this_)->GetEmbeddedUrl(); }
		static Result<void> UrlInterface_SetEmbeddedUrl(UrlInterface* this_, const Url& url) { return C::Get(this_)->SetEmbeddedUrl(url); }
		static String UrlInterface_GetName(const UrlInterface* this_) { return C::Get(this_)->GetName(); }
		static Result<void> UrlInterface_SetName(UrlInterface* this_, const String& name) { return C::Get(this_)->SetName(name); }
		static Url UrlInterface_GetDirectory(const UrlInterface* this_) { return C::Get(this_)->GetDirectory(); }
		static Result<void> UrlInterface_SetPath(UrlInterface* this_, const String& path) { return C::Get(this_)->SetPath(path); }
		static const String& UrlInterface_GetPath(const UrlInterface* this_) { return C::Get(this_)->GetPath(); }
		static Result<void> UrlInterface_SetSystemPath(UrlInterface* this_, const String& path) { return C::Get(this_)->SetSystemPath(path); }
		static Result<String> UrlInterface_GetSystemPath(const UrlInterface* this_) { return C::Get(this_)->GetSystemPath(); }
		static Result<void> UrlInterface_SetUrl(UrlInterface* this_, const String& urlString, Bool enableDefaultFallbackScheme) { return C::Get(this_)->SetUrl(urlString, enableDefaultFallbackScheme); }
		static String UrlInterface_GetUrl(const UrlInterface* this_) { return C::Get(this_)->GetUrl(); }
		static Result<void> UrlInterface_SetAuthority(UrlInterface* this_, const String& authority) { return C::Get(this_)->SetAuthority(authority); }
		static Result<void> UrlInterface_SetAuthority_1(UrlInterface* this_, const Url& authority) { return C::Get(this_)->SetAuthority(authority); }
		static const Url& UrlInterface_GetAuthority(const UrlInterface* this_) { return C::Get(this_)->GetAuthority(); }
		static Result<void> UrlInterface_GetComponents(const UrlInterface* this_, const NonConstArray<String>& parts) { return C::Get(this_)->GetComponents(parts); }
		static Result<Url> UrlInterface_GetRelativeUrl(const UrlInterface* this_, const Url& basePath) { return C::Get(this_)->GetRelativeUrl(basePath); }
		static String UrlInterface_GetSuffix(const UrlInterface* this_) { return C::Get(this_)->GetSuffix(); }
		static Bool UrlInterface_CheckSuffix(const UrlInterface* this_, const String& suffix) { return C::Get(this_)->CheckSuffix(suffix); }
		static Result<void> UrlInterface_SetSuffix(UrlInterface* this_, const String& suffix) { return C::Get(this_)->SetSuffix(suffix); }
		static void UrlInterface_ClearSuffix(UrlInterface* this_) { return C::Get(this_)->ClearSuffix(); }
		static Bool UrlInterface_IsEmpty(const UrlInterface* this_) { return C::Get(this_)->IsEmpty(); }
		static COMPARERESULT UrlInterface_Compare(const UrlInterface* this_, const UrlInterface* name, URLCOMPARE mode) { return C::Get(this_)->Compare(name, mode); }
		static Result<Data> UrlInterface_GetData(const UrlInterface* this_, const ConstDataPtr& key) { return C::Get(this_)->GetData(key); }
		static Result<void> UrlInterface_SetData(UrlInterface* this_, ForwardingDataPtr&& key, const Data& data, Bool persistent) { return C::Get(this_)->SetData(std::forward<ForwardingDataPtr>(key), data, persistent); }
		static Result<void> UrlInterface_SetData_1(UrlInterface* this_, ForwardingDataPtr&& key, Data&& data, Bool persistent) { return C::Get(this_)->SetData(std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent); }
		static Result<void> UrlInterface_EraseData(UrlInterface* this_, ForwardingDataPtr&& key, Bool persistent) { return C::Get(this_)->EraseData(std::forward<ForwardingDataPtr>(key), persistent); }
		static String UrlInterface_ToString(const UrlInterface* this_, const FormatStatement* formatStatement) { return C::Get(this_)->ToString(formatStatement); }
		static Result<String> UrlInterface_ConvertToUiName(const UrlInterface* this_, CONVERTTOUINAMEFLAGS flags) { return C::Get(this_)->ConvertToUiName(flags); }
		static Result<Url> UrlInterface_ConvertFromUiName(const String& str) { return C::ConvertFromUiName(str); }
		static Result<void> UrlInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
		static Result<String> UrlInterface_ConvertToUiNameWithRepository(const UrlInterface* this_, CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) { return C::Get(this_)->ConvertToUiNameWithRepository(flags, lookupRepository); }
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
	return MTable::_instance.UrlInterface_GetScheme(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetScheme(const UrlScheme& scheme) -> Result<void>
{
	return MTable::_instance.UrlInterface_SetScheme(this, scheme);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Append(const String& name) -> Result<void>
{
	return MTable::_instance.UrlInterface_Append(this, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Append(const Url& relativeUrl) -> Result<void>
{
	return MTable::_instance.UrlInterface_Append_1(this, relativeUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::RemoveName() -> Result<void>
{
	return MTable::_instance.UrlInterface_RemoveName(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetEmbeddedUrl() const -> Url
{
	return MTable::_instance.UrlInterface_GetEmbeddedUrl(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetEmbeddedUrl(const Url& url) -> Result<void>
{
	return MTable::_instance.UrlInterface_SetEmbeddedUrl(this, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetName() const -> String
{
	return MTable::_instance.UrlInterface_GetName(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetName(const String& name) -> Result<void>
{
	return MTable::_instance.UrlInterface_SetName(this, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetDirectory() const -> Url
{
	return MTable::_instance.UrlInterface_GetDirectory(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetPath(const String& path) -> Result<void>
{
	return MTable::_instance.UrlInterface_SetPath(this, path);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetPath() const -> const String&
{
	return MTable::_instance.UrlInterface_GetPath(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetSystemPath(const String& path) -> Result<void>
{
	return MTable::_instance.UrlInterface_SetSystemPath(this, path);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetSystemPath() const -> Result<String>
{
	return MTable::_instance.UrlInterface_GetSystemPath(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetUrl(const String& urlString, Bool enableDefaultFallbackScheme) -> Result<void>
{
	return MTable::_instance.UrlInterface_SetUrl(this, urlString, enableDefaultFallbackScheme);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetUrl() const -> String
{
	return MTable::_instance.UrlInterface_GetUrl(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetAuthority(const String& authority) -> Result<void>
{
	return MTable::_instance.UrlInterface_SetAuthority(this, authority);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetAuthority(const Url& authority) -> Result<void>
{
	return MTable::_instance.UrlInterface_SetAuthority_1(this, authority);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetAuthority() const -> const Url&
{
	return MTable::_instance.UrlInterface_GetAuthority(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetComponents(const NonConstArray<String>& parts) const -> Result<void>
{
	return MTable::_instance.UrlInterface_GetComponents(this, parts);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetRelativeUrl(const Url& basePath) const -> Result<Url>
{
	return MTable::_instance.UrlInterface_GetRelativeUrl(this, basePath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetSuffix() const -> String
{
	return MTable::_instance.UrlInterface_GetSuffix(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::CheckSuffix(const String& suffix) const -> Bool
{
	return MTable::_instance.UrlInterface_CheckSuffix(this, suffix);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetSuffix(const String& suffix) -> Result<void>
{
	return MTable::_instance.UrlInterface_SetSuffix(this, suffix);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::ClearSuffix() -> void
{
	return MTable::_instance.UrlInterface_ClearSuffix(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::IsEmpty() const -> Bool
{
	return MTable::_instance.UrlInterface_IsEmpty(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Compare(const UrlInterface* name, URLCOMPARE mode) const -> COMPARERESULT
{
	return MTable::_instance.UrlInterface_Compare(this, name, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	return MTable::_instance.UrlInterface_GetData(this, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent) -> Result<void>
{
	return MTable::_instance.UrlInterface_SetData(this, std::forward<ForwardingDataPtr>(key), data, persistent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent) -> Result<void>
{
	return MTable::_instance.UrlInterface_SetData_1(this, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::EraseData(ForwardingDataPtr&& key, Bool persistent) -> Result<void>
{
	return MTable::_instance.UrlInterface_EraseData(this, std::forward<ForwardingDataPtr>(key), persistent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance.UrlInterface_ToString(this, formatStatement);
}
[[deprecated("use ConvertToUiNameWithRepository instead")]] MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::ConvertToUiName(CONVERTTOUINAMEFLAGS flags) const -> Result<String>
{
	return MTable::_instance.UrlInterface_ConvertToUiName(this, flags);
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
	return MTable::_instance.UrlInterface_ConvertToUiNameWithRepository(this, flags, lookupRepository);
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
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const UrlScheme&>, const UrlScheme&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const UrlScheme&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UrlInterface_GetScheme(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetScheme(const UrlScheme& scheme) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_SetScheme(o_, scheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetScheme(const UrlScheme& scheme) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UrlInterface_SetScheme(o_, scheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::Append(const String& name) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); } 
	auto res_ = MTable::_instance.UrlInterface_Append(o_, name);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::Append(const String& name) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	auto res_ = MTable::_instance.UrlInterface_Append(o_, name);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::Append(const Url& relativeUrl) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); } 
	auto res_ = MTable::_instance.UrlInterface_Append_1(o_, relativeUrl);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::Append(const Url& relativeUrl) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	auto res_ = MTable::_instance.UrlInterface_Append_1(o_, relativeUrl);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::RemoveName() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_RemoveName(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::RemoveName() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UrlInterface_RemoveName(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetEmbeddedUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UrlInterface_GetEmbeddedUrl(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetEmbeddedUrl(const Url& url) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_SetEmbeddedUrl(o_, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetEmbeddedUrl(const Url& url) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UrlInterface_SetEmbeddedUrl(o_, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UrlInterface_GetName(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetName(const String& name) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_SetName(o_, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetName(const String& name) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UrlInterface_SetName(o_, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetDirectory() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UrlInterface_GetDirectory(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetPath(const String& path) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_SetPath(o_, path));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetPath(const String& path) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UrlInterface_SetPath(o_, path));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetPath() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UrlInterface_GetPath(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetSystemPath(const String& path) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_SetSystemPath(o_, path));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetSystemPath(const String& path) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UrlInterface_SetSystemPath(o_, path));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetSystemPath() const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_GetSystemPath(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetUrl(const String& urlString, Bool enableDefaultFallbackScheme) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_SetUrl(o_, urlString, enableDefaultFallbackScheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetUrl(const String& urlString, Bool enableDefaultFallbackScheme) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UrlInterface_SetUrl(o_, urlString, enableDefaultFallbackScheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UrlInterface_GetUrl(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetAuthority(const String& authority) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_SetAuthority(o_, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetAuthority(const String& authority) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UrlInterface_SetAuthority(o_, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetAuthority(const Url& authority) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_SetAuthority_1(o_, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetAuthority(const Url& authority) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UrlInterface_SetAuthority_1(o_, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetAuthority() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UrlInterface_GetAuthority(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetComponents(const NonConstArray<String>& parts) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_GetComponents(o_, parts));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetRelativeUrl(const Url& basePath) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_GetRelativeUrl(o_, basePath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetSuffix() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UrlInterface_GetSuffix(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::CheckSuffix(const String& suffix) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance.UrlInterface_CheckSuffix(o_, suffix));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetSuffix(const String& suffix) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_SetSuffix(o_, suffix));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetSuffix(const String& suffix) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UrlInterface_SetSuffix(o_, suffix));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::ClearSuffix() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { DebugStop(); return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.UrlInterface_ClearSuffix(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::ClearSuffix() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	MTable::_instance.UrlInterface_ClearSuffix(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return true; } 
	return (MTable::_instance.UrlInterface_IsEmpty(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::Compare(const UrlInterface* name, URLCOMPARE mode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UrlInterface_Compare(o_, name, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_GetData(o_, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_SetData(o_, std::forward<ForwardingDataPtr>(key), data, persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UrlInterface_SetData(o_, std::forward<ForwardingDataPtr>(key), data, persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_SetData_1(o_, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UrlInterface_SetData_1(o_, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::Fn<S>::EraseData(ForwardingDataPtr&& key, Bool persistent) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_EraseData(o_, std::forward<ForwardingDataPtr>(key), persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWFn<S>::EraseData(ForwardingDataPtr&& key, Bool persistent) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } 
	return (MTable::_instance.UrlInterface_EraseData(o_, std::forward<ForwardingDataPtr>(key), persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoDetect() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<IODETECT>, IODETECT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<IODETECT>, IODETECT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<IODETECT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->IoDetect());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::OpenConnection() const -> typename maxon::SFINAEHelper<Result<IoConnectionRef>, S>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename maxon::SFINAEHelper<Result<IoConnectionRef>, S>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenConnection());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::OpenInputStream(OPENSTREAMFLAGS flags) const -> typename maxon::SFINAEHelper<Result<InputStreamRef>, S>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename maxon::SFINAEHelper<Result<InputStreamRef>, S>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenInputStream(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::OpenOutputStream(OPENSTREAMFLAGS flags) const -> typename maxon::SFINAEHelper<Result<OutputStreamRef>, S>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename maxon::SFINAEHelper<Result<OutputStreamRef>, S>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenOutputStream(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::OpenInOutputStream(OPENSTREAMFLAGS flags) const -> typename maxon::SFINAEHelper<Result<InOutputStreamRef>, S>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename maxon::SFINAEHelper<Result<InOutputStreamRef>, S>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenInOutputStream(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::GetBrowseIterator(GETBROWSEITERATORFLAGS flags) const -> typename maxon::SFINAEHelper<Result<IoBrowseRef>, S>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename maxon::SFINAEHelper<Result<IoBrowseRef>, S>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->GetBrowseIterator(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoGetAttributes() const -> Result<IOATTRIBUTES>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<IOATTRIBUTES>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoGetAttributes());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoSetAttributes(flags, mask));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoGetTime(IOTIMEMODE mode) const -> typename maxon::SFINAEHelper<Result<UniversalDateTime>, S>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename maxon::SFINAEHelper<Result<UniversalDateTime>, S>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->IoGetTime(mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoSetTime(mode, dateTime));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoDelete(Bool force, Bool recursive) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoDelete(force, recursive));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoCreateDirectory(createParents, createdDirs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly, const IoProgressDelegate& progress) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoCopyFile(destName, overwrite, removeReadOnly, progress));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoMove(const Url& destName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoMove(destName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoRename(const Url& newName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoRename(newName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoGetFreeVolumeSpace(availableBytes, totalBytes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoShowInOS(IOSHOWINOSFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoShowInOS(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::Normalize(NORMALIZEFLAGS flags) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Normalize(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::IoNormalize(NORMALIZEFLAGS flags) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoNormalize(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::operator +(const String& s) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->operator +(s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::operator +(const Url& s) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->operator +(s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.UrlInterface_ToString(o_, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstFn<S>::ConvertToUiName(CONVERTTOUINAMEFLAGS flags) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_ConvertToUiName(o_, flags));
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
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.UrlInterface_ConvertToUiNameWithRepository(o_, flags, lookupRepository));
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

