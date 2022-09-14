
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* NoiseInterface::PrivateGetCppName() { return "maxon::NoiseRef"; }

struct NoiseInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(NoiseInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const NoiseInterface* object);
	PRIVATE_MAXON_SF_POINTER(NoiseInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (NoiseInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_Init, Init, false, NoiseInterface,, (Result<void>), UInt32 seed, Int permutationTablePower);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_GetSeed, GetSeed, false, NoiseInterface, const, (UInt32));
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_GetPermutationTablePower, GetPermutationTablePower, false, NoiseInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_GetPermutationTable, GetPermutationTable, false, NoiseInterface, const, (const BaseArray<UInt16>*));
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_GetGradientTable, GetGradientTable, false, NoiseInterface, const, (Result<void>), Bool gradient3D, BaseArray<Vector4d32>& gradient);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_GetFbmTable, GetFbmTable, false, NoiseInterface, const, (Result<void>), FbmTableRef table, BaseArray<Float32>& fbm);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_GetRandomTable, GetRandomTable, false, NoiseInterface, const, (const BaseArray<Vector4d32>*));
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_SNoise, SNoise, false, NoiseInterface, const, (Float32), const Vector32& p);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_SNoise_1, SNoise, false, NoiseInterface, const, (Float32), const Vector4d32& p);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_PeriodicSNoise, PeriodicSNoise, false, NoiseInterface, const, (Float32), const Vector32& p, Int repeatX, Int repeatY, Int repeatZ);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_PeriodicSNoise_1, PeriodicSNoise, false, NoiseInterface, const, (Float32), const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_Voronoi, Voronoi, false, NoiseInterface, const, (void), const Vector32& p, Int maximumOrder, Float32* distance, Int32* index);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_Voronoi_1, Voronoi, false, NoiseInterface, const, (void), const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_InitFbm, InitFbm, false, NoiseInterface, const, (ResultMemT<FbmTableRef>), Float32 lacunarity, Float32 gain);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_Fbm, Fbm, false, NoiseInterface, const, (Float32), FbmTableRef table, Vector32 p, Float32 octaves);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_Fbm_1, Fbm, false, NoiseInterface, const, (Float32), FbmTableRef table, Vector4d32 p, Float32 octaves);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_Turbulence, Turbulence, false, NoiseInterface, const, (Float32), Vector32 p, Float32 octaves, Bool absolute);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_Turbulence_1, Turbulence, false, NoiseInterface, const, (Float32), Vector4d32 p, Float32 octaves, Bool absolute);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_RidgedMultifractal, RidgedMultifractal, false, NoiseInterface, const, (Float32), FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold);
	PRIVATE_MAXON_MF_POINTER(NoiseInterface_RidgedMultifractal_1, RidgedMultifractal, false, NoiseInterface, const, (Float32), FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold);
	template <typename IMPL> void Init()
	{
		NoiseInterface_Free = NoiseInterface_Free_GetPtr<IMPL>(true);
		NoiseInterface_Alloc = NoiseInterface_Alloc_GetPtr<IMPL>(true);
		NoiseInterface_Init = NoiseInterface_Init_GetPtr<IMPL>(0, true).first;
		NoiseInterface_GetSeed = NoiseInterface_GetSeed_GetPtr<IMPL>(0, true).first;
		NoiseInterface_GetPermutationTablePower = NoiseInterface_GetPermutationTablePower_GetPtr<IMPL>(0, true).first;
		NoiseInterface_GetPermutationTable = NoiseInterface_GetPermutationTable_GetPtr<IMPL>(0, true).first;
		NoiseInterface_GetGradientTable = NoiseInterface_GetGradientTable_GetPtr<IMPL>(0, true).first;
		NoiseInterface_GetFbmTable = NoiseInterface_GetFbmTable_GetPtr<IMPL>(0, true).first;
		NoiseInterface_GetRandomTable = NoiseInterface_GetRandomTable_GetPtr<IMPL>(0, true).first;
		NoiseInterface_SNoise = NoiseInterface_SNoise_GetPtr<IMPL>(0, true).first;
		NoiseInterface_SNoise_1 = NoiseInterface_SNoise_1_GetPtr<IMPL>(0, true).first;
		NoiseInterface_PeriodicSNoise = NoiseInterface_PeriodicSNoise_GetPtr<IMPL>(0, true).first;
		NoiseInterface_PeriodicSNoise_1 = NoiseInterface_PeriodicSNoise_1_GetPtr<IMPL>(0, true).first;
		NoiseInterface_Voronoi = NoiseInterface_Voronoi_GetPtr<IMPL>(0, true).first;
		NoiseInterface_Voronoi_1 = NoiseInterface_Voronoi_1_GetPtr<IMPL>(0, true).first;
		NoiseInterface_InitFbm = NoiseInterface_InitFbm_GetPtr<IMPL>(0, true).first;
		NoiseInterface_Fbm = NoiseInterface_Fbm_GetPtr<IMPL>(0, true).first;
		NoiseInterface_Fbm_1 = NoiseInterface_Fbm_1_GetPtr<IMPL>(0, true).first;
		NoiseInterface_Turbulence = NoiseInterface_Turbulence_GetPtr<IMPL>(0, true).first;
		NoiseInterface_Turbulence_1 = NoiseInterface_Turbulence_1_GetPtr<IMPL>(0, true).first;
		NoiseInterface_RidgedMultifractal = NoiseInterface_RidgedMultifractal_GetPtr<IMPL>(0, true).first;
		NoiseInterface_RidgedMultifractal_1 = NoiseInterface_RidgedMultifractal_1_GetPtr<IMPL>(0, true).first;
	}
};

