#ifndef __MMD_VMD_MODEl_H__
#define __MMD_VMD_MODEl_H__

#include "Utility.h"
#include "NameConversion.h"
#include "TMMDBone.h"
#include "OMMDRigid.h"
#include "OMMDJoint.h"
#include "OMMDModel.h"

namespace mmd {
	/* MMD model */

	/* PMX model global information struct. */
	struct PMXModelInformation
	{
		Float32 version = 2.0f;                                      /* version */
		Char	text_encoding = 0;                                   /* String encoding. 0 is UTF16LE encoding and 1 is UTF8 encoding. */
		Char	additional_Vector4d32_count = 0;                     /* Additional Vector4d32 numbers */
		Char	vertex_index_size = 0;                               /* Vertex index size */
		Char	texture_index_size = 0;                              /* Texture index size */
		Char	material_index_size = 0;                             /* Material index size */
		Char	bone_index_size = 0;                                 /* Bone index size */
		Char	morph_index_size = 0;                                /* Morph index size */
		Char	rigidbody_index_size = 0;                            /* Rigid-body index size */
		String	model_name_local;                                    /* Local model name */
		String	model_name_universal;                                /* Generic model name */
		String	comments_local;                                      /* Local language model description */
		String	comments_universal;                                  /* Common language model description */
		Bool	have_UV_morph = false;                               /* Is there a UV morph */
		Bool	have_vertex_morph = false;                           /* Is there a vertex morph */
	};
	class PMXWeight
	{
	public:
		virtual ~PMXWeight() = default;

