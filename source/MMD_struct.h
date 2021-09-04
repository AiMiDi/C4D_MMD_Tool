﻿#ifndef __MMD_STRUCT_H__
#define __MMD_STRUCT_H__

#include "c4d.h"

#if API_VERSION < 23000
namespace maxon {
	using HashInt = UInt;
}
#endif

namespace mmd {
	typedef maxon::Vec2<Float32> Vector2d32;

	/*MMD动画*/

	struct VMDInterpolator /* MMD风格的补间曲线 */
	{
		UChar ax, ay, bx, by;


		VMDInterpolator(UChar ax_ = 20U, UChar ay_ = 20U, UChar bx_ = 107U, UChar by_ = 107U) : ax(ax_), ay(ay_), bx(bx_), by(by_){}

		maxon::HashInt GetHashCode() const
		{
			return  MAXON_HASHCODE(this->ax, this->ay, this->bx, this->by);
		}

		Bool ReadBoneInterpolator(BaseFile* const file) {
			if (!file->ReadUChar(&this->ax))
				return false;
			file->Seek(3);
			if (!file->ReadUChar(&this->ay))
				return false;
			file->Seek(3);
			if (!file->ReadUChar(&this->bx))
				return false;
			file->Seek(3);
			if (!file->ReadUChar(&this->by))
				return false;
			file->Seek(3);
			return true;
		}


		Bool ReadCameraInterpolator(BaseFile* const file)
		{
			UInt32 tmp = 0;
			if (!file->ReadUInt32(&tmp))
				return false;
			this->ax = (((tmp & 0xFF) ^ 0x80) - 0x80);
			this->bx = ((((tmp & 0xFF00) >> 8) ^ 0x80) - 0x80);
			this->ay = ((((tmp & 0xFF0000) >> 16) ^ 0x80) - 0x80);
			this->by = ((((tmp & 0xFF000000) >> 24) ^ 0x80) - 0x80);
			return true;
		}


		Bool WriteBoneInterpolator(BaseFile* const file) {
			// GePrint(String::UIntToString((UInt32)this->ax) + " " + String::UIntToString((UInt32)this->ay) + " " + String::UIntToString((UInt32)this->bx) + " " + String::UIntToString((UInt32)this->by));
			if (!file->WriteUChar(this->ax))
				return false;
			if (!file->WriteUChar(this->ax))
				return false;
			if (!file->WriteUChar(this->ax))
				return false;
			if (!file->WriteUChar(this->ax))
				return false;			
			if (!file->WriteUChar(this->ay))
				return false;
			if (!file->WriteUChar(this->ay))
				return false;
			if (!file->WriteUChar(this->ay))
				return false;
			if (!file->WriteUChar(this->ay))
				return false;
			if (!file->WriteUChar(this->bx))
				return false;
			if (!file->WriteUChar(this->bx))
				return false;
			if (!file->WriteUChar(this->bx))
				return false;
			if (!file->WriteUChar(this->bx))
				return false;
			if (!file->WriteUChar(this->by))
				return false;
			if (!file->WriteUChar(this->by))
				return false;
			if (!file->WriteUChar(this->by))
				return false;
			if (!file->WriteUChar(this->by))
				return false;
			return true;
		}


		Bool WriteCameraInterpolator(BaseFile* const file) {
			if (!file->WriteUChar(this->ax))
				return false;
			if (!file->WriteUChar(this->bx))
				return false;
			if (!file->WriteUChar(this->ay))
				return false;
			if (!file->WriteUChar(this->by))
				return false;
			return true;
		}
		
	};

	struct VMD_Motion                                                       /* MMD风格的动作 */
	{
		String		bone_name = String();                                      /* 动作对应骨骼名称 */
		UInt32		frame_no = 0;                                   /* 动作所在帧位置 */
		Vector32	position = Vector32();                                          /* 动作对应骨骼位置 */
		Vector4d32	rotation = Vector4d32();                                          /* 动作对应骨骼旋转(四元) */
																					  
		/* 动作补间曲线 */
		VMDInterpolator	interpolator_x = VMDInterpolator();
		VMDInterpolator	interpolator_y = VMDInterpolator();
		VMDInterpolator	interpolator_z = VMDInterpolator();
		VMDInterpolator	interpolator_r = VMDInterpolator();
	};

