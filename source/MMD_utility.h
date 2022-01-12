#ifndef __MMD_UTILITY_H__
#define __MMD_UTILITY_H__

#include "main.h"

namespace mmd {
	typedef maxon::Vec2<Float32> Vector2d32;
	/* MMD animation */


	/* MMD style interpolator. */
	class VMDInterpolator
	{
	private:
		UChar ax, ay, bx, by;
	public:
		/* Partial types of interpolator data */
		enum class PartType { ax, ay, bx, by };
		/* Constructor function */
		VMDInterpolator(UChar ax_ = 20U, UChar ay_ = 20U, UChar bx_ = 107U, UChar by_ = 107U) : ax(ax_), ay(ay_), bx(bx_), by(by_) {}
		/* Sets the value of the interpolator. If the parameter is empty, set the default value. */
		void SetValue(UChar ax_ = 20U, UChar ay_ = 20U, UChar bx_ = 107U, UChar by_ = 107U)
		{
			this->ax = ax_;
			this->ay = ay_;
			this->bx = bx_;
			this->by = by_;
		}
		/* Gets the interpolator value. */
		UChar GetValue(const PartType& part) const
		{
			switch (part)
			{
			case (PartType::ax):
			{
				return this->ax;
			}
			case (PartType::bx):
			{
				return this->bx;
			}
			case (PartType::ay):
			{
				return this->ay;
			}
			case (PartType::by):
			{
				return this->by;
			}
			default:
				return UChar(-1);
			}
		}
		/* Hash function */
		maxon::HashInt GetHashCode() const
		{
			return  MAXON_HASHCODE(this->ax, this->ay, this->bx, this->by);
		}
		/* Read bone interpolator information from a file */
		Bool ReadBoneInterpolator(BaseFile* const file)
		{
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
		/* Read the camera interpolator information from the file. */
		Bool ReadCameraInterpolator(BaseFile* const file)
		{
			UInt32 tmp = 0;
			if (!file->ReadUInt32(&tmp))
				return false;
			this->ax = UChar(((tmp & 0xFF) ^ 0x80) - 0x80);
			this->bx = UChar((((tmp & 0xFF00) >> 8) ^ 0x80) - 0x80);
			this->ay = UChar((((tmp & 0xFF0000) >> 16) ^ 0x80) - 0x80);
			this->by = UChar((((tmp & 0xFF000000) >> 24) ^ 0x80) - 0x80);
			return true;
		}
		/* Write the bone interpolator information to the file. */
		Bool WriteBoneInterpolator(BaseFile* const file) const
		{
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
		/* Write the camera interpolator information to the file. */
		Bool WriteCameraInterpolator(BaseFile* const file) const
		{
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
	/* MMD style bone animation. */
	struct VMD_Motion
	{
		String		bone_name = String();                               /* The action corresponds to the bone name. */
		UInt32		frame_no = 0;                                       /* Frame of action. */
		Vector32	position = Vector32();                              /* The action corresponds to the bone position. */
		Vector4d32	rotation = Vector4d32();                            /* The action corresponds to the rotation of the bone (quad). */
		VMDInterpolator	interpolator_position_x = VMDInterpolator();    /* X-axis displacement action interpolation. */
		VMDInterpolator	interpolator_position_y = VMDInterpolator();    /* Y-axis displacement action interpolation. */
		VMDInterpolator	interpolator_position_z = VMDInterpolator();    /* Z-axis displacement action interpolation. */
		VMDInterpolator	interpolator_position_r = VMDInterpolator();    /* Rotation action interpolation. */
	};
	/* MMD style expression animation. */
	struct VMD_Morph
	{
		String	morph_name = String();                                  /* The action corresponds to the expression name. */
		UInt32	frame_no = 0;                                           /* Frame of action. */
		Float32 weight = 0.f;                                           /* Expression deformation strength. */
	};
	/* MMD风格的摄像机动画 */
	struct VMD_Camera
	{
		UInt32		frame_no = 0;                                       /* Frame of action. */
		Float32		distance = 0.f;                                     /* Camera view distance. */
		Vector32	position = Vector32();                              /* View position of the camera. */
		Vector32	rotation = Vector32();                              /* Camera view rotation (Euler Angle of x and Y reversal) */
		VMDInterpolator	interpolator_position_x = VMDInterpolator();    /* X-axis displacement action interpolation. */
		VMDInterpolator	interpolator_position_y = VMDInterpolator();    /* Y-axis displacement action interpolation. */
		VMDInterpolator	interpolator_position_z = VMDInterpolator();    /* Z-axis displacement action interpolation. */
		VMDInterpolator	interpolator_position_r = VMDInterpolator();    /* Rotation action interpolation. */
		VMDInterpolator	interpolator_position_d = VMDInterpolator();    /* Distance action interpolation. */
		VMDInterpolator	interpolator_position_v = VMDInterpolator();    /* View Angle motion interpolation */
		UInt32		viewing_angle = 0;                                  /* View Angle. */
		UChar		perspective = 0;                                    /* 0:on, 1:off */
	};
	/* MMD style lighting animation */
	struct VMD_Light
	{
		UInt32		frame_no = 0;                                       /* Frame of action. */
		Vector32	rgb = Vector32();                                   /* Light color. */
		Vector32	position = Vector32();                              /* location. */
	};
	/* MMD style shadow animation */
	struct VMD_Shadow
	{
		UInt32	frame_no = 0;                                           /* Frame of action. */
		UChar	shadowType = 0;                                         /* 0:Off 1:mode1 2:mode2 */
		Float32 distance = 0.f;                                         /* Distance. */
	};
	/* MMD style IK enable information */
	struct VMD_IkInfo
	{
		String	name = String();                                        /* IK name. */
		Bool	enable = true;                                          /* Is enable. */
		/* Constructor function */
		VMD_IkInfo(){}
		VMD_IkInfo(const String& name_, Bool enable_ = true) : name(name_), enable(enable_) {}
	};
	/* MMD style model information animation */
	struct VMD_Model
	{
		UInt32				frame_no = 0;                                   /* Frame of action. */
		Bool				show = true;                                       /* Is show. */
		maxon::PointerArray<VMD_IkInfo> IKs_Info;                       /* IKs enable information. */
		/* Constructor function */
		VMD_Model(UInt32 frame_no_ = 0, Bool show_ = true) :frame_no(frame_no_), show(show_) {}
        /* Copy constructor */
		VMD_Model(const mmd::VMD_Model& src)
		{
			if (&src == this)
			{
				return;
			}
			this->frame_no = src.frame_no;
			this->show = src.show;
			this->IKs_Info.CopyFrom(src.IKs_Info) iferr_ignore("err"_s);
		}
		/* operator= */
		mmd::VMD_Model& operator =(const mmd::VMD_Model& src)
		{
			if (&src == this)
			{
				return(*this);
			}
			this->frame_no = src.frame_no;
			this->show = src.show;
			this->IKs_Info.CopyFrom(src.IKs_Info) iferr_ignore("err"_s);
			return(*this);
		}
	};
	/* Morph information struct. */
	struct morph_id_tag
	{
		DescID	id = DescID();                                         /* Morph ID. */
		BaseTag* tag = nullptr;                                        /* Morph tag. */
		String name = String();                                        /* Morph name. */
		/* operator== */
		Bool operator ==(const morph_id_tag& other) const {
			return (this->id == other.id && this->tag == other.tag);
		}
		/* Hash function */
		maxon::HashInt GetHashCode() const
		{
			return  MAXON_HASHCODE(this->id.GetHashCode(), this->tag);
		}
	};
	/* Bone information struct. */
	struct bone_obj_tag
	{
		BaseObject* obj = nullptr;                                     /* Bone object. */
		BaseTag* tag = nullptr;                                        /* Bone tag. */
		/* operator== */
		Bool operator ==(const bone_obj_tag& other) const {
			return (this->obj == other.obj && this->tag == other.tag);
		}
		/* Hash function */
		maxon::HashInt GetHashCode() const
		{
			return  MAXON_HASHCODE(this->obj, this->tag);
		}
	};
	/* MMD model */


	/* PMX model global information struct. */
	struct PMX_Model_information
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
	/* Weight type BDEF1 structure 
	* weight==1 */
	struct BDEF1                                                    
	{
		Int32 bone = 0;                                            /* Bone index. */
	};
	/* Weight type BDEF2 structure
	* Bone 2 weight = 1 - (Bone 1 weight) */
	struct BDEF2                                                    
	{
		Int32	bone[2] = { 0 };                               /* Bone index. */
		Float32 weight = 0.f;                                      /* Bone 1 weight */
	};
	/* Weight type BDEF4 structure 
	* The sum of four weights is not guaranteed to equal 1 */
	struct BDEF4                                                    
	{
		Int32	bone[4] = { 0 };                   /* Bone index. */
		Float32 weight[4] = { 0.f };    /* Bone 1~4 weight */
	};
	/* Weight type SDEF structure
	* Bone 2 weight = 1 - (Bone 1 weight) */
	struct SDEF                                                     
	{
		Int32		bone[2] = { 0 };                             /* Bone index. */
		Float32		weight = 0.f;                                    /* Bone 1 weight */
		Vector32	R0 = Vector32(), R1 = Vector32(), C = Vector32(); /* R0,R1,C */
	};
	/* Weight type QDEF structure
	* The sum of four weights is not guaranteed to equal 1 */
	struct QDEF                                                     
	{
		Int32	bone[4] = { 0 };                /* Bone index. */
		Float32 weight[4] = { 0.f }; /* Bone 1~4 weight */
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
	/* PMX vertex data */
	struct PMX_Vertex_Data                  
	{
		Vector32	position = Vector32();       /* The position. */
		Vector32	normal = Vector32();         /* The normal vector. */
		Vector2d32	UV = Vector2d32();           /* The UV coordinates. */
		/* Skip the extra Vector4d32[N]  16*N */
		Char weight_deform_type = 0;             /* Variant weight type,0=BDEF1, 1=BDEF2, 2=BDEF4, 3=SDEF, 4=QDEF */
		/* Variant weight */
		union
		{
			BDEF1	weight_deform_B1;
			BDEF2	weight_deform_B2;
			BDEF4	weight_deform_B4;
			SDEF	weight_deform_S;
			QDEF	weight_deform_Q;
		};                              
		Float32 edge_scale = 0.f;                /* Edge magnification */
		PMX_Vertex_Data()
		{
		};
	};
	/* Material symbol(1 byte) */
	struct PMX_Material_Flags               
	{
		Bool	no_cull : 1;            /* Double sided depiction */
		Bool	ground_shadow : 1;      /* Cast shadows on geometry */
		Bool	draw_shadow : 1;        /* Render to shadow map（本影标示）*/
		Bool	Receive_shadow : 1;     /* Accept shadows from shadow maps（本影）*/
		Bool	has_edge : 1;           /* Edge depiction（轮廓线有效） */
		Bool	vertex_colour : 1;      /* Use additional vector4d32 as the color of the vertices */
		Bool	point_drawing : 1;      /* All three vertices are drawn */
		Bool	line_drawing : 1;       /* Three sides are drawn */
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
	/* PMX material data */
	struct PMX_Material_Data                                       
	{
		String			material_name_local = String();                 /* Local material name, Japanese, Chinese, etc */
		String			material_name_universal = String();             /* General material name, usually in English */
		Vector4d32		diffuse_colour = Vector4d32(1);                 /* diffuse color RGBA */
		Vector32		specular_colour = Vector32();                   /* Specular (specular) color RGB */
		Float32			specular_strength = 5.f;                        /* Specular light intensity */
		Vector32		ambient_colour = Vector32(1);                   /* Environment color, the shadow color when the light is insufficient (i.e. the base color, which makes the shadow less black) */
		PMX_Material_Flags	drawing_flags = PMX_Material_Flags();       /* Draw marker */
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
		PMX_Material_Data()
		{
		};
		~PMX_Material_Data()
		{
		};
	};
	/* Bone flags(2bytes) */
	struct PMX_Bone_Flags                           
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
		Int32		bone_index = 0;                                /* Bone index */
		Bool		has_limits = 0;                                /* When the value is 1, the angle limit is used */
		Vector32	limit_min = Vector32();                        /* IK angle limit minimum angle (radians) */
		Vector32	limit_max = Vector32();                        /* IK angle limit maximum angle (radians) */
	};
	struct PMX_Bone_Data
	{
		String		bone_name_local = String();                    /* The local name of the skeleton, usually Japanese. */
		String		bone_name_universal = String();                /* The common name of bones is usually English. */
		Vector32	position = Vector32();                         /* Bone position */
		Int32		parent_bone_index = 0;                         /* Bone affinity index, special: the bone affinity of the operation center is - 1 */
		Int32		layer = 0;                                     /* Deformation stratum */
		PMX_Bone_Flags	bone_flags = PMX_Bone_Flags();             /* Bone flags */
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
		Int32	morph_index = 0;                      /* Deformation index */
		Float32 influence = 0.f;                      /* influence */
	};
	struct PMX_Morph_vertex
	{
		UInt32		vertex_index = 0;                 /* Vertex Index  */
		Vector32	translation = Vector32();         /* move */
	};
	struct PMX_Morph_bone
	{
		Int32		bone_index = 0;                   /* Bone index */
		Vector32	translation = Vector32();         /* Relative position of change */
		Vector32	rotation = Vector32();            /* Relative rotation quaternion (revolution Euler) */
	};
	struct PMX_Morph_UV
	{
		Int32		vertex_index = 0;                 /* Vertex Index */
		Vector4d32	floats;                           /* Influence (only x and y are useful, Z and W are 0) */
	};
	struct PMX_Morph_material
	{
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
	struct PMX_Morph_flip
	{
		Int32	morph_index = 0;                      /* Deformation index */
		Float32 influence = 0.;                       /* influence */
	};
	struct PMX_Morph_impulse
	{
		Int32		rigid_body_index = 0;             /* Rigid body index */
		Char		local_flag = 0;                   /* Local flag */
		Vector32	movement_speed = Vector32();      /* Moving speed */
		Vector32	rotation_torque = Vector32();     /* Rotational torque */
	};
	struct PMX_Morph_Data
	{
		String	morph_name_local = String();          /* Local deformation name */
		String	morph_name_universal = String();      /* Generic deformation name */
		Char	panel_type = 0;                       /* Panel position, { 1,2,3,4 }，The position of the expression in the MMD panel */
		/*
		 * Variant type
		 * 0 - 组合（Group）
		 * 1 - 顶点（Vertex）
		 * 2 - 骨骼（Bone）
		 * 3~7 - UV（And expansion UV）
		 * 8 - 材质（Material）
		 * 9 - 切换（Flip）
		 * 10 - 脉冲（Impulse）
		 */
		Char	morph_type = 0;
		Int32	offset_count = 0;                    /* Number of offsets */
		void* offset_data = nullptr;                 /* Offset data */
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
	/* Frame data */
	struct PMX_Frame_data                                                 
	{
		Char	frame_type = 0;                      /* 0: index - bone, 1: index - deformation */
		Int32	frame_data = 0;                      /* Indexes */
	};
	/* Display data */
	struct PMX_Display_Data                                                 
	{
		String	display_name_local = String();       /* Represents a local name */
		String	display_name_universal = String();   /* Indicates the common name of the beam */
		Char	special_flag = 0;                    /* 0 represents normal frame and 1 represents special frame */
		Int32	frame_count = 0;                     /* How many frames are recorded */
		maxon::PointerArray<PMX_Frame_data>	Frames;  /* Frame data */
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
	/* Non collision group mask(2 bytes) */
	struct PMX_Rigid_body_non_collision_group 
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
		String					rigid_body_name_local = String();                                          /* Rigid body local name */
		String					rigid_body_name_universal = String();                                      /* Rigid body common name */
		Int32					related_bone_index = 0;                                                    /* Associative bone index */
		Char					group_id = 0;                                                              /* Group ID */
		PMX_Rigid_body_non_collision_group	non_collision_group = PMX_Rigid_body_non_collision_group();    /* Collision exclusion group */
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
		Float32		mass = 0.;                           /* mass */
		Float32		move_attenuation = 0.;               /* Movement attenuation */
		Float32		rotation_damping = 0.;               /* Rotation attenuation */
		Float32		repulsion_force = 0.;                      /* Reaction force */
		Float32		friction_force = 0.;                 /* friction force */
		/*
		 * Physical mode
		 * 0 - Tracking bones
		 * 1 - Physical calculus
		 * 2 - Physics + bone
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
	struct LocalData : public maxon::ParallelFor::BreakContext
	{
		maxon::Int localCount = 0;
	};
	/* VPD */
	struct VPD_Bone
	{
		String      name = String();
		Vector32	translate = Vector32();
		Vector4d32	rotation = Vector4d32();
	};
	struct VPD_Morph
	{
		String	    name = String();
		Float32		weight = Float32();
	};
	/* Converts Euler rotation to quaternion rotation. */
	extern maxon::Vector4d32 EulerToQuaternion(const maxon::Vector& euler);
	/* Converts quaternion rotation to Euler rotation. */
	extern maxon::Vector QuaternionToEuler(const maxon::Vector4d32& quaternion);
	/*  Converts "SHIFT_JIS" to "UTF-8". */
	extern Bool SJIStoUTF8(char* strin,String& strout, Int64 char_length = -1);
	/*  Converts "UTF-8" to "SHIFT_JIS". */
	extern Bool UTF8toSJIS(const String& strin, char* strout);
}
#endif //__MMD_UTILITY_H__