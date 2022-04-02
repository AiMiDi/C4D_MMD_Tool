#pragma once
#include "Utility.h"
#include "description/TMMDBone.h"

namespace tool {
	struct bone_morph_data
	{
		DescID	grp_id;
		DescID	strength_id;
		DescID	translation_id;
		DescID	rotation_id;
		DescID	button_grp_id;
		DescID	button_delete_id;
		DescID	button_rename_id;
		String	name;
		bone_morph_data(
			const DescID& grp_id_,
			const DescID& strength_id_,
			const DescID& translation_id_,
			const DescID& rotation_id_,
			const DescID& button_grp_id_,
			const DescID& button_delete_id_,
			const DescID& button_rename_id_,
			const String& name_)
		{
			grp_id = grp_id_;
			strength_id = strength_id_;
			translation_id = translation_id_;
			rotation_id = rotation_id_;
			button_grp_id = button_grp_id_;
			button_delete_id = button_delete_id_;
			button_rename_id = button_rename_id_;
			name = name_;
		}
		bone_morph_data() : bone_morph_data(DescID(), DescID(), DescID(), DescID(), DescID(), DescID(), DescID(), String()) {}

		Bool Write(HyperFile* hf)
		{
			if (!grp_id.Write(hf))
				return false;
			if (!strength_id.Write(hf))
				return false;
			if (!translation_id.Write(hf))
				return false;
			if (!rotation_id.Write(hf))
				return false;
			if (!button_grp_id.Write(hf))
				return false;
			if (!button_delete_id.Write(hf))
				return false;
			if (!button_rename_id.Write(hf))
				return false;
			if (!hf->WriteString(name))
				return false;
			return true;
		}

		Bool Read(HyperFile* hf)
		{
			if (!grp_id.Read(hf))
				return false;
			if (!strength_id.Read(hf))
				return false;
			if (!translation_id.Read(hf))
				return false;
			if (!rotation_id.Read(hf))
				return false;
			if (!button_grp_id.Read(hf))
				return false;
			if (!button_delete_id.Read(hf))
				return false;
			if (!button_rename_id.Read(hf))
				return false;
			if (!hf->ReadString(&name))
				return false;
			return true;
		}
	};
	class TMMDBone : public TagData
	{
		/* ʹ��Map���油���������� */
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_X_map;
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_Y_map;
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_Z_map;
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_R_map;
		maxon::HashMap<Int32, mmd::VMDInterpolator>	interpolator_A_map;
		maxon::HashMap<DescID, Int32> button_id_map;
		/* ������������ */
		Int32 bone_morph_name_index = 0;
		/* ����ǰһ֡����ȷ������״̬ */
		Int32 prev_frame = -1;
		/* ������һ���������ͣ���ȷ������״̬ */
		Int32 prev_interpolator_type = -1;
		/* ��Ӧ�Ĺ��������� */
		BaseObject* obj = nullptr;
		/* �����׹������� */
		BaseObject* inherit_bone_parent = nullptr;
		/* ���������� */
		BaseObject* m_BoneRoot_ptr = nullptr;
		/* �Ƿ���������� */
		Bool	Is_physical = false;
		/* ���ڴ���������� */
		Vector	prev_position = Vector();
		/* ���ڴ���������� */
		Vector	prev_rotation = Vector();
		/* ��������������� */
		maxon::PointerArray<bone_morph_data> bone_morph_data_arr;
		TMMDBone() {}
		~TMMDBone() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(TMMDBone);
		INSTANCEOF(TMMDBone, TagData)
	public:
		Int32 AddBondMorph(String morph_name);
		Bool RefreshColor(GeListNode* node = nullptr, BaseObject* op = nullptr);
		/* ��������SplineData�Ļص����� */
		static Bool SplineDataCallBack(Int32 cid, const void* data);
		/* ��ȡ����ֵ */
		Bool GetInterpolator(const Int32& type, const Int32& frame_on, mmd::VMDInterpolator& interpolator) const;
		/* ��������ֵ */
		Bool SetInterpolator(const Int32& type, const Int32& frame_on, mmd::VMDInterpolator&& interpolator, Bool cover = true);
		Bool AutoRegisterKeyFrame(Int32 use_rotation = 0, GeListNode* node = nullptr);
		/* ע��ؼ�֡ */
		Bool RegisterKeyFrame(Int32 frame_on, GeListNode* node = nullptr);
		/* ����ȫ���������� */
		Bool UpdateAllInterpolator(GeListNode* node = nullptr);
		/* ��ʼ������ */
		Bool InitInterpolator(GeListNode* node = nullptr);
		/* ɾ������ */
		Bool DeleteKeyFrame(Int32 frame_on, GeListNode* node = nullptr);
		/* ɾ��ȫ������ */
		Bool DeleteAllKeyFrame(GeListNode* node = nullptr);
		/* ����Messageʱ���ã����ڴ����¼� */
		Bool Message(GeListNode* node, Int32 type, void* data) override;
		Bool Init(GeListNode* node) override;
		/* ���ò���ʱ���ã����ڵ���SplineData�Ļص����� */
		Bool SetDParameter(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags) override;
		Bool GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) override;
		EXECUTIONRESULT Execute(BaseTag* tag, BaseDocument* doc, BaseObject* op, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags) override;
		Bool Read(GeListNode* node, HyperFile* hf, Int32 level) override;
		Bool Write(GeListNode* node, HyperFile* hf) override;
		static NodeData* Alloc()
		{
			return(NewObjClear(TMMDBone));
		}
		virtual void Free(GeListNode* node);
		void SetObj(BaseObject* obj_)
		{
			this->obj = obj_;
		}
		void SetRootObject(BaseObject* obj_)
		{
			this->m_BoneRoot_ptr = obj_;
		}
		Bool SetBondMorphTranslation(Int32 id, Vector translation)
		{
			if (id < 0 || id > bone_morph_data_arr.GetCount() - 1)
			{
				return(false);
			}
			return(Get()->SetParameter(bone_morph_data_arr[id].translation_id, translation, DESCFLAGS_SET::NONE));
		}
		Bool SetBondMorphRotation(Int32 id, Vector rotation)
		{
			if (id < 0 || id > bone_morph_data_arr.GetCount() - 1)
			{
				return(false);
			}
			return(Get()->SetParameter(bone_morph_data_arr[id].rotation_id, rotation, DESCFLAGS_SET::NONE));
		}
		Int GetMorphCount()
		{
			return(bone_morph_data_arr.GetCount());
		}
		bone_morph_data* GetMorph(Int32 index)
		{
			if (index >= bone_morph_data_arr.GetCount()) 
			{
				return nullptr;
			}
			else {
				return &bone_morph_data_arr[index];
			}
		}
		Bool IsPhysical()
		{
			return(this->Is_physical);
		}
		void SetPhysical(Bool Is_physical_)
		{
			this->Is_physical = Is_physical_;
		}
	};
}