	struct VMD_Morph                                                        /* MMD风格的表情动画 */
	{
		String	morph_name = String();                                              /* 动作对应表情名称 */
		UInt32	frame_no = 0;                                    /* 动作对应表情所在帧位置 */
		Float32 weight = 0.f;                                   /* 表情变形程度 */
	};

	struct VMD_Camera                                                       /* MMD风格的摄像机动画 */
	{
		UInt32		frame_no = 0;                            /* 摄像机动作所在帧位置 */
		Float32		distance = 0.f;                           /* 摄像机视点距离 */
		Vector32	position = Vector32();                                       /* 摄像机视点位置 */
		Vector32	rotation = Vector32();                                          /* 摄像机视点旋转(x和y翻转的欧拉角) */
		/* 动作补间曲线 */
		VMDInterpolator	interpolator_x = VMDInterpolator();
		VMDInterpolator	interpolator_y = VMDInterpolator();
		VMDInterpolator	interpolator_z = VMDInterpolator();
		VMDInterpolator	interpolator_r = VMDInterpolator();
		VMDInterpolator	interpolator_d = VMDInterpolator();
		VMDInterpolator	interpolator_v = VMDInterpolator();
		UInt32		viewing_angle = 0;                            /* 视野角 */
		UChar		perspective = 0;                            /* 0:on, 1:off */
	};

	struct VMD_Light                                                        /* MMD风格的灯光动画 */
	{
		UInt32		frame_no = 0;
		Vector32	rgb = Vector32();
		Vector32	position = Vector32();
	};

	struct VMD_Shadow
	{
		UInt32	frame_no = 0;
		UChar	shadowType = 0; /* 0:Off 1:mode1 2:mode2 */
		Float32 distance = 0.f;
	};

	struct VMD_IkInfo
	{
		String	name;
		Bool	enable;
		VMD_IkInfo(String& name_ = String(), Bool enable_ = true) : name(name_), enable(enable_){}
	};

	struct VMD_Model
	{
		UInt32				frame_no;
		Bool				show;
		maxon::PointerArray<VMD_IkInfo> ik_Infos;

		VMD_Model(UInt32 frame_no_ = 0, Bool show_ = true):frame_no(frame_no_), show(show_){}


		VMD_Model(const mmd::VMD_Model& src)
		{
			if (&src == this)
			{
				return;
			}
			this->frame_no = src.frame_no;
			this->show = src.show;
			this->ik_Infos.CopyFrom(src.ik_Infos) iferr_ignore("err"_s);
		}


		mmd::VMD_Model& operator =(const mmd::VMD_Model& src)
		{
			if (&src == this)
			{
				return(*this);
			}
			this->frame_no = src.frame_no;
			this->show = src.show;
			this->ik_Infos.CopyFrom(src.ik_Infos) iferr_ignore("err"_s);
			return(*this);
		}
	};


	struct morph_id_tag
	{
		DescID	id;
		BaseTag* tag = nullptr;
		String name;

		Bool operator ==(const morph_id_tag& other) const {
			return (this->id == other.id && this->tag == other.tag);
		}

		maxon::HashInt GetHashCode() const
		{
			return  MAXON_HASHCODE(this->id.GetHashCode(), this->tag);
		}
	};

	struct bone_obj_tag
	{
		BaseObject* obj = nullptr;
		BaseTag* tag = nullptr;

		Bool operator ==(const bone_obj_tag& other) const {
			return (this->obj == other.obj && this->tag == other.tag);
		}

		maxon::HashInt GetHashCode() const
		{
			return  MAXON_HASHCODE(this->obj, this->tag);
		}
	};

	/*MMD模型*/

	struct PMX_Model_information 
	{
		Float32 version = 2.0f;   /* 版本号 */
		Char	text_encoding = 0;    /* 字符串编码,0为UTF16LE编码，1为UTF8编码 */
		Char	additional_Vector4d32_count = 0;    /* 额外的Vector4d32数量 */
		Char	vertex_index_size = 0;    /* 顶点索引大小 */
		Char	texture_index_size = 0;    /* 纹理索引大小 */
		Char	material_index_size = 0;    /* 材质索引大小 */
		Char	bone_index_size = 0;    /* 骨骼索引大小 */
		Char	morph_index_size = 0;    /* 表情索引大小 */
		Char	rigidbody_index_size = 0;    /* 刚体索引大小 */
		String	model_name_local;                       /* 本地模型名 */
		String	model_name_universal;                   /* 通用模型名 */
		String	comments_local;                         /* 本地语言模型描述 */
		String	comments_universal;                     /* 通用语言模型描述 */
		Bool	have_UV_morph = false;        /* 是否有UV表情 */
		Bool	have_vertex_morph = false;        /* 是否有顶点表情 */
	};

