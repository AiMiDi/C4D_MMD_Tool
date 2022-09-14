����      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��PD:\C4D_MMD_Tool\sdk_2023\frameworks\core.framework\source\maxon\reflectionbase.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/parametertype.h�hhh]��quote��"��template�Nubh()��}�(h�maxon/hashmap.h�hhh]�h-h.h/Nubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhK~hKhKubh�ubhhh]�h)��}�(hh�
reflection�����}�(hKhh)��}�(hhhK�hK
hKubh�ubhh4h]�(h �Class���)��}�(hh�Member�����}�(hKhh)��}�(hhhMqhKhKubh�ubhh=h]�(h �Enum���)��}�(hh�KIND�����}�(hKhh)��}�(hhhM*hK'hKubh�ubhhHh]�(h �	EnumValue���)��}�(hh�PACKAGE�����}�(hKhh)��}�(hhhM4hK)hKubh�ubhhSh]��
simpleName�hb�access��public��kind��	enumvalue�h/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]�h�///< The member is a Package.
�����}�(hKhh)��}�(hhhMIhK)hKubh�uba�doc��///< The member is a Package.
��annotations�}��	anonymous���value��1�ubh])��}�(hh�CLASS�����}�(hKhh)��}�(hhhMihK*hKubh�ubhhSh]�hgh�hhhihjhkh/NhlNhNhmNhnNhoK hp]�h�///< The member is a Class.
�����}�(hKhh)��}�(hhhM}hK*hKubh�ubahx�///< The member is a Class.
�hz}�h|�h}�2�ubh])��}�(hh�FUNCTION�����}�(hKhh)��}�(hhhM�hK+hKubh�ubhhSh]�hgh�hhhihjhkh/NhlNhNhmNhnNhoK hp]�h�S///< The member is a Function (either at package scope, or a static class member).
�����}�(hKhh)��}�(hhhM�hK+hKubh�ubahx�S///< The member is a Function (either at package scope, or a static class member).
�hz}�h|�h}�4�ubh])��}�(hh�INSTANCE_FUNCTION�����}�(hKhh)��}�(hhhMhK,hKubh�ubhhSh]�hgh�hhhihjhkh/NhlNhNhmNhnNhoK hp]�h�R///< The member is a non-const instance function (i.e., non-static class member).
�����}�(hKhh)��}�(hhhM hK,hKubh�ubahx�R///< The member is a non-const instance function (i.e., non-static class member).
�hz}�h|�h}�8�ubh])��}�(hh�CONST_INSTANCE_FUNCTION�����}�(hKhh)��}�(hhhMthK-hKubh�ubhhSh]�hgh�hhhihjhkh/NhlNhNhmNhnNhoK hp]�h�N///< The member is a const instance function (i.e., non-static class member).
�����}�(hKhh)��}�(hhhM�hK-hK!ubh�ubahx�N///< The member is a const instance function (i.e., non-static class member).
�hz}�h|�h}�16�ubh])��}�(hh�CONTAINER_TEST�����}�(hKhh)��}�(hhhM�hK.hKubh�ubhhSh]�hgh�hhhihjhkh/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�h}�PACKAGE|CLASS�ubh])��}�(hh�FUNCTION_TEST�����}�(hKhh)��}�(hhhMhK/hKubh�ubhhSh]�hgh�hhhihjhkh/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�h}�2FUNCTION|INSTANCE_FUNCTION|CONST_INSTANCE_FUNCTION�ubehghWhhh�public�����}�(hKhh)��}�(hhhM�hK"hKubh�ubhj�enum�h/NhlNhNhmNhnNhoK hp]�(h�V/// This enum defines the possible kinds of a Member. Exactly one of the flags is set
�����}�(hKhh)��}�(hhhMChK$hKubh�ubh�(/// in the value returned by GetKind().
�����}�(hKhh)��}�(hhhM�hK%hKubh�ubehx�~/// This enum defines the possible kinds of a Member. Exactly one of the flags is set
/// in the value returned by GetKind().
�hz}�h|��bases�]��scoped���
registered���flags��h X1  enum class KIND
	{
		PACKAGE = 1,									///< The member is a Package.
		CLASS = 2,										///< The member is a Class.
		FUNCTION = 4,									///< The member is a Function (either at package scope, or a static class member).
		INSTANCE_FUNCTION = 8,				///< The member is a non-const instance function (i.e., non-static class member).
		CONST_INSTANCE_FUNCTION = 16,	///< The member is a const instance function (i.e., non-static class member).
		CONTAINER_TEST = PACKAGE | CLASS,
		FUNCTION_TEST = FUNCTION | INSTANCE_FUNCTION | CONST_INSTANCE_FUNCTION
	} �hK0�early��ubh �Function���)��}�(hh�GetEnclosingContainer�����}�(hKhh)��}�(hhhM�	hK8hK ubh�ubhhHh]�hgj  hhh�hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhMy	hK8hKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�Z/// Returns the enclosing container of this member. All members except the global package
