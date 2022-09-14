��29      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��RD:\C4D_MMD_Tool\sdk_r21\frameworks\crypt.framework\source\maxon\cryptography_ssh.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/object.h�hhh]��quote��"��template�Nubh �Class���)��}�(hh�_LIBSSH2_SESSION�����}�(hKhh)��}�(hhhK]hKhKubh�ubhhh]��
simpleName�h6�access��public��kind��class�h/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���bases�]��	interface�N�refKind�N�static���refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent���forward���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���ambiguousCalls�]��	selfCalls�]��methodNames�}�ubh1)��}�(hh�_LIBSSH2_SFTP�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhh]�h;hfh<h=h>h?h/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hJ]�hLNhMNhN�hONhPNhQ�hR�hS�hT�hU�hV�hW�hX�hYNhZ�h[�h\]�h^]�h`}�ubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhh]�(h �	TypeAlias���)��}�(hh�LIBSSH2_PASSWD_CHANGEREQ_FUNC�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhqh]�h;h�h<h=h>�	typealias�h/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hJ]��Ivoid(*)(LIBSSH2_SESSION*session,char**newpw,int*newpw_len,void**abstract)�h=h	��aubh1)��}�(hh�SSHInterface�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhqh]�(h �Function���)��}�(hh�libssh2_session_init�����}�(hKhh)��}�(hhhM"hK"hK'ubh�ubhh�h]�h;h�h<h�public�����}�(hKhh)��}�(hhhM�hK!hKubh�ubh>h�MAXON_METHOD�����}�(hKhh)��}�(hhhMhK"hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN��explicit���deleted���retType��LIBSSH2_SESSION*��const���params�]��
observable�N�result�Nubh�)��}�(hh�libssh2_session_disconnect_ex�����}�(hKhh)��}�(hhhMShK#hKubh�ubhh�h]�h;h�h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhMBhK#hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�(h �	Parameter���)��}�(h�LIBSSH2_SESSION*�hh�session�����}�(hKhh)��}�(hhhM�hK#hKIubh�ub�default�N�pack���input���output��ubh�)��}�(h�int�hh�reason�����}�(hKhh)��}�(hhhM�hK#hKVubh�ubh�NhՉhֈh׉ubh�)��}�(h�const char*�hh�description�����}�(hKhh)��}�(hhhM�hK#hKjubh�ubh�NhՉhֈh׉ubh�)��}�(h�const char*�hh�lang�����}�(hKhh)��}�(hhhM�hK#hK�ubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_session_free�����}�(hKhh)��}�(hhhM�hK$hKubh�ubhh�h]�h;h�h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK$hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�h�)��}�(h�LIBSSH2_SESSION*�hh�session�����}�(hKhh)��}�(hhhMhK$hK@ubh�ubh�NhՉhֈh׉ubah�Nh�Nubh�)��}�(hh�libssh2_session_set_blocking�����}�(hKhh)��}�(hhhM&hK%hKubh�ubhh�h]�h;j  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhMhK%hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��void�h��h�]�(h�)��}�(h�LIBSSH2_SESSION*�hh�session�����}�(hKhh)��}�(hhhMThK%hKIubh�ubh�NhՉhֈh׉ubh�)��}�(h�int�hh�blocking�����}�(hKhh)��}�(hhhMahK%hKVubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_session_handshake�����}�(hKhh)��}�(hhhM�hK&hKubh�ubhh�h]�h;j8  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhMthK&hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�(h�)��}�(h�LIBSSH2_SESSION*�hh�session�����}�(hKhh)��}�(hhhM�hK&hKEubh�ubh�NhՉhֈh׉ubh�)��}�(h�Int�hh�socket�����}�(hKhh)��}�(hhhM�hK&hKRubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_hostkey_hash�����}�(hKhh)��}�(hhhM�hK'hK"ubh�ubhh�h]�h;j]  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK'hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��const char*�h��h�]�(h�)��}�(h�LIBSSH2_SESSION*�hh�session�����}�(hKhh)��}�(hhhMhK'hKHubh�ubh�NhՉhֈh׉ubh�)��}�(h�int�hh�	hash_type�����}�(hKhh)��}�(hhhMhK'hKUubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_userauth_list�����}�(hKhh)��}�(hhhMGhK(hK"ubh�ubhh�h]�h;j�  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhM.hK(hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��const char*�h��h�]�(h�)��}�(h�LIBSSH2_SESSION*�hh�session�����}�(hKhh)��}�(hhhMnhK(hKIubh�ubh�NhՉhֈh׉ubh�)��}�(h�const char*�hh�username�����}�(hKhh)��}�(hhhM�hK(hK^ubh�ubh�NhՉhֈh׉ubh�)��}�(h�unsigned int�hh�username_len�����}�(hKhh)��}�(hhhM�hK(hKuubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_userauth_password_ex�����}�(hKhh)��}�(hhhM�hK)hKubh�ubhh�h]�h;j�  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK)hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�(h�)��}�(h�LIBSSH2_SESSION*�hh�session�����}�(hKhh)��}�(hhhM�hK)hKHubh�ubh�NhՉhֈh׉ubh�)��}�(h�const char*�hh�username�����}�(hKhh)��}�(hhhMhK)hK]ubh�ubh�NhՉhֈh׉ubh�)��}�(h�unsigned int�hh�username_len�����}�(hKhh)��}�(hhhMhK)hKtubh�ubh�NhՉhֈh׉ubh�)��}�(h�const char*�hh�password�����}�(hKhh)��}�(hhhM6hK)hK�ubh�ubh�NhՉhֈh׉ubh�)��}�(h�unsigned int�hh�password_len�����}�(hKhh)��}�(hhhMMhK)hK�ubh�ubh�NhՉhֈh׉ubh�)��}�(h�LIBSSH2_PASSWD_CHANGEREQ_FUNC�hh�passwd_change_cb�����}�(hKhh)��}�(hhhMyhK)hK�ubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_session_last_error�����}�(hKhh)��}�(hhhM�hK*hKubh�ubhh�h]�h;j�  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK*hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�(h�)��}�(h�LIBSSH2_SESSION*�hh�session�����}�(hKhh)��}�(hhhM�hK*hKFubh�ubh�NhՉhֈh׉ubh�)��}�(h�char**�hh�errmsg�����}�(hKhh)��}�(hhhM�hK*hKVubh�ubh�NhՉhֈh׉ubh�)��}�(h�int*�hh�
errmsg_len�����}�(hKhh)��}�(hhhM�hK*hKcubh�ubh�NhՉhֈh׉ubh�)��}�(h�int�hh�want_buf�����}�(hKhh)��}�(hhhM�hK*hKsubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_sftp_init�����}�(hKhh)��}�(hhhM-	hK,hK$ubh�ubhh�h]�h;j0  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhM	hK,hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��LIBSSH2_SFTP*�h��h�]�h�)��}�(h�LIBSSH2_SESSION*�hh�session�����}�(hKhh)��}�(hhhMP	hK,hKGubh�ubh�NhՉhֈh׉ubah�Nh�Nubh�)��}�(hh�libssh2_sftp_shutdown�����}�(hKhh)��}�(hhhMs	hK-hKubh�ubhh�h]�h;jL  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhMb	hK-hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�h�)��}�(h�LIBSSH2_SFTP*�hh�sftp�����}�(hKhh)��}�(hhhM�	hK-hK>ubh�ubh�NhՉhֈh׉ubah�Nh�Nubh�)��}�(hh�libssh2_sftp_open_ex�����}�(hKhh)��}�(hhhM�	hK.hK+ubh�ubhh�h]�h;jh  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhM�	hK.hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��LIBSSH2_SFTP_HANDLE*�h��h�]�(h�)��}�(h�LIBSSH2_SFTP*�hh�sftp�����}�(hKhh)��}�(hhhM�	hK.hKNubh�ubh�NhՉhֈh׉ubh�)��}�(h�const char*�hh�filename�����}�(hKhh)��}�(hhhM�	hK.hK`ubh�ubh�NhՉhֈh׉ubh�)��}�(h�unsigned int�hh�filename_len�����}�(hKhh)��}�(hhhM
hK.hKwubh�ubh�NhՉhֈh׉ubh�)��}�(h�unsigned long�hh�flags�����}�(hKhh)��}�(hhhM0
hK.hK�ubh�ubh�NhՉhֈh׉ubh�)��}�(h�long�hh�mode�����}�(hKhh)��}�(hhhM<
hK.hK�ubh�ubh�NhՉhֈh׉ubh�)��}�(h�int�hh�	open_type�����}�(hKhh)��}�(hhhMF
hK.hK�ubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_sftp_close�����}�(hKhh)��}�(hhhM�
hK/hKubh�ubhh�h]�h;j�  h<h�h>�function�h/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�h�)��}�(h�LIBSSH2_SFTP_HANDLE*�hh�handle�����}�(hKhh)��}�(hhhM�
hK/hK5ubh�ubh�NhՉhֈh׉ubah�Nh�Nubh�)��}�(hh�libssh2_sftp_closedir�����}�(hKhh)��}�(hhhMhK0hKubh�ubhh�h]�h;j�  h<h�h>j�  h/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�h�)��}�(h�LIBSSH2_SFTP_HANDLE*�hh�handle�����}�(hKhh)��}�(hhhM3hK0hK8ubh�ubh�NhՉhֈh׉ubah�Nh�Nubh�)��}�(hh�libssh2_sftp_close_handle�����}�(hKhh)��}�(hhhM�hK1hKubh�ubhh�h]�h;j�  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhMqhK1hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�h�)��}�(h�LIBSSH2_SFTP_HANDLE*�hh�handle�����}�(hKhh)��}�(hhhM�hK1hKIubh�ubh�NhՉhֈh׉ubah�Nh�Nubh�)��}�(hh�libssh2_sftp_unlink_ex�����}�(hKhh)��}�(hhhM�hK2hKubh�ubhh�h]�h;j�  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK2hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�(h�)��}�(h�LIBSSH2_SFTP*�hh�sftp�����}�(hKhh)��}�(hhhM�hK2hK?ubh�ubh�NhՉhֈh׉ubh�)��}�(h�const char*�hh�filename�����}�(hKhh)��}�(hhhM
hK2hKQubh�ubh�NhՉhֈh׉ubh�)��}�(h�unsigned int�hh�filename_len�����}�(hKhh)��}�(hhhM!hK2hKhubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_sftp_mkdir_ex�����}�(hKhh)��}�(hhhMIhK3hKubh�ubhh�h]�h;j(  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhM8hK3hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�(h�)��}�(h�LIBSSH2_SFTP*�hh�sftp�����}�(hKhh)��}�(hhhMmhK3hK>ubh�ubh�NhՉhֈh׉ubh�)��}�(h�const char*�hh�path�����}�(hKhh)��}�(hhhMhK3hKPubh�ubh�NhՉhֈh׉ubh�)��}�(h�unsigned int�hh�path_len�����}�(hKhh)��}�(hhhM�hK3hKcubh�ubh�NhՉhֈh׉ubh�)��}�(h�long�hh�mode�����}�(hKhh)��}�(hhhM�hK3hKrubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_sftp_rmdir_ex�����}�(hKhh)��}�(hhhM�hK4hKubh�ubhh�h]�h;j_  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK4hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�(h�)��}�(h�LIBSSH2_SFTP*�hh�sftp�����}�(hKhh)��}�(hhhM�hK4hK>ubh�ubh�NhՉhֈh׉ubh�)��}�(h�const char*�hh�path�����}�(hKhh)��}�(hhhM�hK4hKPubh�ubh�NhՉhֈh׉ubh�)��}�(h�unsigned int�hh�path_len�����}�(hKhh)��}�(hhhM
hK4hKcubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_sftp_fstat_ex�����}�(hKhh)��}�(hhhM.hK5hKubh�ubhh�h]�h;j�  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhMhK5hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�(h�)��}�(h�LIBSSH2_SFTP_HANDLE*�hh�handle�����}�(hKhh)��}�(hhhMYhK5hKEubh�ubh�NhՉhֈh׉ubh�)��}�(h�LIBSSH2_SFTP_ATTRIBUTES*�hh�attrs�����}�(hKhh)��}�(hhhMzhK5hKfubh�ubh�NhՉhֈh׉ubh�)��}�(h�bool�hh�setstat�����}�(hKhh)��}�(hhhM�hK5hKrubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_sftp_stat_ex�����}�(hKhh)��}�(hhhM�hK6hKubh�ubhh�h]�h;j�  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK6hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�(h�)��}�(h�LIBSSH2_SFTP*�hh�sftp�����}�(hKhh)��}�(hhhM�hK6hK=ubh�ubh�NhՉhֈh׉ubh�)��}�(h�const char*�hh�path�����}�(hKhh)��}�(hhhM�hK6hKOubh�ubh�NhՉhֈh׉ubh�)��}�(h�unsigned int�hh�path_len�����}�(hKhh)��}�(hhhM�hK6hKbubh�ubh�NhՉhֈh׉ubh�)��}�(h�int�hh�	stat_type�����}�(hKhh)��}�(hhhM�hK6hKpubh�ubh�NhՉhֈh׉ubh�)��}�(h�LIBSSH2_SFTP_ATTRIBUTES*�hh�attrs�����}�(hKhh)��}�(hhhM#hK6hK�ubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_sftp_read�����}�(hKhh)��}�(hhhMDhK7hKubh�ubhh�h]�h;j�  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhM3hK7hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��Int�h��h�]�(h�)��}�(h�LIBSSH2_SFTP_HANDLE*�hh�handle�����}�(hKhh)��}�(hhhMkhK7hKAubh�ubh�NhՉhֈh׉ubh�)��}�(h�char*�hh�buffer�����}�(hKhh)��}�(hhhMyhK7hKOubh�ubh�NhՉhֈh׉ubh�)��}�(h�size_t�hh�buffer_maxlen�����}�(hKhh)��}�(hhhM�hK7hK^ubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_sftp_write�����}�(hKhh)��}�(hhhM�hK8hKubh�ubhh�h]�h;j)  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK8hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��Int�h��h�]�(h�)��}�(h�LIBSSH2_SFTP_HANDLE*�hh�handle�����}�(hKhh)��}�(hhhM�hK8hKBubh�ubh�NhՉhֈh׉ubh�)��}�(h�const char*�hh�buffer�����}�(hKhh)��}�(hhhM�hK8hKVubh�ubh�NhՉhֈh׉ubh�)��}�(h�size_t�hh�count�����}�(hKhh)��}�(hhhM�hK8hKeubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_sftp_readdir_ex�����}�(hKhh)��}�(hhhMhK9hKubh�ubhh�h]�h;jW  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhMhK9hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��int�h��h�]�(h�)��}�(h�LIBSSH2_SFTP_HANDLE*�hh�handle�����}�(hKhh)��}�(hhhMJhK9hKGubh�ubh�NhՉhֈh׉ubh�)��}�(h�char*�hh�buffer�����}�(hKhh)��}�(hhhMXhK9hKUubh�ubh�NhՉhֈh׉ubh�)��}�(h�size_t�hh�buffer_maxlen�����}�(hKhh)��}�(hhhMghK9hKdubh�ubh�NhՉhֈh׉ubh�)��}�(h�char*�hh�	longentry�����}�(hKhh)��}�(hhhM|hK9hKyubh�ubh�NhՉhֈh׉ubh�)��}�(h�size_t�hh�longentry_maxlen�����}�(hKhh)��}�(hhhM�hK9hK�ubh�ubh�NhՉhֈh׉ubh�)��}�(h�LIBSSH2_SFTP_ATTRIBUTES*�hh�attrs�����}�(hKhh)��}�(hhhM�hK9hK�ubh�ubh�NhՉhֈh׉ubeh�Nh�Nubh�)��}�(hh�libssh2_sftp_seek64�����}�(hKhh)��}�(hhhM�hK:hKubh�ubhh�h]�h;j�  h<h�h>h�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK:hK	ubh�ubh/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�hN�h��h��h��void�h��h�]�(h�)��}�(h�LIBSSH2_SFTP_HANDLE*�hh�handle�����}�(hKhh)��}�(hhhMhK:hKDubh�ubh�NhՉhֈh׉ubh�)��}�(h�UInt64�hh�offset�����}�(hKhh)��}�(hhhMhK:hKSubh�ubh�NhՉhֈh׉ubeh�Nh�Nubeh;h�h<h=h>h?h/Nh@NhNhAh�"net.maxon.interface.ssh"�����}�(hKhh)��}�(hhhM�hK hKAubh�ubhBNhCK hD]�h�@/// This interface maps all libssh2 functions into a interface.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubahF�@/// This interface maps all libssh2 functions into a interface.
�hG}�hI�hJ]�hLKhMNhN�hONhPNhQ�hR�hS�hT�hU�hV�hW�hX�hYNhZ�h[�h\]�h^]�h`}�ubeh;huh<h=h>�	namespace�h/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI��preprocessorConditions�]��root�hh N�containsResourceId���registry���usings����minIndentation�K �maxIndentation�K �firstMember��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhMghKChKubh�ububeh;hh<h=h>j�  h/Nh@NhNhANhBNhCK hD]�hFh	hG}�hI�j�  ]�j�  hh ]�(hh)h2hbhqh|h�j�  ej�  �j�  �j�  ���hxx1�hq�hxx2�hq�snippets�}�j�  K j�  K j�  �ub.