	struct BDEF1                                            /* 权重==1 */
	{
		Int32 bone1 = 0;
	};
	struct BDEF2                                            /* 骨骼2权重 = 1-骨骼1权重 */
	{
		Int32	bone1 = 0, bone2 = 0;
		Float32 weight1 = 0.f;
	};
	struct BDEF4                                            /* 4个权重和不保证=1 */
	{
		Int32	bone1 = 0, bone2 = 0, bone3 = 0, bone4 = 0;
		Float32 weight1 = 0.f, weight2 = 0.f, weight3 = 0.f, weight4 = 0.f;
	};
	struct SDEF                                             /* 骨骼2权重 = 1-骨骼1权重 */
	{
		Int32		bone1 = 0, bone2 = 0;
		Float32		weight1 = 0.f;
		Vector32	R0 = Vector32() , R1 = Vector32(), C = Vector32();
	};
	struct QDEF                                             /* 4个权重和不保证=1 */
	{
		Int32	bone1 = 0, bone2 = 0, bone3 = 0, bone4 = 0;
		Float32 weight1 = 0.f, weight2 = 0.f, weight3 = 0.f, weight4 = 0.f;
	};
	struct PMX_Data_count
	{
		Int32 vertex_data_count = 0,
			surface_data_count = 0,
			texture_data_count = 0,
			material_data_count = 0,
			bone_data_count = 0,
			morph_data_count = 0,
			display_data_count = 0,
			rigid_body_data_count = 0,
			joint_data_count = 0;
	};
	struct PMX_Vertex_Data                  /* 顶点数据 */
	{
		Vector32	position = Vector32();       /* 位置 */
		Vector32	normal = Vector32();         /* 法向量 */
		Vector2d32	UV = Vector2d32();             /* UV坐标 */
		/* 跳过额外的Vector4d32[N]  16*N */
		Char weight_deform_type = 0;    /* 变型权重类型,0=BDEF1, 1=BDEF2, 2=BDEF4, 3=SDEF, 4=QDEF */
		union
		{
			BDEF1	weight_deform_B1;
			BDEF2	weight_deform_B2;
			BDEF4	weight_deform_B4;
			SDEF	weight_deform_S;
			QDEF	weight_deform_Q;
		};                              /* 变型权重 */
		Float32 edge_scale = 0.f;        /* 边缘放大率 */
		PMX_Vertex_Data()
		{
		};
	};
	struct PMX_Material_Flags               /* 材质标志(1bytes) */
	{
		Bool	no_cull : 1;            /* 双面描绘 */
		Bool	ground_shadow : 1;      /* 将阴影投射到几何体上 */
		Bool	draw_shadow : 1;        /* 渲染到阴影贴图（本影标示） */
		Bool	Receive_shadow : 1;     /* 从阴影贴图接受阴影（本影） */
		Bool	has_edge : 1;           /*有边缘描绘（轮廓线有效） */
		Bool	vertex_colour : 1;      /* 使用额外的Vector4d32作为顶点的颜色 */
		Bool	point_drawing : 1;      /*三个顶点都被画出 */
		Bool	line_drawing : 1;       /*三个边被画出 */
		PMX_Material_Flags()
		{
			this->no_cull = 0;
			this->ground_shadow = 0;
			this->draw_shadow = 0;
			this->Receive_shadow = 0;
			this->has_edge = 0;
			this->vertex_colour = 0;
			this->point_drawing = 0;
			this->line_drawing = 0;
		}
	};
	struct PMX_Material_Data                                        /* 材质数据 */
	{
		String			material_name_local = String();         /* 本地的材质名称，日语、中文等等 */
		String			material_name_universal = String();     /* 通用的材质名称，一般是英文 */
		Vector4d32		diffuse_colour = Vector4d32(1);                 /* 漫反射颜色RGBA */
		Vector32		specular_colour = Vector32();                /* 镜面光（高光）颜色RGB */
		Float32			specular_strength = 5.f;         /* 镜面光强度 */
		Vector32		ambient_colour = Vector32(1);                 /* 环境色,当光线不足时的阴影色（既基础色，让阴影不那么黑） */
		PMX_Material_Flags	drawing_flags= PMX_Material_Flags();                  /* 绘制标记 */
		Vector4d32		edge_colour = Vector4d32(0, 0, 0, 1);                    /* 边缘颜色RGBA */
		Float32			edge_scale = 1.f;   /* 边缘比例[0, 1] */
		Int32			texture_index = -1;    /* 纹理索引 */
		Int32			environment_index = 0;    /* 环境（高光贴图）索引，用于环境映射 */
		Char			environment_blend_mode = 0;    /* 环境（高光贴图）混合模式,0=禁用, 1=乘, 2=加, 3=额外的Vector4d32 */
		Char			toon_reference = 0;    /* 贴图引用 0 = 引用纹理, 1 = 内部引用 */
		Int32			toon_part = 0;
		Char			toon_internal = 0;
		String			meta_data = String();                      /* 元数据,用于脚本或其他数据 */
		Int32			surface_count = 0;              /* 面数量,表示当前材质影响了多少个面 */
		PMX_Material_Data()
		{
		};
		~PMX_Material_Data()
		{
		};
	};
	struct PMX_Bone_Flags                           /* Bone标志(2bytes) */
	{
		Bool	indexed_tail_position : 1;      /* 骨骼尾部(尖端)位置,0为连接相对位置，1为连接子骨骼 */
		Bool	Rotatable : 1;                  /* 启用旋转 */
		Bool	Translatable : 1;               /* 启用移动 */
		Bool	Is_visible : 1;                 /* 启用显示 */
		Bool	Enabled : 1;                    /* 启用操作 */
		Bool	IK : 1;                         /* 启用IK骨 */
		Bool : 2;                               /* 占位 */
		Bool	Inherit_rotation : 1;           /* 启用继承亲骨的旋转 */
		Bool	Inherit_translation : 1;        /* 启用继承亲骨的移动 */
		Bool	Fixed_axis : 1;                 /* 启用轴限制 */
		Bool	Local_coordinate : 1;           /* 启用Local轴 */
		Bool	Physics_after_deform : 1;       /* 先变形，后算物理 */
		Bool	External_parent_deform : 1;     /* 外部亲骨骼变形 */
		Bool : 2;                               /* 占位 */
		PMX_Bone_Flags()
		{
			this->indexed_tail_position = 0;
			this->Rotatable = 0;
			this->Translatable = 0;
			this->Is_visible = 0;
			this->Enabled = 0;
			this->IK = 0;
			this->Inherit_rotation = 0;
			this->Inherit_translation = 0;
			this->Fixed_axis = 0;
			this->Local_coordinate = 0;
			this->Physics_after_deform = 0;
			this->External_parent_deform = 0;
		}
	};
	struct PMX_IK_links
	{
		Int32		bone_index = 0;                            /* 骨骼索引 */
		Bool		has_limits = 0;                            /* 值为1时，使用角度限制 */
		Vector32	limit_min = Vector32();                                      /* IK 角度限制最小角度(弧度制) */
		Vector32	limit_max = Vector32();                                      /* IK 角度限制最大角度(弧度制) */
	};
	struct PMX_Bone_Data
	{
		String		bone_name_local = String();                                /* 骨骼本地名称通常是日语 */
		String		bone_name_universal = String();                              /* 骨骼通用名称一般是英文 */
		Vector32	position = Vector32();                                        /* 位置 */
		Int32		parent_bone_index = 0;                    /* 亲骨索引, 特殊的：操作中心的亲骨为-1 */
		Int32		layer = 0;                    /* 变形阶层 */
		PMX_Bone_Flags	bone_flags = PMX_Bone_Flags();                                     /* Bone标志 */
		Vector32	tail_position = Vector32();
		Int32		tail_index = 0;
		/* 尾部位置,相对位置或连接子骨骼 */
		Int32		inherit_bone_parent_index = 0;            /* 骨骼继承-亲骨索引 */
		Float32		inherit_bone_parent_influence = 0.f;           /* 骨骼继承-影响权重 */
		Vector32	bone_fixed_axis = Vector32();                              /* 骨骼固定轴-轴方向 */
		Vector32	bone_local_X = Vector32();                                 /* 骨骼Local坐标-X矢量 */
		Vector32	bone_local_Z = Vector32();                                /* 骨骼Local坐标-Z矢量 */
		/* 跳过外亲骨(index) */
		Int32					IK_target_index = 0;    /* IK骨-目标骨骼索引 */
		Int32					IK_loop_count = 0;    /* IK骨-循环计数 */
		Float32					IK_limit_radian = 0.f;   /* IK骨-单位角 */
		Int32					IK_link_count = 0;    /* IK骨-IK链计数 */
		maxon::PointerArray<PMX_IK_links>	IK_links;
		PMX_Bone_Data()
		{
		};
		PMX_Bone_Data(const PMX_Bone_Data& src)
		{
			this->bone_name_local = src.bone_name_local;
			this->bone_name_universal = src.bone_name_universal;
			this->position = src.position;
			this->parent_bone_index = src.parent_bone_index;
			this->layer = src.layer;
			this->bone_flags = src.bone_flags;
			this->tail_position = src.tail_position;
			this->tail_index = src.tail_index;
			this->inherit_bone_parent_index = src.inherit_bone_parent_index;
			this->inherit_bone_parent_influence = src.inherit_bone_parent_influence;
			this->bone_fixed_axis = src.bone_fixed_axis;
			this->bone_local_X = src.bone_local_X;
			this->bone_local_Z = src.bone_local_Z;
			this->IK_target_index = src.IK_target_index;
			this->IK_loop_count = src.IK_loop_count;
			this->IK_limit_radian = src.IK_limit_radian;
			this->IK_link_count = src.IK_link_count;
			this->IK_links.CopyFrom(src.IK_links) iferr_ignore("err"_s);
		}


