���Y      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��aD:\C4D_MMD_Tool\sdk_r20\frameworks\cinema.framework\source\c4d_customgui\customgui_bitmapbutton.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhM7hKhKubh�ububh)��}�(hNhhh]�h h�#ifdef _INTERNAL_BITMAPBUTTON_�����}�(hK
hh)��}�(hhhM~hK
hKubh�ububh �Define���)��}�(hh�_INTERNAL_BASECUSTOM_�����}�(hKhh)��}�(hhhM�hKhK
ubh�ubhhh]��
simpleName�h6�access��public��kind��#define��template�N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���params�]�ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hKhKubh�ububh �Include���)��}�(h�customgui_base.h�hhh]��quote��"�h@NubhW)��}�(h�c4d_basecontainer.h�hhh]�h\h]h@NubhW)��}�(h�c4d_customdatatype.h�hhh]�h\h]h@NubhW)��}�(h�lib_description.h�hhh]�h\h]h@Nubh1)��}�(hh�CUSTOMGUI_BITMAPBUTTON�����}�(hKhh)��}�(hhhMfhKhK	ubh�ubhhh]�h;hnh<h=h>h?h@NhANhNhBNhCNhDK hE]�h�!/// Bitmap button custom GUI ID.
�����}�(hKhh)��}�(hhhM=hKhKubh�ubahG�!/// Bitmap button custom GUI ID.
�hH}�hJ�hK]�ubh1)��}�(hh�CUSTOMDATATYPE_BITMAPBUTTON�����}�(hKhh)��}�(hhhM�hKhK	ubh�ubhhh]�h;h�h<h=h>h?h@NhANhNhBNhCNhDK hE]�h�"/// Bitmap button custom data ID.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubahG�"/// Bitmap button custom data ID.
�hH}�hJ�hK]�ubh1)��}�(hh�BITMAPBUTTON_BORDER�����}�(hKhh)��}�(hhhM4hKhK	ubh�ubhhh]�h;h�h<h=h>h?h@NhANhNhBNhCNhDK hE]�(h�//// @addtogroup BITMAPBUTTON_CUSTOMGUISETTINGS
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�/// @ingroup CUSTOMGUISETTINGS
�����}�(hKhh)��}�(hhhMhKhKubh�ubh�/// @{
�����}�(hKhh)��}�(hhhM%hKhKubh�ubh�Q///< @note Used for the pressed button state if ::BITMAPBUTTON_OUTBORDER is set.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubehG��/// @addtogroup BITMAPBUTTON_CUSTOMGUISETTINGS
/// @ingroup CUSTOMGUISETTINGS
/// @{
///< @note Used for the pressed button state if ::BITMAPBUTTON_OUTBORDER is set.
�hH}�hJ�hK]�ubh1)��}�(hh�BITMAPBUTTON_BUTTON�����}�(hKhh)��}�(hhhM�hKhK	ubh�ubhhh]�h;h�h<h=h>h?h@NhANhNhBNhCNhDK hE]�h��///< @note To detect when the button is pressed in a description check if the ::DESCFLAGS_SET::USERINTERACTION flag is set in the NodeData::SetDParameter() call.
�����}�(hKhh)��}�(hhhMZhKhKubh�ubahG��///< @note To detect when the button is pressed in a description check if the ::DESCFLAGS_SET::USERINTERACTION flag is set in the NodeData::SetDParameter() call.
�hH}�hJ�hK]�ubh1)��}�(hh�BITMAPBUTTON_TOGGLE�����}�(hKhh)��}�(hhhMhK hK	ubh�ubhhh]�h;h�h<h=h>h?h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�hK]�ubh1)��}�(hh� BITMAPBUTTON_IGNORE_BITMAP_WIDTH�����}�(hKhh)��}�(hhhM\hK!hK	ubh�ubhhh]�h;h�h<h=h>h?h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�hK]�ubh1)��}�(hh�!BITMAPBUTTON_IGNORE_BITMAP_HEIGHT�����}�(hKhh)��}�(hhhM�hK"hK	ubh�ubhhh]�h;h�h<h=h>h?h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�hK]�ubh1)��}�(hh�BITMAPBUTTON_DRAWPOPUPBUTTON�����}�(hKhh)��}�(hhhMhK#hK	ubh�ubhhh]�h;h�h<h=h>h?h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�hK]�ubh1)��}�(hh�BITMAPBUTTON_TOOLTIP�����}�(hKhh)��}�(hhhMShK$hK	ubh�ubhhh]�h;h�h<h=h>h?h@NhANhNhBNhCNhDK hE]�(h�M///< @note Only work if @ref BITMAPBUTTON_BUTTON is @formatConstant{true}.\n
�����}�(hKhh)��}�(hhhM�hK%hKubh�ubh��///< To format the bitmap's button tooltip text use the "<b>" and "<br>" HTML tags. This is used internally to format the tooltip text for the palettes buttons. For example:
�����}�(hKhh)��}�(hhhMhK&hKubh�ubh�///< @code
�����}�(hKhh)��}�(hhhM�hK'hKubh�ubehGX  ///< @note Only work if @ref BITMAPBUTTON_BUTTON is @formatConstant{true}.\n
///< To format the bitmap's button tooltip text use the "<b>" and "<br>" HTML tags. This is used internally to format the tooltip text for the palettes buttons. For example:
///< @code
�hH}�hJ�hK]�ubh1)��}�(hh�BITMAPBUTTON_ICONID1�����}�(hKhh)��}�(hhhMhK*hK	ubh�ubhhh]�h;j  h<h=h>h?h@NhANhNhBNhCNhDK hE]�(h�I///  bc.SetString(BITMAPBUTTON_TOOLTIP, "<b>Bold Text</b><br>New line");
�����}�(hKhh)��}�(hhhMhK(hKubh�ubh�///  @endcode
�����}�(hKhh)��}�(hhhMihK)hKubh�ubehG�W///  bc.SetString(BITMAPBUTTON_TOOLTIP, "<b>Bold Text</b><br>New line");
///  @endcode
�hH}�hJ�hK]�ubh1)��}�(hh�BITMAPBUTTON_ICONID2�����}�(hKhh)��}�(hhhM�hK+hK	ubh�ubhhh]�h;j4  h<h=h>h?h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�hK]�ubh1)��}�(hh�BITMAPBUTTON_FORCE_SIZE�����}�(hKhh)��}�(hhhMj	hK,hK	ubh�ubhhh]�h;j@  h<h=h>h?h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�hK]�ubh1)��}�(hh�BITMAPBUTTON_SPECIAL�����}�(hKhh)��}�(hhhM�	hK-hK	ubh�ubhhh]�h;jL  h<h=h>h?h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�hK]�ubh1)��}�(hh�BITMAPBUTTON_NOBORDERDRAW�����}�(hKhh)��}�(hhhM�	hK.hK	ubh�ubhhh]�h;jX  h<h=h>h?h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�hK]�ubh1)��}�(hh�BITMAPBUTTON_OUTBORDER�����}�(hKhh)��}�(hhhM;
hK/hK	ubh�ubhhh]�h;jd  h<h=h>h?h@NhANhNhBNhCNhDK hE]�h�1///< @note Used if ::BITMAPBUTTON_BUTTON is set.
�����}�(hKhh)��}�(hhhM�
hK0hKubh�ubahG�1///< @note Used if ::BITMAPBUTTON_BUTTON is set.
�hH}�hJ�hK]�ubh1)��}�(hh�BITMAPBUTTON_BACKCOLOR�����}�(hKhh)��}�(hhhM�
hK1hK	ubh�ubhhh]�h;jw  h<h=h>h?h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�hK]�ubh1)��}�(hh�BITMAPBUTTON_MIRROR�����}�(hKhh)��}�(hhhMKhK2hK	ubh�ubhhh]�h;j�  h<h=h>h?h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�hK]�ubh1)��}�(hh�BITMAPBUTTON_STRING�����}�(hKhh)��}�(hhhM�hK3hK	ubh�ubhhh]�h;j�  h<h=h>h?h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�hK]�ubh �Class���)��}�(hh�
BaseList2D�����}�(hKhh)��}�(hhhMhK6hKubh�ubhhh]�h;j�  h<h=h>�class�h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ��bases�]��	interface�N�refKind�N�refClass�N�constRefClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent���forward���
singleImpl���ambiguousCalls�]��	selfCalls�]��methodNames�}�ubj�  )��}�(hh�BitmapButtonStruct�����}�(hKhh)��}�(hhhM�hK<hKubh�ubhhh]�(h �Function���)��}�(h�constructor�hj�  h]�h;j�  h<h�public�����}�(hKhh)��}�(hhhMhK>hKubh�ubh>j�  h@NhANhNhBNhCNhDK hE]�h�/// Default constructor.
�����}�(hKhh)��}�(hhhMyhK@hKubh�ubahG�/// Default constructor.
�hH}�hJ��static���explicit���deleted���retType��void��const��hK]��
observable�N�result�Nubj�  )��}�(hj�  hj�  h]�h;j�  h<j�  h>j�  h@NhANhNhBNhCNhDK hE]�(h�"/// Creates a bitmap button data.
�����}�(hKhh)��}�(hhhM�hKEhKubh�ubh�N/// @param[in] t_op								The object to send ::MSG_DESCRIPTION_GETBITMAP to.
�����}�(hKhh)��}�(hhhM�hKFhKubh�ubh�J/// @param[in] t_id								The ID for the DescriptionGetBitmap::id field.
�����}�(hKhh)��}�(hhhMhKGhKubh�ubh��/// @param[in] t_dirty						The dirty flag. Internally used to detect changes. If this flag changes on parameter set, a new MSG_DESCRIPTION_GETBITMAP will be emitted.
�����}�(hKhh)��}�(hhhMNhKHhKubh�ubehGXa  /// Creates a bitmap button data.
/// @param[in] t_op								The object to send ::MSG_DESCRIPTION_GETBITMAP to.
/// @param[in] t_id								The ID for the DescriptionGetBitmap::id field.
/// @param[in] t_dirty						The dirty flag. Internally used to detect changes. If this flag changes on parameter set, a new MSG_DESCRIPTION_GETBITMAP will be emitted.
�hH}�hJ�j�  �j�  �j�  �j�  j�  j�  �hK]�(h �	Parameter���)��}�(h�BaseList2D*�hh�t_op�����}�(hKhh)��}�(hhhMshKJhK"ubh�ub�default�N�pack���input���output��ubj   )��}�(h�const DescID&�hh�t_id�����}�(hKhh)��}�(hhhM�hKJhK6ubh�ubj
  Nj  �j  �j  �ubj   )��}�(h�Int32�hh�t_dirty�����}�(hKhh)��}�(hhhM�hKJhKBubh�ubj
  Nj  �j  �j  �ubej�  Nj�  Nubh �Variable���)��}�(hh�op�����}�(hKhh)��}�(hhhM�hKLhKubh�ubhj�  h]�h;j&  h<j�  h>�variable�h@NhANh�BaseList2D*�hBNhCNhDK hE]�h�8///< The object to send ::MSG_DESCRIPTION_GETBITMAP to.
