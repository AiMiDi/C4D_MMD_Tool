#ifndef _PMX_BONE_TAG_H_
#define _PMX_BONE_TAG_H_
enum
{
	PMX_BONE_INFO_GRP = 5000,
	BONE_NAME_LOCAL,//骨骼本地名称
	BONE_NAME_UNIVERSAL,//骨骼通用名称
	POSITION,//位置

	PMX_BONE_PARENT_BONE_GRP,//亲骨组
	PARENT_BONE_INDEX,//亲骨索引
	PARENT_BONE_LINK,//亲骨

	PMX_BONE_FLAG_GRP,//骨骼特征组
	ROTATABLE,//启用旋转
	TRANSLATABLE,//启用移动
	VISIBLE,//启用显示
	ENABLED,//启用操作
	IS_IK,//启用IK骨

	PMX_BONE_DEFORM_LAYER_GRP,//变形阶层组
	LAYER,//变形阶层
	PHYSICS_AFTER_DEFORM,//先变形，后算物理

	PMX_BONE_END_OF_BONE_GRP,//骨骼末端
	INDEXED_TAIL_POSITION,//骨骼尾部(尖端)位置
	TAIL_INDEX,//子骨骼索引
	TAIL_POSITION,//相对位置
	TAIL_IS_INDEX = 0,//是连接子骨骼
	TAIL_IS_POSITION = 1//是连接相对位置
};
#endif _PMX_BONE_TAG_H_
