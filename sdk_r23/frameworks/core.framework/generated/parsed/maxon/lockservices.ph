��	      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��TG:\C4DSDK\C4D_MMD_Tool\sdk_r23\frameworks\core.framework\source\maxon\lockservices.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/interface.h�hhh]��quote��"��template�Nubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhK[hKhKubh�ubhhh]�(h)��}�(hNhh0h]�h h�/// @cond INTERNAL
�����}�(hK	hh)��}�(hhhKdhK	hKubh�ububh �Class���)��}�(hh�ARWLock�����}�(hKhh)��}�(hhhK~hKhKubh�ubhh0h]��
simpleName�hH�access��public��kind��class�h/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���bases�]��	interface�N�refKind�N�static���refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent���forward���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���ambiguousCalls�]��	selfCalls�]��methodNames�}�ubhC)��}�(hh�CoreSerializerPOD�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh0h]�hMhxhNhOhPhQh/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h\]�h^Nh_Nh`�haNhbNhc�hd�he�hf�hg�hh�hi�hj�hkNhl�hm�hn]�hp]�hr}�ubh �	TypeAlias���)��}�(hh�CoreSerializerCallback�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh0h]�hMh�hNhOhP�	typealias�h/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h\]��void(*)(void*)�hOh	��aubh�)��}�(hh�CoreSerializerBuildWrapper�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh0h]�hMh�hNhOhPh�h/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h\]��:void*(*)(void*buf,void*fn,CoreSerializerCallback&callback)�hOh	��aubh �Variable���)��}�(hh�MAXCORESERIALIZERJOBSIZE�����}�(hKhh)��}�(hhhMyhKhKubh�ubhh0h]�hMh�hNhOhP�variable�h/NhRNh�	const Int�hSNhTNhUK hV]�hXh	hY}�h[�h`�ubhC)��}�(hh�LockServices�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh0h]�(h �Function���)��}�(hh�	Serialize�����}�(hKhh)��}�(hhhMjhKhKubh�ubhh�h]�hMh�hNh�private�����}�(hKhh)��}�(hhhMGhKhKubh�ubhPh�MAXON_METHOD�����}�(hKhh)��}�(hhhMXhKhK	ubh�ubh/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h`��explicit���deleted���retType��void��const���params�]�(h �	Parameter���)��}�(h�CoreSerializerPOD&�hh�
serializer�����}�(hKhh)��}�(hhhM�hKhK8ubh�ub�default�N�pack���input���output��ubh�)��}�(h�CoreSerializerCallback�hh�jobCallback�����}�(hKhh)��}�(hhhM�hKhK[ubh�ubh�Nh�h�h�ubh�)��}�(h�void*�hh�jobParam�����}�(hKhh)��}�(hhhM�hKhKnubh�ubh�Nh�h�h�ube�
observable�N�result�Nubh�)��}�(hh�SerializeAsync�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh�h]�hMj  hNh�hPh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKhK	ubh�ubh/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h`�hӉhԉhՌvoid�h׉h�]�(h�)��}�(h�CoreSerializerPOD&�hh�
serializer�����}�(hKhh)��}�(hhhMhKhK=ubh�ubh�Nh�h�h�ubh�)��}�(h�CoreSerializerBuildWrapper�hh�wrapperCallback�����}�(hKhh)��}�(hhhM+hKhKdubh�ubh�Nh�h�h�ubh�)��}�(h�void*�hh�fn�����}�(hKhh)��}�(hhhMBhKhK{ubh�ubh�Nh�h�h�ubeh�Nh�Nubh�)��}�(hh�AllocRWLockSlot�����}�(hKhh)��}�(hhhMbhKhKubh�ubhh�h]�hMj/  hNh�hPh�MAXON_METHOD�����}�(hKhh)��}�(hhhMPhKhK	ubh�ubh/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h`�hӉhԉhՌvoid�h׉h�]�h�)��}�(h�ARWLock*�hh�arw�����}�(hKhh)��}�(hhhM{hKhK4ubh�ubh�Nh�h�h�ubah�Nh�Nubh�)��}�(hh�FreeRWLockSlot�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh�h]�hMjK  hNh�hPh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKhK	ubh�ubh/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h`�hӉhԉhՌvoid�h׉h�]�h�)��}�(h�ARWLock*�hh�arw�����}�(hKhh)��}�(hhhM�hKhK3ubh�ubh�Nh�h�h�ubah�Nh�Nubh�)��}�(hh�ARWReadLock�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh�h]�hMjg  hNh�hPh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKhK	ubh�ubh/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h`�hӉhԉhՌvoid�h׉h�]�h�)��}�(h�ARWLock*�hh�arw�����}�(hKhh)��}�(hhhM�hKhK0ubh�ubh�Nh�h�h�ubah�Nh�Nubh�)��}�(hh�ARWReadUnlock�����}�(hKhh)��}�(hhhMhK hKubh�ubhh�h]�hMj�  hNh�hPh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK hK	ubh�ubh/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h`�hӉhԉhՌvoid�h׉h�]�h�)��}�(h�ARWLock*�hh�arw�����}�(hKhh)��}�(hhhMhK hK2ubh�ubh�Nh�h�h�ubah�Nh�Nubh�)��}�(hh�ARWWriteLock�����}�(hKhh)��}�(hhhM?hK!hKubh�ubhh�h]�hMj�  hNh�hPh�MAXON_METHOD�����}�(hKhh)��}�(hhhM-hK!hK	ubh�ubh/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h`�hӉhԉhՌvoid�h׉h�]�h�)��}�(h�ARWLock*�hh�arw�����}�(hKhh)��}�(hhhMUhK!hK1ubh�ubh�Nh�h�h�ubah�Nh�Nubh�)��}�(hh�ARWWriteUnlock�����}�(hKhh)��}�(hhhMuhK"hKubh�ubhh�h]�hMj�  hNh�hPh�MAXON_METHOD�����}�(hKhh)��}�(hhhMchK"hK	ubh�ubh/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h`�hӉhԉhՌvoid�h׉h�]�h�)��}�(h�ARWLock*�hh�arw�����}�(hKhh)��}�(hhhM�hK"hK3ubh�ubh�Nh�h�h�ubah�Nh�Nubh�)��}�(hh�ARWAttemptWriteLock�����}�(hKhh)��}�(hhhM�hK#hKubh�ubhh�h]�hMj�  hNh�hPh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK#hK	ubh�ubh/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�h`�hӉhԉhՌBool�h׉h�]�h�)��}�(h�ARWLock*�hh�arw�����}�(hKhh)��}�(hhhM�hK#hK8ubh�ubh�Nh�h�h�ubah�Nh�NubehMh�hNhOhPhQh/NhRNhNhSh�""net.maxon.interface.lockservices"�����}�(hKhh)��}�(hhhM"hKhKAubh�ubhTNhUK hV]�hXh	hY}�h[�h\]�h^Kh_Nh`�haNhbNhc�hd�he�hf�hg�hh�hi�hj�hkNhl�hm�hn]�hp]�hr}�ubh)��}�(hNhh0h]�h h�/// @endcond
�����}�(hK	hh)��}�(hhhM�hK%hKubh�ububehMh4hNhOhP�	namespace�h/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[��preprocessorConditions�]��root�hh N�containsResourceId���registry���usings����minIndentation�K �maxIndentation�K �firstMember��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hK.hKubh�ububehMhhNhOhPj  h/NhRNhNhSNhTNhUK hV]�hXh	hY}�h[�j  ]�j	  hh ]�(hh)h0h9hDhth�h�h�h�j�  j  ej
  �j  �j  ���hxx1�h0�hxx2�h0�snippets�}�j  K j  K j  �ub.