		static void Free(PMXWeight*& m) {
			DeleteObj(m);
			m = nullptr;
		}
		virtual Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) = 0;
	};
	/* Weight type BDEF1
	* weight==1 */
	class PMXWeight_BDEF1 final : public PMXWeight
	{

	public:
		~PMXWeight_BDEF1() override {}
		static maxon::Result<PMXWeight_BDEF1*> Alloc();
		Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) override;
		// Bone index. 
		Int32 bone = 0;

	};
	/* Weight type BDEF2
	* Bone 2 weight = 1 - (Bone 1 weight) */
	class PMXWeight_BDEF2 final : public PMXWeight
	{
	public:
		~PMXWeight_BDEF2() override {}
		static maxon::Result<PMXWeight_BDEF2*> Alloc();
		Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) override;
		Int32	bone[2] = { 0 };                               /* Bone index. */
		Float32 weight = 0.f;                                      /* Bone 1 weight */
	};
	/* Weight type BDEF4
	* The sum of four weights is not guaranteed to equal 1 */
	class PMXWeight_BDEF4 final : public PMXWeight
	{
	public:
		~PMXWeight_BDEF4() override {}
		static maxon::Result<PMXWeight_BDEF4*> Alloc();
		Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) override;
		Int32	bone[4] = { 0 };                   /* Bone index. */
		Float32 weight[4] = { 0.f };    /* Bone 1~4 weight */
	};
	/* Weight type SDEF
	* Bone 2 weight = 1 - (Bone 1 weight) */
	class PMXWeight_SDEF final : public PMXWeight
	{
	public:
		~PMXWeight_SDEF() override {}
		static maxon::Result<PMXWeight_SDEF*> Alloc();
		Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) override;
		Int32		bone[2] = { 0 };                             /* Bone index. */
		Float32		weight = 0.f;                                    /* Bone 1 weight */
		Vector32	R0 = Vector32(), R1 = Vector32(), C = Vector32(); /* R0,R1,C */
	};
	/* Weight type QDEF
	* The sum of four weights is not guaranteed to equal 1 */
	class PMXWeight_QDEF final : public PMXWeight
	{
	public:
		~PMXWeight_QDEF() override {}
		static maxon::Result<PMXWeight_QDEF*> Alloc();
		Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) override;
		Int32	bone[4] = { 0 };                /* Bone index. */
		Float32 weight[4] = { 0.f }; /* Bone 1~4 weight */
	};
	struct PMXDataCount
	{
		Int32 vertex_data_count = 0;
		Int32 surface_data_count = 0;
		Int32 texture_data_count = 0;
		Int32 material_data_count = 0;
		Int32 bone_data_count = 0;
		Int32 morph_data_count = 0;
		Int32 display_data_count = 0;
		Int32 rigid_body_data_count = 0;
		Int32 joint_data_count = 0;
	};
	/* PMX vertex data */
	struct PMXVertexData
	{
		Vector32	position = Vector32();       /* The position. */
		Vector32	normal = Vector32();         /* The normal vector. */
		Vector2d32	UV = Vector2d32();           /* The UV coordinates. */
		/* Skip the extra Vector4d32[N]  16*N */
		enum
		{
			BDEF1,
			BDEF2,
			BDEF4,
			SDEF,
			QDEF
		};
		Char weight_deform_type = BDEF1;             /* Variant weight type,0=BDEF1, 1=BDEF2, 2=BDEF4, 3=SDEF, 4=QDEF */
		/* Variant weight */
		PMXWeight* weight_deform = nullptr;
		Float32 edge_scale = 0.f;                /* Edge magnification */
		PMXVertexData();

		~PMXVertexData();
	};
	/* Material symbol(1 byte) */
	struct PMXMaterialFlags
	{
		Bool	no_cull : 1;            /* Double sided depiction */
		Bool	ground_shadow : 1;      /* Cast shadows on geometry */
		Bool	draw_shadow : 1;        /* Render to shadow map（本影标示）*/
		Bool	Receive_shadow : 1;     /* Accept shadows from shadow maps（本影）*/
		Bool	has_edge : 1;           /* Edge depiction（轮廓线有效） */
		Bool	vertex_colour : 1;      /* Use additional vector4d32 as the color of the vertices */
		Bool	point_drawing : 1;      /* All three vertices are drawn */
		Bool	line_drawing : 1;       /* Three sides are drawn */
		PMXMaterialFlags();
	};
	/* PMX material data */
	struct PMXMaterialData
	{
		String			material_name_local = String();                 /* Local material name, Japanese, Chinese, etc */
		String			material_name_universal = String();             /* General material name, usually in English */
		Vector4d32		diffuse_colour = Vector4d32(1);                 /* diffuse color RGBA */
		Vector32		specular_colour = Vector32();                   /* Specular (specular) color RGB */
		Float32			specular_strength = 5.f;                        /* Specular light intensity */
		Vector32		ambient_colour = Vector32(1);                   /* Environment color, the shadow color when the light is insufficient (i.e. the base color, which makes the shadow less black) */
		PMXMaterialFlags	drawing_flags = PMXMaterialFlags();       /* Draw marker */
		Vector4d32		edge_colour = Vector4d32(0, 0, 0, 1);           /* Edge color RGBA */
		Float32			edge_scale = 1.f;                               /* Edge scale[0, 1] */
		Int32			texture_index = -1;                             /* Texture index */
		Int32			environment_index = 0;                          /* Environment (specular map) index for environment mapping */
		Char			environment_blend_mode = 0;                     /* Environment (specular map) blend mode, 0 = off, 1 = multiply, 2 = add, 3 = extra vector4d32 */
		Char			toon_reference = 0;                             /* Map reference 0 = reference texture, 1 = internal reference */
		Int32			toon_part = 0;                                  /* toon texture part */
		Char			toon_internal = 0;                              /* toon internal index */
		String			meta_data = String();                           /* Metadata, used for scripts and other data. */
		Int32			surface_count = 0;                              /* Number of faces, which indicates how many faces are affected by the current material. */
		PMXMaterialData();
		~PMXMaterialData();
	};
	/* Bone flags(2bytes) */
	struct PMXBoneFlags
	{
		Bool	indexed_tail_position : 1;      /* The position of the tail (tip) of the bone, 0 is the relative position of the connection, and 1 is the connection sub bone */
		Bool	Rotatable : 1;                  /* Enable rotation */
		Bool	Translatable : 1;               /* Enable move */
		Bool	Is_visible : 1;                 /* Enable display */
		Bool	Enabled : 1;                    /* Enable action */
		Bool	IK : 1;                         /* Enable IK bone */
		Bool : 2;                               /* seize a seat */
		Bool	Inherit_rotation : 1;           /* Turn on inherit bone rotation */
		Bool	Inherit_translation : 1;        /* Enable inherited bone movement */
		Bool	Fixed_axis : 1;                 /* Enable axis limit */
		Bool	Local_coordinate : 1;           /* Enable local axis */
		Bool	Physics_after_deform : 1;       /* First deform, then calculate physics */
		Bool	External_parent_deform : 1;     /* External bony deformation */
		Bool : 2;                               /* seize a seat */
		PMXBoneFlags();
	};
	struct PMXIKLinks
	{
		Int32		bone_index = 0;                                /* Bone index */
		Bool		has_limits = 0;                                /* When the value is 1, the angle limit is used */
		Vector32	limit_min = Vector32();                        /* IK angle limit minimum angle (radians) */
		Vector32	limit_max = Vector32();                        /* IK angle limit maximum angle (radians) */
	};
	struct PMXBoneData
	{
		String		bone_name_local = String();                    /* The local name of the skeleton, usually Japanese. */
		String		bone_name_universal = String();                /* The common name of bones is usually English. */
		Vector32	position = Vector32();                         /* Bone position */
		Int32		parent_bone_index = 0;                         /* Bone affinity index, special: the bone affinity of the operation center is - 1 */
		Int32		layer = 0;                                     /* Deformation stratum */
		PMXBoneFlags	bone_flags = PMXBoneFlags();             /* Bone flags */
		Vector32	tail_position = Vector32();                    /* Bone tail coordinates (valid when relative on) */
		Int32		tail_index = 0;                                /* Bone tail index (valid when it is relatively unopened) */
		/* 尾部位置,相对位置或连接子骨骼 */
		Int32		inherit_bone_parent_index = 0;                 /* Bone inheritance - bone affinity index */
		Float32		inherit_bone_parent_influence = 0.f;           /* Bone inheritance - influence weights */
		Vector32	bone_fixed_axis = Vector32();                  /* Bone fixed axis - axis direction */
		Vector32	bone_local_X = Vector32();                     /* Bone local coordinates - x vector */
		Vector32	bone_local_Z = Vector32();                     /* Bone local coordinates - Z vector */
		/* 跳过外亲骨(index) */
		Int32					IK_target_index = 0;               /* IK bone - target bone index */
		Int32					IK_loop_count = 0;                 /* IK bone - cycle count */
		Float32					IK_limit_radian = 0.f;             /* IK bone - unit angle */
		Int32					IK_link_count = 0;                 /* IK bone IK chain count */
		maxon::PointerArray<PMXIKLinks>	IK_links;
		PMXBoneData();
		PMXBoneData(const PMXBoneData& src);


		mmd::PMXBoneData& operator =(const mmd::PMXBoneData& src);
	};
	class PMXMorph {
	public:
		virtual ~PMXMorph();
		static void Free(PMXMorph*& m);
		virtual Bool ReadFromFile(BaseFile* file, const Char& index_size) = 0;
	};
	class PMXMorph_Group final : public PMXMorph
	{
		friend class OMMDModel;
	public:
		~PMXMorph_Group() override;
		static maxon::Result<PMXMorph_Group*> Alloc();
		// index_size is morph index size.
		Bool ReadFromFile(BaseFile* file, const Char& index_size) override;
		Int32	morph_index = 0;                      /* Deformation index */
		Float32 influence = 0.f;                      /* influence */
	};
	class PMXMorph_Vertex final : public PMXMorph
	{
	public:
		~PMXMorph_Vertex() override;
		static maxon::Result<PMXMorph_Vertex*> Alloc();
		// index_size is vertex index size.
		Bool ReadFromFile(BaseFile* file, const Char& index_size) override;
		UInt32		vertex_index = 0;                 /* Vertex Index  */
		Vector32	translation = Vector32();         /* move */
	};
	class PMXMorph_Bone final : public PMXMorph
	{
	public:
		~PMXMorph_Bone() override;
		static maxon::Result<PMXMorph_Bone*> Alloc();
		// index_size is bone index size.
		Bool ReadFromFile(BaseFile* file, const Char& index_size) override;
		Int32		bone_index = 0;                   /* Bone index */
		Vector32	translation = Vector32();         /* Relative position of change */
		Vector32	rotation = Vector32();            /* Relative rotation quaternion (revolution Euler) */
	};
	class PMXMorph_UV final : public PMXMorph
	{
	public:
		~PMXMorph_UV() override;
		static maxon::Result<PMXMorph_UV*> Alloc();
		// index_size is vertex index size.
		Bool ReadFromFile(BaseFile* file, const Char& index_size) override;
		Int32		vertex_index = 0;                 /* Vertex Index */
		Vector4d32	floats;                           /* Influence (only x and y are useful, Z and W are 0) */
	};
	class PMXMorph_Material final : public PMXMorph
	{
	public:
		~PMXMorph_Material() override;
		static maxon::Result<PMXMorph_Material*> Alloc();
		// index_size is material index size.
		Bool ReadFromFile(BaseFile* file, const Char& index_size) override;
		Int32		material_index = 0;               /* Material index */
		Char		blend_mode = 0;                   /* Hybrid method */
		Vector4d32	diffuse = Vector4d32();           /* Diffuse (diffuse) */
		Vector32	specular = Vector32();            /* Specular light (reflected color) */
		Float32		specularity = 0.f;                /* Specular light intensity */
		Vector32	ambient = Vector32();             /* Ambient light (ambient color) */
		Vector4d32	edge_colour = Vector4d32();       /* Edge color */
		Float32		edge_size = 0.f;                  /* Edge size */
		Vector4d32	texture_tint = Vector4d32();      /* Texture tone */
		Vector4d32	environment_tint = Vector4d32();  /* Environmental tone */
		Vector4d32	toon_tint = Vector4d32();         /* Map hue */
	};
	class PMXMorph_Flip final : public PMXMorph
	{
		friend class OMMDModel;
	public:
		~PMXMorph_Flip() override;
		static maxon::Result<PMXMorph_Flip*> Alloc();
		// index_size is morph index size.
		Bool ReadFromFile(BaseFile* file, const Char& index_size) override;
		Int32	morph_index = 0;                      /* Deformation index */
		Float32 influence = 0.f;                       /* influence */
	};
	class PMXMorph_Impulse final : public PMXMorph
	{
	public:
		~PMXMorph_Impulse() override;
		static maxon::Result<PMXMorph_Impulse*> Alloc();
		// index_size is rigidbody index size.
		Bool ReadFromFile(BaseFile* file, const Char& index_size) override;
		Int32		rigid_body_index = 0;             /* Rigid body index */
		Char		local_flag = 0;                   /* Local flag */
		Vector32	movement_speed = Vector32();      /* Moving speed */
		Vector32	rotation_torque = Vector32();     /* Rotational torque */
	};


	struct PMXMorphData
	{
		String	morph_name_local = String();          /* Local deformation name */
		String	morph_name_universal = String();      /* Generic deformation name */
		Char	panel_type = 0;                       /* Panel position, { 1,2,3,4 }，The position of the expression in the MMD panel */
		enum
		{
			GROUP,// 组合（Group）
			VERTEX,// 顶点（Vertex）
			BONE,// 骨骼（Bone）
			UV,// UV
			UV1,// expansion UV1
			UV2,// expansion UV2
			UV3,// expansion UV3
			UV4,// expansion UV4
			MATERIAL,// 材质（Material）
			FLIP,// 切换（Flip）
			IMPULSE// 脉冲（Impulse）
		};
		Char	morph_type = GROUP;
		Int32	offset_count = 0;                    /* Number of offsets */
		maxon::BaseArray<PMXMorph*> offset_data;                 /* Offset data */
		~PMXMorphData();
	};
	/* Frame data */
	struct PMXFrameData
	{
		Char	frame_type = 0;                      /* 0: index - bone, 1: index - deformation */
		Int32	frame_data = 0;                      /* Indexes */
	};
	/* Display data */
	struct PMXDisplayData
	{
		String	display_name_local = String();       /* Represents a local name */
		String	display_name_universal = String();   /* Indicates the common name of the beam */
		Char	special_flag = 0;                    /* 0 represents normal frame and 1 represents special frame */
		Int32	frame_count = 0;                     /* How many frames are recorded */
		maxon::PointerArray<PMXFrameData>	Frames;  /* Frame data */
		PMXDisplayData();

		PMXDisplayData(const PMXDisplayData& src);
	};

	struct PMXRigidBodyData
	{
		String					rigid_body_name_local = String();                                          /* Rigid body local name */
		String					rigid_body_name_universal = String();                                      /* Rigid body common name */
		Int32					related_bone_index = 0;                                                    /* Associative bone index */
		Char					group_id = 0;                                                              /* Group ID */
		PMXRigidBodyNonCollisionGroup	non_collision_group = PMXRigidBodyNonCollisionGroup();    /* Collision exclusion group */
		/*
		 * Rigid body shape type
		 * 0 - Ball
		 * 1 - Box
		 * 2 - Capsule
		 */
		Char		shape_type = 0;
		Vector32	shape_size = Vector32();             /* Shape size */
		Vector32	shape_position = Vector32();         /* Shape position */
		Vector32	shape_rotation = Vector32();         /* Shape rotation */
		Float32		mass = 0.f;                           /* mass */
		Float32		move_attenuation = 0.f;               /* Movement attenuation */
		Float32		rotation_damping = 0.f;               /* Rotation attenuation */
		Float32		repulsion_force = 0.f;                /* Reaction force */
		Float32		friction_force = 0.f;                 /* friction force */
		/*
		 * Physical mode
		 * 0 - Tracking bones
		 * 1 - Physical calculus
		 * 2 - Physics + bone
		 */
		Char physics_mode = 0;

		PMXRigidBodyData();
		~PMXRigidBodyData();
	};
	struct PMXJointData
	{
		String	joint_name_local = String();            /* Joint point local name */
		String	joint_name_universal = String();        /* Common name of joint point */
		/*
		 * Joint point type
		 * 0 - Spring 6DOF
		 * 1 - 6DOF
		 * 2 - P2P - Point combination
		 * 3 - ConeTwist - Shaft rotation
		 * 4 - Slider - Axis movement
		 * 5 - Hinge - Shaft rotation
		 */
		Char		joint_type = 0;
		Int32		rigid_body_index_A = 0;             /* Rigid body index a*/
		Int32		rigid_body_index_B = 0;             /* Rigid body index b */
		Vector32	position = Vector32();              /* Rigid body position */
		Vector32	rotation = Vector32();              /* rigid rotation  */
		Vector32	position_minimum = Vector32();      /* Position min */
		Vector32	position_maximum = Vector32();      /* Position Max */
		Vector32	rotation_minimum = Vector32();      /* Rotation min */
		Vector32	rotation_maximum = Vector32();      /* Rotation Max */
		Vector32	position_spring = Vector32();       /* Positioning spring */
		Vector32	rotation_spring = Vector32();       /* Rotating spring */
	};
}
namespace tool {
	struct tag_info
	{
		MAXON_DISALLOW_COPY_AND_ASSIGN(tag_info)
		CAPoseMorphTag* morph_tag = nullptr;    
		maxon::BaseArray<Int32> vertex_index_arr;

