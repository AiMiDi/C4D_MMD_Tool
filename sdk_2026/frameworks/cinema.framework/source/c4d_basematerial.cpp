#include "c4d_basematerial.h"
#include "c4d_basedocument.h"

#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

namespace cinema
{

void BaseMaterial::Update(Bool preview, Bool rttm)
{
	C4DOS_Mt->Update(this, preview, rttm);
}

Bool BaseMaterial::Compare(BaseMaterial* snd)
{
	return C4DOS_Mt->Compare(this, snd);
}

BaseBitmap* BaseMaterial::GetPreview(Int32 flags)
{
	return C4DOS_Mt->GetPreview(this, flags);
}

BaseShader* BaseMaterial::MakeShader(Int32 type, Int32 id, BaseShader* pred)
{
	return C4DOS_Mt->MakeShader(this, type, id, pred);
}

Vector BaseMaterial::GetAverageColor(Int32 channel)
{
	return C4DOS_Mt->GetAverageColor(this, channel);
}

BaseMaterial* BaseMaterial::Alloc(Int32 type)
{
	return C4DOS_Mt->Alloc(type);
}

void BaseMaterial::Free(BaseMaterial*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

Material* Material::Alloc()
{
	return (Material*)C4DOS_Mt->Alloc(Mmaterial);
}

void Material::Free(Material*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

void MarkMaterials::Mark(BaseMaterial* mat, void* msgData)
{
	if (mat)
	{
		if (!msgData)
		{
			mat->SetBit(BIT_MATMARK);
		}
		else if (!IsTranslation(msgData))
		{
			MarkMaterials* const mm = static_cast<MarkMaterials*>(msgData);
			mm->materials.Insert(mat) iferr_ignore("ignore this unlikely error, some materials will be missing then");
		}
	}
}

void MarkMaterials::HandleMaterialInContainer(GeListNode* node, Int32 id, BaseContainer* bc, void* msgData, BaseDocument* doc)
{
	BaseMaterial* const mat = static_cast<BaseMaterial*>(bc->GetLink(id, doc, Mbase));
	if (!mat)
		return;

	if (IsTranslation(msgData))
	{
		const MarkMaterials* const mm = static_cast<const MarkMaterials*>(msgData);
		if (mm->omat == mat)
		{
			doc->AddUndo(UNDOTYPE::CHANGE_SMALL, node);
			bc->SetLink(id, mm->nmat);

			node->Message(MSG_CHANGE);
		}
	}
	else
	{
		Mark(mat, msgData);
	}
}

} // namespace cinema