		mmd::PMX_Bone_Data& operator =(const mmd::PMX_Bone_Data& src)
		{
			if (&src == this)
			{
				return(*this);
			}
			this->bone_name_local = src.bone_name_local;
			this->bone_name_universal = src.bone_name_universal;
			this->position = src.position;
			this->parent_bone_index = src.parent_bone_index;
			this->layer = src.layer;
			this->bone_flags = src.bone_flags;
			this->tail_position = src.tail_position;
			this->tail_index = src.tail_index;
			this->inherit_bone_parent_index = src.inherit_bone_parent_index;
			this->inherit_bone_parent_influence = src.inherit_bone_parent_influence;
			this->bone_fixed_axis = src.bone_fixed_axis;
			this->bone_local_X = src.bone_local_X;
			this->bone_local_Z = src.bone_local_Z;
			this->IK_target_index = src.IK_target_index;
			this->IK_loop_count = src.IK_loop_count;
			this->IK_limit_radian = src.IK_limit_radian;
			this->IK_link_count = src.IK_link_count;
			this->IK_links.CopyFrom(src.IK_links) iferr_ignore("err"_s);
			return(*this);
		}
	};
	struct PMX_Morph_group
	{
		Int32	morph_index = 0;                    /* 变形索引 */
		Float32 influence = 0.f;                   /* 影响 */
	};
	struct PMX_Morph_vertex
	{
		UInt32		vertex_index = 0;               /* 顶点索引 */
		Vector32	translation = Vector32();                   /* 移动 */
	};
	struct PMX_Morph_bone
	{
		Int32		bone_index = 0;                 /* 骨骼索引 */
		Vector32	translation = Vector32();                  /* 变化的相对位置 */
		Vector32	rotation = Vector32();                      /* 相对旋转四元数(转欧拉) */
	};
	struct PMX_Morph_UV
	{
		Int32		vertex_index = 0;               /* 顶点索引 */
		Vector4d32	floats;                         /* 影响(只有x、y有用，z、w为0) */
	};
	struct PMX_Morph_material
	{
		Int32		material_index = 0;            /* 材质索引 */
		Char		blend_mode = 0;            /* 混合方法 */
		Vector4d32	diffuse = Vector4d32();                        /* 漫反射（扩散色） */
		Vector32	specular = Vector32();                      /* 镜面光（反射色） */
		Float32		specularity = 0.f;               /* 镜面光强度 */
		Vector32	ambient = Vector32();                       /* 环境光（环境色） */
		Vector4d32	edge_colour = Vector4d32();                    /* 边缘颜色 */
		Float32		edge_size = 0.f;                 /* 边缘大小 */
		Vector4d32	texture_tint = Vector4d32();                  /* 纹理色调 */
		Vector4d32	environment_tint = Vector4d32();                /* 环境色调 */
		Vector4d32	toon_tint = Vector4d32();                      /* 贴图色调 */
	};
	struct PMX_Morph_flip
	{
		Int32	morph_index = 0;                    /* 变形索引 */
		Float32 influence = 0.;                   /* 影响 */
	};
	struct PMX_Morph_impulse
	{
		Int32		rigid_body_index = 0;    /* 刚体索引 */
		Char		local_flag = 0;    /* 本地标志 */
		Vector32	movement_speed = Vector32();                  /* 移动速度 */
		Vector32	rotation_torque = Vector32();                /* 转动扭矩 */
	};
	struct PMX_Morph_Data
	{
		String	morph_name_local = String();                        /* 本地变形名称 */
		String	morph_name_universal = String();                     /* 通用变形名称 */
		Char	panel_type = 0;                         /* 面板位置, { 1,2,3,4 }，表情在MMD面板中处于的位置 */