struct NoiseInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void NoiseInterface_Free(const NoiseInterface* object) { return C::Free(object); }
		static NoiseInterface* NoiseInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_Init, NoiseInterface,, (Result<void>), UInt32 seed, Int permutationTablePower) { return C::Get(PRIVATE_MAXON_MF_THIS(NoiseInterface))->Init(seed, permutationTablePower); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_GetSeed, NoiseInterface, const, (UInt32)) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->GetSeed(); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_GetPermutationTablePower, NoiseInterface, const, (Int)) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->GetPermutationTablePower(); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_GetPermutationTable, NoiseInterface, const, (const BaseArray<UInt16>*)) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->GetPermutationTable(); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_GetGradientTable, NoiseInterface, const, (Result<void>), Bool gradient3D, BaseArray<Vector4d32>& gradient) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->GetGradientTable(gradient3D, gradient); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_GetFbmTable, NoiseInterface, const, (Result<void>), FbmTableRef table, BaseArray<Float32>& fbm) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->GetFbmTable(std::forward<FbmTableRef>(table), fbm); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_GetRandomTable, NoiseInterface, const, (const BaseArray<Vector4d32>*)) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->GetRandomTable(); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_SNoise, NoiseInterface, const, (Float32), const Vector32& p) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->SNoise(p); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_SNoise_1, NoiseInterface, const, (Float32), const Vector4d32& p) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->SNoise(p); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_PeriodicSNoise, NoiseInterface, const, (Float32), const Vector32& p, Int repeatX, Int repeatY, Int repeatZ) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->PeriodicSNoise(p, repeatX, repeatY, repeatZ); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_PeriodicSNoise_1, NoiseInterface, const, (Float32), const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->PeriodicSNoise(p, repeatX, repeatY, repeatZ, repeatT); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_Voronoi, NoiseInterface, const, (void), const Vector32& p, Int maximumOrder, Float32* distance, Int32* index) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->Voronoi(p, maximumOrder, distance, index); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_Voronoi_1, NoiseInterface, const, (void), const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->Voronoi(p, maximumOrder, distance, index); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_InitFbm, NoiseInterface, const, (ResultMemT<FbmTableRef>), Float32 lacunarity, Float32 gain) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->InitFbm(lacunarity, gain); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_Fbm, NoiseInterface, const, (Float32), FbmTableRef table, Vector32 p, Float32 octaves) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->Fbm(std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_Fbm_1, NoiseInterface, const, (Float32), FbmTableRef table, Vector4d32 p, Float32 octaves) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->Fbm(std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_Turbulence, NoiseInterface, const, (Float32), Vector32 p, Float32 octaves, Bool absolute) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->Turbulence(std::forward<Vector32>(p), octaves, absolute); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_Turbulence_1, NoiseInterface, const, (Float32), Vector4d32 p, Float32 octaves, Bool absolute) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->Turbulence(std::forward<Vector4d32>(p), octaves, absolute); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_RidgedMultifractal, NoiseInterface, const, (Float32), FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->RidgedMultifractal(std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves, offset, threshold); }
		PRIVATE_MAXON_MF_WRAPPER(NoiseInterface_RidgedMultifractal_1, NoiseInterface, const, (Float32), FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold) { return C::Get(PRIVATE_MAXON_MF_THIS(const NoiseInterface))->RidgedMultifractal(std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves, offset, threshold); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Free(const NoiseInterface* object) -> void
{
	return MTable::_instance.NoiseInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Alloc(const maxon::SourceLocation& allocLocation) -> NoiseInterface*
{
	return MTable::_instance.NoiseInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Init(UInt32 seed, Int permutationTablePower) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_Init, seed, permutationTablePower);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetSeed() const -> UInt32
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_GetSeed);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetPermutationTablePower() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_GetPermutationTablePower);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetPermutationTable() const -> const BaseArray<UInt16>*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_GetPermutationTable);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetGradientTable(Bool gradient3D, BaseArray<Vector4d32>& gradient) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_GetGradientTable, gradient3D, gradient);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetFbmTable(FbmTableRef table, BaseArray<Float32>& fbm) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_GetFbmTable, std::forward<FbmTableRef>(table), fbm);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetRandomTable() const -> const BaseArray<Vector4d32>*
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_GetRandomTable);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::SNoise(const Vector32& p) const -> Float32
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_SNoise, p);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::SNoise(const Vector4d32& p) const -> Float32
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_SNoise_1, p);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::PeriodicSNoise(const Vector32& p, Int repeatX, Int repeatY, Int repeatZ) const -> Float32
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_PeriodicSNoise, p, repeatX, repeatY, repeatZ);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::PeriodicSNoise(const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT) const -> Float32
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_PeriodicSNoise_1, p, repeatX, repeatY, repeatZ, repeatT);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Voronoi(const Vector32& p, Int maximumOrder, Float32* distance, Int32* index) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_Voronoi, p, maximumOrder, distance, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Voronoi(const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index) const -> void
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_Voronoi_1, p, maximumOrder, distance, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::InitFbm(Float32 lacunarity, Float32 gain) const -> ResultMemT<FbmTableRef>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_InitFbm, lacunarity, gain);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Fbm(FbmTableRef table, Vector32 p, Float32 octaves) const -> Float32
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_Fbm, std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Fbm(FbmTableRef table, Vector4d32 p, Float32 octaves) const -> Float32
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_Fbm_1, std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Turbulence(Vector32 p, Float32 octaves, Bool absolute) const -> Float32
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_Turbulence, std::forward<Vector32>(p), octaves, absolute);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Turbulence(Vector4d32 p, Float32 octaves, Bool absolute) const -> Float32
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_Turbulence_1, std::forward<Vector4d32>(p), octaves, absolute);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::RidgedMultifractal(FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold) const -> Float32
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_RidgedMultifractal, std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves, offset, threshold);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::RidgedMultifractal(FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold) const -> Float32
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.NoiseInterface_RidgedMultifractal_1, std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves, offset, threshold);
}

