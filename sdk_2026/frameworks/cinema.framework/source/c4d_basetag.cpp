#include "c4d_memory.h"
#include "c4d_basetag.h"

namespace cinema
{

class CINEWARE_SINGLEINHERITANCE BaseSelect;
class CINEWARE_SINGLEINHERITANCE EdgeBaseSelect;

Int32 VariableTag::GetDataCount() const
{
	return C4DOS_Tg->GetDataCount(this);
}

Int32 VariableTag::GetDataSize() const
{
	return C4DOS_Tg->GetDataSize(this);
}

maxon::UniqueHash VariableTag::GetDataHash() const
{
	return C4DOS_Tg->GetDataHash(this);
}

const VariableTagDataRef<>& VariableTag::GetData() const
{
	return C4DOS_Tg->GetVariableTagData(this);
}

const BaseSelect* SelectionTag::GetBaseSelect() const
{
	return C4DOS_Tg->GetBaseSelect(this);
}

BaseSelect* SelectionTag::GetWritableBaseSelect()
{
	return C4DOS_Tg->GetWritableBaseSelect(this);
}

Vector TextureTag::GetPos() const
{
	return C4DOS_Tx->GetPos(this);
}

Vector TextureTag::GetScale() const
{
	return C4DOS_Tx->GetScale(this);
}

Vector TextureTag::GetRot() const
{
	return C4DOS_Tx->GetRot(this);
}

Matrix TextureTag::GetMl() const
{
	return C4DOS_Tx->GetMl(this);
}

void TextureTag::SetPos(const Vector& v)
{
	C4DOS_Tx->SetPos(this, v);
}

void TextureTag::SetScale(const Vector& v)
{
	C4DOS_Tx->SetScale(this, v);
}

void TextureTag::SetRot(const Vector& v)
{
	C4DOS_Tx->SetRot(this, v);
}

void TextureTag::SetMl(const Matrix& m)
{
	C4DOS_Tx->SetMl(this, m);
}

BaseMaterial* TextureTag::GetMaterial(Bool ignoredoc) const
{
	return C4DOS_Tx->GetMaterial(this, ignoredoc);
}

void TextureTag::SetMaterial(BaseMaterial* mat)
{
	C4DOS_Tx->SetMaterial(this, mat);
}

Bool StickTextureTag::Record(BaseObject* op, Bool always)
{
	return C4DOS_Tg->Record(this, op, always);
}

BaseTag* BaseTag::Alloc(Int32 type)
{
	return C4DOS_Tg->Alloc(type, 0);
}

void BaseTag::Free(BaseTag*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

VariableTag* VariableTag::Alloc(Int32 type, Int32 count)
{
	return (VariableTag*)C4DOS_Tg->Alloc(type, count);
}

void VariableTag::Free(VariableTag*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

SelectionTag* SelectionTag::Alloc(Int32 type)
{
	return (SelectionTag*)C4DOS_Tg->Alloc(type, 0);
}

void SelectionTag::Free(SelectionTag*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

VertexMapTag* VertexMapTag::Alloc(Int32 count)
{
	return (VertexMapTag*)C4DOS_Tg->Alloc(Tvertexmap, count);
}

void VertexMapTag::Free(VertexMapTag*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

NormalTag* NormalTag::Alloc(Int32 count)
{
	return (NormalTag*)C4DOS_Tg->Alloc(Tnormal, count);
}

void NormalTag::Free(NormalTag*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

UVWTag* UVWTag::Alloc(Int32 count)
{
	return (UVWTag*)C4DOS_Tg->Alloc(Tuvw, count);
}

void UVWTag::Free(UVWTag*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

TextureTag* TextureTag::Alloc()
{
	return (TextureTag*)C4DOS_Tg->Alloc(Ttexture, 0);
}

void TextureTag::Free(TextureTag*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

StickTextureTag* StickTextureTag::Alloc(Int32 type)
{
	return (StickTextureTag*)C4DOS_Tg->Alloc(Tsticktexture, 0);
}

void StickTextureTag::Free(StickTextureTag*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

void VertexColorTag::Set(VertexColorHandle dataptr, Neighbor* nb, const CPolygon* vadr, Int32 pIndex, const maxon::ColorA32& color)
{
	if (!nb || !vadr) // per vertex mode
	{
		maxon::ColorA32* data = static_cast<maxon::ColorA32*>(dataptr);
		if (data)
		{
			data[pIndex].r = color.r;
			data[pIndex].g = color.g;
			data[pIndex].b = color.b;
			data[pIndex].a = color.a;
		}
		return;
	}

	Int32*	faces = nullptr;
	Int32		faceCount = 0;
	VertexColorStruct vcs;
	maxon::ColorA32 clamepedColor = color;
	nb->GetPointPolys(pIndex, &faces, &faceCount);
	for (Int32 i = 0; i < faceCount; ++i)
	{
		VertexColorTag::Get(dataptr, faces[i], vcs);

		clamepedColor.r = color.r;
		clamepedColor.g = color.g;
		clamepedColor.b = color.b;
		clamepedColor.a = color.a;

		vcs[vadr[faces[i]].Find(pIndex)] = clamepedColor;

		VertexColorTag::Set(dataptr, faces[i], vcs);
	}
}

maxon::ColorA32 VertexColorTag::Get(ConstVertexColorHandle dataptr, Neighbor* nb, const CPolygon* vadr, Int32 pIndex)
{
	maxon::ColorA32 res = maxon::ColorA32(0.0, 0.0, 0.0, 0.0);

	if (!nb || !vadr) // per vertex mode
	{
		const maxon::ColorA32* data = static_cast<const maxon::ColorA32*>(dataptr);
		if (data)
		{
			res = data[pIndex];
		}
		return res;
	}

	maxon::ColorA32 temp;

	Int32*	faces = nullptr;
	Int32		faceCount = 0;
	VertexColorStruct vcs;
	nb->GetPointPolys(pIndex, &faces, &faceCount);

	if (faceCount <= 0)
		return res;

	for (Int32 i = 0; i < faceCount; ++i)
	{
		VertexColorTag::Get(dataptr, faces[i], vcs);
		temp = vcs[vadr[faces[i]].Find(pIndex)];
		res += temp;
	}

	res = res * Inverse((Float32)faceCount);

	return res;
}

void VertexColorTag::SetColor(VertexColorHandle dataptr, Neighbor* nb, const CPolygon* vadr, Int32 pIndex, const maxon::Color32& color)
{
	if (!nb || !vadr) // per vertex mode
	{
		maxon::ColorA32* data = static_cast<maxon::ColorA32*>(dataptr);
		if (data)
		{
			data[pIndex].r = color.r;
			data[pIndex].g = color.g;
			data[pIndex].b = color.b;
		}
		return;
	}

	Int32*	faces = nullptr;
	Int32		faceCount = 0;
	Int32		index = NOTOK;
	VertexColorStruct vcs;
	nb->GetPointPolys(pIndex, &faces, &faceCount);
	for (Int32 i = 0; i < faceCount; ++i)
	{
		VertexColorTag::Get(dataptr, faces[i], vcs);
		index = vadr[faces[i]].Find(pIndex);
		vcs[index].r = color.r;
		vcs[index].g = color.g;
		vcs[index].b = color.b;
		VertexColorTag::Set(dataptr, faces[i], vcs);
	}
}

maxon::Color32 VertexColorTag::GetColor(ConstVertexColorHandle dataptr, Neighbor* nb, const CPolygon* vadr, Int32 pIndex)
{
	maxon::Color32 res;

	if (!nb || !vadr) // per vertex mode
	{
		const maxon::ColorA32* data = static_cast<const maxon::ColorA32*>(dataptr);
		if (data)
		{
			res.r = data[pIndex].r;
			res.g = data[pIndex].g;
			res.b = data[pIndex].b;
		}
		return res;
	}

	maxon::ColorA32 temp;

	Int32*	faces = nullptr;
	Int32		faceCount = 0;
	VertexColorStruct vcs;
	nb->GetPointPolys(pIndex, &faces, &faceCount);
	for (Int32 i = 0; i < faceCount; ++i)
	{
		VertexColorTag::Get(dataptr, faces[i], vcs);
		temp = vcs[vadr[faces[i]].Find(pIndex)];
		res += maxon::Color32(temp.r, temp.g, temp.b);
	}
	if (faceCount > 0)
		res /= Float32(faceCount);

	return res;
}

void VertexColorTag::SetAlpha(VertexColorHandle dataptr, Neighbor* nb, const CPolygon* vadr, Int32 pIndex, Float32 value)
{
	if (!nb || !vadr) // per vertex mode
	{
		maxon::ColorA32* data = static_cast<maxon::ColorA32*>(dataptr);
		if (data)
			data[pIndex].a = value;

		return;
	}

	Int32*	faces = nullptr;
	Int32		faceCount = 0;
	VertexColorStruct vcs;
	nb->GetPointPolys(pIndex, &faces, &faceCount);
	for (Int32 i = 0; i < faceCount; ++i)
	{
		VertexColorTag::Get(dataptr, faces[i], vcs);
		vcs[vadr[faces[i]].Find(pIndex)].a = value;
		VertexColorTag::Set(dataptr, faces[i], vcs);
	}
}

Float32 VertexColorTag::GetAlpha(ConstVertexColorHandle dataptr, Neighbor* nb, const CPolygon* vadr, Int32 pIndex)
{
	Float32 res = 0.0f;

	if (!nb || !vadr) // per vertex mode
	{
		const maxon::ColorA32* data = static_cast<const maxon::ColorA32*>(dataptr);
		if (data)
			res = data[pIndex].a;
		return res;
	}

	maxon::ColorA32 temp;

	Int32*	faces = nullptr;
	Int32		faceCount = 0;
	VertexColorStruct vcs;
	nb->GetPointPolys(pIndex, &faces, &faceCount);
	for (Int32 i = 0; i < faceCount; ++i)
	{
		VertexColorTag::Get(dataptr, faces[i], vcs);
		temp = vcs[vadr[faces[i]].Find(pIndex)];
		res += temp.a;
	}
	if (faceCount > 0)
		res /= Float32(faceCount);

	return res;
}

VertexColorTag* VertexColorTag::Alloc(Int32 count)
{
	return (VertexColorTag*)C4DOS_Tg->Alloc(Tvertexcolor, count);
}

void VertexColorTag::Free(VertexColorTag*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

GvNodeMaster* XPressoTag::GetNodeMaster()
{
	RetrievePrivateData rp;
	rp.flags = 0;
	rp.data	 = nullptr;

	if (!Message(MSG_RETRIEVEPRIVATEDATA, &rp))
		return nullptr;
	return (GvNodeMaster*)rp.data;
}

XPressoTag* XPressoTag::Alloc()
{
	return (XPressoTag*)C4DOS_Tg->Alloc(Texpresso, 0);
}

void XPressoTag::Free(XPressoTag*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}


HNWeightTag* HNWeightTag::Alloc()
{
	return (HNWeightTag*)C4DOS_Tg->Alloc(Tsds, 0);
}

void HNWeightTag::Free(HNWeightTag*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

Bool HNWeightTag::GetTagData(HNData* data) const
{
	if (!data)
		return false;

	RetrievePrivateData rp;
	rp.flags = 0;
	rp.data	 = data;

	if (!const_cast<HNWeightTag*>(this)->Message(MSG_RETRIEVEPRIVATEDATA, &rp))
		return false;

	return true;
}

// read/write overrides
const Vector* PointTag::GetDataAddressR() const { return (const Vector*)C4DOS_Tg->GetDataAddressR(this); }
Vector* PointTag::GetDataAddressW() { return (Vector*)C4DOS_Tg->GetDataAddressW(this); }

const Vector* StickTextureTag::GetDataAddressR() const { return (const Vector*)C4DOS_Tg->GetDataAddressR(this);	}
Vector* StickTextureTag::GetDataAddressW() { return (Vector*)C4DOS_Tg->GetDataAddressW(this);	}

const Float32* VertexMapTag::GetDataAddressR() const { return (const Float32*)C4DOS_Tg->GetDataAddressR(this); }
Float32* VertexMapTag::GetDataAddressW() { return (Float32*)C4DOS_Tg->GetDataAddressW(this); }

const Segment* SegmentTag::GetDataAddressR() const { return (const Segment*)C4DOS_Tg->GetDataAddressR(this); }
Segment* SegmentTag::GetDataAddressW() { return (Segment*)C4DOS_Tg->GetDataAddressW(this); }

const Tangent* TangentTag::GetDataAddressR() const { return (const Tangent*)C4DOS_Tg->GetDataAddressR(this); }
Tangent* TangentTag::GetDataAddressW() { return (Tangent*)C4DOS_Tg->GetDataAddressW(this); }

const CPolygon* PolygonTag::GetDataAddressR() const { return (const CPolygon*)C4DOS_Tg->GetDataAddressR(this); }
CPolygon* PolygonTag::GetDataAddressW() { return (CPolygon*)C4DOS_Tg->GetDataAddressW(this); }

ConstUVWHandle UVWTag::GetDataAddressR() const { return (ConstUVWHandle)C4DOS_Tg->GetDataAddressR(this); }
UVWHandle UVWTag::GetDataAddressW() { return (UVWHandle)C4DOS_Tg->GetDataAddressW(this); }
maxon::Range<Vector32> UVWTag::CalculateBoundingBox() const { return C4DOS_Tg->CalculateBoundingBox(this); }

ConstVertexColorHandle VertexColorTag::GetDataAddressR() const { return (ConstVertexColorHandle)C4DOS_Tg->GetDataAddressR(this); }
VertexColorHandle VertexColorTag::GetDataAddressW() { return (VertexColorHandle)C4DOS_Tg->GetDataAddressW(this); }

ConstNormalHandle NormalTag::GetDataAddressR() const { return (ConstNormalHandle)C4DOS_Tg->GetDataAddressR(this);	}
NormalHandle NormalTag::GetDataAddressW() { return (NormalHandle)C4DOS_Tg->GetDataAddressW(this);	}

const void* VariableTag::GetLowlevelDataAddressR() const { return C4DOS_Tg->GetDataAddressR(this); }
void* VariableTag::GetLowlevelDataAddressW() { return C4DOS_Tg->GetDataAddressW(this); }
void VariableTag::SetValidationDelegate(ValidationDelegate&& validationDelegate){ C4DOS_Tg->SetValidationDelegate(this, std::move(validationDelegate)); }
Bool VertexColorTag::IsPerPointColor() const { return C4DOS_Tg->IsPerPointColor(this); }

Bool VertexColorTag::SetPerPointMode(Bool perPointColor) {  return C4DOS_Tg->SetPerPointMode(this, perPointColor); }

const Float32* SoftSelectionTag::GetDataAddressR() const { return (const Float32*)C4DOS_Tg->GetDataAddressR(this); }
Float32* SoftSelectionTag::GetDataAddressW() { return (Float32*)C4DOS_Tg->GetDataAddressW(this); }

DISPLAYMODE DisplayTag::GetDisplayMode(Bool original) const { return C4DOS_Tg->GetDisplayMode(this, original); }
Int32 DisplayTag::GetVectorDisplayMode() const { return C4DOS_Tg->GetVectorDisplayMode(this); }

const BaseTag* BacktrackToOriginal(const BaseTag* const startTag)
{
	Int32 tagType = startTag->GetType();
	const String tagName = startTag->GetName();
	const BaseTag* nextOrigin = nullptr;

	auto tryParentStep = [&nextOrigin, &tagName, &tagType](const BaseTag* origin)
		{
			Bool foundOriginForward = false;
			// try to go through the object origin.
			// This might be a cloner clone and it can backtrack to the original object and have a selected influence map on that object
			const BaseObject* obj = origin->GetObject();
			const BaseObject* cacheParent = obj->GetCacheParent();
			if (cacheParent && cacheParent->GetType() == Oalembicgenerator)
			{
				// this might need to reference an alembic tag
				maxon::Block<const BaseTag* const> tags = cacheParent->GetTagsOfType(Talembic);

				GetRealTagData realTag;
				for (const BaseTag* const originTag : tags)
				{
					if (MAXON_REMOVE_CONST(originTag)->Message(MSG_GETREALTAGDATA, &realTag) && realTag.res && realTag.res == origin)
					{
						nextOrigin = originTag;
						tagType = Talembic; // we are now switching and searching for alembic tag proxies
						return;
					}
				}
			}

			while (obj)
			{
				const BaseObject* nextOriginObj = obj->GetOrigin(false);
				if (!nextOriginObj || obj == nextOriginObj)
					break;

				if (nextOriginObj)
				{
					maxon::Block<const BaseTag* const> tags = nextOriginObj->GetTagsOfType(tagType);
					for (const BaseTag* const originTag : tags)
					{
						// here we can only match by name, which is a problem
						if (originTag->GetName() == tagName)
						{
							if (!foundOriginForward) // name matches and the first tag found to match
							{
								nextOrigin = originTag;
								nextOriginObj = nullptr;
								foundOriginForward = true;
							}
							else // another one with matching name found. In this case it cannot be decided any more which one is the correct one if matched by name. So instead show none.
							{
								nextOrigin = nullptr; // go back to having found nothing
								break;
							}
						}
					}
				}
				obj = nextOriginObj;
			}
		};

	const BaseTag* origin = startTag;
	while (origin)
	{
		nextOrigin = origin->GetOrigin();
		if (!nextOrigin || origin == nextOrigin)
		{
			if (!nextOrigin)
			{
				tryParentStep(origin);
				if (nextOrigin)
				{
					// found a new origin, so continue.
					origin = nextOrigin;
					continue;
				}
			}

			// could not find a step forward. Stop here.
			break;
		}
		origin = nextOrigin;
	}

	return origin != startTag ? origin : startTag;
}

const CPolygon* UVWTag::GetUVWPolygonR() const
{
	return C4DOS_Tg->GetUVWPolygonR(this);
}

CPolygon* UVWTag::GetUVWPolygonW()
{
	return C4DOS_Tg->GetUVWPolygonW(this);
}

Int32 UVWTag::GetUVWPolygonCount() const
{
	return C4DOS_Tg->GetUVWPolygonCount(this);
}

const Vector* UVWTag::GetUVWPointR() const
{
	return C4DOS_Tg->GetUVWPointR(this);
}

Vector* UVWTag::GetUVWPointW()
{
	return C4DOS_Tg->GetUVWPointW(this);
}

Int32 UVWTag::GetUVWPointCount() const
{
	return C4DOS_Tg->GetUVWPointCount(this);
}

Bool UVWTag::ResizeUVWTopology(Int32 pointCount, Int32 polygonCount)
{
	return C4DOS_Tg->ResizeUVWTopology(this, pointCount, polygonCount);
}

maxon::Result<void> UVWTag::IsUVWTopologyValid() const
{
	return C4DOS_Tg->IsUVWTopologyValid(this);
}

maxon::Result<void> UVWTag::OptimizeUVWTopology()
{
	return C4DOS_Tg->OptimizeUVWTopology(this);
}

const PolygonObject* UVWTag::GetUVWObjectR() const
{
	return C4DOS_Tg->GetUVWObjectR(this);
}

PolygonObject* UVWTag::GetUVWObjectW()
{
	return C4DOS_Tg->GetUVWObjectW(this);
}

BaseSelect* UVWTag::GetWritableUVWPointS()
{
	return C4DOS_Tg->GetWritableUVWPointS(this);
}

const BaseSelect* UVWTag::GetUVWPointS() const
{
	return C4DOS_Tg->GetUVWPointS(this);
}

EdgeBaseSelect* UVWTag::GetWritableUVWEdgeS()
{
	return C4DOS_Tg->GetWritableUVWEdgeS(this);
}

const EdgeBaseSelect* UVWTag::GetUVWEdgeS() const
{
	return C4DOS_Tg->GetUVWEdgeS(this);
}

BaseSelect* UVWTag::GetWritableUVWPolygonS()
{
	return C4DOS_Tg->GetWritableUVWPolygonS(this);
}

const BaseSelect* UVWTag::GetUVWPolygonS() const
{
	return C4DOS_Tg->GetUVWPolygonS(this);
}

// helper to receive the real tag from virtual tags (e.g. Alembic)
BaseTag* GetRealTag(BaseTag* tag)
{
	if (tag == nullptr)
		return nullptr;

	GetRealTagData realTagData;
	if (tag->Message(MSG_GETREALTAGDATA, &realTagData) && realTagData.res)
		return realTagData.res;
	else
		return tag;
}

} // namespace cinema
