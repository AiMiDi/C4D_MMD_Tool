#if 1
namespace maxon
{
	namespace enum17 { enum class LAYERSETMODE
	{
		LAYERS,					///< Layers / layer Sets.
		LAYERMASKS,			///< Layer masks.
		ALPHAS,					///< Alpha channels.
		LAYERALPHA,			///< Layer alpha.
		DISABLED				///< Disabled.
	} ; }
	maxon::String PrivateToString_LAYERSETMODE17(std::underlying_type<enum17::LAYERSETMODE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum17::LAYERSETMODE::LAYERS, (maxon::UInt64) enum17::LAYERSETMODE::LAYERMASKS, (maxon::UInt64) enum17::LAYERSETMODE::ALPHAS, (maxon::UInt64) enum17::LAYERSETMODE::LAYERALPHA, (maxon::UInt64) enum17::LAYERSETMODE::DISABLED};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "LAYERSETMODE", SIZEOF(x), false, values, "LAYERS\0LAYERMASKS\0ALPHAS\0LAYERALPHA\0DISABLED\0", fmt);
	}
	const maxon::Char* const LayerSetInterface::MTable::_ids = 
		"Free@46348de53c0e5dba\0" // void Free(const LayerSetInterface* object)
		"Alloc@3c541cf9cd8eb223\0" // LayerSetInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@af642a5b2d6513c0\0" // LayerSetInterface* Alloc(const maxon::SourceLocation& allocLocation, const LayerSetInterface& object)
		"SetSelectedLayers@bd5cb7df961de389\0" // Result<void> SetSelectedLayers(const LayerHash& layers)
		"GetSelectedLayers@5161163f03781e3c\0" // const LayerHash& GetSelectedLayers() const
		"SetSelectedImage@cc63eccfe460c07a\0" // void SetSelectedImage(const String& image)
		"GetSelectedImage@b8f12dfa16054f01\0" // String GetSelectedImage() const
		"SetMode@d47d1126101c140\0" // void SetMode(LAYERSETMODE mode)
		"GetMode@3ec87f8fccc49328\0" // LAYERSETMODE GetMode() const
		"SetCalculateAlpha@add9409250097f0c\0" // void SetCalculateAlpha(Bool calcAlpha)
		"GetCalculateAlpha@12e73654e6d65520\0" // Bool GetCalculateAlpha() const
		"IsEqual@4e2e5d5fc4e7ad07\0" // Bool IsEqual(const LayerSetInterface* other) const
		"GetHashCode@b22918402154097b\0" // HashInt GetHashCode() const
		"DescribeIO@fe3f1bd5a495cc32\0" // Result<void> DescribeIO(const DataSerializeInterface& stream)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class LayerSetInterface::Hxx2::Unresolved : public LayerSetInterface
	{
	public:
		static const Unresolved* Get(const LayerSetInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(LayerSetInterface* o) { return (Unresolved*) o; }
		static void Free(const LayerSetInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LayerSetInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static LayerSetInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LayerSetInterface::Alloc(allocLocation); return nullptr;}
		static LayerSetInterface* Alloc(const maxon::SourceLocation& allocLocation, const LayerSetInterface& object) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LayerSetInterface::Alloc(allocLocation, object); return nullptr;}
		Result<void> SetSelectedLayers(const LayerHash& layers) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LayerSetInterface*) this)->SetSelectedLayers(layers); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		const LayerHash& GetSelectedLayers() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LayerSetInterface*) this)->GetSelectedLayers(); return maxon::PrivateIncompleteNullReturnValue<const LayerHash&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		void SetSelectedImage(const String& image) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LayerSetInterface*) this)->SetSelectedImage(image); return maxon::PrivateLogNullptrError();}
		String GetSelectedImage() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LayerSetInterface*) this)->GetSelectedImage(); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		void SetMode(LAYERSETMODE mode) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LayerSetInterface*) this)->SetMode(mode); return maxon::PrivateLogNullptrError();}
		LAYERSETMODE GetMode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LayerSetInterface*) this)->GetMode(); return maxon::PrivateIncompleteNullReturnValue<LAYERSETMODE>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		void SetCalculateAlpha(Bool calcAlpha) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LayerSetInterface*) this)->SetCalculateAlpha(calcAlpha); return maxon::PrivateLogNullptrError();}
		Bool GetCalculateAlpha() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LayerSetInterface*) this)->GetCalculateAlpha(); return maxon::PrivateLogNullptrError(false);}
		Bool IsEqual(const LayerSetInterface* other) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LayerSetInterface*) this)->IsEqual(other); return maxon::PrivateLogNullptrError(false);}
		HashInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LayerSetInterface*) this)->GetHashCode(); return maxon::PrivateIncompleteNullReturnValue<HashInt>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<void> DescribeIO(const DataSerializeInterface& stream) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return LayerSetInterface::DescribeIO(stream); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE LayerSetInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<LayerSetInterface*>::value,
		maxon::details::NullReturnType<LayerSetInterface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<const LayerHash&>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<LAYERSETMODE>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<HashInt>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool LayerSetInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LayerSetInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LayerSetInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LayerSetInterface_Alloc_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_Alloc_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LayerSetInterface_SetSelectedLayers = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_SetSelectedLayers;
		#else
		tbl->_LayerSetInterface_SetSelectedLayers = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_SetSelectedLayers;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const LayerHash&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LayerSetInterface_GetSelectedLayers = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_GetSelectedLayers;
		#else
		tbl->_LayerSetInterface_GetSelectedLayers = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_GetSelectedLayers;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LayerSetInterface_SetSelectedImage = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_SetSelectedImage;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LayerSetInterface_GetSelectedImage = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_GetSelectedImage;
		#else
		tbl->_LayerSetInterface_GetSelectedImage = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_GetSelectedImage;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LayerSetInterface_SetMode = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_SetMode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<LAYERSETMODE>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LayerSetInterface_GetMode = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_GetMode;
		#else
		tbl->_LayerSetInterface_GetMode = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_GetMode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LayerSetInterface_SetCalculateAlpha = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_SetCalculateAlpha;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LayerSetInterface_GetCalculateAlpha = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_GetCalculateAlpha;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LayerSetInterface_IsEqual = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_IsEqual;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<HashInt>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LayerSetInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_GetHashCode;
		#else
		tbl->_LayerSetInterface_GetHashCode = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_GetHashCode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LayerSetInterface_DescribeIO = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_DescribeIO;
		#else
		tbl->_LayerSetInterface_DescribeIO = &Hxx2::Wrapper<Hxx2::Unresolved>::_LayerSetInterface_DescribeIO;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(LayerSetInterface, "net.maxon.interface.layerset", nullptr);
	template <typename DUMMY> maxon::Int LayerSetInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<LAYERSETMODE>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<const LayerHash&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_layerset(0
	| maxon::LayerSetInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