auto NoiseInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<NoiseRef>
{
	NoiseInterface* res_ = NoiseInterface::Alloc(MAXON_SOURCE_LOCATION);
	return NoiseRef(maxon::ForwardResultPtr<NoiseInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::Fn<S>::Init(UInt32 seed, Int permutationTablePower) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); NoiseInterface* o_ = (NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_Init, seed, permutationTablePower));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::GetSeed() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_GetSeed));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::GetPermutationTablePower() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_GetPermutationTablePower));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::GetPermutationTable() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<UInt16>*>, const BaseArray<UInt16>*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<UInt16>*>, const BaseArray<UInt16>*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_GetPermutationTable));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::GetGradientTable(Bool gradient3D, BaseArray<Vector4d32>& gradient) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_GetGradientTable, gradient3D, gradient));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::GetFbmTable(FbmTableRef table, BaseArray<Float32>& fbm) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_GetFbmTable, std::forward<FbmTableRef>(table), fbm));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::GetRandomTable() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector4d32>*>, const BaseArray<Vector4d32>*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector4d32>*>, const BaseArray<Vector4d32>*>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_GetRandomTable));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::SNoise(const Vector32& p) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_SNoise, p));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::SNoise(const Vector4d32& p) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_SNoise_1, p));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::SNoise(const Vector32& p, Float32 time) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (o_->SNoise(p, time));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::PeriodicSNoise(const Vector32& p, Int repeatX, Int repeatY, Int repeatZ) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_PeriodicSNoise, p, repeatX, repeatY, repeatZ));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::PeriodicSNoise(const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_PeriodicSNoise_1, p, repeatX, repeatY, repeatZ, repeatT));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::Voronoi(const Vector32& p, Int maximumOrder, Float32* distance, Int32* index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_Voronoi, p, maximumOrder, distance, index);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::Voronoi(const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_Voronoi_1, p, maximumOrder, distance, index);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::InitFbm(Float32 lacunarity, Float32 gain) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ResultMemT<FbmTableRef>>, ResultMemT<FbmTableRef>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ResultMemT<FbmTableRef>>, ResultMemT<FbmTableRef>>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ResultMemT<FbmTableRef>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_InitFbm, lacunarity, gain));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::Fbm(FbmTableRef table, Vector32 p, Float32 octaves) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_Fbm, std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::Fbm(FbmTableRef table, Vector4d32 p, Float32 octaves) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_Fbm_1, std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::Turbulence(Vector32 p, Float32 octaves, Bool absolute) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_Turbulence, std::forward<Vector32>(p), octaves, absolute));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::Turbulence(Vector4d32 p, Float32 octaves, Bool absolute) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_Turbulence_1, std::forward<Vector4d32>(p), octaves, absolute));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::RidgedMultifractal(FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_RidgedMultifractal, std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves, offset, threshold));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::RidgedMultifractal(FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.NoiseInterface_RidgedMultifractal_1, std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves, offset, threshold));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_noise)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_NoiseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_NoiseInterface() { new (s_ui_maxon_NoiseInterface) maxon::EntityUse(NoiseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/noise.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_NoiseInterface(NoiseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/noise.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct RenderNoiseInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Init);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Noise);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_MF_POINTER(RenderNoiseInterface_Init, Init, true, maxon::GenericComponent,, (Result<void>), UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters);
	maxon::Int RenderNoiseInterface_Init_Offset;
	PRIVATE_MAXON_MF_POINTER(RenderNoiseInterface_Noise, Noise, true, maxon::GenericComponent, const, (Float32), const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius);
	maxon::Int RenderNoiseInterface_Noise_Offset;
	PRIVATE_MAXON_MF_POINTER(RenderNoiseInterface_Noise_1, Noise, true, maxon::GenericComponent, const, (Float32), const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius);
	maxon::Int RenderNoiseInterface_Noise_1_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, RenderNoiseInterface, Init))
	{
		maxon::Tie(RenderNoiseInterface_Init, RenderNoiseInterface_Init_Offset) = RenderNoiseInterface_Init_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, RenderNoiseInterface, Noise))
	{
		maxon::Tie(RenderNoiseInterface_Noise, RenderNoiseInterface_Noise_Offset) = RenderNoiseInterface_Noise_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, RenderNoiseInterface, Noise))
	{
		maxon::Tie(RenderNoiseInterface_Noise_1, RenderNoiseInterface_Noise_1_Offset) = RenderNoiseInterface_Noise_1_GetPtr<W>(offset, true);
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<RenderNoiseInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<RenderNoiseInterface, SUPER>;
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct RenderNoiseInterface::Hxx2
{
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Init);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Noise);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (RenderNoiseInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, RenderNoiseInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(RenderNoiseInterface_Init, maxon::GenericComponent,, (Result<void>), UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters) { return ((typename S::Implementation*) PRIVATE_MAXON_MF_THIS(maxon::GenericComponent))->Init(seed, permutationTablePower, additionalParameters); }
		PRIVATE_MAXON_MF_WRAPPER(RenderNoiseInterface_Noise, maxon::GenericComponent, const, (Float32), const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Noise(p, time, octaves, absolute, sampleRadius); }
		PRIVATE_MAXON_MF_WRAPPER(RenderNoiseInterface_Noise_1, maxon::GenericComponent, const, (Float32), const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Noise(p, time, octaves, absolute, sampleRadius); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters) -> Result<void>
{
	const RenderNoiseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(RenderNoiseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((maxon::GenericComponent*) this + mt_.RenderNoiseInterface_Init_Offset), mt_.RenderNoiseInterface_Init, seed, permutationTablePower, additionalParameters);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Noise(const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const -> Float32
{
	const RenderNoiseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(RenderNoiseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.RenderNoiseInterface_Noise_Offset), mt_.RenderNoiseInterface_Noise, p, time, octaves, absolute, sampleRadius);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Noise(const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const -> Float32
{
	const RenderNoiseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(RenderNoiseInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.RenderNoiseInterface_Noise_1_Offset), mt_.RenderNoiseInterface_Noise_1, p, time, octaves, absolute, sampleRadius);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Hxx1::Fn<S>::Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); RenderNoiseInterface* o_ = (RenderNoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(RenderNoiseInterface, o_, RenderNoiseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<RenderNoiseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<RenderNoiseInterface>() : PRIVATE_MAXON_VTABLE(RenderNoiseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.RenderNoiseInterface_Init_Offset), mt_.RenderNoiseInterface_Init, seed, permutationTablePower, additionalParameters));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Hxx1::COWFn<S>::Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); RenderNoiseInterface* o_ = (RenderNoiseInterface*) this->MakeWritable(true).GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(RenderNoiseInterface, o_, RenderNoiseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<RenderNoiseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<RenderNoiseInterface>() : PRIVATE_MAXON_VTABLE(RenderNoiseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.RenderNoiseInterface_Init_Offset), mt_.RenderNoiseInterface_Init, seed, permutationTablePower, additionalParameters));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Hxx1::ConstFn<S>::Noise(const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const RenderNoiseInterface* o_ = (const RenderNoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = RenderNoiseInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(RenderNoiseInterface, o_, RenderNoiseInterface_Noise) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<RenderNoiseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<RenderNoiseInterface>() : PRIVATE_MAXON_VTABLE(RenderNoiseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.RenderNoiseInterface_Noise_Offset), mt_.RenderNoiseInterface_Noise, p, time, octaves, absolute, sampleRadius));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Hxx1::ConstFn<S>::Noise(const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const RenderNoiseInterface* o_ = (const RenderNoiseInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = RenderNoiseInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(RenderNoiseInterface, o_, RenderNoiseInterface_Noise_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<RenderNoiseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<RenderNoiseInterface>() : PRIVATE_MAXON_VTABLE(RenderNoiseInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.RenderNoiseInterface_Noise_1_Offset), mt_.RenderNoiseInterface_Noise_1, p, time, octaves, absolute, sampleRadius));
}
auto RenderNoiseInterface::GetPtr() -> Ptr { return Ptr(this); }
auto RenderNoiseInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_noise)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_RenderNoiseInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_RenderNoiseInterface() { new (s_ui_maxon_RenderNoiseInterface) maxon::EntityUse(RenderNoiseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/noise.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_RenderNoiseInterface(RenderNoiseInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/noise.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

