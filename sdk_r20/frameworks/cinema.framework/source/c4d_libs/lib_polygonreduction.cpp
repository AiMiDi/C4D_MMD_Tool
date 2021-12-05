#include "lib_polygonreduction.h"

static PolygonReductionLibrary* CheckPolygonReductionLib(Int32 offset)
{
	static PolygonReductionLibrary* polygonReduction_lib_cache = nullptr;

	return (PolygonReductionLibrary*)CheckLib(ID_POLYGONREDUCTION_LIB, offset, (C4DLibrary**)&polygonReduction_lib_cache);
}

PolygonReduction* PolygonReduction::Alloc()
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, Alloc));
	if (!lib || !lib->Alloc)
		return nullptr;

	return lib->Alloc();
}

void PolygonReduction::Free(PolygonReduction*& node)
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, Free));
	if (!lib || !lib->Free)
		return;

	lib->Free(node);
}

Bool PolygonReduction::PreProcess(const PolygonReductionData& data)
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, PreProcess));
	if (!lib || !lib->PreProcess)
		return false;

	return (((iPolygonReduction*)this)->*(lib->PreProcess))(data);
}

Bool PolygonReduction::IsPreprocessing()
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, IsPreprocessing));
	if (!lib || !lib->IsPreprocessing)
		return false;

	return (((iPolygonReduction*)this)->*(lib->IsPreprocessing))();
}

void PolygonReduction::StopPreprocessing()
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, StopPreprocessing));
	if (!lib || !lib->StopPreprocessing)
		return;

	(((iPolygonReduction*)this)->*(lib->StopPreprocessing))();
}

void PolygonReduction::Reset()
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, Reset));
	if (!lib || !lib->Reset)
		return;

	(((iPolygonReduction*)this)->*(lib->Reset))();
}

Bool PolygonReduction::SetReductionStrengthLevel(Float strengthLevel)
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, SetReductionStrengthLevel));
	if (!lib || !lib->SetReductionStrengthLevel)
		return false;

	return (((iPolygonReduction*)this)->*(lib->SetReductionStrengthLevel))(strengthLevel);
}

Bool PolygonReduction::SetTriangleLevel(Int32 desiredLevel)
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, SetTriangleLevel));
	if (!lib || !lib->SetTriangleLevel)
		return false;

	return (((iPolygonReduction*)this)->*(lib->SetTriangleLevel))(desiredLevel);
}

Bool PolygonReduction::SetVertexLevel(Int32 desiredLevel)
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, SetVertexLevel));
	if (!lib || !lib->SetVertexLevel)
		return false;

	return (((iPolygonReduction*)this)->*(lib->SetVertexLevel))(desiredLevel);
}

Bool PolygonReduction::SetRemainingEdgesLevel(Int32 desiredLevel)
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, SetRemainingEdgesLevel));
	if (!lib || !lib->SetRemainingEdgesLevel)
		return false;

	return (((iPolygonReduction*)this)->*(lib->SetRemainingEdgesLevel))(desiredLevel);
}

Float PolygonReduction::GetReductionStrengthLevel() const
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, GetReductionStrengthLevel));
	if (!lib || !lib->GetReductionStrengthLevel)
		return 0.0;

	return (((iPolygonReduction*)this)->*(lib->GetReductionStrengthLevel))();
}

Int32 PolygonReduction::GetTriangleLevel() const
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, GetTriangleLevel));
	if (!lib || !lib->GetTriangleLevel)
		return NOTOK;

	return (((iPolygonReduction*)this)->*(lib->GetTriangleLevel))();
}

Int32 PolygonReduction::GetVertexLevel() const
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, GetVertexLevel));
	if (!lib || !lib->GetVertexLevel)
		return NOTOK;

	return (((iPolygonReduction*)this)->*(lib->GetVertexLevel))();
}

Int32 PolygonReduction::GetRemainingEdgesLevel() const
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, GetRemainingEdgesLevel));
	if (!lib || !lib->GetRemainingEdgesLevel)
		return NOTOK;

	return (((iPolygonReduction*)this)->*(lib->GetRemainingEdgesLevel))();
}

Float PolygonReduction::GetMaxReductionStrengthLevel() const
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, GetMaxReductionStrengthLevel));
	if (!lib || !lib->GetMaxReductionStrengthLevel)
		return 0.0;

	return (((iPolygonReduction*)this)->*(lib->GetMaxReductionStrengthLevel))();
}

Int32 PolygonReduction::GetMaxTriangleLevel() const
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, GetMaxTriangleLevel));
	if (!lib || !lib->GetMaxTriangleLevel)
		return NOTOK;

	return (((iPolygonReduction*)this)->*(lib->GetMaxTriangleLevel))();
}

Int32 PolygonReduction::GetMaxVertexLevel() const
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, GetMaxVertexLevel));
	if (!lib || !lib->GetMaxVertexLevel)
		return NOTOK;

	return (((iPolygonReduction*)this)->*(lib->GetMaxVertexLevel))();
}

Int32 PolygonReduction::GetMaxRemainingEdgesLevel() const
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, GetMaxRemainingEdgesLevel));
	if (!lib || !lib->GetMaxRemainingEdgesLevel)
		return NOTOK;

	return (((iPolygonReduction*)this)->*(lib->GetMaxRemainingEdgesLevel))();
}

Int32 PolygonReduction::GetMinTriangleLevel() const
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, GetMinTriangleLevel));
	if (!lib || !lib->GetMinTriangleLevel)
		return NOTOK;

	return (((iPolygonReduction*)this)->*(lib->GetMinTriangleLevel))();
}

Int32 PolygonReduction::GetMinVertexLevel() const
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, GetMinVertexLevel));
	if (!lib || !lib->GetMinVertexLevel)
		return NOTOK;

	return (((iPolygonReduction*)this)->*(lib->GetMinVertexLevel))();
}

const PolygonReductionData& PolygonReduction::GetData() const
{
	// TODO: (Marc) Should return a pointer instead and not have to deal with a static instance?
	static PolygonReductionData emptyPolyReductionData;
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, GetData));
	if (!lib || !lib->GetData)
		return emptyPolyReductionData;

	return (((iPolygonReduction*)this)->*(lib->GetData))();
}

Bool PolygonReduction::IsValid() const
{
	PolygonReductionLibrary* lib = CheckPolygonReductionLib(LIBOFFSET(PolygonReductionLibrary, IsValid));
	if (!lib || !lib->IsValid)
		return false;

	return (((iPolygonReduction*)this)->*(lib->IsValid))();
}
