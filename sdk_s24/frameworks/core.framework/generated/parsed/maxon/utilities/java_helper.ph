���W      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��VD:\C4D_MMD_Tool\sdk_s24\frameworks\core.framework\source\maxon\utilities\java_helper.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/sortedarray.h�hhh]��quote��"��template�Nubh()��}�(h�maxon/string.h�hhh]�h-h.h/Nubh()��}�(h�maxon/cstdliballocator.h�hhh]�h-h.h/Nubh()��}�(h�maxon/hashmap.h�hhh]�h-h.h/Nubh()��}�(h�maxon/spinlock.h�hhh]�h-h.h/Nubh)��}�(hNhhh]�h h�#ifdef MAXON_TARGET_ANDROID�����}�(hK
hh)��}�(hhhK�hK
hKubh�ububh()��}�(h�ctype.h�hhh]�h-�<�h/Nubh()��}�(h�jni.h�hhh]�h-hMh/Nubh()��}�(h�android/log.h�hhh]�h-hMh/Nubh()��}�(h�android/asset_manager.h�hhh]�h-hMh/Nubh()��}�(h�android/asset_manager_jni.h�hhh]�h-hMh/Nubh)��}�(hNhhh]�h h�#else�����}�(hK
hh)��}�(hhhMnhKhKubh�ububh �	TypeAlias���)��}�(hh�JNIEnv�����}�(hKhh)��}�(hhhM{hKhKubh�ubhhh]��
simpleName�hm�access��public��kind��	typealias�h/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���bases�]��void�hth	��aubhh)��}�(hh�jvalue�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhh]�hrh�hshthuhvh/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]��void*�hth	��aubhh)��}�(hh�	jmethodID�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhh]�hrh�hshthuhvh/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]��void*�hth	��aubhh)��}�(hh�jclass�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhh]�hrh�hshthuhvh/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]��void*�hth	��aubhh)��}�(hh�jfieldID�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhh]�hrh�hshthuhvh/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]��void*�hth	��aubhh)��}�(hh�jobject�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhh]�hrh�hshthuhvh/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]��void*�hth	��aubhh)��}�(hh�jstring�����}�(hKhh)��}�(hhhM
hKhKubh�ubhhh]�hrh�hshthuhvh/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]��void*�hth	��aubhh)��}�(hh�AAssetManager�����}�(hKhh)��}�(hhhM"hKhKubh�ubhhh]�hrh�hshthuhvh/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]��void�hth	��aubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM8hKhKubh�ububh)��}�(hh�maxon�����}�(hKhh)��}�(hhhMJhKhKubh�ubhhh]�(h)��}�(hNhh�h]�h h�#ifdef MAXON_TARGET_ANDROID�����}�(hK
hh)��}�(hhhMShKhKubh�ububh �Function���)��}�(hh�InitJava�����}�(hKhh)��}�(hhhMuhK hKubh�ubhh�h]�hrj  hshthu�function�h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h���static���explicit���deleted���retType��Bool��const���params�]�(h �	Parameter���)��}�(h�JavaVM*�hh�vm�����}�(hKhh)��}�(hhhM�hK hKubh�ub�default�N�pack���input���output��ubj  )��}�(h�jobject�hh�nativeActivity�����}�(hKhh)��}�(hhhM�hK hK#ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�AAssetManager*�hh�assetManager�����}�(hKhh)��}�(hhhM�hK hKBubh�ubj#  Nj$  �j%  �j&  �ube�
observable�N�result�Nubj  )��}�(hh�GetMainThreadJavaEnv�����}�(hKhh)��}�(hhhM�hK!hK	ubh�ubhh�h]�hrj?  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �JNIEnv*�j  �j  ]�j9  Nj:  Nubj  )��}�(hh�
GetJavaEnv�����}�(hKhh)��}�(hhhM�hK"hK	ubh�ubhh�h]�hrjL  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �JNIEnv*�j  �j  ]�j9  Nj:  Nubj  )��}�(hh�	GetJavaVM�����}�(hKhh)��}�(hhhM�hK#hK	ubh�ubhh�h]�hrjY  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �JavaVM*�j  �j  ]�j9  Nj:  Nubj  )��}�(hh�GetNativeActivityObject�����}�(hKhh)��}�(hhhMhK$hK	ubh�ubhh�h]�hrjf  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �jobject�j  �j  ]�j9  Nj:  Nubj  )��}�(hh�GetAssetManager�����}�(hKhh)��}�(hhhM=hK%hKubh�ubhh�h]�hrjs  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �AAssetManager*�j  �j  ]�j9  Nj:  Nubh)��}�(hNhh�h]�h h�#endif�����}�(hK
hh)��}�(hhhMQhK'hKubh�ububh �Class���)��}�(hh�JavaCall�����}�(hKhh)��}�(hhhM`hK)hKubh�ubhh�h]�(h �Variable���)��}�(hh�_memberName�����}�(hKhh)��}�(hhhMyhK+hKubh�ubhj�  h]�hrj�  hshthu�variable�h/NhwNh�const Char*�hxNhyNhzK h{]�h}h	h~}�h��j  �ubj�  )��}�(hh�_sig�����}�(hKhh)��}�(hhhM�hK,hKubh�ubhj�  h]�hrj�  hshthuj�  h/NhwNh�const Char*�hxNhyNhzK h{]�h}h	h~}�h��j  �ubj�  )��}�(hh�_static�����}�(hKhh)��}�(hhhM�hK-hKubh�ubhj�  h]�hrj�  hshthuj�  h/NhwNh�Bool�hxNhyNhzK h{]�h}h	h~}�h��j  �ubj  )��}�(h�constructor�hj�  h]�hrj�  hshthuj�  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �void�j  �j  ]�j9  Nj:  Nubj  )��}�(hj�  hj�  h]�hrj�  hshthuj�  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  j�  j  �j  ]�(j  )��}�(h�const Char*�hh�
memberName�����}�(hKhh)��}�(hhhMhK3hKubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�sig�����}�(hKhh)��}�(hhhM%hK3hK/ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�Bool�hh�
staticCall�����}�(hKhh)��}�(hhhM/hK3hK9ubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubehrj�  hshthu�class�h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]��	interface�N�refKind�Nj  ��refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent���forward���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���ambiguousCalls�]��	selfCalls�]��methodNames�}�ubj�  )��}�(hh�
JavaMember�����}�(hKhh)��}�(hhhM�hK8hKubh�ubhh�h]�(j�  )��}�(hh�_call�����}�(hKhh)��}�(hhhM�hK:hKubh�ubhj�  h]�hrj  hshthuj�  h/NhwNh�JavaCall�hxNhyNhzK h{]�h}h	h~}�h��j  �ubj�  )��}�(hh�fanonymous#D:\C4D_MMD_Tool\sdk_s24\frameworks\core.framework\source\maxon\utilities\java_helper.h(59,2)�����}�(hKhh)��}�(hhhM�hK;hKubh�ubhj�  h]�(j�  )��}�(hh�_memberPointer�����}�(hKhh)��}�(hhhM�hK=hKubh�ubhj  h]�hrj  hshthuj�  h/NhwNh�	jmethodID�hxNhyNhzK h{]�h}h	h~}�h��j  �ubj�  )��}�(hh�_fieldPointer�����}�(hKhh)��}�(hhhM�hK>hKubh�ubhj  h]�hrj'  hshthuj�  h/NhwNh�jfieldID�hxNhyNhzK h{]�h}h	h~}�h��j  �ubehrj  hshthuj�  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]�j�  Nj�  Nj  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  }�ubj  )��}�(hj�  hj�  h]�hrj�  hshthuj�  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  j�  j  �j  ]�j9  Nj:  Nubj  )��}�(hh�IsEqual�����}�(hKhh)��}�(hhhM3hKFhKubh�ubhj�  h]�hrj?  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �Bool�j  �j  ]�(j  )��}�(h�const JavaMember&�hh�a�����}�(hKhh)��}�(hhhMMhKFhK/ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const JavaMember&�hh�b�����}�(hKhh)��}�(hhhMbhKFhKDubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�IsEqual�����}�(hKhh)��}�(hhhMghKOhKubh�ubhj�  h]�hrj^  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �Bool�j  �j  ]�(j  )��}�(h�const JavaCall&�hh�a�����}�(hKhh)��}�(hhhMhKOhK-ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const JavaMember&�hh�b�����}�(hKhh)��}�(hhhM�hKOhKBubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�LessThan�����}�(hKhh)��}�(hhhM�hKXhKubh�ubhj�  h]�hrj}  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �Bool�j  �j  ]�(j  )��}�(h�const JavaMember&�hh�a�����}�(hKhh)��}�(hhhM�hKXhK0ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const JavaMember&�hh�b�����}�(hKhh)��}�(hhhM�hKXhKEubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�LessThan�����}�(hKhh)��}�(hhhM�hKahKubh�ubhj�  h]�hrj�  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �Bool�j  �j  ]�(j  )��}�(h�const JavaCall&�hh�a�����}�(hKhh)��}�(hhhM�hKahK.ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const JavaMember&�hh�b�����}�(hKhh)��}�(hhhM	hKahKCubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubehrj�  hshthuj�  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]�j�  Nj�  Nj  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�	JavaClass�����}�(hKhh)��}�(hhhM
hKkhKubh�ubhh�h]�(hh)��}�(hh�JavaMemberArray�����}�(hKhh)��}�(hhhM
hKmhKubh�ubhj�  h]�hrj�  hshthuhvh/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]��VSortedArray<JavaMember,BaseArray<JavaMember,16,BASEARRAYFLAGS::NONE,CStdLibAllocator>>�hth	��aubj�  )��}�(hh�
_className�����}�(hKhh)��}�(hhhM�
hKohKubh�ubhj�  h]�hrj�  hshthuj�  h/NhwNh�const Char*�hxNhyNhzK h{]�h}h	h~}�h��j  �ubj�  )��}�(hh�_members�����}�(hKhh)��}�(hhhM�
hKphKubh�ubhj�  h]�hrj�  hshthuj�  h/NhwNh�JavaMemberArray*�hxNhyNhzK h{]�h}h	h~}�h��j  �ubj�  )��}�(hh�
_javaClass�����}�(hKhh)��}�(hhhM�
hKqhKubh�ubhj�  h]�hrj�  hshthuj�  h/NhwNh�jclass�hxNhyNhzK h{]�h}h	h~}�h��j  �ubj  )��}�(hj�  hj�  h]�hrj�  hshthuj�  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  j�  j  �j  ]�j9  Nj:  Nubj  )��}�(hh�IsEqual�����}�(hKhh)��}�(hhhMChKxhKubh�ubhj�  h]�hrj  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �Bool�j  �j  ]�(j  )��}�(h�const JavaClass&�hh�a�����}�(hKhh)��}�(hhhM\hKxhK.ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const JavaClass&�hh�b�����}�(hKhh)��}�(hhhMphKxhKBubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�IsEqual�����}�(hKhh)��}�(hhhM�hK}hKubh�ubhj�  h]�hrj!  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �Bool�j  �j  ]�(j  )��}�(h�const Char*�hh�cl�����}�(hKhh)��}�(hhhM�hK}hK)ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const JavaClass&�hh�b�����}�(hKhh)��}�(hhhMhK}hK>ubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�LessThan�����}�(hKhh)��}�(hhhMwhK�hKubh�ubhj�  h]�hrj@  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �Bool�j  �j  ]�(j  )��}�(h�const JavaClass&�hh�a�����}�(hKhh)��}�(hhhM�hK�hK/ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const JavaClass&�hh�b�����}�(hKhh)��}�(hhhM�hK�hKCubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�LessThan�����}�(hKhh)��}�(hhhMhK�hKubh�ubhj�  h]�hrj_  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �Bool�j  �j  ]�(j  )��}�(h�const Char*�hh�cl�����}�(hKhh)��}�(hhhM-hK�hK*ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const JavaClass&�hh�b�����}�(hKhh)��}�(hhhMBhK�hK?ubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�InitInsertData�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhj�  h]�hrj~  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �void�j  �j  ]�(j  )��}�(h�
JavaClass&�hh�initme�����}�(hKhh)��}�(hhhM�hK�hK(ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�	className�����}�(hKhh)��}�(hhhM�hK�hK<ubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�CallStaticMember�����}�(hKhh)��}�(hhhM<hK�hKubh�ubhj�  h]�hrj�  hshthuj  h/h �Template���)��}�j  ]�h �TypeTemplateParam���)��}�(hh)��}�(hhhM.hK�hKubj$  �hh�T�����}�(hKhh)��}�(hhhM7hK�hKubh�ubj#  N�variance�NubasbhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �T�j  �j  ]�(j  )��}�(h�JNIEnv*�hh�env�����}�(hKhh)��}�(hhhMUhK�hK2ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�
memberName�����}�(hKhh)��}�(hhhMfhK�hKCubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�sig�����}�(hKhh)��}�(hhhM~hK�hK[ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�va_list�hh�list�����}�(hKhh)��}�(hhhM�hK�hKhubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�CallStaticMemberVoid�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhj�  h]�hrj�  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �void�j  �j  ]�(j  )��}�(h�JNIEnv*�hh�env�����}�(hKhh)��}�(hhhMhK�hK$ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�
memberName�����}�(hKhh)��}�(hhhMhK�hK5ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�sig�����}�(hKhh)��}�(hhhM*hK�hKMubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�va_list�hh�list�����}�(hKhh)��}�(hhhM7hK�hKZubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�
CallMember�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhj�  h]�hrj  hshthuj  h/j�  )��}�j  ]�j�  )��}�(hh)��}�(hhhM�hK�hKubj$  �hh�T�����}�(hKhh)��}�(hhhM�hK�hKubh�ubj#  Nj�  NubasbhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �T�j  �j  ]�(j  )��}�(h�JNIEnv*�hh�env�����}�(hKhh)��}�(hhhM�hK�hK,ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�jobject�hh�object�����}�(hKhh)��}�(hhhMhK�hK9ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�
memberName�����}�(hKhh)��}�(hhhMhK�hKMubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�sig�����}�(hKhh)��}�(hhhM4hK�hKeubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�va_list�hh�list�����}�(hKhh)��}�(hhhMAhK�hKrubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�GetStaticObjectField�����}�(hKhh)��}�(hhhMBhM	hKubh�ubhj�  h]�hrjX  hshthuj  h/j�  )��}�j  ]�j�  )��}�(hh)��}�(hhhM4hM	hKubj$  �hh�T�����}�(hKhh)��}�(hhhM=hM	hKubh�ubj#  Nj�  NubasbhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �T�j  �j  ]�(j  )��}�(h�JNIEnv*�hh�env�����}�(hKhh)��}�(hhhM_hM	hK6ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�
memberName�����}�(hKhh)��}�(hhhMphM	hKGubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�sig�����}�(hKhh)��}�(hhhM�hM	hK_ubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubehrj�  hshthuj�  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]�j�  Nj�  Nj  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�JavaClassArray�����}�(hKhh)��}�(hhhM� hM0hKubh�ubhh�h]�(j  )��}�(hh�SetEnv�����}�(hKhh)��}�(hhhM&!hM3hKubh�ubhj�  h]�hrj�  hsh�public�����}�(hKhh)��}�(hhhM!hM2hKubh�ubhuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �void�j  �j  ]�j  )��}�(h�JNIEnv*�hh�env�����}�(hKhh)��}�(hhhM5!hM3hKubh�ubj#  Nj$  �j%  �j&  �ubaj9  Nj:  Nubj  )��}�(hh�InsertClass�����}�(hKhh)��}�(hhhM[!hM8hKubh�ubhj�  h]�hrj�  hsj�  huj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �
JavaClass*�j  �j  ]�j  )��}�(h�const Char*�hh�	className�����}�(hKhh)��}�(hhhMs!hM8hK%ubh�ubj#  Nj$  �j%  �j&  �ubaj9  Nj:  Nubj�  )��}�(hh�_env�����}�(hKhh)��}�(hhhM�"hMNhK
ubh�ubhj�  h]�hrj�  hsh�private�����}�(hKhh)��}�(hhhM�"hMMhKubh�ubhuj�  h/NhwNh�JNIEnv*�hxNhyNhzK h{]�h}h	h~}�h��j  �ubehrj�  hshthuj�  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]��XSortedArray<JavaClass, BaseArray<JavaClass, 16, BASEARRAYFLAGS::NONE, CStdLibAllocator>>�h�private�����}�(hKhh)��}�(hhhM� hM0hKubh�ubh	��aj�  Nj�  Nj  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�JavaClassHash�����}�(hKhh)��}�(hhhM�"hMQhKubh�ubhh�h]�(j  )��}�(hh�GetClassArray�����}�(hKhh)��}�(hhhMD#hMThKubh�ubhj�  h]�hrj�  hsh�public�����}�(hKhh)��}�(hhhM+#hMShKubh�ubhuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �JavaClassArray*�j  �j  ]�j  )��}�(h�JNIEnv*�hh�env�����}�(hKhh)��}�(hhhMZ#hMThK(ubh�ubj#  Nj$  �j%  �j&  �ubaj9  Nj:  Nubj�  )��}�(hh�_lock�����}�(hKhh)��}�(hhhM^$hMhhKubh�ubhj�  h]�hrj  hsh�private�����}�(hKhh)��}�(hhhMK$hMghKubh�ubhuj�  h/NhwNh�Spinlock�hxNhyNhzK h{]�h}h	h~}�h��j  �ubehrj�  hshthuj�  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]�� HashMap<JNIEnv*, JavaClassArray>�h�public�����}�(hKhh)��}�(hhhM#hMQhKubh�ubh	��aj�  Nj�  Nj  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�
JavaHelper�����}�(hKhh)��}�(hhhMo$hMkhKubh�ubhh�h]�(j  )��}�(hh�CallStaticMember�����}�(hKhh)��}�(hhhM�$hMohKubh�ubhj/  h]�hrj<  hsh�public�����}�(hKhh)��}�(hhhM|$hMmhKubh�ubhuj  h/j�  )��}�j  ]�j�  )��}�(hh)��}�(hhhM�$hMohKubj$  �hh�T�����}�(hKhh)��}�(hhhM�$hMohKubh�ubj#  Nj�  NubasbhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �T�j  �j  ]�(j  )��}�(h�JNIEnv*�hh�env�����}�(hKhh)��}�(hhhM�$hMohK2ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�	className�����}�(hKhh)��}�(hhhM�$hMohKCubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�
memberName�����}�(hKhh)��}�(hhhM�$hMohKZubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�sig�����}�(hKhh)��}�(hhhM�$hMohKrubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(hh	hh�...�����}�(hKhh)��}�(hhhM�$hMohKwubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�CallStaticMemberVoid�����}�(hKhh)��}�(hhhM�'hM�hKubh�ubhj/  h]�hrj�  hsjC  huj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �void�j  �j  ]�(j  )��}�(h�JNIEnv*�hh�env�����}�(hKhh)��}�(hhhM�'hM�hK$ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�	className�����}�(hKhh)��}�(hhhM�'hM�hK5ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�
memberName�����}�(hKhh)��}�(hhhM(hM�hKLubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�sig�����}�(hKhh)��}�(hhhM*(hM�hKdubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(hh	hh�...�����}�(hKhh)��}�(hhhM/(hM�hKiubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�
CallMember�����}�(hKhh)��}�(hhhM�*hM�hKubh�ubhj/  h]�hrj�  hsjC  huj  h/j�  )��}�j  ]�j�  )��}�(hh)��}�(hhhM�*hM�hKubj$  �hh�T�����}�(hKhh)��}�(hhhM�*hM�hKubh�ubj#  Nj�  NubasbhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �T�j  �j  ]�(j  )��}�(h�JNIEnv*�hh�env�����}�(hKhh)��}�(hhhM+hM�hK,ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�jobject�hh�object�����}�(hKhh)��}�(hhhM+hM�hK9ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�	className�����}�(hKhh)��}�(hhhM&+hM�hKMubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�
memberName�����}�(hKhh)��}�(hhhM=+hM�hKdubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�sig�����}�(hKhh)��}�(hhhMU+hM�hK|ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(hh	hh�...�����}�(hKhh)��}�(hhhMZ+hM�hK�ubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�GetStaticObjectField�����}�(hKhh)��}�(hhhM>.hM�hKubh�ubhj/  h]�hrj  hsjC  huj  h/j�  )��}�j  ]�j�  )��}�(hh)��}�(hhhM0.hM�hKubj$  �hh�T�����}�(hKhh)��}�(hhhM9.hM�hKubh�ubj#  Nj�  NubasbhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �T�j  �j  ]�(j  )��}�(h�JNIEnv*�hh�env�����}�(hKhh)��}�(hhhM[.hM�hK6ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�	className�����}�(hKhh)��}�(hhhMl.hM�hKGubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�
memberName�����}�(hKhh)��}�(hhhM�.hM�hK^ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const Char*�hh�sig�����}�(hKhh)��}�(hhhM�.hM�hKvubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj�  )��}�(hh�_classes�����}�(hKhh)��}�(hhhMC1hM�hKubh�ubhj/  h]�hrjN  hsh�private�����}�(hKhh)��}�(hhhM+1hM�hKubh�ubhuj�  h/NhwNh�JavaClassHash�hxNhyNhzK h{]�h}h	h~}�h��j  �ubehrj3  hshthuj�  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��h�]�j�  Nj�  Nj  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�g_javaHelper�����}�(hKhh)��}�(hhhMc1hM�hKubh�ubhh�h]�hrjf  hshthuj�  h/NhwNh�
JavaHelper�hxNhyNhzK h{]�h}h	h~}�h��j  �ubj  )��}�(hh�GetPrintableString�����}�(hKhh)��}�(hhhM�1hM�hKubh�ubhh�h]�hrjr  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �String�j  �j  ]�(j  )��}�(h�JNIEnv*�hh�env�����}�(hKhh)��}�(hhhM�1hM�hK*ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const jstring&�hh�val�����}�(hKhh)��}�(hhhM�1hM�hK>ubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubj  )��}�(hh�ToString�����}�(hKhh)��}�(hhhM�3hM�hKubh�ubhh�h]�hrj�  hshthuj  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j  �j  �j  �j  �String�j  �j  ]�(j  )��}�(h�JNIEnv*�hh�env�����}�(hKhh)��}�(hhhM�3hM�hK'ubh�ubj#  Nj$  �j%  �j&  �ubj  )��}�(h�const jstring&�hh�str�����}�(hKhh)��}�(hhhM�3hM�hK;ubh�ubj#  Nj$  �j%  �j&  �ubej9  Nj:  Nubehrh�hshthu�	namespace�h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h���preprocessorConditions�]��root�hh N�containsResourceId���registry���usings����minIndentation�K �maxIndentation�K �firstMember��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM?4hMhKubh�ububehrhhshthuj�  h/NhwNhNhxNhyNhzK h{]�h}h	h~}�h��j�  ]�j�  hh ]�(hh)h0h4h8h<h@hIhNhRhVhZh^hih�h�h�h�h�h�h�h�h�h�j  j;  jH  jU  jb  jo  j|  j�  j�  j�  j�  j�  j/  jb  jn  j�  j�  ej�  �j�  �j�  ���hxx1�N�hxx2�N�snippets�}�j�  K j�  K j�  �ub.