		/*
		 * 变型类型
		 * 0 - 组合（Group）
		 * 1 - 顶点（Vertex）
		 * 2 - 骨骼（Bone）
		 * 3~7 - UV（及拓展UV）
		 * 8 - 材质（Material）
		 * 9 - 切换（Flip）
		 * 10 - 脉冲（Impulse）
		 */
		Char	morph_type = 0;
		Int32	offset_count = 0;                    /* 偏移量个数 */
		void* offset_data = nullptr;              /* 偏移量数据 */
		~PMX_Morph_Data()
		{
			if (offset_data != nullptr)
			{
				switch (this->morph_type)
				{
				case 0:
				{
					maxon::PointerArray<PMX_Morph_group>* offset_data_groups = (maxon::PointerArray<PMX_Morph_group>*)offset_data;
					DeleteObj(offset_data_groups);
					break;
				}
				case 1:
				{
					maxon::PointerArray<PMX_Morph_vertex>* offset_data_vertexs = (maxon::PointerArray<PMX_Morph_vertex>*)offset_data;
					DeleteObj(offset_data_vertexs);
					break;
				}
				case 2:
				{
					maxon::PointerArray<PMX_Morph_bone>* offset_data_bones = (maxon::PointerArray<PMX_Morph_bone>*)offset_data;
					DeleteObj(offset_data_bones);
					break;
				}
				case 3:
				{
					maxon::PointerArray<PMX_Morph_UV>* offset_data_UVs = (maxon::PointerArray<PMX_Morph_UV>*)offset_data;
					DeleteObj(offset_data_UVs);
					break;
				}
				case 8:
				{
					maxon::PointerArray<PMX_Morph_material>* offset_data_materials = (maxon::PointerArray<PMX_Morph_material>*)offset_data;
					DeleteObj(offset_data_materials);
					break;
				}
				case 9:
				{
					maxon::PointerArray<PMX_Morph_flip>* offset_data_flips = (maxon::PointerArray<PMX_Morph_flip>*)offset_data;
					DeleteObj(offset_data_flips);
					break;
				}
				case 10:
				{
					maxon::PointerArray<PMX_Morph_impulse>* offset_data_impulses = (maxon::PointerArray<PMX_Morph_impulse>*)offset_data;
					DeleteObj(offset_data_impulses);
					break;
				}
				default:
					break;
				}
			}
		};
	};
	struct PMX_Frame_data                                                   /* 帧数据 */
	{
		Char	frame_type = 0;                                    /* 0:索引-骨骼,1:索引 - 变形 */
		Int32	frame_data = 0;                                    /* 索引 */
	};
	struct PMX_Display_Data                                                 /* 表示枠数据 */
	{
		String					display_name_local = String();       /* 表示枠本地名称 */
		String					display_name_universal = String();   /* 表示枠通用名称 */
		Char					special_flag = 0;    /* 0表示普通帧，1表示特殊帧 */
		Int32					frame_count = 0;    /* 记录有多少个帧 */
		maxon::PointerArray<PMX_Frame_data>	Frames;                 /* 帧数据 */
		PMX_Display_Data()
		{
		}


