#ifndef __MMD_UTILITY_H__
#define __MMD_UTILITY_H__

#include "main.h"

namespace mmd {
	/* Converts Euler rotation to quaternion rotation. */
	extern maxon::Vector4d32 EulerToQuaternion(const maxon::Vector& euler);
	/* Converts quaternion rotation to Euler rotation. */
	extern maxon::Vector QuaternionToEuler(const maxon::Vector4d32& quaternion);
	/*  Converts "SHIFT_JIS" to "UTF-8". */
	extern Bool SJIStoUTF8(char* strin, String& strout, Int64 char_length = -1);
	/*  Converts "UTF-8" to "SHIFT_JIS". */
	extern Bool UTF8toSJIS(const String& strin, char* strout);

	extern Bool ReadPMXText(BaseFile* const file, const Char& text_encoding, String& out_string);
	extern Int32 ReadPMXIndex(BaseFile* const file, const Char& index_size);
	extern UInt32 ReadPMXUIndex(BaseFile* const file, const Char& index_size);

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
	struct VMDBoneAnimation
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
	struct VMDMorphAnimation
	{
		String	morph_name = String();                                  /* The action corresponds to the expression name. */
		UInt32	frame_no = 0;                                           /* Frame of action. */
		Float32 weight = 0.f;                                           /* Expression deformation strength. */
	};
	/* MMD风格的摄像机动画 */
	struct VMDCameraAnimation
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
	struct VMDLightAnimation
	{
		UInt32		frame_no = 0;                                       /* Frame of action. */
		Vector32	rgb = Vector32();                                   /* Light color. */
		Vector32	position = Vector32();                              /* location. */
	};
	/* MMD style shadow animation */
	struct VMDShadowAnimation
	{
		UInt32	frame_no = 0;                                           /* Frame of action. */
		UChar	shadowType = 0;                                         /* 0:Off 1:mode1 2:mode2 */
		Float32 distance = 0.f;                                         /* Distance. */
	};
	/* MMD style IK enable information */
	struct VMDIkControllerAnimation
	{
		String	name = String();                                        /* IK name. */
		Bool	enable = true;                                          /* Is enable. */
		/* Constructor function */
		VMDIkControllerAnimation(){}
		VMDIkControllerAnimation(const String& name_, Bool enable_ = true) : name(name_), enable(enable_) {}
	};
	/* MMD style model information animation */
	struct VMDModelControllerAnimation
	{
		UInt32				frame_no = 0;                                   /* Frame of action. */
		Bool				show = true;                                       /* Is show. */
		maxon::PointerArray<VMDIkControllerAnimation> IKs_Info;                       /* IKs enable information. */
		/* Constructor function */
		VMDModelControllerAnimation(UInt32 frame_no_ = 0, Bool show_ = true) :frame_no(frame_no_), show(show_) {}
        /* Copy constructor */
		VMDModelControllerAnimation(const mmd::VMDModelControllerAnimation& src)
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
		VMDModelControllerAnimation& operator =(const mmd::VMDModelControllerAnimation& src)
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
		virtual ~PMXWeight() {}
		virtual void Free(PMXWeight* m) {
			DeleteObj(m);
		}
		//virtual Bool ReadFromFile(BaseFile* file) = 0;
	};
	/* Weight type BDEF1 structure 
	* weight==1 */
	class PMXWeight_BDEF1 : public PMXWeight
	{
	public:
		~PMXWeight_BDEF1(){}
		static maxon::Result<PMXWeight_BDEF1*> Alloc()
		{
			iferr_scope;
			PMXWeight_BDEF1* res = NewObj(PMXWeight_BDEF1) iferr_return;
			if (res == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
			}
			return res;
		}
		Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) {
			this->bone = ReadPMXIndex(file, bone_index_size);
			return true;
		}
		Int32 bone = 0;                                            /* Bone index. */
	};
	/* Weight type BDEF2 structure
	* Bone 2 weight = 1 - (Bone 1 weight) */
	class PMXWeight_BDEF2 : public PMXWeight
	{
	public:
		~PMXWeight_BDEF2(){}
		static maxon::Result<PMXWeight_BDEF2*> Alloc()
		{
			iferr_scope;
			PMXWeight_BDEF2* res = NewObj(PMXWeight_BDEF2) iferr_return;
			if (res == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
			}
			return res;
		}
		Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) {
			this->bone[0] = ReadPMXIndex(file, bone_index_size);
			this->bone[1] = ReadPMXIndex(file, bone_index_size);
			if (!file->ReadFloat32(&(this->weight)))
				return false;
			return true;
		}
		Int32	bone[2] = { 0 };                               /* Bone index. */
		Float32 weight = 0.f;                                      /* Bone 1 weight */
	};
	/* Weight type BDEF4 structure 
	* The sum of four weights is not guaranteed to equal 1 */
	class PMXWeight_BDEF4 : public PMXWeight
	{
	public:
		~PMXWeight_BDEF4(){}
		static maxon::Result<PMXWeight_BDEF4*> Alloc()
		{
			iferr_scope;
			PMXWeight_BDEF4* res = NewObj(PMXWeight_BDEF4) iferr_return;
			if (res == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
			}
			return res;
		}
		Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) {
			this->bone[0] = ReadPMXIndex(file, bone_index_size);
			this->bone[1] = ReadPMXIndex(file, bone_index_size);
			this->bone[2] = ReadPMXIndex(file, bone_index_size);
			this->bone[3] = ReadPMXIndex(file, bone_index_size);
			if (!file->ReadFloat32(&(this->weight[0])))
				return false;
			if (!file->ReadFloat32(&(this->weight[1])))
				return false;
			if (!file->ReadFloat32(&(this->weight[2])))
				return false;
			if (!file->ReadFloat32(&(this->weight[3])))
				return false;
			return true;
		}
		Int32	bone[4] = { 0 };                   /* Bone index. */
		Float32 weight[4] = { 0.f };    /* Bone 1~4 weight */
	};
	/* Weight type SDEF structure
	* Bone 2 weight = 1 - (Bone 1 weight) */
	class PMXWeight_SDEF : public PMXWeight
	{
	public:
		~PMXWeight_SDEF(){}
		static maxon::Result<PMXWeight_SDEF*> Alloc()
		{
			iferr_scope;
			PMXWeight_SDEF* res = NewObj(PMXWeight_SDEF) iferr_return;
			if (res == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
			}
			return res;
		}
		Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) {
			this->bone[0] = ReadPMXIndex(file, bone_index_size);
			this->bone[1] = ReadPMXIndex(file, bone_index_size);
			if (!file->ReadFloat32(&(this->weight)))
				return false;
			if (!file->ReadVector32(&(this->R0)))
				return false;
			if (!file->ReadVector32(&(this->R1)))
				return false;
			if (!file->ReadVector32(&(this->C)))
				return false;
			return true;
		}
		Int32		bone[2] = { 0 };                             /* Bone index. */
		Float32		weight = 0.f;                                    /* Bone 1 weight */
		Vector32	R0 = Vector32(), R1 = Vector32(), C = Vector32(); /* R0,R1,C */
	};
	/* Weight type QDEF structure
	* The sum of four weights is not guaranteed to equal 1 */
	class PMXWeight_QDEF : public PMXWeight
	{
	public:
		~PMXWeight_QDEF() {}
		static maxon::Result<PMXWeight_QDEF*> Alloc()
		{
			iferr_scope;
			PMXWeight_QDEF* res = NewObj(PMXWeight_QDEF) iferr_return;
			if (res == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
			}
			return res;
		}
		Bool ReadFromFile(BaseFile* file, const Char& bone_index_size) {
			this->bone[0] = ReadPMXIndex(file, bone_index_size);
			this->bone[1] = ReadPMXIndex(file, bone_index_size);
			this->bone[2] = ReadPMXIndex(file, bone_index_size);
			this->bone[3] = ReadPMXIndex(file, bone_index_size);
			if (!file->ReadFloat32(&(this->weight[0])))
				return false;
			if (!file->ReadFloat32(&(this->weight[1])))
				return false;
			if (!file->ReadFloat32(&(this->weight[2])))
				return false;
			if (!file->ReadFloat32(&(this->weight[3])))
				return false;
			return true;
		}
		Int32	bone[4] = { 0 };                /* Bone index. */
		Float32 weight[4] = { 0.f }; /* Bone 1~4 weight */
	};
	struct PMXDataCount
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
	struct PMXVertexData
	{
		Vector32	position = Vector32();       /* The position. */
		Vector32	normal = Vector32();         /* The normal vector. */
		Vector2d32	UV = Vector2d32();           /* The UV coordinates. */
		/* Skip the extra Vector4d32[N]  16*N */
		Char weight_deform_type = 0;             /* Variant weight type,0=BDEF1, 1=BDEF2, 2=BDEF4, 3=SDEF, 4=QDEF */
		/* Variant weight */
		PMXWeight* weight_deform;
		Float32 edge_scale = 0.f;                /* Edge magnification */
		PMXVertexData() {}
		~PMXVertexData() {
			if (weight_deform != nullptr) {
				weight_deform->Free(weight_deform);
			}
		}
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
		PMXMaterialFlags()
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
		PMXMaterialData()
		{
		};
		~PMXMaterialData()
		{
		};
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
		PMXBoneFlags()
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
		PMXBoneData()
		{
		};
		PMXBoneData(const PMXBoneData& src)
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


		mmd::PMXBoneData& operator =(const mmd::PMXBoneData& src)
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
	class PMXMorph {
	public:
		virtual ~PMXMorph(){}
		virtual void Free(PMXMorph* m){
			DeleteObj(m);
		}
		virtual Bool ReadFromFile(BaseFile* file, const Char& index_size) = 0;
	};
	class PMXMorph_Group : public PMXMorph
	{
	public:
		~PMXMorph_Group(){}
		static maxon::Result<PMXMorph_Group*> Alloc()
		{
			iferr_scope;
			PMXMorph_Group* res = NewObj(PMXMorph_Group) iferr_return;
			if (res == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
			}
			return res;
		}
		// index_size is morph index size.
		Bool ReadFromFile(BaseFile* file,const Char& index_size) {
			this->morph_index = ReadPMXIndex(file, index_size);
			if (!file->ReadFloat32(&(this->influence)))
				return false;
			return true;
		}
		Int32	morph_index = 0;                      /* Deformation index */
		Float32 influence = 0.f;                      /* influence */
	};
	class PMXMorph_Vertex : public PMXMorph
	{
	public:
		~PMXMorph_Vertex(){}
		static maxon::Result<PMXMorph_Vertex*> Alloc()
		{
			iferr_scope;
			PMXMorph_Vertex* res = NewObj(PMXMorph_Vertex) iferr_return;
			if (res == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
			}
			return res;
		}
		// index_size is vertex index size.
		Bool ReadFromFile(BaseFile* file, const Char& index_size) {
			this->vertex_index = ReadPMXUIndex(file, index_size);
			if (!file->ReadVector32(&(this->translation)))
				return false;
			return true;
		}
		UInt32		vertex_index = 0;                 /* Vertex Index  */
		Vector32	translation = Vector32();         /* move */
	};
	class PMXMorph_Bone : public PMXMorph
	{
	public:
		~PMXMorph_Bone(){}
		static maxon::Result<PMXMorph_Bone*> Alloc()
		{
			iferr_scope;
			PMXMorph_Bone* res = NewObj(PMXMorph_Bone) iferr_return;
			if (res == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
			}
			return res;
		}
		// index_size is bone index size.
		Bool ReadFromFile(BaseFile* file, const Char& index_size) {
			this->bone_index = ReadPMXIndex(file, index_size);
			if (!file->ReadVector32(&(this->translation)))
				return false;
			Vector4d32 q_rotation;
			if (!file->ReadBytes(&q_rotation, sizeof(Vector4d32)))
				return false;	
			this->rotation = (Vector32)QuaternionToEuler(q_rotation);
			return true;
		}
		Int32		bone_index = 0;                   /* Bone index */
		Vector32	translation = Vector32();         /* Relative position of change */
		Vector32	rotation = Vector32();            /* Relative rotation quaternion (revolution Euler) */
	};
	class PMXMorph_UV : public PMXMorph
	{
	public:
		~PMXMorph_UV(){}
		static maxon::Result<PMXMorph_UV*> Alloc()
		{
			iferr_scope;
			PMXMorph_UV* res = NewObj(PMXMorph_UV) iferr_return;
			if (res == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
			}
			return res;
		}
		// index_size is vertex index size.
		Bool ReadFromFile(BaseFile* file, const Char& index_size) {
			this->vertex_index = ReadPMXIndex(file, index_size);
			if (!file->ReadBytes(&(this->floats), sizeof(Vector4d32)))
				return false;
			return true;
		}
		Int32		vertex_index = 0;                 /* Vertex Index */
		Vector4d32	floats;                           /* Influence (only x and y are useful, Z and W are 0) */
	};
	class PMXMorph_Material : public PMXMorph
	{
	public:
		~PMXMorph_Material(){}
		static maxon::Result<PMXMorph_Material*> Alloc()
		{
			iferr_scope;
			PMXMorph_Material* res = NewObj(PMXMorph_Material) iferr_return;
			if (res == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
			}
			return res;
		}
		// index_size is material index size.
		Bool ReadFromFile(BaseFile* file, const Char& index_size) {
			this->material_index = ReadPMXIndex(file, index_size);
			if (!file->ReadChar(&(this->blend_mode)))
				return false;
			if (!file->ReadBytes(&(this->diffuse), sizeof(Vector4d32)))
				return false;
			if (!file->ReadVector32(&(this->specular)))
				return false;
			if (!file->ReadFloat32(&(this->specularity)))
				return false;
			if (!file->ReadVector32(&(this->ambient)))
				return false;
			if (!file->ReadBytes(&(this->edge_colour), sizeof(Vector4d32)))
				return false;
			if (!file->ReadFloat32(&(this->edge_size)))
				return false;
			if (!file->ReadBytes(&(this->texture_tint), sizeof(Vector4d32)))
				return false;
			if (!file->ReadBytes(&(this->environment_tint), sizeof(Vector4d32)))
				return false;
			if (!file->ReadBytes(&(this->toon_tint), sizeof(Vector4d32)))
				return false;
			return true;
		}
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
	class PMXMorph_Flip : public PMXMorph
	{
	public:
		~PMXMorph_Flip(){}
		static maxon::Result<PMXMorph_Flip*> Alloc()
		{
			iferr_scope;
			PMXMorph_Flip* res = NewObj(PMXMorph_Flip) iferr_return;
			if (res == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
			}
			return res;
		}
		// index_size is morph index size.
		Bool ReadFromFile(BaseFile* file, const Char& index_size) {
			this->morph_index = ReadPMXIndex(file, index_size);
			if (!file->ReadFloat32(&(this->influence)))
				return false;
			return true;
		}
		Int32	morph_index = 0;                      /* Deformation index */
		Float32 influence = 0.f;                       /* influence */
	};
	class PMXMorph_Impulse : public PMXMorph
	{
	public:
		~PMXMorph_Impulse(){}
		static maxon::Result<PMXMorph_Impulse*> Alloc()
		{
			iferr_scope;
			PMXMorph_Impulse* res = NewObj(PMXMorph_Impulse) iferr_return;
			if (res == nullptr)
			{
				GePrint(GeLoadString(IDS_MES_MEM_ERR));
				MessageDialog(GeLoadString(IDS_MES_MEM_ERR));
				return(maxon::OutOfMemoryError(MAXON_SOURCE_LOCATION, GeLoadString(IDS_MES_MEM_ERR)));
			}
			return res;
		}
		// index_size is rigidbody index size.
		Bool ReadFromFile(BaseFile* file, const Char& index_size) {
			this->rigid_body_index = ReadPMXIndex(file, index_size);
			if (!file->ReadChar(&(this->local_flag)))
				return false;
			if (!file->ReadVector32(&(this->movement_speed)))
				return false;
			if (!file->ReadVector32(&(this->rotation_torque)))
				return false;
			return true;
		}
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
		maxon::BaseArray<PMXMorph*> offset_data;                 /* Offset data */
		~PMXMorphData()
		{
			for (auto* data : offset_data)
			{
				if (data != nullptr)
					data->Free(data);
			}
		};
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
		PMXDisplayData()
		{
		}

		PMXDisplayData(const PMXDisplayData& src)
		{
			this->display_name_local = src.display_name_local;
			this->display_name_universal = src.display_name_universal;
			this->special_flag = src.special_flag;
			this->frame_count = src.frame_count;
			this->Frames.CopyFrom(src.Frames) iferr_ignore("err"_s);
		}
	};
	/* Non collision group mask(2 bytes) */
	struct PMXRigidBodyNonCollisionGroup 
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

		PMXRigidBodyNonCollisionGroup(
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
		PMXRigidBodyData()
		{
		}
		~PMXRigidBodyData()
		{
		}
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
	struct LocalData : public maxon::ParallelFor::BreakContext
	{
		maxon::Int localCount = 0;
	};
	/* VPD */
	struct VPDBoneData
	{
		String      name = String();
		Vector32	translate = Vector32();
		Vector4d32	rotation = Vector4d32();
	};
	struct VPDMorphData
	{
		String	    name = String();
		Float32		weight = Float32();
	};
}
#endif //__MMD_UTILITY_H__