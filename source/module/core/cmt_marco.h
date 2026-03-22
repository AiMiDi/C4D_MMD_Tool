#pragma once

#include <utility>
#include "maxon/synchronized.h"

// maxon::HashInt (apibase.h) exists from R23 / API 23100 onward; alias for older SDKs.
#if API_VERSION < 23100
namespace maxon
{
#ifndef CMT_MAXON_HASHINT_ALIAS
#define CMT_MAXON_HASHINT_ALIAS
using HashInt = UInt;
#endif
}
#endif

// ============================================================================
// Class body macros
// ============================================================================

#ifndef CMT_DISALLOW_COPY_AND_ASSIGN_BODY
//----------------------------------------------------------------------------------------
/// This statement needs to be used at the beginning of any class that cannot be copied.
/// An example:
/// @code
/// class MyClass
/// {
///   CMT_DISALLOW_COPY_AND_ASSIGN_BODY(MyClass);
///   ...
/// };
/// @endcode
//----------------------------------------------------------------------------------------
#define CMT_DISALLOW_COPY_AND_ASSIGN_BODY(TypeName) \
		public:										\
		TypeName(const TypeName&) = delete;			\
		void operator =(const TypeName&) = delete;	\
		private:
#endif

#ifndef CMT_DISALLOW_MOVE_AND_ASSIGN_BODY
//----------------------------------------------------------------------------------------
/// This statement needs to be used at the beginning of any class that cannot be moved.
/// An example:
/// @code
/// class MyClass
/// {
///   CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(MyClass);
///   ...
/// };
/// @endcode
//----------------------------------------------------------------------------------------
#define CMT_DISALLOW_MOVE_AND_ASSIGN_BODY(TypeName) \
		public:										\
		TypeName(TypeName&&) = delete;			\
		void operator =(TypeName&&) = delete;	\
		private:
#endif

#ifndef CMT_DEFAULT_MOVE_BODY
//----------------------------------------------------------------------------------------
/// This statement needs to be used at the beginning of any class that uses the default move function
/// An example:
/// @code
/// class MyClass
/// {
///   CMT_DEFAULT_MOVE_BODY(MyClass);
///   ...
/// };
/// @endcode
//----------------------------------------------------------------------------------------
#define CMT_DEFAULT_MOVE_BODY(TypeName)						 \
		public:												 \
		TypeName(TypeName&&) noexcept = default;			 \
		TypeName& operator =(TypeName&&) noexcept = default; \
		private:
#endif

// ============================================================================
// SDK version constants
// ============================================================================

inline constexpr int kSDKVersion = API_VERSION;
inline constexpr bool kSDK2024 = (API_VERSION >= 2024000);
inline constexpr bool kSDK2026 = (API_VERSION >= 2026000);
/// maxon::ParallelFor::Granularity 与 Dynamic(..., const Granularity&, queue)（约 2024+）；R20–2023 为 (threadCnt, Int granularity)。
#define CMT_SDK_HAS_PARALLELFOR_GRANULARITY_STRUCT (API_VERSION >= 2024000)
/// ID_BASELIST_ICON_COLORIZE* 等（S21 / API 21000 起）；预处理器与运行时常量共用同一阈值。
#define CMT_SDK_HAS_ICON_COLORIZE (API_VERSION >= 21000)
inline constexpr bool kSDKHasIconColorize = bool(CMT_SDK_HAS_ICON_COLORIZE);
/// CAWeightTag::SetBindPose（旧版用 MSG_DESCRIPTION_COMMAND + ID_CA_WEIGHT_TAG_SET）
#define CMT_SDK_HAS_WEIGHT_TAG_SETBINDPOSE (API_VERSION >= 21000)
/// CommandData::Execute(BaseDocument*, GeDialog* parentManager) 重载
#define CMT_SDK_HAS_COMMANDDATA_EXECUTE_WITH_PARENT (API_VERSION >= 21000)
/// R20 链接需补全局 ToString(const String&,...)；R21+ 不需要
#define CMT_SDK_NEEDS_GLOBAL_TOSTRING_STRING_LINK (API_VERSION < 21000)
inline constexpr bool kSDKHasCinemaNamespace = (API_VERSION >= 2024900);

// R21(API 21200) 起提供 c4d_customgui/customgui_iconchooser.h；R20 无此头文件。
// 与依赖该头的 FillCustomIconSettingsFromBaseList2D / GetCustomIcon 等代码同条件使用。
#define CMT_SDK_HAS_CUSTOMGUI_ICONCHOOSER_HEADER (API_VERSION >= 21200)