		PMX_Display_Data(const PMX_Display_Data& src)
		{
			this->display_name_local = src.display_name_local;
			this->display_name_universal = src.display_name_universal;
			this->special_flag = src.special_flag;
			this->frame_count = src.frame_count;
			this->Frames.CopyFrom(src.Frames) iferr_ignore("err"_s);
		}
	};
	struct PMX_Rigid_body_non_collision_group /* 非碰撞组掩码(2bytes) */
	{
		Bool	G1 : 1;
		Bool	G2 : 1;
		Bool	G3 : 1;
		Bool	G4 : 1;
		Bool	G5 : 1;
		Bool	G6 : 1;
		Bool	G7 : 1;
		Bool	G8 : 1;
		Bool	G9 : 1;
		Bool	G10 : 1;
		Bool	G11 : 1;
		Bool	G12 : 1;
		Bool	G13 : 1;
		Bool	G14 : 1;
		Bool	G15 : 1;
		Bool	G16 : 1;

		PMX_Rigid_body_non_collision_group(
			Bool G1_ = 0,
			Bool G2_ = 0,
			Bool G3_ = 0,
			Bool G4_ = 0,
			Bool G5_ = 0,
			Bool G6_ = 0,
			Bool G7_ = 0,
			Bool G8_ = 0,
			Bool G9_ = 0,
			Bool G10_ = 0,
			Bool G11_ = 0,
			Bool G12_ = 0,
			Bool G13_ = 0,
			Bool G14_ = 0,
			Bool G15_ = 0,
			Bool G16_ = 0)
		{
			this->G1 = G1_;
			this->G2 = G2_;
			this->G3 = G3_;
			this->G4 = G4_;
			this->G5 = G5_;
			this->G6 = G6_;
			this->G7 = G7_;
			this->G8 = G8_;
			this->G9 = G9_;
			this->G10 = G10_;
			this->G11 = G11_;
			this->G12 = G12_;
			this->G13 = G13_;
			this->G14 = G14_;
			this->G15 = G15_;
			this->G16 = G16_;
		}
	};
	struct PMX_Rigid_Body_Data
	{
		String					rigid_body_name_local = String();            /* 刚体本地名称 */
		String					rigid_body_name_universal = String();        /* 刚体通用名称 */
		Int32					related_bone_index = 0;    /* 关联骨骼索引 */
		Char					group_id = 0;    /* 群组ID */
		PMX_Rigid_body_non_collision_group	non_collision_group = PMX_Rigid_body_non_collision_group();    /* 非碰撞组 */


