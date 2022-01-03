���      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��OG:\C4DSDK\C4D_MMD_Tool\sdk_r25\frameworks\core.framework\source\maxon\win_com.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�wrl/client.h�hhh]��quote��<��template�Nubh()��}�(h�propvarutil.h�hhh]�h-h.h/Nubh()��}�(h�comdef.h�hhh]�h-h.h/Nubh()��}�(h�maxon/win_include.h�hhh]�h-�"�h/Nubh()��}�(h�maxon/errortypes.h�hhh]�h-h<h/Nubh()��}�(h�maxon/datetime.h�hhh]�h-h<h/Nubh()��}�(h�maxon/win_type_conversions.h�hhh]�h-h<h/Nubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhh]�(h �Function���)��}�(hh�GetHResultError�����}�(hKhh)��}�(hhhM@hKhK$ubh�ubhhIh]��
simpleName�hX�access��public��kind��function�h/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���static���explicit���deleted���retType��Error��const���params�]�(h �	Parameter���)��}�(h�HRESULT�hh�hr�����}�(hKhh)��}�(hhhMXhKhK<ubh�ub�default�N�pack���input���output��ubhu)��}�(h�const maxon::SourceLocation&�h�allocLocation�hNh��h��h��ube�
observable�N�result�N�forward��ubhS)��}�(hh�
operator %�����}�(hKhh)��}�(hhhMWhK hK#ubh�ubhhIh]�h]h�h^h_h`hah/NhbNhNhcNhdNheK hf]�hhh	hi}�hk�hl�hm�hn�ho�void�hq�hr]�(hu)��}�(h�HRESULT�hh�value�����}�(hKhh)��}�(hhhMjhK hK6ubh�ubhNh��h��h��ubhu)��}�(h�ThreadReferencedError&�hh�err�����}�(hKhh)��}�(hhhM�hK hKTubh�ubhNh��h��h��ubeh�Nh�Nh��ubh �Class���)��}�(hh�GUIDHASH�����}�(hKhh)��}�(hhhMbhK0hKubh�ubhhIh]�(hS)��}�(hh�GetHashCode�����}�(hKhh)��}�(hhhM�hK3hK.ubh�ubhh�h]�h]h�h^h�public�����}�(hKhh)��}�(hhhMmhK2hKubh�ubh`hah/NhbNhNhcNhdNheK hf]�hhh	hi}�hk�hl�hm�hn�ho�HashInt�hq�hr]�hu)��}�(h�const GUID&�hh�guid�����}�(hKhh)��}�(hhhM�hK3hKFubh�ubhNh��h��h��ubah�Nh�Nh��ubhS)��}�(hh�IsEqual�����}�(hKhh)��}�(hhhMmhK=hK+ubh�ubhh�h]�h]h�h^h�h`hah/NhbNhNhcNhdNheK hf]�hhh	hi}�hk�hl�hm�hn�ho�Bool�hq�hr]�(hu)��}�(h�const GUID&�hh�a�����}�(hKhh)��}�(hhhM�hK=hK?ubh�ubhNh��h��h��ubhu)��}�(h�const GUID&�hh�b�����}�(hKhh)��}�(hhhM�hK=hKNubh�ubhNh��h��h��ubeh�Nh�Nh��ubeh]h�h^h_h`�class�h/NhbNhNhcNhdNheK hf]�(h�V/// This class allows to use windows GUID structures together with HashMaps/HashSets.
�����}�(hKhh)��}�(hhhMwhK-hKubh�ubh�4/// It implements GetHashCode and IsEqual for GUID.
�����}�(hKhh)��}�(hhhM�hK.hKubh�ubehh��/// This class allows to use windows GUID structures together with HashMaps/HashSets.
/// It implements GetHashCode and IsEqual for GUID.
�hi}�hk��bases�]��	interface�N�refKind�Nhl��refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent��h���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���ambiguousCalls�]��	selfCalls�]��methodNames�}�ubhS)��}�(hh�PropVariantToInt64�����}�(hKhh)��}�(hhhM hKFhK,ubh�ubhhIh]�h]j  h^h_h`hah/NhbNhNhcNhdNheK hf]�h�N/// Converts a windows VARIANT into a Int64 value with proper error handling.
�����}�(hKhh)��}�(hhhM,hKDhKubh�ubahh�N/// Converts a windows VARIANT into a Int64 value with proper error handling.
�hi}�hk�hl�hm�hn�ho�Result<Int64>�hq�hr]�hu)��}�(h�const PROPVARIANT&�hh�vt�����}�(hKhh)��}�(hhhM&hKFhKRubh�ubhNh��h��h��ubah�Nh��Int64�h��ubhS)��}�(hh�VariantToInt64�����}�(hKhh)��}�(hhhMA	hKRhK,ubh�ubhhIh]�h]j7  h^h_h`hah/NhbNhNhcNhdNheK hf]�hhh	hi}�hk�hl�hm�hn�ho�Result<Int64>�hq�hr]�hu)��}�(h�const VARIANT&�hh�vt�����}�(hKhh)��}�(hhhM_	hKRhKJubh�ubhNh��h��h��ubah�Nh��Int64�h��ubhS)��}�(hh�PropVariantToUniversalDateTime�����}�(hKhh)��}�(hhhM]hK[hK8ubh�ubhhIh]�h]jN  h^h_h`hah/NhbNhNhcNhdNheK hf]�h�Q/// Converts a windows VARIANT into a DateTime value with proper error handling.
�����}�(hKhh)��}�(hhhMz
hKYhKubh�ubahh�Q/// Converts a windows VARIANT into a DateTime value with proper error handling.
�hi}�hk�hl�hm�hn�ho�Result<UniversalDateTime>�hq�hr]�hu)��}�(h�const PROPVARIANT&�hh�vt�����}�(hKhh)��}�(hhhM�hK[hKjubh�ubhNh��h��h��ubah�Nh��UniversalDateTime�h��ubhS)��}�(hh�VariantToUniversalDateTime�����}�(hKhh)��}�(hhhM�hKshK8ubh�ubhhIh]�h]jl  h^h_h`hah/NhbNhNhcNhdNheK hf]�hhh	hi}�hk�hl�hm�hn�ho�Result<UniversalDateTime>�hq�hr]�hu)��}�(h�const VARIANT&�hh�vt�����}�(hKhh)��}�(hhhM�hKshKbubh�ubhNh��h��h��ubah�Nh��UniversalDateTime�h��ubeh]hMh^h_h`�	namespace�h/NhbNhNhcNhdNheK hf]�hhh	hi}�hk��preprocessorConditions�]��root�hh N�containsResourceId���registry���usings���(�Microsoft.WRL���minIndentation�K �maxIndentation�K �firstMember��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hK{hKubh�ububeh]hh^h_h`j  h/NhbNhNhcNhdNheK hf]�hhh	hi}�hk�j�  ]�j�  hh ]�(hh)h0h4h8h=hAhEhIhTh�h�j  j3  jJ  jh  j�  ej�  �j�  �j�  ���hxx1�N�hxx2�N�snippets�}�j�  K j�  K j�  ��forwardHeaders���ub.