		tag_info();
		tag_info(tag_info&& other) noexcept;

		tag_info& operator=(tag_info&& other) noexcept;
		maxon::HashInt GetHashCode() const;
	};
	class PMXModel
	{
		MAXON_DISALLOW_COPY_AND_ASSIGN(PMXModel)
		mmd::PMXModelInformation				m_model_info;             /* 模型信息 */
		mmd::PMXDataCount					m_model_data_count;       /* 模型数据计数 */
		maxon::PointerArray<mmd::PMXVertexData>		m_vertex_data;            /* 顶点数据 */
		maxon::PointerArray<CPolygon>			m_surface_data;           /* 面数据 */
		maxon::PointerArray<String>			m_texture_data;           /* 贴图数据 */
		maxon::PointerArray<mmd::PMXMaterialData>		m_material_data;          /* 材质数据 */
		maxon::PointerArray<mmd::PMXBoneData>		m_bone_data;              /* 骨骼数据 */
		maxon::PointerArray<mmd::PMXMorphData>		m_morph_data;             /* 变形数据 */
		maxon::PointerArray<mmd::PMXDisplayData>		m_display_data;           /* 表示枠数据 */
		maxon::PointerArray<mmd::PMXRigidBodyData>	m_rigid_body_data;        /* 刚体数据 */
		maxon::PointerArray<mmd::PMXJointData>		m_joint_data;             /* J点数据 */
		maxon::HashMap<Int32, BaseObject*> bone_map;
		BaseDocument* doc = nullptr;
		BaseObject* m_model_root = nullptr;
		BaseObject* m_bone_root = nullptr;
		BaseObject* m_mesh_root = nullptr;
	public:
		PMXModel();
		~PMXModel();

