��      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��^E:\C4DSDK\C4D_MMDTool\sdk_2024\frameworks\modeling_geom.framework\source\maxon\geometryutils.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/errorbase.h�hhh]��quote��"��template�Nubh()��}�(h�maxon/vector2d.h�hhh]�h-h.h/Nubh()��}�(h�maxon/matrix2d.h�hhh]�h-h.h/Nubh()��}�(h�maxon/array.h�hhh]�h-h.h/Nubh()��}�(h�maxon/geomconstants.h�hhh]�h-h.h/Nubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhK�hK
hKubh�ubhhh]�(h �Enum���)��}�(hh�GEOMETRY_TEST_EXACT�����}�(hKhh)��}�(hhhM0hKhKubh�ubhh@h]�(h �	EnumValue���)��}�(hh�
GEOM_FALSE�����}�(hKhh)��}�(hhhMGhKhKubh�ubhhKh]��
simpleName�hZ�access��public��kind��	enumvalue�h/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]�h�///< Test result is false
�����}�(hKhh)��}�(hhhMZhKhKubh�uba�doc��///< Test result is false
��annotations�}��	anonymous���value��0�ubhU)��}�(hh�	GEOM_TRUE�����}�(hKhh)��}�(hhhMuhKhKubh�ubhhKh]�h_h{h`hahbhch/NhdNhNheNhfNhgK hh]�h�///< Test result is true
�����}�(hKhh)��}�(hhhM�hKhKubh�ubahp�///< Test result is true
�hr}�ht�huNubhU)��}�(hh�GEOM_PARALLEL�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhKh]�h_h�h`hahbhch/NhdNhNheNhfNhgK hh]�h�4///< Degenerate colinear, ordered in same direction
�����}�(hKhh)��}�(hhhM�hKhKubh�ubahp�4///< Degenerate colinear, ordered in same direction
�hr}�ht�huNubhU)��}�(hh�GEOM_ANTIPARALLEL�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhKh]�h_h�h`hahbhch/NhdNhNheNhfNhgK hh]�h�8///< Degenerate colinear, ordered in opposite direction
�����}�(hKhh)��}�(hhhM�hKhKubh�ubahp�8///< Degenerate colinear, ordered in opposite direction
�hr}�ht�huNubhU)��}�(hh�GEOM_COINCIDENT_PREV�����}�(hKhh)��}�(hhhM3hKhKubh�ubhhKh]�h_h�h`hahbhch/NhdNhNheNhfNhgK hh]�h�"///< Degenerate coincident points
�����}�(hKhh)��}�(hhhMIhKhKubh�ubahp�"///< Degenerate coincident points
�hr}�ht�huNubhU)��}�(hh�GEOM_COINCIDENT_NEXT�����}�(hKhh)��}�(hhhMlhKhKubh�ubhhKh]�h_h�h`hahbhch/NhdNhNheNhfNhgK hh]�h�"///< Degenerate coincident points
�����}�(hKhh)��}�(hhhM�hKhKubh�ubahp�"///< Degenerate coincident points
�hr}�ht�huNubhU)��}�(hh�GEOM_COINCIDENT_ALL�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhKh]�h_h�h`hahbhch/NhdNhNheNhfNhgK hh]�h�"///< Degenerate coincident points
�����}�(hKhh)��}�(hhhM�hKhKubh�ubahp�"///< Degenerate coincident points
�hr}�ht�huNubhU)��}�(hh�GEOM_DEGENERATE�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhKh]�h_h�h`hahbhch/NhdNhNheNhfNhgK hh]�h�///< Other degeneracy
�����}�(hKhh)��}�(hhhM�hKhKubh�ubahp�///< Other degeneracy
�hr}�ht�huNubhU)��}�(hh�GEOM_INVALID_INPUT�����}�(hKhh)��}�(hhhMhKhKubh�ubhhKh]�h_h�h`hahbhch/NhdNhNheNhfNhgK hh]�h�D///< Input is non-valid in some way making it impossible to proceed
�����}�(hKhh)��}�(hhhMhKhKubh�ubahp�D///< Input is non-valid in some way making it impossible to proceed
�hr}�ht�huNubeh_hOh`hahb�enum�h/NhdNhNheNhfNhgK hh]�h�N/// Return type for geometric tests when degenerate cases need to be reported
�����}�(hKhh)��}�(hhhK�hKhKubh�ubahp�N/// Return type for geometric tests when degenerate cases need to be reported
�hr}�ht��bases�]��scoped���
registered���flags��h X<  enum class GEOMETRY_TEST_EXACT
{
	GEOM_FALSE = 0,				///< Test result is false
	GEOM_TRUE,						///< Test result is true
	GEOM_PARALLEL,				///< Degenerate colinear, ordered in same direction
	GEOM_ANTIPARALLEL,		///< Degenerate colinear, ordered in opposite direction
	GEOM_COINCIDENT_PREV,	///< Degenerate coincident points
	GEOM_COINCIDENT_NEXT,	///< Degenerate coincident points
	GEOM_COINCIDENT_ALL,	///< Degenerate coincident points
	GEOM_DEGENERATE,			///< Other degeneracy
	GEOM_INVALID_INPUT		///< Input is non-valid in some way making it impossible to proceed
} �hK�early��ubhJ)��}�(hh�LOOP_OVERLAP_STATE�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh@h]�(hU)��}�(hh�INTERSECTING�����}�(hKhh)��}�(hhhM�hKhKubh�ubhj  h]�h_j%  h`hahbhch/NhdNhNheNhfNhgK hh]�h�s///< Loops intersect each other. Contact points do not count as intersections, only actual crossings of the loops.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubahp�s///< Loops intersect each other. Contact points do not count as intersections, only actual crossings of the loops.
�hr}�ht�huNubhU)��}�(hh�DISJOINT�����}�(hKhh)��}�(hhhM\hKhKubh�ubhj  h]�h_j7  h`hahbhch/NhdNhNheNhfNhgK hh]�h�3///< Loops are completely disjoint from each other
�����}�(hKhh)��}�(hhhMhhKhKubh�ubahp�3///< Loops are completely disjoint from each other
�hr}�ht�huNubhU)��}�(hh�
A_INSIDE_B�����}�(hKhh)��}�(hhhM�hK hKubh�ubhj  h]�h_jI  h`hahbhch/NhdNhNheNhfNhgK hh]�h�///< A is entirely within B
�����}�(hKhh)��}�(hhhM�hK hKubh�ubahp�///< A is entirely within B
�hr}�ht�huNubhU)��}�(hh�
B_INSIDE_A�����}�(hKhh)��}�(hhhM�hK!hKubh�ubhj  h]�h_j[  h`hahbhch/NhdNhNheNhfNhgK hh]�h�///< B is entirely within A
�����}�(hKhh)��}�(hhhM�hK!hKubh�ubahp�///< B is entirely within A
�hr}�ht�huNubhU)��}�(hh�
COINCIDENT�����}�(hKhh)��}�(hhhM�hK"hKubh�ubhj  h]�h_jm  h`hahbhch/NhdNhNheNhfNhgK hh]�h�[///< Loops are coincident - they lie on each other's perimeter, e.g. A and B are the same.
�����}�(hKhh)��}�(hhhM�hK"hKubh�ubahp�[///< Loops are coincident - they lie on each other's perimeter, e.g. A and B are the same.
�hr}�ht�huNubhU)��}�(hh�
DEGENERATE�����}�(hKhh)��}�(hhhMYhK#hKubh�ubhj  h]�h_j  h`hahbhch/NhdNhNheNhfNhgK hh]�h�I///< At least one of A and B has insufficient vertices (need at least 3)
�����}�(hKhh)��}�(hhhMehK#hKubh�ubahp�I///< At least one of A and B has insufficient vertices (need at least 3)
�hr}�ht�huNubeh_j  h`hahbj  h/NhdNhNheNhfNhgK hh]�h�0/// Return type for loop overlap state queries.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubahp�0/// Return type for loop overlap state queries.
�hr}�ht�j  ]�j  �j  �j  �h X�  enum class LOOP_OVERLAP_STATE
{
	INTERSECTING,	///< Loops intersect each other. Contact points do not count as intersections, only actual crossings of the loops.
	DISJOINT,			///< Loops are completely disjoint from each other
	A_INSIDE_B,		///< A is entirely within B
	B_INSIDE_A,		///< B is entirely within A
	COINCIDENT,		///< Loops are coincident - they lie on each other's perimeter, e.g. A and B are the same.
	DEGENERATE		///< At least one of A and B has insufficient vertices (need at least 3)
} �hK$j  �ubh �Class���)��}�(hh�DegeneratedInputErrorInterface�����}�(hKhh)��}�(hhhM&hK,hKubh�ubhh@h]�h_j�  h`hahb�class�h/NhdNhNheh�+"net.maxon.interface.degeneratedinputerror"�����}�(hKhh)��}�(hhhM�hK.hKQubh�ubhfNhgK hh]�h��/// An Degenerated input error indicates that a function was unable to compute a result because of degenerate cases (i.e. polygons with size 0).
�����}�(hKhh)��}�(hhhM4hK*hKubh�ubahp��/// An Degenerated input error indicates that a function was unable to compute a result because of degenerate cases (i.e. polygons with size 0).
�hr}�ht�j  ]��ErrorInterface�hah	��a�	interface�K�refKind�K�static���refClass��DegeneratedInputError��baseInterfaces�]�j�  h	��a�derived���isError���implementation���	component���finalComponent���forward���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���usings�]��constUsings�]��ambiguousCalls�]��	selfCalls�]��methodNames�}�ubj�  )��}�(hj�  hh@h]�h_j�  h`hahbj�  h/NhdNhNheNhfNhgKhhj�  hp��/// An Degenerated input error indicates that a function was unable to compute a result because of degenerate cases (i.e. polygons with size 0).
�hr}�ht�j  ]��*ErrorInterface::ReferenceClassHelper::type�hah	��aj�  Nj�  Nj�  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]��source�j�  ubj�  )��}�(hh�GeometryUtilsInterface�����}�(hKhh)��}�(hhhM�hK5hKubh�ubhh@h]�(h �Function���)��}�(hh�LinearRemapToRange�����}�(hKhh)��}�(hhhM�hKChKubh�ubhj�  h]�h_j�  h`h�public�����}�(hKhh)��}�(hhhMb	hK9hKubh�ubhbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKChK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�./// Remaps a value from one range to another.
�����}�(hKhh)��}�(hhhM�	hK;hKubh�ubh�./// @param[in] value 					The value to remap.
�����}�(hKhh)��}�(hhhM�	hK<hKubh�ubh�7/// @param[in] from1 					First bound of source range.
�����}�(hKhh)��}�(hhhM%
hK=hKubh�ubh�7/// @param[in] to1 						Second bound of source range.
�����}�(hKhh)��}�(hhhM]
hK>hKubh�ubh�</// @param[in] from2 					First bound of destination range.
�����}�(hKhh)��}�(hhhM�
hK?hKubh�ubh�</// @param[in] to2 						Second bound of destination range.
�����}�(hKhh)��}�(hhhM�
hK@hKubh�ubh�)/// @return 									The remapped value.
�����}�(hKhh)��}�(hhhMhKAhKubh�ubehpXk  /// Remaps a value from one range to another.
/// @param[in] value 					The value to remap.
/// @param[in] from1 					First bound of source range.
/// @param[in] to1 						Second bound of source range.
/// @param[in] from2 					First bound of destination range.
/// @param[in] to2 						Second bound of destination range.
/// @return 									The remapped value.
�hr}�ht�j�  ��explicit���deleted���retType��Float��const���params�]�(h �	Parameter���)��}�(h�Float�hh�value�����}�(hKhh)��}�(hhhM�hKChK5ubh�ub�default�N�pack���input���output��ubj3  )��}�(h�Float�hh�from1�����}�(hKhh)��}�(hhhM�hKChKBubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�to1�����}�(hKhh)��}�(hhhM�hKChKOubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�from2�����}�(hKhh)��}�(hhhM�hKChKZubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�to2�����}�(hKhh)��}�(hhhM�hKChKgubh�ubj=  Nj>  �j?  �j@  �ube�
observable�N�result�Nj�  K ubj�  )��}�(hh�
GetAngle2D�����}�(hKhh)��}�(hhhM�hKKhKubh�ubhj�  h]�h_jk  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKKhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�5/// Gets the 2D angle between two direction vectors.
�����}�(hKhh)��}�(hhhM^hKFhKubh�ubh�6/// @param[in] direction1					First direction vector.
�����}�(hKhh)��}�(hhhM�hKGhKubh�ubh�7/// @param[in] direction2					Second direction vector.
�����}�(hKhh)��}�(hhhM�hKHhKubh�ubh�H/// @return												The angle value in between 0 and 2PI in radians.
�����}�(hKhh)��}�(hhhMhKIhKubh�ubehp��/// Gets the 2D angle between two direction vectors.
/// @param[in] direction1					First direction vector.
/// @param[in] direction2					Second direction vector.
/// @return												The angle value in between 0 and 2PI in radians.
�hr}�ht�j�  �j+  �j,  �j-  �Float�j/  �j0  ]�(j3  )��}�(h�const Vector2d&�hh�
direction1�����}�(hKhh)��}�(hhhM�hKKhK7ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�
direction2�����}�(hKhh)��}�(hhhM�hKKhKSubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�InterpolatePointOnSegment�����}�(hKhh)��}�(hhhMhKUhKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMlhKUhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�L/// Calculates the normalized position of a point along a directed segment.
�����}�(hKhh)��}�(hhhMdhKNhKubh�ubh�4/// @param[in] segmentPoint1			First segment point.
�����}�(hKhh)��}�(hhhM�hKOhKubh�ubh�5/// @param[in] segmentPoint2			Second segment point.
�����}�(hKhh)��}�(hhhM�hKPhKubh�ubh�F/// @param[in] point							The point position along the segment line.
�����}�(hKhh)��}�(hhhMhKQhKubh�ubh�X/// @param[in] clamp							If true the resulting value will be clamped between 0 and 1.
�����}�(hKhh)��}�(hhhMchKRhKubh�ubh�L/// @return												The normalized position of the point on the segment.
�����}�(hKhh)��}�(hhhM�hKShKubh�ubehpX�  /// Calculates the normalized position of a point along a directed segment.
/// @param[in] segmentPoint1			First segment point.
/// @param[in] segmentPoint2			Second segment point.
/// @param[in] point							The point position along the segment line.
/// @param[in] clamp							If true the resulting value will be clamped between 0 and 1.
/// @return												The normalized position of the point on the segment.
�hr}�ht�j�  �j+  �j,  �j-  �Float�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�segmentPoint1�����}�(hKhh)��}�(hhhM�hKUhKDubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�segmentPoint2�����}�(hKhh)��}�(hhhM�hKUhKaubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhM�hKUhK~ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�clamp�����}�(hKhh)��}�(hhhM�hKUhK�ubh�ubj=  �true�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�InterpolatePointOnSegment2D�����}�(hKhh)��}�(hhhMxhK_hKubh�ubhj�  h]�h_j  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMehK_hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�O/// Calculates the normalized position of a 2D point along a directed segment.
�����}�(hKhh)��}�(hhhMZhKXhKubh�ubh�4/// @param[in] segmentPoint1			First segment point.
�����}�(hKhh)��}�(hhhM�hKYhKubh�ubh�5/// @param[in] segmentPoint2			Second segment point.
�����}�(hKhh)��}�(hhhM�hKZhKubh�ubh�F/// @param[in] point							The point position along the segment line.
�����}�(hKhh)��}�(hhhMhK[hKubh�ubh�X/// @param[in] clamp							If true the resulting value will be clamped between 0 and 1.
�����}�(hKhh)��}�(hhhM\hK\hKubh�ubh�L/// @return												The normalized position of the point on the segment.
�����}�(hKhh)��}�(hhhM�hK]hKubh�ubehpX�  /// Calculates the normalized position of a 2D point along a directed segment.
/// @param[in] segmentPoint1			First segment point.
/// @param[in] segmentPoint2			Second segment point.
/// @param[in] point							The point position along the segment line.
/// @param[in] clamp							If true the resulting value will be clamped between 0 and 1.
/// @return												The normalized position of the point on the segment.
�hr}�ht�j�  �j+  �j,  �j-  �Float�j/  �j0  ]�(j3  )��}�(h�const Vector2d&�hh�segmentPoint1�����}�(hKhh)��}�(hhhM�hK_hKHubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�segmentPoint2�����}�(hKhh)��}�(hhhM�hK_hKgubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�point�����}�(hKhh)��}�(hhhM�hK_hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�clamp�����}�(hKhh)��}�(hhhM�hK_hK�ubh�ubj=  �true�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�CalculateBestFitPlane�����}�(hKhh)��}�(hhhMXhKihKubh�ubhj�  h]�h_jc  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMFhKihK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�N/// Calculates the the best fit plane centroid and normal from a point cloud.
�����}�(hKhh)��}�(hhhM[hKbhKubh�ubh�E/// @param[in] pointCloud					A block filled with point coordinates.
�����}�(hKhh)��}�(hhhM�hKchKubh�ubh�A/// @param[out] centroid					The resulting point cloud centroid.
�����}�(hKhh)��}�(hhhM�hKdhKubh�ubh�8/// @param[out] normal						The resulting plane normal.
�����}�(hKhh)��}�(hhhM2hKehKubh�ubh�;/// @param[in] iterMax						Max iteration for computation.
�����}�(hKhh)��}�(hhhMkhKfhKubh�ubh�;/// @return												True if successful otherwise false.
�����}�(hKhh)��}�(hhhM�hKghKubh�ubehpX�  /// Calculates the the best fit plane centroid and normal from a point cloud.
/// @param[in] pointCloud					A block filled with point coordinates.
/// @param[out] centroid					The resulting point cloud centroid.
/// @param[out] normal						The resulting plane normal.
/// @param[in] iterMax						Max iteration for computation.
/// @return												True if successful otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector>&�hh�
pointCloud�����}�(hKhh)��}�(hhhM�hKihKLubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�centroid�����}�(hKhh)��}�(hhhM�hKihK`ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�normal�����}�(hKhh)��}�(hhhM�hKihKrubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Int�hh�iterMax�����}�(hKhh)��}�(hhhM�hKihK~ubh�ubj=  �500�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�Points3Dto2D�����}�(hKhh)��}�(hhhM�hK|hK#ubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK|hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�X/// Projects 3D points as 2D points on a plane which is parallel to the points best fit
�����}�(hKhh)��}�(hhhM)hKlhKubh�ubh�N/// plane and which passes through the origin of the world coordinate system.
�����}�(hKhh)��}�(hhhM�hKmhKubh�ubh�</// @param[in] points							Points 3D positions to project.
�����}�(hKhh)��}�(hhhM�hKnhKubh�ubh�]/// @param[in] normal							The normal vector of the plane onto which to project the points.
�����}�(hKhh)��}�(hhhMhKohKubh�ubh�W/// @param[in, out] basisVector0	First basis vector of the 2D plane coordinate system.
�����}�(hKhh)��}�(hhhMlhKphKubh�ubh�X/// @param[in, out] basisVector1	Second basis vector of the 2D plane coordinate system.
�����}�(hKhh)��}�(hhhM�hKqhKubh�ubh�_/// @param[out] translate					Translation vector between the projection plane origin (which is
�����}�(hKhh)��}�(hhhMhKrhKubh�ubh�P///																the world CS origin) and the best fit plane origin (which is
�����}�(hKhh)��}�(hhhM}hKshKubh�ubh�W///																the orthogonal projection of the world CS origin to the fit plane).
�����}�(hKhh)��}�(hhhM�hKthKubh�ubh�U///																In other words, translation vector is the distance vector between
�����}�(hKhh)��}�(hhhM&hKuhKubh�ubh�@///																the projection plane an the best fit planes.
�����}�(hKhh)��}�(hhhM|hKvhKubh�ubh�y/// @param[in] checkDegenerated		If true try to avoid cases where the resulting 2d outline contains coincident vertices.
�����}�(hKhh)��}�(hhhM�hKwhKubh�ubh�N/// @param[out] outPoints					Array containing 2D projected points positions.
�����}�(hKhh)��}�(hhhM7hKxhKubh�ubh�f/// @param[out] computeBasis			Compute basis vectors from the normal and the input points if enabled.
�����}�(hKhh)��}�(hhhM�hKyhKubh�ubh�h/// @return												OK on success. DegeneratedInputError if input points are collapsed in one point.
�����}�(hKhh)��}�(hhhM�hKzhKubh�ubehpX  /// Projects 3D points as 2D points on a plane which is parallel to the points best fit
/// plane and which passes through the origin of the world coordinate system.
/// @param[in] points							Points 3D positions to project.
/// @param[in] normal							The normal vector of the plane onto which to project the points.
/// @param[in, out] basisVector0	First basis vector of the 2D plane coordinate system.
/// @param[in, out] basisVector1	Second basis vector of the 2D plane coordinate system.
/// @param[out] translate					Translation vector between the projection plane origin (which is
///																the world CS origin) and the best fit plane origin (which is
///																the orthogonal projection of the world CS origin to the fit plane).
///																In other words, translation vector is the distance vector between
///																the projection plane an the best fit planes.
/// @param[in] checkDegenerated		If true try to avoid cases where the resulting 2d outline contains coincident vertices.
/// @param[out] outPoints					Array containing 2D projected points positions.
/// @param[out] computeBasis			Compute basis vectors from the normal and the input points if enabled.
/// @return												OK on success. DegeneratedInputError if input points are collapsed in one point.
�hr}�ht�j�  �j+  �j,  �j-  �Result<void>�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector>&�hh�points�����}�(hKhh)��}�(hhhM�hK|hKKubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�normal�����}�(hKhh)��}�(hhhMhK|hKaubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�basisVector0�����}�(hKhh)��}�(hhhM!hK|hKqubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�basisVector1�����}�(hKhh)��}�(hhhM7hK|hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�	translate�����}�(hKhh)��}�(hhhMMhK|hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�checkDegenerated�����}�(hKhh)��}�(hhhM]hK|hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�!WritableArrayInterface<Vector2d>&�hh�	outPoints�����}�(hKhh)��}�(hhhM�hK|hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�computeBasis�����}�(hKhh)��}�(hhhM�hK|hK�ubh�ubj=  �true�j>  �j?  �j@  �ubeje  Njf  �void�j�  K ubj�  )��}�(hh�Points3Dto2D�����}�(hKhh)��}�(hhhM� hK�hK#ubh�ubhj�  h]�h_jx  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM� hK�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�E/// Projects 3D points as 2D points on a plane. Overloaded function.
�����}�(hKhh)��}�(hhhMhKhKubh�ubh�</// @param[in] points							Points 3D positions to project.
�����}�(hKhh)��}�(hhhM[hK�hKubh�ubh�]/// @param[in] normal							The normal vector of the plane onto which to project the points.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�y/// @param[in] checkDegenerated		If true try to avoid cases where the resulting 2d outline contains coincident vertices.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�N/// @param[out] outPoints					Array containing 2D projected points positions.
�����}�(hKhh)��}�(hhhMphK�hKubh�ubh�h/// @return												OK on success. DegeneratedInputError if input points are collapsed in one point.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubehpX  /// Projects 3D points as 2D points on a plane. Overloaded function.
/// @param[in] points							Points 3D positions to project.
/// @param[in] normal							The normal vector of the plane onto which to project the points.
/// @param[in] checkDegenerated		If true try to avoid cases where the resulting 2d outline contains coincident vertices.
/// @param[out] outPoints					Array containing 2D projected points positions.
/// @return												OK on success. DegeneratedInputError if input points are collapsed in one point.
�hr}�ht�j�  �j+  �j,  �j-  �Result<void>�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector>&�hh�points�����}�(hKhh)��}�(hhhM� hK�hKKubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�normal�����}�(hKhh)��}�(hhhM� hK�hKaubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�checkDegenerated�����}�(hKhh)��}�(hhhM� hK�hKnubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�!WritableArrayInterface<Vector2d>&�hh�	outPoints�����}�(hKhh)��}�(hhhM$!hK�hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  �void�j�  K ubj�  )��}�(hh�Point2Dto3D�����}�(hKhh)��}�(hhhM�#hK�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�#hK�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�I/// Calculates 3D world point coordinates from its 2D local coordinates.
�����}�(hKhh)��}�(hhhM�!hK�hKubh�ubh�7/// @param[in] point							Point 2D local coordinates.
�����}�(hKhh)��}�(hhhM�!hK�hKubh�ubh�U/// @param[in] basisVector0				First basis vector of the 2D local coordinate system.
�����}�(hKhh)��}�(hhhM"hK�hKubh�ubh�V/// @param[in] basisVector1				Second basis vector of the 2D local coordinate system.
�����}�(hKhh)��}�(hhhMf"hK�hKubh�ubh�1/// @param[in] translate					Translation vector.
�����}�(hKhh)��}�(hhhM�"hK�hKubh�ubh�3/// @return												Point 3D world coordinates.
�����}�(hKhh)��}�(hhhM�"hK�hKubh�ubehpX�  /// Calculates 3D world point coordinates from its 2D local coordinates.
/// @param[in] point							Point 2D local coordinates.
/// @param[in] basisVector0				First basis vector of the 2D local coordinate system.
/// @param[in] basisVector1				Second basis vector of the 2D local coordinate system.
/// @param[in] translate					Translation vector.
/// @return												Point 3D world coordinates.
�hr}�ht�j�  �j+  �j,  �j-  �Vector�j/  �j0  ]�(j3  )��}�(h�const Vector2d&�hh�point�����}�(hKhh)��}�(hhhM�#hK�hK9ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�basisVector0�����}�(hKhh)��}�(hhhM�#hK�hKNubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�basisVector1�����}�(hKhh)��}�(hhhM�#hK�hKjubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�	translate�����}�(hKhh)��}�(hhhM$hK�hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�Points2Dto3D�����}�(hKhh)��}�(hhhM�&hK�hK#ubh�ubhj�  h]�h_j1  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMp&hK�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�J/// Calculates 3D world points coordinates from its 2D local coordinates.
�����}�(hKhh)��}�(hhhMm$hK�hKubh�ubh�9/// @param[in] points							Points 2D local coordinates.
�����}�(hKhh)��}�(hhhM�$hK�hKubh�ubh�U/// @param[in] basisVector0				First basis vector of the 2D local coordinate system.
�����}�(hKhh)��}�(hhhM�$hK�hKubh�ubh�V/// @param[in] basisVector1				Second basis vector of the 2D local coordinate system.
�����}�(hKhh)��}�(hhhMH%hK�hKubh�ubh�1/// @param[in] translate					Translation vector.
�����}�(hKhh)��}�(hhhM�%hK�hKubh�ubh�;/// @param[out] outPoints					Points 3D world coordinates.
�����}�(hKhh)��}�(hhhM�%hK�hKubh�ubehpX�  /// Calculates 3D world points coordinates from its 2D local coordinates.
/// @param[in] points							Points 2D local coordinates.
/// @param[in] basisVector0				First basis vector of the 2D local coordinate system.
/// @param[in] basisVector1				Second basis vector of the 2D local coordinate system.
/// @param[in] translate					Translation vector.
/// @param[out] outPoints					Points 3D world coordinates.
�hr}�ht�j�  �j+  �j,  �j-  �Result<void>�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector2d>&�hh�points�����}�(hKhh)��}�(hhhM�&hK�hKMubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�basisVector0�����}�(hKhh)��}�(hhhM�&hK�hKcubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�basisVector1�����}�(hKhh)��}�(hhhM�&hK�hKubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�	translate�����}�(hKhh)��}�(hhhM'hK�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�WritableArrayInterface<Vector>&�hh�	outPoints�����}�(hKhh)��}�(hhhM-'hK�hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  �void�j�  K ubj�  )��}�(hh�CalculateTriangleArea�����}�(hKhh)��}�(hhhM�(hK�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�(hK�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�'/// Calculates the area of a triangle.
�����}�(hKhh)��}�(hhhM�'hK�hKubh�ubh�+/// @param[in] a									Triangle point A.
�����}�(hKhh)��}�(hhhM�'hK�hKubh�ubh�+/// @param[in] b									Triangle point B.
�����}�(hKhh)��}�(hhhM�'hK�hKubh�ubh�+/// @param[in] c									Triangle point C.
�����}�(hKhh)��}�(hhhM(hK�hKubh�ubh�//// @return												Unsigned triangle area.
�����}�(hKhh)��}�(hhhMC(hK�hKubh�ubehp��/// Calculates the area of a triangle.
/// @param[in] a									Triangle point A.
/// @param[in] b									Triangle point B.
/// @param[in] c									Triangle point C.
/// @return												Unsigned triangle area.
�hr}�ht�j�  �j+  �j,  �j-  �Float�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�a�����}�(hKhh)��}�(hhhM)hK�hK@ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�b�����}�(hKhh)��}�(hhhM)hK�hKQubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�c�����}�(hKhh)��}�(hhhM/)hK�hKbubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�CalculateSignedTriangleArea�����}�(hKhh)��}�(hhhMH+hK�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM5+hK�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�8/// Calculates the signed area of an oriented triangle.
�����}�(hKhh)��}�(hhhM�)hK�hKubh�ubh�S/// Sign is defined as the sign of the z coordinate of the triangle normal vector.
�����}�(hKhh)��}�(hhhM�)hK�hKubh�ubh�+/// @param[in] a									Triangle point A.
�����}�(hKhh)��}�(hhhM*hK�hKubh�ubh�+/// @param[in] b									Triangle point B.
�����}�(hKhh)��}�(hhhMJ*hK�hKubh�ubh�+/// @param[in] c									Triangle point C.
�����}�(hKhh)��}�(hhhMv*hK�hKubh�ubh�//// @return												Unsigned triangle area.
�����}�(hKhh)��}�(hhhM�*hK�hKubh�ubehpX;  /// Calculates the signed area of an oriented triangle.
/// Sign is defined as the sign of the z coordinate of the triangle normal vector.
/// @param[in] a									Triangle point A.
/// @param[in] b									Triangle point B.
/// @param[in] c									Triangle point C.
/// @return												Unsigned triangle area.
�hr}�ht�j�  �j+  �j,  �j-  �Float�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�a�����}�(hKhh)��}�(hhhMr+hK�hKFubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�b�����}�(hKhh)��}�(hhhM�+hK�hKWubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�c�����}�(hKhh)��}�(hhhM�+hK�hKhubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�CalculateQuadrangleArea�����}�(hKhh)��}�(hhhM�-hK�hKubh�ubhj�  h]�h_j7  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMp-hK�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�)/// Calculates the area of a quadrangle.
�����}�(hKhh)��}�(hhhM�+hK�hKubh�ubh�-/// @param[in] a									Quadrangle point A.
�����}�(hKhh)��}�(hhhM ,hK�hKubh�ubh�-/// @param[in] b									Quadrangle Point B.
�����}�(hKhh)��}�(hhhMN,hK�hKubh�ubh�-/// @param[in] c									Quadrangle Point C.
�����}�(hKhh)��}�(hhhM|,hK�hKubh�ubh�-/// @param[in] d									Quadrangle Point D.
�����}�(hKhh)��}�(hhhM�,hK�hKubh�ubh�4/// @return												Unsigned area of Quadrangle.
�����}�(hKhh)��}�(hhhM�,hK�hKubh�ubehpX  /// Calculates the area of a quadrangle.
/// @param[in] a									Quadrangle point A.
/// @param[in] b									Quadrangle Point B.
/// @param[in] c									Quadrangle Point C.
/// @param[in] d									Quadrangle Point D.
/// @return												Unsigned area of Quadrangle.
�hr}�ht�j�  �j+  �j,  �j-  �Float�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�a�����}�(hKhh)��}�(hhhM�-hK�hKBubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�b�����}�(hKhh)��}�(hhhM�-hK�hKSubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�c�����}�(hKhh)��}�(hhhM�-hK�hKdubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�d�����}�(hKhh)��}�(hhhM�-hK�hKuubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�CalculateOutlineArea�����}�(hKhh)��}�(hhhM�/hK�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�/hK�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�S/// Calculates the unsigned area of an outline defined by points in outlinePoints.
�����}�(hKhh)��}�(hhhM>.hK�hKubh�ubh�S/// If the points are not co-planar, they will be flattened on a "best fit" plane.
�����}�(hKhh)��}�(hhhM�.hK�hKubh�ubh�?/// @param[in] outlinePoints			An array with a point sequence.
�����}�(hKhh)��}�(hhhM�.hK�hKubh�ubh�)/// @return												The outline area.
�����}�(hKhh)��}�(hhhM&/hK�hKubh�ubehpX  /// Calculates the unsigned area of an outline defined by points in outlinePoints.
/// If the points are not co-planar, they will be flattened on a "best fit" plane.
/// @param[in] outlinePoints			An array with a point sequence.
/// @return												The outline area.
�hr}�ht�j�  �j+  �j,  �j-  �Float�j/  �j0  ]�j3  )��}�(h�const Block<const Vector>&�hh�outlinePoints�����}�(hKhh)��}�(hhhM�/hK�hKLubh�ubj=  Nj>  �j?  �j@  �ubaje  Njf  Nj�  K ubj�  )��}�(hh�CalculateOutlineNormal�����}�(hKhh)��}�(hhhMT2hK�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM@2hK�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�./// Calculates the normal of an ngon outline.
�����}�(hKhh)��}�(hhhMd0hK�hKubh�ubh�O/// @param[in] points							A list of points that includes the outline points.
�����}�(hKhh)��}�(hhhM�0hK�hKubh�ubh�r/// @param[in] indices						The indices in the points list for the outline points to use. The order is important.
�����}�(hKhh)��}�(hhhM�0hK�hKubh�ubh�M/// @param[in] normalized					If true, the output normal will be normalized.
�����}�(hKhh)��}�(hhhMV1hK�hKubh�ubh�8/// @return												The normal of the point outline.
�����}�(hKhh)��}�(hhhM�1hK�hKubh�ubehpXt  /// Calculates the normal of an ngon outline.
/// @param[in] points							A list of points that includes the outline points.
/// @param[in] indices						The indices in the points list for the outline points to use. The order is important.
/// @param[in] normalized					If true, the output normal will be normalized.
/// @return												The normal of the point outline.
�hr}�ht�j�  �j+  �j,  �j-  �Vector�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector>&�hh�points�����}�(hKhh)��}�(hhhM�2hK�hKOubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Int32>&�hh�indices�����}�(hKhh)��}�(hhhM�2hK�hKqubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�
normalized�����}�(hKhh)��}�(hhhM�2hK�hKubh�ubj=  �true�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�CalculateOutlineNormal�����}�(hKhh)��}�(hhhM�4hK�hKubh�ubhj�  h]�h_j  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�4hK�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�./// Calculates the normal of an ngon outline.
�����}�(hKhh)��}�(hhhM(3hK�hKubh�ubh�b/// @param[in] points							The correctly ordered points that include the points for the outline.
�����}�(hKhh)��}�(hhhMW3hK�hKubh�ubh�L/// @param[in] normalize					If true, the output normal will be normalized.
�����}�(hKhh)��}�(hhhM�3hK�hKubh�ubh�8/// @return												The normal of the point outline.
�����}�(hKhh)��}�(hhhM4hK�hKubh�ubehpX  /// Calculates the normal of an ngon outline.
/// @param[in] points							The correctly ordered points that include the points for the outline.
/// @param[in] normalize					If true, the output normal will be normalized.
/// @return												The normal of the point outline.
�hr}�ht�j�  �j+  �j,  �j-  �Vector�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector>&�hh�points�����}�(hKhh)��}�(hhhM�4hK�hKOubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�	normalize�����}�(hKhh)��}�(hhhM�4hK�hK\ubh�ubj=  �true�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IsVertexConvex�����}�(hKhh)��}�(hhhMi7hK�hKubh�ubhj�  h]�h_jU  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMW7hK�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�I/// A convexity test for vertex in between 2 other vertices in 3D space.
�����}�(hKhh)��}�(hhhMg5hK�hKubh�ubh�1/// @param[in] vertex							The vertex to check.
�����}�(hKhh)��}�(hhhM�5hK�hKubh�ubh�+/// @param[in] next								The next point.
�����}�(hKhh)��}�(hhhM�5hK�hKubh�ubh�+/// @param[in] pred								The prev point.
�����}�(hKhh)��}�(hhhM6hK�hKubh�ubh�B/// @param[in] up									Up vector or the normal of the polygon.
�����}�(hKhh)��}�(hhhM;6hK�hKubh�ubh�u/// @return												True if vertex is convex otherwise false, in case of aligned point (angle == PI) return true.
�����}�(hKhh)��}�(hhhM~6hK�hKubh�ubehpX�  /// A convexity test for vertex in between 2 other vertices in 3D space.
/// @param[in] vertex							The vertex to check.
/// @param[in] next								The next point.
/// @param[in] pred								The prev point.
/// @param[in] up									Up vector or the normal of the polygon.
/// @return												True if vertex is convex otherwise false, in case of aligned point (angle == PI) return true.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�vertex�����}�(hKhh)��}�(hhhM�7hK�hK8ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�next�����}�(hKhh)��}�(hhhM�7hK�hKNubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pred�����}�(hKhh)��}�(hhhM�7hK�hKbubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�up�����}�(hKhh)��}�(hhhM�7hK�hKvubh�ubj=  �Vector(0,1,0)�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IsVertexConvexExact�����}�(hKhh)��}�(hhhMY:hK�hK*ubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM8:hK�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�I/// A convexity test for vertex in between 2 other vertices in 3D space.
�����}�(hKhh)��}�(hhhM98hK�hKubh�ubh�V/// This is the same test as IsVertexConvex, but explicitly reports degenerate cases.
�����}�(hKhh)��}�(hhhM�8hK�hKubh�ubh�1/// @param[in] vertex							The vertex to check.
�����}�(hKhh)��}�(hhhM�8hK�hKubh�ubh�+/// @param[in] next								The next point.
�����}�(hKhh)��}�(hhhM9hK�hKubh�ubh�+/// @param[in] pred								The prev point.
�����}�(hKhh)��}�(hhhM89hK�hKubh�ubh�B/// @param[in] up									Up vector or the normal of the polygon.
�����}�(hKhh)��}�(hhhMd9hK�hKubh�ubh�-/// @return												The detectected state
�����}�(hKhh)��}�(hhhM�9hK�hKubh�ubehpX�  /// A convexity test for vertex in between 2 other vertices in 3D space.
/// This is the same test as IsVertexConvex, but explicitly reports degenerate cases.
/// @param[in] vertex							The vertex to check.
/// @param[in] next								The next point.
/// @param[in] pred								The prev point.
/// @param[in] up									Up vector or the normal of the polygon.
/// @return												The detectected state
�hr}�ht�j�  �j+  �j,  �j-  �GEOMETRY_TEST_EXACT�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�vertex�����}�(hKhh)��}�(hhhM{:hK�hKLubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�next�����}�(hKhh)��}�(hhhM�:hK�hKbubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pred�����}�(hKhh)��}�(hhhM�:hK�hKvubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�up�����}�(hKhh)��}�(hhhM�:hK�hK�ubh�ubj=  �Vector(0,1,0)�j>  �j?  �j@  �ubj3  )��}�(h�Float�hh�epsilon�����}�(hKhh)��}�(hhhM�:hK�hK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�$CalculateMeanValueCoordinatesWeights�����}�(hKhh)��}�(hhhM�=hK�hK#ubh�ubhj�  h]�h_j  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�=hK�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�R/// Calculates the mean value coordinates weights for a point inside an outline. 
�����}�(hKhh)��}�(hhhMW;hK�hKubh�ubh��/// This internally calculates the normal of the outline and is thus more expensive than the other version that takes the normal as additional input.
�����}�(hKhh)��}�(hhhM�;hK�hKubh�ubh�E/// @param[in] point							The point for which to calculate weights.
�����}�(hKhh)��}�(hhhMA<hK�hKubh�ubh�)/// @param[in] outline						The outline.
�����}�(hKhh)��}�(hhhM�<hK�hKubh�ubh��/// @param[in] weights						Array of weights. The amount of entries in the resulting array is the same amount of outline vertices.
�����}�(hKhh)��}�(hhhM�<hK�hKubh�ubh�&/// @return												OK on success.
�����}�(hKhh)��}�(hhhM5=hK�hKubh�ubehpX�  /// Calculates the mean value coordinates weights for a point inside an outline. 
/// This internally calculates the normal of the outline and is thus more expensive than the other version that takes the normal as additional input.
/// @param[in] point							The point for which to calculate weights.
/// @param[in] outline						The outline.
/// @param[in] weights						Array of weights. The amount of entries in the resulting array is the same amount of outline vertices.
/// @return												OK on success.
�hr}�ht�j�  �j+  �j,  �j-  �Result<void>�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhM>hK�hKVubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector>&�hh�outline�����}�(hKhh)��}�(hhhM.>hK�hKxubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�WritableArrayInterface<Float>&�hh�weights�����}�(hKhh)��}�(hhhMV>hK�hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  �void�j�  K ubj�  )��}�(hh�$CalculateMeanValueCoordinatesWeights�����}�(hKhh)��}�(hhhMQAhK�hK#ubh�ubhj�  h]�h_js  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM7AhK�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�Q/// Calculates the mean value coordinates weights for a point inside an outline.
�����}�(hKhh)��}�(hhhM�>hK�hKubh�ubh�E/// @param[in] point							The point for which to calculate weights.
�����}�(hKhh)��}�(hhhM?hK�hKubh�ubh�S/// @param[in] points							A list of points that the outlineIndices reference to.
�����}�(hKhh)��}�(hhhMV?hK�hKubh�ubh�</// @param[in] outlineIndices			The indices of the outline.
�����}�(hKhh)��}�(hhhM�?hK�hKubh�ubh�A/// @param[in] normal							The normal direction of the outline.
�����}�(hKhh)��}�(hhhM�?hK�hKubh�ubh��/// @param[in] weights						Array of weights. The amount of entries in the resulting array is the same amount of outline vertices.
�����}�(hKhh)��}�(hhhM)@hK�hKubh�ubh�&/// @return												OK on success.
�����}�(hKhh)��}�(hhhM�@hK�hKubh�ubehpX  /// Calculates the mean value coordinates weights for a point inside an outline.
/// @param[in] point							The point for which to calculate weights.
/// @param[in] points							A list of points that the outlineIndices reference to.
/// @param[in] outlineIndices			The indices of the outline.
/// @param[in] normal							The normal direction of the outline.
/// @param[in] weights						Array of weights. The amount of entries in the resulting array is the same amount of outline vertices.
/// @return												OK on success.
�hr}�ht�j�  �j+  �j,  �j-  �Result<void>�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhM�AhK�hKVubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector>&�hh�points�����}�(hKhh)��}�(hhhM�AhK�hKxubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const UInt32>&�hh�outlineIndices�����}�(hKhh)��}�(hhhM�AhK�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�normal�����}�(hKhh)��}�(hhhM�AhK�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�WritableArrayInterface<Float>&�hh�weights�����}�(hKhh)��}�(hhhMBhK�hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  �void�j�  K ubj�  )��}�(hh�IsVertexConvex2D�����}�(hKhh)��}�(hhhM1DhMhKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMDhMhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�E/// A convexity test for vertex in between two other vertices in 2D.
�����}�(hKhh)��}�(hhhMvBhK�hKubh�ubh�1/// @param[in] vertex							The vertex to check.
�����}�(hKhh)��}�(hhhM�BhK�hKubh�ubh�+/// @param[in] next								The next point.
�����}�(hKhh)��}�(hhhM�BhK�hKubh�ubh�+/// @param[in] pred								The prev point.
�����}�(hKhh)��}�(hhhMChM hKubh�ubh�u/// @return												True if vertex is convex otherwise false, in case of aligned point (angle == PI) return true.
�����}�(hKhh)��}�(hhhMFChMhKubh�ubehpXA  /// A convexity test for vertex in between two other vertices in 2D.
/// @param[in] vertex							The vertex to check.
/// @param[in] next								The next point.
/// @param[in] pred								The prev point.
/// @return												True if vertex is convex otherwise false, in case of aligned point (angle == PI) return true.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector2d&�hh�vertex�����}�(hKhh)��}�(hhhMRDhMhK<ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�next�����}�(hKhh)��}�(hhhMjDhMhKTubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�pred�����}�(hKhh)��}�(hhhM�DhMhKjubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IsVertexConvexExact2D�����}�(hKhh)��}�(hhhM�FhMhK*ubh�ubhj�  h]�h_j,	  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�FhMhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�B/// A convexity test for vertex in between 2 other vertices in 2D
�����}�(hKhh)��}�(hhhM�DhMhKubh�ubh�V/// This is the same test as IsVertexConvex, but explicitly reports degenerate cases.
�����}�(hKhh)��}�(hhhM(EhMhKubh�ubh�1/// @param[in] vertex							The vertex to check.
�����}�(hKhh)��}�(hhhMEhMhKubh�ubh�+/// @param[in] next								The next point.
�����}�(hKhh)��}�(hhhM�EhM	hKubh�ubh�+/// @param[in] pred								The prev point.
�����}�(hKhh)��}�(hhhM�EhM
hKubh�ubh�-/// @return												The detectected state
�����}�(hKhh)��}�(hhhM	FhMhKubh�ubehpXL  /// A convexity test for vertex in between 2 other vertices in 2D
/// This is the same test as IsVertexConvex, but explicitly reports degenerate cases.
/// @param[in] vertex							The vertex to check.
/// @param[in] next								The next point.
/// @param[in] pred								The prev point.
/// @return												The detectected state
�hr}�ht�j�  �j+  �j,  �j-  �GEOMETRY_TEST_EXACT�j/  �j0  ]�(j3  )��}�(h�const Vector2d&�hh�vertex�����}�(hKhh)��}�(hhhM�FhMhKPubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�next�����}�(hKhh)��}�(hhhM�FhMhKhubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�pred�����}�(hKhh)��}�(hhhMGhMhK~ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�epsilon�����}�(hKhh)��}�(hhhMGhMhK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�CalculateBarycentricCoordinate�����}�(hKhh)��}�(hhhM�IhMhKubh�ubhj�  h]�h_j�	  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�IhMhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�K/// Calculates the barycentric UV coordinate of a point within a triangle.
�����}�(hKhh)��}�(hhhM�GhMhKubh�ubh�&/// @param[in] point							The point.
�����}�(hKhh)��}�(hhhM�GhMhKubh�ubh�,/// @param[in] a									Triangle vertex A.
�����}�(hKhh)��}�(hhhMHhMhKubh�ubh�,/// @param[in] b									Triangle vertex B.
�����}�(hKhh)��}�(hhhM=HhMhKubh�ubh�,/// @param[in] c									Triangle vertex C.
�����}�(hKhh)��}�(hhhMjHhMhKubh�ubh�9/// @return												The barycentric point coordinate.
�����}�(hKhh)��}�(hhhM�HhMhKubh�ubh�T///																'x' component of the vector is the coordinate of the point @p c,
�����}�(hKhh)��}�(hhhM�HhMhKubh�ubh�T///																'y' component of the vector is the coordinate of the point @p b.
�����}�(hKhh)��}�(hhhM&IhMhKubh�ubehpX�  /// Calculates the barycentric UV coordinate of a point within a triangle.
/// @param[in] point							The point.
/// @param[in] a									Triangle vertex A.
/// @param[in] b									Triangle vertex B.
/// @param[in] c									Triangle vertex C.
/// @return												The barycentric point coordinate.
///																'x' component of the vector is the coordinate of the point @p c,
///																'y' component of the vector is the coordinate of the point @p b.
�hr}�ht�j�  �j+  �j,  �j-  �Vector2d�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhM!JhMhKLubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�a�����}�(hKhh)��}�(hhhM6JhMhKaubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�b�����}�(hKhh)��}�(hhhMGJhMhKrubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�c�����}�(hKhh)��}�(hhhMXJhMhK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh� CalculateBarycentricCoordinate3D�����}�(hKhh)��}�(hhhMfLhM#hKubh�ubhj�  h]�h_j�	  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMRLhM#hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�L/// Calculates the barycentric UVW coordinate of a point within a triangle.
�����}�(hKhh)��}�(hhhM�JhMhKubh�ubh�&/// @param[in] point							The point.
�����}�(hKhh)��}�(hhhMKhMhKubh�ubh�,/// @param[in] a									Triangle vertex A.
�����}�(hKhh)��}�(hhhM.KhMhKubh�ubh�,/// @param[in] b									Triangle vertex B.
�����}�(hKhh)��}�(hhhM[KhMhKubh�ubh�,/// @param[in] c									Triangle vertex C.
�����}�(hKhh)��}�(hhhM�KhM hKubh�ubh�9/// @return												The barycentric point coordinate.
�����}�(hKhh)��}�(hhhM�KhM!hKubh�ubehpX/  /// Calculates the barycentric UVW coordinate of a point within a triangle.
/// @param[in] point							The point.
/// @param[in] a									Triangle vertex A.
/// @param[in] b									Triangle vertex B.
/// @param[in] c									Triangle vertex C.
/// @return												The barycentric point coordinate.
�hr}�ht�j�  �j+  �j,  �j-  �Vector�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhM�LhM#hKLubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�a�����}�(hKhh)��}�(hhhM�LhM#hKaubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�b�����}�(hKhh)��}�(hhhM�LhM#hKrubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�c�����}�(hKhh)��}�(hhhM�LhM#hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�PointInTriangle�����}�(hKhh)��}�(hhhM�NhM-hKubh�ubhj�  h]�h_jM
  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�NhM-hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�,/// Checks if a point is inside a triangle.
�����}�(hKhh)��}�(hhhM.MhM&hKubh�ubh�./// @param[in] point							The point to test.
�����}�(hKhh)��}�(hhhM[MhM'hKubh�ubh�,/// @param[in] a									Triangle vertex A.
�����}�(hKhh)��}�(hhhM�MhM(hKubh�ubh�,/// @param[in] b									Triangle vertex B.
�����}�(hKhh)��}�(hhhM�MhM)hKubh�ubh�,/// @param[in] c									Triangle vertex C.
�����}�(hKhh)��}�(hhhM�MhM*hKubh�ubh�=/// @return												True if point is inside the triangle.
�����}�(hKhh)��}�(hhhMNhM+hKubh�ubehpX  /// Checks if a point is inside a triangle.
/// @param[in] point							The point to test.
/// @param[in] a									Triangle vertex A.
/// @param[in] b									Triangle vertex B.
/// @param[in] c									Triangle vertex C.
/// @return												True if point is inside the triangle.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhM�NhM-hK9ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�a�����}�(hKhh)��}�(hhhM�NhM-hKNubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�b�����}�(hKhh)��}�(hhhMOhM-hK_ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�c�����}�(hKhh)��}�(hhhMOhM-hKpubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�PointInTriangle2D�����}�(hKhh)��}�(hhhMQhM7hKubh�ubhj�  h]�h_j�
  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMQhM7hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�0/// Checks if a point is inside triangle in 2D.
�����}�(hKhh)��}�(hhhM{OhM0hKubh�ubh�./// @param[in] point							The point to test.
�����}�(hKhh)��}�(hhhM�OhM1hKubh�ubh�,/// @param[in] a									Triangle vertex A.
�����}�(hKhh)��}�(hhhM�OhM2hKubh�ubh�,/// @param[in] b									Triangle vertex B.
�����}�(hKhh)��}�(hhhMPhM3hKubh�ubh�,/// @param[in] c									Triangle vertex C.
�����}�(hKhh)��}�(hhhM5PhM4hKubh�ubh�=/// @return												True if point is inside the triangle.
�����}�(hKhh)��}�(hhhMbPhM5hKubh�ubehpX  /// Checks if a point is inside triangle in 2D.
/// @param[in] point							The point to test.
/// @param[in] a									Triangle vertex A.
/// @param[in] b									Triangle vertex B.
/// @param[in] c									Triangle vertex C.
/// @return												True if point is inside the triangle.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector2d&�hh�point�����}�(hKhh)��}�(hhhM7QhM7hK=ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�a�����}�(hKhh)��}�(hhhMNQhM7hKTubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�b�����}�(hKhh)��}�(hhhMaQhM7hKgubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�c�����}�(hKhh)��}�(hhhMtQhM7hKzubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh� GetPointInPolygonWindingNumber2D�����}�(hKhh)��}�(hhhM2ShM?hKubh�ubhj�  h]�h_j  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM!ShM?hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�,/// Checks if a point is inside an outline.
�����}�(hKhh)��}�(hhhM�QhM:hKubh�ubh�./// @param[in] point							The point ot test.
�����}�(hKhh)��}�(hhhMRhM;hKubh�ubh�;/// @param[in] outline						The array with outline points.
�����}�(hKhh)��}�(hhhM2RhM<hKubh�ubh�O/// @return												The resulting winding number, 0 means point is outside.
�����}�(hKhh)��}�(hhhMnRhM=hKubh�ubehp��/// Checks if a point is inside an outline.
/// @param[in] point							The point ot test.
/// @param[in] outline						The array with outline points.
/// @return												The resulting winding number, 0 means point is outside.
�hr}�ht�j�  �j+  �j,  �j-  �Int�j/  �j0  ]�(j3  )��}�(h�Vector2d�hh�point�����}�(hKhh)��}�(hhhM\ShM?hKDubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector2d>&�hh�outline�����}�(hKhh)��}�(hhhM�ShM?hKhubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�%GetPointInPolygonWindingNumber2DExact�����}�(hKhh)��}�(hhhM^UhMGhKubh�ubhj�  h]�h_jC  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMMUhMGhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�F/// Checks if a point is inside an outline. Exact yet slower version.
�����}�(hKhh)��}�(hhhM�ShMBhKubh�ubh�./// @param[in] point							The point ot test.
�����}�(hKhh)��}�(hhhM/ThMChKubh�ubh�;/// @param[in] outline						The array with outline points.
�����}�(hKhh)��}�(hhhM^ThMDhKubh�ubh�O/// @return												The resulting winding number, 0 means point is outside.
�����}�(hKhh)��}�(hhhM�ThMEhKubh�ubehp��/// Checks if a point is inside an outline. Exact yet slower version.
/// @param[in] point							The point ot test.
/// @param[in] outline						The array with outline points.
/// @return												The resulting winding number, 0 means point is outside.
�hr}�ht�j�  �j+  �j,  �j-  �Int�j/  �j0  ]�(j3  )��}�(h�Vector2d�hh�point�����}�(hKhh)��}�(hhhM�UhMGhKIubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector2d>&�hh�outline�����}�(hKhh)��}�(hhhM�UhMGhKmubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh� GetPointInPolygonWindingNumber2D�����}�(hKhh)��}�(hhhMXhMPhKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�WhMPhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�,/// Checks if a point is inside an outline.
�����}�(hKhh)��}�(hhhMVhMJhKubh�ubh�./// @param[in] point							The point ot test.
�����}�(hKhh)��}�(hhhMFVhMKhKubh�ubh�;/// @param[in] outline						The array with outline points.
�����}�(hKhh)��}�(hhhMuVhMLhKubh�ubh��/// @param[out] edgeHit						In case point lies on an outline edge this will be filled with the edge index, otherwise maxon::InvalidArrayIndex.
�����}�(hKhh)��}�(hhhM�VhMMhKubh�ubh�O/// @return												The resulting winding number, 0 means point is outside.
�����}�(hKhh)��}�(hhhMBWhMNhKubh�ubehpXt  /// Checks if a point is inside an outline.
/// @param[in] point							The point ot test.
/// @param[in] outline						The array with outline points.
/// @param[out] edgeHit						In case point lies on an outline edge this will be filled with the edge index, otherwise maxon::InvalidArrayIndex.
/// @return												The resulting winding number, 0 means point is outside.
�hr}�ht�j�  �j+  �j,  �j-  �Int�j/  �j0  ]�(j3  )��}�(h�Vector2d�hh�point�����}�(hKhh)��}�(hhhM0XhMPhKDubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector2d>&�hh�outline�����}�(hKhh)��}�(hhhMTXhMPhKhubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Int&�hh�edgeHit�����}�(hKhh)��}�(hhhMbXhMPhKvubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�GetPointInPolygonWindingNumber�����}�(hKhh)��}�(hhhM`ZhMXhKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMOZhMXhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�f/// Checks if a point is inside an outline. Accepts 3d vectors but assumes points to lie in xy plane.
�����}�(hKhh)��}�(hhhM�XhMShKubh�ubh�./// @param[in] point							The point to test.
�����}�(hKhh)��}�(hhhM1YhMThKubh�ubh�;/// @param[in] outline						The array with outline points.
�����}�(hKhh)��}�(hhhM`YhMUhKubh�ubh�O/// @return												The resulting winding number. 0 means point is outside.
�����}�(hKhh)��}�(hhhM�YhMVhKubh�ubehpX  /// Checks if a point is inside an outline. Accepts 3d vectors but assumes points to lie in xy plane.
/// @param[in] point							The point to test.
/// @param[in] outline						The array with outline points.
/// @return												The resulting winding number. 0 means point is outside.
�hr}�ht�j�  �j+  �j,  �j-  �Int�j/  �j0  ]�(j3  )��}�(h�Vector�hh�point�����}�(hKhh)��}�(hhhM�ZhMXhK@ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector>&�hh�outline�����}�(hKhh)��}�(hhhM�ZhMXhKbubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�GetPointInPolygonWindingNumber�����}�(hKhh)��}�(hhhMI]hMahKubh�ubhj�  h]�h_j  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM8]hMahK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�f/// Checks if a point is inside an outline. Accepts 3d vectors but assumes points to lie in xy plane.
�����}�(hKhh)��}�(hhhM[hM[hKubh�ubh�./// @param[in] point							The point to test.
�����}�(hKhh)��}�(hhhMw[hM\hKubh�ubh�;/// @param[in] outline						The array with outline points.
�����}�(hKhh)��}�(hhhM�[hM]hKubh�ubh��/// @param[out] edgeHit						In case point lies on an outline edge, this will be filled with the edge index. Otherwise the value maxon::InvalidArrayIndex is set.
�����}�(hKhh)��}�(hhhM�[hM^hKubh�ubh�O/// @return												The resulting winding number. 0 means point is outside.
�����}�(hKhh)��}�(hhhM�\hM_hKubh�ubehpX�  /// Checks if a point is inside an outline. Accepts 3d vectors but assumes points to lie in xy plane.
/// @param[in] point							The point to test.
/// @param[in] outline						The array with outline points.
/// @param[out] edgeHit						In case point lies on an outline edge, this will be filled with the edge index. Otherwise the value maxon::InvalidArrayIndex is set.
/// @return												The resulting winding number. 0 means point is outside.
�hr}�ht�j�  �j+  �j,  �j-  �Int�j/  �j0  ]�(j3  )��}�(h�Vector�hh�point�����}�(hKhh)��}�(hhhMo]hMahK@ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector>&�hh�outline�����}�(hKhh)��}�(hhhM�]hMahKbubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Int&�hh�edgeHit�����}�(hKhh)��}�(hhhM�]hMahKpubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�PointInOutline2D�����}�(hKhh)��}�(hhhMU_hMihKubh�ubhj�  h]�h_jY  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMC_hMihK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�,/// Checks if a point is inside an outline.
�����}�(hKhh)��}�(hhhM^hMdhKubh�ubh�./// @param[in] point							The point ot test.
�����}�(hKhh)��}�(hhhM4^hMehKubh�ubh�;/// @param[in] outline						The array with outline points.
�����}�(hKhh)��}�(hhhMc^hMfhKubh�ubh�@/// @return												True if the point is inside the outline.
�����}�(hKhh)��}�(hhhM�^hMghKubh�ubehp��/// Checks if a point is inside an outline.
/// @param[in] point							The point ot test.
/// @param[in] outline						The array with outline points.
/// @return												True if the point is inside the outline.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhMt_hMihK:ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector2d>&�hh�outline�����}�(hKhh)��}�(hhhM�_hMihK^ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�PointInOutlineRobust2D�����}�(hKhh)��}�(hhhMNahMqhKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM<ahMqhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�,/// Checks if a point is inside an outline.
�����}�(hKhh)��}�(hhhM `hMlhKubh�ubh�./// @param[in] point							The point ot test.
�����}�(hKhh)��}�(hhhM-`hMmhKubh�ubh�;/// @param[in] outline						The array with outline points.
�����}�(hKhh)��}�(hhhM\`hMnhKubh�ubh�@/// @return												True if the point is inside the outline.
�����}�(hKhh)��}�(hhhM�`hMohKubh�ubehp��/// Checks if a point is inside an outline.
/// @param[in] point							The point ot test.
/// @param[in] outline						The array with outline points.
/// @return												True if the point is inside the outline.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhMsahMqhK@ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector2d>&�hh�outline�����}�(hKhh)��}�(hhhM�ahMqhKdubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�CalculateBisector�����}�(hKhh)��}�(hhhM2dhM}hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMdhM}hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�Y/// Calculates the 3D bisector angle using an up vector to identify the sliding surface.
�����}�(hKhh)��}�(hhhM�ahMthKubh�ubh�?/// A custom weight for each side can optionally be specified.
�����}�(hKhh)��}�(hhhMYbhMuhKubh�ubh�(/// @param[in] v1									First vector.
�����}�(hKhh)��}�(hhhM�bhMvhKubh�ubh�)/// @param[in] v2									Second vector.
�����}�(hKhh)��}�(hhhM�bhMwhKubh�ubh�)/// @param[in] up									The up vector.
�����}�(hKhh)��}�(hhhM�bhMxhKubh�ubh�8/// @param[in] w1									Optional weight value for v1.
�����}�(hKhh)��}�(hhhMchMyhKubh�ubh�8/// @param[in] w2									Optional weight value for v2.
�����}�(hKhh)��}�(hhhMOchMzhKubh�ubh�2/// @return												The bisector angle vector.
�����}�(hKhh)��}�(hhhM�chM{hKubh�ubehpX�  /// Calculates the 3D bisector angle using an up vector to identify the sliding surface.
/// A custom weight for each side can optionally be specified.
/// @param[in] v1									First vector.
/// @param[in] v2									Second vector.
/// @param[in] up									The up vector.
/// @param[in] w1									Optional weight value for v1.
/// @param[in] w2									Optional weight value for v2.
/// @return												The bisector angle vector.
�hr}�ht�j�  �j+  �j,  �j-  �Vector�j/  �j0  ]�(j3  )��}�(h�const Vector&��      hh�v1�����}�(hKhh)��}�(hhhMRdhM}hK=ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�v2�����}�(hKhh)��}�(hhhMddhM}hKOubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�up�����}�(hKhh)��}�(hhhMvdhM}hKaubh�ubj=  �Vector(0,1,0)�j>  �j?  �j@  �ubj3  )��}�(h�Float�hh�w1�����}�(hKhh)��}�(hhhM�dhM}hK}ubh�ubj=  �1.0�j>  �j?  �j@  �ubj3  )��}�(h�Float�hh�w2�����}�(hKhh)��}�(hhhM�dhM}hK�ubh�ubj=  �1.0�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�CalculateCircumcenter2D�����}�(hKhh)��}�(hhhM�ghM�hKubh�ubhj�  h]�h_jI  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMyghM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�A/// Calculates the circumcenter and radius of a planar triangle.
�����}�(hKhh)��}�(hhhMehM�hKubh�ubh�+/// @param[in] a									Triangle point A.
�����}�(hKhh)��}�(hhhMMehM�hKubh�ubh�+/// @param[in] b									Triangle point B.
�����}�(hKhh)��}�(hhhMyehM�hKubh�ubh�+/// @param[in] c									Triangle point C.
�����}�(hKhh)��}�(hhhM�ehM�hKubh�ubh�3/// @param[out] center						Triangle circumcenter.
�����}�(hKhh)��}�(hhhM�ehM�hKubh�ubh�Y/// @param[out] sqrRad						Squared radius of the circle defined by the triangle points.
�����}�(hKhh)��}�(hhhMfhM�hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM_fhM�hKubh�ubh�j/// @return												False if the points are collinear or if the triangle is collapsed, true otherwise.
�����}�(hKhh)��}�(hhhM�fhM�hKubh�ubehpX  /// Calculates the circumcenter and radius of a planar triangle.
/// @param[in] a									Triangle point A.
/// @param[in] b									Triangle point B.
/// @param[in] c									Triangle point C.
/// @param[out] center						Triangle circumcenter.
/// @param[out] sqrRad						Squared radius of the circle defined by the triangle points.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												False if the points are collinear or if the triangle is collapsed, true otherwise.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector2d&�hh�a�����}�(hKhh)��}�(hhhM�ghM�hKCubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�b�����}�(hKhh)��}�(hhhM�ghM�hKVubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�c�����}�(hKhh)��}�(hhhM�ghM�hKiubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�	Vector2d&�hh�center�����}�(hKhh)��}�(hhhM�ghM�hKvubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float&�hh�sqrRad�����}�(hKhh)��}�(hhhM�ghM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhMhhM�hK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�CalculateCircumcenter�����}�(hKhh)��}�(hhhM�jhM�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�jhM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�:/// Calculates the circumcenter and radius of a triangle.
�����}�(hKhh)��}�(hhhM�hhM�hKubh�ubh�+/// @param[in] a									Triangle point A.
�����}�(hKhh)��}�(hhhM�hhM�hKubh�ubh�+/// @param[in] b									Triangle point B.
�����}�(hKhh)��}�(hhhM�hhM�hKubh�ubh�+/// @param[in] c									Triangle point C.
�����}�(hKhh)��}�(hhhMihM�hKubh�ubh�3/// @param[out] center						Triangle circumcenter.
�����}�(hKhh)��}�(hhhMFihM�hKubh�ubh�P/// @param[out] rad								Radius of the circle defined by the triangle points.
�����}�(hKhh)��}�(hhhMzihM�hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM�ihM�hKubh�ubh�j/// @return												False if the points are collinear or if the triangle is collapsed, true otherwise.
�����}�(hKhh)��}�(hhhMjhM�hKubh�ubehpX�  /// Calculates the circumcenter and radius of a triangle.
/// @param[in] a									Triangle point A.
/// @param[in] b									Triangle point B.
/// @param[in] c									Triangle point C.
/// @param[out] center						Triangle circumcenter.
/// @param[out] rad								Radius of the circle defined by the triangle points.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												False if the points are collinear or if the triangle is collapsed, true otherwise.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�a�����}�(hKhh)��}�(hhhMkhM�hK?ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�b�����}�(hKhh)��}�(hhhM,khM�hKPubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�c�����}�(hKhh)��}�(hhhM=khM�hKaubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�center�����}�(hKhh)��}�(hhhMHkhM�hKlubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float&�hh�rad�����}�(hKhh)��}�(hhhMWkhM�hK{ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhMbkhM�hK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�SegmentsIntersectionTest2D�����}�(hKhh)��}�(hhhM�mhM�hKubh�ubhj�  h]�h_j?  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�mhM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�2/// Checks if two segments intersect in 2D space.
�����}�(hKhh)��}�(hhhM�khM�hKubh�ubh�7/// @param[in] segment1Point1			First segment point 1.
�����}�(hKhh)��}�(hhhMlhM�hKubh�ubh�7/// @param[in] segment1Point2			First segment point 2.
�����}�(hKhh)��}�(hhhMQlhM�hKubh�ubh�8/// @param[in] segment2Point1			Second segment point 1.
�����}�(hKhh)��}�(hhhM�lhM�hKubh�ubh�8/// @param[in] segment2Point2			Second segment point 2.
�����}�(hKhh)��}�(hhhM�lhM�hKubh�ubh�=/// @return												True if the segments intersect in 2D.
�����}�(hKhh)��}�(hhhM�lhM�hKubh�ubehpXM  /// Checks if two segments intersect in 2D space.
/// @param[in] segment1Point1			First segment point 1.
/// @param[in] segment1Point2			First segment point 2.
/// @param[in] segment2Point1			Second segment point 1.
/// @param[in] segment2Point2			Second segment point 2.
/// @return												True if the segments intersect in 2D.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector2d&�hh�segment1Point1�����}�(hKhh)��}�(hhhM�mhM�hKFubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�segment1Point2�����}�(hKhh)��}�(hhhM�mhM�hKfubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�segment2Point1�����}�(hKhh)��}�(hhhMnhM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�segment2Point2�����}�(hKhh)��}�(hhhM9nhM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�SegmentRayIntersectionTest2D�����}�(hKhh)��}�(hhhM]phM�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMKphM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�=/// Checks if a segment is intersected by a ray in 2D space.
�����}�(hKhh)��}�(hhhM�nhM�hKubh�ubh�0/// @param[in] segmentPoint1			Segment point 1.
�����}�(hKhh)��}�(hhhM�nhM�hKubh�ubh�0/// @param[in] segmentPoint2			Segment point 2.
�����}�(hKhh)��}�(hhhMohM�hKubh�ubh�1/// @param[in] rayStartPoint			Line start point.
�����}�(hKhh)��}�(hhhMHohM�hKubh�ubh�//// @param[in] rayDirection				Line Direction.
�����}�(hKhh)��}�(hhhMzohM�hKubh�ubh�=/// @return												True if the segments intersect in 2D.
�����}�(hKhh)��}�(hhhM�ohM�hKubh�ubehpX:  /// Checks if a segment is intersected by a ray in 2D space.
/// @param[in] segmentPoint1			Segment point 1.
/// @param[in] segmentPoint2			Segment point 2.
/// @param[in] rayStartPoint			Line start point.
/// @param[in] rayDirection				Line Direction.
/// @return												True if the segments intersect in 2D.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector2d&�hh�segmentPoint1�����}�(hKhh)��}�(hhhM�phM�hKHubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�segmentPoint2�����}�(hKhh)��}�(hhhM�phM�hKgubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�rayStartPoint�����}�(hKhh)��}�(hhhM�phM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�rayDirection�����}�(hKhh)��}�(hhhM�phM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectSegments2D�����}�(hKhh)��}�(hhhM�shM�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�shM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�`/// Checks if two segment intersect in 2D space and calculates the intersection point (if any).
�����}�(hKhh)��}�(hhhMTqhM�hKubh�ubh�5/// @param[in] segment1Point1			First segment point.
�����}�(hKhh)��}�(hhhM�qhM�hKubh�ubh�5/// @param[in] segment1Point2			First segment point.
�����}�(hKhh)��}�(hhhM�qhM�hKubh�ubh�6/// @param[in] segment2Point1			Second segment point.
�����}�(hKhh)��}�(hhhM!rhM�hKubh�ubh�6/// @param[in] segment2Point2			Second segment point.
�����}�(hKhh)��}�(hhhMXrhM�hKubh�ubh�M/// @param[out] intersectionPoint	Calculated intersection point in xy plane.
�����}�(hKhh)��}�(hhhM�rhM�hKubh�ubh�\/// @param[in] tolerance					Geometric linear tolerance for the operation by default = 0.0.
�����}�(hKhh)��}�(hhhM�rhM�hKubh�ubh�=/// @return												True if the segments intersect in 2D.
�����}�(hKhh)��}�(hhhM:shM�hKubh�ubehpX  /// Checks if two segment intersect in 2D space and calculates the intersection point (if any).
/// @param[in] segment1Point1			First segment point.
/// @param[in] segment1Point2			First segment point.
/// @param[in] segment2Point1			Second segment point.
/// @param[in] segment2Point2			Second segment point.
/// @param[out] intersectionPoint	Calculated intersection point in xy plane.
/// @param[in] tolerance					Geometric linear tolerance for the operation by default = 0.0.
/// @return												True if the segments intersect in 2D.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector2d&�hh�segment1Point1�����}�(hKhh)��}�(hhhMthM�hK?ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�segment1Point2�����}�(hKhh)��}�(hhhM1thM�hK_ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�segment2Point1�����}�(hKhh)��}�(hhhMQthM�hKubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�segment2Point2�����}�(hKhh)��}�(hhhMqthM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�	Vector2d&�hh�intersectionPoint�����}�(hKhh)��}�(hhhM�thM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM�thM�hK�ubh�ubj=  �0.0_f�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�LineLineDistance�����}�(hKhh)��}�(hhhM�xhM�hKubh�ubhj�  h]�h_jr  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�xhM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�m/// Calculates min distance for given lines, fill param1/param2 with parametrized distance form first point.
�����}�(hKhh)��}�(hhhMuhM�hKubh�ubh�5/// @param[in] line1Point					A point on first line.
�����}�(hKhh)��}�(hhhM�uhM�hKubh�ubh�:/// @param[in] line1Dir						First line direction vector.
�����}�(hKhh)��}�(hhhM�uhM�hKubh�ubh�6/// @param[in] line2Point					A point on second line.
�����}�(hKhh)��}�(hhhM�uhM�hKubh�ubh�;/// @param[in] line2Dir						Second line direction vector.
�����}�(hKhh)��}�(hhhM,vhM�hKubh�ubh�T/// @param[out] parallel					The function set it true if the tow line are parallel.
�����}�(hKhh)��}�(hhhMhvhM�hKubh�ubh��/// @param[out] param1						Parametrized distance from fist line first point where the distance is calculated (p = line1Point + !line1Dir * param1)
�����}�(hKhh)��}�(hhhM�vhM�hKubh�ubh��/// @param[out] param2						Parametrized distance from second line first point where the distance is calculated (p = line2Point + !line2Dir * param2)
�����}�(hKhh)��}�(hhhMRwhM�hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM�whM�hKubh�ubh�(/// @return												Distance Vector.
�����}�(hKhh)��}�(hhhM5xhM�hKubh�ubehpX>  /// Calculates min distance for given lines, fill param1/param2 with parametrized distance form first point.
/// @param[in] line1Point					A point on first line.
/// @param[in] line1Dir						First line direction vector.
/// @param[in] line2Point					A point on second line.
/// @param[in] line2Dir						Second line direction vector.
/// @param[out] parallel					The function set it true if the tow line are parallel.
/// @param[out] param1						Parametrized distance from fist line first point where the distance is calculated (p = line1Point + !line1Dir * param1)
/// @param[out] param2						Parametrized distance from second line first point where the distance is calculated (p = line2Point + !line2Dir * param2)
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												Distance Vector.
�hr}�ht�j�  �j+  �j,  �j-  �Vector�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�
line1Point�����}�(hKhh)��}�(hhhM�xhM�hK<ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�line1Dir�����}�(hKhh)��}�(hhhMyhM�hKVubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�
line2Point�����}�(hKhh)��}�(hhhM'yhM�hKoubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�line2Dir�����}�(hKhh)��}�(hhhMAyhM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool&�hh�parallel�����}�(hKhh)��}�(hhhMQyhM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float&�hh�param1�����}�(hKhh)��}�(hhhMbyhM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float&�hh�param2�����}�(hKhh)��}�(hhhMqyhM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhMyhM�hK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�PointInSegment2D�����}�(hKhh)��}�(hhhM)|hM�hKubh�ubhj�  h]�h_j  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM|hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h��/// Checks if a point is on a line segment in 2D. The tolerance value is used for the colinearity test only, not for the boundary test.
�����}�(hKhh)��}�(hhhMzhM�hKubh�ubh�//// @param[in] point							The point to check.
�����}�(hKhh)��}�(hhhM�zhM�hKubh�ubh�2/// @param[in] segmentPoint1			1st Segment point.
�����}�(hKhh)��}�(hhhM�zhM�hKubh�ubh�2/// @param[in] segmentPoint2			2nd Segment point.
�����}�(hKhh)��}�(hhhM�zhM�hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM"{hM�hKubh�ubh�E/// @return												True if point is on segment, otherwise false.
�����}�(hKhh)��}�(hhhMn{hM�hKubh�ubehpX�  /// Checks if a point is on a line segment in 2D. The tolerance value is used for the colinearity test only, not for the boundary test.
/// @param[in] point							The point to check.
/// @param[in] segmentPoint1			1st Segment point.
/// @param[in] segmentPoint2			2nd Segment point.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if point is on segment, otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector2d&�hh�point�����}�(hKhh)��}�(hhhMJ|hM�hK<ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�segmentPoint1�����}�(hKhh)��}�(hhhMa|hM�hKSubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�segmentPoint2�����}�(hKhh)��}�(hhhM�|hM�hKrubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM�|hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�PointInSegment�����}�(hKhh)��}�(hhhM%hM�hKubh�ubhj�  h]�h_jg  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMhM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h��/// Checks if a point is on a line segment in 3D. The tolerance value is used for the colinearity test only, not for the boundary test.
�����}�(hKhh)��}�(hhhM�|hM�hKubh�ubh�//// @param[in] point							The point to check.
�����}�(hKhh)��}�(hhhM�}hM�hKubh�ubh�2/// @param[in] segmentPoint1			1st Segment point.
�����}�(hKhh)��}�(hhhM�}hM�hKubh�ubh�2/// @param[in] segmentPoint2			2nd Segment point.
�����}�(hKhh)��}�(hhhM�}hM�hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM~hM�hKubh�ubh�E/// @return												True if point is on segment, otherwise false.
�����}�(hKhh)��}�(hhhMj~hM�hKubh�ubehpX�  /// Checks if a point is on a line segment in 3D. The tolerance value is used for the colinearity test only, not for the boundary test.
/// @param[in] point							The point to check.
/// @param[in] segmentPoint1			1st Segment point.
/// @param[in] segmentPoint2			2nd Segment point.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if point is on segment, otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhMBhM�hK8ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�segmentPoint1�����}�(hKhh)��}�(hhhMWhM�hKMubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�segmentPoint2�����}�(hKhh)��}�(hhhMthM�hKjubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM�hM�hKubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�PointInHalfLine�����}�(hKhh)��}�(hhhM؁hM�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMƁhM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�*/// Checks if a point is on a half line .
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�//// @param[in] point							The point to check.
�����}�(hKhh)��}�(hhhM8�hM�hKubh�ubh�2/// @param[in] halfLineOrigin			Half line origin.
�����}�(hKhh)��}�(hhhMh�hM�hKubh�ubh�3/// @param[in] halfLineDir				Half line direction.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhMπhM�hKubh�ubh�G/// @return												True if point is on half line, otherwise false.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubehpXP  /// Checks if a point is on a half line .
/// @param[in] point							The point to check.
/// @param[in] halfLineOrigin			Half line origin.
/// @param[in] halfLineDir				Half line direction.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if point is on half line, otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhM��hM�hK9ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�halfLineOrigin�����}�(hKhh)��}�(hhhM�hM�hKNubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�halfLineDir�����}�(hKhh)��}�(hhhM)�hM�hKlubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM<�hM�hKubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectLines�����}�(hKhh)��}�(hhhMk�hM�hKubh�ubhj�  h]�h_j!  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMY�hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�j/// Checks for intersection between two lines and fills intersectionPoint with the intersection position.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�3/// @param[in] line1Point					A point on 1st line.
�����}�(hKhh)��}�(hhhM+�hM�hKubh�ubh�8/// @param[in] line1Dir						1st line direction vector.
�����}�(hKhh)��}�(hhhM_�hM�hKubh�ubh�3/// @param[in] line2Point					A point on 2nd line.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�8/// @param[in] line2Dir						2nd line direction vector.
�����}�(hKhh)��}�(hhhM̃hM�hKubh�ubh�[/// @param[out] intersectionPoint	Resulting intersection position if intersection happens.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhMa�hM�hKubh�ubh�H/// @return												True if an intersection happens otherwise false.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubehpX.  /// Checks for intersection between two lines and fills intersectionPoint with the intersection position.
/// @param[in] line1Point					A point on 1st line.
/// @param[in] line1Dir						1st line direction vector.
/// @param[in] line2Point					A point on 2nd line.
/// @param[in] line2Dir						2nd line direction vector.
/// @param[out] intersectionPoint	Resulting intersection position if intersection happens.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�
line1Point�����}�(hKhh)��}�(hhhM��hM�hK8ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�line1Dir�����}�(hKhh)��}�(hhhM��hM�hKRubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�
line2Point�����}�(hKhh)��}�(hhhM��hM�hKjubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�line2Dir�����}�(hKhh)��}�(hhhMԅhM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhM�hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectLineSegment�����}�(hKhh)��}�(hhhM �hM�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�d/// Checks for line vs. segment intersection and fills intersection with the intersection position.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�2/// @param[in] linePoint					A point on the line.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�3/// @param[in] lineDir						Line direction vector.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�4/// @param[in] segmentPoint1			First segment point.
�����}�(hKhh)��}�(hhhMO�hM�hKubh�ubh�5/// @param[in] segmentPoint2			Second segment point.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�[/// @param[out] intersectionPoint	Resulting intersection position if intersection happens.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�H/// @return												True if an intersection happens otherwise false.
�����}�(hKhh)��}�(hhhMb�hM�hKubh�ubehpX   /// Checks for line vs. segment intersection and fills intersection with the intersection position.
/// @param[in] linePoint					A point on the line.
/// @param[in] lineDir						Line direction vector.
/// @param[in] segmentPoint1			First segment point.
/// @param[in] segmentPoint2			Second segment point.
/// @param[out] intersectionPoint	Resulting intersection position if intersection happens.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�	linePoint�����}�(hKhh)��}�(hhhMC�hM�hK>ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�lineDir�����}�(hKhh)��}�(hhhM\�hM�hKWubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�segmentPoint1�����}�(hKhh)��}�(hhhMs�hM�hKnubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�segmentPoint2�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectSegments�����}�(hKhh)��}�(hhhM�hMhKubh�ubhj�  h]�h_j  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hMhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�g/// Checks for segment vs. segment intersection and fills intersection with the intersection position.
�����}�(hKhh)��}�(hhhMD�hM�hKubh�ubh�;/// @param[in] segment1Point1			First Segment first point.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�</// @param[in] segment1Point2			First Segment second point.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�</// @param[in] segment2Point1			Second Segment first point.
�����}�(hKhh)��}�(hhhM%�hM�hKubh�ubh�=/// @param[in] segment2Point2			Second Segment second point.
�����}�(hKhh)��}�(hhhMb�hM hKubh�ubh�[/// @param[out] intersectionPoint	Resulting intersection position if intersection happens.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�H/// @return												True if an intersection happens otherwise false.
�����}�(hKhh)��}�(hhhMH�hMhKubh�ubehpXE  /// Checks for segment vs. segment intersection and fills intersection with the intersection position.
/// @param[in] segment1Point1			First Segment first point.
/// @param[in] segment1Point2			First Segment second point.
/// @param[in] segment2Point1			Second Segment first point.
/// @param[in] segment2Point2			Second Segment second point.
/// @param[out] intersectionPoint	Resulting intersection position if intersection happens.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�segment1Point1�����}�(hKhh)��}�(hhhM&�hMhK;ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�segment1Point2�����}�(hKhh)��}�(hhhMD�hMhKYubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�segment2Point1�����}�(hKhh)��}�(hhhMb�hMhKwubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�segment2Point2�����}�(hKhh)��}�(hhhM��hMhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhM��hMhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM��hMhK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectHalfLines�����}�(hKhh)��}�(hhhM��hMhKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hMhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�j/// Checks for halfline/halfline intersection and fills intersectionPoint with the intersection position.
�����}�(hKhh)��}�(hhhM5�hMhKubh�ubh�;/// @param[in] halfLine1Origin		Start point 1st half line.
�����}�(hKhh)��}�(hhhM��hM	hKubh�ubh�?/// @param[in] halfLine1Dir				1st half line direction vector.
�����}�(hKhh)��}�(hhhM܎hM
hKubh�ubh�;/// @param[in] halfLine2Origin		Start point 2nd half line.
�����}�(hKhh)��}�(hhhM�hMhKubh�ubh�?/// @param[in] halfLine2Dir				2nd half line direction vector.
�����}�(hKhh)��}�(hhhMX�hMhKubh�ubh�[/// @param[out] intersectionPoint	Resulting intersection position if intersection happens.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM�hMhKubh�ubh�H/// @return												True if an intersection happens otherwise false.
�����}�(hKhh)��}�(hhhM@�hMhKubh�ubehpXL  /// Checks for halfline/halfline intersection and fills intersectionPoint with the intersection position.
/// @param[in] halfLine1Origin		Start point 1st half line.
/// @param[in] halfLine1Dir				1st half line direction vector.
/// @param[in] halfLine2Origin		Start point 2nd half line.
/// @param[in] halfLine2Dir				2nd half line direction vector.
/// @param[out] intersectionPoint	Resulting intersection position if intersection happens.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�halfLine1Origin�����}�(hKhh)��}�(hhhM�hMhK<ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�halfLine1Dir�����}�(hKhh)��}�(hhhM>�hMhK[ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�halfLine2Origin�����}�(hKhh)��}�(hhhMZ�hMhKwubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�halfLine2Dir�����}�(hKhh)��}�(hhhMy�hMhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhM��hMhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM��hMhK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectLineHalfLine�����}�(hKhh)��}�(hhhM̔hMhKubh�ubhj�  h]�h_j  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hMhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�f/// Checks for line/halfline intersection and fills intersectionPoint with the intersection position.
�����}�(hKhh)��}�(hhhM,�hMhKubh�ubh�2/// @param[in] linePoint					A point on the line.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�3/// @param[in] lineDir						Line direction vector.
�����}�(hKhh)��}�(hhhMƒhMhKubh�ubh�:/// @param[in] halfLineOrigin			Start point of Half line.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�:/// @param[in] halfLineDir				Half line direction vector.
�����}�(hKhh)��}�(hhhM5�hMhKubh�ubh�Q/// @param[out] intersectionPoint	Intersection position if intersection happens.
�����}�(hKhh)��}�(hhhMp�hMhKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhMhMhKubh�ubh�H/// @return												True if an intersection happens otherwise false.
�����}�(hKhh)��}�(hhhM�hMhKubh�ubehpX#  /// Checks for line/halfline intersection and fills intersectionPoint with the intersection position.
/// @param[in] linePoint					A point on the line.
/// @param[in] lineDir						Line direction vector.
/// @param[in] halfLineOrigin			Start point of Half line.
/// @param[in] halfLineDir				Half line direction vector.
/// @param[out] intersectionPoint	Intersection position if intersection happens.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�	linePoint�����}�(hKhh)��}�(hhhM�hMhK?ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�lineDir�����}�(hKhh)��}�(hhhM	�hMhKXubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�halfLineOrigin�����}�(hKhh)��}�(hhhM �hMhKoubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�halfLineDir�����}�(hKhh)��}�(hhhM>�hMhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhMS�hMhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhMl�hMhK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectHalfLineSegment�����}�(hKhh)��}�(hhhM��hM)hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hM)hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�i/// Checks for halfLine/segment Intersection and fills intersectionPoint with the intersection position.
�����}�(hKhh)��}�(hhhM�hM hKubh�ubh�:/// @param[in] halfLineOrigin			Start point of Half line.
�����}�(hKhh)��}�(hhhMZ�hM!hKubh�ubh�:/// @param[in] halfLineDir				Half line direction vector.
�����}�(hKhh)��}�(hhhM��hM"hKubh�ubh�4/// @param[in] segmentPoint1			First Segment point.
�����}�(hKhh)��}�(hhhMЖhM#hKubh�ubh�5/// @param[in] segmentPoint2			Second Segment point.
�����}�(hKhh)��}�(hhhM�hM$hKubh�ubh�Q/// @param[out] intersectionPoint	Intersection position if intersection happens.
�����}�(hKhh)��}�(hhhM;�hM%hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM��hM&hKubh�ubh�H/// @return												True if an intersection happens otherwise false.
�����}�(hKhh)��}�(hhhMٗhM'hKubh�ubehpX*  /// Checks for halfLine/segment Intersection and fills intersectionPoint with the intersection position.
/// @param[in] halfLineOrigin			Start point of Half line.
/// @param[in] halfLineDir				Half line direction vector.
/// @param[in] segmentPoint1			First Segment point.
/// @param[in] segmentPoint2			Second Segment point.
/// @param[out] intersectionPoint	Intersection position if intersection happens.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�halfLineOrigin�����}�(hKhh)��}�(hhhM��hM)hKBubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�halfLineDir�����}�(hKhh)��}�(hhhMܘhM)hK`ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�segmentPoint1�����}�(hKhh)��}�(hhhM��hM)hK{ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�segmentPoint2�����}�(hKhh)��}�(hhhM�hM)hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhM+�hM)hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhMD�hM)hK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectPlanes�����}�(hKhh)��}�(hhhMY�hM6hKubh�ubhj�  h]�h_j  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMG�hM6hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�I/// Checks for plane/plane intersection and fills the intersection line.
�����}�(hKhh)��}�(hhhMșhM,hKubh�ubh�-/// @param[in] plane1Point				Plane 1 point.
�����}�(hKhh)��}�(hhhM�hM-hKubh�ubh�//// @param[in] plane1Normal				Plane 1 normal.
�����}�(hKhh)��}�(hhhM@�hM.hKubh�ubh�-/// @param[in] plane2Point				Plane 2 point.
�����}�(hKhh)��}�(hhhMp�hM/hKubh�ubh�//// @param[in] plane2Normal				Plane 2 normal.
�����}�(hKhh)��}�(hhhM��hM0hKubh�ubh�A/// @param[out] resLinePoint			A point on the intersection line.
�����}�(hKhh)��}�(hhhMΚhM1hKubh�ubh�>/// @param[out] resLineDirection	Intersection line direction.
�����}�(hKhh)��}�(hhhM�hM2hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhMO�hM3hKubh�ubh�H/// @return												True if an intersection happens otherwise false.
�����}�(hKhh)��}�(hhhM��hM4hKubh�ubehpX  /// Checks for plane/plane intersection and fills the intersection line.
/// @param[in] plane1Point				Plane 1 point.
/// @param[in] plane1Normal				Plane 1 normal.
/// @param[in] plane2Point				Plane 2 point.
/// @param[in] plane2Normal				Plane 2 normal.
/// @param[out] resLinePoint			A point on the intersection line.
/// @param[out] resLineDirection	Intersection line direction.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�plane1Point�����}�(hKhh)��}�(hhhMw�hM6hK9ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�plane1Normal�����}�(hKhh)��}�(hhhM��hM6hKTubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�plane2Point�����}�(hKhh)��}�(hhhM��hM6hKpubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�plane2Normal�����}�(hKhh)��}�(hhhMɜhM6hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�resLinePoint�����}�(hKhh)��}�(hhhMߜhM6hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�resLineDirection�����}�(hKhh)��}�(hhhM��hM6hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM�hM6hK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectLinePlane�����}�(hKhh)��}�(hhhM5�hMBhKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM#�hMBhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�c/// Checks for plane/Line intersection and fills intersectionPoint with the intersection position.
�����}�(hKhh)��}�(hhhM��hM9hKubh�ubh�./// @param[in] linePoint					A point on line.
�����}�(hKhh)��}�(hhhM��hM:hKubh�ubh�3/// @param[in] lineDir						Line direction vector.
�����}�(hKhh)��}�(hhhM$�hM;hKubh�ubh�+/// @param[in] planePoint					Plane point.
�����}�(hKhh)��}�(hhhMX�hM<hKubh�ubh�,/// @param[in] planeNormal				Plane normal.
�����}�(hKhh)��}�(hhhM��hM=hKubh�ubh�Q/// @param[out] intersectionPoint	Intersection position if intersection happens.
�����}�(hKhh)��}�(hhhM��hM>hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM�hM?hKubh�ubh�p/// @return												True if an intersection happens  otherwise false. (line is parallel or lie on the plane)
�����}�(hKhh)��}�(hhhMO�hM@hKubh�ubehpX'  /// Checks for plane/Line intersection and fills intersectionPoint with the intersection position.
/// @param[in] linePoint					A point on line.
/// @param[in] lineDir						Line direction vector.
/// @param[in] planePoint					Plane point.
/// @param[in] planeNormal				Plane normal.
/// @param[out] intersectionPoint	Intersection position if intersection happens.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens  otherwise false. (line is parallel or lie on the plane)
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�	linePoint�����}�(hKhh)��}�(hhhMV�hMBhK<ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�lineDir�����}�(hKhh)��}�(hhhMo�hMBhKUubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�
planePoint�����}�(hKhh)��}�(hhhM��hMBhKlubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�planeNormal�����}�(hKhh)��}�(hhhM��hMBhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhM��hMBhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhMΠhMBhK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectLinePlane�����}�(hKhh)��}�(hhhM��hMNhKubh�ubhj�  h]�h_j  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hMNhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�c/// Checks for plane/line intersection and fills intersectionPoint with the intersection position.
�����}�(hKhh)��}�(hhhMR�hMEhKubh�ubh�./// @param[in] linePoint					A point on line.
�����}�(hKhh)��}�(hhhM��hMFhKubh�ubh�3/// @param[in] lineDir						Line direction vector.
�����}�(hKhh)��}�(hhhM�hMGhKubh�ubh�+/// @param[in] planePoint					Plane point.
�����}�(hKhh)��}�(hhhM�hMHhKubh�ubh�,/// @param[in] planeNormal				Plane normal.
�����}�(hKhh)��}�(hhhME�hMIhKubh�ubh�Q/// @param[out] intersectionPoint	Intersection position if intersection happens.
�����}�(hKhh)��}�(hhhMr�hMJhKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhMĢhMKhKubh�ubh�p/// @return												True if an intersection happens  otherwise false. (line is parallel or lie on the plane)
�����}�(hKhh)��}�(hhhM�hMLhKubh�ubehpX'  /// Checks for plane/line intersection and fills intersectionPoint with the intersection position.
/// @param[in] linePoint					A point on line.
/// @param[in] lineDir						Line direction vector.
/// @param[in] planePoint					Plane point.
/// @param[in] planeNormal				Plane normal.
/// @param[out] intersectionPoint	Intersection position if intersection happens.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens  otherwise false. (line is parallel or lie on the plane)
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�	linePoint�����}�(hKhh)��}�(hhhM�hMNhK<ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�lineDir�����}�(hKhh)��}�(hhhM0�hMNhKUubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�
planePoint�����}�(hKhh)��}�(hhhMG�hMNhKlubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�planeNormal�����}�(hKhh)��}�(hhhMa�hMNhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhMv�hMNhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float&�hh�param�����}�(hKhh)��}�(hhhM��hMNhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool&�hh�	samePlane�����}�(hKhh)��}�(hhhM��hMNhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM��hMNhK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectSegmentPlane�����}�(hKhh)��}�(hhhM��hMZhKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hMZhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�f/// Checks for plane/segment intersection and fills intersectionPoint with the intersection position.
�����}�(hKhh)��}�(hhhM2�hMQhKubh�ubh�0/// @param[in] segmentPoint1			Segment point 1.
�����}�(hKhh)��}�(hhhM��hMRhKubh�ubh�0/// @param[in] segmentPoint2			Segment point 2.
�����}�(hKhh)��}�(hhhMʥhMShKubh�ubh�+/// @param[in] planePoint					Plane point.
�����}�(hKhh)��}�(hhhM��hMThKubh�ubh�,/// @param[in] planeNormal				Plane normal.
�����}�(hKhh)��}�(hhhM'�hMUhKubh�ubh�Q/// @param[out] intersectionPoint	Intersection position if intersection happens.
�����}�(hKhh)��}�(hhhMT�hMVhKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM��hMWhKubh�ubh�I/// @return												True if an intersection happens  otherwise false.
�����}�(hKhh)��}�(hhhM�hMXhKubh�ubehpX  /// Checks for plane/segment intersection and fills intersectionPoint with the intersection position.
/// @param[in] segmentPoint1			Segment point 1.
/// @param[in] segmentPoint2			Segment point 2.
/// @param[in] planePoint					Plane point.
/// @param[in] planeNormal				Plane normal.
/// @param[out] intersectionPoint	Intersection position if intersection happens.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens  otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�segmentPoint1�����}�(hKhh)��}�(hhhMէhMZhK?ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�segmentPoint2�����}�(hKhh)��}�(hhhM�hMZhK\ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�
planePoint�����}�(hKhh)��}�(hhhM�hMZhKyubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�planeNormal�����}�(hKhh)��}�(hhhM)�hMZhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhM>�hMZhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhMW�hMZhK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectHalfLinePlane�����}�(hKhh)��}�(hhhMf�hMfhKubh�ubhj�  h]�h_j  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMT�hMfhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�g/// Checks for plane/halfline intersection and fills intersectionPoint with the intersection position.
�����}�(hKhh)��}�(hhhMۨhM]hKubh�ubh�1/// @param[in] halfLinePoint			Half line Origin.
�����}�(hKhh)��}�(hhhMC�hM^hKubh�ubh�:/// @param[in] halfLineDir				Half line direction vector.
�����}�(hKhh)��}�(hhhMu�hM_hKubh�ubh�+/// @param[in] planePoint					Plane point.
�����}�(hKhh)��}�(hhhM��hM`hKubh�ubh�,/// @param[in] planeNormal				Plane normal.
�����}�(hKhh)��}�(hhhMܩhMahKubh�ubh�Q/// @param[out] intersectionPoint	Intersection position if intersection happens.
�����}�(hKhh)��}�(hhhM	�hMbhKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM[�hMchKubh�ubh�I/// @return												True if an intersection happens  otherwise false.
�����}�(hKhh)��}�(hhhM��hMdhKubh�ubehpX  /// Checks for plane/halfline intersection and fills intersectionPoint with the intersection position.
/// @param[in] halfLinePoint			Half line Origin.
/// @param[in] halfLineDir				Half line direction vector.
/// @param[in] planePoint					Plane point.
/// @param[in] planeNormal				Plane normal.
/// @param[out] intersectionPoint	Intersection position if intersection happens.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens  otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�halfLinePoint�����}�(hKhh)��}�(hhhM��hMfhK@ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�halfLineDir�����}�(hKhh)��}�(hhhM��hMfhK]ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�
planePoint�����}�(hKhh)��}�(hhhMëhMfhKxubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�planeNormal�����}�(hKhh)��}�(hhhMݫhMfhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhM�hMfhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM�hMfhK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectLineTriangle�����}�(hKhh)��}�(hhhM˯hMthKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hMthK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�f/// Checks for line/triangle intersection and fills intersectionPoint with the intersection position.
�����}�(hKhh)��}�(hhhM��hMihKubh�ubh�2/// @param[in] linePoint					A point on the line.
�����}�(hKhh)��}�(hhhM��hMjhKubh�ubh�7/// @param[in] lineDir						The line direction vector.
�����}�(hKhh)��}�(hhhM)�hMkhKubh�ubh�*/// @param[in] a									Triangle vertex.
�����}�(hKhh)��}�(hhhMa�hMlhKubh�ubh�*/// @param[in] b									Triangle vertex.
�����}�(hKhh)��}�(hhhM��hMmhKubh�ubh�*/// @param[in] c									Triangle vertex.
�����}�(hKhh)��}�(hhhM��hMnhKubh�ubh�Q/// @param[out] intersectionPoint	Intersection position if intersection happens.
�����}�(hKhh)��}�(hhhM�hMohKubh�ubh��/// @param[out] barycCoords				In case of intersection the pointr is filled with barycentric coordinates of the hit point, can be nullptr.
�����}�(hKhh)��}�(hhhM4�hMphKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM��hMqhKubh�ubh�I/// @return												True if an intersection happens  otherwise false.
�����}�(hKhh)��}�(hhhM�hMrhKubh�ubehpX�  /// Checks for line/triangle intersection and fills intersectionPoint with the intersection position.
/// @param[in] linePoint					A point on the line.
/// @param[in] lineDir						The line direction vector.
/// @param[in] a									Triangle vertex.
/// @param[in] b									Triangle vertex.
/// @param[in] c									Triangle vertex.
/// @param[out] intersectionPoint	Intersection position if intersection happens.
/// @param[out] barycCoords				In case of intersection the pointr is filled with barycentric coordinates of the hit point, can be nullptr.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens  otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�	linePoint�����}�(hKhh)��}�(hhhM�hMthK?ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�lineDir�����}�(hKhh)��}�(hhhM�hMthKXubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�a�����}�(hKhh)��}�(hhhM�hMthKoubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�b�����}�(hKhh)��}�(hhhM0�hMthK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�c�����}�(hKhh)��}�(hhhMA�hMthK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhML�hMthK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�	Vector2d*�hh�barycCoords�����}�(hKhh)��}�(hhhMi�hMthK�ubh�ubj=  �nullptr�j>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM��hMthK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectHalfLineTriangle�����}�(hKhh)��}�(hhhMW�hM�hKubh�ubhj�  h]�h_j%  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhME�hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�j/// Checks for halfline/triangle intersection and fills intersectionPoint with the intersection position.
�����}�(hKhh)��}�(hhhM
�hMwhKubh�ubh�8/// @param[in] halfLineOrigin			Half line origin point.
�����}�(hKhh)��}�(hhhMu�hMxhKubh�ubh�>/// @param[in] halfLineDir				The half line direction vector.
�����}�(hKhh)��}�(hhhM��hMyhKubh�ubh�*/// @param[in] a									Triangle vertex.
�����}�(hKhh)��}�(hhhM��hMzhKubh�ubh�*/// @param[in] b									Triangle vertex.
�����}�(hKhh)��}�(hhhM�hM{hKubh�ubh�*/// @param[in] c									Triangle vertex.
�����}�(hKhh)��}�(hhhMC�hM|hKubh�ubh�Q/// @param[out] intersectionPoint	Intersection position if intersection happens.
�����}�(hKhh)��}�(hhhMn�hM}hKubh�ubh��/// @param[out] barycCoords				In case of intersection the pointr is filled with barycentric coordinates of the hit point, can be nullptr.
�����}�(hKhh)��}�(hhhM��hM~hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhML�hMhKubh�ubh�I/// @return												True if an intersection happens  otherwise false.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubehpX�  /// Checks for halfline/triangle intersection and fills intersectionPoint with the intersection position.
/// @param[in] halfLineOrigin			Half line origin point.
/// @param[in] halfLineDir				The half line direction vector.
/// @param[in] a									Triangle vertex.
/// @param[in] b									Triangle vertex.
/// @param[in] c									Triangle vertex.
/// @param[out] intersectionPoint	Intersection position if intersection happens.
/// @param[out] barycCoords				In case of intersection the pointr is filled with barycentric coordinates of the hit point, can be nullptr.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens  otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�halfLineOrigin�����}�(hKhh)��}�(hhhM�hM�hKCubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�halfLineDir�����}�(hKhh)��}�(hhhM��hM�hKaubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�a�����}�(hKhh)��}�(hhhM��hM�hK|ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�b�����}�(hKhh)��}�(hhhMɴhM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�c�����}�(hKhh)��}�(hhhMڴhM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhM�hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�	Vector2d*�hh�barycCoords�����}�(hKhh)��}�(hhhM�hM�hK�ubh�ubj=  �nullptr�j>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM�hM�hK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectLineQuadrangle�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMv�hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�h/// Checks for line/quadrangle intersection and fills intersectionPoint with the intersection position.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�2/// @param[in] linePoint					A point on the line.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�7/// @param[in] lineDir						The line direction vector.
�����}�(hKhh)��}�(hhhM?�hM�hKubh�ubh�,/// @param[in] a									Quadrangle vertex.
�����}�(hKhh)��}�(hhhMw�hM�hKubh�ubh�,/// @param[in] b									Quadrangle vertex.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�,/// @param[in] c									Quadrangle vertex.
�����}�(hKhh)��}�(hhhMѶhM�hKubh�ubh�,/// @param[in] d									Quadrangle vertex.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�Q/// @param[out] intersectionPoint	Intersection position if intersection happens.
�����}�(hKhh)��}�(hhhM+�hM�hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM}�hM�hKubh�ubh�I/// @return												True if an intersection happens  otherwise false.
�����}�(hKhh)��}�(hhhMɷhM�hKubh�ubehpXf  /// Checks for line/quadrangle intersection and fills intersectionPoint with the intersection position.
/// @param[in] linePoint					A point on the line.
/// @param[in] lineDir						The line direction vector.
/// @param[in] a									Quadrangle vertex.
/// @param[in] b									Quadrangle vertex.
/// @param[in] c									Quadrangle vertex.
/// @param[in] d									Quadrangle vertex.
/// @param[out] intersectionPoint	Intersection position if intersection happens.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens  otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�	linePoint�����}�(hKhh)��}�(hhhM��hM�hKAubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�lineDir�����}�(hKhh)��}�(hhhMǸhM�hKZubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�a�����}�(hKhh)��}�(hhhM޸hM�hKqubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�b�����}�(hKhh)��}�(hhhM�hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�c�����}�(hKhh)��}�(hhhM �hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�d�����}�(hKhh)��}�(hhhM�hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhM�hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM5�hM�hK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectHalfLineQuadrangle�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj�  h]�h_jX  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�l/// Checks for halfline/quadrangle intersection and fills intersectionPoint with the intersection position.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�8/// @param[in] halfLineOrigin			Half line origin point.
�����}�(hKhh)��}�(hhhM&�hM�hKubh�ubh�>/// @param[in] halfLineDir				The half line direction vector.
�����}�(hKhh)��}�(hhhM_�hM�hKubh�ubh�,/// @param[in] a									Quadrangle vertex.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�,/// @param[in] b									Quadrangle vertex.
�����}�(hKhh)��}�(hhhM˺hM�hKubh�ubh�,/// @param[in] c									Quadrangle vertex.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�,/// @param[in] d									Quadrangle vertex.
�����}�(hKhh)��}�(hhhM%�hM�hKubh�ubh�Q/// @param[out] intersectionPoint	Intersection position if intersection happens.
�����}�(hKhh)��}�(hhhMR�hM�hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�I/// @return												True if an intersection happens  otherwise false.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubehpXw  /// Checks for halfline/quadrangle intersection and fills intersectionPoint with the intersection position.
/// @param[in] halfLineOrigin			Half line origin point.
/// @param[in] halfLineDir				The half line direction vector.
/// @param[in] a									Quadrangle vertex.
/// @param[in] b									Quadrangle vertex.
/// @param[in] c									Quadrangle vertex.
/// @param[in] d									Quadrangle vertex.
/// @param[out] intersectionPoint	Intersection position if intersection happens.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens  otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�halfLineOrigin�����}�(hKhh)��}�(hhhMټhM�hKEubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�halfLineDir�����}�(hKhh)��}�(hhhM��hM�hKcubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�a�����}�(hKhh)��}�(hhhM�hM�hK~ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�b�����}�(hKhh)��}�(hhhM#�hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�c�����}�(hKhh)��}�(hhhM4�hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�d�����}�(hKhh)��}�(hhhME�hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhMP�hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhMi�hM�hK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�IntersectSegmentTriangle�����}�(hKhh)��}�(hhhM#�hM�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�m/// Checks for linesegment/triangle intersection and fills intersectionPoint with the intersection position.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�./// @param[in] segmentPoint1			Segment point.
�����}�(hKhh)��}�(hhhM[�hM�hKubh�ubh�./// @param[in] segmentPoint2			Segment point.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�*/// @param[in] a									Triangle vertex.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�*/// @param[in] b									Triangle vertex.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�*/// @param[in] c									Triangle vertex.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�Q/// @param[out] intersectionPoint	Intersection position if intersection happens.
�����}�(hKhh)��}�(hhhM:�hM�hKubh�ubh��/// @param[out] barycCoords				In case of intersection the pointr is filled with barycentric coordinates of the hit point, can be nullptr.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�I/// @return												True if an intersection happens  otherwise false.
�����}�(hKhh)��}�(hhhMd�hM�hKubh�ubehpX�  /// Checks for linesegment/triangle intersection and fills intersectionPoint with the intersection position.
/// @param[in] segmentPoint1			Segment point.
/// @param[in] segmentPoint2			Segment point.
/// @param[in] a									Triangle vertex.
/// @param[in] b									Triangle vertex.
/// @param[in] c									Triangle vertex.
/// @param[out] intersectionPoint	Intersection position if intersection happens.
/// @param[out] barycCoords				In case of intersection the pointr is filled with barycentric coordinates of the hit point, can be nullptr.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens  otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�segmentPoint1�����}�(hKhh)��}�(hhhMJ�hM�hKBubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�segmentPoint2�����}�(hKhh)��}�(hhhMg�hM�hK_ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�a�����}�(hKhh)��}�(hhhM��hM�hK|ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�b�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�c�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector&�hh�intersectionPoint�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Vector*�hh�barycCoords�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  �nullptr�j>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�TrianglesIntersectionTest�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�%/// Checks if 2 triangles intersect.
�����}�(hKhh)��}�(hhhMm�hM�hKubh�ubh�-/// @param[in] t1a								Triangle 1 vertex.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�-/// @param[in] t1b								Triangle 1 vertex.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�-/// @param[in] t1c								Triangle 1 vertex.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�-/// @param[in] t2a								Triangle 2 vertex.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�-/// @param[in] t2b								Triangle 2 vertex.
�����}�(hKhh)��}�(hhhMK�hM�hKubh�ubh�-/// @param[in] t2c								Triangle 2 vertex.
�����}�(hKhh)��}�(hhhMy�hM�hKubh�ubh�K/// @param[in] tolerance					Geometric linear tolerance for the operation.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�I/// @return												True if an intersection happens  otherwise false.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubehpX�  /// Checks if 2 triangles intersect.
/// @param[in] t1a								Triangle 1 vertex.
/// @param[in] t1b								Triangle 1 vertex.
/// @param[in] t1c								Triangle 1 vertex.
/// @param[in] t2a								Triangle 2 vertex.
/// @param[in] t2b								Triangle 2 vertex.
/// @param[in] t2c								Triangle 2 vertex.
/// @param[in] tolerance					Geometric linear tolerance for the operation.
/// @return												True if an intersection happens  otherwise false.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�t1a�����}�(hKhh)��}�(hhhM��hM�hKCubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�t1b�����}�(hKhh)��}�(hhhM��hM�hKVubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�t1c������      }�(hKhh)��}�(hhhM �hM�hKiubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�t2a�����}�(hKhh)��}�(hhhM�hM�hK|ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�t2b�����}�(hKhh)��}�(hhhM&�hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�t2c�����}�(hKhh)��}�(hhhM9�hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhMD�hM�hK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�CalculatePolygonPointST�����}�(hKhh)��}�(hhhM]�hM�hKubh�ubhj�  h]�h_j  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMK�hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�s/// Calculates a S/T coordinate for a given 3D point and polygon in the polygon plane. The 3D point needs to be on
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�./// the plane that is defined by the polygon.
�����}�(hKhh)��}�(hhhM<�hM�hKubh�ubh�/// The function is just a 2d evaluation so not coplanar polygons need to be evaluated by projecting vertex on best fit plane.
�����}�(hKhh)��}�(hhhMk�hM�hKubh�ubh�6/// @param[in] point							The point to find s and t.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�)/// @param[in] pa									Polygon point.
�����}�(hKhh)��}�(hhhM"�hM�hKubh�ubh�)/// @param[in] pb									Polygon point.
�����}�(hKhh)��}�(hhhML�hM�hKubh�ubh�)/// @param[in] pc									Polygon point.
�����}�(hKhh)��}�(hhhMv�hM�hKubh�ubh�)/// @param[in] pd									Polygon point.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�i/// @param[in] isQuad							If true evaluate using a quadrangle, otherwise ignore pd and use a triangle.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�_/// @param[out] s									The resulting s coordinate, or MINVLAUE_FLOAT if the functions fail.
�����}�(hKhh)��}�(hhhM4�hM�hKubh�ubh�_/// @param[out] t									The resulting t coordinate, or MINVLAUE_FLOAT if the functions fail.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh��/// @param[in] tolerance					Geometric linear tolerance for the operation, used to define if the point is inside of polygon or not.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�n/// @return												True if the point is in the polygon boundary otherwise false (negative s or t values).
�����}�(hKhh)��}�(hhhMy�hM�hKubh�ubehpX  /// Calculates a S/T coordinate for a given 3D point and polygon in the polygon plane. The 3D point needs to be on
/// the plane that is defined by the polygon.
/// The function is just a 2d evaluation so not coplanar polygons need to be evaluated by projecting vertex on best fit plane.
/// @param[in] point							The point to find s and t.
/// @param[in] pa									Polygon point.
/// @param[in] pb									Polygon point.
/// @param[in] pc									Polygon point.
/// @param[in] pd									Polygon point.
/// @param[in] isQuad							If true evaluate using a quadrangle, otherwise ignore pd and use a triangle.
/// @param[out] s									The resulting s coordinate, or MINVLAUE_FLOAT if the functions fail.
/// @param[out] t									The resulting t coordinate, or MINVLAUE_FLOAT if the functions fail.
/// @param[in] tolerance					Geometric linear tolerance for the operation, used to define if the point is inside of polygon or not.
/// @return												True if the point is in the polygon boundary otherwise false (negative s or t values).
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhM��hM�hKAubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pa�����}�(hKhh)��}�(hhhM��hM�hKVubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pb�����}�(hKhh)��}�(hhhM��hM�hKhubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pc�����}�(hKhh)��}�(hhhM��hM�hKzubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pd�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�isQuad�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float&�hh�s�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float&�hh�t�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  �GeomConstants::EPSILON4�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�InverseBilinarInterpolate�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�>/// Calculates the bilinear coordinates of a point in a quad.
�����}�(hKhh)��}�(hhhM~�hM�hKubh�ubh�9/// The quad is defined by the points pa, pb, pc and pd.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�)/// @param[in] pa									Polygon point.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�)/// @param[in] pb									Polygon point.
�����}�(hKhh)��}�(hhhM!�hM�hKubh�ubh�)/// @param[in] pc									Polygon point.
�����}�(hKhh)��}�(hhhMK�hM�hKubh�ubh�)/// @param[in] pd									Polygon point.
�����}�(hKhh)��}�(hhhMu�hM�hKubh�ubh�T/// @param[in] point							The point to find the bilinear interpolation values for.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�</// @param[out] bilinarVariables	The resulting coordinates.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubehpX�  /// Calculates the bilinear coordinates of a point in a quad.
/// The quad is defined by the points pa, pb, pc and pd.
/// @param[in] pa									Polygon point.
/// @param[in] pb									Polygon point.
/// @param[in] pc									Polygon point.
/// @param[in] pd									Polygon point.
/// @param[in] point							The point to find the bilinear interpolation values for.
/// @param[out] bilinarVariables	The resulting coordinates.
�hr}�ht�j�  �j+  �j,  �j-  �void�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�pa�����}�(hKhh)��}�(hhhM��hM�hKCubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pb�����}�(hKhh)��}�(hhhM��hM�hKUubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pc�����}�(hKhh)��}�(hhhM��hM�hKgubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pd�����}�(hKhh)��}�(hhhM�hM�hKyubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhM�hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�	Vector2d&�hh�bilinarVariables�����}�(hKhh)��}�(hhhM'�hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�InverseBilinarInterpolateNewton�����}�(hKhh)��}�(hhhM+�hM�hKubh�ubhj�  h]�h_jC  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�]/// Calculates the bilinear coordinates of a point in a quad with a Newton iteration method.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�9/// The quad is defined by the points pa, pb, pc and pd.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�)/// @param[in] pa									Polygon point.
�����}�(hKhh)��}�(hhhM0�hM�hKubh�ubh�)/// @param[in] pb									Polygon point.
�����}�(hKhh)��}�(hhhMZ�hM�hKubh�ubh�)/// @param[in] pc									Polygon point.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�)/// @param[in] pd									Polygon point.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�T/// @param[in] point							The point to find the bilinear interpolation values for.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�K/// @param[in] iterations					The iteration count of the Newton iteration.
�����}�(hKhh)��}�(hhhM-�hM�hKubh�ubh�</// @param[out] bilinarVariables	The resulting coordinates.
�����}�(hKhh)��}�(hhhMy�hM�hKubh�ubehpX  /// Calculates the bilinear coordinates of a point in a quad with a Newton iteration method.
/// The quad is defined by the points pa, pb, pc and pd.
/// @param[in] pa									Polygon point.
/// @param[in] pb									Polygon point.
/// @param[in] pc									Polygon point.
/// @param[in] pd									Polygon point.
/// @param[in] point							The point to find the bilinear interpolation values for.
/// @param[in] iterations					The iteration count of the Newton iteration.
/// @param[out] bilinarVariables	The resulting coordinates.
�hr}�ht�j�  �j+  �j,  �j-  �void�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�pa�����}�(hKhh)��}�(hhhMY�hM�hKIubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pb�����}�(hKhh)��}�(hhhMk�hM�hK[ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pc�����}�(hKhh)��}�(hhhM}�hM�hKmubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pd�����}�(hKhh)��}�(hhhM��hM�hKubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Int32�hh�
iterations�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�	Vector2d&�hh�bilinarVariables�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�InverseBilinarInterpolate2D�����}�(hKhh)��}�(hhhMr�hM�hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM`�hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�D/// Calculates the bilinear coordinates of a 2d point in a 2d quad.
�����}�(hKhh)��}�(hhhM5�hM�hKubh�ubh�9/// The quad is defined by the points pa, pb, pc and pd.
�����}�(hKhh)��}�(hhhMz�hM�hKubh�ubh�,/// @param[in] pa									Polygon 2d point.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�,/// @param[in] pb									Polygon 2d point.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�,/// @param[in] pc									Polygon 2d point.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�,/// @param[in] pd									Polygon 2d point.
�����}�(hKhh)��}�(hhhM;�hM�hKubh�ubh�W/// @param[in] point							The 2d point to find the bilinear interpolation values for.
�����}�(hKhh)��}�(hhhMh�hM�hKubh�ubh�</// @param[out] bilinarVariables	The resulting coordinates.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubehpX�  /// Calculates the bilinear coordinates of a 2d point in a 2d quad.
/// The quad is defined by the points pa, pb, pc and pd.
/// @param[in] pa									Polygon 2d point.
/// @param[in] pb									Polygon 2d point.
/// @param[in] pc									Polygon 2d point.
/// @param[in] pd									Polygon 2d point.
/// @param[in] point							The 2d point to find the bilinear interpolation values for.
/// @param[out] bilinarVariables	The resulting coordinates.
�hr}�ht�j�  �j+  �j,  �j-  �void�j/  �j0  ]�(j3  )��}�(h�const Vector2d&�hh�pa�����}�(hKhh)��}�(hhhM��hM�hKGubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�pb�����}�(hKhh)��}�(hhhM��hM�hK[ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�pc�����}�(hKhh)��}�(hhhM��hM�hKoubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�pd�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�point�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�	Vector2d&�hh�bilinarVariables�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�!InverseBilinarInterpolate2DNewton�����}�(hKhh)��}�(hhhM�hM�hKubh�ubhj�  h]�h_jF  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�c/// Calculates the bilinear coordinates of a 2d point in a 2d quad with a Newton iteration method.
�����}�(hKhh)��}�(hhhMp�hM�hKubh�ubh�9/// The quad is defined by the points pa, pb, pc and pd.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�,/// @param[in] pa									Polygon 2d point.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�,/// @param[in] pb									Polygon 2d point.
�����}�(hKhh)��}�(hhhM;�hM�hKubh�ubh�,/// @param[in] pc									Polygon 2d point.
�����}�(hKhh)��}�(hhhMh�hM�hKubh�ubh�,/// @param[in] pd									Polygon 2d point.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�W/// @param[in] point							The 2d point to find the bilinear interpolation values for.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�K/// @param[in] iterations					The iteration count of the Newton iteration.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�</// @param[out] bilinarVariables	The resulting coordinates.
�����}�(hKhh)��}�(hhhMf�hM�hKubh�ubehpX*  /// Calculates the bilinear coordinates of a 2d point in a 2d quad with a Newton iteration method.
/// The quad is defined by the points pa, pb, pc and pd.
/// @param[in] pa									Polygon 2d point.
/// @param[in] pb									Polygon 2d point.
/// @param[in] pc									Polygon 2d point.
/// @param[in] pd									Polygon 2d point.
/// @param[in] point							The 2d point to find the bilinear interpolation values for.
/// @param[in] iterations					The iteration count of the Newton iteration.
/// @param[out] bilinarVariables	The resulting coordinates.
�hr}�ht�j�  �j+  �j,  �j-  �void�j/  �j0  ]�(j3  )��}�(h�const Vector2d&�hh�pa�����}�(hKhh)��}�(hhhMJ�hM�hKMubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�pb�����}�(hKhh)��}�(hhhM^�hM�hKaubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�pc�����}�(hKhh)��}�(hhhMr�hM�hKuubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�pd�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�point�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Int32�hh�
iterations�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�	Vector2d&�hh�bilinarVariables�����}�(hKhh)��}�(hhhM��hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�BilinearInterpolate�����}�(hKhh)��}�(hhhM��hM
hKubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hM
hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�9/// Calculates the bilinear interpolation within a quad.
�����}�(hKhh)��}�(hhhM.�hM hKubh�ubh�9/// The quad is defined by the points pa, pb, pc and pd.
�����}�(hKhh)��}�(hhhMh�hMhKubh�ubh�)/// @param[in] pa									Polygon point.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�)/// @param[in] pb									Polygon point.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�)/// @param[in] pc									Polygon point.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�)/// @param[in] pd									Polygon point.
�����}�(hKhh)��}�(hhhM �hMhKubh�ubh�7/// @param[in] s									The first bilinar coordinate.
�����}�(hKhh)��}�(hhhMJ�hMhKubh�ubh�9/// @param[in] t									The second bilinear coordinate.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�r/// @return												The point in space with these bilinear coordinates relative to the quad pa, pb, pc and pd.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubehpX�  /// Calculates the bilinear interpolation within a quad.
/// The quad is defined by the points pa, pb, pc and pd.
/// @param[in] pa									Polygon point.
/// @param[in] pb									Polygon point.
/// @param[in] pc									Polygon point.
/// @param[in] pd									Polygon point.
/// @param[in] s									The first bilinar coordinate.
/// @param[in] t									The second bilinear coordinate.
/// @return												The point in space with these bilinear coordinates relative to the quad pa, pb, pc and pd.
�hr}�ht�j�  �j+  �j,  �j-  �Vector�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�pa�����}�(hKhh)��}�(hhhM��hM
hK?ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pb�����}�(hKhh)��}�(hhhM��hM
hKQubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pc�����}�(hKhh)��}�(hhhM��hM
hKcubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�pd�����}�(hKhh)��}�(hhhM��hM
hKuubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Float�hh�s�����}�(hKhh)��}�(hhhM�hM
hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Float�hh�t�����}�(hKhh)��}�(hhhM�hM
hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�CalculateSignedTriangleArea�����}�(hKhh)��}�(hhhM��hMhKubh�ubhj�  h]�h_jO  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhMr�hMhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�8/// Calculates the signed area of an oriented triangle.
�����}�(hKhh)��}�(hhhM�hMhKubh�ubh�S/// Sign is defined as the sign of the z coordinate of the triangle normal vector.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�+/// @param[in] a									Triangle point A.
�����}�(hKhh)��}�(hhhM�hMhKubh�ubh�+/// @param[in] b									Triangle point B.
�����}�(hKhh)��}�(hhhM8�hMhKubh�ubh�+/// @param[in] c									Triangle point C.
�����}�(hKhh)��}�(hhhMd�hMhKubh�ubh�N/// @param[in] normal             The reference normal to calculate the sign.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�//// @return												Unsigned triangle area.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubehpX�  /// Calculates the signed area of an oriented triangle.
/// Sign is defined as the sign of the z coordinate of the triangle normal vector.
/// @param[in] a									Triangle point A.
/// @param[in] b									Triangle point B.
/// @param[in] c									Triangle point C.
/// @param[in] normal             The reference normal to calculate the sign.
/// @return												Unsigned triangle area.
�hr}�ht�j�  �j+  �j,  �j-  �Float�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�a�����}�(hKhh)��}�(hhhM��hMhKFubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�b�����}�(hKhh)��}�(hhhM��hMhKWubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�c�����}�(hKhh)��}�(hhhM��hMhKhubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�normal�����}�(hKhh)��}�(hhhM��hMhKyubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�$CalculateMeanValueCoordinatesWeights�����}�(hKhh)��}�(hhhMu�hMhK#ubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM[�hMhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�Q/// Calculates the mean value coordinates weights for a point inside an outline.
�����}�(hKhh)��}�(hhhMI�hMhKubh�ubh�E/// @param[in] point							The point for which to calculate weights.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�)/// @param[in] outline						The outline.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�A/// @param[in] normal							The normal direction of the outline.
�����}�(hKhh)��}�(hhhM�hMhKubh�ubh��/// @param[in] weights						Array of weights. The amount of entries in the resulting array is the same amount of outline vertices.
�����}�(hKhh)��}�(hhhMM�hMhKubh�ubh�&/// @return												OK on success.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubehpX�  /// Calculates the mean value coordinates weights for a point inside an outline.
/// @param[in] point							The point for which to calculate weights.
/// @param[in] outline						The outline.
/// @param[in] normal							The normal direction of the outline.
/// @param[in] weights						Array of weights. The amount of entries in the resulting array is the same amount of outline vertices.
/// @return												OK on success.
�hr}�ht�j�  �j+  �j,  �j-  �Result<void>�j/  �j0  ]�(j3  )��}�(h�const Vector&�hh�point�����}�(hKhh)��}�(hhhM��hMhKVubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector>&�hh�outline�����}�(hKhh)��}�(hhhM��hMhKxubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector&�hh�normal�����}�(hKhh)��}�(hhhM��hMhK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�WritableArrayInterface<Float>&�hh�weights�����}�(hKhh)��}�(hhhM�hMhK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  �void�j�  K ubj�  )��}�(hh�CalculatePerimeterLength2D�����}�(hKhh)��}�(hhhM��hM&hKubh�ubhj�  h]�h_j  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hM&hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�a/// Calculates the perimeter length for an outline defined by a loop of points in outlinePoints.
�����}�(hKhh)��}�(hhhMp�hM"hKubh�ubh�V/// @param[in] outlinePoints			An array with a point sequence defining the perimeter.
�����}�(hKhh)��}�(hhhM��hM#hKubh�ubh�%/// @return												The perimeter
�����}�(hKhh)��}�(hhhM)�hM$hKubh�ubehp��/// Calculates the perimeter length for an outline defined by a loop of points in outlinePoints.
/// @param[in] outlinePoints			An array with a point sequence defining the perimeter.
/// @return												The perimeter
�hr}�ht�j�  �j+  �j,  �j-  �Float�j/  �j0  ]�j3  )��}�(h�const Block<const Vector2d>&�hh�outlinePoints�����}�(hKhh)��}�(hhhM��hM&hKTubh�ubj=  Nj>  �j?  �j@  �ubaje  Njf  Nj�  K ubj�  )��}�(hh�IsWoundClockwise2D�����}�(hKhh)��}�(hhhM�hM.hK#ubh�ubhj�  h]�h_j=  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hM.hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�U/// Determines whether outline defined by a loop of points is would clockwise or not
�����}�(hKhh)��}�(hhhMk�hM)hKubh�ubh�?/// This is only meaningful if the loop has no self crossings.
�����}�(hKhh)��}�(hhhM��hM*hKubh�ubh�V/// @param[in] outlinePoints			An array with a point sequence defining the perimeter.
�����}�(hKhh)��}�(hhhM�hM+hKubh�ubh�7/// @return												Whether loop is wound clockwise
�����}�(hKhh)��}�(hhhMX�hM,hKubh�ubehpX!  /// Determines whether outline defined by a loop of points is would clockwise or not
/// This is only meaningful if the loop has no self crossings.
/// @param[in] outlinePoints			An array with a point sequence defining the perimeter.
/// @return												Whether loop is wound clockwise
�hr}�ht�j�  �j+  �j,  �j-  �Result<Bool>�j/  �j0  ]�j3  )��}�(h�const Block<const Vector2d>&�hh�outlinePoints�����}�(hKhh)��}�(hhhM=�hM.hKSubh�ubj=  Nj>  �j?  �j@  �ubaje  Njf  �Bool�j�  K ubj�  )��}�(hh�!CalculateOutlineCentroidAndArea2D�����}�(hKhh)��}�(hhhM��hM7hKubh�ubhj�  h]�h_js  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hM7hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�e/// Calculates the centroid coordinates for an outline defined by a loop of points in outlinePoints.
�����}�(hKhh)��}�(hhhM��hM1hKubh�ubh�?/// @param[in] outlinePoints			An array with a point sequence.
�����}�(hKhh)��}�(hhhM�hM2hKubh�ubh�X/// @param[out] area							If non-null, then pointed value is set to the enclosed area.
�����}�(hKhh)��}�(hhhMQ�hM3hKubh�ubh�m/// @param[out] windingPolarity 	If non-null, then pointed value contains the winding direction of the loop.
�����}�(hKhh)��}�(hhhM��hM4hKubh�ubh�1/// @return												The centroid coordinates.
�����}�(hKhh)��}�(hhhM�hM5hKubh�ubehpX�  /// Calculates the centroid coordinates for an outline defined by a loop of points in outlinePoints.
/// @param[in] outlinePoints			An array with a point sequence.
/// @param[out] area							If non-null, then pointed value is set to the enclosed area.
/// @param[out] windingPolarity 	If non-null, then pointed value contains the winding direction of the loop.
/// @return												The centroid coordinates.
�hr}�ht�j�  �j+  �j,  �j-  �Vector2d�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector2d>&�hh�outlinePoints�����}�(hKhh)��}�(hhhM�hM7hK^ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float*�hh�area�����}�(hKhh)��}�(hhhM�hM7hKtubh�ubj=  �nullptr�j>  �j?  �j@  �ubj3  )��}�(h�Bool*�hh�windingPolarity�����}�(hKhh)��}�(hhhM.�hM7hK�ubh�ubj=  �nullptr�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�'CalculateMultiOutlineCentroidAndAreas2D�����}�(hKhh)��}�(hhhM��hMChK'ubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hMChK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�l/// Calculates the centroid coordinates for an outline with optional holes, defined by loop(s) of vertices.
�����}�(hKhh)��}�(hhhM��hM:hKubh�ubh��/// @param[in] loopVertices				An array with one or more point sequences which define perimeter loop followed by any hole loops. All loops are ASSUMED to neither overlap nor intersect, and first loop must enclose all others.
�����}�(hKhh)��}�(hhhM�hM;hKubh�ubh��/// @param[in] loopVertexCounts		An array containing the number of vertices in each loop. If no holes, then this will be a single value equal to the number of entries in loopVertices.
�����}�(hKhh)��}�(hhhM��hM<hKubh�ubh��/// @param[in] includeHolesInCogCalcs If true, the holes are considered in calculation of the centroid position. If false, only the first loop (outer perimeter) is considered.
�����}�(hKhh)��}�(hhhM��hM=hKubh�ubh��/// @param[out] overallArea				If non-null, then pointed value is set to the enclosed area. Holes are ALWAYS considered in this calculation.
�����}�(hKhh)��}�(hhhMa�hM>hKubh�ubh��/// @param[out] loopSoloAreas 		If non-null, then pointed array contains the areas enclosed by each loop in isolation. Overall area is then the first value minus the sum of the rest.
�����}�(hKhh)��}�(hhhM��hM?hKubh�ubh�o/// @param[out] windingPolarity	 	If non-null, then pointed array contains the winding direction of each loop.
�����}�(hKhh)��}�(hhhM��hM@hKubh�ubh�1/// @return												The centroid coordinates.
�����}�(hKhh)��}�(hhhM�hMAhKubh�ubehpX�  /// Calculates the centroid coordinates for an outline with optional holes, defined by loop(s) of vertices.
/// @param[in] loopVertices				An array with one or more point sequences which define perimeter loop followed by any hole loops. All loops are ASSUMED to neither overlap nor intersect, and first loop must enclose all others.
/// @param[in] loopVertexCounts		An array containing the number of vertices in each loop. If no holes, then this will be a single value equal to the number of entries in loopVertices.
/// @param[in] includeHolesInCogCalcs If true, the holes are considered in calculation of the centroid position. If false, only the first loop (outer perimeter) is considered.
/// @param[out] overallArea				If non-null, then pointed value is set to the enclosed area. Holes are ALWAYS considered in this calculation.
/// @param[out] loopSoloAreas 		If non-null, then pointed array contains the areas enclosed by each loop in isolation. Overall area is then the first value minus the sum of the rest.
/// @param[out] windingPolarity	 	If non-null, then pointed array contains the winding direction of each loop.
/// @return												The centroid coordinates.
�hr}�ht�j�  �j+  �j,  �j-  �Result<Vector2d>�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector2d>&�hh�loopVertices�����}�(hKhh)��}�(hhhM�hMChKlubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Int>&�hh�loopVertexCounts�����}�(hKhh)��}�(hhhM5�hMChK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�includeHolesInCogCalcs�����}�(hKhh)��}�(hhhML�hMChK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Float*�hh�overallArea�����}�(hKhh)��}�(hhhMk�hMChK�ubh�ubj=  �nullptr�j>  �j?  �j@  �ubj3  )��}�(h�BaseArray<Float>*�hh�loopSoloAreas�����}�(hKhh)��}�(hhhM��hMChK�ubh�ubj=  �nullptr�j>  �j?  �j@  �ubj3  )��}�(h�BaseArray<Bool>*�hh�windingPolarity�����}�(hKhh)��}�(hhhM��hMChMubh�ubj=  �nullptr�j>  �j?  �j@  �ubeje  Njf  �Vector2d�j�  K ubj�  )��}�(hh�CalculateConvexHull2D�����}�(hKhh)��}�(hhhM��hMLhK-ubh�ubhj�  h]�h_j@  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hMLhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�M/// Calculates the convex hull for an outline, defined by a loop of vertices
�����}�(hKhh)��}�(hhhM8�hMFhKubh�ubh�r/// Note that the polygon is assumed to be non-self intersecting, and with edges formed by the vertices in order.
�����}�(hKhh)��}�(hhhM��hMGhKubh�ubh�u/// In particular, the vertices are NOT treated as a 'sea of points' - but instead as defining edges; order matters!
�����}�(hKhh)��}�(hhhM��hMHhKubh�ubh�g/// @param[in] outlinePoints			An array with a point sequence representing the perimeter of the polgon
�����}�(hKhh)��}�(hhhMo�hMIhKubh�ubh��/// @return												BaseArray containing the indices of the input array corresponding to the vertices of the convex hull of the polygon.
�����}�(hKhh)��}�(hhhM��hMJhKubh�ubehpX'  /// Calculates the convex hull for an outline, defined by a loop of vertices
/// Note that the polygon is assumed to be non-self intersecting, and with edges formed by the vertices in order.
/// In particular, the vertices are NOT treated as a 'sea of points' - but instead as defining edges; order matters!
/// @param[in] outlinePoints			An array with a point sequence representing the perimeter of the polgon
/// @return												BaseArray containing the indices of the input array corresponding to the vertices of the convex hull of the polygon.
�hr}�ht�j�  �j+  �j,  �j-  �Result<BaseArray<Int>>�j/  �j0  ]�j3  )��}�(h�const Block<const Vector2d>&�hh�outlinePoints�����}�(hKhh)��}�(hhhM�hMLhK`ubh�ubj=  Nj>  �j?  �j@  �ubaje  Njf  �BaseArray<Int>�j�  K ubj�  )��}�(hh�CalculateConvexDecomposition2D�����}�(hKhh)��}�(hhhMV�hMUhK8ubh�ubhj�  h]�h_j|  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM'�hMUhK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�S/// Decomposes an outline defined by a loop of vertices into a set of convex parts
�����}�(hKhh)��}�(hhhM��hMOhKubh�ubh�r/// Note that the polygon is assumed to be non-self intersecting, and with edges formed by the vertices in order.
�����}�(hKhh)��}�(hhhM��hMPhKubh�ubh�u/// In particular, the vertices are NOT treated as a 'sea of points' - but instead as defining edges; order matters!
�����}�(hKhh)��}�(hhhMS�hMQhKubh�ubh�g/// @param[in] outlinePoints			An array with a point sequence representing the perimeter of the polgon
�����}�(hKhh)��}�(hhhM��hMRhKubh�ubh��/// @return												BaseArray containing BaseArray of indices of the input array corresponding to the vertices of each of the convex parts of.
�����}�(hKhh)��}�(hhhM1�hMShKubh�ubehpX3  /// Decomposes an outline defined by a loop of vertices into a set of convex parts
/// Note that the polygon is assumed to be non-self intersecting, and with edges formed by the vertices in order.
/// In particular, the vertices are NOT treated as a 'sea of points' - but instead as defining edges; order matters!
/// @param[in] outlinePoints			An array with a point sequence representing the perimeter of the polgon
/// @return												BaseArray containing BaseArray of indices of the input array corresponding to the vertices of each of the convex parts of.
�hr}�ht�j�  �j+  �j,  �j-  �!Result<BaseArray<BaseArray<Int>>>�j/  �j0  ]�j3  )��}�(h�const Block<const Vector2d>&�hh�outlinePoints�����}�(hKhh)��}�(hhhM��hMUhKtubh�ubj=  Nj>  �j?  �j@  �ubaje  Njf  �BaseArray<BaseArray<Int>>�j�  K ubj�  )��}�(hh�CleanLoop2DInPlace�����}�(hKhh)��}�(hhhM�hM_hK#ubh�ubhj�  h]�h_j�  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hM_hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�J/// Given a loop of vertices, this performs in-place cleaning operations.
�����}�(hKhh)��}�(hhhM �hMXhKubh�ubh�3/// - Duplicated consecutive vertices are removed.
�����}�(hKhh)��}�(hhhMK�hMYhKubh�ubh�7/// - Colinear and anti-colinear vertices are removed.
�����}�(hKhh)��}�(hhhM�hMZhKubh�ubh�g/// @param[in] outlinePoints			An array with a point sequence representing the perimeter of the polgon
�����}�(hKhh)��}�(hhhM��hM[hKubh�ubhX4  /// @param[in] maintainStart			If false, then vertex order is rotated such that the first vertex lies on the convex hull. (If it is true, then starting vertex remains unchanged, unless that vertex was removed during cleaning. In this case the new start vertex is the first vertex after that which survived.)
�����}�(hKhh)��}�(hhhM�hM\hKubh�ubh�6/// @return												Whether any changes were made.
�����}�(hKhh)��}�(hhhMT�hM]hKubh�ubehpX�  /// Given a loop of vertices, this performs in-place cleaning operations.
/// - Duplicated consecutive vertices are removed.
/// - Colinear and anti-colinear vertices are removed.
/// @param[in] outlinePoints			An array with a point sequence representing the perimeter of the polgon
/// @param[in] maintainStart			If false, then vertex order is rotated such that the first vertex lies on the convex hull. (If it is true, then starting vertex remains unchanged, unless that vertex was removed during cleaning. In this case the new start vertex is the first vertex after that which survived.)
/// @return												Whether any changes were made.
�hr}�ht�j�  �j+  �j,  �j-  �Result<Bool>�j/  �j0  ]�(j3  )��}�(h�BaseArray<Vector2d>&�hh�outlinePoints�����}�(hKhh)��}�(hhhM0�hM_hKKubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�maintainStart�����}�(hKhh)��}�(hhhMD�hM_hK_ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  �Bool�j�  K ubj�  )��}�(hh�CalculateNoFitPolygonForConvex�����}�(hKhh)��}�(hhhM��hMihK2ubh�ubhj�  h]�h_j   h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhM��hMihK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�v/// Given two loops of vertices which represent two convex polygons, this calculates the corresponding No-Fit Polygon
�����}�(hKhh)��}�(hhhM��hMbhKubh�ubh�/// NFP of convex polygons never contain internal holes, only the main perimeter, hence only ever a single returned edge loop.
�����}�(hKhh)��}�(hhhM)�hMchKubh�ubh�v/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first convex polygon
�����}�(hKhh)��}�(hhhM��hMdhKubh�ubh�w/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second convex polygon
�����}�(hKhh)��}�(hhhM �hMehKubh�ubh��/// @param[in] relativeBToA				If true, returned NFP is the result of moving polygon B relative to polygon A. If false then A relative to B.
�����}�(hKhh)��}�(hhhM��hMfhKubh�ubh�3/// @return												The resulting NoFit polygon
�����}�(hKhh)��}�(hhhM&�hMghKubh�ubehpX�  /// Given two loops of vertices which represent two convex polygons, this calculates the corresponding No-Fit Polygon
/// NFP of convex polygons never contain internal holes, only the main perimeter, hence only ever a single returned edge loop.
/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first convex polygon
/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second convex polygon
/// @param[in] relativeBToA				If true, returned NFP is the result of moving polygon B relative to polygon A. If false then A relative to B.
/// @return												The resulting NoFit polygon
�hr}�ht�j�  �j+  �j,  �j-  �Result<BaseArray<Vector2d>>�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector2d>&�hh�outlinePointsA�����}�(hKhh)��}�(hhhM"�hMihKnubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector2d>&�hh�outlinePointsB�����}�(hKhh)��}�(hhhMO�hMihK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�relativeBToA�����}�(hKhh)��}�(hhhMd�hMihK�ubh�ubj=  �true�j>  �j?  �j@  �ubeje  Njf  �BaseArray<Vector2d>�j�  K ubj�  )��}�(hh�!CalculateNoFitPolygonUsingSliding�����}�(hKhh)��}�(hhhJ� hMshK2ubh�ubhj�  h]�h_jX   h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhJ� hMshK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h��/// Given two loops of vertices which represent two polygons, this calculates the corresponding No-Fit Polygon using the sliding method.
�����}�(hKhh)��}�(hhhM��hMlhKubh�ubh�l/// Internal holes are NOT generated, only the main perimeter, hence only ever a single returned edge loop.
�����}�(hKhh)��}�(hhhMb�hMmhKubh�ubh�o/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first polygon
�����}�(hKhh)��}�(hhhM��hMnhKubh�ubh�p/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon
�����}�(hKhh)��}�(hhhJ?  hMohKubh�ubh��/// @param[in] relativeBToA				If true, returned NFP is the result of moving polygon B relative to polygon A. If false then A relative to B.
�����}�(hKhh)��}�(hhhJ�  hMphKubh�ubh�3/// @return												The resulting NoFit polygon
�����}�(hKhh)��}�(hhhJ> hMqhKubh�ubehpX�  /// Given two loops of vertices which represent two polygons, this calculates the corresponding No-Fit Polygon using the sliding method.
/// Internal holes are NOT generated, only the main perimeter, hence only ever a single returned edge loop.
/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first polygon
/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon
/// @param[in] relativeBToA				If true, returned NFP is the result of moving polygon B relative to polygon A. If false then A relative to B.
/// @return												The resulting NoFit polygon
�hr}�ht�j�  �j+  �j,  �j-  �Result<BaseArray<Vector2d>>�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector2d>&�hh�outlinePointsA�����}�(hKhh)��}�(hhhJ= hMshKqubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector2d>&�hh�outlinePointsB�����}�(hKhh)��}�(hhhJj hMshK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�relativeBToA�����}�(hKhh)��}�(hhhJ hMshK�ubh�ubj=  �true�j>  �j?  �j@  �ubeje  Njf  �BaseArray<Vector2d>�j�  K ubj�  )��}�(hh�$CalculateInnerFitPolygonUsingSliding�����}�(hKhh)��}�(hhhJ� hM|hK2ubh�ubhj�  h]�h_j�   h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhJ� hM|hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h��/// Given two loops of vertices which represent two polygons, this calculates the corresponding Inner-Fit Polygon using the sliding method.
�����}�(hKhh)��}�(hhhJ� hMvhKubh�ubh�l/// Internal holes are NOT generated, only the main perimeter, hence only ever a single returned edge loop.
�����}�(hKhh)��}�(hhhJ� hMwhKubh�ubh��/// @param[in] outlinePointsCcwA	An array with a point sequence representing the perimeter of the first polygon. This must be counterclockwise wound.
�����}�(hKhh)��}�(hhhJ� hMxhKubh�ubh��/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon. This must be clockwise wound.
�����}�(hKhh)��}�(hhhJ� hMyhKubh�ubh�7/// @return												The resulting Inner-Fit polygon
�����}�(hKhh)��}�(hhhJ hMzhKubh�ubehpXT  /// Given two loops of vertices which represent two polygons, this calculates the corresponding Inner-Fit Polygon using the sliding method.
/// Internal holes are NOT generated, only the main perimeter, hence only ever a single returned edge loop.
/// @param[in] outlinePointsCcwA	An array with a point sequence representing the perimeter of the first polygon. This must be counterclockwise wound.
/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon. This must be clockwise wound.
/// @return												The resulting Inner-Fit polygon
�hr}�ht�j�  �j+  �j,  �j-  �Result<BaseArray<Vector2d>>�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector2d>&�hh�outlinePointsCcwA�����}�(hKhh)��}�(hhhJ hM|hKtubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector2d>&�hh�outlinePointsB�����}�(hKhh)��}�(hhhJJ hM|hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  �BaseArray<Vector2d>�j�  K ubj�  )��}�(hh�CalculateNoFitPolygonForConvex�����}�(hKhh)��}�(hhhJ�
 hM�hK2ubh�ubhj�  h]�h_j�   h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhJ�
 hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�v/// Given two loops of vertices which represent two convex polygons, this calculates the corresponding No-Fit Polygon
�����}�(hKhh)��}�(hhhJ� hMhKubh�ubh�/// NFP of convex polygons never contain internal holes, only the main perimeter, hence only ever a single returned edge loop.
�����}�(hKhh)��}�(hhhJ0 hM�hKubh�ubh�v/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first convex polygon
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh�w/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second convex polygon
�����}�(hKhh)��}�(hhhJ' hM�hKubh�ubh�b/// @param[in] transformA					Transformation to be applied to vertices in A prior to calculation.
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh�b/// @param[in] transformB					Transformation to be applied to vertices in B prior to calculation.
�����}�(hKhh)��}�(hhhJ	 hM�hKubh�ubh��/// @param[in] relativeBToA				If true, returned NFP is the result of moving polygon B relative to polygon A. If false then A relative to B.
�����}�(hKhh)��}�(hhhJe	 hM�hKubh�ubh�3/// @return												The resulting NoFit polygon
�����}�(hKhh)��}�(hhhJ�	 hM�hKubh�ubehpXf  /// Given two loops of vertices which represent two convex polygons, this calculates the corresponding No-Fit Polygon
/// NFP of convex polygons never contain internal holes, only the main perimeter, hence only ever a single returned edge loop.
/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first convex polygon
/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second convex polygon
/// @param[in] transformA					Transformation to be applied to vertices in A prior to calculation.
/// @param[in] transformB					Transformation to be applied to vertices in B prior to calculation.
/// @param[in] relativeBToA				If true, returned NFP is the result of moving polygon B relative to polygon A. If false then A relative to B.
/// @return												The resulting NoFit polygon
�hr}�ht�j�  �j+  �j,  �j-  �Result<BaseArray<Vector2d>>�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector2d>&�hh�outlinePointsA�����}�(hKhh)��}�(hhhJ�
 hM�hKnubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector2d>&�hh�outlinePointsB�����}�(hKhh)��}�(hhhJ hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Matrix2d&�hh�
transformA�����}�(hKhh)��}�(hhhJ< hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Matrix2d&�hh�
transformB�����}�(hKhh)��}�(hhhJX hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�relativeBToA�����}�(hKhh)��}�(hhhJi hM�hK�ubh�ubj=  �true�j>  �j?  �j@  �ubeje  Njf  �BaseArray<Vector2d>�j�  K ubj�  )��}�(hh�!CalculateNoFitPolygonUsingSliding�����}�(hKhh)��}�(hhhJ� hM�hK2ubh�ubhj�  h]�h_je!  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhJ� hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h��/// Given two loops of vertices which represent two polygons, this calculates the corresponding No-Fit Polygon using the sliding method.
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh�l/// Internal holes are NOT generated, only the main perimeter, hence only ever a single returned edge loop.
�����}�(hKhh)��}�(hhhJg hM�hKubh�ubh�o/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first polygon
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh�p/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon
�����}�(hKhh)��}�(hhhJD hM�hKubh�ubh�b/// @param[in] transformA					Transformation to be applied to vertices in A prior to calculation.
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh�b/// @param[in] transformB					Transformation to be applied to vertices in B prior to calculation.
�����}�(hKhh)��}�(hhhJ hM�hKubh�ubh��/// @param[in] relativeBToA				If true, returned NFP is the result of moving polygon B relative to polygon A. If false then A relative to B.
�����}�(hKhh)��}�(hhhJ{ hM�hKubh�ubh�3/// @return												The resulting NoFit polygon
�����}�(hKhh)��}�(hhhJ	 hM�hKubh�ubehpXX  /// Given two loops of vertices which represent two polygons, this calculates the corresponding No-Fit Polygon using the sliding method.
/// Internal holes are NOT generated, only the main perimeter, hence only ever a single returned edge loop.
/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first polygon
/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon
/// @param[in] transformA					Transformation to be applied to vertices in A prior to calculation.
/// @param[in] transformB					Transformation to be applied to vertices in B prior to calculation.
/// @param[in] relativeBToA				If true, returned NFP is the result of moving polygon B relative to polygon A. If false then A relative to B.
/// @return												The resulting NoFit polygon
�hr}�ht�j�  �j+  �j,  �j-  �Result<BaseArray<Vector2d>>�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector2d>&�hh�outlinePointsA�����}�(hKhh)��}�(hhhJ hM�hKqubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector2d>&�hh�outlinePointsB�����}�(hKhh)��}�(hhhJ5 hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Matrix2d&�hh�
transformA�����}�(hKhh)��}�(hhhJU hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Matrix2d&�hh�
transformB�����}�(hKhh)��}�(hhhJq hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�relativeBToA�����}�(hKhh)��}�(hhhJ� hM�hK�ubh�ubj=  �true�j>  �j?  �j@  �ubeje  Njf  �BaseArray<Vector2d>�j�  K ubj�  )��}�(hh�CalculateUnionOfPolygons�����}�(hKhh)��}�(hhhJ� hM�hK=ubh�ubhj�  h]�h_j�!  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhJ� hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�a/// Given two loops of vertices which represent two polygon outlines, this calculates the union.
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh�o/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first polygon
�����}�(hKhh)��}�(hhhJX hM�hKubh�ubh�p/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh��/// @param[in] includeHolesInResult		If true, then if union shape contains holes, then these are also calculated and returned. If false then only the outer perimeter is returned.
�����}�(hKhh)��}�(hhhJ9 hM�hKubh�ubh��/// @param[in] createOuterLoop		If true, then attempt to generate an outer loop before looking for holes. Otherwise just generate holes.
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh��/// @return												The resulting union. If this contains multiple loops the first is the outer perimeter and all others represent internal loops (holes).
�����}�(hKhh)��}�(hhhJw hM�hKubh�ubh�G///																If this is empty, then the outlines do not overlap.
�����}�(hKhh)��}�(hhhJ hM�hKubh�ubehpXa  /// Given two loops of vertices which represent two polygon outlines, this calculates the union.
/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first polygon
/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon
/// @param[in] includeHolesInResult		If true, then if union shape contains holes, then these are also calculated and returned. If false then only the outer perimeter is returned.
/// @param[in] createOuterLoop		If true, then attempt to generate an outer loop before looking for holes. Otherwise just generate holes.
/// @return												The resulting union. If this contains multiple loops the first is the outer perimeter and all others represent internal loops (holes).
///																If this is empty, then the outlines do not overlap.
�hr}�ht�j�  �j+  �j,  �j-  �&Result<BaseArray<BaseArray<Vector2d>>>�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector2d>&�hh�outlinePointsA�����}�(hKhh)��}�(hhhJ+ hM�hKsubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector2d>&�hh�outlinePointsB�����}�(hKhh)��}�(hhhJX hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�includeHolesInResult�����}�(hKhh)��}�(hhhJm hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�createOuterLoop�����}�(hKhh)��}�(hhhJ� hM�hK�ubh�ubj=  �true�j>  �j?  �j@  �ubeje  Njf  �BaseArray<BaseArray<Vector2d>>�j�  K ubj�  )��}�(hh�IntersectsSegmentsExact2D�����}�(hKhh)��}�(hhhJW hM�hKubh�ubhj�  h]�h_j<"  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhJE hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�`/// Checks if two segment intersect in 2D space and calculates the intersection point (if any).
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh�-/// If the lines are parallel and intersect:
�����}�(hKhh)��}�(hhhJ` hM�hKubh�ubh�|///   If intersectionPoint2 is nullptr then the midpoint of the intersection range will be returned via 'intersectionPoint'
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh��///		If intersectionPoint2 is non-null, then the start of the intersection range will be returned via 'intersectionPoint', and the end via '*intersectionPoint2'
�����}�(hKhh)��}�(hhhJ hM�hKubh�ubh�/// 
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh�5/// @param[in]	segment1Point1			First segment point.
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh�5/// @param[in]	segment1Point2			First segment point.
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh�6/// @param[in]	segment2Point1			Second segment point.
�����}�(hKhh)��}�(hhhJ hM�hKubh�ubh�6/// @param[in]	segment2Point2			Second segment point.
�����}�(hKhh)��}�(hhhJV hM�hKubh�ubh��/// @param[out] intersectionPoint		Calculated intersection point in xy plane. For parallel intersection segments this is the start or mid-point of the overlapping region - see above.
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh��/// @param[out] areParallel					If non null, routine sets to true or false to indicate whether the line segments were detected to be parallel.
�����}�(hKhh)��}�(hhhJE hM�hKubh�ubh��/// @param[out] intersectionPoint2	If non null, and segments are colinear and overlapping,  then is the end of the overlapping region.
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh�E/// @param[in]	tolerance						Geometric tolerance for the operation.
�����}�(hKhh)��}�(hhhJ] hM�hKubh�ubh�>/// @return													True if the segments intersect in 2D.
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubehpX�  /// Checks if two segment intersect in 2D space and calculates the intersection point (if any).
/// If the lines are parallel and intersect:
///   If intersectionPoint2 is nullptr then the midpoint of the intersection range will be returned via 'intersectionPoint'
///		If intersectionPoint2 is non-null, then the start of the intersection range will be returned via 'intersectionPoint', and the end via '*intersectionPoint2'
/// 
/// @param[in]	segment1Point1			First segment point.
/// @param[in]	segment1Point2			First segment point.
/// @param[in]	segment2Point1			Second segment point.
/// @param[in]	segment2Point2			Second segment point.
/// @param[out] intersectionPoint		Calculated intersection point in xy plane. For parallel intersection segments this is the start or mid-point of the overlapping region - see above.
/// @param[out] areParallel					If non null, routine sets to true or false to indicate whether the line segments were detected to be parallel.
/// @param[out] intersectionPoint2	If non null, and segments are colinear and overlapping,  then is the end of the overlapping region.
/// @param[in]	tolerance						Geometric tolerance for the operation.
/// @return													True if the segments intersect in 2D.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Vector2d&�hh�segment1Point1�����}�(hKhh)��}�(hhhJ� hM�hKEubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�segment1Point2�����}�(hKhh)��}�(hhhJ� hM�hKeubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�segment2Point1�����}�(hKhh)��}�(hhhJ� hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Vector2d&�hh�segment2Point2�����}�(hKhh)��}�(hhhJ� hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�	Vector2d&�hh�intersectionPoint�����}�(hKhh)��}�(hhhJ� hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool&�hh�areParallel�����}�(hKhh)��}�(hhhJ hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�	Vector2d*�hh�intersectionPoint2�����}�(hKhh)��}�(hhhJ+ hM�hK�ubh�ubj=  �nullptr�j>  �j?  �j@  �ubj3  )��}�(h�Float�hh�	tolerance�����}�(hKhh)��}�(hhhJO hM�hMubh�ubj=  �0.0_f�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�*GetContainmentStateForNonIntersectingLoops�����}�(hKhh)��}�(hhhJ� hM�hK)ubh�ubhj�  h]�h_j�"  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhJ� hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�s/// Given two boundary loops of vertices WHICH ARE KNOWN TO CONTAIN NO INTERSECTIONS, this determines the relative
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh�(/// containment state of the two loops.
�����}�(hKhh)��}�(hhhJ6 hM�hKubh�ubh�o/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first polygon
�����}�(hKhh)��}�(hhhJ_ hM�hKubh�ubh�p/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh�-/// @return												The containment state
�����}�(hKhh)��}�(hhhJ@ hM�hKubh�ubehpX�  /// Given two boundary loops of vertices WHICH ARE KNOWN TO CONTAIN NO INTERSECTIONS, this determines the relative
/// containment state of the two loops.
/// @param[in] outlinePointsA			An array with a point sequence representing the perimeter of the first polygon
/// @param[in] outlinePointsB			An array with a point sequence representing the perimeter of the second polygon
/// @return												The containment state
�hr}�ht�j�  �j+  �j,  �j-  �LOOP_OVERLAP_STATE�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector2d>&�hh�outlinePointsA�����}�(hKhh)��}�(hhhJ9 hM�hKqubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector2d>&�hh�outlinePointsB�����}�(hKhh)��}�(hhhJf hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�AreLoopsEqualToWithinTolerance�����}�(hKhh)��}�(hhhJG% hM�hKubh�ubhj�  h]�h_j2#  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhJ5% hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�d/// Given two boundary loops of vertices, this determines whether the two loops are the same shape.
�����}�(hKhh)��}�(hhhJ� hM�hKubh�ubh�g/// They are deemed to be the same if there are the same number of vertices, and the pairwise vertices
�����}�(hKhh)��}�(hhhJ:  hM�hKubh�ubh�@/// have the same coordinates to within the tolerance distance.
�����}�(hKhh)��}�(hhhJ�  hM�hKubh�ubh�R/// @param[in] loopA			An array with a point sequence representing the first loop
�����}�(hKhh)��}�(hhhJ�  hM�hKubh�ubh�S/// @param[in] loopB			An array with a point sequence representing the second loop
�����}�(hKhh)��}�(hhhJ6! hM�hKubh�ubh��/// @param[in] allowCyclicRotation			If true, then cyclically rotated loops are considered equivalent, i.e. the loops don't have to start on the same vertices 
�����}�(hKhh)��}�(hhhJ�! hM�hKubh�ubh��///																			for a match to be found. Loops which match, but have opposing winding directions are also considered to be a match when this is true.
�����}�(hKhh)��}�(hhhJ+" hM�hKubh�ubh�v///																			If false then vertices with the same indices must have the same coordinates to declare a match.
�����}�(hKhh)��}�(hhhJ�" hM�hKubh�ubh��/// @param[in] ignoreTranslationOffset	If true then any translational offset between the loops is ignored. I.e. the same shapes at different offsets will be considered to match.
�����}�(hKhh)��}�(hhhJ?# hM�hKubh�ubh��/// @param[in] tol				The position tolerance. If vertices differ by more than this in either x or y then they are considered to be different and non-matching.
�����}�(hKhh)��}�(hhhJ�# hM�hKubh�ubh�?/// @return								Whether the loops represent the same shape.
�����}�(hKhh)��}�(hhhJ�$ hM�hKubh�ubehpX�  /// Given two boundary loops of vertices, this determines whether the two loops are the same shape.
/// They are deemed to be the same if there are the same number of vertices, and the pairwise vertices
/// have the same coordinates to within the tolerance distance.
/// @param[in] loopA			An array with a point sequence representing the first loop
/// @param[in] loopB			An array with a point sequence representing the second loop
/// @param[in] allowCyclicRotation			If true, then cyclically rotated loops are considered equivalent, i.e. the loops don't have to start on the same vertices 
///																			for a match to be found. Loops which match, but have opposing winding directions are also considered to be a match when this is true.
///																			If false then vertices with the same indices must have the same coordinates to declare a match.
/// @param[in] ignoreTranslationOffset	If true then any translational offset between the loops is ignored. I.e. the same shapes at different offsets will be considered to match.
/// @param[in] tol				The position tolerance. If vertices differ by more than this in either x or y then they are considered to be different and non-matching.
/// @return								Whether the loops represent the same shape.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector2d>&�hh�loopA�����}�(hKhh)��}�(hhhJ�% hM�hKWubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�const Block<const Vector2d>&�hh�loopB�����}�(hKhh)��}�(hhhJ�% hM�hK{ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�allowCyclicRotation�����}�(hKhh)��}�(hhhJ�% hM�hK�ubh�ubj=  �true�j>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�ignoreTranslationOffset�����}�(hKhh)��}�(hhhJ�% hM�hK�ubh�ubj=  �true�j>  �j?  �j@  �ubj3  )��}�(h�maxon::Float�hh�tol�����}�(hKhh)��}�(hhhJ& hM�hK�ubh�ubj=  �maxon::GeomConstants::EPSILON5�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh�CalculateBoundingBoxIndices�����}�(hKhh)��}�(hhhJ�( hM�hKubh�ubhj�  h]�h_j�#  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhJ�( hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�c/// Given a set of vertices, returns indices of vertices which lie on each of the maximal extents.
�����}�(hKhh)��}�(hhhJ�& hM�hKubh�ubh�+/// @param[in] verts			The set of vertices
�����}�(hKhh)��}�(hhhJ�& hM�hKubh�ubh�E/// @param[out] minIdxX		The index of a vertex with minimum X extent
�����}�(hKhh)��}�(hhhJ' hM�hKubh�ubh�E/// @param[out] maxIdxX		The index of a vertex with maximum X extent
�����}�(hKhh)��}�(hhhJ^' hM�hKubh�ubh�E/// @param[out] minIdxY		The index of a vertex with minimum Y extent
�����}�(hKhh)��}�(hhhJ�' hM�hKubh�ubh�E/// @param[out] maxIdxY		The index of a vertex with minimum Y extent
�����}�(hKhh)��}�(hhhJ�' hM�hKubh�ubh��/// @param[in]	findMostCounterClockwise	If true then when multiple vertices lie on the same extent, the most counterclockwise one will be the one whose index is returned.
�����}�(hKhh)��}�(hhhJ0( hM�hKubh�ubehpXM  /// Given a set of vertices, returns indices of vertices which lie on each of the maximal extents.
/// @param[in] verts			The set of vertices
/// @param[out] minIdxX		The index of a vertex with minimum X extent
/// @param[out] maxIdxX		The index of a vertex with maximum X extent
/// @param[out] minIdxY		The index of a vertex with minimum Y extent
/// @param[out] maxIdxY		The index of a vertex with minimum Y extent
/// @param[in]	findMostCounterClockwise	If true then when multiple vertices lie on the same extent, the most counterclockwise one will be the one whose index is returned.
�hr}�ht�j�  �j+  �j,  �j-  �void�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector2d>&�hh�verts�����}�(hKhh)��}�(hhhJ.) hM�hKTubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Int&�hh�minIdxX�����}�(hKhh)��}�(hhhJ:) hM�hK`ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Int&�hh�maxIdxX�����}�(hKhh)��}�(hhhJH) hM�hKnubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Int&�hh�minIdxY�����}�(hKhh)��}�(hhhJV) hM�hK|ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Int&�hh�maxIdxY�����}�(hKhh)��}�(hhhJd) hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�Bool�hh�findMostCounterClockwise�����}�(hKhh)��}�(hhhJr) hM�hK�ubh�ubj=  Nj>  �j?  �j@  �ubeje  Njf  Nj�  K ubj�  )��}�(hh� ArePointsCoLinearWithinTolerance�����}�(hKhh)��}�(hhhJD, hM�hKubh�ubhj�  h]�h_j,$  h`j�  hbh�MAXON_METHOD�����}�(hKhh)��}�(hhhJ2, hM�hK	ubh�ubh/NhdNhNheNhfNhgK hh]�(h�g/// Given a set of vertices, this determines whether the vertices are co-linear (lie in the same line)
�����}�(hKhh)��}�(hhhJ�) hM�hKubh�ubh�t/// They are deemed not to be co-linear if there exists a triangle whose area is greater than the given tolerance. 
�����}�(hKhh)��}�(hhhJS* hM�hKubh�ubh�-/// @param[in] points			The set of vertices.
�����}�(hKhh)��}�(hhhJ�* hM�hKubh�ubh��/// @param[in] tol				The triangle area tolerance. If area of the triangle formed by three vertices is greater than the tolerance, the vertices are not co-linear.
�����}�(hKhh)��}�(hhhJ�* hM�hKubh�ubh�4/// @return								Whether the loops are co-linear.
�����}�(hKhh)��}�(hhhJ�+ hM�hKubh�ubehpX�  /// Given a set of vertices, this determines whether the vertices are co-linear (lie in the same line)
/// They are deemed not to be co-linear if there exists a triangle whose area is greater than the given tolerance. 
/// @param[in] points			The set of vertices.
/// @param[in] tol				The triangle area tolerance. If area of the triangle formed by three vertices is greater than the tolerance, the vertices are not co-linear.
/// @return								Whether the loops are co-linear.
�hr}�ht�j�  �j+  �j,  �j-  �Bool�j/  �j0  ]�(j3  )��}�(h�const Block<const Vector>&�hh�points�����}�(hKhh)��}�(hhhJ�, hM�hKWubh�ubj=  Nj>  �j?  �j@  �ubj3  )��}�(h�maxon::Float�hh�tol�����}�(hKhh)��}�(hhhJ�, hM�hKlubh�ubj=  �maxon::GeomConstants::EPSILON5�j>  �j?  �j@  �ubeje  Njf  Nj�  K ubeh_j�  h`hahbj�  h/NhdNhNheh�"net.maxon.geom.geometryutils"�����}�(hKhh)��}�(hhhM@	hK7hKMubh�ubhfNhgK hh]�h�-/// 2D and 3D geometrical utility functions.
�����}�(hKhh)��}�(hhhMMhK3hKubh�ubahp�-/// 2D and 3D geometrical utility functions.
�hr}�ht�j  ]�j�  Kj�  Nj�  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  ]�j�  }�ubeh_hDh`hahb�	namespace�h/NhdNhNheNhfNhgK hh]�hph	hr}�ht��preprocessorConditions�]��root�hh N�containsResourceId���registry��j�  ���minIndentation�K �maxIndentation�K �firstMember��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhJ- hM�hKubh�ubube��       h_hh`hahbj�$  h/NhdNhNheNhfNhgK hh]�hph	hr}�ht�j�$  ]�j�$  hh ]�(hh)h0h4h8h<h@hKj  j�  j�  j�  j�$  ej�$  �j�$  �j�  ���hxx1�h@�hxx2�h@�snippets�}�j�$  K j�$  K j�$  ��forwardHeaders���ub.