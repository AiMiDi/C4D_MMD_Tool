#ifndef CMT_MARCO_H__
#define CMT_MARCO_H__

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
#ifndef CMT_DISALLOW_MOVE_AND_ASSIGN_BODY
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

#if API_VERSION < 2024000

#   define SDK2024_Const
#   define SDK2024_NotConst const

#	define SDK2024_InitPara
#	define SDK2024_InitParaName
#	define DescIDGeData(id) GeData{ CUSTOMDATATYPE_DESCID, id }

#   ifndef ConstDescID
#       define ConstDescID(...) DescID(__VA_ARGS__)
#       define CreateDescID(...) DescID(__VA_ARGS__)
#   endif

#	define DataGetCustomDataType(data, type, id) reinterpret_cast<type*>(data.GetCustomDataType(id))
#	define GetDynamicDescriptionWritable GetDynamicDescription
#	define MakeObjectColorProperties(color, usecolor, xray) ObjectColorProperties{usecolor, color, xray}

#else

#   define SDK2024_Const const
#   define SDK2024_NotConst

#	define SDK2024_InitPara , isCloneInit
#   define SDK2024_InitParaName ,Bool isCloneInit
#	define DescIDGeData(id) GeData{ id }

#	define DataGetCustomDataType(data, type, id) data.GetCustomDataTypeWritable<type>()
#	define MakeObjectColorProperties(color, usecolor, xray) ObjectColorProperties{color, usecolor, xray}

#endif

#endif // !CMT_MARCO_H__
