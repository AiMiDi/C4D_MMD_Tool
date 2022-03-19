#pragma once
#include "Utility.h"
#include "TMMDBone.h"
#include "description/OMMDModel.h"

namespace mmd {
	enum class OMMDModel_Root_type
	{
		MeshRoot = 0,
		BoneRoot,
		RigidRoot,
		JointRoot
	};

	struct OMMDModel_MSG
	{
		OMMDModel_Root_type	type = OMMDModel_Root_type::MeshRoot;
		BaseObject* Root = nullptr;
		OMMDModel_MSG(OMMDModel_Root_type type_ = OMMDModel_Root_type::MeshRoot, BaseObject* Root_ = nullptr) 
			:type(type_), Root(Root_) {}
	};
	class OMMDModel : public ObjectData
	{
		BaseObject* MeshRoot = nullptr;
		BaseObject* BoneRoot = nullptr;
		BaseObject* RigidRoot = nullptr;
		BaseObject* JointRoot = nullptr;
		OMMDModel() {}
		~OMMDModel() {}
		MAXON_DISALLOW_COPY_AND_ASSIGN(OMMDModel);
		INSTANCEOF(OMMDModel, ObjectData)
	public:
		virtual Bool Init(GeListNode* node);
		virtual Bool Read(GeListNode* node, HyperFile* hf, Int32 level);
		virtual Bool Write(GeListNode* node, HyperFile* hf);
		virtual Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn);
		virtual Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags);
		/* 实时调用 */
		virtual EXECUTIONRESULT Execute(BaseObject* op, BaseDocument* doc, BaseThread* bt, Int32 priority, EXECUTIONFLAGS flags);
		/* 将实时调用添加入优先级列表 */
		virtual Bool AddToExecution(BaseObject* op, PriorityList* list);
		virtual Bool Message(GeListNode* node, Int32 type, void* data);
		Bool CreateRoot();
		BaseObject* GetRootObject(OMMDModel_Root_type type_)
		{
			switch (type_)
			{
			case mmd::OMMDModel_Root_type::MeshRoot:
				return this->MeshRoot;
			case mmd::OMMDModel_Root_type::BoneRoot:
				return this->BoneRoot;
			case mmd::OMMDModel_Root_type::RigidRoot:
				return this->RigidRoot;
			case mmd::OMMDModel_Root_type::JointRoot:
				return this->JointRoot;
			default:
				return nullptr;
			}
		}
		static NodeData* Alloc()
		{
			return(NewObjClear(OMMDModel));
		}
	};
}
