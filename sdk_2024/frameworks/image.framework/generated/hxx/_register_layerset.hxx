#if 1
namespace maxon
{
	namespace enum17
	{
		enum class LAYERSETMODE
		{
			LAYERS,					///< Layers / layer Sets.
			LAYERMASKS,			///< Layer masks.
			ALPHAS,					///< Alpha channels.
			LAYERALPHA,			///< Layer alpha.
			DISABLED				///< Disabled.
		} ;
		static const maxon::UInt64 LAYERSETMODE_values[] = {maxon::UInt64(enum17::LAYERSETMODE::LAYERS), maxon::UInt64(enum17::LAYERSETMODE::LAYERMASKS), maxon::UInt64(enum17::LAYERSETMODE::ALPHAS), maxon::UInt64(enum17::LAYERSETMODE::LAYERALPHA), maxon::UInt64(enum17::LAYERSETMODE::DISABLED)};
		static const maxon::EnumInfo LAYERSETMODE_info{"LAYERSETMODE", SIZEOF(LAYERSETMODE), false, "LAYERS\0LAYERMASKS\0ALPHAS\0LAYERALPHA\0DISABLED\0", LAYERSETMODE_values, std::extent<decltype(LAYERSETMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_LAYERSETMODE17(){ return enum17::LAYERSETMODE_info; }
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
		Result<void> SetSelectedLayers(const LayerHash& layers) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((LayerSetInterface*) this)->SetSelectedLayers(layers); return HXXRET1(UNRESOLVED);}
		const LayerHash& GetSelectedLayers() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LayerSetInterface*) this)->GetSelectedLayers(); return HXXRET3(UNRESOLVED, const LayerHash&);}
		void SetSelectedImage(const String& image) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LayerSetInterface*) this)->SetSelectedImage(image); return maxon::PrivateLogNullptrError();}
		String GetSelectedImage() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LayerSetInterface*) this)->GetSelectedImage(); return HXXRET3(UNRESOLVED, String);}
		void SetMode(LAYERSETMODE mode) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LayerSetInterface*) this)->SetMode(mode); return maxon::PrivateLogNullptrError();}
		LAYERSETMODE GetMode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LayerSetInterface*) this)->GetMode(); return HXXRET3(UNRESOLVED, LAYERSETMODE);}
		void SetCalculateAlpha(Bool calcAlpha) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LayerSetInterface*) this)->SetCalculateAlpha(calcAlpha); return maxon::PrivateLogNullptrError();}
		Bool GetCalculateAlpha() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LayerSetInterface*) this)->GetCalculateAlpha(); return maxon::PrivateLogNullptrError(false);}
		Bool IsEqual(const LayerSetInterface* other) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LayerSetInterface*) this)->IsEqual(other); return maxon::PrivateLogNullptrError(false);}
		HashInt GetHashCode() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LayerSetInterface*) this)->GetHashCode(); return HXXRET3(UNRESOLVED, HashInt);}
		static Result<void> DescribeIO(const DataSerializeInterface& stream) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return LayerSetInterface::DescribeIO(stream); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE LayerSetInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<LayerSetInterface*>::value,
		maxon::details::UnresolvedReturnType<LayerSetInterface*>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<const LayerHash&>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<String>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<LAYERSETMODE>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<void>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Bool>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<HashInt>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool LayerSetInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LayerSetInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LayerSetInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LayerSetInterface_Alloc_1 = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_Alloc_1), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_Alloc_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LayerSetInterface_SetSelectedLayers = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_SetSelectedLayers), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_SetSelectedLayers);
		#else
		tbl->LayerSetInterface_SetSelectedLayers = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_SetSelectedLayers), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_SetSelectedLayers);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<const LayerHash&>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LayerSetInterface_GetSelectedLayers = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_GetSelectedLayers), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_GetSelectedLayers);
		#else
		tbl->LayerSetInterface_GetSelectedLayers = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_GetSelectedLayers), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_GetSelectedLayers);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LayerSetInterface_SetSelectedImage = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_SetSelectedImage), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_SetSelectedImage);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LayerSetInterface_GetSelectedImage = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_GetSelectedImage), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_GetSelectedImage);
		#else
		tbl->LayerSetInterface_GetSelectedImage = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_GetSelectedImage), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_GetSelectedImage);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LayerSetInterface_SetMode = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_SetMode), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_SetMode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<LAYERSETMODE>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LayerSetInterface_GetMode = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_GetMode), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_GetMode);
		#else
		tbl->LayerSetInterface_GetMode = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_GetMode), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_GetMode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LayerSetInterface_SetCalculateAlpha = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_SetCalculateAlpha), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_SetCalculateAlpha);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LayerSetInterface_GetCalculateAlpha = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_GetCalculateAlpha), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_GetCalculateAlpha);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LayerSetInterface_IsEqual = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_IsEqual), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_IsEqual);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<HashInt>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LayerSetInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_GetHashCode);
		#else
		tbl->LayerSetInterface_GetHashCode = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_GetHashCode), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_GetHashCode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LayerSetInterface_DescribeIO = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_DescribeIO), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_DescribeIO);
		#else
		tbl->LayerSetInterface_DescribeIO = PRIVATE_MAXON_MF_CAST(decltype(LayerSetInterface_DescribeIO), &Hxx2::Wrapper<Hxx2::Unresolved>::LayerSetInterface_DescribeIO);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(LayerSetInterface, "net.maxon.interface.layerset", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int LayerSetInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<HashInt>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<LAYERSETMODE>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<const LayerHash&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_layerset(0
	| maxon::LayerSetInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
