���      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��MD:\C4DSDK\C4D_MMDTool\sdk_s26\frameworks\cinema.framework\source\c4d_shader.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhM7hKhKubh�ububh �Include���)��}�(h�	ge_math.h�hhh]��quote��"��template�Nubh()��}�(h�
c4d_file.h�hhh]�h-h.h/Nubh()��}�(h�c4d_basetime.h�hhh]�h-h.h/Nubh()��}�(h�ge_autoptr.h�hhh]�h-h.h/Nubh()��}�(h�ge_prepass.h�hhh]�h-h.h/Nubh)��}�(hNhhh]�h h� #ifdef CINEWARE_NAMESPACE_ENABLE�����}�(hK
hh)��}�(hhhM�hKhKubh�ububh)��}�(hNhhh]�h h�CINEWARE_NAMESPACE_BEGIN�����}�(hK
hh)��}�(hhhMhKhKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM$hKhKubh�ububh �Define���)��}�(hh�TEX_TILE�����}�(hKhh)��}�(hhhMnhKhK	ubh�ubhhh]��
simpleName�ha�access��public��kind��#define�h/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]�(h�/// @addtogroup TEX
�����}�(hKhh)��}�(hhhM,hKhKubh�ubh�/// @ingroup group_enumeration
�����}�(hKhh)��}�(hhhM@hKhKubh�ubh�/// @{
�����}�(hKhh)��}�(hhhM_hKhKubh�ube�doc��:/// @addtogroup TEX
/// @ingroup group_enumeration
/// @{
��annotations�}��	anonymous���params�]�ubh\)��}�(hh�
TEX_MIRROR�����}�(hKhh)��}�(hhhM�hKhK	ubh�ubhhh]�hfh�hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�	TEX_ALPHA�����}�(hKhh)��}�(hhhM�hKhK	ubh�ubhhh]�hfh�hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�TEX_BUMP�����}�(hKhh)��}�(hhhM5hKhK	ubh�ubhhh]�hfh�hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�GET_TEX_BUMP_SAMPLE�����}�(hKhh)��}�(hhhM)hK&hK	ubh�ubhhh]�hfh�hghhhihjh/NhkNhNhlNhmNhnK ho]�(h�9/// Extracts the bump sample from @formatParam{texflag}.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�//// @param[in] texflag						The texture flags.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�(/// @return												The bump sample:
�����}�(hKhh)��}�(hhhM'hK hKubh�ubh�///																- 0 Left.
�����}�(hKhh)��}�(hhhMOhK!hKubh�ubh�///																- 1 Right.
�����}�(hKhh)��}�(hhhMlhK"hKubh�ubh�///																- 2 Above.
�����}�(hKhh)��}�(hhhM�hK#hKubh�ubh�///																- 3 Below.
�����}�(hKhh)��}�(hhhM�hK$hKubh�ubeh�X  /// Extracts the bump sample from @formatParam{texflag}.
/// @param[in] texflag						The texture flags.
/// @return												The bump sample:
///																- 0 Left.
///																- 1 Right.
///																- 2 Above.
///																- 3 Below.
�h�}�h��h�]�h�texflag�����}�(hKhh)��}�(hhhM=hK&hKubh�ubaubh\)��}�(hh�GET_TEX_CHANNEL�����}�(hKhh)��}�(hhhM�hK-hK	ubh�ubhhh]�hfh�hghhhihjh/NhkNhNhlNhmNhnK ho]�(h�=/// Extracts the texture channel from @formatParam{texflag}.
�����}�(hKhh)��}�(hhhM�hK)hKubh�ubh�//// @param[in] texflag						The texture flags.
�����}�(hKhh)��}�(hhhM�hK*hKubh�ubh�D/// @return												The texture channel: @enumerateEnum{CHANNEL}
�����}�(hKhh)��}�(hhhM%hK+hKubh�ubeh���/// Extracts the texture channel from @formatParam{texflag}.
/// @param[in] texflag						The texture flags.
/// @return												The texture channel: @enumerateEnum{CHANNEL}
�h�}�h��h�]�h�texflag�����}�(hKhh)��}�(hhhM�hK-hKubh�ubaubh �Function���)��}�(hh�CALC_TEXINFO�����}�(hKhh)��}�(hhhM�hK5hKubh�ubhhh]�hfj  hghhhi�function�h/NhkNhNhlNhmNhnK ho]�(h�8/// Inserts channel information into the texture flags.
�����}�(hKhh)��}�(hhhM[hK0hKubh�ubh�//// @param[in] texflag						The texture flags.
�����}�(hKhh)��}�(hhhM�hK1hKubh�ubh�I/// @param[in] channel						The texture channel: @enumerateEnum{CHANNEL}
�����}�(hKhh)��}�(hhhM�hK2hKubh�ubh�./// @return												The new texture flags.
�����}�(hKhh)��}�(hhhMhK3hKubh�ubeh���/// Inserts channel information into the texture flags.
/// @param[in] texflag						The texture flags.
/// @param[in] channel						The texture channel: @enumerateEnum{CHANNEL}
/// @return												The new texture flags.
�h�}�h���static���explicit���deleted���retType��Int32��const��h�]�(h �	Parameter���)��}�(h�Int32�hh�texflag�����}�(hKhh)��}�(hhhM�hK5hK!ubh�ub�default�N�pack���input���output��ubj?  )��}�(h�Int32�hh�channel�����}�(hKhh)��}�(hhhM�hK5hK0ubh�ubjI  NjJ  �jK  �jL  �ube�
observable�N�result�N�forward��ubj  )��}�(hh�CALC_TEXINFO_BUMP�����}�(hKhh)��}�(hhhMRhKBhKubh�ubhhh]�hfj]  hghhhij  h/NhkNhNhlNhmNhnK ho]�(h�H/// Inserts channel and bump sample information into the texture flags.
�����}�(hKhh)��}�(hhhMX	hK8hKubh�ubh�//// @param[in] texflag						The texture flags.
�����}�(hKhh)��}�(hhhM�	hK9hKubh�ubh�I/// @param[in] channel						The texture channel: @enumerateEnum{CHANNEL}
�����}�(hKhh)��}�(hhhM�	hK:hKubh�ubh�-/// @param[in] sample							The bump sample:
�����}�(hKhh)��}�(hhhM
hK;hKubh�ubh�///																- 0 Left.
�����}�(hKhh)��}�(hhhME
hK<hKubh�ubh�///																- 1 Right.
�����}�(hKhh)��}�(hhhMb
hK=hKubh�ubh�///																- 2 Above.
�����}�(hKhh)��}�(hhhM�
hK>hKubh�ubh�///																- 3 Below.
�����}�(hKhh)��}�(hhhM�
hK?hKubh�ubh�./// @return												The new texture flags.
�����}�(hKhh)��}�(hhhM�
hK@hKubh�ubeh�X�  /// Inserts channel and bump sample information into the texture flags.
/// @param[in] texflag						The texture flags.
/// @param[in] channel						The texture channel: @enumerateEnum{CHANNEL}
/// @param[in] sample							The bump sample:
///																- 0 Left.
///																- 1 Right.
///																- 2 Above.
///																- 3 Below.
/// @return												The new texture flags.
�h�}�h��j7  �j8  �j9  �j:  �Int32�j<  �h�]�(j?  )��}�(h�Int32�hh�texflag�����}�(hKhh)��}�(hhhMjhKBhK&ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�Int32�hh�channel�����}�(hKhh)��}�(hhhMyhKBhK5ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�Int32�hh�sample�����}�(hKhh)��}�(hhhM�hKBhKDubh�ubjI  NjJ  �jK  �jL  �ubejV  NjW  NjX  �ubh �Class���)��}�(hh�CDialog�����}�(hKhh)��}�(hhhM�hKDhKubh�ubhhh]�hfj�  hghhhi�class�h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h���bases�]��	interface�N�refKind�Nj7  ��refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent��jX  ��
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���usings�]��ambiguousCalls�]��	selfCalls�]��methodNames�}�ubj�  )��}�(hh�	HyperFile�����}�(hKhh)��}�(hhhM�hKEhKubh�ubhhh]�hfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�BaseChannel�����}�(hKhh)��}�(hhhM�hKFhKubh�ubhhh]�hfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�BaseDocument�����}�(hKhh)��}�(hhhMhKGhKubh�ubhhh]�hfj  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�
BaseObject�����}�(hKhh)��}�(hhhM$hKHhKubh�ubhhh]�hfj  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�BaseTag�����}�(hKhh)��}�(hhhM6hKIhKubh�ubhhh]�hfj"  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�BaseDraw�����}�(hKhh)��}�(hhhMEhKJhKubh�ubhhh]�hfj2  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�BaseDrawHelp�����}�(hKhh)��}�(hhhMUhKKhKubh�ubhhh]�hfjB  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�
BaseThread�����}�(hKhh)��}�(hhhMihKLhKubh�ubhhh]�hfjR  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�Filename�����}�(hKhh)��}�(hhhM{hKMhKubh�ubhhh]�hfjb  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�String�����}�(hKhh)��}�(hhhM�hKNhKubh�ubhhh]�hfjr  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�BaseView�����}�(hKhh)��}�(hhhM�hKOhKubh�ubhhh]�hfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�BaseContainer�����}�(hKhh)��}�(hhhM�hKPhKubh�ubhhh]�hfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�	Raytracer�����}�(hKhh)��}�(hhhM�hKQhKubh�ubhhh]�hfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�RootTextureString�����}�(hKhh)��}�(hhhM�hKRhKubh�ubhhh]�hfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�TexEntry�����}�(hKhh)��}�(hhhM�hKShKubh�ubhhh]�hfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�RayObj�����}�(hKhh)��}�(hhhM�hKThKubh�ubhhh]�hfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�RayLight�����}�(hKhh)��}�(hhhM	hKUhKubh�ubhhh]�hfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�	RayObject�����}�(hKhh)��}�(hhhMhKVhKubh�ubhhh]�hfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�
VolumeData�����}�(hKhh)��}�(hhhM,hKWhKubh�ubhhh]�hfj  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubh\)��}�(hh�MAX_MATERIALCHANNELS�����}�(hKhh)��}�(hhhMxhKZhK	ubh�ubhhh]�hfj  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�7/// The maximum number of channels in a @C4D material.
�����}�(hKhh)��}�(hhhM9hKYhKubh�ubah��7/// The maximum number of channels in a @C4D material.
�h�}�h��h�]�ubh\)��}�(hh�CHANNEL_COLOR�����}�(hKhh)��}�(hhhM�hK_hK	ubh�ubhhh]�hfj%  hghhhihjh/NhkNhNhlNhmNhnK ho]�(h�/// @addtogroup CHANNEL
�����}�(hKhh)��}�(hhhM�hK\hKubh�ubh�/// @ingroup group_enumeration
�����}�(hKhh)��}�(hhhM�hK]hKubh�ubh�/// @{
�����}�(hKhh)��}�(hhhM�hK^hKubh�ubeh��>/// @addtogroup CHANNEL
/// @ingroup group_enumeration
/// @{
�h�}�h��h�]�ubh\)��}�(hh�CHANNEL_LUMINANCE�����}�(hKhh)��}�(hhhMhK`hK	ubh�ubhhh]�hfjD  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�CHANNEL_TRANSPARENCY�����}�(hKhh)��}�(hhhMghKahK	ubh�ubhhh]�hfjP  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�CHANNEL_REFLECTION�����}�(hKhh)��}�(hhhM�hKbhK	ubh�ubhhh]�hfj\  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�CHANNEL_ENVIRONMENT�����}�(hKhh)��}�(hhhMhKchK	ubh�ubhhh]�hfjh  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�CHANNEL_FOG�����}�(hKhh)��}�(hhhMPhKdhK	ubh�ubhhh]�hfjt  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�CHANNEL_BUMP�����}�(hKhh)��}�(hhhM�hKehK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�CHANNEL_ALPHA�����}�(hKhh)��}�(hhhM�hKfhK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�CHANNEL_SPECULAR�����}�(hKhh)��}�(hhhM hKghK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�CHANNEL_SPECULARCOLOR�����}�(hKhh)��}�(hhhMkhKhhK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�CHANNEL_GLOW�����}�(hKhh)��}�(hhhM�hKihK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�CHANNEL_DISPLACEMENT�����}�(hKhh)��}�(hhhMhKjhK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�CHANNEL_DIFFUSION�����}�(hKhh)��}�(hhhMUhKkhK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�CHANNEL_NORMAL�����}�(hKhh)��}�(hhhM�hKlhK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�CHANNEL_ANY�����}�(hKhh)��}�(hhhM�hKmhK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_COLOR_EX�����}�(hKhh)��}�(hhhMthKshK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�(h�/// @addtogroup BASECHANNEL
�����}�(hKhh)��}�(hhhM*hKphKubh�ubh�/// @ingroup group_containerid
�����}�(hKhh)��}�(hhhMFhKqhKubh�ubh�/// @{
�����}�(hKhh)��}�(hhhMehKrhKubh�ubeh��B/// @addtogroup BASECHANNEL
/// @ingroup group_containerid
/// @{
�h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_BRIGHTNESS_EX�����}�(hKhh)��}�(hhhM�hKthK	ubh�ubhhh]�hfj  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_MIXMODE_EX�����}�(hKhh)��}�(hhhMhKuhK	ubh�ubhhh]�hfj  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_MIXSTRENGTH_EX�����}�(hKhh)��}�(hhhMHhKvhK	ubh�ubhhh]�hfj#  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_TEXTURE�����}�(hKhh)��}�(hhhM�hKxhK	ubh�ubhhh]�hfj/  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_BLUR_OFFSET�����}�(hKhh)��}�(hhhM�hKyhK	ubh�ubhhh]�hfj;  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_BLUR_STRENGTH�����}�(hKhh)��}�(hhhM@hKzhK	ubh�ubhhh]�hfjG  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_INTERPOLATION�����}�(hKhh)��}�(hhhM�hK{hK	ubh�ubhhh]�hfjS  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_TIME_FROM�����}�(hKhh)��}�(hhhM�hK|hK	ubh�ubhhh]�hfj_  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_TIME_TO�����}�(hKhh)��}�(hhhMDhK}hK	ubh�ubhhh]�hfjk  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_TIME_FPS�����}�(hKhh)��}�(hhhM�hK~hK	ubh�ubhhh]�hfjw  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_TIME_MODE�����}�(hKhh)��}�(hhhM�hKhK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_TIME_TIMING�����}�(hKhh)��}�(hhhM'hK�hK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_TIME_START�����}�(hKhh)��}�(hhhM�hK�hK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_TIME_END�����}�(hKhh)��}�(hhhM�hK�hK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_TIME_LOOPS�����}�(hKhh)��}�(hhhMhK�hK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_SHADERID�����}�(hKhh)��}�(hhhMRhK�hK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�BASECHANNEL_SUGGESTEDFOLDER�����}�(hKhh)��}�(hhhM�hK�hK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh �Enum���)��}�(hh�INITRENDERFLAG�����}�(hKhh)��}�(hhhMlhK�hKubh�ubhhh]�(h �	EnumValue���)��}�(hh�NONE�����}�(hKhh)��}�(hhhM~hK�hKubh�ubhj�  h]�hfj�  hghhhi�	enumvalue�h/NhkNhNhlNhmNhnK ho]�h�///< No flags.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubah��///< No flags.
�h�}�h���value��0�ubj�  )��}�(hh�TEXTURES�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhj�  h]�hfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�///< Use textures.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubah��///< Use textures.
�h�}�h��j�  �(1<<0)�ubj�  )��}�(hh�PAINTERNOMIP�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhj�  h]�hfj  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�///< Disable MIP for painting.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubah��///< Disable MIP for painting.
�h�}�h��j�  �(1<<1)�ubj�  )��}�(hh�NOMIP�����}�(hKhh)��}�(hhhMhK�hKubh�ubhj�  h]�hfj  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�///< Disable MIP.
�����}�(hKhh)��}�(hhhM)hK�hKubh�ubah��///< Disable MIP.
�h�}�h��j�  �(1<<2)�ubj�  )��}�(hh�PREVIEWRENDER�����}�(hKhh)��}�(hhhM<hK�hKubh�ubhj�  h]�hfj2  hghhhij�  h/NhkNhNhlNhmNhnK ho]�(h�///< Preview render.\n
�����}�(hKhh)��}�(hhhMZhK�hK ubh�ubh��///< @note	The container of the preview rendered document contains the path to the original document in ID ::DOCUMENT_SECONDARYPATH:
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubeh���///< Preview render.\n
///< @note	The container of the preview rendered document contains the path to the original document in ID ::DOCUMENT_SECONDARYPATH:
�h�}�h��j�  �(1<<3)�ubj�  )��}�(hh�IRR�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhj�  h]�hfjK  hghhhij�  h/NhkNhNhlNhmNhnK ho]�(h�
/// @code
�����}�(hKhh)��}�(hhhMhK�hKubh�ubh�3/// if (irs.flags & INITRENDERFLAG::PREVIEWRENDER)
�����}�(hKhh)��}�(hhhM6hK�hKubh�ubh�/// {
�����}�(hKhh)��}�(hhhM{hK�hKubh�ubh�0/// 	if (irs.doc && irs.doc->GetDataInstance())
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�/// 	{
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�e/// 		const Filename originalPath = irs.doc->GetDataInstance()->GetFilename(DOCUMENT_SECONDARYPATH);
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�/// 	}
�����}�(hKhh)��}�(hhhMehK�hKubh�ubh�/// }
�����}�(hKhh)��}�(hhhM~hK�hKubh�ubh�/// @endcode
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh� ///< Interactive region render.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubeh�X  /// @code
/// if (irs.flags & INITRENDERFLAG::PREVIEWRENDER)
/// {
/// 	if (irs.doc && irs.doc->GetDataInstance())
/// 	{
/// 		const Filename originalPath = irs.doc->GetDataInstance()->GetFilename(DOCUMENT_SECONDARYPATH);
/// 	}
/// }
/// @endcode
///< Interactive region render.
�h�}�h��j�  �(1<<4)�ubehfj�  hghhhi�enum�h/NhkNhNhlNhmNhnK ho]�(h�/// @addtogroup INITRENDERFLAG
�����}�(hKhh)��}�(hhhMhK�hKubh�ubh�/// @ingroup group_enumeration
�����}�(hKhh)��}�(hhhM;hK�hKubh�ubh�/// @{
�����}�(hKhh)��}�(hhhMZhK�hKubh�ubeh��E/// @addtogroup INITRENDERFLAG
/// @ingroup group_enumeration
/// @{
�h�}�h��j�  ]��scoped���
registered���flags��h X}  enum class INITRENDERFLAG
{
	NONE							= 0,						///< No flags.
	TEXTURES					= (1 << 0),			///< Use textures.
	PAINTERNOMIP			= (1 << 1),			///< Disable MIP for painting.
	NOMIP							= (1 << 2),			///< Disable MIP.
	PREVIEWRENDER			= (1 << 3),			///< Preview render.\n
																		///< @note	The container of the preview rendered document contains the path to the original document in ID ::DOCUMENT_SECONDARYPATH:
																		/// @code
																		/// if (irs.flags & INITRENDERFLAG::PREVIEWRENDER)
																		/// {
																		/// 	if (irs.doc && irs.doc->GetDataInstance())
																		/// 	{
																		/// 		const Filename originalPath = irs.doc->GetDataInstance()->GetFilename(DOCUMENT_SECONDARYPATH);
																		/// 	}
																		/// }
																		/// @endcode
	IRR								= (1 << 4)			///< Interactive region render.
} �hK��early��ubj  )��}�(hh�TransformColor�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhh]�hfj�  hghhhij  h/NhkNhNhlNhmNhnK ho]�(h�:/// Transforms a color from one color profile to another.
�����}�(hKhh)��}�(hhhMchK�hKubh�ubh�3/// @param[in] input							The color to transform.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�l/// @param[in] colortransformation	The color space transformation: @enumerateEnum{COLORSPACETRANSFORMATION}
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�./// @return												The transformed color.
�����}�(hKhh)��}�(hhhM<hK�hKubh�ubeh�X  /// Transforms a color from one color profile to another.
/// @param[in] input							The color to transform.
/// @param[in] colortransformation	The color space transformation: @enumerateEnum{COLORSPACETRANSFORMATION}
/// @return												The transformed color.
�h�}�h��j7  �j8  �j9  �j:  �Vector�j<  �h�]�(j?  )��}�(h�const Vector&�hh�input�����}�(hKhh)��}�(hhhM�hK�hK,ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�COLORSPACETRANSFORMATION�hh�colortransformation�����}�(hKhh)��}�(hhhMhK�hKLubh�ubjI  NjJ  �jK  �jL  �ubejV  NjW  NjX  �ubj  )��}�(hh�TransformColor�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhhh]�hfj�  hghhhij  h/NhkNhNhlNhmNhnK ho]�(h�:/// Transforms a color from one color profile to another.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�3/// @param[in] input							The color to transform.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�l/// @param[in] colortransformation	The color space transformation: @enumerateEnum{COLORSPACETRANSFORMATION}
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�./// @return												The transformed color.
�����}�(hKhh)��}�(hhhM[hK�hKubh�ubeh�X  /// Transforms a color from one color profile to another.
/// @param[in] input							The color to transform.
/// @param[in] colortransformation	The color space transformation: @enumerateEnum{COLORSPACETRANSFORMATION}
/// @return												The transformed color.
�h�}�h��j7  �j8  �j9  �j:  �maxon::Color�j<  �h�]�(j?  )��}�(h�const maxon::Color&�hh�input�����}�(hKhh)��}�(hhhM hK�hK8ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�COLORSPACETRANSFORMATION�hh�colortransformation�����}�(hKhh)��}�(hhhM; hK�hKXubh�ubjI  NjJ  �jK  �jL  �ubejV  NjW  NjX  �ubj�  )��}�(hh�OcioConverter�����}�(hKhh)��}�(hhhMi hK�hKubh�ubhhh]�(j  )��}�(h�constructor�hj  h]�hfj'  hgh�private�����}�(hKhh)��}�(hhhMy hK�hKubh�ubhij'  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j7  �j8  �j9  �j:  �void�j<  �h�]�jV  NjW  NjX  �ubj  )��}�(hh�Init�����}�(hKhh)��}�(hhhM!hK�hK'ubh�ubhj  h]�hfj7  hgh�public�����}�(hKhh)��}�(hhhM� hK�hKubh�ubhij  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j7  �j8  �j9  �j:  �maxon::Result<OcioConverter*>�j<  �h�]�(j?  )��}�(h�const BaseDocument*�hh�doc�����}�(hKhh)��}�(hhhM%!hK�hK@ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�Int32�hh�overrideViewTransform�����}�(hKhh)��}�(hhhM0!hK�hKKubh�ubjI  �-1�jJ  �jK  �jL  �ubejV  NjW  �OcioConverter*�jX  �ubj  )��}�(hh�TransformColor�����}�(hKhh)��}�(hhhM�!hK�hKubh�ubhj  h]�hfj^  hgj>  hij  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j7  �j8  �j9  �j:  �Vector64�j<  �h�]�(j?  )��}�(h�const Vector64&�hh�v�����}�(hKhh)��}�(hhhM�!hK�hK*ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�COLORSPACETRANSFORMATION�hh�colortransformation�����}�(hKhh)��}�(hhhM�!hK�hKFubh�ubjI  NjJ  �jK  �jL  �ubejV  NjW  NjX  �ubj  )��}�(hh�TransformColor�����}�(hKhh)��}�(hhhMM"hK�hKubh�ubhj  h]�hfj}  hgj>  hij  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j7  �j8  �j9  �j:  �Vector32�j<  �h�]�(j?  )��}�(h�const Vector32&�hh�v�����}�(hKhh)��}�(hhhMl"hK�hK*ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�COLORSPACETRANSFORMATION�hh�colortransformation�����}�(hKhh)��}�(hhhM�"hK�hKFubh�ubjI  NjJ  �jK  �jL  �ubejV  NjW  NjX  �ubj  )��}�(hh�GetConverter�����}�(hKhh)��}�(hhhM�"hK�hKubh�ubhj  h]�hfj�  hgj>  hij  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j7  �j8  �j9  �j:  �void�j<  �h�]�(j?  )��}�(h�COLORSPACETRANSFORMATION�hh�colortransformation�����}�(hKhh)��}�(hhhM#hK�hK-ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�maxon::ColorProfileConvert&�hh�	converter�����}�(hKhh)��}�(hhhMN#hK�hK^ubh�ubjI  NjJ  �jK  �jL  �ubejV  NjW  NjX  �ubehfj   hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�/// @markPrivate
�����}�(hKhh)��}�(hhhMR hK�hKubh�ubah��/// @markPrivate
�h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�InitRenderStruct�����}�(hKhh)��}�(hhhMD%hK�hKubh�ubhhh]�(j  )��}�(hj'  hj�  h]�hfj'  hgh�public�����}�(hKhh)��}�(hhhMW%hK�hKubh�ubhij'  h/NhkNhNhlNhmNhnK ho]�h�/// Default constructor.
�����}�(hKhh)��}�(hhhM�%hK�hKubh�ubah��/// Default constructor.
�h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�jV  NjW  NjX  �ubj  )��}�(hj'  hj�  h]�hfj'  hgj�  hij'  h/NhkNhNhlNhmNhnK ho]�(h�>/// Creates the structure accordingly to the passed document.
�����}�(hKhh)��}�(hhhM�'hK�hKubh�ubh�b/// @param[in] t_doc							The document to initialize the structure. @callerOwnsPointed{document}
�����}�(hKhh)��}�(hhhM�'hK�hKubh�ubeh���/// Creates the structure accordingly to the passed document.
/// @param[in] t_doc							The document to initialize the structure. @callerOwnsPointed{document}
�h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�(j?  )��}�(h�BaseDocument*�hh�t_doc�����}�(hKhh)��}�(hhhM�(hK�hK*ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�Int32�hh�overrideViewTransform�����}�(hKhh)��}�(hhhM�(hK�hK7ubh�ubjI  �-1�jJ  �jK  �jL  �ubejV  NjW  NjX  �ubj  )��}�(hh�Init�����}�(hKhh)��}�(hhhM-+hK�hKubh�ubhj�  h]�hfj  hgj�  hij  h/NhkNhNhlNhmNhnK ho]�(h�B/// Initializes the structure accordingly to the passed document.
�����}�(hKhh)��}�(hhhM�)hK�hKubh�ubh�b/// @param[in] t_doc							The document to initialize the structure. @callerOwnsPointed{document}
�����}�(hKhh)��}�(hhhM�)hK�hKubh�ubh��/// @param[in] overrideViewTransform	Index within the viewtransform array to override the view transform. Ignored, if the value is not a valid index.
�����}�(hKhh)��}�(hhhM5*hK�hKubh�ubeh�X:  /// Initializes the structure accordingly to the passed document.
/// @param[in] t_doc							The document to initialize the structure. @callerOwnsPointed{document}
/// @param[in] overrideViewTransform	Index within the viewtransform array to override the view transform. Ignored, if the value is not a valid index.
�h�}�h��j7  �j8  �j9  �j:  �void�j<  �h�]�(j?  )��}�(h�BaseDocument*�hh�t_doc�����}�(hKhh)��}�(hhhM@+hK�hKubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�Int32�hh�overrideViewTransform�����}�(hKhh)��}�(hhhMM+hK�hK'ubh�ubjI  �-1�jJ  �jK  �jL  �ubejV  NjW  NjX  �ubh �Variable���)��}�(hh�version�����}�(hKhh)��}�(hhhM�+hK�hKubh�ubhj�  h]�hfj@  hgh�private�����}�(hKhh)��}�(hhhMk+hK�hKubh�ubhi�variable�h/NhkNh�UInt32�hlNhmNhnK ho]�h�^///< The version of this structure in the upper 8 bits, version of @C4D in the lower 24 bits.
�����}�(hKhh)��}�(hhhM�+hK�hK!ubh�ubah��^///< The version of this structure in the upper 8 bits, version of @C4D in the lower 24 bits.
�h�}�h��j7  �ubj;  )��}�(hh�time�����}�(hKhh)��}�(hhhM	,hK�hKubh�ubhj�  h]�hfjZ  hgh�public�����}�(hKhh)��}�(hhhM�+hK�hKubh�ubhijK  h/NhkNh�BaseTime�hlNhmNhnK ho]�h�///< The current time.
�����}�(hKhh)��}�(hhhM,hK�hK!ubh�ubah��///< The current time.
�h�}�h��j7  �ubj;  )��}�(hh�fps�����}�(hKhh)��}�(hhhM?,hK�hKubh�ubhj�  h]�hfjs  hgja  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�///< The framerate.
�����}�(hKhh)��}�(hhhMO,hK�hKubh�ubah��///< The framerate.
�h�}�h��j7  �ubj;  )��}�(hh�docpath�����}�(hKhh)��}�(hhhMr,hK�hKubh�ubhj�  h]�hfj�  hgja  hijK  h/NhkNh�Filename�hlNhmNhnK ho]�h� ///< The path for the document.
�����}�(hKhh)��}�(hhhM�,hK�hK"ubh�ubah�� ///< The path for the document.
�h�}�h��j7  �ubj;  )��}�(hh�matname�����}�(hKhh)��}�(hhhM�,hK�hKubh�ubhj�  h]�hfj�  hgja  hijK  h/NhkNh�String*�hlNhmNhnK ho]�h�///< The material name.
�����}�(hKhh)��}�(hhhM�,hK�hK"ubh�ubah��///< The material name.
�h�}�h��j7  �ubj;  )��}�(hh�	errorlist�����}�(hKhh)��}�(hhhM�,hM hKubh�ubhj�  h]�hfj�  hgja  hijK  h/NhkNh�RootTextureString*�hlNhmNhnK ho]�h�J///< A private error list. Can be @formatConstant{nullptr}, always check.
�����}�(hKhh)��}�(hhhM-hM hK(ubh�ubah��J///< A private error list. Can be @formatConstant{nullptr}, always check.
�h�}�h��j7  �ubj;  )��}�(hh�vd�����}�(hKhh)��}�(hhhM_-hMhKubh�ubhj�  h]�hfj�  hgja  hijK  h/NhkNh�VolumeData*�hlNhmNhnK ho]�(h�G///< The volume data. Can be @formatConstant{nullptr}, always check.\n
�����}�(hKhh)��}�(hhhMo-hMhK"ubh�ubh��///< @note	When initializing an InitRenderStruct, if the following line is missing, @C4D assumes that there will be only one render thread.\n
�����}�(hKhh)��}�(hhhM�-hMhKubh�ubh��///<				(Without VolumeData no multi-threaded calculation can be done.). Access to VolumeData::Sample() will then crash or overwrite memory.\n
�����}�(hKhh)��}�(hhhMv.hMhKubh�ubh�;///<				Here is a safe initialization of @link vd@endlink:
�����}�(hKhh)��}�(hhhM/hMhKubh�ubh�///<				@code
�����}�(hKhh)��}�(hhhMr/hMhKubh�ubeh�X�  ///< The volume data. Can be @formatConstant{nullptr}, always check.\n
///< @note	When initializing an InitRenderStruct, if the following line is missing, @C4D assumes that there will be only one render thread.\n
///<				(Without VolumeData no multi-threaded calculation can be done.). Access to VolumeData::Sample() will then crash or overwrite memory.\n
///<				Here is a safe initialization of @link vd@endlink:
///<				@code
�h�}�h��j7  �ubj;  )��}�(hh�doc�����}�(hKhh)��}�(hhhM�1hM
hKubh�ubhj�  h]�hfj�  hgja  hijK  h/NhkNh�BaseDocument*�hlNhmNhnK ho]�h�L///< The document to render. Can be @formatConstant{nullptr}, always check.
�����}�(hKhh)��}�(hhhM�1hM
hK#ubh�ubah��L///< The document to render. Can be @formatConstant{nullptr}, always check.
�h�}�h��j7  �ubj;  )��}�(hh�thread�����}�(hKhh)��}�(hhhM2hMhKubh�ubhj�  h]�hfj�  hgja  hijK  h/NhkNh�BaseThread*�hlNhmNhnK ho]�h�N///< The current thread or @formatConstant{nullptr} for the main @C4D thread.
�����}�(hKhh)��}�(hhhM 2hMhK$ubh�ubah��N///< The current thread or @formatConstant{nullptr} for the main @C4D thread.
�h�}�h��j7  �ubj;  )��}�(hh�flags�����}�(hKhh)��}�(hhhM�2hMhKubh�ubhj�  h]�hfj  hgja  hijK  h/NhkNh�INITRENDERFLAG�hlNhmNhnK ho]�h�////< The flags; @enumerateEnum{INITRENDERFLAG}
�����}�(hKhh)��}�(hhhM�2hMhK$ubh�ubah��////< The flags; @enumerateEnum{INITRENDERFLAG}
�h�}�h��j7  �ubj;  )��}�(hh�linear_workflow�����}�(hKhh)��}�(hhhM�2hMhKubh�ubhj�  h]�hfj#  hgja  hijK  h/NhkNh�Bool�hlNhmNhnK ho]�h�'///< Linear workflow enabled/disabled.
�����}�(hKhh)��}�(hhhM�2hMhK$ubh�ubah��'///< Linear workflow enabled/disabled.
�h�}�h��j7  �ubj;  )��}�(hh�document_colorprofile�����}�(hKhh)��}�(hhhM3hMhKubh�ubhj�  h]�hfj6  hgja  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�G///< The document color profile: @enumerateEnum{DOCUMENT_COLORPROFILE}
�����}�(hKhh)��}�(hhhM23hMhK(ubh�ubah��G///< The document color profile: @enumerateEnum{DOCUMENT_COLORPROFILE}
�h�}�h��j7  �ubj;  )��}�(hh�ocioConverter�����}�(hKhh)��}�(hhhM�3hMhK"ubh�ubhj�  h]�hfjI  hgja  hijK  h/NhkNh�maxon::StrongRef<OcioConverter>�hlNhmNhnK ho]�h�!///< @markPrivate OCIO converter
�����}�(hKhh)��}�(hhhM�3hMhK1ubh�ubah��!///< @markPrivate OCIO converter
�h�}�h��j7  �ubj  )��}�(hh�GetC4DVersion�����}�(hKhh)��}�(hhhM�4hMhK%ubh�ubhj�  h]�hfj\  hgja  hij  h/NhkNhNhlNhmNhnK ho]�(h�#/// Gets the current @C4D version.
�����}�(hKhh)��}�(hhhM*4hMhKubh�ubh�(/// @return												The C4D version.
�����}�(hKhh)��}�(hhhMN4hMhKubh�ubeh��K/// Gets the current @C4D version.
/// @return												The C4D version.
�h�}�h��j7  �j8  �j9  �j:  �Int32�j<  �h�]�jV  NjW  NjX  �ubj  )��}�(hh�GetStructureVersion�����}�(hKhh)��}�(hhhMs6hMhK%ubh�ubhj�  h]�hfjv  hgja  hij  h/NhkNhNhlNhmNhnK ho]�(h�(/// Gets the version of this structure.
�����}�(hKhh)��}�(hhhM�5hMhKubh�ubh�6/// @return												The version of this structure.
�����}�(hKhh)��}�(hhhM�5hMhKubh�ubeh��^/// Gets the version of this structure.
/// @return												The version of this structure.
�h�}�h��j7  �j8  �j9  �j:  �Int32�j<  �h�]�jV  NjW  NjX  �ubj  )��}�(hh�GetThreadCount�����}�(hKhh)��}�(hhhM�7hM#hKubh�ubhj�  h]�hfj�  hgja  hij  h/NhkNhNhlNhmNhnK ho]�(h�,/// Retrieves the number of render threads.
�����}�(hKhh)��}�(hhhM7hM hKubh�ubh�5/// @return												The number of render threads.
�����}�(hKhh)��}�(hhhMF7hM!hKubh�ubeh��a/// Retrieves the number of render threads.
/// @return												The number of render threads.
�h�}�h��j7  �j8  �j9  �j:  �Int32�j<  �h�]�jV  NjW  NjX  �ubj  )��}�(hh�TransformColor�����}�(hKhh)��}�(hhhM�9hM*hK	ubh�ubhj�  h]�hfj�  hgja  hij  h/NhkNhNhlNhmNhnK ho]�(h�}/// If linear workflow is enabled the passed color is transformed into the color profile specified by document_colorprofile.
�����}�(hKhh)��}�(hhhMT8hM&hKubh�ubh�3/// @param[in] input							The color to transform.
�����}�(hKhh)��}�(hhhM�8hM'hKubh�ubh�./// @return												The transformed color.
�����}�(hKhh)��}�(hhhM9hM(hKubh�ubeh���/// If linear workflow is enabled the passed color is transformed into the color profile specified by document_colorprofile.
/// @param[in] input							The color to transform.
/// @return												The transformed color.
�h�}�h��j7  �j8  �j9  �j:  �Vector�j<  �h�]�j?  )��}�(h�const Vector&�hh�input�����}�(hKhh)��}�(hhhM�9hM*hK&ubh�ubjI  NjJ  �jK  �jL  �ubajV  NjW  NjX  �ubehfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�(h�o/// The InitRenderStruct is usually filled by @C4D and then passed to the shader or channel @c InitRender().\n
�����}�(hKhh)��}�(hhhM$hK�hKubh�ubh�e/// However to evaluate a BaseChannel for own purposes then create an InitRenderStruct on the stack.
�����}�(hKhh)��}�(hhhM~$hK�hKubh�ubeh���/// The InitRenderStruct is usually filled by @C4D and then passed to the shader or channel @c InitRender().\n
/// However to evaluate a BaseChannel for own purposes then create an InitRenderStruct on the stack.
�h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�RayIllumination�����}�(hKhh)��}�(hhhM?hMFhKubh�ubhhh]�(j  )��}�(hj'  hj�  h]�hfj'  hghhhij'  h/NhkNhNhlNhmNhnK ho]�(h�/// Default constructor.
�����}�(hKhh)��}�(hhhM�?hMIhKubh�ubh�/// @since R17.032
�����}�(hKhh)��}�(hhhM�?hMJhKubh�ubeh��,/// Default constructor.
/// @since R17.032
�h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�jV  NjW  NjX  �ubj;  )��}�(hh�cs_sampleradius�����}�(hKhh)��}�(hhhMKChMghKubh�ubhj�  h]�hfj	  hghhhijK  h/NhkNh�Float�hlNhmNhnK ho]�h�///< Caustics sample radius.
�����}�(hKhh)��}�(hhhMaChMghKubh�ubah��///< Caustics sample radius.
�h�}�h��j7  �ubj;  )��}�(hh�cs_accuracy�����}�(hKhh)��}�(hhhM�ChMhhKubh�ubhj�  h]�hfj	  hghhhijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�///< Caustics accuracy.
�����}�(hKhh)��}�(hhhM�ChMhhKubh�ubah��///< Caustics accuracy.
�h�}�h��j7  �ubehfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�,/// Illumination information for materials.
�����}�(hKhh)��}�(hhhM�>hMDhKubh�ubah��,/// Illumination information for materials.
�h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubh\)��}�(hh�SIDE_FRONT_AND_BACK�����}�(hKhh)��}�(hhhM"FhMzhK	ubh�ubhhh]�hfj7	  hghhhihjh/NhkNhNhlNhmNhnK ho]�(h�/// @addtogroup SIDE
�����}�(hKhh)��}�(hhhM�EhMvhKubh�ubh�/// @ingroup group_enumeration
�����}�(hKhh)��}�(hhhM�EhMwhKubh�ubh�/// @{
�����}�(hKhh)��}�(hhhM�EhMxhKubh�ubh�)/// See @C4D manual for more information
�����}�(hKhh)��}�(hhhM�EhMyhKubh�ubeh��d/// @addtogroup SIDE
/// @ingroup group_enumeration
/// @{
/// See @C4D manual for more information
�h�}�h��h�]�ubh\)��}�(hh�
SIDE_FRONT�����}�(hKhh)��}�(hhhMeFhM{hK	ubh�ubhhh]�hfj\	  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubh\)��}�(hh�	SIDE_BACK�����}�(hKhh)��}�(hhhM�FhM|hK	ubh�ubhhh]�hfjh	  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubj�  )��}�(hh�TexData�����}�(hKhh)��}�(hhhMfYhMDhKubh�ubhhh]�(j  )��}�(hj'  hjp	  h]�hfj'  hgh�private�����}�(hKhh)��}�(hhhMpYhMFhKubh�ubhij'  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�jV  NjW  NjX  �ubj;  )��}�(hh�texflag�����}�(hKhh)��}�(hhhM�ZhMNhK
ubh�ubhjp	  h]�hfj�	  hgh�public�����}�(hKhh)��}�(hhhM�YhMJhKubh�ubhijK  h/NhkNh�Char�hlNhmNhnK ho]�h�,///< The texture flags: @enumerateEnum{TEX}
�����}�(hKhh)��}�(hhhM�ZhMNhKubh�ubah��,///< The texture flags: @enumerateEnum{TEX}
�h�}�h��j7  �ubj;  )��}�(hh�restrict�����}�(hKhh)��}�(hhhM�[hMRhKubh�ubhjp	  h]�hfj�	  hgj�	  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�(h�\///< This is either @em 0 for no restriction or the index to a restriction in a RayObject\n
�����}�(hKhh)��}�(hhhM�[hMRhKubh�ubh�j///< To check if global polygon @c id applies to TexData @c tex using VolumeData @c sd use the following:
�����}�(hKhh)��}�(hhhMJ\hMShKubh�ubeh���///< This is either @em 0 for no restriction or the index to a restriction in a RayObject\n
///< To check if global polygon @c id applies to TexData @c tex using VolumeData @c sd use the following:
�h�}�h��j7  �ubj;  )��}�(hh�mp�����}�(hKhh)��}�(hhhM^ahMjhKubh�ubhjp	  h]�hfj�	  hgj�	  hijK  h/NhkNh�GeListNode*�hlNhmNhnK ho]�(h�///< The material.
�����}�(hKhh)��}�(hhhMiahMjhKubh�ubh�N///< @note Make sure to cast this to the right material type before using it.
�����}�(hKhh)��}�(hhhM�ahMkhKubh�ubeh��a///< The material.
///< @note Make sure to cast this to the right material type before using it.
�h�}�h��j7  �ubj;  )��}�(hh�uvwind�����}�(hKhh)��}�(hhhM�ahMlhKubh�ubhjp	  h]�hfj�	  hgj�	  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�<///< The uvw index, access is through VolumeData::GetUVW().
�����}�(hKhh)��}�(hhhM�ahMlhKubh�ubah��<///< The uvw index, access is through VolumeData::GetUVW().
�h�}�h��j7  �ubj;  )��}�(hh�camera�����}�(hKhh)��}�(hhhM9bhMmhKubh�ubhjp	  h]�hfj�	  hgj�	  hijK  h/NhkNh�	BaseView*�hlNhmNhnK ho]�h�///< The current view.
�����}�(hKhh)��}�(hhhMFbhMmhKubh�ubah��///< The current view.
�h�}�h��j7  �ubj;  )��}�(hh�uvbump�����}�(hKhh)��}�(hhhMfbhMnhK
ubh�ubhjp	  h]�hfj�	  hgj�	  hijK  h/NhkNh�Char�hlNhmNhnK ho]�h�B///< The direct boolean representation of @ref TEXTURETAG_UVBUMP.
�����}�(hKhh)��}�(hhhMsbhMnhKubh�ubah��B///< The direct boolean representation of @ref TEXTURETAG_UVBUMP.
�h�}�h��j7  �ubj;  )��}�(hh�link�����}�(hKhh)��}�(hhhM�bhMohKubh�ubhjp	  h]�hfj
  hgj�	  hijK  h/NhkNh�BaseTag*�hlNhmNhnK ho]�h�"///< The originating texture tag.
�����}�(hKhh)��}�(hhhM�bhMohKubh�ubah��"///< The originating texture tag.
�h�}�h��j7  �ubj;  )��}�(hh�parallaxUVW�����}�(hKhh)��}�(hhhM�chMrhK
ubh�ubhjp	  h]�hfj 
  hgj�	  hijK  h/NhkNh�Bool�hlNhmNhnK ho]�h�_///< @trueIfOtherwiseFalse{the UVW coordinates are changed by Parallax Mapping} @since R19.SP2
�����}�(hKhh)��}�(hhhM�chMrhKubh�ubah��_///< @trueIfOtherwiseFalse{the UVW coordinates are changed by Parallax Mapping} @since R19.SP2
�h�}�h��j7  �ubj  )��}�(hh�Alloc�����}�(hKhh)��}�(hhhM ehMxhKubh�ubhjp	  h]�hfj3
  hgj�	  hij  h/NhkNhNhlNhmNhnK ho]�(h�/// @allocatesA{texture data}
�����}�(hKhh)��}�(hhhMbdhMuhKubh�ubh�2/// @return												@allocReturn{texture data}
�����}�(hKhh)��}�(hhhM�dhMvhKubh�ubeh��P/// @allocatesA{texture data}
/// @return												@allocReturn{texture data}
�h�}�h��j7  �j8  �j9  �j:  �TexData*�j<  �h�]�jV  NjW  NjX  �ubj  )��}�(hh�Free�����}�(hKhh)��}�(hhhMJfhM~hKubh�ubhjp	  h]�hfjM
  hgj�	  hij  h/NhkNhNhlNhmNhnK ho]�(h�"/// @destructsAlloc{texture data}
�����}�(hKhh)��}�(hhhM�ehM{hKubh�ubh�7/// @param[in] td									@theToDestruct{texture data}
�����}�(hKhh)��}�(hhhM�ehM|hKubh�ubeh��Y/// @destructsAlloc{texture data}
/// @param[in] td									@theToDestruct{texture data}
�h�}�h��j7  �j8  �j9  �j:  �void�j<  �h�]�j?  )��}�(h�	TexData*&�hh�td�����}�(hKhh)��}�(hhhMYfhM~hKubh�ubjI  NjJ  �jK  �jL  �ubajV  NjW  NjX  �ubj  )��}�(hh�Init�����}�(hKhh)��}�(hhhM=ghM�hKubh�ubhjp	  h]�hfjp
  hgj�	  hij  h/NhkNhNhlNhmNhnK ho]�h�/// Initializes the structure.
�����}�(hKhh)��}�(hhhM�fhM�hKubh�ubah��/// Initializes the structure.
�h�}�h��j7  �j8  �j9  �j:  �void�j<  �h�]�jV  NjW  NjX  �ubehfjt	  hghhhij�  h/NhkNhNhlNhmNhnK ho]�(h�/// Texture information.
�����}�(hKhh)��}�(hhhM(GhM�hKubh�ubh�/// @addAllocFreeAutoAllocNote
�����}�(hKhh)��}�(hhhMAGhM�hKubh�ubh�///
�����}�(hKhh)��}�(hhhM`GhM�hKubh�ubhX  /// The @ref ox, @ref oy and @ref m values may differ from the values specified in the dialog, these are a precalculated raytracer representation. To better understand the meaning of those values please print this routine (it is the projection routine in source code):
�����}�(hKhh)��}�(hhhMdGhM�hKubh�ubh�
/// @code
�����}�(hKhh)��}�(hhhMqHhM�hKubh�ubh�q/// Bool ShdProjectPoint(VolumeData *sd, TexData *tdp, Int32 lhit, const Vector &p, const Vector &n, Vector *uv)
�����}�(hKhh)��}�(hhhM{HhM�hKubh�ubh�/// {
�����}�(hKhh)��}�(hhhM�HhM�hKubh�ubh�$/// 	Float lenxinv=0.0,lenyinv=0.0;
�����}�(hKhh)��}�(hhhM�HhM�hKubh�ubh�2/// 	if (tdp->lenx!=0.0) lenxinv = 1.0/tdp->lenx;
�����}�(hKhh)��}�(hhhMIhM�hKubh�ubh�2/// 	if (tdp->leny!=0.0) lenyinv = 1.0/tdp->leny;
�����}�(hKhh)��}�(hhhMHIhM�hKubh�ubh�///
�����}�(hKhh)��}�(hhhMzIhM�hKubh�ubh�/// 	switch (tdp->proj)
�����}�(hKhh)��}�(hhhM~IhM�hKubh�ubh�/// 	{
�����}�(hKhh)��}�(hhhM�IhM�hKubh�ubh�/// 		case P_VOLUMESHADER:
�����}�(hKhh)��}�(hhhM�IhM�hKubh�ubh�/// 		{
�����}�(hKhh)��}�(hhhM�IhM�hKubh�ubh�/// 			*uv = p * tdp->im;
�����}�(hKhh)��}�(hhhM�IhM�hKubh�ubh�/// 			return true;
�����}�(hKhh)��}�(hhhM�IhM�hKubh�ubh�/// 		}
�����}�(hKhh)��}�(hhhM�IhM�hKubh�ubh�///
�����}�(hKhh)��}�(hhhM�IhM�hKubh�ubh�!/// 		case P_SPHERICAL: default:
�����}�(hKhh)��}�(hhhM�IhM�hKubh�ubh�/// 		{
�����}�(hKhh)��}�(hhhMJhM�hKubh�ubh�/// 			Vector d = p * tdp->im;
�����}�(hKhh)��}�(hhhM#JhM�hKubh�ubh�+/// 			Float sq = Sqrt(d.x*d.x + d.z*d.z);
�����}�(hKhh)��}�(hhhMBJhM�hKubh�ubh�/// 			if (sq==0.0)
�����}�(hKhh)��}�(hhhMmJhM�hKubh�ubh�	/// 			{
�����}�(hKhh)��}�(hhhM�JhM�hKubh�ubh�/// 				uv->x = 0.0;
�����}�(hKhh)��}�(hhhM�JhM�hKubh�ubh�/// 				if (d.y>0.0)
�����}�(hKhh)��}�(hhhM�JhM�hKubh�ubh�/// 					uv->y = +0.5;
�����}�(hKhh)��}�(hhhM�JhM�hKubh�ubh�/// 				else
�����}�(hKhh)��}�(hhhM�JhM�hKubh�ubh�/// 					uv->y = -0.5;
�����}�(hKhh)��}�(hhhM�JhM�hKubh�ubh�	/// 			}
�����}�(hKhh)��}�(hhhM�JhM�hKubh�ubh�/// 			else
�����}�(hKhh)��}�(hhhM�JhM�hKubh�ubh�	/// 			{
�����}�(hKhh)��}�(hhhMKhM�hKubh�ubh�"/// 				uv->x = ACos(d.x/sq)/PI2;
�����}�(hKhh)��}�(hhhMKhM�hKubh�ubh�(/// 				if (d.z<0.0) uv->x = 1.0-uv->x;
�����}�(hKhh)��}�(hhhM/KhM�hKubh�ubh�///
�����}�(hKhh)��}�(hhhMWKhM�hKubh�ubh�/// 				uv->x -= tdp->ox;
�����}�(hKhh)��}�(hhhM[KhM�hKubh�ubh�(/// 				if (tdp->lenx>0.0 && uv->x<0.0)
�����}�(hKhh)��}�(hhhMuKhM�hKubh�ubh�/// 					uv->x += 1.0;
�����}�(hKhh)��}�(hhhM�KhM�hKubh�ubh�-/// 				else if (tdp->lenx<0.0 && uv->x>0.0)
�����}�(hKhh)��}�(hhhM�KhM�hKubh�ubh�/// 					uv->x -= 1.0;
�����}�(hKhh)��}�(hhhM�KhM�hKubh�ubh�/// 				uv->x *= lenxinv;
�����}�(hKhh)��}�(hhhM�KhM�hKubh�ubh�!/// 				uv->y = ATan(d.y/sq)/PI;
�����}�(hKhh)��}�(hhhMLhM�hKubh�ubh�	/// 			}
�����}�(hKhh)��}�(hhhM3LhM�hKubh�ubh�)/// 			uv->y = -(uv->y+tdp->oy)*lenyinv;
�����}�(hKhh)��}�(hhhM<LhM�hKubh�ubh�/// 			break;
�����}�(hKhh)��}�(hhhMeLhM�hKubh�ubh�/// 		}
�����}�(hKhh)��}�(hhhMsLhM�hKubh�ubh�///
�����}�(hKhh)��}�(hhhM{LhM�hKubh�ubh�/// 		case P_SHRINKWRAP:
�����}�(hKhh)��}�(hhhMLhM�hKubh�ubh�/// 		{
�����}�(hKhh)��}�(hhhM�LhM�hKubh�ubh�/// 			Vector d = p * tdp->im;
�����}�(hKhh)��}�(hhhM�LhM�hKubh�ubh�3/// 			Float   sn,cs,sq = Sqrt(d.x*d.x + d.z*d.z);
�����}�(hKhh)��}�(hhhM�LhM�hKubh�ubh�///
�����}�(hKhh)��}�(hhhM�LhM�hKubh�ubh�/// 			if (sq==0.0)
�����}�(hKhh)��}�(hhhM�LhM�hKubh�ubh�	/// 			{
�����}�(hKhh)��}�(hhhM
MhM�hKubh�ubh�/// 				uv->x = 0.0;
�����}�(hKhh)��}�(hhhMMhM�hKubh�ubh�/// 				if (d.y>0.0)
�����}�(hKhh)��}�(hhhM(MhM�hKubh�ubh�/// 					uv->y = 0.0;
�����}�(hKhh)��}�(hhhM=MhM�hKubh�ubh�/// 				else
�����}�(hKhh)��}�(hhhMSMhM�hKubh�ubh�/// 					uv->y = 1.0;
�����}�(hKhh)��}�(hhhM`MhM�hKubh�ubh�	/// 			}
�����}�(hKhh)��}�(hhhMvMhM�hKubh�ubh�/// 			else
�����}�(hKhh)��}�(hhhMMhM�hKubh�ubh�	/// 			{
�����}�(hKhh)��}�(hhhM�MhM�hKubh�ubh�"/// 				uv->x = ACos(d.x/sq)/PI2;
�����}�(hKhh)��}�(hhhM�MhM�hKubh�ubh�(/// 				if (d.z<0.0) uv->x = 1.0-uv->x;
�����}�(hKhh)��}�(hhhM�MhM�hKubh�ubh�%/// 				uv->y = 0.5-ATan(d.y/sq)/PI;
�����}�(hKhh)��}�(hhhM�MhM�hKubh�ubh�	/// 			}
�����}�(hKhh)��}�(hhhMNhM�hKubh�ubh�///
�����}�(hKhh)��}�(hhhMNhM�hKubh�ubh� /// 			SinCos(uv->x*PI2,sn,cs);
�����}�(hKhh)��}�(hhhMNhM�hKubh�ubh�///
�����}�(hKhh)��}�(hhhM0NhM�hKubh�ubh�7/// 			uv->x = (0.5 + 0.5*cs*uv->y - tdp->ox)*lenxinv;
�����}�(hKhh)��}�(hhhM4NhM�hKubh�ubh�7/// 			uv->y = (0.5 + 0.5*sn*uv->y - tdp->oy)*lenyinv;
�����}�(hKhh)��}�(hhhMkNhM�hKubh�ubh�/// 			break;
�����}�(hKhh)��}�(hhhM�NhM�hKubh�ubh�/// 		}
�����}�(hKhh)��}�(hhhM�NhM�hKubh�ubh�///
�����}�(hKhh)��}�(hhhM�NhM�hKubh�ubh�/// 		case P_CYLINDRICAL:
�����}�(hKhh)��}�(hhhM�NhM�hKubh�ubh�/// 		{
�����}�(hKhh)��}�(hhhM�NhM�hKubh�ubh�/// 			Vector d = p * tdp->im;
�����}�(hKhh)��}�(hhhM�NhM�hKubh�ubh�+/// 			Float sq = Sqrt(d.x*d.x + d.z*d.z);
�����}�(hKhh)��}�(hhhM�NhM�hKubh�ubh�/// 			if (sq==0.0)
�����}�(hKhh)��}�(hhhM(OhM�hKubh�ubh�/// 				uv->x = 0.0;
�����}�(hKhh)��}�(hhhM<OhM�hKubh�ubh�/// 			else
�����}�(hKhh)��}�(hhhMQOhM�hKubh�ubh�	/// 			{
�����}�(hKhh)��}�(hhhM]OhM�hKubh�ubh�"/// 				uv->x = ACos(d.x/sq)/PI2;
�����}�(hKhh)��}�(hhhMfOhM�hKubh�ubh�(/// 				if (d.z<0.0) uv->x = 1.0-uv->x;
�����}�(hKhh)��}�(hhhM�OhM�hKubh�ubh�///
�����}�(hKhh)��}�(hhhM�OhM�hKubh�ubh�/// 				uv->x -= tdp->ox;
�����}�(hKhh)��}�(hhhM�OhM�hKubh�ubh�(/// 				if (tdp->lenx>0.0 && uv->x<0.0)
�����}�(hKhh)��}�(hhhM�OhM�hKubh�ubh�/// 					uv->x += 1.0;
�����}�(hKhh)��}�(hhhM�OhM�hKubh�ubh�-/// 				else if (tdp->lenx<0.0 && uv->x>0.0)
�����}�(hKhh)��}�(hhhMPhM�hKubh�ubh�/// 					uv->x -= 1.0;
�����}�(hKhh)��}�(hhhM:PhM�hKubh�ubh�/// 				uv->x *= lenxinv;
�����}�(hKhh)��}�(hhhMQPhM�hKubh�ubh�	/// 			}
�����}�(hKhh)��}�(hhhMkPhM�hKubh�ubh�+/// 			uv->y = -(d.y*0.5+tdp->oy)*lenyinv;
�����}�(hKhh)��}�(hhhMtPhM�hKubh�ubh�/// 			break;
�����}�(hKhh)��}�(hhhM�PhM�hKubh�ubh�/// 		}
�����}�(hKhh)��}�(hhhM�PhM�hKubh�ubh�///
�����}�(hKhh)��}�(hhhM�PhM�hKubh�ubh�#/// 		case P_FLAT: case P_SPATIAL:
�����}�(hKhh)��}�(hhhM�PhM�hKubh�ubh�/// 		{
�����}�(hKhh)��}�(hhhM�PhM�hKubh�ubh�/// 			Vector d = p * tdp->im;
�����}�(hKhh)��}�(hhhM�PhM�hKubh�ubh�+/// 			uv->x =  (d.x*0.5-tdp->ox)*lenxinv;
�����}�(hKhh)��}�(hhhMQhM�hKubh�ubh�+/// 			uv->y = -(d.y*0.5+tdp->oy)*lenyinv;
�����}�(hKhh)��}�(hhhM.QhM�hKubh�ubh�/// 			break;
�����}�(hKhh)��}�(hhhMYQhM�hKubh�ubh�/// 		}
�����}�(hKhh)��}�(hhhMgQhM�hKubh�ubh�///
�����}�(hKhh)��}�(hhhMoQhM�hKubh�ubh�/// 		case P_CUBIC:
�����}�(hKhh)��}�(hhhMsQhM�hKubh�ubh�/// 		{
�����}�(hKhh)��}�(hhhM�QhM�hKubh�ubh�/// 			Vector d = p * tdp->im;
�����}�(hKhh)��}�(hhhM�QhM�hKubh�ubh�/// 			Vector v = n ^ tdp->im;
�����}�(hKhh)��}�(hhhM�QhM�hKubh�ubh�/// 			Int32   dir;
�����}�(hKhh)��}�(hhhM�QhM�hKubh�ubh�///
�����}�(hKhh)��}�(hhhM�QhM�hKubh�ubh�/// 			if (Abs(v.x)>Abs(v.y))
�����}�(hKhh)��}�(hhhM�QhM�hKubh�ubh�	/// 			{
�����}�(hKhh)��}�(hhhMRhM�hKubh�ubh�/// 				if (Abs(v.x)>Abs(v.z))
�����}�(hKhh)��}�(hhhMRhM�hKubh�ubh�/// 					dir = 0;
�����}�(hKhh)��}�(hhhM+RhM�hKubh�ubh�/// 				else
�����}�(hKhh)��}�(hhhM=RhM�hKubh�ubh�/// 					dir = 2;
�����}�(hKhh)��}�(hhhMJRhM�hKubh�ubh�	/// 			}
�����}�(hKhh)��}�(hhhM\RhM�hKubh�ubh�/// 			else
�����}�(hKhh)��}�(hhhMeRhM�hKubh�ubh�	/// 			{
�����}�(hKhh)��}�(hhhMqRhM�hKubh�ubh�/// 				if (Abs(v.y)>Abs(v.z))
�����}�(hKhh)��}�(hhhMzRhM�hKubh�ubh�/// 					dir = 1;
�����}�(hKhh)��}�(hhhM�RhM�hKubh�ubh�/// 				else
�����}�(hKhh)��}�(hhhM�RhM�hKubh�ubh�/// 					dir = 2;
�����}�(hKhh)��}�(hhhM�RhM�hKubh�ubh�	/// 			}
�����}�(hKhh)��}�(hhhM�RhM�hKubh�ubh�///
�����}�(hKhh)��}�(hhhM�RhM�hKubh�ubh�/// 			switch (dir)
�����}�(hKhh)��}�(hhhM�RhM�hKubh�ubh�	/// 			{
�����}�(hKhh)��}�(hhhM�RhM�hKubh�ubh�/// 				case 0: // x axis
�����}�(hKhh)��}�(hhhM�RhM hKubh�ubh�
/// 				{
�����}�(hKhh)��}�(hhhMShMhKubh�ubh�/// 					if (v.x<0.0)
�����}�(hKhh)��}�(hhhMShMhKubh�ubh�./// 						uv->x = (-d.z*0.5-tdp->ox)*lenxinv;
�����}�(hKhh)��}�(hhhM.ShMhKubh�ubh�/// 					else
�����}�(hKhh)��}�(hhhM\ShMhKubh�ubh�./// 						uv->x = ( d.z*0.5-tdp->ox)*lenxinv;
�����}�(hKhh)��}�(hhhMjShMhKubh�ubh�///
�����}�(hKhh)��}�(hhhM�ShMhKubh�ubh�-/// 					uv->y = -(d.y*0.5+tdp->oy)*lenyinv;
�����}�(hKhh)��}�(hhhM�ShMhKubh�ubh�/// 					break;
�����}�(hKhh)��}�(hhhM�ShMhKubh�ubh�
/// 				}
�����}�(hKhh)��}�(hhhM�ShM	hKubh�ubh�///
�����}�(hKhh)��}�(hhhM�ShM
hKubh�ubh�/// 				case 1:  // y axis
�����}�(hKhh)��}�(hhhM�ShMhKubh�ubh�
/// 				{
�����}�(hKhh)��}�(hhhMThMhKubh�ubh�/// 					if (v.y<0.0)
�����}�(hKhh)��}�(hhhMThMhKubh�ubh�./// 						uv->y = ( d.z*0.5-tdp->oy)*lenyinv;
�����}�(hKhh)��}�(hhhM"ThMhKubh�ubh�/// 					else
�����}�(hKhh)��}�(hhhMPThMhKubh�ubh�./// 						uv->y = (-d.z*0.5-tdp->oy)*lenyinv;
�����}�(hKhh)��}�(hhhM^ThMhKubh�ubh�///
�����}�(hKhh)��}�(hhhM�ThMhKubh�ubh�,/// 					uv->x = (d.x*0.5-tdp->ox)*lenxinv;
�����}�(hKhh)��}�(hhhM�ThMhKubh�ubh�/// 					break;
�����}�(hKhh)��}�(hhhM�ThMhKubh�ubh�
/// 				}
�����}�(hKhh)��}�(hhhM�ThMhKubh�ubh�///
�����}�(hKhh)��}�(hhhM�ThMhKubh�ubh�/// 				case 2: // z axis
�����}�(hKhh)��}�(hhhM�ThMhKubh�ubh�
/// 				{
�����}�(hKhh)��}�(hhhM�ThMhKubh�ubh�/// 					if (v.z<0.0)
�����}�(hKhh)��}�(hhhM�ThMhKubh�ubh�./// 						uv->x = ( d.x*0.5-tdp->ox)*lenxinv;
�����}�(hKhh)��}�(hhhMUhMhKubh�ubh�/// 					else
�����}�(hKhh)��}�(hhhMBUhMhKubh�ubh�./// 						uv->x = (-d.x*0.5-tdp->ox)*lenxinv;
�����}�(hKhh)��}�(hhhMPUhMhKubh�ubh�///
�����}�(hKhh)��}�(hhhM~UhMhKubh�ubh�-/// 					uv->y = -(d.y*0.5+tdp->oy)*lenyinv;
�����}�(hKhh)��}�(hhhM�UhMhKubh�ubh�/// 					break;
�����}�(hKhh)��}�(hhhM�UhMhKubh�ubh�
/// 				}
�����}�(hKhh)��}�(hhhM�UhMhKubh�ubh�	/// 			}
�����}�(hKhh)��}�(hhhM�UhM hKubh�ubh�///
�����}�(hKhh)��}�(hhhM�UhM!hKubh�ubh�/// 			break;
�����}�(hKhh)��}�(hhhM�UhM"hKubh�ubh�/// 		}
�����}�(hKhh)��}�(hhhM�UhM#hKubh�ubh�///
�����}�(hKhh)��}�(hhhM�UhM$hKubh�ubh�/// 		case P_FRONTAL:
�����}�(hKhh)��}�(hhhM�UhM%hKubh�ubh�/// 		{
�����}�(hKhh)��}�(hhhMVhM&hKubh�ubh�2/// 			RayParameter *param=sd->GetRayParameter();
�����}�(hKhh)��}�(hhhMVhM'hKubh�ubh�///
�����}�(hKhh)��}�(hhhM@VhM(hKubh�ubh�:/// 			Float ox=0.0,oy=0.0,ax=param->xres,ay=param->yres;
�����}�(hKhh)��}�(hhhMDVhM)hKubh�ubh� /// 			Int32 curr_x,curr_y,scl;
�����}�(hKhh)��}�(hhhM~VhM*hKubh�ubh�(/// 			sd->GetXY(&curr_x,&curr_y,&scl);
�����}�(hKhh)��}�(hhhM�VhM+hKubh�ubh�E/// 			uv->x = ((Float(curr_x)/Float(scl)-ox)/ax - tdp->ox)*lenxinv;
�����}�(hKhh)��}�(hhhM�VhM,hKubh�ubh�E/// 			uv->y = ((Float(curr_y)/Float(scl)-ox)/ay - tdp->oy)*lenyinv;
�����}�(hKhh)��}�(hhhMWhM-hKubh�ubh�/// 			break;
�����}�(hKhh)��}�(hhhMPWhM.hKubh�ubh�/// 		}
�����}�(hKhh)��}�(hhhM^WhM/hKubh�ubh�///
�����}�(hKhh)��}�(hhhMfWhM0hKubh�ubh�/// 		case P_UVW:
�����}�(hKhh)��}�(hhhMjWhM1hKubh�ubh�/// 		{
�����}�(hKhh)��}�(hhhM|WhM2hKubh�ubh�2/// 			RayObject *op=sd->ID_to_Obj(lhit,nullptr);
�����}�(hKhh)��}�(hhhM�WhM3hKubh�ubh�D/// 			if (op && tdp->uvwind<op->uvwcnt && op->uvwadr[tdp->uvwind])
�����}�(hKhh)��}�(hhhM�WhM4hKubh�ubh�)/// 				*uv=sd->GetPointUVW(tdp,lhit,p);
�����}�(hKhh)��}�(hhhM�WhM5hKubh�ubh�/// 			else
�����}�(hKhh)��}�(hhhM#XhM6hKubh�ubh�/// 				uv->x = uv->y = 0.0;
�����}�(hKhh)��}�(hhhM/XhM7hKubh�ubh�///
�����}�(hKhh)��}�(hhhMLXhM8hKubh�ubh�/// 			break;
�����}�(hKhh)��}�(hhhMPXhM9hKubh�ubh�/// 		}
�����}�(hKhh)��}�(hhhM^XhM:hKubh�ubh�/// 	}
�����}�(hKhh)��}�(hhhMfXhM;hKubh�ubh�///
�����}�(hKhh)��}�(hhhMmXhM<hKubh�ubh� /// 	if (tdp->texflag&TEX_TILE)
�����}�(hKhh)��}�(hhhMqXhM=hKubh�ubh�/// 		return true;
�����}�(hKhh)��}�(hhhM�XhM>hKubh�ubh�
/// 	else
�����}�(hKhh)��}�(hhhM�XhM?hKubh�ubh�C/// 		return uv->x>=0.0 && uv->x<=1.0 && uv->y>=0.0 && uv->y<=1.0;
�����}�(hKhh)��}�(hhhM�XhM@hKubh�ubh�/// }
�����}�(hKhh)��}�(hhhM�XhMAhKubh�ubh�/// @endcode
�����}�(hKhh)��}�(hhhM�XhMBhKubh�ubeh�X�  /// Texture information.
/// @addAllocFreeAutoAllocNote
///
/// The @ref ox, @ref oy and @ref m values may differ from the values specified in the dialog, these are a precalculated raytracer representation. To better understand the meaning of those values please print this routine (it is the projection routine in source code):
/// @code
/// Bool ShdProjectPoint(VolumeData *sd, TexData *tdp, Int32 lhit, const Vector &p, const Vector &n, Vector *uv)
/// {
/// 	Float lenxinv=0.0,lenyinv=0.0;
/// 	if (tdp->lenx!=0.0) lenxinv = 1.0/tdp->lenx;
/// 	if (tdp->leny!=0.0) lenyinv = 1.0/tdp->leny;
///
/// 	switch (tdp->proj)
/// 	{
/// 		case P_VOLUMESHADER:
/// 		{
/// 			*uv = p * tdp->im;
/// 			return true;
/// 		}
///
/// 		case P_SPHERICAL: default:
/// 		{
/// 			Vector d = p * tdp->im;
/// 			Float sq = Sqrt(d.x*d.x + d.z*d.z);
/// 			if (sq==0.0)
/// 			{
/// 				uv->x = 0.0;
/// 				if (d.y>0.0)
/// 					uv->y = +0.5;
/// 				else
/// 					uv->y = -0.5;
/// 			}
/// 			else
/// 			{
/// 				uv->x = ACos(d.x/sq)/PI2;
/// 				if (d.z<0.0) uv->x = 1.0-uv->x;
///
/// 				uv->x -= tdp->ox;
/// 				if (tdp->lenx>0.0 && uv->x<0.0)
/// 					uv->x += 1.0;
/// 				else if (tdp->lenx<0.0 && uv->x>0.0)
/// 					uv->x -= 1.0;
/// 				uv->x *= lenxinv;
/// 				uv->y = ATan(d.y/sq)/PI;
/// 			}
/// 			uv->y = -(uv->y+tdp->oy)*lenyinv;
/// 			break;
/// 		}
///
/// 		case P_SHRINKWRAP:
/// 		{
/// 			Vector d = p * tdp->im;
/// 			Float   sn,cs,sq = Sqrt(d.x*d.x + d.z*d.z);
///
/// 			if (sq==0.0)
/// 			{
/// 				uv->x = 0.0;
/// 				if (d.y>0.0)
/// 					uv->y = 0.0;
/// 				else
/// 					uv->y = 1.0;
/// 			}
/// 			else
/// 			{
/// 				uv->x = ACos(d.x/sq)/PI2;
/// 				if (d.z<0.0) uv->x = 1.0-uv->x;
/// 				uv->y = 0.5-ATan(d.y/sq)/PI;
/// 			}
///
/// 			SinCos(uv->x*PI2,sn,cs);
///
/// 			uv->x = (0.5 + 0.5*cs*uv->y - tdp->ox)*lenxinv;
/// 			uv->y = (0.5 + 0.5*sn*uv->y - tdp->oy)*lenyinv;
/// 			break;
/// 		}
///
/// 		case P_CYLINDRICAL:
/// 		{
/// 			Vector d = p * tdp->im;
/// 			Float sq = Sqrt(d.x*d.x + d.z*d.z);
/// 			if (sq==0.0)
/// 				uv->x = 0.0;
/// 			else
/// 			{
/// 				uv->x = ACos(d.x/sq)/PI2;
/// 				if (d.z<0.0) uv->x = 1.0-uv->x;
///
/// 				uv->x -= tdp->ox;
/// 				if (tdp->lenx>0.0 && uv->x<0.0)
/// 					uv->x += 1.0;
/// 				else if (tdp->lenx<0.0 && uv->x>0.0)
/// 					uv->x -= 1.0;
/// 				uv->x *= lenxinv;
/// 			}
/// 			uv->y = -(d.y*0.5+tdp->oy)*lenyinv;
/// 			break;
/// 		}
///
/// 		case P_FLAT: case P_SPATIAL:
/// 		{
/// 			Vector d = p * tdp->im;
/// 			uv->x =  (d.x*0.5-tdp->ox)*lenxinv;
/// 			uv->y = -(d.y*0.5+tdp->oy)*lenyinv;
/// 			break;
/// 		}
///
/// 		case P_CUBIC:
/// 		{
/// 			Vector d = p * tdp->im;
/// 			Vector v = n ^ tdp->im;
/// 			Int32   dir;
///
/// 			if (Abs(v.x)>Abs(v.y))
/// 			{
/// 				if (Abs(v.x)>Abs(v.z))
/// 					dir = 0;
/// 				else
/// 					dir = 2;
/// 			}
/// 			else
/// 			{
/// 				if (Abs(v.y)>Abs(v.z))
/// 					dir = 1;
/// 				else
/// 					dir = 2;
/// 			}
///
/// 			switch (dir)
/// 			{
/// 				case 0: // x axis
/// 				{
/// 					if (v.x<0.0)
/// 						uv->x = (-d.z*0.5-tdp->ox)*lenxinv;
/// 					else
/// 						uv->x = ( d.z*0.5-tdp->ox)*lenxinv;
///
/// 					uv->y = -(d.y*0.5+tdp->oy)*lenyinv;
/// 					break;
/// 				}
///
/// 				case 1:  // y axis
/// 				{
/// 					if (v.y<0.0)
/// 						uv->y = ( d.z*0.5-tdp->oy)*lenyinv;
/// 					else
/// 						uv->y = (-d.z*0.5-tdp->oy)*lenyinv;
///
/// 					uv->x = (d.x*0.5-tdp->ox)*lenxinv;
/// 					break;
/// 				}
///
/// 				case 2: // z axis
/// 				{
/// 					if (v.z<0.0)
/// 						uv->x = ( d.x*0.5-tdp->ox)*lenxinv;
/// 					else
/// 						uv->x = (-d.x*0.5-tdp->ox)*lenxinv;
///
/// 					uv->y = -(d.y*0.5+tdp->oy)*lenyinv;
/// 					break;
/// 				}
/// 			}
///
/// 			break;
/// 		}
///
/// 		case P_FRONTAL:
/// 		{
/// 			RayParameter *param=sd->GetRayParameter();
///
/// 			Float ox=0.0,oy=0.0,ax=param->xres,ay=param->yres;
/// 			Int32 curr_x,curr_y,scl;
/// 			sd->GetXY(&curr_x,&curr_y,&scl);
/// 			uv->x = ((Float(curr_x)/Float(scl)-ox)/ax - tdp->ox)*lenxinv;
/// 			uv->y = ((Float(curr_y)/Float(scl)-ox)/ay - tdp->oy)*lenyinv;
/// 			break;
/// 		}
///
/// 		case P_UVW:
/// 		{
/// 			RayObject *op=sd->ID_to_Obj(lhit,nullptr);
/// 			if (op && tdp->uvwind<op->uvwcnt && op->uvwadr[tdp->uvwind])
/// 				*uv=sd->GetPointUVW(tdp,lhit,p);
/// 			else
/// 				uv->x = uv->y = 0.0;
///
/// 			break;
/// 		}
/// 	}
///
/// 	if (tdp->texflag&TEX_TILE)
/// 		return true;
/// 	else
/// 		return uv->x>=0.0 && uv->x<=1.0 && uv->y>=0.0 && uv->y<=1.0;
/// }
/// @endcode
�h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�Ray�����}�(hKhh)��}�(hhhMhhM�hKubh�ubhhh]�(j  )��}�(hj'  hj  h]�hfj'  hghhhij'  h/NhkNhNhlNhmNhnK ho]�h�/// Default constructor.
�����}�(hKhh)��}�(hhhMqhhM�hKubh�ubah��/// Default constructor.
�h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�jV  NjW  NjX  �ubj;  )��}�(hh�ior�����}�(hKhh)��}�(hhhM�ihM�hK
ubh�ubhj  h]�hfj4  hghhhijK  h/NhkNh�Float�hlNhmNhnK ho]�h�3///< [READ WRITE] The current index of refraction.
�����}�(hKhh)��}�(hhhM�ihM�hKubh�ubah��3///< [READ WRITE] The current index of refraction.
�h�}�h��j7  �ubj;  )��}�(hh�pp�����}�(hKhh)��}�(hhhM�ihM�hK
ubh�ubhj  h]�hfjG  hghhhijK  h/NhkNh�Vector�hlNhmNhnK ho]�(h�;///< [READ WRITE] 3 additional ray points for MIP-Mapping.
�����}�(hKhh)��}�(hhhM�ihM�hKubh�ubh�#///< @note @image html ray_mip.png
�����}�(hKhh)��}�(hhhM#jhM�hKubh�ubh�@///< @c P is the pixel origin or where the ray was generated.\n
�����}�(hKhh)��}�(hhhMTjhM�hKubh�ubh�>///< 0/1/2 are indices into the @ref pp and @ref vv arrays.\n
�����}�(hKhh)��}�(hhhM�jhM�hKubh�ubh�?///< The square is one screen pixel wide in X and Y direction.
�����}�(hKhh)��}�(hhhM�jhM�hKubh�ubeh�X  ///< [READ WRITE] 3 additional ray points for MIP-Mapping.
///< @note @image html ray_mip.png
///< @c P is the pixel origin or where the ray was generated.\n
///< 0/1/2 are indices into the @ref pp and @ref vv arrays.\n
///< The square is one screen pixel wide in X and Y direction.
�h�}�h��j7  �ubj;  )��}�(hh�vv�����}�(hKhh)��}�(hhhM6khM�hK
ubh�ubhj  h]�hfjr  hghhhijK  h/NhkNh�Vector�hlNhmNhnK ho]�(h�<///< [READ WRITE] 3 additional ray vectors for MIP-Mapping.
�����}�(hKhh)��}�(hhhMAkhM�hKubh�ubh�#///< @note @image html ray_mip.png
�����}�(hKhh)��}�(hhhM�khM�hKubh�ubh�@///< @c P is the pixel origin or where the ray was generated.\n
�����}�(hKhh)��}�(hhhM�khM�hKubh�ubh�>///< 0/1/2 are indices into the @ref pp and @ref vv arrays.\n
�����}�(hKhh)��}�(hhhM
lhM�hKubh�ubh�?///< The square is one screen pixel wide in X and Y direction.
�����}�(hKhh)��}�(hhhMVlhM�hKubh�ubeh�X  ///< [READ WRITE] 3 additional ray vectors for MIP-Mapping.
///< @note @image html ray_mip.png
///< @c P is the pixel origin or where the ray was generated.\n
///< 0/1/2 are indices into the @ref pp and @ref vv arrays.\n
///< The square is one screen pixel wide in X and Y direction.
���      h�}�h��j7  �ubj;  )��}�(hh�	transport�����}�(hKhh)��}�(hhhM�lhM�hK
ubh�ubhj  h]�hfj�  hghhhijK  h/NhkNh�Vector�hlNhmNhnK ho]�h�r///< [READ ONLY] The current ray intensity (for special shadow calculation). A ray starts with intensity @em 1.0.
�����}�(hKhh)��}�(hhhM�lhM�hKubh�ubah��r///< [READ ONLY] The current ray intensity (for special shadow calculation). A ray starts with intensity @em 1.0.
�h�}�h��j7  �ubehfj  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�///
�����}�(hKhh)��}�(hhhM�ghM�hKubh�ubah��///
�h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubh\)��}�(hh�L_SPLIT_BIT�����}�(hKhh)��}�(hhhM;mhM�hK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�/// @markPrivate
�����}�(hKhh)��}�(hhhM"mhM�hKubh�ubah��/// @markPrivate
�h�}�h��h�]�ubj�  )��}�(hh�RayHitID�����}�(hKhh)��}�(hhhM7phM�hKubh�ubhhh]�(j;  )��}�(hh�	rayobject�����}�(hKhh)��}�(hhhMRphM�hKubh�ubhj�  h]�hfj�  hgh�private�����}�(hKhh)��}�(hhhMBphM�hKubh�ubhijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�h	h�}�h��j7  �ubj;  )��}�(hh�polygon�����}�(hKhh)��}�(hhhMdphM�hKubh�ubhj�  h]�hfj�  hgj�  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�h	h�}�h��j7  �ubj  )��}�(hj'  hj�  h]�hfj'  hgh�public�����}�(hKhh)��}�(hhhMnphM�hKubh�ubhij'  h/NhkNhNhlNhmNhnK ho]�h�/// Default constructor.
�����}�(hKhh)��}�(hhhM�phM�hKubh�ubah��/// Default constructor.
�h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�jV  NjW  NjX  �ubj  )��}�(hj'  hj�  h]�hfj'  hgj�  hij'  h/NhkNhNhlNhmNhnK ho]�(h�0/// Creates an uninitialized ray hit structure.
�����}�(hKhh)��}�(hhhM�qhM�hKubh�ubh�8/// @param[in] DC									Dummy argument. Pass @ref DC.
�����}�(hKhh)��}�(hhhM rhM�hKubh�ubeh��h/// Creates an uninitialized ray hit structure.
/// @param[in] DC									Dummy argument. Pass @ref DC.
�h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�j?  )��}�(h�_DONTCONSTRUCT�hh�DC�����}�(hKhh)��}�(hhhM�rhM�hK#ubh�ubjI  NjJ  �jK  �jL  �ubajV  NjW  NjX  �ubj  )��}�(hj'  hj�  h]�hfj'  hgj�  hij'  h/NhkNhNhlNhmNhnK ho]�(h�b/// Copy constructor. Creates a new RayHitID structure with all of the values from the other one.
�����}�(hKhh)��}�(hhhMshM�hKubh�ubh�9/// @param[in] other							The source ray hit structure.
�����}�(hKhh)��}�(hhhMshM�hKubh�ubeh���/// Copy constructor. Creates a new RayHitID structure with all of the values from the other one.
/// @param[in] other							The source ray hit structure.
�h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�j?  )��}�(h�const RayHitID&�hh�other�����}�(hKhh)��}�(hhhM.thM�hKubh�ubjI  NjJ  �jK  �jL  �ubajV  NjW  NjX  �ubj  )��}�(hj'  hj�  h]�hfj'  hgj�  hij'  h/NhkNhNhlNhmNhnK ho]�(h�@/// Creates a ray hit structure based on the passed parameters.
�����}�(hKhh)��}�(hhhM�thM�hKubh�ubh�./// @param[in] t_rayobject				The ray object.
�����}�(hKhh)��}�(hhhMuhM�hKubh�ubh�0/// @param[in] t_polygon					The polygon index.
�����}�(hKhh)��}�(hhhM=uhM�hKubh�ubh��/// @param[in] second							@formatConstant{true} for second part (A-C-D) of a quadrangle, @formatConstant{false} for the first part (A-B-C).
�����}�(hKhh)��}�(hhhMnuhM�hKubh�ubeh�X,  /// Creates a ray hit structure based on the passed parameters.
/// @param[in] t_rayobject				The ray object.
/// @param[in] t_polygon					The polygon index.
/// @param[in] second							@formatConstant{true} for second part (A-C-D) of a quadrangle, @formatConstant{false} for the first part (A-B-C).
�h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�(j?  )��}�(h�const RayObject*�hh�t_rayobject�����}�(hKhh)��}�(hhhMsvhM�hKubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�Int32�hh�	t_polygon�����}�(hKhh)��}�(hhhM�vhM�hK/ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�Bool�hh�second�����}�(hKhh)��}�(hhhM�vhM�hK?ubh�ubjI  NjJ  �jK  �jL  �ubejV  NjW  NjX  �ubj  )��}�(hh�IsEqual�����}�(hKhh)��}�(hhhMNxhM�hKubh�ubhj�  h]�hfj}  hgj�  hij  h/NhkNhNhlNhmNhnK ho]�(h�./// Checks if 2 ray hit structures are equal.
�����}�(hKhh)��}�(hhhM%whM�hKubh�ubh�A/// @param[in] snd								The ray hit structure to compare with.
�����}�(hKhh)��}�(hhhMTwhM�hKubh�ubh�O/// @return												@trueIfOtherwiseFalse{the ray hit structures are equal}
�����}�(hKhh)��}�(hhhM�whM�hKubh�ubeh���/// Checks if 2 ray hit structures are equal.
/// @param[in] snd								The ray hit structure to compare with.
/// @return												@trueIfOtherwiseFalse{the ray hit structures are equal}
�h�}�h��j7  �j8  �j9  �j:  �Bool�j<  �h�]�j?  )��}�(h�const RayHitID&�hh�snd�����}�(hKhh)��}�(hhhMfxhM�hK&ubh�ubjI  NjJ  �jK  �jL  �ubajV  NjW  NjX  �ubj  )��}�(hh�IsPopulated�����}�(hKhh)��}�(hhhM�yhM�hKubh�ubhj�  h]�hfj�  hgj�  hij  h/NhkNhNhlNhmNhnK ho]�(h�,/// Checks if the ray hit identity is zero.
�����}�(hKhh)��}�(hhhMyhM�hKubh�ubh�J/// @return												@trueIfOtherwiseFalse{he ray hit identity is zero}
�����}�(hKhh)��}�(hhhM=yhM�hKubh�ubeh��v/// Checks if the ray hit identity is zero.
/// @return												@trueIfOtherwiseFalse{he ray hit identity is zero}
�h�}�h��j7  �j8  �j9  �j:  �Bool�j<  �h�]�jV  NjW  NjX  �ubj  )��}�(hh�Clear�����}�(hKhh)��}�(hhhM{hM�hKubh�ubhj�  h]�hfj�  hgj�  hij  h/NhkNhNhlNhmNhnK ho]�h�!/// Clears the ray hit identity.
�����}�(hKhh)��}�(hhhM}zhM�hKubh�ubah��!/// Clears the ray hit identity.
�h�}�h��j7  �j8  �j9  �j:  �void�j<  �h�]�jV  NjW  NjX  �ubh)��}�(hNhj�  h]�h h�#ifdef __API_INTERN__�����}�(hK
hh)��}�(hhhM-{hM�hKubh�ububj  )��}�(hh�Set�����}�(hKhh)��}�(hhhMI{hM�hKubh�ubhj�  h]�hfj�  hgj�  hij  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j7  �j8  �j9  �j:  �void�j<  �h�]�(j?  )��}�(h�const RayObject*�hh�t_rayobject�����}�(hKhh)��}�(hhhM^{hM�hKubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�Int32�hh�	t_polygon�����}�(hKhh)��}�(hhhMq{hM�hK/ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�Bool�hh�second�����}�(hKhh)��}�(hhhM�{hM�hK?ubh�ubjI  NjJ  �jK  �jL  �ubejV  NjW  NjX  �ubj  )��}�(hh�	GetObject�����}�(hKhh)��}�(hhhM�{hM�hK
ubh�ubhj�  h]�hfj  hgj�  hij  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j7  �j8  �j9  �j:  �RayObj*�j<  �h�]�j?  )��}�(h�const Raytracer*�hh�rt�����}�(hKhh)��}�(hhhM�{hM�hK%ubh�ubjI  NjJ  �jK  �jL  �ubajV  NjW  NjX  �ubj  )��}�(hh�GetPolygonPlus�����}�(hKhh)��}�(hhhM�{hM�hKubh�ubhj�  h]�hfj  hgj�  hij  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j7  �j8  �j9  �j:  �Int32�j<  �h�]�jV  NjW  NjX  �ubh)��}�(hNhj�  h]�h h�#else�����}�(hK
hh)��}�(hhhM|hM�hKubh�ububj  )��}�(hh�Set�����}�(hKhh)��}�(hhhM�}hM�hKubh�ubhj�  h]�hfj1  hgj�  hij  h/NhkNhNhlNhmNhnK ho]�(h�"/// Setups the ray hit structure.
�����}�(hKhh)��}�(hhhMq|hM�hKubh�ubh�./// @param[in] t_rayobject				The ray object.
�����}�(hKhh)��}�(hhhM�|hM�hKubh�ubh�0/// @param[in] t_polygon					The polygon index.
�����}�(hKhh)��}�(hhhM�|hM�hKubh�ubh��/// @param[in] second							@formatConstant{true} for second part (A-C-D) of a quadrangle, @formatConstant{false} for the first part (A-B-C).
�����}�(hKhh)��}�(hhhM�|hM�hKubh�ubeh�X  /// Setups the ray hit structure.
/// @param[in] t_rayobject				The ray object.
/// @param[in] t_polygon					The polygon index.
/// @param[in] second							@formatConstant{true} for second part (A-C-D) of a quadrangle, @formatConstant{false} for the first part (A-B-C).
�h�}�h��j7  �j8  �j9  �j:  �void�j<  �h�]�(j?  )��}�(h�const RayObject*�hh�t_rayobject�����}�(hKhh)��}�(hhhM ~hM�hK#ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�Int32�hh�	t_polygon�����}�(hKhh)��}�(hhhM~hM�hK6ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�Bool�hh�second�����}�(hKhh)��}�(hhhM#~hM�hKFubh�ubjI  NjJ  �jK  �jL  �ubejV  NjW  NjX  �ubj  )��}�(hh�	GetObject�����}�(hKhh)��}�(hhhMN�hM�hKubh�ubhj�  h]�hfjr  hgj�  hij  h/NhkNhNhlNhmNhnK ho]�(h�H/// Retrieves the ray object of the ray hit identity for a volume data.
�����}�(hKhh)��}�(hhhMhM�hKubh�ubh�+/// @param[in] vd									The volume data.
�����}�(hKhh)��}�(hhhMXhM�hKubh�ubh�U/// @return												The ray object, or @formatConstant{nullptr} if not available.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubeh���/// Retrieves the ray object of the ray hit identity for a volume data.
/// @param[in] vd									The volume data.
/// @return												The ray object, or @formatConstant{nullptr} if not available.
�h�}�h��j7  �j8  �j9  �j:  �const RayObject*�j<  �h�]�j?  )��}�(h�const VolumeData*�hh�vd�����}�(hKhh)��}�(hhhMj�hM�hK6ubh�ubjI  NjJ  �jK  �jL  �ubajV  NjW  NjX  �ubh)��}�(hNhj�  h]�h h�#endif�����}�(hK
hh)��}�(hhhM��hM�hKubh�ububj  )��}�(hh�
GetPolygon�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj�  h]�hfj�  hgj�  hij  h/NhkNhNhlNhmNhnK ho]�(h�/// Gets the polygon index.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�*/// @return												The polygon index.
�����}�(hKhh)��}�(hhhM%�hM�hKubh�ubeh��F/// Gets the polygon index.
/// @return												The polygon index.
�h�}�h��j7  �j8  �j9  �j:  �Int32�j<  �h�]�jV  NjW  NjX  �ubj  )��}�(hh�	GetSecond�����}�(hKhh)��}�(hhhM�hMhKubh�ubhj�  h]�hfj�  hgj�  hij  h/NhkNhNhlNhmNhnK ho]�(h�>/// Checks if the polygon is the second part of a quadrangle.
�����}�(hKhh)��}�(hhhM>�hMhKubh�ubh��/// @return												@formatConstant{true} if the polygon is a second part of a quadrangle (A-C-D), @formatConstant{false} for the first part (A-B-C).
�����}�(hKhh)��}�(hhhM}�hMhKubh�ubeh���/// Checks if the polygon is the second part of a quadrangle.
/// @return												@formatConstant{true} if the polygon is a second part of a quadrangle (A-C-D), @formatConstant{false} for the first part (A-B-C).
�h�}�h��j7  �j8  �j9  �j:  �Bool�j<  �h�]�jV  NjW  NjX  �ubj  )��}�(hh�ClearSecond�����}�(hKhh)��}�(hhhMĄhM
hKubh�ubhj�  h]�hfj�  hgj�  hij  h/NhkNhNhlNhmNhnK ho]�h�A/// Sets the polygon to be a first part of a quadrangle (A-B-C).
�����}�(hKhh)��}�(hhhM�hMhKubh�ubah��A/// Sets the polygon to be a first part of a quadrangle (A-B-C).
�h�}�h��j7  �j8  �j9  �j:  �void�j<  �h�]�jV  NjW  NjX  �ubj  )��}�(hh�	SetSecond�����}�(hKhh)��}�(hhhM��hMhKubh�ubhj�  h]�hfj�  hgj�  hij  h/NhkNhNhlNhmNhnK ho]�h�A/// Set the polygon to be a second part of a quadrangle (A-C-D).
�����}�(hKhh)��}�(hhhMO�hMhKubh�ubah��A/// Set the polygon to be a second part of a quadrangle (A-C-D).
�h�}�h��j7  �j8  �j9  �j:  �void�j<  �h�]�jV  NjW  NjX  �ubj  )��}�(hh�SetPrivateData�����}�(hKhh)��}�(hhhMk�hMhKubh�ubhj�  h]�hfj   hgj�  hij  h/NhkNhNhlNhmNhnK ho]�(h�/// Sets the private data.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�4/// @param[in] t_rayobject				The ray object index.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�0/// @param[in] t_polygon					The polygon index.
�����}�(hKhh)��}�(hhhM҆hMhKubh�ubeh��/// Sets the private data.
/// @param[in] t_rayobject				The ray object index.
/// @param[in] t_polygon					The polygon index.
�h�}�h��j7  �j8  �j9  �j:  �void�j<  �h�]�(j?  )��}�(h�Int32�hh�t_rayobject�����}�(hKhh)��}�(hhhM��hMhK#ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�Int32�hh�	t_polygon�����}�(hKhh)��}�(hhhM��hMhK6ubh�ubjI  NjJ  �jK  �jL  �ubejV  NjW  NjX  �ubj  )��}�(hh�GetPrivateData�����}�(hKhh)��}�(hhhM,�hMhKubh�ubhj�  h]�hfj2  hgj�  hij  h/NhkNhNhlNhmNhnK ho]�(h�/// Gets the private data.
�����}�(hKhh)��}�(hhhM.�hMhKubh�ubh�>/// @param[out] t_rayobject				Assigned the ray object index.
�����}�(hKhh)��}�(hhhMJ�hMhKubh�ubh�:/// @param[out] t_polygon					Assigned the polygon index.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubeh���/// Gets the private data.
/// @param[out] t_rayobject				Assigned the ray object index.
/// @param[out] t_polygon					Assigned the polygon index.
�h�}�h��j7  �j8  �j9  �j:  �void�j<  �h�]�(j?  )��}�(h�Int32*�hh�t_rayobject�����}�(hKhh)��}�(hhhMB�hMhK$ubh�ubjI  NjJ  �jK  �jL  �ubj?  )��}�(h�Int32*�hh�	t_polygon�����}�(hKhh)��}�(hhhMV�hMhK8ubh�ubjI  NjJ  �jK  �jL  �ubejV  NjW  NjX  �ubehfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�(h�f/// The class RayHitID replaces the old ::Int32 value that stored information of an object/polygon.\n
�����}�(hKhh)��}�(hhhM�mhM�hKubh�ubh�\/// It conveniently allows to set objects with a polygon index, or read this information.\n
�����}�(hKhh)��}�(hhhMnhM�hKubh�ubh��/// @link SetSecond()@endlink/@link GetSecond()@endlink determine for a non-coplanar quadrangle which part of the quadrangle was stored (A-B-C or A-C-D). In case of a coplanar quadrangle "second" is not set.\n
�����}�(hKhh)��}�(hhhMonhM�hKubh�ubh�T/// @note	- Instead of <tt>if (lhit==0)</tt> write <tt>if (lhit.IsPopulated())</tt>
�����}�(hKhh)��}�(hhhMAohM�hKubh�ubh�@///				- Instead of <tt>lhit=0</tt> write <tt>lhit.Clear()</tt>
�����}�(hKhh)��}�(hhhM�ohM�hKubh�ubeh�X(  /// The class RayHitID replaces the old ::Int32 value that stored information of an object/polygon.\n
/// It conveniently allows to set objects with a polygon index, or read this information.\n
/// @link SetSecond()@endlink/@link GetSecond()@endlink determine for a non-coplanar quadrangle which part of the quadrangle was stored (A-B-C or A-C-D). In case of a coplanar quadrangle "second" is not set.\n
/// @note	- Instead of <tt>if (lhit==0)</tt> write <tt>if (lhit.IsPopulated())</tt>
///				- Instead of <tt>lhit=0</tt> write <tt>lhit.Clear()</tt>
�h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�SurfaceIntersection�����}�(hKhh)��}�(hhhM��hM#hKubh�ubhhh]�(j  )��}�(hj'  hj�  h]�hfj'  hghhhij'  h/NhkNhNhlNhmNhnK ho]�h�/// Default constructor.
�����}�(hKhh)��}�(hhhM��hM&hKubh�ubah��/// Default constructor.
�h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�jV  NjW  NjX  �ubj  )��}�(hj'  hj�  h]�hfj'  hghhhij'  h/NhkNhNhlNhmNhnK ho]�(h�=/// Creates an uninitialized surface intersection structure.
�����}�(hKhh)��}�(hhhM�hM+hKubh�ubh�8/// @param[in] dc									Dummy argument. Pass @ref DC.
�����}�(hKhh)��}�(hhhMD�hM,hKubh�ubeh��u/// Creates an uninitialized surface intersection structure.
/// @param[in] dc									Dummy argument. Pass @ref DC.
�h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�j?  )��}�(h�_DONTCONSTRUCT�hh�dc�����}�(hKhh)��}�(hhhM�hM.hK.ubh�ubjI  NjJ  �jK  �jL  �ubajV  NjW  NjX  �ubh)��}�(hNhj�  h]�h h�#ifdef __API_INTERN__�����}�(hK
hh)��}�(hhhM%�hM0hKubh�ububj;  )��}�(hh�op�����}�(hKhh)��}�(hhhML�hM1hKubh�ubhj�  h]�hfj�  hghhhijK  h/NhkNh�const RayObj*�hlNhmNhnK ho]�h�///< Intersected object.
�����}�(hKhh)��}�(hhhMQ�hM1hKubh�ubah��///< Intersected object.
�h�}�h��j7  �ubh)��}�(hNhj�  h]�h h�#else�����}�(hK
hh)��}�(hhhMj�hM2hKubh�ububj;  )��}�(hh�op�����}�(hKhh)��}�(hhhM��hM3hKubh�ubhj�  h]�hfj�  hghhhijK  h/NhkNh�const RayObject*�hlNhmNhnK ho]�h�///< Intersected object.
�����}�(hKhh)��}�(hhhM��hM3hKubh�ubah��///< Intersected object.
�h�}�h��j7  �ubh)��}�(hNhj�  h]�h h�#endif�����}�(hK
hh)��}�(hhhM��hM4hKubh�ububj;  )��}�(hh�id�����}�(hKhh)��}�(hhhM��hM6hKubh�ubhj�  h]�hfj�  hghhhijK  h/NhkNh�RayHitID�hlNhmNhnK ho]�h�///< Ray hit identity.
�����}�(hKhh)��}�(hhhM��hM6hKubh�ubah��///< Ray hit identity.
�h�}�h��j7  �ubj;  )��}�(hh�sid�����}�(hKhh)��}�(hhhM�hM9hK
ubh�ubhj�  h]�hfj  hghhhijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�!///< Sub-ID (only used for SPD).
�����}�(hKhh)��}�(hhhM�hM9hKubh�ubah��!///< Sub-ID (only used for SPD).
�h�}�h��j7  �ubehfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�+/// A structure for surface intersections.
�����}�(hKhh)��}�(hhhM��hM!hKubh�ubah��+/// A structure for surface intersections.
�h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�VPBitmap�����}�(hKhh)��}�(hhhMŎhM>hKubh�ubhhh]�hfj1  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�	Multipass�����}�(hKhh)��}�(hhhMܑhMJhKubh�ubhhh]�(j;  )��}�(hh�bmp�����}�(hKhh)��}�(hhhM��hMLhKubh�ubhj=  h]�hfjJ  hghhhijK  h/NhkNh�
VPBitmap**�hlNhmNhnK ho]�h�4///< @markInternal An array of @@ref cnt VPBitmaps.
�����}�(hKhh)��}�(hhhM�hMLhKubh�ubah��4///< @markInternal An array of @@ref cnt VPBitmaps.
�h�}�h��j7  �ubj;  )��}�(hh�ind�����}�(hKhh)��}�(hhhMB�hMMhKubh�ubhj=  h]�hfj]  hghhhijK  h/NhkNh�Int32*�hlNhmNhnK ho]�(h�5///< The index into the components for all layers.\n
�����}�(hKhh)��}�(hhhMR�hMMhKubh�ubh�///< @b Examples:
�����}�(hKhh)��}�(hhhM��hMNhKubh�ubh�///< - Standard rendering:
�����}�(hKhh)��}�(hhhMÒhMOhKubh�ubeh��b///< The index into the components for all layers.\n
///< @b Examples:
///< - Standard rendering:
�h�}�h��j7  �ubj;  )��}�(hh�result�����}�(hKhh)��}�(hhhM��hM_hKubh�ubhj=  h]�hfj|  hghhhijK  h/NhkNh�Float*�hlNhmNhnK ho]�(h�
/// @code
�����}�(hKhh)��}�(hhhM�hMWhKubh�ubh�/// cnt == 3
�����}�(hKhh)��}�(hhhM;�hMXhKubh�ubh�L/// cmp == 8 (R,G,B, Alpha, Diffuse R, Diffuse G, Diffuse B, Depth Channel)
�����}�(hKhh)��}�(hhhM]�hMYhKubh�ubh�/// ind[0] = 0
�����}�(hKhh)��}�(hhhM��hMZhKubh�ubh�/// ind[1] = 4
�����}�(hKhh)��}�(hhhM�hM[hKubh�ubh�/// ind[2] = 7
�����}�(hKhh)��}�(hhhM�hM\hKubh�ubh�R/// result[0..7] : R,G,B, Alpha, Diffuse R, Diffuse G, Diffuse B, Depth component
�����}�(hKhh)��}�(hhhM*�hM]hKubh�ubh�/// @endcode
�����}�(hKhh)��}�(hhhM��hM^hKubh�ubh�#///< The result of all components.
�����}�(hKhh)��}�(hhhM��hM_hKubh�ubeh�X  /// @code
/// cnt == 3
/// cmp == 8 (R,G,B, Alpha, Diffuse R, Diffuse G, Diffuse B, Depth Channel)
/// ind[0] = 0
/// ind[1] = 4
/// ind[2] = 7
/// result[0..7] : R,G,B, Alpha, Diffuse R, Diffuse G, Diffuse B, Depth component
/// @endcode
///< The result of all components.
�h�}�h��j7  �ubj;  )��}�(hh�diffuse�����}�(hKhh)��}�(hhhM�hMchKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Vector**�hlNhmNhnK ho]�h�///< The diffuse components.
�����}�(hKhh)��}�(hhhM��hMchKubh�ubah��///< The diffuse components.
�h�}�h��j7  �ubj;  )��}�(hh�diffuse_cnt�����}�(hKhh)��}�(hhhM��hMdhKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�'///< The number of diffuse components.
�����}�(hKhh)��}�(hhhM̖hMdhKubh�ubah��'///< The number of diffuse components.
�h�}�h��j7  �ubj;  )��}�(hh�specular�����}�(hKhh)��}�(hhhM��hMfhKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Vector**�hlNhmNhnK ho]�h�///< The specular components.
�����}�(hKhh)��}�(hhhM�hMfhKubh�ubah��///< The specular components.
�h�}�h��j7  �ubj;  )��}�(hh�specular_cnt�����}�(hKhh)��}�(hhhM:�hMghKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�(///< The number of specular components.
�����}�(hKhh)��}�(hhhMO�hMghK ubh�ubah��(///< The number of specular components.
�h�}�h��j7  �ubj;  )��}�(hh�shadow�����}�(hKhh)��}�(hhhM��hMihKubh�ubhj=  h]�hfj  hghhhijK  h/NhkNh�Vector**�hlNhmNhnK ho]�h�///< The shadow components.
�����}�(hKhh)��}�(hhhM��hMihKubh�ubah��///< The shadow components.
�h�}�h��j7  �ubj;  )��}�(hh�
shadow_cnt�����}�(hKhh)��}�(hhhM��hMjhKubh�ubhj=  h]�hfj  hghhhijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�&///< The number of shadow components.
�����}�(hKhh)��}�(hhhMϗhMjhKubh�ubah��&///< The number of shadow components.
�h�}�h��j7  �ubj;  )��}�(hh�light�����}�(hKhh)��}�(hhhM�hMlhKubh�ubhj=  h]�hfj1  hghhhijK  h/NhkNh�
RayLight**�hlNhmNhnK ho]�h��///< The array of the lights that create special light buffers. For example, if you render out a diffuse/specular pass for each light source all those lights will be listed here.
�����}�(hKhh)��}�(hhhM�hMlhKubh�ubah���///< The array of the lights that create special light buffers. For example, if you render out a diffuse/specular pass for each light source all those lights will be listed here.
�h�}�h��j7  �ubj;  )��}�(hh�	light_cnt�����}�(hKhh)��}�(hhhMИhMmhKubh�ubhj=  h]�hfjD  hghhhijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�///< The number of lights.
�����}�(hKhh)��}�(hhhM�hMmhKubh�ubah��///< The number of lights.
�h�}�h��j7  �ubj;  )��}�(hh�ochannel�����}�(hKhh)��}�(hhhM
�hMohKubh�ubhj=  h]�hfjW  hghhhijK  h/NhkNh�Float**�hlNhmNhnK ho]�(h�Y///< The object buffers, filled by @C4D. An array of @ref ochannel_cnt Float pointers.\n
�����}�(hKhh)��}�(hhhM�hMohKubh�ubh�D///< Each Float* directly points to the value of the object buffer.
�����}�(hKhh)��}�(hhhM��hMphKubh�ubeh���///< The object buffers, filled by @C4D. An array of @ref ochannel_cnt Float pointers.\n
///< Each Float* directly points to the value of the object buffer.
�h�}�h��j7  �ubj;  )��}�(hh�
ochannelid�����}�(hKhh)��}�(hhhMٙhMqhKubh�ubhj=  h]�hfjp  hghhhijK  h/NhkNh�Int32*�hlNhmNhnK ho]�h�*///< The channel ID of the object buffer.
�����}�(hKhh)��}�(hhhM�hMqhKubh�ubah��*///< The channel ID of the object buffer.
�h�}�h��j7  �ubj;  )��}�(hh�ochannel_cnt�����}�(hKhh)��}�(hhhM!�hMrhKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�#///< The number of object buffers.
�����}�(hKhh)��}�(hhhM6�hMrhK ubh�ubah��#///< The number of object buffers.
�h�}�h��j7  �ubj;  )��}�(hh�vp_direct_diffuse�����}�(hKhh)��}�(hhhMJ�hM�hKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Vector*�hlNhmNhnK ho]�h�9///< Direct diffuse from Reflectance Channel. @since R20
�����}�(hKhh)��}�(hhhMa�hM�hK#ubh�ubah��9///< Direct diffuse from Reflectance Channel. @since R20
�h�}�h��j7  �ubj;  )��}�(hh�vp_indirect_diffuse�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Vector*�hlNhmNhnK ho]�h�;///< Indirect diffuse from Reflectance Channel. @since R20
�����}�(hKhh)��}�(hhhM��hM�hK$ubh�ubah��;///< Indirect diffuse from Reflectance Channel. @since R20
�h�}�h��j7  �ubj;  )��}�(hh�vp_direct_specular�����}�(hKhh)��}�(hhhM�hM�hKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Vector*�hlNhmNhnK ho]�h�:///< Direct specular from Reflectance Channel. @since R20
�����}�(hKhh)��}�(hhhM�hM�hK$ubh�ubah��:///< Direct specular from Reflectance Channel. @since R20
�h�}�h��j7  �ubj;  )��}�(hh�vp_indirect_specular�����}�(hKhh)��}�(hhhM`�hM�hKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Vector*�hlNhmNhnK ho]�h�<///< Indirect specular from Reflectance Channel. @since R20
�����}�(hKhh)��}�(hhhMy�hM�hK%ubh�ubah��<///< Indirect specular from Reflectance Channel. @since R20
�h�}�h��j7  �ubj;  )��}�(hh�vp_reflectance_albedo�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Vector*�hlNhmNhnK ho]�h�4///< Reflectance Channel Diffuse Albedo. @since R21
�����}�(hKhh)��}�(hhhM٤hM�hK%ubh�ubah��4///< Reflectance Channel Diffuse Albedo. @since R21
�h�}�h��j7  �ubj;  )��}�(hh�vp_magicBulletLooks�����}�(hKhh)��}�(hhhM�hM�hKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Vector*�hlNhmNhnK ho]�h�;///< Channel without Magic Bullet Looks effect. @since R23
�����}�(hKhh)��}�(hhhM0�hM�hK$ubh�ubah��;///< Channel without Magic Bullet Looks effect. @since R23
�h�}�h��j7  �ubj;  )��}�(hh�aov_channel�����}�(hKhh)��}�(hhhMw�hM�hKubh�ubhj=  h]�hfj  hghhhijK  h/NhkNh�Vector**�hlNhmNhnK ho]�(h�f///< The object buffers, filled by @C4D. An array of @ref aov_channel_cnt Vector pointers. @since R21
�����}�(hKhh)��}�(hhhM��hM�hK ubh�ubh�P///< Each Vector* directly points to the value of the object buffer. @since R21
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubeh���///< The object buffers, filled by @C4D. An array of @ref aov_channel_cnt Vector pointers. @since R21
///< Each Vector* directly points to the value of the object buffer. @since R21
�h�}�h��j7  �ubj;  )��}�(hh�aov_channel_id�����}�(hKhh)��}�(hhhM`�hM�hKubh�ubhj=  h]�hfj!  hghhhijK  h/NhkNh�Int32*�hlNhmNhnK ho]�h�+///< The channel ID of the AOV. @since R21
�����}�(hKhh)��}�(hhhMv�hM�hK!ubh�ubah��+///< The channel ID of the AOV. @since R21
�h�}�h��j7  �ubj;  )��}�(hh�aov_channel_cnt�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj=  h]�hfj4  hghhhijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�$///< The number of AOVs. @since R21
�����}�(hKhh)��}�(hhhM��hM�hK!ubh�ubah��$///< The number of AOVs. @since R21
�h�}�h��j7  �ubehfjA  hghhhij�  h/NhkNhNhlNhmNhnK ho]�(h�B/// These values have to be filled by custom illumination models:
�����}�(hKhh)��}�(hhhM+�hMAhKubh�ubh�9/// - Standard: @ref diffuse, @ref specular, @ref shadow
�����}�(hKhh)��}�(hhhMm�hMBhKubh�ubh��/// - VP: @ref vp_diffuse, @ref vp_specular, @ref vp_shadow, @ref vp_illumination (later @ref vp_radiosity and @ref vp_caustics)
�����}�(hKhh)��}�(hhhM��hMChKubh�ubh�9/// These values have to be filled/processed by shaders:
�����}�(hKhh)��}�(hhhM'�hMDhKubh�ubh�i/// - Filled: @ref vp_mat_color, @ref vp_mat_luminance, @ref vp_mat_transparency, @ref vp_mat_reflection
�����}�(hKhh)��}�(hhhM`�hMEhKubh�ubh�=///							@ref vp_mat_environment, @ref vp_mat_specularcolor
�����}�(hKhh)��}�(hhhMɐhMFhKubh�ubh�6///							@ref vp_mat_specular, @ref vp_mat_diffusion
�����}�(hKhh)��}�(hhhM�hMGhKubh�ubh�>/// - Processed: @ref diffuse, @ref specular, @ref vp_ambient
�����}�(hKhh)��}�(hhhM<�hMHhKubh�ubeh�XO  /// These values have to be filled by custom illumination models:
/// - Standard: @ref diffuse, @ref specular, @ref shadow
/// - VP: @ref vp_diffuse, @ref vp_specular, @ref vp_shadow, @ref vp_illumination (later @ref vp_radiosity and @ref vp_caustics)
/// These values have to be filled/processed by shaders:
/// - Filled: @ref vp_mat_color, @ref vp_mat_luminance, @ref vp_mat_transparency, @ref vp_mat_reflection
///							@ref vp_mat_environment, @ref vp_mat_specularcolor
///							@ref vp_mat_specular, @ref vp_mat_diffusion
/// - Processed: @ref diffuse, @ref specular, @ref vp_ambient
�h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�BaseVolumeData�����}�(hKhh)��}�(hhhM�hM�hKubh�ubhhh]�(j  )��}�(hj'  hj{  h]�hfj'  hgh�	protected�����}�(hKhh)��}�(hhhM�hM�hKubh�ubhij'  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�jV  NjW  NjX  �ubj;  )��}�(hh�version�����}�(hKhh)��}�(hhhM3�hM�hKubh�ubhj{  h]�hfj�  hgh�public�����}�(hKhh)��}�(hhhM!�hM�hKubh�ubhijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�6///< [READ ONLY] The version number of the structure.
�����}�(hKhh)��}�(hhhMC�hM�hKubh�ubah��6///< [READ ONLY] The version number of the structure.
�h�}�h��j7  �ubj;  )��}�(hh�fps�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�(///< [READ ONLY] The frames per second.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubah��(///< [READ ONLY] The frames per second.
�h�}�h��j7  �ubj;  )��}�(hh�ambient�����}�(hKhh)��}�(hhhMçhM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Vector�hlNhmNhnK ho]�h�////< [READ ONLY] The global ambient component.
�����}�(hKhh)��}�(hhhMӧhM�hKubh�ubah��////< [READ ONLY] The global ambient component.
�h�}�h��j7  �ubj;  )��}�(hh�time�����}�(hKhh)��}�(hhhM�hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Float�hlNhmNhnK ho]�h�.///< [READ ONLY] The current time in seconds.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubah��.///< [READ ONLY] The current time in seconds.
�h�}�h��j7  �ubj;  )��}�(hh�col�����}�(hKhh)��}�(hhhMT�hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Vector�hlNhmNhnK ho]�h�r///< [READ WRITE] Set the calculated color within MaterialData::CalcSurface() and MaterialData::CalcVolumetric().
�����}�(hKhh)��}�(hhhMb�hM�hKubh�ubah��r///< [READ WRITE] Set the calculated color within MaterialData::CalcSurface() and MaterialData::CalcVolumetric().
�h�}�h��j7  �ubj;  )��}�(hh�trans�����}�(hKhh)��}�(hhhMިhM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Vector�hlNhmNhnK ho]�h��///< [READ WRITE] Set the calculated transparency within MaterialData::CalcSurface(), MaterialData::CalcTransparency() and MaterialData::CalcVolumetric().
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubah���///< [READ WRITE] Set the calculated transparency within MaterialData::CalcSurface(), MaterialData::CalcTransparency() and MaterialData::CalcVolumetric().
�h�}�h��j7  �ubj;  )��}�(hh�refl�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj  hgj�  hijK  h/NhkNh�Vector�hlNhmNhnK ho]�h�T///< [READ WRITE] Set the calculated reflection within MaterialData::CalcSurface().
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubah��T///< [READ WRITE] Set the calculated reflection within MaterialData::CalcSurface().
�h�}�h��j7  �ubj;  )��}�(hh�alpha�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj  hgj�  hijK  h/NhkNh�Float�hlNhmNhnK ho]�h�M///< [READ WRITE] Set the calculated alpha within MaterialData::CalcAlpha().
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubah��M///< [READ WRITE] Set the calculated alpha within MaterialData::CalcAlpha().
�h�}�h��j7  �ubj;  )��}�(hh�tray�����}�(hKhh)��}�(hhhMd�hM�hK
ubh�ubhj{  h]�hfj2  hgj�  hijK  h/NhkNh�Ray*�hlNhmNhnK ho]�h��///< [READ WRITE] The transmitted vector (can be modified in MaterialData::ChangeNormal()), only valid if shader sets @ref VOLUMEINFO::TRANSPARENCY and only during MaterialData::CalcSurface().
�����}�(hKhh)��}�(hhhMs�hM�hKubh�ubah���///< [READ WRITE] The transmitted vector (can be modified in MaterialData::ChangeNormal()), only valid if shader sets @ref VOLUMEINFO::TRANSPARENCY and only during MaterialData::CalcSurface().
�h�}�h��j7  �ubj;  )��}�(hh�rray�����}�(hKhh)��}�(hhhM=�hM�hK
ubh�ubhj{  h]�hfjE  hgj�  hijK  h/NhkNh�Ray*�hlNhmNhnK ho]�h��///< [READ WRITE] The reflected vector (can be modified in MaterialData::ChangeNormal()), only valid if shader sets @ref VOLUMEINFO::REFLECTION and only during MaterialData::CalcSurface().
�����}�(hKhh)��}�(hhhML�hM�hKubh�ubah���///< [READ WRITE] The reflected vector (can be modified in MaterialData::ChangeNormal()), only valid if shader sets @ref VOLUMEINFO::REFLECTION and only during MaterialData::CalcSurface().
�h�}�h��j7  �ubj;  )��}�(hh�p�����}�(hKhh)��}�(hhhM�hM�hKubh�ubhj{  h]�hfjX  hgj�  hijK  h/NhkNh�Vector64�hlNhmNhnK ho]�h�\///< [READ WRITE] The surface point, this can only be modified by MaterialData::Displace().
�����}�(hKhh)��}�(hhhM!�hM�hKubh�ubah��\///< [READ WRITE] The surface point, this can only be modified by MaterialData::Displace().
�h�}�h��j7  �ubj;  )��}�(hh�bumpn�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfjk  hgj�  hijK  h/NhkNh�Vector64�hlNhmNhnK ho]�h�5///< [READ WRITE] The surface phong and bump normal.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubah��5///< [READ WRITE] The surface phong and bump normal.
�h�}�h��j7  �ubj;  )��}�(hh�ray�����}�(hKhh)��}�(hhhM֬hM�hK
ubh�ubhj{  h]�hfj~  hgj�  hijK  h/NhkNh�Ray*�hlNhmNhnK ho]�h�R///< [READ ONLY] The current eye ray. Always valid, not @formatConstant{nullptr}.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubah��R///< [READ ONLY] The current eye ray. Always valid, not @formatConstant{nullptr}.
�h�}�h��j7  �ubj;  )��}�(hh�orign�����}�(hKhh)��}�(hhhMA�hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Vector64�hlNhmNhnK ho]�h�.///< [READ ONLY] The original surface normal.
�����}�(hKhh)��}�(hhhMP�hM�hKubh�ubah��.///< [READ ONLY] The original surface normal.
�h�}�h��j7  �ubj;  )��}�(hh�n�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Vector64�hlNhmNhnK ho]�h�+///< [READ ONLY] The surface phong normal.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubah��+///< [READ ONLY] The surface phong normal.
�h�}�h��j7  �ubj;  )��}�(hh�dispn�����}�(hKhh)��}�(hhhM̭hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Vector64�hlNhmNhnK ho]�h�7///< [READ ONLY] The suggested displacement direction.
�����}�(hKhh)��}�(hhhMۭhM�hKubh�ubah��7///< [READ ONLY] The suggested displacement direction.
�h�}�h��j7  �ubj;  )��}�(hh�dist�����}�(hKhh)��}�(hhhM�hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Float64�hlNhmNhnK ho]�h�Q///< [READ ONLY] The distance between @ref p and @c ray->p, i.e. the ray length.
�����}�(hKhh)��}�(hhhM,�hM�hKubh�ubah��Q///< [READ ONLY] The distance between @ref p and @c ray->p, i.e. the ray length.
�h�}�h��j7  �ubj;  )��}�(hh�cosc�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Float64�hlNhmNhnK ho]�h�C///< [READ ONLY] The angle between ray vector and unbumped normal.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubah��C///< [READ ONLY] The angle between ray vector and unbumped normal.
�h�}�h��j7  �ubj;  )��}�(hh�uvw�����}�(hKhh)��}�(hhhM�hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Vector�hlNhmNhnK ho]�h�V///< [READ ONLY] The surface UVW coordinates, this is invalid for volumetric shaders.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubah��V///< [READ ONLY] The surface UVW coordinates, this is invalid for volumetric shaders.
�h�}�h��j7  �ubj;  )��}�(hh�delta�����}�(hKhh)��}�(hhhMS�hM�hKubh�ubhj{  h]�hfj  hgj�  hijK  h/NhkNh�Vector�hlNhmNhnK ho]�(h�o///< [READ ONLY] The MIP sample radius. Defines the radius for the area around UVW that needs to be sampled.\n
�����}�(hKhh)��}�(hhhMb�hM�hKubh�ubh�Y///< If this value is ignored by a shader, it will work, but produce aliasing artefacts.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubeh���///< [READ ONLY] The MIP sample radius. Defines the radius for the area around UVW that needs to be sampled.\n
///< If this value is ignored by a shader, it will work, but produce aliasing artefacts.
�h�}�h��j7  �ubj;  )��}�(hh�lhit�����}�(hKhh)��}�(hhhMH�hM�hKubh�ubhj{  h]�hfj  hgj�  hijK  h/NhkNh�RayHitID�hlNhmNhnK ho]�h�'///< [READ ONLY] The surface identity.
�����}�(hKhh)��}�(hhhMW�hM�hKubh�ubah��'///< [READ ONLY] The surface identity.
�h�}�h��j7  �ubj;  )��}�(hh�tex�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj/  hgj�  hijK  h/NhkNh�const TexData*�hlNhmNhnK ho]�h�D///< [READ ONLY] The surface texture, @b never change this pointer.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubah��D///< [READ ONLY] The surface texture, @b never change this pointer.
�h�}�h��j7  �ubj;  )��}�(hh�raydepth�����}�(hKhh)��}�(hhhM�hM�hKubh�ubhj{  h]�hfjB  hgj�  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�(h�.///< [READ ONLY] The depth of the actual ray.
�����}�(hKhh)��}�(hhhM-�hM�hKubh�ubh�,///< @note @em 0 during shadow calculation.
�����}�(hKhh)��}�(hhhMn�hM�hKubh�ubeh��Z///< [READ ONLY] The depth of the actual ray.
///< @note @em 0 during shadow calculation.
�h�}�h��j7  �ubj;  )��}�(hh�
calc_trans�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj[  hgj�  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�(h�=///< [READ ONLY] Specifies if transparency will be rendered:
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�///< - 0 No transparency.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�///< - 1 No refractions.
�����}�(hKhh)��}�(hhhM4�hM�hKubh�ubh�///< - 2 Full calculation.
�����}�(hKhh)��}�(hhhM`�hM�hKubh�ubeh���///< [READ ONLY] Specifies if transparency will be rendered:
///< - 0 No transparency.
///< - 1 No refractions.
///< - 2 Full calculation.
�h�}�h��j7  �ubj;  )��}�(hh�	calc_refl�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�(h�<///< [READ ONLY] Specifies if reflections will be rendered:
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�///< - 0 No reflection.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�///< - 1 Only sky/floor.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�///< - 2 Full calculation.
�����}�(hKhh)��}�(hhhM<�hM�hKubh�ubeh���///< [READ ONLY] Specifies if reflections will be rendered:
///< - 0 No reflection.
///< - 1 Only sky/floor.
///< - 2 Full calculation.
�h�}�h��j7  �ubj;  )��}�(hh�calc_shadow�����}�(hKhh)��}�(hhhM`�hM�hK
ubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Bool�hlNhmNhnK ho]�h�9///< [READ ONLY] Specifies, if shadows will be rendered.
�����}�(hKhh)��}�(hhhMr�hM�hKubh�ubah��9///< [READ ONLY] Specifies, if shadows will be rendered.
�h�}�h��j7  �ubj;  )��}�(hh�
calc_illum�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�(h�@///< [READ ONLY] Specifies, if illumination will be rendered.\n
�����}�(hKhh)��}�(hhhMǴhM�hKubh�ubh��///< If this value is @em 0 then VolumeData::CalcSurface() should directly return the surface color without illumination (also, no bump mapping is needed in VolumeData::ChangeNormal() etc.).
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh��///< This technique is used for some types of objects like the sky. @c Illuminance1 automatically takes care of @ref calc_illum.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubeh�X�  ///< [READ ONLY] Specifies, if illumination will be rendered.\n
///< If this value is @em 0 then VolumeData::CalcSurface() should directly return the surface color without illumination (also, no bump mapping is needed in VolumeData::ChangeNormal() etc.).
///< This technique is used for some types of objects like the sky. @c Illuminance1 automatically takes care of @ref calc_illum.
�h�}�h��j7  �ubj;  )��}�(hh�calc_mip�����}�(hKhh)��}�(hhhMw�hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�(h�?///< [READ ONLY] Specifies if MIP calculations will be done.\n
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh��///< If this value is @em 0 then no MIP mapping needs to be calculated. @ref calc_mip can in some cases be false, even if the shader sets @ref VOLUMEINFO::MIPSAT.\n
�����}�(hKhh)��}�(hhhMڶhM�hKubh�ubh�p///< If @ref calc_mip is @formatConstant{false} you should not access MIP/SAT variables such as @ref delta etc.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubeh�XT  ///< [READ ONLY] Specifies if MIP calculations will be done.\n
///< If this value is @em 0 then no MIP mapping needs to be calculated. @ref calc_mip can in some cases be false, even if the shader sets @ref VOLUMEINFO::MIPSAT.\n
///< If @ref calc_mip is @formatConstant{false} you should not access MIP/SAT variables such as @ref delta etc.
�h�}�h��j7  �ubj;  )��}�(hh�pp�����}�(hKhh)��}�(hhhM�hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Vector�hlNhmNhnK ho]�(h�4///< [READ ONLY] MIP corner points in global space.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubh�9///< @note Only valid if @ref VOLUMEINFO::MIPSAT is set.
�����}�(hKhh)��}�(hhhMc�hM�hKubh�ubeh��m///< [READ ONLY] MIP corner points in global space.
///< @note Only valid if @ref VOLUMEINFO::MIPSAT is set.
�h�}�h��j7  �ubj;  )��}�(hh�nn�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj  hgj�  hijK  h/NhkNh�Vector�hlNhmNhnK ho]�(h�?///< [READ ONLY] MIP normals of the three other corner points.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubh�9///< @note Only valid if @ref VOLUMEINFO::MIPSAT is set.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubeh��x///< [READ ONLY] MIP normals of the three other corner points.
///< @note Only valid if @ref VOLUMEINFO::MIPSAT is set.
�h�}�h��j7  �ubj;  )��}�(hh�raybits�����}�(hKhh)��}�(hhhMK�hM�hKubh�ubhj{  h]�hfj(  hgj�  hijK  h/NhkNh�RAYBIT�hlNhmNhnK ho]�h�=///< [READ ONLY] The ray information: @enumerateEnum{RAYBIT}
�����}�(hKhh)��}�(hhhM[�hM�hKubh�ubah��=///< [READ ONLY] The ray information: @enumerateEnum{RAYBIT}
�h�}�h��j7  �ubj;  )��}�(hh�xlight�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj;  hgj�  hijK  h/NhkNh�const RayLight*�hlNhmNhnK ho]�h�_///< The light source during shadow evaluation. Can be @formatConstant{nullptr}, always check.
�����}�(hKhh)��}�(hhhM��hM�hK ubh�ubah��_///< The light source during shadow evaluation. Can be @formatConstant{nullptr}, always check.
�h�}�h��j7  �ubj;  )��}�(hh�op�����}�(hKhh)��}�(hhhM(�hM�hKubh�ubhj{  h]�hfjN  hgj�  hijK  h/NhkNh�const RayObject*�hlNhmNhnK ho]�h�@///< The object. Can be @formatConstant{nullptr}, always check.
�����}�(hKhh)��}�(hhhM3�hM�hKubh�ubah��@///< The object. Can be @formatConstant{nullptr}, always check.
�h�}�h��j7  �ubj;  )��}�(hh�recursion_id�����}�(hKhh)��}�(hhhM~�hM�hKubh�ubhj{  h]�hfja  hgj�  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�B///< [READ WRITE] The plugin ID of data passed through recursion.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubah��B///< [READ WRITE] The plugin ID of data passed through recursion.
�h�}�h��j7  �ubj;  )��}�(hh�recursion_data�����}�(hKhh)��}�(hhhMݺhM�hKubh�ubhj{  h]�hfjt  hgj�  hijK  h/NhkNh�void*�hlNhmNhnK ho]�h�@///< [READ WRITE] The address of data passed through recursion.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubah��@///< [READ WRITE] The address of data passed through recursion.
�h�}�h��j7  �ubj;  )��}�(hh�	multipass�����}�(hKhh)��}�(hhhM=�hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�
Multipass*�hlNhmNhnK ho]�h�0///< [READ WRITE] To be filled for multipasses.
�����}�(hKhh)��}�(hhhMN�hM�hKubh�ubah��0///< [READ WRITE] To be filled for multipasses.
�h�}�h��j7  �ubj;  )��}�(hh�back_p�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Vector�hlNhmNhnK ho]�h��///< [READ ONLY] The back-projected point (StickTextureTag) will be generated if the shader sets the flag @ref VOLUMEINFO::TRANSFORM or @ref SHADERINFO::TRANSFORM for a channel shader.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubah���///< [READ ONLY] The back-projected point (StickTextureTag) will be generated if the shader sets the flag @ref VOLUMEINFO::TRANSFORM or @ref SHADERINFO::TRANSFORM for a channel shader.
�h�}�h��j7  �ubj;  )��}�(hh�
back_delta�����}�(hKhh)��}�(hhhM\�hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Vector�hlNhmNhnK ho]�(h�Z///< [READ ONLY] This the 'spot size' (MIP mapping value) for the back-projected point.\n
�����}�(hKhh)��}�(hhhMn�hM�hKubh�ubh��///< The back-projected point (StickTextureTag) will be generated if the shader sets the flag @ref VOLUMEINFO::TRANSFORM (or @ref SHADERINFO::TRANSFORM if it is a channel shader).
�����}�(hKhh)��}�(hhhMۼhM�hKubh�ubeh�X  ///< [READ ONLY] This the 'spot size' (MIP mapping value) for the back-projected point.\n
///< The back-projected point (StickTextureTag) will be generated if the shader sets the flag @ref VOLUMEINFO::TRANSFORM (or @ref SHADERINFO::TRANSFORM if it is a channel shader).
�h�}�h��j7  �ubj;  )��}�(hh�
global_mip�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Float�hlNhmNhnK ho]�h�'///< [READ ONLY] The global MIP scale.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubah��'///< [READ ONLY] The global MIP scale.
�h�}�h��j7  �ubj;  )��}�(hh�sid�����}�(hKhh)��}�(hhhM޽hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�5///< [READ ONLY] Sub-polygon ID (only used for SPD).
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubah��5///< [READ ONLY] Sub-polygon ID (only used for SPD).
�h�}�h��j7  �ubj;  )��}�(hh�intersection�����}�(hKhh)��}�(hhhM�hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�SurfaceIntersection*�hlNhmNhnK ho]�h�W///< [READ ONLY] The intersection data. Can be @formatConstant{nullptr}, always check.
�����}�(hKhh)��}�(hhhM�hM�hK%ubh�ubah��W///< [READ ONLY] The intersection data. Can be @formatConstant{nullptr}, always check.
�h�}�h��j7  �ubj;  )��}�(hh�	mb_offset�����}�(hKhh)��}�(hhhMU�hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�Float�hlNhmNhnK ho]�h�m///< [READ ONLY] The motion blur time offset. (Between @em 0.0 and @em 1.0, only valid in Physical %Render.)
�����}�(hKhh)��}�(hhhMf�hM�hKubh�ubah��m///< [READ ONLY] The motion blur time offset. (Between @em 0.0 and @em 1.0, only valid in Physical %Render.)
�h�}�h��j7  �ubj;  )��}�(hh�
comp_color�����}�(hKhh)��}�(hhhM޿hM�hKubh�ubhj{  h]�hfj  hgj�  hijK  h/NhkNh�Vector�hlNhmNhnK ho]�h�A///< [READ WRITE] The diffuse component of the calculated color.
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubah��A///< [READ WRITE] The diffuse component of the calculated color.
�h�}�h��j7  �ubj;  )��}�(hh�comp_specular�����}�(hKhh)��}�(hhhM;�hM�hKubh�ubhj{  h]�hfj%  hgj�  hijK  h/NhkNh�Vector�hlNhmNhnK ho]�h�B///< [READ WRITE] The specular component of the calculated color.
�����}�(hKhh)��}�(hhhMN�hM�hKubh�ubah��B///< [READ WRITE] The specular component of the calculated color.
�h�}�h��j7  �ubj;  )��}�(hh�comp_luminance�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj8  hgj�  hijK  h/NhkNh�Vector�hlNhmNhnK ho]�h�C///< [READ WRITE] The luminance component of the calculated color.
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubah��C///< [READ WRITE] The luminance component of the calculated color.
�h�}�h��j7  �ubj;  )��}�(hh�rtex�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfjK  hgj�  hijK  h/NhkNh�	TexEntry*�hlNhmNhnK ho]�h�C///< [READ ONLY] @markInternal The reflection textures. @since R16
�����}�(hKhh)��}�(hhhM�hM�hKubh�ubah��C///< [READ ONLY] @markInternal The reflection textures. @since R16
�h�}�h��j7  �ubj;  )��}�(hh�
rtex_count�����}�(hKhh)��}�(hhhM[�hM�hKubh�ubhj{  h]�hfj^  hgj�  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�Z///< [READ ONLY] @markInternal The number of reflection textures in @ref rtex. @since R16
�����}�(hKhh)��}�(hhhMm�hM�hKubh�ubah��Z///< [READ ONLY] @markInternal The number of reflection textures in @ref rtex. @since R16
�h�}�h��j7  �ubj;  )��}�(hh�elementIndex�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfjq  hgj�  hijK  h/NhkNh�Int32�hlNhmNhnK ho]�h��///< [READ ONLY] @markInternal Stores the index of the currently rendering hair. May be extended to other object types eventually. @since R19
�����}�(hKhh)��}�(hhhM��hM�hKubh�ubah���///< [READ ONLY] @markInternal Stores the index of the currently rendering hair. May be extended to other object types eventually. @since R19
�h�}�h��j7  �ubj;  )��}�(hh�displacementWeight�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhj{  h]�hfj�  hgj�  hijK  h/NhkNh�const RayPolyWeight*�hlNhmNhnK ho]�h�///< [READ ONLY] Private.
�����}�(hKhh)��}�(hhhM��hM�hK+ubh�ubah��///< [READ ONLY] Private.
�h�}�h��j7  �ubehfj  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�ChannelData�����}�(hKhh)��}�(hhhM��hM�hKubh�ubhhh]�(j  )��}�(hj'  hj�  h]�hfj'  hghhhij'  h/NhkNhNhlNhmNhnK ho]�h�/// Default constructor.
�����}�(hKhh)��}�(hhhM.�hM�hKubh�ubah��/// Default constructor.
�h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�jV  NjW  NjX  �ubj  )��}�(hj'  hj�  h]�hfj'  hghhhij'  h/NhkNhNhlNhmNhnK ho]�(h�Q/// Constructs a ChannelData that matches the current state of a BaseVolumeData.
�����}�(hKhh)��}�(hhhM"�hMhKubh�ubh�s/// @param[in] t_vd								The volume data to take @ref p, @ref n and @ref d from. @callerOwnsPointed{volume data}
�����}�(hKhh)��}�(hhhMt�hMhKubh�ubeh���/// Constructs a ChannelData that matches the current state of a BaseVolumeData.
/// @param[in] t_vd								The volume data to take @ref p, @ref n and @ref d from. @callerOwnsPointed{volume data}
�h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�j?  )��}�(h�BaseVolumeData*�hh�t_vd�����}�(hKhh)��}�(hhhMi�hMhK'ubh�ubjI  NjJ  �jK  �jL  �ubajV  NjW  NjX  �ubj;  )��}�(hh�p�����}�(hKhh)��}�(hhhM�hM	hKubh�ubhj�  h]�hfj�  hghhhijK  h/NhkNh�Vector�hlNhmNhnK ho]�h�:///< [READ ONLY] The texture position in UVW coordinates.
�����}�(hKhh)��}�(hhhM�hM	hKubh�ubah��:///< [READ ONLY] The texture position in UVW coordinates.
�h�}�h��j7  �ubj;  )��}�(hh�n�����}�(hKhh)��}�(hhhMV�hM
hKubh�ubhj�  h]�hfj�  hghhhijK  h/NhkNh�Vector�hlNhmNhnK ho]�h�%///< [READ ONLY] The surface normal.
�����}�(hKhh)��}�(hhhM]�hM
hKubh�ubah��%///< [READ ONLY] The surface normal.
�h�}�h��j7  �ubj;  )��}�(hh�d�����}�(hKhh)��}�(hhhM��hMhKubh�ubhj�  h]�hfj�  hghhhijK  h/NhkNh�Vector�hlNhmNhnK ho]�h�;///< [READ ONLY] The MIP sample radius in UVW coordinates.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubah��;///< [READ ONLY] The MIP sample radius in UVW coordinates.
�h�}�h��j7  �ubj;  )��}�(hh�t�����}�(hKhh)��}�(hhhM��hMhKubh�ubhj�  h]�hfj	  hghhhijK  h/NhkNh�Float�hlNhmNhnK ho]�h�.///< [READ ONLY] The current time in seconds.
�����}�(hKhh)��}�(hhhM��hMhKubh�ubah��.///< [READ ONLY] The current time in seconds.
�h�}�h��j7  �ubj;  )��}�(hh�texflag�����}�(hKhh)��}�(hhhM�hMhKubh�ubhj�  h]�hfj  hghhhijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�8///< [READ ONLY] The texture flags: @enumerateEnum{TEX}
�����}�(hKhh)��}�(hhhM!�hMhKubh�ubah��8///< [READ ONLY] The texture flags: @enumerateEnum{TEX}
�h�}�h��j7  �ubj;  )��}�(hh�vd�����}�(hKhh)��}�(hhhMf�hMhKubh�ubhj�  h]�hfj/  hghhhijK  h/NhkNh�VolumeData*�hlNhmNhnK ho]�h�J///< [READ ONLY] The volume information, can be @formatConstant{nullptr}.
�����}�(hKhh)��}�(hhhMn�hMhKubh�ubah��J///< [READ ONLY] The volume information, can be @formatConstant{nullptr}.
�h�}�h��j7  �ubj  )��}�(hh�GetCurrentCPU�����}�(hKhh)��}�(hhhM�hMhKubh�ubhj�  h]�hfjB  hghhhij  h/NhkNhNhlNhmNhnK ho]�(h�H/// Retrieves the current thread index on which the shader is executed.
�����}�(hKhh)��}�(hhhMR�hMhKubh�ubh�/// @since R16.038
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�x/// @note	<tt>%GetCurrentCPU()</tt> exists as a member of ChannelData and VolumeData, both yielding the same results.\n
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh��///				However if no VolumeData is present (and only then!) a channel shader calculation can also be called with ChannelData::vd set to @formatConstant{nullptr}.\n
�����}�(hKhh)��}�(hhhM(�hMhKubh�ubh�E///				In that case (or generally) use ChannelData::GetCurrentCPU().
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh��/// @return												The running thread index, which is guaranteed to be <tt>>= 0</tt> and smaller than the thread count that was passed during @c InitRender().
�����}�(hKhh)��}�(hhhM�hMhKubh�ubeh�X_  /// Retrieves the current thread index on which the shader is executed.
/// @since R16.038
/// @note	<tt>%GetCurrentCPU()</tt> exists as a member of ChannelData and VolumeData, both yielding the same results.\n
///				However if no VolumeData is present (and only then!) a channel shader calculation can also be called with ChannelData::vd set to @formatConstant{nullptr}.\n
///				In that case (or generally) use ChannelData::GetCurrentCPU().
/// @return												The running thread index, which is guaranteed to be <tt>>= 0</tt> and smaller than the thread count that was passed during @c InitRender().
�h�}�h��j7  �j8  �j9  �j:  �Int32�j<  �h�]�jV  NjW  NjX  �ubehfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubh\)��}�(hh�MSG_GETALLASSETS�����}�(hKhh)��}�(hhhM��hMhK	ubh�ubhhh]�hfj{  hghhhihjh/NhkNhNhlNhmNhnK ho]�(h�/// @addtogroup MSG_SHADER
�����}�(hKhh)��}�(hhhMU�hMhKubh�ubh�/// @ingroup group_enumeration
�����}�(hKhh)��}�(hhhMp�hMhKubh�ubh�/// @{
�����}�(hKhh)��}�(hhhM��hMhKubh�ubh�<///< @see MSG_MULTI_CLEARSUGGESTEDFOLDER MSG_RENAMETEXTURES
�����}�(hKhh)��}�(hhhM��hM hKubh�ubeh��}/// @addtogroup MSG_SHADER
/// @ingroup group_enumeration
/// @{
///< @see MSG_MULTI_CLEARSUGGESTEDFOLDER MSG_RENAMETEXTURES
�h�}�h��h�]�ubh\)��}�(hh�MSG_RENAMETEXTURES�����}�(hKhh)��}�(hhhM=�hM!hK	ubh�ubhhh]�hfj�  hghhhihjh/NhkNhNhlNhmNhnK ho]�h�h	h�}�h��h�]�ubj�  )��}�(hh�RenameTextureMessage�����}�(hKhh)��}�(hhhM��hM)hKubh�ubhhh]�(j  )��}�(hj'  hj�  h]�hfj'  hghhhij'  h/NhkNhNhlNhmNhnK ho]�h�/// Default constructor.
�����}�(hKhh)��}�(hhhM_�hM,hKubh�ubah��/// Default constructor.
�h�}�h��j7  �j8  �j9  �j:  j1  j<  �h�]�jV  NjW  NjX  �ubj;  )��}�(hh�oldname�����}�(hKhh)��}�(hhhM)�hM0hKubh�ubhj�  h]�hfj�  hghhhijK  h/NhkNh�Filename�hlNhmNhnK ho]�h�///< Old filename.
�����}�(hKhh)��}�(hhhM5�hM0hKubh�ubah��///< Old filename.
�h�}�h��j7  �ubj;  )��}�(hh�newname�����}�(hKhh)��}�(hhhMT�hM1hKubh�ubhj�  h]�hfj�  hghhhijK  h/NhkNh�Filename�hlNhmNhnK ho]�h�///< New filename.
�����}�(hKhh)��}�(hhhM`�hM1hKubh�ubah��///< New filename.
�h�}�h��j7  �ubj;  )��}�(hh�doc�����}�(hKhh)��}�(hhhM��hM2hKubh�ubhj�  h]�hfj�  hghhhijK  h/NhkNh�BaseDocument*�hlNhmNhnK ho]�h�///< Document.
�����}�(hKhh)��}�(hhhM��hM2hKubh�ubah��///< Document.
�h�}�h��j7  �ubj;  )��}�(hh�	changecnt�����}�(hKhh)��}�(hhhM��hM3hKubh�ubhj�  h]�hfj�  hghhhijK  h/NhkNh�Int32�hlNhmNhnK ho]�h�7///< Change count. Increase this if to adjust a value.
�����}�(hKhh)��}�(hhhM��hM3hKubh�ubah��7///< Change count. Increase this if to adjust a value.
�h�}�h��j7  �ubj;  )��}�(hh�noundo�����}�(hKhh)��}�(hhhM��hM4hKubh�ubhj�  h]�hfj  hghhhijK  h/NhkNh�Bool�hlNhmNhnK ho]�(h��///< Set this to @formatConstant{true} when sending @ref MSG_RENAMETEXTURES to stop an undo getting added when filenames (textures etc.) are renamed.\n
�����}�(hKhh)��}�(hhhM �hM4hKubh�ubh��///< Also check this when receiving @ref MSG_RENAMETEXTURES (e.g. morphs/Xrefs check for this message to rename their external filenames).
�����}�(hKhh)��}�(hhhM��hM5hKubh�ubeh�X#  ///< Set this to @formatConstant{true} when sending @ref MSG_RENAMETEXTURES to stop an undo getting added when filenames (textures etc.) are renamed.\n
///< Also check this when receiving @ref MSG_RENAMETEXTURES (e.g. morphs/Xrefs check for this message to rename their external filenames).
�h�}�h��j7  �ubehfj�  hghhhij�  h/NhkNhNhlNhmNhnK ho]�(h�</// Message struct for the @ref MSG_RENAMETEXTURES message.
�����}�(hKhh)��}�(hhhMb�hM%hKubh�ubh��/// This message is broadcast to all scene elements when a bitmap image was renamed (e.g. by Make Project or by @BP3D) and all shaders etc. need to adjust the name.\n
�����}�(hKhh)��}�(hhhM��hM&hKubh�ubh�D/// If something is adjusted then @ref changecnt must be increased.
�����}�(hKhh)��}�(hhhME�hM'hKubh�ubeh�X'  /// Message struct for the @ref MSG_RENAMETEXTURES message.
/// This message is broadcast to all scene elements when a bitmap image was renamed (e.g. by Make Project or by @BP3D) and all shaders etc. need to adjust the name.\n
/// If something is adjusted then @ref changecnt must be increased.
�h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�
VPFragment�����}�(hKhh)��}�(hhhM�hM;hKubh�ubhhh]�(j;  )��}�(hh�id�����}�(hKhh)��}�(hhhM.�hM=hKubh�ubhj=  h]�hfjJ  hghhhijK  h/NhkNh�RayHitID�hlNhmNhnK ho]�h�///< Fragment ID.
�����}�(hKhh)��}�(hhhM6�hM=hKubh�ubah��///< Fragment ID.
�h�}�h��j7  �ubj;  )��}�(hh�weight�����}�(hKhh)��}�(hhhM��hM@hKubh�ubhj=  h]�hfj]  hghhhijK  h/NhkNh�Int16�hlNhmNhnK ho]�h�X///< The weight of the fragment. @em 256 = @em 16x16 = full pixel; @em 0 = empty pixel.
�����}�(hKhh)��}�(hhhM��hM@hKubh�ubah��X///< The weight of the fragment. @em 256 = @em 16x16 = full pixel; @em 0 = empty pixel.
�h�}�h��j7  �ubj;  )��}�(hh�op�����}�(hKhh)��}�(hhhM�hMAhKubh�ubhj=  h]�hfjp  hghhhijK  h/NhkNh�
RayObject*�hlNhmNhnK ho]�h�///< Fragment object.
�����}�(hKhh)��}�(hhhM'�hMAhKubh�ubah��///< Fragment object.
�h�}�h��j7  �ubj;  )��}�(hh�color�����}�(hKhh)��}�(hhhMI�hMChKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Vector32�hlNhmNhnK ho]�h�///< Fragment color.
�����}�(hKhh)��}�(hhhMR�hMChKubh�ubah��///< Fragment color.
�h�}�h��j7  �ubj;  )��}�(hh�z�����}�(hKhh)��}�(hhhMr�hMEhKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Float�hlNhmNhnK ho]�h�D///< Z depth at the @link subx@endlink/@link suby@endlink position.
�����}�(hKhh)��}�(hhhMy�hMEhKubh�ubah��D///< Z depth at the @link subx@endlink/@link suby@endlink position.
�h�}�h��j7  �ubj;  )��}�(hh�p�����}�(hKhh)��}�(hhhM��hMFhKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Vector�hlNhmNhnK ho]�h�V///< Global intersection point at the @link subx@endlink/@link suby@endlink position.
�����}�(hKhh)��}�(hhhM��hMFhKubh�ubah��V///< Global intersection point at the @link subx@endlink/@link suby@endlink position.
�h�}�h��j7  �ubj;  )��}�(hh�n�����}�(hKhh)��}�(hhhM.�hMGhKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�Vector�hlNhmNhnK ho]�h�C///< Normal at the @link subx@endlink/@link suby@endlink position.
�����}�(hKhh)��}�(hhhM5�hMGhKubh�ubah��C///< Normal at the @link subx@endlink/@link suby@endlink position.
�h�}�h��j7  �ubj;  )��}�(hh�next�����}�(hKhh)��}�(hhhM��hMIhKubh�ubhj=  h]�hfj�  hghhhijK  h/NhkNh�VPFragment*�hlNhmNhnK ho]�h�I///< The next fragment, or @formatConstant{nullptr} if this is the last.
�����}�(hKhh)��}�(hhhM��hMIhKubh�ubah��I///< The next fragment, or @formatConstant{nullptr} if this is the last.
�h�}�h��j7  �ubehfjA  hghhhij�  h/NhkNhNhlNhmNhnK ho]�h�"/// @see VolumeData::GetFragments
�����}�(hKhh)��}�(hhhM��hM9hKubh�ubah��"/// @see VolumeData::GetFragments
�h�}�h��j�  ]�j�  Nj�  Nj7  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �jX  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  }�ubh)��}�(hNhhh]�h h� #ifdef CINEWARE_NAMESPACE_ENABLE�����}�(hK
hh)��}�(hhhM��hMLhKubh�ububh)��}�(hNhhh]�h h�CINEWARE_NAMESPACE_END�����}�(hK
hh)��}�(hhhM��hMMhKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hMNhKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hMPhKubh�ububehfhhghhhi�	namespace�h/NhkNhNhlNhmNhnK ho]�h�h	h�}�h���preprocessorConditions�]��root�hh ]�(hh)h0h4h8h<h@hIhRh]h�h�h�h�h�j  jY  j�  j�  j�  j�  j  j  j.  j>  jN  j^  jn  j~  j�  j�  j�  j�  j�  j�  j�  j�  j  j!  j@  jL  jX  jd  jp  j|  j�  j�  j�  j�  j�  j�  j�  j�  j�  j  j  j  j+  j7  jC  jO  j[  jg  js  j  j�  j�  j�  j�  j�  j�  j�  j�  j�  j  j�  j�  j3	  jX	  jd	  jp	  j  j�  j�  j�  j-  j=  j{  j�  jw  j�  j�  j=  j�  j�  j�  j  e�containsResourceId���registry��j�  ���hxx1�N�hxx2�N�snippets�}��minIndentation�K �maxIndentation�K �firstMember���forwardHeaders���ub.