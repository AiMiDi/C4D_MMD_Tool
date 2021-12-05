/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_SPC_H__
#define C4D_SPC_H__

#include "ge_math.h"

/// @addtogroup StereoModeTypes
/// @ingroup group_enumeration
/// @{
/// Stereo types.
/// @markPrivate
/// @since R19
#define SPC_MONO						0								///< Mono projection.
#define SPC_PARALLEL				1								///< Stereo Parallel projection.
#define SPC_TOEIN						2								///< Stereo toe-in projection.
/// @}

/// @addtogroup MappingFormatTypes
/// @ingroup group_enumeration
/// @{
/// Mapping types.
/// @markPrivate
/// @since R19
#define SPC_LAT_LONG				0								///< Equirectangular mapping.
#define SPC_CUBIC						1								///< A cubic cross mapping.
#define SPC_CUBIC32					2								///< A cubic 3x2 mapping.
#define SPC_CUBIC_STRING		3								///< A cubic string mapping.
/// @}

/// @addtogroup LayoutStereoTypes
/// @ingroup group_enumeration
/// @{
/// Stereo Layout types.
/// @markPrivate
/// @since R19
#define SPC_ABOVE_UNDER		0									///< Above-Under Layout.
#define SPC_SIDE_BY_SIDE	1									///< Side-by-Side Layout.
#define SPC_LEFT_ONLY			2									///< Left eye only.
#define SPC_RIGHT_ONLY		3									///< Right eye only.
/// @}

/// @addtogroup SmoothingType
/// @ingroup group_enumeration
/// @{
/// Smoothing types.
/// @markPrivate
/// @since R19
#define SPC_SMOOTHING_NONE				0					///< No smoothing applied.
#define SPC_SMOOTHING_LINEAR			1					///< Linear smoothing.
#define SPC_SMOOTHING_EXPONENTIAL	2					///< Exponential smoothing.
/// @}

//-------------------------------------------------------------------------------------------------
/// Holds latitude and longitude angles range.
/// @markPrivate
/// @since R19
//-------------------------------------------------------------------------------------------------
class LatLongRange
{
public:

	/// @name Constructors
	/// @{

	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	LatLongRange() = default;

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] src								The source LatLongRange.
	//----------------------------------------------------------------------------------------
	LatLongRange(const LatLongRange& src);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Assigment operator.
	/// @param[in] other							Another LatLongRange.
	//----------------------------------------------------------------------------------------
	LatLongRange& operator =(const LatLongRange& other);

	//----------------------------------------------------------------------------------------
	/// Makes the range conver the entire sphere (defaut values).
	//----------------------------------------------------------------------------------------
	void SetFullRange();

	//----------------------------------------------------------------------------------------
	/// Checks if the given lat-long coordinate are within the range.
	/// @param[in] lt									The latitude.
	/// @param[in] lg									The longitude.
	/// @return												@trueIfOtherwiseFalse{@formatParam{angle} is in the current range}
	//----------------------------------------------------------------------------------------
	Bool InRange(Float lt, Float lg) const;


	Float	_latMin  = -PI05;		///< Minimum latitude, default is -PI/2.
	Float	_latMax  =  PI05;		///< Maximum latitude, default is PI/2.
	Float	_longMin = -PI;			///< Minimum longitude, default is -PI.
	Float	_longMax =  PI;			///< Maximum longitude, default is PI.
};


typedef LatLongRange SphereArc;			///< Represents an arc on a sphere. @markPrivate

//-------------------------------------------------------------------------------------------------
/// Spherical camera context and parameters.
/// @markPrivate
/// @since R19
//-------------------------------------------------------------------------------------------------
class SpcInfo
{

public:

	/// @name Constructors
	/// @{
	
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	//----------------------------------------------------------------------------------------
	SpcInfo();

	//----------------------------------------------------------------------------------------
	/// Copy constructor.
	/// @param[in] src								The source SpcInfo.
	//----------------------------------------------------------------------------------------
	SpcInfo(const SpcInfo& src);

	/// @}

	//----------------------------------------------------------------------------------------
	/// Assigment operator.
	/// @param[in] that								Another SpcInfo.
	//----------------------------------------------------------------------------------------
	SpcInfo& operator =(const SpcInfo& that);

	/// @name Spherical Camera Availability
	/// @{

	//----------------------------------------------------------------------------------------
	/// Checks if SPC is available.
	/// @return												@trueIfOtherwiseFalse{SPC is available}
	//----------------------------------------------------------------------------------------
	Bool IsEnabled() const;

	/// @}

	/// @name Standard Properties
	/// @{
	LatLongRange	_range;								///< Spherical camera range (as specified by the user).
	LatLongRange	_crange;							///< Computed range (if _fitFrame option enabled).
	Bool					_fitFrame = true;			///< Rendering always fit frame.
	Int32					_stereoMode = 0;			///< The stereo mode: @enumerateEnum{StereoModeTypes}
	Int32					_mapping = 0;					///< The rendering mapping format: @enumerateEnum{MappingFormatTypes}
	Int32					_layout  = 0;					///< The stereo layout: @enumerateEnum{LayoutStereoTypes}
	Float64				_nw = 1.0;						///< Width normalizing factor.
	Float64				_nh = 1.0;						///< Height normalizing factor.
	Float64				_xmin;								///< Rendering bounding-box minimum X.
	Float64				_ymin;								///< Rendering bounding-box minimum Y.
	Float64				_xmax;								///< Rendering bounding-box maximum X.
	Float64				_ymax;								///< Rendering bounding-box maximum Y.
	/// @}

	/// @name Geometry Properties
	/// @{
	Float _eyeSeparation = 0.0;					///< Eye separation (in mm).
	Float _focalDistance = 0.0;					///< Focal distance (in mm).
	Float _eyeNeckDistance = 0.0;				///< Eye neck distance (in mm).
	/// @}

	/// @name Poles Smoothing
	/// @{
	Int32 _smoothTop = 0;								///< Top pole smoothing type: @enumerateEnum{SmoothingType}
	Int32 _smoothBottom = 0;						///< Bottom pole smoothing type: @enumerateEnum{SmoothingType}
	/// @}

	/// @name Smoothing Threshold Angles
	/// @{
	Float _topAngle = -PI05;						///< The top angle at which the smoothing takes place.
	Float _bottomAngle = PI05;					///< The bottom angle at which the smoothing takes place.
	/// @}

	/// @name Factors Exponential Smoothing
	/// @{
	Float _topExp = 0.0;								///< Top exponential smoothing.
	Float _bottomExp = 0.0;							///< Bottom exponential smoothing.
	/// @}
};

#endif // C4D_SPC_H__
