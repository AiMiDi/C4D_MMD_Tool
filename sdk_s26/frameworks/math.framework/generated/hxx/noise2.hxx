
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
	void (*NoiseInterface_Free) (const NoiseInterface* object);
	NoiseInterface* (*NoiseInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	Result<void> (*NoiseInterface_Init) (NoiseInterface* this_, UInt32 seed, Int permutationTablePower);
	UInt32 (*NoiseInterface_GetSeed) (const NoiseInterface* this_);
	Int (*NoiseInterface_GetPermutationTablePower) (const NoiseInterface* this_);
	const BaseArray<UInt16>* (*NoiseInterface_GetPermutationTable) (const NoiseInterface* this_);
	Result<void> (*NoiseInterface_GetGradientTable) (const NoiseInterface* this_, Bool gradient3D, BaseArray<Vector4d32>& gradient);
	Result<void> (*NoiseInterface_GetFbmTable) (const NoiseInterface* this_, FbmTableRef table, BaseArray<Float32>& fbm);
	const BaseArray<Vector4d32>* (*NoiseInterface_GetRandomTable) (const NoiseInterface* this_);
	Float32 (*NoiseInterface_SNoise) (const NoiseInterface* this_, const Vector32& p);
	Float32 (*NoiseInterface_SNoise_1) (const NoiseInterface* this_, const Vector4d32& p);
	Float32 (*NoiseInterface_PeriodicSNoise) (const NoiseInterface* this_, const Vector32& p, Int repeatX, Int repeatY, Int repeatZ);
	Float32 (*NoiseInterface_PeriodicSNoise_1) (const NoiseInterface* this_, const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT);
	void (*NoiseInterface_Voronoi) (const NoiseInterface* this_, const Vector32& p, Int maximumOrder, Float32* distance, Int32* index);
	void (*NoiseInterface_Voronoi_1) (const NoiseInterface* this_, const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index);
	ResultMemT<FbmTableRef> (*NoiseInterface_InitFbm) (const NoiseInterface* this_, Float32 lacunarity, Float32 gain);
	Float32 (*NoiseInterface_Fbm) (const NoiseInterface* this_, FbmTableRef table, Vector32 p, Float32 octaves);
	Float32 (*NoiseInterface_Fbm_1) (const NoiseInterface* this_, FbmTableRef table, Vector4d32 p, Float32 octaves);
	Float32 (*NoiseInterface_Turbulence) (const NoiseInterface* this_, Vector32 p, Float32 octaves, Bool absolute);
	Float32 (*NoiseInterface_Turbulence_1) (const NoiseInterface* this_, Vector4d32 p, Float32 octaves, Bool absolute);
	Float32 (*NoiseInterface_RidgedMultifractal) (const NoiseInterface* this_, FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold);
	Float32 (*NoiseInterface_RidgedMultifractal_1) (const NoiseInterface* this_, FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold);
	template <typename IMPL> void Init()
	{
		NoiseInterface_Free = &IMPL::NoiseInterface_Free;
		NoiseInterface_Alloc = &IMPL::NoiseInterface_Alloc;
		NoiseInterface_Init = &IMPL::NoiseInterface_Init;
		NoiseInterface_GetSeed = &IMPL::NoiseInterface_GetSeed;
		NoiseInterface_GetPermutationTablePower = &IMPL::NoiseInterface_GetPermutationTablePower;
		NoiseInterface_GetPermutationTable = &IMPL::NoiseInterface_GetPermutationTable;
		NoiseInterface_GetGradientTable = &IMPL::NoiseInterface_GetGradientTable;
		NoiseInterface_GetFbmTable = &IMPL::NoiseInterface_GetFbmTable;
		NoiseInterface_GetRandomTable = &IMPL::NoiseInterface_GetRandomTable;
		NoiseInterface_SNoise = &IMPL::NoiseInterface_SNoise;
		NoiseInterface_SNoise_1 = &IMPL::NoiseInterface_SNoise_1;
		NoiseInterface_PeriodicSNoise = &IMPL::NoiseInterface_PeriodicSNoise;
		NoiseInterface_PeriodicSNoise_1 = &IMPL::NoiseInterface_PeriodicSNoise_1;
		NoiseInterface_Voronoi = &IMPL::NoiseInterface_Voronoi;
		NoiseInterface_Voronoi_1 = &IMPL::NoiseInterface_Voronoi_1;
		NoiseInterface_InitFbm = &IMPL::NoiseInterface_InitFbm;
		NoiseInterface_Fbm = &IMPL::NoiseInterface_Fbm;
		NoiseInterface_Fbm_1 = &IMPL::NoiseInterface_Fbm_1;
		NoiseInterface_Turbulence = &IMPL::NoiseInterface_Turbulence;
		NoiseInterface_Turbulence_1 = &IMPL::NoiseInterface_Turbulence_1;
		NoiseInterface_RidgedMultifractal = &IMPL::NoiseInterface_RidgedMultifractal;
		NoiseInterface_RidgedMultifractal_1 = &IMPL::NoiseInterface_RidgedMultifractal_1;
	}
};