		struct
		{
			Float	position_multiple{};
			Bool	import_polygon{};
			Bool	import_normal{};
			Bool	import_uv{};
			Bool	import_material{};
			Bool	import_bone{};
			Bool	import_weights{};
			Bool	import_ik{};
			Bool	import_inherit{};
			Bool	import_expression{};
			Bool	import_multipart{};
			Bool	import_english{};
			Bool	import_english_check{};
		} m_import_settings{};
		struct
		{
			Float	position_multiple{};
			Bool	export_polygon{};
			Bool	export_normal{};
			Bool	export_uv{};
			Bool	export_material{};
			Bool	export_bone{};
			Bool	export_weights{};
			Bool	export_ik{};
			Bool	export_inherit{};
			Bool	export_expression{};
		} m_export_settings{};
		maxon::Result<String> GetMorphName(const Int32& index) const;
		maxon::Result<void> LoadFromFile(Filename& fn);
		maxon::Result<void> SaveToFile(Filename& fn);
		maxon::Result<void> ImportBone(CAWeightTag* weight_tag);
		maxon::Result<void> ImportWeight(CAWeightTag* weight_tag, BaseObject* obj, const tag_info* const morph_tag_info);
		maxon::Result<void> ImportMaterial(const String& path, const Int32& material_index, TextureTag* const texture_tag);
		maxon::Result<void> FromFileImportMultipartModel();
		maxon::Result<void> FromFileImportOneModel();
		maxon::Result<void> FromDocumentExportModel();
	};
}
#endif /* __MMD_VMD_MODEl_H__ */
