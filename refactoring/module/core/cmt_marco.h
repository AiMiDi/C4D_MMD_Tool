#pragma once

#ifndef CMT_DISALLOW_COPY_AND_ASSIGN_BODY
//----------------------------------------------------------------------------------------
/// This statement needs to be used at the beginning of any class that cannot be copied
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

#ifndef GENERATE_MMD_CLASS_BODY
//----------------------------------------------------------------------------------------
/// This statement needs to be used at the beginning of any class that uses the MMD data interface
/// An example:
/// @code
/// class MMDClass
/// {
///   GENERATE_MMD_CLASS_BODY(MyClass);
///   ...
/// };
/// @endcode
//----------------------------------------------------------------------------------------
#define	GENERATE_MMD_CLASS_BODY(CLASSTYPE, DATATYPE)				\
	CMT_DISALLOW_COPY_AND_ASSIGN_BODY(CLASSTYPE) 					\
	CMT_DEFAULT_MOVE_BODY(CLASSTYPE)								\
	public:															\
	using data_type = DATATYPE;										\
	[[nodiscard]] const std::unique_ptr<data_type>& GetData() const	\
	{																\
		return m_data;												\
	}																\
	private:														\
	std::unique_ptr<data_type> m_data;
#endif

