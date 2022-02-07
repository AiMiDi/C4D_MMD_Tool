���$      �declarations��	Namespace���)��}�(�name��lexer��Token���� �����}�(�type�K�pos�h�SourcePosition���)��}�(�file��RD:\C4DSDK\C4D_MMDTool\sdk_s22\frameworks\core.framework\source\maxon\sse_general.h��index�K �line�KhKub�escaped��ub�owner�N�children�]�(h �	Directive���)��}�(hNhhh]��code�h�#if 1�����}�(hK
hh)��}�(hhhK hKhKubh�ububh �Include���)��}�(h�maxon/apibase.h�hhh]��quote��"��template�Nubh)��}�(hNhhh]�h h�#ifdef MAXON_TARGET_CPU_INTEL�����}�(hK
hh)��}�(hhhM�hKhKubh�ububh �Define���)��}�(hh�C4D_HAS_SSE2_CAPABILITY�����}�(hKhh)��}�(hhhM�hKhK
ubh�ubhhh]��
simpleName�h?�access��public��kind��#define�h/N�friend�NhN�id�N�point�N�
artificial�K �doclist�]��doc�h	�annotations�}��	anonymous���params�]�ubh:)��}�(hh�C4D_HAS_SSE2_INTRINSICS�����}�(hKhh)��}�(hhhM�hKhK
ubh�ubhhh]�hDhYhEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hKhKubh�ububh)��}�(hNhhh]�h h�#ifdef C4D_HAS_SSE2_CAPABILITY�����}�(hK
hh)��}�(hhhM�hKhKubh�ububh)��}�(hNhhh]�h h�#ifdef MAXON_TARGET_LINUX�����}�(hK
hh)��}�(hhhMhKhKubh�ububh)��}�(hNhhh]�h h�#ifndef __SSE__�����}�(hK
hh)��}�(hhhM6hKhKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hKhKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hKhKubh�ububh()��}�(h�xmmintrin.h�hhh]�h-�<�h/Nubh()��}�(h�emmintrin.h�hhh]�h-h�h/Nubh)��}�(hNhhh]�h h�#ifdef MAXON_TARGET_WINDOWS�����}�(hK
hh)��}�(hhhM/hKhKubh�ububh)��}�(hNhhh]�h h� #if defined MAXON_COMPILER_CLANG�����}�(hK
hh)��}�(hhhMMhKhKubh�ububh:)��}�(hh�C4D_HAS_SSE3_CAPABILITY�����}�(hKhh)��}�(hhhMyhKhKubh�ubhhh]�hDh�hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_SSE3_INTRINSICS�����}�(hKhh)��}�(hhhM�hKhKubh�ubhhh]�hDh�hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh()��}�(h�pmmintrin.h�hhh]�h-h�h/Nubh()��}�(h�tmmintrin.h�hhh]�h-h�h/Nubh:)��}�(hh�C4D_HAS_SSE4_CAPABILITY�����}�(hKhh)��}�(hhhMhK"hKubh�ubhhh]�hDh�hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_SSE4_INTRINSICS�����}�(hKhh)��}�(hhhM(hK#hKubh�ubhhh]�hDh�hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh()��}�(h�smmintrin.h�hhh]�h-h�h/Nubh()��}�(h�nmmintrin.h�hhh]�h-h�h/Nubh()��}�(h�ammintrin.h�hhh]�h-h�h/Nubh:)��}�(hh�C4D_HAS_AES_CAPABILITY�����}�(hKhh)��}�(hhhMhK,hKubh�ubhhh]�hDh�hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_AES_INTRINSICS�����}�(hKhh)��}�(hhhM?hK-hKubh�ubhhh]�hDj  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh()��}�(h�wmmintrin.h�hhh]�h-h�h/Nubh:)��}�(hh�C4D_HAS_PCLMULQDQ_CAPABILITY�����}�(hKhh)��}�(hhhM�hK0hKubh�ubhhh]�hDj  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_AVX2_CAPABILITY�����}�(hKhh)��}�(hhhM�hK1hKubh�ubhhh]�hDj"  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh)��}�(hNhhh]�h h�C#elif defined(MAXON_COMPILER_MSVC) || defined(MAXON_COMPILER_INTEL)�����}�(hK
hh)��}�(hhhM�hK2hKubh�ububh:)��}�(hh�C4D_HAS_SSE3_CAPABILITY�����}�(hKhh)��}�(hhhMhK3hKubh�ubhhh]�hDj7  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_SSE3_INTRINSICS�����}�(hKhh)��}�(hhhM8hK4hKubh�ubhhh]�hDjC  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_SSE4_CAPABILITY�����}�(hKhh)��}�(hhhM[hK5hKubh�ubhhh]�hDjO  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_SSE4_INTRINSICS�����}�(hKhh)��}�(hhhM~hK6hKubh�ubhhh]�hDj[  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_AVX_CAPABILITY�����}�(hKhh)��}�(hhhM�hK7hKubh�ubhhh]�hDjg  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_AVX_INTRINSICS�����}�(hKhh)��}�(hhhM�hK8hKubh�ubhhh]�hDjs  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh()��}�(h�intrin.h�hhh]�h-h�h/Nubh()��}�(h�immintrin.h�hhh]�h-h�h/Nubh:)��}�(hh�C4D_HAS_FMADD_CAPABILITY�����}�(hKhh)��}�(hhhMhK;hKubh�ubhhh]�hDj�  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_FMADD_INTRINSICS�����}�(hKhh)��}�(hhhM:hK<hKubh�ubhhh]�hDj�  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_AES_CAPABILITY�����}�(hKhh)��}�(hhhM^hK=hKubh�ubhhh]�hDj�  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_AES_INTRINSICS�����}�(hKhh)��}�(hhhM�hK>hKubh�ubhhh]�hDj�  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_PCLMULQDQ_CAPABILITY�����}�(hKhh)��}�(hhhM�hK?hKubh�ubhhh]�hDj�  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_PCLMULQDQ_INTRINSICS�����}�(hKhh)��}�(hhhM�hK@hKubh�ubhhh]�hDj�  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_AVX2_CAPABILITY�����}�(hKhh)��}�(hhhM�hKAhKubh�ubhhh]�hDj�  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_AVX2_INTRINSICS�����}�(hKhh)��}�(hhhMhKBhKubh�ubhhh]�hDj�  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM/hKChKubh�ububh)��}�(hNhhh]�h h� #elif defined MAXON_TARGET_LINUX�����}�(hK
hh)��}�(hhhM7hKDhKubh�ububh:)��}�(hh�C4D_HAS_SSE4_CAPABILITY�����}�(hKhh)��}�(hhhMbhKEhKubh�ubhhh]�hDj�  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_AES_CAPABILITY�����}�(hKhh)��}�(hhhM�hKFhKubh�ubhhh]�hDj  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh)��}�(hNhhh]�h h�#ifdef MAXON_COMPILER_INTEL�����}�(hK
hh)��}�(hhhM�hKGhKubh�ububh:)��}�(hh�C4D_HAS_SSE4_INTRINSICS�����}�(hKhh)��}�(hhhM�hKHhKubh�ubhhh]�hDj  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_AES_INTRINSICS�����}�(hKhh)��}�(hhhM�hKIhKubh�ubhhh]�hDj&  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM 	hKJhKubh�ububh)��}�(hNhhh]�h h�C#elif defined MAXON_TARGET_MACOS && defined(MAXON_TARGET_CPU_INTEL)�����}�(hK
hh)��}�(hhhM	hKKhKubh�ububh:)��}�(hh�C4D_HAS_SSE4_CAPABILITY�����}�(hKhh)��}�(hhhMV	hKLhKubh�ubhhh]�hDjD  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh:)��}�(hh�C4D_HAS_AES_CAPABILITY�����}�(hKhh)��}�(hhhM�	hKOhKubh�ubhhh]�hDjP  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh()��}�(h�immintrin.h�hhh]�h-h�h/Nubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�	hKQhKubh�ububh)��}�(hNhhh]�h h�#ifdef MAXON_COMPILER_INTEL�����}�(hK
hh)��}�(hhhM�	hKShKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhMN
hKUhKubh�ububh)��}�(hNhhh]�h h�#ifdef __SSE3__�����}�(hK
hh)��}�(hhhMW
hKWhKubh�ububh)��}�(hNhhh]�h h�#ifdef MAXON_TARGET_LINUX�����}�(hK
hh)��}�(hhhM�
hKYhKubh�ububh()��}�(h�pmmintrin.h�hhh]�h-h.h/Nubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�
hK[hKubh�ububh)��}�(hNhhh]�h h�@#if defined MAXON_TARGET_MACOS && !defined(MAXON_TARGET_CPU_PPC)�����}�(hK
hh)��}�(hhhM�
hK\hKubh�ububh()��}�(h�pmmintrin.h�hhh]�h-h�h/Nubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM>hK^hKubh�ububh:)��}�(hh�C4D_HAS_SSE3_INTRINSICS�����}�(hKhh)��}�(hhhMOhK_hKubh�ubhhh]�hDj�  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhMhhK`hKubh�ububh)��}�(hNhhh]�h h�#ifdef __SSSE3__�����}�(hK
hh)��}�(hhhMphKahKubh�ububh)��}�(hNhhh]�h h�#ifdef MAXON_TARGET_LINUX�����}�(hK
hh)��}�(hhhM�hKchKubh�ububh()��}�(h�tmmintrin.h�hhh]�h-h.h/Nubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hKehKubh�ububh)��}�(hNhhh]�h h�@#if defined MAXON_TARGET_MACOS && !defined(MAXON_TARGET_CPU_PPC)�����}�(hK
hh)��}�(hhhM�hKfhKubh�ububh()��}�(h�tmmintrin.h�hhh]�h-h�h/Nubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhMYhKhhKubh�ububh:)��}�(hh�C4D_HAS_SSSE3_INTRINSICS�����}�(hKhh)��}�(hhhMjhKihKubh�ubhhh]�hDj�  hEhFhGhHh/NhINhNhJNhKNhLK hM]�hOh	hP}�hR�hS]�ubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hKjhKubh�ububh()��}�(h�maxon/sse_intrinsics_42.h�hhh]�h-h.h/Nubh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hKnhKubh�ububh)��}�(hNhhh]�h h�#endif�����}�(hK
hh)��}�(hhhM�hKphKubh�ububehDhhEhFhG�	namespace�h/NhINhNhJNhKNhLK hM]�hOh	hP}�hR��preprocessorConditions�]��root�hh ]�(hh)h0h;hUhahjhsh|h�h�h�h�h�h�h�h�h�h�h�h�h�h�h�h�j  j  j  j  j*  j3  j?  jK  jW  jc  jo  j{  j  j�  j�  j�  j�  j�  j�  j�  j�  j�  j�  j�  j  j  j  j"  j.  j7  j@  jL  jX  j\  je  jn  jw  j�  j�  j�  j�  j�  j�  j�  j�  j�  j�  j�  j�  j�  j�  j�  j�  j  j  j  j  e�containsResourceId���registry���usings����hxx1�N�hxx2�N�snippets�}��minIndentation�K �maxIndentation�K �firstMember��ub.