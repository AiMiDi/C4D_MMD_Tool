#ifndef __MMD_VMD_ANIMATION_H__
#define __MMD_VMD_ANIMATION_H__

#include "main.h"

namespace mmd {

	typedef maxon::Vec3<Float32> vec3;
	typedef maxon::Vec4<Float32> vec4;

	struct VMD_Curve {
		UChar ax, ay, bx, by;
	};

	struct VMD_Motion {
		String bone_name;//动作对应骨骼名称
		UInt32 frame_no;//动作所在帧位置
		vec3 position;//动作对应骨骼位置
		vec4 rotation;//动作对应骨骼旋转(四元)
		VMD_Curve XCurve, YCurve, ZCurve, RCurve;//动作补间曲线
	};

	struct VMD_Morph {
		String morph_name;//动作对应表情名称
		UInt32 frame_no;//动作对应表情所在帧位置
		Float32 weight;//表情变形程度
	};

	struct VMD_Camera {
		UInt32 frame_no;//摄像机动作所在帧位置
		Float32 distance; //摄像机视点距离
		vec3 position;//摄像机视点位置
		vec3 rotation;//摄像机视点旋转(x和y翻转的欧拉角)
		VMD_Curve XCurve, YCurve, ZCurve, RCurve, DCurve, VCurve;//动作补间曲线
		UInt32 viewing_angle;//视野角
		UChar perspective; // 0:on, 1:off
	};

	struct VMD_Light {
		UInt32 frame_no;
		vec3 rgb;
		vec3 position;
	};

	class VMDMotionSortedArray : public maxon::SortedArray<VMDMotionSortedArray, maxon::PointerArray<VMD_Motion>>
	{
	public:
		static Bool LessThan(const VMD_Motion& a, const VMD_Motion& b) { return a.frame_no < b.frame_no; }
		static Bool IsEqual(const VMD_Motion& a, const VMD_Motion& b) { return a.frame_no == b.frame_no; }
	};

	class VMDMorphSortedArray : public maxon::SortedArray<VMDMorphSortedArray, maxon::PointerArray<VMD_Morph>>
	{
	public:
		static Bool LessThan(const VMD_Morph& a, const VMD_Morph& b) { return a.frame_no < b.frame_no; }
		static Bool IsEqual(const VMD_Morph& a, const VMD_Morph& b) { return a.frame_no == b.frame_no; }
	};

	class VMDCameraSortedArray : public maxon::SortedArray<VMDCameraSortedArray, maxon::PointerArray<VMD_Camera>>
	{
	public:
		static Bool LessThan(const VMD_Camera& a, const VMD_Camera& b) { return a.frame_no < b.frame_no; }
		static Bool IsEqual(const VMD_Camera& a, const VMD_Camera& b) { return a.frame_no == b.frame_no; }
	};

	class VMDLightSortedArray : public maxon::SortedArray<VMDLightSortedArray, maxon::PointerArray<VMD_Light>>
	{
	public:
		static Bool LessThan(const VMD_Light& a, const VMD_Light& b) { return a.frame_no < b.frame_no; }
		static Bool IsEqual(const VMD_Light& a, const VMD_Light& b) { return a.frame_no == b.frame_no; }
	};


class VMDAnimation 
{
	private:
		String ModelName;
		Bool IsCamera;
		UInt32 MotionFrameNumber;
		UInt32 MorphFrameNumber;
		UInt32 CameraFrameNumber;
		UInt32 LightFrameNumber;
		VMDMotionSortedArray motion_frames;
		VMDMorphSortedArray morph_frames;
		VMDCameraSortedArray camera_frames;
		VMDLightSortedArray light_frames;
	public:
		VMDAnimation();
		~VMDAnimation();

		maxon::Result<void> LoadFromFile(BaseFile* const file);
		maxon::Result<void> WriteToFile(BaseFile* const file);

		static maxon::Result<void> FromFileImportCamera(Float& PositionMultiple, Float& TimeOffset);
		static maxon::Result<void> FromDocumentExportCamera(Float& PositionMultiple, Float& TimeOffset);
		static maxon::Result<void> FromFileImportMotions(Float& PositionMultiple, Float& TimeOffset, Bool& QuaternionRotationSW, Bool& DetailReport, Bool& ByTag);
};

} // namespace
#endif  __MMD_VMD_ANIMATION_H__