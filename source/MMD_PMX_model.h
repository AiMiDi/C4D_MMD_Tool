#ifndef __MMD_VMD_MODEl_H__
#define __MMD_VMD_MODEl_H__

#include "main.h"

namespace mmd {

	typedef maxon::Vec2<Float32> vec2;
	typedef maxon::Vec3<Float32> vec3;
	typedef maxon::Vec4<Float32> vec4;

	struct PMX_Model_information {
		Float32 version;//版本号
		Char text_encoding;//字符串编码,0为UTF16LE编码，1为UTF8编码
		Char additional_vec4_count;//额外的vec4数量
		Char vertex_index_size;//顶点索引大小	
		Char texture_index_size;//纹理索引大小	
		Char material_index_size;//材质索引大小
		Char bone_index_size;//骨骼索引大小
		Char morph_index_size;//表情索引大小	
		Char rigidbody_index_size;//刚体索引大小
		String model_name_local;//本地模型名
		String model_name_universal;//通用模型名
		String comments_local;//本地语言模型描述
		String comments_universal;//通用语言模型描述
	};

	struct BDEF1//权重==1
	{
		Int32 bone1;
	};
	struct BDEF2//骨骼2权重 = 1-骨骼1权重
	{
		Int32 bone1, bone2;
		Float32 weight1;
	};
	struct BDEF4//4个权重和不保证=1
	{
		Int32 bone1, bone2, bone3, bone4;
		Float32 weight1, weight2, weight3, weight4;
	};
	struct SDEF//骨骼2权重 = 1-骨骼1权重
	{
		Int32 bone1, bone2;
		Float32 weight1;
		vec3 R0, R1, C;
	};
	struct QDEF//4个权重和不保证=1
	{
		Int32 bone1, bone2, bone3, bone4;
		Float32 weight1, weight2, weight3, weight4;
	};
	struct PMX_Data_count
	{
		Int32 vertex_data_count, surface_data_count, texture_data_count, material_data_count, bone_data_count, morph_data_count, display_data_count, rigid_body_data_count, joint_data_count;
	};
	struct PMX_Vertex_Data//顶点数据
	{
		vec3 position;//位置
		vec3 normal;//法向量
		vec2 UV;//UV坐标
		//跳过额外的vec4[N]  16*N
		Char weight_deform_type;//变型权重类型,0=BDEF1, 1=BDEF2, 2=BDEF4, 3=SDEF, 4=QDEF
		union
		{
			BDEF1 weight_deform_B1;
			BDEF2 weight_deform_B2;
			BDEF4 weight_deform_B4;
			SDEF weight_deform_S;
			QDEF weight_deform_Q;
		};//变型权重
		Float32 edge_scale;//边缘放大率
		PMX_Vertex_Data() {};
	};
	struct PMX_Material_Flags//材质标志(1bytes)
	{
		Bool no_cull : 1;//双面描绘
		Bool ground_shadow : 1;//将阴影投射到几何体上
		Bool draw_shadow : 1;//渲染到阴影贴图（本影标示）
		Bool Receive_shadow : 1;//从阴影贴图接受阴影（本影）
		Bool has_edge : 1;//有边缘描绘（轮廓线有效）
		Bool vertex_colour : 1;//使用额外的vec4作为顶点的颜色
		Bool point_drawing : 1;//三个顶点都被画出
		Bool line_drawing : 1;//三个边被画出
	};
	struct PMX_Material_Data//材质数据
	{
		String material_name_local;//本地的材质名称，日语、中文等等
		String material_name_universal;//通用的材质名称，一般是英文
		vec4 diffuse_colour;//漫反射颜色RGBA
		vec3 specular_colour;//镜面光（高光）颜色RGB
		Float32 specular_strength;//镜面光强度
		vec3 ambient_colour;//环境色,当光线不足时的阴影色（既基础色，让阴影不那么黑）
		PMX_Material_Flags drawing_flags;//绘制标记
		vec4 edge_colour;//边缘颜色RGBA
		Float32 edge_scale;//边缘比例[0, 1]
		Int32 texture_index;//纹理索引
		Int32 environment_index;//环境（高光贴图）索引，用于环境映射
		Char environment_blend_mode;//环境（高光贴图）混合模式,0=禁用, 1=乘, 2=加, 3=额外的vec4
		Char toon_reference;//贴图引用 0 = 引用纹理, 1 = 内部引用
		union
		{
			Int32 toon_part;
			Char toon_internal;
		};//贴图值,取决于贴图引用
		String meta_data;//元数据,用于脚本或其他数据
		Int32 surface_count; //面数量,表示当前材质影响了多少个面
		PMX_Material_Data() {};
		~PMX_Material_Data() {};
	};
	struct PMX_Bone_Flags //Bone标志(2bytes)
	{
		Bool indexed_tail_position : 1;//骨骼尾部(尖端)位置,0为连接相对位置，1为连接子骨骼
		Bool Rotatable : 1;//启用旋转
		Bool Translatable : 1;//启用移动
		Bool Is_visible : 1;//启用显示
		Bool Enabled : 1;//启用操作
		Bool IK : 1;//启用IK骨
		Bool : 2;//占位
		Bool Inherit_rotation : 1;//启用继承亲骨的旋转
		Bool Inherit_translation : 1;//启用继承亲骨的移动
		Bool Fixed_axis : 1;//启用轴限制
		Bool Local_co_ordinate : 1;//启用Local轴
		Bool Physics_after_deform : 1;//先变形，后算物理
		Bool External_parent_deform : 1;//外部亲骨骼变形
		Bool : 2;//占位
	};
	struct PMX_IK_links
	{
		Int32 bone_index;//骨骼索引
		Bool has_limits;//值为1时，使用角度限制
		vec3 limit_min;//IK 角度限制最小角度(弧度制)
		vec3 limit_max;//IK 角度限制最大角度(弧度制)
	};
	struct PMX_Bone_Data
	{
		String bone_name_local;//骨骼本地名称通常是日语
		String bone_name_universal;//骨骼通用名称一般是英文
		vec3 position;//位置
		Int32 parent_bone_index;//亲骨索引, 特殊的：操作中心的亲骨为-1
		Int32 layer;//变形阶层
		PMX_Bone_Flags bone_flags;//Bone标志
		union
		{
			vec3 tail_position;
			Int32 tail_index;
		};//尾部位置,相对位置或连接子骨骼
		Int32 inherit_bone_parent_index;//骨骼继承-亲骨索引
		Float32 inherit_bone_parent_influence;//骨骼继承-影响权重
		vec3 bone_fixed_axis;//骨骼固定轴-轴方向
		vec3 bone_local_X;//骨骼Local坐标-X矢量
		vec3 bone_local_Z;//骨骼Local坐标-Z矢量
		//跳过外亲骨(index)
		Int32 IK_target_index;//IK骨-目标骨骼索引
		Int32 IK_loop_count;//IK骨-循环计数
		Float32 IK_limit_radian;//IK骨-单位角
		Int32 IK_link_count;//IK骨-IK链计数
		maxon::BaseArray<PMX_IK_links*> IK_links;
		PMX_Bone_Data() {};
		~PMX_Bone_Data() { 
			for (auto i : IK_links) {
				delete i;
			}
			IK_links.Reset(); 
		};
	};
	struct PMX_Morph_group
	{
		Int32 morph_index;//变形索引
		Float32 influence;//影响
	};
	struct PMX_Morph_vertex
	{
		Int32 vertex_index;//顶点索引
		vec3 translation;//移动
	};
	struct PMX_Morph_bone
	{
		Int32 bone_index;//骨骼索引
		vec3 translation;//变化的相对位置
		vec3 rotation;//相对旋转四元数(转欧拉)
	};
	struct PMX_Morph_UV
	{
		Int32 vertex_index;//顶点索引
		vec4 floats;//影响(只有x、y有用，z、w为0)
	};
	struct PMX_Morph_material
	{
		Int32 material_index;//材质索引
		Char blend_mode;//混合方法
		vec4 diffuse;//漫反射（扩散色）
		vec3 specular;//镜面光（反射色）
		Float32 specularity;//镜面光强度
		vec3 ambient;//环境光（环境色）
		vec4 edge_colour;//边缘颜色
		Float32 edge_size;//边缘大小
		vec4 texture_tint;//纹理色调
		vec4 environment_tint;//环境色调
		vec4 toon_tint;//贴图色调
	};
	struct PMX_Morph_flip
	{
		Int32 morph_index;//变形索引
		Float32 influence;//影响
	};
	struct PMX_Morph_impulse
	{
		Int32 rigid_body_index;//刚体索引
		Char local_flag;//本地标志
		vec3 movement_speed;//移动速度
		vec3 rotation_torque;//转动扭矩
	};
	struct PMX_Morph_Data
	{
		String morph_name_local;//本地变形名称
		String morph_name_universal;//通用变形名称
		Char panel_type;//面板位置, { 1,2,3,4 }，表情在MMD面板中处于的位置
		/*
		变型类型
		0 - 组合（Group）
		1 - 顶点（Vertex）
		2 - 骨骼（Bone）
		3~7 - UV（及拓展UV）
		8 - 材质（Material）
		9 - 切换（Flip）
		10 - 脉冲（Impulse）
		*/
		Char morph_type;
		Int32 offset_count;//偏移量个数
		void* offset_data;//偏移量数据
		PMX_Morph_Data(){};
		~PMX_Morph_Data() {
			delete offset_data;
		};
	};
	struct PMX_Frame_data//帧数据
	{
		Char frame_type;//0:索引-骨骼,1:索引 - 变形
		Int32 frame_data;//索引
	};
	struct PMX_Display_Data//表示枠数据
	{
		String display_name_local;//表示枠本地名称
		String display_name_universal;//表示枠通用名称
		Char special_flag;//0表示普通帧，1表示特殊帧
		Int32 frame_count;//记录有多少个帧
		maxon::BaseArray<PMX_Frame_data*> Frames;//帧数据
		PMX_Display_Data() {};
		~PMX_Display_Data() {
			for (auto i : Frames) {
				delete i;
			}
			Frames.Reset();
		};
	};
	struct PMX_Rigid_body_non_collision_group//非碰撞组掩码(2bytes)
	{
		Bool G1 : 1;
		Bool G2 : 1;
		Bool G3 : 1;
		Bool G4 : 1;
		Bool G5 : 1;
		Bool G6 : 1;
		Bool G7 : 1;
		Bool G8 : 1;
		Bool G9 : 1;
		Bool G10 : 1;
		Bool G11 : 1;
		Bool G12 : 1;
		Bool G13 : 1;
		Bool G14 : 1;
		Bool G15 : 1;
		Bool G16 : 1;
	};
	struct PMX_Rigid_Body_Data
	{
		String rigid_body_name_local;//刚体本地名称
		String rigid_body_name_universal;//刚体通用名称
		Int32 related_bone_index;//关联骨骼索引
		Char group_id;//群组ID
		PMX_Rigid_body_non_collision_group non_collision_group;//非碰撞组
		/*
		刚体形状类型
		0 - 球
		1 - 盒子
		2 - 胶囊
		*/
		Char shape_type;
		vec3 shape_size;//形状大小
		vec3 shape_position;//形状位置
		vec3 shape_rotation;//形状旋转
		Float32 mass;//质量
		Float32 move_attenuation;//移动衰减
		Float32 rotation_damping;//旋转衰减
		Float32 repulsion;//反应力
		Float32 friction_force;//摩擦力
		/*
		物理模式
		0 - 追踪骨骼
		1 - 物理演算
		2 - 物理+骨骼
		*/
		Char physics_mode;
		PMX_Rigid_Body_Data() {};
		~PMX_Rigid_Body_Data() {};
	};
	struct PMX_Joint_Data
	{
		String joint_name_local;//关节点本地名称
		String joint_name_universal;//关节点通用名称
		/*
		关节点类型
		0 - Spring 6DOF
		1 - 6DOF
		2 - P2P - 点结合
		3 - ConeTwist - 轴旋转
		4 - Slider - 轴移动
		5 - Hinge - 轴旋转
		*/
		Char joint_type;
		Int32 rigid_body_index_A;//刚体索引A
		Int32 rigid_body_index_B;//刚体索引B
		vec3 position;//位置
		vec3 rotation;//旋转
		vec3 position_minimum;//位置最小值
		vec3 position_maximum;//位置最大值
		vec3 rotation_minimum;//旋转最小值
		vec3 rotation_maximum;//旋转最大值
		vec3 position_spring;//定位弹簧
		vec3 rotation_spring;//旋转弹簧
		PMX_Joint_Data() {};
		~PMX_Joint_Data() {};
	};

