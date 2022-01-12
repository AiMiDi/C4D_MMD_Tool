���0      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��KD:\C4D_MMD_Tool\sdk_s24\frameworks\geom.framework\source\maxon\convexhull.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/interface.h�hhh]��quote��"��template�Nubh()��}�(h�maxon/vector.h�hhh]�h-h.h/Nubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhKqhKhKubh�ubhhh]�(h �Class���)��}�(hh�ConvEdge�����}�(hKhh)��}�(hhhM8hKhKubh�ubhh4h]�(h �Function���)��}�(h�constructor�hh?h]��
simpleName�hL�access��public��kind�hLh/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���static���explicit���deleted���retType��void��const���params�]��
observable�N�result�NubhI)��}�(hhLhh?h]�hNhLhOhPhQhLh/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h\�h]�h^�h_h`ha�hb]�(h �	Parameter���)��}�(h�Int�hh�start�����}�(hKhh)��}�(hhhMhhKhKubh�ub�default�N�pack���input���output��ubhm)��}�(h�Int�hh�end�����}�(hKhh)��}�(hhhMshKhKubh�ubhwNhx�hy�hz�ubhm)��}�(h�Int�hh�nextEdgeOfFace�����}�(hKhh)��}�(hhhM|hKhK#ubh�ubhwNhx�hy�hz�ubhm)��}�(h�Int�hh�nextEdgeOfVert�����}�(hKhh)��}�(hhhM�hKhK7ubh�ubhwNhx�hy�hz�ubhm)��}�(h�Int�hh�reverseEdge�����}�(hKhh)��}�(hhhM�hKhKKubh�ubhwNhx�hy�hz�ubehdNheNubh �Variable���)��}�(hh�_start�����}�(hKhh)��}�(hhhM2hKhKubh�ubhh?h]�hNh�hOhPhQ�variable�h/NhRNh�Int�hSNhTNhUK hV]�hXh	hY}�h[�h\�ubh�)��}�(hh�_end�����}�(hKhh)��}�(hhhMGhKhKubh�ubhh?h]�hNh�hOhPhQh�h/NhRNh�Int�hSNhTNhUK hV]�hXh	hY}�h[�h\�ubh�)��}�(hh�_nextEdgeOfFace�����}�(hKhh)��}�(hhhMZhKhKubh�ubhh?h]�hNh�hOhPhQh�h/NhRNh�Int�hSNhTNhUK hV]�hXh	hY}�h[�h\�ubh�)��}�(hh�_nextEdgeOfVert�����}�(hKhh)��}�(hhhMxhKhKubh�ubhh?h]�hNh�hOhPhQh�h/NhRNh�Int�hSNhTNhUK hV]�hXh	hY}�h[�h\�ubh�)��}�(hh�_reverseEdge�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh?h]�hNh�hOhPhQh�h/NhRNh�Int�hSNhTNhUK hV]�hXh	hY}�h[�h\�ubehNhChOhPhQ�class�h/NhRNhNhSNhTNhUK hV]�(h�x/// ConvEdge struct respresents an edge in the convex hull data. It saves indices to the start and endpoint of the edge
�����}�(hKhh)��}�(hhhK�hKhKubh�ubh��/// as well as indices to other edges, that are somehow related to the current edge (reverse, next edge of face and next edge of vertex)
�����}�(hKhh)��}�(hhhMMhKhKubh�ubehXX  /// ConvEdge struct respresents an edge in the convex hull data. It saves indices to the start and endpoint of the edge
/// as well as indices to other edges, that are somehow related to the current edge (reverse, next edge of face and next edge of vertex)
�hY}�h[��bases�]��	interface�N�refKind�Nh\��refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent���forward���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���ambiguousCalls�]��	selfCalls�]��methodNames�}�ubh>)��}�(hh�ConvexHullData�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh4h]�(hI)��}�(hhLhj  h]�hNhLhOhPhQhLh/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h\�h]�h^�h_h`ha�hb]�hdNheNubhI)��}�(hhLhj  h]�hNhLhOhPhQhLh/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h\�h]�h^�h_h`ha�hb]�hm)��}�(h�ConvexHullData&&�hh�src�����}�(hKhh)��}�(hhhM/hK!hK"ubh�ubhwNhx�hy�hz�ubahdNheNubh�)��}�(hh�vertices�����}�(hKhh)��}�(hhhM�hK#hKubh�ubhj  h]�hNj'  hOhPhQh�h/NhRNh�BaseArray<Vector>�hSNhTNhUK hV]�hXh	hY}�h[�h\�ubh�)��}�(hh�edges�����}�(hKhh)��}�(hhhM�hK$hKubh�ubhj  h]�hNj3  hOhPhQh�h/NhRNh�BaseArray<ConvEdge>�hSNhTNhUK hV]�hXh	hY}�h[�h\�ubh�)��}�(hh�faces�����}�(hKhh)��}�(hhhM�hK%hKubh�ubhj  h]�hNj?  hOhPhQh�h/NhRNh�BaseArray<Int>�hSNhTNhUK hV]�hXh	hY}�h[�h\�ubehNj	  hOhPhQh�h/NhRNhNhSNhTNhUK hV]�h�K/// ConvexHullData struct is a datacontainer that represents a convex hull
�����}�(hKhh)��}�(hhhMhKhKubh�ubahX�K/// ConvexHullData struct is a datacontainer that represents a convex hull
�hY}�h[�h�]�h�Nh�Nh\�h�Nh�Nh�h��h��h��h��h��h��h��h�Nh��h��h�]�j  ]�j  }�ubh>)��}�(hh�ConvexHullInterface�����}�(hKhh)��}�(hhhM�hK+hKubh�ubhh4h]�(hI)��}�(hh�Alloc�����}�(hKhh)��}�(hhhM�hK1hK+ubh�ubhjT  h]�hNja  hOh�public�����}�(hKhh)��}�(hhhM\hK/hKubh�ubhQh�MAXON_METHOD�����}�(hKhh)��}�(hhhMmhK1hK	ubh�ubh/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h\�h]�h^�h_�ConvexHullInterface*�ha�hb]�hm)��}�(h�const maxon::SourceLocation&�h�allocLocation�hwNhx�hy�hz�ubahdNheNubhI)��}�(hh�ComputeConvexHull�����}�(hKhh)��}�(hhhMyhK=hKubh�ubhjT  h]�hNj~  hOjh  hQh�MAXON_METHOD�����}�(hKhh)��}�(hhhM^hK=hKubh�ubh/NhRNhNhSNhTNhUK hV]�(h�3/// Creates a Convex hull out of the input points.
�����}�(hKhh)��}�(hhhMhK4hKubh�ubh�`/// @param[in] vertices						Block of point data for which the convex hull is to be calculated.
�����}�(hKhh)��}�(hhhMKhK5hKubh�ubh�J/// @param[in] shrink							Value the resulting convex hull is shrunk by.
�����}�(hKhh)��}�(hhhM�hK6hKubh�ubh�V/// @param[in] shrinkClamp				Clamping the minimum size of the resulting convex hull.
�����}�(hKhh)��}�(hhhM�hK7hKubh�ubh�e/// @param[out] resultVertices		The array is filled with the vertices of the calculated convex hull.
�����}�(hKhh)��}�(hhhMN	hK8hKubh�ubh�a/// @param[out] resultEdges				The array is filled with the edges of the calculated convex hull.
�����}�(hKhh)��}�(hhhM�	hK9hKubh�ubh�`/// @param[out] resultFaces				The array is filled with the face of the calculated convex hull.
�����}�(hKhh)��}�(hhhM
hK:hKubh�ubh��/// @return												The amount the convex hull was shrunk by. if value is negative the convex hull is empty because it shrunk to much.
�����}�(hKhh)��}�(hhhMw
hK;hKubh�ubehXX�  /// Creates a Convex hull out of the input points.
/// @param[in] vertices						Block of point data for which the convex hull is to be calculated.
/// @param[in] shrink							Value the resulting convex hull is shrunk by.
/// @param[in] shrinkClamp				Clamping the minimum size of the resulting convex hull.
/// @param[out] resultVertices		The array is filled with the vertices of the calculated convex hull.
/// @param[out] resultEdges				The array is filled with the edges of the calculated convex hull.
/// @param[out] resultFaces				The array is filled with the face of the calculated convex hull.
/// @return												The amount the convex hull was shrunk by. if value is negative the convex hull is empty because it shrunk to much.
�hY}�h[�h\�h]�h^�h_�Result<Float>�ha�hb]�(hm)��}�(h�const Block<const Vector>&�hh�vertices�����}�(hKhh)��}�(hhhM�hK=hKJubh�ubhwNhx�hy�hz�ubhm)��}�(h�const Float�hh�shrink�����}�(hKhh)��}�(hhhM�hK=hK`ubh�ubhwNhx�hy�hz�ubhm)��}�(h�const Float�hh�shrinkClamp�����}�(hKhh)��}�(hhhM�hK=hKtubh�ubhwNhx�hy�hz�ubhm)��}�(h�BaseArray<Vector>&�hh�resultVertices�����}�(hKhh)��}�(hhhM�hK=hK�ubh�ubhwNhx�hy�hz�ubhm)��}�(h�BaseArray<ConvEdge>&�hh�resultEdges�����}�(hKhh)��}�(hhhMhK=hK�ubh�ubhwNhx�hy�hz�ubhm)��}�(h�BaseArray<Int>&�hh�resultFaces�����}�(hKhh)��}�(hhhM2hK=hK�ubh�ubhwNhx�hy�hz�ubehdNhe�Float�ubhI)��}�(hh�ComputeConvexHull�����}�(hKhh)��}�(hhhMNhKGhKubh�ubhjT  h]�hNj�  hOjh  hQh�MAXON_METHOD�����}�(hKhh)��}�(hhhM3hKGhKubh�ubh/NhRNhNhSNhTNhUK hV]�(h�3/// Creates a Convex hull out of the input points.
�����}�(hKhh)��}�(hhhM�hK@hKubh�ubh�`/// @param[in] vertices						Block of point data for which the convex hull is to be calculated.
�����}�(hKhh)��}�(hhhM�hKAhKubh�ubh�J/// @param[in] shrink							Value the resulting convex hull is shrunk by.
�����}�(hKhh)��}�(hhhM3hKBhKubh�ubh�V/// @param[in] shrinkClamp				Clamping the minimum size of the resulting convex hull.
�����}�(hKhh)��}�(hhhM~hKChKubh�ubh�v/// @param[out] hull							The struct is filled with all data that makes up the convex hull (vertices, edges, faces).
�����}�(hKhh)��}�(hhhM�hKDhKubh�ubh��/// @return												The amount the convex hull was shrunk by. if value is negative the convex hull is empty because it shrunk to much.
�����}�(hKhh)��}�(hhhMLhKEhKubh�ubehXX3  /// Creates a Convex hull out of the input points.
/// @param[in] vertices						Block of point data for which the convex hull is to be calculated.
/// @param[in] shrink							Value the resulting convex hull is shrunk by.
/// @param[in] shrinkClamp				Clamping the minimum size of the resulting convex hull.
/// @param[out] hull							The struct is filled with all data that makes up the convex hull (vertices, edges, faces).
/// @return												The amount the convex hull was shrunk by. if value is negative the convex hull is empty because it shrunk to much.
�hY}�h[�h\�h]�h^�h_�Result<Float>�ha�hb]�(hm)��}�(h�const Block<const Vector>&�hh�vertices�����}�(hKhh)��}�(hhhM{hKGhKJubh�ubhwNhx�hy�hz�ubhm)��}�(h�const Float�hh�shrink�����}�(hKhh)��}�(hhhM�hKGhK`ubh�ubhwNhx�hy�hz�ubhm)��}�(h�const Float�hh�shrinkClamp�����}�(hKhh)��}�(hhhM�hKGhKtubh�ubhwNhx�hy�hz�ubhm)��}�(h�ConvexHullData&�hh�hull�����}�(hKhh)��}�(hhhM�hKGhK�ubh�ubhwNhx�hy�hz�ubehdNhe�Float�ubehNjX  hOhPhQh�h/NhRNhNhSh� "net.maxon.interface.convexhull"�����}�(hKhh)��}�(hhhM9hK.hKJubh�ubhTNhUK hV]�h�Y/// ConvexHullInterface provides functions for creating a convex hull of a set of points
�����}�(hKhh)��}�(hhhMhK)hKubh�ubahX�Y/// ConvexHullInterface provides functions for creating a convex hull of a set of points
�hY}�h[�h�]�h�Kh�Kh\�h�ConvexHullRef�h�Nh�h��h��h��h��h��h��h��h�Nh��h��h�]�j  ]�j  }�ubh>)��}�(hjb  hh4h]�(hI)��}�(hja  hjf  hje  hNja  hOjh  hQjn  h/NhRNhNhSNhTNhUK hVjr  hXh	hYjs  h[�h\�h]�h^�h_jt  ha�hbju  hdNheNubhI)��}�(hj~  hjf  hj�  hNj~  hOjh  hQj�  h/NhRNhNhSNhTNhUK hVj�  hXX�  /// Creates a Convex hull out of the input points.
/// @param[in] vertices						Block of point data for which the convex hull is to be calculated.
/// @param[in] shrink							Value the resulting convex hull is shrunk by.
/// @param[in] shrinkClamp				Clamping the minimum size of the resulting convex hull.
/// @param[out] resultVertices		The array is filled with the vertices of the calculated convex hull.
/// @param[out] resultEdges				The array is filled with the edges of the calculated convex hull.
/// @param[out] resultFaces				The array is filled with the face of the calculated convex hull.
/// @return												The amount the convex hull was shrunk by. if value is negative the convex hull is empty because it shrunk to much.
�hYj�  h[�h\�h]�h^�h_j�  ha�hbj�  hdNhej�  ubhI)��}�(hj�  hjf  hj�  hNj�  hOjh  hQj   h/NhRNhNhSNhTNhUK hVj  hXX3  /// Creates a Convex hull out of the input points.
/// @param[in] vertices						Block of point data for which the convex hull is to be calculated.
/// @param[in] shrink							Value the resulting convex hull is shrunk by.
/// @param[in] shrinkClamp				Clamping the minimum size of the resulting convex hull.
/// @param[out] hull							The struct is filled with all data that makes up the convex hull (vertices, edges, faces).
/// @return												The amount the convex hull was shrunk by. if value is negative the convex hull is empty because it shrunk to much.
�hYj*  h[�h\�h]�h^�h_j+  ha�hbj,  hdNhejQ  ubehNjb  hOhPhQh�h/NhRNhNhSNhTNhUKhVjX  hX�Y/// ConvexHullInterface provides functions for creating a convex hull of a set of points
�hY}�h[�h�]�h�Nh�Nh\�h�Nh�Nh�h��h��h��h��h��h��h��h�Nh��h���source�jT  ubehNh8hOhPhQ�	namespace�h/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[��preprocessorConditions�]��root�hh N�containsResourceId���registry���usings����minIndentation�K �maxIndentation�K �firstMember��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhMhKMhKubh�ububehNhhOhPhQju  h/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�jx  ]�jz  hh ]�(hh)h0h4h?j  jT  jf  j�  ej{  �j|  �j}  ���hxx1�h4�hxx2�h4�snippets�}�j  K j�  K j�  �ub.