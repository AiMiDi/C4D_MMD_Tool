#include "operatingsystem.h"
#include "c4d_objectplugin.h"

#ifdef __API_INTERN__
	#include "c4d_resource.h"
	#include "basedraw.h"
	#include "res_colortab_priv.h"
#else
	#include "c4d_tools.h"
	#include "c4d_basebitmap.h"
	#include "c4d_file.h"
	#include "c4d_resource.h"
	#include "c4d_baseobject.h"
	#include "c4d_basedraw.h"
	#include "description/dbasedraw.h"
#endif

Vector HandleInfo::CalculateNewPosition(BaseDraw* bd, const Matrix& mg, const Vector& mouse_pos) const
{
	if (MAXON_UNLIKELY(!bd))
	{
		return position;
	}
	
	Vector result = mg * position;
	switch (type)
	{
		case HANDLECONSTRAINTTYPE::LINEAR:
		{
			result = bd->ProjectPointOnLine(mg * position, mg.sqmat * direction, mouse_pos.x, mouse_pos.y);
			break;
		}
		case HANDLECONSTRAINTTYPE::PLANAR:
		{
			Int32 err;
			result = bd->ProjectPointOnPlane(mg * position, mg.sqmat * direction, mouse_pos.x, mouse_pos.y, &err);
			if (err)
			{
				Vector dir = Cross(!(bd->WS(mg * (position + direction)) - bd->WS(mg * position)), Vector(0.0_f, 0.0_f, 1.0_f));
				dir = !(bd->SW(bd->WS(mg * position) + dir) - (mg * position));
				result = bd->ProjectPointOnLine(mg * position, dir, mouse_pos.x, mouse_pos.y);
			}
			break;
		}
		case HANDLECONSTRAINTTYPE::FREE:
		{
			if (mouse_pos.z != 0.0_f)
				result = bd->SW(mouse_pos);
			else
				result = bd->SW(Vector(mouse_pos.x, mouse_pos.y, bd->WC(result).z));
			break;
		}
		case HANDLECONSTRAINTTYPE::RADIAL:
		{
			const Vector mgCenter = mg * center;
			result = bd->ProjectPointOnPlane(mgCenter, mg.sqmat * direction, mouse_pos.x, mouse_pos.y);
			result = mgCenter + (radius * !(result - mgCenter));			break;
		}
		case HANDLECONSTRAINTTYPE::SPHERICAL:
		{
			Float r = 0.0_f;
			Float cp = 0.0_f;

			r = radius * bd->WP_W(mg * center, true);
			if (r == 0.0_f)
				r = 0.1_f;

			result = (mouse_pos - bd->WS(mg * center));
			result.z = 0.0_f;
			cp = FMin(result.GetLength(), r);
			result = cp * !result;
			result.z = -Cos(ASin(cp / r)) * r;
			result = bd->SW(result + bd->WS(mg * center));
			break;
		}
		default:
		{
			break;
		}
	}
	return ~mg * result;
}

void ObjectData::GetDimension(BaseObject* op, Vector* mp, Vector* rad)
{
	// override GetDimension if you do not want C4D's default handling of bounding boxes and set *mp/*rad to 0.0
}

DRAWRESULT ObjectData::Draw(BaseObject* op, DRAWPASS drawpass, BaseDraw* bd, BaseDrawHelp* bh)
{
	if (drawpass != DRAWPASS::HANDLES)
		return DRAWRESULT::SKIP;

	Int32	 i, pass;
	Vector p;
	Int32	 cnt = GetHandleCount(op);
	if (!cnt)
		return DRAWRESULT::SKIP;

#ifdef __API_INTERN__
	Int32					hitid = C4DOS.Bo->GetHighlightHandle(op, bd);
	const Matrix& mg = bh->m;
#else
	Int32					hitid = op->GetHighlightHandle(bd);
	const Matrix& mg = bh->GetMg();
#endif
	Vector col1 = GetViewColor(VIEWCOLOR_SELECTION_PREVIEW);
	Vector col2 = GetViewColor(VIEWCOLOR_HANDLES);

	bd->SetMatrix_Matrix(op, mg);

	for (pass = 0; pass < 2; pass++)
	{
		if (pass == 0)
			bd->SetPen(col2);
		else
			bd->SetPen(col1);

		for (i = 0; i < cnt; i++)
		{
			if ((i == hitid) != pass)
				continue;
			HandleInfo info;
			GetHandle(op, i, info);
			if (info.type == HANDLECONSTRAINTTYPE::INVALID)
				continue;
			bd->DrawHandle(info.position, DRAWHANDLE::BIG, 0);

			// #ifndef __API_INTERN__
			// bd->Line3D(Vector(0.0,0.0,0.0)*mg,p);
			// #endif
		}
	}

	return DRAWRESULT::OK;
}