�����}�(hKhh)��}�(hhhM�hK3hKubh�ubh�_/// have such an enclosing container: Functions and classes are nested in classes or packages,
�����}�(hKhh)��}�(hhhM'hK4hKubh�ubh�+/// packages are nested in other packages.
�����}�(hKhh)��}�(hhhM�hK5hKubh�ubh�i/// @return												The enclosing container of this member, or nullptr if this is the global package.
�����}�(hKhh)��}�(hhhM�hK6hKubh�ubehxXM  /// Returns the enclosing container of this member. All members except the global package
/// have such an enclosing container: Functions and classes are nested in classes or packages,
/// packages are nested in other packages.
/// @return												The enclosing container of this member, or nullptr if this is the global package.
�hz}�h|��static���explicit���deleted���retType��const Container*��const���params�]��
observable�N�result�N�forward��ubj  )��}�(hh�GetKind�����}�(hKhh)��}�(hhhMphK?hKubh�ubhhHh]�hgj;  hhh�hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM^hK?hKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�`/// Returns the kind of this member. This allows to tell whether this Member can be safely cast
�����}�(hKhh)��}�(hhhM
hK;hKubh�ubh�_/// to a Package, Class or Function. The returned value has exactly one of the KIND flags set.
�����}�(hKhh)��}�(hhhMu
hK<hKubh�ubh�,/// @return												Kind of this member.
�����}�(hKhh)��}�(hhhM�
hK=hKubh�ubehx��/// Returns the kind of this member. This allows to tell whether this Member can be safely cast
/// to a Package, Class or Function. The returned value has exactly one of the KIND flags set.
/// @return												Kind of this member.
�hz}�h|�j,  �j-  �j.  �j/  �KIND�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�GetSimpleName�����}�(hKhh)��}�(hhhM�hKFhKubh�ubhhHh]�hgja  hhh�hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKFhKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�g/// Returns the (unqualified) name of this member. E.g., for maxon::StringInterface::GetLength this is
�����}�(hKhh)��}�(hhhM�hKBhKubh�ubh�/// "GetLength".
�����}�(hKhh)��}�(hhhMGhKChKubh�ubh�,/// @return												Name of this member.
�����}�(hKhh)��}�(hhhMYhKDhKubh�ubehx��/// Returns the (unqualified) name of this member. E.g., for maxon::StringInterface::GetLength this is
/// "GetLength".
/// @return												Name of this member.
�hz}�h|�j,  �j-  �j.  �j/  �	const Id&�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�GetId�����}�(hKhh)��}�(hhhM�hKQhKubh�ubhhHh]�hgj�  hhh�hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKQhKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�\/// Returns a unique id for this member. This is the qualified name of the member (with dot
�����}�(hKhh)��}�(hhhMnhKIhKubh�ubh�\/// as separator), plus optionally an additional code for disambiguation, separated by "@".
�����}�(hKhh)��}�(hhhM�hKJhKubh�ubh�V///	For functions, a hashcode which depends on the parameter and return types is used
�����}�(hKhh)��}�(hhhM(hKKhKubh�ubh�K///	to disambiguate between overloads (such as "net.maxon.asin@919429e0").
�����}�(hKhh)��}�(hhhMhKLhKubh�ubh�///
�����}�(hKhh)��}�(hhhM�hKMhKubh�ubh�</// The function Find() allows to find a Member for the id.
�����}�(hKhh)��}�(hhhM�hKNhKubh�ubh�2/// @return												Unique id for this member.
�����}�(hKhh)��}�(hhhMhKOhKubh�ubehxX�  /// Returns a unique id for this member. This is the qualified name of the member (with dot
/// as separator), plus optionally an additional code for disambiguation, separated by "@".
///	For functions, a hashcode which depends on the parameter and return types is used
///	to disambiguate between overloads (such as "net.maxon.asin@919429e0").
///
/// The function Find() allows to find a Member for the id.
/// @return												Unique id for this member.
�hz}�h|�j,  �j-  �j.  �j/  �	const Id&�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�ToString�����}�(hKhh)��}�(hhhMuhKXhKubh�ubhhHh]�hgj�  hhh�hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhMahKXhKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�./// Returns a readable string of the content.
�����}�(hKhh)��}�(hhhM hKThKubh�ubh��/// @param[in] fs									Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
�����}�(hKhh)��}�(hhhMOhKUhKubh�ubh�-/// @return												The converted result.
�����}�(hKhh)��}�(hhhM�hKVhKubh�ubehx��/// Returns a readable string of the content.
/// @param[in] fs									Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
/// @return												The converted result.
�hz}�h|�j,  �j-  �j.  �j/  �String�j1  �j2  ]�h �	Parameter���)��}�(h�const FormatStatement*�hh�fs�����}�(hKhh)��}�(hhhM�hKXhK6ubh�ub�default��nullptr��pack���input���output��ubaj4  Nj5  Nj6  �ubj  )��}�(hh�
GetMembers�����}�(hKhh)��}�(hhhM�hK]hK#ubh�ubhhHh]�hgj�  hhh�hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK]hK	ubh�ubh/NhlNhNhmNhnNhoK hp]�h�"/// Yields all registered members
�����}�(hKhh)��}�(hhhMhK[hKubh�ubahx�"/// Yields all registered members
�hz}�h|�j,  �j-  �j.  �j/  �Result<Bool>�j1  �j2  ]�j�  )��}�(h�#const ValueReceiver<const Member&>&�hh�members�����}�(hKhh)��}�(hhhM�hK]hKRubh�ubj�  Nj�  �j�  �j�  �ubaj4  Nj5  �Bool�j6  �ubj  )��}�(hh�Find�����}�(hKhh)��}�(hhhM�hKehK$ubh�ubhhHh]�hgj  hhh�hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKehK	ubh�ubh/NhlNhNhmNhnNhoK hp]�(h�X/// Finds the member whose id is @p memberId. The id has to be in a format as specified
�����}�(hKhh)��}�(hhhM?hK`hKubh�ubh�W/// by GetId(). If there is no member with the given @p memberId, nullptr is returned.
�����}�(hKhh)��}�(hhhM�hKahKubh�ubh�*/// @param[in] memberId						A member id.
�����}�(hKhh)��}�(hhhM�hKbhKubh�ubh�J/// @return												The member with the given @p memberId, or nullptr.
�����}�(hKhh)��}�(hhhMhKchKubh�ubehxX#  /// Finds the member whose id is @p memberId. The id has to be in a format as specified
/// by GetId(). If there is no member with the given @p memberId, nullptr is returned.
/// @param[in] memberId						A member id.
/// @return												The member with the given @p memberId, or nullptr.
�hz}�h|�j,  �j-  �j.  �j/  �const Member*�j1  �j2  ]�j�  )��}�(h�	const Id&�hh�memberId�����}�(hKhh)��}�(hhhM�hKehK3ubh�ubj�  Nj�  �j�  �j�  �ubaj4  Nj5  Nj6  �ubehghLhhhihj�class�h/NhlNhNhmh�'"net.maxon.reflection.interface.member"�����}�(hKhh)��}�(hhhM�hK!hK;ubh�ubhnNhoK hp]�(h�N/// Member is the root interface of the reflection hierarchy. A Member may be
�����}�(hKhh)��}�(hhhM+hKhKubh�ubh�#/// - a Container, which is either
�����}�(hKhh)��}�(hhhMyhKhKubh�ubh�///   - a Package
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�///   - or a Class
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�/// - or a Function
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�///
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�W/// All members except the global package have an enclosing container as their parent.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�d/// For example, the method StringInterface::GetLength() has the class StringInterface as enclosing
�����}�(hKhh)��}�(hhhM0hKhKubh�ubh�`/// container, which has the maxon package as enclosing container, which has the global package
�����}�(hKhh)��}�(hhhM�hKhKubh�ubh�/// as enclosing container.
�����}�(hKhh)��}�(hhhM�hKhKubh�ubehxX�  /// Member is the root interface of the reflection hierarchy. A Member may be
/// - a Container, which is either
///   - a Package
///   - or a Class
/// - or a Function
///
/// All members except the global package have an enclosing container as their parent.
/// For example, the method StringInterface::GetLength() has the class StringInterface as enclosing
/// container, which has the maxon package as enclosing container, which has the global package
/// as enclosing container.
�hz}�h|�h�]��	interface�K�refKind�Nj,  ��refClass�N�baseInterfaces�N�derived���isError���implementation���	component���finalComponent��j6  ��
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���usings�]��constUsings�]��ambiguousCalls�]��	selfCalls�]��methodNames�}�ubhG)��}�(hh�	Container�����}�(hKhh)��}�(hhhMwhKmhKubh�ubhh=h]�(j  )��}�(hh�
GetClasses�����}�(hKhh)��}�(hhhMhKwhK)ubh�ubhj�  h]�hgj�  hhh�public�����}�(hKhh)��}�(hhhMhKphKubh�ubhjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKwhKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�V/// Returns a list of all classes which are members of this container. For a Package,
�����}�(hKhh)��}�(hhhMjhKrhKubh�ubh�W/// these are its top-level classes. For a Class, these are the direct member classes,
�����}�(hKhh)��}�(hhhM�hKshKubh�ubh�(/// excluding inherited member classes.
�����}�(hKhh)��}�(hhhMhKthKubh�ubh�O/// @return												All classes which are direct members of this container.
�����}�(hKhh)��}�(hhhMBhKuhKubh�ubehxX$  /// Returns a list of all classes which are members of this container. For a Package,
/// these are its top-level classes. For a Class, these are the direct member classes,
/// excluding inherited member classes.
/// @return												All classes which are direct members of this container.
�hz}�h|�j,  �j-  �j.  �j/  �Block<const Class* const>�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�	FindClass�����}�(hKhh)��}�(hhhMAhKhKubh�ubhj�  h]�hgj�  hhj�  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM'hKhKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�h/// Finds the class which is a direct member of this container and has the given (unqualified) @p name.
�����}�(hKhh)��}�(hhhM�hKzhKubh�ubh�B/// This does not search for inherited member classes of a class.
�����}�(hKhh)��}�(hhhM�hK{hKubh�ubh�6/// @param[in] name								Name of the class to find.
�����}�(hKhh)��}�(hhhM3hK|hKubh�ubh�`/// @return												The found class, or nullptr if there is no class with the given @p name.
�����}�(hKhh)��}�(hhhMjhK}hKubh�ubehxX@  /// Finds the class which is a direct member of this container and has the given (unqualified) @p name.
/// This does not search for inherited member classes of a class.
/// @param[in] name								Name of the class to find.
/// @return												The found class, or nullptr if there is no class with the given @p name.
�hz}�h|�j,  �j-  �j.  �j/  �const Class*�j1  �j2  ]�j�  )��}�(h�	const Id&�hh�name�����}�(hKhh)��}�(hhhMUhKhK0ubh�ubj�  Nj�  �j�  �j�  �ubaj4  Nj5  Nj6  �ubj  )��}�(hh�GetFunctions�����}�(hKhh)��}�(hhhMqhK�hK,ubh�ubhj�  h]�hgj#  hhj�  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhMGhK�hKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�X/// Returns a list of all functions which are members of this container. For a Package,
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�T/// these are its top-level functions. For a Class, these are its member functions,
�����}�(hKhh)��}�(hhhMhK�hKubh�ubh�*/// excluding inherited member functions.
�����}�(hKhh)��}�(hhhMnhK�hKubh�ubh�Q/// @return												All functions which are direct members of this container.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubehxX'  /// Returns a list of all functions which are members of this container. For a Package,
/// these are its top-level functions. For a Class, these are its member functions,
/// excluding inherited member functions.
/// @return												All functions which are direct members of this container.
�hz}�h|�j,  �j-  �j.  �j/  �Block<const Function* const>�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�FindFunction�����}�(hKhh)��}�(hhhM hK�hK'ubh�ubhj�  h]�hgjO  hhj�  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�k/// Finds the function which is a direct member of this container and has the given (unqualified) @p name.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�X/// If no such function exists, or if the function is overloaded, an error is returned.
�����}�(hKhh)��}�(hhhMQhK�hKubh�ubh�D/// This does not search for inherited member functions of classes.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�9/// @param[in] name								Name of the function to find.
�����}�(hKhh)��}�(hhhM�hK�hKubh�ubh�n/// @return												The found function, or an error if no function is found or the function is overloaded.
�����}�(hKhh)��}�(hhhM)hK�hKubh�ubehxX�  /// Finds the function which is a direct member of this container and has the given (unqualified) @p name.
/// If no such function exists, or if the function is overloaded, an error is returned.
/// This does not search for inherited member functions of classes.
/// @param[in] name								Name of the function to find.
/// @return												The found function, or an error if no function is found or the function is overloaded.
�hz}�h|�j,  �j-  �j.  �j/  �Result<const Function*>�j1  �j2  ]�j�  )��}�(h�	const Id&�hh�name�����}�(hKhh)��}�(hhhM0 hK�hK>ubh�ubj�  Nj�  �j�  �j�  �ubaj4  Nj5  �const Function*�j6  �ubj  )��}�(hh�FindFunctions�����}�(hKhh)��}�(hhhM{"hK�hKubh�ubhj�  h]�hgj�  hhj�  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhMa"hK�hKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�m/// Finds all functions which are direct members of this container and have the given (unqualified) @p name.
�����}�(hKhh)��}�(hhhM� hK�hKubh�ubh�D/// This does not search for inherited member functions of classes.
�����}�(hKhh)��}�(hhhM	!hK�hKubh�ubh�9/// @param[in] name								Name of the function to find.
�����}�(hKhh)��}�(hhhMN!hK�hKubh�ubh�>/// @param[out] result						Receiver for the found functions.
�����}�(hKhh)��}�(hhhM�!hK�hKubh�ubh�=/// @return												OK unless a memory allocation failed.
�����}�(hKhh)��}�(hhhM�!hK�hKubh�ubehxXe  /// Finds all functions which are direct members of this container and have the given (unqualified) @p name.
/// This does not search for inherited member functions of classes.
/// @param[in] name								Name of the function to find.
/// @param[out] result						Receiver for the found functions.
/// @return												OK unless a memory allocation failed.
�hz}�h|�j,  �j-  �j.  �j/  �Result<void>�j1  �j2  ]�(j�  )��}�(h�	const Id&�hh�name�����}�(hKhh)��}�(hhhM�"hK�hK4ubh�ubj�  Nj�  �j�  �j�  �ubj�  )��}�(h�%const ValueReceiver<const Function*>&�hh�result�����}�(hKhh)��}�(hhhM�"hK�hK`ubh�ubj�  Nj�  �j�  �j�  �ubej4  Nj5  �void�j6  �ubj  )��}�(hh�Find�����}�(hKhh)��}�(hhhM�"hK�hKubh�ubhj�  h]�hgj�  hhj�  hj�function�h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �const Container*�j1  �j2  ]�j�  )��}�(h�	const Id&�hh�memberId�����}�(hKhh)��}�(hhhM�"hK�hK)ubh�ubj�  Nj�  �j�  �j�  �ubaj4  Nj5  Nj6  �ubehgj�  hhhihjjP  h/NhlNhNhmh�*"net.maxon.reflection.interface.container"�����}�(hKhh)��}�(hhhM�hKohKFubh�ubhnNhoK hp]�(h�Y/// Container is the base interface of members which may contain other members, i.e., of
�����}�(hKhh)��}�(hhhM^hKjhKubh�ubh�_/// packages and classes. Correspondingly, there are two derived interfaces Package and Class.
�����}�(hKhh)��}�(hhhM�hKkhKubh�ubehx��/// Container is the base interface of members which may contain other members, i.e., of
/// packages and classes. Correspondingly, there are two derived interfaces Package and Class.
�hz}�h|�h�]��Member�h�public�����}�(hKhh)��}�(hhhM�hKmhKubh�ubh	��aj�  Kj�  Nj,  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j6  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  ]�j�  }�ubhG)��}�(hh�Package�����}�(hKhh)��}�(hhhM�$hK�hKubh�ubhh=h]�(j  )��}�(hh�GetPackages�����}�(hKhh)��}�(hhhM'hK�hK+ubh�ubhj  h]�hgj  hhh�public�����}�(hKhh)��}�(hhhMw%hK�hKubh�ubhjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�&hK�hKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�U/// Returns a list of all packages which are directly contained within this package.
�����}�(hKhh)��}�(hhhM�%hK�hKubh�ubh�V/// @return												All packages which are directly contained within this package.
�����}�(hKhh)��}�(hhhM2&hK�hKubh�ubehx��/// Returns a list of all packages which are directly contained within this package.
/// @return												All packages which are directly contained within this package.
�hz}�h|�j,  �j-  �j.  �j/  �Block<const Package* const>�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�FindPackage�����}�(hKhh)��}�(hhhM)hK�hKubh�ubhj  h]�hgj9  hhj  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�(hK�hKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�o/// Finds the package which is directly contained within this package and has the given (unqualified) @p name.
�����}�(hKhh)��}�(hhhM�'hK�hKubh�ubh�8/// @param[in] name								Name of the package to find.
�����}�(hKhh)��}�(hhhM�'hK�hKubh�ubh�d/// @return												The found package, or nullptr if there is no package with the given @p name.
�����}�(hKhh)��}�(hhhM*(hK�hKubh�ubehxX  /// Finds the package which is directly contained within this package and has the given (unqualified) @p name.
/// @param[in] name								Name of the package to find.
/// @return												The found package, or nullptr if there is no package with the given @p name.
�hz}�h|�j,  �j-  �j.  �j/  �const Package*�j1  �j2  ]�j�  )��}�(h�	const Id&�hh�name�����}�(hKhh)��}�(hhhM)hK�hK4ubh�ubj�  Nj�  �j�  �j�  �ubaj4  Nj5  Nj6  �ubj  )��}�(hh�GetGlobalPackage�����}�(hKhh)��}�(hhhM�*hK�hK%ubh�ubhj  h]�hgjh  hhj  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�*hK�hK	ubh�ubh/NhlNhNhmNhnNhoK hp]�(h�r/// Returns the global package. All other members are directly or indirectly contained within the global package.
�����}�(hKhh)��}�(hhhM�)hK�hKubh�ubh�=/// @return												Representation of the global package.
�����}�(hKhh)��}�(hhhM�)hK�hKubh�ubehx��/// Returns the global package. All other members are directly or indirectly contained within the global package.
/// @return												Representation of the global package.
�hz}�h|�j,  �j-  �j.  �j/  �const Package*�j1  �j2  ]�j4  Nj5  Nj6  �ubehgj
  hhhihjjP  h/NhlNhNhmh�("net.maxon.reflection.interface.package"�����}�(hKhh)��}�(hhhML%hK�hKDubh�ubhnNhoK hp]�(h�^/// Package represents a package, that is a container of other packages, functions or classes
�����}�(hKhh)��}�(hhhM�#hK�hKubh�ubh�6/// which share the same prefix in their identifiers.
�����}�(hKhh)��}�(hhhMU$hK�hKubh�ubehx��/// Package represents a package, that is a container of other packages, functions or classes
/// which share the same prefix in their identifiers.
�hz}�h|�h�]��	Container�h�public�����}�(hKhh)��}�(hhhM�$hK�hKubh�ubh	��aj�  Kj�  Nj,  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j6  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  ]�j�  }�ubhG)��}�(hh�Class�����}�(hKhh)��}�(hhhMr,hK�hKubh�ubhh=h]�(j  )��}�(hh�GetInterface�����}�(hKhh)��}�(hhhM]/hK�hK)ubh�ubhj�  h]�hgj�  hhh�public�����}�(hKhh)��}�(hhhM�,hK�hKubh�ubhjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM6/hK�hKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�S/// Returns a corresponding InterfaceReference if this Class is virtual interface,
�����}�(hKhh)��}�(hhhM\-hK�hKubh�ubh�Z/// otherwise nullptr. If the interface has static methods, also GetNonvirtualInterface()
�����}�(hKhh)��}�(hhhM�-hK�hKubh�ubh�e/// returns a valid pointer which points to the NonvirtualInterfaceReference for the static methods.
�����}�(hKhh)��}�(hhhM.hK�hKubh�ubh�h/// @return												A InterfaceReference for this Class, or nullptr if this is no virtual interface.
�����}�(hKhh)��}�(hhhMq.hK�hKubh�ubehxXz  /// Returns a corresponding InterfaceReference if this Class is virtual interface,
/// otherwise nullptr. If the interface has static methods, also GetNonvirtualInterface()
/// returns a valid pointer which points to the NonvirtualInterfaceReference for the static methods.
/// @return												A InterfaceReference for this Class, or nullptr if this is no virtual interface.
�hz}�h|�j,  �j-  �j.  �j/  �const InterfaceReference*�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�GetNonvirtualInterface�����}�(hKhh)��}�(hhhM�1hK�hK3ubh�ubhj�  h]�hgj�  hhj�  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhMr1hK�hKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�c/// Returns a corresponding NonvirtualInterfaceReference if this Class is a non-virtual interface,
�����}�(hKhh)��}�(hhhM�/hK�hKubh�ubh�A/// or if this Class is a virtual interface with static methods.
�����}�(hKhh)��}�(hhhM50hK�hKubh�ubh�/// otherwise nullptr.
�����}�(hKhh)��}�(hhhMw0hK�hKubh�ubh��/// @return												An NonvirtualInterfaceReference for this Class, or nullptr if there is no corresponding non-virtual interface.
�����}�(hKhh)��}�(hhhM�0hK�hKubh�ubehxXA  /// Returns a corresponding NonvirtualInterfaceReference if this Class is a non-virtual interface,
/// or if this Class is a virtual interface with static methods.
/// otherwise nullptr.
/// @return												An NonvirtualInterfaceReference for this Class, or nullptr if there is no corresponding non-virtual interface.
�hz}�h|�j,  �j-  �j.  �j/  �#const NonvirtualInterfaceReference*�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�GetBaseClasses�����}�(hKhh)��}�(hhhM�2hK�hK)ubh�ubhj�  h]�hgj  hhj�  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�2hK�hKubh�ubh/NhlNhNhmNhnNhoK hp]�h�#/// TODO: (Ole) Not yet supported.
�����}�(hKhh)��}�(hhhM!2hK�hKubh�ubahx�#/// TODO: (Ole) Not yet supported.
�hz}�h|�j,  �j-  �j.  �j/  �Block<const Class* const>�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�GetStaticInterface�����}�(hKhh)��}�(hhhM�4hK�hKubh�ubhj�  h]�hgj,  hhj�  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�4hK�hKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�W/// Return a Class containing the static methods of this virtual interface, or nullptr
�����}�(hKhh)��}�(hhhM>3hK�hKubh�ubh�F/// is this Class isn't a virtual interface or has no static methods.
�����}�(hKhh)��}�(hhhM�3hK�hKubh�ubh�_/// @return												The Class for the static methods of this virtual interface, or nullptr.
�����}�(hKhh)��}�(hhhM�3hK�hKubh�ubehx��/// Return a Class containing the static methods of this virtual interface, or nullptr
/// is this Class isn't a virtual interface or has no static methods.
/// @return												The Class for the static methods of this virtual interface, or nullptr.
�hz}�h|�j,  �j-  �j.  �j/  �const Class*�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�Find�����}�(hKhh)��}�(hhhM�6hK�hKubh�ubhj�  h]�hgjR  hhj�  hjj�  h/NhlNhNhmNhnNhoK hp]�(h�\/// Finds the class whose id is @p memberId. The id is the qualified name of the class with
�����}�(hKhh)��}�(hhhM-5hK�hKubh�ubh�+/// dot as separator, see Member::GetId().
�����}�(hKhh)��}�(hhhM�5hK�hKubh�ubh�J/// If there is no class with the given @p memberId, nullptr is returned.
�����}�(hKhh)��}�(hhhM�5hK�hKubh�ubh�6/// @param[in] memberId						A member id for a class.
�����}�(hKhh)��}�(hhhM6hK�hKubh�ubh�I/// @return												The class with the given @p memberId, or nullptr.
�����}�(hKhh)��}�(hhhM86hK�hKubh�ubehxXP  /// Finds the class whose id is @p memberId. The id is the qualified name of the class with
/// dot as separator, see Member::GetId().
/// If there is no class with the given @p memberId, nullptr is returned.
/// @param[in] memberId						A member id for a class.
/// @return												The class with the given @p memberId, or nullptr.
�hz}�h|�j,  �j-  �j.  �j/  �const Class*�j1  �j2  ]�j�  )��}�(h�	const Id&�hh�memberId�����}�(hKhh)��}�(hhhM7hK�hK%ubh�ubj�  Nj�  �j�  �j�  �ubaj4  Nj5  Nj6  �ubj  )��}�(hh�FindInterface�����}�(hKhh)��}�(hhhM�9hK�hK4ubh�ubhj�  h]�hgj�  hhj�  hjj�  h/h �Template���)��}�j2  ]�h �TypeTemplateParam���)��}�(hh)��}�(hhhMp9hK�hKubj�  �hh�	INTERFACE�����}�(hKhh)��}�(hhhMy9hK�hKubh�ubj�  N�variance�NubasbhlNhNhmNhnNhoK hp]�(h�I/// Finds the Class object for a given non-virtual or virtual interface.
�����}�(hKhh)��}�(hhhM�7hK�hKubh�ubh�K/// @tparam INTERFACE							The interface class (such as StringInterface).
�����}�(hKhh)��}�(hhhM=8hK�hKubh�ubh��/// @return												The Class object for the given interface, or nullptr if no reflection was registered for that interface.
�����}�(hKhh)��}�(hhhM�8hK�hKubh�ubehxX  /// Finds the Class object for a given non-virtual or virtual interface.
/// @tparam INTERFACE							The interface class (such as StringInterface).
/// @return												The Class object for the given interface, or nullptr if no reflection was registered for that interface.
�hz}�h|�j,  �j-  �j.  �j/  �const Class*�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�FindInterface�����}�(hKhh)��}�(hhhM�;hMhKubh�ubhj�  h]�hgj�  hhj�  hjj�  h/NhlNhNhmNhnNhoK hp]�(h�H/// Finds the Class object for a given non-virtual interface reference.
�����}�(hKhh)��}�(hhhM::hK�hKubh�ubh�(/// @param[in] i									The interface.
�����}�(hKhh)��}�(hhhM�:hK�hKubh�ubh��/// @return												The Class object for the given interface, or nullptr if no reflection was registered for that interface or #i was nullptr.
�����}�(hKhh)��}�(hhhM�:hK�hKubh�ubehxX  /// Finds the Class object for a given non-virtual interface reference.
/// @param[in] i									The interface.
/// @return												The Class object for the given interface, or nullptr if no reflection was registered for that interface or #i was nullptr.
�hz}�h|�j,  �j-  �j.  �j/  �const Class*�j1  �j2  ]�j�  )��}�(h�#const NonvirtualInterfaceReference*�hh�i�����}�(hKhh)��}�(hhhM�;hMhKHubh�ubj�  Nj�  �j�  �j�  �ubaj4  Nj5  Nj6  �ubj  )��}�(hh�FindInterface�����}�(hKhh)��}�(hhhM�=hMhKubh�ubhj�  h]�hgj�  hhj�  hjj�  h/NhlNhNhmNhnNhoK hp]�(h�D/// Finds the Class object for a given virtual interface reference.
�����}�(hKhh)��}�(hhhMq<hMhKubh�ubh�(/// @param[in] i									The interface.
�����}�(hKhh)��}�(hhhM�<hMhKubh�ubh��/// @return												The Class object for the given interface, or nullptr if no reflection was registered for that interface or #i was nullptr.
�����}�(hKhh)��}�(hhhM�<hM	hKubh�ubehx��/// Finds the Class object for a given virtual interface reference.
/// @param[in] i									The interface.
/// @return												The Class object for the given interface, or nullptr if no reflection was registered for that interface or #i was nullptr.
�hz}�h|�j,  �j-  �j.  �j/  �const Class*�j1  �j2  ]�j�  )��}�(h�const InterfaceReference*�hh�i�����}�(hKhh)��}�(hhhM
>hMhK>ubh�ubj�  Nj�  �j�  �j�  �ubaj4  Nj5  Nj6  �ubehgj�  hhhihjjP  h/NhlNhNhmh�&"net.maxon.reflection.interface.class"�����}�(hKhh)��}�(hhhM�,hK�hKBubh�ubhnNhoK hp]�(h�V/// Class represents a C++ class. It may contain member functions and member classes.
�����}�(hKhh)��}�(hhhM,+hK�hKubh�ubh�Y/// Also if the class is an interface (in the sense of the MAXON API), the corresponding
�����}�(hKhh)��}�(hhhM�+hK�hKubh�ubh�6/// interface information can be obtained from Class.
�����}�(hKhh)��}�(hhhM�+hK�hKubh�ubehx��/// Class represents a C++ class. It may contain member functions and member classes.
/// Also if the class is an interface (in the sense of the MAXON API), the corresponding
/// interface information can be obtained from Class.
�hz}�h|�h�]��	Container�h�public�����}�(hKhh)��}�(hhhMz,hK�hKubh�ubh	��aj�  Kj�  Nj,  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j6  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  ]�j�  }�ubhG)��}�(hh�InvokeHelper�����}�(hKhh)��}�(hhhM_>hMhKubh�ubhh=h]�hgj4  hhhihjjP  h/j�  )��}�j2  ]�j�  )��}�(hh)��}�(hhhML>hMhKubj�  �hh�T�����}�(hKhh)��}�(hhhMU>hMhKubh�ubj�  Nj�  NubasbhlNhNhmNhnNhoK hp]�hxh	hz}�h|�h�]�j�  Nj�  Nj,  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j6  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  ]�j�  }�ubhG)��}�(hh�Function�����}�(hKhh)��}�(hhhMBhM"hKubh�ubhh=h]�(j  )��}�(hh�Invoke�����}�(hKhh)��}�(hhhMDGhM3hKubh�ubhjN  h]�hgj[  hhh�public�����}�(hKhh)��}�(hhhM�BhM&hKubh�ubhjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM*GhM3hKubh�ubh/NhlNhNhmNhnNhoK hp]�(h�U/// Invokes this function with the given arguments. If this is an instance function,
�����}�(hKhh)��}�(hhhM�BhM(hKubh�ubh�_/// the @c this pointer has to be given as first argument. @p result has to point to an object
�����}�(hKhh)��}�(hhhMUChM)hKubh�ubh�X/// of the return type of the function, the result will then be written to that object.
�����}�(hKhh)��}�(hhhM�ChM*hKubh�ubh�J/// For a function with @c void return type, @p result may be @c nullptr.
�����}�(hKhh)��}�(hhhMDhM+hKubh�ubh�///
�����}�(hKhh)��}�(hhhMYDhM,hKubh�ubh��/// @param[out] result						Pointer to a value to which the function result is written. May be @c nullptr if the functions returns @c void.
�����}�(hKhh)��}�(hhhM^DhM-hKubh�ubh�x/// 															The type of the value must be the return type of the function, otherwise the behaviour is undefined.
�����}�(hKhh)��}�(hhhM�DhM.hKubh�ubh�~/// @param[in] arguments					Arguments for the function. For an instance function, the first argument is the @c this pointer.
�����}�(hKhh)��}�(hhhMdEhM/hKubh�ubh�^/// 															The arguments have to match in type, otherwise the behaviour is undefined.
�����}�(hKhh)��}�(hhhM�EhM0hKubh�ubh��/// @return												An error if the argument count doesn't match or (for a non-@c void function) @p result is @c nullptr, otherwise OK.
�����}�(hKhh)��}�(hhhMBFhM1hKubh�ubehxX�  /// Invokes this function with the given arguments. If this is an instance function,
/// the @c this pointer has to be given as first argument. @p result has to point to an object
/// of the return type of the function, the result will then be written to that object.
/// For a function with @c void return type, @p result may be @c nullptr.
///
/// @param[out] result						Pointer to a value to which the function result is written. May be @c nullptr if the functions returns @c void.
/// 															The type of the value must be the return type of the function, otherwise the behaviour is undefined.
/// @param[in] arguments					Arguments for the function. For an instance function, the first argument is the @c this pointer.
/// 															The arguments have to match in type, otherwise the behaviour is undefined.
/// @return												An error if the argument count doesn't match or (for a non-@c void function) @p result is @c nullptr, otherwise OK.
�hz}�h|�j,  �j-  �j.  �j/  �Result<void>�j1  �j2  ]�(j�  )��}�(h�void*�hh�result�����}�(hKhh)��}�(hhhMQGhM3hK)ubh�ubj�  Nj�  �j�  �j�  �ubj�  )��}�(h�const Block<Argument>&�hh�	arguments�����}�(hKhh)��}�(hhhMpGhM3hKHubh�ubj�  Nj�  �j�  �j�  �ubej4  Nj5  �void�j6  �ubj  )��}�(hh�Invoke�����}�(hKhh)��}�(hhhM�KhMBhKQubh�ubhjN  h]�hgj�  hhjb  hjj�  h/j�  )��}�j2  ]�(j�  )��}�(hh)��}�(hhhM�KhMBhKubj�  �hh�T�����}�(hKhh)��}�(hhhM�KhMBhKubh�ubj�  Nj�  Nubj�  )��}�(hh)��}�(hhhM�KhMBhKubj�  �hh�ARGS�����}�(hKhh)��}�(hhhM�KhMBhK$ubh�ubj�  Nj�  NubesbhlNhNhmNhnNhoK hp]�(h�U/// Invokes this function with the given arguments. If this is an instance function,
�����}�(hKhh)��}�(hhhM�GhM6hKubh�ubh�V/// the @c this pointer has to be given as first argument. @p T has to be of the form
�����}�(hKhh)��}�(hhhM6HhM7hKubh�ubh�O/// <tt>R(A1, ..., An)</tt>, where @c R is the return type of the function and
�����}�(hKhh)��}�(hhhM�HhM8hKubh�ubh�[/// @c A1, ..., @c An are the parameter types. For instance functions, @c A1 has to be the
�����}�(hKhh)��}�(hhhM�HhM9hKubh�ubh�^/// type of the additional @c this argument. If the types don't match the actual types of the
�����}�(hKhh)��}�(hhhM9IhM:hKubh�ubh�*/// function, the behaviour is undefined.
�����}�(hKhh)��}�(hhhM�IhM;hKubh�ubh�///
�����}�(hKhh)��}�(hhhM�IhM<hKubh�ubh�R/// @tparam T											Type of the function of the form <tt>R(A1, ..., An)</tt>.
�����}�(hKhh)��}�(hhhM�IhM=hKubh�ubh�V/// 															If this doesn't match the actual type, the behaviour is undefined.
�����}�(hKhh)��}�(hhhMJhM>hKubh�ubh�|/// @param[in] args								Arguments for the function. For an instance function, the first argument is the @c this pointer.
�����}�(hKhh)��}�(hhhMrJhM?hKubh�ubh�S/// @return												An error if the argument count doesn't match, otherwise OK.
�����}�(hKhh)��}�(hhhM�JhM@hKubh�ubehxXX  /// Invokes this function with the given arguments. If this is an instance function,
/// the @c this pointer has to be given as first argument. @p T has to be of the form
/// <tt>R(A1, ..., An)</tt>, where @c R is the return type of the function and
/// @c A1, ..., @c An are the parameter types. For instance functions, @c A1 has to be the
/// type of the additional @c this argument. If the types don't match the actual types of the
/// function, the behaviour is undefined.
///
/// @tparam T											Type of the function of the form <tt>R(A1, ..., An)</tt>.
/// 															If this doesn't match the actual type, the behaviour is undefined.
/// @param[in] args								Arguments for the function. For an instance function, the first argument is the @c this pointer.
/// @return												An error if the argument count doesn't match, otherwise OK.
�hz}�h|�j,  �j-  �j.  �j/  �&Result<typename InvokeHelper<T>::type>�j1  �j2  ]�j�  )��}�(h�ARGS&&�hh�args�����}�(hKhh)��}�(hhhM�KhMBhKbubh�ubj�  Nj�  �j�  �j�  �ubaj4  Nj5  �typename InvokeHelper<T>::type�j6  �ubj  )��}�(hh�GetReturnType�����}�(hKhh)��}�(hhhMsLhMGhKubh�ubhjN  h]�hgj5  hhjb  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhMXLhMGhKubh�ubh/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �ParameterType�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�GetParameterTypes�����}�(hKhh)��}�(hhhM�LhMIhK*ubh�ubhjN  h]�hgjH  hhjb  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�LhMIhKubh�ubh/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �Block<const ParameterType>�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�GetParameters�����}�(hKhh)��}�(hhhM�LhMKhK-ubh�ubhjN  h]�hgj[  hhjb  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�LhMKhKubh�ubh/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �const Block<const Parameter>&�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�IsPure�����}�(hKhh)��}�(hhhM'MhMMhKubh�ubhjN  h]�hgjn  hhjb  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhMMhMMhKubh�ubh/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �Bool�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�
GetAddress�����}�(hKhh)��}�(hhhMLMhMOhKubh�ubhjN  h]�hgj�  hhjb  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM9MhMOhKubh�ubh/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �void*�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�PrivateFindMethod�����}�(hKhh)��}�(hhhM�MhMQhK&ubh�ubhjN  h]�hgj�  hhjb  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhMiMhMQhK	ubh�ubh/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �const Function*�j1  �j2  ]�(j�  )��}�(h�const InterfaceReference&�hh�vi�����}�(hKhh)��}�(hhhM�MhMQhKRubh�ubj�  Nj�  �j�  �j�  �ubj�  )��}�(h�Int�hh�offset�����}�(hKhh)��}�(hhhM�MhMQhKZubh�ubj�  Nj�  �j�  �j�  �ubej4  Nj5  Nj6  �ubj  )��}�(hh�Find�����}�(hKhh)��}�(hhhM�MhMShKubh�ubhjN  h]�hgj�  hhjb  hjj�  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �const Function*�j1  �j2  ]�j�  )��}�(h�	const Id&�hh�memberId�����}�(hKhh)��}�(hhhM�MhMShK(ubh�ubj�  Nj�  �j�  �j�  �ubaj4  Nj5  Nj6  �ubj  )��}�(hh�FindAll�����}�(hKhh)��}�(hhhMYPhM_hK#ubh�ubhjN  h]�hgj�  hhjb  hjh�MAXON_METHOD�����}�(hKhh)��}�(hhhM?PhM_hK	ubh�ubh/NhlNhNhmNhnNhoK hp]�(h�L/// Finds all functions overloads which have the given (unqualified) @p id.
�����}�(hKhh)��}�(hhhM�NhMZhKubh�ubh�*/// @param[in] memberId						A member id.
�����}�(hKhh)��}�(hhhM4OhM[hKubh�ubh�>/// @param[out] result						Receiver for the found functions.
�����}�(hKhh)��}�(hhhM_OhM\hKubh�ubh�=/// @return												OK unless a memory allocation failed.
�����}�(hKhh)��}�(hhhM�OhM]hKubh�ubehx��/// Finds all functions overloads which have the given (unqualified) @p id.
/// @param[in] memberId						A member id.
/// @param[out] result						Receiver for the found functions.
/// @return												OK unless a memory allocation failed.
�hz}�h|�j,  �j-  �j.  �j/  �Result<void>�j1  �j2  ]�(j�  )��}�(h�	const Id&�hh�memberId�����}�(hKhh)��}�(hhhMkPhM_hK5ubh�ubj�  Nj�  �j�  �j�  �ubj�  )��}�(h�%const ValueReceiver<const Function*>&�hh�result�����}�(hKhh)��}�(hhhM�PhM_hKeubh�ubj�  Nj�  �j�  �j�  �ubej4  Nj5  �void�j6  �ubehgjR  hhhihjjP  h/NhlNhNhmh�)"net.maxon.reflection.interface.function"�����}�(hKhh)��}�(hhhMmBhM$hKEubh�ubhnNhoK hp]�(h�_/// Function represents a C++ function. It describes the name, return type and parameter types
�����}�(hKhh)��}�(hhhM�>hMhKubh�ubh�L/// of the function, but also has the Invoke method to invoke the function.
�����}�(hKhh)��}�(hhhM)?hMhKubh�ubh�///
�����}�(hKhh)��}�(hhhMu?hMhKubh�ubh�(/// There are three kinds of functions:
�����}�(hKhh)��}�(hhhMy?hMhKubh�ubh�\/// - KIND::FUNCTION is used for functions at package scope, or for static member functions
�����}�(hKhh)��}�(hhhM�?hMhKubh�ubh�x/// - KIND::INSTANCE_FUNCTION is used for non-static non-const member functions (which need a <tt>c</tt> this instance)
�����}�(hKhh)��}�(hhhM�?hMhKubh�ubh�~/// - KIND::CONST_INSTANCE_FUNCTION is used for non-static const member functions (which need a <tt>const this</tt> instance)
�����}�(hKhh)��}�(hhhMu@hMhKubh�ubh�///
�����}�(hKhh)��}�(hhhM�@hMhKubh�ubh�`/// The implicit @c this argument is not part of the parameter types, but for the Invoke method
�����}�(hKhh)��}�(hhhM�@hMhKubh�ubh�V/// it has to be specified as first argument if the function is an instance function.
�����}�(hKhh)��}�(hhhMWAhM hKubh�ubehxX�  /// Function represents a C++ function. It describes the name, return type and parameter types
/// of the function, but also has the Invoke method to invoke the function.
///
/// There are three kinds of functions:
/// - KIND::FUNCTION is used for functions at package scope, or for static member functions
/// - KIND::INSTANCE_FUNCTION is used for non-static non-const member functions (which need a <tt>c</tt> this instance)
/// - KIND::CONST_INSTANCE_FUNCTION is used for non-static const member functions (which need a <tt>const this</tt> instance)
///
/// The implicit @c this argument is not part of the parameter types, but for the Invoke method
/// it has to be specified as first argument if the function is an instance function.
�hz}�h|�h�]��Member�h�public�����}�(hKhh)��}�(hhhMBhM"hKubh�ubh	��aj�  Kj�  Nj,  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j6  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  ]�j�  }�ubhG)��}�(h�InvokeHelper<T(ARGS...)>�hh=h]�(h �	TypeAlias���)��}�(hh�type�����}�(hKhh)��}�(hhhM�PhMehKubh�ubhj]  h]�hgjg  hhhihj�	typealias�h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�h�]��T�hih	��aubj  )��}�(hh�Invoke�����}�(hKhh)��}�(hhhMQhMghKubh�ubhj]  h]�hgjv  hhhihjj�  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �	Result<T>�j1  �j2  ]�(j�  )��}�(h�const Function*�hh�fn�����}�(hKhh)��}�(hhhM.QhMghK*ubh�ubj�  Nj�  �j�  �j�  �ubj�  )��}�(h�ARGS�hh�args�����}�(hKhh)��}�(hhhM:QhMghK6ubh�ubj�  Nj�  �j�  �j�  �ubej4  Nj5  �T�j6  �ubehgh�InvokeHelper�����}�(hKhh)��}�(hhhM�PhMchK0ubh�ubhhhihjjP  h/j�  )��}�j2  ]�(j�  )��}�(hh)��}�(hhhM�PhMchKubj�  �hh�T�����}�(hKhh)��}�(hhhM�PhMchKubh�ubj�  Nj�  Nubj�  )��}�(hh)��}�(hhhM�PhMchKubj�  �hh�ARGS�����}�(hKhh)��}�(hhhM�PhMchK#ubh�ubj�  Nj�  NubesbhlNhNhmNhnNhoK hp]�hxh	hz}�h|�h�]�j�  Nj�  Nj,  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j6  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  ]�j�  }�ubhG)��}�(h�InvokeHelper<void(ARGS...)>�hh=h]�(jb  )��}�(hh�type�����}�(hKhh)��}�(hhhMRhMshKubh�ubhj�  h]�hgj�  hhhihjjl  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�h�]��void�hih	��aubj  )��}�(hh�Invoke�����}�(hKhh)��}�(hhhMARhMuhKubh�ubhj�  h]�hgj�  hhhihjj�  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �Result<void>�j1  �j2  ]�(j�  )��}�(h�const Function*�hh�fn�����}�(hKhh)��}�(hhhMXRhMuhK-ubh�ubj�  Nj�  �j�  �j�  �ubj�  )��}�(h�ARGS�hh�args�����}�(hKhh)��}�(hhhMdRhMuhK9ubh�ubj�  Nj�  �j�  �j�  �ubej4  Nj5  �void�j6  �ubehgh�InvokeHelper�����}�(hKhh)��}�(hhhM�QhMqhK$ubh�ubhhhihjjP  h/j�  )��}�j2  ]�j�  )��}�(hh)��}�(hhhM�QhMqhKubj�  �hh�ARGS�����}�(hKhh)��}�(hhhM�QhMqhKubh�ubj�  Nj�  NubasbhlNhNhmNhnNhoK hp]�hxh	hz}�h|�h�]�j�  Nj�  Nj,  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j6  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  ]�j�  }�ubhG)��}�(h�InvokeHelper<T()>�hh=h]�(jb  )��}�(hh�type�����}�(hKhh)��}�(hhhM�RhM~hKubh�ubhj	  h]�hgj	  hhhihjjl  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�h�]��T�hih	��aubj  )��}�(hh�Invoke�����}�(hKhh)��}�(hhhMShM�hKubh�ubhj	  h]�hgj	  hhhihjj�  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �	Result<T>�j1  �j2  ]�j�  )��}�(h�const Function*�hh�fn�����}�(hKhh)��}�(hhhM2ShM�hK*ubh�ubj�  Nj�  �j�  �j�  �ubaj4  Nj5  j�  j6  �ubehgh�InvokeHelper�����}�(hKhh)��}�(hhhM�RhM|hKubh�ubhhhihjjP  h/j�  )��}�j2  ]�j�  )��}�(hh)��}�(hhhM�RhM|hKubj�  �hh�T�����}�(hKhh)��}�(hhhM�RhM|hKubh�ubj�  Nj�  NubasbhlNhNhmNhnNhoK hp]�hxh	hz}�h|�h�]�j�  Nj�  Nj,  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j6  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  ]�j�  }�ubhG)��}�(h�InvokeHelper<void()>�hh=h]�(jb  )��}�(hh�type�����}�(hKhh)��}�(hhhM�ShM�hKubh�ubhjG	  h]�hgjO	  hhhihjjl  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�h�]��void�hih	��aubj  )��}�(hh�Invoke�����}�(hKhh)��}�(hhhM�ShM�hKubh�ubhjG	  h]�hgj]	  hhhihjj�  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �Result<void>�j1  �j2  ]�j�  )��}�(h�const Function*�hh�fn�����}�(hKhh)��}�(hhhMThM�hK-ubh�ubj�  Nj�  �j�  �j�  �ubaj4  Nj5  �void�j6  �ubehgh�InvokeHelper�����}�(hKhh)��}�(hhhM�ShM�hKubh�ubhhhihjjP  h/j�  )��}�j2  ]�h �NontypeTemplateParam���)��}�(hh)��}�(hhhM�ShM�hKubj�  �hNj�  Nhh	j�  NubasbhlNhNhmNhnNhoK hp]�hxh	hz}�h|�h�]�j�  Nj�  Nj,  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j6  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  ]�j�  }�ubjb  )��}�(hh�InvocationWrapper�����}�(hKhh)��}�(hhhM\ThM�hKubh�ubhh=h]�hgj�	  hhhihjjl  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�h�]��Fvoid(*)(const void*native,void*result,const Block<Argument>&arguments)�hih	��aubhG)��}�(hh�ProxyInvocation�����}�(hKhh)��}�(hhhM�ThM�hKubh�ubhh=h]�(j  )��}�(h�constructor�hj�	  h]�hgj�	  hhh�public�����}�(hKhh)��}�(hhhM�ThM�hKubh�ubhjj�	  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �void�j1  �j2  ]�(j�  )��}�(h�void*�hh�result�����}�(hKhh)��}�(hhhM�ThM�hKubh�ubj�  Nj�  �j�  �j�  �ubj�  )��}�(h�const Block<Argument>&�hh�args�����}�(hKhh)��}�(hhhMUhM�hK7ubh�ubj�  Nj�  �j�  �j�  �ubj�  )��}�(h�InvocationWrapper�hh�wrapper�����}�(hKhh)��}�(hhhM.UhM�hKOubh�ubj�  Nj�  �j�  �j�  �ubj�  )��}�(h�const void*�hh�super�����}�(hKhh)��}�(hhhMCUhM�hKdubh�ubj�  Nj�  �j�  �j�  �ubej4  Nj5  Nj6  �ubj  )��}�(hh�	GetResult�����}�(hKhh)��}�(hhhM�UhM�hKubh�ubhj�	  h]�hgj�	  hhj�	  hjj�  h/j�  )��}�j2  ]�j�  )��}�(hh)��}�(hhhM�UhM�hKubj�  �hh�T�����}�(hKhh)��}�(hhhM�UhM�hKubh�ubj�  Nj�  NubasbhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �T&�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�GetArgument�����}�(hKhh)��}�(hhhM
VhM�hKubh�ubhj�	  h]�hgj�	  hhj�	  hjj�  h/j�  )��}�j2  ]�j�  )��}�(hh)��}�(hhhM�UhM�hKubj�  �hh�T�����}�(hKhh)��}�(hhhMVhM�hKubh�ubj�  Nj�  NubasbhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �decltype(Argument().Get<T>())�j1  �j2  ]�j�  )��}�(h�Int�hh�index�����}�(hKhh)��}�(hhhMVhM�hK-ubh�ubj�  Nj�  �j�  �j�  �ubaj4  Nj5  Nj6  �ubj  )��}�(hh�GetArgumentCount�����}�(hKhh)��}�(hhhMvVhM�hKubh�ubhj�	  h]�hgj
  hhj�	  hjj�  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �Int�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�GetArguments�����}�(hKhh)��}�(hhhM�VhM�hKubh�ubhj�	  h]�hgj
  hhj�	  hjj�  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �Block<Argument>�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�GetArgumentsIncludingSelf�����}�(hKhh)��}�(hhhMWhM�hKubh�ubhj�	  h]�hgj+
  hhj�	  hjj�  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �const Block<Argument>&�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�HasSuper�����}�(hKhh)��}�(hhhMRWhM�hKubh�ubhj�	  h]�hgj8
  hhj�	  hjj�  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �Bool�j1  �j2  ]�j4  Nj5  Nj6  �ubj  )��}�(hh�Super�����}�(hKhh)��}�(hhhM�WhM�hKubh�ubhj�	  h]�hgjE
  hhj�	  hjj�  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j,  �j-  �j.  �j/  �void�j1  �j2  ]�j4  Nj5  Nj6  �ubh �Variable���)��}�(hh�_result�����}�(hKhh)��}�(hhhM�WhM�hKubh�ubhj�	  h]�hgjT
  hhh�private�����}�(hKhh)��}�(hhhM�WhM�hKubh�ubhj�variable�h/NhlNh�void*�hmNhnNhoK hp]�hxh	hz}�h|�j,  �ubjO
  )��}�(hh�_args�����}�(hKhh)��}�(hhhM�WhM�hKubh�ubhj�	  h]�hgjg
  hhj[
  hjj_
  h/NhlNh�Block<Argument>�hmNhnNhoK hp]�hxh	hz}�h|�j,  �ubjO
  )��}�(hh�_wrapper�����}�(hKhh)��}�(hhhM	XhM�hKubh�ubhj�	  h]�hgjs
  hhj[
  hjj_
  h/NhlNh�InvocationWrapper�hmNhnNhoK hp]�hxh	hz}�h|�j,  �ubjO
  )��}�(hh�_super�����}�(hKhh)��}�(hhhM XhM�hKubh�ubhj�	  h]�hgj
  hhj[
  hjj_
  h/NhlNh�const void*�hmNhnNhoK hp]�hxh	hz}�h|�j,  �ubehgj�	  hhhihjjP  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�h�]�j�  Nj�  Nj,  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j6  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  ]�j�  }�ubjb  )��}�(hh�ProxyHandler�����}�(hKhh)��}�(hhhM3XhM�hKubh�ubhh=h]�hgj�
  hhhihjjl  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�h�]��Nmaxon::Delegate<void(const Function*,ObjectInterface*,const ProxyInvocation&)>�hih	��aubehghAhhhihj�	namespace�h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|��preprocessorConditions�]��root�hh N�containsResourceId���registry��j�  ���minIndentation�K �maxIndentation�K �firstMember��ubahgh8hhhihjj�
  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j�
  ]�j�
  hh Nj�
  �j�
  �j�  ��j�
  K j�
  K j�
  �ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�XhM�hKubh�ububehghhhhihjj�
  h/NhlNhNhmNhnNhoK hp]�hxh	hz}�h|�j�
  ]�j�
  hh ]�(hh)h0h4h=hG)��}�(hh�	Container�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh=h]�hgj�
  hhhihjjP  h/NhlNhNhmNhnNhoK hp]�hxNhz}�h|�h�]�j�  Nj�  Nj,  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j6  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  ]�j�  }�ubhG)��}�(hh�Class�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh=h]�hgj�
  hhhihjjP  h/NhlNhNhmNhnNhoK hp]�hxNhz}�h|�h�]�j�  Nj�  Nj,  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j6  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  ]�j�  }�ubhG)��}�(hh�Function�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh=h]�hgj�
  hhhihjjP  h/NhlNhNhmNhnNhoK hp]�hxNhz}�h|�h�]�j�  Nj�  Nj,  �j�  Nj�  Nj�  �j�  �j�  �j�  �j�  �j6  �j�  �j�  �j�  Nj�  �j�  �j�  ]�j�  ]�j�  ]�j�  ]�j�  }�ubhHj�  j  j�  j0  jN  j]  j�  j	  jG	  j�	  j�	  j�
  j�
  ej�
  �j�
  �j�  ���hxx1�h=�hxx2�h=�snippets�}�j�
  K j�
  K j�
  ��forwardHeaders���ub.