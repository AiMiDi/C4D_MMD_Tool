����      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��QG:\C4DSDK\C4D_MMD_Tool\sdk_r23\frameworks\core.framework\source\maxon\math\col4.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh)��}�(hNhhh]�h h�#ifndef MAXON_VECTORMODE�����}�(hK
hh)��}�(hhhKbhKhKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhK�hKhKubh�ububh)��}�(hh�maxon�����}�(hKhh)��}�(hhhK�hKhKubh�ubhhh]�(h)��}�(hNhh9h]�h h�#ifdef STRIDE�����}�(hK
hh)��}�(hhhM$hKhKubh�ububh)��}�(hNhh9h]�h h�#else�����}�(hK
hh)��}�(hhhMZhKhKubh�ububh �Class���)��}�(hh�Col4�����}�(hKhh)��}�(hhhM�hKhK.ubh�ubhh9h]�(h �	TypeAlias���)��}�(hh�Rebind�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhVh]��
simpleName�he�access��public��kind��	typealias��template�h �Template���)��}��params�]�h �TypeTemplateParam���)��}�(hh)��}�(hhhM�hKhKub�pack��hh�U�����}�(hKhh)��}�(hhhM�hKhKubh�ub�default�N�variance�Nubasb�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���bases�]��Col4<U,STRIDE>�hlh	��aubh`)��}�(hh�VectorStrideType�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhVh]�hjh�hkhlhmhnhoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]��"std::integral_constant<Int,STRIDE>�hlh	��aubh`)��}�(hh�	ValueType�����}�(hKhh)��}�(hhhMhKhKubh�ubhhVh]�hjh�hkhlhmhnhoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]��T�hlh	��aubh`)��}�(hh�ValueTypeParam�����}�(hKhh)��}�(hhhM.hKhKubh�ubhhVh]�hjh�hkhlhmhnhoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]��typename ByValueParam<T>::type�hlh	��aubh`)��}�(hh�	Unstrided�����}�(hKhh)��}�(hhhMfhKhKubh�ubhhVh]�hjh�hkhlhmhnhoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]��	Col4<T,1>�hlh	��aubh`)��}�(hh�BoolType�����}�(hKhh)��}�(hhhM(hKhKubh�ubhhVh]�hjh�hkhlhmhnhoNh�NhNh�Nh�Nh�K h�]�(h�U/// The type returned by comparisons. If the template argument for T is a SIMD type,
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�K/// this will be a SIMD type, too, which contains the per-element results.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubeh���/// The type returned by comparisons. If the template argument for T is a SIMD type,
/// this will be a SIMD type, too, which contains the per-element results.
�h�}�h��h�]��decltype(T()==T())�hlh	��aubh)��}�(hNhhVh]�h h�#ifdef STRIDE�����}�(hK
hh)��}�(hhhMJhKhKubh�ububh �Variable���)��}�(hh�r�����}�(hKhh)��}�(hhhM[hKhKubh�ubhhVh]�hjh�hkhlhm�variable�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h���static��ubh�)��}�(hh�g�����}�(hKhh)��}�(hhhMahKhKubh�ubhhVh]�hjj  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubh�)��}�(hh�b�����}�(hKhh)��}�(hhhMghKhKubh�ubhhVh]�hjj  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubh�)��}�(hh�a�����}�(hKhh)��}�(hhhMmhKhKubh�ubhhVh]�hjj  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubh)��}�(hNhhVh]�h h�#else�����}�(hK
hh)��}�(hhhMphK hKubh�ububhU)��}�(hh�aanonymous#G:\C4DSDK\C4D_MMD_Tool\sdk_r23\frameworks\core.framework\source\maxon\math\col4.h(33,2)�����}�(hKhh)��}�(hhhMwhK!hKubh�ubhhVh]�(h�)��}�(hh�r�����}�(hKhh)��}�(hhhM�hK!hKubh�ubhj,  h]�hjj9  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubh�)��}�(hh�	_xpadding�����}�(hKhh)��}�(hhhM�hK!hKubh�ubhj,  h]�hjjE  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubehjj0  hkhlhm�class�hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]��	interface�N�refKind�Nh���refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent���forward���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���ambiguousCalls�]��	selfCalls�]��methodNames�}�ubhU)��}�(hh�aanonymous#G:\C4DSDK\C4D_MMD_Tool\sdk_r23\frameworks\core.framework\source\maxon\math\col4.h(34,2)�����}�(hKhh)��}�(hhhM�hK"hKubh�ubhhVh]�(h�)��}�(hh�g�����}�(hKhh)��}�(hhhM�hK"hKubh�ubhjf  h]�hjjs  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubh�)��}�(hh�	_ypadding�����}�(hKhh)��}�(hhhM�hK"hKubh�ubhjf  h]�hjj  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubehjjj  hkhlhmjM  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]�jQ  NjR  Nh��jS  NjT  NjU  �jV  �jW  �jX  �jY  �jZ  �j[  �j\  �j]  Nj^  �j_  �j`  ]�jb  ]�jd  }�ubhU)��}�(hh�aanonymous#G:\C4DSDK\C4D_MMD_Tool\sdk_r23\frameworks\core.framework\source\maxon\math\col4.h(35,2)�����}�(hKhh)��}�(hhhM�hK#hKubh�ubhhVh]�(h�)��}�(hh�b�����}�(hKhh)��}�(hhhM�hK#hKubh�ubhj�  h]�hjj�  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubh�)��}�(hh�	_zpadding�����}�(hKhh)��}�(hhhM�hK#hKubh�ubhj�  h]�hjj�  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubehjj�  hkhlhmjM  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]�jQ  NjR  Nh��jS  NjT  NjU  �jV  �jW  �jX  �jY  �jZ  �j[  �j\  �j]  Nj^  �j_  �j`  ]�jb  ]�jd  }�ubhU)��}�(hh�aanonymous#G:\C4DSDK\C4D_MMD_Tool\sdk_r23\frameworks\core.framework\source\maxon\math\col4.h(36,2)�����}�(hKhh)��}�(hhhM�hK$hKubh�ubhhVh]�(h�)��}�(hh�a�����}�(hKhh)��}�(hhhM�hK$hKubh�ubhj�  h]�hjj�  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubh�)��}�(hh�	_wpadding�����}�(hKhh)��}�(hhhM�hK$hKubh�ubhj�  h]�hjj�  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubehjj�  hkhlhmjM  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]�jQ  NjR  Nh��jS  NjT  NjU  �jV  �jW  �jX  �jY  �jZ  �j[  �j\  �j]  Nj^  �j_  �j`  ]�jb  ]�jd  }�ubh)��}�(hNhhVh]�h h�#endif�����}�(hK
hh)��}�(hhhMhK%hKubh�ububh �Function���)��}�(h�constructor�hhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�F/// Initializes all color components with 0.0 and the alpha with 1.0.
�����}�(hKhh)��}�(hhhMhK'hKubh�ubah��F/// Initializes all color components with 0.0 and the alpha with 1.0.
�h�}�h��h���explicit���deleted���retType��void��const��ht]��
observable�N�result�Nubj�  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�K/// Initializes all color components with a scalar and the alpha with 1.0.
�����}�(hKhh)��}�(hhhM�hK*hKubh�ubah��K/// Initializes all color components with a scalar and the alpha with 1.0.
�h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�h �	Parameter���)��}�(h�ValueTypeParam�hh�in�����}�(hKhh)��}�(hhhMhK+hK)ubh�ubh�Nh|��input���output��ubaj�  Nj�  Nubj�  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�3/// Initializes all vector components individually
�����}�(hKhh)��}�(hhhM-hK-hKubh�ubah��3/// Initializes all vector components individually
�h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�(j	  )��}�(h�ValueTypeParam�hh�ix�����}�(hKhh)��}�(hhhM�hK.hK)ubh�ubh�Nh|�j  �j  �ubj	  )��}�(h�ValueTypeParam�hh�iy�����}�(hKhh)��}�(hhhM�hK.hK<ubh�ubh�Nh|�j  �j  �ubj	  )��}�(h�ValueTypeParam�hh�iz�����}�(hKhh)��}�(hhhM�hK.hKOubh�ubh�Nh|�j  �j  �ubj	  )��}�(h�ValueTypeParam�hh�iw�����}�(hKhh)��}�(hhhM�hK.hKbubh�ubh�Nh|�j  �j  �ubej�  Nj�  Nubj�  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhM&hK1hKubh|�hh�T2�����}�(hKhh)��}�(hhhM/hK1hKubh�ubh�Nh�Nubh �NontypeTemplateParam���)��}�(hh)��}�(hhhM3hK1hKubh|�hh�S2�����}�(hKhh)��}�(hhhM7hK1hKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�h�3/// Initializes components from another 4d vector.
�����}�(hKhh)��}�(hhhM�hK0hKubh�ubah��3/// Initializes components from another 4d vector.
�h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�j	  )��}�(h�const Col4<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhMghK1hKMubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhM�hK2hKubh|�hh�T2�����}�(hKhh)��}�(hhhM�hK2hKubh�ubh�Nh�NubjW  )��}�(hh)��}�(hhhM�hK2hKubh|�hh�S2�����}�(hKhh)��}�(hhhM�hK2hKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�j	  )��}�(h�const Vec4<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhM�hK2hKMubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hohq)��}�ht]�jW  )��}�(hh)��}�(hhhM'hK4hKubh|�hh�S2�����}�(hKhh)��}�(hhhM+hK4hKubh�ubh�Nh�Int�h�Nubasbh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�j	  )��}�(h�const Col4<T, S2>&�hh�v�����}�(hKhh)��}�(hhhMQhK4hK6ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhMhK8hKubh|�hh�T2�����}�(hKhh)��}�(hhhMhK8hKubh�ubh�Nh�NubjW  )��}�(hh)��}�(hhhMhK8hKubh|�hh�S2�����}�(hKhh)��}�(hhhM!hK8hKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�(h�]/// Initializes components from a 3d vector and add an additional value for the a-component.
�����}�(hKhh)��}�(hhhM{hK6hKubh�ubh�,/// The default value for the alpha is 1.0.
�����}�(hKhh)��}�(hhhM�hK7hKubh�ubeh���/// Initializes components from a 3d vector and add an additional value for the a-component.
/// The default value for the alpha is 1.0.
�h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�(j	  )��}�(h�const Col3<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhMQhK8hKMubh�ubh�Nh|�j  �j  �ubj	  )��}�(h�T�hh�iw�����}�(hKhh)��}�(hhhMVhK8hKRubh�ubh��T(1)�h|�j  �j  �ubej�  Nj�  Nubj�  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�6/// Skips initialization of vector (for better speed)
�����}�(hKhh)��}�(hhhM�hK:hKubh�ubah��6/// Skips initialization of vector (for better speed)
�h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�j	  )��}�(h�ENUM_DONT_INITIALIZE�hh�v�����}�(hKhh)��}�(hhhM�hK;hK/ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�	GetVector�����}�(hKhh)��}�(hhhME	hK>hK#ubh�ubhhVh]�hjj  hkhlhm�function�hoNh�NhNh�Nh�Nh�K h�]�h�&/// Reinterprets the color as vector.
�����}�(hKhh)��}�(hhhM�hK=hKubh�ubah��&/// Reinterprets the color as vector.
�h�}�h��h��j�  �j�  �j�  �const Vec4<T, STRIDE>&�j�  �ht]�j�  Nj�  Nubj�  )��}�(hh�	GetVector�����}�(hKhh)��}�(hhhM�	hK?hKubh�ubhhVh]�hjj'  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �Vec4<T, STRIDE>&�j�  �ht]�j�  Nj�  Nubj�  )��}�(hh�	GetColor3�����}�(hKhh)��}�(hhhM+
hKBhK#ubh�ubhhVh]�hjj4  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�8/// Gets the r/g/b components as a color without alpha.
�����}�(hKhh)��}�(hhhM�	hKAhKubh�ubah��8/// Gets the r/g/b components as a color without alpha.
�h�}�h��h��j�  �j�  �j�  �const Col3<T, STRIDE>&�j�  �ht]�j�  Nj�  Nubj�  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�j	  )��}�(h�Gconst typename std::conditional<STRIDE==1, DummyParamType, Col4>::type&�hh�src�����}�(hKhh)��}�(hhhMhKFhKjubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�
operator =�����}�(hKhh)��}�(hhhMDhKJhKubh�ubhhVh]�hjjW  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �Col4&�j�  �ht]�j	  )��}�(h�Gconst typename std::conditional<STRIDE==1, DummyParamType, Col4>::type&�hh�src�����}�(hKhh)��}�(hhhM�hKJhKgubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�operator []�����}�(hKhh)��}�(hhhMnhKThKubh�ubhhVh]�hjjm  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h��/// Accesses vector component: index 0 is 'r', index 1 is 'g', index 2 is 'b'. All other values must not be used and will crash
�����}�(hKhh)��}�(hhhM�hKShKubh�ubah���/// Accesses vector component: index 0 is 'r', index 1 is 'g', index 2 is 'b'. All other values must not be used and will crash
�h�}�h��h��j�  �j�  �j�  �T&�j�  �ht]�j	  )��}�(h�Int�hh�l�����}�(hKhh)��}�(hhhM}hKThKubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�operator []�����}�(hKhh)��}�(hhhMVhK[hKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h��/// Accesses vector component: index 0 is 'r', index 1 is 'g', index 2 is 'b'.  All other values must not be used and will crash
�����}�(hKhh)��}�(hhhM�hKZhKubh�ubah���/// Accesses vector component: index 0 is 'r', index 1 is 'g', index 2 is 'b'.  All other values must not be used and will crash
�h�}�h��h��j�  �j�  �j�  �ValueTypeParam�j�  �ht]�j	  )��}�(h�Int�hh�l�����}�(hKhh)��}�(hhhMehK[hK ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�operator +=�����}�(hKhh)��}�(hhhM�hKbhK1ubh�ubhhVh]�hjj�  hkhlhmj  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhM�hKbhKubh|�hh�T2�����}�(hKhh)��}�(hhhM�hKbhKubh�ubh�Nh�NubjW  )��}�(hh)��}�(hhhM�hKbhKubh|�hh�S2�����}�(hKhh)��}�(hhhM�hKbhKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�h�/// Adds two vectors
�����}�(hKhh)��}�(hhhM�hKahKubh�ubah��/// Adds two vectors
�h�}�h��h��j�  �j�  �j�  �Col4&�j�  �ht]�j	  )��}�(h�const Col4<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhMhKbhKQubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�operator +=�����}�(hKhh)��}�(hhhM:hKlhKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �Col4&�j�  �ht]�j	  )��}�(h�const Col4&�hh�v�����}�(hKhh)��}�(hhhMRhKlhK*ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�operator -=�����}�(hKhh)��}�(hhhM�hKvhK1ubh�ubhhVh]�hjj�  hkhlhmj  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhM�hKvhKubh|�hh�T2�����}�(hKhh)��}�(hhhM�hKvhKubh�ubh�Nh�NubjW  )��}�(hh)��}�(hhhM�hKvhKubh|�hh�S2�����}�(hKhh)��}�(hhhM�hKvhKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�h�/// Subtracts two vectors
�����}�(hKhh)��}�(hhhM�hKuhKubh�ubah��/// Subtracts two vectors
�h�}�h��h��j�  �j�  �j�  �Col4&�j�  �ht]�j	  )��}�(h�const Col4<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhMhKvhKQubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�operator -=�����}�(hKhh)��}�(hhhM#hK�hKubh�ubhhVh]�hjj'  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �Col4&�j�  �ht]�j	  )��}�(h�const Col4&�hh�v�����}�(hKhh)��}�(hhhM;hK�hK*ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�operator *=�����}�(hKhh)��}�(hhhM�hK�hK1ubh�ubhhVh]�hjj=  hkhlhmj  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhM�hK�hKubh|�hh�T2�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�Nh�NubjW  )��}�(hh)��}�(hhhM�hK�hKubh|�hh�S2�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�h�*/// Multiplies two vectors component-wise
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubah��*/// Multiplies two vectors component-wise
�h�}�h��h��j�  �j�  �j�  �Col4&�j�  �ht]�j	  )��}�(h�const Col4<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhM hK�hKQubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�operator *=�����}�(hKhh)��}�(hhhMhK�hKubh�ubhhVh]�hjjr  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �Col4&�j�  �ht]�j	  )��}�(h�const Col4&�hh�v�����}�(hKhh)��}�(hhhM4hK�hK*ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�operator *=�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�1/// Multiplies each vector component by a scalar
�����}�(hKhh)��}�(hhhMhK�hKubh�ubah��1/// Multiplies each vector component by a scalar
�h�}�h��h��j�  �j�  �j�  �Col4&�j�  �ht]�j	  )��}�(h�ValueTypeParam�hh�s�����}�(hKhh)��}�(hhhM�hK�hK-ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�operator /=�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�V/// Divides each vector component by a scalar. The passed argument is checked for 0.0
�����}�(hKhh)��}�(hhhMhK�hKubh�ubah��V/// Divides each vector component by a scalar. The passed argument is checked for 0.0
�h�}�h��h��j�  �j�  �j�  �Col4&�j�  �ht]�j	  )��}�(h�ValueTypeParam�hh�s�����}�(hKhh)��}�(hhhM�hK�hK-ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�
operator *�����}�(hKhh)��}�(hhhMJhK�hKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�h�friend�����}�(hKhh)��}�(hhhM/hK�hKubh�ubhNh�Nh�Nh�K h�]�h�1/// Multiplies each vector component by a scalar
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubah��1/// Multiplies each vector component by a scalar
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�(j	  )��}�(h�ValueTypeParam�hh�s�����}�(hKhh)��}�(hhhMdhK�hK7ubh�ubh�Nh|�j  �j  �ubj	  )��}�(h�const Col4&�hh�v�����}�(hKhh)��}�(hhhMshK�hKFubh�ubh�Nh|�j  �j  �ubej�  Nj�  Nubj�  )��}�(hh�
operator *�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�1/// Multiplies each vector component by a scalar
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubah��1/// Multiplies each vector component by a scalar
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j	  )��}�(h�ValueTypeParam�hh�s�����}�(hKhh)��}�(hhhMhK�hK0ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�
operator *�����}�(hKhh)��}�(hhhM�hK�hKwubh�ubhhVh]�hjj  hkhlhmj  hohq)��}�ht]�hw)��}�(hh)��}�(hhhM�hK�hKubh|�hh�S�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�Nh�Nubasbh�NhNh�Nh�Nh�K h�]�h�1/// Multiplies each vector component by a scalar
�����}�(hKhh)��}�(hhhMWhK�hKubh�ubah��1/// Multiplies each vector component by a scalar
�h�}�h��h��j�  �j�  �j�  �SCol4<typename MultiplicativePromotion<T, S, STD_IS_REPLACEMENT(scalar,S)>::type, 1>�j�  �ht]�j	  )��}�(h�S�hh�s�����}�(hKhh)��}�(hhhMhK�hK�ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�
operator /�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhVh]�hjj5  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�R/// Divides each vector component by a scalar. The scalar value is tested for 0.0
�����}�(hKhh)��}�(hhhMxhK�hKubh�ubah��R/// Divides each vector component by a scalar. The scalar value is tested for 0.0
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j	  )��}�(h�ValueTypeParam�hh�s�����}�(hKhh)��}�(hhhM�hK�hK0ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�
operator *�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhVh]�hjjR  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�*/// Multiplies two vectors component-wise
�����}�(hKhh)��}�(hhhMShK�hKubh�ubah��*/// Multiplies two vectors component-wise
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j	  )��}�(h�const Col4&�hh�v�����}�(hKhh)��}�(hhhM�hK�hK-ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�
operator +�����}�(hKhh)��}�(hhhMhK�hKubh�ubhhVh]�hjjo  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�/// Adds two vectors
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubah��/// Adds two vectors
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j	  )��}�(h�const Col4&�hh�v�����}�(hKhh)��}�(hhhM3hK�hK-ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�
operator -�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h� /// Subtracts vector v2 from v1
�����}�(hKhh)��}�(hhhM|hK�hKubh�ubah�� /// Subtracts vector v2 from v1
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j	  )��}�(h�const Col4&�hh�v�����}�(hKhh)��}�(hhhM�hK�hK-ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�
operator -�����}�(hKhh)��}�(hhhM;hK�hKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�/// Negates vector v
�����}�(hKhh)��}�(hhhMhK�hKubh�ubah��/// Negates vector v
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j�  Nj�  Nubj�  )��}�(hh�operator ==�����}�(hKhh)��}�(hhhM�hK�hK4ubh�ubhhVh]�hjj�  hkhlhmj  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhM�hK�hKubh|�hh�T2�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�Nh�NubjW  )��}�(hh)��}�(hhhM�hK�hKubh|�hh�S2�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�j	  )��}�(h�const Col4<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhM�hK�hKTubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�operator ==�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�j	  )��}�(h�const Col4&�hh�v�����}�(hKhh)��}�(hhhM hK�hK-ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�operator !=�����}�(hKhh)��}�(hhhMzhK�hK4ubh�ubhhVh]�hjj  hkhlhmj  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhMRhK�hKubh|�hh�T2�����}�(hKhh)��}�(hhhM[hK�hKubh�ubh�Nh�NubjW  )��}�(hh)��}�(hhhM_hK�hKubh|�hh�S2�����}�(hKhh)��}�(hhhMchK�hKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�j	  )��}�(h�const Col4<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhM�hK�hKTubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�operator !=�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhVh]�hjj/  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�j	  )��}�(h�const Col4&�hh�v�����}�(hKhh)��}�(hhhM�hK�hK-ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�LessThanOrEqual�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhVh]�hjjE  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�j	  )��}�(h�const Col4&�hh�v�����}�(hKhh)��}�(hhhM hK�hK1ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�GetHashCode�����}�(hKhh)��}�(hhhMa hMhKubh�ubhhVh]�hjj[  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �HashInt�j�  �ht]�j�  Nj�  Nubj�  )��}�(hh�IsEqual�����}�(hKhh)��}�(hhhM� hMhKubh�ubhhVh]�hjjh  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�G/// Tests component-wise if the difference is no bigger than 'epsilon'
�����}�(hKhh)��}�(hhhM� hMhKubh�ubah��G/// Tests component-wise if the difference is no bigger than 'epsilon'
�h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�(j	  )��}�(h�const Col4&�hh�other�����}�(hKhh)��}�(hhhM!hMhK)ubh�ubh�Nh|�j  �j  �ubj	  )��}�(h�ValueTypeParam�hh�epsilon�����}�(hKhh)��}�(hhhM'!hMhK?ubh�ubh�Nh|�j  �j  �ubej�  Nj�  Nubj�  )��}�(hh�Dot�����}�(hKhh)��}�(hhhM�!hMhKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�h�friend�����}�(hKhh)��}�(hhhM�!hMhKubh�ubhNh�Nh�Nh�K h�]�h�(/// Calculates dot product of v1 and v2
�����}�(hKhh)��}�(hhhM�!hMhKubh�ubah��(/// Calculates dot product of v1 and v2
�h�}�h��h��j�  �j�  �j�  �T�j�  �ht]�(j	  )��}�(h�const Col4&�hh�v1�����}�(hKhh)��}�(hhhM"hMhK%ubh�ubh�Nh|�j  �j  �ubj	  )��}�(h�const Col4&�hh�v2�����}�(hKhh)��}�(hhhM"hMhK5ubh�ubh�Nh|�j  �j  �ubej�  Nj�  Nubj�  )��}�(hh�Abs�����}�(hKhh)��}�(hhhM�#hMhKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�h�friend�����}�(hKhh)��}�(hhhM�#hMhKubh�ubhNh�Nh�Nh�K h�]�(h�:/// Returns the vector with absolute value for each entry
�����}�(hKhh)��}�(hhhM�"hMhKubh�ubh�2/// @param[in] v1									input vector to work on
�����}�(hKhh)��}�(hhhM #hMhKubh�ubh�L/// @return												component wise absolute value vector of input vector
�����}�(hKhh)��}�(hhhM3#hMhKubh�ubeh���/// Returns the vector with absolute value for each entry
/// @param[in] v1									input vector to work on
/// @return												component wise absolute value vector of input vector
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j	  )��}�(h�const Col4&�hh�v1�����}�(hKhh)��}�(hhhM$hMhK-ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�Dot�����}�(hKhh)��}�(hhhM�$hMhK`ubh�ubhhVh]�hjj�  hkhlhmj  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhM�$hMhKubh|�hh�T2�����}�(hKhh)��}�(hhhM�$hMhKubh�ubh�Nh�NubjW  )��}�(hh)��}�(hhhM�$hMhKubh|�hh�S2�����}�(hKhh)��}�(hhhM�$hMhKubh�ubh�Nh�Int�h�Nubesbh�h�friend�����}�(hKhh)��}�(hhhM�$hMhK!ubh�ubhNh�Nh�Nh�K h�]�h�(/// Calculates dot product of v1 and v2
�����}�(hKhh)��}�(hhhMS$hMhKubh�ubah��(/// Calculates dot product of v1 and v2
�h�}�h��h��j�  �j�  �j�  �-typename MultiplicativePromotion<T, T2>::type�j�  �ht]�(j	  )��}�(h�const Col4&�hh�v1�����}�(hKhh)��}�(hhhM�$hMhKpubh�ubh�Nh|�j  �j  �ubj	  )��}�(h�const Col4<T2, S2>&�hh�v2�����}�(hKhh)��}�(hhhM%hMhK�ubh�ubh�Nh|�j  �j  �ubej�  Nj�  Nubj�  )��}�(hh�IsZero�����}�(hKhh)��}�(hhhM�%hM#hKubh�ubhhVh]�hjj-  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�&/// Checks if each component is zero.
�����}�(hKhh)��}�(hhhMN%hM"hKubh�ubah��&/// Checks if each component is zero.
�h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�j�  Nj�  Nubj�  )��}�(hh�SetZero�����}�(hKhh)��}�(hhhM&hM)hKubh�ubhhVh]�hjjA  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�!/// Sets all components to zero.
�����}�(hKhh)��}�(hhhM�%hM(hKubh�ubah��!/// Sets all components to zero.
�h�}�h��h��j�  �j�  �j�  �void�j�  �ht]�j�  Nj�  Nubj�  )��}�(hh�
GetAverage�����}�(hKhh)��}�(hhhM}&hM/hKubh�ubhhVh]�hjjU  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�;/// Calculates the average value of 'r', 'g', 'b' and 'a'.
�����}�(hKhh)��}�(hhhM5&hM.hKubh�ubah��;/// Calculates the average value of 'r', 'g', 'b' and 'a'.
�h�}�h��h��j�  �j�  �j�  �T�j�  �ht]�j�  Nj�  Nubj�  )��}�(hh�GetSum�����}�(hKhh)��}�(hhhM�&hM5hKubh�ubhhVh]�hjji  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�1/// Calculates the sum of 'r', 'g', 'b' and 'a'.
�����}�(hKhh)��}�(hhhM�&hM4hKubh�ubah��1/// Calculates the sum of 'r', 'g', 'b' and 'a'.
�h�}�h��h��j�  �j�  �j�  �T�j�  �ht]�j�  Nj�  Nubj�  )��}�(hh�Min�����}�(hKhh)��}�(hhhMs'hM;hKubh�ubhhVh]�hjj}  hkhlhmj  hoNh�h�friend�����}�(hKhh)��}�(hhhMX'hM;hKubh�ubhNh�Nh�Nh�K h�]�h�./// Calculates the minimum of each component.
�����}�(hKhh)��}�(hhhM)'hM:hKubh�ubah��./// Calculates the minimum of each component.
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�(j	  )��}�(h�const Col4&�hh�th�����}�(hKhh)��}�(hhhM�'hM;hK-ubh�ubh�Nh|�j  �j  �ubj	  )��}�(h�const Col4&�hh�other�����}�(hKhh)��}�(hhhM�'hM;hK=ubh�ubh�Nh|�j  �j  �ubej�  Nj�  Nubj�  )��}�(hh�Max�����}�(hKhh)��}�(hhhM�(hMAhKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�h�friend�����}�(hKhh)��}�(hhhMj(hMAhKubh�ubhNh�Nh�Nh�K h�]�h�./// Calculates the maximum of each component.
�����}�(hKhh)��}�(hhhM;(hM@hKubh�ubah��./// Calculates the maximum of each component.
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�(j	  )��}�(h�const Col4&�hh�th�����}�(hKhh)��}�(hhhM�(hMAhK-ubh�ubh�Nh|�j  �j  �ubj	  )��}�(h�const Col4&�hh�other�����}�(hKhh)��}�(hhhM�(hMAhK=ubh�ubh�Nh|�j  �j  �ubej�  Nj�  Nubj�  )��}�(hh�ClampMin�����}�(hKhh)��}�(hhhM�)hMGhKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�'/// Set the minimum of each component.
�����}�(hKhh)��}�(hhhMM)hMFhKubh�ubah��'/// Set the minimum of each component.
�h�}�h��h��j�  �j�  �j�  �void�j�  �ht]�j	  )��}�(h�const Col4&�hh�other�����}�(hKhh)��}�(hhhM�)hMGhK&ubh�ubh��Col4()�h|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�ClampMax�����}�(hKhh)��}�(hhhM\*hMPhKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�'/// Set the maximum of each component.
�����}�(hKhh)��}�(hhhM%*hMOhKubh�ubah��'/// Set the maximum of each component.
�h�}�h��h��j�  �j�  �j�  �void�j�  �ht]�j	  )��}�(h�const Col4&�hh�other�����}�(hKhh)��}�(hhhMq*hMPhK&ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�SetMin�����}�(hKhh)��}�(hhhM2+hMYhKubh�ubhhVh]�hjj  hkhlhmj  hoNh�h�friend�����}�(hKhh)��}�(hhhM+hMYhKubh�ubhNh�Nh�Nh�K h�]�h�'/// Set the minimum of each component.
�����}�(hKhh)��}�(hhhM�*hMXhKubh�ubah��'/// Set the minimum of each component.
�h�}�h��h��j�  �j�  �j�  �void�j�  �ht]�(j	  )��}�(h�Col4&�hh�th�����}�(hKhh)��}�(hhhM?+hMYhK%ubh�ubh�Nh|�j  �j  �ubj	  )��}�(h�const Col4&�hh�other�����}�(hKhh)��}�(hhhMO+hMYhK5ubh�ubh�Nh|�j  �j  �ubej�  Nj�  Nubj�  )��}�(hh�SetMax�����}�(hKhh)��}�(hhhM�+hM_hKubh�ubhhVh]�hjj<  hkhlhmj  hoNh�h�friend�����}�(hKhh)��}�(hhhM�+hM_hKubh�ubhNh�Nh�Nh�K h�]�h�'/// Set the maximum of each component.
�����}�(hKhh)��}�(hhhMt+hM^hKubh�ubah��'/// Set the maximum of each component.
�h�}�h��h��j�  �j�  �j�  �void�j�  �ht]�(j	  )��}�(h�Col4&�hh�th�����}�(hKhh)��}�(hhhM�+hM_hK%ubh�ubh�Nh|�j  �j  �ubj	  )��}�(h�const Col4&�hh�other�����}�(hKhh)��}�(hhhM�+hM_hK5ubh�ubh�Nh|�j  �j  �ubej�  Nj�  Nubj�  )��}�(hh�Clamp01�����}�(hKhh)��}�(hhhMH,hMehKubh�ubhhVh]�hjjh  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�?/// Returns a vector that is clamped to the range [0.0 .. 1.0]
�����}�(hKhh)��}�(hhhM�+hMdhKubh�ubah��?/// Returns a vector that is clamped to the range [0.0 .. 1.0]
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j�  Nj�  Nubj�  )��}�(hh�ToString�����}�(hKhh)��}�(hhhMG.hMohK	ubh�ubhhVh]�hjj|  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�(h�./// Returns a readable string of the content.
�����}�(hKhh)��}�(hhhM-hMkhKubh�ubh�j/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
�����}�(hKhh)��}�(hhhMK-hMlhKubh�ubh�-/// @return												The converted result.
�����}�(hKhh)��}�(hhhM�-hMmhKubh�ubeh���/// Returns a readable string of the content.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
/// @return												The converted result.
�h�}�h��h��j�  �j�  �j�  �String�j�  �ht]�j	  )��}�(h�const FormatStatement*�hh�formatStatement�����}�(hKhh)��}�(hhhMg.hMohK)ubh�ubh��nullptr�h|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�GetMin�����}�(hKhh)��}�(hhhM�/hMuhKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�2/// Returns the minimum of 'r', 'g', 'b' and 'a'.
�����}�(hKhh)��}�(hhhMX/hMthKubh�ubah��2/// Returns the minimum of 'r', 'g', 'b' and 'a'.
�h�}�h��h��j�  �j�  �j�  �T�j�  �ht]�j�  Nj�  Nubj�  )��}�(hh�GetMax�����}�(hKhh)��}�(hhhM0hM{hKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�2/// Returns the maximum of 'r', 'g', 'b' and 'a'.
�����}�(hKhh)��}�(hhhM�/hMzhKubh�ubah��2/// Returns the maximum of 'r', 'g', 'b' and 'a'.
�h�}�h��h��j�  �j�  �j�  �T�j�  �ht]�j�  Nj�  Nubj�  )��}�(hh�GetRightRotated�����}�(hKhh)��}�(hhhM{2hM�hKubh�ubhhVh]�hjj�  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�(h�{/// Returns a vector where the components have been rotated to the right (in the usual (r, g, b, a)-representation). E.g.,
�����}�(hKhh)��}�(hhhM�0hM�hKubh�ubh�A/// with a value of 1 for rots, the result will be (a, r, g, b).
�����}�(hKhh)��}�(hhhM$1hM�hKubh�ubh�q/// @param[in] rots								Number of rotations, may be negative. The result depends only on the number modulo 4.
�����}�(hKhh)��}�(hhhMf1hM�hKubh�ubh�7/// @return												Vector with rotated components.
�����}�(hKhh)��}�(hhhM�1hM�hKubh�ubeh�Xd  /// Returns a vector where the components have been rotated to the right (in the usual (r, g, b, a)-representation). E.g.,
/// with a value of 1 for rots, the result will be (a, r, g, b).
/// @param[in] rots								Number of rotations, may be negative. The result depends only on the number modulo 4.
/// @return												Vector with rotated components.
�h�}�h��h��j�  �j�  �j�  �Col4�j�  �ht]�j	  )��}�(h�Int�hh�rots�����}�(hKhh)��}�(hhhM�2hM�hK%ubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�operator *=�����}�(hKhh)��}�(hhhM�3hM�hK(ubh�ubhhVh]�hjj�  hkhlhmj  hohq)��}�ht]�hw)��}�(hh)��}�(hhhMt3hM�hKubh|�hh�V�����}�(hKhh)��}�(hhhM}3hM�hKubh�ubh�Nh�Nubasbh�NhNh�Nh�Nh�K h�]�h�"/// Multiplies vector by a matrix
�����}�(hKhh)��}�(hhhMG3hM�hKubh�ubah��"/// Multiplies vector by a matrix
�h�}�h��h��j�  �j�  �j�  �Col4&�j�  �ht]�j	  )��}�(h�const SqrMat4<V>&�hh�m�����}�(hKhh)��}�(hhhM�3hM�hKFubh�ubh�Nh|�j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�	NullValue�����}�(hKhh)��}�(hhhM�4hM�hKubh�ubhhVh]�hjj'	  hkhlhmj  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �const Col4&�j�  �ht]�j�  Nj�  NubehjhZhkhlhmjM  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhMjhKhKubh|�hh�T�����}�(hKhh)��}�(hhhMshKhKubh�ubh�Nh�NubjW  )��}�(hh)��}�(hhhMvhKhKubh|�hh�STRIDE�����}�(hKhh)��}�(hhhMzhKhKubh�ubh��1�h�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]�jQ  NjR  Nh��jS  NjT  NjU  �jV  �jW  �jX  �jY  �jZ  �j[  �j\  �j]  Nj^  �j_  �j`  ]�jb  ]�jd  }�ubh)��}�(hNhh9h]�h h�#ifndef STRIDE�����}�(hK
hh)��}�(hhhM05hM�hKubh�ububj�  )��}�(hh�
operator *�����}�(hKhh)��}�(hhhM�5hM�hK�ubh�ubhh9h]�hjj\	  hkhlhmj  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhMz5hM�hKubh|�hh�T�����}�(hKhh)��}�(hhhM�5hM�hKubh�ubh�Nh�NubjW  )��}�(hh)��}�(hhhM�5hM�hKubh|�hh�STR�����}�(hKhh)��}�(hhhM�5hM�hKubh�ubh�Nh�Int�h�Nubhw)��}�(hh)��}�(hhhM�5hM�hK ubh|�hh�S�����}�(hKhh)��}�(hhhM�5hM�hK)ubh�ubh�Nh�Nubesbh�NhNh�Nh�Nh�K h�]�h�1/// Multiplies each vector component by a scalar
�����}�(hKhh)��}�(hhhM?5hM�hKubh�ubah��1/// Multiplies each vector component by a scalar
�h�}�h��h��j�  �j�  �j�  �SCol4<typename MultiplicativePromotion<T, S, STD_IS_REPLACEMENT(scalar,S)>::type, 1>�j�  �ht]�(j	  )��}�(h�S�hh�s�����}�(hKhh)��}�(hhhM6hM�hK�ubh�ubh�Nh|�j  �j  �ubj	  )��}�(h�const Col4<T, STR>&�hh�v�����}�(hKhh)��}�(hhhM6hM�hK�ubh�ubh�Nh|�j  �j  �ubej�  Nj�  Nubj�  )��}�(hh�PrivateGetDataType�����}�(hKhh)��}�(hhhM�6hM�hKKubh�ubhh9h]�hjj�	  hkhlhmj  hohq)��}�ht]�(jW  )��}�(hh)��}�(hhhM�6hM�hKubh|�hh�POLICY�����}�(hKhh)��}�(hhhM�6hM�hKubh�ubh�Nh�GET_DATATYPE_POLICY�h�Nubhw)��}�(hh)��}�(hhhM�6hM�hK'ubh|�hh�T�����}�(hKhh)��}�(hhhM�6hM�hK0ubh�ubh�Nh�Nubesbh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �Result<DataType>�j�  �ht]�(j	  )��}�(h�Col4<T, 1>**�h�anonymous_param_1�h�Nh|�j  �j  �ubj	  )��}�(h�OverloadRank1�h�anonymous_param_2�h�Nh|�j  �j  �ubej�  Nj�  �DataType�ubh)��}�(hNhh9h]�h h�#endif�����}�(hK
hh)��}�(hhhM�7hM�hKubh�ububehjh=hkhlhm�	namespace�hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h���preprocessorConditions�]��root�hh N�containsResourceId���registry���usings����minIndentation�K �maxIndentation�K�firstMember��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�7hM�hKubh�ububehjhhkhlhmj�	  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��j�	  ]�j�	  hh ]�(hh'h0h9hBhKhVjO	  jX	  j�	  j�	  j�	  ej�	  �j�	  �j�	  ���hxx1�N�hxx2�N�snippets�}�j�	  K j�	  K j�	  �ub.