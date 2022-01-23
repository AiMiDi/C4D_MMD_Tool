���,      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��WG:\C4DSDK\C4D_MMD_Tool\sdk_r23\frameworks\image.framework\source\maxon\gfx_basictypes.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/apibase.h�hhh]��quote��"��template�Nubh()��}�(h�maxon/string.h�hhh]�h-h.h/Nubh()��}�(h�maxon/datatype.h�hhh]�h-h.h/Nubh()��}�(h�maxon/vector2d.h�hhh]�h-h.h/Nubh()��}�(h�maxon/range.h�hhh]�h-h.h/Nubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhK�hK
hKubh�ubhhh]�(h �Class���)��}�(hh�DrawDimension�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh@h]�(h �Function���)��}�(h�constructor�hhKh]��
simpleName�hX�access��public��kind�hXh/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���static���explicit���deleted���retType��void��const���params�]��
observable�N�result�NubhU)��}�(hhXhhKh]�hZhXh[h\h]hXh/Nh^NhNh_Nh`NhaK hb]�hdh	he}�hg�hh�hi�hj�hkhlhm�hn]�(h �	Parameter���)��}�(h�T�hh�w�����}�(hKhh)��}�(hhhM2hKhKubh�ub�default�N�pack���input���output��ubhy)��}�(h�T�hh�h�����}�(hKhh)��}�(hhhM7hKhKubh�ubh�Nh��h��h��ubehpNhqNubhU)��}�(hhXhhKh]�hZhXh[h\h]hXh/Nh^NhNh_Nh`NhaK hb]�hdh	he}�hg�hh�hi�hj�hkhlhm�hn]�hy)��}�(h�const Vec2<T, 1>&�hh�src�����}�(hKhh)��}�(hhhM�hKhK1ubh�ubh�Nh��h��h��ubahpNhqNubhU)��}�(hh�ToString�����}�(hKhh)��}�(hhhM\hK%hK	ubh�ubhhKh]�hZh�h[h\h]�function�h/Nh^NhNh_Nh`NhaK hb]�(h�./// Returns a readable string of the content.
�����}�(hKhh)��}�(hhhMhK!hKubh�ubh��/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
�����}�(hKhh)��}�(hhhM=hK"hKubh�ubh�-/// @return												The converted result.
�����}�(hKhh)��}�(hhhM�hK#hKubh�ubehd��/// Returns a readable string of the content.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
/// @return												The converted result.
�he}�hg�hh�hi�hj�hk�String�hm�hn]�hy)��}�(h�const FormatStatement*�hh�formatStatement�����}�(hKhh)��}�(hhhM|hK%hK)ubh�ubh��nullptr�h��h��h��ubahpNhqNubhU)��}�(hh�
DescribeIO�����}�(hKhh)��}�(hhhM�hK1hKubh�ubhhKh]�hZh�h[h\h]h�h/Nh^NhNh_Nh`NhaK hb]�(h�</// Describe all elements of this class for I/O operations.
�����}�(hKhh)��}�(hhhM�hK-hKubh�ubh�S/// @param[in] stream							The stream that is used to register the class members.
�����}�(hKhh)��}�(hhhM�hK.hKubh�ubh�&/// @return												OK on success.
�����}�(hKhh)��}�(hhhMEhK/hKubh�ubehd��/// Describe all elements of this class for I/O operations.
/// @param[in] stream							The stream that is used to register the class members.
/// @return												OK on success.
�he}�hg�hh�hi�hj�hk�Result<void>�hm�hn]�hy)��}�(h�const DataSerializeInterface&�hh�stream�����}�(hKhh)��}�(hhhMhK1hK?ubh�ubh�Nh��h��h��ubahpNhq�void�ubehZhOh[h\h]�class�h/h �Template���)��}�hn]�h �TypeTemplateParam���)��}�(hh)��}�(hhhM�hKhKubh��hh�T�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�N�variance�Nubasbh^NhNh_Nh`NhaK hb]�h�(/// Size of a window/drawing operation.
�����}�(hKhh)��}�(hhhM,hKhKubh�ubahd�(/// Size of a window/drawing operation.
�he}�hg��bases�]��	interface�N�refKind�Nhh��refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent���forward���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���ambiguousCalls�]��	selfCalls�]��methodNames�}�ubhJ)��}�(h�#IsZeroInitialized<DrawDimension<T>>�hh@h]�hZh�IsZeroInitialized�����}�(hKhh)��}�(hhhM/hK4hKubh�ubh[h\h]h�h/h�)��}�hn]�h�)��}�(hh)��}�(hhhMhK4hKubh��hh�T�����}�(hKhh)��}�(hhhM%hK4hKubh�ubh�Nj  Nubasbh^NhNh_Nh`NhaK hb]�hdh	he}�hg�j  ]��IsZeroInitialized<T>�h�public�����}�(hKhh)��}�(hhhMUhK4hKDubh�ubh	��aj  Nj  Nhh�j  Nj  Nj  �j  �j  �j  �j  �j  �j  �j  �j  Nj  �j   �j!  ]�j#  ]�j%  }�ubh �	TypeAlias���)��}�(hh�DrawDimensionInt�����}�(hKhh)��}�(hhhMThK9hKubh�ubhh@h]�hZjR  h[h\h]�	typealias�h/Nh^NhNh_Nh`NhaK hb]�h�!/// DrawDimension for Int types.
�����}�(hKhh)��}�(hhhM�hK7hKubh�ubahd�!/// DrawDimension for Int types.
�he}�hg�j  ]��DrawDimension<Int>�h\h	��aubh �Declaration���)��}�(hh�DrawDimensionInt�����}�(hKhh)��}�(hhhM�hK:hKubh�ubhh@h]�hZjj  h[h\h]�MAXON_DATATYPE�h/Nh^NhNh_h�""net.maxon.image.drawdimensionint"�����}�(hKhh)��}�(hhhM�hK:hK"ubh�ubh`NhaK hb]�hdh	he}�hg�ubjM  )��}�(hh�DrawDimensionFloat�����}�(hKhh)��}�(hhhM�	hK?hKubh�ubhh@h]�hZj|  h[h\h]jW  h/Nh^NhNh_Nh`NhaK hb]�h�#/// DrawDimension for Float types.
�����}�(hKhh)��}�(hhhM	hK=hKubh�ubahd�#/// DrawDimension for Float types.
�he}�hg�j  ]��DrawDimension<Float>�h\h	��aubje  )��}�(hh�DrawDimensionFloat�����}�(hKhh)��}�(hhhM�	hK@hKubh�ubhh@h]�hZj�  h[h\h]jo  h/Nh^NhNh_h�$"net.maxon.image.drawdimensionfloat"�����}�(hKhh)��}�(hhhM�	hK@hK$ubh�ubh`NhaK hb]�hdh	he}�hg�ubhJ)��}�(hh�DrawRect�����}�(hKhh)��}�(hhhM*hKFhKubh�ubhh@h]�(hU)��}�(hhXhj�  h]�hZhXh[h�public�����}�(hKhh)��}�(hhhM5hKHhKubh�ubh]hXh/Nh^NhNh_Nh`NhaK hb]�hdh	he}�hg�hh�hi�hj�hkhlhm�hn]�(hy)��}�(h�
Vec2<T, 1>�hh�positionValue�����}�(hKhh)��}�(hhhMRhKIhKubh�ubh�Nh��h��h��ubhy)��}�(h�DrawDimension<T>�hh�	sizeValue�����}�(hKhh)��}�(hhhMrhKIhK6ubh�ubh�Nh��h��h��ubehpNhqNubhU)��}�(hhXhj�  h]�hZhXh[j�  h]hXh/Nh^NhNh_Nh`NhaK hb]�hdh	he}�hg�hh�hi�hj�hkhlhm�hn]�(hy)��}�(h�T�hh�x�����}�(hKhh)��}�(hhhM�hKMhKubh�ubh�Nh��h��h��ubhy)��}�(h�T�hh�y�����}�(hKhh)��}�(hhhM�hKMhKubh�ubh�Nh��h��h��ubhy)��}�(h�T�hh�w�����}�(hKhh)��}�(hhhM�hKMhKubh�ubh�Nh��h��h��ubhy)��}�(h�T�hh�h�����}�(hKhh)��}�(hhhM�hKMhKubh�ubh�Nh��h��h��ubehpNhqNubhU)��}�(hhXhj�  h]�hZhXh[j�  h]hXh/Nh^NhNh_Nh`NhaK hb]�hdh	he}�hg�hh�hi�hj�hkhlhm�hn]�hy)��}�(h�const Range<Vec2<T, 1>>&�hh�src�����}�(hKhh)��}�(hhhM(hKQhK3ubh�ubh�Nh��h��h��ubahpNhqNubh �Variable���)��}�(hh�position�����}�(hKhh)��}�(hhhM�hKVhKubh�ubhj�  h]�hZj  h[h�public�����}�(hKhh)��}�(hhhMphKUhKubh�ubh]�variable�h/Nh^Nh�
Vec2<T, 1>�h_Nh`NhaK hb]�hdh	he}�hg�hh�ubj�  )��}�(hh�size�����}�(hKhh)��}�(hhhM�hKWhKubh�ubhj�  h]�hZj  h[j  h]j  h/Nh^Nh�DrawDimension<T>�h_Nh`NhaK hb]�hdh	he}�hg�hh�ubhU)��}�(hhXhj�  h]�hZhXh[j  h]hXh/Nh^NhNh_Nh`NhaK hb]�hdh	he}�hg�hh�hi�hj�hkhlhm�hn]�hpNhqNubhU)��}�(hh�Contains�����}�(hKhh)��}�(hhhM�hK]hKubh�ubhj�  h]�hZj)  h[j  h]h�h/Nh^NhNh_Nh`NhaK hb]�hdh	he}�hg�hh�hi�hj�hk�Bool�hm�hn]�hy)��}�(h�const Vec2<T, 1>&�hh�point�����}�(hKhh)��}�(hhhM�hK]hK!ubh�ubh�Nh��h��h��ubahpNhqNubhU)��}�(hh�ToString�����}�(hKhh)��}�(hhhM"hKghK	ubh�ubhj�  h]�hZj?  h[j  h]h�h/Nh^NhNh_Nh`NhaK hb]�(h�./// Returns a readable string of the content.
�����}�(hKhh)��}�(hhhM�hKchKubh�ubh��/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
�����}�(hKhh)��}�(hhhMhKdhKubh�ubh�-/// @return												The converted result.
�����}�(hKhh)��}�(hhhM�hKehKubh�ubehd��/// Returns a readable string of the content.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
/// @return												The converted result.
�he}�hg�hh�hi�hj�hk�String�hm�hn]�hy)��}�(h�const FormatStatement*�hh�formatStatement�����}�(hKhh)��}�(hhhMBhKghK)ubh�ubh��nullptr�h��h��h��ubahpNhqNubhU)��}�(hh�
DescribeIO�����}�(hKhh)��}�(hhhM�hKshKubh�ubhj�  h]�hZji  h[j  h]h�h/Nh^NhNh_Nh`NhaK hb]�(h�</// Describe all elements of this class for I/O operations.
�����}�(hKhh)��}�(hhhMqhKohKubh�ubh�S/// @param[in] stream							The stream that is used to register the class members.
�����}�(hKhh)��}�(hhhM�hKphKubh�ubh�&/// @return												OK on success.
�����}�(hKhh)��}�(hhhMhKqhKubh�ubehd��/// Describe all elements of this class for I/O operations.
/// @param[in] stream							The stream that is used to register the class members.
/// @return												OK on success.
�he}�hg�hh�hi�hj�hk�Result<void>�hm�hn]�hy)��}�(h�const DataSerializeInterface&�hh�stream�����}�(hKhh)��}�(hhhM�hKshK?ubh�ubh�Nh��h��h��ubahpNhq�void�ubehZj�  h[h\h]h�h/h�)��}�hn]�h�)��}�(hh)��}�(hhhMhKFhKubh��hh�T�����}�(hKhh)��}�(hhhM hKFhKubh�ubh�Nj  Nubasbh^NhNh_Nh`NhaK hb]�h�?/// Definition of a rectangle used for window/draw operations.
�����}�(hKhh)��}�(hhhMs
hKDhKubh�ubahd�?/// Definition of a rectangle used for window/draw operations.
�he}�hg�j  ]�j  Nj  Nhh�j  Nj  Nj  �j  �j  �j  �j  �j  �j  �j  �j  Nj  �j   �j!  ]�j#  ]�j%  }�ubhJ)��}�(h�IsZeroInitialized<DrawRect<T>>�hh@h]�hZh�IsZeroInitialized�����}�(hKhh)��}�(hhhM�hKwhKubh�ubh[h\h]h�h/h�)��}�hn]�h�)��}�(hh)��}�(hhhM�hKwhKubh��hh�T�����}�(hKhh)��}�(hhhM�hKwhKubh�ubh�Nj  Nubasbh^NhNh_Nh`NhaK hb]�hdh	he}�hg�j  ]��IsZeroInitialized<T>�h�public�����}�(hKhh)��}�(hhhMhKwhK?ubh�ubh	��aj  Nj  Nhh�j  Nj  Nj  �j  �j  �j  �j  �j  �j  �j  �j  Nj  �j   �j!  ]�j#  ]�j%  }�ubjM  )��}�(hh�DrawRectInt�����}�(hKhh)��}�(hhhM	hK}hKubh�ubhh@h]�hZj�  h[h\h]jW  h/Nh^NhNh_Nh`NhaK hb]�h�/// DrawRect for Int types.
�����}�(hKhh)��}�(hhhM�hK{hKubh�ubahd�/// DrawRect for Int types.
�he}�hg�j  ]��DrawRect<Int>�h\h	��aubje  )��}�(hh�DrawRectInt�����}�(hKhh)��}�(hhhM5hK~hKubh�ubhh@h]�hZj�  h[h\h]jo  h/Nh^NhNh_h�"net.maxon.image.drawrectint"�����}�(hKhh)��}�(hhhMBhK~hKubh�ubh`NhaK hb]�hdh	he}�hg�ubjM  )��}�(hh�DrawRectFloat�����}�(hKhh)��}�(hhhM=hK�hKubh�ubhh@h]�hZj�  h[h\h]jW  h/Nh^NhNh_Nh`NhaK hb]�h�/// DrawRect for Float types.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubahd�/// DrawRect for Float types.
�he}�hg�j  ]��DrawRect<Float>�h\h	��aubje  )��}�(hh�DrawRectFloat�����}�(hKhh)��}�(hhhMmhK�hKubh�ubhh@h]�hZj  h[h\h]jo  h/Nh^NhNh_h�"net.maxon.image.drawrectfloat"�����}�(hKhh)��}�(hhhM|hK�hKubh�ubh`NhaK hb]�hdh	he}�hg�ubehZhDh[h\h]�	namespace�h/Nh^NhNh_Nh`NhaK hb]�hdh	he}�hg��preprocessorConditions�]��root�hh N�containsResourceId���registry���usings����minIndentation�K �maxIndentation�K �firstMember��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hK�hKubh�ububehZhh[h\h]j  h/Nh^NhNh_Nh`NhaK hb]�hdh	he}�hg�j  ]�j  hh ]�(hh)h0h4h8h<h@hKj'  jN  jf  jx  j�  j�  j�  j�  j�  j�  j	  j'  ej   �j!  �j"  ���hxx1�h@�hxx2�h@�snippets�}�j$  K j%  K j&  �ub.