
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
namespace URLFLAGS
{
	struct UNBUFFERED_FILE_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x670d9d6bfaf53728LL), maxon::UInt(29))> { };
	struct NETWORK_CONNECTTIMEOUT_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x4564d4fdbeebef83LL), maxon::UInt(36))> { };
	struct NETWORK_SESSIONTIMEOUT_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x07b08e77efadec57LL), maxon::UInt(36))> { };
	struct USERNAME_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xa369896303106831LL), maxon::UInt(22))> { };
	struct USERPASSWORD_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x56f04b1d924b6541LL), maxon::UInt(26))> { };
	struct QUERY_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xf486648087ecef4dLL), maxon::UInt(19))> { };
	struct FRAGMENT_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0xa3698902b089c1abLL), maxon::UInt(22))> { };
	struct CACHE_IN_RAM_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x5062d12dea9ecb3cLL), maxon::UInt(26))> { };
	struct FTPS_FINGERPRINT_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x4db92ef234434951LL), maxon::UInt(30))> { };
}

struct UrlInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_UrlInterface_Free) (const UrlInterface* object);
	UrlInterface* (*_UrlInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	UrlInterface* (*_UrlInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const UrlInterface& object);
	const UrlScheme& (*_UrlInterface_GetScheme) (const UrlInterface* this_);
	Result<void> (*_UrlInterface_SetScheme) (UrlInterface* this_, const UrlScheme& scheme);
	Result<void> (*_UrlInterface_Append) (UrlInterface* this_, const String& name);
	Result<void> (*_UrlInterface_Append_1) (UrlInterface* this_, const Url& relativeUrl);
	Result<void> (*_UrlInterface_RemoveName) (UrlInterface* this_);
	Url (*_UrlInterface_GetEmbeddedUrl) (const UrlInterface* this_);
	Result<void> (*_UrlInterface_SetEmbeddedUrl) (UrlInterface* this_, const Url& url);
	String (*_UrlInterface_GetName) (const UrlInterface* this_);
	Result<void> (*_UrlInterface_SetName) (UrlInterface* this_, const String& name);
	Url (*_UrlInterface_GetDirectory) (const UrlInterface* this_);
	Result<void> (*_UrlInterface_SetPath) (UrlInterface* this_, const String& path);
	const String& (*_UrlInterface_GetPath) (const UrlInterface* this_);
	Result<void> (*_UrlInterface_SetSystemPath) (UrlInterface* this_, const String& path);
	Result<String> (*_UrlInterface_GetSystemPath) (const UrlInterface* this_);
	Result<void> (*_UrlInterface_SetUrl) (UrlInterface* this_, const String& urlString, Bool enableDefaultFallbackScheme);
	String (*_UrlInterface_GetUrl) (const UrlInterface* this_);
	Result<void> (*_UrlInterface_SetAuthority) (UrlInterface* this_, const String& authority);
	Result<void> (*_UrlInterface_SetAuthority_1) (UrlInterface* this_, const Url& authority);
	const Url& (*_UrlInterface_GetAuthority) (const UrlInterface* this_);
	Result<void> (*_UrlInterface_GetComponents) (const UrlInterface* this_, const NonConstArray<String>& parts);
	Result<Url> (*_UrlInterface_GetRelativeUrl) (const UrlInterface* this_, const Url& basePath);
	String (*_UrlInterface_GetSuffix) (const UrlInterface* this_);
	Bool (*_UrlInterface_CheckSuffix) (const UrlInterface* this_, const String& suffix);
	Result<void> (*_UrlInterface_SetSuffix) (UrlInterface* this_, const String& suffix);
	void (*_UrlInterface_ClearSuffix) (UrlInterface* this_);
	Bool (*_UrlInterface_IsEmpty) (const UrlInterface* this_);
	COMPARERESULT (*_UrlInterface_Compare) (const UrlInterface* this_, const UrlInterface* name, URLCOMPARE mode);
	Result<Data> (*_UrlInterface_GetData) (const UrlInterface* this_, const ConstDataPtr& key);
	Result<void> (*_UrlInterface_SetData) (UrlInterface* this_, ForwardingDataPtr&& key, const Data& data, Bool persistent);
	Result<void> (*_UrlInterface_SetData_1) (UrlInterface* this_, ForwardingDataPtr&& key, Data&& data, Bool persistent);
	String (*_UrlInterface_ToString) (const UrlInterface* this_, const FormatStatement* formatStatement);
	Result<void> (*_UrlInterface_DescribeIO) (const DataSerializeInterface& stream);
	template <typename IMPL> void Init()
	{
		_UrlInterface_Free = &IMPL::_UrlInterface_Free;
		_UrlInterface_Alloc = &IMPL::_UrlInterface_Alloc;
		_UrlInterface_Alloc_1 = &IMPL::_UrlInterface_Alloc_1;
		_UrlInterface_GetScheme = &IMPL::_UrlInterface_GetScheme;
		_UrlInterface_SetScheme = &IMPL::_UrlInterface_SetScheme;
		_UrlInterface_Append = &IMPL::_UrlInterface_Append;
		_UrlInterface_Append_1 = &IMPL::_UrlInterface_Append_1;
		_UrlInterface_RemoveName = &IMPL::_UrlInterface_RemoveName;
		_UrlInterface_GetEmbeddedUrl = &IMPL::_UrlInterface_GetEmbeddedUrl;
		_UrlInterface_SetEmbeddedUrl = &IMPL::_UrlInterface_SetEmbeddedUrl;
		_UrlInterface_GetName = &IMPL::_UrlInterface_GetName;
		_UrlInterface_SetName = &IMPL::_UrlInterface_SetName;
		_UrlInterface_GetDirectory = &IMPL::_UrlInterface_GetDirectory;
		_UrlInterface_SetPath = &IMPL::_UrlInterface_SetPath;
		_UrlInterface_GetPath = &IMPL::_UrlInterface_GetPath;
		_UrlInterface_SetSystemPath = &IMPL::_UrlInterface_SetSystemPath;
		_UrlInterface_GetSystemPath = &IMPL::_UrlInterface_GetSystemPath;
		_UrlInterface_SetUrl = &IMPL::_UrlInterface_SetUrl;
		_UrlInterface_GetUrl = &IMPL::_UrlInterface_GetUrl;
		_UrlInterface_SetAuthority = &IMPL::_UrlInterface_SetAuthority;
		_UrlInterface_SetAuthority_1 = &IMPL::_UrlInterface_SetAuthority_1;
		_UrlInterface_GetAuthority = &IMPL::_UrlInterface_GetAuthority;
		_UrlInterface_GetComponents = &IMPL::_UrlInterface_GetComponents;
		_UrlInterface_GetRelativeUrl = &IMPL::_UrlInterface_GetRelativeUrl;
		_UrlInterface_GetSuffix = &IMPL::_UrlInterface_GetSuffix;
		_UrlInterface_CheckSuffix = &IMPL::_UrlInterface_CheckSuffix;
		_UrlInterface_SetSuffix = &IMPL::_UrlInterface_SetSuffix;
		_UrlInterface_ClearSuffix = &IMPL::_UrlInterface_ClearSuffix;
		_UrlInterface_IsEmpty = &IMPL::_UrlInterface_IsEmpty;
		_UrlInterface_Compare = &IMPL::_UrlInterface_Compare;
		_UrlInterface_GetData = &IMPL::_UrlInterface_GetData;
		_UrlInterface_SetData = &IMPL::_UrlInterface_SetData;
		_UrlInterface_SetData_1 = &IMPL::_UrlInterface_SetData_1;
		_UrlInterface_ToString = &IMPL::_UrlInterface_ToString;
		_UrlInterface_DescribeIO = &IMPL::_UrlInterface_DescribeIO;
	}
};

