#if 1
namespace maxon
{
	namespace enum132 { enum class ROTATIONORDER
	{
		ZXYGLOBAL	=	0,
		ZYXGLOBAL	=	1,
		YXZGLOBAL	=	2,
		YZXGLOBAL	=	3,
		XZYGLOBAL	=	4,
		XYZGLOBAL	=	5,
	
		YXZLOCAL	= 0,
		XYZLOCAL	= 1,
		ZXYLOCAL	= 2,
		XZYLOCAL	= 3,
		YZXLOCAL	= 4,
		ZYXLOCAL	= 5,
	} ; }
	maxon::String PrivateToString_ROTATIONORDER132(std::underlying_type<enum132::ROTATIONORDER>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum132::ROTATIONORDER::ZXYGLOBAL, (maxon::UInt64) enum132::ROTATIONORDER::ZYXGLOBAL, (maxon::UInt64) enum132::ROTATIONORDER::YXZGLOBAL, (maxon::UInt64) enum132::ROTATIONORDER::YZXGLOBAL, (maxon::UInt64) enum132::ROTATIONORDER::XZYGLOBAL, (maxon::UInt64) enum132::ROTATIONORDER::XYZGLOBAL, (maxon::UInt64) enum132::ROTATIONORDER::YXZLOCAL, (maxon::UInt64) enum132::ROTATIONORDER::XYZLOCAL, (maxon::UInt64) enum132::ROTATIONORDER::ZXYLOCAL, (maxon::UInt64) enum132::ROTATIONORDER::XZYLOCAL, (maxon::UInt64) enum132::ROTATIONORDER::YZXLOCAL, (maxon::UInt64) enum132::ROTATIONORDER::ZYXLOCAL};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "ROTATIONORDER", SIZEOF(x), false, values, "ZXYGLOBAL\0ZYXGLOBAL\0YXZGLOBAL\0YZXGLOBAL\0XZYGLOBAL\0XYZGLOBAL\0YXZLOCAL\0XYZLOCAL\0ZXYLOCAL\0XZYLOCAL\0YZXLOCAL\0ZYXLOCAL\0", fmt);
	}
#ifdef MAXON_TARGET_SINGLEPRECISION
#else
#endif
}
#endif
