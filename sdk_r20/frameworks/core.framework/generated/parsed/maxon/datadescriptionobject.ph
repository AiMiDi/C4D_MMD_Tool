���      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��\D:\C4DSDK\C4D_MMDTool\sdk_r20\frameworks\core.framework\source\maxon\datadescriptionobject.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/datadescription.h�hhh]��quote��"��template�Nubh()��}�(h�maxon/object.h�hhh]�h-h.h/Nubh()��}�(h�maxon/stringresource.h�hhh]�h-h.h/Nubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhK�hK	hKubh�ubhhh]�(h �Class���)��}�(hh�DataDictionaryObjectRef�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh8h]��
simpleName�hG�access��public��kind��class�h/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���bases�]��	interface�N�refKind�N�refClass�N�constRefClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent���forward���
singleImpl���ambiguousCalls�]��	selfCalls�]��methodNames�}�ubhB)��}�(hh�DataDescriptionObjectInterface�����}�(hKhh)��}�(hhhMDhKhKubh�ubhh8h]�h �Function���)��}�(hh�GetObjectDescription�����}�(hKhh)��}�(hhhM�hKhK'ubh�ubhhoh]�hLh~hMh�public�����}�(hKhh)��}�(hhhM�hKhKubh�ubhOh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKhKubh�ubh/NhQNhNhRNhSNhTK hU]�(h�@/// GetObjectDescription returns the description of the object.
�����}�(hKhh)��}�(hhhMbhKhKubh�ubh�w/// @param[in] category						Description category to load (DATADESCRIPTION_CATEGORY_DATA/DATADESCRIPTION_CATEGORY_UI).
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�a/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
�����}�(hKhh)��}�(hhhMhKhKubh�ubh�H/// @param[in] objectData					Data of the object to use for evaluation.
�����}�(hKhh)��}�(hhhM}hKhKubh�ubh��/// @return												DataDescription on success. If the Description could not be found an empty description is returned but no error.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubehWX�  /// GetObjectDescription returns the description of the object.
/// @param[in] category						Description category to load (DATADESCRIPTION_CATEGORY_DATA/DATADESCRIPTION_CATEGORY_UI).
/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
/// @param[in] objectData					Data of the object to use for evaluation.
/// @return												DataDescription on success. If the Description could not be found an empty description is returned but no error.
�hX}�hZ��static���explicit���deleted���retType��Result<DataDescription>��const���params�]�(h �	Parameter���)��}�(h�	const Id&�hh�category�����}�(hKhh)��}�(hhhM�hKhKFubh�ub�default�N�pack���input���output��ubh�)��}�(h�const LanguageRef&�hh�language�����}�(hKhh)��}�(hhhMhKhKcubh�ubh�NhĉhňhƉubh�)��}�(h�const DataDictionaryObjectRef&�hh�
objectData�����}�(hKhh)��}�(hhhM5hKhK�ubh�ubh�NhĉhňhƉube�
observable�N�result��DataDescription�ubahLhshMhNhOhPh/NhQNhNhRh�+"net.maxon.interface.datadescriptionobject"�����}�(hKhh)��}�(hhhM�hKhKJubh�ubhSNhTK hU]�(h��/// Interface and base implementation to allow objects to access descriptions. The base implementation automatically loads resources from
�����}�(hKhh)��}�(hhhM4hKhKubh�ubh�%/// the data description data bases.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubehW��/// Interface and base implementation to allow objects to access descriptions. The base implementation automatically loads resources from
/// the data description data bases.
�hX}�hZ�h[]��Object�hN��ah]Kh^Kh_�DataDescriptionObjectRef�h`Nha]�h�ahb�hc�hd�he�hf�hg�hh�hi]�hk]�hm}�ubhB)��}�(hh�hh8h]�hy)��}�(hh~hh�hh�hLh~hMh�hOh�h/NhQNhNhRNhSNhTK hUh�hWX�  /// GetObjectDescription returns the description of the object.
/// @param[in] category						Description category to load (DATADESCRIPTION_CATEGORY_DATA/DATADESCRIPTION_CATEGORY_UI).
/// @param[in] language						Language (only valid for category DATADESCRIPTION_CATEGORY_STRING).
/// @param[in] objectData					Data of the object to use for evaluation.
/// @return												DataDescription on success. If the Description could not be found an empty description is returned but no error.
�hXh�hZ�h��h��h��h�h�h��h�h�h�Nh�h�ubahLh�hMhNhOhPh/NhQNhNhRNhSNhTKhUh�hW��/// Interface and base implementation to allow objects to access descriptions. The base implementation automatically loads resources from
/// the data description data bases.
�hX}�hZ�h[]��"Object::ReferenceClassHelper::type�hN��ah]Nh^Nh_Nh`NhaNhb�hc�hd�he�hf�hg�hh��source�houbh �CppDeclaration���)��}�(hh�DataDescriptionObjectClass�����}�(hKhh)��}�(hhhM�hK#hK4ubh�ubhh8h]�hLj  hMhNhOh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhMshK#hKubh�ubh/NhQNh�Class<DataDescriptionObjectRef>�hR�'"net.maxon.class.datadescriptionobject"�hSNhTK hU]�hWh	hX}�hZ��dependencies��ubehLh<hMhNhO�	namespace�h/NhQNhNhRNhSNhTK hU]�hWh	hX}�hZ��preprocessorConditions�]��root�hh N�containsResourceId���registry���minIndentation�K �maxIndentation�K �firstMember��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhMhK)hKubh�ububehLhhMhNhOj  h/NhQNhNhRNhSNhTK hU]�hWh	hX}�hZ�j  ]�j   hh ]�(hh)h0h4h8hChoh�j  j&  ej!  �j"  ��hxx1�h8�hxx2�h8�snippets�}�j#  K j$  K j%  �ub.