�����}�(hKhh)��}�(hhhM�hKLhKubh�ubahG�8///< The object to send ::MSG_DESCRIPTION_GETBITMAP to.
�hH}�hJ�j�  �ubj!  )��}�(hh�_id�����}�(hKhh)��}�(hhhM,hKMhK
ubh�ubhj�  h]�h;j:  h<j�  h>j+  h@NhANh�DescID�hBNhCNhDK hE]�h�4///< The ID for the DescriptionGetBitmap::id field.
�����}�(hKhh)��}�(hhhM5hKMhKubh�ubahG�4///< The ID for the DescriptionGetBitmap::id field.
�hH}�hJ�j�  �ubj!  )��}�(hh�dirty�����}�(hKhh)��}�(hhhMqhKNhK	ubh�ubhj�  h]�h;jM  h<j�  h>j+  h@NhANh�Int32�hBNhCNhDK hE]�h�j///< The dirty flag. Not used by the implementation. Use this to know when the image needs to be updated.
�����}�(hKhh)��}�(hhhM{hKNhKubh�ubahG�j///< The dirty flag. Not used by the implementation. Use this to know when the image needs to be updated.
�hH}�hJ�j�  �ubj!  )��}�(hh�reserved�����}�(hKhh)��}�(hhhM�hKOhK	ubh�ubhj�  h]�h;j`  h<j�  h>j+  h@NhANh�Int32�hBNhCNhDK hE]�h�///< @markInternal
�����}�(hKhh)��}�(hhhM�hKOhKubh�ubahG�///< @markInternal
�hH}�hJ�j�  �ubeh;j�  h<h=h>j�  h@NhANhNhBNhCNhDK hE]�(h�Z/// Bitmap button data type (@ref CUSTOMDATATYPE_BITMAPBUTTON) for BitmapButtonCustomGui.
�����}�(hKhh)��}�(hhhM�hK9hKubh�ubh��/// @note Used to get a bitmap button in the Attribute Manager. Specify an object, @ref op, that provides an icon through the @ref MSG_DESCRIPTION_GETBITMAP message.
�����}�(hKhh)��}�(hhhM�hK:hKubh�ubehGX   /// Bitmap button data type (@ref CUSTOMDATATYPE_BITMAPBUTTON) for BitmapButtonCustomGui.
/// @note Used to get a bitmap button in the Attribute Manager. Specify an object, @ref op, that provides an icon through the @ref MSG_DESCRIPTION_GETBITMAP message.
�hH}�hJ�j�  ]��CustomDataType�h�public�����}�(hKhh)��}�(hhhM�hK<hKubh�ub��aj�  Nj�  Nj�  Nj�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�BitmapButtonCallback�����}�(hKhh)��}�(hhhM+hKUhKubh�ubhhh]�j!  )��}�(hh�data�����}�(hKhh)��}�(hhhMIhKWhKubh�ubhj�  h]�h;j�  h<h=h>j+  h@NhANh�void*�hBNhCNhDK hE]�h�///< Custom data.
�����}�(hKhh)��}�(hhhMQhKWhKubh�ubahG�///< Custom data.
�hH}�hJ�j�  �ubah;j�  h<h=h>j�  h@NhANhNhBNhCNhDK hE]�h�^/// Callback for BitmapButtonCustomGui, registered with BitmapButtonCustomGui::SetCallback().
�����}�(hKhh)��}�(hhhMkhKShKubh�ubahG�^/// Callback for BitmapButtonCustomGui, registered with BitmapButtonCustomGui::SetCallback().
�hH}�hJ�j�  ]�j�  Nj�  Nj�  Nj�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  ]�j�  ]�j�  }�ubj�  )��}�(hh�BitmapButtonCustomGui�����}�(hKhh)��}�(hhhM�hKchKubh�ubhhh]�(j�  )��}�(hj�  hj�  h]�h;j�  h<h�private�����}�(hKhh)��}�(hhhM0hKehKubh�ubh>j�  h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�j�  �j�  �j�  �j�  j�  j�  �hK]�j�  Nj�  Nubj�  )��}�(hh�SetImage�����}�(hKhh)��}�(hhhM�hKthKubh�ubhj�  h]�h;j�  h<h�public�����}�(hKhh)��}�(hhhMrhKihKubh�ubh>�function�h@NhANhNhBNhCNhDK hE]�(h�&/// Sets the image from a BaseBitmap.
�����}�(hKhh)��}�(hhhM�hKnhKubh�ubh�,/// @param[in] bmp								The bitmap image.
�����}�(hKhh)��}�(hhhM!hKohKubh�ubh�K/// @param[in] copybmp						If @formatConstant{true} the bitmap is copied.
�����}�(hKhh)��}�(hhhMOhKphKubh�ubh�r/// @param[in] secondstate				If @formatConstant{true} a second state for toggle and clickable buttons is stored.
�����}�(hKhh)��}�(hhhM�hKqhKubh�ubh�9/// @return												@trueIfOtherwiseFalse{successful}
�����}�(hKhh)��}�(hhhMhKrhKubh�ubehGXH  /// Sets the image from a BaseBitmap.
/// @param[in] bmp								The bitmap image.
/// @param[in] copybmp						If @formatConstant{true} the bitmap is copied.
/// @param[in] secondstate				If @formatConstant{true} a second state for toggle and clickable buttons is stored.
/// @return												@trueIfOtherwiseFalse{successful}
�hH}�hJ�j�  �j�  �j�  �j�  �Bool�j�  �hK]�(j   )��}�(h�BaseBitmap*�hh�bmp�����}�(hKhh)��}�(hhhM�hKthKubh�ubj
  Nj  �j  �j  �ubj   )��}�(h�Bool�hh�copybmp�����}�(hKhh)��}�(hhhM�hKthK'ubh�ubj
  Nj  �j  �j  �ubj   )��}�(h�Bool�hh�secondstate�����}�(hKhh)��}�(hhhM�hKthK5ubh�ubj
  �false�j  �j  �j  �ubej�  Nj�  Nubj�  )��}�(hh�SetImage�����}�(hKhh)��}�(hhhM�hK|hKubh�ubhj�  h]�h;j  h<j�  h>j�  h@NhANhNhBNhCNhDK hE]�(h�$/// Sets the image from a Filename.
�����}�(hKhh)��}�(hhhMPhKwhKubh�ubh�?/// @param[in] name								The filename for the image to load.
�����}�(hKhh)��}�(hhhMvhKxhKubh�ubh�r/// @param[in] secondstate				If @formatConstant{true} a second state for toggle and clickable buttons is stored.
�����}�(hKhh)��}�(hhhM�hKyhKubh�ubh�9/// @return												@trueIfOtherwiseFalse{successful}
�����}�(hKhh)��}�(hhhM+hKzhKubh�ubehGX  /// Sets the image from a Filename.
/// @param[in] name								The filename for the image to load.
/// @param[in] secondstate				If @formatConstant{true} a second state for toggle and clickable buttons is stored.
/// @return												@trueIfOtherwiseFalse{successful}
�hH}�hJ�j�  �j�  �j�  �j�  �Bool�j�  �hK]�(j   )��}�(h�const Filename&�hh�name�����}�(hKhh)��}�(hhhM�hK|hK!ubh�ubj
  Nj  �j  �j  �ubj   )��}�(h�Bool�hh�secondstate�����}�(hKhh)��}�(hhhM�hK|hK,ubh�ubj
  �false�j  �j  �j  �ubej�  Nj�  Nubj�  )��}�(hh�SetImage�����}�(hKhh)��}�(hhhMhK�hKubh�ubhj�  h]�h;jT  h<j�  h>j�  h@NhANhNhBNhCNhDK hE]�(h�%/// Sets the image from an IconData.
�����}�(hKhh)��}�(hhhMbhKhKubh�ubh�(/// @warning The icon bitmap is copied.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�G/// @param[in] bmp								The icon data. @callerOwnsPointed{icon data}
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�r/// @param[in] secondstate				If @formatConstant{true} a second state for toggle and clickable buttons is stored.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�9/// @return												@trueIfOtherwiseFalse{successful}
�����}�(hKhh)��}�(hhhMphK�hKubh�ubehGX?  /// Sets the image from an IconData.
/// @warning The icon bitmap is copied.
/// @param[in] bmp								The icon data. @callerOwnsPointed{icon data}
/// @param[in] secondstate				If @formatConstant{true} a second state for toggle and clickable buttons is stored.
/// @return												@trueIfOtherwiseFalse{successful}
�hH}�hJ�j�  �j�  �j�  �j�  �Bool�j�  �hK]�(j   )��}�(h�	IconData*�hh�bmp�����}�(hKhh)��}�(hhhM hK�hKubh�ubj
  Nj  �j  �j  �ubj   )��}�(h�Bool�hh�secondstate�����}�(hKhh)��}�(hhhM*hK�hK%ubh�ubj
  �false�j  �j  �j  �ubej�  Nj�  Nubj�  )��}�(hh�SetImage�����}�(hKhh)��}�(hhhM, hK�hKubh�ubhj�  h]�h;j�  h<j�  h>j�  h@NhANhNhBNhCNhDK hE]�(h�$/// Sets the image from an icon ID.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�(/// @warning The icon bitmap is copied.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�)/// @param[in] icon_id						The icon ID.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�r/// @param[in] secondstate				If @formatConstant{true} a second state for toggle and clickable buttons is stored.
�����}�(hKhh)��}�(hhhMhK�hKubh�ubh�9/// @return												@trueIfOtherwiseFalse{successful}
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubehGX   /// Sets the image from an icon ID.
/// @warning The icon bitmap is copied.
/// @param[in] icon_id						The icon ID.
/// @param[in] secondstate				If @formatConstant{true} a second state for toggle and clickable buttons is stored.
/// @return												@trueIfOtherwiseFalse{successful}
�hH}�hJ�j�  �j�  �j�  �j�  �Bool�j�  �hK]�(j   )��}�(h�Int32�hh�icon_id�����}�(hKhh)��}�(hhhM; hK�hKubh�ubj
  Nj  �j  �j  �ubj   )��}�(h�Bool�hh�secondstate�����}�(hKhh)��}�(hhhMI hK�hK%ubh�ubj
  �false�j  �j  �j  �ubej�  Nj�  Nubj�  )��}�(hh�SetToggleState�����}�(hKhh)��}�(hhhM�!hK�hKubh�ubhj�  h]�h;j�  h<j�  h>j�  h@NhANhNhBNhCNhDK hE]�(h�)/// Sets the toggle state of the button.
�����}�(hKhh)��}�(hhhM� hK�hKubh�ubh�0/// @param[in] set								The new toggle state.
�����}�(hKhh)��}�(hhhM!hK�hKubh�ubehG�Y/// Sets the toggle state of the button.
/// @param[in] set								The new toggle state.
�hH}�hJ�j�  �j�  �j�  �j�  �void�j�  �hK]�j   )��}�(h�Bool�hh�set�����}�(hKhh)��}�(hhhM�!hK�hKubh�ubj
  Nj  �j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�SetDragArray�����}�(hKhh)��}�(hhhM�#hK�hKubh�ubhj�  h]�h;j�  h<j�  h>j�  h@NhANhNhBNhCNhDK hE]�(h��/// Stores an atom array that can be dragged from the button by the user. This is only possible for non-button mode (::BITMAPBUTTON_BUTTON is @formatConstant{false}).
�����}�(hKhh)��}�(hhhM&"hK�hKubh�ubh�f/// @param[in] bl									The atom array to store. The array is not copied. @callerOwnsPointed{array}
�����}�(hKhh)��}�(hhhM�"hK�hKubh�ubehGX  /// Stores an atom array that can be dragged from the button by the user. This is only possible for non-button mode (::BITMAPBUTTON_BUTTON is @formatConstant{false}).
/// @param[in] bl									The atom array to store. The array is not copied. @callerOwnsPointed{array}
�hH}�hJ�j�  �j�  �j�  �j�  �void�j�  �hK]�j   )��}�(h�const AtomArray*�hh�bl�����}�(hKhh)��}�(hhhM�#hK�hK&ubh�ubj
  Nj  �j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�SetCallback�����}�(hKhh)��}�(hhhM
%hK�hKubh�ubhj�  h]�h;j  h<j�  h>j�  h@NhANhNhBNhCNhDK hE]�(h�T/// Registers a callback with the bitmap button. Called when the button is pressed.
�����}�(hKhh)��}�(hhhM$hK�hKubh�ubh�4/// @param[in] cb									The callback to register.
�����}�(hKhh)��}�(hhhMr$hK�hKubh�ubehG��/// Registers a callback with the bitmap button. Called when the button is pressed.
/// @param[in] cb									The callback to register.
�hH}�hJ�j�  �j�  �j�  �j�  �void�j�  �hK]�j   )��}�(h�const BitmapButtonCallback&�hh�cb�����}�(hKhh)��}�(hhhM2%hK�hK0ubh�ubj
  Nj  �j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�SetCommandDragId�����}�(hKhh)��}�(hhhM�&hK�hKubh�ubhj�  h]�h;j;  h<j�  h>j�  h@NhANhNhBNhCNhDK hE]�(h�//// Sets the command ID for the bitmap button.
�����}�(hKhh)��}�(hhhM�%hK�hKubh�ubh�r/// @note Enables drag and drop of the command into tool bars and menu managers. Used e.g. in the Script Manager.
�����}�(hKhh)��}�(hhhM�%hK�hKubh�ubh�+/// @param[in] cmdid							The command ID.
�����}�(hKhh)��}�(hhhM<&hK�hKubh�ubehG��/// Sets the command ID for the bitmap button.
/// @note Enables drag and drop of the command into tool bars and menu managers. Used e.g. in the Script Manager.
/// @param[in] cmdid							The command ID.
�hH}�hJ�j�  �j�  �j�  �j�  �void�j�  �hK]�j   )��}�(h�Int32�hh�cmdid�����}�(hKhh)��}�(hhhM�&hK�hKubh�ubj
  Nj  �j  �j  �ubaj�  Nj�  Nubj�  )��}�(hh�GetMaxWidth�����}�(hKhh)��}�(hhhMd(hK�hK	ubh�ubhj�  h]�h;jd  h<j�  h>j�  h@NhANhNhBNhCNhDK hE]�(h��/// Gets the maximum width of the user area that the Bitmap is being drawn into, allowing you to size the bitmap prior to setting.
�����}�(hKhh)��}�(hhhMJ'hK�hKubh�ubh�///
�����}�(hKhh)��}�(hhhM�'hK�hKubh�ubh�*/// @return												The maximum width.
�����}�(hKhh)��}�(hhhM�'hK�hKubh�ubehG��/// Gets the maximum width of the user area that the Bitmap is being drawn into, allowing you to size the bitmap prior to setting.
///
/// @return												The maximum width.
�hH}�hJ�j�  �j�  �j�  �j�  �Int32�j�  �hK]�j�  Nj�  Nubeh;j�  h<h=h>j�  h@NhANhNhBNhCNhDK hE]�(h�>/// Bitmap button custom GUI (@ref CUSTOMGUI_BITMAPBUTTON).\n
�����}�(hKhh)��}�(hhhM�hK`hKubh�ubh�J/// Here are the settings: @enumerateEnum{BITMAPBUTTON_CUSTOMGUISETTINGS}
�����}�(hKhh)��}�(hhhM=hKahKubh�ubehG��/// Bitmap button custom GUI (@ref CUSTOMGUI_BITMAPBUTTON).\n
/// Here are the settings: @enumerateEnum{BITMAPBUTTON_CUSTOMGUISETTINGS}
�hH}�hJ�j�  ]��%BaseCustomGui<CUSTOMGUI_BITMAPBUTTON>�h�public�����}�(hKhh)��}�(hhhM hKchKubh�ub��aj�  Nj�  Nj�  Nj�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  ]�j�  ]�j�  }�ubh)��}�(hNhhh]�h h�/// @cond IGNORE
�����}�(hK	hh)��}�(hhhM�(hK�hKubh�ububh)��}�(hNhhh]�h h�#ifndef _INTERNAL_BITMAPBUTTON_�����}�(hK
hh)��}�(hhhM�)hK�hKubh�ububj�  )��}�(hh�iBitmapButtonCustomGui�����}�(hKhh)��}�(hhhM�)hK�hKubh�ubhhh]�j�  )��}�(hj�  hj�  h]�h;j�  h<�private�h>j�  h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�j�  �j�  �j�  �j�  j�  j�  �hK]�(j   )��}�(h�const BaseContainer&�hh�settings�����}�(hKhh)��}�(hhhM.*hK�hK/ubh�ubj
  Nj  �j  �j  �ubj   )��}�(h�CUSTOMGUIPLUGIN*�hh�plugin�����}�(hKhh)��}�(hhhMI*hK�hKJubh�ubj
  Nj  �j  �j  �ubej�  Nj�  Nubah;j�  h<h=h>j�  h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�j�  ]��iBaseCustomGui�h�public�����}�(hKhh)��}�(hhhM�)hK�hK!ubh�ub��aj�  Nj�  Nj�  Nj�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  ]�j�  ]�j�  }�ubh)��}�(hNhhh]�h h�#else�����}�(hK
