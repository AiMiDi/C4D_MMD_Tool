��h      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��VD:\C4D_MMD_Tool\sdk_r20\frameworks\core.framework\source\maxon\ansi_type_conversions.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/datetime.h�hhh]��quote��"��template�Nubh()��}�(h�time.h�hhh]�h-�<�h/Nubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhKhKhKubh�ubhhh]�(h �Variable���)��}�(hh�g_privateDays�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh5h]��
simpleName�hD�access��public��kind��variable�h/N�friend�Nh�const UInt32��id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���static��ubh �Function���)��}�(hh�ConvertLocalDateTimeToTM�����}�(hKhh)��}�(hhhM>hKhK!ubh�ubhh5h]�hIh`hJhKhL�function�h/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX�hY��explicit���deleted���retType��tm��const���params�]�h �	Parameter���)��}�(h�const LocalDateTime&�hh�dateTime�����}�(hKhh)��}�(hhhMlhKhKOubh�ub�default�N�pack���input���output��uba�
observable�N�result�Nubh[)��}�(hh�ConvertTMToLocalDateTime�����}�(hKhh)��}�(hhhMehK'hK,ubh�ubhh5h]�hIh�hJhKhLheh/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX�hY�hh�hi�hj�LocalDateTime�hl�hm]�hp)��}�(h�	const tm&�hh�st�����}�(hKhh)��}�(hhhM�hK'hKOubh�ubhzNh{�h|�h}�ubah~NhNubh)��}�(hNhh5h]�h h�#ifdef MAXON_TARGET_WINDOWS�����}�(hK
hh)��}�(hhhM�hK4hKubh�ububh[)��}�(hh�mktime_r�����}�(hKhh)��}�(hhhM�hK:hK&ubh�ubhh5h]�hIh�hJhKhLheh/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX�hY�hh�hi�hj�time_t�hl�hm]�hp)��}�(h�
struct tm*�hh�tm�����}�(hKhh)��}�(hhhM�hK:hK:ubh�ubhzNh{�h|�h}�ubah~NhNubh[)��}�(hh�timegm_r�����}�(hKhh)��}�(hhhM�hK>hK&ubh�ubhh5h]�hIh�hJhKhLheh/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX�hY�hh�hi�hj�time_t�hl�hm]�hp)��}�(h�
struct tm*�hh�tm�����}�(hKhh)��}�(hhhMhK>hK:ubh�ubhzNh{�h|�h}�ubah~NhNubh)��}�(hNhh5h]�h h�#else�����}�(hK
hh)��}�(hhhM*	hK\hKubh�ububh[)��}�(hh�mktime_r�����}�(hKhh)��}�(hhhMU	hK]hK&ubh�ubhh5h]�hIh�hJhKhLheh/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX�hY�hh�hi�hj�time_t�hl�hm]�hp)��}�(h�
struct tm*�hh�tm�����}�(hKhh)��}�(hhhMi	hK]hK:ubh�ubhzNh{�h|�h}�ubah~NhNubh)��}�(hNhh5h]�h h�8#if defined MAXON_TARGET_ANDROID && __ANDROID_API__ < 12�����}�(hK
hh)��}�(hhhM�	hKbhKubh�ububh[)��}�(hh�timegm�����}�(hKhh)��}�(hhhML
hKehKubh�ubhh5h]�hIh�hJhKhLheh/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX�hY�hh�hi�hj�time_t�hl�hm]�hp)��}�(h�
struct tm*�hh�a_tm�����}�(hKhh)��}�(hhhM_
hKehK#ubh�ubhzNh{�h|�h}�ubah~NhNubh)��}�(hNhh5h]�h h�#endif�����}�(hK
hh)��}�(hhhM\hKrhKubh�ububh[)��}�(hh�timegm_r�����}�(hKhh)��}�(hhhM�hKthK&ubh�ubhh5h]�hIj  hJhKhLheh/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX�hY�hh�hi�hj�time_t�hl�hm]�hp)��}�(h�
struct tm*�hh�tm�����}�(hKhh)��}�(hhhM�hKthK:ubh�ubhzNh{�h|�h}�ubah~NhNubh)��}�(hNhh5h]�h h�#endif�����}�(hK
hh)��}�(hhhM�hKxhKubh�ububehIh9hJhKhL�	namespace�h/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX��preprocessorConditions�]��root�hh N�containsResourceId���registry���minIndentation�K �maxIndentation�K �firstMember��ubh �Define���)��}�(hh�gmtime_r�����}�(hKhh)��}�(hhhM*hK8hK
ubh�ubhhh]�hIjB  hJhKhL�#define�h/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX�hm]�(h�r�����}�(hKhh)��}�(hhhM3hK8hKubh�ubh�s�����}�(hKhh)��}�(hhhM6hK8hKubh�ubeubj=  )��}�(hh�localtime_r�����}�(hKhh)��}�(hhhMQhK9hK
ubh�ubhhh]�hIj[  hJhKhLjG  h/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX�hm]�(h�r�����}�(hKhh)��}�(hhhM]hK9hKubh�ubh�s�����}�(hKhh)��}�(hhhM`hK9hKubh�ubeubj=  )��}�(hh�	localtime�����}�(hKhh)��}�(hhhMBhK{hK	ubh�ubhhh]�hIjs  hJhKhLjG  h/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX�hm]�ubj=  )��}�(hh�gmtime�����}�(hKhh)��}�(hhhMshK|hK	ubh�ubhhh]�hIj  hJhKhLjG  h/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX�hm]�ubj=  )��}�(hh�timegm�����}�(hKhh)��}�(hhhM�hK}hK	ubh�ubhhh]�hIj�  hJhKhLjG  h/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX�hm]�ubj=  )��}�(hh�mktime�����}�(hKhh)��}�(hhhM�hK~hK	ubh�ubhhh]�hIj�  hJhKhLjG  h/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX�hm]�ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hK�hKubh�ububehIhhJhKhLj1  h/NhNNhNhPNhQNhRK hS]�hUh	hV}�hX�j4  ]�j6  hh ]�(hh)h0h5h@h\h�h�j>  jW  h�h�h�h�h�h�j	  j  j(  jo  j{  j�  j�  j�  ej7  �j8  ��hxx1�N�hxx2�N�snippets�}�j9  K j:  K j;  �ub.