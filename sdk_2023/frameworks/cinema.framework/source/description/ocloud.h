#ifndef OCLOUD_H__
#define OCLOUD_H__

enum
{
	SKY_CLOUD_MIX       = 2000, // real

	SKY_CLOUD_GENERATOR_FLAG  = 906, // bool
	SKY_CLOUD_OVERRIDE_GROUP  = 2002, // bool
	SKY_CLOUD_FALLOFF         = 2003, // real
	SKY_CLOUD_LUM_FALLOFF     = 2004, // real
	SKY_CLOUD_COLOR           = 2005, // vector
	SKY_CLOUD_TRANS_FALLOFF   = 2006, // real
	SKY_CLOUD_ALTITUDE        = 2007, // real
	SKY_CLOUD_HQ_LIGHTING     = 2011, // bool
	SKY_CLOUD_OBJECT_FALLOFF  = 2008, // spline
	SKY_CLOUD_OFFSET_DIST     = 2009, // distance
	SKY_CLOUD_KEEP_SHAPE      = 2010, // bool
	SKY_CLOUD_TYPE            = 2012, // long
		SKY_CLOUD_TYPE_STANDARD = 0,
		SKY_CLOUD_TYPE_ACPERL   = 1,
		SKY_CLOUD_TYPE_ACLENTI  = 2,
		SKY_CLOUD_TYPE_CBCAPINC = 3,
	SKY_CLOUD_COVERAGE        = 2013, // real
	SKY_CLOUD_CONTRAST        = 2014, // real
	SKY_CLOUD_SCALE           = 2015, // vector
	SKY_CLOUD_SIZE_RATIO			= 2016, // real
	SKY_CLOUD_GROOVE_DEPTH    = 2017, // real
	SKY_CLOUD_SHAPE_STRENGTH  = 2018, // real

	SKY_CLOUD_GRID_POINTS     = 2100, // static text

	SKY_CLOUD_DUMMY
};

#endif // OCLOUD_H__
