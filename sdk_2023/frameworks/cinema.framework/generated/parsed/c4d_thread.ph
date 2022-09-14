��v�      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��HD:\C4D_MMD_Tool\sdk_2023\frameworks\cinema.framework\source\c4d_thread.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhM7hKhKubh�ububh)��}�(hNhhh]�h h�#ifdef __API_INTERN__�����}�(hK
hh)��}�(hhhMfhK
hKubh�ububh �Include���)��}�(h�ge_sys_thread.h�hhh]��quote��"��template�Nubh)��}�(hNhhh]�h h�#else�����}�(hK
hh)��}�(hhhM�hKhKubh�ububh1)��}�(h�maxon/spinlock.h�hhh]�h6h7h8Nubh1)��}�(h�maxon/thread.h�hhh]�h6h7h8Nubh1)��}�(h�operatingsystem.h�hhh]�h6h7h8Nubh)��}�(hNhhh]�h h� #ifdef CINEWARE_NAMESPACE_ENABLE�����}�(hK
hh)��}�(hhhM�hKhKubh�ububh)��}�(hNhhh]�h h�CINEWARE_NAMESPACE_BEGIN�����}�(hK
hh)��}�(hhhMhKhKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM.hKhKubh�ububh �Class���)��}�(hh�
BaseThread�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhh]�(h �Function���)��}�(h�constructor�hhkh]��
simpleName�hx�access�h�private�����}�(hKhh)��}�(hhhM�hKhKubh�ub�kind�hxh8N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���static���explicit���deleted���retType��void��const���params�]��
observable�N�result�N�forward��ubhu)��}�(hh�	TestBreak�����}�(hKhh)��}�(hhhMphK'hKubh�ubhhkh]�hzh�h{h�public�����}�(hKhh)��}�(hhhM�hK!hKubh�ubh��function�h8Nh�NhNh�Nh�Nh�K h�]�(h�H/// Checks if the thread received a break command to stop processing.\n
�����}�(hKhh)��}�(hhhM$hK#hKubh�ubh�T/// Normally this is only true when @C4D is closing, or when End() has been called.
�����}�(hKhh)��}�(hhhMmhK$hKubh�ubh�L/// @return												@trueOtherwiseFalse{processing should be terminated}
�����}�(hKhh)��}�(hhhM�hK%hKubh�ubeh���/// Checks if the thread received a break command to stop processing.\n
/// Normally this is only true when @C4D is closing, or when End() has been called.
/// @return												@trueOtherwiseFalse{processing should be terminated}
�h�}�h��h��h��h��h��Bool�h��h�]�h�Nh�Nh��ubhu)��}�(hh�End�����}�(hKhh)��}�(hhhM�hK0hKubh�ubhhkh]�hzh�h{h�h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�\/// Ends the thread. This function will not return until the thread has completely stopped.
�����}�(hKhh)��}�(hhhMhK*hKubh�ubh��/// @warning If the thread does not check for TestBreak() then this function will not return until the thread has finished and this might get into a deadlock situation.
�����}�(hKhh)��}�(hhhMahK+hKubh�ubh�\/// @param[in] wait								Determines if thread termination is synchronous or asynchronous:
�����}�(hKhh)��}�(hhhMhK,hKubh�ubh�i///																- If @formatConstant{true} the function will not return until the thread is finished.
�����}�(hKhh)��}�(hhhMhhK-hKubh�ubh��///																- If @formatConstant{false} the function returns immediately although the thread will still run until it is finished.
�����}�(hKhh)��}�(hhhM�hK.hKubh�ubeh�XS  /// Ends the thread. This function will not return until the thread has completely stopped.
/// @warning If the thread does not check for TestBreak() then this function will not return until the thread has finished and this might get into a deadlock situation.
/// @param[in] wait								Determines if thread termination is synchronous or asynchronous:
///																- If @formatConstant{true} the function will not return until the thread is finished.
///																- If @formatConstant{false} the function returns immediately although the thread will still run until it is finished.
�h�}�h��h��h��h��h��void�h��h�]�h �	Parameter���)��}�(h�Bool�hh�wait�����}�(hKhh)��}�(hhhM�hK0hKubh�ub�default��true��pack���input���output��ubah�Nh�Nh��ubhu)��}�(hh�	IsRunning�����}�(hKhh)��}�(hhhM
hK6hKubh�ubhhkh]�hzh�h{h�h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�%/// Checks if the thread is running.
�����}�(hKhh)��}�(hhhMP	hK3hKubh�ubh�D/// @return												@trueIfOtherwiseFalse{the thread is running}
�����}�(hKhh)��}�(hhhMv	hK4hKubh�ubeh��i/// Checks if the thread is running.
/// @return												@trueIfOtherwiseFalse{the thread is running}
�h�}�h��h��h��h��h��Bool�h��h�]�h�Nh�Nh��ubehzhoh{�public�h��class�h8Nh�NhNh�Nh�Nh�K h�]�(h�4/// Main thread base class used internally by @C4D.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�A/// @markDeprecated Use maxon::ThreadInterface/JobInterface etc.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�"/// @note Cannot be instantiated.
�����}�(hKhh)��}�(hhhMhKhKubh�ubeh���/// Main thread base class used internally by @C4D.
/// @markDeprecated Use maxon::ThreadInterface/JobInterface etc.
/// @note Cannot be instantiated.
�h�}�h���bases�]��	interface�N�refKind�Nh���refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent��h���
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���usings�]��constUsings�]��ambiguousCalls�]��	selfCalls�]��methodNames�}�ubhj)��}�(hh�	C4DThread�����}�(hKhh)��}�(hhhMlhK=hKubh�ubhhh]�(h �Variable���)��}�(hh�weak�����}�(hKhh)��}�(hhhM�hKBhKubh�ubhjF  h]�hzjU  h{h�private�����}�(hKhh)��}�(hhhM�hKAhKubh�ubh��variable�h8Nh�Nh�Bool�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubjP  )��}�(hh�bt�����}�(hKhh)��}�(hhhM�hKChKubh�ubhjF  h]�hzjh  h{j\  h�j`  h8Nh�Nh�BaseThread*�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubhu)��}�(hh�_Free�����}�(hKhh)��}�(hhhM�hKEhKubh�ubhjF  h]�hzjt  h{j\  h�h�h8Nh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��h��h��h��void�h��h�]�h�Nh�Nh��ubhu)��}�(hhxhjF  h]�hzhxh{h�public�����}�(hKhh)��}�(hhhM�hKGhKubh�ubh�hxh8Nh�NhNh�Nh�Nh�K h�]�(h�/// Constructor.
�����}�(hKhh)��}�(hhhM4hKJhKubh�ubh�/// @markDeprecated
�����}�(hKhh)��}�(hhhMFhKKhKubh�ubeh��%/// Constructor.
/// @markDeprecated
�h�}�h��h��h��h��h�h�h��h�]�h�Nh�Nh��ubhu)��}�(hh�Get�����}�(hKhh)��}�(hhhM,hKZhKubh�ubhjF  h]�hzj�  h{j�  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�-/// Retrieves the BaseThread for the thread.
�����}�(hKhh)��}�(hhhM'hKVhKubh�ubh�/// @markDeprecated
�����}�(hKhh)��}�(hhhMUhKWhKubh�ubh�Y/// @return												The BaseThread of the thread. @theOwnsPointed{thread,base thread}
�����}�(hKhh)��}�(hhhMjhKXhKubh�ubeh���/// Retrieves the BaseThread for the thread.
/// @markDeprecated
/// @return												The BaseThread of the thread. @theOwnsPointed{thread,base thread}
�h�}�h��h��h��h��h��BaseThread*�h��h�]�h�Nh�Nh��ubhu)��}�(hh�Start�����}�(hKhh)��}�(hhhMFhKchKubh�ubhjF  h]�hzj�  h{j�  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�/// Starts the thread running.
�����}�(hKhh)��}�(hhhM�hK]hKubh�ubh�9/// @markDeprecated Use maxon::ThreadInterface::Start().
�����}�(hKhh)��}�(hhhM�hK^hKubh�ubh�G/// @param[in] mode								The thread mode: @enumerateEnum{THREADMODE}
�����}�(hKhh)��}�(hhhMhK_hKubh�ubh�S/// @param[in] priority						The thread priority: @enumerateEnum{THREADPRIORITYEX}
�����}�(hKhh)��}�(hhhMKhK`hKubh�ubh�E/// @return												@trueIfOtherwiseFalse{the thread was started}
�����}�(hKhh)��}�(hhhM�hKahKubh�ubeh�X7  /// Starts the thread running.
/// @markDeprecated Use maxon::ThreadInterface::Start().
/// @param[in] mode								The thread mode: @enumerateEnum{THREADMODE}
/// @param[in] priority						The thread priority: @enumerateEnum{THREADPRIORITYEX}
/// @return												@trueIfOtherwiseFalse{the thread was started}
�h�}�h��h��h��h��h��Bool�h��h�]�(h�)��}�(h�
THREADMODE�hh�mode�����}�(hKhh)��}�(hhhMWhKchKubh�ubh��THREADMODE::ASYNC�h��h��h��ubh�)��}�(h�THREADPRIORITYEX�hh�priority�����}�(hKhh)��}�(hhhM�hKchKCubh�ubh��THREADPRIORITYEX::NORMAL�h��h��h��ubeh�Nh�Nh��ubhu)��}�(hh�End�����}�(hKhh)��}�(hhhMhKmhKubh�ubhjF  h]�hzj�  h{j�  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�\/// Ends the thread. This function will not return until the thread has completely stopped.
�����}�(hKhh)��}�(hhhMhKfhKubh�ubh�G/// @markDeprecated Use maxon::ThreadInterface::Wait() or GetResult().
�����}�(hKhh)��}�(hhhMchKghKubh�ubh��/// @warning If the thread does not check for TestBreak() then this function will not return until the thread has finished and this might get into a deadlock situation.
�����}�(hKhh)��}�(hhhM�hKhhKubh�ubh�\/// @param[in] wait								Determines if thread termination is synchronous or asynchronous:
�����}�(hKhh)��}�(hhhMUhKihKubh�ubh�i///																- If @formatConstant{true} the function will not return until the thread is finished.
�����}�(hKhh)��}�(hhhM�hKjhKubh�ubh��///																- If @formatConstant{false} the function returns immediately although the thread will still run until it is finished.
�����}�(hKhh)��}�(hhhMhKkhKubh�ubeh�X�  /// Ends the thread. This function will not return until the thread has completely stopped.
/// @markDeprecated Use maxon::ThreadInterface::Wait() or GetResult().
/// @warning If the thread does not check for TestBreak() then this function will not return until the thread has finished and this might get into a deadlock situation.
/// @param[in] wait								Determines if thread termination is synchronous or asynchronous:
///																- If @formatConstant{true} the function will not return until the thread is finished.
///																- If @formatConstant{false} the function returns immediately although the thread will still run until it is finished.
�h�}�h��h��h��h��h��void�h��h�]�h�)��}�(h�Bool�hh�wait�����}�(hKhh)��}�(hhhMhKmhKubh�ubh��true�h��h��h��ubah�Nh�Nh��ubhu)��}�(hh�	IsRunning�����}�(hKhh)��}�(hhhM�hKthKubh�ubhjF  h]�hzj6  h{j�  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�%/// Checks if the thread is running.
�����}�(hKhh)��}�(hhhM|hKphKubh�ubh�8/// @markDeprecated Use maxon::ThreadInterface::Wait().
�����}�(hKhh)��}�(hhhM�hKqhKubh�ubh�D/// @return												@trueIfOtherwiseFalse{the thread is running}
�����}�(hKhh)��}�(hhhM�hKrhKubh�ubeh���/// Checks if the thread is running.
/// @markDeprecated Use maxon::ThreadInterface::Wait().
/// @return												@trueIfOtherwiseFalse{the thread is running}
�h�}�h��h��h��h��h��Bool�h��h�]�h�Nh�Nh��ubhu)��}�(hh�	TestBreak�����}�(hKhh)��}�(hhhM{hK~hKubh�ubhjF  h]�hzjV  h{j�  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�H/// Checks if the thread received a break command to stop processing.\n
�����}�(hKhh)��}�(hhhMhKwhKubh�ubh�V/// Normally this is only true when @C4D is closing, or when End() has been called.\n
�����}�(hKhh)��}�(hhhM\hKxhKubh�ubh�w/// This function is used by the Semaphore class during the Semaphore::Lock() to check if the thread has been stopped.
�����}�(hKhh)��}�(hhhM�hKyhKubh�ubh�?/// @markDeprecated Use maxon::ThreadInterface::IsCancelled().
�����}�(hKhh)��}�(hhhM+hKzhKubh�ubh�a/// @note Check for break conditions, such as if @em ESC has been pressed outside of the thread.
�����}�(hKhh)��}�(hhhMkhK{hKubh�ubh�L/// @return												@trueOtherwiseFalse{processing should be terminated}
�����}�(hKhh)��}�(hhhM�hK|hKubh�ubeh�X  /// Checks if the thread received a break command to stop processing.\n
/// Normally this is only true when @C4D is closing, or when End() has been called.\n
/// This function is used by the Semaphore class during the Semaphore::Lock() to check if the thread has been stopped.
/// @markDeprecated Use maxon::ThreadInterface::IsCancelled().
/// @note Check for break conditions, such as if @em ESC has been pressed outside of the thread.
/// @return												@trueOtherwiseFalse{processing should be terminated}
�h�}�h��h��h��h��h��Bool�h��h�]�h�Nh�Nh��ubhu)��}�(hh�Wait�����}�(hKhh)��}�(hhhMkhK�hKubh�ubhjF  h]�hzj�  h{j�  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�)/// Waits until the thread has finished.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�G/// @markDeprecated Use maxon::ThreadInterface::Wait() or GetResult().
�����}�(hKhh)��}�(hhhMhK�hKubh�ubh��/// @param[in] checkevents				If @formatConstant{false} then wait until the thread has finished. If @formatConstant{true} then additionally return if a @C4D event occurred.
�����}�(hKhh)��}�(hhhM\hK�hKubh�ubeh�X  /// Waits until the thread has finished.
/// @markDeprecated Use maxon::ThreadInterface::Wait() or GetResult().
/// @param[in] checkevents				If @formatConstant{false} then wait until the thread has finished. If @formatConstant{true} then additionally return if a @C4D event occurred.
�h�}�h��h��h��h��h��void�h��h�]�h�)��}�(h�Bool�hh�checkevents�����}�(hKhh)��}�(hhhMuhK�hKubh�ubh��false�h��h��h��ubah�Nh�Nh��ubhu)��}�(hh�
TestDBreak�����}�(hKhh)��}�(hhhMLhK�hKubh�ubhjF  h]�hzj�  h{j�  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�j/// Override to add user breaks such as pressing the @em ESC key. This function is called by TestBreak().
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�?/// @markDeprecated Use maxon::ThreadInterface::IsCancelled().
�����}�(hKhh)��}�(hhhMThK�hKubh�ubh�N/// @return												@trueIfOtherwiseFalse{processing should be terminated}
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubeh���/// Override to add user breaks such as pressing the @em ESC key. This function is called by TestBreak().
/// @markDeprecated Use maxon::ThreadInterface::IsCancelled().
/// @return												@trueIfOtherwiseFalse{processing should be terminated}
�h�}�h��h��h��h��h��Bool�h��h�]�h�Nh�Nh��ubhu)��}�(hh�Main�����}�(hKhh)��}�(hhhM�hK�hKubh�ubhjF  h]�hzj�  h{j�  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�(/// Override with the thread main code.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�?/// @markDeprecated Use maxon::ThreadInterface::operator ()().
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubeh��g/// Override with the thread main code.
/// @markDeprecated Use maxon::ThreadInterface::operator ()().
�h�}�h��h��h��h��h��void�h��h�]�h�Nh�Nh��ubhu)��}�(hh�GetThreadName�����}�(hKhh)��}�(hhhM0 hK�hKubh�ubhjF  h]�hzj�  h{j�  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�//// Override to return the name of the thread.
�����}�(hKhh)��}�(hhhMhK�hKubh�ubh�0/// @markDeprecated Use maxon::ThreadInterface.
�����}�(hKhh)��}�(hhhM=hK�hKubh�ubh�Q/// @return												The thread name. @theOwnsPointed{thread,character buffer}
�����}�(hKhh)��}�(hhhMnhK�hKubh�ubeh���/// Override to return the name of the thread.
/// @markDeprecated Use maxon::ThreadInterface.
/// @return												The thread name. @theOwnsPointed{thread,character buffer}
�h�}�h��h��h��h��h��const Char*�h��h�]�h�Nh�Nh��ubehzjJ  h{j  h�j  h8Nh�NhNh�Nh�Nh�K h�]�(h�/// %User thread object.
�����}�(hKhh)��}�(hhhM�
hK:hKubh�ubh�A/// @markDeprecated Use maxon::ThreadInterface/JobInterface etc.
�����}�(hKhh)��}�(hhhM�
hK;hKubh�ubeh��Z/// %User thread object.
/// @markDeprecated Use maxon::ThreadInterface/JobInterface etc.
�h�}�h��j,  ]�j.  Nj/  Nh��j0  Nj1  Nj2  �j3  �j4  �j5  �j6  �h��j7  �j8  �j9  Nj:  �j;  �j<  ]�j>  ]�j@  ]�jB  ]�jD  }�ubhu)��}�(hh�GeGetCurrentThreadCount�����}�(hKhh)��}�(hhhM3"hK�hKubh�ubhhh]�hzj!  h{j  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�Q/// Retrieves the number of threads being used for the current (render) context.
�����}�(hKhh)��}�(hhhM� hK�hKubh�ubh��/// @note This might be smaller than the actual CPU core or thread count if the user selected a custom number of render threads.
�����}�(hKhh)��}�(hhhM� hK�hKubh�ubh�Q/// @return												The number of threads being used for the current context.
�����}�(hKhh)��}�(hhhMz!hK�hKubh�ubeh�X#  /// Retrieves the number of threads being used for the current (render) context.
/// @note This might be smaller than the actual CPU core or thread count if the user selected a custom number of render threads.
/// @return												The number of threads being used for the current context.
�h�}�h��h��h��h��h��Int32�h��h�]�h�Nh�Nh��ubhu)��}�(hh�GeThreadLock�����}�(hKhh)��}�(hhhM�$hK�hKubh�ubhhh]�hzjA  h{j  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h��/// A global semaphore. When this is locked, any other thread trying to acquire the lock will have to wait. Other threads will continue.
�����}�(hKhh)��}�(hhhM�"hK�hKubh�ubh�/// @markDeprecated
�����}�(hKhh)��}�(hhhMd#hK�hKubh�ubh��/// @warning As this blocks all threads it should only be used if and when necessary, a local semaphore is a more elegant and efficient solution to multiple thread data access.
�����}�(hKhh)��}�(hhhMx#hK�hKubh�ubeh�XN  /// A global semaphore. When this is locked, any other thread trying to acquire the lock will have to wait. Other threads will continue.
/// @markDeprecated
/// @warning As this blocks all threads it should only be used if and when necessary, a local semaphore is a more elegant and efficient solution to multiple thread data access.
�h�}�h��h��h��h��h��void�h��h�]�h�Nh�Nh��ubhu)��}�(hh�GeThreadUnlock�����}�(hKhh)��}�(hhhM�%hK�hKubh�ubhhh]�hzja  h{j  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�>/// Continues blocked threads after a call to GeThreadLock().
�����}�(hKhh)��}�(hhhM%hK�hKubh�ubh�/// @markDeprecated
�����}�(hKhh)��}�(hhhMY%hK�hKubh�ubeh��R/// Continues blocked threads after a call to GeThreadLock().
/// @markDeprecated
�h�}�h��h��h��h��h��void�h��h�]�h�Nh�Nh��ubhu)��}�(hh�IdentifyThread�����}�(hKhh)��}�(hhhM�'hK�hKubh�ubhhh]�hzj{  h{j  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�%/// Identifies the type of a thread.
�����}�(hKhh)��}�(hhhMc&hK�hKubh�ubh�M/// @param[in] bt									The thread to identify. @callerOwnsPointed{thread}
�����}�(hKhh)��}�(hhhM�&hK�hKubh�ubh�C/// @return												The thread type: @enumerateEnum{THREADTYPE}
�����}�(hKhh)��}�(hhhM�&hK�hKubh�ubeh���/// Identifies the type of a thread.
/// @param[in] bt									The thread to identify. @callerOwnsPointed{thread}
/// @return												The thread type: @enumerateEnum{THREADTYPE}
�h�}�h��h��h��h��h��
THREADTYPE�h��h�]�h�)��}�(h�BaseThread*�hh�bt�����}�(hKhh)��}�(hhhM�'hK�hK.ubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhu)��}�(hh�GeGetCurrentThreadId�����}�(hKhh)��}�(hhhM1)hK�hKubh�ubhhh]�hzj�  h{j  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�2/// Retrieves a unique ID for the current thread.
�����}�(hKhh)��}�(hhhM#(hK�hKubh�ubh�6/// @note Usually you do not have to care about this.
�����}�(hKhh)��}�(hhhMU(hK�hKubh�ubh�=/// @return												The unique ID for the current thread.
�����}�(hKhh)��}�(hhhM�(hK�hKubh�ubeh���/// Retrieves a unique ID for the current thread.
/// @note Usually you do not have to care about this.
/// @return												The unique ID for the current thread.
�h�}�h��h��h��h��h��UInt32�h��h�]�h�Nh�Nh��ubhu)��}�(hh�GeGetCurrentThread�����}�(hKhh)��}�(hhhM�*hK�hKubh�ubhhh]�hzj�  h{j  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�"/// Retrieves the current thread.
�����}�(hKhh)��}�(hhhM�)hK�hKubh�ubh�+/// @return												The current thread.
�����}�(hKhh)��}�(hhhM�)hK�hKubh�ubeh��M/// Retrieves the current thread.
/// @return												The current thread.
�h�}�h��h��h��h��h��BaseThread*�h��h�]�h�Nh�Nh��ubhu)��}�(hh�GeGetDummyThread�����}�(hKhh)��}�(hhhMF,hK�hKubh�ubhhh]�hzj�  h{j  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�T/// Returns a dummy thread (TestBreak() will always return @formatConstant{false}).
�����}�(hKhh)��}�(hhhM$+hK�hKubh�ubh�/// @since R17.032
�����}�(hKhh)��}�(hhhMx+hK�hKubh�ubh�M/// @return												A pointer to a dummy thread (guaranteed to be valid).
�����}�(hKhh)��}�(hhhM�+hK�hKubh�ubeh���/// Returns a dummy thread (TestBreak() will always return @formatConstant{false}).
/// @since R17.032
/// @return												A pointer to a dummy thread (guaranteed to be valid).
�h�}�h��h��h��h��h��BaseThread*�h��h�]�h�Nh�Nh��ubhu)��}�(hh�GeGetEscTestThread�����}�(hKhh)��}�(hhhM3.hK�hKubh�ubhhh]�hzj�  h{j  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h��/// Returns a dummy thread for escape key testing (TestBreak() will return @formatConstant{true}, when the user presses the Esc key).
�����}�(hKhh)��}�(hhhM�,hK�hKubh�ubh�/// @since R17.032
�����}�(hKhh)��}�(hhhMZ-hK�hKubh�ubh�X/// @return												A pointer to an escape key test thread (guaranteed to be valid).
�����}�(hKhh)��}�(hhhMm-hK�hKubh�ubeh���/// Returns a dummy thread for escape key testing (TestBreak() will return @formatConstant{true}, when the user presses the Esc key).
/// @since R17.032
/// @return												A pointer to an escape key test thread (guaranteed to be valid).
�h�}�h��h��h��h��h��BaseThread*�h��h�]�h�Nh�Nh��ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhMq.hK�hKubh�ububhj)��}�(hh�AutoLock�����}�(hKhh)��}�(hhhM�/hK�hKubh�ubhhh]�(jP  )��}�(hh�lock�����}�(hKhh)��}�(hhhM-0hK�hKubh�ubhj#  h]�hzj0  h{h�private�����}�(hKhh)��}�(hhhM�/hK�hKubh�ubh�j`  h8Nh�Nh�maxon::Spinlock�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubjP  )��}�(hh�threadid�����}�(hKhh)��}�(hhhMD0hK�hKubh�ubhj#  h]�hzjB  h{j7  h�j`  h8Nh�Nh�volatile UInt32�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubhu)��}�(hhxhj#  h]�hzhxh{j7  h�hxh8Nh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��h��h��h�h�h��h�]�h�)��}�(h�const AutoLock&�hh�al�����}�(hKhh)��}�(hhhMh0hK�hKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhu)��}�(hhxhj#  h]�hzhxh{j7  h�hxh8Nh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��h��h��h�h�h��h�]�h�)��}�(h�const AutoLocker&�hh�al�����}�(hKhh)��}�(hhhM�0hK�hKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhu)��}�(hhxhj#  h]�hzhxh{h�public�����}�(hKhh)��}�(hhhM�0hK�hKubh�ubh�hxh8Nh�NhNh�Nh�Nh�K h�]�h�/// Constructor.
�����}�(hKhh)��}�(hhhM�0hK�hKubh�ubah��/// Constructor.
�h�}�h��h��h��h��h�h�h��h�]�h�Nh�Nh��ubehzj'  h{j  h�j  h8Nh�NhNh�Nh�Nh�K h�]�(h�E/// Has to be embedded in a structure to be protected by AutoLocker.
�����}�(hKhh)��}�(hhhM�.hK�hKubh�ubh�/// @markDeprecated
�����}�(hKhh)��}�(hhhM-/hK�hKubh�ubh�(/// @note Needs the keyword @c mutable.
�����}�(hKhh)��}�(hhhMA/hK�hKubh�ubh�$/// @see AutoLocker for an example.
�����}�(hKhh)��}�(hhhMi/hK�hKubh�ubeh���/// Has to be embedded in a structure to be protected by AutoLocker.
/// @markDeprecated
/// @note Needs the keyword @c mutable.
/// @see AutoLocker for an example.
�h�}�h��j,  ]�j.  Nj/  Nh��j0  Nj1  Nj2  �j3  �j4  �j5  �j6  �h��j7  �j8  �j9  Nj:  �j;  �j<  ]�j>  ]�j@  ]�jB  ]�jD  }�ubhj)��}�(hh�
AutoLocker�����}�(hKhh)��}�(hhhM�:hM+hKubh�ubhhh]�(jP  )��}�(hh�l�����}�(hKhh)��}�(hhhM�:hM.hKubh�ubhj�  h]�hzj�  h{h�private�����}�(hKhh)��}�(hhhM�:hM-hKubh�ubh�j`  h8Nh�Nh�maxon::Spinlock*�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubjP  )��}�(hh�ct�����}�(hKhh)��}�(hhhM�:hM/hKubh�ubhj�  h]�hzj�  h{j�  h�j`  h8Nh�Nh�volatile UInt32*�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubhu)��}�(hh�
operator =�����}�(hKhh)��}�(hhhM�:hM0hKubh�ubhj�  h]�hzj�  h{j�  h�h�h8Nh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��h��h��h��AutoLocker&�h��h�]�h�)��}�(h�const AutoLocker&�hh�d�����}�(hKhh)��}�(hhhM�:hM0hK/ubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhu)��}�(hhxhj�  h]�hzhxh{j�  h�hxh8Nh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��h��h��h�h�h��h�]�h�)��}�(h�AutoLocker&�hh�data�����}�(hKhh)��}�(hhhM;hM1hKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhu)��}�(hhxhj�  h]�hzhxh{h�public�����}�(hKhh)��}�(hhhM;hM3hKubh�ubh�hxh8Nh�NhNh�Nh�Nh�K h�]�h�/// Default constructor.
�����}�(hKhh)��}�(hhhMy;hM5hKubh�ubah��/// Default constructor.
�h�}�h��h��h��h��h�h�h��h�]�h�Nh�Nh��ubhu)��}�(hhxhj�  h]�hzhxh{j�  h�hxh8Nh�NhNh�Nh�Nh�K h�]�(h�/// Copy constructor.
�����}�(hKhh)��}�(hhhM<hM>hKubh�ubh�/// @since R17.032
�����}�(hKhh)��}�(hhhM�<hM?hKubh�ubh�1/// @param[in] src								The source AutoLocker.
�����}�(hKhh)��}�(hhhM�<hM@hKubh�ubeh��Z/// Copy constructor.
/// @since R17.032
/// @param[in] src								The source AutoLocker.
�h�}�h��h��h��h��h�h�h��h�]�h�)��}�(h�AutoLocker&&�hh�src�����}�(hKhh)��}�(hhhMP=hMBhKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhu)��}�(hhxhj�  h]�hzhxh{j�  h�hxh8Nh�NhNh�Nh�Nh�K h�]�(h�/// Locks the passed AutoLock.
�����}�(hKhh)��}�(hhhM�=hMIhKubh�ubh�1/// @param[in] data								The AutoLock to lock.
�����}�(hKhh)��}�(hhhM>hMJhKubh�ubeh��P/// Locks the passed AutoLock.
/// @param[in] data								The AutoLock to lock.
�h�}�h��h��h��h��h�h�h��h�]�h�)��}�(h�	AutoLock&�hh�data�����}�(hKhh)��}�(hhhM�>hMLhK ubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhu)��}�(hh�DoLock�����}�(hKhh)��}�(hhhM�@hM_hKubh�ubhj�  h]�hzj=  h{j�  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�/// Locks the passed AutoLock.
�����}�(hKhh)��}�(hhhMG@hM\hKubh�ubh�1/// @param[in] data								The AutoLock to lock.
�����}�(hKhh)��}�(hhhMg@hM]hKubh�ubeh��P/// Locks the passed AutoLock.
/// @param[in] data								The AutoLock to lock.
�h�}�h��h��h��h��h��void�h��h�]�h�)��}�(h�	AutoLock&�hh�data�����}�(hKhh)��}�(hhhMAhM_hKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhu)��}�(hh�Unlock�����}�(hKhh)��}�(hhhM�BhMrhKubh�ubhj�  h]�hzj`  h{j�  h�h�h8Nh�NhNh�Nh�Nh�K h�]�h�!/// Unlocks the locked AutoLock.
�����}�(hKhh)��}�(hhhM+BhMphKubh�ubah��!/// Unlocks the locked AutoLock.
�h�}�h��h��h��h��h��void�h��h�]�h�Nh�Nh��ubehzj�  h{j  h�j  h8Nh�NhNh�Nh�Nh�K h�]�(h�D/// A class for thread-safe code access within its current scope.\n
�����}�(hKhh)��}�(hhhM�1hK�hKubh�ubh�0/// please be aware that this is depreciated.\n
�����}�(hKhh)��}�(hhhM22hK�hKubh�ubh�/// @b Example:<br>
�����}�(hKhh)��}�(hhhMb2hK�hKubh�ubh�:/// Embed AutoLock in a class that needs to be protected.
�����}�(hKhh)��}�(hhhMv2hK�hKubh�ubh�
/// @code
�����}�(hKhh)��}�(hhhM�2hK�hKubh�ubh�/// class DriverHelper
�����}�(hKhh)��}�(hhhM�2hK�hKubh�ubh�/// {
�����}�(hKhh)��}�(hhhM�2hK�hKubh�ubh�/// 	public:
�����}�(hKhh)��}�(hhhM�2hK�hKubh�ubh�
/// 		...
�����}�(hKhh)��}�(hhhM�2hK�hKubh�ubh�9/// 		mutable AutoLock lock; // Note the keyword mutable
�����}�(hKhh)��}�(hhhM�2hK�hKubh�ubh�/// };
�����}�(hKhh)��}�(hhhM'3hK�hKubh�ubh�/// @endcode
�����}�(hKhh)��}�(hhhM.3hK�hKubh�ubh�/// In a member function:
�����}�(hKhh)��}�(hhhM;3hK�hKubh�ubh�
/// @code
�����}�(hKhh)��}�(hhhMU3hK�hKubh�ubh�%/// void DriverHelper::FunctionXYZ()
�����}�(hKhh)��}�(hhhM_3hK�hKubh�ubh�/// {
�����}�(hKhh)��}�(hhhM�3hM hKubh�ubh�/// 	AutoLocker al(lock);
�����}�(hKhh)��}�(hhhM�3hMhKubh�ubh�///
�����}�(hKhh)��}�(hhhM�3hMhKubh�ubh�/// 	// Do something
�����}�(hKhh)��}�(hhhM�3hMhKubh�ubh�/// }
�����}�(hKhh)��}�(hhhM�3hMhKubh�ubh�/// @endcode
�����}�(hKhh)��}�(hhhM�3hMhKubh�ubh��/// AutoLocker guarantees that all code within the member function can be accessed thread-safe as no other thread can have access at the same time.\n
�����}�(hKhh)��}�(hhhM�3hMhKubh�ubh��/// This does not solve the general problem of deadlocks that can occur if the calls are done cross-wise, meaning calls between threads.\n
�����}�(hKhh)��}�(hhhMf4hMhKubh�ubh�}/// AutoLocker has the advantage over Spinlock that calls of subroutines with the same protection will not get a deadlock.\n
�����}�(hKhh)��}�(hhhM�4hMhKubh�ubh��/// Also, AutoLocker will automatically unlock everything, so there are no missing Unlock() calls (can be tricky if the code returns at multiple places otherwise).
�����}�(hKhh)��}�(hhhMn5hM	hKubh�ubh�///
�����}�(hKhh)��}�(hhhM6hM
hKubh�ubh�G/// Another example of recursive or deep calls with the same AutoLock:
�����}�(hKhh)��}�(hhhM6hMhKubh�ubh�
/// @code
�����}�(hKhh)��}�(hhhM]6hMhKubh�ubh�/// class ClassA
�����}�(hKhh)��}�(hhhMg6hMhKubh�ubh�/// {
�����}�(hKhh)��}�(hhhMx6hMhKubh�ubh�/// 	public:
�����}�(hKhh)��}�(hhhM~6hMhKubh�ubh�/// 	AutoLock lock;
�����}�(hKhh)��}�(hhhM�6hMhKubh�ubh�///
�����}�(hKhh)��}�(hhhM�6hMhKubh�ubh�/// 	void FunctionA()
�����}�(hKhh)��}�(hhhM�6hMhKubh�ubh�/// 	{
�����}�(hKhh)��}�(hhhM�6hMhKubh�ubh�/// 		AutoLocker al(lock);
�����}�(hKhh)��}�(hhhM�6hMhKubh�ubh�///
�����}�(hKhh)��}�(hhhM�6hMhKubh�ubh�
/// 		...
�����}�(hKhh)��}�(hhhM�6hMhKubh�ubh�(/// 		FunctionB(doc->GetFirstObject());
�����}�(hKhh)��}�(hhhM�6hMhKubh�ubh�
/// 		...
�����}�(hKhh)��}�(hhhM7hMhKubh�ubh�/// 	}
�����}�(hKhh)��}�(hhhM7hMhKubh�ubh�///
�����}�(hKhh)��}�(hhhM"7hMhKubh�ubh�$/// 	void FunctionB(BaseObject *op)
�����}�(hKhh)��}�(hhhM&7hMhKubh�ubh�/// 	{
�����}�(hKhh)��}�(hhhMJ7hMhKubh�ubh�/// 		AutoLocker al(lock);
�����}�(hKhh)��}�(hhhMQ7hMhKubh�ubh�///
�����}�(hKhh)��}�(hhhMl7hMhKubh�ubh�
/// 		...
�����}�(hKhh)��}�(hhhMp7hMhKubh�ubh� /// 		FunctionB(op->GetDown());
�����}�(hKhh)��}�(hhhMz7hM hKubh�ubh�
/// 		...
�����}�(hKhh)��}�(hhhM�7hM!hKubh�ubh�/// 	}
�����}�(hKhh)��}�(hhhM�7hM"hKubh�ubh�/// };
�����}�(hKhh)��}�(hhhM�7hM#hKubh�ubh�/// @endcode
�����}�(hKhh)��}�(hhhM�7hM$hKubh�ubh��/// Both @c FunctionB() calls are fine and will not cause deadlocks. It is important that the lock is performed on the same AutoLock otherwise you will run into deadlocks.
�����}�(hKhh)��}�(hhhM�7hM%hKubh�ubh�///
�����}�(hKhh)��}�(hhhMk8hM&hKubh�ubh�Z/// @note	Should be used for fast methods, for instance to serialize short data access.\n
�����}�(hKhh)��}�(hhhMo8hM'hKubh�ubh��///				As an example within normal objects or GUI managers where routines are called by maybe 1 or 2 threads. In an object for instance one for the viewport and one for generation/execution and maybe a message from another thread.\n
�����}�(hKhh)��}�(hhhM�8hM(hKubh�ubh�n///				Should be avoided for rendering though where locking to access one thread will seriously impair speed.
�����}�(hKhh)��}�(hhhM�9hM)hKubh�ubeh�X2  /// A class for thread-safe code access within its current scope.\n
/// please be aware that this is depreciated.\n
/// @b Example:<br>
/// Embed AutoLock in a class that needs to be protected.
/// @code
/// class DriverHelper
/// {
/// 	public:
/// 		...
/// 		mutable AutoLock lock; // Note the keyword mutable
/// };
/// @endcode
/// In a member function:
/// @code
/// void DriverHelper::FunctionXYZ()
/// {
/// 	AutoLocker al(lock);
///
/// 	// Do something
/// }
/// @endcode
/// AutoLocker guarantees that all code within the member function can be accessed thread-safe as no other thread can have access at the same time.\n
/// This does not solve the general problem of deadlocks that can occur if the calls are done cross-wise, meaning calls between threads.\n
/// AutoLocker has the advantage over Spinlock that calls of subroutines with the same protection will not get a deadlock.\n
/// Also, AutoLocker will automatically unlock everything, so there are no missing Unlock() calls (can be tricky if the code returns at multiple places otherwise).
///
/// Another example of recursive or deep calls with the same AutoLock:
/// @code
/// class ClassA
/// {
/// 	public:
/// 	AutoLock lock;
///
/// 	void FunctionA()
/// 	{
/// 		AutoLocker al(lock);
///
/// 		...
/// 		FunctionB(doc->GetFirstObject());
/// 		...
/// 	}
///
/// 	void FunctionB(BaseObject *op)
/// 	{
/// 		AutoLocker al(lock);
///
/// 		...
/// 		FunctionB(op->GetDown());
/// 		...
/// 	}
/// };
/// @endcode
/// Both @c FunctionB() calls are fine and will not cause deadlocks. It is important that the lock is performed on the same AutoLock otherwise you will run into deadlocks.
///
/// @note	Should be used for fast methods, for instance to serialize short data access.\n
///				As an example within normal objects or GUI managers where routines are called by maybe 1 or 2 threads. In an object for instance one for the viewport and one for generation/execution and maybe a message from another thread.\n
///				Should be avoided for rendering though where locking to access one thread will seriously impair speed.
�h�}�h��j,  ]�j.  Nj/  Nh��j0  Nj1  Nj2  �j3  �j4  �j5  �j6  �h��j7  �j8  �j9  Nj:  �j;  �j<  ]�j>  ]�j@  ]�jB  ]�jD  }�ubhj)��}�(hh�
AutoRWLock�����}�(hKhh)��}�(hhhM^DhM�hKubh�ubhhh]�(jP  )��}�(hh�lock�����}�(hKhh)��}�(hhhM�DhM�hKubh�ubhj�  h]�hzj�  h{�private�h�j`  h8Nh�Nh�maxon::RWSpinlock�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubjP  )��}�(hh�threadid�����}�(hKhh)��}�(hhhM�DhM�hKubh�ubhj�  h]�hzj�  h{j�  h�j`  h8Nh�Nh�volatile UInt32�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubhu)��}�(hhxhj�  h]�hzhxh{h�public�����}�(hKhh)��}�(hhhM�DhM�hKubh�ubh�hxh8Nh�NhNh�Nh�Nh�K h�]�h�/// Constructor.
�����}�(hKhh)��}�(hhhM!EhM�hKubh�ubah��/// Constructor.
�h�}�h��h��h��h��h�h�h��h�]�h�Nh�Nh��ubehzj�  h{j  h�j  h8Nh�NhNh�Nh�Nh�K h�]�(h�G/// Has to be embedded in a structure to be protected by AutoRWLocker.
�����}�(hKhh)��}�(hhhMzChM~hKubh�ubh�%/// @note Needs the keyword mutable.
�����}�(hKhh)��}�(hhhM�ChMhKubh�ubh�/// @see AutoRWLocker.
�����}�(hKhh)��}�(hhhM�ChM�hKubh�ubeh���/// Has to be embedded in a structure to be protected by AutoRWLocker.
/// @note Needs the keyword mutable.
/// @see AutoRWLocker.
�h�}�h��j,  ]�j.  Nj/  Nh��j0  Nj1  Nj2  �j3  �j4  �j5  �j6  �h��j7  �j8  �j9  Nj:  �j;  �j<  ]�j>  ]�j@  ]�jB  ]�jD  }�ubhj)��}�(hh�AutoRWLocker�����}�(hKhh)��}�(hhhM�FhM�hKubh�ubhhh]�(jP  )��}�(hh�l�����}�(hKhh)��}�(hhhMGhM�hKubh�ubhj  h]�hzj,  h{h�private�����}�(hKhh)��}�(hhhM GhM�hKubh�ubh�j`  h8Nh�Nh�maxon::RWSpinlock*�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubjP  )��}�(hh�ct�����}�(hKhh)��}�(hhhM2GhM�hKubh�ubhj  h]�hzj>  h{j3  h�j`  h8Nh�Nh�volatile UInt32*�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubjP  )��}�(hh�is_write�����}�(hKhh)��}�(hhhMEGhM�hKubh�ubhj  h]�hzjJ  h{j3  h�j`  h8Nh�Nh�volatile Bool�h�Nh�Nh�K h�]�h�h	h�}�h��h��ubhu)��}�(hh�
operator =�����}�(hKhh)��}�(hhhM^GhM�hKubh�ubhj  h]�hzjV  h{j3  h�h�h8Nh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��h��h��h��AutoRWLocker&�h��h�]�h�)��}�(h�const AutoRWLocker&�hh�d�����}�(hKhh)��}�(hhhM~GhM�hK0ubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhu)��}�(hhxhj  h]�hzhxh{j3  h�hxh8Nh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��h��h��h�h�h��h�]�h�)��}�(h�AutoRWLocker&�hh�lock�����}�(hKhh)��}�(hhhM�GhM�hKubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhu)��}�(hhxhj  h]�hzhxh{h�public�����}�(hKhh)��}�(hhhM�GhM�hKubh�ubh�hxh8Nh�NhNh�Nh�Nh�K h�]�h�/// Default constructor.
�����}�(hKhh)��}�(hhhMHhM�hKubh�ubah��/// Default constructor.
�h�}�h��h��h��h��h�h�h��h�]�h�Nh�Nh��ubhu)��}�(hhxhj  h]�hzhxh{j|  h�hxh8Nh�NhNh�Nh�Nh�K h�]�(h�!/// Locks the passed AutoRWLock.
�����}�(hKhh)��}�(hhhM'IhM�hKubh�ubh�3/// @param[in] lock								The AutoRWLock to lock.
�����}�(hKhh)��}�(hhhMIIhM�hKubh�ubh�s/// @param[in] write_lock					@formatConstant{true} for write access, @formatConstant{false} for read access only.
�����}�(hKhh)��}�(hhhM}IhM�hKubh�ubeh���/// Locks the passed AutoRWLock.
/// @param[in] lock								The AutoRWLock to lock.
/// @param[in] write_lock					@formatConstant{true} for write access, @formatConstant{false} for read access only.
�h�}�h��h��h��h��h�h�h��h�]�(h�)��}�(h�AutoRWLock&�hh�lock�����}�(hKhh)��}�(hhhMoJhM�hK$ubh�ubh�Nh��h��h��ubh�)��}�(h�Bool�hh�
write_lock�����}�(hKhh)��}�(hhhMzJhM�hK/ubh�ubh��true�h��h��h��ubeh�Nh�Nh��ubhu)��}�(hh�DoLock�����}�(hKhh)��}�(hhhM]MhM�hKubh�ubhj  h]�hzj�  h{j|  h�h�h8Nh�NhNh�Nh�Nh�K h�]�(h�!/// Locks the passed AutoRWLock.
�����}�(hKhh)��}�(hhhM2LhM�hKubh�ubh�3/// @param[in] lock								The AutoRWLock to lock.
�����}�(hKhh)��}�(hhhMTLhM�hKubh�ubh�s/// @param[in] write_lock					@formatConstant{true} for write access, @formatConstant{false} for read access only.
�����}�(hKhh)��}�(hhhM�LhM�hKubh�ubeh���/// Locks the passed AutoRWLock.
/// @param[in] lock								The AutoRWLock to lock.
/// @param[in] write_lock					@formatConstant{true} for write access, @formatConstant{false} for read access only.
�h�}�h��h��h��h��h��void�h��h�]�(h�)��}�(h�AutoRWLock&�hh�lock�����}�(hKhh)��}�(hhhMpMhM�hKubh�ubh�Nh��h��h��ubh�)��}�(h�Bool�hh�
write_lock�����}�(hKhh)��}�(hhhM{MhM�hK%ubh�ubh��true�h��h��h��ubeh�Nh�Nh��ubhu)��}�(hh�Unlock�����}�(hKhh)��}�(hhhM�OhM�hKubh�ubhj  h]�hzj�  h{j|  h�h�h8Nh�NhNh�Nh�Nh�K h�]�h�#/// Unlocks the locked AutoRWLock.
�����}�(hKhh)��}�(hhhMOhM�hKubh�ubah��#/// Unlocks the locked AutoRWLock.
�h�}�h��h��h��h��h��void�h��h�]�h�Nh�Nh��ubehzj#  h{j  h�j  h8Nh�NhNh�Nh�Nh�K h�]�(h�Q/// Much the same as AutoLocker but allows differentiation of read/write access.
�����}�(hKhh)��}�(hhhMFhM�hKubh�ubh�"/// @see AutoLocker for examples.
�����}�(hKhh)��}�(hhhMnFhM�hKubh�ubeh��s/// Much the same as AutoLocker but allows differentiation of read/write access.
/// @see AutoLocker for examples.
�h�}�h��j,  ]�j.  Nj/  Nh��j0  Nj1  Nj2  �j3  �j4  �j5  �j6  �h��j7  �j8  �j9  Nj:  �j;  �j<  ]�j>  ]�j@  ]�jB  ]�jD  }�ubhu)��}�(hh�MaxonConvert�����}�(hKhh)��}�(hhhM<PhM�hKubh�ubhhh]�hzj  h{j  h�h�h8Nh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��h��h��h��maxon::ThreadRef�h��h�]�h�)��}�(h�BaseThread*�hh�thread�����}�(hKhh)��}�(hhhMUPhM�hK+ubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhu)��}�(hh�MaxonConvert�����}�(hKhh)��}�(hhhMjPhM�hKubh�ubhhh]�hzj,  h{j  h�h�h8Nh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��h��h��h��BaseThread*�h��h�]�h�)��}�(h�const maxon::ThreadRef&�hh�thread�����}�(hKhh)��}�(hhhM�PhM�hK2ubh�ubh�Nh��h��h��ubah�Nh�Nh��ubhu)��}�(hh�MaxonConvert�����}�(hKhh)��}�(hhhM�PhM�hKubh�ubhhh]�hzjB  h{j  h�h�h8Nh�NhNh�Nh�Nh�K h�]�h�h	h�}�h��h��h��h��h��BaseThread*�h��h�]�h�)��}�(h�const maxon::ThreadInterface*�hh�thread�����}�(hKhh)��}�(hhhM�PhM�hK8ubh�ubh�Nh��h��h��ubah�Nh�Nh��ubh)��}�(hNhhh]�h h� #ifdef CINEWARE_NAMESPACE_ENABLE�����}�(hK
hh)��}�(hhhM�PhM�hKubh�ububh)��}�(hNhhh]�h h�CINEWARE_NAMESPACE_END�����}�(hK
hh)��}�(hhhM�PhM�hKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhMQhM�hKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhMQhM�hKubh�ububehzhh{j  h��	namespace�h8Nh�NhNh�Nh�Nh�K h�]�h�h	h�}�h���preprocessorConditions�]��root�hh ]�(hh'h2h9hBhFhJhNhWh`hkjF  j  j=  j]  jw  j�  j�  j�  j�  j  hj)��}�(hh�
AutoLocker�����}�(hKhh)��}�(hhhM�.hK�hKubh�ubhhh]�hzj�  h{j  h�j  h8Nh�NhNh�Nh�Nh�K h�]�h�Nh�}�h��j,  ]�j.  Nj/  Nh��j0  Nj1  Nj2  �j3  �j4  �j5  �j6  �h��j7  �j8  �j9  Nj:  �j;  �j<  ]�j>  ]�j@  ]�jB  ]�jD  }�ubj#  j�  j�  j  j  j(  j>  jT  j]  jf  jo  e�containsResourceId���registry��j<  ���hxx1�N�hxx2�N�snippets�}��minIndentation�K �maxIndentation�K �firstMember���forwardHeaders���ub.