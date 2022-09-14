���E      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��GD:\C4D_MMD_Tool\sdk_2023\frameworks\core.framework\source\maxon\queue.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/algorithms.h�hhh]��quote��"��template�Nubh()��}�(h�maxon/optional.h�hhh]�h-h.h/Nubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhKjhKhKubh�ubhhh]�h �Class���)��}�(hh�Queue�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh4h]�(h �	TypeAlias���)��}�(hh�	ValueType�����}�(hKhh)��}�(hhhM�hKhKubh�ubhh?h]��
simpleName�hN�access�h�public�����}�(hKhh)��}�(hhhM�hKhKubh�ub�kind��	typealias�h/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���bases�]��T��public�h	��aubh �Function���)��}�(h�constructor�hh?h]�hShphThWh[hph/Nh]NhNh^Nh_Nh`K ha]�(h�/// Default constructor.
�����}�(hKhh)��}�(hhhM5hKhKubh�ubh�/// Creates an empty queue.
�����}�(hKhh)��}�(hhhMOhKhKubh�ubehc�5/// Default constructor.
/// Creates an empty queue.
�hd}�hf��static���explicit���deleted���retType��void��const���params�]��
observable�N�result�N�forward��ubhm)��}�(hhphh?h]�hShphThWh[hph/Nh]NhNh^Nh_Nh`K ha]�h�/// Deleted copy constructor.
�����}�(hKhh)��}�(hhhM9hKhKubh�ubahc�/// Deleted copy constructor.
�hd}�hf�h��h��h��h�h�h��h�]�h �	Parameter���)��}�(h�const Queue&�h�anonymous_param_1��default�N�pack���input���output��ubah�Nh�Nh��ubhm)��}�(hh�
operator =�����}�(hKhh)��}�(hhhM�hK!hK	ubh�ubhh?h]�hSh�hThWh[�function�h/Nh]NhNh^Nh_Nh`K ha]�h�/// Deleted copy assignment.
�����}�(hKhh)��}�(hhhM0hKhKubh�ubahc�/// Deleted copy assignment.
�hd}�hf�h��h��h��h��Queue&�h��h�]�h�)��}�(h�const Queue&�h�anonymous_param_1�h�Nh��h��h��ubah�Nh�Nh��ubhm)��}�(hhphh?h]�hShphThWh[hph/Nh]NhNh^Nh_Nh`K ha]�h�/// Move constructor.
�����}�(hKhh)��}�(hhhM2hK$hKubh�ubahc�/// Move constructor.
�hd}�hf�h��h��h��h�h�h��h�]�h�)��}�(h�Queue&&�hh�src�����}�(hKhh)��}�(hhhM�hK&hKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhm)��}�(hh�
operator =�����}�(hKhh)��}�(hhhM�hK.hK	ubh�ubhh?h]�hSh�hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�h�/// Move assignment.
�����}�(hKhh)��}�(hhhMrhK,hKubh�ubahc�/// Move assignment.
�hd}�hf�h��h��h��h��Queue&�h��h�]�h�)��}�(h�Queue&&�hh�src�����}�(hKhh)��}�(hhhM�hK.hKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhm)��}�(hh�GetCount�����}�(hKhh)��}�(hhhM�hK>hKubh�ubhh?h]�hSh�hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�h�1/// Returns the number of elements in the queue.
�����}�(hKhh)��}�(hhhMhK<hKubh�ubahc�1/// Returns the number of elements in the queue.
�hd}�hf�h��h��h��h��Int�h��h�]�h�Nh�Nh��ubhm)��}�(hh�IsEmpty�����}�(hKhh)��}�(hhhM�	hKChKubh�ubhh?h]�hSj  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�h�./// Checks if the queue contains no elements.
�����}�(hKhh)��}�(hhhM1	hKAhKubh�ubahc�./// Checks if the queue contains no elements.
�hd}�hf�h��h��h��h��Bool�h��h�]�h�Nh�Nh��ubhm)��}�(hh�IsPopulated�����}�(hKhh)��}�(hhhM�
hKHhKubh�ubhh?h]�hSj  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�h�//// Checks if the queue contains any elements.
�����}�(hKhh)��}�(hhhMG
hKFhKubh�ubahc�//// Checks if the queue contains any elements.
�hd}�hf�h��h��h��h��Bool�h��h�]�h�Nh�Nh��ubhm)��}�(hh�Peek�����}�(hKhh)��}�(hhhMKhKNhKubh�ubhh?h]�hSj/  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�(h�A/// Returns a reference to the element at the front of the queue
�����}�(hKhh)��}�(hhhMbhKKhKubh�ubh�=/// without removing it, or NO_VALUE if the queue was empty.
�����}�(hKhh)��}�(hhhM�hKLhKubh�ubehc�~/// Returns a reference to the element at the front of the queue
/// without removing it, or NO_VALUE if the queue was empty.
�hd}�hf�h��h��h��h��Optional<T&>�h��h�]�h�Nh�Nh��ubhm)��}�(hh�Peek�����}�(hKhh)��}�(hhhM�hKVhKubh�ubhh?h]�hSjI  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��Optional<const T&>�h��h�]�h�Nh�Nh��ubhm)��}�(hh�PeekBack�����}�(hKhh)��}�(hhhMXhKbhKubh�ubhh?h]�hSjV  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�(h�@/// Returns a reference to the element at the back of the queue
�����}�(hKhh)��}�(hhhMphK_hKubh�ubh�=/// without removing it, or NO_VALUE if the queue was empty.
�����}�(hKhh)��}�(hhhM�hK`hKubh�ubehc�}/// Returns a reference to the element at the back of the queue
/// without removing it, or NO_VALUE if the queue was empty.
�hd}�hf�h��h��h��h��Optional<T&>�h��h�]�h�Nh�Nh��ubhm)��}�(hh�PeekBack�����}�(hKhh)��}�(hhhMhKphKubh�ubhh?h]�hSjp  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��Optional<const T&>�h��h�]�h�Nh�Nh��ubhm)��}�(hh�Push�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhh?h]�hSj}  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�h�0/// Pushes an element to the back of the queue.
�����}�(hKhh)��}�(hhhM3hKhKubh�ubahc�0/// Pushes an element to the back of the queue.
�hd}�hf�h��h��h��h��	ResultMem�h��h�]�h�)��}�(h�T�hh�value�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhm)��}�(hh�	PushFront�����}�(hKhh)��}�(hhhMohK�hKubh�ubhh?h]�hSj�  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�h�1/// Pushes an element to the front of the queue.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubahc�1/// Pushes an element to the front of the queue.
�hd}�hf�h��h��h��h��	ResultMem�h��h�]�h�)��}�(h�T�hh�value�����}�(hKhh)��}�(hhhM{hK�hKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhm)��}�(hh�Emplace�����}�(hKhh)��}�(hhhMthK�hK)ubh�ubhh?h]�hSj�  hThWh[h�h/h �Template���)��}�h�]�h �TypeTemplateParam���)��}�(hh)��}�(hhhMWhK�hKubh��hh�ARGS�����}�(hKhh)��}�(hhhMdhK�hKubh�ubh�N�variance�Nubasbh]NhNh^Nh_Nh`K ha]�h�o/// Constructs an element in-place at the back of the queue with the given arguments as constructor arguments.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubahc�o/// Constructs an element in-place at the back of the queue with the given arguments as constructor arguments.
�hd}�hf�h��h��h��h��	ResultMem�h��h�]�h�)��}�(h�ARGS&&�hh�args�����}�(hKhh)��}�(hhhM�hK�hK<ubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhm)��}�(hh�EmplaceFront�����}�(hKhh)��}�(hhhMvhK�hK)ubh�ubhh?h]�hSj�  hThWh[h�h/j�  )��}�h�]�j�  )��}�(hh)��}�(hhhMYhK�hKubh��hh�ARGS�����}�(hKhh)��}�(hhhMfhK�hKubh�ubh�Nj�  Nubasbh]NhNh^Nh_Nh`K ha]�h�W/// Constructs an element in-place at the front of the queue with the given arguments.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubahc�W/// Constructs an element in-place at the front of the queue with the given arguments.
�hd}�hf�h��h��h��h��	ResultMem�h��h�]�h�)��}�(h�ARGS&&�hh�args�����}�(hKhh)��}�(hhhM�hK�hKAubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhm)��}�(hh�Pop�����}�(hKhh)��}�(hhhMrhK�hKubh�ubhh?h]�hSj  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�h�f/// Returns the element at the front of the queue and removes it, or NO_VALUE if the queue was empty.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubahc�f/// Returns the element at the front of the queue and removes it, or NO_VALUE if the queue was empty.
�hd}�hf�h��h��h��h��Optional<T>�h��h�]�h�Nh�Nh��ubhm)��}�(hh�PopBack�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhh?h]�hSj$  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�h�e/// Returns the element at the back of the queue and removes it, or NO_VALUE if the queue was empty.
�����}�(hKhh)��}�(hhhM!hK�hKubh�ubahc�e/// Returns the element at the back of the queue and removes it, or NO_VALUE if the queue was empty.
�hd}�hf�h��h��h��h��Optional<T>�h��h�]�h�Nh�Nh��ubhm)��}�(hh�Truncate�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhh?h]�hSj8  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�(h�f/// Removes the element at the front of the queue without returning it. Returns true if the operation
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�0/// succeeded, or false if the queue was empty.
�����}�(hKhh)��}�(hhhM	hK�hKubh�ubehc��/// Removes the element at the front of the queue without returning it. Returns true if the operation
/// succeeded, or false if the queue was empty.
�hd}�hf�h��h��h��h��Bool�h��h�]�h�Nh�Nh��ubhm)��}�(hh�TruncateBack�����}�(hKhh)��}�(hhhMFhK�hKubh�ubhh?h]�hSjR  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�(h�e/// Removes the element at the back of the queue without returning it. Returns true if the operation
�����}�(hKhh)��}�(hhhMNhK�hKubh�ubh�0/// succeeded, or false if the queue was empty.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubehc��/// Removes the element at the back of the queue without returning it. Returns true if the operation
/// succeeded, or false if the queue was empty.
�hd}�hf�h��h��h��h��Bool�h��h�]�h�Nh�Nh��ubhm)��}�(hh�Flush�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhh?h]�hSjl  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�h�o/// Removes all elements from the queue by calling their destructors, but does not de-allocate the memory yet.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubahc�o/// Removes all elements from the queue by calling their destructors, but does not de-allocate the memory yet.
�hd}�hf�h��h��h��h��void�h��h�]�h�Nh�Nh��ubhm)��}�(hh�Reset�����}�(hKhh)��}�(hhhM3"hMhKubh�ubhh?h]�hSj�  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�h�e/// Removes all elements from the queue by calling their destructors and frees the allocated memory.
�����}�(hKhh)��}�(hhhMl!hMhKubh�ubahc�e/// Removes all elements from the queue by calling their destructors and frees the allocated memory.
�hd}�hf�h��h��h��h��void�h��h�]�h�Nh�Nh��ubhm)��}�(hh�AlignAsBlock�����}�(hKhh)��}�(hhhM�#hMhKubh�ubhh?h]�hSj�  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�h�b/// Linearizes the internal data storage and returns the elements as a block, from front to back.
�����}�(hKhh)��}�(hhhM�"hMhKubh�ubahc�b/// Linearizes the internal data storage and returns the elements as a block, from front to back.
�hd}�hf�h��h��h��h��Block<T>�h��h�]�h�Nh�Nh��ubhm)��}�(hh�CopyFrom�����}�(hKhh)��}�(hhhM�%hM)hKubh�ubhh?h]�hSj�  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�h�/// Copies the queue.
�����}�(hKhh)��}�(hhhM1%hM'hKubh�ubahc�/// Copies the queue.
�hd}�hf�h��h��h��h��Result<void>�h��h�]�h�)��}�(h�const Queue&�hh�src�����}�(hKhh)��}�(hhhM�%hM)hK%ubh�ubh�Nh��h��h��ubah�Nh��void�h��ubhm)��}�(hh�EnsureCapacity�����}�(hKhh)��}�(hhhM�(hM@hKubh�ubhh?h]�hSj�  hThWh[h�h/Nh]NhNh^Nh_Nh`K ha]�(h�a/// Ensures that the queue can hold @c requestedSize items without allocating additional memory.
�����}�(hKhh)��}�(hhhMr'hM=hKubh�ubh�t/// Can be used for optimization to pre-allocate a sufficiently large internal buffer instead of growing on-demand.
�����}�(hKhh)��}�(hhhM�'hM>hKubh�ubehc��/// Ensures that the queue can hold @c requestedSize items without allocating additional memory.
/// Can be used for optimization to pre-allocate a sufficiently large internal buffer instead of growing on-demand.
�hd}�hf�h��h��h��h��	ResultMem�h��h�]�h�)��}�(h�Int�hh�requestedSize�����}�(hKhh)��}�(hhhM�(hM@hKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubh �Variable���)��}�(hh�	GROW_INIT�����}�(hKhh)��}�(hhhM�)hMLhKubh�ubhh?h]�hSj�  hTh�private�����}�(hKhh)��}�(hhhMi)hMKhKubh�ubh[�variable�h/Nh]Nh�	const Int�h^Nh_Nh`K ha]�hch	hd}�hf�h��ubj�  )��}�(hh�GROW_FACTOR�����}�(hKhh)��}�(hhhM�)hMMhKubh�ubhh?h]�hSj�  hTj�  h[j�  h/Nh]Nh�	const Int�h^Nh_Nh`K ha]�hch	hd}�hf�h��ubhm)��}�(hh�IncrementIndex�����}�(hKhh)��}�(hhhM�)hMOhK+ubh�ubhh?h]�hSj
  hTj�  h[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��void�h��h�]�(h�)��}�(h�Int&�hh�index�����}�(hKhh)��}�(hhhM�)hMOhK?ubh�ubh�Nh��h��h��ubh�)��}�(h�Int�hh�capacity�����}�(hKhh)��}�(hhhM *hMOhKJubh�ubh�Nh��h��h��ubeh�Nh�Nh��ubhm)��}�(hh�DecrementIndex�����}�(hKhh)��}�(hhhM�*hMWhK+ubh�ubhh?h]�hSj)  hTj�  h[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��void�h��h�]�(h�)��}�(h�Int&�hh�index�����}�(hKhh)��}�(hhhM�*hMWhK?ubh�ubh�Nh��h��h��ubh�)��}�(h�Int�hh�capacity�����}�(hKhh)��}�(hhhM�*hMWhKJubh�ubh�Nh��h��h��ubeh�Nh�Nh��ubhm)��}�(hh�	Linearize�����}�(hKhh)��}�(hhhM+hM_hKubh�ubhh?h]�hSjH  hTj�  h[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��void�h��h�]�h�Nh�Nh��ubhm)��}�(hh�IsAtFullCapacity�����}�(hKhh)��}�(hhhM�/hM�hKubh�ubhh?h]�hSjU  hTj�  h[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��Bool�h��h�]�h�Nh�Nh��ubhm)��}�(hh�CalcNewCapacity�����}�(hKhh)��}�(hhhM�/hM�hKubh�ubhh?h]�hSjb  hTj�  h[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��Int�h��h�]�h�)��}�(h�Int�hh�
targetSize�����}�(hKhh)��}�(hhhM0hM�hKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhm)��}�(hh�Grow�����}�(hKhh)��}�(hhhM�0hM�hKubh�ubhh?h]�hSjx  hTj�  h[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��Bool�h��h�]�h�)��}�(h�Int�hh�
targetSize�����}�(hKhh)��}�(hhhM1hM�hKubh�ubh��0�h��h��h��ubah�Nh�Nh��ubhm)��}�(hh�CopyDataToNewBuffer�����}�(hKhh)��}�(hhhM�2hM�hKubh�ubhh?h]�hSj�  hTj�  h[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��Result<void>�h��h�]�h�)��}�(h�T*�hh�destPtr�����}�(hKhh)��}�(hhhM3hM�hK&ubh�ubh�Nh��h��h��ubah�Nh��void�h��ubhm)��}�(hh�MoveDataToNewBuffer�����}�(hKhh)��}�(hhhM�5hM�hKubh�ubhh?h]�hSj�  hTj�  h[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��void�h��h�]�h�)��}�(h�T*�hh�destPtr�����}�(hKhh)��}�(hhhM�5hM�hKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhm)��}�(hh�
PushToHead�����}�(hKhh)��}�(hhhM�7hM�hKubh�ubhh?h]�hSj�  hTj�  h[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��void�h��h�]�h�)��}�(h�T&&�hh�value�����}�(hKhh)��}�(hhhM�7hM�hKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhm)��}�(hh�
PushToTail�����}�(hKhh)��}�(hhhMn8hMhKubh�ubhh?h]�hSj�  hTj�  h[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��void�h��h�]�h�)��}�(h�T&&�hh�value�����}�(hKhh)��}�(hhhM}8hMhKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhm)��}�(hh�EmplaceAtHead�����}�(hKhh)��}�(hhhM9hMhK$ubh�ubhh?h]�hSj�  hTj�  h[h�h/j�  )��}�h�]�j�  )��}�(hh)��}�(hhhM�8hMhKubh��hh�ARGS�����}�(hKhh)��}�(hhhM9hMhKubh�ubh�Nj�  Nubasbh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��void�h��h�]�h�)��}�(h�ARGS&&�hh�args�����}�(hKhh)��}�(hhhM,9hMhK=ubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhm)��}�(hh�EmplaceAtTail�����}�(hKhh)��}�(hhhM�9hMhK$ubh�ubhh?h]�hSj  hTj�  h[h�h/j�  )��}�h�]�j�  )��}�(hh)��}�(hhhM�9hMhKubh��hh�ARGS�����}�(hKhh)��}�(hhhM�9hMhKubh�ubh�Nj�  Nubasbh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��void�h��h�]�h�)��}�(h�ARGS&&�hh�args�����}�(hKhh)��}�(hhhM�9hMhK=ubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhm)��}�(hh�PopFromTail�����}�(hKhh)��}�(hhhMg:hMhKubh�ubhh?h]�hSj.  hTj�  h[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��T�h��h�]�h�Nh�Nh��ubhm)��}�(hh�PopFromHead�����}�(hKhh)��}�(hhhM;hM!hKubh�ubhh?h]�hSj;  hTj�  h[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��T�h��h�]�h�Nh�Nh��ubhm)��}�(hh�TruncateTail�����}�(hKhh)��}�(hhhM�;hM,hKubh�ubhh?h]�hSjH  hTj�  h[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��void�h��h�]�h�Nh�Nh��ubhm)��}�(hh�TruncateHead�����}�(hKhh)��}�(hhhM<hM3hKubh�ubhh?h]�hSjU  hTj�  h[h�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�h��h��h��h��void�h��h�]�h�Nh�Nh��ubj�  )��}�(hh�_data�����}�(hKhh)��}�(hhhM�<hM:hKubh�ubhh?h]�hSjb  hTj�  h[j�  h/Nh]Nh�
AutoMem<T>�h^Nh_Nh`K ha]�hch	hd}�hf�h��ubj�  )��}�(hh�
_headIndex�����}�(hKhh)��}�(hhhM�<hM<hKubh�ubhh?h]�hSjn  hTj�  h[j�  h/Nh]Nh�Int�h^Nh_Nh`K ha]�hch	hd}�hf�h��ubj�  )��}�(hh�
_tailIndex�����}�(hKhh)��}�(hhhM�<hM=hKubh�ubhh?h]�hSjz  hTj�  h[j�  h/Nh]Nh�Int�h^Nh_Nh`K ha]�hch	hd}�hf�h��ubj�  )��}�(hh�_count�����}�(hKhh)��}�(hhhM�<hM>hKubh�ubhh?h]�hSj�  hTj�  h[j�  h/Nh]Nh�Int�h^Nh_Nh`K ha]�hch	hd}�hf�h��ubj�  )��}�(hh�	_capacity�����}�(hKhh)��}�(hhhM�<hM?hKubh�ubhh?h]�hSj�  hTj�  h[j�  h/Nh]Nh�Int�h^Nh_Nh`K ha]�hch	hd}�hf�h��ubehShChThjh[�class�h/j�  )��}�h�]�j�  )��}�(hh)��}�(hhhM�hKhKubh��hh�T�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�Nj�  Nubasbh]NhNh^Nh_Nh`K ha]�(h�H/// A Queue that holds elements of type T, stored in a circular buffer.
�����}�(hKhh)��}�(hhhK�hKhKubh�ubh�$/// Supports access from both ends.
�����}�(hKhh)��}�(hhhMhKhKubh�ubehc�l/// A Queue that holds elements of type T, stored in a circular buffer.
/// Supports access from both ends.
�hd}�hf�hg]��	interface�N�refKind�Nh���refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent��h���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���usings�]��constUsings�]��ambiguousCalls�]��	selfCalls�]��methodNames�}�ubahSh8hThjh[�	namespace�h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf��preprocessorConditions�]��root�hh N�containsResourceId���registry��j�  ���minIndentation�K �maxIndentation�K �firstMember��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�<hMDhKubh�ububehShhThjh[j�  h/Nh]NhNh^Nh_Nh`K ha]�hch	hd}�hf�j�  ]�j�  hh ]�(hh)h0h4h?j�  ej�  �j�  �j�  ���hxx1�N�hxx2�N�snippets�}�j�  K j�  K j�  ��forwardHeaders���ub.