// RadToDeg：R24 前由 c4d.h → ge_sys_math 提供全局 ::RadToDeg；R24+ 用 maxon/apibase.h + maxon/utilities/apibasemath.h
// 得到 maxon::RadToDeg（勿用不存在的 maxon/apibasemath.h）。使用 CMT_RAD_TO_DEG 的 .cpp 须先包含 c4d.h。
#if API_VERSION >= 2024000
#ifndef CMT_MAXON_APIBASEMATH_FOR_RAD_INCLUDED
#define CMT_MAXON_APIBASEMATH_FOR_RAD_INCLUDED
#include <maxon/apibase.h>
#include <maxon/utilities/apibasemath.h>
#endif
#ifndef CMT_RAD_TO_DEG
#define CMT_RAD_TO_DEG(R) (maxon::RadToDeg(R))
#endif
#else
#ifndef CMT_RAD_TO_DEG
#define CMT_RAD_TO_DEG(R) (::RadToDeg(R))
#endif
#endif

// MSVC 19.44+ 对 constexpr Vector 数组更严格，统一用 static const 避免 C2131。
#define CMT_STATIC_BONE_REFRESH_COLORS static const

// ============================================================================
// Function signature compatibility macros
// These macros modify virtual function override signatures and CANNOT be
// replaced by inline functions or templates.
// ============================================================================

// --- Const/ConstExpr qualifiers (still needed for non-signature uses) ---

#if API_VERSION < 2024000
#   define SDK2024_Const
#   define SDK2024_ConstExpr
#   ifndef ConstDescID
#       define ConstDescID(...) DescID(__VA_ARGS__)
#       define CreateDescID(...) DescID(__VA_ARGS__)
#   endif
#else
#   define SDK2024_Const const
#   define SDK2024_ConstExpr constexpr
#endif

// --- NodeData::GetDParameter ---

#if API_VERSION < 2024000
#   define SDK2024_GetDParameter(x) Bool x::GetDParameter(GeListNode* node, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags)
#   define SDK2024_GetDParameterOverride Bool GetDParameter(GeListNode* node, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags) override
#else
#   define SDK2024_GetDParameter(x) Bool x::GetDParameter(const GeListNode* node, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags) const
#   define SDK2024_GetDParameterOverride Bool GetDParameter(const GeListNode* node, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags) const override
#endif

// --- NodeData::Init ---

#if API_VERSION < 2024000
#   define SDK2024_SuperInit SUPER::Init(node)
#   define SDK2024_Init(x) Bool x::Init(GeListNode* node)
#   define SDK2024_InitOverride Bool Init(GeListNode* node) override
#else
#   define SDK2024_SuperInit SUPER::Init(node, isCloneInit)
#   define SDK2024_Init(x) Bool x::Init(GeListNode* node, Bool isCloneInit)
#   define SDK2024_InitOverride Bool Init(GeListNode* node, Bool isCloneInit) override
#endif

// --- NodeData::Write ---

#if API_VERSION < 2024000
#   define SDK2024_Write(x) Bool x::Write(GeListNode* node, HyperFile* hf)
#   define SDK2024_WriteOverride Bool Write(GeListNode* node, HyperFile* hf) override
#else
#   define SDK2024_Write(x) Bool x::Write(const GeListNode* node, HyperFile* hf) const
#   define SDK2024_WriteOverride Bool Write(const GeListNode* node, HyperFile* hf) const override
#endif

// --- NodeData::CopyTo ---

#if API_VERSION < 2024000
#   define SDK2024_CopyTo(x) Bool x::CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn)
#   define SDK2024_CopyToOverride Bool CopyTo(NodeData* dest, GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) override
#else
#   define SDK2024_CopyTo(x) Bool x::CopyTo(NodeData* dest, const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) const
#   define SDK2024_CopyToOverride Bool CopyTo(NodeData* dest, const GeListNode* snode, GeListNode* dnode, COPYFLAGS flags, AliasTrans* trn) const override
#endif

// --- NodeData::GetDDescription ---

#if API_VERSION < 2024000
#   define SDK2024_GetDDescription(x) Bool x::GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags)
#   define SDK2024_GetDDescriptionOverride Bool GetDDescription(GeListNode* node, Description* description, DESCFLAGS_DESC& flags) override
#else
#   define SDK2024_GetDDescription(x) Bool x::GetDDescription(const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) const
#   define SDK2024_GetDDescriptionOverride Bool GetDDescription(const GeListNode* node, Description* description, DESCFLAGS_DESC& flags) const override
#endif

// --- NodeData::GetDEnabling ---

