��!U      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��LD:\C4DSDK\C4D_MMDTool\sdk_s26\frameworks\core.framework\source\maxon\units.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/object.h�hhh]��quote��"��template�Nubh)��}�(hh�maxon�����}�(hKhh)��}�(hhhKJhKhKubh�ubhhh]�(h �Enum���)��}�(hh�BASE_DIMENSION�����}�(hKhh)��}�(hhhK^hK	hKubh�ubhh0h]�(h �	EnumValue���)��}�(hh�LENGTH�����}�(hKhh)��}�(hhhKphKhKubh�ubhh;h]��
simpleName�hJ�access��public��kind��	enumvalue�h/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���value�NubhE)��}�(hh�TIME�����}�(hKhh)��}�(hhhKyhKhKubh�ubhh;h]�hOhchPhQhRhSh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�h^NubhE)��}�(hh�MASS�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh;h]�hOhnhPhQhRhSh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�h^NubhE)��}�(hh�TEMPERATURE�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh;h]�hOhyhPhQhRhSh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�h^NubhE)��}�(hh�AMOUNT_OF_SUBSTANCE�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh;h]�hOh�hPhQhRhSh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�h^NubhE)��}�(hh�ELECTRIC_CURRENT�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh;h]�hOh�hPhQhRhSh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�h^NubhE)��}�(hh�LUMINOUS_INTENSITY�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh;h]�hOh�hPhQhRhSh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�h^NubhE)��}�(hh�ANGLE�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh;h]�hOh�hPhQhRhSh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�h^NubhE)��}�(hh�SOLID_ANGLE�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh;h]�hOh�hPhQhRhSh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�h^NubhE)��}�(hh�PRIVATE_COUNT�����}�(hKhh)��}�(hhhK�hKhKubh�ubhh;h]�hOh�hPhQhRhSh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�h^NubehOh?hPhQhR�enum�h/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]��bases�]��scoped���
registered���flags��h ��enum class BASE_DIMENSION
{
	LENGTH,
	TIME,
	MASS,
	TEMPERATURE,
	AMOUNT_OF_SUBSTANCE,
	ELECTRIC_CURRENT,
	LUMINOUS_INTENSITY,
	ANGLE,
	SOLID_ANGLE,
	PRIVATE_COUNT
} �hK�early��ubh �	TypeAlias���)��}�(hh�
UnitsArray�����}�(hKhh)��}�(hhhM?hKhKubh�ubhh0h]�hOh�hPhQhR�	typealias�h/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�h�]��StrongCOWRef<BaseArray<Unit>>�hQh	��aubh �Class���)��}�(hh�DimensionInterface�����}�(hKhh)��}�(hhhMrhKhKubh�ubhh0h]�(h �Function���)��}�(hh�Get�����}�(hKhh)��}�(hhhMehK"hK'ubh�ubhh�h]�hOh�hPh�public�����}�(hKhh)��}�(hhhM7hK!hKubh�ubhRh�MAXON_METHOD�����}�(hKhh)��}�(hhhMGhK"hK	ubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]��static���explicit���deleted���retType��const Dimension&��const���params�]�h �	Parameter���)��}�(h�BASE_DIMENSION�hh�q�����}�(hKhh)��}�(hhhMxhK"hK:ubh�ub�default�N�pack���input���output��uba�
observable�N�result�N�forward��ubh�)��}�(hh�GetId�����}�(hKhh)��}�(hhhM�hK$hKubh�ubhh�h]�hOj  hPh�hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM~hK$hKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �	const Id&�j  �j  ]�j  Nj  Nj  �ubh�)��}�(hh�
operator *�����}�(hKhh)��}�(hhhM�hK&hK!ubh�ubhh�h]�hOj2  hPh�hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK&hKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Result<Dimension>�j  �j  ]�j
  )��}�(h�const Result<Dimension>&�hh�q�����}�(hKhh)��}�(hhhM�hK&hKEubh�ubj  Nj  �j  �j  �ubaj  Nj  �	Dimension�j  �ubh�)��}�(hh�
operator /�����}�(hKhh)��}�(hhhMhK(hK!ubh�ubhh�h]�hOjO  hPh�hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK(hKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Result<Dimension>�j  �j  ]�j
  )��}�(h�const Result<Dimension>&�hh�q�����}�(hKhh)��}�(hhhM8hK(hKEubh�ubj  Nj  �j  �j  �ubaj  Nj  �	Dimension�j  �ubh�)��}�(hh�
operator ^�����}�(hKhh)��}�(hhhMchK*hK!ubh�ubhh�h]�hOjl  hPh�hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhMDhK*hKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Result<Dimension>�j  �j  ]�j
  )��}�(h�Int�hh�exponent�����}�(hKhh)��}�(hhhMrhK*hK0ubh�ubj  Nj  �j  �j  �ubaj  Nj  �	Dimension�j  �ubh�)��}�(hh�Copy�����}�(hKhh)��}�(hhhM�hK,hK!ubh�ubhh�h]�hOj�  hPh�hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK,hKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Result<Dimension>�j  �j  ]�j
  )��}�(h�	const Id&�hh�qid�����}�(hKhh)��}�(hhhM�hK,hK0ubh�ubj  Nj  �j  �j  �ubaj  Nj  �	Dimension�j  �ubh�)��}�(hh�GetExponent�����}�(hKhh)��}�(hhhM�hK.hKubh�ubhh�h]�hOj�  hPh�hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK.hKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Int�j  �j  ]�j
  )��}�(h�BASE_DIMENSION�hh�q�����}�(hKhh)��}�(hhhM�hK.hK.ubh�ubj  Nj  �j  �j  �ubaj  Nj  Nj  �ubh�)��}�(hh�AddUnit�����}�(hKhh)��}�(hhhMhK0hKubh�ubhh�h]�hOj�  hPh�hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK0hKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Result<Unit>�j  �j  ]�(j
  )��}�(h�	const Id&�hh�unitId�����}�(hKhh)��}�(hhhM%hK0hK.ubh�ubj  Nj  �j  �j  �ubj
  )��}�(h�Float�hh�siConversionFactor�����}�(hKhh)��}�(hhhM3hK0hK<ubh�ubj  Nj  �j  �j  �ubej  Nj  �Unit�j  �ubh�)��}�(hh�GetUnits�����}�(hKhh)��}�(hhhMhhK2hKubh�ubhh�h]�hOj�  hPh�hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhMPhK2hKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �
UnitsArray�j  �j  ]�j  Nj  Nj  �ubh�)��}�(hh�IsEquivalent�����}�(hKhh)��}�(hhhM�hK4hKubh�ubhh�h]�hOj�  hPh�hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM|hK4hKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Bool�j  �j  ]�j
  )��}�(h�const Dimension&�hh�other�����}�(hKhh)��}�(hhhM�hK4hK2ubh�ubj  Nj  �j  �j  �ubaj  Nj  Nj  �ubh�)��}�(hh�ToString�����}�(hKhh)��}�(hhhM�hK6hKubh�ubhh�h]�hOj  hPh�hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK6hKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �String�j  �j  ]�j
  )��}�(h�const FormatStatement*�hh�fs�����}�(hKhh)��}�(hhhM�hK6hK6ubh�ubj  �nullptr�j  �j  �j  �ubaj  Nj  Nj  �ubehOh�hPhQhR�class�h/NhTNhNhUh�"net.maxon.interface.dimension"�����}�(hKhh)��}�(hhhM�hKhK=ubh�ubhVNhWK hX]�hZh	h[}�h]�h�]��ObjectInterface�hQh	��a�	interface�K�refKind�Kj  ��refClass��	Dimension��baseInterfaces�]�j:  h	��a�derived���isError���implementation���	component���finalComponent��j  ��
singleImpl���hasStaticMethods���generic�N�refClassForwardDeclared���missingInterfaces���usings�]��ambiguousCalls�]��	selfCalls�]��methodNames�}�ubh�)��}�(hj?  hh0h]�(h�)��}�(hh�hjU  hh�hOh�hPh�hRh�h/NhTNhNhUNhVNhWK hXh�hZh	h[j   h]�j  �j  �j  �j  j  j  �j  j  j  Nj  Nj  �ubh�)��}�(hj  hjU  hj#  hOj  hPh�hRj&  h/NhTNhNhUNhVNhWK hXj*  hZh	h[j+  h]�j  �j  �j  �j  j,  j  �j  j-  j  Nj  Nj  �ubh�)��}�(hj2  hjU  hj6  hOj2  hPh�hRj9  h/NhTNhNhUNhVNhWK hXj=  hZh	h[j>  h]�j  �j  �j  �j  j?  j  �j  j@  j  Nj  jJ  j  �ubh�)��}�(hjO  hjU  hjS  hOjO  hPh�hRjV  h/NhTNhNhUNhVNhWK hXjZ  hZh	h[j[  h]�j  �j  �j  �j  j\  j  �j  j]  j  Nj  jg  j  �ubh�)��}�(hjl  hjU  hjp  hOjl  hPh�hRjs  h/NhTNhNhUNhVNhWK hXjw  hZh	h[jx  h]�j  �j  �j  �j  jy  j  �j  jz  j  Nj  j�  j  �ubh�)��}�(hj�  hjU  hj�  hOj�  hPh�hRj�  h/NhTNhNhUNhVNhWK hXj�  hZh	h[j�  h]�j  �j  �j  �j  j�  j  �j  j�  j  Nj  j�  j  �ubh�)��}�(hj�  hjU  hj�  hOj�  hPh�hRj�  h/NhTNhNhUNhVNhWK hXj�  hZh	h[j�  h]�j  �j  �j  �j  j�  j  �j  j�  j  Nj  Nj  �ubh�)��}�(hj�  hjU  hj�  hOj�  hPh�hRj�  h/NhTNhNhUNhVNhWK hXj�  hZh	h[j�  h]�j  �j  �j  �j  j�  j  �j  j�  j  Nj  j�  j  �ubh�)��}�(hj�  hjU  hj�  hOj�  hPh�hRj�  h/NhTNhNhUNhVNhWK hXj�  hZh	h[j�  h]�j  �j  �j  �j  j�  j  �j  j�  j  Nj  Nj  �ubh�)��}�(hj�  hjU  hj�  hOj�  hPh�hRj  h/NhTNhNhUNhVNhWK hXj  hZh	h[j  h]�j  �j  �j  �j  j  j  �j  j	  j  Nj  Nj  �ubh�)��}�(hj  hjU  hj  hOj  hPh�hRj  h/NhTNhNhUNhVNhWK hXj"  hZh	h[j#  h]�j  �j  �j  �j  j$  j  �j  j%  j  Nj  Nj  �ubehOj?  hPhQhRj0  h/NhTNhNhUNhVNhWKhXj7  hZh	h[}�h]�h�]��+ObjectInterface::ReferenceClassHelper::type�hQh	��aj<  Nj=  Nj  �j>  Nj@  NjC  �jD  �jE  �jF  �jG  �j  �jH  �jI  �jJ  NjK  �jL  �jM  ]��source�h�ubh�)��}�(hh�UnitInterface�����}�(hKhh)��}�(hhhMhK9hKubh�ubhh0h]�(h�)��}�(hh�GetId�����}�(hKhh)��}�(hhhM�hK?hKubh�ubhjt  h]�hOj�  hPh�public�����}�(hKhh)��}�(hhhM�hK>hKubh�ubhRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hK?hKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �	const Id&�j  �j  ]�j  Nj  Nj  �ubh�)��}�(hh�GetDimension�����}�(hKhh)��}�(hhhM%hKAhK ubh�ubhjt  h]�hOj�  hPj�  hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhMhKAhKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �const Dimension&�j  �j  ]�j  Nj  Nj  �ubh�)��}�(hh�GetSIConversionFactor�����}�(hKhh)��}�(hhhMPhKChKubh�ubhjt  h]�hOj�  hPj�  hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM=hKChKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Float�j  �j  ]�j  Nj  Nj  �ubh�)��}�(hh�
operator *�����}�(hKhh)��}�(hhhM�hKEhKubh�ubhjt  h]�hOj�  hPj�  hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhMqhKEhKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Result<Unit>�j  �j  ]�j
  )��}�(h�const Result<Unit>&�hh�u�����}�(hKhh)��}�(hhhM�hKEhK;ubh�ubj  Nj  �j  �j  �ubaj  Nj  �Unit�j  �ubh�)��}�(hh�
operator /�����}�(hKhh)��}�(hhhM�hKGhKubh�ubhjt  h]�hOj�  hPj�  hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKGhKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Result<Unit>�j  �j  ]�j
  )��}�(h�const Result<Unit>&�hh�u�����}�(hKhh)��}�(hhhM�hKGhK;ubh�ubj  Nj  �j  �j  �ubaj  Nj  �Unit�j  �ubh�)��}�(hh�
operator ^�����}�(hKhh)��}�(hhhMhKIhKubh�ubhjt  h]�hOj�  hPj�  hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKIhKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Result<Unit>�j  �j  ]�j
  )��}�(h�Int�hh�exponent�����}�(hKhh)��}�(hhhM$hKIhK+ubh�ubj  Nj  �j  �j  �ubaj  Nj  �Unit�j  �ubh�)��}�(hh�Copy�����}�(hKhh)��}�(hhhMQhKKhKubh�ubhjt  h]�hOj  hPj�  hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM7hKKhKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Result<Unit>�j  �j  ]�j
  )��}�(h�	const Id&�hh�uid�����}�(hKhh)��}�(hhhM`hKKhK+ubh�ubj  Nj  �j  �j  �ubaj  Nj  �Unit�j  �ubh�)��}�(hh�Copy�����}�(hKhh)��}�(hhhM�hKMhKubh�ubhjt  h]�hOj4  hPj�  hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhMnhKMhKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Result<Unit>�j  �j  ]�j
  )��}�(h�const Dimension&�hh�quantity�����}�(hKhh)��}�(hhhM�hKMhK2ubh�ubj  Nj  �j  �j  �ubaj  Nj  �Unit�j  �ubh�)��}�(hh�AddToDimension�����}�(hKhh)��}�(hhhM�hKOhKubh�ubhjt  h]�hOjQ  hPj�  hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKOhKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Result<void>�j  �j  ]�j  Nj  �void�j  �ubh�)��}�(hh�Reduce�����}�(hKhh)��}�(hhhM�hKQhKubh�ubhjt  h]�hOje  hPj�  hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhM�hKQhKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �Result<Unit>�j  �j  ]�j  Nj  �Unit�j  �ubh�)��}�(hh�ToString�����}�(hKhh)��}�(hhhM%hKShKubh�ubhjt  h]�hOjy  hPj�  hRh�MAXON_METHOD�����}�(hKhh)��}�(hhhMhKShKubh�ubh/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j  �j  �j  �j  �String�j  �j  ]�j
  )��}�(h�const FormatStatement*�hh�fs�����}�(hKhh)��}�(hhhMEhKShK6ubh�ubj  �nullptr�j  �j  �j  �ubaj  Nj  Nj  �ubehOjx  hPhQhRj0  h/NhTNhNhUh�"net.maxon.interface.unit"�����}�(hKhh)��}�(hhhM�hK;hKCubh�ubhVNhWK hX]�hZh	h[}�h]�h�]�j<  Kj=  Kj  �j>  �Unit�j@  NjC  �jD  �jE  �jF  �jG  �j  �jH  �jI  �jJ  NjK  �jL  �jM  ]�jO  ]�jQ  ]�jS  }�ubh�)��}�(hj�  hh0h]�(h�)��}�(hj�  hj�  hj�  hOj�  hPj�  hRj�  h/NhTNhNhUNhVNhWK hXj�  hZh	h[j�  h]�j  �j  �j  �j  j�  j  �j  j�  j  Nj  Nj  �ubh�)��}�(hj�  hj�  hj�  hOj�  hPj�  hRj�  h/NhTNhNhUNhVNhWK hXj�  hZh	h[j�  h]�j  �j  �j  �j  j�  j  �j  j�  j  Nj  Nj  �ubh�)��}�(hj�  hj�  hj�  hOj�  hPj�  hRj�  h/NhTNhNhUNhVNhWK hXj�  hZh	h[j�  h]�j  �j  �j  �j  j�  j  �j  j�  j  Nj  Nj  �ubh�)��}�(hj�  hj�  hj�  hOj�  hPj�  hRj�  h/NhTNhNhUNhVNhWK hXj�  hZh	h[j�  h]�j  �j  �j  �j  j�  j  �j  j�  j  Nj  j�  j  �ubh�)��}�(hj�  hj�  hj�  hOj�  hPj�  hRj�  h/NhTNhNhUNhVNhWK hXj�  hZh	h[j�  h]�j  �j  �j  �j  j�  j  �j  j�  j  Nj  j�  j  �ubh�)��}�(hj�  hj�  hj�  hOj�  hPj�  hRj  h/NhTNhNhUNhVNhWK hXj  hZh	h[j  h]�j  �j  �j  �j  j  j  �j  j  j  Nj  j  j  �ubh�)��}�(hj  hj�  hj  hOj  hPj�  hRj  h/NhTNhNhUNhVNhWK hXj"  hZh	h[j#  h]�j  �j  �j  �j  j$  j  �j  j%  j  Nj  j/  j  �ubh�)��}�(hj4  hj�  hj8  hOj4  hPj�  hRj;  h/NhTNhNhUNhVNhWK hXj?  hZh	h[j@  h]�j  �j  �j  �j  jA  j  �j  jB  j  Nj  jL  j  �ubh�)��}�(hjQ  hj�  hjU  hOjQ  hPj�  hRjX  h/NhTNhNhUNhVNhWK hXj\  hZh	h[j]  h]�j  �j  �j  �j  j^  j  �j  j_  j  Nj  j`  j  �ubh�)��}�(hje  hj�  hji  hOje  hPj�  hRjl  h/NhTNhNhUNhVNhWK hXjp  hZh	h[jq  h]�j  �j  �j  �j  jr  j  �j  js  j  Nj  jt  j  �ubh�)��}�(hjy  hj�  hj}  hOjy  hPj�  hRj�  h/NhTNhNhUNhVNhWK hXj�  hZh	h[j�  h]�j  �j  �j  �j  j�  j  �j  j�  j  Nj  Nj  �ubehOj�  hPhQhRj0  h/NhTNhNhUNhVNhWKhXj�  hZh	h[}�h]�h�]�j<  Nj=  Nj  �j>  Nj@  NjC  �jD  �jE  �jF  �jG  �j  �jH  �jI  �jJ  NjK  �jL  �jM  ]�js  jt  ubh)��}�(hh�
Dimensions�����}�(hKhh)��}�(hhhM�hKXhKubh�ubhh0h]�(h �CppDeclaration���)��}�(hh�Length�����}�(hKhh)��}�(hhhM�hK\hKubh�ubhj�  h]�hOj�  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�hK\hKubh�ubh/NhTNh�	Dimension�hU�"net.maxon.dimension.length"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�Time�����}�(hKhh)��}�(hhhM8	hK]hKubh�ubhj�  h]�hOj�  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM	hK]hKubh�ubh/NhTNh�	Dimension�hU�"net.maxon.dimension.time"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�Mass�����}�(hKhh)��}�(hhhMy	hK^hKubh�ubhj�  h]�hOj�  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM\	hK^hKubh�ubh/NhTNh�	Dimension�hU�"net.maxon.dimension.mass"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�Temperature�����}�(hKhh)��}�(hhhM�	hK_hKubh�ubhj�  h]�hOj  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�	hK_hKubh�ubh/NhTNh�	Dimension�hU�!"net.maxon.dimension.temperature"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�AmountOfSubstance�����}�(hKhh)��}�(hhhM	
hK`hKubh�ubhj�  h]�hOj  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�	hK`hKubh�ubh/NhTNh�	Dimension�hU�'"net.maxon.dimension.amountofsubstance"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�ElectricCurrent�����}�(hKhh)��}�(hhhMd
hKahKubh�ubhj�  h]�hOj*  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhMG
hKahKubh�ubh/NhTNh�	Dimension�hU�%"net.maxon.dimension.electriccurrent"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�LuminousIntensity�����}�(hKhh)��}�(hhhM�
hKbhKubh�ubhj�  h]�hOj=  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�
hKbhKubh�ubh/NhTNh�	Dimension�hU�'"net.maxon.dimension.luminousintensity"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�Angle�����}�(hKhh)��}�(hhhMhKchKubh�ubhj�  h]�hOjP  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�
hKchKubh�ubh/NhTNh�	Dimension�hU�"net.maxon.dimension.angle"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�
SolidAngle�����}�(hKhh)��}�(hhhMYhKdhKubh�ubhj�  h]�hOjc  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM<hKdhKubh�ubh/NhTNh�	Dimension�hU� "net.maxon.dimension.solidangle"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�Velocity�����}�(hKhh)��}�(hhhM�hKfhKubh�ubhj�  h]�hOjv  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�hKfhKubh�ubh/NhTNh�	Dimension�hU�"net.maxon.dimension.velocity"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�Density�����}�(hKhh)��}�(hhhM�hKghKubh�ubhj�  h]�hOj�  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�hKghKubh�ubh/NhTNh�	Dimension�hU�"net.maxon.dimension.density"�hVNhWK hX]�hZh	h[}�h]�ubehOj�  hPhQhR�	namespace�h/NhTNh�	Dimension�hUh�"net.maxon.registry.dimensions"�����}�(hKhh)��}�(hhhM�hKXhK'ubh�ubhVNhWK hX]�hZh	h[}�h]��preprocessorConditions�]��root�hh N�containsResourceId���registry��jM  ���minIndentation�K�maxIndentation�K�firstMember��ubh)��}�(hh�Units�����}�(hKhh)��}�(hhhM1hKjhKubh�ubhh0h]�(j�  )��}�(hh�m�����}�(hKhh)��}�(hhhM�hKnhKubh�ubhj�  h]�hOj�  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhMihKnhKubh�ubh/NhTNh�Unit�hU�"net.maxon.unit.m"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�cm�����}�(hKhh)��}�(hhhM�hKohKubh�ubhj�  h]�hOj�  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�hKohKubh�ubh/NhTNh�Unit�hU�"net.maxon.unit.cm"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�ft�����}�(hKhh)��}�(hhhM�hKphKubh�ubhj�  h]�hOj�  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�hKphKubh�ubh/NhTNh�Unit�hU�"net.maxon.unit.ft"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�kg�����}�(hKhh)��}�(hhhMhKqhKubh�ubhj�  h]�hOj�  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM hKqhKubh�ubh/NhTNh�Unit�hU�"net.maxon.unit.kg"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�s�����}�(hKhh)��}�(hhhMKhKrhKubh�ubhj�  h]�hOj  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM3hKrhKubh�ubh/NhTNh�Unit�hU�"net.maxon.unit.s"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�K�����}�(hKhh)��}�(hhhM|hKshKubh�ubhj�  h]�hOj  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhMdhKshKubh�ubh/NhTNh�Unit�hU�"net.maxon.unit.k"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�mol�����}�(hKhh)��}�(hhhM�hKthKubh�ubhj�  h]�hOj*  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�hKthKubh�ubh/NhTNh�Unit�hU�"net.maxon.unit.mol"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�A�����}�(hKhh)��}�(hhhM�hKuhKubh�ubhj�  h]�hOj=  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�hKuhKubh�ubh/NhTNh�Unit�hU�"net.maxon.unit.a"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�cd�����}�(hKhh)��}�(hhhMhKvhKubh�ubhj�  h]�hOjP  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM�hKvhKubh�ubh/NhTNh�Unit�hU�"net.maxon.unit.cd"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�rad�����}�(hKhh)��}�(hhhMFhKwhKubh�ubhj�  h]�hOjc  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhM.hKwhKubh�ubh/NhTNh�Unit�hU�"net.maxon.unit.rad"�hVNhWK hX]�hZh	h[}�h]�ubj�  )��}�(hh�sr�����}�(hKhh)��}�(hhhM{hKxhKubh�ubhj�  h]�hOjv  hPhQhRh�MAXON_DECLARATION�����}�(hKhh)��}�(hhhMchKxhKubh�ubh/NhTNh�Unit�hU�"net.maxon.unit.sr"�hVNhWK hX]�hZh	h[}�h]�ubehOj�  hPhQhRj�  h/NhTNh�Unit�hUh�"net.maxon.registry.units"�����}�(hKhh)��}�(hhhM8hKjhKubh�ubhVNhWK hX]�hZh	h[}�h]�j�  ]�j�  hh Nj�  �j�  �jM  ��j�  Kj�  Kj�  �ubehOh4hPhQhRj�  h/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j�  ]�j�  hh Nj�  �j�  �jM  ��j�  K j�  K j�  �ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hKhKubh�ububehOhhPhQhRj�  h/NhTNhNhUNhVNhWK hX]�hZh	h[}�h]�j�  ]�j�  hh ]�(hh)h0h;h�)��}�(hh�Unit�����}�(hKhh)��}�(hhhM!hKhKubh�ubhh0h]�hOj�  hPhQhRj0  h/NhTNhNhUNhVNhWK hX]�hZNh[}�h]�h�]�j<  Nj=  Nj  �j>  Nj@  NjC  �jD  �jE  �jF  �jG  �j  �jH  �jI  �jJ  NjK  �jL  �jM  ]�jO  ]�jQ  ]�jS  }�ubh�)��}�(hh�	Dimension�����}�(hKhh)��}�(hhhM-hKhKubh�ubhh0h]�hOj�  hPhQhRj0  h/NhTNhNhUNhVNhWK hX]�hZNh[}�h]�h�]�j<  Nj=  Nj  �j>  Nj@  NjC  �jD  �jE  �jF  �jG  �j  �jH  �jI  �jJ  NjK  �jL  �jM  ]�jO  ]�jQ  ]�jS  }�ubh�h�jU  jt  j�  j�  j�  j�  j�  j   j  j&  j9  jL  j_  jr  j�  j�  j�  j�  j�  j�  j   j  j&  j9  jL  j_  jr  j�  ej�  �j�  �jM  ���hxx1�h0�hxx2�h0�snippets�}�j�  K j�  K j�  ��forwardHeaders���ub.