struct NoiseInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void NoiseInterface_Free(const NoiseInterface* object) { return C::Free(object); }
		static NoiseInterface* NoiseInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static Result<void> NoiseInterface_Init(NoiseInterface* this_, UInt32 seed, Int permutationTablePower) { return C::Get(this_)->Init(seed, permutationTablePower); }
		static UInt32 NoiseInterface_GetSeed(const NoiseInterface* this_) { return C::Get(this_)->GetSeed(); }
		static Int NoiseInterface_GetPermutationTablePower(const NoiseInterface* this_) { return C::Get(this_)->GetPermutationTablePower(); }
		static const BaseArray<UInt16>* NoiseInterface_GetPermutationTable(const NoiseInterface* this_) { return C::Get(this_)->GetPermutationTable(); }
		static Result<void> NoiseInterface_GetGradientTable(const NoiseInterface* this_, Bool gradient3D, BaseArray<Vector4d32>& gradient) { return C::Get(this_)->GetGradientTable(gradient3D, gradient); }
		static Result<void> NoiseInterface_GetFbmTable(const NoiseInterface* this_, FbmTableRef table, BaseArray<Float32>& fbm) { return C::Get(this_)->GetFbmTable(std::forward<FbmTableRef>(table), fbm); }
		static const BaseArray<Vector4d32>* NoiseInterface_GetRandomTable(const NoiseInterface* this_) { return C::Get(this_)->GetRandomTable(); }
		static Float32 NoiseInterface_SNoise(const NoiseInterface* this_, const Vector32& p) { return C::Get(this_)->SNoise(p); }
		static Float32 NoiseInterface_SNoise_1(const NoiseInterface* this_, const Vector4d32& p) { return C::Get(this_)->SNoise(p); }
		static Float32 NoiseInterface_PeriodicSNoise(const NoiseInterface* this_, const Vector32& p, Int repeatX, Int repeatY, Int repeatZ) { return C::Get(this_)->PeriodicSNoise(p, repeatX, repeatY, repeatZ); }
		static Float32 NoiseInterface_PeriodicSNoise_1(const NoiseInterface* this_, const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT) { return C::Get(this_)->PeriodicSNoise(p, repeatX, repeatY, repeatZ, repeatT); }
		static void NoiseInterface_Voronoi(const NoiseInterface* this_, const Vector32& p, Int maximumOrder, Float32* distance, Int32* index) { return C::Get(this_)->Voronoi(p, maximumOrder, distance, index); }
		static void NoiseInterface_Voronoi_1(const NoiseInterface* this_, const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index) { return C::Get(this_)->Voronoi(p, maximumOrder, distance, index); }
		static ResultMemT<FbmTableRef> NoiseInterface_InitFbm(const NoiseInterface* this_, Float32 lacunarity, Float32 gain) { return C::Get(this_)->InitFbm(lacunarity, gain); }
		static Float32 NoiseInterface_Fbm(const NoiseInterface* this_, FbmTableRef table, Vector32 p, Float32 octaves) { return C::Get(this_)->Fbm(std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves); }
		static Float32 NoiseInterface_Fbm_1(const NoiseInterface* this_, FbmTableRef table, Vector4d32 p, Float32 octaves) { return C::Get(this_)->Fbm(std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves); }
		static Float32 NoiseInterface_Turbulence(const NoiseInterface* this_, Vector32 p, Float32 octaves, Bool absolute) { return C::Get(this_)->Turbulence(std::forward<Vector32>(p), octaves, absolute); }
		static Float32 NoiseInterface_Turbulence_1(const NoiseInterface* this_, Vector4d32 p, Float32 octaves, Bool absolute) { return C::Get(this_)->Turbulence(std::forward<Vector4d32>(p), octaves, absolute); }
		static Float32 NoiseInterface_RidgedMultifractal(const NoiseInterface* this_, FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold) { return C::Get(this_)->RidgedMultifractal(std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves, offset, threshold); }
		static Float32 NoiseInterface_RidgedMultifractal_1(const NoiseInterface* this_, FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold) { return C::Get(this_)->RidgedMultifractal(std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves, offset, threshold); }
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
	return MTable::_instance.NoiseInterface_Init(this, seed, permutationTablePower);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetSeed() const -> UInt32
{
	return MTable::_instance.NoiseInterface_GetSeed(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetPermutationTablePower() const -> Int
{
	return MTable::_instance.NoiseInterface_GetPermutationTablePower(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetPermutationTable() const -> const BaseArray<UInt16>*
{
	return MTable::_instance.NoiseInterface_GetPermutationTable(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetGradientTable(Bool gradient3D, BaseArray<Vector4d32>& gradient) const -> Result<void>
{
	return MTable::_instance.NoiseInterface_GetGradientTable(this, gradient3D, gradient);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetFbmTable(FbmTableRef table, BaseArray<Float32>& fbm) const -> Result<void>
{
	return MTable::_instance.NoiseInterface_GetFbmTable(this, std::forward<FbmTableRef>(table), fbm);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::GetRandomTable() const -> const BaseArray<Vector4d32>*
{
	return MTable::_instance.NoiseInterface_GetRandomTable(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::SNoise(const Vector32& p) const -> Float32
{
	return MTable::_instance.NoiseInterface_SNoise(this, p);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::SNoise(const Vector4d32& p) const -> Float32
{
	return MTable::_instance.NoiseInterface_SNoise_1(this, p);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::PeriodicSNoise(const Vector32& p, Int repeatX, Int repeatY, Int repeatZ) const -> Float32
{
	return MTable::_instance.NoiseInterface_PeriodicSNoise(this, p, repeatX, repeatY, repeatZ);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::PeriodicSNoise(const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT) const -> Float32
{
	return MTable::_instance.NoiseInterface_PeriodicSNoise_1(this, p, repeatX, repeatY, repeatZ, repeatT);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Voronoi(const Vector32& p, Int maximumOrder, Float32* distance, Int32* index) const -> void
{
	return MTable::_instance.NoiseInterface_Voronoi(this, p, maximumOrder, distance, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Voronoi(const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index) const -> void
{
	return MTable::_instance.NoiseInterface_Voronoi_1(this, p, maximumOrder, distance, index);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::InitFbm(Float32 lacunarity, Float32 gain) const -> ResultMemT<FbmTableRef>
{
	return MTable::_instance.NoiseInterface_InitFbm(this, lacunarity, gain);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Fbm(FbmTableRef table, Vector32 p, Float32 octaves) const -> Float32
{
	return MTable::_instance.NoiseInterface_Fbm(this, std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Fbm(FbmTableRef table, Vector4d32 p, Float32 octaves) const -> Float32
{
	return MTable::_instance.NoiseInterface_Fbm_1(this, std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Turbulence(Vector32 p, Float32 octaves, Bool absolute) const -> Float32
{
	return MTable::_instance.NoiseInterface_Turbulence(this, std::forward<Vector32>(p), octaves, absolute);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Turbulence(Vector4d32 p, Float32 octaves, Bool absolute) const -> Float32
{
	return MTable::_instance.NoiseInterface_Turbulence_1(this, std::forward<Vector4d32>(p), octaves, absolute);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::RidgedMultifractal(FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold) const -> Float32
{
	return MTable::_instance.NoiseInterface_RidgedMultifractal(this, std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves, offset, threshold);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::RidgedMultifractal(FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold) const -> Float32
{
	return MTable::_instance.NoiseInterface_RidgedMultifractal_1(this, std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves, offset, threshold);
}

auto NoiseInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<NoiseRef>
{
	NoiseInterface* res_ = NoiseInterface::Alloc(MAXON_SOURCE_LOCATION);
	return NoiseRef(maxon::ForwardResultPtr<NoiseInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::Fn<S>::Init(UInt32 seed, Int permutationTablePower) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); NoiseInterface* o_ = (NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.NoiseInterface_Init(o_, seed, permutationTablePower));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::GetSeed() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<UInt32>, UInt32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.NoiseInterface_GetSeed(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::GetPermutationTablePower() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.NoiseInterface_GetPermutationTablePower(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::GetPermutationTable() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<UInt16>*>, const BaseArray<UInt16>*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<UInt16>*>, const BaseArray<UInt16>*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (MTable::_instance.NoiseInterface_GetPermutationTable(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::GetGradientTable(Bool gradient3D, BaseArray<Vector4d32>& gradient) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.NoiseInterface_GetGradientTable(o_, gradient3D, gradient));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::GetFbmTable(FbmTableRef table, BaseArray<Float32>& fbm) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance.NoiseInterface_GetFbmTable(o_, std::forward<FbmTableRef>(table), fbm));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::GetRandomTable() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector4d32>*>, const BaseArray<Vector4d32>*>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const BaseArray<Vector4d32>*>, const BaseArray<Vector4d32>*>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return nullptr; } 
	return (MTable::_instance.NoiseInterface_GetRandomTable(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::SNoise(const Vector32& p) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.NoiseInterface_SNoise(o_, p));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::SNoise(const Vector4d32& p) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.NoiseInterface_SNoise_1(o_, p));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::SNoise(const Vector32& p, Float32 time) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (o_->SNoise(p, time));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::PeriodicSNoise(const Vector32& p, Int repeatX, Int repeatY, Int repeatZ) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.NoiseInterface_PeriodicSNoise(o_, p, repeatX, repeatY, repeatZ));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::PeriodicSNoise(const Vector4d32& p, Int repeatX, Int repeatY, Int repeatZ, Int repeatT) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.NoiseInterface_PeriodicSNoise_1(o_, p, repeatX, repeatY, repeatZ, repeatT));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::Voronoi(const Vector32& p, Int maximumOrder, Float32* distance, Int32* index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.NoiseInterface_Voronoi(o_, p, maximumOrder, distance, index);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::Voronoi(const Vector4d32& p, Int maximumOrder, Float32* distance, Int32* index) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(); } 
	MTable::_instance.NoiseInterface_Voronoi_1(o_, p, maximumOrder, distance, index);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::InitFbm(Float32 lacunarity, Float32 gain) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<ResultMemT<FbmTableRef>>, ResultMemT<FbmTableRef>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<ResultMemT<FbmTableRef>>, ResultMemT<FbmTableRef>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<ResultMemT<FbmTableRef>>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.NoiseInterface_InitFbm(o_, lacunarity, gain));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::Fbm(FbmTableRef table, Vector32 p, Float32 octaves) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.NoiseInterface_Fbm(o_, std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::Fbm(FbmTableRef table, Vector4d32 p, Float32 octaves) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.NoiseInterface_Fbm_1(o_, std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::Turbulence(Vector32 p, Float32 octaves, Bool absolute) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.NoiseInterface_Turbulence(o_, std::forward<Vector32>(p), octaves, absolute));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::Turbulence(Vector4d32 p, Float32 octaves, Bool absolute) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.NoiseInterface_Turbulence_1(o_, std::forward<Vector4d32>(p), octaves, absolute));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::RidgedMultifractal(FbmTableRef table, Vector32 p, Float32 octaves, Float32 offset, Float32 threshold) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.NoiseInterface_RidgedMultifractal(o_, std::forward<FbmTableRef>(table), std::forward<Vector32>(p), octaves, offset, threshold));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto NoiseInterface::Hxx1::ConstFn<S>::RidgedMultifractal(FbmTableRef table, Vector4d32 p, Float32 octaves, Float32 offset, Float32 threshold) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const NoiseInterface* o_ = (const NoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = NoiseInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance.NoiseInterface_RidgedMultifractal_1(o_, std::forward<FbmTableRef>(table), std::forward<Vector4d32>(p), octaves, offset, threshold));
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
	Result<void> (*RenderNoiseInterface_Init) (maxon::GenericComponent* this_, UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters);
	maxon::Int RenderNoiseInterface_Init_Offset;
	Float32 (*RenderNoiseInterface_Noise) (const maxon::GenericComponent* this_, const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius);
	maxon::Int RenderNoiseInterface_Noise_Offset;
	Float32 (*RenderNoiseInterface_Noise_1) (const maxon::GenericComponent* this_, const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius);
	maxon::Int RenderNoiseInterface_Noise_1_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, RenderNoiseInterface, Init))
	{
		RenderNoiseInterface_Init = &W::RenderNoiseInterface_Init;
		RenderNoiseInterface_Init_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, RenderNoiseInterface, Noise))
	{
		RenderNoiseInterface_Noise = &W::RenderNoiseInterface_Noise;
		RenderNoiseInterface_Noise_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, RenderNoiseInterface, Noise))
	{
		RenderNoiseInterface_Noise_1 = &W::RenderNoiseInterface_Noise_1;
		RenderNoiseInterface_Noise_1_Offset = offset;
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
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (RenderNoiseInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, RenderNoiseInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static Result<void> RenderNoiseInterface_Init(maxon::GenericComponent* this_, UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters) { return ((typename S::Implementation*) this_)->Init(seed, permutationTablePower, additionalParameters); }
		static Float32 RenderNoiseInterface_Noise(const maxon::GenericComponent* this_, const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) { return ((const typename S::Implementation*) this_)->Noise(p, time, octaves, absolute, sampleRadius); }
		static Float32 RenderNoiseInterface_Noise_1(const maxon::GenericComponent* this_, const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) { return ((const typename S::Implementation*) this_)->Noise(p, time, octaves, absolute, sampleRadius); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters) -> Result<void>
{
	const RenderNoiseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(RenderNoiseInterface, this); return mt_.RenderNoiseInterface_Init((maxon::GenericComponent*) this + mt_.RenderNoiseInterface_Init_Offset, seed, permutationTablePower, additionalParameters);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Noise(const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const -> Float32
{
	const RenderNoiseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(RenderNoiseInterface, this); return mt_.RenderNoiseInterface_Noise((const maxon::GenericComponent*) this + mt_.RenderNoiseInterface_Noise_Offset, p, time, octaves, absolute, sampleRadius);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Noise(const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const -> Float32
{
	const RenderNoiseInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(RenderNoiseInterface, this); return mt_.RenderNoiseInterface_Noise_1((const maxon::GenericComponent*) this + mt_.RenderNoiseInterface_Noise_1_Offset, p, time, octaves, absolute, sampleRadius);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Hxx1::Fn<S>::Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); RenderNoiseInterface* o_ = (RenderNoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(RenderNoiseInterface, o_, RenderNoiseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<RenderNoiseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<RenderNoiseInterface>() : PRIVATE_MAXON_VTABLE(RenderNoiseInterface, o_); 
	return (mt_.RenderNoiseInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.RenderNoiseInterface_Init_Offset, seed, permutationTablePower, additionalParameters));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Hxx1::COWFn<S>::Init(UInt32 seed, Int permutationTablePower, const DataDictionary& additionalParameters) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); RenderNoiseInterface* o_ = (RenderNoiseInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(RenderNoiseInterface, o_, RenderNoiseInterface_Init) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<RenderNoiseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<RenderNoiseInterface>() : PRIVATE_MAXON_VTABLE(RenderNoiseInterface, o_); 
	return (mt_.RenderNoiseInterface_Init(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.RenderNoiseInterface_Init_Offset, seed, permutationTablePower, additionalParameters));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Hxx1::ConstFn<S>::Noise(const Vector32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const RenderNoiseInterface* o_ = (const RenderNoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = RenderNoiseInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(RenderNoiseInterface, o_, RenderNoiseInterface_Noise) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<RenderNoiseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<RenderNoiseInterface>() : PRIVATE_MAXON_VTABLE(RenderNoiseInterface, o_); 
	return (mt_.RenderNoiseInterface_Noise(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.RenderNoiseInterface_Noise_Offset, p, time, octaves, absolute, sampleRadius));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto RenderNoiseInterface::Hxx1::ConstFn<S>::Noise(const Vector2d32& p, Float32 time, Float32 octaves, Bool absolute, Float32 sampleRadius) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Float32>, Float32>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const RenderNoiseInterface* o_ = (const RenderNoiseInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = RenderNoiseInterface::NullValuePtr(); if (!o_) return 0; } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(RenderNoiseInterface, o_, RenderNoiseInterface_Noise_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<RenderNoiseInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<RenderNoiseInterface>() : PRIVATE_MAXON_VTABLE(RenderNoiseInterface, o_); 
	return (mt_.RenderNoiseInterface_Noise_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.RenderNoiseInterface_Noise_1_Offset, p, time, octaves, absolute, sampleRadius));
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

