��      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��dD:\C4DSDK\C4D_MMDTool\sdk_s24\frameworks\cinema.framework\source\c4d_customgui\customgui_listview2.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhM7hKhKubh�ububh �Include���)��}�(h�lib_description.h�hhh]��quote��"��template�Nubh()��}�(h�customgui_base.h�hhh]�h-h.h/Nubh)��}�(hNhhh]�h h� #ifdef CINEWARE_NAMESPACE_ENABLE�����}�(hK
hh)��}�(hhhM�hKhKubh�ububh)��}�(hNhhh]�h h�CINEWARE_NAMESPACE_BEGIN�����}�(hK
hh)��}�(hhhM�hKhKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hKhKubh�ububh �Define���)��}�(hh�CUSTOMDATA_LISTVIEW�����}�(hKhh)��}�(hhhM�hKhK	ubh�ubhhh]��
simpleName�hU�access��public��kind��#define�h/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���params�]�ubhP)��}�(hh�CUSTOMGUI_LISTVIEW�����}�(hKhh)��}�(hhhM!hKhK	ubh�ubhhh]�hZhoh[h\h]h^h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�hi]�ubh �Class���)��}�(hh�iListViewData�����}�(hKhh)��}�(hhhM^hKhK"ubh�ubhhh]�hZh}h[h\h]�class�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh��bases�]��	interface�N�refKind�N�static���refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent���forward���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���ambiguousCalls�]��	selfCalls�]��methodNames�}�ubhx)��}�(hh�ListViewData�����}�(hKhh)��}�(hhhMthKhKubh�ubhhh]�(h �Function���)��}�(h�constructor�hh�h]�hZh�h[h�private�����}�(hKhh)��}�(hhhM�hKhKubh�ubh]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h���explicit���deleted���retType��void��const��hi]��
observable�N�result�Nubh�)��}�(hh�Alloc�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh�h]�hZh�h[h�public�����}�(hKhh)��}�(hhhM�hKhKubh�ubh]�function�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��ListViewData*�h��hi]�h�Nh�Nubh�)��}�(hh�Free�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh�h]�hZh�h[h�h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��void�h��hi]�h �	Parameter���)��}�(h�ListViewData*&�hh�pData�����}�(hKhh)��}�(hhhMhKhK"ubh�ub�default�N�pack���input���output��ubah�Nh�Nubh�)��}�(hh�AddItem�����}�(hKhh)��}�(hhhMhKhKubh�ubhh�h]�hZh�h[h�h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��Bool�h��hi]�(h�)��}�(h�Int32�hh�id�����}�(hKhh)��}�(hhhM,hKhKubh�ubh�Nh�h�h�ubh�)��}�(h�const maxon::String&�hh�name�����}�(hKhh)��}�(hhhMEhKhK.ubh�ubh�Nh�h�h�ubh�)��}�(h�const GeData&�hh�data�����}�(hKhh)��}�(hhhMYhKhKBubh�ubh�Nh�h�h�ubeh�Nh�Nubh�)��}�(hh�
UpdateItem�����}�(hKhh)��}�(hhhMfhK hKubh�ubhh�h]�hZj  h[h�h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��Bool�h��hi]�(h�)��}�(h�Int32�hh�id�����}�(hKhh)��}�(hhhMwhK hKubh�ubh�Nh�h�h�ubh�)��}�(h�const maxon::String&�hh�name�����}�(hKhh)��}�(hhhM�hK hK1ubh�ubh�Nh�h�h�ubh�)��}�(h�const GeData&�hh�data�����}�(hKhh)��}�(hhhM�hK hKEubh�ubh�Nh�h�h�ubeh�Nh�Nubh�)��}�(hh�
RemoveItem�����}�(hKhh)��}�(hhhM�hK!hKubh�ubhh�h]�hZj@  h[h�h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��void�h��hi]�h�)��}�(h�Int32�hh�id�����}�(hKhh)��}�(hhhM�hK!hKubh�ubh�Nh�h�h�ubah�Nh�Nubh�)��}�(hh�GetCount�����}�(hKhh)��}�(hhhM�hK#hKubh�ubhh�h]�hZjV  h[h�h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��Int32�h��hi]�h�Nh�Nubh�)��}�(hh�GetSelected�����}�(hKhh)��}�(hhhM�hK$hKubh�ubhh�h]�hZjc  h[h�h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��Int32�h��hi]�h�Nh�Nubh�)��}�(hh�Select�����}�(hKhh)��}�(hhhM�hK%hKubh�ubhh�h]�hZjp  h[h�h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��void�h��hi]�h�)��}�(h�Int32�hh�index�����}�(hKhh)��}�(hhhMhK%hKubh�ubh�Nh�h�h�ubah�Nh�Nubh�)��}�(hh�GetData�����}�(hKhh)��}�(hhhMhK'hK	ubh�ubhh�h]�hZj�  h[h�h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��GeData�h��hi]�h�)��}�(h�Int32�hh�index�����}�(hKhh)��}�(hhhM#hK'hKubh�ubh�Nh�h�h�ubah�Nh�Nubh�)��}�(hh�GetName�����}�(hKhh)��}�(hhhM3hK(hK	ubh�ubhh�h]�hZj�  h[h�h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��String�h��hi]�h�)��}�(h�Int32�hh�index�����}�(hKhh)��}�(hhhMAhK(hKubh�ubh�Nh�h�h�ubah�Nh�Nubh�)��}�(hh�GetID�����}�(hKhh)��}�(hhhMPhK)hKubh�ubhh�h]�hZj�  h[h�h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��Int32�h��hi]�h�)��}�(h�Int32�hh�index�����}�(hKhh)��}�(hhhM\hK)hKubh�ubh�Nh�h�h�ubah�Nh�Nubh�)��}�(hh�SetData�����}�(hKhh)��}�(hhhMkhK+hKubh�ubhh�h]�hZj�  h[h�h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��void�h��hi]�(h�)��}�(h�Int32�hh�index�����}�(hKhh)��}�(hhhMyhK+hKubh�ubh�Nh�h�h�ubh�)��}�(h�const GeData&�hh�data�����}�(hKhh)��}�(hhhM�hK+hK*ubh�ubh�Nh�h�h�ubeh�Nh�Nubh�)��}�(hh�SetName�����}�(hKhh)��}�(hhhM�hK,hKubh�ubhh�h]�hZj�  h[h�h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��void�h��hi]�(h�)��}�(h�Int32�hh�index�����}�(hKhh)��}�(hhhM�hK,hKubh�ubh�Nh�h�h�ubh�)��}�(h�const maxon::String&�hh�name�����}�(hKhh)��}�(hhhM�hK,hK1ubh�ubh�Nh�h�h�ubeh�Nh�Nubh�)��}�(hh�SetID�����}�(hKhh)��}�(hhhM�hK-hKubh�ubhh�h]�hZj  h[h�h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��void�h��hi]�(h�)��}�(h�Int32�hh�index�����}�(hKhh)��}�(hhhM�hK-hKubh�ubh�Nh�h�h�ubh�)��}�(h�Int32�hh�id�����}�(hKhh)��}�(hhhM�hK-hK ubh�ubh�Nh�h�h�ubeh�Nh�Nubh�)��}�(hh�	FindIndex�����}�(hKhh)��}�(hhhM�hK/hKubh�ubhh�h]�hZj%  h[h�h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h��h��h��h��Int32�h��hi]�h�)��}�(h�Int32�hh�id�����}�(hKhh)��}�(hhhMhK/hKubh�ubh�Nh�h�h�ubah�Nh�NubehZh�h[h\h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h�]��CustomDataType�h�public�����}�(hKhh)��}�(hhhM�hKhKubh�ubh	��ah�Nh�Nh��h�Nh�Nh��h��h��h��h��h��h��h��h�Nh��h��h�]�h�]�h�}�ubh)��}�(hNhhh]�h h�/// @cond IGNORE
�����}�(hK	hh)��}�(hhhMhK2hKubh�ububhx)��}�(hh�CustomGuiListViewLib�����}�(hKhh)��}�(hhhM9hK8hKubh�ubhhh]�hZjR  h[h\h]h�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh�h�]��BaseCustomGuiLib�h�public�����}�(hKhh)��}�(hhhMPhK8hKubh�ubh	��ah�Nh�Nh��h�Nh�Nh��h��h��h��h��h��h��h��h�Nh��h��h�]�h�]�h�}�ubh)��}�(hNhhh]�h h�/// @endcond
�����}�(hK	hh)��}�(hhhM�
hKPhKubh�ububh)��}�(hNhhh]�h h� #ifdef CINEWARE_NAMESPACE_ENABLE�����}�(hK
hh)��}�(hhhM�
hKRhKubh�ububh)��}�(hNhhh]�h h�CINEWARE_NAMESPACE_END�����}�(hK
hh)��}�(hhhMhKShKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhMhKThKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM#hKVhKubh�ububehZhh[h\h]�	namespace�h/Nh_NhNh`NhaNhbK hc]�heh	hf}�hh��preprocessorConditions�]��root�hh ]�(hh)h0h4h=hFhQhkhyh�jE  jN  je  jn  jw  j�  j�  e�containsResourceId���registry���usings����hxx1�N�hxx2�N�snippets�}��minIndentation�K �maxIndentation�K �firstMember��ub.