struct UrlInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _UrlInterface_Free(const UrlInterface* object) { return C::Free(object); }
	static UrlInterface* _UrlInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static UrlInterface* _UrlInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const UrlInterface& object) { return C::Alloc(allocLocation, ((const C&) object)); }
	static const UrlScheme& _UrlInterface_GetScheme(const UrlInterface* this_) { return ((const C*) this_)->GetScheme(); }
	static Result<void> _UrlInterface_SetScheme(UrlInterface* this_, const UrlScheme& scheme) { return ((C*) this_)->SetScheme(scheme); }
	static Result<void> _UrlInterface_Append(UrlInterface* this_, const String& name) { return ((C*) this_)->Append(name); }
	static Result<void> _UrlInterface_Append_1(UrlInterface* this_, const Url& relativeUrl) { return ((C*) this_)->Append(relativeUrl); }
	static Result<void> _UrlInterface_RemoveName(UrlInterface* this_) { return ((C*) this_)->RemoveName(); }
	static Url _UrlInterface_GetEmbeddedUrl(const UrlInterface* this_) { return ((const C*) this_)->GetEmbeddedUrl(); }
	static Result<void> _UrlInterface_SetEmbeddedUrl(UrlInterface* this_, const Url& url) { return ((C*) this_)->SetEmbeddedUrl(url); }
	static String _UrlInterface_GetName(const UrlInterface* this_) { return ((const C*) this_)->GetName(); }
	static Result<void> _UrlInterface_SetName(UrlInterface* this_, const String& name) { return ((C*) this_)->SetName(name); }
	static Url _UrlInterface_GetDirectory(const UrlInterface* this_) { return ((const C*) this_)->GetDirectory(); }
	static Result<void> _UrlInterface_SetPath(UrlInterface* this_, const String& path) { return ((C*) this_)->SetPath(path); }
	static const String& _UrlInterface_GetPath(const UrlInterface* this_) { return ((const C*) this_)->GetPath(); }
	static Result<void> _UrlInterface_SetSystemPath(UrlInterface* this_, const String& path) { return ((C*) this_)->SetSystemPath(path); }
	static Result<String> _UrlInterface_GetSystemPath(const UrlInterface* this_) { return ((const C*) this_)->GetSystemPath(); }
	static Result<void> _UrlInterface_SetUrl(UrlInterface* this_, const String& urlString, Bool enableDefaultFallbackScheme) { return ((C*) this_)->SetUrl(urlString, enableDefaultFallbackScheme); }
	static String _UrlInterface_GetUrl(const UrlInterface* this_) { return ((const C*) this_)->GetUrl(); }
	static Result<void> _UrlInterface_SetAuthority(UrlInterface* this_, const String& authority) { return ((C*) this_)->SetAuthority(authority); }
	static Result<void> _UrlInterface_SetAuthority_1(UrlInterface* this_, const Url& authority) { return ((C*) this_)->SetAuthority(authority); }
	static const Url& _UrlInterface_GetAuthority(const UrlInterface* this_) { return ((const C*) this_)->GetAuthority(); }
	static Result<void> _UrlInterface_GetComponents(const UrlInterface* this_, const NonConstArray<String>& parts) { return ((const C*) this_)->GetComponents(parts); }
	static Result<Url> _UrlInterface_GetRelativeUrl(const UrlInterface* this_, const Url& basePath) { return ((const C*) this_)->GetRelativeUrl(basePath); }
	static String _UrlInterface_GetSuffix(const UrlInterface* this_) { return ((const C*) this_)->GetSuffix(); }
	static Bool _UrlInterface_CheckSuffix(const UrlInterface* this_, const String& suffix) { return ((const C*) this_)->CheckSuffix(suffix); }
	static Result<void> _UrlInterface_SetSuffix(UrlInterface* this_, const String& suffix) { return ((C*) this_)->SetSuffix(suffix); }
	static void _UrlInterface_ClearSuffix(UrlInterface* this_) { return ((C*) this_)->ClearSuffix(); }
	static Bool _UrlInterface_IsEmpty(const UrlInterface* this_) { return ((const C*) this_)->IsEmpty(); }
	static COMPARERESULT _UrlInterface_Compare(const UrlInterface* this_, const UrlInterface* name, URLCOMPARE mode) { return ((const C*) this_)->Compare(name, mode); }
	static Result<Data> _UrlInterface_GetData(const UrlInterface* this_, const ConstDataPtr& key) { return ((const C*) this_)->GetData(key); }
	static Result<void> _UrlInterface_SetData(UrlInterface* this_, ForwardingDataPtr&& key, const Data& data, Bool persistent) { return ((C*) this_)->SetData(std::forward<ForwardingDataPtr>(key), data, persistent); }
	static Result<void> _UrlInterface_SetData_1(UrlInterface* this_, ForwardingDataPtr&& key, Data&& data, Bool persistent) { return ((C*) this_)->SetData(std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent); }
	static String _UrlInterface_ToString(const UrlInterface* this_, const FormatStatement* formatStatement) { return ((const C*) this_)->ToString(formatStatement); }
	static Result<void> _UrlInterface_DescribeIO(const DataSerializeInterface& stream) { return C::DescribeIO(stream); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Free(const UrlInterface* object) -> void
{
	return MTable::_instance._UrlInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Alloc(const maxon::SourceLocation& allocLocation) -> UrlInterface*
{
	return MTable::_instance._UrlInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Alloc(const maxon::SourceLocation& allocLocation, const UrlInterface& object) -> UrlInterface*
{
	return MTable::_instance._UrlInterface_Alloc_1(allocLocation, object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetScheme() const -> const UrlScheme&
{
	return MTable::_instance._UrlInterface_GetScheme(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetScheme(const UrlScheme& scheme) -> Result<void>
{
	return MTable::_instance._UrlInterface_SetScheme(this, scheme);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Append(const String& name) -> Result<void>
{
	return MTable::_instance._UrlInterface_Append(this, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Append(const Url& relativeUrl) -> Result<void>
{
	return MTable::_instance._UrlInterface_Append_1(this, relativeUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::RemoveName() -> Result<void>
{
	return MTable::_instance._UrlInterface_RemoveName(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetEmbeddedUrl() const -> Url
{
	return MTable::_instance._UrlInterface_GetEmbeddedUrl(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetEmbeddedUrl(const Url& url) -> Result<void>
{
	return MTable::_instance._UrlInterface_SetEmbeddedUrl(this, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetName() const -> String
{
	return MTable::_instance._UrlInterface_GetName(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetName(const String& name) -> Result<void>
{
	return MTable::_instance._UrlInterface_SetName(this, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetDirectory() const -> Url
{
	return MTable::_instance._UrlInterface_GetDirectory(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetPath(const String& path) -> Result<void>
{
	return MTable::_instance._UrlInterface_SetPath(this, path);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetPath() const -> const String&
{
	return MTable::_instance._UrlInterface_GetPath(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetSystemPath(const String& path) -> Result<void>
{
	return MTable::_instance._UrlInterface_SetSystemPath(this, path);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetSystemPath() const -> Result<String>
{
	return MTable::_instance._UrlInterface_GetSystemPath(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetUrl(const String& urlString, Bool enableDefaultFallbackScheme) -> Result<void>
{
	return MTable::_instance._UrlInterface_SetUrl(this, urlString, enableDefaultFallbackScheme);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetUrl() const -> String
{
	return MTable::_instance._UrlInterface_GetUrl(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetAuthority(const String& authority) -> Result<void>
{
	return MTable::_instance._UrlInterface_SetAuthority(this, authority);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetAuthority(const Url& authority) -> Result<void>
{
	return MTable::_instance._UrlInterface_SetAuthority_1(this, authority);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetAuthority() const -> const Url&
{
	return MTable::_instance._UrlInterface_GetAuthority(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetComponents(const NonConstArray<String>& parts) const -> Result<void>
{
	return MTable::_instance._UrlInterface_GetComponents(this, parts);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetRelativeUrl(const Url& basePath) const -> Result<Url>
{
	return MTable::_instance._UrlInterface_GetRelativeUrl(this, basePath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetSuffix() const -> String
{
	return MTable::_instance._UrlInterface_GetSuffix(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::CheckSuffix(const String& suffix) const -> Bool
{
	return MTable::_instance._UrlInterface_CheckSuffix(this, suffix);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetSuffix(const String& suffix) -> Result<void>
{
	return MTable::_instance._UrlInterface_SetSuffix(this, suffix);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::ClearSuffix() -> void
{
	return MTable::_instance._UrlInterface_ClearSuffix(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::IsEmpty() const -> Bool
{
	return MTable::_instance._UrlInterface_IsEmpty(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Compare(const UrlInterface* name, URLCOMPARE mode) const -> COMPARERESULT
{
	return MTable::_instance._UrlInterface_Compare(this, name, mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	return MTable::_instance._UrlInterface_GetData(this, key);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent) -> Result<void>
{
	return MTable::_instance._UrlInterface_SetData(this, std::forward<ForwardingDataPtr>(key), data, persistent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent) -> Result<void>
{
	return MTable::_instance._UrlInterface_SetData_1(this, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::ToString(const FormatStatement* formatStatement) const -> String
{
	return MTable::_instance._UrlInterface_ToString(this, formatStatement);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::DescribeIO(const DataSerializeInterface& stream) -> Result<void>
{
	return MTable::_instance._UrlInterface_DescribeIO(stream);
}

auto UrlInterface::Reference::Create() -> maxon::ResultMemT<Url>
{
	UrlInterface* res_ = UrlInterface::Alloc(MAXON_SOURCE_LOCATION);
	return Url(maxon::ForwardResultPtr<UrlInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetScheme() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const UrlScheme&>, const UrlScheme&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const UrlScheme&>, const UrlScheme&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const UrlScheme&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UrlInterface_GetScheme(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::SetScheme(const UrlScheme& scheme) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UrlInterface_SetScheme(o_, scheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetScheme(const UrlScheme& scheme) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UrlInterface_SetScheme(o_, scheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::Append(const String& name) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); 
	auto res_ = MTable::_instance._UrlInterface_Append(o_, name);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::Append(const String& name) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	auto res_ = MTable::_instance._UrlInterface_Append(o_, name);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::Append(const Url& relativeUrl) const -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S const>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR)); 
	auto res_ = MTable::_instance._UrlInterface_Append_1(o_, relativeUrl);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::Append(const Url& relativeUrl) -> maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), true, maxon::Result<DOXYGEN_SWITCH(maxon::RefMemberType<S>, S)>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	auto res_ = MTable::_instance._UrlInterface_Append_1(o_, relativeUrl);
	return ReturnHelper::Return(this, res_.GetErrorStorage());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::RemoveName() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UrlInterface_RemoveName(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::RemoveName() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UrlInterface_RemoveName(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetEmbeddedUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UrlInterface_GetEmbeddedUrl(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::SetEmbeddedUrl(const Url& url) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UrlInterface_SetEmbeddedUrl(o_, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetEmbeddedUrl(const Url& url) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UrlInterface_SetEmbeddedUrl(o_, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UrlInterface_GetName(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::SetName(const String& name) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UrlInterface_SetName(o_, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetName(const String& name) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UrlInterface_SetName(o_, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetDirectory() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Url>, Url>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UrlInterface_GetDirectory(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::SetPath(const String& path) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UrlInterface_SetPath(o_, path));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetPath(const String& path) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UrlInterface_SetPath(o_, path));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPath() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const String&>, const String&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const String&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UrlInterface_GetPath(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::SetSystemPath(const String& path) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UrlInterface_SetSystemPath(o_, path));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetSystemPath(const String& path) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UrlInterface_SetSystemPath(o_, path));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSystemPath() const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._UrlInterface_GetSystemPath(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::SetUrl(const String& urlString, Bool enableDefaultFallbackScheme) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UrlInterface_SetUrl(o_, urlString, enableDefaultFallbackScheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetUrl(const String& urlString, Bool enableDefaultFallbackScheme) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UrlInterface_SetUrl(o_, urlString, enableDefaultFallbackScheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UrlInterface_GetUrl(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::SetAuthority(const String& authority) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UrlInterface_SetAuthority(o_, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetAuthority(const String& authority) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UrlInterface_SetAuthority(o_, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::SetAuthority(const Url& authority) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UrlInterface_SetAuthority_1(o_, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetAuthority(const Url& authority) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UrlInterface_SetAuthority_1(o_, authority));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetAuthority() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UrlInterface_GetAuthority(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetComponents(const NonConstArray<String>& parts) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._UrlInterface_GetComponents(o_, parts));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetRelativeUrl(const Url& basePath) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._UrlInterface_GetRelativeUrl(o_, basePath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSuffix() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UrlInterface_GetSuffix(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::CheckSuffix(const String& suffix) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._UrlInterface_CheckSuffix(o_, suffix));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::SetSuffix(const String& suffix) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UrlInterface_SetSuffix(o_, suffix));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetSuffix(const String& suffix) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UrlInterface_SetSuffix(o_, suffix));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::ClearSuffix() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); 
	MTable::_instance._UrlInterface_ClearSuffix(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::ClearSuffix() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	MTable::_instance._UrlInterface_ClearSuffix(o_);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsEmpty() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return true; } 
	return (MTable::_instance._UrlInterface_IsEmpty(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsPopulated() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (o_->IsPopulated());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Compare(const UrlInterface* name, URLCOMPARE mode) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<COMPARERESULT>, COMPARERESULT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<COMPARERESULT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UrlInterface_Compare(o_, name, mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetData(const ConstDataPtr& key) const -> Result<Data>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Data>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._UrlInterface_GetData(o_, key));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UrlInterface_SetData(o_, std::forward<ForwardingDataPtr>(key), data, persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetData(ForwardingDataPtr&& key, const Data& data, Bool persistent) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UrlInterface_SetData(o_, std::forward<ForwardingDataPtr>(key), data, persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ReferenceFunctionsImpl<S>::SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._UrlInterface_SetData_1(o_, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetData(ForwardingDataPtr&& key, Data&& data, Bool persistent) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); UrlInterface* o_ = (UrlInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (MTable::_instance._UrlInterface_SetData_1(o_, std::forward<ForwardingDataPtr>(key), std::forward<Data>(data), persistent));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoDetect() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<IODETECT>, IODETECT>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<IODETECT>, IODETECT>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<IODETECT>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (o_->IoDetect());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::OpenConnection() const -> DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<IoConnectionRef>, S>::type), Result<IoConnectionRef>)
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<IoConnectionRef>, S>::type), Result<IoConnectionRef>)>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenConnection());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::OpenInputStream(OPENSTREAMFLAGS flags) const -> DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<InputStreamRef>, S>::type), Result<InputStreamRef>)
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<InputStreamRef>, S>::type), Result<InputStreamRef>)>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenInputStream(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::OpenOutputStream(OPENSTREAMFLAGS flags) const -> DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<OutputStreamRef>, S>::type), Result<OutputStreamRef>)
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<OutputStreamRef>, S>::type), Result<OutputStreamRef>)>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenOutputStream(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::OpenInOutputStream(OPENSTREAMFLAGS flags) const -> DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<InOutputStreamRef>, S>::type), Result<InOutputStreamRef>)
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<InOutputStreamRef>, S>::type), Result<InOutputStreamRef>)>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->OpenInOutputStream(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetBrowseIterator(GETBROWSEITERATORFLAGS flags) const -> DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<IoBrowseRef>, S>::type), Result<IoBrowseRef>)
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<IoBrowseRef>, S>::type), Result<IoBrowseRef>)>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->GetBrowseIterator(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoGetAttributes() const -> Result<IOATTRIBUTES>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<IOATTRIBUTES>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoGetAttributes());
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoSetAttributes(IOATTRIBUTES flags, IOATTRIBUTES mask) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoSetAttributes(flags, mask));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoGetTime(IOTIMEMODE mode) const -> DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<UniversalDateTime>, S>::type), Result<UniversalDateTime>)
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, DOXYGEN_SWITCH(MAXON_MACROARG_TYPE(typename maxon::SFINAEHelper<Result<UniversalDateTime>, S>::type), Result<UniversalDateTime>)>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (static_cast<typename maxon::SFINAEHelper<const UrlInterface*, S>::type>(o_)->IoGetTime(mode));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoSetTime(IOTIMEMODE mode, const UniversalDateTime& dateTime) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoSetTime(mode, dateTime));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoDelete(Bool force, Bool recursive) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoDelete(force, recursive));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoCreateDirectory(Bool createParents, BaseArray<Url>* createdDirs) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoCreateDirectory(createParents, createdDirs));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoCopyFile(const Url& destName, Bool overwrite, Bool removeReadOnly) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoCopyFile(destName, overwrite, removeReadOnly));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoMove(const Url& destName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoMove(destName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoRename(const Url& newName) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoRename(newName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoGetFreeVolumeSpace(Int64& availableBytes, Int64& totalBytes) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoGetFreeVolumeSpace(availableBytes, totalBytes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoShowInOS(IOSHOWINOSFLAGS flags) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoShowInOS(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Normalize(NORMALIZEFLAGS flags) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->Normalize(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoNormalize(NORMALIZEFLAGS flags) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->IoNormalize(flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::operator +(const String& s) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->operator +(s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::operator +(const Url& s) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (o_->operator +(s));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ToString(const FormatStatement* formatStatement) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const UrlInterface* o_ = (const UrlInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = UrlInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance._UrlInterface_ToString(o_, formatStatement));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto UrlInterface::Hxx1::ConstReferenceFunctionsImpl<S>::DescribeIO(const DataSerializeInterface& stream) -> Result<void> { return (MTable::_instance._UrlInterface_DescribeIO(stream)); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