		/*
		 * 刚体形状类型
		 * 0 - 球
		 * 1 - 盒子
		 * 2 - 胶囊
		 */
		Char		shape_type = 0;
		Vector32	shape_size = Vector32();                                             /* 形状大小 */
		Vector32	shape_position = Vector32();                                        /* 形状位置 */
		Vector32	shape_rotation = Vector32();                                        /* 形状旋转 */
		Float32		mass = 0.;                           /* 质量 */
		Float32		move_attenuation = 0.;                           /* 移动衰减 */
		Float32		rotation_damping = 0.;                           /* 旋转衰减 */
		Float32		repulsion = 0.;                           /* 反应力 */
		Float32		friction_force = 0.;                           /* 摩擦力 */


		/*
		 * 物理模式
		 * 0 - 追踪骨骼
		 * 1 - 物理演算
		 * 2 - 物理+骨骼
		 */
		Char physics_mode = 0;
		PMX_Rigid_Body_Data()
		{
		}


		~PMX_Rigid_Body_Data()
		{
		}
	};
	struct PMX_Joint_Data
	{
		String	joint_name_local = String();                        /* 关节点本地名称 */
		String	joint_name_universal = String();                     /* 关节点通用名称 */


		/*
		 * 关节点类型
		 * 0 - Spring 6DOF
		 * 1 - 6DOF
		 * 2 - P2P - 点结合
		 * 3 - ConeTwist - 轴旋转
		 * 4 - Slider - 轴移动
		 * 5 - Hinge - 轴旋转
		 */
		Char		joint_type = 0;
		Int32		rigid_body_index_A = 0;    /* 刚体索引A */
		Int32		rigid_body_index_B = 0;    /* 刚体索引B */
		Vector32	position = Vector32();                       /* 位置 */
		Vector32	rotation = Vector32();                       /* 旋转 */
		Vector32	position_minimum = Vector32();               /* 位置最小值 */
		Vector32	position_maximum = Vector32();               /* 位置最大值 */
		Vector32	rotation_minimum = Vector32();               /* 旋转最小值 */
		Vector32	rotation_maximum = Vector32();               /* 旋转最大值 */
		Vector32	position_spring = Vector32();                /* 定位弹簧 */
		Vector32	rotation_spring = Vector32();                /* 旋转弹簧 */
	};

	struct LocalData : public maxon::ParallelFor::BreakContext
	{
		maxon::Int localCount = 0;
	};
}
#endif //__MMD_STRUCT_H__