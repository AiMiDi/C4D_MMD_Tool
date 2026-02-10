#pragma once

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
inline constexpr bool kSDKHasIconColorize = (API_VERSION >= 21000);
inline constexpr bool kSDKHasCinemaNamespace = (API_VERSION >= 2024900);

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
#   define SDK2024_ToPointer
#   define SDK2024_Append(...) Append({__VA_ARGS__})
#   define SDK2024_Move(x) x
#else
#   define SDK2024_ToPointer .ToPointer()
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
