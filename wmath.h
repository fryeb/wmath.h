/*
	The latest version of this library is available on GitHub;
	https://github.com/fryeb/wmath.h.

	This is free and unencumbered software released into the public domain.
	Anyone is free to copy, modify, publish, use, compile, sell, or
	distribute this software, either in source code form or as a compiled
	binary, for any purpose, commercial or non-commercial, and by any
	means.
	In jurisdictions that recognize copyright laws, the author or authors
	of this software dedicate any and all copyright interest in the
	software to the public domain. We make this dedication for the benefit
	of the public at large and to the detriment of our heirs and
	successors. We intend this dedication to be an overt act of
	relinquishment in perpetuity of all present and future rights to this
	software under copyright law.
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
	IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
	OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
	ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
	OTHER DEALINGS IN THE SOFTWARE.
	For more information, please refer to <http://unlicense.org/>.
*/

#ifndef FRYEB_WMATH_H_INCLUDED
#define FRYEB_WMATH_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#define WINLINE static inline

// AVX2 Implementation
#if defined(__AVX2__) && !defined(WMATH_FORCE_SCALAR)
#include <immintrin.h>

// Types
typedef __m256i wint8_t;
typedef __m256i wint16_t;
typedef __m256i wint32_t;
typedef __m256i wint64_t;
typedef __m256i wuint8_t;
typedef __m256i wuint16_t;
typedef __m256i wuint32_t;
typedef __m256i wuint64_t;
typedef __m256 wfloat_t;
typedef __m256d wdouble_t;

// Lane width (number of simd elements)
enum { WINT8_WIDTH = sizeof(wint8_t) / sizeof(int8_t),
       WINT16_WIDTH = sizeof(wint16_t) / sizeof(int16_t),
       WINT32_WIDTH = sizeof(wint32_t) / sizeof(int32_t),
       WINT64_WIDTH = sizeof(wint64_t) / sizeof(int64_t),
       WUINT8_WIDTH = sizeof(wuint8_t) / sizeof(uint8_t),
       WUINT16_WIDTH = sizeof(wuint16_t) / sizeof(uint16_t),
       WUINT32_WIDTH = sizeof(wuint32_t) / sizeof(uint32_t),
       WUINT64_WIDTH = sizeof(wuint64_t) / sizeof(uint64_t),
       WFLOAT_WIDTH = sizeof(wfloat_t) / sizeof(float),
       WDOUBLE_WIDTH = sizeof(wdouble_t) / sizeof(double) };

// Set
WINLINE wint8_t wseti8(int8_t a) { return _mm256_set1_epi8(a); }
WINLINE wint16_t wseti16(int16_t a) { return _mm256_set1_epi16(a); }
WINLINE wint32_t wseti32(int32_t a) { return _mm256_set1_epi32(a); }
WINLINE wint64_t wseti64(int64_t a) { return _mm256_set1_epi64x(a); }
WINLINE wuint8_t wsetu8(uint8_t a) { return _mm256_set1_epi8(a); }
WINLINE wuint16_t wsetu16(uint16_t a) { return _mm256_set1_epi16(a); }
WINLINE wuint32_t wsetu32(uint32_t a) { return _mm256_set1_epi32(a); }
WINLINE wuint64_t wsetu64(uint64_t a) { return _mm256_set1_epi64x(a); }
WINLINE wfloat_t wsetf(float a) { return _mm256_set1_ps(a); }
WINLINE wdouble_t wsetd(double a) { return _mm256_set1_pd(a); }

// Load unaligned
WINLINE wint8_t wloadi8u(wint8_t const *a) { return _mm256_loadu_si256(a); }
WINLINE wint16_t wloadi16u(wint16_t const *a) { return _mm256_loadu_si256(a); }
WINLINE wint32_t wloadi32u(wint32_t const *a) { return _mm256_loadu_si256(a); }
WINLINE wint64_t wloadi64u(wint64_t const *a) { return _mm256_loadu_si256(a); }
WINLINE wuint8_t wloadu8u(wuint8_t const *a) { return _mm256_loadu_si256(a); }
WINLINE wuint16_t wloadu16u(wuint16_t const *a) { return _mm256_loadu_si256(a); }
WINLINE wuint32_t wloadu32u(wuint32_t const *a) { return _mm256_loadu_si256(a); }
WINLINE wuint64_t wloadu64u(wuint64_t const *a) { return _mm256_loadu_si256(a); }
WINLINE wfloat_t wloadfu(wfloat_t const *a) { return _mm256_loadu_ps((float *)a); }
WINLINE wdouble_t wloaddu(wdouble_t const *a) { return _mm256_loadu_pd((double *)a); }