DRAWRESULT ObjectData::DrawShadow(BaseObject* op, BaseDraw* bd, BaseDrawHelp* bh)
{
	return DRAWRESULT::SKIP;
}

void ObjectData::GetHandle(BaseObject* op, Int32 i, HandleInfo& info)
{
}

void ObjectData::SetHandle(BaseObject* op, Int32 i, Vector p, const HandleInfo& info)
{
}

Int32 ObjectData::GetHandleCount(BaseObject* op)
{
	return 0;
}

Int32 ObjectData::DetectHandle(BaseObject* op, BaseDraw* bd, Int32 x, Int32 y, QUALIFIER qualifier)
{
	if (qualifier & QUALIFIER::CTRL)
		return NOTOK;

	Matrix mg = op->GetMg();
	Int32	 i, ret = NOTOK;

	for (i = 0; i < GetHandleCount(op); i++)
	{
		HandleInfo info;
		GetHandle(op, i, info);
		if (info.type == HANDLECONSTRAINTTYPE::INVALID)
			continue;

		if (bd->PointInRange(mg * info.position, x, y))
		{
			ret = i;
			if (!(qualifier & QUALIFIER::SHIFT))
				break;
		}
	}
	return ret;
}

Bool ObjectData::MoveHandle(BaseObject* op, BaseObject* undo, const Vector& mouse_pos, Int32 hit_id, QUALIFIER qualifier, BaseDraw* bd)
{
	Matrix		 mg = op->GetUpMg() * undo->GetMl();
	HandleInfo info;

	undo->GetNodeData<ObjectData>()->GetHandle(undo, hit_id, info);
	SetHandle(op, hit_id, info.CalculateNewPosition(bd, mg, mouse_pos), info);

	return true;
}

SplineObject* ObjectData::GetContour(BaseObject* op, BaseDocument* doc, Float lod, BaseThread* bt)
{
	return nullptr;
}

BaseObject* ObjectData::GetVirtualObjects(BaseObject* op, HierarchyHelp* hh)
{
	return nullptr;
}

Bool ObjectData::ModifyObject(BaseObject* op, BaseDocument* doc, BaseObject* mod, const Matrix& op_mg, const Matrix& mod_mg, Float lod, Int32 flags, BaseThread* thread)
{
	return true;
}

void ObjectData::CheckDirty(BaseObject* op, BaseDocument* doc)
{
}

void ObjectData::ModifyParticles(BaseObject* op, Particle* pp, BaseParticle* ss, Int32 pcnt, Float diff)
{
}

void ObjectData::GetModelingAxis(BaseObject* op, BaseDocument* doc, Matrix& axis)
{
}

Bool ObjectData::AddToExecution(BaseObject* op, PriorityList* list)
{
	return false;
}

EXECUTIONRESULT ObjectData::Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags)
{
	return EXECUTIONRESULT::OK;
}

void FillObjectPlugin(OBJECTPLUGIN* np, DataAllocator* npalloc, Int32 info, Int32 disklevel, BaseBitmap* icon)
{
	FillNodePlugin(np, info, npalloc, icon, disklevel);

	np->command_icon = icon;
	np->GetDimension = &ObjectData::GetDimension;
	np->Draw = &ObjectData::Draw;
	np->DrawShadow = &ObjectData::DrawShadow;
	np->DetectHandle = &ObjectData::DetectHandle;
	np->MoveHandle = &ObjectData::MoveHandle;
	np->Execute	= &ObjectData::Execute;
	np->AddToExecution	= &ObjectData::AddToExecution;
	np->GetModelingAxis	= &ObjectData::GetModelingAxis;
}

Bool RegisterObjectPlugin(Int32 id, const maxon::String& str, Int32 objectinfo, DataAllocator* npalloc, const maxon::String& description, BaseBitmap* icon, Int32 disklevel)
{
	if (description.IsPopulated() && !RegisterDescription(id, description))
		return false;

	OBJECTPLUGIN np;
	ClearMem(&np, sizeof(np));
	FillObjectPlugin(&np, npalloc, objectinfo, disklevel, icon);

	np.CheckDirty	= &ObjectData::CheckDirty;

	if (objectinfo & OBJECT_MODIFIER)
		np.ModifyObject	= &ObjectData::ModifyObject;

	if (objectinfo & OBJECT_PARTICLEMODIFIER)
		np.ModifyParticles = &ObjectData::ModifyParticles;

	if (objectinfo & OBJECT_ISSPLINE)
		np.GetContour = &ObjectData::GetContour;

	if (objectinfo & OBJECT_GENERATOR)
		np.GetVirtualObjects = &ObjectData::GetVirtualObjects;

	return GeRegisterPlugin(PLUGINTYPE::OBJECT, id, str, &np, sizeof(np));
}
