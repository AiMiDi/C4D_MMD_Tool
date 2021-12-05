#if 1
namespace maxon
{
	const maxon::Char* const NoiseInterface::MTable::_ids = 
		"Free@8b28fe10dc068e53\0" // void Free(const NoiseInterface* object)
		"Alloc@9df0fabcae6bfc78\0" // NoiseInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Init@b9f888d427068e41\0" // Result<void> Init(UInt32 seed, Int permutationTablePower)
		"GetSeed@34c6756cf1200a25\0" // UInt32 GetSeed() const
		"GetPermutationTablePower@7d0e6f3d29c239e7\0" // Int GetPermutationTablePower() const
		"GetPermutationTable@6d2deb8bb7939430\0" // const BaseArray<UInt16>* GetPermutationTable() const
		"GetGradientTable@efb893a888d7a3ff\0" // Result<void> GetGradientTable(Bool gradient3D, BaseArray<Vector4d32>& gradient) const
		"GetFbmTable@ff2f027be721db8e\0" // Result<void> GetFbmTable(FbmTableRef table, BaseArray<Float32>& fbm) const
		"GetRandomTable@88629c70edf0fd4d\0" // const BaseArray<Vector4d32>* GetRandomTable() const
		"SNoise@9f6dc5c3765010ea\0" // Float32 SNoise(const Vector32& p) const
		"SNoise@254714411258eeba\0" // Float32 SNoise(const Vector4d32& p) const
		"PeriodicSNoise@3c9cda8cfa673a95\0" // Float32 PeriodicSNoise(const Vector32& p, Int repeatX, Int repeatY, Int repeatZ) const
		"PeriodicSNoise@9abe1d392ad9e542\0" // Float32 PeriodicSNoise(const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT) const
		"Voronoi@2dc7d5c608b178b9\0" // void Voronoi(const Vector32& p, Int maximumOrder, Float32* distance, Int32* index) const
		"Voronoi@39b8fe0108526f09\0" // void Voronoi(const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index) const
		"InitFbm@cae1729a80060708\0" // ResultMemT<FbmTableRef> InitFbm(Float32 lacunarity, Float32 gain) const
		"Fbm@5ac61a3e38d57720\0" // Float32 Fbm(FbmTableRef table, Vector32 p, Float32 octaves) const
		"Fbm@208e0159215ba648\0" // Float32 Fbm(FbmTableRef table, Vector4d32 p, Float32 octaves) const
		"Turbulence@798d518b2ea06f76\0" // Float32 Turbulence(Vector32 p, Float32 octaves, Bool absolute) const
		"Turbulence@598df4ee67645fe6\0" // Float32 Turbulence(Vector4d32 p, Float32 octaves, Bool absolute) const
		"RidgedMultifractal@34c18a902169c04\0" // Float32 RidgedMultifractal(FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold) const
		"RidgedMultifractal@9a43943d834131ec\0" // Float32 RidgedMultifractal(FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold) const
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class NoiseInterface::Hxx2::Unresolved : public NoiseInterface
	{
	public:
		static const Unresolved* Get(const NoiseInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(NoiseInterface* o) { return (Unresolved*) o; }
		static void Free(const NoiseInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return NoiseInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static NoiseInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return NoiseInterface::Alloc(allocLocation); return nullptr;}
		Result<void> Init(UInt32 seed, Int permutationTablePower) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((NoiseInterface*) this)->Init(seed, permutationTablePower); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		UInt32 GetSeed() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->GetSeed(); return 0;}
		Int GetPermutationTablePower() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->GetPermutationTablePower(); return 0;}
		const BaseArray<UInt16>* GetPermutationTable() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->GetPermutationTable(); return nullptr;}
		Result<void> GetGradientTable(Bool gradient3D, BaseArray<Vector4d32>& gradient) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const NoiseInterface*) this)->GetGradientTable(gradient3D, gradient); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> GetFbmTable(FbmTableRef table, BaseArray<Float32>& fbm) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const NoiseInterface*) this)->GetFbmTable(std::forward<FbmTableRef>(table), fbm); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		const BaseArray<Vector4d32>* GetRandomTable() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->GetRandomTable(); return nullptr;}
		Float32 SNoise(const Vector32& p) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->SNoise(p); return 0;}
		Float32 SNoise(const Vector4d32& p) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->SNoise(p); return 0;}
		Float32 PeriodicSNoise(const Vector32& p, Int repeatX, Int repeatY, Int repeatZ) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->PeriodicSNoise(p, repeatX, repeatY, repeatZ); return 0;}
		Float32 PeriodicSNoise(const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->PeriodicSNoise(p, repeatX, repeatY, repeatZ, repeatT); return 0;}
		void Voronoi(const Vector32& p, Int maximumOrder, Float32* distance, Int32* index) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->Voronoi(p, maximumOrder, distance, index); return maxon::PrivateLogNullptrError();}
		void Voronoi(const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->Voronoi(p, maximumOrder, distance, index); return maxon::PrivateLogNullptrError();}
		ResultMemT<FbmTableRef> InitFbm(Float32 lacunarity, Float32 gain) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->InitFbm(lacunarity, gain); return maxon::PrivateIncompleteNullReturnValue<ResultMemT<FbmTableRef>>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Float32 Fbm(FbmTableRef table, Vector32 p, Float32 octaves) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->Fbm(std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves); return 0;}
		Float32 Fbm(FbmTableRef table, Vector4d32 p, Float32 octaves) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->Fbm(std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves); return 0;}
		Float32 Turbulence(Vector32 p, Float32 octaves, Bool absolute) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->Turbulence(std::forward<Vector32>(p), octaves, absolute); return 0;}
		Float32 Turbulence(Vector4d32 p, Float32 octaves, Bool absolute) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->Turbulence(std::forward<Vector4d32>(p), octaves, absolute); return 0;}
		Float32 RidgedMultifractal(FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->RidgedMultifractal(std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves, offset, threshold); return 0;}
		Float32 RidgedMultifractal(FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const NoiseInterface*) this)->RidgedMultifractal(std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves, offset, threshold); return 0;}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE NoiseInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<NoiseInterface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<UInt32>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<const BaseArray<UInt16>*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<const BaseArray<Vector4d32>*>::value,
		maxon::details::NullReturnType<Float32>::value,
		maxon::details::NullReturnType<Float32>::value,
		maxon::details::NullReturnType<Float32>::value,
		maxon::details::NullReturnType<Float32>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<ResultMemT<FbmTableRef>>::value,
		maxon::details::NullReturnType<Float32>::value,
		maxon::details::NullReturnType<Float32>::value,
		maxon::details::NullReturnType<Float32>::value,
		maxon::details::NullReturnType<Float32>::value,
		maxon::details::NullReturnType<Float32>::value,
		maxon::details::NullReturnType<Float32>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool NoiseInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_NoiseInterface_Init = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_Init;
		#else
		tbl->_NoiseInterface_Init = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_Init;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_GetSeed = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_GetSeed;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_GetPermutationTablePower = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_GetPermutationTablePower;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_GetPermutationTable = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_GetPermutationTable;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_NoiseInterface_GetGradientTable = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_GetGradientTable;
		#else
		tbl->_NoiseInterface_GetGradientTable = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_GetGradientTable;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_NoiseInterface_GetFbmTable = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_GetFbmTable;
		#else
		tbl->_NoiseInterface_GetFbmTable = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_GetFbmTable;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_GetRandomTable = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_GetRandomTable;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_SNoise = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_SNoise;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_SNoise_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_SNoise_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_PeriodicSNoise = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_PeriodicSNoise;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_PeriodicSNoise_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_PeriodicSNoise_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_Voronoi = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_Voronoi;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_Voronoi_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_Voronoi_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<ResultMemT<FbmTableRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_NoiseInterface_InitFbm = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_InitFbm;
		#else
		tbl->_NoiseInterface_InitFbm = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_InitFbm;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_Fbm = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_Fbm;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_Fbm_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_Fbm_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_Turbulence = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_Turbulence;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_Turbulence_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_Turbulence_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_RidgedMultifractal = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_RidgedMultifractal;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_NoiseInterface_RidgedMultifractal_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_NoiseInterface_RidgedMultifractal_1;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(NoiseInterface, "net.maxon.render.interface.noise", nullptr);
	template <typename DUMMY> maxon::Int NoiseInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<ResultMemT<FbmTableRef>>(OVERLOAD_MAX_RANK)
		;
	}
	namespace NOISEPROPERTY
	{
		LACUNARITY_PrivateAttribute LACUNARITY;
		GAIN_PrivateAttribute GAIN;
		EXPONENT_PrivateAttribute EXPONENT;
	}
	const maxon::Char* const RenderNoiseInterface::MTable::_ids = 
		"Init@1d3a4b77e0eb4d24\0" // Result<void> Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters)
		"Noise@b624e915785be6b\0" // Float32 Noise(const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const
		"Noise@b5aa570ca0edcca5\0" // Float32 Noise(const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const
	"";
	const maxon::METHOD_FLAGS RenderNoiseInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(RenderNoiseInterface, , "net.maxon.render.interface.rendernoise", "maxon.RenderNoiseInterface", (ObjectInterface::PrivateGetInterface()));
	MAXON_REGISTRY_REGISTER(RenderNoiseClasses);
	namespace RenderNoiseClasses
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(PERLIN, , "net.maxon.render.rendernoiseclass.perlin");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(FBM, , "net.maxon.render.rendernoiseclass.fbm");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(TURBULENCE, , "net.maxon.render.rendernoiseclass.turbulence");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(RIDGEDMULTIFRACTAL, , "net.maxon.render.rendernoiseclass.ridgedmultifractal");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(GASEOUS, , "net.maxon.render.rendernoiseclass.gaseous");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ELECTRIC, , "net.maxon.render.rendernoiseclass.electric");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BOX, , "net.maxon.render.rendernoiseclass.box");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BLISTEREDTURBULENCE, , "net.maxon.render.rendernoiseclass.blisteredturbulence");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CRANAL, , "net.maxon.render.rendernoiseclass.cranal");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(BUYA, , "net.maxon.render.rendernoiseclass.buya");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DENTS, , "net.maxon.render.rendernoiseclass.dents");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CELL, , "net.maxon.render.rendernoiseclass.cell");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DISPLACEDTURBULENCE, , "net.maxon.render.rendernoiseclass.displacedturbulence");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(HAMA, , "net.maxon.render.rendernoiseclass.hama");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(LUKA, , "net.maxon.render.rendernoiseclass.luka");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(MOD, , "net.maxon.render.rendernoiseclass.mod");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(NAKI, , "net.maxon.render.rendernoiseclass.naki");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(NUTOUS, , "net.maxon.render.rendernoiseclass.nutous");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(OBER, , "net.maxon.render.rendernoiseclass.ober");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(PEZO, , "net.maxon.render.rendernoiseclass.pezo");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(POXO, , "net.maxon.render.rendernoiseclass.poxo");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(SEMA, , "net.maxon.render.rendernoiseclass.sema");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(STUPL, , "net.maxon.render.rendernoiseclass.stupl");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(VL, , "net.maxon.render.rendernoiseclass.vl");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(WAVYTURBULENCE, , "net.maxon.render.rendernoiseclass.wavyturbulence");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(ZADA, , "net.maxon.render.rendernoiseclass.zada");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CELLVORONOI, , "net.maxon.render.rendernoiseclass.cellvoronoi");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DISPLACEDVORONOI, , "net.maxon.render.rendernoiseclass.displacedvoronoi");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(VORONOI1, , "net.maxon.render.rendernoiseclass.voronoi1");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(VORONOI2, , "net.maxon.render.rendernoiseclass.voronoi2");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(VORONOI3, , "net.maxon.render.rendernoiseclass.voronoi3");
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_noise(0
	| maxon::NoiseInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