hh)��}�(hhhM|*hK�hKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�*hK�hKubh�ububj�  )��}�(hh�BitmapButtonLib�����}�(hKhh)��}�(hhhM�*hK�hKubh�ubhhh]�h;j�  h<h=h>j�  h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ�j�  ]��BaseCustomGuiLib�h�public�����}�(hKhh)��}�(hhhM�*hK�hKubh�ub��aj�  Nj�  Nj�  Nj�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  ]�j�  ]�j�  }�ubh)��}�(hNhhh]�h h�/// @endcond
�����}�(hK	hh)��}�(hhhMK.hK�hKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhMY.hK�hKubh�ububeh;hh<h=h>�	namespace�h@NhANhNhBNhCNhDK hE]�hGh	hH}�hJ��preprocessorConditions�]��root�hh ]�(hh'h2hMhXh^hbhfhjh}h�h�h�h�h�h�h�j  j0  j<  jH  jT  j`  js  j  j�  j�  j�  j�  j�  j�  j�  j�  j�  j�  )��}�(hh�iBitmapButtonCustomGui�����}�(hKhh)��}�(hhhM�*hK�hKubh�ubhhh]�h;j#  h<h=h>j�  h@NhANhNhBNhCNhDK hE]�hGNhH}�hJ�j�  ]�j�  Nj�  Nj�  Nj�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j�  �j�  �j�  ]�j�  ]�j�  }�ubj�  j�  j  j  e�containsResourceId���registry���hxx1�N�hxx2�N�snippets�}��minIndentation�K �maxIndentation�K �firstMember��ub.