// Add
WINLINE wint8_t waddi8(wint8_t a, wint8_t b) { return _mm256_add_epi8(a, b); }
WINLINE wint16_t waddi16(wint16_t a, wint16_t b) { return _mm256_add_epi16(a, b); }
WINLINE wint32_t waddi32(wint32_t a, wint32_t b) { return _mm256_add_epi32(a, b); }
WINLINE wint64_t waddi64(wint64_t a, wint64_t b) { return _mm256_add_epi64(a, b); }
WINLINE wuint8_t waddu8(wuint8_t a, wuint8_t b) { return _mm256_add_epi8(a, b); }
WINLINE wuint16_t waddu16(wuint16_t a, wuint16_t b) { return _mm256_add_epi16(a, b); }
WINLINE wuint32_t waddu32(wuint32_t a, wuint32_t b) { return _mm256_add_epi32(a, b); }
WINLINE wuint64_t waddu64(wuint64_t a, wuint64_t b) { return _mm256_add_epi64(a, b); }
WINLINE wfloat_t waddf(wfloat_t a, wfloat_t b) { return _mm256_add_ps(a, b); }
WINLINE wdouble_t waddd(wdouble_t a, wdouble_t b) { return _mm256_add_pd(a, b); }

// Store unaligned
WINLINE void wstorei8u(int8_t *p, wint8_t a) { _mm256_storeu_si256((__m256i *)p, a); }
WINLINE void wstorei16u(int16_t *p, wint16_t a) { _mm256_storeu_si256((__m256i *)p, a); }
WINLINE void wstorei32u(int32_t *p, wint32_t a) { _mm256_storeu_si256((__m256i *)p, a); }
WINLINE void wstorei64u(int64_t *p, wint64_t a) { _mm256_storeu_si256((__m256i *)p, a); }
WINLINE void wstoreu8u(int8_t *p, wuint8_t a) { _mm256_storeu_si256((__m256i *)p, a); }
WINLINE void wstoreu16u(int16_t *p, wuint16_t a) { _mm256_storeu_si256((__m256i *)p, a); }
WINLINE void wstoreu32u(int32_t *p, wuint32_t a) { _mm256_storeu_si256((__m256i *)p, a); }
WINLINE void wstoreu64u(int64_t *p, wuint64_t a) { _mm256_storeu_si256((__m256i *)p, a); }

// Subtract
WINLINE wint8_t wsubi8(wint8_t a, wint8_t b) { return _mm256_sub_epi8(a, b); }
WINLINE wint16_t wsubi16(wint16_t a, wint16_t b) { return _mm256_sub_epi16(a, b); }
WINLINE wint32_t wsubi32(wint32_t a, wint32_t b) { return _mm256_sub_epi32(a, b); }
WINLINE wint64_t wsubi64(wint64_t a, wint64_t b) { return _mm256_sub_epi64(a, b); }
WINLINE wuint8_t wsubu8(wint8_t a, wuint8_t b) { return _mm256_sub_epi8(a, b); }
WINLINE wuint16_t wsubu16(wuint16_t a, wuint16_t b) { return _mm256_sub_epi16(a, b); }
WINLINE wuint32_t wsubu32(wuint32_t a, wuint32_t b) { return _mm256_sub_epi32(a, b); }
WINLINE wuint64_t wsubu64(wuint64_t a, wuint64_t b) { return _mm256_sub_epi64(a, b); }
WINLINE wfloat_t wsubf(wfloat_t a, wfloat_t b) { return _mm256_sub_ps(a, b); }
WINLINE wdouble_t wsubd(wdouble_t a, wdouble_t b) { return _mm256_sub_pd(a, b); }

// Multiply
// TODO: WINLINE wint8_t wmuli8(wint8_t a, wint8_t b)
WINLINE wint16_t wmuli16(wint16_t a, wint16_t b) { return _mm256_mullo_epi16(a, b); }
WINLINE wint32_t wmuli32(wint32_t a, wint32_t b) { return _mm256_mullo_epi32(a, b); }
// TODO: WINLINE wint64_t wmuli64(wint64_t a, wint64_t b) { return _mm256_mul_epi64(a, b); }
// TODO: WINLINE wuint8_t wmulu8(wuint8_t a, wuint8_t b)
// TODO: WINLINE wuint16_t wmulu16(wuint16_t a, wuint16_t b) { return _mm256_mullo_epu16(a, b); }
// TODO: WINLINE wuint32_t wmulu32(wuint32_t a, wuint32_t b) { return _mm256_mul_epu32(a, b); }
// TODO: WINLINE wuint64_t wmuli64(wuint64_t a, wuint64_t b) { return _mm256_mul_epu64(a, b); }
WINLINE wfloat_t wmulf(wfloat_t a, wfloat_t b) { return _mm256_mul_ps(a, b); }
WINLINE wdouble_t wmuld(wdouble_t a, wdouble_t b) { return _mm256_mul_pd(a, b); }

