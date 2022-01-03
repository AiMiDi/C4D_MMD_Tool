��,      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��YG:\C4DSDK\C4D_MMD_Tool\sdk_r25\frameworks\core.framework\source\maxon\hierarchyiterator.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/errorbase.h�hhh]��quote��"��template�Nubh()��}�(h�maxon/basearray.h�hhh]�h-h.h/Nubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhK�hKhKubh�ubhhh]�h �Class���)��}�(hh�HierarchyIterator�����}�(hKhh)��}�(hhhK�hK
hKlubh�ubhh4h]�(h �	TypeAlias���)��}�(hh�	StackType�����}�(hKhh)��}�(hhhMhKhKubh�ubhh?h]��
simpleName�hN�access�h�public�����}�(hKhh)��}�(hhhM
hKhKubh�ub�kind��	typealias�h/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���bases�]��#typename ARRAY::template Type<NODE>��public�h	��aubh �Function���)��}�(hh�Init�����}�(hKhh)��}�(hhhMYhKhKubh�ubhh?h]�hShrhThWh[�function�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf��static���explicit���deleted���retType��Result<void>��const���params�]�(h �	Parameter���)��}�(h�!typename ByValueParam<NODE>::type�hh�start�����}�(hKhh)��}�(hhhM�hKhK6ubh�ub�default�N�pack���input���output��ubh�)��}�(h�Bool�hh�includeSelf�����}�(hKhh)��}�(hhhM�hKhKBubh�ubh�Nh��h��h��ubh�)��}�(h�CONTEXT*�hh�context�����}�(hKhh)��}�(hhhM�hKhKXubh�ubh�Nh��h��h��ube�
observable�N�result��void��forward��ubhm)��}�(hh�
MoveToNext�����}�(hKhh)��}�(hhhM�hK hKubh�ubhh?h]�hSh�hThWh[hwh/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�hz�h{�h|�h}�Result<void>�h�h�]�h�Nh��void�h��ubhm)��}�(hh�operator�����}�(hKhh)��}�(hhhMxhK0hKubh�ubhh?h]�hSh�hThWh[hwh/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�hz�h{�h|�h}�Bool�h�h�]�h�Nh�Nh��ubhm)��}�(hh�
operator *�����}�(hKhh)��}�(hhhM�hK5hKubh�ubhh?h]�hSh�hThWh[hwh/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�hz�h{�h|�h}�const NODE&�h�h�]�h�Nh�Nh��ubhm)��}�(hh�operator ->�����}�(hKhh)��}�(hhhM�hK:hKubh�ubhh?h]�hSh�hThWh[hwh/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�hz�h{�h|�h}�NODE*�h�h�]�h�Nh�Nh��ubhm)��}�(hh�SkipBranches�����}�(hKhh)��}�(hhhMMhK?hKubh�ubhh?h]�hSh�hThWh[hwh/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�hz�h{�h|�h}�void�h�h�]�h�Nh�Nh��ubhm)��}�(hh�GetStack�����}�(hKhh)��}�(hhhMhKDhKubh�ubhh?h]�hSh�hThWh[hwh/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�hz�h{�h|�h}�
StackType&�h�h�]�h�Nh�Nh��ubh �Variable���)��}�(hh�_stack�����}�(hKhh)��}�(hhhM�hKJhKubh�ubhh?h]�hSh�hTh�private�����}�(hKhh)��}�(hhhM�hKIhKubh�ubh[�variable�h/Nh]Nh�	StackType�h^Nh_Nh`K ha]�hch	hd}�hf�hz�ubh�)��}�(hh�_skip�����}�(hKhh)��}�(hhhM�hKKhKubh�ubhh?h]�hSj  hTj  h[j  h/Nh]Nh�Bool�h^Nh_Nh`K ha]�hch	hd}�hf�hz�ubh�)��}�(hh�_context�����}�(hKhh)��}�(hhhM�hKLhKubh�ubhh?h]�hSj  hTj  h[j  h/Nh]Nh�CONTEXT*�h^Nh_Nh`K ha]�hch	hd}�hf�hz�ubehShChThjh[�class�h/h �Template���)��}�h�]�(h �TypeTemplateParam���)��}�(hh)��}�(hhhK�hK
hKubh��hh�NODE�����}�(hKhh)��}�(hhhK�hK
hKubh�ubh�N�variance�Nubj*  )��}�(hh)��}�(hhhK�hK
hKubh��hh�	HIERARCHY�����}�(hKhh)��}�(hhhK�hK
hK#ubh�ubh�Nj5  Nubj*  )��}�(hh)��}�(hhhK�hK
hK.ubh��hh�CONTEXT�����}�(hKhh)��}�(hhhK�hK
hK7ubh�ubh�Nj5  Nubj*  )��}�(hh)��}�(hhhK�hK
hK@ubh��hh�ARRAY�����}�(hKhh)��}�(hhhK�hK
hKIubh�ubh��BaseArraySelector<>�j5  Nubesbh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�hg]��	interface�N�refKind�Nhz��refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent��h���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���ambiguousCalls�]��	selfCalls�]��methodNames�}�ubahSh8hThjh[�	namespace�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf��preprocessorConditions�]��root�hh N�containsResourceId���registry���usings����minIndentation�K �maxIndentation�K �firstMember��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hKQhKubh�ububehShhThjh[jl  h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�jo  ]�jq  hh ]�(hh)h0h4h?jy  ejr  �js  �jt  ���hxx1�N�hxx2�N�snippets�}�jv  K jw  K jx  ��forwardHeaders���ub.