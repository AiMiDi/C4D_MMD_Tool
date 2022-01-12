��0�      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��JD:\C4D_MMD_Tool\sdk_r21\frameworks\core.framework\source\maxon\math\vec2.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh)��}�(hNhhh]�h h�#ifndef MAXON_VECTORMODE�����}�(hK
hh)��}�(hhhKbhKhKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhK�hKhKubh�ububh)��}�(hh�maxon�����}�(hKhh)��}�(hhhK�hKhKubh�ubhhh]�(h)��}�(hNhh9h]�h h�#ifdef STRIDE�����}�(hK
hh)��}�(hhhMhKhKubh�ububh)��}�(hNhh9h]�h h�#else�����}�(hK
hh)��}�(hhhMQhKhKubh�ububh �Class���)��}�(hh�Vec2�����}�(hKhh)��}�(hhhM�hKhK.ubh�ubhh9h]�(h �	TypeAlias���)��}�(hh�Rebind�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhVh]��
simpleName�he�access��public��kind��	typealias��template�h �Template���)��}��params�]�h �TypeTemplateParam���)��}�(hh)��}�(hhhM�hKhKub�pack��hh�U�����}�(hKhh)��}�(hhhM�hKhKubh�ub�default�N�variance�Nubasb�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���bases�]��Vec2<U,STRIDE>�hlh	��aubh`)��}�(hh�VectorStrideType�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhVh]�hjh�hkhlhmhnhoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]��"std::integral_constant<Int,STRIDE>�hlh	��aubh`)��}�(hh�	ValueType�����}�(hKhh)��}�(hhhMhKhKubh�ubhhVh]�hjh�hkhlhmhnhoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]��T�hlh	��aubh`)��}�(hh�ValueTypeParam�����}�(hKhh)��}�(hhhM%hKhKubh�ubhhVh]�hjh�hkhlhmhnhoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]��typename ByValueParam<T>::type�hlh	��aubh`)��}�(hh�	Unstrided�����}�(hKhh)��}�(hhhM]hKhKubh�ubhhVh]�hjh�hkhlhmhnhoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]��	Vec2<T,1>�hlh	��aubh`)��}�(hh�BoolType�����}�(hKhh)��}�(hhhMhKhKubh�ubhhVh]�hjh�hkhlhmhnhoNh�NhNh�Nh�Nh�K h�]�(h�U/// The type returned by comparisons. If the template argument for T is a SIMD type,
�����}�(hKhh)��}�(hhhMwhKhKubh�ubh�K/// this will be a SIMD type, too, which contains the per-element results.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubeh���/// The type returned by comparisons. If the template argument for T is a SIMD type,
/// this will be a SIMD type, too, which contains the per-element results.
�h�}�h��h�]��decltype(T()==T())�hlh	��aubh)��}�(hNhhVh]�h h�#ifdef STRIDE�����}�(hK
hh)��}�(hhhMAhKhKubh�ububh �Variable���)��}�(hh�x�����}�(hKhh)��}�(hhhMRhKhKubh�ubhhVh]�hjh�hkhlhm�variable�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h���static��ubh�)��}�(hh�y�����}�(hKhh)��}�(hhhMXhKhKubh�ubhhVh]�hjj  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubh)��}�(hNhhVh]�h h�#else�����}�(hK
hh)��}�(hhhM[hKhKubh�ububhU)��}�(hh�Zanonymous#D:\C4D_MMD_Tool\sdk_r21\frameworks\core.framework\source\maxon\math\vec2.h(31,2)�����}�(hKhh)��}�(hhhMbhKhKubh�ubhhVh]�(h�)��}�(hh�x�����}�(hKhh)��}�(hhhMlhKhKubh�ubhj  h]�hjj!  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubh�)��}�(hh�	_xpadding�����}�(hKhh)��}�(hhhMqhKhKubh�ubhj  h]�hjj-  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubehjj  hkhlhm�class�hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]��	interface�N�refKind�Nh���refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent���forward���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���ambiguousCalls�]��	selfCalls�]��methodNames�}�ubhU)��}�(hh�Zanonymous#D:\C4D_MMD_Tool\sdk_r21\frameworks\core.framework\source\maxon\math\vec2.h(32,2)�����}�(hKhh)��}�(hhhM�hK hKubh�ubhhVh]�(h�)��}�(hh�y�����}�(hKhh)��}�(hhhM�hK hKubh�ubhjN  h]�hjj[  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubh�)��}�(hh�	_ypadding�����}�(hKhh)��}�(hhhM�hK hKubh�ubhjN  h]�hjjg  hkhlhmh�hoNh�Nh�T�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubehjjR  hkhlhmj5  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]�j9  Nj:  Nh��j;  Nj<  Nj=  �j>  �j?  �j@  �jA  �jB  �jC  �jD  �jE  NjF  �jG  �jH  ]�jJ  ]�jL  }�ubh)��}�(hNhhVh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hK!hKubh�ububh �Function���)��}�(h�constructor�hhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�//// Initializes all vector components with 0.0
�����}�(hKhh)��}�(hhhM�hK#hKubh�ubah��//// Initializes all vector components with 0.0
�h�}�h��h���explicit���deleted���retType��void��const��ht]��
observable�N�result�Nubj  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�4/// Initializes all vector components with a scalar
�����}�(hKhh)��}�(hhhM hK&hKubh�ubah��4/// Initializes all vector components with a scalar
�h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�h �	Parameter���)��}�(h�ValueTypeParam�hh�in�����}�(hKhh)��}�(hhhMRhK'hKubh�ubh�Nh|��input���output��ubaj�  Nj�  Nubj  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�3/// Initializes all vector components individually
�����}�(hKhh)��}�(hhhMkhK)hKubh�ubah��3/// Initializes all vector components individually
�h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�(j�  )��}�(h�ValueTypeParam�hh�ix�����}�(hKhh)��}�(hhhM�hK*hKubh�ubh�Nh|�j�  �j�  �ubj�  )��}�(h�ValueTypeParam�hh�iy�����}�(hKhh)��}�(hhhM�hK*hK2ubh�ubh�Nh|�j�  �j�  �ubej�  Nj�  Nubj  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhM&hK-hKubh|�hh�T2�����}�(hKhh)��}�(hhhM/hK-hKubh�ubh�Nh�Nubh �NontypeTemplateParam���)��}�(hh)��}�(hhhM3hK-hKubh|�hh�S2�����}�(hKhh)��}�(hhhM7hK-hKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�h�3/// Initializes components from another 2d vector.
�����}�(hKhh)��}�(hhhM�hK,hKubh�ubah��3/// Initializes components from another 2d vector.
�h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�j�  )��}�(h�const Vec2<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhM]hK-hKCubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hohq)��}�ht]�j�  )��}�(hh)��}�(hhhM�hK0hKubh|�hh�S2�����}�(hKhh)��}�(hhhM�hK0hKubh�ubh�Nh�Int�h�Nubasbh�NhNh�Nh�Nh�K h�]�h�3/// Initializes components from another 2d vector.
�����}�(hKhh)��}�(hhhM}hK/hKubh�ubah��3/// Initializes components from another 2d vector.
�h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�j�  )��}�(h�const Vec2<T, S2>&�hh�v�����}�(hKhh)��}�(hhhM�hK0hK,ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhMNhK3hKubh|�hh�T2�����}�(hKhh)��}�(hhhMWhK3hKubh�ubh�Nh�Nubj�  )��}�(hh)��}�(hhhM[hK3hKubh|�hh�S2�����}�(hKhh)��}�(hhhM_hK3hKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�h�N/// Initializes components from a 3d vector. The z-component of v is ignored.
�����}�(hKhh)��}�(hhhM�hK2hKubh�ubah��N/// Initializes components from a 3d vector. The z-component of v is ignored.
�h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�j�  )��}�(h�const Vec3<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhM�hK3hKCubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�6/// Skips initialization of vector (for better speed)
�����}�(hKhh)��}�(hhhM�hK5hKubh�ubah��6/// Skips initialization of vector (for better speed)
�h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�j�  )��}�(h�ENUM_DONT_INITIALIZE�hh�v�����}�(hKhh)��}�(hhhM�hK6hK%ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hj�  hhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�(h��/// When STRIDE is not 1, we have to provide copy constructor and operator because the default ones would also copy the padding.
�����}�(hKhh)��}�(hhhMhK8hKubh�ubh��/// When STRIDE is 1, we want to avoid to declare them (because then the type wouldn't be trivially copyable any longer), so we use DummyParamType for the parameter in that case.
�����}�(hKhh)��}�(hhhM�hK9hKubh�ubeh�X4  /// When STRIDE is not 1, we have to provide copy constructor and operator because the default ones would also copy the padding.
/// When STRIDE is 1, we want to avoid to declare them (because then the type wouldn't be trivially copyable any longer), so we use DummyParamType for the parameter in that case.
�h�}�h��h��j�  �j�  �j�  j�  j�  �ht]�j�  )��}�(h�Gconst typename std::conditional<STRIDE==1, DummyParamType, Vec2>::type&�hh�src�����}�(hKhh)��}�(hhhM�hK:hK`ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�
operator =�����}�(hKhh)��}�(hhhM�	hKChKubh�ubhhVh]�hjj�  hkhlhm�function�hoNh�NhNh�Nh�Nh�K h�]�(h�/// Copies the source vector.
�����}�(hKhh)��}�(hhhM 	hK?hKubh�ubh�)/// @param[in] src								Source vector.
�����}�(hKhh)��}�(hhhM?	hK@hKubh�ubh�/// @return												*this.
�����}�(hKhh)��}�(hhhMi	hKAhKubh�ubeh��e/// Copies the source vector.
/// @param[in] src								Source vector.
/// @return												*this.
�h�}�h��h��j�  �j�  �j�  �Vec2&�j�  �ht]�j�  )��}�(h�Gconst typename std::conditional<STRIDE==1, DummyParamType, Vec2>::type&�hh�src�����}�(hKhh)��}�(hhhM?
hKChK]ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�operator []�����}�(hKhh)��}�(hhhM�
hKKhKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�p/// Accesses vector component: index 0 is 'x', index 1 is 'y'. All other values must not be used and will crash
�����}�(hKhh)��}�(hhhMv
hKJhKubh�ubah��p/// Accesses vector component: index 0 is 'x', index 1 is 'y'. All other values must not be used and will crash
�h�}�h��h��j�  �j�  �j�  �T&�j�  �ht]�j�  )��}�(h�Int�hh�l�����}�(hKhh)��}�(hhhM�
hKKhKubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�operator []�����}�(hKhh)��}�(hhhM�hKRhKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�q/// Accesses vector component: index 0 is 'x', index 1 is 'y'.  All other values must not be used and will crash
�����}�(hKhh)��}�(hhhMBhKQhKubh�ubah��q/// Accesses vector component: index 0 is 'x', index 1 is 'y'.  All other values must not be used and will crash
�h�}�h��h��j�  �j�  �j�  �ValueTypeParam�j�  �ht]�j�  )��}�(h�Int�hh�l�����}�(hKhh)��}�(hhhM�hKRhK!ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�operator +=�����}�(hKhh)��}�(hhhMbhKYhK'ubh�ubhhVh]�hjj�  hkhlhmj�  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhMGhKYhKubh|�hh�T2�����}�(hKhh)��}�(hhhMPhKYhKubh�ubh�Nh�Nubj�  )��}�(hh)��}�(hhhMThKYhKubh|�hh�S2�����}�(hKhh)��}�(hhhMXhKYhKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�h�/// Adds two vectors
�����}�(hKhh)��}�(hhhM'hKXhKubh�ubah��/// Adds two vectors
�h�}�h��h��j�  �j�  �j�  �Vec2&�j�  �ht]�j�  )��}�(h�const Vec2<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhM�hKYhKGubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�operator +=�����}�(hKhh)��}�(hhhM�hKfhKubh�ubhhVh]�hjj  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�(h�/// Adds a vector.
�����}�(hKhh)��}�(hhhMhKahKubh�ubh��/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
�����}�(hKhh)��}�(hhhM%hKbhKubh�ubh�-/// @param[in] v									Vector to be added.
�����}�(hKhh)��}�(hhhM�hKchKubh�ubh�/// @return												*this.
�����}�(hKhh)��}�(hhhMhKdhKubh�ubeh�X   /// Adds a vector.
/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
/// @param[in] v									Vector to be added.
/// @return												*this.
�h�}�h��h��j�  �j�  �j�  �Vec2&�j�  �ht]�j�  )��}�(h�const Vec2&�hh�v�����}�(hKhh)��}�(hhhM�hKfhK ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�operator -=�����}�(hKhh)��}�(hhhM"hKnhK'ubh�ubhhVh]�hjjN  hkhlhmj�  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhMhKnhKubh|�hh�T2�����}�(hKhh)��}�(hhhMhKnhKubh�ubh�Nh�Nubj�  )��}�(hh)��}�(hhhMhKnhKubh|�hh�S2�����}�(hKhh)��}�(hhhMhKnhKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�h�/// Subtracts two vectors
�����}�(hKhh)��}�(hhhM�hKmhKubh�ubah��/// Subtracts two vectors
�h�}�h��h��j�  �j�  �j�  �Vec2&�j�  �ht]�j�  )��}�(h�const Vec2<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhMBhKnhKGubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�operator -=�����}�(hKhh)��}�(hhhMlhK{hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�(h�/// Subtracts a vector.
�����}�(hKhh)��}�(hhhM�hKvhKubh�ubh��/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
�����}�(hKhh)��}�(hhhM�hKwhKubh�ubh�=/// @param[in] v									Vector to be substracted from this.
�����}�(hKhh)��}�(hhhM�hKxhKubh�ubh�/// @return												*this.
�����}�(hKhh)��}�(hhhM�hKyhKubh�ubeh�X5  /// Subtracts a vector.
/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
/// @param[in] v									Vector to be substracted from this.
/// @return												*this.
�h�}�h��h��j�  �j�  �j�  �Vec2&�j�  �ht]�j�  )��}�(h�const Vec2&�hh�v�����}�(hKhh)��}�(hhhM�hK{hK ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�operator *=�����}�(hKhh)��}�(hhhMhK�hK'ubh�ubhhVh]�hjj�  hkhlhmj�  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhM�hK�hKubh|�hh�T2�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�Nh�Nubj�  )��}�(hh)��}�(hhhM�hK�hKubh|�hh�S2�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�h�*/// Multiplies two vectors component-wise
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubah��*/// Multiplies two vectors component-wise
�h�}�h��h��j�  �j�  �j�  �Vec2&�j�  �ht]�j�  )��}�(h�const Vec2<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhM'hK�hKGubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�operator *=�����}�(hKhh)��}�(hhhM^hK�hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�(h�+/// Multiplies with vector component-wise.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh��/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�7/// @param[in] v									Vector to be multiplied with.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�/// @return												*this.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubeh�XB  /// Multiplies with vector component-wise.
/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector.
/// @param[in] v									Vector to be multiplied with.
/// @return												*this.
�h�}�h��h��j�  �j�  �j�  �Vec2&�j�  �ht]�j�  )��}�(h�const Vec2&�hh�v�����}�(hKhh)��}�(hhhMvhK�hK ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�operator *=�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhVh]�hjj  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�1/// Multiplies each vector component by a scalar
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubah��1/// Multiplies each vector component by a scalar
�h�}�h��h��j�  �j�  �j�  �Vec2&�j�  �ht]�j�  )��}�(h�ValueTypeParam�hh�s�����}�(hKhh)��}�(hhhM�hK�hK#ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�operator /=�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhVh]�hjj3  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�V/// Divides each vector component by a scalar. The passed argument is checked for 0.0
�����}�(hKhh)��}�(hhhM+hK�hKubh�ubah��V/// Divides each vector component by a scalar. The passed argument is checked for 0.0
�h�}�h��h��j�  �j�  �j�  �Vec2&�j�  �ht]�j�  )��}�(h�ValueTypeParam�hh�s�����}�(hKhh)��}�(hhhM�hK�hK#ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�
operator *�����}�(hKhh)��}�(hhhM,hK�hKubh�ubhhVh]�hjjP  hkhlhmj�  hoNh�h�friend�����}�(hKhh)��}�(hhhMhK�hKubh�ubhNh�Nh�Nh�K h�]�h�1/// Multiplies each vector component by a scalar
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubah��1/// Multiplies each vector component by a scalar
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�(j�  )��}�(h�ValueTypeParam�hh�s�����}�(hKhh)��}�(hhhMFhK�hK-ubh�ubh�Nh|�j�  �j�  �ubj�  )��}�(h�const Vec2&�hh�v�����}�(hKhh)��}�(hhhMUhK�hK<ubh�ubh�Nh|�j�  �j�  �ubej�  Nj�  Nubj  )��}�(hh�
operator *�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhVh]�hjj|  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�1/// Multiplies each vector component by a scalar
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubah��1/// Multiplies each vector component by a scalar
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j�  )��}�(h�ValueTypeParam�hh�s�����}�(hKhh)��}�(hhhM�hK�hK&ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�
operator *�����}�(hKhh)��}�(hhhM�hK�hKhubh�ubhhVh]�hjj�  hkhlhmj�  hohq)��}�ht]�hw)��}�(hh)��}�(hhhMKhK�hKubh|�hh�S�����}�(hKhh)��}�(hhhMThK�hKubh�ubh�Nh�Nubasbh�NhNh�Nh�Nh�K h�]�h�1/// Multiplies each vector component by a scalar
�����}�(hKhh)��}�(hhhMhK�hKubh�ubah��1/// Multiplies each vector component by a scalar
�h�}�h��h��j�  �j�  �j�  �OVec2<typename MultiplicativePromotion<T, S, std::is_scalar<S>::value>::type, 1>�j�  �ht]�j�  )��}�(h�S�hh�s�����}�(hKhh)��}�(hhhM�hK�hKuubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�
operator /�����}�(hKhh)��}�(hhhMphK�hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�R/// Divides each vector component by a scalar. The scalar value is tested for 0.0
�����}�(hKhh)��}�(hhhMhK�hKubh�ubah��R/// Divides each vector component by a scalar. The scalar value is tested for 0.0
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j�  )��}�(h�ValueTypeParam�hh�s�����}�(hKhh)��}�(hhhM�hK�hK&ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�
operator *�����}�(hKhh)��}�(hhhM	hK�hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�*/// Multiplies two vectors component-wise
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubah��*/// Multiplies two vectors component-wise
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j�  )��}�(h�const Vec2&�hh�v�����}�(hKhh)��}�(hhhM hK�hK#ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�
operator +�����}�(hKhh)��}�(hhhMwhK�hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�/// Adds two vectors
�����}�(hKhh)��}�(hhhMWhK�hKubh�ubah��/// Adds two vectors
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j�  )��}�(h�const Vec2&�hh�v�����}�(hKhh)��}�(hhhM�hK�hK#ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�
operator -�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhVh]�hjj  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h� /// Subtracts vector v2 from v1
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubah�� /// Subtracts vector v2 from v1
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j�  )��}�(h�const Vec2&�hh�v�����}�(hKhh)��}�(hhhMhK�hK#ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�
operator -�����}�(hKhh)��}�(hhhM^hK�hKubh�ubhhVh]�hjj7  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�/// Negates vector v
�����}�(hKhh)��}�(hhhM>hK�hKubh�ubah��/// Negates vector v
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j�  Nj�  Nubj  )��}�(hh�operator ==�����}�(hKhh)��}�(hhhM�hK�hK*ubh�ubhhVh]�hjjK  hkhlhmj�  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhM�hK�hKubh|�hh�T2�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�Nh�Nubj�  )��}�(hh)��}�(hhhM�hK�hKubh|�hh�S2�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�(h�/// Equality operator.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh��/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
�����}�(hKhh)��}�(hhhM	hK�hKubh�ubh�,/// @param[in] v									Comparison vector.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�F/// @return												True if this and v are equal, otherwise false.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubeh�XJ  /// Equality operator.
/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
/// @param[in] v									Comparison vector.
/// @return												True if this and v are equal, otherwise false.
�h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�j�  )��}�(h�const Vec2<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhM�hK�hKJubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�operator ==�����}�(hKhh)��}�(hhhM"hK�hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�(h�/// Equality operator.
�����}�(hKhh)��}�(hhhMohK�hKubh�ubh��/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�,/// @param[in] v									Comparison vector.
�����}�(hKhh)��}�(hhhMIhK�hKubh�ubh�F/// @return												True if this and v are equal, otherwise false.
�����}�(hKhh)��}�(hhhMvhK�hKubh�ubeh�XJ  /// Equality operator.
/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
/// @param[in] v									Comparison vector.
/// @return												True if this and v are equal, otherwise false.
�h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�j�  )��}�(h�const Vec2&�hh�v�����}�(hKhh)��}�(hhhM:hK�hK#ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�operator !=�����}�(hKhh)��}�(hhhM� hK�hK*ubh�ubhhVh]�hjj�  hkhlhmj�  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhM� hK�hKubh|�hh�T2�����}�(hKhh)��}�(hhhM� hK�hKubh�ubh�Nh�Nubj�  )��}�(hh)��}�(hhhM� hK�hKubh|�hh�S2�����}�(hKhh)��}�(hhhM� hK�hKubh�ubh�Nh�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�(h�/// Inequality operator.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�,/// @param[in] v									Comparison vector.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�F/// @return												False if this and v are equal, otherwise true.
�����}�(hKhh)��}�(hhhM hK�hKubh�ubeh���/// Inequality operator.
/// @param[in] v									Comparison vector.
/// @return												False if this and v are equal, otherwise true.
�h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�j�  )��}�(h�const Vec2<T2, S2>&�hh�v�����}�(hKhh)��}�(hhhM� hK�hKJubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�operator !=�����}�(hKhh)��}�(hhhM<#hK�hKubh�ubhhVh]�hjj  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�(h�/// Inequality operator.
�����}�(hKhh)��}�(hhhM�!hK�hKubh�ubh��/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
�����}�(hKhh)��}�(hhhM�!hK�hKubh�ubh�,/// @param[in] v									Comparison vector.
�����}�(hKhh)��}�(hhhMc"hK�hKubh�ubh�F/// @return												False if this and v are equal, otherwise true.
�����}�(hKhh)��}�(hhhM�"hK�hKubh�ubeh�XL  /// Inequality operator.
/// We repeat the function template as non-template function, this allows the usage in contexts where the parameter is not a vector itself, but something with a conversion operator to a vector
/// @param[in] v									Comparison vector.
/// @return												False if this and v are equal, otherwise true.
�h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�j�  )��}�(h�const Vec2&�hh�v�����}�(hKhh)��}�(hhhMT#hK�hK#ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�LessThanOrEqual�����}�(hKhh)��}�(hhhMJ$hMhKubh�ubhhVh]�hjj1  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�j�  )��}�(h�const Vec2&�hh�v�����}�(hKhh)��}�(hhhMf$hMhK(ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�LessThan�����}�(hKhh)��}�(hhhMM%hMhKubh�ubhhVh]�hjjG  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�j�  )��}�(h�const Vec2&�hh�v�����}�(hKhh)��}�(hhhMb%hMhK ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�GetHashCode�����}�(hKhh)��}�(hhhM�&hMhKubh�ubhhVh]�hjj]  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�(h�N/// Returns the hash code of the vector (used for hash maps and comparisons).
�����}�(hKhh)��}�(hhhM�%hMhKubh�ubh�//// @return												The vector's hash code.
�����}�(hKhh)��}�(hhhM;&hMhKubh�ubeh��}/// Returns the hash code of the vector (used for hash maps and comparisons).
/// @return												The vector's hash code.
�h�}�h��h��j�  �j�  �j�  �UInt�j�  �ht]�j�  Nj�  Nubj  )��}�(hh�IsEqual�����}�(hKhh)��}�(hhhMX'hMhKubh�ubhhVh]�hjjw  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�G/// Tests component-wise if the difference is no bigger than 'epsilon'
�����}�(hKhh)��}�(hhhM'hMhKubh�ubah��G/// Tests component-wise if the difference is no bigger than 'epsilon'
�h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�(j�  )��}�(h�const Vec2&�hh�other�����}�(hKhh)��}�(hhhMl'hMhKubh�ubh�Nh|�j�  �j�  �ubj�  )��}�(h�ValueTypeParam�hh�epsilon�����}�(hKhh)��}�(hhhM�'hMhK5ubh�ubh�Nh|�j�  �j�  �ubej�  Nj�  Nubj  )��}�(hh�Dot�����}�(hKhh)��}�(hhhM(hM$hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�h�friend�����}�(hKhh)��}�(hhhM(hM$hKubh�ubhNh�Nh�Nh�K h�]�h�(/// Calculates dot product of v1 and v2
�����}�(hKhh)��}�(hhhM�'hM#hKubh�ubah��(/// Calculates dot product of v1 and v2
�h�}�h��h��j�  �j�  �j�  �T�j�  �ht]�(j�  )��}�(h�const Vec2&�hh�v1�����}�(hKhh)��}�(hhhM (hM$hKubh�ubh�Nh|�j�  �j�  �ubj�  )��}�(h�const Vec2&�hh�v2�����}�(hKhh)��}�(hhhM0(hM$hK+ubh�ubh�Nh|�j�  �j�  �ubej�  Nj�  Nubj  )��}�(hh�Abs�����}�(hKhh)��}�(hhhM�)hM.hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�h�friend�����}�(hKhh)��}�(hhhM�)hM.hKubh�ubhNh�Nh�Nh�K h�]�(h�:/// returns the vector with absolute value for each entry
�����}�(hKhh)��}�(hhhM�(hM*hKubh�ubh�2/// @param[in] v1									input vector to work on
�����}�(hKhh)��}�(hhhM�(hM+hKubh�ubh�L/// @return												component wise absolute value vector of input vector
�����}�(hKhh)��}�(hhhM*)hM,hKubh�ubeh���/// returns the vector with absolute value for each entry
/// @param[in] v1									input vector to work on
/// @return												component wise absolute value vector of input vector
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j�  )��}�(h�const Vec2&�hh�v1�����}�(hKhh)��}�(hhhM�)hM.hK#ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�Dot�����}�(hKhh)��}�(hhhM�*hM4hKVubh�ubhhVh]�hjj�  hkhlhmj�  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhM]*hM4hKubh|�hh�T2�����}�(hKhh)��}�(hhhMf*hM4hKubh�ubh�Nh�Nubj�  )��}�(hh)��}�(hhhMj*hM4hKubh|�hh�S2�����}�(hKhh)��}�(hhhMn*hM4hKubh�ubh�Nh�Int�h�Nubesbh�h�friend�����}�(hKhh)��}�(hhhMr*hM4hK!ubh�ubhNh�Nh�Nh�K h�]�h�(/// Calculates dot product of v1 and v2
�����}�(hKhh)��}�(hhhM**hM3hKubh�ubah��(/// Calculates dot product of v1 and v2
�h�}�h��h��j�  �j�  �j�  �-typename MultiplicativePromotion<T, T2>::type�j�  �ht]�(j�  )��}�(h�const Vec2&�hh�v1�����}�(hKhh)��}�(hhhM�*hM4hKfubh�ubh�Nh|�j�  �j�  �ubj�  )��}�(h�const Vec2<T2, S2>&�hh�v2�����}�(hKhh)��}�(hhhM�*hM4hK~ubh�ubh�Nh|�j�  �j�  �ubej�  Nj�  Nubj  )��}�(hh�IsZero�����}�(hKhh)��}�(hhhM/+hM:hKubh�ubhhVh]�hjj<  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�&/// Checks if each component is zero.
�����}�(hKhh)��}�(hhhM�*hM9hKubh�ubah��&/// Checks if each component is zero.
�h�}�h��h��j�  �j�  �j�  �BoolType�j�  �ht]�j�  Nj�  Nubj  )��}�(hh�SetZero�����}�(hKhh)��}�(hhhM�+hM@hKubh�ubhhVh]�hjjP  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�!/// Sets all components to zero.
�����}�(hKhh)��}�(hhhMg+hM?hKubh�ubah��!/// Sets all components to zero.
�h�}�h��h��j�  �j�  �j�  �void�j�  �ht]�j�  Nj�  Nubj  )��}�(hh�
GetAverage�����}�(hKhh)��}�(hhhM�+hMFhKubh�ubhhVh]�hjjd  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�5/// Calculates the average value of 'x', 'y' and 'z'
�����}�(hKhh)��}�(hhhM�+hMEhKubh�ubah��5/// Calculates the average value of 'x', 'y' and 'z'
�h�}�h��h��j�  �j�  �j�  �T�j�  �ht]�j�  Nj�  Nubj  )��}�(hh�GetSum�����}�(hKhh)��}�(hhhML,hMLhKubh�ubhhVh]�hjjx  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�+/// Calculates the sum of 'x', 'y' and 'z'
�����}�(hKhh)��}�(hhhM,hMKhKubh�ubah��+/// Calculates the sum of 'x', 'y' and 'z'
�h�}�h��h��j�  �j�  �j�  �T�j�  �ht]�j�  Nj�  Nubj  )��}�(hh�Min�����}�(hKhh)��}�(hhhM�,hMRhKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�h�friend�����}�(hKhh)��}�(hhhM�,hMRhKubh�ubhNh�Nh�Nh�K h�]�h�./// Calculates the minimum of each component.
�����}�(hKhh)��}�(hhhMs,hMQhKubh�ubah��./// Calculates the minimum of each component.
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�(j�  )��}�(h�const Vec2&�hh�a�����}�(hKhh)��}�(hhhM�,hMRhK#ubh�ubh�Nh|�j�  �j�  �ubj�  )��}�(h�const Vec2&�hh�other�����}�(hKhh)��}�(hhhM�,hMRhK2ubh�ubh�Nh|�j�  �j�  �ubej�  Nj�  Nubj  )��}�(hh�Max�����}�(hKhh)��}�(hhhMt-hMXhKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�h�friend�����}�(hKhh)��}�(hhhMc-hMXhKubh�ubhNh�Nh�Nh�K h�]�h�./// Calculates the maximum of each component.
�����}�(hKhh)��}�(hhhM4-hMWhKubh�ubah��./// Calculates the maximum of each component.
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�(j�  )��}�(h�const Vec2&�hh�a�����}�(hKhh)��}�(hhhM�-hMXhK#ubh�ubh�Nh|�j�  �j�  �ubj�  )��}�(h�const Vec2&�hh�other�����}�(hKhh)��}�(hhhM�-hMXhK2ubh�ubh�Nh|�j�  �j�  �ubej�  Nj�  Nubj  )��}�(hh�ClampMin�����}�(hKhh)��}�(hhhM".hM^hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�'/// Set the minimum of each component.
�����}�(hKhh)��}�(hhhM�-hM]hKubh�ubah��'/// Set the minimum of each component.
�h�}�h��h��j�  �j�  �j�  �void�j�  �ht]�j�  )��}�(h�const Vec2&�hh�other�����}�(hKhh)��}�(hhhM7.hM^hKubh�ubh��Vec2()�h|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�ClampMax�����}�(hKhh)��}�(hhhM�.hMehKubh�ubhhVh]�hjj  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�'/// Set the maximum of each component.
�����}�(hKhh)��}�(hhhM�.hMdhKubh�ubah��'/// Set the maximum of each component.
�h�}�h��h��j�  �j�  �j�  �void�j�  �ht]�j�  )��}�(h�const Vec2&�hh�other�����}�(hKhh)��}�(hhhM�.hMehKubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�SetMin�����}�(hKhh)��}�(hhhMH/hMlhKubh�ubhhVh]�hjj  hkhlhmj�  hoNh�h�friend�����}�(hKhh)��}�(hhhM</hMlhKubh�ubhNh�Nh�Nh�K h�]�h�'/// Set the minimum of each component.
�����}�(hKhh)��}�(hhhM/hMkhKubh�ubah��'/// Set the minimum of each component.
�h�}�h��h��j�  �j�  �j�  �void�j�  �ht]�(j�  )��}�(h�Vec2&�hh�a�����}�(hKhh)��}�(hhhMU/hMlhKubh�ubh�Nh|�j�  �j�  �ubj�  )��}�(h�const Vec2&�hh�other�����}�(hKhh)��}�(hhhMd/hMlhK*ubh�ubh�Nh|�j�  �j�  �ubej�  Nj�  Nubj  )��}�(hh�SetMax�����}�(hKhh)��}�(hhhM�/hMrhKubh�ubhhVh]�hjjK  hkhlhmj�  hoNh�h�friend�����}�(hKhh)��}�(hhhM�/hMrhKubh�ubhNh�Nh�Nh�K h�]�h�'/// Set the maximum of each component.
�����}�(hKhh)��}�(hhhM�/hMqhKubh�ubah��'/// Set the maximum of each component.
�h�}�h��h��j�  �j�  �j�  �void�j�  �ht]�(j�  )��}�(h�Vec2&�hh�a�����}�(hKhh)��}�(hhhM�/hMrhKubh�ubh�Nh|�j�  �j�  �ubj�  )��}�(h�const Vec2&�hh�other�����}�(hKhh)��}�(hhhM�/hMrhK*ubh�ubh�Nh|�j�  �j�  �ubej�  Nj�  Nubj  )��}�(hh�Clamp01�����}�(hKhh)��}�(hhhMF0hMxhKubh�ubhhVh]�hjjw  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�?/// Returns a vector that is clamped to the range [0.0 .. 1.0]
�����}�(hKhh)��}�(hhhM�/hMwhKubh�ubah��?/// Returns a vector that is clamped to the range [0.0 .. 1.0]
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j�  Nj�  Nubj  )��}�(hh�	GetLength�����}�(hKhh)��}�(hhhM�0hM~hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�%/// Returns the length of the vector
�����}�(hKhh)��}�(hhhM�0hM}hKubh�ubah��%/// Returns the length of the vector
�h�}�h��h��j�  �j�  �j�  �T�j�  �ht]�j�  Nj�  Nubj  )��}�(hh�GetSquaredLength�����}�(hKhh)��}�(hhhM(1hM�hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�-/// Returns the squared length of the vector
�����}�(hKhh)��}�(hhhM�0hM�hKubh�ubah��-/// Returns the squared length of the vector
�h�}�h��h��j�  �j�  �j�  �T�j�  �ht]�j�  Nj�  Nubj  )��}�(hh�GetNormalized�����}�(hKhh)��}�(hhhM�1hM�hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�@/// Returns a normalized vector, so that GetLength(vector)==1.0
�����}�(hKhh)��}�(hhhMa1hM�hKubh�ubah��@/// Returns a normalized vector, so that GetLength(vector)==1.0
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j�  Nj�  Nubj  )��}�(hh�
operator !�����}�(hKhh)��}�(hhhM`2hM�hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�@/// Returns a normalized vector, so that GetLength(vector)==1.0
�����}�(hKhh)��}�(hhhM2hM�hKubh�ubah��@/// Returns a normalized vector, so that GetLength(vector)==1.0
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j�  Nj�  Nubj  )��}�(hh�	Normalize�����}�(hKhh)��}�(hhhM3hM�hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�5/// Normalizes this vector, so that GetLength()==1.0
�����}�(hKhh)��}�(hhhM�2hM�hKubh�ubah��5/// Normalizes this vector, so that GetLength()==1.0
�h�}�h��h��j�  �j�  �j�  �void�j�  �ht]�j�  Nj�  Nubj  )��}�(hh�GetAngle�����}�(hKhh)��}�(hhhM�3hM�hKubh�ubhhVh]�hjj�  hkhlhmj�  hoNh�h�friend�����}�(hKhh)��}�(hhhM�3hM�hKubh�ubhNh�Nh�Nh�K h�]�h�4/// Calculates angle (in radians) between v1 and v2
�����}�(hKhh)��}�(hhhMR3hM�hKubh�ubah��4/// Calculates angle (in radians) between v1 and v2
�h�}�h��h��j�  �j�  �j�  �T�j�  �ht]�(j�  )��}�(h�const Vec2&�hh�v1�����}�(hKhh)��}�(hhhM�3hM�hK ubh�ubh�Nh|�j�  �j�  �ubj�  )��}�(h�const Vec2&�hh�v2�����}�(hKhh)��}�(hhhM�3hM�hK0ubh�ubh�Nh|�j�  �j�  �ubej�  Nj�  Nubj  )��}�(hh�ToString�����}�(hKhh)��}�(hhhM�5hM�hK	ubh�ubhhVh]�hjj	  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�(h�./// Returns a readable string of the content.
�����}�(hKhh)��}�(hhhM�4hM�hKubh�ubh�j/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
�����}�(hKhh)��}�(hhhM�4hM�hKubh�ubh�-/// @return												The converted result.
�����}�(hKhh)��}�(hhhM5hM�hKubh�ubeh���/// Returns a readable string of the content.
/// @param[in] formatStatement		Nullptr or additional formatting instruction. See also @ref format_float.
/// @return												The converted result.
�h�}�h��h��j�  �j�  �j�  �String�j�  �ht]�j�  )��}�(h�const FormatStatement*�hh�formatStatement�����}�(hKhh)��}�(hhhM�5hM�hK)ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�Cross�����}�(hKhh)��}�(hhhM�6hM�hKubh�ubhhVh]�hjjD	  hkhlhmj�  hoNh�h�friend�����}�(hKhh)��}�(hhhM�6hM�hKubh�ubhNh�Nh�Nh�K h�]�h�y/// Calculates the cross product of a 2d vector. This is the vector (Y, -X), i.e., the clockwise rotation by 90 degrees.
�����}�(hKhh)��}�(hhhM[6hM�hKubh�ubah��y/// Calculates the cross product of a 2d vector. This is the vector (Y, -X), i.e., the clockwise rotation by 90 degrees.
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j�  )��}�(h�const Vec2&�hh�v1�����}�(hKhh)��}�(hhhM�6hM�hK%ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�GetMin�����}�(hKhh)��}�(hhhMO7hM�hKubh�ubhhVh]�hjjg	  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�'/// Returns the minimum of 'x' and 'y'
�����}�(hKhh)��}�(hhhM%7hM�hKubh�ubah��'/// Returns the minimum of 'x' and 'y'
�h�}�h��h��j�  �j�  �j�  �T�j�  �ht]�j�  Nj�  Nubj  )��}�(hh�GetMax�����}�(hKhh)��}�(hhhM�7hM�hKubh�ubhhVh]�hjj{	  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�h�'/// Returns the maximum of 'x' and 'y'
�����}�(hKhh)��}�(hhhM}7hM�hKubh�ubah��'/// Returns the maximum of 'x' and 'y'
�h�}�h��h��j�  �j�  �j�  �T�j�  �ht]�j�  Nj�  Nubj  )��}�(hh�GetRightRotated�����}�(hKhh)��}�(hhhM�9hM�hKubh�ubhhVh]�hjj�	  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�(h�u/// Returns a vector where the components have been rotated to the right (in the usual (x, y)-representation). E.g.,
�����}�(hKhh)��}�(hhhM18hM�hKubh�ubh�;/// with a value of 1 for rots, the result will be (y, x).
�����}�(hKhh)��}�(hhhM�8hM�hKubh�ubh�q/// @param[in] rots								Number of rotations, may be negative. The result depends only on the number modulo 2.
�����}�(hKhh)��}�(hhhM�8hM�hKubh�ubh�7/// @return												Vector with rotated components.
�����}�(hKhh)��}�(hhhMU9hM�hKubh�ubeh�XX  /// Returns a vector where the components have been rotated to the right (in the usual (x, y)-representation). E.g.,
/// with a value of 1 for rots, the result will be (y, x).
/// @param[in] rots								Number of rotations, may be negative. The result depends only on the number modulo 2.
/// @return												Vector with rotated components.
�h�}�h��h��j�  �j�  �j�  �	Unstrided�j�  �ht]�j�  )��}�(h�Int�hh�rots�����}�(hKhh)��}�(hhhM:hM�hK ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�operator *=�����}�(hKhh)��}�(hhhM�:hM�hKubh�ubhhVh]�hjj�	  hkhlhmj�  hohq)��}�ht]�hw)��}�(hh)��}�(hhhM�:hM�hKubh|�hh�T2�����}�(hKhh)��}�(hhhM�:hM�hKubh�ubh�Nh�Nubasbh�NhNh�Nh�Nh�K h�]�h�!/// Transforms point by a matrix
�����}�(hKhh)��}�(hhhM�:hM�hKubh�ubah��!/// Transforms point by a matrix
�h�}�h��h��j�  �j�  �j�  �Vec2&�j�  �ht]�j�  )��}�(h�const Mat2<T2>&�hh�m�����}�(hKhh)��}�(hhhM�:hM�hK;ubh�ubh�Nh|�j�  �j�  �ubaj�  Nj�  Nubj  )��}�(hh�	NullValue�����}�(hKhh)��}�(hhhM�<hM�hKubh�ubhhVh]�hjj�	  hkhlhmj�  hoNh�NhNh�Nh�Nh�K h�]�(h�K/// Returns a null value of the vector (see nullvalue.h for more details).
�����}�(hKhh)��}�(hhhM�;hM�hKubh�ubh�3/// @return												A null value of the vector.
�����}�(hKhh)��}�(hhhM-<hM�hKubh�ubeh��~/// Returns a null value of the vector (see nullvalue.h for more details).
/// @return												A null value of the vector.
�h�}�h��h��j�  �j�  �j�  �const Vec2&�j�  �ht]�j�  Nj�  NubehjhZhkhlhmj5  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhMahKhKubh|�hh�T�����}�(hKhh)��}�(hhhMjhKhKubh�ubh�Nh�Nubj�  )��}�(hh)��}�(hhhMmhKhKubh|�hh�STRIDE�����}�(hKhh)��}�(hhhMqhKhKubh�ubh��1�h�Int�h�Nubesbh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]�j9  Nj:  Nh��j;  Nj<  Nj=  �j>  �j?  �j@  �jA  �jB  �jC  �jD  �jE  NjF  �jG  �jH  ]�jJ  ]�jL  }�ubh)��}�(hNhh9h]�h h�#ifndef STRIDE�����}�(hK
hh)��}�(hhhM=hM�hKubh�ububj  )��}�(hh�
operator *�����}�(hKhh)��}�(hhhM�=hM�hK�ubh�ubhh9h]�hjj*
  hkhlhmj�  hohq)��}�ht]�(hw)��}�(hh)��}�(hhhMM=hM�hKubh|�hh�T�����}�(hKhh)��}�(hhhMV=hM�hKubh�ubh�Nh�Nubj�  )��}�(hh)��}�(hhhMY=hM�hKubh|�hh�STR�����}�(hKhh)��}�(hhhM]=hM�hKubh�ubh�Nh�Int�h�Nubhw)��}�(hh)��}�(hhhMb=hM�hK ubh|�hh�S�����}�(hKhh)��}�(hhhMk=hM�hK)ubh�ubh�Nh�Nubesbh�NhNh�Nh�Nh�K h�]�h�1/// Multiplies each vector component by a scalar
�����}�(hKhh)��}�(hhhM=hM�hKubh�ubah��1/// Multiplies each vector component by a scalar
�h�}�h��h��j�  �j�  �j�  �OVec2<typename MultiplicativePromotion<T, S, std::is_scalar<S>::value>::type, 1>�j�  �ht]�(j�  )��}�(h�S�hh�s�����}�(hKhh)��}�(hhhM�=hM�hK�ubh�ubh�Nh|�j�  �j�  �ubj�  )��}�(h�const Vec2<T, STR>&�hh�v�����}�(hKhh)��}�(hhhM�=hM�hK�ubh�ubh�Nh|�j�  �j�  �ubej�  Nj�  Nubj  )��}�(hh�PrivateGetDataType�����}�(hKhh)��}�(hhhM�>hM�hKKubh�ubhh9h]�hjjr
  hkhlhmj�  hohq)��}�ht]�(j�  )��}�(hh)��}�(hhhML>hM�hKubh|�hh�POLICY�����}�(hKhh)��}�(hhhM`>hM�hKubh�ubh�Nh�GET_DATATYPE_POLICY�h�Nubhw)��}�(hh)��}�(hhhMh>hM�hK'ubh|�hh�T�����}�(hKhh)��}�(hhhMq>hM�hK0ubh�ubh�Nh�Nubesbh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��j�  �j�  �j�  �Result<DataType>�j�  �ht]�(j�  )��}�(h�Vec2<T, 1>**�h�anonymous_param_1�h�Nh|�j�  �j�  �ubj�  )��}�(h�OverloadRank0�h�anonymous_param_2�h�Nh|�j�  �j�  �ubej�  Nj�  �DataType�ubhU)��}�(h�IsZeroInitialized<Vec2<T,1>>�hh9h]�hjh�IsZeroInitialized�����}�(hKhh)��}�(hhhM�?hM�hKubh�ubhkhlhmj5  hohq)��}�ht]�hw)��}�(hh)��}�(hhhM�?hM�hKubh|�hh�T�����}�(hKhh)��}�(hhhM�?hM�hKubh�ubh�Nh�Nubasbh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h�]��IsZeroInitialized<T>�h�public�����}�(hKhh)��}�(hhhM�?hM�hK>ubh�ubh	��aj9  Nj:  Nh��j;  Nj<  Nj=  �j>  �j?  �j@  �jA  �jB  �jC  �jD  �jE  NjF  �jG  �jH  ]�jJ  ]�jL  }�ubh)��}�(hNhh9h]�h h�#endif�����}�(hK
hh)��}�(hhhM�?hM�hKubh�ububehjh=hkhlhm�	namespace�hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h���preprocessorConditions�]��root�hh N�containsResourceId���registry���usings����minIndentation�K �maxIndentation�K�firstMember��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�?hM�hKubh�ububehjhhkhlhmj�
  hoNh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��j�
  ]�j�
  hh ]�(hh'h0h9hBhKhVj
  j&
  jn
  j�
  j�
  j�
  ej�
  �j�
  �j�
  ���hxx1�N�hxx2�N�snippets�}�j�
  K j�
  K j�
  �ub.