// Divide
WINLINE wfloat_t wdivf(wfloat_t a, wfloat_t b) { return _mm256_div_ps(a, b); }
WINLINE wdouble_t wdivd(wdouble_t a, wdouble_t b) { return _mm256_div_pd(a, b); }

#define WUMATH_DEFINE(n)                                                                           \
	/* TODO: Replace this with something faster */                                             \
	WINLINE uint##n##_t whaddu##n(wuint##n##_t a)                                              \
	{                                                                                          \
		uint##n##_t data[WUINT##n##_WIDTH];                                                \
		_mm256_storeu_si256((__m256i *)&data[0], a);                                       \
		uint##n##_t result = 0;                                                            \
		for (size_t i = 0; i < WUINT##n##_WIDTH; i++) {                                    \
			result += data[i];                                                         \
		}                                                                                  \
		return result;                                                                     \
	}

#define WIMATH_DEFINE(n)                                                                           \
	/* TODO: Replace this with something faster */                                             \
	WINLINE int##n##_t whaddi##n(wint##n##_t a)                                                \
	{                                                                                          \
		int##n##_t data[WUINT##n##_WIDTH];                                                 \
		_mm256_storeu_si256((__m256i *)&data[0], a);                                       \
		int##n##_t result = 0;                                                             \
		for (size_t i = 0; i < WUINT##n##_WIDTH; i++) {                                    \
			result += data[i];                                                         \
		}                                                                                  \
		return result;                                                                     \
	}

WUMATH_DEFINE(8)
WIMATH_DEFINE(8)
WUMATH_DEFINE(16)
WIMATH_DEFINE(16)
WUMATH_DEFINE(32)
WIMATH_DEFINE(32)
WUMATH_DEFINE(64)
WIMATH_DEFINE(64)
#undef WUMATH_DEFINE
#undef WIMATH_DEFINE

// TODO: Replace whaddf with something faster
WINLINE float whaddf(wfloat_t a)
{
	const float *p = (float *)&a;
	float total = 0;
	for (size_t i = 0; i < WFLOAT_WIDTH; i++)
		total += p[i];
	return total;
}

// TODO: Replace whaddd with something faster
WINLINE double whaddd(wdouble_t a)
{
	const double *p = (double *)&a;
	double total = 0;
	for (size_t i = 0; i < WDOUBLE_WIDTH; i++)
		total += p[i];
	return total;
}

#else // Scalar implementation

#define WMATH_DEFINE(t, s, T)                                                                      \
	enum { W##T##_WIDTH = 1 };                                                                 \
	typedef t##_t w##t##_t;                                                                    \
	WINLINE w##t##_t wset##s(t##_t a) { return a; }                                            \
	WINLINE w##t##_t wload##s##u(t##_t const *addr) { return *addr; }                          \
	WINLINE void wstore##s(t##_t *p, w##t##_t a) { *p = a; }                                   \
	WINLINE w##t##_t wadd##s(w##t##_t a, w##t##_t b) { return a + b; }                         \
	WINLINE t##_t whadd##s(w##t##_t a) { return a; };                                          \
	WINLINE w##t##_t wsub##s(w##t##_t a, w##t##_t b) { return a - b; }                         \
	WINLINE w##t##_t wmul##s(w##t##_t a, w##t##_t b) { return a * b; }                         \
	WINLINE w##t##_t wdiv##s(w##t##_t a, w##t##_t b) { return a / b; }

WMATH_DEFINE(int8, i8, INT8)
WMATH_DEFINE(int16, i16, INT16)
WMATH_DEFINE(int32, i32, INT32)
WMATH_DEFINE(int64, i64, INT64)
WMATH_DEFINE(uint8, u8, UINT8)
WMATH_DEFINE(uint16, u16, UINT16)
WMATH_DEFINE(uint32, u32, UINT32)
WMATH_DEFINE(uint64, u64, UINT64)
#define float_t float
#define double_t double
WMATH_DEFINE(float, f, FLOAT)
WMATH_DEFINE(double, d, DOUBLE)
#undef float_t
#undef double_t

#undef WMATH_DEFINE
#endif /* WMATH_FORCE_SCALAR */

#undef WINLINE
#ifdef __cplusplus
}
#endif
#endif /* FRYEB_WMATH_H_INCLUDED */