	class PMXModel
	{
	private:
		PMX_Model_information model_info;//模型信息
		PMX_Data_count model_data_count;//模型数据计数
		maxon::BaseArray<PMX_Vertex_Data*> vertex_data;//顶点数据
		maxon::BaseArray<CPolygon*> surface_data;//面数据
		maxon::PointerArray<String> texture_data;//贴图数据
		maxon::BaseArray<PMX_Material_Data*> material_data;//材质数据
		maxon::BaseArray<PMX_Bone_Data*> bone_data;//骨骼数据
		maxon::BaseArray<PMX_Morph_Data*> morph_data;//变形数据
		maxon::BaseArray<PMX_Display_Data*> display_data;//表示枠数据
		maxon::BaseArray<PMX_Rigid_Body_Data*> rigid_body_data;//刚体数据
		maxon::BaseArray<PMX_Joint_Data*> joint_data;//J点数据
		
		//---------------------------------------------
		///根据编码和长度读取mmd模型的文本（Text）数据
		///BaseFile* const file				文件指针
		///Char& text_encoding			文本编码
		///String* text						读取文本地址
		///@return Bool						成功为TRUE
		//---------------------------------------------
		String ReadText(BaseFile* const file, Char& text_encoding);

		//---------------------------------------------
		///根据索引长度读取mmd模型索引（Index）数据
		///BaseFile* const file				文件指针
		///Char& text_encoding			索引长度
		///@return Int32	 			读取到的索引
		//---------------------------------------------
		Int32 ReadIndex(BaseFile* const file, Char& index_size);
		UInt32 ReadUIndex(BaseFile* const file, Char& index_size);
	public:
		PMXModel();
		~PMXModel();
		maxon::Result<void> LoadFromFile(BaseFile* const file);
		maxon::Result<void> WriteToFile(BaseFile* const file);
		static maxon::Result<void> FromFileImportModel(Float &PositionMultiple, Bool& Separate);
	};
}
#endif __MMD_VMD_MODEl_H__