#if API_VERSION < 2024000
#   define SDK2024_GetDEnabling(x) Bool x::GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc)
#   define SDK2024_GetDEnablingOverride Bool GetDEnabling(GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) override
#else
#   define SDK2024_GetDEnabling(x) Bool x::GetDEnabling(const GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) const
#   define SDK2024_GetDEnablingOverride Bool GetDEnabling(const GeListNode* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc) const override
#endif

// ============================================================================
// API name remapping macros
// These macros handle member function renames between SDK versions and
// CANNOT be replaced by using-declarations or inline functions.
// ============================================================================

#if API_VERSION < 2024000
#   define GetDynamicDescriptionWritable GetDynamicDescription
#   define GetWritableBaseSelect GetBaseSelect
#endif

// ============================================================================
// Syntax compatibility macros
// These macros handle chain-call and move-semantics differences and
// CANNOT be replaced by inline functions.
// ============================================================================

#if API_VERSION < 2024000
#   define SDK2024_Append(...) Append({__VA_ARGS__})
#   define SDK2024_Move(x) x
#else
#   define SDK2024_Append(...) Append(__VA_ARGS__)
#   define SDK2024_Move(x) std::move(x)
#endif

// ============================================================================
// Namespace compatibility
// ============================================================================

#if API_VERSION >= 2024900
#   define CINEMA_NAMESPACE cinema::
    using namespace cinema;
#else
#   define CINEMA_NAMESPACE
#endif

// ============================================================================
// Type-safe inline compatibility functions
// These replace function-like macros with proper type-checked functions.
// ============================================================================

/// Creates an ObjectColorProperties with the correct argument order for the current SDK version.
/// In SDK < 2024, the order is {usecolor, color, xray}; in SDK >= 2024, it is {color, usecolor, xray}.
inline ObjectColorProperties MakeObjectColorProperties(
    const Vector& color, Int32 usecolor, Bool xray)
{
#if API_VERSION < 2024000
    return ObjectColorProperties{usecolor, color, xray};
#else
    return ObjectColorProperties{color, usecolor, xray};
#endif
}

/// Creates a GeData wrapping a DescID, using the correct constructor for the current SDK version.
/// In SDK < 2024, GeData requires CUSTOMDATATYPE_DESCID as the first argument; in SDK >= 2024, it does not.
inline GeData MakeDescIDGeData(const DescID& id)
{
#if API_VERSION < 2024000
    return GeData{CUSTOMDATATYPE_DESCID, id};
#else
    return GeData{id};
#endif
}

/// Gets a const custom data type from a BaseContainer by parameter ID.
/// In SDK < 2024, uses GetCustomDataType(id, datatypeId); in SDK >= 2024, uses GetCustomDataType<T>(id).
template<typename T>
inline const T* GetContainerCustomDataType(const BaseContainer& bc, Int32 id, [[maybe_unused]] Int32 datatypeId)
{
#if API_VERSION < 2024000
    return static_cast<const T*>(bc.GetCustomDataType(id, datatypeId));
#else
    return bc.GetCustomDataType<T>(id);
#endif
}

/// Gets a writable custom data type pointer from GeData, using the correct API for the current SDK version.
/// @tparam T The custom data type to retrieve (e.g. PriorityData).
/// @param data The GeData instance to extract from.
/// @param customDataTypeId The custom data type identifier (used only in SDK < 2024).
template<typename T>
inline T* GetCustomDataTypeWritable(GeData& data, [[maybe_unused]] Int32 customDataTypeId)
{
#if API_VERSION < 2024000
    return reinterpret_cast<T*>(data.GetCustomDataType(customDataTypeId));
#else
    return data.GetCustomDataTypeWritable<T>();
#endif
}

template<typename T>
inline Bool GetAtomParameter(const T* atom, const DescID& id, GeData& data, DESCFLAGS_GET flags)
{
	if (!atom)
		return false;
#if API_VERSION < 2024000
	return const_cast<T*>(atom)->GetParameter(id, data, flags);
#else
	return atom->GetParameter(id, data, flags);
#endif
}


// ============================================================================
// Model type aliases
// ============================================================================

#include "libMMD/Model/MMD/PMXModel.h"
#include "libMMD/Model/MMD/PMDModel.h"
using MMDModel = libmmd::MMDModel;
using PMXModel = libmmd::PMXModel;
using PMDModel = libmmd::PMDModel;
#include <memory>
using MMDModelPtr = std::shared_ptr<MMDModel>;
using PMXModelPtr = std::shared_ptr<PMXModel>;
using PMDModelPtr = std::shared_ptr<PMDModel>;
