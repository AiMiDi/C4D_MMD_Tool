��P&      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��`D:\C4DSDK\C4D_MMDTool\sdk_s24\frameworks\core.framework\source\maxon\utilities\movecopywrapper.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/errorbase.h�hhh]��quote��"��template�Nubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhKahKhKubh�ubhhh]�(h �Class���)��}�(hh�CopyWrapper�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh0h]�(h �Variable���)��}�(hh�_value�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh;h]��
simpleName�hJ�access��private��kind��variable�h/N�friend�Nh�T��id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���static��ubhE)��}�(hh�_ptr�����}�(hKhh)��}�(hhhM�hK hKubh�ubhh;h]�hOhdhPhQhRhSh/NhTNh�T*�hVNhWNhXK hY]�h[h	h\}�h^�h_�ubh �Function���)��}�(h�constructor�hh;h]�hOhphPh�public�����}�(hKhh)��}�(hhhM
hK"hKubh�ubhRhph/NhTNhNhVNhWNhXK hY]�h[h	h\}�h^�h_��explicit���deleted���retType��void��const���params�]��
observable�N�result�Nubhm)��}�(hhphh;h]�hOhphPhthRhph/NhTNhNhVNhWNhXK hY]�(h�^/// Copies the source object into the wrapper. Get() will return an error if the copy failed.
�����}�(hKhh)��}�(hhhM�hK(hKubh�ubh�@/// @param[in] src								Object to be copied into the wrapper.
�����}�(hKhh)��}�(hhhM�hK)hKubh�ubeh[��/// Copies the source object into the wrapper. Get() will return an error if the copy failed.
/// @param[in] src								Object to be copied into the wrapper.
�h\}�h^�h_�hz�h{�h|h}h~�h]�h �	Parameter���)��}�(h�const T&�hh�src�����}�(hKhh)��}�(hhhM�hK+hK ubh�ub�default�N�pack���input���output��ubah�Nh�Nubhm)��}�(hhphh;h]�hOhphPhthRhph/NhTNhNhVNhWNhXK hY]�(h�i/// Moves the source object into the wrapper. Following Get()s will succeed because the move can't fail.
�����}�(hKhh)��}�(hhhMAhK1hKubh�ubh�?/// @param[in] src								Object to be moved into the wrapper.
�����}�(hKhh)��}�(hhhM�hK2hKubh�ubeh[��/// Moves the source object into the wrapper. Following Get()s will succeed because the move can't fail.
/// @param[in] src								Object to be moved into the wrapper.
�h\}�h^�h_�hz�h{�h|h}h~�h]�h�)��}�(h�T&&�hh�src�����}�(hKhh)��}�(hhhM`hK4hKubh�ubh�Nh��h��h��ubah�Nh�Nubhm)��}�(hhphh;h]�hOhphPhthRhph/NhTNhNhVNhWNhXK hY]�(h�N/// Copies the source wrapper. Get() will return an error if the copy failed.
�����}�(hKhh)��}�(hhhM�hK9hKubh�ubh�0/// @param[in] src								Wrapper to be copied.
�����}�(hKhh)��}�(hhhM@hK:hKubh�ubeh[�~/// Copies the source wrapper. Get() will return an error if the copy failed.
/// @param[in] src								Wrapper to be copied.
�h\}�h^�h_�hz�h{�h|h}h~�h]�h�)��}�(h�const CopyWrapper&�hh�src�����}�(hKhh)��}�(hhhM�hK<hK!ubh�ubh�Nh��h��h��ubah�Nh�Nubhm)��}�(hhphh;h]�hOhphPhthRhph/NhTNhNhVNhWNhXK hY]�(h�Y/// Moves the source wrapper. Following Get()s will succeed because the move can't fail.
�����}�(hKhh)��}�(hhhM�	hKBhKubh�ubh�//// @param[in] src								Wrapper to be moved.
�����}�(hKhh)��}�(hhhM�	hKChKubh�ubeh[��/// Moves the source wrapper. Following Get()s will succeed because the move can't fail.
/// @param[in] src								Wrapper to be moved.
�h\}�h^�h_�hz�h{�h|h}h~�h]�h�)��}�(h�CopyWrapper&&�hh�src�����}�(hKhh)��}�(hhhM�
hKEhKubh�ubh�Nh��h��h��ubah�Nh�Nubhm)��}�(hh�
operator =�����}�(hKhh)��}�(hhhMHhKNhKubh�ubhh;h]�hOh�hPhthR�function�h/NhTNhNhVNhWNhXK hY]�(h�T/// Copy assigns the source wrapper. Get() will return an error if the copy failed.
�����}�(hKhh)��}�(hhhMYhKKhKubh�ubh�0/// @param[in] src								Wrapper to be copied.
�����}�(hKhh)��}�(hhhM�hKLhKubh�ubeh[��/// Copy assigns the source wrapper. Get() will return an error if the copy failed.
/// @param[in] src								Wrapper to be copied.
�h\}�h^�h_�hz�h{�h|�CopyWrapper&�h~�h]�h�)��}�(h�const CopyWrapper&�hh�src�����}�(hKhh)��}�(hhhMghKNhK.ubh�ubh�Nh��h��h��ubah�Nh�Nubhm)��}�(hh�
operator =�����}�(hKhh)��}�(hhhM1hKZhKubh�ubhh;h]�hOj!  hPhthRj  h/NhTNhNhVNhWNhXK hY]�(h�_/// Move assign the source wrapper. Following Get()s will succeed because the move can't fail.
�����}�(hKhh)��}�(hhhM8hKWhKubh�ubh�//// @param[in] src								Wrapper to be moved.
�����}�(hKhh)��}�(hhhM�hKXhKubh�ubeh[��/// Move assign the source wrapper. Following Get()s will succeed because the move can't fail.
/// @param[in] src								Wrapper to be moved.
�h\}�h^�h_�hz�h{�h|�CopyWrapper&�h~�h]�h�)��}�(h�CopyWrapper&&�hh�src�����}�(hKhh)��}�(hhhMKhKZhK)ubh�ubh�Nh��h��h��ubah�Nh�Nubhm)��}�(hh�Get�����}�(hKhh)��}�(hhhMshKihKubh�ubhh;h]�hOjD  hPhthRj  h/NhTNhNhVNhWNhXK hY]�(h�o/// Returns a reference to the wrapped object if the assignment or construction of the wrapper was successful.
�����}�(hKhh)��}�(hhhMBhKfhKubh�ubh�Q/// @return												Reference to wrapped object on success, error on failure.
�����}�(hKhh)��}�(hhhM�hKghKubh�ubeh[��/// Returns a reference to the wrapped object if the assignment or construction of the wrapper was successful.
/// @return												Reference to wrapped object on success, error on failure.
�h\}�h^�h_�hz�h{�h|�ResultRef<const T>�h~�h]�h�Nh�Nubhm)��}�(hh�Get�����}�(hKhh)��}�(hhhMhKrhKubh�ubhh;h]�hOj^  hPhthRj  h/NhTNhNhVNhWNhXK hY]�(h�o/// Returns a reference to the wrapped object if the assignment or construction of the wrapper was successful.
�����}�(hKhh)��}�(hhhM�hKohKubh�ubh�Q/// @return												Reference to wrapped object on success, error on failure.
�����}�(hKhh)��}�(hhhMbhKphKubh�ubeh[��/// Returns a reference to the wrapped object if the assignment or construction of the wrapper was successful.
/// @return												Reference to wrapped object on success, error on failure.
�h\}�h^�h_�hz�h{�h|�ResultRef<T>�h~�h]�h�Nh�NubehOh?hP�public�hR�class�h/h �Template���)��}�h]�h �TypeTemplateParam���)��}�(hh)��}�(hhhM�hKhKubh��hh�T�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�N�variance�NubasbhTNhNhVNhWNhXK hY]�(h�P/// This wrapper helps to capture objects which require CopyFrom() in a lambda.
�����}�(hKhh)��}�(hhhK�hKhKubh�ubh�W/// The get method will return an error if copying the object into the wrapper failed.
�����}�(hKhh)��}�(hhhMhKhKubh�ubh�B/// Of course move construction and assignment are supported too.
�����}�(hKhh)��}�(hhhMmhKhKubh�ubh�3/// @tparam T											Type of object to wrapped.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�
/// @code
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�:/// JobRef EnqueueSendJob(const BaseArray<Char>& jobdata)
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�/// {
�����}�(hKhh)��}�(hhhM&hKhKubh�ubh�/// 	return JobRef::Enqueue(
�����}�(hKhh)��}�(hhhM,hKhKubh�ubh�M/// 		[this, copy = CopyWrapper<BaseArray<Char>>(jobdata)]() -> Result<void>
�����}�(hKhh)��}�(hhhMIhKhKubh�ubh�/// 		{
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�///				iferr_scope;
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�?///				const BaseArray<Char>& array = copy.Get() iferr_return;
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�A/// 			return _stream.Write(array.GetFirst(), array.GetCount());
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�	/// 		},
�����}�(hKhh)��}�(hhhM2hKhKubh�ubh�/// 		_queue);
�����}�(hKhh)��}�(hhhM;hKhKubh�ubh�/// }
�����}�(hKhh)��}�(hhhMJhKhKubh�ubh�/// @endcode
�����}�(hKhh)��}�(hhhMPhKhKubh�ubeh[X�  /// This wrapper helps to capture objects which require CopyFrom() in a lambda.
/// The get method will return an error if copying the object into the wrapper failed.
/// Of course move construction and assignment are supported too.
/// @tparam T											Type of object to wrapped.
/// @code
/// JobRef EnqueueSendJob(const BaseArray<Char>& jobdata)
/// {
/// 	return JobRef::Enqueue(
/// 		[this, copy = CopyWrapper<BaseArray<Char>>(jobdata)]() -> Result<void>
/// 		{
///				iferr_scope;
///				const BaseArray<Char>& array = copy.Get() iferr_return;
/// 			return _stream.Write(array.GetFirst(), array.GetCount());
/// 		},
/// 		_queue);
/// }
/// @endcode
�h\}�h^��bases�]��	interface�N�refKind�Nh_��refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent���forward���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���ambiguousCalls�]��	selfCalls�]��methodNames�}�ubhm)��}�(hh�CreateCopyWrapper�����}�(hKhh)��}�(hhhMWhK�hKPubh�ubhh0h]�hOj  hPjt  hRj  h/jw  )��}�h]�j|  )��}�(hh)��}�(hhhMhK�hKubh��hh�T�����}�(hKhh)��}�(hhhMhK�hKubh�ubh�Nj�  NubasbhTNhNhVNhWNhXK hY]�h[h	h\}�h^�h_�hz�h{�h|�1Result<CopyWrapper<typename std::decay<T>::type>>�h~�h]�h�)��}�(h�T&&�hh�src�����}�(hKhh)��}�(hhhMmhK�hKfubh�ubh�Nh��h��h��ubah�Nh��)CopyWrapper<typename std::decay<T>::type>�ubehOh4hPjt  hR�	namespace�h/NhTNhNhVNhWNhXK hY]�h[h	h\}�h^��preprocessorConditions�]��root�hh N�containsResourceId���registry���usings����minIndentation�K �maxIndentation�K �firstMember��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhMhK�hKubh�ububehOhhPjt  hRj,  h/NhTNhNhVNhWNhXK hY]�h[h	h\}�h^�j/  ]�j1  hh ]�(hh)h0h;j  j9  ej2  �j3  �j4  ���hxx1�N�hxx2�N�snippets�}�j6  K j7  K j8  �ub.