��bR      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��HD:\C4D_MMD_Tool\sdk_2023\frameworks\core.framework\source\maxon\parser.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/string.h�hhh]��quote��"��template�Nubh()��}�(h�maxon/datadictionary.h�hhh]�h-h.h/Nubh()��}�(h�maxon/datadictionaryobject.h�hhh]�h-h.h/Nubh()��}�(h�maxon/url.h�hhh]�h-h.h/Nubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhK�hKhKubh�ubhhh]�(h �Enum���)��}�(hh�PARSERFLAGS�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh<h]�(h �	EnumValue���)��}�(hh�NONE�����}�(hKhh)��}�(hhhK�hKhKubh�ubhhGh]��
simpleName�hV�access��public��kind��	enumvalue�h/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���value��0�ubhQ)��}�(hh�
HAS_NO_EOF�����}�(hKhh)��}�(hhhK�hKhKubh�ubhhGh]�h[hph\h]h^h_h/Nh`NhNhaNhbNhcK hd]�hfh	hg}�hi�hj�1<<0�ubeh[hKh\h]h^�enum�h/Nh`NhNhaNhbNhcK hd]�hfh	hg}�hi��bases�]��scoped���
registered���flags��h ��enum class PARSERFLAGS
{
	NONE						= 0,
	HAS_NO_EOF			= 1 << 0,	/// Set to true if the connection should kept open and no eof if reached after the  object.
} �hK�early��ubh)��}�(hh�PARSERPARAMETERS�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh<h]�(h �Class���)��}�(hh�RESTRICT�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh�h]�h[h�h\h]h^�class�h/Nh`NhNhaNhbNhcK hd]�hfh	hg}�hi�h{]��	interface�N�refKind�N�static���refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent���forward���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���usings�]��constUsings�]��ambiguousCalls�]��	selfCalls�]��methodNames�}�ubh)��}�(hh�JWT�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh�h]�(h �	Attribute���)��}�(hh�STRINGENCODING�����}�(hKhh)��}�(hhhM�hKhK&ubh�ubhh�h]�h[h�h\h]h^h�MAXON_ATTRIBUTE�����}�(hKhh)��}�(hhhM�hKhKubh�ubh/Nh`NhNhah�&"net.maxon.parser.args.stringencoding"�����}�(hKhh)��}�(hhhM�hKhK6ubh�ubhbNhcK hd]�hfh	hg}�hi�ubh�)��}�(hh�
PRIVATEKEY�����}�(hKhh)��}�(hhhMohKhK$ubh�ubhh�h]�h[h�h\h]h^h�MAXON_ATTRIBUTE�����}�(hKhh)��}�(hhhMNhKhKubh�ubh/Nh`NhNhah�""net.maxon.parser.args.privatekey"�����}�(hKhh)��}�(hhhM{hKhK0ubh�ubhbNhcK hd]�h�3/// public key for jwt writer to encrypt the token
�����}�(hKhh)��}�(hhhMhKhKubh�ubahf�3/// public key for jwt writer to encrypt the token
�hg}�hi�ubh�)��}�(hh�	PUBLICKEY�����}�(hKhh)��}�(hhhM�hKhK$ubh�ubhh�h]�h[h�h\h]h^h�MAXON_ATTRIBUTE�����}�(hKhh)��}�(hhhM�hKhKubh�ubh/Nh`NhNhah�!"net.maxon.parser.args.publickey"�����}�(hKhh)��}�(hhhMhKhK/ubh�ubhbNhcK hd]�h�2/// public key for jwt reader to verify the token
�����}�(hKhh)��}�(hhhM�hKhKubh�ubahf�2/// public key for jwt reader to verify the token
�hg}�hi�ubeh[h�h\h]h^�	namespace�h/Nh`NhNhaNhbNhcK hd]�hfh	hg}�hi��preprocessorConditions�]��root�hh N�containsResourceId���registry��h����minIndentation�K�maxIndentation�K�firstMember��ubh)��}�(hh�CSV�����}�(hKhh)��}�(hhhM5hK"hKubh�ubhh�h]�(h�)��}�(hh�AUTODETECTDELIMITER�����}�(hKhh)��}�(hhhMThK$hKubh�ubhj  h]�h[j+  h\h]h^h�MAXON_ATTRIBUTE�����}�(hKhh)��}�(hhhM>hK$hKubh�ubh/Nh`NhNhah�4"net.maxon.parserparameters.csv.autodetectdelimiter"�����}�(hKhh)��}�(hhhMihK$hK.ubh�ubhbNhcK hd]�hfh	hg}�hi�ubh�)��}�(hh�	DELIMITER�����}�(hKhh)��}�(hhhM�hK%hKubh�ubhj  h]�h[jB  h\h]h^h�MAXON_ATTRIBUTE�����}�(hKhh)��}�(hhhM�hK%hKubh�ubh/Nh`NhNhah�*"net.maxon.parserparameters.csv.delimiter"�����}�(hKhh)��}�(hhhM�hK%hK&ubh�ubhbNhcK hd]�hfh	hg}�hi�ubh�)��}�(hh�DETECTDATATYPES�����}�(hKhh)��}�(hhhM\hK'hKubh�ubhj  h]�h[jY  h\h]h^h�MAXON_ATTRIBUTE�����}�(hKhh)��}�(hhhMFhK'hKubh�ubh/Nh`NhNhah�0"net.maxon.parserparameters.csv.detectdatatypes"�����}�(hKhh)��}�(hhhMmhK'hK*ubh�ubhbNhcK hd]�hfh	hg}�hi�ubh�)��}�(hh�FORCESAMECOLUMNDATATYPE�����}�(hKhh)��}�(hhhM�hK(hKubh�ubhj  h]�h[jp  h\h]h^h�MAXON_ATTRIBUTE�����}�(hKhh)��}�(hhhM�hK(hKubh�ubh/Nh`NhNhah�8"net.maxon.parserparameters.csv.forcecolumnsamedatatype"�����}�(hKhh)��}�(hhhM�hK(hK2ubh�ubhbNhcK hd]�hfh	hg}�hi�ubh�)��}�(hh�	HASHEADER�����}�(hKhh)��}�(hhhM�hK*hKubh�ubhj  h]�h[j�  h\h]h^h�MAXON_ATTRIBUTE�����}�(hKhh)��}�(hhhM�hK*hKubh�ubh/Nh`NhNhah�*"net.maxon.parserparameters.csv.hasheader"�����}�(hKhh)��}�(hhhM�hK*hK$ubh�ubhbNhcK hd]�hfh	hg}�hi�ubh�)��}�(hh�	QUOTECHAR�����}�(hKhh)��}�(hhhMhK+hKubh�ubhj  h]�h[j�  h\h]h^h�MAXON_ATTRIBUTE�����}�(hKhh)��}�(hhhM�hK+hKubh�ubh/Nh`NhNhah�*"net.maxon.parserparameters.csv.quotechar"�����}�(hKhh)��}�(hhhMhK+hK&ubh�ubhbNhcK hd]�hfh	hg}�hi�ubh�)��}�(hh�HASHTAGCOMMENTS�����}�(hKhh)��}�(hhhMShK,hKubh�ubhj  h]�h[j�  h\h]h^h�MAXON_ATTRIBUTE�����}�(hKhh)��}�(hhhM=hK,hKubh�ubh/Nh`NhNhah�0"net.maxon.parserparameters.csv.hashtagcomments"�����}�(hKhh)��}�(hhhMdhK,hK*ubh�ubhbNhcK hd]�hfh	hg}�hi�ubh�)��}�(hh�DOUBLEQUOTE�����}�(hKhh)��}�(hhhM�hK-hKubh�ubhj  h]�h[j�  h\h]h^h�MAXON_ATTRIBUTE�����}�(hKhh)��}�(hhhM�hK-hKubh�ubh/Nh`NhNhah�,"net.maxon.parserparameters.csv.doublequote"�����}�(hKhh)��}�(hhhM�hK-hK&ubh�ubhbNhcK hd]�hfh	hg}�hi�ubh�)��}�(hh�
TRIMSPACES�����}�(hKhh)��}�(hhhM3hK.hKubh�ubhj  h]�h[j�  h\h]h^h�MAXON_ATTRIBUTE�����}�(hKhh)��}�(hhhMhK.hKubh�ubh/Nh`NhNhah�+"net.maxon.parserparameters.csv.trimspaces"�����}�(hKhh)��}�(hhhM?hK.hK%ubh�ubhbNhcK hd]�hfh	hg}�hi�ubh�)��}�(hh�ROWLIMIT�����}�(hKhh)��}�(hhhM�hK/hKubh�ubhj  h]�h[j�  h\h]h^h�MAXON_ATTRIBUTE�����}�(hKhh)��}�(hhhM�hK/hKubh�ubh/Nh`NhNhah�)"net.maxon.parserparameters.csv.rowlimit"�����}�(hKhh)��}�(hhhM�hK/hK"ubh�ubhbNhcK hd]�hfh	hg}�hi�ubeh[j"  h\h]h^j  h/Nh`NhNhaNhbNhcK hd]�hfh	hg}�hi�j  ]�j  hh Nj  �j  �h���j  Kj  Kj  �ubeh[h�h\h]h^j  h/Nh`NhNhaNhbNhcK hd]�hfh	hg}�hi�j  ]�j  hh Nj  �j  �h���j  Kj  Kj  �ubh�)��}�(hh�ParserInterface�����}�(hKhh)��}�(hhhMhK3hKubh�ubhh<h]�(h �	TypeAlias���)��}�(hh�RESTRICT_DICTIONARY_PROPS�����}�(hKhh)��}�(hhhM�hK7hKubh�ubhj  h]�h[j$  h\h�public�����}�(hKhh)��}�(hhhM�hK6hKubh�ubh^�	typealias�h/Nh`NhNhaNhbNhcK hd]�hfh	hg}�hi�h{]��PARSERPARAMETERS::RESTRICT�h]h	��aubh �Function���)��}�(hh�Read�����}�(hKhh)��}�(hhhM�hKAhKubh�ubhj  h]�h[j;  h\j+  h^h�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKAhKubh�ubh/Nh`NhNhaNhbNhcK hd]�(h�p/// ConvertFromJWT converts a JWT token into a json DataDictionary. For more details of JWT see https://jwt.io/
�����}�(hKhh)��}�(hhhMI	hK:hKubh�ubh�G/// @param[in] nameOrStream				JSON formated input stream or file url.
�����}�(hKhh)��}�(hhhM�	hK;hKubh�ubh�//// @param[in] flags							See JWTPARSERFLAGS.
�����}�(hKhh)��}�(hhhM
hK<hKubh�ubh�W/// @param[in] objects				ValueReceiver which receives all processed DataDictionaries.
�����}�(hKhh)��}�(hhhM2
hK=hKubh�ubh�c/// @param[out] originalToken			[Optional] Returns the original token memory read from the stream.
�����}�(hKhh)��}�(hhhM�
hK>hKubh�ubh�p/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
�����}�(hKhh)��}�(hhhM�
hK?hKubh�ubehfX  /// ConvertFromJWT converts a JWT token into a json DataDictionary. For more details of JWT see https://jwt.io/
/// @param[in] nameOrStream				JSON formated input stream or file url.
/// @param[in] flags							See JWTPARSERFLAGS.
/// @param[in] objects				ValueReceiver which receives all processed DataDictionaries.
/// @param[out] originalToken			[Optional] Returns the original token memory read from the stream.
/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
�hg}�hi�h���explicit���deleted���retType��Result<void>��const���params�]�(h �	Parameter���)��}�(h�UrlOrInputStream&&�hh�nameOrStream�����}�(hKhh)��}�(hhhM�hKAhK4ubh�ub�default�N�pack���input���output��ubju  )��}�(h�PARSERFLAGS�hh�flags�����}�(hKhh)��}�(hhhMhKAhKNubh�ubj  Nj�  �j�  �j�  �ubju  )��}�(h�const StringDecodingRef&�hh�stringDecoding�����}�(hKhh)��}�(hhhM'hKAhKnubh�ubj  Nj�  �j�  �j�  �ubju  )��}�(h�+const ValueReceiver<const DataDictionary&>&�hh�objects�����}�(hKhh)��}�(hhhMchKAhK�ubh�ubj  Nj�  �j�  �j�  �ubju  )��}�(h�BaseArray<Char>*�hh�originalToken�����}�(hKhh)��}�(hhhM}hKAhK�ubh�ubj  �nullptr�j�  �j�  �j�  �ube�
observable�N�result��void�h��ubj6  )��}�(hh�
ReadString�����}�(hKhh)��}�(hhhMVhKKhKubh�ubhj  h]�h[j�  h\j+  h^h�MAXON_FUNCTION�����}�(hKhh)��}�(hhhM:hKKhKubh�ubh/Nh`NhNhaNhbNhcK hd]�(h�M/// ConvertFromJSON parses a json string into DataDictionary representation.
�����}�(hKhh)��}�(hhhM�hKDhKubh�ubh�?/// @param[in] parserData					JSON formated string to precess.
�����}�(hKhh)��}�(hhhMChKEhKubh�ubh�0/// @param[in] flags							See JSONPARSERFLAGS.
�����}�(hKhh)��}�(hhhM�hKFhKubh�ubh�^/// @param[in] stringDecoding				ValueReceiver which receives all processed DataDictionaries.
�����}�(hKhh)��}�(hhhM�hKGhKubh�ubh�Y/// @param[in] objects						ValueReceiver which receives all processed DataDictionaries.
�����}�(hKhh)��}�(hhhMhKHhKubh�ubh�p/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
�����}�(hKhh)��}�(hhhMmhKIhKubh�ubehfX�  /// ConvertFromJSON parses a json string into DataDictionary representation.
/// @param[in] parserData					JSON formated string to precess.
/// @param[in] flags							See JSONPARSERFLAGS.
/// @param[in] stringDecoding				ValueReceiver which receives all processed DataDictionaries.
/// @param[in] objects						ValueReceiver which receives all processed DataDictionaries.
/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
�hg}�hi�h��jm  �jn  �jo  �Result<void>�jq  �jr  ]�(ju  )��}�(h�const Block<const Char>&�hh�
parserData�����}�(hKhh)��}�(hhhMzhKKhKBubh�ubj  Nj�  �j�  �j�  �ubju  )��}�(h�PARSERFLAGS�hh�flags�����}�(hKhh)��}�(hhhM�hKKhKZubh�ubj  Nj�  �j�  �j�  �ubju  )��}�(h�const StringDecodingRef&�hh�stringDecoding�����}�(hKhh)��}�(hhhM�hKKhKzubh�ubj  Nj�  �j�  �j�  �ubju  )��}�(h�+const ValueReceiver<const DataDictionary&>&�hh�objects�����}�(hKhh)��}�(hhhM�hKKhK�ubh�ubj  Nj�  �j�  �j�  �ubej�  Nj�  �void�h��ubj6  )��}�(hh�
ReadString�����}�(hKhh)��}�(hhhMhKLhKubh�ubhj  h]�h[j  h\j+  h^h�MAXON_FUNCTION�����}�(hKhh)��}�(hhhM�hKLhKubh�ubh/Nh`NhNhaNhbNhcK hd]�hfh	hg}�hi�h��jm  �jn  �jo  �Result<void>�jq  �jr  ]�(ju  )��}�(h�const String&�hh�text�����}�(hKhh)��}�(hhhM.hKLhK7ubh�ubj  Nj�  �j�  �j�  �ubju  )��}�(h�PARSERFLAGS�hh�flags�����}�(hKhh)��}�(hhhM@hKLhKIubh�ubj  Nj�  �j�  �j�  �ubju  )��}�(h�const StringDecodingRef&�hh�stringDecoding�����}�(hKhh)��}�(hhhM`hKLhKiubh�ubj  Nj�  �j�  �j�  �ubju  )��}�(h�+const ValueReceiver<const DataDictionary&>&�hh�objects�����}�(hKhh)��}�(hhhM�hKLhK�ubh�ubj  Nj�  �j�  �j�  �ubej�  Nj�  �void�h��ubj6  )��}�(hh�Write�����}�(hKhh)��}�(hhhM�hKUhKubh�ubhj  h]�h[jD  h\j+  h^h�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKUhKubh�ubh/Nh`NhNhaNhbNhcK hd]�(h�A/// ConvertToJSON converts a data dictionary into a JSON string.
�����}�(hKhh)��}�(hhhMhKOhKubh�ubh�7/// @param[in] object							DataDictionary to convert.
�����}�(hKhh)��}�(hhhMFhKPhKubh�ubh�+/// @param[out] string						Result string.
�����}�(hKhh)��}�(hhhM~hKQhKubh�ubh��/// @param[in] niceFormatting			True to have nice formatting with indents and new lines. False to get compact format (smaller filesize).
�����}�(hKhh)��}�(hhhM�hKRhKubh�ubh�&/// @return												OK on success.
�����}�(hKhh)��}�(hhhM4hKShKubh�ubehfXR  /// ConvertToJSON converts a data dictionary into a JSON string.
/// @param[in] object							DataDictionary to convert.
/// @param[out] string						Result string.
/// @param[in] niceFormatting			True to have nice formatting with indents and new lines. False to get compact format (smaller filesize).
/// @return												OK on success.
�hg}�hi�h��jm  �jn  �jo  �Result<void>�jq  �jr  ]�(ju  )��}�(h�const DataDictionary&�hh�object�����}�(hKhh)��}�(hhhM�hKUhK8ubh�ubj  Nj�  �j�  �j�  �ubju  )��}�(h�String&�hh�string�����}�(hKhh)��}�(hhhM�hKUhKHubh�ubj  Nj�  �j�  �j�  �ubju  )��}�(h�Bool�hh�niceFormatting�����}�(hKhh)��}�(hhhM
hKUhKUubh�ubj  Nj�  �j�  �j�  �ubej�  Nj�  �void�h��ubj6  )��}�(hh�	WriteFile�����}�(hKhh)��}�(hhhMuhK_hKubh�ubhj  h]�h[j�  h\j+  h^h�MAXON_METHOD�����}�(hKhh)��}�(hhhM[hK_hKubh�ubh/Nh`NhNhaNhbNhcK hd]�(h�2/// WriteFile writes a object into a file or url.
�����}�(hKhh)��}�(hhhMyhKXhKubh�ubh�2/// @param[in] out								Url or stream to write.
�����}�(hKhh)��}�(hhhM�hKYhKubh�ubh�8/// @param[in] stringEncoding			String encoding to use.
�����}�(hKhh)��}�(hhhM�hKZhKubh�ubh�*/// @param[in] dict								Data to write.
�����}�(hKhh)��}�(hhhMhK[hKubh�ubh��/// @param[in] niceFormatting			True to have nice formatting with indents and new lines. False to get compact format (smaller filesize).
�����}�(hKhh)��}�(hhhMChK\hKubh�ubh�1/// @return                       OK on success.
�����}�(hKhh)��}�(hhhM�hK]hKubh�ubehfX�  /// WriteFile writes a object into a file or url.
/// @param[in] out								Url or stream to write.
/// @param[in] stringEncoding			String encoding to use.
/// @param[in] dict								Data to write.
/// @param[in] niceFormatting			True to have nice formatting with indents and new lines. False to get compact format (smaller filesize).
/// @return                       OK on success.
�hg}�hi�h��jm  �jn  �jo  �Result<void>�jq  �jr  ]�(ju  )��}�(h�UrlOrOutputStream&&�hh�out�����}�(hKhh)��}�(hhhM�hK_hK:ubh�ubj  Nj�  �j�  �j�  �ubju  )��}�(h�const StringEncodingRef&�hh�stringEncoding�����}�(hKhh)��}�(hhhM�hK_hKXubh�ubj  Nj�  �j�  �j�  �ubju  )��}�(h�const DataDictionary&�hh�dict�����}�(hKhh)��}�(hhhM�hK_hK~ubh�ubj  Nj�  �j�  �j�  �ubju  )��}�(h�Bool�hh�niceFormatting�����}�(hKhh)��}�(hhhM�hK_hK�ubh�ubj  Nj�  �j�  �j�  �ubej�  Nj�  �void�h��ubj6  )��}�(hh�GetFileExtension�����}�(hKhh)��}�(hhhM�hKdhKubh�ubhj  h]�h[j�  h\j+  h^h�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKdhKubh�ubh/Nh`NhNhaNhbNhcK hd]�(h�=/// GetFileExtension gives the file extension of the parser.
�����}�(hKhh)��}�(hhhMRhKbhKubh�ubh�,/// @return the file extension as a string.
�����}�(hKhh)��}�(hhhM�hKchKubh�ubehf�i/// GetFileExtension gives the file extension of the parser.
/// @return the file extension as a string.
�hg}�hi�h��jm  �jn  �jo  �String�jq  �jr  ]�j�  Nj�  Nh��ubeh[j  h\h]h^h�h/Nh`NhNhah�"net.maxon.interface.parser"�����}�(hKhh)��}�(hhhM�hK5hK;ubh�ubhbNhcK hd]�hfh	hg}�hi�h{]��DataDictionaryObjectInterface�h]h	��ah�Kh�Kh��h��	ParserRef�h�]�j  h	��ah��h��h��h��h��h��h��h��h�Nh��h��h�]�h�]�h�]�h�]�h�}�ubh�)��}�(hj  hh<h]�(j6  )��}�(hj;  hj  hj?  h[j;  h\j+  h^jB  h/Nh`NhNhaNhbNhcK hdjF  hfX  /// ConvertFromJWT converts a JWT token into a json DataDictionary. For more details of JWT see https://jwt.io/
/// @param[in] nameOrStream				JSON formated input stream or file url.
/// @param[in] flags							See JWTPARSERFLAGS.
/// @param[in] objects				ValueReceiver which receives all processed DataDictionaries.
/// @param[out] originalToken			[Optional] Returns the original token memory read from the stream.
/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
�hgjl  hi�h��jm  �jn  �jo  jp  jq  �jr  js  j�  Nj�  j�  h��ubj6  )��}�(hj�  hj  hj�  h[j�  h\j+  h^j�  h/Nh`NhNhaNhbNhcK hdj�  hfX�  /// ConvertFromJSON parses a json string into DataDictionary representation.
/// @param[in] parserData					JSON formated string to precess.
/// @param[in] flags							See JSONPARSERFLAGS.
/// @param[in] stringDecoding				ValueReceiver which receives all processed DataDictionaries.
/// @param[in] objects						ValueReceiver which receives all processed DataDictionaries.
/// @return												OK on success. If successful it's guaranteed that at least one DataDictionary was found.
�hgj�  hi�h��jm  �jn  �jo  j�  jq  �jr  j�  j�  Nj�  j  h��ubj6  )��}�(hj  hj  hj  h[j  h\j+  h^j  h/Nh`NhNhaNhbNhcK hdj  hfh	hgj  hi�h��jm  �jn  �jo  j  jq  �jr  j  j�  Nj�  j?  h��ubj6  )��}�(hjD  hj  hjH  h[jD  h\j+  h^jK  h/Nh`NhNhaNhbNhcK hdjO  hfXR  /// ConvertToJSON converts a data dictionary into a JSON string.
/// @param[in] object							DataDictionary to convert.
/// @param[out] string						Result string.
/// @param[in] niceFormatting			True to have nice formatting with indents and new lines. False to get compact format (smaller filesize).
/// @return												OK on success.
�hgjo  hi�h��jm  �jn  �jo  jp  jq  �jr  jq  j�  Nj�  j�  h��ubj6  )��}�(hj�  hj  hj�  h[j�  h\j+  h^j�  h/Nh`NhNhaNhbNhcK hdj�  hfX�  /// WriteFile writes a object into a file or url.
/// @param[in] out								Url or stream to write.
/// @param[in] stringEncoding			String encoding to use.
/// @param[in] dict								Data to write.
/// @param[in] niceFormatting			True to have nice formatting with indents and new lines. False to get compact format (smaller filesize).
/// @return                       OK on success.
�hgj�  hi�h��jm  �jn  �jo  j�  jq  �jr  j�  j�  Nj�  j�  h��ubj6  )��}�(hj�  hj  hj�  h[j�  h\j+  h^j�  h/Nh`NhNhaNhbNhcK hdj�  hf�i/// GetFileExtension gives the file extension of the parser.
/// @return the file extension as a string.
�hgj  hi�h��jm  �jn  �jo  j	  jq  �jr  j
  j�  Nj�  Nh��ubeh[j  h\h]h^h�h/Nh`NhNhaNhbNhcKhdj  hfh	hg}�hi�h{]��9DataDictionaryObjectInterface::ReferenceClassHelper::type�h]h	��ah�Nh�Nh��h�Nh�Nh��h��h��h��h��h��h��h��h�Nh��h��h�]�h�]��source�j  ubh)��}�(hh�ParserClasses�����}�(hKhh)��}�(hhhM'hKhhK"ubh�ubhh<h]�(h �CppDeclaration���)��}�(hh�
JsonParser�����}�(hKhh)��}�(hhhM�hKlhK.ubh�ubhj9  h]�h[jH  h\h]h^h�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�hKlhKubh�ubh/Nh`Nh�ParserClasses::EntryType�ha�&"net.maxon.interface.parserclass.json"�hbNhcK hd]�hfh	hg}�hi�ubjC  )��}�(hh�	JwtParser�����}�(hKhh)��}�(hhhMhKmhK.ubh�ubhj9  h]�h[j[  h\h]h^h�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�hKmhKubh�ubh/Nh`Nh�ParserClasses::EntryType�ha�%"net.maxon.interface.parserclass.jwt"�hbNhcK hd]�hfh	hg}�hi�ubjC  )��}�(hh�	CsvParser�����}�(hKhh)��}�(hhhMohKnhK.ubh�ubhj9  h]�h[jn  h\h]h^h�MAXON_DECLARATION�����}�(hKhh)��}�(hhhMChKnhKubh�ubh/Nh`Nh�ParserClasses::EntryType�ha�%"net.maxon.interface.parserclass.csv"�hbNhcK hd]�hfh	hg}�hi�ubeh[j=  h\h]h^j  h/Nh`Nh�Class<ParserRef>�hah�,"net.maxon.interface.registry.parserclasses"�����}�(hKhh)��}�(hhhM6hKhhK1ubh�ubhbNhcK hd]�hfh	hg}�hi�j  ]�j  hh Nj  �j  �h���j  Kj  Kj  �ubjC  )��}�(hh�ParserBaseClass�����}�(hKhh)��}�(hhhM�hKphK%ubh�ubhh<h]�h[j�  h\h]h^h�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�hKphKubh�ubh/Nh`Nh�Class<ParserRef>�ha�&"net.maxon.interface.parserclass.base"�hbNhcK hd]�hfh	hg}�hi�ubeh[h@h\h]h^j  h/Nh`NhNhaNhbNhcK hd]�hfh	hg}�hi�j  ]�j  hh Nj  �j  �h���j  K j  K j  �ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM hKxhKubh�ububeh[hh\h]h^j  h/Nh`NhNhaNhbNhcK hd]�hfh	hg}�hi�j  ]�j  hh ]�(hh)h0h4h8h<hGh�h�h�h�h�h�j  j'  j>  jU  jl  j�  j�  j�  j�  j�  j�  j  j  j9  jD  jW  jj  j�  j�  ej  �j  �h����hxx1�h<�hxx2�h<�snippets�}�j  K j  K j  ��forwardHeaders���ub.